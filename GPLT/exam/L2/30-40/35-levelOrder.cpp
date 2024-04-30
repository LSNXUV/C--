// #include<bits/stdc++.h>
#include<iostream>
#include <vector>
using namespace std;
int n,cnt;
int In[31],Pre[31],Post[31];
int level[31];

/*
8
91 71 2 34 10 15 55 18
 */
void BuildByPost(int index){
    if(index > n) return;
    BuildByPost(index << 1);
    BuildByPost(index << 1 | 1);
    level[index] = Post[cnt++];
}

/* 
8
18 34 71 91 2 55 10 15
*/
void BuildByPre(int index){
    if(index > n) return;
    level[index] = Pre[cnt++];
    BuildByPre(index << 1);
    BuildByPre(index << 1 | 1);
}

/*
8
91 71 34 2 18 10 55 15
*/
void BuildByIn(int index){
    if(index > n) return;
    BuildByIn(index << 1);
    level[index] = In[cnt++];
    BuildByIn(index << 1 | 1);
}
int main(){
    cin>>n;
    for(int i = 0;i<n;i++) cin>>In[i];
    BuildByIn(1);
    /* for(int i = 0;i<n;i++) cin>>Pre[i];
    cnt = 0;
    BuildByPre(1); */
    /* for(int i = 0;i<n;i++) cin>>Post[i];
    cnt = 0;
    BuildByPost(1); */
    
    cout<<level[1];
    for(int i = 2;i<=n;i++) cout<<" "<<level[i]; 
    system("pause");
    return 0;
}