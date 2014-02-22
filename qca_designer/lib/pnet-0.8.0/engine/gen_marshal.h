/* gen_marshal.h.  Generated automatically by treecc */
#ifndef __ILM__gen_marshal_h
#define __ILM__gen_marshal_h
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
#line 33 "./gen_marshal.tc"


#include "engine.h"

/*
 * Declare the "ILM_Context" structure.
 */
typedef struct
{
	ILCoder		   *coder;			/* Coder to write the final code to */
	ILMethod	   *method;			/* The method being converted */
	ILType		   *signature;		/* The method signature */
	int				isInternal;		/* This is an internalcall method */
	int				useRawCalls;	/* Non-zero to use raw libffi calls */
	int				isConstructor;	/* This is a constructor expansion */
	int				hasReturn;		/* Non-zero if a libffi return value */
	int				mayBeCtor;		/* May be a constructor */

} ILM_Context;

#line 47 "gen_marshal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ILM_Node_kind 1
#define ILM_LValue_kind 2
#define ILM_Unary_kind 7
#define ILM_Binary_kind 8
#define ILM_FfiThread_kind 16
#define ILM_FfiThis_kind 17
#define ILM_FfiArgument_kind 18
#define ILM_FfiReturnArgument_kind 19
#define ILM_FfiReturn_kind 20
#define ILM_FfiCall_kind 21
#define ILM_TryFinally_kind 22
#define ILM_Compound_kind 25
#define ILM_Argument_kind 3
#define ILM_Local_kind 5
#define ILM_Field_kind 6
#define ILM_ArgumentCtor_kind 4
#define ILM_Return_kind 11
#define ILM_ReturnCtor_kind 12
#define ILM_Convert_kind 13
#define ILM_ConvertCustom_kind 14
#define ILM_AddressOf_kind 15
#define ILM_Method_kind 23
#define ILM_CompoundStmt_kind 24
#define ILM_Assign_kind 9
#define ILM_AssignCtor_kind 10

typedef struct ILM_Node__ ILM_Node;
typedef struct ILM_LValue__ ILM_LValue;
typedef struct ILM_Unary__ ILM_Unary;
typedef struct ILM_Binary__ ILM_Binary;
typedef struct ILM_FfiThread__ ILM_FfiThread;
typedef struct ILM_FfiThis__ ILM_FfiThis;
typedef struct ILM_FfiArgument__ ILM_FfiArgument;
typedef struct ILM_FfiReturnArgument__ ILM_FfiReturnArgument;
typedef struct ILM_FfiReturn__ ILM_FfiReturn;
typedef struct ILM_FfiCall__ ILM_FfiCall;
typedef struct ILM_TryFinally__ ILM_TryFinally;
typedef struct ILM_Compound__ ILM_Compound;
typedef struct ILM_Argument__ ILM_Argument;
typedef struct ILM_Local__ ILM_Local;
typedef struct ILM_Field__ ILM_Field;
typedef struct ILM_ArgumentCtor__ ILM_ArgumentCtor;
typedef struct ILM_Return__ ILM_Return;
typedef struct ILM_ReturnCtor__ ILM_ReturnCtor;
typedef struct ILM_Convert__ ILM_Convert;
typedef struct ILM_ConvertCustom__ ILM_ConvertCustom;
typedef struct ILM_AddressOf__ ILM_AddressOf;
typedef struct ILM_Method__ ILM_Method;
typedef struct ILM_CompoundStmt__ ILM_CompoundStmt;
typedef struct ILM_Assign__ ILM_Assign;
typedef struct ILM_AssignCtor__ ILM_AssignCtor;

#line 1 "c_skel.h"
typedef struct
{
	struct ILM_State_block *blocks__;
	struct ILM_State_push *push_stack__;
	int used__;

} ILM_State;
#line 113 "gen_marshal.h"
struct ILM_Node__ {
	const struct ILM_Node_vtable__ *vtable__;
};

struct ILM_Node_vtable__ {
	const void *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Node_vtable__ const ILM_Node_vt__;

#define ILM_AllocLocals(this__,context) \
	((*(((struct ILM_Node_vtable__ *)((this__)->vtable__))->ILM_AllocLocals_v__)) \
		((ILM_Node *)(this__), (context)))

#define ILM_ClearLocals(this__,context) \
	((*(((struct ILM_Node_vtable__ *)((this__)->vtable__))->ILM_ClearLocals_v__)) \
		((ILM_Node *)(this__), (context)))

#define ILM_GenValue(this__,context) \
	((*(((struct ILM_Node_vtable__ *)((this__)->vtable__))->ILM_GenValue_v__)) \
		((ILM_Node *)(this__), (context)))

struct ILM_LValue__ {
	const struct ILM_LValue_vtable__ *vtable__;
};

struct ILM_LValue_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_Prepare_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_Store_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_GenRef_v__)(ILM_LValue *this__, ILM_Context * context);
};

extern struct ILM_LValue_vtable__ const ILM_LValue_vt__;

#define ILM_Prepare(this__,context) \
	((*(((struct ILM_LValue_vtable__ *)((this__)->vtable__))->ILM_Prepare_v__)) \
		((ILM_LValue *)(this__), (context)))

#define ILM_Store(this__,context) \
	((*(((struct ILM_LValue_vtable__ *)((this__)->vtable__))->ILM_Store_v__)) \
		((ILM_LValue *)(this__), (context)))

#define ILM_GenRef(this__,context) \
	((*(((struct ILM_LValue_vtable__ *)((this__)->vtable__))->ILM_GenRef_v__)) \
		((ILM_LValue *)(this__), (context)))

struct ILM_Unary__ {
	const struct ILM_Unary_vtable__ *vtable__;
	ILM_Node * expr;
};

struct ILM_Unary_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Unary_vtable__ const ILM_Unary_vt__;

extern void ILM_Unary_ILM_AllocLocals__(ILM_Unary *node, ILM_Context * context);
extern void ILM_Unary_ILM_ClearLocals__(ILM_Unary *node, ILM_Context * context);

struct ILM_Binary__ {
	const struct ILM_Binary_vtable__ *vtable__;
	ILM_Node * expr1;
	ILM_Node * expr2;
};

struct ILM_Binary_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Binary_vtable__ const ILM_Binary_vt__;

extern void ILM_Binary_ILM_AllocLocals__(ILM_Binary *node, ILM_Context * context);
extern void ILM_Binary_ILM_ClearLocals__(ILM_Binary *node, ILM_Context * context);

struct ILM_FfiThread__ {
	const struct ILM_FfiThread_vtable__ *vtable__;
};

struct ILM_FfiThread_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_FfiThread_vtable__ const ILM_FfiThread_vt__;

extern void ILM_FfiThread_ILM_AllocLocals__(ILM_FfiThread *node, ILM_Context * context);
extern void ILM_FfiThread_ILM_ClearLocals__(ILM_FfiThread *node, ILM_Context * context);
extern void ILM_FfiThread_ILM_GenValue__(ILM_FfiThread *node, ILM_Context * context);

struct ILM_FfiThis__ {
	const struct ILM_FfiThis_vtable__ *vtable__;
};

struct ILM_FfiThis_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_FfiThis_vtable__ const ILM_FfiThis_vt__;

extern void ILM_FfiThis_ILM_AllocLocals__(ILM_FfiThis *node, ILM_Context * context);
extern void ILM_FfiThis_ILM_ClearLocals__(ILM_FfiThis *node, ILM_Context * context);
extern void ILM_FfiThis_ILM_GenValue__(ILM_FfiThis *node, ILM_Context * context);

struct ILM_FfiArgument__ {
	const struct ILM_FfiArgument_vtable__ *vtable__;
	ILM_Node * expr;
	ILType * type;
	ILUInt32 localNum;
};

struct ILM_FfiArgument_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_FfiArgument_vtable__ const ILM_FfiArgument_vt__;

extern void ILM_FfiArgument_ILM_AllocLocals__(ILM_FfiArgument *node, ILM_Context * context);
extern void ILM_FfiArgument_ILM_ClearLocals__(ILM_FfiArgument *node, ILM_Context * context);
extern void ILM_FfiArgument_ILM_GenValue__(ILM_FfiArgument *node, ILM_Context * context);

struct ILM_FfiReturnArgument__ {
	const struct ILM_FfiReturnArgument_vtable__ *vtable__;
	ILType * type;
	ILM_Node * returnLocal;
	ILUInt32 localNum;
};

struct ILM_FfiReturnArgument_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_FfiReturnArgument_vtable__ const ILM_FfiReturnArgument_vt__;

extern void ILM_FfiReturnArgument_ILM_AllocLocals__(ILM_FfiReturnArgument *node, ILM_Context * context);
extern void ILM_FfiReturnArgument_ILM_ClearLocals__(ILM_FfiReturnArgument *node, ILM_Context * context);
extern void ILM_FfiReturnArgument_ILM_GenValue__(ILM_FfiReturnArgument *node, ILM_Context * context);

struct ILM_FfiReturn__ {
	const struct ILM_FfiReturn_vtable__ *vtable__;
	ILType * type;
	ILM_Node * returnLocal;
};

struct ILM_FfiReturn_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_FfiReturn_vtable__ const ILM_FfiReturn_vt__;

extern void ILM_FfiReturn_ILM_AllocLocals__(ILM_FfiReturn *node, ILM_Context * context);
extern void ILM_FfiReturn_ILM_ClearLocals__(ILM_FfiReturn *node, ILM_Context * context);
extern void ILM_FfiReturn_ILM_GenValue__(ILM_FfiReturn *node, ILM_Context * context);

struct ILM_FfiCall__ {
	const struct ILM_FfiCall_vtable__ *vtable__;
	void * fn;
	void * cif;
	void * ctorfn;
	void * ctorcif;
};

struct ILM_FfiCall_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_FfiCall_vtable__ const ILM_FfiCall_vt__;

extern void ILM_FfiCall_ILM_AllocLocals__(ILM_FfiCall *node, ILM_Context * context);
extern void ILM_FfiCall_ILM_ClearLocals__(ILM_FfiCall *node, ILM_Context * context);
extern void ILM_FfiCall_ILM_GenValue__(ILM_FfiCall *node, ILM_Context * context);

struct ILM_TryFinally__ {
	const struct ILM_TryFinally_vtable__ *vtable__;
	ILM_Node * tryBlock;
	ILM_Node * finallyBlock;
	ILM_Node * returnExpr;
	ILType * returnType;
};

struct ILM_TryFinally_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_TryFinally_vtable__ const ILM_TryFinally_vt__;

extern void ILM_TryFinally_ILM_AllocLocals__(ILM_TryFinally *node, ILM_Context * context);
extern void ILM_TryFinally_ILM_ClearLocals__(ILM_TryFinally *node, ILM_Context * context);
extern void ILM_TryFinally_ILM_GenValue__(ILM_TryFinally *node, ILM_Context * context);

struct ILM_Compound__ {
	const struct ILM_Compound_vtable__ *vtable__;
	ILM_CompoundStmt * stmts;
	ILM_CompoundStmt * last;
};

struct ILM_Compound_vtable__ {
	const struct ILM_Node_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Compound_vtable__ const ILM_Compound_vt__;

extern void ILM_Compound_ILM_AllocLocals__(ILM_Compound *node, ILM_Context * context);
extern void ILM_Compound_ILM_ClearLocals__(ILM_Compound *node, ILM_Context * context);
extern void ILM_Compound_ILM_GenValue__(ILM_Compound *node, ILM_Context * context);

struct ILM_Argument__ {
	const struct ILM_Argument_vtable__ *vtable__;
	ILType * type;
	ILUInt32 argNum;
};

struct ILM_Argument_vtable__ {
	const struct ILM_LValue_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_Prepare_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_Store_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_GenRef_v__)(ILM_LValue *this__, ILM_Context * context);
};

extern struct ILM_Argument_vtable__ const ILM_Argument_vt__;

extern void ILM_Argument_ILM_AllocLocals__(ILM_Argument *node, ILM_Context * context);
extern void ILM_Argument_ILM_ClearLocals__(ILM_Argument *node, ILM_Context * context);
extern void ILM_Argument_ILM_GenValue__(ILM_Argument *node, ILM_Context * context);
extern void ILM_Argument_ILM_Prepare__(ILM_Argument *node, ILM_Context * context);
extern void ILM_Argument_ILM_Store__(ILM_Argument *node, ILM_Context * context);
extern void ILM_Argument_ILM_GenRef__(ILM_Argument *node, ILM_Context * context);

struct ILM_Local__ {
	const struct ILM_Local_vtable__ *vtable__;
	ILType * type;
	ILUInt32 localNum;
};

struct ILM_Local_vtable__ {
	const struct ILM_LValue_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_Prepare_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_Store_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_GenRef_v__)(ILM_LValue *this__, ILM_Context * context);
};

extern struct ILM_Local_vtable__ const ILM_Local_vt__;

extern void ILM_Local_ILM_AllocLocals__(ILM_Local *node, ILM_Context * context);
extern void ILM_Local_ILM_ClearLocals__(ILM_Local *node, ILM_Context * context);
extern void ILM_Local_ILM_GenValue__(ILM_Local *node, ILM_Context * context);
extern void ILM_Local_ILM_Prepare__(ILM_Local *node, ILM_Context * context);
extern void ILM_Local_ILM_Store__(ILM_Local *node, ILM_Context * context);
extern void ILM_Local_ILM_GenRef__(ILM_Local *node, ILM_Context * context);

struct ILM_Field__ {
	const struct ILM_Field_vtable__ *vtable__;
	ILM_Node * expr;
	ILField * field;
};

struct ILM_Field_vtable__ {
	const struct ILM_LValue_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_Prepare_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_Store_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_GenRef_v__)(ILM_LValue *this__, ILM_Context * context);
};

extern struct ILM_Field_vtable__ const ILM_Field_vt__;

extern void ILM_Field_ILM_AllocLocals__(ILM_Field *node, ILM_Context * context);
extern void ILM_Field_ILM_ClearLocals__(ILM_Field *node, ILM_Context * context);
extern void ILM_Field_ILM_GenValue__(ILM_Field *node, ILM_Context * context);
extern void ILM_Field_ILM_Prepare__(ILM_Field *node, ILM_Context * context);
extern void ILM_Field_ILM_Store__(ILM_Field *node, ILM_Context * context);
extern void ILM_Field_ILM_GenRef__(ILM_Field *node, ILM_Context * context);

struct ILM_ArgumentCtor__ {
	const struct ILM_ArgumentCtor_vtable__ *vtable__;
	ILType * type;
	ILUInt32 argNum;
};

struct ILM_ArgumentCtor_vtable__ {
	const struct ILM_Argument_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_Prepare_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_Store_v__)(ILM_LValue *this__, ILM_Context * context);
	void (*ILM_GenRef_v__)(ILM_LValue *this__, ILM_Context * context);
};

extern struct ILM_ArgumentCtor_vtable__ const ILM_ArgumentCtor_vt__;

extern void ILM_ArgumentCtor_ILM_GenValue__(ILM_ArgumentCtor *node, ILM_Context * context);
extern void ILM_ArgumentCtor_ILM_Prepare__(ILM_ArgumentCtor *node, ILM_Context * context);
extern void ILM_ArgumentCtor_ILM_Store__(ILM_ArgumentCtor *node, ILM_Context * context);
extern void ILM_ArgumentCtor_ILM_GenRef__(ILM_ArgumentCtor *node, ILM_Context * context);

struct ILM_Return__ {
	const struct ILM_Return_vtable__ *vtable__;
	ILM_Node * expr;
	ILType * type;
};

struct ILM_Return_vtable__ {
	const struct ILM_Unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Return_vtable__ const ILM_Return_vt__;

extern void ILM_Return_ILM_GenValue__(ILM_Return *node, ILM_Context * context);

struct ILM_ReturnCtor__ {
	const struct ILM_ReturnCtor_vtable__ *vtable__;
	ILM_Node * expr;
};

struct ILM_ReturnCtor_vtable__ {
	const struct ILM_Unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_ReturnCtor_vtable__ const ILM_ReturnCtor_vt__;

extern void ILM_ReturnCtor_ILM_GenValue__(ILM_ReturnCtor *node, ILM_Context * context);

struct ILM_Convert__ {
	const struct ILM_Convert_vtable__ *vtable__;
	ILM_Node * expr;
	int opcode;
};

struct ILM_Convert_vtable__ {
	const struct ILM_Unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Convert_vtable__ const ILM_Convert_vt__;

extern void ILM_Convert_ILM_GenValue__(ILM_Convert *node, ILM_Context * context);

struct ILM_ConvertCustom__ {
	const struct ILM_ConvertCustom_vtable__ *vtable__;
	ILM_Node * expr;
	int opcode;
	ILUInt32 customNameLen;
	ILUInt32 customCookieLen;
	void * customName;
	void * customCookie;
};

struct ILM_ConvertCustom_vtable__ {
	const struct ILM_Unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_ConvertCustom_vtable__ const ILM_ConvertCustom_vt__;

extern void ILM_ConvertCustom_ILM_GenValue__(ILM_ConvertCustom *node, ILM_Context * context);

struct ILM_AddressOf__ {
	const struct ILM_AddressOf_vtable__ *vtable__;
	ILM_Node * expr;
	ILType * type;
	ILUInt32 localNum;
};

struct ILM_AddressOf_vtable__ {
	const struct ILM_Unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_AddressOf_vtable__ const ILM_AddressOf_vt__;

extern void ILM_AddressOf_ILM_AllocLocals__(ILM_AddressOf *node, ILM_Context * context);
extern void ILM_AddressOf_ILM_ClearLocals__(ILM_AddressOf *node, ILM_Context * context);
extern void ILM_AddressOf_ILM_GenValue__(ILM_AddressOf *node, ILM_Context * context);

struct ILM_Method__ {
	const struct ILM_Method_vtable__ *vtable__;
	ILM_Node * expr;
};

struct ILM_Method_vtable__ {
	const struct ILM_Unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Method_vtable__ const ILM_Method_vt__;

extern void ILM_Method_ILM_GenValue__(ILM_Method *node, ILM_Context * context);

struct ILM_CompoundStmt__ {
	const struct ILM_CompoundStmt_vtable__ *vtable__;
	ILM_Node * expr;
	ILM_CompoundStmt * next;
};

struct ILM_CompoundStmt_vtable__ {
	const struct ILM_Unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_CompoundStmt_vtable__ const ILM_CompoundStmt_vt__;

extern void ILM_CompoundStmt_ILM_GenValue__(ILM_CompoundStmt *node, ILM_Context * context);

struct ILM_Assign__ {
	const struct ILM_Assign_vtable__ *vtable__;
	ILM_Node * expr1;
	ILM_Node * expr2;
};

struct ILM_Assign_vtable__ {
	const struct ILM_Binary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_Assign_vtable__ const ILM_Assign_vt__;

extern void ILM_Assign_ILM_GenValue__(ILM_Assign *node, ILM_Context * context);

struct ILM_AssignCtor__ {
	const struct ILM_AssignCtor_vtable__ *vtable__;
	ILM_Node * expr1;
	ILM_Node * expr2;
};

struct ILM_AssignCtor_vtable__ {
	const struct ILM_Binary_vtable__ *parent__;
	int kind__;
	const char *name__;
	void (*ILM_AllocLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_ClearLocals_v__)(ILM_Node *this__, ILM_Context * context);
	void (*ILM_GenValue_v__)(ILM_Node *this__, ILM_Context * context);
};

extern struct ILM_AssignCtor_vtable__ const ILM_AssignCtor_vt__;

extern void ILM_AssignCtor_ILM_GenValue__(ILM_AssignCtor *node, ILM_Context * context);

extern ILM_Node *ILM_FfiThread_create(ILM_State *state__);
extern ILM_Node *ILM_FfiThis_create(ILM_State *state__);
extern ILM_Node *ILM_FfiArgument_create(ILM_State *state__, ILM_Node * expr, ILType * type);
extern ILM_Node *ILM_FfiReturnArgument_create(ILM_State *state__, ILType * type, ILM_Node * returnLocal);
extern ILM_Node *ILM_FfiReturn_create(ILM_State *state__, ILType * type, ILM_Node * returnLocal);
extern ILM_Node *ILM_FfiCall_create(ILM_State *state__, void * fn, void * cif, void * ctorfn, void * ctorcif);
extern ILM_Node *ILM_TryFinally_create(ILM_State *state__, ILM_Node * tryBlock, ILM_Node * finallyBlock, ILM_Node * returnExpr, ILType * returnType);
extern ILM_Node *ILM_Compound_create(ILM_State *state__);
extern ILM_Node *ILM_Argument_create(ILM_State *state__, ILType * type, ILUInt32 argNum);
extern ILM_Node *ILM_Local_create(ILM_State *state__, ILType * type);
extern ILM_Node *ILM_Field_create(ILM_State *state__, ILM_Node * expr, ILField * field);
extern ILM_Node *ILM_ArgumentCtor_create(ILM_State *state__, ILType * type, ILUInt32 argNum);
extern ILM_Node *ILM_Return_create(ILM_State *state__, ILM_Node * expr, ILType * type);
extern ILM_Node *ILM_ReturnCtor_create(ILM_State *state__, ILM_Node * expr);
extern ILM_Node *ILM_Convert_create(ILM_State *state__, ILM_Node * expr, int opcode);
extern ILM_Node *ILM_ConvertCustom_create(ILM_State *state__, ILM_Node * expr, int opcode, ILUInt32 customNameLen, ILUInt32 customCookieLen, void * customName, void * customCookie);
extern ILM_Node *ILM_AddressOf_create(ILM_State *state__, ILM_Node * expr, ILType * type);
extern ILM_Node *ILM_Method_create(ILM_State *state__, ILM_Node * expr);
extern ILM_CompoundStmt *ILM_CompoundStmt_create(ILM_State *state__, ILM_Node * expr);
extern ILM_Node *ILM_Assign_create(ILM_State *state__, ILM_Node * expr1, ILM_Node * expr2);
extern ILM_Node *ILM_AssignCtor_create(ILM_State *state__, ILM_Node * expr1, ILM_Node * expr2);


#ifndef ILM_kind
#define ILM_kind(node__) ((node__)->vtable__->kind__)
#endif

#ifndef ILM_kindname
#define ILM_kindname(node__) ((node__)->vtable__->name__)
#endif

#ifndef ILM_kindof
#define ILM_kindof(type__) (type__##_kind)
#endif

#ifndef ILM_isa
extern int ILM_isa__(const void *vtable__, int kind__);
#define ILM_isa(node__,type__) \
	(ILM_isa__((node__)->vtable__, (type__##_kind)))
#endif

#ifndef ILM_nodeops_declared
extern void ILM_nodeinit(ILM_State *state__);
extern void *ILM_nodealloc(ILM_State *state__, unsigned int size__);
extern int ILM_nodepush(ILM_State *state__);
extern void ILM_nodepop(ILM_State *state__);
extern void ILM_nodeclear(ILM_State *state__);
extern void ILM_nodefailed(ILM_State *state__);
#define ILM_nodeops_declared 1
#endif

#ifdef __cplusplus
};
#endif

#endif
