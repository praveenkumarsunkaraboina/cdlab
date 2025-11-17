%{
#include<stdio.h>
%}

%%
[/][/] [a-z A-Z 0-9]* {printf("%s",yytext);}
[a-z A-Z 0-9]* {printf(" ");}
[/][*][a-z A-Z 0-9]*[*][/] {printf("%s",yytext);}
%%

main()
{
    yylex();
}

/* Compilation:
   lex comments.l
   cc lex.yy.l -ll
   ./a.out
*/