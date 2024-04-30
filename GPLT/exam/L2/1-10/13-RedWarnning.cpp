#include <iostream>
using namespace std;

const int MAX_CITES = 510;
int uf[MAX_CITES], roads[MAX_CITES][MAX_CITES]; // uf数组存储并查集，roads数组存储道路信息

int find(int x)
{
    if (x != uf[x])
        uf[x] = find(uf[x]);
    return uf[x];
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        uf[i] = i; // 初始化
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        uf[find(a)] = find(b);      // a的根节点指向b的根节点
        roads[a][b] = roads[b][a] = 1; // 标记
    }
    int k, city, cnt1 = 0; // cnt1记录攻占前的连通分量个数
    for (int i = 0; i < N; i++)
        if (find(i) == i)
            cnt1++;
    cout<<"最初的连通分量个数为："<<cnt1<<endl; 
    cin >> k;
    while (k--)
    {
        int cnt2 = 0; // cnt2记录攻占后的连通分量个数
        cin >> city;
        for (int i = 0; i < N; i++)
            roads[city][i] = roads[i][city] = 0; // 攻占之后取消标记
        for (int i = 0; i < N; i++)
            uf[i] = i; // 重新初始化
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (roads[i][j])
                    uf[find(i)] = find(j);
        for (int i = 0; i < N; i++)
            if (find(i) == i)
                cnt2++;
        if (cnt2 - cnt1 > 1)
            printf("Red Alert: City %d is lost!\n", city);
        else
            printf("City %d is lost.\n", city);
        cnt1 = cnt2; // 更新攻占前的连通分量
    }
    if (k == N)
        cout << "Game Over."; // 表示全部不连通
    return 0;
}