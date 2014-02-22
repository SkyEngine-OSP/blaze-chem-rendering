/* cg_cast.c.  Generated automatically by treecc */
#line 3 "cg_cast.tc"

/*
 * cg_cast.tc - Cast operations.
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
#line 54 "cg_cast.tc"


static int DecimalToInt32(const ILDecimal *value, ILInt32 *result,
						  ILInt32 minValue, ILInt32 maxValue)
{
	ILDecimal truncValue;
	ILInt64 intValue;
	ILDecimalTruncate(&truncValue, value);
	if(!ILDecimalToInt64(&truncValue, &intValue))
	{
		return 0;
	}
	if(intValue < (ILInt64)minValue || intValue > (ILInt64)maxValue)
	{
		return 0;
	}
	*result = (ILInt32)intValue;
	return 1;
}

static int DecimalToUInt32(const ILDecimal *value, ILInt32 *result,
						   ILUInt32 maxValue)
{
	ILDecimal truncValue;
	ILUInt64 intValue;
	ILDecimalTruncate(&truncValue, value);
	if(!ILDecimalToUInt64(&truncValue, &intValue))
	{
		return 0;
	}
	if(intValue > (ILUInt64)maxValue)
	{
		return 0;
	}
	*result = (ILInt32)(ILUInt32)intValue;
	return 1;
}

#line 65 "cg_cast.c"

int ILGenCastConst_split_0__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 77 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1745 "cg_cast.tc"
			{
				return 0;
			}
#line 87 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1860 "cg_cast.tc"
			{
				return 0;
			}
#line 97 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1972 "cg_cast.tc"
			{
				return 0;
			}
#line 107 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2087 "cg_cast.tc"
			{
				return 0;
			}
#line 117 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2199 "cg_cast.tc"
			{
				return 0;
			}
#line 127 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2311 "cg_cast.tc"
			{
				return 0;
			}
#line 137 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2416 "cg_cast.tc"
			{
				return 0;
			}
#line 147 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2518 "cg_cast.tc"
			{
				return 0;
			}
#line 157 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2814 "cg_cast.tc"
			{
				return 0;
			}
#line 167 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2904 "cg_cast.tc"
			{
				return 0;
			}
#line 177 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2625 "cg_cast.tc"
			{
				return 0;
			}
#line 187 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2729 "cg_cast.tc"
			{
				return 0;
			}
#line 197 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2963 "cg_cast.tc"
			{
				return 0;
			}
#line 207 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3026 "cg_cast.tc"
			{
				return 0;
			}
#line 217 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3089 "cg_cast.tc"
			{
				return 0;
			}
#line 227 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3147 "cg_cast.tc"
			{
				return 0;
			}
#line 237 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 247 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 258 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 268 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 278 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 288 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 298 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_1__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 317 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1699 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 328 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1753 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 339 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1868 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 350 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1982 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 361 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2097 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 372 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2209 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 383 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2325 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 394 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2428 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 405 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2741 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 417 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2826 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 433 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2532 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 444 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2637 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 455 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2916 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 467 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2975 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 479 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3038 "cg_cast.tc"
			{
				value->un.r4Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 491 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3101 "cg_cast.tc"
			{
				ILDecimalFromInt32(&(value->un.decValue), value->un.i4Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 503 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 513 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 524 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 534 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 544 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 554 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 564 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_2__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 583 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 595 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1758 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 606 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1881 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 625 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1982 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 636 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2110 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 655 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2222 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 674 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2325 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 685 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2436 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 700 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2741 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 712 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2826 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 728 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2532 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 739 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2645 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 754 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2916 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 766 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2975 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 778 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3038 "cg_cast.tc"
			{
				value->un.r4Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 790 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3101 "cg_cast.tc"
			{
				ILDecimalFromInt32(&(value->un.decValue), value->un.i4Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 802 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 812 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 823 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 833 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 843 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 853 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 863 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_3__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 882 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 894 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1783 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 913 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1873 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 924 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1982 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 935 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2097 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 946 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2209 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 957 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2325 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 968 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2428 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 979 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2751 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 991 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2840 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 1003 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2532 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 1014 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2637 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 1025 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2926 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 1037 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2985 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 1049 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3048 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 1061 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3111 "cg_cast.tc"
			{
				ILDecimalFromUInt32(&(value->un.decValue), (ILUInt32)(value->un.i4Value));
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 1073 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 1083 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 1094 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1104 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1114 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1124 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1134 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_4__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1153 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 1165 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1765 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < (ILInt32)(-128) ||
					   value->un.i4Value > (ILInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 1185 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1881 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 1204 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1987 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 1215 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2110 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 1234 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2222 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 1253 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2325 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 1264 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2436 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 1279 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2741 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 1291 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2826 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 1307 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2532 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 1318 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2645 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 1333 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2916 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 1345 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2975 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 1357 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3038 "cg_cast.tc"
			{
				value->un.r4Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 1369 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3101 "cg_cast.tc"
			{
				ILDecimalFromInt32(&(value->un.decValue), value->un.i4Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 1381 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 1391 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 1402 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1412 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1422 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1432 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1442 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_5__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1461 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 1473 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1783 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 1492 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1897 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 1511 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2010 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 1530 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2102 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 1541 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2209 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 1552 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2325 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 1563 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2428 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 1574 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2751 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 1586 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2840 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 1598 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2532 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 1609 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2637 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 1620 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2926 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 1632 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2985 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 1644 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3048 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 1656 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3111 "cg_cast.tc"
			{
				ILDecimalFromUInt32(&(value->un.decValue), (ILUInt32)(value->un.i4Value));
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 1668 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 1678 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 1689 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1699 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1709 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1719 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1729 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_6__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1748 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 1760 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1783 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 1779 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1897 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 1798 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2010 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 1817 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2097 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 1828 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2214 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 1839 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2325 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 1850 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2428 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 1861 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2751 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 1873 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2840 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 1885 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2532 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 1896 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2637 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 1907 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2926 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 1919 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2985 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 1931 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3048 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 1943 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3111 "cg_cast.tc"
			{
				ILDecimalFromUInt32(&(value->un.decValue), (ILUInt32)(value->un.i4Value));
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 1955 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 1965 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 1976 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1986 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 1996 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2006 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2016 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_7__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2035 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 2047 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1765 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < (ILInt32)(-128) ||
					   value->un.i4Value > (ILInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 2067 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1881 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 2086 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1993 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < (ILInt32)(-32768) ||
					   value->un.i4Value > (ILInt32)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 2106 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2110 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 2125 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2222 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 2144 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2343 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 2155 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2436 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 2170 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2741 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 2182 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2826 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 2198 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2532 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 2209 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2645 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 2224 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2916 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 2236 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2975 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 2248 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3038 "cg_cast.tc"
			{
				value->un.r4Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 2260 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3101 "cg_cast.tc"
			{
				ILDecimalFromInt32(&(value->un.decValue), value->un.i4Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 2272 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 2282 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 2293 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2303 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2313 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2323 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2333 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_8__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2352 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 2364 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1783 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 2383 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1897 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 2402 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2010 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 2421 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2124 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 2440 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2236 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 2459 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2331 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)0x7FFFFFFF)
					{
						return 0;
					}
				}
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 2477 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2445 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 2488 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2751 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 2500 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2840 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 2512 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2538 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)0x7FFFFFFF)
					{
						return 0;
					}
				}
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 2530 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2637 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 2541 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2926 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 2553 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2985 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 2565 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3048 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 2577 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3111 "cg_cast.tc"
			{
				ILDecimalFromUInt32(&(value->un.decValue), (ILUInt32)(value->un.i4Value));
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 2589 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 2599 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 2610 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2620 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2630 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2640 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2650 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_9__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2669 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1720 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i8Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 2681 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1796 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value < (ILInt64)(-128) ||
					   value->un.i8Value > (ILInt64)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i8Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 2701 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1910 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value < 0 || value->un.i8Value > (ILInt64)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i8Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 2720 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2023 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value < (ILInt64)(-32768) ||
					   value->un.i8Value > (ILInt64)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i8Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 2740 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2137 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value < 0 || value->un.i8Value > (ILInt64)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i8Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 2759 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2249 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value < 0 || value->un.i8Value > (ILInt64)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i8Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 2778 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2348 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value < (ILInt64)IL_MIN_INT32 ||
					   value->un.i8Value > (ILInt64)IL_MAX_INT32)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.i8Value);
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 2798 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2450 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i8Value < 0 ||
					   value->un.i8Value > (ILInt64)IL_MAX_UINT32)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.i8Value);
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 2818 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2757 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 2829 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2851 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i8Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 2844 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2555 "cg_cast.tc"
			{
				if(((ILInt64)(ILInt32)(value->un.i8Value)) != value->un.i8Value)
				{
					/* Since we don't know the size of native integers on the
					   final machine, we deny this type of constant cast.
					   Otherwise we will get different behaviours on 32-bit
					   and 64-bit platforms */
					return 0;
				}
				value->un.i4Value = (ILInt32)(value->un.i8Value);
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 2864 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2659 "cg_cast.tc"
			{
				if(((ILInt64)(ILInt32)(value->un.i8Value)) != value->un.i8Value)
				{
					/* Since we don't know the size of native integers on the
					   final machine, we deny this type of constant cast.
					   Otherwise we will get different behaviours on 32-bit
					   and 64-bit platforms */
					return 0;
				}
				value->un.i4Value = (ILUInt32)(value->un.i8Value);
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 2884 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2932 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.i8Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 2896 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2991 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.i8Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 2908 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3054 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.i8Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 2920 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3117 "cg_cast.tc"
			{
				ILDecimalFromInt64(&(value->un.decValue), value->un.i8Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 2932 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 2942 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 2953 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2963 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2973 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2983 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 2993 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_10__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3012 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1720 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i8Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 3024 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1810 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i8Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 3043 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1923 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i8Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 3062 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2037 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i8Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 3081 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2150 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i8Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 3100 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2262 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i8Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 3119 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2362 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)0x7FFFFFFF)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.i8Value);
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 3138 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2464 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)IL_MAX_UINT32)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.i8Value);
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 3157 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2762 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt64)(value->un.i8Value)) > (ILUInt64)IL_MAX_INT64)
					{
						return 0;
					}
				}
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 3175 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2846 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 3186 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2569 "cg_cast.tc"
			{
				if(((ILUInt64)(ILUInt32)(value->un.i8Value)) !=
							((ILUInt64)(value->un.i8Value)))
				{
					/* Since we don't know the size of native integers on the
					   final machine, we deny this type of constant cast.
					   Otherwise we will get different behaviours on 32-bit
					   and 64-bit platforms */
					return 0;
				}
				value->un.i4Value = (ILInt32)(value->un.i8Value);
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 3207 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2673 "cg_cast.tc"
			{
				if(((ILUInt64)(ILUInt32)(value->un.i8Value)) !=
							((ILUInt64)(value->un.i8Value)))
				{
					/* Since we don't know the size of native integers on the
					   final machine, we deny this type of constant cast.
					   Otherwise we will get different behaviours on 32-bit
					   and 64-bit platforms */
					return 0;
				}
				value->un.i4Value = (ILUInt32)(value->un.i8Value);
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 3228 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2938 "cg_cast.tc"
			{
				value->un.r4Value =
					(ILFloat)(ILUInt64ToFloat((ILUInt64)(value->un.i8Value)));
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 3241 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2997 "cg_cast.tc"
			{
				value->un.r8Value =
					(ILDouble)(ILUInt64ToFloat((ILUInt64)(value->un.i8Value)));
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 3254 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3060 "cg_cast.tc"
			{
				value->un.r8Value =
					(ILDouble)(ILUInt64ToFloat((ILUInt64)(value->un.i8Value)));
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 3267 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3123 "cg_cast.tc"
			{
				ILDecimalFromUInt64(&(value->un.decValue), (ILUInt64)(value->un.i8Value));
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 3279 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 3289 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 3300 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3310 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3320 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3330 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3340 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_11__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3359 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 3371 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1765 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < (ILInt32)(-128) ||
					   value->un.i4Value > (ILInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 3391 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1881 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 3410 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1993 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < (ILInt32)(-32768) ||
					   value->un.i4Value > (ILInt32)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 3430 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2110 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 3449 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2222 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(value->un.i4Value < 0 || value->un.i4Value > (ILInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 3468 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2325 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 3479 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2436 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 3494 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2741 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 3506 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2826 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->un.i8Value = (ILInt64)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 3522 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2550 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 3533 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2645 "cg_cast.tc"
			{
				if(info->overflowInsns && value->un.i4Value < 0)
				{
					return 0;
				}
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 3548 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2916 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 3560 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2975 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 3572 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3038 "cg_cast.tc"
			{
				value->un.r4Value = (ILDouble)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 3584 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3101 "cg_cast.tc"
			{
				ILDecimalFromInt32(&(value->un.decValue), value->un.i4Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 3596 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 3606 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 3617 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3627 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3637 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3647 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3657 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_12__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3676 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 3688 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1783 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)127)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt8)(value->un.i4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 3707 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1897 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)255)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(value->un.i4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 3726 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2010 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)32767)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 3745 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2124 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 3764 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2236 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)65535)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(value->un.i4Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 3783 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2331 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)0x7FFFFFFF)
					{
						return 0;
					}
				}
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 3801 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2428 "cg_cast.tc"
			{
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 3812 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2751 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 3824 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2840 "cg_cast.tc"
			{
				value->un.i8Value = (ILInt64)(ILUInt64)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 3836 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2538 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(((ILUInt32)(value->un.i4Value)) > (ILUInt32)0x7FFFFFFF)
					{
						return 0;
					}
				}
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 3854 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2654 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 3865 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2926 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 3877 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 2985 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 3889 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3048 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(ILUInt32)(value->un.i4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 3901 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3111 "cg_cast.tc"
			{
				ILDecimalFromUInt32(&(value->un.decValue), (ILUInt32)(value->un.i4Value));
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 3913 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 3923 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 3934 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3944 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3954 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3964 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3974 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_13__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 3993 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1726 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.r4Value != (ILFloat)0.0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 4005 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1823 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float32,
										  ILMachineType_Int32) &&
						   ILGenCastConst(info, value, ILMachineType_Int32,
						   				  ILMachineType_Int8);
				}
				value->un.i4Value = (ILInt32)(ILInt8)(ILInt32)(value->un.r4Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 4024 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1936 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float32,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_UInt8);
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(ILUInt32)(value->un.r4Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 4043 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2050 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float32,
										  ILMachineType_Int32) &&
						   ILGenCastConst(info, value, ILMachineType_Int32,
						   				  ILMachineType_Int16);
				}
				value->un.i4Value = (ILInt32)(ILInt16)(ILInt32)(value->un.r4Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 4062 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2163 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float32,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_UInt16);
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(ILUInt32)(value->un.r4Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 4081 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2275 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float32,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_Char);
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(ILUInt32)(value->un.r4Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 4100 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2375 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r4Value) ||
					   value->un.r4Value <= (ILNativeFloat)(-2147483649.0) ||
					   value->un.r4Value >= (ILNativeFloat)2147483648.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.r4Value);
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 4121 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2477 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r4Value) ||
					   value->un.r4Value < (ILNativeFloat)0.0 ||
					   value->un.r4Value >= (ILNativeFloat)4294967296.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.r4Value);
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 4142 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2774 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					value->valueType = ILMachineType_Int64;
					return ILFloatToInt64Ovf(&(value->un.i8Value), value->un.r4Value);
				}
				else
				{
					value->un.i8Value = (ILInt64)(value->un.r4Value);
					value->valueType = ILMachineType_Int64;
					return 1;
				}
			}
#line 4162 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2860 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					value->valueType = ILMachineType_UInt64;
					return ILFloatToUInt64Ovf((ILUInt64 *)&(value->un.i8Value),
											  value->un.r4Value);
				}
				else
				{
					value->un.i8Value = (ILInt64)ILFloatToUInt64(value->un.r4Value);
					value->valueType = ILMachineType_UInt64;
					return 1;
				}
			}
#line 4183 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2584 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r4Value) ||
					   value->un.r4Value <= (ILNativeFloat)(-2147483649.0) ||
					   value->un.r4Value >= (ILNativeFloat)2147483648.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.r4Value);
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 4204 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2688 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r4Value) ||
					   value->un.r4Value < (ILNativeFloat)0.0 ||
					   value->un.r4Value >= (ILNativeFloat)4294967296.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.r4Value);
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 4225 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2945 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 4236 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3004 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.r4Value);
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 4248 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3067 "cg_cast.tc"
			{
				value->un.r8Value = (ILDouble)(value->un.r4Value);
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 4260 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3129 "cg_cast.tc"
			{
				ILDecimalFromFloat(&(value->un.decValue), value->un.r4Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 4272 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 4282 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 4293 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4303 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4313 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4323 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4333 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_14__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4352 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1733 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.r8Value != (ILDouble)0.0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 4364 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1837 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_Int32) &&
						   ILGenCastConst(info, value, ILMachineType_Int32,
						   				  ILMachineType_Int8);
				}
				value->un.i4Value = (ILInt32)(ILInt8)(ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 4383 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1950 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_UInt8);
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 4402 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2064 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_Int32) &&
						   ILGenCastConst(info, value, ILMachineType_Int32,
						   				  ILMachineType_Int16);
				}
				value->un.i4Value = (ILInt32)(ILInt16)(ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 4421 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2177 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_UInt16);
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 4440 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2289 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_Char);
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 4459 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2391 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value <= (ILNativeFloat)(-2147483649.0) ||
					   value->un.r8Value >= (ILNativeFloat)2147483648.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 4480 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2493 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value < (ILNativeFloat)0.0 ||
					   value->un.r8Value >= (ILNativeFloat)4294967296.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 4501 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2789 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					value->valueType = ILMachineType_Int64;
					return ILFloatToInt64Ovf(&(value->un.i8Value), value->un.r8Value);
				}
				else
				{
					value->un.i8Value = (ILInt64)(value->un.r8Value);
					value->valueType = ILMachineType_Int64;
					return 1;
				}
			}
#line 4521 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2876 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					value->valueType = ILMachineType_UInt64;
					return ILFloatToUInt64Ovf((ILUInt64 *)&(value->un.i8Value),
											  value->un.r8Value);
				}
				else
				{
					value->un.i8Value = (ILInt64)ILFloatToUInt64(value->un.r8Value);
					value->valueType = ILMachineType_UInt64;
					return 1;
				}
			}
#line 4542 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2600 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value <= (ILNativeFloat)(-2147483649.0) ||
					   value->un.r8Value >= (ILNativeFloat)2147483648.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 4563 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2704 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value < (ILNativeFloat)0.0 ||
					   value->un.r8Value >= (ILNativeFloat)4294967296.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 4584 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2951 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.r8Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 4596 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3010 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 4607 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3073 "cg_cast.tc"
			{
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 4618 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3136 "cg_cast.tc"
			{
				ILDecimalFromDouble(&(value->un.decValue), value->un.r8Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 4630 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 4640 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 4651 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4661 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4671 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4681 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4691 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_15__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 4710 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1733 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.r8Value != (ILDouble)0.0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 4722 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1837 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_Int32) &&
						   ILGenCastConst(info, value, ILMachineType_Int32,
						   				  ILMachineType_Int8);
				}
				value->un.i4Value = (ILInt32)(ILInt8)(ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 4741 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1950 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_UInt8);
				}
				value->un.i4Value = (ILInt32)(ILUInt8)(ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 4760 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2064 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_Int32) &&
						   ILGenCastConst(info, value, ILMachineType_Int32,
						   				  ILMachineType_Int16);
				}
				value->un.i4Value = (ILInt32)(ILInt16)(ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 4779 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2177 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_UInt16);
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 4798 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2289 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					return ILGenCastConst(info, value, ILMachineType_Float64,
										  ILMachineType_UInt32) &&
						   ILGenCastConst(info, value, ILMachineType_UInt32,
						   				  ILMachineType_Char);
				}
				value->un.i4Value = (ILInt32)(ILUInt16)(ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 4817 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2391 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value <= (ILNativeFloat)(-2147483649.0) ||
					   value->un.r8Value >= (ILNativeFloat)2147483648.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 4838 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2493 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value < (ILNativeFloat)0.0 ||
					   value->un.r8Value >= (ILNativeFloat)4294967296.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 4859 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2789 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					value->valueType = ILMachineType_Int64;
					return ILFloatToInt64Ovf(&(value->un.i8Value), value->un.r8Value);
				}
				else
				{
					value->un.i8Value = (ILInt64)(value->un.r8Value);
					value->valueType = ILMachineType_Int64;
					return 1;
				}
			}
#line 4879 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2876 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					value->valueType = ILMachineType_UInt64;
					return ILFloatToUInt64Ovf((ILUInt64 *)&(value->un.i8Value),
											  value->un.r8Value);
				}
				else
				{
					value->un.i8Value = (ILInt64)ILFloatToUInt64(value->un.r8Value);
					value->valueType = ILMachineType_UInt64;
					return 1;
				}
			}
#line 4900 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2600 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value <= (ILNativeFloat)(-2147483649.0) ||
					   value->un.r8Value >= (ILNativeFloat)2147483648.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILInt32)(value->un.r8Value);
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 4921 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2704 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					if(!ILNativeFloatIsFinite(value->un.r8Value) ||
					   value->un.r8Value < (ILNativeFloat)0.0 ||
					   value->un.r8Value >= (ILNativeFloat)4294967296.0)
					{
						return 0;
					}
				}
				value->un.i4Value = (ILUInt32)(value->un.r8Value);
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 4942 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2951 "cg_cast.tc"
			{
				value->un.r4Value = (ILFloat)(value->un.r8Value);
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 4954 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3015 "cg_cast.tc"
			{
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 4965 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3078 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 4976 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3136 "cg_cast.tc"
			{
				ILDecimalFromDouble(&(value->un.decValue), value->un.r8Value);
				value->valueType = ILMachineType_Decimal;
				return 1;
			}
#line 4988 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 4998 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 5009 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5019 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5029 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5039 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5049 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_16__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5068 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1739 "cg_cast.tc"
			{
				value->un.i4Value = !ILDecimalIsZero(&(value->un.decValue));
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 5080 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1850 "cg_cast.tc"
			{
				if(!DecimalToInt32(&(value->un.decValue), &(value->un.i4Value),
								   -128, 127))
				{
					return 0;
				}
				value->valueType = ILMachineType_Int8;
				return 1;
			}
#line 5096 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1963 "cg_cast.tc"
			{
				if(!DecimalToUInt32(&(value->un.decValue), &(value->un.i4Value), 255))
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt8;
				return 1;
			}
#line 5111 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2077 "cg_cast.tc"
			{
				if(!DecimalToInt32(&(value->un.decValue), &(value->un.i4Value),
								   -32768, 32767))
				{
					return 0;
				}
				value->valueType = ILMachineType_Int16;
				return 1;
			}
#line 5127 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2190 "cg_cast.tc"
			{
				if(!DecimalToUInt32(&(value->un.decValue), &(value->un.i4Value), 65535))
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt16;
				return 1;
			}
#line 5142 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2302 "cg_cast.tc"
			{
				if(!DecimalToUInt32(&(value->un.decValue), &(value->un.i4Value), 65535))
				{
					return 0;
				}
				value->valueType = ILMachineType_Char;
				return 1;
			}
#line 5157 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2406 "cg_cast.tc"
			{
				if(!DecimalToInt32(&(value->un.decValue), &(value->un.i4Value),
								   IL_MIN_INT32, IL_MAX_INT32))
				{
					return 0;
				}
				value->valueType = ILMachineType_Int32;
				return 1;
			}
#line 5173 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2508 "cg_cast.tc"
			{
				if(!DecimalToUInt32(&(value->un.decValue), &(value->un.i4Value),
								    IL_MAX_UINT32))
				{
					return 0;
				}
				value->valueType = ILMachineType_UInt32;
				return 1;
			}
#line 5189 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2803 "cg_cast.tc"
			{
				ILDecimal truncValue;
				ILDecimalTruncate(&truncValue, &(value->un.decValue));
				if(!ILDecimalToInt64(&truncValue, &(value->un.i8Value)))
				{
					return 0;
				}
				value->valueType = ILMachineType_Int64;
				return 1;
			}
#line 5206 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2891 "cg_cast.tc"
			{
				ILDecimal truncValue;
				ILUInt64 intValue;
				ILDecimalTruncate(&truncValue, &(value->un.decValue));
				if(!ILDecimalToUInt64(&truncValue, &intValue))
				{
					return 0;
				}
				value->un.i8Value = (ILInt64)intValue;
				value->valueType = ILMachineType_UInt64;
				return 1;
			}
#line 5225 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2615 "cg_cast.tc"
			{
				if(!DecimalToInt32(&(value->un.decValue), &(value->un.i4Value),
								   IL_MIN_INT32, IL_MAX_INT32))
				{
					return 0;
				}
				value->valueType = ILMachineType_NativeInt;
				return 1;
			}
#line 5241 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2719 "cg_cast.tc"
			{
				if(!DecimalToUInt32(&(value->un.decValue), &(value->un.i4Value),
								    IL_MAX_UINT32))
				{
					return 0;
				}
				value->valueType = ILMachineType_NativeUInt;
				return 1;
			}
#line 5257 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2957 "cg_cast.tc"
			{
				value->un.r4Value = ILDecimalToFloat(&(value->un.decValue));
				value->valueType = ILMachineType_Float32;
				return 1;
			}
#line 5269 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3020 "cg_cast.tc"
			{
				value->un.r8Value = ILDecimalToDouble(&(value->un.decValue));
				value->valueType = ILMachineType_Float64;
				return 1;
			}
#line 5281 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3083 "cg_cast.tc"
			{
				value->un.r8Value = ILDecimalToDouble(&(value->un.decValue));
				value->valueType = ILMachineType_NativeFloat;
				return 1;
			}
#line 5293 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3142 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 5304 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 5314 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 5325 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5335 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5345 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5355 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5365 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_17__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5384 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1745 "cg_cast.tc"
			{
				return 0;
			}
#line 5394 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1860 "cg_cast.tc"
			{
				return 0;
			}
#line 5404 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1972 "cg_cast.tc"
			{
				return 0;
			}
#line 5414 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2087 "cg_cast.tc"
			{
				return 0;
			}
#line 5424 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2199 "cg_cast.tc"
			{
				return 0;
			}
#line 5434 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2311 "cg_cast.tc"
			{
				return 0;
			}
#line 5444 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2416 "cg_cast.tc"
			{
				return 0;
			}
#line 5454 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2518 "cg_cast.tc"
			{
				return 0;
			}
#line 5464 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2814 "cg_cast.tc"
			{
				return 0;
			}
#line 5474 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2904 "cg_cast.tc"
			{
				return 0;
			}
#line 5484 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2625 "cg_cast.tc"
			{
				return 0;
			}
#line 5494 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2729 "cg_cast.tc"
			{
				return 0;
			}
#line 5504 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2963 "cg_cast.tc"
			{
				return 0;
			}
#line 5514 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3026 "cg_cast.tc"
			{
				return 0;
			}
#line 5524 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3089 "cg_cast.tc"
			{
				return 0;
			}
#line 5534 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3147 "cg_cast.tc"
			{
				return 0;
			}
#line 5544 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3155 "cg_cast.tc"
			{
				/* Nothing to do here */
				return 1;
			}
#line 5555 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 5566 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5576 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5586 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5596 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5606 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_18__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5625 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1745 "cg_cast.tc"
			{
				return 0;
			}
#line 5635 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1860 "cg_cast.tc"
			{
				return 0;
			}
#line 5645 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1972 "cg_cast.tc"
			{
				return 0;
			}
#line 5655 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2087 "cg_cast.tc"
			{
				return 0;
			}
#line 5665 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2199 "cg_cast.tc"
			{
				return 0;
			}
#line 5675 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2311 "cg_cast.tc"
			{
				return 0;
			}
#line 5685 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2416 "cg_cast.tc"
			{
				return 0;
			}
#line 5695 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2518 "cg_cast.tc"
			{
				return 0;
			}
#line 5705 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2814 "cg_cast.tc"
			{
				return 0;
			}
#line 5715 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2904 "cg_cast.tc"
			{
				return 0;
			}
#line 5725 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2625 "cg_cast.tc"
			{
				return 0;
			}
#line 5735 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2729 "cg_cast.tc"
			{
				return 0;
			}
#line 5745 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2963 "cg_cast.tc"
			{
				return 0;
			}
#line 5755 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3026 "cg_cast.tc"
			{
				return 0;
			}
#line 5765 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3089 "cg_cast.tc"
			{
				return 0;
			}
#line 5775 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3147 "cg_cast.tc"
			{
				return 0;
			}
#line 5785 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3160 "cg_cast.tc"
			{
				/* Casting "null" to a string */
				value->valueType = ILMachineType_String;
				value->un.strValue.str = 0;
				value->un.strValue.len = 0;
				return 1;
			}
#line 5799 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3176 "cg_cast.tc"
			{
				/* Normally this is casting "null", which is OK */
				return 1;
			}
#line 5810 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 3191 "cg_cast.tc"
			{
				/* Normally this is casting "null", which is OK */
				value->valueType = ILMachineType_UnmanagedPtr;
				value->un.i4Value = 0;
				return 1;
			}
#line 5823 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5833 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5843 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5853 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_19__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 5872 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1713 "cg_cast.tc"
			{
				value->un.i4Value = (value->un.i4Value != 0);
				value->valueType = ILMachineType_Boolean;
				return 1;
			}
#line 5884 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1860 "cg_cast.tc"
			{
				return 0;
			}
#line 5894 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1972 "cg_cast.tc"
			{
				return 0;
			}
#line 5904 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2087 "cg_cast.tc"
			{
				return 0;
			}
#line 5914 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2199 "cg_cast.tc"
			{
				return 0;
			}
#line 5924 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2311 "cg_cast.tc"
			{
				return 0;
			}
#line 5934 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2416 "cg_cast.tc"
			{
				return 0;
			}
#line 5944 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2518 "cg_cast.tc"
			{
				return 0;
			}
#line 5954 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2814 "cg_cast.tc"
			{
				return 0;
			}
#line 5964 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2904 "cg_cast.tc"
			{
				return 0;
			}
#line 5974 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2625 "cg_cast.tc"
			{
				return 0;
			}
#line 5984 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2729 "cg_cast.tc"
			{
				return 0;
			}
#line 5994 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2963 "cg_cast.tc"
			{
				return 0;
			}
#line 6004 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3026 "cg_cast.tc"
			{
				return 0;
			}
#line 6014 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3089 "cg_cast.tc"
			{
				return 0;
			}
#line 6024 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3147 "cg_cast.tc"
			{
				return 0;
			}
#line 6034 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 6044 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 6055 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 3191 "cg_cast.tc"
			{
				/* Normally this is casting "null", which is OK */
				value->valueType = ILMachineType_UnmanagedPtr;
				value->un.i4Value = 0;
				return 1;
			}
#line 6068 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6078 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6088 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6098 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_20__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6117 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1745 "cg_cast.tc"
			{
				return 0;
			}
#line 6127 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1860 "cg_cast.tc"
			{
				return 0;
			}
#line 6137 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1972 "cg_cast.tc"
			{
				return 0;
			}
#line 6147 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2087 "cg_cast.tc"
			{
				return 0;
			}
#line 6157 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2199 "cg_cast.tc"
			{
				return 0;
			}
#line 6167 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2311 "cg_cast.tc"
			{
				return 0;
			}
#line 6177 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2416 "cg_cast.tc"
			{
				return 0;
			}
#line 6187 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2518 "cg_cast.tc"
			{
				return 0;
			}
#line 6197 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2814 "cg_cast.tc"
			{
				return 0;
			}
#line 6207 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2904 "cg_cast.tc"
			{
				return 0;
			}
#line 6217 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2625 "cg_cast.tc"
			{
				return 0;
			}
#line 6227 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2729 "cg_cast.tc"
			{
				return 0;
			}
#line 6237 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2963 "cg_cast.tc"
			{
				return 0;
			}
#line 6247 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3026 "cg_cast.tc"
			{
				return 0;
			}
#line 6257 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3089 "cg_cast.tc"
			{
				return 0;
			}
#line 6267 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3147 "cg_cast.tc"
			{
				return 0;
			}
#line 6277 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 6287 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 6298 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6308 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6318 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6328 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6338 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_21__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6357 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1745 "cg_cast.tc"
			{
				return 0;
			}
#line 6367 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1860 "cg_cast.tc"
			{
				return 0;
			}
#line 6377 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1972 "cg_cast.tc"
			{
				return 0;
			}
#line 6387 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2087 "cg_cast.tc"
			{
				return 0;
			}
#line 6397 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2199 "cg_cast.tc"
			{
				return 0;
			}
#line 6407 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2311 "cg_cast.tc"
			{
				return 0;
			}
#line 6417 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2416 "cg_cast.tc"
			{
				return 0;
			}
#line 6427 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2518 "cg_cast.tc"
			{
				return 0;
			}
#line 6437 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2814 "cg_cast.tc"
			{
				return 0;
			}
#line 6447 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2904 "cg_cast.tc"
			{
				return 0;
			}
#line 6457 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2625 "cg_cast.tc"
			{
				return 0;
			}
#line 6467 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2729 "cg_cast.tc"
			{
				return 0;
			}
#line 6477 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2963 "cg_cast.tc"
			{
				return 0;
			}
#line 6487 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3026 "cg_cast.tc"
			{
				return 0;
			}
#line 6497 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3089 "cg_cast.tc"
			{
				return 0;
			}
#line 6507 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3147 "cg_cast.tc"
			{
				return 0;
			}
#line 6517 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 6527 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 6538 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6548 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6558 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6568 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6578 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst_split_22__(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6597 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1745 "cg_cast.tc"
			{
				return 0;
			}
#line 6607 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1860 "cg_cast.tc"
			{
				return 0;
			}
#line 6617 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1972 "cg_cast.tc"
			{
				return 0;
			}
#line 6627 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 2087 "cg_cast.tc"
			{
				return 0;
			}
#line 6637 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 2199 "cg_cast.tc"
			{
				return 0;
			}
#line 6647 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 2311 "cg_cast.tc"
			{
				return 0;
			}
#line 6657 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 2416 "cg_cast.tc"
			{
				return 0;
			}
#line 6667 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 2518 "cg_cast.tc"
			{
				return 0;
			}
#line 6677 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 2814 "cg_cast.tc"
			{
				return 0;
			}
#line 6687 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 2904 "cg_cast.tc"
			{
				return 0;
			}
#line 6697 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 2625 "cg_cast.tc"
			{
				return 0;
			}
#line 6707 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 2729 "cg_cast.tc"
			{
				return 0;
			}
#line 6717 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 2963 "cg_cast.tc"
			{
				return 0;
			}
#line 6727 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 3026 "cg_cast.tc"
			{
				return 0;
			}
#line 6737 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 3089 "cg_cast.tc"
			{
				return 0;
			}
#line 6747 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 3147 "cg_cast.tc"
			{
				return 0;
			}
#line 6757 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 3168 "cg_cast.tc"
			{
				return 0;
			}
#line 6767 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 3181 "cg_cast.tc"
			{
				/* Nothing else can be cast as a constant in this way */
				return 0;
			}
#line 6778 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6788 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6798 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6808 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1691 "cg_cast.tc"
			{
				return 0;
			}
#line 6818 "cg_cast.c"
		}
		break;

		default: break;
	}
	return (0);
}

int ILGenCastConst(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType)
{
	switch(fromType)
	{
		case ILMachineType_Void:
		{
			return ILGenCastConst_split_0__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Boolean:
		{
			return ILGenCastConst_split_1__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Int8:
		{
			return ILGenCastConst_split_2__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_UInt8:
		{
			return ILGenCastConst_split_3__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Int16:
		{
			return ILGenCastConst_split_4__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_UInt16:
		{
			return ILGenCastConst_split_5__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Char:
		{
			return ILGenCastConst_split_6__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Int32:
		{
			return ILGenCastConst_split_7__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_UInt32:
		{
			return ILGenCastConst_split_8__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Int64:
		{
			return ILGenCastConst_split_9__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_UInt64:
		{
			return ILGenCastConst_split_10__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_NativeInt:
		{
			return ILGenCastConst_split_11__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_NativeUInt:
		{
			return ILGenCastConst_split_12__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Float32:
		{
			return ILGenCastConst_split_13__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Float64:
		{
			return ILGenCastConst_split_14__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_NativeFloat:
		{
			return ILGenCastConst_split_15__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_Decimal:
		{
			return ILGenCastConst_split_16__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_String:
		{
			return ILGenCastConst_split_17__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_ObjectRef:
		{
			return ILGenCastConst_split_18__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
			return ILGenCastConst_split_19__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_ManagedPtr:
		{
			return ILGenCastConst_split_20__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_TransientPtr:
		{
			return ILGenCastConst_split_21__(info, value, fromType, toType);
		}
		break;

		case ILMachineType_ManagedValue:
		{
			return ILGenCastConst_split_22__(info, value, fromType, toType);
		}
		break;

		default: break;
	}
	return (0);
}

void ILGenCast_split_0__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 98 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 6984 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 111 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 6995 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 204 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 7006 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 292 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 7017 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 358 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 7028 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 427 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 7039 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 427 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 7050 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 550 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 7061 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 625 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenAdjust(info, 1);
			}
#line 7072 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 724 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
				ILGenAdjust(info, 1);
			}
#line 7084 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 799 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
				ILGenAdjust(info, 1);
			}
#line 7096 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 912 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I);
				ILGenAdjust(info, 1);
			}
#line 7108 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1003 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_U);
				ILGenAdjust(info, 1);
			}
#line 7120 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1091 "cg_cast.tc"
			{
				ILGenLoadFloat32(info, (ILFloat)0.0);
				ILGenAdjust(info, 1);
			}
#line 7131 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1152 "cg_cast.tc"
			{
				ILGenLoadFloat32(info, (ILFloat)0.0);
				ILGenAdjust(info, 1);
			}
#line 7142 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1213 "cg_cast.tc"
			{
				ILGenLoadFloat32(info, (ILFloat)0.0);
				ILGenAdjust(info, 1);
			}
#line 7153 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1315 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
				ILGenAdjust(info, 1);
			}
#line 7166 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1483 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_LDNULL);
				ILGenAdjust(info, 1);
			}
#line 7177 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1637 "cg_cast.tc"
			{
				/* The default object reference value is "null" */
				ILGenSimple(info, IL_OP_LDNULL);
				ILGenAdjust(info, 1);
			}
#line 7189 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1643 "cg_cast.tc"
			{
				/* The default pointer value is zero */
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I);
				ILGenAdjust(info, 1);
			}
#line 7202 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1637 "cg_cast.tc"
			{
				/* The default object reference value is "null" */
				ILGenSimple(info, IL_OP_LDNULL);
				ILGenAdjust(info, 1);
			}
#line 7214 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1637 "cg_cast.tc"
			{
				/* The default object reference value is "null" */
				ILGenSimple(info, IL_OP_LDNULL);
				ILGenAdjust(info, 1);
			}
#line 7226 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1637 "cg_cast.tc"
			{
				/* The default object reference value is "null" */
				ILGenSimple(info, IL_OP_LDNULL);
				ILGenAdjust(info, 1);
			}
#line 7238 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_1__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 7257 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 116 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7267 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 210 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7277 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 298 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7287 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 366 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7297 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7307 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7317 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 561 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7327 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 634 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7337 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 7348 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 829 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 7359 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 929 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 7370 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1020 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 7381 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1114 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 7392 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1177 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 7403 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 7414 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1323 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS cannot convert from int8 to decimal, so use int32 instead */
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
				}
				else
				{
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int8)");
				}
			}
#line 7434 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1488 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
								"[.library]System.Boolean::ToString(bool)");
			}
#line 7445 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7458 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7471 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7484 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7497 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7510 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_2__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 7529 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 7548 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 210 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7558 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 7575 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 366 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7585 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 7603 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 7621 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 561 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7631 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 640 "cg_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
			}
#line 7645 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 7656 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 811 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U8);
				}
			}
#line 7674 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 920 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 7685 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1011 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 7696 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1102 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 7707 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1162 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 7718 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1220 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 7729 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1323 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS cannot convert from int8 to decimal, so use int32 instead */
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
				}
				else
				{
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int8)");
				}
			}
#line 7749 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1493 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the SByte class, so use Int32 instead */
					ILGenCallByName(info, "class [.library]System.String "
												"[.library]System.Int32::ToString(int32)");
				}
				else
				{
					ILGenCallByName(info, "class [.library]System.String "
											"[.library]System.SByte::ToString(int8)");
				}
			}
#line 7769 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7782 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7795 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7808 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7821 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 7834 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_3__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 7853 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 7872 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 237 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 7889 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 298 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7899 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 366 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7909 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7919 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7929 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 561 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7939 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 634 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 7949 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 7960 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 829 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 7971 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 929 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 7982 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1020 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 7993 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1114 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8004 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1177 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8015 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8026 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1337 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Implicit(unsigned int8)");
			}
#line 8037 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1507 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
										"[.library]System.Byte::ToString(unsigned int8)");
			}
#line 8048 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8061 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8074 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8087 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8100 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8113 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_4__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 8132 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 8151 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 220 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 8168 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 8185 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 366 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8195 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 8213 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 8231 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 561 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8241 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 640 "cg_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
			}
#line 8255 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 8266 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 811 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U8);
				}
			}
#line 8284 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 920 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 8295 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1011 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 8306 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1102 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 8317 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1162 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 8328 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1220 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 8339 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1342 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Implicit(int16)");
			}
#line 8350 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1512 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
										"[.library]System.Int16::ToString(int16)");
			}
#line 8361 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8374 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8387 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8400 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8413 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8426 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_5__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 8445 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 8464 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 237 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 8481 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 325 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 8498 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 392 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 8516 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8526 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8536 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 561 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8546 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 634 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8556 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 8567 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 829 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 8578 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 929 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 8589 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1020 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 8600 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1114 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8611 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1177 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8622 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8633 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1347 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS cannot convert from uint16 to decimal, so use int32 instead */
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
				}
				else
				{
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Implicit(unsigned int16)");
				}
			}
#line 8653 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1517 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the UInt16 class, so use Int32 instead */
					ILGenCallByName(info, "class [.library]System.String "
											"[.library]System.Int32::ToString(int32)");
				}
				else
				{
					ILGenCallByName(info, "class [.library]System.String "
									"[.library]System.UInt16::ToString(unsigned int16)");
				}
			}
#line 8673 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8686 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8699 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8712 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8725 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8738 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_6__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 8757 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 8776 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 237 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 8793 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 325 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 8810 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 392 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 8828 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8838 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 439 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8848 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 561 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8858 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 634 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 8868 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 8879 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 829 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 8890 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 929 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 8901 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1020 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 8912 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1114 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8923 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1177 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8934 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 8945 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1361 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(char)");
			}
#line 8956 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1531 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
										"[.library]System.Char::ToString(char)");
			}
#line 8967 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8980 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 8993 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9006 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9019 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9032 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_7__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 9051 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 9070 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 220 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 9087 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 9104 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 375 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 9122 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 9140 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 9158 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 561 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 9168 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 640 "cg_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
			}
#line 9182 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 9193 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 811 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U8);
				}
			}
#line 9211 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 920 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 9222 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1011 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 9233 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1102 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 9244 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1162 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 9255 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1220 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 9266 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1366 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Implicit(int32)");
			}
#line 9277 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1536 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
										"[.library]System.Int32::ToString(int32)");
			}
#line 9288 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9301 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1663 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 9311 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9324 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9337 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9350 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_8__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 9369 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 9388 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 237 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 9405 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 325 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 9422 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 392 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 9440 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 476 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 9458 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 476 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 9476 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 581 "cg_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4_UN);
				}
			}
#line 9490 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 634 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 9500 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 743 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 9511 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 829 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 9522 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 929 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 9533 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1020 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 9544 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1122 "cg_cast.tc"
			{
				/* Convert an unsigned input value and also clamp the
				   result to the "float32" type's precision range */
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 9557 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1177 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 9568 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 9579 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1371 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS cannot convert from uint32 to decimal, so use int64 instead */
					ILGenSimple(info, IL_OP_CONV_I8);
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Implicit(int64)");
				}
				else
				{
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
								"[.library]System.Decimal::op_Implicit(unsigned int32)");
				}
			}
#line 9600 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1541 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the UInt32 class, so use Int64 instead */
					ILGenSimple(info, IL_OP_CONV_U8);
					ILGenCallByName(info, "class [.library]System.String "
											"[.library]System.Int64::ToString(int64)");
				}
				else
				{
					ILGenCallByName(info, "class [.library]System.String "
									"[.library]System.UInt32::ToString(unsigned int32)");
				}
			}
#line 9621 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9634 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1668 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 9644 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9657 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9670 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 9683 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_9__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 9702 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 146 "cg_cast.tc"
			{
			    /* Note: we can probably do this with "brfalse", but the
			       documentation is a little vague.  It provides information
			       for types "I" and "O", but not "I8" or "F".  Therefore,
			       we will be paranoid and do it the long way */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenSimple(info, IL_OP_CONV_I8);
			    ILGenJump(info, IL_OP_BEQ, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_1);
			    ILGenJump(info, IL_OP_BR, &label2);
			    ILGenLabel(info, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenLabel(info, &label2);
			    ILGenExtend(info, 1);
			}
#line 9726 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 220 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 9743 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 9760 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 375 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 9778 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 9796 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 9814 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 569 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 9832 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 652 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 9850 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 748 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 9860 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 838 "cg_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
			}
#line 9874 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 942 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I);
				}
			}
#line 9892 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1033 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U);
				}
			}
#line 9910 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1102 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 9921 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1162 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 9932 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1248 "cg_cast.tc"
			{
				/* This is where things get nasty.  The instruction
				   set is lacking a "conv.r" opcode which could convert
				   large 64-bit values with accurate precision on
				   machines with mantissas of 64-bits or greater, and
				   truncation on machines with less than 64-bit mantissas.
				   Since we wish to have maximal accuracy, we need to do
				   this in a round-about fashion */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			
				/* First, attempt to determine whether the runtime has
				   enough precision for 64-bit values in its mantissa */
				ILGenUInt64(info, (((ILUInt64)1) << 63) | ((ILUInt64)1));
				ILGenSimple(info, IL_OP_DUP);
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_CONV_U8);
				ILGenJump(info, IL_OP_BNE_UN, &label1);
			
				/* Bias the input value to convert it into an unsigned value */
				ILGenUInt64(info, (((ILUInt64)1) << 63));
				ILGenSimple(info, IL_OP_ADD);
			
				/* Convert into a floating point value with maximal precision */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			
				/* Subtract off the bias to get the final result */
				ILGenUInt64(info, (((ILUInt64)1) << 63));
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_SUB);
			
				/* Jump past the "else" case of the test */
				ILGenJump(info, IL_OP_BR, &label2);
			
				/* We don't have enough precision in the mantissa, so make
				   the most of it using the "conv.r8" instruction */
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_CONV_R8);
			
				/* Done */
				ILGenLabel(info, &label2);
				ILGenExtend(info, 2);
			}
#line 9982 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1386 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int64)");
			}
#line 9993 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1556 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
										"[.library]System.Int64::ToString(int64)");
			}
#line 10004 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10017 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1663 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 10027 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10040 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10053 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10066 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_10__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 10085 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 146 "cg_cast.tc"
			{
			    /* Note: we can probably do this with "brfalse", but the
			       documentation is a little vague.  It provides information
			       for types "I" and "O", but not "I8" or "F".  Therefore,
			       we will be paranoid and do it the long way */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenSimple(info, IL_OP_CONV_I8);
			    ILGenJump(info, IL_OP_BEQ, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_1);
			    ILGenJump(info, IL_OP_BR, &label2);
			    ILGenLabel(info, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenLabel(info, &label2);
			    ILGenExtend(info, 1);
			}
#line 10109 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 237 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 10126 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 325 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 10143 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 392 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 10161 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 476 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 10179 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 476 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 10197 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 591 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 10215 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 666 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 10233 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 767 "cg_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I8_UN);
				}
			}
#line 10247 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 834 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 10257 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 962 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I);
				}
			}
#line 10275 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1053 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U);
				}
			}
#line 10293 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1122 "cg_cast.tc"
			{
				/* Convert an unsigned input value and also clamp the
				   result to the "float32" type's precision range */
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 10306 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1183 "cg_cast.tc"
			{
				/* Convert an unsigned input value and also clamp the
				   result to the "float64" type's precision range */
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 10319 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 10330 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1391 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS cannot convert directly from uint64 to decimal,
					   so we need to do this in a round-about fashion.
					   We subtract 0x8000000000000000, convert to decimal,
					   and then add 0x8000000000000000 */
					ILGenUInt64(info, (ILUInt64)IL_MIN_INT64);
					ILGenSimple(info, IL_OP_SUB);
					ILGenAdjust(info, -1);
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int64)");
					ILGenInt32(info, 0);					/* low */
					ILGenInt32(info, (ILInt32)0x80000000);	/* mid */
					ILGenInt32(info, 0);					/* high */
					ILGenInt32(info, 0);					/* isNegative */
					ILGenInt32(info, 0);					/* scale */
					ILGenAdjust(info, 5);
					ILGenNewObj(info, "[.library]System.Decimal",
					            "(int32, int32, int32, bool, unsigned int8)");
					ILGenAdjust(info, -4);
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
							"[.library]System.Decimal::op_Addition"
									"(valuetype [.library]System.Decimal,"
									 "valuetype [.library]System.Decimal)");
					ILGenAdjust(info, -1);
				}
				else
				{
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
								"[.library]System.Decimal::op_Implicit(unsigned int64)");
				}
			}
#line 10370 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1561 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the UInt64 class, so convert via Decimal */
					ILGenCast(info, ILMachineType_UInt64, ILMachineType_Decimal);
					ILGenCallByName(info, "class [.library]System.String "
									"[.library]System.Decimal::ToString"
									"(valuetype [.library]System.Decimal)");
				}
				else
				{
					ILGenCallByName(info, "class [.library]System.String "
									"[.library]System.UInt64::ToString(unsigned int64)");
				}
			}
#line 10392 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10405 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1668 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 10415 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10428 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10441 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10454 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_11__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 10473 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 10492 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 220 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 10509 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 10526 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 375 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 10544 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 10562 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 10580 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 569 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 10598 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 652 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 10616 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 737 "cg_cast.tc"
			{
				/* A simple sign-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 10627 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 811 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U8);
				}
			}
#line 10645 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 935 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 10655 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1045 "cg_cast.tc"
			{
				/* Convert a signed input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U);
				}
			}
#line 10669 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1102 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 10680 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1162 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 10691 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1243 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_CONV_I8);
				ILGenCast(info, ILMachineType_Int64, ILMachineType_NativeFloat);
			}
#line 10702 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1425 "cg_cast.tc"
			{
				/* Since we don't know how big native integers are,
				   use the "int64" conversion operator */
				ILGenSimple(info, IL_OP_CONV_I8);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int64)");
			}
#line 10716 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1577 "cg_cast.tc"
			{
				/* We don't know how big the native integer is, so
				   convert to "int64" and convert that */
				ILGenSimple(info, IL_OP_CONV_I8);
				ILGenCallByName(info, "class [.library]System.String "
								"[.library]System.Int64::ToString(int64)");
			}
#line 10730 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10743 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 10753 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10766 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10779 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 10792 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_12__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 10811 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 10830 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 237 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 10847 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 325 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 10864 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 392 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 10882 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 476 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 10900 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 476 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 10918 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 591 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 10936 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 666 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 10954 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 743 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 10965 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 829 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 10976 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 954 "cg_cast.tc"
			{
				/* Convert an unsigned input value, but only in overflow mode */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I_UN);
				}
			}
#line 10990 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1026 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 11000 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1122 "cg_cast.tc"
			{
				/* Convert an unsigned input value and also clamp the
				   result to the "float32" type's precision range */
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 11013 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1183 "cg_cast.tc"
			{
				/* Convert an unsigned input value and also clamp the
				   result to the "float64" type's precision range */
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 11026 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 11037 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1434 "cg_cast.tc"
			{
				/* Since we don't know how big native integers are,
				   use the "uint64" conversion operator */
				ILGenSimple(info, IL_OP_CONV_U8);
				ILGenCast(info, ILMachineType_UInt64, ILMachineType_Decimal);
			}
#line 11050 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1586 "cg_cast.tc"
			{
				/* We don't know how big the native integer is, so
				   convert to "uint64" and convert that */
				ILGenSimple(info, IL_OP_CONV_U8);
				ILGenCast(info, ILMachineType_UInt64, ILMachineType_String);
			}
#line 11063 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11076 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 11086 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11099 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11112 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11125 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_13__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 11144 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 166 "cg_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BEQ, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_1);
			    ILGenJump(info, IL_OP_BR, &label2);
			    ILGenLabel(info, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenLabel(info, &label2);
			    ILGenExtend(info, 1);
			}
#line 11163 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 220 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 11180 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 11197 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 375 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 11215 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 11233 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 11251 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 569 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 11269 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 652 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 11287 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 755 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I8);
				}
			}
#line 11305 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 811 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U8);
				}
			}
#line 11323 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 942 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I);
				}
			}
#line 11341 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1033 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U);
				}
			}
#line 11359 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1107 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 11369 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1168 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 11379 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1227 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 11389 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1441 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Explicit(float32)");
			}
#line 11400 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1593 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
								"[.library]System.Single::ToString(float32)");
			}
#line 11411 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11424 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11437 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11450 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11463 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11476 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_14__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 11495 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 166 "cg_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BEQ, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_1);
			    ILGenJump(info, IL_OP_BR, &label2);
			    ILGenLabel(info, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenLabel(info, &label2);
			    ILGenExtend(info, 1);
			}
#line 11514 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 220 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 11531 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 11548 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 375 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 11566 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 11584 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 11602 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 569 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 11620 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 652 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 11638 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 755 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I8);
				}
			}
#line 11656 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 811 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U8);
				}
			}
#line 11674 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 942 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I);
				}
			}
#line 11692 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1033 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U);
				}
			}
#line 11710 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1102 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 11721 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1168 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 11731 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1227 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 11741 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1446 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Explicit(float64)");
			}
#line 11752 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1598 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
								"[.library]System.Double::ToString(float64)");
			}
#line 11763 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11776 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11789 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11802 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11815 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 11828 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_15__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 11847 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 166 "cg_cast.tc"
			{
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BEQ, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_1);
			    ILGenJump(info, IL_OP_BR, &label2);
			    ILGenLabel(info, &label1);
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenLabel(info, &label2);
			    ILGenExtend(info, 1);
			}
#line 11866 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 220 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 11883 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 11900 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 375 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 11918 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 11936 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 458 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 11954 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 569 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 11972 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 652 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 11990 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 755 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I8);
				}
			}
#line 12008 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 811 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U8);
				}
			}
#line 12026 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 942 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I);
				}
			}
#line 12044 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1033 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U);
				}
			}
#line 12062 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1102 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 12073 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1162 "cg_cast.tc"
			{
				/* Convert a signed input value */
				ILGenSimple(info, IL_OP_CONV_R8);
			}
#line 12084 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1227 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 12094 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1451 "cg_cast.tc"
			{
				/* Since we don't know how big native floats are,
				   down-convert to "float64", and convert that */
				ILGenSimple(info, IL_OP_CONV_R8);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
									"[.library]System.Decimal::op_Explicit(float64)");
			}
#line 12108 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1603 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_CONV_R8);
				ILGenCallByName(info, "class [.library]System.String "
								"[.library]System.Double::ToString(float64)");
			}
#line 12120 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12133 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12146 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12159 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12172 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12185 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_16__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 12204 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 179 "cg_cast.tc"
			{
			    ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
				ILGenCallByName(info, "bool [.library]System.Decimal::op_Equality"
						"(valuetype [.library]System.Decimal, "
						"valuetype [.library]System.Decimal)");
				ILGenExtend(info, 1);
			}
#line 12220 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 248 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to int8, so
					   down-convert from int32 instead */
					ILGenCallByName(info, "int32 [.library]System.Decimal::op_Explicit"
												"(valuetype [.library]System.Decimal)");
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenCallByName(info, "int8 [.library]System.Decimal::op_Explicit"
												"(valuetype [.library]System.Decimal)");
				}
			}
#line 12242 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 336 "cg_cast.tc"
			{
				ILGenCallByName(info, "unsigned int8 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12253 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 404 "cg_cast.tc"
			{
				ILGenCallByName(info, "int16 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12264 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 488 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to uint16, so
					   down-convert from int32 instead */
					ILGenCallByName(info, "int32 [.library]System.Decimal::op_Explicit"
												"(valuetype [.library]System.Decimal)");
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenCallByName(info,
							"unsigned int16 [.library]System.Decimal::op_Explicit"
									"(valuetype [.library]System.Decimal)");
				}
			}
#line 12287 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 505 "cg_cast.tc"
			{
				ILGenCallByName(info, "char [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12298 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 603 "cg_cast.tc"
			{
				ILGenCallByName(info, "int32 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12309 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 678 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to uint32, so
					   down-convert from int64 instead */
					ILGenCallByName(info, "int64 [.library]System.Decimal::op_Explicit"
												"(valuetype [.library]System.Decimal)");
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
				else
				{
					ILGenCallByName(info,
							"unsigned int32 [.library]System.Decimal::op_Explicit"
									"(valuetype [.library]System.Decimal)");
				}
			}
#line 12332 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 775 "cg_cast.tc"
			{
				ILGenCallByName(info, "int64 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12343 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 846 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have a conversion from Decimal to uint64,
					   so we need to do this in a more round-about fashion.
					   We subtract 0x8000000000000000, convert to int64, and
					   then add 0x8000000000000000 to the result */
					ILGenInt32(info, 0);					/* low */
					ILGenInt32(info, (ILInt32)0x80000000);	/* mid */
					ILGenInt32(info, 0);					/* high */
					ILGenInt32(info, 0);					/* isNegative */
					ILGenInt32(info, 0);					/* scale */
					ILGenAdjust(info, 5);
					ILGenNewObj(info, "[.library]System.Decimal",
					            "(int32, int32, int32, bool, unsigned int8)");
					ILGenAdjust(info, -4);
					ILGenCallByName(info, "valuetype [.library]System.Decimal "
							"[.library]System.Decimal::op_Subtraction"
									"(valuetype [.library]System.Decimal,"
									 "valuetype [.library]System.Decimal)");
					ILGenAdjust(info, -1);
					ILGenCallByName(info, "int64 [.library]System.Decimal::op_Explicit"
												"(valuetype [.library]System.Decimal)");
					ILGenUInt64(info, (ILUInt64)IL_MIN_INT64);
					ILGenSimple(info, IL_OP_ADD);
					ILGenAdjust(info, -1);
				}
				else
				{
					ILGenCallByName(info,
							"unsigned int64 [.library]System.Decimal::op_Explicit"
								"(valuetype [.library]System.Decimal)");
				}
			}
#line 12384 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 974 "cg_cast.tc"
			{
				/* We don't know how big the native integer type is at
				   this point, so we convert to "int64", and then perform
				   a run-time down conversion to "native int" */
				ILGenCallByName(info, "int64 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
				ILGenSimple(info, IL_OP_CONV_OVF_I);
			}
#line 12399 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1065 "cg_cast.tc"
			{
				/* We don't know how big the native integer type is at
				   this point, so we convert to "uint64", and then perform
				   a run-time down conversion to "native unsigned int" */
				ILGenCast(info, ILMachineType_Decimal, ILMachineType_UInt64);
				ILGenSimple(info, IL_OP_CONV_OVF_U_UN);
			}
#line 12413 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1129 "cg_cast.tc"
			{
				ILGenCallByName(info, "float32 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12424 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1190 "cg_cast.tc"
			{
				ILGenCallByName(info, "float64 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12435 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1292 "cg_cast.tc"
			{
				ILGenCallByName(info, "float64 [.library]System.Decimal::op_Explicit"
											"(valuetype [.library]System.Decimal)");
			}
#line 12446 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1459 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 12456 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1609 "cg_cast.tc"
			{
				ILGenCallByName(info, "class [.library]System.String "
								"[.library]System.Decimal::ToString"
								"(valuetype [.library]System.Decimal)");
			}
#line 12468 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12481 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12494 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12507 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12520 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12533 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_17__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 12552 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 189 "cg_cast.tc"
			{
				ILGenCallByName(info,
						"bool [.library]System.Boolean::FromString"
							"(class [.library]System.String)");
			}
#line 12564 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 264 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the SByte class, so down-convert from Int32 */
					ILGenCallByName(info,
							"int32 [.library]System.Int32::FromString"
									"(class [.library]System.String)");
					ILGenSimple(info, IL_OP_CONV_OVF_I1);
				}
				else
				{
					ILGenCallByName(info, "int8 [.library]System.SByte::FromString"
												"(class [.library]System.String)");
				}
			}
#line 12586 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 341 "cg_cast.tc"
			{
				ILGenCallByName(info, "unsigned int8 [.library]System.Byte::FromString"
											"(class [.library]System.String)");
			}
#line 12597 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 409 "cg_cast.tc"
			{
				ILGenCallByName(info, "int16 [.library]System.Int16::FromString"
											"(class [.library]System.String)");
			}
#line 12608 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 510 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the UInt16 class, so down-convert from Int32 */
					ILGenCallByName(info,
							"int32 [.library]System.Int32::FromString"
									"(class [.library]System.String)");
					ILGenSimple(info, IL_OP_CONV_OVF_U2);
				}
				else
				{
					ILGenCallByName(info,
							"unsigned int16 [.library]System.UInt16::FromString"
									"(class [.library]System.String)");
				}
			}
#line 12631 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 527 "cg_cast.tc"
			{
				ILGenCallByName(info,
						"char [.library]System.Char::FromString"
								"(class [.library]System.String)");
			}
#line 12643 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 608 "cg_cast.tc"
			{
				ILGenCallByName(info, "int32 [.library]System.Int32::FromString"
											"(class [.library]System.String)");
			}
#line 12654 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 695 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the UInt32 class, so down-convert from Int64 */
					ILGenCallByName(info,
							"int64 [.library]System.Int64::FromString"
									"(class [.library]System.String)");
					ILGenSimple(info, IL_OP_CONV_OVF_U4);
				}
				else
				{
					ILGenCallByName(info,
						"unsigned int32 [.library]System.UInt32::FromString"
									"(class [.library]System.String)");
				}
			}
#line 12677 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 780 "cg_cast.tc"
			{
				ILGenCallByName(info,
						"int64 [.library]System.Int64::FromString"
								"(class [.library]System.String)");
			}
#line 12689 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 881 "cg_cast.tc"
			{
				if(info->clsCompliant)
				{
					/* CLS does not have the UInt64 class, so down-convert from Decimal */
					ILGenCallByName(info,
							"valuetype [.library]System.Decimal "
									"[.library]System.Decimal::FromString"
											"(class [.library]System.String)");
					ILGenCast(info, ILMachineType_Decimal, ILMachineType_UInt64);
				}
				else
				{
					ILGenCallByName(info,
						"unsigned int64 [.library]System.UInt64::FromString"
								"(class [.library]System.String)");
				}
			}
#line 12713 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 983 "cg_cast.tc"
			{
				ILGenCallByName(info,
						"int64 [.library]System.Int64::FromString"
								"(class [.library]System.String)");
				ILGenSimple(info, IL_OP_CONV_OVF_I);
			}
#line 12726 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1073 "cg_cast.tc"
			{
				ILGenCast(info, ILMachineType_String, ILMachineType_UInt64);
				ILGenSimple(info, IL_OP_CONV_OVF_U_UN);
			}
#line 12737 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1134 "cg_cast.tc"
			{
				ILGenCallByName(info,
						"float32 [.library]System.Single::FromString"
								"(class [.library]System.String)");
			}
#line 12749 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1195 "cg_cast.tc"
			{
				ILGenCallByName(info,
						"float64 [.library]System.Double::FromString"
								"(class [.library]System.String)");
			}
#line 12761 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1297 "cg_cast.tc"
			{
				ILGenCallByName(info,
						"float64 [.library]System.Double::FromString"
								"(class [.library]System.String)");
			}
#line 12773 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1463 "cg_cast.tc"
			{
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
						"[.library]System.Decimal::FromString"
						"(class [.library]System.String)");
			}
#line 12785 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1615 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 12795 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 12805 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12818 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12831 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12844 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 12857 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_18__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 12876 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 12895 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 283 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 12906 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 349 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 12917 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 417 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 12928 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 12939 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 12950 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 616 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 12961 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 715 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 12972 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 789 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 12984 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 902 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 12996 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 993 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 13008 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1081 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 13020 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1143 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13031 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1204 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13042 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1306 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13053 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1472 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
			}
#line 13066 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1619 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 13076 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 13086 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13099 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13112 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13125 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13138 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_19__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 13157 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 13176 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 237 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I1_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
#line 13193 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 310 "cg_cast.tc"
			{
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U1);
				}
			}
#line 13210 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 392 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
#line 13228 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13239 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 476 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U2_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U2);
				}
			}
#line 13257 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 591 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I4_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I4);
				}
			}
#line 13275 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 666 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_U4_UN);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_U4);
				}
			}
#line 13293 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 755 "cg_cast.tc"
			{
				/* Convert a signed input value */
				if(info->overflowInsns)
				{
					ILGenSimple(info, IL_OP_CONV_OVF_I8);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I8);
				}
			}
#line 13311 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 829 "cg_cast.tc"
			{
				/* A simple zero-extend is sufficient */
				ILGenSimple(info, IL_OP_CONV_U8);
			}
#line 13322 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 935 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 13332 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1026 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 13342 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1122 "cg_cast.tc"
			{
				/* Convert an unsigned input value and also clamp the
				   result to the "float32" type's precision range */
				ILGenSimple(info, IL_OP_CONV_R_UN);
				ILGenSimple(info, IL_OP_CONV_R4);
			}
#line 13355 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1177 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 13366 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1238 "cg_cast.tc"
			{
				/* Convert an unsigned input value */
				ILGenSimple(info, IL_OP_CONV_R_UN);
			}
#line 13377 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1434 "cg_cast.tc"
			{
				/* Since we don't know how big native integers are,
				   use the "uint64" conversion operator */
				ILGenSimple(info, IL_OP_CONV_U8);
				ILGenCast(info, ILMachineType_UInt64, ILMachineType_Decimal);
			}
#line 13390 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1586 "cg_cast.tc"
			{
				/* We don't know how big the native integer is, so
				   convert to "uint64" and convert that */
				ILGenSimple(info, IL_OP_CONV_U8);
				ILGenCast(info, ILMachineType_UInt64, ILMachineType_String);
			}
#line 13403 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13416 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 13426 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13439 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13452 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13465 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_20__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 13484 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 13503 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 283 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13514 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 349 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13525 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 417 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13536 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13547 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13558 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 616 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13569 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 715 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13580 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 789 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 13592 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 902 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 13604 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 993 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 13616 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1081 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 13628 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1143 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13639 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1204 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13650 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1306 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13661 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1472 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
			}
#line 13674 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1625 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13685 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13698 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13711 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 13721 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13734 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13747 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_21__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 13766 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 132 "cg_cast.tc"
			{
				/* Note: this would be a lot easier if there was a
				   "cne" opcode in the instruction set */
				ILLabel label1 = ILLabel_Undefined;
				ILLabel label2 = ILLabel_Undefined;
				ILGenJump(info, IL_OP_BRFALSE, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_1);
				ILGenJump(info, IL_OP_BR, &label2);
				ILGenLabel(info, &label1);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenLabel(info, &label2);
			}
#line 13785 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 283 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13796 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 349 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13807 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 417 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13818 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13829 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13840 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 616 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13851 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 715 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 13862 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 789 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 13874 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 902 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 13886 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 993 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 13898 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1081 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 13910 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1143 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13921 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1204 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13932 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1306 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 13943 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1472 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
			}
#line 13956 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1625 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13967 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13980 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 13993 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 14006 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 14016 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 14029 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast_split_22__(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(toType)
	{
		case ILMachineType_Void:
		{
#line 102 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
#line 14048 "cg_cast.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 195 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14059 "cg_cast.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 283 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14070 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 349 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14081 "cg_cast.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 417 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14092 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14103 "cg_cast.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 541 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14114 "cg_cast.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 616 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14125 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 715 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
			}
#line 14136 "cg_cast.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 789 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 14148 "cg_cast.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 902 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I8);
			}
#line 14160 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 993 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_I);
			}
#line 14172 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1081 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenSimple(info, IL_OP_CONV_U);
			}
#line 14184 "cg_cast.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1143 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 14195 "cg_cast.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1204 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 14206 "cg_cast.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1306 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenLoadFloat32(info, (ILFloat)0.0);
			}
#line 14217 "cg_cast.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1472 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
										"[.library]System.Decimal::op_Implicit(int32)");
			}
#line 14230 "cg_cast.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1625 "cg_cast.tc"
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 14241 "cg_cast.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 14251 "cg_cast.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 14264 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 14277 "cg_cast.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1676 "cg_cast.tc"
			{
				/* Cannot convert numeric values into objects this way.
				   We probably should look into boxing the value later */
				ILGenSimple(info, IL_OP_POP);
				ILGenSimple(info, IL_OP_LDNULL);
			}
#line 14290 "cg_cast.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1658 "cg_cast.tc"
			{
				/* Nothing to do here */
			}
#line 14300 "cg_cast.c"
		}
		break;

		default: break;
	}
}

void ILGenCast(ILGenInfo * info, ILMachineType fromType, ILMachineType toType)
{
	switch(fromType)
	{
		case ILMachineType_Void:
		{
			ILGenCast_split_0__(info, fromType, toType);
		}
		break;

		case ILMachineType_Boolean:
		{
			ILGenCast_split_1__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int8:
		{
			ILGenCast_split_2__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt8:
		{
			ILGenCast_split_3__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int16:
		{
			ILGenCast_split_4__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt16:
		{
			ILGenCast_split_5__(info, fromType, toType);
		}
		break;

		case ILMachineType_Char:
		{
			ILGenCast_split_6__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int32:
		{
			ILGenCast_split_7__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt32:
		{
			ILGenCast_split_8__(info, fromType, toType);
		}
		break;

		case ILMachineType_Int64:
		{
			ILGenCast_split_9__(info, fromType, toType);
		}
		break;

		case ILMachineType_UInt64:
		{
			ILGenCast_split_10__(info, fromType, toType);
		}
		break;

		case ILMachineType_NativeInt:
		{
			ILGenCast_split_11__(info, fromType, toType);
		}
		break;

		case ILMachineType_NativeUInt:
		{
			ILGenCast_split_12__(info, fromType, toType);
		}
		break;

		case ILMachineType_Float32:
		{
			ILGenCast_split_13__(info, fromType, toType);
		}
		break;

		case ILMachineType_Float64:
		{
			ILGenCast_split_14__(info, fromType, toType);
		}
		break;

		case ILMachineType_NativeFloat:
		{
			ILGenCast_split_15__(info, fromType, toType);
		}
		break;

		case ILMachineType_Decimal:
		{
			ILGenCast_split_16__(info, fromType, toType);
		}
		break;

		case ILMachineType_String:
		{
			ILGenCast_split_17__(info, fromType, toType);
		}
		break;

		case ILMachineType_ObjectRef:
		{
			ILGenCast_split_18__(info, fromType, toType);
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
			ILGenCast_split_19__(info, fromType, toType);
		}
		break;

		case ILMachineType_ManagedPtr:
		{
			ILGenCast_split_20__(info, fromType, toType);
		}
		break;

		case ILMachineType_TransientPtr:
		{
			ILGenCast_split_21__(info, fromType, toType);
		}
		break;

		case ILMachineType_ManagedValue:
		{
			ILGenCast_split_22__(info, fromType, toType);
		}
		break;

		default: break;
	}
}

