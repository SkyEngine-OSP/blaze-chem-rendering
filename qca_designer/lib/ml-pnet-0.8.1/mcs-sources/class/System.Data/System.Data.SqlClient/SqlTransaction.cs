//
// System.Data.SqlClient.SqlTransaction.cs
//
// Author:
//   Tim Coleman (tim@timcoleman.com)
//
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

using System;
using System.Data;
using System.Data.Common;

namespace System.Data.SqlClient {
#if NET_2_0
        public sealed class SqlTransaction : DbTransaction, IDbTransaction, IDisposable
#else
	public sealed class SqlTransaction : MarshalByRefObject, IDbTransaction, IDisposable
#endif // NET_2_0
	{
		#region Fields

		bool disposed = false;
		SqlConnection connection;
		IsolationLevel isolationLevel;
		bool isOpen;
		bool isRolledBack = false;

		#endregion

		#region Constructors

		internal SqlTransaction (SqlConnection connection, IsolationLevel isolevel)
		{
			this.connection = connection;
			this.isolationLevel = isolevel;
			isOpen = true;
			isRolledBack = false;
		}

		#endregion // Constructors

		#region Properties

		public 
#if NET_2_0
		new
#endif // NET_2_0
	 SqlConnection Connection {
			get { return connection; }
		}

		internal bool IsOpen {
			get { return isOpen; }
		}

		public 
#if NET_2_0
		override
#endif // NET_2_0
	 IsolationLevel IsolationLevel {
			get { return isolationLevel; }
		}
		
		IDbConnection IDbTransaction.Connection	{
			get { return Connection; }
		}

		#endregion // Properties
               
		#region Methods

		public 
#if NET_2_0
		override
#endif // NET_2_0
	 void Commit ()
		{
			if (!isOpen)
				throw new InvalidOperationException ("The Transaction was not open.");
			connection.Tds.Execute ("COMMIT TRANSACTION");
			connection.Transaction = null;
			isOpen = false;
		}		

		private void Dispose (bool disposing)
		{
			if (!disposed)  {
				if (disposing) {
					if (isOpen) // in case it is called in the dispose of the class, then the isOpen is already false 
						Rollback ();
				}
				disposed = true;
			}
		}

		public 
#if NET_2_0
		override
#endif // NET_2_0
	 void Dispose ()
		{
			Dispose (true);
			GC.SuppressFinalize (this);
		}

		public 
#if NET_2_0
		override
#endif // NET_2_0
	 void Rollback ()
		{
			Rollback (String.Empty);
		}

		public void Rollback (string transactionName)
		{
			if (!isRolledBack) {
				if (!isOpen)
					throw new InvalidOperationException ("The Transaction was not open.");
				connection.Tds.Execute (String.Format ("ROLLBACK TRANSACTION {0}", transactionName));
				isRolledBack = true;
				isOpen = false;
			}
				
		}

		public void Save (string savePointName)
		{
			if (!isOpen)
				throw new InvalidOperationException ("The Transaction was not open.");
			connection.Tds.Execute (String.Format ("SAVE TRANSACTION {0}", savePointName));
		}
#if NET_2_0
                protected override DbConnection DbConnection
                {
                        get {return (DbConnection) Connection;}
                }
#endif // NET_2_0
		#endregion // Methods
	}
}