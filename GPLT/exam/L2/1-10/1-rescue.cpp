#include<iostream>
#include <climits>
using namespace std;
int main()
{
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    int *rescue = new int[n];
    int **road = new int*[n];
    for(int i = 0;i<n;i++){
        cin>>rescue[i];
        road[i] = new int[n];
        for(int j = 0;j<n;j++){
            road[i][j] = i == j ? 0 : INT_MAX;
        }
    }
    while(m--){
        int i,j;
        cin>>i>>j>>road[i][j];
        road[j][i] = road[i][j];
    }
    //floyd算法
    int **shortPath = new int*[n];
    for(int i = 0;i<n;i++){
        shortPath[i] = new int[n];
    }
    int **path = new int*[n];
    for(int i = 0;i<n;i++){
        path[i] = new int[n];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            shortPath[i][j] = road[i][j];
            if(i!=j && road[i][j] < INT_MAX){
                path[i][j] = i;
            }else{
                path[i][j] = -1;
            }
        }
    }
    // cout<<"initial shortPath or road:"<<endl;
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         cout<<shortPath[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(shortPath[i][j] > shortPath[i][k] + shortPath[k][j] || (shortPath[i][j] == shortPath[i][k] + shortPath[k][j] 
                    && i != j && i != k && k != j
                    && shortPath[i][j] 
                    && shortPath[i][k] 
                    && shortPath[k][j])){
                    shortPath[i][j] = shortPath[i][k] + shortPath[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    //输出最短路径
    int len = 0,resc = 0;
    int *minPath = new int[n];
    int k = path[s][d];
    minPath[len] = d;
    resc += (rescue[s] + rescue[d]);
    while(k != -1 && k!=s){
        minPath[++len] = k;
        resc += rescue[k];
        k = path[s][k];
    }
    minPath[++len] = s;
    cout<<len<<" "<<resc<<endl;
    for(int i = len;i>=0;i--){
        cout<<minPath[i]<<(i == 0 ? "" : " ");
    }
    return 0;
 }