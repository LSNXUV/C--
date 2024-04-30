#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
int N,pre[31],in[31],post[31],level[10000],n;
unordered_map<int,int> map;

//ǰ�� + ����  ->  �������
void levelOrder(int root,int start,int end,int index){
    if(start > end) return;
    int i = map[pre[root]];
    level[index] = pre[root];
    levelOrder(root + 1,start,i-1,(index << 1) + 2); //����������,����+2�Ǿ���
    levelOrder(root + 1 + (i-start),i+1,end,(index << 1) + 1);//����������
}

//ǰ�� + ����  ->  ����
void postOrder(int root,int start,int end){
    if(start > end) return;
    int i = map[pre[root]];
    postOrder(root + 1,start,i-1);              //������
    postOrder(root + 1 + (i-start),i+1,end);    //������
    cout<<pre[root]<<(++n < N ? " " : "");      //��
}
int main() {
    cin >> N;
    for(int i = 0;i<N;i++){
        cin>>in[i];
        map[in[i]] = i;
    }
    for(int i = 0;i<N;i++) 
        cin>>pre[i];
    
    // postOrder(0,0,N-1);

    levelOrder(0,0,N-1,0);
    for(int i = 0;i<10000;i++){
        if(level[i]) cout<<level[i]<<(++n < N ? " ": "");
    }
    return 0;
}