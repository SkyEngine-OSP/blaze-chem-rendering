/* cg_arith.c.  Generated automatically by treecc */
#line 3 "cg_arith.tc"

/*
 * cg_arith.tc - Arithmetic operator nodes.
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

/*
 * Bit count stuff to get the correct power of 2 for stuff
 */
static int IsPowOfTwo(ILEvalValue evalValue)
{
	int bitpos=-1;
	int bitcount=0;
	ILUInt32 word;
	ILUInt64 longWord;
	switch(evalValue.valueType)
	{
		case ILMachineType_Int8:
		case ILMachineType_Int16:
		case ILMachineType_Int32:
		{
			if(evalValue.un.i4Value<0)
			{
				return -1;
			}
		}
		/* fall through */
		case ILMachineType_UInt8:
		case ILMachineType_UInt16:
		case ILMachineType_UInt32:
		{
			for(word=evalValue.un.i4Value;word!=0;word=word>>1)
			{
				if(word & 0x01)bitcount++;
				bitpos++;
			}
		}
		break;
		
		case ILMachineType_Int64:
		{
			if(evalValue.un.i8Value<0)
			{
				return -1;
			}
		}
		/* fall through */
		
		case ILMachineType_UInt64:
		{
			for(longWord=evalValue.un.i8Value;longWord!=0;longWord=longWord>>1)
			{
				if(longWord & 0x01)bitcount++;
				bitpos++;
			}
		}
		break;
		default:
			return -1;
	}
	if(bitcount==1)return bitpos;
	return -1;
}

/*
 * Reduce operator strength for arithmetic operators
 */
static int ReduceOperator(ILGenInfo *info, ILNode *node,
		ILNode** parent,ILMachineType commonType)
{
	ILEvalValue evalValue;
	ILNode_BinaryExpression *expr;
	int bitpos;
	if(info->overflowInsns || !(info->optimizeFlag))
	{
		return 0;
	}
	if(!yyisa(node,ILNode_BinaryExpression))
	{
		return 0;
	}

	expr=(ILNode_BinaryExpression*)(node);
	if(!ILNode_EvalConst(expr->expr1,info,&evalValue) && 
		!ILNode_EvalConst(expr->expr2,info,&evalValue))
	{
		return 0;
	}
	
	switch(commonType)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			if(ILNode_EvalConst(expr->expr1,info,&evalValue))
			{
				if((bitpos=IsPowOfTwo(evalValue))>0)
				{
					if(yyisa(node,ILNode_Mul))
					{
						*parent=ILNode_Shl_create(expr->expr2,
									ILNode_Int32_create(bitpos,0,0));
						return 1;
					}
				}
			}
			else if(ILNode_EvalConst(expr->expr2,info,&evalValue))
			{
				if((bitpos=IsPowOfTwo(evalValue))>0)
				{
					if(yyisa(node,ILNode_Mul))
					{
						*parent=ILNode_Shl_create(expr->expr1,
									ILNode_Int32_create(bitpos,0,0));
						return 1;
					}
					else if(yyisa(node,ILNode_Div))
					{
						*parent=ILNode_Shr_create(expr->expr1,
									ILNode_Int32_create(bitpos,0,0));
						return 1;
					}
				}
			}
		}
		default:
			break;
	}

	return 0;
}
#line 158 "cg_arith.c"

ILMachineType ILNode_Neg_ILNode_GetType__(ILNode_Neg *node, ILGenInfo * info)
#line 275 "cg_arith.tc"
{
	ILMachineType type = ILNode_GetType(node->expr, info);
	return ILCommonType(info, type, type, 0);
}
#line 166 "cg_arith.c"

void ILNode_Neg_ILNode_GenDiscard__(ILNode_Neg *node, ILGenInfo * info)
#line 340 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 173 "cg_arith.c"

ILMachineType ILNode_Neg_ILNode_GenValue__(ILNode_Neg *node, ILGenInfo * info)
#line 490 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 0);

	/* Apply the operator */
	ILNegate_ApplyOp(info, node, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 191 "cg_arith.c"

int ILNode_Neg_ILNode_EvalConst__(ILNode_Neg *node, ILGenInfo * info, ILEvalValue * value)
#line 778 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 0);

	/* Evaluate the argument and cast to the common type */
	if(!ILNode_EvalConst(node->expr, info, value) ||
	   !ILGenCastConst(info, value, value->valueType, commonType))
	{
		return 0;
	}

	/* Apply the operator */
	return ILNegate_EvalOp(info, commonType, value);
}
#line 213 "cg_arith.c"

void ILNode_Neg_JavaGenDiscard__(ILNode_Neg *node, ILGenInfo * info)
#line 81 "jv_arith.tc"
{
	JavaGenDiscard(node->expr, info);
}
#line 220 "cg_arith.c"

ILMachineType ILNode_Neg_JavaGenValue__(ILNode_Neg *node, ILGenInfo * info)
#line 220 "jv_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 0);

	/* Evaluate the sub-expression and cast to the common type */
	JavaGenCast(info, JavaGenValue(node->expr, info), commonType);

	/* Apply the operator */
	JavaNegate_ApplyOp(info, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 241 "cg_arith.c"

struct ILNode_Neg_vtable__ const ILNode_Neg_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_Neg_kind,
	"ILNode_Neg",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Neg_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Neg_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Neg_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Neg_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Neg_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Neg_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UnaryPlus_ILNode_GetType__(ILNode_UnaryPlus *node, ILGenInfo * info)
#line 275 "cg_arith.tc"
{
	ILMachineType type = ILNode_GetType(node->expr, info);
	return ILCommonType(info, type, type, 0);
}
#line 266 "cg_arith.c"

void ILNode_UnaryPlus_ILNode_GenDiscard__(ILNode_UnaryPlus *node, ILGenInfo * info)
#line 340 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 273 "cg_arith.c"

ILMachineType ILNode_UnaryPlus_ILNode_GenValue__(ILNode_UnaryPlus *node, ILGenInfo * info)
#line 509 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 0);

	/* Generate code for the sub-expression and cast to the common type */
	ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 291 "cg_arith.c"

int ILNode_UnaryPlus_ILNode_EvalConst__(ILNode_UnaryPlus *node, ILGenInfo * info, ILEvalValue * value)
#line 801 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 0);

	/* Generate code for the sub-expression and cast to the common type */
	if(!ILNode_EvalConst(node->expr, info, value) ||
	   !ILGenCastConst(info, value, value->valueType, commonType))
	{
		return 0;
	}
	return 1;
}
#line 311 "cg_arith.c"

void ILNode_UnaryPlus_JavaGenDiscard__(ILNode_UnaryPlus *node, ILGenInfo * info)
#line 81 "jv_arith.tc"
{
	JavaGenDiscard(node->expr, info);
}
#line 318 "cg_arith.c"

ILMachineType ILNode_UnaryPlus_JavaGenValue__(ILNode_UnaryPlus *node, ILGenInfo * info)
#line 242 "jv_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 0);

	/* Generate code for the sub-expression and cast to the common type */
	JavaGenCast(info, JavaGenValue(node->expr, info), commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 336 "cg_arith.c"

struct ILNode_UnaryPlus_vtable__ const ILNode_UnaryPlus_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_UnaryPlus_kind,
	"ILNode_UnaryPlus",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UnaryPlus_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UnaryPlus_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UnaryPlus_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_UnaryPlus_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UnaryPlus_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UnaryPlus_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Not_ILNode_GetType__(ILNode_Not *node, ILGenInfo * info)
#line 284 "cg_arith.tc"
{
	ILMachineType type = ILNode_GetType(node->expr, info);
	return ILCommonType(info, type, type, 1);
}
#line 361 "cg_arith.c"

void ILNode_Not_ILNode_GenDiscard__(ILNode_Not *node, ILGenInfo * info)
#line 340 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 368 "cg_arith.c"

ILMachineType ILNode_Not_ILNode_GenValue__(ILNode_Not *node, ILGenInfo * info)
#line 528 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 1);

	/* Generate code for the sub-expression and cast to the common type */
	ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);

	/* Apply the operator */
	ILNot_ApplyOp(info, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 389 "cg_arith.c"

int ILNode_Not_ILNode_EvalConst__(ILNode_Not *node, ILGenInfo * info, ILEvalValue * value)
#line 822 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 1);

	/* Evaluate the sub-expression and cast to the common type */
	if(!ILNode_EvalConst(node->expr, info, value) ||
	   !ILGenCastConst(info, value, value->valueType, commonType))
	{
		return 0;
	}

	/* Apply the operator */
	return ILNot_EvalOp(info, commonType, value);
}
#line 411 "cg_arith.c"

void ILNode_Not_JavaGenDiscard__(ILNode_Not *node, ILGenInfo * info)
#line 81 "jv_arith.tc"
{
	JavaGenDiscard(node->expr, info);
}
#line 418 "cg_arith.c"

ILMachineType ILNode_Not_JavaGenValue__(ILNode_Not *node, ILGenInfo * info)
#line 261 "jv_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type to use */
	type = ILNode_GetType(node->expr, info);
	commonType = ILCommonType(info, type, type, 1);

	/* Generate code for the sub-expression and cast to the common type */
	JavaGenCast(info, JavaGenValue(node->expr, info), commonType);

	/* Apply the operator */
	JavaNot_ApplyOp(info, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 439 "cg_arith.c"

struct ILNode_Not_vtable__ const ILNode_Not_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_Not_kind,
	"ILNode_Not",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Not_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Not_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Not_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Not_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Not_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Not_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserUnaryOp_ILNode_GetType__(ILNode_UserUnaryOp *node, ILGenInfo * info)
#line 293 "cg_arith.tc"
{
	return node->machineType;
}
#line 463 "cg_arith.c"

void ILNode_UserUnaryOp_ILNode_GenDiscard__(ILNode_UserUnaryOp *node, ILGenInfo * info)
#line 340 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 470 "cg_arith.c"

ILMachineType ILNode_UserUnaryOp_ILNode_GenValue__(ILNode_UserUnaryOp *node, ILGenInfo * info)
#line 550 "cg_arith.tc"
{
	/* Generate code to compute the value of the argument */
	ILNode_GenValue(node->expr, info);

	/* Call the operator */
	ILGenCallByMethod(info, node->method);
	return node->machineType;
}
#line 482 "cg_arith.c"

void ILNode_UserUnaryOp_JavaGenDiscard__(ILNode_UserUnaryOp *node, ILGenInfo * info)
#line 81 "jv_arith.tc"
{
	JavaGenDiscard(node->expr, info);
}
#line 489 "cg_arith.c"

ILMachineType ILNode_UserUnaryOp_JavaGenValue__(ILNode_UserUnaryOp *node, ILGenInfo * info)
#line 283 "jv_arith.tc"
{
	ILMachineType type;

	/* Generate code to compute the value of the argument */
	type = JavaGenValue(node->expr, info);

	/* Call the operator */
	JavaGenCallByMethod(info, node->method);

	/* Adjust the stack height and return */
	JavaGenAdjust(info, -(JavaGenTypeSize(type)));
	JavaGenAdjust(info, JavaGenTypeSize(node->machineType));
	return node->machineType;
}
#line 507 "cg_arith.c"

struct ILNode_UserUnaryOp_vtable__ const ILNode_UserUnaryOp_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_UserUnaryOp_kind,
	"ILNode_UserUnaryOp",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserUnaryOp_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserUnaryOp_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserUnaryOp_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserUnaryOp_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserUnaryOp_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_BinaryArith_ILNode_GetType__(ILNode_BinaryArith *node, ILGenInfo * info)
#line 243 "cg_arith.tc"
{
	return ILCommonType(info,
						ILNode_GetType(node->expr1, info),
						ILNode_GetType(node->expr2, info),
						0);
}
#line 534 "cg_arith.c"

void ILNode_BinaryArith_ILNode_GenDiscard__(ILNode_BinaryArith *node, ILGenInfo * info)
#line 332 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 542 "cg_arith.c"

ILMachineType ILNode_BinaryArith_ILNode_GenValue__(ILNode_BinaryArith *node, ILGenInfo * info)
#line 348 "cg_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILNode *reducedNode = NULL;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	commonType = ILCommonType(info, type1, type2, 0);

	if(ReduceOperator(info,(ILNode*)node,(ILNode**)(&reducedNode),commonType))
	{
		if(reducedNode != NULL)
		{
			return ILNode_GenValue(reducedNode,info);
		}
	}

	/* Evaluate the sub-expressions and cast to the common type */
	ILGenCast(info, ILNode_GenValue(node->expr1, info), commonType);
	ILGenCast(info, ILNode_GenValue(node->expr2, info), commonType);

	/* Apply the operator */
	ILBinary_ApplyOp(info, node, commonType);
	ILGenAdjust(info, -1);

	/* Return the common type to the caller */
	return commonType;
}
#line 578 "cg_arith.c"

int ILNode_BinaryArith_ILNode_EvalConst__(ILNode_BinaryArith *node, ILGenInfo * info, ILEvalValue * value)
#line 667 "cg_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILEvalValue value2;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	commonType = ILCommonType(info, type1, type2, 0);

	/* Evaluate the sub-expressions and cast to the common type */
	if(!ILNode_EvalConst(node->expr1, info, value) ||
	   !ILGenCastConst(info, value, value->valueType, commonType))
	{
		return 0;
	}
	if(!ILNode_EvalConst(node->expr2, info, &value2) ||
	   !ILGenCastConst(info, &value2, value2.valueType, commonType))
	{
		return 0;
	}

	/* Evaluate the operator */
	return ILBinary_EvalOp(info, node, commonType, value, &value2);
}
#line 610 "cg_arith.c"

void ILNode_BinaryArith_JavaGenDiscard__(ILNode_BinaryArith *node, ILGenInfo * info)
#line 73 "jv_arith.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 618 "cg_arith.c"

ILMachineType ILNode_BinaryArith_JavaGenValue__(ILNode_BinaryArith *node, ILGenInfo * info)
#line 89 "jv_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	commonType = ILCommonType(info, type1, type2, 0);

	/* Evaluate the sub-expressions and cast to the common type */
	JavaGenCast(info, JavaGenValue(node->expr1, info), commonType);
	JavaGenCast(info, JavaGenValue(node->expr2, info), commonType);

	/* Apply the operator */
	JavaBinary_ApplyOp(info, node, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 644 "cg_arith.c"

struct ILNode_BinaryArith_vtable__ const ILNode_BinaryArith_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_BinaryArith_kind,
	"ILNode_BinaryArith",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryArith_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_BinaryBitwise_ILNode_GetType__(ILNode_BinaryBitwise *node, ILGenInfo * info)
#line 254 "cg_arith.tc"
{
	return ILCommonType(info,
						ILNode_GetType(node->expr1, info),
						ILNode_GetType(node->expr2, info),
						1);
}
#line 671 "cg_arith.c"

void ILNode_BinaryBitwise_ILNode_GenDiscard__(ILNode_BinaryBitwise *node, ILGenInfo * info)
#line 332 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 679 "cg_arith.c"

ILMachineType ILNode_BinaryBitwise_ILNode_GenValue__(ILNode_BinaryBitwise *node, ILGenInfo * info)
#line 422 "cg_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	commonType = ILCommonType(info, type1, type2, 1);

	/* Evaluate the sub-expressions and cast to the common type */
	ILGenCast(info, ILNode_GenValue(node->expr1, info), commonType);
	ILGenCast(info, ILNode_GenValue(node->expr2, info), commonType);

	/* Apply the operator */
	ILBitwise_ApplyOp(info, node, commonType);
	ILGenAdjust(info, -1);

	/* Return the common type to the caller */
	return commonType;
}
#line 706 "cg_arith.c"

int ILNode_BinaryBitwise_ILNode_EvalConst__(ILNode_BinaryBitwise *node, ILGenInfo * info, ILEvalValue * value)
#line 700 "cg_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILEvalValue value2;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	commonType = ILCommonType(info, type1, type2, 1);

	/* Evaluate the sub-expressions and cast to the common type */
	if(!ILNode_EvalConst(node->expr1, info, value) ||
	   !ILGenCastConst(info, value, value->valueType, commonType))
	{
		return 0;
	}
	if(!ILNode_EvalConst(node->expr2, info, &value2) ||
	   !ILGenCastConst(info, &value2, value2.valueType, commonType))
	{
		return 0;
	}

	/* Evaluate the operator */
	return ILBitwise_EvalOp(info, node, commonType, value, &value2);
}
#line 738 "cg_arith.c"

void ILNode_BinaryBitwise_JavaGenDiscard__(ILNode_BinaryBitwise *node, ILGenInfo * info)
#line 73 "jv_arith.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 746 "cg_arith.c"

ILMachineType ILNode_BinaryBitwise_JavaGenValue__(ILNode_BinaryBitwise *node, ILGenInfo * info)
#line 152 "jv_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	commonType = ILCommonType(info, type1, type2, 1);

	/* Evaluate the sub-expressions and cast to the common type */
	JavaGenCast(info, JavaGenValue(node->expr1, info), commonType);
	JavaGenCast(info, JavaGenValue(node->expr2, info), commonType);

	/* Apply the operator */
	JavaBitwise_ApplyOp(info, node, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 772 "cg_arith.c"

struct ILNode_BinaryBitwise_vtable__ const ILNode_BinaryBitwise_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_BinaryBitwise_kind,
	"ILNode_BinaryBitwise",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryBitwise_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_BinaryShift_ILNode_GetType__(ILNode_BinaryShift *node, ILGenInfo * info)
#line 265 "cg_arith.tc"
{
	ILMachineType type = ILNode_GetType(node->expr1, info);
	return ILCommonType(info, type, type, 1);
}
#line 797 "cg_arith.c"

void ILNode_BinaryShift_ILNode_GenDiscard__(ILNode_BinaryShift *node, ILGenInfo * info)
#line 332 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 805 "cg_arith.c"

ILMachineType ILNode_BinaryShift_ILNode_GenValue__(ILNode_BinaryShift *node, ILGenInfo * info)
#line 450 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type */
	type = ILNode_GetType(node->expr1, info);
	commonType = ILCommonType(info, type, type, 1);

	/* Evaluate the first sub-expression and cast to the common type */
	ILGenCast(info, ILNode_GenValue(node->expr1, info), commonType);

	/* If we are doing an unsigned shift right on an 8-bit or
	   16-bit value, we need to mask off the sign bits first */
	if(commonType == ILMachineType_Int8 &&
	   yykind(node) == yykindof(ILNode_UShr))
	{
		ILGenSimple(info, IL_OP_CONV_U1);
	}
	else if(commonType == ILMachineType_Int16 &&
	        yykind(node) == yykindof(ILNode_UShr))
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}

	/* Evaluate the second sub-expression and cast to "native uint" */
	ILGenCast(info, ILNode_GenValue(node->expr2, info),
			  ILMachineType_NativeUInt);

	/* Apply the operator */
	ILShift_ApplyOp(info, node, commonType);
	ILGenAdjust(info, -1);

	/* Return the common type to the caller */
	return commonType;
}
#line 844 "cg_arith.c"

int ILNode_BinaryShift_ILNode_EvalConst__(ILNode_BinaryShift *node, ILGenInfo * info, ILEvalValue * value)
#line 733 "cg_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;
	ILEvalValue value2;

	/* Determine the common type */
	type = ILNode_GetType(node->expr1, info);
	commonType = ILCommonType(info, type, type, 1);

	/* Evaluate the first sub-expression and cast to the common type */
	if(!ILNode_EvalConst(node->expr1, info, value) ||
	   !ILGenCastConst(info, value, value->valueType, commonType))
	{
		return 0;
	}

	/* If we are doing an unsigned shift right on an 8-bit or
	   16-bit value, we need to mask off the sign bits first */
	if(commonType == ILMachineType_Int8 &&
	   yykind(node) == yykindof(ILNode_UShr))
	{
		value->un.i4Value &= 0xFF;
	}
	else if(commonType == ILMachineType_Int16 &&
	        yykind(node) == yykindof(ILNode_UShr))
	{
		value->un.i4Value &= 0xFFFF;
	}

	/* Evaluate the second sub-expression and cast to "native uint" */
	if(!ILNode_EvalConst(node->expr2, info, &value2) ||
	   !ILGenCastConst(info, &value2, value2.valueType,
	   				   ILMachineType_NativeUInt))
	{
		return 0;
	}

	/* Apply the operator */
	return ILShift_EvalOp(info, node, commonType, value, &value2);
}
#line 888 "cg_arith.c"

void ILNode_BinaryShift_JavaGenDiscard__(ILNode_BinaryShift *node, ILGenInfo * info)
#line 73 "jv_arith.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 896 "cg_arith.c"

ILMachineType ILNode_BinaryShift_JavaGenValue__(ILNode_BinaryShift *node, ILGenInfo * info)
#line 179 "jv_arith.tc"
{
	ILMachineType type;
	ILMachineType commonType;

	/* Determine the common type */
	type = ILNode_GetType(node->expr1, info);
	commonType = ILCommonType(info, type, type, 1);

	/* Evaluate the first sub-expression and cast to the common type */
	JavaGenCast(info, JavaGenValue(node->expr1, info), commonType);

	/* If we are doing an unsigned shift right on an 8-bit or
	   16-bit value, we need to mask off the sign bits first */
	if(commonType == ILMachineType_Int8 &&
	   yykind(node) == yykindof(ILNode_UShr))
	{
		JavaGenInt32(info, 0xFF);
		JavaGenSimple(info, JAVA_OP_IAND);
		JavaGenExtend(info, 1);
	}
	else if(commonType == ILMachineType_Int16 &&
	        yykind(node) == yykindof(ILNode_UShr))
	{
		JavaGenSimple(info, JAVA_OP_I2C);
	}

	/* Evaluate the second sub-expression and cast to "native uint" */
	JavaGenCast(info, JavaGenValue(node->expr2, info),
			    ILMachineType_NativeUInt);

	/* Apply the operator */
	JavaShift_ApplyOp(info, node, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 936 "cg_arith.c"

struct ILNode_BinaryShift_vtable__ const ILNode_BinaryShift_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_BinaryShift_kind,
	"ILNode_BinaryShift",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryShift_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserBinaryOp_ILNode_GetType__(ILNode_UserBinaryOp *node, ILGenInfo * info)
#line 301 "cg_arith.tc"
{
	return node->machineType;
}
#line 960 "cg_arith.c"

void ILNode_UserBinaryOp_ILNode_GenDiscard__(ILNode_UserBinaryOp *node, ILGenInfo * info)
#line 332 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 968 "cg_arith.c"

ILMachineType ILNode_UserBinaryOp_ILNode_GenValue__(ILNode_UserBinaryOp *node, ILGenInfo * info)
#line 563 "cg_arith.tc"
{
	/* Generate code to compute the value of the arguments */
	ILNode_GenValue(node->expr1, info);
	ILNode_GenValue(node->expr2, info);

	/* Call the operator */
	ILGenCallByMethod(info, node->method);
	ILGenAdjust(info, -1);
	return node->machineType;
}
#line 982 "cg_arith.c"

void ILNode_UserBinaryOp_JavaGenDiscard__(ILNode_UserBinaryOp *node, ILGenInfo * info)
#line 73 "jv_arith.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 990 "cg_arith.c"

ILMachineType ILNode_UserBinaryOp_JavaGenValue__(ILNode_UserBinaryOp *node, ILGenInfo * info)
#line 302 "jv_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;

	/* Generate code to compute the value of the arguments */
	type1 = JavaGenValue(node->expr1, info);
	type2 = JavaGenValue(node->expr2, info);

	/* Call the operator */
	JavaGenCallByMethod(info, node->method);

	/* Adjust the stack height and return */
	JavaGenAdjust(info, -(JavaGenTypeSize(type1) + JavaGenTypeSize(type2)));
	JavaGenAdjust(info, JavaGenTypeSize(node->machineType));
	return node->machineType;
}
#line 1010 "cg_arith.c"

struct ILNode_UserBinaryOp_vtable__ const ILNode_UserBinaryOp_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_UserBinaryOp_kind,
	"ILNode_UserBinaryOp",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserBinaryOp_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserBinaryOp_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserBinaryOp_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_UserBinaryOp_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserBinaryOp_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Concat_ILNode_GetType__(ILNode_Concat *node, ILGenInfo * info)
#line 309 "cg_arith.tc"
{
	return ILMachineType_String;
}
#line 1034 "cg_arith.c"

void ILNode_Concat_ILNode_GenDiscard__(ILNode_Concat *node, ILGenInfo * info)
#line 332 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 1042 "cg_arith.c"

ILMachineType ILNode_Concat_ILNode_GenValue__(ILNode_Concat *node, ILGenInfo * info)
#line 578 "cg_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;

	/* Generate code for the two arguments */
	type1 = ILNode_GenValue(node->expr1, info);
	if(type1 >= ILMachineType_Boolean &&
	   type1 <= ILMachineType_Decimal)
	{
		ILGenCast(info, type1, ILMachineType_String);
		type1 = ILMachineType_String;
	}
	else
	{
		ILGenCast(info, type1, ILMachineType_ObjectRef);
	}
	type2 = ILNode_GenValue(node->expr2, info);
	if(type2 >= ILMachineType_Boolean &&
	   type2 <= ILMachineType_Decimal)
	{
		ILGenCast(info, type2, ILMachineType_String);
		type2 = ILMachineType_String;
	}
	else
	{
		ILGenCast(info, type2, ILMachineType_ObjectRef);
	}

	/* Apply either the string or the object concatenation function */
	if(type1 == ILMachineType_String && type2 == ILMachineType_String)
	{
		ILGenCallByName(info,
		  "class [.library]System.String [.library]System.String::Concat"
			"(class [.library]System.String, class [.library]System.String)");
	}
	else
	{
		ILGenCallByName(info,
		  "class [.library]System.String [.library]System.String::Concat"
			"(class [.library]System.Object, class [.library]System.Object)");
	}
	ILGenAdjust(info, -1);
	return ILMachineType_String;
}
#line 1090 "cg_arith.c"

int ILNode_Concat_ILNode_EvalConst__(ILNode_Concat *node, ILGenInfo * info, ILEvalValue * value)
#line 842 "cg_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILEvalValue value2;
	ILIntString new_string;

	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	if(type1 != ILMachineType_String || type2 != ILMachineType_String)
	{
		return 0;
	}
	if(!ILNode_EvalConst(node->expr1,info,value)) 
	{
		return 0;
	}
	if(!ILNode_EvalConst(node->expr2,info,&value2)) 
	{
		return 0;
	}
	new_string = ILInternAppendedString
				(ILInternString(value->un.strValue.str, 
					value->un.strValue.len),
				 ILInternString(value2.un.strValue.str,
				 	value2.un.strValue.len));
	value->un.strValue.str=new_string.string; 
	value->un.strValue.len=new_string.len;
	return 1;
}
#line 1123 "cg_arith.c"

void ILNode_Concat_JavaGenDiscard__(ILNode_Concat *node, ILGenInfo * info)
#line 73 "jv_arith.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 1131 "cg_arith.c"

ILMachineType ILNode_Concat_JavaGenValue__(ILNode_Concat *node, ILGenInfo * info)
#line 323 "jv_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;

	/* Generate code for the two arguments */
	type1 = JavaGenValue(node->expr1, info);
	if(type1 >= ILMachineType_Boolean &&
	   type1 <= ILMachineType_Decimal)
	{
		JavaGenCast(info, type1, ILMachineType_String);
		type1 = ILMachineType_String;
	}
	else
	{
		JavaGenCast(info, type1, ILMachineType_ObjectRef);
		if(info->useJavaLib)
		{
			JavaGenCallVirtual(info, "java/lang/Object", "toString",
							   "()Ljava/lang/String;");
			type1 = ILMachineType_String;
		}
	}
	type2 = JavaGenValue(node->expr2, info);
	if(type2 >= ILMachineType_Boolean &&
	   type2 <= ILMachineType_Decimal)
	{
		JavaGenCast(info, type2, ILMachineType_String);
		type2 = ILMachineType_String;
	}
	else
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
	return ILMachineType_String;
}
#line 1197 "cg_arith.c"

struct ILNode_Concat_vtable__ const ILNode_Concat_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_Concat_kind,
	"ILNode_Concat",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Concat_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Concat_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Concat_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Concat_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Concat_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Concat_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_DelegateAdd_ILNode_GetType__(ILNode_DelegateAdd *node, ILGenInfo * info)
#line 318 "cg_arith.tc"
{
	return ILMachineType_ObjectRef;
}
#line 1221 "cg_arith.c"

void ILNode_DelegateAdd_ILNode_GenDiscard__(ILNode_DelegateAdd *node, ILGenInfo * info)
#line 332 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 1229 "cg_arith.c"

ILMachineType ILNode_DelegateAdd_ILNode_GenValue__(ILNode_DelegateAdd *node, ILGenInfo * info)
#line 627 "cg_arith.tc"
{
	/* Generate code for the two arguments */
	ILNode_GenValue(node->expr1, info);
	ILNode_GenValue(node->expr2, info);

	/* Call the delegate combination operator in "System.Delegate" */
	ILGenCallByName(info,
	  "class [.library]System.Delegate [.library]System.Delegate::Combine"
		"(class [.library]System.Delegate, class [.library]System.Delegate)");
	ILGenAdjust(info, -1);
	ILGenClassToken(info, IL_OP_CASTCLASS, node->delegateClass);

	/* The result is always an object reference */
	return ILMachineType_ObjectRef;
}
#line 1248 "cg_arith.c"

void ILNode_DelegateAdd_JavaGenDiscard__(ILNode_DelegateAdd *node, ILGenInfo * info)
#line 73 "jv_arith.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 1256 "cg_arith.c"

ILMachineType ILNode_DelegateAdd_JavaGenValue__(ILNode_DelegateAdd *node, ILGenInfo * info)
#line 390 "jv_arith.tc"
{
	/* Generate code for the two arguments */
	JavaGenValue(node->expr1, info);
	JavaGenValue(node->expr2, info);

	/* Call the delegate combination operator in "System.Delegate" */
	JavaGenCallByName(info, "System/Delegate", "Combine",
			  "(LSystem/Delegate;LSystem/Delegate;)LSystem/Delegate;");
	JavaGenAdjust(info, -1);
	JavaGenClassRef(info, JAVA_OP_CHECKCAST, node->delegateClass);

	/* The result is always an object reference */
	return ILMachineType_ObjectRef;
}
#line 1274 "cg_arith.c"

struct ILNode_DelegateAdd_vtable__ const ILNode_DelegateAdd_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_DelegateAdd_kind,
	"ILNode_DelegateAdd",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateAdd_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateAdd_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateAdd_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateAdd_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateAdd_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_DelegateSub_ILNode_GetType__(ILNode_DelegateSub *node, ILGenInfo * info)
#line 318 "cg_arith.tc"
{
	return ILMachineType_ObjectRef;
}
#line 1298 "cg_arith.c"

void ILNode_DelegateSub_ILNode_GenDiscard__(ILNode_DelegateSub *node, ILGenInfo * info)
#line 332 "cg_arith.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 1306 "cg_arith.c"

ILMachineType ILNode_DelegateSub_ILNode_GenValue__(ILNode_DelegateSub *node, ILGenInfo * info)
#line 647 "cg_arith.tc"
{
	/* Generate code for the two arguments */
	ILNode_GenValue(node->expr1, info);
	ILNode_GenValue(node->expr2, info);

	/* Call the delegate removal operator in "System.Delegate" */
	ILGenCallByName(info,
	  "class [.library]System.Delegate [.library]System.Delegate::Remove"
		"(class [.library]System.Delegate, class [.library]System.Delegate)");
	ILGenAdjust(info, -1);
	ILGenClassToken(info, IL_OP_CASTCLASS, node->delegateClass);

	/* The result is always an object reference */
	return ILMachineType_ObjectRef;
}
#line 1325 "cg_arith.c"

void ILNode_DelegateSub_JavaGenDiscard__(ILNode_DelegateSub *node, ILGenInfo * info)
#line 73 "jv_arith.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 1333 "cg_arith.c"

ILMachineType ILNode_DelegateSub_JavaGenValue__(ILNode_DelegateSub *node, ILGenInfo * info)
#line 409 "jv_arith.tc"
{
	/* Generate code for the two arguments */
	JavaGenValue(node->expr1, info);
	JavaGenValue(node->expr2, info);

	/* Call the delegate removal operator in "System.Delegate" */
	JavaGenCallByName(info, "System/Delegate", "Remove",
			  "(LSystem/Delegate;LSystem/Delegate;)LSystem/Delegate;");
	JavaGenAdjust(info, -1);
	JavaGenClassRef(info, JAVA_OP_CHECKCAST, node->delegateClass);

	/* The result is always an object reference */
	return ILMachineType_ObjectRef;
}
#line 1351 "cg_arith.c"

struct ILNode_DelegateSub_vtable__ const ILNode_DelegateSub_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_DelegateSub_kind,
	"ILNode_DelegateSub",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateSub_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateSub_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateSub_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateSub_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateSub_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_Add_ILNode_GenValue__(ILNode_Add *node, ILGenInfo * info)
#line 385 "cg_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	if(type1 == ILMachineType_String || type2 == ILMachineType_String)
	{
		/* Perform string concatenation on the arguments */
		commonType = ILMachineType_String;
	}
	else
	{
		/* Numeric addition operator */
		commonType = ILCommonType(info, type1, type2, 0);
	}

	/* Evaluate the sub-expressions and cast to the common type */
	ILGenCast(info, ILNode_GenValue(node->expr1, info), commonType);
	ILGenCast(info, ILNode_GenValue(node->expr2, info), commonType);

	/* Apply the operator */
	ILBinary_ApplyOp(info, (ILNode_BinaryArith *)node, commonType);
	ILGenAdjust(info, -1);

	/* Return the common type to the caller */
	return commonType;
}
#line 1404 "cg_arith.c"

ILMachineType ILNode_Add_JavaGenValue__(ILNode_Add *node, ILGenInfo * info)
#line 116 "jv_arith.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Get the types of the sub-expressions */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);

	/* Determine the common type */
	if(type1 == ILMachineType_String || type2 == ILMachineType_String)
	{
		/* Perform string concatenation on the arguments */
		commonType = ILMachineType_String;
	}
	else
	{
		/* Numeric addition operator */
		commonType = ILCommonType(info, type1, type2, 0);
	}

	/* Evaluate the sub-expressions and cast to the common type */
	JavaGenCast(info, JavaGenValue(node->expr1, info), commonType);
	JavaGenCast(info, JavaGenValue(node->expr2, info), commonType);

	/* Apply the operator */
	JavaBinary_ApplyOp(info, (ILNode_BinaryArith *)node, commonType);

	/* Return the common type to the caller */
	return commonType;
}
#line 1439 "cg_arith.c"

struct ILNode_Add_vtable__ const ILNode_Add_vt__ = {
	&ILNode_BinaryArith_vt__,
	ILNode_Add_kind,
	"ILNode_Add",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Add_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryArith_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Add_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Sub_vtable__ const ILNode_Sub_vt__ = {
	&ILNode_BinaryArith_vt__,
	ILNode_Sub_kind,
	"ILNode_Sub",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryArith_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Mul_vtable__ const ILNode_Mul_vt__ = {
	&ILNode_BinaryArith_vt__,
	ILNode_Mul_kind,
	"ILNode_Mul",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryArith_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Div_vtable__ const ILNode_Div_vt__ = {
	&ILNode_BinaryArith_vt__,
	ILNode_Div_kind,
	"ILNode_Div",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryArith_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Rem_vtable__ const ILNode_Rem_vt__ = {
	&ILNode_BinaryArith_vt__,
	ILNode_Rem_kind,
	"ILNode_Rem",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryArith_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryArith_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_And_vtable__ const ILNode_And_vt__ = {
	&ILNode_BinaryBitwise_vt__,
	ILNode_And_kind,
	"ILNode_And",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryBitwise_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Or_vtable__ const ILNode_Or_vt__ = {
	&ILNode_BinaryBitwise_vt__,
	ILNode_Or_kind,
	"ILNode_Or",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryBitwise_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Xor_vtable__ const ILNode_Xor_vt__ = {
	&ILNode_BinaryBitwise_vt__,
	ILNode_Xor_kind,
	"ILNode_Xor",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryBitwise_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryBitwise_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Shl_vtable__ const ILNode_Shl_vt__ = {
	&ILNode_BinaryShift_vt__,
	ILNode_Shl_kind,
	"ILNode_Shl",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryShift_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_Shr_vtable__ const ILNode_Shr_vt__ = {
	&ILNode_BinaryShift_vt__,
	ILNode_Shr_kind,
	"ILNode_Shr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryShift_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_UShr_vtable__ const ILNode_UShr_vt__ = {
	&ILNode_BinaryShift_vt__,
	ILNode_UShr_kind,
	"ILNode_UShr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_BinaryShift_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BinaryShift_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILNode *ILNode_Neg_create(ILNode * expr)
{
	ILNode_Neg *node__ = (ILNode_Neg *)yynodealloc(sizeof(struct ILNode_Neg__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Neg_vt__;
	node__->kind__ = ILNode_Neg_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_UnaryPlus_create(ILNode * expr)
{
	ILNode_UnaryPlus *node__ = (ILNode_UnaryPlus *)yynodealloc(sizeof(struct ILNode_UnaryPlus__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UnaryPlus_vt__;
	node__->kind__ = ILNode_UnaryPlus_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_Not_create(ILNode * expr)
{
	ILNode_Not *node__ = (ILNode_Not *)yynodealloc(sizeof(struct ILNode_Not__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Not_vt__;
	node__->kind__ = ILNode_Not_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_UserUnaryOp_create(ILNode * expr, ILMachineType machineType, ILMethod * method)
{
	ILNode_UserUnaryOp *node__ = (ILNode_UserUnaryOp *)yynodealloc(sizeof(struct ILNode_UserUnaryOp__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserUnaryOp_vt__;
	node__->kind__ = ILNode_UserUnaryOp_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->machineType = machineType;
	node__->method = method;
	return (ILNode *)node__;
}

ILNode *ILNode_UserBinaryOp_create(ILNode * expr1, ILNode * expr2, ILMachineType machineType, ILMethod * method)
{
	ILNode_UserBinaryOp *node__ = (ILNode_UserBinaryOp *)yynodealloc(sizeof(struct ILNode_UserBinaryOp__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserBinaryOp_vt__;
	node__->kind__ = ILNode_UserBinaryOp_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->machineType = machineType;
	node__->method = method;
	return (ILNode *)node__;
}

ILNode *ILNode_Concat_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Concat *node__ = (ILNode_Concat *)yynodealloc(sizeof(struct ILNode_Concat__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Concat_vt__;
	node__->kind__ = ILNode_Concat_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_DelegateAdd_create(ILNode * expr1, ILNode * expr2, ILClass * delegateClass)
{
	ILNode_DelegateAdd *node__ = (ILNode_DelegateAdd *)yynodealloc(sizeof(struct ILNode_DelegateAdd__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DelegateAdd_vt__;
	node__->kind__ = ILNode_DelegateAdd_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->delegateClass = delegateClass;
	return (ILNode *)node__;
}

ILNode *ILNode_DelegateSub_create(ILNode * expr1, ILNode * expr2, ILClass * delegateClass)
{
	ILNode_DelegateSub *node__ = (ILNode_DelegateSub *)yynodealloc(sizeof(struct ILNode_DelegateSub__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DelegateSub_vt__;
	node__->kind__ = ILNode_DelegateSub_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->delegateClass = delegateClass;
	return (ILNode *)node__;
}

ILNode *ILNode_Add_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Add *node__ = (ILNode_Add *)yynodealloc(sizeof(struct ILNode_Add__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Add_vt__;
	node__->kind__ = ILNode_Add_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Sub_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Sub *node__ = (ILNode_Sub *)yynodealloc(sizeof(struct ILNode_Sub__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Sub_vt__;
	node__->kind__ = ILNode_Sub_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Mul_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Mul *node__ = (ILNode_Mul *)yynodealloc(sizeof(struct ILNode_Mul__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Mul_vt__;
	node__->kind__ = ILNode_Mul_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Div_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Div *node__ = (ILNode_Div *)yynodealloc(sizeof(struct ILNode_Div__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Div_vt__;
	node__->kind__ = ILNode_Div_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Rem_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Rem *node__ = (ILNode_Rem *)yynodealloc(sizeof(struct ILNode_Rem__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Rem_vt__;
	node__->kind__ = ILNode_Rem_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_And_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_And *node__ = (ILNode_And *)yynodealloc(sizeof(struct ILNode_And__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_And_vt__;
	node__->kind__ = ILNode_And_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Or_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Or *node__ = (ILNode_Or *)yynodealloc(sizeof(struct ILNode_Or__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Or_vt__;
	node__->kind__ = ILNode_Or_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Xor_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Xor *node__ = (ILNode_Xor *)yynodealloc(sizeof(struct ILNode_Xor__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Xor_vt__;
	node__->kind__ = ILNode_Xor_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Shl_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Shl *node__ = (ILNode_Shl *)yynodealloc(sizeof(struct ILNode_Shl__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Shl_vt__;
	node__->kind__ = ILNode_Shl_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Shr_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Shr *node__ = (ILNode_Shr *)yynodealloc(sizeof(struct ILNode_Shr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Shr_vt__;
	node__->kind__ = ILNode_Shr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_UShr_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_UShr *node__ = (ILNode_UShr *)yynodealloc(sizeof(struct ILNode_UShr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UShr_vt__;
	node__->kind__ = ILNode_UShr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

static int ILShift_EvalOp_1__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2910 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	value1->un.i4Value =
		(ILInt32)(ILInt8)(value1->un.i4Value <<
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 1886 "cg_arith.c"

static int ILShift_EvalOp_2__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2918 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	value1->un.i4Value =
		(ILInt32)(ILUInt8)(value1->un.i4Value <<
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 1897 "cg_arith.c"

static int ILShift_EvalOp_3__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2926 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	value1->un.i4Value =
		(ILInt32)(ILInt16)(value1->un.i4Value <<
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 1908 "cg_arith.c"

static int ILShift_EvalOp_4__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2935 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value <<
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 1919 "cg_arith.c"

static int ILShift_EvalOp_5__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2935 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value <<
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 1930 "cg_arith.c"

static int ILShift_EvalOp_6__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2946 "cg_arith.tc"
{
	value1->un.i4Value <<= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 1938 "cg_arith.c"

static int ILShift_EvalOp_7__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2946 "cg_arith.tc"
{
	value1->un.i4Value <<= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 1946 "cg_arith.c"

static int ILShift_EvalOp_8__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2952 "cg_arith.tc"
{
	value1->un.i8Value <<= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 1954 "cg_arith.c"

static int ILShift_EvalOp_9__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2952 "cg_arith.tc"
{
	value1->un.i8Value <<= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 1962 "cg_arith.c"

static int ILShift_EvalOp_10__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2946 "cg_arith.tc"
{
	value1->un.i4Value <<= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 1970 "cg_arith.c"

static int ILShift_EvalOp_11__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2946 "cg_arith.tc"
{
	value1->un.i4Value <<= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 1978 "cg_arith.c"

static int ILShift_EvalOp_12__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2957 "cg_arith.tc"
{
	return 0;
}
#line 1985 "cg_arith.c"

static int ILShift_EvalOp_13__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2965 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	value1->un.i4Value =
		(ILInt32)(ILInt8)(value1->un.i4Value >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 1996 "cg_arith.c"

static int ILShift_EvalOp_14__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2973 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	value1->un.i4Value =
		(ILInt32)(ILUInt8)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2007 "cg_arith.c"

static int ILShift_EvalOp_15__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2981 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	value1->un.i4Value =
		(ILInt32)(ILInt16)(value1->un.i4Value >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2018 "cg_arith.c"

static int ILShift_EvalOp_16__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2990 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2029 "cg_arith.c"

static int ILShift_EvalOp_17__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2990 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2040 "cg_arith.c"

static int ILShift_EvalOp_18__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2999 "cg_arith.tc"
{
	value1->un.i4Value >>= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 2048 "cg_arith.c"

static int ILShift_EvalOp_19__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3005 "cg_arith.tc"
{
	value1->un.i4Value =
		(ILInt32)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2058 "cg_arith.c"

static int ILShift_EvalOp_20__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3012 "cg_arith.tc"
{
	value1->un.i8Value >>= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 2066 "cg_arith.c"

static int ILShift_EvalOp_21__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3017 "cg_arith.tc"
{
	value1->un.i8Value =
		(ILInt64)((ILUInt64)(value1->un.i8Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2076 "cg_arith.c"

static int ILShift_EvalOp_22__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2999 "cg_arith.tc"
{
	value1->un.i4Value >>= (ILUInt32)(value2->un.i4Value);
	return 1;
}
#line 2084 "cg_arith.c"

static int ILShift_EvalOp_23__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3005 "cg_arith.tc"
{
	value1->un.i4Value =
		(ILInt32)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2094 "cg_arith.c"

static int ILShift_EvalOp_24__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3024 "cg_arith.tc"
{
	return 0;
}
#line 2101 "cg_arith.c"

static int ILShift_EvalOp_25__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3032 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	value1->un.i4Value =
		(ILInt32)(ILInt8)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2112 "cg_arith.c"

static int ILShift_EvalOp_26__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3040 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	value1->un.i4Value =
		(ILInt32)(ILUInt8)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2123 "cg_arith.c"

static int ILShift_EvalOp_27__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3048 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	value1->un.i4Value =
		(ILInt32)(ILInt16)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2134 "cg_arith.c"

static int ILShift_EvalOp_28__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3057 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2145 "cg_arith.c"

static int ILShift_EvalOp_29__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3057 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2156 "cg_arith.c"

static int ILShift_EvalOp_30__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3068 "cg_arith.tc"
{
	value1->un.i4Value =
		(ILInt32)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2166 "cg_arith.c"

static int ILShift_EvalOp_31__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3068 "cg_arith.tc"
{
	value1->un.i4Value =
		(ILInt32)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2176 "cg_arith.c"

static int ILShift_EvalOp_32__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3076 "cg_arith.tc"
{
	value1->un.i8Value =
		(ILInt64)((ILUInt64)(value1->un.i8Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2186 "cg_arith.c"

static int ILShift_EvalOp_33__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3076 "cg_arith.tc"
{
	value1->un.i8Value =
		(ILInt64)((ILUInt64)(value1->un.i8Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2196 "cg_arith.c"

static int ILShift_EvalOp_34__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3068 "cg_arith.tc"
{
	value1->un.i4Value =
		(ILInt32)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2206 "cg_arith.c"

static int ILShift_EvalOp_35__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3068 "cg_arith.tc"
{
	value1->un.i4Value =
		(ILInt32)((ILUInt32)(value1->un.i4Value) >>
						  (ILUInt32)(value2->un.i4Value));
	return 1;
}
#line 2216 "cg_arith.c"

static int ILShift_EvalOp_36__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 3083 "cg_arith.tc"
{
	return 0;
}
#line 2223 "cg_arith.c"

int ILShift_EvalOp(ILGenInfo * info, ILNode_BinaryShift * node__, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
{
	switch(node__->kind__)
	{
		case ILNode_Shl_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILShift_EvalOp_1__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILShift_EvalOp_2__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILShift_EvalOp_3__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILShift_EvalOp_4__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILShift_EvalOp_5__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILShift_EvalOp_6__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILShift_EvalOp_7__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILShift_EvalOp_8__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILShift_EvalOp_9__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILShift_EvalOp_10__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILShift_EvalOp_11__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILShift_EvalOp_12__(info, (ILNode_Shl *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Shr_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILShift_EvalOp_13__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILShift_EvalOp_14__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILShift_EvalOp_15__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILShift_EvalOp_16__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILShift_EvalOp_17__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILShift_EvalOp_18__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILShift_EvalOp_19__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILShift_EvalOp_20__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILShift_EvalOp_21__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILShift_EvalOp_22__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILShift_EvalOp_23__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILShift_EvalOp_24__(info, (ILNode_Shr *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_UShr_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILShift_EvalOp_25__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILShift_EvalOp_26__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILShift_EvalOp_27__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILShift_EvalOp_28__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILShift_EvalOp_29__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILShift_EvalOp_30__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILShift_EvalOp_31__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILShift_EvalOp_32__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILShift_EvalOp_33__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILShift_EvalOp_34__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILShift_EvalOp_35__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILShift_EvalOp_36__(info, (ILNode_UShr *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
	return (0);
}

int ILNot_EvalOp(ILGenInfo * info, ILMachineType commonType, ILEvalValue * value)
{
	switch(commonType)
	{
		case ILMachineType_Int8:
		{
#line 3198 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILInt8)(~(value->un.i4Value));
				return 1;
			}
#line 2686 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 3203 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILUInt8)(~(value->un.i4Value));
				return 1;
			}
#line 2697 "cg_arith.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 3208 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILInt16)(~(value->un.i4Value));
				return 1;
			}
#line 2708 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 3214 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILInt32)(~(value->un.i4Value));
				return 1;
			}
#line 2719 "cg_arith.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 3214 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILInt32)(~(value->un.i4Value));
				return 1;
			}
#line 2730 "cg_arith.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 3220 "cg_arith.tc"
			{
				value->un.i4Value = ~(value->un.i4Value);
				return 1;
			}
#line 2741 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 3220 "cg_arith.tc"
			{
				value->un.i4Value = ~(value->un.i4Value);
				return 1;
			}
#line 2752 "cg_arith.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 3242 "cg_arith.tc"
			{
				value->un.i8Value = ~(value->un.i8Value);
				return 1;
			}
#line 2763 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 3242 "cg_arith.tc"
			{
				value->un.i8Value = ~(value->un.i8Value);
				return 1;
			}
#line 2774 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 3225 "cg_arith.tc"
			{
				/* Because we don't know the size of native integers
				   at compile time, we need to be careful.  We can
				   only perform the operation if the 32-bit and 64-bit
				   results would be the same */
				ILInt64 testResult = ~((ILInt64)(value->un.i4Value));
				value->un.i4Value = ~(value->un.i4Value);
				return (((ILInt64)(value->un.i4Value)) == testResult);
			}
#line 2790 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 3235 "cg_arith.tc"
			{
				/* We cannot use bitwise NOT because we don't know
				   the size of native integers at compile time */
				return 0;
			}
#line 2802 "cg_arith.c"
		}
		break;

		case ILMachineType_Void:
		case ILMachineType_Boolean:
		case ILMachineType_Float32:
		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		case ILMachineType_Decimal:
		case ILMachineType_String:
		case ILMachineType_ObjectRef:
		case ILMachineType_UnmanagedPtr:
		case ILMachineType_ManagedPtr:
		case ILMachineType_TransientPtr:
		case ILMachineType_ManagedValue:
		{
#line 3247 "cg_arith.tc"
			{
				return 0;
			}
#line 2823 "cg_arith.c"
		}
		break;

		default: break;
	}
	return (0);
}

static void ILBitwise_ApplyOp_1__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2838 "cg_arith.c"

static void ILBitwise_ApplyOp_2__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1472 "cg_arith.tc"
{
	/* Returns true if both arguments are true.  We assume
	   that both arguments are clamped to the set {0,1} */
	ILGenSimple(info, IL_OP_AND);
}
#line 2847 "cg_arith.c"

static void ILBitwise_ApplyOp_3__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1478 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_AND);
	ILGenSimple(info, IL_OP_CONV_I1);
}
#line 2856 "cg_arith.c"

static void ILBitwise_ApplyOp_4__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1484 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_AND);
	ILGenSimple(info, IL_OP_CONV_U1);
}
#line 2865 "cg_arith.c"

static void ILBitwise_ApplyOp_5__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1490 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_AND);
	ILGenSimple(info, IL_OP_CONV_I2);
}
#line 2874 "cg_arith.c"

static void ILBitwise_ApplyOp_6__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1497 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_AND);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 2883 "cg_arith.c"

static void ILBitwise_ApplyOp_7__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1497 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_AND);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 2892 "cg_arith.c"

static void ILBitwise_ApplyOp_8__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1508 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_AND);
}
#line 2899 "cg_arith.c"

static void ILBitwise_ApplyOp_9__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1508 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_AND);
}
#line 2906 "cg_arith.c"

static void ILBitwise_ApplyOp_10__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1508 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_AND);
}
#line 2913 "cg_arith.c"

static void ILBitwise_ApplyOp_11__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1508 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_AND);
}
#line 2920 "cg_arith.c"

static void ILBitwise_ApplyOp_12__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1508 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_AND);
}
#line 2927 "cg_arith.c"

static void ILBitwise_ApplyOp_13__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1508 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_AND);
}
#line 2934 "cg_arith.c"

static void ILBitwise_ApplyOp_14__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2942 "cg_arith.c"

static void ILBitwise_ApplyOp_15__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2950 "cg_arith.c"

static void ILBitwise_ApplyOp_16__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2958 "cg_arith.c"

static void ILBitwise_ApplyOp_17__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2966 "cg_arith.c"

static void ILBitwise_ApplyOp_18__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2974 "cg_arith.c"

static void ILBitwise_ApplyOp_19__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2982 "cg_arith.c"

static void ILBitwise_ApplyOp_20__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2990 "cg_arith.c"

static void ILBitwise_ApplyOp_21__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 2998 "cg_arith.c"

static void ILBitwise_ApplyOp_22__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3006 "cg_arith.c"

static void ILBitwise_ApplyOp_23__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1522 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3014 "cg_arith.c"

static void ILBitwise_ApplyOp_24__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3022 "cg_arith.c"

static void ILBitwise_ApplyOp_25__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1531 "cg_arith.tc"
{
	/* Returns true if one of the arguments is true.  We assume
	   that both arguments are clamped to the set {0,1} */
	ILGenSimple(info, IL_OP_OR);
}
#line 3031 "cg_arith.c"

static void ILBitwise_ApplyOp_26__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1537 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_OR);
	ILGenSimple(info, IL_OP_CONV_I1);
}
#line 3040 "cg_arith.c"

static void ILBitwise_ApplyOp_27__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1543 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_OR);
	ILGenSimple(info, IL_OP_CONV_U1);
}
#line 3049 "cg_arith.c"

static void ILBitwise_ApplyOp_28__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1549 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_OR);
	ILGenSimple(info, IL_OP_CONV_I2);
}
#line 3058 "cg_arith.c"

static void ILBitwise_ApplyOp_29__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1556 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_OR);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 3067 "cg_arith.c"

static void ILBitwise_ApplyOp_30__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1556 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_OR);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 3076 "cg_arith.c"

static void ILBitwise_ApplyOp_31__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1567 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_OR);
}
#line 3083 "cg_arith.c"

static void ILBitwise_ApplyOp_32__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1567 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_OR);
}
#line 3090 "cg_arith.c"

static void ILBitwise_ApplyOp_33__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1567 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_OR);
}
#line 3097 "cg_arith.c"

static void ILBitwise_ApplyOp_34__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1567 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_OR);
}
#line 3104 "cg_arith.c"

static void ILBitwise_ApplyOp_35__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1567 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_OR);
}
#line 3111 "cg_arith.c"

static void ILBitwise_ApplyOp_36__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1567 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_OR);
}
#line 3118 "cg_arith.c"

static void ILBitwise_ApplyOp_37__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3126 "cg_arith.c"

static void ILBitwise_ApplyOp_38__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3134 "cg_arith.c"

static void ILBitwise_ApplyOp_39__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3142 "cg_arith.c"

static void ILBitwise_ApplyOp_40__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3150 "cg_arith.c"

static void ILBitwise_ApplyOp_41__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3158 "cg_arith.c"

static void ILBitwise_ApplyOp_42__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3166 "cg_arith.c"

static void ILBitwise_ApplyOp_43__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3174 "cg_arith.c"

static void ILBitwise_ApplyOp_44__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3182 "cg_arith.c"

static void ILBitwise_ApplyOp_45__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3190 "cg_arith.c"

static void ILBitwise_ApplyOp_46__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1581 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3198 "cg_arith.c"

static void ILBitwise_ApplyOp_47__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3206 "cg_arith.c"

static void ILBitwise_ApplyOp_48__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1590 "cg_arith.tc"
{
	/* Returns the XOR of the boolean arguments.  We assume
	   that both arguments are clamped to the set {0,1} */
	ILGenSimple(info, IL_OP_XOR);
}
#line 3215 "cg_arith.c"

static void ILBitwise_ApplyOp_49__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1596 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_XOR);
	ILGenSimple(info, IL_OP_CONV_I1);
}
#line 3224 "cg_arith.c"

static void ILBitwise_ApplyOp_50__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1602 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_XOR);
	ILGenSimple(info, IL_OP_CONV_U1);
}
#line 3233 "cg_arith.c"

static void ILBitwise_ApplyOp_51__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1608 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_XOR);
	ILGenSimple(info, IL_OP_CONV_I2);
}
#line 3242 "cg_arith.c"

static void ILBitwise_ApplyOp_52__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1615 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_XOR);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 3251 "cg_arith.c"

static void ILBitwise_ApplyOp_53__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1615 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_XOR);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 3260 "cg_arith.c"

static void ILBitwise_ApplyOp_54__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1626 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_XOR);
}
#line 3267 "cg_arith.c"

static void ILBitwise_ApplyOp_55__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1626 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_XOR);
}
#line 3274 "cg_arith.c"

static void ILBitwise_ApplyOp_56__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1626 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_XOR);
}
#line 3281 "cg_arith.c"

static void ILBitwise_ApplyOp_57__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1626 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_XOR);
}
#line 3288 "cg_arith.c"

static void ILBitwise_ApplyOp_58__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1626 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_XOR);
}
#line 3295 "cg_arith.c"

static void ILBitwise_ApplyOp_59__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1626 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_XOR);
}
#line 3302 "cg_arith.c"

static void ILBitwise_ApplyOp_60__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3310 "cg_arith.c"

static void ILBitwise_ApplyOp_61__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3318 "cg_arith.c"

static void ILBitwise_ApplyOp_62__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3326 "cg_arith.c"

static void ILBitwise_ApplyOp_63__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3334 "cg_arith.c"

static void ILBitwise_ApplyOp_64__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3342 "cg_arith.c"

static void ILBitwise_ApplyOp_65__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3350 "cg_arith.c"

static void ILBitwise_ApplyOp_66__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3358 "cg_arith.c"

static void ILBitwise_ApplyOp_67__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3366 "cg_arith.c"

static void ILBitwise_ApplyOp_68__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3374 "cg_arith.c"

static void ILBitwise_ApplyOp_69__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1640 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3382 "cg_arith.c"

void ILBitwise_ApplyOp(ILGenInfo * info, ILNode_BinaryBitwise * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_And_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBitwise_ApplyOp_1__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBitwise_ApplyOp_2__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBitwise_ApplyOp_3__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBitwise_ApplyOp_4__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBitwise_ApplyOp_5__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBitwise_ApplyOp_6__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBitwise_ApplyOp_7__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBitwise_ApplyOp_8__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBitwise_ApplyOp_9__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBitwise_ApplyOp_10__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBitwise_ApplyOp_11__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBitwise_ApplyOp_12__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBitwise_ApplyOp_13__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBitwise_ApplyOp_14__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBitwise_ApplyOp_15__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBitwise_ApplyOp_16__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBitwise_ApplyOp_17__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBitwise_ApplyOp_18__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBitwise_ApplyOp_19__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBitwise_ApplyOp_20__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBitwise_ApplyOp_21__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBitwise_ApplyOp_22__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBitwise_ApplyOp_23__(info, (ILNode_And *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Or_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBitwise_ApplyOp_24__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBitwise_ApplyOp_25__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBitwise_ApplyOp_26__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBitwise_ApplyOp_27__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBitwise_ApplyOp_28__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBitwise_ApplyOp_29__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBitwise_ApplyOp_30__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBitwise_ApplyOp_31__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBitwise_ApplyOp_32__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBitwise_ApplyOp_33__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBitwise_ApplyOp_34__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBitwise_ApplyOp_35__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBitwise_ApplyOp_36__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBitwise_ApplyOp_37__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBitwise_ApplyOp_38__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBitwise_ApplyOp_39__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBitwise_ApplyOp_40__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBitwise_ApplyOp_41__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBitwise_ApplyOp_42__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBitwise_ApplyOp_43__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBitwise_ApplyOp_44__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBitwise_ApplyOp_45__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBitwise_ApplyOp_46__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Xor_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBitwise_ApplyOp_47__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBitwise_ApplyOp_48__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBitwise_ApplyOp_49__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBitwise_ApplyOp_50__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBitwise_ApplyOp_51__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBitwise_ApplyOp_52__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBitwise_ApplyOp_53__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBitwise_ApplyOp_54__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBitwise_ApplyOp_55__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBitwise_ApplyOp_56__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBitwise_ApplyOp_57__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBitwise_ApplyOp_58__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBitwise_ApplyOp_59__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBitwise_ApplyOp_60__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBitwise_ApplyOp_61__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBitwise_ApplyOp_62__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBitwise_ApplyOp_63__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBitwise_ApplyOp_64__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBitwise_ApplyOp_65__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBitwise_ApplyOp_66__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBitwise_ApplyOp_67__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBitwise_ApplyOp_68__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBitwise_ApplyOp_69__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void ILShift_ApplyOp_1__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3839 "cg_arith.c"

static void ILShift_ApplyOp_2__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3847 "cg_arith.c"

static void ILShift_ApplyOp_3__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1649 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_SHL);
	ILGenSimple(info, IL_OP_CONV_I1);
}
#line 3856 "cg_arith.c"

static void ILShift_ApplyOp_4__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1655 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_SHL);
	ILGenSimple(info, IL_OP_CONV_U1);
}
#line 3865 "cg_arith.c"

static void ILShift_ApplyOp_5__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1661 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_SHL);
	ILGenSimple(info, IL_OP_CONV_I2);
}
#line 3874 "cg_arith.c"

static void ILShift_ApplyOp_6__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1668 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_SHL);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 3883 "cg_arith.c"

static void ILShift_ApplyOp_7__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1668 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_SHL);
	ILGenSimple(info, IL_OP_CONV_U2);
}
#line 3892 "cg_arith.c"

static void ILShift_ApplyOp_8__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1679 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHL);
}
#line 3899 "cg_arith.c"

static void ILShift_ApplyOp_9__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1679 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHL);
}
#line 3906 "cg_arith.c"

static void ILShift_ApplyOp_10__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1679 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHL);
}
#line 3913 "cg_arith.c"

static void ILShift_ApplyOp_11__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1679 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHL);
}
#line 3920 "cg_arith.c"

static void ILShift_ApplyOp_12__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1679 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHL);
}
#line 3927 "cg_arith.c"

static void ILShift_ApplyOp_13__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1679 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHL);
}
#line 3934 "cg_arith.c"

static void ILShift_ApplyOp_14__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3942 "cg_arith.c"

static void ILShift_ApplyOp_15__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3950 "cg_arith.c"

static void ILShift_ApplyOp_16__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3958 "cg_arith.c"

static void ILShift_ApplyOp_17__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3966 "cg_arith.c"

static void ILShift_ApplyOp_18__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3974 "cg_arith.c"

static void ILShift_ApplyOp_19__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3982 "cg_arith.c"

static void ILShift_ApplyOp_20__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3990 "cg_arith.c"

static void ILShift_ApplyOp_21__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 3998 "cg_arith.c"

static void ILShift_ApplyOp_22__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4006 "cg_arith.c"

static void ILShift_ApplyOp_23__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1694 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4014 "cg_arith.c"

static void ILShift_ApplyOp_24__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4022 "cg_arith.c"

static void ILShift_ApplyOp_25__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4030 "cg_arith.c"

static void ILShift_ApplyOp_26__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4037 "cg_arith.c"

static void ILShift_ApplyOp_27__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4044 "cg_arith.c"

static void ILShift_ApplyOp_28__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4051 "cg_arith.c"

static void ILShift_ApplyOp_29__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4058 "cg_arith.c"

static void ILShift_ApplyOp_30__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4065 "cg_arith.c"

static void ILShift_ApplyOp_31__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4072 "cg_arith.c"

static void ILShift_ApplyOp_32__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1716 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4079 "cg_arith.c"

static void ILShift_ApplyOp_33__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4086 "cg_arith.c"

static void ILShift_ApplyOp_34__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1716 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4093 "cg_arith.c"

static void ILShift_ApplyOp_35__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1710 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR);
}
#line 4100 "cg_arith.c"

static void ILShift_ApplyOp_36__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1716 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4107 "cg_arith.c"

static void ILShift_ApplyOp_37__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4115 "cg_arith.c"

static void ILShift_ApplyOp_38__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4123 "cg_arith.c"

static void ILShift_ApplyOp_39__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4131 "cg_arith.c"

static void ILShift_ApplyOp_40__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4139 "cg_arith.c"

static void ILShift_ApplyOp_41__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4147 "cg_arith.c"

static void ILShift_ApplyOp_42__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4155 "cg_arith.c"

static void ILShift_ApplyOp_43__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4163 "cg_arith.c"

static void ILShift_ApplyOp_44__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4171 "cg_arith.c"

static void ILShift_ApplyOp_45__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4179 "cg_arith.c"

static void ILShift_ApplyOp_46__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1731 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4187 "cg_arith.c"

static void ILShift_ApplyOp_47__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4195 "cg_arith.c"

static void ILShift_ApplyOp_48__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4203 "cg_arith.c"

static void ILShift_ApplyOp_49__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4210 "cg_arith.c"

static void ILShift_ApplyOp_50__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4217 "cg_arith.c"

static void ILShift_ApplyOp_51__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4224 "cg_arith.c"

static void ILShift_ApplyOp_52__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4231 "cg_arith.c"

static void ILShift_ApplyOp_53__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4238 "cg_arith.c"

static void ILShift_ApplyOp_54__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4245 "cg_arith.c"

static void ILShift_ApplyOp_55__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4252 "cg_arith.c"

static void ILShift_ApplyOp_56__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4259 "cg_arith.c"

static void ILShift_ApplyOp_57__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4266 "cg_arith.c"

static void ILShift_ApplyOp_58__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4273 "cg_arith.c"

static void ILShift_ApplyOp_59__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1750 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SHR_UN);
}
#line 4280 "cg_arith.c"

static void ILShift_ApplyOp_60__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4288 "cg_arith.c"

static void ILShift_ApplyOp_61__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4296 "cg_arith.c"

static void ILShift_ApplyOp_62__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4304 "cg_arith.c"

static void ILShift_ApplyOp_63__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4312 "cg_arith.c"

static void ILShift_ApplyOp_64__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4320 "cg_arith.c"

static void ILShift_ApplyOp_65__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4328 "cg_arith.c"

static void ILShift_ApplyOp_66__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4336 "cg_arith.c"

static void ILShift_ApplyOp_67__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4344 "cg_arith.c"

static void ILShift_ApplyOp_68__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4352 "cg_arith.c"

static void ILShift_ApplyOp_69__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1765 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4360 "cg_arith.c"

void ILShift_ApplyOp(ILGenInfo * info, ILNode_BinaryShift * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_Shl_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILShift_ApplyOp_1__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILShift_ApplyOp_2__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILShift_ApplyOp_3__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILShift_ApplyOp_4__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILShift_ApplyOp_5__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILShift_ApplyOp_6__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILShift_ApplyOp_7__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILShift_ApplyOp_8__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILShift_ApplyOp_9__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILShift_ApplyOp_10__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILShift_ApplyOp_11__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILShift_ApplyOp_12__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILShift_ApplyOp_13__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILShift_ApplyOp_14__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILShift_ApplyOp_15__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILShift_ApplyOp_16__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILShift_ApplyOp_17__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILShift_ApplyOp_18__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILShift_ApplyOp_19__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILShift_ApplyOp_20__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILShift_ApplyOp_21__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILShift_ApplyOp_22__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILShift_ApplyOp_23__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Shr_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILShift_ApplyOp_24__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILShift_ApplyOp_25__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILShift_ApplyOp_26__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILShift_ApplyOp_27__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILShift_ApplyOp_28__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILShift_ApplyOp_29__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILShift_ApplyOp_30__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILShift_ApplyOp_31__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILShift_ApplyOp_32__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILShift_ApplyOp_33__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILShift_ApplyOp_34__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILShift_ApplyOp_35__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILShift_ApplyOp_36__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILShift_ApplyOp_37__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILShift_ApplyOp_38__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILShift_ApplyOp_39__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILShift_ApplyOp_40__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILShift_ApplyOp_41__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILShift_ApplyOp_42__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILShift_ApplyOp_43__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILShift_ApplyOp_44__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILShift_ApplyOp_45__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILShift_ApplyOp_46__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_UShr_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILShift_ApplyOp_47__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILShift_ApplyOp_48__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILShift_ApplyOp_49__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILShift_ApplyOp_50__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILShift_ApplyOp_51__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILShift_ApplyOp_52__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILShift_ApplyOp_53__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILShift_ApplyOp_54__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILShift_ApplyOp_55__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILShift_ApplyOp_56__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILShift_ApplyOp_57__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILShift_ApplyOp_58__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILShift_ApplyOp_59__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILShift_ApplyOp_60__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILShift_ApplyOp_61__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILShift_ApplyOp_62__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILShift_ApplyOp_63__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILShift_ApplyOp_64__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILShift_ApplyOp_65__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILShift_ApplyOp_66__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILShift_ApplyOp_67__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILShift_ApplyOp_68__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILShift_ApplyOp_69__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void ILBinary_ApplyOp_1__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 997 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4817 "cg_arith.c"

static void ILBinary_ApplyOp_2__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 997 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 4825 "cg_arith.c"

static void ILBinary_ApplyOp_3__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 876 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_ADD);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I1);
	}
}
#line 4841 "cg_arith.c"

static void ILBinary_ApplyOp_4__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 889 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_ADD);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U1);
	}
}
#line 4857 "cg_arith.c"

static void ILBinary_ApplyOp_5__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 902 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_ADD);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I2);
	}
}
#line 4873 "cg_arith.c"

static void ILBinary_ApplyOp_6__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 916 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_ADD);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 4889 "cg_arith.c"

static void ILBinary_ApplyOp_7__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 916 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_ADD);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 4905 "cg_arith.c"

static void ILBinary_ApplyOp_8__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 931 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_ADD_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_ADD);
	}
}
#line 4919 "cg_arith.c"

static void ILBinary_ApplyOp_9__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 945 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_ADD_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_ADD);
	}
}
#line 4933 "cg_arith.c"

static void ILBinary_ApplyOp_10__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 931 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_ADD_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_ADD);
	}
}
#line 4947 "cg_arith.c"

static void ILBinary_ApplyOp_11__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 945 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_ADD_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_ADD);
	}
}
#line 4961 "cg_arith.c"

static void ILBinary_ApplyOp_12__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 931 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_ADD_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_ADD);
	}
}
#line 4975 "cg_arith.c"

static void ILBinary_ApplyOp_13__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 945 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_ADD_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_ADD);
	}
}
#line 4989 "cg_arith.c"

static void ILBinary_ApplyOp_14__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 956 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_ADD);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float32" */
		ILGenSimple(info, IL_OP_CONV_R4);
	}
}
#line 5001 "cg_arith.c"

static void ILBinary_ApplyOp_15__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 965 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_ADD);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float64" */
		ILGenSimple(info, IL_OP_CONV_R8);
	}
}
#line 5013 "cg_arith.c"

static void ILBinary_ApplyOp_16__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 974 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_ADD);
}
#line 5020 "cg_arith.c"

static void ILBinary_ApplyOp_17__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 978 "cg_arith.tc"
{
	ILGenCallByName(info,
		"valuetype [.library]System.Decimal "
			"[.library]System.Decimal::op_Addition"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 5031 "cg_arith.c"

static void ILBinary_ApplyOp_18__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 986 "cg_arith.tc"
{
	ILGenCallByName(info,
		"class [.library]System.String [.library]System.String::Concat"
			"(class [.library]System.String, class [.library]System.String)");
}
#line 5040 "cg_arith.c"

static void ILBinary_ApplyOp_19__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 997 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5048 "cg_arith.c"

static void ILBinary_ApplyOp_20__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 945 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_ADD_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_ADD);
	}
}
#line 5062 "cg_arith.c"

static void ILBinary_ApplyOp_21__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 997 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5070 "cg_arith.c"

static void ILBinary_ApplyOp_22__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 997 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5078 "cg_arith.c"

static void ILBinary_ApplyOp_23__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 997 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5086 "cg_arith.c"

static void ILBinary_ApplyOp_24__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1122 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5094 "cg_arith.c"

static void ILBinary_ApplyOp_25__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1122 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5102 "cg_arith.c"

static void ILBinary_ApplyOp_26__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1006 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_SUB);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I1);
	}
}
#line 5118 "cg_arith.c"

static void ILBinary_ApplyOp_27__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1019 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_SUB);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U1);
	}
}
#line 5134 "cg_arith.c"

static void ILBinary_ApplyOp_28__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1032 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_SUB);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I2);
	}
}
#line 5150 "cg_arith.c"

static void ILBinary_ApplyOp_29__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1046 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_SUB);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5166 "cg_arith.c"

static void ILBinary_ApplyOp_30__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1046 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_SUB);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5182 "cg_arith.c"

static void ILBinary_ApplyOp_31__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1061 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_SUB_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_SUB);
	}
}
#line 5196 "cg_arith.c"

static void ILBinary_ApplyOp_32__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1075 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_SUB_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_SUB);
	}
}
#line 5210 "cg_arith.c"

static void ILBinary_ApplyOp_33__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1061 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_SUB_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_SUB);
	}
}
#line 5224 "cg_arith.c"

static void ILBinary_ApplyOp_34__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1075 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_SUB_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_SUB);
	}
}
#line 5238 "cg_arith.c"

static void ILBinary_ApplyOp_35__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1061 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_SUB_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_SUB);
	}
}
#line 5252 "cg_arith.c"

static void ILBinary_ApplyOp_36__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1075 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_SUB_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_SUB);
	}
}
#line 5266 "cg_arith.c"

static void ILBinary_ApplyOp_37__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1086 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SUB);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float32" */
		ILGenSimple(info, IL_OP_CONV_R4);
	}
}
#line 5278 "cg_arith.c"

static void ILBinary_ApplyOp_38__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1095 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SUB);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float64" */
		ILGenSimple(info, IL_OP_CONV_R8);
	}
}
#line 5290 "cg_arith.c"

static void ILBinary_ApplyOp_39__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1104 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_SUB);
}
#line 5297 "cg_arith.c"

static void ILBinary_ApplyOp_40__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1108 "cg_arith.tc"
{
	ILGenCallByName(info,
		"valuetype [.library]System.Decimal "
			"[.library]System.Decimal::op_Subtraction"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 5308 "cg_arith.c"

static void ILBinary_ApplyOp_41__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1122 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5316 "cg_arith.c"

static void ILBinary_ApplyOp_42__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1122 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5324 "cg_arith.c"

static void ILBinary_ApplyOp_43__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1075 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_SUB_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_SUB);
	}
}
#line 5338 "cg_arith.c"

static void ILBinary_ApplyOp_44__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1122 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5346 "cg_arith.c"

static void ILBinary_ApplyOp_45__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1122 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5354 "cg_arith.c"

static void ILBinary_ApplyOp_46__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 1122 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5362 "cg_arith.c"

static void ILBinary_ApplyOp_47__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5370 "cg_arith.c"

static void ILBinary_ApplyOp_48__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5378 "cg_arith.c"

static void ILBinary_ApplyOp_49__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1131 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_MUL);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I1);
	}
}
#line 5394 "cg_arith.c"

static void ILBinary_ApplyOp_50__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1144 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_MUL);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U1);
	}
}
#line 5410 "cg_arith.c"

static void ILBinary_ApplyOp_51__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1157 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_MUL);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I2);
	}
}
#line 5426 "cg_arith.c"

static void ILBinary_ApplyOp_52__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1171 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_MUL);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5442 "cg_arith.c"

static void ILBinary_ApplyOp_53__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1171 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_MUL);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5458 "cg_arith.c"

static void ILBinary_ApplyOp_54__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1186 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_MUL_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_MUL);
	}
}
#line 5472 "cg_arith.c"

static void ILBinary_ApplyOp_55__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1199 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_MUL_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_MUL);
	}
}
#line 5486 "cg_arith.c"

static void ILBinary_ApplyOp_56__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1186 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_MUL_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_MUL);
	}
}
#line 5500 "cg_arith.c"

static void ILBinary_ApplyOp_57__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1199 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_MUL_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_MUL);
	}
}
#line 5514 "cg_arith.c"

static void ILBinary_ApplyOp_58__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1186 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_MUL_OVF);
	}
	else
	{
		ILGenSimple(info, IL_OP_MUL);
	}
}
#line 5528 "cg_arith.c"

static void ILBinary_ApplyOp_59__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1199 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_MUL_OVF_UN);
	}
	else
	{
		ILGenSimple(info, IL_OP_MUL);
	}
}
#line 5542 "cg_arith.c"

static void ILBinary_ApplyOp_60__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1210 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_MUL);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float32" */
		ILGenSimple(info, IL_OP_CONV_R4);
	}
}
#line 5554 "cg_arith.c"

static void ILBinary_ApplyOp_61__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1219 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_MUL);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float64" */
		ILGenSimple(info, IL_OP_CONV_R8);
	}
}
#line 5566 "cg_arith.c"

static void ILBinary_ApplyOp_62__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1228 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_MUL);
}
#line 5573 "cg_arith.c"

static void ILBinary_ApplyOp_63__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1232 "cg_arith.tc"
{
	ILGenCallByName(info,
		"valuetype [.library]System.Decimal "
			"[.library]System.Decimal::op_Multiply"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 5584 "cg_arith.c"

static void ILBinary_ApplyOp_64__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5592 "cg_arith.c"

static void ILBinary_ApplyOp_65__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5600 "cg_arith.c"

static void ILBinary_ApplyOp_66__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5608 "cg_arith.c"

static void ILBinary_ApplyOp_67__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5616 "cg_arith.c"

static void ILBinary_ApplyOp_68__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5624 "cg_arith.c"

static void ILBinary_ApplyOp_69__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 1247 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5632 "cg_arith.c"

static void ILBinary_ApplyOp_70__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5640 "cg_arith.c"

static void ILBinary_ApplyOp_71__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5648 "cg_arith.c"

static void ILBinary_ApplyOp_72__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1256 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_DIV);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I1);
	}
}
#line 5664 "cg_arith.c"

static void ILBinary_ApplyOp_73__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1269 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_DIV);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U1);
	}
}
#line 5680 "cg_arith.c"

static void ILBinary_ApplyOp_74__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1282 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_DIV);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I2);
	}
}
#line 5696 "cg_arith.c"

static void ILBinary_ApplyOp_75__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1296 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_DIV);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5712 "cg_arith.c"

static void ILBinary_ApplyOp_76__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1296 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_DIV);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5728 "cg_arith.c"

static void ILBinary_ApplyOp_77__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1312 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV);
}
#line 5735 "cg_arith.c"

static void ILBinary_ApplyOp_78__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1318 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV_UN);
}
#line 5742 "cg_arith.c"

static void ILBinary_ApplyOp_79__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1312 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV);
}
#line 5749 "cg_arith.c"

static void ILBinary_ApplyOp_80__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1318 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV_UN);
}
#line 5756 "cg_arith.c"

static void ILBinary_ApplyOp_81__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1312 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV);
}
#line 5763 "cg_arith.c"

static void ILBinary_ApplyOp_82__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1318 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV_UN);
}
#line 5770 "cg_arith.c"

static void ILBinary_ApplyOp_83__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1322 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float32" */
		ILGenSimple(info, IL_OP_CONV_R4);
	}
}
#line 5782 "cg_arith.c"

static void ILBinary_ApplyOp_84__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1331 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float64" */
		ILGenSimple(info, IL_OP_CONV_R8);
	}
}
#line 5794 "cg_arith.c"

static void ILBinary_ApplyOp_85__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1312 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_DIV);
}
#line 5801 "cg_arith.c"

static void ILBinary_ApplyOp_86__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1340 "cg_arith.tc"
{
	ILGenCallByName(info,
		"valuetype [.library]System.Decimal "
			"[.library]System.Decimal::op_Division"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 5812 "cg_arith.c"

static void ILBinary_ApplyOp_87__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5820 "cg_arith.c"

static void ILBinary_ApplyOp_88__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5828 "cg_arith.c"

static void ILBinary_ApplyOp_89__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5836 "cg_arith.c"

static void ILBinary_ApplyOp_90__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5844 "cg_arith.c"

static void ILBinary_ApplyOp_91__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5852 "cg_arith.c"

static void ILBinary_ApplyOp_92__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 1355 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5860 "cg_arith.c"

static void ILBinary_ApplyOp_93__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5868 "cg_arith.c"

static void ILBinary_ApplyOp_94__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 5876 "cg_arith.c"

static void ILBinary_ApplyOp_95__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1364 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	ILGenSimple(info, IL_OP_REM);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I1);
	}
}
#line 5892 "cg_arith.c"

static void ILBinary_ApplyOp_96__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1377 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	ILGenSimple(info, IL_OP_REM);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U1);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U1);
	}
}
#line 5908 "cg_arith.c"

static void ILBinary_ApplyOp_97__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1390 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	ILGenSimple(info, IL_OP_REM);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_I2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_I2);
	}
}
#line 5924 "cg_arith.c"

static void ILBinary_ApplyOp_98__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1404 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_REM);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5940 "cg_arith.c"

static void ILBinary_ApplyOp_99__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1404 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	ILGenSimple(info, IL_OP_REM);
	if(info->overflowInsns)
	{
		ILGenSimple(info, IL_OP_CONV_OVF_U2);
	}
	else
	{
		ILGenSimple(info, IL_OP_CONV_U2);
	}
}
#line 5956 "cg_arith.c"

static void ILBinary_ApplyOp_100__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1420 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM);
}
#line 5963 "cg_arith.c"

static void ILBinary_ApplyOp_101__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1426 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM_UN);
}
#line 5970 "cg_arith.c"

static void ILBinary_ApplyOp_102__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1420 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM);
}
#line 5977 "cg_arith.c"

static void ILBinary_ApplyOp_103__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1426 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM_UN);
}
#line 5984 "cg_arith.c"

static void ILBinary_ApplyOp_104__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1420 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM);
}
#line 5991 "cg_arith.c"

static void ILBinary_ApplyOp_105__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1426 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM_UN);
}
#line 5998 "cg_arith.c"

static void ILBinary_ApplyOp_106__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1430 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float32" */
		ILGenSimple(info, IL_OP_CONV_R4);
	}
}
#line 6010 "cg_arith.c"

static void ILBinary_ApplyOp_107__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1439 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM);
	if(info->pedanticArith)
	{
		/* Clamp the result back to "float64" */
		ILGenSimple(info, IL_OP_CONV_R8);
	}
}
#line 6022 "cg_arith.c"

static void ILBinary_ApplyOp_108__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1420 "cg_arith.tc"
{
	ILGenSimple(info, IL_OP_REM);
}
#line 6029 "cg_arith.c"

static void ILBinary_ApplyOp_109__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1448 "cg_arith.tc"
{
	ILGenCallByName(info,
		"valuetype [.library]System.Decimal "
			"[.library]System.Decimal::op_Modulus"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 6040 "cg_arith.c"

static void ILBinary_ApplyOp_110__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 6048 "cg_arith.c"

static void ILBinary_ApplyOp_111__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 6056 "cg_arith.c"

static void ILBinary_ApplyOp_112__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 6064 "cg_arith.c"

static void ILBinary_ApplyOp_113__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 6072 "cg_arith.c"

static void ILBinary_ApplyOp_114__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 6080 "cg_arith.c"

static void ILBinary_ApplyOp_115__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1463 "cg_arith.tc"
{
	/* Default - should never be used */
	ILGenSimple(info, IL_OP_POP);
}
#line 6088 "cg_arith.c"

void ILBinary_ApplyOp(ILGenInfo * info, ILNode_BinaryArith * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_Add_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBinary_ApplyOp_1__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBinary_ApplyOp_2__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBinary_ApplyOp_3__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBinary_ApplyOp_4__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBinary_ApplyOp_5__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBinary_ApplyOp_6__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBinary_ApplyOp_7__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBinary_ApplyOp_8__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBinary_ApplyOp_9__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBinary_ApplyOp_10__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBinary_ApplyOp_11__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBinary_ApplyOp_12__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBinary_ApplyOp_13__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBinary_ApplyOp_14__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBinary_ApplyOp_15__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBinary_ApplyOp_16__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBinary_ApplyOp_17__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBinary_ApplyOp_18__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBinary_ApplyOp_19__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBinary_ApplyOp_20__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBinary_ApplyOp_21__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBinary_ApplyOp_22__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBinary_ApplyOp_23__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Sub_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBinary_ApplyOp_24__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBinary_ApplyOp_25__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBinary_ApplyOp_26__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBinary_ApplyOp_27__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBinary_ApplyOp_28__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBinary_ApplyOp_29__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBinary_ApplyOp_30__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBinary_ApplyOp_31__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBinary_ApplyOp_32__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBinary_ApplyOp_33__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBinary_ApplyOp_34__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBinary_ApplyOp_35__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBinary_ApplyOp_36__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBinary_ApplyOp_37__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBinary_ApplyOp_38__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBinary_ApplyOp_39__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBinary_ApplyOp_40__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBinary_ApplyOp_41__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBinary_ApplyOp_42__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBinary_ApplyOp_43__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBinary_ApplyOp_44__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBinary_ApplyOp_45__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBinary_ApplyOp_46__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Mul_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBinary_ApplyOp_47__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBinary_ApplyOp_48__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBinary_ApplyOp_49__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBinary_ApplyOp_50__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBinary_ApplyOp_51__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBinary_ApplyOp_52__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBinary_ApplyOp_53__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBinary_ApplyOp_54__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBinary_ApplyOp_55__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBinary_ApplyOp_56__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBinary_ApplyOp_57__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBinary_ApplyOp_58__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBinary_ApplyOp_59__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBinary_ApplyOp_60__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBinary_ApplyOp_61__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBinary_ApplyOp_62__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBinary_ApplyOp_63__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBinary_ApplyOp_64__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBinary_ApplyOp_65__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBinary_ApplyOp_66__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBinary_ApplyOp_67__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBinary_ApplyOp_68__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBinary_ApplyOp_69__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Div_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBinary_ApplyOp_70__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBinary_ApplyOp_71__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBinary_ApplyOp_72__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBinary_ApplyOp_73__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBinary_ApplyOp_74__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBinary_ApplyOp_75__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBinary_ApplyOp_76__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBinary_ApplyOp_77__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBinary_ApplyOp_78__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBinary_ApplyOp_79__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBinary_ApplyOp_80__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBinary_ApplyOp_81__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBinary_ApplyOp_82__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBinary_ApplyOp_83__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBinary_ApplyOp_84__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBinary_ApplyOp_85__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBinary_ApplyOp_86__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBinary_ApplyOp_87__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBinary_ApplyOp_88__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBinary_ApplyOp_89__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBinary_ApplyOp_90__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBinary_ApplyOp_91__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBinary_ApplyOp_92__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Rem_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILBinary_ApplyOp_93__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILBinary_ApplyOp_94__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILBinary_ApplyOp_95__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILBinary_ApplyOp_96__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILBinary_ApplyOp_97__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILBinary_ApplyOp_98__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILBinary_ApplyOp_99__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILBinary_ApplyOp_100__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILBinary_ApplyOp_101__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILBinary_ApplyOp_102__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILBinary_ApplyOp_103__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILBinary_ApplyOp_104__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILBinary_ApplyOp_105__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILBinary_ApplyOp_106__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILBinary_ApplyOp_107__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILBinary_ApplyOp_108__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILBinary_ApplyOp_109__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILBinary_ApplyOp_110__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILBinary_ApplyOp_111__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILBinary_ApplyOp_112__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILBinary_ApplyOp_113__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILBinary_ApplyOp_114__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILBinary_ApplyOp_115__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

void ILNegate_ApplyOp(ILGenInfo * info, ILNode_Neg * node, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 6844 "cg_arith.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 6855 "cg_arith.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1774 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 6874 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1787 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
				ILGenSimple(info, IL_OP_CONV_U1);
			}
#line 6886 "cg_arith.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1793 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 6905 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 1807 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
				ILGenSimple(info, IL_OP_CONV_U2);
			}
#line 6917 "cg_arith.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 1807 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
				ILGenSimple(info, IL_OP_CONV_U2);
			}
#line 6929 "cg_arith.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 1813 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					/* We need to detect overflow while performing the negation,
					   and there is no "NEG_OVF" operation to do that.  So, we
					   subtract the argument from zero instead */
					ILGenSimple(info, IL_OP_LDC_I4_0);
					ILGenAdjust(info, 1);
					ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
					ILGenSimple(info, IL_OP_SUB_OVF);
					ILGenAdjust(info, -1);
				}
				else
				{
					ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
					ILGenSimple(info, IL_OP_NEG);
				}
			}
#line 6954 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1875 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
			}
#line 6965 "cg_arith.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1832 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					/* We need to detect overflow while performing the negation,
					   and there is no "NEG_OVF" operation to do that.  So, we
					   subtract the argument from zero instead */
					ILGenInt64(info, (ILInt64)0);
					ILGenAdjust(info, 1);
					ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
					ILGenSimple(info, IL_OP_SUB_OVF);
					ILGenAdjust(info, -1);
				}
				else
				{
					ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
					ILGenSimple(info, IL_OP_NEG);
				}
			}
#line 6990 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1875 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
			}
#line 7001 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 1851 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					/* We need to detect overflow while performing the negation,
					   and there is no "NEG_OVF" operation to do that.  So, we
					   subtract the argument from zero instead */
					ILGenIntNative(info, (ILInt32)0);
					ILGenAdjust(info, 1);
					ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
					ILGenSimple(info, IL_OP_SUB_OVF);
					ILGenAdjust(info, -1);
				}
				else
				{
					ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
					ILGenSimple(info, IL_OP_NEG);
				}
			}
#line 7026 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1875 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
			}
#line 7037 "cg_arith.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1875 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
			}
#line 7048 "cg_arith.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1875 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
			}
#line 7059 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1875 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenSimple(info, IL_OP_NEG);
			}
#line 7070 "cg_arith.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1880 "cg_arith.tc"
			{
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
				ILGenCallByName(info,
					"valuetype [.library]System.Decimal "
						"[.library]System.Decimal::op_UnaryNegation"
						"(valuetype [.library]System.Decimal)");
			}
#line 7084 "cg_arith.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 7095 "cg_arith.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 7106 "cg_arith.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 7117 "cg_arith.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 7128 "cg_arith.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 7139 "cg_arith.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1895 "cg_arith.tc"
			{
				/* Default - should never be used */
				ILGenCast(info, ILNode_GenValue(node->expr, info), commonType);
			}
#line 7150 "cg_arith.c"
		}
		break;

		default: break;
	}
}

static int ILBitwise_EvalOp_1__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2757 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	value1->un.i4Value =
		(ILInt32)(ILInt8)(value1->un.i4Value & value2->un.i4Value);
	return 1;
}
#line 7166 "cg_arith.c"

static int ILBitwise_EvalOp_2__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2764 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	value1->un.i4Value =
		(ILInt32)(ILUInt8)(value1->un.i4Value & value2->un.i4Value);
	return 1;
}
#line 7176 "cg_arith.c"

static int ILBitwise_EvalOp_3__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2771 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	value1->un.i4Value =
		(ILInt32)(ILInt16)(value1->un.i4Value & value2->un.i4Value);
	return 1;
}
#line 7186 "cg_arith.c"

static int ILBitwise_EvalOp_4__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2779 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value & value2->un.i4Value);
	return 1;
}
#line 7196 "cg_arith.c"

static int ILBitwise_EvalOp_5__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2779 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value & value2->un.i4Value);
	return 1;
}
#line 7206 "cg_arith.c"

static int ILBitwise_EvalOp_6__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2789 "cg_arith.tc"
{
	value1->un.i4Value &= value2->un.i4Value;
	return 1;
}
#line 7214 "cg_arith.c"

static int ILBitwise_EvalOp_7__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2789 "cg_arith.tc"
{
	value1->un.i4Value &= value2->un.i4Value;
	return 1;
}
#line 7222 "cg_arith.c"

static int ILBitwise_EvalOp_8__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2795 "cg_arith.tc"
{
	value1->un.i8Value &= value2->un.i8Value;
	return 1;
}
#line 7230 "cg_arith.c"

static int ILBitwise_EvalOp_9__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2795 "cg_arith.tc"
{
	value1->un.i8Value &= value2->un.i8Value;
	return 1;
}
#line 7238 "cg_arith.c"

static int ILBitwise_EvalOp_10__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2789 "cg_arith.tc"
{
	value1->un.i4Value &= value2->un.i4Value;
	return 1;
}
#line 7246 "cg_arith.c"

static int ILBitwise_EvalOp_11__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2789 "cg_arith.tc"
{
	value1->un.i4Value &= value2->un.i4Value;
	return 1;
}
#line 7254 "cg_arith.c"

static int ILBitwise_EvalOp_12__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2800 "cg_arith.tc"
{
	return 0;
}
#line 7261 "cg_arith.c"

static int ILBitwise_EvalOp_13__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2808 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	value1->un.i4Value =
		(ILInt32)(ILInt8)(value1->un.i4Value | value2->un.i4Value);
	return 1;
}
#line 7271 "cg_arith.c"

static int ILBitwise_EvalOp_14__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2815 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	value1->un.i4Value =
		(ILInt32)(ILUInt8)(value1->un.i4Value | value2->un.i4Value);
	return 1;
}
#line 7281 "cg_arith.c"

static int ILBitwise_EvalOp_15__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2822 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	value1->un.i4Value =
		(ILInt32)(ILInt16)(value1->un.i4Value | value2->un.i4Value);
	return 1;
}
#line 7291 "cg_arith.c"

static int ILBitwise_EvalOp_16__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2830 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value | value2->un.i4Value);
	return 1;
}
#line 7301 "cg_arith.c"

static int ILBitwise_EvalOp_17__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2830 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value | value2->un.i4Value);
	return 1;
}
#line 7311 "cg_arith.c"

static int ILBitwise_EvalOp_18__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2840 "cg_arith.tc"
{
	value1->un.i4Value |= value2->un.i4Value;
	return 1;
}
#line 7319 "cg_arith.c"

static int ILBitwise_EvalOp_19__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2840 "cg_arith.tc"
{
	value1->un.i4Value |= value2->un.i4Value;
	return 1;
}
#line 7327 "cg_arith.c"

static int ILBitwise_EvalOp_20__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2846 "cg_arith.tc"
{
	value1->un.i8Value |= value2->un.i8Value;
	return 1;
}
#line 7335 "cg_arith.c"

static int ILBitwise_EvalOp_21__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2846 "cg_arith.tc"
{
	value1->un.i8Value |= value2->un.i8Value;
	return 1;
}
#line 7343 "cg_arith.c"

static int ILBitwise_EvalOp_22__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2840 "cg_arith.tc"
{
	value1->un.i4Value |= value2->un.i4Value;
	return 1;
}
#line 7351 "cg_arith.c"

static int ILBitwise_EvalOp_23__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2840 "cg_arith.tc"
{
	value1->un.i4Value |= value2->un.i4Value;
	return 1;
}
#line 7359 "cg_arith.c"

static int ILBitwise_EvalOp_24__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2851 "cg_arith.tc"
{
	return 0;
}
#line 7366 "cg_arith.c"

static int ILBitwise_EvalOp_25__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2859 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	value1->un.i4Value =
		(ILInt32)(ILInt8)(value1->un.i4Value ^ value2->un.i4Value);
	return 1;
}
#line 7376 "cg_arith.c"

static int ILBitwise_EvalOp_26__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2866 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	value1->un.i4Value =
		(ILInt32)(ILUInt8)(value1->un.i4Value ^ value2->un.i4Value);
	return 1;
}
#line 7386 "cg_arith.c"

static int ILBitwise_EvalOp_27__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2873 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	value1->un.i4Value =
		(ILInt32)(ILInt16)(value1->un.i4Value ^ value2->un.i4Value);
	return 1;
}
#line 7396 "cg_arith.c"

static int ILBitwise_EvalOp_28__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2881 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value ^ value2->un.i4Value);
	return 1;
}
#line 7406 "cg_arith.c"

static int ILBitwise_EvalOp_29__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2881 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value ^ value2->un.i4Value);
	return 1;
}
#line 7416 "cg_arith.c"

static int ILBitwise_EvalOp_30__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2891 "cg_arith.tc"
{
	value1->un.i4Value ^= value2->un.i4Value;
	return 1;
}
#line 7424 "cg_arith.c"

static int ILBitwise_EvalOp_31__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2891 "cg_arith.tc"
{
	value1->un.i4Value ^= value2->un.i4Value;
	return 1;
}
#line 7432 "cg_arith.c"

static int ILBitwise_EvalOp_32__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2897 "cg_arith.tc"
{
	value1->un.i8Value ^= value2->un.i8Value;
	return 1;
}
#line 7440 "cg_arith.c"

static int ILBitwise_EvalOp_33__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2897 "cg_arith.tc"
{
	value1->un.i8Value ^= value2->un.i8Value;
	return 1;
}
#line 7448 "cg_arith.c"

static int ILBitwise_EvalOp_34__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2891 "cg_arith.tc"
{
	value1->un.i4Value ^= value2->un.i4Value;
	return 1;
}
#line 7456 "cg_arith.c"

static int ILBitwise_EvalOp_35__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2891 "cg_arith.tc"
{
	value1->un.i4Value ^= value2->un.i4Value;
	return 1;
}
#line 7464 "cg_arith.c"

static int ILBitwise_EvalOp_36__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2902 "cg_arith.tc"
{
	return 0;
}
#line 7471 "cg_arith.c"

int ILBitwise_EvalOp(ILGenInfo * info, ILNode_BinaryBitwise * node__, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
{
	switch(node__->kind__)
	{
		case ILNode_And_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBitwise_EvalOp_1__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBitwise_EvalOp_2__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBitwise_EvalOp_3__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBitwise_EvalOp_4__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBitwise_EvalOp_5__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBitwise_EvalOp_6__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBitwise_EvalOp_7__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBitwise_EvalOp_8__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBitwise_EvalOp_9__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBitwise_EvalOp_10__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBitwise_EvalOp_11__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBitwise_EvalOp_12__(info, (ILNode_And *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Or_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBitwise_EvalOp_13__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBitwise_EvalOp_14__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBitwise_EvalOp_15__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBitwise_EvalOp_16__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBitwise_EvalOp_17__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBitwise_EvalOp_18__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBitwise_EvalOp_19__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBitwise_EvalOp_20__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBitwise_EvalOp_21__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBitwise_EvalOp_22__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBitwise_EvalOp_23__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBitwise_EvalOp_24__(info, (ILNode_Or *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Xor_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBitwise_EvalOp_25__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBitwise_EvalOp_26__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBitwise_EvalOp_27__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBitwise_EvalOp_28__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBitwise_EvalOp_29__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBitwise_EvalOp_30__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBitwise_EvalOp_31__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBitwise_EvalOp_32__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBitwise_EvalOp_33__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBitwise_EvalOp_34__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBitwise_EvalOp_35__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBitwise_EvalOp_36__(info, (ILNode_Xor *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
	return (0);
}

static int ILBinary_EvalOp_1__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1953 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	if(info->overflowInsns)
	{
		value1->un.i4Value += value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)(-128) ||
		   value1->un.i4Value > (ILInt32)127)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILInt8)(value1->un.i4Value + value2->un.i4Value);
	}
	return 1;
}
#line 7943 "cg_arith.c"

static int ILBinary_EvalOp_2__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1972 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	if(info->overflowInsns)
	{
		value1->un.i4Value += value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)255)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt8)(value1->un.i4Value + value2->un.i4Value);
	}
	return 1;
}
#line 7965 "cg_arith.c"

static int ILBinary_EvalOp_3__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1991 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value += value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)(-32768) ||
		   value1->un.i4Value > (ILInt32)32767)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILInt16)(value1->un.i4Value + value2->un.i4Value);
	}
	return 1;
}
#line 7987 "cg_arith.c"

static int ILBinary_EvalOp_4__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2011 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value += value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)65535)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt16)(value1->un.i4Value + value2->un.i4Value);
	}
	return 1;
}
#line 8009 "cg_arith.c"

static int ILBinary_EvalOp_5__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2011 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value += value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)65535)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt16)(value1->un.i4Value + value2->un.i4Value);
	}
	return 1;
}
#line 8031 "cg_arith.c"

static int ILBinary_EvalOp_6__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2031 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		value1->un.i4Value += value2->un.i4Value;
		if(((ILUInt32)(value1->un.i4Value)) <
				((ILUInt32)(value2->un.i4Value)))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value += value2->un.i4Value;
	}
	return 1;
}
#line 8051 "cg_arith.c"

static int ILBinary_EvalOp_7__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2031 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		value1->un.i4Value += value2->un.i4Value;
		if(((ILUInt32)(value1->un.i4Value)) <
				((ILUInt32)(value2->un.i4Value)))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value += value2->un.i4Value;
	}
	return 1;
}
#line 8071 "cg_arith.c"

static int ILBinary_EvalOp_8__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2049 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		value1->un.i8Value += value2->un.i8Value;
		if(((ILUInt64)(value1->un.i8Value)) <
				((ILUInt64)(value2->un.i8Value)))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i8Value += value2->un.i8Value;
	}
	return 1;
}
#line 8091 "cg_arith.c"

static int ILBinary_EvalOp_9__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2049 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		value1->un.i8Value += value2->un.i8Value;
		if(((ILUInt64)(value1->un.i8Value)) <
				((ILUInt64)(value2->un.i8Value)))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i8Value += value2->un.i8Value;
	}
	return 1;
}
#line 8111 "cg_arith.c"

static int ILBinary_EvalOp_10__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2066 "cg_arith.tc"
{
	ILInt64 testResult = ((ILInt64)(value1->un.i4Value)) +
						 ((ILInt64)(value2->un.i4Value));
	value1->un.i4Value += value2->un.i4Value;
	if(((ILInt64)(value1->un.i4Value)) != testResult)
	{
		/* The operation behaves differently on 32-bit and
		   64-bit platforms, so we must evaluate at runtime */
		return 0;
	}
	if(info->overflowInsns)
	{
		if(((ILUInt32)(value1->un.i4Value)) <
				((ILUInt32)(value2->un.i4Value)))
		{
			return 0;
		}
	}
	return 1;
}
#line 8135 "cg_arith.c"

static int ILBinary_EvalOp_11__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2087 "cg_arith.tc"
{
	ILUInt64 testResult = ((ILUInt64)(ILUInt32)(value1->un.i4Value)) +
						  ((ILUInt64)(ILUInt32)(value2->un.i4Value));
	value1->un.i4Value += value2->un.i4Value;
	if(((ILUInt64)(ILUInt32)(value1->un.i4Value)) != testResult)
	{
		/* The operation behaves differently on 32-bit and
		   64-bit platforms, so we must evaluate at runtime */
		return 0;
	}
	if(info->overflowInsns)
	{
		if(((ILUInt32)(value1->un.i4Value)) <
				((ILUInt32)(value2->un.i4Value)))
		{
			return 0;
		}
	}
	return 1;
}
#line 8159 "cg_arith.c"

static int ILBinary_EvalOp_12__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2108 "cg_arith.tc"
{
	value1->un.r4Value += value2->un.r4Value;
	return 1;
}
#line 8167 "cg_arith.c"

static int ILBinary_EvalOp_13__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2114 "cg_arith.tc"
{
	value1->un.r8Value += value2->un.r8Value;
	return 1;
}
#line 8175 "cg_arith.c"

static int ILBinary_EvalOp_14__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2114 "cg_arith.tc"
{
	value1->un.r8Value += value2->un.r8Value;
	return 1;
}
#line 8183 "cg_arith.c"

static int ILBinary_EvalOp_15__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2119 "cg_arith.tc"
{
	return ILDecimalAdd(&(value1->un.decValue),
						&(value1->un.decValue),
						&(value2->un.decValue),
						info->decimalRoundMode);
}
#line 8193 "cg_arith.c"

static int ILBinary_EvalOp_16__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2126 "cg_arith.tc"
{
	return 0;
}
#line 8200 "cg_arith.c"

static int ILBinary_EvalOp_17__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2134 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	if(info->overflowInsns)
	{
		value1->un.i4Value -= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)(-128) ||
		   value1->un.i4Value > (ILInt32)127)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILInt8)(value1->un.i4Value - value2->un.i4Value);
	}
	return 1;
}
#line 8222 "cg_arith.c"

static int ILBinary_EvalOp_18__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2153 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	if(info->overflowInsns)
	{
		value1->un.i4Value -= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)255)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt8)(value1->un.i4Value - value2->un.i4Value);
	}
	return 1;
}
#line 8244 "cg_arith.c"

static int ILBinary_EvalOp_19__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2172 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value -= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)(-32768) ||
		   value1->un.i4Value > (ILInt32)32767)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILInt16)(value1->un.i4Value - value2->un.i4Value);
	}
	return 1;
}
#line 8266 "cg_arith.c"

static int ILBinary_EvalOp_20__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2192 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value -= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)65535)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt16)(value1->un.i4Value - value2->un.i4Value);
	}
	return 1;
}
#line 8288 "cg_arith.c"

static int ILBinary_EvalOp_21__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2192 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value -= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)65535)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt16)(value1->un.i4Value - value2->un.i4Value);
	}
	return 1;
}
#line 8310 "cg_arith.c"

static int ILBinary_EvalOp_22__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2211 "cg_arith.tc"
{
	int RetVal = 1;
	ILInt32 diff = value1->un.i4Value - value2->un.i4Value;
	if(info->overflowInsns)
	{

		if (((ILUInt32)diff > (ILUInt32)value1->un.i4Value)
			!= (diff < 0))
		{
			RetVal = 0;
		}
	}
	value1->un.i4Value = diff;
	return RetVal;
}
#line 8329 "cg_arith.c"

static int ILBinary_EvalOp_23__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2227 "cg_arith.tc"
{
	int RetVal = 1;
	if(info->overflowInsns && 
	   (ILUInt32)value1->un.i4Value < (ILUInt32)value2->un.i4Value)
	{
		RetVal = 0;
	}
	value1->un.i4Value -= value2->un.i4Value;
	return RetVal;
}
#line 8343 "cg_arith.c"

static int ILBinary_EvalOp_24__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2239 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		value1->un.i8Value -= value2->un.i8Value;
		if(((ILUInt64)(value1->un.i8Value)) >
				((ILUInt64)(value2->un.i8Value)))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i8Value -= value2->un.i8Value;
	}
	return 1;
}
#line 8363 "cg_arith.c"

static int ILBinary_EvalOp_25__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2239 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		value1->un.i8Value -= value2->un.i8Value;
		if(((ILUInt64)(value1->un.i8Value)) >
				((ILUInt64)(value2->un.i8Value)))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i8Value -= value2->un.i8Value;
	}
	return 1;
}
#line 8383 "cg_arith.c"

static int ILBinary_EvalOp_26__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2256 "cg_arith.tc"
{
	ILInt64 testResult = ((ILInt64)(value1->un.i4Value)) -
						 ((ILInt64)(value2->un.i4Value));
	value1->un.i4Value -= value2->un.i4Value;
	if(((ILInt64)(value1->un.i4Value)) != testResult)
	{
		/* The operation behaves differently on 32-bit and
		   64-bit platforms, so we must evaluate at runtime */
		return 0;
	}
	if(info->overflowInsns)
	{
		if(((ILUInt32)(value1->un.i4Value)) >
				((ILUInt32)(value2->un.i4Value)))
		{
			return 0;
		}
	}
	return 1;
}
#line 8407 "cg_arith.c"

static int ILBinary_EvalOp_27__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2277 "cg_arith.tc"
{
	ILUInt64 testResult = ((ILUInt64)(ILUInt32)(value1->un.i4Value)) -
						  ((ILUInt64)(ILUInt32)(value2->un.i4Value));
	value1->un.i4Value -= value2->un.i4Value;
	if(((ILUInt64)(ILUInt32)(value1->un.i4Value)) != testResult)
	{
		/* The operation behaves differently on 32-bit and
		   64-bit platforms, so we must evaluate at runtime */
		return 0;
	}
	if(info->overflowInsns)
	{
		if(((ILUInt32)(value1->un.i4Value)) >
				((ILUInt32)(value2->un.i4Value)))
		{
			return 0;
		}
	}
	return 1;
}
#line 8431 "cg_arith.c"

static int ILBinary_EvalOp_28__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2298 "cg_arith.tc"
{
	value1->un.r4Value -= value2->un.r4Value;
	return 1;
}
#line 8439 "cg_arith.c"

static int ILBinary_EvalOp_29__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2304 "cg_arith.tc"
{
	value1->un.r8Value -= value2->un.r8Value;
	return 1;
}
#line 8447 "cg_arith.c"

static int ILBinary_EvalOp_30__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2304 "cg_arith.tc"
{
	value1->un.r8Value -= value2->un.r8Value;
	return 1;
}
#line 8455 "cg_arith.c"

static int ILBinary_EvalOp_31__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2309 "cg_arith.tc"
{
	return ILDecimalSub(&(value1->un.decValue),
						&(value1->un.decValue),
						&(value2->un.decValue),
						info->decimalRoundMode);
}
#line 8465 "cg_arith.c"

static int ILBinary_EvalOp_32__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2316 "cg_arith.tc"
{
	return 0;
}
#line 8472 "cg_arith.c"

static int ILBinary_EvalOp_33__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2324 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	if(info->overflowInsns)
	{
		value1->un.i4Value *= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)(-128) ||
		   value1->un.i4Value > (ILInt32)127)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILInt8)(value1->un.i4Value * value2->un.i4Value);
	}
	return 1;
}
#line 8494 "cg_arith.c"

static int ILBinary_EvalOp_34__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2343 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	if(info->overflowInsns)
	{
		value1->un.i4Value *= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)255)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt8)(value1->un.i4Value * value2->un.i4Value);
	}
	return 1;
}
#line 8516 "cg_arith.c"

static int ILBinary_EvalOp_35__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2362 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value *= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)(-32768) ||
		   value1->un.i4Value > (ILInt32)32767)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILInt16)(value1->un.i4Value * value2->un.i4Value);
	}
	return 1;
}
#line 8538 "cg_arith.c"

static int ILBinary_EvalOp_36__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2382 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value *= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)65535)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt16)(value1->un.i4Value * value2->un.i4Value);
	}
	return 1;
}
#line 8560 "cg_arith.c"

static int ILBinary_EvalOp_37__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2382 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(info->overflowInsns)
	{
		value1->un.i4Value *= value2->un.i4Value;
		if(value1->un.i4Value < (ILInt32)0 ||
		   value1->un.i4Value > (ILInt32)65535)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(ILUInt16)(value1->un.i4Value * value2->un.i4Value);
	}
	return 1;
}
#line 8582 "cg_arith.c"

static int ILBinary_EvalOp_38__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2401 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILInt64 testResult = ((ILInt64)(value1->un.i4Value)) *
							 ((ILInt64)(value2->un.i4Value));
		value1->un.i4Value *= value2->un.i4Value;
		if(((ILInt64)(value1->un.i4Value)) != testResult)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value *= value2->un.i4Value;
	}
	return 1;
}
#line 8603 "cg_arith.c"

static int ILBinary_EvalOp_39__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2419 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		ILUInt64 testResult = ((ILUInt64)(ILUInt32)(value1->un.i4Value)) *
							  ((ILUInt64)(ILUInt32)(value2->un.i4Value));
		value1->un.i4Value =
			(ILInt32)(((ILUInt32)(value1->un.i4Value)) *
					  ((ILUInt32)(value2->un.i4Value)));
		if(((ILUInt64)(ILUInt32)(value1->un.i4Value)) != testResult)
		{
			return 0;
		}
	}
	else
	{
		value1->un.i4Value =
			(ILInt32)(((ILUInt32)(value1->un.i4Value)) *
					  ((ILUInt32)(value2->un.i4Value)));
	}
	return 1;
}
#line 8628 "cg_arith.c"

static int ILBinary_EvalOp_40__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2441 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		if(!ILInt64MulOvf(&(value1->un.i8Value),
						  value1->un.i8Value, value2->un.i8Value))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i8Value *= value2->un.i8Value;
	}
	return 1;
}
#line 8647 "cg_arith.c"

static int ILBinary_EvalOp_41__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2457 "cg_arith.tc"
{
	if(info->overflowInsns)
	{
		if(!ILUInt64MulOvf((ILUInt64 *)&(value1->un.i8Value),
						   (ILUInt64)(value1->un.i8Value),
						   (ILUInt64)(value2->un.i8Value)))
		{
			return 0;
		}
	}
	else
	{
		value1->un.i8Value = (ILInt64)(((ILUInt64)(value1->un.i8Value)) *
									   ((ILUInt64)(value2->un.i8Value)));
	}
	return 1;
}
#line 8668 "cg_arith.c"

static int ILBinary_EvalOp_42__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2475 "cg_arith.tc"
{
	ILInt64 testResult = ((ILInt64)(value1->un.i4Value)) *
						 ((ILInt64)(value2->un.i4Value));
	value1->un.i4Value *= value2->un.i4Value;
	if(((ILInt64)(value1->un.i4Value)) != testResult)
	{
		/* The operation behaves differently on 32-bit and
		   64-bit platforms, so we must evaluate at runtime.
		   This can also happen because of overflow */
		return 0;
	}
	return 1;
}
#line 8685 "cg_arith.c"

static int ILBinary_EvalOp_43__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2489 "cg_arith.tc"
{
	ILUInt64 testResult = ((ILUInt64)(ILUInt32)(value1->un.i4Value)) *
						  ((ILUInt64)(ILUInt32)(value2->un.i4Value));
	value1->un.i4Value *= value2->un.i4Value;
	if(((ILUInt64)(ILUInt32)(value1->un.i4Value)) != testResult)
	{
		/* The operation behaves differently on 32-bit and
		   64-bit platforms, so we must evaluate at runtime.
		   This can also happen because of overflow */
		return 0;
	}
	return 1;
}
#line 8702 "cg_arith.c"

static int ILBinary_EvalOp_44__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2503 "cg_arith.tc"
{
	value1->un.r4Value *= value2->un.r4Value;
	return 1;
}
#line 8710 "cg_arith.c"

static int ILBinary_EvalOp_45__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2509 "cg_arith.tc"
{
	value1->un.r8Value *= value2->un.r8Value;
	return 1;
}
#line 8718 "cg_arith.c"

static int ILBinary_EvalOp_46__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2509 "cg_arith.tc"
{
	value1->un.r8Value *= value2->un.r8Value;
	return 1;
}
#line 8726 "cg_arith.c"

static int ILBinary_EvalOp_47__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2514 "cg_arith.tc"
{
	return ILDecimalMul(&(value1->un.decValue),
						&(value1->un.decValue),
						&(value2->un.decValue),
						info->decimalRoundMode);
}
#line 8736 "cg_arith.c"

static int ILBinary_EvalOp_48__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2521 "cg_arith.tc"
{
	return 0;
}
#line 8743 "cg_arith.c"

static int ILBinary_EvalOp_49__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2529 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILInt8)(value1->un.i4Value / value2->un.i4Value);
	return 1;
}
#line 8757 "cg_arith.c"

static int ILBinary_EvalOp_50__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2540 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILUInt8)(value1->un.i4Value / value2->un.i4Value);
	return 1;
}
#line 8771 "cg_arith.c"

static int ILBinary_EvalOp_51__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2551 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILInt16)(value1->un.i4Value / value2->un.i4Value);
	return 1;
}
#line 8785 "cg_arith.c"

static int ILBinary_EvalOp_52__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2563 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value / value2->un.i4Value);
	return 1;
}
#line 8799 "cg_arith.c"

static int ILBinary_EvalOp_53__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2563 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value / value2->un.i4Value);
	return 1;
}
#line 8813 "cg_arith.c"

static int ILBinary_EvalOp_54__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2575 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value /= value2->un.i4Value;
	return 1;
}
#line 8825 "cg_arith.c"

static int ILBinary_EvalOp_55__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2585 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(((ILUInt32)(value1->un.i4Value)) /
				  ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 8839 "cg_arith.c"

static int ILBinary_EvalOp_56__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2596 "cg_arith.tc"
{
	if(!(value2->un.i8Value))
	{
		return 0;
	}
	value1->un.i8Value /= value2->un.i8Value;
	return 1;
}
#line 8851 "cg_arith.c"

static int ILBinary_EvalOp_57__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2605 "cg_arith.tc"
{
	if(!(value2->un.i8Value))
	{
		return 0;
	}
	value1->un.i8Value =
		(ILInt64)(((ILUInt64)(value1->un.i8Value)) /
				  ((ILUInt64)(value2->un.i8Value)));
	return 1;
}
#line 8865 "cg_arith.c"

static int ILBinary_EvalOp_58__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2575 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value /= value2->un.i4Value;
	return 1;
}
#line 8877 "cg_arith.c"

static int ILBinary_EvalOp_59__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2585 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(((ILUInt32)(value1->un.i4Value)) /
				  ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 8891 "cg_arith.c"

static int ILBinary_EvalOp_60__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2616 "cg_arith.tc"
{
	value1->un.r4Value /= value2->un.r4Value;
	return 1;
}
#line 8899 "cg_arith.c"

static int ILBinary_EvalOp_61__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2622 "cg_arith.tc"
{
	value1->un.r8Value /= value2->un.r8Value;
	return 1;
}
#line 8907 "cg_arith.c"

static int ILBinary_EvalOp_62__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2622 "cg_arith.tc"
{
	value1->un.r8Value /= value2->un.r8Value;
	return 1;
}
#line 8915 "cg_arith.c"

static int ILBinary_EvalOp_63__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2627 "cg_arith.tc"
{
	return ILDecimalDiv(&(value1->un.decValue),
						&(value1->un.decValue),
						&(value2->un.decValue),
						info->decimalRoundMode);
}
#line 8925 "cg_arith.c"

static int ILBinary_EvalOp_64__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2634 "cg_arith.tc"
{
	return 0;
}
#line 8932 "cg_arith.c"

static int ILBinary_EvalOp_65__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2642 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILInt8)(value1->un.i4Value % value2->un.i4Value);
	return 1;
}
#line 8946 "cg_arith.c"

static int ILBinary_EvalOp_66__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2653 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILUInt8)(value1->un.i4Value % value2->un.i4Value);
	return 1;
}
#line 8960 "cg_arith.c"

static int ILBinary_EvalOp_67__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2664 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILInt16)(value1->un.i4Value % value2->un.i4Value);
	return 1;
}
#line 8974 "cg_arith.c"

static int ILBinary_EvalOp_68__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2676 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value % value2->un.i4Value);
	return 1;
}
#line 8988 "cg_arith.c"

static int ILBinary_EvalOp_69__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2676 "cg_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(ILUInt16)(value1->un.i4Value % value2->un.i4Value);
	return 1;
}
#line 9002 "cg_arith.c"

static int ILBinary_EvalOp_70__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2688 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value %= value2->un.i4Value;
	return 1;
}
#line 9014 "cg_arith.c"

static int ILBinary_EvalOp_71__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2698 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(((ILUInt32)(value1->un.i4Value)) %
				  ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 9028 "cg_arith.c"

static int ILBinary_EvalOp_72__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2709 "cg_arith.tc"
{
	if(!(value2->un.i8Value))
	{
		return 0;
	}
	value1->un.i8Value %= value2->un.i8Value;
	return 1;
}
#line 9040 "cg_arith.c"

static int ILBinary_EvalOp_73__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2718 "cg_arith.tc"
{
	if(!(value2->un.i8Value))
	{
		return 0;
	}
	value1->un.i8Value =
		(ILInt64)(((ILUInt64)(value1->un.i8Value)) %
				  ((ILUInt64)(value2->un.i8Value)));
	return 1;
}
#line 9054 "cg_arith.c"

static int ILBinary_EvalOp_74__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2688 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value %= value2->un.i4Value;
	return 1;
}
#line 9066 "cg_arith.c"

static int ILBinary_EvalOp_75__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2698 "cg_arith.tc"
{
	if(!(value2->un.i4Value))
	{
		return 0;
	}
	value1->un.i4Value =
		(ILInt32)(((ILUInt32)(value1->un.i4Value)) %
				  ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 9080 "cg_arith.c"

static int ILBinary_EvalOp_76__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2729 "cg_arith.tc"
{
	value1->un.r4Value = (ILFloat)ILNativeFloatRem(value1->un.r4Value,
												   value2->un.r4Value);
	return 1;
}
#line 9089 "cg_arith.c"

static int ILBinary_EvalOp_77__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2736 "cg_arith.tc"
{
	value1->un.r8Value = (ILDouble)ILNativeFloatRem(value1->un.r8Value,
												    value2->un.r8Value);
	return 1;
}
#line 9098 "cg_arith.c"

static int ILBinary_EvalOp_78__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2736 "cg_arith.tc"
{
	value1->un.r8Value = (ILDouble)ILNativeFloatRem(value1->un.r8Value,
												    value2->un.r8Value);
	return 1;
}
#line 9107 "cg_arith.c"

static int ILBinary_EvalOp_79__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2742 "cg_arith.tc"
{
	return ILDecimalRem(&(value1->un.decValue),
						&(value1->un.decValue),
						&(value2->un.decValue),
						info->decimalRoundMode);
}
#line 9117 "cg_arith.c"

static int ILBinary_EvalOp_80__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 2749 "cg_arith.tc"
{
	return 0;
}
#line 9124 "cg_arith.c"

int ILBinary_EvalOp(ILGenInfo * info, ILNode_BinaryArith * node__, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
{
	switch(node__->kind__)
	{
		case ILNode_Add_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBinary_EvalOp_1__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBinary_EvalOp_2__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBinary_EvalOp_3__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBinary_EvalOp_4__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBinary_EvalOp_5__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBinary_EvalOp_6__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBinary_EvalOp_7__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBinary_EvalOp_8__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBinary_EvalOp_9__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBinary_EvalOp_10__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBinary_EvalOp_11__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBinary_EvalOp_12__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBinary_EvalOp_13__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBinary_EvalOp_14__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBinary_EvalOp_15__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBinary_EvalOp_16__(info, (ILNode_Add *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Sub_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBinary_EvalOp_17__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBinary_EvalOp_18__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBinary_EvalOp_19__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBinary_EvalOp_20__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBinary_EvalOp_21__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBinary_EvalOp_22__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBinary_EvalOp_23__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBinary_EvalOp_24__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBinary_EvalOp_25__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBinary_EvalOp_26__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBinary_EvalOp_27__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBinary_EvalOp_28__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBinary_EvalOp_29__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBinary_EvalOp_30__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBinary_EvalOp_31__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBinary_EvalOp_32__(info, (ILNode_Sub *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Mul_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBinary_EvalOp_33__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBinary_EvalOp_34__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBinary_EvalOp_35__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBinary_EvalOp_36__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBinary_EvalOp_37__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBinary_EvalOp_38__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBinary_EvalOp_39__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBinary_EvalOp_40__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBinary_EvalOp_41__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBinary_EvalOp_42__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBinary_EvalOp_43__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBinary_EvalOp_44__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBinary_EvalOp_45__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBinary_EvalOp_46__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBinary_EvalOp_47__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBinary_EvalOp_48__(info, (ILNode_Mul *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Div_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBinary_EvalOp_49__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBinary_EvalOp_50__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBinary_EvalOp_51__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBinary_EvalOp_52__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBinary_EvalOp_53__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBinary_EvalOp_54__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBinary_EvalOp_55__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBinary_EvalOp_56__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBinary_EvalOp_57__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBinary_EvalOp_58__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBinary_EvalOp_59__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBinary_EvalOp_60__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBinary_EvalOp_61__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBinary_EvalOp_62__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBinary_EvalOp_63__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBinary_EvalOp_64__(info, (ILNode_Div *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Rem_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILBinary_EvalOp_65__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILBinary_EvalOp_66__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILBinary_EvalOp_67__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILBinary_EvalOp_68__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILBinary_EvalOp_69__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILBinary_EvalOp_70__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILBinary_EvalOp_71__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILBinary_EvalOp_72__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILBinary_EvalOp_73__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILBinary_EvalOp_74__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILBinary_EvalOp_75__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILBinary_EvalOp_76__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILBinary_EvalOp_77__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILBinary_EvalOp_78__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILBinary_EvalOp_79__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILBinary_EvalOp_80__(info, (ILNode_Rem *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
	return (0);
}

int ILNegate_EvalOp(ILGenInfo * info, ILMachineType commonType, ILEvalValue * value)
{
	switch(commonType)
	{
		case ILMachineType_Int8:
		{
#line 3091 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					value->un.i4Value = -(value->un.i4Value);
					if(value->un.i4Value < (ILInt32)(-128) ||
					   value->un.i4Value > (ILInt32)127)
					{
						return 0;
					}
					return 1;
				}
				else
				{
					value->un.i4Value = (ILInt32)(ILInt8)(-(value->un.i4Value));
					return 1;
				}
			}
#line 9894 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 3109 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILUInt8)(-(value->un.i4Value));
				return 1;
			}
#line 9905 "cg_arith.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 3114 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					value->un.i4Value = -(value->un.i4Value);
					if(value->un.i4Value < (ILInt32)(-32768) ||
					   value->un.i4Value > (ILInt32)32767)
					{
						return 0;
					}
					return 1;
				}
				else
				{
					value->un.i4Value = (ILInt32)(ILInt16)(-(value->un.i4Value));
					return 1;
				}
			}
#line 9929 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 3133 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILUInt16)(-(value->un.i4Value));
				return 1;
			}
#line 9940 "cg_arith.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 3133 "cg_arith.tc"
			{
				value->un.i4Value = (ILInt32)(ILUInt16)(-(value->un.i4Value));
				return 1;
			}
#line 9951 "cg_arith.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 3139 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value == IL_MIN_INT32)
					{
						return 0;
					}
				}
				value->un.i4Value = -(value->un.i4Value);
				return 1;
			}
#line 9969 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 3164 "cg_arith.tc"
			{
				value->un.i4Value = -(value->un.i4Value);
				return 1;
			}
#line 9980 "cg_arith.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 3151 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value == IL_MIN_INT64)
					{
						return 0;
					}
				}
				value->un.i8Value = -(value->un.i8Value);
				return 1;
			}
#line 9998 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 3169 "cg_arith.tc"
			{
				value->un.i8Value = -(value->un.i4Value);
				return 1;
			}
#line 10009 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 3139 "cg_arith.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value == IL_MIN_INT32)
					{
						return 0;
					}
				}
				value->un.i4Value = -(value->un.i4Value);
				return 1;
			}
#line 10027 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 3164 "cg_arith.tc"
			{
				value->un.i4Value = -(value->un.i4Value);
				return 1;
			}
#line 10038 "cg_arith.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 3174 "cg_arith.tc"
			{
				value->un.r4Value = -(value->un.r4Value);
				return 1;
			}
#line 10049 "cg_arith.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3180 "cg_arith.tc"
			{
				value->un.r8Value = -(value->un.r8Value);
				return 1;
			}
#line 10060 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3180 "cg_arith.tc"
			{
				value->un.r8Value = -(value->un.r8Value);
				return 1;
			}
#line 10071 "cg_arith.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3185 "cg_arith.tc"
			{
				ILDecimalNeg(&(value->un.decValue), &(value->un.decValue));
				return 1;
			}
#line 10082 "cg_arith.c"
		}
		break;

		case ILMachineType_Void:
		case ILMachineType_Boolean:
		case ILMachineType_String:
		case ILMachineType_ObjectRef:
		case ILMachineType_UnmanagedPtr:
		case ILMachineType_ManagedPtr:
		case ILMachineType_TransientPtr:
		case ILMachineType_ManagedValue:
		{
#line 3190 "cg_arith.tc"
			{
				return 0;
			}
#line 10099 "cg_arith.c"
		}
		break;

		default: break;
	}
	return (0);
}

void ILNot_ApplyOp(ILGenInfo * info, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10118 "cg_arith.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10128 "cg_arith.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1904 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
				ILGenSimple(info, IL_OP_CONV_I1);
			}
#line 10139 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1909 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
				ILGenSimple(info, IL_OP_CONV_U1);
			}
#line 10150 "cg_arith.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1914 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
				ILGenSimple(info, IL_OP_CONV_I2);
			}
#line 10161 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 1920 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
				ILGenSimple(info, IL_OP_CONV_U2);
			}
#line 10172 "cg_arith.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 1920 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
				ILGenSimple(info, IL_OP_CONV_U2);
			}
#line 10183 "cg_arith.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 1930 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
			}
#line 10193 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1930 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
			}
#line 10203 "cg_arith.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1930 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
			}
#line 10213 "cg_arith.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1930 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
			}
#line 10223 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 1930 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
			}
#line 10233 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1930 "cg_arith.tc"
			{
				ILGenSimple(info, IL_OP_NOT);
			}
#line 10243 "cg_arith.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10253 "cg_arith.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10263 "cg_arith.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10273 "cg_arith.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10283 "cg_arith.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10293 "cg_arith.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10303 "cg_arith.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10313 "cg_arith.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10323 "cg_arith.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10333 "cg_arith.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1945 "cg_arith.tc"
			{
				/* Default - should never be used */
			}
#line 10343 "cg_arith.c"
		}
		break;

		default: break;
	}
}

#line 3251 "cg_arith.tc"


ILMachineType ILCommonType(ILGenInfo *info, ILMachineType type1,
						   ILMachineType type2, int intonly)
{
	if(type1 == ILMachineType_Decimal || type2 == ILMachineType_Decimal)
	{
		if(intonly)
			return ILMachineType_Int32;
		else
			return ILMachineType_Decimal;
	}
	if(type1 == ILMachineType_NativeFloat || type2 == ILMachineType_NativeFloat)
	{
		if(intonly)
			return ILMachineType_Int32;
		else
			return ILMachineType_NativeFloat;
	}
	if(type1 == ILMachineType_Float64 || type2 == ILMachineType_Float64)
	{
		if(intonly)
			return ILMachineType_Int32;
		else if(info->pedanticArith || info->outputIsJava)
			return ILMachineType_Float64;
		else
			return ILMachineType_NativeFloat;
	}
	if(type1 == ILMachineType_Float32 || type2 == ILMachineType_Float32)
	{
		if(intonly)
			return ILMachineType_Int32;
		else if(info->pedanticArith || info->outputIsJava)
			return ILMachineType_Float32;
		else
			return ILMachineType_NativeFloat;
	}
	if(type1 == ILMachineType_UInt64 || type2 == ILMachineType_UInt64)
	{
		return ILMachineType_UInt64;
	}
	if(type1 == ILMachineType_Int64 || type2 == ILMachineType_Int64)
	{
		return ILMachineType_Int64;
	}
	if(type1 == ILMachineType_UnmanagedPtr ||
	   type2 == ILMachineType_UnmanagedPtr)
	{
		return ILMachineType_UnmanagedPtr;
	}
	if(type1 == ILMachineType_NativeUInt || type2 == ILMachineType_NativeUInt)
	{
		return ILMachineType_NativeUInt;
	}
	if(type1 == ILMachineType_NativeInt || type2 == ILMachineType_NativeInt)
	{
		return ILMachineType_NativeInt;
	}
	if(type1 == ILMachineType_UInt32 || type2 == ILMachineType_UInt32)
	{
		return ILMachineType_UInt32;
	}
	if(type1 == ILMachineType_Int32 || type2 == ILMachineType_Int32)
	{
		return ILMachineType_Int32;
	}
	if(type1 == ILMachineType_UInt16 || type2 == ILMachineType_UInt16)
	{
		return ILMachineType_UInt16;
	}
	if(type1 == ILMachineType_Char || type2 == ILMachineType_Char)
	{
		return ILMachineType_Char;
	}
	if(type1 == ILMachineType_Int16 || type2 == ILMachineType_Int16)
	{
		return ILMachineType_Int16;
	}
	if(type1 == ILMachineType_UInt8 || type2 == ILMachineType_UInt8)
	{
		return ILMachineType_UInt8;
	}
	if(type1 == ILMachineType_Int8 || type2 == ILMachineType_Int8)
	{
		return ILMachineType_Int8;
	}
	if(type1 == ILMachineType_Boolean || type2 == ILMachineType_Boolean)
	{
		/* Arithmetic operations on booleans give an "int32" result */
		return ILMachineType_Int32;
	}
	return ILMachineType_Void;
}

#line 10446 "cg_arith.c"
