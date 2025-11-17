%{
int i,j;
#include<stdio.h>
%}

%%
[0-9]*\.[0-9]+ {
    for(i=0;i<10;i++)
    {
        if(yytext[i]=='.')
            for(j=0;j<=i-1;j++)
            {
                printf("%c",yytext[j]);
            }
    }
    exit(0);
}
%%

main()
{
    yylex();
}

/* Compilation:
   lex realtoint.l
   cc lex.yy.c -ll
   ./a.out
*/

