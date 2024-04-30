#include <iostream>
using namespace std;


typedef struct {
	int data[100];
	int length;
}SqList;


int removeSame1(SqList *B) {				//解法一
    int index = 1;
 
    for (int i = 1; i < B->length; i++) {
        if (B->data[i] != B->data[index-1])
            B->data[index++] = B->data[i];
    }
    return index;
}


int main(){
    SqList *sq;
    sq = (SqList *)malloc(sizeof(SqList));
    int n,i;
    cin>>sq->length;
    n = sq->length;
    for(i = 0;i<n;i++){
        cin>>sq->data[i];
    }
    int len = removeSame1(sq);

    for(i = 0;i<len;i++){
        cout<<sq->data[i]<<" ";
    }
    

    system("pause");
    return 0;
}