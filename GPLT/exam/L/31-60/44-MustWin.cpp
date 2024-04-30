#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int count = 0;
    string attack;
    cin>>attack;
    while(attack != "End"){
        if(count == n && count != 0){
            cout<<attack<<endl;
            count = 0;
        }else{
            if(attack == "ChuiZi"){
                cout<<"Bu"<<endl;
            }else if(attack == "JianDao"){
                cout<<"ChuiZi"<<endl;
            }else if(attack == "Bu"){
                cout<<"JianDao"<<endl;
            }
            count++;
        }
        cin>>attack;
    }
    
    system("pause");
    return 0;
}