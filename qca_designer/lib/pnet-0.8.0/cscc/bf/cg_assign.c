/* cg_assign.c.  Generated automatically by treecc */
#line 3 "cg_assign.tc"

/*
 * cg_assign.tc - Assignment operator nodes.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
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

#include <codegen/cg_nodes.h>
#line 99 "cg_assign.tc"


/*
 *  Common generation code for ILNode_AssignExpression
 */
static ILMachineType AssignCommon(ILNode_AssignExpression *node, 
								  ILGenInfo *info,
						          int leave)
{
	ILMachineType finalType;
	void *data1, *data2;
	ILNode_BinaryExpression *bnode = (ILNode_BinaryExpression *)(node->assign);

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->lvalue, info, 0, &data1, &data2);

	/* Perform the operation */
	if(yyisa(bnode, ILNode_Concat))
	{
		if(finalType == ILMachineType_String &&
		   ILNode_GetType(bnode->expr2, info) == ILMachineType_String)
		{
			ILGenCast(info, ILNode_GenValue(bnode->expr2, info),
					  ILMachineType_String);
			ILGenCallByName(info,
			  "class [.library]System.String [.library]System.String::Concat"
					"(class [.library]System.String, "
					 "class [.library]System.String)");
			ILGenAdjust(info, -1);
		}
		else
		{
			ILGenCast(info, ILNode_GenValue(bnode->expr2, info),
					  ILMachineType_ObjectRef);
			ILGenCallByName(info,
			  "class [.library]System.String [.library]System.String::Concat"
					"(class [.library]System.Object, "
					 "class [.library]System.Object)");
			ILGenAdjust(info, -1);
		}
		ILGenCast(info, ILMachineType_String, finalType);
	}
	else if(yyisa(bnode, ILNode_DelegateAdd))
	{
		ILGenCast(info, ILNode_GenValue(bnode->expr2, info),
				  ILMachineType_ObjectRef);
		ILGenCallByName(info,
		  "class [.library]System.Delegate [.library]System.Delegate::Combine"
				"(class [.library]System.Delegate, "
				 "class [.library]System.Delegate)");
		ILGenAdjust(info, -1);
		ILGenClassToken(info, IL_OP_CASTCLASS,
				((ILNode_DelegateAdd *)bnode)->delegateClass);
		ILGenCast(info, ILMachineType_ObjectRef, finalType);
	}
	else if(yyisa(bnode, ILNode_DelegateSub))
	{
		ILGenCast(info, ILNode_GenValue(bnode->expr2, info),
				  ILMachineType_ObjectRef);
		ILGenCallByName(info,
		  "class [.library]System.Delegate [.library]System.Delegate::Remove"
				"(class [.library]System.Delegate, "
				 "class [.library]System.Delegate)");
		ILGenAdjust(info, -1);
		ILGenClassToken(info, IL_OP_CASTCLASS,
				((ILNode_DelegateSub *)bnode)->delegateClass);
		ILGenCast(info, ILMachineType_ObjectRef, finalType);
	}
	else
	{
		/* Evaluate the second sub-expression and cast to the final type */
		ILGenCast(info, ILNode_GenValue(node->assign, info), finalType);
	}

	/* Store the value into the destination */
	ILNode_Store(node->lvalue, info, leave, data1, data2);
	return finalType;
}

#line 59 "jv_assign.tc"


/*
 * Concatenation two string values on the stack.  We assume that
 * the first will be a string, but the second may need conversion.
 */
static void ConcatString(ILGenInfo *info, ILMachineType type1,
						 ILMachineType type2)
{
	/* Convert the second argument into a string if necessary */
	if(type2 >= ILMachineType_Boolean &&
	   type2 <= ILMachineType_Decimal)
	{
		JavaGenCast(info, type2, ILMachineType_String);
		type2 = ILMachineType_String;
	}
	else if(type2 != ILMachineType_String)
	{
		JavaGenCast(info, type2, ILMachineType_ObjectRef);
		if(info->useJavaLib)
		{
			JavaGenCallVirtual(info, "java/lang/Object", "toString",
							   "()Ljava/lang/String;");
			type2 = ILMachineType_String;
		}
	}

	/* Apply either the string or the object concatenation function */
	if(type1 == ILMachineType_String && type2 == ILMachineType_String)
	{
		if(info->useJavaLib)
		{
			JavaGenCallVirtual(info, "java/lang/String", "concat",
							   "(Ljava/lang/String;)Ljava/lang/String;");
		}
		else
		{
			JavaGenCallByName(info, "System/String", "Concat",
					  "(LSystem/String;LSystem/String;)LSystem/String;");
		}
	}
	else
	{
		JavaGenCallByName(info, "System/String", "Concat",
				  "(LSystem/Object;LSystem/Object;)LSystem/String;");
	}
	JavaGenAdjust(info, -1);
}

/*
 * Common generation code for ILNode_AssignExpression
 */
static ILMachineType JavaAssignCommon(ILNode_AssignExpression *node, 
								      ILGenInfo *info,
						              int leave)
{
	ILMachineType finalType;
	void *data1, *data2;
	ILNode_BinaryExpression *bnode = (ILNode_BinaryExpression *)(node->assign);

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->lvalue, info, 0, &data1, &data2);

	/* Perform the operation */
	if(yyisa(bnode, ILNode_Concat))
	{
		if(finalType == ILMachineType_String &&
		   ILNode_GetType(bnode->expr2, info) == ILMachineType_String)
		{
			JavaGenCast(info, JavaGenValue(bnode->expr2, info),
					    ILMachineType_String);
		    ConcatString(info, finalType, finalType);
		}
		else
		{
			JavaGenCast(info, JavaGenValue(bnode->expr2, info),
					    ILMachineType_ObjectRef);
		    ConcatString(info, finalType, ILMachineType_ObjectRef);
		}
	}
	else if(yyisa(bnode, ILNode_DelegateAdd))
	{
		JavaGenCast(info, JavaGenValue(bnode->expr2, info),
				  ILMachineType_ObjectRef);
		JavaGenCallByName(info, "System/Delegate", "Combine",
				  "(LSystem/Delegate;LSystem/Delegate;)LSystem/Delegate;");
		JavaGenAdjust(info, -1);
		JavaGenClassRef(info, JAVA_OP_CHECKCAST,
				((ILNode_DelegateAdd *)bnode)->delegateClass);
	}
	else if(yyisa(bnode, ILNode_DelegateSub))
	{
		JavaGenCast(info, JavaGenValue(bnode->expr2, info),
				  ILMachineType_ObjectRef);
		JavaGenCallByName(info, "System/Delegate", "Remove",
				  "(LSystem/Delegate;LSystem/Delegate;)LSystem/Delegate;");
		JavaGenAdjust(info, -1);
		JavaGenClassRef(info, JAVA_OP_CHECKCAST,
				((ILNode_DelegateSub *)bnode)->delegateClass);
	}
	else
	{
		/* Evaluate the second sub-expression and cast to the final type */
		JavaGenCast(info, JavaGenValue(node->assign, info), finalType);
	}

	/* Store the value into the destination */
	JavaStore(node->lvalue, info, leave, data1, data2);
	return finalType;
}


#line 219 "cg_assign.c"

ILMachineType ILNode_AssignExpression_ILNode_GetType__(ILNode_AssignExpression *node, ILGenInfo * info)
#line 51 "cg_assign.tc"
{
	return ILNode_GetType(node->lvalue,info);
}
#line 226 "cg_assign.c"

void ILNode_AssignExpression_ILNode_GenDiscard__(ILNode_AssignExpression *node, ILGenInfo * info)
#line 184 "cg_assign.tc"
{
	AssignCommon(node, info, 0);
}
#line 233 "cg_assign.c"

ILMachineType ILNode_AssignExpression_ILNode_GenValue__(ILNode_AssignExpression *node, ILGenInfo * info)
#line 213 "cg_assign.tc"
{
	return AssignCommon(node, info, 1);
}
#line 240 "cg_assign.c"

void ILNode_AssignExpression_JavaGenDiscard__(ILNode_AssignExpression *node, ILGenInfo * info)
#line 177 "jv_assign.tc"
{
	JavaAssignCommon(node, info, 0);
}
#line 247 "cg_assign.c"

ILMachineType ILNode_AssignExpression_JavaGenValue__(ILNode_AssignExpression *node, ILGenInfo * info)
#line 206 "jv_assign.tc"
{
	return JavaAssignCommon(node, info, 1);
}
#line 254 "cg_assign.c"

struct ILNode_AssignExpression_vtable__ const ILNode_AssignExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_AssignExpression_kind,
	"ILNode_AssignExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PreInc_ILNode_GetType__(ILNode_PreInc *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 278 "cg_assign.c"

void ILNode_PreInc_ILNode_GenDiscard__(ILNode_PreInc *node, ILGenInfo * info)
#line 222 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	ILIncrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 306 "cg_assign.c"

ILMachineType ILNode_PreInc_ILNode_GenValue__(ILNode_PreInc *node, ILGenInfo * info)
#line 359 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	ILIncrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 337 "cg_assign.c"

void ILNode_PreInc_JavaGenDiscard__(ILNode_PreInc *node, ILGenInfo * info)
#line 215 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	JavaInc_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 365 "cg_assign.c"

ILMachineType ILNode_PreInc_JavaGenValue__(ILNode_PreInc *node, ILGenInfo * info)
#line 294 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	JavaInc_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 396 "cg_assign.c"

struct ILNode_PreInc_vtable__ const ILNode_PreInc_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_PreInc_kind,
	"ILNode_PreInc",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreInc_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PreInc_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreInc_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PreInc_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreInc_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PreDec_ILNode_GetType__(ILNode_PreDec *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 420 "cg_assign.c"

void ILNode_PreDec_ILNode_GenDiscard__(ILNode_PreDec *node, ILGenInfo * info)
#line 252 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Decrement the value on the top of the stack */
	ILDecrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 448 "cg_assign.c"

ILMachineType ILNode_PreDec_ILNode_GenValue__(ILNode_PreDec *node, ILGenInfo * info)
#line 423 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	ILDecrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 479 "cg_assign.c"

void ILNode_PreDec_JavaGenDiscard__(ILNode_PreDec *node, ILGenInfo * info)
#line 245 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Decrement the value on the top of the stack */
	JavaDec_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 507 "cg_assign.c"

ILMachineType ILNode_PreDec_JavaGenValue__(ILNode_PreDec *node, ILGenInfo * info)
#line 358 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	JavaDec_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 538 "cg_assign.c"

struct ILNode_PreDec_vtable__ const ILNode_PreDec_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_PreDec_kind,
	"ILNode_PreDec",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDec_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDec_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDec_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDec_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDec_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PostInc_ILNode_GetType__(ILNode_PostInc *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 562 "cg_assign.c"

void ILNode_PostInc_ILNode_GenDiscard__(ILNode_PostInc *node, ILGenInfo * info)
#line 222 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	ILIncrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 590 "cg_assign.c"

ILMachineType ILNode_PostInc_ILNode_GenValue__(ILNode_PostInc *node, ILGenInfo * info)
#line 391 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	ILIncrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 621 "cg_assign.c"

void ILNode_PostInc_JavaGenDiscard__(ILNode_PostInc *node, ILGenInfo * info)
#line 215 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	JavaInc_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 649 "cg_assign.c"

ILMachineType ILNode_PostInc_JavaGenValue__(ILNode_PostInc *node, ILGenInfo * info)
#line 326 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be added */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	JavaInc_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 680 "cg_assign.c"

struct ILNode_PostInc_vtable__ const ILNode_PostInc_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_PostInc_kind,
	"ILNode_PostInc",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostInc_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PostInc_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostInc_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PostInc_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostInc_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PostDec_ILNode_GetType__(ILNode_PostDec *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 704 "cg_assign.c"

void ILNode_PostDec_ILNode_GenDiscard__(ILNode_PostDec *node, ILGenInfo * info)
#line 252 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Decrement the value on the top of the stack */
	ILDecrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 732 "cg_assign.c"

ILMachineType ILNode_PostDec_ILNode_GenValue__(ILNode_PostDec *node, ILGenInfo * info)
#line 455 "cg_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = ILNode_GetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	ILGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	ILDecrement_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	ILGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 763 "cg_assign.c"

void ILNode_PostDec_JavaGenDiscard__(ILNode_PostDec *node, ILGenInfo * info)
#line 245 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Decrement the value on the top of the stack */
	JavaDec_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 791 "cg_assign.c"

ILMachineType ILNode_PostDec_JavaGenValue__(ILNode_PostDec *node, ILGenInfo * info)
#line 390 "jv_assign.tc"
{
	ILMachineType finalType;
	ILMachineType commonType;
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	finalType = JavaGetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Determine the common type for the operation.  We use
	   "int8" as the type of the "1" constant to be subtracted */
	commonType = ILCommonType(info, finalType, ILMachineType_Int8, 0);

	/* Cast the first sub-expression to the common type */
	JavaGenCast(info, finalType, commonType);

	/* Increment the value on the top of the stack */
	JavaDec_ApplyOp(info, commonType);

	/* Convert the common type back into the final type */
	JavaGenCast(info, commonType, finalType);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 822 "cg_assign.c"

struct ILNode_PostDec_vtable__ const ILNode_PostDec_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_PostDec_kind,
	"ILNode_PostDec",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDec_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDec_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDec_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDec_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDec_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_UserIncOrDec_vtable__ const ILNode_UserIncOrDec_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_UserIncOrDec_kind,
	"ILNode_UserIncOrDec",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_IncOrDecPtr_vtable__ const ILNode_IncOrDecPtr_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_IncOrDecPtr_kind,
	"ILNode_IncOrDecPtr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserPreInc_ILNode_GetType__(ILNode_UserPreInc *node, ILGenInfo * info)
#line 77 "cg_assign.tc"
{
	return node->type;
}
#line 880 "cg_assign.c"

void ILNode_UserPreInc_ILNode_GenDiscard__(ILNode_UserPreInc *node, ILGenInfo * info)
#line 284 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 896 "cg_assign.c"

ILMachineType ILNode_UserPreInc_ILNode_GenValue__(ILNode_UserPreInc *node, ILGenInfo * info)
#line 488 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 915 "cg_assign.c"

void ILNode_UserPreInc_JavaGenDiscard__(ILNode_UserPreInc *node, ILGenInfo * info)
#line 277 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 931 "cg_assign.c"

ILMachineType ILNode_UserPreInc_JavaGenValue__(ILNode_UserPreInc *node, ILGenInfo * info)
#line 423 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 950 "cg_assign.c"

struct ILNode_UserPreInc_vtable__ const ILNode_UserPreInc_vt__ = {
	&ILNode_UserIncOrDec_vt__,
	ILNode_UserPreInc_kind,
	"ILNode_UserPreInc",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreInc_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreInc_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreInc_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreInc_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreInc_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserPreDec_ILNode_GetType__(ILNode_UserPreDec *node, ILGenInfo * info)
#line 77 "cg_assign.tc"
{
	return node->type;
}
#line 974 "cg_assign.c"

void ILNode_UserPreDec_ILNode_GenDiscard__(ILNode_UserPreDec *node, ILGenInfo * info)
#line 284 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 990 "cg_assign.c"

ILMachineType ILNode_UserPreDec_ILNode_GenValue__(ILNode_UserPreDec *node, ILGenInfo * info)
#line 488 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 1009 "cg_assign.c"

void ILNode_UserPreDec_JavaGenDiscard__(ILNode_UserPreDec *node, ILGenInfo * info)
#line 277 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 1025 "cg_assign.c"

ILMachineType ILNode_UserPreDec_JavaGenValue__(ILNode_UserPreDec *node, ILGenInfo * info)
#line 423 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 1044 "cg_assign.c"

struct ILNode_UserPreDec_vtable__ const ILNode_UserPreDec_vt__ = {
	&ILNode_UserIncOrDec_vt__,
	ILNode_UserPreDec_kind,
	"ILNode_UserPreDec",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreDec_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreDec_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreDec_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreDec_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPreDec_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserPostInc_ILNode_GetType__(ILNode_UserPostInc *node, ILGenInfo * info)
#line 77 "cg_assign.tc"
{
	return node->type;
}
#line 1068 "cg_assign.c"

void ILNode_UserPostInc_ILNode_GenDiscard__(ILNode_UserPostInc *node, ILGenInfo * info)
#line 284 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 1084 "cg_assign.c"

ILMachineType ILNode_UserPostInc_ILNode_GenValue__(ILNode_UserPostInc *node, ILGenInfo * info)
#line 509 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 1103 "cg_assign.c"

void ILNode_UserPostInc_JavaGenDiscard__(ILNode_UserPostInc *node, ILGenInfo * info)
#line 277 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 1119 "cg_assign.c"

ILMachineType ILNode_UserPostInc_JavaGenValue__(ILNode_UserPostInc *node, ILGenInfo * info)
#line 444 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 1138 "cg_assign.c"

struct ILNode_UserPostInc_vtable__ const ILNode_UserPostInc_vt__ = {
	&ILNode_UserIncOrDec_vt__,
	ILNode_UserPostInc_kind,
	"ILNode_UserPostInc",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostInc_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostInc_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostInc_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostInc_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostInc_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserPostDec_ILNode_GetType__(ILNode_UserPostDec *node, ILGenInfo * info)
#line 77 "cg_assign.tc"
{
	return node->type;
}
#line 1162 "cg_assign.c"

void ILNode_UserPostDec_ILNode_GenDiscard__(ILNode_UserPostDec *node, ILGenInfo * info)
#line 284 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 1178 "cg_assign.c"

ILMachineType ILNode_UserPostDec_ILNode_GenValue__(ILNode_UserPostDec *node, ILGenInfo * info)
#line 509 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	ILGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 1197 "cg_assign.c"

void ILNode_UserPostDec_JavaGenDiscard__(ILNode_UserPostDec *node, ILGenInfo * info)
#line 277 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);
}
#line 1213 "cg_assign.c"

ILMachineType ILNode_UserPostDec_JavaGenValue__(ILNode_UserPostDec *node, ILGenInfo * info)
#line 444 "jv_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	JavaGetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Increment or decrement the value on the top of the stack */
	JavaGenCallByMethod(info, node->method);

	/* Store the value into the destination */
	JavaStore(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return node->type;
}
#line 1232 "cg_assign.c"

struct ILNode_UserPostDec_vtable__ const ILNode_UserPostDec_vt__ = {
	&ILNode_UserIncOrDec_vt__,
	ILNode_UserPostDec_kind,
	"ILNode_UserPostDec",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostDec_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostDec_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostDec_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostDec_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserPostDec_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PreIncPtr_ILNode_GetType__(ILNode_PreIncPtr *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 1256 "cg_assign.c"

void ILNode_PreIncPtr_ILNode_GenDiscard__(ILNode_PreIncPtr *node, ILGenInfo * info)
#line 302 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else if(node->sizeNode)
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_ADD);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 1283 "cg_assign.c"

ILMachineType ILNode_PreIncPtr_ILNode_GenValue__(ILNode_PreIncPtr *node, ILGenInfo * info)
#line 529 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else if(node->sizeNode)
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_ADD);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return ILMachineType_UnmanagedPtr;
}
#line 1313 "cg_assign.c"

ILMachineType ILNode_PreIncPtr_JavaGenValue__(ILNode_PreIncPtr *node, ILGenInfo * info)
#line 468 "jv_assign.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 1320 "cg_assign.c"

struct ILNode_PreIncPtr_vtable__ const ILNode_PreIncPtr_vt__ = {
	&ILNode_IncOrDecPtr_vt__,
	ILNode_PreIncPtr_kind,
	"ILNode_PreIncPtr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreIncPtr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PreIncPtr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreIncPtr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreIncPtr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PreDecPtr_ILNode_GetType__(ILNode_PreDecPtr *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 1344 "cg_assign.c"

void ILNode_PreDecPtr_ILNode_GenDiscard__(ILNode_PreDecPtr *node, ILGenInfo * info)
#line 331 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else if(node->sizeNode)
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_SUB);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 1371 "cg_assign.c"

ILMachineType ILNode_PreDecPtr_ILNode_GenValue__(ILNode_PreDecPtr *node, ILGenInfo * info)
#line 591 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else if(node->sizeNode)
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_SUB);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 1, data1, data2);

	/* Return the final type to the caller */
	return ILMachineType_UnmanagedPtr;
}
#line 1401 "cg_assign.c"

ILMachineType ILNode_PreDecPtr_JavaGenValue__(ILNode_PreDecPtr *node, ILGenInfo * info)
#line 468 "jv_assign.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 1408 "cg_assign.c"

struct ILNode_PreDecPtr_vtable__ const ILNode_PreDecPtr_vt__ = {
	&ILNode_IncOrDecPtr_vt__,
	ILNode_PreDecPtr_kind,
	"ILNode_PreDecPtr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDecPtr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDecPtr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDecPtr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PreDecPtr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PostIncPtr_ILNode_GetType__(ILNode_PostIncPtr *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 1432 "cg_assign.c"

void ILNode_PostIncPtr_ILNode_GenDiscard__(ILNode_PostIncPtr *node, ILGenInfo * info)
#line 302 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else if(node->sizeNode)
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_ADD);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 1459 "cg_assign.c"

ILMachineType ILNode_PostIncPtr_ILNode_GenValue__(ILNode_PostIncPtr *node, ILGenInfo * info)
#line 560 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else if(node->sizeNode)
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_ADD);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return ILMachineType_UnmanagedPtr;
}
#line 1489 "cg_assign.c"

ILMachineType ILNode_PostIncPtr_JavaGenValue__(ILNode_PostIncPtr *node, ILGenInfo * info)
#line 468 "jv_assign.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 1496 "cg_assign.c"

struct ILNode_PostIncPtr_vtable__ const ILNode_PostIncPtr_vt__ = {
	&ILNode_IncOrDecPtr_vt__,
	ILNode_PostIncPtr_kind,
	"ILNode_PostIncPtr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostIncPtr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PostIncPtr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostIncPtr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostIncPtr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_PostDecPtr_ILNode_GetType__(ILNode_PostDecPtr *node, ILGenInfo * info)
#line 66 "cg_assign.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 1520 "cg_assign.c"

void ILNode_PostDecPtr_ILNode_GenDiscard__(ILNode_PostDecPtr *node, ILGenInfo * info)
#line 331 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 0, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else if(node->sizeNode)
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_SUB);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);
}
#line 1547 "cg_assign.c"

ILMachineType ILNode_PostDecPtr_ILNode_GenValue__(ILNode_PostDecPtr *node, ILGenInfo * info)
#line 622 "cg_assign.tc"
{
	void *data1, *data2;

	/* Get and prepare the l-value for a later store operation */
	ILNode_GetAndPrepare(node->expr, info, 1, &data1, &data2);

	/* Increment the value on the top of the stack */
	if(node->size != IL_MAX_UINT32)
	{
		ILGenUIntNative(info, node->size);
		ILGenAdjust(info, 1);
	}
	else
	{
		ILNode_GenValue(node->sizeNode, info);
		ILGenSimple(info, IL_OP_CONV_U);
	}
	ILGenSimple(info, IL_OP_SUB);
	ILGenAdjust(info, -1);

	/* Store the value into the destination */
	ILNode_Store(node->expr, info, 0, data1, data2);

	/* Return the final type to the caller */
	return ILMachineType_UnmanagedPtr;
}
#line 1577 "cg_assign.c"

ILMachineType ILNode_PostDecPtr_JavaGenValue__(ILNode_PostDecPtr *node, ILGenInfo * info)
#line 468 "jv_assign.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 1584 "cg_assign.c"

struct ILNode_PostDecPtr_vtable__ const ILNode_PostDecPtr_vt__ = {
	&ILNode_IncOrDecPtr_vt__,
	ILNode_PostDecPtr_kind,
	"ILNode_PostDecPtr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDecPtr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDecPtr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDecPtr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_PostDecPtr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Assign_ILNode_GetType__(ILNode_Assign *node, ILGenInfo * info)
#line 43 "cg_assign.tc"
{
	return ILNode_GetType(node->expr1, info);
}
#line 1608 "cg_assign.c"

void ILNode_Assign_ILNode_GenDiscard__(ILNode_Assign *node, ILGenInfo * info)
#line 85 "cg_assign.tc"
{
	ILMachineType finalType;
	void *data1, *data2;

	/* Prepare the l-value for a later store operation */
	finalType = ILNode_Prepare(node->expr1, info, &data1, &data2);

	/* Evaluate the second sub-expression and cast to the final type */
	ILGenCast(info, ILNode_GenValue(node->expr2, info), finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr1, info, 0, data1, data2);
}
#line 1625 "cg_assign.c"

ILMachineType ILNode_Assign_ILNode_GenValue__(ILNode_Assign *node, ILGenInfo * info)
#line 192 "cg_assign.tc"
{
	ILMachineType finalType;
	void *data1, *data2;

	/* Prepare the l-value for a later store operation */
	finalType = ILNode_Prepare(node->expr1, info, &data1, &data2);

	/* Evaluate the second sub-expression and cast to the final type */
	ILGenCast(info, ILNode_GenValue(node->expr2, info), finalType);

	/* Store the value into the destination */
	ILNode_Store(node->expr1, info, 1, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 1645 "cg_assign.c"

void ILNode_Assign_JavaGenDiscard__(ILNode_Assign *node, ILGenInfo * info)
#line 43 "jv_assign.tc"
{
	ILMachineType finalType;
	void *data1, *data2;

	/* Prepare the l-value for a later store operation */
	finalType = JavaPrepare(node->expr1, info, &data1, &data2);

	/* Evaluate the second sub-expression and cast to the final type */
	JavaGenCast(info, JavaGenValue(node->expr2, info), finalType);

	/* Store the value into the destination */
	JavaStore(node->expr1, info, 0, data1, data2);
}
#line 1662 "cg_assign.c"

ILMachineType ILNode_Assign_JavaGenValue__(ILNode_Assign *node, ILGenInfo * info)
#line 185 "jv_assign.tc"
{
	ILMachineType finalType;
	void *data1, *data2;

	/* Prepare the l-value for a later store operation */
	finalType = JavaPrepare(node->expr1, info, &data1, &data2);

	/* Evaluate the second sub-expression and cast to the final type */
	JavaGenCast(info, JavaGenValue(node->expr2, info), finalType);

	/* Store the value into the destination */
	JavaStore(node->expr1, info, 1, data1, data2);

	/* Return the final type to the caller */
	return finalType;
}
#line 1682 "cg_assign.c"

struct ILNode_Assign_vtable__ const ILNode_Assign_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_Assign_kind,
	"ILNode_Assign",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Assign_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Assign_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Assign_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Assign_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Assign_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignAdd_vtable__ const ILNode_AssignAdd_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignAdd_kind,
	"ILNode_AssignAdd",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignSub_vtable__ const ILNode_AssignSub_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignSub_kind,
	"ILNode_AssignSub",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignMul_vtable__ const ILNode_AssignMul_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignMul_kind,
	"ILNode_AssignMul",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignDiv_vtable__ const ILNode_AssignDiv_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignDiv_kind,
	"ILNode_AssignDiv",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignRem_vtable__ const ILNode_AssignRem_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignRem_kind,
	"ILNode_AssignRem",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignAnd_vtable__ const ILNode_AssignAnd_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignAnd_kind,
	"ILNode_AssignAnd",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignOr_vtable__ const ILNode_AssignOr_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignOr_kind,
	"ILNode_AssignOr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignXor_vtable__ const ILNode_AssignXor_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignXor_kind,
	"ILNode_AssignXor",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignShl_vtable__ const ILNode_AssignShl_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignShl_kind,
	"ILNode_AssignShl",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignShr_vtable__ const ILNode_AssignShr_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignShr_kind,
	"ILNode_AssignShr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_AssignUShr_vtable__ const ILNode_AssignUShr_vt__ = {
	&ILNode_AssignExpression_vt__,
	ILNode_AssignUShr_kind,
	"ILNode_AssignUShr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AssignExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILNode *ILNode_PreInc_create(ILNode * expr)
{
	ILNode_PreInc *node__ = (ILNode_PreInc *)yynodealloc(sizeof(struct ILNode_PreInc__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PreInc_vt__;
	node__->kind__ = ILNode_PreInc_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_PreDec_create(ILNode * expr)
{
	ILNode_PreDec *node__ = (ILNode_PreDec *)yynodealloc(sizeof(struct ILNode_PreDec__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PreDec_vt__;
	node__->kind__ = ILNode_PreDec_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_PostInc_create(ILNode * expr)
{
	ILNode_PostInc *node__ = (ILNode_PostInc *)yynodealloc(sizeof(struct ILNode_PostInc__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PostInc_vt__;
	node__->kind__ = ILNode_PostInc_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_PostDec_create(ILNode * expr)
{
	ILNode_PostDec *node__ = (ILNode_PostDec *)yynodealloc(sizeof(struct ILNode_PostDec__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PostDec_vt__;
	node__->kind__ = ILNode_PostDec_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_UserPreInc_create(ILNode * expr, ILMethod * method, ILMachineType type)
{
	ILNode_UserPreInc *node__ = (ILNode_UserPreInc *)yynodealloc(sizeof(struct ILNode_UserPreInc__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserPreInc_vt__;
	node__->kind__ = ILNode_UserPreInc_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->method = method;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_UserPreDec_create(ILNode * expr, ILMethod * method, ILMachineType type)
{
	ILNode_UserPreDec *node__ = (ILNode_UserPreDec *)yynodealloc(sizeof(struct ILNode_UserPreDec__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserPreDec_vt__;
	node__->kind__ = ILNode_UserPreDec_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->method = method;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_UserPostInc_create(ILNode * expr, ILMethod * method, ILMachineType type)
{
	ILNode_UserPostInc *node__ = (ILNode_UserPostInc *)yynodealloc(sizeof(struct ILNode_UserPostInc__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserPostInc_vt__;
	node__->kind__ = ILNode_UserPostInc_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->method = method;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_UserPostDec_create(ILNode * expr, ILMethod * method, ILMachineType type)
{
	ILNode_UserPostDec *node__ = (ILNode_UserPostDec *)yynodealloc(sizeof(struct ILNode_UserPostDec__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserPostDec_vt__;
	node__->kind__ = ILNode_UserPostDec_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->method = method;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_PreIncPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode)
{
	ILNode_PreIncPtr *node__ = (ILNode_PreIncPtr *)yynodealloc(sizeof(struct ILNode_PreIncPtr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PreIncPtr_vt__;
	node__->kind__ = ILNode_PreIncPtr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->size = size;
	node__->sizeNode = sizeNode;
	return (ILNode *)node__;
}

ILNode *ILNode_PreDecPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode)
{
	ILNode_PreDecPtr *node__ = (ILNode_PreDecPtr *)yynodealloc(sizeof(struct ILNode_PreDecPtr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PreDecPtr_vt__;
	node__->kind__ = ILNode_PreDecPtr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->size = size;
	node__->sizeNode = sizeNode;
	return (ILNode *)node__;
}

ILNode *ILNode_PostIncPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode)
{
	ILNode_PostIncPtr *node__ = (ILNode_PostIncPtr *)yynodealloc(sizeof(struct ILNode_PostIncPtr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PostIncPtr_vt__;
	node__->kind__ = ILNode_PostIncPtr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->size = size;
	node__->sizeNode = sizeNode;
	return (ILNode *)node__;
}

ILNode *ILNode_PostDecPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode)
{
	ILNode_PostDecPtr *node__ = (ILNode_PostDecPtr *)yynodealloc(sizeof(struct ILNode_PostDecPtr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PostDecPtr_vt__;
	node__->kind__ = ILNode_PostDecPtr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->size = size;
	node__->sizeNode = sizeNode;
	return (ILNode *)node__;
}

ILNode *ILNode_Assign_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Assign *node__ = (ILNode_Assign *)yynodealloc(sizeof(struct ILNode_Assign__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Assign_vt__;
	node__->kind__ = ILNode_Assign_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignAdd_create(ILNode * assign)
{
	ILNode_AssignAdd *node__ = (ILNode_AssignAdd *)yynodealloc(sizeof(struct ILNode_AssignAdd__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignAdd_vt__;
	node__->kind__ = ILNode_AssignAdd_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignSub_create(ILNode * assign)
{
	ILNode_AssignSub *node__ = (ILNode_AssignSub *)yynodealloc(sizeof(struct ILNode_AssignSub__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignSub_vt__;
	node__->kind__ = ILNode_AssignSub_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignMul_create(ILNode * assign)
{
	ILNode_AssignMul *node__ = (ILNode_AssignMul *)yynodealloc(sizeof(struct ILNode_AssignMul__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignMul_vt__;
	node__->kind__ = ILNode_AssignMul_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignDiv_create(ILNode * assign)
{
	ILNode_AssignDiv *node__ = (ILNode_AssignDiv *)yynodealloc(sizeof(struct ILNode_AssignDiv__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignDiv_vt__;
	node__->kind__ = ILNode_AssignDiv_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignRem_create(ILNode * assign)
{
	ILNode_AssignRem *node__ = (ILNode_AssignRem *)yynodealloc(sizeof(struct ILNode_AssignRem__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignRem_vt__;
	node__->kind__ = ILNode_AssignRem_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignAnd_create(ILNode * assign)
{
	ILNode_AssignAnd *node__ = (ILNode_AssignAnd *)yynodealloc(sizeof(struct ILNode_AssignAnd__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignAnd_vt__;
	node__->kind__ = ILNode_AssignAnd_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignOr_create(ILNode * assign)
{
	ILNode_AssignOr *node__ = (ILNode_AssignOr *)yynodealloc(sizeof(struct ILNode_AssignOr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignOr_vt__;
	node__->kind__ = ILNode_AssignOr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignXor_create(ILNode * assign)
{
	ILNode_AssignXor *node__ = (ILNode_AssignXor *)yynodealloc(sizeof(struct ILNode_AssignXor__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignXor_vt__;
	node__->kind__ = ILNode_AssignXor_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignShl_create(ILNode * assign)
{
	ILNode_AssignShl *node__ = (ILNode_AssignShl *)yynodealloc(sizeof(struct ILNode_AssignShl__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignShl_vt__;
	node__->kind__ = ILNode_AssignShl_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignShr_create(ILNode * assign)
{
	ILNode_AssignShr *node__ = (ILNode_AssignShr *)yynodealloc(sizeof(struct ILNode_AssignShr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignShr_vt__;
	node__->kind__ = ILNode_AssignShr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

ILNode *ILNode_AssignUShr_create(ILNode * assign)
{
	ILNode_AssignUShr *node__ = (ILNode_AssignUShr *)yynodealloc(sizeof(struct ILNode_AssignUShr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AssignUShr_vt__;
	node__->kind__ = ILNode_AssignUShr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->assign = assign;
	return (ILNode *)node__;
}

void ILDecrement_ApplyOp(ILGenInfo * info, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 941 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2203 "cg_assign.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 941 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2213 "cg_assign.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 801 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_SUB);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
				ILGenExtend(info, 1);
			}
#line 2233 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 815 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_SUB);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
				ILGenExtend(info, 1);
			}
#line 2253 "cg_assign.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 829 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_SUB);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
				ILGenExtend(info, 1);
			}
#line 2273 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 844 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_SUB);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
				ILGenExtend(info, 1);
			}
#line 2293 "cg_assign.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 844 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_SUB);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
				ILGenExtend(info, 1);
			}
#line 2313 "cg_assign.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 859 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_SUB_OVF);
				}
				else
				{
					ILGenSimple(info, IL_OP_SUB);
				}
				ILGenExtend(info, 1);
			}
#line 2332 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 874 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_SUB_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_SUB);
				}
				ILGenExtend(info, 1);
			}
#line 2351 "cg_assign.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 887 "cg_assign.tc"
			{
				ILGenInt64(info, 1);
				ILGenAdjust(info, 1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_SUB_OVF);
				}
				else
				{
					ILGenSimple(info, IL_OP_SUB);
				}
				ILGenAdjust(info, -1);
			}
#line 2371 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 901 "cg_assign.tc"
			{
				ILGenUInt64(info, 1);
				ILGenAdjust(info, 1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_SUB_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_SUB);
				}
				ILGenAdjust(info, -1);
			}
#line 2391 "cg_assign.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 859 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_SUB_OVF);
				}
				else
				{
					ILGenSimple(info, IL_OP_SUB);
				}
				ILGenExtend(info, 1);
			}
#line 2410 "cg_assign.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 874 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_SUB_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_SUB);
				}
				ILGenExtend(info, 1);
			}
#line 2429 "cg_assign.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 915 "cg_assign.tc"
			{
				ILGenLoadFloat32(info, (ILFloat)1.0);
				ILGenSimple(info, IL_OP_SUB);
				ILGenExtend(info, 1);
			}
#line 2441 "cg_assign.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 922 "cg_assign.tc"
			{
				ILGenLoadFloat64(info, (ILDouble)1.0);
				ILGenSimple(info, IL_OP_SUB);
				ILGenExtend(info, 1);
			}
#line 2453 "cg_assign.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 922 "cg_assign.tc"
			{
				ILGenLoadFloat64(info, (ILDouble)1.0);
				ILGenSimple(info, IL_OP_SUB);
				ILGenExtend(info, 1);
			}
#line 2465 "cg_assign.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 928 "cg_assign.tc"
			{
				ILGenCallByName(info,
					"valuetype [.library]System.Decimal "
						"[.library]System.Decimal::op_Decrement"
						"(valuetype System.Decimal)");
			}
#line 2478 "cg_assign.c"
		}
		break;

		case ILMachineType_String:
		{
#line 941 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2488 "cg_assign.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 941 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2498 "cg_assign.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 874 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_SUB_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_SUB);
				}
				ILGenExtend(info, 1);
			}
#line 2517 "cg_assign.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 941 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2527 "cg_assign.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 941 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2537 "cg_assign.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 941 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2547 "cg_assign.c"
		}
		break;

		default: break;
	}
}

void ILIncrement_ApplyOp(ILGenInfo * info, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 793 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2565 "cg_assign.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 793 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2575 "cg_assign.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 653 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_ADD);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
				ILGenExtend(info, 1);
			}
#line 2595 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 667 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_ADD);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
				ILGenExtend(info, 1);
			}
#line 2615 "cg_assign.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 681 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_ADD);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
				ILGenExtend(info, 1);
			}
#line 2635 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 696 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_ADD);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
				ILGenExtend(info, 1);
			}
#line 2655 "cg_assign.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 696 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenSimple(info, IL_OP_ADD);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
				ILGenExtend(info, 1);
			}
#line 2675 "cg_assign.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 711 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_ADD_OVF);
				}
				else
				{
					ILGenSimple(info, IL_OP_ADD);
				}
				ILGenExtend(info, 1);
			}
#line 2694 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 726 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_ADD_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_ADD);
				}
				ILGenExtend(info, 1);
			}
#line 2713 "cg_assign.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 739 "cg_assign.tc"
			{
				ILGenInt64(info, 1);
				ILGenAdjust(info, 1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_ADD_OVF);
				}
				else
				{
					ILGenSimple(info, IL_OP_ADD);
				}
				ILGenAdjust(info, -1);
			}
#line 2733 "cg_assign.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 753 "cg_assign.tc"
			{
				ILGenUInt64(info, 1);
				ILGenAdjust(info, 1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_ADD_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_ADD);
				}
				ILGenAdjust(info, -1);
			}
#line 2753 "cg_assign.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 711 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_ADD_OVF);
				}
				else
				{
					ILGenSimple(info, IL_OP_ADD);
				}
				ILGenExtend(info, 1);
			}
#line 2772 "cg_assign.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 726 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_ADD_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_ADD);
				}
				ILGenExtend(info, 1);
			}
#line 2791 "cg_assign.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 767 "cg_assign.tc"
			{
				ILGenLoadFloat32(info, (ILFloat)1.0);
				ILGenSimple(info, IL_OP_ADD);
				ILGenExtend(info, 1);
			}
#line 2803 "cg_assign.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 774 "cg_assign.tc"
			{
				ILGenLoadFloat64(info, (ILDouble)1.0);
				ILGenSimple(info, IL_OP_ADD);
				ILGenExtend(info, 1);
			}
#line 2815 "cg_assign.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 774 "cg_assign.tc"
			{
				ILGenLoadFloat64(info, (ILDouble)1.0);
				ILGenSimple(info, IL_OP_ADD);
				ILGenExtend(info, 1);
			}
#line 2827 "cg_assign.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 780 "cg_assign.tc"
			{
				ILGenCallByName(info,
					"valuetype [.library]System.Decimal "
						"[.library]System.Decimal::op_Increment"
						"(valuetype [.library]System.Decimal)");
			}
#line 2840 "cg_assign.c"
		}
		break;

		case ILMachineType_String:
		{
#line 793 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2850 "cg_assign.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 793 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2860 "cg_assign.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 726 "cg_assign.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_1);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_ADD_OVF_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_ADD);
				}
				ILGenExtend(info, 1);
			}
#line 2879 "cg_assign.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 793 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2889 "cg_assign.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 793 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2899 "cg_assign.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 793 "cg_assign.tc"
			{
				/* Default - should never be used */
			}
#line 2909 "cg_assign.c"
		}
		break;

		default: break;
	}
}

