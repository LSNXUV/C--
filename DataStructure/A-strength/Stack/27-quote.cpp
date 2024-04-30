#include <iostream>
using namespace std;

#define  MaxSize 100

typedef struct Stack
{
    char data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *&s)
{

    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

void Push(SqStack *&s,char n)
{
    s->top++;
    s->data[s->top] = n;
}

char Pop(SqStack *&s)
{
    if(s->top == -1) {
        // cout<<"error ";
        return '1';
    }
    return s->data[s->top--];
}

int main(){
    SqStack *s;
    InitStack(s);
    char k;
    while(cin>>k)
    {
        if(k=='#') break;
        if(k == '(' || k == ')' || k == '[' || k == ']' || k == '{' || k == '}')
        {
            Push(s,k);
        }
        if(s->data[s->top] == ')' && s->data[s->top-1] == '(')
        {
            Pop(s),Pop(s);
        }
        if(s->data[s->top] == ']' && s->data[s->top-1] == '[')
        {
            Pop(s),Pop(s);
        }
        if(s->data[s->top] == '}' && s->data[s->top-1] == '{')
        {
            Pop(s),Pop(s);
        }
    }
    if(s->top==-1) cout<<"1";
    else cout<<"0";
    system("pause");
    return 0;
}