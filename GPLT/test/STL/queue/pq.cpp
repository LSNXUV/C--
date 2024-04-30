#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<int,string> a,pair<int,string> b){    //自定义优先级队列的比较函数
    if(a.first!=b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    // priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(&cmp)> pq(cmp);    //定义优先级队列，第一个参数是数据类型，第二个参数是容器类型，第三个参数是比较函数
    //使用greater<>和less<>可以实现最小堆和最大堆
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>> pq;
    pq.push({1,"a"});
    pq.push({2,"b"});
    pq.push({2,"a"});
    pq.push({3,"c"});
    pq.push({4,"b"});
    pq.push({4,"a"});

    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    /* 
    1 a
    2 a
    2 b
    3 c
    4 a
    4 b 升序??
     */

    vector<int> v;   
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    sort(v.begin(),v.end(),greater<>());    //使用greater<>可以实现最小堆
    for(auto i:v){
        cout<<i<<" ";   //less: 1 2 3 4,升序. greater: 4 3 2 1,降序
    }
    cout<<endl;

    set<int,greater<>> s;    
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    for(auto i:s){
        cout<<i<<" ";   //less: 1 2 3 4,升序. greater: 4 3 2 1,降序
    }
    system("pause");
    return 0;
}