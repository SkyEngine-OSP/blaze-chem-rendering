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
/* Line 1529 of yacc.c.  */
#line 277 "c_grammar.h"
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
