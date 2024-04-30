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
    dist[s] = 0;            //初始化源点到源点的距离为0
    for(int i = 0;i<n;i++){
        int u = -1;
        for(int j = 0;j<n;j++){
            if(S[j] == 0 && (u == -1 || dist[j] < dist[u])){
                u = j;      //找到不在S中且距离最小的顶点
            }
        }
        S[u] = 1;       //将顶点u加入S
        for(int v = 0;v<n;v++){
            if(S[v] == 0 && dist[u] + g[u][v] < dist[v]){
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
    dist[s] = 0;
    S[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        S[u] = 0;
        for(int v = 0;v<n;v++){
            if(dist[v] > dist[u] + g[u][v]){
                dist[v] = dist[u] + g[u][v];
                path[v] = u;
                if(S[v] == 0){
                    q.push(v);
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
    Dijkstra();
    printDij();

    //floyd算法
    // floyd();
    // printFloyd();

    //spfa算法
    // spfa();
    // printSpfa();

    system("pause");
    return 0;
}