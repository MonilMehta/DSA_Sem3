#include<stdio.h>
#define SIZE 20

int main(int argc, char const *argv[])
{
    int arr[SIZE],i,j,n,flag=0,min,temp;
    printf("\n---------------------Implementing Selection Sort-----------------------\n\n");
    printf("Enter No of Elements : ");
    scanf("%d",&n);
    printf("Enter The elements :  \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    
    
}