#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double allKf(vector<vector<int>>& rens,vector<double>& kf,int sf,double Z,double& r){
    double curKf = kf[sf] * Z * (sf != 0 ? (1-r/100) : 1);
    if(rens[sf].size() == 0) return curKf;
    double all = 0;
    for(int i = 0;i<(int)rens[sf].size();i++){
        all += allKf(rens,kf,rens[sf][i],curKf,r);
    }
    return all;
}
int main() {
    int N;
    double Z,r;
    cin>>N>>Z>>r;
    vector<vector<int>> rens(N);
    vector<double> kf(N,1.0);
    for(int i = 0;i<N;i++){
        int k,apprentice;
        cin>>k;
        if(k == 0){
            cin>>kf[i];
            continue;
        }
        while(k--){
            cin>>apprentice;
            rens[i].push_back(apprentice);
        }
    }
    cout<<int(allKf(rens,kf,0,Z,r));
    return 0;
}
