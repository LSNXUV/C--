#include <iostream>
#include <string>
using namespace std;

/*
����A��B��������[1,1000]
�����ʽ��
������һ�и���A��B������Կո�ֿ���������A��B��һ��������Ҫ�������������ʱ������ǳ�����Χ�����֡���������С�����ʵ����������һ�����롣

ע�⣺���ǰ������г��ֵĵ�1���ո���Ϊ��A��B�ķָ�����Ŀ��֤���ٴ���һ���ո񣬲���B����һ�����ַ�����

�����ʽ��
��������ȷ���������������򰴸�ʽA + B = ����������ĳ�����벻��Ҫ��������Ӧλ�����?����Ȼ��ʱ��Ҳ��?��

��������1��
123 456
�������1��
123 + 456 = 579
��������2��
22. 18
�������2��
? + 18 = ?
��������3��
-100 blabla bla...33
�������3��
? + ? = ?
*/

bool isInt(string s){
    if(s[0] == '0' || s.length() > 4){
        return false;
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    if(stoi(s) > 1000){
        return false;
    }
    return true;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(!isInt(a)){
        a = "?";
    }
    if(!isInt(b)){
        b = "?";
    }
    cout << a << " + " << b << " = ";
    string result = "?";
    if(a != "?" && b != "?"){
        result = to_string(stoi(a) + stoi(b));
    }
    cout << result;
    
    system("pause");
    return 0;
}