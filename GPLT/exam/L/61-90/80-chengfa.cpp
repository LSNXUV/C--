#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    
    int *arr = new int[c*2];
    arr[0] = a;
    arr[1] = b;
    int aIndex = 0;
    int count = 2;
    while(aIndex < c){
        cout<<(aIndex > 0 ? " " : "")<<arr[aIndex];
        int ten = (a*b)/10;
        if(ten != 0){
            arr[count++] = ten;
        }
        arr[count++] = (a*b)%10;
        a = arr[++aIndex];
        b = arr[aIndex+1];
    }
    // system("pause");
    return 0;
}
