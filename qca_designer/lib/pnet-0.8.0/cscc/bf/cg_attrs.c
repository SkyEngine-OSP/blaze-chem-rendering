/* cg_attrs.c.  Generated automatically by treecc */
#line 3 "cg_attrs.tc"

/*
 * cg_attrs.tc - Attribute nodes.
 *
 * Copyright (C) 2002  Southern Storm Software, Pty Ltd.
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
#line 26 "cg_attrs.c"

void ILNode_AttributeTree_ILNode_GenDiscard__(ILNode_AttributeTree *node, ILGenInfo * info)
#line 28 "cg_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 33 "cg_attrs.c"

void ILNode_AttributeTree_JavaGenDiscard__(ILNode_AttributeTree *node, ILGenInfo * info)
#line 22 "jv_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 40 "cg_attrs.c"

struct ILNode_AttributeTree_vtable__ const ILNode_AttributeTree_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_AttributeTree_kind,
	"ILNode_AttributeTree",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AttributeTree_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AttributeTree_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_AttributeSection_ILNode_GenDiscard__(ILNode_AttributeSection *node, ILGenInfo * info)
#line 33 "cg_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 64 "cg_attrs.c"

void ILNode_AttributeSection_JavaGenDiscard__(ILNode_AttributeSection *node, ILGenInfo * info)
#line 27 "jv_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 71 "cg_attrs.c"

struct ILNode_AttributeSection_vtable__ const ILNode_AttributeSection_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_AttributeSection_kind,
	"ILNode_AttributeSection",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AttributeSection_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AttributeSection_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_Attribute_ILNode_GenDiscard__(ILNode_Attribute *node, ILGenInfo * info)
#line 38 "cg_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 95 "cg_attrs.c"

void ILNode_Attribute_JavaGenDiscard__(ILNode_Attribute *node, ILGenInfo * info)
#line 32 "jv_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 102 "cg_attrs.c"

struct ILNode_Attribute_vtable__ const ILNode_Attribute_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_Attribute_kind,
	"ILNode_Attribute",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Attribute_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_Attribute_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_AttrArgs_ILNode_GenDiscard__(ILNode_AttrArgs *node, ILGenInfo * info)
#line 43 "cg_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 126 "cg_attrs.c"

void ILNode_AttrArgs_JavaGenDiscard__(ILNode_AttrArgs *node, ILGenInfo * info)
#line 37 "jv_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 133 "cg_attrs.c"

struct ILNode_AttrArgs_vtable__ const ILNode_AttrArgs_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_AttrArgs_kind,
	"ILNode_AttrArgs",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AttrArgs_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_AttrArgs_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

void ILNode_NamedArg_ILNode_GenDiscard__(ILNode_NamedArg *node, ILGenInfo * info)
#line 48 "cg_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 157 "cg_attrs.c"

void ILNode_NamedArg_JavaGenDiscard__(ILNode_NamedArg *node, ILGenInfo * info)
#line 42 "jv_attrs.tc"
{
	/* Nothing to do here: attributes are handled elsewhere */
}
#line 164 "cg_attrs.c"

struct ILNode_NamedArg_vtable__ const ILNode_NamedArg_vt__ = {
	&ILNode_Declaration_vt__,
	ILNode_NamedArg_kind,
	"ILNode_NamedArg",
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GetType__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NamedArg_ILNode_GenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_ILNode_GenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_ILNode_GenElse__,
	(int (*)(ILNode *this__, ILGenInfo * info, ILEvalValue * value))ILNode_Statement_ILNode_EvalConst__,
	(int (*)(ILNode *this__, ILGenInfo * info))ILNode_ILNode_EndsInReturnImpl__,
	(void (*)(ILNode *this__, ILGenInfo * info))ILNode_NamedArg_JavaGenDiscard__,
	(ILMachineType (*)(ILNode *this__, ILGenInfo * info))ILNode_Statement_JavaGenValue__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenThen__,
	(void (*)(ILNode *this__, ILGenInfo * info, ILLabel * label))ILNode_Statement_JavaGenElse__,
};

ILNode *ILNode_AttributeTree_create(ILNode * sections)
{
	ILNode_AttributeTree *node__ = (ILNode_AttributeTree *)yynodealloc(sizeof(struct ILNode_AttributeTree__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AttributeTree_vt__;
	node__->kind__ = ILNode_AttributeTree_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->sections = sections;
	node__->mode = ILAttrMode_NotVisited;
	return (ILNode *)node__;
}

ILNode *ILNode_AttributeSection_create(ILAttrTargetType type, ILNode * target, ILNode * attrs)
{
	ILNode_AttributeSection *node__ = (ILNode_AttributeSection *)yynodealloc(sizeof(struct ILNode_AttributeSection__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AttributeSection_vt__;
	node__->kind__ = ILNode_AttributeSection_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->type = type;
	node__->target = target;
	node__->attrs = attrs;
	return (ILNode *)node__;
}

ILNode *ILNode_Attribute_create(ILNode * name, ILNode * args)
{
	ILNode_Attribute *node__ = (ILNode_Attribute *)yynodealloc(sizeof(struct ILNode_Attribute__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_Attribute_vt__;
	node__->kind__ = ILNode_Attribute_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = name;
	node__->args = args;
	return (ILNode *)node__;
}

ILNode *ILNode_AttrArgs_create(ILNode * positionalArgs, ILNode * namedArgs)
{
	ILNode_AttrArgs *node__ = (ILNode_AttrArgs *)yynodealloc(sizeof(struct ILNode_AttrArgs__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_AttrArgs_vt__;
	node__->kind__ = ILNode_AttrArgs_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->positionalArgs = positionalArgs;
	node__->namedArgs = namedArgs;
	return (ILNode *)node__;
}

ILNode *ILNode_NamedArg_create(ILNode * name, ILNode * value)
{
	ILNode_NamedArg *node__ = (ILNode_NamedArg *)yynodealloc(sizeof(struct ILNode_NamedArg__));
	if(node__ == 0) return 0;
	node__->vtable__ = &ILNode_NamedArg_vt__;
	node__->kind__ = ILNode_NamedArg_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->varUsage = 0;
	node__->name = name;
	node__->value = value;
	return (ILNode *)node__;
}

void ILNodeStackElse(ILGenInfo * info, ILLabel * label, ILMachineType type)
{
	switch(type)
	{
		case ILMachineType_Void:
		{
#line 1155 "cg_nodes.tc"
			{
				/* Nothing to do here */
			}
#line 264 "cg_attrs.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 275 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 286 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 297 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 308 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 319 "cg_attrs.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 330 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 341 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 352 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1179 "cg_nodes.tc"
			{
			    /* Note: we can probably do this with "brtrue", but the
			       documentation is a little vague.  It provides information
			       for types "I" and "O", but not "I8" or "F".  Therefore,
			       we will be paranoid and do it the long way */
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenSimple(info, IL_OP_CONV_I8);
			    ILGenJump(info, IL_OP_BEQ, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 370 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1179 "cg_nodes.tc"
			{
			    /* Note: we can probably do this with "brtrue", but the
			       documentation is a little vague.  It provides information
			       for types "I" and "O", but not "I8" or "F".  Therefore,
			       we will be paranoid and do it the long way */
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenSimple(info, IL_OP_CONV_I8);
			    ILGenJump(info, IL_OP_BEQ, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 388 "cg_attrs.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 399 "cg_attrs.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 410 "cg_attrs.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1193 "cg_nodes.tc"
			{
				/* See comments above */
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BEQ, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 424 "cg_attrs.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1193 "cg_nodes.tc"
			{
				/* See comments above */
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BEQ, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 438 "cg_attrs.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1193 "cg_nodes.tc"
			{
				/* See comments above */
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BEQ, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 452 "cg_attrs.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1201 "cg_nodes.tc"
			{
			    ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
											"[.library]System.Decimal::op_Implicit(int32)");
				ILGenCallByName(info, "bool [.library]System.Decimal::op_Equality"
								"(valuetype [.library]System.Decimal, "
								"valuetype [.library]System.Decimal)");
			    ILGenJump(info, IL_OP_BEQ, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 470 "cg_attrs.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1213 "cg_nodes.tc"
			{
				ILGenCallByName(info, "bool [.library]System.Boolean::FromString"
											"(class [.library]System.String)");
			    ILGenJump(info, IL_OP_BEQ, label);
				ILGenAdjust(info, -1);
			}
#line 483 "cg_attrs.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 494 "cg_attrs.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 505 "cg_attrs.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 516 "cg_attrs.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 527 "cg_attrs.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1173 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRFALSE, label);
				ILGenAdjust(info, -1);
			}
#line 538 "cg_attrs.c"
		}
		break;

		default: break;
	}
}

void ILNodeStackThen(ILGenInfo * info, ILLabel * label, ILMachineType type)
{
	switch(type)
	{
		case ILMachineType_Void:
		{
#line 1084 "cg_nodes.tc"
			{
				/* Nothing to do here */
			}
#line 556 "cg_attrs.c"
		}
		break;

		case ILMachineType_Boolean:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 567 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int8:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 578 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt8:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 589 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int16:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 600 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt16:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 611 "cg_attrs.c"
		}
		break;

		case ILMachineType_Char:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 622 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int32:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 633 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt32:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 644 "cg_attrs.c"
		}
		break;

		case ILMachineType_Int64:
		{
#line 1108 "cg_nodes.tc"
			{
			    /* Note: we can probably do this with "brtrue", but the
			       documentation is a little vague.  It provides information
			       for types "I" and "O", but not "I8" or "F".  Therefore,
			       we will be paranoid and do it the long way */
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenSimple(info, IL_OP_CONV_I8);
			    ILGenJump(info, IL_OP_BNE_UN, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 662 "cg_attrs.c"
		}
		break;

		case ILMachineType_UInt64:
		{
#line 1108 "cg_nodes.tc"
			{
			    /* Note: we can probably do this with "brtrue", but the
			       documentation is a little vague.  It provides information
			       for types "I" and "O", but not "I8" or "F".  Therefore,
			       we will be paranoid and do it the long way */
			    ILGenSimple(info, IL_OP_LDC_I4_0);
			    ILGenSimple(info, IL_OP_CONV_I8);
			    ILGenJump(info, IL_OP_BNE_UN, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 680 "cg_attrs.c"
		}
		break;

		case ILMachineType_NativeInt:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 691 "cg_attrs.c"
		}
		break;

		case ILMachineType_NativeUInt:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 702 "cg_attrs.c"
		}
		break;

		case ILMachineType_Float32:
		{
#line 1122 "cg_nodes.tc"
			{
				/* See comments above */
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BNE_UN, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 716 "cg_attrs.c"
		}
		break;

		case ILMachineType_Float64:
		{
#line 1122 "cg_nodes.tc"
			{
				/* See comments above */
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BNE_UN, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 730 "cg_attrs.c"
		}
		break;

		case ILMachineType_NativeFloat:
		{
#line 1122 "cg_nodes.tc"
			{
				/* See comments above */
			    ILGenLoadFloat32(info, (ILFloat)0.0);
			    ILGenJump(info, IL_OP_BNE_UN, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 744 "cg_attrs.c"
		}
		break;

		case ILMachineType_Decimal:
		{
#line 1130 "cg_nodes.tc"
			{
			    ILGenSimple(info, IL_OP_LDC_I4_0);
				ILGenCallByName(info, "valuetype [.library]System.Decimal "
											"[.library]System.Decimal::op_Implicit(int32)");
				ILGenCallByName(info, "bool [.library]System.Decimal::op_Equality"
								"(valuetype [.library]System.Decimal, "
								"valuetype [.library]System.Decimal)");
			    ILGenJump(info, IL_OP_BNE_UN, label);
				ILGenExtend(info, 1);
				ILGenAdjust(info, -1);
			}
#line 762 "cg_attrs.c"
		}
		break;

		case ILMachineType_String:
		{
#line 1142 "cg_nodes.tc"
			{
				ILGenCallByName(info, "bool [.library]System.Boolean::FromString"
											"(class [.library]System.String)");
			    ILGenJump(info, IL_OP_BNE_UN, label);
				ILGenAdjust(info, -1);
			}
#line 775 "cg_attrs.c"
		}
		break;

		case ILMachineType_ObjectRef:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 786 "cg_attrs.c"
		}
		break;

		case ILMachineType_UnmanagedPtr:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 797 "cg_attrs.c"
		}
		break;

		case ILMachineType_ManagedPtr:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 808 "cg_attrs.c"
		}
		break;

		case ILMachineType_TransientPtr:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 819 "cg_attrs.c"
		}
		break;

		case ILMachineType_ManagedValue:
		{
#line 1102 "cg_nodes.tc"
			{
				ILGenJump(info, IL_OP_BRTRUE, label);
				ILGenAdjust(info, -1);
			}
#line 830 "cg_attrs.c"
		}
		break;

		default: break;
	}
}

