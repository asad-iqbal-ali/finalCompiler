/* A Bison parser, made by GNU Bison 2.5.1.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

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



/* Line 268 of yacc.c  */
#line 111 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     STRING = 259,
     CONST_INT = 260,
     CONST_STRING = 261,
     IDENT = 262,
     EXTERN = 263,
     IF = 264,
     ELSE = 265,
     WHILE = 266,
     DO = 267,
     RETURN = 268,
     FOR = 269,
     THEN = 270,
     assignment = 271,
     INF = 272,
     EGAL = 273,
     SUP = 274,
     INFEQUAL = 275,
     SUPEQUAL = 276,
     DIFF = 277,
     PLUS = 278,
     MINUS = 279,
     MULTI = 280,
     DIV = 281,
     SHIFTRIGHT = 282,
     SHIFTLEFT = 283,
     MODULO = 284
   };
#endif
/* Tokens.  */
#define INT 258
#define STRING 259
#define CONST_INT 260
#define CONST_STRING 261
#define IDENT 262
#define EXTERN 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define DO 267
#define RETURN 268
#define FOR 269
#define THEN 270
#define assignment 271
#define INF 272
#define EGAL 273
#define SUP 274
#define INFEQUAL 275
#define SUPEQUAL 276
#define DIFF 277
#define PLUS 278
#define MINUS 279
#define MULTI 280
#define DIV 281
#define SHIFTRIGHT 282
#define SHIFTLEFT 283
#define MODULO 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 295 of yacc.c  */
#line 39 "parser.y"

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



/* Line 295 of yacc.c  */
#line 232 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 345 of yacc.c  */
#line 244 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,     2,     2,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    19,    23,
      25,    27,    29,    33,    35,    38,    40,    44,    46,    50,
      55,    57,    61,    64,    66,    68,    70,    72,    74,    76,
      79,    82,    86,    91,    95,    99,   102,   104,   106,   108,
     111,   114,   119,   124,   130,   137,   147,   151,   155,   157,
     159,   161,   163,   165,   167,   169,   173,   177,   179,   183,
     187,   189,   193,   197,   201,   203,   206,   208,   213,   217,
     219,   223,   225,   227,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    37,    38,    -1,    40,    -1,
       8,    40,    -1,    39,    -1,    41,    45,    51,    -1,    41,
      42,    30,    -1,     3,    -1,     4,    -1,    44,    -1,    42,
      31,    44,    -1,    40,    -1,    43,    40,    -1,     7,    -1,
       7,    16,    61,    -1,    45,    -1,     7,    32,    33,    -1,
       7,    32,    46,    33,    -1,    47,    -1,    46,    31,    47,
      -1,    41,     7,    -1,    30,    -1,    51,    -1,    49,    -1,
      57,    -1,    55,    -1,    58,    -1,    61,    30,    -1,    50,
      30,    -1,     7,    16,    61,    -1,    52,    43,    54,    53,
      -1,    52,    43,    53,    -1,    52,    54,    53,    -1,    52,
      53,    -1,    34,    -1,    35,    -1,    48,    -1,    54,    48,
      -1,    56,    48,    -1,    56,    48,    10,    48,    -1,     9,
      32,    59,    33,    -1,    11,    32,    59,    33,    48,    -1,
      12,    48,    11,    32,    59,    33,    -1,    14,    32,    50,
      30,    59,    30,    50,    33,    48,    -1,    13,    61,    30,
      -1,    61,    60,    61,    -1,    18,    -1,    22,    -1,    17,
      -1,    19,    -1,    20,    -1,    21,    -1,    62,    -1,    61,
      28,    62,    -1,    61,    27,    62,    -1,    63,    -1,    62,
      23,    63,    -1,    62,    24,    63,    -1,    64,    -1,    63,
      25,    64,    -1,    63,    26,    64,    -1,    63,    29,    64,
      -1,    65,    -1,    24,    64,    -1,    67,    -1,     7,    32,
      66,    33,    -1,     7,    32,    33,    -1,    61,    -1,    66,
      31,    61,    -1,     7,    -1,     5,    -1,     6,    -1,    32,
      61,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,    99,   103,   104,   113,   117,   153,   264,
     265,   269,   270,   278,   279,   287,   301,   315,   319,   329,
     346,   347,   360,   370,   371,   372,   373,   374,   375,   379,
     391,   406,   460,   463,   464,   465,   470,   519,   534,   535,
     548,   549,   553,   557,   558,   559,   563,   598,   602,   603,
     604,   605,   606,   607,   611,   612,   634,   658,   659,   694,
     718,   719,   741,   763,   789,   790,   820,   821,   850,   873,
     874,   882,   919,   929,   940
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "CONST_INT",
  "CONST_STRING", "IDENT", "EXTERN", "IF", "ELSE", "WHILE", "DO", "RETURN",
  "FOR", "THEN", "assignment", "INF", "EGAL", "SUP", "INFEQUAL",
  "SUPEQUAL", "DIFF", "PLUS", "MINUS", "MULTI", "DIV", "SHIFTRIGHT",
  "SHIFTLEFT", "MODULO", "';'", "','", "'('", "')'", "'{'", "'}'",
  "$accept", "program", "external_declaration", "function_definition",
  "declaration", "type", "declarator_list", "declaration_list",
  "declarator", "function_declarator", "parameter_list",
  "parameter_declaration", "instruction", "expression_instruction",
  "assignment_expression", "compound_instruction", "block_start",
  "block_end", "instruction_list", "select_instruction",
  "cond_instruction", "iteration_instruction", "jump_instruction",
  "condition", "comparison_operator", "expression", "expression_additive",
  "expression_multiplicative", "unary_expression", "expression_postfixee",
  "argument_expression_list", "primary_expression", YY_NULL
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
      59,    44,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    39,    40,    41,
      41,    42,    42,    43,    43,    44,    44,    44,    45,    45,
      46,    46,    47,    48,    48,    48,    48,    48,    48,    49,
      49,    50,    51,    51,    51,    51,    52,    53,    54,    54,
      55,    55,    56,    57,    57,    57,    58,    59,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     3,     3,     1,
       1,     1,     3,     1,     2,     1,     3,     1,     3,     4,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     4,     3,     3,     2,     1,     1,     1,     2,
       2,     4,     4,     5,     6,     9,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     1,     4,     3,     1,
       3,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     0,     2,     6,     4,     0,     5,
       0,     1,     3,    15,     0,    11,    17,    17,     0,     0,
       8,     0,    36,     7,     0,    72,    73,    71,     0,     0,
      16,    54,    57,    60,    64,    66,    18,     0,     0,    20,
      12,    71,     0,     0,     0,     0,     0,    23,    37,    13,
       0,    38,    25,     0,    24,    35,     0,    27,     0,    26,
      28,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,    19,     0,     0,     0,     0,     0,
       0,    14,    33,     0,    30,    39,    34,    40,    29,    68,
      69,     0,    74,    56,    55,    58,    59,    61,    62,    63,
      21,    31,     0,     0,     0,     0,    46,     0,     0,    32,
       0,     0,    67,    42,    50,    48,    51,    52,    53,    49,
       0,     0,     0,     0,    41,    70,    47,    43,     0,     0,
      44,     0,     0,     0,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    10,    14,    50,    15,    17,
      38,    39,    51,    52,    53,    54,    24,    55,    56,    57,
      58,    59,    60,   102,   120,    61,    31,    32,    33,    34,
      91,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
      69,   -78,   -78,    46,    26,   -78,   -78,   -78,    12,   -78,
      12,   -78,   -78,    -4,    25,   -78,   -11,   -78,    11,     6,
     -78,    12,   -78,   -78,    57,   -78,   -78,    -1,    11,    11,
      71,    77,    54,   -78,   -78,   -78,   -78,    30,    -9,   -78,
     -78,     4,    10,    13,   115,    11,    33,   -78,   -78,   -78,
      57,   -78,   -78,    52,   -78,   -78,   101,   -78,   115,   -78,
     -78,    58,   135,   -78,     5,    11,    11,    11,    11,    11,
      11,    11,   -78,    46,   -78,    11,    11,    11,    73,    67,
      89,   -78,   -78,   101,   -78,   -78,   -78,    93,   -78,   -78,
      71,    43,   -78,    77,    77,    54,    54,   -78,   -78,   -78,
     -78,    71,    76,   133,    78,    86,   -78,   103,   100,   -78,
     115,    11,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
      11,   115,    11,    11,   -78,    71,    71,   -78,    90,   102,
     -78,    89,   110,   115,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   130,   -78,     1,     2,   -78,   -78,   123,   138,
     -78,    75,   -43,   -78,   -77,   140,   -78,   -42,   107,   -78,
     -78,   -78,   -78,   -70,   -78,   -18,    51,    70,   -23,   -78,
     -78,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    78,     8,   108,     9,    63,     8,   104,    82,     1,
       2,    64,    18,    85,    86,    87,    25,    26,    27,    13,
      75,    37,    73,    22,    74,    49,    11,    79,    19,     1,
       2,    62,    65,    66,     3,    28,    62,    72,    92,    36,
      85,   109,    76,    29,    90,    77,    97,    98,    99,     1,
       2,    81,   128,   129,   132,    20,    21,   101,   103,   103,
       1,     2,    25,    26,    41,    80,    42,   124,    43,    44,
      45,    46,     1,     2,   111,    37,   112,     3,   127,    69,
      70,    28,    84,    71,   105,    65,    66,    47,    88,    29,
     134,    22,    48,   125,    65,    66,   107,   106,    65,    66,
      67,    68,   126,   110,   103,   103,    25,    26,    41,   113,
      42,   121,    43,    44,    45,    46,    93,    94,   122,    75,
      25,    26,    41,   130,    42,    28,    43,    44,    45,    46,
     123,    47,   131,    29,    12,    22,    48,    95,    96,    28,
      25,    26,    27,   133,    40,    47,    16,    29,   100,    22,
     114,   115,   116,   117,   118,   119,    23,    83,     0,    28,
      65,    66,     0,     0,     0,     0,     0,    29,    89
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-78))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      18,    44,     0,    80,     3,    28,     4,    77,    50,     3,
       4,    29,    16,    56,    56,    58,     5,     6,     7,     7,
      16,    19,    31,    34,    33,    24,     0,    45,    32,     3,
       4,    32,    27,    28,     8,    24,    32,     7,    33,    33,
      83,    83,    32,    32,    62,    32,    69,    70,    71,     3,
       4,    50,   122,   123,   131,    30,    31,    75,    76,    77,
       3,     4,     5,     6,     7,    32,     9,   110,    11,    12,
      13,    14,     3,     4,    31,    73,    33,     8,   121,    25,
      26,    24,    30,    29,    11,    27,    28,    30,    30,    32,
     133,    34,    35,   111,    27,    28,     7,    30,    27,    28,
      23,    24,   120,    10,   122,   123,     5,     6,     7,    33,
       9,    33,    11,    12,    13,    14,    65,    66,    32,    16,
       5,     6,     7,    33,     9,    24,    11,    12,    13,    14,
      30,    30,    30,    32,     4,    34,    35,    67,    68,    24,
       5,     6,     7,    33,    21,    30,     8,    32,    73,    34,
      17,    18,    19,    20,    21,    22,    16,    50,    -1,    24,
      27,    28,    -1,    -1,    -1,    -1,    -1,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     8,    37,    38,    39,    40,    41,    40,
      41,     0,    38,     7,    42,    44,    45,    45,    16,    32,
      30,    31,    34,    51,    52,     5,     6,     7,    24,    32,
      61,    62,    63,    64,    65,    67,    33,    41,    46,    47,
      44,     7,     9,    11,    12,    13,    14,    30,    35,    40,
      43,    48,    49,    50,    51,    53,    54,    55,    56,    57,
      58,    61,    32,    64,    61,    27,    28,    23,    24,    25,
      26,    29,     7,    31,    33,    16,    32,    32,    48,    61,
      32,    40,    53,    54,    30,    48,    53,    48,    30,    33,
      61,    66,    33,    62,    62,    63,    63,    64,    64,    64,
      47,    61,    59,    61,    59,    11,    30,     7,    50,    53,
      10,    31,    33,    33,    17,    18,    19,    20,    21,    22,
      60,    33,    32,    30,    48,    61,    61,    48,    59,    59,
      33,    30,    50,    33,    48
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 5:

/* Line 1810 of yacc.c  */
#line 104 "parser.y"
    {
			declar *t = (yyvsp[(2) - (2)].d);
			int i;
			while(t != NULL){
				i = find_symbol((yyvsp[(2) - (2)].d)->id, &tmp_sym, local_table);
				tmp_sym->scope = EXT;
				t = t->next;
			}
			}
    break;

  case 7:

/* Line 1810 of yacc.c  */
#line 117 "parser.y"
    {		declar *t = (yyvsp[(2) - (3)].d);
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
							tmp_sym = add_symbol(t->id, (yyvsp[(1) - (3)].t), argtypes, GLOBAL, local_table);
						
						print_instructions(f_def);
						f_def = NULL;
						current_block = NULL;
						current_args = NULL;

						}
    break;

  case 8:

/* Line 1810 of yacc.c  */
#line 153 "parser.y"
    {
					declar *t = (yyvsp[(2) - (3)].d);
					int argcount = 1;
					enum type_ *argtypes = NULL;
					expr *last_instruction = NULL;
					expr *first_instruction = NULL;

					while(t != NULL){
						if(t->args == NULL){
							tmp_sym = add_symbol(t->id, (yyvsp[(1) - (3)].t), NULL, STACK, local_table);
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
							tmp_sym = add_symbol(t->id, (yyvsp[(1) - (3)].t), argtypes, STACK, local_table);


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
				(yyval.d) = (yyvsp[(2) - (3)].d);
				current_args = NULL;
				}
    break;

  case 9:

/* Line 1810 of yacc.c  */
#line 264 "parser.y"
    {(yyval.t) = INTEG;}
    break;

  case 10:

/* Line 1810 of yacc.c  */
#line 265 "parser.y"
    {(yyval.t) = STRIN;}
    break;

  case 11:

/* Line 1810 of yacc.c  */
#line 269 "parser.y"
    {(yyval.d) = (yyvsp[(1) - (1)].d);}
    break;

  case 12:

/* Line 1810 of yacc.c  */
#line 270 "parser.y"
    {declar *t = (yyvsp[(1) - (3)].d);
				while(t->next != NULL)
					t = t->next;
				t->next = (yyvsp[(3) - (3)].d);
				(yyval.d) = (yyvsp[(1) - (3)].d);}
    break;

  case 13:

/* Line 1810 of yacc.c  */
#line 278 "parser.y"
    {(yyval.d) = (yyvsp[(1) - (1)].d);}
    break;

  case 14:

/* Line 1810 of yacc.c  */
#line 279 "parser.y"
    {
					

			
				}
    break;

  case 15:

/* Line 1810 of yacc.c  */
#line 287 "parser.y"
    {
				int i = find_symbol((yyvsp[(1) - (1)].a), &tmp_sym, local_table);
				if(tmp_sym != NULL){
					printf("symbol %s\n", (yyvsp[(1) - (1)].a));
					yyerror("symbol already declared");
					return -1;
				}
				
				(yyval.d) = malloc(sizeof(declar));
			 	strcpy((yyval.d)->id, (yyvsp[(1) - (1)].a));
				(yyval.d)->set = NULL;
				(yyval.d)->args = NULL;
				(yyval.d)->next = NULL;
			}
    break;

  case 16:

/* Line 1810 of yacc.c  */
#line 301 "parser.y"
    {
				int i = find_symbol((yyvsp[(1) - (3)].a), &tmp_sym, local_table);
				if(tmp_sym != NULL){
					printf("symbol %s\n", (yyvsp[(1) - (3)].a));
					yyerror("symbol already declared");
					return -1;
				}
				
				(yyval.d) = malloc(sizeof(declar));
			 	strcpy((yyval.d)->id, (yyvsp[(1) - (3)].a));
				(yyval.d)->set = (yyvsp[(3) - (3)].e);
				(yyval.d)->args = NULL;
				(yyval.d)->next = NULL;
				}
    break;

  case 17:

/* Line 1810 of yacc.c  */
#line 315 "parser.y"
    {(yyval.d) = (yyvsp[(1) - (1)].d);}
    break;

  case 18:

/* Line 1810 of yacc.c  */
#line 319 "parser.y"
    {
					strcpy(current_function, (yyvsp[(1) - (3)].a));
				
					(yyval.d) = malloc(sizeof(declar));
			 		strcpy((yyval.d)->id, (yyvsp[(1) - (3)].a));
					(yyval.d)->set = NULL;
					(yyval.d)->args = NOARGS;
					(yyval.d)->next = NULL;
	
				}
    break;

  case 19:

/* Line 1810 of yacc.c  */
#line 329 "parser.y"
    {
					strcpy(current_function, (yyvsp[(1) - (4)].a));
					current_args = (yyvsp[(3) - (4)].s);

					
					(yyval.d) = malloc(sizeof(declar));
			 		strcpy((yyval.d)->id, (yyvsp[(1) - (4)].a));

					(yyval.d)->set = NULL;
					(yyval.d)->args = (yyvsp[(3) - (4)].s);
					(yyval.d)->next = NULL;

	
				}
    break;

  case 20:

/* Line 1810 of yacc.c  */
#line 346 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 21:

/* Line 1810 of yacc.c  */
#line 347 "parser.y"
    {
						tmp_sym = (yyvsp[(1) - (3)].s);
						if((yyvsp[(1) - (3)].s) != NULL){
							while(tmp_sym->next != NULL)
								tmp_sym = tmp_sym->next;
							tmp_sym->next= (yyvsp[(3) - (3)].s);
							(yyval.s) = (yyvsp[(1) - (3)].s);
						}
						else (yyval.s) = (yyvsp[(3) - (3)].s);
						
					}
    break;

  case 22:

/* Line 1810 of yacc.c  */
#line 360 "parser.y"
    {
					(yyval.s) = malloc(sizeof(symbol));
					(yyval.s)->type = (yyvsp[(1) - (2)].t);
					strcpy((yyval.s)->id, (yyvsp[(2) - (2)].a));
					(yyval.s)->next = NULL;
				}
    break;

  case 23:

/* Line 1810 of yacc.c  */
#line 370 "parser.y"
    {}
    break;

  case 24:

/* Line 1810 of yacc.c  */
#line 371 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 25:

/* Line 1810 of yacc.c  */
#line 372 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 26:

/* Line 1810 of yacc.c  */
#line 373 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 27:

/* Line 1810 of yacc.c  */
#line 374 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 28:

/* Line 1810 of yacc.c  */
#line 375 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 29:

/* Line 1810 of yacc.c  */
#line 379 "parser.y"
    {
			tmp = current_block->list;
			if(tmp == NULL)
				current_block->list = (yyvsp[(1) - (2)].e);
			else{
				while(tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = (yyvsp[(1) - (2)].e);

			}
			(yyval.e) = (yyvsp[(1) - (2)].e);
		}
    break;

  case 30:

/* Line 1810 of yacc.c  */
#line 391 "parser.y"
    {
				tmp = current_block->list;
				if(tmp == NULL)
					current_block->list = (yyvsp[(1) - (2)].e);
				else{
					while(tmp->next != NULL)
						tmp = tmp->next;
					tmp->next = (yyvsp[(1) - (2)].e);

				}
				(yyval.e) = (yyvsp[(1) - (2)].e);
			    }
    break;

  case 31:

/* Line 1810 of yacc.c  */
#line 406 "parser.y"
    { 
					int i = find_symbol((yyvsp[(1) - (3)].a), &tmp_sym, local_table);
					if(tmp_sym == NULL){
						yyerror("symbol not found");
						return -1;
					}
					if(tmp_sym->type != (yyvsp[(3) - (3)].e)->ret_type){
						yyerror("conflicting types in assignment expression");
						return -1;
					}
					if(tmp_sym->args != NULL){
						yyerror("assigning value to function");
						return -1;
					}
					tmp = (yyvsp[(3) - (3)].e);
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
					(yyval.e) = (yyvsp[(3) - (3)].e);
				}
    break;

  case 32:

/* Line 1810 of yacc.c  */
#line 460 "parser.y"
    {
			(yyval.e)=(yyvsp[(3) - (4)].e);
			}
    break;

  case 33:

/* Line 1810 of yacc.c  */
#line 463 "parser.y"
    {}
    break;

  case 34:

/* Line 1810 of yacc.c  */
#line 464 "parser.y"
    {(yyval.e)=(yyvsp[(2) - (3)].e);}
    break;

  case 35:

/* Line 1810 of yacc.c  */
#line 465 "parser.y"
    {}
    break;

  case 36:

/* Line 1810 of yacc.c  */
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
			else {
				current_block->list = malloc(sizeof(expr));
				tmp = current_block->list;
			}
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

  case 37:

/* Line 1810 of yacc.c  */
#line 519 "parser.y"
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

  case 38:

/* Line 1810 of yacc.c  */
#line 534 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 39:

/* Line 1810 of yacc.c  */
#line 535 "parser.y"
    {/*
			printf("returned\n");
					tmp = $1;
					while(tmp->next != NULL){
						tmp = tmp->next;
					}

					tmp->next = $2;
					$$ = $1;printf("returned\n");*/ (yyval.e) = (yyvsp[(1) - (2)].e);
				}
    break;

  case 42:

/* Line 1810 of yacc.c  */
#line 553 "parser.y"
    {(yyval.e)=(yyvsp[(3) - (4)].e);}
    break;

  case 43:

/* Line 1810 of yacc.c  */
#line 557 "parser.y"
    {printf("while loop\n");}
    break;

  case 44:

/* Line 1810 of yacc.c  */
#line 558 "parser.y"
    {printf("do/while loop\n");}
    break;

  case 45:

/* Line 1810 of yacc.c  */
#line 559 "parser.y"
    {printf("for loop ");}
    break;

  case 46:

/* Line 1810 of yacc.c  */
#line 563 "parser.y"
    {
			

			tmp = (yyvsp[(2) - (3)].e);
			while(tmp != NULL){
				tmp2 = tmp;
				tmp = tmp->next;			
			}
			tmp2->next = malloc(sizeof(expr));
			tmp2->next->type = RET;
			if((yyvsp[(2) - (3)].e) != NULL){
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
				current_block->list = (yyvsp[(2) - (3)].e);
			else{
				while(tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = (yyvsp[(2) - (3)].e);

			}
			
	
			}
    break;

  case 47:

/* Line 1810 of yacc.c  */
#line 598 "parser.y"
    {printf("comparison\n");}
    break;

  case 48:

/* Line 1810 of yacc.c  */
#line 602 "parser.y"
    {(yyval.entier)=EGA;}
    break;

  case 49:

/* Line 1810 of yacc.c  */
#line 603 "parser.y"
    {(yyval.entier)=DIF;}
    break;

  case 50:

/* Line 1810 of yacc.c  */
#line 604 "parser.y"
    {(yyval.entier)=INFE;}
    break;

  case 51:

/* Line 1810 of yacc.c  */
#line 605 "parser.y"
    {(yyval.entier)=SU;}
    break;

  case 52:

/* Line 1810 of yacc.c  */
#line 606 "parser.y"
    {(yyval.entier)=INFEQUA;}
    break;

  case 53:

/* Line 1810 of yacc.c  */
#line 607 "parser.y"
    {(yyval.entier)=SUPEQUA;}
    break;

  case 54:

/* Line 1810 of yacc.c  */
#line 611 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 55:

/* Line 1810 of yacc.c  */
#line 612 "parser.y"
    {
								if((yyvsp[(1) - (3)].e)->ret_type != INTEG || (yyvsp[(3) - (3)].e)->ret_type != INTEG){
								 	yyerror("left shift requires two integer values");
									return -1;
								}
								tmp = (yyvsp[(3) - (3)].e);
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = (yyvsp[(1) - (3)].e);
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = LSHIFT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								(yyval.e) = (yyvsp[(3) - (3)].e);

							}
    break;

  case 56:

/* Line 1810 of yacc.c  */
#line 634 "parser.y"
    {
								if((yyvsp[(1) - (3)].e)->ret_type != INTEG || (yyvsp[(3) - (3)].e)->ret_type != INTEG){
								 	yyerror("right shift requires two integer values");
									return -1;
								}
								tmp = (yyvsp[(3) - (3)].e);
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = (yyvsp[(1) - (3)].e);
								while(tmp->next != NULL)
									tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = RSHIFT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								(yyval.e) = (yyvsp[(3) - (3)].e);

							}
    break;

  case 57:

/* Line 1810 of yacc.c  */
#line 658 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 58:

/* Line 1810 of yacc.c  */
#line 659 "parser.y"
    {
								
								tmp = (yyvsp[(3) - (3)].e);
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = (yyvsp[(1) - (3)].e);
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								if((yyvsp[(1) - (3)].e)->ret_type == INTEG){
									if((yyvsp[(3) - (3)].e)->ret_type == INTEG)
										tmp->next->type = ADDII;
									else{
										tmp->next->type = ADDIS;
										(yyvsp[(1) - (3)].e)->ret_type = STRIN;
									}
									
								}
								else{
									if((yyvsp[(3) - (3)].e)->ret_type == STRIN)
										tmp->next->type = ADDSS;
									else{
										tmp->next->type = ADDSI;
										(yyvsp[(3) - (3)].e)->ret_type = STRIN;
									}
								}
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								(yyval.e) = (yyvsp[(3) - (3)].e);

							}
    break;

  case 59:

/* Line 1810 of yacc.c  */
#line 694 "parser.y"
    {
								if((yyvsp[(1) - (3)].e)->ret_type != INTEG || (yyvsp[(3) - (3)].e)->ret_type != INTEG){
								 	yyerror("subtraction requires two integer values");
									return -1;
								}
								tmp = (yyvsp[(3) - (3)].e);
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = (yyvsp[(1) - (3)].e);
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = SUB;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								(yyval.e) = (yyvsp[(3) - (3)].e);

							}
    break;

  case 60:

/* Line 1810 of yacc.c  */
#line 718 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 61:

/* Line 1810 of yacc.c  */
#line 719 "parser.y"
    {
								if((yyvsp[(1) - (3)].e)->ret_type != INTEG || (yyvsp[(3) - (3)].e)->ret_type != INTEG){
								 	yyerror("multiplication requires two integer values");
									return -1;
								}
								tmp = (yyvsp[(3) - (3)].e);
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = (yyvsp[(1) - (3)].e);
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = MULT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								(yyval.e) = (yyvsp[(3) - (3)].e);

							}
    break;

  case 62:

/* Line 1810 of yacc.c  */
#line 741 "parser.y"
    {
								if((yyvsp[(1) - (3)].e)->ret_type != INTEG || (yyvsp[(3) - (3)].e)->ret_type != INTEG){
								 	yyerror("division requires two integer values");
									return -1;
								}
								tmp = (yyvsp[(3) - (3)].e);
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = (yyvsp[(1) - (3)].e);
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = DIVI;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								(yyval.e) = (yyvsp[(3) - (3)].e);

							}
    break;

  case 63:

/* Line 1810 of yacc.c  */
#line 763 "parser.y"
    {
								if((yyvsp[(1) - (3)].e)->ret_type != INTEG || (yyvsp[(3) - (3)].e)->ret_type != INTEG){
								 	yyerror("modulo requires two integer values");
									return -1;
								}
								tmp = (yyvsp[(3) - (3)].e);
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = (yyvsp[(1) - (3)].e);
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = MOD;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								(yyval.e) = (yyvsp[(3) - (3)].e);

							}
    break;

  case 64:

/* Line 1810 of yacc.c  */
#line 789 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 65:

/* Line 1810 of yacc.c  */
#line 790 "parser.y"
    {
			 	(yyval.e)=(yyvsp[(2) - (2)].e);
				if((yyvsp[(2) - (2)].e)->ret_type != INTEG){
					yyerror("minus requires an int");
					return -1;
				}
				tmp = (yyvsp[(2) - (2)].e);
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

  case 66:

/* Line 1810 of yacc.c  */
#line 820 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);}
    break;

  case 67:

/* Line 1810 of yacc.c  */
#line 821 "parser.y"
    {

						int i = find_symbol((yyvsp[(1) - (4)].a), &tmp_sym, local_table);
						if(tmp_sym == NULL){
							yyerror("symbol not found");
							return -1;
						}
						(yyval.e) = malloc(sizeof(expr));
						if(tmp_sym->args == NULL){
							yyerror("expected function call");
							return -1;
						}
						(yyval.e)->type = tmp_sym->type;
						(yyval.e)->data = (yyvsp[(1) - (4)].a);
						(yyval.e)->next = NULL;
						(yyval.e)->args = (yyvsp[(3) - (4)].e);
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

  case 68:

/* Line 1810 of yacc.c  */
#line 850 "parser.y"
    {
						int i = find_symbol((yyvsp[(1) - (3)].a), &tmp_sym, local_table);
						if(tmp_sym == NULL){
							yyerror("symbol not found");
							return -1;
						}
						(yyval.e) = malloc(sizeof(expr));
						if(tmp_sym->args == NULL){
							yyerror("expected function call");
							return -1;
						}
						if(tmp_sym->args[1] != VOID){
							yyerror("function call types do not match function declaration");
							return -1;
						}
						(yyval.e)->type = tmp_sym->type;
						(yyval.e)->data = (yyvsp[(1) - (3)].a);
						(yyval.e)->next = NULL;
						(yyval.e)->args = NOARG;
					}
    break;

  case 69:

/* Line 1810 of yacc.c  */
#line 873 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);}
    break;

  case 70:

/* Line 1810 of yacc.c  */
#line 874 "parser.y"
    {tmp = (yyvsp[(3) - (3)].e);
			 while(tmp->next != NULL)
				tmp = tmp->next;
			tmp->next= (yyvsp[(1) - (3)].e);
			(yyval.e) = (yyvsp[(3) - (3)].e);}
    break;

  case 71:

/* Line 1810 of yacc.c  */
#line 882 "parser.y"
    {

	int i = find_symbol((yyvsp[(1) - (1)].a), &tmp_sym, local_table);
	if(tmp_sym == NULL){
		yyerror("symbol not found");
		return -1;
	}
	(yyval.e) = malloc(sizeof(expr));
	(yyval.e)->type = tmp_sym->type;
	(yyval.e)->ret_type = tmp_sym->type;
	if(tmp_sym->args == NULL){
		
		(yyval.e)->data = malloc(sizeof(char)*MAXEXPR);

		if(i == 0)
			if(tmp_sym->type == STRIN)
				snprintf((yyval.e)->data, MAXEXPR, "  leal %s%d(%%ebp), %%eax\n  pushl %%eax\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
			else snprintf((yyval.e)->data, MAXEXPR, "  pushl %s%d(%%ebp)\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
		else{
			char *cur = (yyval.e)->data;
			char *end = cur + MAXEXPR;
			cur += snprintf((yyval.e)->data, MAXEXPR, "  leal (%%ebp), %%ecx\n");
			while(i > 1){
				cur += snprintf(cur, end-cur,"  leal (%%ecx), %%ecx\n");
				--i;
			}
			if(tmp_sym->type == STRIN)
				cur += snprintf((yyval.e)->data, MAXEXPR, "  leal %s%d(%%ecx), %%eax\n  pushl %%eax\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
			else cur += snprintf(cur, end-cur, "  pushl %s%d(%%ecx)\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
		
		}
		(yyval.e)->args = NULL;
	}

	else (yyval.e)->data = (yyvsp[(1) - (1)].a);
	(yyval.e)->next = NULL; 
	}
    break;

  case 72:

/* Line 1810 of yacc.c  */
#line 919 "parser.y"
    {
		(yyval.e) = malloc(sizeof(expr));
		(yyval.e)->type = INTEG;
		(yyval.e)->ret_type = INTEG;
		(yyval.e)->args = NULL;
		(yyval.e)->data = malloc(sizeof(char)*MAXEXPR);
		snprintf((yyval.e)->data, MAXEXPR, "  pushl $%d\n", (yyvsp[(1) - (1)].fn));
		(yyval.e)->next = NULL;
		
		}
    break;

  case 73:

/* Line 1810 of yacc.c  */
#line 929 "parser.y"
    {
		(yyval.e) = malloc(sizeof(expr));
		(yyval.e)->data = malloc(sizeof(char)*MAXEXPR);
		(yyval.e)->type = STRIN;
		(yyval.e)->ret_type = STRIN;
		(yyval.e)->args = NULL;
		glb_strings[str_counter] = (yyvsp[(1) - (1)].a);
		snprintf((yyval.e)->data, MAXEXPR, "  pushl $.s%d\n", str_counter);
		++str_counter;
		(yyval.e)->next = NULL;
		}
    break;

  case 74:

/* Line 1810 of yacc.c  */
#line 940 "parser.y"
    {(yyval.e) = (yyvsp[(2) - (3)].e);}
    break;



/* Line 1810 of yacc.c  */
#line 2751 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2071 of yacc.c  */
#line 943 "parser.y"


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
	else printf("  leave\n");


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
			case DIVI:
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
			case RET:
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

