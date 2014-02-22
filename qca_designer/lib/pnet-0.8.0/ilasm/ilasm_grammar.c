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
     INTEGER_CONSTANT = 258,
     IDENTIFIER = 259,
     DOT_IDENTIFIER = 260,
     SQUOTE_STRING = 261,
     DQUOTE_STRING = 262,
     FLOAT_CONSTANT = 263,
     HEX_BYTE = 264,
     COLON_COLON = 265,
     DOT_DOT_DOT = 266,
     DOT_DOT = 267,
     D_ADDON = 268,
     D_ALGORITHM = 269,
     D_ASSEMBLY = 270,
     D_BACKING = 271,
     D_BLOB = 272,
     D_CAPABILITY = 273,
     D_CCTOR = 274,
     D_CLASS = 275,
     D_COMTYPE = 276,
     D_CONFIG = 277,
     D_CORFLAGS = 278,
     D_CTOR = 279,
     D_CUSTOM = 280,
     D_DATA = 281,
     D_EMITBYTE = 282,
     D_ENTRYPOINT = 283,
     D_EVENT = 284,
     D_EXELOC = 285,
     D_EXPORT = 286,
     D_FIELD = 287,
     D_FILE = 288,
     D_FIRE = 289,
     D_GET = 290,
     D_HASH = 291,
     D_IMAGEBASE = 292,
     D_IMPLICITCOM = 293,
     D_LANGUAGE = 294,
     D_LIBRARY = 295,
     D_LINE = 296,
     D_LOCALE = 297,
     D_LOCALS = 298,
     D_MANIFESTRES = 299,
     D_MAXSTACK = 300,
     D_METHOD = 301,
     D_MIME = 302,
     D_MODULE = 303,
     D_MRESOURCE = 304,
     D_NAMESPACE = 305,
     D_ORIGINATOR = 306,
     D_OS = 307,
     D_OTHER = 308,
     D_OVERRIDE = 309,
     D_PACK = 310,
     D_PARAM = 311,
     D_PERMISSION = 312,
     D_PERMISSIONSET = 313,
     D_PROCESSOR = 314,
     D_PROPERTY = 315,
     D_PUBLICKEY = 316,
     D_PUBLICKEYTOKEN = 317,
     D_REMOVEON = 318,
     D_SET = 319,
     D_SIZE = 320,
     D_SUBSYSTEM = 321,
     D_TITLE = 322,
     D_TRY = 323,
     D_VER = 324,
     D_VTABLE = 325,
     D_VTENTRY = 326,
     D_VTFIXUP = 327,
     D_ZEROINIT = 328,
     K_AT = 329,
     K_AS = 330,
     K_IMPLICITCOM = 331,
     K_IMPLICITRES = 332,
     K_NOAPPDOMAIN = 333,
     K_NOPROCESS = 334,
     K_NOMACHINE = 335,
     K_EXTERN = 336,
     K_INSTANCE = 337,
     K_EXPLICIT = 338,
     K_DEFAULT = 339,
     K_VARARG = 340,
     K_UNMANAGED = 341,
     K_CDECL = 342,
     K_STDCALL = 343,
     K_THISCALL = 344,
     K_FASTCALL = 345,
     K_MARSHAL = 346,
     K_IN = 347,
     K_OUT = 348,
     K_OPT = 349,
     K_LCID = 350,
     K_RETVAL = 351,
     K_STATIC = 352,
     K_PUBLIC = 353,
     K_PRIVATE = 354,
     K_FAMILY = 355,
     K_INITONLY = 356,
     K_RTSPECIALNAME = 357,
     K_SPECIALNAME = 358,
     K_ASSEMBLY = 359,
     K_FAMANDASSEM = 360,
     K_FAMORASSEM = 361,
     K_PRIVATESCOPE = 362,
     K_LITERAL = 363,
     K_NOTSERIALIZED = 364,
     K_VALUE = 365,
     K_NOT_IN_GC_HEAP = 366,
     K_INTERFACE = 367,
     K_SEALED = 368,
     K_ABSTRACT = 369,
     K_AUTO = 370,
     K_SEQUENTIAL = 371,
     K_ANSI = 372,
     K_UNICODE = 373,
     K_AUTOCHAR = 374,
     K_IMPORT = 375,
     K_SERIALIZABLE = 376,
     K_NESTED = 377,
     K_LATEINIT = 378,
     K_EXTENDS = 379,
     K_IMPLEMENTS = 380,
     K_FINAL = 381,
     K_VIRTUAL = 382,
     K_HIDEBYSIG = 383,
     K_NEWSLOT = 384,
     K_UNMANAGEDEXP = 385,
     K_PINVOKEIMPL = 386,
     K_NOMANGLE = 387,
     K_OLE = 388,
     K_LASTERR = 389,
     K_WINAPI = 390,
     K_NATIVE = 391,
     K_IL = 392,
     K_OPTIL = 393,
     K_MANAGED = 394,
     K_FORWARDREF = 395,
     K_RUNTIME = 396,
     K_INTERNALCALL = 397,
     K_SYNCHRONIZED = 398,
     K_NOINLINING = 399,
     K_CUSTOM = 400,
     K_FIXED = 401,
     K_SYSSTRING = 402,
     K_ARRAY = 403,
     K_VARIANT = 404,
     K_CURRENCY = 405,
     K_SYSCHAR = 406,
     K_VOID = 407,
     K_BOOL = 408,
     K_INT8 = 409,
     K_INT16 = 410,
     K_INT32 = 411,
     K_INT64 = 412,
     K_FLOAT32 = 413,
     K_FLOAT64 = 414,
     K_ERROR = 415,
     K_UNSIGNED = 416,
     K_DECIMAL = 417,
     K_DATE = 418,
     K_BSTR = 419,
     K_LPSTR = 420,
     K_LPWSTR = 421,
     K_LPTSTR = 422,
     K_OBJECTREF = 423,
     K_IUNKNOWN = 424,
     K_IDISPATCH = 425,
     K_STRUCT = 426,
     K_SAFEARRAY = 427,
     K_INT = 428,
     K_BYVALSTR = 429,
     K_TBSTR = 430,
     K_LPVOID = 431,
     K_ANY = 432,
     K_FLOAT = 433,
     K_LPSTRUCT = 434,
     K_NULL = 435,
     K_VECTOR = 436,
     K_HRESULT = 437,
     K_CARRAY = 438,
     K_USERDEFINED = 439,
     K_RECORD = 440,
     K_FILETIME = 441,
     K_BLOB = 442,
     K_STREAM = 443,
     K_STORAGE = 444,
     K_STREAMED_OBJECT = 445,
     K_STORED_OBJECT = 446,
     K_BLOB_OBJECT = 447,
     K_CF = 448,
     K_CLSID = 449,
     K_METHOD = 450,
     K_CLASS = 451,
     K_PINNED = 452,
     K_MODREQ = 453,
     K_MODOPT = 454,
     K_TYPEDREF = 455,
     K_WCHAR = 456,
     K_CHAR = 457,
     K_FROMUNMANAGED = 458,
     K_CALLMOSTDERIVED = 459,
     K_BYTEARRAY = 460,
     K_WITH = 461,
     K_INIT = 462,
     K_TO = 463,
     K_CATCH = 464,
     K_FILTER = 465,
     K_FINALLY = 466,
     K_FAULT = 467,
     K_HANDLER = 468,
     K_TLS = 469,
     K_FIELD = 470,
     K_REQUEST = 471,
     K_DEMAND = 472,
     K_ASSERT = 473,
     K_DENY = 474,
     K_PERMITONLY = 475,
     K_LINKCHECK = 476,
     K_INHERITCHECK = 477,
     K_REQMIN = 478,
     K_REQOPT = 479,
     K_REQREFUSE = 480,
     K_PREJITGRANT = 481,
     K_PREJITDENY = 482,
     K_NONCASDEMAND = 483,
     K_NONCASLINKDEMAND = 484,
     K_NONCASINHERITANCE = 485,
     K_READONLY = 486,
     K_NOMETADATA = 487,
     K_ALGORITHM = 488,
     K_FULLORIGIN = 489,
     K_NAN = 490,
     K_INF = 491,
     K_PUBLICKEY = 492,
     K_ENABLEJITTRACKING = 493,
     K_DISABLEJITOPTIMIZER = 494,
     K_PRESERVESIG = 495,
     K_BEFOREFIELDINIT = 496,
     K_COMPILERCONTROLLED = 497,
     K_CIL = 498,
     K_VALUETYPE = 499,
     K_BOXED = 500,
     K_STRING = 501,
     K_OBJECT = 502,
     K_ALIGNMENT = 503,
     K_REQSECOBJ = 504,
     K_TRUE = 505,
     K_FALSE = 506,
     K_JAVA = 507,
     K_NULLREF = 508,
     I_NONE = 509,
     I_VAR = 510,
     I_INT = 511,
     I_FLOAT = 512,
     I_BRANCH = 513,
     I_METHOD = 514,
     I_FIELD = 515,
     I_TYPE = 516,
     I_STRING = 517,
     I_SIGNATURE = 518,
     I_RVA = 519,
     I_TOKEN = 520,
     I_SSA = 521,
     I_SWITCH = 522,
     I_CONST = 523,
     I_IINC = 524,
     I_LSWITCH = 525,
     I_IMETHOD = 526,
     I_NEWARRAY = 527,
     I_MULTINEWARRAY = 528
   };
#endif
/* Tokens.  */
#define INTEGER_CONSTANT 258
#define IDENTIFIER 259
#define DOT_IDENTIFIER 260
#define SQUOTE_STRING 261
#define DQUOTE_STRING 262
#define FLOAT_CONSTANT 263
#define HEX_BYTE 264
#define COLON_COLON 265
#define DOT_DOT_DOT 266
#define DOT_DOT 267
#define D_ADDON 268
#define D_ALGORITHM 269
#define D_ASSEMBLY 270
#define D_BACKING 271
#define D_BLOB 272
#define D_CAPABILITY 273
#define D_CCTOR 274
#define D_CLASS 275
#define D_COMTYPE 276
#define D_CONFIG 277
#define D_CORFLAGS 278
#define D_CTOR 279
#define D_CUSTOM 280
#define D_DATA 281
#define D_EMITBYTE 282
#define D_ENTRYPOINT 283
#define D_EVENT 284
#define D_EXELOC 285
#define D_EXPORT 286
#define D_FIELD 287
#define D_FILE 288
#define D_FIRE 289
#define D_GET 290
#define D_HASH 291
#define D_IMAGEBASE 292
#define D_IMPLICITCOM 293
#define D_LANGUAGE 294
#define D_LIBRARY 295
#define D_LINE 296
#define D_LOCALE 297
#define D_LOCALS 298
#define D_MANIFESTRES 299
#define D_MAXSTACK 300
#define D_METHOD 301
#define D_MIME 302
#define D_MODULE 303
#define D_MRESOURCE 304
#define D_NAMESPACE 305
#define D_ORIGINATOR 306
#define D_OS 307
#define D_OTHER 308
#define D_OVERRIDE 309
#define D_PACK 310
#define D_PARAM 311
#define D_PERMISSION 312
#define D_PERMISSIONSET 313
#define D_PROCESSOR 314
#define D_PROPERTY 315
#define D_PUBLICKEY 316
#define D_PUBLICKEYTOKEN 317
#define D_REMOVEON 318
#define D_SET 319
#define D_SIZE 320
#define D_SUBSYSTEM 321
#define D_TITLE 322
#define D_TRY 323
#define D_VER 324
#define D_VTABLE 325
#define D_VTENTRY 326
#define D_VTFIXUP 327
#define D_ZEROINIT 328
#define K_AT 329
#define K_AS 330
#define K_IMPLICITCOM 331
#define K_IMPLICITRES 332
#define K_NOAPPDOMAIN 333
#define K_NOPROCESS 334
#define K_NOMACHINE 335
#define K_EXTERN 336
#define K_INSTANCE 337
#define K_EXPLICIT 338
#define K_DEFAULT 339
#define K_VARARG 340
#define K_UNMANAGED 341
#define K_CDECL 342
#define K_STDCALL 343
#define K_THISCALL 344
#define K_FASTCALL 345
#define K_MARSHAL 346
#define K_IN 347
#define K_OUT 348
#define K_OPT 349
#define K_LCID 350
#define K_RETVAL 351
#define K_STATIC 352
#define K_PUBLIC 353
#define K_PRIVATE 354
#define K_FAMILY 355
#define K_INITONLY 356
#define K_RTSPECIALNAME 357
#define K_SPECIALNAME 358
#define K_ASSEMBLY 359
#define K_FAMANDASSEM 360
#define K_FAMORASSEM 361
#define K_PRIVATESCOPE 362
#define K_LITERAL 363
#define K_NOTSERIALIZED 364
#define K_VALUE 365
#define K_NOT_IN_GC_HEAP 366
#define K_INTERFACE 367
#define K_SEALED 368
#define K_ABSTRACT 369
#define K_AUTO 370
#define K_SEQUENTIAL 371
#define K_ANSI 372
#define K_UNICODE 373
#define K_AUTOCHAR 374
#define K_IMPORT 375
#define K_SERIALIZABLE 376
#define K_NESTED 377
#define K_LATEINIT 378
#define K_EXTENDS 379
#define K_IMPLEMENTS 380
#define K_FINAL 381
#define K_VIRTUAL 382
#define K_HIDEBYSIG 383
#define K_NEWSLOT 384
#define K_UNMANAGEDEXP 385
#define K_PINVOKEIMPL 386
#define K_NOMANGLE 387
#define K_OLE 388
#define K_LASTERR 389
#define K_WINAPI 390
#define K_NATIVE 391
#define K_IL 392
#define K_OPTIL 393
#define K_MANAGED 394
#define K_FORWARDREF 395
#define K_RUNTIME 396
#define K_INTERNALCALL 397
#define K_SYNCHRONIZED 398
#define K_NOINLINING 399
#define K_CUSTOM 400
#define K_FIXED 401
#define K_SYSSTRING 402
#define K_ARRAY 403
#define K_VARIANT 404
#define K_CURRENCY 405
#define K_SYSCHAR 406
#define K_VOID 407
#define K_BOOL 408
#define K_INT8 409
#define K_INT16 410
#define K_INT32 411
#define K_INT64 412
#define K_FLOAT32 413
#define K_FLOAT64 414
#define K_ERROR 415
#define K_UNSIGNED 416
#define K_DECIMAL 417
#define K_DATE 418
#define K_BSTR 419
#define K_LPSTR 420
#define K_LPWSTR 421
#define K_LPTSTR 422
#define K_OBJECTREF 423
#define K_IUNKNOWN 424
#define K_IDISPATCH 425
#define K_STRUCT 426
#define K_SAFEARRAY 427
#define K_INT 428
#define K_BYVALSTR 429
#define K_TBSTR 430
#define K_LPVOID 431
#define K_ANY 432
#define K_FLOAT 433
#define K_LPSTRUCT 434
#define K_NULL 435
#define K_VECTOR 436
#define K_HRESULT 437
#define K_CARRAY 438
#define K_USERDEFINED 439
#define K_RECORD 440
#define K_FILETIME 441
#define K_BLOB 442
#define K_STREAM 443
#define K_STORAGE 444
#define K_STREAMED_OBJECT 445
#define K_STORED_OBJECT 446
#define K_BLOB_OBJECT 447
#define K_CF 448
#define K_CLSID 449
#define K_METHOD 450
#define K_CLASS 451
#define K_PINNED 452
#define K_MODREQ 453
#define K_MODOPT 454
#define K_TYPEDREF 455
#define K_WCHAR 456
#define K_CHAR 457
#define K_FROMUNMANAGED 458
#define K_CALLMOSTDERIVED 459
#define K_BYTEARRAY 460
#define K_WITH 461
#define K_INIT 462
#define K_TO 463
#define K_CATCH 464
#define K_FILTER 465
#define K_FINALLY 466
#define K_FAULT 467
#define K_HANDLER 468
#define K_TLS 469
#define K_FIELD 470
#define K_REQUEST 471
#define K_DEMAND 472
#define K_ASSERT 473
#define K_DENY 474
#define K_PERMITONLY 475
#define K_LINKCHECK 476
#define K_INHERITCHECK 477
#define K_REQMIN 478
#define K_REQOPT 479
#define K_REQREFUSE 480
#define K_PREJITGRANT 481
#define K_PREJITDENY 482
#define K_NONCASDEMAND 483
#define K_NONCASLINKDEMAND 484
#define K_NONCASINHERITANCE 485
#define K_READONLY 486
#define K_NOMETADATA 487
#define K_ALGORITHM 488
#define K_FULLORIGIN 489
#define K_NAN 490
#define K_INF 491
#define K_PUBLICKEY 492
#define K_ENABLEJITTRACKING 493
#define K_DISABLEJITOPTIMIZER 494
#define K_PRESERVESIG 495
#define K_BEFOREFIELDINIT 496
#define K_COMPILERCONTROLLED 497
#define K_CIL 498
#define K_VALUETYPE 499
#define K_BOXED 500
#define K_STRING 501
#define K_OBJECT 502
#define K_ALIGNMENT 503
#define K_REQSECOBJ 504
#define K_TRUE 505
#define K_FALSE 506
#define K_JAVA 507
#define K_NULLREF 508
#define I_NONE 509
#define I_VAR 510
#define I_INT 511
#define I_FLOAT 512
#define I_BRANCH 513
#define I_METHOD 514
#define I_FIELD 515
#define I_TYPE 516
#define I_STRING 517
#define I_SIGNATURE 518
#define I_RVA 519
#define I_TOKEN 520
#define I_SSA 521
#define I_SWITCH 522
#define I_CONST 523
#define I_IINC 524
#define I_LSWITCH 525
#define I_IMETHOD 526
#define I_NEWARRAY 527
#define I_MULTINEWARRAY 528




/* Copy the first part of user declarations.  */
#line 1 "ilasm_grammar.y"

/*
 * ilasm_grammar.y - Input file for yacc that defines the syntax of
 *                   the ILASM language.
 *
 * Copyright (C) 2001, 2002  Southern Storm Software, Pty Ltd.
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
#include "ilasm_rename.h"

#define YYDEBUG 1

#include <stdio.h>
#include "il_system.h"
#include "il_opcodes.h"
#include "il_meta.h"
#include "il_utils.h"
#include "ilasm_build.h"
#include "ilasm_output.h"
#include "ilasm_data.h"
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

extern char *ILAsmFilename;
extern long  ILAsmLineNum;
extern int   ILAsmErrors;
extern int   ILAsmParseHexBytes;
extern int   ILAsmParseJava;
extern int yylex(void);
#ifdef YYTEXT_POINTER
extern char *ilasm_text;
#else
extern char ilasm_text[];
#endif

static void
yyerror(char *msg)
{
	if(ILAsmFilename && ILAsmLineNum >= 0)
	{
		fprintf(stderr, "%s:%ld: ", ILAsmFilename, ILAsmLineNum);
	}
	else if(ILAsmFilename)
	{
		fprintf(stderr, "%s: ", ILAsmFilename);
	}
	else if(ILAsmLineNum >= 0)
	{
		fprintf(stderr, "%ld: ", ILAsmLineNum);
	}
	if(!strcmp(msg, "parse error") || !strcmp(msg, "syntax error"))
	{
		/* This message is useless, so print something based on ilasm_text */
		fprintf(stderr, "parse error at or near `%s'\n", ilasm_text);
	}
	else
	{
		fprintf(stderr, msg);
		putc('\n', stderr);
	}
	ILAsmErrors = 1;
}

/*
 * Message printing function that is used elsewhere.
 */
void ILAsmPrintMessage(const char *filename, long linenum,
					   const char *format, ...)
{
	va_list va;
	if(filename)
	{
		fputs(filename, stderr);
		if(linenum >= 0)
		{
			fprintf(stderr, ":%ld: ", linenum);
		}
		else
		{
			fputs(": ", stderr);
		}
	}
	else if(linenum >= 0)
	{
		fprintf(stderr, "%ld: ", linenum);
	}
	va_start(va, format);
	vfprintf(stderr, format, va);
	va_end(va);
	putc('\n', stderr);
}

/*
 * Report an out of memory error and abort.
 */
void ILAsmOutOfMemory(void)
{
	fprintf(stderr, "ilasm: virtual memory exhausted\n");
	exit(1);
}

/*
 * Make a simple native specification.
 */
static ILIntString SimpleNative(int type)
{
	char str[1];
	str[0] = (char)type;
	return ILInternString(str, 1);
}

/*
 * Convert a string into its packed representation.
 */
static ILIntString PackString(ILIntString str)
{
	unsigned char prefix[5];
	ILIntString prefixBlock;
	prefixBlock.string = (char *)prefix;
	prefixBlock.len = ILMetaCompressData(prefix, (unsigned long)(str.len));
	if(str.len != 0)
	{
		return ILInternAppendedString(prefixBlock, str);
	}
	else
	{
		return ILInternString(prefixBlock.string, prefixBlock.len);
	}
}

/*
 * Convert a length value into its packed representation.
 */
static ILIntString PackLength(ILInt64 len)
{
	unsigned char prefix[5];
	int prefixLen = ILMetaCompressData(prefix, (unsigned long)len);
	return ILInternString((char *)prefix, prefixLen);
}

/*
 * Pack a string into its Unicode representation.
 */
static ILIntString PackUnicodeString(ILIntString str)
{
	int posn = 0;
	unsigned char buf[256];
	int outposn = 0;
	ILIntString result = ILInternString("", 0);
	while(posn < str.len)
	{
		outposn += ILUTF16WriteCharAsBytes
			(buf + outposn, ILUTF8ReadChar(str.string, str.len, &posn));
		if(outposn >= 240)
		{
			if(result.len > 0)
			{
				result = ILInternAppendedString
							(result, ILInternString((char *)buf, outposn));
			}
			else
			{
				result = ILInternString((char *)buf, outposn);
			}
			outposn = 0;
		}
	}
	if(outposn > 0)
	{
		if(result.len > 0)
		{
			return ILInternAppendedString(result,
									  	  ILInternString((char *)buf, outposn));
		}
		else
		{
			return ILInternString((char *)buf, outposn);
		}
	}
	else
	{
		return result;
	}
}

/*
 * Helper function that sets 32-bit version of a "float".
 */
static void SetFloat(unsigned char *fbytes, ILFloat value)
{
	IL_WRITE_FLOAT(fbytes, value);
}

/*
 * Helper function that sets 64-bit version of a "float".
 */
static void SetDouble(unsigned char *dbytes, ILDouble value)
{
	IL_WRITE_DOUBLE(dbytes, value);
}

/*
 * Find a module reference, or create it if not found.
 */
static ILModule *FindModuleRef(ILImage *image, const char *name)
{
	ILModule *module;
	if(!name)
	{
		name = "";
	}
	module = ILModuleRefCreateUnique(image, name);
	if(!module)
	{
		ILAsmOutOfMemory();
	}
	return module;
}

/*
 * Create a method signature type.
 */
static ILType *CreateMethodSig(ILInt64 callingConventions,
							   ILType *returnType,
							   ILAsmParamInfo *params,
							   ILAsmParamInfo *genericParams,
							   int freeParams)
{
	ILType *type;
	ILAsmParamInfo *nextParam;
	ILUInt32 numGenericParams;

	/* Set the "generic" flag if there are generic parameters */
	numGenericParams = 0;
	if(genericParams)
	{
		callingConventions |= IL_META_CALLCONV_GENERIC;
		nextParam = genericParams;
		while(nextParam != 0)
		{
			++numGenericParams;
			nextParam = nextParam->next;
		}
	}

	/* Create the main method type block */
	type = ILTypeCreateMethod(ILAsmContext, returnType);
	if(!type)
	{
		ILAsmOutOfMemory();
	}
	ILTypeSetCallConv(type, (ILUInt32)callingConventions);
	ILType_SetNumGen(type, numGenericParams);

	/* Add the parameters to the method signature */
	while(params != 0)
	{
		nextParam = params->next;
		if(params->type)
		{
			if(!ILTypeAddParam(ILAsmContext, type, params->type))
			{
				ILAsmOutOfMemory();
			}
		}
		else
		{
			if(!ILTypeAddSentinel(ILAsmContext, type))
			{
				ILAsmOutOfMemory();
			}
		}
		if(freeParams)
		{
			ILFree(params);
		}
		params = nextParam;
	}

	/* Return the final method type to the caller */
	return type;
}

/*
 * Create a method specification token.
 */
static ILToken CreateMethodSpec(ILToken method, ILAsmParamInfo *params)
{
	ILMember *member;
	ILType *signature;
	ILMethodSpec *spec;
	
	/* Convert the method token back into a MethodDef or MemberRef */
	member = ILMember_FromToken(ILAsmImage, method);
	if(!member)
	{
		return method;
	}

	/* Create the method instantiation signature */
	signature = CreateMethodSig(IL_META_CALLCONV_INSTANTIATION,
								ILType_Invalid, params, 0, 1);

	/* Create the MethodSpec token */
	spec = ILMethodSpecCreate(ILAsmImage, 0, member, signature);
	if(!spec)
	{
		ILAsmOutOfMemory();
	}
	return ILMethodSpec_Token(spec);
}

/*
 * Add parameter definition information to a method signature.
 */
static void AddMethodParams(ILMethod *method, ILUInt32 parameterAttrs,
							ILIntString nativeType, ILAsmParamInfo *params)
{
	ILParameter *param;
	ILFieldMarshal *marshal;
	ILAsmParamInfo *nextParam;
	unsigned int paramNum;
	char nameBuf[64];

	/* Create a parameter definition for the return value */
	if(parameterAttrs != 0 || nativeType.len > 0)
	{
		param = ILParameterCreate(method, 0, "retval",
								  parameterAttrs, 0);
		if(!param)
		{
			ILAsmOutOfMemory();
		}
		if(nativeType.len > 0)
		{
			marshal = ILFieldMarshalCreate(ILAsmImage, 0,
										   ILToProgramItem(param));
			if(!marshal)
			{
				ILAsmOutOfMemory();
			}
			if(!ILFieldMarshalSetType(marshal, nativeType.string,
									  nativeType.len))
			{
				ILAsmOutOfMemory();
			}
		}
	}

	/* Add the parameters to the method signature */
	paramNum = 1;
	while(params != 0)
	{
		nextParam = params->next;
		if(params->type)
		{
			if(params->name)
			{
				param = ILParameterCreate(method, 0, params->name,
							  (ILUInt32)(params->parameterAttrs), paramNum);
			}
			else
			{
				sprintf(nameBuf, "A_%u", paramNum);
				param = ILParameterCreate(method, 0, nameBuf,
							  (ILUInt32)(params->parameterAttrs), paramNum);
			}
			if(!param)
			{
				ILAsmOutOfMemory();
			}
			if(params->nativeType.len > 0)
			{
				marshal = ILFieldMarshalCreate(ILAsmImage, 0,
											   ILToProgramItem(param));
				if(!marshal)
				{
					ILAsmOutOfMemory();
				}
				if(!ILFieldMarshalSetType(marshal, params->nativeType.string,
										  params->nativeType.len))
				{
					ILAsmOutOfMemory();
				}
			}
			++paramNum;
		}
		ILFree(params);
		params = nextParam;
	}
}

/*
 * Create a property signature type.
 */
static ILType *CreatePropertySig(ILInt64 callingConventions,
							     ILType *returnType,
							     ILAsmParamInfo *params)
{
	ILType *type;
	ILAsmParamInfo *nextParam;

	/* Create the main property type block */
	type = ILTypeCreateProperty(ILAsmContext, returnType);
	if(!type)
	{
		ILAsmOutOfMemory();
	}
	ILTypeSetCallConv(type, (ILUInt32)callingConventions);

	/* Add the parameters to the property signature */
	while(params != 0)
	{
		nextParam = params->next;
		if(params->type)
		{
			if(!ILTypeAddParam(ILAsmContext, type, params->type))
			{
				ILAsmOutOfMemory();
			}
		}
		else
		{
			if(!ILTypeAddSentinel(ILAsmContext, type))
			{
				ILAsmOutOfMemory();
			}
		}
		ILFree(params);
		params = nextParam;
	}

	/* Return the final property type to the caller */
	return type;
}

/*
 * Helper macros for setting the attributes of non-terminals.
 */
#define	SET_FIELD(name)		yyval.fieldAttrs.flags = IL_META_FIELDDEF_##name; \
							yyval.fieldAttrs.nativeType.string = 0; \
							yyval.fieldAttrs.nativeType.len = 0; \
							yyval.fieldAttrs.pinvokeAttrs = 0; \
							yyval.fieldAttrs.name1 = 0; \
							yyval.fieldAttrs.name2 = 0
#define	SET_METHOD(name)	yyval.methodAttrs.flags = \
								IL_META_METHODDEF_##name; \
							yyval.methodAttrs.pinvokeAttrs = 0; \
							yyval.methodAttrs.name1 = 0; \
							yyval.methodAttrs.name2 = 0

/*
 * Buffer that is used during byte list parsing.
 */
#define	ILASM_BYTE_BUFSIZ	256
static char byteBuffer[ILASM_BYTE_BUFSIZ];

/*
 * Get the token associated with a program item.
 */
#define	GetToken(item)		(ILProgramItemGetToken(ILToProgramItem((item))))

/*
 * Combine an array shell with an element type.
 */
static ILType *CombineArrayType(ILType *elemType, ILType *shell, int cont)
{
	ILType *temp;
	ILType *temp2;

	if(!elemType || !shell)
	{
		ILAsmOutOfMemory();
	}

	/* If the element type is an array, we need to insert the shell
	   at the inner-most level of the element type */
	if(ILType_IsArray(elemType))
	{
		temp = elemType;
		while(ILType_ElemType(temp) != 0 &&
		      ILType_IsComplex(ILType_ElemType(temp)) &&
			  (ILType_Kind(ILType_ElemType(temp)) == IL_TYPE_COMPLEX_ARRAY ||
			   ILType_Kind(ILType_ElemType(temp))
			   		== IL_TYPE_COMPLEX_ARRAY_CONTINUE))
		{
			temp = ILType_ElemType(temp);
		}
		temp2 = ILType_ElemType(temp);
		ILType_ElemType(temp) = shell;
		if(cont)
		{
			temp->kind__ = IL_TYPE_COMPLEX_ARRAY_CONTINUE;
		}
		temp = shell;
		while(ILType_Kind(temp) == IL_TYPE_COMPLEX_ARRAY_CONTINUE)
		{
			temp = ILType_ElemType(temp);
		}
		ILType_ElemType(temp) = temp2;
		return elemType;
	}

	/* Wrap the shell around the element type */
	temp = shell;
	while(ILType_ElemType(temp) != 0 &&
	      ILType_IsComplex(ILType_ElemType(temp)) &&
		  (ILType_Kind(ILType_ElemType(temp)) == IL_TYPE_COMPLEX_ARRAY ||
		   ILType_Kind(ILType_ElemType(temp))
			   		== IL_TYPE_COMPLEX_ARRAY_CONTINUE))
	{
		temp = ILType_ElemType(temp);
	}
	ILType_ElemType(temp) = elemType;
	return shell;
}

/*
 * Set the originator for the current assembly definition or reference.
 */
static void SetOriginator(char *orig, int len, int fullOriginator)
{
	if(ILAsmCurrAssemblyRef)
	{
		if(!ILAssemblySetOriginator(ILAsmCurrAssemblyRef,
									(const void *)orig,
									(unsigned long)(long)len))
		{
			ILAsmOutOfMemory();
		}
		if(fullOriginator)
		{
			ILAssemblySetRefAttrs(ILAsmCurrAssemblyRef,
								  IL_META_ASSEMREF_FULL_ORIGINATOR,
								  IL_META_ASSEMREF_FULL_ORIGINATOR);
		}
	}
	else
	{
		if(!ILAssemblySetOriginator(ILAsmAssembly,
									(const void *)orig,
									(unsigned long)(long)len))
		{
			ILAsmOutOfMemory();
		}
		ILAssemblySetAttrs(ILAsmAssembly,
						   IL_META_ASSEM_PUBLIC_KEY,
						   IL_META_ASSEM_PUBLIC_KEY);
	}
}


typedef struct _tagFieldDataEntry
{
	char    *name;
	ILField *field;
	char *filename;
	long linenum;
	struct _tagFieldDataEntry * next;  
} FieldDataEntry;

typedef struct _tagFieldDataList
{
	FieldDataEntry * first;
	FieldDataEntry * last;
} FieldDataList;

static FieldDataList *unresolvedFieldList = 0;

static void RegisterFieldRvaLabel(char * name, ILField * field)
{
	FieldDataEntry *entry;
	
	if(!unresolvedFieldList)
	{
		unresolvedFieldList = (FieldDataList*) ILMalloc(sizeof(FieldDataList)); 
		if(!unresolvedFieldList)
		{
			ILAsmOutOfMemory();
		}
		unresolvedFieldList->first = 0;
		unresolvedFieldList->last = 0;
	}

	entry = (FieldDataEntry*) ILMalloc(sizeof(FieldDataEntry));

	if(!entry)
	{
		ILAsmOutOfMemory();
	}

	entry->name = name;
	entry->field = field;
	entry->filename = ILAsmFilename;
	entry->linenum = ILAsmLineNum;
	entry->next = NULL;


	if(!unresolvedFieldList->first)
	{
		unresolvedFieldList->first = entry;
		unresolvedFieldList->last = entry;
	}
	else
	{
		unresolvedFieldList->last->next = entry;
		unresolvedFieldList->last = entry;
	}
}

static void FinishDataLabels()
{
	FieldDataEntry * tmp;
	if(unresolvedFieldList)
	{
		for(tmp = unresolvedFieldList->first ; tmp != NULL ; tmp = tmp->next)
		{
			ILInt64 offset = ILAsmDataResolveLabel(tmp->name);
			if(offset == -1)
			{
				ILAsmPrintMessage(tmp->filename, tmp->linenum,
						  "data label `%s' undefined", tmp->name);
				ILAsmErrors = 1;
			}
			else
			{
				/* Set the RVA information for the field */
				if(!ILFieldRVACreate(ILAsmImage, 0,
									 tmp->field, (ILUInt32)offset))
				{
					ILAsmOutOfMemory();
				}
			}
			ILFree(tmp);
		}
		ILFree(unresolvedFieldList);
		unresolvedFieldList = 0;
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
#line 674 "ilasm_grammar.y"
{
	ILInt64			integer;
	ILIntString		strValue;
	ILDouble		real;
	struct {
		ILUInt8		fbytes[4];
		ILUInt8		dbytes[8];
	}				floatValue;
	struct {
		ILInt64		flags;
		ILIntString	nativeType;
		ILInt64		pinvokeAttrs;
		char	   *name1;
		char	   *name2;
	}				fieldAttrs;
	struct {
		ILInt64		flags;
		ILInt64		pinvokeAttrs;
		char	   *name1;
		char	   *name2;
	}				methodAttrs;
	ILInt32			opcode;
	struct {
		ILIntString	interned;
		int			extraSize;
	}				byteList;
	ILClass		   *classInfo;
	ILType		   *type;
	struct
	{
		ILType	   *type;
		ILIntString	nativeType;
	}				marshType;
	struct
	{
		ILAsmParamInfo *paramFirst;
		ILAsmParamInfo *paramLast;
	}				params;
	struct
	{
		ILUInt32	type;
		ILIntString	valueBlob;
	}				fieldInit;
	struct
	{
		ILType		   *type;
		ILProgramItem  *item;

	}				typeSpec;
	ILProgramItem  *customType;
	struct
	{
		char	   *start;
		char	   *end;
	}				scope;
	struct
	{
		char       *label;
		ILInt64     offset;
	}				datalabel;
	ILAsmOutException *exception;
	ILToken			token;

}
/* Line 193 of yacc.c.  */
#line 1377 "ilasm_grammar.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1390 "ilasm_grammar.c"

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
#define YYFINAL  158
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  294
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  202
/* YYNRULES -- Number of rules.  */
#define YYNRULES  815
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1385

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   528

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   293,     2,     2,     2,   292,   289,     2,
     277,   278,   287,   281,   276,   279,   280,   290,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   288,     2,
     282,   286,   283,   291,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   284,     2,   285,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   274,     2,   275,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    13,    18,    19,
      26,    31,    32,    39,    41,    43,    45,    47,    49,    51,
      53,    58,    63,    68,    73,    75,    77,    79,    81,    84,
      87,    90,    94,    97,   102,   109,   111,   113,   115,   117,
     119,   124,   129,   131,   133,   136,   138,   142,   145,   147,
     151,   152,   157,   159,   162,   164,   167,   171,   172,   180,
     181,   185,   187,   191,   196,   198,   199,   201,   203,   206,
     208,   210,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   238,   241,   244,   247,   250,
     253,   256,   258,   260,   262,   264,   265,   268,   269,   272,
     274,   278,   279,   281,   283,   286,   291,   292,   299,   304,
     309,   314,   316,   318,   320,   322,   324,   327,   330,   335,
     349,   350,   360,   361,   365,   366,   368,   370,   373,   375,
     377,   378,   382,   383,   386,   389,   390,   393,   394,   396,
     398,   401,   403,   405,   407,   409,   411,   413,   415,   420,
     422,   424,   426,   428,   430,   432,   434,   442,   448,   453,
     458,   463,   468,   473,   478,   483,   488,   493,   499,   505,
     510,   515,   520,   525,   530,   535,   540,   542,   548,   551,
     553,   565,   567,   573,   575,   577,   579,   580,   582,   584,
     587,   589,   591,   593,   595,   597,   599,   601,   603,   605,
     607,   609,   611,   613,   615,   617,   619,   621,   623,   631,
     637,   642,   643,   645,   647,   650,   652,   654,   656,   658,
     660,   662,   664,   666,   668,   670,   672,   673,   675,   677,
     680,   682,   684,   686,   688,   690,   692,   694,   696,   698,
     700,   702,   704,   706,   707,   709,   711,   714,   717,   719,
     722,   727,   733,   740,   742,   744,   746,   748,   751,   754,
     756,   758,   760,   765,   770,   772,   777,   784,   785,   787,
     789,   792,   795,   798,   800,   802,   804,   807,   810,   812,
     814,   816,   817,   822,   823,   825,   828,   831,   833,   836,
     841,   846,   849,   852,   855,   858,   861,   864,   867,   870,
     872,   874,   876,   881,   886,   887,   892,   893,   895,   898,
     901,   903,   906,   911,   916,   919,   922,   924,   927,   930,
     935,   939,   940,   942,   944,   947,   949,   951,   952,   954,
     956,   959,   962,   965,   968,   971,   973,   975,   984,   991,
    1001,  1009,  1019,  1027,  1028,  1032,  1034,  1038,  1047,  1048,
    1050,  1052,  1055,  1057,  1059,  1060,  1062,  1064,  1067,  1070,
    1073,  1076,  1080,  1082,  1084,  1087,  1092,  1095,  1096,  1098,
    1102,  1104,  1106,  1110,  1111,  1115,  1121,  1127,  1132,  1135,
    1141,  1147,  1153,  1159,  1165,  1171,  1174,  1177,  1180,  1183,
    1186,  1189,  1193,  1201,  1202,  1204,  1206,  1209,  1211,  1213,
    1215,  1217,  1219,  1223,  1228,  1230,  1235,  1240,  1246,  1248,
    1250,  1252,  1256,  1259,  1263,  1266,  1269,  1274,  1279,  1282,
    1285,  1288,  1291,  1297,  1303,  1311,  1313,  1315,  1317,  1319,
    1321,  1323,  1325,  1327,  1329,  1331,  1333,  1336,  1339,  1342,
    1345,  1348,  1352,  1355,  1357,  1359,  1362,  1366,  1371,  1373,
    1377,  1379,  1383,  1384,  1386,  1388,  1392,  1396,  1399,  1402,
    1403,  1414,  1420,  1426,  1428,  1430,  1432,  1434,  1436,  1438,
    1440,  1442,  1444,  1446,  1448,  1450,  1453,  1456,  1459,  1462,
    1465,  1469,  1474,  1482,  1488,  1498,  1505,  1507,  1509,  1511,
    1513,  1515,  1517,  1519,  1521,  1523,  1525,  1527,  1530,  1532,
    1535,  1538,  1540,  1543,  1545,  1548,  1550,  1552,  1555,  1557,
    1559,  1560,  1562,  1564,  1566,  1568,  1570,  1572,  1574,  1576,
    1578,  1580,  1582,  1585,  1588,  1591,  1594,  1598,  1601,  1604,
    1606,  1608,  1610,  1612,  1614,  1616,  1618,  1620,  1622,  1625,
    1627,  1629,  1631,  1633,  1635,  1637,  1639,  1641,  1643,  1645,
    1647,  1649,  1651,  1653,  1654,  1656,  1658,  1662,  1664,  1667,
    1671,  1672,  1674,  1678,  1683,  1685,  1687,  1689,  1691,  1693,
    1694,  1697,  1700,  1702,  1704,  1707,  1710,  1713,  1716,  1720,
    1726,  1730,  1736,  1739,  1744,  1751,  1755,  1756,  1758,  1760,
    1763,  1765,  1767,  1775,  1780,  1785,  1787,  1789,  1790,  1793,
    1794,  1796,  1798,  1801,  1803,  1805,  1807,  1809,  1811,  1813,
    1814,  1816,  1818,  1821,  1827,  1830,  1834,  1838,  1840,  1842,
    1846,  1850,  1854,  1863,  1866,  1870,  1873,  1880,  1883,  1887,
    1889,  1896,  1901,  1902,  1904,  1906,  1909,  1911,  1912,  1914,
    1916,  1919,  1923,  1926,  1928,  1933,  1936,  1938,  1940,  1941,
    1945,  1946,  1948,  1950,  1953,  1955,  1957,  1960,  1963,  1966,
    1969,  1972,  1975,  1976,  1978,  1980,  1983,  1986,  1990,  1993,
    1996,  1999,  2001,  2006,  2008,  2010,  2011,  2015,  2016,  2018,
    2020,  2023,  2025,  2027,  2028,  2030,  2032,  2035,  2038,  2042,
    2047,  2051,  2055,  2057,  2064,  2068,  2073,  2077,  2082,  2084,
    2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,  2104,
    2106,  2108,  2110,  2112,  2114,  2118,  2122,  2125,  2130,  2135,
    2143,  2151,  2157,  2159,  2161,  2163,  2166,  2172,  2176,  2178,
    2181,  2184,  2187,  2190,  2193,  2196,  2199,  2202,  2208,  2212,
    2215,  2218,  2222,  2229,  2232,  2235,  2239,  2246,  2251,  2254,
    2255,  2259,  2260,  2266,  2268,  2270,  2272,  2273,  2275,  2277,
    2280,  2281,  2283,  2285,  2289,  2291,  2293,  2295,  2298,  2302,
    2305,  2311,  2317,  2323,  2329,  2332,  2335,  2338,  2341,  2346,
    2352,  2357,  2360,  2363,  2367,  2373,  2376,  2380,  2384,  2385,
    2394,  2395,  2402,  2404,  2406,  2408,  2410,  2412,  2414,  2416,
    2418,  2419,  2421,  2423,  2427,  2429,  2431,  2433,  2435,  2436,
    2438,  2440,  2444,  2446,  2448,  2452
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     295,     0,    -1,   296,    -1,    -1,   297,    -1,   298,    -1,
     297,   298,    -1,   313,   274,   324,   275,    -1,    -1,    50,
     307,   299,   274,   296,   275,    -1,   341,   274,   353,   275,
      -1,    -1,   341,   252,   274,   300,   356,   275,    -1,   328,
      -1,   398,    -1,   405,    -1,   406,    -1,   427,    -1,   428,
      -1,   432,    -1,   433,   274,   439,   275,    -1,   443,   274,
     447,   275,    -1,   450,   274,   456,   275,    -1,   459,   274,
     465,   275,    -1,   312,    -1,   468,    -1,   472,    -1,   301,
      -1,    66,     3,    -1,    23,     3,    -1,    37,     3,    -1,
      33,   248,     3,    -1,    39,     6,    -1,    39,     6,   276,
       6,    -1,    39,     6,   276,     6,   276,     6,    -1,     4,
      -1,     6,    -1,     3,    -1,     3,    -1,     8,    -1,   158,
     277,   304,   278,    -1,   159,   277,   305,   278,    -1,   235,
      -1,   236,    -1,   279,   236,    -1,   303,    -1,   307,   280,
     303,    -1,   307,     5,    -1,     7,    -1,   308,   281,     7,
      -1,    -1,   277,   310,   311,   278,    -1,     9,    -1,   311,
       9,    -1,    48,    -1,    48,   307,    -1,    48,    81,   307,
      -1,    -1,    20,   318,   303,   315,   321,   314,   322,    -1,
      -1,   282,   316,   283,    -1,   317,    -1,   316,   276,   317,
      -1,   277,   410,   278,   303,    -1,   303,    -1,    -1,   319,
      -1,   320,    -1,   319,   320,    -1,    98,    -1,    99,    -1,
     110,    -1,    86,    -1,   111,    -1,   112,    -1,   113,    -1,
     114,    -1,   115,    -1,   116,    -1,    83,    -1,   117,    -1,
     118,    -1,   119,    -1,   120,    -1,   121,    -1,   122,    98,
      -1,   122,    99,    -1,   122,   100,    -1,   122,   104,    -1,
     122,   105,    -1,   122,   106,    -1,   123,    -1,   241,    -1,
     103,    -1,   102,    -1,    -1,   124,   412,    -1,    -1,   125,
     323,    -1,   412,    -1,   323,   276,   412,    -1,    -1,   325,
      -1,   326,    -1,   325,   326,    -1,   341,   274,   353,   275,
      -1,    -1,   341,   252,   274,   327,   356,   275,    -1,   313,
     274,   324,   275,    -1,   379,   274,   383,   275,    -1,   391,
     274,   395,   275,    -1,   328,    -1,   398,    -1,   468,    -1,
     427,    -1,   472,    -1,    65,   304,    -1,    55,   304,    -1,
     450,   274,   456,   275,    -1,    54,   410,    10,   343,   206,
     426,   414,   410,    10,   343,   277,   420,   278,    -1,    -1,
      32,   334,   337,   414,   303,   335,   336,   329,   330,    -1,
      -1,   274,   331,   275,    -1,    -1,   332,    -1,   333,    -1,
     332,   333,    -1,   427,    -1,   472,    -1,    -1,   284,   304,
     285,    -1,    -1,    74,   303,    -1,    74,   304,    -1,    -1,
     286,   340,    -1,    -1,   338,    -1,   339,    -1,   338,   339,
      -1,    97,    -1,    98,    -1,    99,    -1,   100,    -1,   101,
      -1,   102,    -1,   103,    -1,    91,   277,   418,   278,    -1,
     104,    -1,   105,    -1,   106,    -1,   107,    -1,   242,    -1,
     108,    -1,   109,    -1,   131,   277,   308,    75,   308,   347,
     278,    -1,   131,   277,   308,   347,   278,    -1,   131,   277,
     347,   278,    -1,   158,   277,     8,   278,    -1,   159,   277,
       8,   278,    -1,   158,   277,   305,   278,    -1,   159,   277,
     305,   278,    -1,   158,   277,   235,   278,    -1,   159,   277,
     235,   278,    -1,   158,   277,   236,   278,    -1,   159,   277,
     236,   278,    -1,   158,   277,   279,   236,   278,    -1,   159,
     277,   279,   236,   278,    -1,   157,   277,   305,   278,    -1,
     156,   277,   305,   278,    -1,   155,   277,   305,   278,    -1,
     154,   277,   305,   278,    -1,   202,   277,   305,   278,    -1,
     153,   277,   250,   278,    -1,   153,   277,   251,   278,    -1,
     308,    -1,   201,   287,   277,   308,   278,    -1,   205,   309,
      -1,   253,    -1,    46,   344,   426,   423,   342,   343,   315,
     277,   420,   278,   350,    -1,   414,    -1,   414,    91,   277,
     418,   278,    -1,    24,    -1,    19,    -1,   307,    -1,    -1,
     345,    -1,   346,    -1,   345,   346,    -1,    97,    -1,    98,
      -1,    99,    -1,   100,    -1,   126,    -1,   103,    -1,   127,
      -1,   114,    -1,   104,    -1,   105,    -1,   106,    -1,   107,
      -1,   242,    -1,   128,    -1,   129,    -1,   102,    -1,   249,
      -1,   130,    -1,   131,   277,   308,    75,   308,   347,   278,
      -1,   131,   277,   308,   347,   278,    -1,   131,   277,   347,
     278,    -1,    -1,   348,    -1,   349,    -1,   348,   349,    -1,
     132,    -1,   117,    -1,   118,    -1,   119,    -1,   133,    -1,
     134,    -1,   135,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    -1,   351,    -1,   352,    -1,   351,   352,    -1,
     136,    -1,   137,    -1,   243,    -1,   138,    -1,   139,    -1,
      86,    -1,   140,    -1,   133,    -1,   240,    -1,   141,    -1,
     142,    -1,   143,    -1,   144,    -1,    -1,   354,    -1,   355,
      -1,   354,   355,    -1,    27,   304,    -1,   362,    -1,    45,
     304,    -1,    43,   277,   420,   278,    -1,    43,   207,   277,
     420,   278,    -1,    43,   282,   303,   286,   304,   283,    -1,
      28,    -1,    73,    -1,   398,    -1,   475,    -1,   303,   288,
      -1,   304,   288,    -1,   468,    -1,   427,    -1,   472,    -1,
      71,   304,   288,   304,    -1,    54,   410,    10,   343,    -1,
     359,    -1,    56,   284,   304,   285,    -1,    56,   284,   304,
     285,   286,   340,    -1,    -1,   357,    -1,   358,    -1,   357,
     358,    -1,    45,   304,    -1,    43,   304,    -1,   484,    -1,
     374,    -1,   371,    -1,   303,   288,    -1,   304,   288,    -1,
     468,    -1,   427,    -1,   472,    -1,    -1,   274,   360,   361,
     275,    -1,    -1,   354,    -1,   364,   363,    -1,   365,   363,
      -1,   365,    -1,    68,   359,    -1,    68,   303,   208,   303,
      -1,    68,   304,   208,   304,    -1,   366,   370,    -1,   367,
     370,    -1,   368,   370,    -1,   369,   370,    -1,   209,   411,
      -1,   210,   359,    -1,   210,   303,    -1,   210,   304,    -1,
     211,    -1,   212,    -1,   359,    -1,   213,   303,   208,   303,
      -1,   213,   304,   208,   304,    -1,    -1,   274,   372,   373,
     275,    -1,    -1,   357,    -1,   376,   375,    -1,   377,   375,
      -1,   377,    -1,    68,   371,    -1,    68,   303,   208,   303,
      -1,    68,   304,   208,   304,    -1,   366,   378,    -1,   368,
     378,    -1,   371,    -1,   213,   303,    -1,   213,   304,    -1,
      29,   380,   410,   303,    -1,    29,   380,   303,    -1,    -1,
     381,    -1,   382,    -1,   381,   382,    -1,   102,    -1,   103,
      -1,    -1,   384,    -1,   385,    -1,   384,   385,    -1,    13,
     386,    -1,    63,   386,    -1,    34,   386,    -1,    53,   386,
      -1,   427,    -1,   472,    -1,   426,   414,   410,    10,   343,
     277,   420,   278,    -1,   426,   414,   343,   277,   420,   278,
      -1,   426,   414,   410,    10,   343,   389,   277,   420,   278,
      -1,   426,   414,   343,   389,   277,   420,   278,    -1,   426,
     414,   410,    10,   343,   389,   277,   420,   278,    -1,   426,
     414,   343,   389,   277,   420,   278,    -1,    -1,   282,   390,
     283,    -1,   414,    -1,   390,   276,   414,    -1,    60,   392,
     426,   414,   303,   277,   420,   278,    -1,    -1,   393,    -1,
     394,    -1,   393,   394,    -1,   102,    -1,   103,    -1,    -1,
     396,    -1,   397,    -1,   396,   397,    -1,    64,   386,    -1,
      35,   386,    -1,    53,   386,    -1,    16,   414,   303,    -1,
     472,    -1,   427,    -1,   399,   401,    -1,    26,   400,   303,
     286,    -1,    26,   400,    -1,    -1,   214,    -1,   274,   402,
     275,    -1,   404,    -1,   404,    -1,   402,   276,   404,    -1,
      -1,   284,   304,   285,    -1,   202,   287,   277,   308,   278,
      -1,   201,   287,   277,   308,   278,    -1,   289,   277,   303,
     278,    -1,   205,   309,    -1,   158,   277,   306,   278,   403,
      -1,   159,   277,   306,   278,   403,    -1,   157,   277,   305,
     278,   403,    -1,   156,   277,   304,   278,   403,    -1,   155,
     277,   304,   278,   403,    -1,   154,   277,   304,   278,   403,
      -1,   158,   403,    -1,   159,   403,    -1,   157,   403,    -1,
     156,   403,    -1,   155,   403,    -1,   154,   403,    -1,    70,
     286,   309,    -1,    72,   284,   304,   285,   407,    74,   303,
      -1,    -1,   408,    -1,   409,    -1,   408,   409,    -1,   156,
      -1,   157,    -1,   203,    -1,   204,    -1,   411,    -1,   284,
     307,   285,    -1,   284,    48,   307,   285,    -1,   414,    -1,
     284,   307,   285,   413,    -1,   284,    40,   285,   413,    -1,
     284,    48,   307,   285,   413,    -1,   413,    -1,   410,    -1,
     307,    -1,   413,   290,   307,    -1,   196,   411,    -1,   110,
     196,   411,    -1,   244,   411,    -1,   245,   411,    -1,   414,
     284,   291,   285,    -1,   414,   284,   416,   285,    -1,   414,
     289,    -1,   414,   287,    -1,   414,   292,    -1,   414,   197,
      -1,   414,   198,   277,   411,   278,    -1,   414,   199,   277,
     411,   278,    -1,   195,   426,   414,   287,   277,   420,   278,
      -1,   200,    -1,   201,    -1,   202,    -1,   152,    -1,   153,
      -1,   154,    -1,   155,    -1,   156,    -1,   157,    -1,   158,
      -1,   159,    -1,   161,   154,    -1,   161,   155,    -1,   161,
     156,    -1,   161,   157,    -1,   136,   173,    -1,   136,   161,
     173,    -1,   136,   178,    -1,   246,    -1,   247,    -1,   293,
     304,    -1,   293,   293,   304,    -1,   414,   282,   415,   283,
      -1,   414,    -1,   415,   276,   414,    -1,   417,    -1,   416,
     276,   417,    -1,    -1,    11,    -1,   304,    -1,   304,    11,
     304,    -1,     8,    12,   304,    -1,   304,    11,    -1,     8,
      12,    -1,    -1,   145,   277,   308,   276,   308,   276,   308,
     276,   308,   278,    -1,   146,   147,   284,   304,   285,    -1,
     146,   148,   284,   304,   285,    -1,   149,    -1,   150,    -1,
     151,    -1,   152,    -1,   153,    -1,   154,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
     161,   154,    -1,   161,   155,    -1,   161,   156,    -1,   161,
     157,    -1,   418,   287,    -1,   418,   284,   285,    -1,   418,
     284,   304,   285,    -1,   418,   284,    65,    56,   286,   304,
     285,    -1,   418,   284,   281,   304,   285,    -1,   418,   284,
      65,    56,   286,   304,   287,   304,   285,    -1,   418,   284,
     304,   281,   304,   285,    -1,   162,    -1,   163,    -1,   164,
      -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,   169,
      -1,   170,    -1,   171,    -1,   112,    -1,   172,   419,    -1,
     173,    -1,   161,   173,    -1,   122,   171,    -1,   174,    -1,
     117,   164,    -1,   175,    -1,   149,   153,    -1,   195,    -1,
     176,    -1,    75,   177,    -1,   178,    -1,   179,    -1,    -1,
     180,    -1,   149,    -1,   150,    -1,   152,    -1,   153,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,
     159,    -1,   161,   154,    -1,   161,   155,    -1,   161,   156,
      -1,   161,   157,    -1,   419,   284,   285,    -1,   419,   181,
      -1,   419,   289,    -1,   162,    -1,   163,    -1,   164,    -1,
     165,    -1,   166,    -1,   169,    -1,   170,    -1,   172,    -1,
     173,    -1,   161,   173,    -1,   160,    -1,   182,    -1,   183,
      -1,   184,    -1,   185,    -1,   186,    -1,   187,    -1,   188,
      -1,   189,    -1,   190,    -1,   191,    -1,   192,    -1,   193,
      -1,   194,    -1,    -1,   421,    -1,   422,    -1,   421,   276,
     422,    -1,    11,    -1,   423,   342,    -1,   423,   342,   303,
      -1,    -1,   424,    -1,   284,   425,   285,    -1,   424,   284,
     425,   285,    -1,    92,    -1,    93,    -1,    94,    -1,    96,
      -1,   304,    -1,    -1,    82,   426,    -1,    83,   426,    -1,
      84,    -1,    85,    -1,    86,    87,    -1,    86,    88,    -1,
      86,    89,    -1,    86,    90,    -1,    41,     3,     6,    -1,
      41,     3,   288,     3,     6,    -1,    41,     3,     7,    -1,
      41,     3,   288,     3,     7,    -1,    41,     3,    -1,    41,
       3,   288,     3,    -1,    33,   429,   307,    36,   286,   309,
      -1,    33,   429,   307,    -1,    -1,   430,    -1,   431,    -1,
     430,   431,    -1,   231,    -1,   232,    -1,    30,   307,   277,
     308,   278,    74,   308,    -1,    30,   307,    74,   308,    -1,
      15,   436,   434,   435,    -1,   307,    -1,    40,    -1,    -1,
      75,   308,    -1,    -1,   437,    -1,   438,    -1,   437,   438,
      -1,   237,    -1,    78,    -1,    79,    -1,    80,    -1,   238,
      -1,   239,    -1,    -1,   440,    -1,   441,    -1,   440,   441,
      -1,    67,   308,   277,   308,   278,    -1,    67,   308,    -1,
      36,   233,   304,    -1,    36,    14,   304,    -1,   468,    -1,
     442,    -1,    51,   286,   309,    -1,    61,   286,   309,    -1,
      62,   286,   309,    -1,    69,   304,   288,   304,   288,   304,
     288,   304,    -1,    42,   308,    -1,    42,   286,   309,    -1,
      59,   304,    -1,    52,   304,    69,   304,   288,   304,    -1,
      22,   308,    -1,    22,   286,   309,    -1,   472,    -1,    15,
      81,   444,   434,    75,   308,    -1,    15,    81,   444,   434,
      -1,    -1,   445,    -1,   446,    -1,   445,   446,    -1,   234,
      -1,    -1,   448,    -1,   449,    -1,   448,   449,    -1,    36,
     286,   309,    -1,    30,   307,    -1,   442,    -1,   451,   453,
     307,   452,    -1,    20,    81,    -1,    31,    -1,    21,    -1,
      -1,   277,   308,   278,    -1,    -1,   454,    -1,   455,    -1,
     454,   455,    -1,    99,    -1,    98,    -1,   122,    98,    -1,
     122,    99,    -1,   122,   100,    -1,   122,   104,    -1,   122,
     105,    -1,   122,   106,    -1,    -1,   457,    -1,   458,    -1,
     457,   458,    -1,    33,   307,    -1,    15,    81,   307,    -1,
      21,   307,    -1,    20,   304,    -1,    30,   307,    -1,   472,
      -1,   460,   462,   307,   461,    -1,    44,    -1,    49,    -1,
      -1,   277,   308,   278,    -1,    -1,   463,    -1,   464,    -1,
     463,   464,    -1,    98,    -1,    99,    -1,    -1,   466,    -1,
     467,    -1,   466,   467,    -1,    47,   308,    -1,    47,   286,
     309,    -1,    33,   307,    74,   304,    -1,    15,    81,   307,
      -1,    42,   286,   309,    -1,   472,    -1,    57,   469,   411,
     277,   470,   278,    -1,    18,   469,     6,    -1,    18,   469,
     286,   309,    -1,    58,   469,     6,    -1,    58,   469,   286,
     309,    -1,   216,    -1,   217,    -1,   218,    -1,   219,    -1,
     220,    -1,   221,    -1,   222,    -1,   223,    -1,   224,    -1,
     225,    -1,   226,    -1,   227,    -1,   228,    -1,   229,    -1,
     230,    -1,   471,    -1,   471,   276,   470,    -1,     6,   286,
       6,    -1,    25,   473,    -1,    25,   473,   286,   308,    -1,
      25,   473,   286,   309,    -1,    25,   277,   474,   278,   473,
     286,   309,    -1,    25,   277,   474,   278,   473,   286,   308,
      -1,    25,   277,   474,   278,   473,    -1,   302,    -1,   386,
      -1,   410,    -1,   195,   386,    -1,   215,   414,   410,    10,
     303,    -1,   215,   414,   303,    -1,   254,    -1,   255,   304,
      -1,   255,   303,    -1,   256,   305,    -1,   257,   478,    -1,
     258,   304,    -1,   258,   303,    -1,   259,   387,    -1,   271,
     388,    -1,   260,   414,   410,    10,   303,    -1,   260,   414,
     303,    -1,   261,   410,    -1,   262,   308,    -1,   262,   205,
     309,    -1,   263,   426,   414,   277,   420,   278,    -1,   264,
     303,    -1,   264,   304,    -1,   265,   195,   386,    -1,   265,
     215,   414,   410,    10,   303,    -1,   265,   215,   414,   303,
      -1,   265,   410,    -1,    -1,   266,   476,   479,    -1,    -1,
     267,   277,   477,   481,   278,    -1,   306,    -1,   305,    -1,
     309,    -1,    -1,   480,    -1,   304,    -1,   480,   304,    -1,
      -1,   482,    -1,   483,    -1,   482,   276,   483,    -1,   303,
      -1,   304,    -1,   254,    -1,   255,   304,    -1,   269,   304,
     304,    -1,   256,   305,    -1,   268,   156,   277,   304,   278,
      -1,   268,   157,   277,   305,   278,    -1,   268,   158,   277,
     478,   278,    -1,   268,   159,   277,   478,   278,    -1,   268,
     308,    -1,   258,   304,    -1,   258,   303,    -1,   259,   386,
      -1,   259,   308,   308,   308,    -1,   260,   414,   410,    10,
     303,    -1,   260,   308,   308,   308,    -1,   261,   410,    -1,
     261,   308,    -1,   271,   386,   304,    -1,   271,   308,   308,
     308,   304,    -1,   272,   487,    -1,   273,   410,   304,    -1,
     273,   308,   304,    -1,    -1,   267,   490,   277,   304,   288,
     485,   488,   278,    -1,    -1,   270,   494,   277,   486,   492,
     278,    -1,   153,    -1,   202,    -1,   158,    -1,   159,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,    -1,   489,
      -1,   491,    -1,   489,   276,   491,    -1,   303,    -1,   304,
      -1,   303,    -1,   304,    -1,    -1,   493,    -1,   495,    -1,
     493,   276,   495,    -1,   303,    -1,   304,    -1,   304,   288,
     303,    -1,   304,   288,   304,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1074,  1074,  1080,  1082,  1086,  1087,  1091,  1094,  1094,
    1099,  1100,  1100,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1129,  1130,
    1131,  1132,  1136,  1137,  1138,  1146,  1147,  1151,  1155,  1163,
    1168,  1176,  1188,  1203,  1218,  1236,  1237,  1244,  1250,  1251,
    1257,  1257,  1275,  1280,  1310,  1316,  1324,  1340,  1340,  1350,
    1351,  1355,  1356,  1364,  1381,  1401,  1402,  1406,  1407,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1440,  1444,  1450,  1452,  1456,
    1462,  1471,  1472,  1476,  1477,  1481,  1482,  1482,  1489,  1492,
    1493,  1494,  1495,  1496,  1497,  1498,  1499,  1518,  1537,  1538,
    1578,  1577,  1678,  1680,  1683,  1685,  1689,  1690,  1694,  1695,
    1699,  1700,  1704,  1705,  1709,  1713,  1718,  1722,  1725,  1729,
    1730,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1786,
    1787,  1788,  1789,  1790,  1791,  1792,  1793,  1802,  1810,  1821,
    1827,  1833,  1842,  1855,  1864,  1877,  1886,  1899,  1908,  1921,
    1934,  1943,  1950,  1956,  1963,  1969,  1975,  1979,  1984,  1988,
    2004,  2101,  2106,  2113,  2114,  2115,  2119,  2121,  2125,  2126,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2179,
    2185,  2194,  2195,  2199,  2200,  2204,  2205,  2206,  2207,  2208,
    2209,  2210,  2211,  2212,  2213,  2214,  2218,  2219,  2223,  2224,
    2228,  2229,  2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,
    2238,  2239,  2240,  2244,  2248,  2255,  2256,  2260,  2261,  2262,
    2263,  2266,  2270,  2274,  2276,  2277,  2278,  2279,  2280,  2281,
    2282,  2283,  2284,  2285,  2310,  2311,  2322,  2351,  2355,  2362,
    2363,  2367,  2368,  2369,  2370,  2371,  2372,  2373,  2374,  2375,
    2376,  2380,  2380,  2393,  2395,  2399,  2405,  2409,  2413,  2414,
    2416,  2423,  2427,  2432,  2436,  2443,  2447,  2448,  2449,  2453,
    2457,  2461,  2462,  2464,  2471,  2471,  2482,  2484,  2488,  2494,
    2498,  2502,  2503,  2505,  2512,  2516,  2523,  2524,  2526,  2535,
    2546,  2563,  2564,  2568,  2569,  2573,  2574,  2578,  2579,  2583,
    2584,  2588,  2591,  2594,  2597,  2600,  2601,  2609,  2616,  2626,
    2638,  2654,  2667,  2684,  2685,  2689,  2705,  2729,  2744,  2745,
    2749,  2750,  2754,  2755,  2759,  2760,  2764,  2765,  2769,  2772,
    2775,  2778,  2779,  2780,  2788,  2792,  2796,  2800,  2801,  2805,
    2806,  2810,  2811,  2815,  2816,  2820,  2823,  2826,  2830,  2833,
    2836,  2839,  2842,  2845,  2848,  2851,  2854,  2857,  2860,  2863,
    2866,  2876,  2880,  2884,  2885,  2889,  2890,  2894,  2895,  2896,
    2897,  2905,  2912,  2917,  2922,  2959,  2983,  3000,  3013,  3020,
    3026,  3027,  3037,  3038,  3039,  3040,  3041,  3045,  3048,  3051,
    3054,  3058,  3061,  3067,  3073,  3076,  3077,  3078,  3079,  3080,
    3081,  3082,  3083,  3084,  3085,  3086,  3087,  3088,  3089,  3090,
    3091,  3092,  3093,  3094,  3095,  3096,  3101,  3106,  3114,  3125,
    3135,  3136,  3148,  3149,  3150,  3154,  3159,  3164,  3168,  3175,
    3176,  3186,  3191,  3198,  3199,  3200,  3201,  3202,  3203,  3204,
    3205,  3206,  3207,  3208,  3209,  3210,  3211,  3212,  3213,  3214,
    3218,  3226,  3234,  3243,  3251,  3260,  3268,  3269,  3270,  3271,
    3272,  3273,  3274,  3275,  3276,  3277,  3278,  3279,  3284,  3285,
    3286,  3287,  3288,  3289,  3290,  3291,  3292,  3293,  3294,  3295,
    3299,  3300,  3301,  3302,  3303,  3304,  3305,  3306,  3307,  3308,
    3309,  3310,  3311,  3312,  3313,  3314,  3315,  3316,  3317,  3318,
    3319,  3320,  3321,  3322,  3323,  3324,  3325,  3326,  3327,  3328,
    3329,  3330,  3331,  3332,  3333,  3334,  3335,  3336,  3337,  3338,
    3339,  3340,  3341,  3349,  3350,  3354,  3355,  3363,  3379,  3394,
    3412,  3413,  3417,  3418,  3422,  3423,  3424,  3425,  3426,  3434,
    3435,  3436,  3437,  3438,  3439,  3440,  3441,  3442,  3450,  3453,
    3456,  3459,  3462,  3465,  3472,  3487,  3501,  3502,  3506,  3507,
    3511,  3512,  3516,  3517,  3525,  3537,  3547,  3553,  3555,  3559,
    3560,  3564,  3565,  3569,  3570,  3571,  3572,  3573,  3574,  3578,
    3579,  3583,  3584,  3588,  3589,  3590,  3593,  3596,  3597,  3601,
    3604,  3607,  3610,  3627,  3644,  3661,  3680,  3701,  3702,  3703,
    3707,  3719,  3733,  3734,  3738,  3739,  3743,  3747,  3748,  3752,
    3753,  3757,  3765,  3766,  3774,  3787,  3788,  3789,  3792,  3794,
    3798,  3799,  3803,  3804,  3808,  3809,  3810,  3811,  3812,  3813,
    3814,  3815,  3819,  3820,  3824,  3825,  3829,  3841,  3852,  3873,
    3883,  3884,  3892,  3907,  3908,  3911,  3913,  3917,  3918,  3922,
    3923,  3927,  3928,  3932,  3933,  3937,  3938,  3942,  3943,  3944,
    3956,  3967,  3968,  3976,  3977,  3981,  3984,  3988,  3994,  3995,
    3996,  3997,  3998,  3999,  4000,  4001,  4002,  4003,  4004,  4005,
    4006,  4007,  4008,  4012,  4013,  4017,  4025,  4026,  4029,  4032,
    4035,  4038,  4041,  4047,  4051,  4052,  4053,  4057,  4069,  4070,
    4071,  4072,  4073,  4084,  4085,  4086,  4087,  4088,  4094,  4102,
    4114,  4115,  4116,  4126,  4131,  4136,  4137,  4143,  4150,  4162,
    4162,  4168,  4168,  4177,  4178,  4183,  4219,  4221,  4225,  4226,
    4229,  4231,  4235,  4236,  4240,  4241,  4245,  4246,  4247,  4248,
    4249,  4250,  4251,  4254,  4257,  4258,  4259,  4260,  4261,  4264,
    4270,  4273,  4285,  4286,  4290,  4294,  4295,  4298,  4301,  4301,
    4307,  4307,  4316,  4317,  4318,  4319,  4320,  4321,  4322,  4323,
    4326,  4328,  4332,  4333,  4337,  4338,  4342,  4343,  4346,  4348,
    4352,  4353,  4357,  4358,  4362,  4363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"integer value\"", "\"identifier\"",
  "\".identifier\"", "\"single-quoted string\"",
  "\"double-quoted string\"", "\"floating point value\"",
  "\"hexadecimal byte\"", "\"::\"", "\"...\"", "\"..\"", "\"`.addon'\"",
  "\"`.algorithm'\"", "\"`.assembly'\"", "\"`.backing'\"", "\"`.blob'\"",
  "\"`.capability'\"", "\"`.cctor'\"", "\"`.class'\"", "\"`.comtype'\"",
  "\"`.config'\"", "\"`.corflags'\"", "\"`.ctor'\"", "\"`.custom'\"",
  "\"`.data'\"", "\"`.emitbyte'\"", "\"`.entrypoint'\"", "\"`.event'\"",
  "\"`.exeloc'\"", "\"`.export'\"", "\"`.field'\"", "\"`.file'\"",
  "\"`.fire'\"", "\"`.get'\"", "\"`.hash'\"", "\"`.imagebase'\"",
  "\"`.implicitcom'\"", "\"`.language'\"", "\"`.library'\"", "\"`.line'\"",
  "\"`.locale'\"", "\"`.locals'\"", "\"`.manifestres'\"",
  "\"`.maxstack'\"", "\"`.method'\"", "\"`.mime'\"", "\"`.module'\"",
  "\"`.mresource'\"", "\"`.namespace'\"", "\"`.originator'\"", "\"`.os'\"",
  "\"`.other'\"", "\"`.override'\"", "\"`.pack'\"", "\"`.param'\"",
  "\"`.permission'\"", "\"`.permissionset'\"", "\"`.processor'\"",
  "\"`.property'\"", "\"`.publickey'\"", "\"`.publickeytoken'\"",
  "\"`.removeon'\"", "\"`.set'\"", "\"`.size'\"", "\"`.subsystem'\"",
  "\"`.title'\"", "\"`.try'\"", "\"`.ver'\"", "\"`.vtable'\"",
  "\"`.vtentry'\"", "\"`.vtfixup'\"", "\"`.zeroinit'\"", "\"`at'\"",
  "\"`as'\"", "\"`implicitcom'\"", "\"`implicitres'\"",
  "\"`noappdomain'\"", "\"`noprocess'\"", "\"`nomachine'\"",
  "\"`extern'\"", "\"`instance'\"", "\"`explicit'\"", "\"`default'\"",
  "\"`vararg'\"", "\"`unmanaged'\"", "\"`cdecl'\"", "\"`stdcall'\"",
  "\"`thiscall'\"", "\"`fastcall'\"", "\"`marshal'\"", "\"`in'\"",
  "\"`out'\"", "\"`opt'\"", "\"`lcid'\"", "\"`retval'\"", "\"`static'\"",
  "\"`public'\"", "\"`private'\"", "\"`family'\"", "\"`initonly'\"",
  "\"`rtspecialname'\"", "\"`specialname'\"", "\"`assembly'\"",
  "\"`famandassem'\"", "\"`famorassem'\"", "\"`privatescope'\"",
  "\"`literal'\"", "\"`notserialized'\"", "\"`value'\"",
  "\"`not_in_gc_heap'\"", "\"`interface'\"", "\"`sealed'\"",
  "\"`abstract'\"", "\"`auto'\"", "\"`sequential'\"", "\"`ansi'\"",
  "\"`unicode'\"", "\"`autochar'\"", "\"`import'\"", "\"`serializable'\"",
  "\"`nested'\"", "\"`lateinit'\"", "\"`extends'\"", "\"`implements'\"",
  "\"`final'\"", "\"`virtual'\"", "\"`hidebysig'\"", "\"`newslot'\"",
  "\"`unmanagedexp'\"", "\"`pinvokeimpl'\"", "\"`nomangle'\"", "\"`ole'\"",
  "\"`lasterr'\"", "\"`winapi'\"", "\"`native'\"", "\"`il'\"",
  "\"`optil'\"", "\"`managed'\"", "\"`forwardref'\"", "\"`runtime'\"",
  "\"`internalcall'\"", "\"`synchronized'\"", "\"`noinlining'\"",
  "\"`custom'\"", "\"`fixed'\"", "\"`sysstring'\"", "\"`array'\"",
  "\"`variant'\"", "\"`currency'\"", "\"`syschar'\"", "\"`void'\"",
  "\"`bool'\"", "\"`int8'\"", "\"`int16'\"", "\"`int32'\"", "\"`int64'\"",
  "\"`float32'\"", "\"`float64'\"", "\"`error'\"", "\"`unsigned'\"",
  "\"`decimal'\"", "\"`date'\"", "\"`bstr'\"", "\"`lpstr'\"",
  "\"`lpwstr'\"", "\"`lptstr'\"", "\"`objectref'\"", "\"`iunknown'\"",
  "\"`idispatch'\"", "\"`struct'\"", "\"`safearray'\"", "\"``int''\"",
  "\"`byvalstr'\"", "\"`tbstr'\"", "\"`lpvoid'\"", "\"`any'\"",
  "\"`float'\"", "\"`lpstruct'\"", "\"`null'\"", "\"`vector'\"",
  "\"`hresult'\"", "\"`carray'\"", "\"`userdefined'\"", "\"`record'\"",
  "\"`filetime'\"", "\"`blob'\"", "\"`stream'\"", "\"`storage'\"",
  "\"`streamed_object'\"", "\"`stored_object'\"", "\"`blob_object'\"",
  "\"`cf'\"", "\"`clsid'\"", "\"`method'\"", "\"`class'\"", "\"`pinned'\"",
  "\"`modreq'\"", "\"`modopt'\"", "\"`typedref'\"", "\"`wchar'\"",
  "\"`char'\"", "\"`fromunmanaged'\"", "\"`callmostderived'\"",
  "\"`bytearray'\"", "\"`with'\"", "\"`init'\"", "\"`to'\"", "\"`catch'\"",
  "\"`filter'\"", "\"`finally'\"", "\"`fault'\"", "\"`handler'\"",
  "\"`tls'\"", "\"`field'\"", "\"`request'\"", "\"`demand'\"",
  "\"`assert'\"", "\"`deny'\"", "\"`permitonly'\"", "\"`linkcheck'\"",
  "\"`inheritcheck'\"", "\"`reqmin'\"", "\"`reqopt'\"", "\"`reqrefuse'\"",
  "\"`prejitgrant'\"", "\"`prejitdeny'\"", "\"`noncasdemand'\"",
  "\"`noncaslinkdemand'\"", "\"`noncasinheritance'\"", "\"`readonly'\"",
  "\"`nometadata'\"", "\"`algorithm'\"", "\"`fullorigin'\"", "\"`nan'\"",
  "\"`inf'\"", "\"`publickey'\"", "\"`enablejittracking'\"",
  "\"`disablejitoptimizer'\"", "\"`preservesig'\"",
  "\"`beforefieldinit'\"", "\"`compilercontrolled'\"", "\"`cil'\"",
  "\"`valuetype'\"", "\"`boxed'\"", "\"`string'\"", "\"`object'\"",
  "\"`alignment'\"", "\"`reqsecobj'\"", "\"`true'\"", "\"`false'\"",
  "\"`java'\"", "\"`nullref'\"", "I_NONE", "I_VAR", "I_INT", "I_FLOAT",
  "I_BRANCH", "I_METHOD", "I_FIELD", "I_TYPE", "I_STRING", "I_SIGNATURE",
  "I_RVA", "I_TOKEN", "I_SSA", "I_SWITCH", "I_CONST", "I_IINC",
  "I_LSWITCH", "I_IMETHOD", "I_NEWARRAY", "I_MULTINEWARRAY", "'{'", "'}'",
  "','", "'('", "')'", "'-'", "'.'", "'+'", "'<'", "'>'", "'['", "']'",
  "'='", "'*'", "':'", "'&'", "'/'", "'?'", "'%'", "'!'", "$accept",
  "File", "Declarations", "DeclarationList", "Declaration", "@1", "@2",
  "CommentDeclaration", "LanguageDeclaration", "Identifier", "Integer32",
  "Integer64", "Float64", "QualifiedName", "ComposedString", "Bytes", "@3",
  "ByteList", "ModuleHeading", "ClassHeading", "@4",
  "FormalGenericParamsOpt", "FormalGenericParams", "FormalGenericParam",
  "ClassAttributes", "ClassAttributeList", "ClassAttributeName",
  "ExtendsClause", "ImplementsClause", "ClassNameList",
  "ClassDeclarations", "ClassDeclarationList", "ClassDeclaration", "@5",
  "FieldDeclaration", "@6", "FieldBody", "FieldBodyDeclarations",
  "FieldBodyDeclarationList", "FieldBodyDeclaration", "LayoutOption",
  "AtOption", "InitOption", "FieldAttributes", "FieldAttributeList",
  "FieldAttributeName", "FieldInitialization", "MethodHeading",
  "MarshalledType", "MethodName", "MethodAttributes",
  "MethodAttributeList", "MethodAttributeName", "PInvokeAttributes",
  "PInvokeAttributeList", "PInvokeAttributeName",
  "ImplementationAttributes", "ImplementationAttributeList",
  "ImplementationAttributeName", "MethodDeclarations",
  "MethodDeclarationList", "MethodDeclaration", "JavaMethodDeclarations",
  "JavaMethodDeclarationList", "JavaMethodDeclaration", "ScopeBlock", "@7",
  "ScopeDeclarations", "ExceptionBlock", "ExceptionClauses", "TryBlock",
  "ExceptionClause", "CatchClause", "FilterClause", "FinallyClause",
  "FaultClause", "HandlerBlock", "JavaScopeBlock", "@8",
  "JavaScopeDeclarations", "JavaExceptionBlock", "JavaExceptionClauses",
  "JavaTryBlock", "JavaExceptionClause", "JavaHandlerBlock",
  "EventHeading", "EventAttributes", "EventAttributeList",
  "EventAttributeName", "EventDeclarations", "EventDeclarationList",
  "EventDeclaration", "MethodReference", "GenericMethodReference",
  "InstanceMethodReference", "MethodRefGenericParamsOpt",
  "MethodRefGenericParams", "PropertyHeading", "PropertyAttributes",
  "PropertyAttributeList", "PropertyAttributeName", "PropertyDeclarations",
  "PropertyDeclarationList", "PropertyDeclaration", "DataDeclaration",
  "DataHeading", "DataTLS", "DataBody", "DataItemList", "DataItemCount",
  "DataItem", "VtableDeclaration", "VtfixupDeclaration",
  "VtfixupAttributes", "VtfixupAttributeList", "VtfixupAttributeName",
  "TypeSpecification", "ClassName", "ClassNameTypeSpec", "SlashedName",
  "Type", "ActualGenericParams", "ArrayBounds", "Bounds", "NativeType",
  "VariantType", "OptSignatureArguments", "SignatureArguments",
  "SignatureArgument", "ParameterAttributes", "ParameterAttributeList",
  "ParameterAttributeName", "CallingConventions",
  "ExternalSourceSpecification", "FileDeclaration", "FileAttributes",
  "FileAttributeList", "FileAttributeName", "ExeLocationDeclaration",
  "AssemblyHeading", "AssemblyName", "AltName", "AssemblyAttributes",
  "AssemblyAttributeList", "AssemblyAttributeName", "AssemblyDeclarations",
  "AssemblyDeclarationList", "AssemblyDeclaration", "AsmOrRefDeclaration",
  "AssemblyRefHeading", "AssemblyRefAttributes",
  "AssemblyRefAttributeList", "AssemblyRefAttributeName",
  "AssemblyRefDeclarations", "AssemblyRefDeclarationList",
  "AssemblyRefDeclaration", "ExportHeading", "ExportKeyword",
  "ExportAsName", "ComTypeAttributes", "ComTypeAttributeList",
  "ComTypeAttributeName", "ComTypeDeclarations", "ComTypeDeclarationList",
  "ComTypeDeclaration", "ManifestResHeading", "ManifestResKeyword",
  "ManifestResDescription", "ManifestResAttributes",
  "ManifestResAttributeList", "ManifestResAttributeName",
  "ManifestResDeclarations", "ManifestResDeclarationList",
  "ManifestResDeclaration", "SecurityDeclaration", "SecurityAction",
  "NameValuePairs", "NameValuePair", "CustomAttributeDeclaration",
  "CustomType", "CustomOwner", "Instruction", "@9", "@10",
  "InstructionFloat", "Integer16List", "Integer16List2", "SwitchLabels",
  "SwitchLabelList", "SwitchLabel", "JavaInstruction", "@11", "@12",
  "JavaArrayType", "TableSwitchLabels", "TableSwitchLabelList",
  "TableSwitchDefaultLabel", "TableSwitchLabel", "LookupSwitchLabels",
  "LookupSwitchLabelList", "LookupSwitchDefaultLabel", "LookupSwitchLabel", 0
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   123,   125,    44,    40,    41,    45,
      46,    43,    60,    62,    91,    93,    61,    42,    58,    38,
      47,    63,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   294,   295,   296,   296,   297,   297,   298,   299,   298,
     298,   300,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   301,   301,
     301,   301,   302,   302,   302,   303,   303,   304,   305,   306,
     306,   306,   306,   306,   306,   307,   307,   307,   308,   308,
     310,   309,   311,   311,   312,   312,   312,   314,   313,   315,
     315,   316,   316,   317,   317,   318,   318,   319,   319,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   321,   321,   322,   322,   323,
     323,   324,   324,   325,   325,   326,   327,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     329,   328,   330,   330,   331,   331,   332,   332,   333,   333,
     334,   334,   335,   335,   335,   336,   336,   337,   337,   338,
     338,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     341,   342,   342,   343,   343,   343,   344,   344,   345,   345,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   347,   347,   348,   348,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   350,   350,   351,   351,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   353,   353,   354,   354,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   356,   356,   357,
     357,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   360,   359,   361,   361,   362,   363,   363,   364,   364,
     364,   365,   365,   365,   365,   366,   367,   367,   367,   368,
     369,   370,   370,   370,   372,   371,   373,   373,   374,   375,
     375,   376,   376,   376,   377,   377,   378,   378,   378,   379,
     379,   380,   380,   381,   381,   382,   382,   383,   383,   384,
     384,   385,   385,   385,   385,   385,   385,   386,   386,   387,
     387,   388,   388,   389,   389,   390,   390,   391,   392,   392,
     393,   393,   394,   394,   395,   395,   396,   396,   397,   397,
     397,   397,   397,   397,   398,   399,   399,   400,   400,   401,
     401,   402,   402,   403,   403,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   405,   406,   407,   407,   408,   408,   409,   409,   409,
     409,   410,   410,   410,   410,   411,   411,   411,   411,   412,
     413,   413,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   415,   415,
     416,   416,   417,   417,   417,   417,   417,   417,   417,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   420,   420,   421,   421,   422,   422,   422,
     423,   423,   424,   424,   425,   425,   425,   425,   425,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   427,   427,
     427,   427,   427,   427,   428,   428,   429,   429,   430,   430,
     431,   431,   432,   432,   433,   434,   434,   435,   435,   436,
     436,   437,   437,   438,   438,   438,   438,   438,   438,   439,
     439,   440,   440,   441,   441,   441,   441,   441,   441,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     443,   443,   444,   444,   445,   445,   446,   447,   447,   448,
     448,   449,   449,   449,   450,   451,   451,   451,   452,   452,
     453,   453,   454,   454,   455,   455,   455,   455,   455,   455,
     455,   455,   456,   456,   457,   457,   458,   458,   458,   458,
     458,   458,   459,   460,   460,   461,   461,   462,   462,   463,
     463,   464,   464,   465,   465,   466,   466,   467,   467,   467,
     467,   467,   467,   468,   468,   468,   468,   468,   469,   469,
     469,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     469,   469,   469,   470,   470,   471,   472,   472,   472,   472,
     472,   472,   472,   473,   474,   474,   474,   474,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   476,
     475,   477,   475,   478,   478,   478,   479,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   484,   484,   484,   484,
     484,   484,   484,   484,   484,   484,   484,   484,   484,   484,
     484,   484,   484,   484,   484,   484,   484,   484,   485,   484,
     486,   484,   487,   487,   487,   487,   487,   487,   487,   487,
     488,   488,   489,   489,   490,   490,   491,   491,   492,   492,
     493,   493,   494,   494,   495,   495
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     2,     4,     0,     6,
       4,     0,     6,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     1,     1,     1,     1,     2,     2,
       2,     3,     2,     4,     6,     1,     1,     1,     1,     1,
       4,     4,     1,     1,     2,     1,     3,     2,     1,     3,
       0,     4,     1,     2,     1,     2,     3,     0,     7,     0,
       3,     1,     3,     4,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     0,     2,     0,     2,     1,
       3,     0,     1,     1,     2,     4,     0,     6,     4,     4,
       4,     1,     1,     1,     1,     1,     2,     2,     4,    13,
       0,     9,     0,     3,     0,     1,     1,     2,     1,     1,
       0,     3,     0,     2,     2,     0,     2,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     7,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     4,
       4,     4,     4,     4,     4,     4,     1,     5,     2,     1,
      11,     1,     5,     1,     1,     1,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     5,
       4,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     2,     1,     2,
       4,     5,     6,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     4,     4,     1,     4,     6,     0,     1,     1,
       2,     2,     2,     1,     1,     1,     2,     2,     1,     1,
       1,     0,     4,     0,     1,     2,     2,     1,     2,     4,
       4,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     4,     4,     0,     4,     0,     1,     2,     2,
       1,     2,     4,     4,     2,     2,     1,     2,     2,     4,
       3,     0,     1,     1,     2,     1,     1,     0,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     8,     6,     9,
       7,     9,     7,     0,     3,     1,     3,     8,     0,     1,
       1,     2,     1,     1,     0,     1,     1,     2,     2,     2,
       2,     3,     1,     1,     2,     4,     2,     0,     1,     3,
       1,     1,     3,     0,     3,     5,     5,     4,     2,     5,
       5,     5,     5,     5,     5,     2,     2,     2,     2,     2,
       2,     3,     7,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     4,     1,     4,     4,     5,     1,     1,
       1,     3,     2,     3,     2,     2,     4,     4,     2,     2,
       2,     2,     5,     5,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     3,     2,     1,     1,     2,     3,     4,     1,     3,
       1,     3,     0,     1,     1,     3,     3,     2,     2,     0,
      10,     5,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       3,     4,     7,     5,     9,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     1,     2,     1,     1,     2,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     3,     1,     2,     3,
       0,     1,     3,     4,     1,     1,     1,     1,     1,     0,
       2,     2,     1,     1,     2,     2,     2,     2,     3,     5,
       3,     5,     2,     4,     6,     3,     0,     1,     1,     2,
       1,     1,     7,     4,     4,     1,     1,     0,     2,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     2,     5,     2,     3,     3,     1,     1,     3,
       3,     3,     8,     2,     3,     2,     6,     2,     3,     1,
       6,     4,     0,     1,     1,     2,     1,     0,     1,     1,
       2,     3,     2,     1,     4,     2,     1,     1,     0,     3,
       0,     1,     1,     2,     1,     1,     2,     2,     2,     2,
       2,     2,     0,     1,     1,     2,     2,     3,     2,     2,
       2,     1,     4,     1,     1,     0,     3,     0,     1,     1,
       2,     1,     1,     0,     1,     1,     2,     2,     3,     4,
       3,     3,     1,     6,     3,     4,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     4,     4,     7,
       7,     5,     1,     1,     1,     2,     5,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     5,     3,     2,
       2,     3,     6,     2,     2,     3,     6,     4,     2,     0,
       3,     0,     5,     1,     1,     1,     0,     1,     1,     2,
       0,     1,     1,     3,     1,     1,     1,     2,     3,     2,
       5,     5,     5,     5,     2,     2,     2,     2,     4,     5,
       4,     2,     2,     3,     5,     2,     3,     3,     0,     8,
       0,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     3,     1,     1,     1,     1,     0,     1,
       1,     3,     1,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,   599,     0,    65,   647,     0,   569,   367,     0,   646,
     130,   586,     0,     0,     0,   673,   186,    54,   674,     0,
       0,     0,     0,     0,     0,     0,     2,     4,     5,    27,
     722,    24,     0,    13,     0,    14,     0,    15,    16,    17,
      18,    19,     0,     0,     0,   650,     0,   677,    25,    26,
     604,   605,   606,   632,   603,   607,   608,     0,   600,   601,
     698,   699,   700,   701,   702,   703,   704,   705,   706,   707,
     708,   709,   710,   711,   712,     0,   645,    79,    72,    69,
      70,    94,    93,    71,    73,    74,    75,    76,    77,    78,
      80,    81,    82,    83,    84,     0,    91,    92,     0,    66,
      67,    29,   569,   569,   572,   573,     0,     0,   723,     0,
     716,   368,   366,    35,    36,    45,     0,     0,   137,   590,
     591,     0,     0,   587,   588,    30,    32,   582,   190,   191,
     192,   193,   205,   195,   198,   199,   200,   201,   197,   194,
     196,   203,   204,   207,     0,   202,   206,   569,   187,   188,
       0,    55,     8,     0,     0,    28,     0,     0,     1,     6,
     101,     0,   243,   373,   373,   373,   373,   373,   373,     0,
       0,     0,     0,     0,   364,   370,   609,   637,   662,   655,
     654,     0,     0,   651,   652,   683,   681,   682,     0,   678,
     679,   636,     0,   633,   634,   596,   595,   597,   602,   694,
       0,    85,    86,    87,    88,    89,    90,    59,    68,   570,
     571,   574,   575,   576,   577,     0,     0,   428,   429,   430,
     431,   432,   433,   434,   435,     0,   569,     0,   425,   426,
     427,     0,     0,     0,   443,   444,     0,     0,   410,   724,
     401,   408,   404,     0,   569,     0,     0,     0,    47,     0,
       0,     0,    37,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   149,   150,   151,   152,   154,   155,     0,   153,
       0,   138,   139,    31,   585,   589,     0,   578,   580,     0,
     211,   560,   189,    56,     0,     0,     0,   696,     0,    50,
     391,     0,   321,     0,     0,   348,     0,     0,     0,   102,
     103,   111,     0,     0,     0,   112,   114,     0,   113,   115,
      11,     0,   253,     0,     0,     0,     0,     0,     0,   254,
     728,     0,     0,     0,     0,   569,     0,     0,     0,   569,
       0,     0,   749,     0,   569,   281,     0,     0,     0,   244,
     245,   264,   248,     0,   255,   260,   259,   261,   256,     0,
       0,   390,     0,   389,     0,   388,     0,   387,     0,   385,
       0,   386,     0,     0,   378,     0,   371,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,   618,   617,   629,     0,     0,   643,     0,   638,   639,
       0,     0,     0,     0,     0,     0,   663,   664,   671,   656,
     657,   658,   659,   660,   661,   648,   653,     0,     0,     0,
       0,     0,   684,   685,   692,   675,   680,   631,   635,     0,
     594,   695,     0,    95,     0,     0,   440,   442,   436,   437,
     438,   439,   725,     0,   412,     0,   414,   415,     0,     0,
       0,     0,   445,     0,   421,     0,     0,     0,   452,   419,
     418,   420,   569,     0,   184,   183,   452,   185,     0,     0,
      48,   717,   718,   365,   593,     0,    46,   131,   459,   211,
       0,   140,     0,    33,   583,   222,   223,   224,   225,   216,
     217,   218,   215,   219,   220,   221,   211,     0,   212,   213,
       0,     0,   561,     3,     0,     0,     0,   697,     0,   393,
     325,   326,     0,   322,   323,     0,   117,   352,   353,   569,
     349,   350,   116,   101,     7,   104,     0,   243,   327,   354,
     662,   267,   247,     0,   560,     0,   249,     0,     0,     0,
       0,   288,     0,   730,   729,    38,   731,    39,     0,     0,
      42,    43,     0,   754,   753,   755,   732,   734,   733,   735,
       0,     0,   739,     0,   740,     0,   743,   744,   569,     0,
     748,   756,   751,   736,     0,   283,   257,   258,    10,   246,
       0,     0,   299,   300,   285,   287,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   369,
       0,     0,     0,   627,     0,     0,     0,   623,     0,     0,
     625,     0,     0,   614,     0,    20,   612,   642,     0,    21,
     640,     0,   669,   668,   670,   666,    22,   665,     0,   644,
       0,     0,     0,     0,   687,    23,   686,     0,   672,     0,
     598,     0,    64,     0,    61,     0,    57,   413,   441,     0,
      45,     0,     0,     0,   402,   446,   411,     0,     0,   448,
       0,     0,   453,     0,   454,     0,   450,   721,     0,   560,
       0,     0,     0,     0,   496,     0,     0,     0,     0,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,     0,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   510,   498,   501,   503,   506,   508,   509,   505,
       0,   211,     0,   132,     0,     0,   579,   581,     0,     0,
     210,   214,   564,   565,   566,   567,   568,     0,     0,   181,
       0,     0,     0,     0,     0,     0,   713,    52,     0,   397,
     398,   399,   400,     0,   394,   395,    45,     0,   324,     0,
       0,   351,     0,   106,     0,   569,   569,   569,   569,     0,
     328,   329,   335,   336,     0,   569,   569,   569,     0,   355,
     356,   363,   362,     0,     0,     0,     0,   766,     0,     0,
       0,   569,     0,     0,     0,     0,     0,     0,   569,     0,
       0,   304,     0,     0,     0,   268,   269,   275,   274,     0,
     279,   278,   280,   273,   560,   557,     0,   554,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
     738,     0,   741,     0,   745,     0,   758,   750,   757,   760,
       0,   284,     0,   295,   297,   298,   296,   286,     0,   301,
     291,   292,   293,   294,   373,   374,   373,   373,   373,   373,
     373,     0,     0,   372,   377,   628,   616,   615,   624,   619,
       0,   620,   621,     0,     0,   641,   667,     0,   690,     0,
     691,   688,     0,   630,     0,     0,    60,   409,    96,    97,
     419,     0,   406,   403,   405,     0,     0,     0,   447,   458,
     416,   457,   452,   417,     0,     0,   185,     0,    49,     0,
     507,   502,   500,     0,     0,     0,   504,   475,   476,   477,
     478,   499,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   539,     0,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   511,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   497,   148,     0,
     479,     0,     0,   158,     0,   135,   584,    34,   211,   209,
     562,    59,     0,     0,     9,     0,     0,   693,     0,    53,
      51,     0,   396,   319,     0,     0,   108,   267,   105,   331,
     333,   334,   332,   109,   330,     0,   359,   360,   358,   110,
     357,   118,   272,   271,     0,     0,   311,   767,   769,   776,
     775,     0,   777,     0,     0,   782,   781,   804,   805,     0,
       0,     0,     0,     0,   774,     0,   812,   813,     0,     0,
       0,   792,   796,   797,   798,   799,   794,   795,   793,   785,
       0,     0,   306,   276,   277,    12,   270,     0,     0,   308,
     310,     0,   250,   560,   558,     0,   263,   265,   289,   290,
     262,     0,     0,   343,     0,     0,   560,   747,     0,   759,
     764,   765,     0,   761,   762,   343,     0,   282,     0,     0,
     384,   383,   382,   381,   379,   380,   376,   375,     0,     0,
       0,   649,   689,   676,     0,    62,     0,    58,   560,   726,
     407,   422,   423,   449,   456,   455,   451,   720,   719,   338,
     560,   592,     0,     0,     0,   522,   523,   524,   525,   538,
     527,     0,   528,     0,     0,   480,     0,   211,   157,   133,
     134,     0,   120,     0,     0,   459,   563,   715,   714,   392,
     569,     0,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   768,   790,     0,   783,   787,   786,
     307,     0,     0,   316,   314,   315,   309,   251,   556,   559,
       0,     0,    40,    41,     0,     0,     0,   737,     0,     0,
     752,     0,     0,     0,     0,     0,     0,   613,     0,    63,
      98,    99,     0,     0,     0,     0,     0,   526,     0,     0,
       0,   481,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,   176,   136,   122,   208,   560,     0,
       0,   560,   107,   312,   313,   778,   780,     0,     0,     0,
       0,     0,     0,   808,     0,   305,   317,   318,   252,   266,
       0,   345,   560,   343,   742,   746,   763,   560,   343,   302,
     303,   626,     0,     0,   424,   337,     0,   461,   462,     0,
     483,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   178,   124,   121,     0,   182,     0,     0,   779,
     788,   770,   771,   772,   773,     0,     0,   809,   810,   784,
       0,   344,     0,     0,     0,     0,     0,   100,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   126,   128,   129,   226,     0,   347,   800,     0,   791,
       0,   346,   340,   560,   342,   560,   622,     0,   482,     0,
     174,   175,   172,   171,   170,   169,   159,   163,   165,     0,
     161,   160,   164,   166,     0,   162,     0,   173,   123,   127,
     235,   237,   230,   231,   233,   234,   236,   239,   240,   241,
     242,   238,   232,   180,   227,   228,     0,   806,   807,     0,
     801,   802,   814,   815,   811,     0,     0,     0,     0,   167,
     168,   177,   229,     0,   789,     0,   339,   341,     0,   484,
     560,   803,   460,     0,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,   284,   521,    29,    30,   115,
     337,   543,   544,   238,  1194,   545,   498,   728,    31,    32,
     869,   423,   633,   634,    98,    99,   100,   636,  1077,  1170,
     298,   299,   300,   967,    33,  1196,  1254,  1299,  1300,  1301,
     118,   945,  1112,   270,   271,   272,  1195,    34,   718,   458,
     147,   148,   149,   487,   488,   489,  1353,  1354,  1355,   338,
     339,   340,   784,   785,   786,   341,   565,   822,   342,   574,
     343,   575,   576,   577,   578,   579,   830,   787,  1022,  1141,
     788,  1029,   789,  1030,  1144,   303,   502,   503,   504,   749,
     750,   751,   108,   549,   563,  1155,  1220,   304,   509,   510,
     511,   758,   759,   760,   344,    36,   112,   174,   365,   351,
     175,    37,    38,   733,   734,   735,   867,   240,   868,   241,
     242,   650,   655,   656,   700,   937,   796,   797,   798,   799,
     492,   717,   109,   345,    40,   122,   123,   124,    41,    42,
     197,   420,    57,    58,    59,   378,   379,   380,   381,    43,
     192,   193,   194,   387,   388,   389,    44,    45,   619,   182,
     183,   184,   395,   396,   397,    46,    47,   628,   188,   189,
     190,   411,   412,   413,   346,    75,   725,   726,   347,   110,
     243,   348,   561,   819,   546,   817,   818,  1052,  1053,  1054,
     793,  1307,  1213,  1019,  1359,  1360,   999,  1361,  1266,  1267,
    1008,  1268
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -991
static const yytype_int16 yypact[] =
{
    2018,   360,  1637,  1796,  -991,   100,   125,   -60,   252,  -991,
    -144,   -98,   159,   164,   189,  -991,  1067,   123,  -991,   252,
    1637,  1637,   209,   -63,    61,   276,  -991,  2018,  -991,  -991,
    -991,  -991,    76,  -991,  -139,  -991,  1004,  -991,  -991,  -991,
    -991,  -991,   137,   141,   186,    47,   206,   256,  -991,  -991,
    -991,  -991,  -991,   145,  -991,  -991,  -991,   126,   367,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,    28,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,   483,  -991,  -991,   252,  1841,
    -991,  -991,   799,   799,  -991,  -991,   608,  1391,  -991,  1691,
      88,  -991,   252,  -991,  -991,  -991,   114,   430,   738,  -991,
    -991,   487,   252,   -49,  -991,  -991,   219,    50,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   240,  -991,  -991,   799,  1067,  -991,
     252,    87,    87,    25,    55,  -991,   254,   430,  -991,  -991,
    2155,   238,  1755,   -82,   -81,   -57,   -52,   111,   140,   242,
     246,   254,   798,   260,  -991,  -991,  2110,  2175,   604,  -991,
    -991,   797,   252,    47,  -991,   513,  -991,  -991,   252,   256,
    -991,  -991,   126,   145,  -991,  -991,    87,   469,  -991,  -991,
     254,  -991,  -991,  -991,  -991,  -991,  -991,   269,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,   357,    73,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,   618,   799,    25,  -991,  -991,
    -991,  1691,    25,    25,  -991,  -991,   275,    13,    87,  -991,
    -991,   266,   524,   281,   799,  1090,   105,   282,  -991,   566,
     566,   252,  -991,   293,   313,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   315,  -991,
    1691,   738,  -991,  -991,    48,  -991,   590,  -991,  -991,   610,
    1299,   336,  -991,    87,   349,   445,   353,  -991,   254,  -991,
    -991,   341,   136,  1492,   430,   193,   430,   354,   358,  2155,
    -991,  -991,  -136,   362,   365,  -991,  -991,   366,  -991,  -991,
    -991,   430,  -991,   -76,   430,  1492,   361,   118,   430,  -991,
    -991,   468,   638,   133,   468,   799,  1691,  1492,    83,   799,
     468,  1424,  -991,   371,   799,  -991,   356,   370,   375,  1755,
    -991,  -991,  -991,   622,  -991,  -991,  -991,  -991,  -991,   430,
     430,  -991,   430,  -991,   430,  -991,   638,  -991,   300,  -991,
     300,  -991,   376,   377,  -991,   272,  -991,   252,     3,    84,
      56,   380,   430,   430,   381,   382,   566,   430,   386,  2110,
    -991,  -991,  -991,  -991,   252,   387,  -991,   388,  2175,  -991,
     591,   430,   252,   252,   252,   405,   604,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,    86,  -991,   600,   252,   397,
      72,   409,   513,  -991,  -991,   113,  -991,   616,  -991,   566,
    -991,  -991,    70,   569,    25,   532,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  1691,  -991,   788,  -991,  -991,   422,   252,
      33,   430,  -991,   252,  -991,   432,   435,  1691,    19,  -991,
    -991,  -991,   799,  1691,  -991,  -991,    69,    42,   441,   715,
    -991,   446,  -991,  -991,   446,   187,  -991,  -991,  1948,  1299,
      64,  -991,   442,   453,   560,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,   876,   454,  1436,  -991,
      97,  1691,   450,  2018,   252,    45,   730,  -991,   728,    -5,
    -991,  -991,  1492,   136,  -991,   729,  -991,  -991,  -991,   799,
     193,  -991,  -991,  2155,  -991,  -991,   466,  1755,   234,   836,
     604,  1214,  -991,   465,    93,   252,  -991,   733,   430,   539,
     540,  -991,   470,  -991,  -991,  -991,  -991,  -991,   477,   480,
    -991,  -991,   523,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    1691,   788,  -991,   254,   446,  1691,  -991,  -991,   799,  1691,
    -991,   430,  -991,  -991,  1691,  1755,  -991,  -991,  -991,  -991,
      25,   118,  -991,  -991,  -991,   622,  -151,  -151,  -151,  -151,
     491,   492,   507,   510,   517,   518,   519,   566,   566,  -991,
     798,   521,   254,   446,   430,   430,   254,   446,   254,   696,
    -991,   254,   254,   -29,   503,  -991,  -991,    87,   254,  -991,
    -991,   252,  -991,    87,    87,    87,  -991,  -991,   566,  -991,
     252,   101,   254,   254,   446,  -991,  -991,   566,  -991,   566,
     446,  1492,  -991,   151,  -991,  1492,  -991,  -991,  -991,  1210,
     522,   792,   252,    46,   252,  -991,    87,    25,    25,   524,
     153,   793,  -991,   525,   803,  -175,  -991,   533,   689,    93,
     274,   802,   746,   627,  -991,   657,   652,   547,   447,   675,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,   407,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  2093,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -111,  1003,   570,   776,   254,   845,  -991,  -991,   566,   575,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,   571,   274,   373,
      97,   579,    77,   252,   574,   584,   581,  -991,    74,  -991,
    -991,  -991,  -991,   789,    -5,  -991,   599,   252,  -991,   274,
    1691,  -991,   601,  -991,   615,   799,   799,   799,   799,   619,
     234,  -991,  -991,  -991,  1691,   799,   799,   799,   624,   836,
    -991,  -991,  -991,   629,   430,   430,   122,  -991,   430,   638,
     468,   132,  1591,  1524,   468,   108,   430,   468,   132,   973,
    1524,  -991,   576,   577,   633,  1214,  -991,  -991,  -991,   210,
    -991,  -991,  -991,  -991,    93,  -991,   596,   603,  -991,  1691,
     607,   274,   634,   252,   430,   430,   430,   638,  -991,  1090,
      49,   908,  -991,   479,  -991,   788,  -991,  -991,   430,   468,
    1090,  1755,   646,  -991,  -991,  -991,  -991,  -991,   468,  -991,
    -991,  -991,  -991,  -991,   641,  -991,   641,   641,   641,   641,
     641,   197,   201,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     430,  -991,  -991,   566,   430,  -991,    87,   211,    87,   430,
    -991,  -991,   218,   446,   644,    70,  -991,  -991,  -991,   801,
     659,   252,   266,   252,   266,   656,   660,  1691,  -991,   430,
    -991,   430,   291,  -991,   105,   670,    87,   681,  -991,   566,
    -991,  -991,  -991,   566,   653,   676,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,   546,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,   -84,  -991,    20,
    -991,   566,   683,  -991,   468,   673,  -991,  -991,  1178,  -991,
    -991,   269,   685,   682,  -991,   252,   963,  -991,   730,  -991,
    -991,   252,  -991,  -991,   764,    64,  -991,  1214,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,    64,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   766,   767,  -991,  -991,  -991,  -991,
    -991,    62,  -991,    62,   788,   446,  -991,  -991,  -991,   700,
     705,   714,   719,   720,   446,   430,  -991,  -991,   721,    62,
     430,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
      22,   430,  1214,  -991,  -991,  -991,  -991,   -93,   -93,  -991,
     210,   723,  -991,    60,   252,   430,  -991,   706,  -991,  -991,
    -991,   724,   727,   725,   996,   252,    93,    49,  1002,  -991,
    -991,  -991,   736,   739,  -991,   725,  1008,  -991,   811,   812,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   734,   222,
     737,  -991,  -991,  -991,   252,  -991,  1492,  -991,    93,  -991,
     266,  -991,  -991,   524,  -991,  -991,  -991,   446,  -991,  -991,
      93,   446,  -133,   430,   430,  -991,  -991,  -991,  -991,  -991,
    -991,   741,  -991,   965,   430,  -991,   -11,  1178,  -991,  -991,
    -991,   625,  -991,   750,   747,  1948,  -991,  -991,  -991,  -991,
     799,   753,   761,  -991,   252,   430,    62,    62,  1027,   430,
     430,   638,   133,   133,  -991,  -991,    62,  -991,  -991,  -991,
    1214,   763,   468,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     756,   625,  -991,  -991,  1691,   765,   274,  -991,   768,   252,
    -991,   468,   771,   274,   252,   430,   430,  -991,   430,  -991,
     775,  -991,   774,   777,   566,   758,   759,  -991,   770,   769,
     430,  -991,   780,   772,   783,   791,   806,   807,   808,   809,
     810,   818,   254,  -991,   446,  -991,   779,  -991,    93,   -54,
    1691,    93,  -991,  -991,  -991,   446,   446,   252,   816,   820,
     821,   822,   827,   430,    22,  -991,  -991,  -991,  -991,  -991,
     179,   524,    93,   725,  -991,  -991,  -991,    93,   725,  -991,
    -991,  -991,   819,  1492,  -991,  -991,    31,  -991,  -991,   430,
    -991,   794,  -991,   351,   638,   638,   638,   638,    85,    99,
     829,   638,  -991,   244,  -991,   830,  -991,   788,   832,  -991,
    -991,  -991,  -991,  -991,  -991,   823,   835,   800,  -991,  -991,
    1691,  -991,   839,   841,   846,   842,   430,  -991,   566,   157,
    -991,   855,   856,   861,   862,   864,   865,   868,   871,   872,
     853,   874,   875,   890,   902,   887,   904,   566,   906,   879,
     244,  -991,  -991,  -991,   773,  1175,  -991,   468,   468,  -991,
     430,   524,  -991,    93,  -991,    93,  -991,    89,  -991,   430,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   909,
    -991,  -991,  -991,  -991,   910,  -991,   235,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   773,  -991,   274,  -991,  -991,   911,
     915,  -991,  -991,  -991,  -991,   921,   923,   566,   901,  -991,
    -991,  -991,  -991,   925,  -991,   468,  -991,  -991,   261,  -991,
      93,  -991,  -991,   926,  -991
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -991,  -991,   710,  -991,  1180,  -991,  -991,  -991,  -991,   -95,
     297,  -316,    92,    -8,   -86,  -135,  -991,  -991,  -991,  -141,
    -991,   257,  -991,   345,  -991,  -991,  1116,  -991,  -991,  -991,
     708,  -991,   920,  -991,  -140,  -991,  -991,  -991,  -991,   -78,
    -991,  -991,  -991,  -991,  -991,   952,    79,  -114,   425,  -652,
    -991,  -991,  1077,  -451,  -991,   740,  -991,  -991,  -127,   716,
     666,  -337,   268,   215,  -781,  -173,  -991,  -991,  -991,   663,
    -991,  -991,  -711,  -991,  -681,  -991,   -71,  -619,  -991,  -991,
    -991,   220,  -991,  -991,   212,  -991,  -991,  -991,   749,  -991,
    -991,   506,  -171,  -991,  -991,  -974,  -991,  -991,  -991,  -991,
     751,  -991,  -991,   504,    12,  -991,  -991,  -991,  -991,  -123,
    -165,  -991,  -991,  -991,  -991,   528,   -74,  -138,  -990,  -618,
     -10,  -991,  -991,   391,   154,  -991,  -563,  -991,   237,   993,
    -991,   555,   -89,     5,  -991,  -991,  -991,  1153,  -991,  -991,
    1085,  -991,  -991,  -991,  1221,  -991,  -991,   919,  -117,  -991,
    -991,  -991,  1101,  -991,  -991,   895,  -112,  -991,  -991,  -991,
    -991,  1117,   784,  -991,   903,  -991,  -991,  -991,  -991,  -991,
    1114,  -991,  -991,   896,    37,   589,   363,  -991,     1,   863,
    -991,  -991,  -991,  -991,  -516,  -991,  -991,  -991,  -991,   161,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,   -61,  -991,  -991,
    -991,    14
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -728
static const yytype_int16 yytable[] =
{
     116,    49,   569,   207,  1026,    39,   536,   366,   887,   151,
     460,   152,    35,   209,   210,   286,   252,   247,   702,   297,
     301,   290,   252,   252,   872,   252,   874,   651,    49,   113,
     652,   114,    39,   239,   199,   709,   364,    48,   248,    35,
     584,   353,   355,   357,   359,   361,   302,   248,   307,   196,
     248,   248,  -410,   248,   -45,   432,   277,   278,   281,   -45,
     386,   287,   828,   460,    48,   421,   951,   336,   113,   460,
     114,   795,   252,   113,   113,   114,   114,   651,  1027,   460,
     652,  1162,   248,   959,   472,  1103,  1171,   964,   535,   434,
     460,   248,   248,  1287,   436,   437,   885,  1100,   594,   245,
     252,   882,   535,   101,   795,   874,   248,  1292,  1028,   438,
     883,   462,   460,   161,   274,   460,   516,   439,   248,   248,
    1142,   252,   113,   335,   114,   252,   113,   113,   114,   114,
     113,   523,   114,   119,   120,   162,   535,   433,   517,   460,
     117,   537,   283,  1174,   531,   179,   180,   986,   661,  1036,
     121,   729,   730,   497,   111,   453,   466,  1043,   297,   301,
     461,   309,   125,   464,   465,   306,   195,   938,  1055,   181,
     126,   459,   305,   939,   405,   859,   940,   383,   383,   398,
     415,   781,   119,   120,   196,   302,   414,   307,   249,   712,
     713,   714,   127,   715,   486,   349,   352,   308,   731,   732,
    1101,   524,   350,   350,   150,  1102,   525,   102,   103,   104,
     105,   106,   155,   382,   102,   103,   104,   105,   106,   505,
     354,   435,   529,   156,  1256,   356,   533,   350,   440,   547,
     939,  1031,   350,   940,   425,   556,   550,   457,   500,   501,
     555,   527,   554,  1277,   336,   564,   426,   745,   853,  1273,
     942,   427,   661,   552,  1275,  1080,   113,   560,   114,     6,
     470,   444,   445,   446,  1000,  1001,  1002,  1003,   746,     6,
    1180,   386,   591,    13,  1181,    14,   158,   495,   113,   113,
     114,   114,   593,    13,   597,    14,   637,   747,   553,   592,
     603,   538,   539,   454,   252,   507,   508,   748,   455,   651,
     309,  1104,   652,   661,   306,  1105,   441,  1278,   537,   285,
     653,   305,   661,   251,   200,   438,   551,   595,   644,  1027,
    1288,  1289,   251,   439,   624,   251,   251,   632,   251,   -45,
     723,   873,  -410,   630,  1293,  1294,   308,  1080,   279,   -45,
     640,   288,   596,   661,   490,   157,   447,   631,   448,  1028,
     160,   449,   960,   450,   186,   187,   451,   251,   623,  1026,
     653,   641,   955,   618,  1290,  1367,   251,   251,   540,   541,
     661,  -553,   297,   301,   246,   703,   607,   490,  1295,   191,
     383,   251,   289,   701,   613,   614,   615,   814,   358,   383,
     627,   250,   335,   251,   251,   350,   781,   398,   826,   302,
     621,   307,   107,   829,   829,   829,   829,   736,  1143,  1143,
     289,   176,   542,   414,   253,   177,   382,   360,   812,   570,
     740,   572,   336,   639,   350,   843,   782,   865,   737,   877,
     800,   643,   823,   252,   866,   646,   878,   649,    50,    51,
      52,    53,  1318,   658,  1319,    50,    51,    52,   440,   113,
     585,   114,   586,   988,   291,  1270,   810,   845,   538,   539,
     178,   848,  1271,   849,   952,   662,   851,   852,   661,   433,
     336,   252,   113,   855,   114,  1066,   824,   811,   661,  1067,
     185,   719,   661,  1158,   569,   438,   722,   860,   861,  1071,
     273,  1042,   661,   494,    49,   276,  1073,  1113,    39,   661,
    1167,   841,   842,   661,  1223,    35,   831,   832,   833,   875,
     876,  1228,   310,  1371,   309,  1172,   661,   280,   306,   753,
     762,   398,   792,   752,   761,   305,   790,  1173,   407,   362,
      48,   289,   857,   363,   442,   540,   541,   367,     6,  1382,
     809,   862,   661,   863,   419,   813,   408,   589,   590,   815,
     308,   422,    13,   424,   820,   409,   443,   864,   791,   452,
     410,   897,   898,   899,   900,   459,   706,   707,   463,   946,
     444,   445,   446,   460,   969,   970,   971,   972,   467,   542,
     901,   201,   202,   203,   976,   977,   978,   204,   205,   206,
     468,   506,   469,   512,   894,   895,   473,    54,    55,    56,
     992,  1281,  1282,   856,    54,    55,    56,  1010,   522,   153,
     154,   526,   858,   474,   530,   532,  1211,  1212,   534,   390,
     490,   548,   948,   493,   391,   392,   499,   557,   513,     6,
     496,   457,   460,   514,   393,  1255,   518,   394,  1258,   519,
     520,   535,   963,    13,   566,   528,   580,   581,   562,   582,
     568,   583,   886,   587,   588,   447,  1182,   448,   567,  1272,
     449,   605,   450,   609,  1274,   451,   598,   601,   602,   599,
     600,   984,   611,   608,   604,   989,   444,   445,   446,   997,
     616,   620,  1006,   622,   625,   991,   993,   995,   612,  1004,
     782,   629,  1009,   635,  1020,   211,   212,   213,   214,   996,
    1095,  1096,  1097,  1098,  1373,   638,  1021,   642,  1038,   647,
     886,  1060,   648,  1061,  1062,  1063,  1064,  1065,   659,  1099,
    1047,   444,   445,   446,  1050,   660,   336,   661,   704,   705,
     965,   886,   710,  1058,   720,  1044,   724,   727,   645,   739,
     743,  1048,   794,   801,   975,   654,  1056,   803,   804,  1088,
    1365,   753,  1366,   654,   806,   752,  1046,   807,   805,   808,
     762,   447,   994,   448,   761,   850,   449,  1069,   450,   834,
     632,   451,   428,   429,   430,   431,  1079,   835,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,   836,   792,   716,   837,   719,
     790,   854,   113,   886,   114,   838,   839,   840,  1087,   844,
    -727,   457,   871,  1091,   890,   879,   447,  1092,   448,   888,
     880,   449,   457,   450,   881,  1210,   451,  1383,   783,   884,
     889,   891,   791,   892,   893,   802,  1190,  1191,   896,   254,
    1192,   570,   571,   572,   573,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   943,  1109,
     944,   947,   754,   949,   954,  1107,   950,   958,   816,  1340,
     956,     6,   957,   961,  1023,  1024,  1119,  1083,   825,   268,
    1121,   755,   782,  -320,  1032,    13,   966,    14,  1193,  1033,
    1123,   102,   103,   104,   105,   106,   444,   445,   446,   756,
     968,   846,   847,  1035,   973,   399,   400,   401,   215,   979,
     757,   402,   403,   404,   981,  1126,  1341,  1127,  1025,  1342,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1045,  1037,
    1128,  1057,  1074,  1136,   216,   350,  1076,   782,  1283,  1284,
    1285,  1286,  1291,  1296,  1081,  1298,  1078,  1093,  1082,  1149,
     217,   218,   219,   220,   221,   222,   223,   224,  1089,   225,
    1157,   708,   163,   164,   165,   166,   167,   168,  1090,  1111,
    1094,  1108,  1115,   475,   476,   477,   478,  1116,   792,  1117,
    1120,   447,   790,   448,  1124,  1125,   870,  1129,   450,  1169,
     269,   451,  1130,   244,   227,   444,   445,   446,   228,   229,
     230,  1131,  1151,   479,   480,   481,  1132,  1133,  1135,   169,
     170,  1147,  1152,   171,   791,  1153,  1156,  1154,   482,   483,
     484,   485,  1159,  1351,  1160,  1161,  1352,   716,  1163,  1164,
    1165,  1178,  1166,   792,  1198,  1168,  1177,   790,  1197,  1203,
    1201,  1200,   232,   233,   234,   235,  1202,  1207,  1215,  1218,
    1205,  1206,  1222,  1237,  1238,   782,  1224,  1216,  1227,  1243,
    1214,  1233,  1234,  1253,  1240,  1235,  1239,  1252,  1242,   791,
    1244,   982,   983,   985,  1225,   987,  1050,   990,  1245,  1229,
     447,   998,   456,  1005,  1007,   449,  1310,   450,   941,  1280,
     451,   237,   783,  1246,  1247,  1248,  1249,   173,  1236,  1329,
     475,   476,   477,   478,   113,  1251,   114,  1250,  1261,  1262,
    1263,  1039,  1040,  1041,  1260,  1264,  1297,  1276,  1304,   454,
    1306,  1308,  1259,  1309,   455,  1049,  1051,  1312,  1313,  1315,
     479,   480,   481,  1334,  1314,  1059,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1320,  1321,   482,   483,   484,   485,  1322,
    1323,   792,  1324,  1325,  1221,   790,  1326,  1068,   886,  1327,
    1328,  1070,  1330,  1331,  1338,   886,  1072,   661,   163,   164,
     165,   166,   167,   168,   128,   129,   130,   131,  1332,   132,
     133,   134,   135,   136,   137,  1018,  1084,   791,  1085,   654,
    1333,   138,  1335,  1305,  1337,  1356,  1379,  1369,  1370,  1374,
    1257,  1375,  1317,   139,   140,   141,   142,   143,   144,  1376,
     215,  1377,  1380,   721,  1384,   169,   170,   159,  1114,   171,
    1075,  1336,  1357,  1362,   113,   208,   114,   252,   113,   515,
     114,   742,  1339,   471,  1034,   282,   216,  1372,   711,   454,
    1219,   821,     2,   744,   455,  1122,  1106,  1140,   827,     6,
    1145,  1110,   217,   218,   219,   220,   221,   222,   223,   224,
    1146,   225,   738,    13,  1303,    14,   974,   764,  1302,   765,
    1311,   741,   962,   980,   783,   475,   476,   477,   478,  1199,
    1148,    20,    21,  1086,   491,   953,   275,   417,   172,   198,
    1357,  1378,   766,   610,   661,   244,   227,   444,   445,   446,
     228,   229,   230,   173,   418,   479,   480,   481,   606,   617,
     406,  1303,  1134,   416,   763,  1302,   460,  1137,   626,   145,
     482,   483,   484,   485,  1381,   657,   146,  1138,  1139,   783,
     215,  1118,  1226,     0,  1364,     0,     0,     0,     0,     0,
       0,     0,  1150,     0,   232,   233,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,   216,     0,   886,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   447,     0,   456,     0,     0,   449,     0,   450,
       0,     0,   451,   237,     0,     0,   475,   476,   477,   478,
    1175,  1176,     0,     0,     0,   113,     0,   114,     0,     0,
       0,  1179,     0,     0,     0,   244,   227,   444,   445,   446,
     228,   229,   230,     0,     0,     0,   479,   480,   481,     0,
       0,     0,  1204,     0,     0,     0,  1208,  1209,   113,     0,
     114,   482,   483,   484,   485,     0,     0,   783,     0,  1217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,   235,  1051,   661,
       0,     0,  1230,  1231,     0,  1232,     0,     0,   767,   768,
     769,     0,   770,   771,   772,   773,     0,  1241,     0,     0,
       0,   774,   775,   776,   777,   778,   779,   780,   781,     0,
       0,     0,   447,     0,   456,     0,   113,   870,   114,   450,
       0,   215,   451,   237,     0,     0,     0,     0,     0,     0,
    1265,  1269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,   476,   477,   478,   216,   113,     0,
     114,   460,     0,     0,   215,     0,  1279,     0,     0,     0,
       0,     0,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   479,   480,   481,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,   482,   483,
     484,   485,     0,  1316,     0,     0,   217,   218,   219,   220,
     221,   222,   223,   224,     0,   225,   226,   227,     0,     0,
       0,   228,   229,   230,     0,     0,     0,     0,   460,     0,
       0,     0,   215,     0,  1358,  1363,   231,  1265,     0,     0,
       0,     0,     0,     0,     0,     0,  1368,     0,     0,   558,
     227,     0,     0,     0,   228,   229,   230,     0,   216,     0,
       0,     0,     0,     0,   215,   232,   233,   234,   235,   559,
       0,     0,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,   225,     0,     0,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,   232,   233,
     234,   235,  1358,     0,     0,   236,   217,   218,   219,   220,
     221,   222,   223,   224,   237,   225,     0,   244,   227,     0,
       0,     0,   228,   229,   230,     0,     0,     0,     0,     0,
       0,   215,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,     0,     0,     0,     0,     0,   237,     0,   244,
     227,     0,     0,     0,   228,   229,   230,   216,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   234,   235,
       0,     0,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,     0,     0,     0,     0,     0,   252,   113,
       0,   114,     0,     0,     0,     0,     0,     0,   232,   233,
     234,   235,     0,     2,     0,     0,   236,     0,     0,     0,
       6,     7,   311,   312,     0,   237,   244,   227,     0,     0,
       0,   228,   229,   230,    13,     0,    14,     0,   313,     0,
     314,   215,     0,     0,     0,     0,     0,     0,   236,   315,
       0,   316,    20,    21,     0,     0,     0,   237,     0,     0,
       0,     0,     0,   317,     0,     0,   318,   216,   319,     0,
       0,     0,     0,     0,     0,   232,   233,   234,   235,     0,
       0,     0,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    77,
       0,     0,    78,     0,   237,     0,   244,   227,     0,     0,
       0,   228,   229,   230,    79,    80,     0,     0,    81,    82,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,    77,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,   232,   233,   234,   235,    79,
      80,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   663,     0,     0,   334,     0,     0,   335,
       0,     0,     0,     1,     0,     0,     2,    97,     3,     4,
       0,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,     0,     0,     0,    12,     0,    13,     0,    14,
     664,     0,    15,     0,    16,   665,    17,    18,    19,     0,
     666,     0,     0,     0,     0,    20,    21,     0,     0,     0,
       0,     0,    97,     0,    22,     0,     0,     0,    23,     0,
      24,     0,     0,   667,   668,     0,     0,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   694,   695,   696,     0,   697,   698,     2,     0,
       0,     0,   368,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,   699,     0,     0,   369,     0,     0,    13,
       0,     0,   370,     0,     0,     0,     0,     0,     0,     0,
       0,   371,   372,     0,     0,     0,     0,    20,    21,   373,
       0,   374,   375,     2,     0,     3,     4,   376,     0,   377,
       6,     7,     0,     0,   292,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    13,     0,    14,   368,     0,     0,
       6,    16,     0,     0,     0,   384,     0,     0,     0,   293,
     294,   385,    20,    21,    13,   295,     0,   370,     0,     0,
     296,     0,     0,     0,     0,     0,   371,   372,     0,     0,
       0,     0,     0,     0,   373,     0,   374,   375,     0,     0,
       0,     0,   902,   903,   377,   904,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
       0,     0,   919,   920,     0,   921,   922,     0,     0,     0,
       0,     0,     0,   923,     0,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,   935,   936
};

static const yytype_int16 yycheck[] =
{
       8,     0,   339,    98,   785,     0,   322,   172,   660,    17,
       7,    19,     0,   102,   103,   153,     3,   112,   469,   160,
     160,   156,     3,     3,   642,     3,   644,     8,    27,     4,
      11,     6,    27,   107,     6,   486,   171,     0,     5,    27,
     356,   164,   165,   166,   167,   168,   160,     5,   160,    57,
       5,     5,    10,     5,     5,   226,     6,     7,   147,    10,
     177,     6,   213,     7,    27,   200,   718,   162,     4,     7,
       6,    11,     3,     4,     4,     6,     6,     8,   789,     7,
      11,  1055,     5,     9,    36,    65,  1076,   739,     3,   227,
       7,     5,     5,     8,   232,   233,   659,   181,    14,   109,
       3,   276,     3,     3,    11,   723,     5,     8,   789,    40,
     285,   246,     7,   252,   122,     7,   252,    48,     5,     5,
     213,     3,     4,   274,     6,     3,     4,     4,     6,     6,
       4,   207,     6,   231,   232,   274,     3,   226,   274,     7,
     284,     8,   150,   276,   317,    98,    99,   766,   281,   801,
     248,   156,   157,   288,   214,   244,   251,   809,   299,   299,
     246,   160,     3,   249,   250,   160,    40,   278,   820,   122,
       6,   245,   160,   284,   182,    74,   287,   176,   177,   178,
     188,   274,   231,   232,   192,   299,   185,   299,    74,    92,
      93,    94,     3,    96,   280,   277,   277,   160,   203,   204,
     284,   277,   284,   284,    81,   289,   282,    82,    83,    84,
      85,    86,     3,   176,    82,    83,    84,    85,    86,   293,
     277,   231,   317,   286,   278,   277,   321,   284,   236,   324,
     284,   794,   284,   287,   161,   330,   325,   245,   102,   103,
     329,   315,   328,  1233,   339,   334,   173,    13,   277,  1223,
     701,   178,   281,   327,  1228,   873,     4,   331,     6,    25,
     270,   197,   198,   199,   156,   157,   158,   159,    34,    25,
     281,   388,   367,    39,   285,    41,     0,   285,     4,     4,
       6,     6,   368,    39,   370,    41,   424,    53,   205,   286,
     376,   158,   159,    19,     3,   102,   103,    63,    24,     8,
     299,   281,    11,   281,   299,   285,   293,   276,     8,   284,
     291,   299,   281,   280,   286,    40,   326,   233,   285,  1030,
     235,   236,   280,    48,   410,   280,   280,   422,   280,   280,
     285,   285,   290,   419,   235,   236,   299,   955,   288,   290,
     435,   286,   286,   281,   284,   284,   282,   277,   284,  1030,
     274,   287,   278,   289,    98,    99,   292,   280,   286,  1140,
     291,   435,   285,   277,   279,   276,   280,   280,   235,   236,
     281,   278,   513,   513,   286,   470,   384,   284,   279,   234,
     379,   280,   277,   469,   392,   393,   394,   558,   277,   388,
     277,   277,   274,   280,   280,   284,   274,   396,   571,   513,
     408,   513,   277,   576,   577,   578,   579,   502,  1027,  1028,
     277,   274,   279,   412,   117,   274,   379,   277,   553,   209,
     509,   211,   517,   433,   284,   590,   521,   276,   502,   276,
     525,   439,   570,     3,   283,   443,   283,   447,    78,    79,
      80,    81,   285,   453,   287,    78,    79,    80,   456,     4,
     358,     6,   360,   769,   157,   276,   551,   592,   158,   159,
     274,   596,   283,   598,    91,   278,   601,   602,   281,   558,
     565,     3,     4,   608,     6,   278,   571,   551,   281,   278,
     274,   491,   281,  1046,   821,    40,   494,   622,   623,   278,
       3,   807,   281,    48,   493,   276,   278,   948,   493,   281,
     278,   587,   588,   281,  1156,   493,   577,   578,   579,   647,
     648,  1163,   274,   278,   513,  1078,   281,   277,   513,   518,
     519,   520,   521,   518,   519,   513,   521,  1090,    15,   287,
     493,   277,   618,   287,   237,   235,   236,   277,    25,   278,
     550,   627,   281,   629,    75,   555,    33,   275,   276,   559,
     513,   282,    39,   196,   564,    42,   290,   631,   521,   278,
      47,   154,   155,   156,   157,   639,     6,     7,   286,   704,
     197,   198,   199,     7,   745,   746,   747,   748,   285,   279,
     173,    98,    99,   100,   755,   756,   757,   104,   105,   106,
     277,   294,   277,   296,   147,   148,     6,   237,   238,   239,
     771,   250,   251,   611,   237,   238,   239,   778,   311,    20,
      21,   314,   620,     3,   317,   318,  1132,  1133,   321,    15,
     284,   324,   708,   274,    20,    21,   285,   330,   274,    25,
     277,   639,     7,   275,    30,  1198,   274,    33,  1201,   274,
     274,     3,   737,    39,   288,   284,   349,   350,   277,   352,
     275,   354,   660,   277,   277,   282,  1107,   284,   288,  1222,
     287,   275,   289,   275,  1227,   292,   286,   286,   286,   372,
     373,   766,    81,   286,   377,   770,   197,   198,   199,   774,
     275,    81,   777,   286,   275,   771,   772,   773,   391,   775,
     785,    75,   778,   124,   780,    87,    88,    89,    90,   773,
     154,   155,   156,   157,  1356,   173,   780,   285,   803,   277,
     718,   834,   277,   836,   837,   838,   839,   840,   277,   173,
     815,   197,   198,   199,   819,    10,   821,   281,   286,   276,
     740,   739,   278,   828,   284,   809,     6,     9,   441,    10,
     274,   815,   277,    10,   754,   448,   820,   208,   208,   884,
    1313,   750,  1315,   456,   277,   750,   277,   277,   288,   236,
     759,   282,   772,   284,   759,    69,   287,   853,   289,   278,
     865,   292,   154,   155,   156,   157,   871,   285,   153,   154,
     155,   156,   157,   158,   159,   278,   785,   490,   278,   799,
     785,   288,     4,   801,     6,   278,   278,   278,   884,   278,
     278,   809,    10,   889,   177,    12,   282,   893,   284,     7,
     285,   287,   820,   289,    11,  1131,   292,  1380,   521,   286,
      74,   164,   785,   171,   277,   528,   201,   202,   153,    91,
     205,   209,   210,   211,   212,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   278,   944,
      74,     6,    16,   278,   275,   941,   285,   276,   561,    86,
     286,    25,   278,    74,   288,   288,   961,   877,   571,   131,
     965,    35,   967,   274,   278,    39,   275,    41,   253,   276,
     975,    82,    83,    84,    85,    86,   197,   198,   199,    53,
     275,   594,   595,   286,   275,    98,    99,   100,   110,   275,
      64,   104,   105,   106,   275,   991,   133,   993,   275,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    10,   285,
     994,   275,   278,  1009,   136,   284,   125,  1022,  1244,  1245,
    1246,  1247,  1248,  1249,   278,  1251,   277,   284,   278,  1034,
     152,   153,   154,   155,   156,   157,   158,   159,   278,   161,
    1045,    75,   154,   155,   156,   157,   158,   159,   277,   286,
     284,   278,   277,    87,    88,    89,    90,   285,   967,     6,
     206,   282,   967,   284,   208,   208,   287,   277,   289,  1074,
     242,   292,   277,   195,   196,   197,   198,   199,   200,   201,
     202,   277,   286,   117,   118,   119,   277,   277,   277,   201,
     202,   278,   278,   205,   967,   278,    10,   282,   132,   133,
     134,   135,    10,   240,   278,   276,   243,   720,    10,   208,
     208,    56,   288,  1022,   277,   288,   285,  1022,   278,  1124,
     277,  1120,   244,   245,   246,   247,   275,    10,   275,   283,
    1126,  1127,   277,   285,   285,  1140,   278,  1142,   277,   277,
    1136,   276,   278,   274,   285,   278,   286,  1192,   278,  1022,
     277,   764,   765,   766,  1159,   768,  1161,   770,   277,  1164,
     282,   774,   284,   776,   777,   287,   276,   289,    75,   285,
     292,   293,   785,   277,   277,   277,   277,   289,  1174,   236,
      87,    88,    89,    90,     4,   277,     6,   287,   278,   278,
     278,   804,   805,   806,   288,   278,   277,   288,   278,    19,
     278,   288,  1207,   278,    24,   818,   819,   278,   277,   277,
     117,   118,   119,   236,   278,   828,   153,   154,   155,   156,
     157,   158,   159,   278,   278,   132,   133,   134,   135,   278,
     278,  1140,   278,   278,  1154,  1140,   278,   850,  1156,   278,
     278,   854,   278,   278,   275,  1163,   859,   281,   154,   155,
     156,   157,   158,   159,    97,    98,    99,   100,   278,   102,
     103,   104,   105,   106,   107,   202,   879,  1140,   881,   882,
     278,   114,   278,  1257,   278,    10,   285,   278,   278,   278,
    1200,   276,  1278,   126,   127,   128,   129,   130,   131,   278,
     110,   278,   277,   493,   278,   201,   202,    27,   951,   205,
     865,  1297,  1307,  1308,     4,    99,     6,     3,     4,   299,
       6,   513,  1300,   271,   799,   148,   136,  1354,   488,    19,
    1151,   565,    18,   517,    24,   967,   939,  1022,   575,    25,
    1028,   944,   152,   153,   154,   155,   156,   157,   158,   159,
    1030,   161,   503,    39,  1253,    41,   750,    43,  1253,    45,
    1270,   510,   734,   759,   967,    87,    88,    89,    90,  1115,
    1033,    57,    58,   882,   281,   720,   123,   192,   274,    58,
    1375,  1367,    68,   388,   281,   195,   196,   197,   198,   199,
     200,   201,   202,   289,   193,   117,   118,   119,   379,   396,
     183,  1300,  1005,   189,   520,  1300,     7,  1010,   412,   242,
     132,   133,   134,   135,  1375,   452,   249,  1020,  1021,  1022,
     110,   958,  1161,    -1,  1310,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1035,    -1,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,  1356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,   161,   282,    -1,   284,    -1,    -1,   287,    -1,   289,
      -1,    -1,   292,   293,    -1,    -1,    87,    88,    89,    90,
    1093,  1094,    -1,    -1,    -1,     4,    -1,     6,    -1,    -1,
      -1,  1104,    -1,    -1,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,    -1,   117,   118,   119,    -1,
      -1,    -1,  1125,    -1,    -1,    -1,  1129,  1130,     4,    -1,
       6,   132,   133,   134,   135,    -1,    -1,  1140,    -1,  1142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,  1161,   281,
      -1,    -1,  1165,  1166,    -1,  1168,    -1,    -1,   254,   255,
     256,    -1,   258,   259,   260,   261,    -1,  1180,    -1,    -1,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,    -1,
      -1,    -1,   282,    -1,   284,    -1,     4,   287,     6,   289,
      -1,   110,   292,   293,    -1,    -1,    -1,    -1,    -1,    -1,
    1213,  1214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,   136,     4,    -1,
       6,     7,    -1,    -1,   110,    -1,  1239,    -1,    -1,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   117,   118,   119,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,    -1,  1276,    -1,    -1,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,   161,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    -1,   110,    -1,  1307,  1308,   215,  1310,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1319,    -1,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,    -1,   136,    -1,
      -1,    -1,    -1,    -1,   110,   244,   245,   246,   247,   215,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
     246,   247,  1375,    -1,    -1,   284,   152,   153,   154,   155,
     156,   157,   158,   159,   293,   161,    -1,   195,   196,    -1,
      -1,    -1,   200,   201,   202,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,   195,
     196,    -1,    -1,    -1,   200,   201,   202,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
     246,   247,    -1,    18,    -1,    -1,   284,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,   293,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    39,    -1,    41,    -1,    43,    -1,
      45,   110,    -1,    -1,    -1,    -1,    -1,    -1,   284,    54,
      -1,    56,    57,    58,    -1,    -1,    -1,   293,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    71,   136,    73,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,
      -1,    -1,    86,    -1,   293,    -1,   195,   196,    -1,    -1,
      -1,   200,   201,   202,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    75,    -1,    -1,   271,    -1,    -1,   274,
      -1,    -1,    -1,    15,    -1,    -1,    18,   241,    20,    21,
      -1,    23,    -1,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    -1,    39,    -1,    41,
     112,    -1,    44,    -1,    46,   117,    48,    49,    50,    -1,
     122,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    66,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,   145,   146,    -1,    -1,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,   178,   179,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    36,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    61,    62,    18,    -1,    20,    21,    67,    -1,    69,
      25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    22,    -1,    -1,
      25,    46,    -1,    -1,    -1,    30,    -1,    -1,    -1,    54,
      55,    36,    57,    58,    39,    60,    -1,    42,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,   149,   150,    69,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    15,    18,    20,    21,    23,    25,    26,    30,    31,
      32,    33,    37,    39,    41,    44,    46,    48,    49,    50,
      57,    58,    66,    70,    72,   295,   296,   297,   298,   301,
     302,   312,   313,   328,   341,   398,   399,   405,   406,   427,
     428,   432,   433,   443,   450,   451,   459,   460,   468,   472,
      78,    79,    80,    81,   237,   238,   239,   436,   437,   438,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   469,    81,    83,    86,    98,
      99,   102,   103,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   241,   318,   319,
     320,     3,    82,    83,    84,    85,    86,   277,   386,   426,
     473,   214,   400,     4,     6,   303,   307,   284,   334,   231,
     232,   248,   429,   430,   431,     3,     6,     3,    97,    98,
      99,   100,   102,   103,   104,   105,   106,   107,   114,   126,
     127,   128,   129,   130,   131,   242,   249,   344,   345,   346,
      81,   307,   307,   469,   469,     3,   286,   284,     0,   298,
     274,   252,   274,   154,   155,   156,   157,   158,   159,   201,
     202,   205,   274,   289,   401,   404,   274,   274,   274,    98,
      99,   122,   453,   454,   455,   274,    98,    99,   462,   463,
     464,   234,   444,   445,   446,    40,   307,   434,   438,     6,
     286,    98,    99,   100,   104,   105,   106,   303,   320,   426,
     426,    87,    88,    89,    90,   110,   136,   152,   153,   154,
     155,   156,   157,   158,   159,   161,   195,   196,   200,   201,
     202,   215,   244,   245,   246,   247,   284,   293,   307,   410,
     411,   413,   414,   474,   195,   414,   286,   303,     5,    74,
     277,   280,     3,   304,    91,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   131,   242,
     337,   338,   339,     3,   307,   431,   276,     6,     7,   288,
     277,   426,   346,   307,   299,   284,   411,     6,   286,   277,
     309,   304,    29,    54,    55,    60,    65,   313,   324,   325,
     326,   328,   341,   379,   391,   398,   427,   450,   468,   472,
     274,    27,    28,    43,    45,    54,    56,    68,    71,    73,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   271,   274,   303,   304,   353,   354,
     355,   359,   362,   364,   398,   427,   468,   472,   475,   277,
     284,   403,   277,   403,   277,   403,   277,   403,   277,   403,
     277,   403,   287,   287,   309,   402,   404,   277,    22,    36,
      42,    51,    52,    59,    61,    62,    67,    69,   439,   440,
     441,   442,   468,   472,    30,    36,   442,   447,   448,   449,
      15,    20,    21,    30,    33,   456,   457,   458,   472,    98,
      99,   100,   104,   105,   106,   307,   455,    15,    33,    42,
      47,   465,   466,   467,   472,   307,   464,   434,   446,    75,
     435,   309,   282,   315,   196,   161,   173,   178,   154,   155,
     156,   157,   386,   426,   411,   414,   411,   411,    40,    48,
     307,   293,   304,   290,   197,   198,   199,   282,   284,   287,
     289,   292,   278,   426,    19,    24,   284,   307,   343,   410,
       7,   308,   309,   286,   308,   308,   303,   285,   277,   277,
     414,   339,    36,     6,     3,    87,    88,    89,    90,   117,
     118,   119,   132,   133,   134,   135,   308,   347,   348,   349,
     284,   423,   424,   274,    48,   307,   277,   309,   310,   285,
     102,   103,   380,   381,   382,   410,   304,   102,   103,   392,
     393,   394,   304,   274,   275,   326,   252,   274,   274,   274,
     274,   300,   304,   207,   277,   282,   304,   410,   284,   303,
     304,   359,   304,   303,   304,     3,   305,     8,   158,   159,
     235,   236,   279,   305,   306,   309,   478,   303,   304,   387,
     426,   414,   410,   205,   308,   426,   303,   304,   195,   215,
     410,   476,   277,   388,   426,   360,   288,   288,   275,   355,
     209,   210,   211,   212,   363,   365,   366,   367,   368,   369,
     304,   304,   304,   304,   305,   306,   306,   277,   277,   275,
     276,   303,   286,   308,    14,   233,   286,   308,   286,   304,
     304,   286,   286,   308,   304,   275,   441,   307,   286,   275,
     449,    81,   304,   307,   307,   307,   275,   458,   277,   452,
      81,   307,   286,   286,   308,   275,   467,   277,   461,    75,
     308,   277,   303,   316,   317,   124,   321,   411,   173,   414,
     303,   410,   285,   307,   285,   304,   307,   277,   277,   414,
     415,     8,    11,   291,   304,   416,   417,   473,   414,   277,
      10,   281,   278,    75,   112,   117,   122,   145,   146,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   178,   179,   195,
     418,   308,   347,   303,   286,   276,     6,     7,    75,   347,
     278,   349,    92,    93,    94,    96,   304,   425,   342,   414,
     284,   296,   307,   285,     6,   470,   471,     9,   311,   156,
     157,   203,   204,   407,   408,   409,   303,   410,   382,    10,
     426,   394,   324,   274,   353,    13,    34,    53,    63,   383,
     384,   385,   427,   472,    16,    35,    53,    64,   395,   396,
     397,   427,   472,   456,    43,    45,    68,   254,   255,   256,
     258,   259,   260,   261,   267,   268,   269,   270,   271,   272,
     273,   274,   303,   304,   356,   357,   358,   371,   374,   376,
     427,   468,   472,   484,   277,    11,   420,   421,   422,   423,
     303,    10,   304,   208,   208,   288,   277,   277,   236,   414,
     303,   410,   309,   414,   386,   414,   304,   479,   480,   477,
     414,   354,   361,   411,   303,   304,   359,   363,   213,   359,
     370,   370,   370,   370,   278,   285,   278,   278,   278,   278,
     278,   308,   308,   404,   278,   309,   304,   304,   309,   309,
      69,   309,   309,   277,   288,   309,   307,   308,   307,    74,
     309,   309,   308,   308,   410,   276,   283,   410,   412,   314,
     287,    10,   413,   285,   413,   411,   411,   276,   283,    12,
     285,    11,   276,   285,   286,   420,   307,   343,     7,    74,
     177,   164,   171,   277,   147,   148,   153,   154,   155,   156,
     157,   173,   149,   150,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   169,
     170,   172,   173,   180,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   419,   278,   284,
     287,    75,   347,   278,    74,   335,   309,     6,   308,   278,
     285,   343,    91,   425,   275,   285,   286,   278,   276,     9,
     278,    74,   409,   303,   343,   414,   275,   327,   275,   386,
     386,   386,   386,   275,   385,   414,   386,   386,   386,   275,
     397,   275,   304,   304,   303,   304,   371,   304,   305,   303,
     304,   308,   386,   308,   414,   308,   410,   303,   304,   490,
     156,   157,   158,   159,   308,   304,   303,   304,   494,   308,
     386,   153,   154,   155,   156,   157,   158,   159,   202,   487,
     308,   410,   372,   288,   288,   275,   358,   366,   368,   375,
     377,   420,   278,   276,   342,   286,   343,   285,   303,   304,
     304,   304,   305,   343,   410,    10,   277,   303,   410,   304,
     303,   304,   481,   482,   483,   343,   410,   275,   303,   304,
     403,   403,   403,   403,   403,   403,   278,   278,   304,   308,
     304,   278,   304,   278,   278,   317,   125,   322,   277,   303,
     413,   278,   278,   414,   304,   304,   417,   308,   309,   278,
     277,   308,   308,   284,   284,   154,   155,   156,   157,   173,
     181,   284,   289,    65,   281,   285,   304,   308,   278,   303,
     304,   286,   336,   347,   315,   277,   285,     6,   470,   303,
     206,   303,   356,   303,   208,   208,   308,   308,   410,   277,
     277,   277,   277,   277,   304,   277,   308,   304,   304,   304,
     357,   373,   213,   371,   378,   378,   375,   278,   422,   303,
     304,   286,   278,   278,   282,   389,    10,   303,   420,    10,
     278,   276,   389,    10,   208,   208,   288,   278,   288,   303,
     323,   412,   420,   420,   276,   304,   304,   285,    56,   304,
     281,   285,   347,   153,   154,   155,   156,   157,   158,   159,
     201,   202,   205,   253,   308,   340,   329,   278,   277,   418,
     426,   277,   275,   303,   304,   308,   308,    10,   304,   304,
     305,   478,   478,   486,   308,   275,   303,   304,   283,   340,
     390,   414,   277,   343,   278,   303,   483,   277,   343,   303,
     304,   304,   304,   276,   278,   278,   308,   285,   285,   286,
     285,   304,   278,   277,   277,   277,   277,   277,   277,   277,
     287,   277,   309,   274,   330,   420,   278,   414,   420,   303,
     288,   278,   278,   278,   278,   304,   492,   493,   495,   304,
     276,   283,   420,   389,   420,   389,   288,   412,   276,   304,
     285,   250,   251,   305,   305,   305,   305,     8,   235,   236,
     279,   305,     8,   235,   236,   279,   305,   277,   305,   331,
     332,   333,   427,   472,   278,   410,   278,   485,   288,   278,
     276,   414,   278,   277,   278,   277,   304,   308,   285,   287,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   236,
     278,   278,   278,   278,   236,   278,   308,   278,   275,   333,
      86,   133,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   240,   243,   350,   351,   352,    10,   303,   304,   488,
     489,   491,   303,   304,   495,   420,   420,   276,   304,   278,
     278,   278,   352,   343,   278,   276,   278,   278,   308,   285,
     277,   491,   278,   420,   278
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
#line 1075 "ilasm_grammar.y"
    {
		FinishDataLabels();
	}
    break;

  case 7:
#line 1091 "ilasm_grammar.y"
    {
	  			ILAsmBuildPopClass();
	  		}
    break;

  case 8:
#line 1094 "ilasm_grammar.y"
    {
				ILAsmBuildPushNamespace((yyvsp[(2) - (2)].strValue));
			}
    break;

  case 9:
#line 1096 "ilasm_grammar.y"
    {
				ILAsmBuildPopNamespace((yyvsp[(2) - (6)].strValue).len);
			}
    break;

  case 11:
#line 1100 "ilasm_grammar.y"
    {
				ILAsmParseJava = 1;
				ILJavaAsmInitPool();
			}
    break;

  case 12:
#line 1104 "ilasm_grammar.y"
    {
				ILAsmParseJava = 0;
			}
    break;

  case 13:
#line 1107 "ilasm_grammar.y"
    {}
    break;

  case 35:
#line 1146 "ilasm_grammar.y"
    { (yyval.strValue) = (yyvsp[(1) - (1)].strValue); }
    break;

  case 36:
#line 1147 "ilasm_grammar.y"
    { (yyval.strValue) = (yyvsp[(1) - (1)].strValue); }
    break;

  case 37:
#line 1151 "ilasm_grammar.y"
    { (yyval.integer) = (ILInt64)(ILInt32)((yyvsp[(1) - (1)].integer)); }
    break;

  case 38:
#line 1155 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 39:
#line 1163 "ilasm_grammar.y"
    {
				/* Literal floating point constant */
				SetFloat((yyval.floatValue).fbytes, (ILFloat)((yyvsp[(1) - (1)].real)));
				SetDouble((yyval.floatValue).dbytes, (yyvsp[(1) - (1)].real));
			}
    break;

  case 40:
#line 1168 "ilasm_grammar.y"
    {
				/* Convert a raw big endian value into a 32-bit float */
				(yyval.floatValue).fbytes[3] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 24);
				(yyval.floatValue).fbytes[2] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 16);
				(yyval.floatValue).fbytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				(yyval.floatValue).fbytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				SetDouble((yyval.floatValue).dbytes, (ILDouble)(IL_READ_FLOAT((yyval.floatValue).fbytes)));
			}
    break;

  case 41:
#line 1176 "ilasm_grammar.y"
    {
				/* Convert a raw big endian value into a 64-bit float */
				(yyval.floatValue).dbytes[7] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 56);
				(yyval.floatValue).dbytes[6] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 48);
				(yyval.floatValue).dbytes[5] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 40);
				(yyval.floatValue).dbytes[4] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 32);
				(yyval.floatValue).dbytes[3] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 24);
				(yyval.floatValue).dbytes[2] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 16);
				(yyval.floatValue).dbytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				(yyval.floatValue).dbytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				SetFloat((yyval.floatValue).fbytes, (ILFloat)(IL_READ_DOUBLE((yyval.floatValue).dbytes)));
			}
    break;

  case 42:
#line 1188 "ilasm_grammar.y"
    {
				/* Not a number */
				(yyval.floatValue).fbytes[3] = (ILUInt8)0xFF;
				(yyval.floatValue).fbytes[2] = (ILUInt8)0xC0;
				(yyval.floatValue).fbytes[1] = (ILUInt8)0x00;
				(yyval.floatValue).fbytes[0] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[7] = (ILUInt8)0xFF;
				(yyval.floatValue).dbytes[6] = (ILUInt8)0xF8;
				(yyval.floatValue).dbytes[5] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[4] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[3] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[2] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[1] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[0] = (ILUInt8)0x00;
			}
    break;

  case 43:
#line 1203 "ilasm_grammar.y"
    {
				/* Positive infinity */
				(yyval.floatValue).fbytes[3] = (ILUInt8)0x7F;
				(yyval.floatValue).fbytes[2] = (ILUInt8)0x80;
				(yyval.floatValue).fbytes[1] = (ILUInt8)0x00;
				(yyval.floatValue).fbytes[0] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[7] = (ILUInt8)0x7F;
				(yyval.floatValue).dbytes[6] = (ILUInt8)0xF0;
				(yyval.floatValue).dbytes[5] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[4] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[3] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[2] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[1] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[0] = (ILUInt8)0x00;
			}
    break;

  case 44:
#line 1218 "ilasm_grammar.y"
    {
				/* Negative infinity */
				(yyval.floatValue).fbytes[3] = (ILUInt8)0xFF;
				(yyval.floatValue).fbytes[2] = (ILUInt8)0x80;
				(yyval.floatValue).fbytes[1] = (ILUInt8)0x00;
				(yyval.floatValue).fbytes[0] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[7] = (ILUInt8)0xFF;
				(yyval.floatValue).dbytes[6] = (ILUInt8)0xF0;
				(yyval.floatValue).dbytes[5] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[4] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[3] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[2] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[2] = (ILUInt8)0x00;
				(yyval.floatValue).dbytes[0] = (ILUInt8)0x00;
			}
    break;

  case 45:
#line 1236 "ilasm_grammar.y"
    { (yyval.strValue) = (yyvsp[(1) - (1)].strValue); }
    break;

  case 46:
#line 1237 "ilasm_grammar.y"
    {
				ILIntString dot;
				dot.string = ".";
				dot.len = 1;
				(yyval.strValue) = ILInternAppendedString
						((yyvsp[(1) - (3)].strValue), ILInternAppendedString(dot, (yyvsp[(3) - (3)].strValue)));
			}
    break;

  case 47:
#line 1244 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString((yyvsp[(1) - (2)].strValue), (yyvsp[(2) - (2)].strValue));
			}
    break;

  case 48:
#line 1250 "ilasm_grammar.y"
    { (yyval.strValue) = (yyvsp[(1) - (1)].strValue); }
    break;

  case 49:
#line 1251 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString((yyvsp[(1) - (3)].strValue), (yyvsp[(3) - (3)].strValue));
			}
    break;

  case 50:
#line 1257 "ilasm_grammar.y"
    { ILAsmParseHexBytes = 1; }
    break;

  case 51:
#line 1258 "ilasm_grammar.y"
    {
	  			ILAsmParseHexBytes = 0;
				if((yyvsp[(3) - (4)].byteList).interned.len > 0)
				{
					ILIntString temp;
					temp.string = byteBuffer;
					temp.len = (yyvsp[(3) - (4)].byteList).extraSize;
					(yyval.strValue) = ILInternAppendedString((yyvsp[(3) - (4)].byteList).interned, temp);
				}
				else
				{
					(yyval.strValue) = ILInternString(byteBuffer, (yyvsp[(3) - (4)].byteList).extraSize);
				}
			}
    break;

  case 52:
#line 1275 "ilasm_grammar.y"
    {
				(yyval.byteList).interned = ILInternString("", 0);
				byteBuffer[0] = (char)((yyvsp[(1) - (1)].integer));
				(yyval.byteList).extraSize = 1;
			}
    break;

  case 53:
#line 1280 "ilasm_grammar.y"
    {
				if((yyvsp[(1) - (2)].byteList).extraSize < ILASM_BYTE_BUFSIZ)
				{
					(yyval.byteList).interned = (yyvsp[(1) - (2)].byteList).interned;
					(yyval.byteList).extraSize = (yyvsp[(1) - (2)].byteList).extraSize + 1;
					byteBuffer[(yyvsp[(1) - (2)].byteList).extraSize] = (char)((yyvsp[(2) - (2)].integer));
				}
				else if((yyvsp[(1) - (2)].byteList).interned.len > 0)
				{
					ILIntString temp;
					temp.string = byteBuffer;
					temp.len = (yyvsp[(1) - (2)].byteList).extraSize;
					(yyval.byteList).interned = ILInternAppendedString((yyvsp[(1) - (2)].byteList).interned, temp);
					byteBuffer[0] = (char)((yyvsp[(2) - (2)].integer));
					(yyval.byteList).extraSize = 1;
				}
				else
				{
					(yyval.byteList).interned = ILInternString(byteBuffer, (yyvsp[(1) - (2)].byteList).extraSize);
					byteBuffer[0] = (char)((yyvsp[(2) - (2)].integer));
					(yyval.byteList).extraSize = 1;
				}
			}
    break;

  case 54:
#line 1310 "ilasm_grammar.y"
    {
				/* This form of declaration is used when the programmer
				   wants to attach custom attributes to the current module,
				   so we just modify the "last token" */
				ILAsmLastToken = GetToken(ILAsmModule);
			}
    break;

  case 55:
#line 1316 "ilasm_grammar.y"
    {
				/* Set the name of the current module */
				if(!ILModuleSetName(ILAsmModule, (yyvsp[(2) - (2)].strValue).string))
				{
					ILAsmOutOfMemory();
				}
				ILAsmLastToken = GetToken(ILAsmModule);
			}
    break;

  case 56:
#line 1324 "ilasm_grammar.y"
    {
				/* Declare the name of an external module */
				ILModule *ref = ILModuleRefCreateUnique(ILAsmImage, (yyvsp[(3) - (3)].strValue).string);
				if(!ref)
				{
					ILAsmOutOfMemory();
				}
				ILAsmLastToken = GetToken(ref);
			}
    break;

  case 57:
#line 1340 "ilasm_grammar.y"
    {
				/* Create the new class */
				ILAsmBuildNewClass((yyvsp[(3) - (5)].strValue).string, (yyvsp[(4) - (5)].params).paramFirst,
								   (yyvsp[(5) - (5)].classInfo), (ILUInt32)((yyvsp[(2) - (5)].integer)));
				ILAsmBuildPushScope(ILAsmClass);
			}
    break;

  case 59:
#line 1350 "ilasm_grammar.y"
    { (yyval.params).paramFirst = 0; (yyval.params).paramLast = 0; }
    break;

  case 60:
#line 1351 "ilasm_grammar.y"
    { (yyval.params) = (yyvsp[(2) - (3)].params); }
    break;

  case 61:
#line 1355 "ilasm_grammar.y"
    { (yyval.params) = (yyvsp[(1) - (1)].params); }
    break;

  case 62:
#line 1356 "ilasm_grammar.y"
    {
				(yyvsp[(1) - (3)].params).paramLast->next = (yyvsp[(3) - (3)].params).paramFirst;
				(yyval.params).paramFirst = (yyvsp[(1) - (3)].params).paramFirst;
				(yyval.params).paramLast = (yyvsp[(3) - (3)].params).paramLast;
		}
    break;

  case 63:
#line 1364 "ilasm_grammar.y"
    {
				/* Generic parameter with a type constraint */
				ILAsmParamInfo *param;
				param = (ILAsmParamInfo *)ILMalloc(sizeof(ILAsmParamInfo));
				if(!param)
				{
					ILAsmOutOfMemory();
				}
				param->type = (yyvsp[(2) - (4)].typeSpec).type;
				param->nativeType.string = "";
				param->nativeType.len = 0;
				param->parameterAttrs = 0;
				param->name = (yyvsp[(4) - (4)].strValue).string;
				param->next = 0;
				(yyval.params).paramFirst = param;
				(yyval.params).paramLast = param;
			}
    break;

  case 64:
#line 1381 "ilasm_grammar.y"
    {
				/* Generic parameter with no constraints */
				ILAsmParamInfo *param;
				param = (ILAsmParamInfo *)ILMalloc(sizeof(ILAsmParamInfo));
				if(!param)
				{
					ILAsmOutOfMemory();
				}
				param->type = 0;
				param->nativeType.string = "";
				param->nativeType.len = 0;
				param->parameterAttrs = 0;
				param->name = (yyvsp[(1) - (1)].strValue).string;
				param->next = 0;
				(yyval.params).paramFirst = param;
				(yyval.params).paramLast = param;
			}
    break;

  case 65:
#line 1401 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 66:
#line 1402 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 67:
#line 1406 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 68:
#line 1407 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 69:
#line 1411 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_PUBLIC; }
    break;

  case 70:
#line 1412 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NOT_PUBLIC; }
    break;

  case 71:
#line 1413 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_VALUE_TYPE; }
    break;

  case 72:
#line 1414 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_UNMANAGED_VALUE_TYPE; }
    break;

  case 73:
#line 1415 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_UNMANAGED_VALUE_TYPE; }
    break;

  case 74:
#line 1416 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_INTERFACE; }
    break;

  case 75:
#line 1417 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_SEALED; }
    break;

  case 76:
#line 1418 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_ABSTRACT; }
    break;

  case 77:
#line 1419 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_AUTO_LAYOUT; }
    break;

  case 78:
#line 1420 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_LAYOUT_SEQUENTIAL; }
    break;

  case 79:
#line 1421 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_EXPLICIT_LAYOUT; }
    break;

  case 80:
#line 1422 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_ANSI_CLASS; }
    break;

  case 81:
#line 1423 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_UNICODE_CLASS; }
    break;

  case 82:
#line 1424 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_AUTO_CLASS; }
    break;

  case 83:
#line 1425 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_IMPORT; }
    break;

  case 84:
#line 1426 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_SERIALIZABLE; }
    break;

  case 85:
#line 1427 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_PUBLIC; }
    break;

  case 86:
#line 1428 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_PRIVATE; }
    break;

  case 87:
#line 1429 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_FAMILY; }
    break;

  case 88:
#line 1430 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_ASSEMBLY; }
    break;

  case 89:
#line 1431 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_FAM_AND_ASSEM; }
    break;

  case 90:
#line 1432 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_FAM_OR_ASSEM; }
    break;

  case 91:
#line 1433 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_LATE_INIT; }
    break;

  case 92:
#line 1434 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_BEFORE_FIELD_INIT; }
    break;

  case 93:
#line 1435 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_SPECIAL_NAME; }
    break;

  case 94:
#line 1436 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_RT_SPECIAL_NAME; }
    break;

  case 95:
#line 1440 "ilasm_grammar.y"
    {
				/* Probably "System.Object" or an interface */
				(yyval.classInfo) = 0;
			}
    break;

  case 96:
#line 1444 "ilasm_grammar.y"
    {
				/* Extend a named class */
				(yyval.classInfo) = (yyvsp[(2) - (2)].classInfo);
			}
    break;

  case 99:
#line 1456 "ilasm_grammar.y"
    {
				if(!ILClassAddImplements(ILAsmClass, (yyvsp[(1) - (1)].classInfo), 0))
				{
					ILAsmOutOfMemory();
				}
			}
    break;

  case 100:
#line 1462 "ilasm_grammar.y"
    {
				if(!ILClassAddImplements(ILAsmClass, (yyvsp[(3) - (3)].classInfo), 0))
				{
					ILAsmOutOfMemory();
				}
			}
    break;

  case 101:
#line 1471 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 102:
#line 1472 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 106:
#line 1482 "ilasm_grammar.y"
    {
				ILAsmParseJava = 1;
				ILJavaAsmInitPool();
			}
    break;

  case 107:
#line 1486 "ilasm_grammar.y"
    {
	  			ILAsmParseJava = 0;
	  		}
    break;

  case 108:
#line 1489 "ilasm_grammar.y"
    {
				ILAsmBuildPopClass();
			}
    break;

  case 116:
#line 1499 "ilasm_grammar.y"
    {
				/* Set the class layout size */
				ILClassLayout *layout;
				layout = ILClassLayoutGetFromOwner(ILAsmClass);
				if(!layout)
				{
					/* Create a new layout record */
					layout = ILClassLayoutCreate(ILAsmImage, 0, ILAsmClass,
												 0, (ILUInt32)((yyvsp[(2) - (2)].integer)));
					if(!layout)
					{
						ILAsmOutOfMemory();
					}
				}
				else
				{
					ILClassLayoutSetClassSize(layout, (ILUInt32)((yyvsp[(2) - (2)].integer)));
				}
			}
    break;

  case 117:
#line 1518 "ilasm_grammar.y"
    {
				/* Set the class packing size */
				ILClassLayout *layout;
				layout = ILClassLayoutGetFromOwner(ILAsmClass);
				if(!layout)
				{
					/* Create a new layout record */
					layout = ILClassLayoutCreate(ILAsmImage, 0, ILAsmClass,
												 (ILUInt32)((yyvsp[(2) - (2)].integer)), 0);
					if(!layout)
					{
						ILAsmOutOfMemory();
					}
				}
				else
				{
					ILClassLayoutSetPackingSize(layout, (ILUInt32)((yyvsp[(2) - (2)].integer)));
				}
			}
    break;

  case 119:
#line 1540 "ilasm_grammar.y"
    {
				ILType *sig;
				ILOverride *over;
				ILToken token;
				ILMethod *decl;
				ILMethod *body;

				/* Create a signature block for the methods */
				sig = CreateMethodSig((yyvsp[(6) - (13)].integer), (yyvsp[(7) - (13)].type), (yyvsp[(12) - (13)].params).paramFirst, 0, 1);

				/* Create a MemberRef for the first part of the override */
				token = ILAsmResolveMember((yyvsp[(2) - (13)].typeSpec).item, (yyvsp[(4) - (13)].strValue).string, sig,
										   IL_META_MEMBERKIND_METHOD);
				decl = ILMethod_FromToken(ILAsmImage, token);

				/* Create a MemberRef for the second part of the override */
				token = ILAsmResolveMember((yyvsp[(8) - (13)].typeSpec).item, (yyvsp[(10) - (13)].strValue).string, sig,
										   IL_META_MEMBERKIND_METHOD);
				body = ILMethod_FromToken(ILAsmImage, token);

				/* Create the override block */
				if(decl && body)
				{
					over = ILOverrideCreate(ILAsmClass, 0, decl, body);
					if(!over)
					{
						ILAsmOutOfMemory();
					}
				}
			}
    break;

  case 120:
#line 1578 "ilasm_grammar.y"
    {
				ILField *field;
				ILFieldMarshal *marshal;
				ILConstant *constant;
				ILModule *module;

				field = ILAsmFieldCreate(ILAsmClass, (yyvsp[(5) - (7)].strValue).string, (yyvsp[(3) - (7)].fieldAttrs).flags, (yyvsp[(4) - (7)].type));
				if(((yyvsp[(3) - (7)].fieldAttrs).flags & IL_META_FIELDDEF_HAS_FIELD_MARSHAL) != 0)
				{
					/* Add marshalling information to the field */
					marshal = ILFieldMarshalCreate(ILAsmImage, 0,
												   ILToProgramItem(field));
					if(!marshal)
					{
						ILAsmOutOfMemory();
					}
					if(!ILFieldMarshalSetType(marshal,
											  (yyvsp[(3) - (7)].fieldAttrs).nativeType.string,
											  (yyvsp[(3) - (7)].fieldAttrs).nativeType.len))
					{
						ILAsmOutOfMemory();
					}
				}
				if(((yyvsp[(3) - (7)].fieldAttrs).flags & IL_META_FIELDDEF_PINVOKE_IMPL) != 0)
				{
					/* Add PInvoke information to the field */
					module = FindModuleRef(ILAsmImage, (yyvsp[(3) - (7)].fieldAttrs).name1);
					if(!ILPInvokeFieldCreate(field, 0, (yyvsp[(3) - (7)].fieldAttrs).pinvokeAttrs,
										     module, (yyvsp[(3) - (7)].fieldAttrs).name2))
					{
						ILAsmOutOfMemory();
					}
				}
				if((yyvsp[(2) - (7)].integer) != (ILInt64)0xFFFFFFFF)
				{
					/* Set the layout information for the field */
					if(!ILFieldLayoutCreate(ILAsmImage, 0,
											field, (ILUInt32)((yyvsp[(2) - (7)].integer))))
					{
						ILAsmOutOfMemory();
					}
				}
				if((yyvsp[(6) - (7)].datalabel).offset != (ILInt64)0xFFFFFFFF)
				{
					if((yyvsp[(6) - (7)].datalabel).offset != -1 && (yyvsp[(6) - (7)].datalabel).label != NULL)
					{
						/* Set the RVA information for the field */
						if(!ILFieldRVACreate(ILAsmImage, 0,
											 field, (ILUInt32)((yyvsp[(6) - (7)].datalabel).offset)))
						{
							ILAsmOutOfMemory();
						}
					}
					else
					{
						RegisterFieldRvaLabel((yyvsp[(6) - (7)].datalabel).label,field);
					}
				}
				if((yyvsp[(7) - (7)].fieldInit).type != IL_META_ELEMTYPE_VOID)
				{
					/* Attach a constant to the field */
					constant = ILConstantCreate(ILAsmImage, 0,
												ILToProgramItem(field),
												(yyvsp[(7) - (7)].fieldInit).type);
					if(!constant)
					{
						ILAsmOutOfMemory();
					}
					if(!ILConstantSetValue(constant, (yyvsp[(7) - (7)].fieldInit).valueBlob.string,
										   (yyvsp[(7) - (7)].fieldInit).valueBlob.len))
					{
						ILAsmOutOfMemory();
					}
				}
				ILAsmBuildPushScope(field);

				/* If we are in the global module class, and the field
				   is public, then change the module class to public */
				if(ILAsmClass == ILAsmModuleClass && ILField_IsPublic(field))
				{
					ILClassSetAttrs(ILAsmClass,
									IL_META_TYPEDEF_VISIBILITY_MASK,
									IL_META_TYPEDEF_PUBLIC);
				}
			}
    break;

  case 121:
#line 1663 "ilasm_grammar.y"
    {
				/* Keep the field token, in case the old style of
				   assigning custom attributes to fields is used */
				ILToken token = ILAsmLastToken;
				ILAsmBuildPopScope();
				ILAsmLastToken = token;
			}
    break;

  case 130:
#line 1699 "ilasm_grammar.y"
    { (yyval.integer) = (ILInt64)0xFFFFFFFF; }
    break;

  case 131:
#line 1700 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(2) - (3)].integer); }
    break;

  case 132:
#line 1704 "ilasm_grammar.y"
    { (yyval.datalabel).offset = (ILInt64)0xFFFFFFFF; (yyval.datalabel).label = 0; }
    break;

  case 133:
#line 1705 "ilasm_grammar.y"
    {
				(yyval.datalabel).label = (yyvsp[(2) - (2)].strValue).string;
				(yyval.datalabel).offset = (ILInt64)ILAsmDataResolveLabel((yyvsp[(2) - (2)].strValue).string);
			}
    break;

  case 134:
#line 1709 "ilasm_grammar.y"
    { (yyval.datalabel).offset = (yyvsp[(2) - (2)].integer); (yyval.datalabel).label = 0; }
    break;

  case 135:
#line 1713 "ilasm_grammar.y"
    {
				(yyval.fieldInit).type = IL_META_ELEMTYPE_VOID;
				(yyval.fieldInit).valueBlob.string = "";
				(yyval.fieldInit).valueBlob.len = 0;
			}
    break;

  case 136:
#line 1718 "ilasm_grammar.y"
    { (yyval.fieldInit) = (yyvsp[(2) - (2)].fieldInit); }
    break;

  case 137:
#line 1722 "ilasm_grammar.y"
    { (yyval.fieldAttrs).flags = 0;
							  (yyval.fieldAttrs).nativeType.string = 0;
							  (yyval.fieldAttrs).nativeType.len = 0; }
    break;

  case 138:
#line 1725 "ilasm_grammar.y"
    { (yyval.fieldAttrs) = (yyvsp[(1) - (1)].fieldAttrs); }
    break;

  case 139:
#line 1729 "ilasm_grammar.y"
    { (yyval.fieldAttrs) = (yyvsp[(1) - (1)].fieldAttrs); }
    break;

  case 140:
#line 1730 "ilasm_grammar.y"
    {
				(yyval.fieldAttrs).flags = (yyvsp[(1) - (2)].fieldAttrs).flags | (yyvsp[(2) - (2)].fieldAttrs).flags;
				if(((yyvsp[(1) - (2)].fieldAttrs).flags & IL_META_FIELDDEF_HAS_FIELD_MARSHAL) != 0)
				{
					(yyval.fieldAttrs).nativeType = (yyvsp[(1) - (2)].fieldAttrs).nativeType;
					if(((yyvsp[(2) - (2)].fieldAttrs).flags & IL_META_FIELDDEF_HAS_FIELD_MARSHAL) != 0)
					{
						yyerror("duplicate `marshal' attribute on field");
					}
				}
				else if(((yyvsp[(2) - (2)].fieldAttrs).flags & IL_META_FIELDDEF_HAS_FIELD_MARSHAL) != 0)
				{
					(yyval.fieldAttrs).nativeType = (yyvsp[(2) - (2)].fieldAttrs).nativeType;
				}
				else
				{
					(yyval.fieldAttrs).nativeType.string = 0;
					(yyval.fieldAttrs).nativeType.len = 0;
				}
				if(((yyvsp[(1) - (2)].fieldAttrs).flags & IL_META_FIELDDEF_PINVOKE_IMPL) != 0)
				{
					(yyval.fieldAttrs).pinvokeAttrs = (yyvsp[(1) - (2)].fieldAttrs).pinvokeAttrs;
					(yyval.fieldAttrs).name1 = (yyvsp[(1) - (2)].fieldAttrs).name1;
					(yyval.fieldAttrs).name2 = (yyvsp[(1) - (2)].fieldAttrs).name2;
					if(((yyvsp[(2) - (2)].fieldAttrs).flags & IL_META_FIELDDEF_PINVOKE_IMPL) != 0)
					{
						yyerror("duplicate `pinvokeimpl' attribute on field");
					}
				}
				else if(((yyvsp[(2) - (2)].fieldAttrs).flags & IL_META_FIELDDEF_PINVOKE_IMPL) != 0)
				{
					(yyval.fieldAttrs).pinvokeAttrs = (yyvsp[(2) - (2)].fieldAttrs).pinvokeAttrs;
					(yyval.fieldAttrs).name1 = (yyvsp[(2) - (2)].fieldAttrs).name1;
					(yyval.fieldAttrs).name2 = (yyvsp[(2) - (2)].fieldAttrs).name2;
				}
				else
				{
					(yyval.fieldAttrs).pinvokeAttrs = 0;
					(yyval.fieldAttrs).name1 = 0;
					(yyval.fieldAttrs).name2 = 0;
				}
			}
    break;

  case 141:
#line 1775 "ilasm_grammar.y"
    { SET_FIELD(STATIC); }
    break;

  case 142:
#line 1776 "ilasm_grammar.y"
    { SET_FIELD(PUBLIC); }
    break;

  case 143:
#line 1777 "ilasm_grammar.y"
    { SET_FIELD(PRIVATE); }
    break;

  case 144:
#line 1778 "ilasm_grammar.y"
    { SET_FIELD(FAMILY); }
    break;

  case 145:
#line 1779 "ilasm_grammar.y"
    { SET_FIELD(INIT_ONLY); }
    break;

  case 146:
#line 1780 "ilasm_grammar.y"
    { SET_FIELD(RT_SPECIAL_NAME); }
    break;

  case 147:
#line 1781 "ilasm_grammar.y"
    { SET_FIELD(SPECIAL_NAME); }
    break;

  case 148:
#line 1782 "ilasm_grammar.y"
    {
				(yyval.fieldAttrs).flags = IL_META_FIELDDEF_HAS_FIELD_MARSHAL;
				(yyval.fieldAttrs).nativeType = (yyvsp[(3) - (4)].strValue);
			}
    break;

  case 149:
#line 1786 "ilasm_grammar.y"
    { SET_FIELD(ASSEMBLY); }
    break;

  case 150:
#line 1787 "ilasm_grammar.y"
    { SET_FIELD(FAM_AND_ASSEM); }
    break;

  case 151:
#line 1788 "ilasm_grammar.y"
    { SET_FIELD(FAM_OR_ASSEM); }
    break;

  case 152:
#line 1789 "ilasm_grammar.y"
    { SET_FIELD(COMPILER_CONTROLLED); /* Old name */ }
    break;

  case 153:
#line 1790 "ilasm_grammar.y"
    { SET_FIELD(COMPILER_CONTROLLED); }
    break;

  case 154:
#line 1791 "ilasm_grammar.y"
    { SET_FIELD(LITERAL); }
    break;

  case 155:
#line 1792 "ilasm_grammar.y"
    { SET_FIELD(NOT_SERIALIZED); }
    break;

  case 156:
#line 1794 "ilasm_grammar.y"
    {
				(yyval.fieldAttrs).flags = IL_META_FIELDDEF_PINVOKE_IMPL;
				(yyval.fieldAttrs).nativeType.string = 0;
				(yyval.fieldAttrs).nativeType.len = 0;
			    (yyval.fieldAttrs).pinvokeAttrs = (yyvsp[(6) - (7)].integer);
			    (yyval.fieldAttrs).name1 = (yyvsp[(3) - (7)].strValue).string;
			    (yyval.fieldAttrs).name2 = (yyvsp[(5) - (7)].strValue).string;
			}
    break;

  case 157:
#line 1802 "ilasm_grammar.y"
    {
				(yyval.fieldAttrs).flags = IL_META_FIELDDEF_PINVOKE_IMPL;
				(yyval.fieldAttrs).nativeType.string = 0;
				(yyval.fieldAttrs).nativeType.len = 0;
			    (yyval.fieldAttrs).pinvokeAttrs = (yyvsp[(4) - (5)].integer);
				(yyval.fieldAttrs).name1 = (yyvsp[(3) - (5)].strValue).string;
				(yyval.fieldAttrs).name2 = 0;
			}
    break;

  case 158:
#line 1810 "ilasm_grammar.y"
    {
				(yyval.fieldAttrs).flags = IL_META_FIELDDEF_PINVOKE_IMPL;
				(yyval.fieldAttrs).nativeType.string = 0;
				(yyval.fieldAttrs).nativeType.len = 0;
			    (yyval.fieldAttrs).pinvokeAttrs = (yyvsp[(3) - (4)].integer);
				(yyval.fieldAttrs).name1 = 0;
				(yyval.fieldAttrs).name2 = 0;
			}
    break;

  case 159:
#line 1821 "ilasm_grammar.y"
    {
				unsigned char bytes[4];
				SetFloat(bytes, (ILFloat)((yyvsp[(3) - (4)].real)));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R4;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 4);
			}
    break;

  case 160:
#line 1827 "ilasm_grammar.y"
    {
				unsigned char bytes[8];
				SetDouble(bytes, (ILDouble)((yyvsp[(3) - (4)].real)));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R8;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 8);
			}
    break;

  case 161:
#line 1833 "ilasm_grammar.y"
    {
				unsigned char bytes[4];
				bytes[3] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 24);
				bytes[2] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 16);
				bytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				bytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R4;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 4);
			}
    break;

  case 162:
#line 1842 "ilasm_grammar.y"
    {
				unsigned char bytes[8];
				bytes[7] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 56);
				bytes[6] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 48);
				bytes[5] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 40);
				bytes[4] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 32);
				bytes[3] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 24);
				bytes[2] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 16);
				bytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				bytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R8;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 8);
			}
    break;

  case 163:
#line 1855 "ilasm_grammar.y"
    {
				unsigned char bytes[4];
				bytes[3] = (ILUInt8)0xFF;
				bytes[2] = (ILUInt8)0xC0;
				bytes[1] = (ILUInt8)0x00;
				bytes[0] = (ILUInt8)0x00;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R4;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 4);
			}
    break;

  case 164:
#line 1864 "ilasm_grammar.y"
    {
				unsigned char bytes[8];
				bytes[7] = (ILUInt8)0xFF;
				bytes[6] = (ILUInt8)0xF8;
				bytes[5] = (ILUInt8)0x00;
				bytes[4] = (ILUInt8)0x00;
				bytes[3] = (ILUInt8)0x00;
				bytes[2] = (ILUInt8)0x00;
				bytes[1] = (ILUInt8)0x00;
				bytes[0] = (ILUInt8)0x00;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R8;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 8);
			}
    break;

  case 165:
#line 1877 "ilasm_grammar.y"
    {
				unsigned char bytes[4];
				bytes[3] = (ILUInt8)0x7F;
				bytes[2] = (ILUInt8)0x80;
				bytes[1] = (ILUInt8)0x00;
				bytes[0] = (ILUInt8)0x00;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R4;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 4);
			}
    break;

  case 166:
#line 1886 "ilasm_grammar.y"
    {
				unsigned char bytes[8];
				bytes[7] = (ILUInt8)0x7F;
				bytes[6] = (ILUInt8)0xF0;
				bytes[5] = (ILUInt8)0x00;
				bytes[4] = (ILUInt8)0x00;
				bytes[3] = (ILUInt8)0x00;
				bytes[2] = (ILUInt8)0x00;
				bytes[1] = (ILUInt8)0x00;
				bytes[0] = (ILUInt8)0x00;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R8;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 8);
			}
    break;

  case 167:
#line 1899 "ilasm_grammar.y"
    {
				unsigned char bytes[4];
				bytes[3] = (ILUInt8)0xFF;
				bytes[2] = (ILUInt8)0x80;
				bytes[1] = (ILUInt8)0x00;
				bytes[0] = (ILUInt8)0x00;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R4;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 4);
			}
    break;

  case 168:
#line 1908 "ilasm_grammar.y"
    {
				unsigned char bytes[8];
				bytes[7] = (ILUInt8)0xFF;
				bytes[6] = (ILUInt8)0xF0;
				bytes[5] = (ILUInt8)0x00;
				bytes[4] = (ILUInt8)0x00;
				bytes[3] = (ILUInt8)0x00;
				bytes[2] = (ILUInt8)0x00;
				bytes[1] = (ILUInt8)0x00;
				bytes[0] = (ILUInt8)0x00;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_R8;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 8);
			}
    break;

  case 169:
#line 1921 "ilasm_grammar.y"
    {
				unsigned char bytes[8];
				bytes[7] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 56);
				bytes[6] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 48);
				bytes[5] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 40);
				bytes[4] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 32);
				bytes[3] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 24);
				bytes[2] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 16);
				bytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				bytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_I8;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 8);
			}
    break;

  case 170:
#line 1934 "ilasm_grammar.y"
    {
				unsigned char bytes[4];
				bytes[3] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 24);
				bytes[2] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 16);
				bytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				bytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_I4;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 4);
			}
    break;

  case 171:
#line 1943 "ilasm_grammar.y"
    {
				unsigned char bytes[2];
				bytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				bytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_I2;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 2);
			}
    break;

  case 172:
#line 1950 "ilasm_grammar.y"
    {
				unsigned char bytes[1];
				bytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_I1;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 1);
			}
    break;

  case 173:
#line 1956 "ilasm_grammar.y"
    {
				unsigned char bytes[2];
				bytes[1] = (ILUInt8)((yyvsp[(3) - (4)].integer) >> 8);
				bytes[0] = (ILUInt8)((yyvsp[(3) - (4)].integer));
				(yyval.fieldInit).type = IL_META_ELEMTYPE_CHAR;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 2);
			}
    break;

  case 174:
#line 1963 "ilasm_grammar.y"
    {
				unsigned char bytes[1];
				bytes[0] = 1;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_BOOLEAN;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 1);
			}
    break;

  case 175:
#line 1969 "ilasm_grammar.y"
    {
				unsigned char bytes[1];
				bytes[0] = 0;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_BOOLEAN;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 1);
			}
    break;

  case 176:
#line 1975 "ilasm_grammar.y"
    {
				(yyval.fieldInit).type = IL_META_ELEMTYPE_STRING;
				(yyval.fieldInit).valueBlob = PackUnicodeString((yyvsp[(1) - (1)].strValue));
			}
    break;

  case 177:
#line 1979 "ilasm_grammar.y"
    {
				/* obsolete */
				(yyval.fieldInit).type = IL_META_ELEMTYPE_STRING;
				(yyval.fieldInit).valueBlob = PackUnicodeString((yyvsp[(4) - (5)].strValue));
			}
    break;

  case 178:
#line 1984 "ilasm_grammar.y"
    {
				(yyval.fieldInit).type = IL_META_ELEMTYPE_STRING;
				(yyval.fieldInit).valueBlob = (yyvsp[(2) - (2)].strValue);
			}
    break;

  case 179:
#line 1988 "ilasm_grammar.y"
    {
				unsigned char bytes[4];
				bytes[0] = 0;
				bytes[1] = 0;
				bytes[2] = 0;
				bytes[3] = 0;
				(yyval.fieldInit).type = IL_META_ELEMTYPE_CLASS;
				(yyval.fieldInit).valueBlob = ILInternString((char *)bytes, 4);
			}
    break;

  case 180:
#line 2007 "ilasm_grammar.y"
    {
				ILType *sig;
				ILMethod *method;
				ILUInt32 callConv;
				ILAsmParamInfo *genericParams;
				ILAsmParamInfo *nextGeneric;
				ILUInt32 genericNum;
				ILGenericPar *genPar;
				ILProgramItem *constraint;
				ILTypeSpec *spec;

				/* Create the method definition */
				callConv = (ILUInt32)((yyvsp[(3) - (11)].integer));
				if(((yyvsp[(2) - (11)].methodAttrs).flags & IL_META_METHODDEF_STATIC) == 0)
				{
					/* Add "instance" to the calling conventions, because
					   ECMA allows it to be omitted from non-static methods
					   (Partition II, section 14.3) */
					callConv |= IL_META_CALLCONV_HASTHIS;
				}
				sig = CreateMethodSig(callConv, (yyvsp[(5) - (11)].marshType).type, (yyvsp[(9) - (11)].params).paramFirst,
									  (yyvsp[(7) - (11)].params).paramFirst, 0);
				method = ILAsmMethodCreate
							(ILAsmClass, (yyvsp[(6) - (11)].strValue).string, (yyvsp[(2) - (11)].methodAttrs).flags, sig);
				ILMethodSetImplAttrs(method, ~0, (ILUInt16)((yyvsp[(11) - (11)].integer)));
				ILAsmOutAddParams((yyvsp[(9) - (11)].params).paramFirst, callConv);
				AddMethodParams(method, (yyvsp[(4) - (11)].integer), (yyvsp[(5) - (11)].marshType).nativeType, (yyvsp[(9) - (11)].params).paramFirst);
				if(((yyvsp[(2) - (11)].methodAttrs).flags & IL_META_METHODDEF_PINVOKE_IMPL) != 0)
				{
					ILModule *module;
					module = FindModuleRef(ILAsmImage, (yyvsp[(2) - (11)].methodAttrs).name1);
					if(!ILPInvokeCreate(method, 0, (yyvsp[(2) - (11)].methodAttrs).pinvokeAttrs,
										module, (yyvsp[(2) - (11)].methodAttrs).name2))
					{
						ILAsmOutOfMemory();
					}
				}

				/* Add the formal generic parameters to the method */
				genericNum = 0;
				genericParams = (yyvsp[(7) - (11)].params).paramFirst;
				while(genericParams != 0)
				{
					nextGeneric = genericParams->next;
					genPar = ILGenericParCreate
						(ILAsmImage, 0, ILToProgramItem(method), genericNum);
					if(!genPar)
					{
						ILAsmOutOfMemory();
					}
					if(!ILGenericParSetName(genPar, genericParams->name))
					{
						ILAsmOutOfMemory();
					}
					if(genericParams->type)
					{
						if(ILType_IsClass(genericParams->type) ||
			   			   ILType_IsValueType(genericParams->type))
						{
							constraint = ILToProgramItem
								(ILType_ToClass(genericParams->type));
						}
						else
						{
							spec = ILTypeSpecCreate
								(ILAsmImage, 0, genericParams->type);
							if(!spec)
							{
								ILAsmOutOfMemory();
							}
							constraint = ILToProgramItem(spec);
						}
						ILGenericParSetConstraint(genPar, constraint);
					}
					ILFree(genericParams);
					genericParams = nextGeneric;
					++genericNum;
				}

				/* The current scope is now the method */
				ILAsmBuildPushScope(method);

				/* If we are in the global module class, and the method
				   is public, then change the module class to public */
				if(ILAsmClass == ILAsmModuleClass && ILMethod_IsPublic(method))
				{
					ILClassSetAttrs(ILAsmClass,
									IL_META_TYPEDEF_VISIBILITY_MASK,
									IL_META_TYPEDEF_PUBLIC);
				}
			}
    break;

  case 181:
#line 2101 "ilasm_grammar.y"
    {
				(yyval.marshType).type = (yyvsp[(1) - (1)].type);
				(yyval.marshType).nativeType.string = "";
				(yyval.marshType).nativeType.len = 0;
			}
    break;

  case 182:
#line 2106 "ilasm_grammar.y"
    {
				(yyval.marshType).type = (yyvsp[(1) - (5)].type);
				(yyval.marshType).nativeType = (yyvsp[(4) - (5)].strValue);
			}
    break;

  case 183:
#line 2113 "ilasm_grammar.y"
    { (yyval.strValue) = ILInternString(".ctor", 5); }
    break;

  case 184:
#line 2114 "ilasm_grammar.y"
    { (yyval.strValue) = ILInternString(".cctor", 6); }
    break;

  case 185:
#line 2115 "ilasm_grammar.y"
    { (yyval.strValue) = (yyvsp[(1) - (1)].strValue); }
    break;

  case 186:
#line 2119 "ilasm_grammar.y"
    { (yyval.methodAttrs).flags = 0; (yyval.methodAttrs).pinvokeAttrs = 0;
							  (yyval.methodAttrs).name1 = 0; (yyval.methodAttrs).name2 = 0; }
    break;

  case 187:
#line 2121 "ilasm_grammar.y"
    { (yyval.methodAttrs) = (yyvsp[(1) - (1)].methodAttrs); }
    break;

  case 188:
#line 2125 "ilasm_grammar.y"
    { (yyval.methodAttrs) = (yyvsp[(1) - (1)].methodAttrs); }
    break;

  case 189:
#line 2126 "ilasm_grammar.y"
    {
				(yyval.methodAttrs).flags = (yyvsp[(1) - (2)].methodAttrs).flags | (yyvsp[(2) - (2)].methodAttrs).flags;
				if(((yyvsp[(1) - (2)].methodAttrs).flags & IL_META_METHODDEF_PINVOKE_IMPL) != 0)
				{
					(yyval.methodAttrs).pinvokeAttrs = (yyvsp[(1) - (2)].methodAttrs).pinvokeAttrs;
					(yyval.methodAttrs).name1 = (yyvsp[(1) - (2)].methodAttrs).name1;
					(yyval.methodAttrs).name2 = (yyvsp[(1) - (2)].methodAttrs).name2;
					if(((yyvsp[(2) - (2)].methodAttrs).flags & IL_META_METHODDEF_PINVOKE_IMPL) != 0)
					{
						yyerror("duplicate `pinvokeimpl' attribute on method");
					}
				}
				else if(((yyvsp[(2) - (2)].methodAttrs).flags & IL_META_METHODDEF_PINVOKE_IMPL) != 0)
				{
					(yyval.methodAttrs).pinvokeAttrs = (yyvsp[(2) - (2)].methodAttrs).pinvokeAttrs;
					(yyval.methodAttrs).name1 = (yyvsp[(2) - (2)].methodAttrs).name1;
					(yyval.methodAttrs).name2 = (yyvsp[(2) - (2)].methodAttrs).name2;
				}
				else
				{
					(yyval.methodAttrs).pinvokeAttrs = 0;
					(yyval.methodAttrs).name1 = 0;
					(yyval.methodAttrs).name2 = 0;
				}
			}
    break;

  case 190:
#line 2154 "ilasm_grammar.y"
    { SET_METHOD(STATIC); }
    break;

  case 191:
#line 2155 "ilasm_grammar.y"
    { SET_METHOD(PUBLIC); }
    break;

  case 192:
#line 2156 "ilasm_grammar.y"
    { SET_METHOD(PRIVATE); }
    break;

  case 193:
#line 2157 "ilasm_grammar.y"
    { SET_METHOD(FAMILY); }
    break;

  case 194:
#line 2158 "ilasm_grammar.y"
    { SET_METHOD(FINAL); }
    break;

  case 195:
#line 2159 "ilasm_grammar.y"
    { SET_METHOD(SPECIAL_NAME); }
    break;

  case 196:
#line 2160 "ilasm_grammar.y"
    { SET_METHOD(VIRTUAL); }
    break;

  case 197:
#line 2161 "ilasm_grammar.y"
    { SET_METHOD(ABSTRACT); }
    break;

  case 198:
#line 2162 "ilasm_grammar.y"
    { SET_METHOD(ASSEM); }
    break;

  case 199:
#line 2163 "ilasm_grammar.y"
    { SET_METHOD(FAM_AND_ASSEM); }
    break;

  case 200:
#line 2164 "ilasm_grammar.y"
    { SET_METHOD(FAM_OR_ASSEM); }
    break;

  case 201:
#line 2165 "ilasm_grammar.y"
    { SET_METHOD(COMPILER_CONTROLLED); /* Old name */ }
    break;

  case 202:
#line 2166 "ilasm_grammar.y"
    { SET_METHOD(COMPILER_CONTROLLED); }
    break;

  case 203:
#line 2167 "ilasm_grammar.y"
    { SET_METHOD(HIDE_BY_SIG); }
    break;

  case 204:
#line 2168 "ilasm_grammar.y"
    { SET_METHOD(NEW_SLOT); }
    break;

  case 205:
#line 2169 "ilasm_grammar.y"
    { SET_METHOD(RT_SPECIAL_NAME); }
    break;

  case 206:
#line 2170 "ilasm_grammar.y"
    { SET_METHOD(REQUIRE_SEC_OBJECT); }
    break;

  case 207:
#line 2171 "ilasm_grammar.y"
    { SET_METHOD(UNMANAGED_EXPORT); }
    break;

  case 208:
#line 2173 "ilasm_grammar.y"
    {
				(yyval.methodAttrs).flags = IL_META_METHODDEF_PINVOKE_IMPL;
			    (yyval.methodAttrs).pinvokeAttrs = (yyvsp[(6) - (7)].integer);
			    (yyval.methodAttrs).name1 = (yyvsp[(3) - (7)].strValue).string;
			    (yyval.methodAttrs).name2 = (yyvsp[(5) - (7)].strValue).string;
			}
    break;

  case 209:
#line 2179 "ilasm_grammar.y"
    {
				(yyval.methodAttrs).flags = IL_META_METHODDEF_PINVOKE_IMPL;
			    (yyval.methodAttrs).pinvokeAttrs = (yyvsp[(4) - (5)].integer);
				(yyval.methodAttrs).name1 = (yyvsp[(3) - (5)].strValue).string;
				(yyval.methodAttrs).name2 = 0;
			}
    break;

  case 210:
#line 2185 "ilasm_grammar.y"
    {
				(yyval.methodAttrs).flags = IL_META_METHODDEF_PINVOKE_IMPL;
			    (yyval.methodAttrs).pinvokeAttrs = (yyvsp[(3) - (4)].integer);
				(yyval.methodAttrs).name1 = 0;
				(yyval.methodAttrs).name2 = 0;
			}
    break;

  case 211:
#line 2194 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 212:
#line 2195 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 213:
#line 2199 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 214:
#line 2200 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 215:
#line 2204 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_NO_MANGLE; }
    break;

  case 216:
#line 2205 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CHAR_SET_ANSI; }
    break;

  case 217:
#line 2206 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CHAR_SET_UNICODE; }
    break;

  case 218:
#line 2207 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CHAR_SET_AUTO; }
    break;

  case 219:
#line 2208 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_OLE; }
    break;

  case 220:
#line 2209 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_SUPPORTS_LAST_ERROR; }
    break;

  case 221:
#line 2210 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CALL_CONV_WINAPI; }
    break;

  case 222:
#line 2211 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CALL_CONV_CDECL; }
    break;

  case 223:
#line 2212 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CALL_CONV_STDCALL; }
    break;

  case 224:
#line 2213 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CALL_CONV_THISCALL; }
    break;

  case 225:
#line 2214 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PINVOKE_CALL_CONV_FASTCALL; }
    break;

  case 226:
#line 2218 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 227:
#line 2219 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 228:
#line 2223 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 229:
#line 2224 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 230:
#line 2228 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_NATIVE; }
    break;

  case 231:
#line 2229 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_IL; /* Old name */ }
    break;

  case 232:
#line 2230 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_IL; /* New name */ }
    break;

  case 233:
#line 2231 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_OPTIL; }
    break;

  case 234:
#line 2232 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_MANAGED; }
    break;

  case 235:
#line 2233 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_UNMANAGED; }
    break;

  case 236:
#line 2234 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_FORWARD_REF; }
    break;

  case 237:
#line 2235 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_PRESERVE_SIG; /* Old */ }
    break;

  case 238:
#line 2236 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_PRESERVE_SIG; }
    break;

  case 239:
#line 2237 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_RUNTIME; }
    break;

  case 240:
#line 2238 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_INTERNAL_CALL; }
    break;

  case 241:
#line 2239 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_SYNCHRONIZED; }
    break;

  case 242:
#line 2240 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_METHODIMPL_NO_INLINING; }
    break;

  case 243:
#line 2244 "ilasm_grammar.y"
    {
				ILAsmOutFinalizeMethod((ILMethod *)ILAsmCurrScope);
			  	ILAsmBuildPopScope();
			}
    break;

  case 244:
#line 2248 "ilasm_grammar.y"
    {
				ILAsmOutFinalizeMethod((ILMethod *)ILAsmCurrScope);
			  	ILAsmBuildPopScope();
			}
    break;

  case 247:
#line 2260 "ilasm_grammar.y"
    { ILAsmOutSimple((yyvsp[(2) - (2)].integer) & 0xFF); }
    break;

  case 249:
#line 2262 "ilasm_grammar.y"
    { ILAsmOutMaxStack((ILUInt32)((yyvsp[(2) - (2)].integer))); }
    break;

  case 250:
#line 2263 "ilasm_grammar.y"
    {
				ILAsmOutAddLocals((yyvsp[(3) - (4)].params).paramFirst);
			}
    break;

  case 251:
#line 2266 "ilasm_grammar.y"
    {
				ILAsmOutZeroInit();
				ILAsmOutAddLocals((yyvsp[(4) - (5)].params).paramFirst);
			}
    break;

  case 252:
#line 2270 "ilasm_grammar.y"
    {
				/* Extension for use with "cscc": declare a variable name */
				ILAsmOutDeclareVarName((yyvsp[(3) - (6)].strValue).string, (ILUInt32)((yyvsp[(5) - (6)].integer)));
			}
    break;

  case 253:
#line 2274 "ilasm_grammar.y"
    { ILWriterSetEntryPoint
									(ILAsmWriter, (ILMethod *)ILAsmCurrScope); }
    break;

  case 254:
#line 2276 "ilasm_grammar.y"
    { ILAsmOutZeroInit(); }
    break;

  case 257:
#line 2279 "ilasm_grammar.y"
    { ILAsmOutLabel((yyvsp[(1) - (2)].strValue).string); }
    break;

  case 258:
#line 2280 "ilasm_grammar.y"
    { ILAsmOutIntLabel((yyvsp[(1) - (2)].integer)); }
    break;

  case 262:
#line 2284 "ilasm_grammar.y"
    { /* TODO */ }
    break;

  case 263:
#line 2285 "ilasm_grammar.y"
    {
				ILType *sig;
				ILOverride *over;
				ILToken token;
				ILMethod *decl;

				/* Get the signature block for the current method */
				sig = ILMethod_Signature((ILMethod *)ILAsmCurrScope);

				/* Create a MemberRef for the first part of the override */
				token = ILAsmResolveMember((yyvsp[(2) - (4)].typeSpec).item, (yyvsp[(4) - (4)].strValue).string, sig,
										   IL_META_MEMBERKIND_METHOD);
				decl = ILMethod_FromToken(ILAsmImage, token);

				/* Create the override block */
				if(decl)
				{
					over = ILOverrideCreate(ILAsmClass, 0,
											decl, (ILMethod *)ILAsmCurrScope);
					if(!over)
					{
						ILAsmOutOfMemory();
					}
				}
			}
    break;

  case 264:
#line 2310 "ilasm_grammar.y"
    { /* Nothing to do here */ }
    break;

  case 265:
#line 2311 "ilasm_grammar.y"
    {
				ILParameter *param;
				param = ILAsmFindParameter((ILMethod *)ILAsmCurrScope,
										   (ILUInt32)((yyvsp[(3) - (4)].integer)));
				if(param)
				{
					/* Set the last token, to allow custom attributes
					   to be attached to the parameter */
					ILAsmLastToken = ILParameter_Token(param);
				}
			}
    break;

  case 266:
#line 2322 "ilasm_grammar.y"
    {
				ILParameter *param;
				ILConstant *constant;
				param = ILAsmFindParameter((ILMethod *)ILAsmCurrScope,
										   (ILUInt32)((yyvsp[(3) - (6)].integer)));
				if(param)
				{
					/* Attach a constant token to the parameter */
					constant = ILConstantCreate(ILAsmImage, 0,
												ILToProgramItem(param),
												(yyvsp[(6) - (6)].fieldInit).type);
					if(!constant)
					{
						ILAsmOutOfMemory();
					}
					if(!ILConstantSetValue(constant, (yyvsp[(6) - (6)].fieldInit).valueBlob.string,
										   (yyvsp[(6) - (6)].fieldInit).valueBlob.len))
					{
						ILAsmOutOfMemory();
					}

					/* Set the last token, to allow custom attributes
					   to be attached to the parameter */
					ILAsmLastToken = ILParameter_Token(param);
				}
			}
    break;

  case 267:
#line 2351 "ilasm_grammar.y"
    {
				ILAsmOutFinalizeMethod((ILMethod *)ILAsmCurrScope);
			  	ILAsmBuildPopScope();
			}
    break;

  case 268:
#line 2355 "ilasm_grammar.y"
    {
				ILAsmOutFinalizeMethod((ILMethod *)ILAsmCurrScope);
			  	ILAsmBuildPopScope();
			}
    break;

  case 271:
#line 2367 "ilasm_grammar.y"
    { ILAsmOutMaxStack((ILUInt32)((yyvsp[(2) - (2)].integer)));  }
    break;

  case 272:
#line 2368 "ilasm_grammar.y"
    { ILAsmOutMaxLocals((ILUInt32)((yyvsp[(2) - (2)].integer))); }
    break;

  case 275:
#line 2371 "ilasm_grammar.y"
    { /* nothing to do here */ }
    break;

  case 276:
#line 2372 "ilasm_grammar.y"
    { ILAsmOutLabel((yyvsp[(1) - (2)].strValue).string); }
    break;

  case 277:
#line 2373 "ilasm_grammar.y"
    { ILAsmOutIntLabel((yyvsp[(1) - (2)].integer)); }
    break;

  case 281:
#line 2380 "ilasm_grammar.y"
    {
				/* Record the start of the block */
				(yyval.scope).start = ILAsmOutUniqueLabel();
				ILAsmOutPushVarScope((yyval.scope).start);
			}
    break;

  case 282:
#line 2385 "ilasm_grammar.y"
    {
	  			/* Record the end of the block */
				(yyval.scope).start = (yyvsp[(2) - (4)].scope).start;
				(yyval.scope).end = ILAsmOutUniqueLabel();
				ILAsmOutPopVarScope((yyval.scope).end);
	  		}
    break;

  case 285:
#line 2399 "ilasm_grammar.y"
    {
				ILAsmOutAddTryBlock((yyvsp[(1) - (2)].scope).start, (yyvsp[(1) - (2)].scope).end, (yyvsp[(2) - (2)].exception));
			}
    break;

  case 286:
#line 2405 "ilasm_grammar.y"
    {
				(yyval.exception) = (yyvsp[(1) - (2)].exception);
				(yyvsp[(1) - (2)].exception)->next = (yyvsp[(2) - (2)].exception);
			}
    break;

  case 287:
#line 2409 "ilasm_grammar.y"
    { (yyval.exception) = (yyvsp[(1) - (1)].exception); }
    break;

  case 288:
#line 2413 "ilasm_grammar.y"
    { (yyval.scope) = (yyvsp[(2) - (2)].scope); }
    break;

  case 289:
#line 2414 "ilasm_grammar.y"
    { (yyval.scope).start = (yyvsp[(2) - (4)].strValue).string;
										  (yyval.scope).end = (yyvsp[(4) - (4)].strValue).string; }
    break;

  case 290:
#line 2416 "ilasm_grammar.y"
    {
				(yyval.scope).start = ILAsmOutIntToName((yyvsp[(2) - (4)].integer));
				(yyval.scope).end = ILAsmOutIntToName((yyvsp[(4) - (4)].integer));
			}
    break;

  case 291:
#line 2423 "ilasm_grammar.y"
    {
				(yyval.exception) = ILAsmOutMakeException(IL_META_EXCEPTION_CATCH, (yyvsp[(1) - (2)].classInfo), 0,
										   (yyvsp[(2) - (2)].scope).start, (yyvsp[(2) - (2)].scope).end);
			}
    break;

  case 292:
#line 2427 "ilasm_grammar.y"
    {
				(yyval.exception) = ILAsmOutMakeException(IL_META_EXCEPTION_FILTER,
										   0, (yyvsp[(1) - (2)].scope).start,
										   (yyvsp[(2) - (2)].scope).start, (yyvsp[(2) - (2)].scope).end);
			}
    break;

  case 293:
#line 2432 "ilasm_grammar.y"
    {
				(yyval.exception) = ILAsmOutMakeException(IL_META_EXCEPTION_FINALLY, 0, 0,
										   (yyvsp[(2) - (2)].scope).start, (yyvsp[(2) - (2)].scope).end);
			}
    break;

  case 294:
#line 2436 "ilasm_grammar.y"
    {
				(yyval.exception) = ILAsmOutMakeException(IL_META_EXCEPTION_FAULT, 0, 0,
										   (yyvsp[(2) - (2)].scope).start, (yyvsp[(2) - (2)].scope).end);
			}
    break;

  case 295:
#line 2443 "ilasm_grammar.y"
    { (yyval.classInfo) = (yyvsp[(2) - (2)].classInfo); }
    break;

  case 296:
#line 2447 "ilasm_grammar.y"
    { (yyval.scope) = (yyvsp[(2) - (2)].scope); }
    break;

  case 297:
#line 2448 "ilasm_grammar.y"
    { (yyval.scope).start = (yyvsp[(2) - (2)].strValue).string; (yyval.scope).end = 0; }
    break;

  case 298:
#line 2449 "ilasm_grammar.y"
    { (yyval.scope).start = ILAsmOutIntToName((yyvsp[(2) - (2)].integer)); (yyval.scope).end = 0; }
    break;

  case 301:
#line 2461 "ilasm_grammar.y"
    { (yyval.scope) = (yyvsp[(1) - (1)].scope); }
    break;

  case 302:
#line 2462 "ilasm_grammar.y"
    { (yyval.scope).start = (yyvsp[(2) - (4)].strValue).string;
											  (yyval.scope).end = (yyvsp[(4) - (4)].strValue).string; }
    break;

  case 303:
#line 2464 "ilasm_grammar.y"
    {
				(yyval.scope).start = ILAsmOutIntToName((yyvsp[(2) - (4)].integer));
				(yyval.scope).end = ILAsmOutIntToName((yyvsp[(4) - (4)].integer));
			}
    break;

  case 304:
#line 2471 "ilasm_grammar.y"
    {
				/* Record the start of the block */
				(yyval.scope).start = ILAsmOutUniqueLabel();
			}
    break;

  case 305:
#line 2475 "ilasm_grammar.y"
    {
	  			/* Record the end of the block */
				(yyval.scope).start = (yyvsp[(2) - (4)].scope).start;
				(yyval.scope).end = ILAsmOutUniqueLabel();
	  		}
    break;

  case 308:
#line 2488 "ilasm_grammar.y"
    {
				ILAsmOutAddTryBlock((yyvsp[(1) - (2)].scope).start, (yyvsp[(1) - (2)].scope).end, (yyvsp[(2) - (2)].exception));
			}
    break;

  case 309:
#line 2494 "ilasm_grammar.y"
    {
				(yyval.exception) = (yyvsp[(1) - (2)].exception);
				(yyvsp[(1) - (2)].exception)->next = (yyvsp[(2) - (2)].exception);
			}
    break;

  case 310:
#line 2498 "ilasm_grammar.y"
    { (yyval.exception) = (yyvsp[(1) - (1)].exception); }
    break;

  case 311:
#line 2502 "ilasm_grammar.y"
    { (yyval.scope) = (yyvsp[(2) - (2)].scope); }
    break;

  case 312:
#line 2503 "ilasm_grammar.y"
    { (yyval.scope).start = (yyvsp[(2) - (4)].strValue).string;
										  (yyval.scope).end = (yyvsp[(4) - (4)].strValue).string; }
    break;

  case 313:
#line 2505 "ilasm_grammar.y"
    {
				(yyval.scope).start = ILAsmOutIntToName((yyvsp[(2) - (4)].integer));
				(yyval.scope).end = ILAsmOutIntToName((yyvsp[(4) - (4)].integer));
			}
    break;

  case 314:
#line 2512 "ilasm_grammar.y"
    {
				(yyval.exception) = ILAsmOutMakeException(IL_META_EXCEPTION_CATCH, (yyvsp[(1) - (2)].classInfo), 0,
										   (yyvsp[(2) - (2)].scope).start, (yyvsp[(2) - (2)].scope).end);
			}
    break;

  case 315:
#line 2516 "ilasm_grammar.y"
    {
				(yyval.exception) = ILAsmOutMakeException(IL_META_EXCEPTION_FINALLY, 0, 0,
										   (yyvsp[(2) - (2)].scope).start, (yyvsp[(2) - (2)].scope).end);
			}
    break;

  case 316:
#line 2523 "ilasm_grammar.y"
    { (yyval.scope) = (yyvsp[(1) - (1)].scope); }
    break;

  case 317:
#line 2524 "ilasm_grammar.y"
    { (yyval.scope).start = (yyvsp[(2) - (2)].strValue).string;
									  (yyval.scope).end = 0; }
    break;

  case 318:
#line 2526 "ilasm_grammar.y"
    { (yyval.scope).start = ILAsmOutIntToName((yyvsp[(2) - (2)].integer));
									  (yyval.scope).end = 0; }
    break;

  case 319:
#line 2535 "ilasm_grammar.y"
    {
				ILEvent *event;
				event = ILEventCreate(ILAsmClass, 0, (yyvsp[(4) - (4)].strValue).string,
									  (ILUInt32)((yyvsp[(2) - (4)].integer)),
									  ILProgramItemToClass((yyvsp[(3) - (4)].typeSpec).item));
				if(!event)
				{
					ILAsmOutOfMemory();
				}
				ILAsmBuildPushScope(event);
			}
    break;

  case 320:
#line 2546 "ilasm_grammar.y"
    {
				ILEvent *event;
				event = ILEventCreate(ILAsmClass, 0, (yyvsp[(3) - (3)].strValue).string,
									  (ILUInt32)((yyvsp[(2) - (3)].integer)), 0);
				if(!event)
				{
					ILAsmOutOfMemory();
				}
				if(!ILEventMapCreate(ILAsmImage, 0, ILAsmClass, event))
				{
					ILAsmOutOfMemory();
				}
				ILAsmBuildPushScope(event);
			}
    break;

  case 321:
#line 2563 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 322:
#line 2564 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 323:
#line 2568 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 324:
#line 2569 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 325:
#line 2573 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_EVENTDEF_RT_SPECIAL_NAME; }
    break;

  case 326:
#line 2574 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_EVENTDEF_SPECIAL_NAME; }
    break;

  case 327:
#line 2578 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 328:
#line 2579 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 331:
#line 2588 "ilasm_grammar.y"
    {
				ILAsmAddSemantics(IL_META_METHODSEM_ADD_ON, (yyvsp[(2) - (2)].token));
			}
    break;

  case 332:
#line 2591 "ilasm_grammar.y"
    {
				ILAsmAddSemantics(IL_META_METHODSEM_REMOVE_ON, (yyvsp[(2) - (2)].token));
			}
    break;

  case 333:
#line 2594 "ilasm_grammar.y"
    {
				ILAsmAddSemantics(IL_META_METHODSEM_FIRE, (yyvsp[(2) - (2)].token));
			}
    break;

  case 334:
#line 2597 "ilasm_grammar.y"
    {
				ILAsmAddSemantics(IL_META_METHODSEM_OTHER, (yyvsp[(2) - (2)].token));
			}
    break;

  case 337:
#line 2610 "ilasm_grammar.y"
    {
				ILType *sig;
				sig = CreateMethodSig((yyvsp[(1) - (8)].integer), (yyvsp[(2) - (8)].type), (yyvsp[(7) - (8)].params).paramFirst, 0, 1);
				(yyval.token) = ILAsmResolveMember((yyvsp[(3) - (8)].typeSpec).item, (yyvsp[(5) - (8)].strValue).string, sig,
								        IL_META_MEMBERKIND_METHOD);
			}
    break;

  case 338:
#line 2616 "ilasm_grammar.y"
    {
				/* Reference a method in the global module class */
				ILType *sig = CreateMethodSig((yyvsp[(1) - (6)].integer), (yyvsp[(2) - (6)].type), (yyvsp[(5) - (6)].params).paramFirst, 0, 1);
				(yyval.token) = ILAsmResolveMember(ILToProgramItem(ILAsmModuleClass),
									    (yyvsp[(3) - (6)].strValue).string, sig,
								        IL_META_MEMBERKIND_METHOD);
			}
    break;

  case 339:
#line 2628 "ilasm_grammar.y"
    {
				ILType *sig;
				sig = CreateMethodSig((yyvsp[(1) - (9)].integer), (yyvsp[(2) - (9)].type), (yyvsp[(8) - (9)].params).paramFirst, (yyvsp[(6) - (9)].params).paramFirst, 1);
				(yyval.token) = ILAsmResolveMember((yyvsp[(3) - (9)].typeSpec).item, (yyvsp[(5) - (9)].strValue).string, sig,
								        IL_META_MEMBERKIND_METHOD);
				if((yyvsp[(6) - (9)].params).paramFirst)
				{
					(yyval.token) = CreateMethodSpec((yyval.token), (yyvsp[(6) - (9)].params).paramFirst);
				}
			}
    break;

  case 340:
#line 2639 "ilasm_grammar.y"
    {
				/* Reference a method in the global module class */
				ILType *sig = CreateMethodSig
						((yyvsp[(1) - (7)].integer), (yyvsp[(2) - (7)].type), (yyvsp[(6) - (7)].params).paramFirst, (yyvsp[(4) - (7)].params).paramFirst, 1);
				(yyval.token) = ILAsmResolveMember(ILToProgramItem(ILAsmModuleClass),
									    (yyvsp[(3) - (7)].strValue).string, sig,
								        IL_META_MEMBERKIND_METHOD);
				if((yyvsp[(4) - (7)].params).paramFirst)
				{
					(yyval.token) = CreateMethodSpec((yyval.token), (yyvsp[(4) - (7)].params).paramFirst);
				}
			}
    break;

  case 341:
#line 2656 "ilasm_grammar.y"
    {
				ILType *sig;
				sig = CreateMethodSig((yyvsp[(1) - (9)].integer) | IL_META_CALLCONV_HASTHIS,
									  (yyvsp[(2) - (9)].type), (yyvsp[(8) - (9)].params).paramFirst, (yyvsp[(6) - (9)].params).paramFirst, 1);
				(yyval.token) = ILAsmResolveMember((yyvsp[(3) - (9)].typeSpec).item, (yyvsp[(5) - (9)].strValue).string, sig,
								        IL_META_MEMBERKIND_METHOD);
				if((yyvsp[(6) - (9)].params).paramFirst)
				{
					(yyval.token) = CreateMethodSpec((yyval.token), (yyvsp[(6) - (9)].params).paramFirst);
				}
			}
    break;

  case 342:
#line 2668 "ilasm_grammar.y"
    {
				/* Reference a method in the global module class */
				ILType *sig = CreateMethodSig
						((yyvsp[(1) - (7)].integer) | IL_META_CALLCONV_HASTHIS,
					     (yyvsp[(2) - (7)].type), (yyvsp[(6) - (7)].params).paramFirst, (yyvsp[(4) - (7)].params).paramFirst, 1);
				(yyval.token) = ILAsmResolveMember(ILToProgramItem(ILAsmModuleClass),
									    (yyvsp[(3) - (7)].strValue).string, sig,
								        IL_META_MEMBERKIND_METHOD);
				if((yyvsp[(4) - (7)].params).paramFirst)
				{
					(yyval.token) = CreateMethodSpec((yyval.token), (yyvsp[(4) - (7)].params).paramFirst);
				}
			}
    break;

  case 343:
#line 2684 "ilasm_grammar.y"
    { (yyval.params).paramFirst = 0; (yyval.params).paramLast = 0; }
    break;

  case 344:
#line 2685 "ilasm_grammar.y"
    { (yyval.params) = (yyvsp[(2) - (3)].params); }
    break;

  case 345:
#line 2689 "ilasm_grammar.y"
    {
				ILAsmParamInfo *param;
				param = (ILAsmParamInfo *)ILMalloc(sizeof(ILAsmParamInfo));
				if(!param)
				{
					ILAsmOutOfMemory();
				}
				param->type = (yyvsp[(1) - (1)].type);
				param->nativeType.string = "";
				param->nativeType.len = 0;
				param->parameterAttrs = 0;
				param->name = 0;
				param->next = 0;
				(yyval.params).paramFirst = param;
				(yyval.params).paramLast = param;
			}
    break;

  case 346:
#line 2705 "ilasm_grammar.y"
    {
				ILAsmParamInfo *param;
				param = (ILAsmParamInfo *)ILMalloc(sizeof(ILAsmParamInfo));
				if(!param)
				{
					ILAsmOutOfMemory();
				}
				param->type = (yyvsp[(3) - (3)].type);
				param->nativeType.string = "";
				param->nativeType.len = 0;
				param->parameterAttrs = 0;
				param->name = 0;
				param->next = 0;
				(yyvsp[(1) - (3)].params).paramLast->next = param;
				(yyval.params).paramFirst = (yyvsp[(1) - (3)].params).paramFirst;
				(yyval.params).paramLast = param;
			}
    break;

  case 347:
#line 2730 "ilasm_grammar.y"
    {
				ILType *sig = CreatePropertySig((yyvsp[(3) - (8)].integer), (yyvsp[(4) - (8)].type), (yyvsp[(7) - (8)].params).paramFirst);
				ILProperty *property;
				property = ILPropertyCreate(ILAsmClass, 0, (yyvsp[(5) - (8)].strValue).string,
											(ILUInt32)((yyvsp[(2) - (8)].integer)), sig);
				if(!property)
				{
					ILAsmOutOfMemory();
				}
				ILAsmBuildPushScope(property);
			}
    break;

  case 348:
#line 2744 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 349:
#line 2745 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 350:
#line 2749 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 351:
#line 2750 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 352:
#line 2754 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PROPDEF_RT_SPECIAL_NAME; }
    break;

  case 353:
#line 2755 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PROPDEF_SPECIAL_NAME; }
    break;

  case 354:
#line 2759 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 355:
#line 2760 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 358:
#line 2769 "ilasm_grammar.y"
    {
				ILAsmAddSemantics(IL_META_METHODSEM_SETTER, (yyvsp[(2) - (2)].token));
			}
    break;

  case 359:
#line 2772 "ilasm_grammar.y"
    {
				ILAsmAddSemantics(IL_META_METHODSEM_GETTER, (yyvsp[(2) - (2)].token));
			}
    break;

  case 360:
#line 2775 "ilasm_grammar.y"
    {
				ILAsmAddSemantics(IL_META_METHODSEM_OTHER, (yyvsp[(2) - (2)].token));
			}
    break;

  case 361:
#line 2778 "ilasm_grammar.y"
    { /* Obsolete */ }
    break;

  case 365:
#line 2792 "ilasm_grammar.y"
    {
				/* Record the section offset with the label */
				ILAsmDataSetLabel((yyvsp[(3) - (4)].strValue).string);
			}
    break;

  case 366:
#line 2796 "ilasm_grammar.y"
    { /* nothing to do here */ }
    break;

  case 367:
#line 2800 "ilasm_grammar.y"
    { ILAsmDataSetNormal(); }
    break;

  case 368:
#line 2801 "ilasm_grammar.y"
    { ILAsmDataSetTLS(); }
    break;

  case 373:
#line 2815 "ilasm_grammar.y"
    { (yyval.integer) = 1; }
    break;

  case 374:
#line 2816 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(2) - (3)].integer); }
    break;

  case 375:
#line 2820 "ilasm_grammar.y"
    {
				ILAsmDataWriteBytes((ILUInt8 *)((yyvsp[(4) - (5)].strValue).string), (yyvsp[(4) - (5)].strValue).len);
			}
    break;

  case 376:
#line 2823 "ilasm_grammar.y"
    {
				ILAsmDataWriteBytes((ILUInt8 *)((yyvsp[(4) - (5)].strValue).string), (yyvsp[(4) - (5)].strValue).len);
			}
    break;

  case 377:
#line 2826 "ilasm_grammar.y"
    {
				/* Not supported */
				ILAsmDataWriteInt32(0, 1);
			}
    break;

  case 378:
#line 2830 "ilasm_grammar.y"
    {
				ILAsmDataWriteBytes((ILUInt8 *)((yyvsp[(2) - (2)].strValue).string), (yyvsp[(2) - (2)].strValue).len);
			}
    break;

  case 379:
#line 2833 "ilasm_grammar.y"
    {
				ILAsmDataWriteFloat32((yyvsp[(3) - (5)].floatValue).fbytes, (ILUInt32)((yyvsp[(5) - (5)].integer)));
			}
    break;

  case 380:
#line 2836 "ilasm_grammar.y"
    {
				ILAsmDataWriteFloat64((yyvsp[(3) - (5)].floatValue).dbytes, (ILUInt32)((yyvsp[(5) - (5)].integer)));
			}
    break;

  case 381:
#line 2839 "ilasm_grammar.y"
    {
				ILAsmDataWriteInt64((yyvsp[(3) - (5)].integer), (ILUInt32)((yyvsp[(5) - (5)].integer)));
			}
    break;

  case 382:
#line 2842 "ilasm_grammar.y"
    {
				ILAsmDataWriteInt32((ILInt32)((yyvsp[(3) - (5)].integer)), (ILUInt32)((yyvsp[(5) - (5)].integer)));
			}
    break;

  case 383:
#line 2845 "ilasm_grammar.y"
    {
				ILAsmDataWriteInt16((ILInt32)((yyvsp[(3) - (5)].integer)), (ILUInt32)((yyvsp[(5) - (5)].integer)));
			}
    break;

  case 384:
#line 2848 "ilasm_grammar.y"
    {
				ILAsmDataWriteInt8((ILInt32)((yyvsp[(3) - (5)].integer)), (ILUInt32)((yyvsp[(5) - (5)].integer)));
			}
    break;

  case 385:
#line 2851 "ilasm_grammar.y"
    {
				ILAsmDataPad((ILUInt32)(4 * (yyvsp[(2) - (2)].integer)));
			}
    break;

  case 386:
#line 2854 "ilasm_grammar.y"
    {
				ILAsmDataPad((ILUInt32)(8 * (yyvsp[(2) - (2)].integer)));
			}
    break;

  case 387:
#line 2857 "ilasm_grammar.y"
    {
				ILAsmDataPad((ILUInt32)(8 * (yyvsp[(2) - (2)].integer)));
			}
    break;

  case 388:
#line 2860 "ilasm_grammar.y"
    {
				ILAsmDataPad((ILUInt32)(4 * (yyvsp[(2) - (2)].integer)));
			}
    break;

  case 389:
#line 2863 "ilasm_grammar.y"
    {
				ILAsmDataPad((ILUInt32)(2 * (yyvsp[(2) - (2)].integer)));
			}
    break;

  case 390:
#line 2866 "ilasm_grammar.y"
    {
				ILAsmDataPad((ILUInt32)((yyvsp[(2) - (2)].integer)));
			}
    break;

  case 392:
#line 2880 "ilasm_grammar.y"
    {}
    break;

  case 393:
#line 2884 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 394:
#line 2885 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 395:
#line 2889 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 396:
#line 2890 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 397:
#line 2894 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VTFIXUP_32BIT; }
    break;

  case 398:
#line 2895 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VTFIXUP_64BIT; }
    break;

  case 399:
#line 2896 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VTFIXUP_FROM_UNMANAGED; }
    break;

  case 400:
#line 2897 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VTFIXUP_CALL_MOST_DERIVED; }
    break;

  case 401:
#line 2905 "ilasm_grammar.y"
    {
				if(ILClassIsValueType((yyvsp[(1) - (1)].classInfo)))
					(yyval.typeSpec).type = ILType_FromValueType((yyvsp[(1) - (1)].classInfo));
				else
					(yyval.typeSpec).type = ILType_FromClass((yyvsp[(1) - (1)].classInfo));
				(yyval.typeSpec).item = ILToProgramItem((yyvsp[(1) - (1)].classInfo));
			}
    break;

  case 402:
#line 2912 "ilasm_grammar.y"
    {
				/* TODO: Reference to a foreign assembly's global type */
				(yyval.typeSpec).type = ILType_Invalid;
				(yyval.typeSpec).item = 0;
			}
    break;

  case 403:
#line 2917 "ilasm_grammar.y"
    {
				/* TODO: Reference to a foreign module's global type */
				(yyval.typeSpec).type = ILType_Invalid;
				(yyval.typeSpec).item = 0;
			}
    break;

  case 404:
#line 2922 "ilasm_grammar.y"
    {
				/* Convert a type into a TypeSpec token of some kind */
				(yyval.typeSpec).type = (yyvsp[(1) - (1)].type);
				if(ILType_IsClass((yyvsp[(1) - (1)].type)) || ILType_IsValueType((yyvsp[(1) - (1)].type)))
				{
					/* Simple class reference */
					(yyval.typeSpec).item = ILToProgramItem(ILType_ToClass((yyvsp[(1) - (1)].type)));
				}
				else
				{
					/* Search the TypeSpec table for a match */
					ILTypeSpec *spec = 0;
					while((spec = (ILTypeSpec *)
							ILImageNextToken(ILAsmImage,
											 IL_META_TOKEN_TYPE_SPEC,
											 spec)) != 0)
					{
						if(ILTypeIdentical(ILTypeSpec_Type(spec), (yyvsp[(1) - (1)].type)))
						{
							break;
						}
					}
					if(!spec)
					{
						/* Create a new TypeSpec token */
						spec = ILTypeSpecCreate(ILAsmImage, 0, (yyvsp[(1) - (1)].type));
						if(!spec)
						{
							ILAsmOutOfMemory();
						}
					}
					(yyval.typeSpec).item = ILToProgramItem(spec);
				}
			}
    break;

  case 405:
#line 2959 "ilasm_grammar.y"
    {
				ILAssembly *assem;

				/* Get the assembly reference: NULL if current assembly */
				if(!strcmp((yyvsp[(2) - (4)].strValue).string, ".library"))
				{
					assem = ILAsmFindAssemblyRef(ILAsmLibraryName);
				}
				else
				{
					assem = ILAsmFindAssemblyRef((yyvsp[(2) - (4)].strValue).string);
				}

				/* Look up the class, or create a TypeRef */
				if(assem)
				{
					(yyval.classInfo) = ILAsmClassLookup((yyvsp[(4) - (4)].strValue).string, (ILProgramItem *)assem);
				}
				else
				{
					(yyval.classInfo) = ILAsmClassLookup((yyvsp[(4) - (4)].strValue).string,
										  (ILProgramItem *)ILAsmModule);
				}
			}
    break;

  case 406:
#line 2983 "ilasm_grammar.y"
    {
				ILAssembly *assem;

				/* Find the library: NULL if it is the current assembly */
				assem = ILAsmFindAssemblyRef(ILAsmLibraryName);

				/* Look up the class, or create a TypeRef */
				if(assem)
				{
					(yyval.classInfo) = ILAsmClassLookup((yyvsp[(4) - (4)].strValue).string, (ILProgramItem *)assem);
				}
				else
				{
					(yyval.classInfo) = ILAsmClassLookup((yyvsp[(4) - (4)].strValue).string,
										  (ILProgramItem *)ILAsmModule);
				}
			}
    break;

  case 407:
#line 3000 "ilasm_grammar.y"
    {
				ILModule *module;

				/* Get the module reference: NULL if current module */
				module = ILAsmFindModuleRef((yyvsp[(3) - (5)].strValue).string);
				if(!module)
				{
					module = ILAsmModule;
				}

				/* Look up the class, or create a TypeRef */
				(yyval.classInfo) = ILAsmClassLookup((yyvsp[(5) - (5)].strValue).string, (ILProgramItem *)module);
			}
    break;

  case 408:
#line 3013 "ilasm_grammar.y"
    {
				/* Look up the class or create a reference to this module */
				(yyval.classInfo) = ILAsmClassLookup((yyvsp[(1) - (1)].strValue).string, (ILProgramItem *)ILAsmModule);
			}
    break;

  case 409:
#line 3020 "ilasm_grammar.y"
    {
				(yyval.classInfo) = ILProgramItemToClass((yyvsp[(1) - (1)].typeSpec).item);
			}
    break;

  case 410:
#line 3026 "ilasm_grammar.y"
    { (yyval.strValue) = (yyvsp[(1) - (1)].strValue); }
    break;

  case 411:
#line 3027 "ilasm_grammar.y"
    {
				ILIntString slash;
				slash.string = ILASM_NESTED_CLASS_SEP_STR;
				slash.len = 1;
				(yyval.strValue) = ILInternAppendedString
						((yyvsp[(1) - (3)].strValue), ILInternAppendedString(slash, (yyvsp[(3) - (3)].strValue)));
			}
    break;

  case 412:
#line 3037 "ilasm_grammar.y"
    { (yyval.type) = ILType_FromClass((yyvsp[(2) - (2)].classInfo)); }
    break;

  case 413:
#line 3038 "ilasm_grammar.y"
    { (yyval.type) = ILType_FromValueType((yyvsp[(3) - (3)].classInfo)); }
    break;

  case 414:
#line 3039 "ilasm_grammar.y"
    { (yyval.type) = ILType_FromValueType((yyvsp[(2) - (2)].classInfo)); }
    break;

  case 415:
#line 3040 "ilasm_grammar.y"
    { (yyval.type) = ILType_FromClass((yyvsp[(2) - (2)].classInfo)); }
    break;

  case 416:
#line 3041 "ilasm_grammar.y"
    {
				(yyval.type) = CombineArrayType
						((yyvsp[(1) - (4)].type), ILTypeCreateArray(ILAsmContext, 1, 0), 0);
			}
    break;

  case 417:
#line 3045 "ilasm_grammar.y"
    {
				(yyval.type) = CombineArrayType((yyvsp[(1) - (4)].type), (yyvsp[(3) - (4)].type), 0);
			}
    break;

  case 418:
#line 3048 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateRef(ILAsmContext, IL_TYPE_COMPLEX_BYREF, (yyvsp[(1) - (2)].type));
			}
    break;

  case 419:
#line 3051 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateRef(ILAsmContext, IL_TYPE_COMPLEX_PTR, (yyvsp[(1) - (2)].type));
			}
    break;

  case 420:
#line 3054 "ilasm_grammar.y"
    {
				/* Not sure if this is right: '%' doesn't seem to be doc'ed */
				(yyval.type) = ILTypeCreateRef(ILAsmContext, IL_TYPE_COMPLEX_PTR, (yyvsp[(1) - (2)].type));
			}
    break;

  case 421:
#line 3058 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateRef(ILAsmContext, IL_TYPE_COMPLEX_PINNED, (yyvsp[(1) - (2)].type));
			}
    break;

  case 422:
#line 3061 "ilasm_grammar.y"
    {
				ILType *modifiers =
						ILTypeCreateModifier(ILAsmContext, 0,
											 IL_TYPE_COMPLEX_CMOD_REQD, (yyvsp[(4) - (5)].classInfo));
				(yyval.type) = ILTypeAddModifiers(ILAsmContext, modifiers, (yyvsp[(1) - (5)].type));
			}
    break;

  case 423:
#line 3067 "ilasm_grammar.y"
    {
				ILType *modifiers =
						ILTypeCreateModifier(ILAsmContext, 0,
											 IL_TYPE_COMPLEX_CMOD_OPT, (yyvsp[(4) - (5)].classInfo));
				(yyval.type) = ILTypeAddModifiers(ILAsmContext, modifiers, (yyvsp[(1) - (5)].type));
			}
    break;

  case 424:
#line 3073 "ilasm_grammar.y"
    {
				(yyval.type) = CreateMethodSig((yyvsp[(2) - (7)].integer), (yyvsp[(3) - (7)].type), (yyvsp[(6) - (7)].params).paramFirst, 0, 1);
			}
    break;

  case 425:
#line 3076 "ilasm_grammar.y"
    { (yyval.type) = ILType_TypedRef; }
    break;

  case 426:
#line 3077 "ilasm_grammar.y"
    { (yyval.type) = ILType_Char; }
    break;

  case 427:
#line 3078 "ilasm_grammar.y"
    { (yyval.type) = ILType_Char; }
    break;

  case 428:
#line 3079 "ilasm_grammar.y"
    { (yyval.type) = ILType_Void; }
    break;

  case 429:
#line 3080 "ilasm_grammar.y"
    { (yyval.type) = ILType_Boolean; }
    break;

  case 430:
#line 3081 "ilasm_grammar.y"
    { (yyval.type) = ILType_Int8; }
    break;

  case 431:
#line 3082 "ilasm_grammar.y"
    { (yyval.type) = ILType_Int16; }
    break;

  case 432:
#line 3083 "ilasm_grammar.y"
    { (yyval.type) = ILType_Int32; }
    break;

  case 433:
#line 3084 "ilasm_grammar.y"
    { (yyval.type) = ILType_Int64; }
    break;

  case 434:
#line 3085 "ilasm_grammar.y"
    { (yyval.type) = ILType_Float32; }
    break;

  case 435:
#line 3086 "ilasm_grammar.y"
    { (yyval.type) = ILType_Float64; }
    break;

  case 436:
#line 3087 "ilasm_grammar.y"
    { (yyval.type) = ILType_UInt8; }
    break;

  case 437:
#line 3088 "ilasm_grammar.y"
    { (yyval.type) = ILType_UInt16; }
    break;

  case 438:
#line 3089 "ilasm_grammar.y"
    { (yyval.type) = ILType_UInt32; }
    break;

  case 439:
#line 3090 "ilasm_grammar.y"
    { (yyval.type) = ILType_UInt64; }
    break;

  case 440:
#line 3091 "ilasm_grammar.y"
    { (yyval.type) = ILType_Int; }
    break;

  case 441:
#line 3092 "ilasm_grammar.y"
    { (yyval.type) = ILType_UInt; }
    break;

  case 442:
#line 3093 "ilasm_grammar.y"
    { (yyval.type) = ILType_Float; }
    break;

  case 443:
#line 3094 "ilasm_grammar.y"
    { (yyval.type) = ILType_FromClass(ILAsmSystemClass("String")); }
    break;

  case 444:
#line 3095 "ilasm_grammar.y"
    { (yyval.type) = ILType_FromClass(ILAsmSystemClass("Object")); }
    break;

  case 445:
#line 3096 "ilasm_grammar.y"
    {
				/* Reference to a class generic parameter */
				(yyval.type) = ILTypeCreateVarNum
						(ILAsmContext, IL_TYPE_COMPLEX_VAR, (int)((yyvsp[(2) - (2)].integer)));
			}
    break;

  case 446:
#line 3101 "ilasm_grammar.y"
    {
				/* Reference to a method generic parameter */
				(yyval.type) = ILTypeCreateVarNum
						(ILAsmContext, IL_TYPE_COMPLEX_MVAR, (int)((yyvsp[(3) - (3)].integer)));
			}
    break;

  case 447:
#line 3106 "ilasm_grammar.y"
    {
				/* Reference to a generic type instantiation */
				((yyvsp[(3) - (4)].type))->un.method__.retType__ = (yyvsp[(1) - (4)].type);
				(yyval.type) = (yyvsp[(3) - (4)].type);
			}
    break;

  case 448:
#line 3114 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateWith(ILAsmContext, ILType_Invalid);
				if(!((yyval.type)))
				{
					ILAsmOutOfMemory();
				}
				if(!ILTypeAddWithParam(ILAsmContext, (yyval.type), (yyvsp[(1) - (1)].type)))
				{
					ILAsmOutOfMemory();
				}
			}
    break;

  case 449:
#line 3125 "ilasm_grammar.y"
    {
				if(!ILTypeAddWithParam(ILAsmContext, (yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].type)))
				{
					ILAsmOutOfMemory();
				}
				(yyval.type) = (yyvsp[(1) - (3)].type);
			}
    break;

  case 450:
#line 3135 "ilasm_grammar.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 451:
#line 3136 "ilasm_grammar.y"
    {
				(yyval.type) = CombineArrayType((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].type), 1);
			}
    break;

  case 452:
#line 3148 "ilasm_grammar.y"
    { (yyval.type) = ILTypeCreateArray(ILAsmContext, 1, 0); }
    break;

  case 453:
#line 3149 "ilasm_grammar.y"
    { (yyval.type) = ILTypeCreateArray(ILAsmContext, 1, 0); }
    break;

  case 454:
#line 3150 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateArray(ILAsmContext, 1, 0);
				ILTypeSetSize((yyval.type), 0, (long)(yyvsp[(1) - (1)].integer));
			}
    break;

  case 455:
#line 3154 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateArray(ILAsmContext, 1, 0);
				ILTypeSetSize((yyval.type), 0, (long)((yyvsp[(3) - (3)].integer) - (yyvsp[(1) - (3)].integer) + 1));
				ILTypeSetLowBound((yyval.type), 0, (long)(yyvsp[(1) - (3)].integer));
			}
    break;

  case 456:
#line 3159 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateArray(ILAsmContext, 1, 0);
				ILTypeSetSize((yyval.type), 0, (long)((yyvsp[(3) - (3)].integer) - (yyvsp[(1) - (3)].real) + 1));
				ILTypeSetLowBound((yyval.type), 0, (long)(yyvsp[(1) - (3)].real));
			}
    break;

  case 457:
#line 3164 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateArray(ILAsmContext, 1, 0);
				ILTypeSetLowBound((yyval.type), 0, (long)(yyvsp[(1) - (2)].integer));
			}
    break;

  case 458:
#line 3168 "ilasm_grammar.y"
    {
				(yyval.type) = ILTypeCreateArray(ILAsmContext, 1, 0);
				ILTypeSetLowBound((yyval.type), 0, (long)(yyvsp[(1) - (2)].real));
			}
    break;

  case 459:
#line 3175 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_MAX); }
    break;

  case 460:
#line 3177 "ilasm_grammar.y"
    {
				ILIntString prefix;
				prefix = SimpleNative(IL_META_NATIVETYPE_CUSTOMMARSHALER);
				(yyval.strValue) = ILInternAppendedString(prefix,
						ILInternAppendedString(PackString((yyvsp[(3) - (10)].strValue)),
							ILInternAppendedString(PackString((yyvsp[(5) - (10)].strValue)),
								ILInternAppendedString(PackString((yyvsp[(7) - (10)].strValue)),
													   PackString((yyvsp[(9) - (10)].strValue))))));
			}
    break;

  case 461:
#line 3186 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
							(SimpleNative(IL_META_NATIVETYPE_FIXEDSYSSTRING),
							 PackLength((yyvsp[(4) - (5)].integer)));
			}
    break;

  case 462:
#line 3191 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
							(SimpleNative(IL_META_NATIVETYPE_FIXEDARRAY),
							 ILInternAppendedString
							 	(PackLength((yyvsp[(4) - (5)].integer)),
							 	 SimpleNative(IL_META_NATIVETYPE_MAX)));
			}
    break;

  case 463:
#line 3198 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_VARIANT); }
    break;

  case 464:
#line 3199 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_CURRENCY); }
    break;

  case 465:
#line 3200 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_SYSCHAR); }
    break;

  case 466:
#line 3201 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_VOID); }
    break;

  case 467:
#line 3202 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_BOOLEAN); }
    break;

  case 468:
#line 3203 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_I1); }
    break;

  case 469:
#line 3204 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_I2); }
    break;

  case 470:
#line 3205 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_I4); }
    break;

  case 471:
#line 3206 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_I8); }
    break;

  case 472:
#line 3207 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_R4); }
    break;

  case 473:
#line 3208 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_R8); }
    break;

  case 474:
#line 3209 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_ERROR); }
    break;

  case 475:
#line 3210 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_U1); }
    break;

  case 476:
#line 3211 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_U2); }
    break;

  case 477:
#line 3212 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_U4); }
    break;

  case 478:
#line 3213 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_U8); }
    break;

  case 479:
#line 3214 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
							(SimpleNative(IL_META_NATIVETYPE_PTR), (yyvsp[(1) - (2)].strValue));
			}
    break;

  case 480:
#line 3218 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
						(SimpleNative(IL_META_NATIVETYPE_ARRAY),
						 ILInternAppendedString((yyvsp[(1) - (3)].strValue),
						 	ILInternAppendedString(PackLength(0),
								ILInternAppendedString(PackLength(0),
													   PackLength(0)))));
			}
    break;

  case 481:
#line 3226 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
						(SimpleNative(IL_META_NATIVETYPE_ARRAY),
						 ILInternAppendedString((yyvsp[(1) - (4)].strValue),
						 	ILInternAppendedString(PackLength(0),
								ILInternAppendedString(PackLength(0),
													   PackLength((yyvsp[(3) - (4)].integer))))));
			}
    break;

  case 482:
#line 3234 "ilasm_grammar.y"
    {
				/* Old format */
				(yyval.strValue) = ILInternAppendedString
						(SimpleNative(IL_META_NATIVETYPE_ARRAY),
						 ILInternAppendedString((yyvsp[(1) - (7)].strValue),
						 	ILInternAppendedString(PackLength((yyvsp[(6) - (7)].integer)),
								ILInternAppendedString(PackLength(1),
													   PackLength(0)))));
			}
    break;

  case 483:
#line 3243 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
						(SimpleNative(IL_META_NATIVETYPE_ARRAY),
						 ILInternAppendedString((yyvsp[(1) - (5)].strValue),
						 	ILInternAppendedString(PackLength((yyvsp[(4) - (5)].integer)),
								ILInternAppendedString(PackLength(1),
													   PackLength(0)))));
			}
    break;

  case 484:
#line 3251 "ilasm_grammar.y"
    {
				/* Old format */
				(yyval.strValue) = ILInternAppendedString
						(SimpleNative(IL_META_NATIVETYPE_ARRAY),
						 ILInternAppendedString((yyvsp[(1) - (9)].strValue),
						 	ILInternAppendedString(PackLength((yyvsp[(6) - (9)].integer)),
								ILInternAppendedString(PackLength((yyvsp[(8) - (9)].integer)),
													   PackLength(0)))));
			}
    break;

  case 485:
#line 3260 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
						(SimpleNative(IL_META_NATIVETYPE_ARRAY),
						 ILInternAppendedString((yyvsp[(1) - (6)].strValue),
						 	ILInternAppendedString(PackLength((yyvsp[(5) - (6)].integer)),
								ILInternAppendedString(PackLength(1),
													   PackLength((yyvsp[(3) - (6)].integer))))));
			}
    break;

  case 486:
#line 3268 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_DECIMAL); }
    break;

  case 487:
#line 3269 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_DATE); }
    break;

  case 488:
#line 3270 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_BSTR); }
    break;

  case 489:
#line 3271 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_LPSTR); }
    break;

  case 490:
#line 3272 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_LPWSTR); }
    break;

  case 491:
#line 3273 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_LPTSTR); }
    break;

  case 492:
#line 3274 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_OBJECTREF); }
    break;

  case 493:
#line 3275 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_IUNKNOWN); }
    break;

  case 494:
#line 3276 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_IDISPATCH); }
    break;

  case 495:
#line 3277 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_STRUCT); }
    break;

  case 496:
#line 3278 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_INTF); }
    break;

  case 497:
#line 3279 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternAppendedString
							(SimpleNative(IL_META_NATIVETYPE_SAFEARRAY),
							 PackLength((yyvsp[(2) - (2)].integer)));
			}
    break;

  case 498:
#line 3284 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_INT); }
    break;

  case 499:
#line 3285 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_UINT); }
    break;

  case 500:
#line 3286 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_NESTEDSTRUCT); }
    break;

  case 501:
#line 3287 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_BYVALSTR); }
    break;

  case 502:
#line 3288 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_ANSIBSTR); }
    break;

  case 503:
#line 3289 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_TBSTR); }
    break;

  case 504:
#line 3290 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_VARIANTBOOL); }
    break;

  case 505:
#line 3291 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_FUNC); }
    break;

  case 506:
#line 3292 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_LPVOID); }
    break;

  case 507:
#line 3293 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_ASANY); }
    break;

  case 508:
#line 3294 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_R); }
    break;

  case 509:
#line 3295 "ilasm_grammar.y"
    { (yyval.strValue) = SimpleNative(IL_META_NATIVETYPE_LPSTRUCT); }
    break;

  case 510:
#line 3299 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_EMPTY; }
    break;

  case 511:
#line 3300 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_NULL; }
    break;

  case 512:
#line 3301 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_VARIANT; }
    break;

  case 513:
#line 3302 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_CY; }
    break;

  case 514:
#line 3303 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_VOID; }
    break;

  case 515:
#line 3304 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_BOOL; }
    break;

  case 516:
#line 3305 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_I1; }
    break;

  case 517:
#line 3306 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_I2; }
    break;

  case 518:
#line 3307 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_I4; }
    break;

  case 519:
#line 3308 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_I8; }
    break;

  case 520:
#line 3309 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_R4; }
    break;

  case 521:
#line 3310 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_R8; }
    break;

  case 522:
#line 3311 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_UI1; }
    break;

  case 523:
#line 3312 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_UI2; }
    break;

  case 524:
#line 3313 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_UI4; }
    break;

  case 525:
#line 3314 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_UI8; }
    break;

  case 526:
#line 3315 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_ARRAY | (yyvsp[(1) - (3)].integer); }
    break;

  case 527:
#line 3316 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_VECTOR | (yyvsp[(1) - (2)].integer); }
    break;

  case 528:
#line 3317 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_BYREF | (yyvsp[(1) - (2)].integer); }
    break;

  case 529:
#line 3318 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_DECIMAL; }
    break;

  case 530:
#line 3319 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_DATE; }
    break;

  case 531:
#line 3320 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_BSTR; }
    break;

  case 532:
#line 3321 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_LPSTR; }
    break;

  case 533:
#line 3322 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_LPWSTR; }
    break;

  case 534:
#line 3323 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_UNKNOWN; }
    break;

  case 535:
#line 3324 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_DISPATCH; }
    break;

  case 536:
#line 3325 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_SAFEARRAY; }
    break;

  case 537:
#line 3326 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_INT; }
    break;

  case 538:
#line 3327 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_UINT; }
    break;

  case 539:
#line 3328 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_ERROR; }
    break;

  case 540:
#line 3329 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_HRESULT; }
    break;

  case 541:
#line 3330 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_CARRAY; }
    break;

  case 542:
#line 3331 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_USERDEFINED; }
    break;

  case 543:
#line 3332 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_RECORD; }
    break;

  case 544:
#line 3333 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_FILETIME; }
    break;

  case 545:
#line 3334 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_BLOB; }
    break;

  case 546:
#line 3335 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_STREAM; }
    break;

  case 547:
#line 3336 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_STORAGE; }
    break;

  case 548:
#line 3337 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_STREAMED_OBJECT; }
    break;

  case 549:
#line 3338 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_STORED_OBJECT; }
    break;

  case 550:
#line 3339 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_BLOB_OBJECT; }
    break;

  case 551:
#line 3340 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_CF; }
    break;

  case 552:
#line 3341 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_VARIANTTYPE_CLSID; }
    break;

  case 553:
#line 3349 "ilasm_grammar.y"
    { (yyval.params).paramFirst = 0; (yyval.params).paramLast = 0; }
    break;

  case 554:
#line 3350 "ilasm_grammar.y"
    { (yyval.params) = (yyvsp[(1) - (1)].params); }
    break;

  case 555:
#line 3354 "ilasm_grammar.y"
    { (yyval.params) = (yyvsp[(1) - (1)].params); }
    break;

  case 556:
#line 3355 "ilasm_grammar.y"
    {
				(yyvsp[(1) - (3)].params).paramLast->next = (yyvsp[(3) - (3)].params).paramFirst;
				(yyval.params).paramFirst = (yyvsp[(1) - (3)].params).paramFirst;
				(yyval.params).paramLast = (yyvsp[(3) - (3)].params).paramLast;
			}
    break;

  case 557:
#line 3363 "ilasm_grammar.y"
    {
				ILAsmParamInfo *param;
				param = (ILAsmParamInfo *)ILMalloc(sizeof(ILAsmParamInfo));
				if(!param)
				{
					ILAsmOutOfMemory();
				}
				param->type = 0;
				param->nativeType.string = "";
				param->nativeType.len = 0;
				param->parameterAttrs = 0;
				param->name = 0;
				param->next = 0;
				(yyval.params).paramFirst = param;
				(yyval.params).paramLast = param;
			}
    break;

  case 558:
#line 3379 "ilasm_grammar.y"
    {
				ILAsmParamInfo *param;
				param = (ILAsmParamInfo *)ILMalloc(sizeof(ILAsmParamInfo));
				if(!param)
				{
					ILAsmOutOfMemory();
				}
				param->type = (yyvsp[(2) - (2)].marshType).type;
				param->nativeType = (yyvsp[(2) - (2)].marshType).nativeType;
				param->parameterAttrs = (yyvsp[(1) - (2)].integer);
				param->name = 0;
				param->next = 0;
				(yyval.params).paramFirst = param;
				(yyval.params).paramLast = param;
			}
    break;

  case 559:
#line 3394 "ilasm_grammar.y"
    {
				ILAsmParamInfo *param;
				param = (ILAsmParamInfo *)ILMalloc(sizeof(ILAsmParamInfo));
				if(!param)
				{
					ILAsmOutOfMemory();
				}
				param->type = (yyvsp[(2) - (3)].marshType).type;
				param->nativeType = (yyvsp[(2) - (3)].marshType).nativeType;
				param->parameterAttrs = (yyvsp[(1) - (3)].integer);
				param->name = (yyvsp[(3) - (3)].strValue).string;
				param->next = 0;
				(yyval.params).paramFirst = param;
				(yyval.params).paramLast = param;
			}
    break;

  case 560:
#line 3412 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 561:
#line 3413 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 562:
#line 3417 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(2) - (3)].integer); }
    break;

  case 563:
#line 3418 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (4)].integer) | (yyvsp[(3) - (4)].integer); }
    break;

  case 564:
#line 3422 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PARAMDEF_IN; }
    break;

  case 565:
#line 3423 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PARAMDEF_OUT; }
    break;

  case 566:
#line 3424 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PARAMDEF_OPTIONAL; }
    break;

  case 567:
#line 3425 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_PARAMDEF_RETVAL; }
    break;

  case 568:
#line 3426 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 569:
#line 3434 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_CALLCONV_DEFAULT; }
    break;

  case 570:
#line 3435 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(2) - (2)].integer) | IL_META_CALLCONV_HASTHIS; }
    break;

  case 571:
#line 3436 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(2) - (2)].integer) | IL_META_CALLCONV_EXPLICITTHIS; }
    break;

  case 572:
#line 3437 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_CALLCONV_DEFAULT; }
    break;

  case 573:
#line 3438 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_CALLCONV_VARARG; }
    break;

  case 574:
#line 3439 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_CALLCONV_C; }
    break;

  case 575:
#line 3440 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_CALLCONV_STDCALL; }
    break;

  case 576:
#line 3441 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_CALLCONV_THISCALL; }
    break;

  case 577:
#line 3442 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_CALLCONV_FASTCALL; }
    break;

  case 578:
#line 3450 "ilasm_grammar.y"
    {
				ILAsmDebugLine((ILUInt32)((yyvsp[(2) - (3)].integer)), 0, (yyvsp[(3) - (3)].strValue).string);
			}
    break;

  case 579:
#line 3453 "ilasm_grammar.y"
    {
				ILAsmDebugLine((ILUInt32)((yyvsp[(2) - (5)].integer)), (ILUInt32)((yyvsp[(4) - (5)].integer)), (yyvsp[(5) - (5)].strValue).string);
			}
    break;

  case 580:
#line 3456 "ilasm_grammar.y"
    {
				ILAsmDebugLine((ILUInt32)((yyvsp[(2) - (3)].integer)), 0, (yyvsp[(3) - (3)].strValue).string);
			}
    break;

  case 581:
#line 3459 "ilasm_grammar.y"
    {
				ILAsmDebugLine((ILUInt32)((yyvsp[(2) - (5)].integer)), (ILUInt32)((yyvsp[(4) - (5)].integer)), (yyvsp[(5) - (5)].strValue).string);
			}
    break;

  case 582:
#line 3462 "ilasm_grammar.y"
    {
				ILAsmDebugLine((ILUInt32)((yyvsp[(2) - (2)].integer)), 0, ILAsmDebugLastFile);
			}
    break;

  case 583:
#line 3465 "ilasm_grammar.y"
    {
				ILAsmDebugLine((ILUInt32)((yyvsp[(2) - (4)].integer)), (ILUInt32)((yyvsp[(4) - (4)].integer)),
							   ILAsmDebugLastFile);
			}
    break;

  case 584:
#line 3472 "ilasm_grammar.y"
    {
				/* Create the file declaration and attach the hash */
				ILFileDecl *decl = ILFileDeclCreate(ILAsmImage, 0,
													(yyvsp[(3) - (6)].strValue).string,
													(ILUInt32)((yyvsp[(2) - (6)].integer)));
				if(!decl)
				{
					ILAsmOutOfMemory();
				}
				if(!ILFileDeclSetHash(decl, (yyvsp[(6) - (6)].strValue).string, (yyvsp[(6) - (6)].strValue).len))
				{
					ILAsmOutOfMemory();
				}
				ILAsmLastToken = ILFileDecl_Token(decl);
			}
    break;

  case 585:
#line 3487 "ilasm_grammar.y"
    {
				/* Create the file declaration */
				ILFileDecl *decl = ILFileDeclCreate(ILAsmImage, 0,
													(yyvsp[(3) - (3)].strValue).string,
													(ILUInt32)((yyvsp[(2) - (3)].integer)));
				if(!decl)
				{
					ILAsmOutOfMemory();
				}
				ILAsmLastToken = ILFileDecl_Token(decl);
			}
    break;

  case 586:
#line 3501 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_FILE_WRITEABLE; }
    break;

  case 587:
#line 3502 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer) ^ IL_META_FILE_WRITEABLE; }
    break;

  case 588:
#line 3506 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 589:
#line 3507 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 590:
#line 3511 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_FILE_WRITEABLE; /* invert later */ }
    break;

  case 591:
#line 3512 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_FILE_CONTAINS_NO_META_DATA; }
    break;

  case 594:
#line 3525 "ilasm_grammar.y"
    {
				ILAssemblySetAttrs(ILAsmAssembly, ~0, (ILUInt32)((yyvsp[(2) - (4)].integer)));
				if(!ILAssemblySetName(ILAsmAssembly, (yyvsp[(3) - (4)].strValue).string))
				{
					ILAsmOutOfMemory();
				}
				ILAsmBuildPushScope(ILAsmAssembly);
				ILAsmCurrAssemblyRef = 0;
			}
    break;

  case 595:
#line 3537 "ilasm_grammar.y"
    {
				if(!strcmp((yyvsp[(1) - (1)].strValue).string, ".library"))
				{
					(yyval.strValue) = ILInternString(ILAsmLibraryName, -1);
				}
				else
				{
					(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
				}
			}
    break;

  case 596:
#line 3547 "ilasm_grammar.y"
    {
				(yyval.strValue) = ILInternString(ILAsmLibraryName, -1);
			}
    break;

  case 599:
#line 3559 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 600:
#line 3560 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 601:
#line 3564 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 602:
#line 3565 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 603:
#line 3569 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_ASSEM_PUBLIC_KEY; }
    break;

  case 604:
#line 3570 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_ASSEM_NON_SIDE_BY_SIDE_APP_DOMAIN; }
    break;

  case 605:
#line 3571 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_ASSEM_NON_SIDE_BY_SIDE_PROCESS; }
    break;

  case 606:
#line 3572 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_ASSEM_NON_SIDE_BY_SIDE_MACHINE; }
    break;

  case 607:
#line 3573 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_ASSEM_ENABLE_JIT_TRACKING; }
    break;

  case 608:
#line 3574 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_ASSEM_DISABLE_JIT_OPTIMIZER; }
    break;

  case 609:
#line 3578 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 610:
#line 3579 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 613:
#line 3588 "ilasm_grammar.y"
    { /* Obsolete */ }
    break;

  case 614:
#line 3589 "ilasm_grammar.y"
    { /* Obsolete */ }
    break;

  case 615:
#line 3590 "ilasm_grammar.y"
    {
				ILAssemblySetHashAlgorithm(ILAsmAssembly, (yyvsp[(3) - (3)].integer));
			}
    break;

  case 616:
#line 3593 "ilasm_grammar.y"
    {
				ILAssemblySetHashAlgorithm(ILAsmAssembly, (yyvsp[(3) - (3)].integer));
			}
    break;

  case 619:
#line 3601 "ilasm_grammar.y"
    {
					SetOriginator((yyvsp[(3) - (3)].strValue).string, (yyvsp[(3) - (3)].strValue).len, 1);
				}
    break;

  case 620:
#line 3604 "ilasm_grammar.y"
    {
					SetOriginator((yyvsp[(3) - (3)].strValue).string, (yyvsp[(3) - (3)].strValue).len, 1);
				}
    break;

  case 621:
#line 3607 "ilasm_grammar.y"
    {
					SetOriginator((yyvsp[(3) - (3)].strValue).string, (yyvsp[(3) - (3)].strValue).len, 0);
				}
    break;

  case 622:
#line 3610 "ilasm_grammar.y"
    {
				/* Set the assembly version */
				if(ILAsmCurrAssemblyRef)
				{
					ILAssemblySetVersionSplit
						(ILAsmCurrAssemblyRef,
						 (ILUInt32)((yyvsp[(2) - (8)].integer)), (ILUInt32)((yyvsp[(4) - (8)].integer)),
						 (ILUInt32)((yyvsp[(6) - (8)].integer)), (ILUInt32)((yyvsp[(8) - (8)].integer)));
				}
				else
				{
					ILAssemblySetVersionSplit
						(ILAsmAssembly,
						 (ILUInt32)((yyvsp[(2) - (8)].integer)), (ILUInt32)((yyvsp[(4) - (8)].integer)),
						 (ILUInt32)((yyvsp[(6) - (8)].integer)), (ILUInt32)((yyvsp[(8) - (8)].integer)));
				}
			}
    break;

  case 623:
#line 3627 "ilasm_grammar.y"
    {
				/* Set the assembly locale */
				if(ILAsmCurrAssemblyRef)
				{
					if(!ILAssemblySetLocale(ILAsmCurrAssemblyRef, (yyvsp[(2) - (2)].strValue).string))
					{
						ILAsmOutOfMemory();
					}
				}
				else
				{
					if(!ILAssemblySetLocale(ILAsmAssembly, (yyvsp[(2) - (2)].strValue).string))
					{
						ILAsmOutOfMemory();
					}
				}
			}
    break;

  case 624:
#line 3644 "ilasm_grammar.y"
    {
				/* Set the assembly locale to a byte list */
				if(ILAsmCurrAssemblyRef)
				{
					if(!ILAssemblySetLocale(ILAsmCurrAssemblyRef, (yyvsp[(3) - (3)].strValue).string))
					{
						ILAsmOutOfMemory();
					}
				}
				else
				{
					if(!ILAssemblySetLocale(ILAsmAssembly, (yyvsp[(3) - (3)].strValue).string))
					{
						ILAsmOutOfMemory();
					}
				}
			}
    break;

  case 625:
#line 3661 "ilasm_grammar.y"
    {
				/* Add a processor definition to the assembly */
				if(ILAsmCurrAssemblyRef)
				{
					if(!ILProcessorInfoCreate(ILAsmImage, 0, (ILUInt32)((yyvsp[(2) - (2)].integer)),
							 				  ILAsmCurrAssemblyRef))
					{
						ILAsmOutOfMemory();
					}
				}
				else
				{
					if(!ILProcessorInfoCreate(ILAsmImage, 0, (ILUInt32)((yyvsp[(2) - (2)].integer)),
											  ILAsmAssembly))
					{
						ILAsmOutOfMemory();
					}
				}
			}
    break;

  case 626:
#line 3680 "ilasm_grammar.y"
    {
				/* Add an OS definition to the assembly */
				if(ILAsmCurrAssemblyRef)
				{
					if(!ILOSInfoCreate(ILAsmImage, 0, (ILUInt32)((yyvsp[(2) - (6)].integer)),
							 (ILUInt32)((yyvsp[(4) - (6)].integer)), (ILUInt32)((yyvsp[(6) - (6)].integer)),
							 ILAsmCurrAssemblyRef))
					{
						ILAsmOutOfMemory();
					}
				}
				else
				{
					if(!ILOSInfoCreate(ILAsmImage, 0, (ILUInt32)((yyvsp[(2) - (6)].integer)),
									   (ILUInt32)((yyvsp[(4) - (6)].integer)), (ILUInt32)((yyvsp[(6) - (6)].integer)),
									   ILAsmAssembly))
					{
						ILAsmOutOfMemory();
					}
				}
			}
    break;

  case 627:
#line 3701 "ilasm_grammar.y"
    { /* Obsolete */ }
    break;

  case 628:
#line 3702 "ilasm_grammar.y"
    { /* Obsolete */ }
    break;

  case 630:
#line 3708 "ilasm_grammar.y"
    {
				ILAssembly *assem;
				assem = ILAssemblyCreate(ILAsmImage, 0, (yyvsp[(4) - (6)].strValue).string, 1);
				if(!assem)
				{
					ILAsmOutOfMemory();
				}
				ILAssemblySetRefAttrs(assem, ~0, (ILUInt32)((yyvsp[(3) - (6)].integer)));
				ILAsmBuildPushScope(assem);
				ILAsmCurrAssemblyRef = assem;
			}
    break;

  case 631:
#line 3719 "ilasm_grammar.y"
    {
				ILAssembly *assem;
				assem = ILAssemblyCreate(ILAsmImage, 0, (yyvsp[(4) - (4)].strValue).string, 1);
				if(!assem)
				{
					ILAsmOutOfMemory();
				}
				ILAssemblySetRefAttrs(assem, ~0, (ILUInt32)((yyvsp[(3) - (4)].integer)));
				ILAsmBuildPushScope(assem);
				ILAsmCurrAssemblyRef = assem;
			}
    break;

  case 632:
#line 3733 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 633:
#line 3734 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 634:
#line 3738 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 635:
#line 3739 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 636:
#line 3743 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_ASSEMREF_FULL_ORIGINATOR; }
    break;

  case 637:
#line 3747 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 638:
#line 3748 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 641:
#line 3757 "ilasm_grammar.y"
    {
				/* Set the hash value for the assembly reference */
				if(!ILAssemblySetHash(ILAsmCurrAssemblyRef,
									  (yyvsp[(3) - (3)].strValue).string, (yyvsp[(3) - (3)].strValue).len))
				{
					ILAsmOutOfMemory();
				}
			}
    break;

  case 644:
#line 3774 "ilasm_grammar.y"
    {
				/* Create the exported type */
				ILExportedType *type;
				const char *name;
				const char *namespace;
				ILAsmSplitName((yyvsp[(3) - (4)].strValue).string, (yyvsp[(3) - (4)].strValue).len, &name, &namespace);
				type = ILExportedTypeCreate(ILAsmImage, 0, (ILUInt32)((yyvsp[(2) - (4)].integer)),
											name, namespace, 0);
				ILAsmBuildPushScope(type);
			}
    break;

  case 650:
#line 3798 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 651:
#line 3799 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 652:
#line 3803 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 653:
#line 3804 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 654:
#line 3808 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NOT_PUBLIC; }
    break;

  case 655:
#line 3809 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_PUBLIC; }
    break;

  case 656:
#line 3810 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_PUBLIC; }
    break;

  case 657:
#line 3811 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_PRIVATE; }
    break;

  case 658:
#line 3812 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_FAMILY; }
    break;

  case 659:
#line 3813 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_ASSEMBLY; }
    break;

  case 660:
#line 3814 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_FAM_AND_ASSEM; }
    break;

  case 661:
#line 3815 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_TYPEDEF_NESTED_FAM_OR_ASSEM; }
    break;

  case 662:
#line 3819 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 663:
#line 3820 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 666:
#line 3829 "ilasm_grammar.y"
    {
				/* Set the exported type's scope to a file */
				ILExportedType *type =
					ILProgramItemToExportedType
						(ILProgramItem_FromToken(ILAsmImage, ILAsmLastToken));
				ILFileDecl *decl = ILAsmFindFile((yyvsp[(2) - (2)].strValue).string,
												 IL_META_FILE_WRITEABLE, 1);
				if(type && decl)
				{
					ILExportedTypeSetScopeFile(type, decl);
				}
			}
    break;

  case 667:
#line 3841 "ilasm_grammar.y"
    {
				/* Set the exported type's scope to an assembly reference */
				ILExportedType *type =
					ILProgramItemToExportedType
						(ILProgramItem_FromToken(ILAsmImage, ILAsmLastToken));
				ILAssembly *assem = ILAsmFindAssemblyRef((yyvsp[(3) - (3)].strValue).string);
				if(type && assem)
				{
					ILExportedTypeSetScopeAssembly(type, assem);
				}
			}
    break;

  case 668:
#line 3852 "ilasm_grammar.y"
    {
				/* Set the exported type's scope to another exported type */
				const char *name;
				const char *namespace;
				ILExportedType *type =
					ILProgramItemToExportedType
						(ILProgramItem_FromToken(ILAsmImage, ILAsmLastToken));
				ILExportedType *expType;
				ILAsmSplitName((yyvsp[(2) - (2)].strValue).string, (yyvsp[(2) - (2)].strValue).len, &name, &namespace);
				expType = ILExportedTypeFind(ILAsmImage, name, namespace);
				if(!expType)
				{
					ILAsmPrintMessage(ILAsmFilename, ILAsmLineNum,
									  "exported type `%s' not declared",
									  (yyvsp[(2) - (2)].strValue).string);
				}
				if(type && expType)
				{
					ILExportedTypeSetScopeType(type, expType);
				}
			}
    break;

  case 669:
#line 3873 "ilasm_grammar.y"
    {
				/* Set the foreign class identifier */
				ILExportedType *type =
					ILProgramItemToExportedType
						(ILProgramItem_FromToken(ILAsmImage, ILAsmLastToken));
				if(type)
				{
					ILExportedTypeSetId(type, (ILUInt32)((yyvsp[(2) - (2)].integer)));
				}
			}
    break;

  case 672:
#line 3893 "ilasm_grammar.y"
    {
				/* Create the manifest resource */
				ILManifestRes *res;
				res = ILManifestResCreate(ILAsmImage, 0,
										  (yyvsp[(3) - (4)].strValue).string, (ILUInt32)((yyvsp[(2) - (4)].integer)), 0);
				if(!res)
				{
					ILAsmOutOfMemory();
				}
				ILAsmBuildPushScope(res);
			}
    break;

  case 673:
#line 3907 "ilasm_grammar.y"
    { /* Old name */ }
    break;

  case 674:
#line 3908 "ilasm_grammar.y"
    { /* New name */ }
    break;

  case 677:
#line 3917 "ilasm_grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 678:
#line 3918 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 679:
#line 3922 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 680:
#line 3923 "ilasm_grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 681:
#line 3927 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_MANIFEST_PUBLIC; }
    break;

  case 682:
#line 3928 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_MANIFEST_PRIVATE; }
    break;

  case 683:
#line 3932 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 684:
#line 3933 "ilasm_grammar.y"
    { ILAsmBuildPopScope(); }
    break;

  case 689:
#line 3944 "ilasm_grammar.y"
    {
				/* Set the resource owner to a file */
				ILManifestRes *res =
					ILProgramItemToManifestRes
						(ILProgramItem_FromToken(ILAsmImage, ILAsmLastToken));
				ILFileDecl *decl = ILAsmFindFile((yyvsp[(2) - (4)].strValue).string,
												 IL_META_FILE_WRITEABLE, 1);
				if(res && decl)
				{
					ILManifestResSetOwnerFile(res, decl, (ILUInt32)((yyvsp[(4) - (4)].integer)));
				}
			}
    break;

  case 690:
#line 3956 "ilasm_grammar.y"
    {
				/* Set the resource owner to an assembly reference */
				ILManifestRes *res =
					ILProgramItemToManifestRes
						(ILProgramItem_FromToken(ILAsmImage, ILAsmLastToken));
				ILAssembly *assem = ILAsmFindAssemblyRef((yyvsp[(3) - (3)].strValue).string);
				if(res && assem)
				{
					ILManifestResSetOwnerAssembly(res, assem);
				}
			}
    break;

  case 694:
#line 3977 "ilasm_grammar.y"
    {
				ILIntString unicode = PackUnicodeString((yyvsp[(3) - (3)].strValue));
				ILAsmSecurityCreate((yyvsp[(2) - (3)].integer), unicode.string, unicode.len);
			}
    break;

  case 695:
#line 3981 "ilasm_grammar.y"
    {
				ILAsmSecurityCreate((yyvsp[(2) - (4)].integer), (yyvsp[(4) - (4)].strValue).string, (yyvsp[(4) - (4)].strValue).len);
			}
    break;

  case 696:
#line 3984 "ilasm_grammar.y"
    {
				ILIntString unicode = PackUnicodeString((yyvsp[(3) - (3)].strValue));
				ILAsmSecurityCreate((yyvsp[(2) - (3)].integer), unicode.string, unicode.len);
			}
    break;

  case 697:
#line 3988 "ilasm_grammar.y"
    {
				ILAsmSecurityCreate((yyvsp[(2) - (4)].integer), (yyvsp[(4) - (4)].strValue).string, (yyvsp[(4) - (4)].strValue).len);
			}
    break;

  case 698:
#line 3994 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_REQUEST; }
    break;

  case 699:
#line 3995 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_DEMAND; }
    break;

  case 700:
#line 3996 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_ASSERT; }
    break;

  case 701:
#line 3997 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_DENY; }
    break;

  case 702:
#line 3998 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_PERMIT_ONLY; }
    break;

  case 703:
#line 3999 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_LINK_TIME_CHECK; }
    break;

  case 704:
#line 4000 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_INHERITANCE_CHECK; }
    break;

  case 705:
#line 4001 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_REQUEST_MINIMUM; }
    break;

  case 706:
#line 4002 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_REQUEST_OPTIONAL; }
    break;

  case 707:
#line 4003 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_REQUEST_REFUSE; }
    break;

  case 708:
#line 4004 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_PREJIT_GRANT; }
    break;

  case 709:
#line 4005 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_PREJIT_DENIED; }
    break;

  case 710:
#line 4006 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_NON_CAS_DEMAND; }
    break;

  case 711:
#line 4007 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_NON_CAS_LINK_DEMAND; }
    break;

  case 712:
#line 4008 "ilasm_grammar.y"
    { (yyval.integer) = IL_META_SECURITY_NON_CAS_INHERITANCE; }
    break;

  case 715:
#line 4017 "ilasm_grammar.y"
    {}
    break;

  case 716:
#line 4025 "ilasm_grammar.y"
    { ILAsmAttributeCreate((yyvsp[(2) - (2)].customType), 0); }
    break;

  case 717:
#line 4026 "ilasm_grammar.y"
    {
				ILAsmAttributeCreate((yyvsp[(2) - (4)].customType), &((yyvsp[(4) - (4)].strValue)));
			}
    break;

  case 718:
#line 4029 "ilasm_grammar.y"
    {
				ILAsmAttributeCreate((yyvsp[(2) - (4)].customType), &((yyvsp[(4) - (4)].strValue)));
			}
    break;

  case 719:
#line 4032 "ilasm_grammar.y"
    {
				ILAsmAttributeCreateFor((yyvsp[(3) - (7)].token), (yyvsp[(5) - (7)].customType), &((yyvsp[(7) - (7)].strValue)));
			}
    break;

  case 720:
#line 4035 "ilasm_grammar.y"
    {
				ILAsmAttributeCreateFor((yyvsp[(3) - (7)].token), (yyvsp[(5) - (7)].customType), &((yyvsp[(7) - (7)].strValue)));
			}
    break;

  case 721:
#line 4038 "ilasm_grammar.y"
    {
				ILAsmAttributeCreateFor((yyvsp[(3) - (5)].token), (yyvsp[(5) - (5)].customType), 0);
			}
    break;

  case 722:
#line 4041 "ilasm_grammar.y"
    {
				/* Nothing to do here: ".language" is ignored */
			}
    break;

  case 723:
#line 4047 "ilasm_grammar.y"
    { (yyval.customType) = ILProgramItem_FromToken(ILAsmImage, (yyvsp[(1) - (1)].token)); }
    break;

  case 724:
#line 4051 "ilasm_grammar.y"
    { (yyval.token) = ILProgramItem_Token((yyvsp[(1) - (1)].typeSpec).item); }
    break;

  case 725:
#line 4052 "ilasm_grammar.y"
    { (yyval.token) = (yyvsp[(2) - (2)].token); }
    break;

  case 726:
#line 4053 "ilasm_grammar.y"
    {
				(yyval.token) = ILAsmResolveMember((yyvsp[(3) - (5)].typeSpec).item, (yyvsp[(5) - (5)].strValue).string, (yyvsp[(2) - (5)].type),
								        IL_META_MEMBERKIND_FIELD);
			}
    break;

  case 727:
#line 4057 "ilasm_grammar.y"
    {
				(yyval.token) = ILAsmResolveMember(ILToProgramItem(ILAsmClass),
										(yyvsp[(3) - (3)].strValue).string, (yyvsp[(2) - (3)].type),
										IL_META_MEMBERKIND_FIELD);
			}
    break;

  case 728:
#line 4069 "ilasm_grammar.y"
    { ILAsmOutSimple((yyvsp[(1) - (1)].opcode)); }
    break;

  case 729:
#line 4070 "ilasm_grammar.y"
    { ILAsmOutVar((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].integer)); }
    break;

  case 730:
#line 4071 "ilasm_grammar.y"
    { ILAsmOutVar((yyvsp[(1) - (2)].opcode), ILAsmOutLookupVar((yyvsp[(2) - (2)].strValue).string)); }
    break;

  case 731:
#line 4072 "ilasm_grammar.y"
    { ILAsmOutInt((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].integer)); }
    break;

  case 732:
#line 4073 "ilasm_grammar.y"
    {
				/* Determine what form of floating point value to output */
				if((yyvsp[(1) - (2)].opcode) == IL_OP_LDC_R4)
				{
					ILAsmOutFloat((yyvsp[(2) - (2)].floatValue).fbytes);
				}
				else
				{
					ILAsmOutDouble((yyvsp[(2) - (2)].floatValue).dbytes);
				}
			}
    break;

  case 733:
#line 4084 "ilasm_grammar.y"
    { ILAsmOutBranchInt((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].integer)); }
    break;

  case 734:
#line 4085 "ilasm_grammar.y"
    { ILAsmOutBranch((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].strValue).string); }
    break;

  case 735:
#line 4086 "ilasm_grammar.y"
    { ILAsmOutToken((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].token)); }
    break;

  case 736:
#line 4087 "ilasm_grammar.y"
    { ILAsmOutToken((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].token)); }
    break;

  case 737:
#line 4088 "ilasm_grammar.y"
    {
				/* Refer to a field in some other class */
				ILToken token = ILAsmResolveMember((yyvsp[(3) - (5)].typeSpec).item, (yyvsp[(5) - (5)].strValue).string, (yyvsp[(2) - (5)].type),
											       IL_META_MEMBERKIND_FIELD);
				ILAsmOutToken((yyvsp[(1) - (5)].opcode), token);
			}
    break;

  case 738:
#line 4094 "ilasm_grammar.y"
    {
				/* Refer to a field in the global module class */
				ILToken token = ILAsmResolveMember
						(ILToProgramItem(ILAsmModuleClass),
					     (yyvsp[(3) - (3)].strValue).string, (yyvsp[(2) - (3)].type),
					     IL_META_MEMBERKIND_FIELD);
				ILAsmOutToken((yyvsp[(1) - (3)].opcode), token);
			}
    break;

  case 739:
#line 4102 "ilasm_grammar.y"
    {
				if((yyvsp[(2) - (2)].typeSpec).item != 0)
				{
					ILAsmOutToken((yyvsp[(1) - (2)].opcode), ILProgramItem_Token((yyvsp[(2) - (2)].typeSpec).item));
				}
				else
				{
					ILAsmPrintMessage(ILAsmFilename, ILAsmLineNum,
									  "no token for type specification");
					ILAsmErrors = 1;
				}
			}
    break;

  case 740:
#line 4114 "ilasm_grammar.y"
    { ILAsmOutString((yyvsp[(2) - (2)].strValue)); }
    break;

  case 741:
#line 4115 "ilasm_grammar.y"
    { ILAsmOutString((yyvsp[(3) - (3)].strValue)); }
    break;

  case 742:
#line 4116 "ilasm_grammar.y"
    {
				ILType *sig = CreateMethodSig((yyvsp[(2) - (6)].integer), (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].params).paramFirst, 0, 1);
				ILStandAloneSig *stand =
					ILStandAloneSigCreate(ILAsmImage, 0, sig);
				if(!stand)
				{
					ILAsmOutOfMemory();
				}
				ILAsmOutToken((yyvsp[(1) - (6)].opcode), ILStandAloneSig_Token(stand));
			}
    break;

  case 743:
#line 4126 "ilasm_grammar.y"
    {
				ILAsmPrintMessage(ILAsmFilename, ILAsmLineNum,
								  "unsafe RVA instructions are not supported");
				ILAsmErrors = 1;
			}
    break;

  case 744:
#line 4131 "ilasm_grammar.y"
    {
				ILAsmPrintMessage(ILAsmFilename, ILAsmLineNum,
								  "unsafe RVA instructions are not supported");
				ILAsmErrors = 1;
			}
    break;

  case 745:
#line 4136 "ilasm_grammar.y"
    { ILAsmOutToken((yyvsp[(1) - (3)].opcode), (yyvsp[(3) - (3)].token)); }
    break;

  case 746:
#line 4137 "ilasm_grammar.y"
    {
				/* Refer to a field in some other class */
				ILToken token = ILAsmResolveMember((yyvsp[(4) - (6)].typeSpec).item, (yyvsp[(6) - (6)].strValue).string, (yyvsp[(3) - (6)].type),
											       IL_META_MEMBERKIND_FIELD);
				ILAsmOutToken((yyvsp[(1) - (6)].opcode), token);
			}
    break;

  case 747:
#line 4143 "ilasm_grammar.y"
    {
				/* Refer to a field in the current class */
				ILToken token = ILAsmResolveMember(ILToProgramItem(ILAsmClass),
												   (yyvsp[(4) - (4)].strValue).string, (yyvsp[(3) - (4)].type),
											       IL_META_MEMBERKIND_FIELD);
				ILAsmOutToken((yyvsp[(1) - (4)].opcode), token);
			}
    break;

  case 748:
#line 4150 "ilasm_grammar.y"
    {
				if((yyvsp[(2) - (2)].typeSpec).item != 0)
				{
					ILAsmOutToken((yyvsp[(1) - (2)].opcode), ILProgramItem_Token((yyvsp[(2) - (2)].typeSpec).item));
				}
				else
				{
					ILAsmPrintMessage(ILAsmFilename, ILAsmLineNum,
									  "no token for type specification");
					ILAsmErrors = 1;
				}
			}
    break;

  case 749:
#line 4162 "ilasm_grammar.y"
    {
				ILAsmOutSSAStart((yyvsp[(1) - (1)].opcode));
			}
    break;

  case 750:
#line 4165 "ilasm_grammar.y"
    {
				ILAsmOutSSAEnd();
			}
    break;

  case 751:
#line 4168 "ilasm_grammar.y"
    {
				ILAsmOutSwitchStart();
			}
    break;

  case 752:
#line 4171 "ilasm_grammar.y"
    {
	  			ILAsmOutSwitchEnd();
			}
    break;

  case 753:
#line 4177 "ilasm_grammar.y"
    { (yyval.floatValue) = (yyvsp[(1) - (1)].floatValue); }
    break;

  case 754:
#line 4178 "ilasm_grammar.y"
    {
				/* Convert a 64-bit integer into a float */
				SetFloat((yyval.floatValue).fbytes, (ILFloat)((yyvsp[(1) - (1)].integer)));
				SetDouble((yyval.floatValue).dbytes, (ILDouble)((yyvsp[(1) - (1)].integer)));
			}
    break;

  case 755:
#line 4183 "ilasm_grammar.y"
    {
				/* Convert a group of bytes into a float */
				if((yyvsp[(1) - (1)].strValue).len == 4)
				{
					/* Exact float supplied, so synthesize the double */
					ILMemCpy((yyval.floatValue).fbytes, (yyvsp[(1) - (1)].strValue).string, 4);
					SetDouble((yyval.floatValue).dbytes, (ILDouble)(IL_READ_FLOAT((yyval.floatValue).fbytes)));
				}
				else if((yyvsp[(1) - (1)].strValue).len == 8)
				{
					/* Exact double supplied, so synthesize the float */
					ILMemCpy((yyval.floatValue).dbytes, (yyvsp[(1) - (1)].strValue).string, 8);
					SetFloat((yyval.floatValue).fbytes, (ILFloat)(IL_READ_DOUBLE((yyval.floatValue).dbytes)));
				}
				else
				{
					/* Bad floating point value supplied */
					ILAsmPrintMessage(ILAsmFilename, ILAsmLineNum,
									  "invalid floating point value");
					ILAsmErrors = 1;
					(yyval.floatValue).fbytes[0] = 0;
					(yyval.floatValue).fbytes[1] = 0;
					(yyval.floatValue).fbytes[2] = 0;
					(yyval.floatValue).fbytes[3] = 0;
					(yyval.floatValue).dbytes[0] = 0;
					(yyval.floatValue).dbytes[1] = 0;
					(yyval.floatValue).dbytes[2] = 0;
					(yyval.floatValue).dbytes[3] = 0;
					(yyval.floatValue).dbytes[4] = 0;
					(yyval.floatValue).dbytes[5] = 0;
					(yyval.floatValue).dbytes[6] = 0;
					(yyval.floatValue).dbytes[7] = 0;
				}
			}
    break;

  case 758:
#line 4225 "ilasm_grammar.y"
    { ILAsmOutSSAValue((yyvsp[(1) - (1)].integer)); }
    break;

  case 759:
#line 4226 "ilasm_grammar.y"
    { ILAsmOutSSAValue((yyvsp[(2) - (2)].integer)); }
    break;

  case 764:
#line 4240 "ilasm_grammar.y"
    { ILAsmOutSwitchRef((yyvsp[(1) - (1)].strValue).string); }
    break;

  case 765:
#line 4241 "ilasm_grammar.y"
    { ILAsmOutSwitchRefInt((yyvsp[(1) - (1)].integer)); }
    break;

  case 766:
#line 4245 "ilasm_grammar.y"
    { ILJavaAsmOutSimple((yyvsp[(1) - (1)].opcode)); }
    break;

  case 767:
#line 4246 "ilasm_grammar.y"
    { ILJavaAsmOutVar((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].integer)); }
    break;

  case 768:
#line 4247 "ilasm_grammar.y"
    { ILJavaAsmOutInc((yyvsp[(1) - (3)].opcode), (yyvsp[(2) - (3)].integer), (yyvsp[(3) - (3)].integer)); }
    break;

  case 769:
#line 4248 "ilasm_grammar.y"
    { ILJavaAsmOutInt((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].integer));	  }
    break;

  case 770:
#line 4249 "ilasm_grammar.y"
    { ILJavaAsmOutConstInt32((yyvsp[(1) - (5)].opcode), (yyvsp[(4) - (5)].integer)); }
    break;

  case 771:
#line 4250 "ilasm_grammar.y"
    { ILJavaAsmOutConstInt64((yyvsp[(1) - (5)].opcode), (yyvsp[(4) - (5)].integer));}
    break;

  case 772:
#line 4251 "ilasm_grammar.y"
    { 
			ILJavaAsmOutConstFloat32((yyvsp[(1) - (5)].opcode), (yyvsp[(4) - (5)].floatValue).fbytes);
		}
    break;

  case 773:
#line 4254 "ilasm_grammar.y"
    { 
			ILJavaAsmOutConstFloat64((yyvsp[(1) - (5)].opcode), (yyvsp[(4) - (5)].floatValue).dbytes);
		}
    break;

  case 774:
#line 4257 "ilasm_grammar.y"
    { ILJavaAsmOutString((yyvsp[(2) - (2)].strValue)); }
    break;

  case 775:
#line 4258 "ilasm_grammar.y"
    { ILAsmOutBranchInt((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].integer)); }
    break;

  case 776:
#line 4259 "ilasm_grammar.y"
    { ILAsmOutBranch((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].strValue).string); }
    break;

  case 777:
#line 4260 "ilasm_grammar.y"
    { ILJavaAsmOutToken((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].token)); }
    break;

  case 778:
#line 4261 "ilasm_grammar.y"
    {
			ILJavaAsmOutRef((yyvsp[(1) - (4)].opcode), 1, (yyvsp[(2) - (4)].strValue).string, (yyvsp[(3) - (4)].strValue).string, (yyvsp[(4) - (4)].strValue).string);
		}
    break;

  case 779:
#line 4264 "ilasm_grammar.y"
    {
			/* Refer to a field in some other class */
			ILToken token = ILAsmResolveMember((yyvsp[(3) - (5)].typeSpec).item, (yyvsp[(5) - (5)].strValue).string, (yyvsp[(2) - (5)].type),
												   IL_META_MEMBERKIND_FIELD);
			ILJavaAsmOutToken((yyvsp[(1) - (5)].opcode), token);
		}
    break;

  case 780:
#line 4270 "ilasm_grammar.y"
    {
			ILJavaAsmOutRef((yyvsp[(1) - (4)].opcode), 0, (yyvsp[(2) - (4)].strValue).string, (yyvsp[(3) - (4)].strValue).string, (yyvsp[(4) - (4)].strValue).string);
		}
    break;

  case 781:
#line 4273 "ilasm_grammar.y"
    {
			if((yyvsp[(2) - (2)].typeSpec).item != 0)
			{
				ILJavaAsmOutToken((yyvsp[(1) - (2)].opcode), ILProgramItem_Token((yyvsp[(2) - (2)].typeSpec).item));
			}
			else
			{
				ILAsmPrintMessage(ILAsmFilename, ILAsmLineNum,
								  "no token for type specification");
				ILAsmErrors = 1;
			}
		}
    break;

  case 782:
#line 4285 "ilasm_grammar.y"
    { ILJavaAsmOutType((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].strValue).string); }
    break;

  case 783:
#line 4286 "ilasm_grammar.y"
    { 
			/* FIXME: what is the meaning of the Integer32 node here ?? */
			ILJavaAsmOutToken((yyvsp[(1) - (3)].opcode), (yyvsp[(2) - (3)].token));
		}
    break;

  case 784:
#line 4290 "ilasm_grammar.y"
    {
			/* FIXME: what is the meaning of the Integer32 node here ?? */
			ILJavaAsmOutRef((yyvsp[(1) - (5)].opcode), 1, (yyvsp[(2) - (5)].strValue).string, (yyvsp[(3) - (5)].strValue).string, (yyvsp[(4) - (5)].strValue).string);
		}
    break;

  case 785:
#line 4294 "ilasm_grammar.y"
    { ILJavaAsmOutNewarray((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].integer)); }
    break;

  case 786:
#line 4295 "ilasm_grammar.y"
    {
			ILJavaAsmOutMultinewarray((yyvsp[(1) - (3)].opcode), (yyvsp[(2) - (3)].typeSpec).type, (yyvsp[(3) - (3)].integer));
		}
    break;

  case 787:
#line 4298 "ilasm_grammar.y"
    { 
			ILJavaAsmOutMultinewarrayFromName((yyvsp[(1) - (3)].opcode), (yyvsp[(2) - (3)].strValue).string, (yyvsp[(3) - (3)].integer));
		}
    break;

  case 788:
#line 4301 "ilasm_grammar.y"
    {
			ILJavaAsmOutTableSwitchStart((yyvsp[(4) - (5)].integer));
		}
    break;

  case 789:
#line 4304 "ilasm_grammar.y"
    {
			ILJavaAsmOutTableSwitchEnd((yyvsp[(4) - (8)].integer));
		}
    break;

  case 790:
#line 4307 "ilasm_grammar.y"
    { 
			ILJavaAsmOutLookupSwitchStart();
		}
    break;

  case 791:
#line 4310 "ilasm_grammar.y"
    {
			ILJavaAsmOutLookupSwitchEnd();
		}
    break;

  case 792:
#line 4316 "ilasm_grammar.y"
    { (yyval.integer) = 4; }
    break;

  case 793:
#line 4317 "ilasm_grammar.y"
    { (yyval.integer) = 5; }
    break;

  case 794:
#line 4318 "ilasm_grammar.y"
    { (yyval.integer) = 6; }
    break;

  case 795:
#line 4319 "ilasm_grammar.y"
    { (yyval.integer) = 7; }
    break;

  case 796:
#line 4320 "ilasm_grammar.y"
    { (yyval.integer) = 8; }
    break;

  case 797:
#line 4321 "ilasm_grammar.y"
    { (yyval.integer) = 9; }
    break;

  case 798:
#line 4322 "ilasm_grammar.y"
    { (yyval.integer) = 10; }
    break;

  case 799:
#line 4323 "ilasm_grammar.y"
    { (yyval.integer) = 11; }
    break;

  case 804:
#line 4337 "ilasm_grammar.y"
    { ILJavaAsmOutTableSwitchDefaultRef((yyvsp[(1) - (1)].strValue).string); }
    break;

  case 805:
#line 4338 "ilasm_grammar.y"
    { ILJavaAsmOutTableSwitchDefaultRefInt((yyvsp[(1) - (1)].integer)); }
    break;

  case 806:
#line 4342 "ilasm_grammar.y"
    { ILJavaAsmOutTableSwitchRef((yyvsp[(1) - (1)].strValue).string); }
    break;

  case 807:
#line 4343 "ilasm_grammar.y"
    { ILJavaAsmOutTableSwitchRefInt((yyvsp[(1) - (1)].integer)); }
    break;

  case 812:
#line 4357 "ilasm_grammar.y"
    { ILJavaAsmOutLookupSwitchDefaultRef((yyvsp[(1) - (1)].strValue).string); }
    break;

  case 813:
#line 4358 "ilasm_grammar.y"
    { ILJavaAsmOutLookupSwitchDefaultRefInt((yyvsp[(1) - (1)].integer)); }
    break;

  case 814:
#line 4362 "ilasm_grammar.y"
    { ILJavaAsmOutLookupSwitchRef((yyvsp[(1) - (3)].integer), (yyvsp[(3) - (3)].strValue).string); }
    break;

  case 815:
#line 4363 "ilasm_grammar.y"
    { ILJavaAsmOutLookupSwitchRefInt((yyvsp[(1) - (3)].integer), (yyvsp[(3) - (3)].integer)); }
    break;


/* Line 1267 of yacc.c.  */
#line 9449 "ilasm_grammar.c"
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



