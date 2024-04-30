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
        tokens.push_back(token);
    }
    return tokens;
}
int main(){
    int n;
    cin>>n;
    cin.ignore(); // 忽略第一行的换行符
    for(int i = 0;i<n;i++){
        string line;
        getline(cin,line);
        vector<string> sentence = split(line, ',');
        if(sentence[0].length() >= 3 && sentence[1].length() >= 4){
            if(sentence[0].substr(sentence[0].size()-3,3) == "ong" && sentence[1].substr(sentence[1].size()-4,3) == "ong"){
                //找到倒数第三个空格的位置
                int count = 0;
                for(int i = sentence[1].length()-2;i>=0;i--){
                    if(sentence[1][i] == ' ') count++;
                    if(count == 3){
                        sentence[1] = sentence[1].substr(0,i+1) + "qiao ben zhong.";
                        break;
                    }
                }
                cout<<sentence[0]<<","<<sentence[1]<<endl;
            }else{
                cout<<"Skipped"<<endl;
            }
        }else{
            cout<<"Skipped"<<endl;
        }
    }

    system("pause");
    return 0;
}