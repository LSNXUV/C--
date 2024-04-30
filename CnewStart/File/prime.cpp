#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n){
    if(n==1)
    {
        return false;
    }
    if(n==2||n==3){
        return true;
    }
    for(int i = 2;i<=sqrt(n);i++)
    {
        if((n % i) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int a,b;
    int k = 0;
    cin>>a>>b;
    for(int i = a;i<=b;i++){
        if(isprime(i)){
            cout<<i<<" ";
            k++;
        }
        if(k==8){
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}