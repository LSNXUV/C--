#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> v(510); //�洢ͼ���ڽӱ�v[i]�洢��ڵ�i���ڵĽڵ�
vector<int> color(510);    //�洢ÿ���ڵ����ɫ
bool verify(int n) {    //nΪ�ڵ���
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < v[i].size(); j++)    
            if(color[i] == color[v[i][j]])  // �����ڽڵ���ɫ��ͬ,ֱ�ӷ���false
                return false;
    }
    return true;
}
int main() {
    int n, m, k, num;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);    // ����ͼ,�����ڵ��໥�洢
        v[v2].push_back(v1);   
    }
    cin >> num;
    set<int> s;
    while(num--) {
        s.clear();
        for(int i = 1; i <= n; i++) {
            cin >> color[i];
            s.insert(color[i]);
        }
        if(s.size() != k ) {    // ��ɫ���಻����k,ֱ�����No
            cout << "No\n";
        }else if(!verify(n))     // ��ɫ�������k,�������ڽڵ���ɫ��ͬ,���No
            cout << "No\n";
        else                   
            cout << "Yes\n";
    }
    return 0;
}