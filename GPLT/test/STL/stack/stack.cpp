#include <iostream>
#include <stack>
using namespace std;


int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);

    s.swap(s);  // ��������ջ��Ԫ��
    //����ջ�Ƿ����ĳ��Ԫ��
    int f = 6;
    stack<int> s1 = s;
    

    system("pause");
    return 0;
}