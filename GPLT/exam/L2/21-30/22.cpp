#include <iostream>
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
    int *oldList = new int[N];
    int len = 0;    //记录实际长度！！！！！！！！！！！
    for(int i = start;i != -1;i = next[i]){
        oldList[len++] =i;
    }
    int *newList = new int[len];
    for(int i = 1;i <= len/2;i++){
        newList[(i-1)*2] = oldList[len-i];
        newList[i*2-1] = oldList[i-1];
    }
    if(len % 2 != 0) newList[len-1] = oldList[(len-1)/2];
    for(int i = 0;i<len-1;i++){
        printf("%05d %d %05d\n",newList[i],value[newList[i]],newList[i+1]);
    }
    printf("%05d %d %d\n",newList[len-1],value[newList[len-1]],-1);
    system("pause");
    return 0;
}
