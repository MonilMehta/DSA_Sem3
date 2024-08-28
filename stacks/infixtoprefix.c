#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define n 10
char stack[n],exp[n];
int top=-1;

void push(char val)
{
    if(top==-1)
        stack[++top]=val;
    else if(top==n-1)
        printf("Overflow");
    else
        stack[++top]=val;
}

char pop()
{
    char p;
    if(top==-1)
        p=-1;
    else
        p=stack[top--];
    return p;
}

int isOperand(char c)
{
    if(c=='+'||c=='-'||c=='%'||c=='*'||c=='/') 
        return 1;
    else
        return 0;
}

int getPriority(char c)
{
    if(c=='+'||c=='-')
        return 1;
    else if(c=='/'||c=='*')
        return 2;
    else 
        return 0;
}

void infixToPostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    char temp;
    strcpy(postfix,"");
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else if(infix[i]=='(')
        {
            push(infix[i++]);
        }
        else if(infix[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
                postfix[j++]=pop();
            if(top!=-1)
                temp=pop();
            else
                i++;
        }
        else if(isOperand(infix[i]))
        {
            while(top!=-1 && stack[top]!='(' && (getPriority(stack[top])>=getPriority(infix[i])))
            {
                postfix[j++]=pop();
            }
            push(infix[i++]);
        }   
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
void reverse(char infix[])
{
    int i=0,j=0;
    for(i=strlen(infix)-1;i>=0;i++)
    {
    if(infix[i]=='(')
        exp[j++]=')';
    else if(infix[i]==')')
        exp[j++]='(';
    else
        exp[j++]=infix[i];
    
    }
}
int main(){
    char infix[100], postfix[100];
    printf("Enter Infix: ");
    gets(infix);
    strcpy(exp,"");
    reverse(infix);
    infixToPostfix(exp,postfix);
    printf("The corresponding Postfix is: %s\n", postfix);
    reverse(postfix);
    printf("The corresponding Prefix is: %s\n", exp);
    return 0;
}
