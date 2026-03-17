#include <stdio.h>
#include <string.h>

int main()
{
    int i, at = 0, dot = 0;
    int upper = 0, lower = 0, digit = 0, special = 0;

    char username[50], password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    /* Username validation */
    for(i = 0; i < strlen(username); i++)
    {
        if(username[i] == '@')
            at++;
        if(username[i] == '.')
            dot++;
    }

    /* Password validation */
    for(i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            upper++;
        else if(password[i] >= 'a' && password[i] <= 'z')
            lower++;
        else if(password[i] >= '0' && password[i] <= '9')
            digit++;
        else
            special++;
    }

    /* Output */
    if(at == 1 && dot >= 1)
        printf("\nValid Username");
    else
        printf("\nInvalid Username");

    if(upper >= 1 && lower >= 1 && digit >= 1 && special >= 1 && strlen(password) >= 8)
        printf("\nValid Password");
    else
        printf("\nInvalid Password");

    return 0;
}