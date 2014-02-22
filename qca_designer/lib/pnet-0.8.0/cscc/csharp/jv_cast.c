/* jv_cast.c.  Generated automatically by treecc */
#line 3 "jv_cast.tc"

/*
 * jv_cast.tc - Cast operations.
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
#line 33 "jv_cast.tc"


/*
 * Cast from one type to another, while forcing overflow checking.
 */
void JavaGenCastOverflow(ILGenInfo *info, ILMachineType fromType,
						 ILMachineType toType)
{
	int overflow = info->overflowInsns;
	info->overflowInsns = 1;
	JavaGenCast(info, fromType, toType);
	info->overflowInsns = overflow;
}

#line 41 "jv_cast.c"

void JavaGenCast_split_0__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 53 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 53 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 74 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 64 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 206 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 75 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 354 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 86 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 471 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, 1);
			}
#line 97 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 607 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 108 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 607 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 119 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 781 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 130 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 921 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 141 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1071 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 2);
			}
#line 152 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1181 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 2);
			}
#line 163 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 781 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 174 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 921 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenAdjust(info, 1);
			}
#line 185 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1338 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_FCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 196 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1422 "jv_cast.tc"
			{
				JavaGenFloat32(info, (ILFloat)0.0);
				JavaGenAdjust(info, 1);
			}
#line 207 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1422 "jv_cast.tc"
			{
				JavaGenFloat32(info, (ILFloat)0.0);
				JavaGenAdjust(info, 1);
			}
#line 218 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1531 "jv_cast.tc"
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
#line 242 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1813 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, 1);
			}
#line 253 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2050 "jv_cast.tc"
			{
				/* The default object reference value is "null" */
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, 1);
			}
#line 265 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2050 "jv_cast.tc"
			{
				/* The default object reference value is "null" */
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, 1);
			}
#line 277 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2050 "jv_cast.tc"
			{
				/* The default object reference value is "null" */
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, 1);
			}
#line 289 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2050 "jv_cast.tc"
			{
				/* The default object reference value is "null" */
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, 1);
			}
#line 301 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2050 "jv_cast.tc"
			{
				/* The default object reference value is "null" */
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, 1);
			}
#line 313 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_1__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 332 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 79 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 342 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 212 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 352 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 360 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 362 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 479 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 372 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 382 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 392 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 402 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 412 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 424 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1205 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient, because the high bit is zero */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 436 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 446 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 456 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 466 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 476 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 486 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1550 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else if(info->clsCompliant)
				{
					/* CLS cannot convert from int8 to decimal, so use int32 instead */
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__V",
									  "(B)LSystem/Decimal;");
				}
			}
#line 513 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1818 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenNewObj(info, "java/lang/Boolean");
					JavaGenSimple(info, JAVA_OP_DUP_X1);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_SWAP);
					JavaGenCallCtor(info, "java/lang/Boolean", "<init>", "(Z)V");
					JavaGenAdjust(info, -2);
					JavaGenCallVirtual(info, "java/lang/Boolean", "toString",
									   "()Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Boolean", "ToString",
									  "(Z)LSystem/String;");
				}
			}
#line 538 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 551 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 564 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 577 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 590 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 603 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_2__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 622 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 639 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 212 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 649 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 668 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 479 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 678 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 695 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 712 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 722 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 736 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 748 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1189 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ul_ovf", "(I)J");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenAdjust(info, 1);
				}
			}
#line 767 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 777 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 791 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 801 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 811 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 821 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1550 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else if(info->clsCompliant)
				{
					/* CLS cannot convert from int8 to decimal, so use int32 instead */
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__V",
									  "(B)LSystem/Decimal;");
				}
			}
#line 848 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1837 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Byte", "toString",
									  "(B)Ljava/lang/String;");
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the SByte class, so use Int32 instead */
					JavaGenCallByName(info, "System/Int32", "ToString",
									  "(I)LSystem/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/SByte", "ToString",
									  "(B)LSystem/String;");
				}
			}
#line 873 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 886 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 899 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 912 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 925 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 938 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_3__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 957 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 974 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 233 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 991 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 360 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1001 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 479 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1011 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1021 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1031 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1041 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1051 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 1063 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1205 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient, because the high bit is zero */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 1075 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1085 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1095 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 1105 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 1115 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 1125 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1571 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__BV",
									  "(I)LSystem/Decimal;");
				}
			}
#line 1146 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1856 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "toString",
									  "(I)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Byte", "ToString__BC",
									  "(I)LSystem/String;");
				}
			}
#line 1165 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1178 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1191 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1204 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1217 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1230 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_4__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 1249 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 1266 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 218 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 1283 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 1302 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 479 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1312 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 1329 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 1346 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1356 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 1370 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 1382 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1189 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ul_ovf", "(I)J");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenAdjust(info, 1);
				}
			}
#line 1401 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1411 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 1425 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 1435 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 1445 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 1455 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1586 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__V",
									  "(S)LSystem/Decimal;");
				}
			}
#line 1476 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1869 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Short", "toString",
									  "(S)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Int16", "ToString",
									  "(S)LSystem/String;");
				}
			}
#line 1495 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1508 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1521 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1534 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1547 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1560 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_5__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 1579 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 1596 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 233 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 1613 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 1632 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 499 "jv_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2s_ovf", "(I)S");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 1650 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1660 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1670 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1680 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1690 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 1702 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1205 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient, because the high bit is zero */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 1714 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1724 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1734 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 1744 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 1754 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 1764 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1601 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else if(info->clsCompliant)
				{
					/* CLS cannot convert from uint16 to decimal, so use int32 instead */
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__SV",
									  "(I)LSystem/Decimal;");
				}
			}
#line 1791 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1882 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "toString",
									  "(I)Ljava/lang/String;");
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt16 class, so use Int32 instead */
					JavaGenCallByName(info, "System/Int32", "ToString",
									  "(I)LSystem/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/UInt16", "ToString__SC",
									  "(I)LSystem/String;");
				}
			}
#line 1816 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1829 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1842 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1855 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1868 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 1881 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_6__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 1900 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 1917 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 233 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 1934 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 1953 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 499 "jv_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2s_ovf", "(I)S");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 1971 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1981 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 619 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 1991 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2001 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2011 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 2023 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1205 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient, because the high bit is zero */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 2035 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2045 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2055 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 2065 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 2075 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 2085 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1622 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__V",
									  "(C)LSystem/Decimal;");
				}
			}
#line 2106 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1901 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/String", "valueOf",
									  "(C)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Char", "ToString",
									  "(C)LSystem/String;");
				}
			}
#line 2125 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2138 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2151 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2164 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2177 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2190 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_7__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 2209 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 2226 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 218 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 2243 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 2262 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 484 "jv_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2s_ovf", "(I)S");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 2280 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 2297 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 2314 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2324 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 2338 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 2350 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1189 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ul_ovf", "(I)J");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenAdjust(info, 1);
				}
			}
#line 2369 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2379 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 2393 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 2403 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 2413 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 2423 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1638 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
				}
			}
#line 2444 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1915 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "toString",
									  "(I)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Int32", "ToString",
									  "(I)LSystem/String;");
				}
			}
#line 2463 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2476 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2489 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2502 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2515 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2528 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_8__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 2547 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 2564 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 233 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 2581 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 2600 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 499 "jv_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2s_ovf", "(I)S");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 2618 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 2635 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 2652 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 808 "jv_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2i_ovf", "(I)I");
				}
			}
#line 2666 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2676 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1090 "jv_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 2691 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1212 "jv_cast.tc"
			{
				/* Zero-extend a 32-bit value to a 64-bit value */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 2706 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 808 "jv_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2i_ovf", "(I)I");
				}
			}
#line 2720 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 2730 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1355 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenSimple(info, JAVA_OP_L2F);
				JavaGenExtend(info, 3);
			}
#line 2744 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1449 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenSimple(info, JAVA_OP_L2D);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 2759 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1449 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenSimple(info, JAVA_OP_L2D);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 2774 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1654 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
				}
				else if(info->clsCompliant)
				{
					/* CLS cannot convert from uint32 to decimal, so use int64 instead */
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__lV",
									  "(J)LSystem/Decimal;");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__IV",
									  "(I)LSystem/Decimal;");
					JavaGenAdjust(info, -1);
				}
			}
#line 2803 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1929 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "java/lang/Long", "toString",
									  "(J)Ljava/lang/String;");
					JavaGenAdjust(info, -1);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt32 class, so use Int64 instead */
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "System/Int64", "ToString",
									  "(J)LSystem/String;");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/UInt32", "ToString__IC",
									  "(I)LSystem/String;");
				}
			}
#line 2832 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2845 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2858 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2871 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2884 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 2897 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_9__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 60 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenAdjust(info, -2);
			}
#line 2916 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 117 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    JavaGenSimple(info, JAVA_OP_LCONST_0);
			    JavaGenSimple(info, JAVA_OP_LCMP);
			    JavaGenJump(info, JAVA_OP_IFEQ, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_1);
			    JavaGenJump(info, JAVA_OP_GOTO, &label2);
			    JavaGenLabel(info, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_0);
			    JavaGenLabel(info, &label2);
			    JavaGenExtend(info, 2);
				JavaGenAdjust(info, -1);
			}
#line 2937 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 244 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2b_ovf", "(J)B");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2B);
					JavaGenAdjust(info, -1);
				}
			}
#line 2957 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 385 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2ub_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenAdjust(info, -1);
				}
			}
#line 2978 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 511 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2s_ovf", "(J)S");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2S);
					JavaGenAdjust(info, -1);
				}
			}
#line 2998 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 648 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2us_ovf", "(J)C");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 3018 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 648 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2us_ovf", "(J)C");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 3038 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 817 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2i_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3057 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 959 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2ui_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3076 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1099 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 3086 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1225 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2ul_ovf", "(J)J");
				}
			}
#line 3100 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 817 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2i_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3119 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 959 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2ui_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3138 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1363 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_L2F);
				JavaGenAdjust(info, -1);
			}
#line 3149 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1459 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_L2D);
			}
#line 3159 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1459 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_L2D);
			}
#line 3169 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1677 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__lV",
									  "(J)LSystem/Decimal;");
					JavaGenAdjust(info, -1);
				}
			}
#line 3190 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1952 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Long", "toString",
									  "(J)Ljava/lang/String;");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/Int64", "ToString",
									  "(J)LSystem/String;");
					JavaGenAdjust(info, -1);
				}
			}
#line 3211 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3225 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3239 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3253 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3267 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3281 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_10__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 60 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenAdjust(info, -2);
			}
#line 3300 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 117 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    JavaGenSimple(info, JAVA_OP_LCONST_0);
			    JavaGenSimple(info, JAVA_OP_LCMP);
			    JavaGenJump(info, JAVA_OP_IFEQ, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_1);
			    JavaGenJump(info, JAVA_OP_GOTO, &label2);
			    JavaGenLabel(info, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_0);
			    JavaGenLabel(info, &label2);
			    JavaGenExtend(info, 2);
				JavaGenAdjust(info, -1);
			}
#line 3321 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 258 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ul2b_ovf", "(J)B");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2B);
					JavaGenAdjust(info, -1);
				}
			}
#line 3341 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 385 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2ub_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenAdjust(info, -1);
				}
			}
#line 3362 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 525 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ul2s_ovf", "(J)S");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2S);
					JavaGenAdjust(info, -1);
				}
			}
#line 3382 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 648 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2us_ovf", "(J)C");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 3402 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 648 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2us_ovf", "(J)C");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 3422 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 831 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ul2i_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3441 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 959 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2ui_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3460 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1103 "jv_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ul2l_ovf", "(J)J");
				}
			}
#line 3474 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1221 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 3484 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 831 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ul2i_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3503 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 959 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "l2ui_ovf", "(J)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_L2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 3522 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1368 "jv_cast.tc"
			{
				JavaGenCallIntrinsic(info, "ul2f", "(J)F");
				JavaGenAdjust(info, -1);
			}
#line 3533 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1464 "jv_cast.tc"
			{
				JavaGenCallIntrinsic(info, "ul2d", "(J)D");
			}
#line 3543 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1464 "jv_cast.tc"
			{
				JavaGenCallIntrinsic(info, "ul2d", "(J)D");
			}
#line 3553 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1692 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallIntrinsic(info, "ul2D", "(J)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
				}
				else if(info->clsCompliant)
				{
					/* CLS cannot convert directly from uint64 to decimal,
					   so we need to do this in a round-about fashion.
					   We subtract 0x8000000000000000, convert to decimal,
					   and then add 0x8000000000000000 */
					JavaGenInt64(info, IL_MIN_INT64);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_LSUB);
					JavaGenAdjust(info, -2);
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__lV",
									  "(J)LSystem/Decimal;");
					JavaGenAdjust(info, -1);
					JavaGenNewObj(info, "System/Decimal");
					JavaGenSimple(info, JAVA_OP_DUP);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* low */
					JavaGenInt32(info, (ILInt32)0x80000000);	/* mid */
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* high */
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* isNegative */
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* scale */
					JavaGenAdjust(info, 5);
					JavaGenCallCtor(info, "System/Decimal", "<init>__iiiB", "(IIIZI)V");
					JavaGenAdjust(info, -6);
					JavaGenCallByName(info, "System/Decimal", "op_Addition__VVV",
									  "(LSystem/Decimal;LSystem/Decimal;)LSystem/Decimal;");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__LV",
									  "(J)LSystem/Decimal;");
					JavaGenAdjust(info, -1);
				}
			}
#line 3601 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1967 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallIntrinsic(info, "ul2S", "(J)Ljava/lang/String;");
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt64 class, so convert via Decimal */
					JavaGenCast(info, ILMachineType_UInt64, ILMachineType_Decimal);
					JavaGenCallByName(info, "System/Decimal", "ToString__VC",
									  "(LSystem/Decimal;)LSystem/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/UInt64", "ToString__LC",
									  "(J)LSystem/String;");
				}
			}
#line 3626 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3640 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3654 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3668 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3682 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 3696 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_11__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 3715 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 3732 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 218 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 3749 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 3768 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 484 "jv_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2s_ovf", "(I)S");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 3786 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 3803 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 3820 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 3830 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 3844 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1083 "jv_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenAdjust(info, 1);
			}
#line 3856 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1189 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ul_ovf", "(I)J");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenAdjust(info, 1);
				}
			}
#line 3875 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 801 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 3885 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 948 "jv_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ui_ovf", "(I)I");
				}
			}
#line 3899 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1350 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2F);
			}
#line 3909 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 3919 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1442 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2D);
			}
#line 3929 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1638 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_I2L);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
				}
			}
#line 3950 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1915 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "toString",
									  "(I)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Int32", "ToString",
									  "(I)LSystem/String;");
				}
			}
#line 3969 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 3982 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 3995 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4008 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4021 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4034 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_12__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 4053 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 91 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFEQ, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 4070 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 233 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2b_ovf", "(I)B");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 4087 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 371 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2ub_ovf", "(I)I");
				}
				else
				{
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 4106 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 499 "jv_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2s_ovf", "(I)S");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 4124 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 4141 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 634 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "i2us_ovf", "(I)C");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 4158 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 808 "jv_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2i_ovf", "(I)I");
				}
			}
#line 4172 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 4182 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1090 "jv_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 4197 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1212 "jv_cast.tc"
			{
				/* Zero-extend a 32-bit value to a 64-bit value */
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 4212 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 808 "jv_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "ui2i_ovf", "(I)I");
				}
			}
#line 4226 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 937 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 4236 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1355 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenSimple(info, JAVA_OP_L2F);
				JavaGenExtend(info, 3);
			}
#line 4250 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1449 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenSimple(info, JAVA_OP_L2D);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 4265 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1449 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_I2L);
				JavaGenInt64(info, (ILInt64)(ILUInt32)0xFFFFFFFF);
				JavaGenSimple(info, JAVA_OP_LAND);
				JavaGenSimple(info, JAVA_OP_L2D);
				JavaGenExtend(info, 3);
				JavaGenAdjust(info, 1);
			}
#line 4280 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1654 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenAdjust(info, -1);
				}
				else if(info->clsCompliant)
				{
					/* CLS cannot convert from uint32 to decimal, so use int64 instead */
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__lV",
									  "(J)LSystem/Decimal;");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__IV",
									  "(I)LSystem/Decimal;");
					JavaGenAdjust(info, -1);
				}
			}
#line 4309 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1929 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "java/lang/Long", "toString",
									  "(J)Ljava/lang/String;");
					JavaGenAdjust(info, -1);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt32 class, so use Int64 instead */
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_Int64);
					JavaGenCallByName(info, "System/Int64", "ToString",
									  "(J)LSystem/String;");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/UInt32", "ToString__IC",
									  "(I)LSystem/String;");
				}
			}
#line 4338 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4351 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4364 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4377 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4390 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4403 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_13__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 4422 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    JavaGenSimple(info, JAVA_OP_FCONST_0);
			    JavaGenSimple(info, JAVA_OP_FCMPL);
			    JavaGenJump(info, JAVA_OP_IFEQ, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_1);
			    JavaGenJump(info, JAVA_OP_GOTO, &label2);
			    JavaGenLabel(info, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_0);
			    JavaGenLabel(info, &label2);
			    JavaGenExtend(info, 1);
			}
#line 4442 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 272 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float32, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2I);
					JavaGenSimple(info, JAVA_OP_I2B);
				}
			}
#line 4461 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 400 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float32, ILMachineType_UInt32);
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_UInt8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2I);
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenExtend(info, 1);
				}
			}
#line 4482 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 539 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float32, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2I);
					JavaGenSimple(info, JAVA_OP_I2S);
				}
			}
#line 4501 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 663 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float32, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2I);
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 4520 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 663 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float32, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2I);
					JavaGenSimple(info, JAVA_OP_I2C);
				}
			}
#line 4539 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 845 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					/* Up-convert to "double" and then convert that to "int" */
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenCallIntrinsic(info, "d2i_ovf", "(D)I");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2I);
				}
			}
#line 4559 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 973 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					/* Convert to "double" and then convert that to "uint32" */
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenCallIntrinsic(info, "d2ui_ovf", "(D)I");
					JavaGenExtend(info, 1);
				}
				else
				{
					/* Convert to "double" and then convert that to "uint32" */
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenCallIntrinsic(info, "d2ui", "(D)I");
					JavaGenExtend(info, 1);
				}
			}
#line 4582 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1111 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					/* Convert to "double" and then convert that */
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "d2l_ovf", "(D)J");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2L);
					JavaGenAdjust(info, 1);
				}
			}
#line 4603 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1233 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "d2ul_ovf", "(D)J");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "d2ul", "(D)J");
				}
			}
#line 4624 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 845 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					/* Up-convert to "double" and then convert that to "int" */
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenCallIntrinsic(info, "d2i_ovf", "(D)I");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_F2I);
				}
			}
#line 4644 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 973 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					/* Convert to "double" and then convert that to "uint32" */
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenCallIntrinsic(info, "d2ui_ovf", "(D)I");
					JavaGenExtend(info, 1);
				}
				else
				{
					/* Convert to "double" and then convert that to "uint32" */
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenCallIntrinsic(info, "d2ui", "(D)I");
					JavaGenExtend(info, 1);
				}
			}
#line 4667 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1373 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 4677 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1469 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_F2D);
				JavaGenAdjust(info, 1);
			}
#line 4688 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1469 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_F2D);
				JavaGenAdjust(info, 1);
			}
#line 4699 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1734 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_F2D);
					JavaGenAdjust(info, 1);
					JavaGenNewObj(info, "java/math/BigDecimal");
					JavaGenSimple(info, JAVA_OP_DUP_X2);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_DUP_X2);
					JavaGenAdjust(info, 1);
					JavaGenSimple(info, JAVA_OP_POP);
					JavaGenAdjust(info, -1);
					JavaGenCallCtor(info, "java/math/BigDecimal", "<init>", "(D)V");
					JavaGenAdjust(info, -3);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(F)LSystem/Decimal;");
				}
			}
#line 4727 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1986 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Float", "toString",
									  "(F)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Single", "ToString",
									  "(F)LSystem/String;");
				}
			}
#line 4746 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4759 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4772 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4785 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4798 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 4811 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_14__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 60 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenAdjust(info, -2);
			}
#line 4830 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 147 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    JavaGenSimple(info, JAVA_OP_DCONST_0);
			    JavaGenSimple(info, JAVA_OP_DCMPL);
			    JavaGenJump(info, JAVA_OP_IFEQ, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_1);
			    JavaGenJump(info, JAVA_OP_GOTO, &label2);
			    JavaGenLabel(info, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_0);
			    JavaGenLabel(info, &label2);
			    JavaGenExtend(info, 2);
				JavaGenAdjust(info, -1);
			}
#line 4851 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 286 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2B);
					JavaGenAdjust(info, -1);
				}
			}
#line 4871 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 416 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_UInt32);
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_UInt8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenAdjust(info, -1);
				}
			}
#line 4892 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 553 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2S);
					JavaGenAdjust(info, -1);
				}
			}
#line 4912 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 679 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 4932 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 679 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 4952 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 862 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2i_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 4971 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 993 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2ui_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallIntrinsic(info, "d2ui", "(D)I");
					JavaGenAdjust(info, -1);
				}
			}
#line 4990 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1127 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2l_ovf", "(D)J");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2L);
				}
			}
#line 5007 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1249 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2ul_ovf", "(D)J");
				}
				else
				{
					JavaGenCallIntrinsic(info, "d2ul", "(D)J");
				}
			}
#line 5024 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 862 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2i_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 5043 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 993 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2ui_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallIntrinsic(info, "d2ui", "(D)I");
					JavaGenAdjust(info, -1);
				}
			}
#line 5062 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1378 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_D2F);
				JavaGenAdjust(info, -1);
			}
#line 5073 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1477 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 5083 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1477 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 5093 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1757 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenNewObj(info, "java/math/BigDecimal");
					JavaGenSimple(info, JAVA_OP_DUP_X2);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_DUP_X2);
					JavaGenAdjust(info, 1);
					JavaGenSimple(info, JAVA_OP_POP);
					JavaGenAdjust(info, -1);
					JavaGenCallCtor(info, "java/math/BigDecimal", "<init>", "(D)V");
					JavaGenAdjust(info, -3);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(D)LSystem/Decimal;");
				}
			}
#line 5119 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2000 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Double", "toString",
									  "(D)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Double", "ToString",
									  "(D)LSystem/String;");
				}
			}
#line 5138 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5152 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5166 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5180 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5194 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5208 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_15__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 60 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenAdjust(info, -2);
			}
#line 5227 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 147 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    JavaGenSimple(info, JAVA_OP_DCONST_0);
			    JavaGenSimple(info, JAVA_OP_DCMPL);
			    JavaGenJump(info, JAVA_OP_IFEQ, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_1);
			    JavaGenJump(info, JAVA_OP_GOTO, &label2);
			    JavaGenLabel(info, &label1);
			    JavaGenSimple(info, JAVA_OP_ICONST_0);
			    JavaGenLabel(info, &label2);
			    JavaGenExtend(info, 2);
				JavaGenAdjust(info, -1);
			}
#line 5248 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 286 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2B);
					JavaGenAdjust(info, -1);
				}
			}
#line 5268 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 416 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_UInt32);
					JavaGenCast(info, ILMachineType_UInt32, ILMachineType_UInt8);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenInt32(info, 0xFF);
					JavaGenSimple(info, JAVA_OP_IAND);
					JavaGenAdjust(info, -1);
				}
			}
#line 5289 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 553 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_Int16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2S);
					JavaGenAdjust(info, -1);
				}
			}
#line 5309 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 679 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 5329 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 679 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCast(info, ILMachineType_Float64, ILMachineType_Int32);
					JavaGenCast(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenSimple(info, JAVA_OP_I2C);
					JavaGenAdjust(info, -1);
				}
			}
#line 5349 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 862 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2i_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 5368 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 993 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2ui_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallIntrinsic(info, "d2ui", "(D)I");
					JavaGenAdjust(info, -1);
				}
			}
#line 5387 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1127 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2l_ovf", "(D)J");
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2L);
				}
			}
#line 5404 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1249 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2ul_ovf", "(D)J");
				}
				else
				{
					JavaGenCallIntrinsic(info, "d2ul", "(D)J");
				}
			}
#line 5421 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 862 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2i_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenSimple(info, JAVA_OP_D2I);
					JavaGenAdjust(info, -1);
				}
			}
#line 5440 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 993 "jv_cast.tc"
			{
				if(info->overflowInsns)
				{
					JavaGenCallIntrinsic(info, "d2ui_ovf", "(D)I");
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallIntrinsic(info, "d2ui", "(D)I");
					JavaGenAdjust(info, -1);
				}
			}
#line 5459 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1378 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_D2F);
				JavaGenAdjust(info, -1);
			}
#line 5470 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1477 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 5480 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1477 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 5490 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1757 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenNewObj(info, "java/math/BigDecimal");
					JavaGenSimple(info, JAVA_OP_DUP_X2);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_DUP_X2);
					JavaGenAdjust(info, 1);
					JavaGenSimple(info, JAVA_OP_POP);
					JavaGenAdjust(info, -1);
					JavaGenCallCtor(info, "java/math/BigDecimal", "<init>", "(D)V");
					JavaGenAdjust(info, -3);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(D)LSystem/Decimal;");
				}
			}
#line 5516 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2000 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Double", "toString",
									  "(D)Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Double", "ToString",
									  "(D)LSystem/String;");
				}
			}
#line 5535 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5549 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5563 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5577 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5591 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2084 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
				JavaGenAdjust(info, -1);
			}
#line 5605 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_16__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 5624 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 162 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
				    JavaGenSimple(info, JAVA_OP_LCONST_0);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 2);
					JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
									   "(Ljava/lang/Object;)Z");
				}
				else
				{
				    JavaGenSimple(info, JAVA_OP_ICONST_0);
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
					JavaGenCallByName(info, "System/Decimal", "op_Equality__VV",
									  "(LSystem/Decimal;LSystem/Decimal;)Z");
					JavaGenExtend(info, 1);
				}
			}
#line 5651 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 300 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCastOverflow(info, ILMachineType_Decimal, ILMachineType_Int32);
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to int8, so
					   down-convert from int32 instead */
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__Vi",
									  "(LSystem/Decimal;)I");
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(LSystem/Decimal;)B");
				}
			}
#line 5678 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 431 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCastOverflow(info, ILMachineType_Decimal, ILMachineType_Int32);
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_UInt8);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__VB",
									  "(LSystem/Decimal;)I");
				}
			}
#line 5697 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 567 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCastOverflow(info, ILMachineType_Decimal, ILMachineType_Int32);
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_Int16);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(LSystem/Decimal;)S");
				}
			}
#line 5716 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 693 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCastOverflow(info, ILMachineType_Decimal, ILMachineType_Int32);
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to uint16, so
					   down-convert from int32 instead */
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__VS",
									  "(LSystem/Decimal;)I");
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__VS",
									  "(LSystem/Decimal;)I");
				}
			}
#line 5743 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 714 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCastOverflow(info, ILMachineType_Decimal, ILMachineType_Int32);
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(LSystem/Decimal;)C");
				}
			}
#line 5762 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 876 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallIntrinsic(info, "D2i_ovf", "(Ljava/math/BigDecimal;)I");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__Vi",
									  "(LSystem/Decimal;)I");
				}
			}
#line 5780 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1007 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCastOverflow(info, ILMachineType_Decimal, ILMachineType_Int64);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to uint32, so
					   down-convert from int64 instead */
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__Vl",
									  "(LSystem/Decimal;)J");
					JavaGenAdjust(info, 1);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__VI",
									  "(LSystem/Decimal;)I");
				}
			}
#line 5808 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1138 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallIntrinsic(info, "D2l_ovf", "(Ljava/math/BigDecimal;)J");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__Vl",
									  "(LSystem/Decimal;)J");
					JavaGenAdjust(info, 1);
				}
			}
#line 5828 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1260 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallIntrinsic(info, "D2ul_ovf", "(Ljava/math/BigDecimal;)J");
					JavaGenAdjust(info, 1);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to uint64,
					   so we need to do this in a more round-about fashion.
					   We subtract 0x8000000000000000, convert to int64, and
					   then add 0x8000000000000000 to the result */
					JavaGenNewObj(info, "System/Decimal");
					JavaGenSimple(info, JAVA_OP_DUP);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* low */
					JavaGenInt32(info, (ILInt32)0x80000000);	/* mid */
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* high */
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* isNegative */
					JavaGenSimple(info, JAVA_OP_ICONST_0);		/* scale */
					JavaGenAdjust(info, 5);
					JavaGenCallCtor(info, "System/Decimal", "<init>__iiiB", "(IIIZI)V");
					JavaGenAdjust(info, -6);
					JavaGenCallByName(info, "System/Decimal", "op_Subtraction__VVV",
									  "(LSystem/Decimal;LSystem/Decimal;)LSystem/Decimal;");
					JavaGenAdjust(info, -1);
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__Vl",
									  "(LSystem/Decimal;)J");
					JavaGenAdjust(info, 1);
					JavaGenInt64(info, IL_MIN_INT64);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_LADD);
					JavaGenAdjust(info, -2);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__VL",
									  "(LSystem/Decimal;)J");
					JavaGenAdjust(info, 1);
				}
			}
#line 5876 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 876 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallIntrinsic(info, "D2i_ovf", "(Ljava/math/BigDecimal;)I");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__Vi",
									  "(LSystem/Decimal;)I");
				}
			}
#line 5894 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1007 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCastOverflow(info, ILMachineType_Decimal, ILMachineType_Int64);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to uint32, so
					   down-convert from int64 instead */
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__Vl",
									  "(LSystem/Decimal;)J");
					JavaGenAdjust(info, 1);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__VI",
									  "(LSystem/Decimal;)I");
				}
			}
#line 5922 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1383 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallVirtual(info, "java/math/BigDecimal", "floatValue", "()F");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(LSystem/Decimal;)F");
				}
			}
#line 5940 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1482 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallVirtual(info, "java/math/BigDecimal", "doubleValue", "()D");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(LSystem/Decimal;)D");
					JavaGenAdjust(info, 1);
				}
			}
#line 5960 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1482 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallVirtual(info, "java/math/BigDecimal", "doubleValue", "()D");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "op_Explicit__V",
									  "(LSystem/Decimal;)D");
					JavaGenAdjust(info, 1);
				}
			}
#line 5980 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1777 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 5990 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2013 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallVirtual(info, "java/math/BigDecimal", "toString",
									  "()Ljava/lang/String;");
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "ToString__VC",
									  "(LSystem/Decimal;)LSystem/String;");
				}
			}
#line 6009 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6022 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6035 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6048 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6061 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6074 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_17__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 6093 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 183 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Boolean", "valueOf",
									  "(Ljava/lang/String;)Ljava/lang/Boolean;");
					JavaGenCallVirtual(info, "java/lang/Boolean", "booleanValue", "()Z");
				}
				else
				{
					JavaGenCallByName(info, "System/Boolean", "FromString",
									  "(LSystem/String;)Z");
				}
			}
#line 6113 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 321 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Byte", "parseByte",
									  "(Ljava/lang/String;)B");
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the SByte class, so down-convert from Int32 */
					JavaGenCallByName(info, "System/Int32", "FromString",
									  "(LSystem/String;)I");
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_Int8);
				}
				else
				{
					JavaGenCallByName(info, "System/SByte", "FromString",
									  "(LSystem/String;)B");
				}
			}
#line 6139 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 444 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "parseInt",
									  "(Ljava/lang/String;)I");
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_UInt8);
				}
				else
				{
					JavaGenCallByName(info, "System/Byte", "FromString__CB",
									  "(LSystem/String;)I");
				}
			}
#line 6159 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 580 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Short", "parseShort",
									  "(Ljava/lang/String;)S");
				}
				else
				{
					JavaGenCallByName(info, "System/Int16", "FromString",
									  "(LSystem/String;)S");
				}
			}
#line 6178 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 727 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "parseInt",
									  "(Ljava/lang/String;)I");
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt16 class, so down-convert from Int32 */
					JavaGenCallByName(info, "System/Int32", "FromString",
									  "(LSystem/String;)I");
					JavaGenCastOverflow(info, ILMachineType_Int32, ILMachineType_UInt16);
				}
				else
				{
					JavaGenCallByName(info, "System/UInt16", "FromString__CS",
									  "(LSystem/String;)I");
				}
			}
#line 6205 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 748 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenSimple(info, JAVA_OP_ICONST_0);
					JavaGenCallVirtual(info, "java/lang/String", "charAt", "(I)C");
					JavaGenExtend(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Char", "FromString",
									  "(LSystem/String;)C");
				}
			}
#line 6225 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 889 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "parseInt",
									  "(Ljava/lang/String;)I");
				}
				else
				{
					JavaGenCallByName(info, "System/Int32", "FromString",
									  "(LSystem/String;)I");
				}
			}
#line 6244 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1030 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Long", "parseLong",
									  "(Ljava/lang/String;)J");
					JavaGenAdjust(info, 1);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt32 class, so down-convert from Int64 */
					JavaGenCallByName(info, "System/Int64", "FromString",
									  "(LSystem/String;)J");
					JavaGenAdjust(info, 1);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else
				{
					JavaGenCallByName(info, "System/UInt32", "FromString__CI",
									  "(LSystem/String;)I");
				}
			}
#line 6273 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1152 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Long", "parseLong",
									  "(Ljava/lang/String;)J");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Int64", "FromString",
									  "(LSystem/String;)J");
					JavaGenAdjust(info, 1);
				}
			}
#line 6294 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1302 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenInt32(info, 10);
					JavaGenAdjust(info, 1);
					JavaGenCallIntrinsic(info, "S2ul_ovf", "(Ljava/lang/String;)J");
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt64 class, so down-convert from Decimal */
					JavaGenCallByName(info, "System/Decimal", "FromString__CV",
									  "(LSystem/String;)LSystem/Decimal;");
					JavaGenCast(info, ILMachineType_Decimal, ILMachineType_UInt64);
				}
				else
				{
					JavaGenCallByName(info, "System/UInt64", "FromString__CL",
									  "(LSystem/String;)J");
					JavaGenAdjust(info, 1);
				}
			}
#line 6322 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 889 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Integer", "parseInt",
									  "(Ljava/lang/String;)I");
				}
				else
				{
					JavaGenCallByName(info, "System/Int32", "FromString",
									  "(LSystem/String;)I");
				}
			}
#line 6341 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1030 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Long", "parseLong",
									  "(Ljava/lang/String;)J");
					JavaGenAdjust(info, 1);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else if(info->clsCompliant)
				{
					/* CLS does not have the UInt32 class, so down-convert from Int64 */
					JavaGenCallByName(info, "System/Int64", "FromString",
									  "(LSystem/String;)J");
					JavaGenAdjust(info, 1);
					JavaGenCastOverflow(info, ILMachineType_Int64, ILMachineType_UInt32);
				}
				else
				{
					JavaGenCallByName(info, "System/UInt32", "FromString__CI",
									  "(LSystem/String;)I");
				}
			}
#line 6370 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1395 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Float", "parseFloat",
									  "(Ljava/lang/String;)F");
				}
				else
				{
					JavaGenCallByName(info, "System/Single", "FromString",
									  "(LSystem/String;)F");
				}
			}
#line 6389 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1497 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Double", "parseDouble",
									  "(Ljava/lang/String;)D");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Double", "FromString",
									  "(LSystem/String;)D");
					JavaGenAdjust(info, 1);
				}
			}
#line 6410 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1497 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Double", "parseDouble",
									  "(Ljava/lang/String;)D");
					JavaGenAdjust(info, 1);
				}
				else
				{
					JavaGenCallByName(info, "System/Double", "FromString",
									  "(LSystem/String;)D");
					JavaGenAdjust(info, 1);
				}
			}
#line 6431 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1781 "jv_cast.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenNewObj(info, "java/math/BigDecimal");
					JavaGenSimple(info, JAVA_OP_DUP_X1);
					JavaGenAdjust(info, 2);
					JavaGenSimple(info, JAVA_OP_SWAP);
					JavaGenCallCtor(info, "java/math/BigDecimal", "<init>",
								    "(Ljava/lang/String;)V");
					JavaGenAdjust(info, -2);
				}
				else
				{
					JavaGenCallByName(info, "System/Decimal", "FromString__CV",
									  "(LSystem/String;)LSystem/Decimal;");
				}
			}
#line 6455 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2026 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 6465 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2061 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 6475 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6488 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6501 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6514 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6527 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_18__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 6546 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 105 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFNULL, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 6563 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 345 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6574 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 462 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6585 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 597 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6596 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6607 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6618 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6629 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6640 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1171 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6652 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1328 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6664 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6675 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6686 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1412 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_FCONST_0);
			}
#line 6697 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6709 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6721 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1803 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
				JavaGenCast(info, ILMachineType_Void, ILMachineType_Decimal);
			}
#line 6733 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2030 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 6743 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2061 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 6753 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6766 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6779 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6792 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 6805 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_19__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 6824 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 105 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFNULL, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 6841 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 345 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6852 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 462 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6863 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 597 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6874 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6885 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6896 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6907 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6918 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1171 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6930 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1328 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6942 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6953 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 6964 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1412 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_FCONST_0);
			}
#line 6975 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6987 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 6999 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1803 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
				JavaGenCast(info, ILMachineType_Void, ILMachineType_Decimal);
			}
#line 7011 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2037 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7022 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7035 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2061 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7045 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7058 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7071 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7084 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_20__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 7103 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 105 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFNULL, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 7120 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 345 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7131 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 462 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7142 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 597 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7153 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7164 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7175 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7186 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7197 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1171 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7209 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1328 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7221 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7232 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7243 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1412 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_FCONST_0);
			}
#line 7254 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7266 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7278 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1803 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
				JavaGenCast(info, ILMachineType_Void, ILMachineType_Decimal);
			}
#line 7290 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2037 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7301 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7314 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7327 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2061 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7337 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7350 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7363 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_21__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 7382 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 105 "jv_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				JavaGenJump(info, JAVA_OP_IFNULL, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_1);
				JavaGenJump(info, JAVA_OP_GOTO, &label2);
				JavaGenLabel(info, &label1);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
				JavaGenLabel(info, &label2);
			}
#line 7399 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 345 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7410 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 462 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7421 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 597 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7432 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7443 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7454 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7465 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7476 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1171 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7488 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1328 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7500 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7511 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7522 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1412 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_FCONST_0);
			}
#line 7533 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7545 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7557 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1803 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
				JavaGenCast(info, ILMachineType_Void, ILMachineType_Decimal);
			}
#line 7569 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2037 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7580 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7593 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7606 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7619 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2061 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7629 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7642 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast_split_22__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 65 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
			}
#line 7661 "jv_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 197 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7672 "jv_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 345 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7683 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 462 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7694 "jv_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 597 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7705 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7716 "jv_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 771 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7727 "jv_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7738 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7749 "jv_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1171 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7761 "jv_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1328 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7773 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 911 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7784 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1062 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ICONST_0);
			}
#line 7795 "jv_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1412 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_FCONST_0);
			}
#line 7806 "jv_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7818 "jv_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1521 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenAdjust(info, 1);
			}
#line 7830 "jv_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1803 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenAdjust(info, -1);
				JavaGenCast(info, ILMachineType_Void, ILMachineType_Decimal);
			}
#line 7842 "jv_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 2037 "jv_cast.tc"
			{
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7853 "jv_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7866 "jv_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7879 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7892 "jv_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 2096 "jv_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				JavaGenSimple(info, JAVA_OP_POP);
				JavaGenSimple(info, JAVA_OP_ACONST_NULL);
			}
#line 7905 "jv_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 2061 "jv_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7915 "jv_cast.c"
		}
		break;

		default: break;
	}
}

void JavaGenCast(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(fromType)
	{
		case ILMachineType_Void:
		{
			JavaGenCast_split_0__(info, fromType, toType);
		}
		break;

		case ILMachineType_Boolean:
		{
			JavaGenCast_split_1__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int8:
		{
			JavaGenCast_split_2__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt8:
		{
			JavaGenCast_split_3__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int16:
		{
			JavaGenCast_split_4__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt16:
		{
			JavaGenCast_split_5__(info, fromType, toType);
		}
		break;

		case ILMachineType_Char:
		{
			JavaGenCast_split_6__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int32:
		{
			JavaGenCast_split_7__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt32:
		{
			JavaGenCast_split_8__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int64:
		{
			JavaGenCast_split_9__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt64:
		{
			JavaGenCast_split_10__(info, fromType, toType);
		}
		break;

		case ILMachineType_NativeInt:
		{
			JavaGenCast_split_11__(info, fromType, toType);
		}
		break;

		case ILMachineType_NativeUInt:
		{
			JavaGenCast_split_12__(info, fromType, toType);
		}
		break;

		case ILMachineType_Float32:
		{
			JavaGenCast_split_13__(info, fromType, toType);
		}
		break;

		case ILMachineType_Float64:
		{
			JavaGenCast_split_14__(info, fromType, toType);
		}
		break;

		case ILMachineType_NativeFloat:
		{
			JavaGenCast_split_15__(info, fromType, toType);
		}
		break;

		case ILMachineType_Decimal:
		{
			JavaGenCast_split_16__(info, fromType, toType);
		}
		break;

		case ILMachineType_String:
		{
			JavaGenCast_split_17__(info, fromType, toType);
		}
		break;

		case ILMachineType_ObjectRef:
		{
			JavaGenCast_split_18__(info, fromType, toType);
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
			JavaGenCast_split_19__(info, fromType, toType);
		}
		break;

		case ILMachineType_ManagedPtr:
		{
			JavaGenCast_split_20__(info, fromType, toType);
		}
		break;

		case ILMachineType_TransientPtr:
		{
			JavaGenCast_split_21__(info, fromType, toType);
		}
		break;

		case ILMachineType_ManagedValue:
		{
			JavaGenCast_split_22__(info, fromType, toType);
		}
		break;

		default: break;
	}
}

