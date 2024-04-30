#include<iostream>
#include<set>
#include<tuple>
using namespace std;
int main()
{
    int n;
    int max;
    cin>>n>>max;
    double moon[1000] = {0};
    for(int i = 0 ;i<n;i++){
        cin>>moon[i];
    }
    using Moon = tuple<double,double,double,int>;
    set<Moon,greater<>> moons;
    for(int i = 0 ;i<n;i++){
        double total;
        cin>>total;
        moons.insert({total/moon[i],moon[i],total,i});
    }
    double sum = 0;
    for (const auto& moon : moons) {
        if(max > get<1>(moon)){
            max -= get<1>(moon);
            sum += get<2>(moon);
        }else if(max){
            sum += max * get<0>(moon);
            max = 0;
        }
    }
    printf("%.2f\n",sum);
    return 0;
 }