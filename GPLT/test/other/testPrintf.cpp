#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



int main(){
    string s = "test";
    int num = 123;

    //用0填充，总长度为15
    printf("%015s",s.c_str());
    cout<<endl;
    printf("%015d",num);

    //用5填充，总长度为15
    printf("%515s",s.c_str());// 不可行！！！
    cout<<endl;
    cout<<setw(15)<<setfill('5')<<left<<s<<endl;// 可行
    system("pause");
    return 0;
}