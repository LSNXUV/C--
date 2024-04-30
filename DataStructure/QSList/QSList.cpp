
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

void InitQueue(SqQueue *&q){
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;

}
bool InQueue(SqQueue *&q,int e){
    if((q->rear+1) % MaxSize == q->front)
        return false;
    q->rear = (q->rear+1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}


bool Push(SqStack *&s, int e)
{

    if(s->top == MaxSize-1) 
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;

}

//初始化队列
void InitQ(SqQueue *Q){
    int k;
    cout<<"请输入要测试的数据(队列):"<<endl;
    while(cin>>k)
    {
        InQueue(Q,k);
        if(cin.get() == '\n') break;
    }
    cout<<endl<<"初始化队列成功！"<<endl;
}
//初始化栈
void InitS(SqStack *S){
    int k;
    cout<<"请输入要测试的数据(栈):"<<endl;
    while(cin>>k)
    {
        Push(S,k);
        if(cin.get() == '\n') break;
    }
    cout<<endl<<"初始化栈成功！"<<endl;
}
//入列
void InQ(SqQueue *&q)
{
    int n;
    cout<<"请输入要入队的元素:";
    cin>>n;
    if((q->rear+1) % MaxSize == q->front)
    {
        cout<<"error"<<endl;
        return;
    }
    q->rear = (q->rear+1) % MaxSize;
    q->data[q->rear] = n;

}
//入栈
void InS(SqStack *&s)
{
    int n;
    cout<<"请输入要入栈的元素:";
    cin>>n;
    if(s->top == MaxSize-1) 
    {
        cout<<"error"<<endl;
        return;
    }
    s->top++;
    s->data[s->top] = n;

}
//出队
void OutQ(SqQueue *&q)
{
    if(q->front == q->rear){
        cout<<"error"<<endl;
        return;
    }

    q->front = (q->front+1) % MaxSize;
    cout<<"当前出队元素为："<<q->data[q->front]<<endl;

}
//出栈
void OutS(SqStack *&s)
{
    if(s->top == -1){
        cout<<"error"<<endl;
        return;
    }
    cout<<"当前出栈元素为："<<s->data[s->top--]<<endl;

}

void Gettop(SqStack *&s){

    cout<<"当前栈顶元素为："<<s->data[s->top]<<endl;

}

//输出主界面
void welcome(SqQueue *&Q,SqStack *&S)
{

    system("cls");

    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓  ☆      栈和队列测试系统      ☆  〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆            1.出队          ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆            2.出栈          ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆            3.入队          ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆            4.入栈          ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆            5.栈顶          ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          0.退出系统        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆                            ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

    InitQ(Q);
    InitS(S);

}


int main()
{

    SqQueue *Q;
    SqStack *S;
    int choice;
    InitStack(S);
    InitQueue(Q);

    welcome(Q,S);
    while (1)
    {
        cout<<"请输入操作的序号:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            OutQ(Q);
            continue;
        case 2:
            OutS(S);
            continue;
        case 3:
            InQ(Q);
            continue;
        case 4:
            InS(S);
            continue;
        case 5:
            Gettop(S);
            continue;
        case 0:
            break;
        default:
            continue;
        }

    }
    
    system("pause");
    return 0;
}
