#include <iostream>
#include <tuple>
#include <set>
using namespace std;
struct compare {
    bool operator()(const tuple<set<int>, double, string>& lhs, const tuple<set<int>, double, string>& rhs) const {
        if (get<0>(lhs).size() != get<0>(rhs).size())
            return get<0>(lhs).size() > get<0>(rhs).size();
        else
            return get<1>(lhs) < get<1>(rhs);
    }
};
int main() {
    int N;
    cin>>N;
    set<tuple<set<int>,double,string>,compare> rens;
    for(int i = 0;i<N;i++){
        string name;
        cin>>name;
        int n;
        cin>>n;
        set<int> s;
        for(int i = 0;i<n;i++){
            int no;
            cin>>no;
            s.insert(no);
        }
        rens.insert({s,n,name});
    }
    int i = 0;
    for(auto it = rens.begin();it != rens.end() && i < 3;++it,i++){
        cout<<get<2>(*it)<<(i == 2 ? "" : " ");
    }
   for(int j = i;j<3;j++){
       cout<<"-"<<(j == 2 ? "" : " ");
   }
    return 0;
}
