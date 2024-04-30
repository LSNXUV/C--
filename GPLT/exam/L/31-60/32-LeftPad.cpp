#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin.get();
    getline(cin,s);
    if(s.length()>=n){
        cout<<s.substr(s.length()-n,n)<<endl;
    }else{
        for(int i=0;i<n-s.length();i++){
            cout << c;
        }
        cout << s << endl;
    }

    system("pause");
    return 0;
}