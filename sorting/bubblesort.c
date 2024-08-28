#include<stdio.h>
#define SIZE 10

void bubble_sort(int arr[],int n);

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
    bubble_sort(arr,n);
    printf("Sorted array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
void bubble_sort(int arr[],int n)
{
    int i,j,flag=0,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            return;
    }
}