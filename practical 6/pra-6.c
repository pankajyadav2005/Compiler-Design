#include<stdio.h>
#include<string.h>

int main()
{
    char stack[20], ip[20], opt[10][10][2], ter[10];
    int i, j, k, n, top = 0, row = 0, col = 0;
    int len;

    /* Initialization */
    for(i = 0; i < 20; i++)
    {
        stack[i] = '\0';
        ip[i] = '\0';
    }

    printf("Enter the number of terminals: ");
    scanf("%d", &n);

    printf("Enter the terminals: ");
    scanf("%s", ter);

    printf("\nEnter the operator precedence table values:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter relation for %c %c: ", ter[i], ter[j]);
            scanf("%s", opt[i][j]);
        }
    }

    /* Display table */
    printf("\nOperator Precedence Table:\n");
    printf("\t");
    for(i = 0; i < n; i++)
        printf("%c\t", ter[i]);

    printf("\n");

    for(i = 0; i < n; i++)
    {
        printf("%c\t", ter[i]);
        for(j = 0; j < n; j++)
            printf("%c\t", opt[i][j][0]);
        printf("\n");
    }

    /* Parsing */
    stack[top] = '$';

    printf("\nEnter input string (append with $): ");
    scanf("%s", ip);

    i = 0;
    len = strlen(ip);

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    while(i <= len)
    {
        for(k = 0; k < n; k++)
        {
            if(stack[top] == ter[k])
                row = k;
            if(ip[i] == ter[k])
                col = k;
        }

        if(stack[top] == '$' && ip[i] == '$')
        {
            printf("\nString is ACCEPTED\n");
            break;
        }

        else if(opt[row][col][0] == '<' || opt[row][col][0] == '=')
        {
            stack[++top] = opt[row][col][0];
            stack[++top] = ip[i];

            printf("%s\t\t%s\t\tShift\n", stack, ip);
            i++;
        }

        else if(opt[row][col][0] == '>')
        {
            while(stack[top] != '<')
                top--;

            top--;

            printf("%s\t\t%s\t\tReduce\n", stack, ip);
        }

        else
        {
            printf("\nString is NOT accepted\n");
            break;
        }
    }

    return 0;
}