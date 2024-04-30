#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    int all = n*m;
    set<int> row,col;
    for(int i = 0;i<q;i++){
        int t,c;
        cin>>t>>c;
        if(t == 0){
            int len = row.size();
            row.insert(c);
            if(row.size() > len)
                all -= m-col.size();
        }else{
            int len = col.size();
            col.insert(c);
            if(col.size() > len)
                all -= n-row.size();
        }
    }
    system("pause");
    return 0;
}
