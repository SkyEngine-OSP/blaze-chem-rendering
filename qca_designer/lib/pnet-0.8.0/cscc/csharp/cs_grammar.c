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
     INTEGER_CONSTANT = 258,
     CHAR_CONSTANT = 259,
     IDENTIFIER_LEXICAL = 260,
     STRING_LITERAL = 261,
     FLOAT_CONSTANT = 262,
     DECIMAL_CONSTANT = 263,
     DOC_COMMENT = 264,
     ABSTRACT = 265,
     ADD = 266,
     ARGLIST = 267,
     AS = 268,
     BASE = 269,
     BOOL = 270,
     BREAK = 271,
     BUILTIN_CONSTANT = 272,
     BYTE = 273,
     CASE = 274,
     CATCH = 275,
     CHAR = 276,
     CHECKED = 277,
     CLASS = 278,
     CONST = 279,
     CONTINUE = 280,
     DECIMAL = 281,
     DEFAULT = 282,
     DELEGATE = 283,
     DO = 284,
     DOUBLE = 285,
     ELSE = 286,
     ENUM = 287,
     EVENT = 288,
     EXPLICIT = 289,
     EXTERN = 290,
     FALSE = 291,
     FINALLY = 292,
     FIXED = 293,
     FLOAT = 294,
     FOR = 295,
     FOREACH = 296,
     GET = 297,
     GOTO = 298,
     IF = 299,
     IMPLICIT = 300,
     IN = 301,
     INT = 302,
     INTERFACE = 303,
     INTERNAL = 304,
     IS = 305,
     LOCK = 306,
     LONG = 307,
     LONG_DOUBLE = 308,
     MAKEREF = 309,
     MODULE = 310,
     NAMESPACE = 311,
     NEW = 312,
     NULL_TOK = 313,
     OBJECT = 314,
     OPERATOR = 315,
     OUT = 316,
     OVERRIDE = 317,
     PARAMS = 318,
     PARTIAL = 319,
     PRIVATE = 320,
     PROTECTED = 321,
     PUBLIC = 322,
     READONLY = 323,
     REMOVE = 324,
     REF = 325,
     REFTYPE = 326,
     REFVALUE = 327,
     RETURN = 328,
     SBYTE = 329,
     SEALED = 330,
     SET = 331,
     SHORT = 332,
     SIZEOF = 333,
     STACKALLOC = 334,
     STATIC = 335,
     STRING = 336,
     STRUCT = 337,
     SWITCH = 338,
     THIS = 339,
     THROW = 340,
     TRUE = 341,
     TRY = 342,
     TYPEOF = 343,
     UINT = 344,
     ULONG = 345,
     UNCHECKED = 346,
     UNSAFE = 347,
     USHORT = 348,
     USING = 349,
     VIRTUAL = 350,
     VOID = 351,
     VOLATILE = 352,
     WHERE = 353,
     WHILE = 354,
     YIELD = 355,
     INC_OP = 356,
     DEC_OP = 357,
     LEFT_OP = 358,
     RIGHT_OP = 359,
     LE_OP = 360,
     GE_OP = 361,
     EQ_OP = 362,
     NE_OP = 363,
     AND_OP = 364,
     OR_OP = 365,
     MUL_ASSIGN_OP = 366,
     DIV_ASSIGN_OP = 367,
     MOD_ASSIGN_OP = 368,
     ADD_ASSIGN_OP = 369,
     SUB_ASSIGN_OP = 370,
     LEFT_ASSIGN_OP = 371,
     RIGHT_ASSIGN_OP = 372,
     AND_ASSIGN_OP = 373,
     XOR_ASSIGN_OP = 374,
     OR_ASSIGN_OP = 375,
     PTR_OP = 376,
     GENERIC_LT = 377
   };
#endif
/* Tokens.  */
#define INTEGER_CONSTANT 258
#define CHAR_CONSTANT 259
#define IDENTIFIER_LEXICAL 260
#define STRING_LITERAL 261
#define FLOAT_CONSTANT 262
#define DECIMAL_CONSTANT 263
#define DOC_COMMENT 264
#define ABSTRACT 265
#define ADD 266
#define ARGLIST 267
#define AS 268
#define BASE 269
#define BOOL 270
#define BREAK 271
#define BUILTIN_CONSTANT 272
#define BYTE 273
#define CASE 274
#define CATCH 275
#define CHAR 276
#define CHECKED 277
#define CLASS 278
#define CONST 279
#define CONTINUE 280
#define DECIMAL 281
#define DEFAULT 282
#define DELEGATE 283
#define DO 284
#define DOUBLE 285
#define ELSE 286
#define ENUM 287
#define EVENT 288
#define EXPLICIT 289
#define EXTERN 290
#define FALSE 291
#define FINALLY 292
#define FIXED 293
#define FLOAT 294
#define FOR 295
#define FOREACH 296
#define GET 297
#define GOTO 298
#define IF 299
#define IMPLICIT 300
#define IN 301
#define INT 302
#define INTERFACE 303
#define INTERNAL 304
#define IS 305
#define LOCK 306
#define LONG 307
#define LONG_DOUBLE 308
#define MAKEREF 309
#define MODULE 310
#define NAMESPACE 311
#define NEW 312
#define NULL_TOK 313
#define OBJECT 314
#define OPERATOR 315
#define OUT 316
#define OVERRIDE 317
#define PARAMS 318
#define PARTIAL 319
#define PRIVATE 320
#define PROTECTED 321
#define PUBLIC 322
#define READONLY 323
#define REMOVE 324
#define REF 325
#define REFTYPE 326
#define REFVALUE 327
#define RETURN 328
#define SBYTE 329
#define SEALED 330
#define SET 331
#define SHORT 332
#define SIZEOF 333
#define STACKALLOC 334
#define STATIC 335
#define STRING 336
#define STRUCT 337
#define SWITCH 338
#define THIS 339
#define THROW 340
#define TRUE 341
#define TRY 342
#define TYPEOF 343
#define UINT 344
#define ULONG 345
#define UNCHECKED 346
#define UNSAFE 347
#define USHORT 348
#define USING 349
#define VIRTUAL 350
#define VOID 351
#define VOLATILE 352
#define WHERE 353
#define WHILE 354
#define YIELD 355
#define INC_OP 356
#define DEC_OP 357
#define LEFT_OP 358
#define RIGHT_OP 359
#define LE_OP 360
#define GE_OP 361
#define EQ_OP 362
#define NE_OP 363
#define AND_OP 364
#define OR_OP 365
#define MUL_ASSIGN_OP 366
#define DIV_ASSIGN_OP 367
#define MOD_ASSIGN_OP 368
#define ADD_ASSIGN_OP 369
#define SUB_ASSIGN_OP 370
#define LEFT_ASSIGN_OP 371
#define RIGHT_ASSIGN_OP 372
#define AND_ASSIGN_OP 373
#define XOR_ASSIGN_OP 374
#define OR_ASSIGN_OP 375
#define PTR_OP 376
#define GENERIC_LT 377




/* Copy the first part of user declarations.  */
#line 1 "cs_grammar.y"

/*
 * cs_grammar.y - Input file for yacc that defines the syntax of C#.
 *
 * Copyright (C) 2001, 2002, 2003  Southern Storm Software, Pty Ltd.
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
#include "cs_rename.h"

/*#define YYDEBUG 1*/

#include <stdio.h>
#include "il_system.h"
#include "il_opcodes.h"
#include "il_meta.h"
#include "il_utils.h"
#include "cs_internal.h"
#ifdef HAVE_STDARG_H
	#include <stdarg.h>
#else
	#ifdef HAVE_VARARGS_H
		#include <varargs.h>
	#endif
#endif

#define	YYERROR_VERBOSE

/*
 * An ugly hack to work around missing "-lfl" libraries on MacOSX.
 */
#if defined(__APPLE_CC__) && !defined(YYTEXT_POINTER)
	#define	YYTEXT_POINTER 1
#endif

/*
 * Imports from the lexical analyser.
 */
extern int yylex(void);
#ifdef YYTEXT_POINTER
extern char *cs_text;
#else
extern char cs_text[];
#endif

int CSMetadataOnly = 0;

/*
 * Global state used by the parser.
 */
static unsigned long NestingLevel = 0;
static ILIntString CurrNamespace = {"", 0};
static ILNode_Namespace *CurrNamespaceNode = 0;
static ILScope* localScope = 0;
static int HaveDecls = 0;

/*
 * Initialize the global namespace, if necessary.
 */
static void InitGlobalNamespace(void)
{
	if(!CurrNamespaceNode)
	{
		ILNode_UsingNamespace *using;
		CurrNamespaceNode = (ILNode_Namespace *)ILNode_Namespace_create(0, 0);
		using = (ILNode_UsingNamespace *)ILNode_UsingNamespace_create("System");
		using->next = CurrNamespaceNode->using;
		CurrNamespaceNode->using = using;
	}
}

/*
 * Get the global scope.
 */
static ILScope *GlobalScope(void)
{
	if(CCGlobalScope)
	{
		return CCGlobalScope;
	}
	else
	{
		CCGlobalScope = ILScopeCreate(&CCCodeGen, 0);
		ILScopeDeclareNamespace(CCGlobalScope, "System");
		ILScopeUsing(CCGlobalScope, "System");
		return CCGlobalScope;
	}
}

/* 
 * Get the local scope
 */
static ILScope *LocalScope(void)
{
	if(localScope)
	{
		return localScope;
	}
	else
	{
		localScope = ILScopeCreate(&CCCodeGen, CCGlobalScope);
		return localScope;
	}
}

/*
 * Reset the global state ready for the next file to be parsed.
 */
static void ResetState(void)
{
	NestingLevel = 0;
	CurrNamespace = ILInternString("", 0);
	CurrNamespaceNode = 0;
	HaveDecls = 0;
	localScope = 0;
	ILScopeClearUsing(GlobalScope());
}

/*
 * Determine if the current namespace already has a "using"
 * declaration for a particular namespace.
 */
static int HaveUsingNamespace(char *name)
{
	ILNode_UsingNamespace *using = CurrNamespaceNode->using;
	while(using != 0)
	{
		if(!strcmp(using->name, name))
		{
			return 1;
		}
		using = using->next;
	}
	return 0;
}

static void yyerror(char *msg)
{
	CCPluginParseError(msg, cs_text);
}

/*
 * Determine if an extension has been enabled using "-f".
 */
#define	HaveExtension(name)	\
	(CSStringListContains(extension_flags, num_extension_flags, (name)))

/*
 * Make a simple node and put it into $$.
 */
#define	MakeSimple(classSuffix)	\
	do {	\
		yyval.node = \
			ILNode_##classSuffix##_create(); \
	} while (0)

/*
 * Make a unary node and put it into $$.
 */
#define	MakeUnary(classSuffix,expr)	\
	do {	\
		yyval.node = ILNode_##classSuffix##_create((expr)); \
	} while (0)

/*
 * Make a binary node and put it into $$.
 */
#define	MakeBinary(classSuffix,expr1,expr2)	\
	do {	\
		yyval.node = ILNode_##classSuffix##_create((expr1), (expr2)); \
	} while (0)

/*
 * Make a ternary node and put it into $$.
 */
#define	MakeTernary(classSuffix,expr1,expr2,expr3)	\
	do {	\
		yyval.node = ILNode_##classSuffix##_create((expr1), (expr2), (expr3)); \
	} while (0)

/*
 * Make a quaternary node and put it into $$.
 */
#define	MakeQuaternary(classSuffix,expr1,expr2,expr3,expr4)	\
	do {	\
		yyval.node = ILNode_##classSuffix##_create \
							((expr1), (expr2), (expr3), (expr4)); \
	} while (0)

/*
 * Make a system type name node.
 */
#define	MakeSystemType(name)	\
			(ILNode_GlobalNamespace_create(ILNode_SystemType_create(name)))

/*
 * Clone the filename/linenum information from one node to another.
 */
static void CloneLine(ILNode *dest, ILNode *src)
{
	yysetfilename(dest, yygetfilename(src));
	yysetlinenum(dest, yygetlinenum(src));
}

/*
 * Make a list from an existing list (may be NULL), and a new node
 * (which may also be NULL).
 */
static ILNode *MakeList(ILNode *list, ILNode *node)
{
	if(!node)
	{
		return list;
	}
	else if(!list)
	{
		list = ILNode_List_create();
	}
	ILNode_List_Add(list, node);
	return list;
}

/*
 * Negate an integer node.
 */
static ILNode *NegateInteger(ILNode_Integer *node)
{
	if(node->canneg)
	{
		if(yyisa(node, ILNode_Int32))
		{
			node->isneg = !(node->isneg);
			return (ILNode *)node;
		}
		else if(yyisa(node, ILNode_UInt32))
		{
			return ILNode_Int32_create(node->value, 1, 0);
		}
		else if(yyisa(node, ILNode_Int64))
		{
			node->isneg = !(node->isneg);
			return (ILNode *)node;
		}
		else if(yyisa(node, ILNode_UInt64))
		{
			return ILNode_Int64_create(node->value, 1, 0);
		}
	}
	return ILNode_Neg_create((ILNode *)node);
}

/*
 * The class name stack, which is used to verify the names
 * of constructors and destructors against the name of their
 * enclosing classes.  Also used to check if a class has
 * had a constructor defined for it.
 */
static ILNode **classNameStack = 0;
static int     *classNameCtorDefined = 0;
static int		classNameStackSize = 0;
static int		classNameStackMax = 0;

/*
 * Push an item onto the class name stack.
 */
static void ClassNamePush(ILNode *name)
{
	if(classNameStackSize >= classNameStackMax)
	{
		classNameStack = (ILNode **)ILRealloc
			(classNameStack, sizeof(ILNode *) * (classNameStackMax + 4));
		if(!classNameStack)
		{
			CCOutOfMemory();
		}
		classNameCtorDefined = (int *)ILRealloc
			(classNameCtorDefined, sizeof(int) * (classNameStackMax + 4));
		if(!classNameCtorDefined)
		{
			CCOutOfMemory();
		}
		classNameStackMax += 4;
	}
	classNameStack[classNameStackSize] = name;
	classNameCtorDefined[classNameStackSize++] = 0;
}

/*
 * Pop an item from the class name stack.
 */
static void ClassNamePop(void)
{
	--classNameStackSize;
}

/*
 * Record that a constructor was defined for the current class.
 */
static void ClassNameCtorDefined(void)
{
	classNameCtorDefined[classNameStackSize - 1] = 1;
}

/*
 * Determine if a constructor was defined for the current class.
 */
static int ClassNameIsCtorDefined(void)
{
	return classNameCtorDefined[classNameStackSize - 1];
}

/*
 * Determine if an identifier is identical to
 * the top of the class name stack.
 */
static int ClassNameSame(ILNode *name)
{
	return (strcmp(((ILNode_Identifier *)name)->name,
	   ((ILNode_Identifier *)(classNameStack[classNameStackSize - 1]))->name)
	   			== 0);
}

/*
 * Modify an attribute name so that it ends in "Attribute".
 */
static void ModifyAttrName(ILNode *node,int force)
{
	char *name;
	int namelen;
	ILNode_Identifier *ident;
	
	if(yyisa(node,ILNode_QualIdent))
	{
		ModifyAttrName(((ILNode_QualIdent*)node)->right, force);
		return;
	}
	
	ident = (ILNode_Identifier*) node;
	
	name = ident->name;
	namelen = strlen(name);
	if(force || (namelen < 9 || strcmp(name + namelen - 9, "Attribute") != 0))
	{
		ident->name = ILInternAppendedString
			(ILInternString(name, namelen),
			 ILInternString("Attribute", 9)).string;
	}
}

/* A hack to rename the indexer during parsing , damn the C# designers,
 * they had to make the variable names resolved later using an attribute
 * public int <name>[int posn] would have been a cleaner design. But
 * This is an UGLY hack and should be removed as soon as someone figures
 * out how .
 */
static ILNode *GetIndexerName(ILGenInfo *info,ILNode_AttributeTree *attrTree,
								ILNode* prefixName)
{
	ILNode_ListIter iter;
	ILNode_ListIter iter2;
	ILNode *temp;
	ILNode *attr;
	ILNode_List *args;
	ILEvalValue evalValue;
	char* prefix=(prefixName) ? ILQualIdentName(prefixName,0) : NULL;
	int i;

	const char* possibleWays[] = {"IndexerName", "IndexerNameAttribute",
					"System.Runtime.CompilerServices.IndexerNameAttribute",
					"System.Runtime.CompilerServices.IndexerName"};
	int isIndexerName=0;
	
	if(attrTree && attrTree->sections)
	{
		ILNode_ListIter_Init(&iter, attrTree->sections);
		while((temp = ILNode_ListIter_Next(&iter))!=0)
		{	
			if(!(temp != NULL
					&& yyisa(temp, ILNode_AttributeSection) &&
					((ILNode_AttributeSection*)temp)->attrs != NULL))
			{
				continue;
			}
			
			ILNode_ListIter_Init(&iter2, 
				((ILNode_AttributeSection*)(temp))->attrs);
			while((attr = ILNode_ListIter_Next(&iter2))!=0)
			{
				for(i=0;i<sizeof(possibleWays)/sizeof(char*); i++)
				{
					isIndexerName |= !strcmp(
							ILQualIdentName(((ILNode_Attribute*)attr)->name,0)
							,possibleWays[i]);
				}
				if(isIndexerName)
				{
					/* NOTE: we make it 
					[System.Runtime.CompilerServices.IndexerNameAttribute]
					for the sake of resolution...This too is too ugly a 
					hack.
					*/
					ModifyAttrName(((ILNode_Attribute*)attr)->name,0);

					args=(ILNode_List*)((ILNode_AttrArgs*)
						(((ILNode_Attribute*)attr)->args))->positionalArgs;	
					if(yyisa(args->item1, ILNode_ToConst) &&
					   ILNode_EvalConst(args->item1,info,&evalValue))
					{
						if(evalValue.valueType==ILMachineType_String)
						{
							if(!prefix)
							{
								return ILQualIdentSimple(
									ILInternString(evalValue.un.strValue.str,
										evalValue.un.strValue.len).string);
							}
							else 
							{
								return ILNode_QualIdent_create(prefixName,
									ILQualIdentSimple(
									ILInternString(evalValue.un.strValue.str,
										evalValue.un.strValue.len).string));
							}
						}
					}
				}
			}
		}
	}
	if(!prefix)
		return ILQualIdentSimple(ILInternString("Item", 4).string);
	else 
		return ILNode_QualIdent_create(prefixName,
						ILQualIdentSimple(ILInternString("Item",4).string));
}
/*
 * Adjust the name of a property to include a "get_" or "set_" prefix.
 */
static ILNode *AdjustPropertyName(ILNode *name, char *prefix)
{
	ILNode *node;
	if(yykind(name) == yykindof(ILNode_Identifier))
	{
		/* Simple name: just add the prefix */
		node = ILQualIdentSimple
					(ILInternAppendedString
						(ILInternString(prefix, strlen(prefix)),
						 ILInternString(ILQualIdentName(name, 0), -1)).string);
		CloneLine(node, name);
		return node;
	}
	else if(yykind(name) == yykindof(ILNode_QualIdent))
	{
		/* Qualified name: add the prefix to the second component */
		node = ILNode_QualIdent_create(((ILNode_QualIdent *)name)->left,
			AdjustPropertyName(((ILNode_QualIdent *)name)->right, prefix));
		CloneLine(node, name);
		return node;
	}
	else
	{
		/* Shouldn't happen */
		return name;
	}
}

/*
 * Create the methods needed by a property definition.
 */
static void CreatePropertyMethods(ILNode_PropertyDeclaration *property)
{
	ILNode_MethodDeclaration *decl;
	ILNode *name;
	ILNode *params;
	ILNode_ListIter iter;
	ILNode *temp;

	/* Create the "get" method */
	if((property->getsetFlags & 1) != 0)
	{
		name = AdjustPropertyName(property->name, "get_");
		decl = (ILNode_MethodDeclaration *)(property->getAccessor);
		if(!decl)
		{
			/* Abstract interface definition */
			decl = (ILNode_MethodDeclaration *)
				ILNode_MethodDeclaration_create
						(0, property->modifiers, property->type,
						 name, property->params, 0);
			property->getAccessor = (ILNode *)decl;
		}
		else
		{
			/* Regular class definition */
			decl->modifiers = property->modifiers;
			decl->type = property->type;
			decl->name = name;
			decl->params = property->params;
		}
	}

	/* Create the "set" method */
	if((property->getsetFlags & 2) != 0)
	{
		name = AdjustPropertyName(property->name, "set_");
		params = ILNode_List_create();
		ILNode_ListIter_Init(&iter, property->params);
		while((temp = ILNode_ListIter_Next(&iter)) != 0)
		{
			ILNode_List_Add(params, temp);
		}
		ILNode_List_Add(params,
			ILNode_FormalParameter_create(0, ILParamMod_empty, property->type,
					ILQualIdentSimple(ILInternString("value", 5).string)));
		decl = (ILNode_MethodDeclaration *)(property->setAccessor);
		if(!decl)
		{
			/* Abstract interface definition */
			decl = (ILNode_MethodDeclaration *)
				ILNode_MethodDeclaration_create
						(0, property->modifiers, 0, name, params, 0);
			property->setAccessor = (ILNode *)decl;
		}
		else
		{
			/* Regular class definition */
			decl->modifiers = property->modifiers;
			decl->type = 0;
			decl->name = name;
			decl->params = params;
		}
	}
}

/*
 * Create the methods needed by an event declarator.
 */
static void CreateEventDeclMethods(ILNode_EventDeclaration *event,
								   ILNode_EventDeclarator *decl)
{
	ILNode_MethodDeclaration *method;
	ILNode *eventName;
	ILNode *name;
	ILNode *addParams;
	ILNode *removeParams;

	/* Get the name of the event */
	eventName = ((ILNode_FieldDeclarator *)(decl->fieldDeclarator))->name;

	/* Create the parameter information for the "add" and "remove" methods */
	addParams = ILNode_List_create();
	ILNode_List_Add(addParams,
		ILNode_FormalParameter_create(0, ILParamMod_empty, event->type,
				ILQualIdentSimple(ILInternString("value", 5).string)));
	removeParams = ILNode_List_create();
	ILNode_List_Add(removeParams,
		ILNode_FormalParameter_create(0, ILParamMod_empty, event->type,
				ILQualIdentSimple(ILInternString("value", 5).string)));

	/* Create the "add" method */
	name = AdjustPropertyName(eventName, "add_");
	method = (ILNode_MethodDeclaration *)(decl->addAccessor);
	if(!method && event->needFields)
	{
		/* Field-based event that needs a pre-defined body */
		method = (ILNode_MethodDeclaration *)
			ILNode_MethodDeclaration_create
					(0, event->modifiers, 0, name, addParams, 0);
		method->body = ILNode_NewScope_create
							(ILNode_AssignAdd_create
								(ILNode_Add_create(eventName, 
									ILQualIdentSimple
										(ILInternString("value", 5).string))));
		decl->addAccessor = (ILNode *)method;
	}
	else if(!method)
	{
		/* Abstract interface definition */
		method = (ILNode_MethodDeclaration *)
			ILNode_MethodDeclaration_create
					(0, event->modifiers, 0, name, addParams, 0);
		decl->addAccessor = (ILNode *)method;
	}
	else
	{
		/* Regular class definition */
		method->modifiers = event->modifiers;
		method->type = 0;
		method->name = name;
		method->params = addParams;
	}
	method->modifiers |= IL_META_METHODDEF_SPECIAL_NAME;

	/* Create the "remove" method */
	name = AdjustPropertyName(eventName, "remove_");
	method = (ILNode_MethodDeclaration *)(decl->removeAccessor);
	if(!method && event->needFields)
	{
		/* Field-based event that needs a pre-defined body */
		method = (ILNode_MethodDeclaration *)
			ILNode_MethodDeclaration_create
					(0, event->modifiers, 0, name, removeParams, 0);
		method->body = ILNode_NewScope_create
							(ILNode_AssignSub_create
								(ILNode_Sub_create(eventName, 
									ILQualIdentSimple
										(ILInternString("value", 5).string))));
		decl->removeAccessor = (ILNode *)method;
	}
	else if(!method)
	{
		/* Abstract interface definition */
		method = (ILNode_MethodDeclaration *)
			ILNode_MethodDeclaration_create
					(0, event->modifiers, 0, name, removeParams, 0);
		decl->removeAccessor = (ILNode *)method;
	}
	else
	{
		/* Regular class definition */
		method->modifiers = event->modifiers;
		method->type = 0;
		method->name = name;
		method->params = removeParams;
	}
	method->modifiers |= IL_META_METHODDEF_SPECIAL_NAME;
}

/*
 * Create the methods needed by an event definition.
 */
static void CreateEventMethods(ILNode_EventDeclaration *event)
{
	ILNode_ListIter iter;
	ILNode *decl;

	if(yyisa(event->eventDeclarators, ILNode_EventDeclarator))
	{
		/* A single declarator indicates a property-style event */
		event->needFields = 0;

		/* Create the methods for the event declarator */
		CreateEventDeclMethods
			(event, (ILNode_EventDeclarator *)(event->eventDeclarators));
	}
	else
	{
		/* A list of declarators indicates a field-style event */
		event->needFields =
			((event->modifiers & IL_META_METHODDEF_ABSTRACT) == 0);

		/* Scan the list and create the methods that we require */
		ILNode_ListIter_Init(&iter, event->eventDeclarators);
		while((decl = ILNode_ListIter_Next(&iter)) != 0)
		{
			CreateEventDeclMethods(event, (ILNode_EventDeclarator *)decl);
		}
	}
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
#line 680 "cs_grammar.y"
{
	struct
	{
		ILUInt64	value;
		int			type;
		int			canneg;
	}					integer;
	struct
	{
		ILDouble	value;
		int			type;
	}					real;
	ILDecimal  			decimal;
	ILUInt16			charValue;
	ILIntString			string;
	char			   *name;
	ILUInt32			count;
	ILUInt32			mask;
	ILNode			   *node;
	struct
	{
		ILNode		   *type;
		char		   *id;
		ILNode         *idNode;
	} catchinfo;
	struct
	{
		ILNode		   *item1;
		ILNode		   *item2;
	} pair;
	ILParameterModifier	pmod;
	struct
	{
		char           *binary;
		char           *unary;

	} opName;
	struct
	{
		ILNode		   *type;
		ILNode		   *ident;
		ILNode		   *params;

	} indexer;
	struct
	{
		ILNode		   *decl;
		ILNode		   *init;

	} varInit;
	struct
	{
		ILNode		   *body;
		ILNode		   *staticCtors;

	} member;
	struct
	{
		ILAttrTargetType targetType;
		ILNode		   *target;

	} target;
	int					partial;
}
/* Line 193 of yacc.c.  */
#line 1081 "cs_grammar.c"
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
#line 1106 "cs_grammar.c"

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  212
/* YYNRULES -- Number of rules.  */
#define YYNRULES  574
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1029

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   377

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,     2,     2,     2,   142,   140,     2,
     134,   135,   132,   138,   133,   139,   124,   141,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   146,   127,
     125,   129,   126,   145,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   130,     2,   131,   143,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   128,   144,   123,   137,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     9,    11,    13,    16,    18,
      20,    22,    24,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    55,    57,    62,    67,
      68,    75,    77,    81,    82,    84,    88,    94,    98,    99,
     101,   103,   105,   107,   109,   111,   113,   115,   117,   119,
     121,   126,   129,   134,   139,   141,   146,   149,   152,   155,
     160,   165,   167,   171,   174,   180,   186,   189,   190,   192,
     194,   197,   201,   203,   204,   206,   208,   211,   213,   215,
     217,   219,   221,   223,   225,   227,   229,   231,   233,   235,
     237,   239,   241,   243,   245,   247,   249,   253,   257,   261,
     263,   268,   272,   277,   279,   281,   285,   290,   293,   296,
     298,   306,   310,   315,   320,   325,   330,   334,   340,   345,
     350,   355,   362,   364,   367,   371,   375,   377,   379,   381,
     383,   385,   387,   389,   391,   396,   402,   403,   405,   407,
     411,   413,   416,   419,   421,   425,   426,   428,   432,   437,
     439,   442,   445,   450,   455,   457,   460,   463,   466,   469,
     472,   475,   477,   481,   485,   489,   491,   495,   499,   501,
     505,   509,   511,   515,   519,   523,   527,   531,   535,   537,
     542,   547,   553,   560,   568,   574,   582,   584,   588,   592,
     594,   598,   600,   604,   606,   610,   612,   616,   618,   622,
     624,   630,   634,   638,   642,   646,   650,   654,   658,   662,
     666,   670,   674,   676,   678,   682,   686,   688,   690,   694,
     698,   699,   701,   705,   710,   711,   713,   715,   719,   721,
     723,   724,   726,   730,   733,   736,   738,   740,   742,   744,
     747,   749,   751,   753,   755,   758,   761,   763,   765,   767,
     770,   772,   775,   778,   780,   784,   786,   790,   794,   798,
     802,   803,   805,   807,   810,   812,   814,   816,   818,   820,
     823,   826,   829,   832,   836,   842,   846,   850,   854,   855,
     857,   859,   862,   865,   867,   870,   874,   877,   881,   887,
     894,   902,   905,   907,   910,   912,   914,   917,   919,   922,
     925,   927,   930,   933,   936,   938,   942,   945,   948,   952,
     957,   961,   964,   968,   971,   975,   979,   983,   988,   991,
     994,   995,   997,   999,  1002,  1006,  1007,  1012,  1016,  1020,
    1021,  1023,  1026,  1029,  1033,  1037,  1042,  1046,  1050,  1057,
    1059,  1063,  1067,  1072,  1076,  1077,  1079,  1081,  1083,  1086,
    1091,  1097,  1099,  1103,  1106,  1109,  1112,  1114,  1118,  1120,
    1123,  1126,  1130,  1136,  1140,  1142,  1146,  1148,  1150,  1154,
    1158,  1160,  1161,  1163,  1165,  1168,  1170,  1172,  1174,  1176,
    1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,
    1197,  1209,  1210,  1214,  1218,  1220,  1224,  1225,  1228,  1230,
    1234,  1238,  1244,  1245,  1250,  1251,  1254,  1256,  1260,  1264,
    1268,  1269,  1271,  1273,  1276,  1278,  1280,  1282,  1284,  1286,
    1288,  1290,  1292,  1294,  1296,  1297,  1299,  1306,  1308,  1312,
    1316,  1322,  1324,  1328,  1330,  1334,  1343,  1345,  1347,  1348,
    1350,  1352,  1356,  1361,  1363,  1364,  1366,  1368,  1370,  1377,
    1379,  1382,  1385,  1388,  1391,  1392,  1394,  1398,  1399,  1401,
    1405,  1407,  1409,  1411,  1413,  1420,  1422,  1426,  1428,  1432,
    1440,  1443,  1446,  1449,  1452,  1456,  1460,  1466,  1470,  1476,
    1480,  1484,  1486,  1490,  1495,  1497,  1499,  1501,  1513,  1528,
    1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,
    1550,  1552,  1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,
    1570,  1572,  1584,  1596,  1605,  1606,  1612,  1618,  1626,  1627,
    1639,  1640,  1643,  1647,  1651,  1652,  1664,  1665,  1668,  1672,
    1676,  1677,  1679,  1681,  1684,  1686,  1688,  1690,  1692,  1701,
    1702,  1704,  1711,  1713,  1716,  1719,  1722,  1725,  1730,  1735,
    1742,  1750,  1751,  1760,  1761,  1764,  1766,  1768,  1770,  1772,
    1774,  1776,  1778,  1780,  1784,  1789,  1793,  1794,  1796,  1798,
    1802,  1805,  1810,  1821,  1823
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     148,     0,    -1,    -1,   151,    -1,   151,   257,    -1,   257,
      -1,   150,    -1,   149,   150,    -1,   162,    -1,   164,    -1,
       1,    -1,   152,    -1,   151,   152,    -1,   150,    -1,   123,
      -1,   154,    -1,     5,    -1,    42,    -1,    76,    -1,    11,
      -1,    69,    -1,    98,    -1,    64,    -1,   100,    -1,   156,
      -1,   155,   124,   156,    -1,   153,    -1,   153,   125,   168,
     126,    -1,   153,   122,   168,   126,    -1,    -1,   256,    56,
     159,   158,   161,   160,    -1,   154,    -1,   159,   124,   154,
      -1,    -1,   127,    -1,   128,   163,   123,    -1,    94,   154,
     129,   155,   127,    -1,    94,   159,   127,    -1,    -1,   149,
      -1,   157,    -1,   165,    -1,   272,    -1,   279,    -1,   330,
      -1,   334,    -1,   349,    -1,   357,    -1,   155,    -1,   175,
      -1,   166,   130,   173,   131,    -1,   166,   132,    -1,   166,
     125,   168,   126,    -1,   166,   122,   168,   126,    -1,   175,
      -1,   167,   130,   173,   131,    -1,   167,   132,    -1,   201,
     132,    -1,   188,   132,    -1,   167,   125,   168,   126,    -1,
     167,   122,   168,   126,    -1,   166,    -1,   168,   133,   166,
      -1,   176,   170,    -1,   176,   125,   168,   126,   170,    -1,
     176,   122,   168,   126,   170,    -1,   175,   170,    -1,    -1,
     171,    -1,   172,    -1,   171,   172,    -1,   130,   173,   131,
      -1,   132,    -1,    -1,   174,    -1,   133,    -1,   174,   133,
      -1,    96,    -1,    15,    -1,    74,    -1,    18,    -1,    77,
      -1,    93,    -1,    47,    -1,    89,    -1,    52,    -1,    90,
      -1,    21,    -1,    39,    -1,    30,    -1,    53,    -1,    26,
      -1,    59,    -1,    81,    -1,   177,    -1,   153,    -1,   134,
     201,   135,    -1,   176,   124,   153,    -1,   175,   124,   153,
      -1,   178,    -1,   176,   130,   183,   131,    -1,   176,   130,
     131,    -1,   176,   130,   174,   131,    -1,    12,    -1,    84,
      -1,    14,   124,   153,    -1,    14,   130,   183,   131,    -1,
     176,   101,    -1,   176,   102,    -1,   179,    -1,    57,   166,
     130,   183,   131,   184,   206,    -1,    57,   166,   207,    -1,
      88,   134,   166,   135,    -1,    78,   134,   166,   135,    -1,
      22,   134,   201,   135,    -1,    91,   134,   201,   135,    -1,
     176,   121,   153,    -1,    79,   166,   130,   201,   131,    -1,
      17,   134,     6,   135,    -1,    54,   134,   201,   135,    -1,
      71,   134,   201,   135,    -1,    72,   134,   201,   133,   166,
     135,    -1,    55,    -1,    28,   358,    -1,   176,   124,    27,
      -1,   175,   124,    27,    -1,    86,    -1,    36,    -1,    58,
      -1,     3,    -1,     7,    -1,     8,    -1,     4,    -1,     6,
      -1,   176,   134,   180,   135,    -1,    57,   166,   134,   180,
     135,    -1,    -1,   181,    -1,   182,    -1,   181,   133,   182,
      -1,   201,    -1,    61,   201,    -1,    70,   201,    -1,   201,
      -1,   183,   133,   201,    -1,    -1,   185,    -1,   130,   173,
     131,    -1,   185,   130,   173,   131,    -1,   176,    -1,   136,
     187,    -1,   137,   187,    -1,   134,   201,   135,   186,    -1,
     134,   167,   135,   187,    -1,   186,    -1,   138,   187,    -1,
     139,   187,    -1,   101,   187,    -1,   102,   187,    -1,   132,
     187,    -1,   140,   187,    -1,   187,    -1,   188,   132,   187,
      -1,   188,   141,   187,    -1,   188,   142,   187,    -1,   188,
      -1,   189,   138,   188,    -1,   189,   139,   188,    -1,   189,
      -1,   190,   103,   189,    -1,   190,   104,   189,    -1,   190,
      -1,   191,   125,   190,    -1,   191,   126,   190,    -1,   191,
     105,   190,    -1,   191,   106,   190,    -1,   191,    50,   166,
      -1,   191,    13,   166,    -1,   192,    -1,   192,   134,   180,
     135,    -1,   191,   122,   190,   126,    -1,   191,   122,   190,
     171,   126,    -1,   191,   122,   190,   133,   168,   126,    -1,
     191,   122,   190,   171,   133,   168,   126,    -1,   191,   122,
     175,   170,   126,    -1,   191,   122,   175,   170,   133,   168,
     126,    -1,   191,    -1,   193,   107,   191,    -1,   193,   108,
     191,    -1,   193,    -1,   194,   140,   193,    -1,   194,    -1,
     195,   143,   194,    -1,   195,    -1,   196,   144,   195,    -1,
     196,    -1,   197,   109,   196,    -1,   197,    -1,   198,   110,
     197,    -1,   198,    -1,   198,   145,   201,   146,   201,    -1,
     187,   129,   201,    -1,   187,   114,   201,    -1,   187,   115,
     201,    -1,   187,   111,   201,    -1,   187,   112,   201,    -1,
     187,   113,   201,    -1,   187,   118,   201,    -1,   187,   120,
     201,    -1,   187,   119,   201,    -1,   187,   116,   201,    -1,
     187,   117,   201,    -1,   199,    -1,   200,    -1,   134,   201,
     135,    -1,   134,     1,   135,    -1,   201,    -1,   201,    -1,
     134,   204,   135,    -1,   134,     1,   135,    -1,    -1,   207,
      -1,   128,   208,   123,    -1,   128,   209,   133,   123,    -1,
      -1,   209,    -1,   210,    -1,   209,   133,   210,    -1,   201,
      -1,   207,    -1,    -1,   133,    -1,   153,   146,   222,    -1,
     215,   127,    -1,   218,   127,    -1,   214,    -1,   214,    -1,
     219,    -1,   127,    -1,   224,   127,    -1,   225,    -1,   232,
      -1,   239,    -1,   240,    -1,    22,   219,    -1,    91,   219,
      -1,   249,    -1,   250,    -1,   252,    -1,    92,   219,    -1,
     255,    -1,     1,   127,    -1,   169,   216,    -1,   217,    -1,
     216,   133,   217,    -1,   153,    -1,   153,   129,   210,    -1,
      24,   166,   289,    -1,   128,   220,   123,    -1,   128,     1,
     123,    -1,    -1,   221,    -1,   222,    -1,   221,   222,    -1,
     212,    -1,   224,    -1,   178,    -1,   179,    -1,   200,    -1,
     176,   101,    -1,   176,   102,    -1,   101,   187,    -1,   102,
     187,    -1,    44,   205,   213,    -1,    44,   205,   213,    31,
     213,    -1,    83,   202,   226,    -1,   128,   227,   123,    -1,
     128,     1,   123,    -1,    -1,   228,    -1,   229,    -1,   228,
     229,    -1,   230,   221,    -1,   231,    -1,   230,   231,    -1,
      19,   203,   146,    -1,    27,   146,    -1,    99,   205,   213,
      -1,    29,   213,    99,   205,   127,    -1,    40,   134,   233,
     235,   236,   213,    -1,    41,   134,   166,   153,    46,   237,
     213,    -1,   234,   127,    -1,   127,    -1,     1,   127,    -1,
     215,    -1,   238,    -1,   204,   127,    -1,   127,    -1,     1,
     127,    -1,   238,   135,    -1,   135,    -1,     1,   135,    -1,
     201,   135,    -1,     1,   135,    -1,   223,    -1,   238,   133,
     223,    -1,    16,   127,    -1,    25,   127,    -1,    43,   153,
     127,    -1,    43,    19,   203,   127,    -1,    43,    27,   127,
      -1,    73,   127,    -1,    73,   201,   127,    -1,    85,   127,
      -1,    85,   201,   127,    -1,    87,   219,   241,    -1,    87,
     219,   248,    -1,    87,   219,   241,   248,    -1,   243,   246,
      -1,   242,   247,    -1,    -1,   243,    -1,   244,    -1,   243,
     244,    -1,    20,   245,   219,    -1,    -1,   134,   166,   153,
     135,    -1,   134,   166,   135,    -1,   134,     1,   135,    -1,
      -1,   247,    -1,    20,   219,    -1,    37,   219,    -1,    51,
     202,   213,    -1,    94,   251,   213,    -1,   134,   169,   216,
     135,    -1,   134,   201,   135,    -1,   134,     1,   135,    -1,
      38,   134,   166,   253,   135,   213,    -1,   254,    -1,   253,
     133,   254,    -1,   153,   129,   201,    -1,   100,    73,   201,
     127,    -1,   100,    16,   127,    -1,    -1,   258,    -1,   258,
      -1,   259,    -1,   258,   259,    -1,   130,   261,   211,   131,
      -1,   130,   260,   261,   211,   131,    -1,     9,    -1,   130,
       1,   131,    -1,   155,   146,    -1,    33,   146,    -1,    73,
     146,    -1,   262,    -1,   261,   133,   262,    -1,   155,    -1,
     155,   263,    -1,   134,   135,    -1,   134,   264,   135,    -1,
     134,   264,   133,   266,   135,    -1,   134,   266,   135,    -1,
     265,    -1,   264,   133,   265,    -1,   268,    -1,   267,    -1,
     266,   133,   267,    -1,   153,   129,   268,    -1,   201,    -1,
      -1,   270,    -1,   271,    -1,   270,   271,    -1,    57,    -1,
      67,    -1,    66,    -1,    49,    -1,    65,    -1,    10,    -1,
      75,    -1,    80,    -1,    68,    -1,    95,    -1,    62,    -1,
      35,    -1,    92,    -1,    97,    -1,    -1,   256,   269,   287,
      23,   153,   274,   281,   276,   273,   283,   160,    -1,    -1,
     125,   275,   126,    -1,   122,   275,   126,    -1,   153,    -1,
     275,   133,   153,    -1,    -1,    98,   277,    -1,   278,    -1,
     277,   133,   278,    -1,   153,   146,   166,    -1,   153,   146,
      57,   134,   135,    -1,    -1,    55,   280,   283,   160,    -1,
      -1,   146,   282,    -1,   166,    -1,   282,   133,   166,    -1,
     128,   284,   123,    -1,   128,     1,   123,    -1,    -1,   285,
      -1,   286,    -1,   285,   286,    -1,   288,    -1,   291,    -1,
     294,    -1,   300,    -1,   309,    -1,   318,    -1,   323,    -1,
     327,    -1,   329,    -1,   165,    -1,    -1,    64,    -1,   256,
     269,    24,   166,   289,   127,    -1,   290,    -1,   289,   133,
     290,    -1,   153,   129,   203,    -1,   256,   269,   166,   292,
     127,    -1,   293,    -1,   292,   133,   293,    -1,   153,    -1,
     153,   129,   210,    -1,   256,   269,   166,   155,   134,   296,
     135,   295,    -1,   219,    -1,   127,    -1,    -1,   297,    -1,
     298,    -1,   297,   133,   298,    -1,   256,   299,   166,   153,
      -1,    12,    -1,    -1,    70,    -1,    61,    -1,    63,    -1,
     256,   269,   166,   155,   301,   302,    -1,   128,    -1,   303,
     123,    -1,     1,   123,    -1,   305,   306,    -1,   307,   304,
      -1,    -1,   305,    -1,   256,    42,   308,    -1,    -1,   307,
      -1,   256,    76,   308,    -1,   219,    -1,   127,    -1,   310,
      -1,   313,    -1,   256,   269,    33,   166,   311,   127,    -1,
     312,    -1,   311,   133,   312,    -1,   153,    -1,   153,   129,
     210,    -1,   256,   269,    33,   166,   155,   301,   314,    -1,
     315,   123,    -1,     1,   123,    -1,   316,   317,    -1,   317,
     316,    -1,   256,    11,   308,    -1,   256,    69,   308,    -1,
     256,   269,   319,   301,   302,    -1,   166,    84,   320,    -1,
     166,   155,   124,    84,   320,    -1,   130,   321,   131,    -1,
     130,     1,   131,    -1,   322,    -1,   321,   133,   322,    -1,
     256,   299,   166,   153,    -1,    12,    -1,   324,    -1,   326,
      -1,   256,   269,   166,    60,   325,   274,   134,   166,   153,
     135,   219,    -1,   256,   269,   166,    60,   325,   274,   134,
     166,   153,   133,   166,   153,   135,   219,    -1,   138,    -1,
     139,    -1,   136,    -1,   137,    -1,   101,    -1,   102,    -1,
      86,    -1,    36,    -1,   132,    -1,   141,    -1,   142,    -1,
     140,    -1,   144,    -1,   143,    -1,   103,    -1,   104,    -1,
     107,    -1,   108,    -1,   126,    -1,   125,    -1,   106,    -1,
     105,    -1,   256,   269,    45,    60,   274,   166,   134,   166,
     153,   135,   219,    -1,   256,   269,    34,    60,   274,   166,
     134,   166,   153,   135,   219,    -1,   256,   269,   156,   134,
     296,   135,   328,   295,    -1,    -1,   146,    14,   134,   180,
     135,    -1,   146,    84,   134,   180,   135,    -1,   256,   269,
     137,   156,   134,   135,   219,    -1,    -1,   256,   269,   287,
      82,   153,   274,   332,   276,   331,   333,   160,    -1,    -1,
     146,   282,    -1,   128,   284,   123,    -1,   128,     1,   123,
      -1,    -1,   256,   269,   287,    48,   153,   274,   336,   276,
     335,   337,   160,    -1,    -1,   146,   282,    -1,   128,   338,
     123,    -1,   128,     1,   123,    -1,    -1,   339,    -1,   340,
      -1,   339,   340,    -1,   341,    -1,   343,    -1,   347,    -1,
     348,    -1,   256,   342,   166,   153,   134,   296,   135,   127,
      -1,    -1,    57,    -1,   256,   342,   166,   153,   344,   345,
      -1,   128,    -1,   346,   123,    -1,     1,   123,    -1,    42,
     127,    -1,    76,   127,    -1,    42,   127,    76,   127,    -1,
      76,   127,    42,   127,    -1,   256,   342,    33,   166,   153,
     127,    -1,   256,   342,   166,    84,   320,   344,   345,    -1,
      -1,   256,   269,    32,   153,   351,   350,   353,   160,    -1,
      -1,   146,   352,    -1,    18,    -1,    74,    -1,    77,    -1,
      93,    -1,    47,    -1,    89,    -1,    52,    -1,    90,    -1,
     128,   354,   123,    -1,   128,   355,   133,   123,    -1,   128,
       1,   123,    -1,    -1,   355,    -1,   356,    -1,   355,   133,
     356,    -1,   256,   153,    -1,   256,   153,   129,   203,    -1,
     256,   269,    28,   166,   153,   274,   134,   296,   135,   127,
      -1,   219,    -1,   134,   296,   135,   219,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   990,   990,   996,  1005,  1016,  1035,  1036,  1040,  1041,
    1042,  1092,  1093,  1097,  1098,  1120,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1140,  1141,  1147,  1148,  1151,  1170,
    1170,  1255,  1256,  1264,  1266,  1270,  1274,  1293,  1311,  1313,
    1317,  1318,  1322,  1323,  1324,  1325,  1326,  1327,  1335,  1336,
    1337,  1340,  1343,  1346,  1352,  1353,  1356,  1359,  1362,  1367,
    1370,  1376,  1377,  1386,  1389,  1393,  1397,  1403,  1404,  1408,
    1412,  1419,  1420,  1424,  1425,  1429,  1430,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1464,  1465,  1466,  1467,  1468,  1469,
    1470,  1473,  1483,  1487,  1488,  1489,  1490,  1491,  1492,  1493,
    1494,  1497,  1500,  1501,  1510,  1511,  1512,  1515,  1518,  1524,
    1525,  1526,  1527,  1528,  1529,  1532,  1538,  1539,  1540,  1541,
    1569,  1579,  1582,  1585,  1591,  1605,  1611,  1612,  1616,  1617,
    1621,  1622,  1623,  1627,  1628,  1632,  1633,  1637,  1641,  1680,
    1681,  1684,  1685,  1694,  1704,  1705,  1706,  1730,  1731,  1732,
    1733,  1737,  1738,  1741,  1744,  1750,  1751,  1754,  1760,  1761,
    1764,  1782,  1783,  1786,  1789,  1792,  1795,  1798,  1801,  1804,
    1810,  1813,  1817,  1821,  1827,  1831,  1840,  1841,  1844,  1850,
    1851,  1857,  1858,  1864,  1865,  1871,  1872,  1878,  1879,  1885,
    1886,  1892,  1895,  1898,  1901,  1904,  1907,  1910,  1913,  1916,
    1919,  1922,  1928,  1929,  1933,  1934,  1945,  1949,  1953,  1954,
    1970,  1971,  1975,  1976,  1980,  1981,  1985,  1989,  1996,  1997,
    2000,  2002,  2010,  2017,  2018,  2019,  2023,  2039,  2040,  2041,
    2042,  2043,  2044,  2045,  2046,  2047,  2048,  2049,  2050,  2051,
    2052,  2053,  2064,  2084,  2089,  2115,  2116,  2123,  2129,  2148,
    2159,  2160,  2164,  2165,  2169,  2185,  2201,  2202,  2203,  2204,
    2205,  2206,  2207,  2211,  2215,  2218,  2224,  2225,  2236,  2237,
    2241,  2245,  2253,  2257,  2262,  2270,  2271,  2275,  2278,  2281,
    2285,  2293,  2294,  2295,  2306,  2307,  2311,  2312,  2313,  2324,
    2325,  2326,  2337,  2338,  2349,  2350,  2356,  2357,  2358,  2362,
    2363,  2364,  2365,  2366,  2367,  2371,  2372,  2373,  2377,  2384,
    2399,  2400,  2404,  2408,  2415,  2421,  2426,  2431,  2436,  2449,
    2450,  2454,  2460,  2464,  2470,  2477,  2480,  2483,  2495,  2501,
    2505,  2512,  2532,  2536,  2547,  2548,  2552,  2556,  2563,  2573,
    2576,  2579,  2580,  2590,  2594,  2598,  2605,  2609,  2616,  2619,
    2625,  2626,  2629,  2632,  2638,  2642,  2649,  2653,  2657,  2664,
    2670,  2678,  2679,  2683,  2684,  2696,  2697,  2698,  2699,  2700,
    2701,  2702,  2703,  2704,  2705,  2706,  2707,  2708,  2709,  2718,
    2717,  2782,  2783,  2784,  2788,  2792,  2816,  2818,  2822,  2823,
    2827,  2828,  2832,  2832,  2872,  2873,  2877,  2878,  2882,  2883,
    2894,  2895,  2899,  2903,  2910,  2911,  2912,  2913,  2914,  2915,
    2916,  2917,  2918,  2919,  2923,  2924,  2935,  2942,  2946,  2953,
    2963,  2970,  2974,  2982,  2985,  2995,  3011,  3012,  3016,  3017,
    3021,  3025,  3032,  3035,  3041,  3042,  3043,  3044,  3052,  3070,
    3074,  3077,  3088,  3092,  3099,  3100,  3104,  3114,  3115,  3119,
    3129,  3130,  3138,  3139,  3143,  3151,  3155,  3163,  3167,  3174,
    3188,  3191,  3202,  3206,  3213,  3223,  3237,  3255,  3260,  3268,
    3269,  3279,  3283,  3290,  3293,  3303,  3304,  3308,  3337,  3374,
    3375,  3376,  3377,  3378,  3379,  3380,  3381,  3382,  3383,  3384,
    3385,  3386,  3387,  3388,  3389,  3390,  3391,  3392,  3393,  3394,
    3395,  3399,  3422,  3452,  3525,  3531,  3537,  3543,  3599,  3598,
    3651,  3652,  3656,  3657,  3673,  3672,  3715,  3716,  3720,  3721,
    3732,  3733,  3737,  3741,  3748,  3749,  3750,  3751,  3755,  3769,
    3770,  3774,  3793,  3797,  3800,  3811,  3812,  3813,  3814,  3818,
    3834,  3859,  3859,  3926,  3927,  3931,  3932,  3933,  3934,  3935,
    3936,  3937,  3938,  3942,  3945,  3948,  3958,  3959,  3963,  3967,
    3974,  3977,  3987,  4029,  4033
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"an integer value\"",
  "\"a character constant\"", "\"an identifier\"", "\"a string literal\"",
  "\"a floating point value\"", "\"a decimal value\"",
  "\"a documentation comment\"", "\"`abstract'\"", "\"`add'\"",
  "\"`__arglist'\"", "\"`as'\"", "\"`base'\"", "\"`bool'\"", "\"`break'\"",
  "\"`__builtin_constant'\"", "\"`byte'\"", "\"`case'\"", "\"`catch'\"",
  "\"`char'\"", "\"`checked'\"", "\"`class'\"", "\"`const'\"",
  "\"`continue'\"", "\"`decimal'\"", "\"`default'\"", "\"`delegate'\"",
  "\"`do'\"", "\"`double'\"", "\"`else'\"", "\"`enum'\"", "\"`event'\"",
  "\"`explicit'\"", "\"`extern'\"", "\"`false'\"", "\"`finally'\"",
  "\"`fixed'\"", "\"`float'\"", "\"`for'\"", "\"`foreach'\"", "\"`get'\"",
  "\"`goto'\"", "\"`if'\"", "\"`implicit'\"", "\"`in'\"", "\"`int'\"",
  "\"`interface'\"", "\"`internal'\"", "\"`is'\"", "\"`lock'\"",
  "\"`long'\"", "\"`__long_double'\"", "\"`__makeref'\"", "\"`__module'\"",
  "\"`namespace'\"", "\"`new'\"", "\"`null'\"", "\"`object'\"",
  "\"`operator'\"", "\"`out'\"", "\"`override'\"", "\"`params'\"",
  "\"`partial'\"", "\"`private'\"", "\"`protected'\"", "\"`public'\"",
  "\"`readonly'\"", "\"`remove'\"", "\"`ref'\"", "\"`__reftype'\"",
  "\"`__refvalue'\"", "\"`return'\"", "\"`sbyte'\"", "\"`sealed'\"",
  "\"`set'\"", "\"`short'\"", "\"`sizeof'\"", "\"`stackalloc'\"",
  "\"`static'\"", "\"`string'\"", "\"`struct'\"", "\"`switch'\"",
  "\"`this'\"", "\"`throw'\"", "\"`true'\"", "\"`try'\"", "\"`typeof'\"",
  "\"`uint'\"", "\"`ulong'\"", "\"`unchecked'\"", "\"`unsafe'\"",
  "\"`ushort'\"", "\"`using'\"", "\"`virtual'\"", "\"`void'\"",
  "\"`volatile'\"", "\"`where'\"", "\"`while'\"", "\"`yield'\"",
  "\"`++'\"", "\"`--'\"", "\"`<<'\"", "\"`>>'\"", "\"`<='\"", "\"`>='\"",
  "\"`=='\"", "\"`!='\"", "\"`&&'\"", "\"`||'\"", "\"`*='\"", "\"`/='\"",
  "\"`%='\"", "\"`+='\"", "\"`-='\"", "\"`<<='\"", "\"`>>='\"", "\"`&='\"",
  "\"`^='\"", "\"`|='\"", "\"`->'\"", "\"`<'\"", "'}'", "'.'", "'<'",
  "'>'", "';'", "'{'", "'='", "'['", "']'", "'*'", "','", "'('", "')'",
  "'!'", "'~'", "'+'", "'-'", "'&'", "'/'", "'%'", "'^'", "'|'", "'?'",
  "':'", "$accept", "CompilationUnit", "OuterDeclarations",
  "OuterDeclaration", "OuterDeclarationsRecoverable",
  "OuterDeclarationRecoverable", "Identifier", "IDENTIFIER",
  "QualifiedIdentifier", "QualifiedIdentifierPart", "NamespaceDeclaration",
  "@1", "NamespaceIdentifier", "OptSemiColon", "NamespaceBody",
  "UsingDirective", "OptNamespaceMemberDeclarations",
  "NamespaceMemberDeclaration", "TypeDeclaration", "Type",
  "NonExpressionType", "TypeActuals", "LocalVariableType", "TypeSuffixes",
  "TypeSuffixList", "TypeSuffix", "DimensionSeparators",
  "DimensionSeparatorList", "BuiltinType", "PrimaryExpression",
  "LiteralExpression", "InvocationExpression", "ObjectCreationExpression",
  "OptArgumentList", "ArgumentList", "Argument", "ExpressionList",
  "RankSpecifiers", "RankSpecifierList", "UnaryExpression",
  "PrefixedUnaryExpression", "MultiplicativeExpression",
  "AdditiveExpression", "ShiftExpression", "RelationalExpression",
  "GenericReference", "EqualityExpression", "AndExpression",
  "XorExpression", "OrExpression", "LogicalAndExpression",
  "LogicalOrExpression", "ConditionalExpression", "AssignmentExpression",
  "Expression", "ParenExpression", "ConstantExpression",
  "BooleanExpression", "ParenBooleanExpression", "OptArrayInitializer",
  "ArrayInitializer", "OptVariableInitializerList",
  "VariableInitializerList", "VariableInitializer", "OptComma",
  "Statement", "EmbeddedStatement", "InnerEmbeddedStatement",
  "LocalVariableDeclaration", "VariableDeclarators", "VariableDeclarator",
  "LocalConstantDeclaration", "Block", "OptStatementList", "StatementList",
  "LineStatement", "ExpressionStatement", "InnerExpressionStatement",
  "SelectionStatement", "SwitchBlock", "OptSwitchSections",
  "SwitchSections", "SwitchSection", "SwitchLabels", "SwitchLabel",
  "IterationStatement", "ForInitializer", "ForInitializerInner",
  "ForCondition", "ForIterator", "ForeachExpression",
  "ExpressionStatementList", "JumpStatement", "TryStatement",
  "CatchClauses", "OptSpecificCatchClauses", "SpecificCatchClauses",
  "SpecificCatchClause", "CatchNameInfo", "OptGeneralCatchClause",
  "GeneralCatchClause", "FinallyClause", "LockStatement", "UsingStatement",
  "ResourceAcquisition", "FixedStatement", "FixedPointerDeclarators",
  "FixedPointerDeclarator", "YieldStatement", "OptAttributes",
  "NonOptAttributes", "AttributeSections", "AttributeSection",
  "AttributeTarget", "AttributeList", "Attribute", "AttributeArguments",
  "PositionalArgumentList", "PositionalArgument", "NamedArgumentList",
  "NamedArgument", "AttributeArgumentExpression", "OptModifiers",
  "Modifiers", "Modifier", "ClassDeclaration", "@2", "TypeFormals",
  "TypeFormalList", "Constraints", "ConstraintList", "Constraint",
  "ModuleDeclaration", "@3", "ClassBase", "TypeList", "ClassBody",
  "OptClassMemberDeclarations", "ClassMemberDeclarations",
  "ClassMemberDeclaration", "OptPartial", "ConstantDeclaration",
  "ConstantDeclarators", "ConstantDeclarator", "FieldDeclaration",
  "FieldDeclarators", "FieldDeclarator", "MethodDeclaration", "MethodBody",
  "OptFormalParameterList", "FormalParameterList", "FormalParameter",
  "ParameterModifier", "PropertyDeclaration", "StartAccessorBlock",
  "AccessorBlock", "AccessorDeclarations", "OptGetAccessorDeclaration",
  "GetAccessorDeclaration", "OptSetAccessorDeclaration",
  "SetAccessorDeclaration", "AccessorBody", "EventDeclaration",
  "EventFieldDeclaration", "EventDeclarators", "EventDeclarator",
  "EventPropertyDeclaration", "EventAccessorBlock",
  "EventAccessorDeclarations", "AddAccessorDeclaration",
  "RemoveAccessorDeclaration", "IndexerDeclaration", "IndexerDeclarator",
  "FormalIndexParameters", "FormalIndexParameterList",
  "FormalIndexParameter", "OperatorDeclaration",
  "NormalOperatorDeclaration", "OverloadableOperator",
  "ConversionOperatorDeclaration", "ConstructorDeclaration",
  "ConstructorInitializer", "DestructorDeclaration", "StructDeclaration",
  "@4", "StructInterfaces", "StructBody", "InterfaceDeclaration", "@5",
  "InterfaceBase", "InterfaceBody", "OptInterfaceMemberDeclarations",
  "InterfaceMemberDeclarations", "InterfaceMemberDeclaration",
  "InterfaceMethodDeclaration", "OptNew", "InterfacePropertyDeclaration",
  "StartInterfaceAccessorBody", "InterfaceAccessorBody",
  "InterfaceAccessors", "InterfaceEventDeclaration",
  "InterfaceIndexerDeclaration", "EnumDeclaration", "@6", "EnumBase",
  "EnumBaseType", "EnumBody", "OptEnumMemberDeclarations",
  "EnumMemberDeclarations", "EnumMemberDeclaration", "DelegateDeclaration",
  "AnonymousMethod", 0
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   125,    46,    60,    62,    59,   123,    61,
      91,    93,    42,    44,    40,    41,    33,   126,    43,    45,
      38,    47,    37,    94,   124,    63,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   147,   148,   148,   148,   148,   149,   149,   150,   150,
     150,   151,   151,   152,   152,   153,   154,   154,   154,   154,
     154,   154,   154,   154,   155,   155,   156,   156,   156,   158,
     157,   159,   159,   160,   160,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   165,   165,   165,   165,   166,   166,
     166,   166,   166,   166,   167,   167,   167,   167,   167,   167,
     167,   168,   168,   169,   169,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   177,   177,   177,   177,
     177,   177,   177,   177,   178,   179,   180,   180,   181,   181,
     182,   182,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   186,   186,   186,   187,   187,   187,   187,   187,   187,
     187,   188,   188,   188,   188,   189,   189,   189,   190,   190,
     190,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     192,   192,   192,   192,   192,   192,   193,   193,   193,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   198,   199,
     199,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   201,   201,   202,   202,   203,   204,   205,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   210,   210,
     211,   211,   212,   212,   212,   212,   213,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   215,   216,   216,   217,   217,   218,   219,   219,
     220,   220,   221,   221,   222,   223,   224,   224,   224,   224,
     224,   224,   224,   225,   225,   225,   226,   226,   227,   227,
     228,   228,   229,   230,   230,   231,   231,   232,   232,   232,
     232,   233,   233,   233,   234,   234,   235,   235,   235,   236,
     236,   236,   237,   237,   238,   238,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   240,   240,   240,   241,   241,
     242,   242,   243,   243,   244,   245,   245,   245,   245,   246,
     246,   247,   248,   249,   250,   251,   251,   251,   252,   253,
     253,   254,   255,   255,   256,   256,   257,   258,   258,   259,
     259,   259,   259,   260,   260,   260,   261,   261,   262,   262,
     263,   263,   263,   263,   264,   264,   265,   266,   266,   267,
     268,   269,   269,   270,   270,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   273,
     272,   274,   274,   274,   275,   275,   276,   276,   277,   277,
     278,   278,   280,   279,   281,   281,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   287,   287,   288,   289,   289,   290,
     291,   292,   292,   293,   293,   294,   295,   295,   296,   296,
     297,   297,   298,   298,   299,   299,   299,   299,   300,   301,
     302,   302,   303,   303,   304,   304,   305,   306,   306,   307,
     308,   308,   309,   309,   310,   311,   311,   312,   312,   313,
     314,   314,   315,   315,   316,   317,   318,   319,   319,   320,
     320,   321,   321,   322,   322,   323,   323,   324,   324,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   326,   326,   327,   328,   328,   328,   329,   331,   330,
     332,   332,   333,   333,   335,   334,   336,   336,   337,   337,
     338,   338,   339,   339,   340,   340,   340,   340,   341,   342,
     342,   343,   344,   345,   345,   346,   346,   346,   346,   347,
     348,   350,   349,   351,   351,   352,   352,   352,   352,   352,
     352,   352,   352,   353,   353,   353,   354,   354,   355,   355,
     356,   356,   357,   358,   358
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     4,     0,
       6,     1,     3,     0,     1,     3,     5,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     4,     4,     1,     4,     2,     2,     2,     4,
       4,     1,     3,     2,     5,     5,     2,     0,     1,     1,
       2,     3,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       4,     3,     4,     1,     1,     3,     4,     2,     2,     1,
       7,     3,     4,     4,     4,     4,     3,     5,     4,     4,
       4,     6,     1,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     0,     1,     1,     3,
       1,     2,     2,     1,     3,     0,     1,     3,     4,     1,
       2,     2,     4,     4,     1,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     4,
       4,     5,     6,     7,     5,     7,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     1,     1,     3,     3,
       0,     1,     3,     4,     0,     1,     1,     3,     1,     1,
       0,     1,     3,     2,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     2,
       1,     2,     2,     1,     3,     1,     3,     3,     3,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     5,     3,     3,     3,     0,     1,
       1,     2,     2,     1,     2,     3,     2,     3,     5,     6,
       7,     2,     1,     2,     1,     1,     2,     1,     2,     2,
       1,     2,     2,     2,     1,     3,     2,     2,     3,     4,
       3,     2,     3,     2,     3,     3,     3,     4,     2,     2,
       0,     1,     1,     2,     3,     0,     4,     3,     3,     0,
       1,     2,     2,     3,     3,     4,     3,     3,     6,     1,
       3,     3,     4,     3,     0,     1,     1,     1,     2,     4,
       5,     1,     3,     2,     2,     2,     1,     3,     1,     2,
       2,     3,     5,     3,     1,     3,     1,     1,     3,     3,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
      11,     0,     3,     3,     1,     3,     0,     2,     1,     3,
       3,     5,     0,     4,     0,     2,     1,     3,     3,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     6,     1,     3,     3,
       5,     1,     3,     1,     3,     8,     1,     1,     0,     1,
       1,     3,     4,     1,     0,     1,     1,     1,     6,     1,
       2,     2,     2,     2,     0,     1,     3,     0,     1,     3,
       1,     1,     1,     1,     6,     1,     3,     1,     3,     7,
       2,     2,     2,     2,     3,     3,     5,     3,     5,     3,
       3,     1,     3,     4,     1,     1,     1,    11,    14,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    11,    11,     8,     0,     5,     5,     7,     0,    11,
       0,     2,     3,     3,     0,    11,     0,     2,     3,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     8,     0,
       1,     6,     1,     2,     2,     2,     2,     4,     4,     6,
       7,     0,     8,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     0,     1,     1,     3,
       2,     4,    10,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    10,   351,   402,     0,    14,     0,     0,    13,     0,
      11,    40,     8,     9,    41,   371,     5,   345,   347,    42,
      43,    44,    45,    46,    47,     0,    16,    19,    17,    22,
      20,    18,    21,    23,    31,     0,     0,     0,     0,    26,
      15,   358,    24,     0,   230,   356,     1,    12,     4,   380,
     386,   378,     0,   375,   385,   379,   377,   376,   383,   381,
     382,   387,   384,   388,   424,   372,   373,   348,     0,    33,
       0,     0,    37,   352,   354,   355,     0,     0,     0,     0,
     353,   359,   358,   230,   231,     0,    31,    29,     0,     0,
     425,     0,   374,     0,   423,   371,   345,     0,   344,   412,
     414,   415,   416,   417,   418,   462,   463,   419,   420,   485,
     486,   421,   422,    34,   403,     0,    32,    78,    80,    87,
      91,    89,    88,    83,    85,    90,    92,    79,    81,    93,
      84,    86,    82,    77,    48,    61,     0,    49,     0,    25,
     129,   132,   133,   130,   131,   103,     0,     0,     0,     0,
     127,     0,   122,     0,   128,     0,     0,     0,     0,   104,
     126,     0,     0,     0,     0,     0,     0,   360,     0,     0,
       0,     0,     0,    95,     0,   149,    94,    99,   109,   154,
     161,   165,   168,   171,   186,   178,   189,   191,   193,   195,
     197,   199,   212,   213,   370,     0,   364,     0,   367,   366,
       0,   357,   349,     0,     0,   553,     0,     0,     0,   409,
     424,   408,   413,    36,     0,     0,    73,    51,    28,     0,
      27,     0,     0,     0,     0,     0,   344,   573,   123,     0,
       0,     0,     0,     0,     0,     0,     0,    95,   157,   158,
     159,     0,    54,   165,     0,   150,   151,   155,   156,   160,
       0,     0,   107,   108,     0,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,     0,   363,   350,     0,    33,   391,
       0,   551,   391,   391,   391,     0,     0,     0,     0,    22,
       0,    24,     0,     0,     0,     0,    75,     0,    74,    62,
     105,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,   238,    95,
       0,    67,   149,    99,   109,     0,   268,   264,   235,     0,
       0,   237,     0,     0,   262,     0,   240,   241,   242,   243,
     246,   247,   248,   250,   443,   444,     0,   439,   440,     0,
     224,    73,   136,   111,     0,     0,     0,    73,     0,     0,
       0,     0,    73,    56,     0,    58,    57,    96,   369,   125,
      98,   116,   124,    97,   101,     0,     0,     0,     0,     0,
     137,   138,   140,   204,   205,   206,   202,   203,   210,   211,
     207,   209,   208,   201,   162,   163,   164,   161,   166,   167,
     169,   170,   177,   176,   174,   175,    67,     0,   172,   173,
       0,   187,   188,   190,   192,   194,   196,   198,     0,   365,
       0,     0,   368,     0,     6,     0,    30,     0,     0,     0,
     555,   559,   561,   556,   557,   560,   562,   558,   554,     0,
     404,   526,   520,     0,     0,   391,   391,     0,   344,     0,
       0,    26,     0,     0,   431,   449,     0,    53,    52,    50,
      76,   106,     0,   118,   114,   259,   251,   306,   244,     0,
     307,     0,   149,     0,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   311,     0,     0,   313,     0,
       0,   245,   249,     0,     0,     0,     0,     0,   157,   158,
       0,   255,   252,   253,    73,    72,    66,    68,    69,   107,
     108,     0,     0,     0,    63,   233,   234,   258,   263,   239,
     446,   447,   445,     0,     0,   344,   119,   228,   229,     0,
     225,   226,     0,     0,   120,     0,   113,     0,   112,   115,
       0,     0,     0,   153,   152,   102,   100,   141,   142,   134,
       0,     0,   180,     0,     0,   179,     0,   362,     7,    35,
     394,     0,     0,   344,     0,    33,     0,   396,     0,   396,
       0,   396,     0,     0,   427,    26,     0,     0,   465,     0,
       0,     0,     0,   496,   495,   493,   494,   503,   504,   510,
     509,   505,   506,   508,   507,   497,   491,   492,   489,   490,
     500,   498,   499,   502,   501,   391,     0,   477,     0,     0,
     344,     0,   430,     0,     0,     0,   476,     0,   344,   344,
     144,   257,     0,     0,     0,   292,   294,   304,   265,     0,
       0,   295,     0,   216,     0,   310,   308,     0,   217,     0,
     273,     0,     0,   333,   312,     0,   275,   314,   325,     0,
     315,     0,   329,   322,   316,     0,     0,   149,     0,   334,
     287,   343,     0,   232,     0,     0,     0,    70,     0,     0,
       0,     0,   574,   441,   222,     0,   145,   135,     0,   117,
      60,    59,    55,   139,   184,     0,     0,   181,     0,   200,
     393,     0,   392,     0,     0,     0,     0,   567,   568,   552,
     406,   405,     0,   389,   527,   524,   521,   518,     0,   426,
       0,     0,     0,   464,     0,     0,     0,     0,   514,     0,
       0,   484,   444,     0,   481,   434,     0,     0,   448,   433,
     432,   451,     0,     0,   450,     0,   452,   458,     0,   453,
     455,     0,     0,     0,   339,   293,     0,   297,     0,     0,
     291,     0,     0,   309,   219,   218,     0,   215,   214,     0,
       0,     0,     0,   279,   280,     0,   283,     0,     0,   332,
     317,     0,   319,     0,   323,   318,   330,   337,     0,   336,
     342,   256,   254,    71,    67,    67,   442,   223,   227,    73,
     220,   146,   121,     0,   182,     0,   395,     0,   565,   570,
     563,   344,     0,     0,   397,   398,     0,     0,     0,   429,
     428,   468,     0,     0,   469,     0,   344,   344,   467,   466,
       0,     0,   517,     0,     0,     0,   480,     0,   479,   344,
     478,     0,   461,   460,   456,   459,   288,     0,     0,     0,
     298,   296,     0,   300,     0,     0,   305,     0,   274,   277,
       0,   286,   276,   281,     0,   284,     0,     0,   324,   331,
     335,    65,    64,     0,   110,   221,    73,   185,   183,   572,
       0,   564,   569,   407,     0,     0,    33,     0,    33,     0,
      33,   471,     0,     0,   470,     0,   472,     0,   473,     0,
       0,     0,     0,   437,   436,   513,     0,     0,   482,   435,
     341,   340,   338,   301,   289,   299,     0,     0,     0,   285,
     328,   327,     0,   147,     0,   571,     0,   400,   399,   390,
       0,   539,     0,   344,   532,   534,   535,   536,   537,   525,
       0,     0,   519,   474,   475,     0,     0,   136,   136,     0,
     483,   303,   302,   290,   326,   148,     0,   529,   540,     0,
     528,   533,   523,   522,     0,     0,     0,     0,     0,     0,
     401,     0,     0,   512,   511,   515,   516,     0,   487,     0,
       0,     0,     0,     0,     0,   542,   344,     0,     0,   549,
       0,     0,     0,     0,     0,   541,     0,   488,   550,     0,
     544,   545,   546,   543,   538,     0,     0,   547,   548
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,   453,     8,     9,    10,   237,    40,   134,    42,
      11,   203,    35,   114,   298,    12,   455,    13,    14,   135,
     241,   136,   350,   544,   537,   538,   317,   318,   174,   175,
     176,   177,   178,   409,   410,   411,   406,   820,   821,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   412,   514,   664,   669,   512,   894,
     558,   559,   560,   561,    85,   357,   503,   504,   359,   532,
     533,   360,   361,   362,   363,   364,   657,   365,   366,   676,
     792,   793,   794,   795,   796,   367,   659,   660,   779,   874,
     938,   661,   368,   369,   680,   681,   682,   683,   798,   805,
     802,   684,   370,   371,   524,   372,   773,   774,   373,   375,
      16,    96,    18,    43,    44,    45,    81,   195,   196,   197,
     198,   199,    64,    65,    66,    19,   836,   459,   591,   733,
     834,   835,    20,    25,   597,   731,    69,    97,    98,    99,
      91,   100,   603,   604,   101,   483,   484,   102,   925,   376,
     377,   378,   553,   103,   486,   646,   647,   769,   648,   766,
     649,   864,   104,   105,   607,   608,   106,   844,   845,   846,
     847,   107,   313,   637,   753,   754,   108,   109,   635,   110,
     111,   854,   112,    21,   838,   601,   910,    22,   837,   599,
     908,   952,   953,   954,   955,   979,   956,  1007,  1015,  1016,
     957,   958,    23,   469,   301,   468,   595,   726,   727,   728,
      24,   228
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -744
static const yytype_int16 yypact[] =
{
    1131,  -744,  -744,  -744,   827,  -744,   411,    87,  -744,  4716,
    -744,  -744,  -744,  -744,  -744,  1077,  -744,    30,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   -22,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,    -4,   -38,    11,    12,    65,   131,
    -744,    -5,  -744,   827,   118,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,   827,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,    28,  5093,  -744,  -744,  1490,    23,
     827,   827,  -744,  -744,  -744,  -744,  5438,  5438,   827,  3563,
    -744,  -744,    -2,   118,   827,    93,  -744,   112,  5438,   827,
    -744,    75,  -744,   170,  -744,  5093,    37,   201,    59,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   244,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,   143,   318,    90,  -744,   208,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,    13,   150,   178,   153,
    -744,   195,  -744,  5438,  -744,   221,   252,   256,  5438,  -744,
    -744,   261,   272,  4220,  4220,  4220,  4220,  -744,  4220,  4220,
    4220,  4220,  4220,   316,   383,   145,  -744,  -744,  -744,  -744,
     947,     4,   200,   310,   227,   376,   325,   378,   389,   404,
     461,   -44,  -744,  -744,  -744,   331,  -744,   356,  -744,  -744,
     430,  -744,  -744,   438,   305,   455,   827,   827,   827,  -744,
    4660,  -744,  -744,  -744,  5438,  5438,   464,  -744,  -744,  5438,
    -744,   827,  4220,   602,  4220,  1922,    24,  -744,  -744,  4220,
     183,  4220,  4220,  5438,   498,  5438,  4220,  -744,  -744,  -744,
    -744,   205,   383,   123,   283,  -744,  -744,  -744,  -744,  -744,
    4220,   608,  -744,  -744,   827,   627,  3182,  3320,  4220,  4220,
    4220,  4220,  4220,  4220,  4220,  4220,  4220,  4220,  4220,  4220,
    4220,  4220,  4220,  4220,  4220,  4220,  5438,  5438,  4220,  4220,
    4220,  4220,  4220,  3320,  4220,  4220,  4220,  4220,  4220,  4220,
    4220,  4220,  4220,  -744,   827,  -744,  -744,  4966,    23,   306,
     453,  -744,   306,   306,   306,  5438,  5438,   592,   599,   125,
     827,   528,  1180,   539,   225,   237,  -744,   537,   538,   318,
    -744,   440,  -744,   540,   543,   111,   552,   248,  5438,   555,
    2342,   549,   553,   554,   512,   559,   563,  3701,   563,  3839,
     573,   313,   573,   577,   559,    61,  4220,  4220,  -744,   571,
     827,   144,  1372,   229,   330,   947,  -744,  -744,  -744,   580,
     596,  -744,   609,  2062,  -744,   610,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   189,   601,   607,  -744,   606,
    3977,  4082,  3320,  -744,   611,   616,   304,  4082,   324,   618,
    5438,  5438,   464,  -744,  4220,  4220,  -744,  4564,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   452,   476,  4220,  4220,   619,
     623,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,     4,     4,
     200,   200,   318,   318,   310,   310,   144,   193,   310,   310,
     625,   227,   227,   325,   378,   389,   404,   461,   597,  -744,
     516,   316,  -744,  5042,  -744,   621,  -744,   827,   827,   617,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,   614,
     615,   622,   624,   305,   305,   306,   306,   638,    24,  5117,
     645,   250,    86,   395,  -744,  -744,    54,  -744,  -744,  -744,
    -744,  -744,  4220,  -744,  -744,  -744,  -744,  -744,  -744,   305,
    -744,   649,   161,   678,  -744,  5438,  1317,  5438,  4220,   651,
     653,  2762,  2342,  2867,  2342,  -744,   654,   655,  -744,   657,
      47,  -744,  -744,  2972,  2342,  2342,   658,  4220,   355,   359,
    2202,   659,   660,  -744,   464,  -744,  -744,    55,  -744,   371,
     386,  5438,  5438,  3182,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  5438,   573,    42,  -744,  -744,  -744,   663,
     662,  -744,   524,   647,  -744,  5438,  -744,   661,  -744,  -744,
     254,   291,   665,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    3320,   346,  -744,  5438,   278,  -744,  4220,  -744,  -744,  -744,
    -744,   369,   407,    24,    33,    23,  5438,   692,  5438,   692,
    5438,   692,   668,   425,  -744,   473,   174,   451,  -744,  5438,
    5438,   664,   666,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   306,  4811,  -744,  3977,   789,
      24,    54,  -744,   827,   679,    62,  -744,   680,    38,    82,
    -744,   671,   559,   305,   681,  -744,  -744,  -744,  -744,  2482,
     682,   674,   305,  -744,   684,  -744,  -744,   683,  -744,   686,
     784,   687,   688,  -744,  -744,    80,  -744,  -744,   690,   573,
     779,   797,   805,  -744,  -744,   693,   827,  5076,   694,  -744,
    -744,  -744,   700,  -744,  3977,   827,   699,  -744,   408,   423,
     452,   305,  -744,  -744,  -744,  3425,   704,  -744,   504,  -744,
    -744,  -744,  -744,  -744,  -744,  5438,   424,  -744,  5438,  -744,
    -744,   827,  -744,   701,   712,   827,   714,   707,  -744,  -744,
     318,   708,   827,  -744,   708,  -744,   708,  -744,  4220,  -744,
     827,  3977,    48,  -744,   827,   266,   457,   573,   696,   709,
     716,  -744,   189,   561,  -744,  -744,   645,   715,  -744,   723,
    -744,  -744,   349,   349,  -744,   778,  -744,  -744,   813,  -744,
    -744,   729,   728,   565,  -744,  -744,   733,  -744,   734,  2622,
    -744,  4325,   820,  -744,  -744,  -744,  2342,  -744,  -744,   744,
    4220,   722,   747,    91,  -744,  1782,  -744,  5261,   573,  -744,
    -744,   573,  -744,   471,  -744,  -744,  -744,  -744,   581,  -744,
    -744,  -744,  -744,  -744,    55,    55,  -744,  -744,  -744,   464,
     743,   742,  -744,   434,  -744,   436,  -744,   748,  -744,   745,
    -744,   103,  5438,   731,   746,  -744,   -22,   752,   754,  -744,
    -744,  -744,   760,    34,  -744,   761,    37,    37,   759,  -744,
    5438,  5438,  -744,    27,   447,  5438,  -744,  5438,  -744,    53,
    -744,   447,  -744,  -744,  -744,  -744,  -744,  4220,   827,  2342,
    -744,  -744,   757,  -744,  2342,   589,  -744,  3077,  -744,  -744,
     751,  -744,  -744,  -744,  1642,  -744,   758,   267,  -744,  -744,
    -744,  -744,  -744,   763,  -744,  -744,   464,  -744,  -744,  -744,
    4220,  -744,  -744,   318,  5313,   827,    23,  4897,    23,  4465,
      23,  -744,   349,   349,  -744,   831,  -744,   890,  -744,   305,
     305,   768,   771,  -744,  -744,  -744,   305,   305,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,   773,   775,  2342,  -744,
    -744,  -744,   776,  -744,   781,  -744,   782,   318,  -744,  -744,
     792,   860,   795,   107,  -744,  -744,  -744,  -744,  -744,  -744,
     796,   799,  -744,  -744,  -744,   788,   793,  3320,  3320,   595,
    -744,  -744,  -744,  -744,  -744,  -744,   794,  -744,  -744,  5386,
    -744,  -744,  -744,  -744,   573,   573,   798,   807,  5438,   573,
    -744,  5438,  5115,  -744,  -744,  -744,  -744,   305,  -744,   305,
     645,   493,   809,   818,   812,  -744,    24,    52,   573,  -744,
      52,   815,   825,   824,   826,  -744,   829,  -744,  -744,   828,
    -744,   878,   914,  -744,  -744,   830,   834,  -744,  -744
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -744,  -744,  -744,  -272,  -744,   949,    -6,   202,     9,   -71,
    -744,  -744,   911,  -292,  -744,  -744,  -744,  -744,   -63,   -84,
    -744,     3,   443,  -341,   530,  -479,  -381,  -242,   -45,  -164,
    -744,  -105,   233,  -282,  -744,   388,  -202,  -744,  -744,   578,
     767,   -76,   350,   362,   361,  -744,   691,   697,   695,   685,
     689,  -744,  -744,   435,   740,   640,  -714,   321,  -332,  -744,
    -227,  -744,  -744,  -550,   898,  -744,  -496,  -223,   481,   302,
     294,  -744,   -99,  -744,   199,  -355,   214,  -487,  -744,  -744,
    -744,  -744,   204,  -744,   215,  -744,  -744,  -744,  -744,  -744,
    -744,   230,  -744,  -744,  -744,  -744,  -744,   329,  -744,  -744,
     333,   336,  -744,  -744,  -744,  -744,  -744,   149,  -744,    17,
    1004,   280,    31,  -744,   975,   936,  -744,  -744,   730,   732,
     727,   777,   928,  -744,   960,  -744,  -744,  -281,   568,   130,
    -744,   124,  -744,  -744,  -744,   135,   194,   126,  -744,   935,
    -744,  -744,   535,   303,  -744,  -744,   401,  -744,   207,  -469,
    -744,   495,   317,  -744,  -442,   429,  -744,  -744,   422,  -744,
     426,  -736,  -744,  -744,  -744,   328,  -744,  -744,  -744,   226,
     232,  -744,  -744,  -743,  -744,   216,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,   127,  -744,  -744,  -744,    77,    72,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,   253,
    -744,  -744
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -567
static const yytype_int16 yytable[] =
{
      39,   440,   358,   383,   204,    94,   456,   139,   548,   612,
     536,   572,   525,   860,   405,    41,   670,    15,   673,   658,
     321,   470,   471,   472,   839,   454,    15,   865,   689,   690,
    -346,   137,   137,     2,   724,    94,   374,    39,  -344,     2,
     641,   921,     2,   137,  -344,   912,     2,     2,    67,   842,
     227,     2,    82,  1012,   374,   644,    88,     2,   697,  -344,
      89,   352,     2,     2,    39,   751,   290,   678,     2,   230,
      39,    39,    39,   173,   234,  -344,   880,   526,    39,   115,
     138,   789,    39,   205,   679,    95,    71,    46,   755,    72,
     243,     2,    90,    82,  1013,   581,  -344,  -344,   206,   790,
     563,   291,  -344,   913,   762,   697,    68,   791,   137,  -344,
     790,   922,     2,   137,     3,    95,     2,  -344,   791,    78,
     353,   242,    78,   207,   723,    70,   312,    67,  1014,    79,
    -344,  -344,    79,  -344,   527,   319,   269,   221,   763,   311,
     358,    80,    73,   222,   811,   270,   271,    39,  -425,   386,
     113,   388,    39,   696,     6,   818,  -566,   208,    74,  -438,
       6,  -457,   696,     6,   742,   137,   502,     6,     6,   137,
     137,   757,     6,  -425,   137,   693,   963,   964,     6,   562,
     351,   588,  -411,     6,     6,   534,   945,   535,   137,     6,
     137,   841,   432,   433,   609,   610,   428,   429,   299,   352,
     302,   303,   304,  -278,    39,  -454,    34,  -425,    39,    39,
     639,    75,     6,    39,   485,   320,   218,   314,   315,   349,
     640,   473,   474,   219,   202,   353,   901,    39,   498,    39,
    -531,   137,   137,     6,   495,   436,    71,     6,   496,   477,
     276,   520,   521,   522,   499,   400,   252,   253,   401,   403,
     550,    84,   551,    76,    86,   395,    77,  1004,   353,   552,
     137,   137,   539,   540,   270,   271,   254,    78,   251,   255,
      39,    39,    26,   116,   534,   256,   535,   277,    27,   257,
      17,   225,   254,   137,   223,   255,   173,   226,   451,    17,
     878,   256,   658,   209,   658,   257,   274,   275,    78,    39,
      39,   700,   485,   729,    39,   214,   481,   358,   215,    28,
      26,   380,   224,   381,    15,   217,    27,   382,   351,   582,
     771,   482,    39,   534,   211,   535,   583,   390,   510,   229,
     391,    29,   278,   279,   220,   392,    30,   393,   272,   273,
     394,   219,   352,    31,   531,   137,   137,    28,   502,   280,
     502,   487,   281,   282,   749,   231,  -266,   349,   219,   687,
     502,   502,  -266,   488,  -266,    32,   352,    33,    78,    29,
     219,   213,    76,   932,    30,    77,   225,  -433,   934,   638,
     710,    31,   224,  -433,    39,    39,   232,   219,   214,   214,
     233,   215,   215,   570,   571,   235,   216,   216,   217,   217,
     850,   353,   941,    32,   717,    33,   236,   353,   534,   353,
     535,   718,    36,   274,   275,   396,    26,   711,   397,   353,
     353,   653,    27,   662,   219,   353,   214,   214,   457,   215,
     215,   458,   284,   285,   216,   216,   217,   217,   893,   566,
     214,   225,   973,   215,    37,   250,   214,   236,   216,   215,
     217,   590,   590,    28,   216,   702,   217,  -267,   354,   568,
     137,   351,   137,  -267,   292,  -267,   293,   602,   605,   701,
      15,   460,   714,   891,   892,    29,   862,   225,   351,   715,
      30,   708,  -271,   606,    38,   351,  -272,    31,  -271,   294,
    -271,   295,  -272,   602,  -272,   720,   137,   137,  -269,    39,
     461,    39,   721,   645,  -269,   462,  -269,   251,   137,    32,
     283,    33,   730,  -270,   730,   944,   730,    26,   286,  -270,
     137,  -270,   642,    27,   349,   745,   746,   463,   643,   548,
     464,   508,   287,   722,   814,    39,    39,  1011,   137,   509,
     721,   219,   465,   466,   698,   699,   467,    39,   288,   815,
     824,   137,   739,   137,    28,   137,   219,   219,   740,    39,
     897,   296,   898,   354,   137,   137,   297,   219,   139,   219,
     289,   491,   358,   492,   923,   225,    29,    39,   743,   214,
     799,    30,   215,   575,   744,   490,   716,   216,    31,   217,
      39,   851,    39,   895,    39,    76,   354,   316,    77,   225,
    -467,   300,   741,    39,    39,   797,  -467,   576,   323,   492,
      32,   725,    33,    26,   949,   502,   959,   502,   962,    27,
     214,  1005,   502,   215,   430,   431,   214,  1006,   387,   215,
     217,   352,    26,    39,   216,   399,   217,   759,    27,   822,
     434,   435,   437,   438,   439,   441,   442,   772,   852,   294,
      28,   587,   475,   752,   402,   706,   782,   492,   645,   476,
     356,   358,   478,   863,   863,   765,   768,   485,   489,    28,
     137,   490,    29,   137,   353,   493,   353,    30,   494,   497,
     531,   353,   500,   505,    31,   986,   987,   506,   507,   531,
     353,    29,   858,   511,   859,   816,    30,   513,   868,   888,
     869,   225,   889,    31,   889,   502,    32,   545,    33,    39,
     502,   523,    39,   887,   695,   826,   890,   530,   823,   829,
     352,   825,   781,   546,   935,    32,   833,    33,   988,   735,
     989,   737,   547,   734,   602,   736,   554,   549,   848,   354,
     555,   556,   594,   586,   589,   354,   564,   354,   903,   565,
     351,   593,   137,   569,   579,   924,   580,   354,   354,   843,
     585,   596,   924,   354,   353,   356,   919,   920,   598,   353,
     600,   926,   611,   927,   502,   636,   496,   652,   665,   353,
     666,   674,   707,   675,   677,   691,   704,   137,   694,   349,
     732,    39,   709,   695,    26,   705,   712,   738,   356,   747,
      27,   748,   761,   764,   740,   137,   137,   781,   775,   780,
     137,   783,   137,   863,   863,   786,   679,   801,   784,   194,
     947,   785,   787,   788,   797,   803,    39,   810,   807,   809,
     813,    28,    26,   353,   819,   828,   827,   830,    27,   351,
     831,   832,   853,   855,    39,    39,    94,   856,   725,    39,
     861,    39,   638,    29,   763,   762,   866,   867,    30,   137,
     870,   871,   772,   915,   917,    31,   877,   879,   881,    28,
     882,   380,   896,   756,   900,   899,   752,   904,   349,   905,
     907,   942,   909,   911,   914,   993,   994,    32,   741,    33,
     998,    29,   933,   940,   943,   992,    30,   939,    39,   833,
     913,   912,   967,    31,   997,   968,   244,   999,   971,  1017,
     972,   974,   975,   965,   966,   977,   976,   978,   980,   982,
     969,   970,   983,   984,   951,    32,    95,    33,   985,   990,
     238,   239,   240,   995,   137,   245,   246,   247,   248,   249,
    1005,   356,   996,   137,  1008,  1009,   137,   356,  1020,   356,
    1019,  1021,  1023,  1022,  1025,  1024,  1026,  1027,    47,   356,
     356,  1028,   322,    87,   324,   356,   686,   584,   713,   379,
     951,   384,   385,    39,   446,   574,   389,   443,   517,   447,
     778,   200,    39,   445,   444,    39,  1001,   656,   808,   812,
     194,  1002,   355,  1003,   884,   876,   322,   883,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   875,
     885,   804,   354,    48,   354,   806,   800,   931,    83,   354,
     201,   452,   449,   210,   450,    92,   592,   398,   354,   948,
     906,   448,   194,   212,   651,   961,   424,   425,   426,   427,
     427,   427,   427,   840,   760,   427,   427,   427,   427,   427,
     703,   427,   427,   427,   427,   427,   427,   427,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   929,   857,
     758,   770,   849,   918,   767,   928,   268,   516,   916,   519,
     981,  1010,  1018,     0,   902,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,   354,     0,     0,     0,     0,   354,     0,     0,
       0,     0,    50,   528,   529,     0,     0,   354,     0,     0,
     557,   322,     0,     0,     0,     0,    51,   567,     0,     0,
     355,    -2,     1,    52,    53,     0,     0,     0,     0,    54,
       2,  -344,    55,    56,    57,    58,     0,   577,   578,     0,
       0,     0,    59,     0,  -344,     0,     0,    60,     0,  -344,
       0,   573,   424,  -344,     0,     0,  -344,     0,     0,    61,
       0,   354,    62,     0,    63,     0,     0,     0,     0,  -344,
    -344,     0,     0,     0,     0,    26,     3,  -344,  -344,     0,
       0,    27,     0,  -344,     0,  -344,  -344,  -344,  -344,  -344,
       0,     0,     0,     0,     0,     0,  -344,     0,     0,     0,
       0,  -344,     0,  -344,   356,     0,   356,     0,     0,     0,
       0,   356,    28,  -344,     0,     4,  -344,     0,  -344,     0,
     356,     0,   650,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,    29,     0,     0,     0,   663,    30,
       0,   668,     0,   672,     5,     0,    31,     0,     0,     0,
       0,     6,     0,   688,   480,     0,     0,   692,     0,     0,
       0,     0,     0,   355,     0,     0,     0,     0,    32,   355,
      33,   355,     0,   322,     0,     0,     0,     0,     0,     0,
       0,   355,   355,     0,     0,     0,     0,   355,     0,     0,
       0,     0,   214,     0,   356,   215,     0,     0,     0,   356,
     216,     0,   217,     0,     0,     0,     0,     0,   654,   356,
     140,   141,    26,   142,   143,   144,   719,     0,    27,   145,
       0,   146,   117,     0,   147,   118,     0,     0,   119,   148,
       0,     0,     0,   120,     0,   149,     0,   121,     0,     0,
       0,     0,     0,   150,     0,     0,   122,     0,     0,    28,
       0,     0,     0,     0,   123,     0,     0,     0,     0,   124,
     125,   151,   152,   356,   153,   154,   126,   -67,   557,     0,
       0,    29,     0,   -67,     0,     0,    30,     0,   155,   156,
       0,   127,     0,    31,   128,   157,   158,     0,   129,   668,
       0,   159,     0,   160,     0,   161,   130,   131,   162,     0,
     132,     0,     0,   133,   -67,    32,     0,    33,   346,   347,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,     0,   -67,     0,     0,     0,
       0,   -67,     0,     0,   655,   557,     0,     0,   -67,   165,
       0,   166,     0,   168,   169,   170,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -67,     0,   -67,   539,   540,     0,     0,     0,   663,     0,
       0,   557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,   254,   541,  -344,   255,   542,     0,     2,
    -344,  -344,   543,     0,   535,  -344,   257,     0,  -344,     0,
       0,  -344,     0,  -344,  -344,     0,  -344,     0,  -344,     0,
    -344,     0,  -344,  -344,  -344,  -344,     0,     0,     0,  -344,
     663,     0,  -344,     0,     0,  -344,     0,  -344,  -344,  -344,
       0,     0,  -344,  -344,     0,     3,   355,  -344,   355,  -344,
       0,     0,  -344,   355,  -344,  -344,  -344,  -344,  -344,  -344,
       0,     0,   355,     0,  -344,  -344,  -344,  -344,     0,     0,
    -344,  -344,  -344,     0,     0,     0,     0,     0,     0,  -344,
    -344,     0,  -344,  -344,     0,  -344,  -344,  -344,  -344,     0,
    -344,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   930,     0,     0,
       0,     0,     0,  -410,     0,     0,     0,   937,     0,     0,
       6,     0,     0,     0,     0,     0,     0,  -344,     0,     0,
       0,     0,     0,     0,     0,     0,   355,     0,     0,     0,
     663,   355,     0,   501,     0,   140,   141,    26,   142,   143,
     144,   355,     0,    27,   145,     0,   146,   117,   326,   147,
     118,  -282,     0,   119,   327,     0,   328,   329,   120,  -282,
     149,   330,   121,     0,     0,     0,     0,     0,   150,     0,
     331,   122,   332,   333,    28,   334,   335,     0,     0,   123,
       0,     0,     0,   336,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,   355,    29,     0,     0,     0,
       0,    30,     0,   155,   156,   337,   127,     0,    31,   128,
     157,   158,     0,   129,     0,   338,   159,   339,   160,   340,
     161,   130,   131,   341,   342,   132,   343,     0,   133,     0,
      32,   344,   345,   346,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -282,     0,     0,     0,   348,
     225,     0,     0,     0,   165,     0,   166,     0,   168,   169,
     170,   171,   172,   501,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,   326,   147,
     118,   790,     0,   119,   327,     0,   328,   329,   120,   791,
     149,   330,   121,     0,     0,     0,     0,     0,   150,     0,
     331,   122,   332,   333,    28,   334,   335,     0,     0,   123,
       0,     0,     0,   336,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,   337,   127,     0,    31,   128,
     157,   158,     0,   129,     0,   338,   159,   339,   160,   340,
     161,   130,   131,   341,   342,   132,   343,     0,   133,     0,
      32,   344,   345,   346,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
     225,     0,     0,     0,   165,     0,   166,     0,   168,   169,
     170,   171,   172,   325,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,   326,   147,
     118,     0,     0,   119,   327,     0,   328,   329,   120,     0,
     149,   330,   121,     0,     0,     0,     0,     0,   150,     0,
     331,   122,   332,   333,    28,   334,   335,     0,     0,   123,
       0,     0,     0,   336,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,   337,   127,     0,    31,   128,
     157,   158,     0,   129,     0,   338,   159,   339,   160,   340,
     161,   130,   131,   341,   342,   132,   343,     0,   133,     0,
      32,   344,   345,   346,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -260,     0,     0,     0,   348,
     225,     0,     0,     0,   165,     0,   166,     0,   168,   169,
     170,   171,   172,   501,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,   326,   147,
     118,     0,     0,   119,   327,     0,   328,   329,   120,     0,
     149,   330,   121,     0,     0,     0,     0,     0,   150,     0,
     331,   122,   332,   333,    28,   334,   335,     0,     0,   123,
       0,     0,     0,   336,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,   337,   127,     0,    31,   128,
     157,   158,     0,   129,     0,   338,   159,   339,   160,   340,
     161,   130,   131,   341,   342,   132,   343,     0,   133,     0,
      32,   344,   345,   346,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -261,     0,     0,     0,   348,
     225,     0,     0,     0,   165,     0,   166,     0,   168,   169,
     170,   171,   172,   501,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,   326,   147,
     118,     0,     0,   119,   327,     0,   328,   329,   120,     0,
     149,   330,   121,     0,     0,     0,     0,     0,   150,     0,
     331,   122,   332,   333,    28,   334,   335,     0,     0,   123,
       0,     0,     0,   336,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,   337,   127,     0,    31,   128,
     157,   158,     0,   129,     0,   338,   159,   339,   160,   340,
     161,   130,   131,   341,   342,   132,   343,     0,   133,     0,
      32,   344,   345,   346,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
     225,     0,     0,     0,   165,     0,   166,     0,   168,   169,
     170,   171,   172,   501,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,   326,   147,
     118,     0,     0,   119,   327,     0,     0,   329,   120,     0,
     149,   330,   121,     0,     0,     0,     0,     0,   150,     0,
     331,   122,   332,   333,    28,   334,   335,     0,     0,   123,
       0,     0,     0,   336,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,   337,   127,     0,    31,   128,
     157,   158,     0,   129,     0,   338,   159,   339,   160,   340,
     161,   130,   131,   341,   342,   132,   343,     0,   133,     0,
      32,   344,   345,   346,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
     225,     0,     0,     0,   165,     0,   166,     0,   168,   169,
     170,   171,   172,   776,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,     0,   147,
     118,     0,     0,   119,   148,     0,     0,     0,   120,     0,
     149,     0,   121,     0,     0,     0,     0,     0,   150,     0,
       0,   122,     0,     0,    28,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,     0,   127,     0,    31,   128,
     157,   158,     0,   129,     0,     0,   159,     0,   160,     0,
     161,   130,   131,   162,     0,   132,     0,     0,   133,     0,
      32,     0,    33,   163,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   777,
       0,     0,     0,     0,   165,     0,   166,     0,   168,   169,
     170,   171,   172,   872,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,     0,   147,
     118,     0,     0,   119,   148,     0,     0,     0,   120,     0,
     149,     0,   121,     0,     0,     0,     0,     0,   150,     0,
       0,   122,     0,     0,    28,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,     0,   127,     0,    31,   128,
     157,   158,     0,   129,     0,     0,   159,     0,   160,     0,
     161,   130,   131,   162,     0,   132,     0,     0,   133,     0,
      32,     0,    33,   346,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,   166,   873,   168,   169,
     170,   171,   172,   667,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,     0,   147,
     118,     0,     0,   119,   148,     0,     0,     0,   120,     0,
     149,     0,   121,     0,     0,     0,     0,     0,   150,     0,
       0,   122,     0,     0,    28,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,     0,   127,     0,    31,   128,
     157,   158,     0,   129,     0,     0,   159,     0,   160,     0,
     161,   130,   131,   162,     0,   132,     0,     0,   133,     0,
      32,     0,    33,   163,   164,     0,     0,     0,   671,     0,
     140,   141,    26,   142,   143,   144,     0,     0,    27,   145,
       0,   146,   117,     0,   147,   118,     0,     0,   119,   148,
       0,     0,     0,   120,   165,   149,   166,   121,   168,   169,
     170,   171,   172,   150,     0,     0,   122,     0,     0,    28,
       0,     0,     0,     0,   123,     0,     0,     0,     0,   124,
     125,   151,   152,     0,   153,   154,   126,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    30,     0,   155,   156,
       0,   127,     0,    31,   128,   157,   158,     0,   129,     0,
       0,   159,     0,   160,     0,   161,   130,   131,   162,     0,
     132,     0,     0,   133,     0,    32,     0,    33,   163,   164,
       0,     0,     0,   685,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,     0,   147,
     118,     0,     0,   119,   148,     0,     0,     0,   120,   165,
     149,   166,   121,   168,   169,   170,   171,   172,   150,     0,
       0,   122,     0,     0,    28,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,     0,   127,     0,    31,   128,
     157,   158,     0,   129,     0,     0,   159,     0,   160,     0,
     161,   130,   131,   162,     0,   132,     0,     0,   133,     0,
      32,     0,    33,   163,   164,     0,     0,     0,   936,     0,
     140,   141,    26,   142,   143,   144,     0,     0,    27,   145,
       0,   146,   117,     0,   147,   118,     0,     0,   119,   148,
       0,     0,     0,   120,   165,   149,   166,   121,   168,   169,
     170,   171,   172,   150,     0,     0,   122,     0,     0,    28,
       0,     0,     0,     0,   123,     0,     0,     0,     0,   124,
     125,   151,   152,     0,   153,   154,   126,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    30,     0,   155,   156,
       0,   127,     0,    31,   128,   157,   158,     0,   129,     0,
       0,   159,     0,   160,     0,   161,   130,   131,   162,     0,
     132,     0,     0,   133,     0,    32,     0,    33,   163,   164,
       0,     0,     0,     0,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,     0,   147,
     118,     0,     0,   119,   148,     0,     0,     0,   120,   165,
     149,   166,   121,   168,   169,   170,   171,   172,   150,     0,
       0,   122,     0,     0,    28,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,     0,   127,     0,    31,   128,
     157,   158,     0,   129,     0,     0,   159,     0,   160,     0,
     161,   130,   131,   162,     0,   132,     0,     0,   133,     0,
      32,     0,    33,   163,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   165,   316,   166,     0,   168,   169,
     170,   171,   172,   140,   141,    26,   142,   143,   144,     0,
       0,    27,   145,     0,   146,   117,     0,   147,   118,     0,
       0,   119,   148,     0,     0,     0,   120,     0,   149,     0,
     121,     0,     0,     0,     0,     0,   150,     0,     0,   122,
       0,     0,    28,     0,     0,     0,     0,   123,     0,     0,
       0,     0,   124,   125,   151,   152,     0,   153,   154,   126,
       0,   407,     0,     0,    29,     0,     0,     0,     0,    30,
     408,   155,   156,     0,   127,     0,    31,   128,   157,   158,
       0,   129,     0,     0,   159,     0,   160,     0,   161,   130,
     131,   162,     0,   132,     0,     0,   133,     0,    32,     0,
      33,   163,   164,     0,     0,     0,     0,     0,   140,   141,
      26,   142,   143,   144,     0,     0,    27,   145,     0,   146,
     117,     0,   147,   118,     0,     0,   119,   148,     0,     0,
       0,   120,   165,   149,   166,   121,   168,   169,   170,   171,
     172,   150,     0,     0,   122,     0,     0,    28,     0,     0,
       0,     0,   123,     0,     0,     0,     0,   124,   125,   151,
     152,     0,   153,   154,   126,     0,     0,     0,     0,    29,
       0,     0,     0,     0,    30,     0,   155,   156,     0,   127,
       0,    31,   128,   157,   158,     0,   129,     0,     0,   159,
       0,   160,     0,   161,   130,   131,   162,     0,   132,     0,
       0,   133,     0,    32,     0,    33,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   817,     0,
       0,     0,     0,   380,     0,     0,     0,   165,     0,   166,
       0,   168,   169,   170,   171,   172,   140,   141,    26,   142,
     143,   144,     0,     0,    27,   145,     0,   146,   117,     0,
     147,   118,     0,     0,   119,   148,     0,     0,     0,   120,
       0,   149,     0,   121,     0,     0,     0,     0,     0,   150,
       0,     0,   122,     0,     0,    28,     0,     0,     0,     0,
     123,     0,     0,     0,     0,   124,   125,   151,   152,     0,
     153,   154,   126,     0,     0,     0,     0,    29,     0,     0,
       0,     0,    30,     0,   155,   156,     0,   127,     0,    31,
     128,   157,   158,     0,   129,     0,     0,   159,     0,   160,
       0,   161,   130,   131,   162,     0,   132,     0,     0,   133,
       0,    32,     0,    33,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,   166,   167,   168,
     169,   170,   171,   172,   140,   141,    26,   142,   143,   144,
       0,     0,    27,   145,     0,   146,   117,     0,   147,   118,
       0,     0,   119,   148,     0,     0,     0,   120,     0,   149,
       0,   121,     0,     0,     0,     0,     0,   150,     0,     0,
     122,     0,     0,    28,     0,     0,     0,     0,   123,     0,
       0,     0,     0,   124,   125,   151,   152,     0,   153,   154,
     126,     0,     0,     0,     0,    29,     0,     0,     0,     0,
      30,     0,   155,   156,     0,   127,     0,    31,   128,   157,
     158,     0,   129,     0,     0,   159,     0,   160,     0,   161,
     130,   131,   162,     0,   132,     0,     0,   133,     0,    32,
       0,    33,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   515,     0,
       0,     0,     0,   165,     0,   166,     0,   168,   169,   170,
     171,   172,   140,   141,    26,   142,   143,   144,     0,     0,
      27,   145,     0,   146,   117,     0,   147,   118,     0,     0,
     119,   148,     0,     0,     0,   120,     0,   149,     0,   121,
       0,     0,     0,     0,     0,   150,     0,     0,   122,     0,
       0,    28,     0,     0,     0,     0,   123,     0,     0,     0,
       0,   124,   125,   151,   152,     0,   153,   154,   126,     0,
       0,     0,     0,    29,     0,     0,     0,     0,    30,     0,
     155,   156,     0,   127,     0,    31,   128,   157,   158,     0,
     129,     0,     0,   159,     0,   160,     0,   161,   130,   131,
     162,     0,   132,     0,     0,   133,     0,    32,     0,    33,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   518,     0,     0,     0,
       0,   165,     0,   166,     0,   168,   169,   170,   171,   172,
     140,   141,    26,   142,   143,   144,     0,     0,    27,   145,
       0,   146,   117,     0,   147,   118,     0,     0,   119,   148,
       0,     0,     0,   120,     0,   149,     0,   121,     0,     0,
       0,     0,     0,   150,     0,     0,   122,     0,     0,    28,
       0,     0,     0,     0,   123,     0,     0,     0,     0,   124,
     125,   151,   152,     0,   153,   154,   126,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    30,     0,   155,   156,
       0,   127,     0,    31,   128,   157,   158,     0,   129,     0,
       0,   159,     0,   160,     0,   161,   130,   131,   162,     0,
     132,     0,     0,   133,     0,    32,     0,    33,   163,   164,
       0,     0,     0,     0,     0,   140,   141,    26,   142,   143,
     144,     0,     0,    27,   145,     0,   146,   117,     0,   147,
     118,     0,     0,   119,   148,   380,     0,     0,   120,   165,
     149,   166,   121,   168,   169,   170,   171,   172,   150,     0,
       0,   122,     0,     0,    28,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   124,   125,   151,   152,     0,   153,
     154,   126,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,   155,   156,     0,   127,     0,    31,   128,
     157,   158,     0,   129,     0,     0,   159,     0,   160,     0,
     161,   130,   131,   162,     0,   132,     0,     0,   133,     0,
      32,     0,    33,   163,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   316,   166,     0,   168,   169,
     170,   171,   172,   140,   141,    26,   142,   143,   144,     0,
       0,    27,   145,     0,   146,   117,     0,   147,   118,     0,
       0,   119,   148,     0,     0,     0,   120,     0,   149,     0,
     121,     0,     0,     0,     0,     0,   150,     0,     0,   122,
       0,     0,    28,     0,     0,     0,     0,   123,     0,     0,
       0,     0,   124,   125,   151,   152,     0,   153,   154,   126,
       0,     0,     0,     0,    29,     0,     0,     0,     0,    30,
       0,   155,   156,     0,   127,     0,    31,   128,   157,   158,
       0,   129,     0,     0,   159,     0,   160,     0,   161,   130,
     131,   162,     0,   132,     0,     0,   133,     0,    32,     0,
      33,   163,   164,     0,     0,     0,     0,     0,   140,   141,
      26,   142,   143,   144,     0,     0,    27,   145,     0,   146,
     117,     0,   147,   118,     0,     0,   119,   148,     0,     0,
       0,   120,   165,   149,   166,   121,   168,   169,   170,   171,
     172,   150,     0,     0,   122,     0,     0,    28,     0,     0,
       0,     0,   123,     0,     0,     0,     0,   124,   125,   151,
     152,     0,   153,   154,   126,     0,     0,     0,     0,    29,
       0,     0,     0,     0,    30,     0,   155,   156,     0,   127,
       0,    31,   128,   157,   158,     0,   129,     0,     0,   159,
       0,   160,     0,   161,   130,   131,   162,     0,   132,     0,
       0,   133,     0,    32,     0,    33,   346,   347,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,   166,
       0,   168,   169,   170,   171,   172,   960,     0,     0,     0,
    -344,     0,     0,     0,     2,  -344,  -344,     0,     0,     0,
    -344,     0,     0,  -344,     0,     0,  -344,     0,  -344,  -344,
       0,  -344,     0,  -344,     0,  -344,     0,  -344,  -344,  -344,
    -344,     0,     0,     0,  -344,     0,     0,  -344,     0,     0,
    -344,     0,  -344,  -344,  -344,     0,     0,  -344,  -344,     0,
       3,     0,  -344,     0,  -344,     0,     0,  -344,     0,  -344,
    -344,  -344,  -344,  -344,  -344,     0,     0,     0,     0,  -344,
    -344,  -344,  -344,     0,     0,  -344,  -344,  -344,     0,     0,
       0,     0,     0,     0,  -344,  -344,     0,  -344,  -344,     0,
    -344,  -344,  -344,  -344,     0,  -344,     0,   140,   141,    26,
     142,   143,   144,     0,     0,    27,   145,     0,   146,   117,
       0,   147,   118,     0,     0,   119,   148,     0,  -410,     0,
     120,     0,   149,     0,   121,     6,     0,     0,     0,     0,
     150,     0,  -344,   122,     0,     0,    28,     0,     0,     0,
       0,   123,     0,     0,     0,     0,   124,   125,   151,   152,
       0,   153,   154,   126,     0,     0,     0,     0,    29,     0,
       0,     0,     0,    30,     0,   155,   156,     0,   127,     0,
      31,   128,   157,   158,     0,   129,     0,     0,   159,     0,
     160,     0,   161,   130,   131,   162,     0,   132,     0,     0,
     133,     0,    32,     0,    33,    26,     0,     0,     0,     0,
       0,    27,     0,     0,     0,   117,     0,     0,   118,     0,
       0,   119,     0,     0,   305,     0,   120,     0,    88,     0,
     121,     0,    89,   306,   307,     0,     0,     0,   166,   122,
     168,   169,    28,     0,     0,   308,     0,   123,     0,     0,
       0,     0,   124,   125,     0,     0,    -3,     1,     0,   126,
       0,     0,     0,     0,   309,     2,  -344,     0,     0,    30,
       0,     0,     0,     0,   127,     0,    31,   128,     0,  -344,
       0,   129,     0,     0,  -344,     0,     0,     0,  -344,   130,
     131,  -344,     0,   132,     0,     0,   133,     0,    32,     0,
      33,     0,     0,     0,  -344,  -344,     0,     0,     0,     0,
       0,     3,  -344,  -344,     0,     0,     0,     0,  -344,     0,
    -344,  -344,  -344,  -344,  -344,     0,     0,     0,     0,     0,
       0,  -344,     0,     0,     0,     0,  -344,   310,  -344,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -344,     0,
       4,  -344,   750,  -344,     0,     0,  -344,     0,     0,     0,
       2,     0,  -344,   751,     0,     0,  -344,     0,     0,  -344,
       0,     0,  -344,     0,     0,     0,     0,  -344,     0,     5,
       0,  -344,     0,     0,     0,     0,     6,     0,     0,     0,
    -344,     0,     0,  -344,     0,     0,     0,     0,  -344,     0,
       0,     0,     0,  -344,  -344,     0,     0,     0,     0,     0,
    -344,     0,  -344,     0,  -344,  -344,     0,     0,     0,     0,
    -344,  -344,     0,     0,     0,  -344,     0,  -344,  -344,     0,
       0,     0,  -344,     0,     0,     0,     0,     0,   950,     0,
    -344,  -344,  -344,     0,  -344,     0,     2,  -344,  -344,  -344,
       0,  -344,  -344,     0,     0,  -344,     0,     0,  -344,     0,
       0,     0,     0,  -344,     0,     0,     0,  -344,     0,     0,
    -344,     0,     0,     0,     0,     0,  -344,     0,     0,  -344,
       0,     6,     0,     0,  -344,     0,     0,     0,     0,  -344,
    -344,     0,     0,     0,  -344,     0,  -344,     0,     0,     0,
       0,  -344,     0,     0,     0,     0,  -344,     1,     0,     0,
       0,  -344,     0,  -344,  -344,     2,  -344,     0,  -344,     0,
       0,     0,     0,     0,     0,     0,  -344,  -344,     0,  -344,
    -344,     0,     0,  -344,  -344,  -344,     0,  -344,  -344,     0,
       0,  -344,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -344,  -344,     0,     0,     0,     0,
    -530,     3,  -344,  -344,     0,     0,     0,     6,  -344,     0,
    -344,  -344,  -344,  -344,  -344,     0,     0,     0,     0,     0,
       0,  -344,     0,     1,     0,     0,  -344,     0,  -344,     0,
       0,     2,  -344,     0,     0,     0,     0,     0,  -344,     0,
       4,  -344,     0,  -344,     0,  -344,     0,     0,     0,     0,
    -344,     0,     0,     0,  -344,     0,     0,  -344,     0,     0,
       0,   -67,     0,     0,     0,     0,     0,   -67,     0,   -38,
    -344,  -344,     0,     0,     0,     0,     6,     3,  -344,  -344,
       0,     0,     0,    49,  -344,     0,  -344,  -344,  -344,  -344,
    -344,     0,     0,     0,     0,     0,     0,  -344,   -67,     0,
      26,     0,  -344,     0,  -344,     0,    27,     0,    50,     0,
       0,     0,     0,     0,  -344,     0,     4,  -344,     0,  -344,
     -67,     0,    51,     0,     0,   -67,     0,     0,     0,     0,
      53,     0,   -67,   613,     0,    54,     0,    28,    55,    56,
      57,    58,     0,     0,     0,   -39,     0,     0,    59,     0,
       0,     0,     6,    60,   -67,     0,   -67,   252,   253,    29,
       0,     0,     0,     0,    30,    61,     0,     0,    62,     0,
      63,    31,     0,     0,     0,     0,     0,   254,   541,  1000,
     255,   542,     0,   614,     0,     0,   543,     0,   535,     0,
     257,     0,     0,    32,     0,    33,     0,     0,   615,   616,
     617,   618,   619,   620,   621,   622,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,     0,     0,
     215,     0,   623,   624,     0,   216,     0,   217,     0,   625,
       0,     0,     0,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   886,     0,     0,     0,    26,     0,     0,     0,
       0,     0,    27,     0,     0,     0,   117,     0,     0,   118,
       0,     0,   119,     0,     0,     0,     0,   120,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,    28,     0,     0,     0,     0,   123,     0,
       0,     0,     0,   124,   125,     0,     0,     0,    26,     0,
     126,     0,     0,     0,    27,    29,     0,     0,   117,     0,
      30,   118,     0,     0,   119,   127,     0,    31,   128,   120,
       0,     0,   129,   121,     0,     0,     0,     0,     0,     0,
     130,   131,   122,     0,   132,    28,     0,   133,     0,    32,
     123,    33,     0,     0,     0,   124,   125,     0,     0,     0,
     946,     0,   126,     0,     0,     0,     0,    29,     0,     0,
       0,     0,    30,     0,     0,     0,     0,   127,     0,    31,
     128,    26,     0,     0,   129,     0,     0,    27,     0,     0,
       0,   117,   130,   131,   118,     0,   132,   119,     0,   133,
       0,    32,   120,    33,     0,     0,   121,     0,     0,   991,
       0,     0,     0,     0,     0,   122,     0,     0,    28,     0,
       0,     0,     0,   123,     0,     0,     0,     0,   124,   125,
       0,     0,     0,    26,     0,   126,     0,     0,     0,    27,
      29,     0,     0,   117,     0,    30,   118,     0,     0,   119,
     127,     0,    31,   128,   120,     0,     0,   129,   121,     0,
       0,     0,     0,     0,     0,   130,   131,   122,     0,   132,
      28,     0,   133,     0,    32,   123,    33,     0,     0,     0,
     124,   125,     0,     0,     0,     0,     0,   126,     0,     0,
       0,     0,    29,     0,     0,     0,     0,    30,     0,     0,
       0,     0,   127,     0,    31,   128,     0,     0,     0,   129,
       0,     0,     0,     0,     0,     0,     0,   130,   131,     0,
       0,   132,     0,     0,   133,     0,    32,     0,    33
};

static const yytype_int16 yycheck[] =
{
       6,   283,   225,   230,    88,    68,   298,    78,   363,   478,
     351,   392,   344,   756,   256,     6,   512,     0,   514,   506,
     222,   302,   303,   304,   738,   297,     9,   763,   524,   525,
       0,    76,    77,     9,     1,    98,    12,    43,     5,     9,
     482,    14,     9,    88,    11,    11,     9,     9,    17,     1,
     149,     9,    43,     1,    12,     1,    28,     9,   537,    11,
      32,   225,     9,     9,    70,    12,   110,    20,     9,   153,
      76,    77,    78,    79,   158,    42,   790,    16,    84,    70,
      77,     1,    88,    89,    37,    68,   124,     0,   638,   127,
     166,     9,    64,    84,    42,   436,    42,    64,    23,    19,
     382,   145,    69,    69,    42,   584,   128,    27,   153,    76,
      19,    84,     9,   158,    55,    98,     9,    69,    27,   124,
     225,   166,   124,    48,   593,   129,   210,    96,    76,   134,
      76,    98,   134,   100,    73,   219,   132,   124,    76,   210,
     363,   146,   131,   130,   694,   141,   142,   153,    23,   233,
     127,   235,   158,   534,   130,   705,   123,    82,   146,   135,
     130,   123,   543,   130,   606,   210,   330,   130,   130,   214,
     215,   640,   130,    48,   219,   530,   912,   913,   130,   381,
     225,   453,   123,   130,   130,   130,   900,   132,   233,   130,
     235,   741,   276,   277,   475,   476,   272,   273,   204,   363,
     206,   207,   208,   123,   210,   123,     4,    82,   214,   215,
     124,   146,   130,   219,   128,   221,   126,   214,   215,   225,
     134,   305,   306,   133,   131,   330,   123,   233,   327,   235,
     123,   276,   277,   130,   123,   280,   124,   130,   127,   310,
      13,   340,   341,   342,   328,   251,   101,   102,   254,   255,
      61,   133,    63,   122,    52,   132,   125,  1000,   363,    70,
     305,   306,   101,   102,   141,   142,   121,   124,   124,   124,
     276,   277,     5,    71,   130,   130,   132,    50,    11,   134,
       0,   128,   121,   328,   134,   124,   292,   134,   294,     9,
     786,   130,   779,   123,   781,   134,   103,   104,   124,   305,
     306,   543,   128,   595,   310,   122,   312,   530,   125,    42,
       5,   128,   134,   130,   297,   132,    11,   134,   363,   126,
     652,   312,   328,   130,   123,   132,   133,   122,   334,   134,
     125,    64,   105,   106,   126,   130,    69,   132,   138,   139,
     135,   133,   506,    76,   350,   390,   391,    42,   512,   122,
     514,   126,   125,   126,   635,   134,   127,   363,   133,   523,
     524,   525,   133,   126,   135,    98,   530,   100,   124,    64,
     133,   127,   122,   869,    69,   125,   128,   127,   874,   129,
     126,    76,   134,   133,   390,   391,   134,   133,   122,   122,
     134,   125,   125,   390,   391,   134,   130,   130,   132,   132,
     134,   506,   135,    98,   126,   100,   134,   512,   130,   514,
     132,   133,     1,   103,   104,   132,     5,   126,   135,   524,
     525,   505,    11,   507,   133,   530,   122,   122,   122,   125,
     125,   125,   107,   108,   130,   130,   132,   132,   819,   135,
     122,   128,   938,   125,    33,   129,   122,   134,   130,   125,
     132,   457,   458,    42,   130,   554,   132,   127,   225,   135,
     505,   506,   507,   133,   133,   135,   135,   473,   474,   553,
     453,    18,   126,   814,   815,    64,   127,   128,   523,   133,
      69,   565,   127,   474,    73,   530,   127,    76,   133,   133,
     135,   135,   133,   499,   135,   126,   541,   542,   127,   505,
      47,   507,   133,   486,   133,    52,   135,   124,   553,    98,
     134,   100,   596,   127,   598,   896,   600,     5,   140,   133,
     565,   135,   127,    11,   530,   609,   610,    74,   133,   884,
      77,    19,   143,   126,   126,   541,   542,  1006,   583,    27,
     133,   133,    89,    90,   541,   542,    93,   553,   144,   126,
     126,   596,   127,   598,    42,   600,   133,   133,   133,   565,
     126,   131,   126,   330,   609,   610,   128,   133,   639,   133,
     109,   131,   795,   133,   127,   128,    64,   583,   127,   122,
     679,    69,   125,   131,   133,   133,   583,   130,    76,   132,
     596,   134,   598,   820,   600,   122,   363,   133,   125,   128,
     127,   146,   129,   609,   610,   134,   133,   131,     6,   133,
      98,   594,   100,     5,   906,   779,   908,   781,   910,    11,
     122,   128,   786,   125,   274,   275,   122,   134,   130,   125,
     132,   795,     5,   639,   130,    27,   132,   643,    11,   135,
     278,   279,   280,   281,   282,   284,   285,   653,   747,   133,
      42,   135,    60,   636,    27,   131,   662,   133,   641,    60,
     225,   884,   134,   762,   763,   648,   649,   128,   131,    42,
     715,   133,    64,   718,   779,   135,   781,    69,   135,   127,
     686,   786,   127,   134,    76,   967,   968,   134,   134,   695,
     795,    64,   131,   134,   133,   701,    69,   134,   133,   798,
     135,   128,   801,    76,   803,   869,    98,   127,   100,   715,
     874,   134,   718,   797,   133,   721,   135,   146,   715,   725,
     884,   718,   133,   127,   135,    98,   732,   100,   133,   599,
     135,   601,   123,   598,   740,   600,   135,   127,   744,   506,
     133,   135,   128,   146,   123,   512,   135,   514,   832,   133,
     795,   134,   797,   135,   135,   854,   133,   524,   525,   742,
     135,   146,   861,   530,   869,   330,   850,   851,   146,   874,
     146,   855,   134,   857,   938,   130,   127,    99,   127,   884,
     127,   127,   135,   128,   127,   127,   123,   832,   129,   795,
      98,   797,   131,   133,     5,   133,   131,   129,   363,   135,
      11,   135,   123,   123,   133,   850,   851,   133,   127,   127,
     855,   127,   857,   912,   913,    31,    37,    20,   135,    79,
     904,   135,   135,   135,   134,    20,   832,   127,   135,   135,
     131,    42,     5,   938,   130,   123,   135,   123,    11,   884,
     133,   133,   146,   134,   850,   851,   909,   131,   831,   855,
     135,   857,   129,    64,    76,    42,   127,   129,    69,   904,
     127,   127,   868,   846,   847,    76,    46,   123,   146,    42,
     123,   128,   130,    84,   129,   127,   859,   146,   884,   133,
     128,   887,   128,   123,   123,   984,   985,    98,   129,   100,
     989,    64,   135,   135,   131,   979,    69,   146,   904,   905,
      69,    11,   134,    76,   988,   134,   166,   991,   135,  1008,
     135,   135,   131,   919,   920,   123,   134,    57,   123,   123,
     926,   927,   123,   135,   907,    98,   909,   100,   135,   135,
     163,   164,   165,   135,   979,   168,   169,   170,   171,   172,
     128,   506,   135,   988,   135,   127,   991,   512,   123,   514,
     135,   127,   123,   127,    76,   127,    42,   127,     9,   524,
     525,   127,   222,    52,   224,   530,   523,   437,   580,   229,
     953,   231,   232,   979,   289,   397,   236,   286,   338,   290,
     659,    83,   988,   288,   287,   991,   992,   506,   686,   695,
     250,   997,   225,   999,   795,   781,   256,   793,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   779,
     795,   682,   779,     9,   781,   682,   680,   868,    43,   786,
      84,   294,   292,    95,   292,    65,   458,   250,   795,   905,
     836,   291,   292,    98,   499,   909,   269,   270,   271,   272,
     273,   274,   275,   740,   643,   278,   279,   280,   281,   282,
     555,   284,   285,   286,   287,   288,   289,   290,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   861,   752,
     641,   649,   744,   847,   648,   859,   129,   337,   846,   339,
     953,  1004,  1010,    -1,   831,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,    -1,    -1,
      -1,    -1,   869,    -1,    -1,    -1,    -1,   874,    -1,    -1,
      -1,    -1,    35,   346,   347,    -1,    -1,   884,    -1,    -1,
     380,   381,    -1,    -1,    -1,    -1,    49,   387,    -1,    -1,
     363,     0,     1,    56,    57,    -1,    -1,    -1,    -1,    62,
       9,    10,    65,    66,    67,    68,    -1,   407,   408,    -1,
      -1,    -1,    75,    -1,    23,    -1,    -1,    80,    -1,    28,
      -1,   394,   395,    32,    -1,    -1,    35,    -1,    -1,    92,
      -1,   938,    95,    -1,    97,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,     5,    55,    56,    57,    -1,
      -1,    11,    -1,    62,    -1,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    80,    -1,    82,   779,    -1,   781,    -1,    -1,    -1,
      -1,   786,    42,    92,    -1,    94,    95,    -1,    97,    -1,
     795,    -1,   492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    64,    -1,    -1,    -1,   508,    69,
      -1,   511,    -1,   513,   123,    -1,    76,    -1,    -1,    -1,
      -1,   130,    -1,   523,    84,    -1,    -1,   527,    -1,    -1,
      -1,    -1,    -1,   506,    -1,    -1,    -1,    -1,    98,   512,
     100,   514,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   524,   525,    -1,    -1,    -1,    -1,   530,    -1,    -1,
      -1,    -1,   122,    -1,   869,   125,    -1,    -1,    -1,   874,
     130,    -1,   132,    -1,    -1,    -1,    -1,    -1,     1,   884,
       3,     4,     5,     6,     7,     8,   586,    -1,    11,    12,
      -1,    14,    15,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    26,    -1,    28,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,   938,    57,    58,    59,     5,   638,    -1,
      -1,    64,    -1,    11,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    81,   659,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    42,    98,    -1,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   694,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    -1,   127,   705,    -1,    -1,    76,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,   100,   101,   102,    -1,    -1,    -1,   738,    -1,
      -1,   741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,   121,   122,     5,   124,   125,    -1,     9,
      10,    11,   130,    -1,   132,    15,   134,    -1,    18,    -1,
      -1,    21,    -1,    23,    24,    -1,    26,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,
     790,    -1,    42,    -1,    -1,    45,    -1,    47,    48,    49,
      -1,    -1,    52,    53,    -1,    55,   779,    57,   781,    59,
      -1,    -1,    62,   786,    64,    65,    66,    67,    68,    69,
      -1,    -1,   795,    -1,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    93,    -1,    95,    96,    97,    98,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   867,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    -1,   877,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   869,    -1,    -1,    -1,
     900,   874,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,   884,    -1,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,   938,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    24,    25,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    24,    25,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    24,    25,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,   136,   137,
     138,   139,   140,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    14,    15,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    26,   132,    28,   134,    30,   136,   137,
     138,   139,   140,    36,    -1,    -1,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,   102,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,   132,
      28,   134,    30,   136,   137,   138,   139,   140,    36,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    14,    15,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    26,   132,    28,   134,    30,   136,   137,
     138,   139,   140,    36,    -1,    -1,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,   132,
      28,   134,    30,   136,   137,   138,   139,   140,    36,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,    -1,   136,   137,
     138,   139,   140,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    14,    15,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    81,    -1,    -1,    84,    -1,    86,    -1,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    26,   132,    28,   134,    30,   136,   137,   138,   139,
     140,    36,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    81,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,   132,    -1,   134,
      -1,   136,   137,   138,   139,   140,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,
      -1,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,
      77,    78,    79,    -1,    81,    -1,    -1,    84,    -1,    86,
      -1,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    98,    -1,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,    -1,   134,   135,   136,
     137,   138,   139,   140,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    -1,    14,    15,    -1,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,    28,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    98,
      -1,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    -1,    14,    15,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      81,    -1,    -1,    84,    -1,    86,    -1,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,   132,    -1,   134,    -1,   136,   137,   138,   139,   140,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    14,    15,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    26,    -1,    28,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,    17,
      18,    -1,    -1,    21,    22,   128,    -1,    -1,    26,   132,
      28,   134,    30,   136,   137,   138,   139,   140,    36,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,   139,   140,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    14,    15,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    81,    -1,    -1,    84,    -1,    86,    -1,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    26,   132,    28,   134,    30,   136,   137,   138,   139,
     140,    36,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    81,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    98,    -1,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,   134,
      -1,   136,   137,   138,   139,   140,     1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    18,    -1,    -1,    21,    -1,    23,    24,
      -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      45,    -1,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      55,    -1,    57,    -1,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    92,    93,    -1,
      95,    96,    97,    98,    -1,   100,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,   123,    -1,
      26,    -1,    28,    -1,    30,   130,    -1,    -1,    -1,    -1,
      36,    -1,   137,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    81,    -1,    -1,    84,    -1,
      86,    -1,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      96,    -1,    98,    -1,   100,     5,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,    -1,
      -1,    21,    -1,    -1,    24,    -1,    26,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    -1,    -1,    -1,   134,    39,
     136,   137,    42,    -1,    -1,    45,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,     0,     1,    -1,    59,
      -1,    -1,    -1,    -1,    64,     9,    10,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    74,    -1,    76,    77,    -1,    23,
      -1,    81,    -1,    -1,    28,    -1,    -1,    -1,    32,    89,
      90,    35,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
     100,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    -1,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    80,   137,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      94,    95,     1,    97,    -1,    -1,     5,    -1,    -1,    -1,
       9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,   123,
      -1,    30,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    61,    -1,    63,    64,    -1,    -1,    -1,    -1,
      69,    70,    -1,    -1,    -1,    74,    -1,    76,    77,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      89,    90,     5,    -1,    93,    -1,     9,    96,    11,    98,
      -1,   100,    15,    -1,    -1,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
      -1,   130,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    69,     1,    -1,    -1,
      -1,    74,    -1,    76,    77,     9,    10,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    23,
      93,    -1,    -1,    96,    28,    98,    -1,   100,    32,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
     123,    55,    56,    57,    -1,    -1,    -1,   130,    62,    -1,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,     1,    -1,    -1,    80,    -1,    82,    -1,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      94,    95,    -1,    97,    -1,    23,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    11,    -1,   123,
      48,    49,    -1,    -1,    -1,    -1,   130,    55,    56,    57,
      -1,    -1,    -1,    10,    62,    -1,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    75,    42,    -1,
       5,    -1,    80,    -1,    82,    -1,    11,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    94,    95,    -1,    97,
      64,    -1,    49,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      57,    -1,    76,    36,    -1,    62,    -1,    42,    65,    66,
      67,    68,    -1,    -1,    -1,   123,    -1,    -1,    75,    -1,
      -1,    -1,   130,    80,    98,    -1,   100,   101,   102,    64,
      -1,    -1,    -1,    -1,    69,    92,    -1,    -1,    95,    -1,
      97,    76,    -1,    -1,    -1,    -1,    -1,   121,   122,    84,
     124,   125,    -1,    86,    -1,    -1,   130,    -1,   132,    -1,
     134,    -1,    -1,    98,    -1,   100,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,   125,   126,    -1,   130,    -1,   132,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,     5,    -1,
      59,    -1,    -1,    -1,    11,    64,    -1,    -1,    15,    -1,
      69,    18,    -1,    -1,    21,    74,    -1,    76,    77,    26,
      -1,    -1,    81,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    39,    -1,    93,    42,    -1,    96,    -1,    98,
      47,   100,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    76,
      77,     5,    -1,    -1,    81,    -1,    -1,    11,    -1,    -1,
      -1,    15,    89,    90,    18,    -1,    93,    21,    -1,    96,
      -1,    98,    26,   100,    -1,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,     5,    -1,    59,    -1,    -1,    -1,    11,
      64,    -1,    -1,    15,    -1,    69,    18,    -1,    -1,    21,
      74,    -1,    76,    77,    26,    -1,    -1,    81,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    39,    -1,    93,
      42,    -1,    96,    -1,    98,    47,   100,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      -1,    93,    -1,    -1,    96,    -1,    98,    -1,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     9,    55,    94,   123,   130,   148,   150,   151,
     152,   157,   162,   164,   165,   256,   257,   258,   259,   272,
     279,   330,   334,   349,   357,   280,     5,    11,    42,    64,
      69,    76,    98,   100,   154,   159,     1,    33,    73,   153,
     154,   155,   156,   260,   261,   262,     0,   152,   257,    10,
      35,    49,    56,    57,    62,    65,    66,    67,    68,    75,
      80,    92,    95,    97,   269,   270,   271,   259,   128,   283,
     129,   124,   127,   131,   146,   146,   122,   125,   124,   134,
     146,   263,   155,   261,   133,   211,   154,   159,    28,    32,
      64,   287,   271,     1,   165,   256,   258,   284,   285,   286,
     288,   291,   294,   300,   309,   310,   313,   318,   323,   324,
     326,   327,   329,   127,   160,   155,   154,    15,    18,    21,
      26,    30,    39,    47,    52,    53,    59,    74,    77,    81,
      89,    90,    93,    96,   155,   166,   168,   175,   168,   156,
       3,     4,     6,     7,     8,    12,    14,    17,    22,    28,
      36,    54,    55,    57,    58,    71,    72,    78,    79,    84,
      86,    88,    91,   101,   102,   132,   134,   135,   136,   137,
     138,   139,   140,   153,   175,   176,   177,   178,   179,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   264,   265,   266,   267,   268,
     211,   262,   131,   158,   166,   153,    23,    48,    82,   123,
     269,   123,   286,   127,   122,   125,   130,   132,   126,   133,
     126,   124,   130,   134,   134,   128,   134,   219,   358,   134,
     166,   134,   134,   134,   166,   134,   134,   153,   187,   187,
     187,   167,   175,   188,   201,   187,   187,   187,   187,   187,
     129,   124,   101,   102,   121,   124,   130,   134,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   129,   132,
     141,   142,   138,   139,   103,   104,    13,    50,   105,   106,
     122,   125,   126,   134,   107,   108,   140,   143,   144,   109,
     110,   145,   133,   135,   133,   135,   131,   128,   161,   153,
     146,   351,   153,   153,   153,    24,    33,    34,    45,    64,
     137,   156,   166,   319,   168,   168,   133,   173,   174,   166,
     153,   183,   201,     6,   201,     1,    16,    22,    24,    25,
      29,    38,    40,    41,    43,    44,    51,    73,    83,    85,
      87,    91,    92,    94,    99,   100,   101,   102,   127,   153,
     169,   175,   176,   178,   179,   187,   200,   212,   214,   215,
     218,   219,   220,   221,   222,   224,   225,   232,   239,   240,
     249,   250,   252,   255,    12,   256,   296,   297,   298,   201,
     128,   130,   134,   207,   201,   201,   166,   130,   166,   201,
     122,   125,   130,   132,   135,   132,   132,   135,   268,    27,
     153,   153,    27,   153,   131,   174,   183,    61,    70,   180,
     181,   182,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   187,   187,   187,   187,   188,   188,
     189,   189,   166,   166,   190,   190,   175,   190,   190,   190,
     180,   191,   191,   193,   194,   195,   196,   197,   201,   265,
     266,   153,   267,   149,   150,   163,   160,   122,   125,   274,
      18,    47,    52,    74,    77,    89,    90,    93,   352,   350,
     274,   274,   274,   166,   166,    60,    60,   156,   134,    60,
      84,   153,   155,   292,   293,   128,   301,   126,   126,   131,
     133,   131,   133,   135,   135,   123,   127,   127,   219,   166,
     127,     1,   176,   213,   214,   134,   134,   134,    19,    27,
     153,   134,   205,   134,   202,   127,   201,   202,   127,   201,
     219,   219,   219,   134,   251,   205,    16,    73,   187,   187,
     146,   153,   216,   217,   130,   132,   170,   171,   172,   101,
     102,   122,   125,   130,   170,   127,   127,   123,   222,   127,
      61,    63,    70,   299,   135,   133,   135,   201,   207,   208,
     209,   210,   183,   180,   135,   133,   135,   201,   135,   135,
     168,   168,   173,   187,   186,   131,   131,   201,   201,   135,
     133,   170,   126,   133,   171,   135,   146,   135,   150,   123,
     153,   275,   275,   134,   128,   353,   146,   281,   146,   336,
     146,   332,   153,   289,   290,   153,   155,   311,   312,   274,
     274,   134,   296,    36,    86,   101,   102,   103,   104,   105,
     106,   107,   108,   125,   126,   132,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   325,   130,   320,   129,   124,
     134,   301,   127,   133,     1,   256,   302,   303,   305,   307,
     201,   289,    99,   166,     1,   127,   215,   223,   224,   233,
     234,   238,   166,   201,   203,   127,   127,     1,   201,   204,
     213,     1,   201,   213,   127,   128,   226,   127,    20,    37,
     241,   242,   243,   244,   248,     1,   169,   176,   201,   213,
     213,   127,   201,   222,   129,   133,   173,   172,   168,   168,
     174,   166,   219,   298,   123,   133,   131,   135,   166,   131,
     126,   126,   131,   182,   126,   133,   168,   126,   133,   201,
     126,   133,   126,   296,     1,   256,   354,   355,   356,   160,
     166,   282,    98,   276,   282,   276,   282,   276,   129,   127,
     133,   129,   301,   127,   133,   166,   166,   135,   135,   274,
       1,    12,   256,   321,   322,   210,    84,   296,   302,   153,
     293,   123,    42,    76,   123,   256,   306,   307,   256,   304,
     305,   205,   153,   253,   254,   127,     1,   127,   204,   235,
     127,   133,   153,   127,   135,   135,    31,   135,   135,     1,
      19,    27,   227,   228,   229,   230,   231,   134,   245,   219,
     248,    20,   247,    20,   244,   246,   247,   135,   216,   135,
     127,   210,   217,   131,   126,   126,   153,   123,   210,   130,
     184,   185,   135,   168,   126,   168,   153,   135,   123,   153,
     123,   133,   133,   153,   277,   278,   273,   335,   331,   203,
     290,   210,     1,   256,   314,   315,   316,   317,   153,   312,
     134,   134,   219,   146,   328,   134,   131,   299,   131,   133,
     320,   135,   127,   219,   308,   308,   127,   129,   133,   135,
     127,   127,     1,   135,   236,   238,   223,    46,   213,   123,
     203,   146,   123,   229,   221,   231,     1,   166,   219,   219,
     135,   170,   170,   173,   206,   207,   130,   126,   126,   127,
     129,   123,   356,   166,   146,   133,   283,   128,   337,   128,
     333,   123,    11,    69,   123,   256,   317,   256,   316,   166,
     166,    14,    84,   127,   219,   295,   166,   166,   322,   295,
     201,   254,   213,   135,   213,   135,     1,   201,   237,   146,
     135,   135,   153,   131,   173,   203,    57,   166,   278,   160,
       1,   256,   338,   339,   340,   341,   343,   347,   348,   160,
       1,   284,   160,   308,   308,   153,   153,   134,   134,   153,
     153,   135,   135,   213,   135,   131,   134,   123,    57,   342,
     123,   340,   123,   123,   135,   135,   180,   180,   133,   135,
     135,    33,   166,   219,   219,   135,   135,   166,   219,   166,
      84,   153,   153,   153,   320,   128,   134,   344,   135,   127,
     344,   296,     1,    42,    76,   345,   346,   219,   345,   135,
     123,   127,   127,   123,   127,    76,    42,   127,   127
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
        case 2:
#line 990 "cs_grammar.y"
    {
				/* The input file is empty */
				CCTypedWarning("-empty-input",
							   "file contains no declarations");
				ResetState();
			}
    break;

  case 3:
#line 996 "cs_grammar.y"
    {
				/* Check for empty input and finalize the parse */
				if(!HaveDecls)
				{
					CCTypedWarning("-empty-input",
								   "file contains no declarations");
				}
				ResetState();
			}
    break;

  case 4:
#line 1005 "cs_grammar.y"
    {
				/* A file that contains declarations and assembly attributes */
				if((yyvsp[(2) - (2)].node))
				{
					InitGlobalNamespace();
					CCPluginAddStandaloneAttrs
						(ILNode_StandaloneAttr_create
							((ILNode*)CurrNamespaceNode, (yyvsp[(2) - (2)].node)));
				}
				ResetState();
			}
    break;

  case 5:
#line 1016 "cs_grammar.y"
    {
				/* A file that contains only assembly attributes */
				if((yyvsp[(1) - (1)].node))
				{
					InitGlobalNamespace();
					CCPluginAddStandaloneAttrs
						(ILNode_StandaloneAttr_create
							((ILNode*)CurrNamespaceNode, (yyvsp[(1) - (1)].node)));
				}
				ResetState();
			}
    break;

  case 10:
#line 1042 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors at the outer level
				 * by skipping invalid tokens until a namespace, using,
				 * type declaration, or attribute, is encountered.
				 */
			#ifdef YYEOF
				while(yychar != YYEOF)
			#else
				while(yychar >= 0)
			#endif
				{
					if(yychar == NAMESPACE || yychar == USING ||
					   yychar == PUBLIC || yychar == INTERNAL ||
					   yychar == UNSAFE || yychar == SEALED ||
					   yychar == ABSTRACT || yychar == CLASS ||
					   yychar == STRUCT || yychar == DELEGATE ||
					   yychar == ENUM || yychar == INTERFACE ||
					   yychar == '[')
					{
						/* This token starts a new outer-level declaration */
						break;
					}
					else if(yychar == '}' && CurrNamespace.len != 0)
					{
						/* Probably the end of the enclosing namespace */
						break;
					}
					else if(yychar == ';')
					{
						/* Probably the end of an outer-level declaration,
						   so restart the parser on the next token */
						yychar = YYLEX;
						break;
					}
					yychar = YYLEX;
				}
			#ifdef YYEOF
				if(yychar != YYEOF)
			#else
				if(yychar >= 0)
			#endif
				{
					yyerrok;
				}
				NestingLevel = 0;
			}
    break;

  case 14:
#line 1098 "cs_grammar.y"
    {
				/* Recover from our educated guess that we were at the
				   end of a namespace scope in the error processing code
				   for '}' above.  If the programmer wrote "namespace XXX }"
				   instead of "namespace { XXX }", this code will stop the
				   error processing logic from looping indefinitely */
				if(CurrNamespace.len == 0)
				{
					CCError(_("parse error at or near `}'"));
				}
				else
				{
					CurrNamespace = ILInternString("", 0);
				}
			}
    break;

  case 15:
#line 1120 "cs_grammar.y"
    {
				/* Build an undistinguished identifier node.  At this
				   point, we have no idea of the identifier's type.
				   We leave that up to the semantic analysis phase */
				(yyval.node) = ILQualIdentSimple((yyvsp[(1) - (1)].name));
			}
    break;

  case 16:
#line 1129 "cs_grammar.y"
    { (yyval.name) = (yyvsp[(1) - (1)].name); }
    break;

  case 17:
#line 1130 "cs_grammar.y"
    { (yyval.name) = ILInternString("get", 3).string; }
    break;

  case 18:
#line 1131 "cs_grammar.y"
    { (yyval.name) = ILInternString("set", 3).string; }
    break;

  case 19:
#line 1132 "cs_grammar.y"
    { (yyval.name) = ILInternString("add", 3).string; }
    break;

  case 20:
#line 1133 "cs_grammar.y"
    { (yyval.name) = ILInternString("remove", 6).string; }
    break;

  case 21:
#line 1134 "cs_grammar.y"
    { (yyval.name) = ILInternString("where", 5).string; }
    break;

  case 22:
#line 1135 "cs_grammar.y"
    { (yyval.name) = ILInternString("partial", 7).string; }
    break;

  case 23:
#line 1136 "cs_grammar.y"
    { (yyval.name) = ILInternString("yield", 5).string; }
    break;

  case 24:
#line 1140 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 25:
#line 1141 "cs_grammar.y"
    {
				MakeBinary(QualIdent, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 26:
#line 1147 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:
#line 1148 "cs_grammar.y"
    {
				MakeBinary(GenericReference, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 28:
#line 1151 "cs_grammar.y"
    {
				MakeBinary(GenericReference, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 29:
#line 1170 "cs_grammar.y"
    {
				int posn, len;
				ILScope *oldLocalScope;
				posn = 0;
				if((yyvsp[(1) - (3)].node))
				{
					InitGlobalNamespace();
					CCPluginAddStandaloneAttrs
						(ILNode_StandaloneAttr_create
							((ILNode*)CurrNamespaceNode, (yyvsp[(1) - (3)].node)));
				}
				while(posn < (yyvsp[(3) - (3)].string).len)
				{
					/* Extract the next identifier */
					if((yyvsp[(3) - (3)].string).string[posn] == '.')
					{
						++posn;
						continue;
					}
					len = 0;
					while((posn + len) < (yyvsp[(3) - (3)].string).len &&
						  (yyvsp[(3) - (3)].string).string[posn + len] != '.')
					{
						++len;
					}

					/* Push a new identifier onto the end of the namespace */
					if(CurrNamespace.len != 0)
					{
						CurrNamespace = ILInternAppendedString
							(CurrNamespace,
							 ILInternAppendedString
							 	(ILInternString(".", 1),
								 ILInternString((yyvsp[(3) - (3)].string).string + posn, len)));
					}
					else
					{
						CurrNamespace = ILInternString((yyvsp[(3) - (3)].string).string + posn, len);
					}

					/* Create the namespace node */
					InitGlobalNamespace();
					
					oldLocalScope=LocalScope();
					
					CurrNamespaceNode = (ILNode_Namespace *)
						ILNode_Namespace_create(CurrNamespace.string,
												CurrNamespaceNode);

					/* Preserve compilation unit specific local scopes 
					 * or maybe I need to create a new scope as child of
					 * this scope (fix when I find a test case) */
					CurrNamespaceNode->localScope=oldLocalScope;

					/* Declare the namespace within the global scope */
					ILScopeDeclareNamespace(GlobalScope(),
											CurrNamespace.string);

					/* Move on to the next namespace component */
					posn += len;
				}
			}
    break;

  case 30:
#line 1232 "cs_grammar.y"
    {
				/* Pop the identifier from the end of the namespace */
				if(CurrNamespace.len == (yyvsp[(3) - (6)].string).len)
				{
					CurrNamespace = ILInternString("", 0);
					while(CurrNamespaceNode->enclosing != 0)
					{
						CurrNamespaceNode = CurrNamespaceNode->enclosing;
					}
				}
				else
				{
					CurrNamespace = ILInternString
						(CurrNamespace.string, CurrNamespace.len - (yyvsp[(3) - (6)].string).len - 1);
					while(CurrNamespaceNode->name != CurrNamespace.string)
					{
						CurrNamespaceNode = CurrNamespaceNode->enclosing;
					}
				}
			}
    break;

  case 31:
#line 1255 "cs_grammar.y"
    { (yyval.string) = ILInternString((yyvsp[(1) - (1)].name), strlen((yyvsp[(1) - (1)].name))); }
    break;

  case 32:
#line 1256 "cs_grammar.y"
    {
				(yyval.string) = ILInternAppendedString
					((yyvsp[(1) - (3)].string), ILInternAppendedString
					 		(ILInternString(".", 1),
							 ILInternString((yyvsp[(3) - (3)].name), strlen((yyvsp[(3) - (3)].name)))));
			}
    break;

  case 36:
#line 1274 "cs_grammar.y"
    {
				ILScope *globalScope = GlobalScope();
				ILScope *scope = LocalScope();
				ILNode *alias;
				if(ILScopeLookup(globalScope, (yyvsp[(2) - (5)].name), 1))
				{
					CCError("`%s' is already declared", (yyvsp[(2) - (5)].name));
				}
				else if(ILScopeLookup(localScope, (yyvsp[(2) - (5)].name), 1))
				{
					CCError("`%s' is already declared", (yyvsp[(2) - (5)].name));
				}
				alias = ILNode_UsingAlias_create((yyvsp[(2) - (5)].name), ILQualIdentName((yyvsp[(4) - (5)].node),0));
				/* NOTE: CSSemGuard is not needed as ILNode_UsingAlias is
				         never Semanalyzed */
				InitGlobalNamespace();
				ILScopeDeclareAlias(scope, (yyvsp[(2) - (5)].name),alias,(yyvsp[(4) - (5)].node));
				CurrNamespaceNode->localScope=scope;
			}
    break;

  case 37:
#line 1293 "cs_grammar.y"
    {
				ILScope *globalScope = GlobalScope();
				ILNode_UsingNamespace *using;
				if(!ILScopeUsing(globalScope, (yyvsp[(2) - (3)].string).string))
				{
					CCError("`%s' is not a namespace", (yyvsp[(2) - (3)].string).string);
				}
				InitGlobalNamespace();
				if(!HaveUsingNamespace((yyvsp[(2) - (3)].string).string))
				{
					using = (ILNode_UsingNamespace *)
						ILNode_UsingNamespace_create((yyvsp[(2) - (3)].string).string);
					using->next = CurrNamespaceNode->using;
					CurrNamespaceNode->using = using;
				}
			}
    break;

  case 41:
#line 1318 "cs_grammar.y"
    { CCPluginAddTopLevel((yyvsp[(1) - (1)].node)); }
    break;

  case 42:
#line 1322 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 43:
#line 1323 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 44:
#line 1324 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 45:
#line 1325 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 46:
#line 1326 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 47:
#line 1327 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 48:
#line 1335 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 49:
#line 1336 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 50:
#line 1337 "cs_grammar.y"
    {
				MakeBinary(ArrayType, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].count));
			}
    break;

  case 51:
#line 1340 "cs_grammar.y"
    {
				MakeUnary(PtrType, (yyvsp[(1) - (2)].node));
			}
    break;

  case 52:
#line 1343 "cs_grammar.y"
    {
				MakeBinary(GenericReference, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 53:
#line 1346 "cs_grammar.y"
    {
				MakeBinary(GenericReference, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 54:
#line 1352 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 55:
#line 1353 "cs_grammar.y"
    {
				MakeBinary(ArrayType, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].count));
			}
    break;

  case 56:
#line 1356 "cs_grammar.y"
    {
				MakeUnary(PtrType, (yyvsp[(1) - (2)].node));
			}
    break;

  case 57:
#line 1359 "cs_grammar.y"
    { 
				MakeUnary(PtrType, (yyvsp[(1) - (2)].node));
			}
    break;

  case 58:
#line 1362 "cs_grammar.y"
    { 
				/* Needed becuase of shift issues that won't be picked
				   up by the "Expression *" case above */
				MakeUnary(PtrType, (yyvsp[(1) - (2)].node));
			}
    break;

  case 59:
#line 1367 "cs_grammar.y"
    {
				MakeBinary(GenericReference, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 60:
#line 1370 "cs_grammar.y"
    {
				MakeBinary(GenericReference, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 61:
#line 1376 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:
#line 1377 "cs_grammar.y"
    { MakeBinary(TypeActuals, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 63:
#line 1386 "cs_grammar.y"
    {
				MakeBinary(LocalVariableType, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
			}
    break;

  case 64:
#line 1389 "cs_grammar.y"
    {
				ILNode *type = ILNode_GenericReference_create((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node));
				MakeBinary(LocalVariableType, type, (yyvsp[(5) - (5)].node));
			}
    break;

  case 65:
#line 1393 "cs_grammar.y"
    {
				ILNode *type = ILNode_GenericReference_create((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node));
				MakeBinary(LocalVariableType, type, (yyvsp[(5) - (5)].node));
			}
    break;

  case 66:
#line 1397 "cs_grammar.y"
    {
				MakeBinary(LocalVariableType, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
			}
    break;

  case 67:
#line 1403 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 68:
#line 1404 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 69:
#line 1408 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 70:
#line 1412 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 71:
#line 1419 "cs_grammar.y"
    { MakeUnary(TypeSuffix, (yyvsp[(2) - (3)].count)); }
    break;

  case 72:
#line 1420 "cs_grammar.y"
    { MakeUnary(TypeSuffix, 0); }
    break;

  case 73:
#line 1424 "cs_grammar.y"
    { (yyval.count) = 1; }
    break;

  case 74:
#line 1425 "cs_grammar.y"
    { (yyval.count) = (yyvsp[(1) - (1)].count); }
    break;

  case 75:
#line 1429 "cs_grammar.y"
    { (yyval.count) = 2; }
    break;

  case 76:
#line 1430 "cs_grammar.y"
    { (yyval.count) = (yyvsp[(1) - (2)].count) + 1; }
    break;

  case 77:
#line 1440 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_VOID); }
    break;

  case 78:
#line 1441 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_BOOLEAN); }
    break;

  case 79:
#line 1442 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I1); }
    break;

  case 80:
#line 1443 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U1); }
    break;

  case 81:
#line 1444 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I2); }
    break;

  case 82:
#line 1445 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U2); }
    break;

  case 83:
#line 1446 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I4); }
    break;

  case 84:
#line 1447 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U4); }
    break;

  case 85:
#line 1448 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I8); }
    break;

  case 86:
#line 1449 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U8); }
    break;

  case 87:
#line 1450 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_CHAR); }
    break;

  case 88:
#line 1451 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_R4); }
    break;

  case 89:
#line 1452 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_R8); }
    break;

  case 90:
#line 1453 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_R); }
    break;

  case 91:
#line 1454 "cs_grammar.y"
    { MakeUnary(SystemType,"Decimal"); }
    break;

  case 92:
#line 1455 "cs_grammar.y"
    { MakeUnary(SystemType,"Object"); }
    break;

  case 93:
#line 1456 "cs_grammar.y"
    { MakeUnary(SystemType,"String"); }
    break;

  case 94:
#line 1464 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:
#line 1465 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 96:
#line 1466 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 97:
#line 1467 "cs_grammar.y"
    { MakeBinary(MemberAccess, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 98:
#line 1468 "cs_grammar.y"
    { MakeBinary(MemberAccess, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 99:
#line 1469 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 100:
#line 1470 "cs_grammar.y"
    {
				MakeBinary(ArrayAccess, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 101:
#line 1473 "cs_grammar.y"
    {
				/*
				 * This is actually a type, but we have to recognise
				 * it here to avoid shift/reduce conflicts in the
				 * definition of casts in UnaryExpression.  We would
				 * like to handle this in NonExpressionType, but then it
				 * creates problems for casts to array types like "A[]".
				 */
				MakeBinary(ArrayType, (yyvsp[(1) - (3)].node), 1);
			}
    break;

  case 102:
#line 1483 "cs_grammar.y"
    {
				/* This is also a type */
				MakeBinary(ArrayType, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].count));
			}
    break;

  case 103:
#line 1487 "cs_grammar.y"
    { MakeSimple(VarArgList); }
    break;

  case 104:
#line 1488 "cs_grammar.y"
    { MakeSimple(This); }
    break;

  case 105:
#line 1489 "cs_grammar.y"
    { MakeUnary(BaseAccess, (yyvsp[(3) - (3)].node)); }
    break;

  case 106:
#line 1490 "cs_grammar.y"
    { MakeUnary(BaseElement, (yyvsp[(3) - (4)].node)); }
    break;

  case 107:
#line 1491 "cs_grammar.y"
    { MakeUnary(PostInc, (yyvsp[(1) - (2)].node)); }
    break;

  case 108:
#line 1492 "cs_grammar.y"
    { MakeUnary(PostDec, (yyvsp[(1) - (2)].node)); }
    break;

  case 109:
#line 1493 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 110:
#line 1494 "cs_grammar.y"
    {
				(yyval.node) = ILNode_NewExpression_create((yyvsp[(2) - (7)].node), (yyvsp[(4) - (7)].node), (yyvsp[(6) - (7)].node), (yyvsp[(7) - (7)].node));
			}
    break;

  case 111:
#line 1497 "cs_grammar.y"
    {
				(yyval.node) = ILNode_NewExpression_create((yyvsp[(2) - (3)].node), 0, 0, (yyvsp[(3) - (3)].node));
			}
    break;

  case 112:
#line 1500 "cs_grammar.y"
    { MakeUnary(TypeOf, (yyvsp[(3) - (4)].node)); }
    break;

  case 113:
#line 1501 "cs_grammar.y"
    {
				/*
				 * This is only safe if it is used on one of the following
				 * builtin types: sbyte, byte, short, ushort, int, uint,
				 * long, ulong, float, double, char, bool.  We leave the
				 * check to the semantic analysis phase.
				 */
				MakeUnary(SizeOf, (yyvsp[(3) - (4)].node));
			}
    break;

  case 114:
#line 1510 "cs_grammar.y"
    { MakeUnary(Overflow, (yyvsp[(3) - (4)].node)); }
    break;

  case 115:
#line 1511 "cs_grammar.y"
    { MakeUnary(NoOverflow, (yyvsp[(3) - (4)].node)); }
    break;

  case 116:
#line 1512 "cs_grammar.y"
    {
				MakeBinary(DerefField, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 117:
#line 1515 "cs_grammar.y"
    {
				MakeBinary(StackAlloc, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));
			}
    break;

  case 118:
#line 1518 "cs_grammar.y"
    {
				/*
				 * Get the value of a builtin constant.
				 */
				(yyval.node) = CSBuiltinConstant((yyvsp[(3) - (4)].string).string);
			}
    break;

  case 119:
#line 1524 "cs_grammar.y"
    { MakeUnary(MakeRefAny, (yyvsp[(3) - (4)].node)); }
    break;

  case 120:
#line 1525 "cs_grammar.y"
    { MakeUnary(RefType, (yyvsp[(3) - (4)].node)); }
    break;

  case 121:
#line 1526 "cs_grammar.y"
    { MakeBinary(RefValue, (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node)); }
    break;

  case 122:
#line 1527 "cs_grammar.y"
    { (yyval.node) = ILQualIdentSimple("<Module>"); }
    break;

  case 123:
#line 1528 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 124:
#line 1529 "cs_grammar.y"
    {
				(yyval.node) = ILNode_DefaultConstructor_create((yyvsp[(1) - (3)].node), 0, 0);
			}
    break;

  case 125:
#line 1532 "cs_grammar.y"
    {
				(yyval.node) = ILNode_DefaultConstructor_create((yyvsp[(1) - (3)].node), 0, 0);
			}
    break;

  case 126:
#line 1538 "cs_grammar.y"
    { MakeSimple(True); }
    break;

  case 127:
#line 1539 "cs_grammar.y"
    { MakeSimple(False); }
    break;

  case 128:
#line 1540 "cs_grammar.y"
    { MakeSimple(Null); }
    break;

  case 129:
#line 1541 "cs_grammar.y"
    {
				switch((yyvsp[(1) - (1)].integer).type)
				{
					case CS_NUMTYPE_INT32:
					{
						(yyval.node) = ILNode_Int32_create((yyvsp[(1) - (1)].integer).value, 0, (yyvsp[(1) - (1)].integer).canneg);
					}
					break;

					case CS_NUMTYPE_UINT32:
					{
						(yyval.node) = ILNode_UInt32_create((yyvsp[(1) - (1)].integer).value, 0, (yyvsp[(1) - (1)].integer).canneg);
					}
					break;

					case CS_NUMTYPE_INT64:
					{
						(yyval.node) = ILNode_Int64_create((yyvsp[(1) - (1)].integer).value, 0, (yyvsp[(1) - (1)].integer).canneg);
					}
					break;

					default:
					{
						(yyval.node) = ILNode_UInt64_create((yyvsp[(1) - (1)].integer).value, 0, (yyvsp[(1) - (1)].integer).canneg);
					}
					break;
				}
			}
    break;

  case 130:
#line 1569 "cs_grammar.y"
    {
				if((yyvsp[(1) - (1)].real).type == CS_NUMTYPE_FLOAT32)
				{
					(yyval.node) = ILNode_Float32_create((yyvsp[(1) - (1)].real).value);
				}
				else
				{
					(yyval.node) = ILNode_Float64_create((yyvsp[(1) - (1)].real).value);
				}
			}
    break;

  case 131:
#line 1579 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Decimal_create((yyvsp[(1) - (1)].decimal));
			}
    break;

  case 132:
#line 1582 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Char_create((ILUInt64)((yyvsp[(1) - (1)].charValue)), 0, 1);
			}
    break;

  case 133:
#line 1585 "cs_grammar.y"
    {
				(yyval.node) = ILNode_String_create((yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).len);
			}
    break;

  case 134:
#line 1591 "cs_grammar.y"
    { 
				/* Check for "__arglist", which is handled specially */
				if(!yyisa((yyvsp[(1) - (4)].node), ILNode_VarArgList))
				{
					MakeBinary(InvocationExpression, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); 
				}
				else
				{
					MakeUnary(VarArgExpand, (yyvsp[(3) - (4)].node)); 
				}
			}
    break;

  case 135:
#line 1605 "cs_grammar.y"
    { 
				MakeBinary(ObjectCreationExpression, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)); 
			}
    break;

  case 136:
#line 1611 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 137:
#line 1612 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 138:
#line 1616 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 139:
#line 1617 "cs_grammar.y"
    { MakeBinary(ArgList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 140:
#line 1621 "cs_grammar.y"
    { MakeBinary(Argument, ILParamMod_empty, (yyvsp[(1) - (1)].node)); }
    break;

  case 141:
#line 1622 "cs_grammar.y"
    { MakeBinary(Argument, ILParamMod_out, (yyvsp[(2) - (2)].node)); }
    break;

  case 142:
#line 1623 "cs_grammar.y"
    { MakeBinary(Argument, ILParamMod_ref, (yyvsp[(2) - (2)].node)); }
    break;

  case 143:
#line 1627 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 144:
#line 1628 "cs_grammar.y"
    { MakeBinary(ArgList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 145:
#line 1632 "cs_grammar.y"
    { (yyval.node) = 0;}
    break;

  case 146:
#line 1633 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 147:
#line 1637 "cs_grammar.y"
    {
					(yyval.node) = ILNode_List_create();
					ILNode_List_Add((yyval.node), ILNode_TypeSuffix_create((yyvsp[(2) - (3)].count)));
				}
    break;

  case 148:
#line 1641 "cs_grammar.y"
    {
					ILNode_List_Add((yyvsp[(1) - (4)].node), ILNode_TypeSuffix_create((yyvsp[(3) - (4)].count)));
					(yyval.node) = (yyvsp[(1) - (4)].node);
				}
    break;

  case 149:
#line 1680 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 150:
#line 1681 "cs_grammar.y"
    { 
				MakeUnary(LogicalNot,ILNode_ToBool_create((yyvsp[(2) - (2)].node))); 
	}
    break;

  case 151:
#line 1684 "cs_grammar.y"
    { MakeUnary(Not, (yyvsp[(2) - (2)].node)); }
    break;

  case 152:
#line 1685 "cs_grammar.y"
    {
				/*
				 * Note: we need to use a full "Expression" for the type,
				 * so that we don't get a reduce/reduce conflict with the
				 * rule "PrimaryExpression: '(' Expression ')'".  We later
				 * filter out expressions that aren't really types.
				 */
				MakeBinary(UserCast, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 153:
#line 1694 "cs_grammar.y"
    {
				/*
				 * This rule recognizes types that involve non-expression
				 * identifiers such as "int", "bool", "string", etc.
				 */
				MakeBinary(UserCast, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 154:
#line 1704 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 155:
#line 1705 "cs_grammar.y"
    { MakeUnary(UnaryPlus, (yyvsp[(2) - (2)].node)); }
    break;

  case 156:
#line 1706 "cs_grammar.y"
    {
				/* We create negate nodes carefully so that integer
				   and float constants can be negated in-place */
				if(yyisa((yyvsp[(2) - (2)].node), ILNode_Integer))
				{
					(yyval.node) = NegateInteger((ILNode_Integer *)(yyvsp[(2) - (2)].node));
				}
				else if(yyisa((yyvsp[(2) - (2)].node), ILNode_Real))
				{
					((ILNode_Real *)((yyvsp[(2) - (2)].node)))->value =
							-(((ILNode_Real *)((yyvsp[(2) - (2)].node)))->value);
					(yyval.node) = (yyvsp[(2) - (2)].node);
				}
				else if(yyisa((yyvsp[(2) - (2)].node), ILNode_Decimal))
				{
					ILDecimalNeg(&(((ILNode_Decimal *)((yyvsp[(2) - (2)].node)))->value),
								 &(((ILNode_Decimal *)((yyvsp[(2) - (2)].node)))->value));
					(yyval.node) = (yyvsp[(2) - (2)].node);
				}
				else
				{
					MakeUnary(Neg, (yyvsp[(2) - (2)].node));
				}
			}
    break;

  case 157:
#line 1730 "cs_grammar.y"
    { MakeUnary(PreInc, (yyvsp[(2) - (2)].node)); }
    break;

  case 158:
#line 1731 "cs_grammar.y"
    { MakeUnary(PreDec, (yyvsp[(2) - (2)].node)); }
    break;

  case 159:
#line 1732 "cs_grammar.y"
    { MakeBinary(Deref, (yyvsp[(2) - (2)].node), 0); }
    break;

  case 160:
#line 1733 "cs_grammar.y"
    { MakeUnary(AddressOf, (yyvsp[(2) - (2)].node)); }
    break;

  case 161:
#line 1737 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 162:
#line 1738 "cs_grammar.y"
    {
				MakeBinary(Mul, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 163:
#line 1741 "cs_grammar.y"
    {
				MakeBinary(Div, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 164:
#line 1744 "cs_grammar.y"
    {
				MakeBinary(Rem, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 165:
#line 1750 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 166:
#line 1751 "cs_grammar.y"
    {
				MakeBinary(Add, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 167:
#line 1754 "cs_grammar.y"
    {
				MakeBinary(Sub, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 168:
#line 1760 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 169:
#line 1761 "cs_grammar.y"
    {
				MakeBinary(Shl, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 170:
#line 1764 "cs_grammar.y"
    {
				MakeBinary(Shr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 171:
#line 1782 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 172:
#line 1783 "cs_grammar.y"
    {
				MakeBinary(Lt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 173:
#line 1786 "cs_grammar.y"
    {
				MakeBinary(Gt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 174:
#line 1789 "cs_grammar.y"
    {
				MakeBinary(Le, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 175:
#line 1792 "cs_grammar.y"
    {
				MakeBinary(Ge, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 176:
#line 1795 "cs_grammar.y"
    {
				MakeBinary(IsUntyped, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 177:
#line 1798 "cs_grammar.y"
    {
				MakeBinary(AsUntyped, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 178:
#line 1801 "cs_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (1)].node);
			}
    break;

  case 179:
#line 1804 "cs_grammar.y"
    {
				(yyval.node) = CSInsertMethodInvocation((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 180:
#line 1810 "cs_grammar.y"
    {
				(yyval.node) = CSInsertGenericReference((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 181:
#line 1813 "cs_grammar.y"
    {
				(yyval.node) = CSInsertGenericReference
					((yyvsp[(1) - (5)].node), ILNode_LocalVariableType_create((yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node)));
			}
    break;

  case 182:
#line 1817 "cs_grammar.y"
    {
				(yyval.node) = CSInsertGenericReference
					((yyvsp[(1) - (6)].node), ILNode_TypeActuals_create((yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node)));
			}
    break;

  case 183:
#line 1822 "cs_grammar.y"
    {
				(yyval.node) = CSInsertGenericReference
					((yyvsp[(1) - (7)].node), CSInsertTypeActuals
						(ILNode_LocalVariableType_create((yyvsp[(3) - (7)].node), (yyvsp[(4) - (7)].node)), (yyvsp[(6) - (7)].node)));
			}
    break;

  case 184:
#line 1827 "cs_grammar.y"
    {
				(yyval.node) = CSInsertGenericReference
					((yyvsp[(1) - (5)].node), ILNode_LocalVariableType_create((yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node)));
			}
    break;

  case 185:
#line 1832 "cs_grammar.y"
    {
				(yyval.node) = CSInsertGenericReference
					((yyvsp[(1) - (7)].node), CSInsertTypeActuals
						(ILNode_LocalVariableType_create((yyvsp[(3) - (7)].node), (yyvsp[(4) - (7)].node)), (yyvsp[(6) - (7)].node)));
			}
    break;

  case 186:
#line 1840 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 187:
#line 1841 "cs_grammar.y"
    {
				MakeBinary(Eq, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 188:
#line 1844 "cs_grammar.y"
    {
				MakeBinary(Ne, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 189:
#line 1850 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 190:
#line 1851 "cs_grammar.y"
    {
				MakeBinary(And, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 191:
#line 1857 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 192:
#line 1858 "cs_grammar.y"
    {
				MakeBinary(Xor, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 193:
#line 1864 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 194:
#line 1865 "cs_grammar.y"
    {
				MakeBinary(Or, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 195:
#line 1871 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 196:
#line 1872 "cs_grammar.y"
    {
				MakeBinary(LogicalAnd, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 197:
#line 1878 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 198:
#line 1879 "cs_grammar.y"
    {
				MakeBinary(LogicalOr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 199:
#line 1885 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 200:
#line 1886 "cs_grammar.y"
    {
				MakeTernary(Conditional, ILNode_ToBool_create((yyvsp[(1) - (5)].node)), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 201:
#line 1892 "cs_grammar.y"
    {
				MakeBinary(Assign, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 202:
#line 1895 "cs_grammar.y"
    {
				MakeUnary(AssignAdd, ILNode_Add_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 203:
#line 1898 "cs_grammar.y"
    {
				MakeUnary(AssignSub, ILNode_Sub_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 204:
#line 1901 "cs_grammar.y"
    {
				MakeUnary(AssignMul, ILNode_Mul_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 205:
#line 1904 "cs_grammar.y"
    {
				MakeUnary(AssignDiv, ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 206:
#line 1907 "cs_grammar.y"
    {
				MakeUnary(AssignRem, ILNode_Rem_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 207:
#line 1910 "cs_grammar.y"
    {
				MakeUnary(AssignAnd, ILNode_And_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 208:
#line 1913 "cs_grammar.y"
    {
				MakeUnary(AssignOr, ILNode_Or_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 209:
#line 1916 "cs_grammar.y"
    {
				MakeUnary(AssignXor, ILNode_Xor_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 210:
#line 1919 "cs_grammar.y"
    {
				MakeUnary(AssignShl, ILNode_Shl_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 211:
#line 1922 "cs_grammar.y"
    {
				MakeUnary(AssignShr, ILNode_Shr_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 212:
#line 1928 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 213:
#line 1929 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 214:
#line 1933 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 215:
#line 1934 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in expressions
				 * that are used with "switch".  Return 0 as the value.
				 */
				MakeTernary(Int32, 0, 0, 1);
				yyerrok;
			}
    break;

  case 216:
#line 1945 "cs_grammar.y"
    { MakeUnary(ToConst, (yyvsp[(1) - (1)].node)); }
    break;

  case 217:
#line 1949 "cs_grammar.y"
    { MakeUnary(ToBool, (yyvsp[(1) - (1)].node)); }
    break;

  case 218:
#line 1953 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 219:
#line 1954 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in boolean
				 * expressions that are used with "if", "while", etc.
				 * Default to "false" as the error condition's value.
				 */
				MakeSimple(False);
				yyerrok;
			}
    break;

  case 220:
#line 1970 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 221:
#line 1971 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 222:
#line 1975 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 223:
#line 1976 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (4)].node); }
    break;

  case 224:
#line 1980 "cs_grammar.y"
    { (yyval.node) = ILNode_List_create(); }
    break;

  case 225:
#line 1981 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 226:
#line 1985 "cs_grammar.y"
    {	
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 227:
#line 1989 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 228:
#line 1996 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 229:
#line 1997 "cs_grammar.y"
    { MakeUnary(ArrayInit, (yyvsp[(1) - (1)].node)); }
    break;

  case 232:
#line 2010 "cs_grammar.y"
    {
				/* Convert the identifier into a "GotoLabel" node */
				ILNode *label = ILNode_GotoLabel_create(ILQualIdentName((yyvsp[(1) - (3)].node), 0));

				/* Build a compound statement */
				(yyval.node) = ILNode_Compound_CreateFrom(label, (yyvsp[(3) - (3)].node));
			}
    break;

  case 233:
#line 2017 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 234:
#line 2018 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 235:
#line 2019 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 236:
#line 2023 "cs_grammar.y"
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

  case 237:
#line 2039 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 238:
#line 2040 "cs_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 239:
#line 2041 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 240:
#line 2042 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 241:
#line 2043 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 242:
#line 2044 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 243:
#line 2045 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 244:
#line 2046 "cs_grammar.y"
    { MakeUnary(Overflow, (yyvsp[(2) - (2)].node)); }
    break;

  case 245:
#line 2047 "cs_grammar.y"
    { MakeUnary(NoOverflow, (yyvsp[(2) - (2)].node)); }
    break;

  case 246:
#line 2048 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 247:
#line 2049 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 248:
#line 2050 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 249:
#line 2051 "cs_grammar.y"
    { MakeUnary(Unsafe, (yyvsp[(2) - (2)].node)); }
    break;

  case 250:
#line 2052 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 251:
#line 2053 "cs_grammar.y"
    {
				/*
				 * This production recovers from parse errors in statements,
				 * by seaching for the end of the current statement.
				 */
				MakeSimple(Empty);
				yyerrok;
			}
    break;

  case 252:
#line 2064 "cs_grammar.y"
    {
				/* "VariableDeclarators" has split the declaration into
				   a list of variable names, plus a list of assignment
				   statements to set the initial values.  Turn the result
				   into a local variable declaration followed by the
				   assignment statements */
				if((yyvsp[(2) - (2)].varInit).init)
				{
					(yyval.node) = ILNode_Compound_CreateFrom
							(ILNode_LocalVarDeclaration_create((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].varInit).decl),
							 (yyvsp[(2) - (2)].varInit).init);
				}
				else
				{
					(yyval.node) = ILNode_LocalVarDeclaration_create((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].varInit).decl);
				}
			}
    break;

  case 253:
#line 2084 "cs_grammar.y"
    {
				(yyval.varInit).decl = ILNode_List_create();
				ILNode_List_Add((yyval.varInit).decl, (yyvsp[(1) - (1)].varInit).decl);
				(yyval.varInit).init = (yyvsp[(1) - (1)].varInit).init;
			}
    break;

  case 254:
#line 2089 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].varInit).decl, (yyvsp[(3) - (3)].varInit).decl);
				(yyval.varInit).decl = (yyvsp[(1) - (3)].varInit).decl;
				if((yyvsp[(1) - (3)].varInit).init)
				{
					if((yyvsp[(3) - (3)].varInit).init)
					{
						(yyval.varInit).init = ILNode_Compound_CreateFrom((yyvsp[(1) - (3)].varInit).init, (yyvsp[(3) - (3)].varInit).init);
					}
					else
					{
						(yyval.varInit).init = (yyvsp[(1) - (3)].varInit).init;
					}
				}
				else if((yyvsp[(3) - (3)].varInit).init)
				{
					(yyval.varInit).init = (yyvsp[(3) - (3)].varInit).init;
				}
				else
				{
					(yyval.varInit).init = 0;
				}
			}
    break;

  case 255:
#line 2115 "cs_grammar.y"
    { (yyval.varInit).decl = (yyvsp[(1) - (1)].node); (yyval.varInit).init = 0; }
    break;

  case 256:
#line 2116 "cs_grammar.y"
    {
				(yyval.varInit).decl = (yyvsp[(1) - (3)].node);
				(yyval.varInit).init = ILNode_Assign_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 257:
#line 2123 "cs_grammar.y"
    {
				(yyval.node) = ILNode_LocalConstDeclaration_create((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 258:
#line 2129 "cs_grammar.y"
    {
				ILNode *temp;
			#ifdef YYBISON
				if(yykind((yyvsp[(2) - (3)].node)) == yykindof(ILNode_Empty) && debug_flag)
				{
					temp = ILNode_LineInfo_create((yyvsp[(2) - (3)].node));
					yysetlinenum(temp, (yylsp[(1) - (3)]).first_line);
				}
				else
			#endif
				{
					temp = (yyvsp[(2) - (3)].node);
				}

				/* Wrap the block in a new local variable scope */
				(yyval.node) = ILNode_NewScope_create(temp);
				yysetfilename((yyval.node), yygetfilename(temp));
				yysetlinenum((yyval.node), yygetlinenum(temp));
			}
    break;

  case 259:
#line 2148 "cs_grammar.y"
    {
				/*
				 * This production recovers from parse errors in
				 * a block, by closing off the block on error.
				 */
				MakeSimple(Empty);
				yyerrok;
			}
    break;

  case 260:
#line 2159 "cs_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 261:
#line 2160 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 262:
#line 2164 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 263:
#line 2165 "cs_grammar.y"
    { (yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 264:
#line 2169 "cs_grammar.y"
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

  case 265:
#line 2185 "cs_grammar.y"
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

  case 266:
#line 2201 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 267:
#line 2202 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 268:
#line 2203 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 269:
#line 2204 "cs_grammar.y"
    { MakeUnary(PostInc, (yyvsp[(1) - (2)].node)); }
    break;

  case 270:
#line 2205 "cs_grammar.y"
    { MakeUnary(PostDec, (yyvsp[(1) - (2)].node)); }
    break;

  case 271:
#line 2206 "cs_grammar.y"
    { MakeUnary(PreInc, (yyvsp[(2) - (2)].node)); }
    break;

  case 272:
#line 2207 "cs_grammar.y"
    { MakeUnary(PreDec, (yyvsp[(2) - (2)].node)); }
    break;

  case 273:
#line 2211 "cs_grammar.y"
    {
				MakeTernary(If, ILNode_ToBool_create((yyvsp[(2) - (3)].node)), (yyvsp[(3) - (3)].node),
							ILNode_Empty_create());
			}
    break;

  case 274:
#line 2215 "cs_grammar.y"
    {
				MakeTernary(If, ILNode_ToBool_create((yyvsp[(2) - (5)].node)), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
			}
    break;

  case 275:
#line 2218 "cs_grammar.y"
    {
				MakeTernary(Switch, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), 0);
			}
    break;

  case 276:
#line 2224 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 277:
#line 2225 "cs_grammar.y"
    {
				/*
				 * This production recovers from parse errors in the
				 * body of a switch statement.
				 */
				(yyval.node) = 0;
				yyerrok;
			}
    break;

  case 278:
#line 2236 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 279:
#line 2237 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 280:
#line 2241 "cs_grammar.y"
    { 
				(yyval.node) = ILNode_SwitchSectList_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 281:
#line 2245 "cs_grammar.y"
    {
				/* Append the new section to the list */
				ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 282:
#line 2253 "cs_grammar.y"
    { MakeBinary(SwitchSection, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 283:
#line 2257 "cs_grammar.y"
    {
				/* Create a new label list with one element */
				(yyval.node) = ILNode_CaseList_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 284:
#line 2262 "cs_grammar.y"
    {
				/* Append the new label to the list */
				ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 285:
#line 2270 "cs_grammar.y"
    { MakeUnary(CaseLabel, (yyvsp[(2) - (3)].node)); }
    break;

  case 286:
#line 2271 "cs_grammar.y"
    { MakeSimple(DefaultLabel); }
    break;

  case 287:
#line 2275 "cs_grammar.y"
    {
				MakeBinary(While, ILNode_ToBool_create((yyvsp[(2) - (3)].node)), (yyvsp[(3) - (3)].node));
			}
    break;

  case 288:
#line 2278 "cs_grammar.y"
    {
				MakeBinary(Do, (yyvsp[(2) - (5)].node), ILNode_ToBool_create((yyvsp[(4) - (5)].node)));
			}
    break;

  case 289:
#line 2281 "cs_grammar.y"
    {
				MakeQuaternary(For, (yyvsp[(3) - (6)].node), ILNode_ToBool_create((yyvsp[(4) - (6)].node)), (yyvsp[(5) - (6)].node), (yyvsp[(6) - (6)].node));
				(yyval.node) = ILNode_NewScope_create((yyval.node));
			}
    break;

  case 290:
#line 2285 "cs_grammar.y"
    {
				(yyval.node) = ILNode_NewScope_create
					(ILNode_Foreach_create((yyvsp[(3) - (7)].node), ILQualIdentName((yyvsp[(4) - (7)].node), 0),
										   (yyvsp[(4) - (7)].node), (yyvsp[(6) - (7)].node), (yyvsp[(7) - (7)].node)));
			}
    break;

  case 291:
#line 2293 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 292:
#line 2294 "cs_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 293:
#line 2295 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in the initializer
				 * of a "for" statement.
				 */
				MakeSimple(Empty);
				yyerrok;
			}
    break;

  case 294:
#line 2306 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 295:
#line 2307 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 296:
#line 2311 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 297:
#line 2312 "cs_grammar.y"
    { MakeSimple(True); }
    break;

  case 298:
#line 2313 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in the condition
				 * of a "for" statement.
				 */
				MakeSimple(False);
				yyerrok;
			}
    break;

  case 299:
#line 2324 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 300:
#line 2325 "cs_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 301:
#line 2326 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in the interator
				 * of a "for" statement.
				 */
				MakeSimple(Empty);
				yyerrok;
			}
    break;

  case 302:
#line 2337 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 303:
#line 2338 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in the expression
				 * used within a "foreach" statement.
				 */
				MakeSimple(Null);
				yyerrok;
			}
    break;

  case 304:
#line 2349 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 305:
#line 2350 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 306:
#line 2356 "cs_grammar.y"
    { MakeSimple(Break); }
    break;

  case 307:
#line 2357 "cs_grammar.y"
    { MakeSimple(Continue); }
    break;

  case 308:
#line 2358 "cs_grammar.y"
    {
				/* Convert the identifier node into a "Goto" node */
				(yyval.node) = ILNode_Goto_create(ILQualIdentName((yyvsp[(2) - (3)].node), 0));
			}
    break;

  case 309:
#line 2362 "cs_grammar.y"
    { MakeUnary(GotoCase, (yyvsp[(3) - (4)].node)); }
    break;

  case 310:
#line 2363 "cs_grammar.y"
    { MakeSimple(GotoDefault); }
    break;

  case 311:
#line 2364 "cs_grammar.y"
    { MakeSimple(Return); }
    break;

  case 312:
#line 2365 "cs_grammar.y"
    { MakeUnary(ReturnExpr, (yyvsp[(2) - (3)].node)); }
    break;

  case 313:
#line 2366 "cs_grammar.y"
    { MakeSimple(Throw); }
    break;

  case 314:
#line 2367 "cs_grammar.y"
    { MakeUnary(ThrowExpr, (yyvsp[(2) - (3)].node)); }
    break;

  case 315:
#line 2371 "cs_grammar.y"
    { MakeTernary(Try, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), 0); }
    break;

  case 316:
#line 2372 "cs_grammar.y"
    { MakeTernary(Try, (yyvsp[(2) - (3)].node), 0, (yyvsp[(3) - (3)].node)); }
    break;

  case 317:
#line 2373 "cs_grammar.y"
    { MakeTernary(Try, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 318:
#line 2377 "cs_grammar.y"
    {
				if((yyvsp[(2) - (2)].node))
				{
					ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				}
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 319:
#line 2384 "cs_grammar.y"
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

  case 320:
#line 2399 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 321:
#line 2400 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 322:
#line 2404 "cs_grammar.y"
    {
				(yyval.node) = ILNode_CatchClauses_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 323:
#line 2408 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 324:
#line 2415 "cs_grammar.y"
    {
				(yyval.node) = ILNode_CatchClause_create((yyvsp[(2) - (3)].catchinfo).type, (yyvsp[(2) - (3)].catchinfo).id, (yyvsp[(2) - (3)].catchinfo).idNode, (yyvsp[(3) - (3)].node));
			}
    break;

  case 325:
#line 2421 "cs_grammar.y"
    {
				(yyval.catchinfo).type=ILNode_Identifier_create("Exception");
				(yyval.catchinfo).id = 0;
				(yyval.catchinfo).idNode = 0;
			}
    break;

  case 326:
#line 2426 "cs_grammar.y"
    {
				(yyval.catchinfo).type = (yyvsp[(2) - (4)].node);
				(yyval.catchinfo).id = ILQualIdentName((yyvsp[(3) - (4)].node), 0);
				(yyval.catchinfo).idNode = (yyvsp[(3) - (4)].node);
			}
    break;

  case 327:
#line 2431 "cs_grammar.y"
    {
				(yyval.catchinfo).type = (yyvsp[(2) - (3)].node);
				(yyval.catchinfo).id = 0;
				(yyval.catchinfo).idNode = 0;
			}
    break;

  case 328:
#line 2436 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in catch
				 * variable name declarations.
				 */
				(yyval.catchinfo).type = ILNode_Error_create();
				(yyval.catchinfo).id = 0;
				(yyval.catchinfo).idNode = 0;
				yyerrok;
			}
    break;

  case 329:
#line 2449 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 330:
#line 2450 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 331:
#line 2454 "cs_grammar.y"
    {
				(yyval.node) = ILNode_CatchClause_create(0, 0, 0, (yyvsp[(2) - (2)].node));
			}
    break;

  case 332:
#line 2460 "cs_grammar.y"
    { MakeUnary(FinallyClause, (yyvsp[(2) - (2)].node)); }
    break;

  case 333:
#line 2464 "cs_grammar.y"
    {
				MakeBinary(Lock, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 334:
#line 2470 "cs_grammar.y"
    {
				MakeBinary(Using, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = ILNode_NewScope_create((yyval.node));
			}
    break;

  case 335:
#line 2477 "cs_grammar.y"
    { 
			MakeTernary(ResourceDeclaration,(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].varInit).decl,(yyvsp[(3) - (4)].varInit).init); 
		}
    break;

  case 336:
#line 2480 "cs_grammar.y"
    { 
			(yyval.node) = (yyvsp[(2) - (3)].node);
		}
    break;

  case 337:
#line 2483 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in resource
				 * acquisition declarations.
				 */
				MakeSimple(Error);
				yyerrok;
			}
    break;

  case 338:
#line 2495 "cs_grammar.y"
    {
				MakeTernary(Fixed, (yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
			}
    break;

  case 339:
#line 2501 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 340:
#line 2505 "cs_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (3)].node);
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 341:
#line 2512 "cs_grammar.y"
    {
				/*
				 * Note: we have to handle two cases here.  One where
				 * the expression has the form "&expr", and the other
				 * where it doesn't have that form.  We cannot express
				 * these as two different rules, or it creates a
				 * reduce/reduce conflict with "UnaryExpression".
				 */
				if(yykind((yyvsp[(3) - (3)].node)) == yykindof(ILNode_AddressOf))
				{
					MakeBinary(FixAddress, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
				}
				else
				{
					MakeBinary(FixExpr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				}
			}
    break;

  case 342:
#line 2532 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Empty_create();
				CCError(_("`yield return' is not yet supported"));
			}
    break;

  case 343:
#line 2536 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Empty_create();
				CCError(_("`yield break' is not yet supported"));
			}
    break;

  case 344:
#line 2547 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 345:
#line 2548 "cs_grammar.y"
    { CSValidateDocs((yyvsp[(1) - (1)].node)); MakeUnary(AttributeTree, (yyvsp[(1) - (1)].node)); }
    break;

  case 346:
#line 2552 "cs_grammar.y"
    { CSValidateDocs((yyvsp[(1) - (1)].node)); MakeUnary(AttributeTree, (yyvsp[(1) - (1)].node)); }
    break;

  case 347:
#line 2556 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				if((yyvsp[(1) - (1)].node))
				{
					ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
				}
			}
    break;

  case 348:
#line 2563 "cs_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (2)].node);
				if((yyvsp[(2) - (2)].node))
				{
					ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				}
			}
    break;

  case 349:
#line 2573 "cs_grammar.y"
    {
				MakeTernary(AttributeSection, ILAttrTargetType_None, 0, (yyvsp[(2) - (4)].node));
			}
    break;

  case 350:
#line 2576 "cs_grammar.y"
    {
				MakeTernary(AttributeSection, (yyvsp[(2) - (5)].target).targetType, (yyvsp[(2) - (5)].target).target, (yyvsp[(3) - (5)].node));
			}
    break;

  case 351:
#line 2579 "cs_grammar.y"
    { MakeBinary(DocComment, (yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).len); }
    break;

  case 352:
#line 2580 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in attributes.
				 */
				(yyval.node) = 0;
				yyerrok;
			}
    break;

  case 353:
#line 2590 "cs_grammar.y"
    {
				(yyval.target).targetType = ILAttrTargetType_Named;
				(yyval.target).target = (yyvsp[(1) - (2)].node);
			}
    break;

  case 354:
#line 2594 "cs_grammar.y"
    {
				(yyval.target).targetType = ILAttrTargetType_Event;
				(yyval.target).target = 0;
			}
    break;

  case 355:
#line 2598 "cs_grammar.y"
    {
				(yyval.target).targetType = ILAttrTargetType_Return;
				(yyval.target).target = 0;
			}
    break;

  case 356:
#line 2605 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 357:
#line 2609 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 358:
#line 2616 "cs_grammar.y"
    { 
				MakeBinary(Attribute, (yyvsp[(1) - (1)].node), 0);
			}
    break;

  case 359:
#line 2619 "cs_grammar.y"
    { 
				MakeBinary(Attribute, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
			}
    break;

  case 360:
#line 2625 "cs_grammar.y"
    {	(yyval.node)=0; /* empty */ }
    break;

  case 361:
#line 2626 "cs_grammar.y"
    {
				MakeBinary(AttrArgs, (yyvsp[(2) - (3)].node), 0);
			}
    break;

  case 362:
#line 2629 "cs_grammar.y"
    {
				MakeBinary(AttrArgs, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));
			}
    break;

  case 363:
#line 2632 "cs_grammar.y"
    {
				MakeBinary(AttrArgs, 0, (yyvsp[(2) - (3)].node));
			}
    break;

  case 364:
#line 2638 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create ();
				ILNode_List_Add ((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 365:
#line 2642 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 366:
#line 2649 "cs_grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 367:
#line 2653 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create ();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 368:
#line 2657 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 369:
#line 2664 "cs_grammar.y"
    {
				MakeBinary(NamedArg, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 370:
#line 2670 "cs_grammar.y"
    { (yyval.node) = ILNode_ToAttrConst_create((yyvsp[(1) - (1)].node)); }
    break;

  case 371:
#line 2678 "cs_grammar.y"
    { (yyval.mask) = 0; }
    break;

  case 372:
#line 2679 "cs_grammar.y"
    { (yyval.mask) = (yyvsp[(1) - (1)].mask); }
    break;

  case 373:
#line 2683 "cs_grammar.y"
    { (yyval.mask) = (yyvsp[(1) - (1)].mask); }
    break;

  case 374:
#line 2684 "cs_grammar.y"
    {
				if(((yyvsp[(1) - (2)].mask) & (yyvsp[(2) - (2)].mask)) != 0)
				{
					/* A modifier was used more than once in the list */
					CSModifiersUsedTwice(yycurrfilename(), yycurrlinenum(),
										 ((yyvsp[(1) - (2)].mask) & (yyvsp[(2) - (2)].mask)));
				}
				(yyval.mask) = ((yyvsp[(1) - (2)].mask) | (yyvsp[(2) - (2)].mask));
			}
    break;

  case 375:
#line 2696 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_NEW; }
    break;

  case 376:
#line 2697 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_PUBLIC; }
    break;

  case 377:
#line 2698 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_PROTECTED; }
    break;

  case 378:
#line 2699 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_INTERNAL; }
    break;

  case 379:
#line 2700 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_PRIVATE; }
    break;

  case 380:
#line 2701 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_ABSTRACT; }
    break;

  case 381:
#line 2702 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_SEALED; }
    break;

  case 382:
#line 2703 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_STATIC; }
    break;

  case 383:
#line 2704 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_READONLY; }
    break;

  case 384:
#line 2705 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_VIRTUAL; }
    break;

  case 385:
#line 2706 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_OVERRIDE; }
    break;

  case 386:
#line 2707 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_EXTERN; }
    break;

  case 387:
#line 2708 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_UNSAFE; }
    break;

  case 388:
#line 2709 "cs_grammar.y"
    { (yyval.mask) = CS_MODIFIER_VOLATILE; }
    break;

  case 389:
#line 2718 "cs_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(5) - (8)].node));
			}
    break;

  case 390:
#line 2725 "cs_grammar.y"
    {
				ILNode *classBody = ((yyvsp[(10) - (11)].member)).body;

				/* Validate the modifiers */
				ILUInt32 attrs =
					CSModifiersToTypeAttrs((yyvsp[(5) - (11)].node), (yyvsp[(2) - (11)].mask), (NestingLevel > 1));

				/* Exit the current nesting level */
				--NestingLevel;

				/* Determine if we need to add a default constructor */
				if(!ClassNameIsCtorDefined())
				{
					ILUInt32 ctorMods =
						(((attrs & IL_META_TYPEDEF_ABSTRACT) != 0)
							? CS_MODIFIER_PROTECTED : CS_MODIFIER_PUBLIC);
					ILNode *cname = ILQualIdentSimple
							(ILInternString(".ctor", 5).string);
					ILNode *body = ILNode_NewScope_create
							(ILNode_Compound_CreateFrom
								(ILNode_NonStaticInit_create(),
								 ILNode_InvocationExpression_create
									(ILNode_BaseInit_create(), 0)));
					ILNode *ctor = ILNode_MethodDeclaration_create
						  (0, CSModifiersToConstructorAttrs(cname, ctorMods),
						   0 /* "void" */, cname,
						   ILNode_Empty_create(), body);
					if(!classBody)
					{
						classBody = ILNode_List_create();
					}
					ILNode_List_Add(classBody, ctor);
				}

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (11)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(5) - (11)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 (yyvsp[(6) - (11)].node),					/* TypeFormals */
							 (yyvsp[(7) - (11)].node),					/* ClassBase */
							 classBody,
							 ((yyvsp[(10) - (11)].member)).staticCtors);
				CloneLine((yyval.node), (yyvsp[(5) - (11)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 391:
#line 2782 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 392:
#line 2783 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 393:
#line 2784 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 394:
#line 2788 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 395:
#line 2792 "cs_grammar.y"
    {
				/* Check for duplicates in the list */
				ILNode_ListIter iter;
				ILNode *node;
				ILNode_ListIter_Init(&iter, (yyvsp[(1) - (3)].node));
				while((node = ILNode_ListIter_Next(&iter)) != 0)
				{
					if(!strcmp(ILQualIdentName(node, 0),
							   ILQualIdentName((yyvsp[(3) - (3)].node), 0)))
					{
						CCErrorOnLine(yygetfilename((yyvsp[(3) - (3)].node)), yygetlinenum((yyvsp[(3) - (3)].node)),
						  "`%s' declared multiple times in generic parameters",
						  ILQualIdentName((yyvsp[(3) - (3)].node), 0));
						break;
					}
				}

				/* Add the identifier to the list */
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 400:
#line 2827 "cs_grammar.y"
    { /* TODO */ }
    break;

  case 401:
#line 2828 "cs_grammar.y"
    { /* TODO */ }
    break;

  case 402:
#line 2832 "cs_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				(yyval.node) = ILQualIdentSimple("<Module>");
				ClassNamePush((yyval.node));
			}
    break;

  case 403:
#line 2840 "cs_grammar.y"
    {
				ILNode *classBody = ((yyvsp[(3) - (4)].member)).body;

				/* Get the default modifiers */
				ILUInt32 attrs = IL_META_TYPEDEF_PUBLIC;

				/* Exit the current nesting level */
				--NestingLevel;

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							(0,						/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILInternString("<Module>", -1).string,
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 0,						/* TypeFormals */
							 0,						/* ClassBase */
							 classBody,
							 ((yyvsp[(3) - (4)].member)).staticCtors);
				CloneLine((yyval.node), (yyvsp[(2) - (4)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 404:
#line 2872 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 405:
#line 2873 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 406:
#line 2877 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 407:
#line 2878 "cs_grammar.y"
    { MakeBinary(ArgList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 408:
#line 2882 "cs_grammar.y"
    { (yyval.member) = (yyvsp[(2) - (3)].member); }
    break;

  case 409:
#line 2883 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in class bodies.
				 */
				yyerrok;
				(yyval.member).body = 0;
				(yyval.member).staticCtors = 0;
			}
    break;

  case 410:
#line 2894 "cs_grammar.y"
    { (yyval.member).body = 0; (yyval.member).staticCtors = 0; }
    break;

  case 411:
#line 2895 "cs_grammar.y"
    { (yyval.member) = (yyvsp[(1) - (1)].member); }
    break;

  case 412:
#line 2899 "cs_grammar.y"
    {
				(yyval.member).body = MakeList(0, (yyvsp[(1) - (1)].member).body);
				(yyval.member).staticCtors = MakeList(0, (yyvsp[(1) - (1)].member).staticCtors);
			}
    break;

  case 413:
#line 2903 "cs_grammar.y"
    {
				(yyval.member).body = MakeList((yyvsp[(1) - (2)].member).body, (yyvsp[(2) - (2)].member).body);
				(yyval.member).staticCtors = MakeList((yyvsp[(1) - (2)].member).staticCtors, (yyvsp[(2) - (2)].member).staticCtors);
			}
    break;

  case 414:
#line 2910 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 415:
#line 2911 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 416:
#line 2912 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 417:
#line 2913 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 418:
#line 2914 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 419:
#line 2915 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 420:
#line 2916 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 421:
#line 2917 "cs_grammar.y"
    { (yyval.member) = (yyvsp[(1) - (1)].member); }
    break;

  case 422:
#line 2918 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 423:
#line 2919 "cs_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 424:
#line 2923 "cs_grammar.y"
    { (yyval.partial) = 0; }
    break;

  case 425:
#line 2924 "cs_grammar.y"
    {
				(yyval.partial) = 1;
				CCError(_("partial types are not yet supported"));
			}
    break;

  case 426:
#line 2935 "cs_grammar.y"
    {
				ILUInt32 attrs = CSModifiersToConstAttrs((yyvsp[(4) - (6)].node), (yyvsp[(2) - (6)].mask));
				(yyval.node) = ILNode_FieldDeclaration_create((yyvsp[(1) - (6)].node), attrs, (yyvsp[(4) - (6)].node), (yyvsp[(5) - (6)].node));
			}
    break;

  case 427:
#line 2942 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 428:
#line 2946 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 429:
#line 2953 "cs_grammar.y"
    {
				MakeBinary(FieldDeclarator, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 430:
#line 2963 "cs_grammar.y"
    {
				ILUInt32 attrs = CSModifiersToFieldAttrs((yyvsp[(3) - (5)].node), (yyvsp[(2) - (5)].mask));
				(yyval.node) = ILNode_FieldDeclaration_create((yyvsp[(1) - (5)].node), attrs, (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node));
			}
    break;

  case 431:
#line 2970 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 432:
#line 2974 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 433:
#line 2982 "cs_grammar.y"
    {
				MakeBinary(FieldDeclarator, (yyvsp[(1) - (1)].node), 0);
			}
    break;

  case 434:
#line 2985 "cs_grammar.y"
    {
				MakeBinary(FieldDeclarator, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 435:
#line 2996 "cs_grammar.y"
    {
				ILUInt32 attrs = CSModifiersToMethodAttrs((yyvsp[(3) - (8)].node), (yyvsp[(2) - (8)].mask));
				if((yyvsp[(2) - (8)].mask) & CS_MODIFIER_PRIVATE  && yyisa((yyvsp[(4) - (8)].node), ILNode_QualIdent))
				{
					// NOTE: clean this up later
					CCErrorOnLine(yygetfilename((yyvsp[(3) - (8)].node)), yygetlinenum((yyvsp[(3) - (8)].node)),
						"`private' cannot be used in this context");
				}
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (8)].node), attrs, (yyvsp[(3) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
				CloneLine((yyval.node), (yyvsp[(4) - (8)].node));
			}
    break;

  case 436:
#line 3011 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 437:
#line 3012 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 438:
#line 3016 "cs_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 439:
#line 3017 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 440:
#line 3021 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 441:
#line 3025 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 442:
#line 3032 "cs_grammar.y"
    {
				(yyval.node) = ILNode_FormalParameter_create((yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].pmod), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 443:
#line 3035 "cs_grammar.y"
    {
				(yyval.node) = ILNode_FormalParameter_create(0, ILParamMod_arglist, 0, 0);
			}
    break;

  case 444:
#line 3041 "cs_grammar.y"
    { (yyval.pmod) = ILParamMod_empty;}
    break;

  case 445:
#line 3042 "cs_grammar.y"
    { (yyval.pmod) = ILParamMod_ref;}
    break;

  case 446:
#line 3043 "cs_grammar.y"
    { (yyval.pmod) = ILParamMod_out;}
    break;

  case 447:
#line 3044 "cs_grammar.y"
    { (yyval.pmod) = ILParamMod_params;}
    break;

  case 448:
#line 3053 "cs_grammar.y"
    {
				ILUInt32 attrs;

				/* Create the property declaration */
				attrs = CSModifiersToPropertyAttrs((yyvsp[(3) - (6)].node), (yyvsp[(2) - (6)].mask));
				(yyval.node) = ILNode_PropertyDeclaration_create((yyvsp[(1) - (6)].node),
								   attrs, (yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].node), 0, (yyvsp[(6) - (6)].pair).item1, (yyvsp[(6) - (6)].pair).item2,
								   (((yyvsp[(6) - (6)].pair).item1 ? 1 : 0) |
								    ((yyvsp[(6) - (6)].pair).item2 ? 2 : 0)));
				CloneLine((yyval.node), (yyvsp[(4) - (6)].node));

				/* Create the property method declarations */
				CreatePropertyMethods((ILNode_PropertyDeclaration *)((yyval.node)));
			}
    break;

  case 450:
#line 3074 "cs_grammar.y"
    {
				(yyval.pair) = (yyvsp[(1) - (2)].pair);
			}
    break;

  case 451:
#line 3077 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in accessor blocks.
				 */
				(yyval.pair).item1 = 0;
				(yyval.pair).item2 = 0;
				yyerrok;
			}
    break;

  case 452:
#line 3088 "cs_grammar.y"
    {
				(yyval.pair).item1 = (yyvsp[(1) - (2)].node); 
				(yyval.pair).item2 = (yyvsp[(2) - (2)].node);
			}
    break;

  case 453:
#line 3092 "cs_grammar.y"
    {
				(yyval.pair).item1 = (yyvsp[(2) - (2)].node); 
				(yyval.pair).item2 = (yyvsp[(1) - (2)].node);
			}
    break;

  case 454:
#line 3099 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 455:
#line 3100 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 456:
#line 3104 "cs_grammar.y"
    {
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (3)].node), 0, 0, 0, 0, (yyvsp[(3) - (3)].node));
			#ifdef YYBISON
				yysetlinenum((yyval.node), (yylsp[(2) - (3)]).first_line);
			#endif
			}
    break;

  case 457:
#line 3114 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 458:
#line 3115 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 459:
#line 3119 "cs_grammar.y"
    {
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (3)].node), 0, 0, 0, 0, (yyvsp[(3) - (3)].node));
			#ifdef YYBISON
				yysetlinenum((yyval.node), (yylsp[(2) - (3)]).first_line);
			#endif
			}
    break;

  case 460:
#line 3129 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 461:
#line 3130 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 464:
#line 3143 "cs_grammar.y"
    {
				ILUInt32 attrs = CSModifiersToEventAttrs((yyvsp[(4) - (6)].node), (yyvsp[(2) - (6)].mask));
				(yyval.node) = ILNode_EventDeclaration_create((yyvsp[(1) - (6)].node), attrs, (yyvsp[(4) - (6)].node), (yyvsp[(5) - (6)].node));
				CreateEventMethods((ILNode_EventDeclaration *)((yyval.node)));
			}
    break;

  case 465:
#line 3151 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 466:
#line 3155 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 467:
#line 3163 "cs_grammar.y"
    {
				(yyval.node) = ILNode_EventDeclarator_create
						(ILNode_FieldDeclarator_create((yyvsp[(1) - (1)].node), 0), 0, 0);
			}
    break;

  case 468:
#line 3167 "cs_grammar.y"
    {
				(yyval.node) = ILNode_EventDeclarator_create
						(ILNode_FieldDeclarator_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), 0, 0);
			}
    break;

  case 469:
#line 3175 "cs_grammar.y"
    {
				ILUInt32 attrs = CSModifiersToEventAttrs((yyvsp[(4) - (7)].node), (yyvsp[(2) - (7)].mask));
				(yyval.node) = ILNode_EventDeclaration_create
					((yyvsp[(1) - (7)].node), attrs, (yyvsp[(4) - (7)].node), 
						ILNode_EventDeclarator_create
							(ILNode_FieldDeclarator_create((yyvsp[(5) - (7)].node), 0),
							 (yyvsp[(7) - (7)].pair).item1, (yyvsp[(7) - (7)].pair).item2));
				CloneLine((yyval.node), (yyvsp[(5) - (7)].node));
				CreateEventMethods((ILNode_EventDeclaration *)((yyval.node)));
			}
    break;

  case 470:
#line 3188 "cs_grammar.y"
    {
				(yyval.pair) = (yyvsp[(1) - (2)].pair);
			}
    break;

  case 471:
#line 3191 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in accessor blocks.
				 */
				(yyval.pair).item1 = 0;
				(yyval.pair).item2 = 0;
				yyerrok;
			}
    break;

  case 472:
#line 3202 "cs_grammar.y"
    {
				(yyval.pair).item1 = (yyvsp[(1) - (2)].node);
				(yyval.pair).item2 = (yyvsp[(2) - (2)].node);
			}
    break;

  case 473:
#line 3206 "cs_grammar.y"
    {
				(yyval.pair).item1 = (yyvsp[(2) - (2)].node);
				(yyval.pair).item2 = (yyvsp[(1) - (2)].node);
			}
    break;

  case 474:
#line 3213 "cs_grammar.y"
    {
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (3)].node), 0, 0, 0, 0, (yyvsp[(3) - (3)].node));
			#ifdef YYBISION
				yysetlinenum((yyval.node), (yylsp[(2) - (3)]).first_line);
			#endif
			}
    break;

  case 475:
#line 3223 "cs_grammar.y"
    {
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (3)].node), 0, 0, 0, 0, (yyvsp[(3) - (3)].node));
			#ifdef YYBISION
				yysetlinenum((yyval.node), (yylsp[(2) - (3)]).first_line);
			#endif
			}
    break;

  case 476:
#line 3238 "cs_grammar.y"
    {
				ILNode* name=GetIndexerName(&CCCodeGen,(ILNode_AttributeTree*)(yyvsp[(1) - (5)].node),
							(yyvsp[(3) - (5)].indexer).ident);
				ILUInt32 attrs = CSModifiersToPropertyAttrs((yyvsp[(3) - (5)].indexer).type, (yyvsp[(2) - (5)].mask));
				(yyval.node) = ILNode_PropertyDeclaration_create((yyvsp[(1) - (5)].node),
								   attrs, (yyvsp[(3) - (5)].indexer).type, name, (yyvsp[(3) - (5)].indexer).params,
								   (yyvsp[(5) - (5)].pair).item1, (yyvsp[(5) - (5)].pair).item2,
								   (((yyvsp[(5) - (5)].pair).item1 ? 1 : 0) |
								    ((yyvsp[(5) - (5)].pair).item2 ? 2 : 0)));
				CloneLine((yyval.node), (yyvsp[(3) - (5)].indexer).ident);

				/* Create the property method declarations */
				CreatePropertyMethods((ILNode_PropertyDeclaration *)((yyval.node)));
			}
    break;

  case 477:
#line 3255 "cs_grammar.y"
    {
				(yyval.indexer).type = (yyvsp[(1) - (3)].node);
				(yyval.indexer).ident = ILQualIdentSimple(NULL);
				(yyval.indexer).params = (yyvsp[(3) - (3)].node);
			}
    break;

  case 478:
#line 3260 "cs_grammar.y"
    {
				(yyval.indexer).type = (yyvsp[(1) - (5)].node);
				(yyval.indexer).ident = (yyvsp[(2) - (5)].node);
				(yyval.indexer).params = (yyvsp[(5) - (5)].node);
			}
    break;

  case 479:
#line 3268 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 480:
#line 3269 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in indexer parameters.
				 */
				(yyval.node) = 0;
				yyerrok;
			}
    break;

  case 481:
#line 3279 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create ();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 482:
#line 3283 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 483:
#line 3290 "cs_grammar.y"
    {
				(yyval.node) = ILNode_FormalParameter_create((yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].pmod), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 484:
#line 3293 "cs_grammar.y"
    {
				(yyval.node) = ILNode_FormalParameter_create(0, ILParamMod_arglist, 0, 0);
			}
    break;

  case 485:
#line 3303 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 486:
#line 3304 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 487:
#line 3309 "cs_grammar.y"
    {
				ILUInt32 attrs;
				ILNode *params;

				/* TODO: generic parameters */

				/* Validate the name of the unary operator */
				if((yyvsp[(5) - (11)].opName).unary == 0)
				{
					CCError("overloadable unary operator expected");
					(yyvsp[(5) - (11)].opName).unary = (yyvsp[(5) - (11)].opName).binary;
				}

				/* Get the operator attributes */
				attrs = CSModifiersToOperatorAttrs((yyvsp[(3) - (11)].node), (yyvsp[(2) - (11)].mask));

				/* Build the formal parameter list */
				params = ILNode_List_create();
				ILNode_List_Add(params,
					ILNode_FormalParameter_create(0, ILParamMod_empty, (yyvsp[(8) - (11)].node), (yyvsp[(9) - (11)].node)));

				/* Create a method definition for the operator */
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (11)].node), attrs, (yyvsp[(3) - (11)].node),
						 ILQualIdentSimple(ILInternString((yyvsp[(5) - (11)].opName).unary, -1).string),
						 params, (yyvsp[(11) - (11)].node));
				CloneLine((yyval.node), (yyvsp[(3) - (11)].node));
			}
    break;

  case 488:
#line 3338 "cs_grammar.y"
    {
				ILUInt32 attrs;
				ILNode *params;

				/* TODO: generic parameters */

				/* Validate the name of the binary operator */
				if((yyvsp[(5) - (14)].opName).binary == 0)
				{
					CCError("overloadable binary operator expected");
					(yyvsp[(5) - (14)].opName).binary = (yyvsp[(5) - (14)].opName).unary;
				}

				/* Get the operator attributes */
				attrs = CSModifiersToOperatorAttrs((yyvsp[(3) - (14)].node), (yyvsp[(2) - (14)].mask));

				/* Build the formal parameter list */
				params = ILNode_List_create();
				ILNode_List_Add(params,
					ILNode_FormalParameter_create
						(0, ILParamMod_empty, (yyvsp[(8) - (14)].node), (yyvsp[(9) - (14)].node)));
				ILNode_List_Add(params,
					ILNode_FormalParameter_create
						(0, ILParamMod_empty, (yyvsp[(11) - (14)].node), (yyvsp[(12) - (14)].node)));

				/* Create a method definition for the operator */
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (14)].node), attrs, (yyvsp[(3) - (14)].node),
						 ILQualIdentSimple
						 	(ILInternString((yyvsp[(5) - (14)].opName).binary, -1).string),
						 params, (yyvsp[(14) - (14)].node));
				CloneLine((yyval.node), (yyvsp[(3) - (14)].node));
			}
    break;

  case 489:
#line 3374 "cs_grammar.y"
    { (yyval.opName).binary = "op_Addition"; (yyval.opName).unary = "op_UnaryPlus"; }
    break;

  case 490:
#line 3375 "cs_grammar.y"
    { (yyval.opName).binary = "op_Subtraction"; (yyval.opName).unary = "op_UnaryNegation"; }
    break;

  case 491:
#line 3376 "cs_grammar.y"
    { (yyval.opName).binary = 0; (yyval.opName).unary = "op_LogicalNot"; }
    break;

  case 492:
#line 3377 "cs_grammar.y"
    { (yyval.opName).binary = 0; (yyval.opName).unary = "op_OnesComplement"; }
    break;

  case 493:
#line 3378 "cs_grammar.y"
    { (yyval.opName).binary = 0; (yyval.opName).unary = "op_Increment"; }
    break;

  case 494:
#line 3379 "cs_grammar.y"
    { (yyval.opName).binary = 0; (yyval.opName).unary = "op_Decrement"; }
    break;

  case 495:
#line 3380 "cs_grammar.y"
    { (yyval.opName).binary = 0; (yyval.opName).unary = "op_True"; }
    break;

  case 496:
#line 3381 "cs_grammar.y"
    { (yyval.opName).binary = 0; (yyval.opName).unary = "op_False"; }
    break;

  case 497:
#line 3382 "cs_grammar.y"
    { (yyval.opName).binary = "op_Multiply"; (yyval.opName).unary = 0; }
    break;

  case 498:
#line 3383 "cs_grammar.y"
    { (yyval.opName).binary = "op_Division"; (yyval.opName).unary = 0; }
    break;

  case 499:
#line 3384 "cs_grammar.y"
    { (yyval.opName).binary = "op_Modulus"; (yyval.opName).unary = 0; }
    break;

  case 500:
#line 3385 "cs_grammar.y"
    { (yyval.opName).binary = "op_BitwiseAnd"; (yyval.opName).unary = 0; }
    break;

  case 501:
#line 3386 "cs_grammar.y"
    { (yyval.opName).binary = "op_BitwiseOr"; (yyval.opName).unary = 0; }
    break;

  case 502:
#line 3387 "cs_grammar.y"
    { (yyval.opName).binary = "op_ExclusiveOr"; (yyval.opName).unary = 0; }
    break;

  case 503:
#line 3388 "cs_grammar.y"
    { (yyval.opName).binary = "op_LeftShift"; (yyval.opName).unary = 0; }
    break;

  case 504:
#line 3389 "cs_grammar.y"
    { (yyval.opName).binary = "op_RightShift"; (yyval.opName).unary = 0; }
    break;

  case 505:
#line 3390 "cs_grammar.y"
    { (yyval.opName).binary = "op_Equality"; (yyval.opName).unary = 0; }
    break;

  case 506:
#line 3391 "cs_grammar.y"
    { (yyval.opName).binary = "op_Inequality"; (yyval.opName).unary = 0; }
    break;

  case 507:
#line 3392 "cs_grammar.y"
    { (yyval.opName).binary = "op_GreaterThan"; (yyval.opName).unary = 0; }
    break;

  case 508:
#line 3393 "cs_grammar.y"
    { (yyval.opName).binary = "op_LessThan"; (yyval.opName).unary = 0; }
    break;

  case 509:
#line 3394 "cs_grammar.y"
    { (yyval.opName).binary = "op_GreaterThanOrEqual"; (yyval.opName).unary = 0; }
    break;

  case 510:
#line 3395 "cs_grammar.y"
    { (yyval.opName).binary = "op_LessThanOrEqual"; (yyval.opName).unary = 0; }
    break;

  case 511:
#line 3400 "cs_grammar.y"
    {
				ILUInt32 attrs;
				ILNode *params;

				/* TODO: generic parameters */

				/* Get the operator attributes */
				attrs = CSModifiersToOperatorAttrs((yyvsp[(6) - (11)].node), (yyvsp[(2) - (11)].mask));

				/* Build the formal parameter list */
				params = ILNode_List_create();
				ILNode_List_Add(params,
					ILNode_FormalParameter_create(0, ILParamMod_empty, (yyvsp[(8) - (11)].node), (yyvsp[(9) - (11)].node)));

				/* Create a method definition for the operator */
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (11)].node), attrs, (yyvsp[(6) - (11)].node),
						 ILQualIdentSimple
						 	(ILInternString("op_Implicit", -1).string),
						 params, (yyvsp[(11) - (11)].node));
				CloneLine((yyval.node), (yyvsp[(6) - (11)].node));
			}
    break;

  case 512:
#line 3423 "cs_grammar.y"
    {
				ILUInt32 attrs;
				ILNode *params;

				/* TODO: generic parameters */

				/* Get the operator attributes */
				attrs = CSModifiersToOperatorAttrs((yyvsp[(6) - (11)].node), (yyvsp[(2) - (11)].mask));

				/* Build the formal parameter list */
				params = ILNode_List_create();
				ILNode_List_Add(params,
					ILNode_FormalParameter_create(0, ILParamMod_empty, (yyvsp[(8) - (11)].node), (yyvsp[(9) - (11)].node)));

				/* Create a method definition for the operator */
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (11)].node), attrs, (yyvsp[(6) - (11)].node),
						 ILQualIdentSimple
						 	(ILInternString("op_Explicit", -1).string),
						 params, (yyvsp[(11) - (11)].node));
				CloneLine((yyval.node), (yyvsp[(6) - (11)].node));
			}
    break;

  case 513:
#line 3453 "cs_grammar.y"
    {
				ILUInt32 attrs = CSModifiersToConstructorAttrs((yyvsp[(3) - (8)].node), (yyvsp[(2) - (8)].mask));
				ILNode *ctorName;
				ILNode *cname;
				ILNode *initializer = (yyvsp[(7) - (8)].node);
				ILNode *body;
				if((attrs & IL_META_METHODDEF_STATIC) != 0)
				{
					cname = ILQualIdentSimple
								(ILInternString(".cctor", 6).string);
					initializer = 0;
				}
				else
				{
					cname = ILQualIdentSimple
								(ILInternString(".ctor", 5).string);
					ClassNameCtorDefined();
				}
				ctorName = (yyvsp[(3) - (8)].node);
				if(yyisa(ctorName, ILNode_GenericReference))
				{
					CCErrorOnLine(yygetfilename((yyvsp[(3) - (8)].node)), yygetlinenum((yyvsp[(3) - (8)].node)),
						"constructors cannot have type parameters");
					ctorName = ((ILNode_GenericReference *)ctorName)->type;
				}
				if(!ClassNameSame(ctorName))
				{
					CCErrorOnLine(yygetfilename((yyvsp[(3) - (8)].node)), yygetlinenum((yyvsp[(3) - (8)].node)),
						"constructor name does not match class name");
				}
				if((yyvsp[(8) - (8)].node) && yykind((yyvsp[(8) - (8)].node)) == yykindof(ILNode_NewScope))
				{
					/* Push the initializer into the body scope */
					body = (yyvsp[(8) - (8)].node);
					((ILNode_NewScope *)body)->stmt =
						ILNode_Compound_CreateFrom
							(initializer, ((ILNode_NewScope *)body)->stmt);
				}
				else if((yyvsp[(8) - (8)].node) || (attrs & CS_SPECIALATTR_EXTERN) == 0)
				{
					/* Non-scoped body: create a new scoped body */
					body = ILNode_NewScope_create
								(ILNode_Compound_CreateFrom(initializer, (yyvsp[(8) - (8)].node)));
					CCWarningOnLine(yygetfilename((yyvsp[(3) - (8)].node)), yygetlinenum((yyvsp[(3) - (8)].node)),
						"constructor without body should be declared 'extern'");
				}
				else
				{
					/* Extern constructor with an empty body */
					body = 0;
				}
				if((attrs & IL_META_METHODDEF_STATIC) != 0)
				{
					if(!yyisa((yyvsp[(5) - (8)].node),ILNode_Empty))
					{
						CCErrorOnLine(yygetfilename((yyvsp[(3) - (8)].node)), yygetlinenum((yyvsp[(3) - (8)].node)),
								"Static constructors cannot have parameters");
					}
					(yyval.member).body = 0;
					(yyval.member).staticCtors = body;
				}
				else
				{
					(yyval.member).body = ILNode_MethodDeclaration_create
						  ((yyvsp[(1) - (8)].node), attrs, 0 /* "void" */, cname, (yyvsp[(5) - (8)].node), body);
					CloneLine((yyval.member).body, (yyvsp[(3) - (8)].node));
					(yyval.member).staticCtors = 0;
				}
			}
    break;

  case 514:
#line 3525 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom
						(ILNode_NonStaticInit_create(),
						 ILNode_InvocationExpression_create
							(ILNode_BaseInit_create(), 0));
			}
    break;

  case 515:
#line 3531 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom
						(ILNode_NonStaticInit_create(),
						 ILNode_InvocationExpression_create
							(ILNode_BaseInit_create(), (yyvsp[(4) - (5)].node)));
			}
    break;

  case 516:
#line 3537 "cs_grammar.y"
    {
				MakeBinary(InvocationExpression, ILNode_ThisInit_create(), (yyvsp[(4) - (5)].node));
			}
    break;

  case 517:
#line 3543 "cs_grammar.y"
    {
				ILUInt32 attrs;
				ILNode *dtorName;
				ILNode *name;
				ILNode *body;

				/* Destructors cannot have type parameters */
				dtorName = (yyvsp[(4) - (7)].node);
				if(yyisa(dtorName, ILNode_GenericReference))
				{
					CCErrorOnLine(yygetfilename((yyvsp[(4) - (7)].node)), yygetlinenum((yyvsp[(4) - (7)].node)),
						"destructors cannot have type parameters");
					dtorName = ((ILNode_GenericReference *)dtorName)->type;
				}

				/* Validate the destructor name */
				if(!ClassNameSame(dtorName))
				{
					CCErrorOnLine(yygetfilename((yyvsp[(4) - (7)].node)), yygetlinenum((yyvsp[(4) - (7)].node)),
						"destructor name does not match class name");
				}

				/* Build the list of attributes needed on "Finalize" */
				attrs = CSModifiersToDestructorAttrs((yyvsp[(4) - (7)].node),(yyvsp[(2) - (7)].mask));

				/* Build the name of the "Finalize" method */
				name = ILQualIdentSimple(ILInternString("Finalize", -1).string);

				/* Destructors must always call their parent finalizer
				   even if an exception occurs.  We force this to happen
				   by wrapping the method body with a try block whose
				   finally clause always calls its parent */
				/* Note: BaseDestructor filters out these calls for 
						 System.Object class */
				body = ILNode_BaseDestructor_create(
							ILNode_InvocationExpression_create
							(ILNode_BaseAccess_create(name), 0));
				body = ILNode_Try_create
							((yyvsp[(7) - (7)].node), 0, ILNode_FinallyClause_create(body));

				/* Construct the finalizer declaration */
				(yyval.node) = ILNode_MethodDeclaration_create
							((yyvsp[(1) - (7)].node), attrs, 0 /* void */,
							 ILQualIdentSimple
							 	(ILInternString("Finalize", -1).string),
							 0, body);
				CloneLine((yyval.node), (yyvsp[(4) - (7)].node));
			}
    break;

  case 518:
#line 3599 "cs_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(5) - (8)].node));
			}
    break;

  case 519:
#line 3606 "cs_grammar.y"
    {
				ILNode *baseList;
				ILUInt32 attrs;

				/* Validate the modifiers */
				attrs = CSModifiersToTypeAttrs((yyvsp[(5) - (11)].node), (yyvsp[(2) - (11)].mask), (NestingLevel > 1));

				/* Add extra attributes that structs need */
				attrs |= IL_META_TYPEDEF_LAYOUT_SEQUENTIAL |
						 IL_META_TYPEDEF_SERIALIZABLE |
						 IL_META_TYPEDEF_SEALED;

				/* Exit the current nesting level */
				--NestingLevel;

				/* Make sure that we have "ValueType" in the base list */
				baseList = MakeSystemType("ValueType");
				if((yyvsp[(7) - (11)].node) != 0)
				{
					baseList = ILNode_ArgList_create((yyvsp[(7) - (11)].node), baseList);
				}

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (11)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(5) - (11)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 (yyvsp[(6) - (11)].node),					/* TypeFormals */
							 baseList,				/* ClassBase */
							 ((yyvsp[(10) - (11)].member)).body,				/* StructBody */
							 ((yyvsp[(10) - (11)].member)).staticCtors);		/* StaticCtors */
				CloneLine((yyval.node), (yyvsp[(5) - (11)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 520:
#line 3651 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 521:
#line 3652 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 522:
#line 3656 "cs_grammar.y"
    { (yyval.member) = (yyvsp[(2) - (3)].member); }
    break;

  case 523:
#line 3657 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in struct declarations.
				 */
				(yyval.member).body = 0;
				(yyval.member).staticCtors = 0;
				yyerrok;
			}
    break;

  case 524:
#line 3673 "cs_grammar.y"
    {
				/* Increase the nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(5) - (8)].node));
			}
    break;

  case 525:
#line 3680 "cs_grammar.y"
    {
				/* Validate the modifiers */
				ILUInt32 attrs =
					CSModifiersToTypeAttrs((yyvsp[(5) - (11)].node), (yyvsp[(2) - (11)].mask), (NestingLevel > 1));

				/* Add extra attributes that interfaces need */
				attrs |= IL_META_TYPEDEF_INTERFACE |
						 IL_META_TYPEDEF_ABSTRACT;

				/* Exit from the current nesting level */
				--NestingLevel;

				/* Create the interface definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (11)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(5) - (11)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 (yyvsp[(6) - (11)].node),					/* TypeFormals */
							 (yyvsp[(7) - (11)].node),					/* ClassBase */
							 (yyvsp[(10) - (11)].node),					/* InterfaceBody */
							 0);					/* StaticCtors */
				CloneLine((yyval.node), (yyvsp[(5) - (11)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 526:
#line 3715 "cs_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 527:
#line 3716 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 528:
#line 3720 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 529:
#line 3721 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in interface
				 * declarations.
				 */
				(yyval.node) = 0;
				yyerrok;
			}
    break;

  case 530:
#line 3732 "cs_grammar.y"
    { (yyval.node) = 0;}
    break;

  case 531:
#line 3733 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 532:
#line 3737 "cs_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 533:
#line 3741 "cs_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 534:
#line 3748 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 535:
#line 3749 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 536:
#line 3750 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 537:
#line 3751 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 538:
#line 3755 "cs_grammar.y"
    {
				ILUInt32 attrs = ((yyvsp[(2) - (8)].mask) ? CS_SPECIALATTR_NEW : 0) |
								 IL_META_METHODDEF_PUBLIC |
								 IL_META_METHODDEF_VIRTUAL |
								 IL_META_METHODDEF_ABSTRACT |
								 IL_META_METHODDEF_HIDE_BY_SIG |
								 IL_META_METHODDEF_NEW_SLOT;
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (8)].node), attrs, (yyvsp[(3) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node), 0);
				CloneLine((yyval.node), (yyvsp[(4) - (8)].node));
			}
    break;

  case 539:
#line 3769 "cs_grammar.y"
    { (yyval.mask) = 0; }
    break;

  case 540:
#line 3770 "cs_grammar.y"
    { (yyval.mask) = 1; }
    break;

  case 541:
#line 3775 "cs_grammar.y"
    {
				ILUInt32 attrs = ((yyvsp[(2) - (6)].mask) ? CS_SPECIALATTR_NEW : 0) |
								 IL_META_METHODDEF_PUBLIC |
								 IL_META_METHODDEF_VIRTUAL |
								 IL_META_METHODDEF_ABSTRACT |
								 IL_META_METHODDEF_HIDE_BY_SIG |
								 IL_META_METHODDEF_SPECIAL_NAME |
								 IL_META_METHODDEF_NEW_SLOT;
				(yyval.node) = ILNode_PropertyDeclaration_create
								((yyvsp[(1) - (6)].node), attrs, (yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].node), 0, 0, 0, (yyvsp[(6) - (6)].mask));
				CloneLine((yyval.node), (yyvsp[(4) - (6)].node));

				/* Create the property method declarations */
				CreatePropertyMethods((ILNode_PropertyDeclaration *)((yyval.node)));
			}
    break;

  case 543:
#line 3797 "cs_grammar.y"
    {
				(yyval.mask) = (yyvsp[(1) - (2)].mask);
			}
    break;

  case 544:
#line 3800 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in interface
				 * accessor declarations.
				 */
				(yyval.mask) = 0;
				yyerrok;
			}
    break;

  case 545:
#line 3811 "cs_grammar.y"
    { (yyval.mask) = 1; }
    break;

  case 546:
#line 3812 "cs_grammar.y"
    { (yyval.mask) = 2; }
    break;

  case 547:
#line 3813 "cs_grammar.y"
    { (yyval.mask) = 3; }
    break;

  case 548:
#line 3814 "cs_grammar.y"
    { (yyval.mask) = 3; }
    break;

  case 549:
#line 3818 "cs_grammar.y"
    {
				ILUInt32 attrs = ((yyvsp[(2) - (6)].mask) ? CS_SPECIALATTR_NEW : 0) |
								 IL_META_METHODDEF_PUBLIC |
								 IL_META_METHODDEF_VIRTUAL |
								 IL_META_METHODDEF_ABSTRACT |
								 IL_META_METHODDEF_HIDE_BY_SIG |
								 IL_META_METHODDEF_NEW_SLOT;
				(yyval.node) = ILNode_EventDeclaration_create
							((yyvsp[(1) - (6)].node), attrs, (yyvsp[(4) - (6)].node),
							 ILNode_EventDeclarator_create
							 	(ILNode_FieldDeclarator_create((yyvsp[(5) - (6)].node), 0), 0, 0));
				CreateEventMethods((ILNode_EventDeclaration *)((yyval.node)));
			}
    break;

  case 550:
#line 3835 "cs_grammar.y"
    {
				ILUInt32 attrs = ((yyvsp[(2) - (7)].mask) ? CS_SPECIALATTR_NEW : 0) |
								 IL_META_METHODDEF_PUBLIC |
								 IL_META_METHODDEF_VIRTUAL |
								 IL_META_METHODDEF_ABSTRACT |
								 IL_META_METHODDEF_HIDE_BY_SIG |
								 IL_META_METHODDEF_SPECIAL_NAME |
								 IL_META_METHODDEF_NEW_SLOT;
				ILNode* name=GetIndexerName(&CCCodeGen,(ILNode_AttributeTree*)(yyvsp[(1) - (7)].node),
								ILQualIdentSimple(NULL));
				(yyval.node) = ILNode_PropertyDeclaration_create
								((yyvsp[(1) - (7)].node), attrs, (yyvsp[(3) - (7)].node), name, (yyvsp[(5) - (7)].node), 0, 0, (yyvsp[(7) - (7)].mask));
				CloneLine((yyval.node), (yyvsp[(3) - (7)].node));

				/* Create the property method declarations */
				CreatePropertyMethods((ILNode_PropertyDeclaration *)((yyval.node)));
			}
    break;

  case 551:
#line 3859 "cs_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(4) - (5)].node));
			}
    break;

  case 552:
#line 3866 "cs_grammar.y"
    {
				ILNode *baseList;
				ILNode *bodyList;
				ILNode *fieldDecl;
				ILUInt32 attrs;

				/* Validate the modifiers */
				attrs = CSModifiersToTypeAttrs((yyvsp[(4) - (8)].node), (yyvsp[(2) - (8)].mask), (NestingLevel > 1));

				/* Add extra attributes that enums need */
				attrs |= IL_META_TYPEDEF_SERIALIZABLE |
						 IL_META_TYPEDEF_SEALED;

				/* Exit the current nesting level */
				--NestingLevel;

				/* Make sure that we have "Enum" in the base list */
				baseList = MakeSystemType("Enum");

				/* Add an instance field called "value__" to the body,
				   which is used to hold the enumerated value */
				bodyList = (yyvsp[(7) - (8)].node);
				if(!bodyList)
				{
					bodyList = ILNode_List_create();
				}
				fieldDecl = ILNode_List_create();
				ILNode_List_Add(fieldDecl,
					ILNode_FieldDeclarator_create
						(ILQualIdentSimple("value__"), 0));
				MakeBinary(FieldDeclarator, (yyvsp[(1) - (8)].node), 0);
				ILNode_List_Add(bodyList,
					ILNode_FieldDeclaration_create
						(0, IL_META_FIELDDEF_PUBLIC |
							IL_META_FIELDDEF_SPECIAL_NAME |
							IL_META_FIELDDEF_RT_SPECIAL_NAME, (yyvsp[(5) - (8)].node), fieldDecl));

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (8)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(4) - (8)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 0,						/* TypeFormals */
							 baseList,				/* ClassBase */
							 bodyList,				/* EnumBody */
							 0);					/* StaticCtors */
				CloneLine((yyval.node), (yyvsp[(4) - (8)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 553:
#line 3926 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I4); }
    break;

  case 554:
#line 3927 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 555:
#line 3931 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U1); }
    break;

  case 556:
#line 3932 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I1); }
    break;

  case 557:
#line 3933 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I2); }
    break;

  case 558:
#line 3934 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U2); }
    break;

  case 559:
#line 3935 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I4); }
    break;

  case 560:
#line 3936 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U4); }
    break;

  case 561:
#line 3937 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_I8); }
    break;

  case 562:
#line 3938 "cs_grammar.y"
    { MakeUnary(PrimitiveType, IL_META_ELEMTYPE_U8); }
    break;

  case 563:
#line 3942 "cs_grammar.y"
    {
				(yyval.node) = (yyvsp[(2) - (3)].node);
			}
    break;

  case 564:
#line 3945 "cs_grammar.y"
    {
				(yyval.node) = (yyvsp[(2) - (4)].node);
			}
    break;

  case 565:
#line 3948 "cs_grammar.y"
    {
				/*
				 * This production recovers from errors in enum declarations.
				 */
				(yyval.node) = 0;
				yyerrok;
			}
    break;

  case 566:
#line 3958 "cs_grammar.y"
    { (yyval.node) = 0;}
    break;

  case 567:
#line 3959 "cs_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 568:
#line 3963 "cs_grammar.y"
    {
			(yyval.node) = ILNode_List_create ();
			ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
		}
    break;

  case 569:
#line 3967 "cs_grammar.y"
    {
			ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			(yyval.node) = (yyvsp[(1) - (3)].node);
		}
    break;

  case 570:
#line 3974 "cs_grammar.y"
    {
			(yyval.node) = ILNode_EnumMemberDeclaration_create((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0);
		}
    break;

  case 571:
#line 3977 "cs_grammar.y"
    {
			(yyval.node) = ILNode_EnumMemberDeclaration_create((yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
		}
    break;

  case 572:
#line 3988 "cs_grammar.y"
    {
				ILNode *baseList;
				ILNode *bodyList;
				ILUInt32 attrs;

				/* Validate the modifiers */
				attrs = CSModifiersToDelegateAttrs((yyvsp[(5) - (10)].node), (yyvsp[(2) - (10)].mask), (NestingLevel > 0));

				/* Make sure that we have "MulticastDelegate"
				   in the base list */
				baseList = MakeSystemType("MulticastDelegate");

				/* Construct the body of the delegate class */
				bodyList = ILNode_List_create();
				ILNode_List_Add(bodyList,
					ILNode_DelegateMemberDeclaration_create((yyvsp[(4) - (10)].node), (yyvsp[(8) - (10)].node)));

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (10)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(5) - (10)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 (yyvsp[(6) - (10)].node),					/* TypeFormals */
							 baseList,				/* ClassBase */
							 bodyList,				/* Body */
							 0);					/* StaticCtors */
				CloneLine((yyval.node), (yyvsp[(5) - (10)].node));

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 573:
#line 4029 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Null_create();
				CCError(_("anonymous methods are not yet supported"));
			}
    break;

  case 574:
#line 4033 "cs_grammar.y"
    {
				(yyval.node) = ILNode_Null_create();
				CCError(_("anonymous methods are not yet supported"));
			}
    break;


/* Line 1267 of yacc.c.  */
#line 8733 "cs_grammar.c"
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



