/* cg_relop.c.  Generated automatically by treecc */
#line 3 "cg_relop.tc"

/*
 * cg_relop.tc - Relational operator nodes.
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
 * Determine a common type for relational operators.
 */
static ILMachineType Relational_CommonType(ILGenInfo *info,
										   ILMachineType type1,
										   ILMachineType type2)
{
	if(type1 == ILMachineType_ObjectRef || type2 == ILMachineType_ObjectRef ||
	   type1 == ILMachineType_String || type2 == ILMachineType_String)
	{
		return ILMachineType_ObjectRef;
	}
	else
	{
		return ILCommonType(info, type1, type2, 0);
	}
}

#line 45 "cg_relop.c"

ILMachineType ILNode_Relational_ILNode_GetType__(ILNode_Relational *node, ILGenInfo * info)
#line 87 "cg_relop.tc"
{
	return ILMachineType_Boolean;
}
#line 52 "cg_relop.c"

void ILNode_Relational_ILNode_GenDiscard__(ILNode_Relational *node, ILGenInfo * info)
#line 95 "cg_relop.tc"
{
	ILNode_GenDiscard(node->expr1, info);
	ILNode_GenDiscard(node->expr2, info);
}
#line 60 "cg_relop.c"

ILMachineType ILNode_Relational_ILNode_GenValue__(ILNode_Relational *node, ILGenInfo * info)
#line 104 "cg_relop.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Determine the common type to use */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	commonType = Relational_CommonType(info, type1, type2);

	/* Generate code for the sub-expressions */
	ILGenCast(info, ILNode_GenValue(node->expr1, info), commonType);
	ILGenCast(info, ILNode_GenValue(node->expr2, info), commonType);

	/* Compare the values */
	ILRelational_ApplyOp(info, node, commonType);
	ILGenAdjust(info, -1);

	/* The result type is always boolean */
	return ILMachineType_Boolean;
}
#line 85 "cg_relop.c"

void ILNode_Relational_ILNode_GenThen__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label)
#line 130 "cg_relop.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Determine the common type to use */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	commonType = Relational_CommonType(info, type1, type2);

	/* Generate code for the sub-expressions */
	ILGenCast(info, ILNode_GenValue(node->expr1, info), commonType);
	ILGenCast(info, ILNode_GenValue(node->expr2, info), commonType);

	/* Compare the values and jump */
	ILRelational_ThenOp(info, node, commonType, label);
	ILGenAdjust(info, -2);
}
#line 107 "cg_relop.c"

void ILNode_Relational_ILNode_GenElse__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label)
#line 153 "cg_relop.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Determine the common type to use */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	commonType = Relational_CommonType(info, type1, type2);

	/* Generate code for the sub-expressions */
	ILGenCast(info, ILNode_GenValue(node->expr1, info), commonType);
	ILGenCast(info, ILNode_GenValue(node->expr2, info), commonType);

	/* Compare the values and jump */
	ILRelational_ElseOp(info, node, commonType, label);
	ILGenAdjust(info, -2);
}
#line 129 "cg_relop.c"

int ILNode_Relational_ILNode_EvalConst__(ILNode_Relational *node, ILGenInfo * info, ILEvalValue * value)
#line 176 "cg_relop.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;
	ILEvalValue value2;

	/* Determine the common type to use */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	commonType = Relational_CommonType(info, type1, type2);

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

	/* Compare the values */
	if(!ILRelational_EvalOp(info, node, commonType, value, &value2))
	{
		return 0;
	}

	/* The result type is always boolean */
	value->valueType = ILMachineType_Boolean;
	return 1;
}
#line 166 "cg_relop.c"

void ILNode_Relational_JavaGenDiscard__(ILNode_Relational *node, ILGenInfo * info)
#line 55 "jv_relop.tc"
{
	JavaGenDiscard(node->expr1, info);
	JavaGenDiscard(node->expr2, info);
}
#line 174 "cg_relop.c"

ILMachineType ILNode_Relational_JavaGenValue__(ILNode_Relational *node, ILGenInfo * info)
#line 64 "jv_relop.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Determine the common type to use */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	commonType = Relational_CommonType(info, type1, type2);

	/* Generate code for the sub-expressions */
	JavaGenCast(info, JavaGenValue(node->expr1, info), commonType);
	JavaGenCast(info, JavaGenValue(node->expr2, info), commonType);

	/* Compare the values */
	JavaRelational_ApplyOp(info, node, commonType);

	/* The result type is always boolean */
	return ILMachineType_Boolean;
}
#line 198 "cg_relop.c"

void ILNode_Relational_JavaGenThen__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label)
#line 89 "jv_relop.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Determine the common type to use */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	commonType = Relational_CommonType(info, type1, type2);

	/* Generate code for the sub-expressions */
	JavaGenCast(info, JavaGenValue(node->expr1, info), commonType);
	JavaGenCast(info, JavaGenValue(node->expr2, info), commonType);

	/* Compare the values and jump */
	JavaRelational_ThenOp(info, node, commonType, label);
}
#line 219 "cg_relop.c"

void ILNode_Relational_JavaGenElse__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label)
#line 111 "jv_relop.tc"
{
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType commonType;

	/* Determine the common type to use */
	type1 = ILNode_GetType(node->expr1, info);
	type2 = ILNode_GetType(node->expr2, info);
	commonType = Relational_CommonType(info, type1, type2);

	/* Generate code for the sub-expressions */
	JavaGenCast(info, JavaGenValue(node->expr1, info), commonType);
	JavaGenCast(info, JavaGenValue(node->expr2, info), commonType);

	/* Compare the values and jump */
	JavaRelational_ElseOp(info, node, commonType, label);
}
#line 240 "cg_relop.c"

struct ILNode_Relational_vtable__ const ILNode_Relational_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_Relational_kind,
	"ILNode_Relational",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Relational_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenElse__,
};

struct ILNode_Eq_vtable__ const ILNode_Eq_vt__ = {
	&ILNode_Relational_vt__,
	ILNode_Eq_kind,
	"ILNode_Eq",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Relational_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenElse__,
};

struct ILNode_Ne_vtable__ const ILNode_Ne_vt__ = {
	&ILNode_Relational_vt__,
	ILNode_Ne_kind,
	"ILNode_Ne",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Relational_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenElse__,
};

struct ILNode_Lt_vtable__ const ILNode_Lt_vt__ = {
	&ILNode_Relational_vt__,
	ILNode_Lt_kind,
	"ILNode_Lt",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Relational_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenElse__,
};

struct ILNode_Le_vtable__ const ILNode_Le_vt__ = {
	&ILNode_Relational_vt__,
	ILNode_Le_kind,
	"ILNode_Le",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Relational_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenElse__,
};

struct ILNode_Gt_vtable__ const ILNode_Gt_vt__ = {
	&ILNode_Relational_vt__,
	ILNode_Gt_kind,
	"ILNode_Gt",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Relational_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenElse__,
};

struct ILNode_Ge_vtable__ const ILNode_Ge_vt__ = {
	&ILNode_Relational_vt__,
	ILNode_Ge_kind,
	"ILNode_Ge",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Relational_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Relational_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Relational_JavaGenElse__,
};

ILNode *ILNode_Eq_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Eq *node__ = (ILNode_Eq *)yynodealloc(sizeof(struct ILNode_Eq__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Eq_vt__;
	node__->kind__ = ILNode_Eq_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Ne_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Ne *node__ = (ILNode_Ne *)yynodealloc(sizeof(struct ILNode_Ne__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Ne_vt__;
	node__->kind__ = ILNode_Ne_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Lt_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Lt *node__ = (ILNode_Lt *)yynodealloc(sizeof(struct ILNode_Lt__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Lt_vt__;
	node__->kind__ = ILNode_Lt_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Le_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Le *node__ = (ILNode_Le *)yynodealloc(sizeof(struct ILNode_Le__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Le_vt__;
	node__->kind__ = ILNode_Le_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Gt_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Gt *node__ = (ILNode_Gt *)yynodealloc(sizeof(struct ILNode_Gt__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Gt_vt__;
	node__->kind__ = ILNode_Gt_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Ge_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_Ge *node__ = (ILNode_Ge *)yynodealloc(sizeof(struct ILNode_Ge__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Ge_vt__;
	node__->kind__ = ILNode_Ge_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

static int ILRelational_EvalOp_1__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 445 "cg_relop.c"

static int ILRelational_EvalOp_2__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 453 "cg_relop.c"

static int ILRelational_EvalOp_3__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 461 "cg_relop.c"

static int ILRelational_EvalOp_4__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 469 "cg_relop.c"

static int ILRelational_EvalOp_5__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 477 "cg_relop.c"

static int ILRelational_EvalOp_6__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 485 "cg_relop.c"

static int ILRelational_EvalOp_7__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 493 "cg_relop.c"

static int ILRelational_EvalOp_8__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 501 "cg_relop.c"

static int ILRelational_EvalOp_9__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1121 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value == value2->un.i8Value);
	return 1;
}
#line 509 "cg_relop.c"

static int ILRelational_EvalOp_10__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1121 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value == value2->un.i8Value);
	return 1;
}
#line 517 "cg_relop.c"

static int ILRelational_EvalOp_11__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 525 "cg_relop.c"

static int ILRelational_EvalOp_12__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1115 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value == value2->un.i4Value);
	return 1;
}
#line 533 "cg_relop.c"

static int ILRelational_EvalOp_13__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1126 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r4Value == value2->un.r4Value);
	return 1;
}
#line 541 "cg_relop.c"

static int ILRelational_EvalOp_14__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1132 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value == value2->un.r8Value);
	return 1;
}
#line 549 "cg_relop.c"

static int ILRelational_EvalOp_15__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1132 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value == value2->un.r8Value);
	return 1;
}
#line 557 "cg_relop.c"

static int ILRelational_EvalOp_16__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1137 "cg_relop.tc"
{
	value1->un.i4Value = (ILDecimalCmp(&(value1->un.decValue),
									   &(value2->un.decValue)) == 0);
	return 1;
}
#line 566 "cg_relop.c"

static int ILRelational_EvalOp_17__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1143 "cg_relop.tc"
{
	/* Compare two object ref constants, which will
	   always be "null", and hence equal */
	value1->un.i4Value = 1;
	return 1;
}
#line 576 "cg_relop.c"

static int ILRelational_EvalOp_18__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1150 "cg_relop.tc"
{
	return 0;
}
#line 583 "cg_relop.c"

static int ILRelational_EvalOp_19__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 591 "cg_relop.c"

static int ILRelational_EvalOp_20__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 599 "cg_relop.c"

static int ILRelational_EvalOp_21__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 607 "cg_relop.c"

static int ILRelational_EvalOp_22__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 615 "cg_relop.c"

static int ILRelational_EvalOp_23__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 623 "cg_relop.c"

static int ILRelational_EvalOp_24__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 631 "cg_relop.c"

static int ILRelational_EvalOp_25__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 639 "cg_relop.c"

static int ILRelational_EvalOp_26__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 647 "cg_relop.c"

static int ILRelational_EvalOp_27__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1173 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value != value2->un.i8Value);
	return 1;
}
#line 655 "cg_relop.c"

static int ILRelational_EvalOp_28__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1173 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value != value2->un.i8Value);
	return 1;
}
#line 663 "cg_relop.c"

static int ILRelational_EvalOp_29__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 671 "cg_relop.c"

static int ILRelational_EvalOp_30__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1167 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value != value2->un.i4Value);
	return 1;
}
#line 679 "cg_relop.c"

static int ILRelational_EvalOp_31__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1178 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r4Value != value2->un.r4Value);
	return 1;
}
#line 687 "cg_relop.c"

static int ILRelational_EvalOp_32__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1184 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value != value2->un.r8Value);
	return 1;
}
#line 695 "cg_relop.c"

static int ILRelational_EvalOp_33__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1184 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value != value2->un.r8Value);
	return 1;
}
#line 703 "cg_relop.c"

static int ILRelational_EvalOp_34__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1189 "cg_relop.tc"
{
	value1->un.i4Value = (ILDecimalCmp(&(value1->un.decValue),
									   &(value2->un.decValue)) != 0);
	return 1;
}
#line 712 "cg_relop.c"

static int ILRelational_EvalOp_35__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1195 "cg_relop.tc"
{
	/* Compare two object ref constants, which will
	   always be "null", and hence equal */
	value1->un.i4Value = 0;
	return 1;
}
#line 722 "cg_relop.c"

static int ILRelational_EvalOp_36__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1202 "cg_relop.tc"
{
	return 0;
}
#line 729 "cg_relop.c"

static int ILRelational_EvalOp_37__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1214 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value < value2->un.i4Value);
	return 1;
}
#line 737 "cg_relop.c"

static int ILRelational_EvalOp_38__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1214 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value < value2->un.i4Value);
	return 1;
}
#line 745 "cg_relop.c"

static int ILRelational_EvalOp_39__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1223 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 755 "cg_relop.c"

static int ILRelational_EvalOp_40__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1214 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value < value2->un.i4Value);
	return 1;
}
#line 763 "cg_relop.c"

static int ILRelational_EvalOp_41__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1223 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 773 "cg_relop.c"

static int ILRelational_EvalOp_42__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1223 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 783 "cg_relop.c"

static int ILRelational_EvalOp_43__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1214 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value < value2->un.i4Value);
	return 1;
}
#line 791 "cg_relop.c"

static int ILRelational_EvalOp_44__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1223 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 801 "cg_relop.c"

static int ILRelational_EvalOp_45__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1230 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value < value2->un.i8Value);
	return 1;
}
#line 809 "cg_relop.c"

static int ILRelational_EvalOp_46__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1235 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt64)(value1->un.i8Value)) <
		 ((ILUInt64)(value2->un.i8Value)));
	return 1;
}
#line 819 "cg_relop.c"

static int ILRelational_EvalOp_47__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1214 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value < value2->un.i4Value);
	return 1;
}
#line 827 "cg_relop.c"

static int ILRelational_EvalOp_48__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1223 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 837 "cg_relop.c"

static int ILRelational_EvalOp_49__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1242 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r4Value < value2->un.r4Value);
	return 1;
}
#line 845 "cg_relop.c"

static int ILRelational_EvalOp_50__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1248 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value < value2->un.r8Value);
	return 1;
}
#line 853 "cg_relop.c"

static int ILRelational_EvalOp_51__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1248 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value < value2->un.r8Value);
	return 1;
}
#line 861 "cg_relop.c"

static int ILRelational_EvalOp_52__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1253 "cg_relop.tc"
{
	value1->un.i4Value = (ILDecimalCmp(&(value1->un.decValue),
									   &(value2->un.decValue)) < 0);
	return 1;
}
#line 870 "cg_relop.c"

static int ILRelational_EvalOp_53__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1259 "cg_relop.tc"
{
	/* Compare two object ref constants, which will
	   always be "null", and hence equal */
	value1->un.i4Value = 0;
	return 1;
}
#line 880 "cg_relop.c"

static int ILRelational_EvalOp_54__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1266 "cg_relop.tc"
{
	return 0;
}
#line 887 "cg_relop.c"

static int ILRelational_EvalOp_55__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1278 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value <= value2->un.i4Value);
	return 1;
}
#line 895 "cg_relop.c"

static int ILRelational_EvalOp_56__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1278 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value <= value2->un.i4Value);
	return 1;
}
#line 903 "cg_relop.c"

static int ILRelational_EvalOp_57__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1287 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 913 "cg_relop.c"

static int ILRelational_EvalOp_58__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1278 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value <= value2->un.i4Value);
	return 1;
}
#line 921 "cg_relop.c"

static int ILRelational_EvalOp_59__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1287 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 931 "cg_relop.c"

static int ILRelational_EvalOp_60__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1287 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 941 "cg_relop.c"

static int ILRelational_EvalOp_61__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1278 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value <= value2->un.i4Value);
	return 1;
}
#line 949 "cg_relop.c"

static int ILRelational_EvalOp_62__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1287 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 959 "cg_relop.c"

static int ILRelational_EvalOp_63__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1294 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value <= value2->un.i8Value);
	return 1;
}
#line 967 "cg_relop.c"

static int ILRelational_EvalOp_64__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1299 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt64)(value1->un.i8Value)) <=
		 ((ILUInt64)(value2->un.i8Value)));
	return 1;
}
#line 977 "cg_relop.c"

static int ILRelational_EvalOp_65__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1278 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value <= value2->un.i4Value);
	return 1;
}
#line 985 "cg_relop.c"

static int ILRelational_EvalOp_66__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1287 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) <=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 995 "cg_relop.c"

static int ILRelational_EvalOp_67__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1306 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r4Value <= value2->un.r4Value);
	return 1;
}
#line 1003 "cg_relop.c"

static int ILRelational_EvalOp_68__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1312 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value <= value2->un.r8Value);
	return 1;
}
#line 1011 "cg_relop.c"

static int ILRelational_EvalOp_69__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1312 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value <= value2->un.r8Value);
	return 1;
}
#line 1019 "cg_relop.c"

static int ILRelational_EvalOp_70__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1317 "cg_relop.tc"
{
	value1->un.i4Value = (ILDecimalCmp(&(value1->un.decValue),
									   &(value2->un.decValue)) <= 0);
	return 1;
}
#line 1028 "cg_relop.c"

static int ILRelational_EvalOp_71__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1323 "cg_relop.tc"
{
	/* Compare two object ref constants, which will
	   always be "null", and hence equal */
	value1->un.i4Value = 1;
	return 1;
}
#line 1038 "cg_relop.c"

static int ILRelational_EvalOp_72__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1330 "cg_relop.tc"
{
	return 0;
}
#line 1045 "cg_relop.c"

static int ILRelational_EvalOp_73__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1342 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value > value2->un.i4Value);
	return 1;
}
#line 1053 "cg_relop.c"

static int ILRelational_EvalOp_74__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1342 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value > value2->un.i4Value);
	return 1;
}
#line 1061 "cg_relop.c"

static int ILRelational_EvalOp_75__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1351 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1071 "cg_relop.c"

static int ILRelational_EvalOp_76__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1342 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value > value2->un.i4Value);
	return 1;
}
#line 1079 "cg_relop.c"

static int ILRelational_EvalOp_77__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1351 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1089 "cg_relop.c"

static int ILRelational_EvalOp_78__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1351 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1099 "cg_relop.c"

static int ILRelational_EvalOp_79__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1342 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value > value2->un.i4Value);
	return 1;
}
#line 1107 "cg_relop.c"

static int ILRelational_EvalOp_80__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1351 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1117 "cg_relop.c"

static int ILRelational_EvalOp_81__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1358 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value > value2->un.i8Value);
	return 1;
}
#line 1125 "cg_relop.c"

static int ILRelational_EvalOp_82__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1363 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt64)(value1->un.i8Value)) >
		 ((ILUInt64)(value2->un.i8Value)));
	return 1;
}
#line 1135 "cg_relop.c"

static int ILRelational_EvalOp_83__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1342 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value > value2->un.i4Value);
	return 1;
}
#line 1143 "cg_relop.c"

static int ILRelational_EvalOp_84__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1351 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1153 "cg_relop.c"

static int ILRelational_EvalOp_85__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1370 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r4Value > value2->un.r4Value);
	return 1;
}
#line 1161 "cg_relop.c"

static int ILRelational_EvalOp_86__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1376 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value > value2->un.r8Value);
	return 1;
}
#line 1169 "cg_relop.c"

static int ILRelational_EvalOp_87__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1376 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value > value2->un.r8Value);
	return 1;
}
#line 1177 "cg_relop.c"

static int ILRelational_EvalOp_88__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1381 "cg_relop.tc"
{
	value1->un.i4Value = (ILDecimalCmp(&(value1->un.decValue),
									   &(value2->un.decValue)) > 0);
	return 1;
}
#line 1186 "cg_relop.c"

static int ILRelational_EvalOp_89__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1387 "cg_relop.tc"
{
	/* Compare two object ref constants, which will
	   always be "null", and hence equal */
	value1->un.i4Value = 0;
	return 1;
}
#line 1196 "cg_relop.c"

static int ILRelational_EvalOp_90__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1394 "cg_relop.tc"
{
	return 0;
}
#line 1203 "cg_relop.c"

static int ILRelational_EvalOp_91__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1406 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value >= value2->un.i4Value);
	return 1;
}
#line 1211 "cg_relop.c"

static int ILRelational_EvalOp_92__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1406 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value >= value2->un.i4Value);
	return 1;
}
#line 1219 "cg_relop.c"

static int ILRelational_EvalOp_93__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1415 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1229 "cg_relop.c"

static int ILRelational_EvalOp_94__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1406 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value >= value2->un.i4Value);
	return 1;
}
#line 1237 "cg_relop.c"

static int ILRelational_EvalOp_95__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1415 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1247 "cg_relop.c"

static int ILRelational_EvalOp_96__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1415 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1257 "cg_relop.c"

static int ILRelational_EvalOp_97__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1406 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value >= value2->un.i4Value);
	return 1;
}
#line 1265 "cg_relop.c"

static int ILRelational_EvalOp_98__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1415 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1275 "cg_relop.c"

static int ILRelational_EvalOp_99__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1422 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i8Value >= value2->un.i8Value);
	return 1;
}
#line 1283 "cg_relop.c"

static int ILRelational_EvalOp_100__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1427 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt64)(value1->un.i8Value)) >=
		 ((ILUInt64)(value2->un.i8Value)));
	return 1;
}
#line 1293 "cg_relop.c"

static int ILRelational_EvalOp_101__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1406 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.i4Value >= value2->un.i4Value);
	return 1;
}
#line 1301 "cg_relop.c"

static int ILRelational_EvalOp_102__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1415 "cg_relop.tc"
{
	value1->un.i4Value =
		(((ILUInt32)(value1->un.i4Value)) >=
		 ((ILUInt32)(value2->un.i4Value)));
	return 1;
}
#line 1311 "cg_relop.c"

static int ILRelational_EvalOp_103__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1434 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r4Value >= value2->un.r4Value);
	return 1;
}
#line 1319 "cg_relop.c"

static int ILRelational_EvalOp_104__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1440 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value >= value2->un.r8Value);
	return 1;
}
#line 1327 "cg_relop.c"

static int ILRelational_EvalOp_105__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1440 "cg_relop.tc"
{
	value1->un.i4Value = (value1->un.r8Value >= value2->un.r8Value);
	return 1;
}
#line 1335 "cg_relop.c"

static int ILRelational_EvalOp_106__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1445 "cg_relop.tc"
{
	value1->un.i4Value = (ILDecimalCmp(&(value1->un.decValue),
									   &(value2->un.decValue)) >= 0);
	return 1;
}
#line 1344 "cg_relop.c"

static int ILRelational_EvalOp_107__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1451 "cg_relop.tc"
{
	/* Compare two object ref constants, which will
	   always be "null", and hence equal */
	value1->un.i4Value = 1;
	return 1;
}
#line 1354 "cg_relop.c"

static int ILRelational_EvalOp_108__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
#line 1458 "cg_relop.tc"
{
	return 0;
}
#line 1361 "cg_relop.c"

int ILRelational_EvalOp(ILGenInfo * info, ILNode_Relational * node__, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2)
{
	switch(node__->kind__)
	{
		case ILNode_Eq_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILRelational_EvalOp_18__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILRelational_EvalOp_1__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILRelational_EvalOp_2__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILRelational_EvalOp_3__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILRelational_EvalOp_4__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILRelational_EvalOp_5__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILRelational_EvalOp_6__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILRelational_EvalOp_7__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILRelational_EvalOp_8__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILRelational_EvalOp_9__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILRelational_EvalOp_10__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILRelational_EvalOp_11__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILRelational_EvalOp_12__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILRelational_EvalOp_13__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILRelational_EvalOp_14__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILRelational_EvalOp_15__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILRelational_EvalOp_16__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILRelational_EvalOp_18__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILRelational_EvalOp_17__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILRelational_EvalOp_18__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILRelational_EvalOp_18__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILRelational_EvalOp_18__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILRelational_EvalOp_18__(info, (ILNode_Eq *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ne_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILRelational_EvalOp_36__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILRelational_EvalOp_19__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILRelational_EvalOp_20__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILRelational_EvalOp_21__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILRelational_EvalOp_22__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILRelational_EvalOp_23__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILRelational_EvalOp_24__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILRelational_EvalOp_25__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILRelational_EvalOp_26__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILRelational_EvalOp_27__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILRelational_EvalOp_28__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILRelational_EvalOp_29__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILRelational_EvalOp_30__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILRelational_EvalOp_31__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILRelational_EvalOp_32__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILRelational_EvalOp_33__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILRelational_EvalOp_34__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILRelational_EvalOp_36__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILRelational_EvalOp_35__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILRelational_EvalOp_36__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILRelational_EvalOp_36__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILRelational_EvalOp_36__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILRelational_EvalOp_36__(info, (ILNode_Ne *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Lt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILRelational_EvalOp_54__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILRelational_EvalOp_37__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILRelational_EvalOp_38__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILRelational_EvalOp_39__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILRelational_EvalOp_40__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILRelational_EvalOp_41__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILRelational_EvalOp_42__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILRelational_EvalOp_43__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILRelational_EvalOp_44__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILRelational_EvalOp_45__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILRelational_EvalOp_46__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILRelational_EvalOp_47__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILRelational_EvalOp_48__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILRelational_EvalOp_49__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILRelational_EvalOp_50__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILRelational_EvalOp_51__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILRelational_EvalOp_52__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILRelational_EvalOp_54__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILRelational_EvalOp_53__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILRelational_EvalOp_54__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILRelational_EvalOp_54__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILRelational_EvalOp_54__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILRelational_EvalOp_54__(info, (ILNode_Lt *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Le_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILRelational_EvalOp_72__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILRelational_EvalOp_55__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILRelational_EvalOp_56__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILRelational_EvalOp_57__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILRelational_EvalOp_58__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILRelational_EvalOp_59__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILRelational_EvalOp_60__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILRelational_EvalOp_61__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILRelational_EvalOp_62__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILRelational_EvalOp_63__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILRelational_EvalOp_64__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILRelational_EvalOp_65__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILRelational_EvalOp_66__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILRelational_EvalOp_67__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILRelational_EvalOp_68__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILRelational_EvalOp_69__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILRelational_EvalOp_70__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILRelational_EvalOp_72__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILRelational_EvalOp_71__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILRelational_EvalOp_72__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILRelational_EvalOp_72__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILRelational_EvalOp_72__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILRelational_EvalOp_72__(info, (ILNode_Le *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Gt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILRelational_EvalOp_90__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILRelational_EvalOp_73__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILRelational_EvalOp_74__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILRelational_EvalOp_75__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILRelational_EvalOp_76__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILRelational_EvalOp_77__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILRelational_EvalOp_78__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILRelational_EvalOp_79__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILRelational_EvalOp_80__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILRelational_EvalOp_81__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILRelational_EvalOp_82__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILRelational_EvalOp_83__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILRelational_EvalOp_84__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILRelational_EvalOp_85__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILRelational_EvalOp_86__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILRelational_EvalOp_87__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILRelational_EvalOp_88__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILRelational_EvalOp_90__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILRelational_EvalOp_89__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILRelational_EvalOp_90__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILRelational_EvalOp_90__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILRelational_EvalOp_90__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILRelational_EvalOp_90__(info, (ILNode_Gt *)node__, commonType, value1, value2);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ge_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					return ILRelational_EvalOp_108__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Boolean:
				{
					return ILRelational_EvalOp_91__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int8:
				{
					return ILRelational_EvalOp_92__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt8:
				{
					return ILRelational_EvalOp_93__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int16:
				{
					return ILRelational_EvalOp_94__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt16:
				{
					return ILRelational_EvalOp_95__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Char:
				{
					return ILRelational_EvalOp_96__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int32:
				{
					return ILRelational_EvalOp_97__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt32:
				{
					return ILRelational_EvalOp_98__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Int64:
				{
					return ILRelational_EvalOp_99__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UInt64:
				{
					return ILRelational_EvalOp_100__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeInt:
				{
					return ILRelational_EvalOp_101__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					return ILRelational_EvalOp_102__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float32:
				{
					return ILRelational_EvalOp_103__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Float64:
				{
					return ILRelational_EvalOp_104__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					return ILRelational_EvalOp_105__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_Decimal:
				{
					return ILRelational_EvalOp_106__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_String:
				{
					return ILRelational_EvalOp_108__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					return ILRelational_EvalOp_107__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					return ILRelational_EvalOp_108__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					return ILRelational_EvalOp_108__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					return ILRelational_EvalOp_108__(info, (ILNode_Ge *)node__, commonType, value1, value2);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					return ILRelational_EvalOp_108__(info, (ILNode_Ge *)node__, commonType, value1, value2);
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

static void ILRelational_ElseOp_1__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 816 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 2259 "cg_relop.c"

static void ILRelational_ElseOp_2__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2266 "cg_relop.c"

static void ILRelational_ElseOp_3__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2273 "cg_relop.c"

static void ILRelational_ElseOp_4__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2280 "cg_relop.c"

static void ILRelational_ElseOp_5__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2287 "cg_relop.c"

static void ILRelational_ElseOp_6__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2294 "cg_relop.c"

static void ILRelational_ElseOp_7__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2301 "cg_relop.c"

static void ILRelational_ElseOp_8__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2308 "cg_relop.c"

static void ILRelational_ElseOp_9__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2315 "cg_relop.c"

static void ILRelational_ElseOp_10__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2322 "cg_relop.c"

static void ILRelational_ElseOp_11__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2329 "cg_relop.c"

static void ILRelational_ElseOp_12__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2336 "cg_relop.c"

static void ILRelational_ElseOp_13__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2343 "cg_relop.c"

static void ILRelational_ElseOp_14__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2350 "cg_relop.c"

static void ILRelational_ElseOp_15__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2357 "cg_relop.c"

static void ILRelational_ElseOp_16__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2364 "cg_relop.c"

static void ILRelational_ElseOp_17__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 843 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_Equality"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 2375 "cg_relop.c"

static void ILRelational_ElseOp_18__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 851 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.String::op_Equality"
			"(class [.library]System.String, class [.library]System.String)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 2385 "cg_relop.c"

static void ILRelational_ElseOp_19__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2392 "cg_relop.c"

static void ILRelational_ElseOp_20__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2399 "cg_relop.c"

static void ILRelational_ElseOp_21__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2406 "cg_relop.c"

static void ILRelational_ElseOp_22__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2413 "cg_relop.c"

static void ILRelational_ElseOp_23__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 839 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 2420 "cg_relop.c"

static void ILRelational_ElseOp_24__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 862 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 2427 "cg_relop.c"

static void ILRelational_ElseOp_25__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2434 "cg_relop.c"

static void ILRelational_ElseOp_26__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2441 "cg_relop.c"

static void ILRelational_ElseOp_27__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2448 "cg_relop.c"

static void ILRelational_ElseOp_28__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2455 "cg_relop.c"

static void ILRelational_ElseOp_29__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2462 "cg_relop.c"

static void ILRelational_ElseOp_30__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2469 "cg_relop.c"

static void ILRelational_ElseOp_31__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2476 "cg_relop.c"

static void ILRelational_ElseOp_32__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2483 "cg_relop.c"

static void ILRelational_ElseOp_33__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2490 "cg_relop.c"

static void ILRelational_ElseOp_34__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2497 "cg_relop.c"

static void ILRelational_ElseOp_35__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2504 "cg_relop.c"

static void ILRelational_ElseOp_36__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2511 "cg_relop.c"

static void ILRelational_ElseOp_37__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2518 "cg_relop.c"

static void ILRelational_ElseOp_38__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2525 "cg_relop.c"

static void ILRelational_ElseOp_39__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2532 "cg_relop.c"

static void ILRelational_ElseOp_40__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 889 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_Inequality"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 2543 "cg_relop.c"

static void ILRelational_ElseOp_41__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 897 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.String::op_Inequality"
			"(class [.library]System.String, class [.library]System.String)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 2553 "cg_relop.c"

static void ILRelational_ElseOp_42__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2560 "cg_relop.c"

static void ILRelational_ElseOp_43__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2567 "cg_relop.c"

static void ILRelational_ElseOp_44__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2574 "cg_relop.c"

static void ILRelational_ElseOp_45__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2581 "cg_relop.c"

static void ILRelational_ElseOp_46__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 885 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 2588 "cg_relop.c"

static void ILRelational_ElseOp_47__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 908 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 2595 "cg_relop.c"

static void ILRelational_ElseOp_48__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2602 "cg_relop.c"

static void ILRelational_ElseOp_49__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2609 "cg_relop.c"

static void ILRelational_ElseOp_50__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 941 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 2616 "cg_relop.c"

static void ILRelational_ElseOp_51__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2623 "cg_relop.c"

static void ILRelational_ElseOp_52__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 941 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 2630 "cg_relop.c"

static void ILRelational_ElseOp_53__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 941 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 2637 "cg_relop.c"

static void ILRelational_ElseOp_54__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2644 "cg_relop.c"

static void ILRelational_ElseOp_55__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 941 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 2651 "cg_relop.c"

static void ILRelational_ElseOp_56__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2658 "cg_relop.c"

static void ILRelational_ElseOp_57__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 941 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 2665 "cg_relop.c"

static void ILRelational_ElseOp_58__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2672 "cg_relop.c"

static void ILRelational_ElseOp_59__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 941 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 2679 "cg_relop.c"

static void ILRelational_ElseOp_60__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 929 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 2689 "cg_relop.c"

static void ILRelational_ElseOp_61__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 929 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 2699 "cg_relop.c"

static void ILRelational_ElseOp_62__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 929 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 2709 "cg_relop.c"

static void ILRelational_ElseOp_63__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 945 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_LessThan"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 2720 "cg_relop.c"

static void ILRelational_ElseOp_64__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2727 "cg_relop.c"

static void ILRelational_ElseOp_65__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2734 "cg_relop.c"

static void ILRelational_ElseOp_66__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2741 "cg_relop.c"

static void ILRelational_ElseOp_67__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2748 "cg_relop.c"

static void ILRelational_ElseOp_68__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2755 "cg_relop.c"

static void ILRelational_ElseOp_69__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 923 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 2762 "cg_relop.c"

static void ILRelational_ElseOp_70__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 957 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 2769 "cg_relop.c"

static void ILRelational_ElseOp_71__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2776 "cg_relop.c"

static void ILRelational_ElseOp_72__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2783 "cg_relop.c"

static void ILRelational_ElseOp_73__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 992 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 2790 "cg_relop.c"

static void ILRelational_ElseOp_74__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2797 "cg_relop.c"

static void ILRelational_ElseOp_75__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 992 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 2804 "cg_relop.c"

static void ILRelational_ElseOp_76__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 992 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 2811 "cg_relop.c"

static void ILRelational_ElseOp_77__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2818 "cg_relop.c"

static void ILRelational_ElseOp_78__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 992 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 2825 "cg_relop.c"

static void ILRelational_ElseOp_79__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2832 "cg_relop.c"

static void ILRelational_ElseOp_80__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 992 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 2839 "cg_relop.c"

static void ILRelational_ElseOp_81__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2846 "cg_relop.c"

static void ILRelational_ElseOp_82__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 992 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 2853 "cg_relop.c"

static void ILRelational_ElseOp_83__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 979 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLE, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 2863 "cg_relop.c"

static void ILRelational_ElseOp_84__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 979 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLE, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 2873 "cg_relop.c"

static void ILRelational_ElseOp_85__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 979 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLE, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 2883 "cg_relop.c"

static void ILRelational_ElseOp_86__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 996 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_LessThanOrEqual"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 2894 "cg_relop.c"

static void ILRelational_ElseOp_87__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2901 "cg_relop.c"

static void ILRelational_ElseOp_88__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2908 "cg_relop.c"

static void ILRelational_ElseOp_89__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2915 "cg_relop.c"

static void ILRelational_ElseOp_90__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2922 "cg_relop.c"

static void ILRelational_ElseOp_91__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2929 "cg_relop.c"

static void ILRelational_ElseOp_92__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 972 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 2936 "cg_relop.c"

static void ILRelational_ElseOp_93__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1008 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 2943 "cg_relop.c"

static void ILRelational_ElseOp_94__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 2950 "cg_relop.c"

static void ILRelational_ElseOp_95__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 2957 "cg_relop.c"

static void ILRelational_ElseOp_96__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1041 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 2964 "cg_relop.c"

static void ILRelational_ElseOp_97__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 2971 "cg_relop.c"

static void ILRelational_ElseOp_98__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1041 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 2978 "cg_relop.c"

static void ILRelational_ElseOp_99__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1041 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 2985 "cg_relop.c"

static void ILRelational_ElseOp_100__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 2992 "cg_relop.c"

static void ILRelational_ElseOp_101__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1041 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 2999 "cg_relop.c"

static void ILRelational_ElseOp_102__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3006 "cg_relop.c"

static void ILRelational_ElseOp_103__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1041 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 3013 "cg_relop.c"

static void ILRelational_ElseOp_104__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3020 "cg_relop.c"

static void ILRelational_ElseOp_105__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1041 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 3027 "cg_relop.c"

static void ILRelational_ElseOp_106__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1029 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGT, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 3037 "cg_relop.c"

static void ILRelational_ElseOp_107__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1029 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGT, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 3047 "cg_relop.c"

static void ILRelational_ElseOp_108__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1029 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGT, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 3057 "cg_relop.c"

static void ILRelational_ElseOp_109__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1045 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_GreaterThan"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 3068 "cg_relop.c"

static void ILRelational_ElseOp_110__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3075 "cg_relop.c"

static void ILRelational_ElseOp_111__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3082 "cg_relop.c"

static void ILRelational_ElseOp_112__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3089 "cg_relop.c"

static void ILRelational_ElseOp_113__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3096 "cg_relop.c"

static void ILRelational_ElseOp_114__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3103 "cg_relop.c"

static void ILRelational_ElseOp_115__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1023 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 3110 "cg_relop.c"

static void ILRelational_ElseOp_116__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1057 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 3117 "cg_relop.c"

static void ILRelational_ElseOp_117__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3124 "cg_relop.c"

static void ILRelational_ElseOp_118__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3131 "cg_relop.c"

static void ILRelational_ElseOp_119__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1090 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 3138 "cg_relop.c"

static void ILRelational_ElseOp_120__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3145 "cg_relop.c"

static void ILRelational_ElseOp_121__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1090 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 3152 "cg_relop.c"

static void ILRelational_ElseOp_122__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1090 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 3159 "cg_relop.c"

static void ILRelational_ElseOp_123__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3166 "cg_relop.c"

static void ILRelational_ElseOp_124__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1090 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 3173 "cg_relop.c"

static void ILRelational_ElseOp_125__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3180 "cg_relop.c"

static void ILRelational_ElseOp_126__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1090 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 3187 "cg_relop.c"

static void ILRelational_ElseOp_127__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3194 "cg_relop.c"

static void ILRelational_ElseOp_128__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1090 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 3201 "cg_relop.c"

static void ILRelational_ElseOp_129__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1078 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGE, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 3211 "cg_relop.c"

static void ILRelational_ElseOp_130__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1078 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGE, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 3221 "cg_relop.c"

static void ILRelational_ElseOp_131__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1078 "cg_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGE, &label1);
	ILGenJump(info, IL_OP_BR, label);
	ILGenLabel(info, &label1);
}
#line 3231 "cg_relop.c"

static void ILRelational_ElseOp_132__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1094 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_GreaterThanOrEqual"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRFALSE, label);
}
#line 3242 "cg_relop.c"

static void ILRelational_ElseOp_133__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3249 "cg_relop.c"

static void ILRelational_ElseOp_134__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3256 "cg_relop.c"

static void ILRelational_ElseOp_135__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3263 "cg_relop.c"

static void ILRelational_ElseOp_136__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3270 "cg_relop.c"

static void ILRelational_ElseOp_137__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3277 "cg_relop.c"

static void ILRelational_ElseOp_138__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1072 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 3284 "cg_relop.c"

void ILRelational_ElseOp(ILGenInfo * info, ILNode_Relational * node__, ILMachineType commonType, ILLabel * label)
{
	switch(node__->kind__)
	{
		case ILNode_Eq_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ElseOp_1__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ElseOp_2__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ElseOp_3__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ElseOp_4__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ElseOp_5__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ElseOp_6__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ElseOp_7__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ElseOp_8__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ElseOp_9__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ElseOp_10__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ElseOp_11__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ElseOp_12__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ElseOp_13__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ElseOp_14__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ElseOp_15__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ElseOp_16__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ElseOp_17__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ElseOp_18__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ElseOp_19__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ElseOp_20__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ElseOp_21__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ElseOp_22__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ElseOp_23__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ne_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ElseOp_24__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ElseOp_25__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ElseOp_26__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ElseOp_27__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ElseOp_28__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ElseOp_29__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ElseOp_30__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ElseOp_31__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ElseOp_32__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ElseOp_33__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ElseOp_34__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ElseOp_35__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ElseOp_36__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ElseOp_37__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ElseOp_38__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ElseOp_39__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ElseOp_40__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ElseOp_41__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ElseOp_42__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ElseOp_43__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ElseOp_44__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ElseOp_45__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ElseOp_46__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Lt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ElseOp_47__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ElseOp_48__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ElseOp_49__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ElseOp_50__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ElseOp_51__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ElseOp_52__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ElseOp_53__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ElseOp_54__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ElseOp_55__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ElseOp_56__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ElseOp_57__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ElseOp_58__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ElseOp_59__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ElseOp_60__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ElseOp_61__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ElseOp_62__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ElseOp_63__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ElseOp_64__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ElseOp_65__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ElseOp_66__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ElseOp_67__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ElseOp_68__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ElseOp_69__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Le_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ElseOp_70__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ElseOp_71__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ElseOp_72__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ElseOp_73__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ElseOp_74__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ElseOp_75__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ElseOp_76__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ElseOp_77__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ElseOp_78__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ElseOp_79__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ElseOp_80__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ElseOp_81__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ElseOp_82__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ElseOp_83__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ElseOp_84__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ElseOp_85__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ElseOp_86__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ElseOp_87__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ElseOp_88__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ElseOp_89__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ElseOp_90__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ElseOp_91__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ElseOp_92__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Gt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ElseOp_93__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ElseOp_94__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ElseOp_95__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ElseOp_96__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ElseOp_97__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ElseOp_98__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ElseOp_99__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ElseOp_100__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ElseOp_101__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ElseOp_102__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ElseOp_103__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ElseOp_104__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ElseOp_105__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ElseOp_106__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ElseOp_107__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ElseOp_108__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ElseOp_109__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ElseOp_110__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ElseOp_111__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ElseOp_112__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ElseOp_113__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ElseOp_114__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ElseOp_115__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ge_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ElseOp_116__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ElseOp_117__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ElseOp_118__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ElseOp_119__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ElseOp_120__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ElseOp_121__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ElseOp_122__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ElseOp_123__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ElseOp_124__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ElseOp_125__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ElseOp_126__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ElseOp_127__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ElseOp_128__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ElseOp_129__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ElseOp_130__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ElseOp_131__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ElseOp_132__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ElseOp_133__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ElseOp_134__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ElseOp_135__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ElseOp_136__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ElseOp_137__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ElseOp_138__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void JavaRelational_ApplyOp_1__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 133 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 4181 "cg_relop.c"

static void JavaRelational_ApplyOp_2__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4196 "cg_relop.c"

static void JavaRelational_ApplyOp_3__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4211 "cg_relop.c"

static void JavaRelational_ApplyOp_4__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4226 "cg_relop.c"

static void JavaRelational_ApplyOp_5__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4241 "cg_relop.c"

static void JavaRelational_ApplyOp_6__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4256 "cg_relop.c"

static void JavaRelational_ApplyOp_7__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4271 "cg_relop.c"

static void JavaRelational_ApplyOp_8__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4286 "cg_relop.c"

static void JavaRelational_ApplyOp_9__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4301 "cg_relop.c"

static void JavaRelational_ApplyOp_10__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 159 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4317 "cg_relop.c"

static void JavaRelational_ApplyOp_11__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 159 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4333 "cg_relop.c"

static void JavaRelational_ApplyOp_12__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4348 "cg_relop.c"

static void JavaRelational_ApplyOp_13__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 146 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4363 "cg_relop.c"

static void JavaRelational_ApplyOp_14__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 188 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4379 "cg_relop.c"

static void JavaRelational_ApplyOp_15__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 202 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4395 "cg_relop.c"

static void JavaRelational_ApplyOp_16__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 202 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4411 "cg_relop.c"

static void JavaRelational_ApplyOp_17__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 215 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Equality__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 4429 "cg_relop.c"

static void JavaRelational_ApplyOp_18__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 230 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/String", "op_Equality",
						  "(LSystem/String;LSystem/String;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 4447 "cg_relop.c"

static void JavaRelational_ApplyOp_19__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 176 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4462 "cg_relop.c"

static void JavaRelational_ApplyOp_20__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 176 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4477 "cg_relop.c"

static void JavaRelational_ApplyOp_21__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 176 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4492 "cg_relop.c"

static void JavaRelational_ApplyOp_22__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 176 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4507 "cg_relop.c"

static void JavaRelational_ApplyOp_23__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 176 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4522 "cg_relop.c"

static void JavaRelational_ApplyOp_24__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 249 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 4529 "cg_relop.c"

static void JavaRelational_ApplyOp_25__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4544 "cg_relop.c"

static void JavaRelational_ApplyOp_26__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4559 "cg_relop.c"

static void JavaRelational_ApplyOp_27__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4574 "cg_relop.c"

static void JavaRelational_ApplyOp_28__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4589 "cg_relop.c"

static void JavaRelational_ApplyOp_29__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4604 "cg_relop.c"

static void JavaRelational_ApplyOp_30__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4619 "cg_relop.c"

static void JavaRelational_ApplyOp_31__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4634 "cg_relop.c"

static void JavaRelational_ApplyOp_32__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4649 "cg_relop.c"

static void JavaRelational_ApplyOp_33__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 275 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4665 "cg_relop.c"

static void JavaRelational_ApplyOp_34__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 275 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4681 "cg_relop.c"

static void JavaRelational_ApplyOp_35__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4696 "cg_relop.c"

static void JavaRelational_ApplyOp_36__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 262 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4711 "cg_relop.c"

static void JavaRelational_ApplyOp_37__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 304 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4727 "cg_relop.c"

static void JavaRelational_ApplyOp_38__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 318 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4743 "cg_relop.c"

static void JavaRelational_ApplyOp_39__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 318 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 4759 "cg_relop.c"

static void JavaRelational_ApplyOp_40__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 331 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		ILLabel label1 = ILLabel_Undefined;
		ILLabel label2 = ILLabel_Undefined;
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFEQ, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_1);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_0);
		JavaGenLabel(info, &label2);
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Inequality__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 4785 "cg_relop.c"

static void JavaRelational_ApplyOp_41__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 354 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		ILLabel label1 = ILLabel_Undefined;
		ILLabel label2 = ILLabel_Undefined;
		JavaGenCallVirtual(info, "java/lang/String", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_1);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_0);
		JavaGenLabel(info, &label2);
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/String", "op_Inequality",
						  "(LSystem/String;LSystem/String;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 4811 "cg_relop.c"

static void JavaRelational_ApplyOp_42__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 292 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4826 "cg_relop.c"

static void JavaRelational_ApplyOp_43__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 292 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4841 "cg_relop.c"

static void JavaRelational_ApplyOp_44__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 292 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4856 "cg_relop.c"

static void JavaRelational_ApplyOp_45__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 292 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4871 "cg_relop.c"

static void JavaRelational_ApplyOp_46__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 292 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4886 "cg_relop.c"

static void JavaRelational_ApplyOp_47__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 381 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 4893 "cg_relop.c"

static void JavaRelational_ApplyOp_48__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4908 "cg_relop.c"

static void JavaRelational_ApplyOp_49__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4923 "cg_relop.c"

static void JavaRelational_ApplyOp_50__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4938 "cg_relop.c"

static void JavaRelational_ApplyOp_51__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4953 "cg_relop.c"

static void JavaRelational_ApplyOp_52__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4968 "cg_relop.c"

static void JavaRelational_ApplyOp_53__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4983 "cg_relop.c"

static void JavaRelational_ApplyOp_54__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 4998 "cg_relop.c"

static void JavaRelational_ApplyOp_55__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 427 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5014 "cg_relop.c"

static void JavaRelational_ApplyOp_56__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 404 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5030 "cg_relop.c"

static void JavaRelational_ApplyOp_57__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 440 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5046 "cg_relop.c"

static void JavaRelational_ApplyOp_58__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 392 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5061 "cg_relop.c"

static void JavaRelational_ApplyOp_59__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 427 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5077 "cg_relop.c"

static void JavaRelational_ApplyOp_60__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 453 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_FCMPG);
	JavaGenJump(info, JAVA_OP_IFGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5093 "cg_relop.c"

static void JavaRelational_ApplyOp_61__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 467 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5109 "cg_relop.c"

static void JavaRelational_ApplyOp_62__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 467 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5125 "cg_relop.c"

static void JavaRelational_ApplyOp_63__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 480 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		ILLabel label1 = ILLabel_Undefined;
		ILLabel label2 = ILLabel_Undefined;
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFGE, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_1);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_0);
		JavaGenLabel(info, &label2);
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_LessThan__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 5151 "cg_relop.c"

static void JavaRelational_ApplyOp_64__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 422 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5158 "cg_relop.c"

static void JavaRelational_ApplyOp_65__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 422 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5165 "cg_relop.c"

static void JavaRelational_ApplyOp_66__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 422 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5172 "cg_relop.c"

static void JavaRelational_ApplyOp_67__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 422 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5179 "cg_relop.c"

static void JavaRelational_ApplyOp_68__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 422 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5186 "cg_relop.c"

static void JavaRelational_ApplyOp_69__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 422 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5193 "cg_relop.c"

static void JavaRelational_ApplyOp_70__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 507 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 5200 "cg_relop.c"

static void JavaRelational_ApplyOp_71__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5215 "cg_relop.c"

static void JavaRelational_ApplyOp_72__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5230 "cg_relop.c"

static void JavaRelational_ApplyOp_73__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5245 "cg_relop.c"

static void JavaRelational_ApplyOp_74__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5260 "cg_relop.c"

static void JavaRelational_ApplyOp_75__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5275 "cg_relop.c"

static void JavaRelational_ApplyOp_76__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5290 "cg_relop.c"

static void JavaRelational_ApplyOp_77__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5305 "cg_relop.c"

static void JavaRelational_ApplyOp_78__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 553 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5321 "cg_relop.c"

static void JavaRelational_ApplyOp_79__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 530 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5337 "cg_relop.c"

static void JavaRelational_ApplyOp_80__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 566 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5353 "cg_relop.c"

static void JavaRelational_ApplyOp_81__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 518 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5368 "cg_relop.c"

static void JavaRelational_ApplyOp_82__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 553 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5384 "cg_relop.c"

static void JavaRelational_ApplyOp_83__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 579 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_FCMPG);
	JavaGenJump(info, JAVA_OP_IFGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5400 "cg_relop.c"

static void JavaRelational_ApplyOp_84__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 593 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5416 "cg_relop.c"

static void JavaRelational_ApplyOp_85__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 593 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5432 "cg_relop.c"

static void JavaRelational_ApplyOp_86__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 606 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		ILLabel label1 = ILLabel_Undefined;
		ILLabel label2 = ILLabel_Undefined;
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFGT, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_1);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_0);
		JavaGenLabel(info, &label2);
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_LessThanOrEqual__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 5458 "cg_relop.c"

static void JavaRelational_ApplyOp_87__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 548 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5465 "cg_relop.c"

static void JavaRelational_ApplyOp_88__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 548 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5472 "cg_relop.c"

static void JavaRelational_ApplyOp_89__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 548 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5479 "cg_relop.c"

static void JavaRelational_ApplyOp_90__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 548 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5486 "cg_relop.c"

static void JavaRelational_ApplyOp_91__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 548 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5493 "cg_relop.c"

static void JavaRelational_ApplyOp_92__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 548 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5500 "cg_relop.c"

static void JavaRelational_ApplyOp_93__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 633 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 5507 "cg_relop.c"

static void JavaRelational_ApplyOp_94__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5522 "cg_relop.c"

static void JavaRelational_ApplyOp_95__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5537 "cg_relop.c"

static void JavaRelational_ApplyOp_96__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5552 "cg_relop.c"

static void JavaRelational_ApplyOp_97__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5567 "cg_relop.c"

static void JavaRelational_ApplyOp_98__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5582 "cg_relop.c"

static void JavaRelational_ApplyOp_99__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5597 "cg_relop.c"

static void JavaRelational_ApplyOp_100__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5612 "cg_relop.c"

static void JavaRelational_ApplyOp_101__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 679 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5628 "cg_relop.c"

static void JavaRelational_ApplyOp_102__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 656 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5644 "cg_relop.c"

static void JavaRelational_ApplyOp_103__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 692 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5660 "cg_relop.c"

static void JavaRelational_ApplyOp_104__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 644 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5675 "cg_relop.c"

static void JavaRelational_ApplyOp_105__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 679 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5691 "cg_relop.c"

static void JavaRelational_ApplyOp_106__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 705 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5707 "cg_relop.c"

static void JavaRelational_ApplyOp_107__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 719 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5723 "cg_relop.c"

static void JavaRelational_ApplyOp_108__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 719 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLE, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5739 "cg_relop.c"

static void JavaRelational_ApplyOp_109__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 732 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		ILLabel label1 = ILLabel_Undefined;
		ILLabel label2 = ILLabel_Undefined;
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFLE, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_1);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_0);
		JavaGenLabel(info, &label2);
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_GreaterThan__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 5765 "cg_relop.c"

static void JavaRelational_ApplyOp_110__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 674 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5772 "cg_relop.c"

static void JavaRelational_ApplyOp_111__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 674 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5779 "cg_relop.c"

static void JavaRelational_ApplyOp_112__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 674 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5786 "cg_relop.c"

static void JavaRelational_ApplyOp_113__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 674 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5793 "cg_relop.c"

static void JavaRelational_ApplyOp_114__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 674 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5800 "cg_relop.c"

static void JavaRelational_ApplyOp_115__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 674 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 5807 "cg_relop.c"

static void JavaRelational_ApplyOp_116__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 759 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 5814 "cg_relop.c"

static void JavaRelational_ApplyOp_117__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5829 "cg_relop.c"

static void JavaRelational_ApplyOp_118__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5844 "cg_relop.c"

static void JavaRelational_ApplyOp_119__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5859 "cg_relop.c"

static void JavaRelational_ApplyOp_120__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5874 "cg_relop.c"

static void JavaRelational_ApplyOp_121__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5889 "cg_relop.c"

static void JavaRelational_ApplyOp_122__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5904 "cg_relop.c"

static void JavaRelational_ApplyOp_123__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5919 "cg_relop.c"

static void JavaRelational_ApplyOp_124__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 805 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5935 "cg_relop.c"

static void JavaRelational_ApplyOp_125__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 782 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5951 "cg_relop.c"

static void JavaRelational_ApplyOp_126__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 818 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 5967 "cg_relop.c"

static void JavaRelational_ApplyOp_127__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 770 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5982 "cg_relop.c"

static void JavaRelational_ApplyOp_128__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 805 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 5998 "cg_relop.c"

static void JavaRelational_ApplyOp_129__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 831 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -1);
}
#line 6014 "cg_relop.c"

static void JavaRelational_ApplyOp_130__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 845 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 6030 "cg_relop.c"

static void JavaRelational_ApplyOp_131__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 845 "jv_relop.tc"
{
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLT, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenJump(info, JAVA_OP_GOTO, &label2);
	JavaGenLabel(info, &label1);
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenLabel(info, &label2);
	JavaGenAdjust(info, -3);
}
#line 6046 "cg_relop.c"

static void JavaRelational_ApplyOp_132__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 858 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		ILLabel label1 = ILLabel_Undefined;
		ILLabel label2 = ILLabel_Undefined;
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFLT, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_1);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenSimple(info, JAVA_OP_ICONST_0);
		JavaGenLabel(info, &label2);
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_GreaterThanOrEqual__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenAdjust(info, -1);
	}
}
#line 6072 "cg_relop.c"

static void JavaRelational_ApplyOp_133__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 800 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 6079 "cg_relop.c"

static void JavaRelational_ApplyOp_134__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 800 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 6086 "cg_relop.c"

static void JavaRelational_ApplyOp_135__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 800 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 6093 "cg_relop.c"

static void JavaRelational_ApplyOp_136__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 800 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 6100 "cg_relop.c"

static void JavaRelational_ApplyOp_137__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 800 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 6107 "cg_relop.c"

static void JavaRelational_ApplyOp_138__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 800 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 6114 "cg_relop.c"

void JavaRelational_ApplyOp(ILGenInfo * info, ILNode_Relational * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_Eq_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ApplyOp_1__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ApplyOp_2__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ApplyOp_3__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ApplyOp_4__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ApplyOp_5__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ApplyOp_6__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ApplyOp_7__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ApplyOp_8__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ApplyOp_9__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ApplyOp_10__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ApplyOp_11__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ApplyOp_12__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ApplyOp_13__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ApplyOp_14__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ApplyOp_15__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ApplyOp_16__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ApplyOp_17__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ApplyOp_18__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ApplyOp_19__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ApplyOp_20__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ApplyOp_21__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ApplyOp_22__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ApplyOp_23__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ne_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ApplyOp_24__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ApplyOp_25__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ApplyOp_26__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ApplyOp_27__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ApplyOp_28__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ApplyOp_29__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ApplyOp_30__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ApplyOp_31__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ApplyOp_32__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ApplyOp_33__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ApplyOp_34__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ApplyOp_35__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ApplyOp_36__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ApplyOp_37__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ApplyOp_38__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ApplyOp_39__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ApplyOp_40__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ApplyOp_41__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ApplyOp_42__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ApplyOp_43__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ApplyOp_44__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ApplyOp_45__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ApplyOp_46__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Lt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ApplyOp_47__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ApplyOp_48__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ApplyOp_49__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ApplyOp_50__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ApplyOp_51__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ApplyOp_52__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ApplyOp_53__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ApplyOp_54__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ApplyOp_55__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ApplyOp_56__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ApplyOp_57__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ApplyOp_58__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ApplyOp_59__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ApplyOp_60__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ApplyOp_61__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ApplyOp_62__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ApplyOp_63__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ApplyOp_64__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ApplyOp_65__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ApplyOp_66__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ApplyOp_67__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ApplyOp_68__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ApplyOp_69__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Le_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ApplyOp_70__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ApplyOp_71__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ApplyOp_72__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ApplyOp_73__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ApplyOp_74__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ApplyOp_75__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ApplyOp_76__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ApplyOp_77__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ApplyOp_78__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ApplyOp_79__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ApplyOp_80__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ApplyOp_81__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ApplyOp_82__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ApplyOp_83__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ApplyOp_84__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ApplyOp_85__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ApplyOp_86__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ApplyOp_87__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ApplyOp_88__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ApplyOp_89__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ApplyOp_90__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ApplyOp_91__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ApplyOp_92__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Gt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ApplyOp_93__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ApplyOp_94__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ApplyOp_95__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ApplyOp_96__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ApplyOp_97__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ApplyOp_98__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ApplyOp_99__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ApplyOp_100__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ApplyOp_101__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ApplyOp_102__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ApplyOp_103__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ApplyOp_104__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ApplyOp_105__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ApplyOp_106__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ApplyOp_107__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ApplyOp_108__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ApplyOp_109__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ApplyOp_110__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ApplyOp_111__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ApplyOp_112__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ApplyOp_113__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ApplyOp_114__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ApplyOp_115__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ge_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ApplyOp_116__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ApplyOp_117__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ApplyOp_118__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ApplyOp_119__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ApplyOp_120__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ApplyOp_121__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ApplyOp_122__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ApplyOp_123__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ApplyOp_124__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ApplyOp_125__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ApplyOp_126__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ApplyOp_127__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ApplyOp_128__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ApplyOp_129__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ApplyOp_130__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ApplyOp_131__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ApplyOp_132__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ApplyOp_133__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ApplyOp_134__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ApplyOp_135__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ApplyOp_136__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ApplyOp_137__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ApplyOp_138__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void JavaRelational_ElseOp_1__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1367 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 7011 "cg_relop.c"

static void JavaRelational_ElseOp_2__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7019 "cg_relop.c"

static void JavaRelational_ElseOp_3__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7027 "cg_relop.c"

static void JavaRelational_ElseOp_4__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7035 "cg_relop.c"

static void JavaRelational_ElseOp_5__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7043 "cg_relop.c"

static void JavaRelational_ElseOp_6__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7051 "cg_relop.c"

static void JavaRelational_ElseOp_7__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7059 "cg_relop.c"

static void JavaRelational_ElseOp_8__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7067 "cg_relop.c"

static void JavaRelational_ElseOp_9__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7075 "cg_relop.c"

static void JavaRelational_ElseOp_10__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1386 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -4);
}
#line 7084 "cg_relop.c"

static void JavaRelational_ElseOp_11__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1386 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -4);
}
#line 7093 "cg_relop.c"

static void JavaRelational_ElseOp_12__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7101 "cg_relop.c"

static void JavaRelational_ElseOp_13__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1380 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7109 "cg_relop.c"

static void JavaRelational_ElseOp_14__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1401 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -2);
}
#line 7118 "cg_relop.c"

static void JavaRelational_ElseOp_15__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1408 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -2);
}
#line 7127 "cg_relop.c"

static void JavaRelational_ElseOp_16__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1408 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -2);
}
#line 7136 "cg_relop.c"

static void JavaRelational_ElseOp_17__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1414 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Equality__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 7156 "cg_relop.c"

static void JavaRelational_ElseOp_18__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1431 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/String", "op_Equality",
						  "(LSystem/String;LSystem/String;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 7176 "cg_relop.c"

static void JavaRelational_ElseOp_19__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1396 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7184 "cg_relop.c"

static void JavaRelational_ElseOp_20__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1396 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7192 "cg_relop.c"

static void JavaRelational_ElseOp_21__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1396 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7200 "cg_relop.c"

static void JavaRelational_ElseOp_22__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1396 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7208 "cg_relop.c"

static void JavaRelational_ElseOp_23__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 1396 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 7216 "cg_relop.c"

static void JavaRelational_ElseOp_24__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1452 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 7223 "cg_relop.c"

static void JavaRelational_ElseOp_25__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7231 "cg_relop.c"

static void JavaRelational_ElseOp_26__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7239 "cg_relop.c"

static void JavaRelational_ElseOp_27__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7247 "cg_relop.c"

static void JavaRelational_ElseOp_28__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7255 "cg_relop.c"

static void JavaRelational_ElseOp_29__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7263 "cg_relop.c"

static void JavaRelational_ElseOp_30__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7271 "cg_relop.c"

static void JavaRelational_ElseOp_31__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7279 "cg_relop.c"

static void JavaRelational_ElseOp_32__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7287 "cg_relop.c"

static void JavaRelational_ElseOp_33__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1471 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -4);
}
#line 7296 "cg_relop.c"

static void JavaRelational_ElseOp_34__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1471 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -4);
}
#line 7305 "cg_relop.c"

static void JavaRelational_ElseOp_35__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7313 "cg_relop.c"

static void JavaRelational_ElseOp_36__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1465 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7321 "cg_relop.c"

static void JavaRelational_ElseOp_37__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1486 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7330 "cg_relop.c"

static void JavaRelational_ElseOp_38__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1493 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7339 "cg_relop.c"

static void JavaRelational_ElseOp_39__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1493 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7348 "cg_relop.c"

static void JavaRelational_ElseOp_40__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1499 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Inequality__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 7368 "cg_relop.c"

static void JavaRelational_ElseOp_41__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1516 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/String", "op_Inequality",
						  "(LSystem/String;LSystem/String;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 7388 "cg_relop.c"

static void JavaRelational_ElseOp_42__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1481 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7396 "cg_relop.c"

static void JavaRelational_ElseOp_43__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1481 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7404 "cg_relop.c"

static void JavaRelational_ElseOp_44__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1481 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7412 "cg_relop.c"

static void JavaRelational_ElseOp_45__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1481 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7420 "cg_relop.c"

static void JavaRelational_ElseOp_46__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1481 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 7428 "cg_relop.c"

static void JavaRelational_ElseOp_47__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1537 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 7435 "cg_relop.c"

static void JavaRelational_ElseOp_48__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7443 "cg_relop.c"

static void JavaRelational_ElseOp_49__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7451 "cg_relop.c"

static void JavaRelational_ElseOp_50__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7459 "cg_relop.c"

static void JavaRelational_ElseOp_51__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7467 "cg_relop.c"

static void JavaRelational_ElseOp_52__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7475 "cg_relop.c"

static void JavaRelational_ElseOp_53__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7483 "cg_relop.c"

static void JavaRelational_ElseOp_54__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7491 "cg_relop.c"

static void JavaRelational_ElseOp_55__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1554 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 7500 "cg_relop.c"

static void JavaRelational_ElseOp_56__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1560 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -4);
}
#line 7509 "cg_relop.c"

static void JavaRelational_ElseOp_57__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1566 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -4);
}
#line 7518 "cg_relop.c"

static void JavaRelational_ElseOp_58__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1548 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 7526 "cg_relop.c"

static void JavaRelational_ElseOp_59__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1554 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 7535 "cg_relop.c"

static void JavaRelational_ElseOp_60__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1581 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPG);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 7544 "cg_relop.c"

static void JavaRelational_ElseOp_61__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1588 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 7553 "cg_relop.c"

static void JavaRelational_ElseOp_62__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1588 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 7562 "cg_relop.c"

static void JavaRelational_ElseOp_63__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1594 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFGE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_LessThan__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 7582 "cg_relop.c"

static void JavaRelational_ElseOp_64__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1577 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7589 "cg_relop.c"

static void JavaRelational_ElseOp_65__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1577 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7596 "cg_relop.c"

static void JavaRelational_ElseOp_66__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1577 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7603 "cg_relop.c"

static void JavaRelational_ElseOp_67__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1577 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7610 "cg_relop.c"

static void JavaRelational_ElseOp_68__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1577 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7617 "cg_relop.c"

static void JavaRelational_ElseOp_69__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1577 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7624 "cg_relop.c"

static void JavaRelational_ElseOp_70__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1615 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 7631 "cg_relop.c"

static void JavaRelational_ElseOp_71__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7639 "cg_relop.c"

static void JavaRelational_ElseOp_72__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7647 "cg_relop.c"

static void JavaRelational_ElseOp_73__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7655 "cg_relop.c"

static void JavaRelational_ElseOp_74__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7663 "cg_relop.c"

static void JavaRelational_ElseOp_75__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7671 "cg_relop.c"

static void JavaRelational_ElseOp_76__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7679 "cg_relop.c"

static void JavaRelational_ElseOp_77__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7687 "cg_relop.c"

static void JavaRelational_ElseOp_78__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1632 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 7696 "cg_relop.c"

static void JavaRelational_ElseOp_79__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1638 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -4);
}
#line 7705 "cg_relop.c"

static void JavaRelational_ElseOp_80__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1644 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -4);
}
#line 7714 "cg_relop.c"

static void JavaRelational_ElseOp_81__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1626 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 7722 "cg_relop.c"

static void JavaRelational_ElseOp_82__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1632 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 7731 "cg_relop.c"

static void JavaRelational_ElseOp_83__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1659 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPG);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 7740 "cg_relop.c"

static void JavaRelational_ElseOp_84__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1666 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 7749 "cg_relop.c"

static void JavaRelational_ElseOp_85__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1666 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 7758 "cg_relop.c"

static void JavaRelational_ElseOp_86__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1672 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFGT, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_LessThanOrEqual__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 7778 "cg_relop.c"

static void JavaRelational_ElseOp_87__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1655 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7785 "cg_relop.c"

static void JavaRelational_ElseOp_88__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1655 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7792 "cg_relop.c"

static void JavaRelational_ElseOp_89__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1655 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7799 "cg_relop.c"

static void JavaRelational_ElseOp_90__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1655 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7806 "cg_relop.c"

static void JavaRelational_ElseOp_91__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1655 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7813 "cg_relop.c"

static void JavaRelational_ElseOp_92__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1655 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7820 "cg_relop.c"

static void JavaRelational_ElseOp_93__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1693 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 7827 "cg_relop.c"

static void JavaRelational_ElseOp_94__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7835 "cg_relop.c"

static void JavaRelational_ElseOp_95__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7843 "cg_relop.c"

static void JavaRelational_ElseOp_96__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7851 "cg_relop.c"

static void JavaRelational_ElseOp_97__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7859 "cg_relop.c"

static void JavaRelational_ElseOp_98__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7867 "cg_relop.c"

static void JavaRelational_ElseOp_99__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7875 "cg_relop.c"

static void JavaRelational_ElseOp_100__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7883 "cg_relop.c"

static void JavaRelational_ElseOp_101__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1710 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 7892 "cg_relop.c"

static void JavaRelational_ElseOp_102__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1716 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -4);
}
#line 7901 "cg_relop.c"

static void JavaRelational_ElseOp_103__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1722 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -4);
}
#line 7910 "cg_relop.c"

static void JavaRelational_ElseOp_104__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1704 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 7918 "cg_relop.c"

static void JavaRelational_ElseOp_105__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1710 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 7927 "cg_relop.c"

static void JavaRelational_ElseOp_106__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1737 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 7936 "cg_relop.c"

static void JavaRelational_ElseOp_107__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1744 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 7945 "cg_relop.c"

static void JavaRelational_ElseOp_108__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1744 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 7954 "cg_relop.c"

static void JavaRelational_ElseOp_109__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1750 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFLE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_GreaterThan__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 7974 "cg_relop.c"

static void JavaRelational_ElseOp_110__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1733 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7981 "cg_relop.c"

static void JavaRelational_ElseOp_111__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1733 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7988 "cg_relop.c"

static void JavaRelational_ElseOp_112__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1733 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 7995 "cg_relop.c"

static void JavaRelational_ElseOp_113__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1733 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8002 "cg_relop.c"

static void JavaRelational_ElseOp_114__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1733 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8009 "cg_relop.c"

static void JavaRelational_ElseOp_115__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1733 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8016 "cg_relop.c"

static void JavaRelational_ElseOp_116__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1771 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 8023 "cg_relop.c"

static void JavaRelational_ElseOp_117__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8031 "cg_relop.c"

static void JavaRelational_ElseOp_118__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8039 "cg_relop.c"

static void JavaRelational_ElseOp_119__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8047 "cg_relop.c"

static void JavaRelational_ElseOp_120__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8055 "cg_relop.c"

static void JavaRelational_ElseOp_121__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8063 "cg_relop.c"

static void JavaRelational_ElseOp_122__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8071 "cg_relop.c"

static void JavaRelational_ElseOp_123__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8079 "cg_relop.c"

static void JavaRelational_ElseOp_124__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1788 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 8088 "cg_relop.c"

static void JavaRelational_ElseOp_125__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1794 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -4);
}
#line 8097 "cg_relop.c"

static void JavaRelational_ElseOp_126__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1800 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -4);
}
#line 8106 "cg_relop.c"

static void JavaRelational_ElseOp_127__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1782 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 8114 "cg_relop.c"

static void JavaRelational_ElseOp_128__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1788 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 8123 "cg_relop.c"

static void JavaRelational_ElseOp_129__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1815 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 8132 "cg_relop.c"

static void JavaRelational_ElseOp_130__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1822 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 8141 "cg_relop.c"

static void JavaRelational_ElseOp_131__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1822 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 8150 "cg_relop.c"

static void JavaRelational_ElseOp_132__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1828 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFLT, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_GreaterThanOrEqual__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
}
#line 8170 "cg_relop.c"

static void JavaRelational_ElseOp_133__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1811 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8177 "cg_relop.c"

static void JavaRelational_ElseOp_134__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1811 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8184 "cg_relop.c"

static void JavaRelational_ElseOp_135__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1811 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8191 "cg_relop.c"

static void JavaRelational_ElseOp_136__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1811 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8198 "cg_relop.c"

static void JavaRelational_ElseOp_137__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1811 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8205 "cg_relop.c"

static void JavaRelational_ElseOp_138__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1811 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 8212 "cg_relop.c"

void JavaRelational_ElseOp(ILGenInfo * info, ILNode_Relational * node__, ILMachineType commonType, ILLabel * label)
{
	switch(node__->kind__)
	{
		case ILNode_Eq_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ElseOp_1__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ElseOp_2__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ElseOp_3__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ElseOp_4__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ElseOp_5__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ElseOp_6__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ElseOp_7__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ElseOp_8__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ElseOp_9__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ElseOp_10__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ElseOp_11__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ElseOp_12__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ElseOp_13__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ElseOp_14__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ElseOp_15__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ElseOp_16__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ElseOp_17__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ElseOp_18__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ElseOp_19__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ElseOp_20__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ElseOp_21__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ElseOp_22__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ElseOp_23__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ne_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ElseOp_24__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ElseOp_25__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ElseOp_26__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ElseOp_27__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ElseOp_28__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ElseOp_29__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ElseOp_30__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ElseOp_31__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ElseOp_32__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ElseOp_33__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ElseOp_34__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ElseOp_35__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ElseOp_36__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ElseOp_37__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ElseOp_38__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ElseOp_39__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ElseOp_40__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ElseOp_41__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ElseOp_42__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ElseOp_43__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ElseOp_44__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ElseOp_45__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ElseOp_46__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Lt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ElseOp_47__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ElseOp_48__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ElseOp_49__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ElseOp_50__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ElseOp_51__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ElseOp_52__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ElseOp_53__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ElseOp_54__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ElseOp_55__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ElseOp_56__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ElseOp_57__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ElseOp_58__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ElseOp_59__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ElseOp_60__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ElseOp_61__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ElseOp_62__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ElseOp_63__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ElseOp_64__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ElseOp_65__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ElseOp_66__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ElseOp_67__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ElseOp_68__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ElseOp_69__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Le_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ElseOp_70__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ElseOp_71__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ElseOp_72__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ElseOp_73__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ElseOp_74__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ElseOp_75__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ElseOp_76__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ElseOp_77__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ElseOp_78__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ElseOp_79__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ElseOp_80__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ElseOp_81__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ElseOp_82__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ElseOp_83__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ElseOp_84__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ElseOp_85__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ElseOp_86__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ElseOp_87__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ElseOp_88__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ElseOp_89__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ElseOp_90__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ElseOp_91__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ElseOp_92__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Gt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ElseOp_93__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ElseOp_94__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ElseOp_95__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ElseOp_96__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ElseOp_97__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ElseOp_98__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ElseOp_99__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ElseOp_100__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ElseOp_101__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ElseOp_102__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ElseOp_103__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ElseOp_104__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ElseOp_105__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ElseOp_106__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ElseOp_107__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ElseOp_108__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ElseOp_109__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ElseOp_110__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ElseOp_111__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ElseOp_112__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ElseOp_113__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ElseOp_114__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ElseOp_115__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ge_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ElseOp_116__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ElseOp_117__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ElseOp_118__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ElseOp_119__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ElseOp_120__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ElseOp_121__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ElseOp_122__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ElseOp_123__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ElseOp_124__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ElseOp_125__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ElseOp_126__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ElseOp_127__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ElseOp_128__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ElseOp_129__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ElseOp_130__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ElseOp_131__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ElseOp_132__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ElseOp_133__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ElseOp_134__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ElseOp_135__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ElseOp_136__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ElseOp_137__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ElseOp_138__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void ILRelational_ApplyOp_1__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 214 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 9109 "cg_relop.c"

static void ILRelational_ApplyOp_2__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9116 "cg_relop.c"

static void ILRelational_ApplyOp_3__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9123 "cg_relop.c"

static void ILRelational_ApplyOp_4__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9130 "cg_relop.c"

static void ILRelational_ApplyOp_5__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9137 "cg_relop.c"

static void ILRelational_ApplyOp_6__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9144 "cg_relop.c"

static void ILRelational_ApplyOp_7__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9151 "cg_relop.c"

static void ILRelational_ApplyOp_8__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9158 "cg_relop.c"

static void ILRelational_ApplyOp_9__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9165 "cg_relop.c"

static void ILRelational_ApplyOp_10__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9172 "cg_relop.c"

static void ILRelational_ApplyOp_11__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9179 "cg_relop.c"

static void ILRelational_ApplyOp_12__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9186 "cg_relop.c"

static void ILRelational_ApplyOp_13__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9193 "cg_relop.c"

static void ILRelational_ApplyOp_14__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 240 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BEQ, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9209 "cg_relop.c"

static void ILRelational_ApplyOp_15__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 240 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BEQ, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9225 "cg_relop.c"

static void ILRelational_ApplyOp_16__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 240 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BEQ, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9241 "cg_relop.c"

static void ILRelational_ApplyOp_17__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 253 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_Equality"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 9251 "cg_relop.c"

static void ILRelational_ApplyOp_18__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 260 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.String::op_Equality"
			"(class [.library]System.String, class [.library]System.String)");
}
#line 9260 "cg_relop.c"

static void ILRelational_ApplyOp_19__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9267 "cg_relop.c"

static void ILRelational_ApplyOp_20__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9274 "cg_relop.c"

static void ILRelational_ApplyOp_21__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9281 "cg_relop.c"

static void ILRelational_ApplyOp_22__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9288 "cg_relop.c"

static void ILRelational_ApplyOp_23__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType)
#line 234 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
}
#line 9295 "cg_relop.c"

static void ILRelational_ApplyOp_24__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 270 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 9302 "cg_relop.c"

static void ILRelational_ApplyOp_25__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9311 "cg_relop.c"

static void ILRelational_ApplyOp_26__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9320 "cg_relop.c"

static void ILRelational_ApplyOp_27__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9329 "cg_relop.c"

static void ILRelational_ApplyOp_28__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9338 "cg_relop.c"

static void ILRelational_ApplyOp_29__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9347 "cg_relop.c"

static void ILRelational_ApplyOp_30__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9356 "cg_relop.c"

static void ILRelational_ApplyOp_31__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9365 "cg_relop.c"

static void ILRelational_ApplyOp_32__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9374 "cg_relop.c"

static void ILRelational_ApplyOp_33__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9383 "cg_relop.c"

static void ILRelational_ApplyOp_34__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9392 "cg_relop.c"

static void ILRelational_ApplyOp_35__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9401 "cg_relop.c"

static void ILRelational_ApplyOp_36__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9410 "cg_relop.c"

static void ILRelational_ApplyOp_37__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 298 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BNE_UN, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9426 "cg_relop.c"

static void ILRelational_ApplyOp_38__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 298 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BNE_UN, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9442 "cg_relop.c"

static void ILRelational_ApplyOp_39__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 298 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BNE_UN, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9458 "cg_relop.c"

static void ILRelational_ApplyOp_40__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 311 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_Inequality"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 9468 "cg_relop.c"

static void ILRelational_ApplyOp_41__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 318 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.String::op_Inequality"
			"(class [.library]System.String, class [.library]System.String)");
}
#line 9477 "cg_relop.c"

static void ILRelational_ApplyOp_42__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9486 "cg_relop.c"

static void ILRelational_ApplyOp_43__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9495 "cg_relop.c"

static void ILRelational_ApplyOp_44__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9504 "cg_relop.c"

static void ILRelational_ApplyOp_45__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9513 "cg_relop.c"

static void ILRelational_ApplyOp_46__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType)
#line 290 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CEQ);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9522 "cg_relop.c"

static void ILRelational_ApplyOp_47__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 328 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 9529 "cg_relop.c"

static void ILRelational_ApplyOp_48__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9536 "cg_relop.c"

static void ILRelational_ApplyOp_49__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9543 "cg_relop.c"

static void ILRelational_ApplyOp_50__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 352 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
}
#line 9550 "cg_relop.c"

static void ILRelational_ApplyOp_51__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9557 "cg_relop.c"

static void ILRelational_ApplyOp_52__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 352 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
}
#line 9564 "cg_relop.c"

static void ILRelational_ApplyOp_53__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 352 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
}
#line 9571 "cg_relop.c"

static void ILRelational_ApplyOp_54__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9578 "cg_relop.c"

static void ILRelational_ApplyOp_55__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 352 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
}
#line 9585 "cg_relop.c"

static void ILRelational_ApplyOp_56__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9592 "cg_relop.c"

static void ILRelational_ApplyOp_57__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 352 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
}
#line 9599 "cg_relop.c"

static void ILRelational_ApplyOp_58__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9606 "cg_relop.c"

static void ILRelational_ApplyOp_59__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 352 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
}
#line 9613 "cg_relop.c"

static void ILRelational_ApplyOp_60__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 358 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9629 "cg_relop.c"

static void ILRelational_ApplyOp_61__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 358 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9645 "cg_relop.c"

static void ILRelational_ApplyOp_62__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 358 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9661 "cg_relop.c"

static void ILRelational_ApplyOp_63__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 371 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_LessThan"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 9671 "cg_relop.c"

static void ILRelational_ApplyOp_64__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9678 "cg_relop.c"

static void ILRelational_ApplyOp_65__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9685 "cg_relop.c"

static void ILRelational_ApplyOp_66__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9692 "cg_relop.c"

static void ILRelational_ApplyOp_67__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9699 "cg_relop.c"

static void ILRelational_ApplyOp_68__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9706 "cg_relop.c"

static void ILRelational_ApplyOp_69__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType)
#line 343 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
}
#line 9713 "cg_relop.c"

static void ILRelational_ApplyOp_70__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 382 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 9720 "cg_relop.c"

static void ILRelational_ApplyOp_71__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9729 "cg_relop.c"

static void ILRelational_ApplyOp_72__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9738 "cg_relop.c"

static void ILRelational_ApplyOp_73__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 408 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9747 "cg_relop.c"

static void ILRelational_ApplyOp_74__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9756 "cg_relop.c"

static void ILRelational_ApplyOp_75__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 408 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9765 "cg_relop.c"

static void ILRelational_ApplyOp_76__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 408 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9774 "cg_relop.c"

static void ILRelational_ApplyOp_77__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9783 "cg_relop.c"

static void ILRelational_ApplyOp_78__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 408 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9792 "cg_relop.c"

static void ILRelational_ApplyOp_79__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9801 "cg_relop.c"

static void ILRelational_ApplyOp_80__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 408 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9810 "cg_relop.c"

static void ILRelational_ApplyOp_81__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9819 "cg_relop.c"

static void ILRelational_ApplyOp_82__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 408 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9828 "cg_relop.c"

static void ILRelational_ApplyOp_83__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 416 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLE, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9844 "cg_relop.c"

static void ILRelational_ApplyOp_84__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 416 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLE, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9860 "cg_relop.c"

static void ILRelational_ApplyOp_85__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 416 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BLE, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 9876 "cg_relop.c"

static void ILRelational_ApplyOp_86__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 429 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_LessThanOrEqual"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 9886 "cg_relop.c"

static void ILRelational_ApplyOp_87__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9895 "cg_relop.c"

static void ILRelational_ApplyOp_88__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9904 "cg_relop.c"

static void ILRelational_ApplyOp_89__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9913 "cg_relop.c"

static void ILRelational_ApplyOp_90__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9922 "cg_relop.c"

static void ILRelational_ApplyOp_91__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9931 "cg_relop.c"

static void ILRelational_ApplyOp_92__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType)
#line 397 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 9940 "cg_relop.c"

static void ILRelational_ApplyOp_93__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 440 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 9947 "cg_relop.c"

static void ILRelational_ApplyOp_94__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 9954 "cg_relop.c"

static void ILRelational_ApplyOp_95__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 9961 "cg_relop.c"

static void ILRelational_ApplyOp_96__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 464 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
}
#line 9968 "cg_relop.c"

static void ILRelational_ApplyOp_97__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 9975 "cg_relop.c"

static void ILRelational_ApplyOp_98__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 464 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
}
#line 9982 "cg_relop.c"

static void ILRelational_ApplyOp_99__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 464 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
}
#line 9989 "cg_relop.c"

static void ILRelational_ApplyOp_100__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 9996 "cg_relop.c"

static void ILRelational_ApplyOp_101__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 464 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
}
#line 10003 "cg_relop.c"

static void ILRelational_ApplyOp_102__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10010 "cg_relop.c"

static void ILRelational_ApplyOp_103__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 464 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
}
#line 10017 "cg_relop.c"

static void ILRelational_ApplyOp_104__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10024 "cg_relop.c"

static void ILRelational_ApplyOp_105__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 464 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT_UN);
}
#line 10031 "cg_relop.c"

static void ILRelational_ApplyOp_106__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 470 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGT, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 10047 "cg_relop.c"

static void ILRelational_ApplyOp_107__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 470 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGT, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 10063 "cg_relop.c"

static void ILRelational_ApplyOp_108__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 470 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGT, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 10079 "cg_relop.c"

static void ILRelational_ApplyOp_109__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 483 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_GreaterThan"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 10089 "cg_relop.c"

static void ILRelational_ApplyOp_110__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10096 "cg_relop.c"

static void ILRelational_ApplyOp_111__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10103 "cg_relop.c"

static void ILRelational_ApplyOp_112__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10110 "cg_relop.c"

static void ILRelational_ApplyOp_113__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10117 "cg_relop.c"

static void ILRelational_ApplyOp_114__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10124 "cg_relop.c"

static void ILRelational_ApplyOp_115__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType)
#line 455 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CGT);
}
#line 10131 "cg_relop.c"

static void ILRelational_ApplyOp_116__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 494 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 10138 "cg_relop.c"

static void ILRelational_ApplyOp_117__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10147 "cg_relop.c"

static void ILRelational_ApplyOp_118__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10156 "cg_relop.c"

static void ILRelational_ApplyOp_119__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 520 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10165 "cg_relop.c"

static void ILRelational_ApplyOp_120__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10174 "cg_relop.c"

static void ILRelational_ApplyOp_121__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 520 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10183 "cg_relop.c"

static void ILRelational_ApplyOp_122__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 520 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10192 "cg_relop.c"

static void ILRelational_ApplyOp_123__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10201 "cg_relop.c"

static void ILRelational_ApplyOp_124__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 520 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10210 "cg_relop.c"

static void ILRelational_ApplyOp_125__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10219 "cg_relop.c"

static void ILRelational_ApplyOp_126__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 520 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10228 "cg_relop.c"

static void ILRelational_ApplyOp_127__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10237 "cg_relop.c"

static void ILRelational_ApplyOp_128__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 520 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT_UN);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10246 "cg_relop.c"

static void ILRelational_ApplyOp_129__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 528 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGE, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 10262 "cg_relop.c"

static void ILRelational_ApplyOp_130__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 528 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGE, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 10278 "cg_relop.c"

static void ILRelational_ApplyOp_131__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 528 "cg_relop.tc"
{
	/* We must use branch instructions or NaN will not
	   be handled correctly by the comparison */
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILGenJump(info, IL_OP_BGE, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenLabel(info, &label2);
}
#line 10294 "cg_relop.c"

static void ILRelational_ApplyOp_132__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 541 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_GreaterThanOrEqual"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
}
#line 10304 "cg_relop.c"

static void ILRelational_ApplyOp_133__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10313 "cg_relop.c"

static void ILRelational_ApplyOp_134__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10322 "cg_relop.c"

static void ILRelational_ApplyOp_135__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10331 "cg_relop.c"

static void ILRelational_ApplyOp_136__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10340 "cg_relop.c"

static void ILRelational_ApplyOp_137__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10349 "cg_relop.c"

static void ILRelational_ApplyOp_138__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType)
#line 509 "cg_relop.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CLT);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_XOR);
}
#line 10358 "cg_relop.c"

void ILRelational_ApplyOp(ILGenInfo * info, ILNode_Relational * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_Eq_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ApplyOp_1__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ApplyOp_2__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ApplyOp_3__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ApplyOp_4__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ApplyOp_5__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ApplyOp_6__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ApplyOp_7__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ApplyOp_8__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ApplyOp_9__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ApplyOp_10__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ApplyOp_11__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ApplyOp_12__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ApplyOp_13__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ApplyOp_14__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ApplyOp_15__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ApplyOp_16__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ApplyOp_17__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ApplyOp_18__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ApplyOp_19__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ApplyOp_20__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ApplyOp_21__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ApplyOp_22__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ApplyOp_23__(info, (ILNode_Eq *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ne_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ApplyOp_24__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ApplyOp_25__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ApplyOp_26__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ApplyOp_27__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ApplyOp_28__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ApplyOp_29__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ApplyOp_30__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ApplyOp_31__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ApplyOp_32__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ApplyOp_33__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ApplyOp_34__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ApplyOp_35__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ApplyOp_36__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ApplyOp_37__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ApplyOp_38__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ApplyOp_39__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ApplyOp_40__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ApplyOp_41__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ApplyOp_42__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ApplyOp_43__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ApplyOp_44__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ApplyOp_45__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ApplyOp_46__(info, (ILNode_Ne *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Lt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ApplyOp_47__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ApplyOp_48__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ApplyOp_49__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ApplyOp_50__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ApplyOp_51__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ApplyOp_52__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ApplyOp_53__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ApplyOp_54__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ApplyOp_55__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ApplyOp_56__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ApplyOp_57__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ApplyOp_58__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ApplyOp_59__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ApplyOp_60__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ApplyOp_61__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ApplyOp_62__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ApplyOp_63__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ApplyOp_64__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ApplyOp_65__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ApplyOp_66__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ApplyOp_67__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ApplyOp_68__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ApplyOp_69__(info, (ILNode_Lt *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Le_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ApplyOp_70__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ApplyOp_71__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ApplyOp_72__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ApplyOp_73__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ApplyOp_74__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ApplyOp_75__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ApplyOp_76__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ApplyOp_77__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ApplyOp_78__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ApplyOp_79__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ApplyOp_80__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ApplyOp_81__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ApplyOp_82__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ApplyOp_83__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ApplyOp_84__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ApplyOp_85__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ApplyOp_86__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ApplyOp_87__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ApplyOp_88__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ApplyOp_89__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ApplyOp_90__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ApplyOp_91__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ApplyOp_92__(info, (ILNode_Le *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Gt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ApplyOp_93__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ApplyOp_94__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ApplyOp_95__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ApplyOp_96__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ApplyOp_97__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ApplyOp_98__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ApplyOp_99__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ApplyOp_100__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ApplyOp_101__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ApplyOp_102__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ApplyOp_103__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ApplyOp_104__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ApplyOp_105__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ApplyOp_106__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ApplyOp_107__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ApplyOp_108__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ApplyOp_109__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ApplyOp_110__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ApplyOp_111__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ApplyOp_112__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ApplyOp_113__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ApplyOp_114__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ApplyOp_115__(info, (ILNode_Gt *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ge_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ApplyOp_116__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ApplyOp_117__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ApplyOp_118__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ApplyOp_119__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ApplyOp_120__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ApplyOp_121__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ApplyOp_122__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ApplyOp_123__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ApplyOp_124__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ApplyOp_125__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ApplyOp_126__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ApplyOp_127__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ApplyOp_128__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ApplyOp_129__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ApplyOp_130__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ApplyOp_131__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ApplyOp_132__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ApplyOp_133__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ApplyOp_134__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ApplyOp_135__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ApplyOp_136__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ApplyOp_137__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ApplyOp_138__(info, (ILNode_Ge *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void ILRelational_ThenOp_1__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 552 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 11255 "cg_relop.c"

static void ILRelational_ThenOp_2__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11262 "cg_relop.c"

static void ILRelational_ThenOp_3__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11269 "cg_relop.c"

static void ILRelational_ThenOp_4__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11276 "cg_relop.c"

static void ILRelational_ThenOp_5__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11283 "cg_relop.c"

static void ILRelational_ThenOp_6__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11290 "cg_relop.c"

static void ILRelational_ThenOp_7__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11297 "cg_relop.c"

static void ILRelational_ThenOp_8__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11304 "cg_relop.c"

static void ILRelational_ThenOp_9__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11311 "cg_relop.c"

static void ILRelational_ThenOp_10__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11318 "cg_relop.c"

static void ILRelational_ThenOp_11__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11325 "cg_relop.c"

static void ILRelational_ThenOp_12__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11332 "cg_relop.c"

static void ILRelational_ThenOp_13__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11339 "cg_relop.c"

static void ILRelational_ThenOp_14__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11346 "cg_relop.c"

static void ILRelational_ThenOp_15__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11353 "cg_relop.c"

static void ILRelational_ThenOp_16__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11360 "cg_relop.c"

static void ILRelational_ThenOp_17__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 579 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_Equality"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 11371 "cg_relop.c"

static void ILRelational_ThenOp_18__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 587 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.String::op_Equality"
			"(class [.library]System.String, class [.library]System.String)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 11381 "cg_relop.c"

static void ILRelational_ThenOp_19__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11388 "cg_relop.c"

static void ILRelational_ThenOp_20__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11395 "cg_relop.c"

static void ILRelational_ThenOp_21__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11402 "cg_relop.c"

static void ILRelational_ThenOp_22__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11409 "cg_relop.c"

static void ILRelational_ThenOp_23__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 575 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BEQ, label);
}
#line 11416 "cg_relop.c"

static void ILRelational_ThenOp_24__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 598 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 11423 "cg_relop.c"

static void ILRelational_ThenOp_25__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11430 "cg_relop.c"

static void ILRelational_ThenOp_26__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11437 "cg_relop.c"

static void ILRelational_ThenOp_27__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11444 "cg_relop.c"

static void ILRelational_ThenOp_28__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11451 "cg_relop.c"

static void ILRelational_ThenOp_29__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11458 "cg_relop.c"

static void ILRelational_ThenOp_30__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11465 "cg_relop.c"

static void ILRelational_ThenOp_31__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11472 "cg_relop.c"

static void ILRelational_ThenOp_32__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11479 "cg_relop.c"

static void ILRelational_ThenOp_33__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11486 "cg_relop.c"

static void ILRelational_ThenOp_34__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11493 "cg_relop.c"

static void ILRelational_ThenOp_35__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11500 "cg_relop.c"

static void ILRelational_ThenOp_36__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11507 "cg_relop.c"

static void ILRelational_ThenOp_37__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11514 "cg_relop.c"

static void ILRelational_ThenOp_38__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11521 "cg_relop.c"

static void ILRelational_ThenOp_39__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11528 "cg_relop.c"

static void ILRelational_ThenOp_40__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 625 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_Inequality"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 11539 "cg_relop.c"

static void ILRelational_ThenOp_41__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 633 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.String::op_Inequality"
			"(class [.library]System.String, class [.library]System.String)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 11549 "cg_relop.c"

static void ILRelational_ThenOp_42__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11556 "cg_relop.c"

static void ILRelational_ThenOp_43__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11563 "cg_relop.c"

static void ILRelational_ThenOp_44__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11570 "cg_relop.c"

static void ILRelational_ThenOp_45__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11577 "cg_relop.c"

static void ILRelational_ThenOp_46__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 621 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BNE_UN, label);
}
#line 11584 "cg_relop.c"

static void ILRelational_ThenOp_47__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 644 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 11591 "cg_relop.c"

static void ILRelational_ThenOp_48__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11598 "cg_relop.c"

static void ILRelational_ThenOp_49__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11605 "cg_relop.c"

static void ILRelational_ThenOp_50__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 671 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 11612 "cg_relop.c"

static void ILRelational_ThenOp_51__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11619 "cg_relop.c"

static void ILRelational_ThenOp_52__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 671 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 11626 "cg_relop.c"

static void ILRelational_ThenOp_53__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 671 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 11633 "cg_relop.c"

static void ILRelational_ThenOp_54__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11640 "cg_relop.c"

static void ILRelational_ThenOp_55__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 671 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 11647 "cg_relop.c"

static void ILRelational_ThenOp_56__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11654 "cg_relop.c"

static void ILRelational_ThenOp_57__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 671 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 11661 "cg_relop.c"

static void ILRelational_ThenOp_58__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11668 "cg_relop.c"

static void ILRelational_ThenOp_59__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 671 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT_UN, label);
}
#line 11675 "cg_relop.c"

static void ILRelational_ThenOp_60__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11682 "cg_relop.c"

static void ILRelational_ThenOp_61__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11689 "cg_relop.c"

static void ILRelational_ThenOp_62__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11696 "cg_relop.c"

static void ILRelational_ThenOp_63__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 675 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_LessThan"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 11707 "cg_relop.c"

static void ILRelational_ThenOp_64__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11714 "cg_relop.c"

static void ILRelational_ThenOp_65__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11721 "cg_relop.c"

static void ILRelational_ThenOp_66__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11728 "cg_relop.c"

static void ILRelational_ThenOp_67__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11735 "cg_relop.c"

static void ILRelational_ThenOp_68__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11742 "cg_relop.c"

static void ILRelational_ThenOp_69__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 662 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLT, label);
}
#line 11749 "cg_relop.c"

static void ILRelational_ThenOp_70__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 687 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 11756 "cg_relop.c"

static void ILRelational_ThenOp_71__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11763 "cg_relop.c"

static void ILRelational_ThenOp_72__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11770 "cg_relop.c"

static void ILRelational_ThenOp_73__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 714 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 11777 "cg_relop.c"

static void ILRelational_ThenOp_74__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11784 "cg_relop.c"

static void ILRelational_ThenOp_75__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 714 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 11791 "cg_relop.c"

static void ILRelational_ThenOp_76__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 714 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 11798 "cg_relop.c"

static void ILRelational_ThenOp_77__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11805 "cg_relop.c"

static void ILRelational_ThenOp_78__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 714 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 11812 "cg_relop.c"

static void ILRelational_ThenOp_79__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11819 "cg_relop.c"

static void ILRelational_ThenOp_80__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 714 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 11826 "cg_relop.c"

static void ILRelational_ThenOp_81__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11833 "cg_relop.c"

static void ILRelational_ThenOp_82__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 714 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE_UN, label);
}
#line 11840 "cg_relop.c"

static void ILRelational_ThenOp_83__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11847 "cg_relop.c"

static void ILRelational_ThenOp_84__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11854 "cg_relop.c"

static void ILRelational_ThenOp_85__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11861 "cg_relop.c"

static void ILRelational_ThenOp_86__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 718 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_LessThanOrEqual"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 11872 "cg_relop.c"

static void ILRelational_ThenOp_87__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11879 "cg_relop.c"

static void ILRelational_ThenOp_88__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11886 "cg_relop.c"

static void ILRelational_ThenOp_89__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11893 "cg_relop.c"

static void ILRelational_ThenOp_90__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11900 "cg_relop.c"

static void ILRelational_ThenOp_91__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11907 "cg_relop.c"

static void ILRelational_ThenOp_92__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 705 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BLE, label);
}
#line 11914 "cg_relop.c"

static void ILRelational_ThenOp_93__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 730 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 11921 "cg_relop.c"

static void ILRelational_ThenOp_94__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 11928 "cg_relop.c"

static void ILRelational_ThenOp_95__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 11935 "cg_relop.c"

static void ILRelational_ThenOp_96__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 757 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 11942 "cg_relop.c"

static void ILRelational_ThenOp_97__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 11949 "cg_relop.c"

static void ILRelational_ThenOp_98__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 757 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 11956 "cg_relop.c"

static void ILRelational_ThenOp_99__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 757 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 11963 "cg_relop.c"

static void ILRelational_ThenOp_100__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 11970 "cg_relop.c"

static void ILRelational_ThenOp_101__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 757 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 11977 "cg_relop.c"

static void ILRelational_ThenOp_102__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 11984 "cg_relop.c"

static void ILRelational_ThenOp_103__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 757 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 11991 "cg_relop.c"

static void ILRelational_ThenOp_104__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 11998 "cg_relop.c"

static void ILRelational_ThenOp_105__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 757 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT_UN, label);
}
#line 12005 "cg_relop.c"

static void ILRelational_ThenOp_106__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12012 "cg_relop.c"

static void ILRelational_ThenOp_107__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12019 "cg_relop.c"

static void ILRelational_ThenOp_108__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12026 "cg_relop.c"

static void ILRelational_ThenOp_109__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 761 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_GreaterThan"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 12037 "cg_relop.c"

static void ILRelational_ThenOp_110__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12044 "cg_relop.c"

static void ILRelational_ThenOp_111__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12051 "cg_relop.c"

static void ILRelational_ThenOp_112__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12058 "cg_relop.c"

static void ILRelational_ThenOp_113__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12065 "cg_relop.c"

static void ILRelational_ThenOp_114__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12072 "cg_relop.c"

static void ILRelational_ThenOp_115__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 748 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGT, label);
}
#line 12079 "cg_relop.c"

static void ILRelational_ThenOp_116__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 773 "cg_relop.tc"
{
	/* Nothing to do here */
}
#line 12086 "cg_relop.c"

static void ILRelational_ThenOp_117__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12093 "cg_relop.c"

static void ILRelational_ThenOp_118__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12100 "cg_relop.c"

static void ILRelational_ThenOp_119__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 800 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 12107 "cg_relop.c"

static void ILRelational_ThenOp_120__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12114 "cg_relop.c"

static void ILRelational_ThenOp_121__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 800 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 12121 "cg_relop.c"

static void ILRelational_ThenOp_122__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 800 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 12128 "cg_relop.c"

static void ILRelational_ThenOp_123__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12135 "cg_relop.c"

static void ILRelational_ThenOp_124__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 800 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 12142 "cg_relop.c"

static void ILRelational_ThenOp_125__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12149 "cg_relop.c"

static void ILRelational_ThenOp_126__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 800 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 12156 "cg_relop.c"

static void ILRelational_ThenOp_127__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12163 "cg_relop.c"

static void ILRelational_ThenOp_128__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 800 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE_UN, label);
}
#line 12170 "cg_relop.c"

static void ILRelational_ThenOp_129__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12177 "cg_relop.c"

static void ILRelational_ThenOp_130__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12184 "cg_relop.c"

static void ILRelational_ThenOp_131__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12191 "cg_relop.c"

static void ILRelational_ThenOp_132__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 804 "cg_relop.tc"
{
	ILGenCallByName(info,
		"bool [.library]System.Decimal::op_GreaterThanOrEqual"
			"(valuetype [.library]System.Decimal, "
			"valuetype [.library]System.Decimal)");
	ILGenJump(info, IL_OP_BRTRUE, label);
}
#line 12202 "cg_relop.c"

static void ILRelational_ThenOp_133__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12209 "cg_relop.c"

static void ILRelational_ThenOp_134__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12216 "cg_relop.c"

static void ILRelational_ThenOp_135__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12223 "cg_relop.c"

static void ILRelational_ThenOp_136__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12230 "cg_relop.c"

static void ILRelational_ThenOp_137__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12237 "cg_relop.c"

static void ILRelational_ThenOp_138__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 791 "cg_relop.tc"
{
	ILGenJump(info, IL_OP_BGE, label);
}
#line 12244 "cg_relop.c"

void ILRelational_ThenOp(ILGenInfo * info, ILNode_Relational * node__, ILMachineType commonType, ILLabel * label)
{
	switch(node__->kind__)
	{
		case ILNode_Eq_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ThenOp_1__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ThenOp_2__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ThenOp_3__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ThenOp_4__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ThenOp_5__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ThenOp_6__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ThenOp_7__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ThenOp_8__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ThenOp_9__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ThenOp_10__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ThenOp_11__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ThenOp_12__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ThenOp_13__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ThenOp_14__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ThenOp_15__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ThenOp_16__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ThenOp_17__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ThenOp_18__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ThenOp_19__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ThenOp_20__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ThenOp_21__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ThenOp_22__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ThenOp_23__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ne_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ThenOp_24__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ThenOp_25__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ThenOp_26__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ThenOp_27__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ThenOp_28__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ThenOp_29__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ThenOp_30__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ThenOp_31__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ThenOp_32__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ThenOp_33__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ThenOp_34__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ThenOp_35__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ThenOp_36__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ThenOp_37__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ThenOp_38__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ThenOp_39__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ThenOp_40__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ThenOp_41__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ThenOp_42__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ThenOp_43__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ThenOp_44__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ThenOp_45__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ThenOp_46__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Lt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ThenOp_47__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ThenOp_48__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ThenOp_49__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ThenOp_50__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ThenOp_51__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ThenOp_52__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ThenOp_53__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ThenOp_54__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ThenOp_55__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ThenOp_56__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ThenOp_57__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ThenOp_58__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ThenOp_59__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ThenOp_60__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ThenOp_61__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ThenOp_62__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ThenOp_63__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ThenOp_64__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ThenOp_65__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ThenOp_66__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ThenOp_67__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ThenOp_68__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ThenOp_69__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Le_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ThenOp_70__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ThenOp_71__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ThenOp_72__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ThenOp_73__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ThenOp_74__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ThenOp_75__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ThenOp_76__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ThenOp_77__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ThenOp_78__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ThenOp_79__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ThenOp_80__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ThenOp_81__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ThenOp_82__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ThenOp_83__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ThenOp_84__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ThenOp_85__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ThenOp_86__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ThenOp_87__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ThenOp_88__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ThenOp_89__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ThenOp_90__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ThenOp_91__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ThenOp_92__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Gt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ThenOp_93__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ThenOp_94__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ThenOp_95__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ThenOp_96__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ThenOp_97__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ThenOp_98__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ThenOp_99__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ThenOp_100__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ThenOp_101__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ThenOp_102__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ThenOp_103__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ThenOp_104__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ThenOp_105__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ThenOp_106__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ThenOp_107__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ThenOp_108__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ThenOp_109__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ThenOp_110__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ThenOp_111__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ThenOp_112__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ThenOp_113__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ThenOp_114__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ThenOp_115__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ge_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					ILRelational_ThenOp_116__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					ILRelational_ThenOp_117__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					ILRelational_ThenOp_118__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					ILRelational_ThenOp_119__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					ILRelational_ThenOp_120__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					ILRelational_ThenOp_121__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					ILRelational_ThenOp_122__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					ILRelational_ThenOp_123__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					ILRelational_ThenOp_124__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					ILRelational_ThenOp_125__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					ILRelational_ThenOp_126__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					ILRelational_ThenOp_127__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					ILRelational_ThenOp_128__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					ILRelational_ThenOp_129__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					ILRelational_ThenOp_130__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					ILRelational_ThenOp_131__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					ILRelational_ThenOp_132__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					ILRelational_ThenOp_133__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					ILRelational_ThenOp_134__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					ILRelational_ThenOp_135__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					ILRelational_ThenOp_136__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					ILRelational_ThenOp_137__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					ILRelational_ThenOp_138__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void JavaRelational_ThenOp_1__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 885 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 13141 "cg_relop.c"

static void JavaRelational_ThenOp_2__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13149 "cg_relop.c"

static void JavaRelational_ThenOp_3__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13157 "cg_relop.c"

static void JavaRelational_ThenOp_4__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13165 "cg_relop.c"

static void JavaRelational_ThenOp_5__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13173 "cg_relop.c"

static void JavaRelational_ThenOp_6__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13181 "cg_relop.c"

static void JavaRelational_ThenOp_7__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13189 "cg_relop.c"

static void JavaRelational_ThenOp_8__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13197 "cg_relop.c"

static void JavaRelational_ThenOp_9__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13205 "cg_relop.c"

static void JavaRelational_ThenOp_10__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 904 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -4);
}
#line 13214 "cg_relop.c"

static void JavaRelational_ThenOp_11__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 904 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -4);
}
#line 13223 "cg_relop.c"

static void JavaRelational_ThenOp_12__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13231 "cg_relop.c"

static void JavaRelational_ThenOp_13__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 898 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13239 "cg_relop.c"

static void JavaRelational_ThenOp_14__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 919 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13248 "cg_relop.c"

static void JavaRelational_ThenOp_15__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 926 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13257 "cg_relop.c"

static void JavaRelational_ThenOp_16__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 926 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13266 "cg_relop.c"

static void JavaRelational_ThenOp_17__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 932 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Equality__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 13286 "cg_relop.c"

static void JavaRelational_ThenOp_18__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 949 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/String", "op_Equality",
						  "(LSystem/String;LSystem/String;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 13306 "cg_relop.c"

static void JavaRelational_ThenOp_19__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 914 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13314 "cg_relop.c"

static void JavaRelational_ThenOp_20__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 914 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13322 "cg_relop.c"

static void JavaRelational_ThenOp_21__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 914 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13330 "cg_relop.c"

static void JavaRelational_ThenOp_22__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 914 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13338 "cg_relop.c"

static void JavaRelational_ThenOp_23__(ILGenInfo * info, ILNode_Eq *node, ILMachineType commonType, ILLabel * label)
#line 914 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPEQ, label);
	JavaGenAdjust(info, -2);
}
#line 13346 "cg_relop.c"

static void JavaRelational_ThenOp_24__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 970 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 13353 "cg_relop.c"

static void JavaRelational_ThenOp_25__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13361 "cg_relop.c"

static void JavaRelational_ThenOp_26__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13369 "cg_relop.c"

static void JavaRelational_ThenOp_27__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13377 "cg_relop.c"

static void JavaRelational_ThenOp_28__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13385 "cg_relop.c"

static void JavaRelational_ThenOp_29__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13393 "cg_relop.c"

static void JavaRelational_ThenOp_30__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13401 "cg_relop.c"

static void JavaRelational_ThenOp_31__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13409 "cg_relop.c"

static void JavaRelational_ThenOp_32__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13417 "cg_relop.c"

static void JavaRelational_ThenOp_33__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 989 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -4);
}
#line 13426 "cg_relop.c"

static void JavaRelational_ThenOp_34__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 989 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -4);
}
#line 13435 "cg_relop.c"

static void JavaRelational_ThenOp_35__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13443 "cg_relop.c"

static void JavaRelational_ThenOp_36__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 983 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13451 "cg_relop.c"

static void JavaRelational_ThenOp_37__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1004 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -2);
}
#line 13460 "cg_relop.c"

static void JavaRelational_ThenOp_38__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1011 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -2);
}
#line 13469 "cg_relop.c"

static void JavaRelational_ThenOp_39__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1011 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFNE, label);
	JavaGenAdjust(info, -2);
}
#line 13478 "cg_relop.c"

static void JavaRelational_ThenOp_40__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1017 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Inequality__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 13498 "cg_relop.c"

static void JavaRelational_ThenOp_41__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 1034 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "equals",
						   "(Ljava/lang/Object;)Z");
		JavaGenJump(info, JAVA_OP_IFEQ, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/String", "op_Inequality",
						  "(LSystem/String;LSystem/String;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 13518 "cg_relop.c"

static void JavaRelational_ThenOp_42__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 999 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13526 "cg_relop.c"

static void JavaRelational_ThenOp_43__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 999 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13534 "cg_relop.c"

static void JavaRelational_ThenOp_44__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 999 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13542 "cg_relop.c"

static void JavaRelational_ThenOp_45__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 999 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13550 "cg_relop.c"

static void JavaRelational_ThenOp_46__(ILGenInfo * info, ILNode_Ne *node, ILMachineType commonType, ILLabel * label)
#line 999 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ACMPNE, label);
	JavaGenAdjust(info, -2);
}
#line 13558 "cg_relop.c"

static void JavaRelational_ThenOp_47__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1055 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 13565 "cg_relop.c"

static void JavaRelational_ThenOp_48__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13573 "cg_relop.c"

static void JavaRelational_ThenOp_49__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13581 "cg_relop.c"

static void JavaRelational_ThenOp_50__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13589 "cg_relop.c"

static void JavaRelational_ThenOp_51__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13597 "cg_relop.c"

static void JavaRelational_ThenOp_52__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13605 "cg_relop.c"

static void JavaRelational_ThenOp_53__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13613 "cg_relop.c"

static void JavaRelational_ThenOp_54__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13621 "cg_relop.c"

static void JavaRelational_ThenOp_55__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1072 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 13630 "cg_relop.c"

static void JavaRelational_ThenOp_56__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1078 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -4);
}
#line 13639 "cg_relop.c"

static void JavaRelational_ThenOp_57__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1084 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -4);
}
#line 13648 "cg_relop.c"

static void JavaRelational_ThenOp_58__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1066 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, label);
	JavaGenAdjust(info, -2);
}
#line 13656 "cg_relop.c"

static void JavaRelational_ThenOp_59__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1072 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 13665 "cg_relop.c"

static void JavaRelational_ThenOp_60__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1099 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPG);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 13674 "cg_relop.c"

static void JavaRelational_ThenOp_61__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1106 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 13683 "cg_relop.c"

static void JavaRelational_ThenOp_62__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1106 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFLT, label);
	JavaGenAdjust(info, -2);
}
#line 13692 "cg_relop.c"

static void JavaRelational_ThenOp_63__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1112 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFLT, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_LessThan__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 13712 "cg_relop.c"

static void JavaRelational_ThenOp_64__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1095 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13719 "cg_relop.c"

static void JavaRelational_ThenOp_65__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1095 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13726 "cg_relop.c"

static void JavaRelational_ThenOp_66__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1095 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13733 "cg_relop.c"

static void JavaRelational_ThenOp_67__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1095 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13740 "cg_relop.c"

static void JavaRelational_ThenOp_68__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1095 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13747 "cg_relop.c"

static void JavaRelational_ThenOp_69__(ILGenInfo * info, ILNode_Lt *node, ILMachineType commonType, ILLabel * label)
#line 1095 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13754 "cg_relop.c"

static void JavaRelational_ThenOp_70__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1133 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 13761 "cg_relop.c"

static void JavaRelational_ThenOp_71__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13769 "cg_relop.c"

static void JavaRelational_ThenOp_72__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13777 "cg_relop.c"

static void JavaRelational_ThenOp_73__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13785 "cg_relop.c"

static void JavaRelational_ThenOp_74__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13793 "cg_relop.c"

static void JavaRelational_ThenOp_75__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13801 "cg_relop.c"

static void JavaRelational_ThenOp_76__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13809 "cg_relop.c"

static void JavaRelational_ThenOp_77__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13817 "cg_relop.c"

static void JavaRelational_ThenOp_78__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1150 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 13826 "cg_relop.c"

static void JavaRelational_ThenOp_79__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1156 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -4);
}
#line 13835 "cg_relop.c"

static void JavaRelational_ThenOp_80__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1162 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -4);
}
#line 13844 "cg_relop.c"

static void JavaRelational_ThenOp_81__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1144 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPLE, label);
	JavaGenAdjust(info, -2);
}
#line 13852 "cg_relop.c"

static void JavaRelational_ThenOp_82__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1150 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 13861 "cg_relop.c"

static void JavaRelational_ThenOp_83__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1177 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPG);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 13870 "cg_relop.c"

static void JavaRelational_ThenOp_84__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1184 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 13879 "cg_relop.c"

static void JavaRelational_ThenOp_85__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1184 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPG);
	JavaGenJump(info, JAVA_OP_IFLE, label);
	JavaGenAdjust(info, -2);
}
#line 13888 "cg_relop.c"

static void JavaRelational_ThenOp_86__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1190 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFLE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_LessThanOrEqual__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 13908 "cg_relop.c"

static void JavaRelational_ThenOp_87__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1173 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13915 "cg_relop.c"

static void JavaRelational_ThenOp_88__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1173 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13922 "cg_relop.c"

static void JavaRelational_ThenOp_89__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1173 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13929 "cg_relop.c"

static void JavaRelational_ThenOp_90__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1173 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13936 "cg_relop.c"

static void JavaRelational_ThenOp_91__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1173 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13943 "cg_relop.c"

static void JavaRelational_ThenOp_92__(ILGenInfo * info, ILNode_Le *node, ILMachineType commonType, ILLabel * label)
#line 1173 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 13950 "cg_relop.c"

static void JavaRelational_ThenOp_93__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1211 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 13957 "cg_relop.c"

static void JavaRelational_ThenOp_94__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 13965 "cg_relop.c"

static void JavaRelational_ThenOp_95__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 13973 "cg_relop.c"

static void JavaRelational_ThenOp_96__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 13981 "cg_relop.c"

static void JavaRelational_ThenOp_97__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 13989 "cg_relop.c"

static void JavaRelational_ThenOp_98__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 13997 "cg_relop.c"

static void JavaRelational_ThenOp_99__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 14005 "cg_relop.c"

static void JavaRelational_ThenOp_100__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 14013 "cg_relop.c"

static void JavaRelational_ThenOp_101__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1228 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 14022 "cg_relop.c"

static void JavaRelational_ThenOp_102__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1234 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -4);
}
#line 14031 "cg_relop.c"

static void JavaRelational_ThenOp_103__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1240 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -4);
}
#line 14040 "cg_relop.c"

static void JavaRelational_ThenOp_104__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1222 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGT, label);
	JavaGenAdjust(info, -2);
}
#line 14048 "cg_relop.c"

static void JavaRelational_ThenOp_105__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1228 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 14057 "cg_relop.c"

static void JavaRelational_ThenOp_106__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1255 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 14066 "cg_relop.c"

static void JavaRelational_ThenOp_107__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1262 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 14075 "cg_relop.c"

static void JavaRelational_ThenOp_108__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1262 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFGT, label);
	JavaGenAdjust(info, -2);
}
#line 14084 "cg_relop.c"

static void JavaRelational_ThenOp_109__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1268 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFGT, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_GreaterThan__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 14104 "cg_relop.c"

static void JavaRelational_ThenOp_110__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1251 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14111 "cg_relop.c"

static void JavaRelational_ThenOp_111__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1251 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14118 "cg_relop.c"

static void JavaRelational_ThenOp_112__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1251 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14125 "cg_relop.c"

static void JavaRelational_ThenOp_113__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1251 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14132 "cg_relop.c"

static void JavaRelational_ThenOp_114__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1251 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14139 "cg_relop.c"

static void JavaRelational_ThenOp_115__(ILGenInfo * info, ILNode_Gt *node, ILMachineType commonType, ILLabel * label)
#line 1251 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14146 "cg_relop.c"

static void JavaRelational_ThenOp_116__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1289 "jv_relop.tc"
{
	/* Nothing to do here */
}
#line 14153 "cg_relop.c"

static void JavaRelational_ThenOp_117__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14161 "cg_relop.c"

static void JavaRelational_ThenOp_118__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14169 "cg_relop.c"

static void JavaRelational_ThenOp_119__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14177 "cg_relop.c"

static void JavaRelational_ThenOp_120__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14185 "cg_relop.c"

static void JavaRelational_ThenOp_121__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14193 "cg_relop.c"

static void JavaRelational_ThenOp_122__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14201 "cg_relop.c"

static void JavaRelational_ThenOp_123__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14209 "cg_relop.c"

static void JavaRelational_ThenOp_124__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1306 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 14218 "cg_relop.c"

static void JavaRelational_ThenOp_125__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1312 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_LCMP);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -4);
}
#line 14227 "cg_relop.c"

static void JavaRelational_ThenOp_126__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1318 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -4);
}
#line 14236 "cg_relop.c"

static void JavaRelational_ThenOp_127__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1300 "jv_relop.tc"
{
	JavaGenJump(info, JAVA_OP_IF_ICMPGE, label);
	JavaGenAdjust(info, -2);
}
#line 14244 "cg_relop.c"

static void JavaRelational_ThenOp_128__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1306 "jv_relop.tc"
{
	JavaGenCallIntrinsic(info, "iucmp", "(II)I");
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 14253 "cg_relop.c"

static void JavaRelational_ThenOp_129__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1333 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_FCMPL);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 14262 "cg_relop.c"

static void JavaRelational_ThenOp_130__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1340 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 14271 "cg_relop.c"

static void JavaRelational_ThenOp_131__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1340 "jv_relop.tc"
{
	JavaGenSimple(info, JAVA_OP_DCMPL);
	JavaGenJump(info, JAVA_OP_IFGE, label);
	JavaGenAdjust(info, -2);
}
#line 14280 "cg_relop.c"

static void JavaRelational_ThenOp_132__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1346 "jv_relop.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "compareTo",
						   "(Ljava/math/BigDecimal;)I");
		JavaGenJump(info, JAVA_OP_IFGE, label);
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_GreaterThanOrEqual__VV",
						  "(LSystem/Decimal;LSystem/Decimal;)Z");
		JavaGenJump(info, JAVA_OP_IFNE, label);
		JavaGenAdjust(info, -2);
	}
}
#line 14300 "cg_relop.c"

static void JavaRelational_ThenOp_133__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1329 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14307 "cg_relop.c"

static void JavaRelational_ThenOp_134__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1329 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14314 "cg_relop.c"

static void JavaRelational_ThenOp_135__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1329 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14321 "cg_relop.c"

static void JavaRelational_ThenOp_136__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1329 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14328 "cg_relop.c"

static void JavaRelational_ThenOp_137__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1329 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14335 "cg_relop.c"

static void JavaRelational_ThenOp_138__(ILGenInfo * info, ILNode_Ge *node, ILMachineType commonType, ILLabel * label)
#line 1329 "jv_relop.tc"
{
	/* Shouldn't happen */
}
#line 14342 "cg_relop.c"

void JavaRelational_ThenOp(ILGenInfo * info, ILNode_Relational * node__, ILMachineType commonType, ILLabel * label)
{
	switch(node__->kind__)
	{
		case ILNode_Eq_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ThenOp_1__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ThenOp_2__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ThenOp_3__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ThenOp_4__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ThenOp_5__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ThenOp_6__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ThenOp_7__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ThenOp_8__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ThenOp_9__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ThenOp_10__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ThenOp_11__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ThenOp_12__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ThenOp_13__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ThenOp_14__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ThenOp_15__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ThenOp_16__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ThenOp_17__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ThenOp_18__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ThenOp_19__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ThenOp_20__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ThenOp_21__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ThenOp_22__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ThenOp_23__(info, (ILNode_Eq *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ne_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ThenOp_24__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ThenOp_25__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ThenOp_26__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ThenOp_27__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ThenOp_28__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ThenOp_29__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ThenOp_30__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ThenOp_31__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ThenOp_32__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ThenOp_33__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ThenOp_34__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ThenOp_35__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ThenOp_36__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ThenOp_37__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ThenOp_38__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ThenOp_39__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ThenOp_40__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ThenOp_41__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ThenOp_42__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ThenOp_43__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ThenOp_44__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ThenOp_45__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ThenOp_46__(info, (ILNode_Ne *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Lt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ThenOp_47__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ThenOp_48__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ThenOp_49__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ThenOp_50__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ThenOp_51__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ThenOp_52__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ThenOp_53__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ThenOp_54__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ThenOp_55__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ThenOp_56__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ThenOp_57__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ThenOp_58__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ThenOp_59__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ThenOp_60__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ThenOp_61__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ThenOp_62__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ThenOp_63__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ThenOp_64__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ThenOp_65__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ThenOp_66__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ThenOp_67__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ThenOp_68__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ThenOp_69__(info, (ILNode_Lt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Le_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ThenOp_70__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ThenOp_71__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ThenOp_72__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ThenOp_73__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ThenOp_74__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ThenOp_75__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ThenOp_76__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ThenOp_77__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ThenOp_78__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ThenOp_79__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ThenOp_80__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ThenOp_81__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ThenOp_82__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ThenOp_83__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ThenOp_84__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ThenOp_85__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ThenOp_86__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ThenOp_87__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ThenOp_88__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ThenOp_89__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ThenOp_90__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ThenOp_91__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ThenOp_92__(info, (ILNode_Le *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Gt_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ThenOp_93__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ThenOp_94__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ThenOp_95__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ThenOp_96__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ThenOp_97__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ThenOp_98__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ThenOp_99__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ThenOp_100__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ThenOp_101__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ThenOp_102__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ThenOp_103__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ThenOp_104__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ThenOp_105__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ThenOp_106__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ThenOp_107__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ThenOp_108__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ThenOp_109__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ThenOp_110__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ThenOp_111__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ThenOp_112__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ThenOp_113__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ThenOp_114__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ThenOp_115__(info, (ILNode_Gt *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		case ILNode_Ge_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaRelational_ThenOp_116__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaRelational_ThenOp_117__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaRelational_ThenOp_118__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaRelational_ThenOp_119__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaRelational_ThenOp_120__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaRelational_ThenOp_121__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Char:
				{
					JavaRelational_ThenOp_122__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaRelational_ThenOp_123__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaRelational_ThenOp_124__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaRelational_ThenOp_125__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaRelational_ThenOp_126__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaRelational_ThenOp_127__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaRelational_ThenOp_128__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaRelational_ThenOp_129__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaRelational_ThenOp_130__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaRelational_ThenOp_131__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaRelational_ThenOp_132__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_String:
				{
					JavaRelational_ThenOp_133__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaRelational_ThenOp_134__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaRelational_ThenOp_135__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaRelational_ThenOp_136__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaRelational_ThenOp_137__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaRelational_ThenOp_138__(info, (ILNode_Ge *)node__, commonType, label);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

