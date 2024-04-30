#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> v(510); //存储图的邻接表，v[i]存储与节点i相邻的节点
vector<int> color(510);    //存储每个节点的颜色
bool verify(int n) {    //n为节点数
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < v[i].size(); j++)    
            if(color[i] == color[v[i][j]])  // 有相邻节点颜色相同,直接返回false
                return false;
    }
    return true;
}
int main() {
    int n, m, k, num;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);    // 无向图,两个节点相互存储
        v[v2].push_back(v1);   
    }
    cin >> num;
    set<int> s;
    while(num--) {
        s.clear();
        for(int i = 1; i <= n; i++) {
            cin >> color[i];
            s.insert(color[i]);
        }
        if(s.size() != k ) {    // 颜色种类不等于k,直接输出No
            cout << "No\n";
        }else if(!verify(n))     // 颜色种类等于k,但有相邻节点颜色相同,输出No
            cout << "No\n";
        else                   
            cout << "Yes\n";
    }
    return 0;
}