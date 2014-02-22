/* java_nodes.c.  Generated automatically by treecc */
#line 101 "java_defs.tc"

#include <cscc/java/java_internal.h>
#line 6 "java_nodes.c"

struct ILNode_JPrimitiveType_vtable__ const ILNode_JPrimitiveType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_JPrimitiveType_kind,
	"ILNode_JPrimitiveType",
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

struct ILNode_JArrayType_vtable__ const ILNode_JArrayType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_JArrayType_kind,
	"ILNode_JArrayType",
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

struct ILNode_JPackage_vtable__ const ILNode_JPackage_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_JPackage_kind,
	"ILNode_JPackage",
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

struct ILNode_JImport_vtable__ const ILNode_JImport_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_JImport_kind,
	"ILNode_JImport",
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

struct ILNode_JSystemType_vtable__ const ILNode_JSystemType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_JSystemType_kind,
	"ILNode_JSystemType",
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

struct ILNode_ILSystemType_vtable__ const ILNode_ILSystemType_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_ILSystemType_kind,
	"ILNode_ILSystemType",
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

struct ILNode_JTypeSuffix_vtable__ const ILNode_JTypeSuffix_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_JTypeSuffix_kind,
	"ILNode_JTypeSuffix",
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

struct ILNode_TypeSuffixDeclarator_vtable__ const ILNode_TypeSuffixDeclarator_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_TypeSuffixDeclarator_kind,
	"ILNode_TypeSuffixDeclarator",
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

struct ILNode_JImportType_vtable__ const ILNode_JImportType_vt__ = {
	&ILNode_JImport_vt__,
	ILNode_JImportType_kind,
	"ILNode_JImportType",
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

struct ILNode_JImportPackage_vtable__ const ILNode_JImportPackage_vt__ = {
	&ILNode_JImport_vt__,
	ILNode_JImportPackage_kind,
	"ILNode_JImportPackage",
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

struct ILNode_InstanceOf_vtable__ const ILNode_InstanceOf_vt__ = {
	&ILNode_DummyBinaryExpr_vt__,
	ILNode_InstanceOf_kind,
	"ILNode_InstanceOf",
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

ILMachineType ILNode_JNewExpression_ILNode_GenValue__(ILNode_JNewExpression *node, ILGenInfo * info)
#line 377 "java_misc.tc"
{
	long saveStack;

	/* Bail out if initializer-based (semantic analysis should
	   have turned this node into "ILNode_ArrayInit") */
	if(!(node->indexes))
	{
		return ILMachineType_ObjectRef;
	}

	/* Output the indexes */
	saveStack = info->stackHeight;
	
	if(yyisa(node->indexes,ILNode_ArgList))
	{
		/* Create the array */
		GenArrayOfArray(info,node->arrayType,node->indexes);
	}
	else
	{
		ILNode_GenValue(node->indexes,info);
		ILGenArrayNew(info,ILType_ElemType(node->arrayType));
	}

	/* Set the final stack position */
	info->stackHeight = saveStack + 1;

	/* Arrays are always object references */
	return ILMachineType_ObjectRef;
}
#line 244 "java_nodes.c"

struct ILNode_JNewExpression_vtable__ const ILNode_JNewExpression_vt__ = {
	&ILNode_NewExpression_vt__,
	ILNode_JNewExpression_kind,
	"ILNode_JNewExpression",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NewExpression_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_JNewExpression_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Expression_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Expression_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_NewExpression_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Expression_JavaGenElse__,
};

void ILNode_JMain_ILNode_GenDiscard__(ILNode_JMain *node, ILGenInfo * info)
#line 252 "java_misc.tc"
{
	unsigned arrayVar;
	unsigned indexVar;
	ILType *sig=ILMethod_Signature(node->method);
	ILType * arrayType=ILTypeGetParam(sig,1);
	ILType * elemType=ILTypeGetElemType(arrayType);

	ILLabel label1 = ILLabel_Undefined;
	ILLabel label2 = ILLabel_Undefined;
	ILLabel label3 = ILLabel_Undefined;
	ILLabel label4 = ILLabel_Undefined;


	/* We need a temporary variable for the evaluated array */
	arrayVar = ILGenTempTypedVar(info, arrayType);

	/* We need a temporary variable for the array index */
	indexVar = ILGenTempTypedVar(info, ILType_Int32);

	ILGenSimple(info,IL_OP_LDARG_0); /* load args[] */
	ILGenSimple(info,IL_OP_LDLEN); /* args.length */
	ILGenSimple(info,IL_OP_CONV_I4); /* convert to I4 */
	ILGenAdjust(info,2);
	ILGenArrayNew(info,elemType);   /* newargs = new String[..]; */
	ILGenStoreLocal(info,arrayVar); 
	ILGenAdjust(info, -1);
	
	ILGenSimple(info,IL_OP_LDC_I4_0);
	ILGenStoreLocal(info,indexVar);

	ILGenJump(info,IL_OP_BR,&label1);

	ILGenLabel(info,&label2);

	ILGenLoadLocal(info,arrayVar);
	ILGenLoadLocal(info,indexVar);
	ILGenAdjust(info,2);

	ILGenSimple(info,IL_OP_LDARG_0);
	ILGenLoadLocal(info,indexVar);
	ILGenAdjust(info,2);

	ILGenSimple(info,IL_OP_LDELEM_REF);
	ILGenAdjust(info,-1);
	
	ILGenCallByName(info,
			"class ['java.lang']'java.lang'.'String' "
			"['java.lang']'dotgnu.javawrappers'.'StringWrapper'::'op_Implicit'"
			"(class [.library]'System'.'String')");

	ILGenSimple(info,IL_OP_STELEM_REF);
	ILGenAdjust(info,-1);
	ILGenLabel(info,&label3);	
	
	ILGenLoadLocal(info,indexVar);
	ILGenSimple(info,IL_OP_LDC_I4_1);
	ILGenAdjust(info,2);
	ILGenSimple(info,IL_OP_ADD);
	ILGenAdjust(info,-1);
	ILGenStoreLocal(info,indexVar);
	ILGenAdjust(info,-1);

	ILGenLabel(info,&label1);
	ILGenLoadLocal(info,indexVar);
	ILGenSimple(info,IL_OP_LDARG_0);
	ILGenAdjust(info,2);
	ILGenSimple(info,IL_OP_LDLEN);
	ILGenSimple(info,IL_OP_CONV_I4); /* convert to I4 */
	
	ILGenJump(info,IL_OP_BLT,&label2);
	ILGenAdjust(info,-2);

	ILGenLabel(info,&label4);

	ILGenLoadLocal(info,arrayVar);
	ILGenAdjust(info,1);

	ILGenCallByMethod(info, node->method);
}
#line 344 "java_nodes.c"

void ILNode_JMain_JavaGenDiscard__(ILNode_JMain *node, ILGenInfo * info)
#line 333 "java_misc.tc"
{
	// why ?
}
#line 351 "java_nodes.c"

struct ILNode_JMain_vtable__ const ILNode_JMain_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_JMain_kind,
	"ILNode_JMain",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_JMain_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_JMain_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

ILNode *ILNode_JPrimitiveType_create(ILUInt32 elementType)
{
	ILNode_JPrimitiveType *node__ = (ILNode_JPrimitiveType *)yynodealloc(sizeof(struct ILNode_JPrimitiveType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JPrimitiveType_vt__;
	node__->kind__ = ILNode_JPrimitiveType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->elementType = elementType;
	return (ILNode *)node__;
}

ILNode *ILNode_JArrayType_create(ILNode * type, ILUInt32 numDimensions)
{
	ILNode_JArrayType *node__ = (ILNode_JArrayType *)yynodealloc(sizeof(struct ILNode_JArrayType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JArrayType_vt__;
	node__->kind__ = ILNode_JArrayType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->numDimensions = numDimensions;
	return (ILNode *)node__;
}

ILNode *ILNode_JPackage_create(char * name)
{
	ILNode_JPackage *node__ = (ILNode_JPackage *)yynodealloc(sizeof(struct ILNode_JPackage__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JPackage_vt__;
	node__->kind__ = ILNode_JPackage_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->import = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_JImport_create(char * name)
{
	ILNode_JImport *node__ = (ILNode_JImport *)yynodealloc(sizeof(struct ILNode_JImport__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JImport_vt__;
	node__->kind__ = ILNode_JImport_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->next = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_JSystemType_create(char * className)
{
	ILNode_JSystemType *node__ = (ILNode_JSystemType *)yynodealloc(sizeof(struct ILNode_JSystemType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JSystemType_vt__;
	node__->kind__ = ILNode_JSystemType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->className = className;
	return (ILNode *)node__;
}

ILNode *ILNode_ILSystemType_create(char * className)
{
	ILNode_ILSystemType *node__ = (ILNode_ILSystemType *)yynodealloc(sizeof(struct ILNode_ILSystemType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ILSystemType_vt__;
	node__->kind__ = ILNode_ILSystemType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->className = className;
	return (ILNode *)node__;
}

ILNode *ILNode_JTypeSuffix_create(ILUInt32 count)
{
	ILNode_JTypeSuffix *node__ = (ILNode_JTypeSuffix *)yynodealloc(sizeof(struct ILNode_JTypeSuffix__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JTypeSuffix_vt__;
	node__->kind__ = ILNode_JTypeSuffix_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->count = count;
	return (ILNode *)node__;
}

ILNode *ILNode_TypeSuffixDeclarator_create(ILNode * name, int dims)
{
	ILNode_TypeSuffixDeclarator *node__ = (ILNode_TypeSuffixDeclarator *)yynodealloc(sizeof(struct ILNode_TypeSuffixDeclarator__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_TypeSuffixDeclarator_vt__;
	node__->kind__ = ILNode_TypeSuffixDeclarator_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->dims = dims;
	return (ILNode *)node__;
}

ILNode *ILNode_JImportType_create(char * name)
{
	ILNode_JImportType *node__ = (ILNode_JImportType *)yynodealloc(sizeof(struct ILNode_JImportType__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JImportType_vt__;
	node__->kind__ = ILNode_JImportType_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->next = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_JImportPackage_create(char * name)
{
	ILNode_JImportPackage *node__ = (ILNode_JImportPackage *)yynodealloc(sizeof(struct ILNode_JImportPackage__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JImportPackage_vt__;
	node__->kind__ = ILNode_JImportPackage_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->name = name;
	node__->next = 0;
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

ILNode *ILNode_InstanceOf_create(ILNode * expr1, ILNode * expr2)
{
	ILNode_InstanceOf *node__ = (ILNode_InstanceOf *)yynodealloc(sizeof(struct ILNode_InstanceOf__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_InstanceOf_vt__;
	node__->kind__ = ILNode_InstanceOf_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (ILNode *)node__;
}

ILNode *ILNode_JNewExpression_create(ILNode * type, ILNode * indexes, ILNode * rank, ILNode * arrayInitializer)
{
	ILNode_JNewExpression *node__ = (ILNode_JNewExpression *)yynodealloc(sizeof(struct ILNode_JNewExpression__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JNewExpression_vt__;
	node__->kind__ = ILNode_JNewExpression_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = type;
	node__->indexes = indexes;
	node__->rank = rank;
	node__->arrayInitializer = arrayInitializer;
	node__->arrayType = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_JMain_create(ILMethod * method)
{
	ILNode_JMain *node__ = (ILNode_JMain *)yynodealloc(sizeof(struct ILNode_JMain__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_JMain_vt__;
	node__->kind__ = ILNode_JMain_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->method = method;
	return (ILNode *)node__;
}

