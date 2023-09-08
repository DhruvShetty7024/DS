#include<stdio.h>
#include<math.h>
#define MAX 100
int top=-1;
int stack[MAX];
void push(int n)
{
    top++;
    if(top<MAX)
    {
        stack[top]=n;
    }
    else
    {
        printf("Stack has overflowed");
    }
}
int main()
{
    int n,base;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Enter the base:");
    scanf("%d",&base);
    while(n!=0)
    {
        push(n%base);
        n/=base;
    }
    while(top>=0)
    {
        intpop =stack[top];
        if(pop>=10)
        printf("%c",pop+55);
        else printf("%d",pop);
        top--;
    }
    return 0;
}
