#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node ;

struct Node *createNode(int val)
{
    node *temp=(node *)(malloc(sizeof(node)));
    temp->data=val;
    temp->next=NULL;
    return temp;
}
node *top=NULL;

// void createList(){
//     node *temp,*New;
//     int data,choice=1;
//     while(choice!=0)
//     {
//         printf("Enter Data : ");
//         scanf("%d",&data);
//         New=createNode(data);
//         if(top==NULL)
//             temp=top=New;
//         else{
//             temp->next=New;
//             temp=temp->next;
//         }
//         printf("Enter 1 to cotinue, 0 to stop : ");
//         scanf("%d",&choice);
//     }
// }
void displayStack()
{
    node *temp=top;
    if(temp==NULL)
    {
        printf("No Linked List Created \n");
    }
    else
    {
        while(temp!=NULL)
        {
                printf("%d\t|",temp->data);
                temp=temp->next;
        }
    }
}
void push(int val)
{
    node *New=createNode(val);
    if(top==NULL)
        top=New;
    else{
        New->next=top;
        top=New;
    }
}
void pop()
{
    node *temp=top;
    if(temp==NULL)
        printf("Stack underflow");
    else{
        temp=top;
        printf("%d popped",top->data);
        top=top->next;
        free(temp);
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