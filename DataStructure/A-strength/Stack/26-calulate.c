#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  MaxSize 100

typedef struct Stack
{
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *s)
{

    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
    
}

void Push(SqStack *s,int n)
{
    s->top++;
    s->data[s->top] = n;
    
}

int Pop(SqStack *s)
{
    if(s->top == -1) {
        return -1;
    }
    return s->data[s->top--];
}


int main(){
    SqStack s;
    s.top = -1;
    InitStack(&s);
    char k[100];
    while(scanf("%s",k))
    {
        if(k[0] == '#') break;

        int n = 0,i;
        if(k[0] >= '0' && k[0] <= '9')
        {
            //转换数字
            for(i = 0;i<strlen(k);i++)
            {
                n+=(k[i]-'0')*pow(10,strlen(k)-1-i);
            }
            Push(&s,n);
        }else{
            int a = Pop(&s);
            int b = Pop(&s);
            if(k[0] == '+')
            {
                Push(&s,b+a);
            }
            else if(k[0] == '-')
            {
                Push(&s,b-a);
            }
            else if(k[0] == '*')
            {
                Push(&s,b*a);
            }
            else if(k[0] == '/')
            {
                Push(&s, b/a);
            }
        }   
    }
    printf("%d",Pop(&s));
    return 0;
}