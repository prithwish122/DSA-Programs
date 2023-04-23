

#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
}Q;

void init(Q *q, int cap)
{
    q->front=q->rear=-1;
    q->capacity=cap;
    q->size=0;
    q->arr=(int*)malloc(cap*sizeof(int));
}
int isempty(Q *q)
{
    return( q->front==-1);
}

int isfull(Q *q)
{
    return(q->front==0 && q->rear==q->capacity-1 || q->rear==q->front-1);
}

void enqueue(Q *q, int item)
{
    if(!isfull(q))
    {
        //q->rear=q->rear+1;
        if(q->rear==q->capacity-1)
            q->rear=0;
       else if(q->rear==-1 && q->front==-1)
          {
            q->front=0;
            q->rear = 0;
          }
          else
          {
              q->rear=q->rear+1;
          }

           q->arr[q->rear]=item;
            q->size=q->size+1;
    }
    else
        printf("\n Queue is full");
    
    
}
int dequeue(Q *q)
{
    int item;
    if(!isempty(q))
    {
        item=q->arr[q->front];
        q->size--;
        if(q->front==q->rear)   //for last element
        {
            q->front=q->rear=-1;
        }
        else if(q->front==q->capacity-1)                   //for normal deletion
        {
                q->front=0;
        }
        else
          q->front++;
        return item;
    }  
    else
        return 404;
}

int main()
{
    Q q;
    int n,a ;
    init(&q,4);
    do
    {
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Exit");
        printf("\n Enter your choice: ");;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("\n Enter any numner: ");
                scanf("%d",&a);
                enqueue(&q,a);
                printf("\nItems in Queue: %d",q.size);
                break;
            case 2:
                printf(" \n Deq Operation: %d",dequeue(&q));
                printf("\n  Items in Queue: %d",q.size);
                break;
            case 3:printf("::BYE::");
        }
    }while(n!=3);
    
}