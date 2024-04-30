#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int sum = 0;
    for(int i = 1; i <= n; i++){
        int factorial = 1;
        for(int j = 1; j <= i; j++){
            factorial *= j;
        }
        sum += factorial;
    }
    cout<<sum<<endl;

    system("pause");
    return 0;
}