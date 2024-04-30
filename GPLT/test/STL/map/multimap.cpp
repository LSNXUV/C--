#include <iostream>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

/* 
测试emplace和insert的性能
 */

int main(){
    map<int, int> mp;

    auto starttime = clock();
    
    for(int i = 0; i < 1000000; i++){
        mp.emplace(i, i);
    }

    auto endtime = clock();
    cout << "emplace: " << endtime - starttime << endl;

    mp.clear();

    starttime = clock();

    for(int i = 0; i < 1000000; i++){
        mp.insert({i,i}); 
        // mp.insert(pair<int,int>(i, i));
        // mp.insert(make_pair(i,i));
    }

    endtime = clock();
    cout << "insert: " << endtime - starttime << endl;
    system("pause");
    return 0;
}