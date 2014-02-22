/* cg_decls.c.  Generated automatically by treecc */
#line 3 "cg_decls.tc"

/*
 * cg_decls.tc - Declaration nodes.
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

#include <codegen/cg_nodes.h>
#include "il_dumpasm.h"

/*
 * Output the attributes that are attached to a program item.
 */
void ILGenOutputAttributes(ILGenInfo *info, FILE *stream, ILProgramItem *item)
{
	ILAttribute *attr;
	ILMethod *ctor;
	const void *value;
	unsigned long valueLen;
	unsigned long posn;
	ILDeclSecurity *decl;

	attr = 0;
	while((attr = ILProgramItemNextAttribute(item, attr)) != 0)
	{
		fputs(".custom ", stream);
		ctor = ILProgramItemToMethod(ILAttributeTypeAsItem(attr));
		if(ctor)
		{
			ILDumpMethodType(stream, info->image,
							 ILMethod_Signature(ctor),
							 IL_DUMP_QUOTE_NAMES,
							 ILMethod_Owner(ctor),
							 ILMethod_Name(ctor),
							 ctor);
		}
		if((value = ILAttributeGetValue(attr, &valueLen)) != 0)
		{
			fputs(" = (", stream);
			for(posn = 0; posn < valueLen; ++posn)
			{
				if(posn != 0)
				{
					putc(' ', stream);
				}
				fprintf(stream, "%02X",
						(int)(((const unsigned char *)value)[posn]));
			}
			putc(')', stream);
		}
		putc('\n', stream);
	}

	/* Dump declarative security blobs as well */
	if(ILProgramItemToAssembly(item) ||
	   ILProgramItemToClass(item) ||
	   ILProgramItemToMethod(item))
	{
		decl = ILDeclSecurityGetFromOwner(item);
		if(decl)
		{
			static char * const actionNames[] = {
				"demand /*nil*/", "request", "demand", "assert",
				"deny", "permitonly", "linkcheck", "inheritcheck",
				"reqmin", "reqopt", "reqrefuse", "prejitgrant",
				"prejitdeny", "noncasdemand", "noncaslinkdemand",
				"nocasinheritance"
			};
			fputs(".capability ", stream);
			fputs(actionNames[ILDeclSecurity_Type(decl) &
							  IL_META_SECURITY_ACTION_MASK], stream);
			fputs(" = (", stream);
			value = ILDeclSecurityGetBlob(decl, &valueLen);
			if(value && valueLen)
			{
				for(posn = 0; posn < valueLen; ++posn)
				{
					if(posn != 0)
					{
						putc(' ', stream);
					}
					fprintf(stream, "%02X",
							(int)(((const unsigned char *)value)[posn]));
				}
			}
			fputs(")\n", stream);
		}
	}
}

/*
 * Determine if a class has no instance fields.
 */
static int ClassIsEmpty(ILClass *classInfo)
{
	ILField *field = 0;
	while((field = (ILField *)ILClassNextMemberByKind
					(classInfo, (ILMember *)field,
					 IL_META_MEMBERKIND_FIELD)) != 0)
	{
		if(!ILField_IsStatic(field))
		{
			return 0;
		}
	}
	return 1;
}

#line 372 "cg_decls.tc"


/*
 * Dump PInvoke information for a method or field.
 */
static void DumpPInvoke(ILGenInfo *info, FILE *outstream,
						ILPInvoke *pinvoke, ILMember *member)
{
	fputs("pinvokeimpl(", outstream);
	ILDumpString(outstream,
				 ILModule_Name(ILPInvoke_Module(pinvoke)));
	putc(' ', outstream);
	if(strcmp(ILPInvoke_Alias(pinvoke), ILMember_Name(member)) != 0)
	{
		fputs("as ", outstream);
		ILDumpString(outstream, ILPInvoke_Alias(pinvoke));
		putc(' ', outstream);
	}
	ILDumpFlags(outstream, ILPInvoke_Attrs(pinvoke),
				ILPInvokeImplementationFlags, 0);
	fputs(") ", outstream);
}

/*
 * Dump information about a field to the output stream.
 */
static void DumpField(ILGenInfo *info, ILField *field, ILNode *node)
{
	ILFieldLayout *layout;
	ILPInvoke *pinvoke;

	/* Does the field have PInvoke information associated with it? */
	if(ILField_HasPInvokeImpl(field))
	{
		pinvoke = ILPInvokeFindField(field);
	}
	else
	{
		pinvoke = 0;
	}

	/* Dump the field signature and name */
	fputs(".field ", info->asmOutput);
	layout = ILFieldLayoutGetFromOwner(field);
	if(layout)
	{
		fprintf(info->asmOutput, "[%lu] ",
				(unsigned long)(ILFieldLayout_Offset(layout)));
	}
	ILDumpFlags(info->asmOutput, ILField_Attrs(field),
			    ILFieldDefinitionFlags, 0);
	if(pinvoke)
	{
		DumpPInvoke(info, info->asmOutput, pinvoke, (ILMember *)field);
	}
	ILDumpType(info->asmOutput, info->image, ILFieldGetTypeWithPrefixes(field),
			   IL_DUMP_QUOTE_NAMES);
	fputc(' ', info->asmOutput);
	ILDumpIdentifier(info->asmOutput, ILField_Name(field), 0,
					 IL_DUMP_QUOTE_NAMES);

	/* Dump the field initializer */
	ILDumpConstant(info->asmOutput, (ILProgramItem *)field, 1);

	/* Terminate the field definition */
	putc('\n', info->asmOutput);

	/* Output the line number information for the field */
	if(info->debugFlag)
	{
		fprintf(info->asmOutput, ".line %ld \"%s\"\n",
				yygetlinenum(node), yygetfilename(node));
	}

	/* Output the attributes that are attached to the field */
	ILGenOutputAttributes(info, info->asmOutput, (ILProgramItem *)field);
}

#line 608 "cg_decls.tc"


/*
 * Dump the local variable block for an IL method.
 */
static void DumpILLocals(ILGenInfo *info, FILE *outstream, ILType *localVarSig)
{
	/* Dump the local variable signature, and set the
	   base for temporary local variable allocation */
	if(localVarSig)
	{
		unsigned long num = ILTypeNumLocals(localVarSig);
		unsigned long index;
		fputs("\t.locals init\t(", outstream);
		for(index = 0; index < num; ++index)
		{
			if(index != 0)
			{
				fputs(", ", outstream);
			}
			ILDumpType(outstream, info->image,
					   ILTypeGetLocal(localVarSig, index),
					   IL_DUMP_QUOTE_NAMES);
		}
		fputs(")\n", outstream);
		info->tempLocalBase = num;
	}
	else
	{
		info->tempLocalBase = 0;
	}
}

void ILGenDumpILLocals(ILGenInfo *info, ILType *localVarSig)
{
	if(info->asmOutput)
	{
		DumpILLocals(info, info->asmOutput, localVarSig);
	}
}

/*
 * Allocate the arguments and locals for a JL method.
 */
static void AllocJLVars(ILGenInfo *info, ILType *signature,
						ILType *localVarSig)
{
	ILType *vars;
	ILType *type;
	unsigned long num;
	unsigned long index;
	ILMachineType machineType;
	char *name;

	/* Allocate frame positions to the method arguments */
	JavaGenStartFrame(info);
	vars = signature;
	if(ILType_HasThis(vars))
	{
		/* Allocate a slot for the "this" argument */
		JavaGenAddFrameSlot(info, ILMachineType_ObjectRef);
	}
	num = ILTypeNumParams(vars);
	for(index = 1; index <= num; ++index)
	{
		JavaGenAddFrameSlot
			(info, ILTypeToMachineType(ILTypeGetParam(vars, index)));
	}

	/* Allocate frame positions to the locals, and initialize them */
	JavaGenStartLocals(info);
	vars = localVarSig;
	if(vars)
	{
		num = ILTypeNumLocals(vars);
		for(index = 0; index < num; ++index)
		{
			type = ILTypeGetLocal(vars, index);
			machineType = ILTypeToMachineType(type);
			JavaGenAddFrameSlot(info, machineType);
			if(machineType == ILMachineType_Decimal && info->useJavaLib)
			{
				/* Initialize "decimal" objects using "BigDecimal" */
				JavaGenSimple(info, JAVA_OP_LCONST_0);
				JavaGenAdjust(info, 2);
				JavaGenCallByName(info, "java/math/BigDecimal",
						  "valueOf", "(J)Ljava/math/BigDecimal;");
				JavaGenStoreLocal(info, index, ILMachineType_ManagedValue);
				JavaGenAdjust(info, -2);
			}
			else if(machineType == ILMachineType_ManagedValue ||
					machineType == ILMachineType_Decimal)
			{
				/* Regular value type, which we assume has a
				   zero-argument constructor per the C# rules */
				name = JavaGetClassName(info, ILType_ToValueType(type));
				JavaGenNewObj(info, name);
				JavaGenSimple(info, JAVA_OP_DUP);
				JavaGenAdjust(info, 2);
				JavaGenCallCtor(info, name, "<init>", "()V");
				JavaGenStoreLocal(info, index, ILMachineType_ManagedValue);
				JavaGenAdjust(info, -2);
				ILFree(name);
			}
		}
		info->tempLocalBase = num;
	}
	else
	{
		info->tempLocalBase = 0;
	}
}

void ILGenEndMethod(ILGenInfo *info)
{
	ILGotoEntry *gotoEntry, *nextGoto;

	/* Flush the static array initialization classes used by the method */
	if(!(info->outputIsJava))
	{
		ILArrayInitFlush(info);
	}

	/* Clear the stack heights */
	info->stackHeight = 0;
	info->maxStackHeight = 0;

	/* Clear the return type information */
	info->returnType = ILType_Void;
	info->returnVar = -1;
	info->returnLabel = ILLabel_Undefined;
	info->gotoPtrLabel = ILLabel_Undefined;

	/* Clear the temporary throw variable */
	info->throwVariable = -1;

	/* Clear the "goto" list */
	gotoEntry = info->gotoList;
	while(gotoEntry != 0)
	{
		nextGoto = gotoEntry->next;
		ILFree(gotoEntry);
		gotoEntry = nextGoto;
	}
	info->gotoList = 0;

	/* Clear the list of temporary variables */
	info->numTempVars = 0;
	info->tempLocalBase = 0;
}

/*
 * Generate discard code for a method.
 */
static void MethodGenDiscard(ILGenInfo *info, FILE *outstream,
							 ILNode_MethodDeclaration *node,
							 ILMethod *method)
{
	ILPInvoke *pinvoke;
	int outputLabel;
	ILParameter *param;
	ILMachineType returnMachineType;
	ILOverride *over;
	ILMethod *decl;
	ILConstant *constant;

	/* Ignore the method if "suppressCodeGen" is set.  This can happen
	   for "extern" methods within the "<Module>" class, which are
	   actually imported from C into C# */
	if(node && node->suppressCodeGen)
	{
		return;
	}

	/* Does the method have PInvoke information associated with it? */
	if(ILMethod_HasPInvokeImpl(method))
	{
		pinvoke = ILPInvokeFind(method);
	}
	else
	{
		pinvoke = 0;
	}

	/* Dump the method heading */
	fputs(".method ", outstream);
	ILDumpFlags(outstream, ILMethod_Attrs(method),
				ILMethodDefinitionFlags, 0);
	if(pinvoke)
	{
		/* Dump PInvoke information for the method */
		DumpPInvoke(info, outstream, pinvoke, (ILMember *)method);
	}
	ILDumpMethodType(outstream, info->image,
					 ILMethod_Signature(method),
					 IL_DUMP_QUOTE_NAMES, 0,
					 ILMethod_Name(method), method);
	putc(' ', outstream);
	ILDumpFlags(outstream, ILMethod_ImplAttrs(method),
				ILMethodImplementationFlags, 0);
	if(info->outputIsJava && !ILMethod_IsJava(method))
	{
		/* Make sure that the assembler is informed
		   that this is a Java method */
		fputs("java ", outstream);
	}
	fputs("\n{\n", outstream);

	/* Output the attributes that are attached to the field */
	ILGenOutputAttributes(info, outstream, (ILProgramItem *)method);

	/* Output the attributes that are attached to the parameters */
	param = 0;
	while((param = ILMethodNextParam(method, param)) != 0)
	{
		constant = ILConstantGetFromOwner((ILProgramItem *)param);
		if(ILProgramItemNextAttribute((ILProgramItem *)param, 0) != 0 ||
		   constant != 0)
		{
			fprintf(outstream, ".param[%lu]",
					(unsigned long)(ILParameter_Num(param)));
			ILDumpConstant(outstream, (ILProgramItem *)param, 1);
			putc('\n', outstream);
			ILGenOutputAttributes(info, outstream, (ILProgramItem *)param);
		}
	}

	/* Output override information */
	over = ILOverrideFromMethod(method);
	if(over)
	{
		decl = ILOverride_Decl(over);
		fputs("\t.override\t", outstream);
		ILDumpClassName(outstream, info->image,
						ILMethod_Owner(decl),
						IL_DUMP_QUOTE_NAMES);
		fputs("::", outstream);
		ILDumpIdentifier(outstream, ILMethod_Name(decl), 0,
						 IL_DUMP_QUOTE_NAMES);
		putc('\n', outstream);
	}

	/* Set up the return type so that "return" statements
	   know what to cast the return value to upon exit */
	info->returnType = ILTypeGetReturn(ILMethod_Signature(method));
	returnMachineType = ILTypeToMachineType(info->returnType);

	/* The local variable frame is created differently in IL and JL */
	if(info->outputIsJava)
	{
		AllocJLVars(info, ILMethod_Signature(method), node->localVarSig);
	}
	else
	{
		DumpILLocals(info, outstream, node->localVarSig);
	}

	/* Dump the code within the body of the method */
	if(node->body)
	{
		if(info->outputIsJava)
		{
			JavaGenDiscard(node->body, info);
		}
		else
		{
			ILNode_GenDiscard(node->body, info);
		}
	}

	/* Don't bother with return logic or stack sizes if abstract or extern */
	if(!ILMethod_IsAbstract(method) && ILMethod_IsIL(method) && node->body)
	{
		if(!(info->outputIsJava))
		{
			/* Add an explicit return instruction if the body didn't */
			outputLabel = 0;
			if(!ILNodeEndsInFlowChange(node->body,info))
			{
				if(info->returnLabel != ILLabel_Undefined &&
				   info->returnType == ILType_Void)
				{
					/* Use this point in the code for return labels
					   to prevent outputting two "ret"'s in a row */
					ILGenLabel(info, &(info->returnLabel));
					outputLabel = 1;
				}
				ILGenCast(info, ILMachineType_Void, returnMachineType);
				ILGenSimple(info, IL_OP_RET);
				if(info->returnType != ILType_Void)
				{
					ILGenAdjust(info, -1);
				}
			}

			/* If we have a return label, we need to output some final
			   code to return the contents of a temporary local variable.
			   This is used when returning from inside a "try" block */
			if(!outputLabel && info->returnLabel != ILLabel_Undefined)
			{
				ILGenLabel(info, &(info->returnLabel));
				if(info->returnType != ILType_Void)
				{
					ILGenLoadLocal(info, info->returnVar);
					ILGenExtend(info, 1);
				}
				ILGenSimple(info, IL_OP_RET);
			}
		}
		else
		{
			/* Add an explicit return instruction if the body didn't */
			outputLabel = 0;
			if(!ILNodeEndsInFlowChange(node->body,info))
			{
				if(info->returnLabel != ILLabel_Undefined &&
				   info->returnType == ILType_Void)
				{
					/* Use this point in the code for return labels
					   to prevent outputting two "ret"'s in a row */
					JavaGenLabel(info, &(info->returnLabel));
					outputLabel = 1;
				}
				JavaGenCast(info, ILMachineType_Void, returnMachineType);
				JavaGenReturnInsn(info, returnMachineType);
				if(info->returnType != ILMachineType_Void)
				{
					JavaGenAdjust(info, -JavaGenTypeSize(returnMachineType));
				}
			}

			/* If we have a return label, we need to output some final
			   code to return the contents of a temporary local variable.
			   This is used when returning from inside a "try" block */
			if(!outputLabel && info->returnLabel != ILLabel_Undefined)
			{
				JavaGenLabel(info, &(info->returnLabel));
				if(info->returnType != ILType_Void)
				{
					JavaGenLoadLocal(info, info->returnVar, returnMachineType);
					JavaGenExtend(info, JavaGenTypeSize(returnMachineType));
				}
				JavaGenReturnInsn(info, returnMachineType);
			}

			/* Output the number of local variables to the method */
			fprintf(outstream, "\t.locals %u\n", JavaGenNumLocals(info));
		}

		/* Output the maximum stack height to the method */
		fprintf(outstream, "\t.maxstack %ld\n", info->maxStackHeight);
	}

	/* Dump the method terminator */
	fputs ("} // method ", outstream);
	ILDumpIdentifier(outstream, ILMethod_Name(method), 0, 0);
	putc('\n', outstream);

	/* Clean up values that were used to generate the method code */
	ILGenEndMethod(info);
}

#line 1060 "cg_decls.tc"


/*
 * Dump the definition of a "runtime" method.
 */
static void DumpRuntimeMethod(ILGenInfo *info, FILE *outstream,
							  ILMethod *method)
{
	/* Bail out if the parameters are incorrect */
	if(!outstream || !method)
	{
		return;
	}

	/* Dump the method heading */
	fputs(".method ", outstream);
	ILDumpFlags(outstream, ILMethod_Attrs(method),
				ILMethodDefinitionFlags, 0);
	ILDumpMethodType(outstream, info->image,
					 ILMethod_Signature(method),
					 IL_DUMP_QUOTE_NAMES, 0,
					 ILMethod_Name(method), method);
	putc(' ', outstream);
	ILDumpFlags(outstream, ILMethod_ImplAttrs(method),
				ILMethodImplementationFlags, 0);

	/* Dump the method body, which is empty */
	fputs("{}\n", outstream);
}

#line 599 "cg_decls.c"

struct ILNode_Declaration_vtable__ const ILNode_Declaration_vt__ = {
	&ILNode_Statement_vt__,
	ILNode_Declaration_kind,
	"ILNode_Declaration",
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

void ILNode_ClassDefn_ILNode_GenDiscard__(ILNode_ClassDefn *node, ILGenInfo * info)
#line 131 "cg_decls.tc"
{
	ILClass *classInfo;
	ILImplements *impl;
	ILClass *interface;
	int first;
	ILNode *prevClass;
	int isModule = (!strcmp(node->name, "<Module>"));
	ILClassLayout *layout;

	/* Get the class information structure */
	classInfo = node->classInfo;
	if(!classInfo || classInfo == ((ILClass *)1))
	{
		return;
	}
	layout = ILClassLayoutGetFromOwner(classInfo);

	/* Set the current class within the ILGenInfo object */
	prevClass = info->currentClass;
	info->currentClass = (ILNode *)node;

	/* Output the class heading */
	if(info->asmOutput && !isModule)
	{
		/* Output the namespace information */
		if(ILClass_Namespace(classInfo) && ILClass_NestedParent(classInfo) == 0)
		{
			fputs(".namespace ", info->asmOutput);
			ILDumpIdentifier(info->asmOutput, ILClass_Namespace(classInfo), 0,
							 IL_DUMP_QUOTE_NAMES);
			fputs("\n{\n", info->asmOutput);
		}

		/* Output the class flags and name */
		fputs(".class ", info->asmOutput);
		ILDumpFlags(info->asmOutput, (unsigned long)(ILClass_Attrs(classInfo)),
					ILTypeDefinitionFlags, 0);
		ILDumpIdentifier(info->asmOutput, ILClass_Name(classInfo), 0,
						 IL_DUMP_QUOTE_NAMES);

		/* Output the generic parameters, if any */
		if(ILGenericParGetNumParams(ILToProgramItem(classInfo)) > 0)
		{
			ILUInt32 number = 0;
			ILGenericPar *genPar;
			putc('<', info->asmOutput);
			while((genPar = ILGenericParGetFromOwner
					(ILToProgramItem(classInfo), number)) != 0)
			{
				if(number > 0)
				{
					fputs(", ", info->asmOutput);
				}
				/* TODO: generic type constraints */
				ILDumpIdentifier(info->asmOutput, ILGenericPar_Name(genPar),
								 0, IL_DUMP_QUOTE_NAMES);
				++number;
			}
			putc('>', info->asmOutput);
		}

		/* Output the name of the parent class */
		if(ILClass_ParentRef(classInfo) != 0)
		{
			fputs(" extends ", info->asmOutput);
			ILDumpClassName(info->asmOutput, info->image,
							ILClass_ParentRef(classInfo),
							IL_DUMP_QUOTE_NAMES);
		}

		/* Output the names of the implemented interfaces */
		impl = 0;
		first = 1;
		while((impl = ILClassNextImplements(classInfo, impl)) != 0)
		{
			interface = ILImplementsGetInterface(impl);
			if(first)
			{
				fputs(" implements ", info->asmOutput);
				first = 0;
			}
			else
			{
				fputs(", ", info->asmOutput);
			}
			ILDumpClassName(info->asmOutput, info->image, interface,
							IL_DUMP_QUOTE_NAMES);
		}

		/* Done with the header */
		fputs("\n{\n", info->asmOutput);

		/* Output the line number information for the class */
		if(info->debugFlag)
		{
			fprintf(info->asmOutput, ".line %ld \"%s\"\n",
					yygetlinenum(node), yygetfilename(node));
		}

		/* Output the attributes that are attached to the class */
		ILGenOutputAttributes
			(info, info->asmOutput, (ILProgramItem *)classInfo);

		/* Output the class layout information */
		if(layout)
		{
			if(ILClassLayout_ClassSize(layout) != 0)
			{
				fprintf(info->asmOutput, ".size %lu\n",
						(unsigned long)(ILClassLayout_ClassSize(layout)));
			}
			if(ILClassLayout_PackingSize(layout) != 0)
			{
				fprintf(info->asmOutput, ".pack %lu\n",
						(unsigned long)(ILClassLayout_PackingSize(layout)));
			}
		}
		else if(ClassIsEmpty(classInfo) && ILClassIsValueType(classInfo))
		{
			/* Make sure that "struct"'s are never zero-sized */
			fprintf(info->asmOutput, ".size 1\n");
		}
	}

	/* Output the class members */
	if(info->outputIsJava)
	{
		JavaGenDiscard(node->body, info);
	}
	else
	{
		ILNode_GenDiscard(node->body, info);
	}

	/* Output the static constructor for the class */
	if(node->staticCtorsMethod && info->asmOutput)
	{
		MethodGenDiscard(info, info->asmOutput,
						 (ILNode_MethodDeclaration *)(node->staticCtorsMethod),
						 ((ILNode_MethodDeclaration *)(node->staticCtorsMethod))
						 		->methodInfo);
	}

	/* Output the class footer */
	if(info->asmOutput && !isModule)
	{
		fprintf(info->asmOutput, "} // class %s\n", ILClass_Name(classInfo));
		if(ILClass_Namespace(classInfo) && ILClass_NestedParent(classInfo) == 0)
		{
			fprintf(info->asmOutput, "} // namespace %s\n",
					ILClass_Namespace(classInfo));
		}
	}

	/* Restore the previous class */
	info->currentClass = prevClass;
}
#line 777 "cg_decls.c"

void ILNode_ClassDefn_JavaGenDiscard__(ILNode_ClassDefn *node, ILGenInfo * info)
#line 25 "jv_decls.tc"
{
	/* We let ILNode_GenDiscard do the hard work because the class
	   definition shell for IL and JL are identical.  It will call
	   back into JavaGenDiscard when outputting the class body */
	ILNode_GenDiscard(node, info);
}
#line 787 "cg_decls.c"

struct ILNode_ClassDefn_vtable__ const ILNode_ClassDefn_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_ClassDefn_kind,
	"ILNode_ClassDefn",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ClassDefn_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ClassDefn_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_ScopeChange_ILNode_GenDiscard__(ILNode_ScopeChange *node, ILGenInfo * info)
#line 362 "cg_decls.tc"
{
	if(node->body)
	{
		ILScope *oldScope = info->currentScope;
		info->currentScope = node->scope;
		ILNode_GenDiscard(node->body, info);
		info->currentScope = oldScope;
	}
}
#line 817 "cg_decls.c"

void ILNode_ScopeChange_JavaGenDiscard__(ILNode_ScopeChange *node, ILGenInfo * info)
#line 44 "jv_decls.tc"
{
	if(node->body)
	{
		ILScope *oldScope = info->currentScope;
		info->currentScope = node->scope;
		JavaGenDiscard(node->body, info);
		info->currentScope = oldScope;
	}
}
#line 830 "cg_decls.c"

struct ILNode_ScopeChange_vtable__ const ILNode_ScopeChange_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_ScopeChange_kind,
	"ILNode_ScopeChange",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ScopeChange_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ScopeChange_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_FieldDeclaration_ILNode_GenDiscard__(ILNode_FieldDeclaration *node, ILGenInfo * info)
#line 456 "cg_decls.tc"
{
	ILNode_ListIter	iter;
	ILNode_FieldDeclarator *decl;
	ILField *field;

	if(node->fieldDeclarators && info->asmOutput)
	{
		ILNode_ListIter_Init(&iter, node->fieldDeclarators);
		while((decl = (ILNode_FieldDeclarator *)
							ILNode_ListIter_Next(&iter)) != 0)
		{
			field = decl->fieldInfo;
			if(field)
			{
				DumpField(info, field, decl->name);
			}
		}
	}
}
#line 870 "cg_decls.c"

void ILNode_FieldDeclaration_JavaGenDiscard__(ILNode_FieldDeclaration *node, ILGenInfo * info)
#line 58 "jv_decls.tc"
{
	/* We let ILNode_GenDiscard do the hard work because the field
	   definition syntax for IL and JL are identical */
	ILNode_GenDiscard(node, info);
}
#line 879 "cg_decls.c"

struct ILNode_FieldDeclaration_vtable__ const ILNode_FieldDeclaration_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_FieldDeclaration_kind,
	"ILNode_FieldDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FieldDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FieldDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_FieldDeclarator_ILNode_GenDiscard__(ILNode_FieldDeclarator *node, ILGenInfo * info)
#line 480 "cg_decls.tc"
{
	/* Nothing to do here: handled by ILNode_FieldDeclaration */
}
#line 903 "cg_decls.c"

void ILNode_FieldDeclarator_JavaGenDiscard__(ILNode_FieldDeclarator *node, ILGenInfo * info)
#line 68 "jv_decls.tc"
{
	/* Nothing to do here: handled by ILNode_FieldDeclaration */
}
#line 910 "cg_decls.c"

struct ILNode_FieldDeclarator_vtable__ const ILNode_FieldDeclarator_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_FieldDeclarator_kind,
	"ILNode_FieldDeclarator",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FieldDeclarator_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FieldDeclarator_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_EventDeclaration_ILNode_GenDiscard__(ILNode_EventDeclaration *node, ILGenInfo * info)
#line 488 "cg_decls.tc"
{
	ILNode_ListIter iter;
	ILNode *decl;

	if(yyisa(node->eventDeclarators, ILNode_EventDeclarator))
	{
		/* Create the singleton event */
		ILNode_GenDiscard(node->eventDeclarators, info);
	}
	else
	{
		/* Scan the list and create the events that we require */
		ILNode_ListIter_Init(&iter, node->eventDeclarators);
		while((decl = ILNode_ListIter_Next(&iter)) != 0)
		{
			ILNode_GenDiscard(decl, info);
		}
	}
}
#line 950 "cg_decls.c"

void ILNode_EventDeclaration_JavaGenDiscard__(ILNode_EventDeclaration *node, ILGenInfo * info)
#line 76 "jv_decls.tc"
{
	/* TODO */
}
#line 957 "cg_decls.c"

struct ILNode_EventDeclaration_vtable__ const ILNode_EventDeclaration_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_EventDeclaration_kind,
	"ILNode_EventDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EventDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EventDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_EventDeclarator_ILNode_GenDiscard__(ILNode_EventDeclarator *node, ILGenInfo * info)
#line 512 "cg_decls.tc"
{
	FILE *outstream = info->asmOutput;
	ILMethod *methodInfo;

	if(outstream && node->eventInfo)
	{
		/* Generate the code for the add method */
		if(node->addAccessor)
		{
			ILNode_GenDiscard(node->addAccessor, info);
		}

		/* Generate the code for the remove method */
		if(node->removeAccessor)
		{
			ILNode_GenDiscard(node->removeAccessor, info);
		}

		/* Output the hidden field that holds the event data */
		if(node->backLink->needFields)
		{
			fputs(".field private ", outstream);
			if(node->addAccessor)
			{
				methodInfo = ((ILNode_MethodDeclaration *)(node->addAccessor))
								->methodInfo;
				if(ILMethod_IsStatic(methodInfo))
				{
					fputs("static ", outstream);
				}
			}
			else if(node->removeAccessor)
			{
				methodInfo =
					((ILNode_MethodDeclaration *)(node->removeAccessor))
						->methodInfo;
				if(ILMethod_IsStatic(methodInfo))
				{
					fputs("static ", outstream);
				}
			}
			ILDumpType(outstream, info->image,
					   ILEvent_Type(node->eventInfo),
					   IL_DUMP_QUOTE_NAMES);
			putc(' ', outstream);
			ILDumpIdentifier(outstream, ILEvent_Name(node->eventInfo),
							 0, IL_DUMP_QUOTE_NAMES);
			putc('\n', outstream);
		}

		/* Output the event declaration */
		fputs(".event ", outstream);
		ILDumpFlags(outstream, ILEvent_Attrs(node->eventInfo),
					ILEventDefinitionFlags, 0);
		ILDumpClassName(outstream, info->image,
					    ILType_ToClass(ILEvent_Type(node->eventInfo)),
					    IL_DUMP_QUOTE_NAMES);
		putc(' ', outstream);
		ILDumpIdentifier(outstream, ILEvent_Name(node->eventInfo),
					     0, IL_DUMP_QUOTE_NAMES);
		fputs("\n{\n", outstream);
		if(info->debugFlag && info->asmOutput)
		{
			fprintf(info->asmOutput, ".line %ld \"%s\"\n",
					yygetlinenum(node), yygetfilename(node));
		}
		ILGenOutputAttributes(info, outstream,
						 	  (ILProgramItem *)(node->eventInfo));
		if(node->addAccessor)
		{
			methodInfo = ((ILNode_MethodDeclaration *)(node->addAccessor))
								->methodInfo;
			fputs("\t.addon ", outstream);
			ILDumpMethodType(outstream, info->image,
						     ILMethod_Signature(methodInfo),
						     IL_DUMP_QUOTE_NAMES, ILMethod_Owner(methodInfo),
							 ILMethod_Name(methodInfo), 0);
			putc('\n', outstream);
		}
		if(node->removeAccessor)
		{
			methodInfo = ((ILNode_MethodDeclaration *)(node->removeAccessor))
								->methodInfo;
			fputs("\t.removeon ", outstream);
			ILDumpMethodType(outstream, info->image,
						     ILMethod_Signature(methodInfo),
						     IL_DUMP_QUOTE_NAMES, ILMethod_Owner(methodInfo),
							 ILMethod_Name(methodInfo), 0);
			putc('\n', outstream);
		}
		fputs("} // event ", outstream);
		ILDumpIdentifier(outstream, ILEvent_Name(node->eventInfo), 0, 0);
		putc('\n', outstream);
	}
}
#line 1073 "cg_decls.c"

void ILNode_EventDeclarator_JavaGenDiscard__(ILNode_EventDeclarator *node, ILGenInfo * info)
#line 84 "jv_decls.tc"
{
	/* Nothing to do here: handled by ILNode_EventDeclaration */
}
#line 1080 "cg_decls.c"

struct ILNode_EventDeclarator_vtable__ const ILNode_EventDeclarator_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_EventDeclarator_kind,
	"ILNode_EventDeclarator",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EventDeclarator_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EventDeclarator_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_ProxyDeclaration_ILNode_GenDiscard__(ILNode_ProxyDeclaration *node, ILGenInfo * info)
#line 293 "cg_decls.tc"
{
	FILE *outstream = info->asmOutput;
	char *name;
	ILType *signature = ILMethod_Signature(node->interfaceMethod);
	unsigned long numParams;
	unsigned long param;

	/* Bail out if no assembly output stream */
	if(!outstream)
	{
		return;
	}
	
	/* Create a name for the proxy method */
	name = ILInternAppendedString
		(ILInternAppendedString
			(ILInternString
				((char *)ILClass_Name(ILMethod_Owner(node->interfaceMethod)),
				 -1),
			 ILInternString(".", 1)),
		 ILInternString((char *)ILMethod_Name(node->interfaceMethod), -1))
		 		.string;

	/* Dump the method heading */
	fputs(".method ", outstream);
	ILDumpFlags(outstream, IL_META_METHODDEF_PRIVATE |
						   IL_META_METHODDEF_FINAL |
						   IL_META_METHODDEF_VIRTUAL |
						   IL_META_METHODDEF_NEW_SLOT,
				ILMethodDefinitionFlags, 0);
	ILDumpMethodType(outstream, info->image, signature,
					 IL_DUMP_QUOTE_NAMES, 0, name,
					 node->interfaceMethod);
	fputs(" il managed\n{\n", outstream);

	/* Output the ".override" declaration */
	fputs("\t.override\t", outstream);
	ILDumpClassName(outstream, info->image,
					ILMethod_Owner(node->interfaceMethod),
					IL_DUMP_QUOTE_NAMES);
	fputs("::", outstream);
	ILDumpIdentifier(outstream, ILMethod_Name(node->interfaceMethod), 0,
					 IL_DUMP_QUOTE_NAMES);
	putc('\n', outstream);

	/* Push all of the arguments onto the stack, including "this" */
	numParams = ILTypeNumParams(signature);
	for(param = 0; param <= numParams; ++param)
	{
		ILGenLoadArg(info, (unsigned)param);
	}

	/* Call the proxy replacement method */
	ILGenCallMethod(info, node->proxyReplacement);

	/* Return from the proxy method */
	ILGenSimple(info, IL_OP_RET);

	/* Set the maximum stack height */
	fprintf(outstream, "\t.maxstack %ld\n", numParams + 1);

	/* Output the method footer */
	fputs("}\n", outstream);
}
#line 1165 "cg_decls.c"

void ILNode_ProxyDeclaration_JavaGenDiscard__(ILNode_ProxyDeclaration *node, ILGenInfo * info)
#line 36 "jv_decls.tc"
{
	/* TODO */
}
#line 1172 "cg_decls.c"

struct ILNode_ProxyDeclaration_vtable__ const ILNode_ProxyDeclaration_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_ProxyDeclaration_kind,
	"ILNode_ProxyDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ProxyDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_ProxyDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_MethodDeclaration_ILNode_GenDiscard__(ILNode_MethodDeclaration *node, ILGenInfo * info)
#line 976 "cg_decls.tc"
{
	if(info->asmOutput && node->methodInfo)
	{
		MethodGenDiscard(info, info->asmOutput, node, node->methodInfo);
	}
}
#line 1199 "cg_decls.c"

void ILNode_MethodDeclaration_JavaGenDiscard__(ILNode_MethodDeclaration *node, ILGenInfo * info)
#line 92 "jv_decls.tc"
{
	/* We let ILNode_GenDiscard do the hard work because the method
	   definition shell for IL and JL are identical.  It will call
	   back into JavaGenDiscard when outputting the method body */
	ILNode_GenDiscard(node, info);
}
#line 1209 "cg_decls.c"

struct ILNode_MethodDeclaration_vtable__ const ILNode_MethodDeclaration_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_MethodDeclaration_kind,
	"ILNode_MethodDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_MethodDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_MethodDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_PropertyDeclaration_ILNode_GenDiscard__(ILNode_PropertyDeclaration *node, ILGenInfo * info)
#line 987 "cg_decls.tc"
{
	FILE *outstream = info->asmOutput;
	ILMethod *methodInfo;

	if(outstream && node->propertyInfo)
	{
		/* Generate the code for the get method */
		if(node->getAccessor)
		{
			ILNode_GenDiscard(node->getAccessor, info);
		}

		/* Generate the code for the set method */
		if(node->setAccessor)
		{
			ILNode_GenDiscard(node->setAccessor, info);
		}

		/* Output the property declaration */
		fputs(".property ", outstream);
		ILDumpFlags(outstream, ILProperty_Attrs(node->propertyInfo),
					ILPropertyDefinitionFlags, 0);
		ILDumpMethodType(outstream, info->image,
					     ILProperty_Signature(node->propertyInfo),
					     IL_DUMP_QUOTE_NAMES, 0,
						 ILProperty_Name(node->propertyInfo), 0);
		fputs("\n{\n", outstream);
		if(info->debugFlag && info->asmOutput)
		{
			fprintf(info->asmOutput, ".line %ld \"%s\"\n",
					yygetlinenum(node->name), yygetfilename(node->name));
		}
		ILGenOutputAttributes(info, outstream,
						      (ILProgramItem *)(node->propertyInfo));
		if(node->getAccessor)
		{
			methodInfo = ((ILNode_MethodDeclaration *)(node->getAccessor))
								->methodInfo;
			fputs("\t.get ", outstream);
			ILDumpMethodType(outstream, info->image,
						     ILMethod_Signature(methodInfo),
						     IL_DUMP_QUOTE_NAMES, ILMethod_Owner(methodInfo),
							 ILMethod_Name(methodInfo), 0);
			putc('\n', outstream);
		}
		if(node->setAccessor)
		{
			methodInfo = ((ILNode_MethodDeclaration *)(node->setAccessor))
								->methodInfo;
			fputs("\t.set ", outstream);
			ILDumpMethodType(outstream, info->image,
						     ILMethod_Signature(methodInfo),
						     IL_DUMP_QUOTE_NAMES, ILMethod_Owner(methodInfo),
							 ILMethod_Name(methodInfo), 0);
			putc('\n', outstream);
		}
		fputs("} // property ", outstream);
		ILDumpIdentifier(outstream, ILProperty_Name(node->propertyInfo), 0, 0);
		putc('\n', outstream);
	}
}
#line 1291 "cg_decls.c"

void ILNode_PropertyDeclaration_JavaGenDiscard__(ILNode_PropertyDeclaration *node, ILGenInfo * info)
#line 100 "jv_decls.tc"
{
	/* We let ILNode_GenDiscard do the hard work because the property
	   definition shell for IL and JL are identical.  It will call
	   back into JavaGenDiscard when outputting the accessor bodies */
	ILNode_GenDiscard(node, info);
}
#line 1301 "cg_decls.c"

struct ILNode_PropertyDeclaration_vtable__ const ILNode_PropertyDeclaration_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_PropertyDeclaration_kind,
	"ILNode_PropertyDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PropertyDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_PropertyDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_EnumMemberDeclaration_ILNode_GenDiscard__(ILNode_EnumMemberDeclaration *node, ILGenInfo * info)
#line 1050 "cg_decls.tc"
{
	ILField *field;

	field = node->fieldInfo;
	if(info->asmOutput && field)
	{
		DumpField(info, field, node->name);
	}
}
#line 1331 "cg_decls.c"

void ILNode_EnumMemberDeclaration_JavaGenDiscard__(ILNode_EnumMemberDeclaration *node, ILGenInfo * info)
#line 108 "jv_decls.tc"
{
	/* We let ILNode_GenDiscard do the hard work because the enum
	   definition syntax for IL and JL are identical */
	ILNode_GenDiscard(node, info);
}
#line 1340 "cg_decls.c"

struct ILNode_EnumMemberDeclaration_vtable__ const ILNode_EnumMemberDeclaration_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_EnumMemberDeclaration_kind,
	"ILNode_EnumMemberDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EnumMemberDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_EnumMemberDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_DelegateMemberDeclaration_ILNode_GenDiscard__(ILNode_DelegateMemberDeclaration *node, ILGenInfo * info)
#line 1093 "cg_decls.tc"
{
	DumpRuntimeMethod(info, info->asmOutput, node->ctorMethod);
	DumpRuntimeMethod(info, info->asmOutput, node->invokeMethod);
	DumpRuntimeMethod(info, info->asmOutput, node->beginInvokeMethod);
	DumpRuntimeMethod(info, info->asmOutput, node->endInvokeMethod);
}
#line 1367 "cg_decls.c"

void ILNode_DelegateMemberDeclaration_JavaGenDiscard__(ILNode_DelegateMemberDeclaration *node, ILGenInfo * info)
#line 115 "jv_decls.tc"
{
	/* TODO */
}
#line 1374 "cg_decls.c"

struct ILNode_DelegateMemberDeclaration_vtable__ const ILNode_DelegateMemberDeclaration_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_DelegateMemberDeclaration_kind,
	"ILNode_DelegateMemberDeclaration",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateMemberDeclaration_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_DelegateMemberDeclaration_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_FormalParameter_ILNode_GenDiscard__(ILNode_FormalParameter *node, ILGenInfo * info)
#line 1101 "cg_decls.tc"
{
#if 0
	if (info->asmOutput)
	{
		/*FIXME attributes, parameter modifier */
		DumpTypeName(info->asmOutput, node->type);
		ILNode_GenDiscard(node->type, info);
		fputc(' ', info->asmOutput);
		fputs (ILQualIdentName (node->name, 1), info->asmOutput);
	}
#endif
}
#line 1407 "cg_decls.c"

void ILNode_FormalParameter_JavaGenDiscard__(ILNode_FormalParameter *node, ILGenInfo * info)
#line 120 "jv_decls.tc"
{
	/* TODO */
}
#line 1414 "cg_decls.c"

struct ILNode_FormalParameter_vtable__ const ILNode_FormalParameter_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_FormalParameter_kind,
	"ILNode_FormalParameter",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FormalParameter_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_FormalParameter_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

ILNode *ILNode_ClassDefn_create(ILNode * attributes, ILUInt32 modifiers, char * name, char * namespace, ILNode * namespaceNode, ILNode * typeFormals, ILNode * baseClass, ILNode * body, ILNode * staticCtors)
{
	ILNode_ClassDefn *node__ = (ILNode_ClassDefn *)yynodealloc(sizeof(struct ILNode_ClassDefn__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ClassDefn_vt__;
	node__->kind__ = ILNode_ClassDefn_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->attributes = attributes;
	node__->modifiers = modifiers;
	node__->name = name;
	node__->namespace = namespace;
	node__->namespaceNode = namespaceNode;
	node__->typeFormals = typeFormals;
	node__->baseClass = baseClass;
	node__->body = body;
	node__->staticCtors = staticCtors;
	node__->classInfo = 0;
	node__->nextEnum = 0;
	node__->staticCtorsMethod = 0;
	node__->initCtorsMethod = 0;
	node__->nestedParent = 0;
	node__->nestedClasses = 0;
	node__->visited = ILVisitMode_NotVisited;
	node__->defaultMemberName = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ScopeChange_create(ILScope * scope, ILNode * body)
{
	ILNode_ScopeChange *node__ = (ILNode_ScopeChange *)yynodealloc(sizeof(struct ILNode_ScopeChange__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ScopeChange_vt__;
	node__->kind__ = ILNode_ScopeChange_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->scope = scope;
	node__->body = body;
	return (ILNode *)node__;
}

ILNode *ILNode_FieldDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * fieldDeclarators)
{
	ILNode_FieldDeclaration *node__ = (ILNode_FieldDeclaration *)yynodealloc(sizeof(struct ILNode_FieldDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_FieldDeclaration_vt__;
	node__->kind__ = ILNode_FieldDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->attributes = attributes;
	node__->modifiers = modifiers;
	node__->type = type;
	node__->fieldDeclarators = fieldDeclarators;
	return (ILNode *)node__;
}

ILNode *ILNode_FieldDeclarator_create(ILNode * name, ILNode * initializer)
{
	ILNode_FieldDeclarator *node__ = (ILNode_FieldDeclarator *)yynodealloc(sizeof(struct ILNode_FieldDeclarator__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_FieldDeclarator_vt__;
	node__->kind__ = ILNode_FieldDeclarator_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = name;
	node__->initializer = initializer;
	node__->fieldInfo = 0;
	node__->visited = ILVisitMode_NotVisited;
	node__->owner = 0;
	node__->staticCtor = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_EventDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * eventDeclarators)
{
	ILNode_EventDeclaration *node__ = (ILNode_EventDeclaration *)yynodealloc(sizeof(struct ILNode_EventDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_EventDeclaration_vt__;
	node__->kind__ = ILNode_EventDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->attributes = attributes;
	node__->modifiers = modifiers;
	node__->type = type;
	node__->eventDeclarators = eventDeclarators;
	node__->needFields = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_EventDeclarator_create(ILNode * fieldDeclarator, ILNode * addAccessor, ILNode * removeAccessor)
{
	ILNode_EventDeclarator *node__ = (ILNode_EventDeclarator *)yynodealloc(sizeof(struct ILNode_EventDeclarator__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_EventDeclarator_vt__;
	node__->kind__ = ILNode_EventDeclarator_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->fieldDeclarator = fieldDeclarator;
	node__->addAccessor = addAccessor;
	node__->removeAccessor = removeAccessor;
	node__->eventInfo = 0;
	node__->backingField = 0;
	node__->visited = ILVisitMode_NotVisited;
	node__->backLink = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_ProxyDeclaration_create(ILMethod * interfaceMethod, ILMethod * proxyReplacement)
{
	ILNode_ProxyDeclaration *node__ = (ILNode_ProxyDeclaration *)yynodealloc(sizeof(struct ILNode_ProxyDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_ProxyDeclaration_vt__;
	node__->kind__ = ILNode_ProxyDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->interfaceMethod = interfaceMethod;
	node__->proxyReplacement = proxyReplacement;
	return (ILNode *)node__;
}

ILNode *ILNode_MethodDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * name, ILNode * params, ILNode * body)
{
	ILNode_MethodDeclaration *node__ = (ILNode_MethodDeclaration *)yynodealloc(sizeof(struct ILNode_MethodDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_MethodDeclaration_vt__;
	node__->kind__ = ILNode_MethodDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->attributes = attributes;
	node__->modifiers = modifiers;
	node__->type = type;
	node__->name = name;
	node__->params = params;
	node__->body = body;
	node__->methodInfo = 0;
	node__->localVarSig = 0;
	node__->visited = ILVisitMode_NotVisited;
	node__->suppressCodeGen = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_PropertyDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * name, ILNode * params, ILNode * getAccessor, ILNode * setAccessor, ILUInt32 getsetFlags)
{
	ILNode_PropertyDeclaration *node__ = (ILNode_PropertyDeclaration *)yynodealloc(sizeof(struct ILNode_PropertyDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_PropertyDeclaration_vt__;
	node__->kind__ = ILNode_PropertyDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->attributes = attributes;
	node__->modifiers = modifiers;
	node__->type = type;
	node__->name = name;
	node__->params = params;
	node__->getAccessor = getAccessor;
	node__->setAccessor = setAccessor;
	node__->getsetFlags = getsetFlags;
	node__->propertyInfo = 0;
	node__->visited = ILVisitMode_NotVisited;
	return (ILNode *)node__;
}

ILNode *ILNode_EnumMemberDeclaration_create(ILNode * attributes, ILNode * name, ILNode * value)
{
	ILNode_EnumMemberDeclaration *node__ = (ILNode_EnumMemberDeclaration *)yynodealloc(sizeof(struct ILNode_EnumMemberDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_EnumMemberDeclaration_vt__;
	node__->kind__ = ILNode_EnumMemberDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->attributes = attributes;
	node__->name = name;
	node__->value = value;
	node__->fieldInfo = 0;
	node__->visited = ILVisitMode_NotVisited;
	return (ILNode *)node__;
}

ILNode *ILNode_DelegateMemberDeclaration_create(ILNode * returnType, ILNode * params)
{
	ILNode_DelegateMemberDeclaration *node__ = (ILNode_DelegateMemberDeclaration *)yynodealloc(sizeof(struct ILNode_DelegateMemberDeclaration__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_DelegateMemberDeclaration_vt__;
	node__->kind__ = ILNode_DelegateMemberDeclaration_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->returnType = returnType;
	node__->params = params;
	node__->ctorMethod = 0;
	node__->invokeMethod = 0;
	node__->beginInvokeMethod = 0;
	node__->endInvokeMethod = 0;
	return (ILNode *)node__;
}

ILNode *ILNode_FormalParameter_create(ILNode * attributes, ILParameterModifier pmod, ILNode * type, ILNode * name)
{
	ILNode_FormalParameter *node__ = (ILNode_FormalParameter *)yynodealloc(sizeof(struct ILNode_FormalParameter__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_FormalParameter_vt__;
	node__->kind__ = ILNode_FormalParameter_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->attributes = attributes;
	node__->pmod = pmod;
	node__->type = type;
	node__->name = name;
	return (ILNode *)node__;
}

