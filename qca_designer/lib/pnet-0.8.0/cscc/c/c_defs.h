/* c_defs.h.  Generated automatically by treecc */
#ifndef __yy_c_defs_h
#define __yy_c_defs_h
#line 34 "c_defs.tc"


#include <codegen/cg_nodes.h>
#include <codegen/cg_coerce.h>
#include <codegen/cg_resolve.h>
#include <codegen/cg_scope.h>
#include <cscc/common/cc_preproc.h>
#include <cscc/common/cc_options.h>
#include <cscc/c/c_declspec.h>

/*
 * Define the semantic analysis value for C nodes.
 */
typedef struct
{
	int		kind__;
	ILType *type__;
	void   *extra__;

} CSemValue;

/*
 * Semantic analysis value kinds.
 *
 * If the "DYN_CONSTANT" flag is set, then it indicates a
 * constant value that must be computed at runtime, because
 * it references a function, a static address, or a type
 * whose size is only known at runtime.
 *
 * If the "BOOLEAN" flag is set, then the compiler has inferred
 * that the correspond node will always be boolean true or false.
 */
#define	C_SEMKIND_VOID			(1<<0)
#define	C_SEMKIND_LVALUE		(1<<1)
#define	C_SEMKIND_RVALUE		(1<<2)
#define	C_SEMKIND_CONSTANT		(1<<3)
#define	C_SEMKIND_DYN_CONSTANT	(1<<4)
#define	C_SEMKIND_FUNCTION		(1<<5)
#define	C_SEMKIND_TYPE			(1<<6)
#define	C_SEMKIND_BOOLEAN		(1<<7)
#define	C_SEMKIND_NO_REF		(1<<8)
#define	C_SEMKIND_DECAYED		(1<<9)
#define	C_SEMKIND_ERROR			(1<<10)
#define	C_SEMKIND_FIELD			(1<<11)
#define	C_SEMKIND_PROPERTY		(1<<12)
#define	C_SEMKIND_METHOD_GROUP	(1<<13)
#define	C_SEMKIND_SVALUE		(1<<14)

/*
 * The default semantic value, which is always "void".
 */
extern CSemValue CSemValueDefault;

/*
 * A semantic value that represents a boolean r-value.
 */
extern CSemValue CSemValueBool;

/*
 * A semantic value that represents a semantic error.
 */
extern CSemValue CSemValueError;

/*
 * Test for various kinds of semantic values.
 */
#define	CSemIsVoid(value)		(((value).kind__ & C_SEMKIND_VOID) != 0)
#define	CSemIsLValue(value)			\
			(((value).kind__ & (C_SEMKIND_LVALUE | C_SEMKIND_SVALUE)) != 0)
#define	CSemIsRValue(value)			\
			(((value).kind__ & (C_SEMKIND_LVALUE | C_SEMKIND_RVALUE)) != 0)
#define	CSemIsConstant(value)	(((value).kind__ & C_SEMKIND_CONSTANT) != 0)
#define	CSemIsDynConstant(value)	\
			(((value).kind__ & C_SEMKIND_DYN_CONSTANT) != 0)
#define	CSemIsFunction(value)	(((value).kind__ & C_SEMKIND_FUNCTION) != 0)
#define	CSemIsType(value)		(((value).kind__ & C_SEMKIND_TYPE) != 0)
#define	CSemIsBoolean(value)	(((value).kind__ & C_SEMKIND_BOOLEAN) != 0)
#define	CSemIsNoRef(value)		(((value).kind__ & C_SEMKIND_NO_REF) != 0)
#define	CSemIsDecayed(value)	(((value).kind__ & C_SEMKIND_DECAYED) != 0)
#define	CSemIsError(value)		(((value).kind__ & C_SEMKIND_ERROR) != 0)
#define	CSemIsField(value)		(((value).kind__ & C_SEMKIND_FIELD) != 0)
#define	CSemIsProperty(value)	(((value).kind__ & C_SEMKIND_PROPERTY) != 0)
#define	CSemIsMethodGroup(value)	\
			(((value).kind__ & C_SEMKIND_METHOD_GROUP) != 0)
#define	CSemIsSValue(value)		(((value).kind__ & C_SEMKIND_SVALUE) != 0)

/*
 * Get the type field from a semantic value.
 */
#define	CSemGetType(value)				((value).type__)

/*
 * Get the decayed type field from a semantic value.
 */
#define	CSemGetDecayedType(value)		((ILType *)((value).extra__))

/*
 * Get the constant value associated with a semantic value.
 */
#define	CSemGetConstant(value)	\
	((((value).kind__ & (C_SEMKIND_CONSTANT | C_SEMKIND_DYN_CONSTANT)) \
			== C_SEMKIND_CONSTANT) ? ((ILEvalValue *)((value).extra__)) \
								   : ((ILEvalValue *)0))

/*
 * Get the function name associated with a semantic value.
 */
#define	CSemGetFuncName(value)	((char *)((value).extra__))

/*
 * Set a semantic value to "void".
 */
#define	CSemSetVoid(value)	\
			do { \
				(value).kind__ = C_SEMKIND_VOID; \
				(value).type__ = ILType_Void; \
				(value).extra__ = 0; \
			} while (0)

/*
 * Set a semantic value to an l-value reference.
 */
#define	CSemSetLValue(value,type)	\
			do { \
				(value).kind__ = C_SEMKIND_LVALUE; \
				(value).type__ = (type); \
				(value).extra__ = 0; \
			} while (0)

/*
 * Set a semantic value to an s-value reference (i.e. an l-value that
 * cannot be used as an r-value such as a write-only property).
 */
#define	CSemSetSValue(value,type)	\
			do { \
				(value).kind__ = C_SEMKIND_SVALUE | C_SEMKIND_NO_REF; \
				(value).type__ = (type); \
				(value).extra__ = 0; \
			} while (0)

/*
 * Set a semantic value to an l-value reference that does not
 * allow the "&" operator to be used (e.g. bit fields).
 */
#define	CSemSetLValueNoRef(value,type)	\
			do { \
				(value).kind__ = C_SEMKIND_LVALUE | C_SEMKIND_NO_REF; \
				(value).type__ = (type); \
				(value).extra__ = 0; \
			} while (0)

/*
 * Set a semantic value to an r-value reference.
 */
#define	CSemSetRValue(value,type)	\
			do { \
				(value).kind__ = C_SEMKIND_RVALUE; \
				(value).type__ = (type); \
				(value).extra__ = 0; \
			} while (0)

/*
 * Set a semantic value to an r-value reference that resulted
 * from a decayed array l-value.
 */
#define	CSemSetDecayedRValue(value,type,origType)	\
			do { \
				(value).kind__ = C_SEMKIND_RVALUE | C_SEMKIND_DECAYED; \
				(value).type__ = (type); \
				(value).extra__ = (void *)(origType); \
			} while (0)

/*
 * Set a semantic value to a constant reference.
 */
#define	CSemSetConstant(value,type,constValue)	\
			do { \
				(value).kind__ = C_SEMKIND_RVALUE | C_SEMKIND_CONSTANT; \
				(value).type__ = (type); \
				(value).extra__ = \
					CSemDupExtra(&(constValue), sizeof(ILEvalValue)); \
			} while (0)

/*
 * Set a semantic value to a dynamic constant reference.
 */
#define	CSemSetDynConstant(value,type)	\
			do { \
				(value).kind__ = C_SEMKIND_RVALUE | C_SEMKIND_CONSTANT | \
								 C_SEMKIND_DYN_CONSTANT; \
				(value).type__ = (type); \
				(value).extra__ = 0; \
			} while (0)

/*
 * Set a semantic value to a function reference.
 */
#define	CSemSetFunction(value,type,name)	\
			do { \
				(value).kind__ = C_SEMKIND_FUNCTION | C_SEMKIND_CONSTANT | \
								 C_SEMKIND_DYN_CONSTANT; \
				(value).type__ = (type); \
				(value).extra__ = (void *)(name); \
			} while (0)

/*
 * Set a semantic value to a type reference.
 */
#define	CSemSetType(value,type)	\
			do { \
				(value).kind__ = C_SEMKIND_TYPE; \
				(value).type__ = (type); \
				(value).extra__ = 0; \
			} while (0)

/*
 * Covnert a semantic value into a type reference.
 */
#define	CSemToType(value)	\
			do { \
				(value).kind__ = C_SEMKIND_TYPE; \
				(value).extra__ = 0; \
			} while (0)

/*
 * Adjust a semantic value to record that it is boolean.  This must
 * be used after one of the above "Set" macros.
 */
#define	CSemSetBoolean(value)	\
			do { \
				(value).kind__ |= C_SEMKIND_BOOLEAN; \
			} while (0)

/*
 * Set a semantic value to "error".
 */
#define	CSemSetError(value)	\
			do { \
				(value).kind__ = C_SEMKIND_ERROR; \
				(value).type__ = ILType_Void; \
				(value).extra__ = 0; \
			} while (0)

/*
 * Convert l-values into r-values, while retaining constant information.
 */
#define	CSemLToRValue(value)	\
			do { \
				(value).kind__ &= ~C_SEMKIND_LVALUE; \
				(value).kind__ |= C_SEMKIND_RVALUE; \
			} while (0)

/*
 * Set a semantic value to a field.
 */
#define	CSemSetField(value,field)	\
			do { \
				(value).kind__ = C_SEMKIND_FIELD; \
				(value).type__ = ILType_Void; \
				(value).extra__ = (void *)(field); \
			} while (0)

/*
 * Extract the field from a semantic value.
 */
#define	CSemGetField(value)		((ILField *)((value).extra__))

/*
 * Set a semantic value to a property.
 */
#define	CSemSetProperty(value,property)	\
			do { \
				(value).kind__ = C_SEMKIND_PROPERTY; \
				(value).type__ = ILType_Void; \
				(value).extra__ = (void *)(property); \
			} while (0)

/*
 * Extract the property from a semantic value.
 */
#define	CSemGetProperty(value)	((ILProperty *)((value).extra__))

/*
 * Set a semantic value to a method group.
 */
#define	CSemSetMethodGroup(value,type,name)	\
			do { \
				(value).kind__ = C_SEMKIND_METHOD_GROUP; \
				(value).type__ = (type); \
				(value).extra__ = (void *)(name); \
			} while (0)

/*
 * Get the name from a method group.
 */
#define	CSemGetMethodName(value)	((char *)((value).extra__))

/*
 * Perform inline semantic analysis on a node, in a specific scope.
 */
CSemValue CSemInlineAnalysis(ILGenInfo *info, ILNode *node,
							 ILNode **parent, ILScope *scope);

/*
 * Determine if a semantic value is zero.
 */
int CSemIsZero(CSemValue value);

/*
 * Information about an address that is generated by "ILNode_CGenAddress".
 */
typedef struct
{
	int			ptrOnStack;		/* Zero if the address is relative to NULL */
	ILInt32		offset;			/* Constant offset from the pointer */

} CAddress;

/*
 * The default address (evaluates to NULL).
 */
extern CAddress CAddressDefault;

/*
 * Push the address of an l-value node onto the stack.  This calls
 * "ILNode_CGenAddress" and then combines the pointer and offset into
 * a single pointer value on the stack.
 */
void CGenAddress(ILGenInfo *info, ILNode *node);

#line 409 "c_stmt.tc"


/*
 * Destroy the "goto" label list for the current function.
 */
void CGenGotoDestroy(void);

/*
 * Generate labels for the switch statement that handles "goto *".
 */
void CGenGotoPtrLabels(ILGenInfo *info, ILLabel *defaultLabel);

#line 24 "c_name.tc"


/*
 * Name information that is returned by "ILNode_CName",
 */
typedef struct
{
	char *name;
	int	  prec;

} CName;

/*
 * Standard precedence values.
 */
#define	C_PREC_PRIMARY		200
#define	C_PREC_POSTFIX		190
#define	C_PREC_UNARY		180
#define	C_PREC_MULT			170
#define	C_PREC_ADD			160
#define	C_PREC_SHIFT		150
#define	C_PREC_RELATIONAL	140
#define	C_PREC_EQUALITY		130
#define	C_PREC_AND			120
#define	C_PREC_XOR			110
#define	C_PREC_OR			100
#define	C_PREC_LOGAND		90
#define	C_PREC_LOGOR		80
#define	C_PREC_COND			70
#define	C_PREC_ASSIGN		60
#define	C_PREC_EXPR			50

/*
 * The default name.
 */
extern CName CNameDefault;

/*
 * Create a name from a string and precedence.
 */
CName CNameCreate(const char *name, int prec);

/*
 * Create a name that results from applying a unary operator.
 */
CName CNameCreateUnary(const char *oper, CName arg, int prec);

/*
 * Create a name that results from applying a unary operator with brackets.
 */
CName CNameCreateUnaryBracketed(const char *oper, CName arg, int prec);

/*
 * Create a name that results from applying a binary operator.
 */
CName CNameCreateBinary(CName left, const char *oper, CName right, int prec);

#line 407 "c_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ILNode_CDeclarator_kind 271
#define ILNode_CSharpInvocation_kind 285
#define ILNode_CAttribute_kind 293
#define ILNode_CAttributeValue_kind 294
#define ILNode_CBitFieldDeclarator_kind 272
#define ILNode_CInitDeclarator_kind 273
#define ILNode_SizeOfType_kind 270
#define ILNode_VaStart_kind 274
#define ILNode_VaEnd_kind 275
#define ILNode_VaArg_kind 276
#define ILNode_FunctionRef_kind 283
#define ILNode_CLabelRef_kind 299
#define ILNode_CSharpTypeOf_kind 301
#define ILNode_CTypeExpression_kind 302
#define ILNode_CNewObject_kind 304
#define ILNode_CNewArray_kind 305
#define ILNode_CSizeOfRaw_kind 307
#define ILNode_CSizeTempVar_kind 308
#define ILNode_CSizeAlign_kind 311
#define ILNode_CString_kind 267
#define ILNode_CWString_kind 268
#define ILNode_CLocalVar_kind 280
#define ILNode_CArgumentVar_kind 281
#define ILNode_CGlobalVar_kind 282
#define ILNode_CFieldAccess_kind 287
#define ILNode_CDeref_kind 291
#define ILNode_CBitField_kind 292
#define ILNode_CArrayAccess_kind 286
#define ILNode_CDerefField_kind 288
#define ILNode_CMemberField_kind 289
#define ILNode_CStaticField_kind 290
#define ILNode_SizeOfExpr_kind 269
#define ILNode_SetJmp_kind 277
#define ILNode_AllocA_kind 278
#define ILNode_CToCSharpString_kind 297
#define ILNode_CArrayInit_kind 298
#define ILNode_CBox_kind 303
#define ILNode_CopyComplex_kind 312
#define ILNode_CDelete_kind 306
#define ILNode_CSizeReleaseTempVar_kind 309
#define ILNode_CSizeMax_kind 310
#define ILNode_CInvocationExpression_kind 284
#define ILNode_AsmStmt_kind 279
#define ILNode_CAssignArray_kind 295
#define ILNode_CAssignStruct_kind 296
#define ILNode_CGotoPtr_kind 300

typedef enum {
	ILGC_Unknown,
	ILGC_Managed,
	ILGC_Unmanaged
} ILGCSpecifier;

typedef struct ILNode_CDeclarator__ ILNode_CDeclarator;
typedef struct ILNode_CSharpInvocation__ ILNode_CSharpInvocation;
typedef struct ILNode_CAttribute__ ILNode_CAttribute;
typedef struct ILNode_CAttributeValue__ ILNode_CAttributeValue;
typedef struct ILNode_CBitFieldDeclarator__ ILNode_CBitFieldDeclarator;
typedef struct ILNode_CInitDeclarator__ ILNode_CInitDeclarator;
typedef struct ILNode_SizeOfType__ ILNode_SizeOfType;
typedef struct ILNode_VaStart__ ILNode_VaStart;
typedef struct ILNode_VaEnd__ ILNode_VaEnd;
typedef struct ILNode_VaArg__ ILNode_VaArg;
typedef struct ILNode_FunctionRef__ ILNode_FunctionRef;
typedef struct ILNode_CLabelRef__ ILNode_CLabelRef;
typedef struct ILNode_CSharpTypeOf__ ILNode_CSharpTypeOf;
typedef struct ILNode_CTypeExpression__ ILNode_CTypeExpression;
typedef struct ILNode_CNewObject__ ILNode_CNewObject;
typedef struct ILNode_CNewArray__ ILNode_CNewArray;
typedef struct ILNode_CSizeOfRaw__ ILNode_CSizeOfRaw;
typedef struct ILNode_CSizeTempVar__ ILNode_CSizeTempVar;
typedef struct ILNode_CSizeAlign__ ILNode_CSizeAlign;
typedef struct ILNode_CString__ ILNode_CString;
typedef struct ILNode_CWString__ ILNode_CWString;
typedef struct ILNode_CLocalVar__ ILNode_CLocalVar;
typedef struct ILNode_CArgumentVar__ ILNode_CArgumentVar;
typedef struct ILNode_CGlobalVar__ ILNode_CGlobalVar;
typedef struct ILNode_CFieldAccess__ ILNode_CFieldAccess;
typedef struct ILNode_CDeref__ ILNode_CDeref;
typedef struct ILNode_CBitField__ ILNode_CBitField;
typedef struct ILNode_CArrayAccess__ ILNode_CArrayAccess;
typedef struct ILNode_CDerefField__ ILNode_CDerefField;
typedef struct ILNode_CMemberField__ ILNode_CMemberField;
typedef struct ILNode_CStaticField__ ILNode_CStaticField;
typedef struct ILNode_SizeOfExpr__ ILNode_SizeOfExpr;
typedef struct ILNode_SetJmp__ ILNode_SetJmp;
typedef struct ILNode_AllocA__ ILNode_AllocA;
typedef struct ILNode_CToCSharpString__ ILNode_CToCSharpString;
typedef struct ILNode_CArrayInit__ ILNode_CArrayInit;
typedef struct ILNode_CBox__ ILNode_CBox;
typedef struct ILNode_CopyComplex__ ILNode_CopyComplex;
typedef struct ILNode_CDelete__ ILNode_CDelete;
typedef struct ILNode_CSizeReleaseTempVar__ ILNode_CSizeReleaseTempVar;
typedef struct ILNode_CSizeMax__ ILNode_CSizeMax;
typedef struct ILNode_CInvocationExpression__ ILNode_CInvocationExpression;
typedef struct ILNode_AsmStmt__ ILNode_AsmStmt;
typedef struct ILNode_CAssignArray__ ILNode_CAssignArray;
typedef struct ILNode_CAssignStruct__ ILNode_CAssignStruct;
typedef struct ILNode_CGotoPtr__ ILNode_CGotoPtr;

struct ILNode_CDeclarator__ {
	const struct ILNode_CDeclarator_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	CDeclarator decl;
};

struct ILNode_CDeclarator_vtable__ {
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

extern struct ILNode_CDeclarator_vtable__ const ILNode_CDeclarator_vt__;

struct ILNode_CSharpInvocation__ {
	const struct ILNode_CSharpInvocation_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILType * type;
	char * name;
	ILNode * thisExpr;
	ILNode * args;
};

struct ILNode_CSharpInvocation_vtable__ {
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

extern struct ILNode_CSharpInvocation_vtable__ const ILNode_CSharpInvocation_vt__;

struct ILNode_CAttribute__ {
	const struct ILNode_CAttribute_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILNode * args;
};

struct ILNode_CAttribute_vtable__ {
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

extern struct ILNode_CAttribute_vtable__ const ILNode_CAttribute_vt__;

struct ILNode_CAttributeValue__ {
	const struct ILNode_CAttributeValue_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILEvalValue value;
};

struct ILNode_CAttributeValue_vtable__ {
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

extern struct ILNode_CAttributeValue_vtable__ const ILNode_CAttributeValue_vt__;

struct ILNode_CBitFieldDeclarator__ {
	const struct ILNode_CBitFieldDeclarator_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	CDeclarator decl;
	ILUInt32 bitFieldSize;
};

struct ILNode_CBitFieldDeclarator_vtable__ {
	const struct ILNode_CDeclarator_vtable__ *parent__;
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

extern struct ILNode_CBitFieldDeclarator_vtable__ const ILNode_CBitFieldDeclarator_vt__;

struct ILNode_CInitDeclarator__ {
	const struct ILNode_CInitDeclarator_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	CDeclarator decl;
	ILNode * init;
};

struct ILNode_CInitDeclarator_vtable__ {
	const struct ILNode_CDeclarator_vtable__ *parent__;
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

extern struct ILNode_CInitDeclarator_vtable__ const ILNode_CInitDeclarator_vt__;

struct ILNode_SizeOfType__ {
	const struct ILNode_SizeOfType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILType * type;
};

struct ILNode_SizeOfType_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_SizeOfType_vtable__ const ILNode_SizeOfType_vt__;

extern ILMachineType ILNode_SizeOfType_ILNode_GetType__(ILNode_SizeOfType *node, ILGenInfo * info);
extern ILMachineType ILNode_SizeOfType_ILNode_GenValue__(ILNode_SizeOfType *node, ILGenInfo * info);
extern int ILNode_SizeOfType_ILNode_EvalConst__(ILNode_SizeOfType *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_SizeOfType_JavaGenValue__(ILNode_SizeOfType *node, ILGenInfo * info);

struct ILNode_VaStart__ {
	const struct ILNode_VaStart_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * vaList;
	char * name;
};

struct ILNode_VaStart_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_VaStart_vtable__ const ILNode_VaStart_vt__;

extern ILMachineType ILNode_VaStart_ILNode_GetType__(ILNode_VaStart *node, ILGenInfo * info);
extern void ILNode_VaStart_ILNode_GenDiscard__(ILNode_VaStart *node, ILGenInfo * info);
extern ILMachineType ILNode_VaStart_ILNode_GenValue__(ILNode_VaStart *node, ILGenInfo * info);
extern ILMachineType ILNode_VaStart_JavaGenValue__(ILNode_VaStart *node, ILGenInfo * info);

struct ILNode_VaEnd__ {
	const struct ILNode_VaEnd_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * vaList;
};

struct ILNode_VaEnd_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_VaEnd_vtable__ const ILNode_VaEnd_vt__;

extern ILMachineType ILNode_VaEnd_ILNode_GetType__(ILNode_VaEnd *node, ILGenInfo * info);
extern void ILNode_VaEnd_ILNode_GenDiscard__(ILNode_VaEnd *node, ILGenInfo * info);
extern ILMachineType ILNode_VaEnd_ILNode_GenValue__(ILNode_VaEnd *node, ILGenInfo * info);
extern ILMachineType ILNode_VaEnd_JavaGenValue__(ILNode_VaEnd *node, ILGenInfo * info);

struct ILNode_VaArg__ {
	const struct ILNode_VaArg_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * vaList;
	ILType * type;
};

struct ILNode_VaArg_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_VaArg_vtable__ const ILNode_VaArg_vt__;

extern ILMachineType ILNode_VaArg_ILNode_GetType__(ILNode_VaArg *node, ILGenInfo * info);
extern ILMachineType ILNode_VaArg_ILNode_GenValue__(ILNode_VaArg *node, ILGenInfo * info);
extern ILMachineType ILNode_VaArg_JavaGenValue__(ILNode_VaArg *node, ILGenInfo * info);

struct ILNode_FunctionRef__ {
	const struct ILNode_FunctionRef_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILType * signature;
};

struct ILNode_FunctionRef_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_FunctionRef_vtable__ const ILNode_FunctionRef_vt__;

extern ILMachineType ILNode_FunctionRef_ILNode_GetType__(ILNode_FunctionRef *node, ILGenInfo * info);
extern ILMachineType ILNode_FunctionRef_ILNode_GenValue__(ILNode_FunctionRef *node, ILGenInfo * info);
extern ILMachineType ILNode_FunctionRef_JavaGenValue__(ILNode_FunctionRef *node, ILGenInfo * info);

struct ILNode_CLabelRef__ {
	const struct ILNode_CLabelRef_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILInt32 labelNum;
};

struct ILNode_CLabelRef_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CLabelRef_vtable__ const ILNode_CLabelRef_vt__;

extern ILMachineType ILNode_CLabelRef_ILNode_GetType__(ILNode_CLabelRef *node, ILGenInfo * info);
extern ILMachineType ILNode_CLabelRef_ILNode_GenValue__(ILNode_CLabelRef *node, ILGenInfo * info);
extern int ILNode_CLabelRef_ILNode_EvalConst__(ILNode_CLabelRef *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_CLabelRef_JavaGenValue__(ILNode_CLabelRef *node, ILGenInfo * info);

struct ILNode_CSharpTypeOf__ {
	const struct ILNode_CSharpTypeOf_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILType * type;
};

struct ILNode_CSharpTypeOf_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CSharpTypeOf_vtable__ const ILNode_CSharpTypeOf_vt__;

extern ILMachineType ILNode_CSharpTypeOf_ILNode_GetType__(ILNode_CSharpTypeOf *node, ILGenInfo * info);
extern ILMachineType ILNode_CSharpTypeOf_ILNode_GenValue__(ILNode_CSharpTypeOf *node, ILGenInfo * info);
extern ILMachineType ILNode_CSharpTypeOf_JavaGenValue__(ILNode_CSharpTypeOf *node, ILGenInfo * info);

struct ILNode_CTypeExpression__ {
	const struct ILNode_CTypeExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILType * type;
};

struct ILNode_CTypeExpression_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CTypeExpression_vtable__ const ILNode_CTypeExpression_vt__;

extern ILMachineType ILNode_CTypeExpression_ILNode_GetType__(ILNode_CTypeExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_CTypeExpression_ILNode_GenValue__(ILNode_CTypeExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_CTypeExpression_JavaGenValue__(ILNode_CTypeExpression *node, ILGenInfo * info);

struct ILNode_CNewObject__ {
	const struct ILNode_CNewObject_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILGCSpecifier specifier;
	ILType * type;
	ILNode * args;
	int useGlobalNew;
};

struct ILNode_CNewObject_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CNewObject_vtable__ const ILNode_CNewObject_vt__;

extern ILMachineType ILNode_CNewObject_ILNode_GetType__(ILNode_CNewObject *node, ILGenInfo * info);
extern ILMachineType ILNode_CNewObject_ILNode_GenValue__(ILNode_CNewObject *node, ILGenInfo * info);
extern ILMachineType ILNode_CNewObject_JavaGenValue__(ILNode_CNewObject *node, ILGenInfo * info);

struct ILNode_CNewArray__ {
	const struct ILNode_CNewArray_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILGCSpecifier specifier;
	ILType * type;
	ILNode * expr;
	int useGlobalNew;
	ILType * resultType;
};

struct ILNode_CNewArray_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CNewArray_vtable__ const ILNode_CNewArray_vt__;

extern ILMachineType ILNode_CNewArray_ILNode_GetType__(ILNode_CNewArray *node, ILGenInfo * info);
extern ILMachineType ILNode_CNewArray_ILNode_GenValue__(ILNode_CNewArray *node, ILGenInfo * info);
extern ILMachineType ILNode_CNewArray_JavaGenValue__(ILNode_CNewArray *node, ILGenInfo * info);

struct ILNode_CSizeOfRaw__ {
	const struct ILNode_CSizeOfRaw_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILType * type;
};

struct ILNode_CSizeOfRaw_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CSizeOfRaw_vtable__ const ILNode_CSizeOfRaw_vt__;

extern ILMachineType ILNode_CSizeOfRaw_ILNode_GetType__(ILNode_CSizeOfRaw *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeOfRaw_ILNode_GenValue__(ILNode_CSizeOfRaw *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeOfRaw_JavaGenValue__(ILNode_CSizeOfRaw *node, ILGenInfo * info);

struct ILNode_CSizeTempVar__ {
	const struct ILNode_CSizeTempVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	unsigned tempVar;
};

struct ILNode_CSizeTempVar_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CSizeTempVar_vtable__ const ILNode_CSizeTempVar_vt__;

extern ILMachineType ILNode_CSizeTempVar_ILNode_GetType__(ILNode_CSizeTempVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeTempVar_ILNode_GenValue__(ILNode_CSizeTempVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeTempVar_JavaGenValue__(ILNode_CSizeTempVar *node, ILGenInfo * info);

struct ILNode_CSizeAlign__ {
	const struct ILNode_CSizeAlign_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * size;
	ILUInt32 alignFlags;
	ILType * measureType;
	ILNode * alignVar;
};

struct ILNode_CSizeAlign_vtable__ {
	const struct ILNode_Expression_vtable__ *parent__;
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

extern struct ILNode_CSizeAlign_vtable__ const ILNode_CSizeAlign_vt__;

extern ILMachineType ILNode_CSizeAlign_ILNode_GetType__(ILNode_CSizeAlign *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeAlign_ILNode_GenValue__(ILNode_CSizeAlign *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeAlign_JavaGenValue__(ILNode_CSizeAlign *node, ILGenInfo * info);

struct ILNode_CString__ {
	const struct ILNode_CString_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * str;
	int len;
};

struct ILNode_CString_vtable__ {
	const struct ILNode_String_vtable__ *parent__;
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

extern struct ILNode_CString_vtable__ const ILNode_CString_vt__;

extern ILMachineType ILNode_CString_ILNode_GetType__(ILNode_CString *node, ILGenInfo * info);
extern ILMachineType ILNode_CString_ILNode_GenValue__(ILNode_CString *node, ILGenInfo * info);
extern int ILNode_CString_ILNode_EvalConst__(ILNode_CString *node, ILGenInfo * info, ILEvalValue * value);

struct ILNode_CWString__ {
	const struct ILNode_CWString_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * str;
	int len;
};

struct ILNode_CWString_vtable__ {
	const struct ILNode_String_vtable__ *parent__;
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

extern struct ILNode_CWString_vtable__ const ILNode_CWString_vt__;

extern ILMachineType ILNode_CWString_ILNode_GetType__(ILNode_CWString *node, ILGenInfo * info);
extern ILMachineType ILNode_CWString_ILNode_GenValue__(ILNode_CWString *node, ILGenInfo * info);
extern int ILNode_CWString_ILNode_EvalConst__(ILNode_CWString *node, ILGenInfo * info, ILEvalValue * value);

struct ILNode_CLocalVar__ {
	const struct ILNode_CLocalVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	unsigned long index;
	ILMachineType machineType;
	ILType * type;
	ILType * decayedType;
};

struct ILNode_CLocalVar_vtable__ {
	const struct ILNode_LValue_vtable__ *parent__;
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

extern struct ILNode_CLocalVar_vtable__ const ILNode_CLocalVar_vt__;

extern ILMachineType ILNode_CLocalVar_ILNode_GetType__(ILNode_CLocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CLocalVar_ILNode_GenValue__(ILNode_CLocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CLocalVar_JavaGenValue__(ILNode_CLocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CLocalVar_ILNode_Prepare__(ILNode_CLocalVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CLocalVar_ILNode_GetAndPrepare__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CLocalVar_ILNode_Store__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CLocalVar_ILNode_GenRef__(ILNode_CLocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CLocalVar_JavaPrepare__(ILNode_CLocalVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CLocalVar_JavaGetAndPrepare__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CLocalVar_JavaStore__(ILNode_CLocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_CArgumentVar__ {
	const struct ILNode_CArgumentVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	unsigned long index;
	ILMachineType machineType;
	ILType * type;
};

struct ILNode_CArgumentVar_vtable__ {
	const struct ILNode_LValue_vtable__ *parent__;
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

extern struct ILNode_CArgumentVar_vtable__ const ILNode_CArgumentVar_vt__;

extern ILMachineType ILNode_CArgumentVar_ILNode_GetType__(ILNode_CArgumentVar *node, ILGenInfo * info);
extern void ILNode_CArgumentVar_ILNode_GenDiscard__(ILNode_CArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CArgumentVar_ILNode_GenValue__(ILNode_CArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CArgumentVar_JavaGenValue__(ILNode_CArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CArgumentVar_ILNode_Prepare__(ILNode_CArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CArgumentVar_ILNode_GetAndPrepare__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CArgumentVar_ILNode_Store__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CArgumentVar_ILNode_GenRef__(ILNode_CArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CArgumentVar_JavaPrepare__(ILNode_CArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CArgumentVar_JavaGetAndPrepare__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CArgumentVar_JavaStore__(ILNode_CArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_CGlobalVar__ {
	const struct ILNode_CGlobalVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
	ILType * type;
	ILType * decayedType;
};

struct ILNode_CGlobalVar_vtable__ {
	const struct ILNode_LValue_vtable__ *parent__;
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

extern struct ILNode_CGlobalVar_vtable__ const ILNode_CGlobalVar_vt__;

extern ILMachineType ILNode_CGlobalVar_ILNode_GetType__(ILNode_CGlobalVar *node, ILGenInfo * info);
extern void ILNode_CGlobalVar_ILNode_GenDiscard__(ILNode_CGlobalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CGlobalVar_ILNode_GenValue__(ILNode_CGlobalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CGlobalVar_JavaGenValue__(ILNode_CGlobalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CGlobalVar_ILNode_Prepare__(ILNode_CGlobalVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CGlobalVar_ILNode_GetAndPrepare__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CGlobalVar_ILNode_Store__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CGlobalVar_ILNode_GenRef__(ILNode_CGlobalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CGlobalVar_JavaPrepare__(ILNode_CGlobalVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CGlobalVar_JavaGetAndPrepare__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CGlobalVar_JavaStore__(ILNode_CGlobalVar *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_CFieldAccess__ {
	const struct ILNode_CFieldAccess_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	char * name;
	ILField * field;
	ILType * ownerType;
};

struct ILNode_CFieldAccess_vtable__ {
	const struct ILNode_LValue_vtable__ *parent__;
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

extern struct ILNode_CFieldAccess_vtable__ const ILNode_CFieldAccess_vt__;

struct ILNode_CDeref__ {
	const struct ILNode_CDeref_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
	ILMachineType machineType;
};

struct ILNode_CDeref_vtable__ {
	const struct ILNode_LValue_vtable__ *parent__;
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

extern struct ILNode_CDeref_vtable__ const ILNode_CDeref_vt__;

extern ILMachineType ILNode_CDeref_ILNode_GetType__(ILNode_CDeref *node, ILGenInfo * info);
extern void ILNode_CDeref_ILNode_GenDiscard__(ILNode_CDeref *node, ILGenInfo * info);
extern ILMachineType ILNode_CDeref_ILNode_GenValue__(ILNode_CDeref *node, ILGenInfo * info);
extern ILMachineType ILNode_CDeref_JavaGenValue__(ILNode_CDeref *node, ILGenInfo * info);
extern ILMachineType ILNode_CDeref_ILNode_Prepare__(ILNode_CDeref *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CDeref_ILNode_GetAndPrepare__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CDeref_ILNode_Store__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CDeref_ILNode_GenRef__(ILNode_CDeref *node, ILGenInfo * info);
extern ILMachineType ILNode_CDeref_JavaPrepare__(ILNode_CDeref *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CDeref_JavaGetAndPrepare__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CDeref_JavaStore__(ILNode_CDeref *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_CBitField__ {
	const struct ILNode_CBitField_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILField * field;
	ILMachineType machineType;
	ILUInt32 bitFieldStart;
	ILUInt32 bitFieldSize;
	int genExprAsAddr;
	unsigned tempVar;
	unsigned tempPtrVar;
};

struct ILNode_CBitField_vtable__ {
	const struct ILNode_LValueNoRef_vtable__ *parent__;
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

extern struct ILNode_CBitField_vtable__ const ILNode_CBitField_vt__;

extern ILMachineType ILNode_CBitField_ILNode_GetType__(ILNode_CBitField *node, ILGenInfo * info);
extern ILMachineType ILNode_CBitField_ILNode_GenValue__(ILNode_CBitField *node, ILGenInfo * info);
extern ILMachineType ILNode_CBitField_JavaGenValue__(ILNode_CBitField *node, ILGenInfo * info);
extern ILMachineType ILNode_CBitField_ILNode_Prepare__(ILNode_CBitField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CBitField_ILNode_GetAndPrepare__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CBitField_ILNode_Store__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_CBitField_JavaPrepare__(ILNode_CBitField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CBitField_JavaGetAndPrepare__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CBitField_JavaStore__(ILNode_CBitField *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_CArrayAccess__ {
	const struct ILNode_CArrayAccess_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * array;
	ILNode * indices;
	ILType * arrayType;
	ILType * elemType;
	long saveStack;
};

struct ILNode_CArrayAccess_vtable__ {
	const struct ILNode_ArrayAccess_vtable__ *parent__;
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

extern struct ILNode_CArrayAccess_vtable__ const ILNode_CArrayAccess_vt__;

extern ILMachineType ILNode_CArrayAccess_ILNode_GetType__(ILNode_CArrayAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_CArrayAccess_ILNode_GenValue__(ILNode_CArrayAccess *node, ILGenInfo * info);
extern int ILNode_CArrayAccess_ILNode_EvalConst__(ILNode_CArrayAccess *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_CArrayAccess_ILNode_Prepare__(ILNode_CArrayAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CArrayAccess_ILNode_GetAndPrepare__(ILNode_CArrayAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CArrayAccess_ILNode_Store__(ILNode_CArrayAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CArrayAccess_ILNode_GenRef__(ILNode_CArrayAccess *node, ILGenInfo * info);

struct ILNode_CDerefField__ {
	const struct ILNode_CDerefField_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	char * name;
	ILField * field;
	ILType * ownerType;
};

struct ILNode_CDerefField_vtable__ {
	const struct ILNode_CFieldAccess_vtable__ *parent__;
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

extern struct ILNode_CDerefField_vtable__ const ILNode_CDerefField_vt__;

extern ILMachineType ILNode_CDerefField_ILNode_GetType__(ILNode_CDerefField *node, ILGenInfo * info);
extern void ILNode_CDerefField_ILNode_GenDiscard__(ILNode_CDerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_CDerefField_ILNode_GenValue__(ILNode_CDerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_CDerefField_JavaGenValue__(ILNode_CDerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_CDerefField_ILNode_Prepare__(ILNode_CDerefField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CDerefField_ILNode_GetAndPrepare__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CDerefField_ILNode_Store__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CDerefField_ILNode_GenRef__(ILNode_CDerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_CDerefField_JavaPrepare__(ILNode_CDerefField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CDerefField_JavaGetAndPrepare__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CDerefField_JavaStore__(ILNode_CDerefField *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_CMemberField__ {
	const struct ILNode_CMemberField_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	char * name;
	ILField * field;
	ILType * ownerType;
};

struct ILNode_CMemberField_vtable__ {
	const struct ILNode_CFieldAccess_vtable__ *parent__;
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

extern struct ILNode_CMemberField_vtable__ const ILNode_CMemberField_vt__;

extern ILMachineType ILNode_CMemberField_ILNode_GetType__(ILNode_CMemberField *node, ILGenInfo * info);
extern void ILNode_CMemberField_ILNode_GenDiscard__(ILNode_CMemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_CMemberField_ILNode_GenValue__(ILNode_CMemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_CMemberField_JavaGenValue__(ILNode_CMemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_CMemberField_ILNode_Prepare__(ILNode_CMemberField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CMemberField_ILNode_GetAndPrepare__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CMemberField_ILNode_Store__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CMemberField_ILNode_GenRef__(ILNode_CMemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_CMemberField_JavaPrepare__(ILNode_CMemberField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CMemberField_JavaGetAndPrepare__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CMemberField_JavaStore__(ILNode_CMemberField *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_CStaticField__ {
	const struct ILNode_CStaticField_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	char * name;
	ILField * field;
	ILType * ownerType;
};

struct ILNode_CStaticField_vtable__ {
	const struct ILNode_CFieldAccess_vtable__ *parent__;
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

extern struct ILNode_CStaticField_vtable__ const ILNode_CStaticField_vt__;

extern ILMachineType ILNode_CStaticField_ILNode_GetType__(ILNode_CStaticField *node, ILGenInfo * info);
extern void ILNode_CStaticField_ILNode_GenDiscard__(ILNode_CStaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_CStaticField_ILNode_GenValue__(ILNode_CStaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_CStaticField_JavaGenValue__(ILNode_CStaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_CStaticField_ILNode_Prepare__(ILNode_CStaticField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CStaticField_ILNode_GetAndPrepare__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CStaticField_ILNode_Store__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_CStaticField_ILNode_GenRef__(ILNode_CStaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_CStaticField_JavaPrepare__(ILNode_CStaticField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_CStaticField_JavaGetAndPrepare__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_CStaticField_JavaStore__(ILNode_CStaticField *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_SizeOfExpr__ {
	const struct ILNode_SizeOfExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
};

struct ILNode_SizeOfExpr_vtable__ {
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

extern struct ILNode_SizeOfExpr_vtable__ const ILNode_SizeOfExpr_vt__;

extern ILMachineType ILNode_SizeOfExpr_ILNode_GetType__(ILNode_SizeOfExpr *node, ILGenInfo * info);
extern ILMachineType ILNode_SizeOfExpr_ILNode_GenValue__(ILNode_SizeOfExpr *node, ILGenInfo * info);
extern int ILNode_SizeOfExpr_ILNode_EvalConst__(ILNode_SizeOfExpr *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_SizeOfExpr_JavaGenValue__(ILNode_SizeOfExpr *node, ILGenInfo * info);

struct ILNode_SetJmp__ {
	const struct ILNode_SetJmp_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_SetJmp_vtable__ {
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

extern struct ILNode_SetJmp_vtable__ const ILNode_SetJmp_vt__;

extern ILMachineType ILNode_SetJmp_ILNode_GetType__(ILNode_SetJmp *node, ILGenInfo * info);
extern ILMachineType ILNode_SetJmp_ILNode_GenValue__(ILNode_SetJmp *node, ILGenInfo * info);
extern ILMachineType ILNode_SetJmp_JavaGenValue__(ILNode_SetJmp *node, ILGenInfo * info);

struct ILNode_AllocA__ {
	const struct ILNode_AllocA_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_AllocA_vtable__ {
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

extern struct ILNode_AllocA_vtable__ const ILNode_AllocA_vt__;

extern ILMachineType ILNode_AllocA_ILNode_GetType__(ILNode_AllocA *node, ILGenInfo * info);
extern ILMachineType ILNode_AllocA_ILNode_GenValue__(ILNode_AllocA *node, ILGenInfo * info);
extern ILMachineType ILNode_AllocA_JavaGenValue__(ILNode_AllocA *node, ILGenInfo * info);

struct ILNode_CToCSharpString__ {
	const struct ILNode_CToCSharpString_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_CToCSharpString_vtable__ {
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

extern struct ILNode_CToCSharpString_vtable__ const ILNode_CToCSharpString_vt__;

extern ILMachineType ILNode_CToCSharpString_ILNode_GetType__(ILNode_CToCSharpString *node, ILGenInfo * info);
extern ILMachineType ILNode_CToCSharpString_ILNode_GenValue__(ILNode_CToCSharpString *node, ILGenInfo * info);
extern ILMachineType ILNode_CToCSharpString_JavaGenValue__(ILNode_CToCSharpString *node, ILGenInfo * info);

struct ILNode_CArrayInit__ {
	const struct ILNode_CArrayInit_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_CArrayInit_vtable__ {
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

extern struct ILNode_CArrayInit_vtable__ const ILNode_CArrayInit_vt__;

extern ILMachineType ILNode_CArrayInit_ILNode_GetType__(ILNode_CArrayInit *node, ILGenInfo * info);
extern ILMachineType ILNode_CArrayInit_ILNode_GenValue__(ILNode_CArrayInit *node, ILGenInfo * info);
extern ILMachineType ILNode_CArrayInit_JavaGenValue__(ILNode_CArrayInit *node, ILGenInfo * info);

struct ILNode_CBox__ {
	const struct ILNode_CBox_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_CBox_vtable__ {
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

extern struct ILNode_CBox_vtable__ const ILNode_CBox_vt__;

extern ILMachineType ILNode_CBox_ILNode_GetType__(ILNode_CBox *node, ILGenInfo * info);
extern ILMachineType ILNode_CBox_ILNode_GenValue__(ILNode_CBox *node, ILGenInfo * info);
extern ILMachineType ILNode_CBox_JavaGenValue__(ILNode_CBox *node, ILGenInfo * info);

struct ILNode_CopyComplex__ {
	const struct ILNode_CopyComplex_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
};

struct ILNode_CopyComplex_vtable__ {
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

extern struct ILNode_CopyComplex_vtable__ const ILNode_CopyComplex_vt__;

extern ILMachineType ILNode_CopyComplex_ILNode_GetType__(ILNode_CopyComplex *node, ILGenInfo * info);
extern ILMachineType ILNode_CopyComplex_ILNode_GenValue__(ILNode_CopyComplex *node, ILGenInfo * info);
extern ILMachineType ILNode_CopyComplex_JavaGenValue__(ILNode_CopyComplex *node, ILGenInfo * info);

struct ILNode_CDelete__ {
	const struct ILNode_CDelete_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	int arrayDelete;
	int useGlobalDelete;
	ILMethod * dtor;
};

struct ILNode_CDelete_vtable__ {
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

extern struct ILNode_CDelete_vtable__ const ILNode_CDelete_vt__;

extern ILMachineType ILNode_CDelete_ILNode_GetType__(ILNode_CDelete *node, ILGenInfo * info);
extern void ILNode_CDelete_ILNode_GenDiscard__(ILNode_CDelete *node, ILGenInfo * info);
extern ILMachineType ILNode_CDelete_ILNode_GenValue__(ILNode_CDelete *node, ILGenInfo * info);
extern ILMachineType ILNode_CDelete_JavaGenValue__(ILNode_CDelete *node, ILGenInfo * info);

struct ILNode_CSizeReleaseTempVar__ {
	const struct ILNode_CSizeReleaseTempVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_CSizeReleaseTempVar_vtable__ {
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

extern struct ILNode_CSizeReleaseTempVar_vtable__ const ILNode_CSizeReleaseTempVar_vt__;

extern ILMachineType ILNode_CSizeReleaseTempVar_ILNode_GetType__(ILNode_CSizeReleaseTempVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeReleaseTempVar_ILNode_GenValue__(ILNode_CSizeReleaseTempVar *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeReleaseTempVar_JavaGenValue__(ILNode_CSizeReleaseTempVar *node, ILGenInfo * info);

struct ILNode_CSizeMax__ {
	const struct ILNode_CSizeMax_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_CSizeMax_vtable__ {
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

extern struct ILNode_CSizeMax_vtable__ const ILNode_CSizeMax_vt__;

extern ILMachineType ILNode_CSizeMax_ILNode_GetType__(ILNode_CSizeMax *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeMax_ILNode_GenValue__(ILNode_CSizeMax *node, ILGenInfo * info);
extern ILMachineType ILNode_CSizeMax_JavaGenValue__(ILNode_CSizeMax *node, ILGenInfo * info);

struct ILNode_CInvocationExpression__ {
	const struct ILNode_CInvocationExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILNode * thisExpr;
	ILMethod * methodInfo;
	ILType * callSiteSig;
	int baseCall;
	char * name;
};

struct ILNode_CInvocationExpression_vtable__ {
	const struct ILNode_InvocationExpression_vtable__ *parent__;
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

extern struct ILNode_CInvocationExpression_vtable__ const ILNode_CInvocationExpression_vt__;

extern ILMachineType ILNode_CInvocationExpression_ILNode_GenValue__(ILNode_CInvocationExpression *node, ILGenInfo * info);

struct ILNode_AsmStmt__ {
	const struct ILNode_AsmStmt_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * code;
};

struct ILNode_AsmStmt_vtable__ {
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

extern struct ILNode_AsmStmt_vtable__ const ILNode_AsmStmt_vt__;

extern void ILNode_AsmStmt_ILNode_GenDiscard__(ILNode_AsmStmt *node, ILGenInfo * info);
extern int ILNode_AsmStmt_ILNode_EndsInReturnImpl__(ILNode_AsmStmt *node, ILGenInfo * info);
extern void ILNode_AsmStmt_JavaGenDiscard__(ILNode_AsmStmt *node, ILGenInfo * info);

struct ILNode_CAssignArray__ {
	const struct ILNode_CAssignArray_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr1;
	ILNode * expr2;
	ILType * type;
};

struct ILNode_CAssignArray_vtable__ {
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

extern struct ILNode_CAssignArray_vtable__ const ILNode_CAssignArray_vt__;

extern void ILNode_CAssignArray_ILNode_GenDiscard__(ILNode_CAssignArray *node, ILGenInfo * info);
extern void ILNode_CAssignArray_JavaGenDiscard__(ILNode_CAssignArray *node, ILGenInfo * info);

struct ILNode_CAssignStruct__ {
	const struct ILNode_CAssignStruct_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr1;
	ILNode * expr2;
	ILType * type;
};

struct ILNode_CAssignStruct_vtable__ {
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

extern struct ILNode_CAssignStruct_vtable__ const ILNode_CAssignStruct_vt__;

extern void ILNode_CAssignStruct_ILNode_GenDiscard__(ILNode_CAssignStruct *node, ILGenInfo * info);
extern void ILNode_CAssignStruct_JavaGenDiscard__(ILNode_CAssignStruct *node, ILGenInfo * info);

struct ILNode_CGotoPtr__ {
	const struct ILNode_CGotoPtr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr;
};

struct ILNode_CGotoPtr_vtable__ {
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

extern struct ILNode_CGotoPtr_vtable__ const ILNode_CGotoPtr_vt__;

extern void ILNode_CGotoPtr_ILNode_GenDiscard__(ILNode_CGotoPtr *node, ILGenInfo * info);
extern int ILNode_CGotoPtr_ILNode_EndsInReturnImpl__(ILNode_CGotoPtr *node, ILGenInfo * info);
extern void ILNode_CGotoPtr_JavaGenDiscard__(ILNode_CGotoPtr *node, ILGenInfo * info);

extern ILNode *ILNode_CDeclarator_create(CDeclarator decl);
extern ILNode *ILNode_CSharpInvocation_create(ILType * type, char * name, ILNode * thisExpr, ILNode * args);
extern ILNode *ILNode_CAttribute_create(char * name, ILNode * args);
extern ILNode *ILNode_CAttributeValue_create(ILEvalValue value);
extern ILNode *ILNode_CBitFieldDeclarator_create(CDeclarator decl, ILUInt32 bitFieldSize);
extern ILNode *ILNode_CInitDeclarator_create(CDeclarator decl, ILNode * init);
extern ILNode *ILNode_SizeOfType_create(ILType * type);
extern ILNode *ILNode_VaStart_create(ILNode * vaList, char * name);
extern ILNode *ILNode_VaEnd_create(ILNode * vaList);
extern ILNode *ILNode_VaArg_create(ILNode * vaList, ILType * type);
extern ILNode *ILNode_FunctionRef_create(char * name, ILType * signature);
extern ILNode *ILNode_CLabelRef_create(char * name);
extern ILNode *ILNode_CSharpTypeOf_create(ILType * type);
extern ILNode *ILNode_CTypeExpression_create(ILType * type);
extern ILNode *ILNode_CNewObject_create(ILGCSpecifier specifier, ILType * type, ILNode * args, int useGlobalNew);
extern ILNode *ILNode_CNewArray_create(ILGCSpecifier specifier, ILType * type, ILNode * expr, int useGlobalNew);
extern ILNode *ILNode_CSizeOfRaw_create(ILType * type);
extern ILNode *ILNode_CSizeTempVar_create(void);
extern ILNode *ILNode_CSizeAlign_create(ILNode * size, ILUInt32 alignFlags, ILType * measureType, ILNode * alignVar);
extern ILNode *ILNode_CString_create(char * str, int len);
extern ILNode *ILNode_CWString_create(char * str, int len);
extern ILNode *ILNode_CLocalVar_create(unsigned long index, ILMachineType machineType, ILType * type, ILType * decayedType);
extern ILNode *ILNode_CArgumentVar_create(unsigned long index, ILMachineType machineType, ILType * type);
extern ILNode *ILNode_CGlobalVar_create(char * name, ILType * type, ILType * decayedType);
extern ILNode *ILNode_CDeref_create(ILNode * expr);
extern ILNode *ILNode_CBitField_create(ILNode * expr, ILField * field, ILMachineType machineType, ILUInt32 bitFieldStart, ILUInt32 bitFieldSize, int genExprAsAddr);
extern ILNode *ILNode_CArrayAccess_create(ILNode * array, ILNode * indices);
extern ILNode *ILNode_CDerefField_create(ILNode * expr, char * name);
extern ILNode *ILNode_CMemberField_create(ILNode * expr, char * name);
extern ILNode *ILNode_CStaticField_create(ILNode * expr, char * name);
extern ILNode *ILNode_SizeOfExpr_create(ILNode * expr);
extern ILNode *ILNode_SetJmp_create(ILNode * expr);
extern ILNode *ILNode_AllocA_create(ILNode * expr);
extern ILNode *ILNode_CToCSharpString_create(ILNode * expr);
extern ILNode *ILNode_CArrayInit_create(ILNode * expr);
extern ILNode *ILNode_CBox_create(ILNode * expr);
extern ILNode *ILNode_CopyComplex_create(ILNode * expr, ILType * type);
extern ILNode *ILNode_CDelete_create(ILNode * expr1, ILNode * expr2, int arrayDelete, int useGlobalDelete);
extern ILNode *ILNode_CSizeReleaseTempVar_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_CSizeMax_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_CInvocationExpression_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_AsmStmt_create(char * code);
extern ILNode *ILNode_CAssignArray_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_CAssignStruct_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_CGotoPtr_create(ILNode * expr);

extern CSemValue ILNode_CSemAnalysis(ILNode * node, ILGenInfo * info, ILNode * * parent, int stmtLevel);
extern CAddress ILNode_CGenAddress(ILNode_LValue * node, ILGenInfo * info);
extern void ILNode_CollectCases(ILNode * node, ILGenInfo * info, ILNode * list);
extern CName ILNode_CName(ILNode * node);

#ifdef __cplusplus
};
#endif

#line 21 "c_const.tc"


/*
 * Get the index of a particular string within the string constant pool.
 */
ILUInt32 CGenStringIndex(ILGenInfo *info, const char *str, int len);

/*
 * Get the length of a wide character string.
 */
ILUInt32 CGenWStringLength(const char *str, int len);

/*
 * Get the index of a particular wide string within the string constant pool.
 */
ILUInt32 CGenWStringIndex(ILGenInfo *info, const char *str, int len);

/*
 * Dump the contents of the string constant pool.
 */
void CGenStringPool(ILGenInfo *info);

#line 2202 "c_defs.h"
#endif
