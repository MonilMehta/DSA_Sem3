#include<Stdio.h>
#define SIZE 20

int q[SIZE],front=-1,rear=-1;

void enqueue(int val)
{
    if(rear==-1){
        front=rear=0;
        q[rear]=val;
    }
    else if(front==(rear+1)%SIZE){
        printf("Q full");
    }
    else{
        rear=(rear+1)%SIZE;
        q[rear]=val;
    }
}
void dequeue(){
    int val;
    if(front==-1)
    {
        printf("Queue Empty");
    }
    else if(front==rear && front!=-1)
    {
        val=q[front];
        front=rear=-1;
        printf("%d dequeed\n",val);
    }
    else{
        val=q[front];
        front=(front+1)%SIZE;
        printf("%d dequeed\n",val);
    } 
}
void displayQueue(){
    if(front==-1 || rear==-1)
        printf("Queue Empty");
    else{
        int i=front;
        while(i!=rear)
        {
            printf("%d  ||",q[i]);
            i=(i+1)%SIZE;
        }
        printf("%d",q[i]);
    }
}
void peak(){
    
}
void main(){
    int choice,val;
    do{
        printf("\n|-----------------------------------------------------------------|\n");
        printf("Enter :\n1 to enqueue\n2 to dequeue\n3 to display queue\n0 to stop\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data to enqueue : ");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayQueue();
            break;
        
        default:
            printf("Thank You");
            break;
        }

    }while(choice!=0);

}