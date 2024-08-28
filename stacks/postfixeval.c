#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 10
char stack[SIZE];
int top=-1;
void push(int val){
    if(top==SIZE-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top]=val;
    }
}
int pop(){
    int val;
    if(top==-1){
        printf("Stack empty");
    }
    else{
        val=stack[top];
        top--;
    }
    return val;
}
int postfixeval(char exp[])
{
    int result,i=0,op1,op2;
    char ch;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i]-'0');
            i++;
        }
        else{
            ch=exp[i];
            op1=pop();
            op2=pop();
            switch(ch)
            {
                case '+':
                    result=op1+op2;
                    break;
                case '-':
                    result=op1-op2;
                    break;
                case '/':
                    result=op2/op1;
                    break;
                case '*':
                    result=op1*op2;
                    break;
                default:
                    break;
            }
            push(result);
            i++;
        }
    }
    return pop();
}
void main(){
    char postfix[100];
    int ans;

    printf("Enter Postfix Expression :");
    gets(postfix);

    ans=postfixeval(postfix);

    printf("Ans is %d ",ans);
}