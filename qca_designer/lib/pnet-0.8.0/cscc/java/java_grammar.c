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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_LITERAL = 258,
     FLOAT_LITERAL = 259,
     CHAR_LITERAL = 260,
     BOOLEAN_LITERAL = 261,
     STRING_LITERAL = 262,
     NULL_LITERAL = 263,
     FALSE = 264,
     TRUE = 265,
     IDENTIFIER = 266,
     DIMS = 267,
     ABSTRACT = 268,
     DEFAULT = 269,
     IF = 270,
     PRIVATE = 271,
     THIS = 272,
     BOOLEAN = 273,
     DO = 274,
     IMPLEMENTS = 275,
     PROTECTED = 276,
     THROW = 277,
     BREAK = 278,
     DOUBLE = 279,
     IMPORT = 280,
     PUBLIC = 281,
     THROWS = 282,
     BYTE = 283,
     ELSE = 284,
     INSTANCEOF = 285,
     RETURN = 286,
     TRANSIENT = 287,
     CASE = 288,
     EXTENDS = 289,
     INT = 290,
     SHORT = 291,
     TRY = 292,
     CATCH = 293,
     FINAL = 294,
     INTERFACE = 295,
     STATIC = 296,
     VOID = 297,
     CHAR = 298,
     FINALLY = 299,
     LONG = 300,
     STRICTFP = 301,
     VOLATILE = 302,
     CLASS = 303,
     FLOAT = 304,
     NATIVE = 305,
     SUPER = 306,
     WHILE = 307,
     CONST = 308,
     FOR = 309,
     NEW = 310,
     SWITCH = 311,
     CONTINUE = 312,
     GOTO = 313,
     PACKAGE_KEY = 314,
     SYNCHRONIZED = 315,
     AND_OP = 316,
     OR_OP = 317,
     INC_OP = 318,
     DEC_OP = 319,
     SHL_OP = 320,
     SHR_OP = 321,
     USHR_OP = 322,
     L_OP = 323,
     G_OP = 324,
     LE_OP = 325,
     GE_OP = 326,
     EQ_OP = 327,
     NEQ_OP = 328,
     ADD_ASSIGN_OP = 329,
     SUB_ASSIGN_OP = 330,
     MUL_ASSIGN_OP = 331,
     DIV_ASSIGN_OP = 332,
     AND_ASSIGN_OP = 333,
     OR_ASSIGN_OP = 334,
     XOR_ASSIGN_OP = 335,
     MOD_ASSIGN_OP = 336,
     SHR_ASSIGN_OP = 337,
     SHL_ASSIGN_OP = 338,
     USHR_ASSIGN_OP = 339
   };
#endif
/* Tokens.  */
#define INTEGER_LITERAL 258
#define FLOAT_LITERAL 259
#define CHAR_LITERAL 260
#define BOOLEAN_LITERAL 261
#define STRING_LITERAL 262
#define NULL_LITERAL 263
#define FALSE 264
#define TRUE 265
#define IDENTIFIER 266
#define DIMS 267
#define ABSTRACT 268
#define DEFAULT 269
#define IF 270
#define PRIVATE 271
#define THIS 272
#define BOOLEAN 273
#define DO 274
#define IMPLEMENTS 275
#define PROTECTED 276
#define THROW 277
#define BREAK 278
#define DOUBLE 279
#define IMPORT 280
#define PUBLIC 281
#define THROWS 282
#define BYTE 283
#define ELSE 284
#define INSTANCEOF 285
#define RETURN 286
#define TRANSIENT 287
#define CASE 288
#define EXTENDS 289
#define INT 290
#define SHORT 291
#define TRY 292
#define CATCH 293
#define FINAL 294
#define INTERFACE 295
#define STATIC 296
#define VOID 297
#define CHAR 298
#define FINALLY 299
#define LONG 300
#define STRICTFP 301
#define VOLATILE 302
#define CLASS 303
#define FLOAT 304
#define NATIVE 305
#define SUPER 306
#define WHILE 307
#define CONST 308
#define FOR 309
#define NEW 310
#define SWITCH 311
#define CONTINUE 312
#define GOTO 313
#define PACKAGE_KEY 314
#define SYNCHRONIZED 315
#define AND_OP 316
#define OR_OP 317
#define INC_OP 318
#define DEC_OP 319
#define SHL_OP 320
#define SHR_OP 321
#define USHR_OP 322
#define L_OP 323
#define G_OP 324
#define LE_OP 325
#define GE_OP 326
#define EQ_OP 327
#define NEQ_OP 328
#define ADD_ASSIGN_OP 329
#define SUB_ASSIGN_OP 330
#define MUL_ASSIGN_OP 331
#define DIV_ASSIGN_OP 332
#define AND_ASSIGN_OP 333
#define OR_ASSIGN_OP 334
#define XOR_ASSIGN_OP 335
#define MOD_ASSIGN_OP 336
#define SHR_ASSIGN_OP 337
#define SHL_ASSIGN_OP 338
#define USHR_ASSIGN_OP 339




/* Copy the first part of user declarations.  */
#line 1 "java_grammar.y"

/*
 * java_grammar.y - Input file for Yacc that defines Java syntax
 *
 * Copyright (C) 2001 Southern Storm Software, Pty Ltd.
 * Copyright (C) 2003 Gopal.V
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#line 157 "java_grammar.y"

#include <stdio.h>
#include "il_system.h"
#include "il_opcodes.h"
#include "il_meta.h"
#include "il_utils.h"

#include "java_internal.h"
#include "java_rename.h"

int yydebug;

/*
 * Imports from the lexical analyser.
 */

extern int yylex();

#ifdef YYTEXT_POINTER
extern char *java_text;
#else
extern char java_text[];
#endif

/*
 * Global code generator object.
 */
ILGenInfo JavaCodeGen;

/*
 * Global state used by the parser.
 */
static unsigned long NestingLevel = 0;
static ILIntString CurrPackage = {"", 0};
static ILNode_JPackage *CurrPackageNode = 0;
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
		ILScopeDeclareNamespace(CCGlobalScope, "java.lang");
		ILScopeUsing(CCGlobalScope, "java.lang");
		return CCGlobalScope;
	}
}

/*
 * Reset the global state ready for the next file to be parsed.
 */
static void ResetState(void)
{
	NestingLevel = 0;
	CurrPackage = ILInternString("", 0);
	CurrPackageNode = 0;
	HaveDecls = 0;
	ILScopeClearUsing(GlobalScope());
}

static void InitGlobalPackage()
{
	if(!CurrPackageNode)
	{
		CurrPackageNode = (ILNode_JPackage*)ILNode_JPackage_create(0);
	}
}

/*
 * Determine if the current file already has an "import"
 * declaration for a particular package.
 */
 
static int HaveImported(char *name)
{
	ILNode_JImport *import = (ILNode_JImport*)CurrPackageNode->import;
	while(import != 0)
	{
		if(!strcmp(import->name, name))
		{
			return 1;
		}
		import = (ILNode_JImport*)import->next;
	}
	return 0;
}

/* make sure java.lang is always available */
static void ImportJavaLang()
{
	ILScope *globalScope = GlobalScope();
	InitGlobalPackage();
	if(!HaveImported("java.lang"))
	{
		ILNode_JImportPackage *import;
		import = (ILNode_JImportPackage*)
					ILNode_JImportPackage_create("java.lang");
		import->next = CurrPackageNode->import;
		CurrPackageNode->import=(ILNode*)import;
		ILScopeUsing(globalScope,"java.lang");
	}
}

static void yyerror(char *msg)
{
	CCPluginParseError(msg, java_text);
}


/*
 * Determine if an extension has been enabled using "-f".
 */
#define HaveExtension(name)	\
	(CSStringListContains(extension_flags, num_extension_flags, (name)))

/*
 * Make a simple node and put it into $$.
 */
#define MakeSimple(classSuffix)	\
	do	{	\
		yyval.node = \
			ILNode_##classSuffix##_create(); \
	} while (0)

/*
 * Make a unary node and put it into $$.
 */
#define MakeUnary(classSuffix,expr)	\
	do	{	\
		yyval.node = ILNode_##classSuffix##_create((expr)); \
	} while (0)

/*
 * Make a binary node and put it into $$.
 */
#define MakeBinary(classSuffix,expr1,expr2)	\
	do	{	\
		yyval.node = ILNode_##classSuffix##_create((expr1), (expr2)); \
	} while (0)

/*
 * Make a ternary node and put it into $$.
 */
#define MakeTernary(classSuffix,expr1,expr2,expr3)	\
	do	{	\
		yyval.node = ILNode_##classSuffix##_create((expr1), (expr2), (expr3)); \
	} while (0)

/*
 * Make a quaternary node and put it into $$.
 */
#define MakeQuaternary(classSuffix,expr1,expr2,expr3,expr4)	\
	do	{	\
		yyval.node = ILNode_##classSuffix##_create \
							((expr1), (expr2), (expr3), (expr4)); \
	} while (0)

/*
 * Make a system type name node.
 */
#define MakeSystemType(name)	(ILQualIdentTwo("System", #name))

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
 * Clone the filename/linenum information from one node to another.
 */
static void CloneLine(ILNode *dest, ILNode *src)
{
	yysetfilename(dest, yygetfilename(src));
	yysetlinenum(dest, yygetlinenum(src));
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
static int classNameStackSize = 0;
static int classNameStackMax = 0;

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
#line 456 "java_grammar.y"
{
	struct	{
	ILUInt64 value;
	int type;
	int canneg;
	}integer;
	struct	{
	ILDouble value;
	int type;
	}real;
	ILUInt16 charValue;
	ILIntString string;
	char		*name;
	ILUInt32 count;
	ILUInt32 mask;
	ILNode	*node;
	struct
	{
		ILNode *body;
		ILNode *staticCtors;
	} member;
	struct
	{
		ILNode		   *decl;
		ILNode		   *init;
	} varInit;
}
/* Line 193 of yacc.c.  */
#line 613 "java_grammar.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 484 "java_grammar.y"




/* Line 216 of yacc.c.  */
#line 629 "java_grammar.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2603

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  119
/* YYNRULES -- Number of rules.  */
#define YYNRULES  351
/* YYNRULES -- Number of states.  */
#define YYNSTATES  605

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   106,     2,     2,     2,   104,   100,     2,
      91,    92,    87,   101,    88,   102,    86,   103,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    96,    85,
       2,    95,     2,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,    99,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    93,    98,    94,   105,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    14,    18,    22,    26,
      28,    32,    33,    36,    42,    48,    52,    58,    62,    64,
      66,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    96,    98,   102,   104,   108,
     110,   114,   116,   119,   121,   124,   126,   129,   131,   134,
     136,   139,   143,   146,   150,   151,   153,   155,   158,   160,
     162,   164,   166,   168,   170,   172,   174,   176,   178,   180,
     181,   184,   186,   188,   192,   195,   199,   201,   205,   209,
     212,   217,   221,   224,   228,   233,   237,   239,   243,   247,
     249,   251,   253,   257,   262,   266,   271,   275,   277,   281,
     283,   287,   289,   291,   292,   299,   300,   303,   306,   311,
     312,   314,   318,   321,   323,   326,   328,   330,   333,   335,
     337,   339,   341,   342,   345,   347,   352,   357,   362,   364,
     368,   370,   374,   377,   382,   388,   394,   400,   407,   412,
     419,   426,   427,   434,   437,   438,   441,   445,   448,   450,
     453,   455,   457,   459,   461,   466,   471,   476,   482,   488,
     493,   499,   501,   503,   506,   510,   512,   515,   517,   519,
     521,   526,   530,   535,   539,   544,   548,   550,   552,   554,
     556,   558,   560,   562,   564,   566,   568,   570,   572,   574,
     576,   578,   582,   584,   587,   591,   594,   598,   601,   605,
     609,   615,   623,   629,   639,   648,   649,   651,   655,   658,
     659,   661,   669,   673,   678,   682,   684,   687,   696,   704,
     712,   719,   722,   730,   731,   733,   736,   738,   740,   743,
     746,   750,   753,   758,   762,   768,   771,   774,   776,   778,
     780,   782,   784,   786,   788,   790,   794,   796,   798,   800,
     804,   808,   812,   816,   820,   824,   828,   832,   836,   840,
     844,   848,   850,   856,   858,   862,   864,   868,   870,   874,
     876,   880,   882,   886,   888,   892,   896,   898,   902,   906,
     910,   914,   918,   920,   924,   928,   932,   934,   938,   942,
     944,   948,   952,   956,   958,   960,   963,   966,   968,   971,
     974,   976,   981,   987,   992,   994,   997,  1000,  1002,  1004,
    1006,  1009,  1012,  1014,  1016,  1018,  1020,  1024,  1029,  1031,
    1035,  1040,  1044,  1046,  1048,  1050,  1054,  1058,  1062,  1068,
    1072,  1076,  1078,  1081,  1086,  1089,  1092,  1097,  1102,  1107,
    1110,  1114,  1116,  1120,  1125,  1132,  1139,  1144,  1148,  1153,
    1158,  1162
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     108,     0,    -1,    -1,   109,   113,   129,    -1,    -1,   111,
     110,   113,   129,    -1,    59,   112,    85,    -1,    59,     1,
      85,    -1,    59,   112,     1,    -1,    11,    -1,   112,    86,
      11,    -1,    -1,   113,   114,    -1,    25,   112,    86,    11,
      85,    -1,    25,   112,    86,    87,    85,    -1,    25,     1,
      85,    -1,    25,   112,    86,    87,     1,    -1,    25,   112,
       1,    -1,    28,    -1,    36,    -1,    43,    -1,    35,    -1,
      45,    -1,    49,    -1,    24,    -1,    18,    -1,    42,    -1,
       3,    -1,     4,    -1,     5,    -1,     7,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,   117,    -1,   118,    86,
     117,    -1,   118,    -1,   119,    88,   118,    -1,   121,    -1,
     120,    88,   121,    -1,   115,    -1,   115,   125,    -1,   118,
      -1,   118,   125,    -1,   115,    -1,   115,   125,    -1,   219,
      -1,   219,   125,    -1,   124,    -1,   123,   124,    -1,    89,
     196,    90,    -1,    89,    90,    -1,   125,    89,    90,    -1,
      -1,   127,    -1,   128,    -1,   127,   128,    -1,    21,    -1,
      26,    -1,    16,    -1,    41,    -1,    13,    -1,    39,    -1,
      50,    -1,    60,    -1,    32,    -1,    47,    -1,    46,    -1,
      -1,   129,   130,    -1,   141,    -1,    85,    -1,    91,   132,
      92,    -1,    91,    92,    -1,    91,     1,    92,    -1,   133,
      -1,   132,    88,   133,    -1,    39,   121,   117,    -1,   121,
     117,    -1,    39,   121,   117,   125,    -1,   121,   117,   125,
      -1,    93,    94,    -1,    93,   135,    94,    -1,    93,   135,
      88,    94,    -1,    93,   135,     1,    -1,   136,    -1,   135,
      88,   136,    -1,     1,    88,   136,    -1,   196,    -1,   134,
      -1,   138,    -1,   137,    88,   138,    -1,   117,   125,    95,
     136,    -1,   117,    95,   136,    -1,   117,   125,     1,   136,
      -1,   117,     1,   136,    -1,   140,    -1,   139,    88,   140,
      -1,   117,    -1,   117,    95,   136,    -1,   142,    -1,   156,
      -1,    -1,   126,    48,   117,   144,   143,   146,    -1,    -1,
      34,   121,    -1,    20,   120,    -1,    34,   121,    20,   120,
      -1,    -1,   146,    -1,    93,   147,    94,    -1,    93,    94,
      -1,   148,    -1,   147,   148,    -1,    85,    -1,   150,    -1,
      41,   150,    -1,   154,    -1,   151,    -1,   155,    -1,   141,
      -1,    -1,    27,   119,    -1,   165,    -1,   126,   121,   152,
      85,    -1,   126,     1,   152,    85,    -1,   126,   121,   152,
       1,    -1,   153,    -1,   152,    88,   153,    -1,   117,    -1,
     117,    95,   136,    -1,   117,   125,    -1,   117,   125,    95,
     136,    -1,   126,   117,   131,   149,   164,    -1,   126,   117,
     131,     1,   119,    -1,   126,   117,   131,    27,     1,    -1,
     126,   121,   117,   131,   149,   164,    -1,   126,     1,   117,
     131,    -1,   126,   121,   117,   131,     1,   119,    -1,   126,
     121,   117,   131,    27,     1,    -1,    -1,   126,    40,   117,
     158,   157,   159,    -1,    34,   120,    -1,    -1,     1,   119,
      -1,    93,   160,    94,    -1,    93,    94,    -1,   161,    -1,
     160,   161,    -1,    85,    -1,   162,    -1,   163,    -1,   141,
      -1,   126,   121,   137,    85,    -1,   126,     1,   137,    85,
      -1,   126,   121,   137,     1,    -1,   126,   121,   117,   131,
      85,    -1,   126,     1,   117,   131,    85,    -1,   126,   121,
       1,   131,    -1,   126,   121,   117,   131,     1,    -1,   165,
      -1,    85,    -1,    93,    94,    -1,    93,   166,    94,    -1,
     167,    -1,   166,   167,    -1,   168,    -1,   169,    -1,   141,
      -1,    39,   122,   139,    85,    -1,   122,   139,    85,    -1,
      39,   122,   139,     1,    -1,   122,   139,     1,    -1,    39,
       1,   139,    85,    -1,     1,   139,    85,    -1,   170,    -1,
     178,    -1,   176,    -1,   177,    -1,   171,    -1,   186,    -1,
     181,    -1,   172,    -1,   173,    -1,   174,    -1,   191,    -1,
     175,    -1,   182,    -1,   192,    -1,   165,    -1,   117,    96,
     169,    -1,    85,    -1,    23,    85,    -1,    23,   117,    85,
      -1,    57,    85,    -1,    57,   117,    85,    -1,    31,    85,
      -1,    31,   196,    85,    -1,    22,   196,    85,    -1,    15,
      91,   196,    92,   169,    -1,    15,    91,   196,    92,   169,
      29,   169,    -1,    52,    91,   196,    92,   169,    -1,    54,
      91,   179,    85,   196,    85,   180,    92,   169,    -1,    54,
      91,   179,    85,    85,   180,    92,   169,    -1,    -1,   194,
      -1,    39,   121,   139,    -1,   122,   139,    -1,    -1,   194,
      -1,    19,   169,    52,    91,   196,    92,    85,    -1,    37,
     165,   183,    -1,    37,   165,   183,   185,    -1,    37,   165,
     185,    -1,   184,    -1,   183,   184,    -1,    38,    91,    39,
     118,   117,   125,    92,   165,    -1,    38,    91,   118,   117,
     125,    92,   165,    -1,    38,    91,    39,   118,   117,    92,
     165,    -1,    38,    91,   118,   117,    92,   165,    -1,    44,
     165,    -1,    56,    91,   196,    92,    93,   187,    94,    -1,
      -1,   188,    -1,   188,   190,    -1,   190,    -1,   189,    -1,
     188,   189,    -1,   190,   166,    -1,    33,   195,    96,    -1,
      14,    96,    -1,   190,    33,   195,    96,    -1,   190,    14,
      96,    -1,    60,    91,   196,    92,   165,    -1,   193,    85,
      -1,   193,     1,    -1,   197,    -1,   210,    -1,   211,    -1,
     215,    -1,   216,    -1,   220,    -1,   224,    -1,   193,    -1,
     194,    88,   193,    -1,   196,    -1,   198,    -1,   197,    -1,
     196,    95,   198,    -1,   196,    74,   198,    -1,   196,    75,
     198,    -1,   196,    76,   198,    -1,   196,    77,   198,    -1,
     196,    78,   198,    -1,   196,    79,   198,    -1,   196,    80,
     198,    -1,   196,    81,   198,    -1,   196,    82,   198,    -1,
     196,    83,   198,    -1,   196,    84,   198,    -1,   199,    -1,
     199,    97,   196,    96,   198,    -1,   200,    -1,   199,    62,
     200,    -1,   201,    -1,   200,    61,   201,    -1,   202,    -1,
     201,    98,   202,    -1,   203,    -1,   202,    99,   203,    -1,
     204,    -1,   203,   100,   204,    -1,   205,    -1,   204,    72,
     205,    -1,   204,    73,   205,    -1,   206,    -1,   205,    68,
     206,    -1,   205,    69,   206,    -1,   205,    70,   206,    -1,
     205,    71,   206,    -1,   205,    30,   121,    -1,   207,    -1,
     206,    65,   207,    -1,   206,    66,   207,    -1,   206,    67,
     207,    -1,   208,    -1,   207,   101,   208,    -1,   207,   102,
     208,    -1,   209,    -1,   208,    87,   209,    -1,   208,   103,
     209,    -1,   208,   104,   209,    -1,   210,    -1,   211,    -1,
     101,   209,    -1,   102,   209,    -1,   212,    -1,    63,   209,
      -1,    64,   209,    -1,   213,    -1,    91,   115,    92,   209,
      -1,    91,   115,   125,    92,   209,    -1,    91,   196,    92,
     213,    -1,   214,    -1,   105,   209,    -1,   106,   209,    -1,
     217,    -1,   215,    -1,   216,    -1,   214,    63,    -1,   214,
      64,    -1,   218,    -1,   225,    -1,   224,    -1,   116,    -1,
     115,    86,    48,    -1,   115,   125,    86,    48,    -1,   219,
      -1,   219,    86,    48,    -1,   219,   125,    86,    48,    -1,
     219,    86,    17,    -1,    17,    -1,   220,    -1,   221,    -1,
      91,   196,    92,    -1,   218,    86,   117,    -1,   224,    86,
     117,    -1,   219,    86,    51,    86,   117,    -1,   219,    86,
     117,    -1,    51,    86,   117,    -1,   117,    -1,   219,   222,
      -1,   218,    86,    51,   222,    -1,    51,   222,    -1,    17,
     222,    -1,   219,    89,   196,    90,    -1,   220,    89,   196,
      90,    -1,   221,    89,   196,    90,    -1,    91,    92,    -1,
      91,   223,    92,    -1,   196,    -1,   223,    88,   196,    -1,
      55,   118,   222,   145,    -1,   218,    86,    55,   117,   222,
     145,    -1,   219,    86,    55,   117,   222,   145,    -1,    55,
     115,   123,   125,    -1,    55,   115,   123,    -1,    55,   115,
     125,   134,    -1,    55,   118,   123,   125,    -1,    55,   118,
     123,    -1,    55,   118,   125,   134,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   493,   493,   493,   499,   499,   507,   556,   559,   565,
     566,   575,   576,   580,   615,   631,   633,   635,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   653,   673,   683,
     684,   685,   686,   687,   691,   697,   698,   702,   706,   713,
     714,   718,   721,   730,   733,   745,   748,   757,   761,   774,
     777,   783,   787,   788,   792,   793,   797,   798,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   822,
     828,   832,   833,   837,   838,   839,   845,   849,   856,   859,
     862,   865,   878,   879,   880,   881,   888,   892,   896,   902,
     903,   907,   911,   918,   920,   923,   926,   932,   937,   963,
     967,   974,   975,   979,   979,  1029,  1032,  1035,  1038,  1044,
    1045,  1049,  1050,  1054,  1058,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,  1075,  1076,  1080,  1087,  1091,  1094,  1100,  1104,
    1112,  1115,  1118,  1123,  1130,  1151,  1155,  1162,  1175,  1179,
    1183,  1191,  1191,  1226,  1227,  1228,  1234,  1235,  1239,  1243,
    1249,  1250,  1251,  1252,  1256,  1260,  1263,  1269,  1276,  1279,
    1282,  1288,  1289,  1293,  1294,  1302,  1303,  1309,  1310,  1311,
    1315,  1316,  1335,  1338,  1341,  1344,  1351,  1352,  1353,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1369,  1375,  1379,  1380,  1384,  1385,  1389,  1390,  1394,
    1398,  1401,  1407,  1413,  1417,  1425,  1426,  1427,  1428,  1448,
    1449,  1453,  1459,  1460,  1461,  1465,  1469,  1476,  1477,  1478,
    1479,  1485,  1489,  1495,  1496,  1497,  1498,  1502,  1506,  1513,
    1517,  1521,  1525,  1529,  1536,  1540,  1541,  1548,  1549,  1550,
    1551,  1552,  1553,  1554,  1558,  1559,  1564,  1568,  1569,  1573,
    1574,  1577,  1580,  1583,  1586,  1589,  1592,  1595,  1598,  1601,
    1604,  1611,  1612,  1616,  1617,  1621,  1622,  1628,  1629,  1635,
    1636,  1640,  1641,  1645,  1646,  1647,  1651,  1652,  1653,  1654,
    1655,  1656,  1660,  1661,  1662,  1663,  1667,  1668,  1671,  1677,
    1678,  1681,  1684,  1690,  1691,  1692,  1695,  1716,  1720,  1726,
    1732,  1733,  1736,  1747,  1753,  1754,  1755,  1759,  1760,  1761,
    1766,  1770,  1774,  1775,  1776,  1780,  1781,  1784,  1787,  1788,
    1791,  1794,  1797,  1798,  1799,  1800,  1804,  1807,  1810,  1812,
    1815,  1818,  1822,  1825,  1828,  1834,  1840,  1843,  1845,  1851,
    1852,  1856,  1857,  1861,  1864,  1867,  1877,  1886,  1889,  1898,
    1907,  1910
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_LITERAL", "FLOAT_LITERAL",
  "CHAR_LITERAL", "BOOLEAN_LITERAL", "STRING_LITERAL", "NULL_LITERAL",
  "FALSE", "TRUE", "IDENTIFIER", "DIMS", "ABSTRACT", "DEFAULT", "IF",
  "PRIVATE", "THIS", "BOOLEAN", "DO", "IMPLEMENTS", "PROTECTED", "THROW",
  "BREAK", "DOUBLE", "IMPORT", "PUBLIC", "THROWS", "BYTE", "ELSE",
  "INSTANCEOF", "RETURN", "TRANSIENT", "CASE", "EXTENDS", "INT", "SHORT",
  "TRY", "CATCH", "FINAL", "INTERFACE", "STATIC", "VOID", "CHAR",
  "FINALLY", "LONG", "STRICTFP", "VOLATILE", "CLASS", "FLOAT", "NATIVE",
  "SUPER", "WHILE", "CONST", "FOR", "NEW", "SWITCH", "CONTINUE", "GOTO",
  "PACKAGE_KEY", "SYNCHRONIZED", "AND_OP", "OR_OP", "INC_OP", "DEC_OP",
  "SHL_OP", "SHR_OP", "USHR_OP", "L_OP", "G_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NEQ_OP", "ADD_ASSIGN_OP", "SUB_ASSIGN_OP", "MUL_ASSIGN_OP",
  "DIV_ASSIGN_OP", "AND_ASSIGN_OP", "OR_ASSIGN_OP", "XOR_ASSIGN_OP",
  "MOD_ASSIGN_OP", "SHR_ASSIGN_OP", "SHL_ASSIGN_OP", "USHR_ASSIGN_OP",
  "';'", "'.'", "'*'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'",
  "'='", "':'", "'?'", "'|'", "'^'", "'&'", "'+'", "'-'", "'/'", "'%'",
  "'~'", "'!'", "$accept", "CompilationUnit", "@1", "@2",
  "PackageDeclaration", "PackageOrImportIdentifier",
  "ImportDeclarationZeroOrMore", "ImportDeclaration", "PrimitiveType",
  "Literal", "Identifier", "QualifiedIdentifier",
  "QualifiedIdentifierList", "TypeList", "Type", "LocalVariableType",
  "DimExprs", "DimExpr", "Dims", "ModifiersOpt", "Modifiers", "Modifier",
  "TypeDeclarationZeroOrMore", "TypeDeclaration", "FormalParameters",
  "FormalParametersList", "FormalParameter", "ArrayInitializer",
  "VariableInitializersList", "VariableInitializer",
  "ConstantDeclaratorsList", "ConstantDeclarator", "VariableDeclarators",
  "VariableDeclarator", "ClassOrInterfaceDeclaration", "ClassDeclaration",
  "@3", "SuperOpt", "ClassBodyOpt", "ClassBody",
  "ClassBodyDeclarationOneOrMore", "ClassBodyDeclaration", "ThrowsOpt",
  "InstanceInitializer", "FieldDeclaration", "FieldDeclarators",
  "FieldDeclarator", "ConstructorDeclaration", "MethodDeclaration",
  "InterfaceDeclaration", "@4", "ExtendsOpt", "InterfaceBody",
  "InterfaceBodyDeclarationOneOrMore", "InterfaceBodyDeclaration",
  "InterfaceFieldDeclarator", "InterfaceMethodDeclarator", "MethodBody",
  "Block", "BlockStatements", "BlockStatement", "LocalVariableDeclaration",
  "Statement", "LabeledStatement", "EmptyStatement", "BreakStatement",
  "ContinueStatement", "ReturnStatement", "ThrowStatement",
  "IfThenStatement", "WhileStatement", "ForStatement", "ForInit",
  "ForUpdate", "DoStatement", "TryStatement", "CatchClauses",
  "CatchClause", "FinallyClause", "SwitchStatement", "SwitchBlock",
  "SwitchBlockStatementGroups", "SwitchBlockStatementGroup",
  "SwitchLabels", "SynchronizedStatement", "ExpressionStatement",
  "StatementExpression", "StatementExpressionList", "ConstantExpression",
  "Expression", "Assignment", "ConditionalExpression",
  "ConditionalOrExpression", "ConditionalAndExpression",
  "InclusiveOrExpression", "ExclusiveOrExpression", "AndExpression",
  "EqualityExpression", "RelationalExpression", "ShiftExpression",
  "AdditiveExpression", "MultiplicativeExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression", "CastExpression",
  "UnaryExpressionNotPlusMinus", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "Primary",
  "RealPrimary", "FieldAccess", "MethodInvocation", "ArrayAccess",
  "Arguments", "ExpressionList", "ObjectCreationExpression",
  "ArrayCreationExpression", 0
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
     335,   336,   337,   338,   339,    59,    46,    42,    44,    91,
      93,    40,    41,   123,   125,    61,    58,    63,   124,    94,
      38,    43,    45,    47,    37,   126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   109,   108,   110,   108,   111,   111,   111,   112,
     112,   113,   113,   114,   114,   114,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   121,   122,   122,   122,   122,   123,
     123,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   130,   130,   131,   131,   131,   132,   132,   133,   133,
     133,   133,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   137,   137,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   143,   142,   144,   144,   144,   144,   145,
     145,   146,   146,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   149,   149,   150,   151,   151,   151,   152,   152,
     153,   153,   153,   153,   154,   154,   154,   155,   155,   155,
     155,   157,   156,   158,   158,   158,   159,   159,   160,   160,
     161,   161,   161,   161,   162,   162,   162,   163,   163,   163,
     163,   164,   164,   165,   165,   166,   166,   167,   167,   167,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   170,   171,   172,   172,   173,   173,   174,   174,   175,
     176,   176,   177,   178,   178,   179,   179,   179,   179,   180,
     180,   181,   182,   182,   182,   183,   183,   184,   184,   184,
     184,   185,   186,   187,   187,   187,   187,   188,   188,   189,
     190,   190,   190,   190,   191,   192,   192,   193,   193,   193,
     193,   193,   193,   193,   194,   194,   195,   196,   196,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   204,   205,   205,   205,   205,
     205,   205,   206,   206,   206,   206,   207,   207,   207,   208,
     208,   208,   208,   209,   209,   209,   209,   209,   210,   211,
     212,   212,   212,   212,   213,   213,   213,   214,   214,   214,
     215,   216,   217,   217,   217,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   219,
     219,   219,   220,   220,   220,   220,   221,   221,   221,   222,
     222,   223,   223,   224,   224,   224,   225,   225,   225,   225,
     225,   225
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     4,     3,     3,     3,     1,
       3,     0,     2,     5,     5,     3,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     3,     2,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     3,     2,     3,     1,     3,     3,     2,
       4,     3,     2,     3,     4,     3,     1,     3,     3,     1,
       1,     1,     3,     4,     3,     4,     3,     1,     3,     1,
       3,     1,     1,     0,     6,     0,     2,     2,     4,     0,
       1,     3,     2,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     0,     2,     1,     4,     4,     4,     1,     3,
       1,     3,     2,     4,     5,     5,     5,     6,     4,     6,
       6,     0,     6,     2,     0,     2,     3,     2,     1,     2,
       1,     1,     1,     1,     4,     4,     4,     5,     5,     4,
       5,     1,     1,     2,     3,     1,     2,     1,     1,     1,
       4,     3,     4,     3,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     3,     2,     3,     2,     3,     3,
       5,     7,     5,     9,     8,     0,     1,     3,     2,     0,
       1,     7,     3,     4,     3,     1,     2,     8,     7,     7,
       6,     2,     7,     0,     1,     2,     1,     1,     2,     2,
       3,     2,     4,     3,     5,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     2,     2,     1,     2,     2,
       1,     4,     5,     4,     1,     2,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     4,     1,     3,
       4,     3,     1,     1,     1,     3,     3,     3,     5,     3,
       3,     1,     2,     4,     2,     2,     4,     4,     4,     2,
       3,     1,     3,     4,     6,     6,     4,     3,     4,     4,
       3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,    11,     4,     0,     9,     0,     1,    69,
      11,     7,     8,     6,     0,     0,    12,    54,    69,    10,
       0,     0,    62,    60,    58,    59,    66,    63,    61,    68,
      67,    64,    65,    72,     0,    55,    56,    70,    71,   101,
     102,    54,    15,    17,     0,     0,     0,    57,    10,     0,
      34,     0,   105,    13,    16,    14,     0,     0,   141,     0,
       0,   103,    35,    37,   145,    25,    24,    18,    21,    19,
      26,    20,    22,    23,    41,    43,   143,    39,     0,   107,
     106,     0,     0,     0,     0,    42,    44,     0,    54,   142,
       0,    54,   104,    36,    38,    52,     0,    40,   150,   147,
       0,   153,    54,   148,   151,   152,   108,    61,   115,     0,
     112,     0,   121,    54,   113,   116,   119,   118,   120,   124,
      53,     0,     0,   146,   149,   117,     0,    27,    28,    29,
      30,    31,    32,    33,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,   192,     0,   163,     0,     0,     0,     0,    45,   315,
     331,     0,   169,   190,     0,   165,   167,   168,   176,   180,
     183,   184,   185,   187,   178,   179,   177,   182,   188,   181,
     186,   189,     0,     0,   248,   247,   261,   263,   265,   267,
     269,   271,   273,   276,   282,   286,   289,   293,   294,   297,
     300,   304,   308,   309,   307,   312,   318,   323,   324,   314,
     313,     0,    35,     0,   111,   114,     0,     0,    91,     0,
       0,     0,    99,     0,    97,     0,     0,   335,     0,     0,
       0,   318,   331,     0,   248,   293,   294,   308,   309,   323,
     314,   193,     0,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,     0,   205,     0,     0,     0,   195,
       0,     0,   298,   299,     0,     0,   295,   296,   305,   306,
       0,    46,     0,     0,   164,   166,   236,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   310,   311,     0,     0,     0,    48,   332,     0,     0,
       0,   130,     0,   128,     0,     0,   130,     0,     0,     0,
       0,     0,   155,     0,   159,     0,   156,   154,     0,   175,
       0,     0,   339,   341,     0,     0,     0,     0,   199,   194,
     198,     0,     0,   212,   215,   214,     0,     0,     0,     0,
     330,     0,     0,     0,     0,   244,   206,     0,   347,    49,
       0,   350,     0,   109,     0,   196,     0,     0,     0,   325,
     316,     0,   191,   173,   171,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   249,   264,     0,   266,
     268,   270,   272,   274,   275,   281,   277,   278,   279,   280,
     283,   284,   285,   287,   288,   290,   291,   292,     0,     0,
     326,   321,   319,     0,     0,   329,     0,     0,     0,     0,
     327,     0,   132,   138,   126,     0,     0,     0,    74,     0,
       0,    76,     0,     0,     0,     0,   127,   125,     0,    90,
      96,    89,    94,     0,     0,   158,     0,    92,   160,   157,
     100,    98,     0,     0,   340,     0,     0,   221,   216,   213,
     174,   325,   172,   170,     0,     0,   208,     0,     0,     0,
      50,   346,   348,   349,   351,   343,   110,     0,     0,   301,
       0,   303,   317,     0,   333,     0,     0,     0,   336,   320,
     337,   338,   131,     0,   130,   129,    75,     0,    79,     0,
      73,   135,   136,   123,   162,   134,   161,     0,     0,     0,
       0,    82,     0,    86,    95,    93,   200,   342,     0,     0,
       0,   202,   207,   209,     0,   245,    51,   223,   234,   302,
     262,   109,   328,   109,   133,    78,    81,    77,   139,   140,
     137,     0,    85,     0,    83,     0,     0,     0,     0,     0,
     210,   209,     0,     0,     0,   224,   227,     0,   344,   345,
      80,    88,    84,    87,   201,   211,     0,     0,     0,     0,
       0,   231,     0,   246,   222,   228,     0,     0,     0,     0,
       0,     0,   220,     0,   204,     0,   230,   233,     0,   219,
       0,   218,   203,   232,   217
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,     4,     7,     9,    16,   229,   159,
     232,    75,   513,    76,    77,   161,   368,   369,   330,    34,
      35,    36,    17,    37,   325,   440,   441,   449,   522,   450,
     217,   218,   223,   224,   162,    39,    81,    61,   485,   486,
     113,   114,   444,   115,   116,   322,   323,   117,   118,    40,
      78,    58,    89,   102,   103,   104,   105,   515,   163,   589,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   364,   559,   177,   178,   353,   354,   355,   179,
     564,   565,   566,   567,   180,   181,   182,   560,   582,   183,
     234,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   235,   236,   199,   200,   201,   237,   238,
     204,   205,   231,   239,   208,   317,   344,   240,   210
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -280
static const yytype_int16 yypact[] =
{
      -3,   197,    78,  -280,  -280,    -2,  -280,   148,  -280,    65,
    -280,  -280,  -280,  -280,    88,   199,  -280,   644,    65,  -280,
      70,    22,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,   189,   280,  -280,  -280,  -280,  -280,
    -280,   957,  -280,  -280,     7,   170,   170,  -280,   111,    46,
    -280,    12,    54,  -280,  -280,  -280,   170,   587,  -280,   587,
     587,  -280,  -280,   125,   134,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,    31,   272,   167,  -280,   216,   167,
     347,   290,   170,   170,   299,   307,   307,   587,   788,  -280,
     587,  1479,  -280,  -280,   125,  -280,   310,  -280,  -280,  -280,
     328,  -280,   984,  -280,  -280,  -280,   167,   331,  -280,  1261,
    -280,   797,  -280,  2267,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,   170,   202,  -280,  -280,  -280,   170,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,   350,   357,  1543,  2103,    28,  1683,
     331,  2224,   256,   363,   368,   587,   370,    61,   376,  2103,
    2103,  -280,  2103,  -280,  2103,  2103,  2103,  2103,   320,  -280,
     335,   170,  -280,  -280,  1367,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,    91,  2508,    62,  -280,   -22,   404,   371,   375,
     377,   198,   214,   429,   231,   159,  -280,    85,   133,  -280,
    -280,   252,   143,   157,  -280,   395,   201,    94,   394,    79,
    -280,   170,   396,   170,  -280,  -280,    47,   322,  -280,   396,
      47,   109,   393,   323,  -280,  2103,  1755,  -280,   376,   320,
     439,   234,  -280,   850,  -280,  -280,  -280,  -280,  -280,   403,
     414,  -280,   416,  -280,  1146,    41,   170,   170,  2103,   170,
     395,   414,   170,  -280,  2103,  1827,   413,   296,  2103,  -280,
     420,  2103,  -280,  -280,   221,  1252,  -280,  -280,  -280,  -280,
     461,   327,  1543,   131,  -280,  -280,  -280,  -280,  2103,  2103,
    2103,  2103,  2103,  2103,  2103,  2103,  2103,  2103,  2103,  2103,
    2103,  2103,  2103,  2103,  2103,  2103,  2103,  2103,   587,  2103,
    2103,  2103,  2103,  2103,  2103,  2103,  2103,  2103,  2103,  2103,
    2103,  -280,  -280,   106,   203,  1895,   337,  -280,  2103,  2103,
     170,   271,   340,  -280,   571,    40,   271,   155,  1963,  1963,
       9,   426,  -280,   170,  -280,   192,  -280,  -280,  1963,  -280,
     170,  2254,  -280,  2508,   243,   327,   423,   337,  -280,  -280,
    -280,   427,   331,    41,  -280,  -280,   355,   263,  2288,   171,
    -280,  2310,   587,   170,   432,  -280,   431,  1895,   413,  -280,
     295,   413,   295,   290,  2332,  -280,  2354,  2103,   289,  2171,
    -280,   475,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,   404,  1040,   371,
     375,   377,   198,   214,   214,  -280,   429,   429,   429,   429,
     231,   231,   231,   159,   159,  -280,  -280,  -280,   357,   170,
    -280,  -280,  -280,   438,   170,  -280,  2376,   478,  2398,  2420,
    -280,  1963,   110,  -280,  -280,   170,   436,   587,  -280,   170,
     303,  -280,   170,   237,   218,    60,  -280,  -280,  1439,  -280,
    -280,  2508,  -280,  1963,  1963,  -280,    32,  -280,  -280,  -280,
    -280,  -280,  1543,  2103,  -280,  2103,    21,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  1543,   170,   445,  2031,  2103,  2442,
    -280,   307,  -280,   307,  -280,  -280,  -280,   442,   331,  -280,
    2103,  -280,  -280,  2103,  -280,   357,   170,   357,  -280,  -280,
    -280,  -280,  -280,  1963,   209,  -280,  -280,   170,    31,   932,
    -280,   134,  -280,   134,  -280,  -280,  -280,   170,   265,   218,
     449,  -280,    34,  -280,  -280,  -280,   509,  2508,  2464,   170,
      20,  -280,   445,  2103,  2486,  -280,  -280,     3,  -280,  -280,
    -280,   290,  -280,   290,  -280,    31,   307,  -280,   134,  -280,
    -280,  1963,  -280,  1615,  -280,  1543,   455,    20,   353,   453,
     431,  2103,   451,  2103,   458,     3,  -280,   853,  -280,  -280,
     307,  -280,  -280,  -280,  -280,  -280,   358,   331,   366,  1543,
     464,  -280,   457,  2508,  -280,  -280,  1049,   462,  2103,  1155,
     331,   374,  -280,   331,  -280,  1543,  -280,  -280,   463,  -280,
     331,  -280,  -280,  -280,  -280
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,  -280,  -280,   542,   550,  -280,   -38,  -280,
     -45,    14,   -49,    -8,   -57,  -132,   306,   107,   -69,   246,
    -280,   530,   548,  -280,  -191,  -280,    58,  -229,  -280,  -279,
     446,   236,  -137,   233,    27,  -280,  -280,  -280,  -252,   490,
    -280,   466,   132,   473,  -280,   372,   146,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,   481,  -280,  -280,    67,   -87,   482,
    -156,  -280,  -109,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,    23,  -280,  -280,  -280,   240,   241,  -280,
    -280,  -280,    25,    36,  -280,  -280,  -239,   332,     8,   488,
     -25,   502,  -280,   312,   308,   311,   314,   317,   118,   103,
     194,    44,    35,    42,   100,  -280,   238,  -280,   114,   164,
    -280,   477,  -107,   172,  -280,   -77,  -280,   -40,  -280
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -244
static const yytype_int16 yytable[] =
{
      51,    52,   206,    80,   119,    85,    86,    64,   275,   249,
     453,    62,    62,    56,    62,    62,   365,   562,    48,    74,
     119,    74,    74,    43,   273,   331,   119,   230,   334,   335,
      97,    50,    50,   328,   206,   552,   563,    93,    62,    50,
     290,   442,    62,   122,    38,    62,    57,    54,   328,    74,
     452,    79,    74,   245,   213,    62,     1,   206,   227,   460,
     529,   517,    74,  -237,   160,   253,   212,   443,    38,   209,
      63,   158,    50,    74,    59,   291,   216,   220,     8,   351,
    -243,   222,   106,    11,   184,   352,  -238,   518,    60,   271,
      15,   160,   276,   242,    49,  -242,   209,    94,    96,    19,
      62,   251,   260,   158,   454,  -144,    82,   256,    44,   356,
     336,   184,   359,   241,   264,   101,   222,    50,   112,   160,
      84,    84,   553,   363,   209,  -122,   158,   329,   554,   101,
     433,    55,   383,  -122,  -239,   445,    84,   316,   324,   184,
     112,   482,   329,   484,  -240,  -122,   259,  -237,   206,    12,
    -237,   197,   502,  -122,  -237,    42,   446,   418,  -241,   257,
     345,   419,   347,   382,  -243,   320,   321,  -243,   326,   523,
    -238,  -243,   472,  -238,   524,   525,   277,  -238,   197,  -242,
     373,    50,  -242,   318,   262,   263,  -242,   370,   372,   266,
     267,   268,   269,   458,   337,   378,    53,   333,     5,    96,
      20,   222,    62,   219,   222,   503,   197,   360,     6,   198,
       6,    82,   -47,    50,    50,   209,   384,   158,  -239,   340,
     421,  -239,    83,   202,   544,  -239,   476,   160,  -240,    45,
     184,  -240,   209,    13,    14,  -240,   198,    46,   512,   535,
     447,   405,  -241,   435,   298,  -241,   308,   184,    50,  -241,
     202,   422,   432,    62,   423,    87,   473,   432,   424,   340,
      74,   357,   309,   310,   198,   467,   549,   439,   420,   425,
     296,   297,   571,   203,   573,   430,    50,   459,   202,    62,
     373,   207,   299,   300,   301,   302,    74,   314,   456,   568,
     315,   569,   226,    22,   365,   222,    23,   197,    84,   481,
     203,    24,   483,   514,   431,   475,    25,   270,   207,    88,
      84,   109,    26,   377,   197,   311,   312,    62,   222,    27,
     314,    28,   365,   315,    74,   226,    29,    30,   203,   121,
      31,   463,   306,   307,   100,   464,   207,   111,   532,    50,
      32,   494,   252,   415,   416,   417,    65,   226,   100,    82,
     413,   414,    66,   526,   226,   198,    67,   516,    82,   111,
      84,    84,   324,    68,    69,   531,   431,    90,    45,   202,
      70,    71,   198,    72,   495,   381,    46,    73,    96,   497,
     507,   490,    82,    91,    96,   367,   202,   226,   448,    95,
     504,   509,    62,   511,   508,   510,    96,    62,    62,    74,
     120,   538,   406,   407,   408,   409,   270,   332,   339,    84,
     333,   340,   489,   381,   403,   404,    96,   160,   541,   203,
     543,    62,   209,   427,   109,   434,    96,   207,   435,   160,
     222,   272,   516,   275,   209,   432,   203,   184,   209,   546,
     470,   225,    84,   340,   207,   577,   574,    84,   226,   184,
     590,   542,   439,   184,   254,    96,    63,    63,   593,   255,
     206,   258,   545,    96,    62,   292,   600,   261,   548,   293,
     594,    74,    62,    62,   294,   480,   570,   295,   480,   206,
     530,   313,   206,   319,    62,   558,   602,   324,   338,   578,
     592,   346,   318,   209,   303,   304,   305,   410,   411,   412,
     320,   349,   367,   599,   197,   375,   601,   591,   184,   380,
     160,   455,   576,   604,   465,   209,   197,   477,   466,   478,
     197,   209,   160,   492,   496,   539,   499,   209,   506,   158,
     184,    63,    63,   340,   160,   537,   184,   551,   555,   209,
     575,   160,   184,   557,   160,   579,   209,   581,   158,   209,
     160,   158,   584,   596,   184,   209,   595,    21,   597,   603,
      18,   184,   198,   371,   184,    47,    41,   547,   221,   457,
     184,    92,   436,   461,   198,   197,   202,   519,   198,   215,
     125,   505,    50,   124,   580,   327,   550,   366,   202,    65,
     585,   164,   202,   468,   469,    66,   598,   197,    50,    67,
     399,   586,   397,   197,   400,    65,    68,    69,   401,   197,
     437,    66,   402,    70,    71,    67,    72,   491,   250,     0,
      73,   197,    68,    69,     0,   233,   203,   244,   197,    70,
      71,   197,    72,   198,   207,     0,    73,   197,   203,     0,
     265,     0,   203,     0,    -3,     0,   207,   202,     0,     0,
     207,     0,     0,     0,     0,   198,     0,    22,     0,     0,
      23,   198,     0,   438,     0,    24,     0,   198,     0,   202,
      25,     0,     0,     0,     0,   202,    26,     0,     0,   198,
       0,   202,     0,    27,     0,    28,   198,     0,     0,   198,
      29,    30,     0,   202,    31,   198,     0,   203,     0,     0,
     202,     0,     0,   202,    32,   207,     0,     0,     0,   202,
       0,     0,     0,   341,   343,     0,     0,     0,     0,   203,
       0,     0,     0,     0,     0,   203,     0,   207,     0,    33,
       0,   203,     0,   207,     0,     0,   358,     0,     0,   207,
       0,     0,   361,   203,     0,     0,   374,     0,     0,   376,
     203,   207,     0,   203,     0,     0,     0,     0,   207,   203,
       0,   207,     0,     0,     0,     0,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,     0,     0,     0,     0,     0,     0,   211,     0,
       0,    22,     0,   426,    23,     0,   428,   429,    50,    24,
       0,     0,     0,     0,    25,    65,   451,   451,     0,     0,
      26,    66,     0,     0,     0,    67,   451,    27,     0,    28,
       0,     0,    68,    69,    29,    30,     0,    45,    31,    70,
      71,     0,    72,     0,     0,    46,    73,     0,    32,     0,
       0,     0,     0,     0,   126,   479,   127,   128,   129,     0,
     130,   131,   132,   133,    50,     0,    22,   587,   134,    23,
     135,    65,   136,    98,    24,   137,   138,    66,     0,    25,
       0,    67,    99,     0,   139,    26,   588,     0,    68,    69,
     140,     0,   141,   -54,    28,    70,    71,     0,    72,    29,
      30,   -54,    73,    31,   142,   143,     0,   144,   145,   146,
     147,     0,     0,   148,     0,     0,   149,   150,     0,   451,
       0,     0,     0,     0,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   348,   451,     0,   151,     0,
       0,   451,   451,    50,   152,   289,   109,  -226,     0,     0,
      65,   527,     0,   528,   154,   155,    66,    -5,   156,   157,
      67,     0,     0,     0,     0,   534,     0,    68,    69,     0,
      22,   437,     0,    23,    70,    71,     0,    72,    24,     0,
       0,    73,     0,    25,     0,     0,     0,     0,     0,    26,
       0,   451,     0,     0,     0,   540,    27,    22,    28,     0,
      23,     0,     0,    29,    30,    24,     0,    31,     0,     0,
      25,     0,     0,     0,     0,     0,    26,    32,     0,     0,
       0,     0,     0,    27,     0,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,     0,     0,     0,   451,
       0,   451,    33,     0,    32,     0,     0,     0,     0,     0,
     126,   583,   127,   128,   129,     0,   130,   131,   132,   133,
      50,     0,    22,   587,   134,    23,   135,    65,   136,    98,
      24,   137,   138,    66,     0,    25,   583,    67,   123,     0,
     139,    26,   588,     0,    68,    69,   140,     0,   141,   -54,
      28,    70,    71,     0,    72,    29,    30,   -54,    73,    31,
     142,   143,     0,   144,   145,   146,   147,     0,     0,   148,
       0,     0,   149,   150,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   289,   493,     0,     0,     0,
     152,     0,   109,  -225,     0,     0,     0,     0,     0,     0,
     154,   155,     0,     0,   156,   157,   126,     0,   127,   128,
     129,     0,   130,   131,   132,   133,    50,     0,    22,  -229,
     134,    23,   135,    65,   136,     0,    24,   137,   138,    66,
       0,    25,     0,    67,     0,     0,   139,    26,  -229,     0,
      68,    69,   140,     0,   141,   -54,    28,    70,    71,     0,
      72,    29,    30,   -54,    73,    31,   142,   143,     0,   144,
     145,   146,   147,     0,     0,   148,     0,     0,   149,   150,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   350,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   289,     0,     0,     0,     0,   152,     0,   109,  -229,
       0,     0,     0,     0,     0,     0,   154,   155,     0,     0,
     156,   157,   126,     0,   127,   128,   129,     0,   130,   131,
     132,   133,    50,     0,    22,     0,   134,    23,   135,    65,
     136,     0,    24,   137,   138,    66,     0,    25,     0,    67,
       0,     0,   139,    26,     0,     0,    68,    69,   140,     0,
     141,   -54,    28,    70,    71,     0,    72,    29,    30,   -54,
      73,    31,   142,   143,     0,   144,   145,   146,   147,     0,
       0,   148,     0,     0,   149,   150,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,     0,     0,     0,
       0,     0,     0,     0,   379,     0,   151,   289,     0,     0,
       0,     0,   152,     0,   109,   153,     0,     0,     0,     0,
       0,     0,   154,   155,     0,     0,   156,   157,   126,     0,
     127,   128,   129,     0,   130,   131,   132,   133,    50,     0,
      22,     0,   134,    23,   135,    65,   136,     0,    24,   137,
     138,    66,     0,    25,     0,    67,     0,     0,   139,    26,
       0,     0,    68,    69,   140,     0,   141,   -54,    28,    70,
      71,     0,    72,    29,    30,   -54,    73,    31,   142,   143,
       0,   144,   145,   146,   147,     0,     0,   148,     0,     0,
     149,   150,     0,     0,     0,     0,     0,     0,     0,     0,
     520,     0,   127,   128,   129,     0,   130,   131,   132,   133,
      50,     0,   151,     0,     0,     0,   135,    65,   152,     0,
     109,   274,     0,    66,     0,     0,     0,    67,   154,   155,
       0,     0,   156,   157,    68,    69,     0,     0,     0,     0,
       0,    70,    71,     0,    72,     0,     0,     0,    73,     0,
     142,     0,    22,     0,   145,    23,     0,     0,     0,     0,
      24,     0,   149,   150,     0,    25,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,    27,     0,
     107,     0,     0,     0,     0,    29,    30,     0,     0,    31,
     152,     0,   448,   521,     0,     0,     0,     0,     0,    32,
     154,   155,     0,     0,   156,   157,   127,   128,   129,     0,
     130,   131,   132,   133,    50,     0,     0,     0,   134,     0,
     135,    65,   136,     0,   108,   137,   138,    66,     0,     0,
       0,    67,   109,   110,   139,     0,     0,     0,    68,    69,
     140,     0,     0,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     0,   142,   143,     0,   144,   145,   146,
     147,     0,     0,   228,     0,     0,   149,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
     129,     0,   130,   131,   132,   133,    50,     0,   151,     0,
       0,     0,   135,    65,   152,     0,   109,     0,     0,    66,
       0,     0,     0,    67,   154,   155,     0,     0,   156,   157,
      68,    69,     0,     0,     0,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     0,   142,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,   149,   150,
       0,     0,     0,     0,     0,     0,   127,   128,   129,     0,
     130,   131,   132,   133,    50,     0,     0,     0,     0,     0,
     135,    65,     0,     0,     0,     0,   152,    66,   448,   572,
       0,    67,     0,     0,     0,     0,   154,   155,    68,    69,
     156,   157,     0,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     0,   142,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,   149,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
     129,     0,   130,   131,   132,   133,    50,     0,   243,     0,
       0,     0,   135,    65,   152,     0,     0,     0,     0,    66,
       0,     0,     0,    67,   154,   155,     0,     0,   156,   157,
      68,    69,     0,     0,     0,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     0,   142,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,   149,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,   129,     0,   130,   131,   132,   133,    50,     0,
       0,     0,     0,     0,   135,    65,   152,   342,     0,     0,
       0,    66,     0,     0,     0,    67,   154,   155,     0,     0,
     156,   157,    68,    69,     0,     0,   362,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     0,   142,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
     149,   150,     0,     0,     0,     0,     0,     0,   127,   128,
     129,     0,   130,   131,   132,   133,    50,     0,     0,     0,
       0,     0,   135,    65,     0,     0,     0,     0,   152,    66,
       0,     0,     0,    67,     0,     0,     0,     0,   154,   155,
      68,    69,   156,   157,     0,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     0,   142,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,   149,   150,
       0,     0,     0,     0,     0,     0,   127,   128,   129,     0,
     130,   131,   132,   133,    50,     0,     0,     0,     0,     0,
     135,    65,     0,     0,     0,    95,   152,    66,     0,     0,
       0,    67,     0,     0,     0,     0,   154,   155,    68,    69,
     156,   157,     0,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     0,   142,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,   149,   150,     0,     0,
       0,     0,     0,     0,   127,   128,   129,     0,   130,   131,
     132,   133,    50,     0,     0,     0,     0,     0,   135,    65,
       0,     0,     0,     0,   152,    66,   448,     0,     0,    67,
       0,     0,     0,     0,   154,   155,    68,    69,   156,   157,
       0,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     0,   142,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,   149,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,   129,     0,
     130,   131,   132,   133,    50,     0,   533,     0,     0,     0,
     135,    65,   152,     0,     0,     0,     0,    66,     0,     0,
       0,    67,   154,   155,     0,     0,   156,   157,    68,    69,
       0,     0,     0,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     0,   142,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,   149,   150,     0,     0,
       0,     0,     0,     0,   127,   128,   129,     0,   130,   131,
     132,   133,    50,     0,     0,     0,     0,     0,   135,    65,
       0,     0,     0,     0,   152,    66,     0,     0,     0,    67,
       0,     0,     0,     0,   154,   155,    68,    69,   156,   157,
       0,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     0,   142,     0,     0,   246,   145,   127,   128,   129,
       0,   130,   131,   132,   133,    50,     0,   -63,     0,     0,
     -63,   135,    65,     0,     0,   -63,     0,     0,    66,     0,
     -63,     0,    67,     0,     0,     0,   -63,     0,     0,    68,
      69,     0,   248,   -63,   -63,   -63,    70,    71,     0,    72,
     -63,   -63,   -63,    73,   -63,   142,   156,   157,     0,   247,
      22,     0,     0,    23,   -63,     0,     0,     0,    24,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,    27,     0,   107,     0,
       0,     0,     0,    29,    30,   248,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,     0,
       0,     0,     0,     0,     0,     0,   462,     0,     0,   289,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
     109,   214,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,     0,     0,     0,     0,     0,     0,     0,
     471,     0,     0,   289,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,     0,     0,     0,     0,     0,
       0,     0,   474,     0,     0,   289,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,     0,     0,     0,
       0,     0,     0,     0,   487,     0,     0,   289,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,     0,
       0,     0,     0,     0,     0,     0,   488,     0,     0,   289,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,     0,     0,     0,     0,     0,   498,     0,     0,     0,
       0,   289,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,     0,     0,     0,     0,     0,   500,     0,
       0,     0,     0,   289,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,     0,     0,     0,     0,     0,
     501,     0,     0,     0,     0,   289,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,     0,     0,     0,
       0,     0,   536,     0,     0,     0,     0,   289,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,     0,
       0,     0,     0,     0,     0,     0,   556,     0,     0,   289,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   561,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   289,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   289
};

static const yytype_int16 yycheck[] =
{
      45,    46,   109,    60,    91,    74,    75,    56,   164,   141,
       1,    56,    57,     1,    59,    60,   255,    14,    11,    57,
     107,    59,    60,     1,   161,   216,   113,   136,   219,   220,
      87,    11,    11,     1,   141,     1,    33,    82,    83,    11,
      62,     1,    87,   100,    17,    90,    34,     1,     1,    87,
     329,    59,    90,   140,   111,   100,    59,   164,   135,   338,
      39,     1,   100,     1,   109,   142,   111,    27,    41,   109,
      56,   109,    11,   111,    20,    97,   121,   122,     0,    38,
       1,   126,    90,    85,   109,    44,     1,    27,    34,   158,
      25,   136,     1,   138,    87,     1,   136,    83,    89,    11,
     145,   141,   147,   141,    95,    93,    86,   145,    86,   246,
       1,   136,   249,    85,   152,    88,   161,    11,    91,   164,
      89,    89,    88,   255,   164,    85,   164,    95,    94,   102,
     321,    85,     1,    93,     1,   326,    89,   206,    91,   164,
     113,   370,    95,   372,     1,    85,    85,    85,   255,     1,
      88,   109,   431,    93,    92,    85,     1,    51,     1,   145,
     229,    55,   231,   272,    85,    86,   211,    88,   213,   448,
      85,    92,     1,    88,   453,   454,    85,    92,   136,    85,
     257,    11,    88,    89,   149,   150,    92,   256,   257,   154,
     155,   156,   157,     1,    85,   264,    85,    88,     1,    89,
       1,   246,   247,     1,   249,    95,   164,   252,    11,   109,
      11,    86,    11,    11,    11,   255,    85,   255,    85,    88,
      17,    88,    88,   109,   503,    92,   363,   272,    85,    40,
     255,    88,   272,    85,    86,    92,   136,    48,     1,   478,
      85,   298,    85,    88,    30,    88,    87,   272,    11,    92,
     136,    48,   321,   298,    51,    88,    85,   326,    55,    88,
     298,   247,   103,   104,   164,   352,     1,   324,   313,   314,
      72,    73,   551,   109,   553,   320,    11,    85,   164,   324,
     357,   109,    68,    69,    70,    71,   324,    86,   333,   541,
      89,   543,    91,    13,   533,   340,    16,   255,    89,   368,
     136,    21,   371,    85,    95,   362,    26,    86,   136,    93,
      89,    93,    32,    92,   272,    63,    64,   362,   363,    39,
      86,    41,   561,    89,   362,    91,    46,    47,   164,     1,
      50,    88,   101,   102,    88,    92,   164,    91,   475,    11,
      60,   418,    86,   308,   309,   310,    18,    91,   102,    86,
     306,   307,    24,   462,    91,   255,    28,   444,    86,   113,
      89,    89,    91,    35,    36,   474,    95,    20,    40,   255,
      42,    43,   272,    45,   419,    86,    48,    49,    89,   424,
     437,    92,    86,    93,    89,    89,   272,    91,    93,    90,
     435,    88,   437,   442,   439,    92,    89,   442,   443,   437,
      90,   488,   299,   300,   301,   302,    86,    85,    85,    89,
      88,    88,   377,    86,   296,   297,    89,   462,   495,   255,
     497,   466,   462,    86,    93,    85,    89,   255,    88,   474,
     475,    96,   519,   589,   474,   504,   272,   462,   478,   508,
      85,    91,    89,    88,   272,    92,   555,    89,    91,   474,
      92,   496,   509,   478,    91,    89,   442,   443,    92,    91,
     567,    91,   507,    89,   509,    61,    92,    91,   517,    98,
     579,   509,   517,   518,    99,   368,   545,   100,   371,   586,
     466,    86,   589,    89,   529,   530,   595,    91,    95,   558,
     577,    52,    89,   533,    65,    66,    67,   303,   304,   305,
      86,    85,    89,   590,   462,    85,   593,   576,   533,    48,
     555,    85,   557,   600,    91,   555,   474,    85,    91,    88,
     478,   561,   567,    48,    86,   490,    48,   567,    92,   567,
     555,   517,   518,    88,   579,    93,   561,    88,    29,   579,
      85,   586,   567,   529,   589,    92,   586,    96,   586,   589,
     595,   589,    94,    96,   579,   595,    92,    15,    96,    96,
      10,   586,   462,   257,   589,    35,    18,   509,   122,   333,
     595,    81,     1,   340,   474,   533,   462,   445,   478,   113,
     107,   435,    11,   102,   561,   213,   519,   255,   474,    18,
     565,   109,   478,   353,   353,    24,   588,   555,    11,    28,
     292,   565,   290,   561,   293,    18,    35,    36,   294,   567,
      39,    24,   295,    42,    43,    28,    45,   379,   141,    -1,
      49,   579,    35,    36,    -1,   137,   462,   139,   586,    42,
      43,   589,    45,   533,   462,    -1,    49,   595,   474,    -1,
     152,    -1,   478,    -1,     0,    -1,   474,   533,    -1,    -1,
     478,    -1,    -1,    -1,    -1,   555,    -1,    13,    -1,    -1,
      16,   561,    -1,    92,    -1,    21,    -1,   567,    -1,   555,
      26,    -1,    -1,    -1,    -1,   561,    32,    -1,    -1,   579,
      -1,   567,    -1,    39,    -1,    41,   586,    -1,    -1,   589,
      46,    47,    -1,   579,    50,   595,    -1,   533,    -1,    -1,
     586,    -1,    -1,   589,    60,   533,    -1,    -1,    -1,   595,
      -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,   555,
      -1,    -1,    -1,    -1,    -1,   561,    -1,   555,    -1,    85,
      -1,   567,    -1,   561,    -1,    -1,   248,    -1,    -1,   567,
      -1,    -1,   254,   579,    -1,    -1,   258,    -1,    -1,   261,
     586,   579,    -1,   589,    -1,    -1,    -1,    -1,   586,   595,
      -1,   589,    -1,    -1,    -1,    -1,    -1,   595,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    13,    -1,   315,    16,    -1,   318,   319,    11,    21,
      -1,    -1,    -1,    -1,    26,    18,   328,   329,    -1,    -1,
      32,    24,    -1,    -1,    -1,    28,   338,    39,    -1,    41,
      -1,    -1,    35,    36,    46,    47,    -1,    40,    50,    42,
      43,    -1,    45,    -1,    -1,    48,    49,    -1,    60,    -1,
      -1,    -1,    -1,    -1,     1,   367,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    85,    21,    22,    23,    24,    -1,    26,
      -1,    28,    94,    -1,    31,    32,    33,    -1,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    -1,    -1,    60,    -1,    -1,    63,    64,    -1,   431,
      -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   448,    -1,    85,    -1,
      -1,   453,   454,    11,    91,    95,    93,    94,    -1,    -1,
      18,   463,    -1,   465,   101,   102,    24,     0,   105,   106,
      28,    -1,    -1,    -1,    -1,   477,    -1,    35,    36,    -1,
      13,    39,    -1,    16,    42,    43,    -1,    45,    21,    -1,
      -1,    49,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      -1,   503,    -1,    -1,    -1,   493,    39,    13,    41,    -1,
      16,    -1,    -1,    46,    47,    21,    -1,    50,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    32,    60,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,   551,
      -1,   553,    85,    -1,    60,    -1,    -1,    -1,    -1,    -1,
       1,   563,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    85,
      21,    22,    23,    24,    -1,    26,   588,    28,    94,    -1,
      31,    32,    33,    -1,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    95,    96,    -1,    -1,    -1,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,   106,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      -1,    26,    -1,    28,    -1,    -1,    31,    32,    33,    -1,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    -1,    -1,    60,    -1,    -1,    63,    64,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    95,    -1,    -1,    -1,    -1,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,   106,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    -1,    26,    -1,    28,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    -1,
      -1,    60,    -1,    -1,    63,    64,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    85,    95,    -1,    -1,
      -1,    -1,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,   106,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    -1,    26,    -1,    28,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    -1,    -1,    60,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    85,    -1,    -1,    -1,    17,    18,    91,    -1,
      93,    94,    -1,    24,    -1,    -1,    -1,    28,   101,   102,
      -1,    -1,   105,   106,    35,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    45,    -1,    -1,    -1,    49,    -1,
      51,    -1,    13,    -1,    55,    16,    -1,    -1,    -1,    -1,
      21,    -1,    63,    64,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    50,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    60,
     101,   102,    -1,    -1,   105,   106,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,
      17,    18,    19,    -1,    85,    22,    23,    24,    -1,    -1,
      -1,    28,    93,    94,    31,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    49,    -1,    51,    52,    -1,    54,    55,    56,
      57,    -1,    -1,    60,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    85,    -1,
      -1,    -1,    17,    18,    91,    -1,    93,    -1,    -1,    24,
      -1,    -1,    -1,    28,   101,   102,    -1,    -1,   105,   106,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      45,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    91,    24,    93,    94,
      -1,    28,    -1,    -1,    -1,    -1,   101,   102,    35,    36,
     105,   106,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    49,    -1,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    85,    -1,
      -1,    -1,    17,    18,    91,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,   101,   102,    -1,    -1,   105,   106,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      45,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    91,    92,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    28,   101,   102,    -1,    -1,
     105,   106,    35,    36,    -1,    -1,    39,    -1,    -1,    42,
      43,    -1,    45,    -1,    -1,    -1,    49,    -1,    51,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    91,    24,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,   101,   102,
      35,    36,   105,   106,    -1,    -1,    -1,    42,    43,    -1,
      45,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    90,    91,    24,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,   101,   102,    35,    36,
     105,   106,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    49,    -1,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    91,    24,    93,    -1,    -1,    28,
      -1,    -1,    -1,    -1,   101,   102,    35,    36,   105,   106,
      -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,
      49,    -1,    51,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    85,    -1,    -1,    -1,
      17,    18,    91,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    28,   101,   102,    -1,    -1,   105,   106,    35,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    49,    -1,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    91,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,   101,   102,    35,    36,   105,   106,
      -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,
      49,    -1,    51,    -1,    -1,     1,    55,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    13,    -1,    -1,
      16,    17,    18,    -1,    -1,    21,    -1,    -1,    24,    -1,
      26,    -1,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      36,    -1,    91,    39,    40,    41,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,   105,   106,    -1,    55,
      13,    -1,    -1,    16,    60,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,    46,    47,    91,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    95,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    95,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    95,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,   108,   109,   111,     1,    11,   112,     0,   113,
     110,    85,     1,    85,    86,    25,   114,   129,   113,    11,
       1,   112,    13,    16,    21,    26,    32,    39,    41,    46,
      47,    50,    60,    85,   126,   127,   128,   130,   141,   142,
     156,   129,    85,     1,    86,    40,    48,   128,    11,    87,
      11,   117,   117,    85,     1,    85,     1,    34,   158,    20,
      34,   144,   117,   118,   119,    18,    24,    28,    35,    36,
      42,    43,    45,    49,   115,   118,   120,   121,   157,   120,
     121,   143,    86,    88,    89,   125,   125,    88,    93,   159,
      20,    93,   146,   117,   118,    90,    89,   121,    85,    94,
     126,   141,   160,   161,   162,   163,   120,    41,    85,    93,
      94,   126,   141,   147,   148,   150,   151,   154,   155,   165,
      90,     1,   121,    94,   161,   150,     1,     3,     4,     5,
       7,     8,     9,    10,    15,    17,    19,    22,    23,    31,
      37,    39,    51,    52,    54,    55,    56,    57,    60,    63,
      64,    85,    91,    94,   101,   102,   105,   106,   115,   116,
     117,   122,   141,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   181,   182,   186,
     191,   192,   193,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   224,
     225,     1,   117,   121,    94,   148,   117,   137,   138,     1,
     117,   137,   117,   139,   140,    91,    91,   222,    60,   115,
     169,   219,   117,   196,   197,   210,   211,   215,   216,   220,
     224,    85,   117,    85,   196,   165,     1,    55,    91,   122,
     218,   224,    86,   222,    91,    91,   115,   118,    91,    85,
     117,    91,   209,   209,   115,   196,   209,   209,   209,   209,
      86,   125,    96,   139,    94,   167,     1,    85,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    95,
      62,    97,    61,    98,    99,   100,    72,    73,    30,    68,
      69,    70,    71,    65,    66,    67,   101,   102,    87,   103,
     104,    63,    64,    86,    86,    89,   125,   222,    89,    89,
      86,   117,   152,   153,    91,   131,   117,   152,     1,    95,
     125,   131,    85,    88,   131,   131,     1,    85,    95,    85,
      88,   196,    92,   196,   223,   125,    52,   125,    85,    85,
      85,    38,    44,   183,   184,   185,   139,   118,   196,   139,
     117,   196,    39,   122,   179,   193,   194,    89,   123,   124,
     125,   123,   125,   222,   196,    85,   196,    92,   125,    92,
      48,    86,   169,     1,    85,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   200,   196,   201,
     202,   203,   204,   205,   205,   121,   206,   206,   206,   206,
     207,   207,   207,   208,   208,   209,   209,   209,    51,    55,
     117,    17,    48,    51,    55,   117,   196,    86,   196,   196,
     117,    95,   125,   131,    85,    88,     1,    39,    92,   121,
     132,   133,     1,    27,   149,   131,     1,    85,    93,   134,
     136,   196,   136,     1,    95,    85,   117,   138,     1,    85,
     136,   140,    92,    88,    92,    91,    91,   165,   184,   185,
      85,    92,     1,    85,    92,   121,   139,    85,    88,   196,
     124,   125,   134,   125,   134,   145,   146,    92,    92,   209,
      92,   213,    48,    96,   222,   117,    86,   117,    90,    48,
      90,    90,   136,    95,   117,   153,    92,   121,   117,    88,
      92,   119,     1,   119,    85,   164,   165,     1,    27,   149,
       1,    94,   135,   136,   136,   136,   169,   196,   196,    39,
     118,   169,   139,    85,   196,   193,    90,    93,   165,   209,
     198,   222,   117,   222,   136,   117,   125,   133,   119,     1,
     164,    88,     1,    88,    94,    29,    92,   118,   117,   180,
     194,    85,    14,    33,   187,   188,   189,   190,   145,   145,
     125,   136,    94,   136,   169,    85,   117,    92,   125,    92,
     180,    96,   195,   196,    94,   189,   190,    14,    33,   166,
      92,   125,   165,    92,   169,    92,    96,    96,   195,   165,
      92,   165,   169,    96,   165
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 493 "java_grammar.y"
    {
	}
    break;

  case 3:
#line 495 "java_grammar.y"
    {
		ResetState();
	}
    break;

  case 4:
#line 499 "java_grammar.y"
    {
	}
    break;

  case 5:
#line 501 "java_grammar.y"
    {
		ResetState();
	}
    break;

  case 6:
#line 508 "java_grammar.y"
    { 
				int posn, len;
				posn = 0;
				while(posn < (yyvsp[(2) - (3)].string).len)
				{
					/* Extract the next identifier */
					if((yyvsp[(2) - (3)].string).string[posn] == '.')
					{
						++posn;
						continue;
					}
					len = 0;
					while((posn + len) < (yyvsp[(2) - (3)].string).len &&
	(yyvsp[(2) - (3)].string).string[posn + len] != '.')
					{
						++len;
					}

					/* Push a new identifier onto the end of the namespace */
					if(CurrPackage.len != 0)
					{
						CurrPackage = ILInternAppendedString
							(CurrPackage,
							 ILInternAppendedString
							 	(ILInternString(".", 1),
								 ILInternString((yyvsp[(2) - (3)].string).string + posn, len)));
					}
					else
					{
						CurrPackage = ILInternString((yyvsp[(2) - (3)].string).string + posn, len);
					}

					InitGlobalPackage();

					CurrPackageNode = (ILNode_JPackage*)ILNode_JPackage_create(
											CurrPackage.string);

					/* Declare the namespace within the global scope */
					ILScopeDeclareNamespace(GlobalScope(),
											CurrPackage.string);

					/* Move on to the next namespace component */
					posn += len;
				}
		/** NOTE: there is no enclosing packages idea here , so the
		Package is preserved till the ResetState()
		*/
	}
    break;

  case 7:
#line 556 "java_grammar.y"
    { 
		/* TODO */
	}
    break;

  case 8:
#line 559 "java_grammar.y"
    {
		/* TODO */
	}
    break;

  case 9:
#line 565 "java_grammar.y"
    {  (yyval.string) = ILInternString((yyvsp[(1) - (1)].name),strlen((yyvsp[(1) - (1)].name))); }
    break;

  case 10:
#line 566 "java_grammar.y"
    { 
				(yyval.string) = ILInternAppendedString
					((yyvsp[(1) - (3)].string), ILInternAppendedString
					 		(ILInternString(".", 1),
							 ILInternString((yyvsp[(3) - (3)].name), strlen((yyvsp[(3) - (3)].name)))));
	}
    break;

  case 11:
#line 575 "java_grammar.y"
    {}
    break;

  case 13:
#line 580 "java_grammar.y"
    {
	/* TODO: import only type , not the package 
		ILScope *globalScope = GlobalScope();
		ILNode_JImportType *import;
		ILIntString str= ILInternAppendedString
					($2, ILInternAppendedString
					 		(ILInternString(".", 1),
							 ILInternString($4, strlen($4))));
		if(!ILScopeUsing(globalScope, $2.string))
		{
			CCError("`%s' is not a pacakge", $2.string);
		}
		InitGlobalPackage();
		if(!HaveImported($2.string))
		{
			import = (ILNode_JImportType *)
				ILNode_JImportType_create(str.string);
			import->next = CurrPackageNode->import;
			CurrPackageNode->import = (ILNode*)import;
		}*/
		ILScope *globalScope = GlobalScope();
		ILNode_JImportPackage *import;
		if(!ILScopeUsing(globalScope, (yyvsp[(2) - (5)].string).string))
		{
			CCError("`%s' is not a pacakge", (yyvsp[(2) - (5)].string).string);
		}
		InitGlobalPackage();
		if(!HaveImported((yyvsp[(2) - (5)].string).string))
		{
			import = (ILNode_JImportPackage *)
				ILNode_JImportPackage_create((yyvsp[(2) - (5)].string).string);
			import->next = CurrPackageNode->import;
			CurrPackageNode->import = (ILNode*)import;
		}
	}
    break;

  case 14:
#line 615 "java_grammar.y"
    { 
		ILScope *globalScope = GlobalScope();
		ILNode_JImportPackage *import;
		if(!ILScopeUsing(globalScope, (yyvsp[(2) - (5)].string).string))
		{
			CCError("`%s' is not a pacakge", (yyvsp[(2) - (5)].string).string);
		}
		InitGlobalPackage();
		if(!HaveImported((yyvsp[(2) - (5)].string).string))
		{
			import = (ILNode_JImportPackage *)
				ILNode_JImportPackage_create((yyvsp[(2) - (5)].string).string);
			import->next = CurrPackageNode->import;
			CurrPackageNode->import = (ILNode*)import;
		}
	}
    break;

  case 15:
#line 631 "java_grammar.y"
    {
	}
    break;

  case 16:
#line 633 "java_grammar.y"
    {
	}
    break;

  case 17:
#line 635 "java_grammar.y"
    {
	}
    break;

  case 18:
#line 641 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_U1); }
    break;

  case 19:
#line 642 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_I2); }
    break;

  case 20:
#line 643 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_CHAR); }
    break;

  case 21:
#line 644 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_I4); }
    break;

  case 22:
#line 645 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_I8); }
    break;

  case 23:
#line 646 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_R4); }
    break;

  case 24:
#line 647 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_R8); }
    break;

  case 25:
#line 648 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_BOOLEAN); }
    break;

  case 26:
#line 649 "java_grammar.y"
    { MakeUnary(JPrimitiveType, IL_META_ELEMTYPE_VOID); }
    break;

  case 27:
#line 653 "java_grammar.y"
    {
			switch((yyvsp[(1) - (1)].integer).type)
			{
				case JAVA_NUMTYPE_INT32:
				{
					(yyval.node) = ILNode_Int32_create((yyvsp[(1) - (1)].integer).value, 0, (yyvsp[(1) - (1)].integer).canneg);
				}
				break;
				case JAVA_NUMTYPE_INT64:
				{
					(yyval.node) = ILNode_Int64_create((yyvsp[(1) - (1)].integer).value, 0, (yyvsp[(1) - (1)].integer).canneg);
				}
				break;
				default:
				{
					(yyval.node) = ILNode_Int64_create((yyvsp[(1) - (1)].integer).value, 0, (yyvsp[(1) - (1)].integer).canneg);
				}
				break;
			}
	}
    break;

  case 28:
#line 673 "java_grammar.y"
    { 
				if((yyvsp[(1) - (1)].real).type == JAVA_NUMTYPE_FLOAT32)
				{
					(yyval.node) = ILNode_Float32_create((yyvsp[(1) - (1)].real).value);
				}
				else
				{
					(yyval.node) = ILNode_Float64_create((yyvsp[(1) - (1)].real).value);
				}
	}
    break;

  case 29:
#line 683 "java_grammar.y"
    { (yyval.node) = ILNode_Char_create((ILUInt64)((yyvsp[(1) - (1)].charValue)), 0, 1); }
    break;

  case 30:
#line 684 "java_grammar.y"
    { (yyval.node) = ILNode_String_create((yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).len); }
    break;

  case 31:
#line 685 "java_grammar.y"
    { MakeSimple(Null); }
    break;

  case 32:
#line 686 "java_grammar.y"
    { MakeSimple(False); }
    break;

  case 33:
#line 687 "java_grammar.y"
    { MakeSimple(True); }
    break;

  case 34:
#line 691 "java_grammar.y"
    { 
	(yyval.node) = ILQualIdentSimple(ILInternString((yyvsp[(1) - (1)].name), strlen((yyvsp[(1) - (1)].name))).string);
	}
    break;

  case 35:
#line 697 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:
#line 698 "java_grammar.y"
    { MakeBinary(QualIdent, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 37:
#line 702 "java_grammar.y"
    { 
		(yyval.node) = ILNode_List_create();
		ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node)); 
	}
    break;

  case 38:
#line 706 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (3)].node);
		ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
	}
    break;

  case 39:
#line 713 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:
#line 714 "java_grammar.y"
    { MakeBinary(ArgList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 41:
#line 718 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
	}
    break;

  case 42:
#line 721 "java_grammar.y"
    { 
		int i;
		ILNode *type=(yyvsp[(1) - (2)].node);
		for(i=0;i<(yyvsp[(2) - (2)].count);i++)
		{
			type=ILNode_JArrayType_create(type,1);
		}
		(yyval.node) = type;
	}
    break;

  case 43:
#line 730 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
	}
    break;

  case 44:
#line 733 "java_grammar.y"
    {
		int i;
		ILNode *type=(yyvsp[(1) - (2)].node);
		for(i=0;i<(yyvsp[(2) - (2)].count);i++)
		{
			type=ILNode_JArrayType_create(type,1);
		}
		(yyval.node) = type;
	}
    break;

  case 45:
#line 745 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
	}
    break;

  case 46:
#line 748 "java_grammar.y"
    { 
		int i;
		ILNode *type=(yyvsp[(1) - (2)].node);
		for(i=0;i<(yyvsp[(2) - (2)].count);i++)
		{
			type=ILNode_JArrayType_create(type,1);
		}
		(yyval.node) = type;
	}
    break;

  case 47:
#line 758 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
	}
    break;

  case 48:
#line 762 "java_grammar.y"
    {
		int i;
		ILNode *type=(yyvsp[(1) - (2)].node);
		for(i=0;i<(yyvsp[(2) - (2)].count);i++)
		{
			type=ILNode_JArrayType_create(type,1);
		}
		(yyval.node) = type;
	}
    break;

  case 49:
#line 774 "java_grammar.y"
    { 
		(yyval.node) = (yyvsp[(1) - (1)].node);
	}
    break;

  case 50:
#line 777 "java_grammar.y"
    { 
		MakeBinary(ArgList,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 51:
#line 783 "java_grammar.y"
    { (yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 52:
#line 787 "java_grammar.y"
    { (yyval.count) = 1; }
    break;

  case 53:
#line 788 "java_grammar.y"
    { (yyval.count) = (yyval.count) + 1; }
    break;

  case 54:
#line 792 "java_grammar.y"
    { (yyval.mask) = 0; }
    break;

  case 55:
#line 793 "java_grammar.y"
    { (yyval.mask) = (yyvsp[(1) - (1)].mask); }
    break;

  case 56:
#line 797 "java_grammar.y"
    { (yyval.mask) = (yyvsp[(1) - (1)].mask); }
    break;

  case 57:
#line 798 "java_grammar.y"
    { 
		if((yyvsp[(1) - (2)].mask) & (yyvsp[(2) - (2)].mask))
		{
			CCWarning("repeated modifier");
		}
		(yyval.mask) = (yyvsp[(1) - (2)].mask) | (yyvsp[(2) - (2)].mask);
	}
    break;

  case 58:
#line 808 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_PROTECTED; }
    break;

  case 59:
#line 809 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_PUBLIC; }
    break;

  case 60:
#line 810 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_PRIVATE; }
    break;

  case 61:
#line 811 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_STATIC; }
    break;

  case 62:
#line 812 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_ABSTRACT; }
    break;

  case 63:
#line 813 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_FINAL; }
    break;

  case 64:
#line 814 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_NATIVE; }
    break;

  case 65:
#line 815 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_SYNCHRONIZED; }
    break;

  case 66:
#line 816 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_TRANSIENT; }
    break;

  case 67:
#line 817 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_VOLATILE; }
    break;

  case 68:
#line 818 "java_grammar.y"
    { (yyval.mask) = JAVA_MODIFIER_STRICTFP; }
    break;

  case 69:
#line 822 "java_grammar.y"
    { 
		/* Note: I'm calling it here because this production will
		be used only once for a set of TypeDeclarations , sort of
		designed optimisation */
		ImportJavaLang(); 
	}
    break;

  case 71:
#line 832 "java_grammar.y"
    { CCPluginAddTopLevel((yyvsp[(1) - (1)].node));}
    break;

  case 73:
#line 837 "java_grammar.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 74:
#line 838 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 75:
#line 839 "java_grammar.y"
    {
		CCError("bad formal parameters");
	}
    break;

  case 76:
#line 845 "java_grammar.y"
    {
		(yyval.node) = ILNode_List_create();
		ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
	}
    break;

  case 77:
#line 849 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (3)].node);
		ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
	}
    break;

  case 78:
#line 856 "java_grammar.y"
    {
		/* TODO */
	}
    break;

  case 79:
#line 859 "java_grammar.y"
    {
		MakeQuaternary(FormalParameter,NULL, ILParamMod_empty, (yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 80:
#line 862 "java_grammar.y"
    {
		/* TODO */
	}
    break;

  case 81:
#line 865 "java_grammar.y"
    { 
		int i;
		ILNode *type=(yyvsp[(1) - (3)].node);
		for(i=0;i<(yyvsp[(3) - (3)].count);i++)
		{
			type=ILNode_JArrayType_create(type,1);
		}
		MakeQuaternary(FormalParameter,NULL,ILParamMod_empty, 
						type,(yyvsp[(2) - (3)].node));
	}
    break;

  case 82:
#line 878 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 83:
#line 879 "java_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 84:
#line 880 "java_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (4)].node); }
    break;

  case 85:
#line 881 "java_grammar.y"
    {
		CCError("missing '}' in array initializer");
	}
    break;

  case 86:
#line 888 "java_grammar.y"
    {
		(yyval.node) = ILNode_List_create();	  
		ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
	}
    break;

  case 87:
#line 892 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (3)].node);	  
		ILNode_List_Add((yyval.node), (yyvsp[(3) - (3)].node));
	}
    break;

  case 88:
#line 896 "java_grammar.y"
    {
		CCError("invalid variable initializer");
	}
    break;

  case 90:
#line 903 "java_grammar.y"
    { MakeUnary(ArrayInit,(yyvsp[(1) - (1)].node)); }
    break;

  case 91:
#line 907 "java_grammar.y"
    {
		(yyval.node) = ILNode_List_create();
		ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
	}
    break;

  case 92:
#line 911 "java_grammar.y"
    {
		ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		(yyval.node) = (yyvsp[(1) - (3)].node);
	}
    break;

  case 93:
#line 918 "java_grammar.y"
    {
	}
    break;

  case 94:
#line 920 "java_grammar.y"
    {
		MakeBinary(FieldDeclarator, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));	
	}
    break;

  case 95:
#line 923 "java_grammar.y"
    {
		CCError("missing '=' in constant declarator");
	}
    break;

  case 96:
#line 926 "java_grammar.y"
    {
		CCError("missing '=' in constant declarator");
	}
    break;

  case 97:
#line 932 "java_grammar.y"
    {
		(yyval.varInit).decl = ILNode_List_create();
		ILNode_List_Add((yyval.varInit).decl, (yyvsp[(1) - (1)].varInit).decl);
		(yyval.varInit).init = (yyvsp[(1) - (1)].varInit).init;
	}
    break;

  case 98:
#line 937 "java_grammar.y"
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

  case 99:
#line 963 "java_grammar.y"
    {
		(yyval.varInit).decl = (yyvsp[(1) - (1)].node);
		(yyval.varInit).init = NULL;
	}
    break;

  case 100:
#line 967 "java_grammar.y"
    {
		(yyval.varInit).decl = (yyvsp[(1) - (3)].node);
		(yyval.varInit).init = ILNode_Assign_create((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 103:
#line 979 "java_grammar.y"
    {
		++NestingLevel;
		ClassNamePush((yyvsp[(3) - (4)].node));
	}
    break;

  case 104:
#line 982 "java_grammar.y"
    {
		int currentModifiers = 0;
		ILNode *classBody = ((yyvsp[(6) - (6)].member)).body;
		NestingLevel--;
		currentModifiers = JavaModifiersToTypeAttrs((yyvsp[(3) - (6)].node), (yyvsp[(1) - (6)].mask), NestingLevel);
		InitGlobalPackage();
		if(!ClassNameIsCtorDefined())
		{
			ILUInt32 ctorMods =
				(((currentModifiers & IL_META_TYPEDEF_ABSTRACT) != 0)
					? JAVA_MODIFIER_PROTECTED : JAVA_MODIFIER_PUBLIC);
			ILNode *cname = ILQualIdentSimple
							(ILInternString(".ctor", 5).string);
			ILNode *body = ILNode_NewScope_create
							(ILNode_Compound_CreateFrom
								(ILNode_NonStaticInit_create(),
								 ILNode_InvocationExpression_create
									(ILNode_BaseInit_create(), 0)));
			ILNode *ctor = ILNode_MethodDeclaration_create
						  (0, JavaModifiersToConstructorAttrs(cname, ctorMods),
						   0 /* "void" */, cname,
						   ILNode_Empty_create(), body);
			if(!classBody)
			{
				classBody = ILNode_List_create();
			}
			ILNode_List_Add(classBody, ctor);
		}
	
		(yyval.node) = ILNode_ClassDefn_create(NULL,	    /* attributes */
				currentModifiers,	            /* modifiers */
				ILQualIdentName((yyvsp[(3) - (6)].node), 0),         /* class name */
				CurrPackage.string,   			/* scope name */
				(ILNode*)CurrPackageNode,      	/* namespace node */
				NULL,							/* (generics) */
				(yyvsp[(4) - (6)].node),		                      	/* super class */
				classBody,	                   	/* class body */
				(yyvsp[(6) - (6)].member).staticCtors);				/* static ctors */

		ClassNamePop();

		HaveDecls = 1;
	}
    break;

  case 105:
#line 1029 "java_grammar.y"
    {
		(yyval.node) = 0;
	}
    break;

  case 106:
#line 1032 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(2) - (2)].node);
	}
    break;

  case 107:
#line 1035 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(2) - (2)].node);
	}
    break;

  case 108:
#line 1038 "java_grammar.y"
    {
		MakeBinary(ArgList,(yyvsp[(4) - (4)].node), (yyvsp[(2) - (4)].node));
	}
    break;

  case 109:
#line 1044 "java_grammar.y"
    { (yyval.member).body = NULL; (yyval.member).staticCtors = NULL;}
    break;

  case 110:
#line 1045 "java_grammar.y"
    { (yyval.member) = (yyvsp[(1) - (1)].member); }
    break;

  case 111:
#line 1049 "java_grammar.y"
    { (yyval.member) = (yyvsp[(2) - (3)].member); }
    break;

  case 112:
#line 1050 "java_grammar.y"
    { (yyval.member).body = NULL; (yyval.member).staticCtors = NULL; }
    break;

  case 113:
#line 1054 "java_grammar.y"
    {
		(yyval.member).body = MakeList(0,(yyvsp[(1) - (1)].member).body);
		(yyval.member).staticCtors = MakeList(0,(yyvsp[(1) - (1)].member).staticCtors);
	}
    break;

  case 114:
#line 1058 "java_grammar.y"
    {
		(yyval.member).body = MakeList((yyvsp[(1) - (2)].member).body, (yyvsp[(2) - (2)].member).body);
		(yyval.member).staticCtors = MakeList((yyvsp[(1) - (2)].member).staticCtors, (yyvsp[(2) - (2)].member).staticCtors);
	}
    break;

  case 115:
#line 1065 "java_grammar.y"
    { (yyval.member).body = NULL; (yyval.member).staticCtors=NULL;}
    break;

  case 116:
#line 1066 "java_grammar.y"
    { (yyval.member).body = NULL; (yyval.member).staticCtors = NULL;}
    break;

  case 117:
#line 1067 "java_grammar.y"
    { }
    break;

  case 118:
#line 1068 "java_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors=NULL;}
    break;

  case 119:
#line 1069 "java_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors=NULL;}
    break;

  case 120:
#line 1070 "java_grammar.y"
    { (yyval.member).body=(yyvsp[(1) - (1)].node); (yyval.member).staticCtors=NULL; }
    break;

  case 121:
#line 1071 "java_grammar.y"
    { (yyval.member).body = (yyvsp[(1) - (1)].node); (yyval.member).staticCtors=0; }
    break;

  case 122:
#line 1075 "java_grammar.y"
    {(yyval.node) = NULL;}
    break;

  case 123:
#line 1076 "java_grammar.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 125:
#line 1087 "java_grammar.y"
    {
		ILUInt32 attrs = JavaModifiersToFieldAttrs((yyvsp[(2) - (4)].node), (yyvsp[(1) - (4)].mask));
		(yyval.node) = ILNode_FieldDeclaration_create(NULL, attrs, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node));
	}
    break;

  case 126:
#line 1091 "java_grammar.y"
    {
		CCError("invalid variable type");
	}
    break;

  case 127:
#line 1094 "java_grammar.y"
    {
		CCError("missing ';' after variable declarations");
	}
    break;

  case 128:
#line 1100 "java_grammar.y"
    {
				(yyval.node) = ILNode_List_create();
				ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
			}
    break;

  case 129:
#line 1104 "java_grammar.y"
    {
				ILNode_List_Add((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
				(yyval.node) = (yyvsp[(1) - (3)].node);
			}
    break;

  case 130:
#line 1112 "java_grammar.y"
    {
				MakeBinary(FieldDeclarator, (yyvsp[(1) - (1)].node), 0);
			}
    break;

  case 131:
#line 1115 "java_grammar.y"
    {
				MakeBinary(FieldDeclarator, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
    break;

  case 132:
#line 1119 "java_grammar.y"
    {
				MakeBinary(FieldDeclarator, 
					ILNode_TypeSuffixDeclarator_create((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].count)), 0);
			}
    break;

  case 133:
#line 1123 "java_grammar.y"
    {
				MakeBinary(FieldDeclarator, 
					ILNode_TypeSuffixDeclarator_create((yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].count)), (yyvsp[(4) - (4)].node));
			}
    break;

  case 134:
#line 1130 "java_grammar.y"
    {
		
		ILNode *cname;
		ILUInt32 attrs;
		cname =  ILQualIdentSimple( ILInternString(".ctor",5).string);
		ClassNameCtorDefined();
		if(!ClassNameSame((yyvsp[(2) - (5)].node)))
		{
				CCErrorOnLine(yygetfilename((yyvsp[(2) - (5)].node)), yygetlinenum((yyvsp[(2) - (5)].node)),
					"constructor name does not match class name");
		}
		attrs=JavaModifiersToConstructorAttrs((yyvsp[(2) - (5)].node),(yyvsp[(1) - (5)].mask));
		(yyval.node) = ILNode_MethodDeclaration_create (0,	/* attributes */
											attrs,		/* modifiers */
											0, 			/* "void" */
											cname,  	/* name */
											(yyvsp[(3) - (5)].node), 		/* params */
											(yyvsp[(5) - (5)].node));		/* body */
		CloneLine((yyval.node), (yyvsp[(2) - (5)].node));
	}
    break;

  case 135:
#line 1151 "java_grammar.y"
    {
		CCError("missing 'throws'");
		yyerrok;
	}
    break;

  case 136:
#line 1155 "java_grammar.y"
    {
		CCError("bad exception names");
		yyerrok;
	}
    break;

  case 137:
#line 1162 "java_grammar.y"
    { 
		ILNode *cname;
		ILUInt32 attrs;
		cname =  (yyvsp[(3) - (6)].node);
		attrs=JavaModifiersToMethodAttrs((yyvsp[(3) - (6)].node),(yyvsp[(1) - (6)].mask));
		(yyval.node) = ILNode_MethodDeclaration_create (0,	/* attributes */
											attrs,		/* modifiers */
											(yyvsp[(2) - (6)].node),			/* retval */
											cname,  	/* name */
											(yyvsp[(4) - (6)].node), 		/* params */
											(yyvsp[(6) - (6)].node));		/* body */
		CloneLine((yyval.node), (yyvsp[(2) - (6)].node));
	}
    break;

  case 138:
#line 1175 "java_grammar.y"
    {
		CCError("invalid return type");
		yyerrok;
	}
    break;

  case 139:
#line 1179 "java_grammar.y"
    {
		CCError("missing 'throws'");
		yyerrok;
	}
    break;

  case 140:
#line 1183 "java_grammar.y"
    {
		CCError("bad exception names");
		yyerrok;
	}
    break;

  case 141:
#line 1191 "java_grammar.y"
    {
		NestingLevel++;
		/* Push the identifier onto the class name stack */
		ClassNamePush((yyvsp[(4) - (4)].node));
	}
    break;

  case 142:
#line 1195 "java_grammar.y"
    {
		/* Validate the modifiers */
		ILUInt32 attrs =
			JavaModifiersToTypeAttrs((yyvsp[(3) - (6)].node), (yyvsp[(1) - (6)].mask), (NestingLevel > 1));

		/* Add extra attributes that interfaces need */
		attrs |= IL_META_TYPEDEF_INTERFACE |
				 IL_META_TYPEDEF_ABSTRACT;
		InitGlobalPackage();
		(yyval.node) = ILNode_ClassDefn_create
					(NULL,					/* Attributes */
					 attrs,					/* OptModifiers */
					 ILQualIdentName((yyvsp[(3) - (6)].node), 0),/* Identifier */
					 CurrPackage.string,	/* Namespace */
					 (ILNode *)CurrPackageNode,
					 NULL,					/* TypeFormals */
					 (yyvsp[(4) - (6)].node),					/* ClassBase */
					 (yyvsp[(6) - (6)].node),					/* InterfaceBody */
					 0);					/* StaticCtors */
		CloneLine((yyval.node), (yyvsp[(3) - (6)].node));

		/* Pop the class name stack */
		ClassNamePop();


		/* Exit from the current nesting level */
		--NestingLevel;
	}
    break;

  case 143:
#line 1226 "java_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 144:
#line 1227 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 145:
#line 1228 "java_grammar.y"
    {
		CCError("missing 'extends'");
	}
    break;

  case 146:
#line 1234 "java_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 147:
#line 1235 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 148:
#line 1239 "java_grammar.y"
    {
		(yyval.node) = ILNode_List_create();
		ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
	}
    break;

  case 149:
#line 1243 "java_grammar.y"
    {
		ILNode_List_Add((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
	}
    break;

  case 150:
#line 1249 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 154:
#line 1256 "java_grammar.y"
    {
		ILUInt32 attrs = JavaModifiersToFieldAttrs((yyvsp[(2) - (4)].node), (yyvsp[(1) - (4)].mask));
		(yyval.node) = ILNode_FieldDeclaration_create(NULL, attrs, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node));
	}
    break;

  case 155:
#line 1260 "java_grammar.y"
    {
		CCError("invalid variable type");
	}
    break;

  case 156:
#line 1263 "java_grammar.y"
    {
		CCError("missing ';' after variable declarations");
	}
    break;

  case 157:
#line 1269 "java_grammar.y"
    {
		ILUInt32 attrs =JavaModifiersToMethodAttrs((yyvsp[(3) - (5)].node),(yyvsp[(1) - (5)].mask));
		attrs = attrs | IL_META_METHODDEF_ABSTRACT;
		(yyval.node) = ILNode_MethodDeclaration_create
					(NULL, attrs, (yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node), 0);
		CloneLine((yyval.node), (yyvsp[(3) - (5)].node));
	}
    break;

  case 158:
#line 1276 "java_grammar.y"
    {
		CCError("invalid return type");
	}
    break;

  case 159:
#line 1279 "java_grammar.y"
    {
		CCError("invalid function name");
	}
    break;

  case 160:
#line 1282 "java_grammar.y"
    {
		CCError("missing ';' after function declaration");
	}
    break;

  case 162:
#line 1289 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 163:
#line 1293 "java_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 164:
#line 1294 "java_grammar.y"
    { 
		(yyval.node) = ILNode_NewScope_create((yyvsp[(2) - (3)].node));
		yysetfilename((yyval.node), yygetfilename((yyvsp[(2) - (3)].node)));
		yysetlinenum((yyval.node), yygetlinenum((yyvsp[(2) - (3)].node)));
	}
    break;

  case 165:
#line 1302 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 166:
#line 1303 "java_grammar.y"
    { 
		(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); 
	}
    break;

  case 170:
#line 1315 "java_grammar.y"
    { /* TODO */ }
    break;

  case 171:
#line 1316 "java_grammar.y"
    {
		/* "VariableDeclarators" has split the declaration into
		   a list of variable names, plus a list of assignment
		   statements to set the initial values.  Turn the result
		   into a local variable declaration followed by the
		   assignment statements */
		if((yyvsp[(2) - (3)].varInit).init)
		{
			(yyval.node) = ILNode_Compound_CreateFrom
					(ILNode_LocalVarDeclaration_create((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].varInit).decl),
					 (yyvsp[(2) - (3)].varInit).init);
		}
		else
		{
			(yyval.node) = ILNode_LocalVarDeclaration_create((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].varInit).decl);
		}
	}
    break;

  case 172:
#line 1335 "java_grammar.y"
    {
		CCError("missing ';' after local variable declaration");
	}
    break;

  case 173:
#line 1338 "java_grammar.y"
    {
	CCError("missing ';' after local variable declaration");
	}
    break;

  case 174:
#line 1341 "java_grammar.y"
    {
		CCError("invalid type in local variable declaration");
	}
    break;

  case 175:
#line 1344 "java_grammar.y"
    {
		CCError("invalid type in local variable declaration");
	}
    break;

  case 191:
#line 1369 "java_grammar.y"
    { 
	(yyval.node) = ILNode_Compound_CreateFrom(ILNode_GotoLabel_create(ILQualIdentName((yyvsp[(1) - (3)].node), 0)),(yyvsp[(3) - (3)].node));
	}
    break;

  case 192:
#line 1375 "java_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 193:
#line 1379 "java_grammar.y"
    { MakeSimple(Break); }
    break;

  case 194:
#line 1380 "java_grammar.y"
    { /* TODO */}
    break;

  case 195:
#line 1384 "java_grammar.y"
    { MakeSimple(Continue); }
    break;

  case 196:
#line 1385 "java_grammar.y"
    { /* TODO */}
    break;

  case 197:
#line 1389 "java_grammar.y"
    { MakeSimple(Return); }
    break;

  case 198:
#line 1390 "java_grammar.y"
    { MakeUnary(ReturnExpr, (yyvsp[(2) - (3)].node)); }
    break;

  case 199:
#line 1394 "java_grammar.y"
    { MakeUnary(ThrowExpr, (yyvsp[(2) - (3)].node)); }
    break;

  case 200:
#line 1398 "java_grammar.y"
    { 
		MakeTernary(If, ILNode_ToBool_create((yyvsp[(3) - (5)].node)), (yyvsp[(5) - (5)].node), ILNode_Empty_create()); 
	}
    break;

  case 201:
#line 1401 "java_grammar.y"
    { 
		MakeTernary(If, ILNode_ToBool_create((yyvsp[(3) - (7)].node)), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); 
	}
    break;

  case 202:
#line 1407 "java_grammar.y"
    { 
		MakeBinary(While, ILNode_ToBool_create((yyvsp[(3) - (5)].node)), (yyvsp[(5) - (5)].node)); 
	}
    break;

  case 203:
#line 1413 "java_grammar.y"
    {
		MakeQuaternary(For, (yyvsp[(3) - (9)].node), ILNode_ToBool_create((yyvsp[(5) - (9)].node)), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node));
		(yyval.node)=ILNode_NewScope_create((yyval.node));
	}
    break;

  case 204:
#line 1417 "java_grammar.y"
    {
		MakeQuaternary(For, (yyvsp[(3) - (8)].node), ILNode_ToBool_create(ILNode_True_create()), 
						(yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
		(yyval.node)=ILNode_NewScope_create((yyval.node));
	}
    break;

  case 205:
#line 1425 "java_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 206:
#line 1426 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 207:
#line 1427 "java_grammar.y"
    { /* TODO */ }
    break;

  case 208:
#line 1428 "java_grammar.y"
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

  case 209:
#line 1448 "java_grammar.y"
    { MakeSimple(Empty); }
    break;

  case 210:
#line 1449 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 211:
#line 1453 "java_grammar.y"
    { 
			MakeBinary(Do, (yyvsp[(2) - (7)].node), ILNode_ToBool_create((yyvsp[(5) - (7)].node))); 
	}
    break;

  case 212:
#line 1459 "java_grammar.y"
    { MakeTernary(Try, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL); }
    break;

  case 213:
#line 1460 "java_grammar.y"
    { MakeTernary(Try, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 214:
#line 1461 "java_grammar.y"
    { MakeTernary(Try, (yyvsp[(2) - (3)].node), NULL, (yyvsp[(3) - (3)].node)); }
    break;

  case 215:
#line 1465 "java_grammar.y"
    {
		(yyval.node) = ILNode_CatchClauses_create();
		ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
	}
    break;

  case 216:
#line 1469 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		ILNode_List_Add((yyval.node), (yyvsp[(2) - (2)].node));
	}
    break;

  case 217:
#line 1476 "java_grammar.y"
    {}
    break;

  case 218:
#line 1477 "java_grammar.y"
    {}
    break;

  case 219:
#line 1478 "java_grammar.y"
    {}
    break;

  case 220:
#line 1479 "java_grammar.y"
    {	
		MakeQuaternary(CatchClause ,(yyvsp[(3) - (6)].node),ILQualIdentName((yyvsp[(4) - (6)].node),0),(yyvsp[(4) - (6)].node),(yyvsp[(6) - (6)].node));
	}
    break;

  case 221:
#line 1485 "java_grammar.y"
    { MakeUnary(FinallyClause, (yyvsp[(2) - (2)].node)); }
    break;

  case 222:
#line 1489 "java_grammar.y"
    { 
				MakeTernary(Switch, (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node), 0);
	}
    break;

  case 223:
#line 1495 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 224:
#line 1496 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 225:
#line 1497 "java_grammar.y"
    { /* fixme */ }
    break;

  case 226:
#line 1498 "java_grammar.y"
    { /* fixme */ }
    break;

  case 227:
#line 1502 "java_grammar.y"
    {
		(yyval.node) = ILNode_SwitchSectList_create();	  
		ILNode_List_Add((yyval.node), (yyvsp[(1) - (1)].node));
	}
    break;

  case 228:
#line 1506 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		ILNode_List_Add((yyval.node), (yyvsp[(2) - (2)].node));
	}
    break;

  case 229:
#line 1513 "java_grammar.y"
    { MakeBinary(SwitchSection, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 230:
#line 1517 "java_grammar.y"
    {
		(yyval.node) = ILNode_CaseList_create();
		ILNode_List_Add((yyval.node), ILNode_CaseLabel_create((yyvsp[(2) - (3)].node)));
	}
    break;

  case 231:
#line 1521 "java_grammar.y"
    {
		(yyval.node) = ILNode_CaseList_create();
		ILNode_List_Add((yyval.node), ILNode_DefaultLabel_create());
	}
    break;

  case 232:
#line 1525 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (4)].node);
		ILNode_List_Add((yyval.node), ILNode_CaseLabel_create((yyvsp[(3) - (4)].node)));
	}
    break;

  case 233:
#line 1529 "java_grammar.y"
    {
		(yyval.node) = (yyvsp[(1) - (3)].node);
		ILNode_List_Add((yyval.node), ILNode_DefaultLabel_create());
	}
    break;

  case 234:
#line 1536 "java_grammar.y"
    { /* TODO */ }
    break;

  case 235:
#line 1540 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 236:
#line 1541 "java_grammar.y"
    {
		CCError("missing ';' after statement");
		yyerrok;
	}
    break;

  case 244:
#line 1558 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 245:
#line 1559 "java_grammar.y"
    { 
		(yyval.node) = ILNode_Compound_CreateFrom((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 249:
#line 1573 "java_grammar.y"
    {MakeBinary(Assign, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 250:
#line 1574 "java_grammar.y"
    { 
		MakeUnary(AssignAdd, ILNode_Add_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 251:
#line 1577 "java_grammar.y"
    { 
		MakeUnary(AssignSub, ILNode_Sub_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 252:
#line 1580 "java_grammar.y"
    { 
		MakeUnary(AssignMul, ILNode_Mul_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 253:
#line 1583 "java_grammar.y"
    { 
		MakeUnary(AssignDiv, ILNode_Div_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 254:
#line 1586 "java_grammar.y"
    { 
		MakeUnary(AssignAnd, ILNode_And_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 255:
#line 1589 "java_grammar.y"
    { 
		MakeUnary(AssignOr,   ILNode_Or_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 256:
#line 1592 "java_grammar.y"
    { 
		MakeUnary(AssignXor, ILNode_Xor_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 257:
#line 1595 "java_grammar.y"
    { 
		MakeUnary(AssignRem, ILNode_Rem_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 258:
#line 1598 "java_grammar.y"
    { 
		MakeUnary(AssignShr, ILNode_Shr_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 259:
#line 1601 "java_grammar.y"
    { 
		MakeUnary(AssignShl, ILNode_Shl_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); 
	}
    break;

  case 260:
#line 1604 "java_grammar.y"
    { 
		MakeUnary(AssignUShr, ILNode_UShr_create((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));
		
	}
    break;

  case 262:
#line 1612 "java_grammar.y"
    { MakeTernary(Conditional, ILNode_ToBool_create((yyvsp[(1) - (5)].node)), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); }
    break;

  case 264:
#line 1617 "java_grammar.y"
    { MakeBinary(LogicalOr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 266:
#line 1622 "java_grammar.y"
    { 
		MakeBinary(LogicalAnd, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	}
    break;

  case 268:
#line 1629 "java_grammar.y"
    { 
		MakeBinary(Or, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	}
    break;

  case 270:
#line 1636 "java_grammar.y"
    { MakeBinary(Xor, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 272:
#line 1641 "java_grammar.y"
    { MakeBinary(And, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 274:
#line 1646 "java_grammar.y"
    { MakeBinary(Eq, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 275:
#line 1647 "java_grammar.y"
    { MakeBinary(Ne, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 277:
#line 1652 "java_grammar.y"
    { MakeBinary(Lt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 278:
#line 1653 "java_grammar.y"
    { MakeBinary(Gt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 279:
#line 1654 "java_grammar.y"
    { MakeBinary(Le, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 280:
#line 1655 "java_grammar.y"
    { MakeBinary(Ge, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 281:
#line 1656 "java_grammar.y"
    { MakeBinary(InstanceOf,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 283:
#line 1661 "java_grammar.y"
    { MakeBinary(Shl, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 284:
#line 1662 "java_grammar.y"
    { MakeBinary(Shr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 285:
#line 1663 "java_grammar.y"
    { MakeBinary(UShr,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 287:
#line 1668 "java_grammar.y"
    { 
		MakeBinary(Add, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	}
    break;

  case 288:
#line 1671 "java_grammar.y"
    { 
		MakeBinary(Sub, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	}
    break;

  case 290:
#line 1678 "java_grammar.y"
    { 
		MakeBinary(Mul, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	}
    break;

  case 291:
#line 1681 "java_grammar.y"
    { 
		MakeBinary(Div, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	}
    break;

  case 292:
#line 1684 "java_grammar.y"
    { 
		MakeBinary(Rem, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	}
    break;

  case 295:
#line 1692 "java_grammar.y"
    { 
		MakeUnary(UnaryPlus, (yyvsp[(2) - (2)].node)); 
	}
    break;

  case 296:
#line 1695 "java_grammar.y"
    { 
		if(yyisa((yyvsp[(2) - (2)].node), ILNode_Integer))
		{
			(yyval.node) = NegateInteger((ILNode_Integer *)(yyvsp[(2) - (2)].node));
		} 
		else if(yyisa((yyvsp[(2) - (2)].node), ILNode_Real)) 
		{
			((ILNode_Real *)((yyvsp[(2) - (2)].node)))->value = -(((ILNode_Real *)((yyvsp[(2) - (2)].node)))->value);
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

  case 298:
#line 1720 "java_grammar.y"
    { 
		MakeUnary(PreInc, (yyvsp[(2) - (2)].node)); 
	}
    break;

  case 299:
#line 1726 "java_grammar.y"
    { 
		MakeUnary(PreDec, (yyvsp[(2) - (2)].node)); 
	}
    break;

  case 301:
#line 1733 "java_grammar.y"
    { 
				MakeBinary(UserCast, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
	}
    break;

  case 302:
#line 1736 "java_grammar.y"
    { 
		ILNode *type=(yyvsp[(2) - (5)].node);
		int i;
		
		for(i=0;i<(yyvsp[(3) - (5)].count);i++)
		{
			type = ILNode_JArrayType_create(type,1);
		}
		
		MakeBinary(UserCast,type, (yyvsp[(5) - (5)].node));
	}
    break;

  case 303:
#line 1747 "java_grammar.y"
    { 
				MakeBinary(UserCast, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
	}
    break;

  case 305:
#line 1754 "java_grammar.y"
    { MakeUnary(Not, (yyvsp[(2) - (2)].node)); }
    break;

  case 306:
#line 1755 "java_grammar.y"
    { MakeUnary(LogicalNot, (yyvsp[(2) - (2)].node)); }
    break;

  case 310:
#line 1766 "java_grammar.y"
    { MakeUnary(PostInc, (yyvsp[(1) - (2)].node)); }
    break;

  case 311:
#line 1770 "java_grammar.y"
    { MakeUnary(PostDec, (yyvsp[(1) - (2)].node)); }
    break;

  case 316:
#line 1781 "java_grammar.y"
    { 
		/* TODO */
	}
    break;

  case 317:
#line 1784 "java_grammar.y"
    { 
		/* TODO */
	}
    break;

  case 319:
#line 1788 "java_grammar.y"
    {  
		/* TODO */
	}
    break;

  case 320:
#line 1791 "java_grammar.y"
    { 
		/* TODO */
	}
    break;

  case 321:
#line 1794 "java_grammar.y"
    { 
		/* TODO */
	}
    break;

  case 322:
#line 1797 "java_grammar.y"
    { MakeSimple(This); }
    break;

  case 325:
#line 1800 "java_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 326:
#line 1804 "java_grammar.y"
    {
		MakeBinary(MemberAccess, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	}
    break;

  case 327:
#line 1807 "java_grammar.y"
    {
		MakeBinary(MemberAccess, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	}
    break;

  case 328:
#line 1810 "java_grammar.y"
    {
	}
    break;

  case 329:
#line 1812 "java_grammar.y"
    {
		MakeBinary(MemberAccess, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	}
    break;

  case 330:
#line 1815 "java_grammar.y"
    {
		MakeUnary(BaseAccess,(yyvsp[(3) - (3)].node));
	}
    break;

  case 332:
#line 1822 "java_grammar.y"
    { 
		MakeBinary(InvocationExpression, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); 
	}
    break;

  case 333:
#line 1825 "java_grammar.y"
    { 
		/* TODO */
	}
    break;

  case 334:
#line 1828 "java_grammar.y"
    { 
		(yyval.node) = ILNode_Compound_CreateFrom
				(ILNode_NonStaticInit_create(),
				 ILNode_InvocationExpression_create
					(ILNode_BaseInit_create(), (yyvsp[(2) - (2)].node)));
	}
    break;

  case 335:
#line 1834 "java_grammar.y"
    { 
		/* TODO */
	}
    break;

  case 336:
#line 1840 "java_grammar.y"
    {
		MakeBinary(ArrayAccess, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
	}
    break;

  case 337:
#line 1843 "java_grammar.y"
    {
	}
    break;

  case 338:
#line 1845 "java_grammar.y"
    {
		MakeBinary(ArrayAccess,(yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node));
	}
    break;

  case 339:
#line 1851 "java_grammar.y"
    { (yyval.node) = NULL; }
    break;

  case 340:
#line 1852 "java_grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 341:
#line 1856 "java_grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 342:
#line 1857 "java_grammar.y"
    { MakeBinary(ArgList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 343:
#line 1861 "java_grammar.y"
    {
				MakeBinary(ObjectCreationExpression, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node)); 
	}
    break;

  case 344:
#line 1864 "java_grammar.y"
    {
		/* TODO */
	}
    break;

  case 345:
#line 1867 "java_grammar.y"
    {
		/* TODO */
	}
    break;

  case 346:
#line 1877 "java_grammar.y"
    {
		ILNode *list=ILNode_List_create();
		int i;
		for(i=0;i<(yyvsp[(4) - (4)].count);i++)
		{
			ILNode_List_Add(list,ILNode_JTypeSuffix_create(1));
		}
		(yyval.node) = ILNode_JNewExpression_create((yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),list,NULL);	
	}
    break;

  case 347:
#line 1886 "java_grammar.y"
    {
		(yyval.node) = ILNode_JNewExpression_create((yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node),NULL,NULL);	
	}
    break;

  case 348:
#line 1889 "java_grammar.y"
    {
		ILNode *type=(yyvsp[(2) - (4)].node);
		int i;
		for(i=0;i<(yyvsp[(3) - (4)].count);i++)
		{
			type=ILNode_JArrayType_create(type,1);
		}
		(yyval.node) = ILNode_JNewExpression_create(type,NULL,NULL,(yyvsp[(4) - (4)].node));	
	}
    break;

  case 349:
#line 1898 "java_grammar.y"
    {
		ILNode *list=ILNode_List_create();
		int i;
		for(i=0;i<(yyvsp[(4) - (4)].count);i++)
		{
			ILNode_List_Add(list,ILNode_JTypeSuffix_create(1));
		}
		(yyval.node) = ILNode_JNewExpression_create((yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),list,NULL);	
	}
    break;

  case 350:
#line 1907 "java_grammar.y"
    {
		(yyval.node) = ILNode_JNewExpression_create((yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node),NULL,NULL);	
	}
    break;

  case 351:
#line 1910 "java_grammar.y"
    {
		ILNode *list=ILNode_List_create();
		int i;
		for(i=0;i<(yyvsp[(3) - (4)].count);i++)
		{
			ILNode_List_Add(list,ILNode_JTypeSuffix_create(1));
		}
		(yyval.node) = ILNode_JNewExpression_create((yyvsp[(2) - (4)].node),NULL,list,(yyvsp[(4) - (4)].node));	
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4993 "java_grammar.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 1920 "java_grammar.y"


