//
// XmlSchemaWriter.cs - DataSet.WriteXmlSchema() support
//
// Author:
//
//	Atsushi Enomoto  <atsushi@ximian.com>
//
// Original WriteXml/WriteXmlSchema authors are:
//	Ville Palo, Alan Tam, Lluis Sanchez and Eran Domb.
//

//
// Copyright (C) 2004-05 Novell, Inc (http://www.novell.com)
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

using System;
using System.Collections;
using System.Collections.Specialized;
using System.Globalization;
using System.Data;
using System.Xml;

namespace System.Data
{
	internal class XmlSchemaWriter
	{
		const string xmlnsxs = System.Xml.Schema.XmlSchema.Namespace;

		public static void WriteXmlSchema (DataSet dataset,
			XmlWriter writer)
		{
			WriteXmlSchema (dataset, writer, dataset.Tables,
				dataset.Relations);
		}

		public static void WriteXmlSchema (DataSet dataset,
			XmlWriter writer, DataTableCollection tables,
			DataRelationCollection relations)
		{
			new XmlSchemaWriter (dataset, writer,
				tables, relations).WriteSchema ();
		}

		public XmlSchemaWriter (DataSet dataset,
			XmlWriter writer, DataTableCollection tables,
			DataRelationCollection relations)
		{
			ds = dataset;
			w = writer;
			this.tables = tables;
			this.relations = relations;
		}

		DataSet ds;
		XmlWriter w;
		DataTableCollection tables;
		DataRelationCollection relations;

		ArrayList globalTypeTables = new ArrayList ();
		Hashtable additionalNamespaces = new Hashtable ();

		public string ConstraintPrefix {
			get { return ds.Namespace != String.Empty ? XmlConstants.TnsPrefix + ':' : String.Empty; }
		}

		// the whole DataSet

		public void WriteSchema ()
		{
			ListDictionary names = new ListDictionary ();
			ListDictionary includes = new ListDictionary ();

			// Add namespaces used in DataSet components (tables, columns, ...)
			foreach (DataTable dt in tables) {
				foreach (DataColumn col in dt.Columns)
					CheckNamespace (col.Prefix, col.Namespace, names, includes);
				CheckNamespace (dt.Prefix, dt.Namespace, names, includes);
			}

			w.WriteStartElement ("xs", "schema", xmlnsxs);
			w.WriteAttributeString ("id", ds.DataSetName);

			if (ds.Namespace != String.Empty) {
				w.WriteAttributeString ("targetNamespace",
					ds.Namespace);
				w.WriteAttributeString (
					"xmlns",
					XmlConstants.TnsPrefix,
					XmlConstants.XmlnsNS,
					ds.Namespace);
			}
			w.WriteAttributeString ("xmlns", ds.Namespace);

			w.WriteAttributeString ("xmlns", "xs",
				XmlConstants.XmlnsNS, xmlnsxs);
			w.WriteAttributeString ("xmlns",
				XmlConstants.MsdataPrefix,
				XmlConstants.XmlnsNS,
				XmlConstants.MsdataNamespace);

			if (CheckExtendedPropertyExists (tables, relations))
				w.WriteAttributeString ("xmlns",
					XmlConstants.MspropPrefix,
					XmlConstants.XmlnsNS,
					XmlConstants.MspropNamespace);

			if (ds.Namespace != String.Empty) {
				w.WriteAttributeString ("attributeFormDefault", "qualified");
				w.WriteAttributeString ("elementFormDefault", "qualified");
			}

			foreach (string prefix in names.Keys)
				w.WriteAttributeString ("xmlns", prefix,
					XmlConstants.XmlnsNS,
					names [prefix] as string);

			if (includes.Count > 0)
				w.WriteComment ("ATTENTION: This schema contains references to other imported schemas");
			foreach (string ns in includes.Keys) {
				w.WriteStartElement ("xs", "import", xmlnsxs);
				w.WriteAttributeString ("namespace", ns);
				w.WriteAttributeString ("schemaLocation", includes [ns] as string);
				w.WriteEndElement ();
			}

			WriteDataSetElement ();

			w.WriteEndElement (); // xs:schema

			w.Flush ();
		}

		// FIXME: actually there are some cases that this method(ology)
		// does not apply.
		private void WriteDataSetElement ()
		{
			w.WriteStartElement ("xs", "element", xmlnsxs);
			w.WriteAttributeString ("name", ds.DataSetName);
			w.WriteAttributeString (XmlConstants.MsdataPrefix,
				"IsDataSet", XmlConstants.MsdataNamespace,
				"true");
#if NET_2_0
			if (ds.Locale == CultureInfo.CurrentCulture) {
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					"UseCurrentCulture",
					XmlConstants.MsdataNamespace,
					"true");
			}
			else
#endif
			{
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					"Locale",
					XmlConstants.MsdataNamespace,
					ds.Locale.Name);
			}

			AddExtendedPropertyAttributes (ds.ExtendedProperties);

			w.WriteStartElement ("xs", "complexType", xmlnsxs);
			w.WriteStartElement ("xs", "choice", xmlnsxs);
			w.WriteAttributeString ("maxOccurs", "unbounded");

			foreach (DataTable table in tables) {
				bool isTopLevel = true;
				foreach (DataRelation rel in table.ParentRelations) {
					if (rel.Nested) {
						isTopLevel = false;
						break;
					}
				}
				
				if (isTopLevel) {
					if (ds.Namespace != table.Namespace) {
						// <xs:element ref="X:y" />
						w.WriteStartElement ("xs",
							"element",
							xmlnsxs);
						w.WriteStartAttribute ("ref", String.Empty);
						w.WriteQualifiedName (table.TableName, table.Namespace);
						w.WriteEndAttribute ();
						w.WriteEndElement ();
					}
					else
						WriteTableElement (table);
				}
			}

			w.WriteEndElement (); // choice
			w.WriteEndElement (); // complexType

			WriteConstraints (); // DataSet constraints

			w.WriteEndElement (); // element
		}

		// Relation based Constraints

		private void WriteConstraints ()
		{
			ArrayList names = new ArrayList ();

			// add all unique constraints.
			foreach (DataTable table in tables) {
				foreach (Constraint c in table.Constraints) {
					UniqueConstraint u =
						c as UniqueConstraint;
					if (u != null)
						AddUniqueConstraints (u, names);
				}
			}

			// Add all foriegn key constraints.
			if (relations != null)
				foreach (DataRelation rel in relations)
					if (rel.ParentKeyConstraint != null &&
						rel.ChildKeyConstraint != null)
						AddForeignKeys (rel, names);
		}

		// Add unique constaraints to the schema.
		// return hashtable with the names of all XmlSchemaUnique elements we created.
		private void AddUniqueConstraints (UniqueConstraint uniq,
			ArrayList names)
		{
			// if column of the constraint is hidden do not write the constraint.
			foreach (DataColumn column in uniq.Columns)
				if (column.ColumnMapping == MappingType.Hidden)
					return; // do nothing

			w.WriteStartElement ("xs", "unique", xmlnsxs);
			// if constaraint name do not exist in the hashtable we can use it.
			string name;
			if (!names.Contains (uniq.ConstraintName)) {
				name = uniq.ConstraintName;
				w.WriteAttributeString ("name", name);
			}
			// otherwise generate new constraint name for the
			// XmlSchemaUnique element.
			else {
				name = uniq.Table.TableName + "_" + uniq.ConstraintName;
				w.WriteAttributeString ("name", name);
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.ConstraintName,
					XmlConstants.MsdataNamespace,
					uniq.ConstraintName);
			}
			names.Add (name);

			if (uniq.IsPrimaryKey) {
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.PrimaryKey,
					XmlConstants.MsdataNamespace,
					"true");
			}

			AddExtendedPropertyAttributes (uniq.ExtendedProperties);

			w.WriteStartElement ("xs", "selector",
				xmlnsxs);
			w.WriteAttributeString ("xpath", ".//" +
				ConstraintPrefix + uniq.Table.TableName);
			w.WriteEndElement (); // selector
			foreach (DataColumn c in uniq.Columns) {
				w.WriteStartElement ("xs", "field",
					xmlnsxs);
				w.WriteStartAttribute ("xpath", String.Empty);
				if (c.ColumnMapping == MappingType.Attribute)
					w.WriteString ("@");
				w.WriteString (ConstraintPrefix);
				w.WriteString (c.ColumnName);
				w.WriteEndAttribute (); // xpath
				w.WriteEndElement (); // field
			}

			w.WriteEndElement (); // unique
		}

		// Add the foriegn keys to the schema.
		private void AddForeignKeys (DataRelation rel, ArrayList names)
		{
			// Do nothing if it contains hidden relation
			foreach (DataColumn col in rel.ParentColumns)
				if (col.ColumnMapping == MappingType.Hidden)
					return;
			foreach (DataColumn col in rel.ChildColumns)
				if (col.ColumnMapping == MappingType.Hidden)
					return;

			w.WriteStartElement ("xs", "keyref", xmlnsxs);
			w.WriteAttributeString ("name", rel.RelationName);

			ForeignKeyConstraint fkConst = rel.ChildKeyConstraint;
			UniqueConstraint uqConst = rel.ParentKeyConstraint;

			string concatName = rel.ParentTable.TableName + "_" + uqConst.ConstraintName;
			// first try to find the concatenated name. If we didn't find it - use constraint name.
			if (names.Contains (concatName)) {
				w.WriteStartAttribute ("refer", String.Empty);
				w.WriteQualifiedName (concatName, ds.Namespace);
				w.WriteEndAttribute ();
			}
			else {
				w.WriteStartAttribute ("refer", String.Empty);
				w.WriteQualifiedName (
					uqConst.ConstraintName, ds.Namespace);
				w.WriteEndAttribute ();
			}

			if (rel.Nested)
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.IsNested,
					XmlConstants.MsdataNamespace,
					"true");

			AddExtendedPropertyAttributes (uqConst.ExtendedProperties);

			w.WriteStartElement ("xs", "selector", xmlnsxs);
			w.WriteAttributeString ("xpath", ".//" + 
				ConstraintPrefix + rel.ChildTable.TableName);
			w.WriteEndElement ();

			foreach (DataColumn c in rel.ChildColumns) {
				w.WriteStartElement ("xs", "field",
					xmlnsxs);
				w.WriteStartAttribute ("xpath", String.Empty);
				if (c.ColumnMapping == MappingType.Attribute)
					w.WriteString ("@");
				w.WriteString (ConstraintPrefix);
				w.WriteString (c.ColumnName);
				w.WriteEndAttribute ();
				w.WriteEndElement (); // field
			}

			w.WriteEndElement (); // keyref
		}

		// ExtendedProperties

		private bool CheckExtendedPropertyExists (
			DataTableCollection tables,
			DataRelationCollection relations)
		{
			if (ds.ExtendedProperties.Count > 0)
				return true;
			foreach (DataTable dt in tables) {
				if (dt.ExtendedProperties.Count > 0)
					return true;
				foreach (DataColumn col in dt.Columns)
					if (col.ExtendedProperties.Count > 0)
						return true;
				foreach (Constraint c in dt.Constraints)
					if (c.ExtendedProperties.Count > 0)
						return true;
			}
			if (relations == null)
				return false;
			foreach (DataRelation rel in relations)
				if (rel.ExtendedProperties.Count > 0)
					return true;
			return false;
		}

		private void AddExtendedPropertyAttributes (PropertyCollection props)
		{
			// add extended properties to xs:element
			foreach (DictionaryEntry de in props) {
				w.WriteStartAttribute (
					XmlConstants.MspropPrefix,
					XmlConvert.EncodeName (de.Key.ToString ()),
					XmlConstants.MspropNamespace);
				if (de.Value != null)
					w.WriteString (
						DataSet.WriteObjectXml (de.Value));
				w.WriteEndAttribute ();
			}
		}

		// Table

		private void WriteTableElement (DataTable table)
		{
			w.WriteStartElement ("xs", "element", xmlnsxs);
			w.WriteAttributeString ("name", table.TableName);

			AddExtendedPropertyAttributes (table.ExtendedProperties);

			WriteTableType (table);

			w.WriteEndElement ();
		}

		private void WriteTableType (DataTable table)
		{
			ArrayList elements;
			ArrayList atts;
			DataColumn simple;

			DataSet.SplitColumns (table, out atts, out elements, out simple);

			w.WriteStartElement ("xs", "complexType", xmlnsxs);

			if (simple != null) {
				w.WriteStartElement ("xs", "simpleContent", xmlnsxs);
				// add column name attribute
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.ColumnName,
					XmlConstants.MsdataNamespace,
					simple.ColumnName);

				// add ordinal attribute
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.Ordinal,
					XmlConstants.MsdataNamespace,
					XmlConvert.ToString (simple.Ordinal));

				// add extension
				w.WriteStartElement ("xs", "extension",
					xmlnsxs);
				w.WriteStartAttribute ("base", String.Empty);
				WriteQName (MapType (simple.DataType));
				w.WriteEndAttribute ();

				WriteTableAttributes (atts);

				w.WriteEndElement ();
			} else {
				WriteTableAttributes (atts);

				if (elements.Count > 0) {
					w.WriteStartElement ("xs", "sequence",
						xmlnsxs);
					foreach (DataColumn col in elements)
						WriteTableTypeParticles (
							col);
					w.WriteEndElement ();
				}

				foreach (DataRelation rel in table.ChildRelations)
					if (rel.Nested)
						WriteChildRelations (rel);
			}

			w.WriteFullEndElement (); // complexType
		}

		private void WriteTableTypeParticles (DataColumn col)
		{
			w.WriteStartElement ("xs", "element",
				xmlnsxs);
			w.WriteAttributeString ("name",
				col.ColumnName);

			if (col.ColumnName != col.Caption && col.Caption != String.Empty)
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.Caption, 
					XmlConstants.MsdataNamespace,
					col.Caption);

			if (col.AutoIncrement == true)
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.AutoIncrement,
					XmlConstants.MsdataNamespace,
					"true");

			if (col.AutoIncrementSeed != 0) {
				w.WriteAttributeString (

					XmlConstants.MsdataPrefix,
					XmlConstants.AutoIncrementSeed,
					XmlConstants.MsdataNamespace,
					XmlConvert.ToString (col.AutoIncrementSeed));
			}

			if (col.AutoIncrementStep != 1) {
				w.WriteAttributeString (

					XmlConstants.MsdataPrefix,
					XmlConstants.AutoIncrementStep,
					XmlConstants.MsdataNamespace,
					XmlConvert.ToString (col.AutoIncrementStep));
			}

			if (col.DefaultValue.ToString () != String.Empty)
				w.WriteAttributeString ("default",
					DataSet.WriteObjectXml (col.DefaultValue));

			if (col.ReadOnly)
				w.WriteAttributeString (
					XmlConstants.MsdataPrefix,
					XmlConstants.ReadOnly,
					XmlConstants.MsdataNamespace,
					"true");

			XmlQualifiedName typeQName = null;
			if (col.MaxLength < 0) {
				w.WriteStartAttribute ("type", String.Empty);
				typeQName = MapType (col.DataType);
				WriteQName (typeQName);
				w.WriteEndAttribute ();
			}

			if (typeQName == XmlConstants.QnString
				&& col.DataType != typeof (string)
				&& col.DataType != typeof (char)) {
				w.WriteStartAttribute (
					XmlConstants.MsdataPrefix,
					XmlConstants.DataType,
					XmlConstants.MsdataNamespace);
				string runtimeName = col.DataType.AssemblyQualifiedName;
				w.WriteString (runtimeName);
				w.WriteEndAttribute ();
			}

			if (col.AllowDBNull)
				w.WriteAttributeString ("minOccurs", "0");

			//writer.WriteAttributeString (XmlConstants.MsdataPrefix, 
			//                            XmlConstants.Ordinal, 
			//                            XmlConstants.MsdataNamespace, 
			//                            col.Ordinal.ToString ());

			// Write SimpleType if column have MaxLength
			if (col.MaxLength > -1)
				WriteSimpleType (col);

			AddExtendedPropertyAttributes (col.ExtendedProperties);

			w.WriteEndElement (); // sequence
		}

		private void WriteChildRelations (DataRelation rel)
		{
			if (rel.ChildTable.Namespace != ds.Namespace) {
				w.WriteStartElement ("xs", "element", xmlnsxs);
				w.WriteStartAttribute ("ref", String.Empty);
				w.WriteQualifiedName (
					rel.ChildTable.TableName,
					rel.ChildTable.Namespace);
				w.WriteEndAttribute ();
			} else {
				w.WriteStartElement ("xs", "element", xmlnsxs);
				w.WriteStartAttribute ("type", String.Empty);
				w.WriteQualifiedName (
					rel.ChildTable.TableName,
					rel.ChildTable.Namespace);
				w.WriteEndAttribute ();
				w.WriteEndElement ();

				globalTypeTables.Add (rel.ChildTable);
				w.WriteAttributeString ("minOccurs", "0");
				w.WriteAttributeString ("maxOccurs", "unbounded");
			}
		}

		private void WriteTableAttributes (ArrayList atts)
		{
			//Then a list of attributes
			foreach (DataColumn col in atts) {
				w.WriteStartElement ("xs", "attribute", xmlnsxs);

				string name = col.ColumnName;
				if (col.Namespace != String.Empty) {
					w.WriteAttributeString ("form", "qualified");
					string prefix = col.Prefix == String.Empty ? "app" + additionalNamespaces.Count : col.Prefix;
					name = prefix + ":" + col.ColumnName;
					// FIXME: Handle prefix mapping correctly.
					additionalNamespaces [prefix] = col.Namespace;
				}
				w.WriteAttributeString ("name", name);

				AddExtendedPropertyAttributes (
					col.ExtendedProperties);

				if (col.ReadOnly)
					w.WriteAttributeString (
						XmlConstants.MsdataPrefix,
						XmlConstants.ReadOnly,
						XmlConstants.MsdataNamespace,
						"true");

				if (col.MaxLength < 0) {
					// otherwise simpleType is written later
					w.WriteStartAttribute ("type", String.Empty);
					WriteQName (MapType (col.DataType));
					w.WriteEndAttribute ();
				}

				if (!col.AllowDBNull)
					w.WriteAttributeString ("use", "required");
				if (col.DefaultValue.ToString () != String.Empty)
					w.WriteAttributeString ("default",
						DataSet.WriteObjectXml (col.DefaultValue));

				if (col.MaxLength > -1)
					WriteSimpleType (col);

				w.WriteEndElement (); // attribute
			}
		}

		private void WriteSimpleType (DataColumn col)
		{
			w.WriteStartElement ("xs", "simpleType", xmlnsxs);
			w.WriteStartElement ("xs", "restriction", xmlnsxs);
			w.WriteStartAttribute ("base", String.Empty);
			WriteQName (MapType (col.DataType));
			w.WriteEndAttribute ();

			w.WriteStartElement ("xs", "maxLength", xmlnsxs);
			w.WriteAttributeString ("value",
				XmlConvert.ToString (col.MaxLength));
			w.WriteEndElement (); // maxLength
			w.WriteEndElement (); // restriction
			w.WriteEndElement (); // simpleType
		}

		private void WriteQName (XmlQualifiedName name)
		{
			w.WriteQualifiedName (name.Name, name.Namespace);
		}

		private void CheckNamespace (string prefix, string ns, ListDictionary names, ListDictionary includes)
		{
			if (ns == String.Empty)
				return;
			if (ds.Namespace != ns) {
				if (names [prefix] != ns) {
					for (int i = 1; i < int.MaxValue; i++) {
						string p = "app" + i;
						if (names [p] == null) {
							names.Add (p, ns);
							HandleExternalNamespace (p, ns, includes);
							break;
						}
					}
				}
			}
		}

		private void HandleExternalNamespace (string prefix, string ns, ListDictionary includes)
		{
			if (includes.Contains (ns))
				return; // nothing to do
			includes.Add (ns, "_" + prefix + ".xsd");
		}

		private /*static*/ XmlQualifiedName MapType (Type type)
		{
			switch (Type.GetTypeCode (type)) {
				case TypeCode.String: return XmlConstants.QnString;
				case TypeCode.Int16: return XmlConstants.QnShort;
				case TypeCode.Int32: return XmlConstants.QnInt;
				case TypeCode.Int64: return XmlConstants.QnLong;
				case TypeCode.Boolean: return XmlConstants.QnBoolean;
				case TypeCode.Byte: return XmlConstants.QnUnsignedByte;
				//case TypeCode.Char: return XmlConstants.QnChar;
				case TypeCode.DateTime: return XmlConstants.QnDateTime;
				case TypeCode.Decimal: return XmlConstants.QnDecimal;
				case TypeCode.Double: return XmlConstants.QnDouble;
				case TypeCode.SByte: return XmlConstants.QnSbyte;
				case TypeCode.Single: return XmlConstants.QnFloat;
				case TypeCode.UInt16: return XmlConstants.QnUsignedShort;
				case TypeCode.UInt32: return XmlConstants.QnUnsignedInt;
				case TypeCode.UInt64: return XmlConstants.QnUnsignedLong;
			}
			
			if (typeof (TimeSpan) == type)
				return XmlConstants.QnDuration;
			else if (typeof (System.Uri) == type)
				return XmlConstants.QnUri;
			else if (typeof (byte[]) == type)
				return XmlConstants.QnBase64Binary;
			else if (typeof (XmlQualifiedName) == type)
				return XmlConstants.QnXmlQualifiedName;
			else
				return XmlConstants.QnString;
		}
	}
}
