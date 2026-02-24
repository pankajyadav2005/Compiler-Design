#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 20

int n;
char prod[MAX][MAX];
char first[MAX], followSet[MAX];
int firstCount = 0, followCount = 0;

/* Function to find FIRST */
void findFirst(char c) {
    int i;

    if(!isupper(c)) {
        first[firstCount++] = c;
        return;
    }

    for(i = 0; i < n; i++) {
        if(prod[i][0] == c) {

            if(prod[i][2] == '#') {
                first[firstCount++] = '#';
            }
            else if(!isupper(prod[i][2])) {
                first[firstCount++] = prod[i][2];
            }
            else {
                findFirst(prod[i][2]);
            }
        }
    }
}

/* Function to find FOLLOW */
void findFollow(char c) {
    int i, j;

    if(prod[0][0] == c)
        followSet[followCount++] = '$';

    for(i = 0; i < n; i++) {
        for(j = 2; j < strlen(prod[i]); j++) {

            if(prod[i][j] == c) {

                if(prod[i][j+1] != '\0') {
                    if(!isupper(prod[i][j+1]))
                        followSet[followCount++] = prod[i][j+1];
                    else
                        findFirst(prod[i][j+1]);
                }

                if(prod[i][j+1] == '\0' && c != prod[i][0]) {
                    findFollow(prod[i][0]);
                }
            }
        }
    }
}

int main() {

    int i;
    char ch;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR)\n");

    for(i = 0; i < n; i++)
        scanf("%s", prod[i]);

    /* FIRST */
    printf("\nFIRST Sets:\n");

    for(i = 0; i < n; i++) {
        firstCount = 0;
        findFirst(prod[i][0]);

        printf("FIRST(%c) = { ", prod[i][0]);

        for(int j = 0; j < firstCount; j++)
            printf("%c ", first[j]);

        printf("}\n");
    }

    /* FOLLOW */
    printf("\nFOLLOW Sets:\n");

    for(i = 0; i < n; i++) {
        followCount = 0;
        findFollow(prod[i][0]);

        printf("FOLLOW(%c) = { ", prod[i][0]);

        for(int j = 0; j < followCount; j++)
            printf("%c ", followSet[j]);

        printf("}\n");
    }

    return 0;
}