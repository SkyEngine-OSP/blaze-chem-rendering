/* cg_stmt.c.  Generated automatically by treecc */
#line 3 "cg_stmt.tc"

/*
 * cg_stmt.tc - Statement nodes.
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
#include "il_dumpasm.h"

/*
 * Determine if a statement node is empty.
 */
#define	IsEmpty(node)	(!(node) || yykind((node)) == yykindof(ILNode_Empty))

/*
 * Push a new entry onto the loop stack.
 */
static void PushLoop(ILGenInfo *info, ILLabel *continueLabel,
					 ILLabel *breakLabel, char *name,
					 int isForeachCollection)
{
	if(info->loopStackSize >= info->loopStackMax)
	{
		/* Increase the size of the loop stack */
		ILLoopStack *newstack;
		newstack = (ILLoopStack *)ILRealloc(info->loopStack,
											sizeof(ILLoopStack) *
												(info->loopStackMax + 4));
		if(!newstack)
		{
			ILGenOutOfMemory(info);
		}
		info->loopStack = newstack;
		info->loopStackMax += 4;
	}
	info->loopStack[info->loopStackSize].name = name;
	info->loopStack[info->loopStackSize].continueLabel = continueLabel;
	info->loopStack[info->loopStackSize].breakLabel = breakLabel;
	info->loopStack[info->loopStackSize].finallyLabel = 0;
	info->loopStack[info->loopStackSize].isForeachCollection =
		isForeachCollection;
	++(info->loopStackSize);
}

/*
 * Push a new finally entry onto the loop stack.
 */
static void PushFinally(ILGenInfo *info, ILLabel *finallyLabel)
{
	if(info->loopStackSize >= info->loopStackMax)
	{
		/* Increase the size of the loop stack */
		ILLoopStack *newstack;
		newstack = (ILLoopStack *)ILRealloc(info->loopStack,
											sizeof(ILLoopStack) *
												(info->loopStackMax + 4));
		if(!newstack)
		{
			ILGenOutOfMemory(info);
		}
		info->loopStack = newstack;
		info->loopStackMax += 4;
	}
	info->loopStack[info->loopStackSize].name = 0;
	info->loopStack[info->loopStackSize].continueLabel = 0;
	info->loopStack[info->loopStackSize].breakLabel = 0;
	info->loopStack[info->loopStackSize].finallyLabel = finallyLabel;
	info->loopStack[info->loopStackSize].isForeachCollection = 0;
	++(info->loopStackSize);
}

/*
 * Pop an entry from the loop stack.
 */
#define	PopLoop(info)	(--((info)->loopStackSize))

void ILGenPushTry(ILGenInfo *info)
{
	PushFinally(info, 0);
}

void ILGenPopTry(ILGenInfo *info)
{
	PopLoop(info);
}

#line 180 "cg_stmt.tc"


void _ILNode_List_Add(ILNode *list, ILNode *node)
{
	if(list && node && yyisa(list, ILNode_List))
	{
		ILNode_List *temp = (ILNode_List *)list;
		while(temp->rest != 0)
		{
			temp = temp->rest;
		}
		if(temp->item1 == 0)
		{
			temp->item1 = node;
		}
		else if(temp->item2 == 0)
		{
			temp->item2 = node;
		}
		else if(temp->item3 == 0)
		{
			temp->item3 = node;
		}
		else if(temp->item4 == 0)
		{
			temp->item4 = node;
		}
		else
		{
			temp->rest = (ILNode_List *)(ILNode_List_create());
			if(temp->rest)
			{
				temp->rest->item1 = node;
			}
		}
	}
}

void _ILNode_ListIter_Init(ILNode_ListIter *iter, ILNode *node)
{
	if(node != 0 && yyisa(node, ILNode_List))
	{
		iter->list = (ILNode_List *)node;
		iter->posn = 0;
		iter->last = 0;
	}
	else
	{
		iter->list = 0;
		iter->posn = 0;
		iter->last = 0;
	}
}

ILNode *ILNode_ListIter_Next(ILNode_ListIter *iter)
{
	if(iter->list)
	{
		ILNode *node;
		switch(iter->posn)
		{
			case 0:
			{
				node = iter->list->item1;
				iter->last = &(iter->list->item1);
			}
			break;

			case 1:
			{
				node = iter->list->item2;
				iter->last = &(iter->list->item2);
			}
			break;

			case 2:
			{
				node = iter->list->item3;
				iter->last = &(iter->list->item3);
			}
			break;

			default:
			{
				node = iter->list->item4;
				iter->last = &(iter->list->item4);
			}
			break;
		}
		++(iter->posn);
		if(!node)
		{
			iter->list = 0;
			iter->posn = 0;
			iter->last = 0;
		}
		else if(iter->posn >= 4)
		{
			iter->list = iter->list->rest;
			iter->posn = 0;
		}
		return node;
	}
	else
	{
		return 0;
	}
}

int ILNode_List_Length(ILNode *list)
{
	ILNode_ListIter iter;
	ILNode *node;
	int length = 0;
	ILNode_ListIter_Init(&iter, list);
	while((node = ILNode_ListIter_Next(&iter)) != 0)
	{
		++length;
	}
	return length;
}

ILNode *ILNode_Compound_CreateFrom(ILNode *left, ILNode *right)
{
	if(left && yyisa(left, ILNode_Compound))
	{
		if(right)
		{
			ILNode_List_Add(left, right);
		}
		return left;
	}
	else if(!left)
	{
		return right;
	}
	else if(!right)
	{
		return left;
	}
	else
	{
		ILNode *list = ILNode_List_create();
		ILNode_List_Add(list, left);
		ILNode_List_Add(list, right);
		return list;
	}
}

int ILNodeEndsInFlowChange(ILNode *stmt,ILGenInfo *genInfo)
{
	if(stmt)
	{
		int flags = ILNode_EndsInReturnImpl(stmt,genInfo);
		if((flags & (IL_ENDS_IN_RETURN |
					 IL_ENDS_IN_BREAK |
					 IL_ENDS_IN_CONTINUE |
					 IL_ENDS_IN_GOTO |
					 IL_ENDS_IN_THROW)) != 0)
		{
			return 1;
		}
	}
	return 0;
}

void ILNodeAddLabel(ILNode *stmt, char *name)
{
	if(stmt && yyisa(stmt, ILNode_LabelledStatement))
	{
		((ILNode_LabelledStatement *)stmt)->name = name;
	}
}

#line 1266 "cg_stmt.tc"


/*
 * Generate return code for the current method, given a correctly
 * typed value on the top of the stack.
 */
static void GenReturn(ILGenInfo *info)
{
	int withinTry = 0;
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;
	while(size > 0)
	{
		if(stack[size - 1].continueLabel == 0 &&
		   stack[size - 1].breakLabel == 0)
		{
			withinTry = 1;
			break;
		}
		--size;
	}
	if(!withinTry)
	{
		/* Return from the method using a "ret" instruction */
		ILGenSimple(info, IL_OP_RET);
		if(info->returnType != ILType_Void)
		{
			ILGenAdjust(info, -1);
		}
	}
	else
	{
		/* We are within a "try" block, so we cannot use "ret" directly.
		   Store the return value into a temporary local variable and
		   then "leave" to a block of code at the end of the method
		   which pushes the local and invokes "ret" */
		if(info->returnType != ILType_Void)
		{
			if(info->returnVar < 0)
			{
				info->returnVar = ILGenTempTypedVar(info, info->returnType);
			}
			ILGenStoreLocal(info, (unsigned)(info->returnVar));
		}
		ILGenJump(info, IL_OP_LEAVE, &(info->returnLabel));
	}
}

#line 1602 "cg_stmt.tc"


/*
 * Trim the goto list to remove defined labels from inner scopes.
 */
static void TrimGotoList(ILGenInfo *info, int tryScope)
{
	ILGotoEntry *entry;
	ILGotoEntry *next;
	ILGotoEntry *prev;
	entry = info->gotoList;
	prev = 0;
	while(entry != 0)
	{
		if(entry->defined && entry->scopeLevel > info->scopeLevel)
		{
			/* Defined label from an inner scope */
			next = entry->next;
			ILFree(entry);
			entry = next;
			if(prev)
				prev->next = next;
			else
				info->gotoList = next;
		}
		else if(!(entry->defined) && entry->scopeLevel > info->scopeLevel)
		{
			/* Undefined label reference that is crossing a scope boundary */
			if(tryScope)
			{
				entry->crossedTry = 1;
			}
			entry->scopeLevel = info->scopeLevel;
			prev = entry;
			entry = entry->next;
		}
		else
		{
			/* Normal label reference or definition */
			prev = entry;
			entry = entry->next;
		}
	}
}

#line 1726 "cg_stmt.tc"


/*
 * Compare the top of stack with a switch case value and jump
 * to a label if the specified condition is true.
 */
static void CompareSwitchValue(ILGenInfo *info, ILEvalValue *value,
							   int opcode, int uopcode, ILLabel *label)
{
	switch(value->valueType)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		{
			ILGenInt32(info, value->un.i4Value);
			ILGenAdjust(info, 1);
			ILGenJump(info, opcode, label);
			ILGenAdjust(info, -2);
		}
		break;

		case ILMachineType_UInt32:
		{
			ILGenInt32(info, value->un.i4Value);
			ILGenAdjust(info, 1);
			ILGenJump(info, uopcode, label);
			ILGenAdjust(info, -2);
		}
		break;

		case ILMachineType_Int64:
		{
			ILGenInt64(info, value->un.i8Value);
			ILGenAdjust(info, 1);
			ILGenJump(info, opcode, label);
			ILGenAdjust(info, -2);
		}
		break;

		case ILMachineType_UInt64:
		{
			ILGenInt64(info, value->un.i8Value);
			ILGenAdjust(info, 1);
			ILGenJump(info, uopcode, label);
			ILGenAdjust(info, -2);
		}
		break;

		case ILMachineType_String:
		{
			if(opcode == IL_OP_BEQ)
			{
				if(value->un.strValue.str == 0)
				{
					/* Compare for equality against "null" */
					ILGenJump(info, IL_OP_BRFALSE, label);
					ILGenAdjust(info, -1);
				}
				else
				{
					/* Compare for equality against a literal string */
					ILGenLoadString(info, value->un.strValue.str,
									value->un.strValue.len);
					ILGenAdjust(info, 1);
					ILGenCallByName(info,
						"bool [.library]System.String::op_Equality"
							"(class [.library]System.String, "
							 "class [.library]System.String)");
					ILGenJump(info, IL_OP_BRTRUE, label);
					ILGenAdjust(info, -2);
				}
			}
			else
			{
				/* Compare against a string for some other condition */
				if(value->un.strValue.str == 0)
				{
					ILGenSimple(info, IL_OP_LDNULL);
				}
				else
				{
					ILGenLoadString(info, value->un.strValue.str,
									value->un.strValue.len);
				}
				ILGenAdjust(info, 1);
				ILGenCallByName(info,
					"int32 [.library]System.String::CompareOrdinal"
						"(class [.library]System.String, "
						 "class [.library]System.String)");
				ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenJump(info, opcode, label);
				ILGenAdjust(info, -2);
			}
		}
		break;

		default: break;
	}
}

/*
 * Generate a binary tree of "if" statements for a "switch".
 */
static void GenerateBinarySwitch(ILGenInfo *info,
								 ILSwitchValue *values,
								 unsigned long numValues,
								 ILLabel *defaultLabel,
								 unsigned tempVar)
{
	ILNode_SwitchSection *section;
	ILLabel chopLabel;
	unsigned long chopPosn;

	if(numValues <= 4)
	{
		/* This section of the table is small enough that it
		   is faster to do it with direct "if" statements */
		while(numValues > 0)
		{
			if(tempVar == ~((unsigned)0))
			{
				ILGenSimple(info, IL_OP_DUP);
			}
			else
			{
				ILGenLoadLocal(info, tempVar);
			}
			ILGenAdjust(info, 1);
			section = (ILNode_SwitchSection *)(values->section);
			CompareSwitchValue(info, &(values->value),
							   IL_OP_BEQ, IL_OP_BEQ,
							   &(section->label));
			++values;
			--numValues;
		}
		ILGenJump(info, IL_OP_BR, defaultLabel);
	}
	else
	{
		/* Chop the table into two halves, and process each half */
		chopLabel = ILLabel_Undefined;
		chopPosn = numValues / 2;
		if(tempVar == ~((unsigned)0))
		{
			ILGenSimple(info, IL_OP_DUP);
		}
		else
		{
			ILGenLoadLocal(info, tempVar);
		}
		ILGenAdjust(info, 1);
		CompareSwitchValue(info, &(values[chopPosn].value),
						   IL_OP_BGE, IL_OP_BGE_UN, &chopLabel);
		GenerateBinarySwitch(info, values, chopPosn, defaultLabel, tempVar);
		ILGenLabel(info, &chopLabel);
		GenerateBinarySwitch(info, values + chopPosn,
							 numValues - chopPosn, defaultLabel, tempVar);
	}
}

#line 725 "jv_stmt.tc"


/*
 * Generate return code for the current method, given a correctly
 * typed value on the top of the stack.
 */
static void JavaGenReturn(ILGenInfo *info)
{
	int withinTry = 0;
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;
	ILMachineType returnMachineType = ILTypeToMachineType(info->returnType);

	while(size > 0)
	{
		if(stack[size - 1].continueLabel == 0 &&
		   stack[size - 1].breakLabel == 0)
		{
			withinTry = 1;
			break;
		}
		--size;
	}
	if(withinTry)
	{
		/* Save the return value into a local variable temporarily */
		if(info->returnType != ILType_Void)
		{
			if(info->returnVar < 0)
			{
				info->returnVar = ILGenTempTypedVar(info, info->returnType);
			}
			JavaGenStoreLocal(info, (unsigned)(info->returnVar),
							  returnMachineType);
			JavaGenAdjust(info, -(JavaGenTypeSize(returnMachineType)));
		}

		/* Call the "finally" clauses of all active "try" blocks */
		size = info->loopStackSize;
		while(size > 0)
		{
			if(stack[size - 1].continueLabel == 0 &&
			   stack[size - 1].breakLabel == 0)
			{
				JavaGenJump(info, JAVA_OP_JSR, stack[size - 1].finallyLabel);
			}
			--size;
		}

		/* Restore the return value to the top of the stack */
		if(info->returnType != ILType_Void)
		{
			JavaGenLoadLocal(info, (unsigned)(info->returnVar),
							 returnMachineType);
			JavaGenAdjust(info, JavaGenTypeSize(returnMachineType));
		}
	}

	/* Output the correct form of "return" instruction */
	JavaGenReturnInsn(info, returnMachineType);
	JavaGenAdjust(info, -(JavaGenTypeSize(returnMachineType)));
}

#line 1002 "jv_stmt.tc"


/*
 * Compare the top of stack with a switch case value and jump
 * to a label if the specified condition is true.
 */
static void JavaCompareSwitchValue(ILGenInfo *info, ILEvalValue *value,
							       int opcode, int sopcode, ILLabel *label)
{
	switch(value->valueType)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		{
			JavaGenInt32(info, value->un.i4Value);
			JavaGenAdjust(info, 1);
			JavaGenJump(info, opcode, label);
			JavaGenAdjust(info, -2);
		}
		break;

		case ILMachineType_UInt32:
		{
			if(opcode == JAVA_OP_IF_ICMPEQ)
			{
				/* We can compare using signed integer operations */
				JavaGenInt32(info, value->un.i4Value);
				JavaGenAdjust(info, 1);
				JavaGenJump(info, opcode, label);
				JavaGenAdjust(info, -2);
			}
			else
			{
				/* We need to do the unsigned compare the hard way */
				JavaGenInt32(info, value->un.i4Value);
				JavaGenAdjust(info, 1);
				JavaGenCallIntrinsic(info, "iucmp", "(II)I");
				JavaGenJump(info, sopcode, label);
				JavaGenAdjust(info, -2);
			}
		}
		break;

		case ILMachineType_Int64:
		{
			JavaGenInt64(info, value->un.i8Value);
			JavaGenAdjust(info, 2);
			JavaGenSimple(info, JAVA_OP_LCMP);
			JavaGenJump(info, sopcode, label);
			JavaGenAdjust(info, -4);
		}
		break;

		case ILMachineType_UInt64:
		{
			if(opcode == JAVA_OP_IF_ICMPEQ)
			{
				/* We can compare using signed integer operations */
				JavaGenInt64(info, value->un.i8Value);
				JavaGenAdjust(info, 2);
				JavaGenSimple(info, JAVA_OP_LCMP);
				JavaGenJump(info, sopcode, label);
				JavaGenAdjust(info, -4);
			}
			else
			{
				/* We need to do the unsigned compare the hard way */
				JavaGenInt64(info, value->un.i8Value);
				JavaGenAdjust(info, 2);
				JavaGenCallIntrinsic(info, "lucmp", "(JJ)I");
				JavaGenJump(info, sopcode, label);
				JavaGenAdjust(info, -4);
			}
		}
		break;

		case ILMachineType_String:
		{
			if(opcode == JAVA_OP_IF_ICMPEQ)
			{
				if(value->un.strValue.str == 0)
				{
					/* Compare for equality against "null" */
					JavaGenJump(info, JAVA_OP_IFNULL, label);
					JavaGenAdjust(info, -1);
				}
				else if(info->useJavaLib)
				{
					/* Use Java string compare operations */
					JavaGenStringConst(info, value->un.strValue.str,
									   value->un.strValue.len);
					JavaGenAdjust(info, 1);
					JavaGenCallVirtual(info, "java/lang/String", "equals",
						   "(Ljava/lang/Object;)Z");
					JavaGenJump(info, JAVA_OP_IFNE, label);
					JavaGenAdjust(info, -2);
				}
				else
				{
					/* Use CLI string compare operations */
					JavaGenStringConst(info, value->un.strValue.str,
									   value->un.strValue.len);
					JavaGenCallByName(info, "System/String", "__FromJavaString",
						  "(Ljava/lang/String;)LSystem/String;");
					JavaGenAdjust(info, 1);
					JavaGenCallByName(info, "System/String", "op_Equality",
						  "(LSystem/String;LSystem/String;)Z");
					JavaGenJump(info, JAVA_OP_IFNE, label);
					JavaGenAdjust(info, -2);
				}
			}
			else
			{
				/* Compare against a string for greater than or equal to */
				if(value->un.strValue.str == 0)
				{
					/* All strings are greater than or equal to "null" */
					JavaGenSimple(info, JAVA_OP_POP);
					JavaGenAdjust(info, -1);
					JavaGenJump(info, JAVA_OP_GOTO, label);
				}
				else if(info->useJavaLib)
				{
					/* Use Java string compare operations */
					JavaGenStringConst(info, value->un.strValue.str,
									   value->un.strValue.len);
					JavaGenAdjust(info, 1);
					JavaGenCallVirtual(info, "java/lang/String", "compareTo",
						   "(Ljava/lang/String;)I");
					JavaGenJump(info, sopcode, label);
					JavaGenAdjust(info, -2);
				}
				else
				{
					/* Use CLI string compare operations */
					JavaGenStringConst(info, value->un.strValue.str,
									   value->un.strValue.len);
					JavaGenCallByName(info, "System/String", "__FromJavaString",
						  "(Ljava/lang/String;)LSystem/String;");
					JavaGenAdjust(info, 1);
					JavaGenCallByName(info, "System/String", "CompareOrdinal",
						  "(LSystem/String;LSystem/String;)I");
					JavaGenJump(info, sopcode, label);
					JavaGenAdjust(info, -2);
				}
			}
		}
		break;

		default: break;
	}
}

/*
 * Generate a binary tree of "if" statements for a "switch".
 */
static void JavaGenerateBinarySwitch(ILGenInfo *info,
								     ILSwitchValue *values,
								     unsigned long numValues,
								     ILLabel *defaultLabel,
									 ILMachineType type)
{
	ILNode_SwitchSection *section;
	ILLabel chopLabel;
	unsigned long chopPosn;

	if(numValues <= 4)
	{
		/* This section of the table is small enough that it
		   is faster to do it with direct "if" statements */
		while(numValues > 0)
		{
			JavaGenDup(info, type);
			section = (ILNode_SwitchSection *)(values->section);
			JavaCompareSwitchValue(info, &(values->value),
							       JAVA_OP_IF_ICMPEQ, JAVA_OP_IFEQ,
							   	   &(section->label));
			++values;
			--numValues;
		}
		JavaGenJump(info, JAVA_OP_GOTO, defaultLabel);
	}
	else
	{
		/* Chop the table into two halves, and process each half */
		chopLabel = ILLabel_Undefined;
		chopPosn = numValues / 2;
		JavaGenDup(info, type);
		JavaCompareSwitchValue(info, &(values[chopPosn].value),
						       JAVA_OP_IF_ICMPGE, JAVA_OP_IFGE, &chopLabel);
		JavaGenerateBinarySwitch(info, values, chopPosn, defaultLabel, type);
		JavaGenLabel(info, &chopLabel);
		JavaGenerateBinarySwitch(info, values + chopPosn,
							     numValues - chopPosn, defaultLabel, type);
	}
}

#line 806 "cg_stmt.c"

ILMachineType ILNode_EmptyExpr_ILNode_GetType__(ILNode_EmptyExpr *node, ILGenInfo * info)
#line 1255 "cg_nodes.tc"
{
	return node->type;
}
#line 813 "cg_stmt.c"

void ILNode_EmptyExpr_ILNode_GenDiscard__(ILNode_EmptyExpr *node, ILGenInfo * info)
#line 960 "cg_stmt.tc"
{
	/* well it's empty ! */
}
#line 820 "cg_stmt.c"

ILMachineType ILNode_EmptyExpr_ILNode_GenValue__(ILNode_EmptyExpr *node, ILGenInfo * info)
#line 1250 "cg_nodes.tc"
{
	return node->type;
}
#line 827 "cg_stmt.c"

void ILNode_EmptyExpr_JavaGenDiscard__(ILNode_EmptyExpr *node, ILGenInfo * info)
#line 467 "jv_stmt.tc"
{
	/* it's empty !*/
}
#line 834 "cg_stmt.c"

ILMachineType ILNode_EmptyExpr_JavaGenValue__(ILNode_EmptyExpr *node, ILGenInfo * info)
#line 338 "jv_nodes.tc"
{
	return node->type;
}
#line 841 "cg_stmt.c"

struct ILNode_EmptyExpr_vtable__ const ILNode_EmptyExpr_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_EmptyExpr_kind,
	"ILNode_EmptyExpr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_EmptyExpr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EmptyExpr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_EmptyExpr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EmptyExpr_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_EmptyExpr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

void ILNode_Empty_ILNode_GenDiscard__(ILNode_Empty *node, ILGenInfo * info)
#line 386 "cg_stmt.tc"
{
	/* Nothing to do here */
}
#line 865 "cg_stmt.c"

int ILNode_Empty_ILNode_EndsInReturnImpl__(ILNode_Empty *node, ILGenInfo * info)
#line 394 "cg_stmt.tc"
{
	return IL_ENDS_IN_EMPTY;
}
#line 872 "cg_stmt.c"

void ILNode_Empty_JavaGenDiscard__(ILNode_Empty *node, ILGenInfo * info)
#line 27 "jv_stmt.tc"
{
	/* Nothing to do here */
}
#line 879 "cg_stmt.c"

struct ILNode_Empty_vtable__ const ILNode_Empty_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Empty_kind,
	"ILNode_Empty",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Empty_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Empty_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Empty_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_If_ILNode_GenDiscard__(ILNode_If *node, ILGenInfo * info)
#line 466 "cg_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;

	if(ILNode_EvalConst(node->expr, info, &value) &&
	   ILGenCastConst(info, &value, value.valueType, ILMachineType_Boolean))
	{
		/* The condition is constant, so output either "then" or "else" */
		if(value.un.i4Value)
		{
			ILNode_GenDiscard(node->thenClause, info);
		}
		else
		{
			ILNode_GenDiscard(node->elseClause, info);
		}
	}
	else if(IsEmpty(node->thenClause) && IsEmpty(node->elseClause))
	{
		/* No clauses, so evaluate the expression for its side-effects */
		ILNode_GenDiscard(node->expr, info);
	}
	else if(IsEmpty(node->thenClause))
	{
		/* No "then" clause */
		ILNode_GenThen(node->expr, info, &label1);
		ILNode_GenDiscard(node->elseClause, info);
		ILGenLabel(info, &label1);
	}
	else if(IsEmpty(node->elseClause))
	{
		/* No "else" clause */
		ILNode_GenElse(node->expr, info, &label1);
		ILNode_GenDiscard(node->thenClause, info);
		ILGenLabel(info, &label1);
	}
	else
	{
		/* Generate the full case of the "if" */
		ILNode_GenElse(node->expr, info, &label1);
		ILNode_GenDiscard(node->thenClause, info);
		if(!ILNodeEndsInFlowChange(node->thenClause,info))
		{
			ILGenJump(info, IL_OP_BR, &label2);
		}
		ILGenLabel(info, &label1);
		ILNode_GenDiscard(node->elseClause, info);
		ILGenLabel(info, &label2);
	}
}
#line 951 "cg_stmt.c"

int ILNode_If_ILNode_EndsInReturnImpl__(ILNode_If *node, ILGenInfo * info)
#line 522 "cg_stmt.tc"
{
	int flags1, flags2;
	if(node->thenClause)
	{
		flags1 = ILNode_EndsInReturnImpl(node->thenClause,info);
	}
	else
	{
		flags1 = IL_ENDS_IN_EMPTY;
	}
	if(node->elseClause)
	{
		flags2 = ILNode_EndsInReturnImpl(node->elseClause,info);
	}
	else
	{
		flags2 = IL_ENDS_IN_EMPTY;
	}
	if((flags1 & IL_ENDS_IN_EMPTY) != 0 ||
	   (flags2 & IL_ENDS_IN_EMPTY) != 0)
	{
		return ((flags1 | flags2) & IL_ENDS_IN_CONTAINED_MASK);
	}
	else if((flags1 & ~IL_ENDS_IN_CONTAINED_MASK) == 0 ||
	        (flags2 & ~IL_ENDS_IN_CONTAINED_MASK) == 0)
	{
		return ((flags1 | flags2) & IL_ENDS_IN_CONTAINED_MASK);
	}
	else
	{
		return (flags1 | flags2);
	}
}
#line 988 "cg_stmt.c"

void ILNode_If_JavaGenDiscard__(ILNode_If *node, ILGenInfo * info)
#line 51 "jv_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;

	if(ILNode_EvalConst(node->expr, info, &value) &&
	   ILGenCastConst(info, &value, value.valueType, ILMachineType_Boolean))
	{
		/* The condition is constant, so output either "then" or "else" */
		if(value.un.i4Value)
		{
			JavaGenDiscard(node->thenClause, info);
		}
		else
		{
			JavaGenDiscard(node->elseClause, info);
		}
	}
	else if(IsEmpty(node->thenClause) && IsEmpty(node->elseClause))
	{
		/* No clauses, so evaluate the expression for its side-effects */
		JavaGenDiscard(node->expr, info);
	}
	else if(IsEmpty(node->thenClause))
	{
		/* No "then" clause */
		JavaGenThen(node->expr, info, &label1);
		JavaGenDiscard(node->elseClause, info);
		JavaGenLabel(info, &label1);
	}
	else if(IsEmpty(node->elseClause))
	{
		/* No "else" clause */
		JavaGenElse(node->expr, info, &label1);
		JavaGenDiscard(node->thenClause, info);
		JavaGenLabel(info, &label1);
	}
	else
	{
		/* Generate the full case of the "if" */
		JavaGenElse(node->expr, info, &label1);
		JavaGenDiscard(node->thenClause, info);
		if(!ILNodeEndsInFlowChange(node->thenClause,info))
		{
			JavaGenJump(info, JAVA_OP_GOTO, &label2);
		}
		JavaGenLabel(info, &label1);
		JavaGenDiscard(node->elseClause, info);
		JavaGenLabel(info, &label2);
	}
}
#line 1043 "cg_stmt.c"

struct ILNode_If_vtable__ const ILNode_If_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_If_kind,
	"ILNode_If",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_If_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_If_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_If_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

struct ILNode_LabelledStatement_vtable__ const ILNode_LabelledStatement_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_LabelledStatement_kind,
	"ILNode_LabelledStatement",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))0,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))0,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Break_ILNode_GenDiscard__(ILNode_Break *node, ILGenInfo * info)
#line 1120 "cg_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;
	int sawTryBlock;

	/* Look for the next outer loop or switch to break to */
	sawTryBlock = 0;
	if(size > 0 && stack[size - 1].isForeachCollection)
	{
		/* This is a "foreach" block with a surrounding "try" */
		sawTryBlock = 1;
	}
	while(size > 0 && stack[size - 1].breakLabel == 0)
	{
		if(stack[size - 1].continueLabel == 0)
		{
			sawTryBlock = 1;
		}
		--size;
	}
	if(!size)
	{
		return;
	}

	/* Jump to the break label */
	if(sawTryBlock)
	{
		ILGenJump(info, IL_OP_LEAVE, stack[size - 1].breakLabel);
	}
	else
	{
		ILGenJump(info, IL_OP_BR, stack[size - 1].breakLabel);
	}
}
#line 1116 "cg_stmt.c"

int ILNode_Break_ILNode_EndsInReturnImpl__(ILNode_Break *node, ILGenInfo * info)
#line 1096 "cg_stmt.tc"
{
	return IL_ENDS_IN_BREAK | IL_ENDS_IN_CONTAINED_BREAK;
}
#line 1123 "cg_stmt.c"

void ILNode_Break_JavaGenDiscard__(ILNode_Break *node, ILGenInfo * info)
#line 615 "jv_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;

	/* Look for the next outer loop or switch to break to */
	while(size > 0 && stack[size - 1].breakLabel == 0)
	{
		if(stack[size - 1].continueLabel == 0)
		{
			/* Call the "finally" handler for this try block */
			if(stack[size - 1].finallyLabel != 0)
			{
				JavaGenJump(info, JAVA_OP_JSR, stack[size - 1].finallyLabel);
			}
		}
		--size;
	}
	if(!size)
	{
		return;
	}

	/* Jump to the break label */
	JavaGenJump(info, JAVA_OP_GOTO, stack[size - 1].breakLabel);
}
#line 1152 "cg_stmt.c"

struct ILNode_Break_vtable__ const ILNode_Break_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Break_kind,
	"ILNode_Break",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Break_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Break_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Break_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_LabelledBreak_ILNode_GenDiscard__(ILNode_LabelledBreak *node, ILGenInfo * info)
#line 1160 "cg_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;
	int sawTryBlock;

	/* Look for the next outer loop or switch to break to */
	sawTryBlock = 0;
	if(size > 0 && stack[size - 1].isForeachCollection)
	{
		/* This is a "foreach" block with a surrounding "try" */
		sawTryBlock = 1;
	}
	while(size > 0 && stack[size - 1].name != node->name)
	{
		if(stack[size - 1].breakLabel == 0)
		{
			sawTryBlock = 1;
		}
		--size;
	}
	if(!size || !(stack[size - 1].breakLabel))
	{
		return;
	}

	/* Jump to the break label */
	if(sawTryBlock)
	{
		ILGenJump(info, IL_OP_LEAVE, stack[size - 1].breakLabel);
	}
	else
	{
		ILGenJump(info, IL_OP_BR, stack[size - 1].breakLabel);
	}
}
#line 1208 "cg_stmt.c"

int ILNode_LabelledBreak_ILNode_EndsInReturnImpl__(ILNode_LabelledBreak *node, ILGenInfo * info)
#line 1096 "cg_stmt.tc"
{
	return IL_ENDS_IN_BREAK | IL_ENDS_IN_CONTAINED_BREAK;
}
#line 1215 "cg_stmt.c"

void ILNode_LabelledBreak_JavaGenDiscard__(ILNode_LabelledBreak *node, ILGenInfo * info)
#line 645 "jv_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;

	/* Look for the next outer loop or switch to break to */
	while(size > 0 && stack[size - 1].name != node->name)
	{
		if(stack[size - 1].breakLabel == 0)
		{
			/* Call the "finally" handler for this try block */
			if(stack[size - 1].finallyLabel != 0)
			{
				JavaGenJump(info, JAVA_OP_JSR, stack[size - 1].finallyLabel);
			}
		}
		--size;
	}
	if(!size || !(stack[size - 1].breakLabel))
	{
		return;
	}

	/* Jump to the break label */
	JavaGenJump(info, JAVA_OP_GOTO, stack[size - 1].breakLabel);
}
#line 1244 "cg_stmt.c"

struct ILNode_LabelledBreak_vtable__ const ILNode_LabelledBreak_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_LabelledBreak_kind,
	"ILNode_LabelledBreak",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LabelledBreak_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_LabelledBreak_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LabelledBreak_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Continue_ILNode_GenDiscard__(ILNode_Continue *node, ILGenInfo * info)
#line 1200 "cg_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;
	int sawTryBlock;

	/* Look for the next outer loop to continue from */
	sawTryBlock = 0;
	while(size > 0 && stack[size - 1].continueLabel == 0)
	{
		if(stack[size - 1].breakLabel == 0)
		{
			sawTryBlock = 1;
		}
		--size;
	}
	if(!size)
	{
		return;
	}

	/* Jump to the continue label */
	if(sawTryBlock)
	{
		ILGenJump(info, IL_OP_LEAVE, stack[size - 1].continueLabel);
	}
	else
	{
		ILGenJump(info, IL_OP_BR, stack[size - 1].continueLabel);
	}
}
#line 1295 "cg_stmt.c"

int ILNode_Continue_ILNode_EndsInReturnImpl__(ILNode_Continue *node, ILGenInfo * info)
#line 1101 "cg_stmt.tc"
{
	return IL_ENDS_IN_CONTINUE | IL_ENDS_IN_CONTAINED_CONTINUE;
}
#line 1302 "cg_stmt.c"

void ILNode_Continue_JavaGenDiscard__(ILNode_Continue *node, ILGenInfo * info)
#line 675 "jv_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;

	/* Look for the next outer loop to continue from */
	while(size > 0 && stack[size - 1].continueLabel == 0)
	{
		if(stack[size - 1].breakLabel == 0)
		{
			/* Call the "finally" handler for this try block */
			JavaGenJump(info, JAVA_OP_JSR, stack[size - 1].finallyLabel);
		}
		--size;
	}
	if(!size)
	{
		return;
	}

	/* Jump to the continue label */
	JavaGenJump(info, JAVA_OP_GOTO, stack[size - 1].continueLabel);
}
#line 1328 "cg_stmt.c"

struct ILNode_Continue_vtable__ const ILNode_Continue_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Continue_kind,
	"ILNode_Continue",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Continue_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Continue_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Continue_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_LabelledContinue_ILNode_GenDiscard__(ILNode_LabelledContinue *node, ILGenInfo * info)
#line 1235 "cg_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;
	int sawTryBlock;

	/* Look for the next outer loop to continue from */
	sawTryBlock = 0;
	while(size > 0 && stack[size - 1].name != node->name)
	{
		if(stack[size - 1].breakLabel == 0)
		{
			sawTryBlock = 1;
		}
		--size;
	}
	if(!size || !(stack[size - 1].continueLabel))
	{
		return;
	}

	/* Jump to the continue label */
	if(sawTryBlock)
	{
		ILGenJump(info, IL_OP_LEAVE, stack[size - 1].continueLabel);
	}
	else
	{
		ILGenJump(info, IL_OP_BR, stack[size - 1].continueLabel);
	}
}
#line 1379 "cg_stmt.c"

int ILNode_LabelledContinue_ILNode_EndsInReturnImpl__(ILNode_LabelledContinue *node, ILGenInfo * info)
#line 1101 "cg_stmt.tc"
{
	return IL_ENDS_IN_CONTINUE | IL_ENDS_IN_CONTAINED_CONTINUE;
}
#line 1386 "cg_stmt.c"

void ILNode_LabelledContinue_JavaGenDiscard__(ILNode_LabelledContinue *node, ILGenInfo * info)
#line 702 "jv_stmt.tc"
{
	ILLoopStack *stack = info->loopStack;
	long size = info->loopStackSize;

	/* Look for the next outer loop to continue from */
	while(size > 0 && stack[size - 1].name != node->name)
	{
		if(stack[size - 1].breakLabel == 0)
		{
			/* Call the "finally" handler for this try block */
			JavaGenJump(info, JAVA_OP_JSR, stack[size - 1].finallyLabel);
		}
		--size;
	}
	if(!size || !(stack[size - 1].continueLabel))
	{
		return;
	}

	/* Jump to the continue label */
	JavaGenJump(info, JAVA_OP_GOTO, stack[size - 1].continueLabel);
}
#line 1412 "cg_stmt.c"

struct ILNode_LabelledContinue_vtable__ const ILNode_LabelledContinue_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_LabelledContinue_kind,
	"ILNode_LabelledContinue",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LabelledContinue_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_LabelledContinue_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LabelledContinue_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Return_ILNode_GenDiscard__(ILNode_Return *node, ILGenInfo * info)
#line 1320 "cg_stmt.tc"
{
	/* Push a default value on the stack if the real return
	   type is not "void" */
	if(info->returnType != ILType_Void)
	{
		ILGenCast(info, ILMachineType_Void,
				  ILTypeToMachineType(info->returnType));
	}

	/* Generate the correct return sequence */
	GenReturn(info);
}
#line 1445 "cg_stmt.c"

int ILNode_Return_ILNode_EndsInReturnImpl__(ILNode_Return *node, ILGenInfo * info)
#line 1091 "cg_stmt.tc"
{
	return IL_ENDS_IN_RETURN;
}
#line 1452 "cg_stmt.c"

void ILNode_Return_JavaGenDiscard__(ILNode_Return *node, ILGenInfo * info)
#line 794 "jv_stmt.tc"
{
	/* Push a default value on the stack if the real return
	   type is not "void" */
	if(info->returnType != ILType_Void)
	{
		JavaGenCast(info, ILMachineType_Void,
				    ILTypeToMachineType(info->returnType));
	}

	/* Generate the correct return sequence */
	JavaGenReturn(info);
}
#line 1468 "cg_stmt.c"

struct ILNode_Return_vtable__ const ILNode_Return_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Return_kind,
	"ILNode_Return",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Return_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Return_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Return_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_ReturnExpr_ILNode_GenDiscard__(ILNode_ReturnExpr *node, ILGenInfo * info)
#line 1337 "cg_stmt.tc"
{
	ILMachineType valueType;

	/* Evaluate the return value and cast it to the correct type */
	valueType = ILNode_GenValue(node->expr, info);
	ILGenCast(info, valueType, ILTypeToMachineType(info->returnType));

	/* Generate the correct return sequence */
	GenReturn(info);
}
#line 1499 "cg_stmt.c"

int ILNode_ReturnExpr_ILNode_EndsInReturnImpl__(ILNode_ReturnExpr *node, ILGenInfo * info)
#line 1091 "cg_stmt.tc"
{
	return IL_ENDS_IN_RETURN;
}
#line 1506 "cg_stmt.c"

void ILNode_ReturnExpr_JavaGenDiscard__(ILNode_ReturnExpr *node, ILGenInfo * info)
#line 811 "jv_stmt.tc"
{
	ILMachineType valueType;

	/* Evaluate the return value and cast it to the correct type */
	valueType = JavaGenValue(node->expr, info);
	JavaGenCast(info, valueType,
				ILTypeToMachineType(info->returnType));

	/* Generate the correct return sequence */
	JavaGenReturn(info);
}
#line 1521 "cg_stmt.c"

struct ILNode_ReturnExpr_vtable__ const ILNode_ReturnExpr_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_ReturnExpr_kind,
	"ILNode_ReturnExpr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ReturnExpr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ReturnExpr_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ReturnExpr_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Goto_ILNode_GenDiscard__(ILNode_Goto *node, ILGenInfo * info)
#line 1352 "cg_stmt.tc"
{
	ILGotoEntry *entry;
	ILLoopStack *stack;
	long size;

	/* Search the goto list for a matching name */
	entry = info->gotoList;
	while(entry != 0)
	{
		if(entry->name == node->name)
		{
			break;
		}
		entry = entry->next;
	}
	if(!entry)
	{
		/* Create a new entry */
		entry = (ILGotoEntry *)ILMalloc(sizeof(ILGotoEntry));
		if(!entry)
		{
			ILGenOutOfMemory(info);
		}
		entry->name = node->name;
		entry->defined = 0;
		entry->crossedTry = 0;
		entry->loopStackSize = info->loopStackSize;
		entry->scopeLevel = info->scopeLevel;
		entry->label = ILLabel_Undefined;
		entry->next = info->gotoList;
		info->gotoList = entry;
	}

	/* Find the location of the next outer "try" */
	stack = info->loopStack;
	size = info->loopStackSize;
	while(size > 0)
	{
		if(stack[size - 1].continueLabel == 0 &&
		   stack[size - 1].breakLabel == 0)
		{
			break;
		}
		--size;
	}

	/* Determine what type of branch to use */
	if(entry->defined)
	{
		/* We have already seen this label */
		if(size > entry->loopStackSize)
		{
			/* The label is outside the current "try" block */
			ILGenJump(info, IL_OP_LEAVE, &(entry->label));
		}
		else
		{
			/* The label is inside the current "try" block */
			ILGenJump(info, IL_OP_BR, &(entry->label));
		}
	}
	else if(!size)
	{
		/* There are no try blocks in force, so we can use "br" */
		entry->scopeLevel = info->scopeLevel;
		ILGenJump(info, IL_OP_BR, &(entry->label));
	}
	else
	{
		/* The label is not yet defined and there is a "try"
		   block in force.  We must use a the "leave" instruction
		   to allow if we are crossing a "try" block boundary .
		   Otherwise it does not make much of a difference because
		   "leave" is like "br" for this case inside try cases
		   as well. */
		entry->scopeLevel = info->scopeLevel;
		ILGenJump(info, IL_OP_LEAVE, &(entry->label));
	}
}
#line 1621 "cg_stmt.c"

int ILNode_Goto_ILNode_EndsInReturnImpl__(ILNode_Goto *node, ILGenInfo * info)
#line 1112 "cg_stmt.tc"
{
	return IL_ENDS_IN_GOTO;
}
#line 1628 "cg_stmt.c"

void ILNode_Goto_JavaGenDiscard__(ILNode_Goto *node, ILGenInfo * info)
#line 832 "jv_stmt.tc"
{
	ILGotoEntry *entry;
	ILLoopStack *stack;
	long size;

	/* Search the goto list for a matching name */
	entry = info->gotoList;
	while(entry != 0)
	{
		if(entry->name == node->name)
		{
			break;
		}
		entry = entry->next;
	}
	if(!entry)
	{
		/* Create a new entry */
		entry = (ILGotoEntry *)ILMalloc(sizeof(ILGotoEntry));
		if(!entry)
		{
			ILGenOutOfMemory(info);
		}
		entry->name = node->name;
		entry->defined = 0;
		entry->crossedTry = 0;
		entry->loopStackSize = info->loopStackSize;
		entry->scopeLevel = info->scopeLevel;
		entry->label = ILLabel_Undefined;
		entry->next = info->gotoList;
		info->gotoList = entry;
	}

	/* Find the location of the next outer "try" */
	stack = info->loopStack;
	size = info->loopStackSize;
	while(size > 0)
	{
		if(stack[size - 1].continueLabel == 0 &&
		   stack[size - 1].breakLabel == 0)
		{
			break;
		}
		--size;
	}

	/* Determine what type of branch to use */
	if(entry->defined)
	{
		/* We have already seen this label, and we may be
		   crossing a try boundary */
		JavaGenJump(info, JAVA_OP_GOTO, &(entry->label));
	}
	else if(!size)
	{
		/* There are no try blocks in force, so everything is OK */
		entry->scopeLevel = info->scopeLevel;
		JavaGenJump(info, JAVA_OP_GOTO, &(entry->label));
	}
	else
	{
		/* The label is not yet defined and there is a "try"
		   block in force.  Hopefully the programmer has put
		   the label inside this try block */
		entry->scopeLevel = info->scopeLevel;
		JavaGenJump(info, JAVA_OP_GOTO, &(entry->label));
	}
}
#line 1700 "cg_stmt.c"

struct ILNode_Goto_vtable__ const ILNode_Goto_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Goto_kind,
	"ILNode_Goto",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Goto_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Goto_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Goto_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_GotoLabel_ILNode_GenDiscard__(ILNode_GotoLabel *node, ILGenInfo * info)
#line 1436 "cg_stmt.tc"
{
	ILGotoEntry *entry;

	/* Search the goto list for a matching name */
	entry = info->gotoList;
	while(entry != 0)
	{
		if(entry->name == node->name)
		{
			break;
		}
		entry = entry->next;
	}
	if(!entry || (entry->defined && entry->scopeLevel < info->scopeLevel))
	{
		/* Create a new entry */
		entry = (ILGotoEntry *)ILMalloc(sizeof(ILGotoEntry));
		if(!entry)
		{
			ILGenOutOfMemory(info);
		}
		entry->name = node->name;
		entry->defined = 1;
		entry->crossedTry = 0;
		entry->loopStackSize = info->loopStackSize;
		entry->scopeLevel = info->scopeLevel;
		entry->label = ILLabel_Undefined;
		entry->next = info->gotoList;
		info->gotoList = entry;
	}
	else if(!(entry->defined))
	{
		/* Update the scope information for the label */
		entry->loopStackSize = info->loopStackSize;
		entry->scopeLevel = info->scopeLevel;
	}
	else
	{
		/* The label is already defined at the same scope */
		return;
	}

	/* Output the label */
	if(entry->crossedTry)
	{
		/* We must use a "leave label" because there is a
		   goto that jumps to this point that was inside the
		   scope of a "try" block */
		ILGenLeaveLabel(info, &(entry->label));
	}
	else
	{
		/* We can use a normal label */
		ILGenLabel(info, &(entry->label));
	}
}
#line 1777 "cg_stmt.c"

void ILNode_GotoLabel_JavaGenDiscard__(ILNode_GotoLabel *node, ILGenInfo * info)
#line 905 "jv_stmt.tc"
{
	ILGotoEntry *entry;

	/* Search the goto list for a matching name */
	entry = info->gotoList;
	while(entry != 0)
	{
		if(entry->name == node->name)
		{
			break;
		}
		entry = entry->next;
	}
	if(!entry || (entry->defined && entry->scopeLevel < info->scopeLevel))
	{
		/* Create a new entry */
		entry = (ILGotoEntry *)ILMalloc(sizeof(ILGotoEntry));
		if(!entry)
		{
			ILGenOutOfMemory(info);
		}
		entry->name = node->name;
		entry->defined = 1;
		entry->crossedTry = 0;
		entry->loopStackSize = info->loopStackSize;
		entry->scopeLevel = info->scopeLevel;
		entry->label = ILLabel_Undefined;
		entry->next = info->gotoList;
		info->gotoList = entry;
	}
	else if(!(entry->defined))
	{
		/* Update the scope information for the label */
		entry->loopStackSize = info->loopStackSize;
		entry->scopeLevel = info->scopeLevel;
	}
	else
	{
		/* The label is already defined at the same scope */
		return;
	}

	/* Output the label */
	JavaGenLabel(info, &(entry->label));
}
#line 1826 "cg_stmt.c"

struct ILNode_GotoLabel_vtable__ const ILNode_GotoLabel_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_GotoLabel_kind,
	"ILNode_GotoLabel",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoLabel_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoLabel_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_GotoCase_ILNode_GenDiscard__(ILNode_GotoCase *node, ILGenInfo * info)
#line 1497 "cg_stmt.tc"
{
	ILLoopStack *stack;
	int inTryBlock = 0;

	if(info->needSwitchPop)
	{
		/* Note: Because node->expr has the same type as 
		   switch->expr , this works . And what's more
		   this is a constant */
		/* Compute the switch expression's value */
		ILNode_GenValue(node->expr, info);
	}

	/* See if the goto case breaks out of a try block.  If so we
	   must use a leave, otherwise a br will do. */

	for (stack = info->loopStack + info->loopStackSize - 1; ; stack -= 1)
	{
		/* Foreach with its own try block */
		if(stack->isForeachCollection)
		{
			inTryBlock = 1;
			break;
		}

		/* A try block */
		if (stack->continueLabel == 0 && stack->breakLabel == 0)
		{
			inTryBlock = 1;
			break;
		}

		/* The switch block */
		if (stack->continueLabel == 0 && stack->breakLabel != 0)
		{
			break;
		}
	}

	if (inTryBlock)
	{
		ILGenJump(info, IL_OP_LEAVE, &(node->switchSection->label));
	}
	else
	{
		ILGenJump(info, IL_OP_BR, &(node->switchSection->label));
	}
}
#line 1895 "cg_stmt.c"

int ILNode_GotoCase_ILNode_EndsInReturnImpl__(ILNode_GotoCase *node, ILGenInfo * info)
#line 1112 "cg_stmt.tc"
{
	return IL_ENDS_IN_GOTO;
}
#line 1902 "cg_stmt.c"

void ILNode_GotoCase_JavaGenDiscard__(ILNode_GotoCase *node, ILGenInfo * info)
#line 955 "jv_stmt.tc"
{
	if(info->needSwitchPop)
	{
		/* Note: Because node->expr has the same type as 
		   switch->expr , this works . And what's more
		   this is a constant */
		/* Compute the switch expression's value */
		JavaGenValue(node->expr, info);
	}
	JavaGenJump(info,JAVA_OP_GOTO,&(node->switchSection->label));
}
#line 1917 "cg_stmt.c"

struct ILNode_GotoCase_vtable__ const ILNode_GotoCase_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_GotoCase_kind,
	"ILNode_GotoCase",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoCase_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoCase_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoCase_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_GotoDefault_ILNode_GenDiscard__(ILNode_GotoDefault *node, ILGenInfo * info)
#line 1550 "cg_stmt.tc"
{
	ILLoopStack *stack;
	ILNode_Switch * switchNode=(ILNode_Switch*)(info->currentSwitch);
	int inTryBlock = 0;

	if(info->needSwitchPop)
	{
		/* Compute the switch expression's value */
		ILNode_GenValue(switchNode->expr,info);
		/* here we have no choice , but to generate the
		   switch expression. Or maybe I could pick case[1]
		   and generate it ?. But that could cause problems*/
	}

	/* See if the goto case breaks out of a try block.  If so we
	   must use a leave, otherwise a br will do. */

	for (stack = info->loopStack + info->loopStackSize - 1; ; stack -= 1)
	{
		/* Foreach with its own try block */
		if(stack->isForeachCollection)
		{
			inTryBlock = 1;
			break;
		}

		/* A try block */
		if (stack->continueLabel == 0 && stack->breakLabel == 0)
		{
			inTryBlock = 1;
			break;
		}

		/* The switch block - there must be one */
		if (stack->continueLabel == 0 && stack->breakLabel != 0)
		{
			break;
		}
	}

	if (inTryBlock)
	{
		ILGenJump(info, IL_OP_LEAVE, &(((ILNode_SwitchSection*)
						(switchNode->defaultSection))->label));
	}
	else
	{
		ILGenJump(info, IL_OP_BR, &(((ILNode_SwitchSection*)
						(switchNode->defaultSection))->label));
	}
}
#line 1989 "cg_stmt.c"

int ILNode_GotoDefault_ILNode_EndsInReturnImpl__(ILNode_GotoDefault *node, ILGenInfo * info)
#line 1112 "cg_stmt.tc"
{
	return IL_ENDS_IN_GOTO;
}
#line 1996 "cg_stmt.c"

void ILNode_GotoDefault_JavaGenDiscard__(ILNode_GotoDefault *node, ILGenInfo * info)
#line 971 "jv_stmt.tc"
{
	ILNode_Switch * switchNode=(ILNode_Switch*)(info->currentSwitch);
	if(info->needSwitchPop)
	{
		/* Compute the switch expression's value */
		JavaGenValue(switchNode->expr,info);
		/* here we have no choice , but to generate the
		   switch expression, again.*/
	}
	JavaGenJump(info, JAVA_OP_GOTO, &(((ILNode_SwitchSection*)
					(switchNode->defaultSection))->label));
}
#line 2012 "cg_stmt.c"

struct ILNode_GotoDefault_vtable__ const ILNode_GotoDefault_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_GotoDefault_kind,
	"ILNode_GotoDefault",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoDefault_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoDefault_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_GotoDefault_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

ILMachineType ILNode_NewScope_ILNode_GetType__(ILNode_NewScope *node, ILGenInfo * info)
#line 1653 "cg_stmt.tc"
{
	return ILNode_GetType(node->stmt, info);
}
#line 2036 "cg_stmt.c"

void ILNode_NewScope_ILNode_GenDiscard__(ILNode_NewScope *node, ILGenInfo * info)
#line 1689 "cg_stmt.tc"
{
	if(info->hasGotoScopes)
	{
		/* Enter a new scope */
		++(info->scopeLevel);

		/* Generate the code within the scope */
		ILNode_GenDiscard(node->stmt, info);

		/* Exit from the scope */
		--(info->scopeLevel);

		/* Trim goto labels that were defined within the scope */
		TrimGotoList(info, 0);
	}
	else
	{
		/* Generate the code within the scope */
		ILNode_GenDiscard(node->stmt, info);
	}
}
#line 2061 "cg_stmt.c"

ILMachineType ILNode_NewScope_ILNode_GenValue__(ILNode_NewScope *node, ILGenInfo * info)
#line 1661 "cg_stmt.tc"
{
	ILMachineType type;
	if(info->hasGotoScopes)
	{
		/* Enter a new scope */
		++(info->scopeLevel);

		/* Generate the code within the scope */
		type = ILNode_GenValue(node->stmt, info);

		/* Exit from the scope */
		--(info->scopeLevel);

		/* Trim goto labels that were defined within the scope */
		TrimGotoList(info, 0);
	}
	else
	{
		/* Generate the code within the scope */
		type = ILNode_GenValue(node->stmt, info);
	}
	return type;
}
#line 2088 "cg_stmt.c"

int ILNode_NewScope_ILNode_EndsInReturnImpl__(ILNode_NewScope *node, ILGenInfo * info)
#line 1715 "cg_stmt.tc"
{
	if(node->stmt)
	{
		return ILNode_EndsInReturnImpl(node->stmt,info);
	}
	else
	{
		return IL_ENDS_IN_EMPTY;
	}
}
#line 2102 "cg_stmt.c"

void ILNode_NewScope_JavaGenDiscard__(ILNode_NewScope *node, ILGenInfo * info)
#line 988 "jv_stmt.tc"
{
	/* Enter a new scope */
	++(info->scopeLevel);

	/* Generate the code within the scope */
	JavaGenDiscard(node->stmt, info);

	/* Exit from the scope */
	--(info->scopeLevel);

	/* Trim goto labels that were defined within the scope */
	TrimGotoList(info, 0);
}
#line 2119 "cg_stmt.c"

struct ILNode_NewScope_vtable__ const ILNode_NewScope_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_NewScope_kind,
	"ILNode_NewScope",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NewScope_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NewScope_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NewScope_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_NewScope_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NewScope_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_SwitchSection_ILNode_GenDiscard__(ILNode_SwitchSection *node, ILGenInfo * info)
#line 2173 "cg_stmt.tc"
{
	/* Nothing to do here */
}
#line 2143 "cg_stmt.c"

void ILNode_SwitchSection_JavaGenDiscard__(ILNode_SwitchSection *node, ILGenInfo * info)
#line 1433 "jv_stmt.tc"
{
	/* Nothing to do here */
}
#line 2150 "cg_stmt.c"

struct ILNode_SwitchSection_vtable__ const ILNode_SwitchSection_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_SwitchSection_kind,
	"ILNode_SwitchSection",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_SwitchSection_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_SwitchSection_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_CaseLabel_ILNode_GenDiscard__(ILNode_CaseLabel *node, ILGenInfo * info)
#line 2182 "cg_stmt.tc"
{
	if(node->section)
	{
		/* Output the section label for a C-style switch */
		ILGenLabel(info, &(node->section->label));
	
		/* Pop the extra value copy if we were using "if" statements */
		if(info->needSwitchPop)
		{
			ILGenSimple(info, IL_OP_POP);
		}
	}
}
#line 2184 "cg_stmt.c"

void ILNode_CaseLabel_JavaGenDiscard__(ILNode_CaseLabel *node, ILGenInfo * info)
#line 1433 "jv_stmt.tc"
{
	/* Nothing to do here */
}
#line 2191 "cg_stmt.c"

struct ILNode_CaseLabel_vtable__ const ILNode_CaseLabel_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_CaseLabel_kind,
	"ILNode_CaseLabel",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CaseLabel_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CaseLabel_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_DefaultLabel_ILNode_GenDiscard__(ILNode_DefaultLabel *node, ILGenInfo * info)
#line 2182 "cg_stmt.tc"
{
	if(node->section)
	{
		/* Output the section label for a C-style switch */
		ILGenLabel(info, &(node->section->label));
	
		/* Pop the extra value copy if we were using "if" statements */
		if(info->needSwitchPop)
		{
			ILGenSimple(info, IL_OP_POP);
		}
	}
}
#line 2225 "cg_stmt.c"

void ILNode_DefaultLabel_JavaGenDiscard__(ILNode_DefaultLabel *node, ILGenInfo * info)
#line 1433 "jv_stmt.tc"
{
	/* Nothing to do here */
}
#line 2232 "cg_stmt.c"

struct ILNode_DefaultLabel_vtable__ const ILNode_DefaultLabel_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_DefaultLabel_kind,
	"ILNode_DefaultLabel",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DefaultLabel_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DefaultLabel_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Throw_ILNode_GenDiscard__(ILNode_Throw *node, ILGenInfo * info)
#line 2200 "cg_stmt.tc"
{
	ILGenSimple(info, IL_OP_PREFIX + IL_PREFIX_OP_RETHROW);
}
#line 2256 "cg_stmt.c"

int ILNode_Throw_ILNode_EndsInReturnImpl__(ILNode_Throw *node, ILGenInfo * info)
#line 1106 "cg_stmt.tc"
{
	return IL_ENDS_IN_THROW;
}
#line 2263 "cg_stmt.c"

void ILNode_Throw_JavaGenDiscard__(ILNode_Throw *node, ILGenInfo * info)
#line 1441 "jv_stmt.tc"
{
	/* Push the contents of the current throw variable onto
	   the stack and then re-throw it */
	JavaGenLoadLocal(info, info->throwVariable, ILMachineType_ObjectRef);
	JavaGenAdjust(info, 1);
	JavaGenSimple(info, JAVA_OP_ATHROW);
	JavaGenAdjust(info, -1);
}
#line 2275 "cg_stmt.c"

struct ILNode_Throw_vtable__ const ILNode_Throw_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Throw_kind,
	"ILNode_Throw",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Throw_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Throw_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Throw_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_ThrowExpr_ILNode_GenDiscard__(ILNode_ThrowExpr *node, ILGenInfo * info)
#line 2208 "cg_stmt.tc"
{
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_ObjectRef);
	ILGenSimple(info, IL_OP_THROW);
	ILGenAdjust(info, -1);
}
#line 2302 "cg_stmt.c"

int ILNode_ThrowExpr_ILNode_EndsInReturnImpl__(ILNode_ThrowExpr *node, ILGenInfo * info)
#line 1106 "cg_stmt.tc"
{
	return IL_ENDS_IN_THROW;
}
#line 2309 "cg_stmt.c"

void ILNode_ThrowExpr_JavaGenDiscard__(ILNode_ThrowExpr *node, ILGenInfo * info)
#line 1454 "jv_stmt.tc"
{
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);
	JavaGenSimple(info, JAVA_OP_ATHROW);
	JavaGenAdjust(info, -1);
}
#line 2319 "cg_stmt.c"

struct ILNode_ThrowExpr_vtable__ const ILNode_ThrowExpr_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_ThrowExpr_kind,
	"ILNode_ThrowExpr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ThrowExpr_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ThrowExpr_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ThrowExpr_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Try_ILNode_GenDiscard__(ILNode_Try *node, ILGenInfo * info)
#line 2219 "cg_stmt.tc"
{
	ILLabel label = ILLabel_Undefined;

	/* Push an item onto the loop stack which marks the "try" block */
	PushFinally(info, 0);

	/* Output the front of the "try" block */
	if(info->asmOutput)
	{
		fputs("\t.try {\n", info->asmOutput);
		if(node->finallyClause && node->catchClauses)
		{
			/* We need two levels of ".try" if we have both
			   "catch" and "finally" blocks */
			fputs("\t.try {\n", info->asmOutput);
		}
	}

	/* Output the body of the "try" block */
	ILNode_GenDiscard(node->stmt, info);

	/* Jump to the end of the "try" statement */
	if(!ILNodeEndsInFlowChange(node->stmt,info))
	{
		ILGenJump(info, IL_OP_LEAVE, &label);
	}

	/* Terminate the body of the "try" block */
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}

	/* Output the catch clauses */
	if(node->catchClauses)
	{
		ILNode_ListIter iter;
		ILNode *clause;
		ILNode_ListIter_Init(&iter, node->catchClauses);
		while((clause = ILNode_ListIter_Next(&iter)) != 0)
		{
			ILNode_GenDiscard(clause, info);
			if(!ILNodeEndsInFlowChange(clause,info))
			{
				ILGenJump(info, IL_OP_LEAVE, &label);
			}
			if(info->asmOutput)
			{
				fputs("\t}\n", info->asmOutput);
			}
		}
	}

	/* Remove the item from the loop stack which marks the "try" block */
	PopLoop(info);

	/* Output the finally clause */
	if(node->finallyClause)
	{
		if(node->catchClauses)
		{
			if(info->asmOutput)
			{
				fputs("\t}\n", info->asmOutput);
			}
		}
		ILNode_GenDiscard(node->finallyClause, info);
	}

	/* Set the label that marks the end of the "try" statement */
	ILGenLabel(info, &label);
}
#line 2412 "cg_stmt.c"

int ILNode_Try_ILNode_EndsInReturnImpl__(ILNode_Try *node, ILGenInfo * info)
#line 2296 "cg_stmt.tc"
{
	int flags, cflags;

	/* Check the body of the "try" */
	if(node->stmt)
	{
		flags = ILNode_EndsInReturnImpl(node->stmt,info);
	}
	else
	{
		flags = IL_ENDS_IN_EMPTY;
	}

	/* Check that all "catch" clauses end in returns */
	if(node->catchClauses)
	{
		ILNode_ListIter iter;
		ILNode *clause;
		ILNode_ListIter_Init(&iter, node->catchClauses);
		while((clause = ILNode_ListIter_Next(&iter)) != 0)
		{
			cflags = ILNode_EndsInReturnImpl(clause,info);
			if((cflags & (IL_ENDS_IN_RETURN |
						  IL_ENDS_IN_BREAK |
						  IL_ENDS_IN_CONTINUE |
						  IL_ENDS_IN_GOTO |
						  IL_ENDS_IN_THROW)) != 0)
			{
				if((flags & (IL_ENDS_IN_RETURN |
							 IL_ENDS_IN_BREAK |
							 IL_ENDS_IN_CONTINUE |
							 IL_ENDS_IN_GOTO |
							 IL_ENDS_IN_THROW)) != 0)
				{
					flags |= cflags;
				}
				else
				{
					flags = ((flags | cflags) & IL_ENDS_IN_CONTAINED_MASK);
				}
			}
			else
			{
				flags = ((flags | cflags) & IL_ENDS_IN_CONTAINED_MASK);
			}
		}
	}

	/* Return the final flags to the caller */
	return flags;
}
#line 2467 "cg_stmt.c"

void ILNode_Try_JavaGenDiscard__(ILNode_Try *node, ILGenInfo * info)
#line 1465 "jv_stmt.tc"
{
	ILLabel finallyLabel = ILLabel_Undefined;
	ILLabel endLabel = ILLabel_Undefined;

	/* Push an item onto the loop stack which marks the "try" block */
	if(node->finallyClause)
	{
		PushFinally(info, &finallyLabel);
	}
	else
	{
		PushFinally(info, 0);
	}

	/* Output the front of the "try" block */
	if(info->asmOutput)
	{
		fputs("\t.try {\n", info->asmOutput);
	}

	/* Output the body of the "try" block */
	JavaGenDiscard(node->stmt, info);

	/* Jump to the end of the "try" statement */
	if(!ILNodeEndsInFlowChange(node->stmt,info))
	{
		if(node->finallyClause)
		{
			JavaGenJump(info, JAVA_OP_JSR, &finallyLabel);
		}
		JavaGenJump(info, JAVA_OP_GOTO, &endLabel);
	}

	/* Terminate the body of the "try" block */
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}

	/* Output the catch clauses */
	if(node->catchClauses)
	{
		ILNode_ListIter iter;
		ILNode *clause;
		ILNode_ListIter_Init(&iter, node->catchClauses);
		while((clause = ILNode_ListIter_Next(&iter)) != 0)
		{
			JavaGenDiscard(clause, info);
			if(!ILNodeEndsInFlowChange(clause,info))
			{
				if(node->finallyClause)
				{
					JavaGenJump(info, JAVA_OP_JSR, &finallyLabel);
				}
				JavaGenJump(info, JAVA_OP_GOTO, &endLabel);
			}
			if(info->asmOutput)
			{
				fputs("\t}\n", info->asmOutput);
			}
		}
	}

	/* Add an extra catch block to catch any exception
	   if the "try" statement has a "finally" clause */
   	if(node->finallyClause)
	{
		/* Create a temporary local to hold the thrown exception.
		   We never free this variable so that the code generator will
		   not accidentally reuse the variable for non-exception values */
		unsigned tempVar = ILGenTempVar(info, ILMachineType_ObjectRef);
		if(info->asmOutput)
		{
			fputs("\tcatch {\n", info->asmOutput);
		}
		JavaGenExtend(info, 1);
		JavaGenStoreLocal(info, tempVar, ILMachineType_ObjectRef);
		JavaGenJump(info, JAVA_OP_JSR, &finallyLabel);
		JavaGenLoadLocal(info, tempVar, ILMachineType_ObjectRef);
		JavaGenSimple(info, JAVA_OP_ATHROW);
		if(info->asmOutput)
		{
			fputs("\t}\n", info->asmOutput);
		}
	}

	/* Remove the item from the loop stack which marks the "try" block */
	PopLoop(info);

	/* Output the finally clause */
	if(node->finallyClause)
	{
		if(info->asmOutput)
		{
			fputs("\tfinally {\n", info->asmOutput);
		}
		JavaGenLabel(info, &finallyLabel);
		JavaGenDiscard(node->finallyClause, info);
		if(info->asmOutput)
		{
			fputs("\t}\n", info->asmOutput);
		}
	}

	/* Set the label that marks the end of the "try" statement */
	JavaGenLabel(info, &endLabel);
}
#line 2578 "cg_stmt.c"

struct ILNode_Try_vtable__ const ILNode_Try_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Try_kind,
	"ILNode_Try",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Try_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Try_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Try_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_CatchClause_ILNode_GenDiscard__(ILNode_CatchClause *node, ILGenInfo * info)
#line 2352 "cg_stmt.tc"
{
	/* Output the catch header */
	if(info->asmOutput)
	{
		fputs("\tcatch ", info->asmOutput);
		ILDumpClassName(info->asmOutput, info->image, node->classInfo,
						IL_DUMP_QUOTE_NAMES);
		fputs(" {\n", info->asmOutput);
	}

	/* There is an extra object on the stack on entry to the catch block */
	ILGenAdjust(info, 1);

	/* Store the exception object into a local, or pop it if no local */
	if(node->name)
	{
		ILGenStoreLocal(info, (unsigned)(node->varIndex));
	}
	else
	{
		ILGenSimple(info, IL_OP_POP);
	}
	ILGenAdjust(info, -1);

	/* Output the body of the catch block */
	ILNode_GenDiscard(node->stmt, info);

	/* Note: the end of the catch is output by the "ILNode_Try" logic */
}
#line 2628 "cg_stmt.c"

int ILNode_CatchClause_ILNode_EndsInReturnImpl__(ILNode_CatchClause *node, ILGenInfo * info)
#line 2386 "cg_stmt.tc"
{
	if(node->stmt)
	{
		return ILNode_EndsInReturnImpl(node->stmt,info);
	}
	else
	{
		return IL_ENDS_IN_EMPTY;
	}
}
#line 2642 "cg_stmt.c"

void ILNode_CatchClause_JavaGenDiscard__(ILNode_CatchClause *node, ILGenInfo * info)
#line 1577 "jv_stmt.tc"
{
	/* Output the catch header */
	if(info->asmOutput)
	{
		fputs("\tcatch ", info->asmOutput);
		ILDumpClassName(info->asmOutput, info->image, node->classInfo,
						IL_DUMP_QUOTE_NAMES);
		fputs(" {\n", info->asmOutput);
	}

	/* There is an extra object on the stack on entry to the catch block */
	JavaGenAdjust(info, 1);

	/* Determine which local to use to store the throw value.
	   Bug: if the program modifies a catch variable and then
	   re-throws an exception with "throw;", then the modified
	   value will be thrown instead of the original.  This is
	   not 100% correct according to C# semantics, but is rare
	   enough that we can probably ignore the problem for now */
	if(node->name)
	{
		info->throwVariable = (long)(node->varIndex);
	}
	else
	{
		info->throwVariable =
			ILGenTempTypedVar(info, ILType_FromClass(node->classInfo));
	}

	/* Store the exception object into the local */
	JavaGenStoreLocal(info, (unsigned)(info->throwVariable),
					  ILMachineType_ObjectRef);
	JavaGenAdjust(info, -1);

	/* Output the body of the catch block */
	JavaGenDiscard(node->stmt, info);

	/* Release the temporary throw variable */
	if(!(node->name))
	{
		ILGenReleaseTempVar(info, (unsigned)(info->throwVariable));
	}
	info->throwVariable = -1;

	/* Note: the end of the catch is output by the "ILNode_Try" logic */
}
#line 2692 "cg_stmt.c"

struct ILNode_CatchClause_vtable__ const ILNode_CatchClause_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_CatchClause_kind,
	"ILNode_CatchClause",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CatchClause_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_CatchClause_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CatchClause_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_FinallyClause_ILNode_GenDiscard__(ILNode_FinallyClause *node, ILGenInfo * info)
#line 2401 "cg_stmt.tc"
{
	if(info->asmOutput)
	{
		fputs("\tfinally {\n", info->asmOutput);
	}
	ILNode_GenDiscard(node->stmt, info);
	if(info->asmOutput)
	{
		if(!ILNodeEndsInFlowChange(node->stmt,info))
		{
			ILGenSimple(info, IL_OP_ENDFINALLY);
		}
		fputs("\t}\n", info->asmOutput);
	}
}
#line 2728 "cg_stmt.c"

int ILNode_FinallyClause_ILNode_EndsInReturnImpl__(ILNode_FinallyClause *node, ILGenInfo * info)
#line 2421 "cg_stmt.tc"
{
	if(node->stmt)
	{
		return ILNode_EndsInReturnImpl(node->stmt,info);
	}
	else
	{
		return IL_ENDS_IN_EMPTY;
	}
}
#line 2742 "cg_stmt.c"

void ILNode_FinallyClause_JavaGenDiscard__(ILNode_FinallyClause *node, ILGenInfo * info)
#line 1628 "jv_stmt.tc"
{
	unsigned varNum;

	/* Allocate a temporary variable to hold the return address.
	   We never free this variable so that the code generator will
	   not accidentally reuse the variable for non-address values */
	varNum = ILGenTempVar(info, ILMachineType_ObjectRef);

	/* Save the return address into the temporary local variable */
	JavaGenAdjust(info, 1);
	JavaGenStoreLocal(info, varNum, ILMachineType_ObjectRef);
	JavaGenAdjust(info, -1);

	/* Output the code for the clause body */
	JavaGenDiscard(node->stmt, info);

	/* If the clause falls through, then output a "ret" instruction */
	if(!ILNodeEndsInFlowChange(node->stmt,info))
	{
		JavaGenRet(info, varNum);
	}
}
#line 2768 "cg_stmt.c"

struct ILNode_FinallyClause_vtable__ const ILNode_FinallyClause_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_FinallyClause_kind,
	"ILNode_FinallyClause",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FinallyClause_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_FinallyClause_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FinallyClause_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Lock_ILNode_GenDiscard__(ILNode_Lock *node, ILGenInfo * info)
#line 2436 "cg_stmt.tc"
{
	unsigned tempVar;
	ILLabel endLabel = ILLabel_Undefined;

	/* Allocate a temporary local variable to hold the lock object */
	tempVar = ILGenTempVar(info, ILMachineType_ObjectRef);

	/* Evaluate the expression and copy it into the temporary local */
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_ObjectRef);
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);
	ILGenStoreLocal(info, tempVar);
	ILGenAdjust(info, -1);

	/* Enter a monitor on the object */
	ILGenCallByName(info, "void [.library]System.Threading.Monitor::Enter"
								"(class [.library]System.Object)");
	ILGenAdjust(info, -1);

	/* Output the body of the lock statement within a "try" block */
	PushFinally(info, 0);
	if(info->asmOutput)
	{
		fputs("\t.try {\n", info->asmOutput);
	}
	ILNode_GenDiscard(node->stmt, info);
	if(!ILNodeEndsInFlowChange(node->stmt,info))
	{
		ILGenJump(info, IL_OP_LEAVE, &endLabel);
	}
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}
	PopLoop(info);

	/* Output the "finally" clause which exits the monitor */
	if(info->asmOutput)
	{
		fputs("\tfinally {\n", info->asmOutput);
	}
	ILGenLoadLocal(info, tempVar);
	ILGenCallByName(info, "void [.library]System.Threading.Monitor::Exit"
								"(class [.library]System.Object)");
	ILGenExtend(info, 1);
	if(info->asmOutput)
	{
		ILGenSimple(info, IL_OP_ENDFINALLY);
		fputs("\t}\n", info->asmOutput);
	}

	/* Set the label at the end of the "try" block */
	ILGenLabel(info, &endLabel);

	/* Free the temporary variable, which we no longer require */
	ILGenReleaseTempVar(info, tempVar);
}
#line 2847 "cg_stmt.c"

int ILNode_Lock_ILNode_EndsInReturnImpl__(ILNode_Lock *node, ILGenInfo * info)
#line 2499 "cg_stmt.tc"
{
	if(node->stmt)
	{
		return ILNode_EndsInReturnImpl(node->stmt,info);
	}
	else
	{
		return IL_ENDS_IN_EMPTY;
	}
}
#line 2861 "cg_stmt.c"

void ILNode_Lock_JavaGenDiscard__(ILNode_Lock *node, ILGenInfo * info)
#line 1655 "jv_stmt.tc"
{
	unsigned tempVar, tempVar2;
	ILLabel endLabel = ILLabel_Undefined;
	ILLabel finallyLabel = ILLabel_Undefined;

	/* Allocate a temporary local variable to hold the lock object */
	tempVar = ILGenTempVar(info, ILMachineType_ObjectRef);

	/* Evaluate the expression and copy it into the temporary local */
	JavaGenCast(info, JavaGenValue(node->expr, info), ILMachineType_ObjectRef);
	JavaGenSimple(info, JAVA_OP_DUP);
	JavaGenAdjust(info, 1);
	JavaGenStoreLocal(info, tempVar, ILMachineType_ObjectRef);
	JavaGenAdjust(info, -1);

	/* Enter a monitor on the object */
	JavaGenSimple(info, JAVA_OP_MONITORENTER);
	JavaGenAdjust(info, -1);

	/* Output the body of the lock statement within a "try" block */
	PushFinally(info, &finallyLabel);
	if(info->asmOutput)
	{
		fputs("\t.try {\n", info->asmOutput);
	}
	JavaGenDiscard(node->stmt, info);
	if(!ILNodeEndsInFlowChange(node->stmt,info))
	{
		/* We can short-cut the finally processing, by doing the exit here */
		JavaGenLoadLocal(info, tempVar, ILMachineType_ObjectRef);
		JavaGenSimple(info, JAVA_OP_MONITOREXIT);
		JavaGenExtend(info, 1);
		JavaGenJump(info, JAVA_OP_GOTO, &endLabel);
	}
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}
	PopLoop(info);

	/* Output a default "catch" clause that catches all exceptions */
	tempVar2 = ILGenTempVar(info, ILMachineType_ObjectRef);
	if(info->asmOutput)
	{
		fputs("\tcatch {\n", info->asmOutput);
	}
	JavaGenExtend(info, 1);
	JavaGenStoreLocal(info, tempVar2, ILMachineType_ObjectRef);
	JavaGenJump(info, JAVA_OP_JSR, &finallyLabel);
	JavaGenLoadLocal(info, tempVar2, ILMachineType_ObjectRef);
	JavaGenSimple(info, JAVA_OP_ATHROW);
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}

	/* Output the "finally" clause which exits the monitor
	   when an exception is caught, or when "break", "continue",
	   or "return" is used to exit the lock statement */
	if(info->asmOutput)
	{
		fputs("\tfinally {\n", info->asmOutput);
	}
	JavaGenLabel(info, &finallyLabel);
	tempVar2 = ILGenTempVar(info, ILMachineType_ObjectRef);
	JavaGenStoreLocal(info, tempVar2, ILMachineType_ObjectRef); /* save addr */
	JavaGenExtend(info, 1);
	JavaGenLoadLocal(info, tempVar, ILMachineType_ObjectRef);
	JavaGenSimple(info, JAVA_OP_MONITOREXIT);
	JavaGenExtend(info, 1);
	JavaGenRet(info, tempVar2);
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}

	/* Set the label at the end of the "try" block */
	JavaGenLabel(info, &endLabel);

	/* Free the temporary lock variable, which we no longer require */
	ILGenReleaseTempVar(info, tempVar);
}
#line 2947 "cg_stmt.c"

struct ILNode_Lock_vtable__ const ILNode_Lock_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Lock_kind,
	"ILNode_Lock",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Lock_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Lock_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Lock_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_LocalVarDeclaration_ILNode_GenDiscard__(ILNode_LocalVarDeclaration *node, ILGenInfo * info)
#line 2514 "cg_stmt.tc"
{
	/* Nothing to do here: the declaration is done in the method header */
}
#line 2971 "cg_stmt.c"

void ILNode_LocalVarDeclaration_JavaGenDiscard__(ILNode_LocalVarDeclaration *node, ILGenInfo * info)
#line 1742 "jv_stmt.tc"
{
	/* Nothing to do here: the declaration is done in the method header */
}
#line 2978 "cg_stmt.c"

struct ILNode_LocalVarDeclaration_vtable__ const ILNode_LocalVarDeclaration_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_LocalVarDeclaration_kind,
	"ILNode_LocalVarDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalVarDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalVarDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_LocalConstDeclaration_ILNode_GenDiscard__(ILNode_LocalConstDeclaration *node, ILGenInfo * info)
#line 2522 "cg_stmt.tc"
{
	/* Nothing to do here: semantic analysis expands constants in-line */
}
#line 3002 "cg_stmt.c"

void ILNode_LocalConstDeclaration_JavaGenDiscard__(ILNode_LocalConstDeclaration *node, ILGenInfo * info)
#line 1750 "jv_stmt.tc"
{
	/* Nothing to do here: semantic analysis expands constants in-line */
}
#line 3009 "cg_stmt.c"

struct ILNode_LocalConstDeclaration_vtable__ const ILNode_LocalConstDeclaration_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_LocalConstDeclaration_kind,
	"ILNode_LocalConstDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalConstDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LocalConstDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_LineInfo_ILNode_GenDiscard__(ILNode_LineInfo *node, ILGenInfo * info)
#line 2530 "cg_stmt.tc"
{
	if(info->asmOutput)
	{
		fprintf(info->asmOutput, ".line %ld \"%s\"\n",
				yygetlinenum(node), yygetfilename(node));
	}
	if(node->stmt)
	{
		ILNode_GenDiscard(node->stmt, info);
	}
}
#line 3041 "cg_stmt.c"

int ILNode_LineInfo_ILNode_EndsInReturnImpl__(ILNode_LineInfo *node, ILGenInfo * info)
#line 2546 "cg_stmt.tc"
{
	if(node->stmt)
	{
		return ILNode_EndsInReturnImpl(node->stmt,info);
	}
	else
	{
		return IL_ENDS_IN_EMPTY;
	}
}
#line 3055 "cg_stmt.c"

void ILNode_LineInfo_JavaGenDiscard__(ILNode_LineInfo *node, ILGenInfo * info)
#line 1758 "jv_stmt.tc"
{
	/* TODO */
}
#line 3062 "cg_stmt.c"

struct ILNode_LineInfo_vtable__ const ILNode_LineInfo_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_LineInfo_kind,
	"ILNode_LineInfo",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LineInfo_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_LineInfo_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_LineInfo_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_EventAddOrRemove_ILNode_GenDiscard__(ILNode_EventAddOrRemove *node, ILGenInfo * info)
#line 2561 "cg_stmt.tc"
{
	if(node->thisExpr)
	{
		/* Event is based off an object */
		ILNode_GenValue(node->thisExpr, info);
		ILNode_GenValue(node->delegateExpr, info);
		if(ILMethod_IsVirtual(node->method))
		{
			ILGenCallVirtByMethod(info, node->method);
		}
		else
		{
			ILGenCallByMethod(info, node->method);
		}
		ILGenAdjust(info, -2);
	}
	else
	{
		/* Event is static */
		ILNode_GenValue(node->delegateExpr, info);
		ILGenCallByMethod(info, node->method);
		ILGenAdjust(info, -1);
	}
}
#line 3107 "cg_stmt.c"

void ILNode_EventAddOrRemove_JavaGenDiscard__(ILNode_EventAddOrRemove *node, ILGenInfo * info)
#line 1766 "jv_stmt.tc"
{
	if(node->thisExpr)
	{
		/* Event is based off an object */
		JavaGenValue(node->thisExpr, info);
		JavaGenValue(node->delegateExpr, info);
		JavaGenCallByMethod(info, node->method);
		JavaGenAdjust(info, -2);
	}
	else
	{
		/* Event is static */
		JavaGenValue(node->delegateExpr, info);
		JavaGenCallByMethod(info, node->method);
		JavaGenAdjust(info, -1);
	}
}
#line 3128 "cg_stmt.c"

struct ILNode_EventAddOrRemove_vtable__ const ILNode_EventAddOrRemove_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_EventAddOrRemove_kind,
	"ILNode_EventAddOrRemove",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EventAddOrRemove_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EventAddOrRemove_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Compound_ILNode_GenDiscard__(ILNode_Compound *node, ILGenInfo * info)
#line 403 "cg_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *current;

	ILNode_ListIter_Init(&iter, node);
	while((current = ILNode_ListIter_Next(&iter)) != 0)
	{
		ILNode_GenDiscard(current, info);
	}
}
#line 3159 "cg_stmt.c"

ILMachineType ILNode_Compound_ILNode_GenValue__(ILNode_Compound *node, ILGenInfo * info)
#line 419 "cg_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *current;
	ILMachineType lastType = ILMachineType_Void;

	ILNode_ListIter_Init(&iter, node);
	while((current = ILNode_ListIter_Next(&iter)) != 0)
	{
		if(!yyisa(node, ILNode_Empty))
		{
			if(lastType != ILMachineType_Void)
			{
				ILGenSimple(info, IL_OP_POP);
				ILGenAdjust(info, -1);
			}
			lastType = ILNode_GenValue(current, info);
		}
	}
	return lastType;
}
#line 3183 "cg_stmt.c"

int ILNode_Compound_ILNode_EndsInReturnImpl__(ILNode_Compound *node, ILGenInfo * info)
#line 445 "cg_stmt.tc"
{
	int flags1, flags2;
	ILNode_ListIter iter;
	ILNode *child;
	flags1 = IL_ENDS_IN_EMPTY;
	ILNode_ListIter_Init(&iter, node);
	while((child = ILNode_ListIter_Next(&iter)) != 0)
	{
		flags2 = ILNode_EndsInReturnImpl(child,info);
		if((flags2 & IL_ENDS_IN_EMPTY) == 0)
		{
			flags1 = (flags1 & IL_ENDS_IN_CONTAINED_MASK) | flags2;
		}
	}
	return flags1;
}
#line 3203 "cg_stmt.c"

void ILNode_Compound_JavaGenDiscard__(ILNode_Compound *node, ILGenInfo * info)
#line 36 "jv_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *current;

	ILNode_ListIter_Init(&iter, node);
	while((current = ILNode_ListIter_Next(&iter)) != 0)
	{
		JavaGenDiscard(current, info);
	}
}
#line 3217 "cg_stmt.c"

struct ILNode_Compound_vtable__ const ILNode_Compound_vt__ = {
	&ILNode_List_vt__,
	ILNode_Compound_kind,
	"ILNode_Compound",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Compound_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Compound_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Compound_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Compound_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_SwitchSectList_ILNode_GenDiscard__(ILNode_SwitchSectList *node, ILGenInfo * info)
#line 2173 "cg_stmt.tc"
{
	/* Nothing to do here */
}
#line 3241 "cg_stmt.c"

void ILNode_SwitchSectList_JavaGenDiscard__(ILNode_SwitchSectList *node, ILGenInfo * info)
#line 1433 "jv_stmt.tc"
{
	/* Nothing to do here */
}
#line 3248 "cg_stmt.c"

struct ILNode_SwitchSectList_vtable__ const ILNode_SwitchSectList_vt__ = {
	&ILNode_List_vt__,
	ILNode_SwitchSectList_kind,
	"ILNode_SwitchSectList",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_SwitchSectList_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_SwitchSectList_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_CaseList_ILNode_GenDiscard__(ILNode_CaseList *node, ILGenInfo * info)
#line 2173 "cg_stmt.tc"
{
	/* Nothing to do here */
}
#line 3272 "cg_stmt.c"

void ILNode_CaseList_JavaGenDiscard__(ILNode_CaseList *node, ILGenInfo * info)
#line 1433 "jv_stmt.tc"
{
	/* Nothing to do here */
}
#line 3279 "cg_stmt.c"

struct ILNode_CaseList_vtable__ const ILNode_CaseList_vt__ = {
	&ILNode_List_vt__,
	ILNode_CaseList_kind,
	"ILNode_CaseList",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CaseList_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_CaseList_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

struct ILNode_CatchClauses_vtable__ const ILNode_CatchClauses_vt__ = {
	&ILNode_List_vt__,
	ILNode_CatchClauses_kind,
	"ILNode_CatchClauses",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_List_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_List_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_While_ILNode_GenDiscard__(ILNode_While *node, ILGenInfo * info)
#line 560 "cg_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;

	if(ILNode_EvalConst(node->cond, info, &value) &&
	   ILGenCastConst(info, &value, value.valueType, ILMachineType_Boolean))
	{
		/* The condition is constant */
		if(value.un.i4Value)
		{
			/* Generate code for an infinite loop */
			PushLoop(info, &label1, &label2, node->name, 0);
			ILGenLabel(info, &label1);
			if(node->stmt)
			{
				ILNode_GenDiscard(node->stmt, info);
			}
			ILGenJump(info, IL_OP_BR, &label1);
			ILGenLabel(info, &label2);
			PopLoop(info);
		}
	}
	else if(IsEmpty(node->stmt))
	{
		/* The loop body is empty, so loop on the condition's side-effects */
		ILGenLabel(info, &label1);
		ILNode_GenThen(node->cond, info, &label1);
	}
	else
	{
		/* Generate the full case of the "while" loop */
		PushLoop(info, &label2, &label3, node->name, 0);
		ILGenJump(info, IL_OP_BR, &label2);
		ILGenLabel(info, &label1);
		ILNode_GenDiscard(node->stmt, info);
		ILGenLabel(info, &label2);
		ILNode_GenThen(node->cond, info, &label1);
		ILGenLabel(info, &label3);
		PopLoop(info);
	}
}
#line 3360 "cg_stmt.c"

int ILNode_While_ILNode_EndsInReturnImpl__(ILNode_While *node, ILGenInfo * info)
#line 610 "cg_stmt.tc"
{
	int flags;
	ILEvalValue evalue;
	if(!(node->cond) || 
		( ILNode_EvalConst(node->cond,info,&evalue) &&
		  (evalue.valueType == ILMachineType_Boolean) &&
		  (evalue.un.i4Value == 1) /* true */
		))
	{
		/* This may be an infinite loop: check for a contained "break" */
		if(node->stmt)
		{
			flags = ILNode_EndsInReturnImpl(node->stmt,info);
			if((flags & IL_ENDS_IN_CONTAINED_BREAK) != 0)
			{
				return 0;
			}
			else
			{
				return IL_ENDS_IN_RETURN;
			}
		}
		else
		{
			return IL_ENDS_IN_RETURN;
		}
	}
	else
	{
		/* This loop will probably exit at some point */
		return 0;
	}
}
#line 3397 "cg_stmt.c"

void ILNode_While_JavaGenDiscard__(ILNode_While *node, ILGenInfo * info)
#line 107 "jv_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;

	if(ILNode_EvalConst(node->cond, info, &value) &&
	   ILGenCastConst(info, &value, value.valueType, ILMachineType_Boolean))
	{
		/* The condition is constant */
		if(value.un.i4Value)
		{
			/* Generate code for an infinite loop */
			PushLoop(info, &label1, &label2, node->name, 0);
			JavaGenLabel(info, &label1);
			if(node->stmt)
			{
				JavaGenDiscard(node->stmt, info);
			}
			JavaGenJump(info, JAVA_OP_GOTO, &label1);
			JavaGenLabel(info, &label2);
			PopLoop(info);
		}
	}
	else if(IsEmpty(node->stmt))
	{
		/* The loop body is empty, so loop on the condition's side-effects */
		JavaGenLabel(info, &label1);
		JavaGenThen(node->cond, info, &label1);
	}
	else
	{
		/* Generate the full case of the "while" loop */
		PushLoop(info, &label2, &label3, node->name, 0);
		JavaGenJump(info, JAVA_OP_GOTO, &label2);
		JavaGenLabel(info, &label1);
		JavaGenDiscard(node->stmt, info);
		JavaGenLabel(info, &label2);
		JavaGenThen(node->cond, info, &label1);
		JavaGenLabel(info, &label3);
		PopLoop(info);
	}
}
#line 3444 "cg_stmt.c"

struct ILNode_While_vtable__ const ILNode_While_vt__ = {
	&ILNode_LabelledStatement_vt__,
	ILNode_While_kind,
	"ILNode_While",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_While_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_While_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_While_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Do_ILNode_GenDiscard__(ILNode_Do *node, ILGenInfo * info)
#line 648 "cg_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;

	if(ILNode_EvalConst(node->cond, info, &value) &&
	   ILGenCastConst(info, &value, value.valueType, ILMachineType_Boolean))
	{
		/* The condition is constant */
		if(value.un.i4Value)
		{
			/* Generate code for an infinite loop */
			PushLoop(info, &label1, &label2, node->name, 0);
			ILGenLabel(info, &label1);
			if(node->stmt)
			{
				ILNode_GenDiscard(node->stmt, info);
			}
			ILGenJump(info, IL_OP_BR, &label1);
			ILGenLabel(info, &label2);
			PopLoop(info);
		}
		else
		{
			/* Generate code for a single execution of the loop body */
			PushLoop(info, &label1, &label1, node->name, 0);
			ILNode_GenDiscard(node->stmt, info);
			ILGenLabel(info, &label1);
			PopLoop(info);
		}
	}
	else if(IsEmpty(node->stmt))
	{
		/* The loop body is empty, so loop on the condition's side-effects */
		ILGenLabel(info, &label1);
		ILNode_GenThen(node->cond, info, &label1);
	}
	else
	{
		/* Generate the full case of the "do" loop */
		PushLoop(info, &label2, &label3, node->name, 0);
		ILGenLabel(info, &label1);
		ILNode_GenDiscard(node->stmt, info);
		ILGenLabel(info, &label2);
		ILNode_GenThen(node->cond, info, &label1);
		ILGenLabel(info, &label3);
		PopLoop(info);
	}
}
#line 3515 "cg_stmt.c"

int ILNode_Do_ILNode_EndsInReturnImpl__(ILNode_Do *node, ILGenInfo * info)
#line 610 "cg_stmt.tc"
{
	int flags;
	ILEvalValue evalue;
	if(!(node->cond) || 
		( ILNode_EvalConst(node->cond,info,&evalue) &&
		  (evalue.valueType == ILMachineType_Boolean) &&
		  (evalue.un.i4Value == 1) /* true */
		))
	{
		/* This may be an infinite loop: check for a contained "break" */
		if(node->stmt)
		{
			flags = ILNode_EndsInReturnImpl(node->stmt,info);
			if((flags & IL_ENDS_IN_CONTAINED_BREAK) != 0)
			{
				return 0;
			}
			else
			{
				return IL_ENDS_IN_RETURN;
			}
		}
		else
		{
			return IL_ENDS_IN_RETURN;
		}
	}
	else
	{
		/* This loop will probably exit at some point */
		return 0;
	}
}
#line 3552 "cg_stmt.c"

void ILNode_Do_JavaGenDiscard__(ILNode_Do *node, ILGenInfo * info)
#line 155 "jv_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;

	if(ILNode_EvalConst(node->cond, info, &value) &&
	   ILGenCastConst(info, &value, value.valueType, ILMachineType_Boolean))
	{
		/* The condition is constant */
		if(value.un.i4Value)
		{
			/* Generate code for an infinite loop */
			PushLoop(info, &label1, &label2, node->name, 0);
			JavaGenLabel(info, &label1);
			if(node->stmt)
			{
				JavaGenDiscard(node->stmt, info);
			}
			JavaGenJump(info, JAVA_OP_GOTO, &label1);
			JavaGenLabel(info, &label2);
			PopLoop(info);
		}
		else
		{
			/* Generate code for a single execution of the loop body */
			PushLoop(info, &label1, &label1, node->name, 0);
			JavaGenDiscard(node->stmt, info);
			JavaGenLabel(info, &label1);
			PopLoop(info);
		}
	}
	else if(IsEmpty(node->stmt))
	{
		/* The loop body is empty, so loop on the condition's side-effects */
		JavaGenLabel(info, &label1);
		JavaGenThen(node->cond, info, &label1);
	}
	else
	{
		/* Generate the full case of the "do" loop */
		PushLoop(info, &label2, &label3, node->name, 0);
		JavaGenLabel(info, &label1);
		JavaGenDiscard(node->stmt, info);
		JavaGenLabel(info, &label2);
		JavaGenThen(node->cond, info, &label1);
		JavaGenLabel(info, &label3);
		PopLoop(info);
	}
}
#line 3606 "cg_stmt.c"

struct ILNode_Do_vtable__ const ILNode_Do_vt__ = {
	&ILNode_LabelledStatement_vt__,
	ILNode_Do_kind,
	"ILNode_Do",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Do_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Do_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Do_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_For_ILNode_GenDiscard__(ILNode_For *node, ILGenInfo * info)
#line 703 "cg_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;
	int isConst;

	/* Generate the initialisation code */
	if(node->init)
	{
		ILNode_GenDiscard(node->init, info);
	}

	/* Evaluate the condition */
	if(node->cond)
	{
		isConst = (ILNode_EvalConst(node->cond, info, &value) &&
	   			   ILGenCastConst(info, &value, value.valueType,
				   				  ILMachineType_Boolean));
	}
	else
	{
		value.un.i4Value = 1;
		isConst = 1;
	}

	/* Generate the main part of the loop */
	if(isConst)
	{
		/* The condition is constant */
		if(value.un.i4Value)
		{
			/* Generate code for an infinite loop */
			PushLoop(info, &label2, &label3, node->name, 0);
			ILGenLabel(info, &label1);
			if(node->stmt)
			{
				ILNode_GenDiscard(node->stmt, info);
			}
			ILGenLabel(info, &label2);
			if(node->incr)
			{
				ILNode_GenDiscard(node->incr, info);
			}
			ILGenJump(info, IL_OP_BR, &label1);
			ILGenLabel(info, &label3);
			PopLoop(info);
		}
	}
	else if(IsEmpty(node->stmt) && !(node->incr))
	{
		/* The loop body and increment expressions are empty,
		   so loop on the condition's side-effects */
		ILGenLabel(info, &label1);
		ILNode_GenThen(node->cond, info, &label1);
	}
	else
	{
		/* Generate the full case of the "for" loop */
		PushLoop(info, &label2, &label4, node->name, 0);
		ILGenJump(info, IL_OP_BR, &label3);
		ILGenLabel(info, &label1);
		if(node->stmt)
		{
			ILNode_GenDiscard(node->stmt, info);
		}
		ILGenLabel(info, &label2);
		if(node->incr)
		{
			ILNode_GenDiscard(node->incr, info);
		}
		ILGenLabel(info, &label3);
		ILNode_GenThen(node->cond, info, &label1);
		ILGenLabel(info, &label4);
		PopLoop(info);
	}
}
#line 3705 "cg_stmt.c"

int ILNode_For_ILNode_EndsInReturnImpl__(ILNode_For *node, ILGenInfo * info)
#line 610 "cg_stmt.tc"
{
	int flags;
	ILEvalValue evalue;
	if(!(node->cond) || 
		( ILNode_EvalConst(node->cond,info,&evalue) &&
		  (evalue.valueType == ILMachineType_Boolean) &&
		  (evalue.un.i4Value == 1) /* true */
		))
	{
		/* This may be an infinite loop: check for a contained "break" */
		if(node->stmt)
		{
			flags = ILNode_EndsInReturnImpl(node->stmt,info);
			if((flags & IL_ENDS_IN_CONTAINED_BREAK) != 0)
			{
				return 0;
			}
			else
			{
				return IL_ENDS_IN_RETURN;
			}
		}
		else
		{
			return IL_ENDS_IN_RETURN;
		}
	}
	else
	{
		/* This loop will probably exit at some point */
		return 0;
	}
}
#line 3742 "cg_stmt.c"

void ILNode_For_JavaGenDiscard__(ILNode_For *node, ILGenInfo * info)
#line 210 "jv_stmt.tc"
{
	ILEvalValue value;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;
	int isConst;

	/* Generate the initialisation code */
	if(node->init)
	{
		JavaGenDiscard(node->init, info);
	}

	/* Evaluate the condition */
	if(node->cond)
	{
		isConst = (ILNode_EvalConst(node->cond, info, &value) &&
	   			   ILGenCastConst(info, &value, value.valueType,
				   				  ILMachineType_Boolean));
	}
	else
	{
		value.un.i4Value = 1;
		isConst = 1;
	}

	/* Generate the main part of the loop */
	if(isConst)
	{
		/* The condition is constant */
		if(value.un.i4Value)
		{
			/* Generate code for an infinite loop */
			PushLoop(info, &label2, &label3, node->name, 0);
			JavaGenLabel(info, &label1);
			if(node->stmt)
			{
				JavaGenDiscard(node->stmt, info);
			}
			JavaGenLabel(info, &label2);
			if(node->incr)
			{
				JavaGenDiscard(node->incr, info);
			}
			JavaGenJump(info, JAVA_OP_GOTO, &label1);
			JavaGenLabel(info, &label3);
			PopLoop(info);
		}
	}
	else if(IsEmpty(node->stmt) && !(node->incr))
	{
		/* The loop body and increment expressions are empty,
		   so loop on the condition's side-effects */
		JavaGenLabel(info, &label1);
		JavaGenThen(node->cond, info, &label1);
	}
	else
	{
		/* Generate the full case of the "for" loop */
		PushLoop(info, &label2, &label4, node->name, 0);
		JavaGenJump(info, JAVA_OP_GOTO, &label3);
		JavaGenLabel(info, &label1);
		if(node->stmt)
		{
			JavaGenDiscard(node->stmt, info);
		}
		JavaGenLabel(info, &label2);
		if(node->incr)
		{
			JavaGenDiscard(node->incr, info);
		}
		JavaGenLabel(info, &label3);
		JavaGenThen(node->cond, info, &label1);
		JavaGenLabel(info, &label4);
		PopLoop(info);
	}
}
#line 3824 "cg_stmt.c"

struct ILNode_For_vtable__ const ILNode_For_vt__ = {
	&ILNode_LabelledStatement_vt__,
	ILNode_For_kind,
	"ILNode_For",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_For_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_For_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_For_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Foreach_ILNode_GenDiscard__(ILNode_Foreach *node, ILGenInfo * info)
#line 786 "cg_stmt.tc"
{
	unsigned arrayVar;
	unsigned indexVar;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;
	ILMachineType elemType;

	/* We need a temporary variable for the evaluated array */
	arrayVar = ILGenTempTypedVar(info, node->arrayType);

	/* We need a temporary variable for the array index */
	indexVar = ILGenTempTypedVar(info, ILType_Int32);

	/* Evaluate the array expression */
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_ObjectRef);
	ILGenStoreLocal(info, arrayVar);
	ILGenAdjust(info, -1);

	/* Initialize the index expression */
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenStoreLocal(info, indexVar);
	ILGenExtend(info, 1);

	/* Jump to the end of the loop to perform the test */
	ILGenJump(info, IL_OP_BR, &label3);

	/* Push the loop label information */
	PushLoop(info, &label2, &label4, node->name, 0);

	/* Fetch the next array element and put it into the variable */
	ILGenLabel(info, &label1);
	ILGenLoadLocal(info, arrayVar);
	ILGenLoadLocal(info, indexVar);
	ILGenAdjust(info, 2);
	elemType = ILTypeToMachineType(node->elemType);
	ILGenLoadArray(info, elemType, node->elemType);
	ILGenAdjust(info, -1);
	ILGenCast(info, elemType, node->varType);
	if(node->doCast)
	{
		ILGenCast(info, ILNode_GenValue(node->doCast, info), node->varType);
	}
	ILGenStoreLocal(info, node->varIndex);
	ILGenAdjust(info, -1);

	/* Output the loop body */
	ILNode_GenDiscard(node->stmt, info);

	/* Increment the array index */
	ILGenLabel(info, &label2);
	ILGenLoadLocal(info, indexVar);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_ADD);
	ILGenStoreLocal(info, indexVar);
	ILGenExtend(info, 2);

	/* Test the array index condition */
	ILGenLabel(info, &label3);
	ILGenLoadLocal(info, indexVar);
	ILGenAdjust(info, 1);
	ILGenLoadLocal(info, arrayVar);
	ILGenAdjust(info, 1);
	ILGenSimple(info, IL_OP_LDLEN);
	ILGenSimple(info, IL_OP_CONV_I4);
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenAdjust(info, -2);

	/* Mark the end of the loop */
	ILGenLabel(info, &label4);

	/* Pop the loop label information */
	PopLoop(info);

	/* Release the temporary variables */
	ILGenReleaseTempVar(info, arrayVar);
	ILGenReleaseTempVar(info, indexVar);
}
#line 3925 "cg_stmt.c"

void ILNode_Foreach_JavaGenDiscard__(ILNode_Foreach *node, ILGenInfo * info)
#line 293 "jv_stmt.tc"
{
	unsigned arrayVar;
	unsigned indexVar;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;
	ILMachineType elemType;

	/* We need a temporary variable for the evaluated array */
	arrayVar = ILGenTempTypedVar(info, node->arrayType);

	/* We need a temporary variable for the array index */
	indexVar = ILGenTempTypedVar(info, ILType_Int32);

	/* Evaluate the array expression */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);
	JavaGenStoreLocal(info, arrayVar, ILMachineType_ObjectRef);
	JavaGenAdjust(info, -1);

	/* Initialize the index expression */
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenStoreLocal(info, indexVar, ILMachineType_Int32);
	JavaGenExtend(info, 1);

	/* Jump to the end of the loop to perform the test */
	JavaGenJump(info, JAVA_OP_GOTO, &label3);

	/* Push the loop label information */
	PushLoop(info, &label2, &label4, node->name, 0);

	/* Fetch the next array element and put it into the variable */
	JavaGenLabel(info, &label1);
	JavaGenLoadLocal(info, arrayVar, ILMachineType_ObjectRef);
	JavaGenLoadLocal(info, indexVar, ILMachineType_Int32);
	JavaGenAdjust(info, 2);
	elemType = ILTypeToMachineType(node->elemType);
	JavaGenLoadArray(info, elemType);
	JavaGenAdjust(info, (-2 + JavaGenTypeSize(elemType)));
	JavaGenCast(info, elemType, node->varType);
	JavaGenStoreLocal(info, node->varIndex, node->varType);
	JavaGenAdjust(info, -(JavaGenTypeSize(node->varType)));

	/* Output the loop body */
	JavaGenDiscard(node->stmt, info);

	/* Increment the array index */
	JavaGenLabel(info, &label2);
	JavaGenIncLocal(info, indexVar, 1);

	/* Test the array index condition */
	JavaGenLabel(info, &label3);
	JavaGenLoadLocal(info, indexVar, ILMachineType_Int32);
	JavaGenAdjust(info, 1);
	JavaGenLoadLocal(info, arrayVar, ILMachineType_ObjectRef);
	JavaGenAdjust(info, 1);
	JavaGenSimple(info, JAVA_OP_ARRAYLENGTH);
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenAdjust(info, -2);

	/* Mark the end of the loop */
	JavaGenLabel(info, &label4);

	/* Pop the loop label information */
	PopLoop(info);

	/* Release the temporary variables */
	ILGenReleaseTempVar(info, arrayVar);
	ILGenReleaseTempVar(info, indexVar);
}
#line 4000 "cg_stmt.c"

struct ILNode_Foreach_vtable__ const ILNode_Foreach_vt__ = {
	&ILNode_LabelledStatement_vt__,
	ILNode_Foreach_kind,
	"ILNode_Foreach",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Foreach_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Foreach_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_ForeachString_ILNode_GenDiscard__(ILNode_ForeachString *node, ILGenInfo * info)
#line 871 "cg_stmt.tc"
{
	unsigned stringVar;
	unsigned indexVar;
	unsigned lengthVar;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;

	/* We need a temporary variable for the evaluated string */
	stringVar = ILGenTempVar(info, ILMachineType_String);

	/* We need a temporary variable for the array index */
	indexVar = ILGenTempTypedVar(info, ILType_Int32);

	/* We need a temporary variable for the string length */
	lengthVar = ILGenTempTypedVar(info, ILType_Int32);

	/* Evaluate the string expression */
	ILGenCast(info, ILNode_GenValue(node->expr, info),
			  ILMachineType_String);
	ILGenSimple(info, IL_OP_DUP);
	ILGenAdjust(info, 1);
	ILGenStoreLocal(info, stringVar);
	ILGenAdjust(info, -1);

	/* Compute the string length and store it for later */
	ILGenCallVirtual(info, "int32 [.library]System.String::get_Length()");
	ILGenStoreLocal(info, lengthVar);
	ILGenAdjust(info, -1);

	/* Initialize the index expression */
	ILGenSimple(info, IL_OP_LDC_I4_0);
	ILGenStoreLocal(info, indexVar);
	ILGenExtend(info, 1);

	/* Jump to the end of the loop to perform the test */
	ILGenJump(info, IL_OP_BR, &label3);

	/* Push the loop label information */
	PushLoop(info, &label2, &label4, node->name, 0);

	/* Fetch the next string element and put it into the variable */
	ILGenLabel(info, &label1);
	ILGenLoadLocal(info, stringVar);
	ILGenLoadLocal(info, indexVar);
	ILGenAdjust(info, 2);
	ILGenCallVirtual(info, "char [.library]System.String::get_Chars(int32)");
	ILGenAdjust(info, -1);
	ILGenCast(info, ILMachineType_Char, node->varType);
	ILGenStoreLocal(info, node->varIndex);
	ILGenAdjust(info, -1);

	/* Output the loop body */
	ILNode_GenDiscard(node->stmt, info);

	/* Increment the array index */
	ILGenLabel(info, &label2);
	ILGenLoadLocal(info, indexVar);
	ILGenSimple(info, IL_OP_LDC_I4_1);
	ILGenSimple(info, IL_OP_ADD);
	ILGenStoreLocal(info, indexVar);
	ILGenExtend(info, 2);

	/* Test the string index condition */
	ILGenLabel(info, &label3);
	ILGenLoadLocal(info, indexVar);
	ILGenAdjust(info, 1);
	ILGenLoadLocal(info, lengthVar);
	ILGenAdjust(info, 1);
	ILGenJump(info, IL_OP_BLT, &label1);
	ILGenAdjust(info, -2);

	/* Mark the end of the loop */
	ILGenLabel(info, &label4);

	/* Pop the loop label information */
	PopLoop(info);

	/* Release the temporary variables */
	ILGenReleaseTempVar(info, stringVar);
	ILGenReleaseTempVar(info, indexVar);
	ILGenReleaseTempVar(info, lengthVar);
}
#line 4105 "cg_stmt.c"

void ILNode_ForeachString_JavaGenDiscard__(ILNode_ForeachString *node, ILGenInfo * info)
#line 369 "jv_stmt.tc"
{
	unsigned stringVar;
	unsigned indexVar;
	unsigned lengthVar;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;

	/* We need a temporary variable for the evaluated string */
	stringVar = ILGenTempVar(info, ILMachineType_String);

	/* We need a temporary variable for the string index */
	indexVar = ILGenTempTypedVar(info, ILType_Int32);

	/* We need a temporary variable for the string length */
	lengthVar = ILGenTempTypedVar(info, ILType_Int32);

	/* Evaluate the string expression */
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_String);
	JavaGenSimple(info, JAVA_OP_DUP);
	JavaGenAdjust(info, 1);
	JavaGenStoreLocal(info, stringVar, ILMachineType_String);
	JavaGenAdjust(info, -1);

	/* Evaluate the string length */
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "length", "()I");
	}
	else
	{
		JavaGenCallVirtual(info, "System/String", "get_Length", "()I");
	}
	JavaGenStoreLocal(info, lengthVar, ILMachineType_Int32);
	JavaGenAdjust(info, -1);

	/* Initialize the index expression */
	JavaGenSimple(info, JAVA_OP_ICONST_0);
	JavaGenStoreLocal(info, indexVar, ILMachineType_Int32);
	JavaGenExtend(info, 1);

	/* Jump to the end of the loop to perform the test */
	JavaGenJump(info, JAVA_OP_GOTO, &label3);

	/* Push the loop label information */
	PushLoop(info, &label2, &label4, node->name, 0);

	/* Fetch the next array element and put it into the variable */
	JavaGenLabel(info, &label1);
	JavaGenLoadLocal(info, stringVar, ILMachineType_ObjectRef);
	JavaGenLoadLocal(info, indexVar, ILMachineType_Int32);
	JavaGenAdjust(info, 2);
	if(info->useJavaLib)
	{
		JavaGenCallVirtual(info, "java/lang/String", "charAt", "(I)C");
	}
	else
	{
		JavaGenCallVirtual(info, "System/String", "get_Chars", "(I)C");
	}
	JavaGenCast(info, ILMachineType_Char, node->varType);
	JavaGenStoreLocal(info, node->varIndex, node->varType);
	JavaGenAdjust(info, -(JavaGenTypeSize(node->varType)));

	/* Output the loop body */
	JavaGenDiscard(node->stmt, info);

	/* Increment the string index */
	JavaGenLabel(info, &label2);
	JavaGenIncLocal(info, indexVar, 1);

	/* Test the array index condition */
	JavaGenLabel(info, &label3);
	JavaGenLoadLocal(info, indexVar, ILMachineType_Int32);
	JavaGenAdjust(info, 1);
	JavaGenLoadLocal(info, lengthVar, ILMachineType_Int32);
	JavaGenAdjust(info, 1);
	JavaGenJump(info, JAVA_OP_IF_ICMPLT, &label1);
	JavaGenAdjust(info, -2);

	/* Mark the end of the loop */
	JavaGenLabel(info, &label4);

	/* Pop the loop label information */
	PopLoop(info);

	/* Release the temporary variables */
	ILGenReleaseTempVar(info, stringVar);
	ILGenReleaseTempVar(info, indexVar);
	ILGenReleaseTempVar(info, lengthVar);
}
#line 4202 "cg_stmt.c"

struct ILNode_ForeachString_vtable__ const ILNode_ForeachString_vt__ = {
	&ILNode_LabelledStatement_vt__,
	ILNode_ForeachString_kind,
	"ILNode_ForeachString",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ForeachString_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ForeachString_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_ForeachCollection_ILNode_GenDiscard__(ILNode_ForeachCollection *node, ILGenInfo * info)
#line 968 "cg_stmt.tc"
{
	unsigned enumVar;
	unsigned disposeVar;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;
	ILLabel label5 = ILLabel_Undefined;

	/* We need a temporary variable for the collection enumerator */
	enumVar = ILGenTempTypedVar(info, node->enumeratorType);

	/* We need a temporary variable for the enumerator as IDisposable */
	disposeVar = ILGenTempTypedVar(info, ILFindSystemType(info, "IDisposable"));

	/* Evaluate the collection expression and get the enumerator */

	ILGenPrepareForThisAccess(info,node->expr,ILTypeToClass(info,
								node->arrayType),1);

	if(ILMethod_IsVirtual(node->getEnumerator))
	{
		ILGenCallVirtByMethod(info, node->getEnumerator);
	}
	else
	{
		ILGenCallByMethod(info, node->getEnumerator);
	}
	ILGenStoreLocal(info, enumVar);
	ILGenAdjust(info, -1);

	/* Encapsulate the loop in a "try" block so that the "Dispose"
	   method can be called on disposeable enumerators */
	if(info->asmOutput)
	{
		fputs("\t.try {\n", info->asmOutput);
	}
	PushFinally(info, 0);

	/* Jump to the end of the loop to perform the test */
	ILGenJump(info, IL_OP_BR, &label2);

	/* Push the loop label information */
	PushLoop(info, &label2, &label5, node->name, 1);
	ILGenLabel(info, &label1);

	/* Fetch the next collection element and put it into the variable */
	ILGenLoadLocal(info, enumVar);
	ILGenAdjust(info, 1);
	if(ILMethod_IsVirtual(node->getCurrent))
	{
		ILGenCallVirtByMethod(info, node->getCurrent);
	}
	else
	{
		ILGenCallByMethod(info, node->getCurrent);
	}
	if(node->doCast)
	{
		ILGenCast(info, ILNode_GenValue(node->doCast, info), node->varType);
	}
	ILGenStoreLocal(info, node->varIndex);
	ILGenAdjust(info, -1);

	/* Output the loop body */
	ILNode_GenDiscard(node->stmt, info);

	/* Move on to the next enumerator element */
	ILGenLabel(info, &label2);
	ILGenLoadLocal(info, enumVar);
	ILGenAdjust(info, 1);
	if(ILMethod_IsVirtual(node->moveNext))
	{
		ILGenCallVirtByMethod(info, node->moveNext);
	}
	else
	{
		ILGenCallByMethod(info, node->moveNext);
	}
	ILGenJump(info, IL_OP_BRTRUE, &label1);

	/* Mark the end of the loop */
	ILGenLabel(info, &label3);
	ILGenJump(info, IL_OP_LEAVE, &label5);

	/* Pop the loop label information */
	PopLoop(info);

	/* Output the "finally" clause for disposing the enumerator */
	if(info->asmOutput)
	{
		fputs("\t}\n\tfinally {\n", info->asmOutput);
	}
	ILGenLoadLocal(info, enumVar);
	ILGenAdjust(info, 1);
	ILGenClassName(info, IL_OP_ISINST, "[.library]System.IDisposable");
	ILGenStoreLocal(info, disposeVar);
	ILGenLoadLocal(info, disposeVar);
	ILGenJump(info, IL_OP_BRFALSE, &label4);
	ILGenAdjust(info, -1);
	ILGenLoadLocal(info, disposeVar);
	ILGenAdjust(info, 1);
	ILGenCallVirtual(info, "void [.library]System.IDisposable::Dispose()");
	ILGenAdjust(info, -1);
	ILGenLabel(info, &label4);
	ILGenSimple(info, IL_OP_ENDFINALLY);
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}
	ILGenLabel(info, &label5);
	PopLoop(info);

	/* Release the temporary variables */
	ILGenReleaseTempVar(info, enumVar);
	ILGenReleaseTempVar(info, disposeVar);
}
#line 4340 "cg_stmt.c"

void ILNode_ForeachCollection_JavaGenDiscard__(ILNode_ForeachCollection *node, ILGenInfo * info)
#line 475 "jv_stmt.tc"
{
	unsigned enumVar;
	unsigned catchVar;
	unsigned addrVar;
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;
	ILLabel label5 = ILLabel_Undefined;
	ILLabel finallyLabel = ILLabel_Undefined;
	long saveStack;
	ILMachineType enumType;
	ILType *returnType;

	/* We need a temporary variable for the collection enumerator */
	enumVar = ILGenTempTypedVar(info, node->enumeratorType);
	enumType = ILTypeToMachineType(node->enumeratorType);

	/* We need a temporary variable to hold the default catch value */
	catchVar = ILGenTempVar(info, ILMachineType_ObjectRef);

	/* We need a temporary variable to hold the "finally" return address */
	addrVar = ILGenTempVar(info, ILMachineType_ObjectRef);

	/* Evaluate the collection expression and get the enumerator */
	saveStack = info->stackHeight;
	JavaGenCast(info, JavaGenValue(node->expr, info),
			    ILMachineType_ObjectRef);
	JavaGenCallMethod(info, node->getEnumerator, saveStack);
	ILGenAdjust(info, (JavaGenTypeSize(enumType) - 1));
	JavaGenStoreLocal(info, enumVar, enumType);
	ILGenAdjust(info, -(JavaGenTypeSize(enumType)));

	/* Encapsulate the loop in a "try" block so that the "Dispose"
	   method can be called on disposeable enumerators */
	if(info->asmOutput)
	{
		fputs("\t.try {\n", info->asmOutput);
	}
	PushFinally(info, &finallyLabel);

	/* Jump to the end of the loop to perform the test */
	JavaGenJump(info, JAVA_OP_GOTO, &label2);

	/* Push the loop label information */
	PushLoop(info, &label2, &label3, node->name, 1);

	/* Fetch the next collection element and put it into the variable */
	saveStack = info->stackHeight;
	JavaGenLoadLocal(info, enumVar, enumType);
	JavaGenAdjust(info, JavaGenTypeSize(enumType));
	JavaGenCallMethod(info, node->getCurrent, saveStack);
	JavaGenAdjust(info, -(JavaGenTypeSize(enumType)));
	returnType = ILTypeGetReturn(ILMethod_Signature(node->getCurrent));
	JavaGenAdjust(info, JavaGenTypeSize(ILTypeToMachineType(returnType)));
	if(node->doCast)
	{
		JavaGenCast(info, JavaGenValue(node->doCast, info), node->varType);
	}
	JavaGenStoreLocal(info, node->varIndex, node->varType);
	JavaGenAdjust(info, -(JavaGenTypeSize(node->varType)));

	/* Output the loop body */
	JavaGenDiscard(node->stmt, info);

	/* Move on to the next enumerator element */
	JavaGenLabel(info, &label2);
	saveStack = info->stackHeight;
	JavaGenLoadLocal(info, enumVar, enumType);
	JavaGenAdjust(info, JavaGenTypeSize(enumType));
	JavaGenCallMethod(info, node->moveNext, saveStack);
	JavaGenAdjust(info, -(JavaGenTypeSize(enumType)));
	JavaGenAdjust(info, 1);
	JavaGenJump(info, JAVA_OP_IFNE, &label1);
	JavaGenAdjust(info, -1);

	/* Mark the end of the loop */
	JavaGenLabel(info, &label3);

	/* Call the "finally" clause and then jump past it */
	JavaGenJump(info, JAVA_OP_JSR, &finallyLabel);
	JavaGenJump(info, JAVA_OP_GOTO, &label4);

	/* Pop the loop label information */
	PopLoop(info);

	/* Output the default "catch" clause to catch all exceptions */
	if(info->asmOutput)
	{
		fputs("\t}\n\tcatch {\n", info->asmOutput);
	}
	JavaGenAdjust(info, 1);
	JavaGenStoreLocal(info, catchVar, ILMachineType_ObjectRef);
	JavaGenAdjust(info, -1);
	JavaGenJump(info, JAVA_OP_JSR, &finallyLabel);
	JavaGenLoadLocal(info, catchVar, ILMachineType_ObjectRef);
	JavaGenAdjust(info, 1);
	JavaGenSimple(info, JAVA_OP_ATHROW);
	JavaGenAdjust(info, -1);

	/* Output the "finally" clause for disposing the enumerator */
	if(info->asmOutput)
	{
		fputs("\t}\n\tfinally {\n", info->asmOutput);
	}
	JavaGenAdjust(info, 1);
	JavaGenStoreLocal(info, addrVar, ILMachineType_ObjectRef);
	JavaGenAdjust(info, -1);
	JavaGenLoadLocal(info, enumVar, enumType);
	JavaGenAdjust(info, JavaGenTypeSize(enumType));
	JavaGenClassName(info, JAVA_OP_INSTANCEOF, "System/IDisposable");
	JavaGenAdjust(info, -(JavaGenTypeSize(enumType) - 1));
	JavaGenJump(info, JAVA_OP_IFEQ, &label5);
	JavaGenAdjust(info, -1);
	saveStack = info->stackHeight;
	JavaGenLoadLocal(info, enumVar, enumType);
	JavaGenAdjust(info, JavaGenTypeSize(enumType));
	JavaGenClassName(info, JAVA_OP_CHECKCAST, "System/IDisposable");
	JavaGenAdjust(info, -(JavaGenTypeSize(enumType) - 1));
	JavaGenCallInterface(info, "System/IDisposable", "Dispose", "()V",
						 info->stackHeight - saveStack);
	JavaGenAdjust(info, -1);
	JavaGenLabel(info, &label5);
	JavaGenRet(info, addrVar);
	if(info->asmOutput)
	{
		fputs("\t}\n", info->asmOutput);
	}
	JavaGenLabel(info, &label4);
	PopLoop(info);

	/* Release the temporary variables (but not "catchVar" and "addrVar"
	   because of variable reuse issues - see "try" codegen for details) */
	ILGenReleaseTempVar(info, enumVar);
}
#line 4479 "cg_stmt.c"

struct ILNode_ForeachCollection_vtable__ const ILNode_ForeachCollection_vt__ = {
	&ILNode_LabelledStatement_vt__,
	ILNode_ForeachCollection_kind,
	"ILNode_ForeachCollection",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ForeachCollection_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ForeachCollection_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Switch_ILNode_GenDiscard__(ILNode_Switch *node, ILGenInfo * info)
#line 1896 "cg_stmt.tc"
{
	ILLabel breakLabel = ILLabel_Undefined;
	ILLabel defaultLabelValue = ILLabel_Undefined;
	ILLabel *defaultLabel;
	ILNode_ListIter iter;
	ILNode_SwitchSection *section;
	ILSwitchValue *values;
	unsigned long numValues;
	ILInt32 temp;
	int needPop = 0;
	int savePop;
	ILNode *saveSwitch;
	unsigned tempVar = ~((unsigned)0);

	/* Compute the switch expression's value */
	ILNode_GenValue(node->expr, info);

	/* Determine the location of the default label */
	if(node->defaultSection)
	{
		defaultLabel =
			&(((ILNode_SwitchSection *)(node->defaultSection))->label);
	}
	else
	{
		defaultLabel = &defaultLabelValue;
	}

	/* Push the switch context information for "break" statements */
	PushLoop(info, (ILLabel *)0, &breakLabel, node->name, 0);

	/* Get the value table */
	values = node->switchValues;
	numValues = node->numSwitchValues;

	/* Determine how to generate the switch table */
	if(numValues != 0)
	{
		switch(node->tableType)
		{
			case ILSwitchTableType_If:
			{
				/* Use a simple set of "if" statements */
				if(node->body)
				{
					tempVar = ILGenTempVar(info, values->value.valueType);
					ILGenStoreLocal(info, tempVar);
					ILGenAdjust(info, -1);
				}
				else
				{
					needPop = 1;
				}
				while(numValues > 0)
				{
					if(tempVar == ~((unsigned)0))
					{
						ILGenSimple(info, IL_OP_DUP);
						ILGenAdjust(info, 1);
					}
					else
					{
						ILGenLoadLocal(info, tempVar);
						ILGenAdjust(info, 1);
					}
					section = (ILNode_SwitchSection *)(values->section);
					CompareSwitchValue(info, &(values->value),
									   IL_OP_BEQ, IL_OP_BEQ,
									   &(section->label));
					++values;
					--numValues;
				}
				ILGenJump(info, IL_OP_BR, defaultLabel);
				if(needPop)
				{
					ILGenAdjust(info, -1);
				}
			}
			break;
	
			case ILSwitchTableType_Indexed:
			{
				/* Use an indexed lookup on an "int" value */
				if(values[0].value.un.i4Value != 0)
				{
					/* Subtract the base value from the expression */
					ILGenInt32(info, values[0].value.un.i4Value);
					ILGenSimple(info, IL_OP_SUB);
					ILGenExtend(info, 1);
				}
				ILGenSwitchStart(info);
				while(numValues > 1)
				{
					section = (ILNode_SwitchSection *)(values->section);
					ILGenSwitchRef(info, &(section->label), 1);
					temp = values->value.un.i4Value + 1;
					while(temp != values[1].value.un.i4Value)
					{
						ILGenSwitchRef(info, defaultLabel, 1);
						++temp;
					}
					++values;
					--numValues;
				}
				section = (ILNode_SwitchSection *)(values->section);
				ILGenSwitchRef(info, &(section->label), 0);
				ILGenSwitchEnd(info);
				ILGenJump(info, IL_OP_BR, defaultLabel);
				ILGenAdjust(info, -1);
			}
			break;
	
			case ILSwitchTableType_BinaryIf:
			case ILSwitchTableType_Lookup:
			{
				/* Use a binary tree of "if" statements */
				if(node->body)
				{
					tempVar = ILGenTempVar(info, values->value.valueType);
					ILGenStoreLocal(info, tempVar);
					ILGenAdjust(info, -1);
				}
				else
				{
					needPop = 1;
				}
				GenerateBinarySwitch(info, values, numValues,
									 defaultLabel, tempVar);
				ILGenAdjust(info, -1);
			}
			break;
		}
	}
	else
	{
		/* There are no cases, except the default, so pop
		   the switch value and fall through to the default */
		ILGenSimple(info, IL_OP_POP);
		ILGenAdjust(info, -1);
	}

	/* Generate code for the switch sections */
	savePop = info->needSwitchPop;
	info->needSwitchPop = needPop;
	saveSwitch=info->currentSwitch;
	info->currentSwitch=(ILNode*)node;

	if(node->body)
	{
		/* C-style switch: output the code for the entire body */
		ILNode_GenDiscard(node->body, info);
	}
	else
	{
		/* C#-style switch: output the code section by section */
		ILNode_ListIter_Init(&iter, node->sections);
		while((section = (ILNode_SwitchSection *)ILNode_ListIter_Next(&iter))
					!= 0)
		{
			/* Output the section label */
			ILGenLabel(info, &(section->label));
	
			/* Pop the extra value copy if we were using "if" statements */
			if(needPop)
			{
				ILGenSimple(info, IL_OP_POP);
			}
	
			/* Output the code for the section */
			ILNode_GenDiscard(section->stmt, info);
		}
	}
	info->needSwitchPop = savePop;
	info->currentSwitch = saveSwitch;

	/* Pop from the switch context and set the default and break labels */
	PopLoop(info);
	if(!(node->defaultSection))
	{
		ILGenLabel(info, defaultLabel);
		if(needPop)
		{
			ILGenSimple(info, IL_OP_POP);
		}
	}
	ILGenLabel(info, &breakLabel);

	/* Free the temporary switch variable */
	if(tempVar != ~((unsigned)0))
	{
		ILGenReleaseTempVar(info, tempVar);
	}
}
#line 4693 "cg_stmt.c"

int ILNode_Switch_ILNode_EndsInReturnImpl__(ILNode_Switch *node, ILGenInfo * info)
#line 2094 "cg_stmt.tc"
{
	int flags, sflags;
	ILNode_ListIter iter;
	ILNode_SwitchSection *section;

	/* Check that all switch cases end in return statements */
	if(node->body)
	{
		flags = ILNode_EndsInReturnImpl(node->body,info);
	}
	else
	{
		flags = IL_ENDS_IN_EMPTY;
		ILNode_ListIter_Init(&iter, node->sections);
		while((section = (ILNode_SwitchSection *)
					ILNode_ListIter_Next(&iter)) != 0)
		{
			if(section->stmt)
			{
				sflags = ILNode_EndsInReturnImpl(section->stmt,info);
			}
			else
			{
				sflags = IL_ENDS_IN_EMPTY;
			}
			if((flags & IL_ENDS_IN_EMPTY) != 0)
			{
				flags = sflags;
			}
			else if((sflags & (IL_ENDS_IN_RETURN |
							   IL_ENDS_IN_BREAK |
							   IL_ENDS_IN_CONTINUE |
							   IL_ENDS_IN_GOTO |
							   IL_ENDS_IN_THROW)) != 0)
			{
				if((flags & (IL_ENDS_IN_RETURN |
							 IL_ENDS_IN_BREAK |
							 IL_ENDS_IN_CONTINUE |
							 IL_ENDS_IN_GOTO |
							 IL_ENDS_IN_THROW)) != 0)
				{
					flags = IL_ENDS_IN_RETURN |
							((flags | sflags) & IL_ENDS_IN_CONTAINED_MASK);
				}
				else
				{
					flags = ((flags | sflags) & IL_ENDS_IN_CONTAINED_MASK);
				}
			}
			else
			{
				flags = ((flags | sflags) & IL_ENDS_IN_CONTAINED_MASK);
			}
		}
	}

	/* If there is no default case, then we fall through */
	if(!(node->defaultSection))
	{
		flags &= IL_ENDS_IN_CONTAINED_MASK;
	}

	/* If there is a "break" or "continue", then we fall through */
	if((flags & IL_ENDS_IN_CONTAINED_BREAK) != 0 ||
	   (flags & IL_ENDS_IN_CONTAINED_CONTINUE) != 0)
	{
		flags &= IL_ENDS_IN_CONTAINED_CONTINUE;
	}

	/* Return the final flags to the caller */
	return flags;
}
#line 4769 "cg_stmt.c"

void ILNode_Switch_JavaGenDiscard__(ILNode_Switch *node, ILGenInfo * info)
#line 1209 "jv_stmt.tc"
{
	ILLabel breakLabel = ILLabel_Undefined;
	ILLabel defaultLabelValue = ILLabel_Undefined;
	ILLabel *defaultLabel;
	ILNode_ListIter iter;
	ILNode_SwitchSection *section;
	ILSwitchValue *values;
	unsigned long numValues;
	unsigned long posn;
	ILInt32 temp;
	ILMachineType type;
	int size;
	int needPop = 0;
	int savePop;
	ILNode *saveSwitch;

	/* Compute the switch expression's value */
	type = JavaGenValue(node->expr, info);
	size = JavaGenTypeSize(type);

	/* Determine the location of the default label */
	if(node->defaultSection)
	{
		defaultLabel =
			&(((ILNode_SwitchSection *)(node->defaultSection))->label);
	}
	else
	{
		defaultLabel = &defaultLabelValue;
	}

	/* Push the switch context information for "break" statements */
	PushLoop(info, (ILLabel *)0, &breakLabel, node->name, 0);

	/* Get the value table */
	values = node->switchValues;
	numValues = node->numSwitchValues;

	/* If the type is "string", and we are using the Java library,
	   then we need to handle the "null" case specially.  This is
	   because the Java library will throw exceptions for "null"
	   that we do not desire */
	if(type == ILMachineType_String && info->useJavaLib)
	{
		/* Search for the "null" case, if present */
		for(posn = 0; posn < numValues; ++posn)
		{
			if(values[posn].value.un.strValue.str == 0)
			{
				break;
			}
		}
		if(posn < numValues)
		{
			section = (ILNode_SwitchSection *)(values[posn].section);
			JavaGenSimple(info, JAVA_OP_DUP);
			JavaGenJump(info, JAVA_OP_IFNULL, &(section->label));
			JavaGenExtend(info, 1);
		}
		else
		{
			JavaGenSimple(info, JAVA_OP_DUP);
			JavaGenJump(info, JAVA_OP_IFNULL, defaultLabel);
			JavaGenExtend(info, 1);
		}
	}

	/* Determine how to generate the switch table */
	if(numValues != 0)
	{
		switch(node->tableType)
		{
			case ILSwitchTableType_If:
			{
				/* Use a simple set of "if" statements */
				while(numValues > 0)
				{
					JavaGenDup(info, type);
					section = (ILNode_SwitchSection *)(values->section);
					JavaCompareSwitchValue(info, &(values->value),
									       JAVA_OP_IF_ICMPEQ, JAVA_OP_IFEQ,
									   	   &(section->label));
					++values;
					--numValues;
				}
				JavaGenJump(info, JAVA_OP_GOTO, defaultLabel);
				JavaGenAdjust(info, -size);
				needPop = 1;
			}
			break;
	
			case ILSwitchTableType_Indexed:
			{
				/* Use an indexed lookup on an "int" value */
				JavaGenSwitchStart(info, JAVA_OP_TABLESWITCH, defaultLabel,
								   values[0].value.un.i4Value);
				while(numValues > 1)
				{
					section = (ILNode_SwitchSection *)(values->section);
					JavaGenSwitchRef(info, &(section->label), 1);
					temp = values->value.un.i4Value + 1;
					while(temp != values[1].value.un.i4Value)
					{
						JavaGenSwitchRef(info, defaultLabel, 1);
						++temp;
					}
					++values;
					--numValues;
				}
				section = (ILNode_SwitchSection *)(values->section);
				JavaGenSwitchRef(info, &(section->label), 0);
				JavaGenSwitchEnd(info);
				JavaGenAdjust(info, -size);
			}
			break;
	
			case ILSwitchTableType_Lookup:
			{
				/* Use a tagged lookup on an "int" value */
				JavaGenSwitchStart(info, JAVA_OP_LOOKUPSWITCH, defaultLabel, 0);
				while(numValues > 1)
				{
					section = (ILNode_SwitchSection *)(values->section);
					JavaGenSwitchLookupRef
						(info, values->value.un.i4Value, &(section->label), 1);
					++values;
					--numValues;
				}
				section = (ILNode_SwitchSection *)(values->section);
				JavaGenSwitchLookupRef
					(info, values->value.un.i4Value, &(section->label), 0);
				JavaGenSwitchEnd(info);
				JavaGenAdjust(info, -size);
			}
			break;

			case ILSwitchTableType_BinaryIf:
			{
				/* Use a binary tree of "if" statements */
				JavaGenerateBinarySwitch(info, values, numValues,
										 defaultLabel, type);
				JavaGenAdjust(info, -size);
				needPop = 1;
			}
			break;
		}
	}
	else
	{
		/* There are no cases, except the default, so pop
		   the switch value and fall through to the default */
		if(size == 1)
		{
			JavaGenSimple(info, JAVA_OP_POP);
		}
		else if(size == 2)
		{
			JavaGenSimple(info, JAVA_OP_POP2);
		}
		JavaGenAdjust(info, -size);
	}

	/* Generate code for the switch sections */
	savePop = info->needSwitchPop;
	info->needSwitchPop = needPop;
	saveSwitch=info->currentSwitch;
	info->currentSwitch=(ILNode*)node;

	/* Generate code for the switch sections */
	ILNode_ListIter_Init(&iter, node->sections);
	while((section = (ILNode_SwitchSection *)ILNode_ListIter_Next(&iter)) != 0)
	{
		/* Output the section label */
		JavaGenLabel(info, &(section->label));

		/* Pop the extra value copy if we were using "if" statements */
		if(needPop)
		{
			if(size == 1)
			{
				JavaGenSimple(info, JAVA_OP_POP);
			}
			else if(size == 2)
			{
				JavaGenSimple(info, JAVA_OP_POP2);
			}
		}

		/* Output the code for the section */
		JavaGenDiscard(section->stmt, info);
	}

	/* leave currentSwitch and restores saveSwitch */
	info->needSwitchPop = savePop;
	info->currentSwitch = saveSwitch;

	/* Pop from the switch context and set the default and break labels */
	PopLoop(info);
	if(!(node->defaultSection))
	{
		JavaGenLabel(info, defaultLabel);
		if(needPop)
		{
			if(size == 1)
			{
				JavaGenSimple(info, JAVA_OP_POP);
			}
			else if(size == 2)
			{
				JavaGenSimple(info, JAVA_OP_POP2);
			}
		}
	}
	JavaGenLabel(info, &breakLabel);
}
#line 4988 "cg_stmt.c"

struct ILNode_Switch_vtable__ const ILNode_Switch_vt__ = {
	&ILNode_LabelledStatement_vt__,
	ILNode_Switch_kind,
	"ILNode_Switch",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Switch_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Switch_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Switch_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

ILNode *ILNode_EmptyExpr_create(ILMachineType type)
{
	ILNode_EmptyExpr *node__ = (ILNode_EmptyExpr *)yynodealloc(sizeof(struct ILNode_EmptyExpr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_EmptyExpr_vt__;
	node__->kind__ = ILNode_EmptyExpr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_Empty_create(void)
{
	ILNode_Empty *node__ = (ILNode_Empty *)yynodealloc(sizeof(struct ILNode_Empty__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Empty_vt__;
	node__->kind__ = ILNode_Empty_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_If_create(ILNode * expr, ILNode * thenClause, ILNode * elseClause)
{
	ILNode_If *node__ = (ILNode_If *)yynodealloc(sizeof(struct ILNode_If__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_If_vt__;
	node__->kind__ = ILNode_If_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr = expr;
	node__->thenClause = thenClause;
	node__->elseClause = elseClause;
	return (ILNode *)node__;
}

ILNode *ILNode_Break_create(void)
{
	ILNode_Break *node__ = (ILNode_Break *)yynodealloc(sizeof(struct ILNode_Break__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Break_vt__;
	node__->kind__ = ILNode_Break_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_LabelledBreak_create(char * name)
{
	ILNode_LabelledBreak *node__ = (ILNode_LabelledBreak *)yynodealloc(sizeof(struct ILNode_LabelledBreak__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LabelledBreak_vt__;
	node__->kind__ = ILNode_LabelledBreak_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = name;
	return (ILNode *)node__;
}

ILNode *ILNode_Continue_create(void)
{
	ILNode_Continue *node__ = (ILNode_Continue *)yynodealloc(sizeof(struct ILNode_Continue__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Continue_vt__;
	node__->kind__ = ILNode_Continue_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_LabelledContinue_create(char * name)
{
	ILNode_LabelledContinue *node__ = (ILNode_LabelledContinue *)yynodealloc(sizeof(struct ILNode_LabelledContinue__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LabelledContinue_vt__;
	node__->kind__ = ILNode_LabelledContinue_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = name;
	return (ILNode *)node__;
}

ILNode *ILNode_Return_create(void)
{
	ILNode_Return *node__ = (ILNode_Return *)yynodealloc(sizeof(struct ILNode_Return__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Return_vt__;
	node__->kind__ = ILNode_Return_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ReturnExpr_create(ILNode * expr)
{
	ILNode_ReturnExpr *node__ = (ILNode_ReturnExpr *)yynodealloc(sizeof(struct ILNode_ReturnExpr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ReturnExpr_vt__;
	node__->kind__ = ILNode_ReturnExpr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_Goto_create(char * name)
{
	ILNode_Goto *node__ = (ILNode_Goto *)yynodealloc(sizeof(struct ILNode_Goto__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Goto_vt__;
	node__->kind__ = ILNode_Goto_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = name;
	return (ILNode *)node__;
}

ILNode *ILNode_GotoLabel_create(char * name)
{
	ILNode_GotoLabel *node__ = (ILNode_GotoLabel *)yynodealloc(sizeof(struct ILNode_GotoLabel__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_GotoLabel_vt__;
	node__->kind__ = ILNode_GotoLabel_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = name;
	return (ILNode *)node__;
}

ILNode *ILNode_GotoCase_create(ILNode * expr)
{
	ILNode_GotoCase *node__ = (ILNode_GotoCase *)yynodealloc(sizeof(struct ILNode_GotoCase__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_GotoCase_vt__;
	node__->kind__ = ILNode_GotoCase_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr = expr;
	node__->switchSection = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_GotoDefault_create(void)
{
	ILNode_GotoDefault *node__ = (ILNode_GotoDefault *)yynodealloc(sizeof(struct ILNode_GotoDefault__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_GotoDefault_vt__;
	node__->kind__ = ILNode_GotoDefault_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_NewScope_create(ILNode * stmt)
{
	ILNode_NewScope *node__ = (ILNode_NewScope *)yynodealloc(sizeof(struct ILNode_NewScope__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_NewScope_vt__;
	node__->kind__ = ILNode_NewScope_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->stmt = stmt;
	node__->scope = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_SwitchSection_create(ILNode * caseList, ILNode * stmt)
{
	ILNode_SwitchSection *node__ = (ILNode_SwitchSection *)yynodealloc(sizeof(struct ILNode_SwitchSection__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SwitchSection_vt__;
	node__->kind__ = ILNode_SwitchSection_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->caseList = caseList;
	node__->stmt = stmt;
	node__->label = ILLabel_Undefined;
	node__->visited = ILVisitMode_NotVisited;
	return (ILNode *)node__;
}

ILNode *ILNode_CaseLabel_create(ILNode * expr)
{
	ILNode_CaseLabel *node__ = (ILNode_CaseLabel *)yynodealloc(sizeof(struct ILNode_CaseLabel__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CaseLabel_vt__;
	node__->kind__ = ILNode_CaseLabel_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr = expr;
	node__->section = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_DefaultLabel_create(void)
{
	ILNode_DefaultLabel *node__ = (ILNode_DefaultLabel *)yynodealloc(sizeof(struct ILNode_DefaultLabel__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DefaultLabel_vt__;
	node__->kind__ = ILNode_DefaultLabel_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->section = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_Throw_create(void)
{
	ILNode_Throw *node__ = (ILNode_Throw *)yynodealloc(sizeof(struct ILNode_Throw__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Throw_vt__;
	node__->kind__ = ILNode_Throw_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ThrowExpr_create(ILNode * expr)
{
	ILNode_ThrowExpr *node__ = (ILNode_ThrowExpr *)yynodealloc(sizeof(struct ILNode_ThrowExpr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ThrowExpr_vt__;
	node__->kind__ = ILNode_ThrowExpr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_Try_create(ILNode * stmt, ILNode * catchClauses, ILNode * finallyClause)
{
	ILNode_Try *node__ = (ILNode_Try *)yynodealloc(sizeof(struct ILNode_Try__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Try_vt__;
	node__->kind__ = ILNode_Try_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->stmt = stmt;
	node__->catchClauses = catchClauses;
	node__->finallyClause = finallyClause;
	return (ILNode *)node__;
}

ILNode *ILNode_CatchClause_create(ILNode * type, char * name, ILNode * nameNode, ILNode * stmt)
{
	ILNode_CatchClause *node__ = (ILNode_CatchClause *)yynodealloc(sizeof(struct ILNode_CatchClause__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CatchClause_vt__;
	node__->kind__ = ILNode_CatchClause_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->type = type;
	node__->name = name;
	node__->nameNode = nameNode;
	node__->stmt = stmt;
	node__->classInfo = 0;
	node__->varIndex = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_FinallyClause_create(ILNode * stmt)
{
	ILNode_FinallyClause *node__ = (ILNode_FinallyClause *)yynodealloc(sizeof(struct ILNode_FinallyClause__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_FinallyClause_vt__;
	node__->kind__ = ILNode_FinallyClause_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_Lock_create(ILNode * expr, ILNode * stmt)
{
	ILNode_Lock *node__ = (ILNode_Lock *)yynodealloc(sizeof(struct ILNode_Lock__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Lock_vt__;
	node__->kind__ = ILNode_Lock_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->expr = expr;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_LocalVarDeclaration_create(ILNode * type, ILNode * varNames)
{
	ILNode_LocalVarDeclaration *node__ = (ILNode_LocalVarDeclaration *)yynodealloc(sizeof(struct ILNode_LocalVarDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LocalVarDeclaration_vt__;
	node__->kind__ = ILNode_LocalVarDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->type = type;
	node__->varNames = varNames;
	return (ILNode *)node__;
}

ILNode *ILNode_LocalConstDeclaration_create(ILNode * type, ILNode * decls)
{
	ILNode_LocalConstDeclaration *node__ = (ILNode_LocalConstDeclaration *)yynodealloc(sizeof(struct ILNode_LocalConstDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LocalConstDeclaration_vt__;
	node__->kind__ = ILNode_LocalConstDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->type = type;
	node__->decls = decls;
	return (ILNode *)node__;
}

ILNode *ILNode_LineInfo_create(ILNode * stmt)
{
	ILNode_LineInfo *node__ = (ILNode_LineInfo *)yynodealloc(sizeof(struct ILNode_LineInfo__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LineInfo_vt__;
	node__->kind__ = ILNode_LineInfo_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_EventAddOrRemove_create(ILNode * thisExpr, ILNode * delegateExpr, ILMethod * method)
{
	ILNode_EventAddOrRemove *node__ = (ILNode_EventAddOrRemove *)yynodealloc(sizeof(struct ILNode_EventAddOrRemove__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_EventAddOrRemove_vt__;
	node__->kind__ = ILNode_EventAddOrRemove_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->thisExpr = thisExpr;
	node__->delegateExpr = delegateExpr;
	node__->method = method;
	return (ILNode *)node__;
}

ILNode *ILNode_Compound_create(void)
{
	ILNode_Compound *node__ = (ILNode_Compound *)yynodealloc(sizeof(struct ILNode_Compound__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Compound_vt__;
	node__->kind__ = ILNode_Compound_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->item1 = 0;
	node__->item2 = 0;
	node__->item3 = 0;
	node__->item4 = 0;
	node__->rest = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_SwitchSectList_create(void)
{
	ILNode_SwitchSectList *node__ = (ILNode_SwitchSectList *)yynodealloc(sizeof(struct ILNode_SwitchSectList__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SwitchSectList_vt__;
	node__->kind__ = ILNode_SwitchSectList_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->item1 = 0;
	node__->item2 = 0;
	node__->item3 = 0;
	node__->item4 = 0;
	node__->rest = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CaseList_create(void)
{
	ILNode_CaseList *node__ = (ILNode_CaseList *)yynodealloc(sizeof(struct ILNode_CaseList__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CaseList_vt__;
	node__->kind__ = ILNode_CaseList_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->item1 = 0;
	node__->item2 = 0;
	node__->item3 = 0;
	node__->item4 = 0;
	node__->rest = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_CatchClauses_create(void)
{
	ILNode_CatchClauses *node__ = (ILNode_CatchClauses *)yynodealloc(sizeof(struct ILNode_CatchClauses__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_CatchClauses_vt__;
	node__->kind__ = ILNode_CatchClauses_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->item1 = 0;
	node__->item2 = 0;
	node__->item3 = 0;
	node__->item4 = 0;
	node__->rest = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_While_create(ILNode * cond, ILNode * stmt)
{
	ILNode_While *node__ = (ILNode_While *)yynodealloc(sizeof(struct ILNode_While__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_While_vt__;
	node__->kind__ = ILNode_While_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = 0;
	node__->cond = cond;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_Do_create(ILNode * stmt, ILNode * cond)
{
	ILNode_Do *node__ = (ILNode_Do *)yynodealloc(sizeof(struct ILNode_Do__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Do_vt__;
	node__->kind__ = ILNode_Do_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = 0;
	node__->stmt = stmt;
	node__->cond = cond;
	return (ILNode *)node__;
}

ILNode *ILNode_For_create(ILNode * init, ILNode * cond, ILNode * incr, ILNode * stmt)
{
	ILNode_For *node__ = (ILNode_For *)yynodealloc(sizeof(struct ILNode_For__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_For_vt__;
	node__->kind__ = ILNode_For_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = 0;
	node__->init = init;
	node__->cond = cond;
	node__->incr = incr;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_Foreach_create(ILNode * type, char * varName, ILNode * varNameNode, ILNode * expr, ILNode * stmt)
{
	ILNode_Foreach *node__ = (ILNode_Foreach *)yynodealloc(sizeof(struct ILNode_Foreach__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Foreach_vt__;
	node__->kind__ = ILNode_Foreach_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = 0;
	node__->type = type;
	node__->varName = varName;
	node__->varNameNode = varNameNode;
	node__->expr = expr;
	node__->stmt = stmt;
	node__->doCast = 0;
	node__->varIndex = 0;
	node__->varType = ILMachineType_Void;
	node__->arrayType = 0;
	node__->elemType = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ForeachString_create(ILNode * expr, ILNode * stmt, unsigned long varIndex, ILMachineType varType)
{
	ILNode_ForeachString *node__ = (ILNode_ForeachString *)yynodealloc(sizeof(struct ILNode_ForeachString__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ForeachString_vt__;
	node__->kind__ = ILNode_ForeachString_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = 0;
	node__->expr = expr;
	node__->stmt = stmt;
	node__->varIndex = varIndex;
	node__->varType = varType;
	return (ILNode *)node__;
}

ILNode *ILNode_ForeachCollection_create(ILNode * doCast, ILNode * expr, ILNode * stmt, ILType * arrayType, unsigned long varIndex, ILMachineType varType, ILType * enumeratorType, ILMethod * getEnumerator, ILMethod * moveNext, ILMethod * getCurrent)
{
	ILNode_ForeachCollection *node__ = (ILNode_ForeachCollection *)yynodealloc(sizeof(struct ILNode_ForeachCollection__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ForeachCollection_vt__;
	node__->kind__ = ILNode_ForeachCollection_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = 0;
	node__->doCast = doCast;
	node__->expr = expr;
	node__->stmt = stmt;
	node__->arrayType = arrayType;
	node__->varIndex = varIndex;
	node__->varType = varType;
	node__->enumeratorType = enumeratorType;
	node__->getEnumerator = getEnumerator;
	node__->moveNext = moveNext;
	node__->getCurrent = getCurrent;
	return (ILNode *)node__;
}

ILNode *ILNode_Switch_create(ILNode * expr, ILNode * sections, ILNode * body)
{
	ILNode_Switch *node__ = (ILNode_Switch *)yynodealloc(sizeof(struct ILNode_Switch__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Switch_vt__;
	node__->kind__ = ILNode_Switch_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = 0;
	node__->expr = expr;
	node__->sections = sections;
	node__->body = body;
	node__->defaultSection = 0;
	node__->switchValues = 0;
	node__->numSwitchValues = 0;
	node__->switchType = 0;
	node__->tableType = ILSwitchTableType_Indexed;
	return (ILNode *)node__;
}

