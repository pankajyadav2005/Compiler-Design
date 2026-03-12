#include<stdio.h>
#include<string.h>

char c[20];
int input = 0;

void E();
void EPRIME();

int main()
{
    printf("Enter a String (use $ at end): ");
    scanf("%s", c);

    E();

    if(c[input] == '$')
        printf("Valid String\n");
    else
        printf("Invalid String\n");

    return 0;
}

void E()
{
    if(c[input] == 'i')
    {
        input++;
        EPRIME();
    }
    else
    {
        printf("Invalid String\n");
    }
}

void EPRIME()
{
    if(c[input] == '+')
    {
        input++;
        if(c[input] == 'i')
        {
            input++;
            EPRIME();
        }
        else
        {
            printf("Invalid String\n");
        }
    }
    else
    {
        return;   // ε production
    }
}