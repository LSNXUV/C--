#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
vector<int> in, pre,post, level(10000, -1);
unordered_map<int,int> umap;

/*
7
5 6 7 8 9 10 11
8 6 5 7 10 9 11

7
4 2 5 1 6 3 7
1 2 4 5 3 6 7
*/
void levelorderByPre(int root, int start, int end, int index) {
    if(start > end) return;
    int i = umap[pre[root]];
    level[index] = pre[root];
    levelorderByPre(root + 1,start,i-1,(index << 1 )+ 2);
    levelorderByPre(root + 1 + i-start,i+1,end,(index << 1) + 1);
}

/*通过后序和中序遍历序列构建镜像二叉树（交换index）
*/
/*
7
1 2 3 4 5 6 7
2 3 1 5 7 6 4

7
4 2 5 1 6 3 7
4 5 2 6 7 3 1
*/
void levelorderByPost(int root, int start, int end, int index) {
    if(start > end) return;
    int i = umap[post[root]];
    level[index] = post[root];
    levelorderByPost(root - 1 - end + i, start, i-1, (index << 1) + 2);
    levelorderByPost(root - 1, i+1, end, (index << 1) + 1);
}

int main() {
    int n, cnt = 0;
    cin>>n;
    in.resize(n);
    pre.resize(n);
    post.resize(n);
    for(int i = 0; i < n; i++){ 
        cin>>in[i];
        umap[in[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        // cin>>pre[i];
        cin>>post[i];
    }
    // levelorderByPre(0, 0, n-1, 0);
    levelorderByPost(n-1, 0, n-1, 0);
    for(int i = 0; i < (int)level.size(); i++) {
        if(level[i] != -1) {
            cout<<level[i]<<(++cnt < n ? " ": "");
        }
    }
    system("pause");
    return 0;
}