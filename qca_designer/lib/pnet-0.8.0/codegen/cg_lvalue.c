/* cg_lvalue.c.  Generated automatically by treecc */
#line 3 "cg_lvalue.tc"

/*
 * cg_lvalue.tc - Identifier and l-value nodes.
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

#line 330 "cg_lvalue.tc"


/*
 * Resolve and call a specific method for a multi-dimensional array.
 */
static void CallMArrayMethod(ILGenInfo *info, ILType *arrayType,
							 const char *name)
{
	ILClass *classInfo;
	ILMethod *method;

	/* Get the class information block for the array */
	classInfo = ILTypeToClass(info, arrayType);
	if(!classInfo)
	{
		return;
	}

	/* Find the method called "name" */
	if((method = (ILMethod *)ILClassNextMemberMatch
		(classInfo, (ILMember *)0, IL_META_MEMBERKIND_METHOD, name, 0)) != 0)
	{
		ILGenCallByMethod(info, method);
	}
}

#line 171 "jv_lvalue.tc"


/*
 * Validate a value type instance from a field or array element.
 *
 * Because JVM does not really support value types, we have some
 * issues when objects and arrays that contain value types are
 * constructed.  To get around this, we must check for "null" and
 * then replace "null" values with a newly initialized value.
 */
static void ValidateValueType(ILGenInfo *info, ILMachineType machineType,
							  ILType *actualType)
{
	ILLabel label = ILLabel_Undefined;
	char *className;

	/* Bail out if the machine type does not indicate a managed value */
	if(machineType != ILMachineType_Decimal &&
	   machineType != ILMachineType_ManagedValue)
	{
		return;
	}

	/* Check the value on the stack top for "null" */
	JavaGenSimple(info, JAVA_OP_DUP);
	JavaGenAdjust(info, 1);
	JavaGenJump(info, JAVA_OP_IFNONNULL, &label);
	JavaGenAdjust(info, -1);

	/* Pop the "null" value and create an instance of the value type */
	JavaGenSimple(info, JAVA_OP_POP);
	className = JavaGetClassName(info, ILTypeToClass(info, actualType));
	JavaGenNewObj(info, className);
	JavaGenSimple(info, JAVA_OP_DUP);
	JavaGenAdjust(info, 1);
	JavaGenCallCtor(info, className, "<init>", "()V");
	JavaGenAdjust(info, -1);
	ILFree(className);

	/* Output the label that was used to skip the initialization */
	JavaGenLabel(info, &label);
}

#line 585 "jv_misc.tc"


void JavaBoxValue(ILGenInfo *info, ILMachineType type,
				  int isEnumType, ILClass *classInfo)
{
	char *javaName;
	char *signature;

	switch(type)
	{
		case ILMachineType_Void:
		{
			/* Shouldn't happen */
		}
		break;

		case ILMachineType_Boolean:
		{
			if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Boolean");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtor(info, "java/lang/Boolean", "<init>", "(Z)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/Boolean", "copyIn__",
								  "(Z)LSystem/Boolean;");
			}
		}
		break;

		case ILMachineType_Int8:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(B)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Byte");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtor(info, "java/lang/Byte", "<init>", "(B)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/SByte", "copyIn__",
								  "(B)LSystem/SByte;");
			}
		}
		break;

		case ILMachineType_UInt8:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(I)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__B", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewIntrinsic(info, "UByte");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtorIntrinsic(info, "UByte", "<init>", "(I)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/Byte", "copyIn__B",
								  "(I)LSystem/Byte;");
			}
		}
		break;

		case ILMachineType_Int16:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(S)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Short");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtor(info, "java/lang/Short", "<init>", "(S)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/Int16", "copyIn__",
								  "(S)LSystem/Int16;");
			}
		}
		break;

		case ILMachineType_UInt16:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(I)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__S", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewIntrinsic(info, "UShort");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtorIntrinsic(info, "UShort", "<init>", "(I)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/UInt16", "copyIn__S",
								  "(I)LSystem/UInt16;");
			}
		}
		break;

		case ILMachineType_Char:
		{
			if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Character");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtor(info, "java/lang/Character", "<init>", "(C)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/Char", "copyIn__",
								  "(C)LSystem/Char;");
			}
		}
		break;

		case ILMachineType_Int32:
		case ILMachineType_NativeInt:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(I)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Integer");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtor(info, "java/lang/Integer", "<init>", "(I)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/Int32", "copyIn__",
								  "(I)LSystem/Int32;");
			}
		}
		break;

		case ILMachineType_UInt32:
		case ILMachineType_NativeUInt:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(I)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__I", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewIntrinsic(info, "UInteger");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtorIntrinsic(info, "UInteger", "<init>", "(I)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/UInt32", "copyIn__I",
								  "(I)LSystem/UInt32;");
			}
		}
		break;

		case ILMachineType_Int64:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(J)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__", signature);
				ILFree(javaName);
				ILFree(signature);
				JavaGenAdjust(info, -1);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Long");
				JavaGenSimple(info, JAVA_OP_DUP_X2);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_DUP_X2);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenAdjust(info, -2);
				JavaGenCallCtor(info, "java/lang/Long", "<init>", "(J)V");
				JavaGenAdjust(info, -3);
			}
			else
			{
				JavaGenCallByName(info, "System/Int64", "copyIn__",
								  "(J)LSystem/Int64;");
				JavaGenAdjust(info, -1);
			}
		}
		break;

		case ILMachineType_UInt64:
		{
			if(isEnumType)
			{
				/* Boxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(J)L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";");
				JavaGenCallByName(info, javaName, "copyIn__L", signature);
				ILFree(javaName);
				ILFree(signature);
				JavaGenAdjust(info, -1);
			}
			else if(info->useJavaLib)
			{
				JavaGenNewIntrinsic(info, "ULong");
				JavaGenSimple(info, JAVA_OP_DUP_X2);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_DUP_X2);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenAdjust(info, -2);
				JavaGenCallCtorIntrinsic(info, "ULong", "<init>", "(J)V");
				JavaGenAdjust(info, -3);
			}
			else
			{
				JavaGenCallByName(info, "System/UInt64", "copyIn__L",
								  "(J)LSystem/UInt64;");
				JavaGenAdjust(info, -1);
			}
		}
		break;

		case ILMachineType_Float32:
		{
			if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Float");
				JavaGenSimple(info, JAVA_OP_DUP_X1);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_SWAP);
				JavaGenCallCtor(info, "java/lang/Float", "<init>", "(F)V");
				JavaGenAdjust(info, -2);
			}
			else
			{
				JavaGenCallByName(info, "System/Single", "copyIn__",
								  "(F)LSystem/Single;");
			}
		}
		break;

		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		{
			if(info->useJavaLib)
			{
				JavaGenNewObj(info, "java/lang/Double");
				JavaGenSimple(info, JAVA_OP_DUP_X2);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_DUP_X2);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_POP2);
				JavaGenAdjust(info, -2);
				JavaGenCallCtor(info, "java/lang/Double", "<init>", "(D)V");
				JavaGenAdjust(info, -3);
			}
			else
			{
				JavaGenCallByName(info, "System/Double", "copyIn__",
								  "(D)LSystem/Double;");
				JavaGenAdjust(info, -1);
			}
		}
		break;

		case ILMachineType_UnmanagedPtr:
		case ILMachineType_TransientPtr:
		{
			/* Shouldn't happen */
		}
		break;

		case ILMachineType_ObjectRef:
		case ILMachineType_String:
		{
			/* The value is already a boxed object */
		}
		break;

		case ILMachineType_Decimal:
		{
			if(info->useJavaLib)
			{
				/* A "java/math/BigDecimal" object is its own boxed form */
				break;
			}
		}
		/* Fall through to the next case */

		case ILMachineType_ManagedPtr:
		case ILMachineType_ManagedValue:
		{
			/* We have a managed pointer or value, so use the "copyIn__"
			   method to make a complete copy of the value being boxed */
			javaName = JavaGetClassName(info, classInfo);
			signature = JavaStrAppend(info, 0, "(L");
			signature = JavaStrAppend(info, signature, javaName);
			signature = JavaStrAppend(info, signature, ";)L");
			signature = JavaStrAppend(info, signature, javaName);
			signature = JavaStrAppend(info, signature, ";");
			JavaGenCallByName(info, javaName, "copyIn__", signature);
			ILFree(javaName);
			ILFree(signature);
		}
		break;
	}
}

ILMachineType JavaUnboxValue(ILGenInfo *info, ILMachineType subExprType,
					         ILMachineType type, int isEnumType,
					         int isRightType, ILClass *classInfo)
{
	char *javaName;
	char *signature;

	/* Determine the destination type for the unbox operation */
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
			JavaGenCast(info, subExprType, ILMachineType_Void);
		}
		break;

		case ILMachineType_Boolean:
		{
			if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Boolean", "booleanValue",
								   "()Z");
			}
			else
			{
				JavaGenCallByName(info, "System/Boolean", "copyOut__",
								  "(LSystem/Boolean;)Z");
			}
		}
		break;

		case ILMachineType_Int8:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)B");
				JavaGenCallByName(info, javaName, "copyOut__", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Byte", "byteValue", "()B");
			}
			else
			{
				JavaGenCallByName(info, "System/SByte", "copyOut__",
								  "(LSystem/SByte;)B");
			}
		}
		break;

		case ILMachineType_UInt8:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)I");
				JavaGenCallByName(info, javaName, "copyOut__B", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtIntrinsic(info, "UByte",
										 "ubyteValue__B", "()I");
			}
			else
			{
				JavaGenCallByName(info, "System/Byte", "copyOut__B",
								  "(LSystem/Byte;)I");
			}
		}
		break;

		case ILMachineType_Int16:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)S");
				JavaGenCallByName(info, javaName, "copyOut__", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Short",
								   "shortValue", "()S");
			}
			else
			{
				JavaGenCallByName(info, "System/Int16", "copyOut__",
								  "(LSystem/Int16;)S");
			}
		}
		break;

		case ILMachineType_UInt16:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)I");
				JavaGenCallByName(info, javaName, "copyOut__S", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtIntrinsic(info, "UShort",
										 "ushortValue__S", "()I");
			}
			else
			{
				JavaGenCallByName(info, "System/UInt16", "copyOut__S",
								  "(LSystem/UInt16;)I");
			}
		}
		break;

		case ILMachineType_Char:
		{
			if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Character",
								   "charValue", "()C");
			}
			else
			{
				JavaGenCallByName(info, "System/Char", "copyOut__",
								  "(LSystem/Char;)C");
			}
		}
		break;

		case ILMachineType_Int32:
		case ILMachineType_NativeInt:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)I");
				JavaGenCallByName(info, javaName, "copyOut__", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Integer",
								   "intValue", "()I");
			}
			else
			{
				JavaGenCallByName(info, "System/Int32", "copyOut__",
								  "(LSystem/Int32;)I");
			}
		}
		break;

		case ILMachineType_UInt32:
		case ILMachineType_NativeUInt:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)I");
				JavaGenCallByName(info, javaName, "copyOut__I", signature);
				ILFree(javaName);
				ILFree(signature);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtIntrinsic(info, "UInteger",
								         "uintValue__I", "()I");
			}
			else
			{
				JavaGenCallByName(info, "System/UInt32", "copyOut__I",
								  "(LSystem/UInt32;)I");
			}
		}
		break;

		case ILMachineType_Int64:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)J");
				JavaGenCallByName(info, javaName, "copyOut__", signature);
				ILFree(javaName);
				ILFree(signature);
				JavaGenAdjust(info, 1);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Long",
								   "longValue", "()J");
				JavaGenAdjust(info, 1);
			}
			else
			{
				JavaGenCallByName(info, "System/Int64", "copyOut__",
								  "(LSystem/Int64;)J");
				JavaGenAdjust(info, 1);
			}
		}
		break;

		case ILMachineType_UInt64:
		{
			if(isEnumType)
			{
				/* Unboxing an enumerated value */
				javaName = JavaGetClassName(info, classInfo);
				signature = JavaStrAppend(info, 0, "(L");
				signature = JavaStrAppend(info, signature, javaName);
				signature = JavaStrAppend(info, signature, ";)J");
				JavaGenCallByName(info, javaName, "copyOut__L", signature);
				ILFree(javaName);
				ILFree(signature);
				JavaGenAdjust(info, 1);
			}
			else if(info->useJavaLib)
			{
				JavaGenCallVirtIntrinsic(info, "ULong",
								         "ulongValue__L", "()J");
				JavaGenAdjust(info, 1);
			}
			else
			{
				JavaGenCallByName(info, "System/UInt64", "copyOut__L",
								  "(LSystem/UInt64;)J");
				JavaGenAdjust(info, 1);
			}
		}
		break;

		case ILMachineType_Float32:
		{
			if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Float",
								   "floatValue", "()F");
			}
			else
			{
				JavaGenCallByName(info, "System/Single", "copyOut__",
								  "(LSystem/Single;)F");
			}
		}
		break;

		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		{
			if(info->useJavaLib)
			{
				JavaGenCallVirtual(info, "java/lang/Double",
								   "floatValue", "()D");
				JavaGenAdjust(info, 1);
			}
			else
			{
				JavaGenCallByName(info, "System/Double", "copyOut__",
								  "(LSystem/Double;)D");
				JavaGenAdjust(info, 1);
			}
		}
		break;

		case ILMachineType_ObjectRef:
		case ILMachineType_String:
		{
			/* The unboxed form of an object is also an object.
			   We just do a cast to ensure it has the right type */
			if(!isRightType)
			{
				JavaGenClassRef(info, JAVA_OP_CHECKCAST, classInfo);
			}
		}
		break;

		case ILMachineType_UnmanagedPtr:
		case ILMachineType_TransientPtr:
		{
			/* Shouldn't happen */
		}
		break;

		case ILMachineType_Decimal:
		{
			if(info->useJavaLib)
			{
				/* A "java/math/BigDecimal" value is its own unboxed form */
				break;
			}
		}
		/* Fall through to the next case */

		case ILMachineType_ManagedPtr:
		case ILMachineType_ManagedValue:
		{
			/* Use the "copyIn__" method to make a copy of the value.
			   We don't use "copyOut__" because its implementation
			   would be identical to "copyIn__", and so there is no
			   reason to duplicate effort */
			javaName = JavaGetClassName(info, classInfo);
			signature = JavaStrAppend(info, 0, "(L");
			signature = JavaStrAppend(info, signature, javaName);
			signature = JavaStrAppend(info, signature, ";)L");
			signature = JavaStrAppend(info, signature, javaName);
			signature = JavaStrAppend(info, signature, ";");
			JavaGenCallByName(info, javaName, "copyIn__", signature);
			ILFree(javaName);
			ILFree(signature);
		}
		break;
	}

	return type;
}

#line 1571 "jv_misc.tc"


void JavaPrepareForThisAccess(ILGenInfo *info, ILNode *thisExpr,
							  ILClass *classInfo)
{
	ILType *fullType;
	ILMachineType thisType;
	if(yyisa(thisExpr, ILNode_MarkType))
	{
		fullType = ((ILNode_MarkType *)thisExpr)->type;
		thisExpr = ((ILNode_MarkType *)thisExpr)->expr;
	}
	else
	{
		fullType = 0;
	}
	if(yyisa(thisExpr, ILNode_This))
	{
		/* Just push the "this" pointer: we don't want to convert
		   it into a value and then re-box it */
		JavaGenSimple(info, JAVA_OP_ALOAD_0);
		JavaGenAdjust(info, 1);
	}
	else if(fullType && ILTypeIsValue(fullType))
	{
		/* Box the value before calling the method */
		thisType = JavaGenValue(thisExpr, info);
		JavaBoxValue(info, thisType, ILTypeIsEnum(fullType),
				     ILTypeToClass(info, fullType));
	}
	else
	{
		/* Assume that the "this" expression will be an object reference */
		JavaGenCast(info, JavaGenValue(thisExpr, info),
					ILMachineType_ObjectRef);
	}
}

#line 887 "cg_lvalue.c"

ILMachineType ILNode_Identifier_ILNode_GetType__(ILNode_Identifier *node, ILGenInfo * info)
#line 36 "cg_lvalue.tc"
{
	return ILMachineType_Void;
}
#line 894 "cg_lvalue.c"

void ILNode_Identifier_ILNode_GenDiscard__(ILNode_Identifier *node, ILGenInfo * info)
#line 45 "cg_lvalue.tc"
{
}
#line 900 "cg_lvalue.c"

ILMachineType ILNode_Identifier_ILNode_GenValue__(ILNode_Identifier *node, ILGenInfo * info)
#line 36 "cg_lvalue.tc"
{
	return ILMachineType_Void;
}
#line 907 "cg_lvalue.c"

void ILNode_Identifier_ILNode_GenThen__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label)
#line 45 "cg_lvalue.tc"
{
}
#line 913 "cg_lvalue.c"

void ILNode_Identifier_ILNode_GenElse__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label)
#line 45 "cg_lvalue.tc"
{
}
#line 919 "cg_lvalue.c"

int ILNode_Identifier_ILNode_EvalConst__(ILNode_Identifier *node, ILGenInfo * info, ILEvalValue * value)
#line 49 "cg_lvalue.tc"
{
	return 0;
}
#line 926 "cg_lvalue.c"

void ILNode_Identifier_JavaGenDiscard__(ILNode_Identifier *node, ILGenInfo * info)
#line 36 "jv_lvalue.tc"
{
}
#line 932 "cg_lvalue.c"

ILMachineType ILNode_Identifier_JavaGenValue__(ILNode_Identifier *node, ILGenInfo * info)
#line 27 "jv_lvalue.tc"
{
	return ILMachineType_Void;
}
#line 939 "cg_lvalue.c"

void ILNode_Identifier_JavaGenThen__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label)
#line 36 "jv_lvalue.tc"
{
}
#line 945 "cg_lvalue.c"

void ILNode_Identifier_JavaGenElse__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label)
#line 36 "jv_lvalue.tc"
{
}
#line 951 "cg_lvalue.c"

struct ILNode_Identifier_vtable__ const ILNode_Identifier_vt__ = {
	&ILNode_vt__,
	ILNode_Identifier_kind,
	"ILNode_Identifier",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Identifier_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_JavaGenElse__,
};

ILMachineType ILNode_QualIdent_ILNode_GetType__(ILNode_QualIdent *node, ILGenInfo * info)
#line 36 "cg_lvalue.tc"
{
	return ILMachineType_Void;
}
#line 975 "cg_lvalue.c"

void ILNode_QualIdent_ILNode_GenDiscard__(ILNode_QualIdent *node, ILGenInfo * info)
#line 45 "cg_lvalue.tc"
{
}
#line 981 "cg_lvalue.c"

ILMachineType ILNode_QualIdent_ILNode_GenValue__(ILNode_QualIdent *node, ILGenInfo * info)
#line 36 "cg_lvalue.tc"
{
	return ILMachineType_Void;
}
#line 988 "cg_lvalue.c"

void ILNode_QualIdent_ILNode_GenThen__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label)
#line 45 "cg_lvalue.tc"
{
}
#line 994 "cg_lvalue.c"

void ILNode_QualIdent_ILNode_GenElse__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label)
#line 45 "cg_lvalue.tc"
{
}
#line 1000 "cg_lvalue.c"

int ILNode_QualIdent_ILNode_EvalConst__(ILNode_QualIdent *node, ILGenInfo * info, ILEvalValue * value)
#line 49 "cg_lvalue.tc"
{
	return 0;
}
#line 1007 "cg_lvalue.c"

void ILNode_QualIdent_JavaGenDiscard__(ILNode_QualIdent *node, ILGenInfo * info)
#line 36 "jv_lvalue.tc"
{
}
#line 1013 "cg_lvalue.c"

ILMachineType ILNode_QualIdent_JavaGenValue__(ILNode_QualIdent *node, ILGenInfo * info)
#line 27 "jv_lvalue.tc"
{
	return ILMachineType_Void;
}
#line 1020 "cg_lvalue.c"

void ILNode_QualIdent_JavaGenThen__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label)
#line 36 "jv_lvalue.tc"
{
}
#line 1026 "cg_lvalue.c"

void ILNode_QualIdent_JavaGenElse__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label)
#line 36 "jv_lvalue.tc"
{
}
#line 1032 "cg_lvalue.c"

struct ILNode_QualIdent_vtable__ const ILNode_QualIdent_vt__ = {
	&ILNode_vt__,
	ILNode_QualIdent_kind,
	"ILNode_QualIdent",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_QualIdent_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_JavaGenElse__,
};

ILMachineType ILNode_LocalVar_ILNode_GetType__(ILNode_LocalVar *node, ILGenInfo * info)
#line 58 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 1056 "cg_lvalue.c"

void ILNode_LocalVar_ILNode_GenDiscard__(ILNode_LocalVar *node, ILGenInfo * info)
#line 122 "cg_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 1063 "cg_lvalue.c"

ILMachineType ILNode_LocalVar_ILNode_GenValue__(ILNode_LocalVar *node, ILGenInfo * info)
#line 183 "cg_lvalue.tc"
{
	ILGenLoadLocal(info, node->index);
	ILGenAdjust(info, 1);
	return node->machineType;
}
#line 1072 "cg_lvalue.c"

void ILNode_LocalVar_JavaGenDiscard__(ILNode_LocalVar *node, ILGenInfo * info)
#line 45 "jv_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 1079 "cg_lvalue.c"

ILMachineType ILNode_LocalVar_JavaGenValue__(ILNode_LocalVar *node, ILGenInfo * info)
#line 116 "jv_lvalue.tc"
{
	JavaGenLoadLocal(info, node->index, node->machineType);
	JavaGenAdjust(info, JavaGenTypeSize(node->machineType));
	return node->machineType;
}
#line 1088 "cg_lvalue.c"

ILMachineType ILNode_LocalVar_ILNode_Prepare__(ILNode_LocalVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 415 "cg_lvalue.tc"
{
	/* No preparation is needed for locals or arguments */
	return node->machineType;
}
#line 1096 "cg_lvalue.c"

ILMachineType ILNode_LocalVar_ILNode_GetAndPrepare__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 553 "cg_lvalue.tc"
{
	ILGenLoadLocal(info, node->index);
	ILGenAdjust(info, 1);
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	return node->machineType;
}
#line 1110 "cg_lvalue.c"

void ILNode_LocalVar_ILNode_Store__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1126 "cg_lvalue.tc"
{
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	ILGenStoreLocal(info, node->index);
	ILGenAdjust(info, -1);
}
#line 1123 "cg_lvalue.c"

void ILNode_LocalVar_ILNode_GenRef__(ILNode_LocalVar *node, ILGenInfo * info)
#line 1436 "cg_lvalue.tc"
{
	ILGenLoadLocalAddr(info, node->index);
	ILGenAdjust(info, 1);
}
#line 1131 "cg_lvalue.c"

ILMachineType ILNode_LocalVar_JavaPrepare__(ILNode_LocalVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 331 "jv_lvalue.tc"
{
	/* No preparation is needed for locals or arguments */
	return node->machineType;
}
#line 1139 "cg_lvalue.c"

ILMachineType ILNode_LocalVar_JavaGetAndPrepare__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 466 "jv_lvalue.tc"
{
	int size = JavaGenTypeSize(node->machineType);
	JavaGenLoadLocal(info, node->index, node->machineType);
	JavaGenAdjust(info, size);
	if(leave)
	{
		JavaGenDup(info, node->machineType);
	}
	return node->machineType;
}
#line 1153 "cg_lvalue.c"

void ILNode_LocalVar_JavaStore__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 844 "jv_lvalue.tc"
{
	int size = JavaGenTypeSize(node->machineType);
	if(leave)
	{
		JavaGenDup(info, node->machineType);
	}
	JavaGenStoreLocal(info, node->index, node->machineType);
	JavaGenAdjust(info, -size);
}
#line 1166 "cg_lvalue.c"

struct ILNode_LocalVar_vtable__ const ILNode_LocalVar_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_LocalVar_kind,
	"ILNode_LocalVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalVar_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalVar_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_LocalVar_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_LocalVar_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_LocalVar_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LocalVar_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_LocalVar_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_LocalVar_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_LocalVar_JavaStore__,
};

ILMachineType ILNode_ArgumentVar_ILNode_GetType__(ILNode_ArgumentVar *node, ILGenInfo * info)
#line 58 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 1197 "cg_lvalue.c"

void ILNode_ArgumentVar_ILNode_GenDiscard__(ILNode_ArgumentVar *node, ILGenInfo * info)
#line 122 "cg_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 1204 "cg_lvalue.c"

ILMachineType ILNode_ArgumentVar_ILNode_GenValue__(ILNode_ArgumentVar *node, ILGenInfo * info)
#line 193 "cg_lvalue.tc"
{
	ILGenLoadArg(info, node->index);
	ILGenAdjust(info, 1);
	return node->machineType;
}
#line 1213 "cg_lvalue.c"

void ILNode_ArgumentVar_JavaGenDiscard__(ILNode_ArgumentVar *node, ILGenInfo * info)
#line 45 "jv_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 1220 "cg_lvalue.c"

ILMachineType ILNode_ArgumentVar_JavaGenValue__(ILNode_ArgumentVar *node, ILGenInfo * info)
#line 127 "jv_lvalue.tc"
{
	JavaGenLoadArg(info, node->index, node->machineType);
	JavaGenAdjust(info, JavaGenTypeSize(node->machineType));
	return node->machineType;
}
#line 1229 "cg_lvalue.c"

ILMachineType ILNode_ArgumentVar_ILNode_Prepare__(ILNode_ArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 415 "cg_lvalue.tc"
{
	/* No preparation is needed for locals or arguments */
	return node->machineType;
}
#line 1237 "cg_lvalue.c"

ILMachineType ILNode_ArgumentVar_ILNode_GetAndPrepare__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 568 "cg_lvalue.tc"
{
	ILGenLoadArg(info, node->index);
	ILGenAdjust(info, 1);
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	return node->machineType;
}
#line 1251 "cg_lvalue.c"

void ILNode_ArgumentVar_ILNode_Store__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1140 "cg_lvalue.tc"
{
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	ILGenStoreArg(info, node->index);
	ILGenAdjust(info, -1);
}
#line 1264 "cg_lvalue.c"

void ILNode_ArgumentVar_ILNode_GenRef__(ILNode_ArgumentVar *node, ILGenInfo * info)
#line 1445 "cg_lvalue.tc"
{
	ILGenLoadArgAddr(info, node->index);
	ILGenAdjust(info, 1);
}
#line 1272 "cg_lvalue.c"

ILMachineType ILNode_ArgumentVar_JavaPrepare__(ILNode_ArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 331 "jv_lvalue.tc"
{
	/* No preparation is needed for locals or arguments */
	return node->machineType;
}
#line 1280 "cg_lvalue.c"

ILMachineType ILNode_ArgumentVar_JavaGetAndPrepare__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 482 "jv_lvalue.tc"
{
	int size = JavaGenTypeSize(node->machineType);
	JavaGenLoadArg(info, node->index, node->machineType);
	JavaGenAdjust(info, size);
	if(leave)
	{
		JavaGenDup(info, node->machineType);
	}
	return node->machineType;
}
#line 1294 "cg_lvalue.c"

void ILNode_ArgumentVar_JavaStore__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 859 "jv_lvalue.tc"
{
	int size = JavaGenTypeSize(node->machineType);
	if(leave)
	{
		JavaGenDup(info, node->machineType);
	}
	JavaGenStoreArg(info, node->index, node->machineType);
	JavaGenAdjust(info, -size);
}
#line 1307 "cg_lvalue.c"

struct ILNode_ArgumentVar_vtable__ const ILNode_ArgumentVar_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_ArgumentVar_kind,
	"ILNode_ArgumentVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgumentVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgumentVar_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgumentVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgumentVar_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArgumentVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_ArgumentVar_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_ArgumentVar_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_ArgumentVar_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_ArgumentVar_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_ArgumentVar_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_ArgumentVar_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_ArgumentVar_JavaStore__,
};

ILMachineType ILNode_RefArgumentVar_ILNode_GetType__(ILNode_RefArgumentVar *node, ILGenInfo * info)
#line 66 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 1338 "cg_lvalue.c"

void ILNode_RefArgumentVar_ILNode_GenDiscard__(ILNode_RefArgumentVar *node, ILGenInfo * info)
#line 122 "cg_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 1345 "cg_lvalue.c"

ILMachineType ILNode_RefArgumentVar_ILNode_GenValue__(ILNode_RefArgumentVar *node, ILGenInfo * info)
#line 203 "cg_lvalue.tc"
{
	/* Load the reference onto the stack */
	ILGenLoadArg(info, node->index);
	ILGenAdjust(info, 1);

	/* Dereference the pointer to get the actual value */
	ILGenLoadManaged(info, node->machineType, node->type);

	/* Return the value's type to the caller */
	return node->machineType;
}
#line 1360 "cg_lvalue.c"

void ILNode_RefArgumentVar_JavaGenDiscard__(ILNode_RefArgumentVar *node, ILGenInfo * info)
#line 45 "jv_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 1367 "cg_lvalue.c"

ILMachineType ILNode_RefArgumentVar_JavaGenValue__(ILNode_RefArgumentVar *node, ILGenInfo * info)
#line 127 "jv_lvalue.tc"
{
	JavaGenLoadArg(info, node->index, node->machineType);
	JavaGenAdjust(info, JavaGenTypeSize(node->machineType));
	return node->machineType;
}
#line 1376 "cg_lvalue.c"

ILMachineType ILNode_RefArgumentVar_ILNode_Prepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 424 "cg_lvalue.tc"
{
	/* Load the managed pointer onto the stack */
	ILGenLoadArg(info, node->index);
	ILGenAdjust(info, 1);
	return node->machineType;
}
#line 1386 "cg_lvalue.c"

ILMachineType ILNode_RefArgumentVar_ILNode_GetAndPrepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 583 "cg_lvalue.tc"
{
	/* Do we need to leave an extra copy of the value on the stack? */
	if(leave)
	{
		/* Load the managed pointer onto the stack */
		ILGenLoadArg(info, node->index);
		ILGenAdjust(info, 1);

		/* Get the current value of the variable for the left copy */
		ILGenLoadManaged(info, node->machineType, node->type);
	}

	/* Load the managed pointer onto the stack */
	ILGenLoadArg(info, node->index);
	ILGenAdjust(info, 1);

	/* Duplicate the pointer for a later store */
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);

	/* Get the current value of the variable */
	ILGenLoadManaged(info, node->machineType, node->type);

	/* Return the value's type to the caller */
	return node->machineType;
}
#line 1416 "cg_lvalue.c"

void ILNode_RefArgumentVar_ILNode_Store__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1154 "cg_lvalue.tc"
{
	if(leave)
	{
		/* Allocate a temporary local to hold the "left" copy */
		unsigned tempVar = ILGenTempTypedVar(info, node->type);

		/* Duplicate the top-most value and store into the temporary local */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempVar);
		ILGenAdjust(info, -1);

		/* Store the value into the managed pointer */
		ILGenStoreManaged(info, node->machineType, node->type);
		ILGenAdjust(info, -2);

		/* Re-push the temporary local */
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);

		/* Release the temporary local, which we no longer require */
		ILGenReleaseTempVar(info, tempVar);
	}
	else
	{
		/* Store the value into the managed pointer */
		ILGenStoreManaged(info, node->machineType, node->type);
		ILGenAdjust(info, -2);
	}
}
#line 1450 "cg_lvalue.c"

void ILNode_RefArgumentVar_ILNode_GenRef__(ILNode_RefArgumentVar *node, ILGenInfo * info)
#line 1454 "cg_lvalue.tc"
{
	ILGenLoadArg(info, node->index);
	ILGenAdjust(info, 1);
}
#line 1458 "cg_lvalue.c"

ILMachineType ILNode_RefArgumentVar_JavaPrepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 331 "jv_lvalue.tc"
{
	/* No preparation is needed for locals or arguments */
	return node->machineType;
}
#line 1466 "cg_lvalue.c"

ILMachineType ILNode_RefArgumentVar_JavaGetAndPrepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 482 "jv_lvalue.tc"
{
	int size = JavaGenTypeSize(node->machineType);
	JavaGenLoadArg(info, node->index, node->machineType);
	JavaGenAdjust(info, size);
	if(leave)
	{
		JavaGenDup(info, node->machineType);
	}
	return node->machineType;
}
#line 1480 "cg_lvalue.c"

void ILNode_RefArgumentVar_JavaStore__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 859 "jv_lvalue.tc"
{
	int size = JavaGenTypeSize(node->machineType);
	if(leave)
	{
		JavaGenDup(info, node->machineType);
	}
	JavaGenStoreArg(info, node->index, node->machineType);
	JavaGenAdjust(info, -size);
}
#line 1493 "cg_lvalue.c"

struct ILNode_RefArgumentVar_vtable__ const ILNode_RefArgumentVar_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_RefArgumentVar_kind,
	"ILNode_RefArgumentVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefArgumentVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_RefArgumentVar_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefArgumentVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_RefArgumentVar_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_RefArgumentVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_RefArgumentVar_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_RefArgumentVar_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_RefArgumentVar_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_RefArgumentVar_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_RefArgumentVar_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_RefArgumentVar_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_RefArgumentVar_JavaStore__,
};

ILMachineType ILNode_StaticField_ILNode_GetType__(ILNode_StaticField *node, ILGenInfo * info)
#line 86 "cg_lvalue.tc"
{
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1524 "cg_lvalue.c"

void ILNode_StaticField_ILNode_GenDiscard__(ILNode_StaticField *node, ILGenInfo * info)
#line 157 "cg_lvalue.tc"
{
	/* Nothing to do here */
}
#line 1531 "cg_lvalue.c"

ILMachineType ILNode_StaticField_ILNode_GenValue__(ILNode_StaticField *node, ILGenInfo * info)
#line 279 "cg_lvalue.tc"
{
	ILGenFieldRef(info, IL_OP_LDSFLD, node->field);
	ILGenAdjust(info, 1);
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1540 "cg_lvalue.c"

void ILNode_StaticField_JavaGenDiscard__(ILNode_StaticField *node, ILGenInfo * info)
#line 79 "jv_lvalue.tc"
{
	/* Nothing to do here */
}
#line 1547 "cg_lvalue.c"

ILMachineType ILNode_StaticField_JavaGenValue__(ILNode_StaticField *node, ILGenInfo * info)
#line 220 "jv_lvalue.tc"
{
	ILMachineType type = ILTypeToMachineType(ILField_Type(node->field));
	JavaGenFieldRef(info, JAVA_OP_GETSTATIC, node->field);
	JavaGenAdjust(info, JavaGenTypeSize(type));
	ValidateValueType(info, type, ILField_Type(node->field));
	return type;
}
#line 1558 "cg_lvalue.c"

ILMachineType ILNode_StaticField_ILNode_Prepare__(ILNode_StaticField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 472 "cg_lvalue.tc"
{
	/* Nothing needs to be done here */
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1566 "cg_lvalue.c"

ILMachineType ILNode_StaticField_ILNode_GetAndPrepare__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 675 "cg_lvalue.tc"
{
	ILGenFieldRef(info, IL_OP_LDSFLD, node->field);
	ILGenAdjust(info, 1);
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1580 "cg_lvalue.c"

void ILNode_StaticField_ILNode_Store__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1213 "cg_lvalue.tc"
{
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	ILGenFieldRef(info, IL_OP_STSFLD, node->field);
	ILGenAdjust(info, -1);
}
#line 1593 "cg_lvalue.c"

void ILNode_StaticField_ILNode_GenRef__(ILNode_StaticField *node, ILGenInfo * info)
#line 1463 "cg_lvalue.tc"
{
	ILGenFieldRef(info, IL_OP_LDSFLDA, node->field);
	ILGenAdjust(info, 1);
}
#line 1601 "cg_lvalue.c"

ILMachineType ILNode_StaticField_JavaPrepare__(ILNode_StaticField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 376 "jv_lvalue.tc"
{
	/* Nothing needs to be done here */
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1609 "cg_lvalue.c"

ILMachineType ILNode_StaticField_JavaGetAndPrepare__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 533 "jv_lvalue.tc"
{
	ILMachineType type = ILTypeToMachineType(ILField_Type(node->field));
	JavaGenFieldRef(info, JAVA_OP_GETSTATIC, node->field);
	JavaGenAdjust(info, JavaGenTypeSize(type));
	ValidateValueType(info, type, ILField_Type(node->field));
	if(leave)
	{
		JavaGenDup(info, type);
	}
	return type;
}
#line 1624 "cg_lvalue.c"

void ILNode_StaticField_JavaStore__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 905 "jv_lvalue.tc"
{
	ILMachineType type = ILTypeToMachineType(ILField_Type(node->field));
	int size = JavaGenTypeSize(type);
	if(leave)
	{
		JavaGenDup(info, type);
	}
	JavaGenFieldRef(info, JAVA_OP_PUTSTATIC, node->field);
	JavaGenAdjust(info, -size);
}
#line 1638 "cg_lvalue.c"

struct ILNode_StaticField_vtable__ const ILNode_StaticField_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_StaticField_kind,
	"ILNode_StaticField",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticField_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticField_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticField_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticField_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticField_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_StaticField_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_StaticField_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_StaticField_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_StaticField_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_StaticField_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_StaticField_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_StaticField_JavaStore__,
};

ILMachineType ILNode_MemberField_ILNode_GetType__(ILNode_MemberField *node, ILGenInfo * info)
#line 86 "cg_lvalue.tc"
{
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1669 "cg_lvalue.c"

ILMachineType ILNode_MemberField_ILNode_GenValue__(ILNode_MemberField *node, ILGenInfo * info)
#line 289 "cg_lvalue.tc"
{
	unsigned tempVar = ILGenPrepareForThisAccess
		(info, node->expr, ILField_Owner(node->field), 1);
	ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	ILGenFreeThisVar(info, tempVar);
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1680 "cg_lvalue.c"

void ILNode_MemberField_JavaGenDiscard__(ILNode_MemberField *node, ILGenInfo * info)
#line 87 "jv_lvalue.tc"
{
	/* Evaluate the object expression for its side-effects only */
	JavaGenDiscard(node->expr, info);
}
#line 1688 "cg_lvalue.c"

ILMachineType ILNode_MemberField_JavaGenValue__(ILNode_MemberField *node, ILGenInfo * info)
#line 232 "jv_lvalue.tc"
{
	ILMachineType type = ILTypeToMachineType(ILField_Type(node->field));
	JavaPrepareForThisAccess(info, node->expr, ILField_Owner(node->field));
	JavaGenFieldRef(info, JAVA_OP_GETFIELD, node->field);
	JavaGenAdjust(info, JavaGenTypeSize(type) - 1);
	ValidateValueType(info, type, ILField_Type(node->field));
	return type;
}
#line 1700 "cg_lvalue.c"

ILMachineType ILNode_MemberField_ILNode_Prepare__(ILNode_MemberField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 481 "cg_lvalue.tc"
{
	ILGenPrepareForThisAccess(info, node->expr, ILField_Owner(node->field), 0);
	node->tempVar = IL_MAX_UINT32;
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1709 "cg_lvalue.c"

ILMachineType ILNode_MemberField_ILNode_GetAndPrepare__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 690 "cg_lvalue.tc"
{
	/* Generate the object reference */
	ILGenPrepareForThisAccess(info, node->expr, ILField_Owner(node->field), 0);

	/* Do we need to leave the current value on the stack for later? */
	if(leave)
	{
		/* Duplicate the object reference and get the current value */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);

		/* Store the current value into a temporary local */
		node->tempVar = ILGenTempTypedVar(info, ILField_Type(node->field));
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, node->tempVar);
		ILGenExtend(info, 1);
	}
	else
	{
		/* Duplicate the object reference for the later store */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);

		/* Load the current value from the field */
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);

		/* We don't need to reload a previous value in "Store" */
		node->tempVar = IL_MAX_UINT32;
	}
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1745 "cg_lvalue.c"

void ILNode_MemberField_ILNode_Store__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1228 "cg_lvalue.tc"
{
	if(leave)
	{
		/* Copy the result into a temporary local */
		unsigned temp = ILGenTempTypedVar(info, ILField_Type(node->field));
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, temp);
		ILGenExtend(info, 1);

		/* Store the value into the field */
		ILGenFieldRef(info, IL_OP_STFLD, node->field);
		ILGenAdjust(info, -2);

		/* Do we need to restore a previous value to the stack top? */
		if(node->tempVar != IL_MAX_UINT32)
		{
			ILGenLoadLocal(info, node->tempVar);
			ILGenAdjust(info, 1);
			ILGenReleaseTempVar(info, node->tempVar);
		}

		/* Reload the contents of the temporary local */
		ILGenLoadLocal(info, temp);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, temp);
	}
	else
	{
		/* Store the value into the field */
		ILGenFieldRef(info, IL_OP_STFLD, node->field);
		ILGenAdjust(info, -2);

		/* Do we need to restore a previous value to the stack top? */
		if(node->tempVar != IL_MAX_UINT32)
		{
			ILGenLoadLocal(info, node->tempVar);
			ILGenAdjust(info, 1);
			ILGenReleaseTempVar(info, node->tempVar);
		}
	}
}
#line 1790 "cg_lvalue.c"

void ILNode_MemberField_ILNode_GenRef__(ILNode_MemberField *node, ILGenInfo * info)
#line 1472 "cg_lvalue.tc"
{
	unsigned tempVar = ILGenPrepareForThisAccess
		(info, node->expr, ILField_Owner(node->field), 1);
	ILGenFieldRef(info, IL_OP_LDFLDA, node->field);
	ILGenFreeThisVar(info, tempVar);
}
#line 1800 "cg_lvalue.c"

ILMachineType ILNode_MemberField_JavaPrepare__(ILNode_MemberField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 385 "jv_lvalue.tc"
{
	JavaPrepareForThisAccess(info, node->expr, ILField_Owner(node->field));
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 1808 "cg_lvalue.c"

ILMachineType ILNode_MemberField_JavaGetAndPrepare__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 549 "jv_lvalue.tc"
{
	ILMachineType type = ILTypeToMachineType(ILField_Type(node->field));
	int size = JavaGenTypeSize(type);

	/* Generate the object reference */
	JavaPrepareForThisAccess(info, node->expr, ILField_Owner(node->field));

	/* Duplicate it and get the current value */
	JavaGenDup(info, type);
	JavaGenFieldRef(info, JAVA_OP_GETFIELD, node->field);
	JavaGenAdjust(info, size - 1);
	ValidateValueType(info, type, ILField_Type(node->field));

	/* If the value should be left on the stack, then duplicate it */
	if(leave)
	{
		if(size == 1)
		{
			JavaGenSimple(info, JAVA_OP_DUP_X1);
		}
		else if(size == 2)
		{
			JavaGenSimple(info, JAVA_OP_DUP2_X1);
		}
		JavaGenAdjust(info, size);
	}

	/* Return the field's machine type to the caller */
	return type;
}
#line 1842 "cg_lvalue.c"

void ILNode_MemberField_JavaStore__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 920 "jv_lvalue.tc"
{
	ILMachineType type = ILTypeToMachineType(ILField_Type(node->field));
	int size = JavaGenTypeSize(type);

	/* Duplicate the value on the stack if we need it afterwards */
	if(leave)
	{
		if(size == 1)
		{
			JavaGenSimple(info, JAVA_OP_DUP_X1);
		}
		else if(size == 2)
		{
			JavaGenSimple(info, JAVA_OP_DUP2_X1);
		}
		JavaGenAdjust(info, size);
	}

	/* Store the value into the field */
	JavaGenFieldRef(info, JAVA_OP_PUTFIELD, node->field);
	JavaGenAdjust(info, -(size + 1));
}
#line 1868 "cg_lvalue.c"

struct ILNode_MemberField_vtable__ const ILNode_MemberField_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_MemberField_kind,
	"ILNode_MemberField",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberField_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberField_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberField_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberField_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_MemberField_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_MemberField_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_MemberField_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_MemberField_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_MemberField_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_MemberField_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_MemberField_JavaStore__,
};

ILMachineType ILNode_ArrayAccess_ILNode_GetType__(ILNode_ArrayAccess *node, ILGenInfo * info)
#line 104 "cg_lvalue.tc"
{
	return ILTypeToMachineType(node->elemType);
}
#line 1899 "cg_lvalue.c"

void ILNode_ArrayAccess_ILNode_GenDiscard__(ILNode_ArrayAccess *node, ILGenInfo * info)
#line 165 "cg_lvalue.tc"
{
	ILNode_GenDiscard(node->array, info);
	ILNode_GenDiscard(node->indices, info);
}
#line 1907 "cg_lvalue.c"

ILMachineType ILNode_ArrayAccess_ILNode_GenValue__(ILNode_ArrayAccess *node, ILGenInfo * info)
#line 362 "cg_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	long saveStack;
	if(ILType_IsSimpleArray(node->arrayType))
	{
		/* We can use a simple "ldelem" instruction */
		ILNode_GenValue(node->array, info);
		ILNode_GenValue(node->indices, info);
		ILGenLoadArray(info, machineType, node->elemType);
		ILGenAdjust(info, -1);
	}
	else
	{
		/* We have to call a method to get the value */
		saveStack = info->stackHeight;
		ILNode_GenValue(node->array, info);
		ILNode_GenValue(node->indices, info);
		CallMArrayMethod(info, node->arrayType, "Get");
		info->stackHeight = saveStack + 1;
	}
	return machineType;
}
#line 1933 "cg_lvalue.c"

void ILNode_ArrayAccess_JavaGenDiscard__(ILNode_ArrayAccess *node, ILGenInfo * info)
#line 96 "jv_lvalue.tc"
{
	/* Evaluate the sub-expressions for their side-effects only */
	JavaGenDiscard(node->array, info);
	JavaGenDiscard(node->indices, info);
}
#line 1942 "cg_lvalue.c"

ILMachineType ILNode_ArrayAccess_JavaGenValue__(ILNode_ArrayAccess *node, ILGenInfo * info)
#line 274 "jv_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	int rank, dim, posn;
	ILNode *indexNode;

	/* Multi-dimensional arrays are represented as a tree
	   of single-dimensional arrays which we must index
	   into one at a time */
	JavaGenValue(node->array, info);
	rank = ILTypeGetRank(node->arrayType);
	for(dim = 0; dim < rank; ++dim)
	{
		posn = rank - dim;
		indexNode = node->indices;
		while(posn > 1)
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr1;
			--posn;
		}
		if(yyisa(indexNode, ILNode_ArgList))
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr2;
		}
		JavaGenValue(indexNode, info);
		if((dim + 1) < rank)
		{
			JavaGenSimple(info, JAVA_OP_AALOAD);
			JavaGenAdjust(info, -1);
		}
	}

	/* Index into the final array dimension to get the value */
	JavaGenLoadArray(info, machineType);
	JavaGenAdjust(info, -2 + JavaGenTypeSize(machineType));
	ValidateValueType(info, machineType, node->elemType);
	return machineType;
}
#line 1983 "cg_lvalue.c"

ILMachineType ILNode_ArrayAccess_ILNode_Prepare__(ILNode_ArrayAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 512 "cg_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);

	/* Save the current stack position, so "Store" knows what to pop */
	node->saveStack = info->stackHeight;

	/* Push the object and indices onto the stack */
	ILNode_GenValue(node->array, info);
	ILNode_GenValue(node->indices, info);

	/* If this is a simple array of managed values, then we need to
	   compute the address of the element for use in the store */
	if(ILType_IsSimpleArray(node->arrayType) &&
	   (machineType == ILMachineType_Decimal ||
	    machineType == ILMachineType_ManagedValue))
	{
		ILGenTypeToken(info, IL_OP_LDELEMA, node->elemType);
		ILGenAdjust(info, -1);
	}

	/* Return the element's machine type to the caller */
	return machineType;
}
#line 2010 "cg_lvalue.c"

ILMachineType ILNode_ArrayAccess_ILNode_GetAndPrepare__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 802 "cg_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	unsigned tempArrayVar;
	unsigned tempIndexVar;
	unsigned tempValueVar;
	unsigned *tempIndexVars;
	int rank, dim, posn;
	ILNode *indexNode;
	int isManagedValue;

	/* Save the current stack position so "Store" knows what to pop */
	node->saveStack = info->stackHeight;

	/* Determine if the element type is a managed value */
	isManagedValue = (machineType == ILMachineType_Decimal ||
					  machineType == ILMachineType_ManagedValue);

	/* Determine what kind of array we are dealing with */
	if(ILType_IsSimpleArray(node->arrayType))
	{
		/* We need some temporary variables to assist with
		   the duplication of the values */
		tempArrayVar = ILGenTempTypedVar(info, node->arrayType);
		tempIndexVar = ILGenTempTypedVar(info, ILType_Int32);

		/* Get the array reference and save it */
		ILNode_GenValue(node->array, info);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempArrayVar);
		ILGenAdjust(info, -1);

		/* Get the index value and save it */
		ILNode_GenValue(node->indices, info);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempIndexVar);
		ILGenAdjust(info, -1);

		/* Do we need to leave the current value on the stack? */
		if(leave)
		{
			/* Get the array element and save it */
			tempValueVar = ILGenTempTypedVar(info, node->elemType);
			ILGenLoadArray(info, machineType, node->elemType);
			ILGenSimple(info, IL_OP_DUP);
			ILGenStoreLocal(info, tempValueVar);
			ILGenAdjust(info, -1);

			/* Reload all saved values back onto the stack */
			ILGenLoadLocal(info, tempArrayVar);
			ILGenLoadLocal(info, tempIndexVar);
			ILGenAdjust(info, 2);
			if(isManagedValue)
			{
				/* When we do the store, we need an address on the stack */
				ILGenTypeToken(info, IL_OP_LDELEMA, node->elemType);
				ILGenAdjust(info, -1);
			}
			ILGenLoadLocal(info, tempValueVar);
			ILGenAdjust(info, 1);

			/* Account for the extra value that we will be leaving behind */
			++(node->saveStack);

			/* Release the extra temporary variable that we used */
			ILGenReleaseTempVar(info, tempValueVar);
		}
		else
		{
			/* Managed value stores use an address, not an object/index pair */
			if(isManagedValue)
			{
				ILGenTypeToken(info, IL_OP_LDELEMA, node->elemType);
				ILGenAdjust(info, -1);
			}

			/* Reload the values onto the stack and get the array element */
			ILGenLoadLocal(info, tempArrayVar);
			ILGenLoadLocal(info, tempIndexVar);
			ILGenAdjust(info, 2);
			ILGenLoadArray(info, machineType, node->elemType);
			ILGenAdjust(info, -1);
		}

		/* Release the temporary variables */
		ILGenReleaseTempVar(info, tempArrayVar);
		ILGenReleaseTempVar(info, tempIndexVar);
	}
	else
	{
		/* Get temporary variables for the array and the indices */
		tempArrayVar = ILGenTempTypedVar(info, node->arrayType);
		rank = ILTypeGetRank(node->arrayType);
		tempIndexVars = (unsigned *)ILMalloc(sizeof(unsigned) * rank);
		if(!tempIndexVars)
		{
			ILGenOutOfMemory(info);
		}
		for(dim = 0; dim < rank; ++dim)
		{
			tempIndexVars[dim] = ILGenTempTypedVar(info, ILType_Int32);
		}

		/* Get the array reference and save it */
		ILNode_GenValue(node->array, info);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempArrayVar);
		ILGenAdjust(info, -1);

		/* Get the index values and save them */
		for(dim = 0; dim < rank; ++dim)
		{
			posn = rank - dim;
			indexNode = node->indices;
			while(posn > 1)
			{
				indexNode = ((ILNode_ArgList *)indexNode)->expr1;
				--posn;
			}
			if(yyisa(indexNode, ILNode_ArgList))
			{
				indexNode = ((ILNode_ArgList *)indexNode)->expr2;
			}
			ILNode_GenValue(indexNode, info);
			ILGenSimple(info, IL_OP_DUP);
			ILGenAdjust(info, 1);
			ILGenStoreLocal(info, tempIndexVars[dim]);
			ILGenAdjust(info, -1);
		}

		/* Do we need to leave the current value on the stack? */
		if(leave)
		{
			/* Get the array element and save it */
			tempValueVar = ILGenTempTypedVar(info, node->elemType);
			CallMArrayMethod(info, node->arrayType, "Get");
			ILGenAdjust(info, -rank);
			ILGenSimple(info, IL_OP_DUP);
			ILGenAdjust(info, 1);
			ILGenStoreLocal(info, tempValueVar);
			ILGenAdjust(info, -1);

			/* Reload all saved values back onto the stack */
			ILGenLoadLocal(info, tempArrayVar);
			ILGenAdjust(info, 1);
			for(dim = 0; dim < rank; ++dim)
			{
				ILGenLoadLocal(info, tempIndexVars[dim]);
				ILGenAdjust(info, 1);
			}
			ILGenLoadLocal(info, tempValueVar);
			ILGenAdjust(info, 1);

			/* Account for the extra value that we will be leaving behind */
			++(node->saveStack);

			/* Release the extra temporary variable that we used */
			ILGenReleaseTempVar(info, tempValueVar);
		}
		else
		{
			/* Reload the values onto the stack and get the array element */
			ILGenLoadLocal(info, tempArrayVar);
			ILGenAdjust(info, 1);
			for(dim = 0; dim < rank; ++dim)
			{
				ILGenLoadLocal(info, tempIndexVars[dim]);
				ILGenAdjust(info, 1);
			}
			CallMArrayMethod(info, node->arrayType, "Get");
			ILGenAdjust(info, -rank);
		}

		/* Release the temporary variables */
		ILGenReleaseTempVar(info, tempArrayVar);
		for(dim = 0; dim < rank; ++dim)
		{
			ILGenReleaseTempVar(info, tempIndexVars[dim]);
		}
		ILFree(tempIndexVars);
	}
	return machineType;
}
#line 2199 "cg_lvalue.c"

void ILNode_ArrayAccess_ILNode_Store__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1351 "cg_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	unsigned tempVar;

	/* If we need to leave the value on the stack, then temporarily
	   save it into a local variable */
	if(leave)
	{
		tempVar = ILGenTempTypedVar(info, node->elemType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, tempVar);
		ILGenExtend(info, 1);
	}
	else
	{
		tempVar = 0;
	}

	/* Store the value into the array */
	if(ILType_IsSimpleArray(node->arrayType))
	{
		/* We can use a simple "stelem" instruction */
		ILGenStoreArray(info, machineType, node->elemType);
	}
	else
	{
		/* We have to call a method to store the value */
		CallMArrayMethod(info, node->arrayType, "Set");
	}

	/* Reset the stack to its original position */
	info->stackHeight = node->saveStack;

	/* Push the left value back onto the stack if necessary */
	if(leave)
	{
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar);
	}
}
#line 2244 "cg_lvalue.c"

void ILNode_ArrayAccess_ILNode_GenRef__(ILNode_ArrayAccess *node, ILGenInfo * info)
#line 1516 "cg_lvalue.tc"
{
	long saveStack;
	if(ILType_IsSimpleArray(node->arrayType))
	{
		/* We can use the "ldelema" instruction */
		ILNode_GenValue(node->array, info);
		ILNode_GenValue(node->indices, info);
		ILGenTypeToken(info, IL_OP_LDELEMA, node->elemType);
		ILGenAdjust(info, -1);
	}
	else
	{
		/* We have to call a method to get the address */
		saveStack = info->stackHeight;
		ILNode_GenValue(node->array, info);
		ILNode_GenValue(node->indices, info);
		CallMArrayMethod(info, node->arrayType, "Address");
		info->stackHeight = saveStack + 1;
	}
}
#line 2268 "cg_lvalue.c"

ILMachineType ILNode_ArrayAccess_JavaPrepare__(ILNode_ArrayAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 415 "jv_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	int rank, dim, posn;
	ILNode *indexNode;

	/* Multi-dimensional arrays are represented as a tree
	   of single-dimensional arrays which we must index
	   into one at a time */
	JavaGenValue(node->array, info);
	rank = ILTypeGetRank(node->arrayType);
	for(dim = 0; dim < rank; ++dim)
	{
		posn = rank - dim;
		indexNode = node->indices;
		while(posn > 1)
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr1;
			--posn;
		}
		if(yyisa(indexNode, ILNode_ArgList))
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr2;
		}
		JavaGenValue(indexNode, info);
		if((dim + 1) < rank)
		{
			JavaGenSimple(info, JAVA_OP_AALOAD);
			JavaGenAdjust(info, -1);
		}
	}

	/* The final array dimension is on the stack, together
	   with the index into it */
	return machineType;
}
#line 2307 "cg_lvalue.c"

ILMachineType ILNode_ArrayAccess_JavaGetAndPrepare__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 642 "jv_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	int size = JavaGenTypeSize(machineType);
	int rank, dim, posn;
	ILNode *indexNode;

	/* Multi-dimensional arrays are represented as a tree
	   of single-dimensional arrays which we must index
	   into one at a time */
	JavaGenValue(node->array, info);
	rank = ILTypeGetRank(node->arrayType);
	for(dim = 0; dim < rank; ++dim)
	{
		posn = rank - dim;
		indexNode = node->indices;
		while(posn > 1)
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr1;
			--posn;
		}
		if(yyisa(indexNode, ILNode_ArgList))
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr2;
		}
		if((dim + 1) == rank)
		{
			/* Duplicate the values for the final array dimension */
			JavaGenSimple(info, JAVA_OP_DUP);
			JavaGenAdjust(info, 1);
			JavaGenValue(indexNode, info);
			JavaGenSimple(info, JAVA_OP_DUP_X1);
			JavaGenAdjust(info, 1);
		}
		else
		{
			/* Index into the array for all other dimensions */
			JavaGenValue(indexNode, info);
			JavaGenSimple(info, JAVA_OP_AALOAD);
			JavaGenAdjust(info, -1);
		}
	}

	/* Get the value from the final array dimension */
	JavaGenLoadArray(info, machineType);
	JavaGenAdjust(info, -2 + size);
	ValidateValueType(info, machineType, node->elemType);

	/* Push it down the stack if it must be left after the store */
	if(leave)
	{
		if(size == 1)
		{
			JavaGenSimple(info, JAVA_OP_DUP_X2);
			JavaGenAdjust(info, 1);
		}
		else if(size == 2)
		{
			JavaGenSimple(info, JAVA_OP_DUP2_X2);
			JavaGenAdjust(info, 2);
		}
	}

	/* Finished */
	return machineType;
}
#line 2376 "cg_lvalue.c"

void ILNode_ArrayAccess_JavaStore__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 995 "jv_lvalue.tc"
{
	ILMachineType machineType = ILTypeToMachineType(node->elemType);
	JavaGenStoreArray(info, machineType);
	JavaGenAdjust(info, -2 - JavaGenTypeSize(machineType));
}
#line 2385 "cg_lvalue.c"

struct ILNode_ArrayAccess_vtable__ const ILNode_ArrayAccess_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_ArrayAccess_kind,
	"ILNode_ArrayAccess",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_ArrayAccess_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_ArrayAccess_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_ArrayAccess_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_ArrayAccess_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_ArrayAccess_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_ArrayAccess_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_ArrayAccess_JavaStore__,
};

ILMachineType ILNode_StaticProperty_ILNode_GetType__(ILNode_StaticProperty *node, ILGenInfo * info)
#line 95 "cg_lvalue.tc"
{
	ILType *signature = ILProperty_Signature(node->property);
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2417 "cg_lvalue.c"

void ILNode_StaticProperty_ILNode_GenDiscard__(ILNode_StaticProperty *node, ILGenInfo * info)
#line 157 "cg_lvalue.tc"
{
	/* Nothing to do here */
}
#line 2424 "cg_lvalue.c"

ILMachineType ILNode_StaticProperty_ILNode_GenValue__(ILNode_StaticProperty *node, ILGenInfo * info)
#line 301 "cg_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILGenCallMethod(info, getter);
	ILGenAdjust(info, 1);
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2435 "cg_lvalue.c"

ILMachineType ILNode_StaticProperty_JavaGenValue__(ILNode_StaticProperty *node, ILGenInfo * info)
#line 245 "jv_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILMachineType type = ILTypeToMachineType(ILTypeGetReturn(signature));
	JavaGenCallMethod(info, getter, info->stackHeight);
	JavaGenAdjust(info, JavaGenTypeSize(type) - 1);
	return type;
}
#line 2447 "cg_lvalue.c"

ILMachineType ILNode_StaticProperty_ILNode_Prepare__(ILNode_StaticProperty *node, ILGenInfo * info, void * * data1, void * * data2)
#line 491 "cg_lvalue.tc"
{
	ILType *signature = ILProperty_Signature(node->property);
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2455 "cg_lvalue.c"

ILMachineType ILNode_StaticProperty_ILNode_GetAndPrepare__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 727 "cg_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILGenCallMethod(info, getter);
	ILGenAdjust(info, 1);
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2471 "cg_lvalue.c"

void ILNode_StaticProperty_ILNode_Store__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1274 "cg_lvalue.tc"
{
	ILMethod *setter = ILProperty_Setter(node->property);
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	ILGenCallMethod(info, setter);
	ILGenAdjust(info, -1);
}
#line 2485 "cg_lvalue.c"

ILMachineType ILNode_StaticProperty_JavaPrepare__(ILNode_StaticProperty *node, ILGenInfo * info, void * * data1, void * * data2)
#line 394 "jv_lvalue.tc"
{
	/* Nothing needs to be done here */
	ILType *signature = ILProperty_Signature(node->property);
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2494 "cg_lvalue.c"

ILMachineType ILNode_StaticProperty_JavaGetAndPrepare__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 584 "jv_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILMachineType type = ILTypeToMachineType
		(ILTypeGetReturn(ILProperty_Signature(node->property)));
	JavaGenCallMethod(info, getter, info->stackHeight);
	JavaGenAdjust(info, JavaGenTypeSize(type));
	if(leave)
	{
		JavaGenDup(info, type);
	}
	return type;
}
#line 2510 "cg_lvalue.c"

void ILNode_StaticProperty_JavaStore__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 947 "jv_lvalue.tc"
{
	ILMethod *setter = ILProperty_Setter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILType *propType = ILTypeGetReturn(signature);
	ILMachineType type = ILTypeToMachineType(propType);
	int size = JavaGenTypeSize(type);
	if(leave)
	{
		JavaGenDup(info, type);
	}
	JavaGenCallMethod(info, setter, info->stackHeight - 1 - size);
	JavaGenAdjust(info, -(size + 1));
}
#line 2527 "cg_lvalue.c"

struct ILNode_StaticProperty_vtable__ const ILNode_StaticProperty_vt__ = {
	&ILNode_LValueNoRef_vt__,
	ILNode_StaticProperty_kind,
	"ILNode_StaticProperty",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticProperty_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticProperty_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticProperty_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StaticProperty_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_StaticProperty_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_StaticProperty_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_StaticProperty_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRef_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_StaticProperty_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_StaticProperty_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_StaticProperty_JavaStore__,
};

ILMachineType ILNode_MemberProperty_ILNode_GetType__(ILNode_MemberProperty *node, ILGenInfo * info)
#line 95 "cg_lvalue.tc"
{
	ILType *signature = ILProperty_Signature(node->property);
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2559 "cg_lvalue.c"

ILMachineType ILNode_MemberProperty_ILNode_GenValue__(ILNode_MemberProperty *node, ILGenInfo * info)
#line 313 "cg_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	unsigned tempVar = ILGenPrepareForThisAccess
		(info, node->expr, ILProperty_Owner(node->property), 0);
	if(node->baseCall)
	{
		ILGenCallByMethod(info, getter);
	}
	else
	{
		ILGenCallMethod(info,getter);
	}
	ILGenFreeThisVar(info, tempVar);
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2579 "cg_lvalue.c"

ILMachineType ILNode_MemberProperty_JavaGenValue__(ILNode_MemberProperty *node, ILGenInfo * info)
#line 258 "jv_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILMachineType type = ILTypeToMachineType(ILTypeGetReturn(signature));
	long saveStack = info->stackHeight;
	JavaPrepareForThisAccess(info, node->expr,
							 ILProperty_Owner(node->property));
	JavaGenCallMethod(info, getter, saveStack);
	JavaGenAdjust(info, JavaGenTypeSize(type) - 1);
	return type;
}
#line 2594 "cg_lvalue.c"

ILMachineType ILNode_MemberProperty_ILNode_Prepare__(ILNode_MemberProperty *node, ILGenInfo * info, void * * data1, void * * data2)
#line 500 "cg_lvalue.tc"
{
	ILType *signature = ILProperty_Signature(node->property);
	node->tempVar = IL_MAX_UINT32;
	ILGenPrepareForThisAccess(info, node->expr,
							  ILProperty_Owner(node->property), 0);
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2605 "cg_lvalue.c"

ILMachineType ILNode_MemberProperty_ILNode_GetAndPrepare__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 744 "cg_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILType *propType = ILTypeGetReturn(signature);
	if(leave)
	{
		/* Generate the object reference */
		ILGenPrepareForThisAccess(info, node->expr,
								  ILProperty_Owner(node->property), 0);

		/* Duplicate it and get the current value */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		if(node->baseCall)
		{
			ILGenCallByMethod(info, getter);
		}
		else
		{
			ILGenCallMethod(info, getter);
		}

		/* Store the current value into a temporary local */
		node->tempVar = ILGenTempTypedVar(info, propType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, node->tempVar);
		ILGenExtend(info, 1);
	}
	else
	{
		/* Generate the object reference */
		ILGenPrepareForThisAccess(info, node->expr,
								  ILProperty_Owner(node->property), 0);

		/* Duplicate it for the later store */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);

		/* Load the current value from the property */
		if(node->baseCall)
		{
			ILGenCallByMethod(info, getter);
		}
		else
		{
			ILGenCallMethod(info, getter);
		}

		/* We don't need to reload a previous value in "Store" */
		node->tempVar = IL_MAX_UINT32;
	}
	return ILTypeToMachineType(propType);
}
#line 2662 "cg_lvalue.c"

void ILNode_MemberProperty_ILNode_Store__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1289 "cg_lvalue.tc"
{
	ILMethod *setter = ILProperty_Setter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILType *propType = ILTypeGetReturn(signature);
	if(leave)
	{
		/* Copy the result into a temporary local */
		unsigned temp = ILGenTempTypedVar(info, propType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, temp);
		ILGenExtend(info, 1);
		if(node->baseCall)
		{
			ILGenCallByMethod(info,setter);
		}
		else
		{
			/* Store the value into the property */
			ILGenCallMethod(info, setter);
		}
		ILGenAdjust(info, -2);

		/* Do we need to restore a previous value to the stack top? */
		if(node->tempVar != IL_MAX_UINT32)
		{
			ILGenLoadLocal(info, node->tempVar);
			ILGenAdjust(info, 1);
			ILGenReleaseTempVar(info, node->tempVar);
		}

		/* Reload the contents of the temporary local */
		ILGenLoadLocal(info, temp);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, temp);
	}
	else
	{
		/* Store the value into the property */
		if(node->baseCall)
		{
			ILGenCallByMethod(info, setter);
		}
		else
		{
			ILGenCallMethod(info, setter);
		}
		ILGenAdjust(info, -2);

		/* Do we need to restore a previous value to the stack top? */
		if(node->tempVar != IL_MAX_UINT32)
		{
			ILGenLoadLocal(info, node->tempVar);
			ILGenAdjust(info, 1);
			ILGenReleaseTempVar(info, node->tempVar);
		}
	}
}
#line 2723 "cg_lvalue.c"

ILMachineType ILNode_MemberProperty_JavaPrepare__(ILNode_MemberProperty *node, ILGenInfo * info, void * * data1, void * * data2)
#line 404 "jv_lvalue.tc"
{
	ILType *signature = ILProperty_Signature(node->property);
	JavaPrepareForThisAccess(info, node->expr,
							 ILProperty_Owner(node->property));
	return ILTypeToMachineType(ILTypeGetReturn(signature));
}
#line 2733 "cg_lvalue.c"

ILMachineType ILNode_MemberProperty_JavaGetAndPrepare__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 601 "jv_lvalue.tc"
{
	ILMethod *getter = ILProperty_Getter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILType *propType = ILTypeGetReturn(signature);
	ILMachineType type = ILTypeToMachineType(propType);
	int size = JavaGenTypeSize(type);
	long saveStack;

	/* Generate the object reference */
	saveStack = info->stackHeight;
	JavaPrepareForThisAccess(info, node->expr,
							 ILProperty_Owner(node->property));

	/* Duplicate the object reference and get the current value */
	JavaGenSimple(info, JAVA_OP_DUP);
	JavaGenAdjust(info, 1);
	JavaGenCallMethod(info, getter, saveStack);
	JavaGenAdjust(info, size - 1);

	/* Duplicate the current value if necessary */
	if(leave)
	{
		if(size == 1)
		{
			JavaGenSimple(info, JAVA_OP_DUP_X1);
		}
		else if(size == 2)
		{
			JavaGenSimple(info, JAVA_OP_DUP2_X1);
		}
		JavaGenAdjust(info, size);
	}

	/* Return the property's machine type to the caller */
	return type;
}
#line 2773 "cg_lvalue.c"

void ILNode_MemberProperty_JavaStore__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 965 "jv_lvalue.tc"
{
	ILMethod *setter = ILProperty_Setter(node->property);
	ILType *signature = ILProperty_Signature(node->property);
	ILType *propType = ILTypeGetReturn(signature);
	ILMachineType type = ILTypeToMachineType(propType);
	int size = JavaGenTypeSize(type);

	/* Duplicate the top of stack if necessary */
	if(leave)
	{
		if(size == 1)
		{
			JavaGenSimple(info, JAVA_OP_DUP_X1);
		}
		else if(size == 2)
		{
			JavaGenSimple(info, JAVA_OP_DUP2_X1);
		}
		JavaGenAdjust(info, size);
	}

	/* Store the value into the property */
	JavaGenCallMethod(info, setter, info->stackHeight - 1 - size);
	JavaGenAdjust(info, -(size + 1));
}
#line 2802 "cg_lvalue.c"

struct ILNode_MemberProperty_vtable__ const ILNode_MemberProperty_vt__ = {
	&ILNode_LValueNoRef_vt__,
	ILNode_MemberProperty_kind,
	"ILNode_MemberProperty",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberProperty_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberProperty_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberProperty_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_MemberProperty_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_MemberProperty_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_MemberProperty_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRef_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_MemberProperty_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_MemberProperty_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_MemberProperty_JavaStore__,
};

ILMachineType ILNode_IndexerAccess_ILNode_GetType__(ILNode_IndexerAccess *node, ILGenInfo * info)
#line 112 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 2833 "cg_lvalue.c"

void ILNode_IndexerAccess_ILNode_GenDiscard__(ILNode_IndexerAccess *node, ILGenInfo * info)
#line 174 "cg_lvalue.tc"
{
	ILNode_GenDiscard(node->object, info);
	ILNode_GenDiscard(node->indices, info);
}
#line 2841 "cg_lvalue.c"

ILMachineType ILNode_IndexerAccess_ILNode_GenValue__(ILNode_IndexerAccess *node, ILGenInfo * info)
#line 389 "cg_lvalue.tc"
{
	long saveStack = info->stackHeight;
	unsigned thisTemp = ILGenPrepareForThisAccess
				(info, node->object, ILMethod_Owner(node->getMethod), 0);
						
	ILNode_GenValue(node->indices, info);
	if(node->baseAccess)
	{
		ILGenCallByMethod(info, node->getMethod);
	}
	else
	{
		ILGenCallMethod(info, node->getMethod);
	}
	info->stackHeight = saveStack + 1;

	/* Release the temporary local variable if necessary */
	ILGenFreeThisVar(info, thisTemp);
	return node->machineType;
}
#line 2865 "cg_lvalue.c"

void ILNode_IndexerAccess_JavaGenDiscard__(ILNode_IndexerAccess *node, ILGenInfo * info)
#line 106 "jv_lvalue.tc"
{
	/* Evaluate the sub-expressions for their side-effects only */
	JavaGenDiscard(node->object, info);
	JavaGenDiscard(node->indices, info);
}
#line 2874 "cg_lvalue.c"

ILMachineType ILNode_IndexerAccess_JavaGenValue__(ILNode_IndexerAccess *node, ILGenInfo * info)
#line 316 "jv_lvalue.tc"
{
	long saveStack = info->stackHeight;
	JavaGenValue(node->object, info);
	JavaGenValue(node->indices, info);
	JavaGenCallMethod(info, node->getMethod, saveStack);
	info->stackHeight = saveStack + JavaGenTypeSize(node->machineType);
	return node->machineType;
}
#line 2886 "cg_lvalue.c"

ILMachineType ILNode_IndexerAccess_ILNode_Prepare__(ILNode_IndexerAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 540 "cg_lvalue.tc"
{
	node->saveStack = info->stackHeight;
	ILGenPrepareForThisAccess(info, node->object, 
					ILType_ToClass(node->objectType), 
					1);
	ILNode_GenValue(node->indices, info);
	return node->machineType;
}
#line 2898 "cg_lvalue.c"

ILMachineType ILNode_IndexerAccess_ILNode_GetAndPrepare__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 992 "cg_lvalue.tc"
{
	unsigned tempObjectVar;
	unsigned tempValueVar;
	unsigned *tempIndexVars;
	int numArgs, argNum, posn;
	ILNode *indexNode;
	ILType *signature;

	/* Save the current stack position so "Store" knows what to pop */
	node->saveStack = info->stackHeight;

	/* Get the signature for the "get" method, so that we know
	   what types to use to temporarily save the index values */
	signature = ILMethod_Signature(node->getMethod);

	/* Get temporary variables for the object and the indices */
	tempObjectVar = ILGenTempTypedVar(info, node->objectType);
	numArgs = 1;
	indexNode = node->indices;
	while(yyisa(indexNode, ILNode_ArgList))
	{
		++numArgs;
		indexNode = ((ILNode_ArgList *)indexNode)->expr1;
	}
	tempIndexVars = (unsigned *)ILMalloc(sizeof(unsigned) * numArgs);
	if(!tempIndexVars)
	{
		ILGenOutOfMemory(info);
	}
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		tempIndexVars[argNum] = ILGenTempTypedVar
				(info, ILTypeGetParam(signature, argNum + 1));
	}

	/* Get the object reference and save it */
	ILNode_GenValue(node->object, info);
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);
	ILGenStoreLocal(info, tempObjectVar);
	ILGenAdjust(info, -1);

	/* Get the index values and save them */
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		posn = numArgs - argNum;
		indexNode = node->indices;
		while(posn > 1)
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr1;
			--posn;
		}
		if(yyisa(indexNode, ILNode_ArgList))
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr2;
		}
		ILNode_GenValue(indexNode, info);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempIndexVars[argNum]);
		ILGenAdjust(info, -1);
	}

	/* Do we need to leave the current value on the stack? */
	if(leave)
	{
		/* Get the indexer element and save it */
		tempValueVar = ILGenTempTypedVar(info, node->elemType);
		if(node->baseAccess)
		{
			ILGenCallByMethod(info, node->getMethod);
		}
		else
		{
			ILGenCallMethod(info, node->getMethod);
		}
		ILGenAdjust(info, -numArgs);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempValueVar);
		ILGenAdjust(info, -1);

		/* Reload all saved values back onto the stack */
		ILGenLoadLocal(info, tempObjectVar);
		ILGenAdjust(info, 1);
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			ILGenLoadLocal(info, tempIndexVars[argNum]);
			ILGenAdjust(info, 1);
		}
		ILGenLoadLocal(info, tempValueVar);
		ILGenAdjust(info, 1);

		/* Account for the extra value that we will be leaving behind */
		++(node->saveStack);

		/* Release the extra temporary variable that we used */
		ILGenReleaseTempVar(info, tempValueVar);
	}
	else
	{
		/* Reload the values onto the stack and get the indexer element */
		ILGenLoadLocal(info, tempObjectVar);
		ILGenAdjust(info, 1);
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			ILGenLoadLocal(info, tempIndexVars[argNum]);
			ILGenAdjust(info, 1);
		}
		if(node->baseAccess)
		{
			ILGenCallByMethod(info, node->getMethod);
		}
		else
		{
			ILGenCallMethod(info, node->getMethod);
		}
		ILGenAdjust(info, -numArgs);
	}

	/* Release the temporary variables */
	ILGenReleaseTempVar(info, tempObjectVar);
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		ILGenReleaseTempVar(info, tempIndexVars[argNum]);
	}
	ILFree(tempIndexVars);
	return node->machineType;
}
#line 3031 "cg_lvalue.c"

void ILNode_IndexerAccess_ILNode_Store__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1397 "cg_lvalue.tc"
{
	if(leave)
	{
		unsigned tempVar = ILGenTempTypedVar(info, node->elemType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempVar);
		ILGenAdjust(info, -1);
		if(node->baseAccess)
		{
			ILGenCallByMethod(info, node->setMethod);
		}
		else
		{
			ILGenCallMethod(info, node->setMethod);
		}
		info->stackHeight = node->saveStack;
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar);
	}
	else
	{
		if(node->baseAccess)
		{
			ILGenCallByMethod(info, node->setMethod);
		}
		else
		{
			ILGenCallMethod(info, node->setMethod);
		}
		info->stackHeight = node->saveStack;
	}
}
#line 3069 "cg_lvalue.c"

ILMachineType ILNode_IndexerAccess_JavaPrepare__(ILNode_IndexerAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 455 "jv_lvalue.tc"
{
	node->saveStack = info->stackHeight;
	JavaGenValue(node->object, info);
	JavaGenValue(node->indices, info);
	return node->machineType;
}
#line 3079 "cg_lvalue.c"

ILMachineType ILNode_IndexerAccess_JavaGetAndPrepare__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 712 "jv_lvalue.tc"
{
	unsigned tempObjectVar;
	unsigned tempValueVar;
	unsigned *tempIndexVars;
	int numArgs, argNum, posn;
	ILNode *indexNode;
	ILType *signature;
	ILMachineType objectMachineType;
	int objectSize;
	ILType *indexType;
	ILMachineType indexMachineType;

	/* Save the current stack position so "Store" knows what to pop */
	node->saveStack = info->stackHeight;

	/* Get the signature for the "get" method, so that we know
	   what types to use to temporarily save the index values */
	signature = ILMethod_Signature(node->getMethod);

	/* Get temporary variables for the object and the indices */
	tempObjectVar = ILGenTempTypedVar(info, node->objectType);
	numArgs = 1;
	indexNode = node->indices;
	while(yyisa(indexNode, ILNode_ArgList))
	{
		++numArgs;
		indexNode = ((ILNode_ArgList *)indexNode)->expr1;
	}
	tempIndexVars = (unsigned *)ILMalloc(sizeof(unsigned) * numArgs);
	if(!tempIndexVars)
	{
		ILGenOutOfMemory(info);
	}
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		tempIndexVars[argNum] = ILGenTempTypedVar
				(info, ILTypeGetParam(signature, argNum + 1));
	}

	/* Get the object reference and save it */
	JavaGenValue(node->object, info);
	objectMachineType = ILTypeToMachineType(node->objectType);
	objectSize = JavaGenTypeSize(objectMachineType);
	JavaGenDup(info, objectMachineType);
	JavaGenStoreLocal(info, tempObjectVar, objectMachineType);
	JavaGenAdjust(info, -objectSize);

	/* Get the index values and save them */
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		posn = numArgs - argNum;
		indexNode = node->indices;
		while(posn > 1)
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr1;
			--posn;
		}
		if(yyisa(indexNode, ILNode_ArgList))
		{
			indexNode = ((ILNode_ArgList *)indexNode)->expr2;
		}
		indexType = ILTypeGetParam(signature, argNum + 1);
		indexMachineType = ILTypeToMachineType(indexType);
		JavaGenValue(indexNode, info);
		JavaGenDup(info, indexMachineType);
		JavaGenStoreLocal(info, tempIndexVars[argNum], indexMachineType);
		JavaGenAdjust(info, -JavaGenTypeSize(indexMachineType));
	}

	/* Do we need to leave the current value on the stack? */
	if(leave)
	{
		/* Get the indexer element and save it */
		tempValueVar = ILGenTempTypedVar(info, node->elemType);
		indexMachineType = ILTypeToMachineType(node->elemType);
		JavaGenCallMethod(info, node->getMethod, node->saveStack);
		info->stackHeight = node->saveStack + JavaGenTypeSize(indexMachineType);
		JavaGenDup(info, indexMachineType);
		JavaGenStoreLocal(info, tempValueVar, indexMachineType);
		JavaGenAdjust(info, -JavaGenTypeSize(indexMachineType));

		/* Account for the extra value that we will be leaving behind */
		node->saveStack += JavaGenTypeSize(indexMachineType);

		/* Reload all saved values back onto the stack */
		JavaGenLoadLocal(info, tempObjectVar, objectMachineType);
		JavaGenAdjust(info, objectSize);
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			indexType = ILTypeGetParam(signature, argNum + 1);
			indexMachineType = ILTypeToMachineType(indexType);
			JavaGenLoadLocal(info, tempIndexVars[argNum], indexMachineType);
			JavaGenAdjust(info, JavaGenTypeSize(indexMachineType));
		}
		indexMachineType = ILTypeToMachineType(node->elemType);
		JavaGenLoadLocal(info, tempValueVar, indexMachineType);
		JavaGenAdjust(info, JavaGenTypeSize(indexMachineType));

		/* Release the extra temporary variable that we used */
		ILGenReleaseTempVar(info, tempValueVar);
	}
	else
	{
		/* Reload the values onto the stack and get the indexer element */
		JavaGenLoadLocal(info, tempObjectVar, objectMachineType);
		JavaGenAdjust(info, objectSize);
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			indexType = ILTypeGetParam(signature, argNum + 1);
			indexMachineType = ILTypeToMachineType(indexType);
			JavaGenLoadLocal(info, tempIndexVars[argNum], indexMachineType);
			JavaGenAdjust(info, JavaGenTypeSize(indexMachineType));
		}
		JavaGenCallMethod(info, node->getMethod, node->saveStack);
		indexMachineType = ILTypeToMachineType(node->elemType);
		info->stackHeight = node->saveStack + JavaGenTypeSize(indexMachineType);
	}

	/* Release the temporary variables */
	ILGenReleaseTempVar(info, tempObjectVar);
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		ILGenReleaseTempVar(info, tempIndexVars[argNum]);
	}
	ILFree(tempIndexVars);
	return node->machineType;
}
#line 3210 "cg_lvalue.c"

void ILNode_IndexerAccess_JavaStore__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1005 "jv_lvalue.tc"
{
	if(leave)
	{
		unsigned tempVar = ILGenTempTypedVar(info, node->elemType);
		int size = JavaGenTypeSize(node->machineType);
		JavaGenDup(info, node->machineType);
		JavaGenStoreLocal(info, tempVar, node->machineType);
		JavaGenAdjust(info, -size);
		JavaGenCallMethod(info, node->setMethod, node->saveStack);
		info->stackHeight = node->saveStack;
		JavaGenLoadLocal(info, tempVar, node->machineType);
		JavaGenAdjust(info, size);
		ILGenReleaseTempVar(info, tempVar);
	}
	else
	{
		JavaGenCallMethod(info, node->setMethod, node->saveStack);
		info->stackHeight = node->saveStack;
	}
}
#line 3234 "cg_lvalue.c"

struct ILNode_IndexerAccess_vtable__ const ILNode_IndexerAccess_vt__ = {
	&ILNode_LValueNoRef_vt__,
	ILNode_IndexerAccess_kind,
	"ILNode_IndexerAccess",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IndexerAccess_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_IndexerAccess_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IndexerAccess_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_IndexerAccess_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_IndexerAccess_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_IndexerAccess_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_IndexerAccess_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_IndexerAccess_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRef_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_IndexerAccess_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_IndexerAccess_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_IndexerAccess_JavaStore__,
};

ILMachineType ILNode_BaseAccess_ILNode_GetType__(ILNode_BaseAccess *node, ILGenInfo * info)
#line 77 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 3265 "cg_lvalue.c"

void ILNode_BaseAccess_ILNode_GenDiscard__(ILNode_BaseAccess *node, ILGenInfo * info)
#line 139 "cg_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 3272 "cg_lvalue.c"

ILMachineType ILNode_BaseAccess_ILNode_GenValue__(ILNode_BaseAccess *node, ILGenInfo * info)
#line 228 "cg_lvalue.tc"
{
 	ILClass *classInfo = ((ILNode_ClassDefn *)(info->currentClass))
 									->classInfo;
 	ILType *type =ILClassToType(ILClass_Parent(classInfo));
 	ILMachineType machineType;
 
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
	return node->machineType;
}
#line 3303 "cg_lvalue.c"

void ILNode_BaseAccess_JavaGenDiscard__(ILNode_BaseAccess *node, ILGenInfo * info)
#line 62 "jv_lvalue.tc"
{
	/* Nothing needs to be done here */
}
#line 3310 "cg_lvalue.c"

ILMachineType ILNode_BaseAccess_JavaGenValue__(ILNode_BaseAccess *node, ILGenInfo * info)
#line 146 "jv_lvalue.tc"
{
	JavaGenSimple(info, JAVA_OP_ALOAD_0);
	JavaGenAdjust(info, 1);
 	return ILMachineType_ObjectRef;
}
#line 3319 "cg_lvalue.c"

ILMachineType ILNode_BaseAccess_ILNode_Prepare__(ILNode_BaseAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 444 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
	return node->machineType;
}
#line 3327 "cg_lvalue.c"

ILMachineType ILNode_BaseAccess_ILNode_GetAndPrepare__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 623 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
	return node->machineType;
}
#line 3335 "cg_lvalue.c"

void ILNode_BaseAccess_ILNode_Store__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1197 "cg_lvalue.tc"
{
	/* Should be handled by IndexerAccess */
}
#line 3342 "cg_lvalue.c"

void ILNode_BaseAccess_ILNode_GenRef__(ILNode_BaseAccess *node, ILGenInfo * info)
#line 1491 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
}
#line 3349 "cg_lvalue.c"

ILMachineType ILNode_BaseAccess_JavaPrepare__(ILNode_BaseAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 349 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3357 "cg_lvalue.c"

ILMachineType ILNode_BaseAccess_JavaGetAndPrepare__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 506 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3365 "cg_lvalue.c"

void ILNode_BaseAccess_JavaStore__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 881 "jv_lvalue.tc"
{
	/* TODO */
}
#line 3372 "cg_lvalue.c"

struct ILNode_BaseAccess_vtable__ const ILNode_BaseAccess_vt__ = {
	&ILNode_LValueUnaryExpr_vt__,
	ILNode_BaseAccess_kind,
	"ILNode_BaseAccess",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseAccess_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseAccess_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseAccess_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseAccess_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseAccess_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_BaseAccess_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_BaseAccess_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_BaseAccess_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_BaseAccess_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_BaseAccess_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_BaseAccess_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_BaseAccess_JavaStore__,
};

ILMachineType ILNode_BaseElement_ILNode_GetType__(ILNode_BaseElement *node, ILGenInfo * info)
#line 77 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 3403 "cg_lvalue.c"

ILMachineType ILNode_BaseElement_ILNode_GenValue__(ILNode_BaseElement *node, ILGenInfo * info)
#line 260 "cg_lvalue.tc"
{
	/* Should be handled by IndexerAccess */
	return node->machineType;
}
#line 3411 "cg_lvalue.c"

ILMachineType ILNode_BaseElement_JavaGenValue__(ILNode_BaseElement *node, ILGenInfo * info)
#line 156 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3419 "cg_lvalue.c"

ILMachineType ILNode_BaseElement_ILNode_Prepare__(ILNode_BaseElement *node, ILGenInfo * info, void * * data1, void * * data2)
#line 453 "cg_lvalue.tc"
{
	/* Should be handled by IndexerAccess */
	return node->machineType;
}
#line 3427 "cg_lvalue.c"

ILMachineType ILNode_BaseElement_ILNode_GetAndPrepare__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 632 "cg_lvalue.tc"
{
	/* Should be handled by IndexerAccess */
	return node->machineType;
}
#line 3435 "cg_lvalue.c"

void ILNode_BaseElement_ILNode_Store__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1205 "cg_lvalue.tc"
{
	/* Should be handled by IndexerAccess */
}
#line 3442 "cg_lvalue.c"

void ILNode_BaseElement_ILNode_GenRef__(ILNode_BaseElement *node, ILGenInfo * info)
#line 1499 "cg_lvalue.tc"
{
	/* Should be handled by IndexerAccess */
}
#line 3449 "cg_lvalue.c"

ILMachineType ILNode_BaseElement_JavaPrepare__(ILNode_BaseElement *node, ILGenInfo * info, void * * data1, void * * data2)
#line 358 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3457 "cg_lvalue.c"

ILMachineType ILNode_BaseElement_JavaGetAndPrepare__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 515 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3465 "cg_lvalue.c"

void ILNode_BaseElement_JavaStore__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 889 "jv_lvalue.tc"
{
	/* TODO */
}
#line 3472 "cg_lvalue.c"

struct ILNode_BaseElement_vtable__ const ILNode_BaseElement_vt__ = {
	&ILNode_LValueUnaryExpr_vt__,
	ILNode_BaseElement_kind,
	"ILNode_BaseElement",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseElement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseElement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseElement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_BaseElement_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_BaseElement_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_BaseElement_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_BaseElement_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_BaseElement_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_BaseElement_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_BaseElement_JavaStore__,
};

ILMachineType ILNode_MemberAccess_ILNode_GetType__(ILNode_MemberAccess *node, ILGenInfo * info)
#line 77 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 3503 "cg_lvalue.c"

void ILNode_MemberAccess_ILNode_GenDiscard__(ILNode_MemberAccess *node, ILGenInfo * info)
#line 130 "cg_lvalue.tc"
{
	/* Evaluate the object expression for its side-effects */
	ILNode_GenDiscard(node->expr1, info);
}
#line 3511 "cg_lvalue.c"

ILMachineType ILNode_MemberAccess_ILNode_GenValue__(ILNode_MemberAccess *node, ILGenInfo * info)
#line 219 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
	return node->machineType;
}
#line 3519 "cg_lvalue.c"

void ILNode_MemberAccess_JavaGenDiscard__(ILNode_MemberAccess *node, ILGenInfo * info)
#line 53 "jv_lvalue.tc"
{
	/* Evaluate the object expression for its side-effects */
	JavaGenDiscard(node->expr1, info);
}
#line 3527 "cg_lvalue.c"

ILMachineType ILNode_MemberAccess_JavaGenValue__(ILNode_MemberAccess *node, ILGenInfo * info)
#line 137 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3535 "cg_lvalue.c"

ILMachineType ILNode_MemberAccess_ILNode_Prepare__(ILNode_MemberAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 435 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
	return node->machineType;
}
#line 3543 "cg_lvalue.c"

ILMachineType ILNode_MemberAccess_ILNode_GetAndPrepare__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 614 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
	return node->machineType;
}
#line 3551 "cg_lvalue.c"

void ILNode_MemberAccess_ILNode_Store__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1189 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
}
#line 3558 "cg_lvalue.c"

void ILNode_MemberAccess_ILNode_GenRef__(ILNode_MemberAccess *node, ILGenInfo * info)
#line 1483 "cg_lvalue.tc"
{
	/* Pseudo node - replaced during semantic analysis */
}
#line 3565 "cg_lvalue.c"

ILMachineType ILNode_MemberAccess_JavaPrepare__(ILNode_MemberAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 340 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3573 "cg_lvalue.c"

ILMachineType ILNode_MemberAccess_JavaGetAndPrepare__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 497 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3581 "cg_lvalue.c"

void ILNode_MemberAccess_JavaStore__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 873 "jv_lvalue.tc"
{
	/* TODO */
}
#line 3588 "cg_lvalue.c"

struct ILNode_MemberAccess_vtable__ const ILNode_MemberAccess_vt__ = {
	&ILNode_LValueBinaryExpr_vt__,
	ILNode_MemberAccess_kind,
	"ILNode_MemberAccess",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberAccess_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberAccess_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberAccess_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberAccess_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_MemberAccess_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_MemberAccess_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_MemberAccess_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_MemberAccess_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_MemberAccess_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_MemberAccess_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_MemberAccess_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_MemberAccess_JavaStore__,
};

ILMachineType ILNode_DerefField_ILNode_GetType__(ILNode_DerefField *node, ILGenInfo * info)
#line 77 "cg_lvalue.tc"
{
	return node->machineType;
}
#line 3619 "cg_lvalue.c"

void ILNode_DerefField_ILNode_GenDiscard__(ILNode_DerefField *node, ILGenInfo * info)
#line 147 "cg_lvalue.tc"
{
	/* Evaluate the object expression for its side-effects */
	ILNode_GenDiscard(node->expr1, info);
}
#line 3627 "cg_lvalue.c"

ILMachineType ILNode_DerefField_ILNode_GenValue__(ILNode_DerefField *node, ILGenInfo * info)
#line 269 "cg_lvalue.tc"
{
	ILNode_GenValue(node->expr1, info);
	ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	return node->machineType;
}
#line 3636 "cg_lvalue.c"

void ILNode_DerefField_JavaGenDiscard__(ILNode_DerefField *node, ILGenInfo * info)
#line 70 "jv_lvalue.tc"
{
	/* Evaluate the object expression for its side-effects */
	JavaGenDiscard(node->expr1, info);
}
#line 3644 "cg_lvalue.c"

ILMachineType ILNode_DerefField_JavaGenValue__(ILNode_DerefField *node, ILGenInfo * info)
#line 165 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3652 "cg_lvalue.c"

ILMachineType ILNode_DerefField_ILNode_Prepare__(ILNode_DerefField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 462 "cg_lvalue.tc"
{
	ILNode_GenValue(node->expr1, info);
	node->tempVar = IL_MAX_UINT32;
	return node->machineType;
}
#line 3661 "cg_lvalue.c"

ILMachineType ILNode_DerefField_ILNode_GetAndPrepare__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 641 "cg_lvalue.tc"
{
	ILNode_GenValue(node->expr1, info);
	if(leave)
	{
		/* Duplicate the pointer reference and get the current value */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);

		/* Store the current value into a temporary local */
		node->tempVar = ILGenTempTypedVar(info, ILField_Type(node->field));
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, node->tempVar);
		ILGenExtend(info, 1);
	}
	else
	{
		/* Duplicate the pointer reference for the later store */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);

		/* Load the current value from the field */
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);

		/* We don't need to reload a previous value in "Store" */
		node->tempVar = IL_MAX_UINT32;
	}
	return node->machineType;
}
#line 3694 "cg_lvalue.c"

void ILNode_DerefField_ILNode_Store__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1228 "cg_lvalue.tc"
{
	if(leave)
	{
		/* Copy the result into a temporary local */
		unsigned temp = ILGenTempTypedVar(info, ILField_Type(node->field));
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, temp);
		ILGenExtend(info, 1);

		/* Store the value into the field */
		ILGenFieldRef(info, IL_OP_STFLD, node->field);
		ILGenAdjust(info, -2);

		/* Do we need to restore a previous value to the stack top? */
		if(node->tempVar != IL_MAX_UINT32)
		{
			ILGenLoadLocal(info, node->tempVar);
			ILGenAdjust(info, 1);
			ILGenReleaseTempVar(info, node->tempVar);
		}

		/* Reload the contents of the temporary local */
		ILGenLoadLocal(info, temp);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, temp);
	}
	else
	{
		/* Store the value into the field */
		ILGenFieldRef(info, IL_OP_STFLD, node->field);
		ILGenAdjust(info, -2);

		/* Do we need to restore a previous value to the stack top? */
		if(node->tempVar != IL_MAX_UINT32)
		{
			ILGenLoadLocal(info, node->tempVar);
			ILGenAdjust(info, 1);
			ILGenReleaseTempVar(info, node->tempVar);
		}
	}
}
#line 3739 "cg_lvalue.c"

void ILNode_DerefField_ILNode_GenRef__(ILNode_DerefField *node, ILGenInfo * info)
#line 1507 "cg_lvalue.tc"
{
	ILNode_GenValue(node->expr1, info);
	ILGenFieldRef(info, IL_OP_LDFLDA, node->field);
}
#line 3747 "cg_lvalue.c"

ILMachineType ILNode_DerefField_JavaPrepare__(ILNode_DerefField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 367 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3755 "cg_lvalue.c"

ILMachineType ILNode_DerefField_JavaGetAndPrepare__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 524 "jv_lvalue.tc"
{
	/* TODO */
	return node->machineType;
}
#line 3763 "cg_lvalue.c"

void ILNode_DerefField_JavaStore__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 897 "jv_lvalue.tc"
{
	/* TODO */
}
#line 3770 "cg_lvalue.c"

struct ILNode_DerefField_vtable__ const ILNode_DerefField_vt__ = {
	&ILNode_LValueBinaryExpr_vt__,
	ILNode_DerefField_kind,
	"ILNode_DerefField",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DerefField_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DerefField_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DerefField_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DerefField_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DerefField_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_DerefField_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_DerefField_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_DerefField_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_DerefField_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_DerefField_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_DerefField_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_DerefField_JavaStore__,
};

ILNode *ILNode_Identifier_create(char * name)
{
	ILNode_Identifier *node__ = (ILNode_Identifier *)yynodealloc(sizeof(struct ILNode_Identifier__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Identifier_vt__;
	node__->kind__ = ILNode_Identifier_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	return (ILNode *)node__;
}

ILNode *ILNode_QualIdent_create(ILNode * left, ILNode * right)
{
	ILNode_QualIdent *node__ = (ILNode_QualIdent *)yynodealloc(sizeof(struct ILNode_QualIdent__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_QualIdent_vt__;
	node__->kind__ = ILNode_QualIdent_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->left = left;
	node__->right = right;
	return (ILNode *)node__;
}

ILNode *ILNode_LocalVar_create(unsigned long index, ILMachineType machineType)
{
	ILNode_LocalVar *node__ = (ILNode_LocalVar *)yynodealloc(sizeof(struct ILNode_LocalVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LocalVar_vt__;
	node__->kind__ = ILNode_LocalVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->index = index;
	node__->machineType = machineType;
	return (ILNode *)node__;
}

ILNode *ILNode_ArgumentVar_create(unsigned long index, ILMachineType machineType)
{
	ILNode_ArgumentVar *node__ = (ILNode_ArgumentVar *)yynodealloc(sizeof(struct ILNode_ArgumentVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ArgumentVar_vt__;
	node__->kind__ = ILNode_ArgumentVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->index = index;
	node__->machineType = machineType;
	return (ILNode *)node__;
}

ILNode *ILNode_RefArgumentVar_create(unsigned long index, ILMachineType machineType, ILType * type)
{
	ILNode_RefArgumentVar *node__ = (ILNode_RefArgumentVar *)yynodealloc(sizeof(struct ILNode_RefArgumentVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_RefArgumentVar_vt__;
	node__->kind__ = ILNode_RefArgumentVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->index = index;
	node__->machineType = machineType;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_StaticField_create(ILField * field)
{
	ILNode_StaticField *node__ = (ILNode_StaticField *)yynodealloc(sizeof(struct ILNode_StaticField__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_StaticField_vt__;
	node__->kind__ = ILNode_StaticField_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->field = field;
	return (ILNode *)node__;
}

ILNode *ILNode_MemberField_create(ILNode * expr, ILField * field)
{
	ILNode_MemberField *node__ = (ILNode_MemberField *)yynodealloc(sizeof(struct ILNode_MemberField__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_MemberField_vt__;
	node__->kind__ = ILNode_MemberField_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->field = field;
	node__->tempVar = 0;
	node__->baseCall = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ArrayAccess_create(ILNode * array, ILNode * indices)
{
	ILNode_ArrayAccess *node__ = (ILNode_ArrayAccess *)yynodealloc(sizeof(struct ILNode_ArrayAccess__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ArrayAccess_vt__;
	node__->kind__ = ILNode_ArrayAccess_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->array = array;
	node__->indices = indices;
	node__->arrayType = 0;
	node__->elemType = 0;
	node__->saveStack = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_StaticProperty_create(ILProperty * property)
{
	ILNode_StaticProperty *node__ = (ILNode_StaticProperty *)yynodealloc(sizeof(struct ILNode_StaticProperty__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_StaticProperty_vt__;
	node__->kind__ = ILNode_StaticProperty_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->property = property;
	node__->baseCall = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_MemberProperty_create(ILNode * expr, ILProperty * property)
{
	ILNode_MemberProperty *node__ = (ILNode_MemberProperty *)yynodealloc(sizeof(struct ILNode_MemberProperty__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_MemberProperty_vt__;
	node__->kind__ = ILNode_MemberProperty_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->property = property;
	node__->tempVar = 0;
	node__->baseCall = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_IndexerAccess_create(ILNode * object, ILNode * indices, ILMethod * getMethod, ILMethod * setMethod, ILType * objectType, ILType * elemType, ILMachineType machineType, int baseAccess)
{
	ILNode_IndexerAccess *node__ = (ILNode_IndexerAccess *)yynodealloc(sizeof(struct ILNode_IndexerAccess__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_IndexerAccess_vt__;
	node__->kind__ = ILNode_IndexerAccess_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->object = object;
	node__->indices = indices;
	node__->getMethod = getMethod;
	node__->setMethod = setMethod;
	node__->objectType = objectType;
	node__->elemType = elemType;
	node__->machineType = machineType;
	node__->baseAccess = baseAccess;
	node__->saveStack = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_BaseAccess_create(ILNode * expr)
{
	ILNode_BaseAccess *node__ = (ILNode_BaseAccess *)yynodealloc(sizeof(struct ILNode_BaseAccess__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BaseAccess_vt__;
	node__->kind__ = ILNode_BaseAccess_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->machineType = ILMachineType_Void;
	return (ILNode *)node__;
}

ILNode *ILNode_BaseElement_create(ILNode * expr)
{
	ILNode_BaseElement *node__ = (ILNode_BaseElement *)yynodealloc(sizeof(struct ILNode_BaseElement__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BaseElement_vt__;
	node__->kind__ = ILNode_BaseElement_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->machineType = ILMachineType_Void;
	return (ILNode *)node__;
}

ILNode *ILNode_MemberAccess_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_MemberAccess *node__ = (ILNode_MemberAccess *)yynodealloc(sizeof(struct ILNode_MemberAccess__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_MemberAccess_vt__;
	node__->kind__ = ILNode_MemberAccess_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->machineType = ILMachineType_Void;
	return (ILNode *)node__;
}

ILNode *ILNode_DerefField_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_DerefField *node__ = (ILNode_DerefField *)yynodealloc(sizeof(struct ILNode_DerefField__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DerefField_vt__;
	node__->kind__ = ILNode_DerefField_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->machineType = ILMachineType_Void;
	node__->field = 0;
	node__->tempVar = 0;
	return (ILNode *)node__;
}

#line 1585 "cg_lvalue.tc"


ILNode *ILQualIdentSimple(char *name)
{
	return ILNode_Identifier_create(name);
}

ILNode *ILQualIdentTwo(const char *name1, const char *name2)
{
	char *intern1 = ILInternString((char *)name1, -1).string;
	char *intern2 = ILInternString((char *)name2, -1).string;
	return ILNode_QualIdent_create(ILNode_Identifier_create(intern1),
								   ILNode_Identifier_create(intern2));
}

char *ILQualIdentName(ILNode *node, int asmForm)
{
	if(!node)
	{
		return 0;
	}
	else if(yykind(node) == yykindof(ILNode_Identifier))
	{
		/* Simple name */
		ILNode_Identifier *ident = (ILNode_Identifier *)node;
		if(asmForm && ident->name[0] >= 'a' && ident->name[0] <= 'z')
		{
			/* The name might clash with an assembler keyword
			   or instruction name, so we must quote it */
			ILIntString quote = ILInternString("'", 1);
			ILIntString name;
			name.string = ident->name;
			name.len = strlen(ident->name);
			return (ILInternAppendedString
						(quote, ILInternAppendedString(name, quote))).string;
		}
		return ident->name;
	}
	else if(yykind(node) == yykindof(ILNode_QualIdent))
	{
		/* Qualified name */
		ILNode_QualIdent *qident = (ILNode_QualIdent *)node;
		return ILQualIdentAppend(ILQualIdentName(qident->left, asmForm),
								 ILQualIdentName(qident->right, asmForm));
	}
	else
	{
		return 0;
	}
}

char *ILMemberAccessName(ILNode *node)
{
	if (!node) return 0;

	if(yykind(node) == yykindof(ILNode_Identifier))
	{
		return ((ILNode_Identifier *)node)->name;
	}
	else if(yykind(node) == yykindof(ILNode_MemberAccess))
	{
		/*  Member Access  */
		ILNode_MemberAccess *ma = (ILNode_MemberAccess *)node;
		return ILQualIdentAppend(ILMemberAccessName(ma->expr1),
								 ILMemberAccessName(ma->expr2));
	}
	else
	{
		return 0;
	}
}

char *ILQualIdentAppend(char *name1, char *name2)
{
	ILIntString str1;
	ILIntString str2;
	ILIntString str3;
	if(!name1 || *name1 == '\0' || !name2 || *name2 == '\0')
	{
		return 0;
	}
	str1.string = name1;
	str1.len = strlen(name1);
	str2.string = ".";
	str2.len = 1;
	str3.string = name2;
	str3.len = strlen(name2);
	return (ILInternAppendedString
				(str1, ILInternAppendedString(str2, str3))).string;
}

int ILIsQualIdent(ILNode *node)
{
	if(!node)
	{
		return 0;
	}
	if(yykind(node) == yykindof(ILNode_Identifier))
	{
		return 1;
	}
	else if(yykind(node) == yykindof(ILNode_QualIdent))
	{
		return ILIsQualIdent(((ILNode_QualIdent *)node)->left) &&
		       ILIsQualIdent(((ILNode_QualIdent *)node)->right);
	}
	else
	{
		return 0;
	}
}

#line 4121 "cg_lvalue.c"
