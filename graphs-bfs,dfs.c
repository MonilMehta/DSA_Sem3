#include<stdio.h>
#define n 10

int q[n],f=-1,r=-1,top=-1,stack[n],graph[n][n],vis[n];

void enqueue(int x)
{
    if(f==0 && r==n-1)
        printf("Queue FUll");
    else if(f==-1 && r==-1)
    {
        f=r=0;
        q[r]=x;
    }
    else{
        q[++r]=x;
    }
}
int dequeue()
{
    int x;
    if(f==-1 && r==-1)
    {
        return -1;
    }
    else if(f==r && f!=-1)
    {
        return q[f];
        f=r=-1;
    }
    else{
        return q[f++];
    }

}

void push(int vgraphl) {
    if (top == n - 1) {
        printf("Stack full");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    int val;

    if (top == -1)
        return -1;
    else {
        val = stack[top--];
        return val;
    }
}
void bfs(int s,int m)
{
    int p,i;
    enqueue(s-1);
    vis[s-1]==1;
    p=dequeue();
    if(p!=-1)
        printf("%d \t",p+1);
    while(p!=-1)
    {
        for(i=0;i<m;i++)
        {
            while(a[p][i]!=0 && vis[i]==0)
            {
                enqueue(i);
                vis[i]==1;
            }
        }
        p=dequeue();
        if(p!=-1)
            printf("%d \t",p+1);
    }
}
void dfs(int s,int m)
{
    int p,i;
    push(s-1);
    vis[s-1]==1;
    p=pop();
    if(p!=-1)
        printf("%d \t",p+1);
    while(p!=-1)
    {
        for(i=0;i<m;i++)
        {
            while(a[p][i]!=0 && vis[i]==0)
            {
                push(i);
                vis[i]==1;
            }
        }
        p=pop();
        if(p!=-1)
            printf("%d \t",p+1);
    }
    for(i=0;i<m;i++)
    {
        if(vis[i]==0)
            dfs(i,n);
    }
}
int main() {
     int vert, i, source, ch, j, choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    for (i = 0; i < vert; i++) {
        for (j = 0; j < vert; j++) {
            printf("Enter 1 if %d has an edge with %d : ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Adjacency Matrix is : \n");
    for (i = 0; i < vert; i++) {
        for (j = 0; j < vert; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    do {
        for (i = 1; i <= vert; i++)
            vis[i] = 0;

        printf("\nMenu");
        printf("\n1. B.F.S");
        printf("\n2. D.F.S");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        printf("Enter the source vertex: ");
        scanf("%d", &source);

        switch (ch) {
        case 1:
            bfs(source, graph);
            break;
        case 2:
            dfs(source, graph);
            break;
        default:
            break;
        }
        printf("\nDo you want to continue(1/0)? ");
        scanf(" %d", &choice);

    } while (choice != 0);
    return 0;

}