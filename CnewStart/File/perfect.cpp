#include <iostream>
using namespace std;



int main(){
    int n,max;
    // int arr[10];
	cin>>n;
	for(int i=1;i<=n;i++){
		int sum=0; //计数器：计算因子相加的和 
		for(int j=1;j<i;j++){ //计算真因子 
			if(i%j==0) sum+=j;
		}
		if(i==sum) max = i; //判断、输出 
	}
    cout<<max;

    system("pause");
    return 0;
}