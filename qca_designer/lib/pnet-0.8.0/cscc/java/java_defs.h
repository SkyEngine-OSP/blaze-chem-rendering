/* java_defs.h.  Generated automatically by treecc */
#ifndef __yy_java_defs_h
#define __yy_java_defs_h
#line 32 "java_defs.tc"


#include <codegen/cg_nodes.h>
#include <codegen/cg_coerce.h>
#include <codegen/cg_resolve.h>
#include <codegen/cg_scope.h>
#include "il_utils.h"
#include <cscc/java/java_semvalue.h>

#line 21 "java_types.tc"

/*
 * Convert a type into a printable name, suitable for use in error messages.
 */
const char *JavaTypeToName(ILType *type);
#line 22 "java_invoke.tc"


/*
 * Convert a program item (method, property, or delegate)
 * into a printable name, suitable for use in error messages.
 */
const char *JavaItemToName(ILProgramItem *item);

/*
 * Information that is kept about an evaluated argument.
 */
typedef struct
{
	ILType	   *type;
	ILNode     *node;
	ILNode    **parent;
} JavaEvalArg;

/*
 * Evaluate a list of arguments for a method invocation.
 * Returns the number of arguments, or -1 on error.
 */
int JavaEvalArguments(ILGenInfo *info, ILNode *argList,
					ILNode **argListParent, JavaEvalArg **args);

/*
 * Free an evaluated argument list.
 */
void JavaEvalFreeArguments(JavaEvalArg *args);

/*
 * Determine if a program item (method, property, or delegate)
 * is a candidate for evaluation.  Returns 0 if not a candidate,
 * 1 if a candidate in its normal form, and 2 if a candidate
 * in its expanded form.
 */
int JavaItemIsCandidate(ILGenInfo *info, ILProgramItem *item,
					  JavaEvalArg *args, int numArgs);

/*
 * Determine the best item candidate in a group.
 * Returns NULL if none of the methods are "best".
 */
ILProgramItem *JavaBestCandidate(ILGenInfo *info, void *group,
						       JavaEvalArg *args, int numArgs);

/*
 * Coerce the arguments and set up the final argument list.
 * Returns the item's return type.
 */
ILType *JavaItemCoerceArgs(ILGenInfo *info, ILProgramItem *item,
						 JavaEvalArg *args, int numArgs,
						 ILNode **argListParent);

/*
 * Report an error message for a failed item signature match,
 * listing the candidates for the call.
 */
void JavaItemCandidateError(ILNode *node, char *itemName, int isCtor,
						  void *group, JavaEvalArg *args, int numArgs);
#line 21 "java_misc.tc"

void GenArrayOfArray(ILGenInfo *info, ILType *arrayType,
						ILNode *dims);
#line 86 "java_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ILNode_JPrimitiveType_kind 263
#define ILNode_JArrayType_kind 264
#define ILNode_JPackage_kind 265
#define ILNode_JImport_kind 266
#define ILNode_JSystemType_kind 269
#define ILNode_ILSystemType_kind 270
#define ILNode_JTypeSuffix_kind 272
#define ILNode_TypeSuffixDeclarator_kind 276
#define ILNode_JImportType_kind 267
#define ILNode_JImportPackage_kind 268
#define ILNode_UserCast_kind 273
#define ILNode_InstanceOf_kind 274
#define ILNode_JNewExpression_kind 275
#define ILNode_JMain_kind 271

typedef struct ILNode_JPrimitiveType__ ILNode_JPrimitiveType;
typedef struct ILNode_JArrayType__ ILNode_JArrayType;
typedef struct ILNode_JPackage__ ILNode_JPackage;
typedef struct ILNode_JImport__ ILNode_JImport;
typedef struct ILNode_JSystemType__ ILNode_JSystemType;
typedef struct ILNode_ILSystemType__ ILNode_ILSystemType;
typedef struct ILNode_JTypeSuffix__ ILNode_JTypeSuffix;
typedef struct ILNode_TypeSuffixDeclarator__ ILNode_TypeSuffixDeclarator;
typedef struct ILNode_JImportType__ ILNode_JImportType;
typedef struct ILNode_JImportPackage__ ILNode_JImportPackage;
typedef struct ILNode_UserCast__ ILNode_UserCast;
typedef struct ILNode_InstanceOf__ ILNode_InstanceOf;
typedef struct ILNode_JNewExpression__ ILNode_JNewExpression;
typedef struct ILNode_JMain__ ILNode_JMain;

struct ILNode_JPrimitiveType__ {
	const struct ILNode_JPrimitiveType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt32 elementType;
};

struct ILNode_JPrimitiveType_vtable__ {
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

extern struct ILNode_JPrimitiveType_vtable__ const ILNode_JPrimitiveType_vt__;

struct ILNode_JArrayType__ {
	const struct ILNode_JArrayType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILUInt32 numDimensions;
};

struct ILNode_JArrayType_vtable__ {
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

extern struct ILNode_JArrayType_vtable__ const ILNode_JArrayType_vt__;

struct ILNode_JPackage__ {
	const struct ILNode_JPackage_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILNode * import;
};

struct ILNode_JPackage_vtable__ {
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

extern struct ILNode_JPackage_vtable__ const ILNode_JPackage_vt__;

struct ILNode_JImport__ {
	const struct ILNode_JImport_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILNode * next;
};

struct ILNode_JImport_vtable__ {
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

extern struct ILNode_JImport_vtable__ const ILNode_JImport_vt__;

struct ILNode_JSystemType__ {
	const struct ILNode_JSystemType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * className;
};

struct ILNode_JSystemType_vtable__ {
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

extern struct ILNode_JSystemType_vtable__ const ILNode_JSystemType_vt__;

struct ILNode_ILSystemType__ {
	const struct ILNode_ILSystemType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * className;
};

struct ILNode_ILSystemType_vtable__ {
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

extern struct ILNode_ILSystemType_vtable__ const ILNode_ILSystemType_vt__;

struct ILNode_JTypeSuffix__ {
	const struct ILNode_JTypeSuffix_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt32 count;
};

struct ILNode_JTypeSuffix_vtable__ {
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

extern struct ILNode_JTypeSuffix_vtable__ const ILNode_JTypeSuffix_vt__;

struct ILNode_TypeSuffixDeclarator__ {
	const struct ILNode_TypeSuffixDeclarator_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * name;
	int dims;
};

struct ILNode_TypeSuffixDeclarator_vtable__ {
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

extern struct ILNode_TypeSuffixDeclarator_vtable__ const ILNode_TypeSuffixDeclarator_vt__;

struct ILNode_JImportType__ {
	const struct ILNode_JImportType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILNode * next;
};

struct ILNode_JImportType_vtable__ {
	const struct ILNode_JImport_vtable__ *parent__;
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

extern struct ILNode_JImportType_vtable__ const ILNode_JImportType_vt__;

struct ILNode_JImportPackage__ {
	const struct ILNode_JImportPackage_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILNode * next;
};

struct ILNode_JImportPackage_vtable__ {
	const struct ILNode_JImport_vtable__ *parent__;
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

extern struct ILNode_JImportPackage_vtable__ const ILNode_JImportPackage_vt__;

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

struct ILNode_InstanceOf__ {
	const struct ILNode_InstanceOf_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_InstanceOf_vtable__ {
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

extern struct ILNode_InstanceOf_vtable__ const ILNode_InstanceOf_vt__;

struct ILNode_JNewExpression__ {
	const struct ILNode_JNewExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILNode * indexes;
	ILNode * rank;
	ILNode * arrayInitializer;
	ILType * arrayType;
};

struct ILNode_JNewExpression_vtable__ {
	const struct ILNode_NewExpression_vtable__ *parent__;
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

extern struct ILNode_JNewExpression_vtable__ const ILNode_JNewExpression_vt__;

extern ILMachineType ILNode_JNewExpression_ILNode_GenValue__(ILNode_JNewExpression *node, ILGenInfo * info);

struct ILNode_JMain__ {
	const struct ILNode_JMain_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILMethod * method;
};

struct ILNode_JMain_vtable__ {
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

extern struct ILNode_JMain_vtable__ const ILNode_JMain_vt__;

extern void ILNode_JMain_ILNode_GenDiscard__(ILNode_JMain *node, ILGenInfo * info);
extern void ILNode_JMain_JavaGenDiscard__(ILNode_JMain *node, ILGenInfo * info);

extern ILNode *ILNode_JPrimitiveType_create(ILUInt32 elementType);
extern ILNode *ILNode_JArrayType_create(ILNode * type, ILUInt32 numDimensions);
extern ILNode *ILNode_JPackage_create(char * name);
extern ILNode *ILNode_JImport_create(char * name);
extern ILNode *ILNode_JSystemType_create(char * className);
extern ILNode *ILNode_ILSystemType_create(char * className);
extern ILNode *ILNode_JTypeSuffix_create(ILUInt32 count);
extern ILNode *ILNode_TypeSuffixDeclarator_create(ILNode * name, int dims);
extern ILNode *ILNode_JImportType_create(char * name);
extern ILNode *ILNode_JImportPackage_create(char * name);
extern ILNode *ILNode_UserCast_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_InstanceOf_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_JNewExpression_create(ILNode * type, ILNode * indexes, ILNode * rank, ILNode * arrayInitializer);
extern ILNode *ILNode_JMain_create(ILMethod * method);

extern JavaSemValue ILNode_JSemAnalysis(ILNode * node, ILGenInfo * info, ILNode * * parent);
extern void ILNode_Declaration_GatherStaticCtor(ILNode_Declaration * node, ILNode_List * ctor);

#ifdef __cplusplus
};
#endif

#line 41 "java_semantics.tc"


/*
 * Perform semantic analysis on a type.  This is
 * guaranteed to always return a correct type value.
 * The "void" type will produce an error, if present.
 */
ILType *JavaSemType(ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on a literal type identifier.
 * This function changes the compiler state and then calls
 * JavaSemType;
 */
ILType *JavaSemTypeLiteral(ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on a type that can also
 * include the "void" type.
 */
ILType *JavaSemTypeVoid(ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on a base type.  Returns
 * zero if not a legal base type.
 */
int JavaSemBaseType(ILNode *type, ILGenInfo *info, ILNode **parent,
				  ILNode **baseNode, ILClass **baseClass);

/*
 * Perform semantic analysis on a node and expect a value.
 * Returns non-zero if a value, or zero on error.
 */
int JavaSemExpectValue(ILNode *node, ILGenInfo *info,
					 ILNode **parent, JavaSemValue *value);

/*
 * Perform semantic analysis on a node and expect a type.
 * Returns non-zero if a value, or zero on error.
 */
int JavaSemExpectType (ILNode *type, ILGenInfo *info, ILNode **parent);

/*
 * Perform semantic analysis on the node corresponding to a
 * program item.  This is used to finialize semantic analysis
 * on declarations that are forward-declared at the point of use.
 */
void JavaSemProgramItem(ILGenInfo *info, ILProgramItem *item);

#line 590 "java_defs.h"
#endif
