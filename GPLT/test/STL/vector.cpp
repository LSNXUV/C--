#include <iostream>
#include<algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i < 5; i++){
        v.push_back(i*2);
    }
    
    auto it = lower_bound(v.begin(), v.end(), 3, less<>());
    v.insert(it,3);

    for(auto i : v){    //0 2 3 4 6 8
        cout << i << " ";
    }
    
    cout << endl;
    it = upper_bound(v.begin(), v.end(), 4, less<>());
    v.insert(it,4);
    for(auto i : v){
        cout << i << " ";
    }
    system("pause");
    return 0;
}