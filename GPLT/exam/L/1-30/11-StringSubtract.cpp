#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    bool hash[128] = {false};
    for(char c : b){
        hash[c] = true;
    }

    for(char c:a){
        if(!hash[c])
            cout << c;
    }

    system("pause");
    return 0;
}