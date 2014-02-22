/* cg_const.c.  Generated automatically by treecc */
#line 3 "cg_const.tc"

/*
 * cg_const.tc - Constant value nodes.
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
#line 26 "cg_const.c"

ILMachineType ILNode_Null_ILNode_GetType__(ILNode_Null *node, ILGenInfo * info)
#line 63 "cg_const.tc"
{
	return ILMachineType_ObjectRef;
}
#line 33 "cg_const.c"

ILMachineType ILNode_Null_ILNode_GenValue__(ILNode_Null *node, ILGenInfo * info)
#line 67 "cg_const.tc"
{
	ILGenSimple(info, IL_OP_LDNULL);
	ILGenAdjust(info, 1);
	return ILMachineType_ObjectRef;
}
#line 42 "cg_const.c"

void ILNode_Null_ILNode_GenThen__(ILNode_Null *node, ILGenInfo * info, ILLabel * label)
#line 55 "cg_const.tc"
{
	/* Nothing to do here */
}
#line 49 "cg_const.c"

void ILNode_Null_ILNode_GenElse__(ILNode_Null *node, ILGenInfo * info, ILLabel * label)
#line 43 "cg_const.tc"
{
	ILGenJump(info, IL_OP_BR, label);
}
#line 56 "cg_const.c"

int ILNode_Null_ILNode_EvalConst__(ILNode_Null *node, ILGenInfo * info, ILEvalValue * value)
#line 73 "cg_const.tc"
{
	value->valueType = ILMachineType_ObjectRef;
	value->un.oValue = 0;
	return 1;
}
#line 65 "cg_const.c"

ILMachineType ILNode_Null_JavaGenValue__(ILNode_Null *node, ILGenInfo * info)
#line 57 "jv_const.tc"
{
	JavaGenSimple(info, JAVA_OP_ACONST_NULL);
	JavaGenAdjust(info, 1);
	return ILMachineType_ObjectRef;
}
#line 74 "cg_const.c"

void ILNode_Null_JavaGenThen__(ILNode_Null *node, ILGenInfo * info, ILLabel * label)
#line 49 "jv_const.tc"
{
	/* Nothing to do here */
}
#line 81 "cg_const.c"

void ILNode_Null_JavaGenElse__(ILNode_Null *node, ILGenInfo * info, ILLabel * label)
#line 37 "jv_const.tc"
{
	JavaGenJump(info, JAVA_OP_GOTO, label);
}
#line 88 "cg_const.c"

struct ILNode_Null_vtable__ const ILNode_Null_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_Null_kind,
	"ILNode_Null",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Null_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Null_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Null_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Null_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Null_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Null_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Null_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Null_JavaGenElse__,
};

ILMachineType ILNode_NullPtr_ILNode_GetType__(ILNode_NullPtr *node, ILGenInfo * info)
#line 83 "cg_const.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 112 "cg_const.c"

ILMachineType ILNode_NullPtr_ILNode_GenValue__(ILNode_NullPtr *node, ILGenInfo * info)
#line 87 "cg_const.tc"
{
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenSimple(info, IL_OP_CONV_I);
	ILGenAdjust(info, 1);
	return ILMachineType_UnmanagedPtr;
}
#line 122 "cg_const.c"

void ILNode_NullPtr_ILNode_GenThen__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label)
#line 55 "cg_const.tc"
{
	/* Nothing to do here */
}
#line 129 "cg_const.c"

void ILNode_NullPtr_ILNode_GenElse__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label)
#line 43 "cg_const.tc"
{
	ILGenJump(info, IL_OP_BR, label);
}
#line 136 "cg_const.c"

int ILNode_NullPtr_ILNode_EvalConst__(ILNode_NullPtr *node, ILGenInfo * info, ILEvalValue * value)
#line 94 "cg_const.tc"
{
	value->valueType = ILMachineType_UnmanagedPtr;
	value->un.i4Value = 0;
	return 1;
}
#line 145 "cg_const.c"

ILMachineType ILNode_NullPtr_JavaGenValue__(ILNode_NullPtr *node, ILGenInfo * info)
#line 67 "jv_const.tc"
{
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenAdjust(info, 1);
	return ILMachineType_UnmanagedPtr;
}
#line 154 "cg_const.c"

void ILNode_NullPtr_JavaGenThen__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label)
#line 49 "jv_const.tc"
{
	/* Nothing to do here */
}
#line 161 "cg_const.c"

void ILNode_NullPtr_JavaGenElse__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label)
#line 37 "jv_const.tc"
{
	JavaGenJump(info, JAVA_OP_GOTO, label);
}
#line 168 "cg_const.c"

struct ILNode_NullPtr_vtable__ const ILNode_NullPtr_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_NullPtr_kind,
	"ILNode_NullPtr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NullPtr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NullPtr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NullPtr_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NullPtr_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_NullPtr_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NullPtr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NullPtr_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_NullPtr_JavaGenElse__,
};

ILMachineType ILNode_True_ILNode_GetType__(ILNode_True *node, ILGenInfo * info)
#line 104 "cg_const.tc"
{
	return ILMachineType_Boolean;
}
#line 192 "cg_const.c"

ILMachineType ILNode_True_ILNode_GenValue__(ILNode_True *node, ILGenInfo * info)
#line 108 "cg_const.tc"
{
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 201 "cg_const.c"

void ILNode_True_ILNode_GenThen__(ILNode_True *node, ILGenInfo * info, ILLabel * label)
#line 43 "cg_const.tc"
{
	ILGenJump(info, IL_OP_BR, label);
}
#line 208 "cg_const.c"

void ILNode_True_ILNode_GenElse__(ILNode_True *node, ILGenInfo * info, ILLabel * label)
#line 55 "cg_const.tc"
{
	/* Nothing to do here */
}
#line 215 "cg_const.c"

int ILNode_True_ILNode_EvalConst__(ILNode_True *node, ILGenInfo * info, ILEvalValue * value)
#line 114 "cg_const.tc"
{
	value->valueType = ILMachineType_Boolean;
	value->un.i4Value = 1;
	return 1;
}
#line 224 "cg_const.c"

ILMachineType ILNode_True_JavaGenValue__(ILNode_True *node, ILGenInfo * info)
#line 77 "jv_const.tc"
{
	JavaGenSimple(info, JAVA_OP_ICONST_1);
	JavaGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 233 "cg_const.c"

void ILNode_True_JavaGenThen__(ILNode_True *node, ILGenInfo * info, ILLabel * label)
#line 37 "jv_const.tc"
{
	JavaGenJump(info, JAVA_OP_GOTO, label);
}
#line 240 "cg_const.c"

void ILNode_True_JavaGenElse__(ILNode_True *node, ILGenInfo * info, ILLabel * label)
#line 49 "jv_const.tc"
{
	/* Nothing to do here */
}
#line 247 "cg_const.c"

struct ILNode_True_vtable__ const ILNode_True_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_True_kind,
	"ILNode_True",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_True_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_True_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_True_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_True_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_True_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_True_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_True_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_True_JavaGenElse__,
};

ILMachineType ILNode_False_ILNode_GetType__(ILNode_False *node, ILGenInfo * info)
#line 124 "cg_const.tc"
{
	return ILMachineType_Boolean;
}
#line 271 "cg_const.c"

ILMachineType ILNode_False_ILNode_GenValue__(ILNode_False *node, ILGenInfo * info)
#line 128 "cg_const.tc"
{
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 280 "cg_const.c"

void ILNode_False_ILNode_GenThen__(ILNode_False *node, ILGenInfo * info, ILLabel * label)
#line 55 "cg_const.tc"
{
	/* Nothing to do here */
}
#line 287 "cg_const.c"

void ILNode_False_ILNode_GenElse__(ILNode_False *node, ILGenInfo * info, ILLabel * label)
#line 43 "cg_const.tc"
{
	ILGenJump(info, IL_OP_BR, label);
}
#line 294 "cg_const.c"

int ILNode_False_ILNode_EvalConst__(ILNode_False *node, ILGenInfo * info, ILEvalValue * value)
#line 134 "cg_const.tc"
{
	value->valueType = ILMachineType_Boolean;
	value->un.i4Value = 0;
	return 1;
}
#line 303 "cg_const.c"

ILMachineType ILNode_False_JavaGenValue__(ILNode_False *node, ILGenInfo * info)
#line 87 "jv_const.tc"
{
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenAdjust(info, 1);
	return ILMachineType_Boolean;
}
#line 312 "cg_const.c"

void ILNode_False_JavaGenThen__(ILNode_False *node, ILGenInfo * info, ILLabel * label)
#line 49 "jv_const.tc"
{
	/* Nothing to do here */
}
#line 319 "cg_const.c"

void ILNode_False_JavaGenElse__(ILNode_False *node, ILGenInfo * info, ILLabel * label)
#line 37 "jv_const.tc"
{
	JavaGenJump(info, JAVA_OP_GOTO, label);
}
#line 326 "cg_const.c"

struct ILNode_False_vtable__ const ILNode_False_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_False_kind,
	"ILNode_False",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_False_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_False_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_False_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_False_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_False_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_False_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_False_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_False_JavaGenElse__,
};

void ILNode_Integer_ILNode_GenThen__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label)
#line 334 "cg_const.tc"
{
	if(node->value != 0)
	{
		ILGenJump(info, IL_OP_BR, label);
	}
}
#line 353 "cg_const.c"

void ILNode_Integer_ILNode_GenElse__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label)
#line 341 "cg_const.tc"
{
	if(node->value == 0)
	{
		ILGenJump(info, IL_OP_BR, label);
	}
}
#line 363 "cg_const.c"

void ILNode_Integer_JavaGenThen__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label)
#line 232 "jv_const.tc"
{
	if(node->value != 0)
	{
		JavaGenJump(info, JAVA_OP_GOTO, label);
	}
}
#line 373 "cg_const.c"

void ILNode_Integer_JavaGenElse__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label)
#line 239 "jv_const.tc"
{
	if(node->value == 0)
	{
		JavaGenJump(info, JAVA_OP_GOTO, label);
	}
}
#line 383 "cg_const.c"

struct ILNode_Integer_vtable__ const ILNode_Integer_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_Integer_kind,
	"ILNode_Integer",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

void ILNode_Real_ILNode_GenThen__(ILNode_Real *node, ILGenInfo * info, ILLabel * label)
#line 517 "cg_const.tc"
{
	if(node->value != (ILDouble)0.0)
	{
		ILGenJump(info, IL_OP_BR, label);
	}
}
#line 410 "cg_const.c"

void ILNode_Real_ILNode_GenElse__(ILNode_Real *node, ILGenInfo * info, ILLabel * label)
#line 524 "cg_const.tc"
{
	if(node->value == (ILDouble)0.0)
	{
		ILGenJump(info, IL_OP_BR, label);
	}
}
#line 420 "cg_const.c"

void ILNode_Real_JavaGenThen__(ILNode_Real *node, ILGenInfo * info, ILLabel * label)
#line 272 "jv_const.tc"
{
	if(node->value != (ILDouble)0.0)
	{
		JavaGenJump(info, JAVA_OP_GOTO, label);
	}
}
#line 430 "cg_const.c"

void ILNode_Real_JavaGenElse__(ILNode_Real *node, ILGenInfo * info, ILLabel * label)
#line 279 "jv_const.tc"
{
	if(node->value == (ILDouble)0.0)
	{
		JavaGenJump(info, JAVA_OP_GOTO, label);
	}
}
#line 440 "cg_const.c"

struct ILNode_Real_vtable__ const ILNode_Real_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_Real_kind,
	"ILNode_Real",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenElse__,
};

ILMachineType ILNode_Decimal_ILNode_GetType__(ILNode_Decimal *node, ILGenInfo * info)
#line 557 "cg_const.tc"
{
	return ILMachineType_Decimal;
}
#line 464 "cg_const.c"

ILMachineType ILNode_Decimal_ILNode_GenValue__(ILNode_Decimal *node, ILGenInfo * info)
#line 561 "cg_const.tc"
{
	ILInt64 intValue;
	if(ILDecimalToInt64(&(node->value), &intValue))
	{
		/* We can up-convert an integer to get a decimal value */
		if(intValue >= (ILInt64)IL_MIN_INT32 &&
		   intValue <= (ILInt64)IL_MAX_INT32)
		{
			ILGenInt32(info, (ILInt32)intValue);
			ILGenAdjust(info, 1);
			ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Implicit"
											"(int32)");
		}
		else if(!(info->clsCompliant) && intValue >= 0 &&
				intValue <= (ILInt64)(ILUInt64)IL_MAX_UINT32)
		{
			/* Cannot use this if CLS compliance is enabled */
			ILGenUInt32(info, (ILUInt32)intValue);
			ILGenAdjust(info, 1);
			ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit"
											"(unsigned int32)");
		}
		else
		{
			ILGenInt64(info, intValue);
			ILGenAdjust(info, 1);
			ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit"
											"(int64)");
		}
	}
	else
	{
		/* We need to call the "Decimal" constructor to get the value */
		ILGenUInt32(info, node->value.low);
		ILGenUInt32(info, node->value.middle);
		ILGenUInt32(info, node->value.high);
		ILGenUInt32(info,
				((node->value.flags & (ILUInt32)0x80000000) != 0 ? 1 : 0));
		ILGenUInt32(info, ((node->value.flags >> 16) & 0xFF));
		ILGenAdjust(info, 5);
		ILGenNewObj(info, "[.library]System.Decimal",
		            "(int32, int32, int32, bool, unsigned int8)");
		ILGenAdjust(info, -4);
	}
	return ILMachineType_Decimal;
}
#line 517 "cg_const.c"

void ILNode_Decimal_ILNode_GenThen__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label)
#line 611 "cg_const.tc"
{
	if(!ILDecimalIsZero(&(node->value)))
	{
		ILGenJump(info, IL_OP_BR, label);
	}
}
#line 527 "cg_const.c"

void ILNode_Decimal_ILNode_GenElse__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label)
#line 618 "cg_const.tc"
{
	if(ILDecimalIsZero(&(node->value)))
	{
		ILGenJump(info, IL_OP_BR, label);
	}
}
#line 537 "cg_const.c"

int ILNode_Decimal_ILNode_EvalConst__(ILNode_Decimal *node, ILGenInfo * info, ILEvalValue * value)
#line 625 "cg_const.tc"
{
	value->valueType = ILMachineType_Decimal;
	value->un.decValue = node->value;
	return 1;
}
#line 546 "cg_const.c"

ILMachineType ILNode_Decimal_JavaGenValue__(ILNode_Decimal *node, ILGenInfo * info)
#line 290 "jv_const.tc"
{
	ILInt64 intValue;
	if(info->useJavaLib)
	{
		if(ILDecimalToInt64(&(node->value), &intValue))
		{
			/* We can up-convert a "long" to get a BigDecimal object */
			JavaGenInt64(info, intValue);
			JavaGenAdjust(info, 2);
			JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
							  "(J)Ljava/math/BigDecimal;");
			JavaGenAdjust(info, -1);
		}
		else
		{
			/* We must up-convert from the string form of the value */
			char buffer[64];
			JavaGenNewObj(info, "java/math/BigDecimal");
			JavaGenSimple(info, JAVA_OP_DUP);
			JavaGenAdjust(info, 2);
			ILDecimalFormat(buffer, &(node->value), 0);
			JavaGenStringConst(info, buffer, strlen(buffer));
			JavaGenAdjust(info, 1);
			JavaGenCallCtor(info, "java/math/BigDecimal", "<init>",
						    "(Ljava/lang/String;)V");
			JavaGenAdjust(info, -2);
		}
	}
	else if(ILDecimalToInt64(&(node->value), &intValue))
	{
		/* We can up-convert an integer to get a decimal value */
		if(intValue >= (ILInt64)IL_MIN_INT32 &&
		   intValue <= (ILInt64)IL_MAX_INT32)
		{
			JavaGenInt32(info, (ILInt32)intValue);
			JavaGenAdjust(info, 1);
			JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
							  "(I)LSystem/Decimal;");
		}
		else if(!(info->clsCompliant) && intValue >= 0 &&
				intValue <= (ILInt64)(ILUInt64)IL_MAX_UINT32)
		{
			/* Cannot use this if CLS compliance is enabled */
			JavaGenUInt32(info, (ILUInt32)intValue);
			JavaGenAdjust(info, 1);
			JavaGenCallByName(info, "System/Decimal", "op_Implicit__IV",
							  "(I)LSystem/Decimal;");
		}
		else
		{
			JavaGenInt64(info, intValue);
			JavaGenAdjust(info, 2);
			JavaGenCallByName(info, "System/Decimal", "op_Implicit__lV",
							  "(J)LSystem/Decimal;");
			JavaGenAdjust(info, -1);
		}
	}
	else
	{
		/* We need to call the "Decimal" constructor to get the value */
		JavaGenNewObj(info, "System/Decimal");
		JavaGenSimple(info, JAVA_OP_DUP);
		JavaGenAdjust(info, 2);
		JavaGenUInt32(info, node->value.low);
		JavaGenUInt32(info, node->value.middle);
		JavaGenUInt32(info, node->value.high);
		JavaGenUInt32(info,
				((node->value.flags & (ILUInt32)0x80000000) != 0 ? 1 : 0));
		JavaGenUInt32(info, ((node->value.flags >> 16) & 0xFF));
		JavaGenAdjust(info, 5);
		JavaGenCallCtor(info, "System/Decimal", "<init>__iiiB", "(IIIZI)");
		JavaGenAdjust(info, -6);
	}
	return ILMachineType_Decimal;
}
#line 625 "cg_const.c"

void ILNode_Decimal_JavaGenThen__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label)
#line 366 "jv_const.tc"
{
	if(!ILDecimalIsZero(&(node->value)))
	{
		JavaGenJump(info, JAVA_OP_GOTO, label);
	}
}
#line 635 "cg_const.c"

void ILNode_Decimal_JavaGenElse__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label)
#line 373 "jv_const.tc"
{
	if(ILDecimalIsZero(&(node->value)))
	{
		JavaGenJump(info, JAVA_OP_GOTO, label);
	}
}
#line 645 "cg_const.c"

struct ILNode_Decimal_vtable__ const ILNode_Decimal_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_Decimal_kind,
	"ILNode_Decimal",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Decimal_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Decimal_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Decimal_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Decimal_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Decimal_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Decimal_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Decimal_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Decimal_JavaGenElse__,
};

ILMachineType ILNode_String_ILNode_GetType__(ILNode_String *node, ILGenInfo * info)
#line 635 "cg_const.tc"
{
	return ILMachineType_String;
}
#line 669 "cg_const.c"

ILMachineType ILNode_String_ILNode_GenValue__(ILNode_String *node, ILGenInfo * info)
#line 639 "cg_const.tc"
{
	ILGenLoadString(info, node->str, node->len);
	ILGenAdjust(info, 1);
	return ILMachineType_String;
}
#line 678 "cg_const.c"

void ILNode_String_ILNode_GenThen__(ILNode_String *node, ILGenInfo * info, ILLabel * label)
#line 43 "cg_const.tc"
{
	ILGenJump(info, IL_OP_BR, label);
}
#line 685 "cg_const.c"

void ILNode_String_ILNode_GenElse__(ILNode_String *node, ILGenInfo * info, ILLabel * label)
#line 55 "cg_const.tc"
{
	/* Nothing to do here */
}
#line 692 "cg_const.c"

int ILNode_String_ILNode_EvalConst__(ILNode_String *node, ILGenInfo * info, ILEvalValue * value)
#line 645 "cg_const.tc"
{
	value->valueType = ILMachineType_String;
	value->un.strValue.str = node->str;
	value->un.strValue.len = node->len;
	return 1;
}
#line 702 "cg_const.c"

ILMachineType ILNode_String_JavaGenValue__(ILNode_String *node, ILGenInfo * info)
#line 384 "jv_const.tc"
{
	JavaGenStringConst(info, node->str, node->len);
	if(!(info->useJavaLib))
	{
		JavaGenCallByName(info, "System/String", "__FromJavaString",
						  "(Ljava/lang/String;)LSystem/String;");
	}
	JavaGenAdjust(info, 1);
	return ILMachineType_String;
}
#line 716 "cg_const.c"

void ILNode_String_JavaGenThen__(ILNode_String *node, ILGenInfo * info, ILLabel * label)
#line 37 "jv_const.tc"
{
	JavaGenJump(info, JAVA_OP_GOTO, label);
}
#line 723 "cg_const.c"

void ILNode_String_JavaGenElse__(ILNode_String *node, ILGenInfo * info, ILLabel * label)
#line 49 "jv_const.tc"
{
	/* Nothing to do here */
}
#line 730 "cg_const.c"

struct ILNode_String_vtable__ const ILNode_String_vt__ = {
	&ILNode_Constant_vt__,
	ILNode_String_kind,
	"ILNode_String",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_String_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_String_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_String_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_String_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_JavaGenElse__,
};

ILMachineType ILNode_Int8_ILNode_GetType__(ILNode_Int8 *node, ILGenInfo * info)
#line 143 "cg_const.tc"
{ return ILMachineType_Int8; }
#line 752 "cg_const.c"

ILMachineType ILNode_Int8_ILNode_GenValue__(ILNode_Int8 *node, ILGenInfo * info)
#line 199 "cg_const.tc"
{
	if(node->isneg)
	{
		ILGenInt32(info, (ILInt32)(-((ILInt64)(node->value))));
	}
	else
	{
		ILGenInt32(info, (ILInt32)(node->value));
	}
	ILGenAdjust(info, 1);
	return ILMachineType_Int8;
}
#line 768 "cg_const.c"

int ILNode_Int8_ILNode_EvalConst__(ILNode_Int8 *node, ILGenInfo * info, ILEvalValue * value)
#line 352 "cg_const.tc"
{
	value->valueType = ILMachineType_Int8;
	if(node->isneg)
	{
		value->un.i4Value = (ILInt32)(-((ILInt64)(node->value)));
	}
	else
	{
		value->un.i4Value = (ILInt32)(node->value);
	}
	return 1;
}
#line 784 "cg_const.c"

ILMachineType ILNode_Int8_JavaGenValue__(ILNode_Int8 *node, ILGenInfo * info)
#line 97 "jv_const.tc"
{
	if(node->isneg)
	{
		JavaGenInt32(info, (ILInt32)(-((ILInt64)(node->value))));
	}
	else
	{
		JavaGenInt32(info, (ILInt32)(node->value));
	}
	JavaGenAdjust(info, 1);
	return ILMachineType_Int8;
}
#line 800 "cg_const.c"

struct ILNode_Int8_vtable__ const ILNode_Int8_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_Int8_kind,
	"ILNode_Int8",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int8_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int8_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Int8_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int8_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_UInt8_ILNode_GetType__(ILNode_UInt8 *node, ILGenInfo * info)
#line 144 "cg_const.tc"
{ return ILMachineType_UInt8; }
#line 822 "cg_const.c"

ILMachineType ILNode_UInt8_ILNode_GenValue__(ILNode_UInt8 *node, ILGenInfo * info)
#line 212 "cg_const.tc"
{
	ILGenUInt32(info, (ILUInt32)(node->value));
	ILGenAdjust(info, 1);
	return ILMachineType_UInt8;
}
#line 831 "cg_const.c"

int ILNode_UInt8_ILNode_EvalConst__(ILNode_UInt8 *node, ILGenInfo * info, ILEvalValue * value)
#line 365 "cg_const.tc"
{
	value->valueType = ILMachineType_UInt8;
	value->un.i4Value = (ILInt32)(node->value);
	return 1;
}
#line 840 "cg_const.c"

ILMachineType ILNode_UInt8_JavaGenValue__(ILNode_UInt8 *node, ILGenInfo * info)
#line 110 "jv_const.tc"
{
	JavaGenUInt32(info, (ILUInt32)(node->value));
	JavaGenAdjust(info, 1);
	return ILMachineType_UInt8;
}
#line 849 "cg_const.c"

struct ILNode_UInt8_vtable__ const ILNode_UInt8_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_UInt8_kind,
	"ILNode_UInt8",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt8_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt8_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_UInt8_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt8_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_Int16_ILNode_GetType__(ILNode_Int16 *node, ILGenInfo * info)
#line 145 "cg_const.tc"
{ return ILMachineType_Int16; }
#line 871 "cg_const.c"

ILMachineType ILNode_Int16_ILNode_GenValue__(ILNode_Int16 *node, ILGenInfo * info)
#line 218 "cg_const.tc"
{
	if(node->isneg)
	{
		ILGenInt32(info, (ILInt32)(-((ILInt64)(node->value))));
	}
	else
	{
		ILGenInt32(info, (ILInt32)(node->value));
	}
	ILGenAdjust(info, 1);
	return ILMachineType_Int16;
}
#line 887 "cg_const.c"

int ILNode_Int16_ILNode_EvalConst__(ILNode_Int16 *node, ILGenInfo * info, ILEvalValue * value)
#line 371 "cg_const.tc"
{
	value->valueType = ILMachineType_Int16;
	if(node->isneg)
	{
		value->un.i4Value = (ILInt32)(-((ILInt64)(node->value)));
	}
	else
	{
		value->un.i4Value = (ILInt32)(node->value);
	}
	return 1;
}
#line 903 "cg_const.c"

ILMachineType ILNode_Int16_JavaGenValue__(ILNode_Int16 *node, ILGenInfo * info)
#line 116 "jv_const.tc"
{
	if(node->isneg)
	{
		JavaGenInt32(info, (ILInt32)(-((ILInt64)(node->value))));
	}
	else
	{
		JavaGenInt32(info, (ILInt32)(node->value));
	}
	JavaGenAdjust(info, 1);
	return ILMachineType_Int16;
}
#line 919 "cg_const.c"

struct ILNode_Int16_vtable__ const ILNode_Int16_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_Int16_kind,
	"ILNode_Int16",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int16_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int16_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Int16_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int16_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_UInt16_ILNode_GetType__(ILNode_UInt16 *node, ILGenInfo * info)
#line 146 "cg_const.tc"
{ return ILMachineType_UInt16; }
#line 941 "cg_const.c"

ILMachineType ILNode_UInt16_ILNode_GenValue__(ILNode_UInt16 *node, ILGenInfo * info)
#line 232 "cg_const.tc"
{
	ILGenUInt32(info, (ILUInt32)(node->value));
	ILGenAdjust(info, 1);
	return ILMachineType_UInt16;
}
#line 950 "cg_const.c"

int ILNode_UInt16_ILNode_EvalConst__(ILNode_UInt16 *node, ILGenInfo * info, ILEvalValue * value)
#line 384 "cg_const.tc"
{
	value->valueType = ILMachineType_UInt16;
	value->un.i4Value = (ILInt32)(node->value);
	return 1;
}
#line 959 "cg_const.c"

ILMachineType ILNode_UInt16_JavaGenValue__(ILNode_UInt16 *node, ILGenInfo * info)
#line 130 "jv_const.tc"
{
	JavaGenUInt32(info, (ILUInt32)(node->value));
	JavaGenAdjust(info, 1);
	return ILMachineType_UInt16;
}
#line 968 "cg_const.c"

struct ILNode_UInt16_vtable__ const ILNode_UInt16_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_UInt16_kind,
	"ILNode_UInt16",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt16_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt16_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_UInt16_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt16_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_Char_ILNode_GetType__(ILNode_Char *node, ILGenInfo * info)
#line 147 "cg_const.tc"
{ return ILMachineType_Char; }
#line 990 "cg_const.c"

ILMachineType ILNode_Char_ILNode_GenValue__(ILNode_Char *node, ILGenInfo * info)
#line 232 "cg_const.tc"
{
	ILGenUInt32(info, (ILUInt32)(node->value));
	ILGenAdjust(info, 1);
	return ILMachineType_UInt16;
}
#line 999 "cg_const.c"

int ILNode_Char_ILNode_EvalConst__(ILNode_Char *node, ILGenInfo * info, ILEvalValue * value)
#line 390 "cg_const.tc"
{
	value->valueType = ILMachineType_Char;
	value->un.i4Value = (ILInt32)(node->value);
	return 1;
}
#line 1008 "cg_const.c"

ILMachineType ILNode_Char_JavaGenValue__(ILNode_Char *node, ILGenInfo * info)
#line 130 "jv_const.tc"
{
	JavaGenUInt32(info, (ILUInt32)(node->value));
	JavaGenAdjust(info, 1);
	return ILMachineType_UInt16;
}
#line 1017 "cg_const.c"

struct ILNode_Char_vtable__ const ILNode_Char_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_Char_kind,
	"ILNode_Char",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Char_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Char_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Char_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Char_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_Int32_ILNode_GetType__(ILNode_Int32 *node, ILGenInfo * info)
#line 148 "cg_const.tc"
{ return ILMachineType_Int32; }
#line 1039 "cg_const.c"

ILMachineType ILNode_Int32_ILNode_GenValue__(ILNode_Int32 *node, ILGenInfo * info)
#line 238 "cg_const.tc"
{
	if(node->isneg)
	{
		ILGenInt32(info, (ILInt32)(-((ILInt64)(node->value))));
	}
	else
	{
		ILGenInt32(info, (ILInt32)(node->value));
	}
	ILGenAdjust(info, 1);
	return ILMachineType_Int32;
}
#line 1055 "cg_const.c"

int ILNode_Int32_ILNode_EvalConst__(ILNode_Int32 *node, ILGenInfo * info, ILEvalValue * value)
#line 396 "cg_const.tc"
{
	value->valueType = ILMachineType_Int32;
	if(node->isneg)
	{
		value->un.i4Value = (ILInt32)(-((ILInt64)(node->value)));
	}
	else
	{
		value->un.i4Value = (ILInt32)(node->value);
	}
	return 1;
}
#line 1071 "cg_const.c"

ILMachineType ILNode_Int32_JavaGenValue__(ILNode_Int32 *node, ILGenInfo * info)
#line 136 "jv_const.tc"
{
	if(node->isneg)
	{
		JavaGenInt32(info, (ILInt32)(-((ILInt64)(node->value))));
	}
	else
	{
		JavaGenInt32(info, (ILInt32)(node->value));
	}
	JavaGenAdjust(info, 1);
	return ILMachineType_Int32;
}
#line 1087 "cg_const.c"

struct ILNode_Int32_vtable__ const ILNode_Int32_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_Int32_kind,
	"ILNode_Int32",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int32_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int32_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Int32_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int32_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_UInt32_ILNode_GetType__(ILNode_UInt32 *node, ILGenInfo * info)
#line 149 "cg_const.tc"
{ return ILMachineType_UInt32; }
#line 1109 "cg_const.c"

ILMachineType ILNode_UInt32_ILNode_GenValue__(ILNode_UInt32 *node, ILGenInfo * info)
#line 251 "cg_const.tc"
{
	ILGenUInt32(info, (ILUInt32)(node->value));
	ILGenAdjust(info, 1);
	return ILMachineType_UInt32;
}
#line 1118 "cg_const.c"

int ILNode_UInt32_ILNode_EvalConst__(ILNode_UInt32 *node, ILGenInfo * info, ILEvalValue * value)
#line 409 "cg_const.tc"
{
	value->valueType = ILMachineType_UInt32;
	value->un.i4Value = (ILInt32)(ILUInt32)(node->value);
	return 1;
}
#line 1127 "cg_const.c"

ILMachineType ILNode_UInt32_JavaGenValue__(ILNode_UInt32 *node, ILGenInfo * info)
#line 149 "jv_const.tc"
{
	JavaGenUInt32(info, (ILUInt32)(node->value));
	JavaGenAdjust(info, 1);
	return ILMachineType_UInt32;
}
#line 1136 "cg_const.c"

struct ILNode_UInt32_vtable__ const ILNode_UInt32_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_UInt32_kind,
	"ILNode_UInt32",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt32_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt32_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_UInt32_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt32_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_Int64_ILNode_GetType__(ILNode_Int64 *node, ILGenInfo * info)
#line 150 "cg_const.tc"
{ return ILMachineType_Int64; }
#line 1158 "cg_const.c"

ILMachineType ILNode_Int64_ILNode_GenValue__(ILNode_Int64 *node, ILGenInfo * info)
#line 257 "cg_const.tc"
{
	if(node->isneg)
	{
		ILGenInt64(info, -((ILInt64)(node->value)));
	}
	else
	{
		ILGenInt64(info, (ILInt64)(node->value));
	}
	ILGenAdjust(info, 1);
	return ILMachineType_Int64;
}
#line 1174 "cg_const.c"

int ILNode_Int64_ILNode_EvalConst__(ILNode_Int64 *node, ILGenInfo * info, ILEvalValue * value)
#line 415 "cg_const.tc"
{
	value->valueType = ILMachineType_Int64;
	if(node->isneg)
	{
		value->un.i8Value = -((ILInt64)(node->value));
	}
	else
	{
		value->un.i8Value = (ILInt64)(node->value);
	}
	return 1;
}
#line 1190 "cg_const.c"

ILMachineType ILNode_Int64_JavaGenValue__(ILNode_Int64 *node, ILGenInfo * info)
#line 155 "jv_const.tc"
{
	if(node->isneg)
	{
		JavaGenInt64(info, -((ILInt64)(node->value)));
	}
	else
	{
		JavaGenInt64(info, (ILInt64)(node->value));
	}
	JavaGenAdjust(info, 2);
	return ILMachineType_Int64;
}
#line 1206 "cg_const.c"

struct ILNode_Int64_vtable__ const ILNode_Int64_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_Int64_kind,
	"ILNode_Int64",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int64_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int64_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Int64_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int64_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_UInt64_ILNode_GetType__(ILNode_UInt64 *node, ILGenInfo * info)
#line 151 "cg_const.tc"
{ return ILMachineType_UInt64; }
#line 1228 "cg_const.c"

ILMachineType ILNode_UInt64_ILNode_GenValue__(ILNode_UInt64 *node, ILGenInfo * info)
#line 270 "cg_const.tc"
{
	ILGenUInt64(info, node->value);
	ILGenAdjust(info, 1);
	return ILMachineType_UInt64;
}
#line 1237 "cg_const.c"

int ILNode_UInt64_ILNode_EvalConst__(ILNode_UInt64 *node, ILGenInfo * info, ILEvalValue * value)
#line 428 "cg_const.tc"
{
	value->valueType = ILMachineType_UInt64;
	value->un.i8Value = node->value;
	return 1;
}
#line 1246 "cg_const.c"

ILMachineType ILNode_UInt64_JavaGenValue__(ILNode_UInt64 *node, ILGenInfo * info)
#line 168 "jv_const.tc"
{
	JavaGenUInt64(info, node->value);
	JavaGenAdjust(info, 2);
	return ILMachineType_UInt64;
}
#line 1255 "cg_const.c"

struct ILNode_UInt64_vtable__ const ILNode_UInt64_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_UInt64_kind,
	"ILNode_UInt64",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt64_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt64_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_UInt64_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt64_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_Int_ILNode_GetType__(ILNode_Int *node, ILGenInfo * info)
#line 153 "cg_const.tc"
{
	if(node->isneg)
	{
		if(node->value <= (((ILUInt64)(ILUInt32)IL_MAX_INT32) + 1))
		{
			return ILMachineType_NativeInt;
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			return ILMachineType_Int64;
		}
	}
	else
	{
		if(node->value <= (ILUInt64)(ILUInt32)IL_MAX_INT32)
		{
			return ILMachineType_NativeInt;
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			return ILMachineType_Int64;
		}
	}
}
#line 1304 "cg_const.c"

ILMachineType ILNode_Int_ILNode_GenValue__(ILNode_Int *node, ILGenInfo * info)
#line 276 "cg_const.tc"
{
	if(node->isneg)
	{
		if(node->value <= (((ILUInt64)(ILUInt32)IL_MAX_INT32) + 1))
		{
			ILGenIntNative(info, (ILInt32)(-((ILInt64)(node->value))));
			ILGenAdjust(info, 1);
			return ILMachineType_NativeInt;
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			ILGenInt64(info, -((ILInt64)(node->value)));
			ILGenAdjust(info, 1);
			return ILMachineType_Int64;
		}
	}
	else
	{
		if(node->value <= (ILUInt64)(ILUInt32)IL_MAX_INT32)
		{
			ILGenIntNative(info, (ILInt32)(node->value));
			ILGenAdjust(info, 1);
			return ILMachineType_NativeInt;
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			ILGenInt64(info, (ILInt64)(node->value));
			ILGenAdjust(info, 1);
			return ILMachineType_Int64;
		}
	}
}
#line 1344 "cg_const.c"

int ILNode_Int_ILNode_EvalConst__(ILNode_Int *node, ILGenInfo * info, ILEvalValue * value)
#line 434 "cg_const.tc"
{
	if(node->isneg)
	{
		if(node->value <= (((ILUInt64)(ILUInt32)IL_MAX_INT32) + 1))
		{
			value->valueType = ILMachineType_NativeInt;
			value->un.i4Value = -((ILInt64)(node->value));
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			value->valueType = ILMachineType_Int64;
			value->un.i8Value = -((ILInt64)(node->value));
		}
	}
	else
	{
		if(node->value <= (ILUInt64)(ILUInt32)IL_MAX_INT32)
		{
			value->valueType = ILMachineType_NativeInt;
			value->un.i4Value = (ILInt32)(node->value);
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			value->valueType = ILMachineType_Int64;
			value->un.i8Value = (ILInt64)(node->value);
		}
	}
	return 1;
}
#line 1381 "cg_const.c"

ILMachineType ILNode_Int_JavaGenValue__(ILNode_Int *node, ILGenInfo * info)
#line 174 "jv_const.tc"
{
	if(node->isneg)
	{
		if(node->value <= (((ILUInt64)(ILUInt32)IL_MAX_INT32) + 1))
		{
			JavaGenInt32(info, (ILInt32)(-((ILInt64)(node->value))));
			JavaGenAdjust(info, 1);
			return ILMachineType_NativeInt;
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			JavaGenInt64(info, -((ILInt64)(node->value)));
			JavaGenAdjust(info, 2);
			return ILMachineType_Int64;
		}
	}
	else
	{
		if(node->value <= (ILUInt64)(ILUInt32)IL_MAX_INT32)
		{
			JavaGenInt32(info, (ILInt32)(node->value));
			JavaGenAdjust(info, 1);
			return ILMachineType_NativeInt;
		}
		else
		{
			/* The value is too big for systems with 32-bit native
			   integers, so convert into a 64-bit integer instead */
			JavaGenInt64(info, (ILInt64)(node->value));
			JavaGenAdjust(info, 2);
			return ILMachineType_Int64;
		}
	}
}
#line 1421 "cg_const.c"

struct ILNode_Int_vtable__ const ILNode_Int_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_Int_kind,
	"ILNode_Int",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Int_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Int_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_UInt_ILNode_GetType__(ILNode_UInt *node, ILGenInfo * info)
#line 182 "cg_const.tc"
{
	if(node->value <= (ILUInt64)IL_MAX_UINT32)
	{
		return ILMachineType_NativeUInt;
	}
	else
	{
		/* The value is too big for systems with 32-bit native
		   integers, so convert into a 64-bit integer instead */
		return ILMachineType_UInt64;
	}
}
#line 1454 "cg_const.c"

ILMachineType ILNode_UInt_ILNode_GenValue__(ILNode_UInt *node, ILGenInfo * info)
#line 313 "cg_const.tc"
{
	if(node->value <= (ILUInt64)IL_MAX_UINT32)
	{
		ILGenUIntNative(info, (ILUInt32)(node->value));
		ILGenAdjust(info, 1);
		return ILMachineType_NativeUInt;
	}
	else
	{
		/* The value is too big for systems with 32-bit native
		   integers, so convert into a 64-bit integer instead */
		ILGenUInt64(info, node->value);
		ILGenAdjust(info, 1);
		return ILMachineType_UInt64;
	}
}
#line 1474 "cg_const.c"

int ILNode_UInt_ILNode_EvalConst__(ILNode_UInt *node, ILGenInfo * info, ILEvalValue * value)
#line 468 "cg_const.tc"
{
	if(node->value <= (ILUInt64)IL_MAX_UINT32)
	{
		value->valueType = ILMachineType_NativeUInt;
		value->un.i4Value = (ILInt32)(ILUInt32)(node->value);
	}
	else
	{
		/* The value is too big for systems with 32-bit native
		   integers, so convert into a 64-bit integer instead */
		value->valueType = ILMachineType_UInt64;
		value->un.i8Value = (ILInt64)(node->value);
	}
	return 1;
}
#line 1493 "cg_const.c"

ILMachineType ILNode_UInt_JavaGenValue__(ILNode_UInt *node, ILGenInfo * info)
#line 211 "jv_const.tc"
{
	if(node->value <= (ILUInt64)IL_MAX_UINT32)
	{
		JavaGenUInt32(info, (ILUInt32)(node->value));
		JavaGenAdjust(info, 1);
		return ILMachineType_NativeUInt;
	}
	else
	{
		/* The value is too big for systems with 32-bit native
		   integers, so convert into a 64-bit integer instead */
		JavaGenUInt64(info, node->value);
		JavaGenAdjust(info, 2);
		return ILMachineType_UInt64;
	}
}
#line 1513 "cg_const.c"

struct ILNode_UInt_vtable__ const ILNode_UInt_vt__ = {
	&ILNode_Integer_vt__,
	ILNode_UInt_kind,
	"ILNode_UInt",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_UInt_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_UInt_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Integer_JavaGenElse__,
};

ILMachineType ILNode_Float32_ILNode_GetType__(ILNode_Float32 *node, ILGenInfo * info)
#line 487 "cg_const.tc"
{ return ILMachineType_Float32; }
#line 1535 "cg_const.c"

ILMachineType ILNode_Float32_ILNode_GenValue__(ILNode_Float32 *node, ILGenInfo * info)
#line 495 "cg_const.tc"
{
	ILGenLoadFloat32(info, (ILFloat)(node->value));
	ILGenAdjust(info, 1);
	return ILMachineType_Float32;
}
#line 1544 "cg_const.c"

int ILNode_Float32_ILNode_EvalConst__(ILNode_Float32 *node, ILGenInfo * info, ILEvalValue * value)
#line 535 "cg_const.tc"
{
	value->valueType = ILMachineType_Float32;
	value->un.r4Value = (ILFloat)(node->value);
	return 1;
}
#line 1553 "cg_const.c"

ILMachineType ILNode_Float32_JavaGenValue__(ILNode_Float32 *node, ILGenInfo * info)
#line 250 "jv_const.tc"
{
	JavaGenFloat32(info, (ILFloat)(node->value));
	JavaGenAdjust(info, 1);
	return ILMachineType_Float32;
}
#line 1562 "cg_const.c"

struct ILNode_Float32_vtable__ const ILNode_Float32_vt__ = {
	&ILNode_Real_vt__,
	ILNode_Float32_kind,
	"ILNode_Float32",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float32_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float32_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Float32_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float32_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenElse__,
};

ILMachineType ILNode_Float64_ILNode_GetType__(ILNode_Float64 *node, ILGenInfo * info)
#line 488 "cg_const.tc"
{ return ILMachineType_Float64; }
#line 1584 "cg_const.c"

ILMachineType ILNode_Float64_ILNode_GenValue__(ILNode_Float64 *node, ILGenInfo * info)
#line 501 "cg_const.tc"
{
	ILGenLoadFloat64(info, node->value);
	ILGenAdjust(info, 1);
	return ILMachineType_Float64;
}
#line 1593 "cg_const.c"

int ILNode_Float64_ILNode_EvalConst__(ILNode_Float64 *node, ILGenInfo * info, ILEvalValue * value)
#line 541 "cg_const.tc"
{
	value->valueType = ILMachineType_Float64;
	value->un.r8Value = node->value;
	return 1;
}
#line 1602 "cg_const.c"

ILMachineType ILNode_Float64_JavaGenValue__(ILNode_Float64 *node, ILGenInfo * info)
#line 256 "jv_const.tc"
{
	JavaGenFloat64(info, node->value);
	JavaGenAdjust(info, 2);
	return ILMachineType_Float64;
}
#line 1611 "cg_const.c"

struct ILNode_Float64_vtable__ const ILNode_Float64_vt__ = {
	&ILNode_Real_vt__,
	ILNode_Float64_kind,
	"ILNode_Float64",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float64_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float64_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Float64_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float64_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenElse__,
};

ILMachineType ILNode_Float_ILNode_GetType__(ILNode_Float *node, ILGenInfo * info)
#line 489 "cg_const.tc"
{ return ILMachineType_NativeFloat; }
#line 1633 "cg_const.c"

ILMachineType ILNode_Float_ILNode_GenValue__(ILNode_Float *node, ILGenInfo * info)
#line 507 "cg_const.tc"
{
	ILGenLoadFloat64(info, node->value);
	ILGenAdjust(info, 1);
	return ILMachineType_NativeFloat;
}
#line 1642 "cg_const.c"

int ILNode_Float_ILNode_EvalConst__(ILNode_Float *node, ILGenInfo * info, ILEvalValue * value)
#line 547 "cg_const.tc"
{
	value->valueType = ILMachineType_NativeFloat;
	value->un.r8Value = node->value;
	return 1;
}
#line 1651 "cg_const.c"

ILMachineType ILNode_Float_JavaGenValue__(ILNode_Float *node, ILGenInfo * info)
#line 262 "jv_const.tc"
{
	JavaGenFloat64(info, node->value);
	JavaGenAdjust(info, 2);
	return ILMachineType_NativeFloat;
}
#line 1660 "cg_const.c"

struct ILNode_Float_vtable__ const ILNode_Float_vt__ = {
	&ILNode_Real_vt__,
	ILNode_Float_kind,
	"ILNode_Float",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Float_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Float_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Real_JavaGenElse__,
};

ILNode *ILNode_Null_create(void)
{
	ILNode_Null *node__ = (ILNode_Null *)yynodealloc(sizeof(struct ILNode_Null__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Null_vt__;
	node__->kind__ = ILNode_Null_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_NullPtr_create(void)
{
	ILNode_NullPtr *node__ = (ILNode_NullPtr *)yynodealloc(sizeof(struct ILNode_NullPtr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_NullPtr_vt__;
	node__->kind__ = ILNode_NullPtr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_True_create(void)
{
	ILNode_True *node__ = (ILNode_True *)yynodealloc(sizeof(struct ILNode_True__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_True_vt__;
	node__->kind__ = ILNode_True_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_False_create(void)
{
	ILNode_False *node__ = (ILNode_False *)yynodealloc(sizeof(struct ILNode_False__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_False_vt__;
	node__->kind__ = ILNode_False_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_Decimal_create(ILDecimal value)
{
	ILNode_Decimal *node__ = (ILNode_Decimal *)yynodealloc(sizeof(struct ILNode_Decimal__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Decimal_vt__;
	node__->kind__ = ILNode_Decimal_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	return (ILNode *)node__;
}

ILNode *ILNode_String_create(char * str, int len)
{
	ILNode_String *node__ = (ILNode_String *)yynodealloc(sizeof(struct ILNode_String__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_String_vt__;
	node__->kind__ = ILNode_String_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->str = str;
	node__->len = len;
	return (ILNode *)node__;
}

ILNode *ILNode_Int8_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_Int8 *node__ = (ILNode_Int8 *)yynodealloc(sizeof(struct ILNode_Int8__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Int8_vt__;
	node__->kind__ = ILNode_Int8_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_UInt8_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_UInt8 *node__ = (ILNode_UInt8 *)yynodealloc(sizeof(struct ILNode_UInt8__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UInt8_vt__;
	node__->kind__ = ILNode_UInt8_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_Int16_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_Int16 *node__ = (ILNode_Int16 *)yynodealloc(sizeof(struct ILNode_Int16__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Int16_vt__;
	node__->kind__ = ILNode_Int16_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_UInt16_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_UInt16 *node__ = (ILNode_UInt16 *)yynodealloc(sizeof(struct ILNode_UInt16__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UInt16_vt__;
	node__->kind__ = ILNode_UInt16_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_Char_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_Char *node__ = (ILNode_Char *)yynodealloc(sizeof(struct ILNode_Char__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Char_vt__;
	node__->kind__ = ILNode_Char_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_Int32_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_Int32 *node__ = (ILNode_Int32 *)yynodealloc(sizeof(struct ILNode_Int32__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Int32_vt__;
	node__->kind__ = ILNode_Int32_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_UInt32_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_UInt32 *node__ = (ILNode_UInt32 *)yynodealloc(sizeof(struct ILNode_UInt32__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UInt32_vt__;
	node__->kind__ = ILNode_UInt32_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_Int64_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_Int64 *node__ = (ILNode_Int64 *)yynodealloc(sizeof(struct ILNode_Int64__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Int64_vt__;
	node__->kind__ = ILNode_Int64_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_UInt64_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_UInt64 *node__ = (ILNode_UInt64 *)yynodealloc(sizeof(struct ILNode_UInt64__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UInt64_vt__;
	node__->kind__ = ILNode_UInt64_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_Int_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_Int *node__ = (ILNode_Int *)yynodealloc(sizeof(struct ILNode_Int__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Int_vt__;
	node__->kind__ = ILNode_Int_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_UInt_create(ILUInt64 value, int isneg, int canneg)
{
	ILNode_UInt *node__ = (ILNode_UInt *)yynodealloc(sizeof(struct ILNode_UInt__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UInt_vt__;
	node__->kind__ = ILNode_UInt_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	node__->isneg = isneg;
	node__->canneg = canneg;
	return (ILNode *)node__;
}

ILNode *ILNode_Float32_create(ILDouble value)
{
	ILNode_Float32 *node__ = (ILNode_Float32 *)yynodealloc(sizeof(struct ILNode_Float32__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Float32_vt__;
	node__->kind__ = ILNode_Float32_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	return (ILNode *)node__;
}

ILNode *ILNode_Float64_create(ILDouble value)
{
	ILNode_Float64 *node__ = (ILNode_Float64 *)yynodealloc(sizeof(struct ILNode_Float64__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Float64_vt__;
	node__->kind__ = ILNode_Float64_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	return (ILNode *)node__;
}

ILNode *ILNode_Float_create(ILDouble value)
{
	ILNode_Float *node__ = (ILNode_Float *)yynodealloc(sizeof(struct ILNode_Float__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Float_vt__;
	node__->kind__ = ILNode_Float_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	return (ILNode *)node__;
}

