#include <iostream>
#include <set>
using namespace std;
double degree(set<int> a,set<int> b){
    int Nc = 0; // 两个集合都有的不相等整数的个数
    int Nt = 0; // 两个集合一共有的不相等整数的个数
    for (int num : a) {
        if (b.find(num) != b.end()) Nc++; 
        Nt++; 
    }
    for (int num : b) {
        if (a.find(num) == a.end()) Nt++;
    }
    return Nc * 1.0 / Nt * 100.0;
}
int main(){
    int n;
    cin>>n;
    set<pair<int,set<int>>> s;
    for(int i = 1;i<=n;i++){
        int m;
        cin>>m;
        set<int> sb;
        while(m--){
            int num;
            cin>>num;
            sb.insert(num);
        }
        s.insert({i,sb});
    }
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        auto it_a = s.begin();
        auto it_b = s.begin();
        advance(it_a, a-1);     //第a个set
        advance(it_b, b-1);     //第b个set
        printf("%.2f%\n", degree(it_a->second, it_b->second));
    }
    return 0;
}