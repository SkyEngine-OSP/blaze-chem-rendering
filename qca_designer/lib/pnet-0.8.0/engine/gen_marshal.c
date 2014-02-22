/* gen_marshal.c.  Generated automatically by treecc */
#line 1 "./gen_marshal.tc"

/*
 * gen_marshal.tc - Generate marshalling code from PInvoke/internalcall's.
 *
 * Copyright (C) 2003  Southern Storm Software, Pty Ltd.
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
#line 55 "./gen_marshal.tc"

#include "gen_marshal.h"
#include "il_opcodes.h"

/*
 * Import from "verify.c".
 */
ILEngineType _ILTypeToEngineType(ILType *type);

#line 34 "gen_marshal.c"

#define ILM_State_REENTRANT 1
#line 1 "c_skel.c"
/*
 * treecc node allocation routines for C.
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
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#include <stdlib.h>

#ifndef ILM_State_BLKSIZ
#define	ILM_State_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct ILM_State_block
{
	char data__[ILM_State_BLKSIZ];
	struct ILM_State_block *next__;

};
struct ILM_State_push
{
	struct ILM_State_push *next__;
	struct ILM_State_block *saved_block__;
	int saved_used__;
};

/*
 * The fixed global state to use for non-reentrant allocation.
 */
#ifndef ILM_State_REENTRANT
static ILM_State fixed_state__;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	ILM_State_ALIGN_CHECK_TYPE(type,name)	\
	struct _ILM_State_align_##name { \
		char pad; \
		type field; \
	}
#define	ILM_State_ALIGN_FOR_TYPE(type)	\
	((unsigned)(&(((struct _ILM_State_align_##type *)0)->field)))
#define	ILM_State_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	ILM_State_ALIGN_MAX3(a,b,c) \
	(ILM_State_ALIGN_MAX((a), ILM_State_ALIGN_MAX((b), (c))))
ILM_State_ALIGN_CHECK_TYPE(int, int);
ILM_State_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
ILM_State_ALIGN_CHECK_TYPE(__int64, long_long);
#else
ILM_State_ALIGN_CHECK_TYPE(long long, long_long);
#endif
ILM_State_ALIGN_CHECK_TYPE(void *, void_p);
ILM_State_ALIGN_CHECK_TYPE(float, float);
ILM_State_ALIGN_CHECK_TYPE(double, double);
#define	ILM_State_ALIGNMENT	\
	ILM_State_ALIGN_MAX( \
			ILM_State_ALIGN_MAX3	\
			(ILM_State_ALIGN_FOR_TYPE(int), \
		     ILM_State_ALIGN_FOR_TYPE(long), \
			 ILM_State_ALIGN_FOR_TYPE(long_long)), \
  	     ILM_State_ALIGN_MAX3 \
		 	(ILM_State_ALIGN_FOR_TYPE(void_p), \
			 ILM_State_ALIGN_FOR_TYPE(float), \
			 ILM_State_ALIGN_FOR_TYPE(double)))

/*
 * Initialize the node allocation pool.
 */
#ifdef ILM_State_REENTRANT
void ILM_nodeinit(state__)
ILM_State *state__;
{
#else
void ILM_nodeinit()
{
	ILM_State *state__ = &fixed_state__;
#endif
	state__->blocks__ = 0;
	state__->push_stack__ = 0;
	state__->used__ = 0;
}

/*
 * Allocate a block of memory.
 */
#ifdef ILM_State_REENTRANT
void *ILM_nodealloc(state__, size__)
ILM_State *state__;
unsigned int size__;
{
#else
void *ILM_nodealloc(size__)
unsigned int size__;
{
	ILM_State *state__ = &fixed_state__;
#endif
	struct ILM_State_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + ILM_State_ALIGNMENT - 1) &
				~(ILM_State_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = state__->blocks__;
	if(!block__ || (state__->used__ + size__) > ILM_State_BLKSIZ)
	{
		if(size__ > ILM_State_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = (struct ILM_State_block *)
						malloc(sizeof(struct ILM_State_block));
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   supply the "ILM_nodefailed" function to report the
			   out of memory state and/or abort the program */
#ifdef ILM_State_REENTRANT
			ILM_nodefailed(state__);
#else
			ILM_nodefailed();
#endif
			return (void *)0;
		}
		block__->next__ = state__->blocks__;
		state__->blocks__ = block__;
		state__->used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + state__->used__);
	state__->used__ += size__;
	return result__;
}

/*
 * Push the node allocation state.
 */
#ifdef ILM_State_REENTRANT
int ILM_nodepush(state__)
ILM_State *state__;
{
#else
int ILM_nodepush()
{
	ILM_State *state__ = &fixed_state__;
#endif
	struct ILM_State_block *saved_block__;
	int saved_used__;
	struct ILM_State_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = state__->blocks__;
	saved_used__ = state__->used__;

	/* Allocate space for a push item */
#ifdef ILM_State_REENTRANT
	push_item__ = (struct ILM_State_push *)
			ILM_nodealloc(state__, sizeof(struct ILM_State_push));
#else
	push_item__ = (struct ILM_State_push *)
			ILM_nodealloc(sizeof(struct ILM_State_push));
#endif
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = state__->push_stack__;
	state__->push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
#ifdef ILM_State_REENTRANT
void ILM_nodepop(state__)
ILM_State *state__;
{
#else
void ILM_nodepop()
{
	ILM_State *state__ = &fixed_state__;
#endif
	struct ILM_State_push *push_item__;
	struct ILM_State_block *saved_block__;
	struct ILM_State_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = state__->push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		state__->used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		state__->used__ = push_item__->saved_used__;
		state__->push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(state__->blocks__ != saved_block__)
	{
		temp_block__ = state__->blocks__;
		state__->blocks__ = temp_block__->next__;
		free(temp_block__);
	}
}

/*
 * Clear the node allocation pool completely.
 */
#ifdef ILM_State_REENTRANT
void ILM_nodeclear(state__)
ILM_State *state__;
{
#else
void ILM_nodeclear()
{
	ILM_State *state__ = &fixed_state__;
#endif
	struct ILM_State_block *temp_block__;
	while(state__->blocks__ != 0)
	{
		temp_block__ = state__->blocks__;
		state__->blocks__ = temp_block__->next__;
		free(temp_block__);
	}
	state__->push_stack__ = 0;
	state__->used__ = 0;
}
#line 302 "gen_marshal.c"
struct ILM_Node_vtable__ const ILM_Node_vt__ = {
	0,
	ILM_Node_kind,
	"ILM_Node",
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
};

struct ILM_LValue_vtable__ const ILM_LValue_vt__ = {
	&ILM_Node_vt__,
	ILM_LValue_kind,
	"ILM_LValue",
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
	(void (*)(ILM_LValue *this__, ILM_Context * context))0,
	(void (*)(ILM_LValue *this__, ILM_Context * context))0,
	(void (*)(ILM_LValue *this__, ILM_Context * context))0,
};

void ILM_Unary_ILM_AllocLocals__(ILM_Unary *node, ILM_Context * context)
#line 245 "./gen_marshal.tc"
{
	ILM_AllocLocals(node->expr, context);
}
#line 329 "gen_marshal.c"

void ILM_Unary_ILM_ClearLocals__(ILM_Unary *node, ILM_Context * context)
#line 332 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->expr, context);
}
#line 336 "gen_marshal.c"

struct ILM_Unary_vtable__ const ILM_Unary_vt__ = {
	&ILM_Node_vt__,
	ILM_Unary_kind,
	"ILM_Unary",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
};

void ILM_Binary_ILM_AllocLocals__(ILM_Binary *node, ILM_Context * context)
#line 249 "./gen_marshal.tc"
{
	ILM_AllocLocals(node->expr1, context);
	ILM_AllocLocals(node->expr2, context);
}
#line 353 "gen_marshal.c"

void ILM_Binary_ILM_ClearLocals__(ILM_Binary *node, ILM_Context * context)
#line 336 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->expr1, context);
	ILM_ClearLocals(node->expr2, context);
}
#line 361 "gen_marshal.c"

struct ILM_Binary_vtable__ const ILM_Binary_vt__ = {
	&ILM_Node_vt__,
	ILM_Binary_kind,
	"ILM_Binary",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Binary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Binary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))0,
};

void ILM_FfiThread_ILM_AllocLocals__(ILM_FfiThread *node, ILM_Context * context)
#line 230 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 377 "gen_marshal.c"

void ILM_FfiThread_ILM_ClearLocals__(ILM_FfiThread *node, ILM_Context * context)
#line 320 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 384 "gen_marshal.c"

void ILM_FfiThread_ILM_GenValue__(ILM_FfiThread *node, ILM_Context * context)
#line 516 "./gen_marshal.tc"
{
	ILCoderStartFfiArgs(context->coder);
	if(context->isInternal)
	{
		ILCoderPushThread(context->coder, context->useRawCalls);
	}
}
#line 395 "gen_marshal.c"

struct ILM_FfiThread_vtable__ const ILM_FfiThread_vt__ = {
	&ILM_Node_vt__,
	ILM_FfiThread_kind,
	"ILM_FfiThread",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiThread_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiThread_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiThread_ILM_GenValue__,
};

void ILM_FfiThis_ILM_AllocLocals__(ILM_FfiThis *node, ILM_Context * context)
#line 230 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 411 "gen_marshal.c"

void ILM_FfiThis_ILM_ClearLocals__(ILM_FfiThis *node, ILM_Context * context)
#line 320 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 418 "gen_marshal.c"

void ILM_FfiThis_ILM_GenValue__(ILM_FfiThis *node, ILM_Context * context)
#line 528 "./gen_marshal.tc"
{
	if(context->isConstructor || !ILType_HasThis(context->signature))
	{
		/* This method doesn't need a "this" pointer passed to it */
		return;
	}
	if(context->isInternal)
	{
		/* Check the "this" value for null so that the engine
		   internalcall method doesn't have to worry about it */
		ILCoderLoadArg(context->coder, 0, ILType_Int);
		ILCoderCheckNull(context->coder);
		if(!(context->useRawCalls))
		{
			ILCoderPop(context->coder, ILEngineType_I, ILType_Int);
			ILCoderLoadNativeArgAddr(context->coder, 0);
		}
	}
	else if(context->useRawCalls)
	{
		/* Push the value directly onto the system stack */
		ILCoderLoadArg(context->coder, 0, ILType_Int);
	}
	else
	{
		/* Push the address of "this" onto the native argument stack */
		ILCoderLoadNativeArgAddr(context->coder, 0);
	}
}
#line 451 "gen_marshal.c"

struct ILM_FfiThis_vtable__ const ILM_FfiThis_vt__ = {
	&ILM_Node_vt__,
	ILM_FfiThis_kind,
	"ILM_FfiThis",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiThis_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiThis_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiThis_ILM_GenValue__,
};

void ILM_FfiArgument_ILM_AllocLocals__(ILM_FfiArgument *node, ILM_Context * context)
#line 262 "./gen_marshal.tc"
{
	ILM_AllocLocals(node->expr, context);
	if(!(context->useRawCalls))
	{
		if(!ILM_isa(node->expr, ILM_Argument) &&
		   !ILM_isa(node->expr, ILM_Local))
		{
			/* We need a temporary local variable to store the value
			   in a way that we can take its address */
			node->localNum = ILCoderAllocExtraLocal(context->coder, node->type);
		}
	}
}
#line 477 "gen_marshal.c"

void ILM_FfiArgument_ILM_ClearLocals__(ILM_FfiArgument *node, ILM_Context * context)
#line 346 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->expr, context);
	node->localNum = IL_MAX_UINT32;
}
#line 485 "gen_marshal.c"

void ILM_FfiArgument_ILM_GenValue__(ILM_FfiArgument *node, ILM_Context * context)
#line 562 "./gen_marshal.tc"
{
	if(context->useRawCalls)
	{
		/* Push the value directly onto the stack */
		ILM_GenValue(node->expr, context);
	}
	else if(ILM_isa(node->expr, ILM_ArgumentCtor) && context->isConstructor)
	{
		/* Push the address of the argument onto the native stack */
		ILCoderLoadNativeArgAddr
			(context->coder, ((ILM_ArgumentCtor *)(node->expr))->argNum - 1);
	}
	else if(ILM_isa(node->expr, ILM_Argument))
	{
		/* Push the address of the argument onto the native stack */
		ILCoderLoadNativeArgAddr
			(context->coder, ((ILM_Argument *)(node->expr))->argNum);
	}
	else if(ILM_isa(node->expr, ILM_Local))
	{
		/* Push the address of the local onto the native stack */
		ILCoderLoadNativeLocalAddr
			(context->coder, ((ILM_Local *)(node->expr))->localNum);
	}
	else
	{
		/* Store the value into a local variable and take its address */
		ILM_GenValue(node->expr, context);
		ILCoderStoreLocal(context->coder, node->localNum,
						  _ILTypeToEngineType(node->type), node->type);
		ILCoderLoadNativeLocalAddr(context->coder, node->localNum);
	}
}
#line 522 "gen_marshal.c"

struct ILM_FfiArgument_vtable__ const ILM_FfiArgument_vt__ = {
	&ILM_Node_vt__,
	ILM_FfiArgument_kind,
	"ILM_FfiArgument",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiArgument_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiArgument_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiArgument_ILM_GenValue__,
};

void ILM_FfiReturnArgument_ILM_AllocLocals__(ILM_FfiReturnArgument *node, ILM_Context * context)
#line 276 "./gen_marshal.tc"
{
	ILType *returnType = ILTypeGetEnumType(node->type);
	ILM_AllocLocals(node->returnLocal, context);
	if(ILType_IsValueType(returnType) && context->isInternal)
	{
		if(!(context->useRawCalls))
		{
			/* We need an extra local for the pointer to the return value */
			node->localNum = ILCoderAllocExtraLocal(context->coder, ILType_Int);
		}
	}
}
#line 547 "gen_marshal.c"

void ILM_FfiReturnArgument_ILM_ClearLocals__(ILM_FfiReturnArgument *node, ILM_Context * context)
#line 351 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->returnLocal, context);
	node->localNum = IL_MAX_UINT32;
}
#line 555 "gen_marshal.c"

void ILM_FfiReturnArgument_ILM_GenValue__(ILM_FfiReturnArgument *node, ILM_Context * context)
#line 602 "./gen_marshal.tc"
{
	ILType *returnType = ILTypeGetEnumType(node->type);
	if(ILType_IsValueType(returnType) && context->isInternal)
	{
		/* Take the address of the return local */
		ILM_GenRef((ILM_LValue *)(node->returnLocal), context);

		/* If we aren't using raw calls, then store the pointer */
		if(!(context->useRawCalls))
		{
			ILCoderStoreLocal(context->coder, node->localNum,
							  ILEngineType_I, ILType_Int);
			ILCoderLoadNativeLocalAddr(context->coder, node->localNum);
		}
	}
}
#line 575 "gen_marshal.c"

struct ILM_FfiReturnArgument_vtable__ const ILM_FfiReturnArgument_vt__ = {
	&ILM_Node_vt__,
	ILM_FfiReturnArgument_kind,
	"ILM_FfiReturnArgument",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiReturnArgument_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiReturnArgument_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiReturnArgument_ILM_GenValue__,
};

void ILM_FfiReturn_ILM_AllocLocals__(ILM_FfiReturn *node, ILM_Context * context)
#line 289 "./gen_marshal.tc"
{
	ILM_AllocLocals(node->returnLocal, context);
}
#line 591 "gen_marshal.c"

void ILM_FfiReturn_ILM_ClearLocals__(ILM_FfiReturn *node, ILM_Context * context)
#line 356 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->returnLocal, context);
}
#line 598 "gen_marshal.c"

void ILM_FfiReturn_ILM_GenValue__(ILM_FfiReturn *node, ILM_Context * context)
#line 623 "./gen_marshal.tc"
{
	ILType *returnType = ILTypeGetEnumType(node->type);

	/* Push the address of the argument array for raw calls */
	if(context->useRawCalls)
	{
		ILCoderPushRawArgPointer(context->coder);
	}

	/* Push the address of the return value */
	context->hasReturn = 0;
	if(returnType != ILType_Void)
	{
		if(!(context->isInternal) || !ILType_IsValueType(returnType))
		{
			ILCoderAddrOfLocal
				(context->coder, ((ILM_Local *)(node->returnLocal))->localNum);
			context->hasReturn = 1;
		}
	}
	else if(context->isConstructor)
	{
		ILCoderAddrOfLocal
			(context->coder, ((ILM_Local *)(node->returnLocal))->localNum);
		context->hasReturn = 1;
	}
}
#line 629 "gen_marshal.c"

struct ILM_FfiReturn_vtable__ const ILM_FfiReturn_vt__ = {
	&ILM_Node_vt__,
	ILM_FfiReturn_kind,
	"ILM_FfiReturn",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiReturn_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiReturn_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiReturn_ILM_GenValue__,
};

void ILM_FfiCall_ILM_AllocLocals__(ILM_FfiCall *node, ILM_Context * context)
#line 230 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 645 "gen_marshal.c"

void ILM_FfiCall_ILM_ClearLocals__(ILM_FfiCall *node, ILM_Context * context)
#line 320 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 652 "gen_marshal.c"

void ILM_FfiCall_ILM_GenValue__(ILM_FfiCall *node, ILM_Context * context)
#line 655 "./gen_marshal.tc"
{
	if(context->isConstructor)
	{
		ILCoderCallFfi(context->coder, node->ctorfn, node->ctorcif,
					   context->useRawCalls, context->hasReturn);
	}
	else
	{
		ILCoderCallFfi(context->coder, node->fn, node->cif,
					   context->useRawCalls, context->hasReturn);
	}
}
#line 668 "gen_marshal.c"

struct ILM_FfiCall_vtable__ const ILM_FfiCall_vt__ = {
	&ILM_Node_vt__,
	ILM_FfiCall_kind,
	"ILM_FfiCall",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiCall_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiCall_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_FfiCall_ILM_GenValue__,
};

void ILM_TryFinally_ILM_AllocLocals__(ILM_TryFinally *node, ILM_Context * context)
#line 293 "./gen_marshal.tc"
{
	ILM_AllocLocals(node->tryBlock, context);
	ILM_AllocLocals(node->finallyBlock, context);
	if(node->returnExpr)
	{
		ILM_AllocLocals(node->returnExpr, context);
	}
}
#line 689 "gen_marshal.c"

void ILM_TryFinally_ILM_ClearLocals__(ILM_TryFinally *node, ILM_Context * context)
#line 360 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->tryBlock, context);
	ILM_ClearLocals(node->finallyBlock, context);
	if(node->returnExpr)
	{
		ILM_ClearLocals(node->returnExpr, context);
	}
}
#line 701 "gen_marshal.c"

void ILM_TryFinally_ILM_GenValue__(ILM_TryFinally *node, ILM_Context * context)
#line 742 "./gen_marshal.tc"
{
	ILException exception;

	/* Create a fake exception list for the "finally" clause */
	ILMemZero(&exception, sizeof(exception));
	exception.flags = IL_META_EXCEPTION_FINALLY;
	exception.tryOffset = 0;
	exception.tryLength = 1;
	exception.handlerOffset = 1;
	exception.handlerLength = 1;

	/* Set up the method frame to handle exceptions */
	ILCoderSetupExceptions(context->coder, &exception, 0);

	/* Mark the start of the "try" block */
	ILCoderLabel(context->coder, 0);
	ILCoderStackRefresh(context->coder, 0, 0);

	/* Output the body of the "try" block */
	ILM_GenValue(node->tryBlock, context);

	/* Call the "finally" block and then jump to the end of the method */
	ILCoderJsr(context->coder, 1);
	ILCoderBranch(context->coder, IL_OP_LEAVE, 2,
				  ILEngineType_I4, ILEngineType_I4);

	/* Mark the end of the "try" block and the start of the "finally" block */
	ILCoderLabel(context->coder, 1);
	ILCoderStackRefresh(context->coder, 0, 0);

	/* Output the body of the "finally" block */
	ILM_GenValue(node->finallyBlock, context);
	ILCoderRetFromJsr(context->coder);

	/* Mark the end of the "finally" block */
	ILCoderLabel(context->coder, 2);
	ILCoderStackRefresh(context->coder, 0, 0);

	/* Output the "return" instruction for the method */
	if(context->isConstructor)
	{
		if(node->returnExpr)
		{
			ILM_GenValue(node->returnExpr, context);
		}
		ILCoderReturnInsn(context->coder, ILEngineType_I, ILType_Int);
	}
	else
	{
		if(node->returnType != ILType_Void && node->returnExpr)
		{
			ILM_GenValue(node->returnExpr, context);
		}
		ILCoderReturnInsn(context->coder,
						  _ILTypeToEngineType(node->returnType),
						  node->returnType);
	}

	/* Mark the end of the method */
	ILCoderMarkEnd(context->coder);

	/* Output the exception matching table */
	ILCoderTryHandlerStart(context->coder, 0, 1);
	ILCoderJsr(context->coder, 1);
	ILCoderThrow(context->coder, 0);
	ILCoderTryHandlerEnd(context->coder);
	ILCoderTryHandlerStart(context->coder, 0, IL_MAX_UINT32);
	ILCoderThrow(context->coder, 0);
	ILCoderTryHandlerEnd(context->coder);
}
#line 775 "gen_marshal.c"

struct ILM_TryFinally_vtable__ const ILM_TryFinally_vt__ = {
	&ILM_Node_vt__,
	ILM_TryFinally_kind,
	"ILM_TryFinally",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_TryFinally_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_TryFinally_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_TryFinally_ILM_GenValue__,
};

void ILM_Compound_ILM_AllocLocals__(ILM_Compound *node, ILM_Context * context)
#line 302 "./gen_marshal.tc"
{
	ILM_CompoundStmt *stmt = node->stmts;
	while(stmt != 0)
	{
		ILM_AllocLocals(stmt->expr, context);
		stmt = stmt->next;
	}
}
#line 796 "gen_marshal.c"

void ILM_Compound_ILM_ClearLocals__(ILM_Compound *node, ILM_Context * context)
#line 369 "./gen_marshal.tc"
{
	ILM_CompoundStmt *stmt = node->stmts;
	while(stmt != 0)
	{
		ILM_ClearLocals(stmt->expr, context);
		stmt = stmt->next;
	}
}
#line 808 "gen_marshal.c"

void ILM_Compound_ILM_GenValue__(ILM_Compound *node, ILM_Context * context)
#line 821 "./gen_marshal.tc"
{
	ILM_CompoundStmt *stmt = node->stmts;
	while(stmt != 0)
	{
		ILM_GenValue(stmt->expr, context);
		stmt = stmt->next;
	}
}
#line 820 "gen_marshal.c"

struct ILM_Compound_vtable__ const ILM_Compound_vt__ = {
	&ILM_Node_vt__,
	ILM_Compound_kind,
	"ILM_Compound",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Compound_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Compound_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Compound_ILM_GenValue__,
};

void ILM_Argument_ILM_AllocLocals__(ILM_Argument *node, ILM_Context * context)
#line 230 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 836 "gen_marshal.c"

void ILM_Argument_ILM_ClearLocals__(ILM_Argument *node, ILM_Context * context)
#line 320 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 843 "gen_marshal.c"

void ILM_Argument_ILM_GenValue__(ILM_Argument *node, ILM_Context * context)
#line 382 "./gen_marshal.tc"
{
	ILCoderLoadArg(context->coder, node->argNum, node->type);
}
#line 850 "gen_marshal.c"

void ILM_Argument_ILM_Prepare__(ILM_Argument *node, ILM_Context * context)
#line 386 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 857 "gen_marshal.c"

void ILM_Argument_ILM_Store__(ILM_Argument *node, ILM_Context * context)
#line 390 "./gen_marshal.tc"
{
	ILEngineType type = _ILTypeToEngineType(node->type);
	ILCoderStoreArg(context->coder, node->argNum, type, node->type);
}
#line 865 "gen_marshal.c"

void ILM_Argument_ILM_GenRef__(ILM_Argument *node, ILM_Context * context)
#line 395 "./gen_marshal.tc"
{
	ILCoderAddrOfArg(context->coder, node->argNum);
}
#line 872 "gen_marshal.c"

struct ILM_Argument_vtable__ const ILM_Argument_vt__ = {
	&ILM_LValue_vt__,
	ILM_Argument_kind,
	"ILM_Argument",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Argument_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Argument_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Argument_ILM_GenValue__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Argument_ILM_Prepare__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Argument_ILM_Store__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Argument_ILM_GenRef__,
};

void ILM_Local_ILM_AllocLocals__(ILM_Local *node, ILM_Context * context)
#line 234 "./gen_marshal.tc"
{
	if(node->localNum == IL_MAX_UINT32)
	{
		node->localNum = ILCoderAllocExtraLocal(context->coder, node->type);
	}
}
#line 894 "gen_marshal.c"

void ILM_Local_ILM_ClearLocals__(ILM_Local *node, ILM_Context * context)
#line 324 "./gen_marshal.tc"
{
	node->localNum = IL_MAX_UINT32;
}
#line 901 "gen_marshal.c"

void ILM_Local_ILM_GenValue__(ILM_Local *node, ILM_Context * context)
#line 445 "./gen_marshal.tc"
{
	ILCoderLoadLocal(context->coder, node->localNum, node->type);
}
#line 908 "gen_marshal.c"

void ILM_Local_ILM_Prepare__(ILM_Local *node, ILM_Context * context)
#line 449 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 915 "gen_marshal.c"

void ILM_Local_ILM_Store__(ILM_Local *node, ILM_Context * context)
#line 453 "./gen_marshal.tc"
{
	ILEngineType type = _ILTypeToEngineType(node->type);
	ILCoderStoreLocal(context->coder, node->localNum, type, node->type);
}
#line 923 "gen_marshal.c"

void ILM_Local_ILM_GenRef__(ILM_Local *node, ILM_Context * context)
#line 458 "./gen_marshal.tc"
{
	ILCoderAddrOfLocal(context->coder, node->localNum);
}
#line 930 "gen_marshal.c"

struct ILM_Local_vtable__ const ILM_Local_vt__ = {
	&ILM_LValue_vt__,
	ILM_Local_kind,
	"ILM_Local",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Local_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Local_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Local_ILM_GenValue__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Local_ILM_Prepare__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Local_ILM_Store__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Local_ILM_GenRef__,
};

void ILM_Field_ILM_AllocLocals__(ILM_Field *node, ILM_Context * context)
#line 241 "./gen_marshal.tc"
{
	ILM_AllocLocals(node->expr, context);
}
#line 949 "gen_marshal.c"

void ILM_Field_ILM_ClearLocals__(ILM_Field *node, ILM_Context * context)
#line 328 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->expr, context);
}
#line 956 "gen_marshal.c"

void ILM_Field_ILM_GenValue__(ILM_Field *node, ILM_Context * context)
#line 467 "./gen_marshal.tc"
{
	ILType *fieldType;
	ILM_GenValue(node->expr, context);
	fieldType = ILField_Type(node->field);
	ILCoderLoadField(context->coder, ILEngineType_O, ILType_Void,
					 node->field, fieldType);
}
#line 967 "gen_marshal.c"

void ILM_Field_ILM_Prepare__(ILM_Field *node, ILM_Context * context)
#line 475 "./gen_marshal.tc"
{
	ILM_GenValue(node->expr, context);
}
#line 974 "gen_marshal.c"

void ILM_Field_ILM_Store__(ILM_Field *node, ILM_Context * context)
#line 479 "./gen_marshal.tc"
{
	ILType *fieldType = ILField_Type(node->field);
	ILEngineType type = _ILTypeToEngineType(fieldType);
	ILCoderStoreField(context->coder, ILEngineType_O, ILType_Void,
					  node->field, fieldType, type);
}
#line 984 "gen_marshal.c"

void ILM_Field_ILM_GenRef__(ILM_Field *node, ILM_Context * context)
#line 486 "./gen_marshal.tc"
{
	ILM_GenValue(node->expr, context);
	ILCoderLoadFieldAddr(context->coder, ILEngineType_O, ILType_Void,
					     node->field, ILField_Type(node->field));
}
#line 993 "gen_marshal.c"

struct ILM_Field_vtable__ const ILM_Field_vt__ = {
	&ILM_LValue_vt__,
	ILM_Field_kind,
	"ILM_Field",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Field_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Field_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Field_ILM_GenValue__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Field_ILM_Prepare__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Field_ILM_Store__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_Field_ILM_GenRef__,
};

void ILM_ArgumentCtor_ILM_GenValue__(ILM_ArgumentCtor *node, ILM_Context * context)
#line 403 "./gen_marshal.tc"
{
	if(context->isConstructor)
	{
		ILCoderLoadArg(context->coder, node->argNum - 1, node->type);
	}
	else
	{
		ILCoderLoadArg(context->coder, node->argNum, node->type);
	}
}
#line 1019 "gen_marshal.c"

void ILM_ArgumentCtor_ILM_Prepare__(ILM_ArgumentCtor *node, ILM_Context * context)
#line 414 "./gen_marshal.tc"
{
	/* Nothing to do here */
}
#line 1026 "gen_marshal.c"

void ILM_ArgumentCtor_ILM_Store__(ILM_ArgumentCtor *node, ILM_Context * context)
#line 418 "./gen_marshal.tc"
{
	ILEngineType type = _ILTypeToEngineType(node->type);
	if(context->isConstructor)
	{
		ILCoderStoreArg(context->coder, node->argNum - 1, type, node->type);
	}
	else
	{
		ILCoderStoreArg(context->coder, node->argNum, type, node->type);
	}
}
#line 1041 "gen_marshal.c"

void ILM_ArgumentCtor_ILM_GenRef__(ILM_ArgumentCtor *node, ILM_Context * context)
#line 430 "./gen_marshal.tc"
{
	if(context->isConstructor)
	{
		ILCoderAddrOfArg(context->coder, node->argNum - 1);
	}
	else
	{
		ILCoderAddrOfArg(context->coder, node->argNum);
	}
}
#line 1055 "gen_marshal.c"

struct ILM_ArgumentCtor_vtable__ const ILM_ArgumentCtor_vt__ = {
	&ILM_Argument_vt__,
	ILM_ArgumentCtor_kind,
	"ILM_ArgumentCtor",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Argument_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Argument_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_ArgumentCtor_ILM_GenValue__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_ArgumentCtor_ILM_Prepare__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_ArgumentCtor_ILM_Store__,
	(void (*)(ILM_LValue *this__, ILM_Context * context))ILM_ArgumentCtor_ILM_GenRef__,
};

void ILM_Return_ILM_GenValue__(ILM_Return *node, ILM_Context * context)
#line 672 "./gen_marshal.tc"
{
	if(node->type != ILType_Void)
	{
		ILM_GenValue(node->expr, context);
	}
	ILCoderReturnInsn(context->coder, _ILTypeToEngineType(node->type),
					  node->type);
}
#line 1079 "gen_marshal.c"

struct ILM_Return_vtable__ const ILM_Return_vt__ = {
	&ILM_Unary_vt__,
	ILM_Return_kind,
	"ILM_Return",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Return_ILM_GenValue__,
};

void ILM_ReturnCtor_ILM_GenValue__(ILM_ReturnCtor *node, ILM_Context * context)
#line 685 "./gen_marshal.tc"
{
	if(context->isConstructor)
	{
		/* This is the constructor form of the method */
		ILM_GenValue(node->expr, context);
		ILCoderReturnInsn(context->coder, ILEngineType_I, ILType_Int);
	}
	else
	{
		/* This is the regular call form of the method */
		ILCoderReturnInsn(context->coder, ILEngineType_Invalid, ILType_Void);
	}
}
#line 1105 "gen_marshal.c"

struct ILM_ReturnCtor_vtable__ const ILM_ReturnCtor_vt__ = {
	&ILM_Unary_vt__,
	ILM_ReturnCtor_kind,
	"ILM_ReturnCtor",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_ReturnCtor_ILM_GenValue__,
};

void ILM_Convert_ILM_GenValue__(ILM_Convert *node, ILM_Context * context)
#line 703 "./gen_marshal.tc"
{
	ILM_GenValue(node->expr, context);
	ILCoderConvert(context->coder, node->opcode);
}
#line 1122 "gen_marshal.c"

struct ILM_Convert_vtable__ const ILM_Convert_vt__ = {
	&ILM_Unary_vt__,
	ILM_Convert_kind,
	"ILM_Convert",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Convert_ILM_GenValue__,
};

void ILM_ConvertCustom_ILM_GenValue__(ILM_ConvertCustom *node, ILM_Context * context)
#line 712 "./gen_marshal.tc"
{
	ILM_GenValue(node->expr, context);
	ILCoderConvertCustom(context->coder, node->opcode,
						 node->customNameLen, node->customCookieLen,
						 node->customName, node->customCookie);
}
#line 1141 "gen_marshal.c"

struct ILM_ConvertCustom_vtable__ const ILM_ConvertCustom_vt__ = {
	&ILM_Unary_vt__,
	ILM_ConvertCustom_kind,
	"ILM_ConvertCustom",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_ConvertCustom_ILM_GenValue__,
};

void ILM_AddressOf_ILM_AllocLocals__(ILM_AddressOf *node, ILM_Context * context)
#line 254 "./gen_marshal.tc"
{
	ILM_AllocLocals(node->expr, context);
	if(!ILM_isa(node->expr, ILM_LValue))
	{
		node->localNum = ILCoderAllocExtraLocal(context->coder, node->type);
	}
}
#line 1161 "gen_marshal.c"

void ILM_AddressOf_ILM_ClearLocals__(ILM_AddressOf *node, ILM_Context * context)
#line 341 "./gen_marshal.tc"
{
	ILM_ClearLocals(node->expr, context);
	node->localNum = IL_MAX_UINT32;
}
#line 1169 "gen_marshal.c"

void ILM_AddressOf_ILM_GenValue__(ILM_AddressOf *node, ILM_Context * context)
#line 723 "./gen_marshal.tc"
{
	if(ILM_isa(node->expr, ILM_LValue))
	{
		ILM_GenRef((ILM_LValue *)(node->expr), context);
	}
	else
	{
		/* Store the value in a local variable before taking its address */
		ILM_GenValue(node->expr, context);
		ILCoderStoreLocal(context->coder, node->localNum,
						  _ILTypeToEngineType(node->type), node->type);
		ILCoderAddrOfLocal(context->coder, node->localNum);
	}
}
#line 1187 "gen_marshal.c"

struct ILM_AddressOf_vtable__ const ILM_AddressOf_vt__ = {
	&ILM_Unary_vt__,
	ILM_AddressOf_kind,
	"ILM_AddressOf",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_AddressOf_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_AddressOf_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_AddressOf_ILM_GenValue__,
};

void ILM_Method_ILM_GenValue__(ILM_Method *node, ILM_Context * context)
#line 834 "./gen_marshal.tc"
{
	ILM_GenValue(node->expr, context);
	ILCoderMarkEnd(context->coder);
}
#line 1204 "gen_marshal.c"

struct ILM_Method_vtable__ const ILM_Method_vt__ = {
	&ILM_Unary_vt__,
	ILM_Method_kind,
	"ILM_Method",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Method_ILM_GenValue__,
};

void ILM_CompoundStmt_ILM_GenValue__(ILM_CompoundStmt *node, ILM_Context * context)
#line 817 "./gen_marshal.tc"
{
	ILM_GenValue(node->expr, context);
}
#line 1220 "gen_marshal.c"

struct ILM_CompoundStmt_vtable__ const ILM_CompoundStmt_vt__ = {
	&ILM_Unary_vt__,
	ILM_CompoundStmt_kind,
	"ILM_CompoundStmt",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Unary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_CompoundStmt_ILM_GenValue__,
};

void ILM_Assign_ILM_GenValue__(ILM_Assign *node, ILM_Context * context)
#line 496 "./gen_marshal.tc"
{
	ILM_Prepare((ILM_LValue *)(node->expr1), context);
	ILM_GenValue(node->expr2, context);
	ILM_Store((ILM_LValue *)(node->expr1), context);
}
#line 1238 "gen_marshal.c"

struct ILM_Assign_vtable__ const ILM_Assign_vt__ = {
	&ILM_Binary_vt__,
	ILM_Assign_kind,
	"ILM_Assign",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Binary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Binary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Assign_ILM_GenValue__,
};

void ILM_AssignCtor_ILM_GenValue__(ILM_AssignCtor *node, ILM_Context * context)
#line 502 "./gen_marshal.tc"
{
	/* Only need the assignment if we are returning the pointer */
	if(context->isConstructor)
	{
		ILM_Prepare((ILM_LValue *)(node->expr1), context);
		ILM_GenValue(node->expr2, context);
		ILM_Store((ILM_LValue *)(node->expr1), context);
	}
}
#line 1260 "gen_marshal.c"

struct ILM_AssignCtor_vtable__ const ILM_AssignCtor_vt__ = {
	&ILM_Binary_vt__,
	ILM_AssignCtor_kind,
	"ILM_AssignCtor",
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Binary_ILM_AllocLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_Binary_ILM_ClearLocals__,
	(void (*)(ILM_Node *this__, ILM_Context * context))ILM_AssignCtor_ILM_GenValue__,
};

ILM_Node *ILM_FfiThread_create(ILM_State *state__)
{
	ILM_FfiThread *node__ = (ILM_FfiThread *)ILM_nodealloc(state__, sizeof(struct ILM_FfiThread__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_FfiThread_vt__;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_FfiThis_create(ILM_State *state__)
{
	ILM_FfiThis *node__ = (ILM_FfiThis *)ILM_nodealloc(state__, sizeof(struct ILM_FfiThis__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_FfiThis_vt__;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_FfiArgument_create(ILM_State *state__, ILM_Node * expr, ILType * type)
{
	ILM_FfiArgument *node__ = (ILM_FfiArgument *)ILM_nodealloc(state__, sizeof(struct ILM_FfiArgument__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_FfiArgument_vt__;
	node__->expr = expr;
	node__->type = type;
	node__->localNum = IL_MAX_UINT32;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_FfiReturnArgument_create(ILM_State *state__, ILType * type, ILM_Node * returnLocal)
{
	ILM_FfiReturnArgument *node__ = (ILM_FfiReturnArgument *)ILM_nodealloc(state__, sizeof(struct ILM_FfiReturnArgument__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_FfiReturnArgument_vt__;
	node__->type = type;
	node__->returnLocal = returnLocal;
	node__->localNum = IL_MAX_UINT32;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_FfiReturn_create(ILM_State *state__, ILType * type, ILM_Node * returnLocal)
{
	ILM_FfiReturn *node__ = (ILM_FfiReturn *)ILM_nodealloc(state__, sizeof(struct ILM_FfiReturn__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_FfiReturn_vt__;
	node__->type = type;
	node__->returnLocal = returnLocal;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_FfiCall_create(ILM_State *state__, void * fn, void * cif, void * ctorfn, void * ctorcif)
{
	ILM_FfiCall *node__ = (ILM_FfiCall *)ILM_nodealloc(state__, sizeof(struct ILM_FfiCall__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_FfiCall_vt__;
	node__->fn = fn;
	node__->cif = cif;
	node__->ctorfn = ctorfn;
	node__->ctorcif = ctorcif;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_TryFinally_create(ILM_State *state__, ILM_Node * tryBlock, ILM_Node * finallyBlock, ILM_Node * returnExpr, ILType * returnType)
{
	ILM_TryFinally *node__ = (ILM_TryFinally *)ILM_nodealloc(state__, sizeof(struct ILM_TryFinally__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_TryFinally_vt__;
	node__->tryBlock = tryBlock;
	node__->finallyBlock = finallyBlock;
	node__->returnExpr = returnExpr;
	node__->returnType = returnType;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_Compound_create(ILM_State *state__)
{
	ILM_Compound *node__ = (ILM_Compound *)ILM_nodealloc(state__, sizeof(struct ILM_Compound__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Compound_vt__;
	node__->stmts = 0;
	node__->last = 0;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_Argument_create(ILM_State *state__, ILType * type, ILUInt32 argNum)
{
	ILM_Argument *node__ = (ILM_Argument *)ILM_nodealloc(state__, sizeof(struct ILM_Argument__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Argument_vt__;
	node__->type = type;
	node__->argNum = argNum;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_Local_create(ILM_State *state__, ILType * type)
{
	ILM_Local *node__ = (ILM_Local *)ILM_nodealloc(state__, sizeof(struct ILM_Local__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Local_vt__;
	node__->type = type;
	node__->localNum = IL_MAX_UINT32;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_Field_create(ILM_State *state__, ILM_Node * expr, ILField * field)
{
	ILM_Field *node__ = (ILM_Field *)ILM_nodealloc(state__, sizeof(struct ILM_Field__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Field_vt__;
	node__->expr = expr;
	node__->field = field;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_ArgumentCtor_create(ILM_State *state__, ILType * type, ILUInt32 argNum)
{
	ILM_ArgumentCtor *node__ = (ILM_ArgumentCtor *)ILM_nodealloc(state__, sizeof(struct ILM_ArgumentCtor__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_ArgumentCtor_vt__;
	node__->type = type;
	node__->argNum = argNum;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_Return_create(ILM_State *state__, ILM_Node * expr, ILType * type)
{
	ILM_Return *node__ = (ILM_Return *)ILM_nodealloc(state__, sizeof(struct ILM_Return__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Return_vt__;
	node__->expr = expr;
	node__->type = type;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_ReturnCtor_create(ILM_State *state__, ILM_Node * expr)
{
	ILM_ReturnCtor *node__ = (ILM_ReturnCtor *)ILM_nodealloc(state__, sizeof(struct ILM_ReturnCtor__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_ReturnCtor_vt__;
	node__->expr = expr;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_Convert_create(ILM_State *state__, ILM_Node * expr, int opcode)
{
	ILM_Convert *node__ = (ILM_Convert *)ILM_nodealloc(state__, sizeof(struct ILM_Convert__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Convert_vt__;
	node__->expr = expr;
	node__->opcode = opcode;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_ConvertCustom_create(ILM_State *state__, ILM_Node * expr, int opcode, ILUInt32 customNameLen, ILUInt32 customCookieLen, void * customName, void * customCookie)
{
	ILM_ConvertCustom *node__ = (ILM_ConvertCustom *)ILM_nodealloc(state__, sizeof(struct ILM_ConvertCustom__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_ConvertCustom_vt__;
	node__->expr = expr;
	node__->opcode = opcode;
	node__->customNameLen = customNameLen;
	node__->customCookieLen = customCookieLen;
	node__->customName = customName;
	node__->customCookie = customCookie;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_AddressOf_create(ILM_State *state__, ILM_Node * expr, ILType * type)
{
	ILM_AddressOf *node__ = (ILM_AddressOf *)ILM_nodealloc(state__, sizeof(struct ILM_AddressOf__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_AddressOf_vt__;
	node__->expr = expr;
	node__->type = type;
	node__->localNum = IL_MAX_UINT32;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_Method_create(ILM_State *state__, ILM_Node * expr)
{
	ILM_Method *node__ = (ILM_Method *)ILM_nodealloc(state__, sizeof(struct ILM_Method__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Method_vt__;
	node__->expr = expr;
	return (ILM_Node *)node__;
}

ILM_CompoundStmt *ILM_CompoundStmt_create(ILM_State *state__, ILM_Node * expr)
{
	ILM_CompoundStmt *node__ = (ILM_CompoundStmt *)ILM_nodealloc(state__, sizeof(struct ILM_CompoundStmt__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_CompoundStmt_vt__;
	node__->expr = expr;
	node__->next = 0;
	return (ILM_CompoundStmt *)node__;
}

ILM_Node *ILM_Assign_create(ILM_State *state__, ILM_Node * expr1, ILM_Node * expr2)
{
	ILM_Assign *node__ = (ILM_Assign *)ILM_nodealloc(state__, sizeof(struct ILM_Assign__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_Assign_vt__;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILM_Node *)node__;
}

ILM_Node *ILM_AssignCtor_create(ILM_State *state__, ILM_Node * expr1, ILM_Node * expr2)
{
	ILM_AssignCtor *node__ = (ILM_AssignCtor *)ILM_nodealloc(state__, sizeof(struct ILM_AssignCtor__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILM_AssignCtor_vt__;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILM_Node *)node__;
}

struct ILM__vtable__ {
	const struct ILM__vtable__ *parent__;
	int kind__;
};

int ILM_isa__(const void *vtable__, int kind__)
{
	const struct ILM__vtable__ *vt;
	vt = (const struct ILM__vtable__ *)vtable__;
	while(vt != 0) {
		if(vt->kind__ == kind__)
			return 1;
		vt = vt->parent__;
	}
	return 0;
}

#line 839 "./gen_marshal.tc"


/*
 * Add a member to a compound statement.
 */
static void ILM_Compound_Add(ILM_State *state, ILM_Node *compound,
							 ILM_Node *stmt)
{
	if(compound && stmt)
	{
		ILM_Compound *cmp = (ILM_Compound *)compound;
		ILM_CompoundStmt *wrapper;
		wrapper = ILM_CompoundStmt_create(state, stmt);
		if(wrapper)
		{
			if(cmp->last)
			{
				cmp->last->next = wrapper;
			}
			else
			{
				cmp->stmts = wrapper;
			}
			cmp->last = wrapper;
		}
	}
}

/*
 * Import from "cvmc_setup.c".
 */
int _ILCVMCanUseRawCalls(ILMethod *method, int isInternal);

/*
 * Augmented ILM_State, including an out of memory indicator.
 */
typedef struct
{
	ILM_State	state;
	int			outOfMemory;

} ILM_State_Ext;

/*
 * Initialize the native method compilation state.
 */
static void InitNativeMethod(ILM_Context *context, ILM_State_Ext *state,
							 ILCoder *coder, ILMethod *method)
{
	ILM_nodeinit(&(state->state));
	state->outOfMemory = 0;
	context->coder = coder;
	context->method = method;
	context->signature = ILMethod_Signature(method);
	context->isInternal = ILMethod_IsInternalCall(method);
	context->useRawCalls = _ILCVMCanUseRawCalls(method, context->isInternal);
	context->isConstructor = 0;
	context->hasReturn = 0;
	context->mayBeCtor = ILMethodIsConstructor(method);
}

/*
 * Shutdown the native method compilation state.
 */
static void ShutdownNativeMethod(ILM_State *state)
{
	ILM_nodeclear(state);
}

/*
 * Marshal a native method parameter.
 */
static ILM_Node *MarshalNativeParameter(ILM_Context *context, ILM_State *state,
										unsigned long paramNum,
										ILType *argType, ILM_Node *node,
										ILM_Node *cleanup, ILPInvoke *pinv)
{
#ifdef IL_CONFIG_PINVOKE
	ILUInt32 marshalType;
	char *customName;
	int customNameLen;
	char *customCookie;
	int customCookieLen;
#endif

	/* Resolve enumerated type references first */
	argType = ILTypeGetEnumType(argType);

	/* Value types are passed by reference to internalcalls */
	if(context->isInternal && ILType_IsValueType(argType))
	{
		node = ILM_AddressOf_create(state, node, argType);
	}

#ifdef IL_CONFIG_PINVOKE

	/* Process the PInvoke marshalling information */
	if(!(context->isInternal) &&
	   (marshalType = ILPInvokeGetMarshalType(pinv, context->method, paramNum,
	   										  &customName, &customNameLen,
											  &customCookie,
											  &customCookieLen, argType))
			!= IL_META_MARSHAL_DIRECT)
	{
		switch(marshalType)
		{
			case IL_META_MARSHAL_ANSI_STRING:
			{
				node = ILM_Convert_create(state, node, COP_PREFIX_STR2ANSI);
			}
			break;

			case IL_META_MARSHAL_UTF8_STRING:
			{
				node = ILM_Convert_create(state, node, COP_PREFIX_STR2UTF8);
			}
			break;

			case IL_META_MARSHAL_UTF16_STRING:
			{
				node = ILM_Convert_create(state, node, COP_PREFIX_STR2UTF16);
			}
			break;

			case IL_META_MARSHAL_FNPTR:
			{
				node = ILM_Convert_create
					(state, node, COP_PREFIX_DELEGATE2FNPTR);
			}
			break;

			case IL_META_MARSHAL_ARRAY:
			{
				node = ILM_Convert_create(state, node, COP_PREFIX_ARRAY2PTR);
			}
			break;

			case IL_META_MARSHAL_REF_ANSI_ARRAY:
			{
				node = ILM_Convert_create
					(state, node, COP_PREFIX_REFARRAY2ANSI);
			}
			break;

			case IL_META_MARSHAL_REF_UTF8_ARRAY:
			{
				node = ILM_Convert_create
					(state, node, COP_PREFIX_REFARRAY2UTF8);
			}
			break;

			case IL_META_MARSHAL_CUSTOM:
			{
				node = ILM_ConvertCustom_create
					(state, node, COP_PREFIX_TOCUSTOM,
				     (ILUInt32)(ILInt32)customNameLen,
				     (ILUInt32)(ILInt32)customCookieLen,
				     (void *)customName,
				     (void *)customCookie);
			}
			break;

			case IL_META_MARSHAL_ANSI_ARRAY:
			{
				node = ILM_Convert_create
					(state, node, COP_PREFIX_ARRAY2ANSI);
			}
			break;

			case IL_META_MARSHAL_UTF8_ARRAY:
			{
				node = ILM_Convert_create
					(state, node, COP_PREFIX_ARRAY2UTF8);
			}
			break;
		}
	}

#endif /* IL_CONFIG_PINVOKE */

	/* Return the adjusted node to the caller */
	return node;
}

/*
 * Marshal a native method return.
 */
static ILM_Node *MarshalNativeReturn(ILM_Context *context, ILM_State *state,
									 ILType *returnType, ILM_Node *node,
									 ILM_Node *cleanup)
{
	/* TODO */
	return node;
}

/*
 * Compile a native method declaration to a node tree.
 */
static ILM_Node *CompileNativeMethod(ILM_Context *context, ILM_State *state,
									 void *fn, void *cif,
									 void *ctorfn, void *ctorcif)
{
	ILType *signature = context->signature;
	ILType *returnType = ILTypeGetReturn(signature);
	ILM_Node *compound;
	ILM_Node *cleanup;
	ILM_Node *returnLocal;
	ILM_Node *exceptReturn;
	unsigned long numParams;
	unsigned long paramNum;
	ILUInt32 argNum;
	ILType *argType;
	ILM_Node *argNode;
	ILPInvoke *pinv;

	/* Create the main compound statement for the method */
	compound = ILM_Compound_create(state);

	/* Create the cleanup compound statement for the method */
	cleanup = ILM_Compound_create(state);

	/* Push the thread information first */
	ILM_Compound_Add(state, compound, ILM_FfiThread_create(state));

	/* Push the "this" information next */
	ILM_Compound_Add(state, compound, ILM_FfiThis_create(state));

	/* Get the PInvoke information for the method */
	if(context->isInternal)
	{
		pinv = 0;
	}
	else
	{
		pinv = ILPInvokeFind(context->method);
	}

	/* Create a local variable to hold the return value */
	/* TODO: the type may be different if it is structure-marshalled */
	if(context->mayBeCtor)
	{
		returnLocal = ILM_Local_create(state, ILType_Int);
	}
	else
	{
		returnLocal = ILM_Local_create(state, returnType);
	}

	/* Push return argument information if necessary */
	ILM_Compound_Add(state, compound, ILM_FfiReturnArgument_create
			(state, returnType, returnLocal));

	/* Push the arguments for the native method */
	numParams = ILTypeNumParams(signature);
	if(ILType_HasThis(signature))
	{
		argNum = 1;
	}
	else
	{
		argNum = 0;
	}
	for(paramNum = 1; paramNum <= numParams; ++paramNum)
	{
		argType = ILTypeGetParam(signature, paramNum);
		if(context->mayBeCtor)
		{
			argNode = ILM_ArgumentCtor_create(state, argType, argNum);
		}
		else
		{
			argNode = ILM_Argument_create(state, argType, argNum);
		}
		argNode = MarshalNativeParameter
			(context, state, paramNum, argType, argNode, cleanup, pinv);
		ILM_Compound_Add(state, compound, argNode);
		++argNum;
	}

	/* Push the address of the return local */
	ILM_Compound_Add(state, compound, ILM_FfiReturn_create
			(state, returnType, returnLocal));

	/* Call the method using "libffi" */
	ILM_Compound_Add
		(state, compound, ILM_FfiCall_create(state, fn, cif, ctorfn, ctorcif));

	/* De-marshal the return value */
	if(!(context->mayBeCtor) && returnType != ILType_Void)
	{
		argNode = MarshalNativeReturn
			(context, state, returnType, returnLocal, cleanup);
	}
	else
	{
		argNode = returnLocal;
	}

	/* Push the value on the stack and return */
	exceptReturn = 0;
	if(cleanup && ((ILM_Compound *)cleanup)->stmts)
	{
		if(context->mayBeCtor)
		{
			exceptReturn = ILM_Local_create(state, ILType_Int);
			ILM_Compound_Add
				(state, compound, ILM_AssignCtor_create
						(state, exceptReturn, argNode));
		}
		else if(returnType != ILType_Void)
		{
			exceptReturn = ILM_Local_create(state, returnType);
			ILM_Compound_Add
				(state, compound, ILM_Assign_create
						(state, exceptReturn, argNode));
		}
	}
	else if(context->mayBeCtor)
	{
		ILM_Compound_Add
			(state, compound, ILM_ReturnCtor_create(state, argNode));
	}
	else
	{
		ILM_Compound_Add
			(state, compound, ILM_Return_create(state, argNode, returnType));
	}

	/* Wrap the method in a "try ... finally ..." block if there
	   are cleanup operations that need to be performed */
	if(cleanup && ((ILM_Compound *)cleanup)->stmts)
	{
		compound = ILM_TryFinally_create
			(state, compound, cleanup, exceptReturn, returnType);
	}
	else
	{
		compound = ILM_Method_create(state, compound);
	}

	/* Return the compound statement to the caller */
	return compound;
}

/*
 * Handle out of memory conditions from the treecc node allocator.
 */
void ILM_nodefailed(ILM_State *state)
{
	((ILM_State_Ext *)state)->outOfMemory = 1;
}

/*
 * Convert a PInvoke or internalcall method declaration into code.
 */
int _ILMarshalSetupExtern(ILCoder *coder, unsigned char **start,
						  ILMethod *method, void *fn, void *cif)
{
	ILM_Context context;
	ILM_State_Ext state;
	ILM_Node *node;

	/* Initialize the native method state */
	InitNativeMethod(&context, &state, coder, method);

	/* Compile the method into a treecc node tree */
	node = CompileNativeMethod(&context, &(state.state), fn, cif, 0, 0);
	if(state.outOfMemory)
	{
		ShutdownNativeMethod(&(state.state));
		return 0;
	}

	/* TODO: method header code */

	/* Allocate the local variables */
	ILM_AllocLocals(node, &context);

	/* Generate the code */
	ILM_GenValue(node, &context);

	/* TODO: method footer code */

	/* Clean up and exit */
	ShutdownNativeMethod(&(state.state));
	return 0;
}

/*
 * Convert a PInvoke or internalcall constructor declaration into code.
 */
int _ILMarshalSetupExternCtor(ILCoder *coder, unsigned char **start,
						      ILMethod *method, void *fn, void *cif,
						      void *ctorfn, void *ctorcif)
{
	ILM_Context context;
	ILM_State_Ext state;
	ILM_Node *node;

	/* Initialize the native method state */
	InitNativeMethod(&context, &state, coder, method);

	/* Compile the method into a treecc node tree */
	node = CompileNativeMethod(&context, &(state.state),
							   fn, cif, ctorfn, ctorcif);
	if(state.outOfMemory)
	{
		ShutdownNativeMethod(&(state.state));
		return 0;
	}

	/* TODO: output the constructor jump-over block */

	/* TODO: method header code */

	/* Allocate the local variables */
	ILM_AllocLocals(node, &context);

	/* Generate the code */
	ILM_GenValue(node, &context);

	/* Reset for the constructor form of the method */
	ILM_ClearLocals(node, &context);
	context.isConstructor = 1;
	ILM_AllocLocals(node, &context);

	/* Generate the constructor code */
	ILM_GenValue(node, &context);

	/* TODO: method footer code */

	/* Clean up and exit */
	ShutdownNativeMethod(&(state.state));
	return 0;
}

#line 1940 "gen_marshal.c"
