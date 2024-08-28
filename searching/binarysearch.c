#include<stdio.h>
#define SIZE 10

void bubble_sort(int arr[],int n);
int binarySearch(int arr[],int n,int key);
int main(int argc, char const *argv[])
{
    int arr[SIZE],i,j,n,flag=0,min,temp,key;
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
    printf("\nEnter element to search for : ");
    scanf("%d",&key);
    int x=binarySearch(arr,n,key);
    if(x==-1)
        printf("\nElement not in array");
    else{
        printf("\nElement found at position %d",x+1);
    }
}
void bubble_sort(int arr[],int n)
{
    int i,j,flag=0,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
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
        {
            return;
        }
    }
}

int binarySearch(int arr[],int n,int key)
{
    int front=0,rear=n-1,mid;
    while(front<=rear)
    {
        mid=(front+rear)/2;
        if(arr[mid]==key)
            return mid;
        else if(mid<key)
            front=mid+1;
        else
            rear=mid-1;
    }
    return -1;
}



void bubble_sort(int arr[],int n)
{
    int i,j,flag=0,temp,min;
    for(i=1;i<n-1;i++)
    {
        min=i;
        for(j=i;j<n;j++)
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
        {
            return;
        }
    }
}