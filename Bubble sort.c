//Bubble sort 220953504
#include<stdio.h>
void main()
{int a[10],i,j,n,min,temp;
printf("Enter number of elements in array:");
scanf("%d",&n);
printf("Enter elements of the array:");
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
 for(i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
printf("Sorted Array:");

    for (i=0; i<n; i++)
       { printf("%d ", a[i]);
    }
    return 0;
}
