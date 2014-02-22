/*
 * XmlDeclarationInfo.cs - Implementation of the
 *		"System.Xml.Private.XmlDeclarationInfo" class.
 *
 * Copyright (C) 2004  Free Software Foundation, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

namespace System.Xml.Private
{

using System;
using System.Xml;

internal sealed class XmlDeclarationInfo : NodeWithAttributesInfo
{
	// Internal state.
	private String value;
	private String xml;

	// Constructor.
	public XmlDeclarationInfo(String xml)
			: base()
			{
				this.value = null;
				this.xml = xml;
			}


	// Get the quote character.
	public override char QuoteChar
			{
				get
				{
					if(index == -1) { return '"'; }
					return attributes[index].QuoteChar;
				}
			}

	// Get the fully-qualified name.
	public override String Name
			{
				get
				{
					if(index == -1) { return xml; }
					return attributes[index].Name;
				}
			}

	// Get the text value.
	public override String Value
			{
				get
				{
					if(index == -1) { return value; }
					return attributes[index].Value;
				}
			}

	// Get the type of the current node.
	public override XmlNodeType NodeType
			{
				get
				{
					if(index == -1) { return XmlNodeType.XmlDeclaration; }
					return attributes[index].NodeType;
				}
			}


	// Set the node information.
	public void SetInfo(Attributes attributes, String value)
			{
				base.Reset(attributes);
				this.value = value;
			}

}; // class XmlDeclarationInfo

}; // namespace System.Xml.Private
