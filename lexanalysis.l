%{
#include<stdio.h>
%}

%%
"/*"[^*/]*"*/" {printf("Multi-line Comment);}
"//".* {printf("Single-line Comment");}
if|else|while|do|switch|case|break|for|default {printf("Keyword");}
IF|ELSE|WHILE|DO|SWITCH|CASE|BREAK|FOR|DEFAULT {printf("Keyword");}
[A-Z a-z]+[a-z A-Z 0-9 _]* {printf("Identifier");}
[0-9]+             { printf("Integer Constant"); }
[0-9]*\.[0-9]+     { printf("Floating-point Constant"); }
[{}();,:] {printf("Delimiter");}
[ \t \n]+ {printf("Delimiter");}
%%

main()
{
    yylex();
}

/* Compilation:
    lex lexanalysis.l
    cc lex.yy.c -ll
    ./a.out
*/