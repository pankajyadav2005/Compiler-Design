%{
#include<stdio.h>

int lines = 0, words = 0;
int s_letters = 0, c_letters = 0;
int num = 0, spl_char = 0, total = 0;

FILE *yyin;
%}

%%

\n              { lines++; words++; }
[\t ]           { words++; }
[A-Z]           { c_letters++; }
[a-z]           { s_letters++; }
[0-9]           { num++; }
.               { spl_char++; }

%%

int main(void)
{
    yyin = fopen("practical9.txt","r");

    yylex();

    total = s_letters + c_letters + num + spl_char;

    printf("This File contains ...\n");
    printf("\n%d lines", lines);
    printf("\n%d words", words);
    printf("\n%d small letters", s_letters);
    printf("\n%d capital letters", c_letters);
    printf("\n%d digits", num);
    printf("\n%d special characters", spl_char);
    printf("\nIn total %d characters\n", total);

    return 0;
}

int yywrap()
{
    return 1;
}