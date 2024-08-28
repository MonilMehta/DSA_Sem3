#include<stdio.h>
#define SIZE 10
int stack[SIZE];
int top1=-1,top2=SIZE;

void push1(int val)
{
    if(top1==top2-1)
        printf("Stack Overflow");
    else
        stack[++top1]=val;
}
void pop1(){
    if(top1==-1)
    {
        printf("Stack Underflow");
    }
    else{
        printf("%d popped",stack[top1]);
        top1--;
    }
}
void push2(int val)
{
    if(top2==top1+1)
        printf("Stack Overflow");
    else
        stack[--top2]=val;
}
void pop2(){
    if(top2==SIZE-1)
    {
        printf("Stack Underflow");
    }
    else{
        printf("%d popped",stack[++top2]);
    }
}
void displayStack1(){
    int i;
    for(i=top1;i>=0;i--)
    {
        printf("%d\t|",stack[i]);
    }
}
void displayStack2(){
    int i;
    for(i=top2;i<SIZE;i++)
    {
        printf("%d\t|",stack[i]);
    }
}
void main(){
    int choice,val;
    do{
        printf("\n|-----------------------------------------------------------------|\n");
        printf("Enter :\n1 to push stack 1\n2 to pop stack 1\n3 to display stack 1\n4 to push stack 2\n5 to pop stack 2\n6 to display stack 2\n0 to stop\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data to push : ");
            scanf("%d",&val);
            push1(val);
            break;
        case 2:
            pop1();
            break;
        case 3:
            displayStack1();
            break;
        case 4:
            printf("Enter Data to push : ");
            scanf("%d",&val);
            push2(val);
            break;
        case 5:
            pop2();
            break;
        case 6:
            displayStack2();
            break;
        
        default:
            printf("Thank You");
            break;
        }

    }while(choice!=0);

}