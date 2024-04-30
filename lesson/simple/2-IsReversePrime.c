#include <stdio.h>
int pd(int x){//判断是否为素数 
	int i;
	if(x<2) return 0;
	if(x==2) return 1;
	for(i=2;i<x;i++)
		if(x%i==0) return 0;			
	return 1;
}

int ns(int x){//逆序 
	int y=0;
	while(x>0){
		y=y*10+x%10;
		x=x/10;
	}
	return y;
}

int main()
{
	int x;
	scanf("%d",&x);
	int y=ns(x);
	if(pd(x)==0){
		printf("no");
	}else{
		if(pd(y)==0){
			printf("no");
		}else{
			printf("yes");
		}
	}
    return 0;
}
