//Binary Search 220953504
#include<stdio.h>
void main()
{


int a[10],x,i,n,cnt,p,mid,low,high;
cnt=0;
p=0;
printf("Enter number of elements in array:");
scanf("%d",&n);
printf("Enter elements of the array:");
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
printf("Enter element to be searched:");
scanf("%d",&x);



            low=0;
            high=n-1;
            for(i=0;i<n;i++){
        mid = (low + high)/2;
    if (x == a[mid])
    {p=mid+1;
    cnt++;
    }
    else if (x>a[mid])
        low = mid + 1;
    else
        high = mid - 1;
        if(cnt==1)
printf("Element %d is found at position %d",x,p);



    return 0;
}}

