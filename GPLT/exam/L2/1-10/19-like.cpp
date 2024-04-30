#include <iostream>
#include <set>
using namespace std;
struct ComparePairFirst {
    bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs) const {
        return lhs.first < rhs.first;
    }
};
int main() {
    int N;
    cin>>N;
    set<string> atte;
    for(int i = 0;i<N;i++){
        string s;
        cin>>s;
        atte.insert(s);
    }
    int M;
    cin>>M;
    int sum = 0;
    set<pair<string,int>,ComparePairFirst> likes;
    for(int i = 0;i<M;i++){
        string id;
        int like;
        cin>>id>>like;
        sum+=like;
        likes.insert({id,like});
    }
    int avg = sum / M;
    bool has = false;
    for(auto like:likes){
        if(atte.find(like.first) == atte.end() && like.second > avg){
            cout<<like.first<<endl;
            has = true;
        }
    }
    if(!has) cout<<"Bing Mei You";
    return 0;
}
