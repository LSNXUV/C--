#include <iostream>
using namespace std;

/*
����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰�GPLTGPLT....������˳������������������ַ�����Ȼ�������ַ��������ִ�Сд���ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�GPLT��˳���ӡ��ֱ�������ַ����������

�����ʽ��
������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��
��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
���������
GPLTGPLTGLTGLGLL
*/

int main(){

    string str;
    cin >> str;
    int g = 0, p = 0, l = 0, t = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'G' || str[i] == 'g')
            g++;
        else if(str[i] == 'P' || str[i] == 'p')
            p++;
        else if(str[i] == 'L' || str[i] == 'l')
            l++;
        else if(str[i] == 'T' || str[i] == 't')
            t++;
    }
    while(g > 0 || p > 0 || l > 0 || t > 0){
        if(g > 0){
            cout << "G";
            g--;
        }
        if(p > 0){
            cout << "P";
            p--;
        }
        if(l > 0){
            cout << "L";
            l--;
        }
        if(t > 0){
            cout << "T";
            t--;
        }
    }
    cout << endl;
    

    system("pause");
    return 0;
}