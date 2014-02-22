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
/* Line 1529 of yacc.c.  */
#line 660 "ilasm_grammar.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

