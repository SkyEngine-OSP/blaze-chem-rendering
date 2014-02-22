/* c_semantics.c.  Generated automatically by treecc */
#line 577 "c_defs.tc"

#include <cscc/c/c_internal.h>
#include "il_dumpasm.h"
#line 23 "c_ainit.tc"


/*
 * Look ahead to the next item in a list iteration.
 */
static ILNode *IterLookAhead(ILNode_ListIter *iter)
{
	ILNode_ListIter copy = *iter;
	return ILNode_ListIter_Next(&copy);
}

/*
 * Forward declaration.
 */
static int SkipInitializer(ILNode_ListIter *iter, ILType *type);

/*
 * Skip the initializer for an array type.  Returns zero if
 * the initializer does not have sufficient elements.
 */
static int SkipArrayInitializer(ILNode_ListIter *iter, ILType *type)
{
	ILNode *node;
	ILUInt32 numElems;
	ILType *elemType;

	/* Look ahead to see if we are at the end or a nested initializer */
	node = IterLookAhead(iter);
	if(!node)
	{
		return 0;
	}
	else if(yyisa(node, ILNode_CArrayInit))
	{
		/* Assume that the entire array is within the nested initializer */
		ILNode_ListIter_Next(iter);
		return 1;
	}

	/* Get the number of elements and the element type */
	numElems = CTypeGetNumElems(type);
	elemType = CTypeGetElemType(type);

	/* Recognize the elements, inline within the current array */
	while(numElems > 0)
	{
		if(!SkipInitializer(iter, elemType))
		{
			return 0;
		}
		--numElems;
	}
	return 1;
}

/*
 * Skip the initializer for a struct type.  Returns zero if
 * the initializer does not have sufficient elements.
 */
static int SkipStructInitializer(ILNode_ListIter *iter, ILType *type)
{
	ILClass *classInfo = ILType_ToValueType(ILTypeStripPrefixes(type));
	ILField *field;
	ILNode *node;

	/* If the next element is an array initializer, then assume that
	   it contains the entire structure in a nested scope */
	node = IterLookAhead(iter);
	if(node && yyisa(node, ILNode_CArrayInit))
	{
		ILNode_ListIter_Next(iter);
		return 1;
	}

	/* Skip the struct elements, which are inline within the parent array */
	field = 0;
	while((field = (ILField *)ILClassNextMemberByKind
				(classInfo, (ILMember *)field, IL_META_MEMBERKIND_FIELD)) != 0)
	{
		if(!ILField_IsStatic(field))
		{
			if(!SkipInitializer(iter, ILFieldGetTypeWithPrefixes(field)))
			{
				return 0;
			}
		}
	}
	return 1;
}

/*
 * Skip the initializer for a particular type.
 */
static int SkipInitializer(ILNode_ListIter *iter, ILType *type)
{
	if(CTypeIsStruct(type) || CTypeIsUnion(type))
	{
		return SkipStructInitializer(iter, type);
	}
	else if(CTypeIsArray(type))
	{
		return SkipArrayInitializer(iter, type);
	}
	else
	{
		return (ILNode_ListIter_Next(iter) != 0);
	}
}

ILUInt32 CArrayInitializerSize(ILType *type, ILNode *init)
{
	ILType *elemType = CTypeGetElemType(type);
	ILNode *list = ((ILNode_CArrayInit *)init)->expr;
	ILNode_ListIter iter;
	ILUInt32 len = 0;

	/* Scan the list, skipping over elements as we find them.
	   Type checking of the elements is performed later */
	ILNode_ListIter_Init(&iter, list);
	while(IterLookAhead(&iter) != 0)
	{
		if(!SkipInitializer(&iter, elemType))
		{
			CCErrorOnLine(yygetfilename(init), yygetlinenum(init),
						  _("invalid array initializer"));
			return 1;
		}
		++len;
	}

	/* Return the final length to the caller */
	return len;
}

/*
 * Perform semantic analysis on an initializer, defined by an iterator.
 */
static void InitializerSemAnalysis(ILGenInfo *info, ILType *type,
								   ILNode *init, ILNode_ListIter *iter)
{
	ILNode *node = IterLookAhead(iter);
	CSemValue value;
	ILUInt32 size;
	ILUInt32 numElems;
	ILType *elemType;
	ILNode_ListIter inner;
	ILClass *classInfo;
	ILField *field;

	if(CTypeIsArray(type))
	{
		/* Assign to the elements of an array */
		numElems = CTypeGetNumElems(type);
		elemType = CTypeGetElemType(type);
		if(node && yyisa(node, ILNode_CString) &&
		   (ILTypeIdentical(elemType, ILType_Int8) ||
		    ILTypeIdentical(elemType, ILType_UInt8)))
		{
			/* Assign a string to a "char" array */
			node = ILNode_ListIter_Next(iter);
			size = ((ILNode_CString *)node)->len;
			if(size > numElems)
			{
				CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
			  	    _("initializer-string for array of chars is too long"));
			}
		}
		else if(node && yyisa(node, ILNode_CWString) &&
		        (ILTypeIdentical(elemType, ILType_Int16) ||
		         ILTypeIdentical(elemType, ILType_UInt16) ||
		         ILTypeIdentical(elemType, ILType_Char)))
		{
			/* Assign a string to a "wchar" array */
			node = ILNode_ListIter_Next(iter);
			size = CGenWStringLength
					 (((ILNode_CWString *)node)->str,
					  ((ILNode_CWString *)node)->len);
			if(size > numElems)
			{
				CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
		  	      _("initializer-string for array of wide chars is too long"));
			}
		}
		else
		{
			/* Assign to an ordinary array */
			while(numElems > 0 && node != 0)
			{
				if(yyisa(node, ILNode_CArrayInit))
				{
					/* The element is specified as a nested array init scope */
					ILNode_ListIter_Init
						(&inner, ((ILNode_CArrayInit *)node)->expr);
					InitializerSemAnalysis
						(info, elemType,
						 ((ILNode_CArrayInit *)node)->expr, &inner);
					if(ILNode_ListIter_Next(&inner) != 0)
					{
						CCWarningOnLine
							(yygetfilename(init), yygetlinenum(init),
							 _("excess elements in array initializer"));
					}
					ILNode_ListIter_Next(iter);
				}
				else
				{
					/* The element is specified inline within the parent */
					InitializerSemAnalysis(info, elemType, init, iter);
				}
				node = IterLookAhead(iter);
				--numElems;
			}
		}
	}
	else if(CTypeIsStruct(type) || CTypeIsUnion(type))
	{
		/* Assign to the fields of a structure or union */
		classInfo = ILType_ToValueType(ILTypeStripPrefixes(type));
		field = 0;
		while((field = (ILField *)ILClassNextMemberByKind
				(classInfo, (ILMember *)field, IL_META_MEMBERKIND_FIELD)) != 0)
		{
			if(!node)
			{
				break;
			}
			if(!ILField_IsStatic(field))
			{
				elemType = ILFieldGetTypeWithPrefixes(field);
				if(yyisa(node, ILNode_CArrayInit) &&
				   (CTypeIsStruct(elemType) || CTypeIsUnion(elemType) ||
				    CTypeIsArray(elemType)))
				{
					/* The initializer is specified as a nested scope */
					ILNode_ListIter_Init
						(&inner, ((ILNode_CArrayInit *)node)->expr);
					InitializerSemAnalysis
						(info, elemType,
						 ((ILNode_CArrayInit *)node)->expr, &inner);
					if(ILNode_ListIter_Next(&inner) != 0)
					{
						CCWarningOnLine
							(yygetfilename(init), yygetlinenum(init),
							 _("excess elements in structure initializer"));
					}
					ILNode_ListIter_Next(iter);
				}
				else
				{
					InitializerSemAnalysis(info, elemType, init, iter);
				}
			}
			node = IterLookAhead(iter);
		}
	}
	else
	{
		/* Assign a scalar value */
		if(!node)
		{
			CCErrorOnLine(yygetfilename(init), yygetlinenum(init),
						  _("missing scalar initializer value"));
			return;
		}

		/* Perform semantic analysis on the scalar value */
		node = ILNode_ListIter_Next(iter);
		value = ILNode_CSemAnalysis(node, info, iter->last, 0);
		node = *(iter->last);

		/* Check that the scalar value is an r-value */
		if(!CSemIsRValue(value))
		{
			if(!CSemIsError(value))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  	  "invalid rvalue in assignment");
			}
			return;
		}

		/* Check that we can coerce from "value" to "type" */
		if(ILTypeStripPrefixes(type) == ILType_Boolean &&
		   (CSemIsBoolean(value) ||
		    ILTypeStripPrefixes(CSemGetType(value)) == ILType_Boolean))
		{
			/* Assigning a value to a "_Bool" variable */
			return;
		}
		else
		{
			if(!CCanCoerceValue(value, type))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  "incompatible types in assignment");
				return;
			}

			/* Insert coercion nodes to convert the rvalue appropriately */
			CCoerceNode(info, node, iter->last, value, type);
		}
	}
}

#line 23 "c_builtin.tc"


/*
 * Perform semantic analysis on a "va_list" value and verify that
 * it is an l-value of the correct type.
 */
static void VaListSem(ILGenInfo *info, ILNode *node, ILNode **parent)
{
	CSemValue value;

	/* Perform semantic analysis on the value */
	value = ILNode_CSemAnalysis(node, info, parent, 0);
	if(!CSemIsLValue(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("`va_list' value is not an l-value"));
		}
		return;
	}

	/* Verify that the type is correct */
	if(!CTypeIsIdentical(CSemGetType(value), CTypeCreateVaList(info)))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("incorrect type for variable-argument list"));
	}
}

#line 31 "c_lvalue.tc"


/*
 * Convert a C# member reference.
 */
static CSemValue ConvertCSharpMember(ILGenInfo *info, ILNode *expr,
									 ILNode **parent, CSemValue value)
{
	ILField *field;
	ILProperty *property;
	ILType *type;

	if(CSemIsField(value))
	{
		/* We've resolved a member field */
		field = CSemGetField(value);
		type = ILField_Type(field);
		if(CTypeIsArray(type))
		{
			/* Arrays decay immediately into r-values */
			CSemSetDecayedRValue(value, CTypeDecay(info, type), type);
		}
		else if(ILField_IsInitOnly(field))
		{
			/* Read-only fields cannot be l-values */
			CSemSetRValue(value, type);
		}
		else
		{
			/* Everything else must be an l-value field */
			CSemSetLValue(value, type);
		}
		*parent = ILNode_MemberField_create(expr, field);
		CGenCloneLine(*parent, (ILNode *)expr);
	}
	else if(CSemIsProperty(value))
	{
		/* We've resolved a member property */
		property = CSemGetProperty(value);
		type = ILTypeGetReturn(ILProperty_Signature(property));
		if(ILProperty_Getter(property))
		{
			if(ILProperty_Setter(property))
			{
				/* Read-write properties are l-values */
				CSemSetLValueNoRef(value, type);
			}
			else
			{
				/* Read-only properties are r-values */
				CSemSetRValue(value, type);
			}
		}
		else
		{
			/* Write-only properties are s-values */
			CSemSetSValue(value, type);
		}
		*parent = ILNode_MemberProperty_create(expr, property);
		CGenCloneLine(*parent, (ILNode *)expr);
	}
	else if(CSemIsMethodGroup(value))
	{
		/* We've resolved a method group.  We mark it with an "as-is"
		   node so that "c_invoke.tc" can detect the difference between
		   static and instance method calls */
		*parent = ILNode_AsIs_create(expr);
		CGenCloneLine(*parent, (ILNode *)expr);
	}

	/* Return the modified semantic value */
	return value;
}

#line 351 "c_lvalue.tc"


/*
 * Add a complex field offset value to a pointer on the stack.
 */
void CAddComplexFieldOffset(ILGenInfo *info, ILType *type, ILField *field)
{
	if(CTypeIsStruct(type) && CTypeNextField(type, 0) != field)
	{
		if(info->asmOutput)
		{
			fputs("\tldsfld\tunsigned int32 ", info->asmOutput);
			ILDumpClassName
				(info->asmOutput, info->image,
				 ILTypeToClass(info, ILTypeStripPrefixes(type)),
				 IL_DUMP_QUOTE_NAMES);
			fputs("::'", info->asmOutput);
			fputs(ILField_Name(field), info->asmOutput);
			fputs(".offset'\n", info->asmOutput);
		}
		ILGenAdjust(info, 1);
		ILGenSimple(info, IL_OP_CONV_U);
		ILGenSimple(info, IL_OP_ADD);
		ILGenAdjust(info, -1);
	}
}

#line 576 "c_lvalue.tc"


/*
 * Resolve a member within a C#-style type.
 */
static CSemValue ResolveMember(ILGenInfo *info, ILType *type,
							   const char *name, int isStatic)
{
	CSemValue value;
	ILClass *classInfo;
	ILClass *callScope;
	ILClass *tempClass;
	ILClass *child;
	ILNestedInfo *nested;
	ILMember *member;
	ILImplements *impl;

	/* Convert the type into its class form */
	classInfo = ILClassResolve(ILTypeToClass(info, type));

	/* Get the scope that we will be calling from, for access checks */
	callScope = ILClassLookup(ILClassGlobalScope(info->image), "<Module>", 0);

	/* Check for nested types first if we are looking for static members */
	if(isStatic)
	{
		tempClass = classInfo;
		while(tempClass != 0)
		{
			nested = 0;
			while((nested = ILClassNextNested(tempClass, nested)) != 0)
			{
				child = ILClassResolve(ILNestedInfoGetChild(nested));
				if(!strcmp(ILClass_Name(child), name))
				{
					if(ILClassAccessible(child, callScope))
					{
						CSemSetType(value, ILClassToType(child));
						return value;
					}
				}
			}
			tempClass = ILClass_Parent(tempClass);
		}
	}

	/* Scan the class, its parents, and interfaces, for matches */
	tempClass = classInfo;
	while(tempClass != 0)
	{
		member = ILClassNextMemberMatch(tempClass, 0, 0, name, 0);
		if(member && ILMemberAccessible(member, callScope))
		{
			if(ILMember_IsField(member))
			{
				if((isStatic && ILField_IsStatic((ILField *)member)) ||
				   (!isStatic && !ILField_IsStatic((ILField *)member)))
				{
					CSemSetField(value, (ILField *)member);
					return value;
				}
			}
			else if(ILMember_IsMethod(member))
			{
				if((isStatic && ILMethod_IsStatic((ILMethod *)member)) ||
				   (!isStatic && !ILMethod_IsStatic((ILMethod *)member)))
				{
					CSemSetMethodGroup(value, type, name);
					return value;
				}
			}
			else if(ILMember_IsProperty(member))
			{
				ILMethod *accessor = ILProperty_Getter((ILProperty *)member);
				if(!accessor)
				{
					accessor = ILProperty_Setter((ILProperty *)member);
				}
				if(accessor)
				{
					if((isStatic && ILMethod_IsStatic((ILMethod *)accessor)) ||
					   (!isStatic && !ILMethod_IsStatic((ILMethod *)accessor)))
					{
						CSemSetProperty(value, (ILProperty *)member);
						return value;
					}
				}
			}
		}
		if(!isStatic)
		{
			/* Scan the interfaces if we are looking for an instance member */
			impl = 0;
			while((impl = ILClassNextImplements(tempClass, impl)) != 0)
			{
				value = ResolveMember
					(info, ILClassToType(ILImplementsGetInterface(impl)),
					 name, isStatic);
				if(!CSemIsError(value))
				{
					if(CSemIsMethodGroup(value))
					{
						/* Replace the interface type with the real type */
						CSemSetMethodGroup(value, type, name);
					}
					return value;
				}
			}
		}
		tempClass = ILClass_Parent(tempClass);
	}

	/* If we get here, then we were unable to find anything */
	return CSemValueError;
}

#line 63 "c_invoke.tc"


/*
 * Information about an evaluated function argument.
 */
typedef struct
{
	CSemValue	value;
	ILNode     *node;
	ILNode    **parent;

} CEvalArg;

/*
 * Count the number of values in an argument list.
 */
static ILUInt32 CountArgs(ILNode *args)
{
	ILUInt32 num;
	if(!args)
	{
		return 0;
	}
	num = 1;
	while(yyisa(args, ILNode_ArgList))
	{
		++num;
		args = ((ILNode_ArgList *)args)->expr1;
	}
	return num;
}

/*
 * Perform semantic analysis on a specific invocation argument.
 */
static void ArgumentSem(ILGenInfo *info, CEvalArg *arg, ILNode *argList,
						ILNode **argListParent, ILUInt32 index, ILUInt32 num)
{
	/* Find the actual argument and its parent */
	while(num > (index + 1))
	{
		--num;
		argListParent = &(((ILNode_ArgList *)argList)->expr1);
		argList = ((ILNode_ArgList *)argList)->expr1;
	}
	if(yyisa(argList, ILNode_ArgList))
	{
		argListParent = &(((ILNode_ArgList *)argList)->expr2);
		argList = ((ILNode_ArgList *)argList)->expr2;
	}

	/* Populate the "arg" structure */
	arg->value = ILNode_CSemAnalysis(argList, info, argListParent, 0);
	arg->node = *argListParent;
	arg->parent = argListParent;

	/* Check that the argument is an r-value */
	if(!CSemIsRValue(arg->value))
	{
		if(!CSemIsError(arg->value))
		{
			CCErrorOnLine(yygetfilename(arg->node),
						  yygetlinenum(arg->node),
						  _("invalid value for argument %lu"),
						  (unsigned long)(index + 1));
		}
	}
}

/*
 * Coerce an array of argument values to their corresponding
 * types in a function signature.
 */
static void CoerceArgs(ILGenInfo *info, ILNode_CInvocationExpression *node,
					   ILType *signature, CEvalArg *args, ILUInt32 numArgs)
{
	ILUInt32 numParams = (unsigned long)ILTypeNumParams(signature);
	ILUInt32 paramNum;
	ILType *type;

	/* Check that we have the correct number of arguments */
	if(numArgs < numParams)
	{
		if(node->name)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("too few arguments to function `%s'"),
						  node->name);
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("too few arguments to function call"));
		}
		numParams = numArgs;
	}
	else if(numArgs > numParams)
	{
		if(node->name)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("too many arguments to function `%s'"),
						  node->name);
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("too many arguments to function call"));
		}
	}

	/* Coerce the arguments that we have left */
	for(paramNum = 0; paramNum < numParams; ++paramNum)
	{
		type = CTypeGetParam(signature, paramNum + 1);
		if(CTypeIsByRef(type))
		{
			/* This argument is passed by reference (i.e. 'type & name') */
			type = CTypeGetByRef(type);
			if(!CSemIsLValue(args[paramNum].value))
			{
				if(node->name)
				{
					CCErrorOnLine
						(yygetfilename(node), yygetlinenum(node),
						 _("l-value expected for argument %lu of `%s'"),
						 (unsigned long)(paramNum + 1), node->name);
				}
				else
				{
					CCErrorOnLine
						(yygetfilename(node), yygetlinenum(node),
						 _("l-value expected for argument %lu"),
						 (unsigned long)(paramNum + 1));
				}
			}
			else if(!CTypeIsIdentical(type, CSemGetType(args[paramNum].value)))
			{
				/* The type must match exactly in reference parameters */
				goto incompat;
			}
			else
			{
				if(CTypeIsConst(CSemGetType(args[paramNum].value)) &&
				   !CTypeIsConst(type))
				{
					/* Trying to pass a const value via a non-const argument */
					if(node->name)
					{
						CCErrorOnLine
							(yygetfilename(node), yygetlinenum(node),
							 _("discarding const from argument %lu of `%s'"),
							 (unsigned long)(paramNum + 1), node->name);
					}
					else
					{
						CCErrorOnLine
							(yygetfilename(node), yygetlinenum(node),
							 _("discarding const from argument %lu"),
							 (unsigned long)(paramNum + 1));
					}
				}

				/* Wrap the l-value in an address-of node to pass by-ref */
				*(args[paramNum].parent) = ILNode_AddressOf_create
						(args[paramNum].node);
				CGenCloneLine(*(args[paramNum].parent), args[paramNum].node);
			}
		}
		else if(!CCanCoerceValue(args[paramNum].value, type))
		{
		incompat:
			if(node->name)
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  _("incompatible type for argument %lu of `%s'"),
							  (unsigned long)(paramNum + 1), node->name);
			}
			else
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  _("incompatible type for argument %lu"),
							  (unsigned long)(paramNum + 1));
			}
		}
		else
		{
			CCoerceNode(info, args[paramNum].node, args[paramNum].parent,
						args[paramNum].value, type);
		}
	}
}

/*
 * Build a call site for a vararg function call.
 */
static ILType *BuildVarargCallSite(ILGenInfo *info,
								   ILType *origSignature,
								   CEvalArg *args, ILUInt32 numArgs)
{
	ILType *signature;
	ILUInt32 numParams;
	ILUInt32 paramNum;
	ILType *type;

	/* Copy the existing signature and its arguments */
	signature = ILTypeCreateMethod
			(info->context, ILTypeGetReturnWithPrefixes(origSignature));
	if(!signature)
	{
		CCOutOfMemory();
	}
	ILTypeSetCallConv(signature, ILType_CallConv(origSignature));
	numParams = ILTypeNumParams(origSignature);
	for(paramNum = 1; paramNum <= numParams; ++paramNum)
	{
		if(!ILTypeAddParam(info->context, signature,
				   ILTypeGetParamWithPrefixes(origSignature, paramNum)))
		{
			CCOutOfMemory();
		}
	}

	/* Add the sentinel separator */
	if(!ILTypeAddSentinel(info->context, signature))
	{
		CCOutOfMemory();
	}

	/* Coerce the remaining arguments to their natural vararg types
	   and add the types to the call site signature */
	for(paramNum = 0; paramNum < numArgs; ++paramNum)
	{
		type = CFunctionNaturalType(info, CSemGetType(args[paramNum].value), 1);

		/* Use "CCastNode" to prevent "pointer->integer" warnings
		   that are not important in this context */
		CCastNode(info, args[paramNum].node, args[paramNum].parent,
				  args[paramNum].value, type);
		if(!ILTypeAddParam(info->context, signature, type))
		{
			CCOutOfMemory();
		}
	}
	return signature;
}

#line 545 "c_invoke.tc"


/*
 * Internal worker function for locating static C# methods.
 */
static ILMethod *ResolveCSMethod(ILGenInfo *info, ILClass *classInfo,
							     ILClass *callScope, const char *name,
							     ILType **args, int numArgs, int isStatic)
{
	ILMember *member;
	ILMethod *method;
	ILMethod *closestMatch = 0;
	ILType *signature;
	ILType *argType;
	int arg, same;

	while(classInfo != 0)
	{
		classInfo = ILClassResolve(classInfo);
		member = 0;
		while((member = ILClassNextMemberByKind
					(classInfo, member, IL_META_MEMBERKIND_METHOD)) != 0)
		{
			/* Filter out members that aren't interesting */
			method = (ILMethod *)member;
			if(strcmp(ILMethod_Name(method), name) != 0)
			{
				continue;
			}
			if((isStatic && !ILMethod_IsStatic(method)) ||
			   (!isStatic && ILMethod_IsStatic(method)))
			{
				continue;
			}

			/* Check that this is the signature we are interested in */
			signature = ILMethod_Signature(method);
			if(!ILType_IsMethod(signature))
			{
				continue;
			}
			if(numArgs != (int)(ILTypeNumParams(signature)))
			{
				continue;
			}
			same = 1;
			for(arg = 1; arg <= numArgs; ++arg)
			{
				argType = ILTypeGetParam(signature, arg);
				if(!ILTypeIdentical(argType, args[arg - 1]))
				{
					if(!CCanCoerce(args[arg - 1], argType))
					{
						break;
					}
					same = 0;
				}
			}
			if(arg <= numArgs)
			{
				continue;
			}

			/* Check the method's access level against the call scope */
			if(!ILMemberAccessible(member, callScope))
			{
				continue;
			}

			/* We've found a candidate method */
			if(same)
			{
				/* We have an exact match, so return that */
				return method;
			}
			else if(!closestMatch)
			{
				/* This match is close, but try to find a better one */
				closestMatch = method;
			}
		}

		/* Move up to the parent class */
		if(ILClass_IsInterface(classInfo))
		{
			/* Scan the parents of this interface */
			ILImplements *impl = 0;
			while((impl = ILClassNextImplements(classInfo, impl)) != 0)
			{
				method = ResolveCSMethod(info, ILImplementsGetInterface(impl),
									     callScope, name, args, numArgs,
										 isStatic);
				if(method)
				{
					return method;
				}
			}
			classInfo = 0;
		}
		else
		{
			classInfo = ILClass_Parent(classInfo);
		}
	}

	/* Return the closest match if we didn't find an exact match */
	return closestMatch;
}

#line 21 "c_oper.tc"


/*
 * Construct a boolean constant node.
 */
static ILNode *CreateBoolConstant(ILNode *cloneFrom, ILInt32 value)
{
	ILNode *node;
	if(value)
	{
		node = ILNode_True_create();
	}
	else
	{
		node = ILNode_False_create();
	}
	CGenCloneLine(node, cloneFrom);
	return node;
}

/*
 * Construct a boolean constant semantic value.
 */
static CSemValue CreateBoolValue(ILInt32 value)
{
	ILEvalValue eval;
	CSemValue result;
	eval.valueType = ILMachineType_Int32;
	eval.un.i4Value = value;
	CSemSetConstant(result, ILType_Boolean, eval);
	return result;
}

/*
 * Construct a constant node from a compile-time constant.
 * If it isn't possible to construct a node, return "origNode".
 */
static ILNode *CreateConstantNode(ILNode *cloneFrom, ILNode *origNode,
								  ILEvalValue *evalValue)
{
	ILNode *node = 0;
	switch(evalValue->valueType)
	{
		case ILMachineType_Boolean:
		{
			node = CreateBoolConstant(cloneFrom, evalValue->un.i4Value);
		}
		break;

		case ILMachineType_Int8:
		{
			if(evalValue->un.i4Value >= 0)
			{
				node = ILNode_Int8_create
					((ILUInt64)(evalValue->un.i4Value), 0, 1);
			}
			else
			{
				node = ILNode_Int8_create
					((ILUInt64)(-((ILInt64)(evalValue->un.i4Value))), 1, 1);
			}
		}
		break;

		case ILMachineType_UInt8:
		{
			node = ILNode_UInt8_create
				((ILUInt64)(evalValue->un.i4Value), 0, 0);
		}
		break;

		case ILMachineType_Int16:
		{
			if(evalValue->un.i4Value >= 0)
			{
				node = ILNode_Int16_create
					((ILUInt64)(evalValue->un.i4Value), 0, 1);
			}
			else
			{
				node = ILNode_Int16_create
					((ILUInt64)(-((ILInt64)(evalValue->un.i4Value))), 1, 1);
			}
		}
		break;

		case ILMachineType_UInt16:
		{
			node = ILNode_UInt16_create
				((ILUInt64)(evalValue->un.i4Value), 0, 0);
		}
		break;

		case ILMachineType_Char:
		{
			node = ILNode_Char_create
				((ILUInt64)(evalValue->un.i4Value), 0, 0);
		}
		break;

		case ILMachineType_Int32:
		{
			if(evalValue->un.i4Value >= 0)
			{
				node = ILNode_Int32_create
					((ILUInt64)(evalValue->un.i4Value), 0, 1);
			}
			else
			{
				node = ILNode_Int32_create
					((ILUInt64)(-((ILInt64)(evalValue->un.i4Value))), 1, 1);
			}
		}
		break;

		case ILMachineType_UInt32:
		{
			node = ILNode_UInt32_create
				((ILUInt64)(ILUInt32)(evalValue->un.i4Value), 0, 0);
		}
		break;

		case ILMachineType_Int64:
		{
			if(evalValue->un.i4Value >= 0)
			{
				node = ILNode_Int64_create
					((ILUInt64)(evalValue->un.i8Value), 0, 1);
			}
			else
			{
				node = ILNode_Int64_create
					((ILUInt64)(-(evalValue->un.i8Value)), 1, 1);
			}
		}
		break;

		case ILMachineType_UInt64:
		{
			node = ILNode_UInt64_create
				((ILUInt64)(evalValue->un.i8Value), 0, 0);
		}
		break;

		case ILMachineType_NativeInt:
		{
			if(evalValue->un.i4Value >= 0)
			{
				node = ILNode_Int_create
					((ILUInt64)(evalValue->un.i4Value), 0, 1);
			}
			else
			{
				node = ILNode_Int_create
					((ILUInt64)(-((ILInt64)(evalValue->un.i4Value))), 1, 1);
			}
		}
		break;

		case ILMachineType_NativeUInt:
		{
			node = ILNode_UInt_create
				((ILUInt64)(ILUInt32)(evalValue->un.i4Value), 0, 0);
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
			if(evalValue->un.i4Value >= 0)
			{
				node = ILNode_CastSimple_create(ILNode_Int_create
					((ILUInt64)(evalValue->un.i4Value), 0, 1),
					ILMachineType_UnmanagedPtr);
			}
			else
			{
				node = ILNode_CastSimple_create(ILNode_Int_create
					((ILUInt64)(-((ILInt64)(evalValue->un.i4Value))), 1, 1),
					ILMachineType_UnmanagedPtr);
			}
		}
		break;

		case ILMachineType_Float32:
		{
			node = ILNode_Float32_create(evalValue->un.r4Value);
		}
		break;

		case ILMachineType_Float64:
		{
			node = ILNode_Float64_create(evalValue->un.r8Value);
		}
		break;

		case ILMachineType_NativeFloat:
		{
			node = ILNode_Float_create(evalValue->un.r8Value);
		}
		break;

		default: break;
	}
	if(node)
	{
		CGenCloneLine(node, cloneFrom);
		return node;
	}
	else
	{
		return cloneFrom;
	}
}

#line 426 "c_oper.tc"


/*
 * Determine if a machine type is numeric or integer.
 */
#define	IsNumericMachineType(type)	\
			((type) >= ILMachineType_Boolean && \
			 (type) <= ILMachineType_NativeFloat)
#define	IsIntegerMachineType(type)	\
			((type) >= ILMachineType_Boolean && \
			 (type) <= ILMachineType_NativeUInt)
#define	IsSmallIntegerMachineType(type)	\
			((type) >= ILMachineType_Boolean && \
			 (type) <= ILMachineType_Int32)

/*
 * Determine if a machine type is a signed integer type.
 */
static int IsSignedMachineType(ILMachineType type)
{
	return (type == ILMachineType_Int8 ||
			type == ILMachineType_Int16 ||
			type == ILMachineType_Int32 ||
			type == ILMachineType_Int64);
}

/*
 * Multiply a node by a pointer element type size.
 */
static ILNode *MulPtrSize(ILNode *node, CSemValue value, ILType *elemType)
{
	ILEvalValue *evalValue = CSemGetConstant(value);
	ILNode *newNode;
	ILInt64 totalSize;
	CTypeLayoutInfo layout;
	CTypeGetLayoutInfo(elemType, &layout);
	if(layout.category == C_TYPECAT_FIXED)
	{
		/* The size is constant, so try to compute at compile time */
		if(layout.size == 0)
		{
			newNode = ILNode_Int_create(0, 0, 0);
			CGenCloneLine(newNode, node);
			return newNode;
		}
		else if(layout.size == 1)
		{
			return node;
		}
		if(evalValue && IsSmallIntegerMachineType(evalValue->valueType))
		{
			totalSize = ((ILInt64)(layout.size)) *
						((ILInt64)(evalValue->un.i4Value));
			if(totalSize >= (ILInt64)IL_MIN_INT32 &&
			   totalSize <= (ILInt64)IL_MAX_INT32)
			{
				if(totalSize >= 0)
				{
					newNode = ILNode_Int_create((ILUInt64)totalSize, 0, 1);
				}
				else
				{
					newNode = ILNode_Int_create
						((ILUInt64)(-totalSize), 1, 1);
				}
				CGenCloneLine(newNode, node);
				return newNode;
			}
		}
		if(layout.size == 2)
		{
			newNode = ILNode_Shl_create
				(node, ILNode_Int32_create(1, 0, 1));
		}
		else if(layout.size == 4)
		{
			newNode = ILNode_Shl_create
				(node, ILNode_Int32_create(2, 0, 1));
		}
		else if(layout.size == 8)
		{
			newNode = ILNode_Shl_create
				(node, ILNode_Int32_create(3, 0, 1));
		}
		else
		{
			newNode = ILNode_Mul_create
				(node, ILNode_UInt32_create((ILUInt64)layout.size, 0, 1));
		}
	}
	else
	{
		/* The size is dynamic: check for the simple 0 case */
		if(evalValue && IsSmallIntegerMachineType(evalValue->valueType))
		{
			if(evalValue->un.i4Value == 0)
			{
				newNode = ILNode_Int_create(0, 0, 0);
				CGenCloneLine(newNode, node);
				return newNode;
			}
		}
		newNode = ILNode_Mul_create(node, ILNode_SizeOfType_create(elemType));
	}
	CGenCloneLine(newNode, node);
	return newNode;
}

/*
 * Divide a pointer difference by an element size.
 */
static ILNode *DivPtrSize(ILNode *node, ILType *elemType)
{
	ILNode *newNode;
	CTypeLayoutInfo layout;
	CTypeGetLayoutInfo(elemType, &layout);
	if(layout.category == C_TYPECAT_FIXED)
	{
		if(layout.size == 1)
		{
			return node;
		}
		else if(layout.size == 2)
		{
			newNode = ILNode_Shr_create
				(node, ILNode_Int32_create(1, 0, 1));
		}
		else if(layout.size == 4)
		{
			newNode = ILNode_Shr_create
				(node, ILNode_Int32_create(2, 0, 1));
		}
		else if(layout.size == 8)
		{
			newNode = ILNode_Shr_create
				(node, ILNode_Int32_create(3, 0, 1));
		}
		else
		{
			newNode = ILNode_Div_create
				(node, ILNode_Int_create((ILInt64)(layout.size), 0, 1));
		}
	}
	else
	{
		newNode = ILNode_Div_create(node, ILNode_SizeOfType_create(elemType));
	}
	CGenCloneLine(newNode, node);
	return newNode;
}

/*
 * Determine a common type for binary operators.
 */
static ILMachineType CommonBinaryType(ILGenInfo *info,
									  ILMachineType type1,
									  ILMachineType type2)
{
	ILMachineType common;

	/* Determine a common type using the codegen inference algorithm */
	common = ILCommonType(info, type1, type2, 0);

	/* Widen the common type to the natural type for the operation */
	switch(common)
	{
		case ILMachineType_Boolean:
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		{
			common = ILMachineType_Int32;
		}
		break;

		case ILMachineType_Float32:
		{
			common = ILMachineType_Float64;
		}
		break;

		default: break;
	}

	/* Return the common type to the caller */
	return common;
}

/*
 * Binary operator kinds.
 */
#define	C_BINARY_ADD		0
#define	C_BINARY_SUB		1
#define	C_BINARY_REM		2
#define	C_BINARY_NUMERIC	3
#define	C_BINARY_BITWISE	4
#define	C_BINARY_SHIFT		5

/*
 * Perform semantic analysis for a binary operator.
 */
static CSemValue BinarySem(ILGenInfo *info, ILNode_BinaryExpression *node,
						   ILNode **parent, int stmtLevel,
						   const char *name, int opkind)
{
	CSemValue value1;
	CSemValue value2;
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType common1;
	ILMachineType common2;
	ILNode *temp;
	ILType *elemType;
	ILType *elemType2;
	ILType *finalType = ILType_Invalid;
	ILEvalValue evalValue;

	/* Perform semantic analysis on the two arguments, and
	   check that they are both r-values */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), stmtLevel);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), 0);
	if(!CSemIsRValue(value1) || !CSemIsRValue(value2))
	{
		/* Pass error conditions up, but otherwise ignore the problem.
		   We've already reported the error at the lower level */
		if(CSemIsError(value1) || CSemIsError(value2))
		{
			return CSemValueError;
		}
		goto invalid;
	}

	/* Find a common type to use for the operation */
	type1 = ILTypeToMachineType(CSemGetType(value1));
	type2 = ILTypeToMachineType(CSemGetType(value2));
	if(opkind == C_BINARY_SHIFT)
	{
		/* Shift operator that can only support integer operands */
		if(IsIntegerMachineType(type1) && IsIntegerMachineType(type2))
		{
			common1 = CommonBinaryType(info, type1, type1);
			common2 = ILMachineType_Int32;
		}
		else
		{
			goto invalid;
		}
	}
	else if(opkind == C_BINARY_BITWISE || opkind == C_BINARY_REM)
	{
		/* Operator that can only support integer operands */
		if(IsIntegerMachineType(type1) && IsIntegerMachineType(type2))
		{
			common1 = common2 = CommonBinaryType(info, type1, type2);
		}
		else
		{
			goto invalid;
		}
	}
	else
	{
		/* The operator can support all numeric operands */
		if(IsNumericMachineType(type1) && IsNumericMachineType(type2))
		{
			common1 = common2 = CommonBinaryType(info, type1, type2);
		}
		else if(opkind == C_BINARY_ADD)
		{
			if(type1 == ILMachineType_UnmanagedPtr &&
			   IsIntegerMachineType(type2))
			{
				/* Add pointer and integer */
				elemType = CTypeGetPtrRef(CSemGetType(value1));
				node->expr2 = MulPtrSize(node->expr2, value2, elemType);
				if(IsSignedMachineType(type2))
				{
					common1 = common2 = ILMachineType_NativeInt;
				}
				else
				{
					common1 = common2 = ILMachineType_NativeUInt;
				}
				finalType = CSemGetType(value1);
			}
			else if(type2 == ILMachineType_UnmanagedPtr &&
			        IsIntegerMachineType(type1))
			{
				/* Add integer and pointer */
				elemType = CTypeGetPtrRef(CSemGetType(value2));
				node->expr1 = MulPtrSize(node->expr1, value1, elemType);
				if(IsSignedMachineType(type1))
				{
					common1 = common2 = ILMachineType_NativeInt;
				}
				else
				{
					common1 = common2 = ILMachineType_NativeUInt;
				}
				finalType = CSemGetType(value2);
			}
			else
			{
				goto invalid;
			}
		}
		else if(opkind == C_BINARY_SUB)
		{
			if(type1 == ILMachineType_UnmanagedPtr &&
			   IsIntegerMachineType(type2))
			{
				/* Subtract pointer and integer */
				elemType = CTypeGetPtrRef(CSemGetType(value1));
				node->expr2 = MulPtrSize(node->expr2, value2, elemType);
				if(IsSignedMachineType(type2))
				{
					common1 = common2 = ILMachineType_NativeInt;
				}
				else
				{
					common1 = common2 = ILMachineType_NativeUInt;
				}
				finalType = CSemGetType(value1);
			}
			else if(type1 == ILMachineType_UnmanagedPtr &&
			        type2 == ILMachineType_UnmanagedPtr)
			{
				/* Subtract pointer and pointer */
				elemType = ILTypeStripPrefixes
					(CTypeGetPtrRef(CSemGetType(value1)));
				elemType2 = ILTypeStripPrefixes
					(CTypeGetPtrRef(CSemGetType(value2)));
				if(!CTypeIsIdentical(elemType, elemType2))
				{
					goto invalid;
				}
				temp = ILNode_CastSimple_create
					(node->expr1, ILMachineType_NativeInt);
				CGenCloneLine(temp, node->expr1);
				node->expr1 = temp;
				temp = ILNode_CastSimple_create
					(node->expr2, ILMachineType_NativeInt);
				CGenCloneLine(temp, node->expr2);
				node->expr2 = temp;
				*parent = DivPtrSize((ILNode *)node, elemType);
				*parent = ILNode_CastSimple_create
					(*parent, ILMachineType_NativeInt);
				CGenCloneLine(*parent, (ILNode *)node);
				CSemSetRValue(value1, ILType_Int);
				return value1;
			}
			else
			{
				goto invalid;
			}
		}
		else
		{
			goto invalid;
		}
	}

	/* Cast the arguments to their final types */
	if(common1 != type1)
	{
		temp = ILNode_CastSimple_create(node->expr1, common1);
		CGenCloneLine(temp, node->expr1);
		node->expr1 = temp;
	}
	if(common2 != type2)
	{
		temp = ILNode_CastSimple_create(node->expr2, common2);
		CGenCloneLine(temp, node->expr2);
		node->expr2 = temp;
	}
	if(finalType == ILType_Invalid)
	{
		/* Simple numeric calculation */
		finalType = ILValueTypeToType(info, common1);
		CSemSetRValue(value1, finalType);
	}
	else
	{
		/* Pointer calculation */
		*parent = ILNode_CastSimple_create
			((ILNode *)node, ILMachineType_UnmanagedPtr);
		CSemSetRValue(value1, finalType);
	}

	/* Attempt to perform constant evaluation on the entire expression */
	if(ILNode_EvalConst(*parent, info, &evalValue))
	{
		*parent = CreateConstantNode((ILNode *)node, *parent, &evalValue);
		CSemSetConstant(value1, finalType, evalValue);
	}

	/* Return the type of the entire expression */
	return value1;

	/* Report an invalid operands error and bail out */
invalid:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operands to binary `%s'"), name);
	return CSemValueError;
}

/*
 * Perform semantic analysis for binary operator assignment.
 */
static CSemValue AssignSem(ILGenInfo *info, ILNode *anode,
						   ILNode_BinaryExpression *node,
						   ILNode **parent, const char *name, int opkind)
{
	CSemValue value1;
	CSemValue value2;
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType common1;
	ILMachineType common2;
	ILNode *temp;
	ILType *elemType;

	/* Perform semantic analysis on the two arguments, and check
	   that the first is an l-value and second an r-value */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), 0);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), 0);
	if(!CSemIsLValue(value1))
	{
		if(!CSemIsError(value1))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid lvalue in assignment"));
		}
		if(!CSemIsRValue(value2) && !CSemIsError(value2))
		{
			goto invalid;
		}
		return CSemValueError;
	}
	if(!CSemIsRValue(value2))
	{
		/* Pass error conditions up, but otherwise ignore the problem.
		   We've already reported the error at the lower level */
		if(CSemIsError(value2))
		{
			return CSemValueError;
		}
		goto invalid;
	}

	/* Find a common type to use for the operation */
	type1 = ILTypeToMachineType(CSemGetType(value1));
	type2 = ILTypeToMachineType(CSemGetType(value2));
	if(opkind == C_BINARY_SHIFT)
	{
		/* Shift operator that can only support integer operands */
		if(IsIntegerMachineType(type1) && IsIntegerMachineType(type2))
		{
			common1 = CommonBinaryType(info, type1, type1);
			common2 = ILMachineType_Int32;
		}
		else
		{
			goto invalid;
		}
	}
	else if(opkind == C_BINARY_BITWISE || opkind == C_BINARY_REM)
	{
		/* Operator that can only support integer operands */
		if(IsIntegerMachineType(type1) && IsIntegerMachineType(type2))
		{
			common1 = common2 = CommonBinaryType(info, type1, type2);
		}
		else
		{
			goto invalid;
		}
	}
	else
	{
		/* The operator can support all numeric operands */
		if(IsNumericMachineType(type1) && IsNumericMachineType(type2))
		{
			common1 = common2 = CommonBinaryType(info, type1, type2);
		}
		else if(opkind == C_BINARY_ADD)
		{
			if(type1 == ILMachineType_UnmanagedPtr &&
			   IsIntegerMachineType(type2))
			{
				/* Add pointer and integer */
				elemType = CTypeGetPtrRef(CSemGetType(value1));
				node->expr2 = MulPtrSize(node->expr2, value2, elemType);
				if(IsSignedMachineType(type2))
				{
					common2 = ILMachineType_NativeInt;
				}
				else
				{
					common2 = ILMachineType_NativeUInt;
				}
				common1 = type1;
			}
			else
			{
				goto invalid;
			}
		}
		else if(opkind == C_BINARY_SUB)
		{
			if(type1 == ILMachineType_UnmanagedPtr &&
			   IsIntegerMachineType(type2))
			{
				/* Subtract pointer and integer */
				elemType = CTypeGetPtrRef(CSemGetType(value1));
				node->expr2 = MulPtrSize(node->expr2, value2, elemType);
				if(IsSignedMachineType(type2))
				{
					common2 = ILMachineType_NativeInt;
				}
				else
				{
					common2 = ILMachineType_NativeUInt;
				}
				common1 = type1;
			}
			else
			{
				goto invalid;
			}
		}
		else
		{
			goto invalid;
		}
	}

	/* Re-arrange the node a little for the code generator */
	((ILNode_AssignExpression *)anode)->lvalue = node->expr1;
	temp = ILNode_EmptyExpr_create(type1);
	CGenCloneLine(temp, node->expr1);
	node->expr1 = temp;

	/* Cast the arguments to their final types and return */
	if(common1 != type1)
	{
		temp = ILNode_CastSimple_create(node->expr1, common1);
		CGenCloneLine(temp, node->expr1);
		node->expr1 = temp;
	}
	if(common2 != type2)
	{
		temp = ILNode_CastSimple_create(node->expr2, common2);
		CGenCloneLine(temp, node->expr2);
		node->expr2 = temp;
	}
	CSemSetRValue(value1, CSemGetType(value1));
	return value1;

	/* Report an invalid operands error and bail out */
invalid:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operands to binary `%s'"), name);
	return CSemValueError;
}

/*
 * Perform semantic analysis for increment or decrement expressions.
 */
static CSemValue IncOrDecSem(ILGenInfo *info, ILNode_UnaryExpression *node,
						     ILNode **parent, const char *name)
{
	CSemValue value;
	ILMachineType type;
	ILType *elemType;
	ILNode *newNode;
	CTypeLayoutInfo layout;
	ILNode *sizeNode;

	/* Perform semantic analysis on the l-value argument */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), 0);
	if(!CSemIsLValue(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid lvalue in %s"), name);
		}
		return CSemValueError;
	}

	/* Check that the type is incrementable or decrementale */
	type = ILTypeToMachineType(CSemGetType(value));
	switch(type)
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
		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		case ILMachineType_Float32:
		case ILMachineType_Float64:
		case ILMachineType_NativeFloat:		break;

		case ILMachineType_UnmanagedPtr:
		{
			elemType = CTypeGetPtrRef(CSemGetType(value));
			CTypeGetLayoutInfo(elemType, &layout);
			if(layout.category == C_TYPECAT_FIXED)
			{
				sizeNode = 0;
			}
			else
			{
				sizeNode = ILNode_SizeOfType_create(elemType);
			}
			if(yyisa(node, ILNode_PreInc))
			{
				newNode = ILNode_PreIncPtr_create
					(node->expr, layout.size, sizeNode);
			}
			else if(yyisa(node, ILNode_PreDec))
			{
				newNode = ILNode_PreDecPtr_create
					(node->expr, layout.size, sizeNode);
			}
			else if(yyisa(node, ILNode_PostInc))
			{
				newNode = ILNode_PostIncPtr_create
					(node->expr, layout.size, sizeNode);
			}
			else
			{
				newNode = ILNode_PostDecPtr_create
					(node->expr, layout.size, sizeNode);
			}
			CGenCloneLine(newNode, (ILNode *)node);
			*parent = newNode;
		}
		break;

		default:
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("wrong type argument to %s"), name);
			return CSemValueError;
		}
		/* Not reached */
	}

	/* Convert the l-value into and r-value and return */
	CSemSetRValue(value, CSemGetType(value));
	return value;
}

/*
 * Perform semantic analysis for a relational operator.
 */
static CSemValue RelationalSem(ILGenInfo *info, ILNode_BinaryExpression *node,
						       ILNode **parent, int stmtLevel,
						       const char *name)
{
	CSemValue value1;
	CSemValue value2;
	ILMachineType type1;
	ILMachineType type2;
	ILMachineType common;
	ILType *elemType;
	ILType *elemType2;
	ILNode *temp;
	ILEvalValue evalValue;

	/* Perform semantic analysis on the two arguments, and
	   check that they are both r-values */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), stmtLevel);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), 0);
	if(!CSemIsRValue(value1) || !CSemIsRValue(value2))
	{
		/* Pass error conditions up, but otherwise ignore the problem.
		   We've already reported the error at the lower level */
		if(CSemIsError(value1) || CSemIsError(value2))
		{
			return CSemValueBool;
		}
		goto invalid;
	}

	/* Find a common type to use for the operation */
	type1 = ILTypeToMachineType(CSemGetType(value1));
	if(type1 == ILMachineType_String)
	{
		type1 = ILMachineType_ObjectRef;
	}
	type2 = ILTypeToMachineType(CSemGetType(value2));
	if(type2 == ILMachineType_String)
	{
		type2 = ILMachineType_ObjectRef;
	}
	if(IsNumericMachineType(type1) && IsNumericMachineType(type2))
	{
		/* Compare numeric values */
		common = CommonBinaryType(info, type1, type2);
	}
	else if(type1 == ILMachineType_UnmanagedPtr &&
			type2 == ILMachineType_UnmanagedPtr)
	{
		/* Compare pointer values */
		elemType = ILTypeStripPrefixes(CTypeGetPtrRef(CSemGetType(value1)));
		elemType2 = ILTypeStripPrefixes(CTypeGetPtrRef(CSemGetType(value2)));
		if(elemType != ILType_Void && elemType2 != ILType_Void &&
		   !ILTypeIdentical(elemType, elemType2))
		{
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
				_("comparison of distinct pointer types lacks a cast"));
		}
		common = ILMachineType_UnmanagedPtr;
	}
	else if(type1 == ILMachineType_UnmanagedPtr && IsIntegerMachineType(type2))
	{
		/* Compare pointer and integer */
		if(CSemIsZero(value2))
		{
			if(yyisa(node, ILNode_Eq))
			{
				temp = ILNode_IsNull_create(node->expr1);
				CGenCloneLine(temp, node->expr1);
				*parent = temp;
				return CSemValueBool;
			}
			else if(yyisa(node, ILNode_Ne))
			{
				temp = ILNode_IsNonNull_create(node->expr1);
				CGenCloneLine(temp, node->expr1);
				*parent = temp;
				return CSemValueBool;
			}
		}
		else
		{
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
				_("comparison between pointer and integer"));
		}
		if(IsSignedMachineType(type2))
		{
			common = ILMachineType_NativeInt;
		}
		else
		{
			common = ILMachineType_NativeUInt;
		}
	}
	else if(IsIntegerMachineType(type1) && type2 == ILMachineType_UnmanagedPtr)
	{
		/* Compare integer and pointer */
		if(CSemIsZero(value1))
		{
			if(yyisa(node, ILNode_Eq))
			{
				temp = ILNode_IsNull_create(node->expr2);
				CGenCloneLine(temp, node->expr2);
				*parent = temp;
				return CSemValueBool;
			}
			else if(yyisa(node, ILNode_Ne))
			{
				temp = ILNode_IsNonNull_create(node->expr2);
				CGenCloneLine(temp, node->expr2);
				*parent = temp;
				return CSemValueBool;
			}
		}
		else
		{
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
				_("comparison between pointer and integer"));
		}
		if(IsSignedMachineType(type1))
		{
			common = ILMachineType_NativeInt;
		}
		else
		{
			common = ILMachineType_NativeUInt;
		}
	}
	else if(type1 == ILMachineType_ObjectRef &&
			type2 == ILMachineType_ObjectRef)
	{
		/* Compare two object references */
		if(yyisa(node, ILNode_Eq) || yyisa(node, ILNode_Ne))
		{
			return CSemValueBool;
		}
		goto invalid;
	}
	else if(type1 == ILMachineType_ObjectRef && IsIntegerMachineType(type2))
	{
		/* Compare object reference and integer */
		if(CSemIsZero(value2))
		{
			if(yyisa(node, ILNode_Eq))
			{
				temp = ILNode_IsNull_create(node->expr1);
				CGenCloneLine(temp, node->expr1);
				*parent = temp;
				return CSemValueBool;
			}
			else if(yyisa(node, ILNode_Ne))
			{
				temp = ILNode_IsNonNull_create(node->expr1);
				CGenCloneLine(temp, node->expr1);
				*parent = temp;
				return CSemValueBool;
			}
		}
		goto invalid;
	}
	else if(IsIntegerMachineType(type1) && type2 == ILMachineType_ObjectRef)
	{
		/* Compare integer and object reference */
		if(CSemIsZero(value1))
		{
			if(yyisa(node, ILNode_Eq))
			{
				temp = ILNode_IsNull_create(node->expr2);
				CGenCloneLine(temp, node->expr2);
				*parent = temp;
				return CSemValueBool;
			}
			else if(yyisa(node, ILNode_Ne))
			{
				temp = ILNode_IsNonNull_create(node->expr2);
				CGenCloneLine(temp, node->expr2);
				*parent = temp;
				return CSemValueBool;
			}
		}
		goto invalid;
	}
	else
	{
		goto invalid;
	}

	/* Cast the arguments to their final types */
	if(common != type1)
	{
		temp = ILNode_CastSimple_create(node->expr1, common);
		CGenCloneLine(temp, node->expr1);
		node->expr1 = temp;
	}
	if(common != type2)
	{
		temp = ILNode_CastSimple_create(node->expr2, common);
		CGenCloneLine(temp, node->expr2);
		node->expr2 = temp;
	}

	/* Attempt to perform constant evaluation on the entire expression */
	if(ILNode_EvalConst(*parent, info, &evalValue))
	{
		*parent = CreateConstantNode
			((ILNode *)node, (ILNode *)node, &evalValue);
		CSemSetConstant(value1, ILType_Boolean, evalValue);
		return value1;
	}

	/* Return the type of the entire expression */
	return CSemValueBool;

	/* Report an invalid operands error and bail out */
invalid:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operands to binary `%s'"), name);
	return CSemValueBool;
}

#line 2207 "c_oper.tc"


/*
 * Get the common type for a conditional operator.  Returns "ILType_Invalid"
 * if there is no common type.
 */
static ILType *CommonCondType(ILGenInfo *info, ILType *type1, ILType *type2)
{
	ILMachineType mtype1 = ILTypeToMachineType(type1);
	ILMachineType mtype2 = ILTypeToMachineType(type2);

	/* If one of the types is "void", then the result is also "void" */
	if(mtype1 == ILMachineType_Void ||
	   mtype2 == ILMachineType_Void)
	{
		return ILType_Void;
	}

	/* Check for numeric combinations */
	if(IsNumericMachineType(mtype1) && IsNumericMachineType(mtype2))
	{
		return ILValueTypeToType(info, CommonBinaryType(info, mtype1, mtype2));
	}

	/* Check for pointer combinations */
	if(CTypeIsPointer(type1) && CTypeIsPointer(type2))
	{
		return type1;
	}
	else if(CTypeIsFunctionPtr(type1) && CTypeIsFunctionPtr(type2))
	{
		return type1;
	}
	else if(CTypeIsPointer(type1) && IsIntegerMachineType(mtype2))
	{
		return type1;
	}
	else if(CTypeIsFunctionPtr(type1) && IsIntegerMachineType(mtype2))
	{
		return type1;
	}
	else if(CTypeIsPointer(type2) && IsIntegerMachineType(mtype1))
	{
		return type2;
	}
	else if(CTypeIsFunctionPtr(type2) && IsIntegerMachineType(mtype1))
	{
		return type2;
	}

	/* The types must be identical (e.g. for struct and union types) */
	if(CTypeIsIdentical(type1, type2))
	{
		return type1;
	}

	/* Could not determine a common type */
	return ILType_Invalid;
}

#line 21 "c_stmt.tc"


/*
 * Determine if a tree node corresponds to the empty statement.
 */
#define	IsEmpty(node) ((node) == 0 || yykind((node)) == yykindof(ILNode_Empty))

/*
 * Perform semantic analysis on a sub-statement.
 */
static CSemValue StmtSem(ILNode *node, ILGenInfo *info,
					     ILNode **parent, int stmtLevel)
{
	CSemValue value = CSemValueDefault;
	if(node)
	{
		value = ILNode_CSemAnalysis(node, info, parent, stmtLevel);
		if(!CSemIsVoid(value) && !CSemIsRValue(value) && !CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid statement"));
		}
	}
	return value;
}

/*
 * Statement context flags.
 */
#define	C_STMT_LOOP			1
#define	C_STMT_SWITCH		2
#define	C_STMT_TRY			4
#define	C_STMT_CATCH		8
#define	C_STMT_FINALLY		16

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

#line 423 "c_stmt.tc"


/*
 * Storage for the "goto" label list.
 */
typedef struct _tagCGenGoto CGenGoto;
struct _tagCGenGoto
{
	CGenGoto   *next;
	char	   *name;
	ILNode     *node;
	ILInt32		labelNum;
	int			defined : 1;
	int			used : 1;
};
static CGenGoto *gotoList = 0;
static ILInt32 gotoLabelNext = 1;

void CGenGotoDestroy(void)
{
	CGenGoto *label, *nextLabel;
	label = gotoList;
	while(label != 0)
	{
		nextLabel = label->next;
		if(!(label->defined))
		{
			CCErrorOnLine(yygetfilename(label->node),
						  yygetlinenum(label->node),
						  _("label `%s' used but not defined"), label->name);
		}
		else if(!(label->used))
		{
			CCWarningOnLine(yygetfilename(label->node),
							yygetlinenum(label->node),
						    _("label `%s' defined but not used"), label->name);
		}
		ILFree(label);
		label = nextLabel;
	}
	gotoList = 0;
	gotoLabelNext = 1;
}

void CGenGotoPtrLabels(ILGenInfo *info, ILLabel *defaultLabel)
{
	CGenGoto **labels;
	CGenGoto *current;
	ILInt32 posn, posn2, num;
	ILGotoEntry *entry;

	/* Collect up all labels */
	labels = (CGenGoto **)ILMalloc(sizeof(CGenGoto) * gotoLabelNext);
	if(!labels)
	{
		CCOutOfMemory();
	}
	current = gotoList;
	num = 0;
	while(current != 0)
	{
		labels[num++] = current;
		current = current->next;
	}

	/* Sort the labels on label number */
	for(posn = 0; posn < (num - 1); ++posn)
	{
		for(posn2 = posn + 1; posn2 < num; ++posn2)
		{
			if(labels[posn]->labelNum > labels[posn2]->labelNum)
			{
				current = labels[posn];
				labels[posn] = labels[posn2];
				labels[posn2] = current;
			}
		}
	}

	/* Output the labels in order */
	for(posn = 0; posn < num; ++posn)
	{
		entry = info->gotoList;
		while(entry != 0)
		{
			if(!strcmp(entry->name, labels[posn]->name))
			{
				break;
			}
			entry = entry->next;
		}
		if(entry)
		{
			ILGenSwitchRef(info, &(entry->label), (posn != (num - 1)));
		}
		else
		{
			ILGenSwitchRef(info, defaultLabel, (posn != (num - 1)));
		}
	}

	/* Clean up and exit */
	ILFree(labels);
}

#line 727 "c_stmt.tc"


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

		default: break;
	}
	return 0;
}

/*
 * Collect up all of the case labels for a "switch" statement,
 * and sort them into ascending order.  Returns the new size of
 * the case label list, after errors have been removed.
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
	CSemValue value;
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
				value = ILNode_CSemAnalysis(caseLabel->expr, info,
									        &(caseLabel->expr), 0);
				if(CSemIsError(value))
				{
					continue;
				}
				else if(CSemGetConstant(value) == 0 ||
				        !IsIntegerMachineType
							(CSemGetConstant(value)->valueType))
				{
					CCErrorOnLine(yygetfilename(caseLabel->expr),
								  yygetlinenum(caseLabel->expr),
								  "invalid case label expression");
					continue;
				}

				/* Coerce the case expression to the governing type */
				if(!CCanCoerceValue(value, switchType))
				{
					CCErrorOnLine(yygetfilename(caseLabel->expr),
								  yygetlinenum(caseLabel->expr),
								  "no conversion from `%s' to `%s'",
								  CTypeToName(info, CSemGetType(value)),
								  CTypeToName(info, switchType));
					continue;
				}
				CCoerceNode(info, caseLabel->expr, &(caseLabel->expr),
							value, switchType);
				ILGenCastConst(info, CSemGetConstant(value),
							   CSemGetConstant(value)->valueType,
							   switchMachineType);

				/* Record the case node information for later */
				values[size].value = *(CSemGetConstant(value));
				values[size].caseLabel = caseNode;
				values[size].section = section;
				++size;
			}
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

#line 2612 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_1__(ILNode_CDeclarator *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 2620 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_2__(ILNode_CSharpInvocation *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 660 "c_invoke.tc"
{
	ILClass *classInfo;
	ILType *signature;
	CEvalArg *argTypes;
	ILType **typeArray;
	ILUInt32 numArgs;
	ILUInt32 argNum;
	ILMethod *method;
	ILClass *callScope;
	CSemValue value;
	ILNode_InvocationExpression *invoke;

	/* Convert the type into its C# class */
	classInfo = ILTypeToClass(info, ILTypeStripPrefixes(node->type));

	/* Perform semantic analysis on the invocation arguments */
	numArgs = CountArgs(node->args);
	if(numArgs != 0)
	{
		argTypes = (CEvalArg *)ILMalloc(numArgs * sizeof(CEvalArg));
		if(!argTypes)
		{
			CCOutOfMemory();
		}
		typeArray = (ILType **)ILMalloc(numArgs * sizeof(ILType *));
		if(!typeArray)
		{
			CCOutOfMemory();
		}
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			ArgumentSem(info, &(argTypes[argNum]), node->args,
						&(node->args), argNum, numArgs);
			typeArray[argNum] = ILTypeStripPrefixes
				(CSemGetType(argTypes[argNum].value));
		}
	}
	else
	{
		argTypes = 0;
		typeArray = 0;
	}

	/* Resolve a static method that takes the supplied arguments */
	callScope = ILClassLookup(ILClassGlobalScope(info->image), "<Module>", 0);
	if(classInfo)
	{
		method = ResolveCSMethod(info, classInfo, callScope,
								 node->name, typeArray,
								 (int)numArgs, (node->thisExpr == 0));
	}
	else
	{
		method = 0;
	}
	if(!method)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("no candidate for method invocation"));
		if(argTypes)
		{
			ILFree(argTypes);
		}
		if(typeArray)
		{
			ILFree(typeArray);
		}
		return CSemValueError;
	}

	/* Coerce the arguments to the method's actual parameter types */
	signature = ILMethod_Signature(method);
	for(argNum = 0; argNum < numArgs; ++argNum)
	{
		CCoerceNode(info, argTypes[argNum].node,
					argTypes[argNum].parent, argTypes[argNum].value,
				    ILTypeGetParam(signature, argNum + 1));
	}

	/* Build the new method invocation node for the code generator */
	invoke = (ILNode_InvocationExpression *)
		ILNode_InvocationExpression_create(0, node->args);
	CGenCloneLine((ILNode *)invoke, (ILNode *)node);
	invoke->thisExpr = node->thisExpr;
	invoke->methodInfo = method;
	invoke->callSiteSig = 0;
	*parent = (ILNode *)invoke;

	/* Clean up the memory that we used */
	if(argTypes)
	{
		ILFree(argTypes);
	}
	if(typeArray)
	{
		ILFree(typeArray);
	}

	/* Construct the r-value for the method's return type */
	signature = ILTypeGetReturnWithPrefixes(signature);
	if(ILTypeIdentical(signature, ILType_Void))
	{
		return CSemValueDefault;
	}
	else
	{
		CSemSetRValue(value, signature);
		return value;
	}
}
#line 2734 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_3__(ILNode_CAttribute *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 2742 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_4__(ILNode_CAttributeValue *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 2750 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_5__(ILNode_Null *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 49 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_ObjectRef;
	evalValue.un.oValue = 0;
	CSemSetConstant(value, ILType_Null, evalValue);
	return value;
}
#line 2762 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_6__(ILNode_NullPtr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 62 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UnmanagedPtr;
	evalValue.un.i4Value = 0;
	CSemSetConstant(value, CTypeCreateVoidPtr(info), evalValue);
	return value;
}
#line 2774 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_7__(ILNode_True *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 75 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Boolean;
	evalValue.un.i4Value = 1;
	CSemSetConstant(value, ILType_Boolean, evalValue);
	return value;
}
#line 2786 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_8__(ILNode_False *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 88 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Boolean;
	evalValue.un.i4Value = 0;
	CSemSetConstant(value, ILType_Boolean, evalValue);
	return value;
}
#line 2798 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_9__(ILNode_Int8 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 101 "c_const.tc"
{
	CSemValue value;
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
	CSemSetConstant(value, ILType_Int8, evalValue);
	return value;
}
#line 2817 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_10__(ILNode_UInt8 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 121 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt8;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSemSetConstant(value, ILType_UInt8, evalValue);
	return value;
}
#line 2829 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_11__(ILNode_Int16 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 134 "c_const.tc"
{
	CSemValue value;
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
	CSemSetConstant(value, ILType_Int16, evalValue);
	return value;
}
#line 2848 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_12__(ILNode_UInt16 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 154 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt16;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSemSetConstant(value, ILType_UInt16, evalValue);
	return value;
}
#line 2860 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_13__(ILNode_Char *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 167 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Char;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSemSetConstant(value, ILType_Char, evalValue);
	return value;
}
#line 2872 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_14__(ILNode_Int32 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 180 "c_const.tc"
{
	CSemValue value;
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
	CSemSetConstant(value, ILType_Int32, evalValue);
	return value;
}
#line 2891 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_15__(ILNode_UInt32 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 200 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt32;
	evalValue.un.i4Value = (ILInt32)(node->value);
	CSemSetConstant(value, ILType_UInt32, evalValue);
	return value;
}
#line 2903 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_16__(ILNode_Int64 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 213 "c_const.tc"
{
	CSemValue value;
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
	CSemSetConstant(value, ILType_Int64, evalValue);
	return value;
}
#line 2922 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_17__(ILNode_UInt64 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 233 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_UInt64;
	evalValue.un.i8Value = (ILInt64)(node->value);
	CSemSetConstant(value, ILType_UInt64, evalValue);
	return value;
}
#line 2934 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_18__(ILNode_Int *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 246 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	ILType *type;
	if(node->isneg)
	{
		if(node->value > (((ILUInt64)IL_MAX_INT32) + 1))
		{
			/* The value may be too big for native integers
			   on a 32-bit platform, so convert into int64 */
			evalValue.valueType = ILMachineType_Int64;
			evalValue.un.i8Value = -((ILInt64)(node->value));
			type = ILType_Int64;
		}
		else
		{
			evalValue.valueType = ILMachineType_NativeInt;
			evalValue.un.i4Value = -((ILInt32)(node->value));
			type = ILType_Int;
		}
	}
	else
	{
		if(node->value > (ILUInt64)IL_MAX_INT32)
		{
			/* The value may be too big for native integers
			   on a 32-bit platform, so convert into int64 */
			evalValue.valueType = ILMachineType_Int64;
			evalValue.un.i8Value = (ILInt64)(node->value);
			type = ILType_Int64;
		}
		else
		{
			evalValue.valueType = ILMachineType_NativeInt;
			evalValue.un.i4Value = (ILInt32)(node->value);
			type = ILType_Int;
		}
	}
	CSemSetConstant(value, type, evalValue);
	return value;
}
#line 2979 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_19__(ILNode_UInt *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 292 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	ILType *type;
	if(node->value > (ILUInt64)IL_MAX_UINT32)
	{
		/* The value may be too big for native integers
		   on a 32-bit platform, so convert into uint64 */
		evalValue.valueType = ILMachineType_UInt64;
		evalValue.un.i8Value = (ILInt64)(node->value);
		type = ILType_UInt64;
	}
	else
	{
		evalValue.valueType = ILMachineType_NativeInt;
		evalValue.un.i4Value = (ILInt32)(node->value);
		type = ILType_UInt;
	}
	CSemSetConstant(value, type, evalValue);
	return value;
}
#line 3004 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_20__(ILNode_Float32 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 318 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Float32;
	evalValue.un.r4Value = (ILFloat)(node->value);
	CSemSetConstant(value, ILType_Float32, evalValue);
	return value;
}
#line 3016 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_21__(ILNode_Float64 *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 331 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_Float64;
	evalValue.un.r8Value = node->value;
	CSemSetConstant(value, ILType_Float64, evalValue);
	return value;
}
#line 3028 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_22__(ILNode_Float *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 344 "c_const.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	evalValue.valueType = ILMachineType_NativeFloat;
	evalValue.un.r8Value = node->value;
	CSemSetConstant(value, ILType_Float, evalValue);
	return value;
}
#line 3040 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_23__(ILNode_Decimal *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 357 "c_const.tc"
{
	/* Decimal constants are not used in C */
	return CSemValueDefault;
}
#line 3048 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_24__(ILNode_CString *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 376 "c_const.tc"
{
	CSemValue value;
	CSemSetDynConstant(value, CTypeCreateCharPtr(info));
	return value;
}
#line 3057 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_25__(ILNode_CWString *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 420 "c_const.tc"
{
	CSemValue value;
	CSemSetDynConstant(value, CTypeCreateWCharPtr(info));
	return value;
}
#line 3066 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_26__(ILNode_String *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 366 "c_const.tc"
{
	CSemValue value;
	CSemSetDynConstant(value, ILFindSystemType(info, "String"));
	return value;
}
#line 3075 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_27__(ILNode_Deref *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3083 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_28__(ILNode_StaticProperty *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3091 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_29__(ILNode_MemberProperty *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3099 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_30__(ILNode_IndexerAccess *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3107 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_31__(ILNode_CBitField *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3115 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_32__(ILNode_AsIs *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2013 "c_oper.tc"
{
	return ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
}
#line 3122 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_33__(ILNode_Overflow *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2021 "c_oper.tc"
{
	CSemValue value;
	int overflow = info->overflowInsns;
	int changed = info->overflowChanged;
	info->overflowInsns = 1;
	info->overflowChanged = 1;
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	info->overflowInsns = overflow;
	info->overflowChanged = changed;
	return value;
}
#line 3137 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_34__(ILNode_NoOverflow *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2037 "c_oper.tc"
{
	CSemValue value;
	int overflow = info->overflowInsns;
	int changed = info->overflowChanged;
	info->overflowInsns = 0;
	info->overflowChanged = 1;
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	info->overflowInsns = overflow;
	info->overflowChanged = changed;
	return value;
}
#line 3152 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_35__(ILNode_Pedantic *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2013 "c_oper.tc"
{
	return ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
}
#line 3159 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_36__(ILNode_NoPedantic *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2013 "c_oper.tc"
{
	return ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
}
#line 3166 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_37__(ILNode_BaseAccess *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3174 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_38__(ILNode_BaseElement *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3182 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_39__(ILNode_MemberAccess *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3190 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_40__(ILNode_DerefField *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3198 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_41__(ILNode_This *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3206 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_42__(ILNode_LocalVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1019 "c_lvalue.tc"
{
	/* These node types aren't used by the grammar */
	return CSemValueError;
}
#line 3214 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_43__(ILNode_ArgumentVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1019 "c_lvalue.tc"
{
	/* These node types aren't used by the grammar */
	return CSemValueError;
}
#line 3222 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_44__(ILNode_RefArgumentVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1398 "c_lvalue.tc"
{
	CSemValue value;
	if(CTypeIsConst(node->type))
	{
		/* The reference points to a "const" value, which makes it read-only */
		CSemSetRValue(value, node->type);
	}
	else
	{
		CSemSetLValue(value, node->type);
	}
	return value;
}
#line 3239 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_45__(ILNode_StaticField *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3247 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_46__(ILNode_MemberField *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3255 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_47__(ILNode_CArrayAccess *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1644 "c_lvalue.tc"
{
	CSemValue value1;
	CSemValue value2;
	CSemValue tempValue;
	ILNode *tempNode;
	ILType *rawElemType;
	ILType *elemType;

	/* Perform semantic analysis on the two values.  We deliberately
	   turn off "stmtLevel" processing, because we don't know if we
	   may need to swap the values below.  This only affects "setjmp"
	   and "alloca", which probably won't be present here anyway */
	value1 = ILNode_CSemAnalysis(node->array, info, &(node->array), 0);
	value2 = ILNode_CSemAnalysis(node->indices, info, &(node->indices), 0);

	/* Swap the values if the second is the pointer.  We need to do
	   this to support code of the form "3[p]", which is legal ANSI C,
	   but not necessarily a very smart coding convention */
	if(CSemIsRValue(value1) && CSemIsRValue(value2) &&
	   !CTypeIsPointer(CSemGetType(value1)) &&
	   CTypeIsPointer(CSemGetType(value2)))
	{
		tempValue = value1;
		value1 = value2;
		value2 = tempValue;
		tempNode = node->array;
		node->array = node->indices;
		node->indices = tempNode;
	}

	/* Validate the arguments to the array access operator */
	
	/* Handle managed arrays first off */
	if(CSemIsRValue(value1) && ILType_IsSimpleArray(CSemGetType(value1))
		&& CSemIsRValue(value2) && CTypeIsInteger(CSemGetType(value2)))
	{
		elemType = ILType_ElemType(CSemGetType(value1));
		*parent = ILNode_ArrayAccess_create(node->array, node->indices); 
		((ILNode_ArrayAccess*)(*parent))->arrayType = CSemGetType(value1);
		((ILNode_ArrayAccess*)(*parent))->elemType = elemType;
		
		if(CSemIsLValue(value1))
		{
			CSemSetLValue(value1, elemType);
		}
		else
		{
			// could have been a read only array
			CSemSetRValue(value1, elemType);
		}
		return value1;
	}
	
	if(!CSemIsRValue(value1) || !CTypeIsPointer(CSemGetType(value1)))
	{
		if(!CSemIsError(value1))
		{
			CCErrorOnLine(yygetfilename(node->array),
						  yygetlinenum(node->array),
						  _("subscripted value is neither array nor pointer"));
		}
		elemType = 0;
		rawElemType = 0;
	}
	else
	{
		rawElemType = CTypeGetPtrRef(CSemGetType(value1));
		elemType = CTypeDecay(info, rawElemType);
		if(ILTypeStripPrefixes(elemType) == ILType_Void)
		{
			CCErrorOnLine(yygetfilename(node->array),
						  yygetlinenum(node->array),
						  _("dereferencing `void *' pointer"));
		}
	}
	if(!CSemIsRValue(value2) || !CTypeIsInteger(CSemGetType(value2)))
	{
		if(!CSemIsError(value2))
		{
			CCErrorOnLine(yygetfilename(node->indices),
						  yygetlinenum(node->indices),
						  _("array subscript is not an integer"));
		}
	}

	/* Set the type values in the node, for use by the code generators */
	node->arrayType = CSemGetType(value1);
	node->elemType = elemType;

	/* Determine the final semantic value to return */
	if(elemType)
	{
		if(elemType == rawElemType)
		{
			/* Non-array element type, which is an l-value */
			CSemSetLValue(value1, elemType);
		}
		else
		{
			/* The array element decays into a pointer, which is an r-value */
			CSemSetDecayedRValue(value1, elemType, rawElemType);
		}
		return value1;
	}
	else
	{
		return CSemValueError;
	}
}
#line 3368 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_48__(ILNode_ArrayAccess *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 3376 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_49__(ILNode_CLocalVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1038 "c_lvalue.tc"
{
	CSemValue value;
	if(node->type != node->decayedType)
	{
		/* This is an array that decays to an r-value pointer */
		CSemSetDecayedRValue(value, node->decayedType, node->type);
	}
	else
	{
		/* This type doesn't decay, so it is an l-value */
		CSemSetLValue(value, node->type);
	}
	return value;
}
#line 3394 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_50__(ILNode_CArgumentVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1227 "c_lvalue.tc"
{
	CSemValue value;
	CSemSetLValue(value, node->type);
	return value;
}
#line 3403 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_51__(ILNode_CGlobalVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1429 "c_lvalue.tc"
{
	CSemValue value;
	if(node->type != node->decayedType)
	{
		/* This is an array that decays to an r-value pointer */
		CSemSetDecayedRValue(value, node->decayedType, node->type);
	}
	else
	{
		/* This type doesn't decay, so it is an l-value */
		CSemSetLValue(value, node->type);
	}
	return value;
}
#line 3421 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_52__(ILNode_CDerefField *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 909 "c_lvalue.tc"
{
	CSemValue value;
	CSemValue value2;
	ILType *type;
	ILType *structType;
	ILType *fieldType;
	ILField *field;
	ILUInt32 bitFieldStart;
	ILUInt32 bitFieldSize;

	/* Perform semantic analysis on the primary expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(!CSemIsError(value))
		{
			goto typeError;
		}
		return CSemValueError;
	}

	/* Make sure that the expression is a pointer to a structure or union */
	type = CSemGetType(value);
	if(CTypeIsReference(type))
	{
		/* Try to resolve the member using C# semantics */
		value2 = ResolveMember(info, ILTypeStripPrefixes(type), node->name, 0);
		if(!CSemIsError(value2))
		{
			return ConvertCSharpMember(info, node->expr, parent, value2);
		}
	}
	if(!CTypeIsPointer(type))
	{
		goto typeError;
	}
	structType = CTypeGetPtrRef(type);
	if(!CTypeIsStruct(structType) && !CTypeIsUnion(structType))
	{
		goto typeError;
	}

	/* Search for the field within the dereferenced struct type */
	field = CTypeLookupField(info, structType, node->name,
							 &bitFieldStart, &bitFieldSize);
	if(!field)
	{
		if(CTypeIsStruct(structType))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  			  _("structure has no member named `%s'"),
			  			  node->name);
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  			  _("union has no member named `%s'"),
			  			  node->name);
		}
		return CSemValueError;
	}

	/* Save the field for the code generator */
	node->field = field;
	node->ownerType = structType;

	/* Determine if the result is an l-value or an r-value */
	fieldType = ILMember_Signature(field);
	if(CTypeIsConst(structType))
	{
		/* Add back the "const" modifier from the struct type */
		fieldType = CTypeAddConst(info, fieldType);
	}
	if(CTypeIsVolatile(structType))
	{
		/* Add back the "volatile" modifier from the struct type */
		fieldType = CTypeAddVolatile(info, fieldType);
	}
	if(bitFieldSize != 0)
	{
		/* Replace this node with a bit field access node */
		*parent = ILNode_CBitField_create(node->expr, field,
										  ILTypeToMachineType(fieldType),
										  bitFieldStart, bitFieldSize, 0);
		CGenCloneLine(*parent, (ILNode *)node);
		CSemSetLValueNoRef(value, fieldType);
	}
	else if(CTypeIsArray(fieldType))
	{
		CSemSetDecayedRValue(value, CTypeDecay(info, fieldType), fieldType);
	}
	else
	{
		CSemSetLValue(value, fieldType);
	}
	return value;

	/* Report that the type is not consistent with the operation */
typeError:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  _("request for member `%s' in something not a structure or union"),
		  node->name);
	return CSemValueError;
}
#line 3529 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_53__(ILNode_CMemberField *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 111 "c_lvalue.tc"
{
	CSemValue value;
	ILType *type;
	ILType *fieldType;
	ILField *field;
	ILUInt32 bitFieldStart;
	ILUInt32 bitFieldSize;

	/* Perform semantic analysis on the primary expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(!CSemIsError(value))
		{
			goto typeError;
		}
		return CSemValueError;
	}

	/* Make sure that the expression is a structure or union */
	type = CSemGetType(value);
	if(!CTypeIsStruct(type) && !CTypeIsUnion(type))
	{
		if(CTypeIsReference(type))
		{
			/* Try to resolve the member using C# semantics */
			value = ResolveMember
				(info, ILTypeStripPrefixes(type), node->name, 0);
			if(!CSemIsError(value))
			{
				return ConvertCSharpMember(info, node->expr, parent, value);
			}
		}
		goto typeError;
	}

	/* Search for the field within the type */
	field = CTypeLookupField(info, type, node->name,
							 &bitFieldStart, &bitFieldSize);
	if(!field)
	{
		if(CTypeIsStruct(type))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  			  _("structure has no member named `%s'"),
			  			  node->name);
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  			  _("union has no member named `%s'"),
			  			  node->name);
		}
		return CSemValueError;
	}

	/* Save the owner type and the field for the code generator */
	node->ownerType = type;
	node->field = field;

	/* Determine if the result is an l-value or an r-value */
	fieldType = ILMember_Signature(field);
	if(CTypeIsConst(type))
	{
		/* Add back the "const" modifier from the struct type */
		fieldType = CTypeAddConst(info, fieldType);
	}
	if(CTypeIsVolatile(type))
	{
		/* Add back the "volatile" modifier from the struct type */
		fieldType = CTypeAddVolatile(info, fieldType);
	}
	if(bitFieldSize != 0)
	{
		/* Replace this node with a bit field access node */
		if(CSemIsLValue(value))
		{
			*parent = ILNode_CBitField_create(node->expr, field,
											  ILTypeToMachineType(fieldType),
											  bitFieldStart, bitFieldSize, 1);
			CSemSetLValueNoRef(value, fieldType);
		}
		else
		{
			*parent = ILNode_CBitField_create(node->expr, field,
											  ILTypeToMachineType(fieldType),
											  bitFieldStart, bitFieldSize, 0);
			CSemSetRValue(value, fieldType);
		}
		CGenCloneLine(*parent, (ILNode *)node);
	}
	else if(CTypeIsArray(fieldType))
	{
		if(!CSemIsLValue(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  			  _("invalid use of non-lvalue array"));
		}
		CSemSetDecayedRValue(value, CTypeDecay(info, fieldType), fieldType);
	}
	else
	{
		if(CSemIsLValue(value))
		{
			CSemSetLValue(value, fieldType);
		}
		else
		{
			CSemSetRValue(value, fieldType);
		}
	}
	return value;

	/* Report that the type is not consistent with the operation */
typeError:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
		  _("request for member `%s' in something not a structure or union"),
		  node->name);
	return CSemValueError;
}
#line 3653 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_54__(ILNode_CStaticField *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 698 "c_lvalue.tc"
{
	CSemValue value;
	CSemValue typeValue;
	ILType *type;
	ILProperty *property;

	/* Perform semantic analysis on the primary expression */
	typeValue = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsType(typeValue))
	{
		if(!CSemIsError(typeValue))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("type expected on left side of `::'"));
		}
		return CSemValueError;
	}

	/* Resolve the static member */
	value = ResolveMember(info, CSemGetType(typeValue), node->name, 1);
	if(CSemIsError(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`%s' has no static member named `%s'"),
					  CTypeToName(info, CSemGetType(typeValue)), node->name);
		return value;
	}

	/* Determine what to do based on the returned information */
	if(CSemIsType(value))
	{
		/* We've resolved a nested type */
		*parent = ILNode_CTypeExpression_create(CSemGetType(value));
		CGenCloneLine(*parent, (ILNode *)node);
	}
	else if(CSemIsField(value))
	{
		/* We've resolved a static field */
		node->field = CSemGetField(value);
		type = ILField_Type(node->field);
		if(CTypeIsArray(type))
		{
			/* Arrays decay immediately into r-values */
			CSemSetDecayedRValue(value, CTypeDecay(info, type), type);
		}
		else if(ILField_IsInitOnly(node->field))
		{
			/* Read-only fields cannot be l-values */
			CSemSetRValue(value, type);
		}
		else
		{
			/* Everything else must be an l-value field */
			CSemSetLValue(value, type);
		}
	}
	else if(CSemIsProperty(value))
	{
		/* We've resolved a static property */
		property = CSemGetProperty(value);
		type = ILTypeGetReturn(ILProperty_Signature(property));
		*parent = ILNode_StaticProperty_create(property);
		CGenCloneLine(*parent, (ILNode *)node);
		if(ILProperty_Getter(property))
		{
			if(ILProperty_Setter(property))
			{
				/* Read-write properties are l-values */
				CSemSetLValueNoRef(value, type);
			}
			else
			{
				/* Read-only properties are r-values */
				CSemSetRValue(value, type);
			}
		}
		else
		{
			/* Write-only properties are s-values */
			CSemSetSValue(value, type);
		}
	}

	/* Return the modified value to the caller */
	return value;
}
#line 3743 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_55__(ILNode_CDeref *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2122 "c_lvalue.tc"
{
	CSemValue value;
	ILType *type;
	ILType *decayed;

	/* Perform semantic analysis on the pointer value */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(CSemIsRValue(value) && CTypeIsFunctionPtr(CSemGetType(value)))
	{
		/* Remove the dereference from a function pointer expression */
		*parent = node->expr;
		return value;
	}
	if(!CSemIsRValue(value) || !CTypeIsPointer(CSemGetType(value)))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid argument to unary `*'"));
		}
		return CSemValueError;
	}

	/* Get the type of the pointed-to value, decaying array types if needed */
	type = CTypeGetPtrRef(CSemGetType(value));
	if(CTypeIsArray(type))
	{
		decayed = CTypeDecay(info, type);
		CSemSetDecayedRValue(value, decayed, type);
		type = decayed;
	}
	else
	{
		CSemSetLValue(value, type);
	}
	node->type = type;
	node->machineType = ILTypeToMachineType(type);
	return value;
}
#line 3786 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_56__(ILNode_LogicalNot *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 241 "c_oper.tc"
{
	CSemValue value;
	ILEvalValue *evalValue;
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if((evalValue = CSemGetConstant(value)) != 0 &&
	   ILGenCastConst(info, evalValue, evalValue->valueType,
	   				  ILMachineType_Boolean))
	{
		/* Replace this node with either "true" or "false" */
		*parent = CreateBoolConstant(node->expr, evalValue->un.i4Value);
		return CreateBoolValue(evalValue->un.i4Value);
	}
	return CSemValueBool;
}
#line 3804 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_57__(ILNode_Neg *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1362 "c_oper.tc"
{
	CSemValue value;
	ILMachineType type;
	ILMachineType common;
	ILNode *temp;
	ILEvalValue evalValue;

	/* Perform semantic analysis on the argument */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		/* Pass error conditions up, but otherwise ignore the problem.
		   We've already reported the error at the lower level */
		if(CSemIsError(value))
		{
			return CSemValueError;
		}
		goto invalid;
	}

	/* Find an appropriate numeric type to negate within */
	type = ILTypeToMachineType(CSemGetType(value));
	switch(type)
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
			common = ILMachineType_Int32;
		}
		break;

		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			common = ILMachineType_Int64;
		}
		break;

		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		{
			common = ILMachineType_NativeInt;
		}
		break;

		case ILMachineType_Float32:
		case ILMachineType_Float64:
		{
			common = ILMachineType_Float64;
		}
		break;

		case ILMachineType_NativeFloat:
		{
			common = ILMachineType_NativeFloat;
		}
		break;

		default: goto invalid;
	}

	/* Cast the argument to its final type */
	if(common != type)
	{
		temp = ILNode_CastSimple_create(node->expr, common);
		CGenCloneLine(temp, node->expr);
		node->expr = temp;
	}
	CSemSetRValue(value, ILValueTypeToType(info, common));

	/* Attempt to perform constant evaluation on the entire expression */
	if(ILNode_EvalConst(*parent, info, &evalValue))
	{
		*parent = CreateConstantNode((ILNode *)node, *parent, &evalValue);
		CSemSetConstant(value, CSemGetType(value), evalValue);
	}

	/* Return the final semantic value */
	return value;

	/* Report an invalid operands error and bail out */
invalid:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operand to unary `-'"));
	return CSemValueError;
}
#line 3900 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_58__(ILNode_UnaryPlus *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1459 "c_oper.tc"
{
	CSemValue value;
	ILMachineType type;
	ILMachineType common;
	ILNode *temp;
	ILEvalValue evalValue;

	/* Perform semantic analysis on the argument */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		/* Pass error conditions up, but otherwise ignore the problem.
		   We've already reported the error at the lower level */
		if(CSemIsError(value))
		{
			return CSemValueError;
		}
		goto invalid;
	}

	/* Find an appropriate numeric type to process with */
	type = ILTypeToMachineType(CSemGetType(value));
	switch(type)
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
			common = ILMachineType_Int32;
		}
		break;

		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			common = ILMachineType_Int64;
		}
		break;

		case ILMachineType_NativeInt:
		case ILMachineType_NativeUInt:
		{
			common = ILMachineType_NativeInt;
		}
		break;

		case ILMachineType_Float32:
		case ILMachineType_Float64:
		{
			common = ILMachineType_Float64;
		}
		break;

		case ILMachineType_NativeFloat:
		{
			common = ILMachineType_NativeFloat;
		}
		break;

		default: goto invalid;
	}

	/* Cast the argument to its final type */
	if(common != type)
	{
		temp = ILNode_CastSimple_create(node->expr, common);
		CGenCloneLine(temp, node->expr);
		node->expr = temp;
	}
	*parent = node->expr;
	CSemSetRValue(value, ILValueTypeToType(info, common));

	/* Attempt to perform constant evaluation on the entire expression */
	if(ILNode_EvalConst(*parent, info, &evalValue))
	{
		*parent = CreateConstantNode((ILNode *)node, *parent, &evalValue);
		CSemSetConstant(value, CSemGetType(value), evalValue);
	}

	/* Return the final semantic value */
	return value;

	/* Report an invalid operands error and bail out */
invalid:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operand to unary `+'"));
	return CSemValueError;
}
#line 3997 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_59__(ILNode_Not *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1584 "c_oper.tc"
{
	CSemValue value;
	ILMachineType type;
	ILMachineType common;
	ILNode *temp;
	ILEvalValue evalValue;

	/* Perform semantic analysis on the argument */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		/* Pass error conditions up, but otherwise ignore the problem.
		   We've already reported the error at the lower level */
		if(CSemIsError(value))
		{
			return CSemValueError;
		}
		goto invalid;
	}

	/* Find an appropriate numeric type to NOT within */
	type = ILTypeToMachineType(CSemGetType(value));
	switch(type)
	{
		case ILMachineType_Boolean:
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		{
			common = ILMachineType_Int32;
		}
		break;

		case ILMachineType_UInt32:
		{
			common = ILMachineType_UInt32;
		}
		break;

		case ILMachineType_Int64:
		{
			common = ILMachineType_Int64;
		}
		break;

		case ILMachineType_UInt64:
		{
			common = ILMachineType_UInt64;
		}
		break;

		case ILMachineType_NativeInt:
		{
			common = ILMachineType_NativeInt;
		}
		break;

		case ILMachineType_NativeUInt:
		{
			common = ILMachineType_NativeUInt;
		}
		break;

		default: goto invalid;
	}

	/* Cast the argument to its final type */
	if(common != type)
	{
		temp = ILNode_CastSimple_create(node->expr, common);
		CGenCloneLine(temp, node->expr);
		node->expr = temp;
	}
	CSemSetRValue(value, ILValueTypeToType(info, common));

	/* Attempt to perform constant evaluation on the entire expression */
	if(ILNode_EvalConst(*parent, info, &evalValue))
	{
		*parent = CreateConstantNode((ILNode *)node, *parent, &evalValue);
		CSemSetConstant(value, CSemGetType(value), evalValue);
	}

	/* Return the final semantic value */
	return value;

	/* Report an invalid operands error and bail out */
invalid:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operand to unary `~'"));
	return CSemValueError;
}
#line 4095 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_60__(ILNode_UserUnaryOp *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4103 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_61__(ILNode_PreInc *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1878 "c_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node,
					   parent, "increment");
}
#line 4111 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_62__(ILNode_PreDec *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1887 "c_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node,
					   parent, "decrement");
}
#line 4119 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_63__(ILNode_PostInc *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1896 "c_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node,
					   parent, "increment");
}
#line 4127 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_64__(ILNode_PostDec *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1905 "c_oper.tc"
{
	return IncOrDecSem(info, (ILNode_UnaryExpression *)node,
					   parent, "decrement");
}
#line 4135 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_65__(ILNode_UserPreInc *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4143 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_66__(ILNode_UserPreDec *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4151 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_67__(ILNode_UserPostInc *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4159 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_68__(ILNode_UserPostDec *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4167 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_69__(ILNode_UserIncOrDec *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4175 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_70__(ILNode_PreIncPtr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4183 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_71__(ILNode_PreDecPtr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4191 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_72__(ILNode_PostIncPtr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4199 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_73__(ILNode_PostDecPtr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4207 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_74__(ILNode_CastSimple *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2116 "c_oper.tc"
{
	/* This will never be called, as the grammar uses "CastType" instead */
	return CSemValueError;
}
#line 4215 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_75__(ILNode_CastType *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2125 "c_oper.tc"
{
	CSemValue value;

	/* Perform semantic analysis on the argument value */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);

	/* Bail out if not an r-value or a "void"-to-"void" cast */
	if(!CSemIsRValue(value) &&
	   (!CSemIsVoid(value) || node->type != ILType_Void))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid operand to cast expression"));
		}
		CSemSetRValue(value, node->type);
		return value;
	}

	/* It is always possible to cast to "void" */
	if(node->type == ILType_Void)
	{
		*parent = node->expr;
		return CSemValueDefault;
	}

	/* Can we coerce to the destination type? */
	if(!CCanCoerceValue(value, node->type))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  		  "no conversion from `%s' to `%s'",
					  CTypeToName(info, CSemGetType(value)),
					  CTypeToName(info, node->type));
		CSemSetRValue(value, node->type);
		return value;
	}

	/* Perform the cast and get the new semantic value.  We also copy the
	   expression node up one level to eliminate the ILNode_CastType node */
	*parent = node->expr;
	return CCastNode(info, node->expr, parent, value, node->type);
}
#line 4261 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_76__(ILNode_UserConversion *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4269 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_77__(ILNode_AddressOf *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2354 "c_oper.tc"
{
	CSemValue value;

	/* If the argument is a function reference, then remove this operator */
	if(yyisa(node->expr, ILNode_FunctionRef))
	{
		*parent = node->expr;
		return ILNode_CSemAnalysis(node->expr, info, parent, stmtLevel);
	}

	/* Perform semantic analysis on the argument */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(CSemIsDecayed(value))
	{
		/* The argument was an array that just decayed into a pointer.
		   Convert it into a pointer to the entire array */
		CSemSetRValue(value, CTypeCreatePointer
				(info, CSemGetDecayedType(value)));
		return value;
	}
	else if(!CSemIsLValue(value) || CSemIsNoRef(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid lvalue in unary `&'"));
		}
		return CSemValueError;
	}

	/* Build the final semantic value and return it */
	CSemSetRValue(value, CTypeCreatePointer(info, CSemGetType(value)));
	return value;
}
#line 4307 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_78__(ILNode_ToBool *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2393 "c_oper.tc"
{
	CSemValue value;
	ILEvalValue *evalValue;

	/* Perform semantic analysis on the expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);

	/* Bail out if not an r-value */
	if(CSemIsError(value))
	{
		return CSemValueBool;
	}
	else if(!CSemIsRValue(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("invalid boolean expression"));
		return CSemValueBool;
	}

	/* Perform constant evaluation */
	evalValue = CSemGetConstant(value);
	if(evalValue && ILGenCastConst(info, evalValue, evalValue->valueType,
								   ILMachineType_Boolean))
	{
		*parent = CreateBoolConstant((ILNode *)node, evalValue->un.i4Value);
		return CreateBoolValue(evalValue->un.i4Value);
	}

	/* Determine how to test the boolean value */
	if(CTypeIsPrimitive(CSemGetType(value)))
	{
		switch(CTypeToElementType(CSemGetType(value)))
		{
			case IL_META_ELEMTYPE_BOOLEAN:
			case IL_META_ELEMTYPE_I1:
			case IL_META_ELEMTYPE_U1:
			case IL_META_ELEMTYPE_I2:
			case IL_META_ELEMTYPE_U2:
			case IL_META_ELEMTYPE_CHAR:
			case IL_META_ELEMTYPE_I4:
			case IL_META_ELEMTYPE_U4:
			case IL_META_ELEMTYPE_I8:
			case IL_META_ELEMTYPE_U8:
			case IL_META_ELEMTYPE_I:
			case IL_META_ELEMTYPE_U:
			case IL_META_ELEMTYPE_R4:
			case IL_META_ELEMTYPE_R8:
			case IL_META_ELEMTYPE_R:
			{
				/* The code generator already knows how to handle
				   boolean conversions for these kinds of types */
			}
			break;

			default:
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  _("invalid boolean expression"));
			}
			break;
		}
	}
	else if(CTypeIsPointer(CSemGetType(value)) ||
	        CTypeIsFunctionPtr(CSemGetType(value)))
	{
		*parent = ILNode_IsNonNull_create(node->expr);
		CGenCloneLine(*parent, node->expr);
	}
	else if(ILTypeIsReference(CSemGetType(value)))
	{
		*parent = ILNode_IsNonNull_create(node->expr);
		CGenCloneLine(*parent, node->expr);
	}
	else
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("invalid boolean expression"));
	}

	/* The result will always be boolean */
	return CSemValueBool;
}
#line 4393 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_79__(ILNode_ToConst *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2480 "c_oper.tc"
{
	CSemValue value;
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(CSemIsRValue(value) && CSemIsConstant(value))
	{
		return value;
	}
	else if(!CSemIsError(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("constant value required"));
	}
	return CSemValueError;
}
#line 4411 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_80__(ILNode_VarArgExpand *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4419 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_81__(ILNode_IsNull *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4427 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_82__(ILNode_IsNonNull *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4435 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_83__(ILNode_MakeRefAny *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4443 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_84__(ILNode_RefType *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4451 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_85__(ILNode_ArrayLength *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4459 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_86__(ILNode_ArrayInit *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4467 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_87__(ILNode_SizeOfExpr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2499 "c_oper.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	CTypeLayoutInfo layout;

	/* Special cases for strings */
	if(yyisa(node->expr, ILNode_CString))
	{
		evalValue.valueType = ILMachineType_UInt32;
		evalValue.un.i4Value =
			(ILInt32)(((ILNode_CString *)(node->expr))->len + 1);
		CSemSetConstant(value, ILType_UInt32, evalValue);
		*parent = CreateConstantNode
			((ILNode *)node, (ILNode *)node, &evalValue);
		return value;
	}
	else if(yyisa(node->expr, ILNode_CWString))
	{
		evalValue.valueType = ILMachineType_UInt32;
		evalValue.un.i4Value =
			(ILInt32)((CGenWStringLength
						(((ILNode_CWString *)(node->expr))->str,
						 ((ILNode_CWString *)(node->expr))->len) + 1) * 2);
		CSemSetConstant(value, ILType_UInt32, evalValue);
		*parent = CreateConstantNode
			((ILNode *)node, (ILNode *)node, &evalValue);
		return value;
	}

	/* Perform semantic analysis on the expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid operand to `sizeof'"));
		}
		CSemSetDynConstant(value, ILType_UInt32);
		return value;
	}
	if(CSemIsDecayed(value))
	{
		node->type = CSemGetDecayedType(value);
	}
	else
	{
		node->type = CSemGetType(value);
	}

	/* Determine the size based on the type */
	CTypeGetLayoutInfo(node->type, &layout);
	if(layout.category == C_TYPECAT_FIXED)
	{
		/* We can replace this node with a compile-time constant */
		evalValue.valueType = ILMachineType_UInt32;
		evalValue.un.i4Value = (ILInt32)(layout.size);
		CSemSetConstant(value, ILType_UInt32, evalValue);
	}
	else if(layout.category == C_TYPECAT_NO_LAYOUT)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("invalid operand to `sizeof'"));
		CSemSetDynConstant(value, ILType_UInt32);
	}
	else
	{
		/* We must compute this constant value dynamically at runtime */
		CSemSetDynConstant(value, ILType_UInt32);
	}
	return value;
}
#line 4543 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_88__(ILNode_SetJmp *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 274 "c_builtin.tc"
{
	CSemValue value;
	ILType *type;

	/* Record that we saw a "setjmp" in the current function, so that
	   the code generator can output the necessary support logic */
	CFunctionSawSetJmp();

	/* We must be at the "statement level" of the surrounding expression */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  _("`setjmp' must be used at the outermost expression level"));
	}

	/* Verify that the argument is of type "int *" */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  		  _("invalid argument to `setjmp'"));
		}
	}
	else
	{
		type = CSemGetType(value);
		if(!CTypeIsPointer(type) ||
		   !ILTypeIdentical(CTypeGetPtrRef(type), ILType_Int32))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  		  _("`setjmp' argument must be of type `int *'"));
		}
	}

	/* The "setjmp" operator always returns an "int" value */
	CSemSetRValue(value, ILType_Int32);
	return value;
}
#line 4587 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_89__(ILNode_AllocA *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 347 "c_builtin.tc"
{
	CSemValue value;

	/* We must be at the "statement level" of the surrounding expression */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
			  _("`alloca' must be used at the outermost expression level"));
	}

	/* Coerce the argument to "unsigned long" */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CCanCoerceValue(value, ILType_UInt))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  		  _("invalid operand to `alloca'"));
		}
	}
	else
	{
		CCoerceNode(info, node->expr, &(node->expr), value, ILType_UInt);
	}

	/* The "alloca" operator always returns a "void *" value */
	CSemSetRValue(value, CTypeCreateVoidPtr(info));
	return value;
}
#line 4620 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_90__(ILNode_CToCSharpString *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2172 "c_oper.tc"
{
	/* Not used, so nothing to do here */
	return CSemValueDefault;
}
#line 4628 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_91__(ILNode_CArrayInit *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 337 "c_ainit.tc"
{
	ILNode_ListIter iter;
	ILNode *expr;

	/* Replace the array initializer with its first element */
	ILNode_ListIter_Init(&iter, node->expr);
	expr = ILNode_ListIter_Next(&iter);
	if(ILNode_ListIter_Next(&iter) != 0)
	{
		CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
						_("excess elements in scalar initializer"));
	}
	*parent = expr;

	/* Perform semantic analysis on the first element */
	return ILNode_CSemAnalysis(expr, info, parent, stmtLevel);
}
#line 4649 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_92__(ILNode_CBox *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2742 "c_oper.tc"
{
	CSemValue value;
	ILType *objectType;
	ILClass *classInfo;

	/* Perform semantic analysis on the sub-expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid operator to `__box' operator"));
		}
		return CSemValueError;
	}

	/* If the value is already a reference type, then leave it as-is */
	if(ILTypeIsReference(CSemGetType(value)))
	{
		*parent = node->expr;
		CSemLToRValue(value);
		return value;
	}

	/* Determine if we have a boxing conversion */
	objectType = ILFindSystemType(info, "Object");
	if(!ILCanCoerceKind(info, CSemGetType(value), objectType,
						IL_CONVERT_BOXING, 0))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("cannot box values of type `%s'"),
					  CTypeToName(info, CSemGetType(value)));
		return CSemValueError;
	}

	/* Perform the coercion */
	ILCoerceKind(info, node->expr, &(node->expr), CSemGetType(value),
				 objectType, IL_CONVERT_BOXING, 0);

	/* Set the return type to the reference form of the value's type */
	classInfo = ILTypeToClass(info, CSemGetType(value));
	if(!classInfo)
	{
		CCOutOfMemory();
	}
	*parent = node->expr;
	CSemSetRValue(value, ILType_FromClass(classInfo));
	return value;
}
#line 4703 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_93__(ILNode_CopyComplex *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 361 "c_stmt.tc"
{
	/* Not called, so nothing to do here */
	return CSemValueDefault;
}
#line 4711 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_94__(ILNode_LogicalAnd *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 260 "c_oper.tc"
{
	CSemValue value1;
	CSemValue value2;
	ILEvalValue *evalValue1;
	ILEvalValue *evalValue2;

	/* Perform semantic analysis on the two arguments */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), stmtLevel);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), stmtLevel);

	/* Perform constant evaluation */
	evalValue1 = CSemGetConstant(value1);
	if(evalValue1)
	{
		if(!ILGenCastConst(info, evalValue1, evalValue1->valueType,
	   				  	   ILMachineType_Boolean))
		{
			evalValue1 = 0;
		}
	}
	evalValue2 = CSemGetConstant(value2);
	if(evalValue1)
	{
		if(!ILGenCastConst(info, evalValue1, evalValue1->valueType,
	   				  	   ILMachineType_Boolean))
		{
			evalValue1 = 0;
		}
	}
	if(evalValue1 && evalValue2)
	{
		/* Both arguments are boolean constants */
		if(evalValue1->un.i4Value && evalValue2->un.i4Value)
		{
			*parent = CreateBoolConstant((ILNode *)node, 1);
			return CreateBoolValue(1);
		}
		else
		{
			*parent = CreateBoolConstant((ILNode *)node, 0);
			return CreateBoolValue(0);
		}
	}
	else if(evalValue1)
	{
		/* The first argument is a boolean constant */
		if(evalValue1->un.i4Value)
		{
			/* The whole expression evaluates to the second argument */
			*parent = ILNode_ToBool_create(node->expr2);
			CGenCloneLine(*parent, node->expr2);
		}
		else
		{
			/* The whole expression evaluates to false */
			*parent = CreateBoolConstant((ILNode *)node, 0);
			return CreateBoolValue(0);
		}
	}
	else if(evalValue2)
	{
		/* The second argument is a boolean constant */
		if(evalValue2->un.i4Value)
		{
			/* The whole expression evaluates to the first argument */
			*parent = ILNode_ToBool_create(node->expr1);
			CGenCloneLine(*parent, node->expr1);
		}
		else
		{
			/* Evaluate side effects in the first expression and return false */
			*parent = ILNode_Comma_create(node->expr1,
										  CreateBoolConstant(node->expr2, 0));
			CGenCloneLine(*parent, (ILNode *)node);
		}
	}

	/* The result is always boolean */
	return CSemValueBool;
}
#line 4795 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_95__(ILNode_LogicalOr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 345 "c_oper.tc"
{
	CSemValue value1;
	CSemValue value2;
	ILEvalValue *evalValue1;
	ILEvalValue *evalValue2;

	/* Perform semantic analysis on the two arguments */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), stmtLevel);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), stmtLevel);

	/* Perform constant evaluation */
	evalValue1 = CSemGetConstant(value1);
	if(evalValue1)
	{
		if(!ILGenCastConst(info, evalValue1, evalValue1->valueType,
	   				  	   ILMachineType_Boolean))
		{
			evalValue1 = 0;
		}
	}
	evalValue2 = CSemGetConstant(value2);
	if(evalValue1)
	{
		if(!ILGenCastConst(info, evalValue1, evalValue1->valueType,
	   				  	   ILMachineType_Boolean))
		{
			evalValue1 = 0;
		}
	}
	if(evalValue1 && evalValue2)
	{
		/* Both arguments are boolean constants */
		if(evalValue1->un.i4Value || evalValue2->un.i4Value)
		{
			*parent = CreateBoolConstant((ILNode *)node, 1);
			return CreateBoolValue(1);
		}
		else
		{
			*parent = CreateBoolConstant((ILNode *)node, 0);
			return CreateBoolValue(0);
		}
	}
	else if(evalValue1)
	{
		/* The first argument is a boolean constant */
		if(evalValue1->un.i4Value)
		{
			/* The whole expression evaluates to true */
			*parent = CreateBoolConstant((ILNode *)node, 1);
			return CreateBoolValue(1);
		}
		else
		{
			/* The whole expression evaluates to the second argument */
			*parent = ILNode_ToBool_create(node->expr2);
			CGenCloneLine(*parent, node->expr2);
		}
	}
	else if(evalValue2)
	{
		/* The second argument is a boolean constant */
		if(evalValue2->un.i4Value)
		{
			/* Evaluate side effects in the first expression and return true */
			*parent = ILNode_Comma_create(node->expr1,
										  CreateBoolConstant(node->expr2, 1));
			CGenCloneLine(*parent, (ILNode *)node);
		}
		else
		{
			/* The whole expression evaluates to the first argument */
			*parent = ILNode_ToBool_create(node->expr1);
			CGenCloneLine(*parent, node->expr1);
		}
	}

	/* The result is always boolean */
	return CSemValueBool;
}
#line 4879 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_96__(ILNode_UserLogicalAnd *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4887 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_97__(ILNode_UserLogicalOr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4895 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_98__(ILNode_Add *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1317 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "+", C_BINARY_ADD);
}
#line 4903 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_99__(ILNode_Sub *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1326 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "-", C_BINARY_SUB);
}
#line 4911 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_100__(ILNode_Mul *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1335 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "*", C_BINARY_NUMERIC);
}
#line 4919 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_101__(ILNode_Div *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1344 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "/", C_BINARY_NUMERIC);
}
#line 4927 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_102__(ILNode_Rem *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1353 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "%", C_BINARY_REM);
}
#line 4935 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_103__(ILNode_And *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1557 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "&", C_BINARY_BITWISE);
}
#line 4943 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_104__(ILNode_Or *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1566 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "|", C_BINARY_BITWISE);
}
#line 4951 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_105__(ILNode_Xor *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1575 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "^", C_BINARY_BITWISE);
}
#line 4959 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_106__(ILNode_Shl *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1683 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, "<<", C_BINARY_SHIFT);
}
#line 4967 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_107__(ILNode_Shr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1693 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, ">>", C_BINARY_SHIFT);
}
#line 4975 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_108__(ILNode_UShr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1693 "c_oper.tc"
{
	return BinarySem(info, (ILNode_BinaryExpression *)node, parent,
					 stmtLevel, ">>", C_BINARY_SHIFT);
}
#line 4983 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_109__(ILNode_UserBinaryOp *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4991 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_110__(ILNode_Concat *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 4999 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_111__(ILNode_DelegateAdd *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5007 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_112__(ILNode_DelegateSub *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5015 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_113__(ILNode_Assign *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1702 "c_oper.tc"
{
	CSemValue value1;
	CSemValue value2;

	/* Determine if the l-value will leave the machine state at
	   the statement level of the expression, or if it might leave
	   values on the stack before computing "expr2".  This check
	   is necessary to ensure that we can assign the results of
	   "setjmp" and "alloca" to local/global variables */
	if(stmtLevel)
	{
		if(!yyisa(node->expr1, ILNode_CLocalVar) &&
		   !yyisa(node->expr1, ILNode_CArgumentVar) &&
		   !yyisa(node->expr1, ILNode_CGlobalVar))
		{
			stmtLevel = 0;
		}
	}

	/* Perform semantic analysis on the two values */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), 0);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), stmtLevel);

	/* Check that the first is an l-value and the second is an r-value */
	if(!CSemIsLValue(value1))
	{
		if(!CSemIsError(value1))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid lvalue in assignment");
		}
		return CSemValueError;
	}
	if(!CSemIsRValue(value2))
	{
		if(!CSemIsError(value2))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid rvalue in assignment");
		}
		return CSemValueError;
	}

	/* Check that we can coerce from "value2" to "value1"'s type */
	if(ILTypeStripPrefixes(CSemGetType(value1)) == ILType_Boolean &&
	   (CSemIsBoolean(value2) ||
	    ILTypeStripPrefixes(CSemGetType(value2)) == ILType_Boolean))
	{
		/* Assigning a value to a "__bool__" variable is handled specially */
		return CSemValueBool;
	}
	else
	{
		if(!CCanCoerceValue(value2, CSemGetType(value1)))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "incompatible types in assignment");
			CSemSetRValue(value1, CSemGetType(value1));
			return value1;
		}

		/* Insert coercion nodes to convert the rvalue appropriately */
		CCoerceNode(info, node->expr2, &(node->expr2),
					value2, CSemGetType(value1));

		/* Convert value1 into an rvalue and return its type */
		CSemSetRValue(value1, CSemGetType(value1));
		return value1;
	}
}
#line 5089 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_114__(ILNode_Eq *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1914 "c_oper.tc"
{
	return RelationalSem(info, (ILNode_BinaryExpression *)node,
				         parent, stmtLevel, "==");
}
#line 5097 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_115__(ILNode_Ne *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1923 "c_oper.tc"
{
	return RelationalSem(info, (ILNode_BinaryExpression *)node,
				         parent, stmtLevel, "!=");
}
#line 5105 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_116__(ILNode_Lt *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1932 "c_oper.tc"
{
	return RelationalSem(info, (ILNode_BinaryExpression *)node,
				         parent, stmtLevel, "<");
}
#line 5113 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_117__(ILNode_Le *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1941 "c_oper.tc"
{
	return RelationalSem(info, (ILNode_BinaryExpression *)node,
				         parent, stmtLevel, "<=");
}
#line 5121 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_118__(ILNode_Gt *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1950 "c_oper.tc"
{
	return RelationalSem(info, (ILNode_BinaryExpression *)node,
				         parent, stmtLevel, ">");
}
#line 5129 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_119__(ILNode_Ge *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1959 "c_oper.tc"
{
	return RelationalSem(info, (ILNode_BinaryExpression *)node,
				         parent, stmtLevel, ">=");
}
#line 5137 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_120__(ILNode_Comma *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1968 "c_oper.tc"
{
	CSemValue value1;
	CSemValue value2;

	/* Perform semantic analysis on the two arguments */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), stmtLevel);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), stmtLevel);

	/* Both must be r-value's or "void" */
	if((!CSemIsRValue(value1) && !CSemIsVoid(value1)) ||
	   (!CSemIsRValue(value2) && !CSemIsVoid(value2)))
	{
		if(!CSemIsError(value1) && !CSemIsError(value2))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid operands to binary `,'"));
		}
		return CSemValueError;
	}
	if(CSemIsLValue(value2))
	{
		/* Turn l-values into r-values */
		CSemSetRValue(value2, CSemGetType(value2));
	}
	if(CSemIsConstant(value1) && CSemIsConstant(value2))
	{
		/* The whole expression evaluates to its constant second argument */
		*parent = node->expr2;
	}
	else if(!CSemIsConstant(value1) && CSemIsConstant(value2))
	{
		/* Both must be constants for the whole expression to be constant */
		CSemSetRValue(value2, CSemGetType(value2));
	}

	/* Return "value2" as the final semantic value */
	return value2;
}
#line 5179 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_121__(ILNode_ArgList *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5187 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_122__(ILNode_RefValue *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5195 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_123__(ILNode_CInvocationExpression *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 316 "c_invoke.tc"
{
	CSemValue value;
	void *data;
	ILType *signature;
	ILNode *funcNode;
	ILType *type;
	CEvalArg *argTypes;
	ILUInt32 numArgs;
	ILUInt32 argNum;

	/* Determine if this is a call by name or a call by reference */
	signature = 0;
	funcNode = 0;
	if(yyisa(node->expr1, ILNode_FunctionRef))
	{
		/* Record the name for later and then look up the function signature */
		node->name = ((ILNode_FunctionRef *)(node->expr1))->name;
		signature = ((ILNode_FunctionRef *)(node->expr1))->signature;
		if(signature == ILType_Invalid)
		{
			data = CScopeLookup(node->name);
			if(data)
			{
				signature = CScopeGetType(data);
				funcNode = CScopeGetNode(data);
			}
		}
	}
	else
	{
		/* Perform semantic analysis on the function pointer argument */
		node->name = 0;
		value = ILNode_CSemAnalysis(node->expr1, info,
									&(node->expr1), stmtLevel);
		if(CSemIsMethodGroup(value))
		{
			/* Reference to a method group: switch to C# invocation */
			if(yyisa(node->expr1, ILNode_AsIs))
			{
				*parent = ILNode_CSharpInvocation_create
					(CSemGetType(value), CSemGetMethodName(value),
					 node->expr1, node->expr2);
			}
			else
			{
				*parent = ILNode_CSharpInvocation_create
					(CSemGetType(value), CSemGetMethodName(value),
					 0, node->expr2);
			}
			CGenCloneLine(*parent, (ILNode *)node);
			return ILNode_CSemAnalysis(*parent, info, parent, stmtLevel);
		}
		else if(!CSemIsRValue(value) || !CTypeIsFunctionPtr(CSemGetType(value)))
		{
			if(!CSemIsError(value))
			{
				CCErrorOnLine(yygetfilename(node->expr1),
							  yygetlinenum(node->expr1),
							  _("called object is not a function"));
			}
		}
		else
		{
			signature = ILTypeStripPrefixes(CSemGetType(value));
		}
	}

	/* Perform semantic analysis on the invocation arguments */
	numArgs = CountArgs(node->expr2);
	if(numArgs != 0)
	{
		argTypes = (CEvalArg *)ILMalloc(numArgs * sizeof(CEvalArg));
		if(!argTypes)
		{
			CCOutOfMemory();
		}
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			ArgumentSem(info, &(argTypes[argNum]), node->expr2,
						&(node->expr2), argNum, numArgs);
		}
	}
	else
	{
		argTypes = 0;
	}

	/* Infer a forward-reference signature if we weren't given one */
	if(!signature)
	{
		signature = ILTypeCreateMethod(info->context, ILType_Int32);
		if(!signature)
		{
			CCOutOfMemory();
		}
		for(argNum = 0; argNum < numArgs; ++argNum)
		{
			type = CSemGetType(argTypes[argNum].value);
			type = CFunctionNaturalType(info, type, 0);
			if(!ILTypeAddParam(info->context, signature, type))
			{
				CCOutOfMemory();
			}
		}
		if(node->name)
		{
			/* Warn about a forward reference and add it to the global scope */
			CCWarningOnLine(yygetfilename(node->expr1),
							yygetlinenum(node->expr1),
							_("implicit declaration of function `%s'"),
							node->name);
			CScopeAddInferredFunction(node->name, signature);
		}
	}

	/* Coerce the supplied arguments to the signature parameter types */
	if((ILType_CallConv(signature) & IL_META_CALLCONV_MASK) !=
			IL_META_CALLCONV_VARARG)
	{
		/* This is a regular function call */
		CoerceArgs(info, node, signature, argTypes, numArgs);
	}
	else
	{
		/* This is a variable-argument function call */
		argNum = (ILUInt32)(ILTypeNumParams(signature));
		if(argNum >= numArgs)
		{
			/* No variable arguments were supplied */
			CoerceArgs(info, node, signature, argTypes, numArgs);
		}
		else
		{
			/* Coerce the fixed arguments and build a call site signature */
			CoerceArgs(info, node, signature, argTypes, argNum);
			signature = BuildVarargCallSite
				(info, signature, argTypes + argNum, numArgs - argNum);
		}
	}

	/* Set the call site signature, for use by the code generator */
	node->callSiteSig = signature;

	/* Free the temporary argument structures */
	if(argTypes != 0)
	{
		ILFree(argTypes);
	}

	/* Construct the semantic value for the return type */
	type = ILTypeGetReturnWithPrefixes(signature);
	if(ILTypeIdentical(type, ILType_Void))
	{
		return CSemValueDefault;
	}
	else
	{
		CSemSetRValue(value, type);
		return value;
	}
}
#line 5360 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_124__(ILNode_InvocationExpression *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5368 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_125__(ILNode_CDelete *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 901 "c_invoke.tc"
{
	CSemValue value;
	CSemValue arraySize;
	ILType *type;
	ILType *stripped;
	ILMethod *method;

	/* Perform semantic analysis on the sub-expressions */
	if(node->expr1)
	{
		arraySize = ILNode_CSemAnalysis
			(node->expr1, info, &(node->expr1), stmtLevel);
		if(!CSemIsRValue(arraySize))
		{
			if(!CSemIsError(arraySize))
			{
				CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
							  _("invalid size operand to `delete'"));
			}
			arraySize = CSemValueDefault;
		}
	}
	else
	{
		arraySize = CSemValueDefault;
	}
	value = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(!CSemIsError(value))
		{
			goto invalid;
		}
		return CSemValueError;
	}

	/* Determine how to delete the specified value */
	type = CSemGetType(value);
	stripped = ILTypeStripPrefixes(type);
	if(CTypeIsPointer(type))
	{
		/* TODO: overloaded operators and array element destruction */

		/* Use the default destructor to free the pointer */
		return CSemValueDefault;
	}
	else if(ILType_IsClass(stripped))
	{
		/* See if the class has a "__dtor" method */
		method = ILResolveInstanceMethod
				(info, ILType_ToClass(stripped),
				 ILClassLookup(ILClassGlobalScope(info->image), "<Module>", 0),
				 "__dtor", 0, 0);
		if(method)
		{
			node->dtor = method;
			return CSemValueDefault;
		}
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`%s' does not have a public destructor"),
					  CTypeToName(info, type));
		return CSemValueError;
	}

invalid:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operand to `delete'"));
	return CSemValueError;
}
#line 5441 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_126__(ILNode_CSizeReleaseTempVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2826 "c_oper.tc"
{
	return ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), stmtLevel);
}
#line 5448 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_127__(ILNode_CSizeMax *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2834 "c_oper.tc"
{
	CSemValue value1;
	CSemValue value2;
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), 0);
	value2 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), 0);
	if(CSemIsConstant(value1) && CSemIsConstant(value2))
	{
		/* Both expressions are constant, so compute the result now */
		if(CSemGetConstant(value1)->un.i4Value >
		   CSemGetConstant(value2)->un.i4Value)
		{
			*parent = node->expr1;
			CGenCloneLine(*parent, (ILNode *)node);
			return value1;
		}
		else
		{
			*parent = node->expr2;
			CGenCloneLine(*parent, (ILNode *)node);
			return value2;
		}
	}
	CSemSetDynConstant(value1, ILType_UInt32);
	return value1;
}
#line 5477 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_128__(ILNode_Conditional *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2273 "c_oper.tc"
{
	CSemValue boolValue;
	CSemValue value1;
	CSemValue value2;
	ILType *commonType;
	ILEvalValue *evalValue;

	/* Perform semantic analysis on the boolean condition */
	boolValue = ILNode_CSemAnalysis(node->expr1, info,
									&(node->expr1), stmtLevel);

	/* Perform semantic analysis on the "then" and "else" clauses */
	value1 = ILNode_CSemAnalysis(node->expr2, info, &(node->expr2), stmtLevel);
	value2 = ILNode_CSemAnalysis(node->expr3, info, &(node->expr3), stmtLevel);
	if((!CSemIsRValue(value1) && !CSemIsVoid(value1)) ||
	   (!CSemIsRValue(value2) && !CSemIsVoid(value2)))
	{
		goto error;
	}

	/* Convert function references into function pointers */
	if(CTypeIsFunction(CSemGetType(value1)) &&
	   yyisa(node->expr2, ILNode_FunctionRef))
	{
		CSemSetRValue(value1, CTypeAddFunctionPtr(info, CSemGetType(value1)));
	}
	if(CTypeIsFunction(CSemGetType(value2)) &&
	   yyisa(node->expr3, ILNode_FunctionRef))
	{
		CSemSetRValue(value2, CTypeAddFunctionPtr(info, CSemGetType(value2)));
	}

	/* Determine the common type and then coerce the arguments */
	commonType = CommonCondType(info, CSemGetType(value1), CSemGetType(value2));
	if(commonType == ILType_Invalid)
	{
		goto error;
	}
	else if(commonType == ILType_Void)
	{
		return CSemValueDefault;
	}
	else
	{
		value1 = CCoerceNode(info, node->expr2, &(node->expr2),
							 value1, commonType);
		value2 = CCoerceNode(info, node->expr3, &(node->expr3),
							 value2, commonType);
		evalValue = CSemGetConstant(boolValue);
		if(evalValue)
		{
			if(evalValue->un.i4Value)
			{
				*parent = node->expr2;
				CSemLToRValue(value1);
			}
			else
			{
				*parent = node->expr3;
				CSemLToRValue(value2);
				return value2;
			}
		}
		else
		{
			CSemSetRValue(value1, commonType);
		}
		return value1;
	}

	/* Report an error with the arguments to "?:" */
error:
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("invalid operands to ternary `?:'"));
	return CSemValueError;
}
#line 5557 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_129__(ILNode_AssignAdd *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1777 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "+", C_BINARY_ADD);
}
#line 5566 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_130__(ILNode_AssignSub *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1787 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "-", C_BINARY_SUB);
}
#line 5575 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_131__(ILNode_AssignMul *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1797 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "*", C_BINARY_NUMERIC);
}
#line 5584 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_132__(ILNode_AssignDiv *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1807 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "/", C_BINARY_NUMERIC);
}
#line 5593 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_133__(ILNode_AssignRem *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1817 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "%", C_BINARY_REM);
}
#line 5602 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_134__(ILNode_AssignAnd *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1827 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "&", C_BINARY_BITWISE);
}
#line 5611 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_135__(ILNode_AssignOr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1837 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "|", C_BINARY_BITWISE);
}
#line 5620 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_136__(ILNode_AssignXor *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1847 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "^", C_BINARY_BITWISE);
}
#line 5629 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_137__(ILNode_AssignShl *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1857 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), "<<", C_BINARY_SHIFT);
}
#line 5638 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_138__(ILNode_AssignShr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1868 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), ">>", C_BINARY_SHIFT);
}
#line 5647 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_139__(ILNode_AssignUShr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1868 "c_oper.tc"
{
	return AssignSem(info, (ILNode *)node,
					 (ILNode_BinaryExpression *)(node->assign),
					 &(node->assign), ">>", C_BINARY_SHIFT);
}
#line 5656 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_140__(ILNode_VarArgList *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5664 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_141__(ILNode_Argument *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5672 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_142__(ILNode_ArgArray *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5680 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_143__(ILNode_As *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5688 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_144__(ILNode_Is *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5696 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_145__(ILNode_Box *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5704 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_146__(ILNode_Unbox *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5712 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_147__(ILNode_BoxingExpression *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5720 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_148__(ILNode_Error *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2675 "c_oper.tc"
{
	return CSemValueError;
}
#line 5727 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_149__(ILNode_NewExpression *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5735 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_150__(ILNode_ObjectCreationExpression *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5743 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_151__(ILNode_DelegateCreationExpression *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5751 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_152__(ILNode_DefaultConstructor *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5759 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_153__(ILNode_BaseInit *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5767 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_154__(ILNode_ThisInit *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5775 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_155__(ILNode_NonStaticInit *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5783 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_156__(ILNode_EmptyExpr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 5791 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_157__(ILNode_SizeOfType *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2601 "c_oper.tc"
{
	CSemValue value;
	ILEvalValue evalValue;
	CTypeLayoutInfo layout;

	CTypeGetLayoutInfo(node->type, &layout);
	if(layout.category == C_TYPECAT_FIXED)
	{
		/* We can replace this node with a compile-time constant */
		evalValue.valueType = ILMachineType_UInt32;
		evalValue.un.i4Value = (ILInt32)(layout.size);
		CSemSetConstant(value, ILType_UInt32, evalValue);
	}
	else if(layout.category == C_TYPECAT_NO_LAYOUT)
	{
		/* The supplied type does not have any layout information */
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("invalid operand to `sizeof'"));
		CSemSetDynConstant(value, ILType_UInt32);
	}
	else
	{
		/* We must compute this constant value dynamically at runtime */
		CSemSetDynConstant(value, ILType_UInt32);
	}
	return value;
}
#line 5822 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_158__(ILNode_VaStart *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 59 "c_builtin.tc"
{
	ILMethod *method;
	ILType *signature;
	ILParameter *param;

	/* We must use this inside a "VARARG" function */
	method = CFunctionGetCurrent();
	signature = ILMethod_Signature(method);
	if((ILType_CallConv(signature) & IL_META_CALLCONV_MASK)
			!= IL_META_CALLCONV_VARARG)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				      _("`va_start' used in function with fixed args"));
	}

	/* If a parameter name was specified, then it must be
	   the name of the last parameter to the function */
	if(node->name != 0)
	{
		if(ILTypeNumParams(signature) > 0)
		{
			param = 0;
			while((param = ILMethodNextParam(method, param)) != 0)
			{
				if(ILParameter_Name(param) != 0 &&
				   !strcmp(ILParameter_Name(param), node->name))
				{
					break;
				}
			}
		}
		else
		{
			param = 0;
		}
		if(!param || ILParameter_Num(param) != ILTypeNumParams(signature))
		{
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
			  _("second parameter of `va_start' not last named argument"));
		}
	}

	/* Perform semantic analysis on the "va_list" value */
	VaListSem(info, node->vaList, &(node->vaList));

	/* The "va_start" declaration has no value */
	return CSemValueDefault;
}
#line 5874 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_159__(ILNode_VaEnd *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 152 "c_builtin.tc"
{
	/* Perform semantic analysis on the "va_list" value */
	VaListSem(info, node->vaList, &(node->vaList));

	/* The "va_end" declaration has no value */
	return CSemValueDefault;
}
#line 5885 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_160__(ILNode_VaArg *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 199 "c_builtin.tc"
{
	CSemValue value;
	ILType *naturalType;

	/* Perform semantic analysis on the "va_list" value */
	VaListSem(info, node->vaList, &(node->vaList));

	/* The type cannot be "void" */
	if(ILTypeIdentical(node->type, ILType_Void))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`void' cannot be used with `va_arg'"));
		return CSemValueDefault;
	}

	/* Insert a cast from the natural argument type to the actual type,
	   which will undo the normalization that we had to apply to pass
	   the argument to the function in the first place */
	if(ILTypeStripPrefixes(node->type) != ILType_Float)
	{
		naturalType = CFunctionNaturalType(info, node->type, 1);
		CSemSetRValue(value, naturalType);
		CCastNode(info, (ILNode *)node, parent, value, node->type);
	}

	/* The "va_arg" declaration is an r-value of the specified type */
	CSemSetRValue(value, node->type);
	return value;
}
#line 5918 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_161__(ILNode_FunctionRef *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 28 "c_invoke.tc"
{
	CSemValue value;
	CSemSetRValue(value, node->signature);
	return value;
}
#line 5927 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_162__(ILNode_CLabelRef *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 661 "c_stmt.tc"
{
	CGenGoto *label;
	CSemValue value;

	/* Record this label in the function's "goto" label list */
	label = gotoList;
	while(label != 0 && label->name != node->name)
	{
		label = label->next;
	}
	if(!label)
	{
		label = (CGenGoto *)ILMalloc(sizeof(CGenGoto));
		if(!label)
		{
			CCOutOfMemory();
		}
		label->next = gotoList;
		gotoList = label;
		label->name = node->name;
		label->node = (ILNode *)node;
		label->labelNum = gotoLabelNext++;
		label->defined = 0;
		label->used = 1;
	}
	else
	{
		label->used = 1;
	}

	/* Copy the label number for later use */
	node->labelNum = label->labelNum;

	/* Labels always have the type "void *" */
	CSemSetRValue(value, CTypeCreateVoidPtr(info));
	return value;
}
#line 5968 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_163__(ILNode_CSharpTypeOf *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2683 "c_oper.tc"
{
	/* The return value is always "System.Type" */
	CSemValue value;
	CSemSetRValue(value, ILFindSystemType(info, "Type"));
	return value;
}
#line 5978 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_164__(ILNode_CTypeExpression *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2721 "c_oper.tc"
{
	CSemValue value;
	CSemSetType(value, node->type);
	return value;
}
#line 5987 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_165__(ILNode_CNewObject *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 775 "c_invoke.tc"
{
	/* TODO */
	return CSemValueDefault;
}
#line 5995 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_166__(ILNode_CNewArray *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 806 "c_invoke.tc"
{
	CSemValue value;

	/* Deal with unknown "new" specifiers */
	if(node->specifier == ILGC_Unknown)
	{
		if(ILTypeIsReference(node->type))
		{
			node->specifier = ILGC_Managed;
		}
		else
		{
			node->specifier = ILGC_Unmanaged;
		}
	}

	/* Determine the result type */
	if(node->specifier == ILGC_Managed)
	{
		node->resultType = ILTypeCreateArray(info->context, 1, node->type);
		if(!(node->resultType))
		{
			CCOutOfMemory();
		}
	}
	else
	{
		node->resultType = CTypeCreatePointer(info, node->type);
	}

	/* Perform semantic analysis on the size expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid size argument to array construction"));
		}
	}
	else if(!CCanCoerceValue(value, ILType_UInt32))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("size argument is not numeric"));
	}
	else
	{
		CCoerceNode(info, node->expr, &(node->expr), value, ILType_UInt32);
	}

	/* Set the result type and exit */
	CSemSetRValue(value, node->resultType);
	return value;
}
#line 6053 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_167__(ILNode_CSizeOfRaw *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2807 "c_oper.tc"
{
	CSemValue value;
	CSemSetDynConstant(value, ILType_UInt32);
	return value;
}
#line 6062 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_168__(ILNode_CSizeTempVar *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2817 "c_oper.tc"
{
	/* Not used during semantic analysis */
	return CSemValueDefault;
}
#line 6070 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_169__(ILNode_CSizeAlign *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 2864 "c_oper.tc"
{
	CSemValue value;
	ILNode_CSemAnalysis(node->size, info, &(node->size), 0);
	CSemSetDynConstant(value, ILType_UInt32);
	return value;
}
#line 6080 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_170__(ILNode_Compound *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 138 "c_stmt.tc"
{
	CSemValue value = CSemValueDefault;
	ILNode_ListIter iter;
	ILNode *stmt, *replace;
	ILNode_ListIter_Init(&iter, node);
	while((stmt = ILNode_ListIter_Next(&iter)) != 0)
	{
		replace = stmt;
		value = ILNode_CSemAnalysis(stmt, info, &replace, stmtLevel);
		if(replace != stmt)
		{
			*(iter.last) = replace;
		}
		if(!CSemIsVoid(value) && !CSemIsRValue(value) && !CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid statement"));
		}
	}
	return value;
}
#line 6105 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_171__(ILNode_SwitchSectList *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6113 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_172__(ILNode_CaseList *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6121 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_173__(ILNode_List *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 138 "c_stmt.tc"
{
	CSemValue value = CSemValueDefault;
	ILNode_ListIter iter;
	ILNode *stmt, *replace;
	ILNode_ListIter_Init(&iter, node);
	while((stmt = ILNode_ListIter_Next(&iter)) != 0)
	{
		replace = stmt;
		value = ILNode_CSemAnalysis(stmt, info, &replace, stmtLevel);
		if(replace != stmt)
		{
			*(iter.last) = replace;
		}
		if(!CSemIsVoid(value) && !CSemIsRValue(value) && !CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid statement"));
		}
	}
	return value;
}
#line 6146 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_174__(ILNode_Empty *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 125 "c_stmt.tc"
{
	/* Nothing to do here, because there is nothing in the statement */
	return CSemValueDefault;
}
#line 6154 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_175__(ILNode_If *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 179 "c_stmt.tc"
{
	ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	StmtSem(node->thenClause, info, &(node->thenClause), stmtLevel);
	StmtSem(node->elseClause, info, &(node->elseClause), stmtLevel);
	return CSemValueDefault;
}
#line 6164 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_176__(ILNode_While *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 205 "c_stmt.tc"
{
	ILNode_CSemAnalysis(node->cond, info, &(node->cond), stmtLevel);
	PushStmtContext(info, C_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);
	PopStmtContext(info);
	return CSemValueDefault;
}
#line 6175 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_177__(ILNode_Do *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 227 "c_stmt.tc"
{
	PushStmtContext(info, C_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);
	PopStmtContext(info);
	ILNode_CSemAnalysis(node->cond, info, &(node->cond), stmtLevel);
	return CSemValueDefault;
}
#line 6186 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_178__(ILNode_For *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 239 "c_stmt.tc"
{
	StmtSem(node->init, info, &(node->init), stmtLevel);
	ILNode_CSemAnalysis(node->cond, info, &(node->cond), stmtLevel);
	StmtSem(node->incr, info, &(node->incr), stmtLevel);
	PushStmtContext(info, C_STMT_LOOP);
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);
	PopStmtContext(info);
	return CSemValueDefault;
}
#line 6199 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_179__(ILNode_Foreach *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6207 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_180__(ILNode_ForeachString *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6215 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_181__(ILNode_ForeachCollection *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6223 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_182__(ILNode_Switch *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1056 "c_stmt.tc"
{
	CSemValue value;
	ILType *governType;
	unsigned long size;

	/* Make sure that we are at the statement level of the function */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`switch' used within expression statement"));
		return CSemValueDefault;
	}

	/* Collect up the "case" and "default" labels within the "switch" body */
	node->sections = ILNode_SwitchSectList_create();
	if(node->body)
	{
		ILNode_CollectCases(node->body, info, node->sections);
	}

	/* Perform semantic analysis on the expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value) || !CTypeIsInteger(CSemGetType(value)))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node->expr), yygetlinenum(node->expr),
						  _("switch quantity not an integer"));
		}
		CSemSetRValue(value, ILType_Int32);
	}

	/* Determine the governing type to use */
	switch(ILTypeToMachineType(CSemGetType(value)))
	{
		case ILMachineType_UInt32:
		{
			governType = ILType_UInt32;
		}
		break;

		case ILMachineType_NativeInt:
		case ILMachineType_Int64:
		{
			governType = ILType_Int64;
		}
		break;

		case ILMachineType_NativeUInt:
		case ILMachineType_UInt64:
		{
			governType = ILType_UInt64;
		}
		break;

		default:
		{
			governType = ILType_Int32;
		}
		break;
	}

	/* Coerce the expression to the governing type */
	CCoerceNode(info, node->expr, &(node->expr), value, governType);

	/* Enter the switch context */
	PushStmtContext(info, C_STMT_SWITCH);

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

	/* Collect up the case labels and cast to the governing type */
	node->numSwitchValues = CollectCaseLabels(info, node->sections,
											  governType, node->switchValues);

	/* Determine the type of switch table to generate */
	node->tableType = SwitchTableType(governType, node->switchValues,
									  node->numSwitchValues);

	/* Perform semantic analysis on the switch body */
	StmtSem(node->body, info, &(node->body), stmtLevel);

	/* Exit the switch context */
	PopStmtContext(info);

	/* Finished */
	return CSemValueDefault;
}
#line 6333 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_183__(ILNode_Break *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 253 "c_stmt.tc"
{
	if(!StmtContextOK(info, C_STMT_LOOP | C_STMT_SWITCH, 0))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`break' used outside loop or switch");
	}
	return CSemValueDefault;
}
#line 6345 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_184__(ILNode_LabelledBreak *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6353 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_185__(ILNode_Continue *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 266 "c_stmt.tc"
{
	if(!StmtContextOK(info, C_STMT_LOOP, 0))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "`continue' used outside loop");
	}
	return CSemValueDefault;
}
#line 6365 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_186__(ILNode_LabelledContinue *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6373 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_187__(ILNode_Return *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 279 "c_stmt.tc"
{
	ILMethod *method = CFunctionGetCurrent();
	ILType *returnType = CTypeGetReturn(ILMethod_Signature(method));
	if(ILTypeStripPrefixes(returnType) != ILType_Void)
	{
		/* Emit a warning if the return type is not "void".  This really
		   should be an error, but we copy what gcc does for compatibility */
		CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
			  "`return' with no value, in function returning non-void");
	}
	return CSemValueDefault;
}
#line 6389 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_188__(ILNode_ReturnExpr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 296 "c_stmt.tc"
{
	CSemValue value;
	ILMethod *method = CFunctionGetCurrent();
	ILType *returnType = CTypeGetReturn(ILMethod_Signature(method));

	/* Perform semantic analysis on the expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(CSemIsError(value))
	{
		/* We've already reported an error for a bad expression,
		   so don't bother complaining about the situation again */
		return CSemValueDefault;
	}
	else if(!CSemIsRValue(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "invalid return value");
		return CSemValueDefault;
	}

	/* Determine if the value is compatible with the return type */
	if(ILTypeStripPrefixes(returnType) == ILType_Void)
	{
		/* Emit a warning if the return type is "void".  This really should
		   be an error, but we copy what gcc does for compatibility */
		CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
			  "`return' with a value, in function returning void");

		/* Replace the current node with a value-less return so that
		   the code generator outputs the correct return code */
		*parent = ILNode_Return_create();
		CGenCloneLine(*parent, (ILNode *)node);
	}
	else
	{
		/* Coerce the value to the return type */
		if(CCanCoerceValue(value, returnType))
		{
			CCoerceNode(info, node->expr, &(node->expr), value, returnType);
			if(CTypeIsComplex(returnType))
			{
				/* We need to make a copy of a complex value before
				   returning it to the caller */
				node->expr = ILNode_CopyComplex_create
					(node->expr, returnType);
			}
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  		  "incompatible types in return: "
						  		"no conversion from `%s' to `%s'",
						  CTypeToName(info, CSemGetType(value)),
						  CTypeToName(info, returnType));
		}
	}

	/* Done */
	return CSemValueDefault;
}
#line 6453 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_189__(ILNode_Goto *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 534 "c_stmt.tc"
{
	CGenGoto *label;

	/* We must use "goto" at the statement level */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`goto' used within expression statement"));
		return CSemValueDefault;
	}

	/* Record this label in the function's "goto" label list */
	label = gotoList;
	while(label != 0 && label->name != node->name)
	{
		label = label->next;
	}
	if(!label)
	{
		label = (CGenGoto *)ILMalloc(sizeof(CGenGoto));
		if(!label)
		{
			CCOutOfMemory();
		}
		label->next = gotoList;
		gotoList = label;
		label->name = node->name;
		label->node = (ILNode *)node;
		label->labelNum = gotoLabelNext++;
		label->defined = 0;
		label->used = 1;
	}
	else
	{
		label->used = 1;
	}
	return CSemValueDefault;
}
#line 6495 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_190__(ILNode_GotoLabel *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 577 "c_stmt.tc"
{
	CGenGoto *label;

	/* We must use goto labels at the statement level */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("label used within expression statement"));
		return CSemValueDefault;
	}

	/* Record this label in the function's "goto" label list */
	label = gotoList;
	while(label != 0 && label->name != node->name)
	{
		label = label->next;
	}
	if(!label)
	{
		label = (CGenGoto *)ILMalloc(sizeof(CGenGoto));
		if(!label)
		{
			CCOutOfMemory();
		}
		label->next = gotoList;
		gotoList = label;
		label->name = node->name;
		label->node = (ILNode *)node;
		label->labelNum = gotoLabelNext++;
		label->defined = 1;
		label->used = 0;
	}
	else if(!(label->defined))
	{
		label->node = (ILNode *)node;
		label->defined = 1;
	}
	else
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("duplicate label `%s'"), node->name);
	}
	return CSemValueDefault;
}
#line 6543 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_191__(ILNode_GotoCase *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6551 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_192__(ILNode_GotoDefault *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6559 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_193__(ILNode_NewScope *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 703 "c_stmt.tc"
{
	ILScope *savedScope = info->currentScope;
	CSemValue value;
	if(!(node->scope))
	{
		node->scope = ILScopeCreate(info, savedScope);
	}
	info->currentScope = node->scope;
	value = StmtSem(node->stmt, info, &(node->stmt), stmtLevel);
	info->currentScope = savedScope;
	return value;
}
#line 6575 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_194__(ILNode_SwitchSection *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6583 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_195__(ILNode_CaseLabel *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1176 "c_stmt.tc"
{
	if(!StmtContextOK(info, C_STMT_SWITCH, 0))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`case' used outside switch"));
	}
	return CSemValueDefault;
}
#line 6595 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_196__(ILNode_DefaultLabel *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1189 "c_stmt.tc"
{
	if(!StmtContextOK(info, C_STMT_SWITCH, 0))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`default' used outside switch"));
	}
	return CSemValueDefault;
}
#line 6607 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_197__(ILNode_Throw *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1278 "c_stmt.tc"
{
	if(!StmtContextOK(info, C_STMT_CATCH, C_STMT_FINALLY | C_STMT_TRY))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  		  _("`__throw__' with no value must be used "
					    "inside a `__catch__' clause"));
	}
	return CSemValueDefault;
}
#line 6620 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_198__(ILNode_ThrowExpr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1292 "c_stmt.tc"
{
	CSemValue value;
	ILType *exceptionClass;

	/* Perform semantic analysis on the value */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(CSemIsError(value))
	{
		/* We've already reported an error for a bad expression,
		   so don't bother complaining about the situation again */
		return CSemValueDefault;
	}
	else if(!CSemIsRValue(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("invalid throw expression"));
		return CSemValueDefault;
	}

	/* Attempt to coerce the value to "System.Exception" */
	exceptionClass = ILFindSystemType(info, "Exception");
	if(!CCanCoerce(CSemGetType(value), exceptionClass))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  		  "no conversion from `%s' to `%s'",
					  CTypeToName(info, CSemGetType(value)),
					  CTypeToName(info, exceptionClass));
	}
	CCoerceNode(info, node->expr, &(node->expr), value, exceptionClass);

	/* Done */
	return CSemValueDefault;
}
#line 6657 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_199__(ILNode_Try *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1330 "c_stmt.tc"
{
	/* Exception blocks must be at the statement level of the function */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`__try__' used within expression statement"));
		return CSemValueDefault;
	}

	/* Enter a "try" context */
	PushStmtContext(info, C_STMT_TRY);

	/* Perform semantic analysis on the "try" body */
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);

	/* Perform semantic analysis on the "catch" clauses */
	StmtSem(node->catchClauses, info, &(node->catchClauses), stmtLevel);

	/* Perform semantic analysis on the "finally" clause */
	StmtSem(node->finallyClause, info, &(node->finallyClause), stmtLevel);

	/* Exit from the "try" context */
	PopStmtContext(info);

	/* Done */
	return CSemValueDefault;
}
#line 6688 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_200__(ILNode_CatchClause *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1362 "c_stmt.tc"
{
	ILType *exceptionType = ILFindSystemType(info, "Exception");
	ILType *thrownType;
	ILScope *newScope;

	/* Enter a "catch" context */
	PushStmtContext(info, C_STMT_CATCH);

	/* Wrap the catch body in a new scope */
	newScope = ILScopeCreate(info, info->currentScope);
	node->stmt = ILNode_NewScope_create(node->stmt);
	((ILNode_NewScope *)(node->stmt))->scope = newScope;

	/* Validate the thrown value type, which is in "node->classInfo" */
	thrownType = ILClassToType(node->classInfo);
	if(!CCanCoerce(thrownType, exceptionType))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
	  		  		  _("`%s' does not inherit from `%s'"),
					  CTypeToName(info, thrownType),
					  CTypeToName(info, exceptionType));
		thrownType = exceptionType;
	}

	/* Declare a new local variable for the catch value */
	if(node->name)
	{
		/* Add the type to the local variable signature for this method */
		node->varIndex = CGenAllocLocal(info, thrownType);

		/* Create a local variable entry in the current scope */
		ILScopeDeclareLocal(newScope, node->name, node->varIndex,
							node->nameNode);
	}

	/* Perform semantic analysis on the catch body */
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);

	/* Exit from the "catch" context */
	PopStmtContext(info);

	/* Done */
	return CSemValueDefault;
}
#line 6736 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_201__(ILNode_FinallyClause *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1411 "c_stmt.tc"
{
	/* Enter a "finally" context */
	PushStmtContext(info, C_STMT_FINALLY);

	/* Perform semantic analysis on the finally body */
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);

	/* Exit from the "finally" context */
	PopStmtContext(info);

	/* Done */
	return CSemValueDefault;
}
#line 6753 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_202__(ILNode_Lock *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1429 "c_stmt.tc"
{
	CSemValue value;
	ILType *objectType = ILFindSystemType(info, "Object");

	/* Lock blocks must be at the statement level of the function */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`__lock__' used within expression statement"));
		return CSemValueDefault;
	}

	/* Perform semantic analysis on the lock expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(CSemIsError(value))
	{
		/* We've already reported an error for a bad expression,
		   so don't bother complaining about the situation again */
	}
	else if(!CSemIsRValue(value))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("invalid lock expression"));
	}
	else if(!CCanCoerce(CSemGetType(value), objectType))
	{
		CCErrorOnLine(yygetfilename(node->expr), yygetlinenum(node->expr),
					  _("no conversion from `%s' to `%s'"),
					  CTypeToName(info, CSemGetType(value)),
					  CTypeToName(info, objectType));
	}
	else
	{
		CCoerceNode(info, node->expr, &(node->expr), value, objectType);
	}

	/* Enter a "try" context */
	PushStmtContext(info, C_STMT_TRY);

	/* Perform semantic analysis on the lock statement body */
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);

	/* Exit from the "try" context */
	PopStmtContext(info);

	/* Done */
	return CSemValueDefault;
}
#line 6805 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_203__(ILNode_LocalVarDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6813 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_204__(ILNode_LocalConstDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6821 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_205__(ILNode_LineInfo *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1167 "c_stmt.tc"
{
	StmtSem(node->stmt, info, &(node->stmt), stmtLevel);
	return CSemValueDefault;
}
#line 6829 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_206__(ILNode_EventAddOrRemove *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6837 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_207__(ILNode_ClassDefn *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6845 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_208__(ILNode_ScopeChange *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6853 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_209__(ILNode_FieldDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6861 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_210__(ILNode_FieldDeclarator *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6869 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_211__(ILNode_EventDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6877 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_212__(ILNode_EventDeclarator *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6885 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_213__(ILNode_MethodDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6893 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_214__(ILNode_PropertyDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6901 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_215__(ILNode_EnumMemberDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6909 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_216__(ILNode_DelegateMemberDeclaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6917 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_217__(ILNode_FormalParameter *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6925 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_218__(ILNode_AttributeTree *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6933 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_219__(ILNode_AttributeSection *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6941 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_220__(ILNode_Attribute *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6949 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_221__(ILNode_AttrArgs *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6957 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_222__(ILNode_NamedArg *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6965 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_223__(ILNode_Declaration *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 6973 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_224__(ILNode_AsmStmt *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 409 "c_builtin.tc"
{
	/* There is nothing that needs to be done here */
	return CSemValueDefault;
}
#line 6981 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_225__(ILNode_CAssignArray *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 369 "c_ainit.tc"
{
	CSemValue value1;
	ILType *elemType;
	ILUInt32 arraySize;
	ILUInt32 initSize;
	ILNode *init;
	ILNode_ListIter iter;

	/* Perform semantic analysis on the destination expression.
	   We expect it to be either an l-value or a decayed r-value */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), 0);
	if(CSemIsDecayed(value1))
	{
		/* Un-decay the array type */
		CSemSetLValue(value1, CSemGetDecayedType(value1));
	}
	else if(!CSemIsLValue(value1))
	{
		if(!CSemIsError(value1))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid lvalue in assignment"));
		}
		return CSemValueError;
	}
	node->type = CSemGetType(value1);

	/* Determine the type of assignment based on the r-value */
	if(yyisa(node->expr2, ILNode_CString))
	{
		/* Assign the contents of a string */
		elemType = CTypeWithoutQuals(CTypeGetElemType(CSemGetType(value1)));
		if(elemType != ILType_Int8 && elemType != ILType_UInt8)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  	  _("invalid initializer"));
			return CSemValueError;
		}
		arraySize = CTypeGetNumElems(CSemGetType(value1));
		initSize = (ILUInt32)(((ILNode_CString *)(node->expr2))->len);
		if(initSize > arraySize)
		{
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
			  	    _("initializer-string for array of chars is too long"));
		}
	}
	else if(yyisa(node->expr2, ILNode_CWString))
	{
		/* Assign the contents of a wide string */
		elemType = CTypeWithoutQuals(CTypeGetElemType(CSemGetType(value1)));
		if(elemType != ILType_Int16 && elemType != ILType_UInt16 &&
		   elemType != ILType_Char)
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  	  _("invalid initializer"));
			return CSemValueError;
		}
		arraySize = CTypeGetNumElems(CSemGetType(value1));
		initSize = CGenWStringLength
					 (((ILNode_CWString *)(node->expr2))->str,
					  ((ILNode_CWString *)(node->expr2))->len);
		if(initSize > arraySize)
		{
			CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
		  	    _("initializer-string for array of wide chars is too long"));
		}
	}
	else if(yyisa(node->expr2, ILNode_CArrayInit))
	{
		/* Assign the contents of an array initializer to an array */
		init = ((ILNode_CArrayInit *)(node->expr2))->expr;
		ILNode_ListIter_Init(&iter, init);
		if(CTypeGetNumElems(CSemGetType(value1)) != IL_MAX_UINT32)
		{
			InitializerSemAnalysis(info, node->type, init, &iter);
			if(ILNode_ListIter_Next(&iter) != 0)
			{
				CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
								_("excess elements in array initializer"));
			}
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("array size is unknown at compile time"));
		}
	}
	else
	{
		/* The grammar already reported an error for this case */
		return CSemValueError;
	}

	/* Array assignment is used at the statement level of a function */
	return CSemValueDefault;
}
#line 7081 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_226__(ILNode_CAssignStruct *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 470 "c_ainit.tc"
{
	CSemValue value1;
	ILNode *init;
	ILNode_ListIter iter;

	/* Perform semantic analysis on the destination expression.
	   We expect it to be an l-value */
	value1 = ILNode_CSemAnalysis(node->expr1, info, &(node->expr1), 0);
	if(!CSemIsLValue(value1))
	{
		if(!CSemIsError(value1))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  _("invalid lvalue in assignment"));
		}
		return CSemValueError;
	}
	node->type = CSemGetType(value1);

	/* We must have a structure or union type at this point */
	if(!CTypeIsStruct(node->type) && !CTypeIsUnion(node->type))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("lvalue is not a structure"));
		return CSemValueError;
	}

	/* Perform semantic analysis on the structure value */
	init = ((ILNode_CArrayInit *)(node->expr2))->expr;
	ILNode_ListIter_Init(&iter, init);
	InitializerSemAnalysis(info, node->type, init, &iter);
	if(ILNode_ListIter_Next(&iter) != 0)
	{
		CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
						_("excess elements in structure initializer"));
	}

	/* Structure assignment is used at the statement level of a function */
	return CSemValueDefault;
}
#line 7125 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_227__(ILNode_CGotoPtr *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 1216 "c_stmt.tc"
{
	CSemValue value;

	/* We must use "goto *" at the statement level */
	if(!stmtLevel)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`goto *' used within expression statement"));
		return CSemValueDefault;
	}

	/* Perform semantic analysis on the expression */
	value = ILNode_CSemAnalysis(node->expr, info, &(node->expr), stmtLevel);
	if(!CSemIsRValue(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
						  "invalid goto expression value");
		}
		return CSemValueDefault;
	}
	if(!CTypeIsPointer(CSemGetType(value)))
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  "goto expression value must be of a pointer type");
		return CSemValueDefault;
	}

	/* Done */
	return CSemValueDefault;
}
#line 7161 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_228__(ILNode_Identifier *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 25 "c_lvalue.tc"
{
	/* Nothing to do here: the grammar should have replaced this
	   node with something more appropriate by now */
	return CSemValueError;
}
#line 7170 "c_semantics.c"

static CSemValue ILNode_CSemAnalysis_229__(ILNode_QualIdent *node, ILGenInfo * info, ILNode * * parent, int stmtLevel)
#line 115 "c_stubs.tc"
{
	/* Nothing to do here */
	return CSemValueError;
}
#line 7178 "c_semantics.c"

CSemValue ILNode_CSemAnalysis(ILNode * node__, ILGenInfo * info, ILNode * * parent, int stmtLevel)
{
	switch(node__->kind__)
	{
		case ILNode_CDeclarator_kind:
		case ILNode_CBitFieldDeclarator_kind:
		case ILNode_CInitDeclarator_kind:
		{
			return ILNode_CSemAnalysis_1__((ILNode_CDeclarator *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CSharpInvocation_kind:
		{
			return ILNode_CSemAnalysis_2__((ILNode_CSharpInvocation *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CAttribute_kind:
		{
			return ILNode_CSemAnalysis_3__((ILNode_CAttribute *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CAttributeValue_kind:
		{
			return ILNode_CSemAnalysis_4__((ILNode_CAttributeValue *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Null_kind:
		{
			return ILNode_CSemAnalysis_5__((ILNode_Null *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_NullPtr_kind:
		{
			return ILNode_CSemAnalysis_6__((ILNode_NullPtr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_True_kind:
		{
			return ILNode_CSemAnalysis_7__((ILNode_True *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_False_kind:
		{
			return ILNode_CSemAnalysis_8__((ILNode_False *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Int8_kind:
		{
			return ILNode_CSemAnalysis_9__((ILNode_Int8 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UInt8_kind:
		{
			return ILNode_CSemAnalysis_10__((ILNode_UInt8 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Int16_kind:
		{
			return ILNode_CSemAnalysis_11__((ILNode_Int16 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UInt16_kind:
		{
			return ILNode_CSemAnalysis_12__((ILNode_UInt16 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Char_kind:
		{
			return ILNode_CSemAnalysis_13__((ILNode_Char *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Int32_kind:
		{
			return ILNode_CSemAnalysis_14__((ILNode_Int32 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UInt32_kind:
		{
			return ILNode_CSemAnalysis_15__((ILNode_UInt32 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Int64_kind:
		{
			return ILNode_CSemAnalysis_16__((ILNode_Int64 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UInt64_kind:
		{
			return ILNode_CSemAnalysis_17__((ILNode_UInt64 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Int_kind:
		{
			return ILNode_CSemAnalysis_18__((ILNode_Int *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UInt_kind:
		{
			return ILNode_CSemAnalysis_19__((ILNode_UInt *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Float32_kind:
		{
			return ILNode_CSemAnalysis_20__((ILNode_Float32 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Float64_kind:
		{
			return ILNode_CSemAnalysis_21__((ILNode_Float64 *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Float_kind:
		{
			return ILNode_CSemAnalysis_22__((ILNode_Float *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Decimal_kind:
		{
			return ILNode_CSemAnalysis_23__((ILNode_Decimal *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CString_kind:
		{
			return ILNode_CSemAnalysis_24__((ILNode_CString *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CWString_kind:
		{
			return ILNode_CSemAnalysis_25__((ILNode_CWString *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_String_kind:
		{
			return ILNode_CSemAnalysis_26__((ILNode_String *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Deref_kind:
		{
			return ILNode_CSemAnalysis_27__((ILNode_Deref *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_StaticProperty_kind:
		{
			return ILNode_CSemAnalysis_28__((ILNode_StaticProperty *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_MemberProperty_kind:
		{
			return ILNode_CSemAnalysis_29__((ILNode_MemberProperty *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_IndexerAccess_kind:
		{
			return ILNode_CSemAnalysis_30__((ILNode_IndexerAccess *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CBitField_kind:
		{
			return ILNode_CSemAnalysis_31__((ILNode_CBitField *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AsIs_kind:
		case ILNode_MarkType_kind:
		{
			return ILNode_CSemAnalysis_32__((ILNode_AsIs *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Overflow_kind:
		{
			return ILNode_CSemAnalysis_33__((ILNode_Overflow *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_NoOverflow_kind:
		{
			return ILNode_CSemAnalysis_34__((ILNode_NoOverflow *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Pedantic_kind:
		{
			return ILNode_CSemAnalysis_35__((ILNode_Pedantic *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_NoPedantic_kind:
		{
			return ILNode_CSemAnalysis_36__((ILNode_NoPedantic *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_BaseAccess_kind:
		{
			return ILNode_CSemAnalysis_37__((ILNode_BaseAccess *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_BaseElement_kind:
		{
			return ILNode_CSemAnalysis_38__((ILNode_BaseElement *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_MemberAccess_kind:
		{
			return ILNode_CSemAnalysis_39__((ILNode_MemberAccess *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_DerefField_kind:
		{
			return ILNode_CSemAnalysis_40__((ILNode_DerefField *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_This_kind:
		{
			return ILNode_CSemAnalysis_41__((ILNode_This *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LocalVar_kind:
		{
			return ILNode_CSemAnalysis_42__((ILNode_LocalVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ArgumentVar_kind:
		{
			return ILNode_CSemAnalysis_43__((ILNode_ArgumentVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_RefArgumentVar_kind:
		{
			return ILNode_CSemAnalysis_44__((ILNode_RefArgumentVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_StaticField_kind:
		{
			return ILNode_CSemAnalysis_45__((ILNode_StaticField *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_MemberField_kind:
		{
			return ILNode_CSemAnalysis_46__((ILNode_MemberField *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CArrayAccess_kind:
		{
			return ILNode_CSemAnalysis_47__((ILNode_CArrayAccess *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ArrayAccess_kind:
		{
			return ILNode_CSemAnalysis_48__((ILNode_ArrayAccess *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CLocalVar_kind:
		{
			return ILNode_CSemAnalysis_49__((ILNode_CLocalVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CArgumentVar_kind:
		{
			return ILNode_CSemAnalysis_50__((ILNode_CArgumentVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CGlobalVar_kind:
		{
			return ILNode_CSemAnalysis_51__((ILNode_CGlobalVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CDerefField_kind:
		{
			return ILNode_CSemAnalysis_52__((ILNode_CDerefField *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CMemberField_kind:
		{
			return ILNode_CSemAnalysis_53__((ILNode_CMemberField *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CStaticField_kind:
		{
			return ILNode_CSemAnalysis_54__((ILNode_CStaticField *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CDeref_kind:
		{
			return ILNode_CSemAnalysis_55__((ILNode_CDeref *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LogicalNot_kind:
		{
			return ILNode_CSemAnalysis_56__((ILNode_LogicalNot *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Neg_kind:
		{
			return ILNode_CSemAnalysis_57__((ILNode_Neg *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UnaryPlus_kind:
		{
			return ILNode_CSemAnalysis_58__((ILNode_UnaryPlus *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Not_kind:
		{
			return ILNode_CSemAnalysis_59__((ILNode_Not *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserUnaryOp_kind:
		{
			return ILNode_CSemAnalysis_60__((ILNode_UserUnaryOp *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PreInc_kind:
		{
			return ILNode_CSemAnalysis_61__((ILNode_PreInc *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PreDec_kind:
		{
			return ILNode_CSemAnalysis_62__((ILNode_PreDec *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PostInc_kind:
		{
			return ILNode_CSemAnalysis_63__((ILNode_PostInc *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PostDec_kind:
		{
			return ILNode_CSemAnalysis_64__((ILNode_PostDec *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserPreInc_kind:
		{
			return ILNode_CSemAnalysis_65__((ILNode_UserPreInc *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserPreDec_kind:
		{
			return ILNode_CSemAnalysis_66__((ILNode_UserPreDec *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserPostInc_kind:
		{
			return ILNode_CSemAnalysis_67__((ILNode_UserPostInc *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserPostDec_kind:
		{
			return ILNode_CSemAnalysis_68__((ILNode_UserPostDec *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserIncOrDec_kind:
		{
			return ILNode_CSemAnalysis_69__((ILNode_UserIncOrDec *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PreIncPtr_kind:
		{
			return ILNode_CSemAnalysis_70__((ILNode_PreIncPtr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PreDecPtr_kind:
		{
			return ILNode_CSemAnalysis_71__((ILNode_PreDecPtr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PostIncPtr_kind:
		{
			return ILNode_CSemAnalysis_72__((ILNode_PostIncPtr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PostDecPtr_kind:
		{
			return ILNode_CSemAnalysis_73__((ILNode_PostDecPtr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CastSimple_kind:
		{
			return ILNode_CSemAnalysis_74__((ILNode_CastSimple *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CastType_kind:
		{
			return ILNode_CSemAnalysis_75__((ILNode_CastType *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserConversion_kind:
		{
			return ILNode_CSemAnalysis_76__((ILNode_UserConversion *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AddressOf_kind:
		{
			return ILNode_CSemAnalysis_77__((ILNode_AddressOf *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ToBool_kind:
		{
			return ILNode_CSemAnalysis_78__((ILNode_ToBool *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ToConst_kind:
		{
			return ILNode_CSemAnalysis_79__((ILNode_ToConst *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_VarArgExpand_kind:
		{
			return ILNode_CSemAnalysis_80__((ILNode_VarArgExpand *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_IsNull_kind:
		{
			return ILNode_CSemAnalysis_81__((ILNode_IsNull *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_IsNonNull_kind:
		{
			return ILNode_CSemAnalysis_82__((ILNode_IsNonNull *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_MakeRefAny_kind:
		{
			return ILNode_CSemAnalysis_83__((ILNode_MakeRefAny *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_RefType_kind:
		{
			return ILNode_CSemAnalysis_84__((ILNode_RefType *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ArrayLength_kind:
		{
			return ILNode_CSemAnalysis_85__((ILNode_ArrayLength *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ArrayInit_kind:
		{
			return ILNode_CSemAnalysis_86__((ILNode_ArrayInit *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_SizeOfExpr_kind:
		{
			return ILNode_CSemAnalysis_87__((ILNode_SizeOfExpr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_SetJmp_kind:
		{
			return ILNode_CSemAnalysis_88__((ILNode_SetJmp *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AllocA_kind:
		{
			return ILNode_CSemAnalysis_89__((ILNode_AllocA *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CToCSharpString_kind:
		{
			return ILNode_CSemAnalysis_90__((ILNode_CToCSharpString *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CArrayInit_kind:
		{
			return ILNode_CSemAnalysis_91__((ILNode_CArrayInit *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CBox_kind:
		{
			return ILNode_CSemAnalysis_92__((ILNode_CBox *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CopyComplex_kind:
		{
			return ILNode_CSemAnalysis_93__((ILNode_CopyComplex *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LogicalAnd_kind:
		{
			return ILNode_CSemAnalysis_94__((ILNode_LogicalAnd *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LogicalOr_kind:
		{
			return ILNode_CSemAnalysis_95__((ILNode_LogicalOr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserLogicalAnd_kind:
		{
			return ILNode_CSemAnalysis_96__((ILNode_UserLogicalAnd *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserLogicalOr_kind:
		{
			return ILNode_CSemAnalysis_97__((ILNode_UserLogicalOr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Add_kind:
		{
			return ILNode_CSemAnalysis_98__((ILNode_Add *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Sub_kind:
		{
			return ILNode_CSemAnalysis_99__((ILNode_Sub *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Mul_kind:
		{
			return ILNode_CSemAnalysis_100__((ILNode_Mul *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Div_kind:
		{
			return ILNode_CSemAnalysis_101__((ILNode_Div *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Rem_kind:
		{
			return ILNode_CSemAnalysis_102__((ILNode_Rem *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_And_kind:
		{
			return ILNode_CSemAnalysis_103__((ILNode_And *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Or_kind:
		{
			return ILNode_CSemAnalysis_104__((ILNode_Or *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Xor_kind:
		{
			return ILNode_CSemAnalysis_105__((ILNode_Xor *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Shl_kind:
		{
			return ILNode_CSemAnalysis_106__((ILNode_Shl *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Shr_kind:
		{
			return ILNode_CSemAnalysis_107__((ILNode_Shr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UShr_kind:
		{
			return ILNode_CSemAnalysis_108__((ILNode_UShr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_UserBinaryOp_kind:
		{
			return ILNode_CSemAnalysis_109__((ILNode_UserBinaryOp *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Concat_kind:
		{
			return ILNode_CSemAnalysis_110__((ILNode_Concat *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_DelegateAdd_kind:
		{
			return ILNode_CSemAnalysis_111__((ILNode_DelegateAdd *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_DelegateSub_kind:
		{
			return ILNode_CSemAnalysis_112__((ILNode_DelegateSub *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Assign_kind:
		{
			return ILNode_CSemAnalysis_113__((ILNode_Assign *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Eq_kind:
		{
			return ILNode_CSemAnalysis_114__((ILNode_Eq *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Ne_kind:
		{
			return ILNode_CSemAnalysis_115__((ILNode_Ne *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Lt_kind:
		{
			return ILNode_CSemAnalysis_116__((ILNode_Lt *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Le_kind:
		{
			return ILNode_CSemAnalysis_117__((ILNode_Le *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Gt_kind:
		{
			return ILNode_CSemAnalysis_118__((ILNode_Gt *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Ge_kind:
		{
			return ILNode_CSemAnalysis_119__((ILNode_Ge *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Comma_kind:
		{
			return ILNode_CSemAnalysis_120__((ILNode_Comma *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ArgList_kind:
		{
			return ILNode_CSemAnalysis_121__((ILNode_ArgList *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_RefValue_kind:
		{
			return ILNode_CSemAnalysis_122__((ILNode_RefValue *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CInvocationExpression_kind:
		{
			return ILNode_CSemAnalysis_123__((ILNode_CInvocationExpression *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_InvocationExpression_kind:
		{
			return ILNode_CSemAnalysis_124__((ILNode_InvocationExpression *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CDelete_kind:
		{
			return ILNode_CSemAnalysis_125__((ILNode_CDelete *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CSizeReleaseTempVar_kind:
		{
			return ILNode_CSemAnalysis_126__((ILNode_CSizeReleaseTempVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CSizeMax_kind:
		{
			return ILNode_CSemAnalysis_127__((ILNode_CSizeMax *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Conditional_kind:
		{
			return ILNode_CSemAnalysis_128__((ILNode_Conditional *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignAdd_kind:
		{
			return ILNode_CSemAnalysis_129__((ILNode_AssignAdd *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignSub_kind:
		{
			return ILNode_CSemAnalysis_130__((ILNode_AssignSub *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignMul_kind:
		{
			return ILNode_CSemAnalysis_131__((ILNode_AssignMul *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignDiv_kind:
		{
			return ILNode_CSemAnalysis_132__((ILNode_AssignDiv *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignRem_kind:
		{
			return ILNode_CSemAnalysis_133__((ILNode_AssignRem *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignAnd_kind:
		{
			return ILNode_CSemAnalysis_134__((ILNode_AssignAnd *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignOr_kind:
		{
			return ILNode_CSemAnalysis_135__((ILNode_AssignOr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignXor_kind:
		{
			return ILNode_CSemAnalysis_136__((ILNode_AssignXor *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignShl_kind:
		{
			return ILNode_CSemAnalysis_137__((ILNode_AssignShl *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignShr_kind:
		{
			return ILNode_CSemAnalysis_138__((ILNode_AssignShr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AssignUShr_kind:
		{
			return ILNode_CSemAnalysis_139__((ILNode_AssignUShr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_VarArgList_kind:
		{
			return ILNode_CSemAnalysis_140__((ILNode_VarArgList *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Argument_kind:
		{
			return ILNode_CSemAnalysis_141__((ILNode_Argument *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ArgArray_kind:
		{
			return ILNode_CSemAnalysis_142__((ILNode_ArgArray *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_As_kind:
		{
			return ILNode_CSemAnalysis_143__((ILNode_As *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Is_kind:
		{
			return ILNode_CSemAnalysis_144__((ILNode_Is *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Box_kind:
		{
			return ILNode_CSemAnalysis_145__((ILNode_Box *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Unbox_kind:
		{
			return ILNode_CSemAnalysis_146__((ILNode_Unbox *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_BoxingExpression_kind:
		{
			return ILNode_CSemAnalysis_147__((ILNode_BoxingExpression *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Error_kind:
		{
			return ILNode_CSemAnalysis_148__((ILNode_Error *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_NewExpression_kind:
		{
			return ILNode_CSemAnalysis_149__((ILNode_NewExpression *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ObjectCreationExpression_kind:
		{
			return ILNode_CSemAnalysis_150__((ILNode_ObjectCreationExpression *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_DelegateCreationExpression_kind:
		{
			return ILNode_CSemAnalysis_151__((ILNode_DelegateCreationExpression *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_DefaultConstructor_kind:
		{
			return ILNode_CSemAnalysis_152__((ILNode_DefaultConstructor *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_BaseInit_kind:
		{
			return ILNode_CSemAnalysis_153__((ILNode_BaseInit *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ThisInit_kind:
		{
			return ILNode_CSemAnalysis_154__((ILNode_ThisInit *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_NonStaticInit_kind:
		{
			return ILNode_CSemAnalysis_155__((ILNode_NonStaticInit *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_EmptyExpr_kind:
		{
			return ILNode_CSemAnalysis_156__((ILNode_EmptyExpr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_SizeOfType_kind:
		{
			return ILNode_CSemAnalysis_157__((ILNode_SizeOfType *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_VaStart_kind:
		{
			return ILNode_CSemAnalysis_158__((ILNode_VaStart *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_VaEnd_kind:
		{
			return ILNode_CSemAnalysis_159__((ILNode_VaEnd *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_VaArg_kind:
		{
			return ILNode_CSemAnalysis_160__((ILNode_VaArg *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_FunctionRef_kind:
		{
			return ILNode_CSemAnalysis_161__((ILNode_FunctionRef *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CLabelRef_kind:
		{
			return ILNode_CSemAnalysis_162__((ILNode_CLabelRef *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CSharpTypeOf_kind:
		{
			return ILNode_CSemAnalysis_163__((ILNode_CSharpTypeOf *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CTypeExpression_kind:
		{
			return ILNode_CSemAnalysis_164__((ILNode_CTypeExpression *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CNewObject_kind:
		{
			return ILNode_CSemAnalysis_165__((ILNode_CNewObject *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CNewArray_kind:
		{
			return ILNode_CSemAnalysis_166__((ILNode_CNewArray *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CSizeOfRaw_kind:
		{
			return ILNode_CSemAnalysis_167__((ILNode_CSizeOfRaw *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CSizeTempVar_kind:
		{
			return ILNode_CSemAnalysis_168__((ILNode_CSizeTempVar *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CSizeAlign_kind:
		{
			return ILNode_CSemAnalysis_169__((ILNode_CSizeAlign *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Compound_kind:
		{
			return ILNode_CSemAnalysis_170__((ILNode_Compound *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_SwitchSectList_kind:
		{
			return ILNode_CSemAnalysis_171__((ILNode_SwitchSectList *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CaseList_kind:
		{
			return ILNode_CSemAnalysis_172__((ILNode_CaseList *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_List_kind:
		case ILNode_CatchClauses_kind:
		{
			return ILNode_CSemAnalysis_173__((ILNode_List *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Empty_kind:
		{
			return ILNode_CSemAnalysis_174__((ILNode_Empty *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_If_kind:
		{
			return ILNode_CSemAnalysis_175__((ILNode_If *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_While_kind:
		{
			return ILNode_CSemAnalysis_176__((ILNode_While *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Do_kind:
		{
			return ILNode_CSemAnalysis_177__((ILNode_Do *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_For_kind:
		{
			return ILNode_CSemAnalysis_178__((ILNode_For *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Foreach_kind:
		{
			return ILNode_CSemAnalysis_179__((ILNode_Foreach *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ForeachString_kind:
		{
			return ILNode_CSemAnalysis_180__((ILNode_ForeachString *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ForeachCollection_kind:
		{
			return ILNode_CSemAnalysis_181__((ILNode_ForeachCollection *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Switch_kind:
		{
			return ILNode_CSemAnalysis_182__((ILNode_Switch *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Break_kind:
		{
			return ILNode_CSemAnalysis_183__((ILNode_Break *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LabelledBreak_kind:
		{
			return ILNode_CSemAnalysis_184__((ILNode_LabelledBreak *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Continue_kind:
		{
			return ILNode_CSemAnalysis_185__((ILNode_Continue *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LabelledContinue_kind:
		{
			return ILNode_CSemAnalysis_186__((ILNode_LabelledContinue *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Return_kind:
		{
			return ILNode_CSemAnalysis_187__((ILNode_Return *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ReturnExpr_kind:
		{
			return ILNode_CSemAnalysis_188__((ILNode_ReturnExpr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Goto_kind:
		{
			return ILNode_CSemAnalysis_189__((ILNode_Goto *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_GotoLabel_kind:
		{
			return ILNode_CSemAnalysis_190__((ILNode_GotoLabel *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_GotoCase_kind:
		{
			return ILNode_CSemAnalysis_191__((ILNode_GotoCase *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_GotoDefault_kind:
		{
			return ILNode_CSemAnalysis_192__((ILNode_GotoDefault *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_NewScope_kind:
		{
			return ILNode_CSemAnalysis_193__((ILNode_NewScope *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_SwitchSection_kind:
		{
			return ILNode_CSemAnalysis_194__((ILNode_SwitchSection *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CaseLabel_kind:
		{
			return ILNode_CSemAnalysis_195__((ILNode_CaseLabel *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_DefaultLabel_kind:
		{
			return ILNode_CSemAnalysis_196__((ILNode_DefaultLabel *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Throw_kind:
		{
			return ILNode_CSemAnalysis_197__((ILNode_Throw *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ThrowExpr_kind:
		{
			return ILNode_CSemAnalysis_198__((ILNode_ThrowExpr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Try_kind:
		{
			return ILNode_CSemAnalysis_199__((ILNode_Try *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CatchClause_kind:
		{
			return ILNode_CSemAnalysis_200__((ILNode_CatchClause *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_FinallyClause_kind:
		{
			return ILNode_CSemAnalysis_201__((ILNode_FinallyClause *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Lock_kind:
		{
			return ILNode_CSemAnalysis_202__((ILNode_Lock *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LocalVarDeclaration_kind:
		{
			return ILNode_CSemAnalysis_203__((ILNode_LocalVarDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LocalConstDeclaration_kind:
		{
			return ILNode_CSemAnalysis_204__((ILNode_LocalConstDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_LineInfo_kind:
		{
			return ILNode_CSemAnalysis_205__((ILNode_LineInfo *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_EventAddOrRemove_kind:
		{
			return ILNode_CSemAnalysis_206__((ILNode_EventAddOrRemove *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ClassDefn_kind:
		{
			return ILNode_CSemAnalysis_207__((ILNode_ClassDefn *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_ScopeChange_kind:
		{
			return ILNode_CSemAnalysis_208__((ILNode_ScopeChange *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_FieldDeclaration_kind:
		{
			return ILNode_CSemAnalysis_209__((ILNode_FieldDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_FieldDeclarator_kind:
		{
			return ILNode_CSemAnalysis_210__((ILNode_FieldDeclarator *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_EventDeclaration_kind:
		{
			return ILNode_CSemAnalysis_211__((ILNode_EventDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_EventDeclarator_kind:
		{
			return ILNode_CSemAnalysis_212__((ILNode_EventDeclarator *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_MethodDeclaration_kind:
		{
			return ILNode_CSemAnalysis_213__((ILNode_MethodDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_PropertyDeclaration_kind:
		{
			return ILNode_CSemAnalysis_214__((ILNode_PropertyDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_EnumMemberDeclaration_kind:
		{
			return ILNode_CSemAnalysis_215__((ILNode_EnumMemberDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_DelegateMemberDeclaration_kind:
		{
			return ILNode_CSemAnalysis_216__((ILNode_DelegateMemberDeclaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_FormalParameter_kind:
		{
			return ILNode_CSemAnalysis_217__((ILNode_FormalParameter *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AttributeTree_kind:
		{
			return ILNode_CSemAnalysis_218__((ILNode_AttributeTree *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AttributeSection_kind:
		{
			return ILNode_CSemAnalysis_219__((ILNode_AttributeSection *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Attribute_kind:
		{
			return ILNode_CSemAnalysis_220__((ILNode_Attribute *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AttrArgs_kind:
		{
			return ILNode_CSemAnalysis_221__((ILNode_AttrArgs *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_NamedArg_kind:
		{
			return ILNode_CSemAnalysis_222__((ILNode_NamedArg *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Declaration_kind:
		case ILNode_ProxyDeclaration_kind:
		{
			return ILNode_CSemAnalysis_223__((ILNode_Declaration *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_AsmStmt_kind:
		{
			return ILNode_CSemAnalysis_224__((ILNode_AsmStmt *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CAssignArray_kind:
		{
			return ILNode_CSemAnalysis_225__((ILNode_CAssignArray *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CAssignStruct_kind:
		{
			return ILNode_CSemAnalysis_226__((ILNode_CAssignStruct *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_CGotoPtr_kind:
		{
			return ILNode_CSemAnalysis_227__((ILNode_CGotoPtr *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_Identifier_kind:
		{
			return ILNode_CSemAnalysis_228__((ILNode_Identifier *)node__, info, parent, stmtLevel);
		}
		break;

		case ILNode_QualIdent_kind:
		{
			return ILNode_CSemAnalysis_229__((ILNode_QualIdent *)node__, info, parent, stmtLevel);
		}
		break;

		default: break;
	}
	return (CSemValueDefault);
}

static CAddress ILNode_CGenAddress_1__(ILNode_LValueNoRef *node, ILGenInfo * info)
#line 611 "c_defs.tc"
{
	return CAddressDefault;
}
#line 8573 "c_semantics.c"

static CAddress ILNode_CGenAddress_2__(ILNode_AsIs *node, ILGenInfo * info)
#line 2055 "c_oper.tc"
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		return ILNode_CGenAddress((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		return CAddressDefault;
	}
}
#line 8587 "c_semantics.c"

static CAddress ILNode_CGenAddress_3__(ILNode_Overflow *node, ILGenInfo * info)
#line 2070 "c_oper.tc"
{
	CAddress value;
	int overflow = info->overflowInsns;
	int changed = info->overflowChanged;
	info->overflowInsns = 1;
	info->overflowChanged = 1;
	if(yyisa(node->expr, ILNode_LValue))
	{
		value = ILNode_CGenAddress((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		value = CAddressDefault;
	}
	info->overflowInsns = overflow;
	info->overflowChanged = changed;
	return value;
}
#line 8609 "c_semantics.c"

static CAddress ILNode_CGenAddress_4__(ILNode_NoOverflow *node, ILGenInfo * info)
#line 2093 "c_oper.tc"
{
	CAddress value;
	int overflow = info->overflowInsns;
	int changed = info->overflowChanged;
	info->overflowInsns = 0;
	info->overflowChanged = 1;
	if(yyisa(node->expr, ILNode_LValue))
	{
		value = ILNode_CGenAddress((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		value = CAddressDefault;
	}
	info->overflowInsns = overflow;
	info->overflowChanged = changed;
	return value;
}
#line 8631 "c_semantics.c"

static CAddress ILNode_CGenAddress_5__(ILNode_Pedantic *node, ILGenInfo * info)
#line 2055 "c_oper.tc"
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		return ILNode_CGenAddress((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		return CAddressDefault;
	}
}
#line 8645 "c_semantics.c"

static CAddress ILNode_CGenAddress_6__(ILNode_NoPedantic *node, ILGenInfo * info)
#line 2055 "c_oper.tc"
{
	if(yyisa(node->expr, ILNode_LValue))
	{
		return ILNode_CGenAddress((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		return CAddressDefault;
	}
}
#line 8659 "c_semantics.c"

static CAddress ILNode_CGenAddress_7__(ILNode_BaseAccess *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8667 "c_semantics.c"

static CAddress ILNode_CGenAddress_8__(ILNode_BaseElement *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8675 "c_semantics.c"

static CAddress ILNode_CGenAddress_9__(ILNode_MemberAccess *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8683 "c_semantics.c"

static CAddress ILNode_CGenAddress_10__(ILNode_DerefField *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8691 "c_semantics.c"

static CAddress ILNode_CGenAddress_11__(ILNode_This *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8699 "c_semantics.c"

static CAddress ILNode_CGenAddress_12__(ILNode_LocalVar *node, ILGenInfo * info)
#line 1029 "c_lvalue.tc"
{
	/* These node types aren't used by the grammar */
	return CAddressDefault;
}
#line 8707 "c_semantics.c"

static CAddress ILNode_CGenAddress_13__(ILNode_ArgumentVar *node, ILGenInfo * info)
#line 1029 "c_lvalue.tc"
{
	/* These node types aren't used by the grammar */
	return CAddressDefault;
}
#line 8715 "c_semantics.c"

static CAddress ILNode_CGenAddress_14__(ILNode_RefArgumentVar *node, ILGenInfo * info)
#line 1416 "c_lvalue.tc"
{
	CAddress addr;
	ILGenLoadArg(info, node->index);
	ILGenAdjust(info, 1);
	addr.ptrOnStack = 1;
	addr.offset = 0;
	return addr;
}
#line 8727 "c_semantics.c"

static CAddress ILNode_CGenAddress_15__(ILNode_StaticField *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8735 "c_semantics.c"

static CAddress ILNode_CGenAddress_16__(ILNode_MemberField *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8743 "c_semantics.c"

static CAddress ILNode_CGenAddress_17__(ILNode_CArrayAccess *node, ILGenInfo * info)
#line 1861 "c_lvalue.tc"
{
	CAddress addr;
	ILEvalValue value;
	ILInt64 temp;
	CTypeLayoutInfo layout;

	/* Get the address of the array start */
	if(ILNode_EvalConst(node->array, info, &value) &&
	   value.valueType == ILMachineType_UnmanagedPtr)
	{
		addr.ptrOnStack = 0;
		addr.offset = value.un.i4Value;
	}
	else
	{
		ILNode_GenValue(node->array, info);
		addr.ptrOnStack = 1;
		addr.offset = 0;
	}

	/* Adjust the pointer by the array index */
	CTypeGetLayoutInfo(node->elemType, &layout);
	if(layout.category == C_TYPECAT_FIXED &&
	   ILNode_EvalConst(node->indices, info, &value))
	{
		/* Adjust the address offset by a constant index */
		temp = (ILInt64)(layout.size);
		switch(value.valueType)
		{
			case ILMachineType_Int8:
			case ILMachineType_UInt8:
			case ILMachineType_Int16:
			case ILMachineType_UInt16:
			case ILMachineType_Char:
			case ILMachineType_Int32:
			{
				temp *= (ILInt64)(value.un.i4Value);
			}
			break;

			case ILMachineType_UInt32:
			{
				temp *= (ILInt64)(ILUInt32)(value.un.i4Value);
			}
			break;

			case ILMachineType_Int64:
			{
				if(value.un.i8Value >= (ILInt64)IL_MIN_INT32 &&
				   value.un.i8Value <= (ILInt64)IL_MAX_INT32)
				{
					temp *= value.un.i8Value;
				}
				else
				{
					goto force;
				}
			}
			break;

			case ILMachineType_UInt64:
			{
				if(value.un.i8Value >= 0 &&
				   value.un.i8Value <= (ILInt64)IL_MAX_INT32)
				{
					temp *= value.un.i8Value;
				}
				else
				{
					goto force;
				}
			}
			break;

			default: goto force;
		}
		temp += (ILInt64)(addr.offset);
		if(temp < (ILInt64)IL_MIN_INT32 || temp > (ILInt64)IL_MAX_INT32)
		{
			goto force;
		}
		addr.offset = (ILInt32)temp;
	}
	else
	{
	force:
		/* Force the pointer onto the stack */
		if(!(addr.ptrOnStack) && addr.offset != 0)
		{
			ILGenUIntNative(info, addr.offset);
			ILGenAdjust(info, 1);
			addr.ptrOnStack = 1;
			addr.offset = 0;
		}

		/* Push the array index value onto the stack */
		ILGenCast(info, ILNode_GenValue(node->indices, info),
				  ILMachineType_NativeInt);
		ILGenAdjust(info, 1);

		/* Multiply the array index by the element size */
		if(layout.category == C_TYPECAT_FIXED)
		{
			switch(layout.size)
			{
				case 1:		break;

				case 2:
				{
					ILGenSimple(info, IL_OP_LDC_I4_1);
					ILGenSimple(info, IL_OP_SHL);
					ILGenExtend(info, 1);
				}
				break;

				case 4:
				{
					ILGenSimple(info, IL_OP_LDC_I4_2);
					ILGenSimple(info, IL_OP_SHL);
					ILGenExtend(info, 1);
				}
				break;

				case 8:
				{
					ILGenSimple(info, IL_OP_LDC_I4_3);
					ILGenSimple(info, IL_OP_SHL);
					ILGenExtend(info, 1);
				}
				break;

				default:
				{
					ILGenIntNative(info, (ILInt32)(layout.size));
					ILGenSimple(info, IL_OP_MUL);
					ILGenExtend(info, 1);
				}
				break;
			}
		}
		else
		{
			CGenSizeOf(info, node->elemType);
			ILGenSimple(info, IL_OP_CONV_U);
			ILGenSimple(info, IL_OP_MUL);
			ILGenAdjust(info, -1);
		}

		/* Add the computed offset to the pointer */
		if(addr.ptrOnStack)
		{
			ILGenSimple(info, IL_OP_ADD);
			ILGenAdjust(info, -1);
		}
		else
		{
			/* The original pointer was NULL, so there is no need to add */
			addr.ptrOnStack = 1;
		}
	}

	/* Return the final address to the caller */
	return addr;
}
#line 8911 "c_semantics.c"

static CAddress ILNode_CGenAddress_18__(ILNode_ArrayAccess *node, ILGenInfo * info)
#line 131 "c_stubs.tc"
{
	/* Nothing to do here */
	return CAddressDefault;
}
#line 8919 "c_semantics.c"

static CAddress ILNode_CGenAddress_19__(ILNode_CLocalVar *node, ILGenInfo * info)
#line 1117 "c_lvalue.tc"
{
	CAddress addr;
	if(!CTypeIsComplex(node->type))
	{
		ILGenLoadLocalAddr(info, node->index);
	}
	else
	{
		ILGenLoadLocal(info, node->index);
	}
	ILGenAdjust(info, 1);
	addr.ptrOnStack = 1;
	addr.offset = 0;
	return addr;
}
#line 8938 "c_semantics.c"

static CAddress ILNode_CGenAddress_20__(ILNode_CArgumentVar *node, ILGenInfo * info)
#line 1376 "c_lvalue.tc"
{
	CAddress addr;
	if(!CTypeIsComplex(node->type))
	{
		/* Ordinary types are passed by value, so take the arg address */
		ILGenLoadArgAddr(info, node->index);
	}
	else
	{
		/* The argument is passed by reference, so push it directly */
		ILGenLoadArg(info, node->index);
	}
	ILGenAdjust(info, 1);
	addr.ptrOnStack = 1;
	addr.offset = 0;
	return addr;
}
#line 8959 "c_semantics.c"

static CAddress ILNode_CGenAddress_21__(ILNode_CGlobalVar *node, ILGenInfo * info)
#line 1617 "c_lvalue.tc"
{
	CAddress addr;
	ILNode_GenRef((ILNode_LValue *)node, info);
	addr.ptrOnStack = 1;
	addr.offset = 0;
	return addr;
}
#line 8970 "c_semantics.c"

static CAddress ILNode_CGenAddress_22__(ILNode_CDerefField *node, ILGenInfo * info)
#line 541 "c_lvalue.tc"
{
	CAddress addr;
	if(CTypeIsComplex(node->ownerType))
	{
		/* Complex types need special adjustment for their fields */
		if(yyisa(node, ILNode_CMemberField))
		{
			CGenAddress(info, node->expr);
		}
		else
		{
			ILNode_GenValue(node->expr, info);
		}
		CAddComplexFieldOffset(info, node->ownerType, node->field);
		addr.ptrOnStack = 1;
		addr.offset = 0;
	}
	else
	{
		/* We need to use "ldflda" to find the field's dynamic address */
		if(yyisa(node, ILNode_CMemberField))
		{
			CGenAddress(info, node->expr);
		}
		else
		{
			ILNode_GenValue(node->expr, info);
		}
		ILGenFieldRef(info, IL_OP_LDFLDA, node->field);
		addr.ptrOnStack = 1;
		addr.offset = 0;
	}
	return addr;
}
#line 9008 "c_semantics.c"

static CAddress ILNode_CGenAddress_23__(ILNode_CMemberField *node, ILGenInfo * info)
#line 541 "c_lvalue.tc"
{
	CAddress addr;
	if(CTypeIsComplex(node->ownerType))
	{
		/* Complex types need special adjustment for their fields */
		if(yyisa(node, ILNode_CMemberField))
		{
			CGenAddress(info, node->expr);
		}
		else
		{
			ILNode_GenValue(node->expr, info);
		}
		CAddComplexFieldOffset(info, node->ownerType, node->field);
		addr.ptrOnStack = 1;
		addr.offset = 0;
	}
	else
	{
		/* We need to use "ldflda" to find the field's dynamic address */
		if(yyisa(node, ILNode_CMemberField))
		{
			CGenAddress(info, node->expr);
		}
		else
		{
			ILNode_GenValue(node->expr, info);
		}
		ILGenFieldRef(info, IL_OP_LDFLDA, node->field);
		addr.ptrOnStack = 1;
		addr.offset = 0;
	}
	return addr;
}
#line 9046 "c_semantics.c"

static CAddress ILNode_CGenAddress_24__(ILNode_CStaticField *node, ILGenInfo * info)
#line 897 "c_lvalue.tc"
{
	CAddress addr;
	ILGenFieldRef(info, IL_OP_LDSFLDA, node->field);
	addr.ptrOnStack = 1;
	addr.offset = 0;
	return addr;
}
#line 9057 "c_semantics.c"

static CAddress ILNode_CGenAddress_25__(ILNode_CDeref *node, ILGenInfo * info)
#line 2269 "c_lvalue.tc"
{
	CAddress addr;
	ILNode_GenValue(node->expr, info);
	addr.ptrOnStack = 1;
	addr.offset = 0;
	return addr;
}
#line 9068 "c_semantics.c"

CAddress ILNode_CGenAddress(ILNode_LValue * node__, ILGenInfo * info)
{
	switch(node__->kind__)
	{
		case ILNode_LValueNoRef_kind:
		case ILNode_Deref_kind:
		case ILNode_StaticProperty_kind:
		case ILNode_MemberProperty_kind:
		case ILNode_IndexerAccess_kind:
		case ILNode_CBitField_kind:
		{
			return ILNode_CGenAddress_1__((ILNode_LValueNoRef *)node__, info);
		}
		break;

		case ILNode_AsIs_kind:
		case ILNode_MarkType_kind:
		{
			return ILNode_CGenAddress_2__((ILNode_AsIs *)node__, info);
		}
		break;

		case ILNode_Overflow_kind:
		{
			return ILNode_CGenAddress_3__((ILNode_Overflow *)node__, info);
		}
		break;

		case ILNode_NoOverflow_kind:
		{
			return ILNode_CGenAddress_4__((ILNode_NoOverflow *)node__, info);
		}
		break;

		case ILNode_Pedantic_kind:
		{
			return ILNode_CGenAddress_5__((ILNode_Pedantic *)node__, info);
		}
		break;

		case ILNode_NoPedantic_kind:
		{
			return ILNode_CGenAddress_6__((ILNode_NoPedantic *)node__, info);
		}
		break;

		case ILNode_BaseAccess_kind:
		{
			return ILNode_CGenAddress_7__((ILNode_BaseAccess *)node__, info);
		}
		break;

		case ILNode_BaseElement_kind:
		{
			return ILNode_CGenAddress_8__((ILNode_BaseElement *)node__, info);
		}
		break;

		case ILNode_MemberAccess_kind:
		{
			return ILNode_CGenAddress_9__((ILNode_MemberAccess *)node__, info);
		}
		break;

		case ILNode_DerefField_kind:
		{
			return ILNode_CGenAddress_10__((ILNode_DerefField *)node__, info);
		}
		break;

		case ILNode_This_kind:
		{
			return ILNode_CGenAddress_11__((ILNode_This *)node__, info);
		}
		break;

		case ILNode_LocalVar_kind:
		{
			return ILNode_CGenAddress_12__((ILNode_LocalVar *)node__, info);
		}
		break;

		case ILNode_ArgumentVar_kind:
		{
			return ILNode_CGenAddress_13__((ILNode_ArgumentVar *)node__, info);
		}
		break;

		case ILNode_RefArgumentVar_kind:
		{
			return ILNode_CGenAddress_14__((ILNode_RefArgumentVar *)node__, info);
		}
		break;

		case ILNode_StaticField_kind:
		{
			return ILNode_CGenAddress_15__((ILNode_StaticField *)node__, info);
		}
		break;

		case ILNode_MemberField_kind:
		{
			return ILNode_CGenAddress_16__((ILNode_MemberField *)node__, info);
		}
		break;

		case ILNode_CArrayAccess_kind:
		{
			return ILNode_CGenAddress_17__((ILNode_CArrayAccess *)node__, info);
		}
		break;

		case ILNode_ArrayAccess_kind:
		{
			return ILNode_CGenAddress_18__((ILNode_ArrayAccess *)node__, info);
		}
		break;

		case ILNode_CLocalVar_kind:
		{
			return ILNode_CGenAddress_19__((ILNode_CLocalVar *)node__, info);
		}
		break;

		case ILNode_CArgumentVar_kind:
		{
			return ILNode_CGenAddress_20__((ILNode_CArgumentVar *)node__, info);
		}
		break;

		case ILNode_CGlobalVar_kind:
		{
			return ILNode_CGenAddress_21__((ILNode_CGlobalVar *)node__, info);
		}
		break;

		case ILNode_CDerefField_kind:
		{
			return ILNode_CGenAddress_22__((ILNode_CDerefField *)node__, info);
		}
		break;

		case ILNode_CMemberField_kind:
		{
			return ILNode_CGenAddress_23__((ILNode_CMemberField *)node__, info);
		}
		break;

		case ILNode_CStaticField_kind:
		{
			return ILNode_CGenAddress_24__((ILNode_CStaticField *)node__, info);
		}
		break;

		case ILNode_CDeref_kind:
		{
			return ILNode_CGenAddress_25__((ILNode_CDeref *)node__, info);
		}
		break;

		default: break;
	}
	return (CAddressDefault);
}

static void ILNode_CollectCases_1__(ILNode_Compound *node, ILGenInfo * info, ILNode * list)
#line 165 "c_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *stmt;
	ILNode_ListIter_Init(&iter, node);
	while((stmt = ILNode_ListIter_Next(&iter)) != 0)
	{
		ILNode_CollectCases(stmt, info, list);
	}
}
#line 9246 "c_semantics.c"

static void ILNode_CollectCases_2__(ILNode_List *node, ILGenInfo * info, ILNode * list)
#line 165 "c_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *stmt;
	ILNode_ListIter_Init(&iter, node);
	while((stmt = ILNode_ListIter_Next(&iter)) != 0)
	{
		ILNode_CollectCases(stmt, info, list);
	}
}
#line 9259 "c_semantics.c"

static void ILNode_CollectCases_3__(ILNode_If *node, ILGenInfo * info, ILNode * list)
#line 190 "c_stmt.tc"
{
	if(node->thenClause)
	{
		ILNode_CollectCases(node->thenClause, info, list);
	}
	if(node->elseClause)
	{
		ILNode_CollectCases(node->thenClause, info, list);
	}
}
#line 9273 "c_semantics.c"

static void ILNode_CollectCases_4__(ILNode_While *node, ILGenInfo * info, ILNode * list)
#line 219 "c_stmt.tc"
{
	ILNode_CollectCases(node->stmt, info, list);
}
#line 9280 "c_semantics.c"

static void ILNode_CollectCases_5__(ILNode_Do *node, ILGenInfo * info, ILNode * list)
#line 219 "c_stmt.tc"
{
	ILNode_CollectCases(node->stmt, info, list);
}
#line 9287 "c_semantics.c"

static void ILNode_CollectCases_6__(ILNode_For *node, ILGenInfo * info, ILNode * list)
#line 219 "c_stmt.tc"
{
	ILNode_CollectCases(node->stmt, info, list);
}
#line 9294 "c_semantics.c"

static void ILNode_CollectCases_7__(ILNode_NewScope *node, ILGenInfo * info, ILNode * list)
#line 720 "c_stmt.tc"
{
	if(node->stmt)
	{
		ILNode_CollectCases(node->stmt, info, list);
	}
}
#line 9304 "c_semantics.c"

static void ILNode_CollectCases_8__(ILNode_CaseLabel *node, ILGenInfo * info, ILNode * list)
#line 1203 "c_stmt.tc"
{
	ILNode *section;
	ILNode *caseList = ILNode_CaseList_create();
	ILNode_List_Add(caseList, (ILNode *)node);
	section = ILNode_SwitchSection_create(caseList, ILNode_Empty_create());
	node->section = (ILNode_SwitchSection *)section;
	ILNode_List_Add(list, section);
}
#line 9316 "c_semantics.c"

static void ILNode_CollectCases_9__(ILNode_DefaultLabel *node, ILGenInfo * info, ILNode * list)
#line 1203 "c_stmt.tc"
{
	ILNode *section;
	ILNode *caseList = ILNode_CaseList_create();
	ILNode_List_Add(caseList, (ILNode *)node);
	section = ILNode_SwitchSection_create(caseList, ILNode_Empty_create());
	node->section = (ILNode_SwitchSection *)section;
	ILNode_List_Add(list, section);
}
#line 9328 "c_semantics.c"

static void ILNode_CollectCases_10__(ILNode *node, ILGenInfo * info, ILNode * list)
#line 619 "c_defs.tc"
{
	/* Nothing to do here */
}
#line 9335 "c_semantics.c"

void ILNode_CollectCases(ILNode * node__, ILGenInfo * info, ILNode * list)
{
	switch(node__->kind__)
	{
		case ILNode_Compound_kind:
		{
			ILNode_CollectCases_1__((ILNode_Compound *)node__, info, list);
		}
		break;

		case ILNode_List_kind:
		case ILNode_SwitchSectList_kind:
		case ILNode_CaseList_kind:
		case ILNode_CatchClauses_kind:
		{
			ILNode_CollectCases_2__((ILNode_List *)node__, info, list);
		}
		break;

		case ILNode_If_kind:
		{
			ILNode_CollectCases_3__((ILNode_If *)node__, info, list);
		}
		break;

		case ILNode_While_kind:
		{
			ILNode_CollectCases_4__((ILNode_While *)node__, info, list);
		}
		break;

		case ILNode_Do_kind:
		{
			ILNode_CollectCases_5__((ILNode_Do *)node__, info, list);
		}
		break;

		case ILNode_For_kind:
		{
			ILNode_CollectCases_6__((ILNode_For *)node__, info, list);
		}
		break;

		case ILNode_NewScope_kind:
		{
			ILNode_CollectCases_7__((ILNode_NewScope *)node__, info, list);
		}
		break;

		case ILNode_CaseLabel_kind:
		{
			ILNode_CollectCases_8__((ILNode_CaseLabel *)node__, info, list);
		}
		break;

		case ILNode_DefaultLabel_kind:
		{
			ILNode_CollectCases_9__((ILNode_DefaultLabel *)node__, info, list);
		}
		break;

		case ILNode_kind:
		case ILNode_Dummy_kind:
		case ILNode_CDeclarator_kind:
		case ILNode_CBitFieldDeclarator_kind:
		case ILNode_CInitDeclarator_kind:
		case ILNode_CSharpInvocation_kind:
		case ILNode_CAttribute_kind:
		case ILNode_CAttributeValue_kind:
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
		case ILNode_CString_kind:
		case ILNode_CWString_kind:
		case ILNode_LValue_kind:
		case ILNode_LValueNoRef_kind:
		case ILNode_Deref_kind:
		case ILNode_StaticProperty_kind:
		case ILNode_MemberProperty_kind:
		case ILNode_IndexerAccess_kind:
		case ILNode_CBitField_kind:
		case ILNode_LValueUnaryExpr_kind:
		case ILNode_LValueNoRefUnaryExpr_kind:
		case ILNode_AsIs_kind:
		case ILNode_MarkType_kind:
		case ILNode_Overflow_kind:
		case ILNode_NoOverflow_kind:
		case ILNode_Pedantic_kind:
		case ILNode_NoPedantic_kind:
		case ILNode_BaseAccess_kind:
		case ILNode_BaseElement_kind:
		case ILNode_LValueBinaryExpr_kind:
		case ILNode_MemberAccess_kind:
		case ILNode_DerefField_kind:
		case ILNode_This_kind:
		case ILNode_LocalVar_kind:
		case ILNode_ArgumentVar_kind:
		case ILNode_RefArgumentVar_kind:
		case ILNode_StaticField_kind:
		case ILNode_MemberField_kind:
		case ILNode_ArrayAccess_kind:
		case ILNode_CArrayAccess_kind:
		case ILNode_CLocalVar_kind:
		case ILNode_CArgumentVar_kind:
		case ILNode_CGlobalVar_kind:
		case ILNode_CFieldAccess_kind:
		case ILNode_CDerefField_kind:
		case ILNode_CMemberField_kind:
		case ILNode_CStaticField_kind:
		case ILNode_CDeref_kind:
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
		case ILNode_VarArgExpand_kind:
		case ILNode_IsNull_kind:
		case ILNode_IsNonNull_kind:
		case ILNode_MakeRefAny_kind:
		case ILNode_RefType_kind:
		case ILNode_ArrayLength_kind:
		case ILNode_ArrayInit_kind:
		case ILNode_SizeOfExpr_kind:
		case ILNode_SetJmp_kind:
		case ILNode_AllocA_kind:
		case ILNode_CToCSharpString_kind:
		case ILNode_CArrayInit_kind:
		case ILNode_CBox_kind:
		case ILNode_CopyComplex_kind:
		case ILNode_BinaryExpression_kind:
		case ILNode_DummyBinaryExpr_kind:
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
		case ILNode_CInvocationExpression_kind:
		case ILNode_CDelete_kind:
		case ILNode_CSizeReleaseTempVar_kind:
		case ILNode_CSizeMax_kind:
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
		case ILNode_SizeOfType_kind:
		case ILNode_VaStart_kind:
		case ILNode_VaEnd_kind:
		case ILNode_VaArg_kind:
		case ILNode_FunctionRef_kind:
		case ILNode_CLabelRef_kind:
		case ILNode_CSharpTypeOf_kind:
		case ILNode_CTypeExpression_kind:
		case ILNode_CNewObject_kind:
		case ILNode_CNewArray_kind:
		case ILNode_CSizeOfRaw_kind:
		case ILNode_CSizeTempVar_kind:
		case ILNode_CSizeAlign_kind:
		case ILNode_Statement_kind:
		case ILNode_Empty_kind:
		case ILNode_LabelledStatement_kind:
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
		case ILNode_SwitchSection_kind:
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
		case ILNode_AsmStmt_kind:
		case ILNode_CAssignArray_kind:
		case ILNode_CAssignStruct_kind:
		case ILNode_CGotoPtr_kind:
		case ILNode_Identifier_kind:
		case ILNode_QualIdent_kind:
		{
			ILNode_CollectCases_10__((ILNode *)node__, info, list);
		}
		break;

		default: break;
	}
}

#line 471 "c_const.tc"


/*
 * Temporary storage for the string constant pool.
 */
#define	C_STRBUF_SIZE	1024
typedef struct _tagStringBuffer
{
	struct _tagStringBuffer *next;
	int used;
	int size;
	char buffer[1];

} StringBuffer;
typedef struct
{
	const char *str;
	int len;
	int isWide;
	ILUInt32 index;

} StringHashEntry;
static unsigned long poolSize = 0;
static StringBuffer *poolFirst = 0;
static StringBuffer *poolLast = 0;
static ILHashTable  *poolHash = 0;
static ILUInt32      poolIndex = 0;

/*
 * Compute the hash value for a string pool element.
 */
static unsigned long PoolHash_Compute(const StringHashEntry *elem)
{
	return ILHashString(0, elem->str, elem->len);
}

/*
 * Determine if we have a match between and element and a key.
 */
static int PoolHash_Match(const StringHashEntry *elem,
						  const StringHashEntry *key)
{
	if(elem->len != key->len)
	{
		return 0;
	}
	if(elem->isWide != key->isWide)
	{
		return 0;
	}
	return (elem->len == 0 || !ILMemCmp(elem->str, key->str, elem->len));
}

static ILUInt32 GenStringIndex(ILGenInfo *info, const char *str,
							   int len, int isWide)
{
	StringHashEntry *entry;
	StringHashEntry key;
	StringBuffer *buf;
	int size;

	/* Look up the string in the hash table */
	if(poolHash)
	{
		key.str = str;
		key.len = len;
		key.isWide = isWide;
		entry = ILHashFindType(poolHash, &key, StringHashEntry);
		if(entry)
		{
			return entry->index;
		}
	}

	/* Add the string to the pool */
	if(!poolLast || (poolLast->used + len + 1) > poolLast->size)
	{
		size = len + 1;
		if(size < C_STRBUF_SIZE)
		{
			size = C_STRBUF_SIZE;
		}
		buf = (StringBuffer *)ILMalloc(sizeof(StringBuffer) + size - 1);
		if(!buf)
		{
			ILGenOutOfMemory(info);
		}
		buf->next = 0;
		if(poolLast)
		{
			poolLast->next = buf;
		}
		else
		{
			poolFirst = buf;
		}
		poolLast = buf;
		buf->used = 0;
		buf->size = size;
	}
	ILMemCpy(poolLast->buffer + poolLast->used, str, len);
	poolLast->buffer[poolLast->used + len] = '\0';
	str = poolLast->buffer + poolLast->used;
	poolLast->used += len + 1;
	poolSize += (unsigned long)(len + 1);

	/* Add the string to the hash table */
	if(!poolHash)
	{
		poolHash = ILHashCreate(0, (ILHashComputeFunc)PoolHash_Compute,
							    (ILHashKeyComputeFunc)PoolHash_Compute,
								(ILHashMatchFunc)PoolHash_Match,
								(ILHashFreeFunc)ILFree);
		if(!poolHash)
		{
			ILGenOutOfMemory(info);
		}
	}
	entry = (StringHashEntry *)ILMalloc(sizeof(StringHashEntry));
	if(!entry)
	{
		ILGenOutOfMemory(info);
	}
	entry->str = str;
	entry->len = len;
	entry->isWide = isWide;
	entry->index = poolIndex;
	if(!ILHashAdd(poolHash, entry))
	{
		ILGenOutOfMemory(info);
	}

	/* Return the index to the caller */
	return poolIndex++;
}

ILUInt32 CGenStringIndex(ILGenInfo *info, const char *str, int len)
{
	return GenStringIndex(info, str, len, 0);
}

ILUInt32 CGenWStringLength(const char *str, int len)
{
	unsigned long ch;
	ILUInt32 slen = 0;
	int posn = 0;
	while(posn < len)
	{
		ch = ILUTF8ReadChar(str, len, &posn);
		if(ch < 0x10000)
		{
			++slen;
		}
		else
		{
			slen += 2;
		}
	}
	return slen;
}

ILUInt32 CGenWStringIndex(ILGenInfo *info, const char *str, int len)
{
	return GenStringIndex(info, str, len, 1);
}

#if HAVE_QSORT

static int IntCompare(const void *e1, const void *e2)
{
	if(*((int *)e1) < *((int *)e2))
	{
		return -1;
	}
	else if(*((int *)e1) > *((int *)e2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

#endif

void CGenStringPool(ILGenInfo *info)
{
	FILE *stream = info->asmOutput;
	int column;
	const char *str;
	int len;
	ILHashIter iter;
	StringHashEntry *entry;
	int *lengths;
	int *wideLengths;
	int numLengths;
	int numWideLengths;

	/* Bail out if no assembly output stream or string pool */
	if(!stream || !poolSize)
	{
		return;
	}

	/* Generate the type information for the pool */
	fputs(".class private sealed '$strings' extends [.library]System.Object\n",
		  stream);
	fputs("{\n", stream);

	/* Collect up the length values of all strings and sort them */
	lengths = (int *)ILMalloc(sizeof(int) * poolIndex);
	if(!lengths)
	{
		ILGenOutOfMemory(info);
	}
	wideLengths = (int *)ILMalloc(sizeof(int) * poolIndex);
	if(!wideLengths)
	{
		ILGenOutOfMemory(info);
	}
	numLengths = 0;
	numWideLengths = 0;
	ILHashIterInit(&iter, poolHash);
	while((entry = ILHashIterNextType(&iter, StringHashEntry)) != 0)
	{
		if(!(entry->isWide))
		{
			lengths[numLengths++] = entry->len + 1;
		}
		else
		{
			wideLengths[numWideLengths++] =
				(int)(CGenWStringLength(entry->str, entry->len) + 1);
		}
	}
#if HAVE_QSORT
	qsort(lengths, numLengths, sizeof(int), IntCompare);
	qsort(wideLengths, numWideLengths, sizeof(int), IntCompare);
#else
	{
		int x, y;
		for(x = 0; x < (numLengths - 1); ++x)
		{
			for(y = x + 1; y < numLengths; ++y)
			{
				if(lengths[x] > lengths[y])
				{
					len = lengths[x];
					lengths[x] = lengths[y];
					lengths[y] = len;
				}
			}
		}
		for(x = 0; x < (numWideLengths - 1); ++x)
		{
			for(y = x + 1; y < numWideLengths; ++y)
			{
				if(wideLengths[x] > wideLengths[y])
				{
					len = wideLengths[x];
					wideLengths[x] = wideLengths[y];
					wideLengths[y] = len;
				}
			}
		}
	}
#endif

	/* Declare value types for each distinct length value */
	for(len = 0; len < numLengths; ++len)
	{
		if(len < (numLengths - 1) && lengths[len] == lengths[len + 1])
		{
			continue;
		}
		fprintf(stream, ".class nested public sealed explicit "
						"'type%d' extends [.library]System.ValueType\n",
				lengths[len]);
		fprintf(stream, "{\n\t.pack 1\n\t.size %d\n}\n", lengths[len]);
	}
	for(len = 0; len < numWideLengths; ++len)
	{
		if(len < (numWideLengths - 1) &&
		   wideLengths[len] == wideLengths[len + 1])
		{
			continue;
		}
		fprintf(stream, ".class nested public sealed explicit "
						"'wtype%d' extends [.library]System.ValueType\n",
				wideLengths[len]);
		fprintf(stream, "{\n\t.pack 2\n\t.size %d\n}\n",
		        wideLengths[len] * 2);
	}

	/* Dump the contents of all "char *" strings to the ".sdata" section */
	ILHashIterInit(&iter, poolHash);
	while((entry = ILHashIterNextType(&iter, StringHashEntry)) != 0)
	{
		if(entry->isWide)
		{
			fprintf(stream, ".field public static valuetype "
							"'$strings'/'wtype%d' wstr%lu\n",
					CGenWStringLength(entry->str, entry->len) + 1,
				    (unsigned long)(entry->index));
			continue;
		}
		fprintf(stream, ".data StrData%lu = bytearray(\n",
				(unsigned long)(entry->index));
		column = 0;
		str = entry->str;
		len = entry->len + 1;
		while(len > 0)
		{
			fprintf(stream, " %02X", (int)(*str));
			--len;
			++str;
			++column;
			if(len > 0 && (column % 24) == 0)
			{
				putc('\n', stream);
				column = 0;
			}
		}
		fputs(")\n", stream);
		fprintf(stream, ".field public static valuetype '$strings'/'type%d' "
						"str%lu at StrData%lu\n",
				entry->len + 1, (unsigned long)(entry->index),
				(unsigned long)(entry->index));
	}

	/* Output the end of the "$strings" type */
	fputs("}\n", stream);

	/* Dump the contents of all "wchar *" strings to an initializer method */
	if(numWideLengths > 0)
	{
		fputs(".method private static specialname void '.init-wstrings'() "
					"cil managed\n", stream);
		fputs("{\n", stream);
		fputs(".custom instance void OpenSystem.C.InitializerAttribute::.ctor()"
				" = (01 00 00 00)\n", stream);
		fputs(".custom instance void OpenSystem.C.InitializerOrderAttribute"
			  	"::.ctor(int32) = (01 00 FF FF FF FF 00 00)\n", stream);
		fputs("\t.maxstack 2\n", stream);
		ILHashIterInit(&iter, poolHash);
		while((entry = ILHashIterNextType(&iter, StringHashEntry)) != 0)
		{
			if(!(entry->isWide))
			{
				continue;
			}
			fprintf(stream, "\tldsflda valuetype '$strings'/'wtype%d' "
							"'$strings'::wstr%lu\n",
				    (int)(CGenWStringLength(entry->str, entry->len) + 1),
					(unsigned long)(entry->index));
			ILGenLoadString(info, entry->str, entry->len);
			fputs("\tcall void [OpenSystem.C]OpenSystem.C.Crt0::"
				  "SetWideString(char *, class [.library]System.String)\n",
				  stream);
		}
		fputs("\tret\n", stream);
		fputs("}\n", stream);
	}

	/* Done */
	ILFree(lengths);
	ILFree(wideLengths);
}

#line 10026 "c_semantics.c"
