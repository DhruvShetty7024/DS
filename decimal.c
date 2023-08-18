#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int t=-1;
void push(int n)
{
    if(t==MAX-1)
    {
        printf("Stack has overflowed");
        return;
    }
    else
    {
        t++;
        stack[t]=n;
    }
}
void pop()
{
    if(t==-1)
    {
        printf("Stack has underflowed");
        return;
    }
    else
    {
        stack[t--];
    }
}
void display()
{
    for(int i=t;i>0;i--)
    {
        printf("%d\n",&stack);
    }
}
int main()
{

}
