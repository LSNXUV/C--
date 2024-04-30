#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;


typedef struct
{
	QueuePtr front;
	QueuePtr rear;	
}LinkQueue;


typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;


int InitStack(SqStack &S)
{
	S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base) exit(-1);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 1;
}


int Push(SqStack &S,int e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
		if(!S.base) exit(-1);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return 1;
}


int Pop(SqStack&S,int &e)
{
	if(S.top==S.base)
		return -1;
	e=*--S.top;
	return 1;
}


int InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(-1);
	Q.front->next=NULL;
	return 1;
}


int EnQueue(LinkQueue&Q,int e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(-2);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}


int DeQueue(LinkQueue &Q,int &e)
{
	if(Q.front==Q.rear) return -1;
	QueuePtr p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return 1;
}


int main()
{
	int len,integer,i;
	LinkQueue q;
	SqStack s;
	InitStack(s);
	InitQueue(q);
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{	scanf("%d",&integer);
		EnQueue(q,integer);
	}
	while(q.rear!=q.front)
	{
		DeQueue(q,integer);
		Push(s,integer);
	}
	while(s.top!=s.base)
	{
		Pop(s,integer);
		printf("%d ",integer);
	}
		
}