#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void followfirst(char , int , int);
void findfirst(char , int , int);
void follow(char c);

int count,n=0;
char calc_first[10][100];
char calc_follow[10][100];
int m=0;

char production[10][10], first[10];
char f[10];

int k;
char ck;
int e;

/* MAIN FUNCTION */

int main()
{
    int jm=0, km=0, i;
    char c, ch;

    printf("How many productions? : ");
    scanf("%d",&count);

    printf("\nEnter productions (A=B form):\n");
    for(i=0;i<count;i++)
        scanf("%s",production[i]);

    char done[count];
    int ptr = -1;

    /* FIRST calculation */
    for(k=0;k<count;k++)
    {
        c=production[k][0];
        int xxx=0;

        for(int kay=0; kay<=ptr; kay++)
            if(c==done[kay]) xxx=1;

        if(xxx==1) continue;

        findfirst(c,0,0);

        ptr++;
        done[ptr]=c;

        printf("\nFIRST(%c) = { ",c);
        for(i=jm;i<n;i++)
            printf("%c ",first[i]);

        printf("}\n");
        jm=n;
    }

    /* FOLLOW calculation */
    ptr=-1;

    for(e=0;e<count;e++)
    {
        ck=production[e][0];
        int xxx=0;

        for(int kay=0;kay<=ptr;kay++)
            if(ck==done[kay]) xxx=1;

        if(xxx==1) continue;

        follow(ck);

        ptr++;
        done[ptr]=ck;

        printf("FOLLOW(%c) = { ",ck);
        for(i=km;i<m;i++)
            printf("%c ",f[i]);

        printf("}\n");
        km=m;
    }

    printf("\nLL(1) Parsing Completed\n");

    return 0;
}

/* FUNCTIONS */

void findfirst(char c,int q1,int q2)
{
    int j;

    if(!isupper(c))
    {
        first[n++]=c;
        return;
    }

    for(j=0;j<count;j++)
    {
        if(production[j][0]==c)
        {
            if(production[j][2]=='#')
            {
                if(production[q1][q2]=='\0')
                    first[n++]='#';
                else
                    findfirst(production[q1][q2],q1,q2+1);
            }
            else if(!isupper(production[j][2]))
                first[n++]=production[j][2];
            else
                findfirst(production[j][2],j,3);
        }
    }
}

void follow(char c)
{
    if(production[0][0]==c)
        f[m++]='$';

    for(int i=0;i<count;i++)
    {
        for(int j=2;j<strlen(production[i]);j++)
        {
            if(production[i][j]==c)
            {
                if(production[i][j+1]!='\0')
                    followfirst(production[i][j+1],i,j+2);
                else if(c!=production[i][0])
                    follow(production[i][0]);
            }
        }
    }
}

void followfirst(char c,int c1,int c2)
{
    if(!isupper(c))
    {
        f[m++]=c;
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            if(calc_first[i][0]==c)
            {
                int j=1;
                while(calc_first[i][j]!='!')
                {
                    if(calc_first[i][j]!='#')
                        f[m++]=calc_first[i][j];
                    else
                    {
                        if(production[c1][c2]=='\0')
                            follow(production[c1][0]);
                        else
                            followfirst(production[c1][c2],c1,c2+1);
                    }
                    j++;
                }
            }
        }
    }
}