//
// System.Web.UI.DataBinder.cs
//
// Authors:
// 	Duncan Mak  (duncan@ximian.com)
// 	Gonzalo Paniagua Javier (gonzalo@ximian.com)
//
// (C) 2002 Ximian, Inc. (http://www.ximian.com)
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

using System;
using System.Collections;
using System.ComponentModel;
using System.Reflection;

namespace System.Web.UI {

	public sealed class DataBinder
	{
#if NET_2_0
		[Obsolete]
#endif
		public DataBinder ()
		{
		}

		private static string FormatResult (object result, string format)
		{
			if (result == null)
				return String.Empty;

			if (format == null)
				return result.ToString ();

			return String.Format (format, result);
		}
		
		public static object Eval (object container, string expression)
		{
			if (expression == null)
				throw new ArgumentNullException ("expression");

			object current = container;

			while (current != null) {
				int dot = expression.IndexOf ('.');
				int size = (dot == -1) ? expression.Length : dot;
				string prop = expression.Substring (0, size);
				if (prop.IndexOf ('[') != -1)
					current = GetIndexedPropertyValue (current, prop);
				else
					current = GetPropertyValue (current, prop);

				if (dot == -1)
					break;
				
				expression = expression.Substring (prop.Length + 1);
			}

			return current;
		}

		public static string Eval (object container, string expression, string format)
		{
			object result = Eval (container, expression);
			return FormatResult (result, format);
		}

		public static object GetIndexedPropertyValue (object container, string expr)
		{
			if (expr == null)
				throw new ArgumentNullException ("expr");

			int openIdx = expr.IndexOf ('[');
			int closeIdx = expr.IndexOf (']'); // see the test case. MS ignores all after the first ]
			if (openIdx < 0 || closeIdx < 0 || closeIdx - openIdx <= 1)
				throw new ArgumentException (expr + " is not a valid indexed expression.");

			string val = expr.Substring (openIdx + 1, closeIdx - openIdx - 1);
			val = val.Trim ();
			if (val.Length == 0)
				throw new ArgumentException (expr + " is not a valid indexed expression.");

			bool is_string = false;
			// a quoted val means we have a string
			if ((val[0] == '\'' && val[val.Length - 1] == '\'') ||
				(val[0] == '\"' && val[val.Length - 1] == '\"')) {
				is_string = true;
				val = val.Substring(1, val.Length - 2);
			} else {
				// if all chars are digits, then we have a int
				for(int i = 0; i < val.Length; i++)
					if (!Char.IsDigit(val[i])) {
						is_string = true;
						break;
					}
			}

			int intVal = 0;
			if (!is_string) {
				try {
					intVal = Int32.Parse (val);
				} catch {
					throw new ArgumentException (expr + " is not a valid indexed expression.");
				}
			}

			string property = null;
			if (openIdx > 0) {
				property = expr.Substring (0, openIdx);
				if (property != null && property != String.Empty)
					container = GetPropertyValue (container, property);
			}

                        if (container == null)
                                return null;

			if (container is System.Collections.IList) {
				IList l = (IList) container;
				return l [intVal];
			}

			Type t = container.GetType ();
			// MS does not seem to look for any other than "Item"!!!
			object [] atts = t.GetCustomAttributes (typeof (DefaultMemberAttribute), false);
			if (atts.Length != 1)
				throw new ArgumentException (expr + " indexer not found.");

			property = ((DefaultMemberAttribute) atts [0]).MemberName;

			Type [] argTypes = new Type [] { (is_string) ? typeof (string) : typeof (int) };
			PropertyInfo prop = t.GetProperty (property, argTypes);
			if (prop == null)
				throw new ArgumentException (expr + " indexer not found.");

			object [] args = new object [1];
			if (is_string)
				args [0] = val;
			else
				args [0] = intVal;

			return prop.GetValue (container, args);
		}

		public static string GetIndexedPropertyValue (object container, string expr, string format)
		{
			object result = GetIndexedPropertyValue (container, expr);
			return FormatResult (result, format);
		}

		public static object GetPropertyValue (object container, string propName)
		{
			if (propName == null)
				throw new ArgumentNullException ("propName");

			PropertyDescriptor prop = TypeDescriptor.GetProperties (container).Find (propName, true);
			if (prop == null) {
				throw new HttpException ("Property " + propName + " not found in " +
							 container.GetType ());
			}

			return prop.GetValue (container);
		}

		public static string GetPropertyValue (object container, string propName, string format)
		{
			object result = GetPropertyValue (container, propName);
			return FormatResult (result, format);
		}

		#if NET_2_0
		public static object GetDataItem (object container, out bool foundDataItem)
		{	
			foundDataItem = false;
			if (container == null)			
				return null;
			
			if (container is IDataItemContainer) {
				foundDataItem = true;
				return ((IDataItemContainer)container).DataItem;
			}
			
			PropertyInfo pi = container.GetType ().GetProperty ("DataItem", BindingFlags.Public | BindingFlags.Instance);
			if (pi == null)
				return null;
			
			foundDataItem = true;
			return pi.GetValue (container, null); 
		} 
		
		
		public static object GetDataItem (object container)
		{
			bool flag;
			return GetDataItem (container, out flag); 
		}
		#endif
	}
}

