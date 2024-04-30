#include <iostream>
#include <regex>
using namespace std;


int main(){
    string s = "nqowidbqw,helloworld,dwqiohdqwuvcuvq ";
    string s1 = "qiuhxbqwe";
    // s.replace(s.find("helloworld"),10,"");
    s = s.erase(s.find("helloworld"),10);
    
    cout<<s<<endl;
    cout<<s1<<endl;
    // cout<<regex_search(s,regex("helloworld"))<<endl;    // 1
    // cout<<regex_match(s,regex("helloworld"));       // 0,
    system("pause");
    return 0;
}