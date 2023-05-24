#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
          

typedef struct stack{
	int top;
	int size;
	char* arr;
}stack;


void init(stack* ptr, int size){
	ptr->size = size;
	ptr->top = -1;
	ptr->arr = (char*)malloc(size*sizeof(char));
}


void push(stack* ptr, int item){
	ptr->arr[++ptr->top] = item;
}

int isempty(stack* ptr){
	return (-1 == ptr->top);
}

char pop(stack* ptr){
	if(!isempty(ptr))
		return ptr->arr[ptr->top--];
}


int isoperator(char ch){
	if(ch == '^' || ch == '/' || ch == '*' || ch == '%' || ch == '+' || ch == '-')
		return 1;
	else
		return 0;
}


char peek(stack* s){
	return s->arr[s->top];
}

//function for opeation
char operation(char a, char b, char operator){
	char res;
	if(operator == '^')
		res = (a-48) ^ (b-48);
	else if(operator == '/')
		res = (a-48) / (b-48);
	else if(operator == '*')
		res = (a-48) * (b-48);
	else if(operator == '%')
		res = (a-48) % (b-48);
	else if(operator == '+')
		res = (a-48) + (b-48);
	else if(operator == '-')
		res = (a-48) - (b-48);
 	return (res+48);
}

//function to evaluate postfix expression
void postfixEval(stack* s, char* postfix){
	char a, b, c;
	int i, ilen = strlen(postfix);
	for(i=0; i<ilen; i++){
		if(isalnum(postfix[i]))
			push(s, postfix[i]);
		else if(isoperator(postfix[i])){
			a = pop(s);
			b = pop(s);
			c = operation(b,a,postfix[i]);
			push(s,c);
		}
	}
}

int main(){
	stack st; //stack storing the operators
	init(&st, 100);
	char postfix[100];

    printf("Enter postfix expression: ");
	gets(postfix);

	postfixEval(&st, postfix);
	printf("\nAnswer = %c\n",peek(&st));
	return 0;
}
