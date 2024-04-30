#include <iostream>
using namespace std;

int parent[100000];     // 存储每个人的父母
int gen[100000];        // 存储每个人的辈分

int find(int x) {       // 递归计算每个人的辈分
    if(parent[x] == -1) return 1;   // 老祖宗的辈分为1
    if(gen[x] == 0)   // 如果当前人的辈分还没有计算过
        return gen[x] = find(parent[x]) + 1;    // 当前人的辈分等于其父母的辈分+1
    else 
        return gen[x];  // 已经计算过的直接返回
}
int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> parent[i];
        gen[i] = 0;   // 初始化辈分为0
    }

    for(int i = 1; i <= N; i++) {
        gen[i] = find(i);   // 计算每个人的辈分
    }
    // 找出最大的辈分
    int max = 1;    
    for(int i = 1; i <= N; i++) {
        if(gen[i] >= max) max = gen[i]; 
    }
    cout << max << endl;
    int cnt = 0;    // 格式控制
    for(int i = 1; i <= N; i++) {
        if(gen[i] == max){
            if(cnt) cout << " ";
            cout << i;
            cnt++;
        }
    }
}
