#include <iostream>
#include <cmath>
using namespace std;


int sq(int n,int k){
    if(n==1){
        return 1;
    }
    return pow(n,k)+sq(n-1,k);
}

int main(){

    int n,k;
    cout<<"ÇëÊäÈënºÍk:"<<endl;
    cin>>n>>k;
    cout<<"result:"<<sq(n,k);

    system("pause");
    return 0;
}