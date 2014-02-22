//
// StringFunctions.cs
//
// Author:
//   Juraj Skripsky (juraj@hotfeet.ch)
//
// (C) 2004 HotFeet GmbH (http://www.hotfeet.ch)
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
using System.Collections;
using System.Data;

namespace Mono.Data.SqlExpressions {
	internal abstract class StringFunction : UnaryExpression {
		protected StringFunction (IExpression e) : base (e) {}

		override public object Eval (DataRow row)
		{
			object val = expr.Eval (row);
			if(val == null)
				return null;
				
			if (!(val is string)) {
				string fnct = this.GetType ().ToString ();
				int start = fnct.LastIndexOf('.') + 1;
				fnct = fnct.Substring (start, fnct.Length - start - "Function".Length);
				throw new EvaluateException (String.Format ("'{0}' can be applied only to strings.", fnct));
			}
				
			return val;
		}
	}
	
	internal class SubstringFunction : StringFunction {
		int start, len;
		public SubstringFunction (IExpression e, int start, int len) : base (e)
		{
			this.start = start;
			this.len = len;
		}
		
		override public object Eval (DataRow row)
		{
			string str = (string)base.Eval (row);
			if(str == null)
				return null;
				
			if (start > str.Length)
				return String.Empty;
			
			return str.Substring (start - 1, System.Math.Min (len, str.Length - (start - 1)));
		}
	}
	
	internal class LenFunction : StringFunction {
		public LenFunction (IExpression e) : base (e) {}
		
		override public object Eval (DataRow row)
		{
			string str = (string)base.Eval (row);
			if(str == null)
				return 0;
				
			return str.Length;
		}
	}

	internal class TrimFunction : StringFunction {
		public TrimFunction (IExpression e) : base (e) {}
		
		override public object Eval (DataRow row)
		{
			string str = (string)base.Eval (row);
			if(str == null)
				return null;
				
			return str.Trim();
		}
	}
}
