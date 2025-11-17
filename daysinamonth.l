%{
#include<stdio.h>
int year;
%}

%%
jan|mar|may|july|aug|oct|dec {printf("31 days in %s",yylex);}
april|june|sep|nov {printf("30 days in %s",yylex);}
feb {leap();}
[a-z A-Z]* {printf("invalid");}
%%

main()
{
    yylex();
}

leap()
{
    printf("enter year");
    scanf("%d", &year);
    if((year%4==0&&year%100!=0)||(year%400==0))
        printf("29 days");
    else
        printf("28 days");
}

/* Compilation:
   lex daysinamonth.l
   cc lex.yy.c -ll
   ./a.out
*/

