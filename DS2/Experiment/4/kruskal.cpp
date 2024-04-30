
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const short INF = 32767; // ����short���͵����ֵ
const int MaxSize = 100; // ������󶥵���

typedef struct node
{
    int data;   // ����Ӧ������
    int rank;   // ����Ӧ��
    int parent; // ����Ӧ˫���±�
} UFSTree;      // ���鼯���Ľ������

typedef struct
{
    int u; // �ߵ���ʼ����
    int v; // �ߵ���ֹ����
    int w; // �ߵ�Ȩֵ
} Edge;


typedef struct {
    int n; // ������
    int e; // ����
    int edges[MaxSize][MaxSize]; // �ڽӾ���
} MGraph;

void MAKE_SET(UFSTree t[], int n) // ��ʼ�����鼯��
{
    for (int i = 0; i < n; i++) // ������Ϊ0��(n-1)
    {
        t[i].rank = 0;   // �ȳ�ʼ��Ϊ0
        t[i].parent = i; // ˫�׳�ʼ��ָ������
    }
}
int FIND_SET(UFSTree t[], int x) // ��x���������в��Ҽ��ϵı��
{
    if (x != t[x].parent)                  // ��˫�ײ�������
        return (FIND_SET(t, t[x].parent)); // �ݹ���˫������x
    else
        return (x); // ��˫��������,����x
}

void UNION(UFSTree t[], int x, int y) // ��x��y���ڵ������ϲ�
{
    x = FIND_SET(t, x);
    y = FIND_SET(t, y);
    if (t[x].rank > t[y].rank) // x�����ȴ���y������
        t[y].parent = x;       // ��x�����Ϊy��˫�׽��
    else                       // y�����ȴ��ڵ���x������
    {
        t[x].parent = y;            // ��y�����Ϊx��˫�׽��
        if (t[x].rank == t[y].rank) // x��y��������ͬ
            t[y].rank++;            // y��������1
    }
}

bool compareEdges(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

void Kruskal(MGraph g) // Kruskal�㷨
{
    int i, j, k, u1, v1, sn1, sn2;
    UFSTree t[MaxSize];
    Edge E[MaxSize];
    k = 0;
    for (i = 0; i < g.n; i++) // ��g�����ǲ��ֲ����ı߼�E
        for (j = 0; j < i; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }
    sort(E, E + k,compareEdges);   // ����STL��sort()�㷨��w��������
    MAKE_SET(t, g.n); // ��ʼ�����鼯��t
    k = 1;            // k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
    j = 0;            // E�бߵ��±�,��ֵΪ0
    while (k < g.n)   // ���ɵı���С��nʱѭ��
    {
        u1 = E[j].u;
        v1 = E[j].v; // ȡһ���ߵ�ͷβ������u1��v2
        sn1 = FIND_SET(t, u1);
        sn2 = FIND_SET(t, v1); // �ֱ�õ��������������ļ��ϱ��
        if (sn1 != sn2)
        // ��Ӹñ߲��ṹ�ɻ�·,������Ϊ��С��������һ�������
        {
            printf("��ӱ�  (%d,%d):%d\n", u1, v1, E[j].w);
            k++;              // ���ɱ�����1
            UNION(t, u1, v1); // ��u1��v1��������ϲ�
        }
        j++; // ɨ����һ����
    }
}


int main()
{
    MGraph g;
    int i, j, k, w;
    printf("�����붥�����ͱ���:\n");
    scanf("%d%d", &g.n, &g.e);
    for (i = 0; i < g.n; i++) // ��ʼ���ڽӾ���
    {
        for (j = 0; j < g.n; j++)
        {
            g.edges[i][j] = INF; // �ڽӾ����ʼ��ΪINF
        }
    }
    printf("������ÿ���ߵ���㡢�յ��Ȩֵ:\n");
    for (k = 0; k < g.e; k++) // ����ÿ���ߵ���㡢�յ��Ȩֵ
    {
        scanf("%d%d%d", &i, &j, &w);
        g.edges[i][j] = w;
        g.edges[j][i] = w; // ����ͼ���ڽӾ����ǶԳƾ���
    }
    Kruskal(g); // ����Kruskal�㷨����С������

    system("pause");
    return 0;
}
