#include<stdio.h>
void merge_sort(int a[],int beg,int end);
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
void merge(int a[],int beg,int mid,int end)
{
    int i=beg,j=mid+1,index=beg,temp[10],k;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
            temp[index++]=a[i++];
        else if(a[j]<a[i])
            temp[index++]=a[j++];
    }
    if(i>mid)
    {
        while(j<=end)
            temp[index++]=a[j++];
    }
    else{
        while(i<=mid)
            temp[index++]=a[i++];
    }
    for(k=beg;k<index;k++)
    {
        a[k]=temp[k];
    }
}
void merge_sort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        merge_sort(a,beg,mid);
        merge_sort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}