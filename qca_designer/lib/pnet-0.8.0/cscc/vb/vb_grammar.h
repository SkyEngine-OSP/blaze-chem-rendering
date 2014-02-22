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
/* Line 1529 of yacc.c.  */
#line 422 "vb_grammar.h"
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
