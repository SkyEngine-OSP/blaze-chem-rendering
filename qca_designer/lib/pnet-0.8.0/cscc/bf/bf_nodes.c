/* bf_nodes.c.  Generated automatically by treecc */
#line 61 "bf_defs.tc"

#include "bf_internal.h"
#line 1 "bf_codegen.tc"

/*
 * bf_codegen.tc - IL code generator 
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 * 
 * Contributed by Gopal.V
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
#line 29 "bf_nodes.c"

struct ILNode_BF_vtable__ const ILNode_BF_vt__ = {
	&ILNode_Dummy_vt__,
	ILNode_BF_kind,
	"ILNode_BF",
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

struct ILNode_BFBody_vtable__ const ILNode_BFBody_vt__ = {
	&ILNode_BF_vt__,
	ILNode_BFBody_kind,
	"ILNode_BFBody",
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

void ILNode_BFRead_ILNode_GenDiscard__(ILNode_BFRead *node, ILGenInfo * info)
#line 103 "bf_codegen.tc"
{
	ILLabel label1 = ILLabel_Undefined;

	ILGenSimple(info,IL_OP_LDLOC_0);
	ILGenSimple(info,IL_OP_LDLOC_1);
	ILGenCallByName(info,"int32 [.library] System.Console::Read()");
	ILGenAdjust(info,3);
	
	ILGenSimple(info,IL_OP_DUP);
	ILGenSimple(info,IL_OP_LDC_I4_0);
	ILGenAdjust(info,2);
	ILGenJump(info,IL_OP_BGE,&label1);
	ILGenAdjust(info,-2);

	/* result is -1 */
	ILGenSimple(info,IL_OP_LDC_I4_1);
	ILGenAdjust(info,1);
	ILGenSimple(info,IL_OP_ADD);
	ILGenAdjust(info,-1);

	ILGenLabel(info,&label1);
	ILGenSimple(info,IL_OP_STELEM_I1);
	ILGenAdjust(info, -3);
}
#line 91 "bf_nodes.c"

struct ILNode_BFRead_vtable__ const ILNode_BFRead_vt__ = {
	&ILNode_BF_vt__,
	ILNode_BFRead_kind,
	"ILNode_BFRead",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BFRead_ILNode_GenDiscard__,
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

void ILNode_BFWrite_ILNode_GenDiscard__(ILNode_BFWrite *node, ILGenInfo * info)
#line 129 "bf_codegen.tc"
{
	ILGenSimple(info,IL_OP_LDLOC_0);
	ILGenSimple(info,IL_OP_LDLOC_1);
	ILGenAdjust(info,2);
	ILGenSimple(info,IL_OP_LDELEM_I1);
	ILGenAdjust(info,-1);
	ILGenCallByName(info,"void [.library] System.Console::Write(char)");
	ILGenAdjust(info,-1);
}
#line 121 "bf_nodes.c"

struct ILNode_BFWrite_vtable__ const ILNode_BFWrite_vt__ = {
	&ILNode_BF_vt__,
	ILNode_BFWrite_kind,
	"ILNode_BFWrite",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BFWrite_ILNode_GenDiscard__,
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

struct ILNode_BFOpt_vtable__ const ILNode_BFOpt_vt__ = {
	&ILNode_BF_vt__,
	ILNode_BFOpt_kind,
	"ILNode_BFOpt",
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

void ILNode_BFProgram_ILNode_GenDiscard__(ILNode_BFProgram *node, ILGenInfo * info)
#line 36 "bf_codegen.tc"
{
	const char * size= CCStringListGetValue(extension_flags,num_extension_flags,
		"max-array-size");
	char * name = CCStringListGetValue(extension_flags, num_extension_flags , "class-name");

	char * method = CCStringListGetValue(extension_flags, num_extension_flags , "method-name");

	if(size)
	{
		int value;
		sscanf(size,"%u",&value);
		if(value >= 8) /* minimum 8 , right ? */
		{
			maxArraySize = value;
		}
	}

	if(!name) name = "brainfck";
	if(!method) method = "Main";
	
	fprintf(info->asmOutput,
		".class public %s extends [mscorlib] System.Object \n"
		"{\n"
		".method static public void %s() il managed\n"
		"{\n"
		"\t.locals (int8[] bfarray, int32 bfarrayloc)\n"
		"\n",name,method);

	ILGenWordInsn(info,IL_OP_LDC_I4 , maxArraySize);
	ILGenAdjust(info,1);
	ILGenArrayNew(info, ILType_Int8);
	ILGenSimple(info,IL_OP_STLOC_0);
	ILGenAdjust(info,-1);
	
	ILGenWordInsn(info,IL_OP_LDC_I4 , maxArraySize/2);
	ILGenAdjust(info,1);
	ILGenSimple(info,IL_OP_STLOC_1);
	ILGenAdjust(info,-1);
	
	ILNode_GenDiscard(node->body,info);
	ILGenSimple(info,IL_OP_RET);
	
	fprintf(info->asmOutput, "\t.maxstack %ld\n", info->maxStackHeight);
	
	fprintf(info->asmOutput,"}\n"
		"}\n");
}
#line 206 "bf_nodes.c"

struct ILNode_BFProgram_vtable__ const ILNode_BFProgram_vt__ = {
	&ILNode_BFBody_vt__,
	ILNode_BFProgram_kind,
	"ILNode_BFProgram",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BFProgram_ILNode_GenDiscard__,
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

void ILNode_BFLoop_ILNode_GenDiscard__(ILNode_BFLoop *node, ILGenInfo * info)
#line 85 "bf_codegen.tc"
{
	ILLabel label1 = ILLabel_Undefined;	
	ILLabel label2 = ILLabel_Undefined;
	ILGenLabel(info, &label1);
	
	ILGenSimple(info,IL_OP_LDLOC_0);
	ILGenSimple(info,IL_OP_LDLOC_1);
	ILGenSimple(info,IL_OP_LDELEM_I1);

	ILGenJump(info,IL_OP_BRFALSE,&label2);
	
	ILNode_GenDiscard(node->body,info);
	
	ILGenJump(info,IL_OP_BR,&label1);
	ILGenLabel(info, &label2);
}
#line 243 "bf_nodes.c"

struct ILNode_BFLoop_vtable__ const ILNode_BFLoop_vt__ = {
	&ILNode_BFBody_vt__,
	ILNode_BFLoop_kind,
	"ILNode_BFLoop",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BFLoop_ILNode_GenDiscard__,
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

void ILNode_BFArith_ILNode_GenDiscard__(ILNode_BFArith *node, ILGenInfo * info)
#line 140 "bf_codegen.tc"
{
	if(!node->count)return;

	ILGenSimple(info,IL_OP_LDLOC_0);
	ILGenSimple(info,IL_OP_LDLOC_1);
	ILGenAdjust(info,2);

	ILGenSimple(info,IL_OP_LDLOC_0);
	ILGenSimple(info,IL_OP_LDLOC_1);
	ILGenAdjust(info,2);

	ILGenSimple(info,IL_OP_LDELEM_I1);
	ILGenAdjust(info,-1);
	
	if(node->count > 0)
	{
		ILGenShortInsn(info,IL_OP_LDC_I4_S,node->count);
		ILGenAdjust(info,1);
		ILGenSimple(info,IL_OP_ADD);
		ILGenAdjust(info,-1);
	}
	else
	{
		ILGenShortInsn(info,IL_OP_LDC_I4_S,-(node->count));
		ILGenAdjust(info,1);
		ILGenSimple(info,IL_OP_SUB);
		ILGenAdjust(info,-1);
	}

	ILGenSimple(info,IL_OP_STELEM_I1);
	ILGenAdjust(info,-3);
}
#line 296 "bf_nodes.c"

struct ILNode_BFArith_vtable__ const ILNode_BFArith_vt__ = {
	&ILNode_BFOpt_vt__,
	ILNode_BFArith_kind,
	"ILNode_BFArith",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BFArith_ILNode_GenDiscard__,
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

void ILNode_BFMove_ILNode_GenDiscard__(ILNode_BFMove *node, ILGenInfo * info)
#line 175 "bf_codegen.tc"
{
	if(!node->count)return;

	ILGenSimple(info,IL_OP_LDLOC_1);
	if(node->count > 0)
	{
		ILGenShortInsn(info,IL_OP_LDC_I4_S, node->count);
		ILGenAdjust(info,2);
		ILGenSimple(info,IL_OP_ADD);
	}
	else
	{
		ILGenShortInsn(info,IL_OP_LDC_I4_S, -(node->count));
		ILGenAdjust(info,2);
		ILGenSimple(info,IL_OP_SUB);
	}
	ILGenAdjust(info,-1);
	ILGenSimple(info,IL_OP_STLOC_1);
	ILGenAdjust(info,-1);
}
#line 337 "bf_nodes.c"

struct ILNode_BFMove_vtable__ const ILNode_BFMove_vt__ = {
	&ILNode_BFOpt_vt__,
	ILNode_BFMove_kind,
	"ILNode_BFMove",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Dummy_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_BFMove_ILNode_GenDiscard__,
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

ILNode *ILNode_BF_create(void)
{
	ILNode_BF *node__ = (ILNode_BF *)yynodealloc(sizeof(struct ILNode_BF__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BF_vt__;
	node__->kind__ = ILNode_BF_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_BFBody_create(ILNode * body)
{
	ILNode_BFBody *node__ = (ILNode_BFBody *)yynodealloc(sizeof(struct ILNode_BFBody__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFBody_vt__;
	node__->kind__ = ILNode_BFBody_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->body = body;
	return (ILNode *)node__;
}

ILNode *ILNode_BFRead_create(void)
{
	ILNode_BFRead *node__ = (ILNode_BFRead *)yynodealloc(sizeof(struct ILNode_BFRead__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFRead_vt__;
	node__->kind__ = ILNode_BFRead_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_BFWrite_create(void)
{
	ILNode_BFWrite *node__ = (ILNode_BFWrite *)yynodealloc(sizeof(struct ILNode_BFWrite__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFWrite_vt__;
	node__->kind__ = ILNode_BFWrite_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	return (ILNode *)node__;
}

ILNode *ILNode_BFOpt_create(signed int count)
{
	ILNode_BFOpt *node__ = (ILNode_BFOpt *)yynodealloc(sizeof(struct ILNode_BFOpt__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFOpt_vt__;
	node__->kind__ = ILNode_BFOpt_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->count = count;
	return (ILNode *)node__;
}

ILNode *ILNode_BFProgram_create(ILNode * body)
{
	ILNode_BFProgram *node__ = (ILNode_BFProgram *)yynodealloc(sizeof(struct ILNode_BFProgram__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFProgram_vt__;
	node__->kind__ = ILNode_BFProgram_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->body = body;
	return (ILNode *)node__;
}

ILNode *ILNode_BFLoop_create(ILNode * body)
{
	ILNode_BFLoop *node__ = (ILNode_BFLoop *)yynodealloc(sizeof(struct ILNode_BFLoop__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFLoop_vt__;
	node__->kind__ = ILNode_BFLoop_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->body = body;
	return (ILNode *)node__;
}

ILNode *ILNode_BFArith_create(signed int count)
{
	ILNode_BFArith *node__ = (ILNode_BFArith *)yynodealloc(sizeof(struct ILNode_BFArith__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFArith_vt__;
	node__->kind__ = ILNode_BFArith_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->count = count;
	return (ILNode *)node__;
}

ILNode *ILNode_BFMove_create(signed int count)
{
	ILNode_BFMove *node__ = (ILNode_BFMove *)yynodealloc(sizeof(struct ILNode_BFMove__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_BFMove_vt__;
	node__->kind__ = ILNode_BFMove_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->count = count;
	return (ILNode *)node__;
}

