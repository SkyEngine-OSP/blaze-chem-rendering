/* Nodes/JNode.cs.  Generated automatically by treecc */

namespace Microsoft.JScript
{

using System;

#line 1 "./Nodes/JNode.tc"

/*
 * JNode.tc - Input file for "treecc" that defines the JScript nodes.
 *
 * Copyright (C) 2003 Southern Storm Software, Pty Ltd.
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

using Microsoft.JScript.Vsa;
using System.Reflection;
using System.Collections;

#line 35 "Nodes/JNode.cs"
internal class JNodeState
{

	private static JNodeState state__;

	public static JNodeState getState()
	{
		if(state__ != null) return state__;
		state__ = new JNodeState();
		return state__;
	}

	public JNodeState() { state__ = this; }

}

internal abstract class JNode
{
	protected int kind__;

	public int getKind() { return kind__; }

	public const int KIND = 1;

	public Context context;

	protected JNode(Context context)
	{
		this.kind__ = KIND;
		this.context = context;
	}

	public abstract Object Eval(VsaEngine engine);

	public virtual void Prepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 282 "./Nodes/JNode.tc"
	{
		throw new JScriptException(JSError.IllegalAssignment, context);
	}
#line 75 "Nodes/JNode.cs"

	public virtual Object GetAndPrepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 282 "./Nodes/JNode.tc"
	{
		throw new JScriptException(JSError.IllegalAssignment, context);
	}
#line 82 "Nodes/JNode.cs"

	public virtual void Store(VsaEngine engine, Object data1, Object data2, Object value)
#line 282 "./Nodes/JNode.tc"
	{
		throw new JScriptException(JSError.IllegalAssignment, context);
	}
#line 89 "Nodes/JNode.cs"

	public virtual int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return 0;
	}

	public virtual String getKindName()
	{
		return "JNode";
	}
}

internal class JScriptBlock : JNode
{
	public new const int KIND = 2;

	public JNode functions;
	public JNode statements;

	public JScriptBlock(Context context, JNode functions, JNode statements)
		: base(context)
	{
		this.kind__ = KIND;
		this.functions = functions;
		this.statements = statements;
	}

	public override Object Eval(VsaEngine engine)
#line 288 "./Nodes/JNode.tc"
	{
		// Declare the functions into the global scope.  We do this by
		// evaluating them - JFunction.Eval does the rest.
		if(functions != null)
		{
			functions.Eval(engine);
		}
	
		// Execute the global statements within the block.
		if(statements != null)
		{
			return statements.Eval(engine);
		}
		else
		{
			return Empty.Value;
		}
	}
#line 140 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JScriptBlock";
	}
}

internal class JBlock : JNode
{
	public new const int KIND = 3;

	public JNode statements;

	public JBlock(Context context, JNode statements)
		: base(context)
	{
		this.kind__ = KIND;
		this.statements = statements;
	}

	public override Object Eval(VsaEngine engine)
#line 309 "./Nodes/JNode.tc"
	{
		if(statements != null)
		{
			return statements.Eval(engine);
		}
		else
		{
			return Empty.Value;
		}
	}
#line 181 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JBlock";
	}
}

internal class JConstant : JNode
{
	public new const int KIND = 4;

	public Object value;

	public JConstant(Context context, Object value)
		: base(context)
	{
		this.kind__ = KIND;
		this.value = value;
	}

	public override Object Eval(VsaEngine engine)
#line 23 "./Nodes/JExpr.tc"
	{
		return value;
	}
#line 215 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JConstant";
	}
}

internal class JUndefined : JNode
{
	public new const int KIND = 5;

	public JUndefined(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 29 "./Nodes/JExpr.tc"
	{
		return null;
	}
#line 246 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JUndefined";
	}
}

internal abstract class JExprList : JNode
{
	public new const int KIND = 6;

	public JExprListElem first;
	public JExprListElem last;

	protected JExprList(Context context)
		: base(context)
	{
		this.kind__ = KIND;
		this.first = null;
		this.last = null;
	}

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JExprList";
	}
}

internal class JExprListElem : JNode
{
	public new const int KIND = 7;

	public Object name;
	public JNode expr;
	public JExprListElem next;

	public JExprListElem(Context context, Object name, JNode expr, JExprListElem next)
		: base(context)
	{
		this.kind__ = KIND;
		this.name = name;
		this.expr = expr;
		this.next = next;
	}

	public override Object Eval(VsaEngine engine)
#line 35 "./Nodes/JExpr.tc"
	{
		// Nothing to do here: handled by the higher level.
		return null;
	}
#line 314 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JExprListElem";
	}
}

internal class JThis : JNode
{
	public new const int KIND = 10;

	public JThis(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 82 "./Nodes/JExpr.tc"
	{
		IActivationObject act =
			(engine.ScriptObjectStackTop() as IActivationObject);
		if(act != null)
		{
			return act.GetDefaultThisObject();
		}
		else
		{
			return DBNull.Value;
		}
	}
#line 354 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JThis";
	}
}

internal class JSuper : JNode
{
	public new const int KIND = 11;

	public JSuper(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 82 "./Nodes/JExpr.tc"
	{
		IActivationObject act =
			(engine.ScriptObjectStackTop() as IActivationObject);
		if(act != null)
		{
			return act.GetDefaultThisObject();
		}
		else
		{
			return DBNull.Value;
		}
	}
#line 394 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JSuper";
	}
}

internal class JIdentifier : JNode
{
	public new const int KIND = 12;

	public String name;

	public JIdentifier(Context context, String name)
		: base(context)
	{
		this.kind__ = KIND;
		this.name = name;
	}

	public override Object Eval(VsaEngine engine)
#line 97 "./Nodes/JExpr.tc"
	{
		IVariableAccess scope = (engine.ScriptObjectStackTop() as IVariableAccess);
		while(scope != null)
		{
			if(scope.HasVariable(name))
			{
				return scope.GetVariable(name);
			}
			scope = scope.GetParentScope();
		}
		return ((IVariableAccess)(engine.GetMainScope())).GetVariable(name);
	}
#line 437 "Nodes/JNode.cs"

	public override void Prepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 113 "./Nodes/JExpr.tc"
	{
		IVariableAccess scope = (engine.ScriptObjectStackTop() as IVariableAccess);
		while(scope != null)
		{
			if(scope.HasVariable(name))
			{
				data1 = scope;
				return;
			}
			scope = scope.GetParentScope();
		}
		data1 =  engine.GetMainScope();
	}
#line 454 "Nodes/JNode.cs"

	public override Object GetAndPrepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 130 "./Nodes/JExpr.tc"
	{
		IVariableAccess scope = (engine.ScriptObjectStackTop() as IVariableAccess);
		while(scope != null)
		{
			if(scope.HasVariable(name))
			{
				data1 = scope;
				return scope.GetVariable(name);
			}
			scope = scope.GetParentScope();
		}
		scope = (IVariableAccess)(engine.GetMainScope());
		data1 = scope;
		return scope.GetVariable(name);
	}
#line 473 "Nodes/JNode.cs"

	public override void Store(VsaEngine engine, Object data1, Object data2, Object value)
#line 149 "./Nodes/JExpr.tc"
	{
		((IVariableAccess)data1).SetVariable(name, value);
	}
#line 480 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JIdentifier";
	}
}

internal abstract class JUnaryExpression : JNode
{
	public new const int KIND = 13;

	public JNode expr;

	protected JUnaryExpression(Context context, JNode expr)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
	}

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JUnaryExpression";
	}
}

internal abstract class JBinaryExpression : JNode
{
	public new const int KIND = 14;

	public JNode expr1;
	public JNode expr2;

	protected JBinaryExpression(Context context, JNode expr1, JNode expr2)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr1 = expr1;
		this.expr2 = expr2;
	}

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JBinaryExpression";
	}
}

internal class JAssign : JNode
{
	public new const int KIND = 17;

	public JNode expr1;
	public JNode expr2;

	public JAssign(Context context, JNode expr1, JNode expr2)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr1 = expr1;
		this.expr2 = expr2;
	}

	public override Object Eval(VsaEngine engine)
#line 170 "./Nodes/JExpr.tc"
	{
		Object data1 = null;
		Object data2 = null;
		Object value;
		expr1.Prepare(engine, ref data1, ref data2);
		value = expr2.Eval(engine);
		expr1.Store(engine, data1, data2, value);
		return value;
	}
#line 578 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JAssign";
	}
}

internal class JAssignOp : JNode
{
	public new const int KIND = 18;

	public JSToken oper;
	public JNode expr1;
	public JNode expr2;

	public JAssignOp(Context context, JSToken oper, JNode expr1, JNode expr2)
		: base(context)
	{
		this.kind__ = KIND;
		this.oper = oper;
		this.expr1 = expr1;
		this.expr2 = expr2;
	}

	public override Object Eval(VsaEngine engine)
#line 182 "./Nodes/JExpr.tc"
	{
		Object data1 = null;
		Object data2 = null;
		Object value1, value2;
		value1 = expr1.GetAndPrepare(engine, ref data1, ref data2);
		value2 = expr2.Eval(engine);
		value1 = Convert.ToPrimitive(value1, DefaultValueHint.None);
		value2 = Convert.ToPrimitive(value2, DefaultValueHint.None);
		switch(oper)
		{
			case JSToken.PlusAssign:
			{
				if(value1 is String || value2 is String)
				{
					value1 = ((String)value1) + ((String)value2);
				}
				else
				{
					value1 = Convert.ToNumber(value1) + Convert.ToNumber(value2);
				}
			}
			break;
	
			case JSToken.MinusAssign:
			{
				value1 = Convert.ToNumber(value1) - Convert.ToNumber(value2);
			}
			break;
	
			case JSToken.MultiplyAssign:
			{
				value1 = Convert.ToNumber(value1) * Convert.ToNumber(value2);
			}
			break;
	
			case JSToken.DivideAssign:
			{
				value1 = Convert.ToNumber(value1) / Convert.ToNumber(value2);
			}
			break;
	
			case JSToken.ModuloAssign:
			{
				value1 = Convert.ToNumber(value1) % Convert.ToNumber(value2);
			}
			break;
	
			case JSToken.BitwiseOrAssign:
			{
				value1 = Convert.ToInt32(value1) | Convert.ToInt32(value2);
			}
			break;
	
			case JSToken.BitwiseXorAssign:
			{
				value1 = Convert.ToInt32(value1) ^ Convert.ToInt32(value2);
			}
			break;
	
			case JSToken.BitwiseAndAssign:
			{
				value1 = Convert.ToInt32(value1) & Convert.ToInt32(value2);
			}
			break;
	
			case JSToken.LeftShiftAssign:
			{
				value1 = Convert.ToInt32(value1) <<
				         (int)(Convert.ToUInt32(value2) & 0x1F);
			}
			break;
	
			case JSToken.RightShiftAssign:
			{
				value1 = Convert.ToInt32(value1) >>
				         (int)(Convert.ToUInt32(value2) & 0x1F);
			}
			break;
	
			case JSToken.UnsignedRightShiftAssign:
			{
				value1 = Convert.ToUInt32(value1) >>
				         (int)(Convert.ToUInt32(value2) & 0x1F);
			}
			break;
		}
		expr1.Store(engine, data1, data2, value1);
		return value1;
	}
#line 702 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JAssignOp";
	}
}

internal class JIfExpr : JNode
{
	public new const int KIND = 19;

	public JNode expr1;
	public JNode expr2;
	public JNode expr3;

	public JIfExpr(Context context, JNode expr1, JNode expr2, JNode expr3)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr1 = expr1;
		this.expr2 = expr2;
		this.expr3 = expr3;
	}

	public override Object Eval(VsaEngine engine)
#line 274 "./Nodes/JExpr.tc"
	{
		Object value = expr1.Eval(engine);
		if(Convert.ToBoolean(value))
		{
			return expr2.Eval(engine);
		}
		else
		{
			return expr3.Eval(engine);
		}
	}
#line 748 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JIfExpr";
	}
}

internal class JFieldAccess : JNode
{
	public new const int KIND = 56;

	public JNode expr;
	public String name;

	public JFieldAccess(Context context, JNode expr, String name)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
		this.name = name;
	}

	public override Object Eval(VsaEngine engine)
#line 766 "./Nodes/JExpr.tc"
	{
		Object thisob = Convert.ToObject(expr.Eval(engine), engine);
		if(thisob is ScriptObject)
		{
			return ((ScriptObject)thisob)[name];
		}
		else
		{
			return null;
		}
	}
#line 792 "Nodes/JNode.cs"

	public override void Prepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 780 "./Nodes/JExpr.tc"
	{
		data1 = Convert.ToObject(expr.Eval(engine), engine);
	}
#line 799 "Nodes/JNode.cs"

	public override Object GetAndPrepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 786 "./Nodes/JExpr.tc"
	{
		data1 = Convert.ToObject(expr.Eval(engine), engine);
		if(data1 is ScriptObject)
		{
			return ((ScriptObject)data1)[name];
		}
		else
		{
			return null;
		}
	}
#line 814 "Nodes/JNode.cs"

	public override void Store(VsaEngine engine, Object data1, Object data2, Object value)
#line 800 "./Nodes/JExpr.tc"
	{
		if(data1 is ScriptObject)
		{
			((ScriptObject)data1)[name] = value;
		}
	}
#line 824 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JFieldAccess";
	}
}

internal abstract class JStatement : JNode
{
	public new const int KIND = 61;

	public String[] labels;

	protected JStatement(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JStatement";
	}
}

internal class JFunction : JNode
{
	public new const int KIND = 82;

	public String name;
	public JFormalParams fparams;
	public JNode body;

	public JFunction(Context context, String name, JFormalParams fparams, JNode body)
		: base(context)
	{
		this.kind__ = KIND;
		this.name = name;
		this.fparams = fparams;
		this.body = body;
	}

	public override Object Eval(VsaEngine engine)
#line 322 "./Nodes/JNode.tc"
	{
		// Get the scope to declare the function within.
		ScriptObject scope = engine.ScriptObjectStackTop();
	
		// Create a function object to wrap up this function.
		FunctionObject obj = new FunctionObject
			(EngineInstance.GetEngineInstance(engine).GetFunctionPrototype(),
			 this, scope);
		
		// javascript allows for anonymous functions
		if(name != null)
		{
			// Add the function to the scope.
			if(scope is IVariableAccess)
			{
				((IVariableAccess)scope).SetVariable(name, obj);
			}
			else
			{
				scope.Put(name, obj);
			}
		}
	
		// Return compiled function object
		return obj;
	}
#line 911 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JFunction";
	}
}

internal class JArrayLiteral : JExprList
{
	public new const int KIND = 8;

	public int size;

	public JArrayLiteral(Context context, int size)
		: base(context)
	{
		this.kind__ = KIND;
		this.size = size;
	}

	public override Object Eval(VsaEngine engine)
#line 42 "./Nodes/JExpr.tc"
	{
		// Create a new instance of "Array".
		ArrayObject value = new ArrayObject
			(EngineInstance.GetEngineInstance(engine).GetArrayPrototype());
	
		// Evaluate and add the elements.
		JExprListElem elem = first;
		int index = 0;
		while(elem != null)
		{
			value[index++] = elem.expr.Eval(engine);
			elem = elem.next;
		}
	
		// Return the object to the caller.
		return value;
	}
#line 959 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JArrayLiteral";
	}
}

internal class JObjectLiteral : JExprList
{
	public new const int KIND = 9;

	public JObjectLiteral(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 62 "./Nodes/JExpr.tc"
	{
		// Create a new instance of "Object".
		JSObject value = new JSObject(EngineInstance.GetEngineInstance(engine)
											.GetObjectPrototype());
	
		// Evaluate and add the properties.
		JExprListElem elem = first;
		while(elem != null)
		{
			value.Put(Convert.ToString(elem.name), elem.expr.Eval(engine));
			elem = elem.next;
		}
	
		// Return the object to the caller.
		return value;
	}
#line 1003 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JObjectLiteral";
	}
}

internal class JFormalParams : JExprList
{
	public new const int KIND = 83;

	public JFormalParams(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 351 "./Nodes/JNode.tc"
	{
		// Never called - nothing to do here.
		return null;
	}
#line 1035 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JFormalParams";
	}
}

internal class JAsIs : JUnaryExpression
{
	public new const int KIND = 15;

	public JAsIs(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 157 "./Nodes/JExpr.tc"
	{
		return expr.Eval(engine);
	}
#line 1066 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JAsIs";
	}
}

internal class JNeg : JUnaryExpression
{
	public new const int KIND = 43;

	public JNeg(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 509 "./Nodes/JExpr.tc"
	{
		return -(Convert.ToNumber(expr.Eval(engine)));
	}
#line 1097 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JNeg";
	}
}

internal class JUnaryPlus : JUnaryExpression
{
	public new const int KIND = 44;

	public JUnaryPlus(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 515 "./Nodes/JExpr.tc"
	{
		return Convert.ToNumber(expr.Eval(engine));
	}
#line 1128 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JUnaryPlus";
	}
}

internal class JDelete : JUnaryExpression
{
	public new const int KIND = 45;

	public JDelete(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 521 "./Nodes/JExpr.tc"
	{
		if(expr is JFieldAccess)
		{
			// Must be a "JFieldAccess" to make sense.
			Object thisob = Convert.ToObject
				(((JFieldAccess)expr).Eval(engine), engine);
			if(thisob is ScriptObject)
			{
				return ((ScriptObject)thisob).Delete(((JFieldAccess)expr).name);
			}
			else
			{
				return true;
			}
		}
		else
		{
			// Evaluate expr for its side-effects only.
			expr.Eval(engine);
			return true;
		}
	}
#line 1178 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JDelete";
	}
}

internal class JVoid : JUnaryExpression
{
	public new const int KIND = 46;

	public JVoid(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 546 "./Nodes/JExpr.tc"
	{
		// Evaluate the sub-expression and then return "undefined".
		expr.Eval(engine);
		return null;
	}
#line 1211 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JVoid";
	}
}

internal class JTypeof : JUnaryExpression
{
	public new const int KIND = 47;

	public JTypeof(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 554 "./Nodes/JExpr.tc"
	{
		return Support.Typeof(expr.Eval(engine));
	}
#line 1242 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JTypeof";
	}
}

internal class JPreInc : JUnaryExpression
{
	public new const int KIND = 48;

	public JPreInc(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 560 "./Nodes/JExpr.tc"
	{
		Object data1 = null;
		Object data2 = null;
		Object value = expr.GetAndPrepare(engine, ref data1, ref data2);
		value = Convert.ToNumber(value) + 1.0;
		expr.Store(engine, data1, data2, value);
		return value;
	}
#line 1278 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JPreInc";
	}
}

internal class JPreDec : JUnaryExpression
{
	public new const int KIND = 49;

	public JPreDec(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 571 "./Nodes/JExpr.tc"
	{
		Object data1 = null;
		Object data2 = null;
		Object value = expr.GetAndPrepare(engine, ref data1, ref data2);
		value = Convert.ToNumber(value) - 1.0;
		expr.Store(engine, data1, data2, value);
		return value;
	}
#line 1314 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JPreDec";
	}
}

internal class JPostInc : JUnaryExpression
{
	public new const int KIND = 50;

	public JPostInc(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 582 "./Nodes/JExpr.tc"
	{
		Object data1 = null;
		Object data2 = null;
		Object value = expr.GetAndPrepare(engine, ref data1, ref data2);
		double value2 = Convert.ToNumber(value);
		expr.Store(engine, data1, data2, value2 + 1.0);
		return value2;
	}
#line 1350 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JPostInc";
	}
}

internal class JPostDec : JUnaryExpression
{
	public new const int KIND = 51;

	public JPostDec(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 593 "./Nodes/JExpr.tc"
	{
		Object data1 = null;
		Object data2 = null;
		Object value = expr.GetAndPrepare(engine, ref data1, ref data2);
		double value2 = Convert.ToNumber(value);
		expr.Store(engine, data1, data2, value2 - 1.0);
		return value2;
	}
#line 1386 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JPostDec";
	}
}

internal class JBitwiseNot : JUnaryExpression
{
	public new const int KIND = 52;

	public JBitwiseNot(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 604 "./Nodes/JExpr.tc"
	{
		return ~(Convert.ToInt32(expr.Eval(engine)));
	}
#line 1417 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JBitwiseNot";
	}
}

internal class JLogicalNot : JUnaryExpression
{
	public new const int KIND = 53;

	public JLogicalNot(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 610 "./Nodes/JExpr.tc"
	{
		if(Convert.ToBoolean(expr.Eval(engine)))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
#line 1455 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JLogicalNot";
	}
}

internal class JEval : JUnaryExpression
{
	public new const int KIND = 59;

	public JEval(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 854 "./Nodes/JExpr.tc"
	{
		return Microsoft.JScript.Eval.JScriptEvaluate(expr.Eval(engine), engine);
	}
#line 1486 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JEval";
	}
}

internal class JPrint : JUnaryExpression
{
	public new const int KIND = 60;

	public JPrint(Context context, JNode expr)
		: base(context, expr)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 860 "./Nodes/JExpr.tc"
	{
		Support.Print(engine, expr);
		return Empty.Value;
	}
#line 1518 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JPrint";
	}
}

internal class JComma : JBinaryExpression
{
	public new const int KIND = 16;

	public JComma(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 163 "./Nodes/JExpr.tc"
	{
		expr1.Eval(engine);
		return expr2.Eval(engine);
	}
#line 1550 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JComma";
	}
}

internal class JLogicalOr : JBinaryExpression
{
	public new const int KIND = 20;

	public JLogicalOr(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 288 "./Nodes/JExpr.tc"
	{
		Object value = expr1.Eval(engine);
		if(Convert.ToBoolean(value))
		{
			return value;
		}
		else
		{
			return expr2.Eval(engine);
		}
	}
#line 1589 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JLogicalOr";
	}
}

internal class JLogicalAnd : JBinaryExpression
{
	public new const int KIND = 21;

	public JLogicalAnd(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 302 "./Nodes/JExpr.tc"
	{
		Object value = expr1.Eval(engine);
		if(!Convert.ToBoolean(value))
		{
			return value;
		}
		else
		{
			return expr2.Eval(engine);
		}
	}
#line 1628 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JLogicalAnd";
	}
}

internal class JBitwiseOr : JBinaryExpression
{
	public new const int KIND = 22;

	public JBitwiseOr(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 316 "./Nodes/JExpr.tc"
	{
		return Convert.ToInt32(expr1.Eval(engine)) |
			   Convert.ToInt32(expr2.Eval(engine));
	}
#line 1660 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JBitwiseOr";
	}
}

internal class JBitwiseXor : JBinaryExpression
{
	public new const int KIND = 23;

	public JBitwiseXor(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 323 "./Nodes/JExpr.tc"
	{
		return Convert.ToInt32(expr1.Eval(engine)) ^
			   Convert.ToInt32(expr2.Eval(engine));
	}
#line 1692 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JBitwiseXor";
	}
}

internal class JBitwiseAnd : JBinaryExpression
{
	public new const int KIND = 24;

	public JBitwiseAnd(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 330 "./Nodes/JExpr.tc"
	{
		return Convert.ToInt32(expr1.Eval(engine)) &
			   Convert.ToInt32(expr2.Eval(engine));
	}
#line 1724 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JBitwiseAnd";
	}
}

internal class JEq : JBinaryExpression
{
	public new const int KIND = 25;

	public JEq(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 337 "./Nodes/JExpr.tc"
	{
		return Equality.JScriptEquals(expr1.Eval(engine), expr2.Eval(engine));
	}
#line 1755 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JEq";
	}
}

internal class JNe : JBinaryExpression
{
	public new const int KIND = 26;

	public JNe(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 343 "./Nodes/JExpr.tc"
	{
		return !Equality.JScriptEquals(expr1.Eval(engine), expr2.Eval(engine));
	}
#line 1786 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JNe";
	}
}

internal class JStrictEq : JBinaryExpression
{
	public new const int KIND = 27;

	public JStrictEq(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 349 "./Nodes/JExpr.tc"
	{
		return StrictEquality.JScriptStrictEquals
			(expr1.Eval(engine), expr2.Eval(engine));
	}
#line 1818 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JStrictEq";
	}
}

internal class JStrictNe : JBinaryExpression
{
	public new const int KIND = 28;

	public JStrictNe(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 356 "./Nodes/JExpr.tc"
	{
		return !StrictEquality.JScriptStrictEquals
			(expr1.Eval(engine), expr2.Eval(engine));
	}
#line 1850 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JStrictNe";
	}
}

internal class JLt : JBinaryExpression
{
	public new const int KIND = 29;

	public JLt(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 363 "./Nodes/JExpr.tc"
	{
		Object value1 = Convert.ToPrimitive(expr1.Eval(engine),
											DefaultValueHint.Number);
		Object value2 = Convert.ToPrimitive(expr2.Eval(engine),
											DefaultValueHint.Number);
		if(value1 is String && value2 is String)
		{
			return (String.CompareOrdinal((String)value1, (String)value2) < 0);
		}
		else
		{
			return (Convert.ToNumber(value1) < Convert.ToNumber(value2));
		}
	}
#line 1892 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JLt";
	}
}

internal class JLe : JBinaryExpression
{
	public new const int KIND = 30;

	public JLe(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 380 "./Nodes/JExpr.tc"
	{
		Object value1 = Convert.ToPrimitive(expr1.Eval(engine),
											DefaultValueHint.Number);
		Object value2 = Convert.ToPrimitive(expr2.Eval(engine),
											DefaultValueHint.Number);
		if(value1 is String && value2 is String)
		{
			return (String.CompareOrdinal((String)value1, (String)value2) <= 0);
		}
		else
		{
			return (Convert.ToNumber(value1) <= Convert.ToNumber(value2));
		}
	}
#line 1934 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JLe";
	}
}

internal class JGt : JBinaryExpression
{
	public new const int KIND = 31;

	public JGt(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 397 "./Nodes/JExpr.tc"
	{
		Object value1 = Convert.ToPrimitive(expr1.Eval(engine),
											DefaultValueHint.Number);
		Object value2 = Convert.ToPrimitive(expr2.Eval(engine),
											DefaultValueHint.Number);
		if(value1 is String && value2 is String)
		{
			return (String.CompareOrdinal((String)value1, (String)value2) > 0);
		}
		else
		{
			return (Convert.ToNumber(value1) > Convert.ToNumber(value2));
		}
	}
#line 1976 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JGt";
	}
}

internal class JGe : JBinaryExpression
{
	public new const int KIND = 32;

	public JGe(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 414 "./Nodes/JExpr.tc"
	{
		Object value1 = Convert.ToPrimitive(expr1.Eval(engine),
											DefaultValueHint.Number);
		Object value2 = Convert.ToPrimitive(expr2.Eval(engine),
											DefaultValueHint.Number);
		if(value1 is String && value2 is String)
		{
			return (String.CompareOrdinal((String)value1, (String)value2) >= 0);
		}
		else
		{
			return (Convert.ToNumber(value1) >= Convert.ToNumber(value2));
		}
	}
#line 2018 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JGe";
	}
}

internal class JInstanceof : JBinaryExpression
{
	public new const int KIND = 33;

	public JInstanceof(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 431 "./Nodes/JExpr.tc"
	{
		return Instanceof.JScriptInstanceof(expr1.Eval(engine), expr2.Eval(engine));
	}
#line 2049 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JInstanceof";
	}
}

internal class JIn : JBinaryExpression
{
	public new const int KIND = 34;

	public JIn(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 437 "./Nodes/JExpr.tc"
	{
		return In.JScriptIn(expr1.Eval(engine), expr2.Eval(engine));
	}
#line 2080 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JIn";
	}
}

internal class JShl : JBinaryExpression
{
	public new const int KIND = 35;

	public JShl(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 443 "./Nodes/JExpr.tc"
	{
		return Convert.ToInt32(expr1.Eval(engine)) <<
			   (int)(Convert.ToUInt32(expr2.Eval(engine)) & 0x1F);
	}
#line 2112 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JShl";
	}
}

internal class JShr : JBinaryExpression
{
	public new const int KIND = 36;

	public JShr(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 450 "./Nodes/JExpr.tc"
	{
		return Convert.ToInt32(expr1.Eval(engine)) >>
			   (int)(Convert.ToUInt32(expr2.Eval(engine)) & 0x1F);
	}
#line 2144 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JShr";
	}
}

internal class JUShr : JBinaryExpression
{
	public new const int KIND = 37;

	public JUShr(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 457 "./Nodes/JExpr.tc"
	{
		return Convert.ToUInt32(expr1.Eval(engine)) >>
			   (int)(Convert.ToUInt32(expr2.Eval(engine)) & 0x1F);
	}
#line 2176 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JUShr";
	}
}

internal class JAdd : JBinaryExpression
{
	public new const int KIND = 38;

	public JAdd(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 464 "./Nodes/JExpr.tc"
	{
		Object value1 = Convert.ToPrimitive(expr1.Eval(engine),
											DefaultValueHint.None);
		Object value2 = Convert.ToPrimitive(expr2.Eval(engine),
											DefaultValueHint.None);
		if(value1 is String || value2 is String)
		{
			return value1.ToString() + value2.ToString();
		}
		else
		{
			return Convert.ToNumber(value1) + Convert.ToNumber(value2);
		}
	}
#line 2218 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JAdd";
	}
}

internal class JSub : JBinaryExpression
{
	public new const int KIND = 39;

	public JSub(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 481 "./Nodes/JExpr.tc"
	{
		return Convert.ToNumber(expr1.Eval(engine)) -
			   Convert.ToNumber(expr2.Eval(engine));
	}
#line 2250 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JSub";
	}
}

internal class JMul : JBinaryExpression
{
	public new const int KIND = 40;

	public JMul(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 488 "./Nodes/JExpr.tc"
	{
		return Convert.ToNumber(expr1.Eval(engine)) *
			   Convert.ToNumber(expr2.Eval(engine));
	}
#line 2282 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JMul";
	}
}

internal class JDiv : JBinaryExpression
{
	public new const int KIND = 41;

	public JDiv(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 495 "./Nodes/JExpr.tc"
	{
		return Convert.ToNumber(expr1.Eval(engine)) /
			   Convert.ToNumber(expr2.Eval(engine));
	}
#line 2314 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JDiv";
	}
}

internal class JRem : JBinaryExpression
{
	public new const int KIND = 42;

	public JRem(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 502 "./Nodes/JExpr.tc"
	{
		return Convert.ToNumber(expr1.Eval(engine)) %
			   Convert.ToNumber(expr2.Eval(engine));
	}
#line 2346 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JRem";
	}
}

internal class JNew : JBinaryExpression
{
	public new const int KIND = 54;

	public JNew(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 623 "./Nodes/JExpr.tc"
	{
		// Evaluate the constructor.
		Object constructor;
		constructor = expr1.Eval(engine);
	
		// Evaluate the arguments.
		Object[] args = Support.EvalArgList(expr2, engine);
	
		// Bail out if the constructor object is invalid.
		if(!(constructor is ScriptFunction))
		{
			throw new JScriptException(JSError.FunctionExpected, this.context);
		}
	
		// Call the constructor.
		return ((ScriptFunction)constructor).Construct(engine, args);
	}
#line 2391 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JNew";
	}
}

internal class JArrayAccess : JBinaryExpression
{
	public new const int KIND = 55;

	public JArrayAccess(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 643 "./Nodes/JExpr.tc"
	{
		Object thisob = Convert.ToObject(expr1.Eval(engine), engine);
		Object value = expr2.Eval(engine);
		if(thisob is ScriptObject)
		{
			// Try to handle special cases to make array accesses more efficient.
			if(value is int)
			{
				return ((ScriptObject)thisob)[(int)value];
			}
			else if(value is double)
			{
				return ((ScriptObject)thisob)[(double)value];
			}
			else if(value is String)
			{
				return ((ScriptObject)thisob)[(String)value];
			}
			else
			{
				return ((ScriptObject)thisob)[value];
			}
		}
		else if(thisob is Array)
		{
			// Get the element from an underlying CLI array.
			return ((Array)thisob).GetValue(Convert.ToInt32(value));
		}
		else if(thisob is IDictionary)
		{
			// Get the element from an underlying CLI dictionary.
			return ((IDictionary)thisob)[value];
		}
		else
		{
			return null;
		}
	}
#line 2457 "Nodes/JNode.cs"

	public override void Prepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 684 "./Nodes/JExpr.tc"
	{
		data1 = Convert.ToObject(expr1.Eval(engine), engine);
		data2 = expr2.Eval(engine);
	}
#line 2465 "Nodes/JNode.cs"

	public override Object GetAndPrepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 691 "./Nodes/JExpr.tc"
	{
		data1 = Convert.ToObject(expr1.Eval(engine), engine);
		data2 = expr2.Eval(engine);
		if(data1 is ScriptObject)
		{
			// Try to handle special cases to make array accesses more efficient.
			if(data2 is int)
			{
				return ((ScriptObject)data1)[(int)data2];
			}
			else if(data2 is double)
			{
				return ((ScriptObject)data1)[(double)data2];
			}
			else if(data2 is String)
			{
				return ((ScriptObject)data1)[(String)data2];
			}
			else
			{
				return ((ScriptObject)data1)[data2];
			}
		}
		else if(data1 is Array)
		{
			// Get the element from an underlying CLI array.
			return ((Array)data1).GetValue(Convert.ToInt32(data2));
		}
		else if(data1 is IDictionary)
		{
			// Get the element from an underlying CLI dictionary.
			return ((IDictionary)data1)[data2];
		}
		else
		{
			return null;
		}
	}
#line 2507 "Nodes/JNode.cs"

	public override void Store(VsaEngine engine, Object data1, Object data2, Object value)
#line 732 "./Nodes/JExpr.tc"
	{
		if(data1 is ScriptObject)
		{
			if(data2 is int)
			{
				((ScriptObject)data1)[(int)data2] = value;
			}
			else if(data2 is double)
			{
				((ScriptObject)data1)[(double)data2] = value;
			}
			else if(data2 is String)
			{
				((ScriptObject)data1)[(String)data2] = value;
			}
			else
			{
				((ScriptObject)data1)[data2] = value;
			}
		}
		else if(data1 is Array)
		{
			// Store the element into an underlying CLI array.
			((Array)data1).SetValue(value, Convert.ToInt32(data2));
		}
		else if(data1 is IDictionary)
		{
			// Store the element into an underlying CLI dictionary.
			((IDictionary)data1)[data2] = value;
		}
	}
#line 2542 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JArrayAccess";
	}
}

internal class JCall : JBinaryExpression
{
	public new const int KIND = 57;

	public JCall(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 809 "./Nodes/JExpr.tc"
	{
		// Evaluate the function and the "this" object.
		Object thisob;
		Object func;
		if(expr1 is JFieldAccess)
		{
			thisob = Convert.ToObject
				(((JFieldAccess)expr1).expr.Eval(engine), engine);
			if(thisob is ScriptObject)
			{
				func = ((ScriptObject)thisob).Get(((JFieldAccess)expr1).name);
			}
			else
			{
				func = null;
			}
		}
		else
		{
			thisob = null;
			func = expr1.Eval(engine);
		}
	
		// Evaluate the arguments.
		Object[] args = Support.EvalArgList(expr2, engine);
	
		// Bail out if the function object is invalid.
		if(!(func is ScriptFunction))
		{
			throw new JScriptException(JSError.FunctionExpected, this.context);
		}
	
		// Call the function.
		return ((ScriptFunction)func).Call(engine, thisob, args);
	}
#line 2605 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JCall";
	}
}

internal class JArgList : JBinaryExpression
{
	public new const int KIND = 58;

	public JArgList(Context context, JNode expr1, JNode expr2)
		: base(context, expr1, expr2)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 847 "./Nodes/JExpr.tc"
	{
		// Nothing to do here: handled by "Support.EvalArgList" instead.
		return null;
	}
#line 2637 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JArgList";
	}
}

internal class JEmpty : JStatement
{
	public new const int KIND = 62;

	public JEmpty(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 23 "./Nodes/JStmt.tc"
	{
		return Empty.Value;
	}
#line 2668 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JEmpty";
	}
}

internal class JCompound : JStatement
{
	public new const int KIND = 63;

	public JNode stmt1;
	public JNode stmt2;
	public JNode stmt3;
	public JNode stmt4;
	public JCompound next;

	public JCompound(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 29 "./Nodes/JStmt.tc"
	{
		Object last = Empty.Value;
		JCompound node = this;
		do
		{
			if(node.stmt1 != null)
			{
				last = node.stmt1.Eval(engine);
			}
			if(node.stmt2 != null)
			{
				last = node.stmt2.Eval(engine);
			}
			if(node.stmt3 != null)
			{
				last = node.stmt3.Eval(engine);
			}
			if(node.stmt4 != null)
			{
				last = node.stmt4.Eval(engine);
			}
			node = node.next;
		}
		while(node != null);
		return last;
	}
#line 2728 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JCompound";
	}
}

internal class JExprStmt : JStatement
{
	public new const int KIND = 64;

	public JNode expr;

	public JExprStmt(Context context, JNode expr)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
	}

	public override Object Eval(VsaEngine engine)
#line 58 "./Nodes/JStmt.tc"
	{
		return expr.Eval(engine);
	}
#line 2762 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JExprStmt";
	}
}

internal class JIf : JStatement
{
	public new const int KIND = 65;

	public JNode condition;
	public JNode thenClause;
	public JNode elseClause;

	public JIf(Context context, JNode condition, JNode thenClause, JNode elseClause)
		: base(context)
	{
		this.kind__ = KIND;
		this.condition = condition;
		this.thenClause = thenClause;
		this.elseClause = elseClause;
	}

	public override Object Eval(VsaEngine engine)
#line 64 "./Nodes/JStmt.tc"
	{
		Object value = condition.Eval(engine);
		if(Convert.ToBoolean(value))
		{
			if(thenClause != null)
			{
				return thenClause.Eval(engine);
			}
		}
		else
		{
			if(elseClause != null)
			{
				return elseClause.Eval(engine);
			}
		}
		return Empty.Value;
	}
#line 2815 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JIf";
	}
}

internal class JWhile : JStatement
{
	public new const int KIND = 66;

	public JNode condition;
	public JNode body;

	public JWhile(Context context, JNode condition, JNode body)
		: base(context)
	{
		this.kind__ = KIND;
		this.condition = condition;
		this.body = body;
	}

	public override Object Eval(VsaEngine engine)
#line 85 "./Nodes/JStmt.tc"
	{
		Object result = Empty.Value;
		Object temp;
		try
		{
			while(Convert.ToBoolean(condition.Eval(engine)))
			{
				try
				{
					if(body != null)
					{
						temp = body.Eval(engine);
						if(temp != Empty.Value)
						{
							result = temp;
						}
					}
				}
				catch(ContinueJumpOut cont)
				{
					// We received a "continue" from inside the "while" loop.
					if(!Support.LabelMatch(cont.label, labels))
					{
						throw;
					}
				}
			}
		}
		catch(BreakJumpOut brk)
		{
			// We received a "break" from inside the "while" loop.
			if(!Support.LabelMatch(brk.label, labels))
			{
				throw;
			}
		}
		return result;
	}
#line 2886 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JWhile";
	}
}

internal class JDo : JStatement
{
	public new const int KIND = 67;

	public JNode body;
	public JNode condition;

	public JDo(Context context, JNode body, JNode condition)
		: base(context)
	{
		this.kind__ = KIND;
		this.body = body;
		this.condition = condition;
	}

	public override Object Eval(VsaEngine engine)
#line 126 "./Nodes/JStmt.tc"
	{
		Object result = Empty.Value;
		Object temp;
		try
		{
			do
			{
				try
				{
					if(body != null)
					{
						temp = body.Eval(engine);
						if(temp != Empty.Value)
						{
							result = temp;
						}
					}
				}
				catch(ContinueJumpOut cont)
				{
					// We received a "continue" from inside the "do" loop.
					if(!Support.LabelMatch(cont.label, labels))
					{
						throw;
					}
				}
			}
			while(Convert.ToBoolean(condition.Eval(engine)));
		}
		catch(BreakJumpOut brk)
		{
			// We received a "break" from inside the "do" loop.
			if(!Support.LabelMatch(brk.label, labels))
			{
				throw;
			}
		}
		return result;
	}
#line 2958 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JDo";
	}
}

internal class JFor : JStatement
{
	public new const int KIND = 68;

	public JNode init;
	public JNode cond;
	public JNode incr;
	public JNode body;

	public JFor(Context context, JNode init, JNode cond, JNode incr, JNode body)
		: base(context)
	{
		this.kind__ = KIND;
		this.init = init;
		this.cond = cond;
		this.incr = incr;
		this.body = body;
	}

	public override Object Eval(VsaEngine engine)
#line 168 "./Nodes/JStmt.tc"
	{
		Object result = Empty.Value;
		Object temp;
		if(init != null)
		{
			init.Eval(engine);
		}
		try
		{
			while(cond == null || Convert.ToBoolean(cond.Eval(engine)))
			{
				try
				{
					if(body != null)
					{
						temp = body.Eval(engine);
						if(temp != Empty.Value)
						{
							result = temp;
						}
					}
				}
				catch(ContinueJumpOut cont)
				{
					// We received a "continue" from inside the "for" loop.
					if(!Support.LabelMatch(cont.label, labels))
					{
						throw;
					}
				}
				if(incr != null)
				{
					incr.Eval(engine);
				}
			}
		}
		catch(BreakJumpOut brk)
		{
			// We received a "break" from inside the "for" loop.
			if(!Support.LabelMatch(brk.label, labels))
			{
				throw;
			}
		}
		return result;
	}
#line 3041 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JFor";
	}
}

internal class JForIn : JStatement
{
	public new const int KIND = 69;

	public JNode decl;
	public JNode expr;
	public JNode body;

	public JForIn(Context context, JNode decl, JNode expr, JNode body)
		: base(context)
	{
		this.kind__ = KIND;
		this.decl = decl;
		this.expr = expr;
		this.body = body;
	}

	public override Object Eval(VsaEngine engine)
#line 217 "./Nodes/JStmt.tc"
	{
		// Evaluate variable declarations, to make sure that the
		// variable is properly declared into the current scope.
		if(decl is JVarDecl)
		{
			decl.Eval(engine);
		}
	
		// Get the collection that we will be enumerating.
		Object set = expr.Eval(engine);
		IEnumerator e = ForIn.JScriptGetEnumerator(set);
	
		// Loop over the collection.
		Object result = Empty.Value;
		Object data1, data2, temp;
		try
		{
			while(e.MoveNext())
			{
				try
				{
					// Assign e.Current to the loop variable.
					data1 = null;
					data2 = null;
					decl.Prepare(engine, ref data1, ref data2);
					decl.Store(engine, data1, data2, e.Current);
	
					// Execute the loop body.
					if(body != null)
					{
						temp = body.Eval(engine);
						if(temp != Empty.Value)
						{
							result = temp;
						}
					}
				}
				catch(ContinueJumpOut cont)
				{
					// We received a "continue" from inside the "for-in" loop.
					if(!Support.LabelMatch(cont.label, labels))
					{
						throw;
					}
				}
			}
		}
		catch(BreakJumpOut brk)
		{
			// We received a "break" from inside the "for-in" loop.
			if(!Support.LabelMatch(brk.label, labels))
			{
				throw;
			}
		}
		finally
		{
			if(e is IDisposable)
			{
				((IDisposable)e).Dispose();
			}
		}
		return result;
	}
#line 3140 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JForIn";
	}
}

internal class JSwitch : JStatement
{
	public new const int KIND = 70;

	public JNode expr;
	public JNode cases;

	public JSwitch(Context context, JNode expr, JNode cases)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
		this.cases = cases;
	}

	public override Object Eval(VsaEngine engine)
#line 284 "./Nodes/JStmt.tc"
	{
		Object value = expr.Eval(engine);
		Object testValue;
		Object result = Empty.Value;
		JCompound node;
		JNode child, defCase;
		if(cases == null)
		{
			return result;
		}
		try
		{
			if(cases is JCase)
			{
				// Only has a single "case".
				testValue = ((JCase)cases).expr.Eval(engine);
				if(Equality.JScriptEquals(value, testValue))
				{
					result = ((JCase)cases).body.Eval(engine);
				}
			}
			else if(cases is JDefault)
			{
				// Only has a "default" case, which we always execute.
				result = ((JDefault)cases).body.Eval(engine);
			}
			else
			{
				// Search for an applicable case.
				defCase = null;
				node = (JCompound)cases;
				do
				{
					if(node.stmt1 != null)
					{
						child = node.stmt1;
						if(child is JCase)
						{
							testValue = ((JCase)child).expr.Eval(engine);
							if(Equality.JScriptEquals(value, testValue))
							{
								return ((JCase)child).body.Eval(engine);
							}
						}
						else
						{
							defCase = child;
						}
					}
					if(node.stmt2 != null)
					{
						child = node.stmt2;
						if(child is JCase)
						{
							testValue = ((JCase)child).expr.Eval(engine);
							if(Equality.JScriptEquals(value, testValue))
							{
								return ((JCase)child).body.Eval(engine);
							}
						}
						else
						{
							defCase = child;
						}
					}
					if(node.stmt3 != null)
					{
						child = node.stmt3;
						if(child is JCase)
						{
							testValue = ((JCase)child).expr.Eval(engine);
							if(Equality.JScriptEquals(value, testValue))
							{
								return ((JCase)child).body.Eval(engine);
							}
						}
						else
						{
							defCase = child;
						}
					}
					if(node.stmt4 != null)
					{
						child = node.stmt4;
						if(child is JCase)
						{
							testValue = ((JCase)child).expr.Eval(engine);
							if(Equality.JScriptEquals(value, testValue))
							{
								return ((JCase)child).body.Eval(engine);
							}
						}
						else
						{
							defCase = child;
						}
					}
					node = node.next;
				}
				while(node != null);
				if(defCase != null)
				{
					result = defCase.Eval(engine);
				}
			}
		}
		catch(BreakJumpOut brk)
		{
			// We received a "break" from inside the "switch" statement.
			if(!Support.LabelMatch(brk.label, labels))
			{
				throw;
			}
		}
		return result;
	}
#line 3289 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JSwitch";
	}
}

internal class JCase : JStatement
{
	public new const int KIND = 71;

	public JNode expr;
	public JNode body;

	public JCase(Context context, JNode expr, JNode body)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
		this.body = body;
	}

	public override Object Eval(VsaEngine engine)
#line 404 "./Nodes/JStmt.tc"
	{
		return body.Eval(engine);
	}
#line 3325 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JCase";
	}
}

internal class JDefault : JStatement
{
	public new const int KIND = 72;

	public JNode body;

	public JDefault(Context context, JNode body)
		: base(context)
	{
		this.kind__ = KIND;
		this.body = body;
	}

	public override Object Eval(VsaEngine engine)
#line 404 "./Nodes/JStmt.tc"
	{
		return body.Eval(engine);
	}
#line 3359 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JDefault";
	}
}

internal class JFallThrough : JStatement
{
	public new const int KIND = 73;

	public JNode stmt;

	public JFallThrough(Context context, JNode stmt)
		: base(context)
	{
		this.kind__ = KIND;
		this.stmt = stmt;
	}

	public override Object Eval(VsaEngine engine)
#line 411 "./Nodes/JStmt.tc"
	{
		return stmt.Eval(engine);
	}
#line 3393 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JFallThrough";
	}
}

internal class JContinue : JStatement
{
	public new const int KIND = 74;

	public String label;

	public JContinue(Context context, String label)
		: base(context)
	{
		this.kind__ = KIND;
		this.label = label;
	}

	public override Object Eval(VsaEngine engine)
#line 417 "./Nodes/JStmt.tc"
	{
		throw new ContinueJumpOut(label, context);
	}
#line 3427 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JContinue";
	}
}

internal class JBreak : JStatement
{
	public new const int KIND = 75;

	public String label;

	public JBreak(Context context, String label)
		: base(context)
	{
		this.kind__ = KIND;
		this.label = label;
	}

	public override Object Eval(VsaEngine engine)
#line 423 "./Nodes/JStmt.tc"
	{
		throw new BreakJumpOut(label, context);
	}
#line 3461 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JBreak";
	}
}

internal class JReturn : JStatement
{
	public new const int KIND = 76;

	public JReturn(Context context)
		: base(context)
	{
		this.kind__ = KIND;
	}

	public override Object Eval(VsaEngine engine)
#line 429 "./Nodes/JStmt.tc"
	{
		throw new ReturnJumpOut(null, context);
	}
#line 3492 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JReturn";
	}
}

internal class JReturnExpr : JStatement
{
	public new const int KIND = 77;

	public JNode expr;

	public JReturnExpr(Context context, JNode expr)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
	}

	public override Object Eval(VsaEngine engine)
#line 435 "./Nodes/JStmt.tc"
	{
		throw new ReturnJumpOut(expr.Eval(engine), context);
	}
#line 3526 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JReturnExpr";
	}
}

internal class JThrow : JStatement
{
	public new const int KIND = 78;

	public JNode expr;

	public JThrow(Context context, JNode expr)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
	}

	public override Object Eval(VsaEngine engine)
#line 441 "./Nodes/JStmt.tc"
	{
		throw Throw.JScriptThrow(expr.Eval(engine));
	}
#line 3560 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JThrow";
	}
}

internal class JWith : JStatement
{
	public new const int KIND = 79;

	public JNode expr;
	public JNode body;

	public JWith(Context context, JNode expr, JNode body)
		: base(context)
	{
		this.kind__ = KIND;
		this.expr = expr;
		this.body = body;
	}

	public override Object Eval(VsaEngine engine)
#line 447 "./Nodes/JStmt.tc"
	{
		Object result;
	
		// Evaluate the expression to use inside the "with" block
		// and push it onto the script object stack.
		try
		{
			With.JScriptWith(expr.Eval(engine), engine);
		}
		catch(JScriptException e)
		{
			e.context = expr.context.MakeCopy();
			throw e;
		}
	
		// Evaluate the body of the "with" block.
		try
		{
			result = body.Eval(engine);
		}
		finally
		{
			engine.PopScriptObject();
		}
		return result;
	}
#line 3619 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JWith";
	}
}

internal class JVarDecl : JStatement
{
	public new const int KIND = 80;

	public String name;
	public JNode initializer;

	public JVarDecl(Context context, String name, JNode initializer)
		: base(context)
	{
		this.kind__ = KIND;
		this.name = name;
		this.initializer = initializer;
	}

	public override Object Eval(VsaEngine engine)
#line 476 "./Nodes/JStmt.tc"
	{
		// Get the current variable definition scope.
		IActivationObject scope =
			(IActivationObject)(engine.ScriptObjectStackTop());
	
		// We can take a short-cut if the scope implements "IVariableAccess".
		// This avoids creating unnecessary "FieldInfo" objects.
		IVariableAccess varAccess = (scope as IVariableAccess);
		if(varAccess != null)
		{
			if(initializer != null)
			{
				varAccess.SetVariable(name, initializer.Eval(engine));
			}
			else
			{
				varAccess.DeclareVariable(name);
			}
			return name;
		}
	
		// Get the field reference for the variable.
		FieldInfo field = scope.GetLocalField(name);
		if(field == null)
		{
			// Create a new field within the activation object with this name.
			// TODO
		}
		if(initializer != null)
		{
			// Set the variable to the specified initializer value.
			// TODO
		}
	
		// Return the name of the variable as the node's final value.
		return name;
	}
#line 3689 "Nodes/JNode.cs"

	public override void Prepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 113 "./Nodes/JExpr.tc"
	{
		IVariableAccess scope = (engine.ScriptObjectStackTop() as IVariableAccess);
		while(scope != null)
		{
			if(scope.HasVariable(name))
			{
				data1 = scope;
				return;
			}
			scope = scope.GetParentScope();
		}
		data1 =  engine.GetMainScope();
	}
#line 3706 "Nodes/JNode.cs"

	public override Object GetAndPrepare(VsaEngine engine, ref Object data1, ref Object data2)
#line 130 "./Nodes/JExpr.tc"
	{
		IVariableAccess scope = (engine.ScriptObjectStackTop() as IVariableAccess);
		while(scope != null)
		{
			if(scope.HasVariable(name))
			{
				data1 = scope;
				return scope.GetVariable(name);
			}
			scope = scope.GetParentScope();
		}
		scope = (IVariableAccess)(engine.GetMainScope());
		data1 = scope;
		return scope.GetVariable(name);
	}
#line 3725 "Nodes/JNode.cs"

	public override void Store(VsaEngine engine, Object data1, Object data2, Object value)
#line 149 "./Nodes/JExpr.tc"
	{
		((IVariableAccess)data1).SetVariable(name, value);
	}
#line 3732 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JVarDecl";
	}
}

internal class JTry : JStatement
{
	public new const int KIND = 81;

	public JNode body;
	public String catchName;
	public JNode catchClause;
	public JNode finallyClause;

	public JTry(Context context, JNode body, String catchName, JNode catchClause, JNode finallyClause)
		: base(context)
	{
		this.kind__ = KIND;
		this.body = body;
		this.catchName = catchName;
		this.catchClause = catchClause;
		this.finallyClause = finallyClause;
	}

	public override Object Eval(VsaEngine engine)
#line 516 "./Nodes/JStmt.tc"
	{
		Object result = Empty.Value;
		try
		{
			if(body != null)
			{
				result = body.Eval(engine);
			}
		}
		catch(JScriptException e)	// TODO: other exception types
		{
			if(catchName == null)
			{
				throw;
			}
			if(e.errorNumber == JSError.UncaughtException)
			{
				// Handle an object that was thrown by user JScript code.
				// TODO: push a scope and add "catchName" to it
				try
				{
					catchClause.Eval(engine);
				}
				finally
				{
					// TODO: pop the scope
				}
			}
			else
			{
				// TODO: convert runtime engine errors.
				throw;
			}
		}
		finally
		{
			if(finallyClause != null)
			{
				finallyClause.Eval(engine);
			}
		}
		return result;
	}
#line 3812 "Nodes/JNode.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "JTry";
	}
}

}
