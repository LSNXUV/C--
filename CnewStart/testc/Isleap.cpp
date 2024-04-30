#include <iostream>
using namespace std;

bool is_leap_year(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        return true;
    }
    return false;
}
void outLeap(){
    int a,b;
    int c = 0;
    cout<<"请输入两个年份:"<<endl;
    cin>>a>>b;
    for(int i = a;i<=b;i++){
        if(is_leap_year(i)){
            cout<<i<<"\t";
            c++;
            if(c%4==0){
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