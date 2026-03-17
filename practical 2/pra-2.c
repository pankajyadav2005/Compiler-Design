#include <stdio.h>

int main()
{
    char str[100];
    int vowels = 0, digit = 0, special = 0, consonant = 0;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
            str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
        {
            vowels++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digit++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            consonant++;
        }
        else if (str[i] != ' ' && str[i] != '\n')
        {
            special++;
        }
    }

    printf("\nVowels: %d", vowels);
    printf("\nConsonants: %d", consonant);
    printf("\nDigits: %d", digit);
    printf("\nSpecial characters: %d\n", special);

    return 0;
}