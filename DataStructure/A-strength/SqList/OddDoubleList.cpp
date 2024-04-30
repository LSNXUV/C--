#include <iostream>
using namespace std;


typedef struct
{
    int data[1000];
    int length;
} SqList;


int main(){
    SqList *L;
    L = (SqList *)malloc(sizeof(SqList));
    int k ,m = 0,i = 0,n = 0;
    while (cin >> k)
    {
        if( k > m ) m = k;

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
    cout<<"初始顺序表L: ";
    for(i = 0;i<L->length;i++){
        cout<<" "<<L->data[i];
    }
    cout<<endl<<"拆分后："<<endl;
    cout<<"奇数顺序表L: ";
    for(i = 0;i<L->length;i++){
        if(L->data[i]%2!=0)
        cout<<" "<<L->data[i];
    }
    cout<<endl<<"偶数顺序表L1:";
    for(i = 0;i<L->length;i++){
        if(L->data[i]%2==0)
        cout<<" "<<L->data[i];
    }

    system("pause");
    return 0;
}