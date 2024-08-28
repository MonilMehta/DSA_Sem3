#include<stdio.h>
#define n 5
int front=-1,rear=-1;
int q[n];

void enqueueright(int x)
{
    if((front==0 && rear==n-1) || front==rear+1)
    {
        printf("Queue Full");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        q[rear]=x;
    }
    else if(rear==n-1)
    {
        rear=(rear+1)%n;
        q[rear]=x;
    }
    else{
        rear++;
        q[rear]=x;
    }
}
void enqueueleft(int x)
{
    if((front==0 && rear==n-1) || front==rear+1)
    {
        printf("Queue Full");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        q[rear]=x;
    }
    else if(front==0)
    {
        front=n-1;
        q[front]=x;
    }
    else{
        front--;
        q[front]=x;
    }
}
void dequeueright()
{
    int val;
    if(rear==-1 && front==-1)
    {
        printf("Queue empty");
    }
    else if(front==rear)
    {
        val=q[rear];
        front=rear=-1;
    }
    else if(rear==0)
    {
        val=q[rear];
        rear=n-1;
    }
    else{
        val=q[rear];
        rear--;
    }
}
void dequeueleft()
{
    int val;
    if(rear==-1 && front==-1)
    {
        printf("Queue empty");
    }
    else if(front==rear)
    {
        val=q[rear];
        front=rear=-1;
    }
    else if(front==n-1)
    {
        val=q[front];
        front=0;
    }
    else{
        val=q[front];
        front++;
    }
}
void display(){
    int i=front;
    while(i!=rear)
    {
        printf("%d\t|",q[i]);
        i=(i+1)%n;
    }
}