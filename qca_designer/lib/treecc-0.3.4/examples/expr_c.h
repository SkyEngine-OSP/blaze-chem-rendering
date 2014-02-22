/* expr_c.h.  Generated automatically by treecc */
#ifndef __yy_expr_c_h
#define __yy_expr_c_h
#line 24 "./expr_c.tc"


/*
 * Value that is computed by "eval_expr" below.
 */
typedef union
{
	int		int_value;
	float	float_value;

} eval_value;

#line 18 "expr_c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define expression_kind 5
#define binary_kind 6
#define unary_kind 7
#define intnum_kind 8
#define floatnum_kind 9
#define cast_kind 16
#define plus_kind 10
#define minus_kind 11
#define multiply_kind 12
#define divide_kind 13
#define power_kind 14
#define negate_kind 15

typedef struct expression__ expression;
typedef struct binary__ binary;
typedef struct unary__ unary;
typedef struct intnum__ intnum;
typedef struct floatnum__ floatnum;
typedef struct cast__ cast;
typedef struct plus__ plus;
typedef struct minus__ minus;
typedef struct multiply__ multiply;
typedef struct divide__ divide;
typedef struct power__ power;
typedef struct negate__ negate;
typedef enum {
	error_type,
	int_type,
	float_type
} type_code;


#line 1 "c_skel.h"
typedef struct
{
	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;

} YYNODESTATE;
#line 64 "expr_c.h"
struct expression__ {
	const struct expression_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
};

struct expression_vtable__ {
	const void *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct expression_vtable__ const expression_vt__;

#define eval_expr(this__) \
	((*(((struct expression_vtable__ *)((this__)->vtable__))->eval_expr_v__)) \
		((expression *)(this__)))

struct binary__ {
	const struct binary_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr1;
	expression * expr2;
};

struct binary_vtable__ {
	const struct expression_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct binary_vtable__ const binary_vt__;

struct unary__ {
	const struct unary_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr;
};

struct unary_vtable__ {
	const struct expression_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct unary_vtable__ const unary_vt__;

struct intnum__ {
	const struct intnum_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	int num;
};

struct intnum_vtable__ {
	const struct expression_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct intnum_vtable__ const intnum_vt__;

extern eval_value intnum_eval_expr__(intnum *e);

struct floatnum__ {
	const struct floatnum_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	float num;
};

struct floatnum_vtable__ {
	const struct expression_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct floatnum_vtable__ const floatnum_vt__;

extern eval_value floatnum_eval_expr__(floatnum *e);

struct cast__ {
	const struct cast_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	type_code new_type;
	expression * expr;
};

struct cast_vtable__ {
	const struct expression_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct cast_vtable__ const cast_vt__;

extern eval_value cast_eval_expr__(cast *e);

struct plus__ {
	const struct plus_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr1;
	expression * expr2;
};

struct plus_vtable__ {
	const struct binary_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct plus_vtable__ const plus_vt__;

extern eval_value plus_eval_expr__(plus *e);

struct minus__ {
	const struct minus_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr1;
	expression * expr2;
};

struct minus_vtable__ {
	const struct binary_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct minus_vtable__ const minus_vt__;

extern eval_value minus_eval_expr__(minus *e);

struct multiply__ {
	const struct multiply_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr1;
	expression * expr2;
};

struct multiply_vtable__ {
	const struct binary_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct multiply_vtable__ const multiply_vt__;

extern eval_value multiply_eval_expr__(multiply *e);

struct divide__ {
	const struct divide_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr1;
	expression * expr2;
};

struct divide_vtable__ {
	const struct binary_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct divide_vtable__ const divide_vt__;

extern eval_value divide_eval_expr__(divide *e);

struct power__ {
	const struct power_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr1;
	expression * expr2;
};

struct power_vtable__ {
	const struct binary_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct power_vtable__ const power_vt__;

extern eval_value power_eval_expr__(power *e);

struct negate__ {
	const struct negate_vtable__ *vtable__;
	int kind__;
	char *filename__;
	long linenum__;
	type_code type;
	expression * expr;
};

struct negate_vtable__ {
	const struct unary_vtable__ *parent__;
	int kind__;
	const char *name__;
	eval_value (*eval_expr_v__)(expression *this__);
};

extern struct negate_vtable__ const negate_vt__;

extern eval_value negate_eval_expr__(negate *e);

extern expression *intnum_create(int num);
extern expression *floatnum_create(float num);
extern expression *cast_create(type_code new_type, expression * expr);
extern expression *plus_create(expression * expr1, expression * expr2);
extern expression *minus_create(expression * expr1, expression * expr2);
extern expression *multiply_create(expression * expr1, expression * expr2);
extern expression *divide_create(expression * expr1, expression * expr2);
extern expression *power_create(expression * expr1, expression * expr2);
extern expression *negate_create(expression * expr);

extern void coerce(eval_value * value, type_code from, type_code to);
extern void infer_type(expression * e);

#ifndef yykind
#define yykind(node__) ((node__)->kind__)
#endif

#ifndef yykindname
#define yykindname(node__) ((node__)->vtable__->name__)
#endif

#ifndef yykindof
#define yykindof(type__) (type__##_kind)
#endif

#ifndef yyisa
extern int yyisa__(const void *vtable__, int kind__);
#define yyisa(node__,type__) \
	(yyisa__((node__)->vtable__, (type__##_kind)))
#endif

#ifndef yygetfilename
#define yygetfilename(node__) ((node__)->filename__)
#endif

#ifndef yygetlinenum
#define yygetlinenum(node__) ((node__)->linenum__)
#endif

#ifndef yysetfilename
#define yysetfilename(node__, value__) \
	((node__)->filename__ = (value__))
#endif

#ifndef yysetlinenum
#define yysetlinenum(node__, value__) \
	((node__)->linenum__ = (value__))
#endif

#ifndef yytracklines_declared
extern char *yycurrfilename(void);
extern long yycurrlinenum(void);
#define yytracklines_declared 1
#endif

#ifndef yynodeops_declared
extern void yynodeinit(void);
extern void *yynodealloc(unsigned int size__);
extern int yynodepush(void);
extern void yynodepop(void);
extern void yynodeclear(void);
extern void yynodefailed(void);
#define yynodeops_declared 1
#endif

#ifdef __cplusplus
};
#endif

#endif
