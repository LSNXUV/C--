#include <iostream>
using namespace std;

int main(){
    int a , b;
    cin>>a>>b;
    cout<<1000*(a%10)+100*(b%10)+10*(a/10)+b/10;
    return 0;
}