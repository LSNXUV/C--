#include <iostream>
#include <stack>
using namespace std;

#define MaxSize 200

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

//进栈
bool Push(SqStack *&s, int e)
{
    if(s->top == MaxSize-1) 
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

int Pop(SqStack *&s)
{
    if(s->top == -1) return 0;

    return s->data[s->top--];

}

int GetTop(SqStack *&s)
{
	if(s->top == -1) return 0;
	return s->data[s->top];
}

int main(){
    int n;
    SqStack *num;
    stack<string> oprs;
    InitStack(num);

    cin>>n;
    for(int i = 0;i<n;i++){
        string opr;
        int number;
        cin>>opr>>number;
        Push(num,number);
        oprs.push(opr);
    }
    int first;
    cin>>first;
    Push(num,first);

    while (!oprs.empty())
    {
        int a = GetTop(num);Pop(num);
        int b = GetTop(num);Pop(num);

        string c = oprs.top();oprs.pop();

        if (c == "Mul"||c == "mul") {
            Push(num,a * b);
        }
        else if (c == "Add"||c == "add") {
            Push(num,a + b);
        }
        else if (c == "Sub"||c == "sub") {
            Push(num,a - b);
        }
        else {
            Push(num,a);
            Push(num,b);
            cout<<"0";
        }
    }

    cout<<GetTop(num);
    
    system("pause");
    return 0;
}