#include <iostream>
using namespace std;

typedef struct
{
    int a[100];
    int length;
} SqList;

int Find(SqList *L,int n){
    int i =0;
    while (i<L->length && L->a[i]!=n) i++;
    if(i>=L->length) return 0;
    else return i+1;
}

int main(){
    SqList *sq;
    sq = (SqList *)malloc(sizeof(SqList));

    int n,k,i;

    cin>>sq->length;
    int l = sq->length;

    for(i = 0;i<l;i++){
        cin>>k;
        sq->a[i] = k;
    }

    cin>>n;
    if(Find(sq,n) != 0){
        for(i = 0;i<sq->length;i++){
            cout<<sq->a[i]<<" ";
        }
        cout<<endl<<Find(sq,n);
    }else{
        cout<<"no";
    }

    system("pause");
    return 0;
}