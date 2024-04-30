#include<iostream>
#include<string>
using namespace std;

int main(){
    string sentence;
    getline(cin,sentence);
    int i;
    while(i < sentence.length()){
        while(i<sentence.length() && sentence[i] != '6'){
            cout<<sentence[i++];
        }
        int count = 0;
        while(i<sentence.length() && sentence[i] == '6'){
            count++;i++;
        }
        if(count > 9){
            cout<<"27";
        }else if(count > 3){
            cout<<"9";
        }else if(count > 0){
            for(int i = 0;i<count;i++) cout<<'6';
        }
    }
    return 0;
}