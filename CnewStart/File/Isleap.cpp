#include <iostream>
using namespace std;

bool is_leap_year(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


void outLeap(){
    int a,b;
    int c = 0;
    cin>>a>>b;
    for(int i = a;i<=b;i++){
        if(is_leap_year(i)){
            cout<<i<<" ";
            c++;
            if(c%5==0){
                cout<<endl;
            }
        }
    }
    cout<<endl;
}

int main(){
    outLeap();
    system("pause");
    return 0;
}