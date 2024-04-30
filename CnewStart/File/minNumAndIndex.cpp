#include <iostream>
using namespace std;



int main(){
    int arr[999],a;
    int b,k = 0;
    cin>>a;
    for(int i = 0;i<a;i++){
        cin>>arr[i];
    }
    b = arr[0];
    for(int j = 0;j<a;j++){
        if(arr[j]<=b){
            b = arr[j];
            k++;
        }
    }
    cout<<b<<endl<<k;
    system("pause");
    return 0;
}