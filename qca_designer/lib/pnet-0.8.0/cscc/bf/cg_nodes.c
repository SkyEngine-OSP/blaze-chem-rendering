/* cg_nodes.c.  Generated automatically by treecc */
#line 4 "cg_nodes.tc"

/*
 * cg_nodes.tc - Declare common nodes and operations.
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
#line 42 "cg_nodes.tc"

#include <codegen/cg_nodes.h>
#line 27 "cg_nodes.c"

#define YYNODESTATE_TRACK_LINES 1
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

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * The fixed global state to use for non-reentrant allocation.
 */
#ifndef YYNODESTATE_REENTRANT
static YYNODESTATE fixed_state__;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	((unsigned)(&(((struct _YYNODESTATE_align_##type *)0)->field)))
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Initialize the node allocation pool.
 */
#ifdef YYNODESTATE_REENTRANT
void yynodeinit(state__)
YYNODESTATE *state__;
{
#else
void yynodeinit()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	state__->blocks__ = 0;
	state__->push_stack__ = 0;
	state__->used__ = 0;
}

/*
 * Allocate a block of memory.
 */
#ifdef YYNODESTATE_REENTRANT
void *yynodealloc(state__, size__)
YYNODESTATE *state__;
unsigned int size__;
{
#else
void *yynodealloc(size__)
unsigned int size__;
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = state__->blocks__;
	if(!block__ || (state__->used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = (struct YYNODESTATE_block *)
						malloc(sizeof(struct YYNODESTATE_block));
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   supply the "yynodefailed" function to report the
			   out of memory state and/or abort the program */
#ifdef YYNODESTATE_REENTRANT
			yynodefailed(state__);
#else
			yynodefailed();
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
#ifdef YYNODESTATE_REENTRANT
int yynodepush(state__)
YYNODESTATE *state__;
{
#else
int yynodepush()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = state__->blocks__;
	saved_used__ = state__->used__;

	/* Allocate space for a push item */
#ifdef YYNODESTATE_REENTRANT
	push_item__ = (struct YYNODESTATE_push *)
			yynodealloc(state__, sizeof(struct YYNODESTATE_push));
#else
	push_item__ = (struct YYNODESTATE_push *)
			yynodealloc(sizeof(struct YYNODESTATE_push));
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
#ifdef YYNODESTATE_REENTRANT
void yynodepop(state__)
YYNODESTATE *state__;
{
#else
void yynodepop()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

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
#ifdef YYNODESTATE_REENTRANT
void yynodeclear(state__)
YYNODESTATE *state__;
{
#else
void yynodeclear()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_block *temp_block__;
	while(state__->blocks__ != 0)
	{
		temp_block__ = state__->blocks__;
		state__->blocks__ = temp_block__->next__;
		free(temp_block__);
	}
	state__->push_stack__ = 0;
	state__->used__ = 0;
}
#line 295 "cg_nodes.c"
int ILNode_ILNode_EndsInReturnImpl__(ILNode *node, ILGenInfo * info)
#line 1287 "cg_nodes.tc"
{
	return 0;
}
#line 301 "cg_nodes.c"

struct ILNode_vtable__ const ILNode_vt__ = {
	0,
	ILNode_kind,
	"ILNode",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info))0,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))0,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))0,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))0,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))0,
};

ILMachineType ILNode_Dummy_ILNode_GetType__(ILNode_Dummy *node, ILGenInfo * info)
#line 1030 "cg_nodes.tc"
{
	fprintf(stderr, "GetType is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
	return ILMachineType_Void; 
}
#line 328 "cg_nodes.c"

void ILNode_Dummy_ILNode_GenDiscard__(ILNode_Dummy *node, ILGenInfo * info)
#line 1037 "cg_nodes.tc"
{
	fprintf(stderr, "GenDiscard is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 337 "cg_nodes.c"

ILMachineType ILNode_Dummy_ILNode_GenValue__(ILNode_Dummy *node, ILGenInfo * info)
#line 1043 "cg_nodes.tc"
{
	fprintf(stderr, "GenValue is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
	return ILMachineType_Void; /* Not reached */
}
#line 347 "cg_nodes.c"

void ILNode_Dummy_ILNode_GenThen__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label)
#line 1050 "cg_nodes.tc"
{
	fprintf(stderr, "GenThen is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 356 "cg_nodes.c"

void ILNode_Dummy_ILNode_GenElse__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label)
#line 1056 "cg_nodes.tc"
{
	fprintf(stderr, "GenElse is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 365 "cg_nodes.c"

int ILNode_Dummy_ILNode_EvalConst__(ILNode_Dummy *node, ILGenInfo * info, ILEvalValue * value)
#line 1062 "cg_nodes.tc"
{
	fprintf(stderr, "EvalConst is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
	return 0; /* Not reached */
}
#line 375 "cg_nodes.c"

void ILNode_Dummy_JavaGenDiscard__(ILNode_Dummy *node, ILGenInfo * info)
#line 309 "jv_nodes.tc"
{
	fprintf(stderr, "JavaGenDiscard is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 384 "cg_nodes.c"

ILMachineType ILNode_Dummy_JavaGenValue__(ILNode_Dummy *node, ILGenInfo * info)
#line 315 "jv_nodes.tc"
{
	fprintf(stderr, "JavaGenValue is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
	return ILMachineType_Void; /* Not reached */
}
#line 394 "cg_nodes.c"

void ILNode_Dummy_JavaGenThen__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label)
#line 322 "jv_nodes.tc"
{
	fprintf(stderr, "JavaGenThen is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 403 "cg_nodes.c"

void ILNode_Dummy_JavaGenElse__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label)
#line 328 "jv_nodes.tc"
{
	fprintf(stderr, "JavaGenElse is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 412 "cg_nodes.c"

struct ILNode_Dummy_vtable__ const ILNode_Dummy_vt__ = {
	&ILNode_vt__,
	ILNode_Dummy_kind,
	"ILNode_Dummy",
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

void ILNode_Expression_ILNode_GenDiscard__(ILNode_Expression *node, ILGenInfo * info)
#line 1073 "cg_nodes.tc"
{
	ILMachineType type = ILNode_GenValue(node, info);
	ILGenCast(info, type, ILMachineType_Void);
}
#line 437 "cg_nodes.c"

void ILNode_Expression_ILNode_GenThen__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label)
#line 1224 "cg_nodes.tc"
{
	ILMachineType type = ILNode_GenValue(node, info);
	ILNodeStackThen(info, label, type);
}
#line 445 "cg_nodes.c"

void ILNode_Expression_ILNode_GenElse__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label)
#line 1233 "cg_nodes.tc"
{
	ILMachineType type = ILNode_GenValue(node, info);
	ILNodeStackElse(info, label, type);
}
#line 453 "cg_nodes.c"

int ILNode_Expression_ILNode_EvalConst__(ILNode_Expression *node, ILGenInfo * info, ILEvalValue * value)
#line 1242 "cg_nodes.tc"
{
	return 0;
}
#line 460 "cg_nodes.c"

void ILNode_Expression_JavaGenDiscard__(ILNode_Expression *node, ILGenInfo * info)
#line 259 "jv_nodes.tc"
{
	ILMachineType type = JavaGenValue(node, info);
	JavaGenCast(info, type, ILMachineType_Void);
}
#line 468 "cg_nodes.c"

void ILNode_Expression_JavaGenThen__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label)
#line 268 "jv_nodes.tc"
{
	ILMachineType type = JavaGenValue(node, info);
	JavaStackThen(info, label, type);
}
#line 476 "cg_nodes.c"

void ILNode_Expression_JavaGenElse__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label)
#line 277 "jv_nodes.tc"
{
	ILMachineType type = JavaGenValue(node, info);
	JavaStackElse(info, label, type);
}
#line 484 "cg_nodes.c"

struct ILNode_Expression_vtable__ const ILNode_Expression_vt__ = {
	&ILNode_vt__,
	ILNode_Expression_kind,
	"ILNode_Expression",
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
};

ILMachineType ILNode_Statement_ILNode_GetType__(ILNode_Statement *node, ILGenInfo * info)
#line 1003 "cg_nodes.tc"
{
	return ILMachineType_Void;
}
#line 508 "cg_nodes.c"

ILMachineType ILNode_Statement_ILNode_GenValue__(ILNode_Statement *node, ILGenInfo * info)
#line 1007 "cg_nodes.tc"
{
	ILNode_GenDiscard(node, info);
	return ILMachineType_Void;
}
#line 516 "cg_nodes.c"

void ILNode_Statement_ILNode_GenThen__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label)
#line 1012 "cg_nodes.tc"
{
	ILMachineType type = ILNode_GenValue(node, info);
	ILNodeStackThen(info, label, type);
}
#line 524 "cg_nodes.c"

void ILNode_Statement_ILNode_GenElse__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label)
#line 1017 "cg_nodes.tc"
{
	ILMachineType type = ILNode_GenValue(node, info);
	ILNodeStackElse(info, label, type);
}
#line 532 "cg_nodes.c"

int ILNode_Statement_ILNode_EvalConst__(ILNode_Statement *node, ILGenInfo * info, ILEvalValue * value)
#line 1022 "cg_nodes.tc"
{
	return 0;
}
#line 539 "cg_nodes.c"

ILMachineType ILNode_Statement_JavaGenValue__(ILNode_Statement *node, ILGenInfo * info)
#line 286 "jv_nodes.tc"
{
	fprintf(stderr, "JavaGenDiscard is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
	return ILMachineType_Void; /* Not reached */
}
#line 549 "cg_nodes.c"

void ILNode_Statement_JavaGenThen__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label)
#line 293 "jv_nodes.tc"
{
	fprintf(stderr, "JavaGenThen is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 558 "cg_nodes.c"

void ILNode_Statement_JavaGenElse__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label)
#line 299 "jv_nodes.tc"
{
	fprintf(stderr, "JavaGenElse is not implemented for node type `%s'",
			yykindname(node));
	exit(1);
}
#line 567 "cg_nodes.c"

struct ILNode_Statement_vtable__ const ILNode_Statement_vt__ = {
	&ILNode_vt__,
	ILNode_Statement_kind,
	"ILNode_Statement",
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

void ILNode_Constant_ILNode_GenDiscard__(ILNode_Constant *node, ILGenInfo * info)
#line 31 "cg_const.tc"
{
	/* Nothing to do here */
}
#line 591 "cg_nodes.c"

void ILNode_Constant_JavaGenDiscard__(ILNode_Constant *node, ILGenInfo * info)
#line 25 "jv_const.tc"
{
	/* Nothing to do here */
}
#line 598 "cg_nodes.c"

struct ILNode_Constant_vtable__ const ILNode_Constant_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_Constant_kind,
	"ILNode_Constant",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Constant_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))0,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_LValue_vtable__ const ILNode_LValue_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_LValue_kind,
	"ILNode_LValue",
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

struct ILNode_UnaryExpression_vtable__ const ILNode_UnaryExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_UnaryExpression_kind,
	"ILNode_UnaryExpression",
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
};

struct ILNode_BinaryExpression_vtable__ const ILNode_BinaryExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_BinaryExpression_kind,
	"ILNode_BinaryExpression",
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
};

struct ILNode_TernaryExpression_vtable__ const ILNode_TernaryExpression_vt__ = {
	&ILNode_Expression_vt__,
	ILNode_TernaryExpression_kind,
	"ILNode_TernaryExpression",
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
};

void ILNode_LValueNoRef_ILNode_GenRef__(ILNode_LValueNoRef *node, ILGenInfo * info)
#line 1279 "cg_nodes.tc"
{
	/* Nothing to do here */
}
#line 697 "cg_nodes.c"

struct ILNode_LValueNoRef_vtable__ const ILNode_LValueNoRef_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_LValueNoRef_kind,
	"ILNode_LValueNoRef",
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
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRef_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))0,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))0,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))0,
};

struct ILNode_LValueUnaryExpr_vtable__ const ILNode_LValueUnaryExpr_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_LValueUnaryExpr_kind,
	"ILNode_LValueUnaryExpr",
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

struct ILNode_LValueBinaryExpr_vtable__ const ILNode_LValueBinaryExpr_vt__ = {
	&ILNode_LValue_vt__,
	ILNode_LValueBinaryExpr_kind,
	"ILNode_LValueBinaryExpr",
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

void ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__(ILNode_LValueNoRefUnaryExpr *node, ILGenInfo * info)
#line 1279 "cg_nodes.tc"
{
	/* Nothing to do here */
}
#line 776 "cg_nodes.c"

struct ILNode_LValueNoRefUnaryExpr_vtable__ const ILNode_LValueNoRefUnaryExpr_vt__ = {
	&ILNode_LValueUnaryExpr_vt__,
	ILNode_LValueNoRefUnaryExpr_kind,
	"ILNode_LValueNoRefUnaryExpr",
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
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))0,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))0,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))0,
};

ILMachineType ILNode_DummyUnaryExpr_ILNode_GetType__(ILNode_DummyUnaryExpr *node, ILGenInfo * info)
#line 1264 "cg_nodes.tc"
{
	return ILMachineType_Void;
}
#line 807 "cg_nodes.c"

ILMachineType ILNode_DummyUnaryExpr_ILNode_GenValue__(ILNode_DummyUnaryExpr *node, ILGenInfo * info)
#line 1269 "cg_nodes.tc"
{
	return ILMachineType_Void;
}
#line 814 "cg_nodes.c"

ILMachineType ILNode_DummyUnaryExpr_JavaGenValue__(ILNode_DummyUnaryExpr *node, ILGenInfo * info)
#line 347 "jv_nodes.tc"
{
	return ILMachineType_Void;
}
#line 821 "cg_nodes.c"

struct ILNode_DummyUnaryExpr_vtable__ const ILNode_DummyUnaryExpr_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_DummyUnaryExpr_kind,
	"ILNode_DummyUnaryExpr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DummyUnaryExpr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DummyUnaryExpr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DummyUnaryExpr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_DummyBinaryExpr_ILNode_GetType__(ILNode_DummyBinaryExpr *node, ILGenInfo * info)
#line 1264 "cg_nodes.tc"
{
	return ILMachineType_Void;
}
#line 845 "cg_nodes.c"

ILMachineType ILNode_DummyBinaryExpr_ILNode_GenValue__(ILNode_DummyBinaryExpr *node, ILGenInfo * info)
#line 1269 "cg_nodes.tc"
{
	return ILMachineType_Void;
}
#line 852 "cg_nodes.c"

ILMachineType ILNode_DummyBinaryExpr_JavaGenValue__(ILNode_DummyBinaryExpr *node, ILGenInfo * info)
#line 347 "jv_nodes.tc"
{
	return ILMachineType_Void;
}
#line 859 "cg_nodes.c"

struct ILNode_DummyBinaryExpr_vtable__ const ILNode_DummyBinaryExpr_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_DummyBinaryExpr_kind,
	"ILNode_DummyBinaryExpr",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DummyBinaryExpr_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DummyBinaryExpr_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_DummyBinaryExpr_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_List_ILNode_GetType__(ILNode_List *node, ILGenInfo * info)
#line 360 "cg_stmt.tc"
{
	ILNode_ListIter iter;
	ILNode *last = 0;
	ILNode *stmt;
	ILNode_ListIter_Init(&iter, node);
	while((stmt = ILNode_ListIter_Next(&iter)) != 0)
	{
		if(!yyisa(stmt, ILNode_Empty))
		{
			last = stmt;
		}
	}
	if(last)
	{
		return ILNode_GetType(last, info);
	}
	else
	{
		return ILMachineType_Void;
	}
}
#line 901 "cg_nodes.c"

void ILNode_List_ILNode_GenDiscard__(ILNode_List *node, ILGenInfo * info)
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
#line 915 "cg_nodes.c"

ILMachineType ILNode_List_ILNode_GenValue__(ILNode_List *node, ILGenInfo * info)
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
#line 939 "cg_nodes.c"

int ILNode_List_ILNode_EndsInReturnImpl__(ILNode_List *node, ILGenInfo * info)
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
#line 959 "cg_nodes.c"

void ILNode_List_JavaGenDiscard__(ILNode_List *node, ILGenInfo * info)
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
#line 973 "cg_nodes.c"

struct ILNode_List_vtable__ const ILNode_List_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_List_kind,
	"ILNode_List",
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

ILNode *ILNode_List_create(void)
{
	ILNode_List *node__ = (ILNode_List *)yynodealloc(sizeof(struct ILNode_List__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_List_vt__;
	node__->kind__ = ILNode_List_kind;
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

struct yy_vtable__ {
	const struct yy_vtable__ *parent__;
	int kind__;
};

int yyisa__(const void *vtable__, int kind__)
{
	const struct yy_vtable__ *vt;
	vt = (const struct yy_vtable__ *)vtable__;
	while(vt != 0) {
		if(vt->kind__ == kind__)
			return 1;
		vt = vt->parent__;
	}
	return 0;
}

