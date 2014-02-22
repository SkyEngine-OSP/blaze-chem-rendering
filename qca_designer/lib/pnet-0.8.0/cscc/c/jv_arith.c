/* jv_arith.c.  Generated automatically by treecc */
#line 3 "jv_arith.tc"

/*
 * jv_arith.tc - Arithmetic operator code generation for Java.
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
#line 26 "jv_arith.c"

void JavaNot_ApplyOp(ILGenInfo * info, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 38 "jv_arith.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 48 "jv_arith.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1479 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenSimple(info, JAVA_OP_I2B);
				JavaGenExtend(info, 1);
			}
#line 61 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1486 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenInt32(info, 0xFF);
				JavaGenSimple(info, JAVA_OP_IAND);
				JavaGenExtend(info, 1);
			}
#line 75 "jv_arith.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1494 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenSimple(info, JAVA_OP_I2S);
				JavaGenExtend(info, 1);
			}
#line 88 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 1502 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenSimple(info, JAVA_OP_I2C);
				JavaGenExtend(info, 1);
			}
#line 101 "jv_arith.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 1502 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenSimple(info, JAVA_OP_I2C);
				JavaGenExtend(info, 1);
			}
#line 114 "jv_arith.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 1512 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenExtend(info, 1);
			}
#line 126 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1512 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenExtend(info, 1);
			}
#line 138 "jv_arith.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1519 "jv_arith.tc"
			{
				JavaGenInt64(info, (ILInt64)(-1));
				JavaGenSimple(info, JAVA_OP_LXOR);
				JavaGenExtend(info, 2);
			}
#line 150 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1519 "jv_arith.tc"
			{
				JavaGenInt64(info, (ILInt64)(-1));
				JavaGenSimple(info, JAVA_OP_LXOR);
				JavaGenExtend(info, 2);
			}
#line 162 "jv_arith.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 1512 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenExtend(info, 1);
			}
#line 174 "jv_arith.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1512 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_M1);
				JavaGenSimple(info, JAVA_OP_IXOR);
				JavaGenExtend(info, 1);
			}
#line 186 "jv_arith.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 196 "jv_arith.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 206 "jv_arith.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 216 "jv_arith.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 226 "jv_arith.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 236 "jv_arith.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 246 "jv_arith.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 256 "jv_arith.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 266 "jv_arith.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 276 "jv_arith.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1536 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 286 "jv_arith.c"
		}
		break;

		default: break;
	}
}

static void JavaBinary_ApplyOp_1__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 588 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 301 "jv_arith.c"

static void JavaBinary_ApplyOp_2__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 588 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 310 "jv_arith.c"

static void JavaBinary_ApplyOp_3__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 428 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	JavaGenSimple(info, JAVA_OP_IADD);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2B);
	}
}
#line 327 "jv_arith.c"

static void JavaBinary_ApplyOp_4__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 442 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	JavaGenSimple(info, JAVA_OP_IADD);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt8);
	}
	else
	{
		JavaGenInt32(info, 0xFF);
		JavaGenSimple(info, JAVA_OP_IAND);
		JavaGenExtend(info, 1);
	}
}
#line 346 "jv_arith.c"

static void JavaBinary_ApplyOp_5__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 458 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	JavaGenSimple(info, JAVA_OP_IADD);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2S);
	}
}
#line 363 "jv_arith.c"

static void JavaBinary_ApplyOp_6__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 473 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_IADD);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2C);
	}
}
#line 380 "jv_arith.c"

static void JavaBinary_ApplyOp_7__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 473 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_IADD);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2C);
	}
}
#line 397 "jv_arith.c"

static void JavaBinary_ApplyOp_8__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 488 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "iadd_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_IADD);
		JavaGenAdjust(info, -1);
	}
}
#line 413 "jv_arith.c"

static void JavaBinary_ApplyOp_9__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 502 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "uiadd_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_IADD);
		JavaGenAdjust(info, -1);
	}
}
#line 429 "jv_arith.c"

static void JavaBinary_ApplyOp_10__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 515 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "ladd_ovf", "(JJ)J");
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_LADD);
		JavaGenAdjust(info, -2);
	}
}
#line 445 "jv_arith.c"

static void JavaBinary_ApplyOp_11__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 528 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "uladd_ovf", "(JJ)J");
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_LADD);
		JavaGenAdjust(info, -2);
	}
}
#line 461 "jv_arith.c"

static void JavaBinary_ApplyOp_12__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 488 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "iadd_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_IADD);
		JavaGenAdjust(info, -1);
	}
}
#line 477 "jv_arith.c"

static void JavaBinary_ApplyOp_13__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 502 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "uiadd_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_IADD);
		JavaGenAdjust(info, -1);
	}
}
#line 493 "jv_arith.c"

static void JavaBinary_ApplyOp_14__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 541 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_FADD);
	JavaGenAdjust(info, -1);
}
#line 501 "jv_arith.c"

static void JavaBinary_ApplyOp_15__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 547 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DADD);
	JavaGenAdjust(info, -2);
}
#line 509 "jv_arith.c"

static void JavaBinary_ApplyOp_16__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 547 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DADD);
	JavaGenAdjust(info, -2);
}
#line 517 "jv_arith.c"

static void JavaBinary_ApplyOp_17__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 552 "jv_arith.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "add",
						   "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Addition__VVV",
						  "(LSystem/Decimal;LSystem/Decimal;)LSystem/Decimal;");
		JavaGenAdjust(info, -1);
	}
}
#line 535 "jv_arith.c"

static void JavaBinary_ApplyOp_18__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 567 "jv_arith.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "concat",
						   "(Ljava/lang/String;)Ljava/lang/String;");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/String", "Concat",
						  "(LSystem/String;LSystem/String;)LSystem/String;");
		JavaGenAdjust(info, -1);
	}
}
#line 553 "jv_arith.c"

static void JavaBinary_ApplyOp_19__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 588 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 562 "jv_arith.c"

static void JavaBinary_ApplyOp_20__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 588 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 571 "jv_arith.c"

static void JavaBinary_ApplyOp_21__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 588 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 580 "jv_arith.c"

static void JavaBinary_ApplyOp_22__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 588 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 589 "jv_arith.c"

static void JavaBinary_ApplyOp_23__(ILGenInfo * info, ILNode_Add *node, ILMachineType commonType)
#line 588 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 598 "jv_arith.c"

static void JavaBinary_ApplyOp_24__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 607 "jv_arith.c"

static void JavaBinary_ApplyOp_25__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 616 "jv_arith.c"

static void JavaBinary_ApplyOp_26__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 598 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	JavaGenSimple(info, JAVA_OP_ISUB);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2B);
	}
}
#line 633 "jv_arith.c"

static void JavaBinary_ApplyOp_27__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 612 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	JavaGenSimple(info, JAVA_OP_ISUB);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt8);
	}
	else
	{
		JavaGenInt32(info, 0xFF);
		JavaGenSimple(info, JAVA_OP_IAND);
		JavaGenExtend(info, 1);
	}
}
#line 652 "jv_arith.c"

static void JavaBinary_ApplyOp_28__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 628 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	JavaGenSimple(info, JAVA_OP_ISUB);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2S);
	}
}
#line 669 "jv_arith.c"

static void JavaBinary_ApplyOp_29__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 643 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_ISUB);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2C);
	}
}
#line 686 "jv_arith.c"

static void JavaBinary_ApplyOp_30__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 643 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_ISUB);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2C);
	}
}
#line 703 "jv_arith.c"

static void JavaBinary_ApplyOp_31__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 658 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "isub_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_ISUB);
		JavaGenAdjust(info, -1);
	}
}
#line 719 "jv_arith.c"

static void JavaBinary_ApplyOp_32__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 672 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "uisub_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_ISUB);
		JavaGenAdjust(info, -1);
	}
}
#line 735 "jv_arith.c"

static void JavaBinary_ApplyOp_33__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 685 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "lsub_ovf", "(JJ)J");
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_LSUB);
		JavaGenAdjust(info, -2);
	}
}
#line 751 "jv_arith.c"

static void JavaBinary_ApplyOp_34__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 698 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "ulsub_ovf", "(JJ)J");
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_LSUB);
		JavaGenAdjust(info, -2);
	}
}
#line 767 "jv_arith.c"

static void JavaBinary_ApplyOp_35__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 658 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "isub_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_ISUB);
		JavaGenAdjust(info, -1);
	}
}
#line 783 "jv_arith.c"

static void JavaBinary_ApplyOp_36__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 672 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "uisub_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_ISUB);
		JavaGenAdjust(info, -1);
	}
}
#line 799 "jv_arith.c"

static void JavaBinary_ApplyOp_37__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 711 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_FSUB);
	JavaGenAdjust(info, -1);
}
#line 807 "jv_arith.c"

static void JavaBinary_ApplyOp_38__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 717 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DSUB);
	JavaGenAdjust(info, -2);
}
#line 815 "jv_arith.c"

static void JavaBinary_ApplyOp_39__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 717 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DSUB);
	JavaGenAdjust(info, -2);
}
#line 823 "jv_arith.c"

static void JavaBinary_ApplyOp_40__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 722 "jv_arith.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "subtract",
						   "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Subtraction__VVV",
						  "(LSystem/Decimal;LSystem/Decimal;)LSystem/Decimal;");
		JavaGenAdjust(info, -1);
	}
}
#line 841 "jv_arith.c"

static void JavaBinary_ApplyOp_41__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 850 "jv_arith.c"

static void JavaBinary_ApplyOp_42__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 859 "jv_arith.c"

static void JavaBinary_ApplyOp_43__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 868 "jv_arith.c"

static void JavaBinary_ApplyOp_44__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 877 "jv_arith.c"

static void JavaBinary_ApplyOp_45__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 886 "jv_arith.c"

static void JavaBinary_ApplyOp_46__(ILGenInfo * info, ILNode_Sub *node, ILMachineType commonType)
#line 744 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 895 "jv_arith.c"

static void JavaBinary_ApplyOp_47__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 904 "jv_arith.c"

static void JavaBinary_ApplyOp_48__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 913 "jv_arith.c"

static void JavaBinary_ApplyOp_49__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 754 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	JavaGenSimple(info, JAVA_OP_IMUL);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2B);
	}
}
#line 930 "jv_arith.c"

static void JavaBinary_ApplyOp_50__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 768 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	JavaGenSimple(info, JAVA_OP_IMUL);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt8);
	}
	else
	{
		JavaGenInt32(info, 0xFF);
		JavaGenSimple(info, JAVA_OP_IAND);
		JavaGenExtend(info, 1);
	}
}
#line 949 "jv_arith.c"

static void JavaBinary_ApplyOp_51__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 784 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	JavaGenSimple(info, JAVA_OP_IMUL);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2S);
	}
}
#line 966 "jv_arith.c"

static void JavaBinary_ApplyOp_52__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 799 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_IMUL);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_UInt32, ILMachineType_UInt16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2C);
	}
}
#line 983 "jv_arith.c"

static void JavaBinary_ApplyOp_53__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 799 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_IMUL);
	JavaGenAdjust(info, -1);
	if(info->overflowInsns)
	{
		JavaGenCast(info, ILMachineType_UInt32, ILMachineType_UInt16);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_I2C);
	}
}
#line 1000 "jv_arith.c"

static void JavaBinary_ApplyOp_54__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 814 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "imul_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_IMUL);
		JavaGenAdjust(info, -1);
	}
}
#line 1016 "jv_arith.c"

static void JavaBinary_ApplyOp_55__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 828 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "uimul_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		/* Note: due to a quirk of binary arithmetic, executing
		   a signed multiply on the unsigned operands will actually
		   give the correct unsigned result */
		JavaGenSimple(info, JAVA_OP_IMUL);
		JavaGenAdjust(info, -1);
	}
}
#line 1035 "jv_arith.c"

static void JavaBinary_ApplyOp_56__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 844 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "lmul_ovf", "(JJ)J");
		JavaGenAdjust(info, -2);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_LMUL);
		JavaGenAdjust(info, -2);
	}
}
#line 1051 "jv_arith.c"

static void JavaBinary_ApplyOp_57__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 857 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "ulmul_ovf", "(JJ)J");
		JavaGenAdjust(info, -2);
	}
	else
	{
		/* Note: due to a quirk of binary arithmetic, executing
		   a signed multiply on the unsigned operands will actually
		   give the correct unsigned result */
		JavaGenSimple(info, JAVA_OP_LMUL);
		JavaGenAdjust(info, -2);
	}
}
#line 1070 "jv_arith.c"

static void JavaBinary_ApplyOp_58__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 814 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "imul_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenSimple(info, JAVA_OP_IMUL);
		JavaGenAdjust(info, -1);
	}
}
#line 1086 "jv_arith.c"

static void JavaBinary_ApplyOp_59__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 828 "jv_arith.tc"
{
	if(info->overflowInsns)
	{
		JavaGenCallIntrinsic(info, "uimul_ovf", "(II)I");
		JavaGenAdjust(info, -1);
	}
	else
	{
		/* Note: due to a quirk of binary arithmetic, executing
		   a signed multiply on the unsigned operands will actually
		   give the correct unsigned result */
		JavaGenSimple(info, JAVA_OP_IMUL);
		JavaGenAdjust(info, -1);
	}
}
#line 1105 "jv_arith.c"

static void JavaBinary_ApplyOp_60__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 873 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_FMUL);
	JavaGenAdjust(info, -1);
}
#line 1113 "jv_arith.c"

static void JavaBinary_ApplyOp_61__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 879 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DMUL);
	JavaGenAdjust(info, -2);
}
#line 1121 "jv_arith.c"

static void JavaBinary_ApplyOp_62__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 879 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DMUL);
	JavaGenAdjust(info, -2);
}
#line 1129 "jv_arith.c"

static void JavaBinary_ApplyOp_63__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 884 "jv_arith.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/math/BigDecimal", "multiply",
						   "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Multiply__VVV",
						  "(LSystem/Decimal;LSystem/Decimal;)LSystem/Decimal;");
		JavaGenAdjust(info, -1);
	}
}
#line 1147 "jv_arith.c"

static void JavaBinary_ApplyOp_64__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1156 "jv_arith.c"

static void JavaBinary_ApplyOp_65__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1165 "jv_arith.c"

static void JavaBinary_ApplyOp_66__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1174 "jv_arith.c"

static void JavaBinary_ApplyOp_67__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1183 "jv_arith.c"

static void JavaBinary_ApplyOp_68__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1192 "jv_arith.c"

static void JavaBinary_ApplyOp_69__(ILGenInfo * info, ILNode_Mul *node, ILMachineType commonType)
#line 906 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1201 "jv_arith.c"

static void JavaBinary_ApplyOp_70__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1210 "jv_arith.c"

static void JavaBinary_ApplyOp_71__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1219 "jv_arith.c"

static void JavaBinary_ApplyOp_72__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 922 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IDIV);
	JavaGenAdjust(info, -1);
}
#line 1227 "jv_arith.c"

static void JavaBinary_ApplyOp_73__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 922 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IDIV);
	JavaGenAdjust(info, -1);
}
#line 1235 "jv_arith.c"

static void JavaBinary_ApplyOp_74__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 922 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IDIV);
	JavaGenAdjust(info, -1);
}
#line 1243 "jv_arith.c"

static void JavaBinary_ApplyOp_75__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 922 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IDIV);
	JavaGenAdjust(info, -1);
}
#line 1251 "jv_arith.c"

static void JavaBinary_ApplyOp_76__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 922 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IDIV);
	JavaGenAdjust(info, -1);
}
#line 1259 "jv_arith.c"

static void JavaBinary_ApplyOp_77__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 922 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IDIV);
	JavaGenAdjust(info, -1);
}
#line 1267 "jv_arith.c"

static void JavaBinary_ApplyOp_78__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 928 "jv_arith.tc"
{
	JavaGenCallIntrinsic(info, "uidiv", "(II)I");
	JavaGenAdjust(info, -1);
}
#line 1275 "jv_arith.c"

static void JavaBinary_ApplyOp_79__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 933 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LDIV);
	JavaGenAdjust(info, -2);
}
#line 1283 "jv_arith.c"

static void JavaBinary_ApplyOp_80__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 938 "jv_arith.tc"
{
	JavaGenCallIntrinsic(info, "uldiv", "(JJ)J");
	JavaGenAdjust(info, -2);
}
#line 1291 "jv_arith.c"

static void JavaBinary_ApplyOp_81__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 922 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IDIV);
	JavaGenAdjust(info, -1);
}
#line 1299 "jv_arith.c"

static void JavaBinary_ApplyOp_82__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 928 "jv_arith.tc"
{
	JavaGenCallIntrinsic(info, "uidiv", "(II)I");
	JavaGenAdjust(info, -1);
}
#line 1307 "jv_arith.c"

static void JavaBinary_ApplyOp_83__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 943 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_FDIV);
	JavaGenAdjust(info, -1);
}
#line 1315 "jv_arith.c"

static void JavaBinary_ApplyOp_84__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 949 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DDIV);
	JavaGenAdjust(info, -2);
}
#line 1323 "jv_arith.c"

static void JavaBinary_ApplyOp_85__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 949 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DDIV);
	JavaGenAdjust(info, -2);
}
#line 1331 "jv_arith.c"

static void JavaBinary_ApplyOp_86__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 954 "jv_arith.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallIntrinsic(info, "Ddiv",
			  		"(Ljava/math/BigDecimal;Ljava/math/BigDecimal;)"
							"Ljava/math/BigDecimal;");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Division__VVV",
						  "(LSystem/Decimal;LSystem/Decimal;)LSystem/Decimal;");
		JavaGenAdjust(info, -1);
	}
}
#line 1350 "jv_arith.c"

static void JavaBinary_ApplyOp_87__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1359 "jv_arith.c"

static void JavaBinary_ApplyOp_88__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1368 "jv_arith.c"

static void JavaBinary_ApplyOp_89__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1377 "jv_arith.c"

static void JavaBinary_ApplyOp_90__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1386 "jv_arith.c"

static void JavaBinary_ApplyOp_91__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1395 "jv_arith.c"

static void JavaBinary_ApplyOp_92__(ILGenInfo * info, ILNode_Div *node, ILMachineType commonType)
#line 977 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1404 "jv_arith.c"

static void JavaBinary_ApplyOp_93__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1413 "jv_arith.c"

static void JavaBinary_ApplyOp_94__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1422 "jv_arith.c"

static void JavaBinary_ApplyOp_95__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 993 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IREM);
	JavaGenAdjust(info, -1);
}
#line 1430 "jv_arith.c"

static void JavaBinary_ApplyOp_96__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 993 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IREM);
	JavaGenAdjust(info, -1);
}
#line 1438 "jv_arith.c"

static void JavaBinary_ApplyOp_97__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 993 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IREM);
	JavaGenAdjust(info, -1);
}
#line 1446 "jv_arith.c"

static void JavaBinary_ApplyOp_98__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 993 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IREM);
	JavaGenAdjust(info, -1);
}
#line 1454 "jv_arith.c"

static void JavaBinary_ApplyOp_99__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 993 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IREM);
	JavaGenAdjust(info, -1);
}
#line 1462 "jv_arith.c"

static void JavaBinary_ApplyOp_100__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 993 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IREM);
	JavaGenAdjust(info, -1);
}
#line 1470 "jv_arith.c"

static void JavaBinary_ApplyOp_101__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 999 "jv_arith.tc"
{
	JavaGenCallIntrinsic(info, "uirem", "(II)I");
	JavaGenAdjust(info, -1);
}
#line 1478 "jv_arith.c"

static void JavaBinary_ApplyOp_102__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1004 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LREM);
	JavaGenAdjust(info, -2);
}
#line 1486 "jv_arith.c"

static void JavaBinary_ApplyOp_103__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1009 "jv_arith.tc"
{
	JavaGenCallIntrinsic(info, "ulrem", "(JJ)J");
	JavaGenAdjust(info, -2);
}
#line 1494 "jv_arith.c"

static void JavaBinary_ApplyOp_104__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 993 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IREM);
	JavaGenAdjust(info, -1);
}
#line 1502 "jv_arith.c"

static void JavaBinary_ApplyOp_105__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 999 "jv_arith.tc"
{
	JavaGenCallIntrinsic(info, "uirem", "(II)I");
	JavaGenAdjust(info, -1);
}
#line 1510 "jv_arith.c"

static void JavaBinary_ApplyOp_106__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1014 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_FREM);
	JavaGenAdjust(info, -1);
}
#line 1518 "jv_arith.c"

static void JavaBinary_ApplyOp_107__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1020 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DREM);
	JavaGenAdjust(info, -2);
}
#line 1526 "jv_arith.c"

static void JavaBinary_ApplyOp_108__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1020 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_DREM);
	JavaGenAdjust(info, -2);
}
#line 1534 "jv_arith.c"

static void JavaBinary_ApplyOp_109__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1025 "jv_arith.tc"
{
	if(info->useJavaLib)
	{
		JavaGenCallIntrinsic(info, "Drem",
			  		"(Ljava/math/BigDecimal;Ljava/math/BigDecimal;)"
							"Ljava/math/BigDecimal;");
		JavaGenAdjust(info, -1);
	}
	else
	{
		JavaGenCallByName(info, "System/Decimal", "op_Modulus__VVV",
						  "(LSystem/Decimal;LSystem/Decimal;)LSystem/Decimal;");
		JavaGenAdjust(info, -1);
	}
}
#line 1553 "jv_arith.c"

static void JavaBinary_ApplyOp_110__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1562 "jv_arith.c"

static void JavaBinary_ApplyOp_111__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1571 "jv_arith.c"

static void JavaBinary_ApplyOp_112__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1580 "jv_arith.c"

static void JavaBinary_ApplyOp_113__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1589 "jv_arith.c"

static void JavaBinary_ApplyOp_114__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1598 "jv_arith.c"

static void JavaBinary_ApplyOp_115__(ILGenInfo * info, ILNode_Rem *node, ILMachineType commonType)
#line 1048 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 1607 "jv_arith.c"

void JavaBinary_ApplyOp(ILGenInfo * info, ILNode_BinaryArith * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_Add_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaBinary_ApplyOp_1__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBinary_ApplyOp_2__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBinary_ApplyOp_3__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBinary_ApplyOp_4__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBinary_ApplyOp_5__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBinary_ApplyOp_6__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBinary_ApplyOp_7__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBinary_ApplyOp_8__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBinary_ApplyOp_9__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBinary_ApplyOp_10__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBinary_ApplyOp_11__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBinary_ApplyOp_12__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBinary_ApplyOp_13__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBinary_ApplyOp_14__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBinary_ApplyOp_15__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBinary_ApplyOp_16__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBinary_ApplyOp_17__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBinary_ApplyOp_18__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBinary_ApplyOp_19__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBinary_ApplyOp_20__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBinary_ApplyOp_21__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBinary_ApplyOp_22__(info, (ILNode_Add *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBinary_ApplyOp_23__(info, (ILNode_Add *)node__, commonType);
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
					JavaBinary_ApplyOp_24__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBinary_ApplyOp_25__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBinary_ApplyOp_26__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBinary_ApplyOp_27__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBinary_ApplyOp_28__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBinary_ApplyOp_29__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBinary_ApplyOp_30__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBinary_ApplyOp_31__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBinary_ApplyOp_32__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBinary_ApplyOp_33__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBinary_ApplyOp_34__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBinary_ApplyOp_35__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBinary_ApplyOp_36__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBinary_ApplyOp_37__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBinary_ApplyOp_38__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBinary_ApplyOp_39__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBinary_ApplyOp_40__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBinary_ApplyOp_41__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBinary_ApplyOp_42__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBinary_ApplyOp_43__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBinary_ApplyOp_44__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBinary_ApplyOp_45__(info, (ILNode_Sub *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBinary_ApplyOp_46__(info, (ILNode_Sub *)node__, commonType);
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
					JavaBinary_ApplyOp_47__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBinary_ApplyOp_48__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBinary_ApplyOp_49__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBinary_ApplyOp_50__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBinary_ApplyOp_51__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBinary_ApplyOp_52__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBinary_ApplyOp_53__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBinary_ApplyOp_54__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBinary_ApplyOp_55__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBinary_ApplyOp_56__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBinary_ApplyOp_57__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBinary_ApplyOp_58__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBinary_ApplyOp_59__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBinary_ApplyOp_60__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBinary_ApplyOp_61__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBinary_ApplyOp_62__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBinary_ApplyOp_63__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBinary_ApplyOp_64__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBinary_ApplyOp_65__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBinary_ApplyOp_66__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBinary_ApplyOp_67__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBinary_ApplyOp_68__(info, (ILNode_Mul *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBinary_ApplyOp_69__(info, (ILNode_Mul *)node__, commonType);
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
					JavaBinary_ApplyOp_70__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBinary_ApplyOp_71__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBinary_ApplyOp_72__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBinary_ApplyOp_73__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBinary_ApplyOp_74__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBinary_ApplyOp_75__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBinary_ApplyOp_76__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBinary_ApplyOp_77__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBinary_ApplyOp_78__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBinary_ApplyOp_79__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBinary_ApplyOp_80__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBinary_ApplyOp_81__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBinary_ApplyOp_82__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBinary_ApplyOp_83__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBinary_ApplyOp_84__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBinary_ApplyOp_85__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBinary_ApplyOp_86__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBinary_ApplyOp_87__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBinary_ApplyOp_88__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBinary_ApplyOp_89__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBinary_ApplyOp_90__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBinary_ApplyOp_91__(info, (ILNode_Div *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBinary_ApplyOp_92__(info, (ILNode_Div *)node__, commonType);
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
					JavaBinary_ApplyOp_93__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBinary_ApplyOp_94__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBinary_ApplyOp_95__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBinary_ApplyOp_96__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBinary_ApplyOp_97__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBinary_ApplyOp_98__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBinary_ApplyOp_99__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBinary_ApplyOp_100__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBinary_ApplyOp_101__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBinary_ApplyOp_102__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBinary_ApplyOp_103__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBinary_ApplyOp_104__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBinary_ApplyOp_105__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBinary_ApplyOp_106__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBinary_ApplyOp_107__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBinary_ApplyOp_108__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBinary_ApplyOp_109__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBinary_ApplyOp_110__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBinary_ApplyOp_111__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBinary_ApplyOp_112__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBinary_ApplyOp_113__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBinary_ApplyOp_114__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBinary_ApplyOp_115__(info, (ILNode_Rem *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

void JavaNegate_ApplyOp(ILGenInfo * info, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2362 "jv_arith.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2372 "jv_arith.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1373 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_INEG);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 2390 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1385 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_INEG);
				JavaGenInt32(info, 0xFF);
				JavaGenSimple(info, JAVA_OP_IAND);
				JavaGenExtend(info, 1);
			}
#line 2403 "jv_arith.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1392 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_INEG);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 2421 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 1405 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_INEG);
				JavaGenSimple(info, JAVA_OP_I2C);
			}
#line 2432 "jv_arith.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 1405 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_INEG);
				JavaGenSimple(info, JAVA_OP_I2C);
			}
#line 2443 "jv_arith.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 1411 "jv_arith.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ineg_ovf", "(I)I");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_INEG);
				}
			}
#line 2460 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1434 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_INEG);
			}
#line 2470 "jv_arith.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1422 "jv_arith.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "lneg_ovf", "(J)J");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_LNEG);
				}
			}
#line 2487 "jv_arith.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1438 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_LNEG);
			}
#line 2497 "jv_arith.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 1411 "jv_arith.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ineg_ovf", "(I)I");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_INEG);
				}
			}
#line 2514 "jv_arith.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1434 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_INEG);
			}
#line 2524 "jv_arith.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1442 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_FNEG);
			}
#line 2534 "jv_arith.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1447 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_DNEG);
			}
#line 2544 "jv_arith.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1447 "jv_arith.tc"
			{
				JavaGenSimple(info, JAVA_OP_DNEG);
			}
#line 2554 "jv_arith.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1451 "jv_arith.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallVirtual(info, "java/math/BigDecimal", "negate",
									   "()Ljava/math/BigDecimal;");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_UnaryNegation__VV",
									  "(LSystem/Decimal;)LSystem/Decimal;");
				}
			}
#line 2573 "jv_arith.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2583 "jv_arith.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2593 "jv_arith.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2603 "jv_arith.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2613 "jv_arith.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2623 "jv_arith.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1471 "jv_arith.tc"
			{
				/* Default - should never be used */
			}
#line 2633 "jv_arith.c"
		}
		break;

		default: break;
	}
}

static void JavaShift_ApplyOp_1__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2648 "jv_arith.c"

static void JavaShift_ApplyOp_2__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2657 "jv_arith.c"

static void JavaShift_ApplyOp_3__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1220 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenSimple(info, JAVA_OP_I2B);
	JavaGenAdjust(info, -1);
}
#line 2667 "jv_arith.c"

static void JavaShift_ApplyOp_4__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1227 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint8" */
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenInt32(info, 0xFF);
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 2678 "jv_arith.c"

static void JavaShift_ApplyOp_5__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1235 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenSimple(info, JAVA_OP_I2S);
	JavaGenAdjust(info, -1);
}
#line 2688 "jv_arith.c"

static void JavaShift_ApplyOp_6__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1243 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenSimple(info, JAVA_OP_I2C);
	JavaGenAdjust(info, -1);
}
#line 2698 "jv_arith.c"

static void JavaShift_ApplyOp_7__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1243 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "uint16" */
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenSimple(info, JAVA_OP_I2C);
	JavaGenAdjust(info, -1);
}
#line 2708 "jv_arith.c"

static void JavaShift_ApplyOp_8__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1253 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenAdjust(info, -1);
}
#line 2716 "jv_arith.c"

static void JavaShift_ApplyOp_9__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1253 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenAdjust(info, -1);
}
#line 2724 "jv_arith.c"

static void JavaShift_ApplyOp_10__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1259 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LSHL);
	JavaGenAdjust(info, -1);
}
#line 2732 "jv_arith.c"

static void JavaShift_ApplyOp_11__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1259 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LSHL);
	JavaGenAdjust(info, -1);
}
#line 2740 "jv_arith.c"

static void JavaShift_ApplyOp_12__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1253 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenAdjust(info, -1);
}
#line 2748 "jv_arith.c"

static void JavaShift_ApplyOp_13__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1253 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHL);
	JavaGenAdjust(info, -1);
}
#line 2756 "jv_arith.c"

static void JavaShift_ApplyOp_14__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2765 "jv_arith.c"

static void JavaShift_ApplyOp_15__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2774 "jv_arith.c"

static void JavaShift_ApplyOp_16__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2783 "jv_arith.c"

static void JavaShift_ApplyOp_17__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2792 "jv_arith.c"

static void JavaShift_ApplyOp_18__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2801 "jv_arith.c"

static void JavaShift_ApplyOp_19__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2810 "jv_arith.c"

static void JavaShift_ApplyOp_20__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2819 "jv_arith.c"

static void JavaShift_ApplyOp_21__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2828 "jv_arith.c"

static void JavaShift_ApplyOp_22__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2837 "jv_arith.c"

static void JavaShift_ApplyOp_23__(ILGenInfo * info, ILNode_Shl *node, ILMachineType commonType)
#line 1275 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2846 "jv_arith.c"

static void JavaShift_ApplyOp_24__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2855 "jv_arith.c"

static void JavaShift_ApplyOp_25__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2864 "jv_arith.c"

static void JavaShift_ApplyOp_26__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1291 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHR);
	JavaGenAdjust(info, -1);
}
#line 2872 "jv_arith.c"

static void JavaShift_ApplyOp_27__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1291 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHR);
	JavaGenAdjust(info, -1);
}
#line 2880 "jv_arith.c"

static void JavaShift_ApplyOp_28__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1291 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHR);
	JavaGenAdjust(info, -1);
}
#line 2888 "jv_arith.c"

static void JavaShift_ApplyOp_29__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1291 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHR);
	JavaGenAdjust(info, -1);
}
#line 2896 "jv_arith.c"

static void JavaShift_ApplyOp_30__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1291 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHR);
	JavaGenAdjust(info, -1);
}
#line 2904 "jv_arith.c"

static void JavaShift_ApplyOp_31__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1291 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHR);
	JavaGenAdjust(info, -1);
}
#line 2912 "jv_arith.c"

static void JavaShift_ApplyOp_32__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1297 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 2920 "jv_arith.c"

static void JavaShift_ApplyOp_33__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1302 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LSHR);
	JavaGenAdjust(info, -1);
}
#line 2928 "jv_arith.c"

static void JavaShift_ApplyOp_34__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1307 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LUSHR);
	JavaGenAdjust(info, -1);
}
#line 2936 "jv_arith.c"

static void JavaShift_ApplyOp_35__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1291 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_ISHR);
	JavaGenAdjust(info, -1);
}
#line 2944 "jv_arith.c"

static void JavaShift_ApplyOp_36__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1297 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 2952 "jv_arith.c"

static void JavaShift_ApplyOp_37__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2961 "jv_arith.c"

static void JavaShift_ApplyOp_38__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2970 "jv_arith.c"

static void JavaShift_ApplyOp_39__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2979 "jv_arith.c"

static void JavaShift_ApplyOp_40__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2988 "jv_arith.c"

static void JavaShift_ApplyOp_41__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 2997 "jv_arith.c"

static void JavaShift_ApplyOp_42__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3006 "jv_arith.c"

static void JavaShift_ApplyOp_43__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3015 "jv_arith.c"

static void JavaShift_ApplyOp_44__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3024 "jv_arith.c"

static void JavaShift_ApplyOp_45__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3033 "jv_arith.c"

static void JavaShift_ApplyOp_46__(ILGenInfo * info, ILNode_Shr *node, ILMachineType commonType)
#line 1323 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3042 "jv_arith.c"

static void JavaShift_ApplyOp_47__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3051 "jv_arith.c"

static void JavaShift_ApplyOp_48__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3060 "jv_arith.c"

static void JavaShift_ApplyOp_49__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3068 "jv_arith.c"

static void JavaShift_ApplyOp_50__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3076 "jv_arith.c"

static void JavaShift_ApplyOp_51__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3084 "jv_arith.c"

static void JavaShift_ApplyOp_52__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3092 "jv_arith.c"

static void JavaShift_ApplyOp_53__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3100 "jv_arith.c"

static void JavaShift_ApplyOp_54__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3108 "jv_arith.c"

static void JavaShift_ApplyOp_55__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3116 "jv_arith.c"

static void JavaShift_ApplyOp_56__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1347 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LUSHR);
	JavaGenAdjust(info, -1);
}
#line 3124 "jv_arith.c"

static void JavaShift_ApplyOp_57__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1347 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LUSHR);
	JavaGenAdjust(info, -1);
}
#line 3132 "jv_arith.c"

static void JavaShift_ApplyOp_58__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3140 "jv_arith.c"

static void JavaShift_ApplyOp_59__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1341 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IUSHR);
	JavaGenAdjust(info, -1);
}
#line 3148 "jv_arith.c"

static void JavaShift_ApplyOp_60__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3157 "jv_arith.c"

static void JavaShift_ApplyOp_61__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3166 "jv_arith.c"

static void JavaShift_ApplyOp_62__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3175 "jv_arith.c"

static void JavaShift_ApplyOp_63__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3184 "jv_arith.c"

static void JavaShift_ApplyOp_64__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3193 "jv_arith.c"

static void JavaShift_ApplyOp_65__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3202 "jv_arith.c"

static void JavaShift_ApplyOp_66__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3211 "jv_arith.c"

static void JavaShift_ApplyOp_67__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3220 "jv_arith.c"

static void JavaShift_ApplyOp_68__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3229 "jv_arith.c"

static void JavaShift_ApplyOp_69__(ILGenInfo * info, ILNode_UShr *node, ILMachineType commonType)
#line 1363 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3238 "jv_arith.c"

void JavaShift_ApplyOp(ILGenInfo * info, ILNode_BinaryShift * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_Shl_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaShift_ApplyOp_1__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaShift_ApplyOp_2__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaShift_ApplyOp_3__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaShift_ApplyOp_4__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaShift_ApplyOp_5__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaShift_ApplyOp_6__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaShift_ApplyOp_7__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaShift_ApplyOp_8__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaShift_ApplyOp_9__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaShift_ApplyOp_10__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaShift_ApplyOp_11__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaShift_ApplyOp_12__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaShift_ApplyOp_13__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaShift_ApplyOp_14__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaShift_ApplyOp_15__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaShift_ApplyOp_16__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaShift_ApplyOp_17__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaShift_ApplyOp_18__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaShift_ApplyOp_19__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaShift_ApplyOp_20__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaShift_ApplyOp_21__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaShift_ApplyOp_22__(info, (ILNode_Shl *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaShift_ApplyOp_23__(info, (ILNode_Shl *)node__, commonType);
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
					JavaShift_ApplyOp_24__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaShift_ApplyOp_25__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaShift_ApplyOp_26__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaShift_ApplyOp_27__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaShift_ApplyOp_28__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaShift_ApplyOp_29__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaShift_ApplyOp_30__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaShift_ApplyOp_31__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaShift_ApplyOp_32__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaShift_ApplyOp_33__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaShift_ApplyOp_34__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaShift_ApplyOp_35__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaShift_ApplyOp_36__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaShift_ApplyOp_37__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaShift_ApplyOp_38__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaShift_ApplyOp_39__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaShift_ApplyOp_40__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaShift_ApplyOp_41__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaShift_ApplyOp_42__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaShift_ApplyOp_43__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaShift_ApplyOp_44__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaShift_ApplyOp_45__(info, (ILNode_Shr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaShift_ApplyOp_46__(info, (ILNode_Shr *)node__, commonType);
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
					JavaShift_ApplyOp_47__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaShift_ApplyOp_48__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaShift_ApplyOp_49__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaShift_ApplyOp_50__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaShift_ApplyOp_51__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaShift_ApplyOp_52__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaShift_ApplyOp_53__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaShift_ApplyOp_54__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaShift_ApplyOp_55__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaShift_ApplyOp_56__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaShift_ApplyOp_57__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaShift_ApplyOp_58__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaShift_ApplyOp_59__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaShift_ApplyOp_60__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaShift_ApplyOp_61__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaShift_ApplyOp_62__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaShift_ApplyOp_63__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaShift_ApplyOp_64__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaShift_ApplyOp_65__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaShift_ApplyOp_66__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaShift_ApplyOp_67__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaShift_ApplyOp_68__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaShift_ApplyOp_69__(info, (ILNode_UShr *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void JavaBitwise_ApplyOp_1__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3696 "jv_arith.c"

static void JavaBitwise_ApplyOp_2__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1058 "jv_arith.tc"
{
	/* Returns true if both arguments are true.  We assume
	   that both arguments are clamped to the set {0,1} */
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3706 "jv_arith.c"

static void JavaBitwise_ApplyOp_3__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1065 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenSimple(info, JAVA_OP_I2B);
	JavaGenAdjust(info, -1);
}
#line 3716 "jv_arith.c"

static void JavaBitwise_ApplyOp_4__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1085 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3724 "jv_arith.c"

static void JavaBitwise_ApplyOp_5__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1072 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenSimple(info, JAVA_OP_I2S);
	JavaGenAdjust(info, -1);
}
#line 3734 "jv_arith.c"

static void JavaBitwise_ApplyOp_6__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1085 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3742 "jv_arith.c"

static void JavaBitwise_ApplyOp_7__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1085 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3750 "jv_arith.c"

static void JavaBitwise_ApplyOp_8__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1085 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3758 "jv_arith.c"

static void JavaBitwise_ApplyOp_9__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1085 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3766 "jv_arith.c"

static void JavaBitwise_ApplyOp_10__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1091 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LAND);
	JavaGenAdjust(info, -2);
}
#line 3774 "jv_arith.c"

static void JavaBitwise_ApplyOp_11__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1091 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LAND);
	JavaGenAdjust(info, -2);
}
#line 3782 "jv_arith.c"

static void JavaBitwise_ApplyOp_12__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1085 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3790 "jv_arith.c"

static void JavaBitwise_ApplyOp_13__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1085 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IAND);
	JavaGenAdjust(info, -1);
}
#line 3798 "jv_arith.c"

static void JavaBitwise_ApplyOp_14__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3807 "jv_arith.c"

static void JavaBitwise_ApplyOp_15__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3816 "jv_arith.c"

static void JavaBitwise_ApplyOp_16__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3825 "jv_arith.c"

static void JavaBitwise_ApplyOp_17__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3834 "jv_arith.c"

static void JavaBitwise_ApplyOp_18__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3843 "jv_arith.c"

static void JavaBitwise_ApplyOp_19__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3852 "jv_arith.c"

static void JavaBitwise_ApplyOp_20__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3861 "jv_arith.c"

static void JavaBitwise_ApplyOp_21__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3870 "jv_arith.c"

static void JavaBitwise_ApplyOp_22__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3879 "jv_arith.c"

static void JavaBitwise_ApplyOp_23__(ILGenInfo * info, ILNode_And *node, ILMachineType commonType)
#line 1106 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3888 "jv_arith.c"

static void JavaBitwise_ApplyOp_24__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 3897 "jv_arith.c"

static void JavaBitwise_ApplyOp_25__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1116 "jv_arith.tc"
{
	/* Returns true if one of the arguments is true.  We assume
	   that both arguments are clamped to the set {0,1} */
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3907 "jv_arith.c"

static void JavaBitwise_ApplyOp_26__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3915 "jv_arith.c"

static void JavaBitwise_ApplyOp_27__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3923 "jv_arith.c"

static void JavaBitwise_ApplyOp_28__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3931 "jv_arith.c"

static void JavaBitwise_ApplyOp_29__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3939 "jv_arith.c"

static void JavaBitwise_ApplyOp_30__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3947 "jv_arith.c"

static void JavaBitwise_ApplyOp_31__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3955 "jv_arith.c"

static void JavaBitwise_ApplyOp_32__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3963 "jv_arith.c"

static void JavaBitwise_ApplyOp_33__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1137 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LOR);
	JavaGenAdjust(info, -2);
}
#line 3971 "jv_arith.c"

static void JavaBitwise_ApplyOp_34__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1137 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LOR);
	JavaGenAdjust(info, -2);
}
#line 3979 "jv_arith.c"

static void JavaBitwise_ApplyOp_35__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3987 "jv_arith.c"

static void JavaBitwise_ApplyOp_36__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1131 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IOR);
	JavaGenAdjust(info, -1);
}
#line 3995 "jv_arith.c"

static void JavaBitwise_ApplyOp_37__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4004 "jv_arith.c"

static void JavaBitwise_ApplyOp_38__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4013 "jv_arith.c"

static void JavaBitwise_ApplyOp_39__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4022 "jv_arith.c"

static void JavaBitwise_ApplyOp_40__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4031 "jv_arith.c"

static void JavaBitwise_ApplyOp_41__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4040 "jv_arith.c"

static void JavaBitwise_ApplyOp_42__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4049 "jv_arith.c"

static void JavaBitwise_ApplyOp_43__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4058 "jv_arith.c"

static void JavaBitwise_ApplyOp_44__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4067 "jv_arith.c"

static void JavaBitwise_ApplyOp_45__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4076 "jv_arith.c"

static void JavaBitwise_ApplyOp_46__(ILGenInfo * info, ILNode_Or *node, ILMachineType commonType)
#line 1152 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4085 "jv_arith.c"

static void JavaBitwise_ApplyOp_47__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4094 "jv_arith.c"

static void JavaBitwise_ApplyOp_48__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1162 "jv_arith.tc"
{
	/* Returns the XOR of the boolean arguments.  We assume
	   that both arguments are clamped to the set {0,1} */
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4104 "jv_arith.c"

static void JavaBitwise_ApplyOp_49__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1169 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int8" */
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenSimple(info, JAVA_OP_I2B);
	JavaGenAdjust(info, -1);
}
#line 4114 "jv_arith.c"

static void JavaBitwise_ApplyOp_50__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1189 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4122 "jv_arith.c"

static void JavaBitwise_ApplyOp_51__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1176 "jv_arith.tc"
{
	/* Perform the operation and then clamp the result to "int16" */
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenSimple(info, JAVA_OP_I2S);
	JavaGenAdjust(info, -1);
}
#line 4132 "jv_arith.c"

static void JavaBitwise_ApplyOp_52__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1189 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4140 "jv_arith.c"

static void JavaBitwise_ApplyOp_53__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1189 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4148 "jv_arith.c"

static void JavaBitwise_ApplyOp_54__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1189 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4156 "jv_arith.c"

static void JavaBitwise_ApplyOp_55__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1189 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4164 "jv_arith.c"

static void JavaBitwise_ApplyOp_56__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1195 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LXOR);
	JavaGenAdjust(info, -2);
}
#line 4172 "jv_arith.c"

static void JavaBitwise_ApplyOp_57__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1195 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_LXOR);
	JavaGenAdjust(info, -2);
}
#line 4180 "jv_arith.c"

static void JavaBitwise_ApplyOp_58__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1189 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4188 "jv_arith.c"

static void JavaBitwise_ApplyOp_59__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1189 "jv_arith.tc"
{
	JavaGenSimple(info, JAVA_OP_IXOR);
	JavaGenAdjust(info, -1);
}
#line 4196 "jv_arith.c"

static void JavaBitwise_ApplyOp_60__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4205 "jv_arith.c"

static void JavaBitwise_ApplyOp_61__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4214 "jv_arith.c"

static void JavaBitwise_ApplyOp_62__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4223 "jv_arith.c"

static void JavaBitwise_ApplyOp_63__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4232 "jv_arith.c"

static void JavaBitwise_ApplyOp_64__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4241 "jv_arith.c"

static void JavaBitwise_ApplyOp_65__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4250 "jv_arith.c"

static void JavaBitwise_ApplyOp_66__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4259 "jv_arith.c"

static void JavaBitwise_ApplyOp_67__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4268 "jv_arith.c"

static void JavaBitwise_ApplyOp_68__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4277 "jv_arith.c"

static void JavaBitwise_ApplyOp_69__(ILGenInfo * info, ILNode_Xor *node, ILMachineType commonType)
#line 1210 "jv_arith.tc"
{
	/* Default - should never be used */
	JavaGenSimple(info, JAVA_OP_POP);
	JavaGenAdjust(info, -1);
}
#line 4286 "jv_arith.c"

void JavaBitwise_ApplyOp(ILGenInfo * info, ILNode_BinaryBitwise * node__, ILMachineType commonType)
{
	switch(node__->kind__)
	{
		case ILNode_And_kind:
		{
			switch(commonType)
			{
				case ILMachineType_Void:
				{
					JavaBitwise_ApplyOp_1__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBitwise_ApplyOp_2__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBitwise_ApplyOp_3__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBitwise_ApplyOp_4__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBitwise_ApplyOp_5__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBitwise_ApplyOp_6__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBitwise_ApplyOp_7__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBitwise_ApplyOp_8__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBitwise_ApplyOp_9__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBitwise_ApplyOp_10__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBitwise_ApplyOp_11__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBitwise_ApplyOp_12__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBitwise_ApplyOp_13__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBitwise_ApplyOp_14__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBitwise_ApplyOp_15__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBitwise_ApplyOp_16__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBitwise_ApplyOp_17__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBitwise_ApplyOp_18__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBitwise_ApplyOp_19__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBitwise_ApplyOp_20__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBitwise_ApplyOp_21__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBitwise_ApplyOp_22__(info, (ILNode_And *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBitwise_ApplyOp_23__(info, (ILNode_And *)node__, commonType);
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
					JavaBitwise_ApplyOp_24__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBitwise_ApplyOp_25__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBitwise_ApplyOp_26__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBitwise_ApplyOp_27__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBitwise_ApplyOp_28__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBitwise_ApplyOp_29__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBitwise_ApplyOp_30__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBitwise_ApplyOp_31__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBitwise_ApplyOp_32__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBitwise_ApplyOp_33__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBitwise_ApplyOp_34__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBitwise_ApplyOp_35__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBitwise_ApplyOp_36__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBitwise_ApplyOp_37__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBitwise_ApplyOp_38__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBitwise_ApplyOp_39__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBitwise_ApplyOp_40__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBitwise_ApplyOp_41__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBitwise_ApplyOp_42__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBitwise_ApplyOp_43__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBitwise_ApplyOp_44__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBitwise_ApplyOp_45__(info, (ILNode_Or *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBitwise_ApplyOp_46__(info, (ILNode_Or *)node__, commonType);
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
					JavaBitwise_ApplyOp_47__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Boolean:
				{
					JavaBitwise_ApplyOp_48__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int8:
				{
					JavaBitwise_ApplyOp_49__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt8:
				{
					JavaBitwise_ApplyOp_50__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int16:
				{
					JavaBitwise_ApplyOp_51__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt16:
				{
					JavaBitwise_ApplyOp_52__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Char:
				{
					JavaBitwise_ApplyOp_53__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int32:
				{
					JavaBitwise_ApplyOp_54__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt32:
				{
					JavaBitwise_ApplyOp_55__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Int64:
				{
					JavaBitwise_ApplyOp_56__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UInt64:
				{
					JavaBitwise_ApplyOp_57__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_NativeInt:
				{
					JavaBitwise_ApplyOp_58__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_NativeUInt:
				{
					JavaBitwise_ApplyOp_59__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Float32:
				{
					JavaBitwise_ApplyOp_60__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Float64:
				{
					JavaBitwise_ApplyOp_61__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_NativeFloat:
				{
					JavaBitwise_ApplyOp_62__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_Decimal:
				{
					JavaBitwise_ApplyOp_63__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_String:
				{
					JavaBitwise_ApplyOp_64__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_ObjectRef:
				{
					JavaBitwise_ApplyOp_65__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_UnmanagedPtr:
				{
					JavaBitwise_ApplyOp_66__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedPtr:
				{
					JavaBitwise_ApplyOp_67__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_TransientPtr:
				{
					JavaBitwise_ApplyOp_68__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				case ILMachineType_ManagedValue:
				{
					JavaBitwise_ApplyOp_69__(info, (ILNode_Xor *)node__, commonType);
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

