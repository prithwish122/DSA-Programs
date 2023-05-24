#include <stdio.h>
#include <stdlib.h>


typedef struct stack{
	int top;
	int size;
	int* arr;
}stack;


void init(stack* ptr, int size){
	ptr->size = size;
	ptr->top = -1;
	ptr->arr = (int*)malloc(size*sizeof(int));
}

//function to check stack is full or not
int isfull(stack* ptr){
	return (ptr->top == ptr->size-1);
}

//function for pushing element in stack
void push(stack* ptr, int item){
	if(!isfull(ptr))
		ptr->arr[++ptr->top] = item;
	else
		printf("\nStack Overflow!\n");
}

//function to check stack is empty or not
int isempty(stack* ptr){
	return (ptr->top == -1);
}

//function for popping element from stack
int pop(stack* ptr){
	if(isempty(ptr))
		return -1;
	else
		return ptr->arr[ptr->top--];
}

//function for displaying elements in stack
void display(stack* ptr, int length){
	int i;
	for(i=ptr->top; i>-1; i--)
		printf("%d\n",ptr->arr[i]);
}

void peek(stack* ptr){
	printf("%d\n",ptr->arr[ptr->top]);
}

int main(){
	stack s1;
	int len, val, choice, x;
	printf("Enter number of elements: ");
	scanf("%d",&len);
	init(&s1,len);
	
	while(1){
		printf("\nCHOICES-\n1. for push\n2. for pop\n3. for display\n4. for peek\n0. for exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter item to push (DO NOT ENTER -1): ");
				scanf("%d",&val);
				push(&s1,val);
				break;
			
			case 2:
				x = pop(&s1);
				if(x == -1)
					printf("\nStack Underflow!\n");
				else
					printf("\n%d is popped\n",x);
				break;
				
			case 3:
				display(&s1,s1.top+1);
				break;
			
			case 4:
				peek(&s1);
				break;

			case 0:
				exit(0);
				
			default:
				printf("\nInvalid choice\n");
		}
	}
	
	return 0;
}
