#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



int main(){
    string s = "test";
    int num = 123;

    //��0��䣬�ܳ���Ϊ15
    printf("%015s",s.c_str());
    cout<<endl;
    printf("%015d",num);

    //��5��䣬�ܳ���Ϊ15
    printf("%515s",s.c_str());// �����У�����
    cout<<endl;
    cout<<setw(15)<<setfill('5')<<left<<s<<endl;// ����
    system("pause");
    return 0;
}