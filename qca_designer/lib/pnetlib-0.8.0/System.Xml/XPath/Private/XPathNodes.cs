/* XPathNodes.cs.  Generated automatically by treecc */

namespace System.Xml.XPath.Private
{

using System;

#line 29 "./XPath/Private/XPathNodes.tc"

using System.IO;
using System.Xml;
using System.Xml.XPath;
using System.Collections;

#if CONFIG_XPATH

#line 18 "XPathNodes.cs"
internal class YYNODESTATE
{

	private static YYNODESTATE state__;

	public static YYNODESTATE getState()
	{
		if(state__ != null) return state__;
		state__ = new YYNODESTATE();
		return state__;
	}

	public YYNODESTATE() { state__ = this; }

	public virtual String currFilename() { return null; }
	public virtual long currLinenum() { return 0; }

}

internal abstract class Expression : XPathExpressionBase
{
	protected int kind__;
	protected String filename__;
	protected long linenum__;

	public int getKind() { return kind__; }
	public String getFilename() { return filename__; }
	public long getLinenum() { return linenum__; }
	public void setFilename(String filename) { filename__ = filename; }
	public void setLinenum(long linenum) { linenum__ = linenum; }

	public const int KIND = 1;

	protected Expression()
	{
		this.kind__ = KIND;
		this.filename__ = YYNODESTATE.getState().currFilename();
		this.linenum__ = YYNODESTATE.getState().currLinenum();
	}

	public abstract XPathResultType Compile();

	public virtual object EvaluateInternal(XPathNodeIterator iterator)
#line 24 "./XPath/Private/XPathEvaluate.tc"
	{
		Expression node = this;
	
		throw new Exception(node.GetType() + " doesn't have an EvaluateInternal");
	}
#line 68 "XPathNodes.cs"

	public virtual int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return 0;
	}

	public virtual String getKindName()
	{
		return "Expression";
	}
}

internal class BinaryExpression : Expression
{
	public new const int KIND = 2;

	public Expression left;
	public Expression right;

	public BinaryExpression(Expression left, Expression right)
		: base()
	{
		this.kind__ = KIND;
		this.left = left;
		this.right = right;
	}

	public override XPathResultType Compile()
#line 31 "./XPath/Private/XPathCompile.tc"
	{
		BinaryExpression node = this;
	
		return XPathResultType.Error;
	}
#line 106 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "BinaryExpression";
	}
}

internal class UnaryExpression : Expression
{
	public new const int KIND = 16;

	public Expression expr;

	public UnaryExpression(Expression expr)
		: base()
	{
		this.kind__ = KIND;
		this.expr = expr;
	}

	public override XPathResultType Compile()
#line 31 "./XPath/Private/XPathCompile.tc"
	{
		UnaryExpression node = this;
	
		return XPathResultType.Error;
	}
#line 142 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "UnaryExpression";
	}
}

internal class PathExpression : Expression
{
	public new const int KIND = 18;

	public PathExpression()
		: base()
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 57 "./XPath/Private/XPathCompile.tc"
	{
		PathExpression node = this;
	
		return XPathResultType.NodeSet;
	}
#line 175 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "PathExpression";
	}
}

internal class FilterExpression : Expression
{
	public new const int KIND = 23;

	public Expression expr;
	public Expression predicate;

	public FilterExpression(Expression expr, Expression predicate)
		: base()
	{
		this.kind__ = KIND;
		this.expr = expr;
		this.predicate = predicate;
	}

	public override XPathResultType Compile()
#line 45 "./XPath/Private/XPathCompile.tc"
	{
		FilterExpression node = this;
	
		return XPathResultType.Boolean;
	}
#line 213 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 160 "./XPath/Private/XPathEvaluate.tc"
	{
		FilterExpression node = this;
	
		XPathBaseIterator left = (XPathBaseIterator)node.expr.Evaluate(iterator);
		return new XPathPredicateIterator(left, node.predicate);
	}
#line 223 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "FilterExpression";
	}
}

internal class NodeTest : Expression
{
	public new const int KIND = 24;

	public XPathAxis axis;
	public XPathNodeType nodeType;
	public XmlQualifiedName name;

	public NodeTest(XPathAxis axis, XPathNodeType nodeType, XmlQualifiedName name)
		: base()
	{
		this.kind__ = KIND;
		this.axis = axis;
		this.nodeType = nodeType;
		this.name = name;
	}

	public override XPathResultType Compile()
#line 57 "./XPath/Private/XPathCompile.tc"
	{
		NodeTest node = this;
	
		return XPathResultType.NodeSet;
	}
#line 263 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 36 "./XPath/Private/XPathEvaluate.tc"
	{
		NodeTest node = this;
	
		// TODO handle various axes
		XPathSimpleIterator axis = null;
		
		switch(node.axis)
		{
			case XPathAxis.Self:
			{
				axis = new XPathSelfIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			case XPathAxis.Child:
			{
				axis = new XPathChildIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			case XPathAxis.Parent:
			{
				axis = new XPathParentIterator(
										(XPathBaseIterator)iterator);
			}
			break;
	
			case XPathAxis.Attribute:
			{
				axis = new XPathAttributeIterator(
										(XPathBaseIterator)iterator);
			}
			break;
	
			case XPathAxis.Ancestor:
			{
				axis = new XPathAncestorIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			case XPathAxis.AncestorOrSelf:
			{
				axis = new XPathAncestorOrSelfIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			case XPathAxis.Descendant:
			{
				axis = new XPathDescendantIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			case XPathAxis.DescendantOrSelf:
			{
				axis = new XPathDescendantOrSelfIterator(
										(XPathBaseIterator)iterator);
			}
			break;
	
			case XPathAxis.Following:
			{
				axis = new XPathFollowingIterator(
										(XPathBaseIterator)iterator);
			}
			break;
	
			case XPathAxis.FollowingSibling:
			{
				axis = new XPathFollowingSiblingIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			case XPathAxis.Preceding:
			{
				axis = new XPathPrecedingIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			case XPathAxis.PrecedingSibling:
			{
				axis = new XPathPrecedingSiblingIterator(
										(XPathBaseIterator)iterator);
			}
			break;
	
			case XPathAxis.Namespace:
			{
				axis = new XPathNamespaceIterator(
										(XPathBaseIterator)iterator);
			}
			break;
			
			default:
			{
				throw new NotImplementedException(node.axis + " is not implemented");
			}
			break;
		}
		
		return new XPathAxisIterator(axis, this);
	}
#line 375 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "NodeTest";
	}
}

internal abstract class ConstantExpression : Expression
{
	public new const int KIND = 25;

	protected ConstantExpression()
		: base()
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
		return "ConstantExpression";
	}
}

internal class ArgumentList : Expression
{
	public new const int KIND = 28;

	public Expression expr;
	public ArgumentList next;

	public ArgumentList(Expression expr)
		: base()
	{
		this.kind__ = KIND;
		this.expr = expr;
		this.next = null;
	}

	public override XPathResultType Compile()
#line 63 "./XPath/Private/XPathCompile.tc"
	{
		ArgumentList node = this;
	
		XPathResultType type = node.expr.Compile();
		for(ArgumentList tmp = node.next; tmp != null ; tmp = tmp.next)
		{
			if(type != node.expr.Compile())
			{
				type = XPathResultType.Any; // mixed args
			}
		}
		return type;
	}
#line 445 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "ArgumentList";
	}
}

internal class FunctionCallExpression : Expression
{
	public new const int KIND = 29;

	public String name;
	public ArgumentList args;
	public int argCount;

	protected FunctionCallExpression(String name, ArgumentList args)
		: base()
	{
		this.kind__ = KIND;
		this.name = name;
		this.args = args;
		this.argCount = 0;
	}

	public override XPathResultType Compile()
#line 76 "./XPath/Private/XPathCompile.tc"
	{
		FunctionCallExpression node = this;
	
		throw new NotImplementedException("XSLT functions are not supported");
	}
#line 485 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 297 "./XPath/Private/XPathEvaluate.tc"
	{
		FunctionCallExpression node = this;
	
		throw new NotImplementedException("XSLT external functions are not implemented yet");
	}
#line 494 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "FunctionCallExpression";
	}
}

internal class UnionExpression : BinaryExpression
{
	public new const int KIND = 3;

	public UnionExpression(Expression left, Expression right)
		: base(left, right)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 57 "./XPath/Private/XPathCompile.tc"
	{
		UnionExpression node = this;
	
		return XPathResultType.NodeSet;
	}
#line 527 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 289 "./XPath/Private/XPathEvaluate.tc"
	{
		UnionExpression node = this;
	
		XPathBaseIterator left = (XPathBaseIterator)node.left.Evaluate(iterator);
		XPathBaseIterator right = (XPathBaseIterator)node.right.Evaluate(iterator);
		return new XPathUnionIterator((XPathBaseIterator)iterator, left, right); 
	}
#line 538 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "UnionExpression";
	}
}

internal class BooleanExpression : BinaryExpression
{
	public new const int KIND = 4;

	public BooleanExpression(Expression left, Expression right)
		: base(left, right)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 45 "./XPath/Private/XPathCompile.tc"
	{
		BooleanExpression node = this;
	
		return XPathResultType.Boolean;
	}
#line 571 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "BooleanExpression";
	}
}

internal class ArithmeticExpression : BinaryExpression
{
	public new const int KIND = 10;

	public ArithmeticExpression(Expression left, Expression right)
		: base(left, right)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 39 "./XPath/Private/XPathCompile.tc"
	{
		ArithmeticExpression node = this;
	
		return XPathResultType.Number;
	}
#line 604 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "ArithmeticExpression";
	}
}

internal class OrExpression : BooleanExpression
{
	public new const int KIND = 5;

	public OrExpression(Expression left, Expression right)
		: base(left, right)
	{
		this.kind__ = KIND;
	}

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 282 "./XPath/Private/XPathEvaluate.tc"
	{
		OrExpression node = this;
	
		return	
		(((bool)node.left.EvaluateAs(iterator, XPathResultType.Boolean) == true) ||
		((bool)node.right.EvaluateAs(iterator, XPathResultType.Boolean) == true));
	}
#line 639 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "OrExpression";
	}
}

internal class AndExpression : BooleanExpression
{
	public new const int KIND = 6;

	public AndExpression(Expression left, Expression right)
		: base(left, right)
	{
		this.kind__ = KIND;
	}

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 275 "./XPath/Private/XPathEvaluate.tc"
	{
		AndExpression node = this;
	
		return	
		(((bool)node.left.EvaluateAs(iterator, XPathResultType.Boolean) == true) && 
		((bool)node.right.EvaluateAs(iterator, XPathResultType.Boolean) == true));
	}
#line 674 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "AndExpression";
	}
}

internal class CompareExpression : BooleanExpression
{
	public new const int KIND = 7;

	public bool invert;

	public CompareExpression(Expression left, Expression right, bool invert)
		: base(left, right)
	{
		this.kind__ = KIND;
		this.invert = invert;
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
		return "CompareExpression";
	}
}

internal class EqualityExpression : CompareExpression
{
	public new const int KIND = 8;

	public EqualityExpression(Expression left, Expression right, bool invert)
		: base(left, right, invert)
	{
		this.kind__ = KIND;
	}

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 176 "./XPath/Private/XPathEvaluate.tc"
	{
		EqualityExpression node = this;
	
		Object lhs = node.left.Evaluate(iterator);
		Object rhs = node.right.Evaluate(iterator);
		
		XPathResultType ltype = node.left.ReturnType;
		XPathResultType rtype = node.right.ReturnType;
		
		// TODO: remove double evaluation of iterators 
		//       implement proper coercion methods or at least some memoization
	
		if(ltype == XPathResultType.NodeSet || rtype == XPathResultType.NodeSet)
		{
			Expression left = node.left;
			Expression right = node.right;
			
			// Flip the order as a == b is the same as b == a
			// TODO: do this while compiling itself , if possible
			if(ltype != XPathResultType.NodeSet)
			{
				left = node.right;
				right = node.left;
				XPathResultType tmp = ltype;
				ltype = rtype;
				rtype = tmp;
			}
			switch(rtype)
			{
				case XPathResultType.Boolean:
				{
					return (node.invert != 
								(left.EvaluateAs(iterator, rtype) == 
									left.EvaluateAs(iterator, rtype)));
				}
				break;
				case XPathResultType.Number:
				{
					XPathNodeIterator iterleft = (XPathNodeIterator)left.Evaluate(iterator);
					double d = (double) right.EvaluateAs(iterator, XPathResultType.Number);
					while(iterleft.MoveNext())
					{
						return node.invert != 
							((Convert.ToDouble(iterleft.Current.Value) == d));
					}
				}
				break;
				case XPathResultType.String:
				{
					XPathNodeIterator iterleft = (XPathNodeIterator)left.Evaluate(iterator);
					String  s = (String)right.EvaluateAs(iterator, XPathResultType.String);
					while(iterleft.MoveNext())
					{
						return(invert != (iterleft.Current.Value == s));
					}
				}
				break;
				case XPathResultType.NodeSet:
				{
				}
				break;
				
			}
		}
		else if( ltype == XPathResultType.Boolean || 
		         rtype == XPathResultType.Boolean)
		{
			bool lbool = (bool)(node.left.EvaluateAs(iterator, 
													XPathResultType.Boolean));
			bool rbool = (bool)(node.right.EvaluateAs(iterator, 
													XPathResultType.Boolean));
			return (node.invert != (lbool == rbool));
		}
		else if( ltype == XPathResultType.Number || 
		         rtype == XPathResultType.Number)
		{
			double ldouble = (double) (node.left.EvaluateAs(
														iterator, 
														XPathResultType.Number));
														
			double rdouble = (double) (node.right.EvaluateAs(
														iterator, 
														XPathResultType.Number));
			return (node.invert != (ldouble == rdouble));
		}
		else if( ltype == XPathResultType.String || 
		         rtype == XPathResultType.String)
		{
			String lstring = (String) (node.left.EvaluateAs(
												iterator, 
												XPathResultType.String));
			String rstring = (String) (node.right.EvaluateAs(
												iterator, 
												XPathResultType.String));
														
			return (node.invert != (lstring == rstring)); 
		}
		return false;
	}
#line 828 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "EqualityExpression";
	}
}

internal class RelationalExpr : CompareExpression
{
	public new const int KIND = 9;

	public RelationalExpr(Expression left, Expression right, bool invert)
		: base(left, right, invert)
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
		return "RelationalExpr";
	}
}

internal class AddExpression : ArithmeticExpression
{
	public new const int KIND = 11;

	public AddExpression(Expression left, Expression right)
		: base(left, right)
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
		return "AddExpression";
	}
}

internal class SubExpression : ArithmeticExpression
{
	public new const int KIND = 12;

	public SubExpression(Expression left, Expression right)
		: base(left, right)
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
		return "SubExpression";
	}
}

internal class MulExpression : ArithmeticExpression
{
	public new const int KIND = 13;

	public MulExpression(Expression left, Expression right)
		: base(left, right)
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
		return "MulExpression";
	}
}

internal class DivExpression : ArithmeticExpression
{
	public new const int KIND = 14;

	public DivExpression(Expression left, Expression right)
		: base(left, right)
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
		return "DivExpression";
	}
}

internal class ModExpression : ArithmeticExpression
{
	public new const int KIND = 15;

	public ModExpression(Expression left, Expression right)
		: base(left, right)
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
		return "ModExpression";
	}
}

internal class NegExpression : UnaryExpression
{
	public new const int KIND = 17;

	public NegExpression(Expression expr)
		: base(expr)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 39 "./XPath/Private/XPathCompile.tc"
	{
		NegExpression node = this;
	
		return XPathResultType.Number;
	}
#line 1005 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "NegExpression";
	}
}

internal class RootPathExpression : PathExpression
{
	public new const int KIND = 19;

	public RootPathExpression()
		: base()
	{
		this.kind__ = KIND;
	}

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 29 "./XPath/Private/XPathEvaluate.tc"
	{
		RootPathExpression node = this;
	
		XPathNavigator nav = iterator.Current.Clone();
		nav.MoveToRoot();
		return new XPathSelfIterator(nav, this.NamespaceManager);
	}
#line 1040 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "RootPathExpression";
	}
}

internal class SlashExpression : PathExpression
{
	public new const int KIND = 20;

	public Expression left;
	public Expression right;

	public SlashExpression(Expression left, Expression right)
		: base()
	{
		this.kind__ = KIND;
		this.left = left;
		this.right = right;
	}

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 144 "./XPath/Private/XPathEvaluate.tc"
	{
		SlashExpression node = this;
	
		XPathBaseIterator lhs = (XPathBaseIterator)node.left.Evaluate(iterator);
		return new XPathSlashIterator(lhs, node.right);
	}
#line 1079 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "SlashExpression";
	}
}

internal class RecursiveDescentPathExpression : PathExpression
{
	public new const int KIND = 21;

	public Expression left;
	public Expression right;

	public RecursiveDescentPathExpression(Expression left, Expression right)
		: base()
	{
		this.kind__ = KIND;
		this.left = left;
		this.right = right;
	}

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 150 "./XPath/Private/XPathEvaluate.tc"
	{
		RecursiveDescentPathExpression node = this;
	
		XPathBaseIterator lhs = (XPathBaseIterator)node.left.Evaluate(iterator);
		NodeTest test = new NodeTest(XPathAxis.DescendantOrSelf, 
									 XPathNodeType.All, null);
		return new XPathSlashIterator(
						new XPathSlashIterator(lhs, test ),
						node.right);
	}
#line 1122 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "RecursiveDescentPathExpression";
	}
}

internal class StepExpression : PathExpression
{
	public new const int KIND = 22;

	public XPathAxis axis;
	public Expression filter;

	public StepExpression(XPathAxis axis, Expression filter)
		: base()
	{
		this.kind__ = KIND;
		this.axis = axis;
		this.filter = filter;
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
		return "StepExpression";
	}
}

internal class LiteralExpression : ConstantExpression
{
	public new const int KIND = 26;

	public String value;

	public LiteralExpression(String value)
		: base()
	{
		this.kind__ = KIND;
		this.value = value;
	}

	public override XPathResultType Compile()
#line 50 "./XPath/Private/XPathCompile.tc"
	{
		LiteralExpression node = this;
	
		return XPathResultType.String;
	}
#line 1187 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 166 "./XPath/Private/XPathEvaluate.tc"
	{
		LiteralExpression node = this;
	
		return node.value; 
	}
#line 1196 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "LiteralExpression";
	}
}

internal class NumberExpression : ConstantExpression
{
	public new const int KIND = 27;

	public Double number;

	public NumberExpression(Double number)
		: base()
	{
		this.kind__ = KIND;
		this.number = number;
	}

	public override XPathResultType Compile()
#line 39 "./XPath/Private/XPathCompile.tc"
	{
		NumberExpression node = this;
	
		return XPathResultType.Number;
	}
#line 1232 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 171 "./XPath/Private/XPathEvaluate.tc"
	{
		NumberExpression node = this;
	
		return node.number; 
	}
#line 1241 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "NumberExpression";
	}
}

internal class XPathBuiltinFunction : FunctionCallExpression
{
	public new const int KIND = 30;

	protected XPathBuiltinFunction(String name, ArgumentList args)
		: base(name, args)
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
		return "XPathBuiltinFunction";
	}
}

internal class XPathExternalFunction : FunctionCallExpression
{
	public new const int KIND = 58;

	public XPathExternalFunction(String name, ArgumentList args)
		: base(name, args)
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
		return "XPathExternalFunction";
	}
}

internal class XPathCountFunction : XPathBuiltinFunction
{
	public new const int KIND = 31;

	public XPathCountFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 82 "./XPath/Private/XPathCompile.tc"
	{
		XPathCountFunction node = this;
	
		return XPathResultType.Number;
	}
#line 1322 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 303 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathCountFunction node = this;
	
		XPathNodeIterator argIter = (XPathNodeIterator)node.args.expr.EvaluateAs(
													iterator, 
													XPathResultType.NodeSet);
		
		if(argIter != null)
		{
			return (double) argIter.Count;
		}
		
		return 0.0;
	}
#line 1340 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathCountFunction";
	}
}

internal class XPathIdFunction : XPathBuiltinFunction
{
	public new const int KIND = 32;

	public XPathIdFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 87 "./XPath/Private/XPathCompile.tc"
	{
		XPathIdFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 1373 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 316 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathIdFunction node = this;
	
		return null; /* TODO */
	}
#line 1382 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathIdFunction";
	}
}

internal class XPathLastFunction : XPathBuiltinFunction
{
	public new const int KIND = 33;

	public XPathLastFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 92 "./XPath/Private/XPathCompile.tc"
	{
		XPathLastFunction node = this;
	
		return XPathResultType.Number;
	}
#line 1415 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 320 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathLastFunction node = this;
	
		return (double)iterator.Count;
	}
#line 1424 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathLastFunction";
	}
}

internal class XPathLocalNameFunction : XPathBuiltinFunction
{
	public new const int KIND = 34;

	public XPathLocalNameFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 97 "./XPath/Private/XPathCompile.tc"
	{
		XPathLocalNameFunction node = this;
	
		return XPathResultType.String;
	}
#line 1457 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 324 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathLocalNameFunction node = this;
	
		if(node.args == null)
		{
			return iterator.Current.LocalName;
		}
	
		XPathNodeIterator argIter = (XPathNodeIterator)node.args.expr.EvaluateAs(
													iterator, 
													XPathResultType.NodeSet);
		
		if(argIter != null && argIter.MoveNext())
		{
			return argIter.Current.LocalName; 
		}
	
		return String.Empty;
	}
#line 1480 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathLocalNameFunction";
	}
}

internal class XPathNameFunction : XPathBuiltinFunction
{
	public new const int KIND = 35;

	public XPathNameFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 102 "./XPath/Private/XPathCompile.tc"
	{
		XPathNameFunction node = this;
	
		return XPathResultType.String;
	}
#line 1513 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 343 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathNameFunction node = this;
	
		if(node.args == null)
		{
			return iterator.Current.Name;
		}
	
		XPathNodeIterator argIter = (XPathNodeIterator)node.args.expr.EvaluateAs(
													iterator, 
													XPathResultType.NodeSet);
		
		if(argIter != null && argIter.MoveNext())
		{
			return argIter.Current.Name; 
		}
	
		return String.Empty;
	}
#line 1536 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathNameFunction";
	}
}

internal class XPathNamespaceUriFunction : XPathBuiltinFunction
{
	public new const int KIND = 36;

	public XPathNamespaceUriFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 106 "./XPath/Private/XPathCompile.tc"
	{
		XPathNamespaceUriFunction node = this;
	
		return XPathResultType.String;
	}
#line 1569 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 362 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathNamespaceUriFunction node = this;
	
		return null; /* TODO */
	}
#line 1578 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathNamespaceUriFunction";
	}
}

internal class XPathPositionFunction : XPathBuiltinFunction
{
	public new const int KIND = 37;

	public XPathPositionFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 111 "./XPath/Private/XPathCompile.tc"
	{
		XPathPositionFunction node = this;
	
		return XPathResultType.Number; /* TODO */
	}
#line 1611 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 366 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathPositionFunction node = this;
	
		return (double)iterator.CurrentPosition;
	}
#line 1620 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathPositionFunction";
	}
}

internal class XPathBooleanFunction : XPathBuiltinFunction
{
	public new const int KIND = 38;

	public XPathBooleanFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 117 "./XPath/Private/XPathCompile.tc"
	{
		XPathBooleanFunction node = this;
	
		return XPathResultType.Boolean;
	}
#line 1653 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 372 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathBooleanFunction node = this;
	
		return null; /* TODO */
	}
#line 1662 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathBooleanFunction";
	}
}

internal class XPathTrueFunction : XPathBuiltinFunction
{
	public new const int KIND = 39;

	public XPathTrueFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 121 "./XPath/Private/XPathCompile.tc"
	{
		XPathTrueFunction node = this;
	
		return XPathResultType.Boolean; 
	}
#line 1695 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 376 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathTrueFunction node = this;
	
		return true; /* TODO */
	}
#line 1704 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathTrueFunction";
	}
}

internal class XPathFalseFunction : XPathBuiltinFunction
{
	public new const int KIND = 40;

	public XPathFalseFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 125 "./XPath/Private/XPathCompile.tc"
	{
		XPathFalseFunction node = this;
	
		return XPathResultType.Boolean;
	}
#line 1737 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 380 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathFalseFunction node = this;
	
		return false; /* TODO */
	}
#line 1746 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathFalseFunction";
	}
}

internal class XPathLangFunction : XPathBuiltinFunction
{
	public new const int KIND = 41;

	public XPathLangFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 130 "./XPath/Private/XPathCompile.tc"
	{
		XPathLangFunction node = this;
	
		return XPathResultType.Boolean; /* TODO */
	}
#line 1779 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 384 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathLangFunction node = this;
	
		return null; /* TODO */
	}
#line 1788 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathLangFunction";
	}
}

internal class XPathNotFunction : XPathBuiltinFunction
{
	public new const int KIND = 42;

	public XPathNotFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 134 "./XPath/Private/XPathCompile.tc"
	{
		XPathNotFunction node = this;
	
		return XPathResultType.Boolean; 
	}
#line 1821 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 388 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathNotFunction node = this;
	
		bool value = (bool)node.args.expr.EvaluateAs(iterator, 
													 XPathResultType.Boolean);
		return !(value); /* TODO */
	}
#line 1832 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathNotFunction";
	}
}

internal class XPathCeilingFunction : XPathBuiltinFunction
{
	public new const int KIND = 43;

	public XPathCeilingFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 141 "./XPath/Private/XPathCompile.tc"
	{
		XPathCeilingFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 1865 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 397 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathCeilingFunction node = this;
	
		return null; /* TODO */
	}
#line 1874 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathCeilingFunction";
	}
}

internal class XPathFloorFunction : XPathBuiltinFunction
{
	public new const int KIND = 44;

	public XPathFloorFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 145 "./XPath/Private/XPathCompile.tc"
	{
		XPathFloorFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 1907 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 401 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathFloorFunction node = this;
	
		return null; /* TODO */
	}
#line 1916 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathFloorFunction";
	}
}

internal class XPathNumberFunction : XPathBuiltinFunction
{
	public new const int KIND = 45;

	public XPathNumberFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 149 "./XPath/Private/XPathCompile.tc"
	{
		XPathNumberFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 1949 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 405 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathNumberFunction node = this;
	
		return null; /* TODO */
	}
#line 1958 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathNumberFunction";
	}
}

internal class XPathRoundFunction : XPathBuiltinFunction
{
	public new const int KIND = 46;

	public XPathRoundFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 153 "./XPath/Private/XPathCompile.tc"
	{
		XPathRoundFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 1991 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 409 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathRoundFunction node = this;
	
		return null; /* TODO */
	}
#line 2000 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathRoundFunction";
	}
}

internal class XPathSumFunction : XPathBuiltinFunction
{
	public new const int KIND = 47;

	public XPathSumFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 157 "./XPath/Private/XPathCompile.tc"
	{
		XPathSumFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2033 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 413 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathSumFunction node = this;
	
		return null; /* TODO */
	}
#line 2042 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathSumFunction";
	}
}

internal class XPathConcatFunction : XPathBuiltinFunction
{
	public new const int KIND = 48;

	public XPathConcatFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 163 "./XPath/Private/XPathCompile.tc"
	{
		XPathConcatFunction node = this;
	
		return XPathResultType.String; /* TODO */
	}
#line 2075 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 419 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathConcatFunction node = this;
	
		String [] parts = new String[node.argCount];
		
		ArgumentList args = node.args;
		
		for(int i = 0; i < parts.Length ; i++)
		{
			parts[i] = (String) (args.expr.EvaluateAs(iterator,
														XPathResultType.String));
			args = args.next;
		}
	
		return String.Concat(parts);
	}
#line 2095 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathConcatFunction";
	}
}

internal class XPathContainsFunction : XPathBuiltinFunction
{
	public new const int KIND = 49;

	public XPathContainsFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 167 "./XPath/Private/XPathCompile.tc"
	{
		XPathContainsFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2128 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 434 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathContainsFunction node = this;
	
		return null; /* TODO */
	}
#line 2137 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathContainsFunction";
	}
}

internal class XPathNormalizeFunction : XPathBuiltinFunction
{
	public new const int KIND = 50;

	public XPathNormalizeFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 171 "./XPath/Private/XPathCompile.tc"
	{
		XPathNormalizeFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2170 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 438 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathNormalizeFunction node = this;
	
		return null; /* TODO */
	}
#line 2179 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathNormalizeFunction";
	}
}

internal class XPathStartsWithFunction : XPathBuiltinFunction
{
	public new const int KIND = 51;

	public XPathStartsWithFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 175 "./XPath/Private/XPathCompile.tc"
	{
		XPathStartsWithFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2212 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 442 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathStartsWithFunction node = this;
	
		return null; /* TODO */
	}
#line 2221 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathStartsWithFunction";
	}
}

internal class XPathStringFunction : XPathBuiltinFunction
{
	public new const int KIND = 52;

	public XPathStringFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 179 "./XPath/Private/XPathCompile.tc"
	{
		XPathStringFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2254 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 446 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathStringFunction node = this;
	
		String retval = (String) (args.expr.EvaluateAs(iterator,
												XPathResultType.String));
		return (retval == null) ? String.Empty : retval;
	}
#line 2265 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathStringFunction";
	}
}

internal class XPathStringLengthFunction : XPathBuiltinFunction
{
	public new const int KIND = 53;

	public XPathStringLengthFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 183 "./XPath/Private/XPathCompile.tc"
	{
		XPathStringLengthFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2298 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 452 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathStringLengthFunction node = this;
	
		String retval = (String) (args.expr.EvaluateAs(iterator,
												XPathResultType.String));
	
		return (double) ((retval == null) ? 0 : retval.Length);
	}
#line 2310 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathStringLengthFunction";
	}
}

internal class XPathSubstringFunction : XPathBuiltinFunction
{
	public new const int KIND = 54;

	public XPathSubstringFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 187 "./XPath/Private/XPathCompile.tc"
	{
		XPathSubstringFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2343 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 459 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathSubstringFunction node = this;
	
		return null; /* TODO */
	}
#line 2352 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathSubstringFunction";
	}
}

internal class XPathSubstringAfterFunction : XPathBuiltinFunction
{
	public new const int KIND = 55;

	public XPathSubstringAfterFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 191 "./XPath/Private/XPathCompile.tc"
	{
		XPathSubstringAfterFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2385 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 463 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathSubstringAfterFunction node = this;
	
		return null; /* TODO */
	}
#line 2394 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathSubstringAfterFunction";
	}
}

internal class XPathSubstringBeforeFunction : XPathBuiltinFunction
{
	public new const int KIND = 56;

	public XPathSubstringBeforeFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 195 "./XPath/Private/XPathCompile.tc"
	{
		XPathSubstringBeforeFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2427 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 467 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathSubstringBeforeFunction node = this;
	
		return null; /* TODO */
	}
#line 2436 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathSubstringBeforeFunction";
	}
}

internal class XPathTranslateFunction : XPathBuiltinFunction
{
	public new const int KIND = 57;

	public XPathTranslateFunction(String name, ArgumentList args)
		: base(name, args)
	{
		this.kind__ = KIND;
	}

	public override XPathResultType Compile()
#line 199 "./XPath/Private/XPathCompile.tc"
	{
		XPathTranslateFunction node = this;
	
		return XPathResultType.Any; /* TODO */
	}
#line 2469 "XPathNodes.cs"

	public override object EvaluateInternal(XPathNodeIterator iterator)
#line 471 "./XPath/Private/XPathEvaluate.tc"
	{
		XPathTranslateFunction node = this;
	
		return null; /* TODO */
	}
#line 2478 "XPathNodes.cs"

	public override int isA(int kind)
	{
		if(kind == KIND)
			return 1;
		else
			return base.isA(kind);
	}

	public override String getKindName()
	{
		return "XPathTranslateFunction";
	}
}

#line 223 "./XPath/Private/XPathNodes.tc"

#endif /* CONFIG_XPATH */
#line 2497 "XPathNodes.cs"
}
