#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

char stack[MAX];
int top = -1;

int isStackFull(){

    return top == MAX-1;

}

int size(){
    return top+1;
}

int isEmpty(){
    return top == -1;
}

void push(char data){

    if(isStackFull()){
        printf("Stack is full");
        return;
    }

    stack[++top] = data;

    return;
}

char pop(){

    if(isEmpty()){
        printf("Stack is empty");
        return '!';
    }

    return stack[top--];

}

char tops(){
    if(isEmpty()){
        printf("Stack is empty");
        return '!';
    }

    return stack[top];

}

int precedence(char character){

    switch(character){
        case '(' : 
            return 0;
        case '+' : 
        case '-' : 
            return 1;
        case '*' : 
        case '/' : 
            return 2;
        case '^' :
            return 3;
    }

    return -1;

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

void infixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char element;
	char x;

	push('(');                               
	strcat(infix_exp,")");                  

	i=0;
	j=0;
	element=infix_exp[i];         

	while(element != '\0')        
	{
		if(element == '(')
		{
			push(element);
		}
		else if(isalnum(element))
		{
			postfix_exp[j] = element;              
			j++;
		}
		else if(is_operator(element) == 1)        
		{
			x=pop();
			while(precedence(x)>= precedence(element)) 
			{
                if(precedence(x) == precedence(element) && precedence(x) == 3){
                    break;
                }
				postfix_exp[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);

			push(element);                 
		}
		else if(element == ')')         
		{
			x = pop();               
			while(x != '(')          
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}

		i++;


		element = infix_exp[i]; 
	}
	

	postfix_exp[j] = '\0';
	

}

int main(){

    int ans;
    char infix[MAX], postfix[MAX];

    scanf(" %s", infix);
    infixToPostfix(infix,postfix);          
    printf("Postfix Expression: ");
    printf("%s",postfix);
    printf("\n");

    return 0;
}

