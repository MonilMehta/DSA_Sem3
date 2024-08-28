#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}node;

node *root=NULL;
node *createNode(int val){
    node *temp;
    temp=(node *)(malloc(sizeof(node)));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
void createTree()
{
    int val,choice;
    node *temp,*parentptr,*nodeptr;
    while(choice!=0)
    {
         printf("Enter value to insert : ");
        scanf("%d",&val);
        if(root==NULL)
        {
            root=createNode(val);
        }
        else{
            nodeptr=root;
            while(nodeptr!=NULL)
            {
                parentptr=nodeptr;
                if(val<nodeptr->data)
                    nodeptr=nodeptr->left;
                else
                    nodeptr=nodeptr->right;
            }
            if(val<parentptr->data)
                parentptr->left=createNode(val);
            else
                parentptr->right=createNode(val);
        }
        printf("Enter 0 to stop : ");
        scanf("%d",&choice);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        printf("%d\t",root->data);
        postorder(root->right);
    }
}
node *findSuc(node *root){
    if(root==NULL ||root->left==NULL)
        return root;
    else return findSuc(root->left);
}
node *deleteNode(node *root,int key)
{
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->right==NULL)
        {
            node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        node *temp=findSuc(root);
        root->data=temp->data;
        root->right=deleteNode(root->right,root->data);
    }
    return root;
}
node *copyTree(node *root)
{
    node *temp;
    if(temp=NULL)
        return NULL;
    
    temp->data=createNode(root->data);
    temp->left=copyTree(root->left);
    temp->right=copyTree(root->right);
    return temp;
}
int countNode(node *root)
{
    if(root==NULL)
        return 0;
    else
        return ( countNode(root->left) + countNode(root->right) + 1 );
}
int leafNodes(node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return (leafNodes(root->left)+leafNodes(root->right));
}
void main()
{
    node *temp;
    int choice=1,key,count;
    while(choice!=0)
    {
        printf("\n\n\n1 to create tree\n2 to preorder\n3 for inorder\n4 for postorder\n5 for deleetion\n6 for smallest\n");
        printf("7 for largest\n8 for total Nodes\n9 for internal\n10 for external\n0 to stop\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            createTree();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Enter No to delete : ");
            scanf("%d", &key);
            root = deleteNode(root, key); // Update the root pointer
            break;
        case 6:
            temp=smallest(root);
            printf("Smallest is %d",temp->data);
            break;
        case 7:
            temp=largest(root);
            printf("Largest is %d",temp->data);
            break;
        case 8:
            count=totalNode(root);
            printf("Total is %d",count);
            break;
        case 9:
            temp=copyTree(root);
            printf("Tree copied");
            break;
        case 10:
            count=external(root);
            printf("External is %d",count);
            break;

        
        default:
            break;
        }

    }
}