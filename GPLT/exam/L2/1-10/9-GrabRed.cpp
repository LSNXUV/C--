#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
bool customComparator(const tuple<double, int, int>& a, const tuple<double, int, int>& b) {
    if (get<0>(a) != get<0>(b))     // ��һ�� double ֵ������
        return get<0>(a) > get<0>(b);
    if (get<1>(a) != get<1>(b))    // ��һ�� int ֵ������
        return get<1>(a) > get<1>(b);
    return get<2>(a) < get<2>(b);  // �ڶ��� int ֵ������
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
            get<0>(rens[ren]) += coin;  // ������
            get<1>(rens[ren]) ++ ;      // �������
            get<2>(rens[ren]) = ren;    // �˵ı��
            sum+=coin;
        }
        get<0>(rens[i]) -= sum; // ������
        get<2>(rens[i]) = i;    // �˵ı��
    }
    sort(rens.begin(), rens.end(), customComparator);
    for(auto & ren : rens){
        if(get<2>(ren))
            printf("%d %.2f\n",get<2>(ren),get<0>(ren)/100);
    }
    return 0;
}
