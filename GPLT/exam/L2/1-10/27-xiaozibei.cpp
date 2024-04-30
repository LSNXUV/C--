#include <iostream>
using namespace std;

int parent[100000];     // �洢ÿ���˵ĸ�ĸ
int gen[100000];        // �洢ÿ���˵ı���

int find(int x) {       // �ݹ����ÿ���˵ı���
    if(parent[x] == -1) return 1;   // �����ڵı���Ϊ1
    if(gen[x] == 0)   // �����ǰ�˵ı��ֻ�û�м����
        return gen[x] = find(parent[x]) + 1;    // ��ǰ�˵ı��ֵ����丸ĸ�ı���+1
    else 
        return gen[x];  // �Ѿ��������ֱ�ӷ���
}
int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> parent[i];
        gen[i] = 0;   // ��ʼ������Ϊ0
    }

    for(int i = 1; i <= N; i++) {
        gen[i] = find(i);   // ����ÿ���˵ı���
    }
    // �ҳ����ı���
    int max = 1;    
    for(int i = 1; i <= N; i++) {
        if(gen[i] >= max) max = gen[i]; 
    }
    cout << max << endl;
    int cnt = 0;    // ��ʽ����
    for(int i = 1; i <= N; i++) {
        if(gen[i] == max){
            if(cnt) cout << " ";
            cout << i;
            cnt++;
        }
    }
}
