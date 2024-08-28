#include<stdio.h>
#include<string.h>
#define SIZE 10
char stack[SIZE];
int top=-1;
void push(char c)
{
    if(top==SIZE-1)
        printf("Stack Overflow");
    else
        stack[++top]=c;
}
char pop(){
    char val;
    if(top==-1){
        printf("Stack underflow");
        val='\0';
    }
    else
    {
        val=stack[top];
        top--;
    }
    return val;
}
void main()
{
    int flag=1,i=0;
    char exp[SIZE],temp;
    printf("Enter Expression : ");
    gets(exp);

     for(i=0;i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(exp[i]);
        }
        if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(top==-1)
                {flag=0;}
            else{
            temp=pop();
            if(exp[i]==')' && (temp=='['||temp=='{'))
                flag=0;
            if(exp[i]==']' && (temp=='('||temp=='{'))
                flag=0;
            if(exp[i]=='}' && (temp=='['||temp=='('))
                flag=0;
            }
        }
    }
    if(top>=0)
        flag=0;
    if(flag==1)
        printf("\nExpression is balanced");
    else
        printf("\nNot balanced");
}