#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define SIZE 10
char stack[SIZE];
int top=-1;

void push(char val){
    if(top==SIZE-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top]=val;
    }
}
char pop(){
    char val;
    if(top==-1){
        printf("Stack empty");
        return '\0';
    }
    else{
        val=stack[top];
        top--;
    }
    return val;
}
int isoperand(char ch){
    return (ch=='+' || ch=='-' ||ch=='*' || ch=='/' ||ch=='%');
}
int getPriority(char c){
    if(c=='*'||c=='%'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    return 0;
}
void InfixtoPostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    char temp;
    strcpy(postfix,"");
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(' && top!=-1)
            {
                postfix[j]=pop();
                j++;
            }
            if(top==-1)
            {
                printf("Incorrect");
            }
            temp=pop();
            i++;
        }
        else if(isalpha(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else if(isoperand(infix[i]))
        {
            if(top!=-1 && stack[top]!='(' && (getPriority(stack[top])>=getPriority(infix[i])))
            {
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
            i++;
        }
        else
            printf("Incorrect");
    }
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
}

void main()
{
    char infix[100],postfix[100];
    printf("Enter Infix Exp : ");
    gets(infix);
    InfixtoPostfix(infix,postfix);
    printf("Postfix is : ");
    puts(postfix);
}