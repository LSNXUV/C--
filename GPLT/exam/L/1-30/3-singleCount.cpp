#include <iostream>
using namespace std;

int main(){
    int count[10] = {0};
    /* 
    //使用string
    string s;
    cin >> s;
    for(long unsigned i = 0; i < s.length(); i++){
        count[s[i] - '0']++;
    } */

    //使用char
    char s[1001];
    cin >> s;
    for(int i = 0; s[i] != '\0'; i++){
        count[s[i] - '0']++;
    }

    for(int i = 0; i < 10; i++){
        if(count[i] != 0){
            cout << i << ":" << count[i] << endl;
        }
    }
    system("pause");
    return 0;
}