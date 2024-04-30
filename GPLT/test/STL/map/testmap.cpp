#include <iostream>
#include <map>
using namespace std;


int main(){
    multimap<int,int> mp;
    mp.insert({1,2});
    mp.insert({1,3});
    mp.insert({1,4});
    mp.insert({2,3});
    mp.insert({2,4});
    mp.insert({3,4});

    auto it = mp.equal_range(2);
    /* for(auto i = it.first;i!=it.second;i++){
        cout<<i->first<<" "<<i->second<<endl;
    } */
    mp.emplace_hint(it.first,3,5);  //用于在it.first位置插入元素

    for(auto i = it.first;i!=it.second;i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    system("pause");
    return 0;
}