%{
    #include<stdio.h>
%}

%%
"+"?[0-9]+ {printf("%s:positive integers",yytext);}
-[0-9]+ {printf("%s:negative integers",yytext);}
-[0-9]+\.[0-9]+ {printf("%s:negative real numbers",yytext);}
"+"?[0-9]+\.[0-9]+ {printf("%s:positive real numbers",yytext);}
%%

main()
{
    yylex();
}

/* Compilation:
    lex pos-neg-int-real.l
    cc lex.yy.c -ll
    ./a.out
*/