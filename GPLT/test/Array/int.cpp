#include <iostream>

using namespace std;

int arr[11];

int main(){
    for(int i = 0; i < 10; i++){
        arr[i] = i;
    }
    cout<<"length of arr: "<<sizeof(arr)/sizeof(arr[0])<<endl;
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    system("pause");
    return 0;
}