#include<stdio.h>
#define SIZE 10

int table[SIZE];
void displayTable();
int linearprobe(int key,int i)
{
    int index=((key+i)%SIZE);
    if(table[index]==0)
        return index;
    else
        return linearprobe(key,i+1);
}
int quadprobe(int key)
{
    int i=0;
    int index=((key+i*i)%SIZE);
    if(table[index]==0)
        return index;
    else{
    while(table[index]!=0)
    {
        i+=1;
        index=((key+i*i)%SIZE);     
    }
        return index;
    }
}
int isFull()
{
    int count=0;
    for(int i=0;i<SIZE;i++)
    {
        if(table[i]!=0)
            count++;
    }
    if(count==SIZE)
        return 0;
    else
        return 1;
}

void insertVal(int type)
{
    int val,i=0,j=0,index,choice=1;
    while(choice!=-1 && isFull())
    {
        printf("Enter Val : ");
        scanf("%d",&val);
        if(type==1)
            index=linearprobe(val,i);
        else if(type==2)
            index=quadprobe(val);
        
        table[index]=val;
        printf("Inserted %d at position %d \n",val,index);
        displayTable();
        printf("Enter -1 to stop : ");
        scanf("%d",&choice);
    }
    displayTable();
}
void displayTable()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(table[i]==0)
            printf("[ %d ]->[  ]\n",i);
        else 
            printf("[ %d ]->[ %d ]\n",i,table[i]);
    }
}
void main()
{
    for(int i=0;i<SIZE;i++)
    {
        table[i]=0;
    }
    int option;
    printf("Enter 1 for linear probing and 2 for quadratic : ");
    scanf("%d",&option);
    insertVal(option);

}
