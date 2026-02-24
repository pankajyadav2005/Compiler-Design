#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char stack[50], ip[50], opt[10][10];
    char ter[10];
    int i, j, k, n, top = 0, row = 0, col = 0;
    int len;

    printf("Enter the number of terminals: ");
    scanf("%d", &n);

    printf("Enter the terminals (without space): ");
    scanf("%s", ter);

    printf("\nEnter the Operator Precedence Table values (<, >, =)\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter value for %c %c: ", ter[i], ter[j]);
            scanf(" %c", &opt[i][j]);
        }
    }

    printf("\nOPERATOR PRECEDENCE TABLE:\n\t");
    for(i = 0; i < n; i++)
        printf("%c\t", ter[i]);

    printf("\n");

    for(i = 0; i < n; i++)
    {
        printf("%c\t", ter[i]);
        for(j = 0; j < n; j++)
            printf("%c\t", opt[i][j]);
        printf("\n");
    }

    stack[top] = '$';
    stack[top+1] = '\0';

    printf("\nEnter input string (append $ at end): ");
    scanf("%s", ip);

    i = 0;
    len = strlen(ip);

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    while(i < len)
    {
        printf("%s\t\t%s\t\t", stack, ip+i);

        for(k = 0; k < n; k++)
        {
            if(stack[top] == ter[k])
                row = k;
            if(ip[i] == ter[k])
                col = k;
        }

        if(stack[top] == '$' && ip[i] == '$')
        {
            printf("ACCEPTED\n");
            break;
        }
        else if(opt[row][col] == '<' || opt[row][col] == '=')
        {
            top++;
            stack[top] = ip[i];
            stack[top+1] = '\0';
            printf("SHIFT %c\n", ip[i]);
            i++;
        }
        else if(opt[row][col] == '>')
        {
            printf("REDUCE\n");
            while(stack[top] != '<' && top > 0)
                top--;
            stack[top+1] = '\0';
        }
        else
        {
            printf("REJECTED\n");
            break;
        }
    }

    return 0;
}