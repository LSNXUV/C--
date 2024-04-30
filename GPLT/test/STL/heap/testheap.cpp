#include <iostream>
#include <vector>  
#include <algorithm>
using namespace std;

vector<int> heap;

void add(int x){
    heap.push_back(x);
    push_heap(heap.begin(), heap.end());    //默认是大顶堆
}

/*
test data:
// 1
5
1 2 3 4 5
↑ 是堆

// 2
5
4 2 5 3 1
↑ 不是堆
*/

int main(){
    vector<int> v;
    int n, x;
    cin>>n;
    while(n != -1){
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
        }
        cout<<(is_heap_until(v.begin(), v.end()) == v.end())<<endl; //默认判断大顶堆,判断小顶堆可以使用greater<int>()
        //is_heap_until()返回的是第一个不满足堆的位置，如果是堆，返回end()
        //is_heap()返回的是是否是堆,默认是大顶堆
        cout<<(is_heap(v.begin(), v.end()) == 1)<<endl;
        v.clear();
        cin>>n;
    }

    system("pause");
    return 0;
}