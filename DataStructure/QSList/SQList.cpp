#include <iostream>

#define MaxSize 200
using namespace std;

typedef struct Queue
{
    int data[MaxSize];
    int front, rear;
} SqQueue;

typedef struct Stack
{
    int data[MaxSize];
    int top;
} SqStack;

void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

bool InQueue(SqQueue *&q, int e)
{
    if ((q->rear + 1) % MaxSize == q->front)
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

bool OutQueue(SqQueue *&q, int *e)
{
    if (q->front == q->rear)
        return false;

    q->front = (q->front + 1) % MaxSize;
    *e = q->data[q->front];
    return true;
}

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

//进栈
bool Push(SqStack *&s, int e)
{

    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

int Pop(SqStack *&s)
{
    if (s->top == -1)
        return 0;

    return s->data[s->top--];
}

int GetTop(SqStack *&s)
{

    if (s->top == -1)
        return 0;
    return s->data[s->top];
}

int main()
{

    system("pause");
    return 0;
}
