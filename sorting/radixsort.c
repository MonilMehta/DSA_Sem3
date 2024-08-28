#include<stdio.h>
#define SIZE 10

void radix_sort(int arr[],int n);

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
    radix_sort(arr,n);
    printf("Sorted array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
int largest(int arr[], int n)
{
    int large=arr[0], i;
    for(i=1;i<n;i++)
    {
        if(arr[i]>large)
        large = arr[i];
    }
    return large;
}
void radix_sort(int arr[],int n)
{
    int buckets[SIZE][SIZE],bucket_count[SIZE],NOP,large,i,j,k,remainder,pass,divisor=1;
    
    large=largest(arr,n);
    while(large>0){
        NOP++;
        large/=SIZE;
    }
    for(pass=0;pass<NOP;pass++)
    {
        for(i=0;i<SIZE;i++)
            bucket_count[i]=0;
        for(i=0;i<n;i++)
        {
            remainder=(arr[i]/divisor)%SIZE;
            buckets[remainder][bucket_count[remainder]]=arr[i];
            bucket_count[remainder]+=1;
        }
        i=0;
        for(k=0;k<n;k++)
        {
            for(j=0;j<bucket_count[k];j++)
            {
                arr[i]=buckets[k][j];
                i++;
            }
        }
        divisor*=SIZE;
    }
}