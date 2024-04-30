#include <iostream>
using namespace std;

typedef struct
{
    int data[10000];
    int length;
} SqList;

int main()
{
    SqList *L;
    L = (SqList *)malloc(sizeof(SqList));
    int k ,m = 0,i = 0,n = 0;
    while (cin >> k)
    {
        if( k > m ){
            m = k;
        }
        L->data[i++] = k;
        n++;
        if (cin.get() == '\n') break;
    }
    L->length = n;

    cout<<"测试结果："<<endl;
    cout<<"原始数据：";
    for(i = 0;i<L->length;i++){
        cout<<L->data[i]<<"  ";
    }
    cout<<endl;
    cout<<"原始顺序表L:";
    for(i = 0;i<L->length;i++){
        cout<<" "<<L->data[i];
    }
    cout<<endl<<"删除最大元素值后的顺序表L:";
    for(i = 0;i<L->length;i++){
        if(L->data[i] == m){
            continue;
        }
        cout<<" "<<L->data[i];
    }

    system("pause");
    return 0;
}