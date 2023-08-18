#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int t=-1;
int f=0;
char stack[MAX];
void push(char a)
{
    if(t==MAX-1)
    {
        printf("stack has overflowed");
        return;
    }
    else
    {
        t++;
        stack[t]=a;
    }
}
void pop()
{
    if(t==-1)
    {
        printf("stack has underflowed");
        return;
    }
    else
    {
        stack[t--];
    }
}
int main()
{
    char str[MAX];
    int i,j,x,l;
    printf("Enter the string:");
    gets(str);
    l=strlen(str);
    for(i=0;str[i]!='\0';i++)
    {
        x=str[i];
        push(x);
    }
    for(j=0;j<l/2;j++)
    {
        if(stack[t]==stack[f])
        {
            pop();
            f++;
        }
        else
        {
            printf("Above string is not a palindrome");
            break;
        }
    }
    if(l/2==f)
    {
        printf("Above string is a palindrome");
    }
    f=0;
    t=-1;
}
