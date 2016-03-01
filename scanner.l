%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbol.h"
#include "y.tab.h"
%}
 
%x C_COMMENT L_COMMENT
%option yylineno
%%

"/*"	{BEGIN(C_COMMENT);}
<C_COMMENT>"*/"	{BEGIN(0);}
<C_COMMENT>.	{}

"//"	{BEGIN(L_COMMENT);}
<L_COMMENT>[\n]	{BEGIN(0);}
<L_COMMENT>.	{}

#.*	{}

[ \t\n]+	{}
"-"		{return MINUS;}
"+"		{return PLUS;}
">>"		{return SHIFTRIGHT;}
"<<"	{return SHIFTLEFT;}
"*"	{return MULTI;}
"/"	{return DIV;}
"%"	{return MODULO;}

"="	{return assignment;}
"=="	{return EGAL;}
"!="	{return DIFF;}
"<"	{return INF;}
">"	{return SUP;}
"<="	{return INFEQUAL;}
">="	{return SUPEQUAL;}


if	{return IF;}
else	{return ELSE;}
while	{return WHILE;}
do	{return DO;}
for	{return FOR;}
return	{return RETURN;}
then	{return THEN;}

int	{return INT;}
string	{return STRING;}
extern	{return EXTERN;}

\'.\'	{yylval.fn = yytext[1]; return CONST_INT;}

[a-zA-z]+[0-9]*	{yylval.a = strdup(yytext); return IDENT;}
[0-9]+	{yylval.fn = atoi(yytext); return CONST_INT;}
\"([^"]*)\" {yylval.a = strdup(yytext); return CONST_STRING;}

['(){};,.]	{return *yytext;}

%%




