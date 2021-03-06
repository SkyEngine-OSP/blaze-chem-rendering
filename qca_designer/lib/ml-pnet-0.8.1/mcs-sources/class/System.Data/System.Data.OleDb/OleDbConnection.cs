//
// System.Data.OleDb.OleDbConnection
//
// Authors:
//   Rodrigo Moya (rodrigo@ximian.com)
//   Tim Coleman (tim@timcoleman.com)
//
// Copyright (C) Rodrigo Moya, 2002
// Copyright (C) Tim Coleman, 2002
//

//
// Copyright (C) 2004 Novell, Inc (http://www.novell.com)
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

using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.EnterpriseServices;

namespace System.Data.OleDb
{
	[DefaultEvent ("InfoMessage")]	
	public sealed class OleDbConnection : Component, ICloneable, IDbConnection
	{
		#region Fields

		string connectionString;
		int connectionTimeout;
		IntPtr gdaConnection;

		#endregion

		#region Constructors
		
		public OleDbConnection ()
		{
			libgda.gda_init ("System.Data.OleDb", "1.0", 0, new string [0]);
			gdaConnection = IntPtr.Zero;
			connectionTimeout = 15;
			connectionString = null;
		}

		public OleDbConnection (string connectionString) : this ()
		{
			this.connectionString = connectionString;
		}

		#endregion // Constructors

		#region Properties
		
		[DataCategory ("Data")]
		[DefaultValue ("")]
		[DataSysDescriptionAttribute ("Information used to connect to a Data Source")]
		[EditorAttribute ("Microsoft.VSDesigner.Data.ADO.Design.OleDbConnectionStringEditor, "+ Consts.AssemblyMicrosoft_VSDesigner, "System.Drawing.Design.UITypeEditor, "+ Consts.AssemblySystem_Drawing )]
		[RecommendedAsConfigurableAttribute (true)]
		[RefreshPropertiesAttribute (RefreshProperties.All)]
		public string ConnectionString {
			get {
				return connectionString;
			}
			set {
				connectionString = value;
			}
		}

		[DesignerSerializationVisibilityAttribute (DesignerSerializationVisibility.Hidden)]
		[DataSysDescriptionAttribute ("Current connection timeout value 'Connect TimeOut=X' in the ConnectionString")]
		public int ConnectionTimeout {
			get {
				return connectionTimeout;
			}
		}

		[DesignerSerializationVisibilityAttribute (DesignerSerializationVisibility.Hidden)]
                [DataSysDescriptionAttribute ("Current data source Catlog value, 'Initial Catalog=X' in the ConnectionString")]
		public string Database { 
			get {
				if (gdaConnection != IntPtr.Zero
				    && libgda.gda_connection_is_open (gdaConnection)) {
					return libgda.gda_connection_get_database (gdaConnection);
				}

				return null;
			}
		}

	        [DesignerSerializationVisibilityAttribute (DesignerSerializationVisibility.Hidden)]
                [DataSysDescriptionAttribute ("Current data source, 'Data Source=X' in the ConnectionString")]
	 	public string DataSource {
			get {
				if (gdaConnection != IntPtr.Zero
				    && libgda.gda_connection_is_open (gdaConnection)) {
					return libgda.gda_connection_get_dsn (gdaConnection);
				}

				return null;
			}
		}

		[DesignerSerializationVisibilityAttribute (DesignerSerializationVisibility.Hidden)]
                [DataSysDescriptionAttribute ("Current OLE DB provider progid, 'Provider=X' in the ConnectionString")]
		public string Provider {
			get {
				if (gdaConnection != IntPtr.Zero
				    && libgda.gda_connection_is_open (gdaConnection)) {
					return libgda.gda_connection_get_provider (gdaConnection);
				}

				return null;
			}
		}

		[DesignerSerializationVisibilityAttribute (DesignerSerializationVisibility.Hidden)]
                [DataSysDescriptionAttribute ("Version of the product accessed by the OLE DB Provider")]
		[BrowsableAttribute (false)]
		public string ServerVersion {
			get {
				if (gdaConnection != IntPtr.Zero
				    && libgda.gda_connection_is_open (gdaConnection)) {
					return libgda.gda_connection_get_server_version (gdaConnection);
				}

				return null;
			}
		}

		[DesignerSerializationVisibilityAttribute (DesignerSerializationVisibility.Hidden)]
                [DataSysDescriptionAttribute ("The ConnectionState indicating whether the connection is open or closed")]
                [BrowsableAttribute (false)]
		public ConnectionState State
		{
			get {
				if (gdaConnection != IntPtr.Zero) {
					if (libgda.gda_connection_is_open (gdaConnection))
						return ConnectionState.Open;
				}

				return ConnectionState.Closed;
			}
		}

		internal IntPtr GdaConnection
		{
			get {
				return gdaConnection;
			}
		}
		
		#endregion // Properties
	
		#region Methods
	
		public OleDbTransaction BeginTransaction ()
		{
			if (gdaConnection != IntPtr.Zero)
				return new OleDbTransaction (this);

			return null;
		}

		IDbTransaction IDbConnection.BeginTransaction ()
		{
			return BeginTransaction ();
		}
		
		public OleDbTransaction BeginTransaction (IsolationLevel level)
		{
			if (gdaConnection != IntPtr.Zero)
				return new OleDbTransaction (this, level);

			return null;
		}

		IDbTransaction IDbConnection.BeginTransaction (IsolationLevel level)
		{
			return BeginTransaction (level);
		}

		public void ChangeDatabase (string name)
		{
			if (gdaConnection == IntPtr.Zero)
				throw new ArgumentException ();
			if (State != ConnectionState.Open)
				throw new InvalidOperationException ();

			if (!libgda.gda_connection_change_database (gdaConnection, name))
				throw new OleDbException (this);
		}

		public void Close ()
		{
			if (State == ConnectionState.Open) {
				libgda.gda_connection_close (gdaConnection);
				gdaConnection = IntPtr.Zero;
			}
		}

		public OleDbCommand CreateCommand ()
		{
			if (State == ConnectionState.Open)
				return new OleDbCommand (null, this);

			return null;
		}

		[MonoTODO]
		protected override void Dispose (bool disposing)
		{
			throw new NotImplementedException ();
		}

		[MonoTODO]
		public DataTable GetOleDbSchemaTable (Guid schema, object[] restrictions)
		{
			throw new NotImplementedException ();
		}

		[MonoTODO]
		object ICloneable.Clone ()
		{
			throw new NotImplementedException();
		}

		IDbCommand IDbConnection.CreateCommand ()
		{
			return CreateCommand ();
		}

		public void Open ()
		{
			string provider = "Default";
			string gdaCncStr = "";
			string[] args;
			int len;
			char [] separator = { ';' };
			
			if (State == ConnectionState.Open)
				throw new InvalidOperationException ();

			gdaConnection = libgda.gda_client_open_connection (libgda.GdaClient,
                                                                          connectionString,
                                                                          "", "", 0);
			
			/* convert the connection string to its GDA equivalent */
			//args = connectionString.Split (';');
			//len = args.Length;
			//for (int i = 0; i < len; i++) {
			//	string[] values = args[i].Split (separator, 2);
			//	if (values[0] == "Provider") {
			//		if (values[1] == "SQLOLEDB")
			//			provider = "FreeTDS";
			//		else if (values[1] == "MSDAORA")
			//			provider = "Oracle";
			//		else if (values[2] == "Microsoft.Jet.OLEDB.4.0")
			//			provider = "MS Access";
			//		else
			//			provider = values[2];
			//	}
			//	else if (values[0] == "Addr" || values[0] == "Address")
			//		gdaCncStr = String.Concat (gdaCncStr, "HOST=", values[1], ";");
			//	else if (values[0] == "Database")
			//		gdaCncStr = String.Concat (gdaCncStr, "DATABASE=", values[1], ";");
			//	else if (values[0] == "Connection Lifetime")
			//		connectionTimeout = System.Convert.ToInt32 (values[1]);
			//	else if (values[0] == "File Name")
			//		gdaCncStr = String.Concat (gdaCncStr, "FILENAME=", values[1], ";");
			//	else if (values[0] == "Password" || values[0] == "Pwd")
			//		gdaCncStr = String.Concat (gdaCncStr, "PASSWORD=", values[1], ";");
			//	else if (values[0] == "User ID")
			//		gdaCncStr = String.Concat (gdaCncStr, "USERNAME=", values[1], ";");
			//}

			/* open the connection */
			//System.Console.WriteLine ("Opening connection for provider " +
			//		  provider + " with " + gdaCncStr);
			//gdaConnection = libgda.gda_client_open_connection_from_string (libgda.GdaClient,
			//							       provider,
			//							       gdaCncStr);
		}

		[MonoTODO]
		public static void ReleaseObjectPool ()
		{
			throw new NotImplementedException ();
		}

		[MonoTODO]
		public void EnlistDistributedTransaction (ITransaction transaction)
		{
			throw new NotImplementedException ();
		}

		#endregion

		#region Events and Delegates

                [DataSysDescription ("DbConnection_InfoMessage")]
                [DataCategory ("DataCategory_InfoMessage")]
		public event OleDbInfoMessageEventHandler InfoMessage;

		[DataSysDescription ("DbConnection_StateChange")]
                [DataCategory ("DataCategory_StateChange")]
		public event StateChangeEventHandler StateChange;

		#endregion
	}
}
