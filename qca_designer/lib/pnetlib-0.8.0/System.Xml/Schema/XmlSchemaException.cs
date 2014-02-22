/*
 * XmlSchemaException.cs - Implementation of 
 *				"System.Xml.Schema.XmlSchemaException" class
 *
 * Copyright (C) 2003  Southern Storm Software, Pty Ltd.
 * 
 * contributed by Gopal.V
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

using System;
using System.Runtime.Serialization;

namespace System.Xml.Schema
{
	[Serializable]
	public class XmlSchemaException: SystemException
	{
		[TODO]
		public XmlSchemaException(String message, Exception innerException)
		{
			 HResult = unchecked((int)0x80131941);
			 throw new NotImplementedException(".ctor");
		}
#if CONFIG_SERIALIZATION
		[TODO]
		protected XmlSchemaException(SerializationInfo info,
									 StreamingContext context)
			: base(info, context)
		{
			// TODO
		}
#endif

		[TODO]
		public int LineNumber 
		{
 			get
			{
				throw new NotImplementedException("LineNumber");
			}
 		}

		[TODO]
		public int LinePosition 
		{
 			get
			{
				throw new NotImplementedException("LinePosition");
			}
 		}

		[TODO]
		public override String Message 
		{
 			get
			{
				throw new NotImplementedException("Message");
			}
 		}

		[TODO]
		public System.Xml.Schema.XmlSchemaObject SourceSchemaObject 
		{
 			get
			{
				throw new NotImplementedException("SourceSchemaObject");
			}
 		}

		[TODO]
		public String SourceUri 
		{
 			get
			{
				throw new NotImplementedException("SourceUri");
			}
 		}

#if CONFIG_SERIALIZATION
		[TODO]
		public override void GetObjectData(SerializationInfo info,
										   StreamingContext context)
		{
			base.GetObjectData(info, context);
			// TODO
		}
#endif

	}
}//namespace
