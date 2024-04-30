#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> split(string s, char delimiter) {
    vector<string> tokens;
    istringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        if(token != " " && token != "")
            tokens.push_back(token);
    }
    return tokens;
}

int main(){
    string s = "    dahh   dwnio    qwn wqjoi    \n";
    getline(cin,s);
    vector<string> sentence = split(s, ' ');
    cout<<sentence.size()<<endl;
    for (int i = 0; i < sentence.size(); i++) {
        cout << sentence[i] << endl;
    }
    system("pause");
    return 0;
}