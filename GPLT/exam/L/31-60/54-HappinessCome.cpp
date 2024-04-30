#include<iostream>
using namespace std;

int main(){
    char c;
    int n;
    cin>>c>>n;
    char **arr = new char*[n];
    for(int i=0;i<n;i++){
        arr[i] = new char[n];
        for(int j=0;j<n;j++){
            char temp;
            cin.get(temp);
            if(temp== '\n'){
                j--;
                continue;
            }
            arr[i][j] = temp;
        }
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=arr[n-1-i][n-1-j]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag){
        cout<<"bu yong dao le"<<endl;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            cout<<(arr[i][j] != ' ' ? c : ' ');
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}