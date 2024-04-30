#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct Stack {
    int stack[100];
} Stack;

int main() {
    int n;
    cin >> n;
    queue<int> Q;
    stack<int> S;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Q.push(x);
    }
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        S.push(x);
    }
    while (!S.empty()) {
        int x = S.top();
        S.pop();
        Q.push(x);
    }
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        cout << x << " ";
    }
    system("pause");
    return 0;
}

