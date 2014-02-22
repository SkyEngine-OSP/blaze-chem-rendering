// 
// System.Web.Services.Description.Operation.cs
//
// Author:
//   Tim Coleman (tim@timcoleman.com)
//
// Copyright (C) Tim Coleman, 2002
//

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
using System.Xml;
using System.Xml.Serialization;

namespace System.Web.Services.Description 
{
	public sealed class Operation :
#if NET_2_0
		NamedItem
#else
		DocumentableItem 
#endif
	{
		#region Fields

		OperationFaultCollection faults;
		OperationMessageCollection messages;
#if !NET_2_0
		string name;
#endif
		string[] parameterOrder;
		PortType portType;

		#endregion // Fields

		#region Constructors
		
		public Operation ()
		{
			faults = new OperationFaultCollection (this);
			messages = new OperationMessageCollection (this);
#if !NET_2_0
			name = String.Empty;
#endif
			parameterOrder = null;
			portType = null;
		}
		
		#endregion // Constructors

		#region Properties

		[XmlElement ("fault")]
		public OperationFaultCollection Faults {
			get { return faults; }
		}

		[XmlElement ("output", typeof (OperationOutput))]
		[XmlElement ("input", typeof (OperationInput))]
		public OperationMessageCollection Messages {
			get { return messages; }
		}

#if !NET_2_0
		[XmlAttribute ("name", DataType = "NCName")]
		public string Name {
			get { return name; }
			set { name = value; }
		}
#endif

		[XmlIgnore]
		public string[] ParameterOrder {
			get { return parameterOrder; }
			set { parameterOrder = value; }
		}

		[DefaultValue ("")]
		[XmlAttribute ("parameterOrder")]
		public string ParameterOrderString {
			get { 
				if (parameterOrder == null)
					return String.Empty;
				return String.Join (" ", parameterOrder); 
			}
			set { ParameterOrder = value.Split (' '); }
		}

//		[XmlIgnore]
		public PortType PortType {
			get { return portType; }
		}

		#endregion // Properties

		#region Methods

		public bool IsBoundBy (OperationBinding operationBinding)
		{
			return (operationBinding.Name == Name);
		}

		internal void SetParent (PortType portType)
		{
			this.portType = portType;
		}

		#endregion
	}
}
