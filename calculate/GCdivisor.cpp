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
    cout<<"请输入两个数:";
    cin>>x>>y;
    
    cout<<"最大公约数:"<<gcd(x,y)<<endl;
    cout<<"最小公倍数:"<<x*y/gcd(x,y);
    
    system("pause");
    return 0;
}