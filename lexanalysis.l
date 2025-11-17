%{
#include<stdio.h>
%}

%%
[/][/] [a-zA-Z0-9]* {printf("Single Line Comment.");}
[/][*][a-zA-Z0-9]*[*][/] {printf("Multiline Comment.");}
if|else|while|do|switch|case|break|for|default {printf("Keyword");}
IF|ELSE|WHILE|DO|SWITCH|CASE|BREAK|FOR|DEFAULT {printf("Keyword");}
[A-Za-z_]+[a-zA-Z0-9_]* {printf("Identifier");}
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
