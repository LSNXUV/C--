#include <iostream>
#include <set>
using namespace std;
int main() {
    int start,N;
    cin>>start>>N;
    int value[100000];
    int next[100000];
    for(int i = 0;i<N;i++){
        int addr;
        cin>>addr>>value[addr]>>next[addr];
    }
    int *newList = new int[N];  
    int *repeatList = new int[N];
    set<int> rps;
    int len = 0,rlen = 0;       //记录去重后的长度和重复的长度！！！！！！！！！！！
    for(int i = start;i != -1;i = next[i]){
        if(rps.find(abs(value[i])) != rps.end()){
            repeatList[rlen++] = i;
        }else{
            newList[len++] =i;
            rps.insert(abs(value[i]));
        }
    }
    for(int i = 0;i<len-1;i++){
        printf("%05d %d %05d\n",newList[i],value[newList[i]],newList[i+1]);
    }
    printf("%05d %d %d\n",newList[len-1],value[newList[len-1]],-1);
    for(int i = 0;i<rlen-1;i++){
        printf("%05d %d %05d\n",repeatList[i],value[repeatList[i]],repeatList[i+1]);
    }
    if(rlen > 0)    //注意这里的判断！！！！！！！！！！！
        printf("%05d %d %d\n",repeatList[rlen-1],value[repeatList[rlen-1]],-1);
    return 0;
}
