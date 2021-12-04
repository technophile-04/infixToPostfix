#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define MAX 50

int stack[MAX];
int topInt = -1;

int isStackFull(){
    return topInt == MAX-1;
}

int sizeInt(){
    return topInt+1;
}

int isEmptyInt(){
    return topInt == -1;
}

void pushInt(int data){

    if(isStackFull()){
        printf("Stack is full");
        return;
    }

    stack[++topInt] = data;

    return;
}

int popInt(){

    if(isEmptyInt()){
        printf("Stack is empty");
        return '!';
    }

    return stack[topInt--];

}

int topsInt(){
    if(isEmptyInt()){
        printf("Stack is empty");
        return '!';
    }

    return stack[topInt];

}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int performOperation(char operator, int a, int b){

    switch(operator){
        case '+': 
            return a+b;
        case '-': 
            return a-b;
        case '*':
             return a*b;
        case '/':  
            return a/b;
        case '^':
            return pow(a , b);
    }

    return -1;

}

int evaluate(char postfix[]){
    int len = strlen(postfix);
    int operand1;
    int operand2;
    int result;

    int i = 0;

    for(i = 0; i < len; i++){

        if(postfix[i] == ' ') continue;

        if(isdigit(postfix[i])){
            
            int sum  = 0;

            while(isdigit(postfix[i])){
                int digit = postfix[i]-'0';
                sum = sum*10 + digit;
                i++;
            }
            i--;
            pushInt(sum);

        }else if(is_operator(postfix[i])){
            operand2 = popInt();
            operand1 = popInt();
            result = performOperation(postfix[i], operand1, operand2);
            pushInt(result);
        }
    }

    return topsInt();

}

int main(){
    int x;
    int ans;
    char  postfix[MAX];
    printf("Please enter numbers and operators seprated by space");
    printf("\n");

    scanf("%[^\n]%*c", postfix);
    ans = evaluate(postfix);
    printf("Evalution of expression is %d", ans);
    printf("\n");

    return 0;
}