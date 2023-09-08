#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void main()
{
srand(time(NULL));
int a=(rand()%(10-5+ 1))+5;
int x;
do
{
printf("Guess a:");
scanf("%d",&x);
if(x==a)
{
    printf("Right guess");
    exit(0);
}
else
{
  printf("Wrong guess \n");
}
}while(1);
}
