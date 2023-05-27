#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
           

typedef struct stack
{
    int Top;
    int size;
    char *arr;

}stack;

void init(stack *s,int size)
{
    s->Top=-1;
    s->size=size;
    s->arr=(char*)malloc(size*sizeof(char));
}


int isfull(stack *s)
{
    return(s->Top==s->size-1);
}

void push(stack *s,char item)
{
    int full=isfull(s);
    if(full==0)
    {
        s->arr[++s->Top]=item;
    }

}

int isempty(stack *s)
{
    return(s->Top==-1);
}

char pop(stack*s)
{
    int empty=isempty(s);
    if(empty==0)
    return (s->arr[s->Top--]);

}

int isoperator(char ch)
{
    return (ch=='+'|| ch=='-' || ch=='*' || ch=='/' ||ch=='^'|| ch=='%');
}
 int precedence(char ch)
 {
    if(ch=='^')
    return (3);
    else if(ch=='*'||ch=='/'|| ch=='%')
    return (2);
    else if(ch=='+' || ch=='-')
    return (1);
    else
    return (0);

 }

 char peek(stack *s)
 {
    return(s->arr[s->Top]);
 }
char *infix_to_postfix(char *inf,stack *s)
{
    int i,j;
    int ilen=strlen(inf);
    char *pf=(char*)malloc(ilen*sizeof(char));
    for(int i=0,j=0;i<ilen;i++)
    {
        if(inf[i]==' '||inf[i]=='\t')
        {
            continue;
        }
        else if(isalnum(inf[i]))
        {
            pf[j++]=inf[i];

        }

        else if(inf[i]=='(')
        {
            push(s,inf[i]);
        }
        else if(inf[i]==')')
        {
            while(peek(s)!='(' && s->Top >-1)
            {
                pf[j++]=pop(s);
            }
            if(s->Top==-1)
            {
                return("Invalid expression\n");

            }
            else
            s->Top--;
        }
        else if(isoperator(inf[i]))
        {
            while(precedence(inf[i])<=precedence(peek(s)) && s->Top-1)
            {
                pf[j++]=pop(s);
            }
            push(s,inf[i]);
        }
    }
    while(s->Top>-1)
    {
        if(peek(s)=='(')
        return "invalid statement";
        else
        pf[j++]=pop(s);

    }
    pf[j]='\0';
    return(pf);
}


int main()
{
	stack s1;
	init(&s1,100);//init(&s1,20);
	char infix[100];//char infix[20]="a+b+(c*d)+e/f";
	
	printf("Enter the Infix Expression: ");
	gets(infix);//scanf("%s",infix);
	char *postfix = infix_to_postfix(infix,&s1);
	printf("The Postfix Expression: %s\n",postfix);
	return 0;
}



