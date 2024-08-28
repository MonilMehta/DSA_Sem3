#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *head=NULL;
node *createNode(int val)
{
    node *temp=(node *)(malloc(sizeof(node)));
    temp->data=val;
    temp->next=NULL;
    return temp;
}
node *createList(node *head){
    node *temp,*New;
    int choice=1,val;
    do{
        printf("Enter Data : ");
        scanf("%d",&val);
        New=createNode(val);
        if(head==NULL)
            head=temp=New;
        else{
            temp=head;
            while(temp->next!=head)
                temp=temp->next;
            New->next=temp->next;
            temp->next=New;
        }
        printf("Enter 0 to stop : ");
        scanf("%d",&choice);
    }while(choice!=0);
    return head;
}
void display(node *head)
{
    node *temp=head;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else{
        while(temp!=head)
        {
            printf("%d\t|",temp->data);
            temp=temp->next;
        }
    }
}
node *insertNode(node *head)
{
    int choice,val,p;
    node *temp=head,*New;
    printf("Enter data to insert : ");
    scanf("%d",&val);
    New=createNode(val);

    printf("Enter 1 to insert at head\n2 to insert at end\n3 to insert before\n4 to insert after\n enter : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        if(temp==NULL){
            temp=head=New;
        }
        else{
            while(temp->next!=head)
                temp=temp->next;
            temp->next=New;
            New->next=head;
            head=New;
        }
        break;
    case 2:
    while(temp->next!=head)
                temp=temp->next;
            temp->next=New;
            New->next=head;
    break;
    case 3:
        printf("Enter val to insert before : ");
        scanf("%d",&p);
        while(temp->next->data!=p)
            temp=temp->next;
        New->next=temp->next;
        temp->next=New;
        break;
    case 4:
        printf("Enter val to insert after : ");
        scanf("%d",&p);
        while(temp->data!=p)
            temp=temp->next;
        New->next=temp->next;
        temp->next=New;
        break;
    default:
        break;
    }
    return head;
}
node *deleteNode(node *head)
{
    int choice,val,p;
    node *temp=head,*New;
    printf("Enter 1 to delete at head\n2 to delete at end\n3 to delete before\n enter : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        if(temp==NULL){
            printf("Empty");
        }
        else{
            head=head->next;
            free(temp);
        }
        break;
    case 2:
    while(temp->next->next!=NULL)
        temp=temp->next;
    free(temp->next->next);
    temp->next=NULL;
    break;
    case 3:
        printf("Enter val to delete Value : ");
        scanf("%d",&p);
        while(temp->next->data!=p)
            temp=temp->next;
        temp->next=temp->next->next;
        break;
    default:
        break;
    }
    return head;
}
node *reverse(node *head)
{
    node *cur=head,*prev=NULL,*next;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}