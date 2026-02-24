#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int i, at=0,sp=0,c=0,n=0,s=0,spl=0;
char username[20],password[20];
printf("enter user name ");
scanf("%s",username); printf("enter password "); scanf("%s",password);
for(i=0;i<strlen(username);i++){
if(username[i]=='@') at++;
if(username[i]=='.') sp++;
}
for(i=0;i<strlen(password); i++) {
if(password[i]>64 && password[i]<90)
c++;
if(password[i]>47 && password[i]<58)
n++;
if(password[i]>97 && password[i]<123)
s++;
else
spl++;
}
if(at!=1)
printf("\ninvalid user name"); else
printf("\nvalid user name");
if(c<1||n<1||s<1||spl<1||(n+c+s+spl)<8) printf("\ninvalid password");
else
printf("\nvalid password");
} 
