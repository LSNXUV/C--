#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    // ʹ���ڽӱ��ʾ��ϵͼ
    vector<vector<int>> relations(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; ++i) {
        int p1, p2, rel;
        cin >> p1 >> p2 >> rel;
        relations[p1][p2] = relations[p2][p1] = rel;
    }

    // �����ڽӱ���ٲ��ҹ�ͬ���Ѻ͵���
    unordered_map<int, vector<int>> friends, enemies;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (relations[i][j] == 1) {
                friends[i].push_back(j);
                friends[j].push_back(i);
            } else if (relations[i][j] == -1) {
                enemies[i].push_back(j);
                enemies[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < K; ++i) {
        int p1, p2;
        cin >> p1 >> p2;
        if (relations[p1][p2] == 1) {
            cout << "No problem" << endl;
        } else if (relations[p1][p2] == -1) {
            bool hasCommonFriend = false;
            // ����Ƿ��й�ͬ����
            for (int friend1 : friends[p1]) {
                for (int friend2 : friends[p2]) {
                    if (friend1 == friend2) {
                        hasCommonFriend = true;
                        break;
                    }
                }
                if (hasCommonFriend) break;
            }
            if (hasCommonFriend) {
                cout << "OK but..." << endl;
            } else {
                cout << "No way" << endl;
            }
        } else {
            cout << "OK" << endl;
        }
    }

    return 0;
}
