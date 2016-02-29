/* A Bison parser, made by GNU Bison 2.5.1.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2072 of yacc.c  */
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



/* Line 2072 of yacc.c  */
#line 127 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


