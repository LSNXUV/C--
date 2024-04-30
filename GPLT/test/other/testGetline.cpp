#include <iostream>
#include <string>
using namespace std;


int main(){
    string s;
    // cin.get();
    getline(cin, s);
    cout << s.substr(0,5) << endl;
    system("pause");
    return 0;
}