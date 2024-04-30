#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int n;
    cin >> n;
    int maxLen = 0;
    int maxStart = 0;
    for(int i = 2;i < sqrt(n);i++){
        int temp = n;
        int j = i;
        while(temp % j == 0){
            temp /= j;
            j++;
        }
        if((j-i) > maxLen){
            maxLen = j - i;
            maxStart = i;
        }
    }
    if(maxLen == 0){
        maxLen = 1;
        maxStart = n;
    }
    cout<<maxLen<<endl;
    cout<<maxStart;
    for(int i = 1;i < maxLen;i++){
        cout<<"*"<<i+maxStart;
    }

    // system("pause");
    return 0;
}