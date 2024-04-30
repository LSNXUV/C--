#include <stdio.h>



int main(){
    //输出不超过m的最大完全数
    int m,i,j;
    scanf("%d",&m);
    for(i=m;i>=6;i--){
		int sum=0; //计数器：计算因子相加的和 
		for(j=1;j<=i/2;j++){ //计算真因子 
			if(i%j==0) sum+=j;
		}
		if(i==sum){
            printf("%d",sum);
            break;
        }
        
         //判断、输出 
	}

    return 0;

}
