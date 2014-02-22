/* cg_nodes.h.  Generated automatically by treecc */
#ifndef __yy_cg_nodes_h
#define __yy_cg_nodes_h
#line 4 "cg_nodes.tc"

/*
 * cg_nodes.tc - Declare common nodes and operations.
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
#line 26 "cg_nodes.tc"


#include <codegen/cg_defs.h>
#include <codegen/cg_varusage.h>

typedef struct _tagILEvalValue ILEvalValue;

#line 43 "cg_cast.tc"


#define	ILGenConstToBoolean(info,value)	\
			(ILGenCastConst((info), (value), (value)->valueType, \
							ILMachineType_Boolean))

#line 41 "cg_nodes.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ILNode_kind 1
#define ILNode_Dummy_kind 41
#define ILNode_Expression_kind 42
#define ILNode_Statement_kind 54
#define ILNode_Identifier_kind 181
#define ILNode_QualIdent_kind 182
#define ILNode_Constant_kind 43
#define ILNode_LValue_kind 44
#define ILNode_UnaryExpression_kind 46
#define ILNode_BinaryExpression_kind 51
#define ILNode_TernaryExpression_kind 53
#define ILNode_AssignExpression_kind 106
#define ILNode_VarArgList_kind 157
#define ILNode_Argument_kind 159
#define ILNode_ArgArray_kind 160
#define ILNode_BoxingExpression_kind 161
#define ILNode_Error_kind 164
#define ILNode_NewExpression_kind 173
#define ILNode_ObjectCreationExpression_kind 174
#define ILNode_DelegateCreationExpression_kind 175
#define ILNode_DefaultConstructor_kind 176
#define ILNode_BaseInit_kind 178
#define ILNode_ThisInit_kind 179
#define ILNode_NonStaticInit_kind 180
#define ILNode_EmptyExpr_kind 206
#define ILNode_Null_kind 56
#define ILNode_NullPtr_kind 57
#define ILNode_True_kind 58
#define ILNode_False_kind 59
#define ILNode_Integer_kind 60
#define ILNode_Real_kind 72
#define ILNode_Decimal_kind 76
#define ILNode_String_kind 77
#define ILNode_Int8_kind 61
#define ILNode_UInt8_kind 62
#define ILNode_Int16_kind 63
#define ILNode_UInt16_kind 64
#define ILNode_Char_kind 65
#define ILNode_Int32_kind 66
#define ILNode_UInt32_kind 67
#define ILNode_Int64_kind 68
#define ILNode_UInt64_kind 69
#define ILNode_Int_kind 70
#define ILNode_UInt_kind 71
#define ILNode_Float32_kind 73
#define ILNode_Float64_kind 74
#define ILNode_Float_kind 75
#define ILNode_LValueNoRef_kind 45
#define ILNode_LValueUnaryExpr_kind 48
#define ILNode_LValueBinaryExpr_kind 50
#define ILNode_This_kind 155
#define ILNode_LocalVar_kind 183
#define ILNode_ArgumentVar_kind 184
#define ILNode_RefArgumentVar_kind 185
#define ILNode_StaticField_kind 190
#define ILNode_MemberField_kind 191
#define ILNode_ArrayAccess_kind 194
#define ILNode_Deref_kind 151
#define ILNode_StaticProperty_kind 192
#define ILNode_MemberProperty_kind 193
#define ILNode_IndexerAccess_kind 195
#define ILNode_LValueNoRefUnaryExpr_kind 49
#define ILNode_BaseAccess_kind 187
#define ILNode_BaseElement_kind 188
#define ILNode_AsIs_kind 141
#define ILNode_Overflow_kind 143
#define ILNode_NoOverflow_kind 144
#define ILNode_Pedantic_kind 145
#define ILNode_NoPedantic_kind 146
#define ILNode_MarkType_kind 142
#define ILNode_MemberAccess_kind 186
#define ILNode_DerefField_kind 189
#define ILNode_DummyUnaryExpr_kind 47
#define ILNode_LogicalNot_kind 78
#define ILNode_Neg_kind 92
#define ILNode_UnaryPlus_kind 93
#define ILNode_Not_kind 97
#define ILNode_UserUnaryOp_kind 101
#define ILNode_PreInc_kind 119
#define ILNode_PreDec_kind 120
#define ILNode_PostInc_kind 121
#define ILNode_PostDec_kind 122
#define ILNode_UserIncOrDec_kind 123
#define ILNode_IncOrDecPtr_kind 128
#define ILNode_CastSimple_kind 147
#define ILNode_CastType_kind 148
#define ILNode_UserConversion_kind 149
#define ILNode_AddressOf_kind 152
#define ILNode_ToBool_kind 153
#define ILNode_ToConst_kind 154
#define ILNode_VarArgExpand_kind 158
#define ILNode_IsNull_kind 167
#define ILNode_IsNonNull_kind 168
#define ILNode_MakeRefAny_kind 169
#define ILNode_RefType_kind 170
#define ILNode_ArrayLength_kind 172
#define ILNode_ArrayInit_kind 196
#define ILNode_UserPreInc_kind 124
#define ILNode_UserPreDec_kind 125
#define ILNode_UserPostInc_kind 126
#define ILNode_UserPostDec_kind 127
#define ILNode_PreIncPtr_kind 129
#define ILNode_PreDecPtr_kind 130
#define ILNode_PostIncPtr_kind 131
#define ILNode_PostDecPtr_kind 132
#define ILNode_DummyBinaryExpr_kind 52
#define ILNode_LogicalAnd_kind 79
#define ILNode_LogicalOr_kind 80
#define ILNode_UserLogical_kind 81
#define ILNode_BinaryArith_kind 84
#define ILNode_BinaryBitwise_kind 85
#define ILNode_BinaryShift_kind 86
#define ILNode_UserBinaryOp_kind 102
#define ILNode_Concat_kind 103
#define ILNode_DelegateAdd_kind 104
#define ILNode_DelegateSub_kind 105
#define ILNode_Assign_kind 107
#define ILNode_Relational_kind 133
#define ILNode_Comma_kind 140
#define ILNode_ArgList_kind 156
#define ILNode_RefValue_kind 171
#define ILNode_InvocationExpression_kind 177
#define ILNode_UserLogicalAnd_kind 82
#define ILNode_UserLogicalOr_kind 83
#define ILNode_Add_kind 87
#define ILNode_Sub_kind 88
#define ILNode_Mul_kind 89
#define ILNode_Div_kind 90
#define ILNode_Rem_kind 91
#define ILNode_And_kind 94
#define ILNode_Or_kind 95
#define ILNode_Xor_kind 96
#define ILNode_Shl_kind 98
#define ILNode_Shr_kind 99
#define ILNode_UShr_kind 100
#define ILNode_Eq_kind 134
#define ILNode_Ne_kind 135
#define ILNode_Lt_kind 136
#define ILNode_Le_kind 137
#define ILNode_Gt_kind 138
#define ILNode_Ge_kind 139
#define ILNode_Conditional_kind 150
#define ILNode_AssignAdd_kind 108
#define ILNode_AssignSub_kind 109
#define ILNode_AssignMul_kind 110
#define ILNode_AssignDiv_kind 111
#define ILNode_AssignRem_kind 112
#define ILNode_AssignAnd_kind 113
#define ILNode_AssignOr_kind 114
#define ILNode_AssignXor_kind 115
#define ILNode_AssignShl_kind 116
#define ILNode_AssignShr_kind 117
#define ILNode_AssignUShr_kind 118
#define ILNode_As_kind 162
#define ILNode_Is_kind 163
#define ILNode_Box_kind 165
#define ILNode_Unbox_kind 166
#define ILNode_List_kind 55
#define ILNode_Empty_kind 197
#define ILNode_If_kind 199
#define ILNode_LabelledStatement_kind 200
#define ILNode_Break_kind 208
#define ILNode_LabelledBreak_kind 209
#define ILNode_Continue_kind 210
#define ILNode_LabelledContinue_kind 211
#define ILNode_Return_kind 212
#define ILNode_ReturnExpr_kind 213
#define ILNode_Goto_kind 214
#define ILNode_GotoLabel_kind 215
#define ILNode_GotoCase_kind 216
#define ILNode_GotoDefault_kind 217
#define ILNode_NewScope_kind 218
#define ILNode_SwitchSection_kind 221
#define ILNode_CaseLabel_kind 223
#define ILNode_DefaultLabel_kind 224
#define ILNode_Throw_kind 225
#define ILNode_ThrowExpr_kind 226
#define ILNode_Try_kind 227
#define ILNode_CatchClause_kind 229
#define ILNode_FinallyClause_kind 230
#define ILNode_Lock_kind 231
#define ILNode_LocalVarDeclaration_kind 232
#define ILNode_LocalConstDeclaration_kind 233
#define ILNode_LineInfo_kind 234
#define ILNode_EventAddOrRemove_kind 235
#define ILNode_Declaration_kind 236
#define ILNode_Compound_kind 198
#define ILNode_SwitchSectList_kind 220
#define ILNode_CaseList_kind 222
#define ILNode_CatchClauses_kind 228
#define ILNode_While_kind 201
#define ILNode_Do_kind 202
#define ILNode_For_kind 203
#define ILNode_Foreach_kind 204
#define ILNode_ForeachString_kind 205
#define ILNode_ForeachCollection_kind 207
#define ILNode_Switch_kind 219
#define ILNode_ClassDefn_kind 237
#define ILNode_ScopeChange_kind 238
#define ILNode_FieldDeclaration_kind 239
#define ILNode_FieldDeclarator_kind 240
#define ILNode_EventDeclaration_kind 241
#define ILNode_EventDeclarator_kind 242
#define ILNode_ProxyDeclaration_kind 243
#define ILNode_MethodDeclaration_kind 244
#define ILNode_PropertyDeclaration_kind 245
#define ILNode_EnumMemberDeclaration_kind 246
#define ILNode_DelegateMemberDeclaration_kind 247
#define ILNode_FormalParameter_kind 248
#define ILNode_AttributeTree_kind 258
#define ILNode_AttributeSection_kind 259
#define ILNode_Attribute_kind 260
#define ILNode_AttrArgs_kind 261
#define ILNode_NamedArg_kind 262
typedef enum {
	ILMachineType_Void,
	ILMachineType_Boolean,
	ILMachineType_Int8,
	ILMachineType_UInt8,
	ILMachineType_Int16,
	ILMachineType_UInt16,
	ILMachineType_Char,
	ILMachineType_Int32,
	ILMachineType_UInt32,
	ILMachineType_Int64,
	ILMachineType_UInt64,
	ILMachineType_NativeInt,
	ILMachineType_NativeUInt,
	ILMachineType_Float32,
	ILMachineType_Float64,
	ILMachineType_NativeFloat,
	ILMachineType_Decimal,
	ILMachineType_String,
	ILMachineType_ObjectRef,
	ILMachineType_UnmanagedPtr,
	ILMachineType_ManagedPtr,
	ILMachineType_TransientPtr,
	ILMachineType_ManagedValue
} ILMachineType;

typedef enum {
	ILAttrMode_NotVisited,
	ILAttrMode_Processing,
	ILAttrMode_Done
} ILAttrMode;

typedef enum {
	ILAttrTargetType_None,
	ILAttrTargetType_Named,
	ILAttrTargetType_Event,
	ILAttrTargetType_Return
} ILAttrTargetType;

typedef struct ILNode__ ILNode;
typedef struct ILNode_Dummy__ ILNode_Dummy;
typedef struct ILNode_Expression__ ILNode_Expression;
typedef struct ILNode_Statement__ ILNode_Statement;
typedef struct ILNode_Identifier__ ILNode_Identifier;
typedef struct ILNode_QualIdent__ ILNode_QualIdent;
typedef struct ILNode_Constant__ ILNode_Constant;
typedef struct ILNode_LValue__ ILNode_LValue;
typedef struct ILNode_UnaryExpression__ ILNode_UnaryExpression;
typedef struct ILNode_BinaryExpression__ ILNode_BinaryExpression;
typedef struct ILNode_TernaryExpression__ ILNode_TernaryExpression;
typedef struct ILNode_AssignExpression__ ILNode_AssignExpression;
typedef struct ILNode_VarArgList__ ILNode_VarArgList;
typedef struct ILNode_Argument__ ILNode_Argument;
typedef struct ILNode_ArgArray__ ILNode_ArgArray;
typedef struct ILNode_BoxingExpression__ ILNode_BoxingExpression;
typedef struct ILNode_Error__ ILNode_Error;
typedef struct ILNode_NewExpression__ ILNode_NewExpression;
typedef struct ILNode_ObjectCreationExpression__ ILNode_ObjectCreationExpression;
typedef struct ILNode_DelegateCreationExpression__ ILNode_DelegateCreationExpression;
typedef struct ILNode_DefaultConstructor__ ILNode_DefaultConstructor;
typedef struct ILNode_BaseInit__ ILNode_BaseInit;
typedef struct ILNode_ThisInit__ ILNode_ThisInit;
typedef struct ILNode_NonStaticInit__ ILNode_NonStaticInit;
typedef struct ILNode_EmptyExpr__ ILNode_EmptyExpr;
typedef struct ILNode_Null__ ILNode_Null;
typedef struct ILNode_NullPtr__ ILNode_NullPtr;
typedef struct ILNode_True__ ILNode_True;
typedef struct ILNode_False__ ILNode_False;
typedef struct ILNode_Integer__ ILNode_Integer;
typedef struct ILNode_Real__ ILNode_Real;
typedef struct ILNode_Decimal__ ILNode_Decimal;
typedef struct ILNode_String__ ILNode_String;
typedef struct ILNode_Int8__ ILNode_Int8;
typedef struct ILNode_UInt8__ ILNode_UInt8;
typedef struct ILNode_Int16__ ILNode_Int16;
typedef struct ILNode_UInt16__ ILNode_UInt16;
typedef struct ILNode_Char__ ILNode_Char;
typedef struct ILNode_Int32__ ILNode_Int32;
typedef struct ILNode_UInt32__ ILNode_UInt32;
typedef struct ILNode_Int64__ ILNode_Int64;
typedef struct ILNode_UInt64__ ILNode_UInt64;
typedef struct ILNode_Int__ ILNode_Int;
typedef struct ILNode_UInt__ ILNode_UInt;
typedef struct ILNode_Float32__ ILNode_Float32;
typedef struct ILNode_Float64__ ILNode_Float64;
typedef struct ILNode_Float__ ILNode_Float;
typedef struct ILNode_LValueNoRef__ ILNode_LValueNoRef;
typedef struct ILNode_LValueUnaryExpr__ ILNode_LValueUnaryExpr;
typedef struct ILNode_LValueBinaryExpr__ ILNode_LValueBinaryExpr;
typedef struct ILNode_This__ ILNode_This;
typedef struct ILNode_LocalVar__ ILNode_LocalVar;
typedef struct ILNode_ArgumentVar__ ILNode_ArgumentVar;
typedef struct ILNode_RefArgumentVar__ ILNode_RefArgumentVar;
typedef struct ILNode_StaticField__ ILNode_StaticField;
typedef struct ILNode_MemberField__ ILNode_MemberField;
typedef struct ILNode_ArrayAccess__ ILNode_ArrayAccess;
typedef struct ILNode_Deref__ ILNode_Deref;
typedef struct ILNode_StaticProperty__ ILNode_StaticProperty;
typedef struct ILNode_MemberProperty__ ILNode_MemberProperty;
typedef struct ILNode_IndexerAccess__ ILNode_IndexerAccess;
typedef struct ILNode_LValueNoRefUnaryExpr__ ILNode_LValueNoRefUnaryExpr;
typedef struct ILNode_BaseAccess__ ILNode_BaseAccess;
typedef struct ILNode_BaseElement__ ILNode_BaseElement;
typedef struct ILNode_AsIs__ ILNode_AsIs;
typedef struct ILNode_Overflow__ ILNode_Overflow;
typedef struct ILNode_NoOverflow__ ILNode_NoOverflow;
typedef struct ILNode_Pedantic__ ILNode_Pedantic;
typedef struct ILNode_NoPedantic__ ILNode_NoPedantic;
typedef struct ILNode_MarkType__ ILNode_MarkType;
typedef struct ILNode_MemberAccess__ ILNode_MemberAccess;
typedef struct ILNode_DerefField__ ILNode_DerefField;
typedef struct ILNode_DummyUnaryExpr__ ILNode_DummyUnaryExpr;
typedef struct ILNode_LogicalNot__ ILNode_LogicalNot;
typedef struct ILNode_Neg__ ILNode_Neg;
typedef struct ILNode_UnaryPlus__ ILNode_UnaryPlus;
typedef struct ILNode_Not__ ILNode_Not;
typedef struct ILNode_UserUnaryOp__ ILNode_UserUnaryOp;
typedef struct ILNode_PreInc__ ILNode_PreInc;
typedef struct ILNode_PreDec__ ILNode_PreDec;
typedef struct ILNode_PostInc__ ILNode_PostInc;
typedef struct ILNode_PostDec__ ILNode_PostDec;
typedef struct ILNode_UserIncOrDec__ ILNode_UserIncOrDec;
typedef struct ILNode_IncOrDecPtr__ ILNode_IncOrDecPtr;
typedef struct ILNode_CastSimple__ ILNode_CastSimple;
typedef struct ILNode_CastType__ ILNode_CastType;
typedef struct ILNode_UserConversion__ ILNode_UserConversion;
typedef struct ILNode_AddressOf__ ILNode_AddressOf;
typedef struct ILNode_ToBool__ ILNode_ToBool;
typedef struct ILNode_ToConst__ ILNode_ToConst;
typedef struct ILNode_VarArgExpand__ ILNode_VarArgExpand;
typedef struct ILNode_IsNull__ ILNode_IsNull;
typedef struct ILNode_IsNonNull__ ILNode_IsNonNull;
typedef struct ILNode_MakeRefAny__ ILNode_MakeRefAny;
typedef struct ILNode_RefType__ ILNode_RefType;
typedef struct ILNode_ArrayLength__ ILNode_ArrayLength;
typedef struct ILNode_ArrayInit__ ILNode_ArrayInit;
typedef struct ILNode_UserPreInc__ ILNode_UserPreInc;
typedef struct ILNode_UserPreDec__ ILNode_UserPreDec;
typedef struct ILNode_UserPostInc__ ILNode_UserPostInc;
typedef struct ILNode_UserPostDec__ ILNode_UserPostDec;
typedef struct ILNode_PreIncPtr__ ILNode_PreIncPtr;
typedef struct ILNode_PreDecPtr__ ILNode_PreDecPtr;
typedef struct ILNode_PostIncPtr__ ILNode_PostIncPtr;
typedef struct ILNode_PostDecPtr__ ILNode_PostDecPtr;
typedef struct ILNode_DummyBinaryExpr__ ILNode_DummyBinaryExpr;
typedef struct ILNode_LogicalAnd__ ILNode_LogicalAnd;
typedef struct ILNode_LogicalOr__ ILNode_LogicalOr;
typedef struct ILNode_UserLogical__ ILNode_UserLogical;
typedef struct ILNode_BinaryArith__ ILNode_BinaryArith;
typedef struct ILNode_BinaryBitwise__ ILNode_BinaryBitwise;
typedef struct ILNode_BinaryShift__ ILNode_BinaryShift;
typedef struct ILNode_UserBinaryOp__ ILNode_UserBinaryOp;
typedef struct ILNode_Concat__ ILNode_Concat;
typedef struct ILNode_DelegateAdd__ ILNode_DelegateAdd;
typedef struct ILNode_DelegateSub__ ILNode_DelegateSub;
typedef struct ILNode_Assign__ ILNode_Assign;
typedef struct ILNode_Relational__ ILNode_Relational;
typedef struct ILNode_Comma__ ILNode_Comma;
typedef struct ILNode_ArgList__ ILNode_ArgList;
typedef struct ILNode_RefValue__ ILNode_RefValue;
typedef struct ILNode_InvocationExpression__ ILNode_InvocationExpression;
typedef struct ILNode_UserLogicalAnd__ ILNode_UserLogicalAnd;
typedef struct ILNode_UserLogicalOr__ ILNode_UserLogicalOr;
typedef struct ILNode_Add__ ILNode_Add;
typedef struct ILNode_Sub__ ILNode_Sub;
typedef struct ILNode_Mul__ ILNode_Mul;
typedef struct ILNode_Div__ ILNode_Div;
typedef struct ILNode_Rem__ ILNode_Rem;
typedef struct ILNode_And__ ILNode_And;
typedef struct ILNode_Or__ ILNode_Or;
typedef struct ILNode_Xor__ ILNode_Xor;
typedef struct ILNode_Shl__ ILNode_Shl;
typedef struct ILNode_Shr__ ILNode_Shr;
typedef struct ILNode_UShr__ ILNode_UShr;
typedef struct ILNode_Eq__ ILNode_Eq;
typedef struct ILNode_Ne__ ILNode_Ne;
typedef struct ILNode_Lt__ ILNode_Lt;
typedef struct ILNode_Le__ ILNode_Le;
typedef struct ILNode_Gt__ ILNode_Gt;
typedef struct ILNode_Ge__ ILNode_Ge;
typedef struct ILNode_Conditional__ ILNode_Conditional;
typedef struct ILNode_AssignAdd__ ILNode_AssignAdd;
typedef struct ILNode_AssignSub__ ILNode_AssignSub;
typedef struct ILNode_AssignMul__ ILNode_AssignMul;
typedef struct ILNode_AssignDiv__ ILNode_AssignDiv;
typedef struct ILNode_AssignRem__ ILNode_AssignRem;
typedef struct ILNode_AssignAnd__ ILNode_AssignAnd;
typedef struct ILNode_AssignOr__ ILNode_AssignOr;
typedef struct ILNode_AssignXor__ ILNode_AssignXor;
typedef struct ILNode_AssignShl__ ILNode_AssignShl;
typedef struct ILNode_AssignShr__ ILNode_AssignShr;
typedef struct ILNode_AssignUShr__ ILNode_AssignUShr;
typedef struct ILNode_As__ ILNode_As;
typedef struct ILNode_Is__ ILNode_Is;
typedef struct ILNode_Box__ ILNode_Box;
typedef struct ILNode_Unbox__ ILNode_Unbox;
typedef struct ILNode_List__ ILNode_List;
typedef struct ILNode_Empty__ ILNode_Empty;
typedef struct ILNode_If__ ILNode_If;
typedef struct ILNode_LabelledStatement__ ILNode_LabelledStatement;
typedef struct ILNode_Break__ ILNode_Break;
typedef struct ILNode_LabelledBreak__ ILNode_LabelledBreak;
typedef struct ILNode_Continue__ ILNode_Continue;
typedef struct ILNode_LabelledContinue__ ILNode_LabelledContinue;
typedef struct ILNode_Return__ ILNode_Return;
typedef struct ILNode_ReturnExpr__ ILNode_ReturnExpr;
typedef struct ILNode_Goto__ ILNode_Goto;
typedef struct ILNode_GotoLabel__ ILNode_GotoLabel;
typedef struct ILNode_GotoCase__ ILNode_GotoCase;
typedef struct ILNode_GotoDefault__ ILNode_GotoDefault;
typedef struct ILNode_NewScope__ ILNode_NewScope;
typedef struct ILNode_SwitchSection__ ILNode_SwitchSection;
typedef struct ILNode_CaseLabel__ ILNode_CaseLabel;
typedef struct ILNode_DefaultLabel__ ILNode_DefaultLabel;
typedef struct ILNode_Throw__ ILNode_Throw;
typedef struct ILNode_ThrowExpr__ ILNode_ThrowExpr;
typedef struct ILNode_Try__ ILNode_Try;
typedef struct ILNode_CatchClause__ ILNode_CatchClause;
typedef struct ILNode_FinallyClause__ ILNode_FinallyClause;
typedef struct ILNode_Lock__ ILNode_Lock;
typedef struct ILNode_LocalVarDeclaration__ ILNode_LocalVarDeclaration;
typedef struct ILNode_LocalConstDeclaration__ ILNode_LocalConstDeclaration;
typedef struct ILNode_LineInfo__ ILNode_LineInfo;
typedef struct ILNode_EventAddOrRemove__ ILNode_EventAddOrRemove;
typedef struct ILNode_Declaration__ ILNode_Declaration;
typedef struct ILNode_Compound__ ILNode_Compound;
typedef struct ILNode_SwitchSectList__ ILNode_SwitchSectList;
typedef struct ILNode_CaseList__ ILNode_CaseList;
typedef struct ILNode_CatchClauses__ ILNode_CatchClauses;
typedef struct ILNode_While__ ILNode_While;
typedef struct ILNode_Do__ ILNode_Do;
typedef struct ILNode_For__ ILNode_For;
typedef struct ILNode_Foreach__ ILNode_Foreach;
typedef struct ILNode_ForeachString__ ILNode_ForeachString;
typedef struct ILNode_ForeachCollection__ ILNode_ForeachCollection;
typedef struct ILNode_Switch__ ILNode_Switch;
typedef struct ILNode_ClassDefn__ ILNode_ClassDefn;
typedef struct ILNode_ScopeChange__ ILNode_ScopeChange;
typedef struct ILNode_FieldDeclaration__ ILNode_FieldDeclaration;
typedef struct ILNode_FieldDeclarator__ ILNode_FieldDeclarator;
typedef struct ILNode_EventDeclaration__ ILNode_EventDeclaration;
typedef struct ILNode_EventDeclarator__ ILNode_EventDeclarator;
typedef struct ILNode_ProxyDeclaration__ ILNode_ProxyDeclaration;
typedef struct ILNode_MethodDeclaration__ ILNode_MethodDeclaration;
typedef struct ILNode_PropertyDeclaration__ ILNode_PropertyDeclaration;
typedef struct ILNode_EnumMemberDeclaration__ ILNode_EnumMemberDeclaration;
typedef struct ILNode_DelegateMemberDeclaration__ ILNode_DelegateMemberDeclaration;
typedef struct ILNode_FormalParameter__ ILNode_FormalParameter;
typedef struct ILNode_AttributeTree__ ILNode_AttributeTree;
typedef struct ILNode_AttributeSection__ ILNode_AttributeSection;
typedef struct ILNode_Attribute__ ILNode_Attribute;
typedef struct ILNode_AttrArgs__ ILNode_AttrArgs;
typedef struct ILNode_NamedArg__ ILNode_NamedArg;
typedef enum {
	ILSwitchTableType_Indexed,
	ILSwitchTableType_Lookup,
	ILSwitchTableType_If,
	ILSwitchTableType_BinaryIf
} ILSwitchTableType;

typedef enum {
	ILVisitMode_NotVisited,
	ILVisitMode_Processing,
	ILVisitMode_Done
} ILVisitMode;

typedef enum {
	ILParamMod_empty,
	ILParamMod_ref,
	ILParamMod_out,
	ILParamMod_params,
	ILParamMod_arglist
} ILParameterModifier;

#line 1 "c_skel.h"
typedef struct
{
	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;

} YYNODESTATE;
#line 543 "cg_nodes.h"
struct ILNode__ {
	const struct ILNode_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_vtable__ {
	const void *parent__;
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

extern struct ILNode_vtable__ const ILNode_vt__;

#define ILNode_GetType(this__,info) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->ILNode_GetType_v__)) \
		((ILNode *)(this__), (info)))

#define ILNode_GenDiscard(this__,info) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->ILNode_GenDiscard_v__)) \
		((ILNode *)(this__), (info)))

#define ILNode_GenValue(this__,info) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->ILNode_GenValue_v__)) \
		((ILNode *)(this__), (info)))

#define ILNode_GenThen(this__,info,label) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->ILNode_GenThen_v__)) \
		((ILNode *)(this__), (info), (label)))

#define ILNode_GenElse(this__,info,label) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->ILNode_GenElse_v__)) \
		((ILNode *)(this__), (info), (label)))

#define ILNode_EvalConst(this__,info,value) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->ILNode_EvalConst_v__)) \
		((ILNode *)(this__), (info), (value)))

#define ILNode_EndsInReturnImpl(this__,info) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->ILNode_EndsInReturnImpl_v__)) \
		((ILNode *)(this__), (info)))

#define JavaGenDiscard(this__,info) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->JavaGenDiscard_v__)) \
		((ILNode *)(this__), (info)))

#define JavaGenValue(this__,info) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->JavaGenValue_v__)) \
		((ILNode *)(this__), (info)))

#define JavaGenThen(this__,info,label) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->JavaGenThen_v__)) \
		((ILNode *)(this__), (info), (label)))

#define JavaGenElse(this__,info,label) \
	((*(((struct ILNode_vtable__ *)((this__)->vtable__))->JavaGenElse_v__)) \
		((ILNode *)(this__), (info), (label)))

extern int ILNode_ILNode_EndsInReturnImpl__(ILNode *node, ILGenInfo * info);

struct ILNode_Dummy__ {
	const struct ILNode_Dummy_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_Dummy_vtable__ {
	const struct ILNode_vtable__ *parent__;
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

extern struct ILNode_Dummy_vtable__ const ILNode_Dummy_vt__;

extern ILMachineType ILNode_Dummy_ILNode_GetType__(ILNode_Dummy *node, ILGenInfo * info);
extern void ILNode_Dummy_ILNode_GenDiscard__(ILNode_Dummy *node, ILGenInfo * info);
extern ILMachineType ILNode_Dummy_ILNode_GenValue__(ILNode_Dummy *node, ILGenInfo * info);
extern void ILNode_Dummy_ILNode_GenThen__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Dummy_ILNode_GenElse__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Dummy_ILNode_EvalConst__(ILNode_Dummy *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Dummy_JavaGenDiscard__(ILNode_Dummy *node, ILGenInfo * info);
extern ILMachineType ILNode_Dummy_JavaGenValue__(ILNode_Dummy *node, ILGenInfo * info);
extern void ILNode_Dummy_JavaGenThen__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Dummy_JavaGenElse__(ILNode_Dummy *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Expression__ {
	const struct ILNode_Expression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_Expression_vtable__ {
	const struct ILNode_vtable__ *parent__;
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

extern struct ILNode_Expression_vtable__ const ILNode_Expression_vt__;

extern void ILNode_Expression_ILNode_GenDiscard__(ILNode_Expression *node, ILGenInfo * info);
extern void ILNode_Expression_ILNode_GenThen__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Expression_ILNode_GenElse__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Expression_ILNode_EvalConst__(ILNode_Expression *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Expression_JavaGenDiscard__(ILNode_Expression *node, ILGenInfo * info);
extern void ILNode_Expression_JavaGenThen__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Expression_JavaGenElse__(ILNode_Expression *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Statement__ {
	const struct ILNode_Statement_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_Statement_vtable__ {
	const struct ILNode_vtable__ *parent__;
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

extern struct ILNode_Statement_vtable__ const ILNode_Statement_vt__;

extern ILMachineType ILNode_Statement_ILNode_GetType__(ILNode_Statement *node, ILGenInfo * info);
extern ILMachineType ILNode_Statement_ILNode_GenValue__(ILNode_Statement *node, ILGenInfo * info);
extern void ILNode_Statement_ILNode_GenThen__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Statement_ILNode_GenElse__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Statement_ILNode_EvalConst__(ILNode_Statement *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Statement_JavaGenValue__(ILNode_Statement *node, ILGenInfo * info);
extern void ILNode_Statement_JavaGenThen__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Statement_JavaGenElse__(ILNode_Statement *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Identifier__ {
	const struct ILNode_Identifier_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * name;
};

struct ILNode_Identifier_vtable__ {
	const struct ILNode_vtable__ *parent__;
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

extern struct ILNode_Identifier_vtable__ const ILNode_Identifier_vt__;

extern ILMachineType ILNode_Identifier_ILNode_GetType__(ILNode_Identifier *node, ILGenInfo * info);
extern void ILNode_Identifier_ILNode_GenDiscard__(ILNode_Identifier *node, ILGenInfo * info);
extern ILMachineType ILNode_Identifier_ILNode_GenValue__(ILNode_Identifier *node, ILGenInfo * info);
extern void ILNode_Identifier_ILNode_GenThen__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Identifier_ILNode_GenElse__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Identifier_ILNode_EvalConst__(ILNode_Identifier *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Identifier_JavaGenDiscard__(ILNode_Identifier *node, ILGenInfo * info);
extern ILMachineType ILNode_Identifier_JavaGenValue__(ILNode_Identifier *node, ILGenInfo * info);
extern void ILNode_Identifier_JavaGenThen__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Identifier_JavaGenElse__(ILNode_Identifier *node, ILGenInfo * info, ILLabel * label);

struct ILNode_QualIdent__ {
	const struct ILNode_QualIdent_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * left;
	ILNode * right;
};

struct ILNode_QualIdent_vtable__ {
	const struct ILNode_vtable__ *parent__;
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

extern struct ILNode_QualIdent_vtable__ const ILNode_QualIdent_vt__;

extern ILMachineType ILNode_QualIdent_ILNode_GetType__(ILNode_QualIdent *node, ILGenInfo * info);
extern void ILNode_QualIdent_ILNode_GenDiscard__(ILNode_QualIdent *node, ILGenInfo * info);
extern ILMachineType ILNode_QualIdent_ILNode_GenValue__(ILNode_QualIdent *node, ILGenInfo * info);
extern void ILNode_QualIdent_ILNode_GenThen__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_QualIdent_ILNode_GenElse__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_QualIdent_ILNode_EvalConst__(ILNode_QualIdent *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_QualIdent_JavaGenDiscard__(ILNode_QualIdent *node, ILGenInfo * info);
extern ILMachineType ILNode_QualIdent_JavaGenValue__(ILNode_QualIdent *node, ILGenInfo * info);
extern void ILNode_QualIdent_JavaGenThen__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_QualIdent_JavaGenElse__(ILNode_QualIdent *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Constant__ {
	const struct ILNode_Constant_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_Constant_vtable__ {
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

extern struct ILNode_Constant_vtable__ const ILNode_Constant_vt__;

extern void ILNode_Constant_ILNode_GenDiscard__(ILNode_Constant *node, ILGenInfo * info);
extern void ILNode_Constant_JavaGenDiscard__(ILNode_Constant *node, ILGenInfo * info);

struct ILNode_LValue__ {
	const struct ILNode_LValue_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_LValue_vtable__ {
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
	ILMachineType (*ILNode_Prepare_v__)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2);
	ILMachineType (*ILNode_GetAndPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2);
	void (*ILNode_Store_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2);
	void (*ILNode_GenRef_v__)(ILNode_LValue *this__, ILGenInfo * info);
	ILMachineType (*JavaPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, void * * data1, void * * data2);
	ILMachineType (*JavaGetAndPrepare_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * * data1, void * * data2);
	void (*JavaStore_v__)(ILNode_LValue *this__, ILGenInfo * info, int leave, void * data1, void * data2);
};

extern struct ILNode_LValue_vtable__ const ILNode_LValue_vt__;

#define ILNode_Prepare(this__,info,data1,data2) \
	((*(((struct ILNode_LValue_vtable__ *)((this__)->vtable__))->ILNode_Prepare_v__)) \
		((ILNode_LValue *)(this__), (info), (data1), (data2)))

#define ILNode_GetAndPrepare(this__,info,leave,data1,data2) \
	((*(((struct ILNode_LValue_vtable__ *)((this__)->vtable__))->ILNode_GetAndPrepare_v__)) \
		((ILNode_LValue *)(this__), (info), (leave), (data1), (data2)))

#define ILNode_Store(this__,info,leave,data1,data2) \
	((*(((struct ILNode_LValue_vtable__ *)((this__)->vtable__))->ILNode_Store_v__)) \
		((ILNode_LValue *)(this__), (info), (leave), (data1), (data2)))

#define ILNode_GenRef(this__,info) \
	((*(((struct ILNode_LValue_vtable__ *)((this__)->vtable__))->ILNode_GenRef_v__)) \
		((ILNode_LValue *)(this__), (info)))

#define JavaPrepare(this__,info,data1,data2) \
	((*(((struct ILNode_LValue_vtable__ *)((this__)->vtable__))->JavaPrepare_v__)) \
		((ILNode_LValue *)(this__), (info), (data1), (data2)))

#define JavaGetAndPrepare(this__,info,leave,data1,data2) \
	((*(((struct ILNode_LValue_vtable__ *)((this__)->vtable__))->JavaGetAndPrepare_v__)) \
		((ILNode_LValue *)(this__), (info), (leave), (data1), (data2)))

#define JavaStore(this__,info,leave,data1,data2) \
	((*(((struct ILNode_LValue_vtable__ *)((this__)->vtable__))->JavaStore_v__)) \
		((ILNode_LValue *)(this__), (info), (leave), (data1), (data2)))

struct ILNode_UnaryExpression__ {
	const struct ILNode_UnaryExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_UnaryExpression_vtable__ {
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

extern struct ILNode_UnaryExpression_vtable__ const ILNode_UnaryExpression_vt__;

struct ILNode_BinaryExpression__ {
	const struct ILNode_BinaryExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_BinaryExpression_vtable__ {
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

extern struct ILNode_BinaryExpression_vtable__ const ILNode_BinaryExpression_vt__;

struct ILNode_TernaryExpression__ {
	const struct ILNode_TernaryExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILNode * expr3;
};

struct ILNode_TernaryExpression_vtable__ {
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

extern struct ILNode_TernaryExpression_vtable__ const ILNode_TernaryExpression_vt__;

struct ILNode_AssignExpression__ {
	const struct ILNode_AssignExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignExpression_vtable__ {
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

extern struct ILNode_AssignExpression_vtable__ const ILNode_AssignExpression_vt__;

extern ILMachineType ILNode_AssignExpression_ILNode_GetType__(ILNode_AssignExpression *node, ILGenInfo * info);
extern void ILNode_AssignExpression_ILNode_GenDiscard__(ILNode_AssignExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_AssignExpression_ILNode_GenValue__(ILNode_AssignExpression *node, ILGenInfo * info);
extern void ILNode_AssignExpression_JavaGenDiscard__(ILNode_AssignExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_AssignExpression_JavaGenValue__(ILNode_AssignExpression *node, ILGenInfo * info);

struct ILNode_VarArgList__ {
	const struct ILNode_VarArgList_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_VarArgList_vtable__ {
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

extern struct ILNode_VarArgList_vtable__ const ILNode_VarArgList_vt__;

extern ILMachineType ILNode_VarArgList_ILNode_GetType__(ILNode_VarArgList *node, ILGenInfo * info);
extern void ILNode_VarArgList_ILNode_GenDiscard__(ILNode_VarArgList *node, ILGenInfo * info);
extern ILMachineType ILNode_VarArgList_ILNode_GenValue__(ILNode_VarArgList *node, ILGenInfo * info);
extern ILMachineType ILNode_VarArgList_JavaGenValue__(ILNode_VarArgList *node, ILGenInfo * info);

struct ILNode_Argument__ {
	const struct ILNode_Argument_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILParameterModifier modifier;
	ILNode * expression;
};

struct ILNode_Argument_vtable__ {
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

extern struct ILNode_Argument_vtable__ const ILNode_Argument_vt__;

extern ILMachineType ILNode_Argument_ILNode_GetType__(ILNode_Argument *node, ILGenInfo * info);
extern ILMachineType ILNode_Argument_ILNode_GenValue__(ILNode_Argument *node, ILGenInfo * info);
extern int ILNode_Argument_ILNode_EvalConst__(ILNode_Argument *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Argument_JavaGenValue__(ILNode_Argument *node, ILGenInfo * info);

struct ILNode_ArgArray__ {
	const struct ILNode_ArgArray_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILType * elemType;
	ILUInt32 numElems;
	ILNode * args;
};

struct ILNode_ArgArray_vtable__ {
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

extern struct ILNode_ArgArray_vtable__ const ILNode_ArgArray_vt__;

extern ILMachineType ILNode_ArgArray_ILNode_GetType__(ILNode_ArgArray *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgArray_ILNode_GenValue__(ILNode_ArgArray *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgArray_JavaGenValue__(ILNode_ArgArray *node, ILGenInfo * info);

struct ILNode_BoxingExpression__ {
	const struct ILNode_BoxingExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILClass * classInfo;
	int isEnumType;
};

struct ILNode_BoxingExpression_vtable__ {
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

extern struct ILNode_BoxingExpression_vtable__ const ILNode_BoxingExpression_vt__;

struct ILNode_Error__ {
	const struct ILNode_Error_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_Error_vtable__ {
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

extern struct ILNode_Error_vtable__ const ILNode_Error_vt__;

extern ILMachineType ILNode_Error_ILNode_GetType__(ILNode_Error *node, ILGenInfo * info);
extern ILMachineType ILNode_Error_ILNode_GenValue__(ILNode_Error *node, ILGenInfo * info);
extern ILMachineType ILNode_Error_JavaGenValue__(ILNode_Error *node, ILGenInfo * info);

struct ILNode_NewExpression__ {
	const struct ILNode_NewExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILNode * indexes;
	ILNode * rank;
	ILNode * arrayInitializer;
	ILType * arrayType;
};

struct ILNode_NewExpression_vtable__ {
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

extern struct ILNode_NewExpression_vtable__ const ILNode_NewExpression_vt__;

extern ILMachineType ILNode_NewExpression_ILNode_GetType__(ILNode_NewExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_NewExpression_ILNode_GenValue__(ILNode_NewExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_NewExpression_JavaGenValue__(ILNode_NewExpression *node, ILGenInfo * info);

struct ILNode_ObjectCreationExpression__ {
	const struct ILNode_ObjectCreationExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * type;
	ILNode * argList;
	ILMethod * methodInfo;
	ILType * callSiteSig;
};

struct ILNode_ObjectCreationExpression_vtable__ {
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

extern struct ILNode_ObjectCreationExpression_vtable__ const ILNode_ObjectCreationExpression_vt__;

extern ILMachineType ILNode_ObjectCreationExpression_ILNode_GetType__(ILNode_ObjectCreationExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_ObjectCreationExpression_ILNode_GenValue__(ILNode_ObjectCreationExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_ObjectCreationExpression_JavaGenValue__(ILNode_ObjectCreationExpression *node, ILGenInfo * info);

struct ILNode_DelegateCreationExpression__ {
	const struct ILNode_DelegateCreationExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILClass * delegateClass;
	ILNode * expr;
	ILMethod * methodInfo;
};

struct ILNode_DelegateCreationExpression_vtable__ {
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

extern struct ILNode_DelegateCreationExpression_vtable__ const ILNode_DelegateCreationExpression_vt__;

extern ILMachineType ILNode_DelegateCreationExpression_ILNode_GetType__(ILNode_DelegateCreationExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_DelegateCreationExpression_ILNode_GenValue__(ILNode_DelegateCreationExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_DelegateCreationExpression_JavaGenValue__(ILNode_DelegateCreationExpression *node, ILGenInfo * info);

struct ILNode_DefaultConstructor__ {
	const struct ILNode_DefaultConstructor_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
	int useCtorMethod;
};

struct ILNode_DefaultConstructor_vtable__ {
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

extern struct ILNode_DefaultConstructor_vtable__ const ILNode_DefaultConstructor_vt__;

extern ILMachineType ILNode_DefaultConstructor_ILNode_GetType__(ILNode_DefaultConstructor *node, ILGenInfo * info);
extern ILMachineType ILNode_DefaultConstructor_ILNode_GenValue__(ILNode_DefaultConstructor *node, ILGenInfo * info);
extern int ILNode_DefaultConstructor_ILNode_EvalConst__(ILNode_DefaultConstructor *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_DefaultConstructor_JavaGenValue__(ILNode_DefaultConstructor *node, ILGenInfo * info);

struct ILNode_BaseInit__ {
	const struct ILNode_BaseInit_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_BaseInit_vtable__ {
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

extern struct ILNode_BaseInit_vtable__ const ILNode_BaseInit_vt__;

extern ILMachineType ILNode_BaseInit_ILNode_GetType__(ILNode_BaseInit *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseInit_ILNode_GenValue__(ILNode_BaseInit *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseInit_JavaGenValue__(ILNode_BaseInit *node, ILGenInfo * info);

struct ILNode_ThisInit__ {
	const struct ILNode_ThisInit_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_ThisInit_vtable__ {
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

extern struct ILNode_ThisInit_vtable__ const ILNode_ThisInit_vt__;

extern ILMachineType ILNode_ThisInit_ILNode_GetType__(ILNode_ThisInit *node, ILGenInfo * info);
extern ILMachineType ILNode_ThisInit_ILNode_GenValue__(ILNode_ThisInit *node, ILGenInfo * info);
extern ILMachineType ILNode_ThisInit_JavaGenValue__(ILNode_ThisInit *node, ILGenInfo * info);

struct ILNode_NonStaticInit__ {
	const struct ILNode_NonStaticInit_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_NonStaticInit_vtable__ {
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

extern struct ILNode_NonStaticInit_vtable__ const ILNode_NonStaticInit_vt__;

extern ILMachineType ILNode_NonStaticInit_ILNode_GetType__(ILNode_NonStaticInit *node, ILGenInfo * info);
extern ILMachineType ILNode_NonStaticInit_ILNode_GenValue__(ILNode_NonStaticInit *node, ILGenInfo * info);
extern ILMachineType ILNode_NonStaticInit_JavaGenValue__(ILNode_NonStaticInit *node, ILGenInfo * info);

struct ILNode_EmptyExpr__ {
	const struct ILNode_EmptyExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILMachineType type;
};

struct ILNode_EmptyExpr_vtable__ {
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

extern struct ILNode_EmptyExpr_vtable__ const ILNode_EmptyExpr_vt__;

extern ILMachineType ILNode_EmptyExpr_ILNode_GetType__(ILNode_EmptyExpr *node, ILGenInfo * info);
extern void ILNode_EmptyExpr_ILNode_GenDiscard__(ILNode_EmptyExpr *node, ILGenInfo * info);
extern ILMachineType ILNode_EmptyExpr_ILNode_GenValue__(ILNode_EmptyExpr *node, ILGenInfo * info);
extern void ILNode_EmptyExpr_JavaGenDiscard__(ILNode_EmptyExpr *node, ILGenInfo * info);
extern ILMachineType ILNode_EmptyExpr_JavaGenValue__(ILNode_EmptyExpr *node, ILGenInfo * info);

struct ILNode_Null__ {
	const struct ILNode_Null_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_Null_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_Null_vtable__ const ILNode_Null_vt__;

extern ILMachineType ILNode_Null_ILNode_GetType__(ILNode_Null *node, ILGenInfo * info);
extern ILMachineType ILNode_Null_ILNode_GenValue__(ILNode_Null *node, ILGenInfo * info);
extern void ILNode_Null_ILNode_GenThen__(ILNode_Null *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Null_ILNode_GenElse__(ILNode_Null *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Null_ILNode_EvalConst__(ILNode_Null *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Null_JavaGenValue__(ILNode_Null *node, ILGenInfo * info);
extern void ILNode_Null_JavaGenThen__(ILNode_Null *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Null_JavaGenElse__(ILNode_Null *node, ILGenInfo * info, ILLabel * label);

struct ILNode_NullPtr__ {
	const struct ILNode_NullPtr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_NullPtr_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_NullPtr_vtable__ const ILNode_NullPtr_vt__;

extern ILMachineType ILNode_NullPtr_ILNode_GetType__(ILNode_NullPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_NullPtr_ILNode_GenValue__(ILNode_NullPtr *node, ILGenInfo * info);
extern void ILNode_NullPtr_ILNode_GenThen__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_NullPtr_ILNode_GenElse__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_NullPtr_ILNode_EvalConst__(ILNode_NullPtr *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_NullPtr_JavaGenValue__(ILNode_NullPtr *node, ILGenInfo * info);
extern void ILNode_NullPtr_JavaGenThen__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_NullPtr_JavaGenElse__(ILNode_NullPtr *node, ILGenInfo * info, ILLabel * label);

struct ILNode_True__ {
	const struct ILNode_True_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_True_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_True_vtable__ const ILNode_True_vt__;

extern ILMachineType ILNode_True_ILNode_GetType__(ILNode_True *node, ILGenInfo * info);
extern ILMachineType ILNode_True_ILNode_GenValue__(ILNode_True *node, ILGenInfo * info);
extern void ILNode_True_ILNode_GenThen__(ILNode_True *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_True_ILNode_GenElse__(ILNode_True *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_True_ILNode_EvalConst__(ILNode_True *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_True_JavaGenValue__(ILNode_True *node, ILGenInfo * info);
extern void ILNode_True_JavaGenThen__(ILNode_True *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_True_JavaGenElse__(ILNode_True *node, ILGenInfo * info, ILLabel * label);

struct ILNode_False__ {
	const struct ILNode_False_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_False_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_False_vtable__ const ILNode_False_vt__;

extern ILMachineType ILNode_False_ILNode_GetType__(ILNode_False *node, ILGenInfo * info);
extern ILMachineType ILNode_False_ILNode_GenValue__(ILNode_False *node, ILGenInfo * info);
extern void ILNode_False_ILNode_GenThen__(ILNode_False *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_False_ILNode_GenElse__(ILNode_False *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_False_ILNode_EvalConst__(ILNode_False *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_False_JavaGenValue__(ILNode_False *node, ILGenInfo * info);
extern void ILNode_False_JavaGenThen__(ILNode_False *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_False_JavaGenElse__(ILNode_False *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Integer__ {
	const struct ILNode_Integer_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_Integer_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_Integer_vtable__ const ILNode_Integer_vt__;

extern void ILNode_Integer_ILNode_GenThen__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Integer_ILNode_GenElse__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Integer_JavaGenThen__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Integer_JavaGenElse__(ILNode_Integer *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Real__ {
	const struct ILNode_Real_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILDouble value;
};

struct ILNode_Real_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_Real_vtable__ const ILNode_Real_vt__;

extern void ILNode_Real_ILNode_GenThen__(ILNode_Real *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Real_ILNode_GenElse__(ILNode_Real *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Real_JavaGenThen__(ILNode_Real *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Real_JavaGenElse__(ILNode_Real *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Decimal__ {
	const struct ILNode_Decimal_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILDecimal value;
};

struct ILNode_Decimal_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_Decimal_vtable__ const ILNode_Decimal_vt__;

extern ILMachineType ILNode_Decimal_ILNode_GetType__(ILNode_Decimal *node, ILGenInfo * info);
extern ILMachineType ILNode_Decimal_ILNode_GenValue__(ILNode_Decimal *node, ILGenInfo * info);
extern void ILNode_Decimal_ILNode_GenThen__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Decimal_ILNode_GenElse__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Decimal_ILNode_EvalConst__(ILNode_Decimal *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Decimal_JavaGenValue__(ILNode_Decimal *node, ILGenInfo * info);
extern void ILNode_Decimal_JavaGenThen__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Decimal_JavaGenElse__(ILNode_Decimal *node, ILGenInfo * info, ILLabel * label);

struct ILNode_String__ {
	const struct ILNode_String_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	char * str;
	int len;
};

struct ILNode_String_vtable__ {
	const struct ILNode_Constant_vtable__ *parent__;
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

extern struct ILNode_String_vtable__ const ILNode_String_vt__;

extern ILMachineType ILNode_String_ILNode_GetType__(ILNode_String *node, ILGenInfo * info);
extern ILMachineType ILNode_String_ILNode_GenValue__(ILNode_String *node, ILGenInfo * info);
extern void ILNode_String_ILNode_GenThen__(ILNode_String *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_String_ILNode_GenElse__(ILNode_String *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_String_ILNode_EvalConst__(ILNode_String *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_String_JavaGenValue__(ILNode_String *node, ILGenInfo * info);
extern void ILNode_String_JavaGenThen__(ILNode_String *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_String_JavaGenElse__(ILNode_String *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Int8__ {
	const struct ILNode_Int8_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_Int8_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_Int8_vtable__ const ILNode_Int8_vt__;

extern ILMachineType ILNode_Int8_ILNode_GetType__(ILNode_Int8 *node, ILGenInfo * info);
extern ILMachineType ILNode_Int8_ILNode_GenValue__(ILNode_Int8 *node, ILGenInfo * info);
extern int ILNode_Int8_ILNode_EvalConst__(ILNode_Int8 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Int8_JavaGenValue__(ILNode_Int8 *node, ILGenInfo * info);

struct ILNode_UInt8__ {
	const struct ILNode_UInt8_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_UInt8_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_UInt8_vtable__ const ILNode_UInt8_vt__;

extern ILMachineType ILNode_UInt8_ILNode_GetType__(ILNode_UInt8 *node, ILGenInfo * info);
extern ILMachineType ILNode_UInt8_ILNode_GenValue__(ILNode_UInt8 *node, ILGenInfo * info);
extern int ILNode_UInt8_ILNode_EvalConst__(ILNode_UInt8 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_UInt8_JavaGenValue__(ILNode_UInt8 *node, ILGenInfo * info);

struct ILNode_Int16__ {
	const struct ILNode_Int16_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_Int16_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_Int16_vtable__ const ILNode_Int16_vt__;

extern ILMachineType ILNode_Int16_ILNode_GetType__(ILNode_Int16 *node, ILGenInfo * info);
extern ILMachineType ILNode_Int16_ILNode_GenValue__(ILNode_Int16 *node, ILGenInfo * info);
extern int ILNode_Int16_ILNode_EvalConst__(ILNode_Int16 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Int16_JavaGenValue__(ILNode_Int16 *node, ILGenInfo * info);

struct ILNode_UInt16__ {
	const struct ILNode_UInt16_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_UInt16_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_UInt16_vtable__ const ILNode_UInt16_vt__;

extern ILMachineType ILNode_UInt16_ILNode_GetType__(ILNode_UInt16 *node, ILGenInfo * info);
extern ILMachineType ILNode_UInt16_ILNode_GenValue__(ILNode_UInt16 *node, ILGenInfo * info);
extern int ILNode_UInt16_ILNode_EvalConst__(ILNode_UInt16 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_UInt16_JavaGenValue__(ILNode_UInt16 *node, ILGenInfo * info);

struct ILNode_Char__ {
	const struct ILNode_Char_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_Char_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_Char_vtable__ const ILNode_Char_vt__;

extern ILMachineType ILNode_Char_ILNode_GetType__(ILNode_Char *node, ILGenInfo * info);
extern ILMachineType ILNode_Char_ILNode_GenValue__(ILNode_Char *node, ILGenInfo * info);
extern int ILNode_Char_ILNode_EvalConst__(ILNode_Char *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Char_JavaGenValue__(ILNode_Char *node, ILGenInfo * info);

struct ILNode_Int32__ {
	const struct ILNode_Int32_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_Int32_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_Int32_vtable__ const ILNode_Int32_vt__;

extern ILMachineType ILNode_Int32_ILNode_GetType__(ILNode_Int32 *node, ILGenInfo * info);
extern ILMachineType ILNode_Int32_ILNode_GenValue__(ILNode_Int32 *node, ILGenInfo * info);
extern int ILNode_Int32_ILNode_EvalConst__(ILNode_Int32 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Int32_JavaGenValue__(ILNode_Int32 *node, ILGenInfo * info);

struct ILNode_UInt32__ {
	const struct ILNode_UInt32_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_UInt32_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_UInt32_vtable__ const ILNode_UInt32_vt__;

extern ILMachineType ILNode_UInt32_ILNode_GetType__(ILNode_UInt32 *node, ILGenInfo * info);
extern ILMachineType ILNode_UInt32_ILNode_GenValue__(ILNode_UInt32 *node, ILGenInfo * info);
extern int ILNode_UInt32_ILNode_EvalConst__(ILNode_UInt32 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_UInt32_JavaGenValue__(ILNode_UInt32 *node, ILGenInfo * info);

struct ILNode_Int64__ {
	const struct ILNode_Int64_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_Int64_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_Int64_vtable__ const ILNode_Int64_vt__;

extern ILMachineType ILNode_Int64_ILNode_GetType__(ILNode_Int64 *node, ILGenInfo * info);
extern ILMachineType ILNode_Int64_ILNode_GenValue__(ILNode_Int64 *node, ILGenInfo * info);
extern int ILNode_Int64_ILNode_EvalConst__(ILNode_Int64 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Int64_JavaGenValue__(ILNode_Int64 *node, ILGenInfo * info);

struct ILNode_UInt64__ {
	const struct ILNode_UInt64_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_UInt64_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_UInt64_vtable__ const ILNode_UInt64_vt__;

extern ILMachineType ILNode_UInt64_ILNode_GetType__(ILNode_UInt64 *node, ILGenInfo * info);
extern ILMachineType ILNode_UInt64_ILNode_GenValue__(ILNode_UInt64 *node, ILGenInfo * info);
extern int ILNode_UInt64_ILNode_EvalConst__(ILNode_UInt64 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_UInt64_JavaGenValue__(ILNode_UInt64 *node, ILGenInfo * info);

struct ILNode_Int__ {
	const struct ILNode_Int_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_Int_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_Int_vtable__ const ILNode_Int_vt__;

extern ILMachineType ILNode_Int_ILNode_GetType__(ILNode_Int *node, ILGenInfo * info);
extern ILMachineType ILNode_Int_ILNode_GenValue__(ILNode_Int *node, ILGenInfo * info);
extern int ILNode_Int_ILNode_EvalConst__(ILNode_Int *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Int_JavaGenValue__(ILNode_Int *node, ILGenInfo * info);

struct ILNode_UInt__ {
	const struct ILNode_UInt_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILUInt64 value;
	int isneg;
	int canneg;
};

struct ILNode_UInt_vtable__ {
	const struct ILNode_Integer_vtable__ *parent__;
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

extern struct ILNode_UInt_vtable__ const ILNode_UInt_vt__;

extern ILMachineType ILNode_UInt_ILNode_GetType__(ILNode_UInt *node, ILGenInfo * info);
extern ILMachineType ILNode_UInt_ILNode_GenValue__(ILNode_UInt *node, ILGenInfo * info);
extern int ILNode_UInt_ILNode_EvalConst__(ILNode_UInt *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_UInt_JavaGenValue__(ILNode_UInt *node, ILGenInfo * info);

struct ILNode_Float32__ {
	const struct ILNode_Float32_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILDouble value;
};

struct ILNode_Float32_vtable__ {
	const struct ILNode_Real_vtable__ *parent__;
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

extern struct ILNode_Float32_vtable__ const ILNode_Float32_vt__;

extern ILMachineType ILNode_Float32_ILNode_GetType__(ILNode_Float32 *node, ILGenInfo * info);
extern ILMachineType ILNode_Float32_ILNode_GenValue__(ILNode_Float32 *node, ILGenInfo * info);
extern int ILNode_Float32_ILNode_EvalConst__(ILNode_Float32 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Float32_JavaGenValue__(ILNode_Float32 *node, ILGenInfo * info);

struct ILNode_Float64__ {
	const struct ILNode_Float64_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILDouble value;
};

struct ILNode_Float64_vtable__ {
	const struct ILNode_Real_vtable__ *parent__;
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

extern struct ILNode_Float64_vtable__ const ILNode_Float64_vt__;

extern ILMachineType ILNode_Float64_ILNode_GetType__(ILNode_Float64 *node, ILGenInfo * info);
extern ILMachineType ILNode_Float64_ILNode_GenValue__(ILNode_Float64 *node, ILGenInfo * info);
extern int ILNode_Float64_ILNode_EvalConst__(ILNode_Float64 *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Float64_JavaGenValue__(ILNode_Float64 *node, ILGenInfo * info);

struct ILNode_Float__ {
	const struct ILNode_Float_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILDouble value;
};

struct ILNode_Float_vtable__ {
	const struct ILNode_Real_vtable__ *parent__;
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

extern struct ILNode_Float_vtable__ const ILNode_Float_vt__;

extern ILMachineType ILNode_Float_ILNode_GetType__(ILNode_Float *node, ILGenInfo * info);
extern ILMachineType ILNode_Float_ILNode_GenValue__(ILNode_Float *node, ILGenInfo * info);
extern int ILNode_Float_ILNode_EvalConst__(ILNode_Float *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_Float_JavaGenValue__(ILNode_Float *node, ILGenInfo * info);

struct ILNode_LValueNoRef__ {
	const struct ILNode_LValueNoRef_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_LValueNoRef_vtable__ {
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

extern struct ILNode_LValueNoRef_vtable__ const ILNode_LValueNoRef_vt__;

extern void ILNode_LValueNoRef_ILNode_GenRef__(ILNode_LValueNoRef *node, ILGenInfo * info);

struct ILNode_LValueUnaryExpr__ {
	const struct ILNode_LValueUnaryExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_LValueUnaryExpr_vtable__ {
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

extern struct ILNode_LValueUnaryExpr_vtable__ const ILNode_LValueUnaryExpr_vt__;

struct ILNode_LValueBinaryExpr__ {
	const struct ILNode_LValueBinaryExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_LValueBinaryExpr_vtable__ {
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

extern struct ILNode_LValueBinaryExpr_vtable__ const ILNode_LValueBinaryExpr_vt__;

struct ILNode_This__ {
	const struct ILNode_This_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
};

struct ILNode_This_vtable__ {
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

extern struct ILNode_This_vtable__ const ILNode_This_vt__;

extern ILMachineType ILNode_This_ILNode_GetType__(ILNode_This *node, ILGenInfo * info);
extern void ILNode_This_ILNode_GenDiscard__(ILNode_This *node, ILGenInfo * info);
extern ILMachineType ILNode_This_ILNode_GenValue__(ILNode_This *node, ILGenInfo * info);
extern void ILNode_This_JavaGenDiscard__(ILNode_This *node, ILGenInfo * info);
extern ILMachineType ILNode_This_JavaGenValue__(ILNode_This *node, ILGenInfo * info);
extern ILMachineType ILNode_This_ILNode_Prepare__(ILNode_This *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_This_ILNode_GetAndPrepare__(ILNode_This *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_This_ILNode_Store__(ILNode_This *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_This_ILNode_GenRef__(ILNode_This *node, ILGenInfo * info);
extern ILMachineType ILNode_This_JavaPrepare__(ILNode_This *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_This_JavaGetAndPrepare__(ILNode_This *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_This_JavaStore__(ILNode_This *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_LocalVar__ {
	const struct ILNode_LocalVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	unsigned long index;
	ILMachineType machineType;
};

struct ILNode_LocalVar_vtable__ {
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

extern struct ILNode_LocalVar_vtable__ const ILNode_LocalVar_vt__;

extern ILMachineType ILNode_LocalVar_ILNode_GetType__(ILNode_LocalVar *node, ILGenInfo * info);
extern void ILNode_LocalVar_ILNode_GenDiscard__(ILNode_LocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_LocalVar_ILNode_GenValue__(ILNode_LocalVar *node, ILGenInfo * info);
extern void ILNode_LocalVar_JavaGenDiscard__(ILNode_LocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_LocalVar_JavaGenValue__(ILNode_LocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_LocalVar_ILNode_Prepare__(ILNode_LocalVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_LocalVar_ILNode_GetAndPrepare__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_LocalVar_ILNode_Store__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_LocalVar_ILNode_GenRef__(ILNode_LocalVar *node, ILGenInfo * info);
extern ILMachineType ILNode_LocalVar_JavaPrepare__(ILNode_LocalVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_LocalVar_JavaGetAndPrepare__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_LocalVar_JavaStore__(ILNode_LocalVar *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_ArgumentVar__ {
	const struct ILNode_ArgumentVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	unsigned long index;
	ILMachineType machineType;
};

struct ILNode_ArgumentVar_vtable__ {
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

extern struct ILNode_ArgumentVar_vtable__ const ILNode_ArgumentVar_vt__;

extern ILMachineType ILNode_ArgumentVar_ILNode_GetType__(ILNode_ArgumentVar *node, ILGenInfo * info);
extern void ILNode_ArgumentVar_ILNode_GenDiscard__(ILNode_ArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgumentVar_ILNode_GenValue__(ILNode_ArgumentVar *node, ILGenInfo * info);
extern void ILNode_ArgumentVar_JavaGenDiscard__(ILNode_ArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgumentVar_JavaGenValue__(ILNode_ArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgumentVar_ILNode_Prepare__(ILNode_ArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_ArgumentVar_ILNode_GetAndPrepare__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_ArgumentVar_ILNode_Store__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_ArgumentVar_ILNode_GenRef__(ILNode_ArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgumentVar_JavaPrepare__(ILNode_ArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_ArgumentVar_JavaGetAndPrepare__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_ArgumentVar_JavaStore__(ILNode_ArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_RefArgumentVar__ {
	const struct ILNode_RefArgumentVar_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	unsigned long index;
	ILMachineType machineType;
	ILType * type;
};

struct ILNode_RefArgumentVar_vtable__ {
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

extern struct ILNode_RefArgumentVar_vtable__ const ILNode_RefArgumentVar_vt__;

extern ILMachineType ILNode_RefArgumentVar_ILNode_GetType__(ILNode_RefArgumentVar *node, ILGenInfo * info);
extern void ILNode_RefArgumentVar_ILNode_GenDiscard__(ILNode_RefArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_RefArgumentVar_ILNode_GenValue__(ILNode_RefArgumentVar *node, ILGenInfo * info);
extern void ILNode_RefArgumentVar_JavaGenDiscard__(ILNode_RefArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_RefArgumentVar_JavaGenValue__(ILNode_RefArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_RefArgumentVar_ILNode_Prepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_RefArgumentVar_ILNode_GetAndPrepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_RefArgumentVar_ILNode_Store__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_RefArgumentVar_ILNode_GenRef__(ILNode_RefArgumentVar *node, ILGenInfo * info);
extern ILMachineType ILNode_RefArgumentVar_JavaPrepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_RefArgumentVar_JavaGetAndPrepare__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_RefArgumentVar_JavaStore__(ILNode_RefArgumentVar *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_StaticField__ {
	const struct ILNode_StaticField_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILField * field;
};

struct ILNode_StaticField_vtable__ {
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

extern struct ILNode_StaticField_vtable__ const ILNode_StaticField_vt__;

extern ILMachineType ILNode_StaticField_ILNode_GetType__(ILNode_StaticField *node, ILGenInfo * info);
extern void ILNode_StaticField_ILNode_GenDiscard__(ILNode_StaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_StaticField_ILNode_GenValue__(ILNode_StaticField *node, ILGenInfo * info);
extern void ILNode_StaticField_JavaGenDiscard__(ILNode_StaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_StaticField_JavaGenValue__(ILNode_StaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_StaticField_ILNode_Prepare__(ILNode_StaticField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_StaticField_ILNode_GetAndPrepare__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_StaticField_ILNode_Store__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_StaticField_ILNode_GenRef__(ILNode_StaticField *node, ILGenInfo * info);
extern ILMachineType ILNode_StaticField_JavaPrepare__(ILNode_StaticField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_StaticField_JavaGetAndPrepare__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_StaticField_JavaStore__(ILNode_StaticField *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_MemberField__ {
	const struct ILNode_MemberField_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILField * field;
	ILUInt32 tempVar;
	ILUInt32 baseCall;
};

struct ILNode_MemberField_vtable__ {
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

extern struct ILNode_MemberField_vtable__ const ILNode_MemberField_vt__;

extern ILMachineType ILNode_MemberField_ILNode_GetType__(ILNode_MemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberField_ILNode_GenValue__(ILNode_MemberField *node, ILGenInfo * info);
extern void ILNode_MemberField_JavaGenDiscard__(ILNode_MemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberField_JavaGenValue__(ILNode_MemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberField_ILNode_Prepare__(ILNode_MemberField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_MemberField_ILNode_GetAndPrepare__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_MemberField_ILNode_Store__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_MemberField_ILNode_GenRef__(ILNode_MemberField *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberField_JavaPrepare__(ILNode_MemberField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_MemberField_JavaGetAndPrepare__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_MemberField_JavaStore__(ILNode_MemberField *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_ArrayAccess__ {
	const struct ILNode_ArrayAccess_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * array;
	ILNode * indices;
	ILType * arrayType;
	ILType * elemType;
	long saveStack;
};

struct ILNode_ArrayAccess_vtable__ {
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

extern struct ILNode_ArrayAccess_vtable__ const ILNode_ArrayAccess_vt__;

extern ILMachineType ILNode_ArrayAccess_ILNode_GetType__(ILNode_ArrayAccess *node, ILGenInfo * info);
extern void ILNode_ArrayAccess_ILNode_GenDiscard__(ILNode_ArrayAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayAccess_ILNode_GenValue__(ILNode_ArrayAccess *node, ILGenInfo * info);
extern void ILNode_ArrayAccess_JavaGenDiscard__(ILNode_ArrayAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayAccess_JavaGenValue__(ILNode_ArrayAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayAccess_ILNode_Prepare__(ILNode_ArrayAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_ArrayAccess_ILNode_GetAndPrepare__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_ArrayAccess_ILNode_Store__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_ArrayAccess_ILNode_GenRef__(ILNode_ArrayAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayAccess_JavaPrepare__(ILNode_ArrayAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_ArrayAccess_JavaGetAndPrepare__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_ArrayAccess_JavaStore__(ILNode_ArrayAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_Deref__ {
	const struct ILNode_Deref_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * elemType;
};

struct ILNode_Deref_vtable__ {
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

extern struct ILNode_Deref_vtable__ const ILNode_Deref_vt__;

extern ILMachineType ILNode_Deref_ILNode_GetType__(ILNode_Deref *node, ILGenInfo * info);
extern void ILNode_Deref_ILNode_GenDiscard__(ILNode_Deref *node, ILGenInfo * info);
extern ILMachineType ILNode_Deref_ILNode_GenValue__(ILNode_Deref *node, ILGenInfo * info);
extern void ILNode_Deref_JavaGenDiscard__(ILNode_Deref *node, ILGenInfo * info);
extern ILMachineType ILNode_Deref_JavaGenValue__(ILNode_Deref *node, ILGenInfo * info);
extern ILMachineType ILNode_Deref_ILNode_Prepare__(ILNode_Deref *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_Deref_ILNode_GetAndPrepare__(ILNode_Deref *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_Deref_ILNode_Store__(ILNode_Deref *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_Deref_JavaPrepare__(ILNode_Deref *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_Deref_JavaGetAndPrepare__(ILNode_Deref *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_Deref_JavaStore__(ILNode_Deref *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_StaticProperty__ {
	const struct ILNode_StaticProperty_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILProperty * property;
	ILUInt32 baseCall;
};

struct ILNode_StaticProperty_vtable__ {
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

extern struct ILNode_StaticProperty_vtable__ const ILNode_StaticProperty_vt__;

extern ILMachineType ILNode_StaticProperty_ILNode_GetType__(ILNode_StaticProperty *node, ILGenInfo * info);
extern void ILNode_StaticProperty_ILNode_GenDiscard__(ILNode_StaticProperty *node, ILGenInfo * info);
extern ILMachineType ILNode_StaticProperty_ILNode_GenValue__(ILNode_StaticProperty *node, ILGenInfo * info);
extern ILMachineType ILNode_StaticProperty_JavaGenValue__(ILNode_StaticProperty *node, ILGenInfo * info);
extern ILMachineType ILNode_StaticProperty_ILNode_Prepare__(ILNode_StaticProperty *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_StaticProperty_ILNode_GetAndPrepare__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_StaticProperty_ILNode_Store__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_StaticProperty_JavaPrepare__(ILNode_StaticProperty *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_StaticProperty_JavaGetAndPrepare__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_StaticProperty_JavaStore__(ILNode_StaticProperty *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_MemberProperty__ {
	const struct ILNode_MemberProperty_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILProperty * property;
	ILUInt32 tempVar;
	ILUInt32 baseCall;
};

struct ILNode_MemberProperty_vtable__ {
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

extern struct ILNode_MemberProperty_vtable__ const ILNode_MemberProperty_vt__;

extern ILMachineType ILNode_MemberProperty_ILNode_GetType__(ILNode_MemberProperty *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberProperty_ILNode_GenValue__(ILNode_MemberProperty *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberProperty_JavaGenValue__(ILNode_MemberProperty *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberProperty_ILNode_Prepare__(ILNode_MemberProperty *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_MemberProperty_ILNode_GetAndPrepare__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_MemberProperty_ILNode_Store__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_MemberProperty_JavaPrepare__(ILNode_MemberProperty *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_MemberProperty_JavaGetAndPrepare__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_MemberProperty_JavaStore__(ILNode_MemberProperty *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_IndexerAccess__ {
	const struct ILNode_IndexerAccess_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * object;
	ILNode * indices;
	ILMethod * getMethod;
	ILMethod * setMethod;
	ILType * objectType;
	ILType * elemType;
	ILMachineType machineType;
	int baseAccess;
	long saveStack;
};

struct ILNode_IndexerAccess_vtable__ {
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

extern struct ILNode_IndexerAccess_vtable__ const ILNode_IndexerAccess_vt__;

extern ILMachineType ILNode_IndexerAccess_ILNode_GetType__(ILNode_IndexerAccess *node, ILGenInfo * info);
extern void ILNode_IndexerAccess_ILNode_GenDiscard__(ILNode_IndexerAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_IndexerAccess_ILNode_GenValue__(ILNode_IndexerAccess *node, ILGenInfo * info);
extern void ILNode_IndexerAccess_JavaGenDiscard__(ILNode_IndexerAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_IndexerAccess_JavaGenValue__(ILNode_IndexerAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_IndexerAccess_ILNode_Prepare__(ILNode_IndexerAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_IndexerAccess_ILNode_GetAndPrepare__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_IndexerAccess_ILNode_Store__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_IndexerAccess_JavaPrepare__(ILNode_IndexerAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_IndexerAccess_JavaGetAndPrepare__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_IndexerAccess_JavaStore__(ILNode_IndexerAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_LValueNoRefUnaryExpr__ {
	const struct ILNode_LValueNoRefUnaryExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_LValueNoRefUnaryExpr_vtable__ {
	const struct ILNode_LValueUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_LValueNoRefUnaryExpr_vtable__ const ILNode_LValueNoRefUnaryExpr_vt__;

extern void ILNode_LValueNoRefUnaryExpr_ILNode_GenRef__(ILNode_LValueNoRefUnaryExpr *node, ILGenInfo * info);

struct ILNode_BaseAccess__ {
	const struct ILNode_BaseAccess_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMachineType machineType;
};

struct ILNode_BaseAccess_vtable__ {
	const struct ILNode_LValueUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_BaseAccess_vtable__ const ILNode_BaseAccess_vt__;

extern ILMachineType ILNode_BaseAccess_ILNode_GetType__(ILNode_BaseAccess *node, ILGenInfo * info);
extern void ILNode_BaseAccess_ILNode_GenDiscard__(ILNode_BaseAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseAccess_ILNode_GenValue__(ILNode_BaseAccess *node, ILGenInfo * info);
extern void ILNode_BaseAccess_JavaGenDiscard__(ILNode_BaseAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseAccess_JavaGenValue__(ILNode_BaseAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseAccess_ILNode_Prepare__(ILNode_BaseAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_BaseAccess_ILNode_GetAndPrepare__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_BaseAccess_ILNode_Store__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_BaseAccess_ILNode_GenRef__(ILNode_BaseAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseAccess_JavaPrepare__(ILNode_BaseAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_BaseAccess_JavaGetAndPrepare__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_BaseAccess_JavaStore__(ILNode_BaseAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_BaseElement__ {
	const struct ILNode_BaseElement_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMachineType machineType;
};

struct ILNode_BaseElement_vtable__ {
	const struct ILNode_LValueUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_BaseElement_vtable__ const ILNode_BaseElement_vt__;

extern ILMachineType ILNode_BaseElement_ILNode_GetType__(ILNode_BaseElement *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseElement_ILNode_GenValue__(ILNode_BaseElement *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseElement_JavaGenValue__(ILNode_BaseElement *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseElement_ILNode_Prepare__(ILNode_BaseElement *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_BaseElement_ILNode_GetAndPrepare__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_BaseElement_ILNode_Store__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_BaseElement_ILNode_GenRef__(ILNode_BaseElement *node, ILGenInfo * info);
extern ILMachineType ILNode_BaseElement_JavaPrepare__(ILNode_BaseElement *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_BaseElement_JavaGetAndPrepare__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_BaseElement_JavaStore__(ILNode_BaseElement *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_AsIs__ {
	const struct ILNode_AsIs_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_AsIs_vtable__ {
	const struct ILNode_LValueNoRefUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_AsIs_vtable__ const ILNode_AsIs_vt__;

extern ILMachineType ILNode_AsIs_ILNode_GetType__(ILNode_AsIs *node, ILGenInfo * info);
extern ILMachineType ILNode_AsIs_ILNode_GenValue__(ILNode_AsIs *node, ILGenInfo * info);
extern void ILNode_AsIs_ILNode_GenThen__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_AsIs_ILNode_GenElse__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_AsIs_ILNode_EvalConst__(ILNode_AsIs *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_AsIs_JavaGenValue__(ILNode_AsIs *node, ILGenInfo * info);
extern void ILNode_AsIs_JavaGenThen__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_AsIs_JavaGenElse__(ILNode_AsIs *node, ILGenInfo * info, ILLabel * label);
extern ILMachineType ILNode_AsIs_ILNode_Prepare__(ILNode_AsIs *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_AsIs_ILNode_GetAndPrepare__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_AsIs_ILNode_Store__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_AsIs_JavaPrepare__(ILNode_AsIs *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_AsIs_JavaGetAndPrepare__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_AsIs_JavaStore__(ILNode_AsIs *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_Overflow__ {
	const struct ILNode_Overflow_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_Overflow_vtable__ {
	const struct ILNode_LValueNoRefUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_Overflow_vtable__ const ILNode_Overflow_vt__;

extern ILMachineType ILNode_Overflow_ILNode_GetType__(ILNode_Overflow *node, ILGenInfo * info);
extern void ILNode_Overflow_ILNode_GenDiscard__(ILNode_Overflow *node, ILGenInfo * info);
extern ILMachineType ILNode_Overflow_ILNode_GenValue__(ILNode_Overflow *node, ILGenInfo * info);
extern void ILNode_Overflow_ILNode_GenThen__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Overflow_ILNode_GenElse__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Overflow_ILNode_EvalConst__(ILNode_Overflow *node, ILGenInfo * info, ILEvalValue * value);
extern int ILNode_Overflow_ILNode_EndsInReturnImpl__(ILNode_Overflow *node, ILGenInfo * info);
extern void ILNode_Overflow_JavaGenDiscard__(ILNode_Overflow *node, ILGenInfo * info);
extern ILMachineType ILNode_Overflow_JavaGenValue__(ILNode_Overflow *node, ILGenInfo * info);
extern void ILNode_Overflow_JavaGenThen__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Overflow_JavaGenElse__(ILNode_Overflow *node, ILGenInfo * info, ILLabel * label);
extern ILMachineType ILNode_Overflow_ILNode_Prepare__(ILNode_Overflow *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_Overflow_ILNode_GetAndPrepare__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_Overflow_ILNode_Store__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_Overflow_JavaPrepare__(ILNode_Overflow *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_Overflow_JavaGetAndPrepare__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_Overflow_JavaStore__(ILNode_Overflow *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_NoOverflow__ {
	const struct ILNode_NoOverflow_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_NoOverflow_vtable__ {
	const struct ILNode_LValueNoRefUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_NoOverflow_vtable__ const ILNode_NoOverflow_vt__;

extern ILMachineType ILNode_NoOverflow_ILNode_GetType__(ILNode_NoOverflow *node, ILGenInfo * info);
extern void ILNode_NoOverflow_ILNode_GenDiscard__(ILNode_NoOverflow *node, ILGenInfo * info);
extern ILMachineType ILNode_NoOverflow_ILNode_GenValue__(ILNode_NoOverflow *node, ILGenInfo * info);
extern void ILNode_NoOverflow_ILNode_GenThen__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_NoOverflow_ILNode_GenElse__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_NoOverflow_ILNode_EvalConst__(ILNode_NoOverflow *node, ILGenInfo * info, ILEvalValue * value);
extern int ILNode_NoOverflow_ILNode_EndsInReturnImpl__(ILNode_NoOverflow *node, ILGenInfo * info);
extern void ILNode_NoOverflow_JavaGenDiscard__(ILNode_NoOverflow *node, ILGenInfo * info);
extern ILMachineType ILNode_NoOverflow_JavaGenValue__(ILNode_NoOverflow *node, ILGenInfo * info);
extern void ILNode_NoOverflow_JavaGenThen__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_NoOverflow_JavaGenElse__(ILNode_NoOverflow *node, ILGenInfo * info, ILLabel * label);
extern ILMachineType ILNode_NoOverflow_ILNode_Prepare__(ILNode_NoOverflow *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_NoOverflow_ILNode_GetAndPrepare__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_NoOverflow_ILNode_Store__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_NoOverflow_JavaPrepare__(ILNode_NoOverflow *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_NoOverflow_JavaGetAndPrepare__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_NoOverflow_JavaStore__(ILNode_NoOverflow *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_Pedantic__ {
	const struct ILNode_Pedantic_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_Pedantic_vtable__ {
	const struct ILNode_LValueNoRefUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_Pedantic_vtable__ const ILNode_Pedantic_vt__;

extern ILMachineType ILNode_Pedantic_ILNode_GetType__(ILNode_Pedantic *node, ILGenInfo * info);
extern void ILNode_Pedantic_ILNode_GenDiscard__(ILNode_Pedantic *node, ILGenInfo * info);
extern ILMachineType ILNode_Pedantic_ILNode_GenValue__(ILNode_Pedantic *node, ILGenInfo * info);
extern void ILNode_Pedantic_ILNode_GenThen__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Pedantic_ILNode_GenElse__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Pedantic_ILNode_EvalConst__(ILNode_Pedantic *node, ILGenInfo * info, ILEvalValue * value);
extern int ILNode_Pedantic_ILNode_EndsInReturnImpl__(ILNode_Pedantic *node, ILGenInfo * info);
extern void ILNode_Pedantic_JavaGenDiscard__(ILNode_Pedantic *node, ILGenInfo * info);
extern ILMachineType ILNode_Pedantic_JavaGenValue__(ILNode_Pedantic *node, ILGenInfo * info);
extern void ILNode_Pedantic_JavaGenThen__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Pedantic_JavaGenElse__(ILNode_Pedantic *node, ILGenInfo * info, ILLabel * label);
extern ILMachineType ILNode_Pedantic_ILNode_Prepare__(ILNode_Pedantic *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_Pedantic_ILNode_GetAndPrepare__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_Pedantic_ILNode_Store__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_Pedantic_JavaPrepare__(ILNode_Pedantic *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_Pedantic_JavaGetAndPrepare__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_Pedantic_JavaStore__(ILNode_Pedantic *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_NoPedantic__ {
	const struct ILNode_NoPedantic_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_NoPedantic_vtable__ {
	const struct ILNode_LValueNoRefUnaryExpr_vtable__ *parent__;
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

extern struct ILNode_NoPedantic_vtable__ const ILNode_NoPedantic_vt__;

extern ILMachineType ILNode_NoPedantic_ILNode_GetType__(ILNode_NoPedantic *node, ILGenInfo * info);
extern void ILNode_NoPedantic_ILNode_GenDiscard__(ILNode_NoPedantic *node, ILGenInfo * info);
extern ILMachineType ILNode_NoPedantic_ILNode_GenValue__(ILNode_NoPedantic *node, ILGenInfo * info);
extern void ILNode_NoPedantic_ILNode_GenThen__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_NoPedantic_ILNode_GenElse__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_NoPedantic_ILNode_EvalConst__(ILNode_NoPedantic *node, ILGenInfo * info, ILEvalValue * value);
extern int ILNode_NoPedantic_ILNode_EndsInReturnImpl__(ILNode_NoPedantic *node, ILGenInfo * info);
extern void ILNode_NoPedantic_JavaGenDiscard__(ILNode_NoPedantic *node, ILGenInfo * info);
extern ILMachineType ILNode_NoPedantic_JavaGenValue__(ILNode_NoPedantic *node, ILGenInfo * info);
extern void ILNode_NoPedantic_JavaGenThen__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_NoPedantic_JavaGenElse__(ILNode_NoPedantic *node, ILGenInfo * info, ILLabel * label);
extern ILMachineType ILNode_NoPedantic_ILNode_Prepare__(ILNode_NoPedantic *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_NoPedantic_ILNode_GetAndPrepare__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_NoPedantic_ILNode_Store__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern ILMachineType ILNode_NoPedantic_JavaPrepare__(ILNode_NoPedantic *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_NoPedantic_JavaGetAndPrepare__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_NoPedantic_JavaStore__(ILNode_NoPedantic *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_MarkType__ {
	const struct ILNode_MarkType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
};

struct ILNode_MarkType_vtable__ {
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

extern struct ILNode_MarkType_vtable__ const ILNode_MarkType_vt__;

struct ILNode_MemberAccess__ {
	const struct ILNode_MemberAccess_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILMachineType machineType;
};

struct ILNode_MemberAccess_vtable__ {
	const struct ILNode_LValueBinaryExpr_vtable__ *parent__;
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

extern struct ILNode_MemberAccess_vtable__ const ILNode_MemberAccess_vt__;

extern ILMachineType ILNode_MemberAccess_ILNode_GetType__(ILNode_MemberAccess *node, ILGenInfo * info);
extern void ILNode_MemberAccess_ILNode_GenDiscard__(ILNode_MemberAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberAccess_ILNode_GenValue__(ILNode_MemberAccess *node, ILGenInfo * info);
extern void ILNode_MemberAccess_JavaGenDiscard__(ILNode_MemberAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberAccess_JavaGenValue__(ILNode_MemberAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberAccess_ILNode_Prepare__(ILNode_MemberAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_MemberAccess_ILNode_GetAndPrepare__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_MemberAccess_ILNode_Store__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_MemberAccess_ILNode_GenRef__(ILNode_MemberAccess *node, ILGenInfo * info);
extern ILMachineType ILNode_MemberAccess_JavaPrepare__(ILNode_MemberAccess *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_MemberAccess_JavaGetAndPrepare__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_MemberAccess_JavaStore__(ILNode_MemberAccess *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_DerefField__ {
	const struct ILNode_DerefField_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILMachineType machineType;
	ILField * field;
	ILUInt32 tempVar;
};

struct ILNode_DerefField_vtable__ {
	const struct ILNode_LValueBinaryExpr_vtable__ *parent__;
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

extern struct ILNode_DerefField_vtable__ const ILNode_DerefField_vt__;

extern ILMachineType ILNode_DerefField_ILNode_GetType__(ILNode_DerefField *node, ILGenInfo * info);
extern void ILNode_DerefField_ILNode_GenDiscard__(ILNode_DerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_DerefField_ILNode_GenValue__(ILNode_DerefField *node, ILGenInfo * info);
extern void ILNode_DerefField_JavaGenDiscard__(ILNode_DerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_DerefField_JavaGenValue__(ILNode_DerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_DerefField_ILNode_Prepare__(ILNode_DerefField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_DerefField_ILNode_GetAndPrepare__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_DerefField_ILNode_Store__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * data1, void * data2);
extern void ILNode_DerefField_ILNode_GenRef__(ILNode_DerefField *node, ILGenInfo * info);
extern ILMachineType ILNode_DerefField_JavaPrepare__(ILNode_DerefField *node, ILGenInfo * info, void * * data1, void * * data2);
extern ILMachineType ILNode_DerefField_JavaGetAndPrepare__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * * data1, void * * data2);
extern void ILNode_DerefField_JavaStore__(ILNode_DerefField *node, ILGenInfo * info, int leave, void * data1, void * data2);

struct ILNode_DummyUnaryExpr__ {
	const struct ILNode_DummyUnaryExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_DummyUnaryExpr_vtable__ {
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

extern struct ILNode_DummyUnaryExpr_vtable__ const ILNode_DummyUnaryExpr_vt__;

extern ILMachineType ILNode_DummyUnaryExpr_ILNode_GetType__(ILNode_DummyUnaryExpr *node, ILGenInfo * info);
extern ILMachineType ILNode_DummyUnaryExpr_ILNode_GenValue__(ILNode_DummyUnaryExpr *node, ILGenInfo * info);
extern ILMachineType ILNode_DummyUnaryExpr_JavaGenValue__(ILNode_DummyUnaryExpr *node, ILGenInfo * info);

struct ILNode_LogicalNot__ {
	const struct ILNode_LogicalNot_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_LogicalNot_vtable__ {
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

extern struct ILNode_LogicalNot_vtable__ const ILNode_LogicalNot_vt__;

extern ILMachineType ILNode_LogicalNot_ILNode_GetType__(ILNode_LogicalNot *node, ILGenInfo * info);
extern void ILNode_LogicalNot_ILNode_GenDiscard__(ILNode_LogicalNot *node, ILGenInfo * info);
extern ILMachineType ILNode_LogicalNot_ILNode_GenValue__(ILNode_LogicalNot *node, ILGenInfo * info);
extern void ILNode_LogicalNot_ILNode_GenThen__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_LogicalNot_ILNode_GenElse__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_LogicalNot_ILNode_EvalConst__(ILNode_LogicalNot *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_LogicalNot_JavaGenDiscard__(ILNode_LogicalNot *node, ILGenInfo * info);
extern ILMachineType ILNode_LogicalNot_JavaGenValue__(ILNode_LogicalNot *node, ILGenInfo * info);
extern void ILNode_LogicalNot_JavaGenThen__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_LogicalNot_JavaGenElse__(ILNode_LogicalNot *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Neg__ {
	const struct ILNode_Neg_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_Neg_vtable__ {
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

extern struct ILNode_Neg_vtable__ const ILNode_Neg_vt__;

extern ILMachineType ILNode_Neg_ILNode_GetType__(ILNode_Neg *node, ILGenInfo * info);
extern void ILNode_Neg_ILNode_GenDiscard__(ILNode_Neg *node, ILGenInfo * info);
extern ILMachineType ILNode_Neg_ILNode_GenValue__(ILNode_Neg *node, ILGenInfo * info);
extern int ILNode_Neg_ILNode_EvalConst__(ILNode_Neg *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Neg_JavaGenDiscard__(ILNode_Neg *node, ILGenInfo * info);
extern ILMachineType ILNode_Neg_JavaGenValue__(ILNode_Neg *node, ILGenInfo * info);

struct ILNode_UnaryPlus__ {
	const struct ILNode_UnaryPlus_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_UnaryPlus_vtable__ {
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

extern struct ILNode_UnaryPlus_vtable__ const ILNode_UnaryPlus_vt__;

extern ILMachineType ILNode_UnaryPlus_ILNode_GetType__(ILNode_UnaryPlus *node, ILGenInfo * info);
extern void ILNode_UnaryPlus_ILNode_GenDiscard__(ILNode_UnaryPlus *node, ILGenInfo * info);
extern ILMachineType ILNode_UnaryPlus_ILNode_GenValue__(ILNode_UnaryPlus *node, ILGenInfo * info);
extern int ILNode_UnaryPlus_ILNode_EvalConst__(ILNode_UnaryPlus *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_UnaryPlus_JavaGenDiscard__(ILNode_UnaryPlus *node, ILGenInfo * info);
extern ILMachineType ILNode_UnaryPlus_JavaGenValue__(ILNode_UnaryPlus *node, ILGenInfo * info);

struct ILNode_Not__ {
	const struct ILNode_Not_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_Not_vtable__ {
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

extern struct ILNode_Not_vtable__ const ILNode_Not_vt__;

extern ILMachineType ILNode_Not_ILNode_GetType__(ILNode_Not *node, ILGenInfo * info);
extern void ILNode_Not_ILNode_GenDiscard__(ILNode_Not *node, ILGenInfo * info);
extern ILMachineType ILNode_Not_ILNode_GenValue__(ILNode_Not *node, ILGenInfo * info);
extern int ILNode_Not_ILNode_EvalConst__(ILNode_Not *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Not_JavaGenDiscard__(ILNode_Not *node, ILGenInfo * info);
extern ILMachineType ILNode_Not_JavaGenValue__(ILNode_Not *node, ILGenInfo * info);

struct ILNode_UserUnaryOp__ {
	const struct ILNode_UserUnaryOp_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMachineType machineType;
	ILMethod * method;
};

struct ILNode_UserUnaryOp_vtable__ {
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

extern struct ILNode_UserUnaryOp_vtable__ const ILNode_UserUnaryOp_vt__;

extern ILMachineType ILNode_UserUnaryOp_ILNode_GetType__(ILNode_UserUnaryOp *node, ILGenInfo * info);
extern void ILNode_UserUnaryOp_ILNode_GenDiscard__(ILNode_UserUnaryOp *node, ILGenInfo * info);
extern ILMachineType ILNode_UserUnaryOp_ILNode_GenValue__(ILNode_UserUnaryOp *node, ILGenInfo * info);
extern void ILNode_UserUnaryOp_JavaGenDiscard__(ILNode_UserUnaryOp *node, ILGenInfo * info);
extern ILMachineType ILNode_UserUnaryOp_JavaGenValue__(ILNode_UserUnaryOp *node, ILGenInfo * info);

struct ILNode_PreInc__ {
	const struct ILNode_PreInc_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_PreInc_vtable__ {
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

extern struct ILNode_PreInc_vtable__ const ILNode_PreInc_vt__;

extern ILMachineType ILNode_PreInc_ILNode_GetType__(ILNode_PreInc *node, ILGenInfo * info);
extern void ILNode_PreInc_ILNode_GenDiscard__(ILNode_PreInc *node, ILGenInfo * info);
extern ILMachineType ILNode_PreInc_ILNode_GenValue__(ILNode_PreInc *node, ILGenInfo * info);
extern void ILNode_PreInc_JavaGenDiscard__(ILNode_PreInc *node, ILGenInfo * info);
extern ILMachineType ILNode_PreInc_JavaGenValue__(ILNode_PreInc *node, ILGenInfo * info);

struct ILNode_PreDec__ {
	const struct ILNode_PreDec_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_PreDec_vtable__ {
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

extern struct ILNode_PreDec_vtable__ const ILNode_PreDec_vt__;

extern ILMachineType ILNode_PreDec_ILNode_GetType__(ILNode_PreDec *node, ILGenInfo * info);
extern void ILNode_PreDec_ILNode_GenDiscard__(ILNode_PreDec *node, ILGenInfo * info);
extern ILMachineType ILNode_PreDec_ILNode_GenValue__(ILNode_PreDec *node, ILGenInfo * info);
extern void ILNode_PreDec_JavaGenDiscard__(ILNode_PreDec *node, ILGenInfo * info);
extern ILMachineType ILNode_PreDec_JavaGenValue__(ILNode_PreDec *node, ILGenInfo * info);

struct ILNode_PostInc__ {
	const struct ILNode_PostInc_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_PostInc_vtable__ {
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

extern struct ILNode_PostInc_vtable__ const ILNode_PostInc_vt__;

extern ILMachineType ILNode_PostInc_ILNode_GetType__(ILNode_PostInc *node, ILGenInfo * info);
extern void ILNode_PostInc_ILNode_GenDiscard__(ILNode_PostInc *node, ILGenInfo * info);
extern ILMachineType ILNode_PostInc_ILNode_GenValue__(ILNode_PostInc *node, ILGenInfo * info);
extern void ILNode_PostInc_JavaGenDiscard__(ILNode_PostInc *node, ILGenInfo * info);
extern ILMachineType ILNode_PostInc_JavaGenValue__(ILNode_PostInc *node, ILGenInfo * info);

struct ILNode_PostDec__ {
	const struct ILNode_PostDec_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_PostDec_vtable__ {
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

extern struct ILNode_PostDec_vtable__ const ILNode_PostDec_vt__;

extern ILMachineType ILNode_PostDec_ILNode_GetType__(ILNode_PostDec *node, ILGenInfo * info);
extern void ILNode_PostDec_ILNode_GenDiscard__(ILNode_PostDec *node, ILGenInfo * info);
extern ILMachineType ILNode_PostDec_ILNode_GenValue__(ILNode_PostDec *node, ILGenInfo * info);
extern void ILNode_PostDec_JavaGenDiscard__(ILNode_PostDec *node, ILGenInfo * info);
extern ILMachineType ILNode_PostDec_JavaGenValue__(ILNode_PostDec *node, ILGenInfo * info);

struct ILNode_UserIncOrDec__ {
	const struct ILNode_UserIncOrDec_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMethod * method;
	ILMachineType type;
};

struct ILNode_UserIncOrDec_vtable__ {
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

extern struct ILNode_UserIncOrDec_vtable__ const ILNode_UserIncOrDec_vt__;

struct ILNode_IncOrDecPtr__ {
	const struct ILNode_IncOrDecPtr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILUInt32 size;
	ILNode * sizeNode;
};

struct ILNode_IncOrDecPtr_vtable__ {
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

extern struct ILNode_IncOrDecPtr_vtable__ const ILNode_IncOrDecPtr_vt__;

struct ILNode_CastSimple__ {
	const struct ILNode_CastSimple_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMachineType machineType;
};

struct ILNode_CastSimple_vtable__ {
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

extern struct ILNode_CastSimple_vtable__ const ILNode_CastSimple_vt__;

extern ILMachineType ILNode_CastSimple_ILNode_GetType__(ILNode_CastSimple *node, ILGenInfo * info);
extern ILMachineType ILNode_CastSimple_ILNode_GenValue__(ILNode_CastSimple *node, ILGenInfo * info);
extern int ILNode_CastSimple_ILNode_EvalConst__(ILNode_CastSimple *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_CastSimple_JavaGenValue__(ILNode_CastSimple *node, ILGenInfo * info);

struct ILNode_CastType__ {
	const struct ILNode_CastType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
};

struct ILNode_CastType_vtable__ {
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

extern struct ILNode_CastType_vtable__ const ILNode_CastType_vt__;

extern ILMachineType ILNode_CastType_ILNode_GetType__(ILNode_CastType *node, ILGenInfo * info);
extern ILMachineType ILNode_CastType_ILNode_GenValue__(ILNode_CastType *node, ILGenInfo * info);
extern ILMachineType ILNode_CastType_JavaGenValue__(ILNode_CastType *node, ILGenInfo * info);

struct ILNode_UserConversion__ {
	const struct ILNode_UserConversion_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMachineType machineType;
	ILMethod * method;
};

struct ILNode_UserConversion_vtable__ {
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

extern struct ILNode_UserConversion_vtable__ const ILNode_UserConversion_vt__;

extern ILMachineType ILNode_UserConversion_ILNode_GetType__(ILNode_UserConversion *node, ILGenInfo * info);
extern ILMachineType ILNode_UserConversion_ILNode_GenValue__(ILNode_UserConversion *node, ILGenInfo * info);
extern ILMachineType ILNode_UserConversion_JavaGenValue__(ILNode_UserConversion *node, ILGenInfo * info);

struct ILNode_AddressOf__ {
	const struct ILNode_AddressOf_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_AddressOf_vtable__ {
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

extern struct ILNode_AddressOf_vtable__ const ILNode_AddressOf_vt__;

extern ILMachineType ILNode_AddressOf_ILNode_GetType__(ILNode_AddressOf *node, ILGenInfo * info);
extern void ILNode_AddressOf_ILNode_GenDiscard__(ILNode_AddressOf *node, ILGenInfo * info);
extern ILMachineType ILNode_AddressOf_ILNode_GenValue__(ILNode_AddressOf *node, ILGenInfo * info);
extern void ILNode_AddressOf_JavaGenDiscard__(ILNode_AddressOf *node, ILGenInfo * info);
extern ILMachineType ILNode_AddressOf_JavaGenValue__(ILNode_AddressOf *node, ILGenInfo * info);

struct ILNode_ToBool__ {
	const struct ILNode_ToBool_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMethod * trueMethod;
	ILMethod * falseMethod;
};

struct ILNode_ToBool_vtable__ {
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

extern struct ILNode_ToBool_vtable__ const ILNode_ToBool_vt__;

extern ILMachineType ILNode_ToBool_ILNode_GetType__(ILNode_ToBool *node, ILGenInfo * info);
extern ILMachineType ILNode_ToBool_ILNode_GenValue__(ILNode_ToBool *node, ILGenInfo * info);
extern void ILNode_ToBool_ILNode_GenThen__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_ToBool_ILNode_GenElse__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_ToBool_ILNode_EvalConst__(ILNode_ToBool *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_ToBool_JavaGenValue__(ILNode_ToBool *node, ILGenInfo * info);
extern void ILNode_ToBool_JavaGenThen__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_ToBool_JavaGenElse__(ILNode_ToBool *node, ILGenInfo * info, ILLabel * label);

struct ILNode_ToConst__ {
	const struct ILNode_ToConst_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_ToConst_vtable__ {
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

extern struct ILNode_ToConst_vtable__ const ILNode_ToConst_vt__;

extern ILMachineType ILNode_ToConst_ILNode_GetType__(ILNode_ToConst *node, ILGenInfo * info);
extern ILMachineType ILNode_ToConst_ILNode_GenValue__(ILNode_ToConst *node, ILGenInfo * info);
extern void ILNode_ToConst_ILNode_GenThen__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_ToConst_ILNode_GenElse__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_ToConst_ILNode_EvalConst__(ILNode_ToConst *node, ILGenInfo * info, ILEvalValue * value);
extern ILMachineType ILNode_ToConst_JavaGenValue__(ILNode_ToConst *node, ILGenInfo * info);
extern void ILNode_ToConst_JavaGenThen__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_ToConst_JavaGenElse__(ILNode_ToConst *node, ILGenInfo * info, ILLabel * label);

struct ILNode_VarArgExpand__ {
	const struct ILNode_VarArgExpand_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * varArgTypes;
};

struct ILNode_VarArgExpand_vtable__ {
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

extern struct ILNode_VarArgExpand_vtable__ const ILNode_VarArgExpand_vt__;

extern ILMachineType ILNode_VarArgExpand_ILNode_GetType__(ILNode_VarArgExpand *node, ILGenInfo * info);
extern ILMachineType ILNode_VarArgExpand_ILNode_GenValue__(ILNode_VarArgExpand *node, ILGenInfo * info);
extern ILMachineType ILNode_VarArgExpand_JavaGenValue__(ILNode_VarArgExpand *node, ILGenInfo * info);

struct ILNode_IsNull__ {
	const struct ILNode_IsNull_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_IsNull_vtable__ {
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

extern struct ILNode_IsNull_vtable__ const ILNode_IsNull_vt__;

extern ILMachineType ILNode_IsNull_ILNode_GetType__(ILNode_IsNull *node, ILGenInfo * info);
extern void ILNode_IsNull_ILNode_GenDiscard__(ILNode_IsNull *node, ILGenInfo * info);
extern ILMachineType ILNode_IsNull_ILNode_GenValue__(ILNode_IsNull *node, ILGenInfo * info);
extern void ILNode_IsNull_ILNode_GenThen__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_IsNull_ILNode_GenElse__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_IsNull_JavaGenDiscard__(ILNode_IsNull *node, ILGenInfo * info);
extern ILMachineType ILNode_IsNull_JavaGenValue__(ILNode_IsNull *node, ILGenInfo * info);
extern void ILNode_IsNull_JavaGenThen__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_IsNull_JavaGenElse__(ILNode_IsNull *node, ILGenInfo * info, ILLabel * label);

struct ILNode_IsNonNull__ {
	const struct ILNode_IsNonNull_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_IsNonNull_vtable__ {
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

extern struct ILNode_IsNonNull_vtable__ const ILNode_IsNonNull_vt__;

extern ILMachineType ILNode_IsNonNull_ILNode_GetType__(ILNode_IsNonNull *node, ILGenInfo * info);
extern void ILNode_IsNonNull_ILNode_GenDiscard__(ILNode_IsNonNull *node, ILGenInfo * info);
extern ILMachineType ILNode_IsNonNull_ILNode_GenValue__(ILNode_IsNonNull *node, ILGenInfo * info);
extern void ILNode_IsNonNull_ILNode_GenThen__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_IsNonNull_ILNode_GenElse__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_IsNonNull_JavaGenDiscard__(ILNode_IsNonNull *node, ILGenInfo * info);
extern ILMachineType ILNode_IsNonNull_JavaGenValue__(ILNode_IsNonNull *node, ILGenInfo * info);
extern void ILNode_IsNonNull_JavaGenThen__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_IsNonNull_JavaGenElse__(ILNode_IsNonNull *node, ILGenInfo * info, ILLabel * label);

struct ILNode_MakeRefAny__ {
	const struct ILNode_MakeRefAny_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * type;
};

struct ILNode_MakeRefAny_vtable__ {
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

extern struct ILNode_MakeRefAny_vtable__ const ILNode_MakeRefAny_vt__;

extern ILMachineType ILNode_MakeRefAny_ILNode_GetType__(ILNode_MakeRefAny *node, ILGenInfo * info);
extern ILMachineType ILNode_MakeRefAny_ILNode_GenValue__(ILNode_MakeRefAny *node, ILGenInfo * info);
extern ILMachineType ILNode_MakeRefAny_JavaGenValue__(ILNode_MakeRefAny *node, ILGenInfo * info);

struct ILNode_RefType__ {
	const struct ILNode_RefType_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_RefType_vtable__ {
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

extern struct ILNode_RefType_vtable__ const ILNode_RefType_vt__;

extern ILMachineType ILNode_RefType_ILNode_GetType__(ILNode_RefType *node, ILGenInfo * info);
extern ILMachineType ILNode_RefType_ILNode_GenValue__(ILNode_RefType *node, ILGenInfo * info);
extern ILMachineType ILNode_RefType_JavaGenValue__(ILNode_RefType *node, ILGenInfo * info);

struct ILNode_ArrayLength__ {
	const struct ILNode_ArrayLength_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
};

struct ILNode_ArrayLength_vtable__ {
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

extern struct ILNode_ArrayLength_vtable__ const ILNode_ArrayLength_vt__;

extern ILMachineType ILNode_ArrayLength_ILNode_GetType__(ILNode_ArrayLength *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayLength_ILNode_GenValue__(ILNode_ArrayLength *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayLength_JavaGenValue__(ILNode_ArrayLength *node, ILGenInfo * info);

struct ILNode_ArrayInit__ {
	const struct ILNode_ArrayInit_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILType * arrayType;
};

struct ILNode_ArrayInit_vtable__ {
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

extern struct ILNode_ArrayInit_vtable__ const ILNode_ArrayInit_vt__;

extern ILMachineType ILNode_ArrayInit_ILNode_GetType__(ILNode_ArrayInit *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayInit_ILNode_GenValue__(ILNode_ArrayInit *node, ILGenInfo * info);
extern ILMachineType ILNode_ArrayInit_JavaGenValue__(ILNode_ArrayInit *node, ILGenInfo * info);

struct ILNode_UserPreInc__ {
	const struct ILNode_UserPreInc_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMethod * method;
	ILMachineType type;
};

struct ILNode_UserPreInc_vtable__ {
	const struct ILNode_UserIncOrDec_vtable__ *parent__;
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

extern struct ILNode_UserPreInc_vtable__ const ILNode_UserPreInc_vt__;

extern ILMachineType ILNode_UserPreInc_ILNode_GetType__(ILNode_UserPreInc *node, ILGenInfo * info);
extern void ILNode_UserPreInc_ILNode_GenDiscard__(ILNode_UserPreInc *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPreInc_ILNode_GenValue__(ILNode_UserPreInc *node, ILGenInfo * info);
extern void ILNode_UserPreInc_JavaGenDiscard__(ILNode_UserPreInc *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPreInc_JavaGenValue__(ILNode_UserPreInc *node, ILGenInfo * info);

struct ILNode_UserPreDec__ {
	const struct ILNode_UserPreDec_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMethod * method;
	ILMachineType type;
};

struct ILNode_UserPreDec_vtable__ {
	const struct ILNode_UserIncOrDec_vtable__ *parent__;
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

extern struct ILNode_UserPreDec_vtable__ const ILNode_UserPreDec_vt__;

extern ILMachineType ILNode_UserPreDec_ILNode_GetType__(ILNode_UserPreDec *node, ILGenInfo * info);
extern void ILNode_UserPreDec_ILNode_GenDiscard__(ILNode_UserPreDec *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPreDec_ILNode_GenValue__(ILNode_UserPreDec *node, ILGenInfo * info);
extern void ILNode_UserPreDec_JavaGenDiscard__(ILNode_UserPreDec *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPreDec_JavaGenValue__(ILNode_UserPreDec *node, ILGenInfo * info);

struct ILNode_UserPostInc__ {
	const struct ILNode_UserPostInc_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMethod * method;
	ILMachineType type;
};

struct ILNode_UserPostInc_vtable__ {
	const struct ILNode_UserIncOrDec_vtable__ *parent__;
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

extern struct ILNode_UserPostInc_vtable__ const ILNode_UserPostInc_vt__;

extern ILMachineType ILNode_UserPostInc_ILNode_GetType__(ILNode_UserPostInc *node, ILGenInfo * info);
extern void ILNode_UserPostInc_ILNode_GenDiscard__(ILNode_UserPostInc *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPostInc_ILNode_GenValue__(ILNode_UserPostInc *node, ILGenInfo * info);
extern void ILNode_UserPostInc_JavaGenDiscard__(ILNode_UserPostInc *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPostInc_JavaGenValue__(ILNode_UserPostInc *node, ILGenInfo * info);

struct ILNode_UserPostDec__ {
	const struct ILNode_UserPostDec_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILMethod * method;
	ILMachineType type;
};

struct ILNode_UserPostDec_vtable__ {
	const struct ILNode_UserIncOrDec_vtable__ *parent__;
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

extern struct ILNode_UserPostDec_vtable__ const ILNode_UserPostDec_vt__;

extern ILMachineType ILNode_UserPostDec_ILNode_GetType__(ILNode_UserPostDec *node, ILGenInfo * info);
extern void ILNode_UserPostDec_ILNode_GenDiscard__(ILNode_UserPostDec *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPostDec_ILNode_GenValue__(ILNode_UserPostDec *node, ILGenInfo * info);
extern void ILNode_UserPostDec_JavaGenDiscard__(ILNode_UserPostDec *node, ILGenInfo * info);
extern ILMachineType ILNode_UserPostDec_JavaGenValue__(ILNode_UserPostDec *node, ILGenInfo * info);

struct ILNode_PreIncPtr__ {
	const struct ILNode_PreIncPtr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILUInt32 size;
	ILNode * sizeNode;
};

struct ILNode_PreIncPtr_vtable__ {
	const struct ILNode_IncOrDecPtr_vtable__ *parent__;
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

extern struct ILNode_PreIncPtr_vtable__ const ILNode_PreIncPtr_vt__;

extern ILMachineType ILNode_PreIncPtr_ILNode_GetType__(ILNode_PreIncPtr *node, ILGenInfo * info);
extern void ILNode_PreIncPtr_ILNode_GenDiscard__(ILNode_PreIncPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PreIncPtr_ILNode_GenValue__(ILNode_PreIncPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PreIncPtr_JavaGenValue__(ILNode_PreIncPtr *node, ILGenInfo * info);

struct ILNode_PreDecPtr__ {
	const struct ILNode_PreDecPtr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILUInt32 size;
	ILNode * sizeNode;
};

struct ILNode_PreDecPtr_vtable__ {
	const struct ILNode_IncOrDecPtr_vtable__ *parent__;
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

extern struct ILNode_PreDecPtr_vtable__ const ILNode_PreDecPtr_vt__;

extern ILMachineType ILNode_PreDecPtr_ILNode_GetType__(ILNode_PreDecPtr *node, ILGenInfo * info);
extern void ILNode_PreDecPtr_ILNode_GenDiscard__(ILNode_PreDecPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PreDecPtr_ILNode_GenValue__(ILNode_PreDecPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PreDecPtr_JavaGenValue__(ILNode_PreDecPtr *node, ILGenInfo * info);

struct ILNode_PostIncPtr__ {
	const struct ILNode_PostIncPtr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILUInt32 size;
	ILNode * sizeNode;
};

struct ILNode_PostIncPtr_vtable__ {
	const struct ILNode_IncOrDecPtr_vtable__ *parent__;
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

extern struct ILNode_PostIncPtr_vtable__ const ILNode_PostIncPtr_vt__;

extern ILMachineType ILNode_PostIncPtr_ILNode_GetType__(ILNode_PostIncPtr *node, ILGenInfo * info);
extern void ILNode_PostIncPtr_ILNode_GenDiscard__(ILNode_PostIncPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PostIncPtr_ILNode_GenValue__(ILNode_PostIncPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PostIncPtr_JavaGenValue__(ILNode_PostIncPtr *node, ILGenInfo * info);

struct ILNode_PostDecPtr__ {
	const struct ILNode_PostDecPtr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILUInt32 size;
	ILNode * sizeNode;
};

struct ILNode_PostDecPtr_vtable__ {
	const struct ILNode_IncOrDecPtr_vtable__ *parent__;
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

extern struct ILNode_PostDecPtr_vtable__ const ILNode_PostDecPtr_vt__;

extern ILMachineType ILNode_PostDecPtr_ILNode_GetType__(ILNode_PostDecPtr *node, ILGenInfo * info);
extern void ILNode_PostDecPtr_ILNode_GenDiscard__(ILNode_PostDecPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PostDecPtr_ILNode_GenValue__(ILNode_PostDecPtr *node, ILGenInfo * info);
extern ILMachineType ILNode_PostDecPtr_JavaGenValue__(ILNode_PostDecPtr *node, ILGenInfo * info);

struct ILNode_DummyBinaryExpr__ {
	const struct ILNode_DummyBinaryExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_DummyBinaryExpr_vtable__ {
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

extern struct ILNode_DummyBinaryExpr_vtable__ const ILNode_DummyBinaryExpr_vt__;

extern ILMachineType ILNode_DummyBinaryExpr_ILNode_GetType__(ILNode_DummyBinaryExpr *node, ILGenInfo * info);
extern ILMachineType ILNode_DummyBinaryExpr_ILNode_GenValue__(ILNode_DummyBinaryExpr *node, ILGenInfo * info);
extern ILMachineType ILNode_DummyBinaryExpr_JavaGenValue__(ILNode_DummyBinaryExpr *node, ILGenInfo * info);

struct ILNode_LogicalAnd__ {
	const struct ILNode_LogicalAnd_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_LogicalAnd_vtable__ {
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

extern struct ILNode_LogicalAnd_vtable__ const ILNode_LogicalAnd_vt__;

extern ILMachineType ILNode_LogicalAnd_ILNode_GetType__(ILNode_LogicalAnd *node, ILGenInfo * info);
extern void ILNode_LogicalAnd_ILNode_GenDiscard__(ILNode_LogicalAnd *node, ILGenInfo * info);
extern ILMachineType ILNode_LogicalAnd_ILNode_GenValue__(ILNode_LogicalAnd *node, ILGenInfo * info);
extern void ILNode_LogicalAnd_ILNode_GenThen__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_LogicalAnd_ILNode_GenElse__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_LogicalAnd_ILNode_EvalConst__(ILNode_LogicalAnd *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_LogicalAnd_JavaGenDiscard__(ILNode_LogicalAnd *node, ILGenInfo * info);
extern ILMachineType ILNode_LogicalAnd_JavaGenValue__(ILNode_LogicalAnd *node, ILGenInfo * info);
extern void ILNode_LogicalAnd_JavaGenThen__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_LogicalAnd_JavaGenElse__(ILNode_LogicalAnd *node, ILGenInfo * info, ILLabel * label);

struct ILNode_LogicalOr__ {
	const struct ILNode_LogicalOr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_LogicalOr_vtable__ {
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

extern struct ILNode_LogicalOr_vtable__ const ILNode_LogicalOr_vt__;

extern ILMachineType ILNode_LogicalOr_ILNode_GetType__(ILNode_LogicalOr *node, ILGenInfo * info);
extern void ILNode_LogicalOr_ILNode_GenDiscard__(ILNode_LogicalOr *node, ILGenInfo * info);
extern ILMachineType ILNode_LogicalOr_ILNode_GenValue__(ILNode_LogicalOr *node, ILGenInfo * info);
extern void ILNode_LogicalOr_ILNode_GenThen__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_LogicalOr_ILNode_GenElse__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_LogicalOr_ILNode_EvalConst__(ILNode_LogicalOr *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_LogicalOr_JavaGenDiscard__(ILNode_LogicalOr *node, ILGenInfo * info);
extern ILMachineType ILNode_LogicalOr_JavaGenValue__(ILNode_LogicalOr *node, ILGenInfo * info);
extern void ILNode_LogicalOr_JavaGenThen__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_LogicalOr_JavaGenElse__(ILNode_LogicalOr *node, ILGenInfo * info, ILLabel * label);

struct ILNode_UserLogical__ {
	const struct ILNode_UserLogical_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILMethod * opMethod;
	ILMethod * trueMethod;
	ILMethod * falseMethod;
};

struct ILNode_UserLogical_vtable__ {
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

extern struct ILNode_UserLogical_vtable__ const ILNode_UserLogical_vt__;

struct ILNode_BinaryArith__ {
	const struct ILNode_BinaryArith_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_BinaryArith_vtable__ {
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

extern struct ILNode_BinaryArith_vtable__ const ILNode_BinaryArith_vt__;

extern ILMachineType ILNode_BinaryArith_ILNode_GetType__(ILNode_BinaryArith *node, ILGenInfo * info);
extern void ILNode_BinaryArith_ILNode_GenDiscard__(ILNode_BinaryArith *node, ILGenInfo * info);
extern ILMachineType ILNode_BinaryArith_ILNode_GenValue__(ILNode_BinaryArith *node, ILGenInfo * info);
extern int ILNode_BinaryArith_ILNode_EvalConst__(ILNode_BinaryArith *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_BinaryArith_JavaGenDiscard__(ILNode_BinaryArith *node, ILGenInfo * info);
extern ILMachineType ILNode_BinaryArith_JavaGenValue__(ILNode_BinaryArith *node, ILGenInfo * info);

struct ILNode_BinaryBitwise__ {
	const struct ILNode_BinaryBitwise_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_BinaryBitwise_vtable__ {
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

extern struct ILNode_BinaryBitwise_vtable__ const ILNode_BinaryBitwise_vt__;

extern ILMachineType ILNode_BinaryBitwise_ILNode_GetType__(ILNode_BinaryBitwise *node, ILGenInfo * info);
extern void ILNode_BinaryBitwise_ILNode_GenDiscard__(ILNode_BinaryBitwise *node, ILGenInfo * info);
extern ILMachineType ILNode_BinaryBitwise_ILNode_GenValue__(ILNode_BinaryBitwise *node, ILGenInfo * info);
extern int ILNode_BinaryBitwise_ILNode_EvalConst__(ILNode_BinaryBitwise *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_BinaryBitwise_JavaGenDiscard__(ILNode_BinaryBitwise *node, ILGenInfo * info);
extern ILMachineType ILNode_BinaryBitwise_JavaGenValue__(ILNode_BinaryBitwise *node, ILGenInfo * info);

struct ILNode_BinaryShift__ {
	const struct ILNode_BinaryShift_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_BinaryShift_vtable__ {
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

extern struct ILNode_BinaryShift_vtable__ const ILNode_BinaryShift_vt__;

extern ILMachineType ILNode_BinaryShift_ILNode_GetType__(ILNode_BinaryShift *node, ILGenInfo * info);
extern void ILNode_BinaryShift_ILNode_GenDiscard__(ILNode_BinaryShift *node, ILGenInfo * info);
extern ILMachineType ILNode_BinaryShift_ILNode_GenValue__(ILNode_BinaryShift *node, ILGenInfo * info);
extern int ILNode_BinaryShift_ILNode_EvalConst__(ILNode_BinaryShift *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_BinaryShift_JavaGenDiscard__(ILNode_BinaryShift *node, ILGenInfo * info);
extern ILMachineType ILNode_BinaryShift_JavaGenValue__(ILNode_BinaryShift *node, ILGenInfo * info);

struct ILNode_UserBinaryOp__ {
	const struct ILNode_UserBinaryOp_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILMachineType machineType;
	ILMethod * method;
};

struct ILNode_UserBinaryOp_vtable__ {
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

extern struct ILNode_UserBinaryOp_vtable__ const ILNode_UserBinaryOp_vt__;

extern ILMachineType ILNode_UserBinaryOp_ILNode_GetType__(ILNode_UserBinaryOp *node, ILGenInfo * info);
extern void ILNode_UserBinaryOp_ILNode_GenDiscard__(ILNode_UserBinaryOp *node, ILGenInfo * info);
extern ILMachineType ILNode_UserBinaryOp_ILNode_GenValue__(ILNode_UserBinaryOp *node, ILGenInfo * info);
extern void ILNode_UserBinaryOp_JavaGenDiscard__(ILNode_UserBinaryOp *node, ILGenInfo * info);
extern ILMachineType ILNode_UserBinaryOp_JavaGenValue__(ILNode_UserBinaryOp *node, ILGenInfo * info);

struct ILNode_Concat__ {
	const struct ILNode_Concat_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Concat_vtable__ {
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

extern struct ILNode_Concat_vtable__ const ILNode_Concat_vt__;

extern ILMachineType ILNode_Concat_ILNode_GetType__(ILNode_Concat *node, ILGenInfo * info);
extern void ILNode_Concat_ILNode_GenDiscard__(ILNode_Concat *node, ILGenInfo * info);
extern ILMachineType ILNode_Concat_ILNode_GenValue__(ILNode_Concat *node, ILGenInfo * info);
extern int ILNode_Concat_ILNode_EvalConst__(ILNode_Concat *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Concat_JavaGenDiscard__(ILNode_Concat *node, ILGenInfo * info);
extern ILMachineType ILNode_Concat_JavaGenValue__(ILNode_Concat *node, ILGenInfo * info);

struct ILNode_DelegateAdd__ {
	const struct ILNode_DelegateAdd_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILClass * delegateClass;
};

struct ILNode_DelegateAdd_vtable__ {
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

extern struct ILNode_DelegateAdd_vtable__ const ILNode_DelegateAdd_vt__;

extern ILMachineType ILNode_DelegateAdd_ILNode_GetType__(ILNode_DelegateAdd *node, ILGenInfo * info);
extern void ILNode_DelegateAdd_ILNode_GenDiscard__(ILNode_DelegateAdd *node, ILGenInfo * info);
extern ILMachineType ILNode_DelegateAdd_ILNode_GenValue__(ILNode_DelegateAdd *node, ILGenInfo * info);
extern void ILNode_DelegateAdd_JavaGenDiscard__(ILNode_DelegateAdd *node, ILGenInfo * info);
extern ILMachineType ILNode_DelegateAdd_JavaGenValue__(ILNode_DelegateAdd *node, ILGenInfo * info);

struct ILNode_DelegateSub__ {
	const struct ILNode_DelegateSub_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILClass * delegateClass;
};

struct ILNode_DelegateSub_vtable__ {
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

extern struct ILNode_DelegateSub_vtable__ const ILNode_DelegateSub_vt__;

extern ILMachineType ILNode_DelegateSub_ILNode_GetType__(ILNode_DelegateSub *node, ILGenInfo * info);
extern void ILNode_DelegateSub_ILNode_GenDiscard__(ILNode_DelegateSub *node, ILGenInfo * info);
extern ILMachineType ILNode_DelegateSub_ILNode_GenValue__(ILNode_DelegateSub *node, ILGenInfo * info);
extern void ILNode_DelegateSub_JavaGenDiscard__(ILNode_DelegateSub *node, ILGenInfo * info);
extern ILMachineType ILNode_DelegateSub_JavaGenValue__(ILNode_DelegateSub *node, ILGenInfo * info);

struct ILNode_Assign__ {
	const struct ILNode_Assign_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Assign_vtable__ {
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

extern struct ILNode_Assign_vtable__ const ILNode_Assign_vt__;

extern ILMachineType ILNode_Assign_ILNode_GetType__(ILNode_Assign *node, ILGenInfo * info);
extern void ILNode_Assign_ILNode_GenDiscard__(ILNode_Assign *node, ILGenInfo * info);
extern ILMachineType ILNode_Assign_ILNode_GenValue__(ILNode_Assign *node, ILGenInfo * info);
extern void ILNode_Assign_JavaGenDiscard__(ILNode_Assign *node, ILGenInfo * info);
extern ILMachineType ILNode_Assign_JavaGenValue__(ILNode_Assign *node, ILGenInfo * info);

struct ILNode_Relational__ {
	const struct ILNode_Relational_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Relational_vtable__ {
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

extern struct ILNode_Relational_vtable__ const ILNode_Relational_vt__;

extern ILMachineType ILNode_Relational_ILNode_GetType__(ILNode_Relational *node, ILGenInfo * info);
extern void ILNode_Relational_ILNode_GenDiscard__(ILNode_Relational *node, ILGenInfo * info);
extern ILMachineType ILNode_Relational_ILNode_GenValue__(ILNode_Relational *node, ILGenInfo * info);
extern void ILNode_Relational_ILNode_GenThen__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Relational_ILNode_GenElse__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Relational_ILNode_EvalConst__(ILNode_Relational *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Relational_JavaGenDiscard__(ILNode_Relational *node, ILGenInfo * info);
extern ILMachineType ILNode_Relational_JavaGenValue__(ILNode_Relational *node, ILGenInfo * info);
extern void ILNode_Relational_JavaGenThen__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Relational_JavaGenElse__(ILNode_Relational *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Comma__ {
	const struct ILNode_Comma_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Comma_vtable__ {
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

extern struct ILNode_Comma_vtable__ const ILNode_Comma_vt__;

extern ILMachineType ILNode_Comma_ILNode_GetType__(ILNode_Comma *node, ILGenInfo * info);
extern void ILNode_Comma_ILNode_GenDiscard__(ILNode_Comma *node, ILGenInfo * info);
extern ILMachineType ILNode_Comma_ILNode_GenValue__(ILNode_Comma *node, ILGenInfo * info);
extern void ILNode_Comma_ILNode_GenThen__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Comma_ILNode_GenElse__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Comma_ILNode_EvalConst__(ILNode_Comma *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Comma_JavaGenDiscard__(ILNode_Comma *node, ILGenInfo * info);
extern ILMachineType ILNode_Comma_JavaGenValue__(ILNode_Comma *node, ILGenInfo * info);
extern void ILNode_Comma_JavaGenThen__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Comma_JavaGenElse__(ILNode_Comma *node, ILGenInfo * info, ILLabel * label);

struct ILNode_ArgList__ {
	const struct ILNode_ArgList_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_ArgList_vtable__ {
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

extern struct ILNode_ArgList_vtable__ const ILNode_ArgList_vt__;

extern ILMachineType ILNode_ArgList_ILNode_GetType__(ILNode_ArgList *node, ILGenInfo * info);
extern void ILNode_ArgList_ILNode_GenDiscard__(ILNode_ArgList *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgList_ILNode_GenValue__(ILNode_ArgList *node, ILGenInfo * info);
extern ILMachineType ILNode_ArgList_JavaGenValue__(ILNode_ArgList *node, ILGenInfo * info);

struct ILNode_RefValue__ {
	const struct ILNode_RefValue_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILType * type;
};

struct ILNode_RefValue_vtable__ {
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

extern struct ILNode_RefValue_vtable__ const ILNode_RefValue_vt__;

extern ILMachineType ILNode_RefValue_ILNode_GetType__(ILNode_RefValue *node, ILGenInfo * info);
extern ILMachineType ILNode_RefValue_ILNode_GenValue__(ILNode_RefValue *node, ILGenInfo * info);
extern ILMachineType ILNode_RefValue_JavaGenValue__(ILNode_RefValue *node, ILGenInfo * info);

struct ILNode_InvocationExpression__ {
	const struct ILNode_InvocationExpression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILNode * thisExpr;
	ILMethod * methodInfo;
	ILType * callSiteSig;
	int baseCall;
};

struct ILNode_InvocationExpression_vtable__ {
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

extern struct ILNode_InvocationExpression_vtable__ const ILNode_InvocationExpression_vt__;

extern ILMachineType ILNode_InvocationExpression_ILNode_GetType__(ILNode_InvocationExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_InvocationExpression_ILNode_GenValue__(ILNode_InvocationExpression *node, ILGenInfo * info);
extern ILMachineType ILNode_InvocationExpression_JavaGenValue__(ILNode_InvocationExpression *node, ILGenInfo * info);

struct ILNode_UserLogicalAnd__ {
	const struct ILNode_UserLogicalAnd_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILMethod * opMethod;
	ILMethod * trueMethod;
	ILMethod * falseMethod;
};

struct ILNode_UserLogicalAnd_vtable__ {
	const struct ILNode_UserLogical_vtable__ *parent__;
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

extern struct ILNode_UserLogicalAnd_vtable__ const ILNode_UserLogicalAnd_vt__;

extern ILMachineType ILNode_UserLogicalAnd_ILNode_GetType__(ILNode_UserLogicalAnd *node, ILGenInfo * info);
extern ILMachineType ILNode_UserLogicalAnd_ILNode_GenValue__(ILNode_UserLogicalAnd *node, ILGenInfo * info);
extern ILMachineType ILNode_UserLogicalAnd_JavaGenValue__(ILNode_UserLogicalAnd *node, ILGenInfo * info);

struct ILNode_UserLogicalOr__ {
	const struct ILNode_UserLogicalOr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILMethod * opMethod;
	ILMethod * trueMethod;
	ILMethod * falseMethod;
};

struct ILNode_UserLogicalOr_vtable__ {
	const struct ILNode_UserLogical_vtable__ *parent__;
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

extern struct ILNode_UserLogicalOr_vtable__ const ILNode_UserLogicalOr_vt__;

extern ILMachineType ILNode_UserLogicalOr_ILNode_GetType__(ILNode_UserLogicalOr *node, ILGenInfo * info);
extern ILMachineType ILNode_UserLogicalOr_ILNode_GenValue__(ILNode_UserLogicalOr *node, ILGenInfo * info);
extern ILMachineType ILNode_UserLogicalOr_JavaGenValue__(ILNode_UserLogicalOr *node, ILGenInfo * info);

struct ILNode_Add__ {
	const struct ILNode_Add_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Add_vtable__ {
	const struct ILNode_BinaryArith_vtable__ *parent__;
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

extern struct ILNode_Add_vtable__ const ILNode_Add_vt__;

extern ILMachineType ILNode_Add_ILNode_GenValue__(ILNode_Add *node, ILGenInfo * info);
extern ILMachineType ILNode_Add_JavaGenValue__(ILNode_Add *node, ILGenInfo * info);

struct ILNode_Sub__ {
	const struct ILNode_Sub_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Sub_vtable__ {
	const struct ILNode_BinaryArith_vtable__ *parent__;
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

extern struct ILNode_Sub_vtable__ const ILNode_Sub_vt__;

struct ILNode_Mul__ {
	const struct ILNode_Mul_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Mul_vtable__ {
	const struct ILNode_BinaryArith_vtable__ *parent__;
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

extern struct ILNode_Mul_vtable__ const ILNode_Mul_vt__;

struct ILNode_Div__ {
	const struct ILNode_Div_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Div_vtable__ {
	const struct ILNode_BinaryArith_vtable__ *parent__;
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

extern struct ILNode_Div_vtable__ const ILNode_Div_vt__;

struct ILNode_Rem__ {
	const struct ILNode_Rem_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Rem_vtable__ {
	const struct ILNode_BinaryArith_vtable__ *parent__;
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

extern struct ILNode_Rem_vtable__ const ILNode_Rem_vt__;

struct ILNode_And__ {
	const struct ILNode_And_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_And_vtable__ {
	const struct ILNode_BinaryBitwise_vtable__ *parent__;
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

extern struct ILNode_And_vtable__ const ILNode_And_vt__;

struct ILNode_Or__ {
	const struct ILNode_Or_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Or_vtable__ {
	const struct ILNode_BinaryBitwise_vtable__ *parent__;
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

extern struct ILNode_Or_vtable__ const ILNode_Or_vt__;

struct ILNode_Xor__ {
	const struct ILNode_Xor_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Xor_vtable__ {
	const struct ILNode_BinaryBitwise_vtable__ *parent__;
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

extern struct ILNode_Xor_vtable__ const ILNode_Xor_vt__;

struct ILNode_Shl__ {
	const struct ILNode_Shl_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Shl_vtable__ {
	const struct ILNode_BinaryShift_vtable__ *parent__;
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

extern struct ILNode_Shl_vtable__ const ILNode_Shl_vt__;

struct ILNode_Shr__ {
	const struct ILNode_Shr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Shr_vtable__ {
	const struct ILNode_BinaryShift_vtable__ *parent__;
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

extern struct ILNode_Shr_vtable__ const ILNode_Shr_vt__;

struct ILNode_UShr__ {
	const struct ILNode_UShr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_UShr_vtable__ {
	const struct ILNode_BinaryShift_vtable__ *parent__;
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

extern struct ILNode_UShr_vtable__ const ILNode_UShr_vt__;

struct ILNode_Eq__ {
	const struct ILNode_Eq_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Eq_vtable__ {
	const struct ILNode_Relational_vtable__ *parent__;
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

extern struct ILNode_Eq_vtable__ const ILNode_Eq_vt__;

struct ILNode_Ne__ {
	const struct ILNode_Ne_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Ne_vtable__ {
	const struct ILNode_Relational_vtable__ *parent__;
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

extern struct ILNode_Ne_vtable__ const ILNode_Ne_vt__;

struct ILNode_Lt__ {
	const struct ILNode_Lt_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Lt_vtable__ {
	const struct ILNode_Relational_vtable__ *parent__;
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

extern struct ILNode_Lt_vtable__ const ILNode_Lt_vt__;

struct ILNode_Le__ {
	const struct ILNode_Le_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Le_vtable__ {
	const struct ILNode_Relational_vtable__ *parent__;
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

extern struct ILNode_Le_vtable__ const ILNode_Le_vt__;

struct ILNode_Gt__ {
	const struct ILNode_Gt_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Gt_vtable__ {
	const struct ILNode_Relational_vtable__ *parent__;
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

extern struct ILNode_Gt_vtable__ const ILNode_Gt_vt__;

struct ILNode_Ge__ {
	const struct ILNode_Ge_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
};

struct ILNode_Ge_vtable__ {
	const struct ILNode_Relational_vtable__ *parent__;
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

extern struct ILNode_Ge_vtable__ const ILNode_Ge_vt__;

struct ILNode_Conditional__ {
	const struct ILNode_Conditional_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr1;
	ILNode * expr2;
	ILNode * expr3;
};

struct ILNode_Conditional_vtable__ {
	const struct ILNode_TernaryExpression_vtable__ *parent__;
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

extern struct ILNode_Conditional_vtable__ const ILNode_Conditional_vt__;

extern ILMachineType ILNode_Conditional_ILNode_GetType__(ILNode_Conditional *node, ILGenInfo * info);
extern void ILNode_Conditional_ILNode_GenDiscard__(ILNode_Conditional *node, ILGenInfo * info);
extern ILMachineType ILNode_Conditional_ILNode_GenValue__(ILNode_Conditional *node, ILGenInfo * info);
extern void ILNode_Conditional_ILNode_GenThen__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Conditional_ILNode_GenElse__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label);
extern int ILNode_Conditional_ILNode_EvalConst__(ILNode_Conditional *node, ILGenInfo * info, ILEvalValue * value);
extern void ILNode_Conditional_JavaGenDiscard__(ILNode_Conditional *node, ILGenInfo * info);
extern ILMachineType ILNode_Conditional_JavaGenValue__(ILNode_Conditional *node, ILGenInfo * info);
extern void ILNode_Conditional_JavaGenThen__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Conditional_JavaGenElse__(ILNode_Conditional *node, ILGenInfo * info, ILLabel * label);

struct ILNode_AssignAdd__ {
	const struct ILNode_AssignAdd_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignAdd_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignAdd_vtable__ const ILNode_AssignAdd_vt__;

struct ILNode_AssignSub__ {
	const struct ILNode_AssignSub_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignSub_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignSub_vtable__ const ILNode_AssignSub_vt__;

struct ILNode_AssignMul__ {
	const struct ILNode_AssignMul_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignMul_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignMul_vtable__ const ILNode_AssignMul_vt__;

struct ILNode_AssignDiv__ {
	const struct ILNode_AssignDiv_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignDiv_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignDiv_vtable__ const ILNode_AssignDiv_vt__;

struct ILNode_AssignRem__ {
	const struct ILNode_AssignRem_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignRem_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignRem_vtable__ const ILNode_AssignRem_vt__;

struct ILNode_AssignAnd__ {
	const struct ILNode_AssignAnd_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignAnd_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignAnd_vtable__ const ILNode_AssignAnd_vt__;

struct ILNode_AssignOr__ {
	const struct ILNode_AssignOr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignOr_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignOr_vtable__ const ILNode_AssignOr_vt__;

struct ILNode_AssignXor__ {
	const struct ILNode_AssignXor_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignXor_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignXor_vtable__ const ILNode_AssignXor_vt__;

struct ILNode_AssignShl__ {
	const struct ILNode_AssignShl_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignShl_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignShl_vtable__ const ILNode_AssignShl_vt__;

struct ILNode_AssignShr__ {
	const struct ILNode_AssignShr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignShr_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignShr_vtable__ const ILNode_AssignShr_vt__;

struct ILNode_AssignUShr__ {
	const struct ILNode_AssignUShr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * assign;
	ILNode * lvalue;
};

struct ILNode_AssignUShr_vtable__ {
	const struct ILNode_AssignExpression_vtable__ *parent__;
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

extern struct ILNode_AssignUShr_vtable__ const ILNode_AssignUShr_vt__;

struct ILNode_As__ {
	const struct ILNode_As_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILClass * classInfo;
	int isEnumType;
};

struct ILNode_As_vtable__ {
	const struct ILNode_BoxingExpression_vtable__ *parent__;
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

extern struct ILNode_As_vtable__ const ILNode_As_vt__;

extern ILMachineType ILNode_As_ILNode_GetType__(ILNode_As *node, ILGenInfo * info);
extern void ILNode_As_ILNode_GenDiscard__(ILNode_As *node, ILGenInfo * info);
extern ILMachineType ILNode_As_ILNode_GenValue__(ILNode_As *node, ILGenInfo * info);
extern void ILNode_As_ILNode_GenThen__(ILNode_As *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_As_ILNode_GenElse__(ILNode_As *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_As_JavaGenDiscard__(ILNode_As *node, ILGenInfo * info);
extern ILMachineType ILNode_As_JavaGenValue__(ILNode_As *node, ILGenInfo * info);
extern void ILNode_As_JavaGenThen__(ILNode_As *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_As_JavaGenElse__(ILNode_As *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Is__ {
	const struct ILNode_Is_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILClass * classInfo;
	int isEnumType;
};

struct ILNode_Is_vtable__ {
	const struct ILNode_BoxingExpression_vtable__ *parent__;
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

extern struct ILNode_Is_vtable__ const ILNode_Is_vt__;

extern ILMachineType ILNode_Is_ILNode_GetType__(ILNode_Is *node, ILGenInfo * info);
extern void ILNode_Is_ILNode_GenDiscard__(ILNode_Is *node, ILGenInfo * info);
extern ILMachineType ILNode_Is_ILNode_GenValue__(ILNode_Is *node, ILGenInfo * info);
extern void ILNode_Is_ILNode_GenThen__(ILNode_Is *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Is_ILNode_GenElse__(ILNode_Is *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Is_JavaGenDiscard__(ILNode_Is *node, ILGenInfo * info);
extern ILMachineType ILNode_Is_JavaGenValue__(ILNode_Is *node, ILGenInfo * info);
extern void ILNode_Is_JavaGenThen__(ILNode_Is *node, ILGenInfo * info, ILLabel * label);
extern void ILNode_Is_JavaGenElse__(ILNode_Is *node, ILGenInfo * info, ILLabel * label);

struct ILNode_Box__ {
	const struct ILNode_Box_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILClass * classInfo;
	int isEnumType;
};

struct ILNode_Box_vtable__ {
	const struct ILNode_BoxingExpression_vtable__ *parent__;
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

extern struct ILNode_Box_vtable__ const ILNode_Box_vt__;

extern ILMachineType ILNode_Box_ILNode_GetType__(ILNode_Box *node, ILGenInfo * info);
extern ILMachineType ILNode_Box_ILNode_GenValue__(ILNode_Box *node, ILGenInfo * info);
extern ILMachineType ILNode_Box_JavaGenValue__(ILNode_Box *node, ILGenInfo * info);

struct ILNode_Unbox__ {
	const struct ILNode_Unbox_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILNode * expr;
	ILClass * classInfo;
	int isEnumType;
	ILMachineType machineType;
};

struct ILNode_Unbox_vtable__ {
	const struct ILNode_BoxingExpression_vtable__ *parent__;
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

extern struct ILNode_Unbox_vtable__ const ILNode_Unbox_vt__;

extern ILMachineType ILNode_Unbox_ILNode_GetType__(ILNode_Unbox *node, ILGenInfo * info);
extern ILMachineType ILNode_Unbox_ILNode_GenValue__(ILNode_Unbox *node, ILGenInfo * info);
extern ILMachineType ILNode_Unbox_JavaGenValue__(ILNode_Unbox *node, ILGenInfo * info);

struct ILNode_List__ {
	const struct ILNode_List_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * item1;
	ILNode * item2;
	ILNode * item3;
	ILNode * item4;
	ILNode_List * rest;
};

struct ILNode_List_vtable__ {
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

extern struct ILNode_List_vtable__ const ILNode_List_vt__;

extern ILMachineType ILNode_List_ILNode_GetType__(ILNode_List *node, ILGenInfo * info);
extern void ILNode_List_ILNode_GenDiscard__(ILNode_List *node, ILGenInfo * info);
extern ILMachineType ILNode_List_ILNode_GenValue__(ILNode_List *node, ILGenInfo * info);
extern int ILNode_List_ILNode_EndsInReturnImpl__(ILNode_List *node, ILGenInfo * info);
extern void ILNode_List_JavaGenDiscard__(ILNode_List *node, ILGenInfo * info);

struct ILNode_Empty__ {
	const struct ILNode_Empty_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_Empty_vtable__ {
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

extern struct ILNode_Empty_vtable__ const ILNode_Empty_vt__;

extern void ILNode_Empty_ILNode_GenDiscard__(ILNode_Empty *node, ILGenInfo * info);
extern int ILNode_Empty_ILNode_EndsInReturnImpl__(ILNode_Empty *node, ILGenInfo * info);
extern void ILNode_Empty_JavaGenDiscard__(ILNode_Empty *node, ILGenInfo * info);

struct ILNode_If__ {
	const struct ILNode_If_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr;
	ILNode * thenClause;
	ILNode * elseClause;
};

struct ILNode_If_vtable__ {
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

extern struct ILNode_If_vtable__ const ILNode_If_vt__;

extern void ILNode_If_ILNode_GenDiscard__(ILNode_If *node, ILGenInfo * info);
extern int ILNode_If_ILNode_EndsInReturnImpl__(ILNode_If *node, ILGenInfo * info);
extern void ILNode_If_JavaGenDiscard__(ILNode_If *node, ILGenInfo * info);

struct ILNode_LabelledStatement__ {
	const struct ILNode_LabelledStatement_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
};

struct ILNode_LabelledStatement_vtable__ {
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

extern struct ILNode_LabelledStatement_vtable__ const ILNode_LabelledStatement_vt__;

struct ILNode_Break__ {
	const struct ILNode_Break_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_Break_vtable__ {
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

extern struct ILNode_Break_vtable__ const ILNode_Break_vt__;

extern void ILNode_Break_ILNode_GenDiscard__(ILNode_Break *node, ILGenInfo * info);
extern int ILNode_Break_ILNode_EndsInReturnImpl__(ILNode_Break *node, ILGenInfo * info);
extern void ILNode_Break_JavaGenDiscard__(ILNode_Break *node, ILGenInfo * info);

struct ILNode_LabelledBreak__ {
	const struct ILNode_LabelledBreak_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
};

struct ILNode_LabelledBreak_vtable__ {
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

extern struct ILNode_LabelledBreak_vtable__ const ILNode_LabelledBreak_vt__;

extern void ILNode_LabelledBreak_ILNode_GenDiscard__(ILNode_LabelledBreak *node, ILGenInfo * info);
extern int ILNode_LabelledBreak_ILNode_EndsInReturnImpl__(ILNode_LabelledBreak *node, ILGenInfo * info);
extern void ILNode_LabelledBreak_JavaGenDiscard__(ILNode_LabelledBreak *node, ILGenInfo * info);

struct ILNode_Continue__ {
	const struct ILNode_Continue_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_Continue_vtable__ {
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

extern struct ILNode_Continue_vtable__ const ILNode_Continue_vt__;

extern void ILNode_Continue_ILNode_GenDiscard__(ILNode_Continue *node, ILGenInfo * info);
extern int ILNode_Continue_ILNode_EndsInReturnImpl__(ILNode_Continue *node, ILGenInfo * info);
extern void ILNode_Continue_JavaGenDiscard__(ILNode_Continue *node, ILGenInfo * info);

struct ILNode_LabelledContinue__ {
	const struct ILNode_LabelledContinue_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
};

struct ILNode_LabelledContinue_vtable__ {
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

extern struct ILNode_LabelledContinue_vtable__ const ILNode_LabelledContinue_vt__;

extern void ILNode_LabelledContinue_ILNode_GenDiscard__(ILNode_LabelledContinue *node, ILGenInfo * info);
extern int ILNode_LabelledContinue_ILNode_EndsInReturnImpl__(ILNode_LabelledContinue *node, ILGenInfo * info);
extern void ILNode_LabelledContinue_JavaGenDiscard__(ILNode_LabelledContinue *node, ILGenInfo * info);

struct ILNode_Return__ {
	const struct ILNode_Return_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_Return_vtable__ {
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

extern struct ILNode_Return_vtable__ const ILNode_Return_vt__;

extern void ILNode_Return_ILNode_GenDiscard__(ILNode_Return *node, ILGenInfo * info);
extern int ILNode_Return_ILNode_EndsInReturnImpl__(ILNode_Return *node, ILGenInfo * info);
extern void ILNode_Return_JavaGenDiscard__(ILNode_Return *node, ILGenInfo * info);

struct ILNode_ReturnExpr__ {
	const struct ILNode_ReturnExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr;
};

struct ILNode_ReturnExpr_vtable__ {
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

extern struct ILNode_ReturnExpr_vtable__ const ILNode_ReturnExpr_vt__;

extern void ILNode_ReturnExpr_ILNode_GenDiscard__(ILNode_ReturnExpr *node, ILGenInfo * info);
extern int ILNode_ReturnExpr_ILNode_EndsInReturnImpl__(ILNode_ReturnExpr *node, ILGenInfo * info);
extern void ILNode_ReturnExpr_JavaGenDiscard__(ILNode_ReturnExpr *node, ILGenInfo * info);

struct ILNode_Goto__ {
	const struct ILNode_Goto_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
};

struct ILNode_Goto_vtable__ {
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

extern struct ILNode_Goto_vtable__ const ILNode_Goto_vt__;

extern void ILNode_Goto_ILNode_GenDiscard__(ILNode_Goto *node, ILGenInfo * info);
extern int ILNode_Goto_ILNode_EndsInReturnImpl__(ILNode_Goto *node, ILGenInfo * info);
extern void ILNode_Goto_JavaGenDiscard__(ILNode_Goto *node, ILGenInfo * info);

struct ILNode_GotoLabel__ {
	const struct ILNode_GotoLabel_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
};

struct ILNode_GotoLabel_vtable__ {
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

extern struct ILNode_GotoLabel_vtable__ const ILNode_GotoLabel_vt__;

extern void ILNode_GotoLabel_ILNode_GenDiscard__(ILNode_GotoLabel *node, ILGenInfo * info);
extern void ILNode_GotoLabel_JavaGenDiscard__(ILNode_GotoLabel *node, ILGenInfo * info);

struct ILNode_GotoCase__ {
	const struct ILNode_GotoCase_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr;
	ILNode_SwitchSection * switchSection;
};

struct ILNode_GotoCase_vtable__ {
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

extern struct ILNode_GotoCase_vtable__ const ILNode_GotoCase_vt__;

extern void ILNode_GotoCase_ILNode_GenDiscard__(ILNode_GotoCase *node, ILGenInfo * info);
extern int ILNode_GotoCase_ILNode_EndsInReturnImpl__(ILNode_GotoCase *node, ILGenInfo * info);
extern void ILNode_GotoCase_JavaGenDiscard__(ILNode_GotoCase *node, ILGenInfo * info);

struct ILNode_GotoDefault__ {
	const struct ILNode_GotoDefault_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_GotoDefault_vtable__ {
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

extern struct ILNode_GotoDefault_vtable__ const ILNode_GotoDefault_vt__;

extern void ILNode_GotoDefault_ILNode_GenDiscard__(ILNode_GotoDefault *node, ILGenInfo * info);
extern int ILNode_GotoDefault_ILNode_EndsInReturnImpl__(ILNode_GotoDefault *node, ILGenInfo * info);
extern void ILNode_GotoDefault_JavaGenDiscard__(ILNode_GotoDefault *node, ILGenInfo * info);

struct ILNode_NewScope__ {
	const struct ILNode_NewScope_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * stmt;
	ILScope * scope;
};

struct ILNode_NewScope_vtable__ {
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

extern struct ILNode_NewScope_vtable__ const ILNode_NewScope_vt__;

extern ILMachineType ILNode_NewScope_ILNode_GetType__(ILNode_NewScope *node, ILGenInfo * info);
extern void ILNode_NewScope_ILNode_GenDiscard__(ILNode_NewScope *node, ILGenInfo * info);
extern ILMachineType ILNode_NewScope_ILNode_GenValue__(ILNode_NewScope *node, ILGenInfo * info);
extern int ILNode_NewScope_ILNode_EndsInReturnImpl__(ILNode_NewScope *node, ILGenInfo * info);
extern void ILNode_NewScope_JavaGenDiscard__(ILNode_NewScope *node, ILGenInfo * info);

struct ILNode_SwitchSection__ {
	const struct ILNode_SwitchSection_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * caseList;
	ILNode * stmt;
	ILLabel label;
	ILVisitMode visited;
};

struct ILNode_SwitchSection_vtable__ {
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

extern struct ILNode_SwitchSection_vtable__ const ILNode_SwitchSection_vt__;

extern void ILNode_SwitchSection_ILNode_GenDiscard__(ILNode_SwitchSection *node, ILGenInfo * info);
extern void ILNode_SwitchSection_JavaGenDiscard__(ILNode_SwitchSection *node, ILGenInfo * info);

struct ILNode_CaseLabel__ {
	const struct ILNode_CaseLabel_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr;
	ILNode_SwitchSection * section;
};

struct ILNode_CaseLabel_vtable__ {
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

extern struct ILNode_CaseLabel_vtable__ const ILNode_CaseLabel_vt__;

extern void ILNode_CaseLabel_ILNode_GenDiscard__(ILNode_CaseLabel *node, ILGenInfo * info);
extern void ILNode_CaseLabel_JavaGenDiscard__(ILNode_CaseLabel *node, ILGenInfo * info);

struct ILNode_DefaultLabel__ {
	const struct ILNode_DefaultLabel_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode_SwitchSection * section;
};

struct ILNode_DefaultLabel_vtable__ {
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

extern struct ILNode_DefaultLabel_vtable__ const ILNode_DefaultLabel_vt__;

extern void ILNode_DefaultLabel_ILNode_GenDiscard__(ILNode_DefaultLabel *node, ILGenInfo * info);
extern void ILNode_DefaultLabel_JavaGenDiscard__(ILNode_DefaultLabel *node, ILGenInfo * info);

struct ILNode_Throw__ {
	const struct ILNode_Throw_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_Throw_vtable__ {
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

extern struct ILNode_Throw_vtable__ const ILNode_Throw_vt__;

extern void ILNode_Throw_ILNode_GenDiscard__(ILNode_Throw *node, ILGenInfo * info);
extern int ILNode_Throw_ILNode_EndsInReturnImpl__(ILNode_Throw *node, ILGenInfo * info);
extern void ILNode_Throw_JavaGenDiscard__(ILNode_Throw *node, ILGenInfo * info);

struct ILNode_ThrowExpr__ {
	const struct ILNode_ThrowExpr_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr;
};

struct ILNode_ThrowExpr_vtable__ {
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

extern struct ILNode_ThrowExpr_vtable__ const ILNode_ThrowExpr_vt__;

extern void ILNode_ThrowExpr_ILNode_GenDiscard__(ILNode_ThrowExpr *node, ILGenInfo * info);
extern int ILNode_ThrowExpr_ILNode_EndsInReturnImpl__(ILNode_ThrowExpr *node, ILGenInfo * info);
extern void ILNode_ThrowExpr_JavaGenDiscard__(ILNode_ThrowExpr *node, ILGenInfo * info);

struct ILNode_Try__ {
	const struct ILNode_Try_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * stmt;
	ILNode * catchClauses;
	ILNode * finallyClause;
};

struct ILNode_Try_vtable__ {
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

extern struct ILNode_Try_vtable__ const ILNode_Try_vt__;

extern void ILNode_Try_ILNode_GenDiscard__(ILNode_Try *node, ILGenInfo * info);
extern int ILNode_Try_ILNode_EndsInReturnImpl__(ILNode_Try *node, ILGenInfo * info);
extern void ILNode_Try_JavaGenDiscard__(ILNode_Try *node, ILGenInfo * info);

struct ILNode_CatchClause__ {
	const struct ILNode_CatchClause_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * type;
	char * name;
	ILNode * nameNode;
	ILNode * stmt;
	ILClass * classInfo;
	unsigned long varIndex;
};

struct ILNode_CatchClause_vtable__ {
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

extern struct ILNode_CatchClause_vtable__ const ILNode_CatchClause_vt__;

extern void ILNode_CatchClause_ILNode_GenDiscard__(ILNode_CatchClause *node, ILGenInfo * info);
extern int ILNode_CatchClause_ILNode_EndsInReturnImpl__(ILNode_CatchClause *node, ILGenInfo * info);
extern void ILNode_CatchClause_JavaGenDiscard__(ILNode_CatchClause *node, ILGenInfo * info);

struct ILNode_FinallyClause__ {
	const struct ILNode_FinallyClause_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * stmt;
};

struct ILNode_FinallyClause_vtable__ {
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

extern struct ILNode_FinallyClause_vtable__ const ILNode_FinallyClause_vt__;

extern void ILNode_FinallyClause_ILNode_GenDiscard__(ILNode_FinallyClause *node, ILGenInfo * info);
extern int ILNode_FinallyClause_ILNode_EndsInReturnImpl__(ILNode_FinallyClause *node, ILGenInfo * info);
extern void ILNode_FinallyClause_JavaGenDiscard__(ILNode_FinallyClause *node, ILGenInfo * info);

struct ILNode_Lock__ {
	const struct ILNode_Lock_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * expr;
	ILNode * stmt;
};

struct ILNode_Lock_vtable__ {
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

extern struct ILNode_Lock_vtable__ const ILNode_Lock_vt__;

extern void ILNode_Lock_ILNode_GenDiscard__(ILNode_Lock *node, ILGenInfo * info);
extern int ILNode_Lock_ILNode_EndsInReturnImpl__(ILNode_Lock *node, ILGenInfo * info);
extern void ILNode_Lock_JavaGenDiscard__(ILNode_Lock *node, ILGenInfo * info);

struct ILNode_LocalVarDeclaration__ {
	const struct ILNode_LocalVarDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * type;
	ILNode * varNames;
};

struct ILNode_LocalVarDeclaration_vtable__ {
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

extern struct ILNode_LocalVarDeclaration_vtable__ const ILNode_LocalVarDeclaration_vt__;

extern void ILNode_LocalVarDeclaration_ILNode_GenDiscard__(ILNode_LocalVarDeclaration *node, ILGenInfo * info);
extern void ILNode_LocalVarDeclaration_JavaGenDiscard__(ILNode_LocalVarDeclaration *node, ILGenInfo * info);

struct ILNode_LocalConstDeclaration__ {
	const struct ILNode_LocalConstDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * type;
	ILNode * decls;
};

struct ILNode_LocalConstDeclaration_vtable__ {
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

extern struct ILNode_LocalConstDeclaration_vtable__ const ILNode_LocalConstDeclaration_vt__;

extern void ILNode_LocalConstDeclaration_ILNode_GenDiscard__(ILNode_LocalConstDeclaration *node, ILGenInfo * info);
extern void ILNode_LocalConstDeclaration_JavaGenDiscard__(ILNode_LocalConstDeclaration *node, ILGenInfo * info);

struct ILNode_LineInfo__ {
	const struct ILNode_LineInfo_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * stmt;
};

struct ILNode_LineInfo_vtable__ {
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

extern struct ILNode_LineInfo_vtable__ const ILNode_LineInfo_vt__;

extern void ILNode_LineInfo_ILNode_GenDiscard__(ILNode_LineInfo *node, ILGenInfo * info);
extern int ILNode_LineInfo_ILNode_EndsInReturnImpl__(ILNode_LineInfo *node, ILGenInfo * info);
extern void ILNode_LineInfo_JavaGenDiscard__(ILNode_LineInfo *node, ILGenInfo * info);

struct ILNode_EventAddOrRemove__ {
	const struct ILNode_EventAddOrRemove_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * thisExpr;
	ILNode * delegateExpr;
	ILMethod * method;
};

struct ILNode_EventAddOrRemove_vtable__ {
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

extern struct ILNode_EventAddOrRemove_vtable__ const ILNode_EventAddOrRemove_vt__;

extern void ILNode_EventAddOrRemove_ILNode_GenDiscard__(ILNode_EventAddOrRemove *node, ILGenInfo * info);
extern void ILNode_EventAddOrRemove_JavaGenDiscard__(ILNode_EventAddOrRemove *node, ILGenInfo * info);

struct ILNode_Declaration__ {
	const struct ILNode_Declaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
};

struct ILNode_Declaration_vtable__ {
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

extern struct ILNode_Declaration_vtable__ const ILNode_Declaration_vt__;

struct ILNode_Compound__ {
	const struct ILNode_Compound_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * item1;
	ILNode * item2;
	ILNode * item3;
	ILNode * item4;
	ILNode_List * rest;
};

struct ILNode_Compound_vtable__ {
	const struct ILNode_List_vtable__ *parent__;
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

extern struct ILNode_Compound_vtable__ const ILNode_Compound_vt__;

extern void ILNode_Compound_ILNode_GenDiscard__(ILNode_Compound *node, ILGenInfo * info);
extern ILMachineType ILNode_Compound_ILNode_GenValue__(ILNode_Compound *node, ILGenInfo * info);
extern int ILNode_Compound_ILNode_EndsInReturnImpl__(ILNode_Compound *node, ILGenInfo * info);
extern void ILNode_Compound_JavaGenDiscard__(ILNode_Compound *node, ILGenInfo * info);

struct ILNode_SwitchSectList__ {
	const struct ILNode_SwitchSectList_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * item1;
	ILNode * item2;
	ILNode * item3;
	ILNode * item4;
	ILNode_List * rest;
};

struct ILNode_SwitchSectList_vtable__ {
	const struct ILNode_List_vtable__ *parent__;
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

extern struct ILNode_SwitchSectList_vtable__ const ILNode_SwitchSectList_vt__;

extern void ILNode_SwitchSectList_ILNode_GenDiscard__(ILNode_SwitchSectList *node, ILGenInfo * info);
extern void ILNode_SwitchSectList_JavaGenDiscard__(ILNode_SwitchSectList *node, ILGenInfo * info);

struct ILNode_CaseList__ {
	const struct ILNode_CaseList_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * item1;
	ILNode * item2;
	ILNode * item3;
	ILNode * item4;
	ILNode_List * rest;
};

struct ILNode_CaseList_vtable__ {
	const struct ILNode_List_vtable__ *parent__;
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

extern struct ILNode_CaseList_vtable__ const ILNode_CaseList_vt__;

extern void ILNode_CaseList_ILNode_GenDiscard__(ILNode_CaseList *node, ILGenInfo * info);
extern void ILNode_CaseList_JavaGenDiscard__(ILNode_CaseList *node, ILGenInfo * info);

struct ILNode_CatchClauses__ {
	const struct ILNode_CatchClauses_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * item1;
	ILNode * item2;
	ILNode * item3;
	ILNode * item4;
	ILNode_List * rest;
};

struct ILNode_CatchClauses_vtable__ {
	const struct ILNode_List_vtable__ *parent__;
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

extern struct ILNode_CatchClauses_vtable__ const ILNode_CatchClauses_vt__;

struct ILNode_While__ {
	const struct ILNode_While_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
	ILNode * cond;
	ILNode * stmt;
};

struct ILNode_While_vtable__ {
	const struct ILNode_LabelledStatement_vtable__ *parent__;
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

extern struct ILNode_While_vtable__ const ILNode_While_vt__;

extern void ILNode_While_ILNode_GenDiscard__(ILNode_While *node, ILGenInfo * info);
extern int ILNode_While_ILNode_EndsInReturnImpl__(ILNode_While *node, ILGenInfo * info);
extern void ILNode_While_JavaGenDiscard__(ILNode_While *node, ILGenInfo * info);

struct ILNode_Do__ {
	const struct ILNode_Do_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
	ILNode * stmt;
	ILNode * cond;
};

struct ILNode_Do_vtable__ {
	const struct ILNode_LabelledStatement_vtable__ *parent__;
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

extern struct ILNode_Do_vtable__ const ILNode_Do_vt__;

extern void ILNode_Do_ILNode_GenDiscard__(ILNode_Do *node, ILGenInfo * info);
extern int ILNode_Do_ILNode_EndsInReturnImpl__(ILNode_Do *node, ILGenInfo * info);
extern void ILNode_Do_JavaGenDiscard__(ILNode_Do *node, ILGenInfo * info);

struct ILNode_For__ {
	const struct ILNode_For_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
	ILNode * init;
	ILNode * cond;
	ILNode * incr;
	ILNode * stmt;
};

struct ILNode_For_vtable__ {
	const struct ILNode_LabelledStatement_vtable__ *parent__;
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

extern struct ILNode_For_vtable__ const ILNode_For_vt__;

extern void ILNode_For_ILNode_GenDiscard__(ILNode_For *node, ILGenInfo * info);
extern int ILNode_For_ILNode_EndsInReturnImpl__(ILNode_For *node, ILGenInfo * info);
extern void ILNode_For_JavaGenDiscard__(ILNode_For *node, ILGenInfo * info);

struct ILNode_Foreach__ {
	const struct ILNode_Foreach_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
	ILNode * type;
	char * varName;
	ILNode * varNameNode;
	ILNode * expr;
	ILNode * stmt;
	ILNode * doCast;
	unsigned long varIndex;
	ILMachineType varType;
	ILType * arrayType;
	ILType * elemType;
};

struct ILNode_Foreach_vtable__ {
	const struct ILNode_LabelledStatement_vtable__ *parent__;
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

extern struct ILNode_Foreach_vtable__ const ILNode_Foreach_vt__;

extern void ILNode_Foreach_ILNode_GenDiscard__(ILNode_Foreach *node, ILGenInfo * info);
extern void ILNode_Foreach_JavaGenDiscard__(ILNode_Foreach *node, ILGenInfo * info);

struct ILNode_ForeachString__ {
	const struct ILNode_ForeachString_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
	ILNode * expr;
	ILNode * stmt;
	unsigned long varIndex;
	ILMachineType varType;
};

struct ILNode_ForeachString_vtable__ {
	const struct ILNode_LabelledStatement_vtable__ *parent__;
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

extern struct ILNode_ForeachString_vtable__ const ILNode_ForeachString_vt__;

extern void ILNode_ForeachString_ILNode_GenDiscard__(ILNode_ForeachString *node, ILGenInfo * info);
extern void ILNode_ForeachString_JavaGenDiscard__(ILNode_ForeachString *node, ILGenInfo * info);

struct ILNode_ForeachCollection__ {
	const struct ILNode_ForeachCollection_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
	ILNode * doCast;
	ILNode * expr;
	ILNode * stmt;
	ILType * arrayType;
	unsigned long varIndex;
	ILMachineType varType;
	ILType * enumeratorType;
	ILMethod * getEnumerator;
	ILMethod * moveNext;
	ILMethod * getCurrent;
};

struct ILNode_ForeachCollection_vtable__ {
	const struct ILNode_LabelledStatement_vtable__ *parent__;
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

extern struct ILNode_ForeachCollection_vtable__ const ILNode_ForeachCollection_vt__;

extern void ILNode_ForeachCollection_ILNode_GenDiscard__(ILNode_ForeachCollection *node, ILGenInfo * info);
extern void ILNode_ForeachCollection_JavaGenDiscard__(ILNode_ForeachCollection *node, ILGenInfo * info);

struct ILNode_Switch__ {
	const struct ILNode_Switch_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	char * name;
	ILNode * expr;
	ILNode * sections;
	ILNode * body;
	ILNode * defaultSection;
	ILSwitchValue * switchValues;
	unsigned long numSwitchValues;
	ILType * switchType;
	ILSwitchTableType tableType;
};

struct ILNode_Switch_vtable__ {
	const struct ILNode_LabelledStatement_vtable__ *parent__;
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

extern struct ILNode_Switch_vtable__ const ILNode_Switch_vt__;

extern void ILNode_Switch_ILNode_GenDiscard__(ILNode_Switch *node, ILGenInfo * info);
extern int ILNode_Switch_ILNode_EndsInReturnImpl__(ILNode_Switch *node, ILGenInfo * info);
extern void ILNode_Switch_JavaGenDiscard__(ILNode_Switch *node, ILGenInfo * info);

struct ILNode_ClassDefn__ {
	const struct ILNode_ClassDefn_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * attributes;
	ILUInt32 modifiers;
	char * name;
	char * namespace;
	ILNode * namespaceNode;
	ILNode * typeFormals;
	ILNode * baseClass;
	ILNode * body;
	ILNode * staticCtors;
	ILClass * classInfo;
	ILUInt64 nextEnum;
	ILNode * staticCtorsMethod;
	ILNode * initCtorsMethod;
	ILNode_ClassDefn * nestedParent;
	ILNode * nestedClasses;
	ILVisitMode visited;
	char * defaultMemberName;
};

struct ILNode_ClassDefn_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_ClassDefn_vtable__ const ILNode_ClassDefn_vt__;

extern void ILNode_ClassDefn_ILNode_GenDiscard__(ILNode_ClassDefn *node, ILGenInfo * info);
extern void ILNode_ClassDefn_JavaGenDiscard__(ILNode_ClassDefn *node, ILGenInfo * info);

struct ILNode_ScopeChange__ {
	const struct ILNode_ScopeChange_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILScope * scope;
	ILNode * body;
};

struct ILNode_ScopeChange_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_ScopeChange_vtable__ const ILNode_ScopeChange_vt__;

extern void ILNode_ScopeChange_ILNode_GenDiscard__(ILNode_ScopeChange *node, ILGenInfo * info);
extern void ILNode_ScopeChange_JavaGenDiscard__(ILNode_ScopeChange *node, ILGenInfo * info);

struct ILNode_FieldDeclaration__ {
	const struct ILNode_FieldDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * attributes;
	ILUInt32 modifiers;
	ILNode * type;
	ILNode * fieldDeclarators;
};

struct ILNode_FieldDeclaration_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_FieldDeclaration_vtable__ const ILNode_FieldDeclaration_vt__;

extern void ILNode_FieldDeclaration_ILNode_GenDiscard__(ILNode_FieldDeclaration *node, ILGenInfo * info);
extern void ILNode_FieldDeclaration_JavaGenDiscard__(ILNode_FieldDeclaration *node, ILGenInfo * info);

struct ILNode_FieldDeclarator__ {
	const struct ILNode_FieldDeclarator_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * name;
	ILNode * initializer;
	ILField * fieldInfo;
	ILVisitMode visited;
	ILNode_FieldDeclaration * owner;
	ILNode * staticCtor;
};

struct ILNode_FieldDeclarator_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_FieldDeclarator_vtable__ const ILNode_FieldDeclarator_vt__;

extern void ILNode_FieldDeclarator_ILNode_GenDiscard__(ILNode_FieldDeclarator *node, ILGenInfo * info);
extern void ILNode_FieldDeclarator_JavaGenDiscard__(ILNode_FieldDeclarator *node, ILGenInfo * info);

struct ILNode_EventDeclaration__ {
	const struct ILNode_EventDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * attributes;
	ILUInt32 modifiers;
	ILNode * type;
	ILNode * eventDeclarators;
	int needFields;
};

struct ILNode_EventDeclaration_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_EventDeclaration_vtable__ const ILNode_EventDeclaration_vt__;

extern void ILNode_EventDeclaration_ILNode_GenDiscard__(ILNode_EventDeclaration *node, ILGenInfo * info);
extern void ILNode_EventDeclaration_JavaGenDiscard__(ILNode_EventDeclaration *node, ILGenInfo * info);

struct ILNode_EventDeclarator__ {
	const struct ILNode_EventDeclarator_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * fieldDeclarator;
	ILNode * addAccessor;
	ILNode * removeAccessor;
	ILEvent * eventInfo;
	ILField * backingField;
	ILVisitMode visited;
	ILNode_EventDeclaration * backLink;
};

struct ILNode_EventDeclarator_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_EventDeclarator_vtable__ const ILNode_EventDeclarator_vt__;

extern void ILNode_EventDeclarator_ILNode_GenDiscard__(ILNode_EventDeclarator *node, ILGenInfo * info);
extern void ILNode_EventDeclarator_JavaGenDiscard__(ILNode_EventDeclarator *node, ILGenInfo * info);

struct ILNode_ProxyDeclaration__ {
	const struct ILNode_ProxyDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILMethod * interfaceMethod;
	ILMethod * proxyReplacement;
};

struct ILNode_ProxyDeclaration_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_ProxyDeclaration_vtable__ const ILNode_ProxyDeclaration_vt__;

extern void ILNode_ProxyDeclaration_ILNode_GenDiscard__(ILNode_ProxyDeclaration *node, ILGenInfo * info);
extern void ILNode_ProxyDeclaration_JavaGenDiscard__(ILNode_ProxyDeclaration *node, ILGenInfo * info);

struct ILNode_MethodDeclaration__ {
	const struct ILNode_MethodDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * attributes;
	ILUInt32 modifiers;
	ILNode * type;
	ILNode * name;
	ILNode * params;
	ILNode * body;
	ILMethod * methodInfo;
	ILType * localVarSig;
	ILVisitMode visited;
	int suppressCodeGen;
};

struct ILNode_MethodDeclaration_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_MethodDeclaration_vtable__ const ILNode_MethodDeclaration_vt__;

extern void ILNode_MethodDeclaration_ILNode_GenDiscard__(ILNode_MethodDeclaration *node, ILGenInfo * info);
extern void ILNode_MethodDeclaration_JavaGenDiscard__(ILNode_MethodDeclaration *node, ILGenInfo * info);

struct ILNode_PropertyDeclaration__ {
	const struct ILNode_PropertyDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * attributes;
	ILUInt32 modifiers;
	ILNode * type;
	ILNode * name;
	ILNode * params;
	ILNode * getAccessor;
	ILNode * setAccessor;
	ILUInt32 getsetFlags;
	ILProperty * propertyInfo;
	ILVisitMode visited;
};

struct ILNode_PropertyDeclaration_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_PropertyDeclaration_vtable__ const ILNode_PropertyDeclaration_vt__;

extern void ILNode_PropertyDeclaration_ILNode_GenDiscard__(ILNode_PropertyDeclaration *node, ILGenInfo * info);
extern void ILNode_PropertyDeclaration_JavaGenDiscard__(ILNode_PropertyDeclaration *node, ILGenInfo * info);

struct ILNode_EnumMemberDeclaration__ {
	const struct ILNode_EnumMemberDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * attributes;
	ILNode * name;
	ILNode * value;
	ILField * fieldInfo;
	ILVisitMode visited;
};

struct ILNode_EnumMemberDeclaration_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_EnumMemberDeclaration_vtable__ const ILNode_EnumMemberDeclaration_vt__;

extern void ILNode_EnumMemberDeclaration_ILNode_GenDiscard__(ILNode_EnumMemberDeclaration *node, ILGenInfo * info);
extern void ILNode_EnumMemberDeclaration_JavaGenDiscard__(ILNode_EnumMemberDeclaration *node, ILGenInfo * info);

struct ILNode_DelegateMemberDeclaration__ {
	const struct ILNode_DelegateMemberDeclaration_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * returnType;
	ILNode * params;
	ILMethod * ctorMethod;
	ILMethod * invokeMethod;
	ILMethod * beginInvokeMethod;
	ILMethod * endInvokeMethod;
};

struct ILNode_DelegateMemberDeclaration_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_DelegateMemberDeclaration_vtable__ const ILNode_DelegateMemberDeclaration_vt__;

extern void ILNode_DelegateMemberDeclaration_ILNode_GenDiscard__(ILNode_DelegateMemberDeclaration *node, ILGenInfo * info);
extern void ILNode_DelegateMemberDeclaration_JavaGenDiscard__(ILNode_DelegateMemberDeclaration *node, ILGenInfo * info);

struct ILNode_FormalParameter__ {
	const struct ILNode_FormalParameter_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * attributes;
	ILParameterModifier pmod;
	ILNode * type;
	ILNode * name;
};

struct ILNode_FormalParameter_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_FormalParameter_vtable__ const ILNode_FormalParameter_vt__;

extern void ILNode_FormalParameter_ILNode_GenDiscard__(ILNode_FormalParameter *node, ILGenInfo * info);
extern void ILNode_FormalParameter_JavaGenDiscard__(ILNode_FormalParameter *node, ILGenInfo * info);

struct ILNode_AttributeTree__ {
	const struct ILNode_AttributeTree_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * sections;
	ILAttrMode mode;
};

struct ILNode_AttributeTree_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_AttributeTree_vtable__ const ILNode_AttributeTree_vt__;

extern void ILNode_AttributeTree_ILNode_GenDiscard__(ILNode_AttributeTree *node, ILGenInfo * info);
extern void ILNode_AttributeTree_JavaGenDiscard__(ILNode_AttributeTree *node, ILGenInfo * info);

struct ILNode_AttributeSection__ {
	const struct ILNode_AttributeSection_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILAttrTargetType type;
	ILNode * target;
	ILNode * attrs;
};

struct ILNode_AttributeSection_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_AttributeSection_vtable__ const ILNode_AttributeSection_vt__;

extern void ILNode_AttributeSection_ILNode_GenDiscard__(ILNode_AttributeSection *node, ILGenInfo * info);
extern void ILNode_AttributeSection_JavaGenDiscard__(ILNode_AttributeSection *node, ILGenInfo * info);

struct ILNode_Attribute__ {
	const struct ILNode_Attribute_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * name;
	ILNode * args;
};

struct ILNode_Attribute_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_Attribute_vtable__ const ILNode_Attribute_vt__;

extern void ILNode_Attribute_ILNode_GenDiscard__(ILNode_Attribute *node, ILGenInfo * info);
extern void ILNode_Attribute_JavaGenDiscard__(ILNode_Attribute *node, ILGenInfo * info);

struct ILNode_AttrArgs__ {
	const struct ILNode_AttrArgs_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * positionalArgs;
	ILNode * namedArgs;
};

struct ILNode_AttrArgs_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_AttrArgs_vtable__ const ILNode_AttrArgs_vt__;

extern void ILNode_AttrArgs_ILNode_GenDiscard__(ILNode_AttrArgs *node, ILGenInfo * info);
extern void ILNode_AttrArgs_JavaGenDiscard__(ILNode_AttrArgs *node, ILGenInfo * info);

struct ILNode_NamedArg__ {
	const struct ILNode_NamedArg_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	ILVarUsageTable * varUsage;
	ILNode * name;
	ILNode * value;
};

struct ILNode_NamedArg_vtable__ {
	const struct ILNode_Declaration_vtable__ *parent__;
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

extern struct ILNode_NamedArg_vtable__ const ILNode_NamedArg_vt__;

extern void ILNode_NamedArg_ILNode_GenDiscard__(ILNode_NamedArg *node, ILGenInfo * info);
extern void ILNode_NamedArg_JavaGenDiscard__(ILNode_NamedArg *node, ILGenInfo * info);

extern ILNode *ILNode_Identifier_create(char * name);
extern ILNode *ILNode_QualIdent_create(ILNode * left, ILNode * right);
extern ILNode *ILNode_VarArgList_create(void);
extern ILNode *ILNode_Argument_create(ILParameterModifier modifier, ILNode * expression);
extern ILNode *ILNode_ArgArray_create(ILType * elemType, ILUInt32 numElems, ILNode * args);
extern ILNode *ILNode_Error_create(void);
extern ILNode *ILNode_NewExpression_create(ILNode * type, ILNode * indexes, ILNode * rank, ILNode * arrayInitializer);
extern ILNode *ILNode_ObjectCreationExpression_create(ILNode * type, ILNode * argList);
extern ILNode *ILNode_DelegateCreationExpression_create(ILClass * delegateClass, ILNode * expr, ILMethod * methodInfo);
extern ILNode *ILNode_DefaultConstructor_create(ILNode * expr, ILType * type, int useCtorMethod);
extern ILNode *ILNode_BaseInit_create(void);
extern ILNode *ILNode_ThisInit_create(void);
extern ILNode *ILNode_NonStaticInit_create(void);
extern ILNode *ILNode_EmptyExpr_create(ILMachineType type);
extern ILNode *ILNode_Null_create(void);
extern ILNode *ILNode_NullPtr_create(void);
extern ILNode *ILNode_True_create(void);
extern ILNode *ILNode_False_create(void);
extern ILNode *ILNode_Decimal_create(ILDecimal value);
extern ILNode *ILNode_String_create(char * str, int len);
extern ILNode *ILNode_Int8_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_UInt8_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_Int16_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_UInt16_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_Char_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_Int32_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_UInt32_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_Int64_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_UInt64_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_Int_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_UInt_create(ILUInt64 value, int isneg, int canneg);
extern ILNode *ILNode_Float32_create(ILDouble value);
extern ILNode *ILNode_Float64_create(ILDouble value);
extern ILNode *ILNode_Float_create(ILDouble value);
extern ILNode *ILNode_This_create(void);
extern ILNode *ILNode_LocalVar_create(unsigned long index, ILMachineType machineType);
extern ILNode *ILNode_ArgumentVar_create(unsigned long index, ILMachineType machineType);
extern ILNode *ILNode_RefArgumentVar_create(unsigned long index, ILMachineType machineType, ILType * type);
extern ILNode *ILNode_StaticField_create(ILField * field);
extern ILNode *ILNode_MemberField_create(ILNode * expr, ILField * field);
extern ILNode *ILNode_ArrayAccess_create(ILNode * array, ILNode * indices);
extern ILNode *ILNode_Deref_create(ILNode * expr, ILType * elemType);
extern ILNode *ILNode_StaticProperty_create(ILProperty * property);
extern ILNode *ILNode_MemberProperty_create(ILNode * expr, ILProperty * property);
extern ILNode *ILNode_IndexerAccess_create(ILNode * object, ILNode * indices, ILMethod * getMethod, ILMethod * setMethod, ILType * objectType, ILType * elemType, ILMachineType machineType, int baseAccess);
extern ILNode *ILNode_BaseAccess_create(ILNode * expr);
extern ILNode *ILNode_BaseElement_create(ILNode * expr);
extern ILNode *ILNode_AsIs_create(ILNode * expr);
extern ILNode *ILNode_Overflow_create(ILNode * expr);
extern ILNode *ILNode_NoOverflow_create(ILNode * expr);
extern ILNode *ILNode_Pedantic_create(ILNode * expr);
extern ILNode *ILNode_NoPedantic_create(ILNode * expr);
extern ILNode *ILNode_MarkType_create(ILNode * expr, ILType * type);
extern ILNode *ILNode_MemberAccess_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_DerefField_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_LogicalNot_create(ILNode * expr);
extern ILNode *ILNode_Neg_create(ILNode * expr);
extern ILNode *ILNode_UnaryPlus_create(ILNode * expr);
extern ILNode *ILNode_Not_create(ILNode * expr);
extern ILNode *ILNode_UserUnaryOp_create(ILNode * expr, ILMachineType machineType, ILMethod * method);
extern ILNode *ILNode_PreInc_create(ILNode * expr);
extern ILNode *ILNode_PreDec_create(ILNode * expr);
extern ILNode *ILNode_PostInc_create(ILNode * expr);
extern ILNode *ILNode_PostDec_create(ILNode * expr);
extern ILNode *ILNode_CastSimple_create(ILNode * expr, ILMachineType machineType);
extern ILNode *ILNode_CastType_create(ILNode * expr, ILType * type);
extern ILNode *ILNode_UserConversion_create(ILNode * expr, ILMachineType machineType, ILMethod * method);
extern ILNode *ILNode_AddressOf_create(ILNode * expr);
extern ILNode *ILNode_ToBool_create(ILNode * expr);
extern ILNode *ILNode_ToConst_create(ILNode * expr);
extern ILNode *ILNode_VarArgExpand_create(ILNode * expr);
extern ILNode *ILNode_IsNull_create(ILNode * expr);
extern ILNode *ILNode_IsNonNull_create(ILNode * expr);
extern ILNode *ILNode_MakeRefAny_create(ILNode * expr);
extern ILNode *ILNode_RefType_create(ILNode * expr);
extern ILNode *ILNode_ArrayLength_create(ILNode * expr);
extern ILNode *ILNode_ArrayInit_create(ILNode * expr);
extern ILNode *ILNode_UserPreInc_create(ILNode * expr, ILMethod * method, ILMachineType type);
extern ILNode *ILNode_UserPreDec_create(ILNode * expr, ILMethod * method, ILMachineType type);
extern ILNode *ILNode_UserPostInc_create(ILNode * expr, ILMethod * method, ILMachineType type);
extern ILNode *ILNode_UserPostDec_create(ILNode * expr, ILMethod * method, ILMachineType type);
extern ILNode *ILNode_PreIncPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode);
extern ILNode *ILNode_PreDecPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode);
extern ILNode *ILNode_PostIncPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode);
extern ILNode *ILNode_PostDecPtr_create(ILNode * expr, ILUInt32 size, ILNode * sizeNode);
extern ILNode *ILNode_LogicalAnd_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_LogicalOr_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_UserBinaryOp_create(ILNode * expr1, ILNode * expr2, ILMachineType machineType, ILMethod * method);
extern ILNode *ILNode_Concat_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_DelegateAdd_create(ILNode * expr1, ILNode * expr2, ILClass * delegateClass);
extern ILNode *ILNode_DelegateSub_create(ILNode * expr1, ILNode * expr2, ILClass * delegateClass);
extern ILNode *ILNode_Assign_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Comma_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_ArgList_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_RefValue_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_InvocationExpression_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_UserLogicalAnd_create(ILNode * expr1, ILNode * expr2, ILMethod * opMethod, ILMethod * trueMethod, ILMethod * falseMethod);
extern ILNode *ILNode_UserLogicalOr_create(ILNode * expr1, ILNode * expr2, ILMethod * opMethod, ILMethod * trueMethod, ILMethod * falseMethod);
extern ILNode *ILNode_Add_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Sub_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Mul_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Div_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Rem_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_And_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Or_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Xor_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Shl_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Shr_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_UShr_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Eq_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Ne_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Lt_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Le_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Gt_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Ge_create(ILNode * expr1, ILNode * expr2);
extern ILNode *ILNode_Conditional_create(ILNode * expr1, ILNode * expr2, ILNode * expr3);
extern ILNode *ILNode_AssignAdd_create(ILNode * assign);
extern ILNode *ILNode_AssignSub_create(ILNode * assign);
extern ILNode *ILNode_AssignMul_create(ILNode * assign);
extern ILNode *ILNode_AssignDiv_create(ILNode * assign);
extern ILNode *ILNode_AssignRem_create(ILNode * assign);
extern ILNode *ILNode_AssignAnd_create(ILNode * assign);
extern ILNode *ILNode_AssignOr_create(ILNode * assign);
extern ILNode *ILNode_AssignXor_create(ILNode * assign);
extern ILNode *ILNode_AssignShl_create(ILNode * assign);
extern ILNode *ILNode_AssignShr_create(ILNode * assign);
extern ILNode *ILNode_AssignUShr_create(ILNode * assign);
extern ILNode *ILNode_As_create(ILNode * expr, ILClass * classInfo, int isEnumType);
extern ILNode *ILNode_Is_create(ILNode * expr, ILClass * classInfo, int isEnumType);
extern ILNode *ILNode_Box_create(ILNode * expr, ILClass * classInfo, int isEnumType);
extern ILNode *ILNode_Unbox_create(ILNode * expr, ILClass * classInfo, int isEnumType, ILMachineType machineType);
extern ILNode *ILNode_List_create(void);
extern ILNode *ILNode_Empty_create(void);
extern ILNode *ILNode_If_create(ILNode * expr, ILNode * thenClause, ILNode * elseClause);
extern ILNode *ILNode_Break_create(void);
extern ILNode *ILNode_LabelledBreak_create(char * name);
extern ILNode *ILNode_Continue_create(void);
extern ILNode *ILNode_LabelledContinue_create(char * name);
extern ILNode *ILNode_Return_create(void);
extern ILNode *ILNode_ReturnExpr_create(ILNode * expr);
extern ILNode *ILNode_Goto_create(char * name);
extern ILNode *ILNode_GotoLabel_create(char * name);
extern ILNode *ILNode_GotoCase_create(ILNode * expr);
extern ILNode *ILNode_GotoDefault_create(void);
extern ILNode *ILNode_NewScope_create(ILNode * stmt);
extern ILNode *ILNode_SwitchSection_create(ILNode * caseList, ILNode * stmt);
extern ILNode *ILNode_CaseLabel_create(ILNode * expr);
extern ILNode *ILNode_DefaultLabel_create(void);
extern ILNode *ILNode_Throw_create(void);
extern ILNode *ILNode_ThrowExpr_create(ILNode * expr);
extern ILNode *ILNode_Try_create(ILNode * stmt, ILNode * catchClauses, ILNode * finallyClause);
extern ILNode *ILNode_CatchClause_create(ILNode * type, char * name, ILNode * nameNode, ILNode * stmt);
extern ILNode *ILNode_FinallyClause_create(ILNode * stmt);
extern ILNode *ILNode_Lock_create(ILNode * expr, ILNode * stmt);
extern ILNode *ILNode_LocalVarDeclaration_create(ILNode * type, ILNode * varNames);
extern ILNode *ILNode_LocalConstDeclaration_create(ILNode * type, ILNode * decls);
extern ILNode *ILNode_LineInfo_create(ILNode * stmt);
extern ILNode *ILNode_EventAddOrRemove_create(ILNode * thisExpr, ILNode * delegateExpr, ILMethod * method);
extern ILNode *ILNode_Compound_create(void);
extern ILNode *ILNode_SwitchSectList_create(void);
extern ILNode *ILNode_CaseList_create(void);
extern ILNode *ILNode_CatchClauses_create(void);
extern ILNode *ILNode_While_create(ILNode * cond, ILNode * stmt);
extern ILNode *ILNode_Do_create(ILNode * stmt, ILNode * cond);
extern ILNode *ILNode_For_create(ILNode * init, ILNode * cond, ILNode * incr, ILNode * stmt);
extern ILNode *ILNode_Foreach_create(ILNode * type, char * varName, ILNode * varNameNode, ILNode * expr, ILNode * stmt);
extern ILNode *ILNode_ForeachString_create(ILNode * expr, ILNode * stmt, unsigned long varIndex, ILMachineType varType);
extern ILNode *ILNode_ForeachCollection_create(ILNode * doCast, ILNode * expr, ILNode * stmt, ILType * arrayType, unsigned long varIndex, ILMachineType varType, ILType * enumeratorType, ILMethod * getEnumerator, ILMethod * moveNext, ILMethod * getCurrent);
extern ILNode *ILNode_Switch_create(ILNode * expr, ILNode * sections, ILNode * body);
extern ILNode *ILNode_ClassDefn_create(ILNode * attributes, ILUInt32 modifiers, char * name, char * namespace, ILNode * namespaceNode, ILNode * typeFormals, ILNode * baseClass, ILNode * body, ILNode * staticCtors);
extern ILNode *ILNode_ScopeChange_create(ILScope * scope, ILNode * body);
extern ILNode *ILNode_FieldDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * fieldDeclarators);
extern ILNode *ILNode_FieldDeclarator_create(ILNode * name, ILNode * initializer);
extern ILNode *ILNode_EventDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * eventDeclarators);
extern ILNode *ILNode_EventDeclarator_create(ILNode * fieldDeclarator, ILNode * addAccessor, ILNode * removeAccessor);
extern ILNode *ILNode_ProxyDeclaration_create(ILMethod * interfaceMethod, ILMethod * proxyReplacement);
extern ILNode *ILNode_MethodDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * name, ILNode * params, ILNode * body);
extern ILNode *ILNode_PropertyDeclaration_create(ILNode * attributes, ILUInt32 modifiers, ILNode * type, ILNode * name, ILNode * params, ILNode * getAccessor, ILNode * setAccessor, ILUInt32 getsetFlags);
extern ILNode *ILNode_EnumMemberDeclaration_create(ILNode * attributes, ILNode * name, ILNode * value);
extern ILNode *ILNode_DelegateMemberDeclaration_create(ILNode * returnType, ILNode * params);
extern ILNode *ILNode_FormalParameter_create(ILNode * attributes, ILParameterModifier pmod, ILNode * type, ILNode * name);
extern ILNode *ILNode_AttributeTree_create(ILNode * sections);
extern ILNode *ILNode_AttributeSection_create(ILAttrTargetType type, ILNode * target, ILNode * attrs);
extern ILNode *ILNode_Attribute_create(ILNode * name, ILNode * args);
extern ILNode *ILNode_AttrArgs_create(ILNode * positionalArgs, ILNode * namedArgs);
extern ILNode *ILNode_NamedArg_create(ILNode * name, ILNode * value);
extern int ILRelational_EvalOp(ILGenInfo * info, ILNode_Relational * node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2);
extern void ILRelational_ElseOp(ILGenInfo * info, ILNode_Relational * node, ILMachineType commonType, ILLabel * label);
extern void JavaRelational_ApplyOp(ILGenInfo * info, ILNode_Relational * node, ILMachineType commonType);
extern void JavaRelational_ElseOp(ILGenInfo * info, ILNode_Relational * node, ILMachineType commonType, ILLabel * label);
extern void JavaNot_ApplyOp(ILGenInfo * info, ILMachineType commonType);
extern int ILShift_EvalOp(ILGenInfo * info, ILNode_BinaryShift * node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2);
extern void JavaBinary_ApplyOp(ILGenInfo * info, ILNode_BinaryArith * node, ILMachineType commonType);
extern void JavaNegate_ApplyOp(ILGenInfo * info, ILMachineType commonType);
extern void ILRelational_ApplyOp(ILGenInfo * info, ILNode_Relational * node, ILMachineType commonType);
extern void ILRelational_ThenOp(ILGenInfo * info, ILNode_Relational * node, ILMachineType commonType, ILLabel * label);
extern void JavaRelational_ThenOp(ILGenInfo * info, ILNode_Relational * node, ILMachineType commonType, ILLabel * label);
extern void JavaShift_ApplyOp(ILGenInfo * info, ILNode_BinaryShift * node, ILMachineType commonType);
extern int ILNot_EvalOp(ILGenInfo * info, ILMachineType commonType, ILEvalValue * value);
extern void JavaStackThen(ILGenInfo * info, ILLabel * label, ILMachineType type);
extern void ILDecrement_ApplyOp(ILGenInfo * info, ILMachineType commonType);
extern void ILBitwise_ApplyOp(ILGenInfo * info, ILNode_BinaryBitwise * node, ILMachineType commonType);
extern void ILShift_ApplyOp(ILGenInfo * info, ILNode_BinaryShift * node, ILMachineType commonType);
extern void ILNodeStackElse(ILGenInfo * info, ILLabel * label, ILMachineType type);
extern void ILBinary_ApplyOp(ILGenInfo * info, ILNode_BinaryArith * node, ILMachineType commonType);
extern void ILNegate_ApplyOp(ILGenInfo * info, ILNode_Neg * node, ILMachineType commonType);
extern int ILBitwise_EvalOp(ILGenInfo * info, ILNode_BinaryBitwise * node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2);
extern int ILGenCastConst(ILGenInfo * info, ILEvalValue * value, ILMachineType fromType, ILMachineType toType);
extern void JavaDec_ApplyOp(ILGenInfo * info, ILMachineType commonType);
extern int ILBinary_EvalOp(ILGenInfo * info, ILNode_BinaryArith * node, ILMachineType commonType, ILEvalValue * value1, ILEvalValue * value2);
extern int ILNegate_EvalOp(ILGenInfo * info, ILMachineType commonType, ILEvalValue * value);
extern void ILIncrement_ApplyOp(ILGenInfo * info, ILMachineType commonType);
extern void JavaInc_ApplyOp(ILGenInfo * info, ILMachineType commonType);
extern void JavaGenCast(ILGenInfo * info, ILMachineType fromType, ILMachineType toType);
extern void ILNot_ApplyOp(ILGenInfo * info, ILMachineType commonType);
extern void ILGenCast(ILGenInfo * info, ILMachineType fromType, ILMachineType toType);
extern void JavaBitwise_ApplyOp(ILGenInfo * info, ILNode_BinaryBitwise * node, ILMachineType commonType);
extern void ILNodeStackThen(ILGenInfo * info, ILLabel * label, ILMachineType type);
extern void JavaStackElse(ILGenInfo * info, ILLabel * label, ILMachineType type);
#ifndef yykind
#define yykind(node__) ((node__)->kind__)
#endif

#ifndef yykindname
#define yykindname(node__) ((node__)->vtable__->name__)
#endif

#ifndef yykindof
#define yykindof(type__) (type__##_kind)
#endif

#ifndef yyisa
extern int yyisa__(const void *vtable__, int kind__);
#define yyisa(node__,type__) \
	(yyisa__((node__)->vtable__, (type__##_kind)))
#endif

#ifndef yygetfilename
#define yygetfilename(node__) ((node__)->filename__)
#endif

#ifndef yygetlinenum
#define yygetlinenum(node__) ((node__)->linenum__)
#endif

#ifndef yysetfilename
#define yysetfilename(node__, value__) \
	((node__)->filename__ = (value__))
#endif

#ifndef yysetlinenum
#define yysetlinenum(node__, value__) \
	((node__)->linenum__ = (value__))
#endif

#ifndef yytracklines_declared
extern char *yycurrfilename(void);
extern long yycurrlinenum(void);
#define yytracklines_declared 1
#endif

#ifndef yynodeops_declared
extern void yynodeinit(void);
extern void *yynodealloc(unsigned int size__);
extern int yynodepush(void);
extern void yynodepop(void);
extern void yynodeclear(void);
extern void yynodefailed(void);
#define yynodeops_declared 1
#endif

#ifdef __cplusplus
};
#endif

#line 35 "cg_nodes.tc"

#include <codegen/cg_varusage.h>
#include <codegen/cg_gen.h>
#include <codegen/cg_output.h>
#include <codegen/cg_utils.h>
#line 127 "cg_nodes.tc"


struct _tagILEvalValue
{
	ILMachineType		valueType;
	union
	{
		ILInt32			i4Value;
		ILInt64			i8Value;
		ILFloat			r4Value;
		ILDouble		r8Value;
		ILDecimal		decValue;
		void		   *oValue;
		struct
		{
			char	   *str;
			int			len;
		}				strValue;
	} un;

};

#line 154 "cg_nodes.tc"


struct _tagILSwitchValue
{
	ILEvalValue			value;
	ILNode             *caseLabel;
	ILNode             *section;

};

#line 1540 "cg_lvalue.tc"


/*
 * Create a simple identifier node.  "name" must be intern'ed.
 */
ILNode *ILQualIdentSimple(char *name);

/*
 * Create a two-name identifier node.  The names do not need
 * to be intern'ed.
 */
ILNode *ILQualIdentTwo(const char *name1, const char *name2);

/*
 * Convert a qualified identifier node into a full string name,
 * and intern the string.  Returns NULL if not an identifier node.
 * If "asmForm" is non-zero, then quote the name to put it into
 * a form suitable for assembly code.
 */
char *ILQualIdentName(ILNode *node, int asmForm);

/*
 *  Very similar to ILQualIdentName, but only recognizes
 *  MemberAccess and Identifier nodes.  Plus it doesn't care
 *  about assembly code.
 *
 *  Not sensible, but documented.  -JPS
 */
char *ILMemberAccessName(ILNode *node);

/*
 * Append two qualified identifier strings, with '.' between them.
 */
char *ILQualIdentAppend(char *name1, char *name2);

/*
 * Determine if a node is a qualified identifier.
 */
int ILIsQualIdent(ILNode *node);

#line 1273 "cg_misc.tc"


/*
 * Prepare a "this" expression for use in a method invocation
 * or field access expression.  Returns a temporary variable
 * reference, which should be freed with "ILGenFreeThisVar".
 */
unsigned ILGenPrepareForThisAccess(ILGenInfo *info, ILNode *thisExpr,
							       ILClass *classInfo, int isLoadOnly);

/*
 * Free the temporary variable used for "this" access.
 */
void ILGenFreeThisVar(ILGenInfo *info, unsigned tempVar);

#line 28 "cg_ainit.tc"


/*
 * Get the length of an array initialization expression list
 * at a particular dimension level.
 */
ILUInt32 ILGetArrayInitLength(ILNode *list, int dimension);

/*
 * Determine if an array initialization expression has the
 * correct shape for an array type.  If it does, then embed
 * the array type into it.
 */
int ILArrayInitShapeOK(ILGenInfo *info, ILNode *node, ILType *type);

/*
 * Flush nested class definitions that are needed for
 * static array initialization.  Call this at the end
 * of writing out the code for a method.
 */
void ILArrayInitFlush(ILGenInfo *info);

#line 109 "cg_stmt.tc"


/*
 * Add a node to a list.
 */
void _ILNode_List_Add(ILNode *list, ILNode *node);
#define	ILNode_List_Add(list,node)	\
			(_ILNode_List_Add((ILNode *)(list), (ILNode *)(node)))

/*
 * Control structure for iterators.
 */
typedef struct
{
	ILNode_List *list;
	int		     posn;
	ILNode     **last;

} ILNode_ListIter;

/*
 * Initialize a list iterator.
 */
void _ILNode_ListIter_Init(ILNode_ListIter *iter, ILNode *node);
#define	ILNode_ListIter_Init(iter,node)	\
				(_ILNode_ListIter_Init((iter), (ILNode *)(node)))

/*
 * Get the next node from a list iterator.  Returns NULL if no more nodes.
 */
ILNode *ILNode_ListIter_Next(ILNode_ListIter *iter);

/*
 * Get the length of a list.
 */
int ILNode_List_Length(ILNode *list);

/*
 * Create a compound statement node from two other nodes.
 */
ILNode *ILNode_Compound_CreateFrom(ILNode *left, ILNode *right);

/*
 * Flags for "ILNode_EndsInReturnImpl".
 */
#define	IL_ENDS_IN_RETURN				1
#define	IL_ENDS_IN_EMPTY				2
#define	IL_ENDS_IN_BREAK				4
#define	IL_ENDS_IN_CONTINUE				8
#define	IL_ENDS_IN_GOTO					16
#define	IL_ENDS_IN_THROW				32
#define	IL_ENDS_IN_CONTAINED_BREAK		64
#define	IL_ENDS_IN_CONTAINED_CONTINUE	128
#define	IL_ENDS_IN_CONTAINED_MASK		(IL_ENDS_IN_CONTAINED_BREAK | \
										 IL_ENDS_IN_CONTAINED_CONTINUE)

/*
 * Determine if a statement list ends in a flow control change statement.
 */
int ILNodeEndsInFlowChange(ILNode *stmt,ILGenInfo *genInfo);

/*
 * Add a break/continue label to a loop or switch statement.
 */
void ILNodeAddLabel(ILNode *stmt, char *name);

#line 27 "jv_nodes.tc"

#include "il_jopcodes.h"
#include <codegen/jv_output.h>
#line 568 "jv_misc.tc"


/*
 * Box a value on the stack into an object.
 */
void JavaBoxValue(ILGenInfo *info, ILMachineType type,
				  int isEnumType, ILClass *classInfo);

/*
 * Unbox a value onto the stack.
 */
ILMachineType JavaUnboxValue(ILGenInfo *info, ILMachineType subExprType,
					         ILMachineType type, int isEnumType,
					         int isRightType, ILClass *classInfo);

#line 1560 "jv_misc.tc"


/*
 * Prepare a "this" expression for use in a method invocation
 * or field access expression.
 */
void JavaPrepareForThisAccess(ILGenInfo *info, ILNode *thisExpr,
							  ILClass *classInfo);

#line 8507 "cg_nodes.h"
#endif
