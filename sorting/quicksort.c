#include<stdio.h>
void insertionSOrt(int a[],int n);
void main()
{
    int a[20], n,key;
    printf("Enter No of elements : ");
    scanf("%d",&n);
    printf("Enter Array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Entered Array is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    merge_sort(a,0,n);
    printf("\nSorted Array is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int partition(int a[],int beg,int end)
{
    int loc=beg,left=beg,right=end,flag=0,temp;
    while(flag!=1)
    {
        while(a[right]>a[loc] && loc!=right)
            right--;
        if(right==loc)
            flag=1;
        else if(a[loc]>a[right])
        {
            temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
        }
        if(flag!=1)
        {
            while(a[left]<a[loc] && left!=loc)
                left++;
            if(left==loc)
            flag=1;
            else if(a[loc]>a[left])
            {
            temp=a[loc];
            a[loc]=a[left];
            a[left]=temp;
            }
        }
    }
    return loc;
}
void quick_sort(int a[],int beg,int end)
{
    int loc;
    if(beg<end)
    {
        loc=partition(a,beg,end);
        quick_sort(a,beg,loc-1);
        quick_sort(a,loc+1,end);
    }
}