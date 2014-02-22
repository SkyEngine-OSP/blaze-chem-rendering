//
// Expressions.cs
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
	internal interface IExpression {
		object Eval (DataRow row);
		bool DependsOn(DataColumn other);

		bool EvalBoolean (DataRow row);
	}

	internal abstract class BaseExpression : IExpression {
		public abstract object Eval (DataRow row);
		public abstract bool DependsOn(DataColumn other);

		public virtual bool EvalBoolean (DataRow row)
		{
			return (bool) Eval (row);
		}
	}

	// abstract base classes
	internal abstract class UnaryExpression : BaseExpression {
		protected IExpression expr;
	
		public UnaryExpression (IExpression e)
		{
			expr = e;
		}

		override public bool DependsOn(DataColumn other) {
			return expr.DependsOn(other);
		}
	}
	
	internal abstract class BinaryExpression : BaseExpression {
		protected IExpression expr1, expr2;
	
		protected BinaryExpression (IExpression e1, IExpression e2)
		{
			expr1 = e1;
			expr2 = e2;
		}
		override public bool DependsOn(DataColumn other)
		{
			return expr1.DependsOn(other) || expr2.DependsOn(other);
		}
	}
	
	internal enum Operation {
		AND, OR,
		EQ, NE, LT, LE, GT, GE,
		ADD, SUB, MUL, DIV, MOD
	}
	
	internal abstract class BinaryOpExpression : BinaryExpression {
		protected Operation op;
	
		protected BinaryOpExpression (Operation op, IExpression e1, IExpression e2) : base (e1, e2)
		{
			this.op = op;
		}
	}
}
