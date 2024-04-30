#include <iostream>
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

void Pop(SqStack *&s)
{
    if(s->top == -1) {
        cout<<"error ";
        return;
    }
    cout<<s->data[s->top--]<<" ";
}
int main(){
    int k;
    SqStack *s;
    InitStack(s);
    while(cin>>k)
    {

        if(k == 1){
            int n;
            cin>>n;
            Push(s,n);
        }
        else if (k == 0)
        {
            Pop(s);
        }
        
        if(cin.get() == -1) break;
    }
    system("pause");
    return 0;
}