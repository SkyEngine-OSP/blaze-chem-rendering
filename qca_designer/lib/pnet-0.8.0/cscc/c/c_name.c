/* c_name.c.  Generated automatically by treecc */
#line 83 "c_name.tc"


#include <cscc/c/c_internal.h>

CName CNameDefault = {0, 0};

CName CNameCreate(const char *name, int prec)
{
	CName result;
	result.name = ILDupString(name);
	if(!(result.name))
	{
		CCOutOfMemory();
	}
	result.prec = prec;
	return result;
}

CName CNameCreateUnary(const char *oper, CName arg, int prec)
{
	CName result;
	result.name = (char *)ILMalloc(strlen(oper) + strlen(arg.name) + 4);
	if(!(result.name))
	{
		CCOutOfMemory();
	}
	if(prec > arg.prec)
	{
		strcpy(result.name, oper);
		strcat(result.name, " (");
		strcat(result.name, arg.name);
		strcat(result.name, ")");
	}
	else
	{
		strcpy(result.name, oper);
		strcat(result.name, " ");
		strcat(result.name, arg.name);
	}
	ILFree(arg.name);
	result.prec = prec;
	return result;
}

CName CNameCreateUnaryBracketed(const char *oper, CName arg, int prec)
{
	CName result;
	result.name = (char *)ILMalloc(strlen(oper) + strlen(arg.name) + 3);
	if(!(result.name))
	{
		CCOutOfMemory();
	}
	strcpy(result.name, oper);
	strcat(result.name, "(");
	strcat(result.name, arg.name);
	strcat(result.name, ")");
	ILFree(arg.name);
	result.prec = prec;
	return result;
}

CName CNameCreateBinary(CName left, const char *oper, CName right, int prec)
{
	CName result;
	result.name = (char *)ILMalloc(strlen(left.name) + strlen(oper) +
								   strlen(right.name) + 7);
	if(!(result.name))
	{
		CCOutOfMemory();
	}
	if(prec >= left.prec)
	{
		strcpy(result.name, "(");
		strcat(result.name, left.name);
		strcat(result.name, ")");
	}
	else
	{
		strcpy(result.name, left.name);
	}
	strcat(result.name, " ");
	strcat(result.name, oper);
	strcat(result.name, " ");
	if(prec > right.prec)
	{
		strcpy(result.name, "(");
		strcat(result.name, right.name);
		strcat(result.name, ")");
	}
	else
	{
		strcpy(result.name, right.name);
	}
	ILFree(left.name);
	ILFree(right.name);
	result.prec = prec;
	return result;
}

#line 103 "c_name.c"

static CName ILNode_CName_1__(ILNode_CDeclarator *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 110 "c_name.c"

static CName ILNode_CName_2__(ILNode_CSharpInvocation *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 117 "c_name.c"

static CName ILNode_CName_3__(ILNode_Dummy *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 124 "c_name.c"

static CName ILNode_CName_4__(ILNode_Null *node)
#line 264 "c_name.tc"
{
	return CNameCreate("__null__", C_PREC_PRIMARY);
}
#line 131 "c_name.c"

static CName ILNode_CName_5__(ILNode_NullPtr *node)
#line 268 "c_name.tc"
{
	return CNameCreate("((void *)0)", C_PREC_PRIMARY);
}
#line 138 "c_name.c"

static CName ILNode_CName_6__(ILNode_True *node)
#line 272 "c_name.tc"
{
	return CNameCreate("__true__", C_PREC_PRIMARY);
}
#line 145 "c_name.c"

static CName ILNode_CName_7__(ILNode_False *node)
#line 276 "c_name.tc"
{
	return CNameCreate("__false__", C_PREC_PRIMARY);
}
#line 152 "c_name.c"

static CName ILNode_CName_8__(ILNode_Integer *node)
#line 280 "c_name.tc"
{
	char numbuf[64];
	if(node->value <= (ILUInt64)IL_MAX_UINT32)
	{
		sprintf(numbuf, "%s%lu",
				(node->isneg ? "-" : ""),
				(unsigned long)(node->value));
	}
	else
	{
		sprintf(numbuf, "%s0x%lX%08lX",
				(node->isneg ? "-" : ""),
				(unsigned long)(node->value >> 32),
				(unsigned long)(node->value & IL_MAX_UINT32));
	}
	return CNameCreate(numbuf, (node->isneg ? C_PREC_UNARY : C_PREC_PRIMARY));
}
#line 173 "c_name.c"

static CName ILNode_CName_9__(ILNode_Real *node)
#line 298 "c_name.tc"
{
	char numbuf[64];
	sprintf(numbuf, "%f", (double)(node->value));
	return CNameCreate
		(numbuf, (numbuf[0] == '-' ? C_PREC_UNARY : C_PREC_PRIMARY));
}
#line 183 "c_name.c"

static CName ILNode_CName_10__(ILNode_Decimal *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 190 "c_name.c"

static CName ILNode_CName_11__(ILNode_String *node)
#line 305 "c_name.tc"
{
	CName result;
	char *str = (char *)ILMalloc(node->len + 3);
	str[0] = '"';
	ILMemCpy(str + 1, node->str, node->len);
	str[node->len + 1] = '"';
	str[node->len + 2] = '\0';
	result.name = str;
	result.prec = C_PREC_PRIMARY;
	return result;
}
#line 205 "c_name.c"

static CName ILNode_CName_12__(ILNode_Deref *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 212 "c_name.c"

static CName ILNode_CName_13__(ILNode_AsIs *node)
#line 453 "c_name.tc"
{
	return ILNode_CName(node->expr);
}
#line 219 "c_name.c"

static CName ILNode_CName_14__(ILNode_Overflow *node)
#line 457 "c_name.tc"
{
	return CNameCreateUnaryBracketed
		("__checked__", ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 227 "c_name.c"

static CName ILNode_CName_15__(ILNode_NoOverflow *node)
#line 462 "c_name.tc"
{
	return CNameCreateUnaryBracketed
		("__unchecked__", ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 235 "c_name.c"

static CName ILNode_CName_16__(ILNode_Pedantic *node)
#line 453 "c_name.tc"
{
	return ILNode_CName(node->expr);
}
#line 242 "c_name.c"

static CName ILNode_CName_17__(ILNode_NoPedantic *node)
#line 453 "c_name.tc"
{
	return ILNode_CName(node->expr);
}
#line 249 "c_name.c"

static CName ILNode_CName_18__(ILNode_This *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 256 "c_name.c"

static CName ILNode_CName_19__(ILNode_LValue *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 263 "c_name.c"

static CName ILNode_CName_20__(ILNode_LogicalNot *node)
#line 321 "c_name.tc"
{
	return CNameCreateUnary("!", ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 270 "c_name.c"

static CName ILNode_CName_21__(ILNode_Neg *node)
#line 364 "c_name.tc"
{
	return CNameCreateUnary("-", ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 277 "c_name.c"

static CName ILNode_CName_22__(ILNode_UnaryPlus *node)
#line 368 "c_name.tc"
{
	return CNameCreateUnary("+", ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 284 "c_name.c"

static CName ILNode_CName_23__(ILNode_Not *node)
#line 387 "c_name.tc"
{
	return CNameCreateUnary("~", ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 291 "c_name.c"

static CName ILNode_CName_24__(ILNode_UserUnaryOp *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 298 "c_name.c"

static CName ILNode_CName_25__(ILNode_PreInc *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 305 "c_name.c"

static CName ILNode_CName_26__(ILNode_PreDec *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 312 "c_name.c"

static CName ILNode_CName_27__(ILNode_PostInc *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 319 "c_name.c"

static CName ILNode_CName_28__(ILNode_PostDec *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 326 "c_name.c"

static CName ILNode_CName_29__(ILNode_UserIncOrDec *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 333 "c_name.c"

static CName ILNode_CName_30__(ILNode_IncOrDecPtr *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 340 "c_name.c"

static CName ILNode_CName_31__(ILNode_CastSimple *node)
#line 467 "c_name.tc"
{
	const char *type;
	switch(node->machineType)
	{
		case ILMachineType_Void:		type = "(void)"; break;
		case ILMachineType_Boolean:		type = "(_Bool)"; break;
		case ILMachineType_Int8:		type = "(char)"; break;
		case ILMachineType_UInt8:		type = "(unsigned char)"; break;
		case ILMachineType_Int16:		type = "(short)"; break;
		case ILMachineType_UInt16:		type = "(unsigned short)"; break;
		case ILMachineType_Char:		type = "(__wchar__)"; break;
		case ILMachineType_Int32:		type = "(int)"; break;
		case ILMachineType_UInt32:		type = "(unsigned int)"; break;
		case ILMachineType_Int64:		type = "(long long)"; break;
		case ILMachineType_UInt64:		type = "(unsigned long long)"; break;
		case ILMachineType_NativeInt:	type = "(long)"; break;
		case ILMachineType_NativeUInt:	type = "(unsigned long)"; break;
		case ILMachineType_Float32:		type = "(float)"; break;
		case ILMachineType_Float64:		type = "(double)"; break;
		case ILMachineType_NativeFloat:	type = "(native float)"; break;
		case ILMachineType_Decimal:		type = "(System.Decimal)"; break;
		case ILMachineType_String:		type = "(System.String)"; break;
		case ILMachineType_ObjectRef:	type = "(System.Object)"; break;
		case ILMachineType_UnmanagedPtr:
		case ILMachineType_ManagedPtr:
		case ILMachineType_TransientPtr: type = "(void *)"; break;
		default:						type = "(?)"; break;
	}
	return CNameCreateUnaryBracketed
		(type, ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 375 "c_name.c"

static CName ILNode_CName_32__(ILNode_CastType *node)
#line 499 "c_name.tc"
{
	return CNameCreateUnaryBracketed
		(CTypeToName(&CCCodeGen, node->type),
		 ILNode_CName(node->expr), C_PREC_UNARY);
}
#line 384 "c_name.c"

static CName ILNode_CName_33__(ILNode_UserConversion *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 391 "c_name.c"

static CName ILNode_CName_34__(ILNode_AddressOf *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 398 "c_name.c"

static CName ILNode_CName_35__(ILNode_ToBool *node)
#line 453 "c_name.tc"
{
	return ILNode_CName(node->expr);
}
#line 405 "c_name.c"

static CName ILNode_CName_36__(ILNode_ToConst *node)
#line 453 "c_name.tc"
{
	return ILNode_CName(node->expr);
}
#line 412 "c_name.c"

static CName ILNode_CName_37__(ILNode_VarArgExpand *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 419 "c_name.c"

static CName ILNode_CName_38__(ILNode_IsNull *node)
#line 530 "c_name.tc"
{
	CName name = CNameCreate("0", C_PREC_PRIMARY);
	return CNameCreateBinary(ILNode_CName(node->expr), "==",
							 name, C_PREC_EQUALITY);
}
#line 428 "c_name.c"

static CName ILNode_CName_39__(ILNode_IsNonNull *node)
#line 536 "c_name.tc"
{
	CName name = CNameCreate("0", C_PREC_PRIMARY);
	return CNameCreateBinary(ILNode_CName(node->expr), "!=",
							 name, C_PREC_EQUALITY);
}
#line 437 "c_name.c"

static CName ILNode_CName_40__(ILNode_MakeRefAny *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 444 "c_name.c"

static CName ILNode_CName_41__(ILNode_RefType *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 451 "c_name.c"

static CName ILNode_CName_42__(ILNode_ArrayLength *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 458 "c_name.c"

static CName ILNode_CName_43__(ILNode_ArrayInit *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 465 "c_name.c"

static CName ILNode_CName_44__(ILNode_SizeOfExpr *node)
#line 548 "c_name.tc"
{
	CName name = CNameCreate
		(CTypeToName(&CCCodeGen, node->type), C_PREC_PRIMARY);
	return CNameCreateUnaryBracketed("sizeof", name, C_PREC_UNARY);
}
#line 474 "c_name.c"

static CName ILNode_CName_45__(ILNode_SetJmp *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 481 "c_name.c"

static CName ILNode_CName_46__(ILNode_AllocA *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 488 "c_name.c"

static CName ILNode_CName_47__(ILNode_CToCSharpString *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 495 "c_name.c"

static CName ILNode_CName_48__(ILNode_CArrayInit *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 502 "c_name.c"

static CName ILNode_CName_49__(ILNode_CBox *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 509 "c_name.c"

static CName ILNode_CName_50__(ILNode_CopyComplex *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 516 "c_name.c"

static CName ILNode_CName_51__(ILNode_LogicalAnd *node)
#line 325 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "&&",
							 ILNode_CName(node->expr2), C_PREC_LOGAND);
}
#line 524 "c_name.c"

static CName ILNode_CName_52__(ILNode_LogicalOr *node)
#line 330 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "||",
							 ILNode_CName(node->expr2), C_PREC_LOGOR);
}
#line 532 "c_name.c"

static CName ILNode_CName_53__(ILNode_UserLogical *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 539 "c_name.c"

static CName ILNode_CName_54__(ILNode_Add *node)
#line 339 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "+",
							 ILNode_CName(node->expr2), C_PREC_ADD);
}
#line 547 "c_name.c"

static CName ILNode_CName_55__(ILNode_Sub *node)
#line 344 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "-",
							 ILNode_CName(node->expr2), C_PREC_ADD);
}
#line 555 "c_name.c"

static CName ILNode_CName_56__(ILNode_Mul *node)
#line 349 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "*",
							 ILNode_CName(node->expr2), C_PREC_MULT);
}
#line 563 "c_name.c"

static CName ILNode_CName_57__(ILNode_Div *node)
#line 354 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "/",
							 ILNode_CName(node->expr2), C_PREC_MULT);
}
#line 571 "c_name.c"

static CName ILNode_CName_58__(ILNode_Rem *node)
#line 359 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "%",
							 ILNode_CName(node->expr2), C_PREC_MULT);
}
#line 579 "c_name.c"

static CName ILNode_CName_59__(ILNode_And *node)
#line 372 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "&",
							 ILNode_CName(node->expr2), C_PREC_AND);
}
#line 587 "c_name.c"

static CName ILNode_CName_60__(ILNode_Or *node)
#line 377 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "|",
							 ILNode_CName(node->expr2), C_PREC_OR);
}
#line 595 "c_name.c"

static CName ILNode_CName_61__(ILNode_Xor *node)
#line 382 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "^",
							 ILNode_CName(node->expr2), C_PREC_XOR);
}
#line 603 "c_name.c"

static CName ILNode_CName_62__(ILNode_Shl *node)
#line 391 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "<<",
							 ILNode_CName(node->expr2), C_PREC_SHIFT);
}
#line 611 "c_name.c"

static CName ILNode_CName_63__(ILNode_Shr *node)
#line 396 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), ">>",
							 ILNode_CName(node->expr2), C_PREC_SHIFT);
}
#line 619 "c_name.c"

static CName ILNode_CName_64__(ILNode_UShr *node)
#line 401 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), ">>",
							 ILNode_CName(node->expr2), C_PREC_SHIFT);
}
#line 627 "c_name.c"

static CName ILNode_CName_65__(ILNode_UserBinaryOp *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 634 "c_name.c"

static CName ILNode_CName_66__(ILNode_Concat *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 641 "c_name.c"

static CName ILNode_CName_67__(ILNode_DelegateAdd *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 648 "c_name.c"

static CName ILNode_CName_68__(ILNode_DelegateSub *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 655 "c_name.c"

static CName ILNode_CName_69__(ILNode_Assign *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 662 "c_name.c"

static CName ILNode_CName_70__(ILNode_Eq *node)
#line 410 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "==",
							 ILNode_CName(node->expr2), C_PREC_EQUALITY);
}
#line 670 "c_name.c"

static CName ILNode_CName_71__(ILNode_Ne *node)
#line 415 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "!=",
							 ILNode_CName(node->expr2), C_PREC_EQUALITY);
}
#line 678 "c_name.c"

static CName ILNode_CName_72__(ILNode_Lt *node)
#line 420 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "<",
							 ILNode_CName(node->expr2), C_PREC_RELATIONAL);
}
#line 686 "c_name.c"

static CName ILNode_CName_73__(ILNode_Le *node)
#line 425 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), "<=",
							 ILNode_CName(node->expr2), C_PREC_RELATIONAL);
}
#line 694 "c_name.c"

static CName ILNode_CName_74__(ILNode_Gt *node)
#line 430 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), ">",
							 ILNode_CName(node->expr2), C_PREC_RELATIONAL);
}
#line 702 "c_name.c"

static CName ILNode_CName_75__(ILNode_Ge *node)
#line 435 "c_name.tc"
{
	return CNameCreateBinary(ILNode_CName(node->expr1), ">=",
							 ILNode_CName(node->expr2), C_PREC_RELATIONAL);
}
#line 710 "c_name.c"

static CName ILNode_CName_76__(ILNode_Comma *node)
#line 444 "c_name.tc"
{
	/* In a constant expression, the first argument will be discarded */
	return ILNode_CName(node->expr2);
}
#line 718 "c_name.c"

static CName ILNode_CName_77__(ILNode_ArgList *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 725 "c_name.c"

static CName ILNode_CName_78__(ILNode_RefValue *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 732 "c_name.c"

static CName ILNode_CName_79__(ILNode_InvocationExpression *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 739 "c_name.c"

static CName ILNode_CName_80__(ILNode_CDelete *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 746 "c_name.c"

static CName ILNode_CName_81__(ILNode_CSizeReleaseTempVar *node)
#line 554 "c_name.tc"
{
	return ILNode_CName(node->expr1);
}
#line 753 "c_name.c"

static CName ILNode_CName_82__(ILNode_CSizeMax *node)
#line 558 "c_name.tc"
{
	CName name1 = ILNode_CName(node->expr1);
	CName name2 = ILNode_CName(node->expr2);
	CName result;
	result.name = (char *)ILMalloc(strlen(name1.name) + strlen(name2.name) + 8);
	if(!(result.name))
	{
		CCOutOfMemory();
	}
	strcpy(result.name, "max(");
	strcat(result.name, name1.name);
	strcat(result.name, ", ");
	strcat(result.name, name2.name);
	strcat(result.name, ")");
	ILFree(name1.name);
	ILFree(name2.name);
	result.prec = C_PREC_POSTFIX;
	return result;
}
#line 776 "c_name.c"

static CName ILNode_CName_83__(ILNode_Conditional *node)
#line 505 "c_name.tc"
{
	CName name1 = ILNode_CName(node->expr1);
	CName name2 = ILNode_CName(node->expr2);
	CName name3 = ILNode_CName(node->expr3);
	CName result;
	result.name = (char *)ILMalloc(strlen(name1.name) + strlen(name2.name) +
								   strlen(name3.name) + 15);
	if(!(result.name))
	{
		CCOutOfMemory();
	}
	strcpy(result.name, "((");
	strcat(result.name, name1.name);
	strcat(result.name, ") ? (");
	strcat(result.name, name2.name);
	strcat(result.name, ") : (");
	strcat(result.name, name3.name);
	strcat(result.name, "))");
	ILFree(name1.name);
	ILFree(name2.name);
	ILFree(name3.name);
	result.prec = C_PREC_PRIMARY;
	return result;
}
#line 804 "c_name.c"

static CName ILNode_CName_84__(ILNode_AssignExpression *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 811 "c_name.c"

static CName ILNode_CName_85__(ILNode_VarArgList *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 818 "c_name.c"

static CName ILNode_CName_86__(ILNode_Argument *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 825 "c_name.c"

static CName ILNode_CName_87__(ILNode_ArgArray *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 832 "c_name.c"

static CName ILNode_CName_88__(ILNode_BoxingExpression *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 839 "c_name.c"

static CName ILNode_CName_89__(ILNode_Error *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 846 "c_name.c"

static CName ILNode_CName_90__(ILNode_NewExpression *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 853 "c_name.c"

static CName ILNode_CName_91__(ILNode_ObjectCreationExpression *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 860 "c_name.c"

static CName ILNode_CName_92__(ILNode_DelegateCreationExpression *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 867 "c_name.c"

static CName ILNode_CName_93__(ILNode_DefaultConstructor *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 874 "c_name.c"

static CName ILNode_CName_94__(ILNode_BaseInit *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 881 "c_name.c"

static CName ILNode_CName_95__(ILNode_ThisInit *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 888 "c_name.c"

static CName ILNode_CName_96__(ILNode_NonStaticInit *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 895 "c_name.c"

static CName ILNode_CName_97__(ILNode_EmptyExpr *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 902 "c_name.c"

static CName ILNode_CName_98__(ILNode_SizeOfType *node)
#line 548 "c_name.tc"
{
	CName name = CNameCreate
		(CTypeToName(&CCCodeGen, node->type), C_PREC_PRIMARY);
	return CNameCreateUnaryBracketed("sizeof", name, C_PREC_UNARY);
}
#line 911 "c_name.c"

static CName ILNode_CName_99__(ILNode_VaStart *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 918 "c_name.c"

static CName ILNode_CName_100__(ILNode_VaEnd *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 925 "c_name.c"

static CName ILNode_CName_101__(ILNode_VaArg *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 932 "c_name.c"

static CName ILNode_CName_102__(ILNode_FunctionRef *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 939 "c_name.c"

static CName ILNode_CName_103__(ILNode_CLabelRef *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 946 "c_name.c"

static CName ILNode_CName_104__(ILNode_CSharpTypeOf *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 953 "c_name.c"

static CName ILNode_CName_105__(ILNode_CTypeExpression *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 960 "c_name.c"

static CName ILNode_CName_106__(ILNode_CNewObject *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 967 "c_name.c"

static CName ILNode_CName_107__(ILNode_CNewArray *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 974 "c_name.c"

static CName ILNode_CName_108__(ILNode_CSizeOfRaw *node)
#line 548 "c_name.tc"
{
	CName name = CNameCreate
		(CTypeToName(&CCCodeGen, node->type), C_PREC_PRIMARY);
	return CNameCreateUnaryBracketed("sizeof", name, C_PREC_UNARY);
}
#line 983 "c_name.c"

static CName ILNode_CName_109__(ILNode_CSizeTempVar *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 990 "c_name.c"

static CName ILNode_CName_110__(ILNode_CSizeAlign *node)
#line 578 "c_name.tc"
{
	CName name1 = ILNode_CName(node->size);
	CName name2;
	char numbuf[32];
	CName result;
	sprintf(numbuf, "0x%04lX", (unsigned long)(node->alignFlags));
	if(node->measureType)
	{
		name2 = CNameCreate
			(CTypeToName(&CCCodeGen, node->measureType), C_PREC_PRIMARY);
	}
	else
	{
		name2 = CNameCreate("", C_PREC_PRIMARY);
	}
	result.name = (char *)ILMalloc(strlen(name1.name) + strlen(numbuf) +
								   strlen(name2.name) + 12);
	if(!(result.name))
	{
		CCOutOfMemory();
	}
	strcpy(result.name, "align(");
	strcat(result.name, name1.name);
	strcat(result.name, ", ");
	strcat(result.name, numbuf);
	if(node->measureType)
	{
		strcat(result.name, ", ");
		strcat(result.name, name2.name);
	}
	strcat(result.name, ")");
	ILFree(name1.name);
	ILFree(name2.name);
	result.prec = C_PREC_POSTFIX;
	return result;
}
#line 1030 "c_name.c"

static CName ILNode_CName_111__(ILNode_Statement *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 1037 "c_name.c"

static CName ILNode_CName_112__(ILNode_Identifier *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 1044 "c_name.c"

static CName ILNode_CName_113__(ILNode_QualIdent *node)
#line 256 "c_name.tc"
{
	return CNameCreate("???", C_PREC_PRIMARY);
}
#line 1051 "c_name.c"

CName ILNode_CName(ILNode * node__)
{
	switch(node__->kind__)
	{
		case ILNode_CDeclarator_kind:
		case ILNode_CBitFieldDeclarator_kind:
		case ILNode_CInitDeclarator_kind:
		{
			return ILNode_CName_1__((ILNode_CDeclarator *)node__);
		}
		break;

		case ILNode_CSharpInvocation_kind:
		{
			return ILNode_CName_2__((ILNode_CSharpInvocation *)node__);
		}
		break;

		case ILNode_Dummy_kind:
		case ILNode_CAttribute_kind:
		case ILNode_CAttributeValue_kind:
		{
			return ILNode_CName_3__((ILNode_Dummy *)node__);
		}
		break;

		case ILNode_Null_kind:
		{
			return ILNode_CName_4__((ILNode_Null *)node__);
		}
		break;

		case ILNode_NullPtr_kind:
		{
			return ILNode_CName_5__((ILNode_NullPtr *)node__);
		}
		break;

		case ILNode_True_kind:
		{
			return ILNode_CName_6__((ILNode_True *)node__);
		}
		break;

		case ILNode_False_kind:
		{
			return ILNode_CName_7__((ILNode_False *)node__);
		}
		break;

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
		{
			return ILNode_CName_8__((ILNode_Integer *)node__);
		}
		break;

		case ILNode_Real_kind:
		case ILNode_Float32_kind:
		case ILNode_Float64_kind:
		case ILNode_Float_kind:
		{
			return ILNode_CName_9__((ILNode_Real *)node__);
		}
		break;

		case ILNode_Decimal_kind:
		{
			return ILNode_CName_10__((ILNode_Decimal *)node__);
		}
		break;

		case ILNode_String_kind:
		case ILNode_CString_kind:
		case ILNode_CWString_kind:
		{
			return ILNode_CName_11__((ILNode_String *)node__);
		}
		break;

		case ILNode_Deref_kind:
		{
			return ILNode_CName_12__((ILNode_Deref *)node__);
		}
		break;

		case ILNode_AsIs_kind:
		case ILNode_MarkType_kind:
		{
			return ILNode_CName_13__((ILNode_AsIs *)node__);
		}
		break;

		case ILNode_Overflow_kind:
		{
			return ILNode_CName_14__((ILNode_Overflow *)node__);
		}
		break;

		case ILNode_NoOverflow_kind:
		{
			return ILNode_CName_15__((ILNode_NoOverflow *)node__);
		}
		break;

		case ILNode_Pedantic_kind:
		{
			return ILNode_CName_16__((ILNode_Pedantic *)node__);
		}
		break;

		case ILNode_NoPedantic_kind:
		{
			return ILNode_CName_17__((ILNode_NoPedantic *)node__);
		}
		break;

		case ILNode_This_kind:
		{
			return ILNode_CName_18__((ILNode_This *)node__);
		}
		break;

		case ILNode_LValue_kind:
		case ILNode_LValueNoRef_kind:
		case ILNode_StaticProperty_kind:
		case ILNode_MemberProperty_kind:
		case ILNode_IndexerAccess_kind:
		case ILNode_CBitField_kind:
		case ILNode_LValueUnaryExpr_kind:
		case ILNode_LValueNoRefUnaryExpr_kind:
		case ILNode_BaseAccess_kind:
		case ILNode_BaseElement_kind:
		case ILNode_LValueBinaryExpr_kind:
		case ILNode_MemberAccess_kind:
		case ILNode_DerefField_kind:
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
		{
			return ILNode_CName_19__((ILNode_LValue *)node__);
		}
		break;

		case ILNode_LogicalNot_kind:
		{
			return ILNode_CName_20__((ILNode_LogicalNot *)node__);
		}
		break;

		case ILNode_Neg_kind:
		{
			return ILNode_CName_21__((ILNode_Neg *)node__);
		}
		break;

		case ILNode_UnaryPlus_kind:
		{
			return ILNode_CName_22__((ILNode_UnaryPlus *)node__);
		}
		break;

		case ILNode_Not_kind:
		{
			return ILNode_CName_23__((ILNode_Not *)node__);
		}
		break;

		case ILNode_UserUnaryOp_kind:
		{
			return ILNode_CName_24__((ILNode_UserUnaryOp *)node__);
		}
		break;

		case ILNode_PreInc_kind:
		{
			return ILNode_CName_25__((ILNode_PreInc *)node__);
		}
		break;

		case ILNode_PreDec_kind:
		{
			return ILNode_CName_26__((ILNode_PreDec *)node__);
		}
		break;

		case ILNode_PostInc_kind:
		{
			return ILNode_CName_27__((ILNode_PostInc *)node__);
		}
		break;

		case ILNode_PostDec_kind:
		{
			return ILNode_CName_28__((ILNode_PostDec *)node__);
		}
		break;

		case ILNode_UserIncOrDec_kind:
		case ILNode_UserPreInc_kind:
		case ILNode_UserPreDec_kind:
		case ILNode_UserPostInc_kind:
		case ILNode_UserPostDec_kind:
		{
			return ILNode_CName_29__((ILNode_UserIncOrDec *)node__);
		}
		break;

		case ILNode_IncOrDecPtr_kind:
		case ILNode_PreIncPtr_kind:
		case ILNode_PreDecPtr_kind:
		case ILNode_PostIncPtr_kind:
		case ILNode_PostDecPtr_kind:
		{
			return ILNode_CName_30__((ILNode_IncOrDecPtr *)node__);
		}
		break;

		case ILNode_CastSimple_kind:
		{
			return ILNode_CName_31__((ILNode_CastSimple *)node__);
		}
		break;

		case ILNode_CastType_kind:
		{
			return ILNode_CName_32__((ILNode_CastType *)node__);
		}
		break;

		case ILNode_UserConversion_kind:
		{
			return ILNode_CName_33__((ILNode_UserConversion *)node__);
		}
		break;

		case ILNode_AddressOf_kind:
		{
			return ILNode_CName_34__((ILNode_AddressOf *)node__);
		}
		break;

		case ILNode_ToBool_kind:
		{
			return ILNode_CName_35__((ILNode_ToBool *)node__);
		}
		break;

		case ILNode_ToConst_kind:
		{
			return ILNode_CName_36__((ILNode_ToConst *)node__);
		}
		break;

		case ILNode_VarArgExpand_kind:
		{
			return ILNode_CName_37__((ILNode_VarArgExpand *)node__);
		}
		break;

		case ILNode_IsNull_kind:
		{
			return ILNode_CName_38__((ILNode_IsNull *)node__);
		}
		break;

		case ILNode_IsNonNull_kind:
		{
			return ILNode_CName_39__((ILNode_IsNonNull *)node__);
		}
		break;

		case ILNode_MakeRefAny_kind:
		{
			return ILNode_CName_40__((ILNode_MakeRefAny *)node__);
		}
		break;

		case ILNode_RefType_kind:
		{
			return ILNode_CName_41__((ILNode_RefType *)node__);
		}
		break;

		case ILNode_ArrayLength_kind:
		{
			return ILNode_CName_42__((ILNode_ArrayLength *)node__);
		}
		break;

		case ILNode_ArrayInit_kind:
		{
			return ILNode_CName_43__((ILNode_ArrayInit *)node__);
		}
		break;

		case ILNode_SizeOfExpr_kind:
		{
			return ILNode_CName_44__((ILNode_SizeOfExpr *)node__);
		}
		break;

		case ILNode_SetJmp_kind:
		{
			return ILNode_CName_45__((ILNode_SetJmp *)node__);
		}
		break;

		case ILNode_AllocA_kind:
		{
			return ILNode_CName_46__((ILNode_AllocA *)node__);
		}
		break;

		case ILNode_CToCSharpString_kind:
		{
			return ILNode_CName_47__((ILNode_CToCSharpString *)node__);
		}
		break;

		case ILNode_CArrayInit_kind:
		{
			return ILNode_CName_48__((ILNode_CArrayInit *)node__);
		}
		break;

		case ILNode_CBox_kind:
		{
			return ILNode_CName_49__((ILNode_CBox *)node__);
		}
		break;

		case ILNode_CopyComplex_kind:
		{
			return ILNode_CName_50__((ILNode_CopyComplex *)node__);
		}
		break;

		case ILNode_LogicalAnd_kind:
		{
			return ILNode_CName_51__((ILNode_LogicalAnd *)node__);
		}
		break;

		case ILNode_LogicalOr_kind:
		{
			return ILNode_CName_52__((ILNode_LogicalOr *)node__);
		}
		break;

		case ILNode_UserLogical_kind:
		case ILNode_UserLogicalAnd_kind:
		case ILNode_UserLogicalOr_kind:
		{
			return ILNode_CName_53__((ILNode_UserLogical *)node__);
		}
		break;

		case ILNode_Add_kind:
		{
			return ILNode_CName_54__((ILNode_Add *)node__);
		}
		break;

		case ILNode_Sub_kind:
		{
			return ILNode_CName_55__((ILNode_Sub *)node__);
		}
		break;

		case ILNode_Mul_kind:
		{
			return ILNode_CName_56__((ILNode_Mul *)node__);
		}
		break;

		case ILNode_Div_kind:
		{
			return ILNode_CName_57__((ILNode_Div *)node__);
		}
		break;

		case ILNode_Rem_kind:
		{
			return ILNode_CName_58__((ILNode_Rem *)node__);
		}
		break;

		case ILNode_And_kind:
		{
			return ILNode_CName_59__((ILNode_And *)node__);
		}
		break;

		case ILNode_Or_kind:
		{
			return ILNode_CName_60__((ILNode_Or *)node__);
		}
		break;

		case ILNode_Xor_kind:
		{
			return ILNode_CName_61__((ILNode_Xor *)node__);
		}
		break;

		case ILNode_Shl_kind:
		{
			return ILNode_CName_62__((ILNode_Shl *)node__);
		}
		break;

		case ILNode_Shr_kind:
		{
			return ILNode_CName_63__((ILNode_Shr *)node__);
		}
		break;

		case ILNode_UShr_kind:
		{
			return ILNode_CName_64__((ILNode_UShr *)node__);
		}
		break;

		case ILNode_UserBinaryOp_kind:
		{
			return ILNode_CName_65__((ILNode_UserBinaryOp *)node__);
		}
		break;

		case ILNode_Concat_kind:
		{
			return ILNode_CName_66__((ILNode_Concat *)node__);
		}
		break;

		case ILNode_DelegateAdd_kind:
		{
			return ILNode_CName_67__((ILNode_DelegateAdd *)node__);
		}
		break;

		case ILNode_DelegateSub_kind:
		{
			return ILNode_CName_68__((ILNode_DelegateSub *)node__);
		}
		break;

		case ILNode_Assign_kind:
		{
			return ILNode_CName_69__((ILNode_Assign *)node__);
		}
		break;

		case ILNode_Eq_kind:
		{
			return ILNode_CName_70__((ILNode_Eq *)node__);
		}
		break;

		case ILNode_Ne_kind:
		{
			return ILNode_CName_71__((ILNode_Ne *)node__);
		}
		break;

		case ILNode_Lt_kind:
		{
			return ILNode_CName_72__((ILNode_Lt *)node__);
		}
		break;

		case ILNode_Le_kind:
		{
			return ILNode_CName_73__((ILNode_Le *)node__);
		}
		break;

		case ILNode_Gt_kind:
		{
			return ILNode_CName_74__((ILNode_Gt *)node__);
		}
		break;

		case ILNode_Ge_kind:
		{
			return ILNode_CName_75__((ILNode_Ge *)node__);
		}
		break;

		case ILNode_Comma_kind:
		{
			return ILNode_CName_76__((ILNode_Comma *)node__);
		}
		break;

		case ILNode_ArgList_kind:
		{
			return ILNode_CName_77__((ILNode_ArgList *)node__);
		}
		break;

		case ILNode_RefValue_kind:
		{
			return ILNode_CName_78__((ILNode_RefValue *)node__);
		}
		break;

		case ILNode_InvocationExpression_kind:
		case ILNode_CInvocationExpression_kind:
		{
			return ILNode_CName_79__((ILNode_InvocationExpression *)node__);
		}
		break;

		case ILNode_CDelete_kind:
		{
			return ILNode_CName_80__((ILNode_CDelete *)node__);
		}
		break;

		case ILNode_CSizeReleaseTempVar_kind:
		{
			return ILNode_CName_81__((ILNode_CSizeReleaseTempVar *)node__);
		}
		break;

		case ILNode_CSizeMax_kind:
		{
			return ILNode_CName_82__((ILNode_CSizeMax *)node__);
		}
		break;

		case ILNode_Conditional_kind:
		{
			return ILNode_CName_83__((ILNode_Conditional *)node__);
		}
		break;

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
		{
			return ILNode_CName_84__((ILNode_AssignExpression *)node__);
		}
		break;

		case ILNode_VarArgList_kind:
		{
			return ILNode_CName_85__((ILNode_VarArgList *)node__);
		}
		break;

		case ILNode_Argument_kind:
		{
			return ILNode_CName_86__((ILNode_Argument *)node__);
		}
		break;

		case ILNode_ArgArray_kind:
		{
			return ILNode_CName_87__((ILNode_ArgArray *)node__);
		}
		break;

		case ILNode_BoxingExpression_kind:
		case ILNode_As_kind:
		case ILNode_Is_kind:
		case ILNode_Box_kind:
		case ILNode_Unbox_kind:
		{
			return ILNode_CName_88__((ILNode_BoxingExpression *)node__);
		}
		break;

		case ILNode_Error_kind:
		{
			return ILNode_CName_89__((ILNode_Error *)node__);
		}
		break;

		case ILNode_NewExpression_kind:
		{
			return ILNode_CName_90__((ILNode_NewExpression *)node__);
		}
		break;

		case ILNode_ObjectCreationExpression_kind:
		{
			return ILNode_CName_91__((ILNode_ObjectCreationExpression *)node__);
		}
		break;

		case ILNode_DelegateCreationExpression_kind:
		{
			return ILNode_CName_92__((ILNode_DelegateCreationExpression *)node__);
		}
		break;

		case ILNode_DefaultConstructor_kind:
		{
			return ILNode_CName_93__((ILNode_DefaultConstructor *)node__);
		}
		break;

		case ILNode_BaseInit_kind:
		{
			return ILNode_CName_94__((ILNode_BaseInit *)node__);
		}
		break;

		case ILNode_ThisInit_kind:
		{
			return ILNode_CName_95__((ILNode_ThisInit *)node__);
		}
		break;

		case ILNode_NonStaticInit_kind:
		{
			return ILNode_CName_96__((ILNode_NonStaticInit *)node__);
		}
		break;

		case ILNode_EmptyExpr_kind:
		{
			return ILNode_CName_97__((ILNode_EmptyExpr *)node__);
		}
		break;

		case ILNode_SizeOfType_kind:
		{
			return ILNode_CName_98__((ILNode_SizeOfType *)node__);
		}
		break;

		case ILNode_VaStart_kind:
		{
			return ILNode_CName_99__((ILNode_VaStart *)node__);
		}
		break;

		case ILNode_VaEnd_kind:
		{
			return ILNode_CName_100__((ILNode_VaEnd *)node__);
		}
		break;

		case ILNode_VaArg_kind:
		{
			return ILNode_CName_101__((ILNode_VaArg *)node__);
		}
		break;

		case ILNode_FunctionRef_kind:
		{
			return ILNode_CName_102__((ILNode_FunctionRef *)node__);
		}
		break;

		case ILNode_CLabelRef_kind:
		{
			return ILNode_CName_103__((ILNode_CLabelRef *)node__);
		}
		break;

		case ILNode_CSharpTypeOf_kind:
		{
			return ILNode_CName_104__((ILNode_CSharpTypeOf *)node__);
		}
		break;

		case ILNode_CTypeExpression_kind:
		{
			return ILNode_CName_105__((ILNode_CTypeExpression *)node__);
		}
		break;

		case ILNode_CNewObject_kind:
		{
			return ILNode_CName_106__((ILNode_CNewObject *)node__);
		}
		break;

		case ILNode_CNewArray_kind:
		{
			return ILNode_CName_107__((ILNode_CNewArray *)node__);
		}
		break;

		case ILNode_CSizeOfRaw_kind:
		{
			return ILNode_CName_108__((ILNode_CSizeOfRaw *)node__);
		}
		break;

		case ILNode_CSizeTempVar_kind:
		{
			return ILNode_CName_109__((ILNode_CSizeTempVar *)node__);
		}
		break;

		case ILNode_CSizeAlign_kind:
		{
			return ILNode_CName_110__((ILNode_CSizeAlign *)node__);
		}
		break;

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
		case ILNode_AsmStmt_kind:
		case ILNode_CAssignArray_kind:
		case ILNode_CAssignStruct_kind:
		case ILNode_CGotoPtr_kind:
		{
			return ILNode_CName_111__((ILNode_Statement *)node__);
		}
		break;

		case ILNode_Identifier_kind:
		{
			return ILNode_CName_112__((ILNode_Identifier *)node__);
		}
		break;

		case ILNode_QualIdent_kind:
		{
			return ILNode_CName_113__((ILNode_QualIdent *)node__);
		}
		break;

		default: break;
	}
	return (CNameDefault);
}

