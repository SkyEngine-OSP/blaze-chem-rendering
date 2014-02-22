/* java_semantics.c.  Generated automatically by treecc */
#line 24 "java_semantics.tc"

#include <cscc/java/java_internal.h>
#include <cscc/java/java_semvalue.h>

#line 92 "java_semantics.tc"


#include <codegen/cg_nodemap.h>

#line 21 "java_lvalue.tc"


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
			JavaSemProgramItem(info, ILToProgramItem(ILField_Owner(field)));
		}
		else
		{
			/* We may already be inside the enumerated type, so go
			   directly to the field to avoid circularity problems */
			JavaSemProgramItem(info, ILToProgramItem(field));
		}
	}
	else
	{
		/* Perform semantic analysis on the value directly */
		JavaSemProgramItem(info, ILToProgramItem(field));
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
static JavaSemValue SemToLRValue(ILNode *node, ILGenInfo *info, ILNode **parent,
							   JavaSemValue value, char *name, ILNode *expr,
							   JavaSemValue *exprSem)
{
	ILNode *constNode;
	ILMethod *method;
	ILField *field;
	int allowConst;
	ILType *thisType;
	ILType *type;

	switch(JavaSemGetKind(value))
	{
		case JAVA_SEMKIND_FIELD:
		{
			/* Reference to a class field */
			field = JavaSemGetField(value);
			if(!(info->currentMethod))
			{
				/* We are performing semantic analysis of declarations,
				   where only literals and types are allowed */
				if(!ILField_IsStatic(field) || !ILField_IsLiteral(field))
				{
					CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`%s' is not declared as a type in the current scope",
					  name);
					JavaSemSetType(value, ILType_Int32);
					return value;
				}
			}

			/* Create the final semantic type */
			JavaSemSetLValue(value, ILField_Type(field));

			/* Check the usage of "readonly" fields */
			allowConst = 1;
			if(ILField_IsInitOnly(field))
			{
				method = ((ILNode_MethodDeclaration *)(info->currentMethod))
							->methodInfo;
				if(method && JavaGetAccessScope(info, 1) == ILField_Owner(field))
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
						/* Instance readonly used within instance constructor.
						   or the ".init" psuedo constructor
						   Nothing needs to be done here */
					}
					else
					{
						/* The field is used elsewhere, so make it an r-value */
						JavaSemSetRValue(value, ILField_Type(field));
					}
				}
				else
				{
					/* The field is used elsewhere, so make it an r-value */
					JavaSemSetRValue(value, ILField_Type(field));
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
					JavaSemSetConstant(value, type, evalValue);
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
							(expr, JavaSemGetType(*exprSem)), field);
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

		case JAVA_SEMKIND_METHOD_GROUP:
		{
			/* Reference to a method group */
			if(!(info->currentMethod))
			{
				/* We are performing semantic analysis of declarations,
				   which does not permit methods to be used as types */
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`%s' is not declared as a type in the current scope",
					  name);
				JavaSemSetType(value, ILType_Int32);
				return value;
			}

			/* Replace the node with either the object expression or "this" */
			if(expr)
			{
				*parent = ILNode_MarkType_create(expr, JavaSemGetType(*exprSem));
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
			if(exprSem && JavaSemIsSuper(*exprSem))
			{
				JavaSemSetSuper(value);
			}
		}
		break;
	}
	// TODO
	return value;
}

#line 771 "java_lvalue.tc"


/*
 * Wrap an array index expression in an overflow conversion to "int".
 */
static ILNode *ArrayIndexToInt(ILGenInfo *info, ILNode *node,
							   ILNode **parent, ILType *currentType)
{
	ILNode *result;
	if(info->overflowInsns)
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
							 ILNode **parent, ILType *type)
{
	if(ILCoerce(info, *node, parent, type, ILType_Int32, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_Int32);
	}
	else if(ILCoerce(info, *node, parent, type, ILType_UInt32, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_UInt32);
	}
	else if(ILCoerce(info, *node, parent, type, ILType_Int64, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_Int64);
	}
	else if(ILCoerce(info, *node, parent, type, ILType_UInt64, 1))
	{
		*node = ArrayIndexToInt
			(info, *parent, parent, ILType_Int64);
	}
	else
	{
		CCErrorOnLine(yygetfilename(*node), yygetlinenum(*node),
					  "no conversion from `%s' to `int'",
					  JavaTypeToName(type));
	}
}

static int GetArrayDepth(ILType *array)
{
	int dims=0;
	while(ILType_IsArray(array))
	{
		array=ILType_ElemType(array);
		dims++;
	}
	return dims;
}
#line 22 "java_stmt.tc"


/*
 * Determine if a tree node corresponds to the empty statement.
 */
#define	IsEmpty(node) ((node) == 0 || yykind((node)) == yykindof(ILNode_Empty))

/*
 * determine if a type1 implements type2
 */
#if USED
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
#endif
/*
 * Obtain the default scope of the class
 */
#define GetDefaultScope(info)	(((ILNode_ClassDefn*)(info->currentClass))->classInfo)

/*
 * Perform semantic analysis on a sub-statement.
 */
static void StmtSem(ILNode *node, ILGenInfo *info, ILNode **parent)
{
	JavaSemValue value;
	if(node)
	{
		value = ILNode_JSemAnalysis(node, info, parent);
		if(!JavaSemIsVoid(value) && !JavaSemIsValue(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid statement");
		}
	}
}

/*
 * Statement context flags.
 */
#define	JAVA_STMT_LOOP		1
#define	JAVA_STMT_SWITCH		2
#define	JAVA_STMT_TRY			4
#define	JAVA_STMT_CATCH		8
#define	JAVA_STMT_FINALLY		16

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

#line 553 "java_stmt.tc"


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

static ILNode* GetFallThroughNode(ILGenInfo *info, ILNode *nextSection)
{
	if(nextSection && yyisa(nextSection,ILNode_SwitchSection))
	{
		ILNode_ListIter iter;
		ILNode *nextLabel;
		ILNode_ListIter_Init(&iter,
				(((ILNode_SwitchSection*)nextSection)->caseList));
		nextLabel = ILNode_ListIter_Next(&iter);
		if(yyisa(nextLabel,ILNode_CaseLabel))
		{
			return ILNode_GotoCase_create(((ILNode_CaseLabel*)nextLabel)->expr);
		}
		else if(yyisa(nextLabel,ILNode_DefaultLabel))
		{
			return ILNode_GotoDefault_create();
		}
	}
	
	return ILNode_Break_create();	
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
	JavaSemValue value;
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
				if(!JavaSemExpectValue(caseLabel->expr, info,
									 &(caseLabel->expr), &value))
				{
					CCErrorOnLine(yygetfilename(caseLabel->expr),
								  yygetlinenum(caseLabel->expr),
								  "invalid case label expression");
					continue;
				}

				/* Coerce the case expression to the governing type */
				if(!ILCoerce(info, caseLabel->expr, &(caseLabel->expr),
							 JavaSemGetType(value), switchType,1))
				{
					CCErrorOnLine(yygetfilename(caseLabel->expr),
								  yygetlinenum(caseLabel->expr),
								  "no conversion from `%s' to `%s'",
								  JavaTypeToName(JavaSemGetType(value)),
								  JavaTypeToName(switchType));
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

		/* The body must end in some kind of return or jump statement */
		if(!ILNodeEndsInFlowChange(((ILNode_SwitchSection *)section)->stmt
									,info))
		{
			ILNode_ListIter lookAhead=iter1;
			ILNode *next=ILNode_ListIter_Next(&lookAhead);
			
			ILNode *jumpNext=GetFallThroughNode(info,next);
			
			/* We do the actual Semanalysis in the second phase */
			
			((ILNode_SwitchSection*)section)->stmt = 
									ILNode_Compound_CreateFrom(
										((ILNode_SwitchSection*)section)->stmt,
										jumpNext);
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
		ILNode_JSemAnalysis(((ILNode_SwitchSection *)section)->stmt, info,
						   &(((ILNode_SwitchSection *)section)->stmt));
		((ILNode_SwitchSection*)section)->visited=ILVisitMode_Done;
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
	   indexed table for the switch */
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
			if(((range * 80) / 100) <= numValues)
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
			if(((range * 80) / 100) <= numValues)
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

#line 22 "java_decls.tc"


/*
 * Error reporting function for "ILGenImplementsAllInterfaces".
 */
static void InterfaceErrorFunc(ILNode *node, ILClass *classInfo,
							   ILMember *missingMember)
{
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("`%s' does not implement `%s'"),
				  JavaTypeToName(ILClassToType(classInfo)),
				  JavaItemToName((ILProgramItem *)missingMember));
}

/*
 * Proxy reporting function for "ILGenImplementsAllInterfaces".
 */
static void InterfaceProxyFunc(ILNode *node, ILClass *classInfo,
							   ILMethod *missingMember,
							   ILMethod *proxyReplacement)
{
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("`%s' does not implement `%s'"),
				  JavaTypeToName(ILClassToType(classInfo)),
				  JavaItemToName((ILProgramItem *)missingMember));
}

/*  Since we can't (shouldn't?) inherit list from multiple types, this
 *  operation will iterate over a list of declarations adding to the 
 *  compound constructor */
static void JavaListGatherStaticCtor(ILNode_List *node, ILNode_List *ctor)
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

#line 392 "java_decls.tc"


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

void JavaAddInitCtor(ILGenInfo *info, ILNode *stmt)
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

#line 84 "java_invoke.tc"

/*
 * Reduce a method group to a set of candidates.
 */
static void ReduceMethodGroup(ILGenInfo *info, JavaEvalArg *args,
							  int numArgs, JavaSemValue *method)
{
	unsigned long itemNum;
	int candidateForm;
	ILProgramItem *itemInfo;
	ILMember *member;
	ILClass *lowestOwner = 0;
	ILClass *owner;

	/* Remove methods that aren't candidates */
	itemNum = 0;
	while((itemInfo = JavaGetGroupMember(JavaSemGetGroup(*method), itemNum)) != 0)
	{
		candidateForm = JavaItemIsCandidate(info, itemInfo, args, numArgs);
		if(candidateForm)
		{
			JavaSetGroupMemberForm(JavaSemGetGroup(*method), itemNum,
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
				else if(JavaIsBaseTypeFor(lowestOwner, owner))
				{
					lowestOwner = owner;
				}
			}
		}
		else
		{
			JavaSemModifyGroup(*method, JavaRemoveGroupMember
								(JavaSemGetGroup(*method), itemNum));
		}
	}

	/* Remove candidates in base classes */
	if(lowestOwner)
	{
		itemNum = 0;
		while((itemInfo = JavaGetGroupMember(JavaSemGetGroup(*method), itemNum))
					!= 0)
		{
			member = ILProgramItemToMember(itemInfo);
			if(member)
			{
				owner = ILClassResolve(ILMember_Owner(member));
				if(owner != lowestOwner)
				{
					JavaSemModifyGroup(*method, JavaRemoveGroupMember
										(JavaSemGetGroup(*method), itemNum));
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

#line 289 "java_invoke.tc"


void JavaItemCandidateError(ILNode *node, char *itemName, int isCtor,
						  void *group, JavaEvalArg *args, int numArgs)
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
			str = ILInternAppendedString
					(str, ILInternString
							((char *)JavaTypeToName(args[argNum].type), -1));
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
	while((item = JavaGetGroupMember(group, num)) != 0)
	{
		if(!num)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "candidates are: %s", JavaItemToName(item));
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "                %s", JavaItemToName(item));
		}
		++num;
	}
}

/*
 * Get the signature of a program item (method, property, or delegate).
 */
static ILType *GetItemSignature(ILProgramItem *item)
{
	ILMethod *method;

	/* Determine what kind of item we are dealing with */
	if((method = ILProgramItemToMethod(item)) != 0)
	{
		return ILMethod_Signature(method);
	}

	/* If we get here, then we do not know how to obtain the signature */
	return 0;
}


const char *JavaItemToName(ILProgramItem *item)
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
	ILClass *owner;

	/* Get the name of the item, and find an underlying method */
	if((method = ILProgramItemToMethod(item)) != 0)
	{
		name = ILMethod_Name(method);
		kind = IL_META_MEMBERKIND_METHOD;
		owner = ILMethod_Owner(method);
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

	/* The formatting is slightly different for constructors */
	if(!strcmp(name, ".ctor") || !strcmp(name, ".cctor"))
	{
		/* Append the class name to the string */
		str = ILInternAppendedString
				(str, ILInternString((char *)JavaTypeToName(type), -1));
	}
	else
	{
		/* Convert the return type into a string */
		str = ILInternAppendedString
				(str, ILInternString((char *)JavaTypeToName
										(ILTypeGetReturn(signature)), -1));
		str = ILInternAppendedString(str, ILInternString(" ", 1));

		/* Append the class name to the string */
		str = ILInternAppendedString
				(str, ILInternString((char *)JavaTypeToName(type), -1));

		/* Don't add the method name for delegates */
		if(kind != 0)
		{
			/* Append a dot to the string */
			str = ILInternAppendedString(str, ILInternString(".", 1));

			/* Append the method name to the string */
			str = ILInternAppendedString(str, ILInternString((char *)name, -1));
		}
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
	}
	str = ILInternAppendedString(str, ILInternString(")", 1));
	/* Return the final string to the caller */
	return str.string;
}

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

int JavaEvalArguments(ILGenInfo *info, ILNode *argList,
					ILNode **argListParent, JavaEvalArg **args)
{
	int argCount;
	int argNum;
	JavaEvalArg *argArray;
	ILNode *tempList;
	ILNode **tempParent;
	int tempNum;
	int haveErrors;
	JavaSemValue value;

	/* Get the number of arguments that have been supplied */
	argCount = CountArgList(argList);

	/* Bail out if there are no arguments */
	if(!argCount)
	{
		*args = 0;
		return 0;
	}

	/* Allocate an argument array */
	argArray = (JavaEvalArg *)ILMalloc(sizeof(JavaEvalArg) * argCount);
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
		if(!yyisa(tempList, ILNode_Argument))
		{
			/* Ordinary argument */
			value = ILNode_JSemAnalysis(tempList, info, tempParent);
			argArray[argNum].node = *tempParent;
			argArray[argNum].parent = tempParent;
			if(JavaSemIsValue(value))
			{
				argArray[argNum].type = JavaSemGetType(value);
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

void JavaEvalFreeArguments(JavaEvalArg *args)
{
	if(args)
	{
		ILFree(args);
	}
}

/*
 * Get the type and modifier information associated with
 * an item parameter.  The first parameter is 0.  Returns
 * ILType_Invalid if the parameter index is invalid.
 */
static ILType *GetItemParamType(ILProgramItem *item, ILType *signature,
								int paramNum)
{
	int numParams = ILGenNumUsableParams(signature);
	int firstParam;
	ILType *paramType;
	ILMethod *method;

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
		ILGenGetParamInfo(method, signature, paramNum + firstParam,
									  &paramType);
	}
	return paramType;
}

/*
 * Get the type information associated with an item parameter,
 * given that its expansion form is known.
 */
static ILType *GetItemExpandedType(ILProgramItem *item, ILType *signature,
								   int form, int paramNum)
{
	ILType *paramType;
	paramType = GetItemParamType(item, signature, paramNum);
	if(paramType == ILType_Invalid)
	{
		return ILType_Invalid;
	}
	return paramType;
}

int JavaItemIsCandidate(ILGenInfo *info, ILProgramItem *item,
					  JavaEvalArg *args, int numArgs)
{
	ILType *signature = GetItemSignature(item);
	ILType *paramType;
	int argNum, paramNum;

	/* If the item does not have a signature, then bail out */
	if(!signature)
	{
		return 0;
	}

	/* Scan through the parameters looking for a match */
	paramNum = 0;
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		paramType = GetItemParamType(item, signature, paramNum);
		if(paramType == ILType_Invalid)
		{
			/* Too many arguments were supplied */
			return 0;
		}
		else
		{
			/* Match anything that can coerce to the parameter type */
			if (!ILCanCoerceNode(info, args[argNum].node, 
									args[argNum].type, paramType,1))
			{
				return 0;
			}
			++paramNum;
		}
	}

	/* Get the next parameter type, which must either be
	   a "params" array, or the end of the parameter list */
	paramType = GetItemParamType(item, signature, paramNum);
	if(paramType == ILType_Invalid)
	{
		/* The candidate was matched in its normal form */
		return 1;
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
					  JavaEvalArg *args, int numArgs)
{
	ILType *signature1 = GetItemSignature(item1);
	ILType *signature2 = GetItemSignature(item2);
	int argNum;
	int paramNum1;
	int paramNum2;
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
									form1, paramNum1++);
		type2 = GetItemExpandedType(item2, signature2,
									form2, paramNum2++);
		atype = args[argNum].type;

		/* Skip the argument if "out", "ref", or "arglist", because such
		   arguments must always be identical, so neither can be better */
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

ILProgramItem *JavaBestCandidate(ILGenInfo *info, void *group,
						       JavaEvalArg *args, int numArgs)
{
	unsigned long itemNum = 1;
	ILProgramItem *bestItem = JavaGetGroupMember(group, 0);
	ILProgramItem *testItem;
	int better;
	int form1 = JavaGetGroupMemberForm(group, 0);
	int form2;
	int sawBetter = 0;
	while((testItem = JavaGetGroupMember(group, itemNum)) != 0)
	{
		form2 = JavaGetGroupMemberForm(group, itemNum);
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

ILType *JavaItemCoerceArgs(ILGenInfo *info, ILProgramItem *item,
						 JavaEvalArg *args, int numArgs,
						 ILNode **argListParent)
{
	ILType *signature = GetItemSignature(item);
	int argNum, paramNum;
	ILType *paramType;

	/* Coerce the fixed parameters */
	paramNum = 0;
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		paramType = GetItemParamType(item, signature, paramNum);
		ILCoerce(info, args[argNum].node,
				 args[argNum].parent, args[argNum].type, paramType,0);
		++paramNum;
	}

	/* Return the item's return type to the caller */
	return ILTypeGetReturn(signature);
}

#line 337 "java_misc.tc"


static ILType * GetUnderlyingElementType(ILType *arrayType)
{
	if(ILType_IsArray(arrayType))
	{
		return GetUnderlyingElementType(ILType_ElemType(arrayType));
	}
	return arrayType;
}

void GenArrayOfArray(ILGenInfo *info, ILType *arrayType,
						ILNode *dims)
{
	ILNode *argArray= ILNode_ArgArray_create(ILType_UInt32,
								CountArgList(dims), 
								dims);
	
	ILGenTypeToken(info,IL_OP_LDTOKEN,arrayType);
	ILGenAdjust(info,1);
	
	/* Convert the type handle into a type object */
	ILGenCallByName(info,
			"class [.library]System.Type "
				"[.library]System.Type::GetTypeFromHandle"
				"(valuetype [.library]System.RuntimeTypeHandle)");
		
	ILNode_GenValue(argArray,info);

	ILGenCallByName(info,
			"class [.library]System.Array "
			"['java.lang']dotgnu.javawrappers.ArrayWrapper::CreateMultiArray"
			"(class [.library]System.Type type, unsigned int32[] dims)");
	ILGenAdjust(info,-1);
	ILGenTypeToken(info, IL_OP_CASTCLASS , arrayType);
}

#line 21 "java_oper.tc"


/*
 * Perform constant evaluation on an operator node.
 */
static void EvalOperator(ILGenInfo *info, ILNode *node,
					     ILNode **parent, JavaSemValue *result)
{
	ILEvalValue evalValue;
	if(ILNode_EvalConst(node, info, &evalValue))
	{
		JavaSemSetConstant(*result, JavaSemGetType(*result), evalValue);
		JavaSemReplaceWithConstant(parent, *result);
	}
}

/*
 * Determine if a semantic value is zero.  Used to support
 * implicit coercions from zero to enumerated types.
 */
static int IsEnumZero(JavaSemValue *value)
{
	ILEvalValue *evalValue = JavaSemGetConstant(*value);
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
 * Coerce the elements of an array initializer to a common type.
 */
static void CoerceArrayInit(ILGenInfo *info, ILNode *expr,
							ILNode **parent, ILType *type)
{
	ILNode_ListIter iter;
	ILNode *node;
	JavaSemValue value;

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
		if(!JavaSemExpectValue(expr, info, parent, &value))
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  _("invalid array initializer element"));
		}
		else if(!ILCanCoerceNode(info, *parent, JavaSemGetType(value), type,1))
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
			  _("incompatible types in initializer: no conversion "
			  		"from `%s' to `%s'"),
			  JavaTypeToName(JavaSemGetType(value)), JavaTypeToName(type));
		}
		else
		{
			ILCoerce(info, *parent, parent, JavaSemGetType(value), type,1);
		}
	}
}


#line 178 "java_oper.tc"

/*
 * Common semantic analysis for operation-based assignment operators.
 */
static JavaSemValue AssignSem(ILGenInfo *info, 
                            ILNode_AssignExpression *anode,
					        ILNode **assignParent,
							const ILOperator *table, const char *name,
							const char *errorName)
{
	/*  Re-jigger arguments from the original version  */
	ILNode_BinaryExpression *node = (ILNode_BinaryExpression *)anode->assign;
	ILNode **parent = &(anode->assign);
	const ILOperator *oper;
	JavaSemValue value1;
	JavaSemValue value2;
	ILType *resultType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));
	anode->lvalue = node->expr1;  /* Preserve lvalue for later */
	value2 = ILNode_JSemAnalysis(node->expr2, info, &(node->expr2));

	if(!JavaSemIsLValue(value1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid lvalue in assignment");
		if(!JavaSemIsRValue(value1))
		{
			JavaSemSetRValue(value1, ILType_Int32);
		}
		return value1;
	}

	/* The second argument must be a value */
	if(!JavaSemIsValue(value2))
	{
		goto error;
	}

	/* Replace node->expr1 with an empty expression, so that it
	   doesn't double-evaluate during code generation */
	node->expr1 = ILNode_EmptyExpr_create
			(ILTypeToMachineType(JavaSemGetType(value1)));

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, JavaSemGetType(value1),
								JavaSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			JavaSemSetRValue(value1, resultType);
		}
		else
		{
			JavaSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		return value1;
	}

	/* Should we be performing string concatenation? */
	if(ILTypeIsStringClass(JavaSemGetType(value1)) && yyisa(node, ILNode_Add))
	{
		if(!ILTypeIsStringClass(JavaSemGetType(value2)))
		{
			/* Convert the second argument into "ObjectRef" */
			ILCast(info, node->expr2, &(node->expr2), JavaSemGetType(value2),
				   ILFindSystemType(info, "Object"),1);
		}
		*parent = ILNode_Concat_create(node->expr1, node->expr2);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		JavaSemSetRValue(value1, JavaSemGetType(value1));
		return value1;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `%s'", errorName);
	if(JavaSemIsLValue(value1))
	{
		JavaSemSetRValue(value1, JavaSemGetType(value1));
	}
	else
	{
		JavaSemSetRValue(value1, ILType_Int32);
	}
	return value1;
}
#line 373 "java_oper.tc"


/*
 * Common semantic analysis function for binary arithmetic operators.
 */
static JavaSemValue BinarySem(ILGenInfo *info, ILNode_BinaryExpression *node,
					        ILNode **parent, const ILOperator *table,
					        const char *name, const char *errorName,
							int canCoerce)
{
	const ILOperator *oper;
	JavaSemValue value1;
	JavaSemValue value2;
	ILType *resultType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_JSemAnalysis(node->expr2, info, &(node->expr2));

	/* The two arguments must be values */
	if(!JavaSemIsValue(value1) || !JavaSemIsValue(value2))
	{
		goto error;
	}

	/* try constant coercion before operator lookup */
	if(canCoerce && ILCanCoerceNodeKind(info,node->expr1,JavaSemGetType(value1),
			JavaSemGetType(value2),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr1,&(node->expr1),JavaSemGetType(value1),
			JavaSemGetType(value2),IL_CONVERT_CONSTANT,1);
		JavaSemSetRValue(value1,JavaSemGetType(value2));
	}
	else if(canCoerce && 
			ILCanCoerceNodeKind(info,node->expr2,JavaSemGetType(value2),
				JavaSemGetType(value1),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr2,&(node->expr2),JavaSemGetType(value2),
			JavaSemGetType(value1),IL_CONVERT_CONSTANT,1);
		JavaSemSetRValue(value2,JavaSemGetType(value1));
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, JavaSemGetType(value1),
								JavaSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			JavaSemSetRValue(value1, resultType);
		}
		else
		{
			JavaSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* As a last measure , try coercing the nodes */
	if(ILCanCoerceNode(info, node->expr1, JavaSemGetType(value1),
					   JavaSemGetType(value2),1))
	{
		ILCoerce(info, node->expr1, &(node->expr1), JavaSemGetType(value1),
				 JavaSemGetType(value2),1);
		JavaSemSetRValue(value1, JavaSemGetType(value2));
	}
	else if(ILCanCoerceNode(info, node->expr2, JavaSemGetType(value2),
					   JavaSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), JavaSemGetType(value2),
				 JavaSemGetType(value1),1);
		JavaSemSetRValue(value2, JavaSemGetType(value1));
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, JavaSemGetType(value1),
								JavaSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			JavaSemSetRValue(value1, resultType);
		}
		else
		{
			JavaSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `%s'", errorName);
	JavaSemSetRValue(value1, ILType_Int32);
	return value1;
}

#line 697 "java_oper.tc"


/*
 * Common semantic analysis function for unary arithmetic operators.
 */
static JavaSemValue UnarySem(ILGenInfo *info, ILNode_UnaryExpression *node,
					 	   ILNode **parent, const ILOperator *table,
						   const char *name, const char *errorName)
{
	const ILOperator *oper;
	JavaSemValue value;
	ILType *resultType;

	/* Perform semantic analysis on the argument */
	value = ILNode_JSemAnalysis(node->expr, info, &(node->expr));

	/* The argument must be a value */
	if(!JavaSemIsValue(value))
	{
		goto error;
	}

	/* Look for a builtin operator */
	oper = ILFindUnaryOperator(table, JavaSemGetType(value), &resultType);
	if(oper)
	{
		ILApplyUnaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			JavaSemSetRValue(value, resultType);
		}
		else
		{
			JavaSemSetRValue(value, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value);
		return value;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to unary `%s'", errorName);
	JavaSemSetRValue(value, ILType_Int32);
	return value;
}
#line 772 "java_oper.tc"


/*
 * Perform semantic analysis for increment or decrement operators.
 */
static JavaSemValue IncOrDecSem(ILGenInfo *info, ILNode_UnaryExpression *node,
							  ILNode **parent, const char *opName,
							  const char *errorName)
{
	JavaSemValue value;
	ILMachineType machineType;

	/* Perform semantic analysis on the argument, which must be an lvalue */
	value = ILNode_JSemAnalysis(node->expr, info, &(node->expr));
	if(!JavaSemIsLValue(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid lvalue in increment");
		if(!JavaSemIsRValue(value))
		{
			JavaSemSetRValue(value, ILType_Int32);
		}
		return value;
	}

	/* The final result will be an rvalue */
	JavaSemSetRValue(value, JavaSemGetType(value));

	/* Can we use the builtin version of the operator? */
	machineType = ILTypeToMachineType(JavaSemGetType(value));
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

		default: break;
	}

	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operands to unary `%s'", errorName);
	if(!JavaSemIsRValue(value))
	{
		JavaSemSetRValue(value, ILType_Int32);
	}
	return value;
}

#line 903 "java_oper.tc"


/*
 * Perform semantic analysis for the equality or inequality operators.
 */
static JavaSemValue EqualitySem(ILGenInfo *info, ILNode_BinaryExpression *node,
							  ILNode **parent, const ILOperator *table,
							  const char *name, const char *errorName)
{
	const ILOperator *oper;
	JavaSemValue value1;
	JavaSemValue value2;
	ILType *resultType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_JSemAnalysis(node->expr2, info, &(node->expr2));

	/* The two arguments must be values */
	if(!JavaSemIsValue(value1) || !JavaSemIsValue(value2))
	{
		goto error;
	}

	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, JavaSemGetType(value1),
								JavaSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		JavaSemSetRValue(value1, ILType_Boolean);
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* If one of the arguments is a string and the other is null,
	   then the code generator knows how to handle the operation */
	if(ILTypeIsStringClass(JavaSemGetType(value1)))
	{
		if(JavaSemGetType(value2) == ILType_Null)
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
			JavaSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
	}
	else if(JavaSemGetType(value1) == ILType_Null &&
			ILTypeIsStringClass(JavaSemGetType(value2)))
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
		JavaSemSetRValue(value1, ILType_Boolean);
		return value1;
	}

	/* If both arguments are object references, then we can compare them
	   using the built-in code generator logic */
	if(JavaSemGetType(value1) != ILType_Null &&
	   ILTypeIsReference(JavaSemGetType(value1)))
	{
		if(JavaSemGetType(value2) == ILType_Null)
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
			JavaSemSetRValue(value1, ILType_Boolean);
			return value1;
		}
		else if(ILTypeIsReference(JavaSemGetType(value2)))
		{
			if(ILCanCoerceNode(info, node->expr1, JavaSemGetType(value1),
							   JavaSemGetType(value2),1) ||
			   ILCanCoerceNode(info, node->expr2, JavaSemGetType(value2),
			   				   JavaSemGetType(value1),1))
			{
				JavaSemSetRValue(value1, ILType_Boolean);
				return value1;
			}
		}
	}
	else if(JavaSemGetType(value1) == ILType_Null &&
			ILTypeIsReference(JavaSemGetType(value2)))
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
		JavaSemSetRValue(value1, ILType_Boolean);
		return value1;
	}

	/* Try coercion as a last resort */
	if(ILCanCoerceNode(info, node->expr1, JavaSemGetType(value1),
					   JavaSemGetType(value2),1))
	{
		ILCoerce(info, node->expr1, &(node->expr1), JavaSemGetType(value1),
				 JavaSemGetType(value2),1);
		JavaSemSetRValue(value1, ILType_Boolean);
	}
	else if(ILCanCoerceNode(info, node->expr2, JavaSemGetType(value2),
					   JavaSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), JavaSemGetType(value2),
				 JavaSemGetType(value1),1);
		JavaSemSetRValue(value1, ILType_Boolean);
	}
	/* Look for a builtin operator */
	oper = ILFindBinaryOperator(table, JavaSemGetType(value1),
								JavaSemGetType(value2), &resultType,
								IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		JavaSemSetRValue(value1, ILType_Boolean);
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `%s'", errorName);
	JavaSemSetRValue(value1, ILType_Int32);
	return value1;
}

#line 2783 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_1__(ILNode_JPrimitiveType *node, ILGenInfo * info, ILNode * * parent)
#line 31 "java_types.tc"
{
	JavaSemValue value;
	JavaSemSetType(value, ILType_FromElement(node->elementType));
	return value;
}
#line 2792 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_2__(ILNode_JArrayType *node, ILGenInfo * info, ILNode * * parent)
#line 78 "java_types.tc"
{
	JavaSemValue value;
	ILNode *elemType;
	ILNode **elemTypeParent;
	ILType *arrayType;
	ILType *type;

	/* Find the element type at the end of the rank specifiers */
	elemType = node->type;
	elemTypeParent = &(node->type);
	while(yykind(elemType) == yykindof(ILNode_JArrayType))
	{
		elemTypeParent = &(((ILNode_JArrayType *)elemType)->type);
		elemType = ((ILNode_JArrayType *)elemType)->type;
	}

	/* Perform semantic analysis on the element type */
	type = JavaSemTypeLiteral(elemType, info, elemTypeParent);

	/* Create the array type from the outermost rank inwards */
	arrayType = ILTypeCreateArray(info->context, node->numDimensions, type);
	if(!arrayType)
	{
		CCOutOfMemory();
	}
	elemType = node->type;
	while(yykind(elemType) == yykindof(ILNode_JArrayType))
	{
		arrayType = ILTypeCreateArray
			(info->context, ((ILNode_JArrayType *)elemType)->numDimensions,
			 arrayType);
		if(!arrayType)
		{
			CCOutOfMemory();
		}
		elemType = ((ILNode_JArrayType *)elemType)->type;
	}

	/* Return the final array type */
	JavaSemSetType(value, arrayType);
	return value;
}
#line 2838 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_3__(ILNode_JSystemType *node, ILGenInfo * info, ILNode * * parent)
#line 41 "java_types.tc"
{
	JavaSemValue value;
	JavaSemSetType(value, ILFindNonSystemType(info, node->className,"java.lang"));
	if(!(JavaSemGetType(value)))
	{
		value=ILNode_JSemAnalysis(
				ILQualIdentTwo("java.lang",node->className),info,parent);
	}
	if(!(JavaSemGetType(value)))
	{
		CCOutOfMemory();
	}
	return value;
}
#line 2856 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_4__(ILNode_ILSystemType *node, ILGenInfo * info, ILNode * * parent)
#line 57 "java_types.tc"
{
	JavaSemValue value;
	JavaSemSetType(value, ILFindSystemType(info, node->className));
	if(!(JavaSemGetType(value)))
	{
		value=ILNode_JSemAnalysis(
				ILQualIdentTwo("System",node->className),info,parent);
	}
	if(!(JavaSemGetType(value)))
	{
		CCOutOfMemory();
	}
	return value;
}
#line 2874 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_5__(ILNode_Null *node, ILGenInfo * info, ILNode * * parent)
#line 26 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_ObjectRef;
	evalValue.un.oValue = 0;
	JavaSemSetConstant(value, ILType_Null, evalValue);
	return value;
}
#line 2886 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_6__(ILNode_True *node, ILGenInfo * info, ILNode * * parent)
#line 40 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Boolean;
	evalValue.un.i4Value = 1;
	JavaSemSetConstant(value, ILType_Boolean, evalValue);
	return value;
}
#line 2898 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_7__(ILNode_False *node, ILGenInfo * info, ILNode * * parent)
#line 53 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Boolean;
	evalValue.un.i4Value = 0;
	JavaSemSetConstant(value, ILType_Boolean, evalValue);
	return value;
}
#line 2910 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_8__(ILNode_UInt8 *node, ILGenInfo * info, ILNode * * parent)
#line 63 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt8;
	evalValue.un.i4Value = (ILInt32)(node->value);
	JavaSemSetConstant(value, ILType_UInt8, evalValue);
	return value;
}
#line 2922 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_9__(ILNode_Int16 *node, ILGenInfo * info, ILNode * * parent)
#line 73 "java_const.tc"
{
	JavaSemValue value;
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
	JavaSemSetConstant(value, ILType_Int16, evalValue);
	return value;
}
#line 2941 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_10__(ILNode_Char *node, ILGenInfo * info, ILNode * * parent)
#line 89 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Char;
	evalValue.un.i4Value = (ILInt32)(node->value);
	JavaSemSetConstant(value, ILType_Char, evalValue);
	return value;
}
#line 2953 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_11__(ILNode_Int32 *node, ILGenInfo * info, ILNode * * parent)
#line 98 "java_const.tc"
{
	JavaSemValue value;
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
	JavaSemSetConstant(value, ILType_Int32, evalValue);
	return value;
}
#line 2972 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_12__(ILNode_Int64 *node, ILGenInfo * info, ILNode * * parent)
#line 129 "java_const.tc"
{
	JavaSemValue value;
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
	JavaSemSetConstant(value, ILType_Int64, evalValue);
	return value;
}
#line 2991 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_13__(ILNode_Int *node, ILGenInfo * info, ILNode * * parent)
#line 114 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	ILNode_EvalConst(node, info, &evalValue);
	if(evalValue.valueType == ILMachineType_Int64)
	{
		JavaSemSetConstant(value, ILType_Int64, evalValue);
	}
	else
	{
		JavaSemSetConstant(value, ILType_Int, evalValue);
	}
	return value;
}
#line 3009 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_14__(ILNode_Float32 *node, ILGenInfo * info, ILNode * * parent)
#line 149 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Float32;
	evalValue.un.r4Value = (ILFloat)(node->value);
	JavaSemSetConstant(value, ILType_Float32, evalValue);
	return value;
}
#line 3021 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_15__(ILNode_Float64 *node, ILGenInfo * info, ILNode * * parent)
#line 158 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Float64;
	evalValue.un.r8Value = node->value;
	JavaSemSetConstant(value, ILType_Float64, evalValue);
	return value;
}
#line 3033 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_16__(ILNode_Float *node, ILGenInfo * info, ILNode * * parent)
#line 167 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_NativeFloat;
	evalValue.un.r8Value = node->value;
	JavaSemSetConstant(value, ILType_Float, evalValue);
	return value;
}
#line 3045 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_17__(ILNode_String *node, ILGenInfo * info, ILNode * * parent)
#line 180 "java_const.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_String;
	evalValue.un.strValue.str = node->str;
	evalValue.un.strValue.len = node->len;
	JavaSemSetConstant(value, ILFindSystemType(info, "String"), evalValue);
	return value;
}
#line 3058 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_18__(ILNode_BaseAccess *node, ILGenInfo * info, ILNode * * parent)
#line 947 "java_lvalue.tc"
{
	JavaSemValue value;
	JavaSemValue value2;
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
		JavaSemSetType(value, ILType_Int32);
		return value;
	}

	/* Find the parent class to start searching from */
	classInfo = ILClass_Parent(ILMethod_Owner(caller->methodInfo));
	if(!classInfo)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "cannot use base reference in `System.Object'");
		JavaSemSetType(value, ILType_Int32);
		return value;
	}

	/* Get the semantic value for the "base" part of the node */
	JavaSemSetRValue(value, ILClassToType(classInfo));
	JavaSemSetSuper(value);

	/* Construct a dummy "this" expression to represent the object */
	thisExpr = ILNode_This_create();

	/* Resolve the member */
	name = ILQualIdentName(node->expr, 0);
	value2 = JavaResolveMemberName(info, (ILNode *)node, value, name, 0);

	/* Convert the result into an l-value or r-value and return it */
	return SemToLRValue((ILNode *)node, info, parent, value2,
						name, thisExpr, &value);
}
#line 3105 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_19__(ILNode_MemberAccess *node, ILGenInfo * info, ILNode * * parent)
#line 692 "java_lvalue.tc"
{
	JavaSemValue value;
	JavaSemValue value2;
	char *name;
	ILEvalValue evalue;

	/* Get the semantic value for the left part of the identifier */
	value = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));

	/* Set the rvalue if it is a constant expression */
	if(yyisa(node->expr1,ILNode_Constant))
	{
		if(ILNode_EvalConst(node->expr1,info,&evalue))
		{
			/* Set the RValue to the type .. to handle Boxing later on*/
			if(JavaSemGetType(value)==ILType_Null)
			{
				JavaSemSetRValue(value,ILValueTypeToType(info,evalue.valueType));
			}
			else
			{
				JavaSemSetRValue(value,JavaSemGetType(value));
			}
		}
	}

	/* Convert the second subexpression into a name */
	name = ILQualIdentName(node->expr2, 0);

	/* Check for the special case of "array.Length" */
	if(JavaSemIsValue(value) && !strcmp(name, "Length") &&
	   ILType_IsSimpleArray(JavaSemGetType(value)))
	{
		*parent = ILNode_ArrayLength_create(node->expr1);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		*parent = ILNode_CastSimple_create(*parent, ILMachineType_Int32);
		JavaSemSetRValue(value, ILType_Int32);
		return value;
	}
	else if(JavaSemIsValue(value) && !strcmp(name, "length") &&
	   ILType_IsSimpleArray(JavaSemGetType(value)))
	{
		*parent = ILNode_ArrayLength_create(node->expr1);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		*parent = ILNode_CastSimple_create(*parent, ILMachineType_Int32);
		JavaSemSetRValue(value, ILType_Int32);
		return value;
	}

	/* Resolve the member */
	value2 = JavaResolveMemberName(info, (ILNode *)node, value, name, 0);

	if (JavaSemGetKind(value2) != JAVA_SEMKIND_VOID)
	{
		/* Convert the result into an l-value or r-value and return it */
		return SemToLRValue((ILNode *)node, info, parent, value2,
					    name, node->expr1, &value);
	}
	return JavaSemValueDefault;
}
#line 3171 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_20__(ILNode_This *node, ILGenInfo * info, ILNode * * parent)
#line 915 "java_lvalue.tc"
{
	JavaSemValue value;
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
		JavaSemSetLValue(value, type);
	}
	else
	{
		JavaSemSetRValue(value, type);
	}
	return value;
}
#line 3202 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_21__(ILNode_ArrayAccess *node, ILGenInfo * info, ILNode * * parent)
#line 847 "java_lvalue.tc"
{
	JavaSemValue value;
	JavaEvalArg *args;
	int numArgs, argNum;

	/* Perform semantic analysis on the array expression */
	if(!JavaSemExpectValue(node->array, info, &(node->array), &value))
	{
		CCErrorOnLine(yygetfilename(node->array), yygetlinenum(node->array),
					  "array expected");
		JavaSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Perform semantic analysis on the index argument list */
	numArgs = JavaEvalArguments(info, node->indices, &(node->indices), &args);
	if(numArgs < 0)
	{
		JavaSemSetLValue(value, ILType_Int32);
		return value;
	}

	/* Is this an array element or an indexer access? */
	if(ILType_IsArray(JavaSemGetType(value)))
	{
		/* All arguments must be coercable to one of "int", "uint",
		   "long", or "ulong", and are converted to "int" */
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			CoerceArrayIndex(info, &(args[argNum].node), args[argNum].parent,
			            	 args[argNum].type);
		}
		
		/* Check the array's rank */
		if(numArgs > GetArrayDepth(JavaSemGetType(value)))
		{
			CCErrorOnLine(yygetfilename(node->indices),
						  yygetlinenum(node->indices),
						  "incorrect number of indices for `%s'",
						  JavaTypeToName(JavaSemGetType(value)));
		}

		/* Store the type information in the node for the code generator */
		node->arrayType = JavaSemGetType(value);
		node->elemType = node->arrayType;

		for(argNum=0 ; argNum<numArgs; argNum++)
		{
			node->elemType=ILType_ElemType(node->elemType);	
		}

		/* Construct the semantic value for the element type */
		JavaSemSetLValue(value, node->elemType);
	}
	else
	{
		/* Not an appropriate value for array or indexer access */
		CCErrorOnLine(yygetfilename(node->array), yygetlinenum(node->array),
					  "array expected");
		JavaSemSetLValue(value, ILType_Int32);
	}

	/* Free the argument list and return the element type */
	JavaEvalFreeArguments(args);
	return value;
}
#line 3272 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_22__(ILNode_LogicalNot *node, ILGenInfo * info, ILNode * * parent)
#line 1122 "java_oper.tc"
{
	JavaSemValue value;

	/* Perform semantic analysis on the argument value */
	if(!JavaSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		goto error;
	}

	/* If the type is not boolean, we need to look for an operator */
	if(JavaSemGetType(value) == ILType_Boolean)
	{
		/* Builtin "!" operator: the result is always boolean */
		JavaSemSetRValue(value, ILType_Boolean);
		EvalOperator(info, *parent, parent, &value);
		return value;
	}

error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operand to unary `!'");
	JavaSemSetRValue(value, ILType_Boolean);
	return value;
}
#line 3300 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_23__(ILNode_Neg *node, ILGenInfo * info, ILNode * * parent)
#line 749 "java_oper.tc"
{
	return UnarySem(info, (ILNode_UnaryExpression *)node,
					parent, ILOp_Neg, "op_UnaryNegation", "-");
}
#line 3308 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_24__(ILNode_UnaryPlus *node, ILGenInfo * info, ILNode * * parent)
#line 758 "java_oper.tc"
{
	return UnarySem(info, (ILNode_UnaryExpression *)node,
				  	parent, ILOp_UnaryPlus, "op_UnaryPlus", "+");
}
#line 3316 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_25__(ILNode_Not *node, ILGenInfo * info, ILNode * * parent)
#line 766 "java_oper.tc"
{
	return UnarySem(info, (ILNode_UnaryExpression *)node, parent, ILOp_Not,
					"op_OnesComplement", "~");
}
#line 3324 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_26__(ILNode_PreInc *node, ILGenInfo * info, ILNode * * parent)
#line 841 "java_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Increment", "++");
}
#line 3332 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_27__(ILNode_PreDec *node, ILGenInfo * info, ILNode * * parent)
#line 850 "java_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Decrement", "--");
}
#line 3340 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_28__(ILNode_PostInc *node, ILGenInfo * info, ILNode * * parent)
#line 859 "java_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Increment", "++");
}
#line 3348 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_29__(ILNode_PostDec *node, ILGenInfo * info, ILNode * * parent)
#line 868 "java_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node, parent,
					   "op_Decrement", "--");
}
#line 3356 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_30__(ILNode_ToBool *node, ILGenInfo * info, ILNode * * parent)
#line 877 "java_oper.tc"
{
	JavaSemValue value;

	/* Perform semantic analysis on the value */
	if(!JavaSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid boolean expression");
		JavaSemSetRValue(value, ILType_Boolean);
		return value;
	}

	/* If the type is boolean, then we are done */
	if(JavaSemGetType(value) == ILType_Boolean)
	{
		return value;
	}

	/* We need a class or a value type if not boolean */
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "no conversion from `%s' to `boolean'",
				  JavaTypeToName(JavaSemGetType(value)));
	JavaSemSetRValue(value, ILType_Boolean);
	return value;
}
#line 3385 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_31__(ILNode_ArrayInit *node, ILGenInfo * info, ILNode * * parent)
#line 221 "java_misc.tc"
{
	if(node->arrayType)
	{
		/* We've already visited this node, so return its type */
		JavaSemValue value;
		JavaSemSetRValue(value, node->arrayType);
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
		return JavaSemValueDefault;
	}
}
#line 3408 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_32__(ILNode_UserCast *node, ILGenInfo * info, ILNode * * parent)
#line 26 "java_cast.tc"
{
	JavaSemValue type;
	JavaSemValue value;
/*	ILEvalValue evalValue;*/

	/* Perform semantic analysis on the type and value expressions */
	type = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));
	value = ILNode_JSemAnalysis(node->expr2, info, &(node->expr2));

	/* Validate the value */
	if(!JavaSemIsValue(value))
	{
		CCErrorOnLine(yygetfilename(node->expr2), yygetlinenum(node->expr2),
					  "invalid value supplied to cast");
		if(JavaSemIsType(type))
		{
			JavaSemSetRValue(value, JavaSemGetType(type));
		}
		else
		{
			JavaSemSetRValue(value, ILType_Int32);
		}
	}

	/* Validate the type */
	if(!JavaSemIsType(type))
	{
		CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
					  "invalid type supplied to cast");
		JavaSemSetType(type, JavaSemGetType(value));
	}

	/* Determine if we can cast between the types */
	if(!ILCast(info, node->expr2, &(node->expr2),
			   JavaSemGetType(value), JavaSemGetType(type),69))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "cannot cast from `%s' to `%s'",
					  JavaTypeToName(JavaSemGetType(value)),
					  JavaTypeToName(JavaSemGetType(type)));
	}
	else
	{
		/* Replace this node with the converted node */
		*parent = node->expr2;
	}

	/* Return an rvalue of the final type to the caller */
/*
	if(ILNode_EvalConst(*parent, info, &evalValue))
	{
		JavaSemSetConstant(value, JavaSemGetType(type), evalValue);
		JavaSemReplaceWithConstant(parent, value);
	}
	else
	{*/
		JavaSemSetRValue(value, JavaSemGetType(type));
//	}
	return value;
}
#line 3472 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_33__(ILNode_InstanceOf *node, ILGenInfo * info, ILNode * * parent)
#line 1234 "java_oper.tc"
{
	JavaSemValue value;
	JavaSemValue result;
	ILType *type;
	ILClass *classInfo;

	/* Perform semantic analysis on the two arguments */
	if(!JavaSemExpectValue(node->expr1, info, &(node->expr1), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid operands to binary `is'");
		JavaSemSetRValue(value, ILFindSystemType(info, "Object"));
	}
	type = JavaSemType(node->expr2, info, &(node->expr2));

	/* Create the result semantic value */
	JavaSemSetRValue(result, ILType_Boolean);

	/* Determine if there is an implicit reference or boxing coercion */
	if(ILCanCoerceKind(info, JavaSemGetType(value), type,
					   IL_CONVERT_REFERENCE,1))					   
	{
		if(ILTypeIsReference(JavaSemGetType(value)))
		{
			/* Reference types: test the expression against null */
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
				    "`is' expression is equivalent to a test against `null'");
			*parent = ILNode_Ne_create(node->expr1, ILNode_Null_create());
		}
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		return result;
	}

	/* Determine if there is an explicit reference or unboxing conversion */
	classInfo = ILGetExplicitConv(info, JavaSemGetType(value), type,
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
#line 3528 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_34__(ILNode_LogicalAnd *node, ILGenInfo * info, ILNode * * parent)
#line 1151 "java_oper.tc"
{
	JavaSemValue value1;
	JavaSemValue value2;

	/* Perform semantic analysis on the arguments */
	if(!JavaSemExpectValue(node->expr1, info, &(node->expr1), &value1) ||
	   !JavaSemExpectValue(node->expr2, info, &(node->expr2), &value2))
	{
		goto error;
	}

	/* We must have boolean arguments at this point */
	if(!ILCanCoerceNode(info, node->expr1, JavaSemGetType(value1),
						ILType_Boolean,1) ||
	   !ILCanCoerceNode(info, node->expr2, JavaSemGetType(value2),
	   					ILType_Boolean,1))
	{
		goto error;
	}

	/* Coerce the two arguments to `bool' */
	ILCoerce(info, node->expr1, &(node->expr1),
			 JavaSemGetType(value1), ILType_Boolean,1);
	ILCoerce(info, node->expr2, &(node->expr2),
			 JavaSemGetType(value2), ILType_Boolean,1);

	/* The result is boolean */
	JavaSemSetRValue(value1, ILType_Boolean);
	EvalOperator(info, *parent, parent, &value1);
	return value1;

	/* Report an argument error */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `&&'");
	JavaSemSetRValue(value1, ILType_Boolean);
	return value1;
}
#line 3570 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_35__(ILNode_LogicalOr *node, ILGenInfo * info, ILNode * * parent)
#line 1194 "java_oper.tc"
{
	JavaSemValue value1;
	JavaSemValue value2;

	/* Perform semantic analysis on the arguments */
	if(!JavaSemExpectValue(node->expr1, info, &(node->expr1), &value1) ||
	   !JavaSemExpectValue(node->expr2, info, &(node->expr2), &value2))
	{
		goto error;
	}

	/* We must have boolean arguments at this point */
	if(!ILCanCoerceNode(info, node->expr1, JavaSemGetType(value1),
						ILType_Boolean,1) ||
	   !ILCanCoerceNode(info, node->expr2, JavaSemGetType(value2),
	   					ILType_Boolean,1))
	{
		goto error;
	}

	/* Coerce the two arguments to `bool' */
	ILCoerce(info, node->expr1, &(node->expr1),
			 JavaSemGetType(value1), ILType_Boolean,1);
	ILCoerce(info, node->expr2, &(node->expr2),
			 JavaSemGetType(value2), ILType_Boolean,1);

	/* The result is boolean */
	JavaSemSetRValue(value1, ILType_Boolean);
	EvalOperator(info, *parent, parent, &value1);
	return value1;

	/* Report an argument error */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `||'");
	JavaSemSetRValue(value1, ILType_Boolean);
	return value1;
}
#line 3612 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_36__(ILNode_Add *node, ILGenInfo * info, ILNode * * parent)
#line 483 "java_oper.tc"
{
	const ILOperator *oper;
	JavaSemValue value1;
	JavaSemValue value2;
	ILType *resultType;

	/* Perform semantic analysis on the arguments */
	value1 = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));
	value2 = ILNode_JSemAnalysis(node->expr2, info, &(node->expr2));

	/* The two arguments must be values */
	if(!JavaSemIsValue(value1) || !JavaSemIsValue(value2))
	{
		goto error;
	}

	/* try constant coercion first */
	if(ILCanCoerceNodeKind(info,node->expr1,JavaSemGetType(value1),
			JavaSemGetType(value2),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr1,&(node->expr1),JavaSemGetType(value1),
			JavaSemGetType(value2),IL_CONVERT_CONSTANT,1);
		JavaSemSetRValue(value1,JavaSemGetType(value2));
	}
	else if(ILCanCoerceNodeKind(info,node->expr2,JavaSemGetType(value2),
			JavaSemGetType(value1),IL_CONVERT_CONSTANT,1))
	{
		ILCoerceKind(info,node->expr2,&(node->expr2),JavaSemGetType(value2),
			JavaSemGetType(value1),IL_CONVERT_CONSTANT,1);
		JavaSemSetRValue(value2,JavaSemGetType(value1));
	}
	
	/* Look for a builtin operator */
	oper = ILFindBinaryOperator
				(ILOp_Add, JavaSemGetType(value1),
				 JavaSemGetType(value2), &resultType,
				 IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			JavaSemSetRValue(value1, resultType);
		}
		else
		{
			JavaSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	} 

	/* If one of the arguments is a string, then perform concatenation */
	if(ILTypeIsStringClass(JavaSemGetType(value1)) ||
	   ILTypeIsStringClass(JavaSemGetType(value2)))
	{
		if(!ILTypeIsStringClass(JavaSemGetType(value1)))
		{
			/* Convert the first argument into "ObjectRef" */
			ILCast(info, node->expr1, &(node->expr1), JavaSemGetType(value1),
				   ILFindSystemType(info, "Object"),1);
		}
		if(!ILTypeIsStringClass(JavaSemGetType(value2)))
		{
			/* Convert the second argument into "ObjectRef" */
			ILCast(info, node->expr2, &(node->expr2), JavaSemGetType(value2),
				   ILFindSystemType(info, "Object"),1);
		}
		*parent = ILNode_Concat_create(node->expr1, node->expr2);
		yysetfilename(*parent, yygetfilename(node));
		yysetlinenum(*parent, yygetlinenum(node));
		JavaSemSetRValue(value1, ILFindSystemType(info, "String"));
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* As a last measure , try coercing the nodes */
	if(ILCanCoerceNode(info, node->expr1, JavaSemGetType(value1),
					   JavaSemGetType(value2),1))
	{
		ILCoerce(info, node->expr1, &(node->expr1), JavaSemGetType(value1),
				 JavaSemGetType(value2),1);
		JavaSemSetRValue(value1, JavaSemGetType(value2));
	}
	else if(ILCanCoerceNode(info, node->expr2, JavaSemGetType(value2),
					   JavaSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), JavaSemGetType(value2),
				 JavaSemGetType(value1),1);
		JavaSemSetRValue(value2, JavaSemGetType(value1));
	}

	/* Look for a builtin operator again */
	oper = ILFindBinaryOperator
				(ILOp_Add, JavaSemGetType(value1),
				 JavaSemGetType(value2), &resultType,
				 IsEnumZero(&value1), IsEnumZero(&value2));
	if(oper)
	{
		ILApplyBinaryOperator(info, (ILNode *)node, parent, oper);
		if(resultType)
		{
			JavaSemSetRValue(value1, resultType);
		}
		else
		{
			JavaSemSetRValue(value1, ILFindSystemType(info, "Decimal"));
		}
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	} 

	/* Could not find a suitable operator */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to binary `+'");
	JavaSemSetRValue(value1, ILType_Int32);
	return value1;
}
#line 3735 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_37__(ILNode_Sub *node, ILGenInfo * info, ILNode * * parent)
#line 607 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Sub, "op_Subtract", "*",1);
}
#line 3743 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_38__(ILNode_Mul *node, ILGenInfo * info, ILNode * * parent)
#line 616 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Mul, "op_Multiply", "*",1);
}
#line 3751 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_39__(ILNode_Div *node, ILGenInfo * info, ILNode * * parent)
#line 625 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Div, "op_Division", "/",1);
}
#line 3759 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_40__(ILNode_Rem *node, ILGenInfo * info, ILNode * * parent)
#line 634 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Rem, "op_Modulus", "%",1);
}
#line 3767 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_41__(ILNode_And *node, ILGenInfo * info, ILNode * * parent)
#line 644 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_And, "op_BitwiseAnd", "&",1);
}
#line 3775 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_42__(ILNode_Or *node, ILGenInfo * info, ILNode * * parent)
#line 662 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Or, "op_BitwiseOr", "|",1);
}
#line 3783 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_43__(ILNode_Xor *node, ILGenInfo * info, ILNode * * parent)
#line 653 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Xor, "op_ExclusiveOr", "^",1);
}
#line 3791 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_44__(ILNode_Shl *node, ILGenInfo * info, ILNode * * parent)
#line 671 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Shl, "op_LeftShift", "<<",0);
}
#line 3799 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_45__(ILNode_Shr *node, ILGenInfo * info, ILNode * * parent)
#line 680 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Shr, "op_RightShift", ">>",0);
}
#line 3807 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_46__(ILNode_UShr *node, ILGenInfo * info, ILNode * * parent)
#line 689 "java_oper.tc"
{
	/* C# doesn't actually have an unsigned right shift, but we
	   still need to include this case for completeness sake */
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_UShr, "op_RightShift", ">>>",0);
}
#line 3817 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_47__(ILNode_Assign *node, ILGenInfo * info, ILNode * * parent)
#line 114 "java_oper.tc"
{
	JavaSemValue value1;
	JavaSemValue value2;

	/* Perform semantic analysis on the lvalue */
	value1 = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));
	if(!JavaSemIsLValue(value1) && !JavaSemIsSValue(value1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid lvalue in assignment");
		if(!JavaSemIsRValue(value1))
		{
			JavaSemSetRValue(value1, ILType_Int32);
		}
		return value1;
	}
	/* Check for array initializers in the assigned expression */
	if(yyisa(node->expr2, ILNode_ArrayInit))
	{
		/* Make sure that the destination type is an array */
		if(!ILType_IsArray(JavaSemGetType(value1)))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "array initializer assigned to non-array destination");
			JavaSemSetRValue(value1, JavaSemGetType(value1));
			return value1;
		}

		/* Check the shape of the array initializer */
		if(!ILArrayInitShapeOK(info, node->expr2, JavaSemGetType(value1)))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "incorrect pattern of elements in array initializer");
			JavaSemSetRValue(value1, JavaSemGetType(value1));
			return value1;
		}

		/* Coerce all initializer members to the element type */
		CoerceArrayInit(info, node->expr2, &(node->expr2),
					    ILTypeGetElemType(JavaSemGetType(value1)));
		JavaSemSetRValue(value1, JavaSemGetType(value1));
		return value1;
	}
	/* Perform semantic analysis and coercion on the rvalue */
	if(!JavaSemExpectValue(node->expr2, info, &(node->expr2), &value2) ||
	   !ILCanCoerceNode(info, node->expr2, JavaSemGetType(value2),
	   					JavaSemGetType(value1),1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  "incompatible types in assignment: no conversion from `%s' to `%s'",
		  JavaTypeToName(JavaSemGetType(value2)),
		  JavaTypeToName(JavaSemGetType(value1)));
		JavaSemSetRValue(value1, JavaSemGetType(value1));
		return value1;
	}
	/* Insert coercion nodes to convert the rvalue appropriately */
	ILCoerce(info, node->expr2, &(node->expr2),
			 JavaSemGetType(value2), JavaSemGetType(value1),1);

	/* Convert value1 into an rvalue and return its type */
	JavaSemSetRValue(value1, JavaSemGetType(value1));
	return value1;
}
#line 3884 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_48__(ILNode_Eq *node, ILGenInfo * info, ILNode * * parent)
#line 1066 "java_oper.tc"
{
	return EqualitySem(info, (ILNode_BinaryExpression *)node, parent,
					   ILOp_Eq, "op_Equality", "==");
}
#line 3892 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_49__(ILNode_Ne *node, ILGenInfo * info, ILNode * * parent)
#line 1075 "java_oper.tc"
{
	return EqualitySem(info, (ILNode_BinaryExpression *)node, parent,
					   ILOp_Ne, "op_Inequality", "!=");
}
#line 3900 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_50__(ILNode_Lt *node, ILGenInfo * info, ILNode * * parent)
#line 1084 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Lt, "op_LessThan", "<",1);
}
#line 3908 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_51__(ILNode_Le *node, ILGenInfo * info, ILNode * * parent)
#line 1093 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Le, "op_LessThanOrEqual", "<=",1);
}
#line 3916 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_52__(ILNode_Gt *node, ILGenInfo * info, ILNode * * parent)
#line 1102 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Gt, "op_GreaterThan", ">",1);
}
#line 3924 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_53__(ILNode_Ge *node, ILGenInfo * info, ILNode * * parent)
#line 1111 "java_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node,
					 parent, ILOp_Ge, "op_GreaterThanOrEqual", ">=",1);
}
#line 3932 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_54__(ILNode_InvocationExpression *node, ILGenInfo * info, ILNode * * parent)
#line 164 "java_invoke.tc"
{
	JavaSemValue value;
	JavaSemValue method;
	ILProgramItem *itemInfo;
	ILMethod *methodInfo;
	ILType *retType;
	JavaEvalArg *args;
	int numArgs;
	unsigned long itemNum;
	char *itemName;
	ILNode_MethodDeclaration *caller;
	int isCtor = 0;

	/* Get the method name for later error reporting */
	if(ILIsQualIdent(node->expr1))
	{
		itemName = ILQualIdentName(node->expr1, 0);
	}
	else if(yyisa(node->expr1, ILNode_MemberAccess))
	{
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
	method = ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));

	if(!JavaSemIsMethodGroup(method))
	{
		CCErrorOnLine(yygetfilename(node->expr1), yygetlinenum(node->expr1),
					  "called object is not a method");
		return JavaSemValueDefault;
	}

	/* Evaluate the arguments */
	numArgs = JavaEvalArguments(info, node->expr2, &(node->expr2), &args);
	if(numArgs < 0)
	{
		return JavaSemValueDefault;
	}

	/* Find the set of candidate methods */
	ReduceMethodGroup(info, args, numArgs, &method);

	/* If there are no candidates left, then bail out */
	itemNum = 0;
	itemInfo = JavaGetGroupMember(JavaSemGetGroup(method), itemNum);
	if(!itemInfo)
	{
		JavaItemCandidateError((ILNode *)node, itemName, isCtor,
						     JavaSemGetGroup(method), args, numArgs);
		JavaEvalFreeArguments(args);
		return JavaSemValueDefault;
	}

	/* There are two or more candidates, then try to find the best one */
	if(JavaGetGroupMember(JavaSemGetGroup(method), 1) != 0)
	{
		itemInfo = JavaBestCandidate(info, JavaSemGetGroup(method),
								   args, numArgs);
		if(!itemInfo)
		{
			JavaItemCandidateError((ILNode *)node, itemName, isCtor,
							     JavaSemGetGroup(method), args, numArgs);
			JavaEvalFreeArguments(args);
			return JavaSemValueDefault;
		}
	}

	/* Import the method into this image, and set it within the node */
	methodInfo = (ILMethod *)itemInfo;
	methodInfo = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)methodInfo);
	node->methodInfo = methodInfo;

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
	retType = JavaItemCoerceArgs(info, ILToProgramItem(methodInfo),
							   args, numArgs, &(node->expr2));
	JavaEvalFreeArguments(args);

	/* The semantic value is the method's return type as an r-value */
	if(retType == ILType_Void)
	{
		JavaSemSetVoid(value);
	}
	else
	{
		JavaSemSetRValue(value, retType);
	}
	return value;
}
#line 4060 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_55__(ILNode_Conditional *node, ILGenInfo * info, ILNode * * parent)
#line 1295 "java_oper.tc"
{
	JavaSemValue value1;
	JavaSemValue value2;

	/* Perform semantic analysis on the boolean condition */
	ILNode_JSemAnalysis(node->expr1, info, &(node->expr1));

	/* Perform semantic analysis on the "then" and "else" clauses */
	if(!JavaSemExpectValue(node->expr2, info, &(node->expr2), &value1) ||
	   !JavaSemExpectValue(node->expr3, info, &(node->expr3), &value2))
	{
		goto error;
	}

	/* If the types are the same, then we are done */
	if(ILTypeIdentical(JavaSemGetType(value1), JavaSemGetType(value2)))
	{
		JavaSemSetRValue(value1, JavaSemGetType(value1));
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Determine which of the types is the result type */
	if(ILCanCoerceNode(info, node->expr2, JavaSemGetType(value1),
					   JavaSemGetType(value2),1) &&
	   !ILCanCoerceNode(info, node->expr3, JavaSemGetType(value2),
	   					JavaSemGetType(value1),1))
	{
		ILCoerce(info, node->expr2, &(node->expr2), JavaSemGetType(value1),
				 JavaSemGetType(value2),1);
		JavaSemSetRValue(value2, JavaSemGetType(value2));
		EvalOperator(info, *parent, parent, &value2);
		return value2;
	}
	else if(ILCanCoerceNode(info, node->expr3, JavaSemGetType(value2),
							JavaSemGetType(value1),1) &&
	        !ILCanCoerceNode(info, node->expr2, JavaSemGetType(value1),
							 JavaSemGetType(value2),1))
	{
		ILCoerce(info, node->expr3, &(node->expr3), JavaSemGetType(value2),
				 JavaSemGetType(value1),1);
		JavaSemSetRValue(value1, JavaSemGetType(value1));
		EvalOperator(info, *parent, parent, &value1);
		return value1;
	}

	/* Report an error with the arguments to "?:" */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "invalid operands to ternary `?:'");
	JavaSemSetRValue(value1, ILType_Int32);
	return value1;
}
#line 4117 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_56__(ILNode_AssignAdd *node, ILGenInfo * info, ILNode * * parent)
#line 277 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Add, "op_Addition", "+");
}
#line 4125 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_57__(ILNode_AssignSub *node, ILGenInfo * info, ILNode * * parent)
#line 286 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Sub, "op_Subtraction", "-");
}
#line 4133 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_58__(ILNode_AssignMul *node, ILGenInfo * info, ILNode * * parent)
#line 295 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Mul, "op_Multiply", "*");
}
#line 4141 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_59__(ILNode_AssignDiv *node, ILGenInfo * info, ILNode * * parent)
#line 304 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Div, "op_Division", "/");
}
#line 4149 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_60__(ILNode_AssignRem *node, ILGenInfo * info, ILNode * * parent)
#line 313 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Rem, "op_Modulus", "%");
}
#line 4157 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_61__(ILNode_AssignAnd *node, ILGenInfo * info, ILNode * * parent)
#line 322 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_And, "op_BitwiseAnd", "&");
}
#line 4165 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_62__(ILNode_AssignOr *node, ILGenInfo * info, ILNode * * parent)
#line 340 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Or, "op_BitwiseOr", "|");
}
#line 4173 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_63__(ILNode_AssignXor *node, ILGenInfo * info, ILNode * * parent)
#line 331 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Xor, "op_ExclusiveOr", "^");
}
#line 4181 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_64__(ILNode_AssignShl *node, ILGenInfo * info, ILNode * * parent)
#line 349 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Shl, "op_LeftShift", "<<");
}
#line 4189 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_65__(ILNode_AssignShr *node, ILGenInfo * info, ILNode * * parent)
#line 358 "java_oper.tc"
{
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_Shr, "op_RightShift", ">>");
}
#line 4197 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_66__(ILNode_AssignUShr *node, ILGenInfo * info, ILNode * * parent)
#line 367 "java_oper.tc"
{
	/* C# does not have an unsigned right shift, so use the signed version */
	return AssignSem(info, (ILNode_AssignExpression *)node,
					 parent, ILOp_UShr, "op_RightShift", ">>>");
}
#line 4206 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_67__(ILNode_NewExpression *node, ILGenInfo * info, ILNode * * parent)
#line 27 "java_misc.tc"
{
	JavaSemValue value;
	ILNode_ListIter iter;
	ILNode *child;
	ILNode *expr;
	ILNode **parentNode;
	ILNode **parentOfExpr;
	ILEvalValue evalValue;
	int numDimensions = 0;
	int dim,dimCount;

	/* Determine if the array creation is normal or initializer-based */
	if(node->indexes)
	{
		/* Build the full type node, by combining the element
		   type, indexed dimensions, and the rank specifiers */
		if(yyisa(node->type, ILNode_JArrayType))
		{
			/* Cannot use array types in this context */
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
						  "invalid array element type");
		}

		dimCount = CountArgList(node->indexes);
		for(dim=0;dim<dimCount;dim++)
		{
			node->type = ILNode_JArrayType_create(node->type, 1);
		}
		
		ILNode_ListIter_Init(&iter, node->rank);
		while((child = ILNode_ListIter_Next(&iter)) != 0)
		{
			node->type = ILNode_JArrayType_create
				(node->type, ((ILNode_JTypeSuffix *)child)->count);
		}

		/* Perform semantic analysis on the array type */
		node->arrayType = JavaSemType(node->type, info, &(node->type));

		/* Perform semantic analysis on the array dimensions */
		child = node->indexes;
		parentOfExpr = &(node->indexes);
		while(yyisa(child, ILNode_ArgList))
		{
			++numDimensions;
			expr = ((ILNode_ArgList *)child)->expr2;
			parentNode = &(((ILNode_ArgList *)child)->expr2);
			if(JavaSemExpectValue(expr, info, parentNode, &value))
			{
				if(!ILCoerce(info, *parentNode, parentNode,
							 JavaSemGetType(value), ILType_Int32,1) &&
				   !ILCoerce(info, *parentNode, parentNode,
							 JavaSemGetType(value), ILType_UInt32,1) &&
				   !ILCoerce(info, *parentNode, parentNode,
							 JavaSemGetType(value), ILType_Int64,1) &&
				   !ILCoerce(info, *parentNode, parentNode,
							 JavaSemGetType(value), ILType_UInt64,1))
				{
					CCErrorOnLine
						(yygetfilename(expr), yygetlinenum(expr),
			  			 "incompatible types in dimension specifier: "
						 	"no conversion from `%s' to `int', `uint', "
							"`long', or `ulong'",
					     JavaTypeToName(JavaSemGetType(value)));
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
		if(JavaSemExpectValue(expr, info, parentNode, &value))
		{
			if(!ILCoerce(info, *parentNode, parentNode,
						 JavaSemGetType(value), ILType_Int32,1) &&
			   !ILCoerce(info, *parentNode, parentNode,
						 JavaSemGetType(value), ILType_UInt32,1) &&
			   !ILCoerce(info, *parentNode, parentNode,
						 JavaSemGetType(value), ILType_Int64,1) &&
			   !ILCoerce(info, *parentNode, parentNode,
						 JavaSemGetType(value), ILType_UInt64,1))
			{
				CCErrorOnLine
					(yygetfilename(expr), yygetlinenum(expr),
		  			 "incompatible types in dimension specifier: "
					 	"no conversion from `%s' to `int', `uint', "
						"`long', or `ulong'",
				     JavaTypeToName(JavaSemGetType(value)));
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
		node->arrayType = JavaSemType(node->type, info, &(node->type));

		/* Check that the supplied type is actually an array */
		if(!ILType_IsArray(node->arrayType))
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
						  "array initializer used with non-array type");
			JavaSemSetRValue(value, node->arrayType);
			return value;
		}
	}

	/* Handle array initializers */
	if(node->arrayInitializer)
	{
		/*
		 * Since java supports untyped array initializers like
		 * int a[]={1,2}; The grammar with wrap the arrays in 
		 * in an ILNode_ArrayInit by default.
		 */
		if(!yyisa(node->arrayInitializer,ILNode_ArrayInit))
		{
			/* Wrap the initializer in an "ILNode_ArrayInit" node */
			node->arrayInitializer =
				ILNode_ArrayInit_create(node->arrayInitializer);
		}

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
	JavaSemSetRValue(value, node->arrayType);
	return value;
}
#line 4402 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_68__(ILNode_ObjectCreationExpression *node, ILGenInfo * info, ILNode * * parent)
#line 896 "java_invoke.tc"
{
	JavaSemValue value;
	JavaSemValue method;
	ILProgramItem *itemInfo;
	ILMethod *methodInfo;
	ILType *objectType;
	ILClass *objectClass;
	JavaEvalArg *args;
	int numArgs;
	unsigned long itemNum;
	int candidateForm;

	/* Perform semantic analysis on the type */
	objectType = JavaSemTypeLiteral(node->type, info, &(node->type));

	/* Set up the default return value */
	JavaSemSetRValue(value, objectType);

	if(ILType_IsClass(objectType))
	{
		objectClass = ILClassResolve(ILType_ToClass(objectType));
		if(ILClass_IsInterface(objectClass))
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  "cannot instantiate interface `%s' with the `new' operator",
			  JavaTypeToName(objectType));
			return value;
		}
		else if(ILClass_IsAbstract(objectClass))
		{
			CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  "cannot instantiate abstract class `%s' with the `new' operator",
			  JavaTypeToName(objectType));
			return value;
		}
	}
	else
	{
		CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
			  		  "`%s' is not a class",
					  JavaTypeToName(objectType));
		return value;
	}

	/* Get the list of accessible constructors for the type */
	method = JavaResolveConstructor(info, node->type, objectType);
	if(!JavaSemIsMethodGroup(method))
	{
		CCErrorOnLine(yygetfilename(node->type), yygetlinenum(node->type),
					  "`%s' does not have an accessible constructor",
					  JavaTypeToName(objectType));
		return value;
	}

	/* Evaluate the arguments */
	numArgs = JavaEvalArguments(info, node->argList, &(node->argList), &args);
	if(numArgs < 0)
	{
		return value;
	}

	/* Find the set of candidate methods */
	itemNum = 0;
	while((itemInfo = JavaGetGroupMember(JavaSemGetGroup(method), itemNum)) != 0)
	{
		candidateForm = JavaItemIsCandidate(info, itemInfo, args, numArgs);
		if(candidateForm)
		{
			JavaSetGroupMemberForm(JavaSemGetGroup(method), itemNum,
								 candidateForm);
			++itemNum;
		}
		else
		{
			JavaSemModifyGroup(method, JavaRemoveGroupMember
								(JavaSemGetGroup(method), itemNum));
		}
	}

	/* If there are no candidates left, then bail out */
	itemNum = 0;
	itemInfo = JavaGetGroupMember(JavaSemGetGroup(method), itemNum);
	if(!itemInfo)
	{
		JavaItemCandidateError((ILNode *)node, 0, 1,
						     JavaSemGetGroup(method), args, numArgs);
		JavaEvalFreeArguments(args);
		return value;
	}

	/* There are two or more candidates, then try to find the best one */
	if(JavaGetGroupMember(JavaSemGetGroup(method), 1) != 0)
	{
		itemInfo = JavaBestCandidate(info, JavaSemGetGroup(method),
								   args, numArgs);
		if(!itemInfo)
		{
			JavaItemCandidateError((ILNode *)node, 0, 1,
							     JavaSemGetGroup(method), args, numArgs);
			JavaEvalFreeArguments(args);
			return value;
		}
	}

	/* Import the method into this image, and set it within the node */
	methodInfo = (ILMethod *)itemInfo;
	methodInfo = (ILMethod *)ILMemberImport
						(info->image, (ILMember *)methodInfo);
	node->methodInfo = methodInfo;

	/* Coerce the arguments and build the final argument list */
	JavaItemCoerceArgs(info, ILToProgramItem(methodInfo),
					 args, numArgs, &(node->argList));
	JavaEvalFreeArguments(args);

	/* Return the final semantic value */
	return value;
}
#line 4524 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_69__(ILNode_BaseInit *node, ILGenInfo * info, ILNode * * parent)
#line 850 "java_invoke.tc"
{
	JavaSemValue value;
	ILClass *classInfo;
	ILClass *parentInfo;

	/* If we are compiling "System.Object", then we need to
	   bail out with an empty method group.  This tells
	   "InvocationExpression" to ignore the call */
	classInfo = ((ILNode_ClassDefn *)(info->currentClass))->classInfo;
	parentInfo = (classInfo ? ILClass_Parent(classInfo) : 0);
	if(!parentInfo)
	{
		JavaSemSetMethodGroup(value, 0);
		return value;
	}

	/* Resolve the constructor within the base class */
	JavaSemSetRValue(value, ILType_FromClass(parentInfo));
	value = JavaResolveConstructor(info, (ILNode *)node, JavaSemGetType(value));

	/* Report an error if we could not find any accessible constructors */
	if(!JavaSemIsMethodGroup(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "no accessible base class constructors");
	}

	/* Replace the current expression with "this" */
	*parent = ILNode_This_create();
	JavaSemSetSuper(value);
	return value;
}
#line 4560 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_70__(ILNode_NonStaticInit *node, ILGenInfo * info, ILNode * * parent)
#line 887 "java_invoke.tc"
{
	/* Non-static initializer calls are always "void" statements */
	return JavaSemValueDefault;
}
#line 4568 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_71__(ILNode_Compound *node, ILGenInfo * info, ILNode * * parent)
#line 172 "java_stmt.tc"
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
	return JavaSemValueDefault;
}
#line 4588 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_72__(ILNode_SwitchSectList *node, ILGenInfo * info, ILNode * * parent)
#line 1087 "java_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return JavaSemValueDefault;
}
#line 4596 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_73__(ILNode_CaseList *node, ILGenInfo * info, ILNode * * parent)
#line 1087 "java_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return JavaSemValueDefault;
}
#line 4604 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_74__(ILNode_List *node, ILGenInfo * info, ILNode * * parent)
#line 172 "java_stmt.tc"
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
	return JavaSemValueDefault;
}
#line 4624 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_75__(ILNode_Empty *node, ILGenInfo * info, ILNode * * parent)
#line 163 "java_stmt.tc"
{
	return JavaSemValueDefault;
}
#line 4631 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_76__(ILNode_If *node, ILGenInfo * info, ILNode * * parent)
#line 331 "java_stmt.tc"
{
	ILNode_JSemAnalysis(node->expr, info, &(node->expr));
	StmtSem(node->thenClause, info, &(node->thenClause));
	StmtSem(node->elseClause, info, &(node->elseClause));
	return JavaSemValueDefault;
}
#line 4641 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_77__(ILNode_While *node, ILGenInfo * info, ILNode * * parent)
#line 346 "java_stmt.tc"
{
	ILNode_JSemAnalysis(node->cond, info, &(node->cond));
	PushStmtContext(info, JAVA_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt));
	PopStmtContext(info);
	return JavaSemValueDefault;
}
#line 4652 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_78__(ILNode_Do *node, ILGenInfo * info, ILNode * * parent)
#line 362 "java_stmt.tc"
{
	PushStmtContext(info, JAVA_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt));
	PopStmtContext(info);
	ILNode_JSemAnalysis(node->cond, info, &(node->cond));
	return JavaSemValueDefault;
}
#line 4663 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_79__(ILNode_For *node, ILGenInfo * info, ILNode * * parent)
#line 378 "java_stmt.tc"
{
	StmtSem(node->init, info, &(node->init));
	ILNode_JSemAnalysis(node->cond, info, &(node->cond));
	StmtSem(node->incr, info, &(node->incr));
	PushStmtContext(info, JAVA_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt));
	PopStmtContext(info);
	return JavaSemValueDefault;
}
#line 4676 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_80__(ILNode_Switch *node, ILGenInfo * info, ILNode * * parent)
#line 981 "java_stmt.tc"
{
	static ILType * const governingTypes[] = {
		ILType_Int8, ILType_UInt8, ILType_Int16, ILType_UInt16,
		ILType_Int32, ILType_UInt32, ILType_Int64, ILType_UInt64, ILType_Char
	};
	#define numGoverningTypes	(sizeof(governingTypes) / sizeof(ILType *))
	JavaSemValue value;
	ILType *actualType;
	ILType *switchType;
	int posn;
	unsigned long size;
	ILNode *savedSwitch;

	/* Perform semantic analysis on the expression */
	if(!JavaSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node->expr), yygetlinenum(node->expr),
					  "invalid expression for `switch' statement");
		actualType = ILType_Int32;
	}
	else
	{
		actualType = JavaSemGetType(value);
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
			CCErrorOnLine(yygetfilename(node->expr),
				  yygetlinenum(node->expr),
				  "`%s' is invalid as the governing type for a `switch'",
				  JavaTypeToName(actualType));
		}
	}

	/* Cast the switch expression to the governing type */
	ILCast(info, node->expr, &(node->expr), actualType, switchType,1);

	node->switchType=switchType;

	/* Enter the switch context */
	PushStmtContext(info, JAVA_STMT_SWITCH);
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
	return JavaSemValueDefault;
}
#line 4777 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_81__(ILNode_Break *node, ILGenInfo * info, ILNode * * parent)
#line 536 "java_stmt.tc"
{
	if(!StmtContextOK(info, JAVA_STMT_LOOP | JAVA_STMT_SWITCH, JAVA_STMT_FINALLY))
	{
		if(StmtContextOK(info, JAVA_STMT_FINALLY, 0))
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
	return JavaSemValueDefault;
}
#line 4797 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_82__(ILNode_Return *node, ILGenInfo * info, ILNode * * parent)
#line 193 "java_stmt.tc"
{
	/* Emit an error if the return type is not "void" */
	ILType *returnType = ILTypeGetReturn(ILMethod_Signature
		(((ILNode_MethodDeclaration *)(info->currentMethod))->methodInfo));
	if(returnType != ILType_Void)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "`return' with no value, in method returning non-void");
	}
	if(!StmtContextOK(info, 0, JAVA_STMT_FINALLY))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  		  "`return' used inside `finally' clause");
	}
	return JavaSemValueDefault;
}
#line 4817 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_83__(ILNode_ReturnExpr *node, ILGenInfo * info, ILNode * * parent)
#line 214 "java_stmt.tc"
{
	JavaSemValue value;
	ILType *returnType;

	/* Perform semantic analysis on the expression */
	if(!JavaSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid return value");
		return JavaSemValueDefault;
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
					 JavaSemGetType(value), returnType,1))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  		  "incompatible types in return: "
						  		"no conversion from `%s' to `%s'",
						  JavaTypeToName(JavaSemGetType(value)),
						  			   JavaTypeToName(returnType));
		}
	}

	/* Check that the return was not used inside a "finally" clause */
	if(!StmtContextOK(info, 0, JAVA_STMT_FINALLY))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  		  "`return' used inside `finally' clause");
	}

	/* Done */
	return JavaSemValueDefault;
}
#line 4865 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_84__(ILNode_GotoCase *node, ILGenInfo * info, ILNode * * parent)
#line 1096 "java_stmt.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	ILNode_Switch *switchExpr;
	ILMachineType switchMachineType;
	ILSwitchValue switchValue;
	unsigned long posn;

	if(!StmtContextOK(info, JAVA_STMT_SWITCH, JAVA_STMT_FINALLY))
	{
		if(StmtContextOK(info, JAVA_STMT_FINALLY, 0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`goto' used inside `finally' clause");
			return JavaSemValueDefault;
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`goto' used outside switch");
			return JavaSemValueDefault;
		}
	}

	/* if node->currentSwitch is NULL, then somebody messed up the 
	   PushStmtContext . It is a "bug detection" bug */
	/* Initialize */

	switchExpr=(ILNode_Switch*)(info->currentSwitch);
	switchMachineType = ILTypeToMachineType(switchExpr->switchType);


	if(!JavaSemExpectValue(node->expr, info,
							 &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node->expr),
					  yygetlinenum(node->expr),
					  "invalid case label expression");
		return JavaSemValueDefault;
	}
	/* Coerce the case expression to the governing type */
	if(!ILCoerce(info, node->expr, &(node->expr),
					 JavaSemGetType(value), switchExpr->switchType,1))
	{
		CCErrorOnLine(yygetfilename(node->expr),
						  yygetlinenum(node->expr),
						  "no conversion from `%s' to `%s'",
						  JavaTypeToName(JavaSemGetType(value)),
						  JavaTypeToName(switchExpr->switchType));
		return JavaSemValueDefault;
	}
	
	/* Evaluate the constant value for the case expression */
	if(!ILNode_EvalConst(node->expr, info, &evalValue) ||
		   !ILGenCastConst(info, &evalValue, evalValue.valueType,
				   				   switchMachineType))
	{
		CCErrorOnLine(yygetfilename(node->expr),
						  yygetlinenum(node->expr),
						  "case expression is not constant");
		return JavaSemValueDefault;
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
			return JavaSemValueDefault;
		}
	}
	/* if we get here , the case entry was not locatable */
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  "could not find a matching case for 'goto'");
	
	return JavaSemValueDefault;
}
#line 4954 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_85__(ILNode_NewScope *node, ILGenInfo * info, ILNode * * parent)
#line 759 "java_lvalue.tc"
{
	ILScope *savedScope = info->currentScope;
	if(!(node->scope))
	{
		node->scope = ILScopeCreate(info, savedScope);
	}
	info->currentScope = node->scope;
	StmtSem(node->stmt, info, &(node->stmt));
	info->currentScope = savedScope;
	return JavaSemValueDefault;
}
#line 4969 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_86__(ILNode_SwitchSection *node, ILGenInfo * info, ILNode * * parent)
#line 1087 "java_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return JavaSemValueDefault;
}
#line 4977 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_87__(ILNode_CaseLabel *node, ILGenInfo * info, ILNode * * parent)
#line 1087 "java_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return JavaSemValueDefault;
}
#line 4985 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_88__(ILNode_DefaultLabel *node, ILGenInfo * info, ILNode * * parent)
#line 1087 "java_stmt.tc"
{
	/* Nothing to do here: the real work is done in "ILNode_Switch" */
	return JavaSemValueDefault;
}
#line 4993 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_89__(ILNode_ThrowExpr *node, ILGenInfo * info, ILNode * * parent)
#line 508 "java_stmt.tc"
{
	JavaSemValue value;
	ILType *exceptionClass;

	/* Perform semantic analysis on the value */
	if(!JavaSemExpectValue(node->expr, info, &(node->expr), &value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  		  "invalid throw expression");
		JavaSemSetRValue(value, ILType_Null);
	}

	/* Attempt to coerce the value to "System.Exception" */
	exceptionClass = ILFindSystemType(info, "Exception");
	if(!ILCoerce(info, node->expr, &(node->expr),
				 JavaSemGetType(value), exceptionClass,1))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  		  "no conversion from `%s' to `%s'",
					  JavaTypeToName(JavaSemGetType(value)),
					  JavaTypeToName(exceptionClass));
	}

	/* Done */
	return JavaSemValueDefault;
}
#line 5023 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_90__(ILNode_Try *node, ILGenInfo * info, ILNode * * parent)
#line 392 "java_stmt.tc"
{
	/* Enter a "try" context */
	PushStmtContext(info, JAVA_STMT_TRY);

	/* Perform semantic analysis on the "try" body */
	StmtSem(node->stmt, info, &(node->stmt));

	/* Perform semantic analysis on the "catch" clauses */
	StmtSem(node->catchClauses, info, &(node->catchClauses));

	/* Perform semantic analysis on the "finally" clause */
	StmtSem(node->finallyClause, info, &(node->finallyClause));

	/* Exit from the "try" context */
	PopStmtContext(info);

	/* Done */
	return JavaSemValueDefault;
}
#line 5046 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_91__(ILNode_CatchClause *node, ILGenInfo * info, ILNode * * parent)
#line 416 "java_stmt.tc"
{
	ILType *exceptionType = ILFindSystemType(info, "Exception");
	ILType *thrownType;
	ILScope *newScope;
	ILNode_MethodDeclaration *method =
		(ILNode_MethodDeclaration *)(info->currentMethod);

	/* Enter a "catch" context */
	PushStmtContext(info, JAVA_STMT_CATCH);

	/* Wrap the catch body in a new scope */
	newScope = ILScopeCreate(info, info->currentScope);
	node->stmt = ILNode_NewScope_create(node->stmt);
	((ILNode_NewScope *)(node->stmt))->scope = newScope;

	/* Validate the thrown value type */
	if(node->type)
	{
		thrownType = JavaSemType(node->type, info, &(node->type));
		if(!ILCanCoerce(info, thrownType, exceptionType,0))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  		  		  "`%s' does not inherit from `%s'",
						  JavaTypeToName(thrownType),
						  JavaTypeToName(exceptionType));
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
	return JavaSemValueDefault;
}
#line 5119 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_92__(ILNode_FinallyClause *node, ILGenInfo * info, ILNode * * parent)
#line 490 "java_stmt.tc"
{
	/* Enter a "finally" context */
	PushStmtContext(info, JAVA_STMT_FINALLY);

	/* Perform semantic analysis on the finally body */
	StmtSem(node->stmt, info, &(node->stmt));

	/* Exit from the "finally" context */
	PopStmtContext(info);

	/* Done */
	return JavaSemValueDefault;
}
#line 5136 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_93__(ILNode_LocalVarDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 263 "java_stmt.tc"
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
	type = JavaSemType(node->type, info, &(node->type));

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
	return JavaSemValueDefault;
}
#line 5199 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_94__(ILNode_ClassDefn *node, ILGenInfo * info, ILNode * * parent)
#line 98 "java_decls.tc"
{
	JavaSemValue value;
	ILNode *savedClass;
	ILNode *savedNamespace;
	ILNode *savedMethod;
	ILNode *staticCtorList=NULL;
	int hadStaticCtorsBefore;

	/* Determine if we have already visited this node */
	if(node->visited == ILVisitMode_Processing)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "circularity detected in class definition");
		return JavaSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return JavaSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Perform semantic analysis on the node */
	hadStaticCtorsBefore = (node->staticCtors != 0);
	if(node->body)
	{
		savedClass = info->currentClass;
		savedNamespace = info->currentNamespace;
		savedMethod = info->currentMethod;
		info->currentClass = (ILNode *)node;
		info->currentNamespace = node->namespaceNode;
		info->currentMethod = NULL;
		value = ILNode_JSemAnalysis(node->body, info, &(node->body));
		if(node->initCtorsMethod)
		{
			/* Perform semantic analysis on the non-static initializers */
			ILNode_JSemAnalysis(node->initCtorsMethod, info,
							   &(node->initCtorsMethod));
		}
		/*  save the explicit static constructors before gathering  */
		if (node->staticCtors)
		{
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
			ILNode_JSemAnalysis(node->staticCtorsMethod, info,
							   &(node->staticCtorsMethod));
		}
		info->currentClass = savedClass;
		info->currentNamespace = savedNamespace;
		info->currentMethod = savedMethod;
	}
	else
	{
		JavaSemSetRValue(value, ILType_Int32);
	}
	if(node->classInfo && !ILClass_IsInterface(node->classInfo))
	{
		/* Check that the class implements all of its interfaces */
		ILGenImplementsAllInterfaces(info, (ILNode *)node, node->classInfo,
									 InterfaceErrorFunc,InterfaceProxyFunc);
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
	return JavaSemValueDefault;
	
}
#line 5335 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_95__(ILNode_ScopeChange *node, ILGenInfo * info, ILNode * * parent)
#line 367 "java_decls.tc"
{
	JavaSemValue value;
	if (node->body)
	{
		ILScope *oldscope = info->currentScope;
		info->currentScope = node->scope;
		value = ILNode_JSemAnalysis(node->body, info, &(node->body));
		info->currentScope = oldscope;
	}
	else
	{
		JavaSemSetRValue(value, ILType_Int32);
	}
	return value;
}
#line 5354 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_96__(ILNode_FieldDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 661 "java_decls.tc"
{
	ILNode_ListIter iterator;
	ILNode *decl;

	/* Verify the initializers */
	ILNode_ListIter_Init(&iterator, node->fieldDeclarators);
	while((decl = ILNode_ListIter_Next(&iterator)) != 0)
	{
		ILNode_JSemAnalysis(decl, info, &decl);
	}

	/* Fields don't really have a semantic value, so return the default */
	return JavaSemValueDefault;
}
#line 5372 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_97__(ILNode_FieldDeclarator *node, ILGenInfo * info, ILNode * * parent)
#line 686 "java_decls.tc"
{
	JavaSemValue value;
	ILEvalValue evalValue;
	ILNode *savedMethod;
	ILNode *initializer;

	savedMethod=info->currentMethod;

	/* Determine if we have already visited this node */
	if(node->visited == ILVisitMode_Processing)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "circularity detected in field definition");
		return JavaSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return JavaSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Skip the field if no initializer or ILField block */
	if(!(node->initializer) || !(node->fieldInfo))
	{
		goto done;
	}
	
	info->currentMethod=NULL;

	/* Non-static fields are initialized differently */
	if(node->owner && (node->owner->modifiers & IL_META_FIELDDEF_STATIC) == 0)
	{
		initializer = ILNode_Assign_create(node->name, node->initializer);
		yysetfilename(initializer,yygetfilename(node));
		yysetlinenum(initializer,yygetlinenum(node));
		
		JavaAddInitCtor(info, initializer);
		goto done;
	}

	/* If this is a constant, then evaluate the value */
	if(node->owner && (node->owner->modifiers & IL_META_FIELDDEF_LITERAL) != 0)
	{
		/* Perform semantic analysis on the initializer value */
		value = ILNode_JSemAnalysis(node->initializer, info,
								   &(node->initializer));
		if(!JavaSemIsValue(value))
		{
			CCErrorOnLine(yygetfilename(node->initializer),
						  yygetlinenum(node->initializer),
						  "initializer is not a value");
			goto done;
		}

		/* Make sure that the value is compatible with the field's type */
		if(!ILCoerce(info, node->initializer, &(node->initializer),
					 JavaSemGetType(value), ILField_Type(node->fieldInfo),1))
		{
			CCErrorOnLine(yygetfilename(node->initializer),
						  yygetlinenum(node->initializer),
			  			  "incompatible types in initialization: "
			  					"no conversion from `%s' to `%s'",
			  			  JavaTypeToName(JavaSemGetType(value)),
						  JavaTypeToName(ILField_Type(node->fieldInfo)));
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

		/* Record the constant value so the compiler can pick
		  it up when the binary form of the code is reloaded */
		AddConstantValue(info, node->fieldInfo, &evalValue);
		goto done;
	}

	/* Add a statement to the static constructor to initialize the field */
	/*	JavaAddStaticCtor(info,  
	                 ILNode_Assign_create(node->name, node->initializer)); */

	initializer=ILNode_Assign_create(node->name, node->initializer);
	yysetfilename(initializer,yygetfilename(node));
	yysetlinenum(initializer,yygetlinenum(node));

	node->staticCtor = ILNode_NewScope_create(initializer);

done:
	/* Mark the node as done and return */
	info->currentMethod=savedMethod;
	node->visited = ILVisitMode_Done;
	return JavaSemValueDefault;
}
#line 5476 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_98__(ILNode_MethodDeclaration *node, ILGenInfo * info, ILNode * * parent)
#line 232 "java_decls.tc"
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
		return JavaSemValueDefault;
	}
	else if(node->visited == ILVisitMode_Done)
	{
		return JavaSemValueDefault;
	}
	node->visited = ILVisitMode_Processing;

	/* Record the current method that we are in */
	savedMethod = info->currentMethod;
	info->currentMethod = (ILNode *)node;

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
			ILScopeDeclareLocal(scope, name, argNum | JAVA_LOCAL_IS_ARG,
								param->name);
		}
		++argNum;
		++argIndex;
	}

	/* Perform semantic analysis on the method body */
	if(node->body)
	{
		if((node->modifiers & IL_META_METHODDEF_ABSTRACT) != 0)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "`abstract' cannot be used with a method body");
		}
		savedScope = info->currentScope;
		info->currentScope = scope;
		ILNode_JSemAnalysis(node->body, info, &(node->body));
		info->currentScope = savedScope;
	}
	else if((node->modifiers & IL_META_METHODDEF_ABSTRACT) == 0)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  "method with no body requires `abstract'");
	}

	/* If the return type is not void, then make sure that the
	   method ends in some kind of return statement */
	returnType = ILTypeGetReturn(ILMethod_Signature(node->methodInfo));
	if(returnType != ILType_Void && node->body)
	{
		if(!ILMethod_IsAbstract(node->methodInfo) &&
		   ILMethod_IsIL(node->methodInfo))
		{
			if(!ILNodeEndsInFlowChange(node->body,info))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  "control reaches end of non-void method");
			}
		}
	}

	/* Return to the previous method level */
	info->currentMethod = savedMethod;

	/* Finished visiting this node */
	node->visited = ILVisitMode_Done;

	/* Methods don't really have a semantic value, so return the default */
	return JavaSemValueDefault;
}
#line 5609 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_99__(ILNode_JMain *node, ILGenInfo * info, ILNode * * parent)
#line 246 "java_misc.tc"
{
	/* Nothing to do here */
	return JavaSemValueDefault;
}
#line 5617 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_100__(ILNode_Identifier *node, ILGenInfo * info, ILNode * * parent)
#line 607 "java_lvalue.tc"
{
	JavaSemValue value;
	ILScopeData *data;
	unsigned long index;
	ILNode_MethodDeclaration *method;
	ILType *type;

	/* Look for local variables in the current scope */
	data = ILScopeLookup(info->currentScope, node->name, 1);
	if(data && ILScopeDataGetKind(data) == IL_SCOPE_LOCAL)
	{
		index = ILScopeDataGetIndex(data);
		method = (ILNode_MethodDeclaration *)(info->currentMethod);
		if((index & JAVA_LOCAL_IS_ARG) == 0)
		{
			/* Local variable reference */
			type = ILTypeGetLocal(method->localVarSig, index);
			JavaSemSetLValue(value, type);
			*parent = ILNode_LocalVar_create(index, ILTypeToMachineType(type));
			yysetfilename(*parent, yygetfilename(node));
			yysetlinenum(*parent, yygetlinenum(node));
		}
		else
		{
			/* Argument reference */
			index &= ~JAVA_LOCAL_IS_ARG;
			if((method->modifiers & IL_META_METHODDEF_STATIC) == 0)
			{
				ILGenGetParamInfo(method->methodInfo, 0,
											 index, &type);
			}
			else
			{
				ILGenGetParamInfo(method->methodInfo, 0,
											 index + 1, &type);
			}
			*parent = ILNode_ArgumentVar_create
							(index, ILTypeToMachineType(type));
			JavaSemSetLValue(value, type);
		}
		return value;
	}
#if TODO
	else if(data && ILScopeDataGetKind(data) == IL_SCOPE_LOCAL_CONST)
	{
		method = (ILNode_MethodDeclaration *)(info->currentMethod);
		constVar = (ILNode_JSemGuard *)(ILScopeDataGetData1(data));
		*parent = constVar->expr;
		JavaSemSetRValue(value, JavaSemGetType(constVar->value));
		return value;
	}
#endif

	value = JavaResolveSimpleName(info, (ILNode *)node, node->name, 0);
	
	/* Convert the result into an l-value or r-value and return it */
	return SemToLRValue((ILNode *)node, info, parent, 
							value, node->name, 0, 0);
}
#line 5680 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_101__(ILNode_QualIdent *node, ILGenInfo * info, ILNode * * parent)
#line 671 "java_lvalue.tc"
{
	JavaSemValue value;
	JavaSemValue value2;
	char *name;

	/* Get the semantic value for the left part of the identifier */
	value = ILNode_JSemAnalysis(node->left, info, &(node->left));

	/* Resolve the member */
	name = ILQualIdentName(node->right, 0);
	value2 = JavaResolveMemberName(info, (ILNode *)node, value, name, 0);

	/* Convert the result into an l-value or r-value and return it */
	return SemToLRValue((ILNode *)node, info, parent, value2,
						name, node->left, &value);
}
#line 5700 "java_semantics.c"

static JavaSemValue ILNode_JSemAnalysis_102__(ILNode *node, ILGenInfo * info, ILNode * * parent)
#line 36 "java_semantics.tc"
{
	fprintf(stderr,"%s:%d <%s>\n",__FILE__,__LINE__,yykindname(node));
	return JavaSemValueDefault;
}
#line 5708 "java_semantics.c"

JavaSemValue ILNode_JSemAnalysis(ILNode * node__, ILGenInfo * info, ILNode * * parent)
{
	switch(node__->kind__)
	{
		case ILNode_JPrimitiveType_kind:
		{
			return ILNode_JSemAnalysis_1__((ILNode_JPrimitiveType *)node__, info, parent);
		}
		break;

		case ILNode_JArrayType_kind:
		{
			return ILNode_JSemAnalysis_2__((ILNode_JArrayType *)node__, info, parent);
		}
		break;

		case ILNode_JSystemType_kind:
		{
			return ILNode_JSemAnalysis_3__((ILNode_JSystemType *)node__, info, parent);
		}
		break;

		case ILNode_ILSystemType_kind:
		{
			return ILNode_JSemAnalysis_4__((ILNode_ILSystemType *)node__, info, parent);
		}
		break;

		case ILNode_Null_kind:
		{
			return ILNode_JSemAnalysis_5__((ILNode_Null *)node__, info, parent);
		}
		break;

		case ILNode_True_kind:
		{
			return ILNode_JSemAnalysis_6__((ILNode_True *)node__, info, parent);
		}
		break;

		case ILNode_False_kind:
		{
			return ILNode_JSemAnalysis_7__((ILNode_False *)node__, info, parent);
		}
		break;

		case ILNode_UInt8_kind:
		{
			return ILNode_JSemAnalysis_8__((ILNode_UInt8 *)node__, info, parent);
		}
		break;

		case ILNode_Int16_kind:
		{
			return ILNode_JSemAnalysis_9__((ILNode_Int16 *)node__, info, parent);
		}
		break;

		case ILNode_Char_kind:
		{
			return ILNode_JSemAnalysis_10__((ILNode_Char *)node__, info, parent);
		}
		break;

		case ILNode_Int32_kind:
		{
			return ILNode_JSemAnalysis_11__((ILNode_Int32 *)node__, info, parent);
		}
		break;

		case ILNode_Int64_kind:
		{
			return ILNode_JSemAnalysis_12__((ILNode_Int64 *)node__, info, parent);
		}
		break;

		case ILNode_Int_kind:
		{
			return ILNode_JSemAnalysis_13__((ILNode_Int *)node__, info, parent);
		}
		break;

		case ILNode_Float32_kind:
		{
			return ILNode_JSemAnalysis_14__((ILNode_Float32 *)node__, info, parent);
		}
		break;

		case ILNode_Float64_kind:
		{
			return ILNode_JSemAnalysis_15__((ILNode_Float64 *)node__, info, parent);
		}
		break;

		case ILNode_Float_kind:
		{
			return ILNode_JSemAnalysis_16__((ILNode_Float *)node__, info, parent);
		}
		break;

		case ILNode_String_kind:
		{
			return ILNode_JSemAnalysis_17__((ILNode_String *)node__, info, parent);
		}
		break;

		case ILNode_BaseAccess_kind:
		{
			return ILNode_JSemAnalysis_18__((ILNode_BaseAccess *)node__, info, parent);
		}
		break;

		case ILNode_MemberAccess_kind:
		{
			return ILNode_JSemAnalysis_19__((ILNode_MemberAccess *)node__, info, parent);
		}
		break;

		case ILNode_This_kind:
		{
			return ILNode_JSemAnalysis_20__((ILNode_This *)node__, info, parent);
		}
		break;

		case ILNode_ArrayAccess_kind:
		{
			return ILNode_JSemAnalysis_21__((ILNode_ArrayAccess *)node__, info, parent);
		}
		break;

		case ILNode_LogicalNot_kind:
		{
			return ILNode_JSemAnalysis_22__((ILNode_LogicalNot *)node__, info, parent);
		}
		break;

		case ILNode_Neg_kind:
		{
			return ILNode_JSemAnalysis_23__((ILNode_Neg *)node__, info, parent);
		}
		break;

		case ILNode_UnaryPlus_kind:
		{
			return ILNode_JSemAnalysis_24__((ILNode_UnaryPlus *)node__, info, parent);
		}
		break;

		case ILNode_Not_kind:
		{
			return ILNode_JSemAnalysis_25__((ILNode_Not *)node__, info, parent);
		}
		break;

		case ILNode_PreInc_kind:
		{
			return ILNode_JSemAnalysis_26__((ILNode_PreInc *)node__, info, parent);
		}
		break;

		case ILNode_PreDec_kind:
		{
			return ILNode_JSemAnalysis_27__((ILNode_PreDec *)node__, info, parent);
		}
		break;

		case ILNode_PostInc_kind:
		{
			return ILNode_JSemAnalysis_28__((ILNode_PostInc *)node__, info, parent);
		}
		break;

		case ILNode_PostDec_kind:
		{
			return ILNode_JSemAnalysis_29__((ILNode_PostDec *)node__, info, parent);
		}
		break;

		case ILNode_ToBool_kind:
		{
			return ILNode_JSemAnalysis_30__((ILNode_ToBool *)node__, info, parent);
		}
		break;

		case ILNode_ArrayInit_kind:
		{
			return ILNode_JSemAnalysis_31__((ILNode_ArrayInit *)node__, info, parent);
		}
		break;

		case ILNode_UserCast_kind:
		{
			return ILNode_JSemAnalysis_32__((ILNode_UserCast *)node__, info, parent);
		}
		break;

		case ILNode_InstanceOf_kind:
		{
			return ILNode_JSemAnalysis_33__((ILNode_InstanceOf *)node__, info, parent);
		}
		break;

		case ILNode_LogicalAnd_kind:
		{
			return ILNode_JSemAnalysis_34__((ILNode_LogicalAnd *)node__, info, parent);
		}
		break;

		case ILNode_LogicalOr_kind:
		{
			return ILNode_JSemAnalysis_35__((ILNode_LogicalOr *)node__, info, parent);
		}
		break;

		case ILNode_Add_kind:
		{
			return ILNode_JSemAnalysis_36__((ILNode_Add *)node__, info, parent);
		}
		break;

		case ILNode_Sub_kind:
		{
			return ILNode_JSemAnalysis_37__((ILNode_Sub *)node__, info, parent);
		}
		break;

		case ILNode_Mul_kind:
		{
			return ILNode_JSemAnalysis_38__((ILNode_Mul *)node__, info, parent);
		}
		break;

		case ILNode_Div_kind:
		{
			return ILNode_JSemAnalysis_39__((ILNode_Div *)node__, info, parent);
		}
		break;

		case ILNode_Rem_kind:
		{
			return ILNode_JSemAnalysis_40__((ILNode_Rem *)node__, info, parent);
		}
		break;

		case ILNode_And_kind:
		{
			return ILNode_JSemAnalysis_41__((ILNode_And *)node__, info, parent);
		}
		break;

		case ILNode_Or_kind:
		{
			return ILNode_JSemAnalysis_42__((ILNode_Or *)node__, info, parent);
		}
		break;

		case ILNode_Xor_kind:
		{
			return ILNode_JSemAnalysis_43__((ILNode_Xor *)node__, info, parent);
		}
		break;

		case ILNode_Shl_kind:
		{
			return ILNode_JSemAnalysis_44__((ILNode_Shl *)node__, info, parent);
		}
		break;

		case ILNode_Shr_kind:
		{
			return ILNode_JSemAnalysis_45__((ILNode_Shr *)node__, info, parent);
		}
		break;

		case ILNode_UShr_kind:
		{
			return ILNode_JSemAnalysis_46__((ILNode_UShr *)node__, info, parent);
		}
		break;

		case ILNode_Assign_kind:
		{
			return ILNode_JSemAnalysis_47__((ILNode_Assign *)node__, info, parent);
		}
		break;

		case ILNode_Eq_kind:
		{
			return ILNode_JSemAnalysis_48__((ILNode_Eq *)node__, info, parent);
		}
		break;

		case ILNode_Ne_kind:
		{
			return ILNode_JSemAnalysis_49__((ILNode_Ne *)node__, info, parent);
		}
		break;

		case ILNode_Lt_kind:
		{
			return ILNode_JSemAnalysis_50__((ILNode_Lt *)node__, info, parent);
		}
		break;

		case ILNode_Le_kind:
		{
			return ILNode_JSemAnalysis_51__((ILNode_Le *)node__, info, parent);
		}
		break;

		case ILNode_Gt_kind:
		{
			return ILNode_JSemAnalysis_52__((ILNode_Gt *)node__, info, parent);
		}
		break;

		case ILNode_Ge_kind:
		{
			return ILNode_JSemAnalysis_53__((ILNode_Ge *)node__, info, parent);
		}
		break;

		case ILNode_InvocationExpression_kind:
		{
			return ILNode_JSemAnalysis_54__((ILNode_InvocationExpression *)node__, info, parent);
		}
		break;

		case ILNode_Conditional_kind:
		{
			return ILNode_JSemAnalysis_55__((ILNode_Conditional *)node__, info, parent);
		}
		break;

		case ILNode_AssignAdd_kind:
		{
			return ILNode_JSemAnalysis_56__((ILNode_AssignAdd *)node__, info, parent);
		}
		break;

		case ILNode_AssignSub_kind:
		{
			return ILNode_JSemAnalysis_57__((ILNode_AssignSub *)node__, info, parent);
		}
		break;

		case ILNode_AssignMul_kind:
		{
			return ILNode_JSemAnalysis_58__((ILNode_AssignMul *)node__, info, parent);
		}
		break;

		case ILNode_AssignDiv_kind:
		{
			return ILNode_JSemAnalysis_59__((ILNode_AssignDiv *)node__, info, parent);
		}
		break;

		case ILNode_AssignRem_kind:
		{
			return ILNode_JSemAnalysis_60__((ILNode_AssignRem *)node__, info, parent);
		}
		break;

		case ILNode_AssignAnd_kind:
		{
			return ILNode_JSemAnalysis_61__((ILNode_AssignAnd *)node__, info, parent);
		}
		break;

		case ILNode_AssignOr_kind:
		{
			return ILNode_JSemAnalysis_62__((ILNode_AssignOr *)node__, info, parent);
		}
		break;

		case ILNode_AssignXor_kind:
		{
			return ILNode_JSemAnalysis_63__((ILNode_AssignXor *)node__, info, parent);
		}
		break;

		case ILNode_AssignShl_kind:
		{
			return ILNode_JSemAnalysis_64__((ILNode_AssignShl *)node__, info, parent);
		}
		break;

		case ILNode_AssignShr_kind:
		{
			return ILNode_JSemAnalysis_65__((ILNode_AssignShr *)node__, info, parent);
		}
		break;

		case ILNode_AssignUShr_kind:
		{
			return ILNode_JSemAnalysis_66__((ILNode_AssignUShr *)node__, info, parent);
		}
		break;

		case ILNode_NewExpression_kind:
		case ILNode_JNewExpression_kind:
		{
			return ILNode_JSemAnalysis_67__((ILNode_NewExpression *)node__, info, parent);
		}
		break;

		case ILNode_ObjectCreationExpression_kind:
		{
			return ILNode_JSemAnalysis_68__((ILNode_ObjectCreationExpression *)node__, info, parent);
		}
		break;

		case ILNode_BaseInit_kind:
		{
			return ILNode_JSemAnalysis_69__((ILNode_BaseInit *)node__, info, parent);
		}
		break;

		case ILNode_NonStaticInit_kind:
		{
			return ILNode_JSemAnalysis_70__((ILNode_NonStaticInit *)node__, info, parent);
		}
		break;

		case ILNode_Compound_kind:
		{
			return ILNode_JSemAnalysis_71__((ILNode_Compound *)node__, info, parent);
		}
		break;

		case ILNode_SwitchSectList_kind:
		{
			return ILNode_JSemAnalysis_72__((ILNode_SwitchSectList *)node__, info, parent);
		}
		break;

		case ILNode_CaseList_kind:
		{
			return ILNode_JSemAnalysis_73__((ILNode_CaseList *)node__, info, parent);
		}
		break;

		case ILNode_List_kind:
		case ILNode_CatchClauses_kind:
		{
			return ILNode_JSemAnalysis_74__((ILNode_List *)node__, info, parent);
		}
		break;

		case ILNode_Empty_kind:
		{
			return ILNode_JSemAnalysis_75__((ILNode_Empty *)node__, info, parent);
		}
		break;

		case ILNode_If_kind:
		{
			return ILNode_JSemAnalysis_76__((ILNode_If *)node__, info, parent);
		}
		break;

		case ILNode_While_kind:
		{
			return ILNode_JSemAnalysis_77__((ILNode_While *)node__, info, parent);
		}
		break;

		case ILNode_Do_kind:
		{
			return ILNode_JSemAnalysis_78__((ILNode_Do *)node__, info, parent);
		}
		break;

		case ILNode_For_kind:
		{
			return ILNode_JSemAnalysis_79__((ILNode_For *)node__, info, parent);
		}
		break;

		case ILNode_Switch_kind:
		{
			return ILNode_JSemAnalysis_80__((ILNode_Switch *)node__, info, parent);
		}
		break;

		case ILNode_Break_kind:
		{
			return ILNode_JSemAnalysis_81__((ILNode_Break *)node__, info, parent);
		}
		break;

		case ILNode_Return_kind:
		{
			return ILNode_JSemAnalysis_82__((ILNode_Return *)node__, info, parent);
		}
		break;

		case ILNode_ReturnExpr_kind:
		{
			return ILNode_JSemAnalysis_83__((ILNode_ReturnExpr *)node__, info, parent);
		}
		break;

		case ILNode_GotoCase_kind:
		{
			return ILNode_JSemAnalysis_84__((ILNode_GotoCase *)node__, info, parent);
		}
		break;

		case ILNode_NewScope_kind:
		{
			return ILNode_JSemAnalysis_85__((ILNode_NewScope *)node__, info, parent);
		}
		break;

		case ILNode_SwitchSection_kind:
		{
			return ILNode_JSemAnalysis_86__((ILNode_SwitchSection *)node__, info, parent);
		}
		break;

		case ILNode_CaseLabel_kind:
		{
			return ILNode_JSemAnalysis_87__((ILNode_CaseLabel *)node__, info, parent);
		}
		break;

		case ILNode_DefaultLabel_kind:
		{
			return ILNode_JSemAnalysis_88__((ILNode_DefaultLabel *)node__, info, parent);
		}
		break;

		case ILNode_ThrowExpr_kind:
		{
			return ILNode_JSemAnalysis_89__((ILNode_ThrowExpr *)node__, info, parent);
		}
		break;

		case ILNode_Try_kind:
		{
			return ILNode_JSemAnalysis_90__((ILNode_Try *)node__, info, parent);
		}
		break;

		case ILNode_CatchClause_kind:
		{
			return ILNode_JSemAnalysis_91__((ILNode_CatchClause *)node__, info, parent);
		}
		break;

		case ILNode_FinallyClause_kind:
		{
			return ILNode_JSemAnalysis_92__((ILNode_FinallyClause *)node__, info, parent);
		}
		break;

		case ILNode_LocalVarDeclaration_kind:
		{
			return ILNode_JSemAnalysis_93__((ILNode_LocalVarDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_ClassDefn_kind:
		{
			return ILNode_JSemAnalysis_94__((ILNode_ClassDefn *)node__, info, parent);
		}
		break;

		case ILNode_ScopeChange_kind:
		{
			return ILNode_JSemAnalysis_95__((ILNode_ScopeChange *)node__, info, parent);
		}
		break;

		case ILNode_FieldDeclaration_kind:
		{
			return ILNode_JSemAnalysis_96__((ILNode_FieldDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_FieldDeclarator_kind:
		{
			return ILNode_JSemAnalysis_97__((ILNode_FieldDeclarator *)node__, info, parent);
		}
		break;

		case ILNode_MethodDeclaration_kind:
		{
			return ILNode_JSemAnalysis_98__((ILNode_MethodDeclaration *)node__, info, parent);
		}
		break;

		case ILNode_JMain_kind:
		{
			return ILNode_JSemAnalysis_99__((ILNode_JMain *)node__, info, parent);
		}
		break;

		case ILNode_Identifier_kind:
		{
			return ILNode_JSemAnalysis_100__((ILNode_Identifier *)node__, info, parent);
		}
		break;

		case ILNode_QualIdent_kind:
		{
			return ILNode_JSemAnalysis_101__((ILNode_QualIdent *)node__, info, parent);
		}
		break;

		case ILNode_kind:
		case ILNode_Dummy_kind:
		case ILNode_JPackage_kind:
		case ILNode_JImport_kind:
		case ILNode_JImportType_kind:
		case ILNode_JImportPackage_kind:
		case ILNode_JTypeSuffix_kind:
		case ILNode_TypeSuffixDeclarator_kind:
		case ILNode_Expression_kind:
		case ILNode_Constant_kind:
		case ILNode_NullPtr_kind:
		case ILNode_Integer_kind:
		case ILNode_Int8_kind:
		case ILNode_UInt16_kind:
		case ILNode_UInt32_kind:
		case ILNode_UInt64_kind:
		case ILNode_UInt_kind:
		case ILNode_Real_kind:
		case ILNode_Decimal_kind:
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
		case ILNode_Overflow_kind:
		case ILNode_NoOverflow_kind:
		case ILNode_Pedantic_kind:
		case ILNode_NoPedantic_kind:
		case ILNode_BaseElement_kind:
		case ILNode_LValueBinaryExpr_kind:
		case ILNode_DerefField_kind:
		case ILNode_LocalVar_kind:
		case ILNode_ArgumentVar_kind:
		case ILNode_RefArgumentVar_kind:
		case ILNode_StaticField_kind:
		case ILNode_MemberField_kind:
		case ILNode_UnaryExpression_kind:
		case ILNode_DummyUnaryExpr_kind:
		case ILNode_UserUnaryOp_kind:
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
		case ILNode_ToConst_kind:
		case ILNode_VarArgExpand_kind:
		case ILNode_IsNull_kind:
		case ILNode_IsNonNull_kind:
		case ILNode_MakeRefAny_kind:
		case ILNode_RefType_kind:
		case ILNode_ArrayLength_kind:
		case ILNode_BinaryExpression_kind:
		case ILNode_DummyBinaryExpr_kind:
		case ILNode_UserLogical_kind:
		case ILNode_UserLogicalAnd_kind:
		case ILNode_UserLogicalOr_kind:
		case ILNode_BinaryArith_kind:
		case ILNode_BinaryBitwise_kind:
		case ILNode_BinaryShift_kind:
		case ILNode_UserBinaryOp_kind:
		case ILNode_Concat_kind:
		case ILNode_DelegateAdd_kind:
		case ILNode_DelegateSub_kind:
		case ILNode_Relational_kind:
		case ILNode_Comma_kind:
		case ILNode_ArgList_kind:
		case ILNode_RefValue_kind:
		case ILNode_TernaryExpression_kind:
		case ILNode_AssignExpression_kind:
		case ILNode_VarArgList_kind:
		case ILNode_Argument_kind:
		case ILNode_ArgArray_kind:
		case ILNode_BoxingExpression_kind:
		case ILNode_As_kind:
		case ILNode_Is_kind:
		case ILNode_Box_kind:
		case ILNode_Unbox_kind:
		case ILNode_Error_kind:
		case ILNode_DelegateCreationExpression_kind:
		case ILNode_DefaultConstructor_kind:
		case ILNode_ThisInit_kind:
		case ILNode_EmptyExpr_kind:
		case ILNode_Statement_kind:
		case ILNode_LabelledStatement_kind:
		case ILNode_Foreach_kind:
		case ILNode_ForeachString_kind:
		case ILNode_ForeachCollection_kind:
		case ILNode_LabelledBreak_kind:
		case ILNode_Continue_kind:
		case ILNode_LabelledContinue_kind:
		case ILNode_Goto_kind:
		case ILNode_GotoLabel_kind:
		case ILNode_GotoDefault_kind:
		case ILNode_Throw_kind:
		case ILNode_Lock_kind:
		case ILNode_LocalConstDeclaration_kind:
		case ILNode_LineInfo_kind:
		case ILNode_EventAddOrRemove_kind:
		case ILNode_Declaration_kind:
		case ILNode_EventDeclaration_kind:
		case ILNode_EventDeclarator_kind:
		case ILNode_ProxyDeclaration_kind:
		case ILNode_PropertyDeclaration_kind:
		case ILNode_EnumMemberDeclaration_kind:
		case ILNode_DelegateMemberDeclaration_kind:
		case ILNode_FormalParameter_kind:
		case ILNode_AttributeTree_kind:
		case ILNode_AttributeSection_kind:
		case ILNode_Attribute_kind:
		case ILNode_AttrArgs_kind:
		case ILNode_NamedArg_kind:
		{
			return ILNode_JSemAnalysis_102__((ILNode *)node__, info, parent);
		}
		break;

		default: break;
	}
	return (JavaSemValueDefault);
}

static void ILNode_Declaration_GatherStaticCtor_1__(ILNode_ClassDefn *node, ILNode_List * ctor)
#line 385 "java_decls.tc"
{
	if (node->body) 
	{
		JavaListGatherStaticCtor((ILNode_List *)node->body, ctor);
	}
}
#line 6465 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_2__(ILNode_ScopeChange *node, ILNode_List * ctor)
#line 385 "java_decls.tc"
{
	if (node->body) 
	{
		JavaListGatherStaticCtor((ILNode_List *)node->body, ctor);
	}
}
#line 6475 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_3__(ILNode_FieldDeclaration *node, ILNode_List * ctor)
#line 677 "java_decls.tc"
{
	if (node->fieldDeclarators) 
	{
		return JavaListGatherStaticCtor
							((ILNode_List *)node->fieldDeclarators, ctor);
	}
}
#line 6486 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_4__(ILNode_FieldDeclarator *node, ILNode_List * ctor)
#line 788 "java_decls.tc"
{
	ILNode_List_Add(ctor, node->staticCtor);
}
#line 6493 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_5__(ILNode_EventDeclaration *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6500 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_6__(ILNode_EventDeclarator *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6507 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_7__(ILNode_ProxyDeclaration *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6514 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_8__(ILNode_MethodDeclaration *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6521 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_9__(ILNode_PropertyDeclaration *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6528 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_10__(ILNode_EnumMemberDeclaration *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6535 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_11__(ILNode_DelegateMemberDeclaration *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6542 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_12__(ILNode_FormalParameter *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6549 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_13__(ILNode_AttributeTree *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6556 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_14__(ILNode_AttributeSection *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6563 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_15__(ILNode_Attribute *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6570 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_16__(ILNode_AttrArgs *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6577 "java_semantics.c"

static void ILNode_Declaration_GatherStaticCtor_17__(ILNode_NamedArg *node, ILNode_List * ctor)
#line 805 "java_decls.tc"
{
	return;
}
#line 6584 "java_semantics.c"

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

#line 99 "java_semantics.tc"


static ILType *JavaSemFilterVoid(ILType *resultType, ILNode *type)
{
	if(resultType == ILType_Void)
	{
		CCErrorOnLine(yygetfilename(type), yygetlinenum(type),
					  "`void' type is not allowed in this context");
		resultType = ILType_Int32;
	}
	return resultType;
}

static ILType *JavaSemValidate(ILNode *type, JavaSemValue value)
{
	if(!JavaSemIsType(value))
	{
		if(!JavaSemIsError(value))
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
		return JavaSemGetType(value);
	}
}

ILType *JavaSemType(ILNode *type, ILGenInfo *info, ILNode **parent)
{
	return JavaSemFilterVoid(JavaSemTypeVoid(type, info, parent), type);
}

ILType *JavaSemTypeLiteral(ILNode *type, ILGenInfo *info, ILNode **parent)
{
	JavaSemValue value;
	int save;

	/* NULL is used in some places in the grammar to indicate "void" */
	if(!type) return JavaSemFilterVoid(ILType_Void, type);
	
	save = info->inSemType;
	info->inSemType = info->typeGather;
	value = ILNode_JSemAnalysis(type, info, parent);
	info->inSemType = save;
	return JavaSemFilterVoid(JavaSemValidate(type, value),type);
}

ILType *JavaSemTypeVoid(ILNode *type, ILGenInfo *info, ILNode **parent)
{
	JavaSemValue value;
	int save;

	/* NULL is used in some places in the grammar to indicate "void" */
	if(!type) return ILType_Void;
 	
	save = info->inSemType;
	info->inSemType = info->typeGather;
	value = ILNode_JSemAnalysis(type, info, parent);
	info->inSemType = save;

	return JavaSemValidate(type, value);
}

int JavaSemExpectType (ILNode *type, ILGenInfo *info, ILNode **parent)
{
	JavaSemValue value;
	value = ILNode_JSemAnalysis(type, info, parent);
	return JavaSemIsType(value);
}

int JavaSemBaseType(ILNode *type, ILGenInfo *info, ILNode **parent,
				  ILNode **baseNode, ILClass **baseClass)
{
	JavaSemValue value;
	int save = info->inSemType;
	info->inSemType = info->typeGather;
	value = ILNode_JSemAnalysis(type, info, parent);
	info->inSemType = save;
	if(JavaSemIsType(value))
	{
		*baseNode = 0;
		*baseClass = ILTypeToClass(info, JavaSemGetType(value));
		return (*baseClass != 0);
	}
	else if(JavaSemIsTypeNode(value))
	{
		*baseNode = JavaSemGetTypeNode(value);
		*baseClass = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

int JavaSemExpectValue(ILNode *node, ILGenInfo *info,
					 ILNode **parent, JavaSemValue *value)
{
	*value = ILNode_JSemAnalysis(node, info, parent);
	return JavaSemIsValue(*value);
}

void JavaSemProgramItem(ILGenInfo *info, ILProgramItem *item)
{
	ILGenItemContext context;
	ILNode *node;
	node = ILEnterProgramItemContext(info, item, CCGlobalScope, &context);
	if(node)
	{
		ILNode_JSemAnalysis(node, info, &node);
		ILLeaveProgramItemContext(info, &context);
	}
}
#line 121 "java_types.tc"

const char *JavaTypeToName(ILType *type)
{
	if(ILType_IsPrimitive(type))
	{
		/* Get the name of a primitive type */
		switch(ILType_ToElement(type))
		{
			case IL_META_ELEMTYPE_VOID:			return "void";
			case IL_META_ELEMTYPE_BOOLEAN:		return "boolean";
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
		if(namespace)
		{
			return ILInternAppendedString
						(ILInternAppendedString
							(ILInternString((char *)namespace, -1),
							 ILInternString((char *)".", 1)),
						 ILInternString((char *)name, -1)).string;
		}
		else
		{
			return name;
		}
	}
	else if(type != ILType_Invalid)
	{
		/* Get the name of a complex type */
		int kind = ILType_Kind(type);
		if(kind == IL_TYPE_COMPLEX_BYREF)
		{
			return ILInternAppendedString
					(ILInternString((char *)JavaTypeToName(ILType_Ref(type)), -1),
					 ILInternString((char *)" &", 2)).string;
		}
		else if(kind == IL_TYPE_COMPLEX_PTR)
		{
			return ILInternAppendedString
					(ILInternString((char *)JavaTypeToName(ILType_Ref(type)), -1),
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
			str = ILInternString((char *)JavaTypeToName(elemType), -1);
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
			  ((char *)(JavaTypeToName(ILType_FromClass
			  				(type->un.modifier__.info__))), -1);
			str = ILInternAppendedString(str, temp);
			temp = ILInternString(" */ ", -1);
			str = ILInternAppendedString(str, temp);
			temp = ILInternString
				((char *)(JavaTypeToName(type->un.modifier__.type__)), -1);
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
				((char *)(JavaTypeToName(ILTypeGetReturnWithPrefixes(type))), -1);

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
				temp = ILInternString((char *)(JavaTypeToName(paramType)), -1);
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


#line 7008 "java_semantics.c"
