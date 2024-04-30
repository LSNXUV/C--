#include <iostream>
using namespace std;

typedef struct
{
    int a[100];
    int length;
} SqList;

bool Delete(SqList *L,int n,int &m){
    int j;
    if(n<1 || n>L->length){
        return false;
    }
    n--;
    m = L->a[n];
    for(j = n;j<L->length-1;j++)
        L->a[j]=L->a[j+1];
    L->length--;
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

    cin>>n;
    if(Delete(sq,n,m)){
        for(i = 0;i<sq->length;i++){
            cout<<sq->a[i]<<" ";
        }
        cout<<endl<<m;
    }else{
        cout<<"The delete location does not exist"<<endl<<sq->length;
    }

    system("pause");
    return 0;
}