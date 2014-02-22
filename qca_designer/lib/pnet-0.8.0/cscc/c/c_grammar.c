/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER_CONSTANT = 259,
     FLOAT_CONSTANT = 260,
     IMAG_CONSTANT = 261,
     STRING_LITERAL = 262,
     WSTRING_LITERAL = 263,
     CS_STRING_LITERAL = 264,
     TYPE_NAME = 265,
     NAMESPACE_NAME = 266,
     PTR_OP = 267,
     INC_OP = 268,
     DEC_OP = 269,
     LEFT_OP = 270,
     RIGHT_OP = 271,
     LE_OP = 272,
     GE_OP = 273,
     EQ_OP = 274,
     NE_OP = 275,
     AND_OP = 276,
     OR_OP = 277,
     MUL_ASSIGN_OP = 278,
     DIV_ASSIGN_OP = 279,
     MOD_ASSIGN_OP = 280,
     ADD_ASSIGN_OP = 281,
     SUB_ASSIGN_OP = 282,
     LEFT_ASSIGN_OP = 283,
     RIGHT_ASSIGN_OP = 284,
     AND_ASSIGN_OP = 285,
     XOR_ASSIGN_OP = 286,
     OR_ASSIGN_OP = 287,
     COLON_COLON_OP = 288,
     K_ASM = 289,
     K_AUTO = 290,
     K_BREAK = 291,
     K_CASE = 292,
     K_CHAR = 293,
     K_CONST = 294,
     K_CONTINUE = 295,
     K_DEFAULT = 296,
     K_DO = 297,
     K_DOUBLE = 298,
     K_ELSE = 299,
     K_ENUM = 300,
     K_EXTERN = 301,
     K_FLOAT = 302,
     K_FOR = 303,
     K_GOTO = 304,
     K_IF = 305,
     K_INLINE = 306,
     K_INT = 307,
     K_LONG = 308,
     K_REGISTER = 309,
     K_RETURN = 310,
     K_SHORT = 311,
     K_SIGNED = 312,
     K_SIZEOF = 313,
     K_STATIC = 314,
     K_STRUCT = 315,
     K_SWITCH = 316,
     K_TYPEDEF = 317,
     K_TYPEOF = 318,
     K_UNION = 319,
     K_UNSIGNED = 320,
     K_VOID = 321,
     K_VOLATILE = 322,
     K_WHILE = 323,
     K_ELIPSIS = 324,
     K_VA_LIST = 325,
     K_VA_START = 326,
     K_VA_ARG = 327,
     K_VA_END = 328,
     K_SETJMP = 329,
     K_ALLOCA = 330,
     K_ATTRIBUTE = 331,
     K_BOOL = 332,
     K_WCHAR = 333,
     K_FUNCTION = 334,
     K_FUNC = 335,
     K_INT64 = 336,
     K_UINT = 337,
     K_TRY = 338,
     K_CATCH = 339,
     K_FINALLY = 340,
     K_THROW = 341,
     K_CHECKED = 342,
     K_UNCHECKED = 343,
     K_NULL = 344,
     K_TRUE = 345,
     K_FALSE = 346,
     K_LOCK = 347,
     K_USING = 348,
     K_NAMESPACE = 349,
     K_NEW = 350,
     K_DELETE = 351,
     K_CS_TYPEOF = 352,
     K_BOX = 353,
     K_DECLSPEC = 354,
     K_GC = 355,
     K_NOGC = 356
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER_CONSTANT 259
#define FLOAT_CONSTANT 260
#define IMAG_CONSTANT 261
#define STRING_LITERAL 262
#define WSTRING_LITERAL 263
#define CS_STRING_LITERAL 264
#define TYPE_NAME 265
#define NAMESPACE_NAME 266
#define PTR_OP 267
#define INC_OP 268
#define DEC_OP 269
#define LEFT_OP 270
#define RIGHT_OP 271
#define LE_OP 272
#define GE_OP 273
#define EQ_OP 274
#define NE_OP 275
#define AND_OP 276
#define OR_OP 277
#define MUL_ASSIGN_OP 278
#define DIV_ASSIGN_OP 279
#define MOD_ASSIGN_OP 280
#define ADD_ASSIGN_OP 281
#define SUB_ASSIGN_OP 282
#define LEFT_ASSIGN_OP 283
#define RIGHT_ASSIGN_OP 284
#define AND_ASSIGN_OP 285
#define XOR_ASSIGN_OP 286
#define OR_ASSIGN_OP 287
#define COLON_COLON_OP 288
#define K_ASM 289
#define K_AUTO 290
#define K_BREAK 291
#define K_CASE 292
#define K_CHAR 293
#define K_CONST 294
#define K_CONTINUE 295
#define K_DEFAULT 296
#define K_DO 297
#define K_DOUBLE 298
#define K_ELSE 299
#define K_ENUM 300
#define K_EXTERN 301
#define K_FLOAT 302
#define K_FOR 303
#define K_GOTO 304
#define K_IF 305
#define K_INLINE 306
#define K_INT 307
#define K_LONG 308
#define K_REGISTER 309
#define K_RETURN 310
#define K_SHORT 311
#define K_SIGNED 312
#define K_SIZEOF 313
#define K_STATIC 314
#define K_STRUCT 315
#define K_SWITCH 316
#define K_TYPEDEF 317
#define K_TYPEOF 318
#define K_UNION 319
#define K_UNSIGNED 320
#define K_VOID 321
#define K_VOLATILE 322
#define K_WHILE 323
#define K_ELIPSIS 324
#define K_VA_LIST 325
#define K_VA_START 326
#define K_VA_ARG 327
#define K_VA_END 328
#define K_SETJMP 329
#define K_ALLOCA 330
#define K_ATTRIBUTE 331
#define K_BOOL 332
#define K_WCHAR 333
#define K_FUNCTION 334
#define K_FUNC 335
#define K_INT64 336
#define K_UINT 337
#define K_TRY 338
#define K_CATCH 339
#define K_FINALLY 340
#define K_THROW 341
#define K_CHECKED 342
#define K_UNCHECKED 343
#define K_NULL 344
#define K_TRUE 345
#define K_FALSE 346
#define K_LOCK 347
#define K_USING 348
#define K_NAMESPACE 349
#define K_NEW 350
#define K_DELETE 351
#define K_CS_TYPEOF 352
#define K_BOX 353
#define K_DECLSPEC 354
#define K_GC 355
#define K_NOGC 356




/* Copy the first part of user declarations.  */
#line 1 "c_grammar.y"

/*
 * c_grammar.y - Input file for yacc that defines the syntax of the C language.
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

/* Rename the lex/yacc symbols to support multiple parsers */
#include "c_rename.h"

#include <stdio.h>
#include <cscc/c/c_internal.h>
#include "il_dumpasm.h"

#define	YYERROR_VERBOSE

/*
 * Current context.
 */
static char *functionName = "";
static ILType *currentStruct = 0;
static ILType *currentEnum = 0;
static ILInt32 currentEnumValue = 0;
static ILNode *initializers = 0;
static int usedGlobalVar = 0;
static unsigned long globalInitNum = 0;
static int inhibitRollBack = 0;

/*
 * Imports from the lexical analyser.
 */
extern int yylex(void);
#ifdef YYTEXT_POINTER
extern char *c_text;
#else
extern char c_text[];
#endif

static void yyerror(char *msg)
{
	CCPluginParseError(msg, c_text);
}

void CInhibitNodeRollback(void)
{
	inhibitRollBack = 1;
}

/*
 * Fix up an identifier node that was previously detected as
 * undeclared, but we weren't sure if it was going to be used
 * as a normal identifier or a forward-referenced function name.
 */
static ILNode *FixIdentifierNode(ILNode *node, int functionRef)
{
	char *name;

	/* Bail out if the node is not an identifier */
	if(!yyisa(node, ILNode_Identifier))
	{
		return node;
	}

	/* Extract the name from the identifier node */
	name = ILQualIdentName(node, 0);

	/* Report an error if not a function reference */
	if(!functionRef)
	{
		if(functionName && functionName[0] != '\0')
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				_("`%s' undeclared (first use in this function)"), name);
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				_("(Each undeclared identifier is reported only once"));
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				_("for each function it appears in.)"));
			CScopeAddUndeclared(name);
		}
		else
		{
			CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				_("`%s' undeclared"), name);
		}
		return ILNode_Error_create();
	}

	/* Create a forward-reference to the function, which will be
	   fixed up during semantic analysis to contain the signature */
	return ILNode_FunctionRef_create(name, ILType_Invalid);
}

/*
 * Copy the contents of one parameter declaration list to another.
 */
static void CopyParamDecls(ILNode *dest, ILNode *src)
{
	if(yyisa(src, ILNode_List))
	{
		ILNode_ListIter iter;
		ILNode *node;
		ILNode_ListIter_Init(&iter, src);
		while((node = ILNode_ListIter_Next(&iter)) != 0)
		{
			ILNode_List_Add(dest, node);
		}
	}
	else
	{
		ILNode_List_Add(dest, src);
	}
}

/*
 * Process a "struct" or "union" field.
 */
static void ProcessField(CDeclSpec spec, CDeclarator decl)
{
	ILType *type;

	/* Get the final type for the declarator */
	type = CDeclFinalize(&CCCodeGen, spec, decl, 0, 0);

	/* Define the field within the current "struct" or "union" */
	if(!CTypeDefineField(&CCCodeGen, currentStruct, decl.name, type))
	{
		CCErrorOnLine(yygetfilename(decl.node), yygetlinenum(decl.node),
					  _("storage size of `%s' is not known"), decl.name);
	}
}

/*
 * Report an invalid bit field type error.
 */
static void BitFieldInvalidType(char *name, ILNode *node)
{
	if(name)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("bit-field `%s' has invalid type"), name);
	}
	else
	{
		CCError(_("bit-field has invalid type"));
	}
}

/*
 * Report a zero-width bit field error.
 */
static void BitFieldZeroWidth(char *name, ILNode *node)
{
	if(name)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("zero width for bit-field `%s'"), name);
	}
	else
	{
		CCError(_("zero width for bit-field"));
	}
}

/*
 * Report bit field size warning.
 */
static void BitFieldMaxSize(char *name, ILNode *node)
{
	if(name)
	{
		CCWarningOnLine(yygetfilename(node), yygetlinenum(node),
					    _("width of `%s' exceeds its type"), name);
	}
	else
	{
		CCWarning(_("width of bit-field exceeds its type"));
	}
}

/*
 * Process a "struct" or "union" bit field.
 */
static void ProcessBitField(CDeclSpec spec, CDeclarator decl, ILUInt32 size)
{
	ILType *type;
	ILType *baseType;
	ILType *nonEnumType;
	ILUInt32 maxSize;
	int typeInvalid;

	/* Get the final type for the declarator */
	type = CDeclFinalize(&CCCodeGen, spec, decl, 0, 0);

	/* Get the base type, removing prefixes and enum wrappers */
	baseType = ILTypeStripPrefixes(type);
	nonEnumType = ILTypeGetEnumType(baseType);
	if(nonEnumType != baseType)
	{
		baseType = nonEnumType;
		if(CTypeIsConst(type))
		{
			baseType = CTypeAddConst(&CCCodeGen, baseType);
		}
		if(CTypeIsVolatile(type))
		{
			baseType = CTypeAddVolatile(&CCCodeGen, baseType);
		}
		type = baseType;
		baseType = ILTypeStripPrefixes(type);
	}

	/* Make sure that the type is integer and that the size is in range */
	typeInvalid = 0;
	if(ILType_IsPrimitive(baseType))
	{
		switch(ILType_ToElement(baseType))
		{
			case IL_META_ELEMTYPE_I1:
			case IL_META_ELEMTYPE_U1:
			{
				maxSize = 8;
			}
			break;

			case IL_META_ELEMTYPE_I2:
			case IL_META_ELEMTYPE_U2:
			case IL_META_ELEMTYPE_CHAR:
			{
				maxSize = 16;
			}
			break;

			case IL_META_ELEMTYPE_I4:
			case IL_META_ELEMTYPE_U4:
			{
				maxSize = 32;
			}
			break;

			case IL_META_ELEMTYPE_I8:
			case IL_META_ELEMTYPE_U8:
			{
				maxSize = 64;
			}
			break;

			default:
			{
				BitFieldInvalidType(decl.name, decl.node);
				type = ILType_UInt64;
				maxSize = 64;
				typeInvalid = 1;
			}
			break;
		}
	}
	else
	{
		BitFieldInvalidType(decl.name, decl.node);
		type = ILType_UInt64;
		maxSize = 64;
		typeInvalid = 1;
	}
	if(!size)
	{
		BitFieldZeroWidth(decl.name, decl.node);
		size = 1;
	}
	else if(size > maxSize)
	{
		if(!typeInvalid)
		{
			BitFieldMaxSize(decl.name, decl.node);
		}
		size = maxSize;
	}

	/* Define the bit field within the current "struct" or "union" */
	if(!CTypeDefineBitField(&CCCodeGen, currentStruct, decl.name,
							type, size, maxSize))
	{
		CCErrorOnLine(yygetfilename(decl.node), yygetlinenum(decl.node),
					  _("storage size of `%s' is not known"), decl.name);
	}
}

/*
 * Build an appropriate assignment statement for initializing a variable.
 */
static ILNode *BuildAssignInit(ILNode *var, ILNode *init, ILType *type)
{
	ILNode *stmt;

	if(yyisa(init, ILNode_CArrayInit))
	{
		if(CTypeIsArray(type))
		{
			stmt = ILNode_CAssignArray_create(var, init);
		}
		else if(CTypeIsStruct(type) || CTypeIsUnion(type))
		{
			stmt = ILNode_CAssignStruct_create(var, init);
		}
		else
		{
			stmt = ILNode_Assign_create(var, init);
		}
	}
	else if(CTypeIsArray(type) && yyisa(init, ILNode_CString))
	{
		stmt = ILNode_CAssignArray_create(var, init);
	}
	else if(CTypeIsArray(type) && yyisa(init, ILNode_CWString))
	{
		stmt = ILNode_CAssignArray_create(var, init);
	}
	else
	{
		stmt = ILNode_Assign_create(var, init);
	}

	return stmt;
}

/*
 * Add a global initializer statement to the pending list.
 */
static void AddInitializer(char *name, ILNode *node, ILType *type, ILNode *init)
{
	ILNode *stmt;

	/* Build the initialization statement */
	stmt = ILNode_CGlobalVar_create(name, type, CTypeDecay(&CCCodeGen, type));
	CGenCloneLine(stmt, node);
	stmt = BuildAssignInit(stmt, init, type);
	CGenCloneLine(stmt, init);

	/* Add the statement to the pending list */
	if(!initializers)
	{
		initializers = ILNode_List_create();
	}
	ILNode_List_Add(initializers, stmt);
}

/*
 * Report a redeclaration error.
 */
static void ReportRedeclared(const char *name, ILNode *node, void *data)
{
	CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
				  _("redeclaration of `%s'"), name);
	node = CScopeGetNode(data);
	if(node)
	{
		CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  _("`%s' previously declared here"), name);
	}
}

/*
 * Process attributes that were attached to a function definition.
 */
static void ProcessFunctionAttributes(CDeclSpec spec, CDeclarator decl,
									  ILType *signature)
{
	const char *arg;
	const char *name;
	ILUInt32 flags;
	int isPrivate = ((spec.specifiers & C_SPEC_STATIC) != 0);

	/* Flush any initializers that are pending */
	if(initializers)
	{
		CFunctionFlushInits(&CCCodeGen, initializers);
		initializers = 0;
	}

	/* Check for strong and weak alias definitions */
	if((arg = CAttrGetString(decl.attrs, "alias", "__alias__")) != 0)
	{
		if(CAttrPresent(decl.attrs, "weak", "__weak__"))
		{
			CFunctionWeakAlias(&CCCodeGen, decl.name, decl.node,
							   signature, arg, isPrivate);
		}
		else
		{
			CFunctionStrongAlias(&CCCodeGen, decl.name, decl.node,
								 signature, arg, isPrivate);
		}
		return;
	}

	/* Check for PInvoke definitions */
	if((arg = CAttrGetString(decl.attrs, "pinvoke", "__pinvoke__")) != 0)
	{
		name = CAttrGetString(decl.attrs, "name", "__name__");
		if(CAttrPresent(decl.attrs, "ansi", "__ansi__"))
		{
			flags = IL_META_PINVOKE_CHAR_SET_ANSI;
		}
		else if(CAttrPresent(decl.attrs, "unicode", "__unicode__"))
		{
			flags = IL_META_PINVOKE_CHAR_SET_UNICODE;
		}
		else if(CAttrPresent(decl.attrs, "auto", "__auto__"))
		{
			flags = IL_META_PINVOKE_CHAR_SET_AUTO;
		}
		else
		{
			flags = IL_META_PINVOKE_CHAR_SET_NOT_SPEC;
		}
		if(CAttrPresent(decl.attrs, "nomangle", "__nomangle__"))
		{
			flags |= IL_META_PINVOKE_NO_MANGLE;
		}
		if(CAttrPresent(decl.attrs, "preservesig", "__preservesig__"))
		{
			flags |= IL_META_PINVOKE_OLE;
		}
		if(CAttrPresent(decl.attrs, "lasterr", "__lasterr__"))
		{
			flags |= IL_META_PINVOKE_SUPPORTS_LAST_ERROR;
		}
		if(CAttrPresent(decl.attrs, "winapi", "__winapi__"))
		{
			flags |= IL_META_PINVOKE_CALL_CONV_WINAPI;
		}
		else if(CAttrPresent(decl.attrs, "cdecl", "__cdecl__"))
		{
			flags |= IL_META_PINVOKE_CALL_CONV_CDECL;
		}
		else if(CAttrPresent(decl.attrs, "stdcall", "__stdcall__"))
		{
			flags |= IL_META_PINVOKE_CALL_CONV_STDCALL;
		}
		else if(CAttrPresent(decl.attrs, "thiscall", "__thiscall__"))
		{
			flags |= IL_META_PINVOKE_CALL_CONV_THISCALL;
		}
		else if(CAttrPresent(decl.attrs, "fastcall", "__fastcall__"))
		{
			flags |= IL_META_PINVOKE_CALL_CONV_FASTCALL;
		}
		if((flags & IL_META_PINVOKE_CALL_CONV_MASK) == 0)
		{
			/* Default to a calling convention of "cdecl" */
			flags |= IL_META_PINVOKE_CALL_CONV_CDECL;
		}
		CFunctionPInvoke(&CCCodeGen, decl.name, decl.node,
						 signature, arg, name, flags, isPrivate);
		return;
	}
}

/*
 * Process a local or global function declaration.
 */
static void ProcessFunctionDeclaration(CDeclSpec spec, CDeclarator decl,
							   		   ILNode *init, ILNode **list)
{
	ILType *signature;
	void *data;

	/* We cannot use initializers with function declarations */
	if(init != 0)
	{
		CCErrorOnLine(yygetfilename(decl.node), yygetlinenum(decl.node),
					  _("function `%s' is initialized like a variable"),
					  decl.name);
	}

	/* Build the final function signature */
	signature = CDeclFinalize(&CCCodeGen, spec, decl, 0, 0);

	/* See if there is already something registered with this name */
	data = CScopeLookup(decl.name);
	if(data)
	{
		if(CScopeGetKind(data) == C_SCDATA_FUNCTION ||
		   CScopeGetKind(data) == C_SCDATA_FUNCTION_FORWARD ||
		   CScopeGetKind(data) == C_SCDATA_FUNCTION_INFERRED)
		{
			/* The previous definition was an ANSI prototype */
			if(decl.isKR)
			{
				if(!CTypeIsIdentical
						(CTypeGetReturn(signature),
						 CTypeGetReturn(CScopeGetType(data))))
				{
					ReportRedeclared(decl.name, decl.node, data);
				}
				else if(decl.attrs)
				{
					ProcessFunctionAttributes(spec, decl, signature);
				}
			}
			else
			{
				if(!CTypeIsIdentical(signature, CScopeGetType(data)))
				{
					ReportRedeclared(decl.name, decl.node, data);
				}
				else if(decl.attrs)
				{
					ProcessFunctionAttributes(spec, decl, signature);
				}
			}
		}
		else if(CScopeGetKind(data) == C_SCDATA_FUNCTION_FORWARD_KR)
		{
			/* The previous definition was a K&R prototype */
			if(!CTypeIsIdentical
					(CTypeGetReturn(signature),
					 CTypeGetReturn(CScopeGetType(data))))
			{
				ReportRedeclared(decl.name, decl.node, data);
			}
			else if(!(decl.isKR))
			{
				/* Convert the K&R prototype into an ANSI prototype */
				CScopeUpdateFunction(decl.name, C_SCDATA_FUNCTION_FORWARD,
									 decl.node, signature);
				if(decl.attrs)
				{
					ProcessFunctionAttributes(spec, decl, signature);
				}
			}
			else if(decl.attrs)
			{
				ProcessFunctionAttributes(spec, decl, signature);
			}
		}
		else
		{
			ReportRedeclared(decl.name, decl.node, data);
		}
		return;
	}

	/* Process any function attributes that are present */
	if(decl.attrs)
	{
		ProcessFunctionAttributes(spec, decl, signature);
	}

	/* Add the function's forward definition to the global scope */
	if(decl.isKR)
	{
		CScopeAddFunctionForward(decl.name, C_SCDATA_FUNCTION_FORWARD_KR,
								 decl.node, signature);
	}
	else
	{
		CScopeAddFunctionForward(decl.name, C_SCDATA_FUNCTION_FORWARD,
								 decl.node, signature);
	}
}

/*
 * Get the size of an array initializer for a particular array type.
 */
static ILUInt32 ArrayInitializerSize(ILType *type, ILNode *init)
{
	/* Handle the string cases first */
	if(yyisa(init, ILNode_CString))
	{
		return (ILUInt32)(((ILNode_CString *)init)->len) + 1;
	}
	else if(yyisa(init, ILNode_CWString))
	{
		return CGenWStringLength
				((((ILNode_CWString *)init)->str),
				 (((ILNode_CWString *)init)->len)) + 1;
	}

	/* If this isn't an array initializer, then bail out */
	if(!yyisa(init, ILNode_CArrayInit))
	{
		CCErrorOnLine(yygetfilename(init), yygetlinenum(init),
					  _("invalid initializer"));
		return 1;
	}

	/* Check for {"foo"}, which sometimes should be just "foo" */
	if(ILNode_List_Length(((ILNode_CArrayInit *)init)->expr) == 1 &&
	   CTypeIsOpenArray(type) &&
	   (ILTypeIdentical(CTypeGetElemType(type), ILType_Int8) ||
	    ILTypeIdentical(CTypeGetElemType(type), ILType_UInt8)))
	{
		ILNode *elem =
			((ILNode_List *)(((ILNode_CArrayInit *)init)->expr))->item1;
		if(yyisa(elem, ILNode_CString))
		{
			return (ILUInt32)(((ILNode_CString *)elem)->len) + 1;
		}
	}
	else if(ILNode_List_Length(((ILNode_CArrayInit *)init)->expr) == 1 &&
	        CTypeIsOpenArray(type) &&
	        ILTypeIdentical(CTypeGetElemType(type), ILType_Char))
	{
		ILNode *elem =
			((ILNode_List *)(((ILNode_CArrayInit *)init)->expr))->item1;
		if(yyisa(elem, ILNode_CWString))
		{
			return CGenWStringLength
					((((ILNode_CWString *)elem)->str),
					 (((ILNode_CWString *)elem)->len)) + 1;
		}
	}

	/* Calculate the size from the node, using the type as a guide */
	return CArrayInitializerSize(type, init);
}

/*
 * Process a local or global declaration.
 */
static void ProcessDeclaration(CDeclSpec spec, CDeclarator decl,
							   ILNode *init, ILNode **list)
{
	ILType *type;
	void *data;
	unsigned index;
	ILNode *assign;
	ILType *prevType;
	ILUInt32 size;
	CTypeLayoutInfo layout;

	/* If there is a parameter list associated with the declarator, then
	   we are declaring a forward function reference, not a variable */
	if(decl.params != 0 ||
	   (spec.baseType != ILType_Invalid && CTypeIsFunction(spec.baseType)))
	{
		if((spec.specifiers & C_SPEC_TYPEDEF) == 0)
		{
			ProcessFunctionDeclaration(spec, decl, init, list);
			return;
		}
	}

	/* Finalize the type that is associated with the declaration */
	type = CDeclFinalize(&CCCodeGen, spec, decl, 0, 0);

	/* See if there is already something in this scope for the name */
	data = CScopeLookupCurrent(decl.name);

	/* Determine what kind of item to declare */
	if((spec.specifiers & C_SPEC_TYPEDEF) != 0)
	{
		/* Define a new type in the local scope */
		if(data)
		{
			ReportRedeclared(decl.name, decl.node, data);
		}
		else
		{
			CScopeAddTypedef(decl.name, type, decl.node);
		}
	}
	else if((spec.specifiers & C_SPEC_EXTERN) != 0)
	{
		/* Declare a forward reference for a global variable */
		if(data)
		{
			if(CScopeGetKind(data) == C_SCDATA_GLOBAL_VAR ||
			   CScopeGetKind(data) == C_SCDATA_GLOBAL_VAR_FORWARD)
			{
				/* We've already seen this variable - this may be a
				   redundant redeclaration */
				prevType = CScopeGetType(data);
				if(!CTypeIsIdentical(type, prevType))
				{
					ReportRedeclared(decl.name, decl.node, data);
				}
				else if(init != 0)
				{
					CCWarningOnLine(yygetfilename(decl.node),
									yygetlinenum(decl.node),
						_("`%s' initialized and declared `extern'"),
						decl.name);
				}
			}
			else
			{
				/* Already declared as a different kind of symbol */
				ReportRedeclared(decl.name, decl.node, data);
			}
			return;
		}

		/* Cannot use initializers with "extern" variables */
		if(init != 0)
		{
			CCWarningOnLine(yygetfilename(decl.node),
							yygetlinenum(decl.node),
							_("`%s' initialized and declared `extern'"),
							decl.name);
		}

		/* Declare the global variable for later */
		if(data)
		{
			CScopeUpdateGlobal(data, C_SCDATA_GLOBAL_VAR_FORWARD,
							   decl.node, type);
		}
		else
		{
			CScopeAddGlobalForward(decl.name, decl.node, type);
		}
	}
	else if(CCurrentScope == CGlobalScope ||
	        (spec.specifiers & C_SPEC_STATIC) != 0)
	{
		/* Declare a global variable */
		if(data)
		{
			if(CScopeGetKind(data) != C_SCDATA_GLOBAL_VAR_FORWARD)
			{
				ReportRedeclared(decl.name, decl.node, data);
				return;
			}
		}

		/* Extend open arrays to the same size as initializers */
		if(CTypeIsOpenArray(type))
		{
			if(init != 0)
			{
				/* Infer the initializer size from the expression */
				size = ArrayInitializerSize(type, init);
			}
			else
			{
				/* If there is no initializer, then change to one element */
				CCWarningOnLine(yygetfilename(decl.node),
								yygetlinenum(decl.node),
								_("array `%s' assumed to have one element"),
								decl.name);
				size = 1;
			}
			type = CTypeCreateArray(&CCCodeGen, CTypeGetElemType(type), size);
		}

		/* Make sure that the type size is fixed, dynamic, or complex */
		CTypeGetLayoutInfo(type, &layout);
		if(layout.category == C_TYPECAT_NO_LAYOUT)
		{
			CCErrorOnLine(yygetfilename(decl.node), yygetlinenum(decl.node),
						  _("storage size of `%s' is not known"), decl.name);
		}

		/* Mark the type for output */
		CTypeMarkForOutput(&CCCodeGen, type);

		/* Declare the global variable in the assembly output stream */
		if(CCCodeGen.asmOutput)
		{
			if((spec.specifiers & C_SPEC_STATIC) != 0)
			{
				fputs(".field private static ", CCCodeGen.asmOutput);
			}
			else
			{
				fputs(".field public static ", CCCodeGen.asmOutput);
			}
			ILDumpType(CCCodeGen.asmOutput, CCCodeGen.image, type,
					   IL_DUMP_QUOTE_NAMES);
			if(layout.category == C_TYPECAT_COMPLEX)
			{
				/* Complex types must be stored by pointer, not value */
				fputs(" *", CCCodeGen.asmOutput);
			}
			putc(' ', CCCodeGen.asmOutput);
			ILDumpIdentifier(CCCodeGen.asmOutput, decl.name, 0,
							 IL_DUMP_QUOTE_NAMES);
			putc('\n', CCCodeGen.asmOutput);
			if((spec.specifiers & C_SPEC_THREAD_SPECIFIC) != 0)
			{
				/* Mark the global variable as thread-specific */
				fputs(".custom instance void System.ThreadStaticAttribute"
					  "::.ctor() = (01 00 00 00)\n", CCCodeGen.asmOutput);
			}
		}

		/* Add the global variable to the current scope */
		if(data)
		{
			CScopeUpdateGlobal(data, C_SCDATA_GLOBAL_VAR, decl.node, type);
		}
		else
		{
			CScopeAddGlobal(decl.name, decl.node, type);
		}

		/* If the type is complex, then we need to allocate memory for it */
		if(layout.category == C_TYPECAT_COMPLEX && CCCodeGen.asmOutput)
		{
			long stackHeight;
			long maxStackHeight;
			fprintf(CCCodeGen.asmOutput, ".method private static specialname "
					"void '.global-%lu' () cil managed\n{\n",
					++globalInitNum);
			fputs(".custom instance void OpenSystem.C.InitializerAttribute"
				  "::.ctor()  = (01 00 00 00)\n", CCCodeGen.asmOutput);
			fputs(".custom instance void OpenSystem.C.InitializerOrderAttribute"
				  "::.ctor(int32)  = (01 00 00 00 00 80 00 00)\n",
				  CCCodeGen.asmOutput);
			stackHeight = CCCodeGen.stackHeight;
			maxStackHeight = CCCodeGen.maxStackHeight;
			CCCodeGen.stackHeight = 0;
			CCCodeGen.maxStackHeight = 0;
			CGenSizeOf(&CCCodeGen, type);
			fputs("\tcall\tnative int [.library]System.Runtime.InteropServices."
				  "Marshal::AllocHGlobal(int32)\n", CCCodeGen.asmOutput);
			fputs("\tstsfld\t", CCCodeGen.asmOutput);
			ILDumpType(CCCodeGen.asmOutput, CCCodeGen.image, type,
					   IL_DUMP_QUOTE_NAMES);
			fputs(" * ", CCCodeGen.asmOutput);
			ILDumpIdentifier(CCCodeGen.asmOutput, decl.name, 0,
							 IL_DUMP_QUOTE_NAMES);
			fputs("\n\tret\n", CCCodeGen.asmOutput);
			fprintf(CCCodeGen.asmOutput, "\t.maxstack %ld\n",
					CCCodeGen.maxStackHeight);
			CCCodeGen.stackHeight = stackHeight;
			CCCodeGen.maxStackHeight = maxStackHeight;
			fputs("}\n", CCCodeGen.asmOutput);
		}

		/* Process the initializer */
		if(init)
		{
			AddInitializer(decl.name, decl.node, type, init);
		}
	}
	else
	{
		/* Declare a local variable in the current scope */
		if(data)
		{
			ReportRedeclared(decl.name, decl.node, data);
		}
		else
		{
			/* Extend open arrays to the same size as initializers */
			if(CTypeIsOpenArray(type))
			{
				if(init != 0)
				{
					/* Infer the initializer size from the expression */
					size = ArrayInitializerSize(type, init);
				}
				else
				{
					/* If there is no initializer, then change to one element */
					CCWarningOnLine(yygetfilename(decl.node),
									yygetlinenum(decl.node),
									_("array `%s' assumed to have one element"),
									decl.name);
					size = 1;
				}
				type = CTypeCreateArray
					(&CCCodeGen, CTypeGetElemType(type), size);
			}

			/* Allocate the local variable */
			index = CGenAllocLocal(&CCCodeGen, type);
			CScopeAddLocal(decl.name, decl.node, index, type);
			if(init)
			{
				if(!(*list))
				{
					*list = ILNode_List_create();
				}
				assign = ILNode_CLocalVar_create
					(index, ILTypeToMachineType(type), type,
					 CTypeDecay(&CCCodeGen, type));
				CGenCloneLine(assign, decl.node);
				assign = BuildAssignInit(assign, init, type);
				CGenCloneLine(assign, init);
				ILNode_List_Add(*list, assign);
			}
		}
	}
}

/*
 * Process a C# type that is being imported into the global scope
 * via a "using Type" declaration.
 */
static void ProcessUsingTypeDeclaration(ILType *type, ILNode *declNode)
{
	ILClass *classInfo;
	char *name;
	void *data;

	/* Get the name of the type, without its namespace */
	classInfo = ILTypeToClass(&CCCodeGen, type);
	name = ILInternString((char *)ILClass_Name(classInfo), -1).string;

	/* See if we already have a declaration for this name */
	data = CScopeLookupCurrent(name);
	if(data)
	{
		/* Don't report an error if the name is already defined
		   with this type, just in case the user has declared the
		   same "using Type" in multiple places (e.g. header files) */
		if(CScopeGetKind(data) != C_SCDATA_TYPEDEF ||
		   !CTypeIsIdentical(CScopeGetType(data), type))
		{
			ReportRedeclared(name, declNode, data);
		}
		return;
	}

	/* Add the name as a "typedef" to the scope */
	CScopeAddTypedef(name, type, declNode);
}

/*
 * Evaluate a constant expression to an "unsigned int" value.
 * Used for array and bit field sizes.
 */
static ILNode *EvaluateSize(ILNode *expr)
{
	CSemValue value;
	ILEvalValue *evalValue;
	ILUInt32 size;
	ILNode *node;

	/* Perform inline semantic analysis on the expression */
	value = CSemInlineAnalysis(&CCCodeGen, expr, &expr, CCurrentScope);
	if(!CSemIsConstant(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  _("constant value required"));
		}
		size = 1;
		goto done;
	}

	/* Convert the constant value into an "unsigned int" value */
	evalValue = CSemGetConstant(value);
	if(!evalValue)
	{
		/* This is a dynamic constant: cast the value to "unsigned int" */
		if(!CCanCoerceValue(value, ILType_UInt32))
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  _("compile-time integer constant value required"));
			size = 1;
			goto done;
		}
		CCastNode(&CCCodeGen, expr, &expr, value, ILType_UInt32);
		return expr;
	}

	/* Fold the constant value to a "ILUInt32" value */
	size = 1;
	switch(evalValue->valueType)
	{
		case ILMachineType_Int8:
		case ILMachineType_UInt8:
		case ILMachineType_Int16:
		case ILMachineType_UInt16:
		case ILMachineType_Char:
		case ILMachineType_Int32:
		case ILMachineType_NativeInt:
		{
			if(evalValue->un.i4Value >= 0)
			{
				size = (ILUInt32)(evalValue->un.i4Value);
			}
			else
			{
				CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
							  _("size value is negative"));
			}
		}
		break;

		case ILMachineType_UInt32:
		case ILMachineType_NativeUInt:
		{
			size = (ILUInt32)(evalValue->un.i4Value);
		}
		break;

		case ILMachineType_Int64:
		{
			if(evalValue->un.i8Value > (ILInt64)IL_MAX_UINT32)
			{
				CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
							  _("size value is too large"));
			}
			else if(evalValue->un.i8Value >= 0)
			{
				size = (ILUInt32)(evalValue->un.i8Value);
			}
			else
			{
				CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
							  _("size value is negative"));
			}
		}
		break;

		case ILMachineType_UInt64:
		{
			if(((ILUInt64)(evalValue->un.i8Value)) > (ILUInt64)IL_MAX_UINT32)
			{
				CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
							  _("size value is too large"));
			}
			else
			{
				size = (ILUInt32)(evalValue->un.i8Value);
			}
		}
		break;

		default:
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  _("size value has non-integer type"));
		}
		break;
	}

	/* Return the computed size to the caller */
done:
	node = ILNode_UInt32_create((ILUInt64)size, 0, 1);
	CGenCloneLine(node, expr);
	return node;
}

/*
 * Evaluate the size of a bit field.
 */
static ILUInt32 EvaluateBitFieldSize(ILNode *expr)
{
	ILEvalValue value;
	ILNode *size = EvaluateSize(expr);
	if(!size || !ILNode_EvalConst(size, &CCCodeGen, &value))
	{
		return 0;
	}
	return (ILUInt32)(value.un.i4Value);
}

/*
 * Evaluate a constant expression to an "int" value.
 * Used for enumerated constant values.
 */
static ILInt32 EvaluateIntConstant(ILNode *expr)
{
	CSemValue value;
	ILEvalValue *evalValue;

	/* Perform inline semantic analysis on the expression */
	value = CSemInlineAnalysis(&CCCodeGen, expr, &expr, CCurrentScope);
	if(!CSemIsConstant(value))
	{
		if(!CSemIsError(value))
		{
			CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
						  _("constant value required"));
		}
		return 0;
	}

	/* Convert the constant value into an "int" value */
	evalValue = CSemGetConstant(value);
	if(!evalValue || !ILGenCastConst(&CCCodeGen, evalValue,
									 evalValue->valueType,
									 ILMachineType_Int32))
	{
		CCErrorOnLine(yygetfilename(expr), yygetlinenum(expr),
					  _("compile-time constant value required"));
		return 0;
	}
	return evalValue->un.i4Value;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 1108 "c_grammar.y"
{

	CLexIntConst		integer;
	CLexFloatConst		real;
	ILIntString			string;
	char	           *name;
	ILNode             *node;
	ILType			   *type;
	CDeclSpec			declSpec;
	CDeclarator			decl;
	int					kind;
	struct {
		ILType		   *type;
		ILType		   *parent;
	}					structInfo;
	ILMethod           *methodInfo;
	struct
	{
		ILType		   *type;
		char		   *id;
		ILNode         *idNode;
	}					catchInfo;
	ILGCSpecifier		gcSpecifier;

}
/* Line 193 of yacc.c.  */
#line 1428 "c_grammar.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1453 "c_grammar.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  95
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  397
/* YYNRULES -- Number of states.  */
#define YYNSTATES  708

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,     2,     2,     2,   115,   112,     2,
     102,   103,   113,   109,   107,   108,   106,   114,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   121,   123,
     116,   122,   117,   120,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   104,     2,   105,   118,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   124,   119,   125,   110,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    37,    41,
      45,    47,    49,    52,    55,    57,    60,    62,    65,    67,
      72,    76,    81,    85,    89,    93,    97,   101,   104,   107,
     114,   121,   126,   131,   136,   141,   143,   147,   149,   152,
     155,   158,   161,   164,   167,   170,   173,   176,   181,   184,
     189,   194,   197,   202,   207,   209,   211,   213,   218,   223,
     229,   235,   242,   248,   255,   261,   268,   275,   278,   283,
     289,   291,   294,   296,   299,   301,   305,   309,   313,   315,
     319,   323,   325,   329,   333,   335,   339,   343,   347,   351,
     353,   357,   361,   363,   367,   369,   373,   375,   379,   381,
     385,   387,   391,   393,   399,   401,   405,   409,   413,   417,
     421,   425,   429,   433,   437,   441,   445,   447,   451,   453,
     456,   460,   462,   465,   467,   470,   472,   476,   478,   482,
     484,   486,   488,   490,   492,   494,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   529,   531,   533,   535,   537,   542,   547,   549,   551,
     552,   554,   559,   560,   567,   568,   574,   577,   579,   581,
     582,   584,   586,   589,   593,   595,   599,   601,   604,   608,
     610,   614,   615,   621,   622,   629,   632,   634,   637,   639,
     641,   645,   647,   651,   653,   657,   659,   662,   664,   667,
     671,   676,   682,   688,   695,   699,   704,   709,   715,   720,
     726,   727,   729,   731,   738,   740,   744,   746,   751,   753,
     755,   757,   761,   763,   766,   769,   773,   775,   778,   781,
     785,   787,   789,   791,   794,   796,   799,   801,   803,   807,
     809,   813,   815,   819,   821,   825,   828,   832,   834,   837,
     839,   842,   844,   846,   849,   853,   857,   862,   867,   873,
     878,   884,   890,   897,   900,   904,   908,   913,   917,   922,
     927,   933,   935,   939,   944,   946,   950,   952,   954,   956,
     958,   960,   962,   964,   966,   968,   971,   972,   977,   978,
     984,   985,   990,   991,   997,   999,  1000,  1002,  1005,  1007,
    1008,  1010,  1013,  1015,  1018,  1020,  1026,  1034,  1040,  1046,
    1054,  1061,  1069,  1077,  1086,  1094,  1103,  1112,  1122,  1126,
    1131,  1134,  1137,  1140,  1144,  1151,  1157,  1165,  1172,  1174,
    1176,  1178,  1180,  1184,  1188,  1193,  1196,  1199,  1200,  1202,
    1204,  1207,  1211,  1212,  1217,  1221,  1225,  1226,  1228,  1231,
    1234,  1237,  1241,  1244,  1247,  1253,  1255,  1256,  1258,  1261,
    1263,  1265,  1267,  1270,  1273,  1275,  1276,  1283,  1284,  1292,
    1294,  1295,  1297,  1300,  1304,  1306,  1310,  1312,  1315,  1320,
    1324,  1331,  1333,  1337,  1338,  1343,  1345,  1346
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     232,     0,    -1,     3,    -1,    10,    -1,    11,    -1,     3,
      -1,   128,    -1,     4,    -1,     5,    -1,     6,    -1,   130,
      -1,   131,    -1,   132,    -1,    80,    -1,    89,    -1,    90,
      -1,    91,    -1,   102,   153,   103,    -1,   102,   207,   103,
      -1,   102,     1,   103,    -1,     7,    -1,    79,    -1,   130,
       7,    -1,   130,    79,    -1,     8,    -1,   131,     8,    -1,
       9,    -1,   132,     9,    -1,   129,    -1,   133,   104,   153,
     105,    -1,   133,   102,   103,    -1,   133,   102,   134,   103,
      -1,   133,   106,   127,    -1,    10,    33,   127,    -1,   246,
      33,   127,    -1,   133,    33,   127,    -1,   133,    12,   127,
      -1,   133,    13,    -1,   133,    14,    -1,    72,   102,   135,
     107,   196,   103,    -1,    71,   102,   135,   107,   128,   103,
      -1,    71,   102,   135,   103,    -1,    73,   102,   135,   103,
      -1,    74,   102,   135,   103,    -1,    75,   102,   152,   103,
      -1,   152,    -1,   134,   107,   152,    -1,   133,    -1,    13,
     135,    -1,    14,   135,    -1,   108,   136,    -1,   109,   136,
      -1,   110,   136,    -1,   111,   136,    -1,   112,   136,    -1,
     113,   136,    -1,    58,   135,    -1,    58,   102,   196,   103,
      -1,    21,     3,    -1,    87,   102,   153,   103,    -1,    88,
     102,   153,   103,    -1,    97,   135,    -1,    97,   102,   196,
     103,    -1,    98,   102,   153,   103,    -1,   137,    -1,   138,
      -1,   135,    -1,   102,   196,   103,   136,    -1,   139,   190,
     102,   103,    -1,   139,   190,   102,   134,   103,    -1,   100,
     139,   190,   102,   103,    -1,   100,   139,   190,   102,   134,
     103,    -1,   101,   139,   190,   102,   103,    -1,   101,   139,
     190,   102,   134,   103,    -1,   139,   190,   104,   153,   105,
      -1,   100,   139,   190,   104,   153,   105,    -1,   101,   139,
     190,   104,   153,   105,    -1,   140,   136,    -1,   140,   104,
     105,   136,    -1,   140,   104,   153,   105,   136,    -1,    95,
      -1,    33,    95,    -1,    96,    -1,    33,   140,    -1,   136,
      -1,   141,   113,   136,    -1,   141,   114,   136,    -1,   141,
     115,   136,    -1,   141,    -1,   142,   109,   141,    -1,   142,
     108,   141,    -1,   142,    -1,   143,    15,   142,    -1,   143,
      16,   142,    -1,   143,    -1,   144,   116,   143,    -1,   144,
     117,   143,    -1,   144,    17,   143,    -1,   144,    18,   143,
      -1,   144,    -1,   145,    19,   144,    -1,   145,    20,   144,
      -1,   145,    -1,   146,   112,   145,    -1,   146,    -1,   147,
     118,   146,    -1,   147,    -1,   148,   119,   147,    -1,   148,
      -1,   149,    21,   148,    -1,   149,    -1,   150,    22,   149,
      -1,   150,    -1,   150,   120,   153,   121,   152,    -1,   151,
      -1,   150,   122,   152,    -1,   150,    23,   152,    -1,   150,
      24,   152,    -1,   150,    25,   152,    -1,   150,    26,   152,
      -1,   150,    27,   152,    -1,   150,    28,   152,    -1,   150,
      29,   152,    -1,   150,    30,   152,    -1,   150,    31,   152,
      -1,   150,    32,   152,    -1,   152,    -1,   153,   107,   152,
      -1,   151,    -1,   156,   123,    -1,   156,   157,   123,    -1,
     159,    -1,   159,   156,    -1,   160,    -1,   160,   156,    -1,
     158,    -1,   157,   107,   158,    -1,   178,    -1,   178,   122,
     199,    -1,    62,    -1,    46,    -1,    59,    -1,    35,    -1,
      54,    -1,    51,    -1,    99,   102,   161,   103,    -1,    38,
      -1,    56,    -1,    52,    -1,    53,    -1,    81,    -1,    82,
      -1,    57,    -1,    65,    -1,    47,    -1,    43,    -1,    39,
      -1,    67,    -1,    98,    -1,    66,    -1,    77,    -1,    78,
      -1,    70,    -1,   162,    -1,   171,    -1,    63,   102,   153,
     103,    -1,    63,   102,   196,   103,    -1,    10,    -1,   246,
      -1,    -1,   127,    -1,   127,   102,   130,   103,    -1,    -1,
     165,   127,   124,   163,   166,   125,    -1,    -1,   165,   124,
     164,   166,   125,    -1,   165,   127,    -1,    60,    -1,    64,
      -1,    -1,   167,    -1,   168,    -1,   167,   168,    -1,   189,
     169,   123,    -1,   170,    -1,   169,   107,   170,    -1,   178,
      -1,   121,   154,    -1,   178,   121,   154,    -1,    10,    -1,
      10,   121,   154,    -1,    -1,    45,   124,   172,   174,   125,
      -1,    -1,    45,   127,   124,   173,   174,   125,    -1,    45,
     127,    -1,   175,    -1,   175,   107,    -1,     1,    -1,   176,
      -1,   175,   107,   176,    -1,     3,    -1,     3,   122,   154,
      -1,   127,    -1,   177,   106,   127,    -1,   179,    -1,   186,
     179,    -1,     3,    -1,     3,   181,    -1,   102,   178,   103,
      -1,   179,   180,   104,   105,    -1,   179,   180,   104,   105,
     181,    -1,   179,   180,   104,   154,   105,    -1,   179,   180,
     104,   154,   105,   181,    -1,   179,   102,   103,    -1,   179,
     102,   103,   181,    -1,   179,   102,   193,   103,    -1,   179,
     102,   193,   103,   181,    -1,   179,   102,   191,   103,    -1,
     179,   102,   191,   103,   181,    -1,    -1,   100,    -1,   101,
      -1,    76,   102,   102,   182,   103,   103,    -1,   183,    -1,
     182,   107,   183,    -1,   127,    -1,   127,   102,   185,   103,
      -1,    39,    -1,   151,    -1,   184,    -1,   185,   107,   184,
      -1,   113,    -1,   113,   188,    -1,   113,   186,    -1,   113,
     188,   186,    -1,   112,    -1,   112,   188,    -1,   112,   186,
      -1,   112,   188,   186,    -1,    39,    -1,    67,    -1,   187,
      -1,   188,   187,    -1,   160,    -1,   189,   160,    -1,   189,
      -1,   192,    -1,   192,   107,    69,    -1,     3,    -1,   192,
     107,     3,    -1,   194,    -1,   194,   107,    69,    -1,   195,
      -1,   194,   107,   195,    -1,   189,   178,    -1,    54,   189,
     178,    -1,   196,    -1,    54,   196,    -1,   189,    -1,   189,
     197,    -1,   186,    -1,   198,    -1,   186,   198,    -1,   102,
     197,   103,    -1,   180,   104,   105,    -1,   180,   104,   105,
     181,    -1,   180,   104,   154,   105,    -1,   180,   104,   154,
     105,   181,    -1,   198,   180,   104,   105,    -1,   198,   180,
     104,   105,   181,    -1,   198,   180,   104,   154,   105,    -1,
     198,   180,   104,   154,   105,   181,    -1,   102,   103,    -1,
     102,   103,   181,    -1,   102,   193,   103,    -1,   102,   193,
     103,   181,    -1,   198,   102,   103,    -1,   198,   102,   103,
     181,    -1,   198,   102,   193,   103,    -1,   198,   102,   193,
     103,   181,    -1,   152,    -1,   124,   200,   125,    -1,   124,
     200,   107,   125,    -1,   199,    -1,   200,   107,   199,    -1,
     202,    -1,   203,    -1,   207,    -1,   213,    -1,   215,    -1,
     216,    -1,   217,    -1,   218,    -1,   219,    -1,     1,   123,
      -1,    -1,     3,   121,   204,   201,    -1,    -1,    37,   154,
     121,   205,   201,    -1,    -1,    41,   121,   206,   201,    -1,
      -1,   124,   208,   209,   211,   125,    -1,   210,    -1,    -1,
     155,    -1,   210,   155,    -1,   212,    -1,    -1,   201,    -1,
     212,   201,    -1,   123,    -1,   153,   123,    -1,   153,    -1,
      50,   102,   214,   103,   201,    -1,    50,   102,   214,   103,
     201,    44,   201,    -1,    61,   102,   153,   103,   201,    -1,
      68,   102,   214,   103,   201,    -1,    42,   201,    68,   102,
     214,   103,   123,    -1,    48,   102,   123,   123,   103,   201,
      -1,    48,   102,   123,   123,   153,   103,   201,    -1,    48,
     102,   123,   214,   123,   103,   201,    -1,    48,   102,   123,
     214,   123,   153,   103,   201,    -1,    48,   102,   153,   123,
     123,   103,   201,    -1,    48,   102,   153,   123,   123,   153,
     103,   201,    -1,    48,   102,   153,   123,   214,   123,   103,
     201,    -1,    48,   102,   153,   123,   214,   123,   153,   103,
     201,    -1,    49,     3,   123,    -1,    49,   113,   153,   123,
      -1,    40,   123,    -1,    36,   123,    -1,    55,   123,    -1,
      55,   153,   123,    -1,    34,   102,   130,   121,   121,   103,
      -1,    34,   102,   130,    33,   103,    -1,    34,    67,   102,
     130,   121,   121,   103,    -1,    34,    67,   102,   130,    33,
     103,    -1,   220,    -1,   229,    -1,   230,    -1,   231,    -1,
      83,   207,   221,    -1,    83,   207,   228,    -1,    83,   207,
     221,   228,    -1,   223,   226,    -1,   222,   227,    -1,    -1,
     223,    -1,   224,    -1,   223,   224,    -1,    84,   225,   207,
      -1,    -1,   102,   196,   128,   103,    -1,   102,   196,   103,
      -1,   102,     1,   103,    -1,    -1,   227,    -1,    84,   207,
      -1,    85,   207,    -1,    86,   123,    -1,    86,   153,   123,
      -1,    87,   207,    -1,    88,   207,    -1,    92,   102,   153,
     103,   201,    -1,   233,    -1,    -1,   234,    -1,   233,   234,
      -1,   235,    -1,   155,    -1,   244,    -1,     1,   123,    -1,
       1,   125,    -1,   123,    -1,    -1,   178,   238,   124,   236,
     243,   125,    -1,    -1,   156,   178,   238,   124,   237,   243,
     125,    -1,   239,    -1,    -1,   240,    -1,   239,   240,    -1,
     156,   241,   123,    -1,   242,    -1,   241,   107,   242,    -1,
     178,    -1,   209,   211,    -1,    93,    94,   245,   123,    -1,
      93,   245,   123,    -1,    93,   104,   177,   105,   245,   123,
      -1,   127,    -1,   245,    33,   127,    -1,    -1,    11,    33,
     247,   248,    -1,    10,    -1,    -1,    11,    33,   249,   248,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1311,  1311,  1312,  1313,  1317,  1321,  1417,  1489,  1500,
    1512,  1515,  1518,  1521,  1530,  1531,  1532,  1533,  1534,  1535,
    1539,  1540,  1543,  1546,  1553,  1554,  1560,  1561,  1567,  1568,
    1571,  1575,  1579,  1583,  1588,  1592,  1596,  1600,  1603,  1606,
    1609,  1612,  1615,  1618,  1621,  1627,  1628,  1634,  1635,  1636,
    1637,  1641,  1642,  1643,  1646,  1647,  1648,  1649,  1650,  1651,
    1654,  1657,  1665,  1668,  1671,  1672,  1676,  1677,  1684,  1687,
    1690,  1693,  1696,  1699,  1702,  1705,  1708,  1714,  1717,  1720,
    1726,  1727,  1731,  1732,  1736,  1737,  1740,  1743,  1749,  1750,
    1753,  1759,  1760,  1763,  1769,  1770,  1773,  1776,  1779,  1785,
    1786,  1789,  1795,  1796,  1802,  1803,  1809,  1810,  1816,  1817,
    1824,  1825,  1832,  1833,  1840,  1841,  1844,  1847,  1850,  1853,
    1856,  1859,  1862,  1865,  1868,  1871,  1877,  1878,  1884,  1890,
    1924,  1992,  1993,  1996,  1997,  2003,  2004,  2020,  2023,  2029,
    2030,  2031,  2032,  2033,  2034,  2035,  2039,  2040,  2041,  2042,
    2043,  2044,  2045,  2046,  2047,  2048,  2049,  2050,  2051,  2052,
    2053,  2054,  2055,  2056,  2057,  2059,  2067,  2068,  2074,  2078,
    2079,  2090,  2094,  2094,  2147,  2147,  2163,  2182,  2183,  2186,
    2188,  2192,  2193,  2197,  2246,  2247,  2263,  2264,  2270,  2274,
    2279,  2288,  2288,  2305,  2305,  2338,  2356,  2357,  2358,  2362,
    2363,  2367,  2391,  2423,  2424,  2430,  2431,  2435,  2438,  2442,
    2443,  2446,  2450,  2457,  2465,  2468,  2471,  2474,  2477,  2480,
    2486,  2487,  2488,  2492,  2496,  2500,  2507,  2510,  2513,  2520,
    2551,  2552,  2558,  2561,  2564,  2567,  2570,  2573,  2576,  2579,
    2585,  2586,  2590,  2591,  2605,  2606,  2610,  2620,  2621,  2629,
    2634,  2642,  2643,  2651,  2655,  2662,  2678,  2694,  2698,  2705,
    2712,  2720,  2721,  2722,  2726,  2727,  2731,  2736,  2744,  2753,
    2756,  2760,  2767,  2776,  2780,  2784,  2788,  2792,  2795,  2798,
    2801,  2807,  2808,  2809,  2813,  2817,  2824,  2840,  2841,  2842,
    2843,  2844,  2845,  2846,  2847,  2848,  2852,  2852,  2858,  2858,
    2864,  2864,  2873,  2873,  2901,  2902,  2906,  2907,  2913,  2914,
    2918,  2919,  2925,  2926,  2930,  2934,  2937,  2940,  2947,  2950,
    2953,  2958,  2963,  2967,  2970,  2975,  2978,  2981,  2987,  2988,
    2989,  2990,  2991,  2992,  2997,  3000,  3003,  3006,  3012,  3013,
    3014,  3015,  3019,  3022,  3025,  3031,  3038,  3053,  3054,  3058,
    3062,  3069,  3077,  3082,  3087,  3092,  3105,  3106,  3110,  3119,
    3125,  3126,  3130,  3131,  3135,  3141,  3157,  3161,  3162,  3166,
    3179,  3180,  3181,  3182,  3183,  3187,  3187,  3248,  3248,  3313,
    3314,  3318,  3329,  3336,  3389,  3394,  3412,  3416,  3429,  3432,
    3444,  3460,  3461,  3467,  3467,  3476,  3479,  3479
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"an identifier\"",
  "\"an integer value\"", "\"a floating point value\"",
  "\"an imaginary value\"", "\"a string literal\"",
  "\"a wide string literal\"", "\"a C# string literal\"",
  "\"a type identifier\"", "\"a namespace identifier\"", "\"`->'\"",
  "\"`++'\"", "\"`--'\"", "\"`<<'\"", "\"`>>'\"", "\"`<='\"", "\"`>='\"",
  "\"`=='\"", "\"`!='\"", "\"`&&'\"", "\"`||'\"", "\"`*='\"", "\"`/='\"",
  "\"`%='\"", "\"`+='\"", "\"`-='\"", "\"`<<='\"", "\"`>>='\"", "\"`&='\"",
  "\"`^='\"", "\"`|='\"", "\"`::'\"", "\"`asm'\"", "\"`auto'\"",
  "\"`break'\"", "\"`case'\"", "\"`char'\"", "\"`const'\"",
  "\"`continue'\"", "\"`default'\"", "\"`do'\"", "\"`double'\"",
  "\"`else'\"", "\"`enum'\"", "\"`extern'\"", "\"`float'\"", "\"`for'\"",
  "\"`goto'\"", "\"`if'\"", "\"`inline'\"", "\"`int'\"", "\"`long'\"",
  "\"`register'\"", "\"`return'\"", "\"`short'\"", "\"`signed'\"",
  "\"`sizeof'\"", "\"`static'\"", "\"`struct'\"", "\"`switch'\"",
  "\"`typedef'\"", "\"`typeof'\"", "\"`union'\"", "\"`unsigned'\"",
  "\"`void'\"", "\"`volatile'\"", "\"`while'\"", "\"`...'\"",
  "\"`__builtin_va_list'\"", "\"`__builtin_va_start'\"",
  "\"`__builtin_va_arg'\"", "\"`__builtin_va_end'\"",
  "\"`__builtin_setjmp'\"", "\"`__builtin_alloca'\"",
  "\"`__attribute__'\"", "\"`_Bool'\"", "\"`__wchar__'\"",
  "\"`__FUNCTION__'\"", "\"`__func__'\"", "\"`__int64'\"",
  "\"`__unsigned_int__'\"", "\"`__try__'\"", "\"`__catch__'\"",
  "\"`__finally__'\"", "\"`__throw__'\"", "\"`__checked__'\"",
  "\"`__unchecked__'\"", "\"`__null__'\"", "\"`__true__'\"",
  "\"`__false__'\"", "\"`__lock__'\"", "\"`__using__'\"",
  "\"`__namespace__'\"", "\"`__new__'\"", "\"`__delete__'\"",
  "\"`__typeof'\"", "\"`__box'\"", "\"`__declspec'\"", "\"`__gc'\"",
  "\"`__nogc'\"", "'('", "')'", "'['", "']'", "'.'", "','", "'-'", "'+'",
  "'~'", "'!'", "'&'", "'*'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept", "AnyIdentifier",
  "Identifier", "PrimaryExpression", "StringLiteral", "WStringLiteral",
  "CSharpStringLiteral", "PostfixExpression", "ArgumentExpressionList",
  "UnaryExpression", "CastExpression", "NewExpression", "DeleteExpression",
  "New", "Delete", "MultiplicativeExpression", "AdditiveExpression",
  "ShiftExpression", "RelationalExpression", "EqualityExpression",
  "AndExpression", "XorExpression", "OrExpression", "LogicalAndExpression",
  "LogicalOrExpression", "ConditionalExpression", "AssignmentExpression",
  "Expression", "ConstantExpression", "Declaration",
  "DeclarationSpecifiers", "InitDeclaratorList", "InitDeclarator",
  "StorageClassSpecifier", "TypeSpecifier", "DeclSpecArg",
  "StructOrUnionSpecifier", "@1", "@2", "StructOrUnion",
  "StructDeclarationList", "StructDeclarationList2", "StructDeclaration",
  "StructDeclaratorList", "StructDeclarator", "EnumSpecifier", "@3", "@4",
  "EnumeratorList", "EnumeratorListNoComma", "Enumerator",
  "QualifiedIdentifier", "Declarator", "Declarator2", "GCSpecifier",
  "Attributes", "AttributeList", "Attribute",
  "ConstantAttributeExpression", "AttributeArgs", "Pointer",
  "TypeQualifier", "TypeQualifierList", "TypeSpecifierList", "TypeId",
  "ParameterIdentifierList", "IdentifierList", "ParameterTypeList",
  "ParameterList", "ParameterDeclaration", "TypeName",
  "AbstractDeclarator", "AbstractDeclarator2", "Initializer",
  "InitializerList", "Statement", "Statement2", "LabeledStatement", "@5",
  "@6", "@7", "CompoundStatement", "@8", "OptDeclarationList",
  "DeclarationList", "OptStatementList", "StatementList",
  "ExpressionStatement", "BoolExpression", "SelectionStatement",
  "IterationStatement", "JumpStatement", "AsmStatement", "CSharpStatement",
  "TryStatement", "CatchClauses", "OptSpecificCatchClauses",
  "SpecificCatchClauses", "SpecificCatchClause", "CatchNameInfo",
  "OptGeneralCatchClause", "GeneralCatchClause", "FinallyClause",
  "ThrowStatement", "CheckedStatement", "LockStatement", "File", "File2",
  "ExternalDefinition", "FunctionDefinition", "@9", "@10",
  "OptParamDeclarationList", "ParamDeclarationList", "ParamDeclaration",
  "ParamDeclaratorList", "ParamDeclarator", "FunctionBody",
  "UsingDeclaration", "TypeOrNamespaceDesignator",
  "NamespaceQualifiedType", "@11", "NamespaceQualifiedRest", "@12", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,    40,    41,    91,    93,    46,    44,    45,    43,
     126,    33,    38,    42,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   126,   127,   127,   127,   128,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   136,   136,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   138,   138,   138,
     139,   139,   140,   140,   141,   141,   141,   141,   142,   142,
     142,   143,   143,   143,   144,   144,   144,   144,   144,   145,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   153,   153,   154,   155,
     155,   156,   156,   156,   156,   157,   157,   158,   158,   159,
     159,   159,   159,   159,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   161,
     161,   161,   163,   162,   164,   162,   162,   165,   165,   166,
     166,   167,   167,   168,   169,   169,   170,   170,   170,   170,
     170,   172,   171,   173,   171,   171,   174,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     180,   180,   180,   181,   182,   182,   183,   183,   183,   184,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   186,
     187,   187,   188,   188,   189,   189,   190,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195,   195,   195,   196,
     196,   197,   197,   197,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   199,   199,   199,   200,   200,   201,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   204,   203,   205,   203,
     206,   203,   208,   207,   209,   209,   210,   210,   211,   211,
     212,   212,   213,   213,   214,   215,   215,   215,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   217,   217,
     217,   217,   217,   217,   218,   218,   218,   218,   219,   219,
     219,   219,   220,   220,   220,   221,   221,   222,   222,   223,
     223,   224,   225,   225,   225,   225,   226,   226,   227,   228,
     229,   229,   230,   230,   231,   232,   232,   233,   233,   234,
     234,   234,   234,   234,   234,   236,   235,   237,   235,   238,
     238,   239,   239,   240,   241,   241,   242,   243,   244,   244,
     244,   245,   245,   247,   246,   248,   249,   248
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     2,     2,     1,     2,     1,     2,     1,     4,
       3,     4,     3,     3,     3,     3,     3,     2,     2,     6,
       6,     4,     4,     4,     4,     1,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     2,     4,
       4,     2,     4,     4,     1,     1,     1,     4,     4,     5,
       5,     6,     5,     6,     5,     6,     6,     2,     4,     5,
       1,     2,     1,     2,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     1,     0,
       1,     4,     0,     6,     0,     5,     2,     1,     1,     0,
       1,     1,     2,     3,     1,     3,     1,     2,     3,     1,
       3,     0,     5,     0,     6,     2,     1,     2,     1,     1,
       3,     1,     3,     1,     3,     1,     2,     1,     2,     3,
       4,     5,     5,     6,     3,     4,     4,     5,     4,     5,
       0,     1,     1,     6,     1,     3,     1,     4,     1,     1,
       1,     3,     1,     2,     2,     3,     1,     2,     2,     3,
       1,     1,     1,     2,     1,     2,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     3,     1,     2,     1,
       2,     1,     1,     2,     3,     3,     4,     4,     5,     4,
       5,     5,     6,     2,     3,     3,     4,     3,     4,     4,
       5,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     4,     0,     5,
       0,     4,     0,     5,     1,     0,     1,     2,     1,     0,
       1,     2,     1,     2,     1,     5,     7,     5,     5,     7,
       6,     7,     7,     8,     7,     8,     8,     9,     3,     4,
       2,     2,     2,     3,     6,     5,     7,     6,     1,     1,
       1,     1,     3,     3,     4,     2,     2,     0,     1,     1,
       2,     3,     0,     4,     3,     3,     0,     1,     2,     2,
       2,     3,     2,     2,     5,     1,     0,     1,     2,     1,
       1,     1,     2,     2,     1,     0,     6,     0,     7,     1,
       0,     1,     2,     3,     1,     3,     1,     2,     4,     3,
       6,     1,     3,     0,     4,     1,     0,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   207,   167,     0,   142,   146,   156,   155,     0,
     140,   154,   144,   148,   149,   143,   147,   152,   141,   177,
     139,     0,   178,   153,   159,   157,   162,   160,   161,   150,
     151,     0,   158,     0,     0,   236,   232,   374,   370,     0,
     131,   133,   163,     0,   164,   380,   205,     0,     0,     0,
     367,   369,   371,   168,   372,   373,     0,   208,   393,     2,
       3,     4,   191,   195,     0,     0,     0,   391,     0,   169,
       0,   240,   241,   238,   242,   237,   234,   233,   129,     0,
     135,   137,   132,   134,   174,   176,     0,     0,   379,   381,
     221,   222,     0,     0,   206,     1,   368,     0,     0,     0,
     193,     5,     7,     8,     9,    20,    24,    26,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      13,     0,     0,    14,    15,    16,    80,    82,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
      28,    10,    11,    12,    47,    66,    84,    64,    65,     0,
       0,    88,    91,    94,    99,   102,   104,   106,   108,   110,
     112,   114,   126,     0,   244,   259,     0,   168,     0,   203,
       0,     0,   389,   170,     0,   209,   239,   243,   235,     0,
     130,     0,     0,   179,   172,   386,     0,   384,   375,   382,
     249,     0,   214,   259,     0,   247,     0,   251,   253,   257,
       0,     0,   395,     0,   394,   198,   201,     0,   196,   199,
       0,     0,     0,     0,     0,    48,     0,    49,    58,     0,
      81,    83,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,   302,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    22,    23,
      25,    27,     0,    37,    38,     0,     0,     0,     0,   246,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,   220,   245,     0,   261,   260,
     262,   166,     0,   388,     0,     0,   392,     0,   145,   136,
     137,     0,   281,   138,   377,     0,   180,   181,     0,   179,
       0,   383,   305,   259,   258,   215,   220,   255,   261,   218,
       0,   216,     0,   210,   112,   128,     0,   228,   226,     0,
     224,   396,     0,   192,   197,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
     305,    17,     0,    18,    36,    35,    30,     0,    45,     0,
      32,     0,     0,     0,     0,    85,    86,    87,    90,    89,
      92,    93,    97,    98,    95,    96,   100,   101,   103,   105,
     107,   109,   111,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   115,   127,   273,     0,     0,     0,
     263,     0,     0,    34,     0,   204,     0,   284,     0,   305,
     175,   182,   167,     0,     0,   184,   186,     0,   385,   306,
       0,     0,   304,     0,   256,   219,   250,   248,   217,   252,
     254,   211,   212,     0,     0,     0,     0,   202,   200,   194,
      57,    41,     0,     0,    42,    43,    44,    59,    60,    62,
      63,     0,     0,     0,     0,     0,    67,    31,     0,    29,
      68,     0,     0,    78,     0,     0,   274,   275,   264,   265,
       0,   277,     0,     0,   390,   171,     0,   282,     0,     0,
     187,     0,   183,     0,   173,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   312,     0,   310,   286,   287,   288,
     387,     0,   289,   290,   291,   292,   293,   294,   338,   339,
     340,   341,   307,   376,   213,   229,   230,     0,   223,   225,
     397,     0,     0,    70,     0,     0,    72,     0,     0,     0,
      46,    69,    74,    79,   113,   276,   266,   267,   278,   279,
     269,     0,   283,   285,   378,   190,   189,   185,   188,   295,
     296,     0,     0,   331,     0,   330,   300,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,   360,     0,   362,
     363,     0,   313,   311,   227,     0,    40,    39,    71,    75,
      73,    76,   303,   268,   280,   270,   271,     0,     0,     0,
     298,     0,     0,     0,     0,   328,     0,   314,     0,   333,
       0,     0,   352,     0,   342,     0,   356,   349,   343,   361,
       0,   231,   272,   297,     0,     0,     0,     0,   301,     0,
       0,     0,     0,   329,     0,     0,     0,     0,     0,   359,
     344,     0,   346,     0,   350,   345,   357,     0,     0,     0,
     335,     0,   299,     0,     0,     0,     0,     0,     0,   315,
     317,   318,     0,     0,   351,   358,   364,   337,     0,   334,
       0,   320,     0,     0,     0,     0,     0,     0,     0,   355,
     354,     0,   336,   319,   321,   322,     0,   324,     0,     0,
       0,   316,   353,   323,   325,   326,     0,   327
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    67,   139,   140,   141,   142,   143,   144,   367,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   515,   336,   429,
     430,    79,    80,    40,   164,   174,    42,   319,   183,    43,
     315,   316,   317,   424,   425,    44,    99,   210,   207,   208,
     209,   170,    45,    46,   297,    57,   339,   340,   536,   537,
      47,    74,    75,   165,   260,   194,   195,   407,   197,   198,
     199,   299,   300,   313,   418,   516,   517,   518,   607,   637,
     611,   519,   360,   431,   432,   520,   521,   522,   618,   523,
     524,   525,   526,   527,   528,   624,   625,   626,   627,   648,
     655,   652,   628,   529,   530,   531,    48,    49,    50,    51,
     322,   419,    87,    88,    89,   186,   187,   433,    52,    68,
     216,    98,   204,   446
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -444
static const yytype_int16 yypact[] =
{
    1163,   -46,    -4,  -444,    84,  -444,  -444,  -444,  -444,    26,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,    41,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,   199,  -444,    61,    43,    -8,    -8,  -444,  -444,    77,
    1467,  1467,  -444,    40,  -444,  1467,   253,    17,   182,  1249,
    -444,  -444,  -444,  -444,  -444,  -444,    69,  -444,  -444,  -444,
    -444,  -444,  -444,    64,  2280,   262,   262,  -444,    11,   262,
      98,  -444,  -444,  -444,  -444,    -8,  -444,    -8,  -444,   -39,
    -444,  2200,  -444,  -444,  -444,    83,    43,    90,  1467,  -444,
    -444,  -444,  4553,   142,   253,  -444,  -444,   118,   328,    86,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,   210,  3834,
    3834,   234,   154,  3945,   150,   159,   183,   189,   249,  -444,
    -444,   254,   257,  -444,  -444,  -444,  -444,  -444,  4056,   265,
      -5,    -5,   835,  4167,  4167,  4167,  4167,  4167,  4167,  -444,
    -444,    68,   407,   414,   352,  -444,  -444,  -444,  -444,  1690,
    2391,   349,   382,   426,    45,   483,   340,   339,   326,   446,
     449,  -444,  -444,   105,  -444,  4477,   380,   467,    52,  -444,
     401,   262,  -444,   402,   408,  -444,  -444,  -444,  -444,    43,
    -444,  1483,   395,  1690,  -444,  -444,   104,  -444,  -444,  -444,
    -444,  1690,    -4,  4325,   413,   417,   429,   422,  -444,  -444,
    2502,   193,  -444,   506,  -444,  -444,   421,   423,   435,  -444,
      86,   262,   210,   265,  1081,  -444,   467,  -444,  -444,    34,
    -444,  -444,   835,  -444,  3834,  3834,  3834,  3834,  4167,  4167,
    4167,   835,  -444,  4167,   450,  1690,  1690,   448,  -444,   171,
     452,   453,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,   262,  -444,  -444,   262,  2613,  4167,   262,  1690,
     175,  2724,  -444,  4167,  4167,  4167,  4167,  4167,  4167,  4167,
    4167,  4167,  4167,  4167,  4167,  4167,  4167,  4167,  4167,  4167,
    4167,  4167,  4167,  4167,  4167,  4167,  4167,  4167,  4167,  4167,
    4167,  4167,  4167,  -444,  4167,  4401,  -444,   445,   293,  -444,
     312,  -444,   262,  -444,   262,   262,  -444,   139,  -444,  -444,
     430,  1483,  -444,  -444,  -444,   428,  1690,  -444,  2121,  1690,
      43,  -444,  1467,  4325,  -444,  -444,  4249,  -444,   245,    -4,
      53,    -4,  1579,    -4,    16,  -444,   454,  -444,   455,   177,
    -444,  -444,  4167,  -444,   555,   436,  -444,   457,   230,   456,
     459,   461,   462,   255,   270,   463,   272,   304,   344,  -444,
    1467,  -444,  4167,  -444,  -444,  -444,  -444,   275,  -444,   282,
    -444,  2835,  4167,  4167,   361,  -444,  -444,  -444,   349,   349,
     382,   382,   426,   426,   426,   426,    45,    45,   483,   340,
     339,   326,   446,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,   -24,  -444,  -444,    -4,   464,   465,  2946,
     312,  4601,   466,  -444,    58,  -444,    23,  -444,    88,  1467,
    -444,  -444,   133,  4167,   160,  -444,   451,   458,  -444,  -444,
      77,   585,  1467,   472,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,    -4,  4167,   470,   193,   328,  -444,  -444,  -444,
    -444,  -444,   571,  1690,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  3057,  4167,  3168,  4167,   585,  -444,  -444,  4167,  -444,
    -444,   285,   377,  -444,  4167,  4167,  -444,    -4,  -444,    -4,
     473,    -4,   477,  3279,  -444,  -444,  1360,  -444,   475,  4167,
    -444,   121,  -444,  4167,  -444,   478,   460,   117,   479,  4167,
     482,   486,   957,   480,     8,   485,  1595,   507,   508,   484,
    1706,   -29,   -26,   509,  -444,   163,  -444,  -444,  -444,  -444,
    -444,   710,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,   297,  -444,  -444,
    -444,   481,   510,  -444,   300,   391,  -444,   315,   392,   487,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,    -4,  -444,    -4,
      -4,   511,  -444,  -444,  -444,  -444,   493,  -444,  -444,  -444,
    -444,   513,   139,  -444,   496,  -444,  -444,   552,  1817,   500,
    4167,  4167,  -444,   204,  4167,  4167,   425,  -444,   206,  -444,
    -444,  4167,  -444,  -444,  -444,  4167,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,    -4,   957,   139,    27,
    -444,   957,   526,  1928,   221,  -444,   229,   468,   527,  -444,
     318,   528,   530,   484,   544,   553,   554,  -444,  -444,  -444,
     321,  -444,  -444,  -444,    94,   533,   518,   957,  -444,  4167,
    3390,   519,  2039,  -444,   957,   957,   957,  1339,   484,  -444,
    -444,   484,  -444,    97,  -444,  -444,  -444,   957,   538,   523,
    -444,   542,  -444,   545,   957,   327,  3501,  3612,   529,   605,
    -444,  -444,   547,    32,  -444,  -444,  -444,  -444,   548,  -444,
     531,  -444,   957,   957,   330,   957,   332,  3723,   957,  -444,
    -444,   558,  -444,  -444,  -444,  -444,   957,  -444,   957,   957,
     333,  -444,  -444,  -444,  -444,  -444,   957,  -444
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -444,     5,  -443,  -444,  -291,  -444,  -444,  -444,  -338,   116,
    -111,  -444,  -444,   383,   -91,   260,   266,   216,   263,   379,
     385,   388,   384,   387,  -185,  -168,  -174,   -63,  -103,     6,
     420,  -444,   490,  -444,    12,  -444,  -444,  -444,  -444,  -444,
     351,  -444,   362,  -444,   188,  -444,  -444,  -444,   474,  -444,
     345,  -444,   -21,   -28,   -36,  -189,  -444,   243,    95,  -444,
     103,   374,   655,   -50,   305,  -444,  -444,   -87,  -444,   360,
     -62,  -248,  -232,  -294,  -444,  -152,  -444,  -444,  -444,  -444,
    -444,  -128,  -444,   341,  -444,   235,  -444,  -444,  -237,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,    73,  -444,
    -444,    76,    79,  -444,  -444,  -444,  -444,  -444,   656,  -444,
    -444,  -444,   623,  -444,   618,  -444,   405,   288,  -444,   -57,
       0,  -444,   276,  -444
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -381
static const yytype_int16 yytable[] =
{
      53,   163,   166,   325,   241,   196,    38,   312,   168,   541,
      93,   579,    41,    70,    63,   334,   416,   417,    81,    94,
       2,   221,   242,   243,   244,   245,   246,   247,   234,    59,
     248,    71,   335,   471,   248,   101,    60,    61,   280,   262,
      53,    53,   193,    59,   171,    53,     2,   408,    85,    53,
      60,    61,    41,    41,   352,    38,   436,    41,    93,    72,
     635,    41,   270,   271,   167,   185,   410,   219,   179,   239,
     240,   169,    56,   229,   173,   248,   230,    54,   408,    55,
       2,    53,   368,   294,   180,   171,   241,   205,    53,   206,
     126,   171,    53,    41,   241,   238,   410,   475,   238,   259,
      41,   248,   249,   241,    35,    36,   249,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,    58,   404,    34,
     405,   580,   437,   544,     2,   547,   485,   658,   221,   324,
     127,   566,   167,   318,   172,   690,   291,   312,    73,    76,
     435,   323,   438,    64,   441,    34,   105,   249,   636,    53,
      62,   239,   375,   376,   377,    35,    36,   334,   310,   239,
     347,   272,   273,    69,    84,    53,   353,   354,   239,   355,
     356,    97,   327,   249,   335,   303,   306,   296,   176,    34,
     178,   484,    95,    53,   571,   259,   259,   219,   100,    35,
      36,    53,   563,    53,   369,   486,    59,   368,   374,   647,
      78,   175,    59,    60,    61,   296,   338,   184,   293,    60,
      61,   320,   294,   487,   188,   659,   346,   476,   119,   572,
     201,   238,   167,    34,   334,   215,   217,   321,   403,   223,
     691,   167,   337,    35,    36,    53,    53,   218,   334,   447,
    -189,   335,   423,   211,   232,   193,   200,   414,     2,   220,
     127,   466,   224,   534,   489,   335,  -189,   364,   334,    53,
     365,   225,   473,   370,   412,    59,   318,   491,   298,   318,
     294,   296,    60,    61,   361,   535,   193,   371,   294,   372,
     444,   609,   193,   492,   445,   226,   592,   368,   555,   368,
     556,   227,   558,    65,   550,    53,   328,   426,   334,   185,
      94,   554,   434,    66,   334,    70,   480,   413,   334,   472,
     415,   294,   312,   294,   334,   335,    53,   634,    53,    53,
     490,   335,    53,    53,   482,   335,    53,   619,   294,   629,
     296,   335,    53,   451,    41,   296,   294,   452,   202,   203,
     348,   349,   350,   351,   642,    90,    91,   326,   621,  -220,
     577,   228,   643,    90,    91,    92,   229,  -220,   457,   230,
      53,   193,   294,   553,   252,   253,   254,   233,   603,   593,
     604,   605,    41,   458,   412,   460,   641,   294,   467,   294,
     561,   586,   468,   589,   590,   255,   565,   469,   551,   294,
     568,   542,   468,    90,    91,   295,   574,  -220,   298,   545,
     594,   548,   663,   598,   595,   668,   461,   468,   462,   310,
     334,    53,    90,    91,   411,   250,  -220,   632,   600,    53,
      39,   645,   468,   251,   657,   294,   328,   535,   294,   328,
     682,    41,    53,   696,   294,   698,   706,   294,   532,   294,
     294,   268,   269,   583,    41,   278,   463,   588,   464,   177,
     338,   177,   276,    53,   256,   633,   257,   277,   258,   638,
      82,    83,   263,   264,   265,    86,   474,   279,   294,    39,
     426,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   552,   301,   294,   662,   382,   383,   384,   385,
     266,   267,   669,   670,   671,   649,   599,   601,   294,   294,
     302,    86,   274,   275,   307,   676,   304,   305,    86,   622,
     623,   308,   681,   235,   236,   614,   329,   616,   617,   314,
     674,   620,   617,   675,   330,   675,   378,   379,   630,   332,
     694,   695,   331,   697,   380,   381,   701,   386,   387,   341,
     357,   358,   344,   342,   703,   220,   704,   705,   343,   409,
     617,   359,   181,   420,   707,   362,   363,   443,   206,   442,
     450,   449,   454,   453,   455,   456,   459,   477,   478,   291,
     483,   292,   493,   538,   101,   294,   617,   665,   557,   617,
     559,   570,   578,   494,   596,   673,   495,   581,   496,   102,
     103,   104,   105,   106,   107,   212,     4,   533,   109,   110,
     564,   569,   573,   684,   686,   575,   111,   576,   238,   584,
     585,   591,   602,   597,   489,   608,   606,   610,   112,   497,
     612,   498,   499,   615,   700,   500,   501,   502,   639,   623,
     644,   646,   647,   503,   504,   505,   660,   651,   653,   661,
     506,   677,   666,   113,   678,   679,   507,    53,   680,   688,
     689,   692,   687,   508,   693,   388,   114,   115,   116,   117,
     118,   702,   389,   391,   119,   120,   390,   392,   509,   309,
     427,   510,   511,   512,   123,   124,   125,   513,   421,   567,
     126,   127,   128,   213,   345,   130,   131,   132,   539,   448,
     631,    77,   440,   133,   134,   135,   136,   137,   138,   654,
     549,   465,   656,   650,   182,    96,   189,   488,   514,   238,
    -309,   495,     0,   496,   102,   103,   104,   105,   106,   107,
     212,     4,   540,   109,   110,   428,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   497,     0,   498,   499,     0,     0,
     500,   501,   502,     0,     0,     0,     0,     0,   503,   504,
     505,     0,     0,     0,     0,   506,     0,     0,   113,     0,
       0,   507,     0,     0,     0,     0,     0,     0,   508,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,   119,
     120,     0,     0,   509,     0,     0,   510,   511,   512,   123,
     124,   125,   513,     0,     0,   126,   127,   128,   213,     0,
     130,   131,   132,     0,     0,     0,     0,     0,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   514,   238,  -308,   237,     0,   101,   102,
     103,   104,   105,   106,   107,   108,     4,     0,   109,   110,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     6,     7,     0,     0,     0,     8,     0,
       9,     0,    11,     0,     0,     0,     0,    13,    14,     0,
       0,    16,    17,   113,     0,    19,     0,     0,    21,    22,
      23,    24,    25,     0,     0,    26,   114,   115,   116,   117,
     118,     0,    27,    28,   119,   120,    29,    30,     0,     0,
       0,     0,   121,   122,   123,   124,   125,     0,     0,     0,
     126,   127,   128,   129,     0,   130,   131,   132,     0,     0,
       0,     0,     0,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   238,
     496,   102,   103,   104,   105,   106,   107,   212,     4,     0,
     109,   110,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   497,     0,   498,   499,     0,     0,   500,   501,   502,
       0,     0,     0,     0,     0,   503,   504,   505,     0,     0,
       0,     0,   506,     0,     0,   113,     0,     0,   507,     0,
       0,     0,     0,     0,     0,   508,     0,     0,   114,   115,
     116,   117,   118,     0,     0,     0,   119,   120,     0,     0,
     509,     0,     0,   510,   511,   512,   123,   124,   125,   513,
       0,     0,   126,   127,   128,   213,     0,   130,   131,   132,
       0,     0,     0,     0,     0,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,   238,   237,     0,   101,   102,   103,   104,   105,   106,
     107,   212,     4,     0,   109,   110,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,     0,     0,     0,
     119,   120,     0,  -366,     1,     0,     2,     0,   121,   122,
     123,   124,   125,     3,     4,     0,   126,   127,   128,   213,
       0,   130,   131,   132,     0,     0,     0,     0,     0,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     5,     0,
       0,     6,     7,     0,     0,   238,     8,     0,     9,    10,
      11,     0,     0,     0,    12,    13,    14,    15,     0,    16,
      17,     0,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,    26,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,    29,    30,     0,     0,     0,  -365,
       1,     0,     2,     0,     0,     0,    31,     0,     0,     3,
       4,    32,    33,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     5,     0,    37,     6,     7,     0,
       0,     0,     8,     0,     9,    10,    11,     0,     0,     0,
      12,    13,    14,    15,     0,    16,    17,     0,    18,    19,
       0,    20,    21,    22,    23,    24,    25,     0,     0,    26,
       0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
     672,     0,    31,     0,     0,     0,     0,    32,    33,     3,
       4,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,   101,   102,   103,   104,   105,   106,   107,
     212,     4,    37,   109,   110,     0,     0,     6,     7,     0,
       0,   111,     8,     0,     9,     0,    11,     0,     0,     0,
       0,    13,    14,   112,     0,    16,    17,     0,     0,    19,
       0,     0,    21,    22,    23,    24,    25,     0,     0,    26,
       0,     0,     0,     0,     0,     0,    27,    28,   113,     0,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,    32,     0,   119,
     120,     0,     0,     0,     0,     0,     0,   121,   122,   123,
     124,   125,     0,     0,     0,   126,   127,   128,   213,     0,
     130,   131,   132,     0,     0,     0,     0,     0,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     3,     4,     0,
       0,     0,     0,     0,   311,   562,   101,   102,   103,   104,
     105,   106,   107,   212,     4,     0,   109,   110,     0,     0,
       0,     0,     5,     0,   111,     6,     7,     0,     0,     0,
       8,     0,     9,    10,    11,     0,   112,     0,    12,    13,
      14,    15,     0,    16,    17,     0,    18,    19,     0,    20,
      21,    22,    23,    24,    25,     0,     0,    26,     0,     0,
       0,   113,     0,     0,    27,    28,     0,     0,    29,    30,
       0,     0,     0,     0,   114,   115,   116,   117,   118,     0,
       0,     0,   119,   120,     0,    32,    33,     0,     0,     0,
     121,   122,   123,   124,   125,     0,     0,     0,   126,   127,
     128,   213,     0,   130,   131,   132,     0,     0,     0,     3,
       4,   133,   134,   135,   136,   137,   138,     0,   101,   102,
     103,   104,   105,   106,   107,   212,     4,   311,   109,   110,
       0,     0,     0,     0,     0,     0,   111,     6,     7,     0,
       0,     0,     8,     0,     9,     0,    11,     0,   112,     0,
       0,    13,    14,   191,     0,    16,    17,     0,     0,    19,
       0,     0,    21,    22,    23,    24,    25,     0,   439,    26,
       0,     0,     0,   113,     0,     0,    27,    28,     0,     0,
      29,    30,     0,     0,     0,     0,   114,   115,   116,   117,
     118,     0,     0,     0,   119,   120,     0,    32,     0,     0,
       0,     0,   121,   122,   123,   124,   125,     0,     0,     0,
     126,   127,   128,   213,     0,   130,   131,   132,     0,     0,
       3,     4,     0,   133,   134,   135,   136,   137,   138,   101,
     102,   103,   104,   105,   106,   107,   212,     4,   582,   109,
     110,     0,     0,     0,     0,     0,     0,   111,     6,     7,
       0,     0,     0,     8,     0,     9,     0,    11,     0,   112,
       0,     0,    13,    14,     0,     0,    16,    17,     0,     0,
      19,     0,     0,    21,    22,    23,    24,    25,     0,     0,
      26,     0,     0,     0,   113,     0,     0,    27,    28,     0,
       0,    29,    30,     0,     0,     0,     0,   114,   115,   116,
     117,   118,     0,     0,     0,   119,   120,     0,    32,     0,
       0,     0,     0,   121,   122,   123,   124,   125,     0,     0,
       0,   126,   127,   128,   213,     0,   130,   131,   132,     0,
       0,     0,     0,     0,   133,   134,   135,   136,   137,   138,
     101,   102,   103,   104,   105,   106,   107,   212,     4,   587,
     109,   110,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,     0,     0,     0,   119,   120,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,     0,
       0,     0,   126,   127,   128,   213,     0,   130,   131,   132,
       0,     0,     0,     0,     0,   133,   134,   135,   136,   137,
     138,   101,   102,   103,   104,   105,   106,   107,   212,     4,
     613,   109,   110,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,     0,     0,     0,   119,   120,     0,
       0,     0,     0,     0,     0,   121,   122,   123,   124,   125,
       0,     0,     0,   126,   127,   128,   213,     0,   130,   131,
     132,     0,     0,     0,     0,     0,   133,   134,   135,   136,
     137,   138,   101,   102,   103,   104,   105,   106,   107,   212,
       4,   640,   109,   110,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,     0,     0,     0,   119,   120,
       0,     0,     0,     0,     2,     0,   121,   122,   123,   124,
     125,   422,     4,     0,   126,   127,   128,   213,     0,   130,
     131,   132,     0,     0,     0,     0,     0,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     6,
       7,     0,   667,     0,     8,     0,     9,     0,    11,     0,
       0,     0,     0,    13,    14,     0,     0,    16,    17,     0,
       0,    19,     0,     0,    21,    22,    23,    24,    25,     0,
       0,    26,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    29,    30,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     5,     0,     0,     6,     7,
       0,     0,   423,     8,     0,     9,    10,    11,     0,     0,
       0,    12,    13,    14,    15,     0,    16,    17,     0,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,     0,
      26,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,    29,    30,   101,   102,   103,   104,   105,   106,   107,
     108,     4,     0,   109,   110,     0,     0,     0,    32,    33,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,     0,     6,     7,
       0,     0,   181,     8,  -380,     9,     0,    11,     0,     0,
       0,     0,    13,    14,     0,     0,    16,    17,   113,     0,
      19,     0,     0,    21,    22,    23,    24,    25,     0,     0,
      26,   114,   115,   116,   117,   118,     0,    27,    28,   119,
     120,    29,    30,     0,     0,     0,     0,   121,   122,   123,
     124,   125,     0,     0,     0,   126,   127,   128,   129,     0,
     130,   131,   132,     0,     0,     0,     0,     0,   133,   134,
     135,   136,   137,   138,   101,   102,   103,   104,   105,   106,
     107,   212,     4,     0,   109,   110,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,     0,     0,     0,
     119,   120,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,   125,     0,     0,     0,   126,   127,   128,   213,
       0,   130,   131,   132,     0,   261,     0,     0,     0,   133,
     134,   135,   136,   137,   138,   101,   102,   103,   104,   105,
     106,   107,   212,     4,     0,   109,   110,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,     0,     0,
       0,   119,   120,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,   125,     0,     0,     0,   126,   127,   128,
     213,     0,   130,   131,   132,     0,     0,   333,     0,     0,
     133,   134,   135,   136,   137,   138,   101,   102,   103,   104,
     105,   106,   107,   212,     4,     0,   109,   110,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,     0,
       0,     0,   119,   120,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,     0,     0,     0,   126,   127,
     128,   213,     0,   130,   131,   132,   366,     0,     0,     0,
       0,   133,   134,   135,   136,   137,   138,   101,   102,   103,
     104,   105,   106,   107,   212,     4,     0,   109,   110,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
       0,     0,     0,   119,   120,     0,     0,     0,     0,     0,
       0,   121,   122,   123,   124,   125,     0,     0,     0,   126,
     127,   128,   213,     0,   130,   131,   132,     0,     0,   373,
       0,     0,   133,   134,   135,   136,   137,   138,   101,   102,
     103,   104,   105,   106,   107,   212,     4,     0,   109,   110,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,     0,     0,     0,   119,   120,     0,     0,     0,     0,
       0,     0,   121,   122,   123,   124,   125,     0,     0,     0,
     126,   127,   128,   213,     0,   130,   131,   132,   470,     0,
       0,     0,     0,   133,   134,   135,   136,   137,   138,   101,
     102,   103,   104,   105,   106,   107,   212,     4,     0,   109,
     110,     0,     0,     0,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,     0,     0,     0,   119,   120,     0,     0,     0,
       0,     0,     0,   121,   122,   123,   124,   125,     0,     0,
       0,   126,   127,   128,   213,     0,   130,   131,   132,     0,
       0,   479,     0,     0,   133,   134,   135,   136,   137,   138,
     101,   102,   103,   104,   105,   106,   107,   212,     4,     0,
     109,   110,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,     0,     0,     0,   119,   120,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,     0,
       0,     0,   126,   127,   128,   213,     0,   130,   131,   132,
     543,     0,     0,     0,     0,   133,   134,   135,   136,   137,
     138,   101,   102,   103,   104,   105,   106,   107,   212,     4,
       0,   109,   110,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,     0,     0,     0,   119,   120,     0,
       0,     0,     0,     0,     0,   121,   122,   123,   124,   125,
       0,     0,     0,   126,   127,   128,   213,     0,   130,   131,
     132,   546,     0,     0,     0,     0,   133,   134,   135,   136,
     137,   138,   101,   102,   103,   104,   105,   106,   107,   212,
       4,     0,   109,   110,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,     0,     0,     0,   119,   120,
       0,     0,     0,     0,     0,     0,   121,   122,   123,   124,
     125,     0,     0,     0,   126,   127,   128,   213,     0,   130,
     131,   132,     0,     0,   560,     0,     0,   133,   134,   135,
     136,   137,   138,   101,   102,   103,   104,   105,   106,   107,
     212,     4,     0,   109,   110,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,   119,
     120,     0,     0,     0,     0,     0,     0,   121,   122,   123,
     124,   125,     0,     0,     0,   126,   127,   128,   213,     0,
     130,   131,   132,   664,     0,     0,     0,     0,   133,   134,
     135,   136,   137,   138,   101,   102,   103,   104,   105,   106,
     107,   212,     4,     0,   109,   110,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,     0,     0,     0,
     119,   120,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,   125,     0,     0,     0,   126,   127,   128,   213,
       0,   130,   131,   132,   683,     0,     0,     0,     0,   133,
     134,   135,   136,   137,   138,   101,   102,   103,   104,   105,
     106,   107,   212,     4,     0,   109,   110,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,     0,     0,
       0,   119,   120,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,   125,     0,     0,     0,   126,   127,   128,
     213,     0,   130,   131,   132,   685,     0,     0,     0,     0,
     133,   134,   135,   136,   137,   138,   101,   102,   103,   104,
     105,   106,   107,   212,     4,     0,   109,   110,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,     0,
       0,     0,   119,   120,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,     0,     0,     0,   126,   127,
     128,   213,     0,   130,   131,   132,   699,     0,     0,     0,
       0,   133,   134,   135,   136,   137,   138,   101,   102,   103,
     104,   105,   106,   107,   212,     4,     0,   109,   110,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
       0,     0,     0,   119,   120,     0,     0,     0,     0,     0,
       0,   121,   122,   123,   124,   125,     0,     0,     0,   126,
     127,   128,   213,     0,   130,   131,   214,     0,     0,     0,
       0,     0,   133,   134,   135,   136,   137,   138,   101,   102,
     103,   104,   105,   106,   107,   212,     4,     0,   109,   110,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,     0,     0,     0,   119,   120,     0,     0,     0,     0,
       0,     0,   121,   122,   123,   124,   125,     0,     0,     0,
     126,   127,   128,   213,     0,   130,   131,   222,     0,     0,
       0,     0,     0,   133,   134,   135,   136,   137,   138,   101,
     102,   103,   104,   105,   106,   107,   212,     4,     0,   109,
     110,     0,     0,     0,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,     0,     0,     0,   119,   120,     0,     0,     0,
       0,     0,     0,   121,   122,   123,   124,   125,     0,     0,
       0,   126,   127,   128,   213,     0,   130,   131,   231,     0,
       0,     0,     0,     0,   133,   134,   135,   136,   137,   138,
     101,   102,   103,   104,   105,   106,   107,   212,     4,     0,
     109,   110,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,     0,     0,     0,   119,   120,     0,     0,
       0,     0,     2,     0,   121,   122,   123,   124,   125,     3,
       4,     0,   126,   127,   128,   213,     0,   130,   131,   132,
       0,     0,     0,     0,     0,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     6,     7,     0,
       0,     0,     8,     0,     9,     0,    11,     0,     0,     0,
       0,    13,    14,   191,     0,    16,    17,     0,     0,    19,
       0,     0,    21,    22,    23,    24,    25,     0,     0,    26,
       0,     0,     0,     0,     0,     0,    27,    28,     2,     0,
      29,    30,     0,     0,     0,     3,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,    90,
      91,   326,   406,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,     6,     7,     0,     0,     0,     8,     0,
       9,     0,    11,     0,     0,     0,     0,    13,    14,     0,
       0,    16,    17,     0,     0,    19,     0,     0,    21,    22,
      23,    24,    25,     0,     0,    26,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,    29,    30,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    90,    91,   326,     0,  -220,
       0,     0,     0,     0,     0,     0,     0,    35,    36,     6,
       7,     0,     0,     0,     8,     0,     9,     0,    11,     0,
       0,     0,     0,    13,    14,   191,     0,    16,    17,     0,
       0,    19,     0,     0,    21,    22,    23,    24,    25,     0,
       0,    26,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    29,    30,     0,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,    90,    91,   295,   406,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     6,     7,     0,     0,     0,
       8,     0,     9,     0,    11,     0,     0,     0,     0,    13,
      14,     0,     0,    16,    17,     0,     0,    19,     0,     0,
      21,    22,    23,    24,    25,     0,     0,    26,     0,     0,
       0,     0,     0,     0,    27,    28,   190,     0,    29,    30,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,    90,    91,   295,
       0,  -220,     0,     0,     0,     0,     0,     0,     0,    35,
      36,     6,     7,     0,     0,     0,     8,     0,     9,     0,
      11,     0,     0,     0,     0,    13,    14,   191,     0,    16,
      17,     3,     4,    19,     0,     0,    21,    22,    23,    24,
      25,     0,     0,    26,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,    29,    30,     0,     0,     0,     6,
       7,     0,     0,     0,     8,     0,     9,     0,    11,     0,
       0,    32,     0,    13,    14,   191,   192,    16,    17,     0,
       0,    19,     0,     0,    21,    22,    23,    24,    25,     0,
       0,    26,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,   481
};

static const yytype_int16 yycheck[] =
{
       0,    64,    64,   192,   132,    92,     0,   181,    65,   452,
      46,     3,     0,    34,     9,   200,   307,   311,    39,    47,
       3,   112,   133,   134,   135,   136,   137,   138,    33,     3,
       7,    39,   200,   371,     7,     3,    10,    11,    22,   150,
      40,    41,    92,     3,    33,    45,     3,   295,    43,    49,
      10,    11,    40,    41,   228,    49,     3,    45,    94,    67,
      33,    49,    17,    18,    64,    86,   298,    33,   107,   132,
     132,    66,    76,   102,    69,     7,   102,   123,   326,   125,
       3,    81,   256,   107,   123,    33,   214,     1,    88,     3,
      95,    33,    92,    81,   222,   124,   328,   121,   124,   149,
      88,     7,    79,   231,   112,   113,    79,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,    33,   292,   102,
     294,   113,    69,   461,     3,   463,   103,    33,   219,   191,
      96,    10,   132,   183,   123,   103,   120,   311,    35,    36,
     329,   191,   331,   102,   333,   102,     7,    79,   121,   149,
     124,   214,   263,   264,   265,   112,   113,   342,   179,   222,
     222,   116,   117,   102,   124,   165,   229,   230,   231,   231,
     233,   102,   193,    79,   342,   123,   171,   165,    75,   102,
      77,   123,     0,   183,    67,   235,   236,    33,   124,   112,
     113,   191,   486,   193,   257,   107,     3,   371,   261,   102,
     123,   103,     3,    10,    11,   193,   201,   124,   103,    10,
      11,   107,   107,   125,   124,   121,   211,   406,    79,   102,
     102,   124,   222,   102,   409,   109,   110,   123,   291,   113,
     673,   231,    39,   112,   113,   235,   236,     3,   423,   342,
     107,   409,   121,    33,   128,   295,   104,   304,     3,    95,
      96,   362,   102,   442,   121,   423,   123,   252,   443,   259,
     255,   102,   373,   258,   300,     3,   316,   107,   165,   319,
     107,   259,    10,    11,   103,   443,   326,   102,   107,   104,
     103,   572,   332,   123,   107,   102,   123,   461,   477,   463,
     479,   102,   481,    94,   468,   295,   193,   318,   483,   320,
     328,   475,   323,   104,   489,   326,   409,   302,   493,   372,
     305,   107,   486,   107,   499,   483,   316,   608,   318,   319,
     423,   489,   322,   323,   411,   493,   326,   123,   107,   123,
     318,   499,   332,   103,   322,   323,   107,   107,    10,    11,
     224,   225,   226,   227,   123,   100,   101,   102,   585,   104,
     502,   102,   123,   100,   101,   102,   102,   104,   103,   102,
     360,   411,   107,   474,    12,    13,    14,   102,   557,   521,
     559,   560,   360,   103,   410,   103,   613,   107,   103,   107,
     483,   509,   107,   511,   512,    33,   489,   105,   103,   107,
     493,   453,   107,   100,   101,   102,   499,   104,   295,   462,
     103,   464,   639,   103,   107,   642,   102,   107,   104,   430,
     595,   411,   100,   101,   102,     8,   104,   606,   103,   419,
       0,   103,   107,     9,   103,   107,   323,   595,   107,   326,
     103,   419,   432,   103,   107,   103,   103,   107,   432,   107,
     107,    15,    16,   506,   432,   119,   102,   510,   104,    75,
     445,    77,   112,   453,   102,   607,   104,   118,   106,   611,
      40,    41,   113,   114,   115,    45,   105,    21,   107,    49,
     491,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   105,   103,   107,   637,   270,   271,   272,   273,
     108,   109,   644,   645,   646,   623,   105,   105,   107,   107,
      33,    81,    19,    20,   102,   657,   105,   106,    88,    84,
      85,   103,   664,   130,   131,   578,   103,   580,   581,   124,
     648,   584,   585,   651,   107,   653,   266,   267,   591,   107,
     682,   683,   103,   685,   268,   269,   688,   274,   275,    33,
     235,   236,   107,   122,   696,    95,   698,   699,   125,   104,
     613,   103,   122,   125,   706,   103,   103,   102,     3,   105,
     103,   125,   103,   107,   103,   103,   103,   103,   103,   120,
     104,   122,   121,   103,     3,   107,   639,   640,   105,   642,
     103,   121,   102,   125,   103,   647,     1,   102,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   125,    13,    14,
     125,   123,   123,   666,   667,   123,    21,   121,   124,   102,
     102,   102,   125,   103,   121,   102,   105,   121,    33,    34,
      68,    36,    37,   123,   687,    40,    41,    42,   102,    85,
     103,   103,   102,    48,    49,    50,   103,    84,    84,   121,
      55,   103,   123,    58,   121,   103,    61,   647,   103,    44,
     103,   103,   123,    68,   123,   276,    71,    72,    73,    74,
      75,   103,   277,   279,    79,    80,   278,   280,    83,   179,
     319,    86,    87,    88,    89,    90,    91,    92,   316,   491,
      95,    96,    97,    98,   210,   100,   101,   102,   445,   344,
     595,    36,   332,   108,   109,   110,   111,   112,   113,   626,
     465,   360,   626,   624,    81,    49,    88,   419,   123,   124,
     125,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   446,    13,    14,   320,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    83,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    43,    -1,
      45,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    56,    57,    58,    -1,    60,    -1,    -1,    63,    64,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,   124,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      83,    -1,    -1,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,     0,     1,    -1,     3,    -1,    87,    88,
      89,    90,    91,    10,    11,    -1,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,    35,    -1,
      -1,    38,    39,    -1,    -1,   124,    43,    -1,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    81,    82,    -1,    -1,    -1,     0,
       1,    -1,     3,    -1,    -1,    -1,    93,    -1,    -1,    10,
      11,    98,    99,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,   123,    38,    39,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    -1,    -1,    -1,
      51,    52,    53,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,    10,
      11,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   123,    13,    14,    -1,    -1,    38,    39,    -1,
      -1,    21,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    33,    -1,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    58,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    98,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,   124,   125,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    35,    -1,    21,    38,    39,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    -1,    33,    -1,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    58,    -1,    -1,    77,    78,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    79,    80,    -1,    98,    99,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,    -1,    10,
      11,   108,   109,   110,   111,   112,   113,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   124,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    38,    39,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    -1,    33,    -1,
      -1,    52,    53,    54,    -1,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    58,    -1,    -1,    77,    78,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    98,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
      10,    11,    -1,   108,   109,   110,   111,   112,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,   123,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    38,    39,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,    33,
      -1,    -1,    52,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    58,    -1,    -1,    77,    78,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    98,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   123,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     123,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   123,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,     3,    -1,    87,    88,    89,    90,
      91,    10,    11,    -1,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,   123,    -1,    43,    -1,    45,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    56,    57,    -1,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,    35,    -1,    -1,    38,    39,
      -1,    -1,   121,    43,    -1,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    56,    57,    -1,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    98,    99,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,   122,    43,   124,    45,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,    -1,    -1,
     108,   109,   110,   111,   112,   113,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
      -1,    -1,   108,   109,   110,   111,   112,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,    -1,    -1,   108,   109,   110,   111,   112,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    -1,   100,   101,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,    -1,    -1,   108,   109,   110,
     111,   112,   113,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    97,    98,    -1,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    96,    97,    98,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    -1,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,     3,    -1,    87,    88,    89,    90,    91,    10,
      11,    -1,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    -1,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,     3,    -1,
      81,    82,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,    38,    39,    -1,    -1,    -1,    43,    -1,
      45,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    56,    57,    -1,    -1,    60,    -1,    -1,    63,    64,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    81,    82,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    38,
      39,    -1,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    54,    -1,    56,    57,    -1,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    81,    82,    -1,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,    38,    39,    -1,    -1,    -1,
      43,    -1,    45,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    56,    57,    -1,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,     3,    -1,    81,    82,
      -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,    38,    39,    -1,    -1,    -1,    43,    -1,    45,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,    56,
      57,    10,    11,    60,    -1,    -1,    63,    64,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    81,    82,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,
      -1,    98,    -1,    52,    53,    54,   103,    56,    57,    -1,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    10,    11,    35,    38,    39,    43,    45,
      46,    47,    51,    52,    53,    54,    56,    57,    59,    60,
      62,    63,    64,    65,    66,    67,    70,    77,    78,    81,
      82,    93,    98,    99,   102,   112,   113,   123,   155,   156,
     159,   160,   162,   165,   171,   178,   179,   186,   232,   233,
     234,   235,   244,   246,   123,   125,    76,   181,    33,     3,
      10,    11,   124,   127,   102,    94,   104,   127,   245,   102,
     178,    39,    67,   186,   187,   188,   186,   188,   123,   157,
     158,   178,   156,   156,   124,   127,   156,   238,   239,   240,
     100,   101,   102,   180,   179,     0,   234,   102,   247,   172,
     124,     3,     4,     5,     6,     7,     8,     9,    10,    13,
      14,    21,    33,    58,    71,    72,    73,    74,    75,    79,
      80,    87,    88,    89,    90,    91,    95,    96,    97,    98,
     100,   101,   102,   108,   109,   110,   111,   112,   113,   128,
     129,   130,   131,   132,   133,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   160,   189,   196,   246,   245,   127,
     177,    33,   123,   127,   161,   103,   186,   187,   186,   107,
     123,   122,   238,   164,   124,   178,   241,   242,   124,   240,
       3,    54,   103,   189,   191,   192,   193,   194,   195,   196,
     104,   102,    10,    11,   248,     1,     3,   174,   175,   176,
     173,    33,    10,    98,   102,   135,   246,   135,     3,    33,
      95,   140,   102,   135,   102,   102,   102,   102,   102,   102,
     102,   102,   135,   102,    33,   139,   139,     1,   124,   153,
     196,   207,   136,   136,   136,   136,   136,   136,     7,    79,
       8,     9,    12,    13,    14,    33,   102,   104,   106,   189,
     190,   104,   136,   113,   114,   115,   108,   109,    15,    16,
      17,    18,   116,   117,    19,    20,   112,   118,   119,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   120,   122,   103,   107,   102,   160,   180,   186,   197,
     198,   103,    33,   123,   105,   106,   127,   102,   103,   158,
     178,   124,   152,   199,   124,   166,   167,   168,   189,   163,
     107,   123,   236,   189,   196,   181,   102,   178,   186,   103,
     107,   103,   107,   105,   150,   151,   154,    39,   127,   182,
     183,    33,   122,   125,   107,   174,   127,   196,   135,   135,
     135,   135,   152,   153,   153,   196,   153,   190,   190,   103,
     208,   103,   103,   103,   127,   127,   103,   134,   152,   153,
     127,   102,   104,   105,   153,   136,   136,   136,   141,   141,
     142,   142,   143,   143,   143,   143,   144,   144,   145,   146,
     147,   148,   149,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   153,   152,   152,   103,   193,   197,   104,
     198,   102,   180,   127,   245,   127,   130,   199,   200,   237,
     125,   168,    10,   121,   169,   170,   178,   166,   242,   155,
     156,   209,   210,   243,   178,   181,     3,    69,   181,    69,
     195,   181,   105,   102,   103,   107,   249,   154,   176,   125,
     103,   103,   107,   107,   103,   103,   103,   103,   103,   103,
     103,   102,   104,   102,   104,   209,   136,   103,   107,   105,
     103,   134,   153,   136,   105,   121,   181,   103,   103,   105,
     154,   103,   193,   104,   123,   103,   107,   125,   243,   121,
     154,   107,   123,   121,   125,     1,     3,    34,    36,    37,
      40,    41,    42,    48,    49,    50,    55,    61,    68,    83,
      86,    87,    88,    92,   123,   153,   201,   202,   203,   207,
     211,   212,   213,   215,   216,   217,   218,   219,   220,   229,
     230,   231,   155,   125,   181,   151,   184,   185,   103,   183,
     248,   128,   196,   103,   134,   153,   103,   134,   153,   211,
     152,   103,   105,   136,   152,   181,   181,   105,   181,   103,
     105,   154,   125,   199,   125,   154,    10,   170,   154,   123,
     121,    67,   102,   123,   154,   123,   121,   201,   102,     3,
     113,   102,   123,   153,   102,   102,   207,   123,   153,   207,
     207,   102,   123,   201,   103,   107,   103,   103,   103,   105,
     103,   105,   125,   181,   181,   181,   105,   204,   102,   130,
     121,   206,    68,   123,   153,   123,   153,   153,   214,   123,
     153,   214,    84,    85,   221,   222,   223,   224,   228,   123,
     153,   184,   181,   201,   130,    33,   121,   205,   201,   102,
     123,   214,   123,   123,   103,   103,   103,   102,   225,   207,
     228,    84,   227,    84,   224,   226,   227,   103,    33,   121,
     103,   121,   201,   214,   103,   153,   123,   123,   214,   201,
     201,   201,     1,   196,   207,   207,   201,   103,   121,   103,
     103,   201,   103,   103,   153,   103,   153,   123,    44,   103,
     103,   128,   103,   123,   201,   201,   103,   201,   103,   103,
     153,   201,   103,   201,   201,   201,   103,   201
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 1321 "c_grammar.y"
    {
				/* Resolve the identifier to a node */
				void *data = CScopeLookup((yyvsp[(1) - (1)].name));
				ILType *type, *decayedType;
				if(!data)
				{
					/* We don't know what this identifier is, so return
					   a generic node until the next higher level can
					   make a determination as to whether the name is truly
					   undeclared or a forward reference to a function */
					(yyval.node) = ILNode_Identifier_create((yyvsp[(1) - (1)].name));
				}
				else
				{
					/* Determine the kind of node to create */
					switch(CScopeGetKind(data))
					{
						case C_SCDATA_LOCAL_VAR:
						{
							/* Create a local variable reference */
							type = CScopeGetType(data);
							decayedType = CTypeDecay(&CCCodeGen, type);
							(yyval.node) = ILNode_CLocalVar_create
								(CScopeGetIndex(data),
								 ILTypeToMachineType(decayedType), type,
								 decayedType);
						}
						break;

						case C_SCDATA_PARAMETER_VAR:
						{
							/* Create a parameter variable reference */
							type = CScopeGetType(data);
							if(!CTypeIsByRef(type))
							{
								(yyval.node) = ILNode_CArgumentVar_create
									(CScopeGetIndex(data),
									 ILTypeToMachineType(type), type);
							}
							else
							{
								type = CTypeGetByRef(type);
								(yyval.node) = ILNode_RefArgumentVar_create
									(CScopeGetIndex(data),
									 ILTypeToMachineType(type), type);
							}
						}
						break;

						case C_SCDATA_GLOBAL_VAR:
						case C_SCDATA_GLOBAL_VAR_FORWARD:
						{
							/* Create a global variable reference */
							type = CScopeGetType(data);
							decayedType = CTypeDecay(&CCCodeGen, type);
							(yyval.node) = ILNode_CGlobalVar_create
								((yyvsp[(1) - (1)].name), type, decayedType);
							usedGlobalVar = 1;
						}
						break;

						case C_SCDATA_FUNCTION:
						case C_SCDATA_FUNCTION_FORWARD:
						case C_SCDATA_FUNCTION_FORWARD_KR:
						case C_SCDATA_FUNCTION_INFERRED:
						{
							(yyval.node) = ILNode_FunctionRef_create
									((yyvsp[(1) - (1)].name), CScopeGetType(data));
						}
						break;

						case C_SCDATA_ENUM_CONSTANT:
						{
							ILInt32 value = CScopeGetEnumConst(data);
							if(value >= 0)
							{
								(yyval.node) = ILNode_Int32_create
									((ILUInt64)value, 0, 1);
							}
							else
							{
								(yyval.node) = ILNode_Int32_create
									((ILUInt64)(ILUInt32)(-value), 1, 1);
							}
						}
						break;

						default:
						{
							/* Previously detected an undeclared identifier */
							(yyval.node) = ILNode_Error_create();
						}
						break;
					}
				}
			}
    break;

  case 7:
#line 1417 "c_grammar.y"
    {
				/* Convert the integer value into a node */
				switch((yyvsp[(1) - (1)].integer).type)
				{
					case ILMachineType_Int8:
					{
						(yyval.node) = ILNode_Int8_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_UInt8:
					{
						(yyval.node) = ILNode_UInt8_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_Int16:
					{
						(yyval.node) = ILNode_Int16_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_UInt16:
					{
						(yyval.node) = ILNode_UInt16_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_Int32:
					{
						(yyval.node) = ILNode_Int32_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_UInt32:
					{
						(yyval.node) = ILNode_UInt32_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_Int64:
					{
						(yyval.node) = ILNode_Int64_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_UInt64:
					{
						(yyval.node) = ILNode_UInt64_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_NativeInt:
					{
						(yyval.node) = ILNode_Int_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					case ILMachineType_NativeUInt:
					{
						(yyval.node) = ILNode_UInt_create((yyvsp[(1) - (1)].integer).value, (yyvsp[(1) - (1)].integer).isneg, 1);
					}
					break;

					default:
					{
						/* Shouldn't happen */
						(yyval.node) = ILNode_Error_create();
					}
					break;
				}
			}
    break;

  case 8:
#line 1489 "c_grammar.y"
    {
				/* Convert the floating-point value into a node */
				if((yyvsp[(1) - (1)].real).type == ILMachineType_Float32)
				{
					(yyval.node) = ILNode_Float32_create((yyvsp[(1) - (1)].real).value);
				}
				else
				{
					(yyval.node) = ILNode_Float64_create((yyvsp[(1) - (1)].real).value);
				}
			}
    break;

  case 9:
#line 1500 "c_grammar.y"
    {
				/* Convert the imaginary floating-point value into a node */
				/* TODO: true imaginary constants */
				if((yyvsp[(1) - (1)].real).type == ILMachineType_Float32)
				{
					(yyval.node) = ILNode_Float32_create((yyvsp[(1) - (1)].real).value);
				}
				else
				{
					(yyval.node) = ILNode_Float64_create((yyvsp[(1) - (1)].real).value);
				}
			}
    break;

  case 10:
#line 1512 "c_grammar.y"
    {
				(yyval.node) = ILNode_CString_create((yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).len);
			}
    break;

  case 11:
#line 1515 "c_grammar.y"
    {
				(yyval.node) = ILNode_CWString_create((yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).len);
			}
    break;

  case 12:
#line 1518 "c_grammar.y"
    {
				(yyval.node) = ILNode_String_create((yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).len);
			}
    break;

  case 13:
#line 1521 "c_grammar.y"
    {
				/* Create a reference to the local "__func__" array.
				   In this implementation, we create a reference to
				   the string pool.  The pool implementation will take
				   care of pointing all copies of the function name
				   at the same memory location */
				ILIntString str = ILInternString(functionName, -1);
				(yyval.node) = ILNode_CString_create(str.string, str.len);
			}
    break;

  case 14:
#line 1530 "c_grammar.y"
    { (yyval.node) = ILNode_Null_create(); }
    break;

  case 15:
#line 1531 "c_grammar.y"
    { (yyval.node) = ILNode_True_create(); }
    break;

  case 16:
#line 1532 "c_grammar.y"
    { (yyval.node) = ILNode_False_create(); }
    break;

  case 17:
#line 1533 "c_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 18:
#line 1534 "c_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 19:
#line 1535 "c_grammar.y"
    { (yyval.node) = ILNode_Error_create(); }
    break;

  case 20:
#line 1539 "c_grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 21:
#line 1540 "c_grammar.y"
    {
				(yyval.string) = ILInternString(functionName, strlen(functionName));
			}
    break;

  case 22:
#line 1543 "c_grammar.y"
    {
				(yyval.string) = ILInternAppendedString((yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
			}
    break;

  case 23:
#line 1546 "c_grammar.y"
    {
				(yyval.string) = ILInternAppendedString
					((yyvsp[(1) - (2)].string), ILInternString(functionName, strlen(functionName)));
			}
    break;

  case 24:
#line 1553 "c_grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 25:
#line 1554 "c_grammar.y"
    {
				(yyval.string) = ILInternAppendedString((yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
			}
    break;

  case 26:
#line 1560 "c_grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 27:
#line 1561 "c_grammar.y"
    {
				(yyval.string) = ILInternAppendedString((yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
			}
    break;

  case 29:
#line 1568 "c_grammar.y"
    {
				(yyval.node) = ILNode_CArrayAccess_create(FixIdentifierNode((yyvsp[(1) - (4)].node), 0), (yyvsp[(3) - (4)].node));
			}
    break;

  case 30:
#line 1571 "c_grammar.y"
    {
				(yyval.node) = ILNode_CInvocationExpression_create
						(FixIdentifierNode((yyvsp[(1) - (3)].node), 1), 0);
			}
    break;

  case 31:
#line 1575 "c_grammar.y"
    {
				(yyval.node) = ILNode_CInvocationExpression_create
						(FixIdentifierNode((yyvsp[(1) - (4)].node), 1), (yyvsp[(3) - (4)].node));
			}
    break;

  case 32:
#line 1579 "c_grammar.y"
    {
				(yyval.node) = ILNode_CMemberField_create
						(FixIdentifierNode((yyvsp[(1) - (3)].node), 0), (yyvsp[(3) - (3)].name));
			}
    break;

  case 33:
#line 1583 "c_grammar.y"
    {
				(yyval.node) = ILNode_CStaticField_create
						(ILNode_CTypeExpression_create
							(CScopeGetType(CScopeLookup((yyvsp[(1) - (3)].name)))), (yyvsp[(3) - (3)].name));
			}
    break;

  case 34:
#line 1588 "c_grammar.y"
    {
				(yyval.node) = ILNode_CStaticField_create
						(ILNode_CTypeExpression_create((yyvsp[(1) - (3)].type)), (yyvsp[(3) - (3)].name));
			}
    break;

  case 35:
#line 1592 "c_grammar.y"
    {
				(yyval.node) = ILNode_CStaticField_create
						(FixIdentifierNode((yyvsp[(1) - (3)].node), 0), (yyvsp[(3) - (3)].name));
			}
    break;

  case 36:
#line 1596 "c_grammar.y"
    {
				(yyval.node) = ILNode_CDerefField_create
						(FixIdentifierNode((yyvsp[(1) - (3)].node), 0), (yyvsp[(3) - (3)].name));
			}
    break;

  case 37:
#line 1600 "c_grammar.y"
    {
				(yyval.node) = ILNode_PostInc_create(FixIdentifierNode((yyvsp[(1) - (2)].node), 0));
			}
    break;

  case 38:
#line 1603 "c_grammar.y"
    {
				(yyval.node) = ILNode_PostDec_create(FixIdentifierNode((yyvsp[(1) - (2)].node), 0));
			}
    break;

  case 39:
#line 1606 "c_grammar.y"
    {
				(yyval.node) = ILNode_VaArg_create((yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].type));
			}
    break;

  case 40:
#line 1609 "c_grammar.y"
    {
				(yyval.node) = ILNode_VaStart_create((yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].name));
			}
    break;

  case 41:
#line 1612 "c_grammar.y"
    {
				(yyval.node) = ILNode_VaStart_create((yyvsp[(3) - (4)].node), 0);
			}
    break;

  case 42:
#line 1615 "c_grammar.y"
    {
				(yyval.node) = ILNode_VaEnd_create((yyvsp[(3) - (4)].node));
			}
    break;

  case 43:
#line 1618 "c_grammar.y"
    {
				(yyval.node) = ILNode_SetJmp_create((yyvsp[(3) - (4)].node));
			}
    break;

  case 44:
#line 1621 "c_grammar.y"
    {
				(yyval.node) = ILNode_AllocA_create((yyvsp[(3) - (4)].node));
			}
    break;

  case 46:
#line 1628 "c_grammar.y"
    {
				(yyval.node) = ILNode_ArgList_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 47:
#line 1634 "c_grammar.y"
    { (yyval.node) = FixIdentifierNode((yyvsp[(1) - (1)].node), 0); }
    break;

  case 48:
#line 1635 "c_grammar.y"
    { (yyval.node) = ILNode_PreInc_create((yyvsp[(2) - (2)].node)); }
    break;

  case 49:
#line 1636 "c_grammar.y"
    { (yyval.node) = ILNode_PreDec_create((yyvsp[(2) - (2)].node)); }
    break;

  case 50:
#line 1637 "c_grammar.y"
    {
				/* Negate simple integer and floating point values in-place */
				(yyval.node) = ILNode_Neg_create((yyvsp[(2) - (2)].node));
			}
    break;

  case 51:
#line 1641 "c_grammar.y"
    { (yyval.node) = ILNode_UnaryPlus_create((yyvsp[(2) - (2)].node)); }
    break;

  case 52:
#line 1642 "c_grammar.y"
    { (yyval.node) = ILNode_Not_create((yyvsp[(2) - (2)].node)); }
    break;

  case 53:
#line 1643 "c_grammar.y"
    {
			(yyval.node) = ILNode_LogicalNot_create(ILNode_ToBool_create((yyvsp[(2) - (2)].node)));
		}
    break;

  case 54:
#line 1646 "c_grammar.y"
    { (yyval.node) = ILNode_AddressOf_create((yyvsp[(2) - (2)].node)); }
    break;

  case 55:
#line 1647 "c_grammar.y"
    { (yyval.node) = ILNode_CDeref_create((yyvsp[(2) - (2)].node)); }
    break;

  case 56:
#line 1648 "c_grammar.y"
    { (yyval.node) = ILNode_SizeOfExpr_create((yyvsp[(2) - (2)].node)); }
    break;

  case 57:
#line 1649 "c_grammar.y"
    { (yyval.node) = ILNode_SizeOfType_create((yyvsp[(3) - (4)].type)); }
    break;

  case 58:
#line 1650 "c_grammar.y"
    { (yyval.node) = ILNode_CLabelRef_create((yyvsp[(2) - (2)].name)); }
    break;

  case 59:
#line 1651 "c_grammar.y"
    {
				(yyval.node) = ILNode_Overflow_create((yyvsp[(3) - (4)].node));
			}
    break;

  case 60:
#line 1654 "c_grammar.y"
    {
				(yyval.node) = ILNode_NoOverflow_create((yyvsp[(3) - (4)].node));
			}
    break;

  case 61:
#line 1657 "c_grammar.y"
    {
				/* Perform inline semantic analysis on the expression */
				CSemValue value = CSemInlineAnalysis
						(&CCCodeGen, (yyvsp[(2) - (2)].node), &((yyvsp[(2) - (2)].node)), CCurrentScope);

				/* Use the type of the expression as our return value */
				(yyval.node) = ILNode_CSharpTypeOf_create(CSemGetType(value));
			}
    break;

  case 62:
#line 1665 "c_grammar.y"
    {
				(yyval.node) = ILNode_CSharpTypeOf_create((yyvsp[(3) - (4)].type));
			}
    break;

  case 63:
#line 1668 "c_grammar.y"
    {
				(yyval.node) = ILNode_CBox_create((yyvsp[(3) - (4)].node));
			}
    break;

  case 64:
#line 1671 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 65:
#line 1672 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 67:
#line 1677 "c_grammar.y"
    {
				(yyval.node) = ILNode_CastType_create((yyvsp[(4) - (4)].node), (yyvsp[(2) - (4)].type));
			}
    break;

  case 68:
#line 1684 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewObject_create(ILGC_Unknown, (yyvsp[(2) - (4)].type), 0, (yyvsp[(1) - (4)].kind)); 
			}
    break;

  case 69:
#line 1687 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewObject_create(ILGC_Unknown, (yyvsp[(2) - (5)].type), (yyvsp[(4) - (5)].node), (yyvsp[(1) - (5)].kind)); 
			}
    break;

  case 70:
#line 1690 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewObject_create(ILGC_Managed, (yyvsp[(3) - (5)].type), 0, (yyvsp[(2) - (5)].kind)); 
			}
    break;

  case 71:
#line 1693 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewObject_create(ILGC_Managed, (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].node), (yyvsp[(2) - (6)].kind)); 
			}
    break;

  case 72:
#line 1696 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewObject_create(ILGC_Unmanaged, (yyvsp[(3) - (5)].type), 0, (yyvsp[(2) - (5)].kind)); 
			}
    break;

  case 73:
#line 1699 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewObject_create(ILGC_Unmanaged, (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].node), (yyvsp[(2) - (6)].kind)); 
			}
    break;

  case 74:
#line 1702 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewArray_create(ILGC_Unknown, (yyvsp[(2) - (5)].type), (yyvsp[(4) - (5)].node), (yyvsp[(1) - (5)].kind));
			}
    break;

  case 75:
#line 1705 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewArray_create(ILGC_Managed, (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].node), (yyvsp[(2) - (6)].kind));
			}
    break;

  case 76:
#line 1708 "c_grammar.y"
    {
				(yyval.node) = ILNode_CNewArray_create(ILGC_Unmanaged, (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].node), (yyvsp[(2) - (6)].kind));
			}
    break;

  case 77:
#line 1714 "c_grammar.y"
    {
				(yyval.node) = ILNode_CDelete_create(0, (yyvsp[(2) - (2)].node), 0, (yyvsp[(1) - (2)].kind));
			}
    break;

  case 78:
#line 1717 "c_grammar.y"
    {
				(yyval.node) = ILNode_CDelete_create(0, (yyvsp[(4) - (4)].node), 1, (yyvsp[(1) - (4)].kind));
			}
    break;

  case 79:
#line 1720 "c_grammar.y"
    {
				(yyval.node) = ILNode_CDelete_create((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), 1, (yyvsp[(1) - (5)].kind));
			}
    break;

  case 80:
#line 1726 "c_grammar.y"
    { (yyval.kind) = 0; }
    break;

  case 81:
#line 1727 "c_grammar.y"
    { (yyval.kind) = 1; }
    break;

  case 82:
#line 1731 "c_grammar.y"
    { (yyval.kind) = 0; }
    break;

  case 83:
#line 1732 "c_grammar.y"
    { (yyval.kind) = 1; }
    break;

  case 85:
#line 1737 "c_grammar.y"
    {
				(yyval.node) = ILNode_Mul_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 86:
#line 1740 "c_grammar.y"
    {
				(yyval.node) = ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 87:
#line 1743 "c_grammar.y"
    {
				(yyval.node) = ILNode_Rem_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 89:
#line 1750 "c_grammar.y"
    {
				(yyval.node) = ILNode_Add_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 90:
#line 1753 "c_grammar.y"
    {
				(yyval.node) = ILNode_Sub_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 92:
#line 1760 "c_grammar.y"
    {
				(yyval.node) = ILNode_Shl_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 93:
#line 1763 "c_grammar.y"
    {
				(yyval.node) = ILNode_Shr_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 95:
#line 1770 "c_grammar.y"
    {
				(yyval.node) = ILNode_Lt_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 96:
#line 1773 "c_grammar.y"
    {
				(yyval.node) = ILNode_Gt_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 97:
#line 1776 "c_grammar.y"
    {
				(yyval.node) = ILNode_Le_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 98:
#line 1779 "c_grammar.y"
    {
				(yyval.node) = ILNode_Ge_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 100:
#line 1786 "c_grammar.y"
    {
				(yyval.node) = ILNode_Eq_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 101:
#line 1789 "c_grammar.y"
    {
				(yyval.node) = ILNode_Ne_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 103:
#line 1796 "c_grammar.y"
    {
				(yyval.node) = ILNode_And_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 105:
#line 1803 "c_grammar.y"
    {
				(yyval.node) = ILNode_Xor_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 107:
#line 1810 "c_grammar.y"
    {
				(yyval.node) = ILNode_Or_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 109:
#line 1817 "c_grammar.y"
    {
				(yyval.node) = ILNode_LogicalAnd_create(ILNode_ToBool_create((yyvsp[(1) - (3)].node)),
											  ILNode_ToBool_create((yyvsp[(3) - (3)].node)));
			}
    break;

  case 111:
#line 1825 "c_grammar.y"
    {
				(yyval.node) = ILNode_LogicalOr_create(ILNode_ToBool_create((yyvsp[(1) - (3)].node)),
											 ILNode_ToBool_create((yyvsp[(3) - (3)].node)));
			}
    break;

  case 113:
#line 1833 "c_grammar.y"
    {
				(yyval.node) = ILNode_Conditional_create
						(ILNode_ToBool_create((yyvsp[(1) - (5)].node)), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 115:
#line 1841 "c_grammar.y"
    {
				(yyval.node) = ILNode_Assign_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 116:
#line 1844 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignMul_create(ILNode_Mul_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 117:
#line 1847 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignDiv_create(ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 118:
#line 1850 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignRem_create(ILNode_Rem_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 119:
#line 1853 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignAdd_create(ILNode_Add_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 120:
#line 1856 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignSub_create(ILNode_Sub_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 121:
#line 1859 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignShl_create(ILNode_Shl_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 122:
#line 1862 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignShr_create(ILNode_Shr_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 123:
#line 1865 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignAnd_create(ILNode_And_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 124:
#line 1868 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignXor_create(ILNode_Xor_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 125:
#line 1871 "c_grammar.y"
    {
				(yyval.node) = ILNode_AssignOr_create(ILNode_Or_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 127:
#line 1878 "c_grammar.y"
    {
				(yyval.node) = ILNode_Comma_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 128:
#line 1884 "c_grammar.y"
    {
				(yyval.node) = ILNode_ToConst_create((yyvsp[(1) - (1)].node));
			}
    break;

  case 129:
#line 1890 "c_grammar.y"
    {
				CDeclSpec spec;

				/* Finalize the declaration specifier */
				if(CCurrentScope == CGlobalScope)
				{
					spec = CDeclSpecFinalize((yyvsp[(1) - (2)].declSpec), 0, 0, C_KIND_GLOBAL_NAME);
				}
				else
				{
					spec = CDeclSpecFinalize((yyvsp[(1) - (2)].declSpec), 0, 0, C_KIND_LOCAL_NAME);
				}

				/* Check for something that looks like a multiple typedef */
				if((((yyvsp[(1) - (2)].declSpec)).dupSpecifiers & C_SPEC_MULTIPLE_BASES) != 0 &&
				   (spec.specifiers & C_SPEC_TYPEDEF) != 0)
				{
					CCError(_("(may be a redeclaration of a typedef'ed name)"));
				}

				/* Check for useless declarations */
				if((!CTypeIsStruct(spec.baseType) &&
				    !CTypeIsUnion(spec.baseType) &&
					(spec.specifiers & C_SPEC_ENUM) == 0 &&
					!CTypeIsEnum(spec.baseType)) ||
				    (spec.specifiers & C_SPEC_STORAGE) != 0)
				{
					CCWarning(_("useless keyword or type name "
								"in empty declaration"));
				}

				/* This declaration's code is the empty statement */
				(yyval.node) = ILNode_Empty_create();
			}
    break;

  case 130:
#line 1924 "c_grammar.y"
    {
				CDeclSpec spec;
				ILNode_CDeclarator *decl;
				ILNode_ListIter iter;
				ILNode *list;

				/* Find the first declarator, for error reporting */
				if(!yyisa((yyvsp[(2) - (3)].node), ILNode_List))
				{
					decl = (ILNode_CDeclarator *)((yyvsp[(2) - (3)].node));
				}
				else
				{
					ILNode_ListIter_Init(&iter, (yyvsp[(2) - (3)].node));
					decl = (ILNode_CDeclarator *)(ILNode_ListIter_Next(&iter));
				}

				/* Finalize the declaration specifier */
				if(CCurrentScope == CGlobalScope)
				{
					spec = CDeclSpecFinalize
						((yyvsp[(1) - (3)].declSpec), decl->decl.node, decl->decl.name,
						 C_KIND_GLOBAL_NAME);
				}
				else
				{
					spec = CDeclSpecFinalize
						((yyvsp[(1) - (3)].declSpec), decl->decl.node, decl->decl.name,
						 C_KIND_LOCAL_NAME);
				}

				/* Process the declarations in the list */
				list = 0;
				if(yyisa((yyvsp[(2) - (3)].node), ILNode_CInitDeclarator))
				{
					ProcessDeclaration(spec, decl->decl,
						   ((ILNode_CInitDeclarator *)decl)->init, &list);
				}
				else if(yyisa((yyvsp[(2) - (3)].node), ILNode_CDeclarator))
				{
					ProcessDeclaration(spec, decl->decl, 0, &list);
				}
				else
				{
					ILNode_ListIter_Init(&iter, (yyvsp[(2) - (3)].node));
					while((decl = (ILNode_CDeclarator *)
							ILNode_ListIter_Next(&iter)) != 0)
					{
						if(yyisa(decl, ILNode_CInitDeclarator))
						{
							ProcessDeclaration(spec, decl->decl,
							   ((ILNode_CInitDeclarator *)decl)->init, &list);
						}
						else
						{
							ProcessDeclaration(spec, decl->decl, 0, &list);
						}
					}
				}
				if(!list)
				{
					list = ILNode_Empty_create();
				}
				(yyval.node) = list;
			}
    break;

  case 132:
#line 1993 "c_grammar.y"
    {
				(yyval.declSpec) = CDeclSpecCombine((yyvsp[(1) - (2)].declSpec), (yyvsp[(2) - (2)].declSpec));
			}
    break;

  case 134:
#line 1997 "c_grammar.y"
    {
				(yyval.declSpec) = CDeclSpecCombine((yyvsp[(1) - (2)].declSpec), (yyvsp[(2) - (2)].declSpec));
			}
    break;

  case 136:
#line 2004 "c_grammar.y"
    {
				if(yyisa((yyvsp[(1) - (3)].node), ILNode_List))
				{
					ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
					(yyval.node) = (yyvsp[(1) - (3)].node);
				}
				else
				{
					(yyval.node) = ILNode_List_create();
					ILNode_List_Add((yyval.node), (yyvsp[(1) - (3)].node));
					ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
				}
			}
    break;

  case 137:
#line 2020 "c_grammar.y"
    {
				(yyval.node) = ILNode_CDeclarator_create((yyvsp[(1) - (1)].decl));
			}
    break;

  case 138:
#line 2023 "c_grammar.y"
    {
				(yyval.node) = ILNode_CInitDeclarator_create((yyvsp[(1) - (3)].decl), (yyvsp[(3) - (3)].node));
			}
    break;

  case 139:
#line 2029 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_TYPEDEF); }
    break;

  case 140:
#line 2030 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_EXTERN); }
    break;

  case 141:
#line 2031 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_STATIC); }
    break;

  case 142:
#line 2032 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_AUTO); }
    break;

  case 143:
#line 2033 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_REGISTER); }
    break;

  case 144:
#line 2034 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_INLINE); }
    break;

  case 145:
#line 2035 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), (yyvsp[(3) - (4)].kind)); }
    break;

  case 146:
#line 2039 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Int8); }
    break;

  case 147:
#line 2040 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_SHORT); }
    break;

  case 148:
#line 2041 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Int32); }
    break;

  case 149:
#line 2042 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_LONG); }
    break;

  case 150:
#line 2043 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Int64); }
    break;

  case 151:
#line 2044 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_UInt32); }
    break;

  case 152:
#line 2045 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_SIGNED); }
    break;

  case 153:
#line 2046 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_UNSIGNED); }
    break;

  case 154:
#line 2047 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Float32); }
    break;

  case 155:
#line 2048 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Float64); }
    break;

  case 156:
#line 2049 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_CONST); }
    break;

  case 157:
#line 2050 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_VOLATILE); }
    break;

  case 158:
#line 2051 "c_grammar.y"
    { CDeclSpecSet((yyval.declSpec), C_SPEC_BOX); }
    break;

  case 159:
#line 2052 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Void); }
    break;

  case 160:
#line 2053 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Boolean); }
    break;

  case 161:
#line 2054 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), ILType_Char); }
    break;

  case 162:
#line 2055 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), CTypeCreateVaList(&CCCodeGen)); }
    break;

  case 163:
#line 2056 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), (yyvsp[(1) - (1)].type)); }
    break;

  case 164:
#line 2057 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), (yyvsp[(1) - (1)].type));
									  (yyval.declSpec).specifiers = C_SPEC_ENUM; }
    break;

  case 165:
#line 2059 "c_grammar.y"
    {
				/* Perform inline semantic analysis on the expression */
				CSemValue value = CSemInlineAnalysis
						(&CCCodeGen, (yyvsp[(3) - (4)].node), &((yyvsp[(3) - (4)].node)), CCurrentScope);

				/* Use the type of the expression as our return value */
				CDeclSpecSetType((yyval.declSpec), CSemGetType(value));
			}
    break;

  case 166:
#line 2067 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), (yyvsp[(3) - (4)].type)); }
    break;

  case 167:
#line 2068 "c_grammar.y"
    {
				/* Look up the type in the current scope.  We know that
				   the typedef is present, because the lexer found it */
				ILType *type = CScopeGetType(CScopeLookup((yyvsp[(1) - (1)].name)));
				CDeclSpecSetType((yyval.declSpec), type);
			}
    break;

  case 168:
#line 2074 "c_grammar.y"
    { CDeclSpecSetType((yyval.declSpec), (yyvsp[(1) - (1)].type)); }
    break;

  case 169:
#line 2078 "c_grammar.y"
    { (yyval.kind) = 0; }
    break;

  case 170:
#line 2079 "c_grammar.y"
    {
				/* Check for the "thread" declaration specifier */
				if(!strcmp((yyvsp[(1) - (1)].name), "thread") || !strcmp((yyvsp[(1) - (1)].name), "__thread__"))
				{
					(yyval.kind) = C_SPEC_THREAD_SPECIFIC;
				}
				else
				{
					(yyval.kind) = 0;
				}
			}
    break;

  case 171:
#line 2090 "c_grammar.y"
    { (yyval.kind) = 0; }
    break;

  case 172:
#line 2094 "c_grammar.y"
    {
				/* Look for a definition in the local scope */
				if(!CScopeHasStructOrUnion((yyvsp[(2) - (3)].name), (yyvsp[(1) - (3)].kind)))
				{
					/* Define the struct or union type */
					(yyval.structInfo).type = CTypeDefineStructOrUnion
							(&CCCodeGen, (yyvsp[(2) - (3)].name), (yyvsp[(1) - (3)].kind), functionName);
					if(!((yyval.structInfo).type))
					{
						/* This shouldn't happen, but fail gracefully */
						if((yyvsp[(1) - (3)].kind) == C_STKIND_STRUCT)
						{
							CCError(_("`struct %s' is already defined"), (yyvsp[(2) - (3)].name));
						}
						else
						{
							CCError(_("`union %s' is already defined"), (yyvsp[(2) - (3)].name));
						}
						(yyval.structInfo).type = CTypeDefineAnonStructOrUnion
							(&CCCodeGen, currentStruct, functionName, (yyvsp[(1) - (3)].kind));
					}
				}
				else
				{
					/* We've already seen a definition for this type before */
					if((yyvsp[(1) - (3)].kind) == C_STKIND_STRUCT)
					{
						CCError(_("redefinition of `struct %s'"), (yyvsp[(2) - (3)].name));
					}
					else
					{
						CCError(_("redefinition of `union %s'"), (yyvsp[(2) - (3)].name));
					}

					/* Create an anonymous type as a place-holder */
					(yyval.structInfo).type = CTypeDefineAnonStructOrUnion
						(&CCCodeGen, currentStruct, functionName, (yyvsp[(1) - (3)].kind));
				}

				/* Push in a scope level for the structure */
				(yyval.structInfo).parent = currentStruct;
				currentStruct = (yyval.structInfo).type;

				/* Add the type to the current scope */
				CScopeAddStructOrUnion((yyvsp[(2) - (3)].name), (yyvsp[(1) - (3)].kind), (yyval.structInfo).type);
			}
    break;

  case 173:
#line 2140 "c_grammar.y"
    {
	  			/* Pop the structure scope */
				currentStruct = (yyvsp[(4) - (6)].structInfo).parent;

				/* Terminate the structure definition */
				(yyval.type) = CTypeEndStruct(&CCCodeGen, (yyvsp[(4) - (6)].structInfo).type, 0);
	  		}
    break;

  case 174:
#line 2147 "c_grammar.y"
    {
				/* Define an anonymous struct or union type */
				(yyval.structInfo).type = CTypeDefineAnonStructOrUnion
					(&CCCodeGen, currentStruct, functionName, (yyvsp[(1) - (2)].kind));

				/* Push in a scope level for the structure */
				(yyval.structInfo).parent = currentStruct;
				currentStruct = (yyval.structInfo).type;
			}
    break;

  case 175:
#line 2156 "c_grammar.y"
    {
	  			/* Pop the structure scope */
				currentStruct = (yyvsp[(3) - (5)].structInfo).parent;

				/* Terminate the structure definition */
				(yyval.type) = CTypeEndStruct(&CCCodeGen, (yyvsp[(3) - (5)].structInfo).type, 1);
	  		}
    break;

  case 176:
#line 2163 "c_grammar.y"
    {
				/* Look for an existing definition for this type */
				void *data = CScopeLookupStructOrUnion((yyvsp[(2) - (2)].name), (yyvsp[(1) - (2)].kind));
				if(!data)
				{
					/* Create a reference to the named struct or union type,
					   assuming that it is at the global level */
					(yyval.type) = CTypeCreateStructOrUnion
							(&CCCodeGen, (yyvsp[(2) - (2)].name), (yyvsp[(1) - (2)].kind), 0);
				}
				else
				{
					/* Use the type that was registered in the scope */
					(yyval.type) = CScopeGetType(data);
				}
			}
    break;

  case 177:
#line 2182 "c_grammar.y"
    { (yyval.kind) = C_STKIND_STRUCT; }
    break;

  case 178:
#line 2183 "c_grammar.y"
    { (yyval.kind) = C_STKIND_UNION; }
    break;

  case 183:
#line 2197 "c_grammar.y"
    {
				/* Process each of the declarators in the list */
				ILNode_ListIter iter;
				ILNode_CDeclarator *decl;
				CDeclSpec spec;
				if(yyisa((yyvsp[(2) - (3)].node), ILNode_List))
				{
					/* There are two or more declarators in the list */
					spec = CDeclSpecFinalize((yyvsp[(1) - (3)].declSpec), 0, 0, 0);
					ILNode_ListIter_Init(&iter, (yyvsp[(2) - (3)].node));
					while((decl = (ILNode_CDeclarator *)
							ILNode_ListIter_Next(&iter)) != 0)
					{
						if(yyisa(decl, ILNode_CBitFieldDeclarator))
						{
							ProcessBitField
								(spec, ((ILNode_CBitFieldDeclarator *)decl)
											->decl,
								 ((ILNode_CBitFieldDeclarator *)decl)
								 			->bitFieldSize);
						}
						else
						{
							ProcessField(spec, decl->decl);
						}
					}
				}
				else if(yyisa((yyvsp[(2) - (3)].node), ILNode_CBitFieldDeclarator))
				{
					/* There is a single bit field in the list */
					spec = CDeclSpecFinalize
						((yyvsp[(1) - (3)].declSpec), ((ILNode_CBitFieldDeclarator *)((yyvsp[(2) - (3)].node)))->decl.node,
						 ((ILNode_CBitFieldDeclarator *)((yyvsp[(2) - (3)].node)))->decl.name, 0);
					ProcessBitField
						(spec, ((ILNode_CBitFieldDeclarator *)((yyvsp[(2) - (3)].node)))->decl,
						 ((ILNode_CBitFieldDeclarator *)((yyvsp[(2) - (3)].node)))->bitFieldSize);
				}
				else
				{
					/* There is a single ordinary field in the list */
					spec = CDeclSpecFinalize
						((yyvsp[(1) - (3)].declSpec), ((ILNode_CDeclarator *)((yyvsp[(2) - (3)].node)))->decl.node,
						 ((ILNode_CDeclarator *)((yyvsp[(2) - (3)].node)))->decl.name, 0);
					ProcessField(spec, ((ILNode_CDeclarator *)((yyvsp[(2) - (3)].node)))->decl);
				}
			}
    break;

  case 185:
#line 2247 "c_grammar.y"
    {
				if(yyisa((yyvsp[(1) - (3)].node), ILNode_List))
				{
					ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
					(yyval.node) = (yyvsp[(1) - (3)].node);
				}
				else
				{
					(yyval.node) = ILNode_List_create();
					ILNode_List_Add((yyval.node), (yyvsp[(1) - (3)].node));
					ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
				}
			}
    break;

  case 186:
#line 2263 "c_grammar.y"
    { (yyval.node) = ILNode_CDeclarator_create((yyvsp[(1) - (1)].decl)); }
    break;

  case 187:
#line 2264 "c_grammar.y"
    {
				ILUInt32 size = EvaluateBitFieldSize((yyvsp[(2) - (2)].node));
				CDeclarator decl;
				CDeclSetName(decl, 0, 0);
				(yyval.node) = ILNode_CBitFieldDeclarator_create(decl, size);
			}
    break;

  case 188:
#line 2270 "c_grammar.y"
    {
				ILUInt32 size = EvaluateBitFieldSize((yyvsp[(3) - (3)].node));
				(yyval.node) = ILNode_CBitFieldDeclarator_create((yyvsp[(1) - (3)].decl), size);
			}
    break;

  case 189:
#line 2274 "c_grammar.y"
    {
				CDeclarator decl;
				CDeclSetName(decl, (yyvsp[(1) - (1)].name), ILQualIdentSimple((yyvsp[(1) - (1)].name)));
				(yyval.node) = ILNode_CDeclarator_create(decl);
			}
    break;

  case 190:
#line 2279 "c_grammar.y"
    {
				CDeclarator decl;
				ILUInt32 size = EvaluateBitFieldSize((yyvsp[(3) - (3)].node));
				CDeclSetName(decl, (yyvsp[(1) - (3)].name), ILQualIdentSimple((yyvsp[(1) - (3)].name)));
				(yyval.node) = ILNode_CBitFieldDeclarator_create(decl, size);
			}
    break;

  case 191:
#line 2288 "c_grammar.y"
    {
				/* Define an anonymous enum type */
				(yyval.structInfo).type = CTypeDefineAnonEnum
						(&CCCodeGen, functionName);

				/* Push in a scope level for the enum */
				(yyval.structInfo).parent = currentEnum;
				currentEnum = (yyval.structInfo).type;
				currentEnumValue = 0;
			}
    break;

  case 192:
#line 2298 "c_grammar.y"
    {
	  			/* Pop the enum scope */
				currentEnum = (yyvsp[(3) - (5)].structInfo).parent;

				/* Return the completed type to the next higher level */
				(yyval.type) = CTypeResolveAnonEnum((yyvsp[(3) - (5)].structInfo).type);
	  		}
    break;

  case 193:
#line 2305 "c_grammar.y"
    {
				/* Look for a definition in the local scope */
				if(!CScopeHasEnum((yyvsp[(2) - (3)].name)))
				{
					/* Define the enum type */
					(yyval.structInfo).type = CTypeDefineEnum
							(&CCCodeGen, (yyvsp[(2) - (3)].name), functionName);
				}
				else
				{
					/* We've already seen a definition for this type before */
					CCError(_("redefinition of `enum %s'"), (yyvsp[(2) - (3)].name));

					/* Create an anonymous type as a place-holder */
					(yyval.structInfo).type = CTypeDefineAnonEnum
							(&CCCodeGen, functionName);
				}

				/* Push in a scope level for the enum */
				(yyval.structInfo).parent = currentEnum;
				currentEnum = (yyval.structInfo).type;
				currentEnumValue = 0;

				/* Add the type to the current scope */
				CScopeAddEnum((yyvsp[(2) - (3)].name), (yyval.structInfo).type);
			}
    break;

  case 194:
#line 2331 "c_grammar.y"
    {
	  			/* Pop the enum scope */
				currentEnum = (yyvsp[(4) - (6)].structInfo).parent;

				/* Return the completed type to the next higher level */
				(yyval.type) = (yyvsp[(4) - (6)].structInfo).type;
			}
    break;

  case 195:
#line 2338 "c_grammar.y"
    {
				/* Look for an existing definition for this type */
				void *data = CScopeLookupEnum((yyvsp[(2) - (2)].name));
				if(!data)
				{
					/* Create a reference to the named enum type
					   assuming that it is at the global level */
					(yyval.type) = CTypeCreateEnum(&CCCodeGen, (yyvsp[(2) - (2)].name), 0);
				}
				else
				{
					/* Use the type that was registered in the scope */
					(yyval.type) = CScopeGetType(data);
				}
			}
    break;

  case 201:
#line 2367 "c_grammar.y"
    {
				/* See if we already have a definition with this name */
				void *data = CScopeLookupCurrent((yyvsp[(1) - (1)].name));
				ILNode *node;
				if(data)
				{
					CCError(_("redeclaration of `%s'"), (yyvsp[(1) - (1)].name));
					node = CScopeGetNode(data);
					if(node)
					{
						CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  				  _("`%s' previously declared here"), (yyvsp[(1) - (1)].name));
					}
				}
				else
				{
					CTypeDefineEnumConst(&CCCodeGen, currentEnum,
										 (yyvsp[(1) - (1)].name), currentEnumValue);
					CScopeAddEnumConst((yyvsp[(1) - (1)].name), ILQualIdentSimple((yyvsp[(1) - (1)].name)),
									   currentEnumValue,
									   CTypeResolveAnonEnum(currentEnum));
				}
				++currentEnumValue;
			}
    break;

  case 202:
#line 2391 "c_grammar.y"
    {
				void *data;
				ILNode *node;

				/* Update the current enumeration value */
				currentEnumValue = EvaluateIntConstant((yyvsp[(3) - (3)].node));

				/* See if we already have a definition with this name */
				data = CScopeLookupCurrent((yyvsp[(1) - (3)].name));
				if(data)
				{
					CCError(_("redeclaration of `%s'"), (yyvsp[(1) - (3)].name));
					node = CScopeGetNode(data);
					if(node)
					{
						CCErrorOnLine(yygetfilename(node), yygetlinenum(node),
					  				  _("`%s' previously declared here"), (yyvsp[(1) - (3)].name));
					}
				}
				else
				{
					CTypeDefineEnumConst(&CCCodeGen, currentEnum,
										 (yyvsp[(1) - (3)].name), currentEnumValue);
					CScopeAddEnumConst((yyvsp[(1) - (3)].name), ILQualIdentSimple((yyvsp[(1) - (3)].name)),
									   currentEnumValue,
									   CTypeResolveAnonEnum(currentEnum));
				}
				++currentEnumValue;
			}
    break;

  case 203:
#line 2423 "c_grammar.y"
    { (yyval.node) = ILQualIdentSimple((yyvsp[(1) - (1)].name)); }
    break;

  case 204:
#line 2424 "c_grammar.y"
    {
				(yyval.node) = ILNode_QualIdent_create((yyvsp[(1) - (3)].node), ILQualIdentSimple((yyvsp[(3) - (3)].name)));
			}
    break;

  case 206:
#line 2431 "c_grammar.y"
    { (yyval.decl) = CDeclCombine((yyvsp[(1) - (2)].decl), (yyvsp[(2) - (2)].decl)); }
    break;

  case 207:
#line 2435 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), (yyvsp[(1) - (1)].name), ILQualIdentSimple((yyvsp[(1) - (1)].name)));
			}
    break;

  case 208:
#line 2438 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), (yyvsp[(1) - (2)].name), ILQualIdentSimple((yyvsp[(1) - (2)].name)));
				(yyval.decl).attrs = (yyvsp[(2) - (2)].node);
			}
    break;

  case 209:
#line 2442 "c_grammar.y"
    { (yyval.decl) = (yyvsp[(2) - (3)].decl); }
    break;

  case 210:
#line 2443 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateOpenArray(&CCCodeGen, (yyvsp[(1) - (4)].decl), (yyvsp[(2) - (4)].gcSpecifier));
			}
    break;

  case 211:
#line 2446 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateOpenArray(&CCCodeGen, (yyvsp[(1) - (5)].decl), (yyvsp[(2) - (5)].gcSpecifier));
				(yyval.decl).attrs = (yyvsp[(5) - (5)].node);
			}
    break;

  case 212:
#line 2450 "c_grammar.y"
    {
				/* Evaluate the constant value */
				ILNode *size = EvaluateSize((yyvsp[(4) - (5)].node));

				/* Create the array */
				(yyval.decl) = CDeclCreateArray(&CCCodeGen, (yyvsp[(1) - (5)].decl), size, (yyvsp[(2) - (5)].gcSpecifier));
			}
    break;

  case 213:
#line 2457 "c_grammar.y"
    {
				/* Evaluate the constant value */
				ILNode *size = EvaluateSize((yyvsp[(4) - (6)].node));

				/* Create the array */
				(yyval.decl) = CDeclCreateArray(&CCCodeGen, (yyvsp[(1) - (6)].decl), size, (yyvsp[(2) - (6)].gcSpecifier));
				(yyval.decl).attrs = (yyvsp[(6) - (6)].node);
			}
    break;

  case 214:
#line 2465 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (3)].decl), 0, 0);
			}
    break;

  case 215:
#line 2468 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (4)].decl), 0, (yyvsp[(4) - (4)].node));
			}
    break;

  case 216:
#line 2471 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (4)].decl), (yyvsp[(3) - (4)].node), 0);
			}
    break;

  case 217:
#line 2474 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (5)].decl), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 218:
#line 2477 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (4)].decl), (yyvsp[(3) - (4)].node), 0);
			}
    break;

  case 219:
#line 2480 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (5)].decl), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 220:
#line 2486 "c_grammar.y"
    { (yyval.gcSpecifier) = ILGC_Unknown; }
    break;

  case 221:
#line 2487 "c_grammar.y"
    { (yyval.gcSpecifier) = ILGC_Managed; }
    break;

  case 222:
#line 2488 "c_grammar.y"
    { (yyval.gcSpecifier) = ILGC_Unmanaged; }
    break;

  case 223:
#line 2492 "c_grammar.y"
    { (yyval.node) = (yyvsp[(4) - (6)].node); }
    break;

  case 224:
#line 2496 "c_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 225:
#line 2500 "c_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 226:
#line 2507 "c_grammar.y"
    {
				(yyval.node) = ILNode_CAttribute_create((yyvsp[(1) - (1)].name), 0);
			}
    break;

  case 227:
#line 2510 "c_grammar.y"
    {
				(yyval.node) = ILNode_CAttribute_create((yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].node));
			}
    break;

  case 228:
#line 2513 "c_grammar.y"
    {
				(yyval.node) = ILNode_CAttribute_create
						(ILInternString("__const__", -1).string, 0);
			}
    break;

  case 229:
#line 2520 "c_grammar.y"
    {
				ILNode *node = ILNode_ToConst_create((yyvsp[(1) - (1)].node));
				CSemValue value;
				ILEvalValue evalValue;
				value = CSemInlineAnalysis
					(&CCCodeGen, node, &node, CCurrentScope);
				if(CSemIsRValue(value))
				{
					if(yyisa((yyvsp[(1) - (1)].node), ILNode_CString))
					{
						evalValue.valueType = ILMachineType_String;
						evalValue.un.strValue.str =
								((ILNode_CString *)((yyvsp[(1) - (1)].node)))->str;
						evalValue.un.strValue.len =
								((ILNode_CString *)((yyvsp[(1) - (1)].node)))->len;
					}
					else if(!ILNode_EvalConst(node, &CCCodeGen, &evalValue))
					{
						CCError(_("compile-time constant value required"));
						evalValue.valueType = ILMachineType_Void;
					}
				}
				else
				{
					evalValue.valueType = ILMachineType_Void;
				}
				(yyval.node) = ILNode_CAttributeValue_create(evalValue);
			}
    break;

  case 231:
#line 2552 "c_grammar.y"
    {
				(yyval.node) = ILNode_ArgList_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 232:
#line 2558 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePointer(&CCCodeGen, 0, 0);
			}
    break;

  case 233:
#line 2561 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePointer(&CCCodeGen, (yyvsp[(2) - (2)].kind), 0);
			}
    break;

  case 234:
#line 2564 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePointer(&CCCodeGen, 0, &((yyvsp[(2) - (2)].decl)));
			}
    break;

  case 235:
#line 2567 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePointer(&CCCodeGen, (yyvsp[(2) - (3)].kind), &((yyvsp[(3) - (3)].decl)));
			}
    break;

  case 236:
#line 2570 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateByRef(&CCCodeGen, 0, 0);
			}
    break;

  case 237:
#line 2573 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateByRef(&CCCodeGen, (yyvsp[(2) - (2)].kind), 0);
			}
    break;

  case 238:
#line 2576 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateByRef(&CCCodeGen, 0, &((yyvsp[(2) - (2)].decl)));
			}
    break;

  case 239:
#line 2579 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateByRef(&CCCodeGen, (yyvsp[(2) - (3)].kind), &((yyvsp[(3) - (3)].decl)));
			}
    break;

  case 240:
#line 2585 "c_grammar.y"
    { (yyval.kind) = C_SPEC_CONST; }
    break;

  case 241:
#line 2586 "c_grammar.y"
    { (yyval.kind) = C_SPEC_VOLATILE; }
    break;

  case 243:
#line 2591 "c_grammar.y"
    {
				if(((yyvsp[(1) - (2)].kind) & (yyvsp[(2) - (2)].kind) & C_SPEC_CONST) != 0)
				{
					CCWarning(_("duplicate `const'"));
				}
				if(((yyvsp[(1) - (2)].kind) & (yyvsp[(2) - (2)].kind) & C_SPEC_VOLATILE) != 0)
				{
					CCWarning(_("duplicate `volatile'"));
				}
				(yyval.kind) = ((yyvsp[(1) - (2)].kind) | (yyvsp[(2) - (2)].kind));
			}
    break;

  case 245:
#line 2606 "c_grammar.y"
    { (yyval.declSpec) = CDeclSpecCombine((yyvsp[(1) - (2)].declSpec), (yyvsp[(2) - (2)].declSpec)); }
    break;

  case 246:
#line 2610 "c_grammar.y"
    {
				CDeclarator decl;
				CDeclSpec spec;
				CDeclSetName(decl, 0, 0);
				spec = CDeclSpecFinalize((yyvsp[(1) - (1)].declSpec), 0, 0, 0);
				(yyval.type) = CDeclFinalize(&CCCodeGen, spec, decl, 0, 0);
			}
    break;

  case 248:
#line 2621 "c_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), ILNode_FormalParameter_create
					(0, ILParamMod_arglist, 0, 0));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 249:
#line 2629 "c_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), ILNode_FormalParameter_create
					(0, ILParamMod_empty, 0, ILQualIdentSimple((yyvsp[(1) - (1)].name))));
			}
    break;

  case 250:
#line 2634 "c_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), ILNode_FormalParameter_create
					(0, ILParamMod_empty, 0, ILQualIdentSimple((yyvsp[(3) - (3)].name))));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 252:
#line 2643 "c_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), ILNode_FormalParameter_create
					(0, ILParamMod_arglist, 0, 0));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 253:
#line 2651 "c_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 254:
#line 2655 "c_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 255:
#line 2662 "c_grammar.y"
    {
				ILType *type;
				ILNode *nameNode;
				CDeclSpec spec;
				spec = CDeclSpecFinalize
					((yyvsp[(1) - (2)].declSpec), (yyvsp[(2) - (2)].decl).node, (yyvsp[(2) - (2)].decl).name, C_KIND_PARAMETER_NAME);
				type = CDeclFinalize(&CCCodeGen, spec, (yyvsp[(2) - (2)].decl), 0, 0);
				nameNode = (yyvsp[(2) - (2)].decl).node;
				if(!nameNode && (yyvsp[(2) - (2)].decl).name != 0)
				{
					nameNode = ILQualIdentSimple((yyvsp[(2) - (2)].decl).name);
				}
				(yyval.node) = ILNode_FormalParameter_create
					(0, ILParamMod_empty,
					 ILNode_MarkType_create(0, type), nameNode);
			}
    break;

  case 256:
#line 2678 "c_grammar.y"
    {
				ILType *type;
				ILNode *nameNode;
				CDeclSpec spec;
				spec = CDeclSpecFinalize
					((yyvsp[(2) - (3)].declSpec), (yyvsp[(3) - (3)].decl).node, (yyvsp[(3) - (3)].decl).name, C_KIND_PARAMETER_NAME);
				type = CDeclFinalize(&CCCodeGen, spec, (yyvsp[(3) - (3)].decl), 0, 0);
				nameNode = (yyvsp[(3) - (3)].decl).node;
				if(!nameNode && (yyvsp[(3) - (3)].decl).name != 0)
				{
					nameNode = ILQualIdentSimple((yyvsp[(3) - (3)].decl).name);
				}
				(yyval.node) = ILNode_FormalParameter_create
					(0, ILParamMod_empty,
					 ILNode_MarkType_create(0, type), nameNode);
			}
    break;

  case 257:
#line 2694 "c_grammar.y"
    {
				(yyval.node) = ILNode_FormalParameter_create
					(0, ILParamMod_empty, ILNode_MarkType_create(0, (yyvsp[(1) - (1)].type)), 0);
			}
    break;

  case 258:
#line 2698 "c_grammar.y"
    {
				(yyval.node) = ILNode_FormalParameter_create
					(0, ILParamMod_empty, ILNode_MarkType_create(0, (yyvsp[(2) - (2)].type)), 0);
			}
    break;

  case 259:
#line 2705 "c_grammar.y"
    {
				CDeclarator decl;
				CDeclSpec spec;
				CDeclSetName(decl, 0, 0);
				spec = CDeclSpecFinalize((yyvsp[(1) - (1)].declSpec), 0, 0, 0);
				(yyval.type) = CDeclFinalize(&CCCodeGen, spec, decl, 0, 0);
			}
    break;

  case 260:
#line 2712 "c_grammar.y"
    {
				CDeclSpec spec;
				spec = CDeclSpecFinalize((yyvsp[(1) - (2)].declSpec), 0, 0, 0);
				(yyval.type) = CDeclFinalize(&CCCodeGen, spec, (yyvsp[(2) - (2)].decl), 0, 0);
			}
    break;

  case 263:
#line 2722 "c_grammar.y"
    { (yyval.decl) = CDeclCombine((yyvsp[(1) - (2)].decl), (yyvsp[(2) - (2)].decl)); }
    break;

  case 264:
#line 2726 "c_grammar.y"
    { (yyval.decl) = (yyvsp[(2) - (3)].decl); }
    break;

  case 265:
#line 2727 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreateOpenArray(&CCCodeGen, (yyval.decl), (yyvsp[(1) - (3)].gcSpecifier));
			}
    break;

  case 266:
#line 2731 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreateOpenArray(&CCCodeGen, (yyval.decl), (yyvsp[(1) - (4)].gcSpecifier));
				(yyval.decl).attrs = (yyvsp[(4) - (4)].node);
			}
    break;

  case 267:
#line 2736 "c_grammar.y"
    {
				/* Evaluate the constant value */
				ILNode *size = EvaluateSize((yyvsp[(3) - (4)].node));

				/* Create the array */
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreateArray(&CCCodeGen, (yyval.decl), size, (yyvsp[(1) - (4)].gcSpecifier));
			}
    break;

  case 268:
#line 2744 "c_grammar.y"
    {
				/* Evaluate the constant value */
				ILNode *size = EvaluateSize((yyvsp[(3) - (5)].node));

				/* Create the array */
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreateArray(&CCCodeGen, (yyval.decl), size, (yyvsp[(1) - (5)].gcSpecifier));
				(yyval.decl).attrs = (yyvsp[(5) - (5)].node);
			}
    break;

  case 269:
#line 2753 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateOpenArray(&CCCodeGen, (yyvsp[(1) - (4)].decl), (yyvsp[(2) - (4)].gcSpecifier));
			}
    break;

  case 270:
#line 2756 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreateOpenArray(&CCCodeGen, (yyvsp[(1) - (5)].decl), (yyvsp[(2) - (5)].gcSpecifier));
				(yyval.decl).attrs = (yyvsp[(5) - (5)].node);
			}
    break;

  case 271:
#line 2760 "c_grammar.y"
    {
				/* Evaluate the constant value */
				ILNode *size = EvaluateSize((yyvsp[(4) - (5)].node));

				/* Create the array */
				(yyval.decl) = CDeclCreateArray(&CCCodeGen, (yyvsp[(1) - (5)].decl), size, (yyvsp[(2) - (5)].gcSpecifier));
			}
    break;

  case 272:
#line 2768 "c_grammar.y"
    {
				/* Evaluate the constant value */
				ILNode *size = EvaluateSize((yyvsp[(4) - (6)].node));

				/* Create the array */
				(yyval.decl) = CDeclCreateArray(&CCCodeGen, (yyvsp[(1) - (6)].decl), size, (yyvsp[(2) - (6)].gcSpecifier));
				(yyval.decl).attrs = (yyvsp[(6) - (6)].node);
			}
    break;

  case 273:
#line 2776 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyval.decl), 0, 0);
			}
    break;

  case 274:
#line 2780 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyval.decl), 0, (yyvsp[(3) - (3)].node));
			}
    break;

  case 275:
#line 2784 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyval.decl), (yyvsp[(2) - (3)].node), 0);
			}
    break;

  case 276:
#line 2788 "c_grammar.y"
    {
				CDeclSetName((yyval.decl), 0, 0);
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyval.decl), (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 277:
#line 2792 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (3)].decl), 0, 0);
			}
    break;

  case 278:
#line 2795 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (4)].decl), 0, (yyvsp[(4) - (4)].node));
			}
    break;

  case 279:
#line 2798 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (4)].decl), (yyvsp[(3) - (4)].node), 0);
			}
    break;

  case 280:
#line 2801 "c_grammar.y"
    {
				(yyval.decl) = CDeclCreatePrototype(&CCCodeGen, (yyvsp[(1) - (5)].decl), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 281:
#line 2807 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 282:
#line 2808 "c_grammar.y"
    { (yyval.node) = ILNode_CArrayInit_create((yyvsp[(2) - (3)].node)); }
    break;

  case 283:
#line 2809 "c_grammar.y"
    { (yyval.node) = ILNode_CArrayInit_create((yyvsp[(2) - (4)].node)); }
    break;

  case 284:
#line 2813 "c_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 285:
#line 2817 "c_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (3)].node);
				ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 286:
#line 2824 "c_grammar.y"
    {
			#ifdef YYBISON
				if(debug_flag)
				{
					(yyval.node) = ILNode_LineInfo_create((yyvsp[(1) - (1)].node));
					yysetlinenum((yyval.node), (yylsp[(1) - (1)]).first_line);
				}
				else
			#endif
				{
					(yyval.node) = (yyvsp[(1) - (1)].node);
				}
			}
    break;

  case 295:
#line 2848 "c_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 296:
#line 2852 "c_grammar.y"
    {
				(yyval.node) = ILNode_GotoLabel_create((yyvsp[(1) - (2)].name));
			}
    break;

  case 297:
#line 2855 "c_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 298:
#line 2858 "c_grammar.y"
    {
				(yyval.node) = ILNode_CaseLabel_create((yyvsp[(2) - (3)].node));
			}
    break;

  case 299:
#line 2861 "c_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 300:
#line 2864 "c_grammar.y"
    {
				(yyval.node) = ILNode_DefaultLabel_create();
			}
    break;

  case 301:
#line 2867 "c_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 302:
#line 2873 "c_grammar.y"
    {
				/* Create a new scope */
				CCurrentScope = ILScopeCreate(&CCCodeGen, CCurrentScope);
			}
    break;

  case 303:
#line 2877 "c_grammar.y"
    {
	  			/* Build the compound statement block if it isn't empty */
				if((yyvsp[(3) - (5)].node) != 0 || (yyvsp[(4) - (5)].node) != 0)
				{
					(yyval.node) = ILNode_NewScope_create
						(ILNode_Compound_CreateFrom((yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node)));
					((ILNode_NewScope *)((yyval.node)))->scope = CCurrentScope;
				}
				else
				{
					(yyval.node) = ILNode_Empty_create();
				}

				/* Fix up the line number on the compound statement node */
			#ifdef YYBISON
				yysetlinenum((yyval.node), (yylsp[(1) - (5)]).first_line);
			#endif

	  			/* Pop the scope */
				CCurrentScope = ILScopeGetParent(CCurrentScope);
			}
    break;

  case 304:
#line 2901 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 305:
#line 2902 "c_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 307:
#line 2907 "c_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
			}
    break;

  case 308:
#line 2913 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 309:
#line 2914 "c_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 311:
#line 2919 "c_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
			}
    break;

  case 312:
#line 2925 "c_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 313:
#line 2926 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 314:
#line 2930 "c_grammar.y"
    { (yyval.node) = ILNode_ToBool_create((yyvsp[(1) - (1)].node)); }
    break;

  case 315:
#line 2934 "c_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), ILNode_Empty_create());
			}
    break;

  case 316:
#line 2937 "c_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
			}
    break;

  case 317:
#line 2940 "c_grammar.y"
    {
				(yyval.node) = ILNode_Switch_create((yyvsp[(3) - (5)].node), 0, (yyvsp[(5) - (5)].node));
				CGenCloneLine((yyval.node), (yyvsp[(3) - (5)].node));
			}
    break;

  case 318:
#line 2947 "c_grammar.y"
    {
				(yyval.node) = ILNode_While_create((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 319:
#line 2950 "c_grammar.y"
    {
				(yyval.node) = ILNode_Do_create((yyvsp[(2) - (7)].node), (yyvsp[(5) - (7)].node));
			}
    break;

  case 320:
#line 2953 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create(ILNode_Empty_create(),
									   ILNode_True_create(),
									   ILNode_Empty_create(), (yyvsp[(6) - (6)].node));
			}
    break;

  case 321:
#line 2958 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create(ILNode_Empty_create(),
									   ILNode_True_create(),
									   (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
			}
    break;

  case 322:
#line 2963 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create(ILNode_Empty_create(), (yyvsp[(4) - (7)].node),
									   ILNode_Empty_create(), (yyvsp[(7) - (7)].node));
			}
    break;

  case 323:
#line 2967 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create(ILNode_Empty_create(), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
			}
    break;

  case 324:
#line 2970 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create((yyvsp[(3) - (7)].node),
									   ILNode_True_create(),
									   ILNode_Empty_create(), (yyvsp[(7) - (7)].node));
			}
    break;

  case 325:
#line 2975 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create((yyvsp[(3) - (8)].node), ILNode_True_create(), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
			}
    break;

  case 326:
#line 2978 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create((yyvsp[(3) - (8)].node), (yyvsp[(5) - (8)].node), ILNode_Empty_create(), (yyvsp[(8) - (8)].node));
			}
    break;

  case 327:
#line 2981 "c_grammar.y"
    {
				(yyval.node) = ILNode_For_create((yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node));
			}
    break;

  case 328:
#line 2987 "c_grammar.y"
    { (yyval.node) = ILNode_Goto_create((yyvsp[(2) - (3)].name)); }
    break;

  case 329:
#line 2988 "c_grammar.y"
    { (yyval.node) = ILNode_CGotoPtr_create((yyvsp[(3) - (4)].node)); }
    break;

  case 330:
#line 2989 "c_grammar.y"
    { (yyval.node) = ILNode_Continue_create(); }
    break;

  case 331:
#line 2990 "c_grammar.y"
    { (yyval.node) = ILNode_Break_create(); }
    break;

  case 332:
#line 2991 "c_grammar.y"
    { (yyval.node) = ILNode_Return_create(); }
    break;

  case 333:
#line 2992 "c_grammar.y"
    { (yyval.node) = ILNode_ReturnExpr_create((yyvsp[(2) - (3)].node)); }
    break;

  case 334:
#line 2997 "c_grammar.y"
    {
				(yyval.node) = ILNode_AsmStmt_create((yyvsp[(3) - (6)].string).string);
			}
    break;

  case 335:
#line 3000 "c_grammar.y"
    {
				(yyval.node) = ILNode_AsmStmt_create((yyvsp[(3) - (5)].string).string);
			}
    break;

  case 336:
#line 3003 "c_grammar.y"
    {
				(yyval.node) = ILNode_AsmStmt_create((yyvsp[(4) - (7)].string).string);
			}
    break;

  case 337:
#line 3006 "c_grammar.y"
    {
				(yyval.node) = ILNode_AsmStmt_create((yyvsp[(4) - (6)].string).string);
			}
    break;

  case 342:
#line 3019 "c_grammar.y"
    {
				(yyval.node) = ILNode_Try_create((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), 0);
			}
    break;

  case 343:
#line 3022 "c_grammar.y"
    {
				(yyval.node) = ILNode_Try_create((yyvsp[(2) - (3)].node), 0, (yyvsp[(3) - (3)].node));
			}
    break;

  case 344:
#line 3025 "c_grammar.y"
    {
				(yyval.node) = ILNode_Try_create((yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 345:
#line 3031 "c_grammar.y"
    {
				if((yyvsp[(2) - (2)].node))
				{
					ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				}
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 346:
#line 3038 "c_grammar.y"
    {
				if((yyvsp[(1) - (2)].node))
				{
					ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
					(yyval.node) = (yyvsp[(1) - (2)].node);
				}
				else
				{
					(yyval.node) = ILNode_CatchClauses_create();
					ILNode_List_Add((yyval.node), (yyvsp[(2) - (2)].node));
				}
			}
    break;

  case 347:
#line 3053 "c_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 348:
#line 3054 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 349:
#line 3058 "c_grammar.y"
    {
				(yyval.node) = ILNode_CatchClauses_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 350:
#line 3062 "c_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 351:
#line 3069 "c_grammar.y"
    {
				(yyval.node) = ILNode_CatchClause_create(0, (yyvsp[(2) - (3)].catchInfo).id, (yyvsp[(2) - (3)].catchInfo).idNode, (yyvsp[(3) - (3)].node));
				((ILNode_CatchClause *)(yyval.node))->classInfo =
					ILTypeToClass(&CCCodeGen, (yyvsp[(2) - (3)].catchInfo).type);
			}
    break;

  case 352:
#line 3077 "c_grammar.y"
    {
				(yyval.catchInfo).type = ILFindSystemType(&CCCodeGen, "Exception");
				(yyval.catchInfo).id = 0;
				(yyval.catchInfo).idNode = 0;
			}
    break;

  case 353:
#line 3082 "c_grammar.y"
    {
				(yyval.catchInfo).type = (yyvsp[(2) - (4)].type);
				(yyval.catchInfo).id = (yyvsp[(3) - (4)].name);
				(yyval.catchInfo).idNode = ILQualIdentSimple((yyvsp[(3) - (4)].name));
			}
    break;

  case 354:
#line 3087 "c_grammar.y"
    {
				(yyval.catchInfo).type = (yyvsp[(2) - (3)].type);
				(yyval.catchInfo).id = 0;
				(yyval.catchInfo).idNode = 0;
			}
    break;

  case 355:
#line 3092 "c_grammar.y"
    {
				/*
				 * This production recovers from errors in catch
				 * variable name declarations.
				 */
				(yyval.catchInfo).type = ILFindSystemType(&CCCodeGen, "Exception");
				(yyval.catchInfo).id = 0;
				(yyval.catchInfo).idNode = 0;
				yyerrok;
			}
    break;

  case 356:
#line 3105 "c_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 357:
#line 3106 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 358:
#line 3110 "c_grammar.y"
    {
				(yyval.node) = ILNode_CatchClause_create(0, 0, 0, (yyvsp[(2) - (2)].node));
				((ILNode_CatchClause *)(yyval.node))->classInfo = ILTypeToClass
						(&CCCodeGen, ILFindSystemType
							(&CCCodeGen, "Exception"));
			}
    break;

  case 359:
#line 3119 "c_grammar.y"
    {
				(yyval.node) = ILNode_FinallyClause_create((yyvsp[(2) - (2)].node));
			}
    break;

  case 360:
#line 3125 "c_grammar.y"
    { (yyval.node) = ILNode_Throw_create(); }
    break;

  case 361:
#line 3126 "c_grammar.y"
    { (yyval.node) = ILNode_ThrowExpr_create((yyvsp[(2) - (3)].node)); }
    break;

  case 362:
#line 3130 "c_grammar.y"
    { (yyval.node) = ILNode_Overflow_create((yyvsp[(2) - (2)].node)); }
    break;

  case 363:
#line 3131 "c_grammar.y"
    { (yyval.node) = ILNode_NoOverflow_create((yyvsp[(2) - (2)].node)); }
    break;

  case 364:
#line 3135 "c_grammar.y"
    {
				(yyval.node) = ILNode_Lock_create((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 365:
#line 3141 "c_grammar.y"
    {
				/* Flush the code for any remaining initializers */
				if(initializers != 0)
				{
					CFunctionFlushInits(&CCCodeGen, initializers);
					initializers = 0;
				}
				CGenGotoDestroy();

				/* Roll the treecc node heap back to the last check point */
				if(!inhibitRollBack)
				{
					yynodepop();
					yynodepush();
				}
			}
    break;

  case 369:
#line 3166 "c_grammar.y"
    {
				/* Roll the treecc node heap back to the last check point */
				if(inhibitRollBack)
				{
					yynodepush();
					inhibitRollBack = 0;
				}
				else
				{
					yynodepop();
					yynodepush();
				}
			}
    break;

  case 370:
#line 3179 "c_grammar.y"
    { /* Nothing to do here */ }
    break;

  case 375:
#line 3187 "c_grammar.y"
    {
				CDeclSpec spec;
				ILMethod *method;

				/* Flush the code for any pending initializers */
				if(initializers != 0)
				{
					CFunctionFlushInits(&CCCodeGen, initializers);
					initializers = 0;
				}

				/* The default return type in this case is "int" */
				CDeclSpecSetType(spec, ILType_Int32);

				/* Create the method block from the function header */
				method = CFunctionCreate
					(&CCCodeGen, (yyvsp[(1) - (3)].decl).name, (yyvsp[(1) - (3)].decl).node, spec, (yyvsp[(1) - (3)].decl), (yyvsp[(2) - (3)].node));

				/* Create a new scope to hold the function body */
				CCurrentScope = ILScopeCreate(&CCCodeGen, CCurrentScope);

				/* Declare the parameters into the new scope */
				CFunctionDeclareParams(&CCCodeGen, method);
				(yyval.methodInfo) = method;

				/* Set the new function name */
				functionName = (yyvsp[(1) - (3)].decl).name;

				/* No global variables in use yet */
				usedGlobalVar = 0;
			}
    break;

  case 376:
#line 3218 "c_grammar.y"
    {
	  			/* Wrap the function body in a new scope record */
				ILNode *body = ILNode_NewScope_create((yyvsp[(5) - (6)].node));
				((ILNode_NewScope *)body)->scope = CCurrentScope;

				/* Fix up the line number on the function body */
			#ifdef YYBISON
				yysetlinenum(body, (yylsp[(3) - (6)]).first_line);
			#endif

				/* Pop the scope */
				CCurrentScope = ILScopeGetParent(CCurrentScope);

				/* Clear the goto label information */
				CGenGotoDestroy();

				/* Output the finished function */
				CFunctionOutput(&CCCodeGen, (yyvsp[(4) - (6)].methodInfo), body,
								usedGlobalVar);

				/* Reset the function name */
				functionName = "";

				/* Flush the code for any pending initializers */
				if(initializers != 0)
				{
					CFunctionFlushInits(&CCCodeGen, initializers);
					initializers = 0;
				}
	  		}
    break;

  case 377:
#line 3248 "c_grammar.y"
    {
				ILMethod *method;
				CDeclSpec spec;

				/* Flush the code for any pending initializers */
				if(initializers != 0)
				{
					CFunctionFlushInits(&CCCodeGen, initializers);
					initializers = 0;
				}

				/* Finalize the declaration specifier */
				spec = CDeclSpecFinalize
						((yyvsp[(1) - (4)].declSpec), (yyvsp[(2) - (4)].decl).node, (yyvsp[(2) - (4)].decl).name, C_KIND_GLOBAL_NAME);

				/* Create the method block from the function header */
				method = CFunctionCreate
					(&CCCodeGen, (yyvsp[(2) - (4)].decl).name, (yyvsp[(2) - (4)].decl).node, spec, (yyvsp[(2) - (4)].decl), (yyvsp[(3) - (4)].node));

				/* Create a new scope to hold the function body */
				CCurrentScope = ILScopeCreate(&CCCodeGen, CCurrentScope);

				/* Declare the parameters into the new scope */
				CFunctionDeclareParams(&CCCodeGen, method);
				(yyval.methodInfo) = method;

				/* Set the new function name */
				functionName = (yyvsp[(2) - (4)].decl).name;

				/* No global variables in use yet */
				usedGlobalVar = 0;
			}
    break;

  case 378:
#line 3280 "c_grammar.y"
    {
	  			/* Wrap the function body in a new scope record */
				ILNode *body = ILNode_NewScope_create((yyvsp[(6) - (7)].node));
				((ILNode_NewScope *)body)->scope = CCurrentScope;

				/* Fix up the line number on the function body */
			#ifdef YYBISON
				yysetlinenum(body, (yylsp[(4) - (7)]).first_line);
			#endif

				/* Pop the scope */
				CCurrentScope = ILScopeGetParent(CCurrentScope);

				/* Clear the goto label information */
				CGenGotoDestroy();

				/* Output the finished function */
				CFunctionOutput(&CCCodeGen, (yyvsp[(5) - (7)].methodInfo), body,
								usedGlobalVar);

				/* Reset the function name */
				functionName = "";

				/* Flush the code for any pending initializers */
				if(initializers != 0)
				{
					CFunctionFlushInits(&CCCodeGen, initializers);
					initializers = 0;
				}
	  		}
    break;

  case 379:
#line 3313 "c_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 380:
#line 3314 "c_grammar.y"
    { (yyval.node) = ILNode_List_create(); }
    break;

  case 381:
#line 3318 "c_grammar.y"
    {
				if(yyisa((yyvsp[(1) - (1)].node), ILNode_List))
				{
					(yyval.node) = (yyvsp[(1) - (1)].node);
				}
				else
				{
					(yyval.node) = ILNode_List_create();
					ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
				}
			}
    break;

  case 382:
#line 3329 "c_grammar.y"
    {
				CopyParamDecls((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 383:
#line 3336 "c_grammar.y"
    {
				CDeclSpec spec;
				char *name;
				ILNode *nameNode;
				ILType *type;
				ILNode_CDeclarator *decl;
				ILNode_ListIter iter;

				/* Get the first name and its node for error reporting */
				if(yyisa((yyvsp[(2) - (3)].node), ILNode_CDeclarator))
				{
					name = ((ILNode_CDeclarator *)((yyvsp[(2) - (3)].node)))->decl.name;
					nameNode = ((ILNode_CDeclarator *)((yyvsp[(2) - (3)].node)))->decl.node;
				}
				else
				{
					nameNode = ((ILNode_List *)((yyvsp[(2) - (3)].node)))->item1;
					name = ((ILNode_CDeclarator *)nameNode)->decl.name;
					nameNode = ((ILNode_CDeclarator *)nameNode)->decl.node;
				}

				/* Finalize the declaration specifiers */
				spec = CDeclSpecFinalize((yyvsp[(1) - (3)].declSpec), nameNode, name,
										 C_KIND_PARAMETER_NAME);

				/* Build the formal parameters from the declarators */
				if(yyisa((yyvsp[(2) - (3)].node), ILNode_CDeclarator))
				{
					decl = (ILNode_CDeclarator *)((yyvsp[(2) - (3)].node));
					type = CDeclFinalize(&CCCodeGen, spec, decl->decl, 0, 0);
					(yyval.node) = ILNode_FormalParameter_create
						(0, ILParamMod_empty, ILNode_MarkType_create(0, type),
						 decl->decl.node);
				}
				else
				{
					(yyval.node) = ILNode_List_create();
					ILNode_ListIter_Init(&iter, (yyvsp[(2) - (3)].node));
					while((decl = (ILNode_CDeclarator *)
							ILNode_ListIter_Next(&iter)) != 0)
					{
						type = CDeclFinalize(&CCCodeGen, spec,
											 decl->decl, 0, 0);
						ILNode_List_Add((yyval.node), ILNode_FormalParameter_create
							(0, ILParamMod_empty,
							 ILNode_MarkType_create(0, type),
							 decl->decl.node));
					}
				}
			}
    break;

  case 384:
#line 3389 "c_grammar.y"
    {
				/* Don't bother creating a list for the common case
				   of there being only one declarator */
				(yyval.node) = ILNode_CDeclarator_create((yyvsp[(1) - (1)].decl));
			}
    break;

  case 385:
#line 3394 "c_grammar.y"
    {
				if(yyisa((yyvsp[(1) - (3)].node), ILNode_List))
				{
					/* Add the declarator to the existing list */
					ILNode_List_Add((yyvsp[(1) - (3)].node), ILNode_CDeclarator_create((yyvsp[(3) - (3)].decl)));
					(yyval.node) = (yyvsp[(1) - (3)].node);
				}
				else
				{
					/* At least two declarators: create a new list */
					(yyval.node) = ILNode_List_create();
					ILNode_List_Add((yyval.node), (yyvsp[(1) - (3)].node));
					ILNode_List_Add((yyval.node), ILNode_CDeclarator_create((yyvsp[(3) - (3)].decl)));
				}
			}
    break;

  case 387:
#line 3416 "c_grammar.y"
    {
				if((yyvsp[(1) - (2)].node) != 0 || (yyvsp[(2) - (2)].node) != 0)
				{
					(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				}
				else
				{
					(yyval.node) = ILNode_Empty_create();
				}
			}
    break;

  case 388:
#line 3429 "c_grammar.y"
    {
				CScopeUsingNamespace(ILQualIdentName((yyvsp[(3) - (4)].node), 0));
			}
    break;

  case 389:
#line 3432 "c_grammar.y"
    {
				ILType *type = CTypeFromCSharp(&CCCodeGen, 0, (yyvsp[(2) - (3)].node));
				if(type)
				{
					ProcessUsingTypeDeclaration(type, (yyvsp[(2) - (3)].node));
				}
				else
				{
					CCError(_("could not resolve `%s' as a C# type"),
							ILQualIdentName((yyvsp[(2) - (3)].node), 0));
				}
			}
    break;

  case 390:
#line 3444 "c_grammar.y"
    {
				ILType *type = CTypeFromCSharp
					(&CCCodeGen, ILQualIdentName((yyvsp[(3) - (6)].node), 0), (yyvsp[(5) - (6)].node));
				if(type)
				{
					ProcessUsingTypeDeclaration(type, (yyvsp[(5) - (6)].node));
				}
				else
				{
					CCError(_("could not resolve `[%s]%s' as a C# type"),
							ILQualIdentName((yyvsp[(3) - (6)].node), 0), ILQualIdentName((yyvsp[(5) - (6)].node), 0));
				}
			}
    break;

  case 391:
#line 3460 "c_grammar.y"
    { (yyval.node) = ILQualIdentSimple((yyvsp[(1) - (1)].name)); }
    break;

  case 392:
#line 3461 "c_grammar.y"
    {
				(yyval.node) = ILNode_QualIdent_create((yyvsp[(1) - (3)].node), ILQualIdentSimple((yyvsp[(3) - (3)].name)));
			}
    break;

  case 393:
#line 3467 "c_grammar.y"
    {
				CScopePushNamespace((yyvsp[(1) - (2)].name));
			}
    break;

  case 394:
#line 3469 "c_grammar.y"
    {
				CScopePopNamespace((yyvsp[(1) - (4)].name));
				(yyval.type) = (yyvsp[(4) - (4)].type);
			}
    break;

  case 395:
#line 3476 "c_grammar.y"
    {
				(yyval.type) = CScopeGetType(CScopeLookup((yyvsp[(1) - (1)].name)));
			}
    break;

  case 396:
#line 3479 "c_grammar.y"
    {
				CScopePushNamespace((yyvsp[(1) - (2)].name));
			}
    break;

  case 397:
#line 3481 "c_grammar.y"
    {
				CScopePopNamespace((yyvsp[(1) - (4)].name));
				(yyval.type) = (yyvsp[(4) - (4)].type);
			}
    break;


/* Line 1267 of yacc.c.  */
#line 7319 "c_grammar.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



