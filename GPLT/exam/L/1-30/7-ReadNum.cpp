#include <iostream>
using namespace std;

/*
����һ�����������ÿ�����ֶ�Ӧ��ƴ����������Ϊ����ʱ�������fu�֡�ʮ�����ֶ�Ӧ��ƴ�����£�

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
*/

int main(){
    string num;
    cin>>num;
    if(num[0]=='-'){
        cout<<"fu ";
        num = num.substr(1);
    }
    string pinyin[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    // string *pinyin = new string[10]{"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    for(int i=0;i<num.length();i++){
        if(i!=0) cout<<" ";
        cout<<pinyin[num[i]-'0'];
    }

    system("pause");
    return 0;
}