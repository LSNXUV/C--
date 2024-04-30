// #include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
#include <tuple>
using namespace std;
int N,k,c;
double house,area;
set<int> rens; //存储临时家庭
struct cmp{
    bool operator()(const tuple<double,set<int>,double,double>& f1,const tuple<double,set<int>,double,double>& f2) const {
        if(get<0>(f1) != get<0>(f2)){
            return get<0>(f1) > get<0>(f2);
        }
        return *(get<1>(f1).begin()) < *(get<1>(f2).begin());
    }
};
set<tuple<double,set<int>,double,double>,cmp> fms; //存储所有家庭
vector<tuple<double,set<int>,double,double>> merges; //存储待合并家庭
bool isFm(const set<int>& s1,const set<int>& s2){
    if(s1.size() > s2.size()) return isFm(s2,s1);
    for(auto f:s1){
        if(s2.find(f) != s2.end()) return true;
    }
    return false;
}
int main() {
    cin >> N;
    for(int i = 0;i<N;i++){
        rens.clear();
        for(int i = 0;i<3;i++){
            cin>>k;rens.insert(k);
        }
        cin>>k;
        while(k--){
            cin>>c;
            rens.insert(c);
        }
        cin>>house>>area;
        rens.erase(-1); //过世不算
        //收集所有同族
        merges.clear();
        for(auto &fm : fms){
            if(isFm(rens,get<1>(fm))){
                merges.push_back(fm);
            }
        }
        //合并房子和面积，以及成员。
        for(auto& it:merges){
            house += get<2>(it);
            area += get<3>(it);
            rens.insert(get<1>(it).begin(),get<1>(it).end());
            fms.erase(it);
        }
        fms.emplace(area / rens.size(),rens,house,area);
    }
    cout<<fms.size()<<endl;
    for(auto fm : fms){
        auto mem = get<1>(fm);
        printf("%04d %ld %.3f %.3f\n",(*mem.begin()),mem.size(),get<2>(fm) / mem.size(),get<0>(fm));
    }
    return 0;
}
