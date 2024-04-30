#include <iostream>
#include <string>
using namespace std;

#define  MaxSize 100

typedef struct Stack
{
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *&s)
{

    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

void Push(SqStack *&s,int n)
{
    s->top++;
    s->data[s->top] = n;
}

int Pop(SqStack *&s)
{
    if(s->top == -1) {
        cout<<"error ";
        return -1;
    }
    return s->data[s->top--];
}

int main(){
    SqStack *s;
    InitStack(s);
    string k;
    while(cin>>k)
    {
        if(k[0] >= '0' && k[0] <= '9')
        {
            Push(s,stoi(k));
        }else{
            int a = Pop(s);
            int b = Pop(s);
            if(k[0] == '+')
            {
                Push(s,b+a);
            }
            else if(k[0] == '-')
            {
                Push(s,b-a);
            }
            else if(k[0] == '*')
            {
                Push(s,b*a);
            }
            else if(k[0] == '/')
            {
                Push(s, b/a);
            }
        }   
        if(k[1] == '#') break;
    }
    cout<<Pop(s);
    system("pause");
    return 0;
}