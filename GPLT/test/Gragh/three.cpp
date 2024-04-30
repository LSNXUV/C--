#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;


#define MAXVEX 510
#define INF 32767

int dist[MAXVEX];                  //���Դ�㵽������������·������
int path[MAXVEX];                  //���Դ�㵽������������·����ǰһ������
int S[MAXVEX];                   //S[i]Ϊ1��ʾ����i��S�У�Ϊ0��ʾ����S��
int n,m;                         //nΪ��������mΪ����
int g[MAXVEX][MAXVEX];           //�ڽӾ���
int s,e;                         //Դ����յ�
vector<int> route;               //��Ŵ�ӡ·��

void printRoute(){
    for(int i = route.size()-1;i>=0;i--){
        cout<<route[i]<<" ";
    }
    cout<<endl;
}

void Dijkstra(){
    dist[s] = 0;            //��ʼ��Դ�㵽Դ��ľ���Ϊ0
    for(int i = 0;i<n;i++){
        int u = -1;
        for(int j = 0;j<n;j++){
            if(S[j] == 0 && (u == -1 || dist[j] < dist[u])){
                u = j;      //�ҵ�����S���Ҿ�����С�Ķ���
            }
        }
        S[u] = 1;       //������u����S
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

int pathFloyd[MAXVEX][MAXVEX]; //���·��
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
    while(t != 0){      //ֻ��������0�Ŷ��������������0�ţ���ô��·��pathӦ��Ϊ-1���������Ƿ�ֵ
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
    memset(g, 0x3f, sizeof(g)); //��ʼ���ڽӾ���
    memset(dist, 0x3f, sizeof(dist)); //��ʼ��dist����

    // cout<<"���붥������������Դ�㡢�յ㣺\n";
    cin>>n>>m>>s>>e;
    // cout<<"��������ߣ�\n";
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = c;
    }

    //dijkstra�㷨
    Dijkstra();
    printDij();

    //floyd�㷨
    // floyd();
    // printFloyd();

    //spfa�㷨
    // spfa();
    // printSpfa();

    system("pause");
    return 0;
}