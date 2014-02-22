/* cg_logical.c.  Generated automatically by treecc */
#line 3 "cg_logical.tc"

/*
 * cg_logical.tc - Logical operator nodes.
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
#line 26 "cg_logical.c"

ILMachineType ILNode_LogicalNot_ILNode_GetType__(ILNode_LogicalNot *node, ILGenInfo * info)
#line 35 "cg_logical.tc"
{
	return ILMachineType_Boolean;
}
#line 33 "cg_logical.c"

void ILNode_LogicalNot_ILNode_GenDiscard__(ILNode_LogicalNot *node, ILGenInfo * info)
#line 43 "cg_logical.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 40 "cg_logical.c"

ILMachineType ILNode_LogicalNot_ILNode_GenValue__(ILNode_LogicalNot *node, ILGenInfo * info)
#line 51 "cg_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILNode_GenThen(node->expr, info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenLabel(info, &label2);
	ILGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 56 "cg_logical.c"

void ILNode_LogicalNot_ILNode_GenThen__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label)
#line 68 "cg_logical.tc"
{
	ILNode_GenElse(node->expr, info, label);
}
#line 63 "cg_logical.c"

void ILNode_LogicalNot_ILNode_GenElse__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label)
#line 76 "cg_logical.tc"
{
	ILNode_GenThen(node->expr, info, label);
}
#line 70 "cg_logical.c"

int ILNode_LogicalNot_ILNode_EvalConst__(ILNode_LogicalNot *node, ILGenInfo * info, ILEvalValue * value)
#line 84 "cg_logical.tc"
{
	if(!ILNode_EvalConst(node->expr, info, value))
	{
		return 0;
	}
	if(!ILGenConstToBoolean(info, value))
	{
		return 0;
	}
	value->un.i4Value = !(value->un.i4Value);
	return 1;
}
#line 86 "cg_logical.c"

void ILNode_LogicalNot_JavaGenDiscard__(ILNode_LogicalNot *node, ILGenInfo * info)
#line 25 "jv_logical.tc"
{
	JavaGenDiscard(node->expr, info);
}
#line 93 "cg_logical.c"

ILMachineType ILNode_LogicalNot_JavaGenValue__(ILNode_LogicalNot *node, ILGenInfo * info)
#line 33 "jv_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenThen(node->expr, info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 109 "cg_logical.c"

void ILNode_LogicalNot_JavaGenThen__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label)
#line 50 "jv_logical.tc"
{
	JavaGenElse(node->expr, info, label);
}
#line 116 "cg_logical.c"

void ILNode_LogicalNot_JavaGenElse__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label)
#line 58 "jv_logical.tc"
{
	JavaGenThen(node->expr, info, label);
}
#line 123 "cg_logical.c"

struct ILNode_LogicalNot_vtable__ const ILNode_LogicalNot_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_LogicalNot_kind,
	"ILNode_LogicalNot",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalNot_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalNot_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalNot_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalNot_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalNot_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_LogicalNot_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalNot_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalNot_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalNot_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalNot_JavaGenElse__,
};

ILMachineType ILNode_LogicalAnd_ILNode_GetType__(ILNode_LogicalAnd *node, ILGenInfo * info)
#line 35 "cg_logical.tc"
{
	return ILMachineType_Boolean;
}
#line 147 "cg_logical.c"

void ILNode_LogicalAnd_ILNode_GenDiscard__(ILNode_LogicalAnd *node, ILGenInfo * info)
#line 101 "cg_logical.tc"
{
	ILLabel label = ILLabel_Undefined;
	ILNode_GenElse(node->expr1, info, &label);
	ILNode_GenDiscard(node->expr2, info);
	ILGenLabel(info, &label);
}
#line 157 "cg_logical.c"

ILMachineType ILNode_LogicalAnd_ILNode_GenValue__(ILNode_LogicalAnd *node, ILGenInfo * info)
#line 112 "cg_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILNode_GenElse(node->expr1, info, &label1);
	ILNode_GenElse(node->expr2, info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenLabel(info, &label2);
	ILGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 174 "cg_logical.c"

void ILNode_LogicalAnd_ILNode_GenThen__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label)
#line 130 "cg_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILNode_GenElse(node->expr1, info, &label1);
	ILNode_GenThen(node->expr2, info, label);
	ILGenLabel(info, &label1);
}
#line 184 "cg_logical.c"

void ILNode_LogicalAnd_ILNode_GenElse__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label)
#line 141 "cg_logical.tc"
{
	ILNode_GenElse(node->expr1, info, label);
	ILNode_GenElse(node->expr2, info, label);
}
#line 192 "cg_logical.c"

int ILNode_LogicalAnd_ILNode_EvalConst__(ILNode_LogicalAnd *node, ILGenInfo * info, ILEvalValue * value)
#line 150 "cg_logical.tc"
{
	ILInt32 tempValue;

	/* Evaluate the first sub-expression */
	if(!ILNode_EvalConst(node->expr1, info, value))
	{
		return 0;
	}
	if(!ILGenConstToBoolean(info, value))
	{
		return 0;
	}
	if(!(info->semAnalysis))
	{
		/* If the result is false, then we have the final value,
		   even if the second sub-expression is non-constant.
		   Note: if we are performing semantic analysis, then assume
		   that we are evaluating real constants, which we must
		   fully evaluate to be sure that they are constants.
		   When not performing semantic analysis, we can optimise more */
		if(!(value->un.i4Value))
		{
			return 1;
		}
	}
	tempValue = value->un.i4Value;

	/* Evaluate the second sub-expression and return its value */
	if(!ILNode_EvalConst(node->expr2, info, value))
	{
		return 0;
	}
	if(!ILGenConstToBoolean(info, value))
	{
		return 0;
	}
	value->un.i4Value = (tempValue && value->un.i4Value);
	return 1;
}
#line 235 "cg_logical.c"

void ILNode_LogicalAnd_JavaGenDiscard__(ILNode_LogicalAnd *node, ILGenInfo * info)
#line 66 "jv_logical.tc"
{
	ILLabel label = ILLabel_Undefined;
	JavaGenElse(node->expr1, info, &label);
	JavaGenDiscard(node->expr2, info);
	JavaGenLabel(info, &label);
}
#line 245 "cg_logical.c"

ILMachineType ILNode_LogicalAnd_JavaGenValue__(ILNode_LogicalAnd *node, ILGenInfo * info)
#line 77 "jv_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenElse(node->expr1, info, &label1);
	JavaGenElse(node->expr2, info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 262 "cg_logical.c"

void ILNode_LogicalAnd_JavaGenThen__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label)
#line 95 "jv_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	JavaGenElse(node->expr1, info, &label1);
	JavaGenThen(node->expr2, info, label);
	JavaGenLabel(info, &label1);
}
#line 272 "cg_logical.c"

void ILNode_LogicalAnd_JavaGenElse__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label)
#line 106 "jv_logical.tc"
{
	JavaGenElse(node->expr1, info, label);
	JavaGenElse(node->expr2, info, label);
}
#line 280 "cg_logical.c"

struct ILNode_LogicalAnd_vtable__ const ILNode_LogicalAnd_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_LogicalAnd_kind,
	"ILNode_LogicalAnd",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalAnd_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalAnd_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalAnd_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalAnd_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalAnd_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_LogicalAnd_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalAnd_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalAnd_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalAnd_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalAnd_JavaGenElse__,
};

ILMachineType ILNode_LogicalOr_ILNode_GetType__(ILNode_LogicalOr *node, ILGenInfo * info)
#line 35 "cg_logical.tc"
{
	return ILMachineType_Boolean;
}
#line 304 "cg_logical.c"

void ILNode_LogicalOr_ILNode_GenDiscard__(ILNode_LogicalOr *node, ILGenInfo * info)
#line 194 "cg_logical.tc"
{
	ILLabel label = ILLabel_Undefined;
	ILNode_GenThen(node->expr1, info, &label);
	ILNode_GenDiscard(node->expr2, info);
	ILGenLabel(info, &label);
}
#line 314 "cg_logical.c"

ILMachineType ILNode_LogicalOr_ILNode_GenValue__(ILNode_LogicalOr *node, ILGenInfo * info)
#line 205 "cg_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILNode_GenThen(node->expr1, info, &label1);
	ILNode_GenThen(node->expr2, info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
	ILGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 331 "cg_logical.c"

void ILNode_LogicalOr_ILNode_GenThen__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label)
#line 223 "cg_logical.tc"
{
	ILNode_GenThen(node->expr1, info, label);
	ILNode_GenThen(node->expr2, info, label);
}
#line 339 "cg_logical.c"

void ILNode_LogicalOr_ILNode_GenElse__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label)
#line 232 "cg_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILNode_GenThen(node->expr1, info, &label1);
	ILNode_GenElse(node->expr2, info, label);
	ILGenLabel(info, &label1);
}
#line 349 "cg_logical.c"

int ILNode_LogicalOr_ILNode_EvalConst__(ILNode_LogicalOr *node, ILGenInfo * info, ILEvalValue * value)
#line 243 "cg_logical.tc"
{
	ILInt32 tempValue;

	/* Evaluate the first sub-expression */
	if(!ILNode_EvalConst(node->expr1, info, value))
	{
		return 0;
	}
	if(!ILGenConstToBoolean(info, value))
	{
		return 0;
	}
	if(!(info->semAnalysis))
	{
		/* If the result is true, then we have the final value,
		   even if the second sub-expression is non-constant.
		   Note: if we are performing semantic analysis, then assume
		   that we are evaluating real constants, which we must
		   fully evaluate to be sure that they are constants.
		   When not performing semantic analysis, we can optimise more */
		if(value->un.i4Value)
		{
			return 1;
		}
	}
	tempValue = value->un.i4Value;

	/* Evaluate the second sub-expression and return its value */
	if(!ILNode_EvalConst(node->expr2, info, value))
	{
		return 0;
	}
	if(!ILGenConstToBoolean(info, value))
	{
		return 0;
	}
	value->un.i4Value = (tempValue || value->un.i4Value);
	return 1;
}
#line 392 "cg_logical.c"

void ILNode_LogicalOr_JavaGenDiscard__(ILNode_LogicalOr *node, ILGenInfo * info)
#line 115 "jv_logical.tc"
{
	ILLabel label = ILLabel_Undefined;
	JavaGenThen(node->expr1, info, &label);
	JavaGenDiscard(node->expr2, info);
	JavaGenLabel(info, &label);
}
#line 402 "cg_logical.c"

ILMachineType ILNode_LogicalOr_JavaGenValue__(ILNode_LogicalOr *node, ILGenInfo * info)
#line 126 "jv_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenThen(node->expr1, info, &label1);
	JavaGenThen(node->expr2, info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 419 "cg_logical.c"

void ILNode_LogicalOr_JavaGenThen__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label)
#line 144 "jv_logical.tc"
{
	JavaGenThen(node->expr1, info, label);
	JavaGenThen(node->expr2, info, label);
}
#line 427 "cg_logical.c"

void ILNode_LogicalOr_JavaGenElse__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label)
#line 153 "jv_logical.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	JavaGenThen(node->expr1, info, &label1);
	JavaGenElse(node->expr2, info, label);
	JavaGenLabel(info, &label1);
}
#line 437 "cg_logical.c"

struct ILNode_LogicalOr_vtable__ const ILNode_LogicalOr_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_LogicalOr_kind,
	"ILNode_LogicalOr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalOr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalOr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalOr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalOr_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalOr_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_LogicalOr_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalOr_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LogicalOr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalOr_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_LogicalOr_JavaGenElse__,
};

struct ILNode_UserLogical_vtable__ const ILNode_UserLogical_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_UserLogical_kind,
	"ILNode_UserLogical",
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

ILMachineType ILNode_UserLogicalAnd_ILNode_GetType__(ILNode_UserLogicalAnd *node, ILGenInfo * info)
#line 35 "cg_logical.tc"
{
	return ILMachineType_Boolean;
}
#line 478 "cg_logical.c"

ILMachineType ILNode_UserLogicalAnd_ILNode_GenValue__(ILNode_UserLogicalAnd *node, ILGenInfo * info)
#line 287 "cg_logical.tc"
{
	ILMachineType type;
	ILLabel label = ILLabel_Undefined;

	/* Evaluate the first sub-expression */
	type = ILNode_GenValue(node->expr1, info);

	/* Test the first sub-expression for false */
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);
	if(node->falseMethod)
	{
		ILGenCallByMethod(info, node->falseMethod);
		ILGenJump(info, IL_OP_BRTRUE, &label);
	}
	else
	{
		ILGenCallByMethod(info, node->trueMethod);
		ILGenJump(info, IL_OP_BRFALSE, &label);
	}
	ILGenAdjust(info, -1);

	/* Pop the first sub-expression and evaluate the second */
	ILGenSimple(info, IL_OP_POP);
	ILGenAdjust(info, -1);
	type = ILNode_GenValue(node->expr2, info);

	/* Output the jump label here */
	ILGenLabel(info, &label);

	/* Done */
	return type;
}
#line 515 "cg_logical.c"

ILMachineType ILNode_UserLogicalAnd_JavaGenValue__(ILNode_UserLogicalAnd *node, ILGenInfo * info)
#line 164 "jv_logical.tc"
{
	ILMachineType type;
	int size;
	ILLabel label = ILLabel_Undefined;

	/* Evaluate the first sub-expression */
	type = JavaGenValue(node->expr1, info);

	/* Test the first sub-expression for false */
	size = JavaGenTypeSize(type);
	if(size == 1)
	{
		JavaGenSimple(info, JAVA_OP_DUP);
	}
	else if(size == 2)
	{
		JavaGenSimple(info, JAVA_OP_DUP2);
	}
	JavaGenAdjust(info, size);
	if(node->falseMethod)
	{
		JavaGenCallByMethod(info, node->falseMethod);
		JavaGenJump(info, JAVA_OP_IFNE, &label);
	}
	else
	{
		JavaGenCallByMethod(info, node->trueMethod);
		JavaGenJump(info, JAVA_OP_IFEQ, &label);
	}
	JavaGenAdjust(info, -size);

	/* Pop the first sub-expression and evaluate the second */
	JavaGenCast(info, type, ILMachineType_Void);
	type = JavaGenValue(node->expr2, info);

	/* Output the jump label here */
	JavaGenLabel(info, &label);

	/* Done */
	return type;
}
#line 560 "cg_logical.c"

struct ILNode_UserLogicalAnd_vtable__ const ILNode_UserLogicalAnd_vt__ = {
	&ILNode_UserLogical_vt__,
	ILNode_UserLogicalAnd_kind,
	"ILNode_UserLogicalAnd",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserLogicalAnd_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserLogicalAnd_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserLogicalAnd_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_UserLogicalOr_ILNode_GetType__(ILNode_UserLogicalOr *node, ILGenInfo * info)
#line 35 "cg_logical.tc"
{
	return ILMachineType_Boolean;
}
#line 584 "cg_logical.c"

ILMachineType ILNode_UserLogicalOr_ILNode_GenValue__(ILNode_UserLogicalOr *node, ILGenInfo * info)
#line 325 "cg_logical.tc"
{
	ILMachineType type;
	ILLabel label = ILLabel_Undefined;

	/* Evaluate the first sub-expression */
	type = ILNode_GenValue(node->expr1, info);

	/* Test the first sub-expression for true */
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);
	if(node->trueMethod)
	{
		ILGenCallByMethod(info, node->trueMethod);
		ILGenJump(info, IL_OP_BRTRUE, &label);
	}
	else
	{
		ILGenCallByMethod(info, node->falseMethod);
		ILGenJump(info, IL_OP_BRFALSE, &label);
	}
	ILGenAdjust(info, -1);

	/* Pop the first sub-expression and evaluate the second */
	ILGenSimple(info, IL_OP_POP);
	ILGenAdjust(info, -1);
	type = ILNode_GenValue(node->expr2, info);

	/* Output the jump label here */
	ILGenLabel(info, &label);

	/* Done */
	return type;
}
#line 621 "cg_logical.c"

ILMachineType ILNode_UserLogicalOr_JavaGenValue__(ILNode_UserLogicalOr *node, ILGenInfo * info)
#line 210 "jv_logical.tc"
{
	ILMachineType type;
	int size;
	ILLabel label = ILLabel_Undefined;

	/* Evaluate the first sub-expression */
	type = JavaGenValue(node->expr1, info);

	/* Test the first sub-expression for true */
	size = JavaGenTypeSize(type);
	if(size == 1)
	{
		JavaGenSimple(info, JAVA_OP_DUP);
	}
	else if(size == 2)
	{
		JavaGenSimple(info, JAVA_OP_DUP2);
	}
	JavaGenAdjust(info, size);
	if(node->trueMethod)
	{
		JavaGenCallByMethod(info, node->trueMethod);
		JavaGenJump(info, JAVA_OP_IFNE, &label);
	}
	else
	{
		JavaGenCallByMethod(info, node->falseMethod);
		JavaGenJump(info, JAVA_OP_IFEQ, &label);
	}
	JavaGenAdjust(info, -size);

	/* Pop the first sub-expression and evaluate the second */
	JavaGenCast(info, type, ILMachineType_Void);
	type = JavaGenValue(node->expr2, info);

	/* Output the jump label here */
	JavaGenLabel(info, &label);

	/* Done */
	return type;
}
#line 666 "cg_logical.c"

struct ILNode_UserLogicalOr_vtable__ const ILNode_UserLogicalOr_vt__ = {
	&ILNode_UserLogical_vt__,
	ILNode_UserLogicalOr_kind,
	"ILNode_UserLogicalOr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserLogicalOr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserLogicalOr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UserLogicalOr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILNode *ILNode_LogicalNot_create(ILNode * expr)
{
	ILNode_LogicalNot *node__ = (ILNode_LogicalNot *)yynodealloc(sizeof(struct ILNode_LogicalNot__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LogicalNot_vt__;
	node__->kind__ = ILNode_LogicalNot_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_LogicalAnd_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_LogicalAnd *node__ = (ILNode_LogicalAnd *)yynodealloc(sizeof(struct ILNode_LogicalAnd__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LogicalAnd_vt__;
	node__->kind__ = ILNode_LogicalAnd_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_LogicalOr_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_LogicalOr *node__ = (ILNode_LogicalOr *)yynodealloc(sizeof(struct ILNode_LogicalOr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LogicalOr_vt__;
	node__->kind__ = ILNode_LogicalOr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_UserLogicalAnd_create(ILNode * expr1, ILNode * expr2, ILMethod * opMethod, ILMethod * trueMethod, ILMethod * falseMethod)
{
	ILNode_UserLogicalAnd *node__ = (ILNode_UserLogicalAnd *)yynodealloc(sizeof(struct ILNode_UserLogicalAnd__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserLogicalAnd_vt__;
	node__->kind__ = ILNode_UserLogicalAnd_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->opMethod = opMethod;
	node__->trueMethod = trueMethod;
	node__->falseMethod = falseMethod;
	return (ILNode *)node__;
}

ILNode *ILNode_UserLogicalOr_create(ILNode * expr1, ILNode * expr2, ILMethod * opMethod, ILMethod * trueMethod, ILMethod * falseMethod)
{
	ILNode_UserLogicalOr *node__ = (ILNode_UserLogicalOr *)yynodealloc(sizeof(struct ILNode_UserLogicalOr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserLogicalOr_vt__;
	node__->kind__ = ILNode_UserLogicalOr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->opMethod = opMethod;
	node__->trueMethod = trueMethod;
	node__->falseMethod = falseMethod;
	return (ILNode *)node__;
}

