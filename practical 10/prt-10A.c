%{
#include<stdio.h>
int num = 0;
FILE *yyin;
%}

%%

[0-9]    { num++; ECHO; }

%%

int main(void)
{
    yyin = fopen("practical10.txt","r");

    yylex();

    printf("\n%d digits\n", num);

    return 0;
}

int yywrap()
{
    return 1;
}