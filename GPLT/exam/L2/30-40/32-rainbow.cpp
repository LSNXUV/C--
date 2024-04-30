// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;
int main() {
    int N,M,K,num,cur;
    cin>>N>>M>>K;
    while(K--){
        cur = 1;
        stack<int> s;
        for(int i = 0;i<N;i++){
            cin>>num;
            if(num != cur){
                s.push(num);
            }else{
                if(s.size() == 0) ++cur;
                while(s.size() <= M && s.size() > 0 && s.top() == ++cur) s.pop();
            }
        }
        if(s.size() == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}