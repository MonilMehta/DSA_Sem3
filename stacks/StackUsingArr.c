#include<Stdio.h>
#define SIZE 20

int stack[SIZE],top=-1;

void push(int val)
{
    if(top==-1)
    {
        stack[++top]=val;
    }
    else if(top==SIZE-1)
    {
        printf("Stack Overflow");
    }
    else{
        stack[++top]=val;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        printf("%d popped",stack[top]);
        top--;
    }
}
void displayStack(){
    int temp=top;
    if(temp==-1)
    {
        printf("Stack Empty");
    }
    else{
        while(temp>=0)
        {
            printf("%d\t|",stack[temp]);
            temp--;
        }
    }
}
void peak(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else
    {
        printf("Peak : %d",stack[top]);
    }
}
void main(){
    int choice,val;
    do{
        printf("\n|-----------------------------------------------------------------|\n");
        printf("Enter :\n1 to push\n2 to pop\n3 to display stack\n0 to stop\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data to push : ");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            displayStack();
            break;
        
        default:
            printf("Thank You");
            break;
        }

    }while(choice!=0);

}