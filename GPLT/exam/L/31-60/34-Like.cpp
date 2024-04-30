#include <iostream>

using namespace std;


int main(){
    int chrc[1001] = {0};
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int m;
        cin>>m;
        for(int j = 0;j<m;j++){
            int c;
            cin>>c;
            chrc[c]++;
        }
    }
    int maxChrcIndex = 1;
    for(int i = 2;i<1001;i++){
        if(chrc[i]>0){
            if(chrc[i] >= chrc[maxChrcIndex])
                maxChrcIndex = i;
        }
    }
    cout<<maxChrcIndex<<" "<<chrc[maxChrcIndex];

    system("pause");
    return 0;
}