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
/* Line 1529 of yacc.c.  */
#line 245 "java_grammar.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

