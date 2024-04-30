#include <iostream>
using namespace std;

/*
输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。十个数字对应的拼音如下：

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