//Split,Reverse dekhlena
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
node *root=NULL;

void createList(){
    node *temp,*New;
    int data,choice=1;
    while(choice!=0)
    {
        printf("Enter Data : ");
        scanf("%d",&data);
        New=createNode(data);
        if(root==NULL)
            temp=root=New;
        else{
            temp->next=New;
            temp=temp->next;
        }
        printf("Enter 1 to cotinue, 0 to stop : ");
        scanf("%d",&choice);
    }
}
void displayList(node *root)
{
    node *temp=root;
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
void insertNode(int data)
{
    node *temp,*temp2;
    int choice=1,val;
    printf("Enter 1 to insert at start \n");
    printf("Enter 2 to insert at end \n");
    printf("Enter 3 to insert before node \n");
    printf("Enter 4 to insert after node \n");
    printf("Enter Choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        temp=createNode(data);
        temp->next=root;
        root=temp;
        break;
    case 2:
        temp=createNode(data);
        temp2=root;
        while(temp2->next!=NULL)
            temp2=temp2->next;
        temp2->next=temp;
        temp->next=NULL;
        break;
    case 3:
        temp=createNode(data);
        printf("Enter Node Val to insert before : ");
        scanf("%d",&val);
        temp2=root;
        while(temp2->next->data!=val)
            temp2=temp2->next;
        temp->next=temp2->next;
        temp2->next=temp;
        break;
    case 4:
        temp=createNode(data);
        printf("Enter Node Val to insert after : ");
        scanf("%d",&val);
        temp2=root;
        while(temp2->data!=val)
            temp2=temp2->next;
        temp->next=temp2->next;
        temp2->next=temp;
        break;
    
    default:
        printf("Enter a valid choice");
        break;
    }
}
void deleteNode()
{
    node *temp,*temp2;
    int choice=1,val;
    printf("Enter 1 to delete at start \n");
    printf("Enter 2 to delete at end \n");
    printf("Enter 3 to delete node base on val \n");
    printf("Enter Choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        temp=root;
        root=temp->next;
        free(temp);
        break;
    case 2:
        temp2=root;
        while(temp2->next->next!=NULL)
            temp2=temp2->next;
        temp->next=temp2->next;
        free(temp);
        temp2->next=NULL;
        break;
    case 3:
        printf("Enter Node Val to delete : ");
        scanf("%d",&val);
        temp2=root;
        while(temp2->next->data!=val)
            temp2=temp2->next;
        temp->next=temp2->next;
        temp2->next=temp2->next->next;
        free(temp);
        break;
    
    default:
        printf("Enter a valid choice");
        break;
    }
}
node *root2=NULL;
void copyLL(node *root1)
{
    node *temp1 = root1;
    node *temp2 = NULL;
    node *newNode = NULL;

    while (temp1 != NULL)
    {
        newNode = createNode(temp1->data);

        if (temp2 == NULL)
        {
            temp2 = newNode;
            root2 = temp2;
        }
        else
        {
            temp2->next = newNode;
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    printf("Linked List Copied:\n");
    displayList(root2);
}
void concatenate(node *root1, node *root2)
{
    node *temp = root1;

    if (temp == NULL)
    {
        printf("First linked list is empty.\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = root2;
    displayList(root1);
}
void split(node *root, int val)
{
    node *temp = root;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        root2 = temp->next;
        temp->next = NULL;
        printf("Linked List Split:\n");
        displayList(root);
        printf("Second Linked List after Split:\n");
        displayList(root2);
    }
    else
    {
        printf("Value not found for split.\n");
    }
}
void countNodes(node *root)
{
    int count=0;
    node *temp=root;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("COunt of nodes is %d " ,count);
}
void reverse(node **root)
{
    node *prev = NULL, *current = *root, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *root = prev;

    printf("Linked List Reversed\n");
}

int main()
{
    int choice = 1, data;
    while (choice != 0)
    {
        printf("|--------------------------------------------------------------------|\n");
        printf("Enter : \n1 for creating list\n2 for inserting element\n3 for deletion \n4 for Display\n5 for Reverse\n6 for copy\n7 for count\n 8 for split\n9 to concat\n0 For Exit\nChoice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createList();
            break;

        case 2:
            printf("Enter Data to insert : ");
            scanf("%d", &data);
            insertNode(data);
            break;

        case 3:
            deleteNode();
            break;

        case 4:
            displayList(root);
            break;

        case 5:
            reverse(&root);
            break;
        case 6:
            copyLL(root);
            break;
        case 7:
            countNodes(root);
            break;

        case 8:
            printf("Enter the value to split the linked list: ");
            scanf("%d", &data);
            split(root, data);
            break;

        case 9:
            concatenate(root, root2);
            break;
        default:
            printf("Thank You\n");
            break;
        }
    }

    return 0;
}
