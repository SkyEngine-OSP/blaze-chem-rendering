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
     TYPED_IDENTIFIER = 259,
     INTEGER_CONSTANT = 260,
     FLOAT_CONSTANT = 261,
     DECIMAL_CONSTANT = 262,
     CHAR_LITERAL = 263,
     STRING_LITERAL = 264,
     END_LINE = 265,
     CONCAT_ASSIGN_OP = 266,
     MUL_ASSIGN_OP = 267,
     DIV_ASSIGN_OP = 268,
     IDIV_ASSIGN_OP = 269,
     POW_ASSIGN_OP = 270,
     ADD_ASSIGN_OP = 271,
     SUB_ASSIGN_OP = 272,
     NE_OP = 273,
     LE_OP = 274,
     GE_OP = 275,
     EQ_OP = 276,
     LEFT_OP = 277,
     RIGHT_OP = 278,
     K_ADDHANDLER = 279,
     K_ADDRESSOF = 280,
     K_ALIAS = 281,
     K_AND = 282,
     K_ANDALSO = 283,
     K_ANSI = 284,
     K_AS = 285,
     K_ASSEMBLY = 286,
     K_AUTO = 287,
     K_BOOLEAN = 288,
     K_BYREF = 289,
     K_BYTE = 290,
     K_BYVAL = 291,
     K_CALL = 292,
     K_CASE = 293,
     K_CATCH = 294,
     K_CBOOL = 295,
     K_CBYTE = 296,
     K_CCHAR = 297,
     K_CDATE = 298,
     K_CDEC = 299,
     K_CDBL = 300,
     K_CHAR = 301,
     K_CINT = 302,
     K_CLASS = 303,
     K_CLNG = 304,
     K_COBJ = 305,
     K_CONST = 306,
     K_CSHORT = 307,
     K_CSNG = 308,
     K_CSTR = 309,
     K_CTYPE = 310,
     K_DATE = 311,
     K_DECIMAL = 312,
     K_DECLARE = 313,
     K_DEFAULT = 314,
     K_DELEGATE = 315,
     K_DIM = 316,
     K_DIRECTCAST = 317,
     K_DO = 318,
     K_DOUBLE = 319,
     K_EACH = 320,
     K_ELSE = 321,
     K_ELSEIF = 322,
     K_END = 323,
     K_ENUM = 324,
     K_ERASE = 325,
     K_ERROR = 326,
     K_EVENT = 327,
     K_EXIT = 328,
     K_FALSE = 329,
     K_FINALLY = 330,
     K_FOR = 331,
     K_FRIEND = 332,
     K_FUNCTION = 333,
     K_GET = 334,
     K_GETTYPE = 335,
     K_GOSUB = 336,
     K_GOTO = 337,
     K_HANDLES = 338,
     K_IF = 339,
     K_IMPLEMENTS = 340,
     K_IMPORTS = 341,
     K_IN = 342,
     K_INHERITS = 343,
     K_INTEGER = 344,
     K_INTERFACE = 345,
     K_IS = 346,
     K_LET = 347,
     K_LIB = 348,
     K_LIKE = 349,
     K_LONG = 350,
     K_LOOP = 351,
     K_ME = 352,
     K_MOD = 353,
     K_MODULE = 354,
     K_MUSTINHERIT = 355,
     K_MUSTOVERRIDE = 356,
     K_MYBASE = 357,
     K_MYCLASS = 358,
     K_NAMESPACE = 359,
     K_NEW = 360,
     K_NEXT = 361,
     K_NOT = 362,
     K_NOTHING = 363,
     K_NOTINHERITABLE = 364,
     K_NOTOVERRIDABLE = 365,
     K_OBJECT = 366,
     K_ON = 367,
     K_OPTION = 368,
     K_OPTIONAL = 369,
     K_OR = 370,
     K_ORELSE = 371,
     K_OVERLOADS = 372,
     K_OVERRIDABLE = 373,
     K_OVERRIDES = 374,
     K_PARAMARRAY = 375,
     K_PRESERVE = 376,
     K_PRIVATE = 377,
     K_PROPERTY = 378,
     K_PROTECTED = 379,
     K_PUBLIC = 380,
     K_RAISEEVENT = 381,
     K_READONLY = 382,
     K_REDIM = 383,
     K_REMOVEHANDLER = 384,
     K_RESUME = 385,
     K_RETURN = 386,
     K_SELECT = 387,
     K_SET = 388,
     K_SHADOWS = 389,
     K_SHARED = 390,
     K_SHORT = 391,
     K_SINGLE = 392,
     K_STATIC = 393,
     K_STEP = 394,
     K_STOP = 395,
     K_STRING = 396,
     K_STRUCTURE = 397,
     K_SUB = 398,
     K_SYNCLOCK = 399,
     K_THEN = 400,
     K_THROW = 401,
     K_TO = 402,
     K_TRUE = 403,
     K_TRY = 404,
     K_TYPEOF = 405,
     K_UNICODE = 406,
     K_UNTIL = 407,
     K_VARIANT = 408,
     K_WHEN = 409,
     K_WHILE = 410,
     K_WITH = 411,
     K_WITHEVENTS = 412,
     K_WRITEONLY = 413,
     K_XOR = 414
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPED_IDENTIFIER 259
#define INTEGER_CONSTANT 260
#define FLOAT_CONSTANT 261
#define DECIMAL_CONSTANT 262
#define CHAR_LITERAL 263
#define STRING_LITERAL 264
#define END_LINE 265
#define CONCAT_ASSIGN_OP 266
#define MUL_ASSIGN_OP 267
#define DIV_ASSIGN_OP 268
#define IDIV_ASSIGN_OP 269
#define POW_ASSIGN_OP 270
#define ADD_ASSIGN_OP 271
#define SUB_ASSIGN_OP 272
#define NE_OP 273
#define LE_OP 274
#define GE_OP 275
#define EQ_OP 276
#define LEFT_OP 277
#define RIGHT_OP 278
#define K_ADDHANDLER 279
#define K_ADDRESSOF 280
#define K_ALIAS 281
#define K_AND 282
#define K_ANDALSO 283
#define K_ANSI 284
#define K_AS 285
#define K_ASSEMBLY 286
#define K_AUTO 287
#define K_BOOLEAN 288
#define K_BYREF 289
#define K_BYTE 290
#define K_BYVAL 291
#define K_CALL 292
#define K_CASE 293
#define K_CATCH 294
#define K_CBOOL 295
#define K_CBYTE 296
#define K_CCHAR 297
#define K_CDATE 298
#define K_CDEC 299
#define K_CDBL 300
#define K_CHAR 301
#define K_CINT 302
#define K_CLASS 303
#define K_CLNG 304
#define K_COBJ 305
#define K_CONST 306
#define K_CSHORT 307
#define K_CSNG 308
#define K_CSTR 309
#define K_CTYPE 310
#define K_DATE 311
#define K_DECIMAL 312
#define K_DECLARE 313
#define K_DEFAULT 314
#define K_DELEGATE 315
#define K_DIM 316
#define K_DIRECTCAST 317
#define K_DO 318
#define K_DOUBLE 319
#define K_EACH 320
#define K_ELSE 321
#define K_ELSEIF 322
#define K_END 323
#define K_ENUM 324
#define K_ERASE 325
#define K_ERROR 326
#define K_EVENT 327
#define K_EXIT 328
#define K_FALSE 329
#define K_FINALLY 330
#define K_FOR 331
#define K_FRIEND 332
#define K_FUNCTION 333
#define K_GET 334
#define K_GETTYPE 335
#define K_GOSUB 336
#define K_GOTO 337
#define K_HANDLES 338
#define K_IF 339
#define K_IMPLEMENTS 340
#define K_IMPORTS 341
#define K_IN 342
#define K_INHERITS 343
#define K_INTEGER 344
#define K_INTERFACE 345
#define K_IS 346
#define K_LET 347
#define K_LIB 348
#define K_LIKE 349
#define K_LONG 350
#define K_LOOP 351
#define K_ME 352
#define K_MOD 353
#define K_MODULE 354
#define K_MUSTINHERIT 355
#define K_MUSTOVERRIDE 356
#define K_MYBASE 357
#define K_MYCLASS 358
#define K_NAMESPACE 359
#define K_NEW 360
#define K_NEXT 361
#define K_NOT 362
#define K_NOTHING 363
#define K_NOTINHERITABLE 364
#define K_NOTOVERRIDABLE 365
#define K_OBJECT 366
#define K_ON 367
#define K_OPTION 368
#define K_OPTIONAL 369
#define K_OR 370
#define K_ORELSE 371
#define K_OVERLOADS 372
#define K_OVERRIDABLE 373
#define K_OVERRIDES 374
#define K_PARAMARRAY 375
#define K_PRESERVE 376
#define K_PRIVATE 377
#define K_PROPERTY 378
#define K_PROTECTED 379
#define K_PUBLIC 380
#define K_RAISEEVENT 381
#define K_READONLY 382
#define K_REDIM 383
#define K_REMOVEHANDLER 384
#define K_RESUME 385
#define K_RETURN 386
#define K_SELECT 387
#define K_SET 388
#define K_SHADOWS 389
#define K_SHARED 390
#define K_SHORT 391
#define K_SINGLE 392
#define K_STATIC 393
#define K_STEP 394
#define K_STOP 395
#define K_STRING 396
#define K_STRUCTURE 397
#define K_SUB 398
#define K_SYNCLOCK 399
#define K_THEN 400
#define K_THROW 401
#define K_TO 402
#define K_TRUE 403
#define K_TRY 404
#define K_TYPEOF 405
#define K_UNICODE 406
#define K_UNTIL 407
#define K_VARIANT 408
#define K_WHEN 409
#define K_WHILE 410
#define K_WITH 411
#define K_WITHEVENTS 412
#define K_WRITEONLY 413
#define K_XOR 414




/* Copy the first part of user declarations.  */
#line 1 "vb_grammar.y"

/*
 * vb_grammar.y - Input file for yacc that defines the syntax of VB.
 *
 * Copyright (C) 2003  Southern Storm Software, Pty Ltd.
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
#include "vb_rename.h"

#include <stdio.h>
#include <cscc/vb/vb_internal.h>

#define	YYERROR_VERBOSE

/*
 * Imports from the lexical analyser.
 */
extern int yylex(void);
#ifdef YYTEXT_POINTER
extern char *vb_text;
#else
extern char vb_text[];
#endif

static void yyerror(char *msg)
{
	CCPluginParseError(msg, vb_text);
}

/*
 * Insert an "else" clause into an "if" node at the end of the chain.
 */
static void VBInsertElse(ILNode *ifnode, ILNode *elseClause)
{
	while(((ILNode_If *)ifnode)->elseClause != 0)
	{
		ifnode = ((ILNode_If *)ifnode)->elseClause;
	}
	((ILNode_If *)ifnode)->elseClause = elseClause;
}

/*
 * Global state used by the parser.
 */
static unsigned long NestingLevel = 0;
static ILIntString CurrNamespace = {"", 0};
static ILNode_Namespace *CurrNamespaceNode = 0;
static ILNode_Namespace *GlobalNamespaceNode = 0;
static ILScope* localScope = 0;
static int HaveDecls = 0;

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
 * Initialize the global namespace, if necessary.
 */
static void PushIntoNamespace(ILIntString name);
static void InitGlobalNamespace(void)
{
	if(!CurrNamespaceNode)
	{
		ILNode_UsingNamespace *using;
		char *root;

		/* Create the global namespace node */
		CurrNamespaceNode = (ILNode_Namespace *)ILNode_Namespace_create(0, 0);
		using = (ILNode_UsingNamespace *)ILNode_UsingNamespace_create("System");
		using->next = CurrNamespaceNode->using;
		CurrNamespaceNode->using = using;
		GlobalNamespaceNode = CurrNamespaceNode;

		/* Set the default options on the global namespace */
		VBOptionInit(GlobalNamespaceNode);

		/* Add extra "using" clauses for command-line supplied namespaces */
		VBAddGlobalImports(GlobalNamespaceNode, GlobalScope());

		/* If we have a root namespace, then push into it */
		root = VBGetRootNamespace();
		if(root)
		{
			PushIntoNamespace(ILInternString(root, -1));
		}
	}
}

/*
 * Push into a new namespace context.
 */
static void PushIntoNamespace(ILIntString name)
{
	int posn, len;
	ILScope *oldLocalScope;
	posn = 0;
	while(posn < name.len)
	{
		/* Extract the next identifier */
		if(name.string[posn] == '.')
		{
			++posn;
			continue;
		}
		len = 0;
		while((posn + len) < name.len &&
			  name.string[posn + len] != '.')
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
					 ILInternString(name.string + posn, len)));
		}
		else
		{
			CurrNamespace = ILInternString(name.string + posn, len);
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

/*
 * Pop out of a namespace context.
 */
static void PopOutOfNamespace(ILIntString name)
{
	if(CurrNamespace.len == name.len)
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
			(CurrNamespace.string, CurrNamespace.len - name.len - 1);
		while(CurrNamespaceNode->name != CurrNamespace.string)
		{
			CurrNamespaceNode = CurrNamespaceNode->enclosing;
		}
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
	GlobalNamespaceNode = 0;
	localScope = 0;
	ILScopeClearUsing(GlobalScope());
	HaveDecls = 0;
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
 * Make a system type name node.
 */
#define	MakeSystemType(name)	\
			(ILNode_GlobalNamespace_create(ILNode_SystemType_create(name)))

/*
 * The class name stack, which is used to verify the names
 * of constructors and destructors against the name of their
 * enclosing classes.  Also used to check if a class has
 * had a constructor defined for it.
 */
static ILNode **classNameStack = 0;
static int     *classNameCtorDefined = 0;
static int     *classNameIsModule = 0;
static int		classNameStackSize = 0;
static int		classNameStackMax = 0;

/*
 * Push an item onto the class name stack.
 */
static void ClassNamePush(ILNode *name, int isModule)
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
		classNameIsModule = (int *)ILRealloc
			(classNameIsModule, sizeof(int) * (classNameStackMax + 4));
		if(!classNameIsModule)
		{
			CCOutOfMemory();
		}
		classNameStackMax += 4;
	}
	classNameStack[classNameStackSize] = name;
	classNameIsModule[classNameStackSize] = isModule;
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
 * Determine if the current class is a module.
 */
static int ClassNameIsModule(void)
{
	return classNameIsModule[classNameStackSize - 1];
}

/*
 * Combine two attribute lists.
 */
static ILNode *CombineAttributes(ILNode *list, ILAttrTargetType type,
								 ILNode *attr)
{
	/* TODO */
	return list;
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
#line 374 "vb_grammar.y"
{

	struct
	{
		ILInt64		value;
		int			type;
		int			numDigits;
	}					integer;
	struct
	{
		ILDouble	value;
		int			type;
	}					real;
	ILDecimal			decimal;
	ILIntString			string;
	char	           *name;
	ILNode             *node;
	ILUInt32			rank;
	ILInt64				date;
	int					ampm;
	struct
	{
		ILNode	   *thenClause;
		ILNode	   *elseClause;

	}					ifrest;
	struct
	{
		ILNode	   *name;
		ILNode     *type;

	}					loopvar;
	ILUInt32			modifier;
	struct
	{
		ILNode		   *body;
		ILNode		   *staticCtors;

	} member;
	struct
	{
		ILUInt32	rank;
		ILNode	   *exprs;

	}					arrayName;
	struct
	{
		ILNode	   *type;
		ILNode	   *attrs;

	}					typeInfo;
	ILParameterModifier	paramMod;

}
/* Line 193 of yacc.c.  */
#line 839 "vb_grammar.c"
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
#line 864 "vb_grammar.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4800

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  179
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  195
/* YYNRULES -- Number of rules.  */
#define YYNRULES  512
/* YYNRULES -- Number of states.  */
#define YYNSTATES  896

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   414

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   171,     2,   172,     2,     2,   178,     2,
     166,   167,   176,   175,   160,   170,   162,   173,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   165,     2,
     163,   161,   164,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   177,     2,   174,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   168,     2,   169,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    10,    13,    15,    20,    21,
      23,    25,    26,    28,    31,    33,    37,    41,    43,    45,
      49,    51,    53,    55,    59,    61,    65,    67,    68,    72,
      75,    77,    81,    82,    85,    88,    89,    92,    96,    98,
     102,   104,   108,   110,   114,   116,   121,   123,   125,   130,
     132,   134,   136,   138,   140,   142,   144,   146,   148,   150,
     152,   154,   156,   157,   159,   162,   164,   168,   172,   176,
     178,   179,   188,   189,   191,   194,   196,   198,   200,   202,
     204,   206,   208,   210,   212,   214,   215,   217,   220,   222,
     224,   226,   228,   230,   232,   234,   236,   238,   240,   242,
     244,   246,   248,   250,   252,   254,   256,   258,   259,   271,
     272,   275,   277,   279,   281,   283,   284,   286,   289,   291,
     297,   301,   302,   314,   315,   319,   323,   325,   326,   328,
     330,   333,   335,   337,   339,   341,   343,   345,   347,   348,
     361,   362,   366,   367,   378,   379,   391,   392,   396,   397,
     399,   401,   404,   406,   408,   410,   412,   417,   419,   421,
     423,   425,   427,   429,   438,   439,   444,   448,   458,   459,
     464,   468,   479,   491,   492,   496,   497,   500,   504,   508,
     510,   516,   517,   519,   522,   524,   526,   528,   530,   532,
     533,   536,   537,   540,   541,   544,   546,   547,   549,   552,
     555,   557,   561,   565,   568,   570,   574,   575,   577,   579,
     581,   584,   585,   588,   596,   604,   606,   609,   610,   613,
     622,   628,   629,   631,   635,   637,   640,   645,   647,   650,
     651,   657,   660,   667,   671,   673,   676,   680,   684,   686,
     696,   697,   702,   706,   708,   710,   713,   716,   721,   722,
     727,   731,   736,   737,   742,   746,   747,   749,   753,   756,
     757,   759,   763,   765,   767,   769,   771,   773,   775,   777,
     779,   781,   783,   785,   787,   789,   791,   793,   795,   797,
     799,   801,   803,   805,   807,   809,   811,   813,   815,   817,
     819,   821,   823,   827,   830,   832,   834,   837,   840,   847,
     854,   857,   860,   863,   867,   871,   876,   880,   884,   888,
     892,   896,   900,   904,   907,   909,   911,   914,   917,   922,
     928,   933,   940,   946,   947,   949,   952,   954,   959,   965,
     966,   970,   972,   977,   983,   989,   990,   992,   995,   997,
    1002,  1006,  1008,  1011,  1015,  1017,  1021,  1023,  1025,  1027,
    1029,  1031,  1033,  1034,  1038,  1045,  1052,  1059,  1066,  1073,
    1085,  1094,  1098,  1100,  1101,  1104,  1105,  1107,  1109,  1112,
    1115,  1120,  1126,  1131,  1133,  1136,  1139,  1146,  1147,  1149,
    1152,  1154,  1160,  1161,  1165,  1166,  1169,  1170,  1174,  1177,
    1180,  1183,  1186,  1189,  1192,  1195,  1198,  1200,  1202,  1204,
    1207,  1210,  1214,  1217,  1221,  1223,  1228,  1232,  1234,  1236,
    1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1258,
    1260,  1262,  1264,  1269,  1273,  1278,  1282,  1285,  1287,  1290,
    1294,  1301,  1308,  1313,  1318,  1319,  1325,  1327,  1329,  1330,
    1333,  1338,  1345,  1346,  1348,  1352,  1354,  1356,  1360,  1362,
    1369,  1374,  1376,  1379,  1383,  1389,  1396,  1397,  1400,  1404,
    1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,
    1426,  1428,  1430,  1434,  1436,  1439,  1442,  1444,  1448,  1452,
    1454,  1458,  1460,  1464,  1466,  1470,  1474,  1476,  1480,  1482,
    1486,  1490,  1492,  1496,  1500,  1504,  1508,  1512,  1516,  1520,
    1524,  1528,  1533,  1535,  1538,  1540,  1544,  1548,  1550,  1554,
    1558,  1562,  1564
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     180,     0,    -1,   181,   185,   211,    -1,    -1,   182,    -1,
     182,   183,    -1,   183,    -1,   113,   190,   184,    10,    -1,
      -1,   190,    -1,   112,    -1,    -1,   186,    -1,   186,   187,
      -1,   187,    -1,    86,   188,    10,    -1,   188,   160,   189,
      -1,   189,    -1,   192,    -1,   190,   161,   192,    -1,     3,
      -1,     4,    -1,   190,    -1,   192,   162,   191,    -1,   190,
      -1,   193,   162,   190,    -1,   190,    -1,    -1,   163,   195,
     164,    -1,   195,   196,    -1,   196,    -1,   197,   203,   198,
      -1,    -1,    31,   165,    -1,    99,   165,    -1,    -1,   166,
     167,    -1,   166,   199,   167,    -1,   200,    -1,   200,   160,
     201,    -1,   201,    -1,   200,   160,   373,    -1,   373,    -1,
     201,   160,   202,    -1,   202,    -1,   190,   165,   161,   373,
      -1,   192,    -1,   204,    -1,   203,   166,   205,   167,    -1,
     111,    -1,   153,    -1,   141,    -1,    33,    -1,    56,    -1,
      46,    -1,    57,    -1,    35,    -1,   136,    -1,    89,    -1,
      95,    -1,   137,    -1,    64,    -1,    -1,   206,    -1,   206,
     160,    -1,   160,    -1,   166,   205,   167,    -1,   166,   208,
     167,    -1,   208,   160,   372,    -1,   372,    -1,    -1,   104,
     192,    10,   210,   211,    68,   104,    10,    -1,    -1,   212,
      -1,   212,   213,    -1,   213,    -1,   209,    -1,   214,    -1,
     236,    -1,   215,    -1,   219,    -1,   226,    -1,   238,    -1,
     233,    -1,   244,    -1,    -1,   217,    -1,   217,   218,    -1,
     218,    -1,   125,    -1,   124,    -1,    77,    -1,   122,    -1,
     134,    -1,   100,    -1,   109,    -1,   135,    -1,   138,    -1,
     118,    -1,   110,    -1,   101,    -1,   119,    -1,   117,    -1,
     127,    -1,   158,    -1,   157,    -1,    59,    -1,    -1,   194,
     216,    69,   190,   221,    10,   220,   223,    68,    69,    10,
      -1,    -1,    30,   222,    -1,    35,    -1,   136,    -1,    89,
      -1,    95,    -1,    -1,   224,    -1,   224,   225,    -1,   225,
      -1,   194,   190,   161,   373,    10,    -1,   194,   190,    10,
      -1,    -1,   194,   216,   142,   190,    10,   228,   227,   230,
      68,   142,    10,    -1,    -1,    85,   229,    10,    -1,   229,
     160,   203,    -1,   203,    -1,    -1,   231,    -1,   232,    -1,
     231,   232,    -1,   215,    -1,   278,    -1,   277,    -1,   274,
      -1,   245,    -1,   286,    -1,   273,    -1,    -1,   194,   216,
      48,   190,    10,   235,   228,   234,   230,    68,    48,    10,
      -1,    -1,    88,   203,    10,    -1,    -1,   194,   216,    99,
     190,    10,   237,   230,    68,    99,    10,    -1,    -1,   194,
     216,    90,   190,    10,   240,   239,   241,    68,    90,    10,
      -1,    -1,    88,   229,    10,    -1,    -1,   242,    -1,   243,
      -1,   242,   243,    -1,   215,    -1,   274,    -1,   245,    -1,
     286,    -1,   194,   216,    60,   246,    -1,   246,    -1,   247,
      -1,   248,    -1,   250,    -1,   252,    -1,   253,    -1,   194,
     216,   143,   190,   255,   263,    10,   249,    -1,    -1,   294,
      68,   143,    10,    -1,    68,   143,    10,    -1,   194,   216,
      78,   190,   255,   254,   263,    10,   251,    -1,    -1,   294,
      68,    78,    10,    -1,    68,    78,    10,    -1,   194,   216,
      58,   270,   143,   190,   271,   272,   255,    10,    -1,   194,
     216,    58,   270,    78,   190,   271,   272,   255,   254,    10,
      -1,    -1,    30,   194,   203,    -1,    -1,   166,   167,    -1,
     166,   256,   167,    -1,   256,   160,   257,    -1,   257,    -1,
     194,   258,   190,   261,   262,    -1,    -1,   259,    -1,   259,
     260,    -1,   260,    -1,    34,    -1,    36,    -1,   114,    -1,
     120,    -1,    -1,    30,   203,    -1,    -1,   161,   373,    -1,
      -1,    83,   266,    -1,   265,    -1,    -1,   265,    -1,    85,
     268,    -1,   266,   267,    -1,   267,    -1,   190,   162,   193,
      -1,   102,   162,   193,    -1,   268,   269,    -1,   269,    -1,
     203,   162,   190,    -1,    -1,    29,    -1,   151,    -1,    32,
      -1,    93,     9,    -1,    -1,    26,     9,    -1,   194,   216,
     143,   105,   255,    10,   249,    -1,   194,   216,    72,   190,
     275,   276,    10,    -1,   255,    -1,    30,   203,    -1,    -1,
      85,   268,    -1,   194,   216,    51,   190,   261,   161,   373,
      10,    -1,   194,   216,   279,   280,    10,    -1,    -1,    61,
      -1,   280,   160,   281,    -1,   281,    -1,   282,   283,    -1,
     282,   283,   161,   284,    -1,   190,    -1,   190,   207,    -1,
      -1,    30,   203,   166,   353,   167,    -1,    30,   203,    -1,
      30,   105,   203,   166,   353,   167,    -1,    30,   105,   203,
      -1,   372,    -1,   168,   169,    -1,   168,   285,   169,    -1,
     285,   160,   284,    -1,   284,    -1,   194,   216,   123,   190,
     255,   254,   264,    10,   287,    -1,    -1,   288,    68,   123,
      10,    -1,    68,   123,    10,    -1,   289,    -1,   291,    -1,
     289,   291,    -1,   291,   289,    -1,   194,    79,    10,   290,
      -1,    -1,   294,    68,    79,    10,    -1,    68,    79,    10,
      -1,   194,   133,    10,   292,    -1,    -1,   294,    68,   133,
      10,    -1,    68,   133,    10,    -1,    -1,   294,    -1,   294,
     297,    10,    -1,   297,    10,    -1,    -1,   296,    -1,   296,
     165,   298,    -1,   298,    -1,   299,    -1,   300,    -1,   301,
      -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,
      -1,   308,    -1,   310,    -1,   311,    -1,   313,    -1,   314,
      -1,   321,    -1,   330,    -1,   334,    -1,   335,    -1,   342,
      -1,   343,    -1,   303,    -1,   306,    -1,   307,    -1,   308,
      -1,   310,    -1,   311,    -1,   313,    -1,   334,    -1,   342,
      -1,   343,    -1,   302,   165,   297,    -1,   302,   165,    -1,
     190,    -1,     5,    -1,    61,   281,    -1,    51,   281,    -1,
     156,   372,    10,   293,    68,   156,    -1,   144,   372,    10,
     293,    68,   144,    -1,   126,   347,    -1,    24,   309,    -1,
     129,   309,    -1,   356,   160,   356,    -1,   347,   161,   372,
      -1,   347,   161,    25,   347,    -1,   347,    15,   372,    -1,
     347,    12,   372,    -1,   347,    13,   372,    -1,   347,    14,
     372,    -1,   347,    16,   372,    -1,   347,    17,   372,    -1,
     347,    11,   372,    -1,    92,   310,    -1,   372,    -1,   347,
      -1,    37,   347,    -1,    81,   347,    -1,    84,   320,    10,
     315,    -1,    84,   320,   145,    10,   315,    -1,    84,   320,
     145,   296,    -1,    84,   320,   145,   296,    66,   295,    -1,
     293,   316,   319,    68,    84,    -1,    -1,   317,    -1,   317,
     318,    -1,   318,    -1,    67,   320,    10,   293,    -1,    67,
     320,   145,    10,   293,    -1,    -1,    66,    10,   293,    -1,
     372,    -1,   132,   372,    10,   322,    -1,   132,    38,   372,
      10,   322,    -1,   323,   329,    68,   132,    10,    -1,    -1,
     324,    -1,   324,   325,    -1,   325,    -1,    38,   326,    10,
     293,    -1,   326,   160,   327,    -1,   327,    -1,   328,   372,
      -1,    91,   328,   372,    -1,   372,    -1,   372,   147,   372,
      -1,   161,    -1,   163,    -1,   164,    -1,    19,    -1,    20,
      -1,    18,    -1,    -1,    38,    66,   293,    -1,   155,   320,
      10,   293,    68,   155,    -1,    63,   155,   320,    10,   293,
      96,    -1,    63,   152,   320,    10,   293,    96,    -1,    63,
      10,   293,    96,   155,   320,    -1,    63,    10,   293,    96,
     152,   320,    -1,    76,   331,   161,   372,   147,   372,   332,
      10,   293,   106,   333,    -1,    76,    65,   331,    87,   372,
      10,   106,   333,    -1,   190,    30,   203,    -1,   347,    -1,
      -1,   139,   372,    -1,    -1,   190,    -1,   146,    -1,   146,
     372,    -1,    71,   372,    -1,   112,    71,   130,   106,    -1,
     112,    71,    82,   170,     5,    -1,   112,    71,    82,   302,
      -1,   130,    -1,   130,   106,    -1,   130,   302,    -1,   149,
     293,   336,   341,    68,   149,    -1,    -1,   337,    -1,   337,
     338,    -1,   338,    -1,    39,   339,   340,    10,   293,    -1,
      -1,   190,    30,   203,    -1,    -1,   154,   320,    -1,    -1,
      75,    10,   293,    -1,    82,   302,    -1,    73,    63,    -1,
      73,    76,    -1,    73,   155,    -1,    73,   132,    -1,    73,
     143,    -1,    73,    78,    -1,    73,   149,    -1,   140,    -1,
      68,    -1,   131,    -1,   131,   372,    -1,   128,   344,    -1,
     128,   121,   344,    -1,    70,   346,    -1,   344,   160,   345,
      -1,   345,    -1,   312,   166,   208,   167,    -1,   346,   160,
     312,    -1,   312,    -1,     5,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,   348,    -1,   148,    -1,    74,    -1,
     108,    -1,   190,    -1,   166,   372,   167,    -1,    97,    -1,
     103,    -1,   102,    -1,    80,   166,   372,   167,    -1,   347,
     166,   167,    -1,   347,   166,   353,   167,    -1,   347,   162,
     191,    -1,   162,   191,    -1,   357,    -1,   171,   191,    -1,
     347,   171,   191,    -1,    55,   166,   372,   160,   203,   167,
      -1,    62,   166,   372,   160,   203,   167,    -1,   359,   166,
     372,   167,    -1,   172,   349,   351,   172,    -1,    -1,     5,
     350,     5,   350,     5,    -1,   170,    -1,   173,    -1,    -1,
       5,   352,    -1,     5,   165,     5,   352,    -1,     5,   165,
       5,   165,     5,   352,    -1,    -1,     3,    -1,   354,   160,
     355,    -1,   354,    -1,   355,    -1,   354,   160,   356,    -1,
     356,    -1,   355,   160,   190,   165,   161,   356,    -1,   190,
     165,   161,   356,    -1,   372,    -1,    25,   347,    -1,   105,
     203,   358,    -1,   105,   203,   166,   167,   358,    -1,   105,
     203,   166,   353,   167,   358,    -1,    -1,   168,   169,    -1,
     168,   285,   169,    -1,    40,    -1,    41,    -1,    42,    -1,
      43,    -1,    44,    -1,    45,    -1,    47,    -1,    49,    -1,
      50,    -1,    52,    -1,    53,    -1,    54,    -1,   347,    -1,
     360,   174,   361,    -1,   360,    -1,   170,   361,    -1,   175,
     361,    -1,   361,    -1,   362,   176,   361,    -1,   362,   173,
     361,    -1,   362,    -1,   363,   177,   362,    -1,   363,    -1,
     362,    98,   363,    -1,   364,    -1,   365,   175,   364,    -1,
     365,   170,   364,    -1,   365,    -1,   366,   178,   365,    -1,
     366,    -1,   367,    22,   366,    -1,   367,    23,   366,    -1,
     367,    -1,   368,   161,   367,    -1,   368,    21,   367,    -1,
     368,    18,   367,    -1,   368,   163,   367,    -1,   368,   164,
     367,    -1,   368,    19,   367,    -1,   368,    20,   367,    -1,
     368,    91,   367,    -1,   368,    94,   367,    -1,   150,   372,
      91,   203,    -1,   368,    -1,   107,   369,    -1,   369,    -1,
     370,    27,   369,    -1,   370,    28,   369,    -1,   370,    -1,
     371,   115,   370,    -1,   371,   116,   370,    -1,   371,   159,
     370,    -1,   371,    -1,   372,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   677,   677,   683,   685,   689,   690,   694,   767,   768,
     769,   772,   774,   778,   779,   783,   787,   788,   792,   809,
     834,   835,   840,   844,   847,   851,   854,   862,   863,   867,
     874,   884,   910,   911,   914,   920,   921,   922,   926,   929,
     932,   938,   942,   949,   953,   960,   970,   971,   972,   978,
     979,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   991,   995,   996,  1000,  1001,  1005,  1006,  1010,  1014,
    1025,  1025,  1032,  1034,  1038,  1039,  1043,  1044,  1048,  1049,
    1053,  1054,  1055,  1056,  1057,  1065,  1066,  1070,  1078,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1110,  1110,  1176,
    1177,  1181,  1182,  1183,  1184,  1188,  1189,  1193,  1197,  1204,
    1207,  1218,  1217,  1269,  1270,  1274,  1277,  1281,  1282,  1286,
    1290,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1312,  1311,
    1391,  1392,  1400,  1400,  1478,  1477,  1520,  1521,  1525,  1526,
    1530,  1534,  1541,  1542,  1543,  1544,  1552,  1562,  1563,  1567,
    1568,  1572,  1573,  1577,  1592,  1593,  1594,  1598,  1614,  1615,
    1616,  1620,  1636,  1654,  1658,  1665,  1666,  1667,  1671,  1675,
    1682,  1690,  1691,  1695,  1709,  1713,  1714,  1715,  1716,  1720,
    1721,  1725,  1726,  1729,  1731,  1732,  1735,  1737,  1741,  1745,
    1746,  1750,  1751,  1755,  1756,  1760,  1763,  1765,  1766,  1767,
    1771,  1774,  1776,  1784,  1822,  1827,  1828,  1831,  1833,  1841,
    1857,  1863,  1865,  1869,  1870,  1874,  1875,  1879,  1880,  1883,
    1885,  1886,  1887,  1888,  1892,  1893,  1894,  1898,  1899,  1907,
    1913,  1915,  1916,  1920,  1921,  1922,  1923,  1927,  1931,  1932,
    1933,  1937,  1941,  1942,  1943,  1951,  1952,  1956,  1959,  1963,
    1964,  1968,  1971,  1975,  1991,  2007,  2008,  2009,  2010,  2011,
    2012,  2013,  2014,  2015,  2016,  2017,  2018,  2019,  2020,  2021,
    2022,  2023,  2028,  2029,  2030,  2031,  2032,  2033,  2034,  2035,
    2036,  2037,  2041,  2045,  2051,  2052,  2062,  2063,  2067,  2071,
    2075,  2079,  2083,  2087,  2091,  2094,  2098,  2102,  2105,  2108,
    2112,  2115,  2118,  2125,  2132,  2136,  2141,  2146,  2155,  2158,
    2161,  2164,  2170,  2185,  2186,  2190,  2194,  2198,  2201,  2207,
    2208,  2212,  2217,  2218,  2222,  2225,  2227,  2231,  2232,  2236,
    2240,  2241,  2245,  2246,  2247,  2248,  2252,  2253,  2254,  2255,
    2256,  2257,  2260,  2262,  2266,  2271,  2276,  2282,  2287,  2293,
    2302,  2314,  2315,  2319,  2320,  2323,  2325,  2329,  2330,  2331,
    2332,  2333,  2334,  2335,  2336,  2337,  2342,  2345,  2347,  2351,
    2352,  2356,  2359,  2361,  2364,  2366,  2369,  2371,  2375,  2376,
    2380,  2384,  2388,  2392,  2393,  2394,  2395,  2399,  2404,  2405,
    2409,  2410,  2411,  2415,  2416,  2420,  2424,  2425,  2433,  2468,
    2478,  2481,  2484,  2487,  2488,  2489,  2490,  2491,  2492,  2493,
    2494,  2495,  2496,  2497,  2500,  2504,  2507,  2510,  2511,  2515,
    2519,  2522,  2526,  2532,  2542,  2543,  2560,  2561,  2565,  2566,
    2567,  2570,  2576,  2577,  2595,  2599,  2600,  2604,  2607,  2611,
    2615,  2622,  2623,  2630,  2631,  2632,  2635,  2637,  2638,  2642,
    2643,  2644,  2645,  2646,  2647,  2648,  2649,  2650,  2651,  2652,
    2653,  2657,  2658,  2665,  2666,  2667,  2671,  2672,  2675,  2681,
    2682,  2689,  2690,  2696,  2697,  2700,  2706,  2707,  2713,  2714,
    2717,  2723,  2724,  2728,  2731,  2734,  2737,  2740,  2743,  2746,
    2750,  2754,  2760,  2761,  2767,  2768,  2771,  2777,  2778,  2781,
    2784,  2790,  2794
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"an identifier\"",
  "\"a typed identifier\"", "\"an integer value\"",
  "\"a floating point value\"", "\"a decimal value\"",
  "\"a character literal\"", "\"a string literal\"", "\"line terminator\"",
  "\"`&='\"", "\"`*='\"", "\"`/='\"", "\"`\\\\='\"", "\"`^='\"",
  "\"`+='\"", "\"`-='\"", "\"`<>'\"", "\"`<='\"", "\"`>='\"", "\"`=='\"",
  "\"`<<'\"", "\"`>>'\"", "\"`AddHandler'\"", "\"`AddressOf'\"",
  "\"`Alias'\"", "\"`And'\"", "\"`AndAlso'\"", "\"`Ansi'\"", "\"`As'\"",
  "\"`Assembly'\"", "\"`Auto'\"", "\"`Boolean'\"", "\"`ByRef'\"",
  "\"`Byte'\"", "\"`ByVal'\"", "\"`Call'\"", "\"`Case'\"", "\"`Catch'\"",
  "\"`CBool'\"", "\"`CByte'\"", "\"`CChar'\"", "\"`CDate'\"", "\"`CDec'\"",
  "\"`CDbl'\"", "\"`Char'\"", "\"`CInt'\"", "\"`Class'\"", "\"`CLng'\"",
  "\"`CObj'\"", "\"`Const'\"", "\"`CShort'\"", "\"`CSng'\"", "\"`CStr'\"",
  "\"`CType'\"", "\"`Date'\"", "\"`Decimal'\"", "\"`Declare'\"",
  "\"`Default'\"", "\"`Delegate'\"", "\"`Dim'\"", "\"`DirectCast'\"",
  "\"`Do'\"", "\"`Double'\"", "\"`Each'\"", "\"`Else'\"", "\"`ElseIf'\"",
  "\"`End'\"", "\"`Enum'\"", "\"`Erase'\"", "\"`Error'\"", "\"`Event'\"",
  "\"`Exit'\"", "\"`False'\"", "\"`Finally'\"", "\"`For'\"",
  "\"`Friend'\"", "\"`Function'\"", "\"`Get'\"", "\"`GetType'\"",
  "\"`GoSub'\"", "\"`GoTo'\"", "\"`Handles'\"", "\"`If'\"",
  "\"`Implements'\"", "\"`Imports'\"", "\"`In'\"", "\"`Inherits'\"",
  "\"`Integer'\"", "\"`Interface'\"", "\"`Is'\"", "\"`Let'\"", "\"`Lib'\"",
  "\"`Like'\"", "\"`Long'\"", "\"`Loop'\"", "\"`Me'\"", "\"`Mod'\"",
  "\"`Module'\"", "\"`MustInherit'\"", "\"`MustOverride'\"",
  "\"`MyBase'\"", "\"`MyClass'\"", "\"`Namespace'\"", "\"`New'\"",
  "\"`Next'\"", "\"`Not'\"", "\"`Nothing'\"", "\"`NotInheritable'\"",
  "\"`NotOverridable'\"", "\"`Object'\"", "\"`On'\"", "\"`Option'\"",
  "\"`Optional'\"", "\"`Or'\"", "\"`OrElse'\"", "\"`Overloads'\"",
  "\"`Overridable'\"", "\"`Overrides'\"", "\"`ParamArray'\"",
  "\"`Preserve'\"", "\"`Private'\"", "\"`Property'\"", "\"`Protected'\"",
  "\"`Public'\"", "\"`RaiseEvent'\"", "\"`ReadOnly'\"", "\"`ReDim'\"",
  "\"`RemoveHandler'\"", "\"`Resume'\"", "\"`Return'\"", "\"`Select'\"",
  "\"`Set'\"", "\"`Shadows'\"", "\"`Shared'\"", "\"`Short'\"",
  "\"`Single'\"", "\"`Static'\"", "\"`Step'\"", "\"`Stop'\"",
  "\"`String'\"", "\"`Structure'\"", "\"`Sub'\"", "\"`SyncLock'\"",
  "\"`Then'\"", "\"`Throw'\"", "\"`To'\"", "\"`True'\"", "\"`Try'\"",
  "\"`TypeOf'\"", "\"`Unicode'\"", "\"`Until'\"", "\"`Variant'\"",
  "\"`When'\"", "\"`While'\"", "\"`With'\"", "\"`WithEvents'\"",
  "\"`WriteOnly'\"", "\"`Xor'\"", "','", "'='", "'.'", "'<'", "'>'", "':'",
  "'('", "')'", "'{'", "'}'", "'-'", "'!'", "'#'", "'/'", "'^'", "'+'",
  "'*'", "'\\\\'", "'&'", "$accept", "File", "Options", "OptionList",
  "Option", "OptionValue", "Imports", "ImportList", "Import",
  "ImportClauses", "ImportClause", "Identifier", "IdentifierOrKeyword",
  "QualifiedIdentifier", "QualifiedIdentifier2", "OptAttributes",
  "AttributeList", "Attribute", "AttributeModifier",
  "AttributeArgsWithBrackets", "AttributeArguments",
  "AttributePositionalArguments", "AttributeNamedArguments",
  "AttributeNamedArgument", "TypeName", "PredefinedType", "ArrayRank",
  "RankList", "ArrayNameModifier", "InitializationRankList",
  "NamespaceDeclaration", "@1", "NamespaceBody", "NamespaceMemberList",
  "NamespaceMember", "TypeDeclaration", "NonModuleDeclaration",
  "OptModifiers", "ModifierList", "Modifier", "EnumDeclaration", "@2",
  "EnumBase", "EnumBaseType", "EnumBody", "EnumMemberList", "EnumMember",
  "StructureDeclaration", "@3", "ImplementsClause", "Implements",
  "StructBody", "StructMemberList", "StructMember", "ClassDeclaration",
  "@4", "ClassBase", "ModuleDeclaration", "@5", "InterfaceDeclaration",
  "@6", "InterfaceBases", "InterfaceBody", "InterfaceMemberList",
  "InterfaceMember", "DelegateDeclaration", "MethodMemberDeclaration",
  "MethodDeclaration", "ExternalMethodDeclaration", "SubDeclaration",
  "SubBody", "FunctionDeclaration", "FunctionBody",
  "ExternalSubDeclaration", "ExternalFunctionDeclaration", "ReturnType",
  "FormalParameters", "FormalParameterList", "FormalParameter",
  "OptParameterModifiers", "ParameterModifierList", "ParameterModifier",
  "ParameterType", "ParameterDefaultValue", "HandlesOrImplements",
  "OptMethodImplementsClause", "MethodImplementsClause",
  "EventHandlerList", "EventMemberSpecifier", "MethodImplementsList",
  "MethodImplements", "CharsetModifier", "LibraryClause", "AliasClause",
  "ConstructorMemberDeclaration", "EventMemberDeclaration",
  "ParametersOrType", "EventImplements", "ConstantMemberDeclaration",
  "VariableMemberDeclaration", "OptDim", "VariableDeclarators",
  "VariableDeclarator", "VariableIdentifier", "VarType",
  "VariableInitializer", "VariableInitializerList",
  "PropertyMemberDeclaration", "PropertyBody", "PropertyAccessors",
  "Getter", "GetBody", "Setter", "SetBody", "OptBlock", "Block",
  "OptLineBlock", "LineBlock", "Statement", "LineStatement",
  "InnerStatement", "InnerLineStatement", "LabeledStatement", "LabelName",
  "LocalDeclarationStatement", "WithStatement", "SyncLockStatement",
  "RaiseEventStatement", "AddHandlerStatement", "RemoveHandlerStatement",
  "HandlerArguments", "AssignmentStatement", "LetStatement",
  "VariableExpression", "InvocationStatement", "IfStatement", "IfRest",
  "ElseIfStatements", "ElseIfStatementList", "ElseIfStatement",
  "ElseStatement", "BooleanExpression", "SelectStatement", "SelectRest",
  "CaseStatements", "CaseStatementList", "CaseStatement", "CaseClauses",
  "CaseClause", "ComparisonOperator", "CaseElseStatement", "LoopStatement",
  "LoopControlVariable", "StepExpression", "NextExpression",
  "ExceptionHandlingStatement", "TryStatement", "CatchStatements",
  "CatchStatementList", "CatchStatement", "CatchName", "CatchWhen",
  "FinallyStatement", "ControlFlowStatement", "ArrayHandlingStatement",
  "RedimClauses", "RedimClause", "VariableExpressions",
  "PrimaryExpression", "DateLiteral", "DateValue", "DateSeparator",
  "TimeValue", "AmPm", "ArgumentList", "PositionalArgumentList",
  "NamedArgumentList", "ArgumentExpression", "ObjectCreationExpression",
  "ArrayElementInitializer", "CastTarget", "PowerExpression",
  "UnaryExpression", "MultiplicativeExpression",
  "IntegerDivisionExpression", "ModExpression", "AdditiveExpression",
  "ConcatenationExpression", "ShiftExpression", "RelationalExpression",
  "NotExpression", "AndExpression", "OrExpression", "Expression",
  "ConstantExpression", 0
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
      44,    61,    46,    60,    62,    58,    40,    41,   123,   125,
      45,    33,    35,    47,    94,    43,    42,    92,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   179,   180,   181,   181,   182,   182,   183,   184,   184,
     184,   185,   185,   186,   186,   187,   188,   188,   189,   189,
     190,   190,   191,   192,   192,   193,   193,   194,   194,   195,
     195,   196,   197,   197,   197,   198,   198,   198,   199,   199,
     199,   200,   200,   201,   201,   202,   203,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     210,   209,   211,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   215,   215,   215,   216,   216,   217,   217,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   220,   219,   221,
     221,   222,   222,   222,   222,   223,   223,   224,   224,   225,
     225,   227,   226,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   232,   232,   232,   232,   232,   234,   233,
     235,   235,   237,   236,   239,   238,   240,   240,   241,   241,
     242,   242,   243,   243,   243,   243,   244,   245,   245,   246,
     246,   247,   247,   248,   249,   249,   249,   250,   251,   251,
     251,   252,   253,   254,   254,   255,   255,   255,   256,   256,
     257,   258,   258,   259,   259,   260,   260,   260,   260,   261,
     261,   262,   262,   263,   263,   263,   264,   264,   265,   266,
     266,   267,   267,   268,   268,   269,   270,   270,   270,   270,
     271,   272,   272,   273,   274,   275,   275,   276,   276,   277,
     278,   279,   279,   280,   280,   281,   281,   282,   282,   283,
     283,   283,   283,   283,   284,   284,   284,   285,   285,   286,
     287,   287,   287,   288,   288,   288,   288,   289,   290,   290,
     290,   291,   292,   292,   292,   293,   293,   294,   294,   295,
     295,   296,   296,   297,   298,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   301,   301,   302,   302,   303,   303,   304,   305,
     306,   307,   308,   309,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   311,   312,   313,   313,   313,   314,   314,
     314,   314,   315,   316,   316,   317,   317,   318,   318,   319,
     319,   320,   321,   321,   322,   323,   323,   324,   324,   325,
     326,   326,   327,   327,   327,   327,   328,   328,   328,   328,
     328,   328,   329,   329,   330,   330,   330,   330,   330,   330,
     330,   331,   331,   332,   332,   333,   333,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   335,   336,   336,   337,
     337,   338,   339,   339,   340,   340,   341,   341,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     343,   343,   343,   344,   344,   345,   346,   346,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   348,   349,   349,   350,   350,   351,   351,
     351,   351,   352,   352,   353,   353,   353,   354,   354,   355,
     355,   356,   356,   357,   357,   357,   358,   358,   358,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   360,   360,   361,   361,   361,   362,   362,   362,   363,
     363,   364,   364,   365,   365,   365,   366,   366,   367,   367,
     367,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   369,   369,   370,   370,   370,   371,   371,   371,
     371,   372,   373
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     1,     2,     1,     4,     0,     1,
       1,     0,     1,     2,     1,     3,     3,     1,     1,     3,
       1,     1,     1,     3,     1,     3,     1,     0,     3,     2,
       1,     3,     0,     2,     2,     0,     2,     3,     1,     3,
       1,     3,     1,     3,     1,     4,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     2,     1,     3,     3,     3,     1,
       0,     8,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,    11,     0,
       2,     1,     1,     1,     1,     0,     1,     2,     1,     5,
       3,     0,    11,     0,     3,     3,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     0,    12,
       0,     3,     0,    10,     0,    11,     0,     3,     0,     1,
       1,     2,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     8,     0,     4,     3,     9,     0,     4,
       3,    10,    11,     0,     3,     0,     2,     3,     3,     1,
       5,     0,     1,     2,     1,     1,     1,     1,     1,     0,
       2,     0,     2,     0,     2,     1,     0,     1,     2,     2,
       1,     3,     3,     2,     1,     3,     0,     1,     1,     1,
       2,     0,     2,     7,     7,     1,     2,     0,     2,     8,
       5,     0,     1,     3,     1,     2,     4,     1,     2,     0,
       5,     2,     6,     3,     1,     2,     3,     3,     1,     9,
       0,     4,     3,     1,     1,     2,     2,     4,     0,     4,
       3,     4,     0,     4,     3,     0,     1,     3,     2,     0,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     2,     2,     6,     6,
       2,     2,     2,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     2,     2,     4,     5,
       4,     6,     5,     0,     1,     2,     1,     4,     5,     0,
       3,     1,     4,     5,     5,     0,     1,     2,     1,     4,
       3,     1,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     0,     3,     6,     6,     6,     6,     6,    11,
       8,     3,     1,     0,     2,     0,     1,     1,     2,     2,
       4,     5,     4,     1,     2,     2,     6,     0,     1,     2,
       1,     5,     0,     3,     0,     2,     0,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     2,
       2,     3,     2,     3,     1,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     4,     3,     4,     3,     2,     1,     2,     3,
       6,     6,     4,     4,     0,     5,     1,     1,     0,     2,
       4,     6,     0,     1,     3,     1,     1,     3,     1,     6,
       4,     1,     2,     3,     5,     6,     0,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     1,     2,     1,     3,     3,     1,     3,     3,
       3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,    11,     4,     6,    20,    21,     8,     1,
       0,    27,    12,    14,     5,    10,     0,     9,     0,    17,
      24,    18,     0,    32,    85,    76,     2,    27,    75,    77,
      79,    80,    81,    83,    78,    82,    84,    13,     7,    15,
       0,     0,     0,    24,     0,     0,     0,    32,    30,     0,
     106,    91,    94,   100,    95,    99,   102,    98,   101,    92,
      90,    89,   103,    93,    96,    97,   105,   104,     0,    86,
      88,    74,    16,    19,    22,    23,    70,    33,    34,    28,
      29,    52,    56,    54,    53,    55,    61,    58,    59,    49,
      57,    60,    51,    50,    46,    35,    47,     0,    27,     0,
       0,     0,     0,    87,    27,     0,    31,     0,    85,   156,
     159,   160,   109,     0,     0,     0,     0,   408,   409,   410,
     411,   412,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,     0,     0,   415,     0,   419,   421,
     420,     0,     0,   416,   414,     0,    65,     0,     0,    36,
       0,     0,   434,     0,   417,     0,    38,    40,    44,     0,
      63,   471,   413,   427,     0,   473,   476,   479,   481,   483,
     486,   488,   491,   502,   504,   507,   511,   512,    42,   140,
       0,     0,     0,   146,   142,   123,     0,     0,     0,     0,
     456,   417,   503,     0,   426,     0,   474,   428,     0,   438,
     475,     0,    37,     0,     0,    48,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,   111,
     113,   114,   112,   110,   107,     0,   144,    27,     0,   121,
       0,     0,     0,     0,     0,     0,   453,     0,   418,   436,
     437,     0,   442,     0,     0,    39,    41,     0,    43,   425,
       0,   423,   417,     0,   445,   446,   448,   451,   429,     0,
     472,   479,   482,   478,   477,   480,   485,   484,   487,   489,
     490,   494,   497,   498,   493,   499,   500,   492,   495,   496,
     505,   506,   508,   509,   510,     0,   138,   175,   175,    27,
     126,     0,    27,    85,   131,     0,    27,   129,   135,   157,
     158,   161,   162,   137,   134,   133,   132,   136,     0,    27,
      71,     0,     0,   422,   456,     0,     0,   457,   238,     0,
     234,   501,     0,   443,     0,   439,   433,    45,   452,     0,
     424,     0,     0,   432,   141,    62,    27,    27,   173,   193,
       0,     0,    27,   118,   147,     0,    85,   152,     0,    27,
     150,   154,   153,   155,   221,     0,   130,   124,     0,     0,
       0,   454,   456,   235,     0,     0,   458,     0,   442,     0,
     444,   447,     0,     0,   176,   181,     0,   179,    27,   193,
       0,     0,     0,   195,     0,     0,   117,   125,     0,     0,
     151,     0,   206,   222,     0,     0,     0,     0,     0,     0,
     430,   431,   455,   236,   237,   435,     0,   440,   450,     0,
       0,   185,   186,   187,   188,     0,   182,   184,    27,   177,
       0,     0,     0,     0,   194,   200,     0,   198,   204,   164,
     120,     0,     0,     0,   189,   207,   209,   208,     0,   175,
     175,   175,   227,     0,   224,   229,   143,     0,   442,     0,
       0,   189,   183,   178,   174,   168,     0,     0,   199,     0,
     203,   408,     0,     0,     0,     0,     0,   397,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     373,   398,     0,   396,     0,   367,   255,     0,     0,   417,
     163,     0,     0,   263,   265,     0,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   315,     0,   108,   145,     0,     0,     0,     0,
       0,   215,   217,   173,     0,    62,   228,   220,     0,     0,
     225,   122,   441,   449,   139,   191,   397,   167,     0,    26,
     202,   201,   205,   301,     0,   316,   297,   296,   255,     0,
       0,     0,   407,   402,   314,   369,   389,   390,   394,   392,
     393,   395,   391,     0,   417,     0,   362,   317,   295,   294,
     388,     0,   331,   313,     0,     0,   300,     0,     0,   400,
     404,   302,   374,   375,   399,     0,     0,     0,   368,   397,
     377,   256,     0,     0,   397,     0,   258,   293,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   190,     0,     0,
       0,   216,     0,     0,   196,   164,     0,     0,    69,   223,
       0,   231,     0,     0,   180,     0,   397,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,   255,     0,     0,
       0,   401,     0,     0,     0,   335,     0,   382,   386,   378,
     380,     0,     0,     0,   257,   292,   312,   307,   308,   309,
     306,   310,   311,     0,   304,     0,     0,   211,   211,   218,
     214,     0,   197,   213,    66,     0,    67,   233,    62,   226,
     192,   170,     0,    25,   303,     0,   255,   255,   406,     0,
     361,     0,   323,   318,   255,   320,   262,   264,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,   372,
     370,     0,   403,   335,     0,   332,   352,   336,   338,     0,
       0,   384,     0,     0,   379,     0,     0,   165,   305,   219,
     210,     0,   175,   175,   240,    68,    62,     0,   169,     0,
       0,     0,     0,     0,     0,     0,   329,   324,   326,   319,
     259,     0,   371,   405,   333,   351,   349,   350,     0,   346,
     347,   348,     0,   341,     0,   344,     0,     0,   337,     0,
       0,     0,     0,     0,     0,     0,     0,   212,   173,     0,
       0,     0,   239,     0,    27,    27,     0,   230,   358,   357,
     356,   355,     0,   363,     0,     0,     0,   325,   321,   260,
     261,     0,   255,     0,   342,     0,     0,     0,   299,   383,
     385,   255,   387,   376,   354,   298,     0,   171,     0,     0,
       0,     0,     0,   245,     0,   246,   232,   365,     0,     0,
     255,     0,     0,     0,   343,   339,   340,   345,   353,     0,
     381,   172,   242,   248,   252,     0,   366,   360,   364,   255,
     327,   255,   330,   322,   334,   397,   247,     0,   397,   251,
       0,   241,     0,   328,     0,   397,     0,   397,   365,   250,
       0,   254,     0,   359,   249,   253
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    16,    11,    12,    13,    18,
      19,   191,    75,    94,   560,   313,    47,    48,    49,   106,
     155,   156,   157,   158,   446,    96,   159,   160,   546,   637,
      25,   104,    26,    27,    28,    29,   314,    68,    69,    70,
      31,   309,   182,   243,   361,   362,   363,    32,   329,   249,
     311,   315,   316,   317,    33,   356,   236,    34,   247,    35,
     312,   246,   368,   369,   370,    36,   318,   319,   320,   110,
     510,   111,   557,   321,   322,   399,   358,   396,   397,   435,
     436,   437,   537,   644,   402,   691,   403,   444,   445,   447,
     448,   458,   687,   752,   323,   324,   542,   633,   325,   326,
     417,   463,   464,   465,   550,   338,   339,   327,   802,   803,
     804,   876,   805,   879,   712,   611,   818,   715,   512,   716,
     513,   717,   514,   515,   516,   517,   518,   519,   520,   521,
     563,   522,   523,   598,   524,   525,   713,   766,   767,   768,
     816,   591,   526,   735,   736,   737,   738,   782,   783,   784,
     787,   527,   585,   849,   867,   528,   529,   668,   669,   670,
     741,   792,   743,   530,   531,   599,   600,   573,   161,   162,
     199,   261,   263,   345,   273,   274,   275,   276,   163,   256,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   277,   178
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -610
static const yytype_int16 yypact[] =
{
     -22,    70,   154,    73,   -22,  -610,  -610,  -610,    64,  -610,
      70,    28,    73,  -610,  -610,  -610,   225,  -610,    33,  -610,
       3,   100,    70,    16,   827,  -610,  -610,    34,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
      70,    70,    70,  -610,    26,   118,   133,    11,  -610,   591,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,   228,   827,
    -610,  -610,  -610,   100,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,   100,   136,  -610,    70,   158,    70,
      70,    70,    70,  -610,    18,  1302,  -610,   307,   827,  -610,
    -610,  -610,   304,   330,   344,   348,   300,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,   208,   211,  -610,   215,  -610,  -610,
    -610,   591,  2456,  -610,  -610,  2456,  -610,    70,  2456,  -610,
    2592,    70,   380,  2592,   223,   236,   232,   247,  -610,   242,
     259,   128,  -610,  -610,   254,   248,  -610,   -39,   250,  -610,
     -87,   246,   303,   147,  -610,   367,   153,  -610,  -610,   337,
       9,    -5,   418,   343,  -610,   345,   329,  2456,  2456,  2456,
     205,  -610,  -610,   346,  -610,   268,  -610,  -610,   -45,   435,
    -610,   281,  -610,  2456,    70,  -610,  -610,    70,  1381,    70,
    2456,  2592,  2592,  2592,  2592,  2592,  2592,  2592,  2592,  2592,
    2592,  2592,  2592,  2592,  2592,  2592,  2592,  2592,  2592,  2592,
    2456,  2456,  2456,  2456,  2456,   591,   345,    70,    70,  -610,
    -610,  -610,  -610,  -610,  -610,   591,  -610,    61,   591,  -610,
     437,   292,   293,   287,  1166,  1517,  -610,   591,  -610,  -610,
    -610,   450,    29,   284,  2456,   247,  -610,   223,  -610,  -610,
    4628,  -610,   294,   290,   298,   302,  -610,  -610,  -610,   301,
    -610,   159,   250,  -610,  -610,   159,  -610,  -610,   -87,   246,
     246,   303,   303,   303,   303,   303,   303,   303,   303,   303,
    -610,  -610,   367,   367,   367,    21,  -610,   306,   306,    79,
     311,    36,    80,   827,  -610,   401,    87,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,    41,    61,
    -610,   591,   591,  -610,   305,   312,  1596,  -610,  -610,   -66,
    -610,   311,   -45,  -610,   465,  -610,  -610,  -610,   128,   319,
    -610,  1811,    70,  -610,  -610,   322,    61,   -54,   455,   308,
      70,   419,    95,  -610,  -610,   591,   827,  -610,   421,   111,
    -610,  -610,  -610,  -610,   318,   387,  -610,  -610,   423,   231,
     235,  -610,   305,  -610,   122,  1947,  -610,   489,    30,  1811,
     302,  -610,   331,   429,  -610,   229,   146,  -610,   158,   308,
     114,   591,   488,  -610,    25,   432,  -610,   311,   530,   412,
    -610,    70,    82,  -610,    70,    70,   117,    70,   497,   366,
    -610,  -610,  -610,  -610,  -610,  -610,   504,  -610,  -610,   350,
     464,  -610,  -610,  -610,  -610,    70,   229,  -610,   158,  -610,
     591,   505,   352,   356,   114,  -610,   115,   591,  -610,  2728,
    -610,  2456,   509,   510,   491,  -610,  -610,  -610,    57,     8,
     306,   306,   357,    44,  -610,   492,  -610,   515,   523,  1811,
     517,   491,  -610,  -610,   311,  2898,    70,    70,  -610,    70,
    -610,   363,  1811,  4628,    70,    70,    75,   386,  2456,  2456,
     289,  4550,  4628,   342,  2456,  4628,   459,  4628,  2026,  1811,
      72,  2456,  2162,  -610,  2456,  2456,  3068,  2456,  2456,   369,
    -610,  3238,   521,  -610,  -610,   371,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,    49,   522,  -610,  -610,   591,   379,    70,    70,
     591,  -610,   456,   455,   533,  2241,  -610,  -610,    70,   460,
     383,  -610,  -610,  -610,  -610,   384,   468,  -610,  3408,  -610,
     388,   388,  -610,  -610,   391,   128,  -610,  -610,  3068,  2456,
    2456,   542,  -610,   393,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  4628,   524,   395,   128,   128,  -610,  -610,
    -610,    27,  -610,  -610,    49,    -4,   128,  2456,   392,   399,
    -610,  -610,  -610,  -610,  -610,  2456,   550,   551,  -610,  -610,
     525,  3068,   552,   553,   425,   556,  -610,  3068,  2456,  2456,
    2456,  2456,  2456,  2456,  2456,  2377,  -610,   311,  2456,   476,
     476,   311,   591,   560,   487,  2728,   406,   155,  -610,  -610,
     591,   408,  1947,  2456,  -610,   565,   498,    70,  1811,   481,
     569,   570,  -610,  2456,   494,   591,  2456,  3068,  4258,    20,
     477,   399,  2456,  2456,   574,   547,  3068,    70,   511,   525,
    -610,  3068,  3068,   577,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  4628,  -610,   579,   582,   566,   566,   591,
    -610,   583,  -610,  -610,  -610,  2456,  -610,   434,  1732,  -610,
    -610,  -610,   588,  -610,  -610,   132,  3068,  3068,  -610,  2456,
     311,   458,   536,  -610,  3068,   -14,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,   601,  -610,
    -610,   156,  -610,   547,  1087,  -610,   571,   547,  -610,   539,
     581,   461,   602,   549,  -610,   554,   555,  -610,   128,  -610,
    -610,   609,   306,   306,   -10,  -610,  1732,   454,  -610,  2456,
    2456,   529,   531,   618,  2456,  2456,   563,   536,  -610,  -610,
    4404,  4404,  -610,  -610,  -610,  -610,  -610,  -610,    62,  -610,
    -610,  -610,    45,  -610,  2456,   483,   567,   564,  -610,   496,
     591,  2456,   625,  3068,   495,   486,   480,  -610,   455,   628,
     519,   134,  -610,   575,   116,   130,   478,  -610,  -610,  -610,
    -610,  -610,   543,   512,    35,   642,   589,  -610,  -610,   499,
    -610,  2456,  3068,  1087,  -610,  2456,  3068,   527,  -610,   311,
    -610,  3068,  -610,  -610,  -610,  -610,   650,  -610,   651,   652,
     657,   545,   541,  -610,   590,  -610,  -610,    70,  2456,   665,
    3068,   667,  3068,   594,  -610,  -610,  -610,  -610,  -610,   669,
    -610,  -610,  -610,  3578,  3748,   671,  -610,  -610,  -610,  3068,
    -610,  3068,  -610,  -610,  -610,   603,  -610,  3918,   557,  -610,
    4088,  -610,   585,  -610,   673,   606,   677,   561,    70,  -610,
     679,  -610,   685,  -610,  -610,  -610
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -610,  -610,  -610,  -610,   695,  -610,  -610,  -610,   688,  -610,
     661,    -1,   177,   279,   226,    -9,  -610,   662,  -610,  -610,
    -610,  -610,   501,   506,   -36,  -610,   163,  -610,  -610,    63,
    -610,  -610,   607,  -610,   696,  -610,    -7,   -94,  -610,   655,
    -610,  -610,  -610,  -610,  -610,  -610,   364,  -610,  -610,   500,
     482,   -49,  -610,   415,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,   365,  -610,  -220,   635,  -610,  -610,
     102,  -610,  -610,  -610,  -610,  -528,  -303,  -610,   297,  -610,
    -610,   310,   267,  -610,   340,  -610,   106,  -610,   299,   109,
    -425,  -610,   112,    59,  -610,   -98,  -610,  -610,  -610,  -610,
    -610,  -610,  -377,  -610,  -610,  -369,   413,   -55,  -610,  -610,
     -57,  -610,   -53,  -610,  -489,  -446,  -610,   -20,  -505,   -19,
    -610,  -610,  -610,  -474,  -609,  -610,  -610,  -601,  -542,  -539,
     257,  -485,  -531,  -461,  -525,  -610,    39,  -610,  -610,    -6,
    -610,  -499,  -610,    24,  -610,  -610,    23,  -610,   -65,   -16,
    -610,  -610,   180,  -610,  -124,  -522,  -610,  -610,  -610,    96,
    -610,  -610,  -610,  -519,  -516,   171,   107,  -610,   201,  -610,
    -610,   431,  -610,  -344,  -253,  -610,   420,  -339,  -610,  -241,
    -610,  -610,   125,   129,   562,   189,   559,   192,   493,  -610,
     -86,   123,  -610,   278,  -192
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -296
static const yytype_int16 yytable[] =
{
       8,   335,    24,   511,    30,   359,   615,    17,   612,    20,
     593,   266,   391,    95,   180,   634,   424,   610,    24,   590,
      30,    43,   480,     6,     7,   588,   603,   572,   -72,   558,
     239,   354,   343,   343,   -73,   450,    76,   657,   540,    20,
      43,    74,    45,    39,   427,   850,   364,    45,    43,   718,
     428,   377,   770,   615,   547,   822,   192,   719,   800,   212,
     618,   619,   620,   621,   622,   623,   624,     6,     7,   -27,
     650,   651,   347,     6,     7,     6,     7,   588,   659,   649,
     775,   776,   777,   216,   240,   568,   -72,   237,   217,   108,
     241,     1,   371,   381,   385,    24,   107,    30,   112,   113,
     114,   115,   -73,   386,   154,   190,   615,   566,   567,    23,
      46,   455,   675,   394,   456,    46,   720,     6,     7,   721,
       6,     7,    22,   -27,   552,   259,   660,   723,   260,  -127,
     553,   242,    22,   724,   213,   538,   725,   214,    22,   726,
      43,   422,   727,   564,   300,   301,    74,  -115,  -148,   371,
      74,   771,   238,    23,     9,  -128,   541,   543,   544,    10,
     564,   718,   718,  -116,    41,   221,   222,   223,   224,   719,
     719,   639,   658,   722,   357,    79,    15,   739,   602,  -149,
     851,    23,   745,   746,  -243,   729,   451,   355,    42,   511,
     728,    23,   708,    40,   344,   426,   365,    23,  -244,   305,
     539,   365,   154,   267,   548,   823,    74,   272,    74,   310,
     625,   207,   310,   839,   372,   208,   442,   761,   762,   374,
     209,   341,   461,   779,    23,   780,   781,   569,   720,   720,
     570,   721,   721,   457,    43,    38,   307,   308,   225,   723,
     723,   226,    23,    23,    43,   724,   724,    43,   725,   725,
      23,   726,   726,   272,   727,   727,    43,   373,    23,   533,
     808,   809,    42,   431,   480,   432,   814,   840,   232,   233,
     836,   372,   408,   699,    23,   196,    97,   479,   200,    23,
     378,   355,   385,    77,   759,   722,   722,   760,    98,    21,
     207,   423,   830,    23,   208,   379,   380,    99,    78,   209,
     360,    44,   105,   366,   832,   367,   438,   393,   227,   704,
     228,   229,   234,   439,   373,   695,   695,   179,   100,    21,
      73,    23,   696,   773,   194,   219,   220,   101,   197,   407,
      43,    43,   213,   855,   181,   214,   280,   858,   283,   284,
     183,   281,   860,   433,   285,     6,     7,   588,   395,   434,
     272,   392,   576,   360,   184,   302,   303,   304,   185,   404,
     366,   870,   367,   872,    43,   577,    97,   578,   186,   411,
     102,   254,   615,   255,   187,   615,   412,   188,    98,   413,
     882,   189,   883,   177,   269,   198,   278,    99,   201,   440,
     414,   400,   203,   401,   230,   231,   237,   355,   420,   443,
      43,   355,   421,   202,   474,   286,   287,   204,   100,   205,
     454,   289,   290,   459,   460,   308,   462,   877,   880,   206,
     210,   579,   211,   193,   218,   235,   195,   215,   244,   395,
     248,   245,   580,   250,   471,   258,   685,   257,   581,    43,
     262,   415,   264,   443,   582,   757,    43,   330,   509,   798,
     799,   700,   331,   332,   333,   342,   346,   350,   351,   349,
     102,   416,   352,     6,     7,   251,   252,   253,   353,   375,
     388,   348,   357,   255,   509,   559,   559,   355,   562,   382,
     389,   177,   146,   462,   462,   398,   418,   405,   279,   409,
     584,   419,   589,    81,   425,    82,   429,   430,   449,   589,
     627,   452,   453,   806,   631,   509,    83,   466,   467,   468,
     509,   469,   470,   641,   476,   475,    84,    85,   477,   534,
     535,   536,   549,   545,    86,   551,   343,   554,  -295,   571,
     595,   616,   626,   340,  -294,    43,   617,   629,   630,    43,
     628,   632,   177,   635,   642,   643,   645,   462,    43,    87,
     647,   648,   652,   653,   655,    88,   656,   509,   662,   663,
     665,   666,   671,   672,   667,   640,   674,   509,   673,   686,
     690,    89,   401,   694,   698,   701,   702,   705,    97,   706,
     707,   709,   584,   730,   733,   734,   742,   747,   412,   749,
      98,   750,   751,   754,     6,     7,    90,    91,   758,    99,
     756,    92,   414,   765,   697,   764,   772,   789,   237,   786,
     509,   790,   793,    93,   340,   791,   509,   794,   797,   710,
     100,   807,   795,   796,    81,   810,    82,   811,   812,   815,
     825,    43,   827,   826,   509,   831,   835,    83,   837,    43,
     828,   834,   838,   841,   833,   846,   703,    84,    85,   847,
     532,   848,   852,   415,    43,    86,   509,   853,   589,   859,
     861,   862,   863,   340,   771,   509,   740,   864,   865,   839,
     509,   509,   102,   238,   840,   869,   532,   871,   873,   874,
      87,   881,   884,   889,   565,   890,    88,   891,    43,   894,
     886,   888,   586,   587,   892,   895,   594,   272,   596,    14,
      37,    72,    89,   561,   265,   509,   509,   532,   636,    80,
     268,   116,   532,   509,   291,   292,   293,   294,   295,   296,
     297,   298,   299,    71,   103,   731,   406,    90,    91,   177,
     328,   376,    92,   109,   410,   473,   306,   693,   555,   441,
     692,   689,   688,   478,    93,   801,   472,   753,   845,   384,
     819,   843,   820,   769,   829,   272,   601,   774,   856,   532,
     788,   817,   821,   654,   893,   744,   574,   575,   661,   532,
     732,   390,   592,   387,   282,     0,   574,   288,     0,   604,
     606,     0,   607,   608,   586,   592,   613,     0,     0,    43,
       0,     0,   509,     0,     0,   842,   844,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   532,     0,     0,     0,     0,     0,   532,     0,
       0,   509,     0,   638,     0,   509,     0,     0,     0,     0,
     509,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   866,   592,   592,   509,
       0,   509,     0,     0,     0,     0,     0,     0,   532,   532,
       0,     0,   509,   509,     0,     0,     0,   532,   509,     0,
     509,     0,   532,   532,     0,   574,   509,     0,     0,   509,
       0,     0,     0,   664,   748,     0,    50,   866,     0,     0,
       0,     0,     0,     0,     0,     0,   676,   677,   678,   679,
     680,   681,   682,   684,    51,     0,   177,   532,   532,     0,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
     340,   177,     0,     0,     0,     0,     0,    52,    53,     0,
       0,   574,     0,     0,   711,     0,    54,    55,     0,     0,
     638,   574,     0,     0,    56,    57,    58,     0,     0,    59,
       0,    60,    61,     0,    62,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,    65,     0,     0,     0,     0,
       0,   532,   532,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,    67,     0,   763,     0,     0,
       0,     0,     0,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   785,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   532,     0,     0,     0,   532,     0,     0,
       0,     0,   532,     0,     0,     0,     0,   592,   592,     0,
       0,     0,   813,   592,     0,     0,     0,     0,     0,     0,
       0,   532,     0,   532,     0,     0,     0,     0,     0,     0,
       0,     0,   824,     0,   532,   532,     0,     0,     0,   592,
     532,     0,   532,     0,     0,     0,     0,     0,   532,     0,
       0,   532,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,   117,   118,   119,   120,   121,     0,     0,   854,
       0,   785,     0,   857,     0,   775,   776,   777,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   868,   122,   123,   124,
     125,   126,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,   137,     0,     6,
       7,   117,   118,   119,   120,   121,     0,     0,   778,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,   139,
     140,   270,   141,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     126,   127,     0,   128,     0,   129,   130,     0,   131,   132,
     133,   134,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,   144,     0,   145,     0,     0,
     136,     0,     0,     0,     0,     0,   137,     0,   779,   147,
     780,   781,     0,   148,     0,     0,     0,   150,   151,   152,
       0,     0,   153,   138,     0,     0,     0,     0,   139,   140,
       0,   141,     0,   142,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,   117,   118,   119,
     120,   121,     0,     0,   144,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,     0,   147,     0,
       0,     0,   148,   334,     0,     0,   150,   151,   152,     0,
       0,   153,   122,   123,   124,   125,   126,   127,     0,   128,
       0,   129,   130,     0,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,   137,     0,     6,     7,   117,   118,   119,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,   139,   140,   270,   141,     0,   142,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,     0,     0,     0,
     144,     0,   145,     0,     0,   136,     0,     0,     0,     0,
       0,   137,   146,     0,   147,     0,     0,     0,   148,   149,
       0,     0,   150,   151,   152,     0,     0,   153,   138,     0,
       0,     0,     0,   139,   140,     0,   141,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,   117,   118,   119,   120,   121,     0,     0,   144,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,     0,     0,     0,   148,   271,     0,
       0,   150,   151,   152,     0,     0,   153,   122,   123,   124,
     125,   126,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,   137,     0,     6,
       7,   117,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,   139,
     140,     0,   141,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     126,   127,     0,   128,     0,   129,   130,     0,   131,   132,
     133,   134,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,   144,     0,   145,     0,     0,
     136,     0,     0,     0,     0,     0,   137,     0,     0,   147,
       0,     0,     0,   148,     0,   336,   337,   150,   151,   152,
       0,     0,   153,   138,     0,     0,     0,     0,   139,   140,
       0,   141,     0,   142,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,   117,   118,   119,
     120,   121,     0,     0,   144,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   147,     0,
       0,     0,   148,     0,   336,   383,   150,   151,   152,     0,
       0,   153,   122,   123,   124,   125,   126,   127,     0,   128,
       0,   129,   130,     0,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,   137,     0,     6,     7,   117,   118,   119,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,   139,   140,   270,   141,     0,   142,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,     0,     0,     0,
     144,     0,   145,     0,     0,   136,     0,     0,     0,     0,
       0,   137,   146,     0,   147,     0,     0,     0,   148,     0,
       0,     0,   150,   151,   152,     0,     0,   153,   138,     0,
       0,     0,     0,   139,   140,     0,   141,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,   117,   118,   119,   120,   121,     0,     0,   144,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,     0,     0,     0,   148,     0,     0,
       0,   150,   151,   152,     0,     0,   153,   122,   123,   124,
     125,   126,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,   137,     0,     6,
       7,   117,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,   139,
     140,     0,   141,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     126,   127,     0,   128,     0,   129,   130,     0,   131,   132,
     133,   134,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,   144,     0,   145,     0,     0,
     136,     0,     0,     0,     0,     0,   137,     0,     0,   147,
       0,     0,     0,   148,     0,   336,     0,   150,   151,   152,
       0,     0,   153,   138,     0,     0,     0,     0,   139,   140,
       0,   141,     0,   142,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   597,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,   117,   118,   119,
     120,   121,     0,     0,   144,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,     0,
       0,     0,   148,     0,     0,     0,   150,   151,   152,     0,
     605,   153,   122,   123,   124,   125,   126,   127,     0,   128,
       0,   129,   130,     0,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,   137,     0,     6,     7,   117,   118,   119,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,   139,   140,     0,   141,     0,   142,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,     0,     0,     0,
     144,     0,   145,     0,     0,   136,     0,     0,     0,     0,
       0,   137,     0,     0,   147,     0,     0,     0,   148,     0,
       0,     0,   150,   151,   152,     0,     0,   153,   138,     0,
       0,     0,     0,   139,   140,     0,   141,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,   117,   118,   119,   120,   121,     0,     0,   144,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   683,   147,     0,     0,     0,   148,     0,     0,
       0,   150,   151,   152,     0,     0,   153,   122,   123,   124,
     125,   126,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,   137,     0,     6,
       7,   117,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,   139,
     140,     0,   141,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     126,   127,     0,   128,     0,   129,   130,     0,   131,   132,
     133,   134,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,   144,     0,   145,     0,     0,
     136,     0,     0,     0,     0,     0,   137,     0,     0,   147,
       0,     0,     0,   148,     0,     0,     0,   150,   151,   152,
       0,     0,   153,   138,     0,     0,     0,     0,   139,   140,
       0,   141,     0,   142,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,   117,   118,   119,
     120,   121,     0,     0,   144,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,     0,
       0,     0,   148,     0,     0,     0,   150,   151,   152,     0,
       0,   153,   122,   123,   124,   125,   126,   127,     0,   128,
       0,   129,   130,     0,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,   139,   140,     0,   141,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     7,   481,   118,   119,   120,   121,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,   147,     0,     0,     0,   148,     0,
       0,     0,   150,   151,   152,   483,     0,   153,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   487,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   556,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   609,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   614,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   646,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   875,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   878,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   885,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   481,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,   486,     0,     0,     0,     0,   887,     0,   488,   489,
       0,   490,   136,     0,   491,     0,     0,     0,   137,   492,
     493,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
     502,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,   504,     0,   505,     0,   144,   506,     0,     0,
       0,     0,     0,   507,   508,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152,     6,     7,   117,   118,   119,   120,   121,   714,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   484,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   485,
     135,     0,     0,     0,     0,     0,   609,     0,   488,   489,
       0,   490,   136,     0,     0,     0,     0,     0,   137,   492,
     493,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   498,   499,   500,   501,
       0,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,   505,     0,   144,     6,     7,   117,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,   482,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,     0,     0,   122,   123,   124,   125,   126,   127,
       0,   128,     0,   129,   130,   484,   131,   132,   133,   134,
       0,     0,     0,     0,     0,   485,   135,     0,     0,     0,
       0,     0,   609,     0,   488,   489,     0,   490,   136,     0,
       0,     0,     0,     0,   137,   492,   493,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,     0,     0,     0,
       0,   138,     0,     0,     0,     0,   139,   140,     0,   141,
       0,     0,   143,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,     0,   498,   499,   500,   501,     0,     0,     0,     0,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
     505,     0,   144,     6,     7,   117,   118,   119,   120,   121,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
     148,     0,     0,     0,     0,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,   125,   126,   127,     0,   128,     0,   129,
     130,     0,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,   135,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
     137,     6,     7,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,   139,   140,     0,   141,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   128,     0,   129,   130,     0,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
     135,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   136,     0,     0,     0,     0,     0,   137,     0,
       0,     0,   147,     0,     0,     0,   148,     0,     0,     0,
       0,   151,   152,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,   141,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   148,     0,     0,     0,     0,   151,
     152
};

static const yytype_int16 yycheck[] =
{
       1,   254,    11,   449,    11,   308,   511,     8,   507,    10,
     495,   203,   351,    49,   108,   543,   385,   506,    27,   493,
      27,    22,   447,     3,     4,     5,   500,   488,     0,   475,
      35,    10,     3,     3,     0,    10,    10,    10,    30,    40,
      41,    42,    31,    10,   388,    10,    10,    31,    49,   658,
     389,    10,    66,   558,    10,    10,   142,   658,    68,    98,
      11,    12,    13,    14,    15,    16,    17,     3,     4,    79,
     569,   570,   264,     3,     4,     3,     4,     5,    82,   568,
      18,    19,    20,   170,    89,    10,    68,    78,   175,    98,
      95,   113,   312,   334,   160,   104,    97,   104,    99,   100,
     101,   102,    68,   169,   105,   141,   611,   484,   485,   163,
      99,    29,   617,   167,    32,    99,   658,     3,     4,   658,
       3,     4,   104,   133,   468,   170,   130,   658,   173,    68,
     469,   136,   104,   658,   173,    78,   658,   176,   104,   658,
     141,   382,   658,   482,   230,   231,   147,    68,    68,   369,
     151,   165,   143,   163,     0,    68,   459,   460,   461,    86,
     499,   770,   771,    68,   161,    18,    19,    20,    21,   770,
     771,   548,   145,   658,   166,   164,   112,   666,   106,    68,
     145,   163,   671,   672,    68,   659,   161,   166,   162,   635,
     170,   163,   653,   160,   165,   165,   160,   163,    68,   235,
     143,   160,   203,   204,   160,   160,   207,   208,   209,   245,
     161,   162,   248,    79,   312,   166,   102,   706,   707,   313,
     171,   257,   105,   161,   163,   163,   164,   152,   770,   771,
     155,   770,   771,   151,   235,    10,   237,   238,    91,   770,
     771,    94,   163,   163,   245,   770,   771,   248,   770,   771,
     163,   770,   771,   254,   770,   771,   257,   312,   163,   451,
     759,   760,   162,    34,   689,    36,   765,   133,   115,   116,
     798,   369,   366,   642,   163,   150,    48,   162,   153,   163,
     329,   166,   160,   165,   152,   770,   771,   155,    60,    10,
     162,   169,   791,   163,   166,   331,   332,    69,   165,   171,
     309,    22,   166,   312,   793,   312,   160,   356,   161,   648,
     163,   164,   159,   167,   369,   160,   160,    10,    90,    40,
      41,   163,   167,   167,   147,    22,    23,    99,   151,   365,
     331,   332,   173,   822,    30,   176,   211,   826,   213,   214,
      10,   212,   831,   114,   215,     3,     4,     5,   357,   120,
     351,   352,    63,   362,    10,   232,   233,   234,    10,   360,
     369,   850,   369,   852,   365,    76,    48,    78,    68,    51,
     142,   166,   877,   168,   166,   880,    58,   166,    60,    61,
     869,   166,   871,   105,   207,     5,   209,    69,   165,   398,
      72,    83,   160,    85,    27,    28,    78,   166,   167,   400,
     401,   166,   167,   167,   440,   216,   217,   160,    90,   167,
     411,   219,   220,   414,   415,   416,   417,   863,   864,   160,
     166,   132,   174,   145,   178,    88,   148,   177,    10,   438,
      85,    88,   143,   104,   435,   167,   628,    91,   149,   440,
       5,   123,   161,   444,   155,   698,   447,    10,   449,   752,
     753,   643,   160,   160,   167,     5,   172,   167,   160,   165,
     142,   143,   160,     3,     4,   187,   188,   189,   167,    68,
       5,   270,   166,   168,   475,   476,   477,   166,   479,   167,
     161,   203,   160,   484,   485,    30,    99,    68,   210,    68,
     491,    68,   493,    33,     5,    35,   165,    68,    10,   500,
     536,    69,    90,   756,   540,   506,    46,    10,   142,     5,
     511,   161,    48,   549,   162,    10,    56,    57,   162,    10,
      10,    30,    30,   166,    64,    10,     3,    10,   165,   143,
      71,    10,    10,   255,   165,   536,   165,   538,   539,   540,
     161,    85,   264,    10,   161,   161,    78,   548,   549,    89,
     162,   160,    10,   160,    30,    95,   161,   558,   166,   160,
      10,    10,    10,    10,    39,   105,    10,   568,   143,    93,
      10,   111,    85,   167,   166,    10,    78,    96,    48,    10,
      10,    87,   583,   106,    10,    38,    75,    10,    58,    10,
      60,     9,    26,    10,     3,     4,   136,   137,    10,    69,
     166,   141,    72,    67,   640,   147,     5,    68,    78,    38,
     611,    30,    10,   153,   336,   154,   617,    68,     9,   655,
      90,   167,    68,    68,    33,    96,    35,    96,    10,    66,
     147,   632,    68,    66,   635,    10,   156,    46,    10,   640,
     144,   155,   123,    68,   149,   167,   647,    56,    57,   106,
     449,   139,    10,   123,   655,    64,   657,    68,   659,   132,
      10,    10,    10,   385,   165,   666,   667,    10,   123,    79,
     671,   672,   142,   143,   133,    10,   475,    10,    84,    10,
      89,    10,    79,    10,   483,    79,    95,    10,   689,    10,
     133,   106,   491,   492,   133,    10,   495,   698,   497,     4,
      12,    40,   111,   477,   203,   706,   707,   506,   545,    47,
     204,   104,   511,   714,   221,   222,   223,   224,   225,   226,
     227,   228,   229,    27,    69,   662,   362,   136,   137,   451,
     248,   316,   141,    98,   369,   438,   236,   635,   471,   399,
     634,   632,   630,   444,   153,   754,   436,   688,   805,   336,
     770,   804,   771,   714,   790,   756,   499,   733,   823,   558,
     737,   767,   778,   583,   888,   669,   488,   489,   597,   568,
     663,   351,   494,   342,   212,    -1,   498,   218,    -1,   501,
     502,    -1,   504,   505,   583,   507,   508,    -1,    -1,   790,
      -1,    -1,   793,    -1,    -1,   804,   805,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,   617,    -1,
      -1,   822,    -1,   545,    -1,   826,    -1,    -1,    -1,    -1,
     831,    -1,    -1,    -1,    -1,    -1,   635,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   847,   569,   570,   850,
      -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,   657,   658,
      -1,    -1,   863,   864,    -1,    -1,    -1,   666,   869,    -1,
     871,    -1,   671,   672,    -1,   597,   877,    -1,    -1,   880,
      -1,    -1,    -1,   605,   683,    -1,    59,   888,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   618,   619,   620,   621,
     622,   623,   624,   625,    77,    -1,   628,   706,   707,    -1,
      -1,    -1,    -1,    -1,    -1,   714,    -1,    -1,    -1,    -1,
     642,   643,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
      -1,   653,    -1,    -1,   656,    -1,   109,   110,    -1,    -1,
     662,   663,    -1,    -1,   117,   118,   119,    -1,    -1,   122,
      -1,   124,   125,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,   770,   771,   695,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,    -1,   709,    -1,    -1,
      -1,    -1,    -1,    -1,   793,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   822,    -1,    -1,    -1,   826,    -1,    -1,
      -1,    -1,   831,    -1,    -1,    -1,    -1,   759,   760,    -1,
      -1,    -1,   764,   765,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   850,    -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   784,    -1,   863,   864,    -1,    -1,    -1,   791,
     869,    -1,   871,    -1,    -1,    -1,    -1,    -1,   877,    -1,
      -1,   880,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,   821,
      -1,   823,    -1,   825,    -1,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   848,    40,    41,    42,
      43,    44,    45,    -1,    47,    -1,    49,    50,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,   102,
     103,    25,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,   161,   162,
     163,   164,    -1,   166,    -1,    -1,    -1,   170,   171,   172,
      -1,    -1,   175,    97,    -1,    -1,    -1,    -1,   102,   103,
      -1,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,   162,    -1,
      -1,    -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,
      -1,   175,    40,    41,    42,    43,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,   102,   103,    25,   105,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    -1,    47,    -1,
      49,    50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,   150,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    80,   160,    -1,   162,    -1,    -1,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,   175,    97,    -1,
      -1,    -1,    -1,   102,   103,    -1,   105,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,   148,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,   166,   167,    -1,
      -1,   170,   171,   172,    -1,    -1,   175,    40,    41,    42,
      43,    44,    45,    -1,    47,    -1,    49,    50,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,   102,
     103,    -1,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,   162,
      -1,    -1,    -1,   166,    -1,   168,   169,   170,   171,   172,
      -1,    -1,   175,    97,    -1,    -1,    -1,    -1,   102,   103,
      -1,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   162,    -1,
      -1,    -1,   166,    -1,   168,   169,   170,   171,   172,    -1,
      -1,   175,    40,    41,    42,    43,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,   102,   103,    25,   105,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    -1,    47,    -1,
      49,    50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,   150,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    80,   160,    -1,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   171,   172,    -1,    -1,   175,    97,    -1,
      -1,    -1,    -1,   102,   103,    -1,   105,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,   148,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,   171,   172,    -1,    -1,   175,    40,    41,    42,
      43,    44,    45,    -1,    47,    -1,    49,    50,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,   102,
     103,    -1,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,   162,
      -1,    -1,    -1,   166,    -1,   168,    -1,   170,   171,   172,
      -1,    -1,   175,    97,    -1,    -1,    -1,    -1,   102,   103,
      -1,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,   171,   172,    -1,
      38,   175,    40,    41,    42,    43,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,   102,   103,    -1,   105,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    -1,    47,    -1,
      49,    50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,   150,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   171,   172,    -1,    -1,   175,    97,    -1,
      -1,    -1,    -1,   102,   103,    -1,   105,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,   148,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,    25,   162,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,   171,   172,    -1,    -1,   175,    40,    41,    42,
      43,    44,    45,    -1,    47,    -1,    49,    50,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,   102,
     103,    -1,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,   162,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   171,   172,
      -1,    -1,   175,    97,    -1,    -1,    -1,    -1,   102,   103,
      -1,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,   171,   172,    -1,
      -1,   175,    40,    41,    42,    43,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,   102,   103,    -1,   105,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   171,   172,    37,    -1,   175,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,   146,    -1,   148,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    24,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      -1,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    71,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,   102,   103,    -1,   105,
      -1,    -1,   108,    -1,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
     146,    -1,   148,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    -1,    47,    -1,    49,
      50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      80,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,   102,   103,    -1,   105,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,    50,    -1,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,   171,   172,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
     172
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   113,   180,   181,   182,   183,     3,     4,   190,     0,
      86,   185,   186,   187,   183,   112,   184,   190,   188,   189,
     190,   192,   104,   163,   194,   209,   211,   212,   213,   214,
     215,   219,   226,   233,   236,   238,   244,   187,    10,    10,
     160,   161,   162,   190,   192,    31,    99,   195,   196,   197,
      59,    77,   100,   101,   109,   110,   117,   118,   119,   122,
     124,   125,   127,   134,   135,   138,   157,   158,   216,   217,
     218,   213,   189,   192,   190,   191,    10,   165,   165,   164,
     196,    33,    35,    46,    56,    57,    64,    89,    95,   111,
     136,   137,   141,   153,   192,   203,   204,    48,    60,    69,
      90,    99,   142,   218,   210,   166,   198,   190,   194,   246,
     248,   250,   190,   190,   190,   190,   211,     5,     6,     7,
       8,     9,    40,    41,    42,    43,    44,    45,    47,    49,
      50,    52,    53,    54,    55,    62,    74,    80,    97,   102,
     103,   105,   107,   108,   148,   150,   160,   162,   166,   167,
     170,   171,   172,   175,   190,   199,   200,   201,   202,   205,
     206,   347,   348,   357,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,    10,
     216,    30,   221,    10,    10,    10,    68,   166,   166,   166,
     203,   190,   369,   372,   191,   372,   361,   191,     5,   349,
     361,   165,   167,   160,   160,   167,   160,   162,   166,   171,
     166,   174,    98,   173,   176,   177,   170,   175,   178,    22,
      23,    18,    19,    20,    21,    91,    94,   161,   163,   164,
      27,    28,   115,   116,   159,    88,   235,    78,   143,    35,
      89,    95,   136,   222,    10,    88,   240,   237,    85,   228,
     104,   372,   372,   372,   166,   168,   358,    91,   167,   170,
     173,   350,     5,   351,   161,   201,   373,   190,   202,   191,
      25,   167,   190,   353,   354,   355,   356,   372,   191,   372,
     361,   362,   363,   361,   361,   362,   364,   364,   365,   366,
     366,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     369,   369,   370,   370,   370,   203,   228,   190,   190,   220,
     203,   229,   239,   194,   215,   230,   231,   232,   245,   246,
     247,   252,   253,   273,   274,   277,   278,   286,   229,   227,
      10,   160,   160,   167,   167,   353,   168,   169,   284,   285,
     372,   203,     5,     3,   165,   352,   172,   373,   347,   165,
     167,   160,   160,   167,    10,   166,   234,   166,   255,   255,
     194,   223,   224,   225,    10,   160,   194,   215,   241,   242,
     243,   245,   274,   286,   216,    68,   232,    10,   230,   203,
     203,   358,   167,   169,   285,   160,   169,   350,     5,   161,
     355,   356,   190,   230,   167,   194,   256,   257,    30,   254,
      83,    85,   263,   265,   190,    68,   225,   203,   216,    68,
     243,    51,    58,    61,    72,   123,   143,   279,    99,    68,
     167,   167,   358,   169,   284,     5,   165,   352,   356,   165,
      68,    34,    36,   114,   120,   258,   259,   260,   160,   167,
     194,   263,   102,   190,   266,   267,   203,   268,   269,    10,
      10,   161,    69,    90,   190,    29,    32,   151,   270,   190,
     190,   105,   190,   280,   281,   282,    10,   142,     5,   161,
      48,   190,   260,   257,   203,    10,   162,   162,   267,   162,
     269,     5,    24,    37,    51,    61,    63,    68,    70,    71,
      73,    76,    81,    82,    84,    92,   112,   126,   128,   129,
     130,   131,   132,   140,   144,   146,   149,   155,   156,   190,
     249,   294,   297,   299,   301,   302,   303,   304,   305,   306,
     307,   308,   310,   311,   313,   314,   321,   330,   334,   335,
     342,   343,   347,   373,    10,    10,    30,   261,    78,   143,
      30,   255,   275,   255,   255,   166,   207,    10,   160,    30,
     283,    10,   352,   356,    10,   261,    68,   251,   294,   190,
     193,   193,   190,   309,   356,   347,   281,   281,    10,   152,
     155,   143,   312,   346,   372,   372,    63,    76,    78,   132,
     143,   149,   155,    65,   190,   331,   347,   347,     5,   190,
     302,   320,   372,   310,   347,    71,   347,   121,   312,   344,
     345,   309,   106,   302,   372,    38,   372,   372,   372,    68,
     293,   294,   320,   372,    68,   297,    10,   165,    11,    12,
      13,    14,    15,    16,    17,   161,    10,   203,   161,   190,
     190,   203,    85,   276,   254,    10,   205,   208,   372,   281,
     105,   203,   161,   161,   262,    78,    68,   162,   160,   293,
     320,   320,    10,   160,   331,    30,   161,    10,   145,    82,
     130,   344,   166,   160,   372,    10,    10,    39,   336,   337,
     338,    10,    10,   143,    10,   297,   372,   372,   372,   372,
     372,   372,   372,    25,   372,   373,    93,   271,   271,   268,
      10,   264,   265,   249,   167,   160,   167,   203,   166,   284,
     373,    10,    78,   190,   356,    96,    10,    10,   312,    87,
     203,   372,   293,   315,    10,   296,   298,   300,   303,   306,
     307,   308,   310,   311,   313,   334,   342,   343,   170,   302,
     106,   208,   345,    10,    38,   322,   323,   324,   325,   293,
     190,   339,    75,   341,   338,   293,   293,    10,   347,    10,
       9,    26,   272,   272,    10,   372,   166,   353,    10,   152,
     155,   293,   293,   372,   147,    67,   316,   317,   318,   315,
      66,   165,     5,   167,   322,    18,    19,    20,    91,   161,
     163,   164,   326,   327,   328,   372,    38,   329,   325,    68,
      30,   154,   340,    10,    68,    68,    68,     9,   255,   255,
      68,   194,   287,   288,   289,   291,   353,   167,   320,   320,
      96,    96,    10,   372,   320,    66,   319,   318,   295,   296,
     298,   328,    10,   160,   372,   147,    66,    68,   144,   203,
     320,    10,   293,   149,   155,   156,   254,    10,   123,    79,
     133,    68,   194,   291,   194,   289,   167,   106,   139,   332,
      10,   145,    10,    68,   372,   293,   327,   372,   293,   132,
     293,    10,    10,    10,    10,   123,   190,   333,   372,    10,
     293,    10,   293,    84,    10,    68,   290,   294,    68,   292,
     294,    10,   293,   293,    79,    68,   133,    68,   106,    10,
      79,    10,   133,   333,    10,    10
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
#line 677 "vb_grammar.y"
    {
				/* Reset the parse state for the next file */
				ResetState();
			}
    break;

  case 7:
#line 694 "vb_grammar.y"
    {
				char *name = ILQualIdentName((yyvsp[(2) - (4)].node), 0);
				char *value = (yyvsp[(3) - (4)].name);
				int invalidValue = 0;
				InitGlobalNamespace();
				if(!ILStrICmp(name, "Explicit"))
				{
					if(!value || !ILStrICmp(value, "On"))
					{
						VBOptionSet(GlobalNamespaceNode,
									VB_OPTION_EXPLICIT, 1);
					}
					else if(!ILStrICmp(value, "Off"))
					{
						VBOptionSet(GlobalNamespaceNode,
								    VB_OPTION_EXPLICIT, 0);
					}
					else
					{
						invalidValue = 1;
					}
				}
				else if(!ILStrICmp(name, "Strict"))
				{
					if(!value || !ILStrICmp(value, "On"))
					{
						VBOptionSet(GlobalNamespaceNode,
									VB_OPTION_STRICT, 1);
					}
					else if(!ILStrICmp(value, "Off"))
					{
						VBOptionSet(GlobalNamespaceNode,
									VB_OPTION_STRICT, 0);
					}
					else
					{
						invalidValue = 1;
					}
				}
				else if(!ILStrICmp(name, "Compare"))
				{
					if(!value)
					{
						CCError(_("missing value for `%s' option"), name);
					}
					else if(!ILStrICmp(value, "Binary"))
					{
						VBOptionSet(GlobalNamespaceNode,
									VB_OPTION_BINARY_COMPARE, 1);
					}
					else if(!ILStrICmp(value, "Text"))
					{
						VBOptionSet(GlobalNamespaceNode,
									VB_OPTION_BINARY_COMPARE, 0);
					}
					else
					{
						invalidValue = 1;
					}
				}
				else
				{
					CCError(_("unknown option `%s'"), name);
				}
				if(invalidValue)
				{
					CCError(_("invalid value `%s' for `%s' option"),
							name, value);
				}
			}
    break;

  case 8:
#line 767 "vb_grammar.y"
    { (yyval.name) = 0; }
    break;

  case 9:
#line 768 "vb_grammar.y"
    { (yyval.name) = ILQualIdentName((yyvsp[(1) - (1)].node), 0); }
    break;

  case 10:
#line 769 "vb_grammar.y"
    { (yyval.name) = "On"; }
    break;

  case 18:
#line 792 "vb_grammar.y"
    {
				ILScope *globalScope = GlobalScope();
				ILNode_UsingNamespace *using;
				char *name = ILQualIdentName((yyvsp[(1) - (1)].node), 0);
				if(!ILScopeUsing(globalScope, name))
				{
					CCError("`%s' is not a namespace", name);
				}
				InitGlobalNamespace();
				if(!HaveUsingNamespace(name))
				{
					using = (ILNode_UsingNamespace *)
						ILNode_UsingNamespace_create(name);
					using->next = CurrNamespaceNode->using;
					CurrNamespaceNode->using = using;
				}
			}
    break;

  case 19:
#line 809 "vb_grammar.y"
    {
				ILScope *globalScope = GlobalScope();
				ILScope *scope = LocalScope();
				ILNode *alias;
				char *name = ILQualIdentName((yyvsp[(1) - (3)].node), 0);
				if(ILScopeLookup(globalScope, name, 1))
				{
					CCError("`%s' is already declared", name);
				}
				else if(ILScopeLookup(localScope, name, 1))
				{
					CCError("`%s' is already declared", name);
				}
				alias = ILNode_UsingAlias_create(name, ILQualIdentName((yyvsp[(3) - (3)].node), 0));
				InitGlobalNamespace();
				ILScopeDeclareAlias(scope, name, alias, (yyvsp[(3) - (3)].node));
				CurrNamespaceNode->localScope = scope;
			}
    break;

  case 20:
#line 834 "vb_grammar.y"
    { (yyval.node) = ILQualIdentSimple((yyvsp[(1) - (1)].name)); }
    break;

  case 21:
#line 835 "vb_grammar.y"
    { (yyval.node) = ILQualIdentSimple((yyvsp[(1) - (1)].name));
								  /* TODO: strip type suffix */ }
    break;

  case 22:
#line 840 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); /* TODO: keywords */ }
    break;

  case 23:
#line 844 "vb_grammar.y"
    {
				(yyval.node) = ILNode_QualIdent_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 25:
#line 851 "vb_grammar.y"
    {
				(yyval.node) = ILNode_QualIdent_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 27:
#line 862 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 28:
#line 863 "vb_grammar.y"
    { (yyval.node) = ILNode_AttributeTree_create((yyvsp[(2) - (3)].node)); }
    break;

  case 29:
#line 867 "vb_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (2)].node);
				if((yyvsp[(2) - (2)].node))
				{
					ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				}
			}
    break;

  case 30:
#line 874 "vb_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				if((yyvsp[(1) - (1)].node))
				{
					ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
				}
			}
    break;

  case 31:
#line 884 "vb_grammar.y"
    {
				ILNode *attr;
				ILNode *list;

				/* Create the attribute */
				attr = ILNode_Attribute_create((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));

				/* Wrap it in a list node */
				list = ILNode_List_create();
				ILNode_List_Add(list, attr);

				/* Wrap the list in an attribute section node */
				if((yyvsp[(1) - (3)].node))
				{
					(yyval.node) = ILNode_AttributeSection_create
							(ILAttrTargetType_Named, (yyvsp[(1) - (3)].node), list);
				}
				else
				{
					(yyval.node) = ILNode_AttributeSection_create
							(ILAttrTargetType_None, 0, list);
				}
			}
    break;

  case 32:
#line 910 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 33:
#line 911 "vb_grammar.y"
    {
				(yyval.node) = ILQualIdentSimple(ILInternString("assembly", 8).string);
			}
    break;

  case 34:
#line 914 "vb_grammar.y"
    {
				(yyval.node) = ILQualIdentSimple(ILInternString("module", 6).string);
			}
    break;

  case 35:
#line 920 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 36:
#line 921 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 37:
#line 922 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 38:
#line 926 "vb_grammar.y"
    {
				(yyval.node) = ILNode_AttrArgs_create((yyvsp[(1) - (1)].node), 0);
			}
    break;

  case 39:
#line 929 "vb_grammar.y"
    {
				(yyval.node) = ILNode_AttrArgs_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 40:
#line 932 "vb_grammar.y"
    {
				(yyval.node) = ILNode_AttrArgs_create(0, (yyvsp[(1) - (1)].node));
			}
    break;

  case 41:
#line 938 "vb_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (3)].node);
				ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 42:
#line 942 "vb_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 43:
#line 949 "vb_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (3)].node);
				ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 44:
#line 953 "vb_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 45:
#line 960 "vb_grammar.y"
    {
				(yyval.node) = ILNode_NamedArg_create((yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 48:
#line 972 "vb_grammar.y"
    {
				ILNode_ArrayType_create((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].rank));
			}
    break;

  case 49:
#line 978 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("Object"); }
    break;

  case 50:
#line 979 "vb_grammar.y"
    { CCWarning(_("`Variant' is obsolete; use `Object' instead"));
				  (yyval.node) = ILNode_SystemType_create("Object"); }
    break;

  case 51:
#line 981 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("String"); }
    break;

  case 52:
#line 982 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_BOOLEAN); }
    break;

  case 53:
#line 983 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("DateTime"); }
    break;

  case 54:
#line 984 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_CHAR); }
    break;

  case 55:
#line 985 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("Decimal"); }
    break;

  case 56:
#line 986 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_U1); }
    break;

  case 57:
#line 987 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I2); }
    break;

  case 58:
#line 988 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I4); }
    break;

  case 59:
#line 989 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I8); }
    break;

  case 60:
#line 990 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_R4); }
    break;

  case 61:
#line 991 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_R8); }
    break;

  case 62:
#line 995 "vb_grammar.y"
    { (yyval.rank) = 1; }
    break;

  case 63:
#line 996 "vb_grammar.y"
    { (yyval.rank) = (yyvsp[(1) - (1)].rank); }
    break;

  case 64:
#line 1000 "vb_grammar.y"
    { (yyval.rank) = (yyvsp[(1) - (2)].rank) + 1; }
    break;

  case 65:
#line 1001 "vb_grammar.y"
    { (yyval.rank) = 2; }
    break;

  case 66:
#line 1005 "vb_grammar.y"
    { (yyval.arrayName).rank = (yyvsp[(2) - (3)].rank); (yyval.arrayName).exprs = 0; }
    break;

  case 67:
#line 1006 "vb_grammar.y"
    { (yyval.arrayName) = (yyvsp[(2) - (3)].arrayName); }
    break;

  case 68:
#line 1010 "vb_grammar.y"
    {
				(yyval.arrayName).rank = (yyvsp[(1) - (3)].arrayName).rank + 1;
				(yyval.arrayName).exprs = ILNode_ArgList_create((yyvsp[(1) - (3)].arrayName).exprs, (yyvsp[(3) - (3)].node));
			}
    break;

  case 69:
#line 1014 "vb_grammar.y"
    {
				(yyval.arrayName).rank = 1;
				(yyval.arrayName).exprs = (yyvsp[(1) - (1)].node);
			}
    break;

  case 70:
#line 1025 "vb_grammar.y"
    {
				PushIntoNamespace(ILInternString(ILQualIdentName((yyvsp[(2) - (3)].node), 0), -1));
			}
    break;

  case 71:
#line 1027 "vb_grammar.y"
    {
				PopOutOfNamespace(ILInternString(ILQualIdentName((yyvsp[(2) - (8)].node), 0), -1));
			}
    break;

  case 77:
#line 1044 "vb_grammar.y"
    { CCPluginAddTopLevel((yyvsp[(1) - (1)].node)); }
    break;

  case 85:
#line 1065 "vb_grammar.y"
    { (yyval.modifier) = 0; }
    break;

  case 86:
#line 1066 "vb_grammar.y"
    { (yyval.modifier) = (yyvsp[(1) - (1)].modifier); }
    break;

  case 87:
#line 1070 "vb_grammar.y"
    {
				if(((yyvsp[(1) - (2)].modifier) & (yyvsp[(2) - (2)].modifier)) != 0)
				{
					VBModifiersUsedTwice
						(yycurrfilename(), yycurrlinenum(), ((yyvsp[(1) - (2)].modifier) & (yyvsp[(2) - (2)].modifier)));
				}
				(yyval.modifier) = ((yyvsp[(1) - (2)].modifier) | (yyvsp[(2) - (2)].modifier));
			}
    break;

  case 88:
#line 1078 "vb_grammar.y"
    { (yyval.modifier) = (yyvsp[(1) - (1)].modifier); }
    break;

  case 89:
#line 1082 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_PUBLIC; }
    break;

  case 90:
#line 1083 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_PROTECTED; }
    break;

  case 91:
#line 1084 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_FRIEND; }
    break;

  case 92:
#line 1085 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_PRIVATE; }
    break;

  case 93:
#line 1086 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_SHADOWS; }
    break;

  case 94:
#line 1087 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_MUST_INHERIT; }
    break;

  case 95:
#line 1088 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_NOT_INHERITABLE; }
    break;

  case 96:
#line 1089 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_SHARED; }
    break;

  case 97:
#line 1090 "vb_grammar.y"
    {
				CCWarning(_("`Static' is obsolete; use `Shared' instead"));
				(yyval.modifier) = VB_MODIFIER_SHARED;
			}
    break;

  case 98:
#line 1094 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_OVERRIDABLE; }
    break;

  case 99:
#line 1095 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_NOT_OVERRIDABLE; }
    break;

  case 100:
#line 1096 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_MUST_OVERRIDE; }
    break;

  case 101:
#line 1097 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_OVERRIDES; }
    break;

  case 102:
#line 1098 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_OVERLOADS; }
    break;

  case 103:
#line 1099 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_READ_ONLY; }
    break;

  case 104:
#line 1100 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_WRITE_ONLY; }
    break;

  case 105:
#line 1101 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_WITH_EVENTS; }
    break;

  case 106:
#line 1102 "vb_grammar.y"
    { (yyval.modifier) = VB_MODIFIER_DEFAULT; }
    break;

  case 107:
#line 1110 "vb_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(4) - (6)].node), 0);
			}
    break;

  case 108:
#line 1117 "vb_grammar.y"
    {
				ILNode *baseList;
				ILNode *bodyList;
				ILNode *fieldDecl;
				ILUInt32 attrs;

				/* Validate the modifiers */
				attrs = VBModifiersToTypeAttrs((yyvsp[(4) - (11)].node), (yyvsp[(2) - (11)].modifier), (NestingLevel > 1));

				/* Add extra attributes that enums need */
				attrs |= IL_META_TYPEDEF_SERIALIZABLE |
						 IL_META_TYPEDEF_SEALED;

				/* Exit the current nesting level */
				--NestingLevel;

				/* Make sure that we have "Enum" in the base list */
				baseList = MakeSystemType("Enum");

				/* Add an instance field called "value__" to the body,
				   which is used to hold the enumerated value */
				bodyList = (yyvsp[(8) - (11)].node);
				if(!bodyList)
				{
					bodyList = ILNode_List_create();
				}
				fieldDecl = ILNode_List_create();
				ILNode_List_Add(fieldDecl,
					ILNode_FieldDeclarator_create
						(ILQualIdentSimple("value__"), 0));
				ILNode_List_Add(bodyList,
					ILNode_FieldDeclaration_create
						(0, IL_META_FIELDDEF_PUBLIC |
							IL_META_FIELDDEF_SPECIAL_NAME |
							IL_META_FIELDDEF_RT_SPECIAL_NAME, (yyvsp[(5) - (11)].node), fieldDecl));

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (11)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(4) - (11)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 0,						/* TypeFormals */
							 baseList,				/* ClassBase */
							 bodyList,				/* EnumBody */
							 0);					/* StaticCtors */
				CloneLine((yyval.node), (yyvsp[(4) - (11)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 109:
#line 1176 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I4); }
    break;

  case 110:
#line 1177 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 111:
#line 1181 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_U1); }
    break;

  case 112:
#line 1182 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I2); }
    break;

  case 113:
#line 1183 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I4); }
    break;

  case 114:
#line 1184 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I8); }
    break;

  case 115:
#line 1188 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 116:
#line 1189 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 117:
#line 1193 "vb_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (2)].node);
				ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
			}
    break;

  case 118:
#line 1197 "vb_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 119:
#line 1204 "vb_grammar.y"
    {
				(yyval.node) = ILNode_EnumMemberDeclaration_create((yyvsp[(1) - (5)].node), (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));
			}
    break;

  case 120:
#line 1207 "vb_grammar.y"
    {
				(yyval.node) = ILNode_EnumMemberDeclaration_create((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), 0);
			}
    break;

  case 121:
#line 1218 "vb_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(4) - (6)].node), 0);
			}
    break;

  case 122:
#line 1224 "vb_grammar.y"
    {
				ILNode *baseList;
				ILUInt32 attrs;

				/* Validate the modifiers */
				attrs = VBModifiersToTypeAttrs((yyvsp[(4) - (11)].node), (yyvsp[(2) - (11)].modifier), (NestingLevel > 1));

				/* Add extra attributes that structs need */
				attrs |= IL_META_TYPEDEF_LAYOUT_SEQUENTIAL |
						 IL_META_TYPEDEF_SERIALIZABLE |
						 IL_META_TYPEDEF_SEALED;

				/* Exit the current nesting level */
				--NestingLevel;

				/* Make sure that we have "ValueType" in the base list */
				baseList = MakeSystemType("ValueType");
				if((yyvsp[(6) - (11)].node) != 0)
				{
					baseList = ILNode_ArgList_create((yyvsp[(6) - (11)].node), baseList);
				}

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (11)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(4) - (11)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 0,						/* TypeFormals */
							 baseList,				/* ClassBase */
							 ((yyvsp[(8) - (11)].member)).body,				/* StructBody */
							 ((yyvsp[(8) - (11)].member)).staticCtors);		/* StaticCtors */
				CloneLine((yyval.node), (yyvsp[(4) - (11)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 123:
#line 1269 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 124:
#line 1270 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 125:
#line 1274 "vb_grammar.y"
    {
				(yyval.node) = ILNode_ArgList_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 127:
#line 1281 "vb_grammar.y"
    { (yyval.member).body = 0; (yyval.member).staticCtors = 0; }
    break;

  case 128:
#line 1282 "vb_grammar.y"
    { (yyval.member) = (yyvsp[(1) - (1)].member); }
    break;

  case 129:
#line 1286 "vb_grammar.y"
    {
				(yyval.member).body = MakeList(0, (yyvsp[(1) - (1)].member).body);
				(yyval.member).staticCtors = MakeList(0, (yyvsp[(1) - (1)].member).staticCtors);
			}
    break;

  case 130:
#line 1290 "vb_grammar.y"
    {
				(yyval.member).body = MakeList((yyvsp[(1) - (2)].member).body, (yyvsp[(2) - (2)].member).body);
				(yyval.member).staticCtors = MakeList((yyvsp[(1) - (2)].member).staticCtors, (yyvsp[(2) - (2)].member).staticCtors);
			}
    break;

  case 131:
#line 1297 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 132:
#line 1298 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 133:
#line 1299 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 134:
#line 1300 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 135:
#line 1301 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 136:
#line 1302 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 137:
#line 1303 "vb_grammar.y"
    { (yyval.member) = (yyvsp[(1) - (1)].member); }
    break;

  case 138:
#line 1312 "vb_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(4) - (7)].node), 0);
			}
    break;

  case 139:
#line 1319 "vb_grammar.y"
    {
				ILNode *classBody = ((yyvsp[(9) - (12)].member)).body;
				ILNode *classBase;

				/* Validate the modifiers */
				ILUInt32 attrs =
					VBModifiersToTypeAttrs((yyvsp[(4) - (12)].node), (yyvsp[(2) - (12)].modifier), (NestingLevel > 1));

				/* Exit the current nesting level */
				--NestingLevel;

				/* Combine the class base and interface information */
				if((yyvsp[(6) - (12)].node) && (yyvsp[(7) - (12)].node))
				{
					classBase = ILNode_ArgList_create((yyvsp[(7) - (12)].node), (yyvsp[(6) - (12)].node));
				}
				else if((yyvsp[(6) - (12)].node))
				{
					classBase = (yyvsp[(6) - (12)].node);
				}
				else
				{
					classBase = (yyvsp[(7) - (12)].node);
				}

				/* Determine if we need to add a default constructor */
				if(!ClassNameIsCtorDefined())
				{
					ILUInt32 ctorMods =
						(((attrs & IL_META_TYPEDEF_ABSTRACT) != 0)
							? VB_MODIFIER_PROTECTED : VB_MODIFIER_PUBLIC);
					ILNode *cname = ILQualIdentSimple
							(ILInternString(".ctor", 5).string);
					ILNode *body = ILNode_NewScope_create
							(ILNode_Compound_CreateFrom
								(ILNode_NonStaticInit_create(),
								 ILNode_InvocationExpression_create
									(ILNode_BaseInit_create(), 0)));
					ILNode *ctor = ILNode_MethodDeclaration_create
						  (0, VBModifiersToConstructorAttrs(cname, ctorMods, 0),
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
							((yyvsp[(1) - (12)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(4) - (12)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 0,						/* TypeFormals */
							 classBase,				/* ClassBase */
							 classBody,
							 ((yyvsp[(9) - (12)].member)).staticCtors);
				CloneLine((yyval.node), (yyvsp[(4) - (12)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 140:
#line 1391 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 141:
#line 1392 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 142:
#line 1400 "vb_grammar.y"
    {
				/* Enter a new nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(4) - (5)].node), 1);
			}
    break;

  case 143:
#line 1407 "vb_grammar.y"
    {
				ILNode *classBody = ((yyvsp[(7) - (10)].member)).body;

				/* Validate the modifiers */
				ILUInt32 attrs =
					VBModifiersToTypeAttrs((yyvsp[(4) - (10)].node), (yyvsp[(2) - (10)].modifier), (NestingLevel > 1));

				/* Modules are always sealed */
				attrs |= IL_META_TYPEDEF_SEALED;

				/* Exit the current nesting level */
				--NestingLevel;

				/* Determine if we need to add a default constructor */
				if(!ClassNameIsCtorDefined())
				{
					ILUInt32 ctorMods = VB_MODIFIER_PRIVATE;
					ILNode *cname = ILQualIdentSimple
							(ILInternString(".ctor", 5).string);
					ILNode *body = ILNode_NewScope_create
							(ILNode_Compound_CreateFrom
								(ILNode_NonStaticInit_create(),
								 ILNode_InvocationExpression_create
									(ILNode_BaseInit_create(), 0)));
					ILNode *ctor = ILNode_MethodDeclaration_create
						  (0, VBModifiersToConstructorAttrs(cname, ctorMods, 0),
						   0 /* "void" */, cname,
						   ILNode_Empty_create(), body);
					if(!classBody)
					{
						classBody = ILNode_List_create();
					}
					ILNode_List_Add(classBody, ctor);
				}
				else
				{
					/* Modules are not supposed to have constructors */
					CCErrorOnLine(yygetfilename((yyvsp[(4) - (10)].node)), yygetlinenum((yyvsp[(4) - (10)].node)),
							 _("modules cannot have instance constructors"));
				}

				/* TODO: add the "StandardModule" attribute to the class */

				/* Create the class definition */
				InitGlobalNamespace();
				(yyval.node) = ILNode_ClassDefn_create
							((yyvsp[(1) - (10)].node),					/* OptAttributes */
							 attrs,					/* OptModifiers */
							 ILQualIdentName((yyvsp[(4) - (10)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 0,						/* TypeFormals */
							 0,						/* ClassBase */
							 classBody,
							 ((yyvsp[(7) - (10)].member)).staticCtors);
				CloneLine((yyval.node), (yyvsp[(4) - (10)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 144:
#line 1478 "vb_grammar.y"
    {
				/* Increase the nesting level */
				++NestingLevel;

				/* Push the identifier onto the class name stack */
				ClassNamePush((yyvsp[(4) - (6)].node), 0);
			}
    break;

  case 145:
#line 1485 "vb_grammar.y"
    {
				/* Validate the modifiers */
				ILUInt32 attrs =
					VBModifiersToTypeAttrs((yyvsp[(4) - (11)].node), (yyvsp[(2) - (11)].modifier), (NestingLevel > 1));

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
							 ILQualIdentName((yyvsp[(4) - (11)].node), 0),/* Identifier */
							 CurrNamespace.string,	/* Namespace */
							 (ILNode *)CurrNamespaceNode,
							 0,						/* TypeFormals */
							 (yyvsp[(6) - (11)].node),					/* ClassBase */
							 ((yyvsp[(8) - (11)].member)).body,				/* InterfaceBody */
							 ((yyvsp[(8) - (11)].member)).staticCtors);		/* StaticCtors */
				CloneLine((yyval.node), (yyvsp[(4) - (11)].node));

				/* Pop the class name stack */
				ClassNamePop();

				/* We have declarations at the top-most level of the file */
				HaveDecls = 1;
			}
    break;

  case 146:
#line 1520 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 147:
#line 1521 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 148:
#line 1525 "vb_grammar.y"
    { (yyval.member).body = 0; (yyval.member).staticCtors = 0; }
    break;

  case 149:
#line 1526 "vb_grammar.y"
    { (yyval.member) = (yyvsp[(1) - (1)].member); }
    break;

  case 150:
#line 1530 "vb_grammar.y"
    {
				(yyval.member).body = MakeList(0, (yyvsp[(1) - (1)].member).body);
				(yyval.member).staticCtors = MakeList(0, (yyvsp[(1) - (1)].member).staticCtors);
			}
    break;

  case 151:
#line 1534 "vb_grammar.y"
    {
				(yyval.member).body = MakeList((yyvsp[(1) - (2)].member).body, (yyvsp[(2) - (2)].member).body);
				(yyval.member).staticCtors = MakeList((yyvsp[(1) - (2)].member).staticCtors, (yyvsp[(2) - (2)].member).staticCtors);
			}
    break;

  case 152:
#line 1541 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 153:
#line 1542 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 154:
#line 1543 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 155:
#line 1544 "vb_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors = 0; }
    break;

  case 156:
#line 1552 "vb_grammar.y"
    {
				/* TODO */
			}
    break;

  case 163:
#line 1578 "vb_grammar.y"
    {
				ILUInt32 attrs;
				attrs = VBModifiersToMethodAttrs
						((yyvsp[(4) - (8)].node), (yyvsp[(2) - (8)].modifier), ClassNameIsModule());
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (8)].node), attrs, ILNode_PrimitiveType_create
										(IL_META_ELEMTYPE_VOID),
						 (yyvsp[(4) - (8)].node), (yyvsp[(5) - (8)].node), (yyvsp[(8) - (8)].node));
				CloneLine((yyval.node), (yyvsp[(4) - (8)].node));
				/* TODO: HandlesOrImplements clause */
			}
    break;

  case 164:
#line 1592 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 165:
#line 1593 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (4)].node); }
    break;

  case 166:
#line 1594 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 167:
#line 1599 "vb_grammar.y"
    {
				ILUInt32 attrs;
				ILNode *funcattrs;
				attrs = VBModifiersToMethodAttrs
						((yyvsp[(4) - (9)].node), (yyvsp[(2) - (9)].modifier), ClassNameIsModule());
				funcattrs = CombineAttributes
					((yyvsp[(1) - (9)].node), ILAttrTargetType_Return, (yyvsp[(6) - (9)].typeInfo).attrs);
				(yyval.node) = ILNode_MethodDeclaration_create
						(funcattrs, attrs, (yyvsp[(6) - (9)].typeInfo).type, (yyvsp[(4) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(9) - (9)].node));
				CloneLine((yyval.node), (yyvsp[(4) - (9)].node));
				/* TODO: HandlesOrImplements clause */
			}
    break;

  case 168:
#line 1614 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 169:
#line 1615 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (4)].node); }
    break;

  case 170:
#line 1616 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 171:
#line 1621 "vb_grammar.y"
    {
				ILUInt32 attrs;
				attrs = VBModifiersToMethodAttrs
						((yyvsp[(6) - (10)].node), (yyvsp[(2) - (10)].modifier), ClassNameIsModule());
				attrs |= CS_SPECIALATTR_EXTERN;
				(yyval.node) = ILNode_MethodDeclaration_create
						((yyvsp[(1) - (10)].node), attrs, ILNode_PrimitiveType_create
										(IL_META_ELEMTYPE_VOID),
						 (yyvsp[(6) - (10)].node), (yyvsp[(9) - (10)].node), 0);
				CloneLine((yyval.node), (yyvsp[(6) - (10)].node));
				/* TODO: PInvoke information */
			}
    break;

  case 172:
#line 1638 "vb_grammar.y"
    {
				ILUInt32 attrs;
				ILNode *funcattrs;
				attrs = VBModifiersToMethodAttrs
						((yyvsp[(6) - (11)].node), (yyvsp[(2) - (11)].modifier), ClassNameIsModule());
				attrs |= CS_SPECIALATTR_EXTERN;
				funcattrs = CombineAttributes
					((yyvsp[(1) - (11)].node), ILAttrTargetType_Return, (yyvsp[(10) - (11)].typeInfo).attrs);
				(yyval.node) = ILNode_MethodDeclaration_create
						(funcattrs, attrs, (yyvsp[(10) - (11)].typeInfo).type, (yyvsp[(6) - (11)].node), (yyvsp[(9) - (11)].node), 0);
				CloneLine((yyval.node), (yyvsp[(6) - (11)].node));
				/* TODO: PInvoke information */
			}
    break;

  case 173:
#line 1654 "vb_grammar.y"
    {
				(yyval.typeInfo).type = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_VOID);
				(yyval.typeInfo).attrs = 0;
			}
    break;

  case 174:
#line 1658 "vb_grammar.y"
    {
				(yyval.typeInfo).type = (yyvsp[(3) - (3)].node);
				(yyval.typeInfo).attrs = (yyvsp[(2) - (3)].node);
			}
    break;

  case 175:
#line 1665 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 176:
#line 1666 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 177:
#line 1667 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 178:
#line 1671 "vb_grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (3)].node);
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 179:
#line 1675 "vb_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 180:
#line 1683 "vb_grammar.y"
    {
				(yyval.node) = ILNode_FormalParameter_create((yyvsp[(1) - (5)].node), (yyvsp[(2) - (5)].paramMod), (yyvsp[(4) - (5)].node), (yyvsp[(3) - (5)].node));
				/* TODO: default value handling */
			}
    break;

  case 181:
#line 1690 "vb_grammar.y"
    { (yyval.paramMod) = ILParamMod_empty; }
    break;

  case 182:
#line 1691 "vb_grammar.y"
    { (yyval.paramMod) = (yyvsp[(1) - (1)].paramMod); }
    break;

  case 183:
#line 1695 "vb_grammar.y"
    {
				if((yyvsp[(1) - (2)].paramMod) == ILParamMod_empty)
				{
					(yyval.paramMod) = (yyvsp[(2) - (2)].paramMod);
				}
				else if((yyvsp[(2) - (2)].paramMod) == ILParamMod_empty || (yyvsp[(1) - (2)].paramMod) == (yyvsp[(2) - (2)].paramMod))
				{
					(yyval.paramMod) = (yyvsp[(1) - (2)].paramMod);
				}
				else
				{
					CCError(_("conflicting parameter modifiers"));
				}
			}
    break;

  case 184:
#line 1709 "vb_grammar.y"
    { (yyval.paramMod) = (yyvsp[(1) - (1)].paramMod); }
    break;

  case 185:
#line 1713 "vb_grammar.y"
    { (yyval.paramMod) = ILParamMod_ref; }
    break;

  case 186:
#line 1714 "vb_grammar.y"
    { (yyval.paramMod) = ILParamMod_empty; }
    break;

  case 187:
#line 1715 "vb_grammar.y"
    { (yyval.paramMod) = ILParamMod_empty;	/* TODO */ }
    break;

  case 188:
#line 1716 "vb_grammar.y"
    { (yyval.paramMod) = ILParamMod_params; }
    break;

  case 189:
#line 1720 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("Object"); }
    break;

  case 190:
#line 1721 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 191:
#line 1725 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 192:
#line 1726 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 201:
#line 1750 "vb_grammar.y"
    {}
    break;

  case 202:
#line 1751 "vb_grammar.y"
    {}
    break;

  case 205:
#line 1760 "vb_grammar.y"
    {}
    break;

  case 213:
#line 1785 "vb_grammar.y"
    {
				ILUInt32 attrs =
					VBModifiersToConstructorAttrs
						((yyvsp[(5) - (7)].node), (yyvsp[(2) - (7)].modifier), ClassNameIsModule());
				ILNode *cname;
				ILNode *body = (yyvsp[(7) - (7)].node);
				if((attrs & IL_META_METHODDEF_STATIC) != 0)
				{
					cname = ILQualIdentSimple
								(ILInternString(".cctor", 6).string);
				}
				else
				{
					cname = ILQualIdentSimple
								(ILInternString(".ctor", 5).string);
					ClassNameCtorDefined();
				}
				if((attrs & IL_META_METHODDEF_STATIC) != 0)
				{
					(yyval.member).body = 0;
					(yyval.member).staticCtors = body;
				}
				else
				{
					(yyval.member).body = ILNode_MethodDeclaration_create
						  ((yyvsp[(1) - (7)].node), attrs, 0 /* "void" */, cname, (yyvsp[(5) - (7)].node), body);
					CloneLine((yyval.member).body, (yyvsp[(5) - (7)].node));
					(yyval.member).staticCtors = 0;
				}
			}
    break;

  case 214:
#line 1823 "vb_grammar.y"
    { /* TODO */ }
    break;

  case 215:
#line 1827 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 216:
#line 1828 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 219:
#line 1842 "vb_grammar.y"
    {
				ILUInt32 attrs = VBModifiersToConstAttrs
					((yyvsp[(4) - (8)].node), (yyvsp[(2) - (8)].modifier), ClassNameIsModule());
				ILNode *decl = ILNode_List_create();
				ILNode_List_Add
					(decl, ILNode_FieldDeclarator_create((yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node)));
				(yyval.node) = ILNode_FieldDeclaration_create((yyvsp[(1) - (8)].node), attrs, (yyvsp[(5) - (8)].node), decl);
			}
    break;

  case 220:
#line 1857 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 227:
#line 1879 "vb_grammar.y"
    {}
    break;

  case 228:
#line 1880 "vb_grammar.y"
    {}
    break;

  case 234:
#line 1892 "vb_grammar.y"
    {}
    break;

  case 239:
#line 1908 "vb_grammar.y"
    {
				/* TODO */
			}
    break;

  case 247:
#line 1927 "vb_grammar.y"
    {}
    break;

  case 248:
#line 1931 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 249:
#line 1932 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (4)].node); }
    break;

  case 250:
#line 1933 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 251:
#line 1937 "vb_grammar.y"
    {}
    break;

  case 252:
#line 1941 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 253:
#line 1942 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (4)].node); }
    break;

  case 254:
#line 1943 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 255:
#line 1951 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 256:
#line 1952 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 257:
#line 1956 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
			}
    break;

  case 258:
#line 1959 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 259:
#line 1963 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 260:
#line 1964 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 261:
#line 1968 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 262:
#line 1971 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 263:
#line 1975 "vb_grammar.y"
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

  case 264:
#line 1991 "vb_grammar.y"
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
#line 2008 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 267:
#line 2009 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 268:
#line 2010 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 269:
#line 2011 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 270:
#line 2012 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 271:
#line 2013 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 276:
#line 2018 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 279:
#line 2021 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 281:
#line 2023 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 282:
#line 2028 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 283:
#line 2029 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 284:
#line 2030 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 285:
#line 2031 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 291:
#line 2037 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 292:
#line 2041 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Compound_CreateFrom
					(ILNode_GotoLabel_create((yyvsp[(1) - (3)].name)), (yyvsp[(3) - (3)].node));
			}
    break;

  case 293:
#line 2045 "vb_grammar.y"
    {
				(yyval.node) = ILNode_GotoLabel_create((yyvsp[(1) - (2)].name));
			}
    break;

  case 294:
#line 2051 "vb_grammar.y"
    { (yyval.name) = ILQualIdentName((yyvsp[(1) - (1)].node), 0); /* TODO: case */ }
    break;

  case 295:
#line 2052 "vb_grammar.y"
    {
				/* Convert the integer into a string so that we
				   can handle all labels as string-form names */
				char numbuf[32];
				sprintf(numbuf, "%lu", (unsigned long)((yyvsp[(1) - (1)].integer).value));
				(yyval.name) = ILInternString(numbuf, -1).string;
			}
    break;

  case 303:
#line 2087 "vb_grammar.y"
    {}
    break;

  case 304:
#line 2091 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Assign_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 305:
#line 2094 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 306:
#line 2098 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 307:
#line 2102 "vb_grammar.y"
    {
				(yyval.node) = ILNode_AssignMul_create(ILNode_Mul_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 308:
#line 2105 "vb_grammar.y"
    {
				(yyval.node) = ILNode_AssignDiv_create(ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 309:
#line 2108 "vb_grammar.y"
    {
				/* TODO: integer division */
				(yyval.node) = ILNode_AssignDiv_create(ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 310:
#line 2112 "vb_grammar.y"
    {
				(yyval.node) = ILNode_AssignAdd_create(ILNode_Add_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 311:
#line 2115 "vb_grammar.y"
    {
				(yyval.node) = ILNode_AssignSub_create(ILNode_Sub_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 312:
#line 2118 "vb_grammar.y"
    {
				/* TODO: concat assign */
				(yyval.node) = ILNode_AssignAdd_create(ILNode_Add_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));
			}
    break;

  case 313:
#line 2125 "vb_grammar.y"
    {
				CCWarning(_("`Let' is obsolete; it is no longer required"));
				(yyval.node) = (yyvsp[(2) - (2)].node);
			}
    break;

  case 315:
#line 2136 "vb_grammar.y"
    {
				/* TODO: wrap with a node that checks the expression
				   to make sure that it is a procedure call */
				(yyval.node) = (yyvsp[(1) - (1)].node);
			}
    break;

  case 316:
#line 2141 "vb_grammar.y"
    {
				/* TODO: wrap with a node that checks the expression
				   to make sure that it is a procedure or function call */
				(yyval.node) = (yyvsp[(2) - (2)].node);
			}
    break;

  case 317:
#line 2146 "vb_grammar.y"
    {
				CCWarning(_("`GoSub' is obsolete; it is no longer required"));
				/* TODO: wrap with a node that checks the expression
				   to make sure that it is a procedure or function call */
				(yyval.node) = (yyvsp[(2) - (2)].node);
			}
    break;

  case 318:
#line 2155 "vb_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].ifrest).thenClause, (yyvsp[(4) - (4)].ifrest).elseClause);
			}
    break;

  case 319:
#line 2158 "vb_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(2) - (5)].node), (yyvsp[(5) - (5)].ifrest).thenClause, (yyvsp[(5) - (5)].ifrest).elseClause);
			}
    break;

  case 320:
#line 2161 "vb_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), ILNode_Empty_create());
			}
    break;

  case 321:
#line 2164 "vb_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
			}
    break;

  case 322:
#line 2170 "vb_grammar.y"
    {
				(yyval.ifrest).thenClause = (yyvsp[(1) - (5)].node);
				if((yyvsp[(2) - (5)].node))
				{
					(yyval.ifrest).elseClause = (yyvsp[(2) - (5)].node);
					VBInsertElse((yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node));
				}
				else
				{
					(yyval.ifrest).elseClause = (yyvsp[(3) - (5)].node);
				}
			}
    break;

  case 323:
#line 2185 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 324:
#line 2186 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 325:
#line 2190 "vb_grammar.y"
    {
				VBInsertElse((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
				(yyval.node) = (yyvsp[(1) - (2)].node);
			}
    break;

  case 326:
#line 2194 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 327:
#line 2198 "vb_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), 0);
			}
    break;

  case 328:
#line 2201 "vb_grammar.y"
    {
				(yyval.node) = ILNode_If_create((yyvsp[(2) - (5)].node), (yyvsp[(5) - (5)].node), 0);
			}
    break;

  case 329:
#line 2207 "vb_grammar.y"
    { (yyval.node) = ILNode_Empty_create(); }
    break;

  case 330:
#line 2208 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(3) - (3)].node); }
    break;

  case 331:
#line 2212 "vb_grammar.y"
    { (yyval.node) = ILNode_ToBool_create((yyvsp[(1) - (1)].node)); }
    break;

  case 344:
#line 2247 "vb_grammar.y"
    {}
    break;

  case 345:
#line 2248 "vb_grammar.y"
    {}
    break;

  case 354:
#line 2266 "vb_grammar.y"
    {
				(yyval.node) = ILNode_While_create((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node));
				((ILNode_LabelledStatement *)(yyval.node))->name =
					ILInternString("while", -1).string;
			}
    break;

  case 355:
#line 2271 "vb_grammar.y"
    {
				(yyval.node) = ILNode_While_create((yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node));
				((ILNode_LabelledStatement *)(yyval.node))->name =
					ILInternString("do", -1).string;
			}
    break;

  case 356:
#line 2276 "vb_grammar.y"
    {
				(yyval.node) = ILNode_While_create
					(ILNode_LogicalNot_create((yyvsp[(3) - (6)].node)), (yyvsp[(5) - (6)].node));
				((ILNode_LabelledStatement *)(yyval.node))->name =
					ILInternString("do", -1).string;
			}
    break;

  case 357:
#line 2282 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Do_create((yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node));
				((ILNode_LabelledStatement *)(yyval.node))->name =
					ILInternString("do", -1).string;
			}
    break;

  case 358:
#line 2287 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Do_create
					((yyvsp[(3) - (6)].node), ILNode_LogicalNot_create((yyvsp[(6) - (6)].node)));
				((ILNode_LabelledStatement *)(yyval.node))->name =
					ILInternString("do", -1).string;
			}
    break;

  case 359:
#line 2294 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			/*
				((ILNode_LabelledStatement *)$$)->name =
					ILInternString("for", -1).string;
			*/
			}
    break;

  case 360:
#line 2303 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			/*
				((ILNode_LabelledStatement *)$$)->name =
					ILInternString("for", -1).string;
			*/
			}
    break;

  case 361:
#line 2314 "vb_grammar.y"
    { (yyval.loopvar).name = (yyvsp[(1) - (3)].node); (yyval.loopvar).type = (yyvsp[(3) - (3)].node); }
    break;

  case 362:
#line 2315 "vb_grammar.y"
    { (yyval.loopvar).name = (yyvsp[(1) - (1)].node); (yyval.loopvar).type = 0; }
    break;

  case 363:
#line 2319 "vb_grammar.y"
    { (yyval.node) = 0; }
    break;

  case 364:
#line 2320 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 366:
#line 2325 "vb_grammar.y"
    {}
    break;

  case 367:
#line 2329 "vb_grammar.y"
    { (yyval.node) = ILNode_Throw_create(); }
    break;

  case 368:
#line 2330 "vb_grammar.y"
    { (yyval.node) = ILNode_ThrowExpr_create((yyvsp[(2) - (2)].node)); }
    break;

  case 369:
#line 2331 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 370:
#line 2332 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 371:
#line 2333 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 372:
#line 2334 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 373:
#line 2335 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 374:
#line 2336 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 375:
#line 2337 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 383:
#line 2361 "vb_grammar.y"
    {}
    break;

  case 388:
#line 2375 "vb_grammar.y"
    { (yyval.node) = ILNode_Goto_create((yyvsp[(2) - (2)].name)); /* TODO: case */ }
    break;

  case 389:
#line 2376 "vb_grammar.y"
    {
				(yyval.node) = ILNode_LabelledBreak_create
						(ILInternString("do", -1).string);
			}
    break;

  case 390:
#line 2380 "vb_grammar.y"
    {
				(yyval.node) = ILNode_LabelledBreak_create
						(ILInternString("for", -1).string);
			}
    break;

  case 391:
#line 2384 "vb_grammar.y"
    {
				(yyval.node) = ILNode_LabelledBreak_create
						(ILInternString("while", -1).string);
			}
    break;

  case 392:
#line 2388 "vb_grammar.y"
    {
				(yyval.node) = ILNode_LabelledBreak_create
						(ILInternString("select", -1).string);
			}
    break;

  case 393:
#line 2392 "vb_grammar.y"
    { (yyval.node) = ILNode_Return_create(); }
    break;

  case 394:
#line 2393 "vb_grammar.y"
    { (yyval.node) = ILNode_Return_create(); }
    break;

  case 395:
#line 2394 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 396:
#line 2395 "vb_grammar.y"
    {
				/* TODO: Call "System.Diagnostics.Debugger.Break()" */
				(yyval.node) = ILNode_Empty_create();
			}
    break;

  case 397:
#line 2399 "vb_grammar.y"
    {
				/* TODO: Call "Microsoft.VisualBasic.CompilerServices.
				   ProjectData.EndApp()" */
				(yyval.node) = ILNode_Empty_create();
			}
    break;

  case 398:
#line 2404 "vb_grammar.y"
    { (yyval.node) = ILNode_Return_create(); }
    break;

  case 399:
#line 2405 "vb_grammar.y"
    { (yyval.node) = ILNode_ReturnExpr_create((yyvsp[(2) - (2)].node)); }
    break;

  case 405:
#line 2420 "vb_grammar.y"
    {}
    break;

  case 406:
#line 2424 "vb_grammar.y"
    {}
    break;

  case 407:
#line 2425 "vb_grammar.y"
    {}
    break;

  case 408:
#line 2433 "vb_grammar.y"
    {
				switch((yyvsp[(1) - (1)].integer).type)
				{
					case CS_NUMTYPE_INT32:
					{
						if((yyvsp[(1) - (1)].integer).value < 0)
						{
							(yyval.node) = ILNode_Int32_create
								((ILUInt64)(-((yyvsp[(1) - (1)].integer).value)), 1, 1);
						}
						else
						{
							(yyval.node) = ILNode_Int32_create
								((ILUInt64)((yyvsp[(1) - (1)].integer).value), 0, 1);
						}
					}
					break;

					case CS_NUMTYPE_INT64:
					default:
					{
						if((yyvsp[(1) - (1)].integer).value < 0)
						{
							(yyval.node) = ILNode_Int64_create
								((ILUInt64)(-((yyvsp[(1) - (1)].integer).value)), 1, 1);
						}
						else
						{
							(yyval.node) = ILNode_Int64_create
								((ILUInt64)((yyvsp[(1) - (1)].integer).value), 0, 1);
						}
					}
					break;
				}
			}
    break;

  case 409:
#line 2468 "vb_grammar.y"
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

  case 410:
#line 2478 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Decimal_create((yyvsp[(1) - (1)].decimal));
			}
    break;

  case 411:
#line 2481 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Char_create((ILUInt64)((yyvsp[(1) - (1)].integer).value), 0, 1);
			}
    break;

  case 412:
#line 2484 "vb_grammar.y"
    {
				(yyval.node) = ILNode_String_create((yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).len);
			}
    break;

  case 413:
#line 2487 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 414:
#line 2488 "vb_grammar.y"
    { (yyval.node) = ILNode_True_create(); }
    break;

  case 415:
#line 2489 "vb_grammar.y"
    { (yyval.node) = ILNode_False_create(); }
    break;

  case 416:
#line 2490 "vb_grammar.y"
    { (yyval.node) = ILNode_Null_create(); }
    break;

  case 418:
#line 2492 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 419:
#line 2493 "vb_grammar.y"
    { (yyval.node) = ILNode_This_create(); }
    break;

  case 420:
#line 2494 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 421:
#line 2495 "vb_grammar.y"
    { (yyval.node) = 0; /* TODO */ }
    break;

  case 422:
#line 2496 "vb_grammar.y"
    { (yyval.node) = ILNode_TypeOf_create((yyvsp[(3) - (4)].node)); }
    break;

  case 423:
#line 2497 "vb_grammar.y"
    {
				(yyval.node) = ILNode_InvocationExpression_create((yyvsp[(1) - (3)].node), 0);
			}
    break;

  case 424:
#line 2500 "vb_grammar.y"
    {
				/* TODO: might actually be an array reference instead */
				(yyval.node) = ILNode_InvocationExpression_create((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 425:
#line 2504 "vb_grammar.y"
    {
				(yyval.node) = ILNode_MemberAccess_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 426:
#line 2507 "vb_grammar.y"
    {
				(yyval.node) = ILNode_MemberAccess_create(ILNode_This_create(), (yyvsp[(2) - (2)].node));
			}
    break;

  case 428:
#line 2511 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 429:
#line 2515 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 430:
#line 2519 "vb_grammar.y"
    {
				(yyval.node) = ILNode_UserCast_create((yyvsp[(5) - (6)].node), (yyvsp[(3) - (6)].node));
			}
    break;

  case 431:
#line 2522 "vb_grammar.y"
    {
				/* TODO: operand must be exactly the specified type */
				(yyval.node) = ILNode_UserCast_create((yyvsp[(5) - (6)].node), (yyvsp[(3) - (6)].node));
			}
    break;

  case 432:
#line 2526 "vb_grammar.y"
    {
				(yyval.node) = ILNode_UserCast_create((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
			}
    break;

  case 433:
#line 2532 "vb_grammar.y"
    {
				/* Create a "DateTime" instance from the tick value */
				ILInt64 ticks = (yyvsp[(2) - (4)].date) + (yyvsp[(3) - (4)].date);
				(yyval.node) = ILNode_ObjectCreationExpression_create
					(ILNode_SystemType_create("DateTime"),
					 ILNode_Int64_create((ILUInt64)ticks, 0, 0));
			}
    break;

  case 434:
#line 2542 "vb_grammar.y"
    { (yyval.date) = 0; }
    break;

  case 435:
#line 2544 "vb_grammar.y"
    {
				/* The "-freversed-dates" flag causes dates to be
				   interpreted as "DD/MM/YYYY" instead of "MM/DD/YYYY" */
				if(CCStringListContains(extension_flags, num_extension_flags,
										"reversed-dates"))
				{
					(yyval.date) = VBDate((yyvsp[(3) - (5)].integer).value, (yyvsp[(1) - (5)].integer).value, (yyvsp[(5) - (5)].integer).value, (yyvsp[(5) - (5)].integer).numDigits);
				}
				else
				{
					(yyval.date) = VBDate((yyvsp[(1) - (5)].integer).value, (yyvsp[(3) - (5)].integer).value, (yyvsp[(5) - (5)].integer).value, (yyvsp[(5) - (5)].integer).numDigits);
				}
			}
    break;

  case 438:
#line 2565 "vb_grammar.y"
    { (yyval.date) = 0; }
    break;

  case 439:
#line 2566 "vb_grammar.y"
    { (yyval.date) = VBTime((yyvsp[(1) - (2)].integer).value, 0, 0, (yyvsp[(2) - (2)].ampm)); }
    break;

  case 440:
#line 2567 "vb_grammar.y"
    {
				(yyval.date) = VBTime((yyvsp[(1) - (4)].integer).value, (yyvsp[(3) - (4)].integer).value, 0, (yyvsp[(4) - (4)].ampm));
			}
    break;

  case 441:
#line 2570 "vb_grammar.y"
    {
				(yyval.date) = VBTime((yyvsp[(1) - (6)].integer).value, (yyvsp[(3) - (6)].integer).value, (yyvsp[(5) - (6)].integer).value, (yyvsp[(6) - (6)].ampm));
			}
    break;

  case 442:
#line 2576 "vb_grammar.y"
    { (yyval.ampm) = VB_TIME_UNSPEC; }
    break;

  case 443:
#line 2577 "vb_grammar.y"
    {
				if(!ILStrICmp((yyvsp[(1) - (1)].name), "Am"))
				{
					(yyval.ampm) = VB_TIME_AM;
				}
				else if(!ILStrICmp((yyvsp[(1) - (1)].name), "Pm"))
				{
					(yyval.ampm) = VB_TIME_PM;
				}
				else
				{
					CCError(_("invalid AM/PM specifier"));
					(yyval.ampm) = VB_TIME_UNSPEC;
				}
			}
    break;

  case 444:
#line 2595 "vb_grammar.y"
    {
				/* TODO: append the two lists */
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 445:
#line 2599 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 446:
#line 2600 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 447:
#line 2604 "vb_grammar.y"
    {
				(yyval.node) = ILNode_ArgList_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 449:
#line 2611 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 450:
#line 2615 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 452:
#line 2623 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 453:
#line 2630 "vb_grammar.y"
    {}
    break;

  case 454:
#line 2631 "vb_grammar.y"
    {}
    break;

  case 455:
#line 2632 "vb_grammar.y"
    {}
    break;

  case 459:
#line 2642 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_BOOLEAN); }
    break;

  case 460:
#line 2643 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_U1); }
    break;

  case 461:
#line 2644 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_CHAR); }
    break;

  case 462:
#line 2645 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("DateTime"); }
    break;

  case 463:
#line 2646 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("Decimal"); }
    break;

  case 464:
#line 2647 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_R8); }
    break;

  case 465:
#line 2648 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I4); }
    break;

  case 466:
#line 2649 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I8); }
    break;

  case 467:
#line 2650 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("Object"); }
    break;

  case 468:
#line 2651 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_I2); }
    break;

  case 469:
#line 2652 "vb_grammar.y"
    { (yyval.node) = ILNode_PrimitiveType_create(IL_META_ELEMTYPE_R4); }
    break;

  case 470:
#line 2653 "vb_grammar.y"
    { (yyval.node) = ILNode_SystemType_create("String"); }
    break;

  case 472:
#line 2658 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 474:
#line 2666 "vb_grammar.y"
    { (yyval.node) = ILNode_UnaryPlus_create((yyvsp[(2) - (2)].node)); }
    break;

  case 475:
#line 2667 "vb_grammar.y"
    { (yyval.node) = ILNode_Neg_create((yyvsp[(2) - (2)].node)); }
    break;

  case 477:
#line 2672 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Mul_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 478:
#line 2675 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 480:
#line 2682 "vb_grammar.y"
    {
				/* TODO: integer division */
				(yyval.node) = ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 482:
#line 2690 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Rem_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 484:
#line 2697 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Add_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 485:
#line 2700 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Sub_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 487:
#line 2707 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Concat_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 489:
#line 2714 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Shl_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 490:
#line 2717 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Shr_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 492:
#line 2724 "vb_grammar.y"
    {
				/* TODO: value, not object, equality */
				(yyval.node) = ILNode_Eq_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 493:
#line 2728 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Eq_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 494:
#line 2731 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Ne_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 495:
#line 2734 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Lt_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 496:
#line 2737 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Gt_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 497:
#line 2740 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Le_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 498:
#line 2743 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Ge_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 499:
#line 2746 "vb_grammar.y"
    {
				/* TODO: object identity */
				(yyval.node) = ILNode_Eq_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 500:
#line 2750 "vb_grammar.y"
    {
				/* TODO */
				(yyval.node) = 0;
			}
    break;

  case 501:
#line 2754 "vb_grammar.y"
    {
				(yyval.node) = ILNode_IsUntyped_create((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
			}
    break;

  case 503:
#line 2761 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Not_create((yyvsp[(2) - (2)].node));
			}
    break;

  case 505:
#line 2768 "vb_grammar.y"
    {
				(yyval.node) = ILNode_And_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 506:
#line 2771 "vb_grammar.y"
    {
				(yyval.node) = ILNode_LogicalAnd_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 508:
#line 2778 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Or_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 509:
#line 2781 "vb_grammar.y"
    {
				(yyval.node) = ILNode_LogicalOr_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 510:
#line 2784 "vb_grammar.y"
    {
				(yyval.node) = ILNode_Xor_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 511:
#line 2790 "vb_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 512:
#line 2794 "vb_grammar.y"
    { (yyval.node) = ILNode_ToConst_create((yyvsp[(1) - (1)].node)); }
    break;


/* Line 1267 of yacc.c.  */
#line 6559 "vb_grammar.c"
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



