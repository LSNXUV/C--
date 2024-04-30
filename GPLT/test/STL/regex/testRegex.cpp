#include <iostream>
#include <regex>
using namespace std;

#include <iostream>
#include <regex>
using namespace std;

int main(){
    string s = "fewniufnwe994wqeqw348qwecq8w qwe7 qw671e wq16"; //提取所有数字
    smatch result;
    while(regex_search(s, result, regex(R"(\d+)"))){
        cout << result.str() << endl;   //输出匹配的字符串
        s = result.suffix();    //更新字符串, 去掉已经匹配的部分
    }


    system("pause");
    return 0;
}