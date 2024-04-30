#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;


#define MAXVEX 510
#define INF 32767

int dist[MAXVEX];                  //存放源点到其他顶点的最短路径长度
int path[MAXVEX];                  //存放源点到其他顶点的最短路径的前一个顶点
int S[MAXVEX];                   //S[i]为1表示顶点i在S中，为0表示不在S中
int n,m;                         //n为顶点数，m为边数
int g[MAXVEX][MAXVEX];           //邻接矩阵
int s,e;                         //源点和终点
vector<int> route;               //存放打印路径

void printRoute(){
    for(int i = route.size()-1;i>=0;i--){
        cout<<route[i]<<" ";
    }
    cout<<endl;
}

void Dijkstra(){
    dist[s] = 0;
    for(int i = 0;i<n;i++){
        int u = -1;
        for(int j = 0;j<n;j++){
            if(S[j] == 0 && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        S[u] = 1;
        for(int v = 0;v < n;v++){
            if(S[v] == 0 && dist[v] > dist[u] + g[u][v]){
                dist[v] = dist[u] + g[u][v];
                path[v] = u;
            }
        }
    }
}


void printDij(){
    int t = e;
    while(t != s){
        route.push_back(t);
        t = path[t];
    }
    route.push_back(s);
    printRoute();
}

int pathFloyd[MAXVEX][MAXVEX]; //存放路径
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

void printFloyd(){
    int t = e;
    while(t != 0){      //只适用于无0号顶点的情况，如果有0号，那么无路径path应该为-1或者其他非法值
        route.push_back(t);
        t = pathFloyd[s][t];
    }
    route.push_back(s);
    printRoute();
}

void spfa(){
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;
    // S[s] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        S[u] = 1;
        for(int v = 0;v<n;v++){
            if(dist[v] > dist[u] + g[u][v]){
                dist[v] = dist[u] + g[u][v];
                path[v] = u;
                if(S[v] == 0){
                    Q.push(v);
                    S[v] = 1;
                }
            }
        }
    }

}

void printSpfa(){
    int t = e;
    while(t != s){
        route.push_back(t);
        t = path[t];
    }
    route.push_back(s);
    printRoute();
}

int main(){
    int a,b,c;
    memset(g, 0x3f, sizeof(g)); //初始化邻接矩阵
    memset(dist, 0x3f, sizeof(dist)); //初始化dist数组

    // cout<<"输入顶点数、边数、源点、终点：\n";
    cin>>n>>m>>s>>e;
    // cout<<"请输入各边：\n";
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = c;
    }

    //dijkstra算法
    // Dijkstra();
    // printDij();

    //floyd算法
    // floyd();
    // printFloyd();

    //spfa算法
    spfa();
    printSpfa();

    system("pause");
    return 0;
}

/* 
测试数据：

带0节点：

8 11 0 7
0 2 2
0 3 4
2 6 1
2 5 3
2 4 3
3 4 2
3 5 3
3 6 1
4 7 1
5 7 3
6 7 4

不带0节点:

8 11 1 7
1 2 2
1 3 4
2 6 1
2 5 3
2 4 3
3 4 2
3 5 3
3 6 1
4 7 1
5 7 3
6 7 4

 */