/* cs_defs.h.  Generated automatically by treecc */
#ifndef __yy_cs_defs_h
#define __yy_cs_defs_h
#line 34 "cs_defs.tc"


#include <codegen/cg_nodes.h>
#include <codegen/cg_coerce.h>
#include <codegen/cg_resolve.h>
#include <codegen/cg_scope.h>
#include <cscc/common/cc_preproc.h>
#include <cscc/common/cc_options.h>
#include <cscc/csharp/cs_semvalue.h>

#line 21 "cs_cast.tc"


/*
 * Convert a type into a printable name, suitable for use in error messages.
 */
const char *CSTypeToName(ILType *type);

#line 21 "cs_invoke.tc"


/*
 * Convert a program item (method, property, or delegate)
 * into a printable name, suitable for use in error messages.
 */
const char *CSItemToName(ILProgramItem *item);

/*
 * Information that is kept about an evaluated argument.
 */
typedef struct
{
	ILType	   *type;
	ILNode     *node;
	ILNode    **parent;
	ILParameterModifier modifier;

} CSEvalArg;

/*
 * Evaluate a list of arguments for a method invocation.
 * Returns the number of arguments, or -1 on error.
 */
int CSEvalArguments(ILGenInfo *info, ILNode *argList,
					ILNode **argListParent, CSEvalArg **args);

/*
 * Free an evaluated argument list.
 */
void CSEvalFreeArguments(CSEvalArg *args);

/*
 * Determine if a program item (method, property, or delegate)
 * is a candidate for evaluation.  Returns 0 if not a candidate,
 * 1 if a candidate in its normal form, and 2 if a candidate
 * in its expanded form.
 */
int CSItemIsCandidate(ILGenInfo *info, ILProgramItem *item,
					  CSEvalArg *args, int numArgs);

/*
 * Determine the best item candidate in a group.
 * Returns NULL if none of the methods are "best".
 */
ILProgramItem *CSBestCandidate(ILGenInfo *info, void *group,
						       CSEvalArg *args, int numArgs);

/*
 * Coerce the arguments and set up the final argument list.
 * Returns the item's return type.
 */
ILType *CSItemCoerceArgs(ILGenInfo *info, ILProgramItem *item,
						 CSEvalArg *args, int numArgs,
						 ILNode **argListParent);

/*
 * Report an error message for a failed item signature match,
 * listing the candidates for the call.
 */
void CSItemCandidateError(ILNode *node, char *itemName, int isCtor,
						  void *group, CSEvalArg *args, int numArgs);

#line 88 "cs_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ILNode_DummySem_kind 263
#define ILNode_ArrayType_kind 264
#define ILNode_PtrType_kind 265
#define ILNode_PrimitiveType_kind 266
#define ILNode_SystemType_kind 267
#define ILNode_TypeSuffix_kind 268
#define ILNode_LocalVariableType_kind 269
#define ILNode_TypeActuals_kind 270
#define ILNode_GenericReference_kind 271
#define ILNode_FixedVariable_kind 283
#define ILNode_ResourceDeclaration_kind 286
#define ILNode_BaseDestructor_kind 289
#define ILNode_DocComment_kind 290
#define ILNode_StandaloneAttr_kind 295
#define ILNode_Namespace_kind 291
#define ILNode_UsingAlias_kind 292
#define ILNode_UsingNamespace_kind 293
#define ILNode_FixAddress_kind 284
#define ILNode_FixExpr_kind 285
#define ILNode_SemGuard_kind 278
#define ILNode_GlobalNamespace_kind 294
#define ILNode_TypeOf_kind 272
#define ILNode_SizeOf_kind 273
#define ILNode_ToAttrConst_kind 279
#define ILNode_StackAlloc_kind 274
#define ILNode_UserCast_kind 275
#define ILNode_IsUntyped_kind 276
#define ILNode_AsUntyped_kind 277
#define ILNode_Fixed_kind 282
#define ILNode_Using_kind 287
#define ILNode_Unsafe_kind 288
#define ILNode_AttrIdentifier_kind 281
#define ILNode_AttrQualIdent_kind 280

typedef struct ILNode_DummySem__ ILNode_DummySem;
typedef struct ILNode_ArrayType__ ILNode_ArrayType;
typedef struct ILNode_PtrType__ ILNode_PtrType;
typedef struct ILNode_PrimitiveType__ ILNode_PrimitiveType;
typedef struct ILNode_SystemType__ ILNode_SystemType;
typedef struct ILNode_TypeSuffix__ ILNode_TypeSuffix;
typedef struct ILNode_LocalVariableType__ ILNode_LocalVariableType;
typedef struct ILNode_TypeActuals__ ILNode_TypeActuals;
typedef struct ILNode_GenericReference__ ILNode_GenericReference;
typedef struct ILNode_FixedVariable__ ILNode_FixedVariable;
typedef struct ILNode_ResourceDeclaration__ ILNode_ResourceDeclaration;
typedef struct ILNode_BaseDestructor__ ILNode_BaseDestructor;
typedef struct ILNode_DocComment__ ILNode_DocComment;
typedef struct ILNode_StandaloneAttr__ ILNode_StandaloneAttr;
typedef struct ILNode_Namespace__ ILNode_Namespace;
typedef struct ILNode_UsingAlias__ ILNode_UsingAlias;
typedef struct ILNode_UsingNamespace__ ILNode_UsingNamespace;
typedef struct ILNode_FixAddress__ ILNode_FixAddress;
typedef struct ILNode_FixExpr__ ILNode_FixExpr;
typedef struct ILNode_SemGuard__ ILNode_SemGuard;
typedef struct ILNode_GlobalNamespace__ ILNode_GlobalNamespace;
typedef struct ILNode_TypeOf__ ILNode_TypeOf;
typedef struct ILNode_SizeOf__ ILNode_SizeOf;
typedef struct ILNode_ToAttrConst__ ILNode_ToAttrConst;
typedef struct ILNode_StackAlloc__ ILNode_StackAlloc;
typedef struct ILNode_UserCast__ ILNode_UserCast;
typedef struct ILNode_IsUntyped__ ILNode_IsUntyped;
typedef struct ILNode_AsUntyped__ ILNode_AsUntyped;
typedef struct ILNode_Fixed__ ILNode_Fixed;
typedef struct ILNode_Using__ ILNode_Using;
typedef struct ILNode_Unsafe__ ILNode_Unsafe;
typedef struct ILNode_AttrIdentifier__ ILNode_AttrIdentifier;
typedef struct ILNode_AttrQualIdent__ ILNode_AttrQualIdent;

struct ILNode_DummySem__ {
	const struct ILNode_DummySem_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_DummySem_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_DummySem_vtable__ const ILNode_DummySem_vt__;

struct ILNode_ArrayType__ {
	const struct ILNode_ArrayType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILUInt32 numDimensions;
};

struct ILNode_ArrayType_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_ArrayType_vtable__ const ILNode_ArrayType_vt__;

struct ILNode_PtrType__ {
	const struct ILNode_PtrType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
};

struct ILNode_PtrType_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_PtrType_vtable__ const ILNode_PtrType_vt__;

struct ILNode_PrimitiveType__ {
	const struct ILNode_PrimitiveType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt32 elementType;
};

struct ILNode_PrimitiveType_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_PrimitiveType_vtable__ const ILNode_PrimitiveType_vt__;

struct ILNode_SystemType__ {
	const struct ILNode_SystemType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * className;
};

struct ILNode_SystemType_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_SystemType_vtable__ const ILNode_SystemType_vt__;

struct ILNode_TypeSuffix__ {
	const struct ILNode_TypeSuffix_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt32 count;
};

struct ILNode_TypeSuffix_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_TypeSuffix_vtable__ const ILNode_TypeSuffix_vt__;

struct ILNode_LocalVariableType__ {
	const struct ILNode_LocalVariableType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILNode * suffixes;
};

struct ILNode_LocalVariableType_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_LocalVariableType_vtable__ const ILNode_LocalVariableType_vt__;

struct ILNode_TypeActuals__ {
	const struct ILNode_TypeActuals_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * left;
	ILNode * right;
};

struct ILNode_TypeActuals_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_TypeActuals_vtable__ const ILNode_TypeActuals_vt__;

struct ILNode_GenericReference__ {
	const struct ILNode_GenericReference_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILNode * actuals;
};

struct ILNode_GenericReference_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_GenericReference_vtable__ const ILNode_GenericReference_vt__;

struct ILNode_FixedVariable__ {
	const struct ILNode_FixedVariable_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * name;
};

struct ILNode_FixedVariable_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_FixedVariable_vtable__ const ILNode_FixedVariable_vt__;

struct ILNode_ResourceDeclaration__ {
	const struct ILNode_ResourceDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILNode * variables;
	ILNode * init;
};

struct ILNode_ResourceDeclaration_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_ResourceDeclaration_vtable__ const ILNode_ResourceDeclaration_vt__;

extern void ILNode_ResourceDeclaration_ILNode_GenDiscard__(ILNode_ResourceDeclaration *node, ILGenInfo * info);

struct ILNode_BaseDestructor__ {
	const struct ILNode_BaseDestructor_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * destructor;
};

struct ILNode_BaseDestructor_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_BaseDestructor_vtable__ const ILNode_BaseDestructor_vt__;

extern void ILNode_BaseDestructor_ILNode_GenDiscard__(ILNode_BaseDestructor *node, ILGenInfo * info);

struct ILNode_DocComment__ {
	const struct ILNode_DocComment_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * str;
	int len;
};

struct ILNode_DocComment_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_DocComment_vtable__ const ILNode_DocComment_vt__;

struct ILNode_StandaloneAttr__ {
	const struct ILNode_StandaloneAttr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * namespaceNode;
	ILNode * attributes;
};

struct ILNode_StandaloneAttr_vtable__ {
	const struct ILNode_Dummy_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_StandaloneAttr_vtable__ const ILNode_StandaloneAttr_vt__;

struct ILNode_Namespace__ {
	const struct ILNode_Namespace_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILNode_Namespace * enclosing;
	ILNode_UsingNamespace * using;
	ILScope * localScope;
};

struct ILNode_Namespace_vtable__ {
	const struct ILNode_DummySem_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_Namespace_vtable__ const ILNode_Namespace_vt__;

struct ILNode_UsingAlias__ {
	const struct ILNode_UsingAlias_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	char * ref;
	ILVisitMode visited;
};

struct ILNode_UsingAlias_vtable__ {
	const struct ILNode_DummySem_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_UsingAlias_vtable__ const ILNode_UsingAlias_vt__;

struct ILNode_UsingNamespace__ {
	const struct ILNode_UsingNamespace_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILNode_UsingNamespace * next;
};

struct ILNode_UsingNamespace_vtable__ {
	const struct ILNode_DummySem_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_UsingNamespace_vtable__ const ILNode_UsingNamespace_vt__;

struct ILNode_FixAddress__ {
	const struct ILNode_FixAddress_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * name;
	ILNode * address;
};

struct ILNode_FixAddress_vtable__ {
	const struct ILNode_FixedVariable_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_FixAddress_vtable__ const ILNode_FixAddress_vt__;

struct ILNode_FixExpr__ {
	const struct ILNode_FixExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * name;
	ILNode * expr;
};

struct ILNode_FixExpr_vtable__ {
	const struct ILNode_FixedVariable_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_FixExpr_vtable__ const ILNode_FixExpr_vt__;

struct ILNode_SemGuard__ {
	const struct ILNode_SemGuard_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	CSSemValue value;
};

struct ILNode_SemGuard_vtable__ {
	const struct ILNode_AsIs_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	ILMachineType (*ILNode_Prepare_v__)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2);
	ILMachineType (*ILNode_GetAndPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2);
	void (*ILNode_Store_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2);
	void (*ILNode_GenRef_v__)(ILNode_LValue *this__, ILGenInfo * info);
	ILMachineType (*JavaPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2);
	ILMachineType (*JavaGetAndPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2);
	void (*JavaStore_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2);
};

extern struct ILNode_SemGuard_vtable__ const ILNode_SemGuard_vt__;

struct ILNode_GlobalNamespace__ {
	const struct ILNode_GlobalNamespace_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_GlobalNamespace_vtable__ {
	const struct ILNode_AsIs_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	ILMachineType (*ILNode_Prepare_v__)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2);
	ILMachineType (*ILNode_GetAndPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2);
	void (*ILNode_Store_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2);
	void (*ILNode_GenRef_v__)(ILNode_LValue *this__, ILGenInfo * info);
	ILMachineType (*JavaPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2);
	ILMachineType (*JavaGetAndPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2);
	void (*JavaStore_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2);
};

extern struct ILNode_GlobalNamespace_vtable__ const ILNode_GlobalNamespace_vt__;

struct ILNode_TypeOf__ {
	const struct ILNode_TypeOf_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
};

struct ILNode_TypeOf_vtable__ {
	const struct ILNode_UnaryExpression_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_TypeOf_vtable__ const ILNode_TypeOf_vt__;

extern ILMachineType ILNode_TypeOf_ILNode_GetType__(ILNode_TypeOf *node, ILGenInfo * info);
extern ILMachineType ILNode_TypeOf_ILNode_GenValue__(ILNode_TypeOf *node, ILGenInfo * info);
extern ILMachineType ILNode_TypeOf_JavaGenValue__(ILNode_TypeOf *node, ILGenInfo * info);

struct ILNode_SizeOf__ {
	const struct ILNode_SizeOf_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
	ILInt32 size;
};

struct ILNode_SizeOf_vtable__ {
	const struct ILNode_UnaryExpression_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_SizeOf_vtable__ const ILNode_SizeOf_vt__;

extern ILMachineType ILNode_SizeOf_ILNode_GetType__(ILNode_SizeOf *node, ILGenInfo * info);
extern ILMachineType ILNode_SizeOf_ILNode_GenValue__(ILNode_SizeOf *node, ILGenInfo * info);
extern int ILNode_SizeOf_ILNode_EvalConst__(ILNode_SizeOf *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_SizeOf_JavaGenValue__(ILNode_SizeOf *node, ILGenInfo * info);

struct ILNode_ToAttrConst__ {
	const struct ILNode_ToAttrConst_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_ToAttrConst_vtable__ {
	const struct ILNode_ToConst_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_ToAttrConst_vtable__ const ILNode_ToAttrConst_vt__;

struct ILNode_StackAlloc__ {
	const struct ILNode_StackAlloc_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_StackAlloc_vtable__ {
	const struct ILNode_BinaryExpression_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_StackAlloc_vtable__ const ILNode_StackAlloc_vt__;

extern ILMachineType ILNode_StackAlloc_ILNode_GetType__(ILNode_StackAlloc *node, ILGenInfo * info);
extern ILMachineType ILNode_StackAlloc_ILNode_GenValue__(ILNode_StackAlloc *node, ILGenInfo * info);
extern ILMachineType ILNode_StackAlloc_JavaGenValue__(ILNode_StackAlloc *node, ILGenInfo * info);

struct ILNode_UserCast__ {
	const struct ILNode_UserCast_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_UserCast_vtable__ {
	const struct ILNode_DummyBinaryExpr_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_UserCast_vtable__ const ILNode_UserCast_vt__;

struct ILNode_IsUntyped__ {
	const struct ILNode_IsUntyped_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_IsUntyped_vtable__ {
	const struct ILNode_DummyBinaryExpr_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_IsUntyped_vtable__ const ILNode_IsUntyped_vt__;

struct ILNode_AsUntyped__ {
	const struct ILNode_AsUntyped_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_AsUntyped_vtable__ {
	const struct ILNode_DummyBinaryExpr_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_AsUntyped_vtable__ const ILNode_AsUntyped_vt__;

struct ILNode_Fixed__ {
	const struct ILNode_Fixed_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * type;
	ILNode * decls;
	ILNode * stmt;
};

struct ILNode_Fixed_vtable__ {
	const struct ILNode_Statement_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_Fixed_vtable__ const ILNode_Fixed_vt__;

extern void ILNode_Fixed_ILNode_GenDiscard__(ILNode_Fixed *node, ILGenInfo * info);
extern int ILNode_Fixed_ILNode_EndsInReturnImpl__(ILNode_Fixed *node, ILGenInfo * info);
extern void ILNode_Fixed_JavaGenDiscard__(ILNode_Fixed *node, ILGenInfo * info);

struct ILNode_Using__ {
	const struct ILNode_Using_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * resource;
	ILNode * stmt;
};

struct ILNode_Using_vtable__ {
	const struct ILNode_Statement_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_Using_vtable__ const ILNode_Using_vt__;

extern void ILNode_Using_ILNode_GenDiscard__(ILNode_Using *node, ILGenInfo * info);
extern int ILNode_Using_ILNode_EndsInReturnImpl__(ILNode_Using *node, ILGenInfo * info);
extern void ILNode_Using_JavaGenDiscard__(ILNode_Using *node, ILGenInfo * info);

struct ILNode_Unsafe__ {
	const struct ILNode_Unsafe_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * stmt;
};

struct ILNode_Unsafe_vtable__ {
	const struct ILNode_Statement_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_Unsafe_vtable__ const ILNode_Unsafe_vt__;

extern void ILNode_Unsafe_ILNode_GenDiscard__(ILNode_Unsafe *node, ILGenInfo * info);
extern int ILNode_Unsafe_ILNode_EndsInReturnImpl__(ILNode_Unsafe *node, ILGenInfo * info);
extern void ILNode_Unsafe_JavaGenDiscard__(ILNode_Unsafe *node, ILGenInfo * info);

struct ILNode_AttrIdentifier__ {
	const struct ILNode_AttrIdentifier_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
};

struct ILNode_AttrIdentifier_vtable__ {
	const struct ILNode_Identifier_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_AttrIdentifier_vtable__ const ILNode_AttrIdentifier_vt__;

struct ILNode_AttrQualIdent__ {
	const struct ILNode_AttrQualIdent_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * left;
	ILNode * right;
};

struct ILNode_AttrQualIdent_vtable__ {
	const struct ILNode_QualIdent_vtable__ *parent__;
	int kind__;
	const char *name__;
	ILMachineType (*ILNode_GetType_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*ILNode_GenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*ILNode_GenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*ILNode_GenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	int (*ILNode_EvalConst_v__)(ILNode *this__, ILGenInfo * info, ILEvalValue * value);
	int (*ILNode_EndsInReturnImpl_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenDiscard_v__)(ILNode *this__, ILGenInfo * info);
	ILMachineType (*JavaGenValue_v__)(ILNode *this__, ILGenInfo * info);
	void (*JavaGenThen_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
	void (*JavaGenElse_v__)(ILNode *this__, ILGenInfo * info, ILLabel * label);
};

extern struct ILNode_AttrQualIdent_vtable__ const ILNode_AttrQualIdent_vt__;

extern ILNode *ILNode_DummySem_create(void);
extern ILNode *ILNode_ArrayType_create(ILNode * type, ILUInt32 numDimensions);
extern ILNode *ILNode_PtrType_create(ILNode * type);
extern ILNode *ILNode_PrimitiveType_create(ILUInt32 elementType);
extern ILNode *ILNode_SystemType_create(char * className);
extern ILNode *ILNode_TypeSuffix_create(ILUInt32 count);
extern ILNode *ILNode_LocalVariableType_create(ILNode * type, ILNode * suffixes);
extern ILNode *ILNode_TypeActuals_create(ILNode * left, ILNode * right);
extern ILNode *ILNode_GenericReference_create(ILNode * type, ILNode * actuals);
extern ILNode *ILNode_ResourceDeclaration_create(ILNode * type, ILNode * variables, ILNode * init);
extern ILNode *ILNode_BaseDestructor_create(ILNode * destructor);
extern ILNode *ILNode_DocComment_create(char * str, int len);
extern ILNode *ILNode_StandaloneAttr_create(ILNode * namespaceNode, ILNode * attributes);
extern ILNode *ILNode_Namespace_create(char * name, ILNode_Namespace * enclosing);
extern ILNode *ILNode_UsingAlias_create(char * name, char * ref);
extern ILNode *ILNode_UsingNamespace_create(char * name);
extern ILNode *ILNode_FixAddress_create(ILNode * name, ILNode * address);
extern ILNode *ILNode_FixExpr_create(ILNode * name, ILNode * expr);
extern ILNode *ILNode_SemGuard_create(ILNode * expr, CSSemValue value);
extern ILNode *ILNode_GlobalNamespace_create(ILNode * expr);
extern ILNode *ILNode_TypeOf_create(ILNode * expr);
extern ILNode *ILNode_SizeOf_create(ILNode * expr);
extern ILNode *ILNode_ToAttrConst_create(ILNode * expr);
extern ILNode *ILNode_StackAlloc_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_UserCast_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_IsUntyped_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_AsUntyped_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Fixed_create(ILNode * type, ILNode * decls, ILNode * stmt);
extern ILNode *ILNode_Using_create(ILNode * resource, ILNode * stmt);
extern ILNode *ILNode_Unsafe_create(ILNode * stmt);
extern ILNode *ILNode_AttrIdentifier_create(char * name);
extern ILNode *ILNode_AttrQualIdent_create(ILNode * left, ILNode * right);

extern CSSemValue ILNode_SemAnalysis(ILNode * node, ILGenInfo * info, ILNode * * parent);
extern void ILNode_Declaration_GatherStaticCtor(ILNode_Declaration * node, ILNode_List * ctor);
extern CSSemValue ILNode_SemAnalysisType(ILNode * node, ILGenInfo * info, ILNode * * parent);

#ifdef __cplusplus
};
#endif

#line 55 "cs_semantics.tc"


/*
 * Create a type for a built-in class or value type.
 */
/*
ILType *CSCreateClassType(CSSemContext *sctx, const char *namespace,
						  const char *name);
ILType *CSCreateValueType(CSSemContext *sctx, const char *namespace,
						  const char *name);
*/

/*
 * Perform semantic analysis on a type.  This is
 * guaranteed to always return a correct type value.
 * The "void" type will produce an error, if present.
 */
ILType *CSSemType(ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on a literal type identifier.
 * This function changes the compiler state and then calls
 * CSSemType;
 */
ILType *CSSemTypeLiteral(ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on a type that can also
 * include the "void" type.
 */
ILType *CSSemTypeVoid(ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on a base type.  Returns
 * zero if not a legal base type.
 */
int CSSemBaseType(ILNode *type, ILGenInfo *info, ILNode **parent,
				  ILNode **baseNode, ILClass **baseClass);

/*
 * Perform semantic analysis on a node and expect a value.
 * Returns non-zero if a value, or zero on error.
 */
int CSSemExpectValue(ILNode *node, ILGenInfo *info,
					 ILNode **parent, CSSemValue *value);

/*
 * Perform semantic analysis on a node and expect a type.
 * Returns non-zero if a value, or zero on error.
 */
int CSSemExpectType (ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on the node corresponding to a
 * program item.  This is used to finialize semantic analysis
 * on declarations that are forward-declared at the point of use.
 */
void CSSemProgramItem(ILGenInfo *info, ILProgramItem *item);

#line 1227 "cs_defs.h"
#endif
