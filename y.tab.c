#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "symbol.h"
	#define TABLESIZE 100
	#define WORDSIZE 4
	#define STLEN 32
	#define MAXEXPR 1024
	#define MAXSTRNGS 100
	#define MAXARGS 32
extern int yylineno;

int yywrap(){
	return 1;
}


void yyerror(const char *str){
	fprintf(stderr, "At line: %d\nerror: %s\n",yylineno,str);

}

sym_table *global_table;
sym_table *local_table;
char* glb_strings[MAXSTRNGS];
int str_counter = 0;

expr *tmp, *tmp2;
expr *NOARG = 0;
symbol *NOARGS = 0;
instr *f_def, *current_block;

char current_function[MAXIDLEN];

symbol *tmp_sym, *tmp_sym2, *current_args;

#line 39 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
 char *a;
 int fn;
 struct exp_ *e;
 enum type_ t;
 enum compr{
	INFE,
	EGA,
	SU,
	INFEQUA,
	SUPEQUA,
	DIF
 } entier;
 struct symbol_ *s;
 struct declar_ *d;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 80 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define STRING 258
#define CONST_INT 259
#define CONST_STRING 260
#define IDENT 261
#define EXTERN 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define DO 266
#define RETURN 267
#define FOR 268
#define THEN 269
#define assignment 270
#define INF 271
#define EGAL 272
#define SUP 273
#define INFEQUAL 274
#define SUPEQUAL 275
#define DIFF 276
#define PLUS 277
#define MINUS 278
#define MULTI 279
#define DIV 280
#define SHIFTRIGHT 281
#define SHIFTLEFT 282
#define MODULO 283
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   28,   28,   28,    9,   25,   21,   21,   24,
   24,   26,   26,   23,   23,   23,   22,   22,   20,   20,
   19,   10,   10,   10,   10,   10,   10,   12,   12,    8,
   11,   11,   11,   11,   29,   30,   17,   17,   14,   14,
   18,   13,   13,   13,   15,   16,   27,   27,   27,   27,
   27,   27,    2,    2,    2,    3,    3,    3,    6,    6,
    6,    6,    4,    4,    5,    5,    5,    7,    7,    1,
    1,    1,    1,
};
static const short yylen[] = {                            2,
    1,    2,    1,    2,    1,    3,    3,    1,    1,    1,
    3,    1,    2,    1,    3,    1,    3,    4,    1,    3,
    2,    1,    1,    1,    1,    1,    1,    2,    2,    3,
    4,    3,    3,    2,    1,    1,    1,    2,    2,    4,
    4,    5,    6,    9,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    3,    1,    3,    3,    1,    3,
    3,    3,    1,    2,    1,    4,    3,    1,    3,    1,
    1,    1,    3,
};
static const short yydefred[] = {                         0,
    8,    9,    0,    0,    5,    0,    3,    1,    0,    4,
    2,    0,    0,   10,    0,   16,    0,    0,   35,    6,
    0,    7,    0,   71,   72,    0,    0,    0,   65,    0,
    0,   59,   63,    0,   17,   19,    0,    0,    0,    0,
    0,    0,    0,    0,   22,   36,    0,    0,   37,   23,
   24,   25,   26,   27,    0,    0,   12,    0,   34,   11,
    0,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   18,   21,    0,    0,    0,    0,    0,    0,   28,
   29,   38,   33,    0,    0,   13,   32,   67,    0,    0,
   73,    0,    0,    0,    0,   60,   61,   62,   20,    0,
    0,    0,    0,    0,   45,    0,    0,    0,   31,    0,
   66,   49,   47,   50,   51,   52,   48,    0,   41,    0,
    0,    0,   40,    0,    0,   42,    0,    0,   43,    0,
    0,    0,   44,
};
static const short yydgoto[] = {                          4,
   29,   47,   31,   32,   33,   34,   90,   48,    5,   49,
   50,   51,   52,   53,   54,  102,   55,   56,   36,   37,
    9,   16,   14,   15,    7,   58,  118,    8,   21,   59,
};
static const short yysindex[] = {                      -192,
    0,    0, -174, -192,    0, -246,    0,    0, -246,    0,
    0,   -7, -104,    0,  -37,    0,   50,  -40,    0,    0,
   58,    0, -246,    0,    0,    1,   50,   50,    0, -177,
 -171,    0,    0, -208,    0,    0,  -12, -215,   -6,   22,
   29,  100,   50,   34,    0,    0,  -57,   19,    0,    0,
    0,    0,    0,    0,   72,  100,    0,   58,    0,    0,
   96,    0,  -30,   50,   50,   50,   50,   50,   50,   50,
 -174,    0,    0,   50,   50,   50, -176,  -55, -150,    0,
    0,    0,    0, -149,   72,    0,    0,    0, -177,    4,
    0, -171, -171, -208, -208,    0,    0,    0,    0, -177,
 -179,   75,   77,   79,    0, -147,   61,  100,    0,   50,
    0,    0,    0,    0,    0,    0,    0,   50,    0,  100,
   50,   50,    0, -177, -177,    0,   80,   65,    0, -150,
   84,  100,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -23,  -21,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -41,    0,    0,    0,   -9,
    8,    0,    0,  -28,    0,    0,    0,    0,  102,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   86,    0,    0,    0,    0,   10,    0,
    0,   20,   32,  -16,   -4,    0,    0,    0,    0,  -32,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   44,  -29,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,   25,   49,   12,    0,   42,    0,  -74,    0,    2,
  114,    0,    0,    0,    0,  -62,   70,    0,   59,    0,
    6,  123,  109,    0,    5,    0,    0,  129,    0,  -38,
};
#define YYTABLESIZE 385
static const short yytable[] = {                         70,
   35,   80,   70,  105,  107,    6,   23,   10,   30,    6,
   91,   46,   56,  103,   12,   56,   83,   70,   19,   87,
   14,   22,   16,   38,   57,   57,   30,   57,   72,   46,
   56,   71,   18,   61,   15,   14,   58,   16,   62,   58,
   61,   30,   57,   77,  111,   73,  109,  110,   53,   15,
   68,   53,   63,   68,   58,  131,   82,   84,  127,  128,
   55,   75,   86,   55,    1,    2,   53,   78,   76,    3,
   68,   69,   54,   79,   70,   54,   38,   81,   55,   96,
   97,   98,    1,    2,   69,   89,   82,   69,  104,   28,
   54,  112,  113,  114,  115,  116,  117,   28,  100,  101,
  101,   64,   65,   64,   65,   66,   67,   94,   95,  123,
  106,   28,   92,   93,  108,  119,   45,  120,  121,  122,
  129,  126,   74,  130,  132,   39,   20,   85,   13,   99,
   45,   60,   11,  133,  124,   28,   88,    0,    0,   28,
    0,    0,  125,    0,   39,  101,  101,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   45,    0,
   70,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   19,    0,   46,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,    0,   46,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   39,    0,
   39,    0,    0,    0,    0,    0,    1,    2,    0,    0,
    0,    0,   19,   64,   65,   64,   65,    0,    0,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
   70,   70,   56,   56,   56,   56,   56,   56,   56,   56,
   64,   65,   56,   56,   57,   57,   57,   57,   57,   57,
   57,   57,   17,   74,   57,   57,   58,   58,   58,   58,
   58,   58,   58,   58,    0,    0,   58,   58,   53,   53,
   53,   53,   53,   53,    0,    0,    0,    0,   53,   53,
   55,   55,   55,   55,   55,   55,    0,    0,    0,    0,
   55,   55,   54,   54,   54,   54,   54,   54,   24,   25,
   26,    0,   54,   54,    1,    2,   24,   25,   39,    0,
   40,    0,   41,   42,   43,   44,    0,   27,    0,    0,
   24,   25,   39,    0,   40,   27,   41,   42,   43,   44,
    0,    0,    0,    0,   39,   39,   39,    0,   39,   27,
   39,   39,   39,   39,   24,   25,   26,    0,   24,   25,
   39,    0,   40,   39,   41,   42,   43,   44,    0,    0,
    0,    0,    0,   27,    0,    0,    0,   27,   70,   70,
   70,   70,   70,   70,   70,
};
static const short yycheck[] = {                         41,
   41,   59,   44,   59,   79,    0,   44,    3,   41,    4,
   41,   41,   41,   76,  261,   44,   55,   59,  123,   58,
   44,   59,   44,   18,   41,   21,   59,   44,   41,   59,
   59,   44,   40,   40,   44,   59,   41,   59,   27,   44,
   40,   17,   59,   42,   41,  261,   85,   44,   41,   59,
   41,   44,   28,   44,   59,  130,   55,   56,  121,  122,
   41,   40,   58,   44,  257,  258,   59,   43,   40,  262,
  279,  280,   41,   40,  283,   44,   71,   59,   59,   68,
   69,   70,  257,  258,   41,   61,   85,   44,  265,   40,
   59,  271,  272,  273,  274,  275,  276,   40,   74,   75,
   76,  281,  282,  281,  282,  277,  278,   66,   67,  108,
  261,   40,   64,   65,  264,   41,   59,   41,   40,   59,
   41,  120,  270,   59,   41,   40,   13,   58,    6,   71,
   59,   23,    4,  132,  110,   40,   41,   -1,   -1,   40,
   -1,   -1,  118,   -1,   59,  121,  122,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,   -1,
   -1,   -1,  123,  281,  282,  281,  282,   -1,   -1,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  271,  272,  273,  274,  275,  276,  277,  278,
  281,  282,  281,  282,  271,  272,  273,  274,  275,  276,
  277,  278,  270,  270,  281,  282,  271,  272,  273,  274,
  275,  276,  277,  278,   -1,   -1,  281,  282,  271,  272,
  273,  274,  275,  276,   -1,   -1,   -1,   -1,  281,  282,
  271,  272,  273,  274,  275,  276,   -1,   -1,   -1,   -1,
  281,  282,  271,  272,  273,  274,  275,  276,  259,  260,
  261,   -1,  281,  282,  257,  258,  259,  260,  261,   -1,
  263,   -1,  265,  266,  267,  268,   -1,  278,   -1,   -1,
  259,  260,  261,   -1,  263,  278,  265,  266,  267,  268,
   -1,   -1,   -1,   -1,  259,  260,  261,   -1,  263,  278,
  265,  266,  267,  268,  259,  260,  261,   -1,  259,  260,
  261,   -1,  263,  278,  265,  266,  267,  268,   -1,   -1,
   -1,   -1,   -1,  278,   -1,   -1,   -1,  278,  277,  278,
  279,  280,  281,  282,  283,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT",
"STRING","CONST_INT","CONST_STRING","IDENT","EXTERN","IF","ELSE","WHILE","DO",
"RETURN","FOR","THEN","assignment","INF","EGAL","SUP","INFEQUAL","SUPEQUAL",
"DIFF","PLUS","MINUS","MULTI","DIV","SHIFTRIGHT","SHIFTLEFT","MODULO",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : program",
"program : external_declaration",
"program : program external_declaration",
"external_declaration : declaration",
"external_declaration : EXTERN declaration",
"external_declaration : function_definition",
"function_definition : type function_declarator compound_instruction",
"declaration : type declarator_list ';'",
"type : INT",
"type : STRING",
"declarator_list : declarator",
"declarator_list : declarator_list ',' declarator",
"declaration_list : declaration",
"declaration_list : declaration_list declaration",
"declarator : IDENT",
"declarator : IDENT assignment expression",
"declarator : function_declarator",
"function_declarator : IDENT '(' ')'",
"function_declarator : IDENT '(' parameter_list ')'",
"parameter_list : parameter_declaration",
"parameter_list : parameter_list ',' parameter_declaration",
"parameter_declaration : type IDENT",
"instruction : ';'",
"instruction : compound_instruction",
"instruction : expression_instruction",
"instruction : iteration_instruction",
"instruction : select_instruction",
"instruction : jump_instruction",
"expression_instruction : expression ';'",
"expression_instruction : assignment_expression ';'",
"assignment_expression : IDENT assignment expression",
"compound_instruction : block_start declaration_list instruction_list block_end",
"compound_instruction : block_start declaration_list block_end",
"compound_instruction : block_start instruction_list block_end",
"compound_instruction : block_start block_end",
"block_start : '{'",
"block_end : '}'",
"instruction_list : instruction",
"instruction_list : instruction_list instruction",
"select_instruction : cond_instruction instruction",
"select_instruction : cond_instruction instruction ELSE instruction",
"cond_instruction : IF '(' condition ')'",
"iteration_instruction : WHILE '(' condition ')' instruction",
"iteration_instruction : DO instruction WHILE '(' condition ')'",
"iteration_instruction : FOR '(' assignment_expression ';' condition ';' assignment_expression ')' instruction",
"jump_instruction : RETURN expression ';'",
"condition : expression comparison_operator expression",
"comparison_operator : EGAL",
"comparison_operator : DIFF",
"comparison_operator : INF",
"comparison_operator : SUP",
"comparison_operator : INFEQUAL",
"comparison_operator : SUPEQUAL",
"expression : expression_additive",
"expression : expression SHIFTLEFT expression_additive",
"expression : expression SHIFTRIGHT expression_additive",
"expression_additive : expression_multiplicative",
"expression_additive : expression_additive PLUS expression_multiplicative",
"expression_additive : expression_additive MINUS expression_multiplicative",
"expression_multiplicative : unary_expression",
"expression_multiplicative : expression_multiplicative MULTI unary_expression",
"expression_multiplicative : expression_multiplicative DIV unary_expression",
"expression_multiplicative : expression_multiplicative MODULO unary_expression",
"unary_expression : expression_postfixee",
"unary_expression : MINUS unary_expression",
"expression_postfixee : primary_expression",
"expression_postfixee : IDENT '(' argument_expression_list ')'",
"expression_postfixee : IDENT '(' ')'",
"argument_expression_list : expression",
"argument_expression_list : argument_expression_list ',' expression",
"primary_expression : IDENT",
"primary_expression : CONST_INT",
"primary_expression : CONST_STRING",
"primary_expression : '(' expression ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 941 "parser.y"

int main(void) {

	int i;
	global_table = malloc(sizeof(sym_table));
	global_table->table = malloc(sizeof(symbol *)*TABLESIZE);
	global_table->prev = NULL;
	global_table->next = NULL;
	f_def = NULL;
	current_block = NULL;


	local_table = global_table;
	

	yyparse();
	printf("\t.comm .stracc,%d,%d\n\n",STLEN*WORDSIZE*2,WORDSIZE);
	if(str_counter > 0){
		printf(".section\t.rodata\n");
		for(i = 0; i < str_counter; ++i)
			printf("\t.s%d:\t.string\t%s\n", i, glb_strings[i]);
	}
	while(local_table != NULL)
		local_table = destroy_table(local_table);
		
	return 0;
}

int hash_sym(char *sym){
	unsigned int hash = 0;
	int i;

	for(i = 0; sym[i] != '\0'; ++i)
		hash = sym[i] + (hash << 6) + (hash << 16) - hash;
	return hash % TABLESIZE;
}

int find_symbol(char *sym, symbol **out, sym_table *t){
	symbol *track;
	sym_table *ti = t;
	int depth = 0;
	
	int i = hash_sym(sym);
	
	while(ti != NULL){
		track = ti->table[i];
		while(track != NULL){
			if(!strcmp(track->id, sym)){
				*out = track;
				return depth;
			}
			else track = track->next;
		}
		ti = ti->prev;
		++depth;
	}
	*out = NULL;
	return -1;

}






symbol *add_symbol(char *name, enum type_ t, enum type_ *a, enum scope_type s, sym_table *tbl){
	symbol *symb = malloc(sizeof(symbol));
	strcpy(symb->id, name);
	symb->type = t;
	symb->args = a;
	symb->scope = s;
	symb->next = NULL;

	int i = hash_sym(symb->id);
	
	symbol *track = tbl->table[i];
	symbol *prev = track;

	if(track == NULL){
		tbl->table[i] = symb;
		if(symb->args == NULL){
			switch(t){
				case INTEG:
					if(s == STACK){		
						tbl->size += WORDSIZE;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						symb->location = tbl->arg_size + WORDSIZE;
					}
					
					break;
				case STRIN:
					if(s == STACK){
						tbl->size += WORDSIZE*STLEN;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						tbl->size += WORDSIZE*STLEN;
						symb->location = tbl->size;
						symb->scope = STACK;
					}
					break;

			}
			
			
		}
		return symb;
	}

	while(track != NULL){
		if(!strcmp(track->id, symb->id)){
			if(symb->type != track->type){
				yyerror("Conflicting definitions");
				return NULL;
			}
			if(track->args != NULL || symb->args != NULL){
				if(track->args == NULL || symb->args == NULL){
						yyerror("Conflicting function definitions 1");
						printf("looked up %s, equal to %s\n", symb->id, track->id);
						return NULL;
					}
				else{
					i = 0;
					while(track->args[i] != VOID && symb->args[i] != VOID){
						if(track->args[i] != symb->args[i]){
							yyerror("Conflicting function definitions 3");
							return NULL;
						}
					}
					if(track->args[i] != VOID || symb->args[i] != VOID){
							yyerror("Conflicting function definitions 2");
							return NULL;
					}
					
				}
			}
			return track;
		}
		prev = track;
		track = track->next;
	}
	
	track = prev;
	
	track->next = symb; 
	if(symb->args == NULL){
			switch(t){
				case INTEG:
					if(s == STACK){		
						tbl->size += WORDSIZE;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						symb->location = tbl->arg_size + WORDSIZE;
					}
					
					break;
				case STRIN:
					if(s == STACK){
						tbl->size += WORDSIZE*STLEN;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						tbl->size += WORDSIZE*STLEN;
						symb->location = tbl->size;
						symb->scope = STACK;
					}
					break;
			}
			
			
	}
	return symb;



}


sym_table *create_table(sym_table *loc){
	
	int i;
	if(loc->next != NULL){
		yyerror("Creating table in middle of list");
		return NULL;
	}
	
	loc->next = malloc(sizeof(sym_table));
	loc->next->table = malloc(sizeof(symbol *)*TABLESIZE);
	for(i = 0; i < TABLESIZE; ++i)
		loc->next->table[i] = NULL;
	loc->next->prev = loc;
	loc->next->next = NULL;
	loc->next->size = 0;
	loc->next->arg_size = 0;
	return loc->next;

}

sym_table *destroy_table(sym_table *loc){

	symbol *s_track, *s_next;
	
	sym_table *ret = loc->prev;
	
	int i;
	for(i = 0; i < TABLESIZE; ++i){
		s_track = loc->table[i];
		while(s_track != NULL){
			s_next = s_track->next;
			free(s_track);
			s_track = s_next;
		}
	}
	
	free(loc->table);
	free(loc);
	if(ret != NULL)
		ret->next = NULL;

	return ret;
}

void print_instructions(instr *block){

	expr *e;
	symbol *arg, *tmp;
	int i;
	int totalargs = 0;

	if(block->prev == NULL)
		printf(".globl %s\n  .type %s,@function\n%s:\n", block->function, block->function, block->function);

	printf("  enter $%d, $0\n", block->stack_size);

	if(block->prev == NULL){
		i = 0;

		arg = block->args;
		while(arg != NULL && arg != NOARGS){
			++totalargs;

			if(arg->type == STRIN){
				++i;
				find_symbol(arg->id, &tmp, local_table);
				printf("  pushl $128\n  pushl %d(%%ebp)\n  leal -%d(%%ebp) %%eax\n  pushl %%eax\n  call strncpy\n  movb  $0, %d(%%eax)\n  addl $12, %%esp\n",4*(totalargs+1),i*WORDSIZE*STLEN, (WORDSIZE*STLEN)-1);		
			}
			arg = arg->next;

		}

	}

	e = block->list;
	while(e != NULL){
		print_expr(e, block->function);
		e = e->next;
	}

	if(block->prev == NULL){
		printf(".%s_ret:\n  leave\n  ret\n\n", block->function);
		return;
	}
	else printf("jump to prev block\n");


}


void print_expr(expr *e, char *function){
	expr *argslist[MAXARGS];
	expr *track;
	int argcounter;
	int i;
	switch(e->type){
			case LSHIFT:
				printf("  popl %%eax\n  popl %%ecx\n  sall %%cl, %%eax\n  pushl %%eax\n");
				break;
			case RSHIFT:
				printf("  popl %%eax\n  popl %%ecx\n  sarl %%cl, %%eax\n  pushl %%eax\n");
				break;
			case DIV:
				printf("  movl $0, %%edx\n  popl %%eax\n  popl %%ecx\n  cltd\n  idivl %%ecx\n  pushl %%eax\n");
				break;
			case MOD:
				printf("  movl $0, %%edx\n  popl %%eax\n  popl %%ecx\n  cltd\n  idivl %%ecx\n  pushl %%edx\n");
				break;
			case ADDII:
				printf("  popl %%eax\n  popl %%ecx\n  addl %%ecx, %%eax\n  pushl %%eax\n");
				break;
			case ADDSS:
				printf("  popl %%eax\n  popl %%ecx\n  pushl $%d\n  pushl %%eax\n  pushl $.stracc\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n  pushl %%ecx\n  pushl $.stracc\n  call strcat\n  movb $0, %d(%%eax)\n  addl $8, %%esp\n  pushl $.stracc\n", WORDSIZE*STLEN, (WORDSIZE*STLEN)-1, (WORDSIZE*STLEN)-1);
				break;
			case ADDIS:
				printf("  popl %%eax\n  popl %%edx\n  andw $0xff, %%ax\n  movw %%ax, .stracc\n  pushl %%edx\n  pushl $.stracc\n  call strcat\n  movb $0, %d(%%eax)\n  addl $8, %%esp\n  pushl $.stracc\n", (WORDSIZE*STLEN)-1);
				break;
			case ADDSI:
				printf("  popl %%edx\n  popl %%eax\n  andw $0xff, %%ax\n  movw %%ax, .stracc\n  sub $%d, %%esp\n  movl %%esp, %%ecx\n  pushl $.stracc\n  pushl %%ecx\n  call strcpy\n  addl $8, %%esp\n  pushl  $%d\n  pushl  %%edx\n  pushl  $.stracc\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n  pushl %%esp\n  pushl $.stracc\n  call strcat\n  movb $0, %d(%%eax)\n  addl $%d, %%esp\n  pushl $.stracc\n", WORDSIZE*STLEN, WORDSIZE*STLEN, (WORDSIZE*STLEN)-1,(WORDSIZE*STLEN)-1, 8+(WORDSIZE*STLEN) );
			case SUB:
				printf("  popl %%eax\n  popl %%ecx\n  subl %%ecx, %%eax\n  pushl %%eax\n");
				break;
			case MULT:
				printf("  popl %%eax\n  popl %%ecx\n  imull %%ecx, %%eax\n  pushl %%eax\n");
				break;
			case RETURN:
				printf("%s", e->data);
				printf("  jmp .%s_ret\n", function);
				break;

			case BLOCK_JUMP:
				print_instructions(e->block);
				break;


			default :
				if(e->args == NULL)
					printf("%s", e->data);
				else{
					argcounter = 0;
					
					track = e->args;
					if(track != NOARG){
						while(track != NULL){
							print_expr(track, function);
							if(track->type == STRIN || track->type == INTEG)
								++argcounter;
							else --argcounter;
							track = track->next;
						}
					}
					printf("  call %s\n", e->data);
					printf("  pushl %%eax\n");
					printf("  addl $%d, %%esp\n", argcounter*WORDSIZE);
						
				}
				break;
	 	}

}
/*

char *print_type(enum type_ t){
	switch(t){
		case INTEG:
		 return "integer";
		case STRIN:
		 return "string";
		case FUNCTION:
		 return "function";
		case VOID:
		 return "void";
		default:
		 return "unknown";
	}

}

void print_table(sym_table *t){


	int i;
	symbol *s;
	arg *a;

	printf("Symbol table");
	if(t->func != NULL)
		printf(" for function %s\n", t->func->id);
	else if(t->prev == NULL)
		printf(" GLOBAL\n");
	else printf("\n");

	printf("\n");

	printf("ID\t\t| type\t\t\t| Arguments\n");
	printf("------------------------------------------------------\n");

	for(i = 0; i < TABLESIZE; ++i){
		s = t->table[i];
		while(s != NULL){
			printf("%s\t\t| %s\t\t| ", s->id, print_type(s->type));
			if(s->type == FUNCTION){
				a = s->alist;
				while(a != NULL){
					printf("%s ", print_type(a->type));
					a = a->next;
				}
			}
			printf("\n");
			s = s->next;

		}


	}
	printf("\n");
}

void print_sym(char *symb, symbol **table){

	symbol *track = table[hash_sym(symb)];
	arg *argument;

	while(track != NULL){
		if(!strcmp(track->id, symb)){
			printf("Function: %s\n", track->id);
			printf("Arguments: ");
			argument = track->alist;
			while(argument != NULL){
				printf("%s ",argument->id);
				argument = argument->next; 
			}
			printf("\n");
			return;
		}
		else track = track->next;
	}
	return;


}
*/
#line 863 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 4:
#line 104 "parser.y"
	{
			declar *t = yystack.l_mark[0].d;
			int i;
			while(t != NULL){
				i = find_symbol(yystack.l_mark[0].d->id, &tmp_sym, local_table);
				tmp_sym->scope = EXT;
				t = t->next;
			}
			}
break;
case 6:
#line 117 "parser.y"
	{		declar *t = yystack.l_mark[-1].d;
							int argcount = 1;
							enum type_ *argtypes = NULL;
							tmp_sym = t->args;
							if(tmp_sym == NOARGS){
								argtypes = malloc(sizeof(enum type_));
								*argtypes = VOID;
							}
							else{
								while(tmp_sym != NULL){
									argcount++;
									tmp_sym = tmp_sym->next;
								}
								argtypes = malloc(sizeof(enum type_)*argcount);
								argcount = 0;
								tmp_sym = t->args;
								while(tmp_sym != NULL){
									argtypes[argcount] = tmp_sym->type;
									argcount++;
									tmp_sym = tmp_sym->next;
								}
								argtypes[argcount] = VOID;
							}
							tmp_sym = add_symbol(t->id, yystack.l_mark[-2].t, argtypes, GLOBAL, local_table);
						
						print_instructions(f_def);
						f_def = NULL;
						current_block = NULL;
						current_args = NULL;

						}
break;
case 7:
#line 153 "parser.y"
	{
					declar *t = yystack.l_mark[-1].d;
					int argcount = 1;
					enum type_ *argtypes = NULL;
					expr *last_instruction = NULL;
					expr *first_instruction = NULL;

					while(t != NULL){
						if(t->args == NULL){
							tmp_sym = add_symbol(t->id, yystack.l_mark[-2].t, NULL, STACK, local_table);
							if(t->set != NULL){
								if(last_instruction == NULL){
									last_instruction = t->set;
									first_instruction = t->set;
								}
								else 	
									last_instruction->next = t->set;

								int i = find_symbol(t->id, &tmp_sym, local_table);
								
								if(tmp_sym->type != t->set->type){
									yyerror("conflicting types in assignment expression");
									return -1;
								}
									
								tmp = t->set;
								while(tmp != NULL){
									tmp2 = tmp;
									tmp = tmp->next;			
								}
								tmp2 = malloc(sizeof(expr));
								tmp2->type = SET;
		
								tmp2->data = malloc(sizeof(char)*MAXEXPR);
								tmp2->data[0] = '\0';
								if(i == 0){
									if(tmp_sym->type == INTEG)
										snprintf(tmp2->data, MAXEXPR, "  popl -%d(%%ebp)\n", tmp_sym->location);
									else
										snprintf(tmp2->data, MAXEXPR, "  leal -%d(%%ebp), %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", tmp_sym->location, (WORDSIZE*STLEN)-1);
								}
								else{
									char *cur = tmp2->data;
									char *end = cur + MAXEXPR;
									cur += snprintf(tmp2->data, MAXEXPR, "  leal (%%ebp), %%ecx\n");
									while(i > 1){
										cur += snprintf(cur, end-cur,"  leal (%%ecx), %%ecx\n");
										--i;
									}
									if(tmp_sym->type == INTEG)
										cur += snprintf(cur, end-cur, "  popl -%d(%%ecx)\n", tmp_sym->location);
									else
										snprintf(tmp2->data, MAXEXPR, "  leal -%d(%%ecx), %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", tmp_sym->location, (WORDSIZE*STLEN)-1);
		
								}
	


								tmp2->args = NULL;

								while(last_instruction->next != NULL)
									last_instruction = last_instruction-> next;
							}
						}
						else{
							tmp_sym = t->args;
							if(tmp_sym == NOARGS){
								argtypes = malloc(sizeof(enum type_));
								*argtypes = VOID;
							}
							else{
								while(tmp_sym != NULL){
									argcount++;
									tmp_sym = tmp_sym->next;
								}
								argtypes = malloc(sizeof(enum type_)*argcount);
								argcount = 0;
								tmp_sym = t->args;
								while(tmp_sym != NULL){
									argtypes[argcount] = tmp_sym->type;
									argcount++;
									tmp_sym = tmp_sym->next;
								}
								argtypes[argcount] = VOID;
							}
							tmp_sym = add_symbol(t->id, yystack.l_mark[-2].t, argtypes, STACK, local_table);


						}
						t = t->next;
						
					}

					if(first_instruction != NULL){
						last_instruction->next = NULL;
						tmp = current_block->list;
						if(tmp == NULL)
							current_block->list = first_instruction;
						else{
							while(tmp->next != NULL)
								tmp = tmp->next;
							tmp->next = first_instruction;

						}
					}
				yyval.d = yystack.l_mark[-1].d;
				current_args = NULL;
				}
break;
case 8:
#line 264 "parser.y"
	{yyval.t = INTEG;}
break;
case 9:
#line 265 "parser.y"
	{yyval.t = STRIN;}
break;
case 10:
#line 269 "parser.y"
	{yyval.d = yystack.l_mark[0].d;}
break;
case 11:
#line 270 "parser.y"
	{declar *t = yystack.l_mark[-2].d;
				while(t->next != NULL)
					t = t->next;
				t->next = yystack.l_mark[0].d;
				yyval.d = yystack.l_mark[-2].d;}
break;
case 12:
#line 278 "parser.y"
	{yyval.d = yystack.l_mark[0].d;}
break;
case 13:
#line 279 "parser.y"
	{
					

			
				}
break;
case 14:
#line 287 "parser.y"
	{
				int i = find_symbol(yystack.l_mark[0].a, &tmp_sym, local_table);
				if(tmp_sym != NULL){
					printf("symbol %s\n", yystack.l_mark[0].a);
					yyerror("symbol already declared");
					return -1;
				}
				
				yyval.d = malloc(sizeof(declar));
			 	strcpy(yyval.d->id, yystack.l_mark[0].a);
				yyval.d->set = NULL;
				yyval.d->args = NULL;
				yyval.d->next = NULL;
			}
break;
case 15:
#line 301 "parser.y"
	{
				int i = find_symbol(yystack.l_mark[-2].a, &tmp_sym, local_table);
				if(tmp_sym != NULL){
					printf("symbol %s\n", yystack.l_mark[-2].a);
					yyerror("symbol already declared");
					return -1;
				}
				
				yyval.d = malloc(sizeof(declar));
			 	strcpy(yyval.d->id, yystack.l_mark[-2].a);
				yyval.d->set = yystack.l_mark[0].e;
				yyval.d->args = NULL;
				yyval.d->next = NULL;
				}
break;
case 16:
#line 315 "parser.y"
	{yyval.d = yystack.l_mark[0].d;}
break;
case 17:
#line 319 "parser.y"
	{
					strcpy(current_function, yystack.l_mark[-2].a);
				
					yyval.d = malloc(sizeof(declar));
			 		strcpy(yyval.d->id, yystack.l_mark[-2].a);
					yyval.d->set = NULL;
					yyval.d->args = NOARGS;
					yyval.d->next = NULL;
	
				}
break;
case 18:
#line 329 "parser.y"
	{
					strcpy(current_function, yystack.l_mark[-3].a);
					current_args = yystack.l_mark[-1].s;

					
					yyval.d = malloc(sizeof(declar));
			 		strcpy(yyval.d->id, yystack.l_mark[-3].a);

					yyval.d->set = NULL;
					yyval.d->args = yystack.l_mark[-1].s;
					yyval.d->next = NULL;

	
				}
break;
case 19:
#line 346 "parser.y"
	{yyval.s = yystack.l_mark[0].s;}
break;
case 20:
#line 347 "parser.y"
	{
						tmp_sym = yystack.l_mark[-2].s;
						if(yystack.l_mark[-2].s != NULL){
							while(tmp_sym->next != NULL)
								tmp_sym = tmp_sym->next;
							tmp_sym->next= yystack.l_mark[0].s;
							yyval.s = yystack.l_mark[-2].s;
						}
						else yyval.s = yystack.l_mark[0].s;
						
					}
break;
case 21:
#line 360 "parser.y"
	{
					yyval.s = malloc(sizeof(symbol));
					yyval.s->type = yystack.l_mark[-1].t;
					strcpy(yyval.s->id, yystack.l_mark[0].a);
					yyval.s->next = NULL;
				}
break;
case 22:
#line 370 "parser.y"
	{}
break;
case 23:
#line 371 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 24:
#line 372 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 25:
#line 373 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 26:
#line 374 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 27:
#line 375 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 28:
#line 379 "parser.y"
	{
			tmp = current_block->list;
			if(tmp == NULL)
				current_block->list = yystack.l_mark[-1].e;
			else{
				while(tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = yystack.l_mark[-1].e;

			}
			yyval.e = yystack.l_mark[-1].e;
		}
break;
case 29:
#line 391 "parser.y"
	{
				tmp = current_block->list;
				if(tmp == NULL)
					current_block->list = yystack.l_mark[-1].e;
				else{
					while(tmp->next != NULL)
						tmp = tmp->next;
					tmp->next = yystack.l_mark[-1].e;

				}
				yyval.e = yystack.l_mark[-1].e;
			    }
break;
case 30:
#line 406 "parser.y"
	{ 
					int i = find_symbol(yystack.l_mark[-2].a, &tmp_sym, local_table);
					if(tmp_sym == NULL){
						yyerror("symbol not found");
						return -1;
					}
					if(tmp_sym->type != yystack.l_mark[0].e->ret_type){
						yyerror("conflicting types in assignment expression");
						return -1;
					}
					if(tmp_sym->args != NULL){
						yyerror("assigning value to function");
						return -1;
					}
					tmp = yystack.l_mark[0].e;
					while(tmp != NULL){
						tmp2 = tmp;
						tmp = tmp->next;			
					}
					tmp2->next = malloc(sizeof(expr));
					tmp2 = tmp2->next;
					tmp2->type = SET;
		
					tmp2->data = malloc(sizeof(char)*MAXEXPR);
					if(i == 0){
						if(tmp_sym->type == INTEG)
							snprintf(tmp2->data, MAXEXPR, "  popl %s%d(%%ebp)\n", (tmp_sym->scope == ARG? "":"-"),tmp_sym->location);
						else
							snprintf(tmp2->data, MAXEXPR, "  popl %%edx\n  pushl $%d\n  pushl %%edx\n  leal %s%d(%%ebp), %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", (WORDSIZE*STLEN), (tmp_sym->scope == ARG? "":"-"), tmp_sym->location, (WORDSIZE*STLEN)-1);
					}
					else{
						char *cur = tmp2->data;
						char *end = cur + MAXEXPR;
						cur += snprintf(tmp2->data, MAXEXPR, "  leal (%%ebp), %%ecx\n");
						while(i > 1){
							cur += snprintf(cur, end-cur, "  leal (%%ecx), %%ecx\n");
							--i;
						}
						if(tmp_sym->type == INTEG)
							cur += snprintf(cur, end-cur, "  popl %s%d(%%ecx)\n", (tmp_sym->scope == ARG? "":"-"),tmp_sym->location);
						else
							cur += snprintf(cur, MAXEXPR, "  leal %s%d(%%ecx), %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location, (WORDSIZE*STLEN)-1);
		
					}
	


					tmp2->args = NULL;
					tmp2->next = NULL;
					yyval.e = yystack.l_mark[0].e;
				}
break;
case 31:
#line 460 "parser.y"
	{
			yyval.e=yystack.l_mark[-1].e;
			}
break;
case 32:
#line 463 "parser.y"
	{}
break;
case 33:
#line 464 "parser.y"
	{yyval.e=yystack.l_mark[-1].e;}
break;
case 34:
#line 465 "parser.y"
	{}
break;
case 35:
#line 470 "parser.y"
	{


		local_table = create_table(local_table);
		if(f_def == NULL){
			f_def = malloc(sizeof(instr));
			f_def->prev = NULL;
			f_def->list = NULL;
			f_def->prev_ins = NULL;
			current_block = f_def;
			f_def->function = current_function;
			f_def->args = current_args;
			tmp_sym = current_args;
			while(tmp_sym != NULL && tmp_sym != NOARGS){
				add_symbol(tmp_sym->id,tmp_sym->type,NULL,ARG,local_table);
				
				tmp_sym = tmp_sym->next;

			}
			
		}
		else{
			tmp = current_block->list;
			if(tmp != NULL){			
				while(tmp->next != NULL){
					tmp = tmp->next;
				}
				tmp->next = malloc(sizeof(expr));
				tmp = tmp->next;
			}
			else tmp = malloc(sizeof(expr));
			tmp->type = BLOCK_JUMP;
			tmp->next = NULL;
			tmp->block = malloc(sizeof(instr));
			tmp->block->prev = current_block;
			tmp->block->function = current_block->function;
			current_block = tmp->block;
			current_block->prev_ins = tmp;
			current_block->list = NULL;
		}


	}
break;
case 36:
#line 516 "parser.y"
	{
		if(local_table == global_table){
			yyerror("No block to close");
			return -1;
		}
		current_block->stack_size = local_table->size;
		current_block = current_block->prev;
		local_table = destroy_table(local_table);


	 
	}
break;
case 37:
#line 531 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 38:
#line 532 "parser.y"
	{/*
			printf("returned\n");
					tmp = $1;
					while(tmp->next != NULL){
						tmp = tmp->next;
					}

					tmp->next = $2;
					$$ = $1;printf("returned\n");*/ yyval.e = yystack.l_mark[-1].e;
				}
break;
case 41:
#line 550 "parser.y"
	{yyval.e=yystack.l_mark[-1].e;}
break;
case 42:
#line 554 "parser.y"
	{printf("while loop\n");}
break;
case 43:
#line 555 "parser.y"
	{printf("do/while loop\n");}
break;
case 44:
#line 556 "parser.y"
	{printf("for loop ");}
break;
case 45:
#line 560 "parser.y"
	{
			

			tmp = yystack.l_mark[-1].e;
			while(tmp != NULL){
				tmp2 = tmp;
				tmp = tmp->next;			
			}
			tmp2->next = malloc(sizeof(expr));
			tmp2->next->type = RETURN;
			if(yystack.l_mark[-1].e != NULL){
				tmp2->next->data = malloc(sizeof(char)*MAXEXPR);
				snprintf(tmp2->next->data, MAXEXPR, "  popl %%eax\n");
			}
			else{
				tmp2->next->data = malloc(sizeof(char));
				tmp2->next->data[0] = '\0';
			}
			tmp2->next->args = NULL;				
			tmp2->next->next = NULL;
			tmp = current_block->list;
			if(tmp == NULL)
				current_block->list = yystack.l_mark[-1].e;
			else{
				while(tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = yystack.l_mark[-1].e;

			}
			
	
			}
break;
case 46:
#line 595 "parser.y"
	{printf("comparison\n");}
break;
case 47:
#line 599 "parser.y"
	{yyval.entier=EGA;}
break;
case 48:
#line 600 "parser.y"
	{yyval.entier=DIF;}
break;
case 49:
#line 601 "parser.y"
	{yyval.entier=INFE;}
break;
case 50:
#line 602 "parser.y"
	{yyval.entier=SU;}
break;
case 51:
#line 603 "parser.y"
	{yyval.entier=INFEQUA;}
break;
case 52:
#line 604 "parser.y"
	{yyval.entier=SUPEQUA;}
break;
case 53:
#line 608 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 54:
#line 609 "parser.y"
	{
								if(yystack.l_mark[-2].e->ret_type != INTEG || yystack.l_mark[0].e->ret_type != INTEG){
								 	yyerror("left shift requires two integer values");
									return -1;
								}
								tmp = yystack.l_mark[0].e;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = yystack.l_mark[-2].e;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = LSHIFT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								yyval.e = yystack.l_mark[0].e;

							}
break;
case 55:
#line 631 "parser.y"
	{
								if(yystack.l_mark[-2].e->ret_type != INTEG || yystack.l_mark[0].e->ret_type != INTEG){
								 	yyerror("right shift requires two integer values");
									return -1;
								}
								tmp = yystack.l_mark[0].e;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = yystack.l_mark[-2].e;
								while(tmp->next != NULL)
									tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = RSHIFT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								yyval.e = yystack.l_mark[0].e;

							}
break;
case 56:
#line 655 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 57:
#line 656 "parser.y"
	{
								
								tmp = yystack.l_mark[0].e;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = yystack.l_mark[-2].e;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								if(yystack.l_mark[-2].e->ret_type == INTEG){
									if(yystack.l_mark[0].e->ret_type == INTEG)
										tmp->next->type = ADDII;
									else{
										tmp->next->type = ADDIS;
										yystack.l_mark[-2].e->ret_type = STRIN;
									}
									
								}
								else{
									if(yystack.l_mark[0].e->ret_type == STRIN)
										tmp->next->type = ADDSS;
									else{
										tmp->next->type = ADDSI;
										yystack.l_mark[0].e->ret_type = STRIN;
									}
								}
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								yyval.e = yystack.l_mark[0].e;

							}
break;
case 58:
#line 691 "parser.y"
	{
								if(yystack.l_mark[-2].e->ret_type != INTEG || yystack.l_mark[0].e->ret_type != INTEG){
								 	yyerror("subtraction requires two integer values");
									return -1;
								}
								tmp = yystack.l_mark[0].e;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = yystack.l_mark[-2].e;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = SUB;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								yyval.e = yystack.l_mark[0].e;

							}
break;
case 59:
#line 715 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 60:
#line 716 "parser.y"
	{
								if(yystack.l_mark[-2].e->ret_type != INTEG || yystack.l_mark[0].e->ret_type != INTEG){
								 	yyerror("multiplication requires two integer values");
									return -1;
								}
								tmp = yystack.l_mark[0].e;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = yystack.l_mark[-2].e;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = MULT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								yyval.e = yystack.l_mark[0].e;

							}
break;
case 61:
#line 738 "parser.y"
	{
								if(yystack.l_mark[-2].e->ret_type != INTEG || yystack.l_mark[0].e->ret_type != INTEG){
								 	yyerror("division requires two integer values");
									return -1;
								}
								tmp = yystack.l_mark[0].e;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = yystack.l_mark[-2].e;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = DIV;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								yyval.e = yystack.l_mark[0].e;

							}
break;
case 62:
#line 760 "parser.y"
	{
								if(yystack.l_mark[-2].e->ret_type != INTEG || yystack.l_mark[0].e->ret_type != INTEG){
								 	yyerror("modulo requires two integer values");
									return -1;
								}
								tmp = yystack.l_mark[0].e;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = yystack.l_mark[-2].e;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = MOD;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								yyval.e = yystack.l_mark[0].e;

							}
break;
case 63:
#line 786 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 64:
#line 787 "parser.y"
	{
			 	yyval.e=yystack.l_mark[0].e;
				if(yystack.l_mark[0].e->ret_type != INTEG){
					yyerror("minus requires an int");
					return -1;
				}
				tmp = yystack.l_mark[0].e;
			 	tmp2 = tmp->next;
				while(tmp2 != NULL){
					tmp = tmp2;
					tmp2 = tmp2->next;
			 	}
				tmp->next = malloc(sizeof(expr));
				tmp = tmp->next;
				tmp->type = INTEG;
				tmp->ret_type = INTEG;
				tmp->args = NULL;
				tmp->data = malloc(sizeof(char)*MAXEXPR);
				snprintf(tmp->data, MAXEXPR, "  pushl $0\n");
				
				tmp->next = malloc(sizeof(expr));
				tmp->next->type = SUB;
				tmp->next->data = NULL;
				tmp->next->args = NULL;	
			 					
				tmp->next->next = NULL;
				}
break;
case 65:
#line 817 "parser.y"
	{yyval.e=yystack.l_mark[0].e;}
break;
case 66:
#line 818 "parser.y"
	{

						int i = find_symbol(yystack.l_mark[-3].a, &tmp_sym, local_table);
						if(tmp_sym == NULL){
							yyerror("symbol not found");
							return -1;
						}
						yyval.e = malloc(sizeof(expr));
						if(tmp_sym->args == NULL){
							yyerror("expected function call");
							return -1;
						}
						yyval.e->type = tmp_sym->type;
						yyval.e->data = yystack.l_mark[-3].a;
						yyval.e->next = NULL;
						yyval.e->args = yystack.l_mark[-1].e;
/*
						tmp = $$->args;
						i = 0;

						while(tmp!= NULL || tmp_sym->args[i] != VOID){
							if(tmp== NULL || tmp_sym->args[i] == VOID || tmp->type != tmp_sym->args[i]){
								yyerror("function call types do not match function declaration");
								return -1;
							}
							tmp = tmp->next;
							++i;
						}
*/					}
break;
case 67:
#line 847 "parser.y"
	{
						int i = find_symbol(yystack.l_mark[-2].a, &tmp_sym, local_table);
						if(tmp_sym == NULL){
							yyerror("symbol not found");
							return -1;
						}
						yyval.e = malloc(sizeof(expr));
						if(tmp_sym->args == NULL){
							yyerror("expected function call");
							return -1;
						}
						if(tmp_sym->args[1] != VOID){
							yyerror("function call types do not match function declaration");
							return -1;
						}
						yyval.e->type = tmp_sym->type;
						yyval.e->data = yystack.l_mark[-2].a;
						yyval.e->next = NULL;
						yyval.e->args = NOARG;
					}
break;
case 68:
#line 870 "parser.y"
	{yyval.e = yystack.l_mark[0].e;}
break;
case 69:
#line 871 "parser.y"
	{tmp = yystack.l_mark[0].e;
			 while(tmp->next != NULL)
				tmp = tmp->next;
			tmp->next= yystack.l_mark[-2].e;
			yyval.e = yystack.l_mark[0].e;}
break;
case 70:
#line 879 "parser.y"
	{

	int i = find_symbol(yystack.l_mark[0].a, &tmp_sym, local_table);
	if(tmp_sym == NULL){
		yyerror("symbol not found");
		return -1;
	}
	yyval.e = malloc(sizeof(expr));
	yyval.e->type = tmp_sym->type;
	yyval.e->ret_type = tmp_sym->type;
	if(tmp_sym->args == NULL){
		
		yyval.e->data = malloc(sizeof(char)*MAXEXPR);

		if(i == 0)
			if(tmp_sym->type == STRIN)
				snprintf(yyval.e->data, MAXEXPR, "  leal %s%d(%%ebp), %%eax\n  pushl %%eax\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
			else snprintf(yyval.e->data, MAXEXPR, "  pushl %s%d(%%ebp)\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
		else{
			char *cur = yyval.e->data;
			char *end = cur + MAXEXPR;
			cur += snprintf(yyval.e->data, MAXEXPR, "  leal (%%ebp), %%ecx\n");
			while(i > 1){
				cur += snprintf(cur, end-cur,"  leal (%%ecx), %%ecx\n");
				--i;
			}
			if(tmp_sym->type == STRIN)
				cur += snprintf(yyval.e->data, MAXEXPR, "  leal %s%d(%%ecx), %%eax\n  pushl %%eax\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
			else cur += snprintf(cur, end-cur, "  pushl %s%d(%%ecx)\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
		
		}
		yyval.e->args = NULL;
	}

	else yyval.e->data = yystack.l_mark[0].a;
	yyval.e->next = NULL; 
	}
break;
case 71:
#line 916 "parser.y"
	{
		yyval.e = malloc(sizeof(expr));
		yyval.e->type = INTEG;
		yyval.e->ret_type = INTEG;
		yyval.e->args = NULL;
		yyval.e->data = malloc(sizeof(char)*MAXEXPR);
		snprintf(yyval.e->data, MAXEXPR, "  pushl $%d\n", yystack.l_mark[0].fn);
		yyval.e->next = NULL;
		
		}
break;
case 72:
#line 926 "parser.y"
	{
		yyval.e = malloc(sizeof(expr));
		yyval.e->data = malloc(sizeof(char)*MAXEXPR);
		yyval.e->type = STRIN;
		yyval.e->ret_type = STRIN;
		yyval.e->args = NULL;
		glb_strings[str_counter] = yystack.l_mark[0].a;
		snprintf(yyval.e->data, MAXEXPR, "  pushl $.s%d\n", str_counter);
		++str_counter;
		yyval.e->next = NULL;
		}
break;
case 73:
#line 937 "parser.y"
	{yyval.e = yystack.l_mark[-1].e;}
break;
#line 2008 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
