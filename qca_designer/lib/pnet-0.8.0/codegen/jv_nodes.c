/* jv_nodes.c.  Generated automatically by treecc */
#line 3 "jv_nodes.tc"

/*
 * jv_nodes.tc - Common definitions for Java node types and operations.
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
#line 26 "jv_nodes.c"

void JavaStackThen(ILGenInfo * info, ILLabel * label, ILMachineType type)
{
	switch(type)
	{
		case ILMachineType_Void:
		{
#line 57 "jv_nodes.tc"
			{
				/* Nothing to do here */
			}
#line 38 "jv_nodes.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 49 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 60 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 71 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 82 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 93 "jv_nodes.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 104 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 115 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 126 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 76 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenSimple(info, JAVA_OP_LCMP);
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 140 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 76 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenSimple(info, JAVA_OP_LCMP);
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 154 "jv_nodes.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 165 "jv_nodes.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 70 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenAdjust(info, -1);
			}
#line 176 "jv_nodes.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 84 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_FCONST_0);
				JavaGenSimple(info, JAVA_OP_FCMPL);
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenExtend(info, 1);
				JavaGenAdjust(info, -1);
			}
#line 190 "jv_nodes.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 93 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenSimple(info, JAVA_OP_DCMPL);
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 204 "jv_nodes.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 93 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenSimple(info, JAVA_OP_DCMPL);
				JavaGenJump(info, JAVA_OP_IFNE, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 218 "jv_nodes.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 101 "jv_nodes.tc"
			{
				if(info->useJavaLib)
				{
				    JavaGenSimple(info, JAVA_OP_LCONST_0);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 2);
					JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
									   "(Ljava/lang/Object;)Z");
					JavaGenJump(info, JAVA_OP_IFNE, label);
					JavaGenAdjust(info, -1);
				}
				else
				{
				    JavaGenSimple(info, JAVA_OP_ICONST_0);
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
					JavaGenCallByName(info, "System/Decimal", "op_Equality__VV",
									  "(LSystem/Decimal;LSystem/Decimal;)Z");
					JavaGenExtend(info, 1);
					JavaGenJump(info, JAVA_OP_IFNE, label);
					JavaGenAdjust(info, -1);
				}
			}
#line 249 "jv_nodes.c"
		}
		break;

		case ILMachineType_String:
		{
#line 126 "jv_nodes.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Boolean", "valueOf",
									  "(Ljava/lang/String;)Ljava/lang/Boolean;");
					JavaGenCallVirtual(info, "java/lang/Boolean", "booleanValue", "()Z");
					JavaGenJump(info, JAVA_OP_IFNE, label);
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/Boolean", "FromString",
									  "(LSystem/String;)Z");
					JavaGenJump(info, JAVA_OP_IFNE, label);
					JavaGenAdjust(info, -1);
				}
			}
#line 273 "jv_nodes.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 148 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNONNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 284 "jv_nodes.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 148 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNONNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 295 "jv_nodes.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 148 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNONNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 306 "jv_nodes.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 148 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNONNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 317 "jv_nodes.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 148 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNONNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 328 "jv_nodes.c"
		}
		break;

		default: break;
	}
}

void JavaStackElse(ILGenInfo * info, ILLabel * label, ILMachineType type)
{
	switch(type)
	{
		case ILMachineType_Void:
		{
#line 159 "jv_nodes.tc"
			{
				/* Nothing to do here */
			}
#line 346 "jv_nodes.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 357 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 368 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 379 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 390 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 401 "jv_nodes.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 412 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 423 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 434 "jv_nodes.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 178 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenSimple(info, JAVA_OP_LCMP);
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 448 "jv_nodes.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 178 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenSimple(info, JAVA_OP_LCMP);
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 462 "jv_nodes.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 473 "jv_nodes.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 172 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenAdjust(info, -1);
			}
#line 484 "jv_nodes.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 186 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_FCONST_0);
				JavaGenSimple(info, JAVA_OP_FCMPL);
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenExtend(info, 1);
				JavaGenAdjust(info, -1);
			}
#line 498 "jv_nodes.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 195 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenSimple(info, JAVA_OP_DCMPL);
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 512 "jv_nodes.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 195 "jv_nodes.tc"
			{
				JavaGenSimple(info, JAVA_OP_DCONST_0);
				JavaGenSimple(info, JAVA_OP_DCMPL);
				JavaGenJump(info, JAVA_OP_IFEQ, label);
				JavaGenExtend(info, 2);
				JavaGenAdjust(info, -2);
			}
#line 526 "jv_nodes.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 203 "jv_nodes.tc"
			{
				if(info->useJavaLib)
				{
				    JavaGenSimple(info, JAVA_OP_LCONST_0);
					JavaGenCallByName(info, "java/math/BigDecimal", "valueOf",
									  "(J)Ljava/math/BigDecimal;");
					JavaGenExtend(info, 2);
					JavaGenCallVirtual(info, "java/math/BigDecimal", "equals",
									   "(Ljava/lang/Object;)Z");
					JavaGenJump(info, JAVA_OP_IFEQ, label);
					JavaGenAdjust(info, -1);
				}
				else
				{
				    JavaGenSimple(info, JAVA_OP_ICONST_0);
					JavaGenCallByName(info, "System/Decimal", "op_Implicit__iV",
									  "(I)LSystem/Decimal;");
					JavaGenCallByName(info, "System/Decimal", "op_Equality__VV",
									  "(LSystem/Decimal;LSystem/Decimal;)Z");
					JavaGenExtend(info, 1);
					JavaGenJump(info, JAVA_OP_IFEQ, label);
					JavaGenAdjust(info, -1);
				}
			}
#line 557 "jv_nodes.c"
		}
		break;

		case ILMachineType_String:
		{
#line 228 "jv_nodes.tc"
			{
				if(info->useJavaLib)
				{
					JavaGenCallByName(info, "java/lang/Boolean", "valueOf",
									  "(Ljava/lang/String;)Ljava/lang/Boolean;");
					JavaGenCallVirtual(info, "java/lang/Boolean", "booleanValue", "()Z");
					JavaGenJump(info, JAVA_OP_IFEQ, label);
					JavaGenAdjust(info, -1);
				}
				else
				{
					JavaGenCallByName(info, "System/Boolean", "FromString",
									  "(LSystem/String;)Z");
					JavaGenJump(info, JAVA_OP_IFEQ, label);
					JavaGenAdjust(info, -1);
				}
			}
#line 581 "jv_nodes.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 250 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 592 "jv_nodes.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 250 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 603 "jv_nodes.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 250 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 614 "jv_nodes.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 250 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 625 "jv_nodes.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 250 "jv_nodes.tc"
			{
				JavaGenJump(info, JAVA_OP_IFNULL, label);
				JavaGenAdjust(info, -1);
			}
#line 636 "jv_nodes.c"
		}
		break;

		default: break;
	}
}

