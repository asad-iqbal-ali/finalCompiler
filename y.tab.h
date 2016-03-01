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
 enum compr entier;
 struct symbol_ *s;
 struct declar_ *d;
 struct cond_ *con;
 struct instr_ *in;
 struct flow_ *f;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
