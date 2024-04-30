#include <iostream>
#include <string>
using namespace std;



int main(){
    string s = "abc";
    s += (char)(122 - 26);
    cout << s << endl;
    system("pause");
    return 0;
}