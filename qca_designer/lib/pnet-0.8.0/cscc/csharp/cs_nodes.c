/* cs_nodes.c.  Generated automatically by treecc */
#line 48 "cs_defs.tc"

#include <cscc/csharp/cs_internal.h>
#line 6 "cs_nodes.c"

struct ILNode_DummySem_vtable__ const ILNode_DummySem_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_DummySem_kind,
	"ILNode_DummySem",
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

struct ILNode_ArrayType_vtable__ const ILNode_ArrayType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_ArrayType_kind,
	"ILNode_ArrayType",
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

struct ILNode_PtrType_vtable__ const ILNode_PtrType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_PtrType_kind,
	"ILNode_PtrType",
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

struct ILNode_PrimitiveType_vtable__ const ILNode_PrimitiveType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_PrimitiveType_kind,
	"ILNode_PrimitiveType",
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

struct ILNode_SystemType_vtable__ const ILNode_SystemType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_SystemType_kind,
	"ILNode_SystemType",
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

struct ILNode_TypeSuffix_vtable__ const ILNode_TypeSuffix_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_TypeSuffix_kind,
	"ILNode_TypeSuffix",
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

struct ILNode_LocalVariableType_vtable__ const ILNode_LocalVariableType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_LocalVariableType_kind,
	"ILNode_LocalVariableType",
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

struct ILNode_TypeActuals_vtable__ const ILNode_TypeActuals_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_TypeActuals_kind,
	"ILNode_TypeActuals",
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

struct ILNode_GenericReference_vtable__ const ILNode_GenericReference_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_GenericReference_kind,
	"ILNode_GenericReference",
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

struct ILNode_FixedVariable_vtable__ const ILNode_FixedVariable_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_FixedVariable_kind,
	"ILNode_FixedVariable",
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

void ILNode_ResourceDeclaration_ILNode_GenDiscard__(ILNode_ResourceDeclaration *node, ILGenInfo * info)
#line 2056 "cs_stmt.tc"
{
	ILNode_GenDiscard(node->init,info);
}
#line 183 "cs_nodes.c"

struct ILNode_ResourceDeclaration_vtable__ const ILNode_ResourceDeclaration_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_ResourceDeclaration_kind,
	"ILNode_ResourceDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ResourceDeclaration_ILNode_GenDiscard__,
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

void ILNode_BaseDestructor_ILNode_GenDiscard__(ILNode_BaseDestructor *node, ILGenInfo * info)
#line 671 "cs_misc.tc"
{
	ILNode_GenDiscard(node->destructor,info);
}
#line 207 "cs_nodes.c"

struct ILNode_BaseDestructor_vtable__ const ILNode_BaseDestructor_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_BaseDestructor_kind,
	"ILNode_BaseDestructor",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BaseDestructor_ILNode_GenDiscard__,
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

struct ILNode_DocComment_vtable__ const ILNode_DocComment_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_DocComment_kind,
	"ILNode_DocComment",
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

struct ILNode_StandaloneAttr_vtable__ const ILNode_StandaloneAttr_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_StandaloneAttr_kind,
	"ILNode_StandaloneAttr",
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

struct ILNode_Namespace_vtable__ const ILNode_Namespace_vt__ = {
	&ILNode_DummySem_vt__,
	ILNode_Namespace_kind,
	"ILNode_Namespace",
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

struct ILNode_UsingAlias_vtable__ const ILNode_UsingAlias_vt__ = {
	&ILNode_DummySem_vt__,
	ILNode_UsingAlias_kind,
	"ILNode_UsingAlias",
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

struct ILNode_UsingNamespace_vtable__ const ILNode_UsingNamespace_vt__ = {
	&ILNode_DummySem_vt__,
	ILNode_UsingNamespace_kind,
	"ILNode_UsingNamespace",
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

struct ILNode_FixAddress_vtable__ const ILNode_FixAddress_vt__ = {
	&ILNode_FixedVariable_vt__,
	ILNode_FixAddress_kind,
	"ILNode_FixAddress",
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

struct ILNode_FixExpr_vtable__ const ILNode_FixExpr_vt__ = {
	&ILNode_FixedVariable_vt__,
	ILNode_FixExpr_kind,
	"ILNode_FixExpr",
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

struct ILNode_SemGuard_vtable__ const ILNode_SemGuard_vt__ = {
	&ILNode_AsIs_vt__,
	ILNode_SemGuard_kind,
	"ILNode_SemGuard",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_AsIs_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_JavaStore__,
};

struct ILNode_GlobalNamespace_vtable__ const ILNode_GlobalNamespace_vt__ = {
	&ILNode_AsIs_vt__,
	ILNode_GlobalNamespace_kind,
	"ILNode_GlobalNamespace",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_AsIs_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_AsIs_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_AsIs_JavaGenElse__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_ILNode_Prepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_ILNode_GetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_ILNode_Store__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info))ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2))ILNode_AsIs_JavaPrepare__,
	(ILMachineType (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2))ILNode_AsIs_JavaGetAndPrepare__,
	(void (*)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2))ILNode_AsIs_JavaStore__,
};

ILMachineType ILNode_TypeOf_ILNode_GetType__(ILNode_TypeOf *node, ILGenInfo * info)
#line 60 "cs_misc.tc"
{
	return ILMachineType_ObjectRef;
}
#line 398 "cs_nodes.c"

ILMachineType ILNode_TypeOf_ILNode_GenValue__(ILNode_TypeOf *node, ILGenInfo * info)
#line 68 "cs_misc.tc"
{
	ILGenTypeToken(info, IL_OP_LDTOKEN, node->type);
	ILGenAdjust(info, 1);
	ILGenCallByName(info,
			"class [.library]System.Type "
				"[.library]System.Type::GetTypeFromHandle"
				"(valuetype [.library]System.RuntimeTypeHandle)");
	return ILMachineType_ObjectRef;
}
#line 411 "cs_nodes.c"

ILMachineType ILNode_TypeOf_JavaGenValue__(ILNode_TypeOf *node, ILGenInfo * info)
#line 82 "cs_misc.tc"
{
	const char *name;

	/* Use the "System.Type.GetType" method to resolve the type,
	   because the JVM does not have an equivalent to "ldtoken" */
	name = CSTypeToName(node->type);
	JavaGenStringConst(info, name, strlen(name));
	JavaGenCallByName(info, "System/String", "__FromJavaString",
					  "(Ljava/lang/String;)LSystem/String;");
	JavaGenAdjust(info, 1);
	JavaGenCallByName(info, "System/Type", "GetType",
					  "(LSystem/String;)LSystem/Type;");

	/* The type of the whole expression is "object reference" */
	return ILMachineType_ObjectRef;
}
#line 431 "cs_nodes.c"

struct ILNode_TypeOf_vtable__ const ILNode_TypeOf_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_TypeOf_kind,
	"ILNode_TypeOf",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_TypeOf_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_TypeOf_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_TypeOf_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

ILMachineType ILNode_SizeOf_ILNode_GetType__(ILNode_SizeOf *node, ILGenInfo * info)
#line 103 "cs_misc.tc"
{
	return ILMachineType_Int32;
}
#line 455 "cs_nodes.c"

ILMachineType ILNode_SizeOf_ILNode_GenValue__(ILNode_SizeOf *node, ILGenInfo * info)
#line 111 "cs_misc.tc"
{
	if(node->size != 0)
	{
		ILGenInt32(info, node->size);
	}
	else
	{
		ILClass *classInfo = ILTypeToClass(info, node->type);
		ILGenClassToken(info, IL_OP_PREFIX + IL_PREFIX_OP_SIZEOF, classInfo);
	}
	ILGenAdjust(info, 1);
	return ILMachineType_Int32;
}
#line 472 "cs_nodes.c"

int ILNode_SizeOf_ILNode_EvalConst__(ILNode_SizeOf *node, ILGenInfo * info, ILEvalValue * value)
#line 129 "cs_misc.tc"
{
	if(node->size != 0)
	{
		value->valueType = ILMachineType_Int32;
		value->un.i4Value = node->size;
		return 1;
	}
	else
	{
		/* Non-primitive types must be evaluated at runtime */
		return 0;
	}
}
#line 489 "cs_nodes.c"

ILMachineType ILNode_SizeOf_JavaGenValue__(ILNode_SizeOf *node, ILGenInfo * info)
#line 147 "cs_misc.tc"
{
	/* Only called for primitive types */
	JavaGenInt32(info, node->size);
	JavaGenAdjust(info, 1);
	return ILMachineType_Int32;
}
#line 499 "cs_nodes.c"

struct ILNode_SizeOf_vtable__ const ILNode_SizeOf_vt__ = {
	&ILNode_UnaryExpression_vt__,
	ILNode_SizeOf_kind,
	"ILNode_SizeOf",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOf_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOf_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_SizeOf_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_SizeOf_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_ToAttrConst_vtable__ const ILNode_ToAttrConst_vt__ = {
	&ILNode_ToConst_vt__,
	ILNode_ToAttrConst_kind,
	"ILNode_ToAttrConst",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToConst_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToConst_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_ToConst_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_ToConst_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_ToConst_JavaGenElse__,
};

ILMachineType ILNode_StackAlloc_ILNode_GetType__(ILNode_StackAlloc *node, ILGenInfo * info)
#line 266 "cs_misc.tc"
{
	if(info->outputIsJava)
	{
		return ILMachineType_ObjectRef;
	}
	else
	{
		return ILMachineType_UnmanagedPtr;
	}
}
#line 547 "cs_nodes.c"

ILMachineType ILNode_StackAlloc_ILNode_GenValue__(ILNode_StackAlloc *node, ILGenInfo * info)
#line 281 "cs_misc.tc"
{
	/* TODO */
	return ILMachineType_UnmanagedPtr;
}
#line 555 "cs_nodes.c"

ILMachineType ILNode_StackAlloc_JavaGenValue__(ILNode_StackAlloc *node, ILGenInfo * info)
#line 290 "cs_misc.tc"
{
	/* TODO */
	return ILMachineType_ObjectRef;
}
#line 563 "cs_nodes.c"

struct ILNode_StackAlloc_vtable__ const ILNode_StackAlloc_vt__ = {
	&ILNode_BinaryExpression_vt__,
	ILNode_StackAlloc_kind,
	"ILNode_StackAlloc",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StackAlloc_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StackAlloc_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_StackAlloc_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

struct ILNode_UserCast_vtable__ const ILNode_UserCast_vt__ = {
	&ILNode_DummyBinaryExpr_vt__,
	ILNode_UserCast_kind,
	"ILNode_UserCast",
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

struct ILNode_IsUntyped_vtable__ const ILNode_IsUntyped_vt__ = {
	&ILNode_DummyBinaryExpr_vt__,
	ILNode_IsUntyped_kind,
	"ILNode_IsUntyped",
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

struct ILNode_AsUntyped_vtable__ const ILNode_AsUntyped_vt__ = {
	&ILNode_DummyBinaryExpr_vt__,
	ILNode_AsUntyped_kind,
	"ILNode_AsUntyped",
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

void ILNode_Fixed_ILNode_GenDiscard__(ILNode_Fixed *node, ILGenInfo * info)
#line 1727 "cs_stmt.tc"
{
	ILNode_GenDiscard(node->decls,info);
	ILNode_GenDiscard(node->stmt,info);
}
#line 639 "cs_nodes.c"

int ILNode_Fixed_ILNode_EndsInReturnImpl__(ILNode_Fixed *node, ILGenInfo * info)
#line 1744 "cs_stmt.tc"
{
	return ILNode_EndsInReturnImpl(node->stmt,info);
}
#line 646 "cs_nodes.c"

void ILNode_Fixed_JavaGenDiscard__(ILNode_Fixed *node, ILGenInfo * info)
#line 1736 "cs_stmt.tc"
{
	/* Nothing to do here: `fixed' is illegal for Java code */
}
#line 653 "cs_nodes.c"

struct ILNode_Fixed_vtable__ const ILNode_Fixed_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Fixed_kind,
	"ILNode_Fixed",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Fixed_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Fixed_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Fixed_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Using_ILNode_GenDiscard__(ILNode_Using *node, ILGenInfo * info)
#line 1518 "cs_stmt.tc"
{
	ILNode *vars;
	ILNode_ListIter iter;
	ILNode_LocalVar *varNode;
	unsigned tempVar=0;
	
	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	if(yyisa(node->resource,ILNode_ResourceDeclaration))
	{
		ILNode_GenDiscard(node->resource,info);
	}
	else if(yyisa(node->resource,ILNode_Expression))
	{
		tempVar=ILGenTempTypedVar(info,ILFindSystemType(info,"IDisposable"));
		ILNode_GenValue(node->resource,info);
		ILGenStoreLocal(info,tempVar);	
		ILGenAdjust(info,-1);
	}
	
	/* Encapsulate the loop in a "try" block so that the "Dispose"
	   method can be called in finally */
	if(info->asmOutput)
	{
		fputs("\t.try {\n", info->asmOutput);
	}
	ILGenPushTry(info);
	ILNode_GenDiscard(node->stmt,info);
	ILGenJump(info, IL_OP_LEAVE, &label1);
	ILGenPopTry(info);
	if(info->asmOutput)
	{
		fputs("\t} finally {\n", info->asmOutput);
	}
	if(yyisa(node->resource,ILNode_ResourceDeclaration))
	{
		vars=((ILNode_ResourceDeclaration*)(node->resource))->variables;
		ILNode_ListIter_Init(&iter, vars);
		while((varNode = (ILNode_LocalVar*)ILNode_ListIter_Next(&iter)) != 0)
		{
			ILGenLoadLocal(info, varNode->index);
			ILGenAdjust(info, 1);
			ILGenJump(info, IL_OP_BRFALSE, &label2);
			ILGenAdjust(info,-1);
			ILGenLoadLocal(info, varNode->index);
			ILGenAdjust(info, 1);
			ILGenCallVirtual(info, 
				"void [.library]System.IDisposable::Dispose()");
			ILGenAdjust(info, -1);
		}
	}
	else if(yyisa(node->resource,ILNode_Expression))
	{
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);
		ILGenJump(info, IL_OP_BRFALSE, &label2);
		ILGenAdjust(info,-1);
		ILGenLoadLocal(info, tempVar);
		ILGenAdjust(info, 1);
		ILGenCallVirtual(info, 
			"void [.library]System.IDisposable::Dispose()");
		ILGenAdjust(info, -1);
		ILGenReleaseTempVar(info,tempVar);
	}
	ILGenSimple(info, IL_OP_ENDFINALLY);
	ILGenLabel(info,&label2);
	if(info->asmOutput)
	{
		fputs("\t}\n",info->asmOutput);
	}
	ILGenLabel(info,&label1);
}
#line 746 "cs_nodes.c"

int ILNode_Using_ILNode_EndsInReturnImpl__(ILNode_Using *node, ILGenInfo * info)
#line 1603 "cs_stmt.tc"
{
	return ILNode_EndsInReturnImpl(node->stmt,info);
}
#line 753 "cs_nodes.c"

void ILNode_Using_JavaGenDiscard__(ILNode_Using *node, ILGenInfo * info)
#line 1595 "cs_stmt.tc"
{
	/* TODO */
}
#line 760 "cs_nodes.c"

struct ILNode_Using_vtable__ const ILNode_Using_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Using_kind,
	"ILNode_Using",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Using_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Using_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Using_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Unsafe_ILNode_GenDiscard__(ILNode_Unsafe *node, ILGenInfo * info)
#line 1622 "cs_stmt.tc"
{
	ILNode_GenDiscard(node->stmt, info);
}
#line 784 "cs_nodes.c"

int ILNode_Unsafe_ILNode_EndsInReturnImpl__(ILNode_Unsafe *node, ILGenInfo * info)
#line 1638 "cs_stmt.tc"
{
	return ILNode_EndsInReturnImpl(node->stmt,info);
}
#line 791 "cs_nodes.c"

void ILNode_Unsafe_JavaGenDiscard__(ILNode_Unsafe *node, ILGenInfo * info)
#line 1630 "cs_stmt.tc"
{
	JavaGenDiscard(node->stmt, info);
}
#line 798 "cs_nodes.c"

struct ILNode_Unsafe_vtable__ const ILNode_Unsafe_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Unsafe_kind,
	"ILNode_Unsafe",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Unsafe_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_Unsafe_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Unsafe_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

struct ILNode_AttrIdentifier_vtable__ const ILNode_AttrIdentifier_vt__ = {
	&ILNode_Identifier_vt__,
	ILNode_AttrIdentifier_kind,
	"ILNode_AttrIdentifier",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Identifier_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Identifier_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Identifier_JavaGenElse__,
};

struct ILNode_AttrQualIdent_vtable__ const ILNode_AttrQualIdent_vt__ = {
	&ILNode_QualIdent_vt__,
	ILNode_AttrQualIdent_kind,
	"ILNode_AttrQualIdent",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_QualIdent_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_QualIdent_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_QualIdent_JavaGenElse__,
};

ILNode *ILNode_DummySem_create(void)
{
	ILNode_DummySem *node__ = (ILNode_DummySem *)yynodealloc(sizeof(struct ILNode_DummySem__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DummySem_vt__;
	node__->kind__ = ILNode_DummySem_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_ArrayType_create(ILNode * type, ILUInt32 numDimensions)
{
	ILNode_ArrayType *node__ = (ILNode_ArrayType *)yynodealloc(sizeof(struct ILNode_ArrayType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ArrayType_vt__;
	node__->kind__ = ILNode_ArrayType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->numDimensions = numDimensions;
	return (ILNode *)node__;
}

ILNode *ILNode_PtrType_create(ILNode * type)
{
	ILNode_PtrType *node__ = (ILNode_PtrType *)yynodealloc(sizeof(struct ILNode_PtrType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PtrType_vt__;
	node__->kind__ = ILNode_PtrType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	return (ILNode *)node__;
}

ILNode *ILNode_PrimitiveType_create(ILUInt32 elementType)
{
	ILNode_PrimitiveType *node__ = (ILNode_PrimitiveType *)yynodealloc(sizeof(struct ILNode_PrimitiveType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PrimitiveType_vt__;
	node__->kind__ = ILNode_PrimitiveType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->elementType = elementType;
	return (ILNode *)node__;
}

ILNode *ILNode_SystemType_create(char * className)
{
	ILNode_SystemType *node__ = (ILNode_SystemType *)yynodealloc(sizeof(struct ILNode_SystemType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SystemType_vt__;
	node__->kind__ = ILNode_SystemType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->className = className;
	return (ILNode *)node__;
}

ILNode *ILNode_TypeSuffix_create(ILUInt32 count)
{
	ILNode_TypeSuffix *node__ = (ILNode_TypeSuffix *)yynodealloc(sizeof(struct ILNode_TypeSuffix__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_TypeSuffix_vt__;
	node__->kind__ = ILNode_TypeSuffix_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->count = count;
	return (ILNode *)node__;
}

ILNode *ILNode_LocalVariableType_create(ILNode * type, ILNode * suffixes)
{
	ILNode_LocalVariableType *node__ = (ILNode_LocalVariableType *)yynodealloc(sizeof(struct ILNode_LocalVariableType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_LocalVariableType_vt__;
	node__->kind__ = ILNode_LocalVariableType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->suffixes = suffixes;
	return (ILNode *)node__;
}

ILNode *ILNode_TypeActuals_create(ILNode * left, ILNode * right)
{
	ILNode_TypeActuals *node__ = (ILNode_TypeActuals *)yynodealloc(sizeof(struct ILNode_TypeActuals__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_TypeActuals_vt__;
	node__->kind__ = ILNode_TypeActuals_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->left = left;
	node__->right = right;
	return (ILNode *)node__;
}

ILNode *ILNode_GenericReference_create(ILNode * type, ILNode * actuals)
{
	ILNode_GenericReference *node__ = (ILNode_GenericReference *)yynodealloc(sizeof(struct ILNode_GenericReference__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_GenericReference_vt__;
	node__->kind__ = ILNode_GenericReference_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->actuals = actuals;
	return (ILNode *)node__;
}

ILNode *ILNode_ResourceDeclaration_create(ILNode * type, ILNode * variables, ILNode * init)
{
	ILNode_ResourceDeclaration *node__ = (ILNode_ResourceDeclaration *)yynodealloc(sizeof(struct ILNode_ResourceDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ResourceDeclaration_vt__;
	node__->kind__ = ILNode_ResourceDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->variables = variables;
	node__->init = init;
	return (ILNode *)node__;
}

ILNode *ILNode_BaseDestructor_create(ILNode * destructor)
{
	ILNode_BaseDestructor *node__ = (ILNode_BaseDestructor *)yynodealloc(sizeof(struct ILNode_BaseDestructor__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BaseDestructor_vt__;
	node__->kind__ = ILNode_BaseDestructor_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->destructor = destructor;
	return (ILNode *)node__;
}

ILNode *ILNode_DocComment_create(char * str, int len)
{
	ILNode_DocComment *node__ = (ILNode_DocComment *)yynodealloc(sizeof(struct ILNode_DocComment__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DocComment_vt__;
	node__->kind__ = ILNode_DocComment_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->str = str;
	node__->len = len;
	return (ILNode *)node__;
}

ILNode *ILNode_StandaloneAttr_create(ILNode * namespaceNode, ILNode * attributes)
{
	ILNode_StandaloneAttr *node__ = (ILNode_StandaloneAttr *)yynodealloc(sizeof(struct ILNode_StandaloneAttr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_StandaloneAttr_vt__;
	node__->kind__ = ILNode_StandaloneAttr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->namespaceNode = namespaceNode;
	node__->attributes = attributes;
	return (ILNode *)node__;
}

ILNode *ILNode_Namespace_create(char * name, ILNode_Namespace * enclosing)
{
	ILNode_Namespace *node__ = (ILNode_Namespace *)yynodealloc(sizeof(struct ILNode_Namespace__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Namespace_vt__;
	node__->kind__ = ILNode_Namespace_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->enclosing = enclosing;
	node__->using = 0;
	node__->localScope = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_UsingAlias_create(char * name, char * ref)
{
	ILNode_UsingAlias *node__ = (ILNode_UsingAlias *)yynodealloc(sizeof(struct ILNode_UsingAlias__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UsingAlias_vt__;
	node__->kind__ = ILNode_UsingAlias_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->ref = ref;
	node__->visited = ILVisitMode_NotVisited;
	return (ILNode *)node__;
}

ILNode *ILNode_UsingNamespace_create(char * name)
{
	ILNode_UsingNamespace *node__ = (ILNode_UsingNamespace *)yynodealloc(sizeof(struct ILNode_UsingNamespace__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UsingNamespace_vt__;
	node__->kind__ = ILNode_UsingNamespace_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->next = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_FixAddress_create(ILNode * name, ILNode * address)
{
	ILNode_FixAddress *node__ = (ILNode_FixAddress *)yynodealloc(sizeof(struct ILNode_FixAddress__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_FixAddress_vt__;
	node__->kind__ = ILNode_FixAddress_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->address = address;
	return (ILNode *)node__;
}

ILNode *ILNode_FixExpr_create(ILNode * name, ILNode * expr)
{
	ILNode_FixExpr *node__ = (ILNode_FixExpr *)yynodealloc(sizeof(struct ILNode_FixExpr__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_FixExpr_vt__;
	node__->kind__ = ILNode_FixExpr_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_SemGuard_create(ILNode * expr, CSSemValue value)
{
	ILNode_SemGuard *node__ = (ILNode_SemGuard *)yynodealloc(sizeof(struct ILNode_SemGuard__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SemGuard_vt__;
	node__->kind__ = ILNode_SemGuard_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->value = value;
	return (ILNode *)node__;
}

ILNode *ILNode_GlobalNamespace_create(ILNode * expr)
{
	ILNode_GlobalNamespace *node__ = (ILNode_GlobalNamespace *)yynodealloc(sizeof(struct ILNode_GlobalNamespace__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_GlobalNamespace_vt__;
	node__->kind__ = ILNode_GlobalNamespace_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_TypeOf_create(ILNode * expr)
{
	ILNode_TypeOf *node__ = (ILNode_TypeOf *)yynodealloc(sizeof(struct ILNode_TypeOf__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_TypeOf_vt__;
	node__->kind__ = ILNode_TypeOf_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_SizeOf_create(ILNode * expr)
{
	ILNode_SizeOf *node__ = (ILNode_SizeOf *)yynodealloc(sizeof(struct ILNode_SizeOf__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_SizeOf_vt__;
	node__->kind__ = ILNode_SizeOf_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	node__->type = 0;
	node__->size = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ToAttrConst_create(ILNode * expr)
{
	ILNode_ToAttrConst *node__ = (ILNode_ToAttrConst *)yynodealloc(sizeof(struct ILNode_ToAttrConst__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ToAttrConst_vt__;
	node__->kind__ = ILNode_ToAttrConst_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr = expr;
	return (ILNode *)node__;
}

ILNode *ILNode_StackAlloc_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_StackAlloc *node__ = (ILNode_StackAlloc *)yynodealloc(sizeof(struct ILNode_StackAlloc__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_StackAlloc_vt__;
	node__->kind__ = ILNode_StackAlloc_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_UserCast_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_UserCast *node__ = (ILNode_UserCast *)yynodealloc(sizeof(struct ILNode_UserCast__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_UserCast_vt__;
	node__->kind__ = ILNode_UserCast_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_IsUntyped_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_IsUntyped *node__ = (ILNode_IsUntyped *)yynodealloc(sizeof(struct ILNode_IsUntyped__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_IsUntyped_vt__;
	node__->kind__ = ILNode_IsUntyped_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_AsUntyped_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_AsUntyped *node__ = (ILNode_AsUntyped *)yynodealloc(sizeof(struct ILNode_AsUntyped__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AsUntyped_vt__;
	node__->kind__ = ILNode_AsUntyped_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_Fixed_create(ILNode * type, ILNode * decls, ILNode * stmt)
{
	ILNode_Fixed *node__ = (ILNode_Fixed *)yynodealloc(sizeof(struct ILNode_Fixed__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Fixed_vt__;
	node__->kind__ = ILNode_Fixed_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->type = type;
	node__->decls = decls;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_Using_create(ILNode * resource, ILNode * stmt)
{
	ILNode_Using *node__ = (ILNode_Using *)yynodealloc(sizeof(struct ILNode_Using__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Using_vt__;
	node__->kind__ = ILNode_Using_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->resource = resource;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_Unsafe_create(ILNode * stmt)
{
	ILNode_Unsafe *node__ = (ILNode_Unsafe *)yynodealloc(sizeof(struct ILNode_Unsafe__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Unsafe_vt__;
	node__->kind__ = ILNode_Unsafe_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->stmt = stmt;
	return (ILNode *)node__;
}

ILNode *ILNode_AttrIdentifier_create(char * name)
{
	ILNode_AttrIdentifier *node__ = (ILNode_AttrIdentifier *)yynodealloc(sizeof(struct ILNode_AttrIdentifier__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AttrIdentifier_vt__;
	node__->kind__ = ILNode_AttrIdentifier_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	return (ILNode *)node__;
}

ILNode *ILNode_AttrQualIdent_create(ILNode * left, ILNode * right)
{
	ILNode_AttrQualIdent *node__ = (ILNode_AttrQualIdent *)yynodealloc(sizeof(struct ILNode_AttrQualIdent__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AttrQualIdent_vt__;
	node__->kind__ = ILNode_AttrQualIdent_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->left = left;
	node__->right = right;
	return (ILNode *)node__;
}

