#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

#define MAXVEX 510
#define INF 0x3f


int dist[MAXVEX];
int path[MAXVEX];
int n,m,s,e;
int pathFloyd[MAXVEX][MAXVEX];
int S[MAXVEX];
int g[MAXVEX][MAXVEX];

vector<int> route;

void Dijkstra(){
    dist[s] = 0;        //初始化源点s到自身的距离为0
    for(int i = 0;i<n;i++){
        int u = -1;
        for(int j = 0;j<n;j++){
            if(S[j] == 0 && (u == -1 || dist[j] < dist[u])){
                u = j;
            }
        }
        S[u] = 1;
        for(int v = 0;v<n;v++){
            if(dist[v] > dist[u] + g[u][v]){
                dist[v] = dist[u] + g[u][v];
                path[v] = u;
            }
        }
    }
}

void spfa(){
    queue<int> Q;
    Q.push(s);
    S[s] = 0;
    dist[s] = 0;
    while(Q.size()){
        int u = Q.front();
        Q.pop();
        S[u] = 1;
        for(int j = 0;j<n;j++){
            if(dist[j] > dist[u] + g[u][j]){
                dist[j] = dist[u] + g[u][j];
                path[j] = u;
                if(S[j] == 0){
                    Q.push(j);
                    S[j] = 1;
                }
            }
        }
        
    }
}

void floyd(){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                    pathFloyd[i][j] = k;
                }
            }
        }
    }
}

int main(){
    memset(g,INF,sizeof g);
    memset(dist,INF,sizeof dist);

    cin>>n>>m>>s>>e;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = c;
    }

    int u = e;
    /* 
    // Dijkstra();
    // spfa();

    while(u != s){
        route.push_back(u);
        u = path[u];
    } */
   
    /* floyd();    
    while(u != s){
        route.push_back(u);
        u = pathFloyd[s][u];
    } */

    route.push_back(s); 
    for(int i = route.size() -1;i>=0;i--){
        cout<<route[i]<<" ";
    }

    system("pause");
    return 0;
}