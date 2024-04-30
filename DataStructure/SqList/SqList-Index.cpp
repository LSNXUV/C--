#include <iostream>
using namespace std;

typedef struct
{
    int a[200];
    int length;
} sqList;



int main(){
    sqList *sq;
    sq = (sqList *)malloc(sizeof(sqList));

    int k,i,n;

    cin>>sq->length;
    int l = sq->length;

    for(i = 0;i<l;i++){
        cin>>k;
        sq->a[i] = k;
    }

    cin>>n;
    

    for(i = 0;i<l;i++){
        cout<<sq->a[i];
        cout<<" ";
    }
    cout<<endl;
    if(n>l || n<1){
        cout<<l<<endl;
        cout<<"The location does not exist";
    }else{
        cout<<sq->a[n-1];
    }
    system("pause");
    return 0;
}