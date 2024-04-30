#include <iostream>
using namespace std;


#define MAXVEX 100
#define INF 32767

typedef char VertexType[10];

typedef struct vertex
{
    int adjvex;
    VertexType data;
} VType;

typedef struct graph
{
    int n,e;
    VType vexs[MAXVEX];
    int edges[MAXVEX][MAXVEX];
} MatGraph;

void CreateGraph(MatGraph &g,int A[][MAXVEX],int n)
{
    g.n = n;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            g.edges[i][j] = A[i][j];
        }
    }
}

void DispAllPath(MatGraph g,int dist[],int path[],int S[],int v)
{
    int k;
    int apath[MAXVEX],d;            //存放一条最短路径（逆向）及其顶点个数

    for(int i = 0;i<g.n;i++)
    {
        if(S[i] == 1 && i!=v)
        {
            printf("  从顶点%d到顶点%d的路径长度为:%d\t路径为:",v,i,dist[i]);
            d = 0;apath[d] = i;
            k = path[i];
            if(k == -1)
            
                printf("无路径\n");
            else                                //存在路径输出路径
            {
                while(k!=v)
                {
                    d++;apath[d] = k;
                    k = path[k];
                }
                d++;apath[d] = v;           //添加路径上的起点
                printf("%d",apath[d]);          //先输出起点

                for(int j = d-1;j>=0;j--)       //其他
                    printf(",%d",apath[j]);
                printf("\n");
            }
            
        }
    }
}

void Dijkstra(MatGraph g,int v)         //求v到其他顶点的最短路径
{
    int dist[MAXVEX];
    int path[MAXVEX];  
    int S[MAXVEX];
    int mindis,u = 0;

    for(int i = 0;i<g.n;i++)
    {
        dist[i] = g.edges[v][i];
        S[i] = 0;

        if(g.edges[v][i] < INF)         
            path[i] = v;                //顶点v到顶点i有边时，置顶点i的前一个顶点为v
        else
            path[i] = -1;               //顶点v到顶点i有边时，置顶点i的前一个顶点为v
    }
    S[v] = 1;
    for(int i = 0;i<g.n-1;i++)
    {
        mindis = INF;
        for(int j = 0;j<g.n;j++)
        {
            if(S[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
            // printf("将顶点%d加入S中\n",u);
        }   

        S[u] = 1;                       //源点编号v放入S中
        for(int j = 0;j<g.n;j++)
        {
            if(S[j] == 0)
                if(g.edges[u][j]<INF && dist[u]+g.edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
        }

    }
    DispAllPath(g,dist,path,S,v);                                    //输出所有最短路径及长度
}




int main(){
    MatGraph g;
    int n,v;
    int A[MAXVEX][MAXVEX];

    cout<<"输入顶点数：\n";
    cin>>n;

    cout<<"输入有向网的信息：\n";
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"输入出发顶点：\n";
    cin>>v;
    CreateGraph(g,A,n);

    printf("从%d顶点出发的最短路径如下:\n",v);
    Dijkstra(g,v);


    system("pause");
    return 0;
}


