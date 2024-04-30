#include <iostream>
using namespace std;
int k, w;
int lost[19][1 << 18]; //lost[i][j]中存储第i轮第j场内失败的选手最大的能力值
int ans[1 << 18];       //ans数组存储每个选手的能力值
int win[19][1 << 18];   //存储第i轮第j场赢的人在ans数组中的下标。
int main() {
    cin >> k;
    for (int i = 1; i <= k; i++) {      //k轮比赛
        for (int j = 0; j < (1 << (k - i)); j++) {  //第i轮比赛有2^(k-i)个选手  
            cin >> lost[i][j];
            if (i == 1) {
                ans[j << 1] = lost[i][j];   
                win[i][j] = j << 1 | 1;
            } else {
                if (lost[i][j] < lost[i - 1][j << 1] && lost[i][j] < lost[i - 1][j << 1 | 1]) {
                    cout << "No Solution";
                    return 0;
                } else if (lost[i][j] >= lost[i - 1][j << 1]) {     
                    ans[win[i - 1][j << 1]] = lost[i][j];                       win[i][j] = win[i - 1][j << 1 | 1]; 
                } else {
                    ans[win[i - 1][j << 1 | 1]] = lost[i][j];
                    win[i][j] = win[i - 1][j << 1];
                }
                lost[i][j] = max(lost[i][j], max(lost[i - 1][j << 1], lost[i - 1][j << 1 | 1])); 
            }
        }
    }
    cin >> w;
    if(lost[k][0] > w) {
        cout << "No Solution";
        return 0;
    }
    ans[win[k][0]] = w;
    for (int i = 0; i < 1 << k; i++) {
        if (i) cout << ' ';
        cout << ans[i] ;
    }
    return 0;
}