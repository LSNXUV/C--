#include <iostream>
#include <regex>
using namespace std;

#include <iostream>
#include <regex>
using namespace std;

int main(){
    string s = "fewniufnwe994wqeqw348qwecq8w qwe7 qw671e wq16"; //��ȡ��������
    smatch result;
    while(regex_search(s, result, regex(R"(\d+)"))){
        cout << result.str() << endl;   //���ƥ����ַ���
        s = result.suffix();    //�����ַ���, ȥ���Ѿ�ƥ��Ĳ���
    }


    system("pause");
    return 0;
}