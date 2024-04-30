
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const short INF = 32767; // 定义short类型的最大值
const int MaxSize = 100; // 定义最大顶点数

typedef struct node
{
    int data;   // 结点对应顶点编号
    int rank;   // 结点对应秩
    int parent; // 结点对应双亲下标
} UFSTree;      // 并查集树的结点类型

typedef struct
{
    int u; // 边的起始顶点
    int v; // 边的终止顶点
    int w; // 边的权值
} Edge;


typedef struct {
    int n; // 顶点数
    int e; // 边数
    int edges[MaxSize][MaxSize]; // 邻接矩阵
} MGraph;

void MAKE_SET(UFSTree t[], int n) // 初始化并查集树
{
    for (int i = 0; i < n; i++) // 顶点编号为0～(n-1)
    {
        t[i].rank = 0;   // 秩初始化为0
        t[i].parent = i; // 双亲初始化指向自已
    }
}
int FIND_SET(UFSTree t[], int x) // 在x所在子树中查找集合的编号
{
    if (x != t[x].parent)                  // 若双亲不是自已
        return (FIND_SET(t, t[x].parent)); // 递归在双亲中找x
    else
        return (x); // 若双亲是自已,返回x
}

void UNION(UFSTree t[], int x, int y) // 将x和y所在的子树合并
{
    x = FIND_SET(t, x);
    y = FIND_SET(t, y);
    if (t[x].rank > t[y].rank) // x结点的秩大于y结点的秩
        t[y].parent = x;       // 将x结点作为y的双亲结点
    else                       // y结点的秩大于等于x结点的秩
    {
        t[x].parent = y;            // 将y结点作为x的双亲结点
        if (t[x].rank == t[y].rank) // x和y结点的秩相同
            t[y].rank++;            // y结点的秩增1
    }
}

bool compareEdges(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

void Kruskal(MGraph g) // Kruskal算法
{
    int i, j, k, u1, v1, sn1, sn2;
    UFSTree t[MaxSize];
    Edge E[MaxSize];
    k = 0;
    for (i = 0; i < g.n; i++) // 由g下三角部分产生的边集E
        for (j = 0; j < i; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }
    sort(E, E + k,compareEdges);   // 调用STL的sort()算法按w递增排序
    MAKE_SET(t, g.n); // 初始化并查集树t
    k = 1;            // k表示当前构造生成树的第几条边,初值为1
    j = 0;            // E中边的下标,初值为0
    while (k < g.n)   // 生成的边数小于n时循环
    {
        u1 = E[j].u;
        v1 = E[j].v; // 取一条边的头尾顶点编号u1和v2
        sn1 = FIND_SET(t, u1);
        sn2 = FIND_SET(t, v1); // 分别得到两个顶点所属的集合编号
        if (sn1 != sn2)
        // 添加该边不会构成回路,将其作为最小生成树的一条边输出
        {
            printf("添加边  (%d,%d):%d\n", u1, v1, E[j].w);
            k++;              // 生成边数增1
            UNION(t, u1, v1); // 将u1和v1两个顶点合并
        }
        j++; // 扫描下一条边
    }
}


int main()
{
    MGraph g;
    int i, j, k, w;
    printf("请输入顶点数和边数:\n");
    scanf("%d%d", &g.n, &g.e);
    for (i = 0; i < g.n; i++) // 初始化邻接矩阵
    {
        for (j = 0; j < g.n; j++)
        {
            g.edges[i][j] = INF; // 邻接矩阵初始化为INF
        }
    }
    printf("请输入每条边的起点、终点和权值:\n");
    for (k = 0; k < g.e; k++) // 输入每条边的起点、终点和权值
    {
        scanf("%d%d%d", &i, &j, &w);
        g.edges[i][j] = w;
        g.edges[j][i] = w; // 无向图的邻接矩阵是对称矩阵
    }
    Kruskal(g); // 调用Kruskal算法求最小生成树

    system("pause");
    return 0;
}
