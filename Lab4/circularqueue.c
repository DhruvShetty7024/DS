#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue[max];
int f=-1,r=-1,delete_ele;
int main() {
    int ch;
    do{
    printf("\nEnter 1 for inserting element in the queue\nEnter 2 for deleting element in the queue\nEnter 3 to display the queue\nEnter 4 to exit\n");
    scanf("%d",&ch);
    int x;
    if(ch==1)
        {
         printf("Enter the element in queue: ");
         scanf("%d",&x);
         enter(x);
        }
else if(ch==2){
x=delete();
 if(x!=-1)
 printf("Deleted element x: %d\n",x);
 else
 printf("queue is empty.\n");
}
else if(ch==3)
{
     display();
}
else
    printf("exited the loop");
    }while(ch!=4);
 return 0;
}
void enter(int ele)
{
    if(f==-1 && r==-1)
    {

        f=r=0;
        queue[r]=ele;
    }
    else if((r+1)%max==f)
    {
        printf("queue has overflowed");
    }
    else{
        r=(r+1)%max;
        queue[r]=ele;
    }
}
int delete()
{
    if(f==-1&& r==-1)
    {
        printf("queue has underflowed");
    }
    else if(f==r)
    {
        delete_ele=queue[f];
        f=r=-1;
    }
    else
    {
        delete_ele=queue[f];
        f=(f+1)%max;
    }
}
void display()
{
    for(int i=f;i<=r;i++)
    {
        printf("%d ",queue[i]);
    }
}
