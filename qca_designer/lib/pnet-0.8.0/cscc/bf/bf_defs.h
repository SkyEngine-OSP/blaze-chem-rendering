/* bf_defs.h.  Generated automatically by treecc */
#ifndef __yy_bf_defs_h
#define __yy_bf_defs_h
#line 30 "bf_defs.tc"


#include "../codegen/cg_nodes.h"
#include "il_utils.h"

#line 27 "bf_codegen.tc"

extern int maxArraySize;
#line 14 "bf_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ILNode_BF_kind 263
#define ILNode_BFBody_kind 264
#define ILNode_BFRead_kind 267
#define ILNode_BFWrite_kind 268
#define ILNode_BFOpt_kind 269
#define ILNode_BFProgram_kind 265
#define ILNode_BFLoop_kind 266
#define ILNode_BFArith_kind 270
#define ILNode_BFMove_kind 271

typedef struct ILNode_BF__ ILNode_BF;
typedef struct ILNode_BFBody__ ILNode_BFBody;
typedef struct ILNode_BFRead__ ILNode_BFRead;
typedef struct ILNode_BFWrite__ ILNode_BFWrite;
typedef struct ILNode_BFOpt__ ILNode_BFOpt;
typedef struct ILNode_BFProgram__ ILNode_BFProgram;
typedef struct ILNode_BFLoop__ ILNode_BFLoop;
typedef struct ILNode_BFArith__ ILNode_BFArith;
typedef struct ILNode_BFMove__ ILNode_BFMove;

struct ILNode_BF__ {
	const struct ILNode_BF_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_BF_vtable__ {
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

extern struct ILNode_BF_vtable__ const ILNode_BF_vt__;

struct ILNode_BFBody__ {
	const struct ILNode_BFBody_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * body;
};

struct ILNode_BFBody_vtable__ {
	const struct ILNode_BF_vtable__ *parent__;
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

extern struct ILNode_BFBody_vtable__ const ILNode_BFBody_vt__;

struct ILNode_BFRead__ {
	const struct ILNode_BFRead_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_BFRead_vtable__ {
	const struct ILNode_BF_vtable__ *parent__;
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

extern struct ILNode_BFRead_vtable__ const ILNode_BFRead_vt__;

extern void ILNode_BFRead_ILNode_GenDiscard__(ILNode_BFRead *node, ILGenInfo * info);

struct ILNode_BFWrite__ {
	const struct ILNode_BFWrite_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_BFWrite_vtable__ {
	const struct ILNode_BF_vtable__ *parent__;
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

extern struct ILNode_BFWrite_vtable__ const ILNode_BFWrite_vt__;

extern void ILNode_BFWrite_ILNode_GenDiscard__(ILNode_BFWrite *node, ILGenInfo * info);

struct ILNode_BFOpt__ {
	const struct ILNode_BFOpt_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	signed int count;
};

struct ILNode_BFOpt_vtable__ {
	const struct ILNode_BF_vtable__ *parent__;
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

extern struct ILNode_BFOpt_vtable__ const ILNode_BFOpt_vt__;

struct ILNode_BFProgram__ {
	const struct ILNode_BFProgram_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * body;
};

struct ILNode_BFProgram_vtable__ {
	const struct ILNode_BFBody_vtable__ *parent__;
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

extern struct ILNode_BFProgram_vtable__ const ILNode_BFProgram_vt__;

extern void ILNode_BFProgram_ILNode_GenDiscard__(ILNode_BFProgram *node, ILGenInfo * info);

struct ILNode_BFLoop__ {
	const struct ILNode_BFLoop_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * body;
};

struct ILNode_BFLoop_vtable__ {
	const struct ILNode_BFBody_vtable__ *parent__;
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

extern struct ILNode_BFLoop_vtable__ const ILNode_BFLoop_vt__;

extern void ILNode_BFLoop_ILNode_GenDiscard__(ILNode_BFLoop *node, ILGenInfo * info);

struct ILNode_BFArith__ {
	const struct ILNode_BFArith_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	signed int count;
};

struct ILNode_BFArith_vtable__ {
	const struct ILNode_BFOpt_vtable__ *parent__;
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

extern struct ILNode_BFArith_vtable__ const ILNode_BFArith_vt__;

extern void ILNode_BFArith_ILNode_GenDiscard__(ILNode_BFArith *node, ILGenInfo * info);

struct ILNode_BFMove__ {
	const struct ILNode_BFMove_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	signed int count;
};

struct ILNode_BFMove_vtable__ {
	const struct ILNode_BFOpt_vtable__ *parent__;
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

extern struct ILNode_BFMove_vtable__ const ILNode_BFMove_vt__;

extern void ILNode_BFMove_ILNode_GenDiscard__(ILNode_BFMove *node, ILGenInfo * info);

extern ILNode *ILNode_BF_create(void);
extern ILNode *ILNode_BFBody_create(ILNode * body);
extern ILNode *ILNode_BFRead_create(void);
extern ILNode *ILNode_BFWrite_create(void);
extern ILNode *ILNode_BFOpt_create(signed int count);
extern ILNode *ILNode_BFProgram_create(ILNode * body);
extern ILNode *ILNode_BFLoop_create(ILNode * body);
extern ILNode *ILNode_BFArith_create(signed int count);
extern ILNode *ILNode_BFMove_create(signed int count);


#ifdef __cplusplus
};
#endif

#endif
