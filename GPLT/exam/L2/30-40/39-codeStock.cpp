// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> temp;
map<vector<int>,int> m;
int main() {
    int N,M;
    cin>>N>>M;
    temp.resize(M);
    for(int i = 0;i<N;i++){
        for (int j = 0; j < M; j++) scanf("%d", &temp[j]);
        m[temp]++;
    }
    multimap<int, vector<int>> mp;
    for(auto & p:m){
        mp.insert({p.second,p.first});
    }
    cout<<m.size()<<endl;
    for(auto & d:mp){
        cout<<d.first;
        for (auto it2 : d.second) printf(" %d", it2);
        printf("\n");
    }
    system("pause");
    return 0;
}