#include <iostream>
using namespace std;

/*
����Ҫ����һ������x���������һ�����������Ҳ���5��β��
Ȼ�󣬾������㣬����������֣�
��һ������s����ʾx����s��һ��������ڶ�������n����������λ����
*/

int main(){
    int n,count = 0,remainder = 0,start = false;
    cin>>n;
    while(true){
        remainder = remainder * 10 + 1; 
        if((remainder / n) != 0) start = true;
        if(start) cout<<(remainder / n);
        remainder = remainder % n;
        count++;
        if(remainder == 0) break;
    }
    cout<<" "<<count;
    system("pause");
    return 0;
}