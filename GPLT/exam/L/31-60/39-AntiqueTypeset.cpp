#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string text;
    cin>>n;
    cin.get();
    getline(cin,text);
    int col = (text.length() + n - 1) / n;
    for(int i = 0;i<n;i++){
        for(int j = (col - 1)*n;j>=0;j-=n){
            cout << ((j + i >= text.length()) ? ' ' : text[j + i]);
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}