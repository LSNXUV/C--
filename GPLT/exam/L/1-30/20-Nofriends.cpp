#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n,m,id,friends[100000],s;
    memset(friends, 0, sizeof(friends));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> id;
            if(m > 1)
                friends[id]++;
        }
    }
    bool flag = true;
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> id;
        if (friends[id] == 0){
            friends[id] = 1;
            if (flag) {
                printf("%05d", id);
                flag = false;
            } else {
                printf(" %05d", id);
            }
        }
    }
    if (flag) {
        cout << "No one is handsome";
    }

    system("pause");
    return 0;
}