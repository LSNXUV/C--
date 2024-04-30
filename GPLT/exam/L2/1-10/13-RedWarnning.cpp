#include <iostream>
using namespace std;

const int MAX_CITES = 510;
int uf[MAX_CITES], roads[MAX_CITES][MAX_CITES]; // uf����洢���鼯��roads����洢��·��Ϣ

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
        uf[i] = i; // ��ʼ��
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        uf[find(a)] = find(b);      // a�ĸ��ڵ�ָ��b�ĸ��ڵ�
        roads[a][b] = roads[b][a] = 1; // ���
    }
    int k, city, cnt1 = 0; // cnt1��¼��ռǰ����ͨ��������
    for (int i = 0; i < N; i++)
        if (find(i) == i)
            cnt1++;
    cout<<"�������ͨ��������Ϊ��"<<cnt1<<endl; 
    cin >> k;
    while (k--)
    {
        int cnt2 = 0; // cnt2��¼��ռ�����ͨ��������
        cin >> city;
        for (int i = 0; i < N; i++)
            roads[city][i] = roads[i][city] = 0; // ��ռ֮��ȡ�����
        for (int i = 0; i < N; i++)
            uf[i] = i; // ���³�ʼ��
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
        cnt1 = cnt2; // ���¹�ռǰ����ͨ����
    }
    if (k == N)
        cout << "Game Over."; // ��ʾȫ������ͨ
    return 0;
}