//Prime numbers between two numbers 220953504
#include<stdio.h>
void main()
{int a,b,i,j,c;
printf("Enter a:");
scanf("%d",&a);
printf("Enter b:");
scanf("%d",&b);
for(i=a;i<=b;i++)
{
    c=0;
for(j=2;j<i;j++)
{if(i%j==0){
c++;
}}
if(c==0)
printf("%d ",i);
}
    return 0;
}
