%{
#include<stdio.h>

int vow_count = 0;
int const_count = 0;

FILE *yyin;
%}

%%

[aeiouAEIOU]     { vow_count++; }
[a-zA-Z]         { const_count++; }

%%

int main()
{
    yyin = fopen("practical8.txt","r");

    yylex();

    printf("The number of vowels are: %d\n", vow_count);
    printf("The number of consonants are: %d\n", const_count);

    return 0;
}

int yywrap()
{
    return 1;
}