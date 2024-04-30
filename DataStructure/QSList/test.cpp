#include <iostream>
#include <string>
using namespace std;


#define MaxSize 200

typedef struct sStack
{
    string data[MaxSize];
    int top;
} SStack;

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

void InitSStack(SStack *&s)
{
    s = (SStack *)malloc(sizeof(SStack));
    s->top = -1;
}

//进栈
bool Push(SqStack *&s, int e)
{
    if(s->top == MaxSize-1) 
        return false;
    s->top++;
    cout<<endl<<e<<endl;
    s->data[s->top] = e;
    cout<<s->data[s->top]<<endl;
    return true;
}
bool SPush(SStack *&s, string str)
{
    if(s->top == MaxSize-1) 
        return false;
    s->top++;
    cout<<s->top<<" "<<str<<endl;
    s->data[s->top] = str;
    cout<<s->data[0];
    return true;
}


int Pop(SqStack *&s)
{
    if(s->top == -1) return 0;

    return s->data[s->top--];

}
string SPop(SStack *&s)
{
    if(s->top == -1) return 0;

    return s->data[s->top--];

}

int GetTop(SqStack *&s)
{
	if(s->top == -1) return 0;
	return s->data[s->top];
}
string SGetTop(SStack *&s)
{
	if(s->top == -1) return 0;
	return s->data[s->top];
}


int main(){
    int n;
    SqStack *num;
    SStack *openr;

    InitStack(num);
    InitSStack(openr);

    cin>>n;
    for(int i = 0;i<n;i++){
        string opr;
        int number;
        cin>>opr>>number;
        Push(num,number);
        SPush(openr,opr);
        
        cout<<"top:"<<num->top<<openr->top<<endl;
    }
    int first;
    cin>>first;
    Push(num,first);



    system("pause");
    return 0;
}