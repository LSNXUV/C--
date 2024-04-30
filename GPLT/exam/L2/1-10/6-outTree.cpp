#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
int N,pre[31],in[31],post[31],level[10000],n;
unordered_map<int,int> map;

//后序 + 中序  ->  层序
void levelOrder(int root,int start,int end,int index){
    if(start > end) return;
    int i = map[post[root]];
    level[index] = post[root];
    levelOrder(root-1,i+1,end,(index << 1) + 2);    //右子树
    levelOrder(root-1-(end - i),start,i-1,(index << 1 )+1); //左子树
}

//后序 + 中序  ->  前序
void preOrder(int root,int start,int end){
    if(start > end) return;
    int i = map[post[root]];
    cout<<post[root]<<(++n < N ? " " : "");     //根
    preOrder(root - 1 - (end - i),start,i-1);   //左子树
    preOrder(root - 1,i + 1,end);               //右子树
}
int main() {

    cin >> N;
    for(int i = 0;i<N;i++) 
        cin>>post[i];
    for(int i = 0;i<N;i++){
        cin>>in[i];
        map[in[i]] = i;
    }
    // preOrder(N-1,0,N-1);

    
    levelOrder(N-1,0,N-1,0);
    for(int i = 0;i<10000;i++){
        if(level[i]) cout<<level[i]<<(++n < N ? " ": "");
    }
    return 0;
}