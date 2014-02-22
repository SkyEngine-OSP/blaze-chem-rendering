/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 358 "cs_grammar.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
