%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { }
%}

%option noyywrap

%%

[ \t\n]          ; // Ignore whitespace characters

"+"              { return TOKEN(TPLUS); }
"-"              { return TOKEN(TMINUS); }
"*"              { return TOKEN(TMUL); }
"/"              { return TOKEN(TDIV); }
"="              { return TOKEN(TEQUAL); }

.                { printf("Unknown token!\n"); yyterminate(); }

%%