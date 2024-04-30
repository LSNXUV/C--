// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
struct Record{
    string name,id,time;
    int state,order;
    bool operator<(const Record& other) const {
        if(time != other.time) return time < other.time;
        return order < other.order;
    }
};
bool isId(string& id){
    if(id.length() != 18) return false;
    for(char c:id) if(c > '9' || c < '0') return false;
    return true;
}
int D,P,T,S,prov;
vector<Record> records;
map<string,int> brs;
set<string> healAre;
vector<pair<string,string>> health;
int main() {
    cin>>D>>P;
    for(int d = 1;d <= D;d++){
        cin>>T>>S;
        records.resize(T);    //≥ı ºªØ
        for(int t = 0;t < T;t++){
            cin>>records[t].name>>records[t].id>>records[t].state>>records[t].time;
            records[t].order = t;
            if(!isId(records[t].id)){
                records[t].name = "";
            }else{
                if(!brs.count(records[t].id)) brs[records[t].id] = -30;
                if(records[t].state == 1 && !healAre.count(records[t].id)){
                    health.push_back({records[t].name,records[t].id});
                    healAre.insert(records[t].id);
                }
            }
        }
        sort(records.begin(),records.end());
        for(int t = 0;t < T && S > 0;t++){
            if(records[t].name != "" && d - brs[records[t].id] > P){
                brs[records[t].id] = d;S--;
                cout<<records[t].name<<" "<<records[t].id<<endl;
            }
        }
    }
    for(auto& d:health) cout<<d.first<<" "<<d.second<<endl;
    return 0;
}