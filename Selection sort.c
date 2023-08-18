//Selection sort 220953504
#include<stdio.h>
void main()
{int a[10],x,i,j,n,ct,p,min,temp;
ct=0;
p=0;
printf("Enter number of elements in array:");
scanf("%d",&n);
printf("Enter elements of the array:");
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
for (i = 0; i < n; i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
          if (a[j] < a[min])
            min=j;
           if(min!= i)
           {
           temp=a[i];
           a[i]=a[min];
           a[min]=temp;
           }

     }


printf("Sorted Array:");

    for (i=0; i<n; i++)
       { printf("%d ", a[i]);
    }
    return 0;
}

