#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
bool customComparator(const tuple<double, int, int>& a, const tuple<double, int, int>& b) {
    if (get<0>(a) != get<0>(b))     // 第一个 double 值，降序
        return get<0>(a) > get<0>(b);
    if (get<1>(a) != get<1>(b))    // 第一个 int 值，降序
        return get<1>(a) > get<1>(b);
    return get<2>(a) < get<2>(b);  // 第二个 int 值，升序
}
int main() {
    int N;
    cin>>N;
    vector<tuple<double,int,int>> rens(N+1,make_tuple(0.0, 0, 0));
    for(int i = 1;i<=N;i++){
        int n;
        cin>>n;
        int sum = 0;
        while(n--){
            int ren,coin;
            cin>>ren>>coin;
            get<0>(rens[ren]) += coin;  // 红包金额
            get<1>(rens[ren]) ++ ;      // 红包个数
            get<2>(rens[ren]) = ren;    // 人的编号
            sum+=coin;
        }
        get<0>(rens[i]) -= sum; // 红包金额
        get<2>(rens[i]) = i;    // 人的编号
    }
    sort(rens.begin(), rens.end(), customComparator);
    for(auto & ren : rens){
        if(get<2>(ren))
            printf("%d %.2f\n",get<2>(ren),get<0>(ren)/100);
    }
    return 0;
}
