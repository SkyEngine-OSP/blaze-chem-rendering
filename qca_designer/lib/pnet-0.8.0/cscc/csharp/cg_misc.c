/* cg_misc.c.  Generated automatically by treecc */
#line 3 "cg_misc.tc"

/*
 * cg_misc.tc - Miscellaneous operator nodes.
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

#line 189 "cg_misc.tc"


/*
 * Determine the common type to use for a conditional expression.
 */
static ILMachineType Conditional_Type(ILNode_Conditional *node,
									  ILGenInfo *info,
									  ILMachineType *type1,
									  ILMachineType *type2)
{
	*type1 = ILNode_GetType(node->expr2, info);
	*type2 = ILNode_GetType(node->expr3, info);
	if(*type1 == *type2)
	{
		return *type1;
	}
	else if(*type1 == ILMachineType_ObjectRef ||
		    *type2 == ILMachineType_ObjectRef)
	{
		return ILMachineType_ObjectRef;
	}
	else
	{
		return ILCommonType(info, *type1, *type2, 0);
	}
}

#line 965 "cg_misc.tc"


/*
 * Get an array element from an argument array list.
 */
static ILNode *GetArgArrayElem(ILNode *list, ILUInt32 posn, ILUInt32 num)
{
	while(posn != (num - 1))
	{
		list = ((ILNode_ArgList *)list)->expr1;
		++posn;
	}
	if(yyisa(list, ILNode_ArgList))
	{
		return ((ILNode_ArgList *)list)->expr2;
	}
	else
	{
		return list;
	}
}

#line 1021 "cg_misc.tc"


/*
 * Output array dimensions for a "new" expression, and ensure
 * that they are converted to 32-bit values.
 */
static void OutputArrayDims(ILGenInfo *info, ILNode *dims)
{
	ILMachineType type;

	/* Recurse down to process the left sub-nodes first */
	if(yyisa(dims, ILNode_ArgList))
	{
		OutputArrayDims(info, ((ILNode_ArgList *)dims)->expr1);
		dims = ((ILNode_ArgList *)dims)->expr2;
	}

	/* Output code for this dimension */
	if(info->outputIsJava)
	{
		type = JavaGenValue(dims, info);
	}
	else
	{
		type = ILNode_GenValue(dims, info);
	}
	if(type == ILMachineType_Int64 || type == ILMachineType_UInt64)
	{
		if(info->outputIsJava)
		{
			JavaGenCallIntrinsic(info, "l2ui_ovf", "(J)I");
			JavaGenAdjust(info, -1);
		}
		else
		{
			ILGenSimple(info, IL_OP_CONV_OVF_U4_UN);
		}
	}
}

#line 1290 "cg_misc.tc"


unsigned ILGenPrepareForThisAccess(ILGenInfo *info, ILNode *thisExpr,
							       ILClass *classInfo, int isLoadOnly)
{
	ILType *fullType;
	ILMachineType thisType;
	unsigned tempVar = ~((unsigned)0);

	/* Bail out if no "this" expression */
	if(!thisExpr)
	{
		return tempVar;
	}

	/* Determine the full type of the "this" expression, if possible */
	if(yyisa(thisExpr, ILNode_MarkType))
	{
		fullType = ((ILNode_MarkType *)thisExpr)->type;
		thisExpr = ((ILNode_MarkType *)thisExpr)->expr;
	}
	else
	{
		fullType = 0;
	}

	/* Is the method in a value type or a regular class? */
	if(ILClassIsValueType(classInfo))
	{
		/* Get a managed pointer for the object */
		if(yyisa(thisExpr, ILNode_This))
		{
			/* Just push the "this" pointer: we don't want to convert
			   it into a value and then re-box it */
			ILGenSimple(info, IL_OP_LDARG_0);
			ILGenAdjust(info, 1);
		}
		else
		{
			thisType = ILNode_GetType(thisExpr, info);
			if((thisType >= ILMachineType_Boolean &&
			    thisType <= ILMachineType_NativeFloat) ||
			   thisType == ILMachineType_Decimal ||
			   thisType == ILMachineType_ManagedValue)
			{
				/* Turn the value into a managed pointer */
				if(yyisa(thisExpr, ILNode_LValue) &&
				   !yyisa(thisExpr, ILNode_LValueNoRef))
				{
					/* Generate a reference for the supplied value instance */
					ILNode_GenRef(thisExpr, info);
				}
				/* NOTE: We need to convert to managed address even if
				   this is a single access*/
				else
				{
					/* Store the managed value into a temporary variable */
					tempVar = ILGenTempTypedVar(info, ILClassToType(classInfo));
					ILNode_GenValue(thisExpr, info);
					ILGenStoreLocal(info, tempVar);
					ILGenAdjust(info, -1);

					/* Push the address of the temporary variable */
					ILGenLoadLocalAddr(info, tempVar);
					ILGenAdjust(info, 1);
					if(isLoadOnly)
					{
						ILGenReleaseTempVar(info,tempVar);
					}
				}
			}
			else
			{
				/* Probably already a managed pointer */
				ILNode_GenValue(thisExpr, info);
			}
		}
	}
	else if(fullType && ILTypeIsValue(fullType))
	{
		/* Box the value before accessing the method, field, or property,
		   because we will be accessing it via a regular object class */
		ILNode_GenValue(thisExpr, info);
		ILGenClassToken(info, IL_OP_BOX, ILTypeToClass(info, fullType));
	}
	else
	{
		/* Assume that the value will be an object reference */
		ILGenCast(info, ILNode_GenValue(thisExpr, info),
				  ILMachineType_ObjectRef);
	}

	/* Return the temporary variable reference to the caller */
	return tempVar;
}

void ILGenFreeThisVar(ILGenInfo *info, unsigned tempVar)
{
	if(tempVar != ~((unsigned)0))
	{
		ILGenReleaseTempVar(info, tempVar);
	}
}

#line 1487 "cg_misc.tc"


/*
 * Generate value code for an "as" expression, which may
 * be nested inside some other kind of expression.
 */
static void As_GenValue(ILNode_As *node, ILGenInfo *info)
{
	/* Evaluate the sub-expression and cast to an object reference */
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_ObjectRef);

	/* Test the object using the "isinst" instruction */
	ILGenClassToken(info, IL_OP_ISINST, node->classInfo);
}

#line 2055 "cg_misc.tc"


/*
 * Generate a branch for a conditional expression.
 */
static void ConditionalBranch(ILNode_Conditional *node, ILGenInfo *info,
							  ILLabel *label, int thenCase)
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILEvalValue value;

	/* Determine the common type to use for the cases */
	commonType = Conditional_Type(node, info, &type1, &type2);

	/* If the condition is constant, then only generate the case we need */
	if(ILNode_EvalConst(node->expr1, info, &value) &&
	   ILGenConstToBoolean(info, &value))
	{
		if(value.un.i4Value)
		{
			/* The condition is always true */
			if(type1 == commonType)
			{
				if(thenCase)
				{
					ILNode_GenThen(node->expr2, info, label);
				}
				else
				{
					ILNode_GenElse(node->expr2, info, label);
				}
			}
			else
			{
				ILNode_GenValue(node->expr2, info);
				ILGenCast(info, type1, commonType);
				if(thenCase)
				{
					ILNodeStackThen(info, label, commonType);
				}
				else
				{
					ILNodeStackElse(info, label, commonType);
				}
			}
		}
		else
		{
			/* The condition is always false */
			if(type2 == commonType)
			{
				if(thenCase)
				{
					ILNode_GenThen(node->expr3, info, label);
				}
				else
				{
					ILNode_GenElse(node->expr3, info, label);
				}
			}
			else
			{
				ILNode_GenValue(node->expr3, info);
				ILGenCast(info, type2, commonType);
				if(thenCase)
				{
					ILNodeStackThen(info, label, commonType);
				}
				else
				{
					ILNodeStackElse(info, label, commonType);
				}
			}
		}
	}
	else
	{
		/* Generate the full case of the conditional.  Use value testing
		   if the type is different in case the conversion might generate
		   a conversion exception.  Optimizing the convert away will change
		   the behaviour of the expression */
		ILNode_GenElse(node->expr1, info, &label1);
		if(type1 == commonType)
		{
			if(thenCase)
			{
				ILNode_GenThen(node->expr2, info, label);
			}
			else
			{
				ILNode_GenElse(node->expr3, info, label);
			}
		}
		else
		{
			ILNode_GenValue(node->expr2, info);
			ILGenCast(info, type1, commonType);
			if(thenCase)
			{
				ILNodeStackThen(info, label, commonType);
			}
			else
			{
				ILNodeStackElse(info, label, commonType);
			}
		}
		ILGenJump(info, IL_OP_BR, &label2);
		ILGenLabel(info, &label1);
		if(type2 == commonType)
		{
			if(thenCase)
			{
				ILNode_GenThen(node->expr3, info, label);
			}
			else
			{
				ILNode_GenElse(node->expr3, info, label);
			}
		}
		else
		{
			ILNode_GenValue(node->expr3, info);
			ILGenCast(info, type2, commonType);
			if(thenCase)
			{
				ILNodeStackThen(info, label, commonType);
			}
			else
			{
				ILNodeStackElse(info, label, commonType);
			}
		}
		ILGenLabel(info, &label2);
	}
}

#line 2325 "cg_misc.tc"


/*
 * Prepare a sub-expression for storage.
 */
static ILMachineType Prepare_SubExpr(ILNode_LValueUnaryExpr *node,
									 ILGenInfo *info, void **data1,
									 void **data2)
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		return ILNode_Prepare((ILNode_LValue *)(node->expr),
							  info, data1, data2);
	}
	else
	{
		return ILMachineType_Void;
	}
}

#line 2424 "cg_misc.tc"


/*
 * Get and prepare a sub-expression for storage.
 */
static ILMachineType GetAndPrepare_SubExpr(ILNode_LValueUnaryExpr *node,
									       ILGenInfo *info, int leave,
										   void **data1, void **data2)
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		return ILNode_GetAndPrepare((ILNode_LValue *)(node->expr),
							        info, leave, data1, data2);
	}
	else
	{
		return ILMachineType_Void;
	}
}

#line 2554 "cg_misc.tc"


/*
 * Store a sub-expression.
 */
static void Store_SubExpr(ILNode_LValueUnaryExpr *node,
					      ILGenInfo *info, int leave,
						  void **data1, void **data2)
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		ILNode_Store((ILNode_LValue *)(node->expr), info, leave, data1, data2);
	}
}

#line 1884 "jv_misc.tc"


/*
 * Determine if a statement node is of base access.
 */
#define IsBaseAccess(node)	(!(node) || yykind((node)) == \
 			yykindof(ILNode_BaseAccess))

/*
 * Generate a branch for a conditional expression.
 */
static void JavaConditionalBranch(ILNode_Conditional *node, ILGenInfo *info,
							      ILLabel *label, int thenCase)
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILEvalValue value;

	/* Determine the common type to use for the cases */
	commonType = Conditional_Type(node, info, &type1, &type2);

	/* If the condition is constant, then only generate the case we need */
	if(ILNode_EvalConst(node->expr1, info, &value) &&
	   ILGenConstToBoolean(info, &value))
	{
		if(value.un.i4Value)
		{
			/* The condition is always true */
			if(type1 == commonType)
			{
				if(thenCase)
				{
					JavaGenThen(node->expr2, info, label);
				}
				else
				{
					JavaGenElse(node->expr2, info, label);
				}
			}
			else
			{
				JavaGenValue(node->expr2, info);
				JavaGenCast(info, type1, commonType);
				if(thenCase)
				{
					JavaStackThen(info, label, commonType);
				}
				else
				{
					JavaStackElse(info, label, commonType);
				}
			}
		}
		else
		{
			/* The condition is always false */
			if(type2 == commonType)
			{
				if(thenCase)
				{
					JavaGenThen(node->expr3, info, label);
				}
				else
				{
					JavaGenElse(node->expr3, info, label);
				}
			}
			else
			{
				JavaGenValue(node->expr3, info);
				JavaGenCast(info, type2, commonType);
				if(thenCase)
				{
					JavaStackThen(info, label, commonType);
				}
				else
				{
					JavaStackElse(info, label, commonType);
				}
			}
		}
	}
	else
	{
		/* Generate the full case of the conditional.  Use value testing
		   if the type is different in case the conversion might generate
		   a conversion exception.  Optimizing the convert away will change
		   the behaviour of the expression */
		JavaGenElse(node->expr1, info, &label1);
		if(type1 == commonType)
		{
			if(thenCase)
			{
				JavaGenThen(node->expr2, info, label);
			}
			else
			{
				JavaGenElse(node->expr3, info, label);
			}
		}
		else
		{
			JavaGenValue(node->expr2, info);
			JavaGenCast(info, type1, commonType);
			if(thenCase)
			{
				JavaStackThen(info, label, commonType);
			}
			else
			{
				JavaStackElse(info, label, commonType);
			}
		}
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		if(type2 == commonType)
		{
			if(thenCase)
			{
				JavaGenThen(node->expr3, info, label);
			}
			else
			{
				JavaGenElse(node->expr3, info, label);
			}
		}
		else
		{
			JavaGenValue(node->expr3, info);
			JavaGenCast(info, type2, commonType);
			if(thenCase)
			{
				JavaStackThen(info, label, commonType);
			}
			else
			{
				JavaStackElse(info, label, commonType);
			}
		}
		JavaGenLabel(info, &label2);
	}
}

#line 2166 "jv_misc.tc"


/*
 * Prepare a sub-expression for storage.
 */
static ILMachineType JavaPrepare_SubExpr(ILNode_LValueUnaryExpr *node,
									     ILGenInfo *info, void **data1,
									     void **data2)
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		return JavaPrepare((ILNode_LValue *)(node->expr),
						   info, data1, data2);
	}
	else
	{
		return ILMachineType_Void;
	}
}

#line 2262 "jv_misc.tc"


/*
 * Get and prepare a sub-expression for storage.
 */
static ILMachineType JavaGetAndPrepare_SubExpr(ILNode_LValueUnaryExpr *node,
									           ILGenInfo *info, int leave,
										       void **data1, void **data2)
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		return JavaGetAndPrepare((ILNode_LValue *)(node->expr),
							     info, leave, data1, data2);
	}
	else
	{
		return ILMachineType_Void;
	}
}

#line 2358 "jv_misc.tc"


/*
 * Store a sub-expression.
 */
static void JavaStore_SubExpr(ILNode_LValueUnaryExpr *node,
					          ILGenInfo *info, int leave,
						      void **data1, void **data2)
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		JavaStore((ILNode_LValue *)(node->expr), info, leave, data1, data2);
	}
}

#line 645 "cg_misc.c"

ILMachineType ILNode_VarArgList_ILNode_GetType__(ILNode_VarArgList *node, ILGenInfo * info)
#line 265 "cg_misc.tc"
{
	/* If used as a value, this is a managed value */
	return ILMachineType_ManagedValue;
}
#line 653 "cg_misc.c"

void ILNode_VarArgList_ILNode_GenDiscard__(ILNode_VarArgList *node, ILGenInfo * info)
#line 417 "cg_misc.tc"
{
	/* Nothing to do here */
}
#line 660 "cg_misc.c"

ILMachineType ILNode_VarArgList_ILNode_GenValue__(ILNode_VarArgList *node, ILGenInfo * info)
#line 924 "cg_misc.tc"
{
	/* When used as a value, this pushes the argument handle
	   for the current method onto the stack */
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_ARGLIST);
	ILGenAdjust(info, 1);
	return ILMachineType_ManagedValue;
}
#line 671 "cg_misc.c"

ILMachineType ILNode_VarArgList_JavaGenValue__(ILNode_VarArgList *node, ILGenInfo * info)
#line 447 "jv_misc.tc"
{
	/* Not used with Java - this should never be called */
	return ILMachineType_ManagedValue;
}
#line 679 "cg_misc.c"

struct ILNode_VarArgList_vtable__ const ILNode_VarArgList_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_VarArgList_kind,
	"ILNode_VarArgList",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VarArgList_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_VarArgList_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VarArgList_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VarArgList_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Argument_ILNode_GetType__(ILNode_Argument *node, ILGenInfo * info)
#line 283 "cg_misc.tc"
{
	if(node->modifier == ILParamMod_ref ||
	   node->modifier == ILParamMod_out)
	{
		return ILMachineType_ManagedPtr;
	}
	else
	{
		return ILNode_GetType(node->expression, info);
	}
}
#line 711 "cg_misc.c"

ILMachineType ILNode_Argument_ILNode_GenValue__(ILNode_Argument *node, ILGenInfo * info)
#line 949 "cg_misc.tc"
{
	if(node->modifier == ILParamMod_ref ||
	   node->modifier == ILParamMod_out)
	{
		if(yyisa(node->expression, ILNode_LValue))
		{
			ILNode_GenRef((ILNode_LValue *)(node->expression), info);
		}
		return ILMachineType_ManagedPtr;
	}
	else
	{
		return ILNode_GenValue(node->expression, info);
	}
}
#line 730 "cg_misc.c"

int ILNode_Argument_ILNode_EvalConst__(ILNode_Argument *node, ILGenInfo * info, ILEvalValue * value)
#line 2786 "cg_misc.tc"
{
	/*  Evaluate the expression  */
	return ILNode_EvalConst(node->expression, info, value);
}
#line 738 "cg_misc.c"

ILMachineType ILNode_Argument_JavaGenValue__(ILNode_Argument *node, ILGenInfo * info)
#line 465 "jv_misc.tc"
{
	/* We don't need to do ref and out parameters,
	   because semantic analysis will disallow such
	   expressions when compiling to the JVM */
	return JavaGenValue(node->expression, info);
}
#line 748 "cg_misc.c"

struct ILNode_Argument_vtable__ const ILNode_Argument_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_Argument_kind,
	"ILNode_Argument",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Argument_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Argument_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Argument_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Argument_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_ArgArray_ILNode_GetType__(ILNode_ArgArray *node, ILGenInfo * info)
#line 299 "cg_misc.tc"
{
	return ILMachineType_ObjectRef;
}
#line 772 "cg_misc.c"

ILMachineType ILNode_ArgArray_ILNode_GenValue__(ILNode_ArgArray *node, ILGenInfo * info)
#line 993 "cg_misc.tc"
{
	ILMachineType machineType;
	ILUInt32 posn;
	int popped;

	/* Create a new array of the desired size */
	ILGenUInt32(info, node->numElems);
	ILGenArrayNew(info, node->elemType);
	ILGenAdjust(info, 1);

	/* Populate the members of the array */
	machineType = ILTypeToMachineType(node->elemType);
	for(posn = 0; posn < node->numElems; ++posn)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenUInt32(info, posn);
		ILGenAdjust(info, 2);
		popped = ILGenStoreArrayPrepare(info, machineType, node->elemType);
		ILGenAdjust(info, -popped);
		ILGenCast(info, ILNode_GenValue
			(GetArgArrayElem(node->args, posn, node->numElems), info),
			machineType);
		ILGenStoreArray(info, machineType, node->elemType);
		ILGenAdjust(info, (-3 + popped));
	}
	return ILMachineType_ObjectRef;
}
#line 803 "cg_misc.c"

ILMachineType ILNode_ArgArray_JavaGenValue__(ILNode_ArgArray *node, ILGenInfo * info)
#line 476 "jv_misc.tc"
{
	ILMachineType machineType;
	ILUInt32 posn;

	/* Create a new array of the desired size */
	JavaGenUInt32(info, node->numElems);
	JavaGenNewArray(info, node->elemType);
	JavaGenAdjust(info, 1);

	/* Populate the members of the array */
	machineType = ILTypeToMachineType(node->elemType);
	for(posn = 0; posn < node->numElems; ++posn)
	{
		JavaGenSimple(info, JAVA_OP_DUP);
		JavaGenUInt32(info, posn);
		JavaGenAdjust(info, 2);
		JavaGenCast(info, JavaGenValue
			(GetArgArrayElem(node->args, posn, node->numElems), info),
			machineType);
		JavaGenStoreArray(info, machineType);
		JavaGenAdjust(info, -3);
	}
	return ILMachineType_ObjectRef;
}
#line 831 "cg_misc.c"

struct ILNode_ArgArray_vtable__ const ILNode_ArgArray_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_ArgArray_kind,
	"ILNode_ArgArray",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgArray_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgArray_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgArray_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_BoxingExpression_vtable__ const ILNode_BoxingExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_BoxingExpression_kind,
	"ILNode_BoxingExpression",
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

ILMachineType ILNode_Error_ILNode_GetType__(ILNode_Error *node, ILGenInfo * info)
#line 339 "cg_misc.tc"
{
	/* This will never be called, but we have to return something */
	return ILMachineType_Void;
}
#line 873 "cg_misc.c"

ILMachineType ILNode_Error_ILNode_GenValue__(ILNode_Error *node, ILGenInfo * info)
#line 1569 "cg_misc.tc"
{
	return ILMachineType_Void;
}
#line 880 "cg_misc.c"

ILMachineType ILNode_Error_JavaGenValue__(ILNode_Error *node, ILGenInfo * info)
#line 564 "jv_misc.tc"
{
	return ILMachineType_Void;
}
#line 887 "cg_misc.c"

struct ILNode_Error_vtable__ const ILNode_Error_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_Error_kind,
	"ILNode_Error",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Error_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Error_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Error_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_NewExpression_ILNode_GetType__(ILNode_NewExpression *node, ILGenInfo * info)
#line 118 "cg_misc.tc"
{
	return ILMachineType_ObjectRef;
}
#line 911 "cg_misc.c"

ILMachineType ILNode_NewExpression_ILNode_GenValue__(ILNode_NewExpression *node, ILGenInfo * info)
#line 1064 "cg_misc.tc"
{
	long saveStack;

	/* Bail out if initializer-based (semantic analysis should
	   have turned this node into "ILNode_ArrayInit") */
	if(!(node->indexes))
	{
		return ILMachineType_ObjectRef;
	}

	/* Output the indexes */
	saveStack = info->stackHeight;
	OutputArrayDims(info, node->indexes);

	/* Create the array */
	if(!yyisa(node->indexes, ILNode_ArgList))
	{
		/* Single-dimensional array creation */
		ILGenArrayNew(info, ILTypeGetElemType(node->arrayType));
	}
	else
	{
		/* Multi-dimensional array creation */
		ILGenArrayCtor(info, node->arrayType);
	}

	/* Set the final stack position */
	info->stackHeight = saveStack + 1;

	/* Arrays are always object references */
	return ILMachineType_ObjectRef;
}
#line 947 "cg_misc.c"

ILMachineType ILNode_NewExpression_JavaGenValue__(ILNode_NewExpression *node, ILGenInfo * info)
#line 1367 "jv_misc.tc"
{
	long saveStack;
	int rank;
	ILNode *temp;

	/* Bail out if initializer-based (semantic analysis should
	   have turned this node into "ILNode_ArrayInit") */
	if(!(node->indexes))
	{
		return ILMachineType_ObjectRef;
	}

	/* Output the indexes */
	saveStack = info->stackHeight;
	OutputArrayDims(info, node->indexes);

	/* Create the array */
	if(!yyisa(node->indexes, ILNode_ArgList))
	{
		/* Single-dimensional array creation */
		JavaGenNewArray(info, ILTypeGetElemType(node->arrayType));
	}
	else
	{
		/* Multi-dimensional array creation */
		rank = 1;
		temp = node->indexes;
		while(yyisa(temp, ILNode_ArgList))
		{
			++rank;
			temp = ((ILNode_ArgList *)temp)->expr1;
		}
		JavaGenNewMultiArray(info, node->arrayType, rank);
	}

	/* Set the final stack position */
	info->stackHeight = saveStack + 1;

	/* Arrays are always object references */
	return ILMachineType_ObjectRef;
}
#line 992 "cg_misc.c"

struct ILNode_NewExpression_vtable__ const ILNode_NewExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_NewExpression_kind,
	"ILNode_NewExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NewExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NewExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NewExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_ObjectCreationExpression_ILNode_GetType__(ILNode_ObjectCreationExpression *node, ILGenInfo * info)
#line 126 "cg_misc.tc"
{
	if(ILClassIsValueType(ILMethod_Owner(node->methodInfo)))
	{
		return ILMachineType_ManagedValue;
	}
	else
	{
		return ILMachineType_ObjectRef;
	}
}
#line 1023 "cg_misc.c"

ILMachineType ILNode_ObjectCreationExpression_ILNode_GenValue__(ILNode_ObjectCreationExpression *node, ILGenInfo * info)
#line 1098 "cg_misc.tc"
{
	long saveStack;

	/* Save the current stack height, so we know where to
	   unwind to when popping the arguments */
	saveStack = info->stackHeight;

	/* Push the argument expressions */
	if(node->argList)
	{
		ILNode_GenValue(node->argList, info);
	}

	/* Invoke the constructor */
	ILGenCtorByMethod(info, node->methodInfo, node->callSiteSig);

	/* Re-adjust the stack to remove the arguments and push the result */
	info->stackHeight = saveStack + 1;
	if(info->stackHeight > info->maxStackHeight)
	{
		info->maxStackHeight = info->stackHeight;
	}

	/* The final object is now on the stack , this is *not* a managed value */
	return ILTypeToMachineType(ILClassToType(ILMethod_Owner(node->methodInfo)));
}
#line 1053 "cg_misc.c"

ILMachineType ILNode_ObjectCreationExpression_JavaGenValue__(ILNode_ObjectCreationExpression *node, ILGenInfo * info)
#line 1410 "jv_misc.tc"
{
	long saveStack;

	/* Construct the memory for the object */
	JavaGenClassRef(info, JAVA_OP_NEW, ILMethod_Owner(node->methodInfo));
	JavaGenAdjust(info, 1);

	/* Save the current stack height, so we know where to
	   unwind to when popping the arguments */
	saveStack = info->stackHeight;

	/* Push the argument expressions */
	JavaGenSimple(info, JAVA_OP_DUP);
	JavaGenAdjust(info, 1);
	if(node->argList)
	{
		JavaGenValue(node->argList, info);
	}

	/* Invoke the constructor */
	JavaGenCallSpecialByMethod(info, node->methodInfo);

	/* Re-adjust the stack to remove the arguments */
	info->stackHeight = saveStack;
	if(info->stackHeight > info->maxStackHeight)
	{
		info->maxStackHeight = info->stackHeight;
	}

	/* The final managed value or object reference is now on the stack */
	if(ILClassIsValueType(ILMethod_Owner(node->methodInfo)))
	{
		return ILMachineType_ManagedValue;
	}
	else
	{
		return ILMachineType_ObjectRef;
	}
}
#line 1096 "cg_misc.c"

struct ILNode_ObjectCreationExpression_vtable__ const ILNode_ObjectCreationExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_ObjectCreationExpression_kind,
	"ILNode_ObjectCreationExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ObjectCreationExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ObjectCreationExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ObjectCreationExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_DelegateCreationExpression_ILNode_GetType__(ILNode_DelegateCreationExpression *node, ILGenInfo * info)
#line 141 "cg_misc.tc"
{
	return ILMachineType_ObjectRef;
}
#line 1120 "cg_misc.c"

ILMachineType ILNode_DelegateCreationExpression_ILNode_GenValue__(ILNode_DelegateCreationExpression *node, ILGenInfo * info)
#line 1129 "cg_misc.tc"
{
	/* Push the object expression */
	if(node->expr)
	{
		ILNode_GenValue(node->expr, info);
	}
	else
	{
		ILGenSimple(info, IL_OP_LDNULL);
		ILGenAdjust(info, 1);
	}

	/* Retrieve the method pointer */
	if(ILMethod_IsVirtual(node->methodInfo))
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenLoadMethod(info, IL_OP_PREFIX + IL_PREFIX_OP_LDVIRTFTN,
						node->methodInfo);
	}
	else
	{
		ILGenLoadMethod(info, IL_OP_PREFIX + IL_PREFIX_OP_LDFTN,
						node->methodInfo);
		ILGenAdjust(info, 1);
	}

	/* Call the delegate constructor */
	ILGenNewDelegate(info, node->delegateClass);
	ILGenAdjust(info, -1);

	/* Delegates are always object references */
	return ILMachineType_ObjectRef;
}
#line 1158 "cg_misc.c"

ILMachineType ILNode_DelegateCreationExpression_JavaGenValue__(ILNode_DelegateCreationExpression *node, ILGenInfo * info)
#line 1454 "jv_misc.tc"
{
	/* Delegate creation is not yet supported in Java */
	return ILMachineType_ObjectRef;
}
#line 1166 "cg_misc.c"

struct ILNode_DelegateCreationExpression_vtable__ const ILNode_DelegateCreationExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_DelegateCreationExpression_kind,
	"ILNode_DelegateCreationExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateCreationExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateCreationExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateCreationExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_DefaultConstructor_ILNode_GetType__(ILNode_DefaultConstructor *node, ILGenInfo * info)
#line 149 "cg_misc.tc"
{
	return ILTypeToMachineType(node->type);
}
#line 1190 "cg_misc.c"

ILMachineType ILNode_DefaultConstructor_ILNode_GenValue__(ILNode_DefaultConstructor *node, ILGenInfo * info)
#line 1168 "cg_misc.tc"
{
	ILMachineType type = ILTypeToMachineType(node->type);
	switch(type)
	{
		case ILMachineType_Void:
		{
			/* Nothing to do here: shouldn't happen anyway */
		}
		break;

		case ILMachineType_Boolean:
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		{
			ILGenSimple(info, IL_OP_LDC_I4_0);
			ILGenAdjust(info, 1);
		}
		break;

		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			ILGenSimple(info, IL_OP_LDC_I4_0);
			ILGenSimple(info, IL_OP_CONV_I8);
			ILGenAdjust(info, 1);
		}
		break;

		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		{
			ILGenSimple(info, IL_OP_LDC_I4_0);
			ILGenSimple(info, IL_OP_CONV_I);
			ILGenAdjust(info, 1);
		}
		break;

		case ILMachineType_Float32:
		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		{
			ILGenLoadFloat32(info, (ILFloat)0.0);
			ILGenAdjust(info, 1);
		}
		break;

		case ILMachineType_String:
		{
			ILGenSimple(info, IL_OP_LDNULL);
			ILGenAdjust(info, 1);
		}
		break;

		case ILMachineType_ObjectRef:
		{
			if(node->useCtorMethod)
			{
				if(info->asmOutput)
				{
					fputs("\tnewobj instance void ", info->asmOutput);
					ILDumpType(info->asmOutput, info->image, node->type,
							   IL_DUMP_QUOTE_NAMES);
					fputs("::.ctor()\n", info->asmOutput);
				}
				ILGenAdjust(info, 1);
			}
			else
			{
				ILGenSimple(info, IL_OP_LDNULL);
				ILGenAdjust(info, 1);
			}
		}
		break;

		case ILMachineType_Decimal:
		{
			ILGenSimple(info, IL_OP_LDC_I4_0);
			ILGenCallByName(info, "valuetype [.library]System.Decimal "
							"[.library]System.Decimal::op_Implicit(int32)");
			ILGenAdjust(info, 1);
		}
		break;

		default:
		{
			/* Allocate a temporary variable, initialize it, and
			   then push the initialized value onto the stack */
			unsigned tempVar = ILGenTempTypedVar(info, node->type);
			ILGenLoadLocalAddr(info, tempVar);
			ILGenAdjust(info, 1);
			ILGenTypeToken(info, IL_PREFIX_OP_INITOBJ + IL_OP_PREFIX,
						   node->type);
			ILGenLoadLocal(info, tempVar);
			ILGenReleaseTempVar(info, tempVar);
		}
		break;
	}
	return type;
}
#line 1298 "cg_misc.c"

int ILNode_DefaultConstructor_ILNode_EvalConst__(ILNode_DefaultConstructor *node, ILGenInfo * info, ILEvalValue * value)
#line 2795 "cg_misc.tc"
{
	ILMachineType type = ILTypeToMachineType(node->type);
	switch(type)
	{
		case ILMachineType_Boolean:
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		{
			value->valueType = type;
			value->un.i4Value = 0;
			return 1;
		}
		/* Not reached */

		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			value->valueType = type;
			value->un.i8Value = 0;
			return 1;
		}
		/* Not reached */

		case ILMachineType_Float32:
		{
			value->valueType = type;
			value->un.r4Value = (ILFloat)0.0;
			return 1;
		}
		/* Not reached */

		case ILMachineType_Float64:
		{
			value->valueType = type;
			value->un.r8Value = (ILDouble)0.0;
			return 1;
		}
		/* Not reached */

		case ILMachineType_String:
		case ILMachineType_ObjectRef:
		{
			value->valueType = ILMachineType_ObjectRef;
			value->un.oValue = 0;
			return 1;
		}
		/* Not reached */

		case ILMachineType_Decimal:
		{
			value->valueType = type;
			ILDecimalFromInt32(&(value->un.decValue), 0);
			return 1;
		}
		/* Not reached */

		default: break;
	}
	return 0;
}
#line 1367 "cg_misc.c"

ILMachineType ILNode_DefaultConstructor_JavaGenValue__(ILNode_DefaultConstructor *node, ILGenInfo * info)
#line 1463 "jv_misc.tc"
{
	ILMachineType type = ILTypeToMachineType(node->type);
	switch(type)
	{
		case ILMachineType_Void:
		{
			/* Nothing to do here: shouldn't happen anyway */
		}
		break;

		case ILMachineType_Boolean:
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		{
			JavaGenSimple(info, JAVA_OP_ICONST_0);
			JavaGenAdjust(info, 1);
		}
		break;

		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			JavaGenSimple(info, JAVA_OP_ICONST_0);
			JavaGenSimple(info, JAVA_OP_I2L);
			JavaGenAdjust(info, 2);
		}
		break;

		case ILMachineType_Float32:
		{
			JavaGenSimple(info, JAVA_OP_FCONST_0);
			JavaGenAdjust(info, 1);
		}
		break;

		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		{
			JavaGenSimple(info, JAVA_OP_DCONST_0);
			JavaGenAdjust(info, 2);
		}
		break;

		case ILMachineType_String:
		case ILMachineType_ObjectRef:
		{
			JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			JavaGenAdjust(info, 1);
		}
		break;

		case ILMachineType_Decimal:
		{
			if(info->useJavaLib)
			{
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
						  		  "(J)Ljava/math/BigDecimal;");
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, 1);
			}
			else
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
						  		  "(I)LSystem/Decimal;");
				JavaGenAdjust(info, 1);
			}
		}
		break;

		default:
		{
			/* Create an instance of the value type using
			   the default constructor */
			char *name;
			name = JavaGetClassName(info, ILTypeToClass(info, node->type));
			JavaGenTypeRef(info, JAVA_OP_NEW, node->type);
			JavaGenAdjust(info, 1);
			JavaGenSimple(info, JAVA_OP_DUP);
			JavaGenAdjust(info, 1);
			JavaGenCallCtor(info, name, "<init>", "()V");
			JavaGenAdjust(info, -1);
			ILFree(name);
		}
		break;
	}
	return type;
}
#line 1467 "cg_misc.c"

struct ILNode_DefaultConstructor_vtable__ const ILNode_DefaultConstructor_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_DefaultConstructor_kind,
	"ILNode_DefaultConstructor",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DefaultConstructor_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DefaultConstructor_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_DefaultConstructor_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DefaultConstructor_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_BaseInit_ILNode_GetType__(ILNode_BaseInit *node, ILGenInfo * info)
#line 175 "cg_misc.tc"
{
	/* These are place-holders that are recognized by "InvocationExpression"
	   for invoking parent class constructors */
	return ILMachineType_Void;
}
#line 1493 "cg_misc.c"

ILMachineType ILNode_BaseInit_ILNode_GenValue__(ILNode_BaseInit *node, ILGenInfo * info)
#line 1461 "cg_misc.tc"
{
	/* These are place-holders that are recognized by "InvocationExpression"
	   for invoking parent class constructors */
	return ILMachineType_Void;
}
#line 1502 "cg_misc.c"

ILMachineType ILNode_BaseInit_JavaGenValue__(ILNode_BaseInit *node, ILGenInfo * info)
#line 1675 "jv_misc.tc"
{
	/* These are place-holders that are used by "InvocationExpression"
	   to assist with the invocation of parent class constructors */
	return ILMachineType_Void;
}
#line 1511 "cg_misc.c"

struct ILNode_BaseInit_vtable__ const ILNode_BaseInit_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_BaseInit_kind,
	"ILNode_BaseInit",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseInit_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseInit_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseInit_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_ThisInit_ILNode_GetType__(ILNode_ThisInit *node, ILGenInfo * info)
#line 175 "cg_misc.tc"
{
	/* These are place-holders that are recognized by "InvocationExpression"
	   for invoking parent class constructors */
	return ILMachineType_Void;
}
#line 1537 "cg_misc.c"

ILMachineType ILNode_ThisInit_ILNode_GenValue__(ILNode_ThisInit *node, ILGenInfo * info)
#line 1461 "cg_misc.tc"
{
	/* These are place-holders that are recognized by "InvocationExpression"
	   for invoking parent class constructors */
	return ILMachineType_Void;
}
#line 1546 "cg_misc.c"

ILMachineType ILNode_ThisInit_JavaGenValue__(ILNode_ThisInit *node, ILGenInfo * info)
#line 1675 "jv_misc.tc"
{
	/* These are place-holders that are used by "InvocationExpression"
	   to assist with the invocation of parent class constructors */
	return ILMachineType_Void;
}
#line 1555 "cg_misc.c"

struct ILNode_ThisInit_vtable__ const ILNode_ThisInit_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_ThisInit_kind,
	"ILNode_ThisInit",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ThisInit_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ThisInit_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ThisInit_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_NonStaticInit_ILNode_GetType__(ILNode_NonStaticInit *node, ILGenInfo * info)
#line 185 "cg_misc.tc"
{
	return ILMachineType_Void;
}
#line 1579 "cg_misc.c"

ILMachineType ILNode_NonStaticInit_ILNode_GenValue__(ILNode_NonStaticInit *node, ILGenInfo * info)
#line 1471 "cg_misc.tc"
{
	ILNode_MethodDeclaration *decl;
	if(info->currentClass)
	{
		/* Do we have a non-static initializer for this class? */
		decl = (ILNode_MethodDeclaration *)
			(((ILNode_ClassDefn *)(info->currentClass))->initCtorsMethod);
		if(decl && decl->body)
		{
			/* Output the body of the initializer here */
			ILNode_GenDiscard(decl->body, info);
		}
	}
	return ILMachineType_Void;
}
#line 1598 "cg_misc.c"

ILMachineType ILNode_NonStaticInit_JavaGenValue__(ILNode_NonStaticInit *node, ILGenInfo * info)
#line 1685 "jv_misc.tc"
{
	ILNode_MethodDeclaration *decl;
	if(info->currentClass)
	{
		/* Do we have a non-static initializer for this class? */
		decl = (ILNode_MethodDeclaration *)
			(((ILNode_ClassDefn *)(info->currentClass))->initCtorsMethod);
		if(decl && decl->body)
		{
			/* Output the body of the initializer here */
			JavaGenDiscard(decl->body, info);
		}
	}
	return ILMachineType_Void;
}
#line 1617 "cg_misc.c"

struct ILNode_NonStaticInit_vtable__ const ILNode_NonStaticInit_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_NonStaticInit_kind,
	"ILNode_NonStaticInit",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NonStaticInit_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NonStaticInit_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NonStaticInit_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_This_ILNode_GetType__(ILNode_This *node, ILGenInfo * info)
#line 239 "cg_misc.tc"
{
	if(info->currentClass)
	{
		return ILTypeToMachineType
			(ILClassToType(((ILNode_ClassDefn *)(info->currentClass))
								->classInfo));
	}
	else
	{
		return ILMachineType_ObjectRef;
	}
}
#line 1650 "cg_misc.c"

void ILNode_This_ILNode_GenDiscard__(ILNode_This *node, ILGenInfo * info)
#line 549 "cg_misc.tc"
{
	/* Nothing needs to be done here */
}
#line 1657 "cg_misc.c"

ILMachineType ILNode_This_ILNode_GenValue__(ILNode_This *node, ILGenInfo * info)
#line 768 "cg_misc.tc"
{
	ILType *type;
	ILMachineType machineType;

	/* Determine the type of the class that we are in */
	if(info->currentClass)
	{
		type = ILClassToType(((ILNode_ClassDefn *)(info->currentClass))
								->classInfo);
	}
	else
	{
		type = ILFindSystemType(info, "Object");
	}

	/* Do we need to unpack a value type instance? */
	if(ILTypeIsValue(type))
	{
		/* Push the managed pointer in "this" onto the stack */
		ILGenSimple(info, IL_OP_LDARG_0);
		ILGenAdjust(info, 1);

		/* Load the value from the managed pointer */
		machineType = ILTypeToMachineType(type);
		ILGenLoadManaged(info, machineType, type);
		return machineType;
	}
	else
	{
		/* We assume that "this" is an object reference in argument 0 */
		ILGenSimple(info, IL_OP_LDARG_0);
		ILGenAdjust(info, 1);
		return ILMachineType_ObjectRef;
	}
}
#line 1696 "cg_misc.c"

void ILNode_This_JavaGenDiscard__(ILNode_This *node, ILGenInfo * info)
#line 158 "jv_misc.tc"
{
	/* Nothing needs to be done here */
}
#line 1703 "cg_misc.c"

ILMachineType ILNode_This_JavaGenValue__(ILNode_This *node, ILGenInfo * info)
#line 390 "jv_misc.tc"
{
	ILType *type;
	ILMachineType machineType;

	/* Push the value of "this" onto the stack */
	JavaGenSimple(info, JAVA_OP_ALOAD_0);
	JavaGenAdjust(info, 1);

	/* Determine the type of the class that we are in */
	if(info->currentClass)
	{
		type = ILClassToType(((ILNode_ClassDefn *)(info->currentClass))
								->classInfo);
	}
	else
	{
		type = ILFindSystemType(info, "Object");
	}
	machineType = ILTypeToMachineType(type);

	/* Do we need to unpack a value type instance? */
	if(ILTypeIsValue(type))
	{
		machineType = JavaUnboxValue(info, ILMachineType_ObjectRef,
					         		 machineType, ILTypeIsEnum(type), 1,
									 ILTypeToClass(info, type));
	}

	/* Done */
	return machineType;
}
#line 1738 "cg_misc.c"

ILMachineType ILNode_This_ILNode_Prepare__(ILNode_This *node, ILGenInfo * info, void * * data1, void * * data2)
#line 808 "cg_misc.tc"
{
	ILMachineType type = ILNode_GetType((ILNode *)node, info);
	ILGenSimple(info, IL_OP_LDARG_0);
	ILGenAdjust(info, 1);
	return type;
}
#line 1748 "cg_misc.c"

ILMachineType ILNode_This_ILNode_GetAndPrepare__(ILNode_This *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 819 "cg_misc.tc"
{
	ILType *type;
	ILMachineType machineType;
	unsigned tempVar;

	/* Determine the type of the class that we are in */
	if(info->currentClass)
	{
		type = ILClassToType(((ILNode_ClassDefn *)(info->currentClass))
								->classInfo);
	}
	else
	{
		type = ILFindSystemType(info, "Object");
	}
	machineType = ILTypeToMachineType(type);

	/* The code to be generated is different for leave and non-leave cases */
	if(leave)
	{
		tempVar = ILGenTempTypedVar(info, type);
		ILGenSimple(info, IL_OP_LDARG_0);
		ILGenAdjust(info, 1);
		ILGenLoadManaged(info, machineType, type);
		ILGenStoreLocal(info, tempVar);
		ILGenLoadLocal(info, tempVar);
		ILGenSimple(info, IL_OP_LDARG_0);
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 2);
		ILGenReleaseTempVar(info, tempVar);
	}
	else
	{
		ILGenSimple(info, IL_OP_LDARG_0);
		ILGenAdjust(info, 1);
		ILGenSimple(info, IL_OP_LDARG_0);
		ILGenAdjust(info, 1);
		ILGenLoadManaged(info, machineType, type);
	}
	return machineType;
}
#line 1793 "cg_misc.c"

void ILNode_This_ILNode_Store__(ILNode_This *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 865 "cg_misc.tc"
{
	ILType *type;
	ILMachineType machineType;
	unsigned tempVar;

	/* Determine the type of the class that we are in */
	if(info->currentClass)
	{
		type = ILClassToType(((ILNode_ClassDefn *)(info->currentClass))
								->classInfo);
	}
	else
	{
		type = ILFindSystemType(info, "Object");
	}
	machineType = ILTypeToMachineType(type);

	/* The code to be generated is different for leave and non-leave cases */
	if(leave)
	{
		tempVar = ILGenTempTypedVar(info, type);
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, tempVar);
		ILGenExtend(info, 1);
		ILGenStoreManaged(info, machineType, type);
		ILGenAdjust(info, -2);
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar);
	}
	else
	{
		ILGenStoreManaged(info, machineType, type);
		ILGenAdjust(info, -2);
	}
}
#line 1833 "cg_misc.c"

void ILNode_This_ILNode_GenRef__(ILNode_This *node, ILGenInfo * info)
#line 906 "cg_misc.tc"
{
	ILGenSimple(info, IL_OP_LDARG_0);
	ILGenAdjust(info, 1);
}
#line 1841 "cg_misc.c"

ILMachineType ILNode_This_JavaPrepare__(ILNode_This *node, ILGenInfo * info, void * * data1, void * * data2)
#line 427 "jv_misc.tc"
{
	return ILMachineType_Void;
}
#line 1848 "cg_misc.c"

ILMachineType ILNode_This_JavaGetAndPrepare__(ILNode_This *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 427 "jv_misc.tc"
{
	return ILMachineType_Void;
}
#line 1855 "cg_misc.c"

void ILNode_This_JavaStore__(ILNode_This *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 431 "jv_misc.tc"
{
}
#line 1861 "cg_misc.c"

struct ILNode_This_vtable__ const ILNode_This_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_This_kind,
	"ILNode_This",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_This_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_This_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_This_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_This_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_This_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_This_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_This_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_This_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_This_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_This_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_This_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_This_JavaStore__,
};

ILMachineType ILNode_Deref_ILNode_GetType__(ILNode_Deref *node, ILGenInfo * info)
#line 323 "cg_misc.tc"
{
	return ILTypeToMachineType(node->elemType);
}
#line 1892 "cg_misc.c"

void ILNode_Deref_ILNode_GenDiscard__(ILNode_Deref *node, ILGenInfo * info)
#line 577 "cg_misc.tc"
{
	/* Evaluate the sub-expression for side effects */
	ILNode_GenDiscard(node->expr, info);
}
#line 1900 "cg_misc.c"

ILMachineType ILNode_Deref_ILNode_GenValue__(ILNode_Deref *node, ILGenInfo * info)
#line 1539 "cg_misc.tc"
{
	ILMachineType machineType;

	/* Evaluate the pointer expression */
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_UnmanagedPtr);

	/* Load the value onto the stack */
	machineType = ILTypeToMachineType(node->elemType);
	ILGenLoadManaged(info, machineType, node->elemType);
	return machineType;
}
#line 1916 "cg_misc.c"

void ILNode_Deref_JavaGenDiscard__(ILNode_Deref *node, ILGenInfo * info)
#line 176 "jv_misc.tc"
{
	/* Evaluate the sub-expression for side effects */
	JavaGenDiscard(node->expr, info);
}
#line 1924 "cg_misc.c"

ILMachineType ILNode_Deref_JavaGenValue__(ILNode_Deref *node, ILGenInfo * info)
#line 546 "jv_misc.tc"
{
	/* TODO */
	return ILMachineType_Void;
}
#line 1932 "cg_misc.c"

ILMachineType ILNode_Deref_ILNode_Prepare__(ILNode_Deref *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2415 "cg_misc.tc"
{
	/* Evaluate the pointer expression */
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_UnmanagedPtr);

	/* Return the machine type for the underlying value */
	return ILTypeToMachineType(node->elemType);
}
#line 1944 "cg_misc.c"

ILMachineType ILNode_Deref_ILNode_GetAndPrepare__(ILNode_Deref *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2515 "cg_misc.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);

	/* Evaluate the pointer expression */
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_UnmanagedPtr);

	/* Should we leave the previous value on the stack afterwards? */
	if(leave)
	{
		unsigned tempVar1 = ILGenTempTypedVar(info, ILType_Int);
		unsigned tempVar2 = ILGenTempTypedVar(info, node->elemType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempVar1);
		ILGenAdjust(info, -1);
		ILGenLoadManaged(info, machineType, node->elemType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempVar2);
		ILGenAdjust(info, -1);
		ILGenLoadLocal(info, tempVar1);
		ILGenAdjust(info, 1);
		ILGenLoadLocal(info, tempVar2);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar1);
		ILGenReleaseTempVar(info, tempVar2);
	}
	else
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenLoadManaged(info, machineType, node->elemType);
	}

	/* Return the machine type for the underlying value */
	return ILTypeToMachineType(node->elemType);
}
#line 1986 "cg_misc.c"

void ILNode_Deref_ILNode_Store__(ILNode_Deref *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2627 "cg_misc.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	if(leave)
	{
		unsigned tempVar = ILGenTempTypedVar(info, node->elemType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempVar);
		ILGenAdjust(info, -1);
		ILGenStoreManaged(info, machineType, node->elemType);
		ILGenAdjust(info, -2);
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar);
	}
	else
	{
		ILGenStoreManaged(info, machineType, node->elemType);
		ILGenAdjust(info, -2);
	}
}
#line 2011 "cg_misc.c"

ILMachineType ILNode_Deref_JavaPrepare__(ILNode_Deref *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2257 "jv_misc.tc"
{
	/* TODO */
	return ILMachineType_Void;
}
#line 2019 "cg_misc.c"

ILMachineType ILNode_Deref_JavaGetAndPrepare__(ILNode_Deref *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2353 "jv_misc.tc"
{
	/* TODO */
	return ILMachineType_Void;
}
#line 2027 "cg_misc.c"

void ILNode_Deref_JavaStore__(ILNode_Deref *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2436 "jv_misc.tc"
{
	/* TODO */
}
#line 2034 "cg_misc.c"

struct ILNode_Deref_vtable__ const ILNode_Deref_vt__ = {
	&ILNode_LValueNoRef_vt__,
	ILNode_Deref_kind,
	"ILNode_Deref",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Deref_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Deref_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Deref_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Deref_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Deref_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_Deref_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_Deref_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_Deref_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRef_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_Deref_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_Deref_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_Deref_JavaStore__,
};

ILMachineType ILNode_AsIs_ILNode_GetType__(ILNode_AsIs *node, ILGenInfo * info)
#line 41 "cg_misc.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 2065 "cg_misc.c"

ILMachineType ILNode_AsIs_ILNode_GenValue__(ILNode_AsIs *node, ILGenInfo * info)
#line 605 "cg_misc.tc"
{
	return ILNode_GenValue(node->expr, info);
}
#line 2072 "cg_misc.c"

void ILNode_AsIs_ILNode_GenThen__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label)
#line 1954 "cg_misc.tc"
{
	ILNode_GenThen(node->expr, info, label);
}
#line 2079 "cg_misc.c"

void ILNode_AsIs_ILNode_GenElse__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label)
#line 1963 "cg_misc.tc"
{
	ILNode_GenElse(node->expr, info, label);
}
#line 2086 "cg_misc.c"

int ILNode_AsIs_ILNode_EvalConst__(ILNode_AsIs *node, ILGenInfo * info, ILEvalValue * value)
#line 2670 "cg_misc.tc"
{
	return ILNode_EvalConst(node->expr, info, value);
}
#line 2093 "cg_misc.c"

ILMachineType ILNode_AsIs_JavaGenValue__(ILNode_AsIs *node, ILGenInfo * info)
#line 214 "jv_misc.tc"
{
	return JavaGenValue(node->expr, info);
}
#line 2100 "cg_misc.c"

void ILNode_AsIs_JavaGenThen__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label)
#line 1781 "jv_misc.tc"
{
	JavaGenThen(node->expr, info, label);
}
#line 2107 "cg_misc.c"

void ILNode_AsIs_JavaGenElse__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label)
#line 1790 "jv_misc.tc"
{
	JavaGenElse(node->expr, info, label);
}
#line 2114 "cg_misc.c"

ILMachineType ILNode_AsIs_ILNode_Prepare__(ILNode_AsIs *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2351 "cg_misc.tc"
{
	return Prepare_SubExpr((ILNode_LValueUnaryExpr *)node, info, data1, data2);
}
#line 2121 "cg_misc.c"

ILMachineType ILNode_AsIs_ILNode_GetAndPrepare__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2450 "cg_misc.tc"
{
	return GetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								 info, leave, data1, data2);
}
#line 2129 "cg_misc.c"

void ILNode_AsIs_ILNode_Store__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2575 "cg_misc.tc"
{
	Store_SubExpr((ILNode_LValueUnaryExpr *)node, info, leave, data1, data2);
}
#line 2136 "cg_misc.c"

ILMachineType ILNode_AsIs_JavaPrepare__(ILNode_AsIs *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2192 "jv_misc.tc"
{
	return JavaPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
							   info, data1, data2);
}
#line 2144 "cg_misc.c"

ILMachineType ILNode_AsIs_JavaGetAndPrepare__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2288 "jv_misc.tc"
{
	return JavaGetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								     info, leave, data1, data2);
}
#line 2152 "cg_misc.c"

void ILNode_AsIs_JavaStore__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2379 "jv_misc.tc"
{
	JavaStore_SubExpr((ILNode_LValueUnaryExpr *)node,
					  info, leave, data1, data2);
}
#line 2160 "cg_misc.c"

struct ILNode_AsIs_vtable__ const ILNode_AsIs_vt__ = {
	&ILNode_LValueNoRefUnaryExpr_vt__,
	ILNode_AsIs_kind,
	"ILNode_AsIs",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_AsIs_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_JavaStore__,
};

ILMachineType ILNode_Overflow_ILNode_GetType__(ILNode_Overflow *node, ILGenInfo * info)
#line 49 "cg_misc.tc"
{
	ILMachineType type;
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	type = ILNode_GetType(node->expr, info);
	info->overflowInsns = oldOverflow;
	return type;
}
#line 2196 "cg_misc.c"

void ILNode_Overflow_ILNode_GenDiscard__(ILNode_Overflow *node, ILGenInfo * info)
#line 425 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	ILNode_GenDiscard(node->expr, info);
	info->overflowInsns = oldOverflow;
}
#line 2206 "cg_misc.c"

ILMachineType ILNode_Overflow_ILNode_GenValue__(ILNode_Overflow *node, ILGenInfo * info)
#line 613 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 1;
	valueType = ILNode_GenValue(node->expr, info);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2218 "cg_misc.c"

void ILNode_Overflow_ILNode_GenThen__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label)
#line 1971 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	ILNode_GenThen(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2228 "cg_misc.c"

void ILNode_Overflow_ILNode_GenElse__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label)
#line 1982 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	ILNode_GenElse(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2238 "cg_misc.c"

int ILNode_Overflow_ILNode_EvalConst__(ILNode_Overflow *node, ILGenInfo * info, ILEvalValue * value)
#line 2678 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	int result;
	info->overflowInsns = 1;
	result = ILNode_EvalConst(node->expr, info, value);
	info->overflowInsns = oldOverflow;
	return result;
}
#line 2250 "cg_misc.c"

int ILNode_Overflow_ILNode_EndsInReturnImpl__(ILNode_Overflow *node, ILGenInfo * info)
#line 2868 "cg_misc.tc"
{
	if(node->expr)
	{
		return ILNode_EndsInReturnImpl(node->expr,info);
	}
	else
	{
		return 2;
	}
}
#line 2264 "cg_misc.c"

void ILNode_Overflow_JavaGenDiscard__(ILNode_Overflow *node, ILGenInfo * info)
#line 34 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	JavaGenDiscard(node->expr, info);
	info->overflowInsns = oldOverflow;
}
#line 2274 "cg_misc.c"

ILMachineType ILNode_Overflow_JavaGenValue__(ILNode_Overflow *node, ILGenInfo * info)
#line 222 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 1;
	valueType = JavaGenValue(node->expr, info);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2286 "cg_misc.c"

void ILNode_Overflow_JavaGenThen__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label)
#line 1798 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	JavaGenThen(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2296 "cg_misc.c"

void ILNode_Overflow_JavaGenElse__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label)
#line 1809 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	JavaGenElse(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2306 "cg_misc.c"

ILMachineType ILNode_Overflow_ILNode_Prepare__(ILNode_Overflow *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2359 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 1;
	valueType = Prepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								info, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2319 "cg_misc.c"

ILMachineType ILNode_Overflow_ILNode_GetAndPrepare__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2459 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 1;
	valueType = GetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								      info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2332 "cg_misc.c"

void ILNode_Overflow_ILNode_Store__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2583 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	Store_SubExpr((ILNode_LValueUnaryExpr *)node, info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
}
#line 2342 "cg_misc.c"

ILMachineType ILNode_Overflow_JavaPrepare__(ILNode_Overflow *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2201 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 1;
	valueType = JavaPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								    info, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2355 "cg_misc.c"

ILMachineType ILNode_Overflow_JavaGetAndPrepare__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2297 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 1;
	valueType = JavaGetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								          info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2368 "cg_misc.c"

void ILNode_Overflow_JavaStore__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2388 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 1;
	JavaStore_SubExpr((ILNode_LValueUnaryExpr *)node,
					  info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
}
#line 2379 "cg_misc.c"

struct ILNode_Overflow_vtable__ const ILNode_Overflow_vt__ = {
	&ILNode_LValueNoRefUnaryExpr_vt__,
	ILNode_Overflow_kind,
	"ILNode_Overflow",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Overflow_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Overflow_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Overflow_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Overflow_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Overflow_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Overflow_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Overflow_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Overflow_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Overflow_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Overflow_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Overflow_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_Overflow_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_Overflow_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_Overflow_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_Overflow_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_Overflow_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_Overflow_JavaStore__,
};

ILMachineType ILNode_NoOverflow_ILNode_GetType__(ILNode_NoOverflow *node, ILGenInfo * info)
#line 62 "cg_misc.tc"
{
	ILMachineType type;
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	type = ILNode_GetType(node->expr, info);
	info->overflowInsns = oldOverflow;
	return type;
}
#line 2415 "cg_misc.c"

void ILNode_NoOverflow_ILNode_GenDiscard__(ILNode_NoOverflow *node, ILGenInfo * info)
#line 436 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	ILNode_GenDiscard(node->expr, info);
	info->overflowInsns = oldOverflow;
}
#line 2425 "cg_misc.c"

ILMachineType ILNode_NoOverflow_ILNode_GenValue__(ILNode_NoOverflow *node, ILGenInfo * info)
#line 626 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 0;
	valueType = ILNode_GenValue(node->expr, info);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2437 "cg_misc.c"

void ILNode_NoOverflow_ILNode_GenThen__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label)
#line 1993 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	ILNode_GenThen(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2447 "cg_misc.c"

void ILNode_NoOverflow_ILNode_GenElse__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label)
#line 2004 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	ILNode_GenElse(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2457 "cg_misc.c"

int ILNode_NoOverflow_ILNode_EvalConst__(ILNode_NoOverflow *node, ILGenInfo * info, ILEvalValue * value)
#line 2691 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	int result;
	info->overflowInsns = 0;
	result = ILNode_EvalConst(node->expr, info, value);
	info->overflowInsns = oldOverflow;
	return result;
}
#line 2469 "cg_misc.c"

int ILNode_NoOverflow_ILNode_EndsInReturnImpl__(ILNode_NoOverflow *node, ILGenInfo * info)
#line 2868 "cg_misc.tc"
{
	if(node->expr)
	{
		return ILNode_EndsInReturnImpl(node->expr,info);
	}
	else
	{
		return 2;
	}
}
#line 2483 "cg_misc.c"

void ILNode_NoOverflow_JavaGenDiscard__(ILNode_NoOverflow *node, ILGenInfo * info)
#line 45 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	JavaGenDiscard(node->expr, info);
	info->overflowInsns = oldOverflow;
}
#line 2493 "cg_misc.c"

ILMachineType ILNode_NoOverflow_JavaGenValue__(ILNode_NoOverflow *node, ILGenInfo * info)
#line 235 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 0;
	valueType = JavaGenValue(node->expr, info);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2505 "cg_misc.c"

void ILNode_NoOverflow_JavaGenThen__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label)
#line 1820 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	JavaGenThen(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2515 "cg_misc.c"

void ILNode_NoOverflow_JavaGenElse__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label)
#line 1831 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	JavaGenElse(node->expr, info, label);
	info->overflowInsns = oldOverflow;
}
#line 2525 "cg_misc.c"

ILMachineType ILNode_NoOverflow_ILNode_Prepare__(ILNode_NoOverflow *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2373 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 0;
	valueType = Prepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								info, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2538 "cg_misc.c"

ILMachineType ILNode_NoOverflow_ILNode_GetAndPrepare__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2473 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 0;
	valueType = GetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								      info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2551 "cg_misc.c"

void ILNode_NoOverflow_ILNode_Store__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2594 "cg_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	Store_SubExpr((ILNode_LValueUnaryExpr *)node, info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
}
#line 2561 "cg_misc.c"

ILMachineType ILNode_NoOverflow_JavaPrepare__(ILNode_NoOverflow *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2215 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 0;
	valueType = JavaPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								    info, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2574 "cg_misc.c"

ILMachineType ILNode_NoOverflow_JavaGetAndPrepare__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2311 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	ILMachineType valueType;
	info->overflowInsns = 0;
	valueType = JavaGetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								          info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
	return valueType;
}
#line 2587 "cg_misc.c"

void ILNode_NoOverflow_JavaStore__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2400 "jv_misc.tc"
{
	int oldOverflow = info->overflowInsns;
	info->overflowInsns = 0;
	JavaStore_SubExpr((ILNode_LValueUnaryExpr *)node,
					  info, leave, data1, data2);
	info->overflowInsns = oldOverflow;
}
#line 2598 "cg_misc.c"

struct ILNode_NoOverflow_vtable__ const ILNode_NoOverflow_vt__ = {
	&ILNode_LValueNoRefUnaryExpr_vt__,
	ILNode_NoOverflow_kind,
	"ILNode_NoOverflow",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NoOverflow_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NoOverflow_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NoOverflow_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoOverflow_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoOverflow_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_NoOverflow_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_NoOverflow_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NoOverflow_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NoOverflow_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoOverflow_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoOverflow_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_NoOverflow_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_NoOverflow_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_NoOverflow_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_NoOverflow_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_NoOverflow_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_NoOverflow_JavaStore__,
};

ILMachineType ILNode_Pedantic_ILNode_GetType__(ILNode_Pedantic *node, ILGenInfo * info)
#line 75 "cg_misc.tc"
{
	ILMachineType type;
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	type = ILNode_GetType(node->expr, info);
	info->pedanticArith = oldPedantic;
	return type;
}
#line 2634 "cg_misc.c"

void ILNode_Pedantic_ILNode_GenDiscard__(ILNode_Pedantic *node, ILGenInfo * info)
#line 447 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	ILNode_GenDiscard(node->expr, info);
	info->pedanticArith = oldPedantic;
}
#line 2644 "cg_misc.c"

ILMachineType ILNode_Pedantic_ILNode_GenValue__(ILNode_Pedantic *node, ILGenInfo * info)
#line 639 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 1;
	valueType = ILNode_GenValue(node->expr, info);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2656 "cg_misc.c"

void ILNode_Pedantic_ILNode_GenThen__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label)
#line 2015 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	ILNode_GenThen(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2666 "cg_misc.c"

void ILNode_Pedantic_ILNode_GenElse__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label)
#line 2026 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	ILNode_GenElse(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2676 "cg_misc.c"

int ILNode_Pedantic_ILNode_EvalConst__(ILNode_Pedantic *node, ILGenInfo * info, ILEvalValue * value)
#line 2704 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	int result;
	info->pedanticArith = 1;
	result = ILNode_EvalConst(node->expr, info, value);
	info->pedanticArith = oldPedantic;
	return result;
}
#line 2688 "cg_misc.c"

int ILNode_Pedantic_ILNode_EndsInReturnImpl__(ILNode_Pedantic *node, ILGenInfo * info)
#line 2868 "cg_misc.tc"
{
	if(node->expr)
	{
		return ILNode_EndsInReturnImpl(node->expr,info);
	}
	else
	{
		return 2;
	}
}
#line 2702 "cg_misc.c"

void ILNode_Pedantic_JavaGenDiscard__(ILNode_Pedantic *node, ILGenInfo * info)
#line 56 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	JavaGenDiscard(node->expr, info);
	info->pedanticArith = oldPedantic;
}
#line 2712 "cg_misc.c"

ILMachineType ILNode_Pedantic_JavaGenValue__(ILNode_Pedantic *node, ILGenInfo * info)
#line 248 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 1;
	valueType = JavaGenValue(node->expr, info);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2724 "cg_misc.c"

void ILNode_Pedantic_JavaGenThen__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label)
#line 1842 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	JavaGenThen(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2734 "cg_misc.c"

void ILNode_Pedantic_JavaGenElse__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label)
#line 1853 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	JavaGenElse(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2744 "cg_misc.c"

ILMachineType ILNode_Pedantic_ILNode_Prepare__(ILNode_Pedantic *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2387 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 1;
	valueType = Prepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								info, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2757 "cg_misc.c"

ILMachineType ILNode_Pedantic_ILNode_GetAndPrepare__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2487 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 1;
	valueType = GetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								      info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2770 "cg_misc.c"

void ILNode_Pedantic_ILNode_Store__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2605 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	Store_SubExpr((ILNode_LValueUnaryExpr *)node, info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
}
#line 2780 "cg_misc.c"

ILMachineType ILNode_Pedantic_JavaPrepare__(ILNode_Pedantic *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2229 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 1;
	valueType = JavaPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								    info, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2793 "cg_misc.c"

ILMachineType ILNode_Pedantic_JavaGetAndPrepare__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2325 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 1;
	valueType = JavaGetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								          info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2806 "cg_misc.c"

void ILNode_Pedantic_JavaStore__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2412 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 1;
	JavaStore_SubExpr((ILNode_LValueUnaryExpr *)node,
					  info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
}
#line 2817 "cg_misc.c"

struct ILNode_Pedantic_vtable__ const ILNode_Pedantic_vt__ = {
	&ILNode_LValueNoRefUnaryExpr_vt__,
	ILNode_Pedantic_kind,
	"ILNode_Pedantic",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Pedantic_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Pedantic_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Pedantic_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Pedantic_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Pedantic_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Pedantic_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Pedantic_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Pedantic_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Pedantic_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Pedantic_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Pedantic_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_Pedantic_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_Pedantic_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_Pedantic_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_Pedantic_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_Pedantic_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_Pedantic_JavaStore__,
};

ILMachineType ILNode_NoPedantic_ILNode_GetType__(ILNode_NoPedantic *node, ILGenInfo * info)
#line 88 "cg_misc.tc"
{
	ILMachineType type;
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	type = ILNode_GetType(node->expr, info);
	info->pedanticArith = oldPedantic;
	return type;
}
#line 2853 "cg_misc.c"

void ILNode_NoPedantic_ILNode_GenDiscard__(ILNode_NoPedantic *node, ILGenInfo * info)
#line 458 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	ILNode_GenDiscard(node->expr, info);
	info->pedanticArith = oldPedantic;
}
#line 2863 "cg_misc.c"

ILMachineType ILNode_NoPedantic_ILNode_GenValue__(ILNode_NoPedantic *node, ILGenInfo * info)
#line 652 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 0;
	valueType = ILNode_GenValue(node->expr, info);
	info->overflowInsns = oldPedantic;
	return valueType;
}
#line 2875 "cg_misc.c"

void ILNode_NoPedantic_ILNode_GenThen__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label)
#line 2037 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	ILNode_GenThen(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2885 "cg_misc.c"

void ILNode_NoPedantic_ILNode_GenElse__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label)
#line 2048 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	ILNode_GenElse(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2895 "cg_misc.c"

int ILNode_NoPedantic_ILNode_EvalConst__(ILNode_NoPedantic *node, ILGenInfo * info, ILEvalValue * value)
#line 2717 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	int result;
	info->pedanticArith = 0;
	result = ILNode_EvalConst(node->expr, info, value);
	info->pedanticArith = oldPedantic;
	return result;
}
#line 2907 "cg_misc.c"

int ILNode_NoPedantic_ILNode_EndsInReturnImpl__(ILNode_NoPedantic *node, ILGenInfo * info)
#line 2868 "cg_misc.tc"
{
	if(node->expr)
	{
		return ILNode_EndsInReturnImpl(node->expr,info);
	}
	else
	{
		return 2;
	}
}
#line 2921 "cg_misc.c"

void ILNode_NoPedantic_JavaGenDiscard__(ILNode_NoPedantic *node, ILGenInfo * info)
#line 67 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	JavaGenDiscard(node->expr, info);
	info->pedanticArith = oldPedantic;
}
#line 2931 "cg_misc.c"

ILMachineType ILNode_NoPedantic_JavaGenValue__(ILNode_NoPedantic *node, ILGenInfo * info)
#line 261 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 0;
	valueType = JavaGenValue(node->expr, info);
	info->overflowInsns = oldPedantic;
	return valueType;
}
#line 2943 "cg_misc.c"

void ILNode_NoPedantic_JavaGenThen__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label)
#line 1864 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	JavaGenThen(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2953 "cg_misc.c"

void ILNode_NoPedantic_JavaGenElse__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label)
#line 1875 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	JavaGenElse(node->expr, info, label);
	info->pedanticArith = oldPedantic;
}
#line 2963 "cg_misc.c"

ILMachineType ILNode_NoPedantic_ILNode_Prepare__(ILNode_NoPedantic *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2401 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 0;
	valueType = Prepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								info, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2976 "cg_misc.c"

ILMachineType ILNode_NoPedantic_ILNode_GetAndPrepare__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2501 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 0;
	valueType = GetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								      info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 2989 "cg_misc.c"

void ILNode_NoPedantic_ILNode_Store__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2616 "cg_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	Store_SubExpr((ILNode_LValueUnaryExpr *)node, info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
}
#line 2999 "cg_misc.c"

ILMachineType ILNode_NoPedantic_JavaPrepare__(ILNode_NoPedantic *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2243 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 0;
	valueType = JavaPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								    info, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 3012 "cg_misc.c"

ILMachineType ILNode_NoPedantic_JavaGetAndPrepare__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2339 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	ILMachineType valueType;
	info->pedanticArith = 0;
	valueType = JavaGetAndPrepare_SubExpr((ILNode_LValueUnaryExpr *)node,
								          info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
	return valueType;
}
#line 3025 "cg_misc.c"

void ILNode_NoPedantic_JavaStore__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2424 "jv_misc.tc"
{
	int oldPedantic = info->pedanticArith;
	info->pedanticArith = 0;
	JavaStore_SubExpr((ILNode_LValueUnaryExpr *)node,
					  info, leave, data1, data2);
	info->pedanticArith = oldPedantic;
}
#line 3036 "cg_misc.c"

struct ILNode_NoPedantic_vtable__ const ILNode_NoPedantic_vt__ = {
	&ILNode_LValueNoRefUnaryExpr_vt__,
	ILNode_NoPedantic_kind,
	"ILNode_NoPedantic",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NoPedantic_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NoPedantic_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NoPedantic_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoPedantic_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoPedantic_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_NoPedantic_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_NoPedantic_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NoPedantic_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NoPedantic_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoPedantic_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NoPedantic_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_NoPedantic_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_NoPedantic_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_NoPedantic_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_NoPedantic_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_NoPedantic_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_NoPedantic_JavaStore__,
};

struct ILNode_MarkType_vtable__ const ILNode_MarkType_vt__ = {
	&ILNode_AsIs_vt__,
	ILNode_MarkType_kind,
	"ILNode_MarkType",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_AsIs_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_JavaStore__,
};

ILMachineType ILNode_CastSimple_ILNode_GetType__(ILNode_CastSimple *node, ILGenInfo * info)
#line 101 "cg_misc.tc"
{
	return node->machineType;
}
#line 3091 "cg_misc.c"

ILMachineType ILNode_CastSimple_ILNode_GenValue__(ILNode_CastSimple *node, ILGenInfo * info)
#line 665 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);
	ILGenCast(info, type, node->machineType);
	return node->machineType;
}
#line 3100 "cg_misc.c"

int ILNode_CastSimple_ILNode_EvalConst__(ILNode_CastSimple *node, ILGenInfo * info, ILEvalValue * value)
#line 2730 "cg_misc.tc"
{
	return (ILNode_EvalConst(node->expr, info, value) &&
		    ILGenCastConst(info, value, value->valueType, node->machineType));
}
#line 3108 "cg_misc.c"

ILMachineType ILNode_CastSimple_JavaGenValue__(ILNode_CastSimple *node, ILGenInfo * info)
#line 274 "jv_misc.tc"
{
	ILMachineType type = JavaGenValue(node->expr, info);
	JavaGenCast(info, type, node->machineType);
	return node->machineType;
}
#line 3117 "cg_misc.c"

struct ILNode_CastSimple_vtable__ const ILNode_CastSimple_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_CastSimple_kind,
	"ILNode_CastSimple",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CastSimple_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CastSimple_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_CastSimple_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CastSimple_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CastType_ILNode_GetType__(ILNode_CastType *node, ILGenInfo * info)
#line 105 "cg_misc.tc"
{
	return ILTypeToMachineType(node->type);
}
#line 3141 "cg_misc.c"

ILMachineType ILNode_CastType_ILNode_GenValue__(ILNode_CastType *node, ILGenInfo * info)
#line 671 "cg_misc.tc"
{
	ILNode_GenValue(node->expr, info);
	ILGenTypeToken(info, IL_OP_CASTCLASS, node->type);
	return ILTypeToMachineType(node->type);
}
#line 3150 "cg_misc.c"

ILMachineType ILNode_CastType_JavaGenValue__(ILNode_CastType *node, ILGenInfo * info)
#line 280 "jv_misc.tc"
{
	ILMachineType type = JavaGenValue(node->expr, info);
	JavaGenTypeRef(info, JAVA_OP_CHECKCAST, node->type);
	JavaGenAdjust(info, -JavaGenTypeSize(type));
	type = ILTypeToMachineType(node->type);
	JavaGenAdjust(info, JavaGenTypeSize(type));
	return type;
}
#line 3162 "cg_misc.c"

struct ILNode_CastType_vtable__ const ILNode_CastType_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_CastType_kind,
	"ILNode_CastType",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CastType_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CastType_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CastType_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserConversion_ILNode_GetType__(ILNode_UserConversion *node, ILGenInfo * info)
#line 113 "cg_misc.tc"
{
	return node->machineType;
}
#line 3186 "cg_misc.c"

ILMachineType ILNode_UserConversion_ILNode_GenValue__(ILNode_UserConversion *node, ILGenInfo * info)
#line 681 "cg_misc.tc"
{
	ILNode_GenValue(node->expr, info);
	ILGenCallByMethod(info, node->method);
	return node->machineType;
}
#line 3195 "cg_misc.c"

ILMachineType ILNode_UserConversion_JavaGenValue__(ILNode_UserConversion *node, ILGenInfo * info)
#line 293 "jv_misc.tc"
{
	JavaGenValue(node->expr, info);
	JavaGenCallByMethod(info, node->method);
	return node->machineType;
}
#line 3204 "cg_misc.c"

struct ILNode_UserConversion_vtable__ const ILNode_UserConversion_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_UserConversion_kind,
	"ILNode_UserConversion",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserConversion_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserConversion_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserConversion_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_AddressOf_ILNode_GetType__(ILNode_AddressOf *node, ILGenInfo * info)
#line 331 "cg_misc.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 3228 "cg_misc.c"

void ILNode_AddressOf_ILNode_GenDiscard__(ILNode_AddressOf *node, ILGenInfo * info)
#line 586 "cg_misc.tc"
{
	/* Evaluate the sub-expression for side effects */
	ILNode_GenDiscard(node->expr, info);
}
#line 3236 "cg_misc.c"

ILMachineType ILNode_AddressOf_ILNode_GenValue__(ILNode_AddressOf *node, ILGenInfo * info)
#line 1556 "cg_misc.tc"
{
	if(yyisa(node->expr, ILNode_LValue) &&
	   !yyisa(node->expr, ILNode_LValueNoRef))
	{
		ILNode_GenRef((ILNode_LValue *)(node->expr), info);
	}
	return ILMachineType_UnmanagedPtr;
}
#line 3248 "cg_misc.c"

void ILNode_AddressOf_JavaGenDiscard__(ILNode_AddressOf *node, ILGenInfo * info)
#line 185 "jv_misc.tc"
{
	/* Evaluate the sub-expression for side effects */
	JavaGenDiscard(node->expr, info);
}
#line 3256 "cg_misc.c"

ILMachineType ILNode_AddressOf_JavaGenValue__(ILNode_AddressOf *node, ILGenInfo * info)
#line 555 "jv_misc.tc"
{
	/* TODO */
	return ILMachineType_Void;
}
#line 3264 "cg_misc.c"

struct ILNode_AddressOf_vtable__ const ILNode_AddressOf_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_AddressOf_kind,
	"ILNode_AddressOf",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AddressOf_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AddressOf_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AddressOf_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AddressOf_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AddressOf_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_ToBool_ILNode_GetType__(ILNode_ToBool *node, ILGenInfo * info)
#line 231 "cg_misc.tc"
{
	return ILMachineType_Boolean;
}
#line 3288 "cg_misc.c"

ILMachineType ILNode_ToBool_ILNode_GenValue__(ILNode_ToBool *node, ILGenInfo * info)
#line 739 "cg_misc.tc"
{
	if(node->trueMethod)
	{
		/* Use a user-supplied "op_True" operator */
		ILNode_GenValue(node->expr, info);
		ILGenCallByMethod(info, node->trueMethod);
	}
	else if(node->falseMethod)
	{
		/* Use a user-supplied "op_False" operator */
		ILNode_GenValue(node->expr, info);
		ILGenCallByMethod(info, node->falseMethod);
		ILGenSimple(info, IL_OP_LDC_I4_0);
		ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
		ILGenExtend(info, 1);
	}
	else
	{
		/* Use a built-in boolean conversion */
		ILGenCast(info, ILNode_GenValue(node->expr, info),
				  ILMachineType_Boolean);
	}
	return ILMachineType_Boolean;
}
#line 3316 "cg_misc.c"

void ILNode_ToBool_ILNode_GenThen__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label)
#line 2217 "cg_misc.tc"
{
	if(node->trueMethod)
	{
		/* Use a user-supplied "op_True" operator */
		ILNode_GenValue(node->expr, info);
		ILGenCallByMethod(info, node->trueMethod);
		ILGenJump(info, IL_OP_BRTRUE, label);
		ILGenAdjust(info, -1);
	}
	else if(node->falseMethod)
	{
		/* Use a user-supplied "op_False" operator */
		ILNode_GenValue(node->expr, info);
		ILGenCallByMethod(info, node->falseMethod);
		ILGenJump(info, IL_OP_BRFALSE, label);
		ILGenAdjust(info, -1);
	}
	else
	{
		/* Use a built-in boolean conversion */
		ILNode_GenThen(node->expr, info, label);
	}
}
#line 3343 "cg_misc.c"

void ILNode_ToBool_ILNode_GenElse__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label)
#line 2245 "cg_misc.tc"
{
	if(node->trueMethod)
	{
		/* Use a user-supplied "op_True" operator */
		ILNode_GenValue(node->expr, info);
		ILGenCallByMethod(info, node->trueMethod);
		ILGenJump(info, IL_OP_BRFALSE, label);
		ILGenAdjust(info, -1);
	}
	else if(node->falseMethod)
	{
		/* Use a user-supplied "op_False" operator */
		ILNode_GenValue(node->expr, info);
		ILGenCallByMethod(info, node->falseMethod);
		ILGenJump(info, IL_OP_BRTRUE, label);
		ILGenAdjust(info, -1);
	}
	else
	{
		/* Use a built-in boolean conversion */
		ILNode_GenElse(node->expr, info, label);
	}
}
#line 3370 "cg_misc.c"

int ILNode_ToBool_ILNode_EvalConst__(ILNode_ToBool *node, ILGenInfo * info, ILEvalValue * value)
#line 2769 "cg_misc.tc"
{
	if(node->trueMethod || node->falseMethod)
	{
		/* Cannot evaluate the use of run-time operators */
		return 0;
	}
	else
	{
		return (ILNode_EvalConst(node->expr, info, value) &&
		        ILGenConstToBoolean(info, value));
	}
}
#line 3386 "cg_misc.c"

ILMachineType ILNode_ToBool_JavaGenValue__(ILNode_ToBool *node, ILGenInfo * info)
#line 351 "jv_misc.tc"
{
	ILMachineType type;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;

	if(node->trueMethod)
	{
		/* Use a user-supplied "op_True" operator */
		type = JavaGenValue(node->expr, info);
		JavaGenCallByMethod(info, node->trueMethod);
		JavaGenAdjust(info, -(JavaGenTypeSize(type) - 1));
	}
	else if(node->falseMethod)
	{
		/* Use a user-supplied "op_False" operator */
		type = JavaGenValue(node->expr, info);
		JavaGenCallByMethod(info, node->falseMethod);
		JavaGenAdjust(info, -(JavaGenTypeSize(type) - 1));
		JavaGenJump(info, JAVA_OP_IFNE, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_1);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_0);
		JavaGenLabel(info, &label2);
	}
	else
	{
		/* Use a built-in boolean conversion */
		JavaGenCast(info, JavaGenValue(node->expr, info),
					ILMachineType_Boolean);
	}

	return ILMachineType_Boolean;
}
#line 3424 "cg_misc.c"

void ILNode_ToBool_JavaGenThen__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label)
#line 2052 "jv_misc.tc"
{
	ILMachineType type;
	if(node->trueMethod)
	{
		/* Use a user-supplied "op_True" operator */
		type = JavaGenValue(node->expr, info);
		JavaGenCallByMethod(info, node->trueMethod);
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -JavaGenTypeSize(type));
	}
	else if(node->falseMethod)
	{
		/* Use a user-supplied "op_False" operator */
		type = JavaGenValue(node->expr, info);
		JavaGenCallByMethod(info, node->falseMethod);
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -JavaGenTypeSize(type));
	}
	else
	{
		/* Use a built-in boolean conversion */
		JavaGenThen(node->expr, info, label);
	}
}
#line 3452 "cg_misc.c"

void ILNode_ToBool_JavaGenElse__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label)
#line 2081 "jv_misc.tc"
{
	ILMachineType type;
	if(node->trueMethod)
	{
		/* Use a user-supplied "op_True" operator */
		type = JavaGenValue(node->expr, info);
		JavaGenCallByMethod(info, node->trueMethod);
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -JavaGenTypeSize(type));
	}
	else if(node->falseMethod)
	{
		/* Use a user-supplied "op_False" operator */
		type = JavaGenValue(node->expr, info);
		JavaGenCallByMethod(info, node->falseMethod);
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -JavaGenTypeSize(type));
	}
	else
	{
		/* Use a built-in boolean conversion */
		JavaGenElse(node->expr, info, label);
	}
}
#line 3480 "cg_misc.c"

struct ILNode_ToBool_vtable__ const ILNode_ToBool_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_ToBool_kind,
	"ILNode_ToBool",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToBool_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToBool_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToBool_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToBool_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_ToBool_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToBool_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToBool_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToBool_JavaGenElse__,
};

ILMachineType ILNode_ToConst_ILNode_GetType__(ILNode_ToConst *node, ILGenInfo * info)
#line 41 "cg_misc.tc"
{
	return ILNode_GetType(node->expr, info);
}
#line 3504 "cg_misc.c"

ILMachineType ILNode_ToConst_ILNode_GenValue__(ILNode_ToConst *node, ILGenInfo * info)
#line 605 "cg_misc.tc"
{
	return ILNode_GenValue(node->expr, info);
}
#line 3511 "cg_misc.c"

void ILNode_ToConst_ILNode_GenThen__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label)
#line 1954 "cg_misc.tc"
{
	ILNode_GenThen(node->expr, info, label);
}
#line 3518 "cg_misc.c"

void ILNode_ToConst_ILNode_GenElse__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label)
#line 1963 "cg_misc.tc"
{
	ILNode_GenElse(node->expr, info, label);
}
#line 3525 "cg_misc.c"

int ILNode_ToConst_ILNode_EvalConst__(ILNode_ToConst *node, ILGenInfo * info, ILEvalValue * value)
#line 2670 "cg_misc.tc"
{
	return ILNode_EvalConst(node->expr, info, value);
}
#line 3532 "cg_misc.c"

ILMachineType ILNode_ToConst_JavaGenValue__(ILNode_ToConst *node, ILGenInfo * info)
#line 214 "jv_misc.tc"
{
	return JavaGenValue(node->expr, info);
}
#line 3539 "cg_misc.c"

void ILNode_ToConst_JavaGenThen__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label)
#line 1781 "jv_misc.tc"
{
	JavaGenThen(node->expr, info, label);
}
#line 3546 "cg_misc.c"

void ILNode_ToConst_JavaGenElse__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label)
#line 1790 "jv_misc.tc"
{
	JavaGenElse(node->expr, info, label);
}
#line 3553 "cg_misc.c"

struct ILNode_ToConst_vtable__ const ILNode_ToConst_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_ToConst_kind,
	"ILNode_ToConst",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToConst_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToConst_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_ToConst_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToConst_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_JavaGenElse__,
};

ILMachineType ILNode_VarArgExpand_ILNode_GetType__(ILNode_VarArgExpand *node, ILGenInfo * info)
#line 274 "cg_misc.tc"
{
	/* This will never be called, but we have to return something */
	return ILMachineType_Void;
}
#line 3578 "cg_misc.c"

ILMachineType ILNode_VarArgExpand_ILNode_GenValue__(ILNode_VarArgExpand *node, ILGenInfo * info)
#line 936 "cg_misc.tc"
{
	/* Expand to the list of arguments */
	if(node->expr)
	{
		ILNode_GenValue(node->expr, info);
	}
	return ILMachineType_Void;
}
#line 3590 "cg_misc.c"

ILMachineType ILNode_VarArgExpand_JavaGenValue__(ILNode_VarArgExpand *node, ILGenInfo * info)
#line 456 "jv_misc.tc"
{
	/* Not used with Java - this should never be called */
	return ILMachineType_Void;
}
#line 3598 "cg_misc.c"

struct ILNode_VarArgExpand_vtable__ const ILNode_VarArgExpand_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_VarArgExpand_kind,
	"ILNode_VarArgExpand",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VarArgExpand_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VarArgExpand_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VarArgExpand_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_IsNull_ILNode_GetType__(ILNode_IsNull *node, ILGenInfo * info)
#line 365 "cg_misc.tc"
{
	return ILMachineType_Boolean;
}
#line 3622 "cg_misc.c"

void ILNode_IsNull_ILNode_GenDiscard__(ILNode_IsNull *node, ILGenInfo * info)
#line 568 "cg_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	ILNode_GenDiscard(node->expr, info);
}
#line 3630 "cg_misc.c"

ILMachineType ILNode_IsNull_ILNode_GenValue__(ILNode_IsNull *node, ILGenInfo * info)
#line 1821 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);
	if(type == ILMachineType_UnmanagedPtr ||
	   type == ILMachineType_NativeInt ||
	   type == ILMachineType_NativeUInt)
	{
		ILGenIntNative(info, 0);
	}
	else
	{
		ILGenCast(info, type, ILMachineType_ObjectRef);
		ILGenSimple(info, IL_OP_LDNULL);
	}
	ILGenAdjust(info, 1);
	ILGenSimple(info, IL_PREFIX_OP_CEQ + IL_OP_PREFIX);
	ILGenAdjust(info, -1);
	return ILMachineType_Boolean;
}
#line 3652 "cg_misc.c"

void ILNode_IsNull_ILNode_GenThen__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label)
#line 2296 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);
	if(type != ILMachineType_UnmanagedPtr &&
	   type != ILMachineType_NativeInt &&
	   type != ILMachineType_NativeUInt)
	{
		ILGenCast(info, type, ILMachineType_ObjectRef);
	}
	ILGenJump(info, IL_OP_BRFALSE, label);
	ILGenAdjust(info, -1);
}
#line 3667 "cg_misc.c"

void ILNode_IsNull_ILNode_GenElse__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label)
#line 2313 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);
	if(type != ILMachineType_UnmanagedPtr &&
	   type != ILMachineType_NativeInt &&
	   type != ILMachineType_NativeUInt)
	{
		ILGenCast(info, type, ILMachineType_ObjectRef);
	}
	ILGenJump(info, IL_OP_BRTRUE, label);
	ILGenAdjust(info, -1);
}
#line 3682 "cg_misc.c"

void ILNode_IsNull_JavaGenDiscard__(ILNode_IsNull *node, ILGenInfo * info)
#line 195 "jv_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	JavaGenDiscard(node->expr, info);
}
#line 3690 "cg_misc.c"

ILMachineType ILNode_IsNull_JavaGenValue__(ILNode_IsNull *node, ILGenInfo * info)
#line 1705 "jv_misc.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCast(info, JavaGenValue(node->expr, info),
				ILMachineType_ObjectRef);
	JavaGenJump(info, JAVA_OP_IFNULL, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenLabel(info, &label2);
	return ILMachineType_Boolean;
}
#line 3707 "cg_misc.c"

void ILNode_IsNull_JavaGenThen__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label)
#line 2147 "jv_misc.tc"
{
	JavaGenCast(info, JavaGenValue(node->expr, info),
				ILMachineType_ObjectRef);
	JavaGenJump(info, JAVA_OP_IFNULL, label);
	JavaGenAdjust(info, -1);
}
#line 3717 "cg_misc.c"

void ILNode_IsNull_JavaGenElse__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label)
#line 2159 "jv_misc.tc"
{
	JavaGenCast(info, JavaGenValue(node->expr, info),
				ILMachineType_ObjectRef);
	JavaGenJump(info, JAVA_OP_IFNONNULL, label);
	JavaGenAdjust(info, -1);
}
#line 3727 "cg_misc.c"

struct ILNode_IsNull_vtable__ const ILNode_IsNull_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_IsNull_kind,
	"ILNode_IsNull",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNull_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNull_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNull_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNull_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNull_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNull_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNull_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNull_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNull_JavaGenElse__,
};

ILMachineType ILNode_IsNonNull_ILNode_GetType__(ILNode_IsNonNull *node, ILGenInfo * info)
#line 365 "cg_misc.tc"
{
	return ILMachineType_Boolean;
}
#line 3751 "cg_misc.c"

void ILNode_IsNonNull_ILNode_GenDiscard__(ILNode_IsNonNull *node, ILGenInfo * info)
#line 568 "cg_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	ILNode_GenDiscard(node->expr, info);
}
#line 3759 "cg_misc.c"

ILMachineType ILNode_IsNonNull_ILNode_GenValue__(ILNode_IsNonNull *node, ILGenInfo * info)
#line 1844 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);
	if(type == ILMachineType_UnmanagedPtr ||
	   type == ILMachineType_NativeInt ||
	   type == ILMachineType_NativeUInt)
	{
		ILGenIntNative(info, 0);
	}
	else
	{
		ILGenCast(info, type, ILMachineType_ObjectRef);
		ILGenSimple(info, IL_OP_LDNULL);
	}
	ILGenAdjust(info, 1);
	ILGenSimple(info, IL_PREFIX_OP_CEQ + IL_OP_PREFIX);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
	ILGenAdjust(info, -1);
	return ILMachineType_Boolean;
}
#line 3783 "cg_misc.c"

void ILNode_IsNonNull_ILNode_GenThen__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label)
#line 2313 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);
	if(type != ILMachineType_UnmanagedPtr &&
	   type != ILMachineType_NativeInt &&
	   type != ILMachineType_NativeUInt)
	{
		ILGenCast(info, type, ILMachineType_ObjectRef);
	}
	ILGenJump(info, IL_OP_BRTRUE, label);
	ILGenAdjust(info, -1);
}
#line 3798 "cg_misc.c"

void ILNode_IsNonNull_ILNode_GenElse__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label)
#line 2296 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);
	if(type != ILMachineType_UnmanagedPtr &&
	   type != ILMachineType_NativeInt &&
	   type != ILMachineType_NativeUInt)
	{
		ILGenCast(info, type, ILMachineType_ObjectRef);
	}
	ILGenJump(info, IL_OP_BRFALSE, label);
	ILGenAdjust(info, -1);
}
#line 3813 "cg_misc.c"

void ILNode_IsNonNull_JavaGenDiscard__(ILNode_IsNonNull *node, ILGenInfo * info)
#line 195 "jv_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	JavaGenDiscard(node->expr, info);
}
#line 3821 "cg_misc.c"

ILMachineType ILNode_IsNonNull_JavaGenValue__(ILNode_IsNonNull *node, ILGenInfo * info)
#line 1723 "jv_misc.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCast(info, JavaGenValue(node->expr, info),
				ILMachineType_ObjectRef);
	JavaGenJump(info, JAVA_OP_IFNONNULL, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenLabel(info, &label2);
	return ILMachineType_Boolean;
}
#line 3838 "cg_misc.c"

void ILNode_IsNonNull_JavaGenThen__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label)
#line 2159 "jv_misc.tc"
{
	JavaGenCast(info, JavaGenValue(node->expr, info),
				ILMachineType_ObjectRef);
	JavaGenJump(info, JAVA_OP_IFNONNULL, label);
	JavaGenAdjust(info, -1);
}
#line 3848 "cg_misc.c"

void ILNode_IsNonNull_JavaGenElse__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label)
#line 2147 "jv_misc.tc"
{
	JavaGenCast(info, JavaGenValue(node->expr, info),
				ILMachineType_ObjectRef);
	JavaGenJump(info, JAVA_OP_IFNULL, label);
	JavaGenAdjust(info, -1);
}
#line 3858 "cg_misc.c"

struct ILNode_IsNonNull_vtable__ const ILNode_IsNonNull_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_IsNonNull_kind,
	"ILNode_IsNonNull",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNonNull_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNonNull_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNonNull_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNonNull_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNonNull_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNonNull_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IsNonNull_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNonNull_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_IsNonNull_JavaGenElse__,
};

ILMachineType ILNode_MakeRefAny_ILNode_GetType__(ILNode_MakeRefAny *node, ILGenInfo * info)
#line 373 "cg_misc.tc"
{
	/* The result is an instance of "System.TypedReference" */
	return ILMachineType_ManagedValue;
}
#line 3883 "cg_misc.c"

ILMachineType ILNode_MakeRefAny_ILNode_GenValue__(ILNode_MakeRefAny *node, ILGenInfo * info)
#line 1869 "cg_misc.tc"
{
	/* Get the address of the supplied l-value */
	ILNode_GenRef(node->expr, info);

	/* Convert the address into a typedref */
	ILGenTypeToken(info, IL_OP_MKREFANY, node->type);

	/* The result is always a typedref */
	return ILMachineType_ManagedValue;
}
#line 3897 "cg_misc.c"

ILMachineType ILNode_MakeRefAny_JavaGenValue__(ILNode_MakeRefAny *node, ILGenInfo * info)
#line 1743 "jv_misc.tc"
{
	/* Not supported for Java output */
	return ILNode_GetType(node, info);
}
#line 3905 "cg_misc.c"

struct ILNode_MakeRefAny_vtable__ const ILNode_MakeRefAny_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_MakeRefAny_kind,
	"ILNode_MakeRefAny",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MakeRefAny_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MakeRefAny_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MakeRefAny_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_RefType_ILNode_GetType__(ILNode_RefType *node, ILGenInfo * info)
#line 382 "cg_misc.tc"
{
	/* The result is an instance of "System.RuntimeTypeHandle" */
	return ILMachineType_ManagedValue;
}
#line 3930 "cg_misc.c"

ILMachineType ILNode_RefType_ILNode_GenValue__(ILNode_RefType *node, ILGenInfo * info)
#line 1884 "cg_misc.tc"
{
	/* Generate the value of the typedref sub-expression */
	ILNode_GenValue(node->expr, info);

	/* Convert the typedref into a type handle */
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_REFANYTYPE);

	/* Convert the type handle into a type object */
	ILGenCallByName(info,
			"class [.library]System.Type "
				"[.library]System.Type::GetTypeFromHandle"
				"(valuetype [.library]System.RuntimeTypeHandle)");

	/* The result is an instance of "System.Type" */
	return ILMachineType_ObjectRef;
}
#line 3950 "cg_misc.c"

ILMachineType ILNode_RefType_JavaGenValue__(ILNode_RefType *node, ILGenInfo * info)
#line 1743 "jv_misc.tc"
{
	/* Not supported for Java output */
	return ILNode_GetType(node, info);
}
#line 3958 "cg_misc.c"

struct ILNode_RefType_vtable__ const ILNode_RefType_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_RefType_kind,
	"ILNode_RefType",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefType_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefType_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefType_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_ArrayLength_ILNode_GetType__(ILNode_ArrayLength *node, ILGenInfo * info)
#line 399 "cg_misc.tc"
{
	return ILMachineType_NativeInt;
}
#line 3982 "cg_misc.c"

ILMachineType ILNode_ArrayLength_ILNode_GenValue__(ILNode_ArrayLength *node, ILGenInfo * info)
#line 1925 "cg_misc.tc"
{
	ILNode_GenValue(node->expr, info);
	ILGenSimple(info, IL_OP_LDLEN);
	return ILMachineType_NativeInt;
}
#line 3991 "cg_misc.c"

ILMachineType ILNode_ArrayLength_JavaGenValue__(ILNode_ArrayLength *node, ILGenInfo * info)
#line 1752 "jv_misc.tc"
{
	JavaGenValue(node->expr, info);
	JavaGenSimple(info, JAVA_OP_ARRAYLENGTH);
	return ILMachineType_NativeInt;
}
#line 4000 "cg_misc.c"

struct ILNode_ArrayLength_vtable__ const ILNode_ArrayLength_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_ArrayLength_kind,
	"ILNode_ArrayLength",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayLength_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayLength_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayLength_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Comma_ILNode_GetType__(ILNode_Comma *node, ILGenInfo * info)
#line 32 "cg_misc.tc"
{
	return ILNode_GetType(node->expr2, info);
}
#line 4024 "cg_misc.c"

void ILNode_Comma_ILNode_GenDiscard__(ILNode_Comma *node, ILGenInfo * info)
#line 408 "cg_misc.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 4032 "cg_misc.c"

ILMachineType ILNode_Comma_ILNode_GenValue__(ILNode_Comma *node, ILGenInfo * info)
#line 595 "cg_misc.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	return ILNode_GenValue(node->expr2, info);
}
#line 4040 "cg_misc.c"

void ILNode_Comma_ILNode_GenThen__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label)
#line 1935 "cg_misc.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenThen(node->expr2, info, label);
}
#line 4048 "cg_misc.c"

void ILNode_Comma_ILNode_GenElse__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label)
#line 1944 "cg_misc.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenElse(node->expr2, info, label);
}
#line 4056 "cg_misc.c"

int ILNode_Comma_ILNode_EvalConst__(ILNode_Comma *node, ILGenInfo * info, ILEvalValue * value)
#line 2653 "cg_misc.tc"
{
	/* The first sub-expression must be constant,
	   but we don't care about its value */
	if(!ILNode_EvalConst(node->expr1, info, value))
	{
		return 0;
	}

	/* Evaluate the value of the second sub-expression */
	return ILNode_EvalConst(node->expr2, info, value);
}
#line 4071 "cg_misc.c"

void ILNode_Comma_JavaGenDiscard__(ILNode_Comma *node, ILGenInfo * info)
#line 25 "jv_misc.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 4079 "cg_misc.c"

ILMachineType ILNode_Comma_JavaGenValue__(ILNode_Comma *node, ILGenInfo * info)
#line 204 "jv_misc.tc"
{
	JavaGenDiscard(node->expr1, info);
	return JavaGenValue(node->expr2, info);
}
#line 4087 "cg_misc.c"

void ILNode_Comma_JavaGenThen__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label)
#line 1762 "jv_misc.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenThen(node->expr2, info, label);
}
#line 4095 "cg_misc.c"

void ILNode_Comma_JavaGenElse__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label)
#line 1771 "jv_misc.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenElse(node->expr2, info, label);
}
#line 4103 "cg_misc.c"

struct ILNode_Comma_vtable__ const ILNode_Comma_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_Comma_kind,
	"ILNode_Comma",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Comma_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Comma_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Comma_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Comma_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Comma_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Comma_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Comma_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Comma_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Comma_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Comma_JavaGenElse__,
};

ILMachineType ILNode_ArgList_ILNode_GetType__(ILNode_ArgList *node, ILGenInfo * info)
#line 256 "cg_misc.tc"
{
	/* This will never be called, but we have to return something */
	return ILMachineType_Void;
}
#line 4128 "cg_misc.c"

void ILNode_ArgList_ILNode_GenDiscard__(ILNode_ArgList *node, ILGenInfo * info)
#line 408 "cg_misc.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 4136 "cg_misc.c"

ILMachineType ILNode_ArgList_ILNode_GenValue__(ILNode_ArgList *node, ILGenInfo * info)
#line 915 "cg_misc.tc"
{
	ILNode_GenValue(node->expr1, info);
	return ILNode_GenValue(node->expr2, info);
}
#line 4144 "cg_misc.c"

ILMachineType ILNode_ArgList_JavaGenValue__(ILNode_ArgList *node, ILGenInfo * info)
#line 438 "jv_misc.tc"
{
	JavaGenValue(node->expr1, info);
	return JavaGenValue(node->expr2, info);
}
#line 4152 "cg_misc.c"

struct ILNode_ArgList_vtable__ const ILNode_ArgList_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_ArgList_kind,
	"ILNode_ArgList",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgList_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgList_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgList_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgList_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_RefValue_ILNode_GetType__(ILNode_RefValue *node, ILGenInfo * info)
#line 391 "cg_misc.tc"
{
	return ILTypeToMachineType(node->type);
}
#line 4176 "cg_misc.c"

ILMachineType ILNode_RefValue_ILNode_GenValue__(ILNode_RefValue *node, ILGenInfo * info)
#line 1905 "cg_misc.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->type);

	/* Generate the value of the typedref sub-expression */
	ILNode_GenValue(node->expr1, info);

	/* Convert the typedref into a managed pointer of the correct type */
	ILGenTypeToken(info, IL_OP_REFANYVAL, node->type);

	/* Load the value from the pointer */
	ILGenLoadManaged(info, machineType, node->type);

	/* Return the value's machine type to the caller */
	return machineType;
}
#line 4195 "cg_misc.c"

ILMachineType ILNode_RefValue_JavaGenValue__(ILNode_RefValue *node, ILGenInfo * info)
#line 1743 "jv_misc.tc"
{
	/* Not supported for Java output */
	return ILNode_GetType(node, info);
}
#line 4203 "cg_misc.c"

struct ILNode_RefValue_vtable__ const ILNode_RefValue_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_RefValue_kind,
	"ILNode_RefValue",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefValue_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefValue_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefValue_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_InvocationExpression_ILNode_GetType__(ILNode_InvocationExpression *node, ILGenInfo * info)
#line 157 "cg_misc.tc"
{
	if(node->methodInfo)
	{
		return ILTypeToMachineType
			(ILTypeGetReturn(ILMethod_Signature(node->methodInfo)));
	}
	else if(node->callSiteSig)
	{
		return ILTypeToMachineType(ILTypeGetReturn(node->callSiteSig));
	}
	else
	{
		return ILMachineType_Void;
	}
}
#line 4239 "cg_misc.c"

ILMachineType ILNode_InvocationExpression_ILNode_GenValue__(ILNode_InvocationExpression *node, ILGenInfo * info)
#line 1397 "cg_misc.tc"
{
	ILMachineType resultType;
	long saveStack;
	unsigned thisTemp;

	/* Save the current stack height, so we know where to
	   unwind to when popping the arguments */
	saveStack = info->stackHeight;

	/* Push the "this" expression if necessary */
	thisTemp = ILGenPrepareForThisAccess
			(info, node->thisExpr,
			 (node->methodInfo ? ILMethod_Owner(node->methodInfo) : 0), 0);

	/* Push the argument expressions */
	if(node->expr2)
	{
		ILNode_GenValue(node->expr2, info);
	}

	/* Invoke the method */
	if(node->methodInfo)
	{
		if(!ILMethod_IsStatic(node->methodInfo) &&
		   !ILClassIsValueType(ILMethod_Owner(node->methodInfo)) &&
		   !(node->baseCall))
		{
			ILGenCallVirtByMethodSig(info, node->methodInfo, node->callSiteSig);
		}
		else
		{
			ILGenCallByMethodSig(info, node->methodInfo, node->callSiteSig);
		}
		resultType = ILTypeToMachineType
			(ILTypeGetReturn(ILMethod_Signature(node->methodInfo)));
	}
	else
	{
		resultType = ILMachineType_Void;
	}

	/* Re-adjust the stack to remove the arguments */
	if(resultType == ILMachineType_Void)
	{
		info->stackHeight = saveStack;
	}
	else
	{
		info->stackHeight = saveStack + 1;
		if(info->stackHeight > info->maxStackHeight)
		{
			info->maxStackHeight = info->stackHeight;
		}
	}

	/* Release the temporary local variable if necessary */
	ILGenFreeThisVar(info, thisTemp);

	/* Done */
	return resultType;
}
#line 4304 "cg_misc.c"

ILMachineType ILNode_InvocationExpression_JavaGenValue__(ILNode_InvocationExpression *node, ILGenInfo * info)
#line 1615 "jv_misc.tc"
{
	ILMachineType resultType;
	long saveStack;

	/* Save the current stack height, so we know where to
	   unwind to when popping the arguments */
	saveStack = info->stackHeight;

	/* Push the "this" expression if necessary */
	if(node->thisExpr && node->methodInfo)
	{
		JavaPrepareForThisAccess(info, node->thisExpr,
								 ILMethod_Owner(node->methodInfo));
	}

	/* Push the argument expressions */
	if(node->expr2)
	{
		JavaGenValue(node->expr2, info);
	}

	/* Invoke the method */
	if(node->methodInfo)
	{
 		if(node->baseCall)
 		{
 			JavaGenCallSpecialByMethod(info,node->methodInfo);
 		}
 		else
 		{
 			JavaGenCallMethod(info, node->methodInfo, saveStack);
 		}
		resultType = ILTypeToMachineType
			(ILTypeGetReturn(ILMethod_Signature(node->methodInfo)));
	}
	else
	{
		resultType = ILMachineType_Void;
	}

	/* Re-adjust the stack to remove the arguments */
	if(resultType == ILMachineType_Void)
	{
		info->stackHeight = saveStack;
	}
	else
	{
		info->stackHeight = saveStack + JavaGenTypeSize(resultType);
		if(info->stackHeight > info->maxStackHeight)
		{
			info->maxStackHeight = info->stackHeight;
		}
	}

	/* Done */
	return resultType;
}
#line 4365 "cg_misc.c"

struct ILNode_InvocationExpression_vtable__ const ILNode_InvocationExpression_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_InvocationExpression_kind,
	"ILNode_InvocationExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_InvocationExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_InvocationExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_InvocationExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Conditional_ILNode_GetType__(ILNode_Conditional *node, ILGenInfo * info)
#line 222 "cg_misc.tc"
{
	ILMachineType type1, type2;
	return Conditional_Type(node, info, &type1, &type2);
}
#line 4390 "cg_misc.c"

void ILNode_Conditional_ILNode_GenDiscard__(ILNode_Conditional *node, ILGenInfo * info)
#line 469 "cg_misc.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILEvalValue value;

	/* Determine the common type to use for the cases */
	commonType = Conditional_Type(node, info, &type1, &type2);

	/* Generate the discard code.  We must generate as value if the
	   final type is different because an exception might occur during
	   the type conversion.  If we optimize away the conversion, then
	   the final code might have different behaviour */
	if(ILNode_EvalConst(node->expr1, info, &value) &&
	   ILGenConstToBoolean(info, &value))
	{
		/* The condition is constant, so generate only the case we need */
		if(value.un.i4Value)
		{
			if(type1 == commonType)
			{
				ILNode_GenDiscard(node->expr2, info);
			}
			else
			{
				ILNode_GenValue(node->expr2, info);
				ILGenCast(info, type1, commonType);
				ILGenCast(info, commonType, ILMachineType_Void);
			}
		}
		else
		{
			if(type2 == commonType)
			{
				ILNode_GenDiscard(node->expr3, info);
			}
			else
			{
				ILNode_GenValue(node->expr3, info);
				ILGenCast(info, type2, commonType);
				ILGenCast(info, commonType, ILMachineType_Void);
			}
		}
	}
	else
	{
		/* We need the general case of the conditional */
		ILNode_GenElse(node->expr1, info, &label1);
		if(type1 == commonType)
		{
			ILNode_GenDiscard(node->expr2, info);
		}
		else
		{
			ILNode_GenValue(node->expr2, info);
			ILGenCast(info, type1, commonType);
			ILGenCast(info, commonType, ILMachineType_Void);
		}
		ILGenJump(info, IL_OP_BR, &label2);
		ILGenLabel(info, &label1);
		if(type2 == commonType)
		{
			ILNode_GenDiscard(node->expr3, info);
		}
		else
		{
			ILNode_GenValue(node->expr3, info);
			ILGenCast(info, type2, commonType);
			ILGenCast(info, commonType, ILMachineType_Void);
		}
		ILGenLabel(info, &label2);
	}
}
#line 4469 "cg_misc.c"

ILMachineType ILNode_Conditional_ILNode_GenValue__(ILNode_Conditional *node, ILGenInfo * info)
#line 691 "cg_misc.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILEvalValue value;

	/* Determine the common type to use for the cases */
	commonType = Conditional_Type(node, info, &type1, &type2);

	/* If the condition is constant, then only generate the case we need */
	if(ILNode_EvalConst(node->expr1, info, &value) &&
	   ILGenConstToBoolean(info, &value))
	{
		if(value.un.i4Value)
		{
			ILNode_GenValue(node->expr2, info);
			ILGenCast(info, type1, commonType);
		}
		else
		{
			ILNode_GenValue(node->expr3, info);
			ILGenCast(info, type2, commonType);
		}
	}
	else
	{
		/* Generate the full case of the conditional */
		int height;
		ILNode_GenElse(node->expr1, info, &label1);
		height = info->stackHeight;
		ILGenCast(info, ILNode_GenValue(node->expr2, info), commonType);
		info->stackHeight = height;
		ILGenJump(info, IL_OP_BR, &label2);
		ILGenLabel(info, &label1);
		ILGenCast(info, ILNode_GenValue(node->expr3, info), commonType);
		ILGenLabel(info, &label2);
	}

	/* The common type is the final type */
	return commonType;
}
#line 4516 "cg_misc.c"

void ILNode_Conditional_ILNode_GenThen__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label)
#line 2201 "cg_misc.tc"
{
	ConditionalBranch(node, info, label, 1);
}
#line 4523 "cg_misc.c"

void ILNode_Conditional_ILNode_GenElse__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label)
#line 2209 "cg_misc.tc"
{
	ConditionalBranch(node, info, label, 0);
}
#line 4530 "cg_misc.c"

int ILNode_Conditional_ILNode_EvalConst__(ILNode_Conditional *node, ILGenInfo * info, ILEvalValue * value)
#line 2739 "cg_misc.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Determine the common type to use for the cases */
	commonType = Conditional_Type(node, info, &type1, &type2);

	/* Evaluate the constant value of the node */
	if(!ILNode_EvalConst(node->expr1, info, value) ||
	   !ILGenConstToBoolean(info, value))
	{
		return 0;
	}
	if(value->un.i4Value)
	{
		return (ILNode_EvalConst(node->expr2, info, value) &&
				ILGenCastConst(info, value, value->valueType, commonType));
	}
	else
	{
		return (ILNode_EvalConst(node->expr3, info, value) &&
				ILGenCastConst(info, value, value->valueType, commonType));
	}
}
#line 4559 "cg_misc.c"

void ILNode_Conditional_JavaGenDiscard__(ILNode_Conditional *node, ILGenInfo * info)
#line 78 "jv_misc.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILEvalValue value;

	/* Determine the common type to use for the cases */
	commonType = Conditional_Type(node, info, &type1, &type2);

	/* Generate the discard code.  We must generate as value if the
	   final type is different because an exception might occur during
	   the type conversion.  If we optimize away the conversion, then
	   the final code might have different behaviour */
	if(ILNode_EvalConst(node->expr1, info, &value) &&
	   ILGenConstToBoolean(info, &value))
	{
		/* The condition is constant, so generate only the case we need */
		if(value.un.i4Value)
		{
			if(type1 == commonType)
			{
				JavaGenDiscard(node->expr2, info);
			}
			else
			{
				JavaGenValue(node->expr2, info);
				JavaGenCast(info, type1, commonType);
				JavaGenCast(info, commonType, ILMachineType_Void);
			}
		}
		else
		{
			if(type2 == commonType)
			{
				JavaGenDiscard(node->expr3, info);
			}
			else
			{
				JavaGenValue(node->expr3, info);
				JavaGenCast(info, type2, commonType);
				JavaGenCast(info, commonType, ILMachineType_Void);
			}
		}
	}
	else
	{
		/* We need the general case of the conditional */
		JavaGenElse(node->expr1, info, &label1);
		if(type1 == commonType)
		{
			JavaGenDiscard(node->expr2, info);
		}
		else
		{
			JavaGenValue(node->expr2, info);
			JavaGenCast(info, type1, commonType);
			JavaGenCast(info, commonType, ILMachineType_Void);
		}
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		if(type2 == commonType)
		{
			JavaGenDiscard(node->expr3, info);
		}
		else
		{
			JavaGenValue(node->expr3, info);
			JavaGenCast(info, type2, commonType);
			JavaGenCast(info, commonType, ILMachineType_Void);
		}
		JavaGenLabel(info, &label2);
	}
}
#line 4638 "cg_misc.c"

ILMachineType ILNode_Conditional_JavaGenValue__(ILNode_Conditional *node, ILGenInfo * info)
#line 303 "jv_misc.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILEvalValue value;

	/* Determine the common type to use for the cases */
	commonType = Conditional_Type(node, info, &type1, &type2);

	/* If the condition is constant, then only generate the case we need */
	if(ILNode_EvalConst(node->expr1, info, &value) &&
	   ILGenConstToBoolean(info, &value))
	{
		if(value.un.i4Value)
		{
			JavaGenValue(node->expr2, info);
			JavaGenCast(info, type1, commonType);
		}
		else
		{
			JavaGenValue(node->expr3, info);
			JavaGenCast(info, type2, commonType);
		}
	}
	else
	{
		/* Generate the full case of the conditional */
		int height;
		JavaGenElse(node->expr1, info, &label1);
		height = info->stackHeight;
		JavaGenCast(info, JavaGenValue(node->expr2, info), commonType);
		info->stackHeight = height;
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenCast(info, JavaGenValue(node->expr3, info), commonType);
		JavaGenLabel(info, &label2);
	}

	/* The common type is the final type */
	return commonType;
}
#line 4685 "cg_misc.c"

void ILNode_Conditional_JavaGenThen__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label)
#line 2036 "jv_misc.tc"
{
	JavaConditionalBranch(node, info, label, 1);
}
#line 4692 "cg_misc.c"

void ILNode_Conditional_JavaGenElse__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label)
#line 2044 "jv_misc.tc"
{
	JavaConditionalBranch(node, info, label, 0);
}
#line 4699 "cg_misc.c"

struct ILNode_Conditional_vtable__ const ILNode_Conditional_vt__ = {
	&ILNode_TernaryExpression_vt__,
	ILNode_Conditional_kind,
	"ILNode_Conditional",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Conditional_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Conditional_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Conditional_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Conditional_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Conditional_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Conditional_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Conditional_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Conditional_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Conditional_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Conditional_JavaGenElse__,
};

ILMachineType ILNode_As_ILNode_GetType__(ILNode_As *node, ILGenInfo * info)
#line 307 "cg_misc.tc"
{
	return ILMachineType_ObjectRef;
}
#line 4723 "cg_misc.c"

void ILNode_As_ILNode_GenDiscard__(ILNode_As *node, ILGenInfo * info)
#line 558 "cg_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	ILNode_GenDiscard(node->expr, info);
}
#line 4731 "cg_misc.c"

ILMachineType ILNode_As_ILNode_GenValue__(ILNode_As *node, ILGenInfo * info)
#line 1509 "cg_misc.tc"
{
	As_GenValue(node, info);
	return ILMachineType_ObjectRef;
}
#line 4739 "cg_misc.c"

void ILNode_As_ILNode_GenThen__(ILNode_As *node, ILGenInfo * info, ILLabel * label)
#line 2274 "cg_misc.tc"
{
	As_GenValue((ILNode_As *)node, info);
	ILGenJump(info, IL_OP_BRTRUE, label);
	ILGenAdjust(info, -1);
}
#line 4748 "cg_misc.c"

void ILNode_As_ILNode_GenElse__(ILNode_As *node, ILGenInfo * info, ILLabel * label)
#line 2285 "cg_misc.tc"
{
	As_GenValue((ILNode_As *)node, info);
	ILGenJump(info, IL_OP_BRFALSE, label);
	ILGenAdjust(info, -1);
}
#line 4757 "cg_misc.c"

void ILNode_As_JavaGenDiscard__(ILNode_As *node, ILGenInfo * info)
#line 167 "jv_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	JavaGenDiscard(node->expr, info);
}
#line 4765 "cg_misc.c"

ILMachineType ILNode_As_JavaGenValue__(ILNode_As *node, ILGenInfo * info)
#line 505 "jv_misc.tc"
{
	ILLabel label1 = ILLabel_Undefined;

	/* Evaluate the sub-expression and cast to an object reference */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);

	/* Test the object using the "instanceof" instruction */
	JavaGenSimple(info, JAVA_OP_DUP);
	JavaGenAdjust(info, 1);
	JavaGenClassRef(info, JAVA_OP_INSTANCEOF, node->classInfo);
	JavaGenJump(info, JAVA_OP_IFNE, &label1);
	JavaGenAdjust(info, -1);
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenSimple(info, JAVA_OP_ACONST_NULL);
	JavaGenLabel(info, &label1);

	/* The return value is also an object */
	return ILMachineType_ObjectRef;
}
#line 4789 "cg_misc.c"

void ILNode_As_JavaGenThen__(ILNode_As *node, ILGenInfo * info, ILLabel * label)
#line 2111 "jv_misc.tc"
{
	/* Evaluate the sub-expression and cast to an object reference */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);

	/* Test the object using the "instanceof" instruction */
	JavaGenClassRef(info, JAVA_OP_INSTANCEOF, node->classInfo);

	/* Jump based on the result */
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -1);
}
#line 4805 "cg_misc.c"

void ILNode_As_JavaGenElse__(ILNode_As *node, ILGenInfo * info, ILLabel * label)
#line 2129 "jv_misc.tc"
{
	/* Evaluate the sub-expression and cast to an object reference */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);

	/* Test the object using the "instanceof" instruction */
	JavaGenClassRef(info, JAVA_OP_INSTANCEOF, node->classInfo);

	/* Jump based on the result */
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -1);
}
#line 4821 "cg_misc.c"

struct ILNode_As_vtable__ const ILNode_As_vt__ = {
	&ILNode_BoxingExpression_vt__,
	ILNode_As_kind,
	"ILNode_As",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_As_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_As_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_As_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_As_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_As_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_As_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_As_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_As_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_As_JavaGenElse__,
};

ILMachineType ILNode_Is_ILNode_GetType__(ILNode_Is *node, ILGenInfo * info)
#line 315 "cg_misc.tc"
{
	return ILMachineType_Boolean;
}
#line 4845 "cg_misc.c"

void ILNode_Is_ILNode_GenDiscard__(ILNode_Is *node, ILGenInfo * info)
#line 558 "cg_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	ILNode_GenDiscard(node->expr, info);
}
#line 4853 "cg_misc.c"

ILMachineType ILNode_Is_ILNode_GenValue__(ILNode_Is *node, ILGenInfo * info)
#line 1518 "cg_misc.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;

	/* Compute the "as" version of the expression */
	As_GenValue((ILNode_As *)node, info);

	/* Compare the result against "null" to get the result */
	ILGenJump(info, IL_OP_BRFALSE, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenLabel(info, &label2);
	return ILMachineType_Boolean;
}
#line 4873 "cg_misc.c"

void ILNode_Is_ILNode_GenThen__(ILNode_Is *node, ILGenInfo * info, ILLabel * label)
#line 2274 "cg_misc.tc"
{
	As_GenValue((ILNode_As *)node, info);
	ILGenJump(info, IL_OP_BRTRUE, label);
	ILGenAdjust(info, -1);
}
#line 4882 "cg_misc.c"

void ILNode_Is_ILNode_GenElse__(ILNode_Is *node, ILGenInfo * info, ILLabel * label)
#line 2285 "cg_misc.tc"
{
	As_GenValue((ILNode_As *)node, info);
	ILGenJump(info, IL_OP_BRFALSE, label);
	ILGenAdjust(info, -1);
}
#line 4891 "cg_misc.c"

void ILNode_Is_JavaGenDiscard__(ILNode_Is *node, ILGenInfo * info)
#line 167 "jv_misc.tc"
{
	/* Evaluate the expression for its side effects only */
	JavaGenDiscard(node->expr, info);
}
#line 4899 "cg_misc.c"

ILMachineType ILNode_Is_JavaGenValue__(ILNode_Is *node, ILGenInfo * info)
#line 530 "jv_misc.tc"
{
	/* Evaluate the sub-expression and cast to an object reference */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);

	/* Test the object using the "instanceof" instruction */
	JavaGenClassRef(info, JAVA_OP_INSTANCEOF, node->classInfo);

	/* The return value is boolean */
	return ILMachineType_Boolean;
}
#line 4914 "cg_misc.c"

void ILNode_Is_JavaGenThen__(ILNode_Is *node, ILGenInfo * info, ILLabel * label)
#line 2111 "jv_misc.tc"
{
	/* Evaluate the sub-expression and cast to an object reference */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);

	/* Test the object using the "instanceof" instruction */
	JavaGenClassRef(info, JAVA_OP_INSTANCEOF, node->classInfo);

	/* Jump based on the result */
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -1);
}
#line 4930 "cg_misc.c"

void ILNode_Is_JavaGenElse__(ILNode_Is *node, ILGenInfo * info, ILLabel * label)
#line 2129 "jv_misc.tc"
{
	/* Evaluate the sub-expression and cast to an object reference */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);

	/* Test the object using the "instanceof" instruction */
	JavaGenClassRef(info, JAVA_OP_INSTANCEOF, node->classInfo);

	/* Jump based on the result */
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -1);
}
#line 4946 "cg_misc.c"

struct ILNode_Is_vtable__ const ILNode_Is_vt__ = {
	&ILNode_BoxingExpression_vt__,
	ILNode_Is_kind,
	"ILNode_Is",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Is_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Is_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Is_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Is_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Is_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Is_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Is_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Is_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Is_JavaGenElse__,
};

ILMachineType ILNode_Box_ILNode_GetType__(ILNode_Box *node, ILGenInfo * info)
#line 348 "cg_misc.tc"
{
	return ILMachineType_ObjectRef;
}
#line 4970 "cg_misc.c"

ILMachineType ILNode_Box_ILNode_GenValue__(ILNode_Box *node, ILGenInfo * info)
#line 1577 "cg_misc.tc"
{
	ILMachineType type = ILNode_GenValue(node->expr, info);

	switch(type)
	{
		case ILMachineType_Void:
		{
			/* Shouldn't happen */
		}
		break;

		case ILMachineType_Boolean:
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		case ILMachineType_Float32:
		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		case ILMachineType_UnmanagedPtr:
		case ILMachineType_TransientPtr:
		case ILMachineType_ManagedValue:
		case ILMachineType_Decimal:
		{
			/* Box an instance of a value type */
			ILGenClassToken(info, IL_OP_BOX, node->classInfo);
		}
		break;

		case ILMachineType_ObjectRef:
		case ILMachineType_String:
		case ILMachineType_ManagedPtr:
		{
			/* Nothing to do here */
		}
		break;
	}

	return ILMachineType_ObjectRef;
}
#line 5021 "cg_misc.c"

ILMachineType ILNode_Box_JavaGenValue__(ILNode_Box *node, ILGenInfo * info)
#line 1345 "jv_misc.tc"
{
	JavaBoxValue(info, JavaGenValue(node->expr, info),
				 node->isEnumType, node->classInfo);
	return ILMachineType_ObjectRef;
}
#line 5030 "cg_misc.c"

struct ILNode_Box_vtable__ const ILNode_Box_vt__ = {
	&ILNode_BoxingExpression_vt__,
	ILNode_Box_kind,
	"ILNode_Box",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Box_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Box_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Box_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Unbox_ILNode_GetType__(ILNode_Unbox *node, ILGenInfo * info)
#line 356 "cg_misc.tc"
{
	return node->machineType;
}
#line 5054 "cg_misc.c"

ILMachineType ILNode_Unbox_ILNode_GenValue__(ILNode_Unbox *node, ILGenInfo * info)
#line 1629 "cg_misc.tc"
{
	ILMachineType subExprType;
	ILMachineType type;

	/* Evaluate the sub-expression to get the object pointer */
	subExprType = ILNode_GenValue(node->expr, info);

	/* Determine the destination type for the unbox operation */
	type = node->machineType;
	if(subExprType == type ||
	   (subExprType != ILMachineType_ObjectRef &&
	    subExprType != ILMachineType_ManagedPtr))
	{
		/* The sub-expression is already in the unboxed form */
		return subExprType;
	}

	/* At this point, we have either an object reference or
	   a managed pointer, which we must unbox into a value */
	switch(type)
	{
		case ILMachineType_Void:
		{
			/* Just pop the value because we won't need it after this */
			ILGenCast(info, subExprType, ILMachineType_Void);
		}
		break;

		case ILMachineType_Boolean:
		case ILMachineType_Int8:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I1);
		}
		break;

		case ILMachineType_UInt8:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_U1);
		}
		break;

		case ILMachineType_Int16:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I2);
		}
		break;

		case ILMachineType_UInt16:
		case ILMachineType_Char:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_U2);
		}
		break;

		case ILMachineType_Int32:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I4);
		}
		break;

		case ILMachineType_UInt32:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I4);
		}
		break;

		case ILMachineType_NativeInt:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I);
		}
		break;

		case ILMachineType_NativeUInt:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I);
		}
		break;

		case ILMachineType_Int64:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I8);
		}
		break;

		case ILMachineType_UInt64:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_I8);
		}
		break;

		case ILMachineType_Float32:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_R4);
		}
		break;

		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		{
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenSimple(info, IL_OP_LDIND_R8);
		}
		break;

		case ILMachineType_ObjectRef:
		case ILMachineType_String:
		{
			/* The unboxed form of an object is also an object.
			   We just do a cast to ensure it has the right type */
			ILGenClassToken(info, IL_OP_CASTCLASS, node->classInfo);
		}
		break;

		case ILMachineType_ManagedPtr:
		case ILMachineType_UnmanagedPtr:
		case ILMachineType_TransientPtr:
		{
			/* Unbox to a managed pointer */
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
		}
		break;

		case ILMachineType_ManagedValue:
		case ILMachineType_Decimal:
		{
			/* Unbox to a managed value */
			if(subExprType == ILMachineType_ObjectRef)
			{
				ILGenClassToken(info, IL_OP_UNBOX, node->classInfo);
			}
			ILGenClassToken(info, IL_OP_LDOBJ, node->classInfo);
		}
		break;
	}

	return type;
}
#line 5245 "cg_misc.c"

ILMachineType ILNode_Unbox_JavaGenValue__(ILNode_Unbox *node, ILGenInfo * info)
#line 1355 "jv_misc.tc"
{
	ILMachineType subExprType;

	/* Evaluate the sub-expression to get the object pointer */
	subExprType = JavaGenValue(node->expr, info);

	/* Unbox the value */
	return JavaUnboxValue(info, subExprType, node->machineType,
						  node->isEnumType, 0, node->classInfo);
}
#line 5259 "cg_misc.c"

struct ILNode_Unbox_vtable__ const ILNode_Unbox_vt__ = {
	&ILNode_BoxingExpression_vt__,
	ILNode_Unbox_kind,
	"ILNode_Unbox",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Unbox_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Unbox_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Unbox_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILNode *ILNode_VarArgList_create(void)
{
	ILNode_VarArgList *node__ = (ILNode_VarArgList *)yynodealloc(sizeof(struct ILNode_VarArgList__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_VarArgList_vt__;
	node__->kind__ = ILNode_VarArgList_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_Argument_create(ILParameterModifier modifier, ILNode * expression)
{
	ILNode_Argument *node__ = (ILNode_Argument *)yynodealloc(sizeof(struct ILNode_Argument__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Argument_vt__;
	node__->kind__ = ILNode_Argument_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->modifier = modifier;
	node__->expression = expression;
	return (ILNode *)node__;
}

ILNode *ILNode_ArgArray_create(ILType * elemType, ILUInt32 numElems, ILNode * args)
{
	ILNode_ArgArray *node__ = (ILNode_ArgArray *)yynodealloc(sizeof(struct ILNode_ArgArray__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ArgArray_vt__;
	node__->kind__ = ILNode_ArgArray_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->elemType = elemType;
	node__->numElems = numElems;
	node__->args = args;
	return (ILNode *)node__;
}

ILNode *ILNode_Error_create(void)
{
	ILNode_Error *node__ = (ILNode_Error *)yynodealloc(sizeof(struct ILNode_Error__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Error_vt__;
	node__->kind__ = ILNode_Error_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_NewExpression_create(ILNode * type, ILNode * indexes, ILNode * rank, ILNode * arrayInitializer)
{
	ILNode_NewExpression *node__ = (ILNode_NewExpression *)yynodealloc(sizeof(struct ILNode_NewExpression__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_NewExpression_vt__;
	node__->kind__ = ILNode_NewExpression_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->indexes = indexes;
	node__->rank = rank;
	node__->arrayInitializer = arrayInitializer;
	node__->arrayType = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ObjectCreationExpression_create(ILNode * type, ILNode * argList)
{
	ILNode_ObjectCreationExpression *node__ = (ILNode_ObjectCreationExpression *)yynodealloc(sizeof(struct ILNode_ObjectCreationExpression__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ObjectCreationExpression_vt__;
	node__->kind__ = ILNode_ObjectCreationExpression_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->argList = argList;
	node__->methodInfo = 0;
	node__->callSiteSig = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_DelegateCreationExpression_create(ILClass * delegateClass, ILNode * expr, ILMethod * methodInfo)
{
	ILNode_DelegateCreationExpression *node__ = (ILNode_DelegateCreationExpression *)yynodealloc(sizeof(struct ILNode_DelegateCreationExpression__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DelegateCreationExpression_vt__;
	node__->kind__ = ILNode_DelegateCreationExpression_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->delegateClass = delegateClass;
	node__->expr = expr;
	node__->methodInfo = methodInfo;
	return (ILNode *)node__;
}

ILNode *ILNode_DefaultConstructor_create(ILNode * expr, ILType * type, int useCtorMethod)
{
	ILNode_DefaultConstructor *node__ = (ILNode_DefaultConstructor *)yynodealloc(sizeof(struct ILNode_DefaultConstructor__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DefaultConstructor_vt__;
	node__->kind__ = ILNode_DefaultConstructor_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = type;
	node__->useCtorMethod = useCtorMethod;
	return (ILNode *)node__;
}

ILNode *ILNode_BaseInit_create(void)
{
	ILNode_BaseInit *node__ = (ILNode_BaseInit *)yynodealloc(sizeof(struct ILNode_BaseInit__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BaseInit_vt__;
	node__->kind__ = ILNode_BaseInit_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_ThisInit_create(void)
{
	ILNode_ThisInit *node__ = (ILNode_ThisInit *)yynodealloc(sizeof(struct ILNode_ThisInit__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ThisInit_vt__;
	node__->kind__ = ILNode_ThisInit_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_NonStaticInit_create(void)
{
	ILNode_NonStaticInit *node__ = (ILNode_NonStaticInit *)yynodealloc(sizeof(struct ILNode_NonStaticInit__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_NonStaticInit_vt__;
	node__->kind__ = ILNode_NonStaticInit_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_This_create(void)
{
	ILNode_This *node__ = (ILNode_This *)yynodealloc(sizeof(struct ILNode_This__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_This_vt__;
	node__->kind__ = ILNode_This_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_Deref_create(ILNode * expr, ILType * elemType)
{
	ILNode_Deref *node__ = (ILNode_Deref *)yynodealloc(sizeof(struct ILNode_Deref__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Deref_vt__;
	node__->kind__ = ILNode_Deref_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->elemType = elemType;
	return (ILNode *)node__;
}

ILNode *ILNode_AsIs_create(ILNode * expr)
{
	ILNode_AsIs *node__ = (ILNode_AsIs *)yynodealloc(sizeof(struct ILNode_AsIs__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AsIs_vt__;
	node__->kind__ = ILNode_AsIs_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_Overflow_create(ILNode * expr)
{
	ILNode_Overflow *node__ = (ILNode_Overflow *)yynodealloc(sizeof(struct ILNode_Overflow__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Overflow_vt__;
	node__->kind__ = ILNode_Overflow_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_NoOverflow_create(ILNode * expr)
{
	ILNode_NoOverflow *node__ = (ILNode_NoOverflow *)yynodealloc(sizeof(struct ILNode_NoOverflow__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_NoOverflow_vt__;
	node__->kind__ = ILNode_NoOverflow_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_Pedantic_create(ILNode * expr)
{
	ILNode_Pedantic *node__ = (ILNode_Pedantic *)yynodealloc(sizeof(struct ILNode_Pedantic__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Pedantic_vt__;
	node__->kind__ = ILNode_Pedantic_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_NoPedantic_create(ILNode * expr)
{
	ILNode_NoPedantic *node__ = (ILNode_NoPedantic *)yynodealloc(sizeof(struct ILNode_NoPedantic__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_NoPedantic_vt__;
	node__->kind__ = ILNode_NoPedantic_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_MarkType_create(ILNode * expr, ILType * type)
{
	ILNode_MarkType *node__ = (ILNode_MarkType *)yynodealloc(sizeof(struct ILNode_MarkType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_MarkType_vt__;
	node__->kind__ = ILNode_MarkType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_CastSimple_create(ILNode * expr, ILMachineType machineType)
{
	ILNode_CastSimple *node__ = (ILNode_CastSimple *)yynodealloc(sizeof(struct ILNode_CastSimple__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CastSimple_vt__;
	node__->kind__ = ILNode_CastSimple_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->machineType = machineType;
	return (ILNode *)node__;
}

ILNode *ILNode_CastType_create(ILNode * expr, ILType * type)
{
	ILNode_CastType *node__ = (ILNode_CastType *)yynodealloc(sizeof(struct ILNode_CastType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CastType_vt__;
	node__->kind__ = ILNode_CastType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_UserConversion_create(ILNode * expr, ILMachineType machineType, ILMethod * method)
{
	ILNode_UserConversion *node__ = (ILNode_UserConversion *)yynodealloc(sizeof(struct ILNode_UserConversion__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserConversion_vt__;
	node__->kind__ = ILNode_UserConversion_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->machineType = machineType;
	node__->method = method;
	return (ILNode *)node__;
}

ILNode *ILNode_AddressOf_create(ILNode * expr)
{
	ILNode_AddressOf *node__ = (ILNode_AddressOf *)yynodealloc(sizeof(struct ILNode_AddressOf__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AddressOf_vt__;
	node__->kind__ = ILNode_AddressOf_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_ToBool_create(ILNode * expr)
{
	ILNode_ToBool *node__ = (ILNode_ToBool *)yynodealloc(sizeof(struct ILNode_ToBool__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ToBool_vt__;
	node__->kind__ = ILNode_ToBool_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->trueMethod = 0;
	node__->falseMethod = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ToConst_create(ILNode * expr)
{
	ILNode_ToConst *node__ = (ILNode_ToConst *)yynodealloc(sizeof(struct ILNode_ToConst__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ToConst_vt__;
	node__->kind__ = ILNode_ToConst_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_VarArgExpand_create(ILNode * expr)
{
	ILNode_VarArgExpand *node__ = (ILNode_VarArgExpand *)yynodealloc(sizeof(struct ILNode_VarArgExpand__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_VarArgExpand_vt__;
	node__->kind__ = ILNode_VarArgExpand_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->varArgTypes = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_IsNull_create(ILNode * expr)
{
	ILNode_IsNull *node__ = (ILNode_IsNull *)yynodealloc(sizeof(struct ILNode_IsNull__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_IsNull_vt__;
	node__->kind__ = ILNode_IsNull_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_IsNonNull_create(ILNode * expr)
{
	ILNode_IsNonNull *node__ = (ILNode_IsNonNull *)yynodealloc(sizeof(struct ILNode_IsNonNull__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_IsNonNull_vt__;
	node__->kind__ = ILNode_IsNonNull_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_MakeRefAny_create(ILNode * expr)
{
	ILNode_MakeRefAny *node__ = (ILNode_MakeRefAny *)yynodealloc(sizeof(struct ILNode_MakeRefAny__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_MakeRefAny_vt__;
	node__->kind__ = ILNode_MakeRefAny_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_RefType_create(ILNode * expr)
{
	ILNode_RefType *node__ = (ILNode_RefType *)yynodealloc(sizeof(struct ILNode_RefType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_RefType_vt__;
	node__->kind__ = ILNode_RefType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_ArrayLength_create(ILNode * expr)
{
	ILNode_ArrayLength *node__ = (ILNode_ArrayLength *)yynodealloc(sizeof(struct ILNode_ArrayLength__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ArrayLength_vt__;
	node__->kind__ = ILNode_ArrayLength_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_Comma_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Comma *node__ = (ILNode_Comma *)yynodealloc(sizeof(struct ILNode_Comma__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Comma_vt__;
	node__->kind__ = ILNode_Comma_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_ArgList_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_ArgList *node__ = (ILNode_ArgList *)yynodealloc(sizeof(struct ILNode_ArgList__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ArgList_vt__;
	node__->kind__ = ILNode_ArgList_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_RefValue_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_RefValue *node__ = (ILNode_RefValue *)yynodealloc(sizeof(struct ILNode_RefValue__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_RefValue_vt__;
	node__->kind__ = ILNode_RefValue_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->type = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_InvocationExpression_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_InvocationExpression *node__ = (ILNode_InvocationExpression *)yynodealloc(sizeof(struct ILNode_InvocationExpression__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_InvocationExpression_vt__;
	node__->kind__ = ILNode_InvocationExpression_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->thisExpr = 0;
	node__->methodInfo = 0;
	node__->callSiteSig = 0;
	node__->baseCall = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_Conditional_create(ILNode * expr1, ILNode * expr2, ILNode * expr3)
{
	ILNode_Conditional *node__ = (ILNode_Conditional *)yynodealloc(sizeof(struct ILNode_Conditional__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Conditional_vt__;
	node__->kind__ = ILNode_Conditional_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->expr3 = expr3;
	return (ILNode *)node__;
}

ILNode *ILNode_As_create(ILNode * expr, ILClass * classInfo, int isEnumType)
{
	ILNode_As *node__ = (ILNode_As *)yynodealloc(sizeof(struct ILNode_As__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_As_vt__;
	node__->kind__ = ILNode_As_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->classInfo = classInfo;
	node__->isEnumType = isEnumType;
	return (ILNode *)node__;
}

ILNode *ILNode_Is_create(ILNode * expr, ILClass * classInfo, int isEnumType)
{
	ILNode_Is *node__ = (ILNode_Is *)yynodealloc(sizeof(struct ILNode_Is__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Is_vt__;
	node__->kind__ = ILNode_Is_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->classInfo = classInfo;
	node__->isEnumType = isEnumType;
	return (ILNode *)node__;
}

ILNode *ILNode_Box_create(ILNode * expr, ILClass * classInfo, int isEnumType)
{
	ILNode_Box *node__ = (ILNode_Box *)yynodealloc(sizeof(struct ILNode_Box__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Box_vt__;
	node__->kind__ = ILNode_Box_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->classInfo = classInfo;
	node__->isEnumType = isEnumType;
	return (ILNode *)node__;
}

ILNode *ILNode_Unbox_create(ILNode * expr, ILClass * classInfo, int isEnumType, ILMachineType machineType)
{
	ILNode_Unbox *node__ = (ILNode_Unbox *)yynodealloc(sizeof(struct ILNode_Unbox__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Unbox_vt__;
	node__->kind__ = ILNode_Unbox_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->classInfo = classInfo;
	node__->isEnumType = isEnumType;
	node__->machineType = machineType;
	return (ILNode *)node__;
}

