/* jv_assign.c.  Generated automatically by treecc */
#line 3 "jv_assign.tc"

/*
 * jv_assign.tc - Assignment operator nodes.
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
#line 26 "jv_assign.c"

void JavaDec_ApplyOp(ILGenInfo * info, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 38 "jv_assign.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 48 "jv_assign.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 647 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_ISUB);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 68 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 661 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_ISUB);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt8);
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
				}
			}
#line 89 "jv_assign.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 676 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_ISUB);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 109 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 691 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_ISUB);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 129 "jv_assign.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 691 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_ISUB);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 149 "jv_assign.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 706 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "isub_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_ISUB);
					JavaGenExtend(info, 1);
				}
			}
#line 171 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 723 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "iusub_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_ISUB);
					JavaGenExtend(info, 1);
				}
			}
#line 193 "jv_assign.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 739 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenAdjust(info, 2);
					JavaGenCallIntrinsic(info, "lsub_ovf", "(JJ)J");
					JavaGenAdjust(info, -2);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenSimple(info, JAVA_OP_LSUB);
					JavaGenExtend(info, 2);
				}
			}
#line 215 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 755 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenAdjust(info, 2);
					JavaGenCallIntrinsic(info, "lusub_ovf", "(JJ)J");
					JavaGenAdjust(info, -2);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenSimple(info, JAVA_OP_LSUB);
					JavaGenExtend(info, 2);
				}
			}
#line 237 "jv_assign.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 706 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "isub_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_ISUB);
					JavaGenExtend(info, 1);
				}
			}
#line 259 "jv_assign.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 723 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "iusub_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_ISUB);
					JavaGenExtend(info, 1);
				}
			}
#line 281 "jv_assign.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 771 "jv_assign.tc"
			{
				JavaGenFloat32(info, (ILFloat)1.0);
				JavaGenSimple(info, JAVA_OP_FSUB);
				JavaGenExtend(info, 1);
			}
#line 293 "jv_assign.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 778 "jv_assign.tc"
			{
				JavaGenFloat64(info, (ILDouble)1.0);
				JavaGenSimple(info, JAVA_OP_DSUB);
				JavaGenExtend(info, 1);
			}
#line 305 "jv_assign.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 778 "jv_assign.tc"
			{
				JavaGenFloat64(info, (ILDouble)1.0);
				JavaGenSimple(info, JAVA_OP_DSUB);
				JavaGenExtend(info, 1);
			}
#line 317 "jv_assign.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 784 "jv_assign.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenAdjust(info, 2);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
					JavaGenCallVirtual(info, "java/math/BigDecimal", "subtract",
									   "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Decrement__VV",
									  "(LSystem/Decimal;)LSystem/Decimal;");
				}
			}
#line 342 "jv_assign.c"
		}
		break;

		case ILMachineType_String:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 352 "jv_assign.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 362 "jv_assign.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 372 "jv_assign.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 382 "jv_assign.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 392 "jv_assign.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 810 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 402 "jv_assign.c"
		}
		break;

		default: break;
	}
}

void JavaInc_ApplyOp(ILGenInfo * info, ILMachineType commonType)
{
	switch(commonType)
	{
		case ILMachineType_Void:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 420 "jv_assign.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 430 "jv_assign.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 476 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_IADD);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 450 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 490 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_IADD);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt8);
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
				}
			}
#line 471 "jv_assign.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 505 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_IADD);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 491 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 520 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_IADD);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 511 "jv_assign.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 520 "jv_assign.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenSimple(info, JAVA_OP_IADD);
				JavaGenExtend(info, 1);
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 531 "jv_assign.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 535 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "iadd_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_IADD);
					JavaGenExtend(info, 1);
				}
			}
#line 553 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 552 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "iuadd_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_IADD);
					JavaGenExtend(info, 1);
				}
			}
#line 575 "jv_assign.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 568 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenAdjust(info, 2);
					JavaGenCallIntrinsic(info, "ladd_ovf", "(JJ)J");
					JavaGenAdjust(info, -2);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenSimple(info, JAVA_OP_LADD);
					JavaGenExtend(info, 2);
				}
			}
#line 597 "jv_assign.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 584 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenAdjust(info, 2);
					JavaGenCallIntrinsic(info, "luadd_ovf", "(JJ)J");
					JavaGenAdjust(info, -2);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenSimple(info, JAVA_OP_LADD);
					JavaGenExtend(info, 2);
				}
			}
#line 619 "jv_assign.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 535 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "iadd_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_IADD);
					JavaGenExtend(info, 1);
				}
			}
#line 641 "jv_assign.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 552 "jv_assign.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "iuadd_ovf", "(II)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_ICONST_1);
					JavaGenSimple(info, JAVA_OP_IADD);
					JavaGenExtend(info, 1);
				}
			}
#line 663 "jv_assign.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 600 "jv_assign.tc"
			{
				JavaGenFloat32(info, (ILFloat)1.0);
				JavaGenSimple(info, JAVA_OP_FADD);
				JavaGenExtend(info, 1);
			}
#line 675 "jv_assign.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 607 "jv_assign.tc"
			{
				JavaGenFloat64(info, (ILDouble)1.0);
				JavaGenSimple(info, JAVA_OP_DADD);
				JavaGenExtend(info, 2);
			}
#line 687 "jv_assign.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 607 "jv_assign.tc"
			{
				JavaGenFloat64(info, (ILDouble)1.0);
				JavaGenSimple(info, JAVA_OP_DADD);
				JavaGenExtend(info, 2);
			}
#line 699 "jv_assign.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 613 "jv_assign.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_LCONST_1);
					JavaGenAdjust(info, 2);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
					JavaGenCallVirtual(info, "java/math/BigDecimal", "add",
									   "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Increment__VV",
									  "(LSystem/Decimal;)LSystem/Decimal;");
				}
			}
#line 724 "jv_assign.c"
		}
		break;

		case ILMachineType_String:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 734 "jv_assign.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 744 "jv_assign.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 754 "jv_assign.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 764 "jv_assign.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 774 "jv_assign.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 639 "jv_assign.tc"
			{
				/* Default - should never be used */
			}
#line 784 "jv_assign.c"
		}
		break;

		default: break;
	}
}

