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

void Prim(MatGraph g,int v)
{
    int all = 0;

    int lowcost[MAXVEX];
    int closest[MAXVEX];
    int min,i,j,k;

    for(i=0;i<g.n;i++)
    {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    for(i = 1;i<g.n;i++)
    {
        min = INF;;k = -1;
        for(j = 0;j<g.n;j++)
            if(lowcost[j]!=0 && lowcost[j]<min)
            {
                min = lowcost[j];
                k = j;
            }
        
        printf("  边(%d,%d)权为:%d\n",closest[k],k,min);
        all+=min;
        
        lowcost[k] = 0;
        for(j = 0;j<g.n;j++)
        {
            if(lowcost[j]!=0 && g.edges[k][j]<lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
    }
    cout<<"最小生成树的代价为:"<<all;
}

int main(){
    MatGraph g;
    int n,v;
    int A[MAXVEX][MAXVEX];
    cin>>n>>v;
    
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    CreateGraph(g,A,n);

    cout<<"普里姆算法求解结果:\n";
    Prim(g,v);
    system("pause");
    return 0;
}