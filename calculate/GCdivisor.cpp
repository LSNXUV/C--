#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll x,ll y){
    return y?gcd(y,x%y):x;
}

ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}

int main(){
    ll x,y;
    cout<<"������������:";
    cin>>x>>y;
    
    cout<<"���Լ��:"<<gcd(x,y)<<endl;
    cout<<"��С������:"<<x*y/gcd(x,y);
    
    system("pause");
    return 0;
}