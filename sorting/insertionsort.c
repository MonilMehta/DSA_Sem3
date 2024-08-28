#include<stdio.h>
#define SIZE 10

void insertion_Sort(int arr[],int n);

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
    insertion_Sort(arr,n);
    printf("Sorted array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
void insertion_Sort(int arr[],int n)
{
    int i,j,temp,min;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && (arr[j]>temp))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}