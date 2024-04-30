#include <iostream>
using namespace std;



int main(){

    string CheckCode = "10X98765432";
    int n;

    cin>>n;
    bool allRight = true;
    for(int i = 0;i<n;i++){
        string id;
        cin>>id;
        int sum = 0;
        int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        bool flag = true;
        for(int j = 0;j<17;j++){
            if(id[j]<'0' || id[j]>'9'){
                flag = false;
                break;
            }
            sum += (id[j]-'0')*weight[j];
        }
        if(flag){
            if(CheckCode[sum%11] != id[17]){
                flag = false;
            }
        }
        if(!flag){
            cout<<id<<endl;
            allRight = false;
        }
    }

    if(allRight){
        cout<<"All passed";
    }

    system("pause");
    return 0;
}