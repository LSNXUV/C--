#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,i,j = 0;
    char c;
    cin>>n>>c;
    i = max((int)sqrt(n/2),1);
    for(int k = 2*i-1;k >=1 ;k-=2){
        for(int p = j;p > 0;p--) cout<<" ";
        for(int s = k;s > 0;s--) cout<<c;
        j++;
        cout<<endl;
    }
    j-=2;
    for(int k = 3;k <= 2*i-1 ;k+=2){
        for(int p = j;p > 0;p--) cout<<" ";
        for(int s = k;s > 0;s--) cout<<c;
        j--;
        cout<<endl;
    }
    cout<<n - 2 * i * i + 1; 
    return 0;
}
