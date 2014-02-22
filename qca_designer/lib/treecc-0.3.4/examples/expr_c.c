/* expr_c.c.  Generated automatically by treecc */
#line 41 "./expr_c.tc"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "expr_c.h"

#line 11 "expr_c.c"

#define YYNODESTATE_TRACK_LINES 1
#line 1 "c_skel.c"
/*
 * treecc node allocation routines for C.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
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
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#include <stdlib.h>

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * The fixed global state to use for non-reentrant allocation.
 */
#ifndef YYNODESTATE_REENTRANT
static YYNODESTATE fixed_state__;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	((unsigned)(&(((struct _YYNODESTATE_align_##type *)0)->field)))
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Initialize the node allocation pool.
 */
#ifdef YYNODESTATE_REENTRANT
void yynodeinit(state__)
YYNODESTATE *state__;
{
#else
void yynodeinit()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	state__->blocks__ = 0;
	state__->push_stack__ = 0;
	state__->used__ = 0;
}

/*
 * Allocate a block of memory.
 */
#ifdef YYNODESTATE_REENTRANT
void *yynodealloc(state__, size__)
YYNODESTATE *state__;
unsigned int size__;
{
#else
void *yynodealloc(size__)
unsigned int size__;
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = state__->blocks__;
	if(!block__ || (state__->used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = (struct YYNODESTATE_block *)
						malloc(sizeof(struct YYNODESTATE_block));
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   supply the "yynodefailed" function to report the
			   out of memory state and/or abort the program */
#ifdef YYNODESTATE_REENTRANT
			yynodefailed(state__);
#else
			yynodefailed();
#endif
			return (void *)0;
		}
		block__->next__ = state__->blocks__;
		state__->blocks__ = block__;
		state__->used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + state__->used__);
	state__->used__ += size__;
	return result__;
}

/*
 * Push the node allocation state.
 */
#ifdef YYNODESTATE_REENTRANT
int yynodepush(state__)
YYNODESTATE *state__;
{
#else
int yynodepush()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = state__->blocks__;
	saved_used__ = state__->used__;

	/* Allocate space for a push item */
#ifdef YYNODESTATE_REENTRANT
	push_item__ = (struct YYNODESTATE_push *)
			yynodealloc(state__, sizeof(struct YYNODESTATE_push));
#else
	push_item__ = (struct YYNODESTATE_push *)
			yynodealloc(sizeof(struct YYNODESTATE_push));
#endif
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = state__->push_stack__;
	state__->push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
#ifdef YYNODESTATE_REENTRANT
void yynodepop(state__)
YYNODESTATE *state__;
{
#else
void yynodepop()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = state__->push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		state__->used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		state__->used__ = push_item__->saved_used__;
		state__->push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(state__->blocks__ != saved_block__)
	{
		temp_block__ = state__->blocks__;
		state__->blocks__ = temp_block__->next__;
		free(temp_block__);
	}
}

/*
 * Clear the node allocation pool completely.
 */
#ifdef YYNODESTATE_REENTRANT
void yynodeclear(state__)
YYNODESTATE *state__;
{
#else
void yynodeclear()
{
	YYNODESTATE *state__ = &fixed_state__;
#endif
	struct YYNODESTATE_block *temp_block__;
	while(state__->blocks__ != 0)
	{
		temp_block__ = state__->blocks__;
		state__->blocks__ = temp_block__->next__;
		free(temp_block__);
	}
	state__->push_stack__ = 0;
	state__->used__ = 0;
}
#line 279 "expr_c.c"
struct expression_vtable__ const expression_vt__ = {
	0,
	expression_kind,
	"expression",
	(eval_value (*)(expression *this__))0,
};

struct binary_vtable__ const binary_vt__ = {
	&expression_vt__,
	binary_kind,
	"binary",
	(eval_value (*)(expression *this__))0,
};

struct unary_vtable__ const unary_vt__ = {
	&expression_vt__,
	unary_kind,
	"unary",
	(eval_value (*)(expression *this__))0,
};

eval_value intnum_eval_expr__(intnum *e)
#line 343 "./expr_c.tc"
{
	eval_value value;
	value.int_value = e->num;
	return value;
}
#line 308 "expr_c.c"

struct intnum_vtable__ const intnum_vt__ = {
	&expression_vt__,
	intnum_kind,
	"intnum",
	(eval_value (*)(expression *this__))intnum_eval_expr__,
};

eval_value floatnum_eval_expr__(floatnum *e)
#line 350 "./expr_c.tc"
{
	eval_value value;
	value.float_value = e->num;
	return value;
}
#line 324 "expr_c.c"

struct floatnum_vtable__ const floatnum_vt__ = {
	&expression_vt__,
	floatnum_kind,
	"floatnum",
	(eval_value (*)(expression *this__))floatnum_eval_expr__,
};

eval_value cast_eval_expr__(cast *e)
#line 331 "./expr_c.tc"
{
	/* Evaluate the sub-expression */
	eval_value value = eval_expr(e->expr);

	/* Cast to the final type */
	coerce(&value, e->expr->type, e->type);

	/* Return the result to the caller */
	return value;
}
#line 345 "expr_c.c"

struct cast_vtable__ const cast_vt__ = {
	&expression_vt__,
	cast_kind,
	"cast",
	(eval_value (*)(expression *this__))cast_eval_expr__,
};

eval_value plus_eval_expr__(plus *e)
#line 185 "./expr_c.tc"
{
	/* Evaluate the sub-expressions */
	eval_value value1 = eval_expr(e->expr1);
	eval_value value2 = eval_expr(e->expr2);

	/* Coerce to the common type */
	coerce(&value1, e->expr1->type, e->type);
	coerce(&value2, e->expr2->type, e->type);

	/* Evaluate the operator */
	if(e->type == int_type)
	{
		value1.int_value += value2.int_value;
	}
	else
	{
		value1.float_value += value2.float_value;
	}

	/* Return the result to the caller */
	return value1;
}
#line 378 "expr_c.c"

struct plus_vtable__ const plus_vt__ = {
	&binary_vt__,
	plus_kind,
	"plus",
	(eval_value (*)(expression *this__))plus_eval_expr__,
};

eval_value minus_eval_expr__(minus *e)
#line 209 "./expr_c.tc"
{
	/* Evaluate the sub-expressions */
	eval_value value1 = eval_expr(e->expr1);
	eval_value value2 = eval_expr(e->expr2);

	/* Coerce to the common type */
	coerce(&value1, e->expr1->type, e->type);
	coerce(&value2, e->expr2->type, e->type);

	/* Evaluate the operator */
	if(e->type == int_type)
	{
		value1.int_value -= value2.int_value;
	}
	else
	{
		value1.float_value -= value2.float_value;
	}

	/* Return the result to the caller */
	return value1;
}
#line 411 "expr_c.c"

struct minus_vtable__ const minus_vt__ = {
	&binary_vt__,
	minus_kind,
	"minus",
	(eval_value (*)(expression *this__))minus_eval_expr__,
};

eval_value multiply_eval_expr__(multiply *e)
#line 233 "./expr_c.tc"
{
	/* Evaluate the sub-expressions */
	eval_value value1 = eval_expr(e->expr1);
	eval_value value2 = eval_expr(e->expr2);

	/* Coerce to the common type */
	coerce(&value1, e->expr1->type, e->type);
	coerce(&value2, e->expr2->type, e->type);

	/* Evaluate the operator */
	if(e->type == int_type)
	{
		value1.int_value *= value2.int_value;
	}
	else
	{
		value1.float_value *= value2.float_value;
	}

	/* Return the result to the caller */
	return value1;
}
#line 444 "expr_c.c"

struct multiply_vtable__ const multiply_vt__ = {
	&binary_vt__,
	multiply_kind,
	"multiply",
	(eval_value (*)(expression *this__))multiply_eval_expr__,
};

eval_value divide_eval_expr__(divide *e)
#line 257 "./expr_c.tc"
{
	/* Evaluate the sub-expressions */
	eval_value value1 = eval_expr(e->expr1);
	eval_value value2 = eval_expr(e->expr2);

	/* Coerce to the common type */
	coerce(&value1, e->expr1->type, e->type);
	coerce(&value2, e->expr2->type, e->type);

	/* Evaluate the operator */
	if(e->type == int_type)
	{
		if(value2.int_value != 0)
		{
			value1.int_value /= value2.int_value;
		}
		else
		{
			fprintf(stderr, "%s:%ld: division by zero\n",
					yygetfilename(e), yygetlinenum(e));
			value1.int_value = 0;
		}
	}
	else
	{
		value1.float_value /= value2.float_value;
	}

	/* Return the result to the caller */
	return value1;
}
#line 486 "expr_c.c"

struct divide_vtable__ const divide_vt__ = {
	&binary_vt__,
	divide_kind,
	"divide",
	(eval_value (*)(expression *this__))divide_eval_expr__,
};

eval_value power_eval_expr__(power *e)
#line 290 "./expr_c.tc"
{
	/* Evaluate the sub-expressions */
	eval_value value1 = eval_expr(e->expr1);
	eval_value value2 = eval_expr(e->expr2);

	/* Evaluate the operator */
	if(e->type == int_type)
	{
		value1.int_value = (int)(pow((double)(value1.int_value),
		                             (double)(value2.int_value)));
	}
	else
	{
		value1.float_value = (float)(pow((double)(value1.float_value),
		                                 (double)(value2.int_value)));
	}

	/* Return the result to the caller */
	return value1;
}
#line 517 "expr_c.c"

struct power_vtable__ const power_vt__ = {
	&binary_vt__,
	power_kind,
	"power",
	(eval_value (*)(expression *this__))power_eval_expr__,
};

eval_value negate_eval_expr__(negate *e)
#line 312 "./expr_c.tc"
{
	/* Evaluate the sub-expression */
	eval_value value = eval_expr(e->expr);

	/* Evaluate the operator */
	if(e->type == int_type)
	{
		value.int_value = -(value.int_value);
	}
	else
	{
		value.float_value = -(value.float_value);
	}

	/* Return the result to the caller */
	return value;
}
#line 545 "expr_c.c"

struct negate_vtable__ const negate_vt__ = {
	&unary_vt__,
	negate_kind,
	"negate",
	(eval_value (*)(expression *this__))negate_eval_expr__,
};

expression *intnum_create(int num)
{
	intnum *node__ = (intnum *)yynodealloc(sizeof(struct intnum__));
	if(node__ == 0) return 0;
	node__->vtable__ = &intnum_vt__;
	node__->kind__ = intnum_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->num = num;
	return (expression *)node__;
}

expression *floatnum_create(float num)
{
	floatnum *node__ = (floatnum *)yynodealloc(sizeof(struct floatnum__));
	if(node__ == 0) return 0;
	node__->vtable__ = &floatnum_vt__;
	node__->kind__ = floatnum_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->num = num;
	return (expression *)node__;
}

expression *cast_create(type_code new_type, expression * expr)
{
	cast *node__ = (cast *)yynodealloc(sizeof(struct cast__));
	if(node__ == 0) return 0;
	node__->vtable__ = &cast_vt__;
	node__->kind__ = cast_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->new_type = new_type;
	node__->expr = expr;
	return (expression *)node__;
}

expression *plus_create(expression * expr1, expression * expr2)
{
	plus *node__ = (plus *)yynodealloc(sizeof(struct plus__));
	if(node__ == 0) return 0;
	node__->vtable__ = &plus_vt__;
	node__->kind__ = plus_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (expression *)node__;
}

expression *minus_create(expression * expr1, expression * expr2)
{
	minus *node__ = (minus *)yynodealloc(sizeof(struct minus__));
	if(node__ == 0) return 0;
	node__->vtable__ = &minus_vt__;
	node__->kind__ = minus_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (expression *)node__;
}

expression *multiply_create(expression * expr1, expression * expr2)
{
	multiply *node__ = (multiply *)yynodealloc(sizeof(struct multiply__));
	if(node__ == 0) return 0;
	node__->vtable__ = &multiply_vt__;
	node__->kind__ = multiply_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (expression *)node__;
}

expression *divide_create(expression * expr1, expression * expr2)
{
	divide *node__ = (divide *)yynodealloc(sizeof(struct divide__));
	if(node__ == 0) return 0;
	node__->vtable__ = &divide_vt__;
	node__->kind__ = divide_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (expression *)node__;
}

expression *power_create(expression * expr1, expression * expr2)
{
	power *node__ = (power *)yynodealloc(sizeof(struct power__));
	if(node__ == 0) return 0;
	node__->vtable__ = &power_vt__;
	node__->kind__ = power_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->expr1 = expr1;
	node__->expr2 = expr2;
	return (expression *)node__;
}

expression *negate_create(expression * expr)
{
	negate *node__ = (negate *)yynodealloc(sizeof(struct negate__));
	if(node__ == 0) return 0;
	node__->vtable__ = &negate_vt__;
	node__->kind__ = negate_kind;
	node__->filename__ = yycurrfilename();
	node__->linenum__ = yycurrlinenum();
	node__->type = error_type;
	node__->expr = expr;
	return (expression *)node__;
}

void coerce(eval_value * value, type_code from, type_code to)
{
	switch(from)
	{
		case error_type:
		{
			switch(to)
			{
				case error_type:
				{
#line 373 "./expr_c.tc"
					{
						/* Nothing to do here */
					}
#line 691 "expr_c.c"
				}
				break;

				case int_type:
				{
#line 373 "./expr_c.tc"
					{
						/* Nothing to do here */
					}
#line 701 "expr_c.c"
				}
				break;

				case float_type:
				{
#line 373 "./expr_c.tc"
					{
						/* Nothing to do here */
					}
#line 711 "expr_c.c"
				}
				break;

				default: break;
			}
		}
		break;

		case int_type:
		{
			switch(to)
			{
				case error_type:
				{
#line 373 "./expr_c.tc"
					{
						/* Nothing to do here */
					}
#line 730 "expr_c.c"
				}
				break;

				case int_type:
				{
#line 373 "./expr_c.tc"
					{
						/* Nothing to do here */
					}
#line 740 "expr_c.c"
				}
				break;

				case float_type:
				{
#line 363 "./expr_c.tc"
					{
						value->float_value = (float)(value->int_value);
					}
#line 750 "expr_c.c"
				}
				break;

				default: break;
			}
		}
		break;

		case float_type:
		{
			switch(to)
			{
				case error_type:
				{
#line 373 "./expr_c.tc"
					{
						/* Nothing to do here */
					}
#line 769 "expr_c.c"
				}
				break;

				case int_type:
				{
#line 368 "./expr_c.tc"
					{
						value->int_value = (int)(value->float_value);
					}
#line 779 "expr_c.c"
				}
				break;

				case float_type:
				{
#line 373 "./expr_c.tc"
					{
						/* Nothing to do here */
					}
#line 789 "expr_c.c"
				}
				break;

				default: break;
			}
		}
		break;

		default: break;
	}
}

static void infer_type_1__(power *e)
#line 145 "./expr_c.tc"
{
    infer_type(e->expr1);
    infer_type(e->expr2);

	if(e->expr1->type == error_type || e->expr2->type == error_type)
	{
		e->type = error_type;
	}
    else if(e->expr2->type != int_type)
    {
        fprintf(stderr, "%s:%ld: second argument to `^' is not an integer\n",
                yygetfilename(e), yygetlinenum(e));
		e->type = error_type;
    }
	else
	{
    	e->type = e->expr1->type;
	}
}
#line 823 "expr_c.c"

static void infer_type_2__(binary *e)
#line 110 "./expr_c.tc"
{
    infer_type(e->expr1);
    infer_type(e->expr2);

    if(e->expr1->type == error_type || e->expr2->type == error_type)
	{
        e->type = error_type;
	}
    else if(e->expr1->type == float_type || e->expr2->type == float_type)
    {
        e->type = float_type;
    }
    else
    {
        e->type = int_type;
    }
}
#line 844 "expr_c.c"

static void infer_type_3__(unary *e)
#line 129 "./expr_c.tc"
{
    infer_type(e->expr);
    e->type = e->expr->type;
}
#line 852 "expr_c.c"

static void infer_type_4__(intnum *e)
#line 135 "./expr_c.tc"
{
    e->type = int_type;
}
#line 859 "expr_c.c"

static void infer_type_5__(floatnum *e)
#line 140 "./expr_c.tc"
{
    e->type = float_type;
}
#line 866 "expr_c.c"

static void infer_type_6__(cast *e)
#line 166 "./expr_c.tc"
{
	infer_type(e->expr);

	if(e->expr->type != error_type)
	{
		e->type = e->new_type;
	}
	else
	{
		e->type = error_type;
	}
}
#line 882 "expr_c.c"

void infer_type(expression * e__)
{
	switch(e__->kind__)
	{
		case power_kind:
		{
			infer_type_1__((power *)e__);
		}
		break;

		case binary_kind:
		case plus_kind:
		case minus_kind:
		case multiply_kind:
		case divide_kind:
		{
			infer_type_2__((binary *)e__);
		}
		break;

		case unary_kind:
		case negate_kind:
		{
			infer_type_3__((unary *)e__);
		}
		break;

		case intnum_kind:
		{
			infer_type_4__((intnum *)e__);
		}
		break;

		case floatnum_kind:
		{
			infer_type_5__((floatnum *)e__);
		}
		break;

		case cast_kind:
		{
			infer_type_6__((cast *)e__);
		}
		break;

		default: break;
	}
}

struct yy_vtable__ {
	const struct yy_vtable__ *parent__;
	int kind__;
};

int yyisa__(const void *vtable__, int kind__)
{
	const struct yy_vtable__ *vt;
	vt = (const struct yy_vtable__ *)vtable__;
	while(vt != 0) {
		if(vt->kind__ == kind__)
			return 1;
		vt = vt->parent__;
	}
	return 0;
}

#line 380 "./expr_c.tc"


/*
 * Global data used by the expression parser.
 */
char *progname;
char *filename;
long linenum;

/*
 * Entry points that are imported from the yacc parser.
 */
extern void yyrestart(FILE *file);
extern int yyparse(void);

/*
 * Main entry point for the expression parser and evaluator.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	progname = argv[0];
	linenum = 1;
	if(argc < 2)
	{
		filename = "stdin";
		yyrestart(stdin);
	}
	else if((file = fopen(argv[1], "r")) == NULL)
	{
		perror(argv[1]);
		return 1;
	}
	else
	{
		filename = argv[1];
		yyrestart(file);
	}
	return yyparse();
}

/*
 * Get the name of the current input file in use by the parser.
 */
char *yycurrfilename(void)
{
	return filename;
}

/*
 * Get the line number for the current input line in use by the parser.
 */
long yycurrlinenum(void)
{
	return linenum;
}

/*
 * Report memory failure and exit.
 */
void yynodefailed(void)
{
	fputs(progname, stderr);
	fputs(": virtual memory exhausted\n", stderr);
	exit(1);
}

#line 1018 "expr_c.c"
