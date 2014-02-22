/* cs_semantics.c.  Generated automatically by treecc */
#line 3 "cs_semantics.tc"

/*
 * cs_semantics.tc - Semantic analysis routines for C#.
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

#include <cscc/csharp/cs_internal.h>
#line 116 "cs_semantics.tc"


#include <codegen/cg_nodemap.h>

#line 21 "cs_decls.tc"


/*
 * Error reporting function for "ILGenImplementsAllInterfaces".
 */
static void InterfaceErrorFunc(ILNode *node, ILClass *classInfo,
							   ILMember *missingMember)
{
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("`%s' does not implement `%s'"),
				  CSTypeToName(ILClassToType(classInfo)),
				  CSItemToName((ILProgramItem *)missingMember));
}

/*
 * Proxy reporting function for "ILGenImplementsAllInterfaces".
 */
static void InterfaceProxyFunc(ILNode *node, ILClass *classInfo,
							   ILMethod *missingMember,
							   ILMethod *proxyReplacement)
{
	ILNode_ClassDefn *defn = (ILNode_ClassDefn *)node;
	ILNode *proxy = ILNode_ProxyDeclaration_create
		(missingMember, proxyReplacement);
	ILNode *body;
	if(!(defn->body))
	{
		body = defn->body = ILNode_List_create();
	}
	else
	{
		body = defn->body;
		if(yyisa(body, ILNode_ScopeChange))
		{
			body = ((ILNode_ScopeChange *)body)->body;
		}
	}
	ILNode_List_Add(body, proxy);
}

/*  Since we can't (shouldn't?) inherit list from multiple types, this
 *  operation will iterate over a list of declarations adding to the 
 *  compound constructor */
static void CSListGatherStaticCtor(ILNode_List *node, ILNode_List *ctor)
{
	ILNode_ListIter iter;
	ILNode_Declaration *curr;

	if (yyisa(node, ILNode_List) || node == 0)
	{
		/* Iterate through the body gathering up the necessary constructors */
		ILNode_ListIter_Init(&iter, node);
		while ((curr = (ILNode_Declaration *)ILNode_ListIter_Next(&iter)))
		{
			ILNode_Declaration_GatherStaticCtor(curr, ctor);
		}
	}
}

/* 
 * append entries in the oldList to the collectedList to order
 * the user specified static ctors after the ones from field decl
 */
static void AppendStaticCtor(ILNode_List *collectedList, 
							 ILNode_List *oldList)
{
	ILNode_ListIter iter;
	ILNode *curr;

	if(!oldList)return;

	if (yyisa(oldList, ILNode_List))
	{
		ILNode_ListIter_Init(&iter,oldList);
		while((curr = ILNode_ListIter_Next(&iter)))
		{
			ILNode_List_Add(collectedList,curr);
		}
	}
}

#line 354 "cs_decls.tc"


/*
 * Attach a constant value to a field.
 */
static void AddConstantValue(ILGenInfo *info, ILField *field,
							 ILEvalValue *evalValue)
{
	unsigned char constBuf[18];
	int constBufLen;
	int constElemType;
	ILConstant *constant;
	ILType *type;
	ILMethod *ctor;
	ILAttribute *attr;
	int posn, wlen;
	unsigned char *newStr;
	unsigned char *tempStr;

	/* Bail out if the field wasn't created properly */
	if(!field)
	{
		return;
	}

	switch(evalValue->valueType)
	{
		case ILMachineType_Boolean:
		{
			constBuf[0] = (unsigned char)(evalValue->un.i4Value);
			constBufLen = 1;
			constElemType = IL_META_ELEMTYPE_BOOLEAN;
		}
		break;

		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		{
			constBuf[0] = (unsigned char)(evalValue->un.i4Value);
			constBufLen = 1;
			constElemType = IL_META_ELEMTYPE_I1;
		}
		break;

		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		{
			constBuf[0] = (unsigned char)(evalValue->un.i4Value);
			constBuf[1] =
				(unsigned char)(evalValue->un.i4Value >> 8);
			constBufLen = 2;
			constElemType = IL_META_ELEMTYPE_I2;
		}
		break;

		case ILMachineType_Char:
		{
			constBuf[0] = (unsigned char)(evalValue->un.i4Value);
			constBuf[1] =
				(unsigned char)(evalValue->un.i4Value >> 8);
			constBufLen = 2;
			constElemType = IL_META_ELEMTYPE_CHAR;
		}
		break;

		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		{
			constBuf[0] = (unsigned char)(evalValue->un.i4Value);
			constBuf[1] =
				(unsigned char)(evalValue->un.i4Value >> 8);
			constBuf[2] =
				(unsigned char)(evalValue->un.i4Value >> 16);
			constBuf[3] =
				(unsigned char)(evalValue->un.i4Value >> 24);
			constBufLen = 4;
			constElemType = IL_META_ELEMTYPE_I4;
		}
		break;

		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			constBuf[0] = (unsigned char)(evalValue->un.i8Value);
			constBuf[1] =
				(unsigned char)(evalValue->un.i8Value >> 8);
			constBuf[2] =
				(unsigned char)(evalValue->un.i8Value >> 16);
			constBuf[3] =
				(unsigned char)(evalValue->un.i8Value >> 24);
			constBuf[4] =
				(unsigned char)(evalValue->un.i8Value >> 32);
			constBuf[5] =
				(unsigned char)(evalValue->un.i8Value >> 40);
			constBuf[6] =
				(unsigned char)(evalValue->un.i8Value >> 48);
			constBuf[7] =
				(unsigned char)(evalValue->un.i8Value >> 56);
			constBufLen = 8;
			constElemType = IL_META_ELEMTYPE_I8;
		}
		break;

		case ILMachineType_Float32:
		{
			IL_WRITE_FLOAT(constBuf, evalValue->un.r4Value);
			constBufLen = 4;
			constElemType = IL_META_ELEMTYPE_R4;
		}
		break;

		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:
		{
			IL_WRITE_DOUBLE(constBuf, evalValue->un.r8Value);
			constBufLen = 8;
			constElemType = IL_META_ELEMTYPE_R8;
		}
		break;

		case ILMachineType_Decimal:
		{
			/* Attach "DecimalConstantAttribute" to the field */
			static ILType * const decConstArgs[5] =
				{ILType_UInt8, ILType_UInt8, ILType_UInt32,
				 ILType_UInt32, ILType_UInt32};
			type = ILFindNonSystemType(info, "DecimalConstantAttribute",
									   "System.Runtime.CompilerServices");
			if(type && ILType_IsClass(type))
			{
				ctor = ILResolveConstructor(info, ILType_ToClass(type),
											ILField_Owner(field),
											(ILType **)decConstArgs, 5);
				if(ctor)
				{
					/* Build the attribute value for the constant */
					constBuf[0] = 0x01;
					constBuf[1] = 0x00;
					constBuf[2] = (unsigned char)
						(evalValue->un.decValue.flags >> 16);
					constBuf[3] = (unsigned char)
						(evalValue->un.decValue.flags >> 24);
					IL_WRITE_UINT32(constBuf + 4, evalValue->un.decValue.high);
					IL_WRITE_UINT32(constBuf + 8,
								    evalValue->un.decValue.middle);
					IL_WRITE_UINT32(constBuf + 12, evalValue->un.decValue.low);
					constBuf[16] = 0x00;
					constBuf[17] = 0x00;

					/* Create and attach the attribute */
					if((attr = ILAttributeCreate
							(ILProgramItem_Image(field), 0)) == 0)
					{
						CCOutOfMemory();
					}
					ILAttributeSetType(attr, ILToProgramItem(ctor));
					if(!ILAttributeSetValue(attr, constBuf, 18))
					{
						CCOutOfMemory();
					}
					ILProgramItemAddAttribute(ILToProgramItem(field), attr);
				}
			}
			return;
		}
		break;

		case ILMachineType_String:
		{
			/* Detect "null" string constants specially */
			if(!(evalValue->un.strValue.str))
			{
				constBuf[0] = 0;
				constBuf[1] = 0;
				constBuf[2] = 0;
				constBuf[3] = 0;
				constBufLen = 4;
				constElemType = IL_META_ELEMTYPE_CLASS;
				break;
			}

			/* Determine the length of string in UTF-16 characters */
			posn = 0;
			wlen = 0;
			while(posn < evalValue->un.strValue.len)
			{
				wlen += ILUTF16WriteChar
					(0, ILUTF8ReadChar(evalValue->un.strValue.str,
									   evalValue->un.strValue.len, &posn));
			}

			/* Allocate temporary storage for the UTF-16 version */
			newStr = (unsigned char *)ILMalloc(wlen * 2 + 1);
			if(!newStr)
			{
				CCOutOfMemory();
			}

			/* Convert the string from UTF-8 into UTF-16 */
			posn = 0;
			tempStr = newStr;
			while(posn < evalValue->un.strValue.len)
			{
				tempStr += ILUTF16WriteCharAsBytes
					(tempStr, ILUTF8ReadChar
						(evalValue->un.strValue.str,
					     evalValue->un.strValue.len, &posn));
			}

			/* Attach the constant to the field */
			constant = ILConstantCreate(info->image, 0, (ILProgramItem *)field,
										IL_META_ELEMTYPE_STRING);
			if(!constant)
			{
				CCOutOfMemory();
			}
			if(!ILConstantSetValue(constant, newStr, wlen * 2))
			{
				CCOutOfMemory();
			}
			ILFree(newStr);
			return;
		}
		break;

		case ILMachineType_ObjectRef:
		{
			/* This is the "null" constant */
			constBuf[0] = 0;
			constBuf[1] = 0;
			constBuf[2] = 0;
			constBuf[3] = 0;
			constBufLen = 4;
			constElemType = IL_META_ELEMTYPE_CLASS;
		}
		break;

		default:
		{
			constBuf[0] = 0;
			constBufLen = 1;
			constElemType = IL_META_ELEMTYPE_I1;
		}
		break;
	}
	constant = ILConstantCreate(info->image, 0, (ILProgramItem *)field,
								constElemType);
	if(!constant)
	{
		CCOutOfMemory();
	}
	if(!ILConstantSetValue(constant, constBuf, constBufLen))
	{
		CCOutOfMemory();
	}
}

void CSAddInitCtor(ILGenInfo *info, ILNode *stmt)
{
	ILNode_ClassDefn *defn = (ILNode_ClassDefn *)(info->currentClass);
	ILNode *bodyList;
	if(defn && stmt)
	{
		/* Construct the method declaration for ".init" if necessary.
		   Note: the ".init" method is a pseudo method to collect up
		   all non-static field initializers.  It isn't output into
		   the final program.  Instead, its body is expanded inline
		   into each constructor that requires field initialization */
		if(!(defn->initCtorsMethod))
		{
			ILMethod *methodInfo;
			ILType *signature;
			bodyList = ILNode_Compound_create();
			defn->initCtorsMethod =
				ILNode_MethodDeclaration_create
					(0, IL_META_METHODDEF_PRIVATE |
						IL_META_METHODDEF_HIDE_BY_SIG,
					 0 /* void */,
					 ILQualIdentSimple(ILInternString(".init", 5).string),
					 0 /* no parameters */,
					 ILNode_NewScope_create(bodyList));
			methodInfo = ILMethodCreate(defn->classInfo, 0, ".init",
										IL_META_METHODDEF_PRIVATE |
										IL_META_METHODDEF_HIDE_BY_SIG);
			if(!methodInfo)
			{
				CCOutOfMemory();
			}
			ILMethodSetCallConv(methodInfo, IL_META_CALLCONV_HASTHIS);
			signature = ILTypeCreateMethod(info->context, ILType_Void);
			if(!signature)
			{
				CCOutOfMemory();
			}
			ILTypeSetCallConv(signature, IL_META_CALLCONV_HASTHIS);
			ILMemberSetSignature((ILMember *)methodInfo, signature);
			((ILNode_MethodDeclaration *)(defn->initCtorsMethod))
					->methodInfo = methodInfo;
		}
		else
		{
			bodyList = ((ILNode_MethodDeclaration *)(defn->initCtorsMethod))
							->body;
			bodyList = ((ILNode_NewScope *)bodyList)->stmt;
		}

		/* Wrap the statement in a scope and add it to the body */
		ILNode_List_Add(bodyList, ILNode_NewScope_create(stmt));
	}
}

#line 21 "cs_lvalue.tc"


/*
 * Check to see if we are permitted to use the "this" expression
 * to access an instance member.
 */
static void CheckForInstanceAccess(ILGenInfo *info, ILNode *node)
{
	ILNode_MethodDeclaration *caller;
	caller = (ILNode_MethodDeclaration *)(info->currentMethod);
	if(!caller || (caller->modifiers & IL_META_METHODDEF_STATIC) != 0)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "cannot access instance members in static methods");
	}
}

#line 88 "cs_lvalue.tc"


/*
 * Convert a field into a literal constant node if possible.
 * Returns NULL if not possible.
 */
static ILNode *FieldToConstant(ILGenInfo *info, ILNode *node, ILField *field)
{
	ILConstant *constValue;
	ILNode_ClassDefn *defn;

	/* Make sure that semantic analysis has been performed on the item */
	if(ILTypeIsEnum(ILClassToType(ILField_Owner(field))))
	{
		/* This is an enumerated type, so perform semantic analysis
		   on the type instead of the field, so that we create the
		   members with default values in the correct order */
		defn = (ILNode_ClassDefn *)ILProgramItemToNode
			(info, ILToProgramItem(ILField_Owner(field)));
		if(defn != 0 && defn->visited == ILVisitMode_NotVisited)
		{
			CSSemProgramItem(info, ILToProgramItem(ILField_Owner(field)));
		}
		else
		{
			/* We may already be inside the enumerated type, so go
			   directly to the field to avoid circularity problems */
			CSSemProgramItem(info, ILToProgramItem(field));
		}
	}
	else
	{
		/* Perform semantic analysis on the value directly */
		CSSemProgramItem(info, ILToProgramItem(field));
	}

	/* Get the constant value, if present */
	if(ILField_IsLiteral(field))
	{
		if((constValue = ILConstantGetFromOwner(ILToProgramItem(field))) != 0)
		{
			/* Convert the constant into an appropriate node */
			ILType *baseType = ILTypeGetEnumType(ILField_Type(field));
			const unsigned char *value;
			unsigned long valueLen;
			value = ILConstantGetValue(constValue, &valueLen);
			switch(ILConstantGetElemType(constValue))
			{
				case IL_META_ELEMTYPE_BOOLEAN:
				{
					/* Create a boolean constant */
					if(value && valueLen > 0 && baseType == ILType_Boolean)
					{
						if(value[0])
						{
							return ILNode_True_create();
						}
						else
						{
							return ILNode_False_create();
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_I1:
				case IL_META_ELEMTYPE_U1:
				{
					/* Create an 8-bit constant */
					if(value && valueLen > 0)
					{
						if(baseType == ILType_Int8)
						{
							ILInt8 val = (ILInt8)(value[0]);
							if(val >= 0)
							{
								return ILNode_Int8_create
									((ILUInt64)(-((ILInt32)val)), 1, 0);
							}
							else
							{
								return ILNode_Int8_create
									((ILUInt64)val, 0, 0);
							}
						}
						else if(baseType == ILType_UInt8)
						{
							return ILNode_UInt8_create
								((ILUInt64)(value[0]), 0, 0);
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_I2:
				case IL_META_ELEMTYPE_U2:
				{
					/* Create a 16-bit constant */
					if(value && valueLen > 1)
					{
						if(baseType == ILType_Int16)
						{
							ILInt16 val = (ILInt16)(IL_READ_INT16(value));
							if(val >= 0)
							{
								return ILNode_Int16_create
									((ILUInt64)(-((ILInt32)val)), 1, 0);
							}
							else
							{
								return ILNode_Int16_create
									((ILUInt64)val, 0, 0);
							}
						}
						else if(baseType == ILType_UInt16)
						{
							return ILNode_UInt16_create
								((ILUInt64)(IL_READ_UINT16(value)), 0, 0);
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_CHAR:
				{
					/* Create a character constant */
					if(value && valueLen > 1)
					{
						if(baseType == ILType_Char)
						{
							return ILNode_Char_create
								((ILUInt64)(IL_READ_UINT16(value)), 0, 0);
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_I4:
				case IL_META_ELEMTYPE_U4:
				{
					/* Create a 32-bit constant */
					if(value && valueLen > 3)
					{
						if(baseType == ILType_Int32)
						{
							ILInt32 val = IL_READ_INT32(value);
							if(val >= 0)
							{
								return ILNode_Int32_create
									((ILUInt64)(ILUInt32)(-val), 1, 0);
							}
							else
							{
								return ILNode_Int32_create
									((ILUInt64)val, 0, 0);
							}
						}
						else if(baseType == ILType_UInt32)
						{
							return ILNode_UInt32_create
								((ILUInt64)(IL_READ_UINT32(value)), 0, 0);
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_I8:
				case IL_META_ELEMTYPE_U8:
				{
					/* Create a 64-bit constant */
					if(value && valueLen > 7)
					{
						if(baseType == ILType_Int64)
						{
							ILInt64 val = IL_READ_INT64(value);
							if(val < 0)
							{
								return ILNode_Int64_create
									((ILUInt64)(-val), 1, 0);
							}
							else
							{
								return ILNode_Int64_create
									((ILUInt64)val, 0, 0);
							}
						}
						else if(baseType == ILType_UInt64)
						{
							return ILNode_UInt64_create
								(IL_READ_UINT64(value), 0, 0);
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_R4:
				{
					/* Create a 32-bit floating-point constant */
					if(value && valueLen > 3)
					{
						if(baseType == ILType_Float32)
						{
							return ILNode_Float32_create
								(IL_READ_FLOAT(value));
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_R8:
				{
					/* Create a 64-bit floating-point constant */
					if(value && valueLen > 7)
					{
						if(baseType == ILType_Float64)
						{
							return ILNode_Float64_create
								(IL_READ_DOUBLE(value));
						}
					}
				}
				break;

				case IL_META_ELEMTYPE_STRING:
				{
					/* Create a string constant */
					if(value && ILTypeIsStringClass(baseType))
					{
						int posn = 0;
						int len = 0;
						char *newStr;
						ILIntString interned;
						while(posn < (int)valueLen)
						{
							len += ILUTF8WriteChar
							  (0, ILUTF16ReadCharAsBytes
								((const char *)value, (int)valueLen, &posn));
						}
						newStr = (char *)ILMalloc(len + 1);
						if(!newStr)
						{
							CCOutOfMemory();
						}
						posn = 0;
						len = 0;
						while(posn < (int)valueLen)
						{
							len += ILUTF8WriteChar
							  (newStr + len, ILUTF16ReadCharAsBytes
								((const char *)value, (int)valueLen, &posn));
						}
						interned = ILInternString(newStr, len);
						ILFree(newStr);
						return ILNode_String_create(interned.string,
													interned.len);
					}
				}
				break;

				case IL_META_ELEMTYPE_CLASS:
				{
					/* Create a "null" constant */
					if(value &&
					   ((valueLen == 4 && IL_READ_UINT32(value) == 0) ||
					    (valueLen == 8 && IL_READ_UINT64(value) == 0)))
					{
						if(ILTypeAssignCompatible(info->image, 0, baseType))
						{
							return ILNode_Null_create();
						}
					}
				}
				break;
			}

			/* If we get here, then the constant is not compatible
			   with the type of the field */
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "literal field has an incorrect constant value");
			return 0;
		}
		else if(ILField_IsLiteral(field) &&
		        ILTypeIsStringClass(ILField_Type(field)))
		{
			/* Sometimes the empty string constant is stored as a literal
			   field with no value associated with it */
			return ILNode_String_create(ILInternString("", 0).string, 0);
		}
		else
		{
			/* This is a literal without an actual constant value */
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "literal field does not have a constant value");
			return 0;
		}
	}
	else if(ILField_IsInitOnly(field))
	{
		/* Check for "DecimalConstantAttribute" values, which are
		   attached to "readonly" fields of type "System.Decimal" */
		ILType *decimalType = ILFindSystemType(info, "Decimal");
		if(ILTypeIdentical(decimalType, ILField_Type(field)))
		{
			ILAttribute *attr = 0;
			ILMethod *ctor;
			const char *namespace;
			const unsigned char *value;
			unsigned long valueLen;
			ILDecimal decValue;

			while((attr = ILProgramItemNextAttribute(ILToProgramItem(field),
													 attr)) != 0)
			{
				ctor = ILProgramItemToMethod(ILAttributeTypeAsItem(attr));
				if(ctor && !strcmp(ILMethod_Name(ctor), ".ctor") &&
				   !strcmp(ILClass_Name(ILMethod_Owner(ctor)),
				   		   "DecimalConstantAttribute"))
				{
					namespace = ILClass_Namespace(ILMethod_Owner(ctor));
					if(namespace &&
					   !strcmp(namespace, "System.Runtime.CompilerServices"))
					{
						value = (const unsigned char *)
							ILAttributeGetValue(attr, &valueLen);
						if(value && valueLen == 18 &&
						   value[0] == 0x01 && value[1] == 0x00 &&
						   value[2] < 29 && (value[3] == 0x00 ||
						   					 value[3] == 0x80))
						{
							decValue.flags =
								(((ILUInt32)(value[2])) << 16) |
								(((ILUInt32)(value[3])) << 24);
							decValue.high = IL_READ_UINT32(value + 4);
							decValue.middle = IL_READ_UINT32(value + 8);
							decValue.low = IL_READ_UINT32(value + 12);
							return ILNode_Decimal_create(decValue);
						}
					}
				}
			}
		}

		/* Check for "IntPtr.Zero", which is very common in unmanaged code */
		if(!strcmp(ILField_Name(field), "Zero") &&
		   ILClassToType(ILField_Owner(field)) == ILType_Int)
		{
			return ILNode_Int_create(0, 0, 0);
		}

		/* Load the contents of the read-only field using regular techniques */
		return 0;
	}
	else
	{
		/* Regular static field */
		return 0;
	}
}

/*
 * Get the type of the current class.  NULL if not possible.
 */
static ILType *CurrentClassType(ILGenInfo *info)
{
	if(info->currentClass)
	{
		ILClass *classInfo = ((ILNode_ClassDefn *)(info->currentClass))
									->classInfo;
		if(classInfo)
		{
			return ILClassToType(classInfo);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

/*
 * Check if the method is the psuedo method ".init" which is expanded
 * into the constructor body inline.
 */
static int ILMethodIsPsuedoConstructor(ILMethod *method)
{
	ILType *signature=ILMethod_Signature(method);
	ILUInt32 attrs=	(IL_META_METHODDEF_PRIVATE| IL_META_METHODDEF_HIDE_BY_SIG);

	return (!strcmp(ILMethod_Name(method),".init") && 
			((ILMethod_Attrs(method) & attrs) !=0) &&
			(ILTypeNumParams(signature)==0) &&
			ILTypeIdentical(ILTypeGetReturn(signature),ILType_Void));
}

/*
 * Convert a semantic value into an l-value or r-value if necessary.
 */
static CSSemValue SemToLRValue(ILNode *node, ILGenInfo *info, ILNode **parent,
							   CSSemValue value, char *name, ILNode *expr,
							   CSSemValue *exprSem)
{
	ILField *field;
	ILProperty *property;
	ILType *signature;
	ILMethod *getter;
	ILMethod *setter;
	ILNode *constNode;
	ILMethod *method;
	ILEvent *event;
	int allowConst;
	ILType *thisType;
	ILType *type;

	switch(CSSemGetKind(value))
	{
		case CS_SEMKIND_FIELD:
		{
			/* Reference to a class field */
			field = CSSemGetField(value);
			if(!(info->currentMethod))
			{
				/* We are performing semantic analysis of declarations,
				   where only literals and types are allowed */
				if(!ILField_IsStatic(field) || !ILField_IsLiteral(field))
				{
					CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`%s' is not declared as a type in the current scope",
					  name);
					CSSemSetType(value, ILType_Int32);
					return value;
				}
			}

			/* Create the final semantic type */
			CSSemSetLValue(value, ILField_Type(field));

			/* Check the usage of "readonly" fields */
			allowConst = 1;
			if(ILField_IsInitOnly(field))
			{
				method = ((ILNode_MethodDeclaration *)(info->currentMethod))
							->methodInfo;
				if(method && CSGetAccessScope(info, 1) == ILField_Owner(field))
				{
					/* The field is being used inside the class */
					if(ILField_IsStatic(field) &&
					   ILMethodIsStaticConstructor(method))
					{
						/* Static readonly used within static constructor */
						allowConst = 0;
					}
					else if(!ILField_IsStatic(field) &&
					        (ILMethodIsConstructor(method)||
							ILMethodIsPsuedoConstructor(method)))
					{
						/* Instance readonly used within instance constructor
						   or the ".init" psuedo constructor
						   Nothing needs to be done here */
					}
					else
					{
						/* The field is used elsewhere, so make it an 
						r-value */
						CSSemSetRValue(value, ILField_Type(field));
					}
				}
				else
				{
					/* The field is used elsewhere, so make it an r-value */
					CSSemSetRValue(value, ILField_Type(field));
				}
			}

			/* Replace this identifier with a field access node */
			if(ILField_IsStatic(field))
			{
				/* Convert the field into a constant node if possible */
				if(allowConst &&
				   (constNode = FieldToConstant(info, node, field)) != 0)
				{
					ILEvalValue evalValue;
					*parent = constNode;
					ILNode_EvalConst(constNode, info, &evalValue);
					thisType = ILClassToType(ILField_Owner(field));
					type = ILField_Type(field);
					if(ILTypeIsEnum(thisType) &&
					   ILTypeIdentical(type, ILTypeGetEnumType(thisType)))
					{
						/* The enum definition erroneously used the
						   underlying type for the constant, instead
						   of using the enum type.  Work around it */
						type = thisType;
					}
					if(ILTypeIsEnum(thisType) && 
					   ILProgramItemToNode(info, 
						   ILToProgramItem(ILField_Owner(field))) 
						   == info->currentClass)
					{
						/* inside an enum declaration the enum fields
						   are treated as values of the underlying 
						   type - this is behavior observed in CSC and
						   NOT according to spec */
						   type = ILTypeGetEnumType(type);
					}
					CSSemSetConstant(value, type, evalValue);
				}
				else
				{
					*parent = ILNode_StaticField_create(field);
				}
			}
			else if(expr)
			{
				*parent = ILNode_MemberField_create
						(ILNode_MarkType_create
							(expr, CSSemGetType(*exprSem)), field);
			}
			else
			{
				CheckForInstanceAccess(info, node);
				thisType = CurrentClassType(info);
				if(thisType)
				{
					*parent = ILNode_MemberField_create
							(ILNode_MarkType_create
								(ILNode_This_create(), thisType), field);
				}
				else
				{
					*parent = ILNode_MemberField_create
							(ILNode_This_create(), field);
				}
			}
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
		}
		break;

		case CS_SEMKIND_METHOD_GROUP:
		{
			/* Reference to a method group */
			if(!(info->currentMethod))
			{
				/* We are performing semantic analysis of declarations,
				   which does not permit methods to be used as types */
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`%s' is not declared as a type in the current scope",
					  name);
				CSSemSetType(value, ILType_Int32);
				return value;
			}

			/* Replace the node with either the object expression or "this" */
			if(expr)
			{
				*parent = ILNode_MarkType_create(expr, CSSemGetType(*exprSem));
			}
			else
			{
				thisType = CurrentClassType(info);
				if(thisType)
				{
					*parent = ILNode_MarkType_create
						(ILNode_This_create(), thisType);
				}
				else
				{
					*parent = ILNode_This_create();
				}
			}
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));

			/* Copy the "base" indication to the method group */
			if(exprSem && CSSemIsBase(*exprSem))
			{
				CSSemSetBase(value);
			}
		}
		break;

		case CS_SEMKIND_PROPERTY:
		{
			/* Reference to a class field */
			if(!(info->currentMethod))
			{
				/* We are performing semantic analysis of declarations,
				   which does not permit properties to be used as types */
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`%s' is not declared as a type in the current scope",
					  name);
				CSSemSetType(value, ILType_Int32);
				return value;
			}

			/* Find the property descriptor */
			property = CSSemGetProperty(value);
			signature = ILProperty_Signature(property);
			type = ILTypeGetReturn(signature);

			/* Create the final semantic type */
			getter = ILProperty_Getter(property);
			setter = ILProperty_Setter(property);
			if(getter != 0)
			{
				if(setter != 0)
				{
					/* Both "get" and "set" are supported */
					CSSemSetLValue(value, type);
				}
				else
				{
					/* Only "get" is supported */
					CSSemSetRValue(value, type);
				}
			}
			else if(setter != 0)
			{
				/* Only "set" is supported */
				CSSemSetSValue(value, type);
			}
			else
			{
				/* Neither "get" nor "set" is supported */
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  "property has neither `get' nor `set' methods");
				CSSemSetLValue(value, type);
			}

			/* Replace this identifier with a property access node */
			if((getter != 0 && ILMethod_IsStatic(getter)) ||
			   (setter != 0 && ILMethod_IsStatic(setter)))
			{
				*parent = ILNode_StaticProperty_create(property);
			}
			else if(expr)
			{
				*parent = ILNode_MemberProperty_create
					(ILNode_MarkType_create
						(expr, CSSemGetType(*exprSem)), property);
				/* Copy the "base" indication to the method group */
				if(exprSem && CSSemIsBase(*exprSem))
				{
					CSSemSetBase(value);
					((ILNode_MemberProperty*)(*parent))->baseCall=1;
				}
			}
			else
			{
				CheckForInstanceAccess(info, node);
				thisType = CurrentClassType(info);
				if(thisType)
				{
					*parent = ILNode_MemberProperty_create
						(ILNode_MarkType_create
							(ILNode_This_create(), thisType), property);
				}
				else
				{
					*parent = ILNode_MemberProperty_create
						(ILNode_This_create(), property);
				}
				/* Copy the "base" indication to the method group */
				if(exprSem && CSSemIsBase(*exprSem))
				{
					CSSemSetBase(value);
					((ILNode_MemberProperty*)(*parent))->baseCall=1;
				}
			}
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
	
		}
		break;

		case CS_SEMKIND_EVENT:
		{
			/* Reference to a class event */
			event = CSSemGetEvent(value);
			if(!(info->currentMethod))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "`%s' is not declared as a type in the current scope",
				  name);
				CSSemSetType(value, ILType_Int32);
				return value;
			}

			/* Replace this identifier node with the "this"
			   expression for the event access */
			method = ILEvent_AddOn(event);
			if(!method)
			{
				method = ILEvent_RemoveOn(event);
			}
			if(method && ILMethod_IsStatic(method))
			{
				*parent = 0;
			}
			else if(expr)
			{
				*parent = expr;
			}
			else
			{
				CheckForInstanceAccess(info, node);
				thisType = CurrentClassType(info);
				if(thisType)
				{
					*parent = ILNode_MarkType_create
								(ILNode_This_create(), thisType);
				}
				else
				{
					*parent = ILNode_This_create();
				}
			}
			if(*parent)
			{
				yysetfilename(*parent, yygetfilename(node));
				yysetlinenum(*parent, yygetlinenum(node));
			}
		}
		break;
	}
	return value;
}

static CSSemValue GetFullyQualifiedType(ILGenInfo *info, char * ns, char * name)
{
	CSSemValue value;
	ILScopeData * data = NULL;
	ILNode *usingNode;

	if(name && ns)
	{
		ILType * type = ILFindNonSystemType(info, name, ns);
		if(type != NULL)
		{
			// Note: had to do this to match the 'System.Intptr' type properly
			type = ILClassToType(ILClassResolve(ILType_ToClass(type)));
			CSSemSetType(value, type);
			return value;
		}
		
		// check if "ns" is really an alias for something
		if(info->currentNamespace && ((ILNode_Namespace*)info->currentNamespace)->localScope)
		{
			data = ILScopeLookup(((ILNode_Namespace*)info->currentNamespace)->localScope, ns, 1);
		}

		if(data && ILScopeDataGetKind(data) == IL_SCOPE_ALIAS)
		{
			usingNode = ILScopeDataGetData1(data);
			ns = ILQualIdentName(usingNode, 0);
		}
		
		if(ns)
		{
			ILType * type = ILFindNonSystemType(info, name, ns);
			if(type != NULL)
			{
				// Note: had to do this to match the 'System.Intptr' type properly
				type = ILClassToType(ILClassResolve(ILType_ToClass(type)));
				CSSemSetType(value, type);
				return value;
			}
		}
	}

	
	return CSSemValueDefault;
}

#line 1694 "cs_lvalue.tc"


/*
 * Wrap an array index expression in an overflow conversion to "int".
 */
static ILNode *ArrayIndexToInt(ILGenInfo *info, ILNode *node,
							   ILNode **parent, ILType *currentType,
							   int pointerAccess)
{
	ILNode *result;
	if(pointerAccess)
	{
		/* Cast to a native integer if accessing by pointer */
		if(currentType == ILType_Int32 || currentType == ILType_Int64)
		{
			result = ILNode_CastSimple_create(node, ILMachineType_NativeInt);
		}
		else
		{
			result = ILNode_CastSimple_create(node, ILMachineType_NativeUInt);
		}
	}
	else if(info->overflowInsns)
	{
		/* We are already in overflow mode, so just wrap it */
		result = ILNode_CastSimple_create(node, ILMachineType_Int32);
	}
	else
	{
		/* The index is not being computed in overflow mode,
		   but we want an overflow conversion for the cast */
		result = ILNode_Overflow_create
					(ILNode_CastSimple_create
						(ILNode_NoOverflow_create(node), ILMachineType_Int32));
	}
	*parent = result;
	return result;
}

/*
 * Coerce an array index to "int", "uint", "long", or "ulong".
 */
static void CoerceArrayIndex(ILGenInfo *info, ILNode **node,
							 ILNode **parent, ILType *type,
							 int pointerAccess)
{
	if(ILCoerce(info, *node, parent, type, ILType_Int32, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_Int32, pointerAccess);
	}
	else if(ILCoerce(info, *node, parent, type, ILType_UInt32, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_UInt32, pointerAccess);
	}
	else if(ILCoerce(info, *node, parent, type, ILType_Int64, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_Int64, pointerAccess);
	}
	else if(ILCoerce(info, *node, parent, type, ILType_UInt64, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_Int64, pointerAccess);
	}
	else
	{
		CCErrorOnLine(yygetfilename(*node), yygetlinenum(*node),
					  "no conversion from `%s' to `int'",
					  CSTypeToName(type));
	}
}

#line 154 "cs_misc.tc"


/*
 * Get the size of a type if it is static.  Returns zero if it isn't.
 */
static ILUInt32 GetPrimitiveTypeSize(ILType *type)
{
	if(ILType_IsPrimitive(type))
	{
		switch(ILType_ToElement(type))
		{
			case IL_META_ELEMTYPE_BOOLEAN:
			case IL_META_ELEMTYPE_I1:
			case IL_META_ELEMTYPE_U1:		return 1;

			case IL_META_ELEMTYPE_CHAR:
			case IL_META_ELEMTYPE_I2:
			case IL_META_ELEMTYPE_U2:		return 2;

			case IL_META_ELEMTYPE_I4:
			case IL_META_ELEMTYPE_U4:
			case IL_META_ELEMTYPE_R4:		return 4;

			case IL_META_ELEMTYPE_I8:
			case IL_META_ELEMTYPE_U8:
			case IL_META_ELEMTYPE_R8:		return 8;
		}
	}
	return 0;
}

#line 180 "cs_invoke.tc"


void CSItemCandidateError(ILNode *node, char *itemName, int isCtor,
						  void *group, CSEvalArg *args, int numArgs)
{
	unsigned long num;
	ILProgramItem *item;
	ILIntString str;
	int argNum;

	/* Report the item name and argument types */
	if(itemName)
	{
		/* Construct a list of the argument types for the error */
		str = ILInternString(itemName, -1);
		str = ILInternAppendedString(str, ILInternString("(", 1));
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			if(argNum != 0)
			{
				str = ILInternAppendedString(str, ILInternString(", ", 2));
			}
			if(args[argNum].modifier == ILParamMod_out)
			{
				str = ILInternAppendedString(str, ILInternString("out ", 4));
			}
			else if(args[argNum].modifier == ILParamMod_ref)
			{
				str = ILInternAppendedString(str, ILInternString("ref ", 4));
			}
			if(args[argNum].modifier != ILParamMod_arglist)
			{
				str = ILInternAppendedString
					(str, ILInternString
							((char *)CSTypeToName(args[argNum].type), -1));
			}
			else
			{
				str = ILInternAppendedString
					(str, ILInternString("__arglist", 9));
			}
		}
		str = ILInternAppendedString(str, ILInternString(")", 1));
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no matching method for call to `%s'",
					  str.string);
	}
	else if(isCtor == 2)
	{
		/* Don't know what the method name is */
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no matching constructor for base class initialization");
	}
	else if(isCtor)
	{
		/* Don't know what the method name is */
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no matching constructor");
	}
	else
	{
		/* Don't know what the method name is */
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no matching method for call");
	}

	/* Report the candidates */
	num = 0;
	while((item = CSGetGroupMember(group, num)) != 0)
	{
		if(!num)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "candidates are: %s", CSItemToName(item));
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "                %s", CSItemToName(item));
		}
		++num;
	}
}

/*
 * Make a call site signature from a method signature and
 * a list of "__arglist" parameter types.
 */
static ILType *MakeCallSiteSig(ILGenInfo *info, ILType *methodSig,
							   ILType *argTypes)
{
	unsigned long numParams;
	unsigned long numMethodParams;
	unsigned long paramNum;
	ILType *signature;

	/* Use the method's signature if there are no extra arguments */
	numParams = ILTypeNumParams(argTypes);
	if(!numParams)
	{
		return methodSig;
	}

	/* Create a new signature for the call site */
	signature = ILTypeCreateMethod
		(info->context, ILTypeGetReturnWithPrefixes(methodSig));
	if(!signature)
	{
		CCOutOfMemory();
	}
	ILTypeSetCallConv(signature, ILType_CallConv(methodSig));
	signature->kind__ |= IL_TYPE_COMPLEX_METHOD_SENTINEL;

	/* Copy the method's current parameters to the call site */
	numMethodParams = ILTypeNumParams(methodSig);
	for(paramNum = 1; paramNum <= numMethodParams; ++paramNum)
	{
		if(!ILTypeAddParam(info->context, signature,
						   ILTypeGetParamWithPrefixes(methodSig, paramNum)))
		{
			CCOutOfMemory();
		}
	}

	/* Add a sentinel to the call site */
	if(!ILTypeAddSentinel(info->context, signature))
	{
		CCOutOfMemory();
	}

	/* Add the types of the variable arguments to the call site */
	for(paramNum = 1; paramNum <= numParams; ++paramNum)
	{
		if(!ILTypeAddParam(info->context, signature,
						   ILTypeGetParamWithPrefixes(argTypes, paramNum)))
		{
			CCOutOfMemory();
		}
	}

	/* The call site is ready */
	return signature;
}

/*
 * Reduce a method group to a set of candidates.
 */
static void ReduceMethodGroup(ILGenInfo *info, CSEvalArg *args,
							  int numArgs, CSSemValue *method)
{
	unsigned long itemNum;
	int candidateForm;
	ILProgramItem *itemInfo;
	ILMember *member;
	ILClass *lowestOwner = 0;
	ILClass *owner;

	/* Remove methods that aren't candidates */
	itemNum = 0;
	while((itemInfo = CSGetGroupMember(CSSemGetGroup(*method), itemNum)) != 0)
	{
		candidateForm = CSItemIsCandidate(info, itemInfo, args, numArgs);
		if(candidateForm)
		{
			CSSetGroupMemberForm(CSSemGetGroup(*method), itemNum,
								 candidateForm);
			++itemNum;
			member = ILProgramItemToMember(itemInfo);
			if(member)
			{
				owner = ILClassResolve(ILMember_Owner(member));
				if(!lowestOwner)
				{
					lowestOwner = owner;
				}
				else if(CSIsBaseTypeFor(lowestOwner, owner))
				{
					lowestOwner = owner;
				}
			}
		}
		else
		{
			CSSemModifyGroup(*method, CSRemoveGroupMember
								(CSSemGetGroup(*method), itemNum));
		}
	}

	/* Remove candidates in base classes */
	if(lowestOwner)
	{
		itemNum = 0;
		while((itemInfo = CSGetGroupMember(CSSemGetGroup(*method), itemNum))
					!= 0)
		{
			member = ILProgramItemToMember(itemInfo);
			if(member)
			{
				owner = ILClassResolve(ILMember_Owner(member));
				if(owner != lowestOwner)
				{
					CSSemModifyGroup(*method, CSRemoveGroupMember
										(CSSemGetGroup(*method), itemNum));
				}
				else
				{
					++itemNum;
				}
			}
			else
			{
				++itemNum;
			}
		}
	}
}

#line 602 "cs_invoke.tc"


/*
 * Peform semantic analysis for the delegate creation variant
 * of an object creation expression.
 */
CSSemValue DelegateCreationSem(ILGenInfo *info, ILNode *node,
							   ILType *delegateType, ILNode *expr,
							   ILNode **parent)
{
	CSSemValue result;
	CSSemValue method;
	unsigned long itemNum;
	ILProgramItem *itemInfo;
	ILMethod *firstMatch;
	ILNode_MethodDeclaration *caller;
	ILNode *newExpr;
	ILNode *thisExpr;

	/* The result is an r-value of type "delegateType" */
	CSSemSetRValue(result, delegateType);

	/* Perform semantic analysis on the expression to get the
	   method group corresponding to the delegate instance */
	newExpr = expr;
	method = ILNode_SemAnalysis(expr, info, &newExpr);

	if(CSSemIsValue(method) && ILTypeIsDelegate(CSSemGetType(method)))
	{
		/* This is a delegate variable: create a method group
		   that contains the "Invoke" method as its only member */
		void *group = CSCreateMethodGroup
				(ILTypeGetDelegateMethod(CSSemGetType(method)));
		CSSemSetMethodGroup(method, group);
	}

	if(!CSSemIsMethodGroup(method))
	{
		CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
		  			  "delegate expression does not refer to a method");
		return result;
	}

	/* Find a match with the delegate's "Invoke" method */
	itemNum = 0;
	firstMatch = 0;
	while((itemInfo = CSGetGroupMember(CSSemGetGroup(method), itemNum)) != 0)
	{
		if(ILTypeDelegateSignatureMatch(delegateType, itemInfo))
		{
			if(firstMatch)
			{
				/* We have two (or possibly more) matches for the delegate */
				CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
	  			  "delegate expression supplies multiple candidates for `%s'",
				  CSTypeToName(delegateType));
				return result;
			}
			firstMatch = (ILMethod *)itemInfo;
		}
		++itemNum;
	}
	if(!firstMatch)
	{
		/* We weren't able to find a match for the delegate */
		CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
  			  "delegate expression is not compatible with `%s'",
			  CSTypeToName(delegateType));
		return result;
	}

	/* Build the DelegateCreationExpression node */
	if(ILMethod_IsStatic(firstMatch))
	{
		*parent = ILNode_DelegateCreationExpression_create
			(ILType_ToClass(delegateType), 0, firstMatch);
	}
	else
	{
		if(yyisa(newExpr,ILNode_Argument))
		{
			thisExpr=((ILNode_Argument*)(newExpr))->expression;
			if(yyisa(thisExpr, ILNode_This) ||
		  	  (yyisa(thisExpr, ILNode_MarkType) &&
			   yyisa(((ILNode_MarkType *)(thisExpr))->expr, ILNode_This)))
			{
				caller = (ILNode_MethodDeclaration *)(info->currentMethod);
				if(!caller || 
					(caller->modifiers & IL_META_METHODDEF_STATIC) != 0)
				{
					/* Attempt to call an instance method using "this"
					   from within a static method */
					CCErrorOnLine(yygetfilename(newExpr), yygetlinenum(newExpr),
						  "cannot access instance members in static methods");
				}
			}
		}
		*parent = ILNode_DelegateCreationExpression_create
			(ILType_ToClass(delegateType), newExpr, firstMatch);
	}

	/* Return the result to the caller */
	return result;
}

#line 1073 "cs_invoke.tc"


/*
 * Count the number of arguments in an ArgList.
 */
static unsigned CountArgList(ILNode *argList)
{
	unsigned count;
	if(!argList)
	{
		return 0;
	}
	count = 1;
	while(yyisa(argList, ILNode_ArgList))
	{
		++count;
		argList = ((ILNode_ArgList *)argList)->expr1;
	}
	return count;
}

/*
 * Get the parameter modifier for an argument.
 */
static ILParameterModifier GetParamModForArg(ILNode *arg)
{
	if(yyisa(arg, ILNode_Argument))
	{
		return ((ILNode_Argument *)arg)->modifier;
	}
	else
	{
		return ILParamMod_empty;
	}
}

/*
 * Perform semantic analysis on a vararg parameter list.
 * Returns zero if an error occurred.
 */
static int VarArgElemSem(ILNode *node, ILGenInfo *info, ILType *signature)
{
	if(!node)
	{
		/* Empty vararg parameter list */
		return 1;
	}
	else if(yyisa(node, ILNode_ArgList))
	{
		return VarArgElemSem(((ILNode_ArgList *)node)->expr1,
							 info, signature) &		/* Deliberately not '&&' */
			   VarArgElemSem(((ILNode_ArgList *)node)->expr2,
			   				 info, signature);
	}
	else
	{
		ILNode_Argument *arg = (ILNode_Argument *)node;
		CSSemValue value;
		ILType *argType;
		if(arg->modifier == ILParamMod_empty)
		{
			if(!CSSemExpectValue(arg->expression, info, &(arg->expression),
								 &value))
			{
				CCErrorOnLine(yygetfilename(arg), yygetlinenum(arg),
							  "invalid argument used with `__arglist'");
				return 0;
			}
			argType = CSSemGetType(value);
			if(argType == ILType_Null)
			{
				/* Replace the null type with "System.Object" */
				argType = ILFindSystemType(info, "Object");
			}
			if(!ILTypeAddParam(info->context, signature, argType))
			{
				CCOutOfMemory();
			}
			return 1;
		}
		else
		{
			CCErrorOnLine(yygetfilename(arg), yygetlinenum(arg),
						  "cannot use `%s' arguments with `__arglist'",
						  ((arg->modifier == ILParamMod_ref) ? "ref" :
						  ((arg->modifier == ILParamMod_out) ? "out"
						  		: "__arglist")));
			return 0;
		}
	}
}

/*
 * Perform semantic analysis on a list of vararg parameters.
 * Returns zero if an error occurred.
 */
static int VarArgSemAnalysis(ILNode_VarArgExpand *node, ILGenInfo *info)
{
	/* Create a fake method signature to hold the argument types */
	node->varArgTypes = ILTypeCreateMethod(info->context, ILType_Void);
	if(!(node->varArgTypes))
	{
		CCOutOfMemory();
	}

	/* Scan the argument list, performing semantic analysis on each element */
	return VarArgElemSem(node->expr, info, node->varArgTypes);
}

int CSEvalArguments(ILGenInfo *info, ILNode *argList,
					ILNode **argListParent, CSEvalArg **args)
{
	int argCount;
	int argNum;
	CSEvalArg *argArray;
	ILNode *tempList;
	ILNode **tempParent;
	int tempNum;
	int haveErrors;
	CSSemValue value;

	/* Get the number of arguments that have been supplied */
	argCount = CountArgList(argList);

	/* Bail out if there are no arguments */
	if(!argCount)
	{
		*args = 0;
		return 0;
	}

	/* Allocate an argument array */
	argArray = (CSEvalArg *)ILMalloc(sizeof(CSEvalArg) * argCount);
	if(!argArray)
	{
		CCOutOfMemory();
	}

	/* Perform semantic analysis on the arguments and fill the array */
	haveErrors = 0;
	for(argNum = 0; argNum < argCount; ++argNum)
	{
		/* Find the argument node and its parent */
		tempList = argList;
		tempParent = argListParent;
		tempNum = argNum + 1;
		while(tempNum < argCount)
		{
			tempParent = &(((ILNode_ArgList *)tempList)->expr1);
			tempList = ((ILNode_ArgList *)tempList)->expr1;
			++tempNum;
		}
		if(yyisa(tempList, ILNode_ArgList))
		{
			tempParent = &(((ILNode_ArgList *)tempList)->expr2);
			tempList = ((ILNode_ArgList *)tempList)->expr2;
		}

		/* Populate the argument array element */
		if(!yyisa(tempList, ILNode_Argument) ||
		   !yyisa(((ILNode_Argument *)tempList)->expression,
		   		  ILNode_VarArgExpand))
		{
			/* Ordinary argument */
			value = ILNode_SemAnalysis(tempList, info, tempParent);
			argArray[argNum].node = *tempParent;
			argArray[argNum].parent = tempParent;
			argArray[argNum].modifier = GetParamModForArg(tempList);
			if(CSSemIsValue(value))
			{
				argArray[argNum].type = CSSemGetType(value);
			}
			else
			{
				argArray[argNum].type = ILType_Void;
				CCErrorOnLine(yygetfilename(tempList),
							  yygetlinenum(tempList),
							  "invalid value for argument %u", argNum + 1);
				haveErrors = 1;
			}
		}
		else
		{
			/* Argument that has the form "__arglist(x, y, z, ...)" */
			argArray[argNum].node = *tempParent;
			argArray[argNum].parent = tempParent;
			argArray[argNum].modifier = ILParamMod_arglist;

			/* "__arglist" parameters must have the "empty" modifier */
			if(((ILNode_Argument *)tempList)->modifier != ILParamMod_empty)
			{
				CCErrorOnLine(yygetfilename(tempList), yygetlinenum(tempList),
					  "cannot use `ref' or `out' with `__arglist' arguments");
				haveErrors = 1;
			}

			/* "__arglist" must be the last argument */
			if((argNum + 1) != argCount)
			{
				CCErrorOnLine(yygetfilename(tempList), yygetlinenum(tempList),
					  		  "`__arglist' must be the last argument");
				haveErrors = 1;
			}

			/* Perform semantic analysis on the "__arglist" values */
			if(!VarArgSemAnalysis
					(((ILNode_VarArgExpand *)
						(((ILNode_Argument *)tempList)->expression)), info))
			{
				haveErrors = 1;
			}
		}
	}

	/* Report either an error, or the argument count */
	if(haveErrors)
	{
		ILFree(argArray);
		*args = 0;
		return -1;
	}
	else
	{
		*args = argArray;
		return argCount;
	}
}

void CSEvalFreeArguments(CSEvalArg *args)
{
	if(args)
	{
		ILFree(args);
	}
}

/*
 * Get the "Invoke" method associated with a delegate class.
 */
static ILMethod *GetDelegateInvoke(ILClass *info)
{
	return ILTypeGetDelegateMethod(ILType_FromClass(info));
}

/*
 * Get the type and modifier information associated with
 * an item parameter.  The first parameter is 0.  Returns
 * ILType_Invalid if the parameter index is invalid.
 */
static ILType *GetItemParamType(ILProgramItem *item, ILType *signature,
								int paramNum, ILParameterModifier *paramMod)
{
	int numParams = ILGenNumUsableParams(signature);
	int firstParam;
	ILType *paramType;
	ILMethod *method;
	ILClass *classInfo;
	ILProperty *property;

	/* If we have an "explicit this" method, then we need to
	   adjust for the first parameter, which is always "this" */
	if((ILType_CallConv(signature) & IL_META_CALLCONV_HASTHIS) != 0 &&
	   (ILType_CallConv(signature) & IL_META_CALLCONV_EXPLICITTHIS) != 0 &&
	   numParams > 0)
	{
		firstParam = 2;
	}
	else
	{
		firstParam = 1;
	}

	/* Bail out if the parameter number is out of range */
	if(paramNum > (numParams - firstParam))
	{
		return ILType_Invalid;
	}

	/* Get the parameter type information and return it */
	if((method = ILProgramItemToMethod(item)) != 0)
	{
		*paramMod = ILGenGetParamInfo(method, signature, paramNum + firstParam,
									  &paramType);
	}
	else if((classInfo = ILProgramItemToClass(item)) != 0)
	{
		/* Get the delegate method.  If there is none, then use
		   the information in the signature */
		method = GetDelegateInvoke(classInfo);
		*paramMod = ILGenGetParamInfo
				(method, signature, paramNum + firstParam, &paramType);
	}
	else if((property=ILProgramItemToProperty(item))!=0)
	{
		/* To handle the rare case of a variable params indexer
		 * NOTE: get_ and set_ methods have the same sig , right ? */	
		 if((method=ILProperty_Getter(property))!=0)
		 {
			*paramMod = ILGenGetParamInfo(method, signature, 
										paramNum + firstParam,&paramType);
		 }
		 else if((method=ILProperty_Setter(property))!=0)
		 {
			*paramMod = ILGenGetParamInfo(method, signature, 
										paramNum + firstParam,&paramType);
		 }
		 else /* just for that rare case */
		 {
			*paramMod = ILGenGetParamInfo
						(0, signature, paramNum + firstParam, &paramType);
		 }
	}
	else
	{
		/* Probably an indexer property: use the signature */
		*paramMod = ILGenGetParamInfo
				(0, signature, paramNum + firstParam, &paramType);
	}
	return paramType;
}

/*
 * Get the type information associated with an item parameter,
 * given that its expansion form is known.
 */
static ILType *GetItemExpandedType(ILProgramItem *item, ILType *signature,
								   int form, int paramNum,
								   ILParameterModifier *paramMod)
{
	ILType *paramType;
	paramType = GetItemParamType(item, signature, paramNum, paramMod);
	if(paramType == ILType_Invalid)
	{
		return ILType_Invalid;
	}
	else if(*paramMod == ILParamMod_params)
	{
		if(form == 2)
		{
			/* We are using the "params" array in its expanded form */
			return paramType;
		}
		else
		{
			/* We are using the "params" array in its array form */
			return ILTypeGetParam(signature, ILTypeNumParams(signature));
		}
	}
	return paramType;
}

/*
 * Get the element type of a single-dimensional array,
 * or return ILType_Invalid if not such as array.
 */
static ILType *GetArrayElemType(ILType *type)
{
	if(type != 0 && ILType_IsComplex(type) &&
	   ILType_Kind(type) == IL_TYPE_COMPLEX_ARRAY)
	{
		return ILType_ElemType(type);
	}
	else
	{
		return ILType_Invalid;
	}
}

/*
 * Get the signature of a program item (method, property, or delegate).
 */
static ILType *GetItemSignature(ILProgramItem *item)
{
	ILMethod *method;
	ILProperty *property;
	ILClass *classInfo;
	ILEvent *event;

	/* Determine what kind of item we are dealing with */
	if((method = ILProgramItemToMethod(item)) != 0)
	{
		return ILMethod_Signature(method);
	}
	else if((property = ILProgramItemToProperty(item)) != 0)
	{
		return ILProperty_Signature(property);
	}
	else if((classInfo = ILProgramItemToClass(item)) != 0)
	{
		/* Look for the "Invoke" method within the delegate */
		method = GetDelegateInvoke(classInfo);
		if(method)
		{
			return ILMethod_Signature(method);
		}
	}
	else if((event = ILProgramItemToEvent(item)) != 0)
	{
		return ILEvent_Type(event);
	}
	
	/* If we get here, then we do not know how to obtain the signature */
	return 0;
}

int CSItemIsCandidate(ILGenInfo *info, ILProgramItem *item,
					  CSEvalArg *args, int numArgs)
{
	ILType *signature = GetItemSignature(item);
	int argNum, paramNum;
	ILParameterModifier paramMod;
	ILType *paramType;
	ILType *elemType;
	int matchParams;

	/* If the item does not have a signature, then bail out */
	if(!signature)
	{
		return 0;
	}

	/* Scan through the parameters looking for a match */
	paramNum = 0;
	matchParams = 0;
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		paramType = GetItemParamType(item, signature, paramNum, &paramMod);
		if(paramType == ILType_Invalid)
		{
			/* Too many arguments were supplied */
			return 0;
		}
		else if(paramMod == ILParamMod_params)
		{
			if(args[argNum].modifier != ILParamMod_empty)
			{
				return 0;
			}
			if(matchParams)
			{
				/* We already started matching as an element type,
				   so we must keep matching as an element type */
				if(!ILCanCoerce(info, args[argNum].type, paramType,1))
				{
					return 0;
				}
			}
			else
			{
				/* The match can either be as an array, or as an element type */			
				elemType = GetArrayElemType(args[argNum].type);
				if((argNum == (numArgs-1)) && elemType != ILType_Invalid &&
				   ILCanCoerce(info, elemType, paramType,1))
				{
					/* Matched as an array */
					++paramNum;
				}
				else if(!ILCanCoerce(info, args[argNum].type, paramType,1))
				{
					if(args[argNum].type==ILType_Null)
					{
						/* Matched as a null array */
						++paramNum;
					}
					else
					{
						/* Could not match as an array or as an element */
						return 0;
					}
				}
				else
				{
					/* Match everything else as an element */
					matchParams = 1;
				}
			}
		}
		else if(paramMod != args[argNum].modifier)
		{
			/* Incorrect modifiers */
			return 0;
		}
		else if(paramMod == ILParamMod_empty)
		{
			/* Match anything that can coerce to the parameter type */
			if (!ILCanCoerceNode(info, args[argNum].node, 
									args[argNum].type, paramType,1))
			{
				return 0;
			}
			++paramNum;
		}
		else if(paramMod != ILParamMod_arglist)
		{
			/* The type match must be exact for "ref" and "out" parameters */
			if(!ILTypeIdentical(args[argNum].type, paramType))
			{
				return 0;
			}
			++paramNum;
		}
		else
		{
			/* Variable argument lists match as-is */
			++paramNum;
		}
	}

	/* Get the next parameter type, which must either be
	   a "params" array, or the end of the parameter list */
	paramType = GetItemParamType(item, signature, paramNum, &paramMod);
	if(paramType == ILType_Invalid)
	{
		/* The candidate was matched in its normal form */
		return 1;
	}
	else if(paramMod == ILParamMod_params)
	{
		/* The candidate was matched in its expanded form */
		return 2;
	}
	else
	{
		/* The candidate did not match */
		return 0;
	}
}

/*
 * Determine which of two items is better than the other one.
 * Returns IL_BETTER_T1 if "item1" is better, or IL_BETTER_T2
 * if "item2" is better, or IL_BETTER_NEITHER if neither is better.
 */
static int BetterItem(ILGenInfo *info,
					  ILProgramItem *item1, int form1,
					  ILProgramItem *item2, int form2,
					  CSEvalArg *args, int numArgs)
{
	ILType *signature1 = GetItemSignature(item1);
	ILType *signature2 = GetItemSignature(item2);
	int argNum;
	int paramNum1;
	int paramNum2;
	ILParameterModifier paramMod1;
	ILParameterModifier paramMod2;
	ILType *type1;
	ILType *type2;
	ILType *atype;
	int better, betterTest;

	/* Compare the argument types */
	paramNum1 = 0;
	paramNum2 = 0;
	better = IL_BETTER_NEITHER;
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		/* Get the types of the two parameters and the argument */
		type1 = GetItemExpandedType(item1, signature1,
									form1, paramNum1++, &paramMod1);
		type2 = GetItemExpandedType(item2, signature2,
									form2, paramNum2++, &paramMod2);
		atype = args[argNum].type;

		/* Skip the argument if "out", "ref", or "arglist", because such
		   arguments must always be identical, so neither can be better */
		if(paramMod1 == ILParamMod_out || paramMod1 == ILParamMod_ref ||
		   paramMod1 == ILParamMod_arglist ||
		   paramMod2 == ILParamMod_out || paramMod2 == ILParamMod_ref ||
		   paramMod2 == ILParamMod_arglist)
		{
			continue;
		}

		/* Determine which is the better coercion */
		betterTest = ILBetterConversion(info, args[argNum].type, type1, type2);
		if(betterTest == IL_BETTER_T1)
		{
			if(better == IL_BETTER_T2)
			{
				/* The first item is better in this parameter,
				   but worse in others */
				better = -1;
			}
			else if(better != -1)
			{
				/* The first item is better so far */
				better = IL_BETTER_T1;
			}
		}
		else if(betterTest == IL_BETTER_T2)
		{
			if(better == IL_BETTER_T1)
			{
				/* The second item is better in this parameter,
				   but worse in others */
				better = -1;
			}
			else if(better != -1)
			{
				/* The second item is better so far */
				better = IL_BETTER_T2;
			}
		}

		/* Back up and revisit "params" parameters within expanded forms */
		if(paramMod1 == ILParamMod_params)
		{
			--paramNum1;
		}
		if(paramMod2 == ILParamMod_params)
		{
			--paramNum2;
		}
	}

	/* Return the result to the caller */
	if(better != -1)
	{
		return better;
	}
	else
	{
		return IL_BETTER_NEITHER;
	}
}

ILProgramItem *CSBestCandidate(ILGenInfo *info, void *group,
						       CSEvalArg *args, int numArgs)
{
	unsigned long itemNum = 1;
	ILProgramItem *bestItem = CSGetGroupMember(group, 0);
	ILProgramItem *testItem;
	int better;
	int form1 = CSGetGroupMemberForm(group, 0);
	int form2;
	int sawBetter = 0;
	while((testItem = CSGetGroupMember(group, itemNum)) != 0)
	{
		form2 = CSGetGroupMemberForm(group, itemNum);
		better = BetterItem(info, bestItem, form1, testItem,
							form2, args, numArgs);
		if(better == IL_BETTER_T1)
		{
			sawBetter = 1;
		}
		else if(better == IL_BETTER_T2)
		{
			bestItem = testItem;
			sawBetter = 1;
		}
		else if(better == IL_BETTER_NEITHER && (form1 == 2 && form2 != 2))
		{
			/* We've found an item that is just as applicable as
			   a previous one.  However, the previous one involved
			   "params" and this one doesn't.  So use this one */
			bestItem = testItem;
			sawBetter = 1;
		}
		else if(better == IL_BETTER_NEITHER && (form1 != 2 && form2 == 2))
		{
			/* We've found an item that is just as applicable as
			   a previous one.  However, this one involved "params"
			   and the previous one didn't.  So use the previous one */
			sawBetter = 1;
		}
		++itemNum;
	}
	if(sawBetter)
	{
		return bestItem;
	}
	else
	{
		return 0;
	}
}

ILType *CSItemCoerceArgs(ILGenInfo *info, ILProgramItem *item,
						 CSEvalArg *args, int numArgs,
						 ILNode **argListParent)
{
	ILType *signature = GetItemSignature(item);
	int argNum, argNum2, paramNum;
	ILParameterModifier paramMod;
	ILType *paramType;
	ILType *elemType;
	ILNode *argList;
	ILNode *argArray;

	/* Coerce the fixed parameters */
	paramNum = 0;
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		paramType = GetItemParamType(item, signature, paramNum, &paramMod);
		if(paramMod == ILParamMod_params)
		{
			break;
		}
		else if(paramMod != ILParamMod_ref && paramMod != ILParamMod_out &&
		        paramMod != ILParamMod_arglist)
		{
			ILCoerce(info, args[argNum].node,
					 args[argNum].parent, args[argNum].type, paramType,0);
		}
		++paramNum;
	}

	/* Coerce the remaining "params" parameters */
	paramType = GetItemParamType(item, signature, paramNum, &paramMod);
	if(paramType != ILType_Invalid && paramMod == ILParamMod_params)
	{
		/* Determine how to repack the arguments */
		if(argNum < numArgs)
		{
			elemType = GetArrayElemType(args[argNum].type);
			if((argNum == (numArgs-1)) && elemType != ILType_Invalid &&
			   ILCanCoerce(info, elemType, paramType,1))
			{
				/* Pass the argument as an array */
				paramType = ILTypeGetParam
					(signature, ILTypeNumParams(signature));
				ILCoerce(info, args[argNum].node,
						 args[argNum].parent, args[argNum].type, paramType,0);
				argArray = 0;
			}
			/* Note: ILCanCoerce can be used to handle stuff intelligently
			   here but that's not what MS CSC does */
			else if(args[argNum].type==ILType_Null) 
			{
				/* Matched as a null array */
				argArray = 0;
			}
			else
			{
				/* Coerce the remaining arguments to the element type */
				for(argNum2 = argNum; argNum2 < numArgs; ++argNum2)
				{
					ILCoerce(info, args[argNum2].node,
							 args[argNum2].parent, args[argNum2].type,
							 paramType,0);
				}

				/* Build an array that contains the remaining arguments */
				argArray = 0;
				for(argNum2 = argNum; argNum2 < numArgs; ++argNum2)
				{
					if(argArray)
					{
						argArray = ILNode_ArgList_create
										(argArray, *(args[argNum2].parent));
					}
					else
					{
						argArray = *(args[argNum2].parent);
					}
				}
				argArray = ILNode_ArgArray_create
								(paramType, numArgs - argNum, argArray);
			}
		}
		else
		{
			/* No extra arguments, so create an empty array */
			argArray = ILNode_ArgArray_create(paramType, 0, 0);
		}

		/* Build a new argument list if necessary */
		if(argArray)
		{
			argList = 0;
			for(argNum2 = 0; argNum2 < argNum; ++argNum2)
			{
				if(argList)
				{
					argList = ILNode_ArgList_create
									(argList, *(args[argNum2].parent));
				}
				else
				{
					argList = *(args[argNum2].parent);
				}
			}
			if(argList)
			{
				argList = ILNode_ArgList_create(argList, argArray);
			}
			else
			{
				argList = argArray;
			}
			*argListParent = argList;
		}
	}

	/* Return the item's return type to the caller */
	return ILTypeGetReturn(signature);
}

const char *CSItemToName(ILProgramItem *item)
{
	ILType *signature = GetItemSignature(item);
	const char *name;
	ILIntString str;
	ILType *type;
	ILParameterModifier paramMod;
	unsigned numParams;
	unsigned param;
	int kind;
	ILMethod *method;
	ILProperty *property;
	ILClass *classInfo;
	ILClass *owner;
	ILEvent *event;

	/* Get the name of the item, and find an underlying method */
	if((method = ILProgramItemToMethod(item)) != 0)
	{
		name = ILMethod_Name(method);
		kind = IL_META_MEMBERKIND_METHOD;
		owner = ILMethod_Owner(method);
	}
	else if((property = ILProgramItemToProperty(item)) != 0)
	{
		name = ILProperty_Name(property);
		kind = IL_META_MEMBERKIND_PROPERTY;
		method = ILProperty_Getter(property);
		if(!method)
		{
			method = ILProperty_Setter(property);
		}
		owner = ILProperty_Owner(property);
	}
	else if((classInfo = ILProgramItemToClass(item)) != 0)
	{
		name = ILClass_Name(classInfo);
		kind = 0;
		method = GetDelegateInvoke(classInfo);
		owner = classInfo;
	}
	else if((event = ILProgramItemToEvent(item)) != 0)
	{
		name = ILEvent_Name(event);
		kind = IL_META_MEMBERKIND_EVENT;
		method = 0;
		owner = ILEvent_Owner(event);
	}
	else
	{
		name = "unknown";
		kind = IL_META_MEMBERKIND_METHOD;
		method = 0;
		owner = 0;
	}

	/* Put "static" or "virtual" on the front if necessary */
	if(method && ILMethod_IsStatic(method))
	{
		str = ILInternString("static ", 7);
	}
	else if(method && ILMethod_IsVirtual(method))
	{
		str = ILInternString("virtual ", 8);
	}
	else
	{
		str = ILInternString("", 0);
	}

	/* Get the type of the class that contains the method */
	type = (owner ? ILType_FromClass(owner) : 0);

	/* add the "event" if it is an event */
	if(kind == IL_META_MEMBERKIND_EVENT)
	{
		str = ILInternAppendedString(str, ILInternString("event ", 6));

		/* Convert the event type into a string */
		str = ILInternAppendedString
				(str, ILInternString((char *)CSTypeToName
										(signature), -1));
		str = ILInternAppendedString(str, ILInternString(" ", 1));
		
		/* Append the class name to the string */
		str = ILInternAppendedString
				(str, ILInternString((char *)CSTypeToName(type), -1));

		/* Append a dot to the string */
		str = ILInternAppendedString(str, ILInternString(".", 1));

		/* Append the event name to the string */
		str = ILInternAppendedString(str, ILInternString((char *)name, -1));
		
		/* return final string to caller */
		return str.string;
		
	}
	/* The formatting is slightly different for constructors */
	else if(!strcmp(name, ".ctor") || !strcmp(name, ".cctor"))
	{
		/* Append the class name to the string */
		str = ILInternAppendedString
				(str, ILInternString((char *)CSTypeToName(type), -1));	
	}
	else
	{
		/* Convert the return type into a string */
		str = ILInternAppendedString
				(str, ILInternString((char *)CSTypeToName
										(ILTypeGetReturn(signature)), -1));
		str = ILInternAppendedString(str, ILInternString(" ", 1));

		/* Append the class name to the string */
		str = ILInternAppendedString
				(str, ILInternString((char *)CSTypeToName(type), -1));

		/* Don't add the method name for delegates */
		if(kind != 0)
		{
			/* Append a dot to the string */
			str = ILInternAppendedString(str, ILInternString(".", 1));

			/* Append the method name to the string */
			str = ILInternAppendedString(str, ILInternString((char *)name, -1));
		}
	}

	/* Add the parameter types to the string */
	if(kind == IL_META_MEMBERKIND_PROPERTY)
	{
		str = ILInternAppendedString(str, ILInternString("[", 1));
	}
	else 
	{
		str = ILInternAppendedString(str, ILInternString("(", 1));
	}
	numParams = ILGenNumUsableParams(signature);
	for(param = 1; param <= numParams; ++param)
	{
		if(method && kind != IL_META_MEMBERKIND_PROPERTY)
		{
			/* Use method information to resolve the parameter */
			paramMod = ILGenGetParamInfo(method, signature, param, &type);
		}
		else
		{
			/* Don't use method information to resolve the parameter */
			paramMod = ILGenGetParamInfo(0, signature, param, &type);
		}
		if(param != 1)
		{
			str = ILInternAppendedString(str, ILInternString(", ", 2));
		}
		if(paramMod == ILParamMod_out)
		{
			str = ILInternAppendedString(str, ILInternString("out ", 4));
		}
		else if(paramMod == ILParamMod_ref)
		{
			str = ILInternAppendedString(str, ILInternString("ref ", 4));
		}
		else if(paramMod == ILParamMod_params)
		{
			str = ILInternAppendedString(str, ILInternString("params ", 7));
		}
		if(paramMod != ILParamMod_arglist)
		{
			str = ILInternAppendedString
					(str, ILInternString((char *)CSTypeToName(type), -1));
			if(paramMod == ILParamMod_params)
			{
				str = ILInternAppendedString(str, ILInternString("[]", 2));
			}
		}
		else
		{
			str = ILInternAppendedString(str, ILInternString("__arglist", 9));
		}
	}
	if(kind == IL_META_MEMBERKIND_PROPERTY)
	{
		str = ILInternAppendedString(str, ILInternString("]", 1));
	}
	else
	{
		str = ILInternAppendedString(str, ILInternString(")", 1));
	}

	/* Return the final string to the caller */
	return str.string;
}

#line 21 "cs_oper.tc"


/*
 * Look for a user-specified binary operator of a particular name.
 */
static ILMethod *FindUserBinaryOperator(ILGenInfo *info, const char *name,
										CSSemValue *arg1, ILNode *arg1Node,
										CSSemValue *arg2, ILNode *arg2Node)
{
	ILMethod *method;
	ILType *arg1Type = CSSemGetType(*arg1);
	ILType *arg2Type = CSSemGetType(*arg2);
	ILClass *arg1Class = ILTypeToClass(info, arg1Type);
	ILClass *arg2Class = ILTypeToClass(info, arg2Type);

	/* Try looking in the first type */
	if(arg1Class)
	{
		method = ILResolveBinaryOperator(info, arg1Class, name,
										 arg1Type, arg1Node,
										 arg2Type, arg2Node);
		if(method)
		{
			return method;
		}
	}

	/* Try looking in the second type */
	if(arg2Class)
	{
		method = ILResolveBinaryOperator(info, arg2Class, name,
										 arg1Type, arg1Node,
										 arg2Type, arg2Node);
		if(method)
		{
			return method;
		}
	}

	/* The operator does not exist */
	return 0;
}

/* 
 * process UserBinaryOperator
 */
static void ApplyUserBinaryOperator(ILGenInfo *info, ILMethod *method,
									ILNode_BinaryExpression *node,
									ILNode **parent,CSSemValue *value1,
									CSSemValue *value2)
{
	ILType *returnType;
	ILType *sig;
	ILType *argType1, *argType2;
	
	method = (ILMethod *)ILMemberImport(info->image, (ILMember *)method);
	if(!method)
	{
		CCOutOfMemory();
		return; /* fall back */
	}
	
	sig= ILMethod_Signature(method);
	
	returnType = ILTypeGetReturn(sig);
	
	/* NOTE: this is valid even for non-static operators */
	argType1=ILTypeGetParam(sig,1); 
	argType2=ILTypeGetParam(sig,2);
	
	if(ILCanCoerce(info,CSSemGetType(*value1),argType1,1))
	{
		ILCoerce(info,node->expr1,
					&(node->expr1),
					CSSemGetType(*value1),
					argType1,1);
		/* CSSemSetRValue(*value1, argType1); *//* not needed */
	}
	if(ILCanCoerce(info,CSSemGetType(*value2),argType2,1))
	{
		ILCoerce(info,node->expr2,
					&(node->expr2),
					CSSemGetType(*value2),
					argType2,1);
		CSSemSetRValue(*value2, argType2);
	}
	*parent = ILNode_UserBinaryOp_create
						(((ILNode_BinaryExpression*)(node))->expr1, 
						((ILNode_BinaryExpression*)(node))->expr2,
						 ILTypeToMachineType(returnType), method);
	yysetfilename(*parent, yygetfilename(node));
	yysetlinenum(*parent, yygetlinenum(node));
	CSSemSetRValue(*value1, returnType);
}

/*
 * Perform constant evaluation on an operator node.
 */
static void EvalOperator(ILGenInfo *info, ILNode *node,
					     ILNode **parent, CSSemValue *result)
{
	ILEvalValue evalValue;
	if(ILNode_EvalConst(node, info, &evalValue))
	{
		CSSemSetConstant(*result, CSSemGetType(*result), evalValue);
		CSSemReplaceWithConstant(parent, *result);
	}
}

/*
 * Determine if a semantic value is zero.  Used to support
 * implicit coercions from zero to enumerated types.
 */
static int IsEnumZero(CSSemValue *value)
{
	ILEvalValue *evalValue = CSSemGetConstant(*value);
	if(evalValue)
	{
		switch(evalValue->valueType)
		{
			case ILMachineType_Int8:
			case ILMachineType_UInt8:
			case ILMachineType_Int16:
			case ILMachineType_UInt16:
			case ILMachineType_Int32:
				return (evalValue->un.i4Value == 0);

			default: break;
		}
	}
	return 0;
}

/*
 * Convert a type into one of "int", "uint", "long", or "ulong".
 */
static ILType *ToNumericType(ILGenInfo *info, ILType *fromType)
{
	if(ILCanCoerce(info, fromType, ILType_Int32, 0))
	{
		return ILType_Int32;
	}
	else if(ILCanCoerce(info, fromType, ILType_UInt32, 0))
	{
		return ILType_UInt32;
	}
	else if(ILCanCoerce(info, fromType, ILType_Int64, 0))
	{
		return ILType_Int64;
	}
	else if(ILCanCoerce(info, fromType, ILType_UInt64, 0))
	{
		return ILType_UInt64;
	}
	else
	{
		return 0;
	}
}

/*
 * Common semantic analysis function for binary arithmetic operators.
 */
static CSSemValue BinarySem(ILGenInfo *info, ILNode_BinaryExpression *node,
					        ILNode **parent, const ILOperator *table,
					        const char *name, const char *errorName,
							int canCoerce)
{
	const ILOperator *oper;
	ILMethod *method;
	CSSemValue value1;
	CSSemValue value2;
	ILType *resultType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));

	/* The two arguments must be values */
	if(!CSSemIsValue(value1) || !CSSemIsValue(value2))
	{
		goto error;
	}

	/* try constant coercion before operator lookup */
	if(canCoerce && ILCanCoerceNodeKind(info,node->expr1,CSSemGetType(value1),
			CSSemGetType(value2),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr1,&(node->expr1),CSSemGetType(value1),
			CSSemGetType(value2),IL_CONVERT_CONSTANT,1);
		CSSemSetRValue(value1,CSSemGetType(value2));
	}
	else if(canCoerce && 
			ILCanCoerceNodeKind(info,node->expr2,CSSemGetType(value2),
				CSSemGetType(value1),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr2,&(node->expr2),CSSemGetType(value2),
			CSSemGetType(value1),IL_CONVERT_CONSTANT,1);
		CSSemSetRValue(value2,CSSemGetType(value1));
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, CSSemGetType(value1),
								CSSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value1, resultType);
		}
		else
		{
			CSSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Check for binary operations involving pointers */
	if(ILType_IsPointer(CSSemGetType(value1)) &&
	   ILType_IsPointer(CSSemGetType(value2)))
	{
		if(table == ILOp_Lt || table == ILOp_Le ||
		   table == ILOp_Gt || table == ILOp_Ge)
		{
			/* Compare two pointers */
			CSSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
	}

	/* Look for a user-specified operator */
	method = FindUserBinaryOperator(info, name, &(value1), node->expr1,
									&(value2), node->expr2);
	if(method)
	{
		ApplyUserBinaryOperator(info,method,(ILNode_BinaryExpression*)node,
								parent,&(value1),&(value2));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}
	
	if(!canCoerce)
	{
		goto error;
	}

	/* As a last resort try coercion */
	if(ILCanCoerceNode(info, node->expr1, CSSemGetType(value1),
					   CSSemGetType(value2),1))
	{
		ILCoerce(info, node->expr1, &(node->expr1), CSSemGetType(value1),
				 CSSemGetType(value2),1);
		CSSemSetRValue(value1, CSSemGetType(value2));
	}
	else if(ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
					   CSSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), CSSemGetType(value2),
				 CSSemGetType(value1),1);
		CSSemSetRValue(value2, CSSemGetType(value1));
	}
	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, CSSemGetType(value1),
								CSSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value1, resultType);
		}
		else
		{
			CSSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `%s'", errorName);
	CSSemSetRValue(value1, ILType_Int32);
	return value1;
}

/*
 * Look for a user-specified unary operator of a particular name.
 */
static ILMethod *FindUserUnaryOperator(ILGenInfo *info, const char *name,
									   CSSemValue *arg, ILNode *argNode)
{
	ILMethod *method;
	ILType *argType = CSSemGetType(*arg);
	ILClass *argClass = ILTypeToClass(info, argType);

	if(argClass)
	{
		method = ILResolveUnaryOperator(info, argClass, name, argType, argNode);
		if(method)
		{
			return method;
		}
	}

	/* The operator does not exist */
	return 0;
}

/*
 * Common semantic analysis function for unary arithmetic operators.
 */
static CSSemValue UnarySem(ILGenInfo *info, ILNode_UnaryExpression *node,
					 	   ILNode **parent, const ILOperator *table,
						   const char *name, const char *errorName)
{
	const ILOperator *oper;
	ILMethod *method;
	ILType *returnType;
	CSSemValue value;
	ILType *resultType;

	/* Perform semantic analysis on the argument */
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));

	/* The argument must be a value */
	if(!CSSemIsValue(value))
	{
		goto error;
	}

	/* Look for a builtin operator */
	oper = ILFindUnaryOperator(table, CSSemGetType(value), &resultType);
	if(oper)
	{
		ILApplyUnaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value, resultType);
		}
		else
		{
			CSSemSetRValue(value, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value);
		return value;
	}

	/* Look for a user-specified operator */
	method = FindUserUnaryOperator(info, name, &(value), node->expr);
	if(method)
	{
		method = (ILMethod *)ILMemberImport(info->image, (ILMember *)method);
		if(!method)
		{
			CCOutOfMemory();
		}
		returnType = ILTypeGetReturn(ILMethod_Signature(method));
		*parent = ILNode_UserUnaryOp_create
						(node->expr, ILTypeToMachineType(returnType), method);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetRValue(value, returnType);
		return value;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to unary `%s'", errorName);
	CSSemSetRValue(value, ILType_Int32);
	return value;
}

#line 907 "cs_oper.tc"


/*
 * Coerce the elements of an array initializer to a common type.
 */
static void CoerceArrayInit(ILGenInfo *info, ILNode *expr,
							ILNode **parent, ILType *type)
{
	ILNode_ListIter iter;
	ILNode *node;
	CSSemValue value;

	if(yyisa(expr, ILNode_ArrayInit))
	{
		/* Recursively visit all array elements */
		ILNode_ListIter_Init(&iter, ((ILNode_ArrayInit *)expr)->expr);
		while((node = ILNode_ListIter_Next(&iter)) != 0)
		{
			CoerceArrayInit(info, node, iter.last, type);
		}
	}
	else
	{
		/* This is a normal array element */ 

		/*  Do semantic analysis on expr. Note expr and *parent
			are equivalent at this point, but *parent may be
			updated during semantic analysis.  Therefore, we must 
			subsequently coerce *parent instead of expr. */
		if(!CSSemExpectValue(expr, info, parent, &value))
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  _("invalid array initializer element"));
		}
		else if(!ILCanCoerceNode(info, *parent, CSSemGetType(value), type,1))
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
			  _("incompatible types in initializer: no conversion "
			  		"from `%s' to `%s'"),
			  CSTypeToName(CSSemGetType(value)), CSTypeToName(type));
		}
		else
		{
			ILCoerce(info, *parent, parent, CSSemGetType(value), type,1);
		}
	}
}

#line 1027 "cs_oper.tc"


/*
 * Common semantic analysis for operation-based assignment operators.
 */
static CSSemValue AssignSem(ILGenInfo *info, 
                            ILNode_AssignExpression *anode,
					        ILNode **assignParent,
							const ILOperator *table, const char *name,
							const char *errorName)
{
	/*  Re-jigger arguments from the original version  */
	ILNode_BinaryExpression *node = (ILNode_BinaryExpression *)anode->assign;
	ILNode **parent = &(anode->assign);
	const ILOperator *oper;
	ILMethod *method;
	CSSemValue value1;
	CSSemValue value2;
	ILType *resultType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	anode->lvalue = node->expr1;  /* Preserve lvalue for later */
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));

	/* The first argument must be an event or an lvalue */
	if(CSSemIsEvent(value1) &&
	   (yyisa(node, ILNode_Add) || yyisa(node, ILNode_Sub)))
	{
		/* Extract the add or remove method from the event */
		if(yyisa(node, ILNode_Add))
		{
			method = ILEvent_AddOn(CSSemGetEvent(value1));
		}
		else
		{
			method = ILEvent_RemoveOn(CSSemGetEvent(value1));
		}

		resultType = ILTypeGetParam(ILMethod_Signature(method), 1); 
		
		if(!ILTypeAssignCompatible(info->image, resultType, CSSemGetType(value2)))
		{
			if(yyisa(node, ILNode_Add))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					_("incompatible types in event addition: "
						"'%s' to '%s'"), 
					CSTypeToName(CSSemGetType(value2)), CSTypeToName(resultType));
			}
			else 
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					_("incompatible types in event removal: "
						"'%s' from '%s'"), 
					CSTypeToName(CSSemGetType(value2)), CSTypeToName(resultType));
			}
			return CSSemValueDefault;
		}

		/* Create the new node and replace "assignParent" with it */
		if(ILMethod_IsStatic(method))
		{
			*assignParent = ILNode_EventAddOrRemove_create
					(0, node->expr2, method);
			yysetfilename(*assignParent, yygetfilename(node));
			yysetlinenum(*assignParent, yygetlinenum(node));
		}
		else
		{
			*assignParent = ILNode_EventAddOrRemove_create
					(node->expr1, node->expr2, method);
			yysetfilename(*assignParent, yygetfilename(node));
			yysetlinenum(*assignParent, yygetlinenum(node));
		}

		/* When an event is used with assignment, the whole assignment
		   is treated as a statement rather than an expression */
		return CSSemValueDefault;
	}
	else if(!CSSemIsLValue(value1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid lvalue in assignment");
		if(!CSSemIsRValue(value1))
		{
			CSSemSetRValue(value1, ILType_Int32);
		}
		return value1;
	}

	/* The second argument must be a value */
	if(!CSSemIsValue(value2))
	{
		goto error;
	}

	/* Replace node->expr1 with an empty expression, so that it
	   doesn't double-evaluate during code generation */
	node->expr1 = ILNode_EmptyExpr_create
			(ILTypeToMachineType(CSSemGetType(value1)));

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, CSSemGetType(value1),
								CSSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value1, resultType);
		}
		else
		{
			CSSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		return value1;
	}

	/* Look for a user-specified operator */
	method = FindUserBinaryOperator(info, name, &(value1), node->expr1,
									&(value2), node->expr2);

	if(method)
	{
		ApplyUserBinaryOperator(info,method,(ILNode_BinaryExpression*)node,
								parent,&(value1),&(value2));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}

	/* Should we be performing string concatenation? */
	if(ILTypeIsStringClass(CSSemGetType(value1)) && yyisa(node, ILNode_Add))
	{
		if(!ILTypeIsStringClass(CSSemGetType(value2)))
		{
			/* Convert the second argument into "ObjectRef" */
			ILCast(info, node->expr2, &(node->expr2), CSSemGetType(value2),
				   ILFindSystemType(info, "Object"),1);
		}
		*parent = ILNode_Concat_create(node->expr1, node->expr2);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetRValue(value1, CSSemGetType(value1));
		return value1;
	}
	else if(ILTypeIsStringClass(CSSemGetType(value2)) && yyisa(node, ILNode_Add))
	{
		if(!ILTypeIsStringClass(CSSemGetType(value1)))
		{
			/* Convert the first argument into "ObjectRef" */
			/* Note: this will be an EmptyExpr , but will cast properly */
			ILCast(info, node->expr1, &(node->expr1), CSSemGetType(value1),
				   ILFindSystemType(info, "Object"),1);
		}
		*parent = ILNode_Concat_create(node->expr1, node->expr2);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetRValue(value1, CSSemGetType(value1));
		return value1;
	}

	/* Should we be performing delegate combination or removal? */
	if(ILTypeIsDelegate(CSSemGetType(value1)))
	{
		if(yyisa(node, ILNode_Add) &&
		   ILTypeIdentical(CSSemGetType(value1), CSSemGetType(value2)))
		{
			*parent = ILNode_DelegateAdd_create
				(node->expr1, node->expr2,
				 ILType_ToClass(CSSemGetType(value1)));
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, CSSemGetType(value1));
			return value1;
		}
		else if(yyisa(node, ILNode_Sub) &&
		        ILTypeIdentical(CSSemGetType(value1), CSSemGetType(value2)))
		{
			*parent = ILNode_DelegateSub_create
				(node->expr1, node->expr2,
				 ILType_ToClass(CSSemGetType(value1)));
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, CSSemGetType(value1));
			return value1;
		}
	}

	/* Try again, this time coercing value2's type to value1's type */
	if (ILCanCoerceNode(info, node->expr2, 
						CSSemGetType(value2), CSSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2),
						CSSemGetType(value2), CSSemGetType(value1),1);
		CSSemSetRValue(value2, CSSemGetType(value1));
		return value1;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `%s'", errorName);
	if(CSSemIsLValue(value1))
	{
		CSSemSetRValue(value1, CSSemGetType(value1));
	}
	else
	{
		CSSemSetRValue(value1, ILType_Int32);
	}
	return value1;
}

#line 1345 "cs_oper.tc"


/*
 * Perform semantic analysis for increment or decrement operators.
 */
static CSSemValue IncOrDecSem(ILGenInfo *info, ILNode_UnaryExpression *node,
							  ILNode **parent, const char *opName,
							  const char *errorName,
							  ILNode *(*createFunc)
							  		(ILNode *expr, ILMethod *method,
									 ILMachineType type),
							  ILNode *(*createPtrFunc)
							  		(ILNode *expr, ILUInt32 size,
									 ILNode *sizeNode))
{
	ILMethod *method;
	CSSemValue value;
	ILMachineType machineType;

	/* Perform semantic analysis on the argument, which must be an lvalue */
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));
	if(!CSSemIsLValue(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid lvalue in increment");
		if(!CSSemIsRValue(value))
		{
			CSSemSetRValue(value, ILType_Int32);
		}
		return value;
	}

	/* The final result will be an rvalue */
	CSSemSetRValue(value, CSSemGetType(value));

	/* Can we use the builtin version of the operator? */
	machineType = ILTypeToMachineType(CSSemGetType(value));
	switch(machineType)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		case ILMachineType_Float32:
		case ILMachineType_Float64:
		case ILMachineType_Decimal:
		{
			/* Semantic analysis is finished: the code generator
			   has enough information to do the rest */
			return value;
		}
		/* Not reached */

		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		case ILMachineType_UnmanagedPtr:
		{
			/* Check for pointer types */
			if(ILType_IsPointer(CSSemGetType(value)))
			{
				ILType *elemType =
					ILTypeStripPrefixes(ILType_Ref(CSSemGetType(value)));
				if(elemType != ILType_Void)
				{
					ILNode_SizeOf *sizeNode = (ILNode_SizeOf *)
						ILNode_SizeOf_create(0);
					sizeNode->type = elemType;
					sizeNode->size = GetPrimitiveTypeSize(elemType);
					*parent = (*createPtrFunc)
						(node->expr, GetPrimitiveTypeSize(elemType),
						 (ILNode *)sizeNode);
					return value;
				}
			}
		}
		break;

		default: break;
	}

	/* Look for an appropriate operator */
	method = FindUserUnaryOperator(info, opName, &(value), node->expr);
	if(!method)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operands to unary `%s'", errorName);
	}
	else
	{
		*parent = (*createFunc)(node->expr, method, machineType);
	}

	/* Done */
	return value;
}

#line 1920 "cs_oper.tc"


/*
 * Perform semantic analysis for the equality or inequality operators.
 */
static CSSemValue EqualitySem(ILGenInfo *info, ILNode_BinaryExpression *node,
							  ILNode **parent, const ILOperator *table,
							  const char *name, const char *errorName)
{
	const ILOperator *oper;
	ILMethod *method;
	CSSemValue value1;
	CSSemValue value2;
	ILType *resultType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));

	/* The two arguments must be values */
	if(!CSSemIsValue(value1) || !CSSemIsValue(value2))
	{
		goto error;
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, CSSemGetType(value1),
								CSSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		CSSemSetRValue(value1, ILType_Boolean);
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* If one of the arguments is a string and the other is null,
	   then the code generator knows how to handle the operation */
	if(ILTypeIsStringClass(CSSemGetType(value1)))
	{
		if(CSSemGetType(value2) == ILType_Null)
		{
			if(table == ILOp_Eq)
			{
				*parent = ILNode_IsNull_create(node->expr1);
			}
			else
			{
				*parent = ILNode_IsNonNull_create(node->expr1);
			}
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
	}
	else if(CSSemGetType(value1) == ILType_Null &&
			ILTypeIsStringClass(CSSemGetType(value2)))
	{
		if(table == ILOp_Eq)
		{
			*parent = ILNode_IsNull_create(node->expr2);
		}
		else
		{
			*parent = ILNode_IsNonNull_create(node->expr2);
		}
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetRValue(value1, ILType_Boolean);
		return value1;
	}

	/* If one of the arguments is a pointer and the other is null,
	   then the code generator knows how to handle the operation */
	if(ILType_IsPointer(CSSemGetType(value1)))
	{
		if(CSSemGetType(value2) == ILType_Null)
		{
			if(table == ILOp_Eq)
			{
				*parent = ILNode_IsNull_create(node->expr1);
			}
			else
			{
				*parent = ILNode_IsNonNull_create(node->expr1);
			}
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
	}
	else if(CSSemGetType(value1) == ILType_Null &&
			ILType_IsPointer(CSSemGetType(value2)))
	{
		if(table == ILOp_Eq)
		{
			*parent = ILNode_IsNull_create(node->expr2);
		}
		else
		{
			*parent = ILNode_IsNonNull_create(node->expr2);
		}
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetRValue(value1, ILType_Boolean);
		return value1;
	}

	/* If the two arguments are pointers, we can use the builtin logic */
	if(ILType_IsPointer(CSSemGetType(value1)) &&
	   ILType_IsPointer(CSSemGetType(value2)))
	{
		CSSemSetRValue(value1, ILType_Boolean);
		return value1;
	}

	/* If the two types are IntPtr, then we take a shortcut, avoiding
	   the call to the user-defined operators in "IntPtr" */
	if(CSSemGetType(value1) == ILType_Int &&
	   CSSemGetType(value2) == ILType_Int)
	{
		CSSemSetRValue(value1, ILType_Boolean);
		return value1;
	}

	/* Look for a user-specified operator */
	method = FindUserBinaryOperator(info, name, &(value1), node->expr1,
									&(value2), node->expr2);
	if(method)
	{
		ApplyUserBinaryOperator(info,method,(ILNode_BinaryExpression*)node,
								parent,&(value1),&(value2));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}

	/* If both arguments are object references, then we can compare them
	   using the built-in code generator logic */
	if(CSSemGetType(value1) != ILType_Null &&
	   ILTypeIsReference(CSSemGetType(value1)))
	{
		if(CSSemGetType(value2) == ILType_Null)
		{
			if(table == ILOp_Eq)
			{
				*parent = ILNode_IsNull_create(node->expr1);
			}
			else
			{
				*parent = ILNode_IsNonNull_create(node->expr1);
			}
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
		else if(ILTypeIsReference(CSSemGetType(value2)))
		{
			if(ILCanCoerceNode(info, node->expr1, CSSemGetType(value1),
							   CSSemGetType(value2),1) ||
			   ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
			   				   CSSemGetType(value1),1))
			{
				CSSemSetRValue(value1, ILType_Boolean);
				return value1;
			}
		}
	}
	else if(CSSemGetType(value1) == ILType_Null &&
			ILTypeIsReference(CSSemGetType(value2)))
	{
		if(table == ILOp_Eq)
		{
			*parent = ILNode_IsNull_create(node->expr2);
		}
		else
		{
			*parent = ILNode_IsNonNull_create(node->expr2);
		}
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetRValue(value1, ILType_Boolean);
		return value1;
	}

	/* Try coercion as a last resort */
	if(ILCanCoerceNode(info, node->expr1, CSSemGetType(value1),
					   CSSemGetType(value2),1))
	{
		ILCoerce(info, node->expr1, &(node->expr1), CSSemGetType(value1),
				 CSSemGetType(value2),1);
		CSSemSetRValue(value1, CSSemGetType(value2));
	}
	else if(ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
					   CSSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), CSSemGetType(value2),
				 CSSemGetType(value1),1);
		CSSemSetRValue(value2, CSSemGetType(value1) );
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, CSSemGetType(value1),
								CSSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		CSSemSetRValue(value1, ILType_Boolean);
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}
	
	/* Look for a user-specified operator */
	method = FindUserBinaryOperator(info, name, &(value1), node->expr1,
									&(value2), node->expr2);
	if(method)
	{
		ApplyUserBinaryOperator(info,method,(ILNode_BinaryExpression*)node,
								parent,&(value1),&(value2));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `%s'", errorName);
	CSSemSetRValue(value1, ILType_Int32);
	return value1;
}

#line 21 "cs_stmt.tc"


/*
 * Determine if a tree node corresponds to the empty statement.
 */
#define	IsEmpty(node) ((node) == 0 || yykind((node)) == yykindof(ILNode_Empty))

/*
 * determine if a type1 implements type2
 */
static int ILTypeImplements(ILGenInfo *info, ILType *type1, ILType *type2)
{
	ILClass *classInfo1 = ILTypeToClass(info, type1);
	ILClass *classInfo2 = ILTypeToClass(info, type2);
	if(classInfo1 && classInfo2)
	{
		return ILClassImplements(classInfo1, classInfo2);
	}
	else
	{
		return 0;
	}
}
/*
 * determine if a type1 inherits type2
 */
static int ILTypeInherits(ILGenInfo *info, ILType *type1, ILType *type2)
{
	ILClass *classInfo1 = ILTypeToClass(info, type1);
	ILClass *classInfo2 = ILTypeToClass(info, type2);
	if(classInfo1 && classInfo2)
	{
		return ILClassInheritsFrom(classInfo1, classInfo2);
	}
	else
	{
		return 0;
	}
}

/*
 * Obtain the default scope of the class
 */
#define GetDefaultScope(info)	(((ILNode_ClassDefn*)(info->currentClass))->classInfo)

/*
 * Perform semantic analysis on a sub-statement.
 */
static void StmtSem(ILNode *node, ILGenInfo *info, ILNode **parent)
{
	CSSemValue value;
	if(node)
	{
		value = ILNode_SemAnalysis(node, info, parent);
		if(!CSSemIsVoid(value) && !CSSemIsValue(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid statement");
		}
	}
}

/*
 * Statement context flags.
 */
#define	CS_STMT_LOOP		1
#define	CS_STMT_SWITCH		2
#define	CS_STMT_TRY			4
#define	CS_STMT_CATCH		8
#define	CS_STMT_FINALLY		16

/*
 * Push a statement context.
 */
static void PushStmtContext(ILGenInfo *info, int context)
{
	if(info->contextStackSize >= info->contextStackMax)
	{
		/* Increase the size of the context stack */
		int *newstack;
		newstack = (int *)ILRealloc(info->contextStack,
									sizeof(int) * (info->contextStackMax + 4));
		if(!newstack)
		{
			ILGenOutOfMemory(info);
		}
		info->contextStack = newstack;
		info->contextStackMax += 4;
	}
	info->contextStack[info->contextStackSize] = context;
	++(info->contextStackSize);
}

/*
 * Pop the top-most statement context.
 */
static void PopStmtContext(ILGenInfo *info)
{
	--(info->contextStackSize);
}

/*
 * Determine if we are within a specific context, but not
 * within a "stop" context.  e.g. "break" can be used
 * within a loop, but not in the body of a "finally"
 * within the loop.  "finally" is the "stop" context.
 */
static int StmtContextOK(ILGenInfo *info, int context, int stopContext)
{
	long posn = info->contextStackSize;
	while(posn > 0)
	{
		--posn;
		if((info->contextStack[posn] & stopContext) != 0)
		{
			return 0;
		}
		if((info->contextStack[posn] & context) != 0)
		{
			return 1;
		}
	}
	if(!context)
	{
		/* We are checking a "return" statement */
		return 1;
	}
	else
	{
		/* We are checking some other kind of statement */
		return 0;
	}
}

#line 497 "cs_stmt.tc"


/*
 * Count the number of case labels in the body of a "switch" statement,
 * and find the default case.
 */
static unsigned long CountLabelsAndFindDefault(ILNode *sections,
											   ILNode **defCase)
{
	ILNode_ListIter iter1;
	ILNode_ListIter iter2;
	ILNode *section;
	ILNode *caseNode;
	unsigned long count;
	ILNode *prevDefLabel;

	/* Initialize the return information */
	count = 0;
	*defCase = 0;
	prevDefLabel = 0;

	/* Iterate through the sections */
	ILNode_ListIter_Init(&iter1, sections);
	while((section = ILNode_ListIter_Next(&iter1)) != 0)
	{
		/* Iterate through the case list for each section */
		ILNode_ListIter_Init
			(&iter2, ((ILNode_SwitchSection *)section)->caseList);
		while((caseNode = ILNode_ListIter_Next(&iter2)) != 0)
		{
			if(yyisa(caseNode, ILNode_DefaultLabel))
			{
				/* This is the switch's default label */
				if(prevDefLabel)
				{
					CCErrorOnLine(yygetfilename(caseNode),
						  yygetlinenum(caseNode),
						  "multiple `default' labels in `switch' statement");
					CCErrorOnLine(yygetfilename(prevDefLabel),
						  yygetlinenum(prevDefLabel),
						  "previous `default' label here");
				}
				else
				{
					*defCase = section;
					prevDefLabel = caseNode;
				}
			}
			else
			{
				/* This is a particular case label */
				++count;
			}
		}
	}

	/* Return the count to the caller */
	return count;
}

/*
 * Compare two case label values within "ILSwitchValue" objects.
 */
static int CompareCaseLabels(const void *e1, const void *e2)
{
	const ILEvalValue *value1 = &(((const ILSwitchValue *)e1)->value);
	const ILEvalValue *value2 = &(((const ILSwitchValue *)e2)->value);

	switch(value1->valueType)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		{
			if(value1->un.i4Value < value2->un.i4Value)
			{
				return -1;
			}
			else if(value1->un.i4Value > value2->un.i4Value)
			{
				return 1;
			}
		}
		break;

		case ILMachineType_UInt32:
		{
			if(((ILUInt32)(value1->un.i4Value)) <
					((ILUInt32)(value2->un.i4Value)))
			{
				return -1;
			}
			else if(((ILUInt32)(value1->un.i4Value)) >
					((ILUInt32)(value2->un.i4Value)))
			{
				return 1;
			}
		}
		break;

		case ILMachineType_Int64:
		{
			if(value1->un.i8Value < value2->un.i8Value)
			{
				return -1;
			}
			else if(value1->un.i8Value > value2->un.i8Value)
			{
				return 1;
			}
		}
		break;

		case ILMachineType_UInt64:
		{
			if(((ILUInt64)(value1->un.i8Value)) <
					((ILUInt64)(value2->un.i8Value)))
			{
				return -1;
			}
			else if(((ILUInt64)(value1->un.i8Value)) >
					((ILUInt64)(value2->un.i8Value)))
			{
				return 1;
			}
		}
		break;

		case ILMachineType_String:
		{
			const char *str1 = value1->un.strValue.str;
			const char *str2 = value2->un.strValue.str;
			int len1 = value1->un.strValue.len;
			int len2 = value2->un.strValue.len;
			unsigned char ch1;
			unsigned char ch2;
			if(!str1)
			{
				/* The first value is "null" */
				return (str2 ? -1 : 0);
			}
			else if(!str2)
			{
				/* The second value is "null" */
				return 1;
			}
			while(len1 > 0 && len2 > 0)
			{
				ch1 = (unsigned char)(*str1++);
				ch2 = (unsigned char)(*str2++);
				if(ch1 < ch2)
				{
					return -1;
				}
				else if(ch1 > ch2)
				{
					return 1;
				}
				--len1;
				--len2;
			}
			if(len1 > 0)
			{
				return 1;
			}
			else if(len2 > 0)
			{
				return -1;
			}
		}
		break;

		default: break;
	}
	return 0;
}

/*
 * Collect up all of the case labels for a "switch" statement,
 * and sort them into ascending order.  This also performs
 * semantic analysis on each of the sections.  Returns the new
 * size of the case label list, after errors have been removed.
 */
static unsigned long CollectCaseLabels(ILGenInfo *info, ILNode *sections,
							  		   ILType *switchType,
									   ILSwitchValue *values)
{
	ILNode_ListIter iter1;
	ILNode_ListIter iter2;
	ILNode *section;
	ILNode *caseNode;
	ILNode_CaseLabel *caseLabel;
	unsigned long size;
	unsigned long posn;
	CSSemValue value;
	ILEvalValue evalValue;
	ILMachineType switchMachineType;

	/* Initialize */
	size = 0;
	switchMachineType = ILTypeToMachineType(switchType);

	/* Iterate through the sections */
	ILNode_ListIter_Init(&iter1, sections);
	while((section = ILNode_ListIter_Next(&iter1)) != 0)
	{
		/* Iterate through the case list for each section */
		ILNode_ListIter_Init
			(&iter2, ((ILNode_SwitchSection *)section)->caseList);
		while((caseNode = ILNode_ListIter_Next(&iter2)) != 0)
		{
			if(yyisa(caseNode, ILNode_CaseLabel))
			{
				/* Perform semantic analysis on the case expression */
				caseLabel = (ILNode_CaseLabel *)caseNode;
				if(!CSSemExpectValue(caseLabel->expr, info,
									 &(caseLabel->expr), &value))
				{
					CCErrorOnLine(yygetfilename(caseLabel->expr),
								  yygetlinenum(caseLabel->expr),
								  "invalid case label expression");
					continue;
				}

				/* Coerce the case expression to the governing type */
				if(!ILCoerce(info, caseLabel->expr, &(caseLabel->expr),
							 CSSemGetType(value), switchType,1))
				{
					CCErrorOnLine(yygetfilename(caseLabel->expr),
								  yygetlinenum(caseLabel->expr),
								  "no conversion from `%s' to `%s'",
								  CSTypeToName(CSSemGetType(value)),
								  CSTypeToName(switchType));
					continue;
				}

				/* Evaluate the constant value for the case expression */
				if(!ILNode_EvalConst(caseLabel->expr, info, &evalValue) ||
				   !ILGenCastConst(info, &evalValue, evalValue.valueType,
				   				   switchMachineType))
				{
					CCErrorOnLine(yygetfilename(caseLabel->expr),
								  yygetlinenum(caseLabel->expr),
								  "case expression is not constant");
					continue;
				}

				/* Record the case node information for later */
				values[size].value = evalValue;
				values[size].caseLabel = caseNode;
				values[size].section = section;
				++size;
			}
		}

	}
	/* split into 2 passes to facilitate goto case 
	 * So SemAnalysis is performed after all the CaseLabels are
	 * collected.
	 */
	/* Iterate through the sections again */
	ILNode_ListIter_Init(&iter1, sections);
	while((section = ILNode_ListIter_Next(&iter1)) != 0)
	{
		((ILNode_SwitchSection*)section)->visited=ILVisitMode_Processing;
		/* Perform semantic analysis on the section's body */
		ILNode_SemAnalysis(((ILNode_SwitchSection *)section)->stmt, info,
						   &(((ILNode_SwitchSection *)section)->stmt));
		((ILNode_SwitchSection*)section)->visited=ILVisitMode_Done;
		/* The body must end in some kind of return or jump statement */
		if(!ILNodeEndsInFlowChange(((ILNode_SwitchSection *)section)->stmt
									,info))
		{
			CCErrorOnLine(yygetfilename(section), yygetlinenum(section),
						  "`switch' section falls through");
		}
	}


	/* Sort the case label list into ascending order */
	if(size > 1)
	{
	#ifdef HAVE_QSORT
		qsort(values, (size_t)size, sizeof(ILSwitchValue), CompareCaseLabels);
	#else
		unsigned long i;
		unsigned long j;
		ILSwitchValue temp;
		for(i = 0; i < size - 1; ++i)
		{
			for(j = i + 1; j < size; ++j)
			{
				if(CompareCaseLabels(&(values[i]), &(values[j])) > 0)
				{
					temp = values[i];
					values[i] = values[j];
					values[j] = temp;
				}
			}
		}
	#endif
	}

	/* Check for duplicates in the case label list */
	if(size > 1)
	{
		for(posn = 0; posn < size - 1; ++posn)
		{
			if(CompareCaseLabels(&(values[posn]), &(values[posn + 1])) == 0)
			{
				CCErrorOnLine(yygetfilename(values[posn + 1].caseLabel),
				              yygetlinenum(values[posn + 1].caseLabel),
							  "duplicate case expression");
				CCErrorOnLine(yygetfilename(values[posn].caseLabel),
				              yygetlinenum(values[posn].caseLabel),
							  "previous definition here");
			}
		}
	}

	/* Return the final table size to the caller */
	return size;
}

/*
 * Determine the type of table to be used for a set of switch cases.
 */
static ILSwitchTableType SwitchTableType(ILType *switchType,
										 ILSwitchValue *values,
										 unsigned long numValues)
{
	ILMachineType type;
	unsigned long range;

	/* Use simple "if" statements for 4 or less cases */
	if(numValues <= 4)
	{
		return ILSwitchTableType_If;
	}

	/* If the switch type can fit in a 32-bit integer, and the
	   cases fill up at least 80% of the range, then use an
	   indexed table for the switch. But the calculation is prone 
	   to overflow, hence the upper limit check. */
	type = ILTypeToMachineType(switchType);
	switch(type)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		{
			range = (unsigned long)(values[numValues - 1].value.un.i4Value -
									values[0].value.un.i4Value);
			if(((range * 4) / 5) <= numValues && range < 0x1fffffff)
			{
				return ILSwitchTableType_Indexed;
			}
			else
			{
				return ILSwitchTableType_Lookup;
			}
		}
		/* Not reached */

		case ILMachineType_UInt32:
		{
			range = (unsigned long)
				(((ILUInt32)(values[numValues - 1].value.un.i4Value)) -
				 ((ILUInt32)(values[0].value.un.i4Value)));
			if(((range * 4) / 5) <= numValues && range < 0x3fffffff)
			{
				return ILSwitchTableType_Indexed;
			}
			else
			{
				return ILSwitchTableType_Lookup;
			}
		}
		/* Not reached */

		default: break;
	}

	/* If we get here, then we need to use a binary tree of if statements */
	return ILSwitchTableType_BinaryIf;
}

#line 170 "cs_types.tc"


/*
 * Get the number of suffixes in a local variable type suffix list.
 */
static ILUInt32 SuffixListLen(ILNode *list)
{
	ILNode_ListIter iter;
	ILUInt32 count = 0;
	ILNode_ListIter_Init(&iter, list);
	while(ILNode_ListIter_Next(&iter))
	{
		++count;
	}
	return count;
}

/*
 * Get a particular suffix value from a local variable type suffix list.
 */
static ILUInt32 SuffixListValue(ILNode *list, ILUInt32 elemNum)
{
	ILNode_ListIter iter;
	ILNode *child;
	ILUInt32 count = 0;
	ILNode_ListIter_Init(&iter, list);
	while((child = ILNode_ListIter_Next(&iter)) != 0)
	{
		if(count == elemNum)
		{
			return ((ILNode_TypeSuffix *)child)->count;
		}
		++count;
	}
	return 0;
}

#line 313 "cs_types.tc"


/*
 * Perform semantic analysis on a set of type actuals
 * and add them to a "with" type.
 */
static void SemWithType(ILGenInfo *info, ILType *withType,
					    ILNode *actuals, ILNode **parent)
{
	CSSemValue value;
	if(yyisa(actuals, ILNode_TypeActuals))
	{
		SemWithType(info, withType, ((ILNode_TypeActuals *)actuals)->left,
					&(((ILNode_TypeActuals *)actuals)->left));
		SemWithType(info, withType, ((ILNode_TypeActuals *)actuals)->right,
					&(((ILNode_TypeActuals *)actuals)->right));
	}
	else
	{
		value = ILNode_SemAnalysisType(actuals, info, parent);
		if(!CSSemIsType(value))
		{
			CCErrorOnLine(yygetfilename(actuals), yygetlinenum(actuals),
					      "type name expected in generic type parameter");
			CSSemSetType(value, ILType_Int32);
		}
		if(!ILTypeAddWithParam(info->context, withType, CSSemGetType(value)))
		{
			CCOutOfMemory();
		}
	}
}

#line 4235 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_1__(ILNode_DummySem *node, ILGenInfo * info, ILNode * * parent)
#line 46 "cs_semantics.tc"
{
	return CSSemValueDefault;
}
#line 4242 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_2__(ILNode_ArrayType *node, ILGenInfo * info, ILNode * * parent)
#line 72 "cs_types.tc"
{
	CSSemValue value;
	ILNode *elemType;
	ILNode **elemTypeParent;
	ILType *arrayType;
	ILType *type;

	/* Find the element type at the end of the rank specifiers */
	elemType = node->type;
	elemTypeParent = &(node->type);
	while(yykind(elemType) == yykindof(ILNode_ArrayType))
	{
		elemTypeParent = &(((ILNode_ArrayType *)elemType)->type);
		elemType = ((ILNode_ArrayType *)elemType)->type;
	}

	/* Perform semantic analysis on the element type */
	type = CSSemTypeLiteral(elemType, info, elemTypeParent);

	/* Create the array type from the outermost rank inwards */
	arrayType = ILTypeCreateArray(info->context, node->numDimensions, type);
	if(!arrayType)
	{
		CCOutOfMemory();
	}
	elemType = node->type;
	while(yykind(elemType) == yykindof(ILNode_ArrayType))
	{
		arrayType = ILTypeCreateArray
			(info->context, ((ILNode_ArrayType *)elemType)->numDimensions,
			 arrayType);
		if(!arrayType)
		{
			CCOutOfMemory();
		}
		elemType = ((ILNode_ArrayType *)elemType)->type;
	}

	/* Return the final array type */
	CSSemSetType(value, arrayType);
	return value;
}
#line 4288 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_3__(ILNode_PtrType *node, ILGenInfo * info, ILNode * * parent)
#line 119 "cs_types.tc"
{
	CSSemValue value;

	/* Perform semantic analysis on the element type */
	value = ILNode_SemAnalysis(node->type, info, &(node->type));
	if(!CSSemIsType(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid pointer element type");
		CSSemSetType(value, ILType_Int32);
	}

	/* Create the pointer type */
	CSSemSetType(value, ILTypeCreateRef(info->context, IL_TYPE_COMPLEX_PTR,
								 		CSSemGetType(value)));
	if(!(CSSemGetType(value)))
	{
		CCOutOfMemory();
	}
	return value;
}
#line 4313 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_4__(ILNode_PrimitiveType *node, ILGenInfo * info, ILNode * * parent)
#line 145 "cs_types.tc"
{
	CSSemValue value;
	CSSemSetType(value, ILType_FromElement(node->elementType));
	return value;
}
#line 4322 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_5__(ILNode_SystemType *node, ILGenInfo * info, ILNode * * parent)
#line 155 "cs_types.tc"
{
	CSSemValue value;
	CSSemSetType(value, ILFindSystemType(info, node->className));
	if(!(CSSemGetType(value)))
	{
		value=ILNode_SemAnalysis(
				ILQualIdentTwo("System",node->className),info,parent);
	}
	if(!(CSSemGetType(value)))
	{
		CCOutOfMemory();
	}
	return value;
}
#line 4340 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_6__(ILNode_TypeSuffix *node, ILGenInfo * info, ILNode * * parent)
#line 298 "cs_types.tc"
{
	/* This is never actually called, so do nothing */
	return CSSemValueDefault;
}
#line 4348 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_7__(ILNode_LocalVariableType *node, ILGenInfo * info, ILNode * * parent)
#line 216 "cs_types.tc"
{
	CSSemValue value;
	ILUInt32 len;
	ILUInt32 posn;
	ILUInt32 count;
	ILUInt32 numRanks;
	ILUInt32 tempRank;
	ILType *type;

	/* Perform semantic analysis on the element type */
	type = CSSemTypeVoid(node->type, info, &(node->type));

	/* If the element type is "void", then the first suffix
	   must indicate a pointer type */
	len = SuffixListLen(node->suffixes);
	if(type == ILType_Void)
	{
		if(!len || SuffixListValue(node->suffixes, 0) != 0)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`void' not permitted as a local variable type");
			CSSemSetType(value, ILType_Int32);
			return value;
		}
	}

	/* Add the suffixes to the type */
	posn = 0;
	while(posn < len)
	{
		count = SuffixListValue(node->suffixes, posn);
		if(count != 0 && (posn + 1) == len)
		{
			/* Special case: single rank specifier */
			type = ILTypeCreateArray(info->context, count, type);
			if(!type)
			{
				CCOutOfMemory();
			}
			++posn;
		}
		else if(count != 0)
		{
			/* Construct an array type from a group of rank specifiers */
			numRanks = 1;
			while((posn + numRanks) < len &&
		       (count = SuffixListValue(node->suffixes, posn + numRanks)) != 0)
			{
				++numRanks;
			}
			tempRank = numRanks;
			while(tempRank > 0)
			{
				--tempRank;
				count = SuffixListValue(node->suffixes, posn + tempRank);
				type = ILTypeCreateArray(info->context, count, type);
				if(!type)
				{
					CCOutOfMemory();
				}
			}
			posn += numRanks;
		}
		else
		{
			/* Construct a pointer type */
			type = ILTypeCreateRef(info->context, IL_TYPE_COMPLEX_PTR, type);
			if(!type)
			{
				CCOutOfMemory();
			}
			++posn;
		}
	}
	CSSemSetType(value, type);
	return value;
}
#line 4429 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_8__(ILNode_TypeActuals *node, ILGenInfo * info, ILNode * * parent)
#line 308 "cs_types.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 4437 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_9__(ILNode_GenericReference *node, ILGenInfo * info, ILNode * * parent)
#line 352 "cs_types.tc"
{
	CSSemValue value;
	ILClass *classInfo;
	ILUInt32 numFormals;
	ILUInt32 numActuals;
	ILNode *actuals;
	ILType *withType;

	/* Perform semantic analysis on the main part of the type */
	value = ILNode_SemAnalysisType(node->type, info, &(node->type));
	if(!CSSemIsType(value))
	{
		CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
					  "type name expected in generic type reference");
		return value;
	}

	/* Find the number of generic parameters that we expect */
	classInfo = ILClassResolve(ILTypeToClass(info, CSSemGetType(value)));
	numFormals = ILGenericParGetNumParams(ILToProgramItem(classInfo));

	/* Count the number of actual parameters that we were given */
	numActuals = 1;
	actuals = node->actuals;
	while(yyisa(actuals, ILNode_TypeActuals))
	{
		++numActuals;
		actuals = ((ILNode_TypeActuals *)actuals)->left;
	}

	/* Check the counts for consistency */
	if(numFormals != numActuals)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "incorrect number of generic parameters supplied to "
					  "`%s'; was %d but should be %d",
					  CSTypeToName(CSSemGetType(value)),
					  (int)numActuals, (int)numFormals);
	}

	/* Build the "with" type and return it */
	withType = ILTypeCreateWith(info->context, CSSemGetType(value));
	if(!withType)
	{
		CCOutOfMemory();
	}
	SemWithType(info, withType, node->actuals, &(node->actuals));
	CSSemSetType(value, withType);
	return value;
}
#line 4491 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_10__(ILNode_FixAddress *node, ILGenInfo * info, ILNode * * parent)
#line 1752 "cs_stmt.tc"
{
	*parent=ILNode_Assign_create(node->name,node->address);
	yysetfilename(*parent, yygetfilename(node));
	yysetlinenum(*parent, yygetlinenum(node));
	ILNode_SemAnalysis(*parent,info,parent);
	return CSSemValueDefault;
}
#line 4502 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_11__(ILNode_FixExpr *node, ILGenInfo * info, ILNode * * parent)
#line 1764 "cs_stmt.tc"
{
	CSSemValue value;
	ILNode *expr;
	
	/* Perform semantic analysis on the expression */
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));

	/* Wrap the expression to prevent double evaluation */
	expr = ILNode_SemGuard_create(node->expr, value);
	yysetfilename(expr, yygetfilename(node->expr));
	yysetlinenum(expr, yygetlinenum(node->expr));

	/* If the expression is an array, then turn it into a pointer */
	if(CSSemIsValue(value) && ILType_IsSimpleArray(CSSemGetType(value)))
	{
		expr = ILNode_ArrayAccess_create(expr, ILNode_Int32_create(0, 0, 1));
		yysetfilename(expr, yygetfilename(node->expr));
		yysetlinenum(expr, yygetlinenum(node->expr));
		expr = ILNode_AddressOf_create(expr);
		yysetfilename(expr, yygetfilename(node->expr));
		yysetlinenum(expr, yygetlinenum(node->expr));
	}

	/* Assign the value to the variable */
	*parent = ILNode_Assign_create(node->name, expr);
	yysetfilename(*parent, yygetfilename(node));
	yysetlinenum(*parent, yygetlinenum(node));

	/* Perform semantic analysis on the assignment */
	ILNode_SemAnalysis(*parent, info, parent);
	return CSSemValueDefault;
}
#line 4538 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_12__(ILNode_ResourceDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 1979 "cs_stmt.tc"
{
	ILType *type;
	ILNode_ListIter iter;
	ILNode *nameNode;
	char *name;
	ILScopeData *data;
	ILNode_MethodDeclaration *method;
	ILNode *errorNode;
	ILType *disposableType;
	/* Locate the method that this local is declared within */
	method = (ILNode_MethodDeclaration *)(info->currentMethod);

	/* Perform semantic analysis on the local variable type */
	type = CSSemType(node->type, info, &(node->type));

	disposableType=ILFindSystemType(info,"IDisposable");
	if(! ILTypeImplements(info,type,disposableType) 
		&& !ILTypeInherits(info,type,disposableType))
	{
		CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  "`%s' does not implement 'IDisposable' interface ", 
			  CSTypeToName(type));
	}

	/* Scan through the variable names and declare them in the current scope */
	ILNode_ListIter_Init(&iter, node->variables);
	while((nameNode = ILNode_ListIter_Next(&iter)) != 0)
	{
		name = ILQualIdentName(nameNode, 0);
		data = ILScopeLookup(info->currentScope, name, 0);
		if(data)
		{
			/* The name is already declared in this scope */
			CCErrorOnLine(yygetfilename(nameNode), yygetlinenum(nameNode),
						  "`%s' is already declared in this scope", name);
			errorNode = ILScopeDataGetNode(data);
			if(errorNode)
			{
				CCErrorOnLine(yygetfilename(errorNode), yygetlinenum(errorNode),
							  "previous declaration here");
			}
		}
		else
		{
			/* Add the type to the local variable signature for this method */
			if(!(method->localVarSig))
			{
				method->localVarSig = ILTypeCreateLocalList(info->context);
				if(!(method->localVarSig))
				{
					CCOutOfMemory();
				}
			}
			if(!ILTypeAddLocal(info->context, method->localVarSig, type))
			{
				CCOutOfMemory();
			}

			/* Create a local variable entry in the current scope */
			ILScopeDeclareLocal(info->currentScope, name,
								ILTypeNumLocals(method->localVarSig) - 1,
								nameNode);

			/* replace the name with the local variable */
			*(iter.last) = ILNode_LocalVar_create(
							ILTypeNumLocals(method->localVarSig)-1,
							ILTypeToMachineType(type));
		}
	}

	ILNode_SemAnalysis(node->init,info, &(node->init));

	/* Return the default value to the caller */
	return CSSemValueDefault;
}
#line 4617 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_13__(ILNode_BaseDestructor *node, ILGenInfo * info, ILNode * * parent)
#line 650 "cs_misc.tc"
{
	ILNode_MethodDeclaration *caller;
	ILType *type;
	
	caller= (ILNode_MethodDeclaration *)(info->currentMethod);

	if(!caller)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "cannot call base destructors outside a method ");
		return CSSemValueDefault;
	}
	
	type = ILType_FromClass(ILMethod_Owner(caller->methodInfo));
	if(ILTypeIsObjectClass(type))
	{
		return CSSemValueDefault;
	}
	return ILNode_SemAnalysis(node->destructor,info,&(node->destructor));
}
#line 4641 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_14__(ILNode_DocComment *node, ILGenInfo * info, ILNode * * parent)
#line 1403 "cs_decls.tc"
{
	/* Nothing to do here */
	return CSSemValueDefault;
}
#line 4649 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_15__(ILNode_StandaloneAttr *node, ILGenInfo * info, ILNode * * parent)
#line 1409 "cs_decls.tc"
{
	ILProgramItem *item;
	ILNode *savedClass;
	ILNode *savedNamespace;
	ILNode *savedMethod;

	/* Save the current context and enter the attribute's namespace */
	savedClass = info->currentClass;
	savedNamespace = info->currentNamespace;
	savedMethod = info->currentMethod;
	info->currentClass = 0;
	info->currentNamespace = node->namespaceNode;
	info->currentMethod = 0;

	/* Perform semantic analysis on the attribute, relative to an assembly */
	item = (ILProgramItem *)ILAssembly_FromToken
				(CCCodeGen.image, IL_META_TOKEN_ASSEMBLY | 1);
	CSProcessAttrs(info, item, node->attributes, CS_ATTR_ASSEMBLY);

	/* Restore the previous context */
	info->currentClass = savedClass;
	info->currentNamespace = savedNamespace;
	info->currentMethod = savedMethod;
	return CSSemValueDefault;
}
#line 4678 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_16__(ILNode_Null *node, ILGenInfo * info, ILNode * * parent)
#line 25 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_ObjectRef;
	evalValue.un.oValue = 0;
	CSSemSetConstant(value, ILType_Null, evalValue);
	return value;
}
#line 4690 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_17__(ILNode_NullPtr *node, ILGenInfo * info, ILNode * * parent)
#line 38 "cs_const.tc"
{
	/* Will never be encountered in C# code, so do the same as "null" */
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_ObjectRef;
	evalValue.un.oValue = 0;
	CSSemSetConstant(value, ILType_Null, evalValue);
	return value;
}
#line 4703 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_18__(ILNode_True *node, ILGenInfo * info, ILNode * * parent)
#line 52 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Boolean;
	evalValue.un.i4Value = 1;
	CSSemSetConstant(value, ILType_Boolean, evalValue);
	return value;
}
#line 4715 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_19__(ILNode_False *node, ILGenInfo * info, ILNode * * parent)
#line 65 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Boolean;
	evalValue.un.i4Value = 0;
	CSSemSetConstant(value, ILType_Boolean, evalValue);
	return value;
}
#line 4727 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_20__(ILNode_Int8 *node, ILGenInfo * info, ILNode * * parent)
#line 78 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Int8;
	if(node->isneg)
	{
		evalValue.un.i4Value = -((ILInt32)(node->value));
	}
	else
	{
		evalValue.un.i4Value = (ILInt32)(node->value);
	}
	CSSemSetConstant(value, ILType_Int8, evalValue);
	return value;
}
#line 4746 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_21__(ILNode_UInt8 *node, ILGenInfo * info, ILNode * * parent)
#line 94 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt8;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSSemSetConstant(value, ILType_UInt8, evalValue);
	return value;
}
#line 4758 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_22__(ILNode_Int16 *node, ILGenInfo * info, ILNode * * parent)
#line 103 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Int16;
	if(node->isneg)
	{
		evalValue.un.i4Value = -((ILInt32)(node->value));
	}
	else
	{
		evalValue.un.i4Value = (ILInt32)(node->value);
	}
	CSSemSetConstant(value, ILType_Int16, evalValue);
	return value;
}
#line 4777 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_23__(ILNode_UInt16 *node, ILGenInfo * info, ILNode * * parent)
#line 119 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt16;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSSemSetConstant(value, ILType_UInt16, evalValue);
	return value;
}
#line 4789 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_24__(ILNode_Char *node, ILGenInfo * info, ILNode * * parent)
#line 128 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Char;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSSemSetConstant(value, ILType_Char, evalValue);
	return value;
}
#line 4801 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_25__(ILNode_Int32 *node, ILGenInfo * info, ILNode * * parent)
#line 137 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Int32;
	if(node->isneg)
	{
		evalValue.un.i4Value = -((ILInt32)(node->value));
	}
	else
	{
		evalValue.un.i4Value = (ILInt32)(node->value);
	}
	CSSemSetConstant(value, ILType_Int32, evalValue);
	return value;
}
#line 4820 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_26__(ILNode_UInt32 *node, ILGenInfo * info, ILNode * * parent)
#line 153 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt32;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSSemSetConstant(value, ILType_UInt32, evalValue);
	return value;
}
#line 4832 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_27__(ILNode_Int64 *node, ILGenInfo * info, ILNode * * parent)
#line 192 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Int64;
	if(node->isneg)
	{
		evalValue.un.i8Value = -((ILInt64)(node->value));
	}
	else
	{
		evalValue.un.i8Value = (ILInt64)(node->value);
	}
	CSSemSetConstant(value, ILType_Int64, evalValue);
	return value;
}
#line 4851 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_28__(ILNode_UInt64 *node, ILGenInfo * info, ILNode * * parent)
#line 208 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt64;
	evalValue.un.i8Value = (ILInt64)(node->value);
	CSSemSetConstant(value, ILType_UInt64, evalValue);
	return value;
}
#line 4863 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_29__(ILNode_Int *node, ILGenInfo * info, ILNode * * parent)
#line 162 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	ILNode_EvalConst(node, info, &evalValue);
	if(evalValue.valueType == ILMachineType_Int64)
	{
		CSSemSetConstant(value, ILType_Int64, evalValue);
	}
	else
	{
		CSSemSetConstant(value, ILType_Int, evalValue);
	}
	return value;
}
#line 4881 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_30__(ILNode_UInt *node, ILGenInfo * info, ILNode * * parent)
#line 177 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	ILNode_EvalConst(node, info, &evalValue);
	if(evalValue.valueType == ILMachineType_UInt64)
	{
		CSSemSetConstant(value, ILType_UInt64, evalValue);
	}
	else
	{
		CSSemSetConstant(value, ILType_UInt, evalValue);
	}
	return value;
}
#line 4899 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_31__(ILNode_Float32 *node, ILGenInfo * info, ILNode * * parent)
#line 221 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Float32;
	evalValue.un.r4Value = (ILFloat)(node->value);
	CSSemSetConstant(value, ILType_Float32, evalValue);
	return value;
}
#line 4911 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_32__(ILNode_Float64 *node, ILGenInfo * info, ILNode * * parent)
#line 230 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Float64;
	evalValue.un.r8Value = node->value;
	CSSemSetConstant(value, ILType_Float64, evalValue);
	return value;
}
#line 4923 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_33__(ILNode_Float *node, ILGenInfo * info, ILNode * * parent)
#line 239 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_NativeFloat;
	evalValue.un.r8Value = node->value;
	CSSemSetConstant(value, ILType_Float, evalValue);
	return value;
}
#line 4935 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_34__(ILNode_Decimal *node, ILGenInfo * info, ILNode * * parent)
#line 252 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_ManagedValue;
	evalValue.un.decValue = node->value;
	CSSemSetConstant(value, ILFindSystemType(info, "Decimal"), evalValue);
	return value;
}
#line 4947 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_35__(ILNode_String *node, ILGenInfo * info, ILNode * * parent)
#line 265 "cs_const.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_String;
	evalValue.un.strValue.str = node->str;
	evalValue.un.strValue.len = node->len;
	CSSemSetConstant(value, ILFindSystemType(info, "String"), evalValue);
	return value;
}
#line 4960 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_36__(ILNode_Deref *node, ILGenInfo * info, ILNode * * parent)
#line 2217 "cs_oper.tc"
{
	CSSemValue value;
	ILType *type;
	CCUnsafeMessage(info, (ILNode *)node, "unsafe pointer dereference");
	value=ILNode_SemAnalysis(node->expr,info,&(node->expr));
	if(!CSSemIsValue(value) || !CSSemGetType(value))
	{
		CCErrorOnLine(yygetfilename(node->expr),yygetlinenum(node->expr),
				"invalid argument for dereference operator");
		CSSemSetLValue(value,ILType_Int32);
		return value;
	}
	type=CSSemGetType(value);
	if(ILType_IsPointer(type) && ILType_Ref(type) != ILType_Void)
	{
		node->elemType = ILType_Ref(type);
		CSSemSetLValue(value, node->elemType);
		return value;
	}
	else
	{
		CCErrorOnLine(yygetfilename(node->expr),yygetlinenum(node->expr),
			"cannot dereference '%s'",CSTypeToName(CSSemGetType(value)));
	}
	CSSemSetLValue(value, ILType_Int32);
	return value;
}
#line 4991 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_37__(ILNode_StaticProperty *node, ILGenInfo * info, ILNode * * parent)
#line 2005 "cs_lvalue.tc"
{
	return CSSemValueDefault;
}
#line 4998 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_38__(ILNode_MemberProperty *node, ILGenInfo * info, ILNode * * parent)
#line 2005 "cs_lvalue.tc"
{
	return CSSemValueDefault;
}
#line 5005 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_39__(ILNode_IndexerAccess *node, ILGenInfo * info, ILNode * * parent)
#line 2005 "cs_lvalue.tc"
{
	return CSSemValueDefault;
}
#line 5012 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_40__(ILNode_SemGuard *node, ILGenInfo * info, ILNode * * parent)
#line 526 "cs_misc.tc"
{
	return node->value;
}
#line 5019 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_41__(ILNode_GlobalNamespace *node, ILGenInfo * info, ILNode * * parent)
#line 2346 "cs_oper.tc"
{
	ILNode *savedNamespace = info->currentNamespace;
	ILNode_Namespace *ns = (ILNode_Namespace *)savedNamespace;
	CSSemValue value;
	while(ns != 0 && ns->enclosing != 0)
	{
		ns = ns->enclosing;
	}
	info->currentNamespace = (ILNode *)ns;
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));
	info->currentNamespace = savedNamespace;
	return value;
}
#line 5036 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_42__(ILNode_AsIs *node, ILGenInfo * info, ILNode * * parent)
#line 2338 "cs_oper.tc"
{
	return ILNode_SemAnalysis(node->expr, info, &(node->expr));
}
#line 5043 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_43__(ILNode_Overflow *node, ILGenInfo * info, ILNode * * parent)
#line 2511 "cs_oper.tc"
{
	CSSemValue value;
	int overflow = info->overflowInsns;
	int changed = info->overflowChanged;
	info->overflowInsns = 1;
	info->overflowChanged = 1;
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));
	info->overflowInsns = overflow;
	info->overflowChanged = changed;
	return value;
}
#line 5058 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_44__(ILNode_NoOverflow *node, ILGenInfo * info, ILNode * * parent)
#line 2527 "cs_oper.tc"
{
	CSSemValue value;
	int overflow = info->overflowInsns;
	int changed = info->overflowChanged;
	info->overflowInsns = 0;
	info->overflowChanged = 1;
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));
	info->overflowInsns = overflow;
	info->overflowChanged = changed;
	return value;
}
#line 5073 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_45__(ILNode_Pedantic *node, ILGenInfo * info, ILNode * * parent)
#line 2543 "cs_oper.tc"
{
	CSSemValue value;
	int pedantic = info->pedanticArith;
	info->pedanticArith = 1;
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));
	info->pedanticArith = pedantic;
	return value;
}
#line 5085 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_46__(ILNode_NoPedantic *node, ILGenInfo * info, ILNode * * parent)
#line 2556 "cs_oper.tc"
{
	CSSemValue value;
	int pedantic = info->pedanticArith;
	info->pedanticArith = 0;
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));
	info->pedanticArith = pedantic;
	return value;
}
#line 5097 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_47__(ILNode_BaseAccess *node, ILGenInfo * info, ILNode * * parent)
#line 1424 "cs_lvalue.tc"
{
	CSSemValue value;
	CSSemValue value2;
	ILNode_MethodDeclaration *caller;
	ILClass *classInfo;
	ILNode *thisExpr;
	char *name;

	/* Bail out if "base" is used within a static method */
	caller = (ILNode_MethodDeclaration *)(info->currentMethod);
	if(!caller || (caller->modifiers & IL_META_METHODDEF_STATIC) != 0)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "cannot use base reference in a static method");
		CSSemSetType(value, ILType_Int32);
		return value;
	}

	/* Find the parent class to start searching from */
	classInfo = ILClass_Parent(ILMethod_Owner(caller->methodInfo));
	if(!classInfo)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "cannot use base reference in `System.Object'");
		CSSemSetType(value, ILType_Int32);
		return value;
	}

	/* Get the semantic value for the "base" part of the node */
	CSSemSetRValue(value, ILClassToType(classInfo));
	CSSemSetBase(value);

	/* Construct a dummy "this" expression to represent the object */
	thisExpr = ILNode_This_create();

	/* Resolve the member */
	name = ILQualIdentName(node->expr, 0);
	value2 = CSResolveMemberName(info, (ILNode *)node, value, name, 0);

	/* Convert the result into an l-value or r-value and return it */
	return SemToLRValue((ILNode *)node, info, parent, value2,
						name, thisExpr, &value);
}
#line 5144 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_48__(ILNode_BaseElement *node, ILGenInfo * info, ILNode * * parent)
#line 1472 "cs_lvalue.tc"
{
	CSSemValue value;
	ILNode_MethodDeclaration *caller;
	ILClass *classInfo;
	ILNode *thisExpr;
	CSSemValue indexers;
	CSEvalArg *args;
	int numArgs;
	unsigned long itemNum;
	ILProgramItem *itemInfo;
	int candidateForm, kind;
	ILMethod *getMethod;
	ILMethod *setMethod;
	ILType *objectType;
	
	/* Bail out if "base" is used within a static method */
	caller = (ILNode_MethodDeclaration *)(info->currentMethod);
	if(!caller || (caller->modifiers & IL_META_METHODDEF_STATIC) != 0)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "cannot use base reference in a static method");
		CSSemSetType(value, ILType_Int32);
		return value;
	}

	/* Find the parent class to start searching from */
	classInfo = ILClass_Parent(ILMethod_Owner(caller->methodInfo));
	if(!classInfo)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "cannot use base reference in `System.Object'");
		CSSemSetType(value, ILType_Int32);
		return value;
	}

	/* Construct a dummy "this" expression to represent the object */
	thisExpr = ILNode_This_create();

	/* Perform semantic analysis on the index argument list */
	numArgs = CSEvalArguments(info, node->expr, &(node->expr), &args);
	if(numArgs < 0)
	{
		CSSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Resolve the indexer for this type */
	objectType = ILClassToType(classInfo);

	indexers = CSResolveIndexers(info, (ILNode *)node,
								 ILType_ToClass(objectType),1);
	
	if(CSSemIsIndexerGroup(indexers))
	{
		/* Scan through the indexer group looking for something
		   that is applicable to the expression list */
		itemNum = 0;
		while((itemInfo = CSGetGroupMember
					(CSSemGetGroup(indexers), itemNum)) != 0)
		{
			candidateForm = CSItemIsCandidate
					(info, itemInfo, args, numArgs);
			if(candidateForm)
			{
				CSSetGroupMemberForm(CSSemGetGroup(indexers), itemNum,
									 candidateForm);
				++itemNum;
			}
			else
			{
				CSSemModifyGroup(indexers, (ILType *)CSRemoveGroupMember
									(CSSemGetGroup(indexers), itemNum));
			}
		}

		/* If there are no candidates left, then bail out */
		itemNum = 0;
		itemInfo = CSGetGroupMember(CSSemGetGroup(indexers), itemNum);
		if(!itemInfo)
		{
			CSItemCandidateError((ILNode *)node, 0, 0,
							     CSSemGetGroup(indexers), args, numArgs);
			CSEvalFreeArguments(args);
			return value;
		}

		/* If there are two or more candidates, then try to
		   find the best one */
		if(CSGetGroupMember(CSSemGetGroup(indexers), 1) != 0)
		{
			itemInfo = CSBestCandidate(info, CSSemGetGroup(indexers),
									   args, numArgs);
			if(!itemInfo)
			{
				CSItemCandidateError((ILNode *)node, 0, 0,
								     CSSemGetGroup(indexers),
									 args, numArgs);
				CSEvalFreeArguments(args);
				return value;
			}
		}

		/* Locate the "get" and "set" methods for the indexer */
		getMethod = ILProperty_Getter((ILProperty *)itemInfo);
		setMethod = ILProperty_Setter((ILProperty *)itemInfo);

		/* Determine the semantic kind for the value */
		if(getMethod && setMethod)
		{
			kind = CS_SEMKIND_LVALUE;
		}
		else if(getMethod)
		{
			kind = CS_SEMKIND_RVALUE;
		}
		else if(setMethod)
		{
			kind = CS_SEMKIND_SVALUE;
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "indexer does not have `get' or `set' accessors");
			kind = CS_SEMKIND_LVALUE;
		}

		/* Import the methods into this image */
		if(getMethod)
		{
			getMethod = (ILMethod *)ILMemberImport
					(info->image, (ILMember *)getMethod);
		}
		if(setMethod)
		{
			setMethod = (ILMethod *)ILMemberImport
					(info->image, (ILMember *)setMethod);
		}

		/* Coerce the arguments and build the final argument list */
		CSSemSetValueKind(value, kind, CSItemCoerceArgs
					(info, ILToProgramItem(itemInfo),
					 args, numArgs, &(node->expr)));

		/* Replace this node with an indexer access node */
		*parent = ILNode_IndexerAccess_create
				(thisExpr, node->expr, getMethod, setMethod,
				 objectType, CSSemGetType(value),
				 ILTypeToMachineType(CSSemGetType(value)),1);
	}
	else
	{
		/* No indexers are defined for this type */
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "array or indexed value expected");
		CSSemSetLValue(value, ILType_Int32);
	}
	return value;
}
#line 5306 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_49__(ILNode_MemberAccess *node, ILGenInfo * info, ILNode * * parent)
#line 1274 "cs_lvalue.tc"
{
	CSSemValue value;
	CSSemValue value2;
	CSSemValue nsvalue;
	char *name;
	ILEvalValue evalue;
	ILNode *save1;

	/*  PART I  - Try it in the usual fashion  */

	/*  Stow the original node contents for later  */
	save1 = node->expr1;
	

	if(info->inSemStatic)
	{
		// reset static lookup flag immediately
		info->inSemStatic = 0;
		value = ILNode_SemAnalysisType(node->expr1, info, &(node->expr1));
	}
	else
	{
		/* Get the semantic value for the left part of the identifier */
		value = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	}

	/* Set the rvalue if it is a constant expression */
	if(yyisa(node->expr1,ILNode_Constant))
	{
		if(ILNode_EvalConst(node->expr1,info,&evalue))
		{
			/* Set the RValue to the type .. to handle Boxing later on*/
			if(CSSemGetType(value)==ILType_Null)
			{
				CSSemSetRValue(value,ILValueTypeToType(info,evalue.valueType));
			}
			else
			{
				CSSemSetRValue(value,CSSemGetType(value));
			}
		}
	}

	/* Convert the second subexpression into a name */
	name = ILQualIdentName(node->expr2, 0);

	/* Check for the special case of "array.Length" */
	if(CSSemIsValue(value) && !strcmp(name, "Length") &&
	   ILType_IsSimpleArray(CSSemGetType(value)))
	{
		*parent = ILNode_ArrayLength_create(node->expr1);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		*parent = ILNode_CastSimple_create(*parent, ILMachineType_Int32);
		CSSemSetRValue(value, ILType_Int32);
		return value;
	}

	/* Resolve the member */
	value2 = CSResolveMemberNameQuiet(info, (ILNode *)node, value, name, 0);

	if (CSSemGetKind(value2) != CS_SEMKIND_VOID)
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, value2,
					    name, node->expr1, &value);
	}

	/*  PART II - Try again, this time limiting parsing to types  */
	node->expr1 = save1;

	value = ILNode_SemAnalysisType(node->expr1, info, &(node->expr1));

	value2 = CSResolveMemberNameQuiet(info, (ILNode *)node, value, name, 0);

	if (CSSemGetKind(value2) != CS_SEMKIND_VOID)
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, value2,
					    name, node->expr1, &value);
	}

	/*  PART III - Assume the left side of the '.' is a namespace and try
	 *  to locate a corresponding type.  */

	/*  Manufacture a Semantic value for the "namespace"  */
	/*
	CSSemSetKind(nsvalue, 
					CS_SEMKIND_NAMESPACE, ILMemberAccessName(node->expr1));

	value2 = CSResolveNamespaceMemberName(info, (ILNode *)node, nsvalue, name);

	if (CSSemGetKind(value2) != CS_SEMKIND_VOID) {
		return SemToLRValue((ILNode *)node, info, parent, value2,
						name, node->expr1, &value);
	}
*/
	/*  PART IV - Punt.  */
	if (!yyisa(*parent,ILNode_MemberAccess))
	{
		/*  Do it once more, but not so quiet about the errors :-)  */
		CSResolveMemberName(info, (ILNode *)node, nsvalue, name, 0);
	}

	/* Convert the result into an l-value or r-value and return it */
	return SemToLRValue((ILNode *)node, info, parent, value2,
					    name, node->expr1, &value);
}
#line 5418 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_50__(ILNode_DerefField *node, ILGenInfo * info, ILNode * * parent)
#line 1635 "cs_lvalue.tc"
{
	CSSemValue value;
	ILType *type;
	char *name;
	ILClass *classInfo;
	ILField *field;

	/* Emit an "unsafe" message if necessary */
	CCUnsafeMessage(info, (ILNode *)node, "unsafe field dereference");

	/* Perform semantic analysis on the left hand sub-expression */
	value = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	if(!CSSemIsValue(value) || !ILType_IsPointer(CSSemGetType(value)))
	{
		CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
					  "pointer value expected");
		CSSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Make sure that this is a pointer to a struct value type */
	type = ILTypeStripPrefixes(ILType_Ref(CSSemGetType(value)));
	if(!ILType_IsValueType(type) || ILTypeIsEnum(type))
	{
		CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
					  "`%s' is not a struct type", CSTypeToName(type));
		CSSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Resolve the field reference */
	name = ILQualIdentName(node->expr2, 0);
	classInfo = ILType_ToValueType(type);
	field = 0;
	while((field = (ILField *)ILClassNextMemberByKind
				(classInfo, (ILMember *)field, IL_META_MEMBERKIND_FIELD)) != 0)
	{
		if(!ILField_IsStatic(field) && !strcmp(ILField_Name(field), name))
		{
			break;
		}
	}
	if(!field)
	{
		CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
					  "`%s' is not a member of `%s'",
					  name, CSTypeToName(type));
		CSSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Set up the node for code generation and return */
	type = ILField_Type(field);
	node->field = field;
	node->machineType = ILTypeToMachineType(type);
	CSSemSetLValue(value, type);
	return value;
}
#line 5480 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_51__(ILNode_This *node, ILGenInfo * info, ILNode * * parent)
#line 44 "cs_lvalue.tc"
{
	CSSemValue value;
	ILNode_MethodDeclaration *method;
	ILType *type;

	/* Find the method declaration */
	method = (ILNode_MethodDeclaration *)(info->currentMethod);

	/* If the method is static, then we cannot use "this" */
	if((method->modifiers & IL_META_METHODDEF_STATIC) != 0)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "cannot use `this' in static methods");
	}

	/* Get the type from the method's class and return */
	type = ILClassToType(ILMethod_Owner(method->methodInfo));
	if(ILTypeIsValue(type) && !(info->outputIsJava))
	{
		CSSemSetLValue(value, type);
	}
	else
	{
		CSSemSetRValue(value, type);
	}
	return value;
}
#line 5511 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_52__(ILNode_LocalVar *node, ILGenInfo * info, ILNode * * parent)
#line 1264 "cs_lvalue.tc"
{
	/* This should never be called: these node types are
	   synthesised when ILNode_Identifier is analysed */
	return CSSemValueDefault;
}
#line 5520 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_53__(ILNode_ArgumentVar *node, ILGenInfo * info, ILNode * * parent)
#line 1264 "cs_lvalue.tc"
{
	/* This should never be called: these node types are
	   synthesised when ILNode_Identifier is analysed */
	return CSSemValueDefault;
}
#line 5529 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_54__(ILNode_RefArgumentVar *node, ILGenInfo * info, ILNode * * parent)
#line 1264 "cs_lvalue.tc"
{
	/* This should never be called: these node types are
	   synthesised when ILNode_Identifier is analysed */
	return CSSemValueDefault;
}
#line 5538 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_55__(ILNode_StaticField *node, ILGenInfo * info, ILNode * * parent)
#line 2005 "cs_lvalue.tc"
{
	return CSSemValueDefault;
}
#line 5545 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_56__(ILNode_MemberField *node, ILGenInfo * info, ILNode * * parent)
#line 2005 "cs_lvalue.tc"
{
	return CSSemValueDefault;
}
#line 5552 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_57__(ILNode_ArrayAccess *node, ILGenInfo * info, ILNode * * parent)
#line 1774 "cs_lvalue.tc"
{
	CSSemValue value;
	CSSemValue indexers;
	CSEvalArg *args;
	int numArgs, argNum;
	unsigned long itemNum;
	ILProgramItem *itemInfo;
	int candidateForm, kind;
	ILMethod *getMethod;
	ILMethod *setMethod;
	ILType *objectType;
	ILNode *tempNode;

	/* Perform semantic analysis on the array expression */
	if(!CSSemExpectValue(node->array, info, &(node->array), &value))
	{
		CCErrorOnLine(yygetfilename(node->array), yygetlinenum(node->array),
					  "array or indexed value expected");
		CSSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Perform semantic analysis on the index argument list */
	numArgs = CSEvalArguments(info, node->indices, &(node->indices), &args);
	if(numArgs < 0)
	{
		CSSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Is this an array element or an indexer access? */
	if(ILType_IsArray(CSSemGetType(value)))
	{
		/* All arguments must be coercable to one of "int", "uint",
		   "long", or "ulong", and are converted to "int" */
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			CoerceArrayIndex(info, &(args[argNum].node), args[argNum].parent,
			            	 args[argNum].type, 0);
		}

		/* Check the array's rank */
		if(numArgs != ILTypeGetRank(CSSemGetType(value)))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "incorrect number of indices for `%s'",
						  CSTypeToName(CSSemGetType(value)));
		}

		/* Store the type information in the node for the code generator */
		node->arrayType = CSSemGetType(value);
		node->elemType = ILTypeGetElemType(node->arrayType);

		/* Construct the semantic value for the element type */
		CSSemSetLValue(value, node->elemType);
	}
	else if(ILType_IsPointer(CSSemGetType(value)))
	{
		/* Access to an array defined by a pointer */
		CCUnsafeMessage(info, (ILNode *)node,
						"unsafe pointer-based array access");
		objectType = CSSemGetType(value);
		if(numArgs != 1)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "incorrect number of indices for `%s'",
						  CSTypeToName(objectType));
		}
		objectType = ILTypeStripPrefixes(ILType_Ref(objectType));
		if(objectType == ILType_Void)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`void *' cannot be used for an array access");
			objectType = ILType_UInt8;
		}
		CoerceArrayIndex(info, &(args[0].node), args[0].parent,
		            	 args[0].type, 1);
		if(objectType == ILType_Int8 || objectType == ILType_UInt8 ||
		   objectType == ILType_Boolean)
		{
			tempNode = ILNode_Add_create(node->array, args[0].node);
		}
		else
		{
			tempNode = ILNode_SizeOf_create(0);
			((ILNode_SizeOf *)tempNode)->type = objectType;
			tempNode = ILNode_CastSimple_create
				(tempNode, ILMachineType_NativeInt);
			tempNode = ILNode_Add_create(node->array,
				ILNode_Mul_create(args[0].node, tempNode));
		}
		yysetfilename(tempNode, yygetfilename(node));
		yysetlinenum(tempNode, yygetlinenum(node));
		*parent = ILNode_Deref_create(tempNode, objectType);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetLValue(value, objectType);
	}
	else if(ILType_IsClass(CSSemGetType(value)) ||
			ILType_IsValueType(CSSemGetType(value)))
	{
		/* Resolve the indexer for this type */
		objectType = CSSemGetType(value);
		indexers = CSResolveIndexers(info, (ILNode *)node,
									 ILType_ToClass(objectType),0);
		if(CSSemIsIndexerGroup(indexers))
		{
			/* Scan through the indexer group looking for something
			   that is applicable to the expression list */
			itemNum = 0;
			while((itemInfo = CSGetGroupMember
						(CSSemGetGroup(indexers), itemNum)) != 0)
			{
				candidateForm = CSItemIsCandidate
						(info, itemInfo, args, numArgs);
				if(candidateForm)
				{
					CSSetGroupMemberForm(CSSemGetGroup(indexers), itemNum,
										 candidateForm);
					++itemNum;
				}
				else
				{
					CSSemModifyGroup(indexers, (ILType *)CSRemoveGroupMember
										(CSSemGetGroup(indexers), itemNum));
				}
			}

			/* If there are no candidates left, then bail out */
			itemNum = 0;
			itemInfo = CSGetGroupMember(CSSemGetGroup(indexers), itemNum);
			if(!itemInfo)
			{
				CSItemCandidateError((ILNode *)node, 0, 0,
								     CSSemGetGroup(indexers), args, numArgs);
				CSEvalFreeArguments(args);
				return value;
			}

			/* If there are two or more candidates, then try to
			   find the best one */
			if(CSGetGroupMember(CSSemGetGroup(indexers), 1) != 0)
			{
				itemInfo = CSBestCandidate(info, CSSemGetGroup(indexers),
										   args, numArgs);
				if(!itemInfo)
				{
					CSItemCandidateError((ILNode *)node, 0, 0,
									     CSSemGetGroup(indexers),
										 args, numArgs);
					CSEvalFreeArguments(args);
					return value;
				}
			}

			/* Locate the "get" and "set" methods for the indexer */
			getMethod = ILProperty_Getter((ILProperty *)itemInfo);
			setMethod = ILProperty_Setter((ILProperty *)itemInfo);

			/* Determine the semantic kind for the value */
			if(getMethod && setMethod)
			{
				kind = CS_SEMKIND_LVALUE;
			}
			else if(getMethod)
			{
				kind = CS_SEMKIND_RVALUE;
			}
			else if(setMethod)
			{
				kind = CS_SEMKIND_SVALUE;
			}
			else
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  "indexer does not have `get' or `set' accessors");
				kind = CS_SEMKIND_LVALUE;
			}

			/* Import the methods into this image */
			if(getMethod)
			{
				getMethod = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)getMethod);
			}
			if(setMethod)
			{
				setMethod = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)setMethod);
			}

			/* Coerce the arguments and build the final argument list */
			CSSemSetValueKind(value, kind, CSItemCoerceArgs
						(info, ILToProgramItem(itemInfo),
						 args, numArgs, &(node->indices)));

			/* Replace this node with an indexer access node */
			*parent = ILNode_IndexerAccess_create
					(node->array, node->indices, getMethod, setMethod,
					 objectType, CSSemGetType(value),
					 ILTypeToMachineType(CSSemGetType(value)),0);
		}
		else
		{
			/* No indexers are defined for this type */
			CCErrorOnLine(yygetfilename(node->array), yygetlinenum(node->array),
						  "array or indexed value expected");
			CSSemSetLValue(value, ILType_Int32);
		}
	}
	else
	{
		/* Not an appropriate value for array or indexer access */
		CCErrorOnLine(yygetfilename(node->array), yygetlinenum(node->array),
					  "array or indexed value expected");
		CSSemSetLValue(value, ILType_Int32);
	}

	/* Free the argument list and return the element type */
	CSEvalFreeArguments(args);
	return value;
}
#line 5778 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_58__(ILNode_LogicalNot *node, ILGenInfo * info, ILNode * * parent)
#line 1688 "cs_oper.tc"
{
	CSSemValue value;
	ILMethod *method;
	ILType *returnType;

	/* Perform semantic analysis on the argument value */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value))
	{
	error:
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operand to unary `!'");
		CSSemSetRValue(value, ILType_Boolean);
		return value;
	}

	/* If the type is not boolean, we need to look for an operator */
	if(CSSemGetType(value) != ILType_Boolean)
	{
		method = FindUserUnaryOperator(info, "op_LogicalNot",
									   &(value), node->expr);
		if(method)
		{
			returnType = ILTypeGetReturn(ILMethod_Signature(method));
			*parent = ILNode_UserUnaryOp_create
						(node->expr, ILTypeToMachineType(returnType), method);
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value, returnType);
			return value;
		}
		else
		{
			goto error;
		}
	}

	/* Builtin "!" operator: the result is always boolean */
	CSSemSetRValue(value, ILType_Boolean);
	EvalOperator(info, *parent, parent, &value);
	return value;
}
#line 5823 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_59__(ILNode_Neg *node, ILGenInfo * info, ILNode * * parent)
#line 828 "cs_oper.tc"
{
	return UnarySem(info, (ILNode_UnaryExpression *)node,
					parent, ILOp_Neg, "op_UnaryNegation", "-");
}
#line 5831 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_60__(ILNode_UnaryPlus *node, ILGenInfo * info, ILNode * * parent)
#line 837 "cs_oper.tc"
{
	return UnarySem(info, (ILNode_UnaryExpression *)node,
				  	parent, ILOp_UnaryPlus, "op_UnaryPlus", "+");
}
#line 5839 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_61__(ILNode_Not *node, ILGenInfo * info, ILNode * * parent)
#line 873 "cs_oper.tc"
{
	return UnarySem(info, (ILNode_UnaryExpression *)node, parent, ILOp_Not,
					"op_OnesComplement", "~");
}
#line 5847 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_62__(ILNode_UserUnaryOp *node, ILGenInfo * info, ILNode * * parent)
#line 2600 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5854 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_63__(ILNode_PreInc *node, ILGenInfo * info, ILNode * * parent)
#line 1452 "cs_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Increment", "++", ILNode_UserPreInc_create,
					   ILNode_PreIncPtr_create);
}
#line 5863 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_64__(ILNode_PreDec *node, ILGenInfo * info, ILNode * * parent)
#line 1462 "cs_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Decrement", "--", ILNode_UserPreDec_create,
					   ILNode_PreDecPtr_create);
}
#line 5872 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_65__(ILNode_PostInc *node, ILGenInfo * info, ILNode * * parent)
#line 1472 "cs_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Increment", "++", ILNode_UserPostInc_create,
					   ILNode_PostIncPtr_create);
}
#line 5881 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_66__(ILNode_PostDec *node, ILGenInfo * info, ILNode * * parent)
#line 1482 "cs_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Decrement", "--", ILNode_UserPostDec_create,
					   ILNode_PostIncPtr_create);
}
#line 5890 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_67__(ILNode_UserPreInc *node, ILGenInfo * info, ILNode * * parent)
#line 2663 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5897 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_68__(ILNode_UserPreDec *node, ILGenInfo * info, ILNode * * parent)
#line 2663 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5904 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_69__(ILNode_UserPostInc *node, ILGenInfo * info, ILNode * * parent)
#line 2663 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5911 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_70__(ILNode_UserPostDec *node, ILGenInfo * info, ILNode * * parent)
#line 2663 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5918 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_71__(ILNode_PreIncPtr *node, ILGenInfo * info, ILNode * * parent)
#line 2674 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5925 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_72__(ILNode_PreDecPtr *node, ILGenInfo * info, ILNode * * parent)
#line 2674 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5932 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_73__(ILNode_PostIncPtr *node, ILGenInfo * info, ILNode * * parent)
#line 2674 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5939 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_74__(ILNode_PostDecPtr *node, ILGenInfo * info, ILNode * * parent)
#line 2674 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5946 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_75__(ILNode_CastSimple *node, ILGenInfo * info, ILNode * * parent)
#line 2632 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5953 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_76__(ILNode_CastType *node, ILGenInfo * info, ILNode * * parent)
#line 2636 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5960 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_77__(ILNode_UserConversion *node, ILGenInfo * info, ILNode * * parent)
#line 2608 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 5967 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_78__(ILNode_AddressOf *node, ILGenInfo * info, ILNode * * parent)
#line 2249 "cs_oper.tc"
{
	CSSemValue value;
	CCUnsafeMessage(info, (ILNode *)node, "unsafe address operator");
	value=ILNode_SemAnalysis(node->expr,info,&(node->expr));
	if(!CSSemIsValue(value))
	{
		CCErrorOnLine(yygetfilename(node->expr),yygetlinenum(node->expr),
				"invalid argument for address operator");
		CSSemSetRValue(value,ILType_Int32);
		return value;
	}
	if(yyisa(node->expr, ILNode_Deref))
	{
		/* If the argument is a pointer dereference, then remove the
		   extra layer and use the pointer directly as the address */
		*parent = ((ILNode_Deref *)(node->expr))->expr;
	}
	CSSemSetRValue(value,ILTypeCreateRef(info->context,
							IL_TYPE_COMPLEX_PTR,
							CSSemGetType(value)));
	return value;
}
#line 5993 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_79__(ILNode_ToBool *node, ILGenInfo * info, ILNode * * parent)
#line 1492 "cs_oper.tc"
{
	CSSemValue value;
	ILClass *classInfo;
	ILMethod *trueMethod;
	ILMethod *falseMethod;

	/* Perform semantic analysis on the value */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid boolean expression");
		CSSemSetRValue(value, ILType_Boolean);
		return value;
	}

	/* If the type is boolean, then we are done */
	if(CSSemGetType(value) == ILType_Boolean)
	{
		return value;
	}

	if(ILCanCoerceNode(info,node->expr,CSSemGetType(value), ILType_Boolean,0))
	{
		ILCoerce(info,node->expr,&(node->expr),CSSemGetType(value),
					ILType_Boolean,0);
		CSSemSetRValue(value,ILType_Boolean);
		return value;
	}

	/* We need a class or a value type if not boolean */
	if(!ILType_IsValueType(CSSemGetType(value)) &&
	   !ILType_IsClass(CSSemGetType(value)))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no conversion from `%s' to `bool'",
					  CSTypeToName(CSSemGetType(value)));
		CSSemSetRValue(value, ILType_Boolean);
		return value;
	}

	/* See if we have the "true" and "false" operators.  The C#
	   standard requires that both operators be present in the
	   class, but we are a little more forgiving than that: if
	   only one of the operators is present, we can synthesise
	   the other one */
	classInfo = ILType_ToClass(CSSemGetType(value));
	trueMethod = ILResolveConversionOperator
					(info, classInfo, "op_True", CSSemGetType(value),
					 ILType_Boolean);
	falseMethod = ILResolveConversionOperator
					(info, classInfo, "op_False", CSSemGetType(value),
					 ILType_Boolean);
	if(!trueMethod && !falseMethod)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no conversion from `%s' to `bool'",
					  CSTypeToName(CSSemGetType(value)));
		CSSemSetRValue(value, ILType_Boolean);
		return value;
	}

	/* Import the "true" and "false" operators into this image */
	if(trueMethod)
	{
		trueMethod = (ILMethod *)ILMemberImport
							(info->image, (ILMember *)trueMethod);
		if(!trueMethod)
		{
			CCOutOfMemory();
		}
	}
	if(falseMethod)
	{
		falseMethod = (ILMethod *)ILMemberImport
							(info->image, (ILMember *)falseMethod);
		if(!falseMethod)
		{
			CCOutOfMemory();
		}
	}

	/* Set the methods within the node for the code generator to use later */
	node->trueMethod = trueMethod;
	node->falseMethod = falseMethod;

	/* Return the final value to the caller */
	CSSemSetRValue(value, ILType_Boolean);
	return value;
}
#line 6086 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_80__(ILNode_ToAttrConst *node, ILGenInfo * info, ILNode * * parent)
#line 1615 "cs_oper.tc"
{
	CSSemValue value;
	ILNode_TypeOf *typeofNode;
	int savedState=info->inAttrArg;

	info->inAttrArg=1;

	/* Special case: types can be used as attribute constants */
	if(yyisa(node->expr, ILNode_TypeOf))
	{
		/* Get the semantic value for the typeof sub-expression */
		typeofNode = (ILNode_TypeOf *)(node->expr);
		value = ILNode_SemAnalysisType
			(typeofNode->expr, info, &(typeofNode->expr));

		/* Check that the argument is of the correct kind */
		if(CSSemIsType(value))
		{
			if(ILType_IsPrimitive(CSSemGetType(value)))
			{
				typeofNode->type = ILType_FromClass
					(ILTypeToClass(info, CSSemGetType(value)));
			}
			else
			{
				typeofNode->type = CSSemGetType(value);
			}
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid argument to `typeof' operator");
			typeofNode->type = ILFindSystemType(info, "Int32");
		}
		CSSemSetType(value, typeofNode->type);
		goto cleanup;
	}

	/* Perform semantic analysis on the sub-expression */
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));

	/* Types can be used as constants in attributes */
	if(CSSemIsType(value))
	{
		goto cleanup;
	}

	/* Determine if the sub-expression evaluates to a constant */
	if(!CSSemIsConstant(value) || CSSemIsDynConstant(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "constant value required");
		if(!CSSemIsValue(value))
		{
			CSSemSetDynConstant(value, ILType_Int32);
		}
		else
		{
			CSSemSetDynConstant(value, CSSemGetType(value));
		}
	}

cleanup:
	info->inAttrArg=savedState;

	/* Return the semantic information to the caller */
	return value;
}
#line 6158 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_81__(ILNode_ToConst *node, ILGenInfo * info, ILNode * * parent)
#line 1586 "cs_oper.tc"
{
	CSSemValue value;

	/* Perform semantic analysis on the sub-expression */
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));

	/* Determine if the sub-expression evaluates to a constant */
	if(!CSSemIsConstant(value) || CSSemIsDynConstant(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "constant value required");
		if(!CSSemIsValue(value))
		{
			CSSemSetDynConstant(value, ILType_Int32);
		}
		else
		{
			CSSemSetDynConstant(value, CSSemGetType(value));
		}
	}

	/* Return the semantic information to the caller */
	return value;
}
#line 6186 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_82__(ILNode_VarArgExpand *node, ILGenInfo * info, ILNode * * parent)
#line 139 "cs_invoke.tc"
{
	/* This will only be called if the term "__arglist(values)"
	   appeared in a context where it wasn't valid */
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  "`__arglist' cannot be used with arguments in this context");
	return CSSemValueDefault;
}
#line 6197 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_83__(ILNode_IsNull *node, ILGenInfo * info, ILNode * * parent)
#line 2699 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 6204 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_84__(ILNode_IsNonNull *node, ILGenInfo * info, ILNode * * parent)
#line 2699 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 6211 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_85__(ILNode_MakeRefAny *node, ILGenInfo * info, ILNode * * parent)
#line 558 "cs_misc.tc"
{
	CSSemValue value;

	/* Cannot use this operator with Java output */
	if(info->outputIsJava)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "`__makeref' disallowed when compiling to Java bytecode");
	}

	/* Perform semantic analysis on the sub-expression
	   which must be an l-value.  S-values are not allowed
	   because we have no way of knowing if some future
	   code may try to read the value via the typedref */
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));
	if(!CSSemIsLValue(value) ||
	   yyisa(node->expr, ILNode_LValueNoRef))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid lvalue in `__makeref' expression");
		node->type = ILType_Int32;
	}
	else
	{
		node->type = CSSemGetType(value);
	}

	/* The type of "__makeref" expressions is always ILType_TypedRef */
	CSSemSetRValue(value, ILType_TypedRef);
	return value;
}
#line 6246 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_86__(ILNode_RefType *node, ILGenInfo * info, ILNode * * parent)
#line 594 "cs_misc.tc"
{
	CSSemValue value;

	/* Cannot use this operator with Java output */
	if(info->outputIsJava)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "`__reftype' disallowed when compiling to Java bytecode");
	}

	/* Perform semantic analysis on the sub-expression, which
	   must be ILType_TypedRef */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value) ||
	   CSSemGetType(value) != ILType_TypedRef)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  	  "invalid argument to `__reftype'");
	}

	/* The result is "System.Type" */
	CSSemSetRValue(value, ILFindSystemType(info, "Type"));
	return value;
}
#line 6273 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_87__(ILNode_ArrayLength *node, ILGenInfo * info, ILNode * * parent)
#line 2707 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 6280 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_88__(ILNode_ArrayInit *node, ILGenInfo * info, ILNode * * parent)
#line 534 "cs_misc.tc"
{
	if(node->arrayType)
	{
		/* We've already visited this node, so return its type */
		CSSemValue value;
		CSSemSetRValue(value, node->arrayType);
		return value;
	}
	else
	{
		/* We haven't visited this node, so it has been used in
		   an incorrect context.  Initializers can be used on
		   fields and variables using regular assignment, or in
		   array creation expressions */
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("internal error in array initializer"));
		return CSSemValueDefault;
	}
}
#line 6303 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_89__(ILNode_TypeOf *node, ILGenInfo * info, ILNode * * parent)
#line 25 "cs_misc.tc"
{
	CSSemValue value;

	/* Get the semantic value for the sub-expression */
	value = ILNode_SemAnalysisType(node->expr, info, &(node->expr));

	/* Check that the argument is of the correct kind */
	if(CSSemIsType(value))
	{
		if(ILType_IsPrimitive(CSSemGetType(value)))
		{
			node->type = ILType_FromClass
				(ILTypeToClass(info, CSSemGetType(value)));
		}
		else
		{
			node->type = CSSemGetType(value);
		}
	}
	else
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid argument to `typeof' operator");
		node->type = ILFindSystemType(info, "Int32");
	}

	/* The type of the expression is "System.Type" */
	CSSemSetRValue(value, ILFindSystemType(info, "Type"));
	return value;
}
#line 6337 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_90__(ILNode_SizeOf *node, ILGenInfo * info, ILNode * * parent)
#line 191 "cs_misc.tc"
{
	CSSemValue value;

	/* Get the semantic value for the sub-expression */
	value = ILNode_SemAnalysis(node->expr, info, &(node->expr));

	/* sizeof(primitive) is safe in C# 2.0 */
	if(!ILType_IsPrimitive(CSSemGetType(value)))
	{
		/* Print an error or warning for this construct if necessary */
		CCUnsafeMessage(info, (ILNode *)node, "unsafe `sizeof' operator");
	}

	/* Convert native types into their value type forms */
	if(CSSemIsType(value))
	{
		if(CSSemGetType(value) == ILType_Int)
		{
			CSSemSetType(value, ILFindSystemType(info, "IntPtr"));
		}
		else if(CSSemGetType(value) == ILType_UInt)
		{
			CSSemSetType(value, ILFindSystemType(info, "UIntPtr"));
		}
	}

	/* Check the semantic value */
	if(!CSSemIsType(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid argument to `sizeof' operator");
		node->type = ILType_Int32;
	}
	else if(!ILType_IsPrimitive(CSSemGetType(value)) &&
			!ILType_IsValueType(CSSemGetType(value)) &&
			!ILType_IsPointer(CSSemGetType(value)))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "cannot take the size of a managed type");
		node->type = ILType_Int32;
	}
	else if(!ILType_IsPrimitive(CSSemGetType(value)) && info->outputIsJava)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`sizeof' disallowed when compiling to Java bytecode");
		node->type = ILType_Int32;
	}
	else if(CSSemGetType(value) == ILType_Void)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`void' type is not allowed in this context");
		node->type = ILType_Int32;
	}
	else if(ILType_IsPointer(CSSemGetType(value)))
	{
		/* Pointers always have the same size as a native integer */
		node->type = ILType_Int;
	}
	else
	{
		node->type = CSSemGetType(value);
	}

	/* Pre-compute the size if this is a primitive type */
	node->size = GetPrimitiveTypeSize(node->type);

	/* Return the type information to the caller */
	CSSemSetRValue(value, ILType_Int32);
	return value;
}
#line 6411 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_91__(ILNode_UserCast *node, ILGenInfo * info, ILNode * * parent)
#line 34 "cs_cast.tc"
{
	CSSemValue type;
	CSSemValue value;
	ILEvalValue evalValue;

	/* Perform semantic analysis on the type and value expressions */
	type = ILNode_SemAnalysisType(node->expr1, info, &(node->expr1));
	/* TODO: fix here when we refactor SemAnalysisType */
	value = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));

	/* Validate the value */
	if(!CSSemIsValue(value))
	{
		CCErrorOnLine(yygetfilename(node->expr2), yygetlinenum(node->expr2),
					  "invalid value supplied to cast");
		if(CSSemIsType(type))
		{
			CSSemSetRValue(value, CSSemGetType(type));
		}
		else
		{
			CSSemSetRValue(value, ILType_Int32);
		}
	}

	/* Validate the type */
	if(!CSSemIsType(type))
	{
		CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
					  "invalid type supplied to cast");
		CSSemSetType(type, CSSemGetType(value));
	}

	/* Determine if we can cast between the types */
	if(CSSemGetType(value) == ILType_Null && 
		CSSemGetType(type) == ILType_Int)
	{
		// Special case (IntPtr)(null) is possible even without a NULL
		// replacing with IntPtr.Zero
		*parent = ILNode_Int_create(0,0,0); 
		node->expr2 = *parent;
		CSSemSetRValue(value, CSSemGetType(type));
	}

	if(!ILCast(info, node->expr2, &(node->expr2),
			   CSSemGetType(value), CSSemGetType(type),1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "cannot cast from `%s' to `%s'",
					  CSTypeToName(CSSemGetType(value)),
					  CSTypeToName(CSSemGetType(type)));
	}
	else
	{
		/* Replace this node with the converted node */
		*parent = node->expr2;
	}

	/* Return an rvalue of the final type to the caller */
	if(ILNode_EvalConst(*parent, info, &evalValue))
	{
		if(!(info->overflowInsns) && !(info->overflowChanged))
		{
			/* Re-evaluate in overflow mode to see if an explicit
			   "unchecked(x)" is required around the expression */
			ILEvalValue evalValue2;
			int result;
			info->overflowInsns = 1;
			info->overflowChanged = 1;
			result = ILNode_EvalConst(*parent, info, &evalValue2);
			info->overflowInsns = 0;
			info->overflowChanged = 0;
			if(!result)
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  "constant value cannot be converted to `%s' "
							  "without an explicit `unchecked' context",
							  CSTypeToName(CSSemGetType(type)));
			}
		}
		CSSemSetConstant(value, CSSemGetType(type), evalValue);
		CSSemReplaceWithConstant(parent, value);
	}
	else
	{
		CSSemSetRValue(value, CSSemGetType(type));
	}
	return value;
}
#line 6504 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_92__(ILNode_IsUntyped *node, ILGenInfo * info, ILNode * * parent)
#line 2438 "cs_oper.tc"
{
	CSSemValue value;
	CSSemValue result;
	ILType *type;
	ILClass *classInfo;

	/* Perform semantic analysis on the two arguments */
	if(!CSSemExpectValue(node->expr1, info, &(node->expr1), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operands to binary `is'");
		CSSemSetRValue(value, ILFindSystemType(info, "Object"));
	}
	type = CSSemType(node->expr2, info, &(node->expr2));

	/* Create the result semantic value */
	CSSemSetRValue(result, ILType_Boolean);

	/* Determine if there is an implicit reference or boxing coercion */
	if(ILCanCoerceKind(info, CSSemGetType(value), type,
					   IL_CONVERT_REFERENCE | IL_CONVERT_BOXING,1))
	{
		if(ILTypeIsReference(CSSemGetType(value)))
		{
			/* Reference types: test the expression against null */
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
				    "`is' expression is equivalent to a test against `null'");
			*parent = ILNode_Ne_create(node->expr1, ILNode_Null_create());
		}
		else
		{
			/* Value types: the result is always true, but we should
			   still evaluate the expression for its side-effects */
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
						    "`is' expression is always true");
			*parent = ILNode_Comma_create(node->expr1, ILNode_True_create());
		}
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return result;
	}

	/* Determine if there is an explicit reference or unboxing conversion */
	classInfo = ILGetExplicitConv(info, CSSemGetType(value), type,
								  IL_CONVERT_REFERENCE | IL_CONVERT_UNBOXING);
	if(classInfo != 0)
	{
		*parent = ILNode_Is_create(node->expr1, classInfo, 0);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return result;
	}

	/* The result will always be "false", but we should still
	   evaluate the expression for its side-effects */
	CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
		  		    "`is' expression is always false");
	*parent = ILNode_Comma_create(node->expr1, ILNode_False_create());
	return result;
}
#line 6568 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_93__(ILNode_AsUntyped *node, ILGenInfo * info, ILNode * * parent)
#line 2381 "cs_oper.tc"
{
	CSSemValue value;
	CSSemValue result;
	ILType *type;
	ILClass *classInfo;

	/* Perform semantic analysis on the two arguments */
	if(!CSSemExpectValue(node->expr1, info, &(node->expr1), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operands to binary `as'");
		CSSemSetRValue(value, ILFindSystemType(info, "Object"));
	}
	type = CSSemType(node->expr2, info, &(node->expr2));

	/* The type must be an object reference type */
	if(!ILTypeIsReference(type))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "reference type required");
		type = ILFindSystemType(info, "Object");
	}

	/* Create the result semantic value */
	CSSemSetRValue(result, type);

	/* Determine if there is an implicit reference or boxing coercion */
	if(ILCoerceKind(info, node->expr1, &(node->expr1),
					CSSemGetType(value), type,
					IL_CONVERT_REFERENCE | IL_CONVERT_BOXING,1))
	{
		*parent = node->expr1;
		return result;
	}

	/* Determine if there is an explicit reference conversion */
	classInfo = ILGetExplicitConv(info, CSSemGetType(value), type,
								  IL_CONVERT_REFERENCE);
	if(classInfo != 0)
	{
		*parent = ILNode_As_create(node->expr1, classInfo, 0);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return result;
	}

	/* Report an error for the conversion */
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  		  "no conversion from `%s' to `%s'",
		  		  CSTypeToName(CSSemGetType(value)), CSTypeToName(type));
	return result;
}
#line 6624 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_94__(ILNode_LogicalAnd *node, ILGenInfo * info, ILNode * * parent)
#line 1734 "cs_oper.tc"
{
	CSSemValue value1;
	CSSemValue value2;
	ILMethod *method1;
	ILMethod *method2;
	ILMethod *method3;

	/* Perform semantic analysis on the arguments */
	if(!CSSemExpectValue(node->expr1, info, &(node->expr1), &value1) ||
	   !CSSemExpectValue(node->expr2, info, &(node->expr2), &value2))
	{
		goto error;
	}

	/* Find a user-defined operator, if any */
	if(CSSemGetType(value1) == CSSemGetType(value2) &&
	   (ILType_IsValueType(CSSemGetType(value1)) ||
	    ILType_IsClass(CSSemGetType(value1))))
	{
		method1 = FindUserBinaryOperator
					(info, "op_BitwiseAnd", &(value1), node->expr1,
					 &(value1), node->expr2);
		method2 = ILResolveConversionOperator
					(info, ILType_ToClass(CSSemGetType(value1)), "op_True",
					 CSSemGetType(value1), ILType_Boolean);
		method3 = ILResolveConversionOperator
					(info, ILType_ToClass(CSSemGetType(value1)), "op_False",
					 CSSemGetType(value1), ILType_Boolean);
		if(method1 && (method2 || method3))
		{
			method1 = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)method1);
			if(!method1)
			{
				CCOutOfMemory();
			}
			if(method2)
			{
				method2 = (ILMethod *)ILMemberImport
							(info->image, (ILMember *)method2);
				if(!method2)
				{
					CCOutOfMemory();
				}
			}
			if(method3)
			{
				method3 = (ILMethod *)ILMemberImport
							(info->image, (ILMember *)method3);
				if(!method3)
				{
					CCOutOfMemory();
				}
			}
			*parent = ILNode_UserLogicalAnd_create
						(node->expr1, node->expr2, method1, method2, method3);
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
	}

	/* We must have boolean arguments at this point */
	if(!ILCanCoerceNode(info, node->expr1, CSSemGetType(value1),
						ILType_Boolean,1) ||
	   !ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
	   					ILType_Boolean,1))
	{
		goto error;
	}

	/* Coerce the two arguments to `bool' */
	ILCoerce(info, node->expr1, &(node->expr1),
			 CSSemGetType(value1), ILType_Boolean,1);
	ILCoerce(info, node->expr2, &(node->expr2),
			 CSSemGetType(value2), ILType_Boolean,1);

	/* The result is boolean */
	CSSemSetRValue(value1, ILType_Boolean);
	EvalOperator(info, *parent, parent, &value1);
	return value1;

	/* Report an argument error */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `&&'");
	CSSemSetRValue(value1, ILType_Boolean);
	return value1;
}
#line 6718 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_95__(ILNode_LogicalOr *node, ILGenInfo * info, ILNode * * parent)
#line 1829 "cs_oper.tc"
{
	CSSemValue value1;
	CSSemValue value2;
	ILMethod *method1;
	ILMethod *method2;
	ILMethod *method3;

	/* Perform semantic analysis on the arguments */
	if(!CSSemExpectValue(node->expr1, info, &(node->expr1), &value1) ||
	   !CSSemExpectValue(node->expr2, info, &(node->expr2), &value2))
	{
		goto error;
	}

	/* Find a user-defined operator, if any */
	if(CSSemGetType(value1) == CSSemGetType(value2) &&
	   (ILType_IsValueType(CSSemGetType(value1)) ||
	    ILType_IsClass(CSSemGetType(value1))))
	{
		method1 = FindUserBinaryOperator
					(info, "op_BitwiseOr", &(value1), node->expr1,
					 &(value1), node->expr2);
		method2 = ILResolveConversionOperator
					(info, ILType_ToClass(CSSemGetType(value1)), "op_True",
					 CSSemGetType(value1), ILType_Boolean);
		method3 = ILResolveConversionOperator
					(info, ILType_ToClass(CSSemGetType(value1)), "op_False",
					 CSSemGetType(value1), ILType_Boolean);
		if(method1 && (method2 || method3))
		{
			method1 = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)method1);
			if(!method1)
			{
				CCOutOfMemory();
			}
			if(method2)
			{
				method2 = (ILMethod *)ILMemberImport
							(info->image, (ILMember *)method2);
				if(!method2)
				{
					CCOutOfMemory();
				}
			}
			if(method3)
			{
				method3 = (ILMethod *)ILMemberImport
							(info->image, (ILMember *)method3);
				if(!method3)
				{
					CCOutOfMemory();
				}
			}
			*parent = ILNode_UserLogicalOr_create
						(node->expr1, node->expr2, method1, method2, method3);
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
	}

	/* We must have boolean arguments at this point */
	if(!ILCanCoerceNode(info, node->expr1, CSSemGetType(value1),
						ILType_Boolean,1) ||
	   !ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
	   					ILType_Boolean,1))
	{
		goto error;
	}

	/* Coerce the two arguments to `bool' */
	ILCoerce(info, node->expr1, &(node->expr1),
			 CSSemGetType(value1), ILType_Boolean,1);
	ILCoerce(info, node->expr2, &(node->expr2),
			 CSSemGetType(value2), ILType_Boolean,1);

	/* The result is boolean */
	CSSemSetRValue(value1, ILType_Boolean);
	EvalOperator(info, *parent, parent, &value1);
	return value1;

	/* Report an argument error */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `||'");
	CSSemSetRValue(value1, ILType_Boolean);
	return value1;
}
#line 6812 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_96__(ILNode_UserLogicalAnd *node, ILGenInfo * info, ILNode * * parent)
#line 2644 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 6819 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_97__(ILNode_UserLogicalOr *node, ILGenInfo * info, ILNode * * parent)
#line 2652 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 6826 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_98__(ILNode_Add *node, ILGenInfo * info, ILNode * * parent)
#line 407 "cs_oper.tc"
{
	const ILOperator *oper;
	ILMethod *method;
	CSSemValue value1;
	CSSemValue value2;
	ILType *resultType;
	ILType *elemType;
	ILNode_SizeOf *sizeNode;
	ILMachineType machineType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));

	/* The two arguments must be values */
	if(!CSSemIsValue(value1) || !CSSemIsValue(value2))
	{
		goto error;
	}

	/* try constant coercion first */
	if(ILCanCoerceNodeKind(info,node->expr1,CSSemGetType(value1),
			CSSemGetType(value2),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr1,&(node->expr1),CSSemGetType(value1),
			CSSemGetType(value2),IL_CONVERT_CONSTANT,1);
		CSSemSetRValue(value1,CSSemGetType(value2));
	}
	else if(ILCanCoerceNodeKind(info,node->expr2,CSSemGetType(value2),
			CSSemGetType(value1),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr2,&(node->expr2),CSSemGetType(value2),
			CSSemGetType(value1),IL_CONVERT_CONSTANT,1);
		CSSemSetRValue(value2,CSSemGetType(value1));
	}
	
	/* Look for a builtin operator */
	oper = ILFindBinaryOperator
				(ILOp_Add, CSSemGetType(value1),
				 CSSemGetType(value2), &resultType,
				 IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value1, resultType);
		}
		else
		{
			CSSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	} 
	/* Look for a user-specified operator */
	method = FindUserBinaryOperator(info, "op_Addition",
									&(value1), node->expr1,
									&(value2), node->expr2);
	if(method)
	{
		ApplyUserBinaryOperator(info,method,(ILNode_BinaryExpression*)node,
								parent,&(value1),&(value2));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}

	/* If one of the arguments is a string, then perform concatenation */
	if(ILTypeIsStringClass(CSSemGetType(value1)) ||
	   ILTypeIsStringClass(CSSemGetType(value2)))
	{
		if(!ILTypeIsStringClass(CSSemGetType(value1)))
		{
			/* Convert the first argument into "ObjectRef" */
			ILCast(info, node->expr1, &(node->expr1), CSSemGetType(value1),
				   ILFindSystemType(info, "Object"),1);
		}
		if(!ILTypeIsStringClass(CSSemGetType(value2)))
		{
			/* Convert the second argument into "ObjectRef" */
			ILCast(info, node->expr2, &(node->expr2), CSSemGetType(value2),
				   ILFindSystemType(info, "Object"),1);
		}
		*parent = ILNode_Concat_create(node->expr1, node->expr2);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		CSSemSetRValue(value1, ILFindSystemType(info, "String"));
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* If both arguments are delegates of the same type,
	   then perform delegate combination */
	if(ILTypeIsDelegate(CSSemGetType(value1)) &&
       ILTypeIsDelegate(CSSemGetType(value2)) &&
	   ILTypeIdentical(CSSemGetType(value1), CSSemGetType(value2)))
	{
		*parent = ILNode_DelegateAdd_create
			(node->expr1, node->expr2, ILType_ToClass(CSSemGetType(value1)));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}

	/* Check for binary operations involving pointers */
	if(ILType_IsPointer(CSSemGetType(value1)))
	{
		resultType = ToNumericType(info, CSSemGetType(value2));
		if(resultType)
		{
			ILCoerce(info, node->expr2, &(node->expr2),
					 CSSemGetType(value2), resultType, 0);
			if(resultType == ILType_UInt32 || resultType == ILType_UInt64)
			{
				machineType = ILMachineType_NativeUInt;
			}
			else
			{
				machineType = ILMachineType_NativeInt;
			}
			node->expr1 = ILNode_CastSimple_create(node->expr1, machineType);
			node->expr2 = ILNode_CastSimple_create(node->expr2, machineType);
			elemType = ILTypeStripPrefixes(ILType_Ref(CSSemGetType(value1)));
			sizeNode = (ILNode_SizeOf *)ILNode_SizeOf_create(0);
			sizeNode->type = elemType;
			sizeNode->size = GetPrimitiveTypeSize(elemType);
			node->expr2 = ILNode_Mul_create
				(node->expr2, ILNode_CastSimple_create
					((ILNode *)sizeNode, machineType));
			CSSemSetRValue(value1, CSSemGetType(value1));
			return value1;
		}
	}
	else if(ILType_IsPointer(CSSemGetType(value2)))
	{
		resultType = ToNumericType(info, CSSemGetType(value1));
		if(resultType)
		{
			ILCoerce(info, node->expr1, &(node->expr1),
					 CSSemGetType(value1), resultType, 0);
			if(resultType == ILType_UInt32 || resultType == ILType_UInt64)
			{
				machineType = ILMachineType_NativeUInt;
			}
			else
			{
				machineType = ILMachineType_NativeInt;
			}
			node->expr1 = ILNode_CastSimple_create(node->expr1, machineType);
			node->expr2 = ILNode_CastSimple_create(node->expr2, machineType);
			elemType = ILTypeStripPrefixes(ILType_Ref(CSSemGetType(value1)));
			sizeNode = (ILNode_SizeOf *)ILNode_SizeOf_create(0);
			sizeNode->type = elemType;
			sizeNode->size = GetPrimitiveTypeSize(elemType);
			node->expr1 = ILNode_Mul_create
				(node->expr1, ILNode_CastSimple_create
					((ILNode *)sizeNode, machineType));
			CSSemSetRValue(value2, CSSemGetType(value2));
			return value2;
		}
	}

	/* As a last measure , try coercing the nodes */
	if(ILCanCoerceNode(info, node->expr1, CSSemGetType(value1),
					   CSSemGetType(value2),1))
	{
		ILCoerce(info, node->expr1, &(node->expr1), CSSemGetType(value1),
				 CSSemGetType(value2),1);
		CSSemSetRValue(value1, CSSemGetType(value2));
	}
	else if(ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
					   CSSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), CSSemGetType(value2),
				 CSSemGetType(value1),1);
		CSSemSetRValue(value2, CSSemGetType(value1));
	}

	/* Look for a builtin operator again */
	oper = ILFindBinaryOperator
				(ILOp_Add, CSSemGetType(value1),
				 CSSemGetType(value2), &resultType,
				 IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value1, resultType);
		}
		else
		{
			CSSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	} 

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `+'");
	CSSemSetRValue(value1, ILType_Int32);
	return value1;
}
#line 7036 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_99__(ILNode_Sub *node, ILGenInfo * info, ILNode * * parent)
#line 618 "cs_oper.tc"
{
	const ILOperator *oper;
	ILMethod *method;
	CSSemValue value1;
	CSSemValue value2;
	ILType *resultType;
	ILType *elemType;
	ILNode_SizeOf *sizeNode;
	ILMachineType machineType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));

	/* The two arguments must be values */
	if(!CSSemIsValue(value1) || !CSSemIsValue(value2))
	{
		goto error;
	}

	/* try constant coercion first */
	if(ILCanCoerceNodeKind(info,node->expr1,CSSemGetType(value1),
			CSSemGetType(value2),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr1,&(node->expr1),CSSemGetType(value1),
			CSSemGetType(value2),IL_CONVERT_CONSTANT,1);
		CSSemSetRValue(value1,CSSemGetType(value2));
	}
	else if(ILCanCoerceNodeKind(info,node->expr2,CSSemGetType(value2),
			CSSemGetType(value1),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr2,&(node->expr2),CSSemGetType(value2),
			CSSemGetType(value1),IL_CONVERT_CONSTANT,1);
		CSSemSetRValue(value2,CSSemGetType(value1));
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator
				(ILOp_Sub, CSSemGetType(value1),
				 CSSemGetType(value2), &resultType,
				 IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value1, resultType);
		}
		else
		{
			CSSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Look for a user-specified operator */
	method = FindUserBinaryOperator(info, "op_Subtraction",
									&(value1), node->expr1,
									&(value2), node->expr2);
	if(method)
	{
		ApplyUserBinaryOperator(info,method,(ILNode_BinaryExpression*)node,
								parent,&(value1),&(value2));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}

	/* If both arguments are delegates of the same type,
	   then perform delegate removal */
	if(ILTypeIsDelegate(CSSemGetType(value1)) &&
	   ILTypeIsDelegate(CSSemGetType(value2)) &&
	   ILTypeIdentical(CSSemGetType(value1), CSSemGetType(value2)))
	{
		*parent = ILNode_DelegateSub_create
			(node->expr1, node->expr2, ILType_ToClass(CSSemGetType(value1)));
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value1;
	}

	/* Check for binary operations involving pointers */
	if(ILType_IsPointer(CSSemGetType(value1)) &&
	   ILType_IsPointer(CSSemGetType(value2)))
	{
		if(ILTypeIdentical(ILType_Ref(CSSemGetType(value1)),
						   ILType_Ref(CSSemGetType(value2))))
		{
			/* Subtract two pointers of the same type */
			elemType = ILTypeStripPrefixes
				(ILType_Ref(CSSemGetType(value1)));
			sizeNode = (ILNode_SizeOf *)ILNode_SizeOf_create(0);
			sizeNode->type = elemType;
			sizeNode->size = GetPrimitiveTypeSize(elemType);
			*parent = ILNode_CastSimple_create
				((ILNode *)node, ILMachineType_Int64);
			*parent = ILNode_Div_create
				(*parent, ILNode_CastSimple_create
					((ILNode *)sizeNode, ILMachineType_Int64));
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			CSSemSetRValue(value1, ILType_Int64);
			return value1;
		}
	}
	else if(ILType_IsPointer(CSSemGetType(value1)))
	{
		resultType = ToNumericType(info, CSSemGetType(value2));
		if(resultType)
		{
			ILCoerce(info, node->expr2, &(node->expr2),
					 CSSemGetType(value2), resultType, 0);
			if(resultType == ILType_UInt32 || resultType == ILType_UInt64)
			{
				machineType = ILMachineType_NativeUInt;
			}
			else
			{
				machineType = ILMachineType_NativeInt;
			}
			node->expr1 = ILNode_CastSimple_create(node->expr1, machineType);
			node->expr2 = ILNode_CastSimple_create(node->expr2, machineType);
			elemType = ILTypeStripPrefixes(ILType_Ref(CSSemGetType(value1)));
			sizeNode = (ILNode_SizeOf *)ILNode_SizeOf_create(0);
			sizeNode->type = elemType;
			sizeNode->size = GetPrimitiveTypeSize(elemType);
			node->expr2 = ILNode_Mul_create
				(node->expr2, ILNode_CastSimple_create
					((ILNode *)sizeNode, machineType));
			CSSemSetRValue(value1, CSSemGetType(value1));
			return value1;
		}
	}

	/* As a last measure try coercing the types*/
	if(ILCanCoerceNode(info, node->expr1, CSSemGetType(value1),
					   CSSemGetType(value2),1))
	{
		ILCoerce(info, node->expr1, &(node->expr1), CSSemGetType(value1),
				 CSSemGetType(value2),1);
		CSSemSetRValue(value1, CSSemGetType(value2));
	}
	else if(ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
					   CSSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), CSSemGetType(value2),
				 CSSemGetType(value1),1);
		CSSemSetRValue(value2, CSSemGetType(value1));
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator
				(ILOp_Add, CSSemGetType(value1),
				 CSSemGetType(value2), &resultType,
				 IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			CSSemSetRValue(value1, resultType);
		}
		else
		{
			CSSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	} 

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `-'");
	CSSemSetRValue(value1, ILType_Int32);
	return value1;
}
#line 7218 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_100__(ILNode_Mul *node, ILGenInfo * info, ILNode * * parent)
#line 801 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Mul, "op_Multiply", "*",1);
}
#line 7226 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_101__(ILNode_Div *node, ILGenInfo * info, ILNode * * parent)
#line 810 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Div, "op_Division", "/",1);
}
#line 7234 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_102__(ILNode_Rem *node, ILGenInfo * info, ILNode * * parent)
#line 819 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Rem, "op_Modulus", "%",1);
}
#line 7242 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_103__(ILNode_And *node, ILGenInfo * info, ILNode * * parent)
#line 846 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_And, "op_BitwiseAnd", "&",1);
}
#line 7250 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_104__(ILNode_Or *node, ILGenInfo * info, ILNode * * parent)
#line 864 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Or, "op_BitwiseOr", "|",1);
}
#line 7258 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_105__(ILNode_Xor *node, ILGenInfo * info, ILNode * * parent)
#line 855 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Xor, "op_ExclusiveOr", "^",1);
}
#line 7266 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_106__(ILNode_Shl *node, ILGenInfo * info, ILNode * * parent)
#line 882 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Shl, "op_LeftShift", "<<",0);
}
#line 7274 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_107__(ILNode_Shr *node, ILGenInfo * info, ILNode * * parent)
#line 891 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Shr, "op_RightShift", ">>",0);
}
#line 7282 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_108__(ILNode_UShr *node, ILGenInfo * info, ILNode * * parent)
#line 900 "cs_oper.tc"
{
	/* C# doesn't actually have an unsigned right shift, but we
	   still need to include this case for completeness sake */
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Shr, "op_RightShift", ">>",0);
}
#line 7292 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_109__(ILNode_UserBinaryOp *node, ILGenInfo * info, ILNode * * parent)
#line 2592 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7299 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_110__(ILNode_Concat *node, ILGenInfo * info, ILNode * * parent)
#line 2575 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7306 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_111__(ILNode_DelegateAdd *node, ILGenInfo * info, ILNode * * parent)
#line 2584 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7313 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_112__(ILNode_DelegateSub *node, ILGenInfo * info, ILNode * * parent)
#line 2584 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7320 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_113__(ILNode_Assign *node, ILGenInfo * info, ILNode * * parent)
#line 961 "cs_oper.tc"
{
	CSSemValue value1;
	CSSemValue value2;

	/* Perform semantic analysis on the lvalue */
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	if(!CSSemIsLValue(value1) && !CSSemIsSValue(value1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid lvalue in assignment");
		if(!CSSemIsRValue(value1))
		{
			CSSemSetRValue(value1, ILType_Int32);
		}
		return value1;
	}

	/* Check for array initializers in the assigned expression */
	if(yyisa(node->expr2, ILNode_ArrayInit))
	{
		/* Make sure that the destination type is an array */
		if(!ILType_IsArray(CSSemGetType(value1)))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "array initializer assigned to non-array destination");
			CSSemSetRValue(value1, CSSemGetType(value1));
			return value1;
		}

		/* Check the shape of the array initializer */
		if(!ILArrayInitShapeOK(info, node->expr2, CSSemGetType(value1)))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "incorrect pattern of elements in array initializer");
			CSSemSetRValue(value1, CSSemGetType(value1));
			return value1;
		}

		/* Coerce all initializer members to the element type */
		CoerceArrayInit(info, node->expr2, &(node->expr2),
					    ILTypeGetElemType(CSSemGetType(value1)));
		CSSemSetRValue(value1, CSSemGetType(value1));
		return value1;
	}
	
	/* Perform semantic analysis and coercion on the rvalue */
	if(!CSSemExpectValue(node->expr2, info, &(node->expr2), &value2) ||
	   !ILCanCoerceNode(info, node->expr2, CSSemGetType(value2),
	   					CSSemGetType(value1),1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  "incompatible types in assignment: no conversion from `%s' to `%s'",
		  CSTypeToName(CSSemGetType(value2)),
		  CSTypeToName(CSSemGetType(value1)));
		CSSemSetRValue(value1, CSSemGetType(value1));
		return value1;
	}
	/* Insert coercion nodes to convert the rvalue appropriately */
	ILCoerce(info, node->expr2, &(node->expr2),
			 CSSemGetType(value2), CSSemGetType(value1),1);

	/* Convert value1 into an rvalue and return its type */
	CSSemSetRValue(value1, CSSemGetType(value1));
	return value1;
}
#line 7389 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_114__(ILNode_Eq *node, ILGenInfo * info, ILNode * * parent)
#line 2163 "cs_oper.tc"
{
	return EqualitySem(info, (ILNode_BinaryExpression *)node, parent,
					   ILOp_Eq, "op_Equality", "==");
}
#line 7397 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_115__(ILNode_Ne *node, ILGenInfo * info, ILNode * * parent)
#line 2172 "cs_oper.tc"
{
	return EqualitySem(info, (ILNode_BinaryExpression *)node, parent,
					   ILOp_Ne, "op_Inequality", "!=");
}
#line 7405 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_116__(ILNode_Lt *node, ILGenInfo * info, ILNode * * parent)
#line 2181 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Lt, "op_LessThan", "<",1);
}
#line 7413 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_117__(ILNode_Le *node, ILGenInfo * info, ILNode * * parent)
#line 2190 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Le, "op_LessThanOrEqual", "<=",1);
}
#line 7421 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_118__(ILNode_Gt *node, ILGenInfo * info, ILNode * * parent)
#line 2199 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Gt, "op_GreaterThan", ">",1);
}
#line 7429 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_119__(ILNode_Ge *node, ILGenInfo * info, ILNode * * parent)
#line 2208 "cs_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Ge, "op_GreaterThanOrEqual", ">=",1);
}
#line 7437 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_120__(ILNode_Comma *node, ILGenInfo * info, ILNode * * parent)
#line 2364 "cs_oper.tc"
{
	CSSemValue value1;
	CSSemValue value2;
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));
	if(!CSSemIsValue(value1) || !CSSemIsValue(value2))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operands to binary `,'");
	}
	return value2;
}
#line 7453 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_121__(ILNode_ArgList *node, ILGenInfo * info, ILNode * * parent)
#line 90 "cs_invoke.tc"
{
	CSSemValue value1;
	CSSemValue value2;
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));
	if(!CSSemIsValue(value1) || !CSSemIsValue(value2))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operands to binary `,'");
	}
	return value2;
}
#line 7469 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_122__(ILNode_RefValue *node, ILGenInfo * info, ILNode * * parent)
#line 622 "cs_misc.tc"
{
	CSSemValue value;

	/* Cannot use this operator with Java output */
	if(info->outputIsJava)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "`__refvalue' disallowed when compiling to Java bytecode");
	}

	/* Perform semantic analysis on the first sub-expression,
	   which must be ILType_TypedRef */
	if(!CSSemExpectValue(node->expr1, info, &(node->expr1), &value) ||
	   CSSemGetType(value) != ILType_TypedRef)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  	  "invalid first argument to `__refvalue'");
	}

	/* Perform semantic analysis on the second sub-expression,
	   which must be a type */
	node->type = CSSemType(node->expr2, info, &(node->expr2));

	/* The result is an r-value of the supplied type */
	CSSemSetRValue(value, node->type);
	return value;
}
#line 7500 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_123__(ILNode_InvocationExpression *node, ILGenInfo * info, ILNode * * parent)
#line 403 "cs_invoke.tc"
{
	CSSemValue value;
	CSSemValue method;
	ILProgramItem *itemInfo;
	ILMethod *methodInfo;
	ILType *retType;
	CSEvalArg *args;
	int numArgs;
	unsigned long itemNum;
	char *itemName;
	ILNode_MethodDeclaration *caller;
	int isCtor = 0;
	ILNode_MemberAccess *savedNode = NULL;
	ILNode *savedChild1 = NULL;
	ILNode *savedChild2 = NULL;
	

	/* Get the method name for later error reporting */
	if(ILIsQualIdent(node->expr1))
	{
		itemName = ILQualIdentName(node->expr1, 0);
	}
	else if(yyisa(node->expr1, ILNode_MemberAccess))
	{
		/* wish we could clone the entire node :) */
		savedNode = (ILNode_MemberAccess*)(node->expr1);
		savedChild1 = savedNode->expr1;
		savedChild2 = savedNode->expr2;
		itemName = ILQualIdentName
			(((ILNode_MemberAccess *)(node->expr1))->expr2, 0);
	}
	else if(yyisa(node->expr1, ILNode_ThisInit))
	{
		itemName = 0;
		isCtor = 1;
	}
	else if(yyisa(node->expr1, ILNode_BaseInit))
	{
		itemName = 0;
		isCtor = 2;
	}
	else
	{
		itemName = 0;
	}

	/* Perform semantic analysis on the method expression */
	method = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	if(CSSemIsValue(method) && ILTypeIsDelegate(CSSemGetType(method)))
	{
		/* This is a delegate invocation: create a method group
		   that contains the "Invoke" method as its only member */
		void *group = CSCreateMethodGroup
				(ILTypeGetDelegateMethod(CSSemGetType(method)));
		CSSemSetMethodGroup(method, group);
	}
	else if(!CSSemIsMethodGroup(method))
	{
		CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
					  "called object is not a method or delegate");
		return CSSemValueDefault;
	}

	/* Bail out if the method group is NULL.  This is used by "BaseInit"
	   to indicate no parent constructor in "System.Object" */
	if(CSSemGetGroup(method) == 0)
	{
		if(node->expr2)
		{
			/* Cannot use arguments on "System.Object"'s base initializer */
			CCErrorOnLine(yygetfilename(node->expr2),
						  yygetlinenum(node->expr2),
						  "too many arguments to base type constructor");
		}
		return CSSemValueDefault;
	}

	/* Evaluate the arguments */
	numArgs = CSEvalArguments(info, node->expr2, &(node->expr2), &args);
	if(numArgs < 0)
	{
		return CSSemValueDefault;
	}

	/* Find the set of candidate methods */
	ReduceMethodGroup(info, args, numArgs, &method);

	/* If there are no candidates left, then bail out */
	itemNum = 0;
	itemInfo = CSGetGroupMember(CSSemGetGroup(method), itemNum);
	if(!itemInfo && savedNode != NULL)
	{
		/* 
		 * Note: if there are no candidates, and it is a member access
		 * try checking if it is a static member invocation
		 */
		node->expr1 = (ILNode*)savedNode;
		savedNode->expr1 = savedChild1;
		savedNode->expr2 = savedChild2;

		info->inSemStatic = 1;
		method = ILNode_SemAnalysis(node->expr1,info, &(node->expr1)); 
		info->inSemStatic = 0;

		if(!CSSemIsMethodGroup(method))
		{
			CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
						  "called object is not a method or delegate");
			return CSSemValueDefault;
		}
		if(CSSemGetGroup(method) == 0)
		{
			return CSSemValueDefault;
		}
		
		/* Find the set of candidate methods */
		ReduceMethodGroup(info, args, numArgs, &method);

		itemInfo = CSGetGroupMember(CSSemGetGroup(method), 0);
	}

	/* if we get here *again* without an iteminfo,  we're actually
		missing a method */

	if(!itemInfo)
	{
		CSItemCandidateError((ILNode *)node, itemName, isCtor,
						     CSSemGetGroup(method), args, numArgs);
		CSEvalFreeArguments(args);
		return CSSemValueDefault;
	}

	/* There are two or more candidates, then try to find the best one */
	if(CSGetGroupMember(CSSemGetGroup(method), 1) != 0)
	{
		itemInfo = CSBestCandidate(info, CSSemGetGroup(method),
								   args, numArgs);
		if(!itemInfo)
		{
			CSItemCandidateError((ILNode *)node, itemName, isCtor,
							     CSSemGetGroup(method), args, numArgs);
			CSEvalFreeArguments(args);
			return CSSemValueDefault;
		}
	}

	/* Import the method into this image, and set it within the node */
	methodInfo = (ILMethod *)itemInfo;
	methodInfo = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)methodInfo);
	node->methodInfo = methodInfo;
	node->baseCall = CSSemIsBase(method);

	/* Create a call site signature if we have vararg parameters */
	if(numArgs > 0 && args[numArgs - 1].modifier == ILParamMod_arglist)
	{
		ILNode_Argument *arg = (ILNode_Argument *)(args[numArgs - 1].node);
		ILNode_VarArgExpand *arglist =
				((ILNode_VarArgExpand *)(arg->expression));
		node->callSiteSig = MakeCallSiteSig
			(info, ILMethod_Signature(methodInfo), arglist->varArgTypes);
	}

	/* Handle the "this" parameter if necessary */
	if(!ILMethod_IsStatic(methodInfo))
	{
		node->thisExpr = node->expr1;
		if(yyisa(node->thisExpr, ILNode_This) ||
		   (yyisa(node->thisExpr, ILNode_MarkType) &&
		    yyisa(((ILNode_MarkType *)(node->thisExpr))->expr, ILNode_This)))
		{
			caller = (ILNode_MethodDeclaration *)(info->currentMethod);
			if(!caller || (caller->modifiers & IL_META_METHODDEF_STATIC) != 0)
			{
				/* Attempt to call an instance method using "this"
				   from within a static method */
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "cannot access instance members in static methods");
			}
		}
	}

	/* Coerce the arguments and build the final argument list */
	retType = CSItemCoerceArgs(info, ILToProgramItem(methodInfo),
							   args, numArgs, &(node->expr2));
	CSEvalFreeArguments(args);

	/* The semantic value is the method's return type as an r-value */
	if(retType == ILType_Void)
	{
		CSSemSetVoid(value);
	}
	else
	{
		CSSemSetRValue(value, retType);
	}
	return value;
}
#line 7702 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_124__(ILNode_StackAlloc *node, ILGenInfo * info, ILNode * * parent)
#line 299 "cs_misc.tc"
{
	CSSemValue value1;
	CSSemValue value2;

	/* Print an error or warning for this construct if necessary */
	CCUnsafeMessage(info, (ILNode *)node, "unsafe `stackalloc' operator");

	/* Perform semantic analysis on the sub-expressions */
	value1 = ILNode_SemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_SemAnalysis(node->expr2, info, &(node->expr2));

	/* The first must be a value type */
	if(!CSSemIsType(value1))
	{
		/* TODO */
	}

	/* The second must be an "int" */
	/* TODO */

	/* The result has the type "pointer to value1.type" */
	CSSemSetRValue(value1, ILType_Int32);	/* TODO */
	return value1;
}
#line 7730 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_125__(ILNode_Conditional *node, ILGenInfo * info, ILNode * * parent)
#line 2280 "cs_oper.tc"
{
	CSSemValue value1;
	CSSemValue value2;

	/* Perform semantic analysis on the boolean condition */
	ILNode_SemAnalysis(node->expr1, info, &(node->expr1));

	/* Perform semantic analysis on the "then" and "else" clauses */
	if(!CSSemExpectValue(node->expr2, info, &(node->expr2), &value1) ||
	   !CSSemExpectValue(node->expr3, info, &(node->expr3), &value2))
	{
		goto error;
	}

	/* If the types are the same, then we are done */
	if(ILTypeIdentical(CSSemGetType(value1), CSSemGetType(value2)))
	{
		CSSemSetRValue(value1, CSSemGetType(value1));
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Determine which of the types is the result type */
	if(ILCanCoerceNode(info, node->expr2, CSSemGetType(value1),
					   CSSemGetType(value2),1) &&
	   !ILCanCoerceNode(info, node->expr3, CSSemGetType(value2),
	   					CSSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), CSSemGetType(value1),
				 CSSemGetType(value2),1);
		CSSemSetRValue(value2, CSSemGetType(value2));
		EvalOperator(info, *parent, parent, &value2);
		return value2;
	}
	else if(ILCanCoerceNode(info, node->expr3, CSSemGetType(value2),
							CSSemGetType(value1),1) &&
	        !ILCanCoerceNode(info, node->expr2, CSSemGetType(value1),
							 CSSemGetType(value2),1))
	{
		ILCoerce(info, node->expr3, &(node->expr3), CSSemGetType(value2),
				 CSSemGetType(value1),1);
		CSSemSetRValue(value1, CSSemGetType(value1));
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Report an error with the arguments to "?:" */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to ternary `?:'");
	CSSemSetRValue(value1, ILType_Int32);
	return value1;
}
#line 7787 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_126__(ILNode_AssignAdd *node, ILGenInfo * info, ILNode * * parent)
#line 1249 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Add, "op_Addition", "+");
}
#line 7795 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_127__(ILNode_AssignSub *node, ILGenInfo * info, ILNode * * parent)
#line 1258 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Sub, "op_Subtraction", "-");
}
#line 7803 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_128__(ILNode_AssignMul *node, ILGenInfo * info, ILNode * * parent)
#line 1267 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Mul, "op_Multiply", "*");
}
#line 7811 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_129__(ILNode_AssignDiv *node, ILGenInfo * info, ILNode * * parent)
#line 1276 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Div, "op_Division", "/");
}
#line 7819 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_130__(ILNode_AssignRem *node, ILGenInfo * info, ILNode * * parent)
#line 1285 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Rem, "op_Modulus", "%");
}
#line 7827 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_131__(ILNode_AssignAnd *node, ILGenInfo * info, ILNode * * parent)
#line 1294 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_And, "op_BitwiseAnd", "&");
}
#line 7835 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_132__(ILNode_AssignOr *node, ILGenInfo * info, ILNode * * parent)
#line 1312 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Or, "op_BitwiseOr", "|");
}
#line 7843 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_133__(ILNode_AssignXor *node, ILGenInfo * info, ILNode * * parent)
#line 1303 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Xor, "op_ExclusiveOr", "^");
}
#line 7851 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_134__(ILNode_AssignShl *node, ILGenInfo * info, ILNode * * parent)
#line 1321 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Shl, "op_LeftShift", "<<");
}
#line 7859 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_135__(ILNode_AssignShr *node, ILGenInfo * info, ILNode * * parent)
#line 1330 "cs_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Shr, "op_RightShift", ">>");
}
#line 7867 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_136__(ILNode_AssignUShr *node, ILGenInfo * info, ILNode * * parent)
#line 1339 "cs_oper.tc"
{
	/* C# does not have an unsigned right shift, so use the signed version */
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Shr, "op_RightShift", ">>");
}
#line 7876 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_137__(ILNode_VarArgList *node, ILGenInfo * info, ILNode * * parent)
#line 107 "cs_invoke.tc"
{
	CSSemValue value;
	ILNode_MethodDeclaration *decl;
	ILMethod *method;

	/* We cannot use "__arglist" when compiling to Java bytecode */
	if(info->outputIsJava)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "`__arglist' is disallowed when compiling to Java bytecode");
	}

	/* We can only use this inside "vararg" methods */
	decl = ((ILNode_MethodDeclaration *)(info->currentMethod));
	method = (decl ? decl->methodInfo : 0);
	if(!method ||
	   (ILMethodGetCallConv(method) & IL_META_CALLCONV_MASK)
	   		!= IL_META_CALLCONV_VARARG)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`__arglist' must be used inside a vararg method");
	}

	/* Construct the result type and return it */
	CSSemSetRValue(value, ILFindSystemType(info, "RuntimeArgumentHandle"));
	return value;
}
#line 7907 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_138__(ILNode_Argument *node, ILGenInfo * info, ILNode * * parent)
#line 148 "cs_invoke.tc"
{
	CSSemValue value;
	value = ILNode_SemAnalysis(node->expression, info, &(node->expression));
	if(node->modifier == ILParamMod_out ||
	   node->modifier == ILParamMod_ref)
	{
		if(!CSSemIsLValue(value) ||
		   yyisa(node->expression, ILNode_LValueNoRef))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid lvalue in `%s' argument",
						  (node->modifier == ILParamMod_out
						  		? "out" : "ref"));
			if(CSSemIsRValue(value) || CSSemIsSValue(value))
			{
				CSSemSetLValue(value, CSSemGetType(value));
			}
			else
			{
				CSSemSetLValue(value, ILType_Int32);
			}
		}
		if(info->outputIsJava)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "`%s' arguments not permitted when compiling to Java bytecode",
			  (node->modifier == ILParamMod_out ? "out" : "ref"));
		}
	}
	return value;
}
#line 7942 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_139__(ILNode_ArgArray *node, ILGenInfo * info, ILNode * * parent)
#line 1068 "cs_invoke.tc"
{
	/* This will never be called */
	return CSSemValueDefault;
}
#line 7950 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_140__(ILNode_As *node, ILGenInfo * info, ILNode * * parent)
#line 2682 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7957 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_141__(ILNode_Is *node, ILGenInfo * info, ILNode * * parent)
#line 2690 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7964 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_142__(ILNode_Box *node, ILGenInfo * info, ILNode * * parent)
#line 2616 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7971 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_143__(ILNode_Unbox *node, ILGenInfo * info, ILNode * * parent)
#line 2624 "cs_oper.tc"
{
	return CSSemValueDefault;
}
#line 7978 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_144__(ILNode_Error *node, ILGenInfo * info, ILNode * * parent)
#line 2503 "cs_oper.tc"
{
	return CSSemValueError;
}
#line 7985 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_145__(ILNode_NewExpression *node, ILGenInfo * info, ILNode * * parent)
#line 325 "cs_misc.tc"
{
	CSSemValue value;
	ILNode_ListIter iter;
	ILNode *child;
	ILNode *expr;
	ILNode **parentNode;
	ILNode **parentOfExpr;
	ILEvalValue evalValue;
	int numDimensions = 0;
	int dim;
	ILType *elemType;

	/* Determine if the array creation is normal or initializer-based */
	if(node->indexes)
	{
		/* Build the full type node, by combining the element
		   type, indexed dimensions, and the rank specifiers */
		if(yyisa(node->type, ILNode_ArrayType))
		{
			/* Cannot use array types in this context */
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
						  "invalid array element type");
		}
		node->type =
			ILNode_ArrayType_create(node->type, CountArgList(node->indexes));
		ILNode_ListIter_Init(&iter, node->rank);
		while((child = ILNode_ListIter_Next(&iter)) != 0)
		{
			node->type = ILNode_ArrayType_create
				(node->type, ((ILNode_TypeSuffix *)child)->count);
		}

		/* Perform semantic analysis on the array type */
		node->arrayType = CSSemType(node->type, info, &(node->type));

		/* Perform semantic analysis on the array dimensions */
		child = node->indexes;
		parentOfExpr = &(node->indexes);
		while(yyisa(child, ILNode_ArgList))
		{
			++numDimensions;
			expr = ((ILNode_ArgList *)child)->expr2;
			parentNode = &(((ILNode_ArgList *)child)->expr2);
			if(CSSemExpectValue(expr, info, parentNode, &value))
			{
				if(!ILCoerce(info, *parentNode, parentNode,
							 CSSemGetType(value), ILType_Int32,1) &&
				   !ILCoerce(info, *parentNode, parentNode,
							 CSSemGetType(value), ILType_UInt32,1) &&
				   !ILCoerce(info, *parentNode, parentNode,
							 CSSemGetType(value), ILType_Int64,1) &&
				   !ILCoerce(info, *parentNode, parentNode,
							 CSSemGetType(value), ILType_UInt64,1))
				{
					CCErrorOnLine
						(yygetfilename(expr), yygetlinenum(expr),
			  			 "incompatible types in dimension specifier: "
						 	"no conversion from `%s' to `int', `uint', "
							"`long', or `ulong'",
					     CSTypeToName(CSSemGetType(value)));
				}
			}
			else
			{
				CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
							  "invalid dimension in array creation expression");
			}
			parentOfExpr = &(((ILNode_ArgList *)child)->expr1);
			child = *parentOfExpr;
		}
		++numDimensions;
		expr = child;
		parentNode = parentOfExpr;
		if(CSSemExpectValue(expr, info, parentNode, &value))
		{
			if(!ILCoerce(info, *parentNode, parentNode,
						 CSSemGetType(value), ILType_Int32,1) &&
			   !ILCoerce(info, *parentNode, parentNode,
						 CSSemGetType(value), ILType_UInt32,1) &&
			   !ILCoerce(info, *parentNode, parentNode,
						 CSSemGetType(value), ILType_Int64,1) &&
			   !ILCoerce(info, *parentNode, parentNode,
						 CSSemGetType(value), ILType_UInt64,1))
			{
				CCErrorOnLine
					(yygetfilename(expr), yygetlinenum(expr),
		  			 "incompatible types in dimension specifier: "
					 	"no conversion from `%s' to `int', `uint', "
						"`long', or `ulong'",
				     CSTypeToName(CSSemGetType(value)));
			}
		}
		else
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  "invalid dimension in array creation expression");
		}
	}
	else
	{
		/* Perform semantic analysis on the array type, which is
		   assumed to already have rank specifiers */
		node->arrayType = CSSemType(node->type, info, &(node->type));

		/* Check that the supplied type is actually an array */
		if(!ILType_IsArray(node->arrayType))
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
						  "array initializer used with non-array type");
			CSSemSetRValue(value, node->arrayType);
			return value;
		}
	}

	/* Check that the element type has a class form associated with it.
	   If we are compiling in a "no floating point" profile, the
	   "System.Single" and "System.Double" classes won't exist, which
	   will lead to problems during the code generation phase */
	elemType = ILTypeGetElemType(node->arrayType);
	if(!ILTypeToClass(info, elemType))
	{
		CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
					  "array of `%s' used in a profile that cannot support it",
					  CSTypeToName(elemType));
	}

	/* Handle array initializers */
	if(node->arrayInitializer)
	{
		/* Wrap the initializer in an "ILNode_ArrayInit" node */
		node->arrayInitializer =
				ILNode_ArrayInit_create(node->arrayInitializer);

		/* Validate the initializer's shape against the actual type,
		   and then coerce all of the elements to their final types */
		if(!ILArrayInitShapeOK(info, node->arrayInitializer, node->arrayType))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "incorrect pattern of elements in array initializer");
		}
		else
		{
			CoerceArrayInit(info, node->arrayInitializer,
							&(node->arrayInitializer),
						    ILTypeGetElemType(node->arrayType));
		}

		/* If we have indices, then they must be constant and match
		   the sizes of the initializer dimensions */
		if(node->indexes)
		{
			dim = numDimensions;
			child = node->indexes;
			while(yyisa(child, ILNode_ArgList))
			{
				expr = ((ILNode_ArgList *)child)->expr2;
				if(!ILNode_EvalConst(expr, info, &evalValue) ||
				   !ILGenCastConst(info, &evalValue, evalValue.valueType,
								   ILMachineType_Int64) ||
				   evalValue.un.i8Value !=
				   		(ILInt64)ILGetArrayInitLength
							(((ILNode_ArrayInit *)(node->arrayInitializer))
									->expr, dim - 1))
				{
					CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  "dimension %d does not match initializer", dim);
				}
				child = (((ILNode_ArgList *)child)->expr1);
				--dim;
			}
			expr = child;
			if(!ILNode_EvalConst(expr, info, &evalValue) ||
			   !ILGenCastConst(info, &evalValue, evalValue.valueType,
							   ILMachineType_Int64) ||
			   evalValue.un.i8Value !=
			   		(ILInt64)ILGetArrayInitLength
						(((ILNode_ArrayInit *)(node->arrayInitializer))
								->expr, dim - 1))
			{
				CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
					  "dimension %d does not match initializer", dim);
			}
		}

		/* Replace the current node with the initializer node */
		*parent = node->arrayInitializer;
	}

	/* Done */
	CSSemSetRValue(value, node->arrayType);
	return value;
}
#line 8181 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_146__(ILNode_ObjectCreationExpression *node, ILGenInfo * info, ILNode * * parent)
#line 713 "cs_invoke.tc"
{
	CSSemValue value;
	CSSemValue method;
	ILProgramItem *itemInfo;
	ILMethod *methodInfo;
	ILType *objectType;
	ILType *mainType;
	ILClass *objectClass;
	CSEvalArg *args;
	int numArgs;
	unsigned long itemNum;
	int candidateForm;

	/* Perform semantic analysis on the type */
	objectType = CSSemTypeLiteral(node->type, info, &(node->type));

	/* Set up the default return value */
	CSSemSetRValue(value, objectType);

	/* Get the main type, after stripping "with" parameters */
	if(ILType_IsWith(objectType))
	{
		mainType = ILTypeGetWithMain(objectType);
	}
	else
	{
		mainType = objectType;
	}

	/* The type must be a delegate, a non-abstract class, or a value type */
	if(ILTypeIsDelegate(objectType))
	{
		/* Delegate creation is not supported with Java output */
		if(info->outputIsJava)
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  			  "delegate creation disallowed when compiling to "
						  "Java bytecode");
			return value;
		}

		/* Delegate creation expressions must have a single argument */
		if(!(node->argList) || yyisa(node->argList, ILNode_ArgList))
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  			  "invalid delegate creation expression for `%s'",
			  			  CSTypeToName(objectType));
			return value;
		}

		/* Perform semantic analysis on the delegate creation */
		return DelegateCreationSem(info, (ILNode *)node, objectType,
								   node->argList, parent);
	}
	else if(ILType_IsClass(mainType))
	{
		objectClass = ILClassResolve(ILType_ToClass(mainType));
		if(ILClass_IsInterface(objectClass))
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  "cannot instantiate interface `%s' with the `new' operator",
			  CSTypeToName(objectType));
			return value;
		}
		else if(ILClass_IsAbstract(objectClass))
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  "cannot instantiate abstract class `%s' with the `new' operator",
			  CSTypeToName(objectType));
			return value;
		}
	}
	else if(ILTypeIsValue(mainType))
	{
		/* Check for the default constructor case */
		if(!(node->argList))
		{
			/* Replace this node with a default constructor call */
			*parent = ILNode_DefaultConstructor_create(0, objectType, 0);
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
			return value;
		}
	}
	else if(ILType_IsTypeParameter(objectType) ||
			ILType_IsMethodParameter(objectType))
	{
		/* Can only use zero-argument constructors with generic parameters */
		if(node->argList)
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
				  		  "`%s' cannot be constructed with arguments",
						  CSTypeToName(objectType));
			return value;
		}
		*parent = ILNode_DefaultConstructor_create(0, objectType, 1);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return value;
	}
	else
	{
		CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  		  "`%s' is not a class or value type",
					  CSTypeToName(objectType));
		return value;
	}

	/* Get the list of accessible constructors for the type */
	method = CSResolveConstructor(info, node->type, objectType);
	if(!CSSemIsMethodGroup(method))
	{
		CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
					  "`%s' does not have an accessible constructor",
					  CSTypeToName(objectType));
		return value;
	}

	/* Evaluate the arguments */
	numArgs = CSEvalArguments(info, node->argList, &(node->argList), &args);
	if(numArgs < 0)
	{
		return value;
	}

	/* Find the set of candidate methods */
	itemNum = 0;
	while((itemInfo = CSGetGroupMember(CSSemGetGroup(method), itemNum)) != 0)
	{
		candidateForm = CSItemIsCandidate(info, itemInfo, args, numArgs);
		if(candidateForm)
		{
			CSSetGroupMemberForm(CSSemGetGroup(method), itemNum,
								 candidateForm);
			++itemNum;
		}
		else
		{
			CSSemModifyGroup(method, CSRemoveGroupMember
								(CSSemGetGroup(method), itemNum));
		}
	}

	/* If there are no candidates left, then bail out */
	itemNum = 0;
	itemInfo = CSGetGroupMember(CSSemGetGroup(method), itemNum);
	if(!itemInfo)
	{
		CSItemCandidateError((ILNode *)node, 0, 1,
						     CSSemGetGroup(method), args, numArgs);
		CSEvalFreeArguments(args);
		return value;
	}

	/* There are two or more candidates, then try to find the best one */
	if(CSGetGroupMember(CSSemGetGroup(method), 1) != 0)
	{
		itemInfo = CSBestCandidate(info, CSSemGetGroup(method),
								   args, numArgs);
		if(!itemInfo)
		{
			CSItemCandidateError((ILNode *)node, 0, 1,
							     CSSemGetGroup(method), args, numArgs);
			CSEvalFreeArguments(args);
			return value;
		}
	}

	/* Import the method into this image, and set it within the node */
	methodInfo = (ILMethod *)itemInfo;
	methodInfo = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)methodInfo);
	node->methodInfo = methodInfo;

	/* Create a call site signature if we have vararg parameters */
	if(numArgs > 0 && args[numArgs - 1].modifier == ILParamMod_arglist)
	{
		ILNode_Argument *arg = (ILNode_Argument *)(args[numArgs - 1].node);
		ILNode_VarArgExpand *arglist =
				((ILNode_VarArgExpand *)(arg->expression));
		node->callSiteSig = MakeCallSiteSig
			(info, ILMethod_Signature(methodInfo), arglist->varArgTypes);
	}

	/* Coerce the arguments and build the final argument list */
	CSItemCoerceArgs(info, ILToProgramItem(methodInfo),
					 args, numArgs, &(node->argList));
	CSEvalFreeArguments(args);

	/* Return the final semantic value */
	return value;
}
#line 8377 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_147__(ILNode_DelegateCreationExpression *node, ILGenInfo * info, ILNode * * parent)
#line 910 "cs_invoke.tc"
{
	/* This is a dummy: it won't be called in practice */
	return CSSemValueDefault;
}
#line 8385 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_148__(ILNode_DefaultConstructor *node, ILGenInfo * info, ILNode * * parent)
#line 919 "cs_invoke.tc"
{
	ILEvalValue evalValue;
	CSSemValue value;

	/* Evaluate the type sub-expression */
	node->type = CSSemType(node->expr, info, &(node->expr));

	/* Perform constant evaluation */
	if(ILTypeIsReference(node->type))
	{
		evalValue.valueType = ILMachineType_ObjectRef;
		evalValue.un.oValue = 0;
		CSSemSetConstant(value, node->type, evalValue);
	}
	else
	{
		evalValue.valueType = ILTypeToMachineType(node->type);
		switch(evalValue.valueType)
		{
			case ILMachineType_Boolean:
			case ILMachineType_Int8:
			case ILMachineType_UInt8:
			case ILMachineType_Int16:
			case ILMachineType_UInt16:
			case ILMachineType_Char:
			case ILMachineType_Int32:
			case ILMachineType_UInt32:
			{
				evalValue.un.i4Value = 0;
			}
			break;
	
			case ILMachineType_Int64:
			case ILMachineType_UInt64:
			{
				evalValue.un.i8Value = 0;
			}
			break;
	
			case ILMachineType_Float32:
			{
				evalValue.un.r4Value = (ILFloat)0.0;
			}
			break;
	
			case ILMachineType_Float64:
			{
				evalValue.un.r8Value = (ILDouble)0.0;
			}
			break;
	
			case ILMachineType_Decimal:
			{
				ILDecimalFromInt32(&(evalValue.un.decValue), 0);
			}
			break;
	
			default:
			{
				CSSemSetRValue(value, node->type);
				return value;
			}
			/* Not reached */
		}
		CSSemSetConstant(value, node->type, evalValue);
	}

	/* Return the final semantic value to the caller */
	return value;
}
#line 8459 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_149__(ILNode_BaseInit *node, ILGenInfo * info, ILNode * * parent)
#line 994 "cs_invoke.tc"
{
	CSSemValue value;
	ILClass *classInfo;
	ILClass *parentInfo;

	/* If we are compiling "System.Object", then we need to
	   bail out with an empty method group.  This tells
	   "InvocationExpression" to ignore the call */
	classInfo = ((ILNode_ClassDefn *)(info->currentClass))->classInfo;
	parentInfo = (classInfo ? ILClass_Parent(classInfo) : 0);
	if(!parentInfo)
	{
		CSSemSetMethodGroup(value, 0);
		return value;
	}

	/* If the current class is a value type, then bail out.
	   We don't want to call the base class constructor
	   in this case */
	if(ILClassIsValueType(classInfo))
	{
		CSSemSetMethodGroup(value, 0);
		return value;
	}

	/* Resolve the constructor within the base class */
	CSSemSetRValue(value, ILType_FromClass(parentInfo));
	value = CSResolveConstructor(info, (ILNode *)node, CSSemGetType(value));

	/* Report an error if we could not find any accessible constructors */
	if(!CSSemIsMethodGroup(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no accessible base class constructors");
	}

	/* Replace the current expression with "this" */
	*parent = ILNode_This_create();
	CSSemSetBase(value);
	return value;
}
#line 8504 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_150__(ILNode_ThisInit *node, ILGenInfo * info, ILNode * * parent)
#line 1040 "cs_invoke.tc"
{
	CSSemValue value;
	ILClass *classInfo;

	/* Resolve the constructor within the current class */
	classInfo = ((ILNode_ClassDefn *)(info->currentClass))->classInfo;
	CSSemSetRValue(value, ILType_FromClass(classInfo));
	value = CSResolveConstructor(info, (ILNode *)node, CSSemGetType(value));

	/* Replace the current expression with "this" */
	*parent = ILNode_This_create();
	CSSemSetBase(value);
	return value;
}
#line 8522 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_151__(ILNode_NonStaticInit *node, ILGenInfo * info, ILNode * * parent)
#line 1059 "cs_invoke.tc"
{
	/* Non-static initializer calls are always "void" statements */
	return CSSemValueDefault;
}
#line 8530 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_152__(ILNode_EmptyExpr *node, ILGenInfo * info, ILNode * * parent)
#line 491 "cs_stmt.tc"
{
	/* We don't need to do anything here, as this node type is
	   synthesized by the "ILNode_Foreach" processing */
	return CSSemValueDefault;
}
#line 8539 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_153__(ILNode_Compound *node, ILGenInfo * info, ILNode * * parent)
#line 170 "cs_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *child;
	ILNode *replace;
	ILNode_ListIter_Init(&iter, node);
	while((child = ILNode_ListIter_Next(&iter)) != 0)
	{
		replace = child;
		StmtSem(child, info, &replace);
		if(replace != child)
		{
			*(iter.last) = replace;
		}
	}
	return CSSemValueDefault;
}
#line 8559 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_154__(ILNode_SwitchSectList *node, ILGenInfo * info, ILNode * * parent)
#line 1013 "cs_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return CSSemValueDefault;
}
#line 8567 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_155__(ILNode_CaseList *node, ILGenInfo * info, ILNode * * parent)
#line 1013 "cs_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return CSSemValueDefault;
}
#line 8575 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_156__(ILNode_List *node, ILGenInfo * info, ILNode * * parent)
#line 170 "cs_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *child;
	ILNode *replace;
	ILNode_ListIter_Init(&iter, node);
	while((child = ILNode_ListIter_Next(&iter)) != 0)
	{
		replace = child;
		StmtSem(child, info, &replace);
		if(replace != child)
		{
			*(iter.last) = replace;
		}
	}
	return CSSemValueDefault;
}
#line 8595 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_157__(ILNode_Empty *node, ILGenInfo * info, ILNode * * parent)
#line 161 "cs_stmt.tc"
{
	return CSSemValueDefault;
}
#line 8602 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_158__(ILNode_If *node, ILGenInfo * info, ILNode * * parent)
#line 195 "cs_stmt.tc"
{
	ILEvalValue evalValue;
	ILNode_SemAnalysis(node->expr, info, &(node->expr));
	StmtSem(node->thenClause, info, &(node->thenClause));
	StmtSem(node->elseClause, info, &(node->elseClause));
	
	/* the compiler does do the same optimisation lower down
	   the codegenerator , but that is not used for return 
	   value tracking */
	if(ILNode_EvalConst(node->expr, info, &evalValue))
	{
		if(evalValue.un.i4Value)
		{
			*parent = node->thenClause;
		}
		else
		{
			*parent = node->elseClause;
		}
	}
	return CSSemValueDefault;
}
#line 8628 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_159__(ILNode_While *node, ILGenInfo * info, ILNode * * parent)
#line 226 "cs_stmt.tc"
{
	ILNode_SemAnalysis(node->cond, info, &(node->cond));
	PushStmtContext(info, CS_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt));
	PopStmtContext(info);
	return CSSemValueDefault;
}
#line 8639 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_160__(ILNode_Do *node, ILGenInfo * info, ILNode * * parent)
#line 242 "cs_stmt.tc"
{
	PushStmtContext(info, CS_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt));
	PopStmtContext(info);
	ILNode_SemAnalysis(node->cond, info, &(node->cond));
	return CSSemValueDefault;
}
#line 8650 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_161__(ILNode_For *node, ILGenInfo * info, ILNode * * parent)
#line 258 "cs_stmt.tc"
{
	StmtSem(node->init, info, &(node->init));
	ILNode_SemAnalysis(node->cond, info, &(node->cond));
	StmtSem(node->incr, info, &(node->incr));
	PushStmtContext(info, CS_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt));
	PopStmtContext(info);
	return CSSemValueDefault;
}
#line 8663 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_162__(ILNode_Foreach *node, ILGenInfo * info, ILNode * * parent)
#line 272 "cs_stmt.tc"
{
	CSSemValue value;
	ILScope *scope;
	ILNode_MethodDeclaration *method;
	ILType *type;
	/* ForeachCollection */
	ILMethod *getEnumerator=NULL;
	ILProperty *property=NULL;
	ILMethod *getCurrent=NULL;
	ILMethod *moveNext=NULL;
	ILType *retType;
	ILType *enumerator;
	ILNode *castNode;
	ILClass *arrayClass;

	/* Locate the scope and method for the iteration variable */
	scope = info->currentScope;
	method = (ILNode_MethodDeclaration *)(info->currentMethod);

	/* Perform semantic analysis on the local variable type */
	if(CSHasUnsafeType(node->type))
	{
		CCUnsafeTypeMessage(info, (ILNode *)node);
	}
	type = CSSemType(node->type, info, &(node->type));

	/* Add the type to the local variable signature for this method */
	if(!(method->localVarSig))
	{
		method->localVarSig = ILTypeCreateLocalList(info->context);
		if(!(method->localVarSig))
		{
			CCOutOfMemory();
		}
	}
	if(!ILTypeAddLocal(info->context, method->localVarSig, type))
	{
		CCOutOfMemory();
	}

	/* Create a local variable entry in the current scope */
	/* TODO: the variable should be marked read-only */
	ILScopeDeclareLocal(info->currentScope, node->varName,
						ILTypeNumLocals(method->localVarSig) - 1,
						node->varNameNode);
	node->varIndex = ILTypeNumLocals(method->localVarSig) - 1;
	node->varType = ILTypeToMachineType(type);

	/* Perform semantic analysis on the collection expression */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node->expr), yygetlinenum(node->expr),
					  "invalid collection expression in `foreach' statement");
		node->arrayType = ILTypeCreateArray(info->context, 1, type);
		if(!(node->arrayType))
		{
			CCOutOfMemory();
		}
	}
	else
	{
		node->arrayType = CSSemGetType(value);
	}

	/* Perform semantic analysis on the body of the "foreach" statement */
	PushStmtContext(info, CS_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt));
	PopStmtContext(info);

	/* Is this a simple array-based or collection-based "foreach" statement? */
	node->elemType = ILTypeGetElemType(node->arrayType);
	if(ILType_IsSimpleArray(node->arrayType) &&
	   ILTypeIdentical(node->elemType, type))
	{
		/* The collection is a simple array and the iteration variable
		   has the same type as the array elements.  We can optimise
		   this case in the code generator to scan the array efficiently */
	}
	else if(ILType_IsSimpleArray(node->arrayType))
	{		
			castNode=ILNode_EmptyExpr_create
				(ILTypeToMachineType(node->elemType));
			if(!ILCast(info,castNode,&(castNode),node->elemType,type,1))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					"Cannot cast '%s' to '%s'",CSTypeToName(node->elemType),
					CSTypeToName(type));
			}
			node->doCast=castNode;
	}
	else if(ILTypeIsStringClass(node->arrayType) &&
	        ILTypeIdentical(type, ILType_Char))
	{
		/* The collection is a string, which we can special-case */
		*parent = ILNode_ForeachString_create(node->expr,
											  node->stmt,
											  node->varIndex,
											  node->varType);
	}
	else 
	{
		arrayClass = ILTypeToClass(info, node->arrayType);
		if(arrayClass)
		{
			getEnumerator = ILResolveInstanceMethod(info, arrayClass,
													GetDefaultScope(info),
													"GetEnumerator",
													NULL, 0);
		}
		if(getEnumerator==NULL &&
			ILTypeImplements(info, node->arrayType,
			ILFindNonSystemType(info,"IEnumerable","System.Collections")))
		{
			ILClass * enumerable = ILTypeToClass(info,
									ILFindNonSystemType(info,"IEnumerable",
													"System.Collections"));
			enumerable = ILClassResolve(enumerable);

			getEnumerator = ILResolveInstanceMethod(info, enumerable,
													GetDefaultScope(info),
													"GetEnumerator",
													NULL, 0);
		}	
		if(getEnumerator)
		{
			enumerator=ILTypeGetReturn(ILMethod_Signature(getEnumerator));
			property=ILResolveProperty(info,
							ILType_ToClass(enumerator),
							GetDefaultScope(info),
							"Current");
			
			getCurrent=(property ? ILProperty_Getter(property) : 0);

			moveNext=ILResolveInstanceMethod(info,
						ILType_ToClass(enumerator),
						GetDefaultScope(info),
						"MoveNext",	NULL, 0);

			if(!property) 
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						"Could not locate 'Current' or 'IEnumerator.Current'"
						"property in '%s'", CSTypeToName(enumerator));
			}
			else if(!getCurrent)
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  		"'Current' property has no 'get' method in '%s'",
					  CSTypeToName(enumerator));
			}
			if(!moveNext) 
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "Cannot locate 'MoveNext()' or 'IEnumerator.MoveNext()' in '%s'",
					  CSTypeToName(enumerator));
			}
			if(!getCurrent || !moveNext)
			{
				/* Bail out if we have insufficient interface support */
				return CSSemValueDefault;
			}
			
			retType=ILTypeGetReturn(ILMethod_Signature(getCurrent));

			if(ILTypeIdentical(type,retType))	
			{	
				*parent=ILNode_ForeachCollection_create(
						NULL,
						node->expr,
						node->stmt,
						node->arrayType,
						node->varIndex,
						ILTypeToMachineType(type),
						enumerator,
						getEnumerator,
						moveNext,
						getCurrent);
			}
			else
			{	
				castNode=ILNode_EmptyExpr_create(ILTypeToMachineType(retType));
				if(!ILCast(info,castNode,&(castNode),retType,type,1))
				{
					CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						"Cannot cast '%s' to '%s'",CSTypeToName(retType),
						CSTypeToName(type));
				}
				*parent=ILNode_ForeachCollection_create(
						castNode,
						node->expr,
						node->stmt,
						node->arrayType,
						node->varIndex,
						ILTypeToMachineType(type),
						enumerator,
						getEnumerator,
						moveNext,
						getCurrent);
			}
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			 "Could not locate a 'GetEnumerator' or "
			 "'IEnumerable.GetEnumerator' in '%s'"
			 ,CSTypeToName(node->arrayType));
		}
	}
	/* Done */
	return CSSemValueDefault;
}
#line 8878 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_163__(ILNode_ForeachString *node, ILGenInfo * info, ILNode * * parent)
#line 491 "cs_stmt.tc"
{
	/* We don't need to do anything here, as this node type is
	   synthesized by the "ILNode_Foreach" processing */
	return CSSemValueDefault;
}
#line 8887 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_164__(ILNode_ForeachCollection *node, ILGenInfo * info, ILNode * * parent)
#line 491 "cs_stmt.tc"
{
	/* We don't need to do anything here, as this node type is
	   synthesized by the "ILNode_Foreach" processing */
	return CSSemValueDefault;
}
#line 8896 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_165__(ILNode_Switch *node, ILGenInfo * info, ILNode * * parent)
#line 896 "cs_stmt.tc"
{
	static ILType * const governingTypes[] = {
		ILType_Int8, ILType_UInt8, ILType_Int16, ILType_UInt16,
		ILType_Int32, ILType_UInt32, ILType_Int64, ILType_UInt64, ILType_Char
	};
	#define numGoverningTypes	(sizeof(governingTypes) / sizeof(ILType *))
	CSSemValue value;
	ILType *actualType;
	ILType *switchType;
	ILType *stringType;
	int posn;
	unsigned long size;
	ILNode *savedSwitch;

	/* Perform semantic analysis on the expression */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node->expr), yygetlinenum(node->expr),
					  "invalid expression for `switch' statement");
		actualType = ILType_Int32;
	}
	else
	{
		actualType = CSSemGetType(value);
	}

	/* Determine the governing type for the switch */
	if(ILTypeIsEnum(actualType))
	{
		switchType = actualType;
	}
	else
	{
		switchType = actualType;
		for(posn = 0; posn < numGoverningTypes; ++posn)
		{
			if(ILCanCoerceKind(info, actualType, governingTypes[posn],
			   				   IL_CONVERT_USER_DEFINED,1))
			{
				switchType = governingTypes[posn];
				break;
			}
		}
		if(posn >= numGoverningTypes)
		{
			stringType = ILFindSystemType(info, "String");
			if(ILCanCoerceKind(info, actualType, stringType,
							   IL_CONVERT_USER_DEFINED,1))
			{
				switchType = stringType;
			}
			else
			{
				CCErrorOnLine(yygetfilename(node->expr),
					  yygetlinenum(node->expr),
					  "`%s' is invalid as the governing type for a `switch'",
					  CSTypeToName(actualType));
				return CSSemValueDefault;
			}
		}
	}

	/* Cast the switch expression to the governing type */
	ILCast(info, node->expr, &(node->expr), actualType, switchType,1);

	node->switchType=switchType;

	/* Enter the switch context */
	PushStmtContext(info, CS_STMT_SWITCH);
	savedSwitch=info->currentSwitch;
	info->currentSwitch=(ILNode*)node;

	/* Count the number of case labels and find the default case */
	node->numSwitchValues = CountLabelsAndFindDefault
			(node->sections, &(node->defaultSection));

	/* Allocate space for the switch value table */
	size = node->numSwitchValues * sizeof(ILSwitchValue);
	if(size > 1024)
	{
		/* Warning!  This will leak memory! */
		node->switchValues = (ILSwitchValue *)ILMalloc(size);
	}
	else
	{
		/* Allocate from the node pool, which will be cleaned up for us */
		node->switchValues = (ILSwitchValue *)yynodealloc((unsigned int)size);
	}
	if(!(node->switchValues))
	{
		CCOutOfMemory();
	}

	/* Perform semantic analysis on the switch body and compute the values */
	node->numSwitchValues = CollectCaseLabels(info, node->sections,
											  switchType, node->switchValues);

	/* Determine the type of switch table to generate */
	node->tableType = SwitchTableType(switchType, node->switchValues,
									  node->numSwitchValues);

	info->currentSwitch=savedSwitch;
	/* Leave the switch context */
	PopStmtContext(info);

	/* Done */
	return CSSemValueDefault;
}
#line 9008 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_166__(ILNode_Break *node, ILGenInfo * info, ILNode * * parent)
#line 1167 "cs_stmt.tc"
{
	PushStmtContext(info, CS_STMT_SWITCH);

	if(!StmtContextOK(info, CS_STMT_LOOP | CS_STMT_SWITCH, CS_STMT_FINALLY))
	{
		if(StmtContextOK(info, CS_STMT_FINALLY, 0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`break' used inside `finally' clause");
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`break' used outside loop or switch");
		}
	}
	return CSSemValueDefault;
}
#line 9030 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_167__(ILNode_LabelledBreak *node, ILGenInfo * info, ILNode * * parent)
#line 1167 "cs_stmt.tc"
{
	PushStmtContext(info, CS_STMT_SWITCH);

	if(!StmtContextOK(info, CS_STMT_LOOP | CS_STMT_SWITCH, CS_STMT_FINALLY))
	{
		if(StmtContextOK(info, CS_STMT_FINALLY, 0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`break' used inside `finally' clause");
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`break' used outside loop or switch");
		}
	}
	return CSSemValueDefault;
}
#line 9052 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_168__(ILNode_Continue *node, ILGenInfo * info, ILNode * * parent)
#line 1191 "cs_stmt.tc"
{
	if(!StmtContextOK(info, CS_STMT_LOOP, CS_STMT_FINALLY))
	{
		if(StmtContextOK(info, CS_STMT_FINALLY, 0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`continue' used inside `finally' clause");
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`continue' used outside loop");
		}
	}
	return CSSemValueDefault;
}
#line 9072 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_169__(ILNode_LabelledContinue *node, ILGenInfo * info, ILNode * * parent)
#line 1191 "cs_stmt.tc"
{
	if(!StmtContextOK(info, CS_STMT_LOOP, CS_STMT_FINALLY))
	{
		if(StmtContextOK(info, CS_STMT_FINALLY, 0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`continue' used inside `finally' clause");
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`continue' used outside loop");
		}
	}
	return CSSemValueDefault;
}
#line 9092 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_170__(ILNode_Return *node, ILGenInfo * info, ILNode * * parent)
#line 1212 "cs_stmt.tc"
{
	/* Emit an error if the return type is not "void" */
	ILType *returnType = ILTypeGetReturn(ILMethod_Signature
		(((ILNode_MethodDeclaration *)(info->currentMethod))->methodInfo));
	if(returnType != ILType_Void)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "`return' with no value, in method returning non-void");
	}
	if(!StmtContextOK(info, 0, CS_STMT_FINALLY))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  		  "`return' used inside `finally' clause");
	}
	return CSSemValueDefault;
}
#line 9112 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_171__(ILNode_ReturnExpr *node, ILGenInfo * info, ILNode * * parent)
#line 1233 "cs_stmt.tc"
{
	CSSemValue value;
	ILType *returnType;

	/* Perform semantic analysis on the expression */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid return value");
		return CSSemValueDefault;
	}

	/* Determine if the value is compatible with the return type */
	returnType = ILTypeGetReturn(ILMethod_Signature
		(((ILNode_MethodDeclaration *)(info->currentMethod))->methodInfo));
	if(returnType == ILType_Void)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`return' with a value, in method returning void");
	}
	else
	{
		/* Coerce to the return type */
		if(!ILCoerce(info, node->expr, &(node->expr),
					 CSSemGetType(value), returnType,1))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  		  "incompatible types in return: "
						  		"no conversion from `%s' to `%s'",
						  CSTypeToName(CSSemGetType(value)),
						  			   CSTypeToName(returnType));
		}
	}

	/* Check that the return was not used inside a "finally" clause */
	if(!StmtContextOK(info, 0, CS_STMT_FINALLY))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  		  "`return' used inside `finally' clause");
	}

	/* Done */
	return CSSemValueDefault;
}
#line 9160 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_172__(ILNode_Goto *node, ILGenInfo * info, ILNode * * parent)
#line 1022 "cs_stmt.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 9168 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_173__(ILNode_GotoLabel *node, ILGenInfo * info, ILNode * * parent)
#line 1031 "cs_stmt.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 9176 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_174__(ILNode_GotoCase *node, ILGenInfo * info, ILNode * * parent)
#line 1040 "cs_stmt.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	ILNode_Switch *switchExpr;
	ILMachineType switchMachineType;
	ILSwitchValue switchValue;
	unsigned long posn;

	if(!StmtContextOK(info, CS_STMT_SWITCH, CS_STMT_FINALLY))
	{
		if(StmtContextOK(info, CS_STMT_FINALLY, 0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`goto' used inside `finally' clause");
			return CSSemValueDefault;
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`goto' used outside switch");
			return CSSemValueDefault;
		}
	}

	/* if node->currentSwitch is NULL, then somebody messed up the 
	   PushStmtContext . It is a "bug detection" bug */
	/* Initialize */

	switchExpr=(ILNode_Switch*)(info->currentSwitch);
	switchMachineType = ILTypeToMachineType(switchExpr->switchType);


	if(!CSSemExpectValue(node->expr, info,
							 &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node->expr),
					  yygetlinenum(node->expr),
					  "invalid case label expression");
		return CSSemValueDefault;
	}
	/* Coerce the case expression to the governing type */
	if(!ILCoerce(info, node->expr, &(node->expr),
					 CSSemGetType(value), switchExpr->switchType,1))
	{
		CCErrorOnLine(yygetfilename(node->expr),
						  yygetlinenum(node->expr),
						  "no conversion from `%s' to `%s'",
						  CSTypeToName(CSSemGetType(value)),
						  CSTypeToName(switchExpr->switchType));
		return CSSemValueDefault;
	}
	
	/* Evaluate the constant value for the case expression */
	if(!ILNode_EvalConst(node->expr, info, &evalValue) ||
		   !ILGenCastConst(info, &evalValue, evalValue.valueType,
				   				   switchMachineType))
	{
		CCErrorOnLine(yygetfilename(node->expr),
						  yygetlinenum(node->expr),
						  "case expression is not constant");
		return CSSemValueDefault;
	}

	switchValue.value=evalValue;
	for(posn = 0; posn < switchExpr->numSwitchValues ; ++posn)
	{
		if(CompareCaseLabels(&(switchExpr->switchValues[posn]), 
			&(switchValue)) == 0)
		{
			node->switchSection=(ILNode_SwitchSection*)
					(switchExpr->switchValues[posn].section);
			if(node->switchSection->visited==ILVisitMode_Processing)
			{
				CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
				  "circularity in 'goto' detected");
			}
			return CSSemValueDefault;
		}
	}
	/* if we get here , the case entry was not locatable */
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "could not find a matching case for 'goto'");
	
	return CSSemValueDefault;
}
#line 9265 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_175__(ILNode_GotoDefault *node, ILGenInfo * info, ILNode * * parent)
#line 1130 "cs_stmt.tc"
{
	ILNode_SwitchSection *defaultSection;
	if(!StmtContextOK(info, CS_STMT_SWITCH, CS_STMT_FINALLY))
	{
		if(StmtContextOK(info, CS_STMT_FINALLY, 0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`goto' used inside `finally' clause");
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`goto' used outside switch");
		}
		return CSSemValueDefault;
	}
	defaultSection=(ILNode_SwitchSection*)
		(((ILNode_Switch*)info->currentSwitch)->defaultSection);
	if(!defaultSection)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no `default' case for switch");
		return CSSemValueDefault;
	}
	if(defaultSection->visited == ILVisitMode_Processing)
	{
		CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
		  "circularity in 'goto' detected");
	}
	return CSSemValueDefault;
}
#line 9300 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_176__(ILNode_NewScope *node, ILGenInfo * info, ILNode * * parent)
#line 76 "cs_lvalue.tc"
{
	ILScope *savedScope = info->currentScope;
	if(!(node->scope))
	{
		node->scope = ILScopeCreate(info, savedScope);
	}
	info->currentScope = node->scope;
	StmtSem(node->stmt, info, &(node->stmt));
	info->currentScope = savedScope;
	return CSSemValueDefault;
}
#line 9315 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_177__(ILNode_SwitchSection *node, ILGenInfo * info, ILNode * * parent)
#line 1013 "cs_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return CSSemValueDefault;
}
#line 9323 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_178__(ILNode_CaseLabel *node, ILGenInfo * info, ILNode * * parent)
#line 1013 "cs_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return CSSemValueDefault;
}
#line 9331 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_179__(ILNode_DefaultLabel *node, ILGenInfo * info, ILNode * * parent)
#line 1013 "cs_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return CSSemValueDefault;
}
#line 9339 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_180__(ILNode_Throw *node, ILGenInfo * info, ILNode * * parent)
#line 1282 "cs_stmt.tc"
{
	if(!StmtContextOK(info, CS_STMT_CATCH, CS_STMT_FINALLY | CS_STMT_TRY))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  "`throw' with no value must be used inside a `catch' clause");
	}
	return CSSemValueDefault;
}
#line 9351 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_181__(ILNode_ThrowExpr *node, ILGenInfo * info, ILNode * * parent)
#line 1295 "cs_stmt.tc"
{
	CSSemValue value;
	ILType *exceptionClass;

	/* Perform semantic analysis on the value */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  		  "invalid throw expression");
		CSSemSetRValue(value, ILType_Null);
	}

	/* Attempt to coerce the value to "System.Exception" */
	exceptionClass = ILFindSystemType(info, "Exception");
	if(!ILCoerce(info, node->expr, &(node->expr),
				 CSSemGetType(value), exceptionClass,1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  		  "no conversion from `%s' to `%s'",
					  CSTypeToName(CSSemGetType(value)),
					  CSTypeToName(exceptionClass));
	}

	/* Done */
	return CSSemValueDefault;
}
#line 9381 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_182__(ILNode_Try *node, ILGenInfo * info, ILNode * * parent)
#line 1326 "cs_stmt.tc"
{
	/* Enter a "try" context */
	PushStmtContext(info, CS_STMT_TRY);

	/* Perform semantic analysis on the "try" body */
	StmtSem(node->stmt, info, &(node->stmt));

	/* Perform semantic analysis on the "catch" clauses */
	StmtSem(node->catchClauses, info, &(node->catchClauses));

	/* Perform semantic analysis on the "finally" clause */
	StmtSem(node->finallyClause, info, &(node->finallyClause));

	/* Exit from the "try" context */
	PopStmtContext(info);

	/* Done */
	return CSSemValueDefault;
}
#line 9404 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_183__(ILNode_CatchClause *node, ILGenInfo * info, ILNode * * parent)
#line 1350 "cs_stmt.tc"
{
	ILType *exceptionType = ILFindSystemType(info, "Exception");
	ILType *thrownType;
	ILScope *newScope;
	ILNode_MethodDeclaration *method =
		(ILNode_MethodDeclaration *)(info->currentMethod);

	/* Enter a "catch" context */
	PushStmtContext(info, CS_STMT_CATCH);

	/* Wrap the catch body in a new scope */
	newScope = ILScopeCreate(info, info->currentScope);
	node->stmt = ILNode_NewScope_create(node->stmt);
	((ILNode_NewScope *)(node->stmt))->scope = newScope;

	/* Validate the thrown value type */
	if(node->type)
	{
		thrownType = CSSemType(node->type, info, &(node->type));
		if(!ILCanCoerce(info, thrownType, exceptionType,0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  		  		  "`%s' does not inherit from `%s'",
						  CSTypeToName(thrownType),
						  CSTypeToName(exceptionType));
			thrownType = exceptionType;
		}
	}
	else
	{
		thrownType = exceptionType;
	}
	node->classInfo = ILTypeToClass(info, thrownType);

	/* Declare a new local variable for the catch value */
	if(node->name)
	{
		/* Add the type to the local variable signature for this method */
		if(!(method->localVarSig))
		{
			method->localVarSig = ILTypeCreateLocalList(info->context);
			if(!(method->localVarSig))
			{
				CCOutOfMemory();
			}
		}
		if(!ILTypeAddLocal(info->context, method->localVarSig, thrownType))
		{
			CCOutOfMemory();
		}

		/* Create a local variable entry in the current scope */
		ILScopeDeclareLocal(newScope, node->name,
							ILTypeNumLocals(method->localVarSig) - 1,
							node->nameNode);

		/* Record the local variable index for the code generator */
		node->varIndex = ILTypeNumLocals(method->localVarSig) - 1;
	}

	/* Perform semantic analysis on the catch body */
	StmtSem(node->stmt, info, &(node->stmt));

	/* Exit from the "catch" context */
	PopStmtContext(info);

	/* Done */
	return CSSemValueDefault;
}
#line 9477 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_184__(ILNode_FinallyClause *node, ILGenInfo * info, ILNode * * parent)
#line 1424 "cs_stmt.tc"
{
	/* Enter a "finally" context */
	PushStmtContext(info, CS_STMT_FINALLY);

	/* Perform semantic analysis on the finally body */
	StmtSem(node->stmt, info, &(node->stmt));

	/* Exit from the "finally" context */
	PopStmtContext(info);

	/* Done */
	return CSSemValueDefault;
}
#line 9494 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_185__(ILNode_Lock *node, ILGenInfo * info, ILNode * * parent)
#line 1442 "cs_stmt.tc"
{
	CSSemValue value;
	ILType *objectType = ILFindSystemType(info, "Object");

	/* Perform semantic analysis on the lock expression */
	if(!CSSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node->expr), yygetlinenum(node->expr),
					  "invalid lock expression");
		CSSemSetRValue(value, objectType);
	}

	/* Coerce the lock expression to "System.Object" */
	if(!ILCoerce(info, node->expr, &(node->expr),
				 CSSemGetType(value), objectType,1))
	{
		CCErrorOnLine(yygetfilename(node->expr), yygetlinenum(node->expr),
					  "no conversion from `%s' to `%s'",
					  CSTypeToName(CSSemGetType(value)),
					  CSTypeToName(objectType));
	}

	/* Enter a "try" context */
	PushStmtContext(info, CS_STMT_TRY);

	/* Perform semantic analysis on the lock statement body */
	StmtSem(node->stmt, info, &(node->stmt));

	/* Exit from the "try" context */
	PopStmtContext(info);

	/* Done */
	return CSSemValueDefault;
}
#line 9532 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_186__(ILNode_LocalVarDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 1801 "cs_stmt.tc"
{
	ILType *type;
	ILNode_ListIter iter;
	ILNode *nameNode;
	char *name;
	ILScopeData *data;
	ILNode_MethodDeclaration *method;
	ILNode *errorNode;

	/* Locate the method that this local is declared within */
	method = (ILNode_MethodDeclaration *)(info->currentMethod);

	/* Perform semantic analysis on the local variable type */
	type = CSSemType(node->type, info, &(node->type));

	/* Scan through the variable names and declare them in the current scope */
	ILNode_ListIter_Init(&iter, node->varNames);
	while((nameNode = ILNode_ListIter_Next(&iter)) != 0)
	{
		name = ILQualIdentName(nameNode, 0);
		data = ILScopeLookup(info->currentScope, name, 0);
		if(data)
		{
			/* The name is already declared in this scope */
			CCErrorOnLine(yygetfilename(nameNode), yygetlinenum(nameNode),
						  "`%s' is already declared in this scope", name);
			errorNode = ILScopeDataGetNode(data);
			if(errorNode)
			{
				CCErrorOnLine(yygetfilename(errorNode), yygetlinenum(errorNode),
							  "previous declaration here");
			}
		}
		else
		{
			/* Add the type to the local variable signature for this method */
			if(!(method->localVarSig))
			{
				method->localVarSig = ILTypeCreateLocalList(info->context);
				if(!(method->localVarSig))
				{
					CCOutOfMemory();
				}
			}
			if(!ILTypeAddLocal(info->context, method->localVarSig, type))
			{
				CCOutOfMemory();
			}

			/* Create a local variable entry in the current scope */
			ILScopeDeclareLocal(info->currentScope, name,
								ILTypeNumLocals(method->localVarSig) - 1,
								nameNode);
		}
	}

	/* Return the default value to the caller */
	return CSSemValueDefault;
}
#line 9595 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_187__(ILNode_LocalConstDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 1865 "cs_stmt.tc"
{
	ILNode_ListIter iterator;
	ILNode_FieldDeclarator *decl;
	/* since Rhys said that this was a reuse of FieldDecl */
	CSSemValue value;
	ILEvalValue evalValue;
	ILType *type = CSSemType(node->type, info, &(node->type));
	char *name;
	ILScopeData *data;
	ILNode_MethodDeclaration *method;
	ILNode *errorNode;

	/* Locate the method that this local is declared within */
	method = (ILNode_MethodDeclaration *)(info->currentMethod);

	/* Perform semantic analysis on the local variable type */
	type = CSSemType(node->type, info, &(node->type));
		
	ILNode_ListIter_Init(&iterator, node->decls);
	while((decl = (ILNode_FieldDeclarator *)
						ILNode_ListIter_Next(&iterator)) != 0)
	{
		name = ILQualIdentName(decl->name, 0);

		if(!(decl->initializer) || !(decl->name))
		{
			CCErrorOnLine(yygetfilename(decl->initializer),
							  yygetlinenum(decl->initializer),
							  "no initializer value for const");
			continue;
		}
		/* Perform semantic analysis on the initializer value */
		value = ILNode_SemAnalysis(decl->initializer, info,
								   &(decl->initializer));
		if(!CSSemIsValue(value))
		{
			CCErrorOnLine(yygetfilename(decl->initializer),
						  yygetlinenum(decl->initializer),
						  "initializer is not a value");
			continue;
		}

		/* Make sure that the value is compatible with the field's type */
		if(!ILCoerce(info, decl->initializer, &(decl->initializer),
					 CSSemGetType(value), type,1))
		{
			CCErrorOnLine(yygetfilename(decl->initializer),
						  yygetlinenum(decl->initializer),
			  			  "incompatible types in initialization: "
			  					"no conversion from `%s' to `%s'",
			  			  CSTypeToName(CSSemGetType(value)),
						  CSTypeToName(type));
			continue;
		}

		/* Check that the literal value is actually constant */
		if(!ILNode_EvalConst(decl->initializer, info, &evalValue) ||
		   !ILGenCastConst(info, &evalValue, evalValue.valueType,
	                  ILTypeToMachineType(type)))
		{
			CCErrorOnLine(yygetfilename(decl->initializer),
						  yygetlinenum(decl->initializer),
						  "initializer is not constant");
			continue;
		}

		/* Guard the node from re-evaluation */
		decl->initializer=ILNode_SemGuard_create(decl->initializer,value);
		data = ILScopeLookup(info->currentScope, name, 0);
		if(data)
		{
			/* The name is already declared in this scope */
			CCErrorOnLine(yygetfilename(decl->name), yygetlinenum(decl->name),
						  "`%s' is already declared in this scope", name);
			errorNode = ILScopeDataGetNode(data);
			if(errorNode)
			{
				CCErrorOnLine(yygetfilename(errorNode), yygetlinenum(errorNode),
							  "previous declaration here");
			}
		}
		else
		{
			/* Create a local variable entry in the current scope */
			ILScopeDeclareLocalConst(info->currentScope, name,
			decl->initializer,decl->name);
		}
	}
	return CSSemValueDefault;
}
#line 9689 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_188__(ILNode_LineInfo *node, ILGenInfo * info, ILNode * * parent)
#line 1960 "cs_stmt.tc"
{
	return ILNode_SemAnalysis(node->stmt, info, &(node->stmt));
}
#line 9696 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_189__(ILNode_EventAddOrRemove *node, ILGenInfo * info, ILNode * * parent)
#line 1968 "cs_stmt.tc"
{
	/* Nothing to do here: this node is generated during semantic
	   analysis of the "+=" and "-=" operators */
	return CSSemValueDefault;
}
#line 9705 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_190__(ILNode_ClassDefn *node, ILGenInfo * info, ILNode * * parent)
#line 111 "cs_decls.tc"
{
	CSSemValue value;
	ILNode *savedClass;
	ILNode *savedNamespace;
	ILNode *savedMethod;
	ILNode *staticCtorList=NULL;
	ILNode *savedTypeFormals;
	ILNode_ListIter iter;
	ILNode *staticCtor;
	int hadStaticCtorsBefore;
	int target;

	/* Determine if we have already visited this node */
	if(node->visited == ILVisitMode_Processing)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "circularity detected in class definition");
		return CSSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return CSSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Process the attributes for the class */
	if(node->defaultMemberName)
	{
		CSAddDefaultMemberAttr(info, node->classInfo, node->defaultMemberName);
	}
	if(ILClass_IsInterface(node->classInfo))
	{
		target = CS_ATTR_INTERFACE;
	}
	else if(ILTypeIsEnum(ILType_FromValueType(node->classInfo)))
	{
		target = CS_ATTR_ENUM;
	}
	else if(ILTypeIsDelegate(ILType_FromClass(node->classInfo)))
	{
		target = CS_ATTR_DELEGATE;
	}
	else if(ILClassIsValueType(node->classInfo))
	{
		target = CS_ATTR_STRUCT;
	}
	else
	{
		target = CS_ATTR_CLASS;
	}
	if(node->attributes)
	{
		savedClass = info->currentClass;
		savedNamespace = info->currentNamespace;
		savedMethod = info->currentMethod;
		info->currentClass = (ILNode *)node;
		info->currentNamespace = node->namespaceNode;
		info->currentMethod = NULL;
		CSProcessAttrs(info, ILToProgramItem(node->classInfo),
					   node->attributes, target);
		info->currentClass = savedClass;
		info->currentNamespace = savedNamespace;
		info->currentMethod = savedMethod;
	}

	/* Perform semantic analysis on the node */
	hadStaticCtorsBefore = (node->staticCtors != 0);
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeEnter(info, (ILNode *)node, "unsafe class declaration");
	}
	if(node->body)
	{
		savedClass = info->currentClass;
		savedNamespace = info->currentNamespace;
		savedMethod = info->currentMethod;
		savedTypeFormals = info->currentTypeFormals;
		info->currentClass = (ILNode *)node;
		info->currentNamespace = node->namespaceNode;
		info->currentMethod = NULL;
		info->currentTypeFormals = node->typeFormals;
		value = ILNode_SemAnalysis(node->body, info, &(node->body));
		if(node->initCtorsMethod)
		{
			/* Perform semantic analysis on the non-static initializers */
			ILNode_SemAnalysis(node->initCtorsMethod, info,
							   &(node->initCtorsMethod));
		}

		/*  save the explicit static constructors before gathering  */
		if (node->staticCtors)
		{
			if(ILNode_List_Length(node->staticCtors)>1)
			{
				ILNode_ListIter_Init(&iter, node->staticCtors);
				ILNode_ListIter_Next(&iter); /* skip the first */
				while((staticCtor=ILNode_ListIter_Next(&iter))!=NULL)
				{
					CCErrorOnLine(yygetfilename(staticCtor),
									yygetlinenum(staticCtor), 
									"Cannot have more than one static "
									"constructor");
				}
			}
			staticCtorList=node->staticCtors;
		}

		node->staticCtors=ILNode_List_create();

		ILNode_Declaration_GatherStaticCtor
								(   (ILNode_Declaration *)node->body, 
									(ILNode_List *)node->staticCtors);

		/* append the explicit static constructors to the end of the 
		   gathered list */
		AppendStaticCtor((ILNode_List*)node->staticCtors,
						  (ILNode_List*) staticCtorList);

		staticCtorList=NULL; /* do not use it again or segfault :-) */

		if (ILNode_List_Length(node->staticCtors) == 0)
		{
			/*  There were no static constructors after all  */
			node->staticCtors = 0;
		}
		else
		{
			/* Create a method for the static constructors and
			   then perform semantic analysis on its contents */
			ILMethod *methodInfo;
			ILType *signature;
			node->staticCtorsMethod =
				ILNode_MethodDeclaration_create
					(0, IL_META_METHODDEF_PRIVATE |
						IL_META_METHODDEF_STATIC |
						IL_META_METHODDEF_HIDE_BY_SIG |
						IL_META_METHODDEF_SPECIAL_NAME |
						IL_META_METHODDEF_RT_SPECIAL_NAME,
					 0 /* void */,
					 ILQualIdentSimple(ILInternString(".cctor", 6).string),
					 0 /* no parameters */,
					 ILNode_NewScope_create(node->staticCtors));
			methodInfo = ILMethodCreate(node->classInfo, 0, ".cctor",
										IL_META_METHODDEF_PRIVATE |
										IL_META_METHODDEF_STATIC |
										IL_META_METHODDEF_HIDE_BY_SIG |
										IL_META_METHODDEF_SPECIAL_NAME |
										IL_META_METHODDEF_RT_SPECIAL_NAME);
			if(!methodInfo)
			{
				CCOutOfMemory();
			}
			signature = ILTypeCreateMethod(info->context, ILType_Void);
			if(!signature)
			{
				CCOutOfMemory();
			}
			ILMemberSetSignature((ILMember *)methodInfo, signature);
			((ILNode_MethodDeclaration *)(node->staticCtorsMethod))
					->methodInfo = methodInfo;
			ILNode_SemAnalysis(node->staticCtorsMethod, info,
							   &(node->staticCtorsMethod));
		}
		info->currentClass = savedClass;
		info->currentNamespace = savedNamespace;
		info->currentMethod = savedMethod;
		info->currentTypeFormals = savedTypeFormals;
	}
	else
	{
		CSSemSetRValue(value, ILType_Int32);
	}
	if(node->classInfo && !ILClass_IsInterface(node->classInfo))
	{
		/* Check that the class implements all of its interfaces */
		ILGenImplementsAllInterfaces(info, (ILNode *)node, node->classInfo,
									 InterfaceErrorFunc, InterfaceProxyFunc);
	}
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeLeave(info);
	}
	if(!hadStaticCtorsBefore && node->staticCtors)
	{
		/* The class contains static initializers for fields, but no
		   explicit static constructor.  Add the "beforefieldinit"
		   flag to the set of modifiers */
		node->modifiers |= IL_META_TYPEDEF_BEFORE_FIELD_INIT;
		if(node->classInfo)
		{
			ILClassSetAttrs(node->classInfo,
							IL_META_TYPEDEF_BEFORE_FIELD_INIT,
							IL_META_TYPEDEF_BEFORE_FIELD_INIT);
		}
	}

	/* We have finished processing this node */
	node->visited = ILVisitMode_Done;
	return CSSemValueDefault;
}
#line 9909 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_191__(ILNode_ScopeChange *node, ILGenInfo * info, ILNode * * parent)
#line 338 "cs_decls.tc"
{
	CSSemValue value;
	if (node->body)
	{
		ILScope *oldscope = info->currentScope;
		info->currentScope = node->scope;
		value = ILNode_SemAnalysis(node->body, info, &(node->body));
		info->currentScope = oldscope;
	}
	else
	{
		CSSemSetRValue(value, ILType_Int32);
	}
	return value;
}
#line 9928 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_192__(ILNode_FieldDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 673 "cs_decls.tc"
{
	ILNode_ListIter iterator;
	ILNode *decl;

	/* Enter an unsafe context for the field if necessary */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		if((node->modifiers & IL_META_FIELDDEF_LITERAL) != 0)
		{
			CCUnsafeEnter(info, (ILNode *)node, "unsafe constant declaration");
		}
		else
		{
			CCUnsafeEnter(info, (ILNode *)node, "unsafe field declaration");
		}
	}

	/* Warn if declaring the field with an unsafe type */
	if(CSHasUnsafeType(node->type))
	{
		CCUnsafeTypeMessage(info, (ILNode *)node);
	}

	/* Verify the initializers */
	ILNode_ListIter_Init(&iterator, node->fieldDeclarators);
	while((decl = ILNode_ListIter_Next(&iterator)) != 0)
	{
		ILNode_SemAnalysis(decl, info, &decl);
	}

	/* Leave the unsafe context for the field */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeLeave(info);
	}

	/* Fields don't really have a semantic value, so return the default */
	return CSSemValueDefault;
}
#line 9971 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_193__(ILNode_FieldDeclarator *node, ILGenInfo * info, ILNode * * parent)
#line 723 "cs_decls.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	ILNode *savedMethod;
	ILNode *initializer;

	savedMethod=info->currentMethod;

	/* Determine if we have already visited this node */
	if(node->visited == ILVisitMode_Processing)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "circularity detected in field definition");
		return CSSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return CSSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Process the field attributes */
	if(node->owner && node->fieldInfo)
	{
		CSProcessAttrs(info, ILToProgramItem(node->fieldInfo),
					   node->owner->attributes, CS_ATTR_FIELD);

		/* Reset the attributes, in case there are multiple fields */
		/* TODO: handle attrs for multiple fields in the same declaration */
		node->owner->attributes = 0;
	}

	/* Skip the field if no initializer or ILField block */
	if(!(node->initializer) || !(node->fieldInfo))
	{
		goto done;
	}
	
	info->currentMethod=NULL;

	/* Non-static fields are initialized differently */
	if(node->owner && (node->owner->modifiers & IL_META_FIELDDEF_STATIC) == 0)
	{
		/* non-static field initializers are not allowed in structs */	 
		if(ILClassIsValueType(((ILNode_ClassDefn *)info->currentClass)->classInfo))
		{
			if (node->initializer != NULL)
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node), 
							"Structs cannot have instance field initializers");

				return CSSemValueDefault;
			}
		}

		initializer = ILNode_Assign_create(node->name, node->initializer);
		yysetfilename(initializer,yygetfilename(node));
		yysetlinenum(initializer,yygetlinenum(node));
		
		CSAddInitCtor(info, initializer);
		goto done;
	}

	/* If this is a constant, then evaluate the value */
	if(node->owner && (node->owner->modifiers & IL_META_FIELDDEF_LITERAL) != 0)
	{
		/* Perform semantic analysis on the initializer value */
		value = ILNode_SemAnalysis(node->initializer, info,
								   &(node->initializer));
		if(!CSSemIsValue(value))
		{
			CCErrorOnLine(yygetfilename(node->initializer),
						  yygetlinenum(node->initializer),
						  "initializer is not a value");
			goto done;
		}

		/* Make sure that the value is compatible with the field's type */
		if(!ILCoerce(info, node->initializer, &(node->initializer),
					 CSSemGetType(value), ILField_Type(node->fieldInfo),1))
		{
			CCErrorOnLine(yygetfilename(node->initializer),
						  yygetlinenum(node->initializer),
			  			  "incompatible types in initialization: "
			  					"no conversion from `%s' to `%s'",
			  			  CSTypeToName(CSSemGetType(value)),
						  CSTypeToName(ILField_Type(node->fieldInfo)));
			goto done;
		}

		/* Check that the literal value is actually constant */
		if(!ILNode_EvalConst(node->initializer, info, &evalValue) ||
		   !ILGenCastConst(info, &evalValue, evalValue.valueType,
                   ILTypeToMachineType(ILField_Type(node->fieldInfo))))
		{
			CCErrorOnLine(yygetfilename(node->initializer),
						  yygetlinenum(node->initializer),
						  "initializer is not constant");
			goto done;
		}

		/* Decimal constants are stored in readonly fields
		   which are computed at runtime.  We also add a
		   "DecimalConstantAttribute" to tag the field so
		   that the compiler can reload the value later */
		if(evalValue.valueType == ILMachineType_Decimal)
		{
			ILMemberSetAttrs((ILMember *)(node->fieldInfo),
							 IL_META_FIELDDEF_LITERAL |
							 		IL_META_FIELDDEF_INIT_ONLY,
					 		 IL_META_FIELDDEF_INIT_ONLY);
			AddConstantValue(info, node->fieldInfo, &evalValue);
		}
		else
		{
			/* Record the constant value so the compiler can pick
			   it up when the binary form of the code is reloaded */
			AddConstantValue(info, node->fieldInfo, &evalValue);
			goto done;
		}

		/* Guard the initializer from further semantic analysis */
		node->initializer = ILNode_SemGuard_create(node->initializer, value);
	}

	/* Add a statement to the static constructor to initialize the field */
	/*	CSAddStaticCtor(info,  
	                 ILNode_Assign_create(node->name, node->initializer)); */

	initializer=ILNode_Assign_create(node->name, node->initializer);
	yysetfilename(initializer,yygetfilename(node));
	yysetlinenum(initializer,yygetlinenum(node));

	node->staticCtor = ILNode_NewScope_create(initializer);

done:
	/* Mark the node as done and return */
	info->currentMethod=savedMethod;
	node->visited = ILVisitMode_Done;
	return CSSemValueDefault;
}
#line 10116 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_194__(ILNode_EventDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 871 "cs_decls.tc"
{
	CSSemValue value = CSSemValueDefault;

	/* Enter an unsafe context for the event field if necessary */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeEnter(info, (ILNode *)node, "unsafe event declaration");
	}

	/* Warn if declaring the event field with an unsafe type */
	if(CSHasUnsafeType(node->type))
	{
		CCUnsafeTypeMessage(info, (ILNode *)node);
	}

	/* Perform semantic analysis on each of the event declarators */
	ILNode_SemAnalysis(node->eventDeclarators, info,
					   &(node->eventDeclarators));

	/* Leave the unsafe context for the event field */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeLeave(info);
	}

	return value;
}
#line 10147 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_195__(ILNode_EventDeclarator *node, ILGenInfo * info, ILNode * * parent)
#line 900 "cs_decls.tc"
{
	/* Process the event attributes */
	if(node->backLink)
	{
		CSProcessAttrs(info, ILToProgramItem(node->eventInfo),
					   node->backLink->attributes, CS_ATTR_EVENT);

		/* Reset the attributes, in case there are multiple events */
		/* TODO: handle attrs for multiple events in the same declaration */
		node->backLink->attributes = 0;
	}

	/* Perform semantic analysis on the "add" and "remove" methods */
	if(node->addAccessor)
	{
		ILNode_SemAnalysis(node->addAccessor, info, &(node->addAccessor));
	}
	if(node->removeAccessor)
	{
		ILNode_SemAnalysis(node->removeAccessor, info, &(node->removeAccessor));
	}
	return CSSemValueDefault;
}
#line 10174 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_196__(ILNode_ProxyDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 325 "cs_decls.tc"
{
	/* Nothing to do here */
	return CSSemValueDefault;
}
#line 10182 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_197__(ILNode_MethodDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 925 "cs_decls.tc"
{
	ILNode *savedMethod;
	ILNode_NewScope *newScope;
	ILScope *scope;
	ILScope *savedScope;
	unsigned long argNum;
	unsigned long argIndex;
	ILNode_ListIter iter;
	ILNode_FormalParameter *param;
	ILScopeData *data;
	char *name;
	ILNode *errorNode;
	ILType *returnType;

	/* Determine if we have already visited this node */
	if(node->visited == ILVisitMode_Processing)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "circularity detected in method definition");
		return CSSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return CSSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Process the attributes on the method */
	if(ILMethod_IsConstructor(node->methodInfo) ||
	   ILMethod_IsStaticConstructor(node->methodInfo))
	{
		CSProcessAttrs(info, ILToProgramItem(node->methodInfo),
					   node->attributes, CS_ATTR_CONSTRUCTOR);

		if (ILClassIsValueType(((ILNode_ClassDefn *)info->currentClass)->classInfo)
										&& ILMethod_IsConstructor(node->methodInfo))
		{
			int numParams = ILTypeNumParams(ILMethod_Signature(ILToProgramItem(node->methodInfo)));

			if(numParams == 0)
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						"Structs cannot contain explicit parameterless constructors");

				return CSSemValueDefault;
			}
		}
	}
	else
	{
		CSProcessAttrs(info, ILToProgramItem(node->methodInfo),
					   node->attributes, CS_ATTR_METHOD);
	}

	/* Record the current method that we are in */
	savedMethod = info->currentMethod;
	info->currentMethod = (ILNode *)node;

	/* Enter an unsafe context for the method if necessary */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeEnter(info, (ILNode *)node, "unsafe method declaration");
	}

	/* Warn if declaring the method with unsafe return or parameter types */
	if(CSHasUnsafeType(node->type) || CSHasUnsafeType(node->params))
	{
		CCUnsafeTypeMessage(info, (ILNode *)node);
	}

	/* Get the method's local variable scope */
	if(node->body && yykind(node->body) == yykindof(ILNode_NewScope))
	{
		newScope = (ILNode_NewScope *)(node->body);
		if(!(newScope->scope))
		{
			newScope->scope = ILScopeCreate(info, info->currentScope);
		}
		scope = newScope->scope;
	}
	else
	{
		scope = ILScopeCreate(info, info->currentScope);
	}

	/* Declare the parameters into the method's local variable scope */
	if((node->modifiers & IL_META_METHODDEF_STATIC) == 0)
	{
		/* Non-static parameters start at argument 1 */
		argNum = 1;
	}
	else
	{
		/* Static parameters start at argument 0 */
		argNum = 0;
	}
	argIndex = 1;
	ILNode_ListIter_Init(&iter, node->params);
	while((param = (ILNode_FormalParameter *)ILNode_ListIter_Next(&iter)) != 0)
	{
		if(param->pmod == ILParamMod_arglist)
		{
			++argNum;
			++argIndex;
			continue;
		}
		CSProcessAttrsForParam(info, node->methodInfo,
							   argIndex, param->attributes);
		name = ILQualIdentName(param->name, 0);
		data = ILScopeLookup(scope, name, 0);
		if(data)
		{
			CCErrorOnLine(yygetfilename(param->name),
						  yygetlinenum(param->name),
						  "`%s' is already declared in this scope", name);
			errorNode = ILScopeDataGetNode(data);
			if(errorNode)
			{
				CCErrorOnLine(yygetfilename(errorNode),
							  yygetlinenum(errorNode),
							  "previous declaration here");
			}
		}
		else
		{
			ILScopeDeclareLocal(scope, name, argNum | CS_LOCAL_IS_ARG,
								param->name);
		}
		++argNum;
		++argIndex;
	}

	/* If the method is abstract, then the class must be too */
	if((node->modifiers & IL_META_METHODDEF_ABSTRACT) != 0)
	{
		if(info->currentClass &&
		   (((ILNode_ClassDefn *)(info->currentClass))->modifiers &
		   			IL_META_TYPEDEF_ABSTRACT) == 0)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "`abstract' used on a member in a non-abstract class");
		}
	}

	/* Perform semantic analysis on the method body */
	if(node->body)
	{
		if(CSMetadataOnly)
		{
			/* Replace the body with "empty", because we only want metadata */
			if(yyisa(node->body, ILNode_NewScope))
			{
				((ILNode_NewScope *)(node->body))->stmt =
					ILNode_Empty_create();
			}
			else
			{
				node->body = ILNode_Empty_create();
			}
		}
		if((node->modifiers & IL_META_METHODDEF_ABSTRACT) != 0)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`abstract' cannot be used with a method body");
		}
		if((node->modifiers & CS_SPECIALATTR_EXTERN) != 0)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`extern' cannot be used with a method body");
		}
		savedScope = info->currentScope;
		info->currentScope = scope;
		ILNode_SemAnalysis(node->body, info, &(node->body));
		info->currentScope = savedScope;
	}
	else if((node->modifiers & CS_SPECIALATTR_EXTERN) == 0 &&
			(node->modifiers & IL_META_METHODDEF_ABSTRACT) == 0)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "method with no body requires `abstract' or `extern'");
	}

	/* If the return type is not void, then make sure that the
	   method ends in some kind of return statement */
	returnType = ILTypeGetReturn(ILMethod_Signature(node->methodInfo));
	if(returnType != ILType_Void && node->body)
	{
		if(!ILMethod_IsAbstract(node->methodInfo) &&
		   ILMethod_IsIL(node->methodInfo))
		{
			if(!ILNodeEndsInFlowChange(node->body,info) && !CSMetadataOnly)
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  "control reaches end of non-void method");
			}
		}
	}

	/* If the "extern" flag is set, and this method is contained
	   within the "<Module>" class, then suppress code generation.
	   Such methods are imported from a foreign C module, and
	   should not be generated from the C# application */
	if((node->modifiers & CS_SPECIALATTR_EXTERN) != 0)
	{
		if(info->currentClass &&
		   !strcmp(((ILNode_ClassDefn *)(info->currentClass))->name,
		   		   "<Module>"))
		{
			node->suppressCodeGen = 1;
		}
	}

	/* Leave the unsafe context for the method */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeLeave(info);
	}

	/* Return to the previous method level */
	info->currentMethod = savedMethod;

	/* Finished visiting this node */
	node->visited = ILVisitMode_Done;

	/* Methods don't really have a semantic value, so return the default */
	return CSSemValueDefault;
}
#line 10413 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_198__(ILNode_PropertyDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 1154 "cs_decls.tc"
{
	/* Determine if we have already visited this node */
	if(node->visited == ILVisitMode_Processing)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "circularity detected in property definition");
		return CSSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return CSSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Process attributes on the property */
	CSProcessAttrs(info, ILToProgramItem(node->propertyInfo),
				   node->attributes, CS_ATTR_PROPERTY);

	/* Enter an unsafe context for the property if necessary */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeEnter(info, (ILNode *)node, "unsafe property declaration");
	}

	/* Warn if declaring the property with an unsafe type */
	if(CSHasUnsafeType(node->type))
	{
		CCUnsafeTypeMessage(info, (ILNode *)node);
	}

	/* Perform semantic analysis on the accessor bodies */
	if(node->getAccessor)
	{
		ILNode_SemAnalysis(node->getAccessor, info, &(node->getAccessor));
	}
	if(node->setAccessor)
	{
		ILNode_SemAnalysis(node->setAccessor, info, &(node->setAccessor));
	}

	/* Leave the unsafe context for the property */
	if((node->modifiers & CS_SPECIALATTR_UNSAFE) != 0)
	{
		CCUnsafeLeave(info);
	}

	/* Finished visiting this node */
	node->visited = ILVisitMode_Done;
	return CSSemValueDefault;
}
#line 10467 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_199__(ILNode_EnumMemberDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 1206 "cs_decls.tc"
{
	CSSemValue value;
	ILEvalValue evalValue;
	ILType *type;
	ILMachineType machineType;
	ILNode_ClassDefn *defn = ((ILNode_ClassDefn *)(info->currentClass));

	/* Determine if we have already visited this node */
	if(node->visited == ILVisitMode_Processing)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "circularity detected in enumeration member definition");
		return CSSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return CSSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Process attributes on the enumerated value */
	CSProcessAttrs(info, ILToProgramItem(node->fieldInfo),
				   node->attributes, CS_ATTR_FIELD);

	/* Determine the type of the enumeration */
	type = ILClassToType(defn->classInfo);
	machineType = ILTypeToMachineType(type);

	/* Perform semantic analysis on the enum member value */
	if(node->value)
	{
		/* An enumerated value has been supplied */
		value = ILNode_SemAnalysis(node->value, info, &(node->value));
		if(!CSSemIsValue(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid enumerated value");
			node->visited = ILVisitMode_Done;
			return CSSemValueDefault;
		}
		else
		{
			/* Compute the constant value */
			if(!ILNode_EvalConst(node->value, info, &evalValue) ||
			   !ILGenCastConst(info, &evalValue, evalValue.valueType,
	                   		   machineType))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  "enumerated value is not constant");
				node->visited = ILVisitMode_Done;
				return CSSemValueDefault;
			}

			/* Set the constant value on the field definition */
			AddConstantValue(info, node->fieldInfo, &evalValue);

			/* Update the next enumerated value in sequence */
			switch(machineType)
			{
				case ILMachineType_Int8:
				case ILMachineType_UInt8:
				case ILMachineType_Int16:
				case ILMachineType_UInt16:
				case ILMachineType_Int32:
				{
					defn->nextEnum = (ILUInt64)(ILInt64)(evalValue.un.i4Value);
				}
				break;

				case ILMachineType_UInt32:
				{
					defn->nextEnum = (ILUInt64)(ILUInt32)(evalValue.un.i4Value);
				}
				break;

				case ILMachineType_Int64:
				{
					defn->nextEnum = (ILUInt64)(evalValue.un.i8Value);
				}
				break;

				case ILMachineType_UInt64:
				{
					defn->nextEnum = (ILUInt64)(evalValue.un.i8Value);
				}
				break;

				default: break;
			}
			++(defn->nextEnum);
		}
	}
	else
	{
		/* Use the next enumerated value in sequence */
		evalValue.valueType = machineType;
		switch(machineType)
		{
			case ILMachineType_Int8:
			case ILMachineType_UInt8:
			case ILMachineType_Int16:
			case ILMachineType_UInt16:
			case ILMachineType_Int32:
			case ILMachineType_UInt32:
			{
				evalValue.un.i4Value = (ILInt32)(defn->nextEnum);
			}
			break;

			case ILMachineType_Int64:
			case ILMachineType_UInt64:
			{
				evalValue.un.i8Value = (ILInt64)(defn->nextEnum);
			}
			break;

			default: break;
		}
		AddConstantValue(info, node->fieldInfo, &evalValue);
		++(defn->nextEnum);
	}

	/* Finished visiting this node */
	node->visited = ILVisitMode_Done;

	return CSSemValueDefault;
}
#line 10598 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_200__(ILNode_DelegateMemberDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 1335 "cs_decls.tc"
{
	unsigned long argNum;
	unsigned long argIndex;
	ILNode_ListIter iter;
	ILNode_FormalParameter *param;

	/* Bail out if compiling to the JVM */
	if(info->outputIsJava)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "delegate definitions are not permitted with Java output");
		return CSSemValueDefault;
	}

	/* Process attributes on the parameters */
	argNum = 1;
	argIndex = 1;
	ILNode_ListIter_Init(&iter, node->params);
	while((param = (ILNode_FormalParameter *)ILNode_ListIter_Next(&iter)) != 0)
	{
		if(param->pmod != ILParamMod_arglist)
		{
			CSProcessAttrsForParam(info, node->invokeMethod,
							   	   argIndex, param->attributes);
		}
		++argNum;
		++argIndex;
	}
	return CSSemValueDefault;
}
#line 10632 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_201__(ILNode_FormalParameter *node, ILGenInfo * info, ILNode * * parent)
#line 1367 "cs_decls.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 10640 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_202__(ILNode_AttributeTree *node, ILGenInfo * info, ILNode * * parent)
#line 1373 "cs_decls.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 10648 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_203__(ILNode_AttributeSection *node, ILGenInfo * info, ILNode * * parent)
#line 1379 "cs_decls.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 10656 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_204__(ILNode_Attribute *node, ILGenInfo * info, ILNode * * parent)
#line 1385 "cs_decls.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 10664 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_205__(ILNode_AttrArgs *node, ILGenInfo * info, ILNode * * parent)
#line 1391 "cs_decls.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 10672 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_206__(ILNode_NamedArg *node, ILGenInfo * info, ILNode * * parent)
#line 1397 "cs_decls.tc"
{
	/* TODO */
	return CSSemValueDefault;
}
#line 10680 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_207__(ILNode_Fixed *node, ILGenInfo * info, ILNode * * parent)
#line 1646 "cs_stmt.tc"
{
	ILType *type;
	char *name;
	ILNode_MethodDeclaration *method;
	ILNode *errorNode;
	ILNode_ListIter iter;
	ILNode *varNode;
	ILNode *nameNode;
	ILScopeData *data;

	/* Locate the method that this local is declared within */
	method = (ILNode_MethodDeclaration *)(info->currentMethod);

	/* TODO */
	CCUnsafeMessage(info, (ILNode *)node, "unsafe `fixed' statement");
	if(info->outputIsJava)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`fixed' disallowed when compiling to Java bytecode");
		return CSSemValueDefault;
	}

	/* Perform semantic analysis on the local variable type */
	type = CSSemType(node->type, info, &(node->type));

	/* Scan through the variable names and declare them in the current scope */
	ILNode_ListIter_Init(&iter, node->decls);
	while((varNode = ILNode_ListIter_Next(&iter)) != 0)
	{
		nameNode=((ILNode_FixedVariable*)varNode)->name;
		name = ILQualIdentName(nameNode,0);
		data = ILScopeLookup(info->currentScope, name, 0);
		if(data)
		{
			/* The name is already declared in this scope */
			CCErrorOnLine(yygetfilename(nameNode), yygetlinenum(nameNode),
						  "`%s' is already declared in this scope", name);
			errorNode = ILScopeDataGetNode(data);
			if(errorNode)
			{
				CCErrorOnLine(yygetfilename(errorNode), yygetlinenum(errorNode),
							  "previous declaration here");
			}
		}
		else
		{
			/* Add the type to the local variable signature for this method */
			if(!(method->localVarSig))
			{
				method->localVarSig = ILTypeCreateLocalList(info->context);
				if(!(method->localVarSig))
				{
					CCOutOfMemory();
				}
			}
			
			if(yyisa(varNode,ILNode_FixAddress))
			{
				/* TODO : figure the right way to pin variables */
			}
			
			if(!ILTypeAddLocal(info->context, method->localVarSig, type))
			{
				CCOutOfMemory();
			}

			/* Create a local variable entry in the current scope */
			ILScopeDeclareLocal(info->currentScope, name,
								ILTypeNumLocals(method->localVarSig) - 1,
								((ILNode_FixedVariable*)varNode)->name);
			ILNode_SemAnalysis(varNode,info,iter.last);
		}
	}
	ILNode_SemAnalysis(node->stmt,info,&(node->stmt));
	return CSSemValueDefault;
}
#line 10760 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_208__(ILNode_Using *node, ILGenInfo * info, ILNode * * parent)
#line 1481 "cs_stmt.tc"
{
	CSSemValue value;
	ILType *type;
	ILType *disposable;
	
	if(yyisa(node->resource,ILNode_Expression))
	{
		value=ILNode_SemAnalysis(node->resource,info,&(node->resource));		
		if(!CSSemGetType(value))
		{
			CCErrorOnLine(yygetfilename(node->resource), 
				yygetlinenum(node->resource), 
				"invalid expression");
		}
		disposable=ILFindSystemType(info,"IDisposable");
		type=CSSemGetType(value);
		if(!ILTypeImplements(info,type,disposable) && 
			!ILTypeImplements(info,type,disposable))
		{
			CCErrorOnLine(yygetfilename(node->resource), 
				yygetlinenum(node->resource), 
				"'%s' does not implement 'IDisposable'",
					CSTypeToName(type));
		}
	}
	else if(yyisa(node->resource,ILNode_ResourceDeclaration))
	{
		ILNode_SemAnalysis(node->resource,info,&(node->resource));
	}
	ILNode_SemAnalysis(node->stmt,info,&(node->stmt));
	return CSSemValueDefault;
}
#line 10796 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_209__(ILNode_Unsafe *node, ILGenInfo * info, ILNode * * parent)
#line 1611 "cs_stmt.tc"
{
	CCUnsafeEnter(info, (ILNode *)node, "unsafe statement");
	StmtSem(node->stmt, info, &(node->stmt));
	CCUnsafeLeave(info);
	return CSSemValueDefault;
}
#line 10806 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_210__(ILNode_Identifier *node, ILGenInfo * info, ILNode * * parent)
#line 872 "cs_lvalue.tc"
{
	CSSemValue value;
	ILScopeData *data=NULL;
	unsigned long index;
	ILNode_MethodDeclaration *method;
	ILParameterModifier paramMod;
  	ILNode_SemGuard *constVar;
	ILNode_UsingAlias *alias;
	ILType *type;
	ILEvalValue evalValue;

	if(!info->inSemType)
	{
		/* Look for local variables in the current scope */
		data = ILScopeLookup(info->currentScope, node->name, 1);
	}
	if(data && ILScopeDataGetKind(data) == IL_SCOPE_LOCAL)
	{
		index = ILScopeDataGetIndex(data);
		method = (ILNode_MethodDeclaration *)(info->currentMethod);
		if((index & CS_LOCAL_IS_ARG) == 0)
		{
			/* Local variable reference */
			type = ILTypeGetLocal(method->localVarSig, index);
			CSSemSetLValue(value, type);
			*parent = ILNode_LocalVar_create(index, ILTypeToMachineType(type));
		}
		else
		{
			/* Argument reference */
			index &= ~CS_LOCAL_IS_ARG;
			if((method->modifiers & IL_META_METHODDEF_STATIC) == 0)
			{
				paramMod = ILGenGetParamInfo(method->methodInfo, 0,
											 index, &type);
			}
			else
			{
				paramMod = ILGenGetParamInfo(method->methodInfo, 0,
											 index + 1, &type);
			}
			if(paramMod == ILParamMod_ref)
			{
				/* Handle by-reference parameters */
				*parent = ILNode_RefArgumentVar_create
					(index, ILTypeToMachineType(type), type);
			}
			else if(paramMod == ILParamMod_out)
			{
				/* Handle output-only parameters.  Technically, this should
				   probably be an s-value, not an l-value, but other C#
				   compilers allow "out" parameters to be read */
				*parent = ILNode_RefArgumentVar_create
					(index, ILTypeToMachineType(type), type);
			}
			else if(paramMod == ILParamMod_params)
			{
				/* Use the array form of the parameter inside the method */
				if((method->modifiers & IL_META_METHODDEF_STATIC) == 0)
				{
					type = ILTypeGetParam
						(ILMethod_Signature(method->methodInfo), index);
				}
				else
				{
					type = ILTypeGetParam
						(ILMethod_Signature(method->methodInfo), index + 1);
				}
				*parent = ILNode_ArgumentVar_create
					(index, ILMachineType_ObjectRef);
			}
			else
			{
				*parent = ILNode_ArgumentVar_create
							(index, ILTypeToMachineType(type));
			}
			CSSemSetLValue(value, type);
		}
		if((void*)(*parent) != (void*)node)
		{
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
		}
		return value;
	}
	else if(data && ILScopeDataGetKind(data) == IL_SCOPE_LOCAL_CONST)
	{
		method = (ILNode_MethodDeclaration *)(info->currentMethod);
		constVar = (ILNode_SemGuard *)(ILScopeDataGetData1(data));
		if(ILNode_EvalConst(constVar->expr, info, &evalValue))
		{
			CSSemSetConstant(value, CSSemGetType(constVar->value), evalValue);
			CSSemReplaceWithConstant(parent, value);
		}
		if((void*)(*parent) != (void*)node)
		{
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
		}
		return value;
	}

	/* Resolve the simple name quietly so that we can check for aliases
	   if & only if this fails */
	value = CSResolveSimpleNameQuiet(info, (ILNode *)node, node->name, 0);

	if (CSSemGetKind(value) != CS_SEMKIND_VOID)
	{	
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, 
							value, node->name, 0, 0);
	}

	if(data && ILScopeDataGetKind(data) == IL_SCOPE_ALIAS)
	{
		alias=(ILNode_UsingAlias*)ILScopeDataGetNode(data);
		if(alias->visited==ILVisitMode_Processing)
		{
			CCErrorOnLine(yygetfilename(alias), yygetlinenum(alias),
			  "circularity detected in `using' declaration");
			CSSemSetLValue(value, ILType_Int32);
			return value;
		}
		alias->visited=ILVisitMode_Processing;
		*parent = (ILNode*)ILScopeDataGetData1(data);
		if(info->resolvingAlias)
		{
			CCErrorOnLine(yygetfilename(alias), yygetlinenum(alias),
						  "using aliases may not refer to other aliases");
		}
		info->resolvingAlias = 1;
		value = ILNode_SemAnalysis(*parent,info,parent);
		info->resolvingAlias = 0;
		alias->visited=ILVisitMode_Done;
		return value;
	}

	/* This time around dump the errors */
	value = CSResolveSimpleName(info, (ILNode *)node, node->name, 0);

	/* Convert the result into an l-value or r-value and return it */
	return SemToLRValue((ILNode *)node, info, parent, 
							value, node->name, 0, 0);
}
#line 10954 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysis_211__(ILNode_QualIdent *node, ILGenInfo * info, ILNode * * parent)
#line 1150 "cs_lvalue.tc"
{
	CSSemValue value;
	CSSemValue value2;
	char *name;

	/* Get the semantic value for the left part of the identifier */
	value = ILNode_SemAnalysisType(node->left, info, &(node->left));

	/* Resolve the member */
	name = ILQualIdentName(node->right, 0);
	value2 = CSResolveMemberName(info, (ILNode *)node, value, name, 0);

	/* Convert the result into an l-value or r-value and return it */
	return SemToLRValue((ILNode *)node, info, parent, value2,
						name, node->left, &value);
}
#line 10974 "cs_semantics.c"

CSSemValue ILNode_SemAnalysis(ILNode * node__, ILGenInfo * info, ILNode * * parent)
{
	switch(node__->kind__)
	{
		case ILNode_DummySem_kind:
		case ILNode_Namespace_kind:
		case ILNode_UsingAlias_kind:
		case ILNode_UsingNamespace_kind:
		{
			return ILNode_SemAnalysis_1__((ILNode_DummySem *)node__, info, parent);
		}
		break;

		case ILNode_ArrayType_kind:
		{
			return ILNode_SemAnalysis_2__((ILNode_ArrayType *)node__, info, parent);
		}
		break;

		case ILNode_PtrType_kind:
		{
			return ILNode_SemAnalysis_3__((ILNode_PtrType *)node__, info, parent);
		}
		break;

		case ILNode_PrimitiveType_kind:
		{
			return ILNode_SemAnalysis_4__((ILNode_PrimitiveType *)node__, info, parent);
		}
		break;

		case ILNode_SystemType_kind:
		{
			return ILNode_SemAnalysis_5__((ILNode_SystemType *)node__, info, parent);
		}
		break;

		case ILNode_TypeSuffix_kind:
		{
			return ILNode_SemAnalysis_6__((ILNode_TypeSuffix *)node__, info, parent);
		}
		break;

		case ILNode_LocalVariableType_kind:
		{
			return ILNode_SemAnalysis_7__((ILNode_LocalVariableType *)node__, info, parent);
		}
		break;

		case ILNode_TypeActuals_kind:
		{
			return ILNode_SemAnalysis_8__((ILNode_TypeActuals *)node__, info, parent);
		}
		break;

		case ILNode_GenericReference_kind:
		{
			return ILNode_SemAnalysis_9__((ILNode_GenericReference *)node__, info, parent);
		}
		break;

		case ILNode_FixAddress_kind:
		{
			return ILNode_SemAnalysis_10__((ILNode_FixAddress *)node__, info, parent);
		}
		break;

		case ILNode_FixExpr_kind:
		{
			return ILNode_SemAnalysis_11__((ILNode_FixExpr *)node__, info, parent);
		}
		break;

		case ILNode_ResourceDeclaration_kind:
		{
			return ILNode_SemAnalysis_12__((ILNode_ResourceDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_BaseDestructor_kind:
		{
			return ILNode_SemAnalysis_13__((ILNode_BaseDestructor *)node__, info, parent);
		}
		break;

		case ILNode_DocComment_kind:
		{
			return ILNode_SemAnalysis_14__((ILNode_DocComment *)node__, info, parent);
		}
		break;

		case ILNode_StandaloneAttr_kind:
		{
			return ILNode_SemAnalysis_15__((ILNode_StandaloneAttr *)node__, info, parent);
		}
		break;

		case ILNode_Null_kind:
		{
			return ILNode_SemAnalysis_16__((ILNode_Null *)node__, info, parent);
		}
		break;

		case ILNode_NullPtr_kind:
		{
			return ILNode_SemAnalysis_17__((ILNode_NullPtr *)node__, info, parent);
		}
		break;

		case ILNode_True_kind:
		{
			return ILNode_SemAnalysis_18__((ILNode_True *)node__, info, parent);
		}
		break;

		case ILNode_False_kind:
		{
			return ILNode_SemAnalysis_19__((ILNode_False *)node__, info, parent);
		}
		break;

		case ILNode_Int8_kind:
		{
			return ILNode_SemAnalysis_20__((ILNode_Int8 *)node__, info, parent);
		}
		break;

		case ILNode_UInt8_kind:
		{
			return ILNode_SemAnalysis_21__((ILNode_UInt8 *)node__, info, parent);
		}
		break;

		case ILNode_Int16_kind:
		{
			return ILNode_SemAnalysis_22__((ILNode_Int16 *)node__, info, parent);
		}
		break;

		case ILNode_UInt16_kind:
		{
			return ILNode_SemAnalysis_23__((ILNode_UInt16 *)node__, info, parent);
		}
		break;

		case ILNode_Char_kind:
		{
			return ILNode_SemAnalysis_24__((ILNode_Char *)node__, info, parent);
		}
		break;

		case ILNode_Int32_kind:
		{
			return ILNode_SemAnalysis_25__((ILNode_Int32 *)node__, info, parent);
		}
		break;

		case ILNode_UInt32_kind:
		{
			return ILNode_SemAnalysis_26__((ILNode_UInt32 *)node__, info, parent);
		}
		break;

		case ILNode_Int64_kind:
		{
			return ILNode_SemAnalysis_27__((ILNode_Int64 *)node__, info, parent);
		}
		break;

		case ILNode_UInt64_kind:
		{
			return ILNode_SemAnalysis_28__((ILNode_UInt64 *)node__, info, parent);
		}
		break;

		case ILNode_Int_kind:
		{
			return ILNode_SemAnalysis_29__((ILNode_Int *)node__, info, parent);
		}
		break;

		case ILNode_UInt_kind:
		{
			return ILNode_SemAnalysis_30__((ILNode_UInt *)node__, info, parent);
		}
		break;

		case ILNode_Float32_kind:
		{
			return ILNode_SemAnalysis_31__((ILNode_Float32 *)node__, info, parent);
		}
		break;

		case ILNode_Float64_kind:
		{
			return ILNode_SemAnalysis_32__((ILNode_Float64 *)node__, info, parent);
		}
		break;

		case ILNode_Float_kind:
		{
			return ILNode_SemAnalysis_33__((ILNode_Float *)node__, info, parent);
		}
		break;

		case ILNode_Decimal_kind:
		{
			return ILNode_SemAnalysis_34__((ILNode_Decimal *)node__, info, parent);
		}
		break;

		case ILNode_String_kind:
		{
			return ILNode_SemAnalysis_35__((ILNode_String *)node__, info, parent);
		}
		break;

		case ILNode_Deref_kind:
		{
			return ILNode_SemAnalysis_36__((ILNode_Deref *)node__, info, parent);
		}
		break;

		case ILNode_StaticProperty_kind:
		{
			return ILNode_SemAnalysis_37__((ILNode_StaticProperty *)node__, info, parent);
		}
		break;

		case ILNode_MemberProperty_kind:
		{
			return ILNode_SemAnalysis_38__((ILNode_MemberProperty *)node__, info, parent);
		}
		break;

		case ILNode_IndexerAccess_kind:
		{
			return ILNode_SemAnalysis_39__((ILNode_IndexerAccess *)node__, info, parent);
		}
		break;

		case ILNode_SemGuard_kind:
		{
			return ILNode_SemAnalysis_40__((ILNode_SemGuard *)node__, info, parent);
		}
		break;

		case ILNode_GlobalNamespace_kind:
		{
			return ILNode_SemAnalysis_41__((ILNode_GlobalNamespace *)node__, info, parent);
		}
		break;

		case ILNode_AsIs_kind:
		case ILNode_MarkType_kind:
		{
			return ILNode_SemAnalysis_42__((ILNode_AsIs *)node__, info, parent);
		}
		break;

		case ILNode_Overflow_kind:
		{
			return ILNode_SemAnalysis_43__((ILNode_Overflow *)node__, info, parent);
		}
		break;

		case ILNode_NoOverflow_kind:
		{
			return ILNode_SemAnalysis_44__((ILNode_NoOverflow *)node__, info, parent);
		}
		break;

		case ILNode_Pedantic_kind:
		{
			return ILNode_SemAnalysis_45__((ILNode_Pedantic *)node__, info, parent);
		}
		break;

		case ILNode_NoPedantic_kind:
		{
			return ILNode_SemAnalysis_46__((ILNode_NoPedantic *)node__, info, parent);
		}
		break;

		case ILNode_BaseAccess_kind:
		{
			return ILNode_SemAnalysis_47__((ILNode_BaseAccess *)node__, info, parent);
		}
		break;

		case ILNode_BaseElement_kind:
		{
			return ILNode_SemAnalysis_48__((ILNode_BaseElement *)node__, info, parent);
		}
		break;

		case ILNode_MemberAccess_kind:
		{
			return ILNode_SemAnalysis_49__((ILNode_MemberAccess *)node__, info, parent);
		}
		break;

		case ILNode_DerefField_kind:
		{
			return ILNode_SemAnalysis_50__((ILNode_DerefField *)node__, info, parent);
		}
		break;

		case ILNode_This_kind:
		{
			return ILNode_SemAnalysis_51__((ILNode_This *)node__, info, parent);
		}
		break;

		case ILNode_LocalVar_kind:
		{
			return ILNode_SemAnalysis_52__((ILNode_LocalVar *)node__, info, parent);
		}
		break;

		case ILNode_ArgumentVar_kind:
		{
			return ILNode_SemAnalysis_53__((ILNode_ArgumentVar *)node__, info, parent);
		}
		break;

		case ILNode_RefArgumentVar_kind:
		{
			return ILNode_SemAnalysis_54__((ILNode_RefArgumentVar *)node__, info, parent);
		}
		break;

		case ILNode_StaticField_kind:
		{
			return ILNode_SemAnalysis_55__((ILNode_StaticField *)node__, info, parent);
		}
		break;

		case ILNode_MemberField_kind:
		{
			return ILNode_SemAnalysis_56__((ILNode_MemberField *)node__, info, parent);
		}
		break;

		case ILNode_ArrayAccess_kind:
		{
			return ILNode_SemAnalysis_57__((ILNode_ArrayAccess *)node__, info, parent);
		}
		break;

		case ILNode_LogicalNot_kind:
		{
			return ILNode_SemAnalysis_58__((ILNode_LogicalNot *)node__, info, parent);
		}
		break;

		case ILNode_Neg_kind:
		{
			return ILNode_SemAnalysis_59__((ILNode_Neg *)node__, info, parent);
		}
		break;

		case ILNode_UnaryPlus_kind:
		{
			return ILNode_SemAnalysis_60__((ILNode_UnaryPlus *)node__, info, parent);
		}
		break;

		case ILNode_Not_kind:
		{
			return ILNode_SemAnalysis_61__((ILNode_Not *)node__, info, parent);
		}
		break;

		case ILNode_UserUnaryOp_kind:
		{
			return ILNode_SemAnalysis_62__((ILNode_UserUnaryOp *)node__, info, parent);
		}
		break;

		case ILNode_PreInc_kind:
		{
			return ILNode_SemAnalysis_63__((ILNode_PreInc *)node__, info, parent);
		}
		break;

		case ILNode_PreDec_kind:
		{
			return ILNode_SemAnalysis_64__((ILNode_PreDec *)node__, info, parent);
		}
		break;

		case ILNode_PostInc_kind:
		{
			return ILNode_SemAnalysis_65__((ILNode_PostInc *)node__, info, parent);
		}
		break;

		case ILNode_PostDec_kind:
		{
			return ILNode_SemAnalysis_66__((ILNode_PostDec *)node__, info, parent);
		}
		break;

		case ILNode_UserPreInc_kind:
		{
			return ILNode_SemAnalysis_67__((ILNode_UserPreInc *)node__, info, parent);
		}
		break;

		case ILNode_UserPreDec_kind:
		{
			return ILNode_SemAnalysis_68__((ILNode_UserPreDec *)node__, info, parent);
		}
		break;

		case ILNode_UserPostInc_kind:
		{
			return ILNode_SemAnalysis_69__((ILNode_UserPostInc *)node__, info, parent);
		}
		break;

		case ILNode_UserPostDec_kind:
		{
			return ILNode_SemAnalysis_70__((ILNode_UserPostDec *)node__, info, parent);
		}
		break;

		case ILNode_PreIncPtr_kind:
		{
			return ILNode_SemAnalysis_71__((ILNode_PreIncPtr *)node__, info, parent);
		}
		break;

		case ILNode_PreDecPtr_kind:
		{
			return ILNode_SemAnalysis_72__((ILNode_PreDecPtr *)node__, info, parent);
		}
		break;

		case ILNode_PostIncPtr_kind:
		{
			return ILNode_SemAnalysis_73__((ILNode_PostIncPtr *)node__, info, parent);
		}
		break;

		case ILNode_PostDecPtr_kind:
		{
			return ILNode_SemAnalysis_74__((ILNode_PostDecPtr *)node__, info, parent);
		}
		break;

		case ILNode_CastSimple_kind:
		{
			return ILNode_SemAnalysis_75__((ILNode_CastSimple *)node__, info, parent);
		}
		break;

		case ILNode_CastType_kind:
		{
			return ILNode_SemAnalysis_76__((ILNode_CastType *)node__, info, parent);
		}
		break;

		case ILNode_UserConversion_kind:
		{
			return ILNode_SemAnalysis_77__((ILNode_UserConversion *)node__, info, parent);
		}
		break;

		case ILNode_AddressOf_kind:
		{
			return ILNode_SemAnalysis_78__((ILNode_AddressOf *)node__, info, parent);
		}
		break;

		case ILNode_ToBool_kind:
		{
			return ILNode_SemAnalysis_79__((ILNode_ToBool *)node__, info, parent);
		}
		break;

		case ILNode_ToAttrConst_kind:
		{
			return ILNode_SemAnalysis_80__((ILNode_ToAttrConst *)node__, info, parent);
		}
		break;

		case ILNode_ToConst_kind:
		{
			return ILNode_SemAnalysis_81__((ILNode_ToConst *)node__, info, parent);
		}
		break;

		case ILNode_VarArgExpand_kind:
		{
			return ILNode_SemAnalysis_82__((ILNode_VarArgExpand *)node__, info, parent);
		}
		break;

		case ILNode_IsNull_kind:
		{
			return ILNode_SemAnalysis_83__((ILNode_IsNull *)node__, info, parent);
		}
		break;

		case ILNode_IsNonNull_kind:
		{
			return ILNode_SemAnalysis_84__((ILNode_IsNonNull *)node__, info, parent);
		}
		break;

		case ILNode_MakeRefAny_kind:
		{
			return ILNode_SemAnalysis_85__((ILNode_MakeRefAny *)node__, info, parent);
		}
		break;

		case ILNode_RefType_kind:
		{
			return ILNode_SemAnalysis_86__((ILNode_RefType *)node__, info, parent);
		}
		break;

		case ILNode_ArrayLength_kind:
		{
			return ILNode_SemAnalysis_87__((ILNode_ArrayLength *)node__, info, parent);
		}
		break;

		case ILNode_ArrayInit_kind:
		{
			return ILNode_SemAnalysis_88__((ILNode_ArrayInit *)node__, info, parent);
		}
		break;

		case ILNode_TypeOf_kind:
		{
			return ILNode_SemAnalysis_89__((ILNode_TypeOf *)node__, info, parent);
		}
		break;

		case ILNode_SizeOf_kind:
		{
			return ILNode_SemAnalysis_90__((ILNode_SizeOf *)node__, info, parent);
		}
		break;

		case ILNode_UserCast_kind:
		{
			return ILNode_SemAnalysis_91__((ILNode_UserCast *)node__, info, parent);
		}
		break;

		case ILNode_IsUntyped_kind:
		{
			return ILNode_SemAnalysis_92__((ILNode_IsUntyped *)node__, info, parent);
		}
		break;

		case ILNode_AsUntyped_kind:
		{
			return ILNode_SemAnalysis_93__((ILNode_AsUntyped *)node__, info, parent);
		}
		break;

		case ILNode_LogicalAnd_kind:
		{
			return ILNode_SemAnalysis_94__((ILNode_LogicalAnd *)node__, info, parent);
		}
		break;

		case ILNode_LogicalOr_kind:
		{
			return ILNode_SemAnalysis_95__((ILNode_LogicalOr *)node__, info, parent);
		}
		break;

		case ILNode_UserLogicalAnd_kind:
		{
			return ILNode_SemAnalysis_96__((ILNode_UserLogicalAnd *)node__, info, parent);
		}
		break;

		case ILNode_UserLogicalOr_kind:
		{
			return ILNode_SemAnalysis_97__((ILNode_UserLogicalOr *)node__, info, parent);
		}
		break;

		case ILNode_Add_kind:
		{
			return ILNode_SemAnalysis_98__((ILNode_Add *)node__, info, parent);
		}
		break;

		case ILNode_Sub_kind:
		{
			return ILNode_SemAnalysis_99__((ILNode_Sub *)node__, info, parent);
		}
		break;

		case ILNode_Mul_kind:
		{
			return ILNode_SemAnalysis_100__((ILNode_Mul *)node__, info, parent);
		}
		break;

		case ILNode_Div_kind:
		{
			return ILNode_SemAnalysis_101__((ILNode_Div *)node__, info, parent);
		}
		break;

		case ILNode_Rem_kind:
		{
			return ILNode_SemAnalysis_102__((ILNode_Rem *)node__, info, parent);
		}
		break;

		case ILNode_And_kind:
		{
			return ILNode_SemAnalysis_103__((ILNode_And *)node__, info, parent);
		}
		break;

		case ILNode_Or_kind:
		{
			return ILNode_SemAnalysis_104__((ILNode_Or *)node__, info, parent);
		}
		break;

		case ILNode_Xor_kind:
		{
			return ILNode_SemAnalysis_105__((ILNode_Xor *)node__, info, parent);
		}
		break;

		case ILNode_Shl_kind:
		{
			return ILNode_SemAnalysis_106__((ILNode_Shl *)node__, info, parent);
		}
		break;

		case ILNode_Shr_kind:
		{
			return ILNode_SemAnalysis_107__((ILNode_Shr *)node__, info, parent);
		}
		break;

		case ILNode_UShr_kind:
		{
			return ILNode_SemAnalysis_108__((ILNode_UShr *)node__, info, parent);
		}
		break;

		case ILNode_UserBinaryOp_kind:
		{
			return ILNode_SemAnalysis_109__((ILNode_UserBinaryOp *)node__, info, parent);
		}
		break;

		case ILNode_Concat_kind:
		{
			return ILNode_SemAnalysis_110__((ILNode_Concat *)node__, info, parent);
		}
		break;

		case ILNode_DelegateAdd_kind:
		{
			return ILNode_SemAnalysis_111__((ILNode_DelegateAdd *)node__, info, parent);
		}
		break;

		case ILNode_DelegateSub_kind:
		{
			return ILNode_SemAnalysis_112__((ILNode_DelegateSub *)node__, info, parent);
		}
		break;

		case ILNode_Assign_kind:
		{
			return ILNode_SemAnalysis_113__((ILNode_Assign *)node__, info, parent);
		}
		break;

		case ILNode_Eq_kind:
		{
			return ILNode_SemAnalysis_114__((ILNode_Eq *)node__, info, parent);
		}
		break;

		case ILNode_Ne_kind:
		{
			return ILNode_SemAnalysis_115__((ILNode_Ne *)node__, info, parent);
		}
		break;

		case ILNode_Lt_kind:
		{
			return ILNode_SemAnalysis_116__((ILNode_Lt *)node__, info, parent);
		}
		break;

		case ILNode_Le_kind:
		{
			return ILNode_SemAnalysis_117__((ILNode_Le *)node__, info, parent);
		}
		break;

		case ILNode_Gt_kind:
		{
			return ILNode_SemAnalysis_118__((ILNode_Gt *)node__, info, parent);
		}
		break;

		case ILNode_Ge_kind:
		{
			return ILNode_SemAnalysis_119__((ILNode_Ge *)node__, info, parent);
		}
		break;

		case ILNode_Comma_kind:
		{
			return ILNode_SemAnalysis_120__((ILNode_Comma *)node__, info, parent);
		}
		break;

		case ILNode_ArgList_kind:
		{
			return ILNode_SemAnalysis_121__((ILNode_ArgList *)node__, info, parent);
		}
		break;

		case ILNode_RefValue_kind:
		{
			return ILNode_SemAnalysis_122__((ILNode_RefValue *)node__, info, parent);
		}
		break;

		case ILNode_InvocationExpression_kind:
		{
			return ILNode_SemAnalysis_123__((ILNode_InvocationExpression *)node__, info, parent);
		}
		break;

		case ILNode_StackAlloc_kind:
		{
			return ILNode_SemAnalysis_124__((ILNode_StackAlloc *)node__, info, parent);
		}
		break;

		case ILNode_Conditional_kind:
		{
			return ILNode_SemAnalysis_125__((ILNode_Conditional *)node__, info, parent);
		}
		break;

		case ILNode_AssignAdd_kind:
		{
			return ILNode_SemAnalysis_126__((ILNode_AssignAdd *)node__, info, parent);
		}
		break;

		case ILNode_AssignSub_kind:
		{
			return ILNode_SemAnalysis_127__((ILNode_AssignSub *)node__, info, parent);
		}
		break;

		case ILNode_AssignMul_kind:
		{
			return ILNode_SemAnalysis_128__((ILNode_AssignMul *)node__, info, parent);
		}
		break;

		case ILNode_AssignDiv_kind:
		{
			return ILNode_SemAnalysis_129__((ILNode_AssignDiv *)node__, info, parent);
		}
		break;

		case ILNode_AssignRem_kind:
		{
			return ILNode_SemAnalysis_130__((ILNode_AssignRem *)node__, info, parent);
		}
		break;

		case ILNode_AssignAnd_kind:
		{
			return ILNode_SemAnalysis_131__((ILNode_AssignAnd *)node__, info, parent);
		}
		break;

		case ILNode_AssignOr_kind:
		{
			return ILNode_SemAnalysis_132__((ILNode_AssignOr *)node__, info, parent);
		}
		break;

		case ILNode_AssignXor_kind:
		{
			return ILNode_SemAnalysis_133__((ILNode_AssignXor *)node__, info, parent);
		}
		break;

		case ILNode_AssignShl_kind:
		{
			return ILNode_SemAnalysis_134__((ILNode_AssignShl *)node__, info, parent);
		}
		break;

		case ILNode_AssignShr_kind:
		{
			return ILNode_SemAnalysis_135__((ILNode_AssignShr *)node__, info, parent);
		}
		break;

		case ILNode_AssignUShr_kind:
		{
			return ILNode_SemAnalysis_136__((ILNode_AssignUShr *)node__, info, parent);
		}
		break;

		case ILNode_VarArgList_kind:
		{
			return ILNode_SemAnalysis_137__((ILNode_VarArgList *)node__, info, parent);
		}
		break;

		case ILNode_Argument_kind:
		{
			return ILNode_SemAnalysis_138__((ILNode_Argument *)node__, info, parent);
		}
		break;

		case ILNode_ArgArray_kind:
		{
			return ILNode_SemAnalysis_139__((ILNode_ArgArray *)node__, info, parent);
		}
		break;

		case ILNode_As_kind:
		{
			return ILNode_SemAnalysis_140__((ILNode_As *)node__, info, parent);
		}
		break;

		case ILNode_Is_kind:
		{
			return ILNode_SemAnalysis_141__((ILNode_Is *)node__, info, parent);
		}
		break;

		case ILNode_Box_kind:
		{
			return ILNode_SemAnalysis_142__((ILNode_Box *)node__, info, parent);
		}
		break;

		case ILNode_Unbox_kind:
		{
			return ILNode_SemAnalysis_143__((ILNode_Unbox *)node__, info, parent);
		}
		break;

		case ILNode_Error_kind:
		{
			return ILNode_SemAnalysis_144__((ILNode_Error *)node__, info, parent);
		}
		break;

		case ILNode_NewExpression_kind:
		{
			return ILNode_SemAnalysis_145__((ILNode_NewExpression *)node__, info, parent);
		}
		break;

		case ILNode_ObjectCreationExpression_kind:
		{
			return ILNode_SemAnalysis_146__((ILNode_ObjectCreationExpression *)node__, info, parent);
		}
		break;

		case ILNode_DelegateCreationExpression_kind:
		{
			return ILNode_SemAnalysis_147__((ILNode_DelegateCreationExpression *)node__, info, parent);
		}
		break;

		case ILNode_DefaultConstructor_kind:
		{
			return ILNode_SemAnalysis_148__((ILNode_DefaultConstructor *)node__, info, parent);
		}
		break;

		case ILNode_BaseInit_kind:
		{
			return ILNode_SemAnalysis_149__((ILNode_BaseInit *)node__, info, parent);
		}
		break;

		case ILNode_ThisInit_kind:
		{
			return ILNode_SemAnalysis_150__((ILNode_ThisInit *)node__, info, parent);
		}
		break;

		case ILNode_NonStaticInit_kind:
		{
			return ILNode_SemAnalysis_151__((ILNode_NonStaticInit *)node__, info, parent);
		}
		break;

		case ILNode_EmptyExpr_kind:
		{
			return ILNode_SemAnalysis_152__((ILNode_EmptyExpr *)node__, info, parent);
		}
		break;

		case ILNode_Compound_kind:
		{
			return ILNode_SemAnalysis_153__((ILNode_Compound *)node__, info, parent);
		}
		break;

		case ILNode_SwitchSectList_kind:
		{
			return ILNode_SemAnalysis_154__((ILNode_SwitchSectList *)node__, info, parent);
		}
		break;

		case ILNode_CaseList_kind:
		{
			return ILNode_SemAnalysis_155__((ILNode_CaseList *)node__, info, parent);
		}
		break;

		case ILNode_List_kind:
		case ILNode_CatchClauses_kind:
		{
			return ILNode_SemAnalysis_156__((ILNode_List *)node__, info, parent);
		}
		break;

		case ILNode_Empty_kind:
		{
			return ILNode_SemAnalysis_157__((ILNode_Empty *)node__, info, parent);
		}
		break;

		case ILNode_If_kind:
		{
			return ILNode_SemAnalysis_158__((ILNode_If *)node__, info, parent);
		}
		break;

		case ILNode_While_kind:
		{
			return ILNode_SemAnalysis_159__((ILNode_While *)node__, info, parent);
		}
		break;

		case ILNode_Do_kind:
		{
			return ILNode_SemAnalysis_160__((ILNode_Do *)node__, info, parent);
		}
		break;

		case ILNode_For_kind:
		{
			return ILNode_SemAnalysis_161__((ILNode_For *)node__, info, parent);
		}
		break;

		case ILNode_Foreach_kind:
		{
			return ILNode_SemAnalysis_162__((ILNode_Foreach *)node__, info, parent);
		}
		break;

		case ILNode_ForeachString_kind:
		{
			return ILNode_SemAnalysis_163__((ILNode_ForeachString *)node__, info, parent);
		}
		break;

		case ILNode_ForeachCollection_kind:
		{
			return ILNode_SemAnalysis_164__((ILNode_ForeachCollection *)node__, info, parent);
		}
		break;

		case ILNode_Switch_kind:
		{
			return ILNode_SemAnalysis_165__((ILNode_Switch *)node__, info, parent);
		}
		break;

		case ILNode_Break_kind:
		{
			return ILNode_SemAnalysis_166__((ILNode_Break *)node__, info, parent);
		}
		break;

		case ILNode_LabelledBreak_kind:
		{
			return ILNode_SemAnalysis_167__((ILNode_LabelledBreak *)node__, info, parent);
		}
		break;

		case ILNode_Continue_kind:
		{
			return ILNode_SemAnalysis_168__((ILNode_Continue *)node__, info, parent);
		}
		break;

		case ILNode_LabelledContinue_kind:
		{
			return ILNode_SemAnalysis_169__((ILNode_LabelledContinue *)node__, info, parent);
		}
		break;

		case ILNode_Return_kind:
		{
			return ILNode_SemAnalysis_170__((ILNode_Return *)node__, info, parent);
		}
		break;

		case ILNode_ReturnExpr_kind:
		{
			return ILNode_SemAnalysis_171__((ILNode_ReturnExpr *)node__, info, parent);
		}
		break;

		case ILNode_Goto_kind:
		{
			return ILNode_SemAnalysis_172__((ILNode_Goto *)node__, info, parent);
		}
		break;

		case ILNode_GotoLabel_kind:
		{
			return ILNode_SemAnalysis_173__((ILNode_GotoLabel *)node__, info, parent);
		}
		break;

		case ILNode_GotoCase_kind:
		{
			return ILNode_SemAnalysis_174__((ILNode_GotoCase *)node__, info, parent);
		}
		break;

		case ILNode_GotoDefault_kind:
		{
			return ILNode_SemAnalysis_175__((ILNode_GotoDefault *)node__, info, parent);
		}
		break;

		case ILNode_NewScope_kind:
		{
			return ILNode_SemAnalysis_176__((ILNode_NewScope *)node__, info, parent);
		}
		break;

		case ILNode_SwitchSection_kind:
		{
			return ILNode_SemAnalysis_177__((ILNode_SwitchSection *)node__, info, parent);
		}
		break;

		case ILNode_CaseLabel_kind:
		{
			return ILNode_SemAnalysis_178__((ILNode_CaseLabel *)node__, info, parent);
		}
		break;

		case ILNode_DefaultLabel_kind:
		{
			return ILNode_SemAnalysis_179__((ILNode_DefaultLabel *)node__, info, parent);
		}
		break;

		case ILNode_Throw_kind:
		{
			return ILNode_SemAnalysis_180__((ILNode_Throw *)node__, info, parent);
		}
		break;

		case ILNode_ThrowExpr_kind:
		{
			return ILNode_SemAnalysis_181__((ILNode_ThrowExpr *)node__, info, parent);
		}
		break;

		case ILNode_Try_kind:
		{
			return ILNode_SemAnalysis_182__((ILNode_Try *)node__, info, parent);
		}
		break;

		case ILNode_CatchClause_kind:
		{
			return ILNode_SemAnalysis_183__((ILNode_CatchClause *)node__, info, parent);
		}
		break;

		case ILNode_FinallyClause_kind:
		{
			return ILNode_SemAnalysis_184__((ILNode_FinallyClause *)node__, info, parent);
		}
		break;

		case ILNode_Lock_kind:
		{
			return ILNode_SemAnalysis_185__((ILNode_Lock *)node__, info, parent);
		}
		break;

		case ILNode_LocalVarDeclaration_kind:
		{
			return ILNode_SemAnalysis_186__((ILNode_LocalVarDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_LocalConstDeclaration_kind:
		{
			return ILNode_SemAnalysis_187__((ILNode_LocalConstDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_LineInfo_kind:
		{
			return ILNode_SemAnalysis_188__((ILNode_LineInfo *)node__, info, parent);
		}
		break;

		case ILNode_EventAddOrRemove_kind:
		{
			return ILNode_SemAnalysis_189__((ILNode_EventAddOrRemove *)node__, info, parent);
		}
		break;

		case ILNode_ClassDefn_kind:
		{
			return ILNode_SemAnalysis_190__((ILNode_ClassDefn *)node__, info, parent);
		}
		break;

		case ILNode_ScopeChange_kind:
		{
			return ILNode_SemAnalysis_191__((ILNode_ScopeChange *)node__, info, parent);
		}
		break;

		case ILNode_FieldDeclaration_kind:
		{
			return ILNode_SemAnalysis_192__((ILNode_FieldDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_FieldDeclarator_kind:
		{
			return ILNode_SemAnalysis_193__((ILNode_FieldDeclarator *)node__, info, parent);
		}
		break;

		case ILNode_EventDeclaration_kind:
		{
			return ILNode_SemAnalysis_194__((ILNode_EventDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_EventDeclarator_kind:
		{
			return ILNode_SemAnalysis_195__((ILNode_EventDeclarator *)node__, info, parent);
		}
		break;

		case ILNode_ProxyDeclaration_kind:
		{
			return ILNode_SemAnalysis_196__((ILNode_ProxyDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_MethodDeclaration_kind:
		{
			return ILNode_SemAnalysis_197__((ILNode_MethodDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_PropertyDeclaration_kind:
		{
			return ILNode_SemAnalysis_198__((ILNode_PropertyDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_EnumMemberDeclaration_kind:
		{
			return ILNode_SemAnalysis_199__((ILNode_EnumMemberDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_DelegateMemberDeclaration_kind:
		{
			return ILNode_SemAnalysis_200__((ILNode_DelegateMemberDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_FormalParameter_kind:
		{
			return ILNode_SemAnalysis_201__((ILNode_FormalParameter *)node__, info, parent);
		}
		break;

		case ILNode_AttributeTree_kind:
		{
			return ILNode_SemAnalysis_202__((ILNode_AttributeTree *)node__, info, parent);
		}
		break;

		case ILNode_AttributeSection_kind:
		{
			return ILNode_SemAnalysis_203__((ILNode_AttributeSection *)node__, info, parent);
		}
		break;

		case ILNode_Attribute_kind:
		{
			return ILNode_SemAnalysis_204__((ILNode_Attribute *)node__, info, parent);
		}
		break;

		case ILNode_AttrArgs_kind:
		{
			return ILNode_SemAnalysis_205__((ILNode_AttrArgs *)node__, info, parent);
		}
		break;

		case ILNode_NamedArg_kind:
		{
			return ILNode_SemAnalysis_206__((ILNode_NamedArg *)node__, info, parent);
		}
		break;

		case ILNode_Fixed_kind:
		{
			return ILNode_SemAnalysis_207__((ILNode_Fixed *)node__, info, parent);
		}
		break;

		case ILNode_Using_kind:
		{
			return ILNode_SemAnalysis_208__((ILNode_Using *)node__, info, parent);
		}
		break;

		case ILNode_Unsafe_kind:
		{
			return ILNode_SemAnalysis_209__((ILNode_Unsafe *)node__, info, parent);
		}
		break;

		case ILNode_Identifier_kind:
		case ILNode_AttrIdentifier_kind:
		{
			return ILNode_SemAnalysis_210__((ILNode_Identifier *)node__, info, parent);
		}
		break;

		case ILNode_QualIdent_kind:
		case ILNode_AttrQualIdent_kind:
		{
			return ILNode_SemAnalysis_211__((ILNode_QualIdent *)node__, info, parent);
		}
		break;

		default: break;
	}
	return (CSSemValueDefault);
}

static void ILNode_Declaration_GatherStaticCtor_1__(ILNode_ClassDefn *node, ILNode_List * ctor)
#line 314 "cs_decls.tc"
{
	if (node->body) 
	{
		CSListGatherStaticCtor((ILNode_List *)node->body, ctor);
	}
}
#line 12266 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_2__(ILNode_ScopeChange *node, ILNode_List * ctor)
#line 314 "cs_decls.tc"
{
	if (node->body) 
	{
		CSListGatherStaticCtor((ILNode_List *)node->body, ctor);
	}
}
#line 12276 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_3__(ILNode_FieldDeclaration *node, ILNode_List * ctor)
#line 714 "cs_decls.tc"
{
	if (node->fieldDeclarators) 
	{
		return CSListGatherStaticCtor
							((ILNode_List *)node->fieldDeclarators, ctor);
	}
}
#line 12287 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_4__(ILNode_FieldDeclarator *node, ILNode_List * ctor)
#line 866 "cs_decls.tc"
{
	ILNode_List_Add(ctor, node->staticCtor);
}
#line 12294 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_5__(ILNode_EventDeclaration *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12301 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_6__(ILNode_EventDeclarator *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12308 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_7__(ILNode_ProxyDeclaration *node, ILNode_List * ctor)
#line 330 "cs_decls.tc"
{
	/* Nothing to do here */
}
#line 12315 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_8__(ILNode_MethodDeclaration *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12322 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_9__(ILNode_PropertyDeclaration *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12329 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_10__(ILNode_EnumMemberDeclaration *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12336 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_11__(ILNode_DelegateMemberDeclaration *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12343 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_12__(ILNode_FormalParameter *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12350 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_13__(ILNode_AttributeTree *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12357 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_14__(ILNode_AttributeSection *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12364 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_15__(ILNode_Attribute *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12371 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_16__(ILNode_AttrArgs *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12378 "cs_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_17__(ILNode_NamedArg *node, ILNode_List * ctor)
#line 1447 "cs_decls.tc"
{
	return;
}
#line 12385 "cs_semantics.c"

void ILNode_Declaration_GatherStaticCtor(ILNode_Declaration * node__, ILNode_List * ctor)
{
	switch(node__->kind__)
	{
		case ILNode_ClassDefn_kind:
		{
			ILNode_Declaration_GatherStaticCtor_1__((ILNode_ClassDefn *)node__, ctor);
		}
		break;

		case ILNode_ScopeChange_kind:
		{
			ILNode_Declaration_GatherStaticCtor_2__((ILNode_ScopeChange *)node__, ctor);
		}
		break;

		case ILNode_FieldDeclaration_kind:
		{
			ILNode_Declaration_GatherStaticCtor_3__((ILNode_FieldDeclaration *)node__, ctor);
		}
		break;

		case ILNode_FieldDeclarator_kind:
		{
			ILNode_Declaration_GatherStaticCtor_4__((ILNode_FieldDeclarator *)node__, ctor);
		}
		break;

		case ILNode_EventDeclaration_kind:
		{
			ILNode_Declaration_GatherStaticCtor_5__((ILNode_EventDeclaration *)node__, ctor);
		}
		break;

		case ILNode_EventDeclarator_kind:
		{
			ILNode_Declaration_GatherStaticCtor_6__((ILNode_EventDeclarator *)node__, ctor);
		}
		break;

		case ILNode_ProxyDeclaration_kind:
		{
			ILNode_Declaration_GatherStaticCtor_7__((ILNode_ProxyDeclaration *)node__, ctor);
		}
		break;

		case ILNode_MethodDeclaration_kind:
		{
			ILNode_Declaration_GatherStaticCtor_8__((ILNode_MethodDeclaration *)node__, ctor);
		}
		break;

		case ILNode_PropertyDeclaration_kind:
		{
			ILNode_Declaration_GatherStaticCtor_9__((ILNode_PropertyDeclaration *)node__, ctor);
		}
		break;

		case ILNode_EnumMemberDeclaration_kind:
		{
			ILNode_Declaration_GatherStaticCtor_10__((ILNode_EnumMemberDeclaration *)node__, ctor);
		}
		break;

		case ILNode_DelegateMemberDeclaration_kind:
		{
			ILNode_Declaration_GatherStaticCtor_11__((ILNode_DelegateMemberDeclaration *)node__, ctor);
		}
		break;

		case ILNode_FormalParameter_kind:
		{
			ILNode_Declaration_GatherStaticCtor_12__((ILNode_FormalParameter *)node__, ctor);
		}
		break;

		case ILNode_AttributeTree_kind:
		{
			ILNode_Declaration_GatherStaticCtor_13__((ILNode_AttributeTree *)node__, ctor);
		}
		break;

		case ILNode_AttributeSection_kind:
		{
			ILNode_Declaration_GatherStaticCtor_14__((ILNode_AttributeSection *)node__, ctor);
		}
		break;

		case ILNode_Attribute_kind:
		{
			ILNode_Declaration_GatherStaticCtor_15__((ILNode_Attribute *)node__, ctor);
		}
		break;

		case ILNode_AttrArgs_kind:
		{
			ILNode_Declaration_GatherStaticCtor_16__((ILNode_AttrArgs *)node__, ctor);
		}
		break;

		case ILNode_NamedArg_kind:
		{
			ILNode_Declaration_GatherStaticCtor_17__((ILNode_NamedArg *)node__, ctor);
		}
		break;

		default: break;
	}
}

static CSSemValue ILNode_SemAnalysisType_1__(ILNode_MemberAccess *node, ILGenInfo * info, ILNode * * parent)
#line 1388 "cs_lvalue.tc"
{
	CSSemValue value;
	int savedState = info->inSemType;
	char *name;
	char *ns;
	
	/* convert the first subexpression into a namespace */
	ns = ILMemberAccessName(node->expr1);
	
	/* Convert the second subexpression into a name */
	name = ILQualIdentName(node->expr2, 0);

	value = GetFullyQualifiedType(info, ns, name);

	if(CSSemGetKind(value) == CS_SEMKIND_TYPE)
	{
		return value;
	}
	
	info->inSemType=1;
	/* Get the semantic value for the left part of the identifier */
	value = ILNode_SemAnalysisType(node->expr1, info, &(node->expr1));

	/* Resolve the member */
	value = CSResolveMemberName(info, (ILNode *)node, value, name, 0);

	info->inSemType=savedState;
	
	/* the result is a type */
	return value ;
}
#line 12530 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysisType_2__(ILNode_AttrIdentifier *node, ILGenInfo * info, ILNode * * parent)
#line 1077 "cs_lvalue.tc"
{
	CSSemValue value;
	ILNode_UsingAlias *alias;
	ILScopeData *data;
	int savedState=info->inSemType;
	char *name;

	/* Resolve the simple name */
	info->inSemType=1;
	value = CSResolveSimpleNameQuiet(info, (ILNode *)node, node->name, 1);
	info->inSemType=savedState;

	if (CSSemGetKind(value) == CS_SEMKIND_TYPE &&
	    ILTypeAssignCompatible(info->image, CSSemGetType(value),
	   					       ILFindSystemType(info, "Attribute")))
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, 
							value, node->name, 0, 0);
	}

	/* Try again, this time with "Attribute" appended */
	name = ILInternAppendedString
		(ILInternString(node->name, strlen(node->name)),
		 ILInternString("Attribute", 9)).string;
	info->inSemType=1;
	value = CSResolveSimpleNameQuiet(info, (ILNode *)node, name, 1);
	info->inSemType=savedState;

	if (CSSemGetKind(value) == CS_SEMKIND_TYPE)
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, 
							value, node->name, 0, 0);
	}

	data = ILScopeLookup(info->currentScope, node->name, 1);
	
	if(data && ILScopeDataGetKind(data) == IL_SCOPE_ALIAS &&
	   !(info->resolvingAlias))
	{
		alias=(ILNode_UsingAlias*)ILScopeDataGetNode(data);
		if(alias->visited==ILVisitMode_Processing)
		{
			CCErrorOnLine(yygetfilename(alias), yygetlinenum(alias),
			  "circularity detected in `using' declaration");
			CSSemSetLValue(value, ILType_Int32);
			return value;
		}
		alias->visited=ILVisitMode_Processing;
		*parent = (ILNode*)ILScopeDataGetData1(data);
		if(info->resolvingAlias)
		{
			CCErrorOnLine(yygetfilename(alias), yygetlinenum(alias),
						  "using aliases may not refer to other aliases");
		}
		info->resolvingAlias = 1;
		savedState=info->inSemType;
		info->inSemType=1;
		value = ILNode_SemAnalysis(*parent,info,parent);
		info->inSemType=savedState;
		info->resolvingAlias = 0;
		alias->visited=ILVisitMode_Done;
		return value;
	}

	return CSSemValueDefault;
}
#line 12602 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysisType_3__(ILNode_Identifier *node, ILGenInfo * info, ILNode * * parent)
#line 1021 "cs_lvalue.tc"
{
	CSSemValue value;
	ILNode_UsingAlias *alias;
	ILScopeData *data;
	int savedState=info->inSemType;

	info->inSemType=1;
	/* Resolve the simple name */
	value = CSResolveSimpleNameQuiet(info, (ILNode *)node, node->name, 1);
	info->inSemType=savedState;

	if (CSSemGetKind(value) == CS_SEMKIND_TYPE || CSSemGetKind(value) == CS_SEMKIND_NAMESPACE || CSSemGetKind(value) == CS_SEMKIND_TYPE_NODE)
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, 
							value, node->name, 0, 0);
	}

	data = ILScopeLookup(((ILNode_Namespace*)info->currentNamespace)->localScope, node->name, 1);
	
	if(data && ILScopeDataGetKind(data) == IL_SCOPE_ALIAS &&
	   !(info->resolvingAlias))
	{
		alias=(ILNode_UsingAlias*)ILScopeDataGetNode(data);
		if(alias->visited==ILVisitMode_Processing)
		{
			CCErrorOnLine(yygetfilename(alias), yygetlinenum(alias),
			  "circularity detected in `using' declaration");
			CSSemSetLValue(value, ILType_Int32);
			return value;
		}
		alias->visited=ILVisitMode_Processing;
		*parent = (ILNode*)ILScopeDataGetData1(data);
		if(info->resolvingAlias)
		{
			CCErrorOnLine(yygetfilename(alias), yygetlinenum(alias),
						  "using aliases may not refer to other aliases");
		}
		info->resolvingAlias = 1;
		savedState=info->inSemType;
		info->inSemType=1;
		value = ILNode_SemAnalysis(*parent,info,parent);
		info->inSemType=savedState;
		info->resolvingAlias = 0;
		alias->visited=ILVisitMode_Done;
		return value;
	}

	return CSSemValueDefault;
}
#line 12656 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysisType_4__(ILNode_AttrQualIdent *node, ILGenInfo * info, ILNode * * parent)
#line 1217 "cs_lvalue.tc"
{
	CSSemValue value;
	CSSemValue value2;
	char *name;
	int savedState = info->inSemType;

	/* Restrict lookups for types only (ie namespaces , types, nested types */
	info->inSemType = 1;

	/* Get the semantic value for the left part of the identifier */
	value = ILNode_SemAnalysis(node->left, info, &(node->left));

	/* Resolve the member */
	name = ILQualIdentName(node->right, 0);
	value2 = CSResolveMemberNameQuiet(info, (ILNode *)node, value, name, 1);

	/* If the resolution failed, then try again with "Attribute" appended */
	if(CSSemGetKind(value2) != CS_SEMKIND_TYPE ||
	   !ILTypeAssignCompatible(info->image, CSSemGetType(value2),
	   					       ILFindSystemType(info, "Attribute")))
	{
		name = ILInternAppendedString
			(ILInternString(name, strlen(name)),
			 ILInternString("Attribute", 9)).string;
		value2 = CSResolveMemberName(info, (ILNode *)node, value, name, 1);
	}

	info->inSemType = savedState;

	if (CSSemGetKind(value2) != CS_SEMKIND_TYPE)
	{
		return CSSemValueDefault;
	}
	else
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, value2,
						name, node->left, &value);
	}
}
#line 12700 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysisType_5__(ILNode_QualIdent *node, ILGenInfo * info, ILNode * * parent)
#line 1171 "cs_lvalue.tc"
{
	CSSemValue value;
	CSSemValue value2;
	char *name;
	char *ns;
	int savedState = info->inSemType;
	
	ns = ILQualIdentName(node->left, 0);
	name = ILQualIdentName(node->right, 0);
	
	value = GetFullyQualifiedType(info, ns, name);

	if(CSSemGetKind(value) == CS_SEMKIND_TYPE)
	{
		return value;
	}

	/* Restrict lookups for types only (ie namespaces , types, nested types */
	info->inSemType = 1;

	/* Get the semantic value for the left part of the identifier */
	value = ILNode_SemAnalysisType(node->left, info, &(node->left));

	/* Resolve the member */
	value2 = CSResolveMemberName(info, (ILNode *)node, value, name, 1);
	
	info->inSemType = savedState;

	if (CSSemGetKind(value2) == CS_SEMKIND_TYPE || CSSemGetKind(value2) == CS_SEMKIND_NAMESPACE || CSSemGetKind(value2) == CS_SEMKIND_TYPE_NODE)
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, value2,
						name, node->left, &value);
	}
	else
	{
		return CSSemValueDefault;
	}
}
#line 12743 "cs_semantics.c"

static CSSemValue ILNode_SemAnalysisType_6__(ILNode *node, ILGenInfo * info, ILNode * * parent)
#line 51 "cs_semantics.tc"
{
	return ILNode_SemAnalysis(node, info, parent);
}
#line 12750 "cs_semantics.c"

CSSemValue ILNode_SemAnalysisType(ILNode * node__, ILGenInfo * info, ILNode * * parent)
{
	switch(node__->kind__)
	{
		case ILNode_MemberAccess_kind:
		{
			return ILNode_SemAnalysisType_1__((ILNode_MemberAccess *)node__, info, parent);
		}
		break;

		case ILNode_AttrIdentifier_kind:
		{
			return ILNode_SemAnalysisType_2__((ILNode_AttrIdentifier *)node__, info, parent);
		}
		break;

		case ILNode_Identifier_kind:
		{
			return ILNode_SemAnalysisType_3__((ILNode_Identifier *)node__, info, parent);
		}
		break;

		case ILNode_AttrQualIdent_kind:
		{
			return ILNode_SemAnalysisType_4__((ILNode_AttrQualIdent *)node__, info, parent);
		}
		break;

		case ILNode_QualIdent_kind:
		{
			return ILNode_SemAnalysisType_5__((ILNode_QualIdent *)node__, info, parent);
		}
		break;

		case ILNode_kind:
		case ILNode_Dummy_kind:
		case ILNode_DummySem_kind:
		case ILNode_Namespace_kind:
		case ILNode_UsingAlias_kind:
		case ILNode_UsingNamespace_kind:
		case ILNode_ArrayType_kind:
		case ILNode_PtrType_kind:
		case ILNode_PrimitiveType_kind:
		case ILNode_SystemType_kind:
		case ILNode_TypeSuffix_kind:
		case ILNode_LocalVariableType_kind:
		case ILNode_TypeActuals_kind:
		case ILNode_GenericReference_kind:
		case ILNode_FixedVariable_kind:
		case ILNode_FixAddress_kind:
		case ILNode_FixExpr_kind:
		case ILNode_ResourceDeclaration_kind:
		case ILNode_BaseDestructor_kind:
		case ILNode_DocComment_kind:
		case ILNode_StandaloneAttr_kind:
		case ILNode_Expression_kind:
		case ILNode_Constant_kind:
		case ILNode_Null_kind:
		case ILNode_NullPtr_kind:
		case ILNode_True_kind:
		case ILNode_False_kind:
		case ILNode_Integer_kind:
		case ILNode_Int8_kind:
		case ILNode_UInt8_kind:
		case ILNode_Int16_kind:
		case ILNode_UInt16_kind:
		case ILNode_Char_kind:
		case ILNode_Int32_kind:
		case ILNode_UInt32_kind:
		case ILNode_Int64_kind:
		case ILNode_UInt64_kind:
		case ILNode_Int_kind:
		case ILNode_UInt_kind:
		case ILNode_Real_kind:
		case ILNode_Float32_kind:
		case ILNode_Float64_kind:
		case ILNode_Float_kind:
		case ILNode_Decimal_kind:
		case ILNode_String_kind:
		case ILNode_LValue_kind:
		case ILNode_LValueNoRef_kind:
		case ILNode_Deref_kind:
		case ILNode_StaticProperty_kind:
		case ILNode_MemberProperty_kind:
		case ILNode_IndexerAccess_kind:
		case ILNode_LValueUnaryExpr_kind:
		case ILNode_LValueNoRefUnaryExpr_kind:
		case ILNode_AsIs_kind:
		case ILNode_MarkType_kind:
		case ILNode_SemGuard_kind:
		case ILNode_GlobalNamespace_kind:
		case ILNode_Overflow_kind:
		case ILNode_NoOverflow_kind:
		case ILNode_Pedantic_kind:
		case ILNode_NoPedantic_kind:
		case ILNode_BaseAccess_kind:
		case ILNode_BaseElement_kind:
		case ILNode_LValueBinaryExpr_kind:
		case ILNode_DerefField_kind:
		case ILNode_This_kind:
		case ILNode_LocalVar_kind:
		case ILNode_ArgumentVar_kind:
		case ILNode_RefArgumentVar_kind:
		case ILNode_StaticField_kind:
		case ILNode_MemberField_kind:
		case ILNode_ArrayAccess_kind:
		case ILNode_UnaryExpression_kind:
		case ILNode_DummyUnaryExpr_kind:
		case ILNode_LogicalNot_kind:
		case ILNode_Neg_kind:
		case ILNode_UnaryPlus_kind:
		case ILNode_Not_kind:
		case ILNode_UserUnaryOp_kind:
		case ILNode_PreInc_kind:
		case ILNode_PreDec_kind:
		case ILNode_PostInc_kind:
		case ILNode_PostDec_kind:
		case ILNode_UserIncOrDec_kind:
		case ILNode_UserPreInc_kind:
		case ILNode_UserPreDec_kind:
		case ILNode_UserPostInc_kind:
		case ILNode_UserPostDec_kind:
		case ILNode_IncOrDecPtr_kind:
		case ILNode_PreIncPtr_kind:
		case ILNode_PreDecPtr_kind:
		case ILNode_PostIncPtr_kind:
		case ILNode_PostDecPtr_kind:
		case ILNode_CastSimple_kind:
		case ILNode_CastType_kind:
		case ILNode_UserConversion_kind:
		case ILNode_AddressOf_kind:
		case ILNode_ToBool_kind:
		case ILNode_ToConst_kind:
		case ILNode_ToAttrConst_kind:
		case ILNode_VarArgExpand_kind:
		case ILNode_IsNull_kind:
		case ILNode_IsNonNull_kind:
		case ILNode_MakeRefAny_kind:
		case ILNode_RefType_kind:
		case ILNode_ArrayLength_kind:
		case ILNode_ArrayInit_kind:
		case ILNode_TypeOf_kind:
		case ILNode_SizeOf_kind:
		case ILNode_BinaryExpression_kind:
		case ILNode_DummyBinaryExpr_kind:
		case ILNode_UserCast_kind:
		case ILNode_IsUntyped_kind:
		case ILNode_AsUntyped_kind:
		case ILNode_LogicalAnd_kind:
		case ILNode_LogicalOr_kind:
		case ILNode_UserLogical_kind:
		case ILNode_UserLogicalAnd_kind:
		case ILNode_UserLogicalOr_kind:
		case ILNode_BinaryArith_kind:
		case ILNode_Add_kind:
		case ILNode_Sub_kind:
		case ILNode_Mul_kind:
		case ILNode_Div_kind:
		case ILNode_Rem_kind:
		case ILNode_BinaryBitwise_kind:
		case ILNode_And_kind:
		case ILNode_Or_kind:
		case ILNode_Xor_kind:
		case ILNode_BinaryShift_kind:
		case ILNode_Shl_kind:
		case ILNode_Shr_kind:
		case ILNode_UShr_kind:
		case ILNode_UserBinaryOp_kind:
		case ILNode_Concat_kind:
		case ILNode_DelegateAdd_kind:
		case ILNode_DelegateSub_kind:
		case ILNode_Assign_kind:
		case ILNode_Relational_kind:
		case ILNode_Eq_kind:
		case ILNode_Ne_kind:
		case ILNode_Lt_kind:
		case ILNode_Le_kind:
		case ILNode_Gt_kind:
		case ILNode_Ge_kind:
		case ILNode_Comma_kind:
		case ILNode_ArgList_kind:
		case ILNode_RefValue_kind:
		case ILNode_InvocationExpression_kind:
		case ILNode_StackAlloc_kind:
		case ILNode_TernaryExpression_kind:
		case ILNode_Conditional_kind:
		case ILNode_AssignExpression_kind:
		case ILNode_AssignAdd_kind:
		case ILNode_AssignSub_kind:
		case ILNode_AssignMul_kind:
		case ILNode_AssignDiv_kind:
		case ILNode_AssignRem_kind:
		case ILNode_AssignAnd_kind:
		case ILNode_AssignOr_kind:
		case ILNode_AssignXor_kind:
		case ILNode_AssignShl_kind:
		case ILNode_AssignShr_kind:
		case ILNode_AssignUShr_kind:
		case ILNode_VarArgList_kind:
		case ILNode_Argument_kind:
		case ILNode_ArgArray_kind:
		case ILNode_BoxingExpression_kind:
		case ILNode_As_kind:
		case ILNode_Is_kind:
		case ILNode_Box_kind:
		case ILNode_Unbox_kind:
		case ILNode_Error_kind:
		case ILNode_NewExpression_kind:
		case ILNode_ObjectCreationExpression_kind:
		case ILNode_DelegateCreationExpression_kind:
		case ILNode_DefaultConstructor_kind:
		case ILNode_BaseInit_kind:
		case ILNode_ThisInit_kind:
		case ILNode_NonStaticInit_kind:
		case ILNode_EmptyExpr_kind:
		case ILNode_Statement_kind:
		case ILNode_List_kind:
		case ILNode_Compound_kind:
		case ILNode_SwitchSectList_kind:
		case ILNode_CaseList_kind:
		case ILNode_CatchClauses_kind:
		case ILNode_Empty_kind:
		case ILNode_If_kind:
		case ILNode_LabelledStatement_kind:
		case ILNode_While_kind:
		case ILNode_Do_kind:
		case ILNode_For_kind:
		case ILNode_Foreach_kind:
		case ILNode_ForeachString_kind:
		case ILNode_ForeachCollection_kind:
		case ILNode_Switch_kind:
		case ILNode_Break_kind:
		case ILNode_LabelledBreak_kind:
		case ILNode_Continue_kind:
		case ILNode_LabelledContinue_kind:
		case ILNode_Return_kind:
		case ILNode_ReturnExpr_kind:
		case ILNode_Goto_kind:
		case ILNode_GotoLabel_kind:
		case ILNode_GotoCase_kind:
		case ILNode_GotoDefault_kind:
		case ILNode_NewScope_kind:
		case ILNode_SwitchSection_kind:
		case ILNode_CaseLabel_kind:
		case ILNode_DefaultLabel_kind:
		case ILNode_Throw_kind:
		case ILNode_ThrowExpr_kind:
		case ILNode_Try_kind:
		case ILNode_CatchClause_kind:
		case ILNode_FinallyClause_kind:
		case ILNode_Lock_kind:
		case ILNode_LocalVarDeclaration_kind:
		case ILNode_LocalConstDeclaration_kind:
		case ILNode_LineInfo_kind:
		case ILNode_EventAddOrRemove_kind:
		case ILNode_Declaration_kind:
		case ILNode_ClassDefn_kind:
		case ILNode_ScopeChange_kind:
		case ILNode_FieldDeclaration_kind:
		case ILNode_FieldDeclarator_kind:
		case ILNode_EventDeclaration_kind:
		case ILNode_EventDeclarator_kind:
		case ILNode_ProxyDeclaration_kind:
		case ILNode_MethodDeclaration_kind:
		case ILNode_PropertyDeclaration_kind:
		case ILNode_EnumMemberDeclaration_kind:
		case ILNode_DelegateMemberDeclaration_kind:
		case ILNode_FormalParameter_kind:
		case ILNode_AttributeTree_kind:
		case ILNode_AttributeSection_kind:
		case ILNode_Attribute_kind:
		case ILNode_AttrArgs_kind:
		case ILNode_NamedArg_kind:
		case ILNode_Fixed_kind:
		case ILNode_Using_kind:
		case ILNode_Unsafe_kind:
		{
			return ILNode_SemAnalysisType_6__((ILNode *)node__, info, parent);
		}
		break;

		default: break;
	}
	return (CSSemValueDefault);
}

#line 122 "cs_semantics.tc"


static ILType *CSSemFilterVoid(ILType *resultType, ILNode *type)
{
	if(resultType == ILType_Void)
	{
		CCErrorOnLine(yygetfilename(type), yygetlinenum(type),
					  "`void' type is not allowed in this context");
		resultType = ILType_Int32;
	}
	return resultType;
}

static ILType *CSSemValidate(ILNode *type, CSSemValue value)
{
	if(!CSSemIsType(value))
	{
		if(!CSSemIsError(value))
		{
			if(yyisa(type, ILNode_QualIdent) 
				|| yyisa(type, ILNode_Identifier))
			{
				CCErrorOnLine(yygetfilename(type), yygetlinenum(type),
						  "invalid type specification `%s' ", 
						  ILQualIdentName(type,0));
			}
			else if(yyisa(type, ILNode_MemberAccess))
			{
				CCErrorOnLine(yygetfilename(type), yygetlinenum(type),
						  "invalid type specification `%s' ", 
						  ILMemberAccessName(type));
			}
			else
			{
				CCErrorOnLine(yygetfilename(type), yygetlinenum(type),
						  "invalid type specification");
			}
		}
		return ILType_Int32;
	}
	else
	{
		return CSSemGetType(value);
	}
}

ILType *CSSemType(ILNode *type, ILGenInfo *info, ILNode **parent)
{
	return CSSemFilterVoid(CSSemTypeVoid(type, info, parent), type);
}

ILType *CSSemTypeLiteral(ILNode *type, ILGenInfo *info, ILNode **parent)
{
	CSSemValue value;
	int save;

	/* NULL is used in some places in the grammar to indicate "void" */
	if(!type) return CSSemFilterVoid(ILType_Void, type);
	
	save = info->inSemType;
	info->inSemType = info->typeGather;
	value = ILNode_SemAnalysisType(type, info, parent);
	info->inSemType = save;
	return CSSemFilterVoid(CSSemValidate(type, value),type);
}

ILType *CSSemTypeVoid(ILNode *type, ILGenInfo *info, ILNode **parent)
{
	CSSemValue value;
	int save;

	/* NULL is used in some places in the grammar to indicate "void" */
	if(!type) return ILType_Void;
 	
	save = info->inSemType;
	info->inSemType = info->typeGather;
	value = ILNode_SemAnalysisType(type, info, parent);
	info->inSemType = save;

	return CSSemValidate(type, value);
}

int CSSemExpectType (ILNode *type, ILGenInfo *info, ILNode **parent)
{
	CSSemValue value;
	value = ILNode_SemAnalysisType(type, info, parent);
	return CSSemIsType(value);
}

int CSSemBaseType(ILNode *type, ILGenInfo *info, ILNode **parent,
				  ILNode **baseNode, ILClass **baseClass)
{
	CSSemValue value;
	int save = info->inSemType;
	info->inSemType = info->typeGather;
	value = ILNode_SemAnalysisType(type, info, parent);
	info->inSemType = save;
	if(CSSemIsType(value))
	{
		*baseNode = 0;
		*baseClass = ILTypeToClass(info, CSSemGetType(value));
		return (*baseClass != 0);
	}
	else if(CSSemIsTypeNode(value))
	{
		*baseNode = CSSemGetTypeNode(value);
		*baseClass = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

int CSSemExpectValue(ILNode *node, ILGenInfo *info,
					 ILNode **parent, CSSemValue *value)
{
	*value = ILNode_SemAnalysis(node, info, parent);
	return CSSemIsValue(*value);
}

void CSSemProgramItem(ILGenInfo *info, ILProgramItem *item)
{
	ILGenItemContext context;
	ILNode *node;
	node = ILEnterProgramItemContext(info, item, CCGlobalScope, &context);
	if(node)
	{
		ILNode_SemAnalysis(node, info, &node);
		ILLeaveProgramItemContext(info, &context);
	}
}

#line 124 "cs_cast.tc"


const char *CSTypeToName(ILType *type)
{
	if(ILType_IsPrimitive(type))
	{
		/* Get the name of a primitive type */
		switch(ILType_ToElement(type))
		{
			case IL_META_ELEMTYPE_VOID:			return "void";
			case IL_META_ELEMTYPE_BOOLEAN:		return "bool";
			case IL_META_ELEMTYPE_I1:			return "sbyte";
			case IL_META_ELEMTYPE_U1:			return "byte";
			case IL_META_ELEMTYPE_I2:			return "short";
			case IL_META_ELEMTYPE_U2:			return "ushort";
			case IL_META_ELEMTYPE_CHAR:			return "char";
			case IL_META_ELEMTYPE_I4:			return "int";
			case IL_META_ELEMTYPE_U4:			return "uint";
			case IL_META_ELEMTYPE_I8:			return "long";
			case IL_META_ELEMTYPE_U8:			return "ulong";
			case IL_META_ELEMTYPE_R4:			return "float";
			case IL_META_ELEMTYPE_R8:			return "double";
			case IL_META_ELEMTYPE_R:			return "double";
			case IL_META_ELEMTYPE_I:			return "System.IntPtr";
			case IL_META_ELEMTYPE_U:			return "System.UIntPtr";
			case IL_META_ELEMTYPE_STRING:		return "System.String";
			case IL_META_ELEMTYPE_OBJECT:		return "System.Object";
			case IL_META_ELEMTYPE_TYPEDBYREF:	return "System.TypedReference";
		}
		if(type == ILType_Null)
		{
			return "null";
		}
	}
	else if(ILType_IsValueType(type) || ILType_IsClass(type))
	{
		/* Get the name of a value or class type */
		ILClass *classInfo = ILType_ToClass(type);
		const char *name = ILClass_Name(classInfo);
		const char *namespace = ILClass_Namespace(classInfo);
		const char *finalName;
		if(namespace)
		{
			finalName = ILInternAppendedString
						(ILInternAppendedString
							(ILInternString((char *)namespace, -1),
							 ILInternString((char *)".", 1)),
						 ILInternString((char *)name, -1)).string;
		}
		else
		{
			finalName = name;
		}
		if(ILClass_NestedParent(classInfo) != 0)
		{
			/* Prepend the name of the enclosing nesting class */
			const char *parentName = CSTypeToName
				(ILType_FromClass(ILClass_NestedParent(classInfo)));
			finalName = ILInternAppendedString
						(ILInternAppendedString
							(ILInternString((char *)parentName, -1),
							 ILInternString((char *)".", 1)),
						 ILInternString((char *)finalName, -1)).string;
		}
		return finalName;
	}
	else if(type != ILType_Invalid)
	{
		/* Get the name of a complex type */
		int kind = ILType_Kind(type);
		if(kind == IL_TYPE_COMPLEX_BYREF)
		{
			return ILInternAppendedString
					(ILInternString((char *)CSTypeToName(ILType_Ref(type)), -1),
					 ILInternString((char *)" &", 2)).string;
		}
		else if(kind == IL_TYPE_COMPLEX_PTR)
		{
			return ILInternAppendedString
					(ILInternString((char *)CSTypeToName(ILType_Ref(type)), -1),
					 ILInternString((char *)" *", 2)).string;
		}
		else if(kind == IL_TYPE_COMPLEX_ARRAY ||
			    kind == IL_TYPE_COMPLEX_ARRAY_CONTINUE)
		{
			ILType *elemType = ILType_ElemType(type);
			ILIntString str;
			ILIntString open;
			ILIntString close;
			ILIntString comma;
			while(ILType_IsComplex(elemType) && elemType != ILType_Invalid &&
			      (ILType_Kind(elemType) == IL_TYPE_COMPLEX_ARRAY ||
				   ILType_Kind(elemType) == IL_TYPE_COMPLEX_ARRAY))
			{
				elemType = ILType_ElemType(elemType);
			}
			str = ILInternString((char *)CSTypeToName(elemType), -1);
			open = ILInternString((char *)"[", 1);
			close = ILInternString((char *)"]", 1);
			comma = ILInternString((char *)",", 1);
			str = ILInternAppendedString(str, open);
			while(type != elemType)
			{
				if(ILType_Kind(type) == IL_TYPE_COMPLEX_ARRAY)
				{
					str = ILInternAppendedString(str, close);
					type = ILType_ElemType(type);
					if(type != elemType)
					{
						str = ILInternAppendedString(str, open);
					}
				}
				else
				{
					str = ILInternAppendedString(str, comma);
					type = ILType_ElemType(type);
				}
			}
			return str.string;
		}
		else if(kind == IL_TYPE_COMPLEX_CMOD_REQD ||
				kind == IL_TYPE_COMPLEX_CMOD_OPT)
		{
			ILIntString str;
			ILIntString temp;
			if(kind == IL_TYPE_COMPLEX_CMOD_REQD)
			{
				str = ILInternString("/* reqd ", -1);
			}
			else
			{
				str = ILInternString("/* opt ", -1);
			}
			temp = ILInternString
			  ((char *)(CSTypeToName(ILType_FromClass
			  				(type->un.modifier__.info__))), -1);
			str = ILInternAppendedString(str, temp);
			temp = ILInternString(" */ ", -1);
			str = ILInternAppendedString(str, temp);
			temp = ILInternString
				((char *)(CSTypeToName(type->un.modifier__.type__)), -1);
			str = ILInternAppendedString(str, temp);
			return str.string;
		}
		else if((kind & IL_TYPE_COMPLEX_METHOD) != 0)
		{
			ILIntString str;
			ILIntString temp;
			unsigned long num;
			unsigned long param;
			ILType *paramType;

			/* Convert the return type */
			str = ILInternString
				((char *)(CSTypeToName(ILTypeGetReturnWithPrefixes(type))), -1);

			/* Add the start of the parameter list */
			temp = ILInternString(" * (", -1);
			str = ILInternAppendedString(str, temp);

			/* Indicate if the type has a "this" parameter */
			if(ILType_HasThis(type))
			{
				temp = ILInternString("/*this,*/ ", -1);
				str = ILInternAppendedString(str, temp);
			}

			/* Add the parameters to the list */
			num = ILTypeNumParams(type);
			for(param = 1; param <= num; ++param)
			{
				paramType = ILTypeGetParamWithPrefixes(type, param);
				temp = ILInternString((char *)(CSTypeToName(paramType)), -1);
				str = ILInternAppendedString(str, temp);
				if(param < num)
				{
					temp = ILInternString(", ", 2);
					str = ILInternAppendedString(str, temp);
				}
			}

			/* Terminate the parameter list and return */
			temp = ILInternString(")", 1);
			str = ILInternAppendedString(str, temp);
			return str.string;
		}
	}
	return "invalid type";
}

#line 275 "cs_const.tc"


ILNode *CSBuiltinConstant(char *name)
{
	if(!strcmp(name, "float_min"))
	{
		static unsigned char const minFloat[4] =
			{0xFF, 0xFF, 0x7F, 0xFF};
		return ILNode_Float32_create(IL_READ_FLOAT(minFloat));
	}
	else if(!strcmp(name, "float_max"))
	{
		static unsigned char const maxFloat[4] =
			{0xFF, 0xFF, 0x7F, 0x7F};
		return ILNode_Float32_create(IL_READ_FLOAT(maxFloat));
	}
	else if(!strcmp(name, "float_epsilon"))
	{
		static unsigned char const epsFloat[4] =
			{0x01, 0x00, 0x00, 0x00};
		return ILNode_Float32_create(IL_READ_FLOAT(epsFloat));
	}
	else if(!strcmp(name, "double_min"))
	{
		static unsigned char const minDouble[8] =
			{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF};
		return ILNode_Float64_create(IL_READ_DOUBLE(minDouble));
	}
	else if(!strcmp(name, "double_max"))
	{
		static unsigned char const maxDouble[8] =
			{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F};
		return ILNode_Float64_create(IL_READ_DOUBLE(maxDouble));
	}
	else if(!strcmp(name, "double_epsilon"))
	{
		static unsigned char const epsDouble[8] =
			{0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
		return ILNode_Float64_create(IL_READ_DOUBLE(epsDouble));
	}
	else
	{
		CCError("unknown builtin constant `%s'", name);
		return ILNode_Null_create();
	}
}

#line 21 "cs_types.tc"


int CSHasUnsafeType(ILNode *node)
{
	if(!node)
	{
		return 0;
	}
	else if(yykind(node) == yykindof(ILNode_ArrayType))
	{
		return CSHasUnsafeType(((ILNode_ArrayType *)node)->type);
	}
	else if(yykind(node) == yykindof(ILNode_PtrType))
	{
		return 1;
	}
	else if(yykind(node) == yykindof(ILNode_MemberAccess))
	{
		return CSHasUnsafeType(((ILNode_MemberAccess *)node)->expr1);
	}
	else if(yykind(node) == yykindof(ILNode_List))
	{
		ILNode_ListIter iter;
		ILNode *child;
		ILNode_ListIter_Init(&iter, node);
		while((child = ILNode_ListIter_Next(&iter)) != 0)
		{
			if(yykind(child) == yykindof(ILNode_FormalParameter))
			{
				if(CSHasUnsafeType(((ILNode_FormalParameter *)node)->type))
				{
					return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return 0;
	}
}

#line 403 "cs_types.tc"


/*
 * Find the position to insert a generic type reference,
 * to re-arrange an expression that was parsed by the
 * "GenericReference" production in the grammar.
 */
static ILNode **FindGenericInsertPosition(ILNode *node, ILNode **parent)
{
	if(yyisa(node, ILNode_BinaryExpression))
	{
		ILNode_BinaryExpression *binary = (ILNode_BinaryExpression *)node;
		return FindGenericInsertPosition(binary->expr2, &(binary->expr2));
	}
	else if(yyisa(node, ILNode_UnaryExpression))
	{
		ILNode_UnaryExpression *unary = (ILNode_UnaryExpression *)node;
		return FindGenericInsertPosition(unary->expr, &(unary->expr));
	}
	else
	{
		return parent;
	}
}

ILNode *CSInsertGenericReference(ILNode *mainNode, ILNode *actuals)
{
	ILNode **parent = FindGenericInsertPosition(mainNode, &mainNode);
	*parent = ILNode_GenericReference_create(*parent, actuals);
	return mainNode;
}

ILNode *CSInsertTypeActuals(ILNode *type, ILNode *actuals)
{
	if(yyisa(actuals, ILNode_TypeActuals))
	{
		((ILNode_TypeActuals *)actuals)->left =
			CSInsertTypeActuals(type, ((ILNode_TypeActuals *)actuals)->left);
		return actuals;
	}
	else
	{
		return ILNode_TypeActuals_create(type, actuals);
	}
}

ILNode *CSInsertMethodInvocation(ILNode *mainNode, ILNode *parameters)
{
	ILNode **parent = FindGenericInsertPosition(mainNode, &mainNode);
	*parent = ILNode_InvocationExpression_create(*parent, parameters);
	return mainNode;
}

#line 13510 "cs_semantics.c"
