#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int sum = 0;
    int count = 0;
    for(int i=n;i<=m;i++){
        sum += i;
        if(count%5==0 && count != 0) cout<<endl;
        // printf("%5d",i);
        cout<<setw(5)<<i;
        count++;
    }
    cout<<endl;
    cout<<"Sum = "<<sum;

    system("pause");
    return 0;
}