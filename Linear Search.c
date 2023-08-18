//Linear search 220953504
#include<stdio.h>
void main()
{
int a[10],x,i,j,n,ct,p;
ct=0;
p=0;
printf("Enter number of elements in array:");
scanf("%d",&n);
printf("Enter elements of the array:");
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
printf("Enter element to be searched:");
scanf("%d",&x);

        for(i=0;i<n;i++)
{
if(a[i]==x)
{ct++;
p=i+1;
}
}
if(ct!=0)
printf("Element %d is found at position %d",x,p);
else
printf("Element not found");
return 0;
}
