/* c_nodes.c.  Generated automatically by treecc */
#line 368 "c_defs.tc"

#include <cscc/c/c_internal.h>
#include "il_dumpasm.h"
#line 513 "c_ainit.tc"


/*
 * Look ahead to the next item in a list iteration.
 */
static ILNode *IterLookAhead(ILNode_ListIter *iter)
{
	ILNode_ListIter copy = *iter;
	return ILNode_ListIter_Next(&copy);
}

/*
 * Write an initializer into memory at a specific pointer location,
 * where the pointer is on the stack.  If "field" is non-NULL, then
 * it indicates a field within a higher-level structure.
 */
static void WriteInitializer(ILGenInfo *info, ILType *type,
							 ILNode_ListIter *iter, ILField *field)
{
	ILNode *node = IterLookAhead(iter);
	ILUInt32 size;
	ILUInt32 numElems;
	ILUInt32 index;
	ILUInt32 wsize;
	ILType *elemType;
	ILClass *classInfo;
	ILField *nextField;
	ILNode_ListIter inner;
	int popped;
	CTypeLayoutInfo layout;

	if(CTypeIsArray(type))
	{
		/* Write the members of an array */
		numElems = CTypeGetNumElems(type);
		elemType = CTypeGetElemType(type);
		if(node && yyisa(node, ILNode_CString) &&
		   (ILTypeIdentical(elemType, ILType_Int8) ||
		    ILTypeIdentical(elemType, ILType_UInt8)))
		{
			/* Populate a "char" array by copying a string into it */
			if(field)
			{
				ILGenFieldRef(info, IL_OP_LDFLDA, field);
			}
			node = ILNode_ListIter_Next(iter);
			ILNode_GenValue(node, info);
			size = CTypeGetNumElems(type);
			if(size > (((ILNode_CString *)node)->len + 1))
			{
				size = ((ILNode_CString *)node)->len + 1;
			}
			ILGenUInt32(info, size);
			ILGenAdjust(info, 1);
			ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 1);
			ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
			ILGenAdjust(info, -3);
		}
		else if(node && yyisa(node, ILNode_CWString) &&
		        (ILTypeIdentical(elemType, ILType_Int16) ||
		         ILTypeIdentical(elemType, ILType_UInt16) ||
		         ILTypeIdentical(elemType, ILType_Char)))
		{
			/* Populate a "wchar" array by copying a wide string into it */
			if(field)
			{
				ILGenFieldRef(info, IL_OP_LDFLDA, field);
			}
			node = ILNode_ListIter_Next(iter);
			ILNode_GenValue(node, info);
			size = CTypeGetNumElems(type);
			wsize = CGenWStringLength
					 (((ILNode_CWString *)node)->str,
					  ((ILNode_CWString *)node)->len);
			if(size > (wsize + 1))
			{
				size = wsize + 1;
			}
			ILGenUInt32(info, size * 2);
			ILGenAdjust(info, 1);
			ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 2);
			ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
			ILGenAdjust(info, -3);
		}
		else
		{
			/* Write ordinary members to the array */
			if(field)
			{
				ILGenFieldRef(info, IL_OP_LDFLDA, field);
			}
			popped = 0;
			index = 0;
			CTypeGetLayoutInfo(elemType, &layout);
			while(numElems > 0 && node != 0)
			{
				if(numElems > 1)
				{
					ILGenSimple(info, IL_OP_DUP);
					ILGenAdjust(info, 1);
				}
				else
				{
					popped = 1;
				}
				if(index != 0)
				{
					/* Adjust the pointer to account for the array index */
					if(layout.category == C_TYPECAT_FIXED)
					{
						ILGenUIntNative(info, index * layout.size);
						ILGenSimple(info, IL_OP_ADD);
						ILGenExtend(info, 1);
					}
					else if(index == 1)
					{
						CGenSizeOf(info, elemType);
						ILGenSimple(info, IL_OP_CONV_U);
						ILGenSimple(info, IL_OP_ADD);
						ILGenAdjust(info, -1);
					}
					else
					{
						ILGenUInt32(info, index);
						ILGenAdjust(info, 1);
						CGenSizeOf(info, elemType);
						ILGenSimple(info, IL_OP_MUL);
						ILGenSimple(info, IL_OP_CONV_U);
						ILGenSimple(info, IL_OP_ADD);
						ILGenAdjust(info, -2);
					}
				}
				if(yyisa(node, ILNode_CArrayInit))
				{
					/* The element is specified as a nested array init scope */
					ILNode_ListIter_Init
						(&inner, ((ILNode_CArrayInit *)node)->expr);
					WriteInitializer(info, elemType, &inner, 0);
					ILNode_ListIter_Next(iter);
				}
				else
				{
					/* The element is specified inline within the parent */
					WriteInitializer(info, elemType, iter, 0);
				}
				node = IterLookAhead(iter);
				--numElems;
				++index;
			}
			if(!popped)
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
		}
	}
	else if(CTypeIsStruct(type) || CTypeIsUnion(type))
	{
		/* Write the elements of a structure */
		if(field)
		{
			if(CTypeIsComplex(ILClassToType(ILField_Owner(field))))
			{
				CAddComplexFieldOffset
					(info, ILClassToType(ILField_Owner(field)), field);
			}
			else
			{
				ILGenFieldRef(info, IL_OP_LDFLDA, field);
			}
		}
		classInfo = ILType_ToValueType(ILTypeStripPrefixes(type));
		field = 0;
		popped = 0;
		while((field = (ILField *)ILClassNextMemberByKind
				(classInfo, (ILMember *)field, IL_META_MEMBERKIND_FIELD)) != 0)
		{
			if(!node)
			{
				break;
			}
			if(ILField_IsStatic(field))
			{
				continue;
			}
			nextField = field;
			while((nextField = (ILField *)ILClassNextMemberByKind
						(classInfo, (ILMember *)nextField,
						 IL_META_MEMBERKIND_FIELD)) != 0 &&
				  ILField_IsStatic(nextField))
			{
				/* Look for the next non-static field */
			}
			if(nextField)
			{
				/* Duplicate the pointer, because we'll need it again */
				ILGenSimple(info, IL_OP_DUP);
				ILGenAdjust(info, 1);
			}
			else
			{
				/* We are on the last field, so don't dup the pointer */
				popped = 1;
			}
			elemType = ILFieldGetTypeWithPrefixes(field);
			if(yyisa(node, ILNode_CArrayInit) &&
			   (CTypeIsStruct(elemType) || CTypeIsUnion(elemType) ||
			    CTypeIsArray(elemType)))
			{
				/* The element is specified as a nested array init scope */
				ILNode_ListIter_Init
					(&inner, ((ILNode_CArrayInit *)node)->expr);
				WriteInitializer(info, elemType, &inner, field);
				ILNode_ListIter_Next(iter);
			}
			else
			{
				/* The element is specified inline within the parent */
				WriteInitializer(info, elemType, iter, field);
			}
			node = IterLookAhead(iter);
		}
		if(!popped)
		{
			ILGenSimple(info, IL_OP_POP);
			ILGenAdjust(info, -1);
		}
	}
	else
	{
		/* Write an ordinary initializer value */
		node = ILNode_ListIter_Next(iter);
		if(field)
		{
			if(CTypeIsComplex(ILClassToType(ILField_Owner(field))))
			{
				CAddComplexFieldOffset
					(info, ILClassToType(ILField_Owner(field)), field);
				ILNode_GenValue(node, info);
				ILGenStoreManaged(info, ILTypeToMachineType(type),
							  	  ILTypeStripPrefixes(type));
			}
			else
			{
				ILNode_GenValue(node, info);
				ILGenFieldRef(info, IL_OP_STFLD, field);
			}
		}
		else
		{
			ILNode_GenValue(node, info);
			ILGenStoreManaged(info, ILTypeToMachineType(type),
							  ILTypeStripPrefixes(type));
		}
		ILGenAdjust(info, -2);
	}
}

#line 435 "c_builtin.tc"


/*
 * Check for an assembly code instruction match.
 */
static int AsmCheckFor(const char *line, int len, const char *insn)
{
	int insnlen = strlen(insn);
	if(insnlen <= len &&
	   !strncmp(line, insn, insnlen) &&
	   (insnlen == len || line[insnlen] == ' ' || line[insnlen] == '\t'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

#line 266 "c_lvalue.tc"


/*
 * Load a value from a pointer.  If the type is complex or an array,
 * then leave the pointer as-is.  Returns a modified type representing
 * the actual value pushed onto the stack.
 */
static ILType *LoadValueFromPointer(ILGenInfo *info, ILType *type)
{
	if(CTypeIsComplex(type) || CTypeIsArray(type))
	{
		return CTypeCreateVoidPtr(info);
	}
	else
	{
		type = ILTypeStripPrefixes(type);
		ILGenLoadManaged(info, ILTypeToMachineType(type), type);
		return type;
	}
}

/*
 * Store a value into a pointer.  If the type is complex,
 * then the value is expected to be a pointer to a complex
 * value, which is then copied into its final location.
 * If "field" is non-NULL, then it indicates that the pointer
 * is a base for a structure, not the location itself.
 * If "leave" is non-zero, then the value should be left
 * on the stack after the store has finished.
 */
static void StoreValueToPointer(ILGenInfo *info, ILType *type,
								ILField *field, int leave)
{
	ILType *tempType;
	unsigned tempVar = ~((unsigned)0);
	if(CTypeIsComplex(type))
	{
		/* Complex values are passed on the stack as pointers */
		tempType = CTypeCreateVoidPtr(info);
	}
	else
	{
		tempType = ILTypeStripPrefixes(type);
	}
	if(leave)
	{
		/* Make a copy of the final value before storing it */
		tempVar = ILGenTempTypedVar(info, tempType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenStoreLocal(info, tempVar);
		ILGenAdjust(info, -1);
	}
	if(CTypeIsComplex(type))
	{
		/* Copy a complex value into its destination */
		CGenSizeOf(info, type);
		ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 1);
		ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
		ILGenAdjust(info, -3);
	}
	else if(field)
	{
		/* Store into a structure field */
		ILGenFieldRef(info, IL_OP_STFLD, field);
		ILGenAdjust(info, -2);
	}
	else
	{
		/* Store directly into a pointer */
		ILGenStoreManaged(info, ILTypeToMachineType(tempType), tempType);
		ILGenAdjust(info, -2);
	}
	if(leave)
	{
		ILGenLoadLocal(info, tempVar);
		ILGenReleaseTempVar(info, tempVar);
		ILGenAdjust(info, 1);
	}
}

#line 2287 "c_lvalue.tc"


/*
 * Convert a raw storage value into a bit field value.
 */
static void RawToBitField(ILGenInfo *info, ILMachineType type,
						  ILUInt32 start, ILUInt32 size)
{
	switch(type)
	{
		case ILMachineType_Int8:
		case ILMachineType_Int16:
		case ILMachineType_Int32:
		{
			/* Handle signed fields of 32 bits or less in size */
			if(size == 8)
			{
				if(start == (32 - 8))
				{
					ILGenUIntNative(info, start);
					ILGenSimple(info, IL_OP_SHR);
					ILGenExtend(info, 1);
				}
				else if(start != 0)
				{
					ILGenUIntNative(info, start);
					ILGenSimple(info, IL_OP_SHR);
					ILGenSimple(info, IL_OP_CONV_I1);
					ILGenExtend(info, 1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I1);
				}
			}
			else if(size == 16)
			{
				if(start == (32 - 16))
				{
					ILGenUIntNative(info, start);
					ILGenSimple(info, IL_OP_SHR);
					ILGenExtend(info, 1);
				}
				else if(start != 0)
				{
					ILGenUIntNative(info, start);
					ILGenSimple(info, IL_OP_SHR);
					ILGenSimple(info, IL_OP_CONV_I2);
					ILGenExtend(info, 1);
				}
				else
				{
					ILGenSimple(info, IL_OP_CONV_I2);
				}
			}
			else
			{
				if((start + size) < 32)
				{
					ILGenUIntNative(info, 32 - (start + size));
					ILGenSimple(info, IL_OP_SHL);
					ILGenExtend(info, 1);
				}
				ILGenUIntNative(info, 32 - size);
				ILGenSimple(info, IL_OP_SHR);
				ILGenExtend(info, 1);
			}
		}
		break;

		case ILMachineType_UInt8:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_UInt32:
		{
			/* Handle unsigned fields of 32 bits or less in size */
			if(start != 0)
			{
				ILGenUIntNative(info, start);
				ILGenSimple(info, IL_OP_SHR_UN);
				ILGenExtend(info, 1);
			}
			if(size == 8)
			{
				ILGenSimple(info, IL_OP_CONV_U1);
			}
			else if(size == 16)
			{
				ILGenSimple(info, IL_OP_CONV_U2);
			}
			else
			{
				ILGenUInt32(info, (((ILUInt32)1) << size) - 1);
				ILGenSimple(info, IL_OP_AND);
				ILGenExtend(info, 1);
			}
		}
		break;

		case ILMachineType_Int64:
		{
			/* Handle 64-bit signed fields */
			if((start + size) < 64)
			{
				ILGenUIntNative(info, 64 - (start + size));
				ILGenSimple(info, IL_OP_SHL);
				ILGenExtend(info, 1);
			}
			ILGenUIntNative(info, 64 - size);
			ILGenSimple(info, IL_OP_SHR);
			ILGenExtend(info, 1);
		}
		break;

		case ILMachineType_UInt64:
		{
			/* Handle 64-bit unsigned fields */
			if(start != 0)
			{
				ILGenUIntNative(info, start);
				ILGenSimple(info, IL_OP_SHR_UN);
				ILGenExtend(info, 1);
			}
			ILGenUInt64(info, (((ILUInt64)1) << size) - 1);
			ILGenSimple(info, IL_OP_AND);
			ILGenExtend(info, 1);
		}
		break;

		default: break;
	}
}

/*
 * Convert a bit field value into a raw storage value, ready to
 * be OR'ed with the original masked value.
 */
static void BitFieldToRaw(ILGenInfo *info, ILMachineType type,
						  ILUInt32 start, ILUInt32 size)
{
	switch(type)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		case ILMachineType_UInt32:
		{
			ILGenUInt32(info, (((ILUInt32)1) << size) - 1);
			ILGenSimple(info, IL_OP_AND);
			ILGenExtend(info, 1);
			if(start != 0)
			{
				ILGenUIntNative(info, start);
				ILGenSimple(info, IL_OP_SHL);
				ILGenExtend(info, 1);
			}
		}
		break;

		case ILMachineType_Int64:
		case ILMachineType_UInt64:
		{
			ILGenUInt64(info, (((ILUInt64)1) << size) - 1);
			ILGenSimple(info, IL_OP_AND);
			ILGenExtend(info, 1);
			if(start != 0)
			{
				ILGenUIntNative(info, start);
				ILGenSimple(info, IL_OP_SHL);
				ILGenExtend(info, 1);
			}
		}
		break;

		default: break;
	}
}

#line 551 "c_nodes.c"

struct ILNode_CDeclarator_vtable__ const ILNode_CDeclarator_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_CDeclarator_kind,
	"ILNode_CDeclarator",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Dummy_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenElse__,
};

struct ILNode_CSharpInvocation_vtable__ const ILNode_CSharpInvocation_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_CSharpInvocation_kind,
	"ILNode_CSharpInvocation",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Dummy_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenElse__,
};

struct ILNode_CAttribute_vtable__ const ILNode_CAttribute_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_CAttribute_kind,
	"ILNode_CAttribute",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Dummy_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenElse__,
};

struct ILNode_CAttributeValue_vtable__ const ILNode_CAttributeValue_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_CAttributeValue_kind,
	"ILNode_CAttributeValue",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Dummy_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenElse__,
};

struct ILNode_CBitFieldDeclarator_vtable__ const ILNode_CBitFieldDeclarator_vt__ = {
	&ILNode_CDeclarator_vt__,
	ILNode_CBitFieldDeclarator_kind,
	"ILNode_CBitFieldDeclarator",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Dummy_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenElse__,
};

struct ILNode_CInitDeclarator_vtable__ const ILNode_CInitDeclarator_vt__ = {
	&ILNode_CDeclarator_vt__,
	ILNode_CInitDeclarator_kind,
	"ILNode_CInitDeclarator",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Dummy_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Dummy_JavaGenElse__,
};

ILMachineType ILNode_SizeOfType_ILNode_GetType__(ILNode_SizeOfType *node, ILGenInfo * info)
#line 2655 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 660 "c_nodes.c"

ILMachineType ILNode_SizeOfType_ILNode_GenValue__(ILNode_SizeOfType *node, ILGenInfo * info)
#line 2660 "c_oper.tc"
{
	CGenSizeOf(info, node->type);
	return ILMachineType_UInt32;
}
#line 668 "c_nodes.c"

int ILNode_SizeOfType_ILNode_EvalConst__(ILNode_SizeOfType *node, ILGenInfo * info, ILEvalValue * value)
#line 2633 "c_oper.tc"
{
	CTypeLayoutInfo layout;
	CTypeGetLayoutInfo(node->type, &layout);
	if(layout.category == C_TYPECAT_FIXED)
	{
		/* The type's size can be evaluated to a compile-time constant */
		value->valueType = ILMachineType_UInt32;
		value->un.i4Value = (ILInt32)(layout.size);
		return 1;
	}
	else
	{
		/* We must compute this constant value dynamically at runtime */
		return 0;
	}
}
#line 688 "c_nodes.c"

ILMachineType ILNode_SizeOfType_JavaGenValue__(ILNode_SizeOfType *node, ILGenInfo * info)
#line 2666 "c_oper.tc"
{
	/* Will never be called: nothing to do here */
	return ILMachineType_UInt32;
}
#line 696 "c_nodes.c"

struct ILNode_SizeOfType_vtable__ const ILNode_SizeOfType_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_SizeOfType_kind,
	"ILNode_SizeOfType",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOfType_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOfType_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_SizeOfType_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOfType_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_VaStart_ILNode_GetType__(ILNode_VaStart *node, ILGenInfo * info)
#line 112 "c_builtin.tc"
{
	return ILMachineType_Void;
}
#line 720 "c_nodes.c"

void ILNode_VaStart_ILNode_GenDiscard__(ILNode_VaStart *node, ILGenInfo * info)
#line 120 "c_builtin.tc"
{
	/* Push a reference to the "va_list" value onto the stack */
	ILNode_GenRef((ILNode_LValue *)(node->vaList), info);

	/* Get the argument list for the current function */
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_ARGLIST);
	ILGenAdjust(info, 1);

	/* Call the "ArgIterator" constructor */
	ILGenCallByName(info, "instance void [.library]System.ArgIterator::.ctor"
			"(valuetype [.library]System.RuntimeArgumentHandle)");
	ILGenAdjust(info, -2);
}
#line 737 "c_nodes.c"

ILMachineType ILNode_VaStart_ILNode_GenValue__(ILNode_VaStart *node, ILGenInfo * info)
#line 138 "c_builtin.tc"
{
	ILNode_GenDiscard(node, info);
	return ILMachineType_Void;
}
#line 745 "c_nodes.c"

ILMachineType ILNode_VaStart_JavaGenValue__(ILNode_VaStart *node, ILGenInfo * info)
#line 143 "c_builtin.tc"
{
	/* Never called: nothing to do here */
	return ILMachineType_Void;
}
#line 753 "c_nodes.c"

struct ILNode_VaStart_vtable__ const ILNode_VaStart_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_VaStart_kind,
	"ILNode_VaStart",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaStart_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_VaStart_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaStart_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaStart_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_VaEnd_ILNode_GetType__(ILNode_VaEnd *node, ILGenInfo * info)
#line 164 "c_builtin.tc"
{
	return ILMachineType_Void;
}
#line 777 "c_nodes.c"

void ILNode_VaEnd_ILNode_GenDiscard__(ILNode_VaEnd *node, ILGenInfo * info)
#line 172 "c_builtin.tc"
{
	/* Push a reference to the "va_list" value onto the stack */
	ILNode_GenRef((ILNode_LValue *)(node->vaList), info);

	/* Call the "ArgIterator.End" method */
	ILGenCallByName(info, "instance void [.library]System.ArgIterator::End()");
	ILGenAdjust(info, -1);
}
#line 789 "c_nodes.c"

ILMachineType ILNode_VaEnd_ILNode_GenValue__(ILNode_VaEnd *node, ILGenInfo * info)
#line 185 "c_builtin.tc"
{
	ILNode_GenDiscard(node, info);
	return ILMachineType_Void;
}
#line 797 "c_nodes.c"

ILMachineType ILNode_VaEnd_JavaGenValue__(ILNode_VaEnd *node, ILGenInfo * info)
#line 190 "c_builtin.tc"
{
	/* Never called: nothing to do here */
	return ILMachineType_Void;
}
#line 805 "c_nodes.c"

struct ILNode_VaEnd_vtable__ const ILNode_VaEnd_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_VaEnd_kind,
	"ILNode_VaEnd",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaEnd_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_VaEnd_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaEnd_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaEnd_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_VaArg_ILNode_GetType__(ILNode_VaArg *node, ILGenInfo * info)
#line 233 "c_builtin.tc"
{
	return ILTypeToMachineType(CFunctionNaturalType(info, node->type, 1));
}
#line 829 "c_nodes.c"

ILMachineType ILNode_VaArg_ILNode_GenValue__(ILNode_VaArg *node, ILGenInfo * info)
#line 241 "c_builtin.tc"
{
	ILType *naturalType;
	ILMachineType machineType;

	/* Push a reference to the "va_list" value onto the stack */
	ILNode_GenRef((ILNode_LValue *)(node->vaList), info);

	/* Get the next argument from the "va_list" value */
	ILGenCallByName(info, "instance valuetype [.library]System.TypedReference "
			"[.library]System.ArgIterator::GetNextArg()");

	/* Unpack the typed reference using the natural passing type */
	naturalType = ILTypeStripPrefixes
		(CFunctionNaturalType(info, node->type, 1));
	ILGenClassToken
		(info, IL_OP_REFANYVAL, ILTypeToClass(info, naturalType));
	machineType = ILTypeToMachineType(naturalType);
	ILGenLoadManaged(info, machineType, naturalType);

	/* Return the natural machine type to the caller, which will take
	   care of casting it to the final type that was requested */
	return machineType;
}
#line 856 "c_nodes.c"

ILMachineType ILNode_VaArg_JavaGenValue__(ILNode_VaArg *node, ILGenInfo * info)
#line 265 "c_builtin.tc"
{
	/* Never called: nothing to do here */
	return ILMachineType_Void;
}
#line 864 "c_nodes.c"

struct ILNode_VaArg_vtable__ const ILNode_VaArg_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_VaArg_kind,
	"ILNode_VaArg",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaArg_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaArg_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_VaArg_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_FunctionRef_ILNode_GetType__(ILNode_FunctionRef *node, ILGenInfo * info)
#line 38 "c_invoke.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 888 "c_nodes.c"

ILMachineType ILNode_FunctionRef_ILNode_GenValue__(ILNode_FunctionRef *node, ILGenInfo * info)
#line 46 "c_invoke.tc"
{
	if(info->asmOutput)
	{
		fputs("\tldftn\t", info->asmOutput);
		ILDumpMethodType(info->asmOutput, info->image, node->signature,
						 IL_DUMP_QUOTE_NAMES, 0, node->name, 0);
		putc('\n', info->asmOutput);
	}
	ILGenAdjust(info, 1);
	return ILMachineType_UnmanagedPtr;
}
#line 903 "c_nodes.c"

ILMachineType ILNode_FunctionRef_JavaGenValue__(ILNode_FunctionRef *node, ILGenInfo * info)
#line 58 "c_invoke.tc"
{
	/* Never called: nothing to do here */
	return ILMachineType_UnmanagedPtr;
}
#line 911 "c_nodes.c"

struct ILNode_FunctionRef_vtable__ const ILNode_FunctionRef_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_FunctionRef_kind,
	"ILNode_FunctionRef",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_FunctionRef_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_FunctionRef_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_FunctionRef_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CLabelRef_ILNode_GetType__(ILNode_CLabelRef *node, ILGenInfo * info)
#line 626 "c_stmt.tc"
{
	return ILMachineType_NativeInt;
}
#line 935 "c_nodes.c"

ILMachineType ILNode_CLabelRef_ILNode_GenValue__(ILNode_CLabelRef *node, ILGenInfo * info)
#line 630 "c_stmt.tc"
{
	ILGenIntNative(info, node->labelNum);
	return ILMachineType_NativeInt;
}
#line 943 "c_nodes.c"

int ILNode_CLabelRef_ILNode_EvalConst__(ILNode_CLabelRef *node, ILGenInfo * info, ILEvalValue * value)
#line 644 "c_stmt.tc"
{
	if(node->labelNum != 0)
	{
		value->valueType = ILMachineType_NativeInt;
		value->un.i4Value = node->labelNum;
		return 1;
	}
	else
	{
		return 0;
	}
}
#line 959 "c_nodes.c"

ILMachineType ILNode_CLabelRef_JavaGenValue__(ILNode_CLabelRef *node, ILGenInfo * info)
#line 635 "c_stmt.tc"
{
	/* Will never be called: nothing to do here */
	return ILMachineType_NativeInt;
}
#line 967 "c_nodes.c"

struct ILNode_CLabelRef_vtable__ const ILNode_CLabelRef_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CLabelRef_kind,
	"ILNode_CLabelRef",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CLabelRef_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CLabelRef_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_CLabelRef_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CLabelRef_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CSharpTypeOf_ILNode_GetType__(ILNode_CSharpTypeOf *node, ILGenInfo * info)
#line 2694 "c_oper.tc"
{
	return ILMachineType_ObjectRef;
}
#line 991 "c_nodes.c"

ILMachineType ILNode_CSharpTypeOf_ILNode_GenValue__(ILNode_CSharpTypeOf *node, ILGenInfo * info)
#line 2702 "c_oper.tc"
{
	ILGenTypeToken(info, IL_OP_LDTOKEN, node->type);
	ILGenAdjust(info, 1);
	ILGenCallByName(info,
			"class [.library]System.Type "
				"[.library]System.Type::GetTypeFromHandle"
				"(valuetype [.library]System.RuntimeTypeHandle)");
	return ILMachineType_ObjectRef;
}
#line 1004 "c_nodes.c"

ILMachineType ILNode_CSharpTypeOf_JavaGenValue__(ILNode_CSharpTypeOf *node, ILGenInfo * info)
#line 2712 "c_oper.tc"
{
	/* Nothing to do here */
	return ILMachineType_ObjectRef;
}
#line 1012 "c_nodes.c"

struct ILNode_CSharpTypeOf_vtable__ const ILNode_CSharpTypeOf_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CSharpTypeOf_kind,
	"ILNode_CSharpTypeOf",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSharpTypeOf_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSharpTypeOf_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSharpTypeOf_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CTypeExpression_ILNode_GetType__(ILNode_CTypeExpression *node, ILGenInfo * info)
#line 2733 "c_oper.tc"
{
	/* Should never be called */
	return ILMachineType_Void;
}
#line 1037 "c_nodes.c"

ILMachineType ILNode_CTypeExpression_ILNode_GenValue__(ILNode_CTypeExpression *node, ILGenInfo * info)
#line 2733 "c_oper.tc"
{
	/* Should never be called */
	return ILMachineType_Void;
}
#line 1045 "c_nodes.c"

ILMachineType ILNode_CTypeExpression_JavaGenValue__(ILNode_CTypeExpression *node, ILGenInfo * info)
#line 2733 "c_oper.tc"
{
	/* Should never be called */
	return ILMachineType_Void;
}
#line 1053 "c_nodes.c"

struct ILNode_CTypeExpression_vtable__ const ILNode_CTypeExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CTypeExpression_kind,
	"ILNode_CTypeExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CTypeExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CTypeExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CTypeExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CNewObject_ILNode_GetType__(ILNode_CNewObject *node, ILGenInfo * info)
#line 784 "c_invoke.tc"
{
	return ILTypeToMachineType(node->type);
}
#line 1077 "c_nodes.c"

ILMachineType ILNode_CNewObject_ILNode_GenValue__(ILNode_CNewObject *node, ILGenInfo * info)
#line 792 "c_invoke.tc"
{
	/* TODO */
	return ILTypeToMachineType(node->type);
}
#line 1085 "c_nodes.c"

ILMachineType ILNode_CNewObject_JavaGenValue__(ILNode_CNewObject *node, ILGenInfo * info)
#line 797 "c_invoke.tc"
{
	/* Nothing to do here */
	return ILTypeToMachineType(node->type);
}
#line 1093 "c_nodes.c"

struct ILNode_CNewObject_vtable__ const ILNode_CNewObject_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CNewObject_kind,
	"ILNode_CNewObject",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CNewObject_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CNewObject_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CNewObject_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CNewArray_ILNode_GetType__(ILNode_CNewArray *node, ILGenInfo * info)
#line 865 "c_invoke.tc"
{
	return ILTypeToMachineType(node->resultType);
}
#line 1117 "c_nodes.c"

ILMachineType ILNode_CNewArray_ILNode_GenValue__(ILNode_CNewArray *node, ILGenInfo * info)
#line 873 "c_invoke.tc"
{
	ILNode_GenValue(node->expr, info);
	if(node->specifier == ILGC_Managed)
	{
		/* Allocate a managed array */
		ILGenArrayNew(info, node->type);
	}
	else
	{
		/* Allocate an unmanaged array using "malloc" */
		/* TODO: overloaded "new" operators */
		CGenSizeOf(info, node->type);
		ILGenSimple(info, IL_OP_MUL);
		ILGenAdjust(info, -1);
		ILGenCallByName(info, "void * 'malloc'(unsigned int32)");
	}
	return ILTypeToMachineType(node->resultType);
}
#line 1139 "c_nodes.c"

ILMachineType ILNode_CNewArray_JavaGenValue__(ILNode_CNewArray *node, ILGenInfo * info)
#line 892 "c_invoke.tc"
{
	/* Nothing to do here */
	return ILTypeToMachineType(node->resultType);
}
#line 1147 "c_nodes.c"

struct ILNode_CNewArray_vtable__ const ILNode_CNewArray_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CNewArray_kind,
	"ILNode_CNewArray",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CNewArray_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CNewArray_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CNewArray_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CSizeOfRaw_ILNode_GetType__(ILNode_CSizeOfRaw *node, ILGenInfo * info)
#line 2879 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 1171 "c_nodes.c"

ILMachineType ILNode_CSizeOfRaw_ILNode_GenValue__(ILNode_CSizeOfRaw *node, ILGenInfo * info)
#line 2887 "c_oper.tc"
{
	ILGenClassToken(info, IL_OP_PREFIX + IL_PREFIX_OP_SIZEOF,
				    ILTypeToClass(info, node->type));
	ILGenAdjust(info, 1);
	return ILMachineType_UInt32;
}
#line 1181 "c_nodes.c"

ILMachineType ILNode_CSizeOfRaw_JavaGenValue__(ILNode_CSizeOfRaw *node, ILGenInfo * info)
#line 3051 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 1188 "c_nodes.c"

struct ILNode_CSizeOfRaw_vtable__ const ILNode_CSizeOfRaw_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CSizeOfRaw_kind,
	"ILNode_CSizeOfRaw",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeOfRaw_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeOfRaw_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeOfRaw_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CSizeTempVar_ILNode_GetType__(ILNode_CSizeTempVar *node, ILGenInfo * info)
#line 2879 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 1212 "c_nodes.c"

ILMachineType ILNode_CSizeTempVar_ILNode_GenValue__(ILNode_CSizeTempVar *node, ILGenInfo * info)
#line 2898 "c_oper.tc"
{
	/* Not used during code generation */
	return ILMachineType_UInt32;
}
#line 1220 "c_nodes.c"

ILMachineType ILNode_CSizeTempVar_JavaGenValue__(ILNode_CSizeTempVar *node, ILGenInfo * info)
#line 3051 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 1227 "c_nodes.c"

struct ILNode_CSizeTempVar_vtable__ const ILNode_CSizeTempVar_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CSizeTempVar_kind,
	"ILNode_CSizeTempVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeTempVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeTempVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeTempVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CSizeAlign_ILNode_GetType__(ILNode_CSizeAlign *node, ILGenInfo * info)
#line 2879 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 1251 "c_nodes.c"

ILMachineType ILNode_CSizeAlign_ILNode_GenValue__(ILNode_CSizeAlign *node, ILGenInfo * info)
#line 2962 "c_oper.tc"
{
	ILNode_CSizeTempVar *tempVar = (ILNode_CSizeTempVar *)(node->alignVar);
	ILField *field;

	/* Compute the size value to be aligned */
	ILNode_GenValue(node->size, info);

	/* Perform the alignment according to the supplied parameters */
	if(node->alignFlags == C_ALIGN_BYTE)
	{
		/* Nothing to be done if we have byte alignment */
		return ILMachineType_UInt32;
	}
	else if((node->alignFlags & C_ALIGN_UNKNOWN) == 0)
	{
		/* Ordinary alignment with no unknown elements */
		ILGenUInt32(info, node->alignFlags);
		ILGenAdjust(info, 1);
	}
	else if(node->measureType)
	{
		/* Use the "LDFLDA" instruction to measure the alignment */
		field = CTypeGetMeasureField(info, node->measureType);
		ILGenUIntNative(info, 0);
		ILGenAdjust(info, 1);
		ILGenFieldRef(info, IL_OP_LDFLDA, field);
		ILGenSimple(info, IL_OP_CONV_U4);

		/* Merge the flags into the total structure alignment */
		if(tempVar)
		{
			ILGenSimple(info, IL_OP_DUP);
			ILGenAdjust(info, -1);
			if(tempVar->tempVar == ~((unsigned)0))
			{
				tempVar->tempVar = ILGenTempTypedVar(info, ILType_UInt32);
				ILGenStoreLocal(info, tempVar->tempVar);
				ILGenAdjust(info, -1);
			}
			else
			{
				ILGenLoadLocal(info, tempVar->tempVar);
				ILGenAdjust(info, 1);
				ILGenSimple(info, IL_OP_OR);
				ILGenStoreLocal(info, tempVar->tempVar);
				ILGenAdjust(info, -2);
			}
		}
	}
	else if(tempVar && tempVar->tempVar != ~((unsigned)0))
	{
		/* Use the final alignment from the temporary variable */
		if((node->alignFlags & ~C_ALIGN_UNKNOWN) != 0)
		{
			ILGenUInt32(info, node->alignFlags & ~C_ALIGN_UNKNOWN);
			ILGenLoadLocal(info, tempVar->tempVar);
			ILGenAdjust(info, 2);
			ILGenSimple(info, IL_OP_OR);
			ILGenAdjust(info, -1);
		}
		else
		{
			ILGenLoadLocal(info, tempVar->tempVar);
			ILGenAdjust(info, 1);
		}
	}
	else
	{
		/* We didn't encounter any unknown fields, so ignore the variable */
		ILGenUInt32(info, node->alignFlags & ~C_ALIGN_UNKNOWN);
		ILGenAdjust(info, 1);
	}

	/* Align the size value using the alignment flags on the stack */
	ILGenCallByName(info,
		"unsigned int32 [OpenSystem.C]OpenSystem.C.Crt0::Align"
			"(unsigned int32, unsigned int32)");
	ILGenAdjust(info, -1);
	return ILMachineType_UInt32;
}
#line 1335 "c_nodes.c"

ILMachineType ILNode_CSizeAlign_JavaGenValue__(ILNode_CSizeAlign *node, ILGenInfo * info)
#line 3051 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 1342 "c_nodes.c"

struct ILNode_CSizeAlign_vtable__ const ILNode_CSizeAlign_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_CSizeAlign_kind,
	"ILNode_CSizeAlign",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeAlign_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeAlign_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeAlign_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CString_ILNode_GetType__(ILNode_CString *node, ILGenInfo * info)
#line 467 "c_const.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 1366 "c_nodes.c"

ILMachineType ILNode_CString_ILNode_GenValue__(ILNode_CString *node, ILGenInfo * info)
#line 386 "c_const.tc"
{
	ILUInt32 index;

	/* Look for this string in the string pool */
	index = CGenStringIndex(info, node->str, node->len);

	/* Get the address of the string in the pool */
	if(info->asmOutput)
	{
		fprintf(info->asmOutput,
		        "\tldsflda\tvaluetype '$strings'/'type%d' "
					"'$strings'::'str%lu'\n",
				node->len + 1, (unsigned long)index);
	}
	ILGenAdjust(info, 1);

	/* Strings are passed on the stack as unmanaged pointers (type I) */
	return ILMachineType_UnmanagedPtr;
}
#line 1389 "c_nodes.c"

int ILNode_CString_ILNode_EvalConst__(ILNode_CString *node, ILGenInfo * info, ILEvalValue * value)
#line 410 "c_const.tc"
{
	/* C string constants must be evaluated at runtime because
	   we don't know what the address is yet */
	return 0;
}
#line 1398 "c_nodes.c"

struct ILNode_CString_vtable__ const ILNode_CString_vt__ = {
	&ILNode_String_vt__,
	ILNode_CString_kind,
	"ILNode_CString",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CString_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CString_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_CString_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_String_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_JavaGenElse__,
};

ILMachineType ILNode_CWString_ILNode_GetType__(ILNode_CWString *node, ILGenInfo * info)
#line 467 "c_const.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 1422 "c_nodes.c"

ILMachineType ILNode_CWString_ILNode_GenValue__(ILNode_CWString *node, ILGenInfo * info)
#line 430 "c_const.tc"
{
	ILUInt32 len;
	ILUInt32 index;

	/* Look for this string in the string pool */
	index = CGenWStringIndex(info, node->str, node->len);

	/* Get the address of the string in the pool */
	if(info->asmOutput)
	{
		len = CGenWStringLength(node->str, node->len);
		fprintf(info->asmOutput,
		        "\tldsflda\tvaluetype '$strings'/'wtype%lu' "
					"'$strings'::'wstr%lu'\n",
				(unsigned long)(len + 1), (unsigned long)index);
	}
	ILGenAdjust(info, 1);

	/* Strings are passed on the stack as unmanaged pointers (type I) */
	return ILMachineType_UnmanagedPtr;
}
#line 1447 "c_nodes.c"

int ILNode_CWString_ILNode_EvalConst__(ILNode_CWString *node, ILGenInfo * info, ILEvalValue * value)
#line 456 "c_const.tc"
{
	/* C wide string constants must be evaluated at runtime because
	   we don't know what the address is yet */
	return 0;
}
#line 1456 "c_nodes.c"

struct ILNode_CWString_vtable__ const ILNode_CWString_vt__ = {
	&ILNode_String_vt__,
	ILNode_CWString_kind,
	"ILNode_CWString",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CWString_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CWString_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_CWString_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_String_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_String_JavaGenElse__,
};

ILMachineType ILNode_CLocalVar_ILNode_GetType__(ILNode_CLocalVar *node, ILGenInfo * info)
#line 1057 "c_lvalue.tc"
{
	if(node->type == node->decayedType && !CTypeIsComplex(node->type))
	{
		return node->machineType;
	}
	else
	{
		return ILMachineType_UnmanagedPtr;
	}
}
#line 1487 "c_nodes.c"

ILMachineType ILNode_CLocalVar_ILNode_GenValue__(ILNode_CLocalVar *node, ILGenInfo * info)
#line 1074 "c_lvalue.tc"
{
	if(node->type == node->decayedType)
	{
		/* This is an ordinary local variable */
		if(!CTypeIsComplex(node->type))
		{
			ILGenLoadLocal(info, node->index);
			ILGenAdjust(info, 1);
			return node->machineType;
		}
		else
		{
			ILGenLoadLocal(info, node->index);
			ILGenAdjust(info, 1);
			return ILMachineType_UnmanagedPtr;
		}
	}
	else
	{
		/* This local variable decays immediately into a pointer */
		if(!CTypeIsComplex(node->type))
		{
			ILGenLoadLocalAddr(info, node->index);
			ILGenAdjust(info, 1);
		}
		else
		{
			ILGenLoadLocal(info, node->index);
			ILGenAdjust(info, 1);
		}
		return ILMachineType_UnmanagedPtr;
	}
}
#line 1524 "c_nodes.c"

ILMachineType ILNode_CLocalVar_JavaGenValue__(ILNode_CLocalVar *node, ILGenInfo * info)
#line 1108 "c_lvalue.tc"
{
	/* Nothing to do here */
	return ILMachineType_Void;
}
#line 1532 "c_nodes.c"

ILMachineType ILNode_CLocalVar_ILNode_Prepare__(ILNode_CLocalVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 1137 "c_lvalue.tc"
{
	if(CTypeIsComplex(node->type))
	{
		ILGenLoadLocal(info, node->index);
		ILGenAdjust(info, 1);
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return node->machineType;
	}
}
#line 1548 "c_nodes.c"

ILMachineType ILNode_CLocalVar_ILNode_GetAndPrepare__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 1170 "c_lvalue.tc"
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
#line 1562 "c_nodes.c"

void ILNode_CLocalVar_ILNode_Store__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1190 "c_lvalue.tc"
{
	if(!CTypeIsComplex(node->type))
	{
		/* Perform a store for a non-complex local variable type */
		if(leave)
		{
			ILGenSimple(info, IL_OP_DUP);
			ILGenAdjust(info, 1);
		}
		ILGenStoreLocal(info, node->index);
		ILGenAdjust(info, -1);
	}
	else
	{
		/* Copy the contents of the complex type into the local variable */
		CGenSizeOf(info, node->type);
		ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 1);
		ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
		ILGenAdjust(info, -3);

		/* If we should leave the value, then reload the local variable */
		if(leave)
		{
			ILGenLoadLocal(info, node->index);
			ILGenAdjust(info, 1);
		}
	}
}
#line 1594 "c_nodes.c"

void ILNode_CLocalVar_ILNode_GenRef__(ILNode_CLocalVar *node, ILGenInfo * info)
#line 1159 "c_lvalue.tc"
{
	CGenAddress(info, (ILNode *)node);
}
#line 1601 "c_nodes.c"

ILMachineType ILNode_CLocalVar_JavaPrepare__(ILNode_CLocalVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 1150 "c_lvalue.tc"
{
	/* Nothing to do here */
	return ILMachineType_Void;
}
#line 1609 "c_nodes.c"

ILMachineType ILNode_CLocalVar_JavaGetAndPrepare__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 1181 "c_lvalue.tc"
{
	/* Nothing to do here */
	return ILMachineType_Void;
}
#line 1617 "c_nodes.c"

void ILNode_CLocalVar_JavaStore__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1219 "c_lvalue.tc"
{
	/* Nothing to do here */
}
#line 1624 "c_nodes.c"

struct ILNode_CLocalVar_vtable__ const ILNode_CLocalVar_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_CLocalVar_kind,
	"ILNode_CLocalVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CLocalVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CLocalVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CLocalVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CLocalVar_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CLocalVar_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CLocalVar_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CLocalVar_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CLocalVar_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CLocalVar_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CLocalVar_JavaStore__,
};

ILMachineType ILNode_CArgumentVar_ILNode_GetType__(ILNode_CArgumentVar *node, ILGenInfo * info)
#line 1237 "c_lvalue.tc"
{
	if(CTypeIsComplex(node->type))
	{
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return node->machineType;
	}
}
#line 1662 "c_nodes.c"

void ILNode_CArgumentVar_ILNode_GenDiscard__(ILNode_CArgumentVar *node, ILGenInfo * info)
#line 1252 "c_lvalue.tc"
{
	/* Nothing to do here */
}
#line 1669 "c_nodes.c"

ILMachineType ILNode_CArgumentVar_ILNode_GenValue__(ILNode_CArgumentVar *node, ILGenInfo * info)
#line 1260 "c_lvalue.tc"
{
	if(!CTypeIsComplex(node->type))
	{
		/* Ordinary values are pushed by value */
		ILGenLoadArg(info, node->index);
		ILGenAdjust(info, 1);
		return node->machineType;
	}
	else
	{
		/* Complex values are pushed by reference */
		ILGenLoadArg(info, node->index);
		ILGenAdjust(info, 1);
		return ILMachineType_UnmanagedPtr;
	}
}
#line 1689 "c_nodes.c"

ILMachineType ILNode_CArgumentVar_JavaGenValue__(ILNode_CArgumentVar *node, ILGenInfo * info)
#line 1277 "c_lvalue.tc"
{
	/* Nothing to do here */
	return ILMachineType_Void;
}
#line 1697 "c_nodes.c"

ILMachineType ILNode_CArgumentVar_ILNode_Prepare__(ILNode_CArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 1286 "c_lvalue.tc"
{
	if(CTypeIsComplex(node->type))
	{
		ILGenLoadArg(info, node->index);
		ILGenAdjust(info, 1);
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return node->machineType;
	}
}
#line 1713 "c_nodes.c"

ILMachineType ILNode_CArgumentVar_ILNode_GetAndPrepare__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 1319 "c_lvalue.tc"
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
#line 1727 "c_nodes.c"

void ILNode_CArgumentVar_ILNode_Store__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1339 "c_lvalue.tc"
{
	if(!CTypeIsComplex(node->type))
	{
		/* Perform a store for a non-complex argument type */
		if(leave)
		{
			ILGenSimple(info, IL_OP_DUP);
			ILGenAdjust(info, 1);
		}
		ILGenStoreArg(info, node->index);
		ILGenAdjust(info, -1);
	}
	else
	{
		/* Copy the contents of the complex type into the argument variable */
		CGenSizeOf(info, node->type);
		ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 1);
		ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
		ILGenAdjust(info, -3);

		/* If we should leave the value, then reload the argument pointer */
		if(leave)
		{
			ILGenLoadArg(info, node->index);
			ILGenAdjust(info, 1);
		}
	}
}
#line 1759 "c_nodes.c"

void ILNode_CArgumentVar_ILNode_GenRef__(ILNode_CArgumentVar *node, ILGenInfo * info)
#line 1308 "c_lvalue.tc"
{
	CGenAddress(info, (ILNode *)node);
}
#line 1766 "c_nodes.c"

ILMachineType ILNode_CArgumentVar_JavaPrepare__(ILNode_CArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 1299 "c_lvalue.tc"
{
	/* Nothing to do here */
	return ILMachineType_Void;
}
#line 1774 "c_nodes.c"

ILMachineType ILNode_CArgumentVar_JavaGetAndPrepare__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 1330 "c_lvalue.tc"
{
	/* Nothing to do here */
	return ILMachineType_Void;
}
#line 1782 "c_nodes.c"

void ILNode_CArgumentVar_JavaStore__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1368 "c_lvalue.tc"
{
	/* Nothing to do here */
}
#line 1789 "c_nodes.c"

struct ILNode_CArgumentVar_vtable__ const ILNode_CArgumentVar_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_CArgumentVar_kind,
	"ILNode_CArgumentVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArgumentVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CArgumentVar_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArgumentVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArgumentVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CArgumentVar_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CArgumentVar_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CArgumentVar_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CArgumentVar_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CArgumentVar_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CArgumentVar_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CArgumentVar_JavaStore__,
};

ILMachineType ILNode_CGlobalVar_ILNode_GetType__(ILNode_CGlobalVar *node, ILGenInfo * info)
#line 1448 "c_lvalue.tc"
{
	if(!CTypeIsComplex(node->type))
	{
		return ILTypeToMachineType(node->decayedType);
	}
	else
	{
		return ILMachineType_UnmanagedPtr;
	}
}
#line 1827 "c_nodes.c"

void ILNode_CGlobalVar_ILNode_GenDiscard__(ILNode_CGlobalVar *node, ILGenInfo * info)
#line 1463 "c_lvalue.tc"
{
	/* Nothing to do here */
}
#line 1834 "c_nodes.c"

ILMachineType ILNode_CGlobalVar_ILNode_GenValue__(ILNode_CGlobalVar *node, ILGenInfo * info)
#line 1471 "c_lvalue.tc"
{
	if(info->asmOutput)
	{
		if(node->type == node->decayedType || CTypeIsComplex(node->type))
		{
			fputs("\tldsfld\t", info->asmOutput);
		}
		else
		{
			fputs("\tldsflda\t", info->asmOutput);
		}
		ILDumpType(info->asmOutput, info->image, node->type,
				   IL_DUMP_QUOTE_NAMES);
		putc(' ', info->asmOutput);
		if(CTypeIsComplex(node->type))
		{
			fputs("* ", info->asmOutput);
		}
		ILDumpIdentifier(info->asmOutput, node->name, 0,
						 IL_DUMP_QUOTE_NAMES);
		putc('\n', info->asmOutput);
	}
	ILGenAdjust(info, 1);
	if(!CTypeIsComplex(node->type))
	{
		return ILTypeToMachineType(node->decayedType);
	}
	else
	{
		return ILMachineType_UnmanagedPtr;
	}
}
#line 1870 "c_nodes.c"

ILMachineType ILNode_CGlobalVar_JavaGenValue__(ILNode_CGlobalVar *node, ILGenInfo * info)
#line 1631 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return ILTypeToMachineType(node->decayedType);
}
#line 1878 "c_nodes.c"

ILMachineType ILNode_CGlobalVar_ILNode_Prepare__(ILNode_CGlobalVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 1508 "c_lvalue.tc"
{
	if(CTypeIsComplex(node->type))
	{
		return ILNode_GenValue((ILNode *)node, info);
	}
	else
	{
		return ILTypeToMachineType(node->decayedType);
	}
}
#line 1892 "c_nodes.c"

ILMachineType ILNode_CGlobalVar_ILNode_GetAndPrepare__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 1526 "c_lvalue.tc"
{
	if(info->asmOutput)
	{
		fputs("\tldsfld\t", info->asmOutput);
		ILDumpType(info->asmOutput, info->image, node->type,
				   IL_DUMP_QUOTE_NAMES);
		putc(' ', info->asmOutput);
		ILDumpIdentifier(info->asmOutput, node->name, 0,
						 IL_DUMP_QUOTE_NAMES);
		putc('\n', info->asmOutput);
	}
	ILGenAdjust(info, 1);
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	return ILTypeToMachineType(node->decayedType);
}
#line 1915 "c_nodes.c"

void ILNode_CGlobalVar_ILNode_Store__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1550 "c_lvalue.tc"
{
	if(!CTypeIsComplex(node->type))
	{
		/* Handle a non-complex type */
		if(leave)
		{
			ILGenSimple(info, IL_OP_DUP);
			ILGenAdjust(info, 1);
		}
		fputs("\tstsfld\t", info->asmOutput);
		ILDumpType(info->asmOutput, info->image, node->type,
				   IL_DUMP_QUOTE_NAMES);
		putc(' ', info->asmOutput);
		ILDumpIdentifier(info->asmOutput, node->name, 0,
						 IL_DUMP_QUOTE_NAMES);
		putc('\n', info->asmOutput);
		ILGenAdjust(info, -1);
	}
	else
	{
		/* Copy the complex value into the pointer on the stack */
		CGenSizeOf(info, node->type);
		ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 1);
		ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
		ILGenAdjust(info, -3);

		/* Push the address of the global variable in leave mode */
		if(leave)
		{
			ILNode_GenValue((ILNode *)node, info);
		}
	}
}
#line 1952 "c_nodes.c"

void ILNode_CGlobalVar_ILNode_GenRef__(ILNode_CGlobalVar *node, ILGenInfo * info)
#line 1588 "c_lvalue.tc"
{
	if(info->asmOutput)
	{
		if(CTypeIsComplex(node->type))
		{
			fputs("\tldsfld\t", info->asmOutput);
		}
		else
		{
			fputs("\tldsflda\t", info->asmOutput);
		}
		ILDumpType(info->asmOutput, info->image, node->type,
				   IL_DUMP_QUOTE_NAMES);
		putc(' ', info->asmOutput);
		if(CTypeIsComplex(node->type))
		{
			fputs("* ", info->asmOutput);
		}
		ILDumpIdentifier(info->asmOutput, node->name, 0,
						 IL_DUMP_QUOTE_NAMES);
		putc('\n', info->asmOutput);
	}
	ILGenAdjust(info, 1);
}
#line 1980 "c_nodes.c"

ILMachineType ILNode_CGlobalVar_JavaPrepare__(ILNode_CGlobalVar *node, ILGenInfo * info, void * * data1, void * * data2)
#line 1631 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return ILTypeToMachineType(node->decayedType);
}
#line 1988 "c_nodes.c"

ILMachineType ILNode_CGlobalVar_JavaGetAndPrepare__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 1631 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return ILTypeToMachineType(node->decayedType);
}
#line 1996 "c_nodes.c"

void ILNode_CGlobalVar_JavaStore__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1636 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
}
#line 2003 "c_nodes.c"

struct ILNode_CGlobalVar_vtable__ const ILNode_CGlobalVar_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_CGlobalVar_kind,
	"ILNode_CGlobalVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CGlobalVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CGlobalVar_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CGlobalVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CGlobalVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CGlobalVar_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CGlobalVar_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CGlobalVar_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CGlobalVar_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CGlobalVar_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CGlobalVar_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CGlobalVar_JavaStore__,
};

struct ILNode_CFieldAccess_vtable__ const ILNode_CFieldAccess_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_CFieldAccess_kind,
	"ILNode_CFieldAccess",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))0,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))0,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))0,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))0,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))0,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))0,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))0,
};

ILMachineType ILNode_CDeref_ILNode_GetType__(ILNode_CDeref *node, ILGenInfo * info)
#line 2166 "c_lvalue.tc"
{
	if(CTypeIsComplex(node->type))
	{
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return node->machineType;
	}
}
#line 2065 "c_nodes.c"

void ILNode_CDeref_ILNode_GenDiscard__(ILNode_CDeref *node, ILGenInfo * info)
#line 2181 "c_lvalue.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 2072 "c_nodes.c"

ILMachineType ILNode_CDeref_ILNode_GenValue__(ILNode_CDeref *node, ILGenInfo * info)
#line 2189 "c_lvalue.tc"
{
	ILNode_GenValue(node->expr, info);
	return ILTypeToMachineType(LoadValueFromPointer(info, node->type));
}
#line 2080 "c_nodes.c"

ILMachineType ILNode_CDeref_JavaGenValue__(ILNode_CDeref *node, ILGenInfo * info)
#line 2194 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return node->machineType;
}
#line 2088 "c_nodes.c"

ILMachineType ILNode_CDeref_ILNode_Prepare__(ILNode_CDeref *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2203 "c_lvalue.tc"
{
	ILNode_GenValue(node->expr, info);
	return ILNode_GetType((ILNode *)node, info);
}
#line 2096 "c_nodes.c"

ILMachineType ILNode_CDeref_ILNode_GetAndPrepare__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2217 "c_lvalue.tc"
{
	ILType *tempType = ILTypeStripPrefixes(node->type);
	ILNode_GenValue(node->expr, info);
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);
	tempType = LoadValueFromPointer(info, tempType);
	if(leave)
	{
		/* Rearrange the stack to leave the value in the correct position */
		unsigned tempVar1 = ILGenTempTypedVar(info, tempType);
		unsigned tempVar2 = ILGenTempTypedVar(info, ILType_Int);
		ILGenStoreLocal(info, tempVar1);
		ILGenStoreLocal(info, tempVar2);
		ILGenLoadLocal(info, tempVar1);
		ILGenLoadLocal(info, tempVar2);
		ILGenLoadLocal(info, tempVar1);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar1);
		ILGenReleaseTempVar(info, tempVar2);
	}
	return ILTypeToMachineType(tempType);
}
#line 2122 "c_nodes.c"

void ILNode_CDeref_ILNode_Store__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2249 "c_lvalue.tc"
{
	StoreValueToPointer(info, node->type, 0, leave);
}
#line 2129 "c_nodes.c"

void ILNode_CDeref_ILNode_GenRef__(ILNode_CDeref *node, ILGenInfo * info)
#line 2261 "c_lvalue.tc"
{
	CGenAddress(info, (ILNode *)node);
}
#line 2136 "c_nodes.c"

ILMachineType ILNode_CDeref_JavaPrepare__(ILNode_CDeref *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2208 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return node->machineType;
}
#line 2144 "c_nodes.c"

ILMachineType ILNode_CDeref_JavaGetAndPrepare__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2240 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return node->machineType;
}
#line 2152 "c_nodes.c"

void ILNode_CDeref_JavaStore__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2253 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
}
#line 2159 "c_nodes.c"

struct ILNode_CDeref_vtable__ const ILNode_CDeref_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_CDeref_kind,
	"ILNode_CDeref",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDeref_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CDeref_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDeref_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDeref_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CDeref_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CDeref_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CDeref_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CDeref_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CDeref_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CDeref_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CDeref_JavaStore__,
};

ILMachineType ILNode_CBitField_ILNode_GetType__(ILNode_CBitField *node, ILGenInfo * info)
#line 2281 "c_lvalue.tc"
{
	return node->machineType;
}
#line 2190 "c_nodes.c"

ILMachineType ILNode_CBitField_ILNode_GenValue__(ILNode_CBitField *node, ILGenInfo * info)
#line 2476 "c_lvalue.tc"
{
	ILType *ownerType;

	/* Push the address or value onto the stack */
	if(node->genExprAsAddr)
	{
		ILNode_GenRef((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		ILNode_GenValue(node->expr, info);
	}

	/* Load the contents of the storage field */
	ownerType = ILClassToType(ILField_Owner(node->field));
	if(CTypeIsComplex(ownerType))
	{
		CAddComplexFieldOffset(info, ownerType, node->field);
		LoadValueFromPointer(info, ILField_Type(node->field));
	}
	else
	{
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	}

	/* Mask off unnecessary bits, shift down, and sign-extend */
	RawToBitField(info, node->machineType, node->bitFieldStart,
				  node->bitFieldSize);

	/* Done */
	return node->machineType;
}
#line 2226 "c_nodes.c"

ILMachineType ILNode_CBitField_JavaGenValue__(ILNode_CBitField *node, ILGenInfo * info)
#line 2509 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return node->machineType;
}
#line 2234 "c_nodes.c"

ILMachineType ILNode_CBitField_ILNode_Prepare__(ILNode_CBitField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2518 "c_lvalue.tc"
{
	ILType *ownerType = ILClassToType(ILField_Owner(node->field));

	/* Push the address of the structure onto the stack */
	if(node->genExprAsAddr)
	{
		ILNode_GenRef((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		ILNode_GenValue(node->expr, info);
	}
	if(CTypeIsComplex(ownerType))
	{
		CAddComplexFieldOffset(info, ownerType, node->field);
	}

	/* Save a copy of the pointer so that we can fetch the other bits later */
	node->tempPtrVar = ILGenTempVar(info, ILMachineType_NativeInt);
	ILGenSimple(info, IL_OP_DUP);
	ILGenStoreLocal(info, node->tempPtrVar);
	ILGenExtend(info, 1);

	/* The bit field is prepared */
	return node->machineType;
}
#line 2264 "c_nodes.c"

ILMachineType ILNode_CBitField_ILNode_GetAndPrepare__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2554 "c_lvalue.tc"
{
	ILType *ownerType = ILClassToType(ILField_Owner(node->field));

	/* Push the address of the structure onto the stack */
	if(node->genExprAsAddr)
	{
		ILNode_GenRef((ILNode_LValue *)(node->expr), info);
	}
	else
	{
		ILNode_GenValue(node->expr, info);
	}
	if(CTypeIsComplex(ownerType))
	{
		CAddComplexFieldOffset(info, ownerType, node->field);
	}

	/* Save a copy of the pointer so that we can fetch the other bits later */
	node->tempPtrVar = ILGenTempVar(info, ILMachineType_NativeInt);
	ILGenSimple(info, IL_OP_DUP);
	ILGenStoreLocal(info, node->tempPtrVar);
	ILGenExtend(info, 1);

	/* Fetch the current value of the storage field */
	if(CTypeIsComplex(ownerType))
	{
		LoadValueFromPointer(info, ILField_Type(node->field));
	}
	else
	{
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	}

	/* Extract the bit field value */
	RawToBitField(info, node->machineType, node->bitFieldStart,
				  node->bitFieldSize);

	/* Save a copy of the value if we need to leave it on the stack */
	if(leave)
	{
		node->tempVar = ILGenTempVar(info, node->machineType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, node->tempVar);
		ILGenExtend(info, 1);
	}

	/* The bit field is prepared */
	return node->machineType;
}
#line 2317 "c_nodes.c"

void ILNode_CBitField_ILNode_Store__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2613 "c_lvalue.tc"
{
	ILType *ownerType = ILClassToType(ILField_Owner(node->field));
	unsigned tempVar = ~((unsigned)0);

	/* Save the value in a temporary variable if we need to leave it */
	if(leave)
	{
		tempVar = ILGenTempVar(info, node->machineType);
		ILGenSimple(info, IL_OP_DUP);
		ILGenStoreLocal(info, tempVar);
		ILGenExtend(info, 1);
	}

	/* Shift the bit field into its final position */
	BitFieldToRaw(info, node->machineType, node->bitFieldStart,
				  node->bitFieldSize);

	/* Load the other bits and combine them with the new value */
	ILGenLoadLocal(info, node->tempPtrVar);
	ILGenAdjust(info, 1);
	if(CTypeIsComplex(ownerType))
	{
		LoadValueFromPointer(info, ILField_Type(node->field));
	}
	else
	{
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	}
	if(node->machineType == ILMachineType_Int64 ||
	   node->machineType == ILMachineType_UInt64)
	{
		ILGenUInt64(info, ~(((((ILUInt64)1) << node->bitFieldSize) - 1)
								<< node->bitFieldStart));
		ILGenSimple(info, IL_OP_AND);
		ILGenExtend(info, 1);
	}
	else
	{
		ILGenUInt32(info, ~(((((ILUInt32)1) << node->bitFieldSize) - 1)
								<< node->bitFieldStart));
		ILGenSimple(info, IL_OP_AND);
		ILGenExtend(info, 1);
	}
	ILGenSimple(info, IL_OP_OR);
	ILGenAdjust(info, -1);
	ILGenReleaseTempVar(info, node->tempPtrVar);

	/* Store the combined value back into the storage field */
	if(CTypeIsComplex(ownerType))
	{
		StoreValueToPointer(info, ILField_Type(node->field), 0, 0);
	}
	else
	{
		ILGenFieldRef(info, IL_OP_STFLD, node->field);
		ILGenAdjust(info, -2);
	}

	/* Reload the value onto the stack if necessary */
	if(leave)
	{
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar);
	}

	/* Did we have a "left" value from the "GetAndPrepare" call? */
	if(node->tempVar != ~((unsigned)0))
	{
		ILGenLoadLocal(info, node->tempVar);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, node->tempVar);
		node->tempVar = ~((unsigned)0);
	}
}
#line 2396 "c_nodes.c"

ILMachineType ILNode_CBitField_JavaPrepare__(ILNode_CBitField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 2545 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return node->machineType;
}
#line 2404 "c_nodes.c"

ILMachineType ILNode_CBitField_JavaGetAndPrepare__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 2604 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
	return node->machineType;
}
#line 2412 "c_nodes.c"

void ILNode_CBitField_JavaStore__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 2689 "c_lvalue.tc"
{
	/* Never called: nothing to do here */
}
#line 2419 "c_nodes.c"

struct ILNode_CBitField_vtable__ const ILNode_CBitField_vt__ = {
	&ILNode_LValueNoRef_vt__,
	ILNode_CBitField_kind,
	"ILNode_CBitField",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CBitField_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CBitField_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CBitField_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CBitField_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CBitField_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CBitField_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRef_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CBitField_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CBitField_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CBitField_JavaStore__,
};

ILMachineType ILNode_CArrayAccess_ILNode_GetType__(ILNode_CArrayAccess *node, ILGenInfo * info)
#line 1758 "c_lvalue.tc"
{
	if(CTypeIsComplex(node->elemType))
	{
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return ILTypeToMachineType(node->elemType);
	}
}
#line 2457 "c_nodes.c"

ILMachineType ILNode_CArrayAccess_ILNode_GenValue__(ILNode_CArrayAccess *node, ILGenInfo * info)
#line 1773 "c_lvalue.tc"
{
	ILType *type = node->elemType;

	/* Push the address of the array element onto the stack */
	CGenAddress(info, (ILNode *)node);

	/* Load the value from the pointer if not a sub-array */
	if(node->elemType == CTypeGetPtrRef(node->arrayType))
	{
		type = LoadValueFromPointer(info, type);
	}

	/* Return the machine type for the element */
	return ILTypeToMachineType(type);
}
#line 2476 "c_nodes.c"

int ILNode_CArrayAccess_ILNode_EvalConst__(ILNode_CArrayAccess *node, ILGenInfo * info, ILEvalValue * value)
#line 2030 "c_lvalue.tc"
{
	ILEvalValue arrayValue;
	ILEvalValue indexValue;
	CTypeLayoutInfo layout;
	ILUInt32 size;
	ILInt64 ptr;

	/* Evaluate the two arguments */
	if(!ILNode_EvalConst(node->array, info, &arrayValue) ||
	   arrayValue.valueType != ILMachineType_UnmanagedPtr ||
	   !ILNode_EvalConst(node->indices, info, &indexValue))
	{
		return 0;
	}

	/* Get the size of the array element type */
	CTypeGetLayoutInfo(node->elemType, &layout);
	if(layout.category != C_TYPECAT_FIXED)
	{
		return 0;
	}
	size = layout.size;

	/* Compute the new constant pointer value */
	ptr = (ILInt64)(arrayValue.un.i4Value);
	switch(indexValue.valueType)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		{
			ptr += ((ILInt64)(indexValue.un.i4Value)) * ((ILInt64)size);
		}
		break;

		case ILMachineType_UInt32:
		{
			ptr += ((ILInt64)(ILUInt32)(indexValue.un.i4Value))
						* ((ILInt64)size);
		}
		break;

		case ILMachineType_Int64:
		{
			if(indexValue.un.i8Value >= (ILInt64)IL_MIN_INT32 &&
			   indexValue.un.i8Value <= (ILInt64)IL_MAX_INT32)
			{
				ptr += indexValue.un.i8Value * ((ILInt64)size);
			}
			else
			{
				return 0;
			}
		}
		break;

		case ILMachineType_UInt64:
		{
			if(indexValue.un.i8Value >= 0 &&
			   indexValue.un.i8Value <= (ILInt64)IL_MAX_INT32)
			{
				ptr += indexValue.un.i8Value * ((ILInt64)size);
			}
			else
			{
				return 0;
			}
		}
		break;

		default: return 0;
	}

	/* Bail out if the constant pointer is outside the 32-bit range */
	if(ptr < (ILInt64)IL_MIN_INT32 || ptr > (ILInt64)IL_MAX_INT32)
	{
		return 0;
	}

	/* Create the new constant pointer value and return it */
	arrayValue.valueType = ILMachineType_UnmanagedPtr;
	arrayValue.un.i4Value = (ILInt32)ptr;
	return 1;
}
#line 2567 "c_nodes.c"

ILMachineType ILNode_CArrayAccess_ILNode_Prepare__(ILNode_CArrayAccess *node, ILGenInfo * info, void * * data1, void * * data2)
#line 1793 "c_lvalue.tc"
{
	/* Push the address of the array element onto the stack */
	CGenAddress(info, (ILNode *)node);

	/* Return the machine type for the element */
	return ILTypeToMachineType(node->elemType);
}
#line 2578 "c_nodes.c"

ILMachineType ILNode_CArrayAccess_ILNode_GetAndPrepare__(ILNode_CArrayAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 1805 "c_lvalue.tc"
{
	ILType *tempType;
	unsigned tempVar1;
	unsigned tempVar2;

	/* Push the address of the array element onto the stack */
	CGenAddress(info, (ILNode *)node);

	/* Duplicate the pointer on the stack for the store */
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);

	/* Load the current value from the pointer */
	tempType = LoadValueFromPointer(info, node->elemType);

	/* Rearrange the contents of the stack if "leave" is set */
	if(leave)
	{
		tempVar1 = ILGenTempTypedVar(info, ILType_Int);
		tempVar2 = ILGenTempTypedVar(info, tempType);
		ILGenStoreLocal(info, tempVar2);
		ILGenStoreLocal(info, tempVar1);
		ILGenLoadLocal(info, tempVar2);
		ILGenLoadLocal(info, tempVar1);
		ILGenLoadLocal(info, tempVar2);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar1);
		ILGenReleaseTempVar(info, tempVar2);
	}

	/* Return the machine type for the element */
	return ILTypeToMachineType(tempType);
}
#line 2615 "c_nodes.c"

void ILNode_CArrayAccess_ILNode_Store__(ILNode_CArrayAccess *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 1843 "c_lvalue.tc"
{
	StoreValueToPointer(info, node->elemType, 0, leave);
}
#line 2622 "c_nodes.c"

void ILNode_CArrayAccess_ILNode_GenRef__(ILNode_CArrayAccess *node, ILGenInfo * info)
#line 1851 "c_lvalue.tc"
{
	/* Generate the address of this node, and force its
	   conversion into a pointer value on the stack */
	CGenAddress(info, (ILNode *)node);
}
#line 2631 "c_nodes.c"

struct ILNode_CArrayAccess_vtable__ const ILNode_CArrayAccess_vt__ = {
	&ILNode_ArrayAccess_vt__,
	ILNode_CArrayAccess_kind,
	"ILNode_CArrayAccess",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArrayAccess_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArrayAccess_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_CArrayAccess_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ArrayAccess_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CArrayAccess_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CArrayAccess_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CArrayAccess_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CArrayAccess_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_ArrayAccess_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_ArrayAccess_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_ArrayAccess_JavaStore__,
};

ILMachineType ILNode_CDerefField_ILNode_GetType__(ILNode_CDerefField *node, ILGenInfo * info)
#line 237 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsArray(type))
	{
		/* Arrays decay to r-value pointers when accessed */
		return ILMachineType_UnmanagedPtr;
	}
	else if(CTypeIsComplex(type))
	{
		/* Complex types are passed on the stack as a pointer */
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return ILTypeToMachineType(type);
	}
}
#line 2676 "c_nodes.c"

void ILNode_CDerefField_ILNode_GenDiscard__(ILNode_CDerefField *node, ILGenInfo * info)
#line 260 "c_lvalue.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 2683 "c_nodes.c"

ILMachineType ILNode_CDerefField_ILNode_GenValue__(ILNode_CDerefField *node, ILGenInfo * info)
#line 385 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsComplex(node->ownerType))
	{
		/* Fetch a field from a complex owner type */
		CGenAddress(info, (ILNode *)node);
		return ILTypeToMachineType(LoadValueFromPointer(info, type));
	}
	if(yyisa(node, ILNode_CMemberField) && yyisa(node->expr, ILNode_LValue))
	{
		CGenAddress(info, node->expr);
	}
	else
	{
		ILNode_GenValue(node->expr, info);
	}
	if(CTypeIsArray(type))
	{
		/* Arrays decay to r-value pointers when accessed */
		ILGenFieldRef(info, IL_OP_LDFLDA, node->field);
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
		return ILTypeToMachineType(type);
	}
}
#line 2715 "c_nodes.c"

ILMachineType ILNode_CDerefField_JavaGenValue__(ILNode_CDerefField *node, ILGenInfo * info)
#line 415 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 2723 "c_nodes.c"

ILMachineType ILNode_CDerefField_ILNode_Prepare__(ILNode_CDerefField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 425 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsComplex(type) || CTypeIsComplex(node->ownerType))
	{
		CGenAddress(info, (ILNode *)node);
		return ILTypeToMachineType(type);
	}
	else if(yyisa(node, ILNode_CMemberField))
	{
		CGenAddress(info, node->expr);
		return ILTypeToMachineType(type);
	}
	else
	{
		ILNode_GenValue(node->expr, info);
		return ILTypeToMachineType(type);
	}
}
#line 2745 "c_nodes.c"

ILMachineType ILNode_CDerefField_ILNode_GetAndPrepare__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 455 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	ILType *tempType = type;
	if(CTypeIsComplex(node->ownerType) || CTypeIsComplex(type))
	{
		/* Fetch a field from a complex owner type or a complex field */
		CGenAddress(info, (ILNode *)node);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		tempType = LoadValueFromPointer(info, type);
	}
	else if(yyisa(node, ILNode_CMemberField))
	{
		/* Fetch a field from a non-complex owner type (member form) */
		CGenAddress(info, node->expr);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	}
	else
	{
		/* Fetch a field from a non-complex owner type (deref form) */
		ILNode_GenValue(node->expr, info);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	}
	if(leave)
	{
		/* Rearrange the stack to leave the value in the correct position */
		unsigned tempVar1 = ILGenTempTypedVar(info, tempType);
		unsigned tempVar2 = ILGenTempTypedVar(info, ILType_Int);
		ILGenStoreLocal(info, tempVar1);
		ILGenStoreLocal(info, tempVar2);
		ILGenLoadLocal(info, tempVar1);
		ILGenLoadLocal(info, tempVar2);
		ILGenLoadLocal(info, tempVar1);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar1);
		ILGenReleaseTempVar(info, tempVar2);
	}
	return ILTypeToMachineType(tempType);
}
#line 2792 "c_nodes.c"

void ILNode_CDerefField_ILNode_Store__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 510 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsComplex(node->ownerType) || CTypeIsComplex(type))
	{
		StoreValueToPointer(info, type, 0, leave);
	}
	else
	{
		StoreValueToPointer(info, type, node->field, leave);
	}
}
#line 2807 "c_nodes.c"

void ILNode_CDerefField_ILNode_GenRef__(ILNode_CDerefField *node, ILGenInfo * info)
#line 532 "c_lvalue.tc"
{
	CGenAddress(info, (ILNode *)node);
}
#line 2814 "c_nodes.c"

ILMachineType ILNode_CDerefField_JavaPrepare__(ILNode_CDerefField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 445 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 2822 "c_nodes.c"

ILMachineType ILNode_CDerefField_JavaGetAndPrepare__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 500 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 2830 "c_nodes.c"

void ILNode_CDerefField_JavaStore__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 523 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
}
#line 2837 "c_nodes.c"

struct ILNode_CDerefField_vtable__ const ILNode_CDerefField_vt__ = {
	&ILNode_CFieldAccess_vt__,
	ILNode_CDerefField_kind,
	"ILNode_CDerefField",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDerefField_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CDerefField_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDerefField_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDerefField_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CDerefField_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CDerefField_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CDerefField_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CDerefField_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CDerefField_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CDerefField_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CDerefField_JavaStore__,
};

ILMachineType ILNode_CMemberField_ILNode_GetType__(ILNode_CMemberField *node, ILGenInfo * info)
#line 237 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsArray(type))
	{
		/* Arrays decay to r-value pointers when accessed */
		return ILMachineType_UnmanagedPtr;
	}
	else if(CTypeIsComplex(type))
	{
		/* Complex types are passed on the stack as a pointer */
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return ILTypeToMachineType(type);
	}
}
#line 2882 "c_nodes.c"

void ILNode_CMemberField_ILNode_GenDiscard__(ILNode_CMemberField *node, ILGenInfo * info)
#line 260 "c_lvalue.tc"
{
	ILNode_GenDiscard(node->expr, info);
}
#line 2889 "c_nodes.c"

ILMachineType ILNode_CMemberField_ILNode_GenValue__(ILNode_CMemberField *node, ILGenInfo * info)
#line 385 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsComplex(node->ownerType))
	{
		/* Fetch a field from a complex owner type */
		CGenAddress(info, (ILNode *)node);
		return ILTypeToMachineType(LoadValueFromPointer(info, type));
	}
	if(yyisa(node, ILNode_CMemberField) && yyisa(node->expr, ILNode_LValue))
	{
		CGenAddress(info, node->expr);
	}
	else
	{
		ILNode_GenValue(node->expr, info);
	}
	if(CTypeIsArray(type))
	{
		/* Arrays decay to r-value pointers when accessed */
		ILGenFieldRef(info, IL_OP_LDFLDA, node->field);
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
		return ILTypeToMachineType(type);
	}
}
#line 2921 "c_nodes.c"

ILMachineType ILNode_CMemberField_JavaGenValue__(ILNode_CMemberField *node, ILGenInfo * info)
#line 415 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 2929 "c_nodes.c"

ILMachineType ILNode_CMemberField_ILNode_Prepare__(ILNode_CMemberField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 425 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsComplex(type) || CTypeIsComplex(node->ownerType))
	{
		CGenAddress(info, (ILNode *)node);
		return ILTypeToMachineType(type);
	}
	else if(yyisa(node, ILNode_CMemberField))
	{
		CGenAddress(info, node->expr);
		return ILTypeToMachineType(type);
	}
	else
	{
		ILNode_GenValue(node->expr, info);
		return ILTypeToMachineType(type);
	}
}
#line 2951 "c_nodes.c"

ILMachineType ILNode_CMemberField_ILNode_GetAndPrepare__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 455 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	ILType *tempType = type;
	if(CTypeIsComplex(node->ownerType) || CTypeIsComplex(type))
	{
		/* Fetch a field from a complex owner type or a complex field */
		CGenAddress(info, (ILNode *)node);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		tempType = LoadValueFromPointer(info, type);
	}
	else if(yyisa(node, ILNode_CMemberField))
	{
		/* Fetch a field from a non-complex owner type (member form) */
		CGenAddress(info, node->expr);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	}
	else
	{
		/* Fetch a field from a non-complex owner type (deref form) */
		ILNode_GenValue(node->expr, info);
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
		ILGenFieldRef(info, IL_OP_LDFLD, node->field);
	}
	if(leave)
	{
		/* Rearrange the stack to leave the value in the correct position */
		unsigned tempVar1 = ILGenTempTypedVar(info, tempType);
		unsigned tempVar2 = ILGenTempTypedVar(info, ILType_Int);
		ILGenStoreLocal(info, tempVar1);
		ILGenStoreLocal(info, tempVar2);
		ILGenLoadLocal(info, tempVar1);
		ILGenLoadLocal(info, tempVar2);
		ILGenLoadLocal(info, tempVar1);
		ILGenAdjust(info, 1);
		ILGenReleaseTempVar(info, tempVar1);
		ILGenReleaseTempVar(info, tempVar2);
	}
	return ILTypeToMachineType(tempType);
}
#line 2998 "c_nodes.c"

void ILNode_CMemberField_ILNode_Store__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 510 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsComplex(node->ownerType) || CTypeIsComplex(type))
	{
		StoreValueToPointer(info, type, 0, leave);
	}
	else
	{
		StoreValueToPointer(info, type, node->field, leave);
	}
}
#line 3013 "c_nodes.c"

void ILNode_CMemberField_ILNode_GenRef__(ILNode_CMemberField *node, ILGenInfo * info)
#line 532 "c_lvalue.tc"
{
	CGenAddress(info, (ILNode *)node);
}
#line 3020 "c_nodes.c"

ILMachineType ILNode_CMemberField_JavaPrepare__(ILNode_CMemberField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 445 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 3028 "c_nodes.c"

ILMachineType ILNode_CMemberField_JavaGetAndPrepare__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 500 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 3036 "c_nodes.c"

void ILNode_CMemberField_JavaStore__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 523 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
}
#line 3043 "c_nodes.c"

struct ILNode_CMemberField_vtable__ const ILNode_CMemberField_vt__ = {
	&ILNode_CFieldAccess_vt__,
	ILNode_CMemberField_kind,
	"ILNode_CMemberField",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CMemberField_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CMemberField_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CMemberField_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CMemberField_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CMemberField_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CMemberField_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CMemberField_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CMemberField_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CMemberField_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CMemberField_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CMemberField_JavaStore__,
};

ILMachineType ILNode_CStaticField_ILNode_GetType__(ILNode_CStaticField *node, ILGenInfo * info)
#line 789 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsArray(type))
	{
		/* Arrays decay to r-value pointers when accessed */
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		return ILTypeToMachineType(type);
	}
}
#line 3083 "c_nodes.c"

void ILNode_CStaticField_ILNode_GenDiscard__(ILNode_CStaticField *node, ILGenInfo * info)
#line 806 "c_lvalue.tc"
{
	/* Nothing to do here */
}
#line 3090 "c_nodes.c"

ILMachineType ILNode_CStaticField_ILNode_GenValue__(ILNode_CStaticField *node, ILGenInfo * info)
#line 814 "c_lvalue.tc"
{
	ILType *type = ILField_Type(node->field);
	if(CTypeIsArray(type))
	{
		/* Arrays decay to r-value pointers when accessed */
		ILGenFieldRef(info, IL_OP_LDSFLDA, node->field);
		return ILMachineType_UnmanagedPtr;
	}
	else
	{
		ILGenFieldRef(info, IL_OP_LDSFLD, node->field);
		return ILTypeToMachineType(type);
	}
}
#line 3108 "c_nodes.c"

ILMachineType ILNode_CStaticField_JavaGenValue__(ILNode_CStaticField *node, ILGenInfo * info)
#line 829 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 3116 "c_nodes.c"

ILMachineType ILNode_CStaticField_ILNode_Prepare__(ILNode_CStaticField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 838 "c_lvalue.tc"
{
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 3123 "c_nodes.c"

ILMachineType ILNode_CStaticField_ILNode_GetAndPrepare__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 851 "c_lvalue.tc"
{
	ILGenFieldRef(info, IL_OP_LDSFLD, node->field);
	if(leave)
	{
		/* Duplicate the stack top to create the left value */
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	return ILTypeToMachineType(ILField_Type(node->field));
}
#line 3137 "c_nodes.c"

void ILNode_CStaticField_ILNode_Store__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 871 "c_lvalue.tc"
{
	if(leave)
	{
		ILGenSimple(info, IL_OP_DUP);
		ILGenAdjust(info, 1);
	}
	ILGenFieldRef(info, IL_OP_STSFLD, node->field);
	ILGenAdjust(info, -1);
}
#line 3150 "c_nodes.c"

void ILNode_CStaticField_ILNode_GenRef__(ILNode_CStaticField *node, ILGenInfo * info)
#line 889 "c_lvalue.tc"
{
	CGenAddress(info, (ILNode *)node);
}
#line 3157 "c_nodes.c"

ILMachineType ILNode_CStaticField_JavaPrepare__(ILNode_CStaticField *node, ILGenInfo * info, void * * data1, void * * data2)
#line 842 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 3165 "c_nodes.c"

ILMachineType ILNode_CStaticField_JavaGetAndPrepare__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2)
#line 862 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
	return ILMachineType_Void;
}
#line 3173 "c_nodes.c"

void ILNode_CStaticField_JavaStore__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * data1, void * data2)
#line 881 "c_lvalue.tc"
{
	/* Nothing to do here: will never be called */
}
#line 3180 "c_nodes.c"

struct ILNode_CStaticField_vtable__ const ILNode_CStaticField_vt__ = {
	&ILNode_CFieldAccess_vt__,
	ILNode_CStaticField_kind,
	"ILNode_CStaticField",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CStaticField_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CStaticField_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CStaticField_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CStaticField_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CStaticField_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CStaticField_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CStaticField_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_CStaticField_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_CStaticField_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_CStaticField_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_CStaticField_JavaStore__,
};

ILMachineType ILNode_SizeOfExpr_ILNode_GetType__(ILNode_SizeOfExpr *node, ILGenInfo * info)
#line 2655 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 3211 "c_nodes.c"

ILMachineType ILNode_SizeOfExpr_ILNode_GenValue__(ILNode_SizeOfExpr *node, ILGenInfo * info)
#line 2660 "c_oper.tc"
{
	CGenSizeOf(info, node->type);
	return ILMachineType_UInt32;
}
#line 3219 "c_nodes.c"

int ILNode_SizeOfExpr_ILNode_EvalConst__(ILNode_SizeOfExpr *node, ILGenInfo * info, ILEvalValue * value)
#line 2576 "c_oper.tc"
{
	CTypeLayoutInfo layout;
	if(!(node->type))
	{
		return 0;
	}
	CTypeGetLayoutInfo(node->type, &layout);
	if(layout.category == C_TYPECAT_FIXED)
	{
		/* The type's size can be evaluated to a compile-time constant */
		value->valueType = ILMachineType_UInt32;
		value->un.i4Value = (ILInt32)(layout.size);
		return 1;
	}
	else
	{
		/* We must compute this constant value dynamically at runtime */
		return 0;
	}
}
#line 3243 "c_nodes.c"

ILMachineType ILNode_SizeOfExpr_JavaGenValue__(ILNode_SizeOfExpr *node, ILGenInfo * info)
#line 2666 "c_oper.tc"
{
	/* Will never be called: nothing to do here */
	return ILMachineType_UInt32;
}
#line 3251 "c_nodes.c"

struct ILNode_SizeOfExpr_vtable__ const ILNode_SizeOfExpr_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_SizeOfExpr_kind,
	"ILNode_SizeOfExpr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOfExpr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOfExpr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_SizeOfExpr_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOfExpr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_SetJmp_ILNode_GetType__(ILNode_SetJmp *node, ILGenInfo * info)
#line 319 "c_builtin.tc"
{
	return ILMachineType_Int32;
}
#line 3275 "c_nodes.c"

ILMachineType ILNode_SetJmp_ILNode_GenValue__(ILNode_SetJmp *node, ILGenInfo * info)
#line 327 "c_builtin.tc"
{
	/* Push the pointer value for the "jmp_buf" onto the stack */
	ILNode_GenValue(node->expr, info);

	/* Generate the "setjmp" handling code */
	CGenSetJmp(info);

	/* The result is always an integer */
	return ILMachineType_Int32;
}
#line 3289 "c_nodes.c"

ILMachineType ILNode_SetJmp_JavaGenValue__(ILNode_SetJmp *node, ILGenInfo * info)
#line 338 "c_builtin.tc"
{
	/* Never called: nothing to do here */
	return ILMachineType_Int32;
}
#line 3297 "c_nodes.c"

struct ILNode_SetJmp_vtable__ const ILNode_SetJmp_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_SetJmp_kind,
	"ILNode_SetJmp",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SetJmp_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SetJmp_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SetJmp_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_AllocA_ILNode_GetType__(ILNode_AllocA *node, ILGenInfo * info)
#line 381 "c_builtin.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 3321 "c_nodes.c"

ILMachineType ILNode_AllocA_ILNode_GenValue__(ILNode_AllocA *node, ILGenInfo * info)
#line 389 "c_builtin.tc"
{
	/* Push the size value onto the stack */
	ILNode_GenValue(node->expr, info);

	/* Perform local memory allocation */
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_LOCALLOC);

	/* The result is always a pointer */
	return ILMachineType_UnmanagedPtr;
}
#line 3335 "c_nodes.c"

ILMachineType ILNode_AllocA_JavaGenValue__(ILNode_AllocA *node, ILGenInfo * info)
#line 400 "c_builtin.tc"
{
	/* Never called: nothing to do here */
	return ILMachineType_UnmanagedPtr;
}
#line 3343 "c_nodes.c"

struct ILNode_AllocA_vtable__ const ILNode_AllocA_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_AllocA_kind,
	"ILNode_AllocA",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AllocA_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AllocA_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AllocA_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CToCSharpString_ILNode_GetType__(ILNode_CToCSharpString *node, ILGenInfo * info)
#line 2181 "c_oper.tc"
{
	return ILMachineType_ObjectRef;
}
#line 3367 "c_nodes.c"

ILMachineType ILNode_CToCSharpString_ILNode_GenValue__(ILNode_CToCSharpString *node, ILGenInfo * info)
#line 2189 "c_oper.tc"
{
	/* Evaluate the C version of the string */
	ILNode_GenValue(node->expr, info);

	/* Use "Marshal.PtrToStringAnsi" to convert the string */
	ILGenCallByName(info, "class [.library]System.String "
						  "[.library]System.Runtime.InteropServices.Marshal::"
						  "PtrToStringAnsi(native int)");

	/* The result is always an object reference */
	return ILMachineType_ObjectRef;
}
#line 3383 "c_nodes.c"

ILMachineType ILNode_CToCSharpString_JavaGenValue__(ILNode_CToCSharpString *node, ILGenInfo * info)
#line 2202 "c_oper.tc"
{
	/* Java output is not supported */
	return ILMachineType_ObjectRef;
}
#line 3391 "c_nodes.c"

struct ILNode_CToCSharpString_vtable__ const ILNode_CToCSharpString_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_CToCSharpString_kind,
	"ILNode_CToCSharpString",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CToCSharpString_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CToCSharpString_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CToCSharpString_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CArrayInit_ILNode_GetType__(ILNode_CArrayInit *node, ILGenInfo * info)
#line 361 "c_ainit.tc"
{
	return ILMachineType_Void;
}
#line 3415 "c_nodes.c"

ILMachineType ILNode_CArrayInit_ILNode_GenValue__(ILNode_CArrayInit *node, ILGenInfo * info)
#line 361 "c_ainit.tc"
{
	return ILMachineType_Void;
}
#line 3422 "c_nodes.c"

ILMachineType ILNode_CArrayInit_JavaGenValue__(ILNode_CArrayInit *node, ILGenInfo * info)
#line 361 "c_ainit.tc"
{
	return ILMachineType_Void;
}
#line 3429 "c_nodes.c"

struct ILNode_CArrayInit_vtable__ const ILNode_CArrayInit_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_CArrayInit_kind,
	"ILNode_CArrayInit",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArrayInit_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArrayInit_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CArrayInit_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CBox_ILNode_GetType__(ILNode_CBox *node, ILGenInfo * info)
#line 2799 "c_oper.tc"
{
	return ILMachineType_ObjectRef;
}
#line 3453 "c_nodes.c"

ILMachineType ILNode_CBox_ILNode_GenValue__(ILNode_CBox *node, ILGenInfo * info)
#line 2799 "c_oper.tc"
{
	return ILMachineType_ObjectRef;
}
#line 3460 "c_nodes.c"

ILMachineType ILNode_CBox_JavaGenValue__(ILNode_CBox *node, ILGenInfo * info)
#line 2799 "c_oper.tc"
{
	return ILMachineType_ObjectRef;
}
#line 3467 "c_nodes.c"

struct ILNode_CBox_vtable__ const ILNode_CBox_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_CBox_kind,
	"ILNode_CBox",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CBox_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CBox_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CBox_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CopyComplex_ILNode_GetType__(ILNode_CopyComplex *node, ILGenInfo * info)
#line 370 "c_stmt.tc"
{
	/* We are always copying into a pointer */
	return ILMachineType_UnmanagedPtr;
}
#line 3492 "c_nodes.c"

ILMachineType ILNode_CopyComplex_ILNode_GenValue__(ILNode_CopyComplex *node, ILGenInfo * info)
#line 379 "c_stmt.tc"
{
	/* Allocate global memory for the value */
	CGenSizeOf(info, node->type);
	if(info->asmOutput)
	{
		fputs("\tcall\tnative int [.library]System.Runtime.InteropServices."
			  "Marshal::AllocHGlobal(int32)\n", info->asmOutput);
	}

	/* Duplicate the pointer because we need it for the return logic */
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);

	/* Push the value onto the stack that we will be returning */
	ILNode_GenValue(node->expr, info);

	/* Copy the value into the block that we allocated */
	CGenSizeOf(info, node->type);
	ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 1);
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
	ILGenAdjust(info, -3);

	/* The return type is a pointer */
	return ILMachineType_UnmanagedPtr;
}
#line 3521 "c_nodes.c"

ILMachineType ILNode_CopyComplex_JavaGenValue__(ILNode_CopyComplex *node, ILGenInfo * info)
#line 405 "c_stmt.tc"
{
	return ILMachineType_UnmanagedPtr;
}
#line 3528 "c_nodes.c"

struct ILNode_CopyComplex_vtable__ const ILNode_CopyComplex_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_CopyComplex_kind,
	"ILNode_CopyComplex",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CopyComplex_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CopyComplex_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CopyComplex_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CDelete_ILNode_GetType__(ILNode_CDelete *node, ILGenInfo * info)
#line 975 "c_invoke.tc"
{
	return ILMachineType_Void;
}
#line 3552 "c_nodes.c"

void ILNode_CDelete_ILNode_GenDiscard__(ILNode_CDelete *node, ILGenInfo * info)
#line 983 "c_invoke.tc"
{
	ILNode_GenValue(node->expr2, info);
	if(node->dtor)
	{
		/* Use the destructor that we discovered earlier */
		ILGenCallByMethod(info, node->dtor);
	}
	else
	{
		/* The default destructor calls the "free" function */
		ILGenCallByName(info, "void 'free'(void *)");
	}
	ILGenAdjust(info, -1);
}
#line 3570 "c_nodes.c"

ILMachineType ILNode_CDelete_ILNode_GenValue__(ILNode_CDelete *node, ILGenInfo * info)
#line 998 "c_invoke.tc"
{
	ILNode_GenDiscard(node, info);
	return ILMachineType_Void;
}
#line 3578 "c_nodes.c"

ILMachineType ILNode_CDelete_JavaGenValue__(ILNode_CDelete *node, ILGenInfo * info)
#line 1003 "c_invoke.tc"
{
	/* Nothing to do here */
	return ILMachineType_Void;
}
#line 3586 "c_nodes.c"

struct ILNode_CDelete_vtable__ const ILNode_CDelete_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_CDelete_kind,
	"ILNode_CDelete",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDelete_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CDelete_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDelete_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CDelete_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CSizeReleaseTempVar_ILNode_GetType__(ILNode_CSizeReleaseTempVar *node, ILGenInfo * info)
#line 2879 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 3610 "c_nodes.c"

ILMachineType ILNode_CSizeReleaseTempVar_ILNode_GenValue__(ILNode_CSizeReleaseTempVar *node, ILGenInfo * info)
#line 2907 "c_oper.tc"
{
	ILNode_CSizeTempVar *var = (ILNode_CSizeTempVar *)(node->expr2);
	ILNode_GenValue(node->expr1, info);
	if(var->tempVar != ~((unsigned)0))
	{
		ILGenReleaseTempVar(info, var->tempVar);
		var->tempVar = ~((unsigned)0);
	}
	return ILMachineType_UInt32;
}
#line 3624 "c_nodes.c"

ILMachineType ILNode_CSizeReleaseTempVar_JavaGenValue__(ILNode_CSizeReleaseTempVar *node, ILGenInfo * info)
#line 3051 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 3631 "c_nodes.c"

struct ILNode_CSizeReleaseTempVar_vtable__ const ILNode_CSizeReleaseTempVar_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_CSizeReleaseTempVar_kind,
	"ILNode_CSizeReleaseTempVar",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeReleaseTempVar_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeReleaseTempVar_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeReleaseTempVar_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CSizeMax_ILNode_GetType__(ILNode_CSizeMax *node, ILGenInfo * info)
#line 2879 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 3655 "c_nodes.c"

ILMachineType ILNode_CSizeMax_ILNode_GenValue__(ILNode_CSizeMax *node, ILGenInfo * info)
#line 2922 "c_oper.tc"
{
	unsigned tempVar1 = ILGenTempTypedVar(info, ILType_UInt32);
	unsigned tempVar2 = ILGenTempTypedVar(info, ILType_UInt32);
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;

	/* Compute the two values and store them in local variables */
	ILNode_GenValue(node->expr1, info);
	ILGenStoreLocal(info, tempVar1);
	ILGenAdjust(info, -1);
	ILNode_GenValue(node->expr2, info);
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);
	ILGenStoreLocal(info, tempVar2);
	ILGenAdjust(info, -1);

	/* Compare the two values (tempVar2 > tempVar1) */
	ILGenLoadLocal(info, tempVar1);
	ILGenAdjust(info, 1);
	ILGenJump(info, IL_OP_BGT, &label1);
	ILGenAdjust(info, -2);

	/* Push the result onto the stack */
	ILGenLoadLocal(info, tempVar1);
	ILGenJump(info, IL_OP_BR, &label2);
	ILGenLabel(info, &label1);
	ILGenLoadLocal(info, tempVar2);
	ILGenLabel(info, &label2);
	ILGenAdjust(info, 1);

	/* Free the temporary variables that we no longer require */
	ILGenReleaseTempVar(info, tempVar1);
	ILGenReleaseTempVar(info, tempVar2);
	return ILMachineType_UInt32;
}
#line 3694 "c_nodes.c"

ILMachineType ILNode_CSizeMax_JavaGenValue__(ILNode_CSizeMax *node, ILGenInfo * info)
#line 3051 "c_oper.tc"
{
	return ILMachineType_UInt32;
}
#line 3701 "c_nodes.c"

struct ILNode_CSizeMax_vtable__ const ILNode_CSizeMax_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_CSizeMax_kind,
	"ILNode_CSizeMax",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeMax_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeMax_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CSizeMax_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_CInvocationExpression_ILNode_GenValue__(ILNode_CInvocationExpression *node, ILGenInfo * info)
#line 485 "c_invoke.tc"
{
	ILMachineType resultType;
	long saveStack;

	/* Save the current stack height, so we know where to
	   unwind to when popping the arguments */
	saveStack = info->stackHeight;

	/* Push the argument expressions */
	if(node->expr2)
	{
		ILNode_GenValue(node->expr2, info);
	}

	/* Push the function pointer if this is not a call by name expression */
	if(!(node->name))
	{
		ILNode_GenValue(node->expr1, info);
	}

	/* Invoke the method */
	if(info->asmOutput)
	{
		if(node->name)
		{
			fputs("\tcall\t", info->asmOutput);
			ILDumpMethodType(info->asmOutput, info->image,
							 node->callSiteSig, IL_DUMP_QUOTE_NAMES,
							 0, node->name, 0);
			putc('\n', info->asmOutput);
		}
		else
		{
			fputs("\tcalli\t", info->asmOutput);
			ILDumpMethodType(info->asmOutput, info->image,
							 node->callSiteSig, IL_DUMP_QUOTE_NAMES,
							 0, "", 0);
			putc('\n', info->asmOutput);
		}
	}
	resultType = ILTypeToMachineType(ILTypeGetReturn(node->callSiteSig));

	/* Re-adjust the stack to remove the arguments */
	if(resultType == ILMachineType_Void)
	{
		info->stackHeight = saveStack;
	}
	else
	{
		info->stackHeight = saveStack + 1;
		if(info->stackHeight > info->maxStackHeight)
		{
			info->maxStackHeight = info->stackHeight;
		}
	}

	/* Done */
	return resultType;
}
#line 3781 "c_nodes.c"

struct ILNode_CInvocationExpression_vtable__ const ILNode_CInvocationExpression_vt__ = {
	&ILNode_InvocationExpression_vt__,
	ILNode_CInvocationExpression_kind,
	"ILNode_CInvocationExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_InvocationExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_CInvocationExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_InvocationExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

void ILNode_AsmStmt_ILNode_GenDiscard__(ILNode_AsmStmt *node, ILGenInfo * info)
#line 418 "c_builtin.tc"
{
	if(info->asmOutput)
	{
		/* We just assume that the code is correct and dump it as-is.
		   The assembler will report any errors that are present */
		fputs("// __asm__(\n", info->asmOutput);
		fputs(node->code, info->asmOutput);
		fputs("\n// )\n", info->asmOutput);
	}
}
#line 3812 "c_nodes.c"

int ILNode_AsmStmt_ILNode_EndsInReturnImpl__(ILNode_AsmStmt *node, ILGenInfo * info)
#line 463 "c_builtin.tc"
{
	const char *code = node->code;
	int end = strlen(code);
	int start;

	/* Find the start and end of the last line in the assembly code */
	while(end > 0 && (code[end - 1] == ' ' || code[end - 1] == '\t' ||
	                  code[end - 1] == '\n' || code[end - 1] == '\r'))
	{
		--end;
	}
	start = end;
	while(start > 0 && code[start - 1] != '\n' && code[start - 1] != '\r')
	{
		--start;
	}
	while(start < end && (code[start] == ' ' || code[start] == '\t'))
	{
		++start;
	}

	/* Check for instructions that cause a return to occur */
	if(AsmCheckFor(code + start, end - start, "ret") ||
	   AsmCheckFor(code + start, end - start, "throw") ||
	   AsmCheckFor(code + start, end - start, "rethrow") ||
	   AsmCheckFor(code + start, end - start, "br") ||
	   AsmCheckFor(code + start, end - start, "br.s") ||
	   AsmCheckFor(code + start, end - start, "leave") ||
	   AsmCheckFor(code + start, end - start, "leave.s") ||
	   AsmCheckFor(code + start, end - start, "endfinally") ||
	   AsmCheckFor(code + start, end - start, "endfilter"))
	{
		return IL_ENDS_IN_RETURN;
	}
	return 0;
}
#line 3852 "c_nodes.c"

void ILNode_AsmStmt_JavaGenDiscard__(ILNode_AsmStmt *node, ILGenInfo * info)
#line 429 "c_builtin.tc"
{
	/* Never called: nothing to do here */
}
#line 3859 "c_nodes.c"

struct ILNode_AsmStmt_vtable__ const ILNode_AsmStmt_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_AsmStmt_kind,
	"ILNode_AsmStmt",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AsmStmt_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_AsmStmt_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AsmStmt_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_CAssignArray_ILNode_GenDiscard__(ILNode_CAssignArray *node, ILGenInfo * info)
#line 777 "c_ainit.tc"
{
	ILNode_ListIter iter;
	ILUInt32 size;
	ILUInt32 wsize;

	/* Get the address of the array */
	CGenAddress(info, node->expr1);

	/* Write the initializer value into the array */
	if(yyisa(node->expr2, ILNode_CString))
	{
		ILNode_GenValue(node->expr2, info);
		size = CTypeGetNumElems(node->type);
		if(size > (((ILNode_CString *)(node->expr2))->len + 1))
		{
			size = ((ILNode_CString *)(node->expr2))->len + 1;
		}
		ILGenUInt32(info, size);
		ILGenAdjust(info, 1);
		ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 1);
		ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
		ILGenAdjust(info, -3);
	}
	else if(yyisa(node->expr2, ILNode_CWString))
	{
		ILNode_GenValue(node->expr2, info);
		size = CTypeGetNumElems(node->type);
		wsize = CGenWStringLength
				 (((ILNode_CWString *)(node->expr2))->str,
				  ((ILNode_CWString *)(node->expr2))->len);
		if(size > (wsize + 1))
		{
			size = wsize + 1;
		}
		ILGenUInt32(info, size * 2);
		ILGenAdjust(info, 1);
		ILGenByteInsn(info, IL_OP_PREFIX + IL_PREFIX_OP_UNALIGNED, 2);
		ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_CPBLK);
		ILGenAdjust(info, -3);
	}
	else
	{
		ILNode_ListIter_Init
			(&iter, ((ILNode_CArrayInit *)(node->expr2))->expr);
		WriteInitializer(info, node->type, &iter, 0);
	}
}
#line 3927 "c_nodes.c"

void ILNode_CAssignArray_JavaGenDiscard__(ILNode_CAssignArray *node, ILGenInfo * info)
#line 825 "c_ainit.tc"
{
	/* Nothing to do here */
}
#line 3934 "c_nodes.c"

struct ILNode_CAssignArray_vtable__ const ILNode_CAssignArray_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_CAssignArray_kind,
	"ILNode_CAssignArray",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CAssignArray_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CAssignArray_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_CAssignStruct_ILNode_GenDiscard__(ILNode_CAssignStruct *node, ILGenInfo * info)
#line 833 "c_ainit.tc"
{
	ILNode_ListIter iter;

	/* Get the address of the structure */
	CGenAddress(info, node->expr1);

	/* Write the initializer value into the structure */
	ILNode_ListIter_Init
		(&iter, ((ILNode_CArrayInit *)(node->expr2))->expr);
	WriteInitializer(info, node->type, &iter, 0);
}
#line 3966 "c_nodes.c"

void ILNode_CAssignStruct_JavaGenDiscard__(ILNode_CAssignStruct *node, ILGenInfo * info)
#line 845 "c_ainit.tc"
{
	/* Nothing to do here */
}
#line 3973 "c_nodes.c"

struct ILNode_CAssignStruct_vtable__ const ILNode_CAssignStruct_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_CAssignStruct_kind,
	"ILNode_CAssignStruct",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CAssignStruct_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CAssignStruct_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_CGotoPtr_ILNode_GenDiscard__(ILNode_CGotoPtr *node, ILGenInfo * info)
#line 1261 "c_stmt.tc"
{
	/* Evaluate the expression and convert it into an integer label number */
	ILGenCast(info, ILNode_GenValue(node->expr, info), ILMachineType_Int32);

	/* Jump to the end of the method, where we will place a
	   switch table to effect the actual indirection */
	ILGenJump(info, IL_OP_BR, &(info->gotoPtrLabel));
}
#line 4002 "c_nodes.c"

int ILNode_CGotoPtr_ILNode_EndsInReturnImpl__(ILNode_CGotoPtr *node, ILGenInfo * info)
#line 1253 "c_stmt.tc"
{
	return IL_ENDS_IN_GOTO;
}
#line 4009 "c_nodes.c"

void ILNode_CGotoPtr_JavaGenDiscard__(ILNode_CGotoPtr *node, ILGenInfo * info)
#line 1270 "c_stmt.tc"
{
	/* Nothing to do here */
}
#line 4016 "c_nodes.c"

struct ILNode_CGotoPtr_vtable__ const ILNode_CGotoPtr_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_CGotoPtr_kind,
	"ILNode_CGotoPtr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CGotoPtr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_CGotoPtr_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CGotoPtr_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

ILNode *ILNode_CDeclarator_create(CDeclarator decl)
{
	ILNode_CDeclarator *node__ = (ILNode_CDeclarator *)yynodealloc(sizeof(struct ILNode_CDeclarator__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CDeclarator_vt__;
	node__->kind__ = ILNode_CDeclarator_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->decl = decl;
	return (ILNode *)node__;
}

ILNode *ILNode_CSharpInvocation_create(ILType * type, char * name, ILNode * thisExpr, ILNode * args)
{
	ILNode_CSharpInvocation *node__ = (ILNode_CSharpInvocation *)yynodealloc(sizeof(struct ILNode_CSharpInvocation__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CSharpInvocation_vt__;
	node__->kind__ = ILNode_CSharpInvocation_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->name = name;
	node__->thisExpr = thisExpr;
	node__->args = args;
	return (ILNode *)node__;
}

ILNode *ILNode_CAttribute_create(char * name, ILNode * args)
{
	ILNode_CAttribute *node__ = (ILNode_CAttribute *)yynodealloc(sizeof(struct ILNode_CAttribute__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CAttribute_vt__;
	node__->kind__ = ILNode_CAttribute_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->args = args;
	return (ILNode *)node__;
}

ILNode *ILNode_CAttributeValue_create(ILEvalValue value)
{
	ILNode_CAttributeValue *node__ = (ILNode_CAttributeValue *)yynodealloc(sizeof(struct ILNode_CAttributeValue__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CAttributeValue_vt__;
	node__->kind__ = ILNode_CAttributeValue_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->value = value;
	return (ILNode *)node__;
}

ILNode *ILNode_CBitFieldDeclarator_create(CDeclarator decl, ILUInt32 bitFieldSize)
{
	ILNode_CBitFieldDeclarator *node__ = (ILNode_CBitFieldDeclarator *)yynodealloc(sizeof(struct ILNode_CBitFieldDeclarator__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CBitFieldDeclarator_vt__;
	node__->kind__ = ILNode_CBitFieldDeclarator_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->decl = decl;
	node__->bitFieldSize = bitFieldSize;
	return (ILNode *)node__;
}

ILNode *ILNode_CInitDeclarator_create(CDeclarator decl, ILNode * init)
{
	ILNode_CInitDeclarator *node__ = (ILNode_CInitDeclarator *)yynodealloc(sizeof(struct ILNode_CInitDeclarator__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CInitDeclarator_vt__;
	node__->kind__ = ILNode_CInitDeclarator_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->decl = decl;
	node__->init = init;
	return (ILNode *)node__;
}

ILNode *ILNode_SizeOfType_create(ILType * type)
{
	ILNode_SizeOfType *node__ = (ILNode_SizeOfType *)yynodealloc(sizeof(struct ILNode_SizeOfType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SizeOfType_vt__;
	node__->kind__ = ILNode_SizeOfType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_VaStart_create(ILNode * vaList, char * name)
{
	ILNode_VaStart *node__ = (ILNode_VaStart *)yynodealloc(sizeof(struct ILNode_VaStart__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_VaStart_vt__;
	node__->kind__ = ILNode_VaStart_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->vaList = vaList;
	node__->name = name;
	return (ILNode *)node__;
}

ILNode *ILNode_VaEnd_create(ILNode * vaList)
{
	ILNode_VaEnd *node__ = (ILNode_VaEnd *)yynodealloc(sizeof(struct ILNode_VaEnd__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_VaEnd_vt__;
	node__->kind__ = ILNode_VaEnd_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->vaList = vaList;
	return (ILNode *)node__;
}

ILNode *ILNode_VaArg_create(ILNode * vaList, ILType * type)
{
	ILNode_VaArg *node__ = (ILNode_VaArg *)yynodealloc(sizeof(struct ILNode_VaArg__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_VaArg_vt__;
	node__->kind__ = ILNode_VaArg_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->vaList = vaList;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_FunctionRef_create(char * name, ILType * signature)
{
	ILNode_FunctionRef *node__ = (ILNode_FunctionRef *)yynodealloc(sizeof(struct ILNode_FunctionRef__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_FunctionRef_vt__;
	node__->kind__ = ILNode_FunctionRef_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->signature = signature;
	return (ILNode *)node__;
}

ILNode *ILNode_CLabelRef_create(char * name)
{
	ILNode_CLabelRef *node__ = (ILNode_CLabelRef *)yynodealloc(sizeof(struct ILNode_CLabelRef__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CLabelRef_vt__;
	node__->kind__ = ILNode_CLabelRef_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->labelNum = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CSharpTypeOf_create(ILType * type)
{
	ILNode_CSharpTypeOf *node__ = (ILNode_CSharpTypeOf *)yynodealloc(sizeof(struct ILNode_CSharpTypeOf__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CSharpTypeOf_vt__;
	node__->kind__ = ILNode_CSharpTypeOf_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_CTypeExpression_create(ILType * type)
{
	ILNode_CTypeExpression *node__ = (ILNode_CTypeExpression *)yynodealloc(sizeof(struct ILNode_CTypeExpression__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CTypeExpression_vt__;
	node__->kind__ = ILNode_CTypeExpression_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_CNewObject_create(ILGCSpecifier specifier, ILType * type, ILNode * args, int useGlobalNew)
{
	ILNode_CNewObject *node__ = (ILNode_CNewObject *)yynodealloc(sizeof(struct ILNode_CNewObject__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CNewObject_vt__;
	node__->kind__ = ILNode_CNewObject_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->specifier = specifier;
	node__->type = type;
	node__->args = args;
	node__->useGlobalNew = useGlobalNew;
	return (ILNode *)node__;
}

ILNode *ILNode_CNewArray_create(ILGCSpecifier specifier, ILType * type, ILNode * expr, int useGlobalNew)
{
	ILNode_CNewArray *node__ = (ILNode_CNewArray *)yynodealloc(sizeof(struct ILNode_CNewArray__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CNewArray_vt__;
	node__->kind__ = ILNode_CNewArray_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->specifier = specifier;
	node__->type = type;
	node__->expr = expr;
	node__->useGlobalNew = useGlobalNew;
	node__->resultType = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CSizeOfRaw_create(ILType * type)
{
	ILNode_CSizeOfRaw *node__ = (ILNode_CSizeOfRaw *)yynodealloc(sizeof(struct ILNode_CSizeOfRaw__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CSizeOfRaw_vt__;
	node__->kind__ = ILNode_CSizeOfRaw_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_CSizeTempVar_create(void)
{
	ILNode_CSizeTempVar *node__ = (ILNode_CSizeTempVar *)yynodealloc(sizeof(struct ILNode_CSizeTempVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CSizeTempVar_vt__;
	node__->kind__ = ILNode_CSizeTempVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->tempVar = ~((unsigned)0);
	return (ILNode *)node__;
}

ILNode *ILNode_CSizeAlign_create(ILNode * size, ILUInt32 alignFlags, ILType * measureType, ILNode * alignVar)
{
	ILNode_CSizeAlign *node__ = (ILNode_CSizeAlign *)yynodealloc(sizeof(struct ILNode_CSizeAlign__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CSizeAlign_vt__;
	node__->kind__ = ILNode_CSizeAlign_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->size = size;
	node__->alignFlags = alignFlags;
	node__->measureType = measureType;
	node__->alignVar = alignVar;
	return (ILNode *)node__;
}

ILNode *ILNode_CString_create(char * str, int len)
{
	ILNode_CString *node__ = (ILNode_CString *)yynodealloc(sizeof(struct ILNode_CString__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CString_vt__;
	node__->kind__ = ILNode_CString_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->str = str;
	node__->len = len;
	return (ILNode *)node__;
}

ILNode *ILNode_CWString_create(char * str, int len)
{
	ILNode_CWString *node__ = (ILNode_CWString *)yynodealloc(sizeof(struct ILNode_CWString__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CWString_vt__;
	node__->kind__ = ILNode_CWString_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->str = str;
	node__->len = len;
	return (ILNode *)node__;
}

ILNode *ILNode_CLocalVar_create(unsigned long index, ILMachineType machineType, ILType * type, ILType * decayedType)
{
	ILNode_CLocalVar *node__ = (ILNode_CLocalVar *)yynodealloc(sizeof(struct ILNode_CLocalVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CLocalVar_vt__;
	node__->kind__ = ILNode_CLocalVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->index = index;
	node__->machineType = machineType;
	node__->type = type;
	node__->decayedType = decayedType;
	return (ILNode *)node__;
}

ILNode *ILNode_CArgumentVar_create(unsigned long index, ILMachineType machineType, ILType * type)
{
	ILNode_CArgumentVar *node__ = (ILNode_CArgumentVar *)yynodealloc(sizeof(struct ILNode_CArgumentVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CArgumentVar_vt__;
	node__->kind__ = ILNode_CArgumentVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->index = index;
	node__->machineType = machineType;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_CGlobalVar_create(char * name, ILType * type, ILType * decayedType)
{
	ILNode_CGlobalVar *node__ = (ILNode_CGlobalVar *)yynodealloc(sizeof(struct ILNode_CGlobalVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CGlobalVar_vt__;
	node__->kind__ = ILNode_CGlobalVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->type = type;
	node__->decayedType = decayedType;
	return (ILNode *)node__;
}

ILNode *ILNode_CDeref_create(ILNode * expr)
{
	ILNode_CDeref *node__ = (ILNode_CDeref *)yynodealloc(sizeof(struct ILNode_CDeref__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CDeref_vt__;
	node__->kind__ = ILNode_CDeref_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = 0;
	node__->machineType = ILMachineType_Void;
	return (ILNode *)node__;
}

ILNode *ILNode_CBitField_create(ILNode * expr, ILField * field, ILMachineType machineType, ILUInt32 bitFieldStart, ILUInt32 bitFieldSize, int genExprAsAddr)
{
	ILNode_CBitField *node__ = (ILNode_CBitField *)yynodealloc(sizeof(struct ILNode_CBitField__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CBitField_vt__;
	node__->kind__ = ILNode_CBitField_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->field = field;
	node__->machineType = machineType;
	node__->bitFieldStart = bitFieldStart;
	node__->bitFieldSize = bitFieldSize;
	node__->genExprAsAddr = genExprAsAddr;
	node__->tempVar = ~((unsigned)0);
	node__->tempPtrVar = ~((unsigned)0);
	return (ILNode *)node__;
}

ILNode *ILNode_CArrayAccess_create(ILNode * array, ILNode * indices)
{
	ILNode_CArrayAccess *node__ = (ILNode_CArrayAccess *)yynodealloc(sizeof(struct ILNode_CArrayAccess__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CArrayAccess_vt__;
	node__->kind__ = ILNode_CArrayAccess_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->array = array;
	node__->indices = indices;
	node__->arrayType = 0;
	node__->elemType = 0;
	node__->saveStack = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CDerefField_create(ILNode * expr, char * name)
{
	ILNode_CDerefField *node__ = (ILNode_CDerefField *)yynodealloc(sizeof(struct ILNode_CDerefField__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CDerefField_vt__;
	node__->kind__ = ILNode_CDerefField_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->name = name;
	node__->field = 0;
	node__->ownerType = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CMemberField_create(ILNode * expr, char * name)
{
	ILNode_CMemberField *node__ = (ILNode_CMemberField *)yynodealloc(sizeof(struct ILNode_CMemberField__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CMemberField_vt__;
	node__->kind__ = ILNode_CMemberField_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->name = name;
	node__->field = 0;
	node__->ownerType = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CStaticField_create(ILNode * expr, char * name)
{
	ILNode_CStaticField *node__ = (ILNode_CStaticField *)yynodealloc(sizeof(struct ILNode_CStaticField__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CStaticField_vt__;
	node__->kind__ = ILNode_CStaticField_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->name = name;
	node__->field = 0;
	node__->ownerType = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_SizeOfExpr_create(ILNode * expr)
{
	ILNode_SizeOfExpr *node__ = (ILNode_SizeOfExpr *)yynodealloc(sizeof(struct ILNode_SizeOfExpr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SizeOfExpr_vt__;
	node__->kind__ = ILNode_SizeOfExpr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_SetJmp_create(ILNode * expr)
{
	ILNode_SetJmp *node__ = (ILNode_SetJmp *)yynodealloc(sizeof(struct ILNode_SetJmp__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SetJmp_vt__;
	node__->kind__ = ILNode_SetJmp_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_AllocA_create(ILNode * expr)
{
	ILNode_AllocA *node__ = (ILNode_AllocA *)yynodealloc(sizeof(struct ILNode_AllocA__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AllocA_vt__;
	node__->kind__ = ILNode_AllocA_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_CToCSharpString_create(ILNode * expr)
{
	ILNode_CToCSharpString *node__ = (ILNode_CToCSharpString *)yynodealloc(sizeof(struct ILNode_CToCSharpString__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CToCSharpString_vt__;
	node__->kind__ = ILNode_CToCSharpString_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_CArrayInit_create(ILNode * expr)
{
	ILNode_CArrayInit *node__ = (ILNode_CArrayInit *)yynodealloc(sizeof(struct ILNode_CArrayInit__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CArrayInit_vt__;
	node__->kind__ = ILNode_CArrayInit_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_CBox_create(ILNode * expr)
{
	ILNode_CBox *node__ = (ILNode_CBox *)yynodealloc(sizeof(struct ILNode_CBox__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CBox_vt__;
	node__->kind__ = ILNode_CBox_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_CopyComplex_create(ILNode * expr, ILType * type)
{
	ILNode_CopyComplex *node__ = (ILNode_CopyComplex *)yynodealloc(sizeof(struct ILNode_CopyComplex__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CopyComplex_vt__;
	node__->kind__ = ILNode_CopyComplex_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_CDelete_create(ILNode * expr1, ILNode * expr2, int arrayDelete, int useGlobalDelete)
{
	ILNode_CDelete *node__ = (ILNode_CDelete *)yynodealloc(sizeof(struct ILNode_CDelete__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CDelete_vt__;
	node__->kind__ = ILNode_CDelete_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->arrayDelete = arrayDelete;
	node__->useGlobalDelete = useGlobalDelete;
	node__->dtor = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CSizeReleaseTempVar_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_CSizeReleaseTempVar *node__ = (ILNode_CSizeReleaseTempVar *)yynodealloc(sizeof(struct ILNode_CSizeReleaseTempVar__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CSizeReleaseTempVar_vt__;
	node__->kind__ = ILNode_CSizeReleaseTempVar_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_CSizeMax_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_CSizeMax *node__ = (ILNode_CSizeMax *)yynodealloc(sizeof(struct ILNode_CSizeMax__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CSizeMax_vt__;
	node__->kind__ = ILNode_CSizeMax_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_CInvocationExpression_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_CInvocationExpression *node__ = (ILNode_CInvocationExpression *)yynodealloc(sizeof(struct ILNode_CInvocationExpression__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CInvocationExpression_vt__;
	node__->kind__ = ILNode_CInvocationExpression_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->thisExpr = 0;
	node__->methodInfo = 0;
	node__->callSiteSig = 0;
	node__->baseCall = 0;
	node__->name = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_AsmStmt_create(char * code)
{
	ILNode_AsmStmt *node__ = (ILNode_AsmStmt *)yynodealloc(sizeof(struct ILNode_AsmStmt__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AsmStmt_vt__;
	node__->kind__ = ILNode_AsmStmt_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->code = code;
	return (ILNode *)node__;
}

ILNode *ILNode_CAssignArray_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_CAssignArray *node__ = (ILNode_CAssignArray *)yynodealloc(sizeof(struct ILNode_CAssignArray__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CAssignArray_vt__;
	node__->kind__ = ILNode_CAssignArray_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->type = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CAssignStruct_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_CAssignStruct *node__ = (ILNode_CAssignStruct *)yynodealloc(sizeof(struct ILNode_CAssignStruct__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CAssignStruct_vt__;
	node__->kind__ = ILNode_CAssignStruct_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	node__->type = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CGotoPtr_create(ILNode * expr)
{
	ILNode_CGotoPtr *node__ = (ILNode_CGotoPtr *)yynodealloc(sizeof(struct ILNode_CGotoPtr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CGotoPtr_vt__;
	node__->kind__ = ILNode_CGotoPtr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr = expr;
	return (ILNode *)node__;
}

