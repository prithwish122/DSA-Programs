#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int top;
    int size;
    int *arr;

}stack;



void init(stack *p,int size)
{
    p->top=-1;
    p->size=size;
    p->arr=(int*)malloc(size*sizeof(int));
}


int isfull(stack *p)
{
    if(p->top==p->size-1)
    return 1;
    else 
    return 2;
}

void push(stack *p, int item)
{

}

int main()
{
    stack s1;
    int x;
    init(&s1,5);
    int status=push(&s1,17);
    x=isfull(&s1);
}