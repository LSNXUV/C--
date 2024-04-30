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
    int apath[MAXVEX],d;            //���һ�����·�������򣩼��䶥�����

    for(int i = 0;i<g.n;i++)
    {
        if(S[i] == 1 && i!=v)
        {
            printf("  �Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
            d = 0;apath[d] = i;
            k = path[i];
            if(k == -1)
            
                printf("��·��\n");
            else                                //����·�����·��
            {
                while(k!=v)
                {
                    d++;apath[d] = k;
                    k = path[k];
                }
                d++;apath[d] = v;           //���·���ϵ����
                printf("%d",apath[d]);          //��������

                for(int j = d-1;j>=0;j--)       //����
                    printf(",%d",apath[j]);
                printf("\n");
            }
            
        }
    }
}

void Dijkstra(MatGraph g,int v)         //��v��������������·��
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
            path[i] = v;                //����v������i�б�ʱ���ö���i��ǰһ������Ϊv
        else
            path[i] = -1;               //����v������i�б�ʱ���ö���i��ǰһ������Ϊv
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
            // printf("������%d����S��\n",u);
        }   

        S[u] = 1;                       //Դ����v����S��
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
    DispAllPath(g,dist,path,S,v);                                    //����������·��������
}




int main(){
    MatGraph g;
    int n,v;
    int A[MAXVEX][MAXVEX];

    cout<<"���붥������\n";
    cin>>n;

    cout<<"��������������Ϣ��\n";
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"����������㣺\n";
    cin>>v;
    CreateGraph(g,A,n);

    printf("��%d������������·������:\n",v);
    Dijkstra(g,v);


    system("pause");
    return 0;
}


