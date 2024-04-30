#include <iostream>
using namespace std;



int main(){
    string phone;
    cin>>phone;
    int num[10] = {0};
    int len = phone.length();
    for(int i = 0;i<len;i++){
        num[phone[i]-'0']++;
    }

    cout<<"int[] arr = new int[]{";
    int nums[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int j = 0;
    for(int i = 9;i>=0;i--){
        if(num[i]!=0){
            if(j != 0){
                cout<<",";
            }
            cout<<i;
            nums[i] = j++;
        }
    }
    cout<<"};"<<endl;

    cout<<"int[] index = new int[]{";
    j = 0;
    for(char c:phone){
        cout<<nums[c-'0'];
        if(j++ != len-1){
            cout<<",";
        }
    }
    cout<<"};"<<endl;

    system("pause");
    return 0;
}