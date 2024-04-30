#include <iostream>
using namespace std;

typedef struct
{
    int a[100];
    int length;
} SqList;

bool Insert(SqList *L,int n,int m){
    int j;
    if(n<1 || n>L->length){
        return false;
    }
    n--;
    for(j = L->length;j>n;j--)
        L->a[j]=L->a[j-1];
    L->a[n] = m;
    L->length++;
    return true;
}

int main(){
    SqList *sq;
    sq = (SqList *)malloc(sizeof(SqList));

    int n,k,i,m;

    cin>>sq->length;
    int l = sq->length;

    for(i = 0;i<l;i++){
        cin>>k;
        sq->a[i] = k;
    }

    cin>>n>>m;
    if(Insert(sq,n,m)){
        for(i = 0;i<sq->length;i++){
            cout<<sq->a[i]<<" ";
        }
    }else{
        cout<<"The insertion position does not exist"<<endl;
        cout<<sq->length;
    }

    system("pause");
    return 0;
}