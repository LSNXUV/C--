
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
char a[10000+10];
int b[10000+10];
int main(){
	int m;
	cin>>m;
	scanf("%s",a);
	if(m==1){
		for(int i=0;i<strlen(a)-1;i++){
			if(a[i]!=a[i+1]){
				printf("%c",a[i]);
			}else{
				int tot=0;
				while(a[i]==a[i+1]){
					tot++;
					i++;
				}
				tot+=1;
				printf("%c%d",a[i],tot);
			}
			if(i==strlen(a)-2)
				printf("%c",a[i+1]);
		} 
		
	}else{
		long long sum=0;
		int p=0;
		char tc;
		for(int i=0;i<strlen(a);){
			if(a[i]>=97&&a[i]<=122){	//字母 
				printf("%c",a[i]);
				tc=a[i];
				i++;
			}
			else{		//数字 
				while(a[i]>=48&&a[i]<=57)
					b[p++]=a[i++]-'0';
					int o=0;
					while(--p>=0){
						sum+=b[p]*pow(10,o);
						o++;
					}
					for(int i=0;i<sum-1;i++){
						printf("%c",tc);
					}
//调试					cout<<"\t"<<sum<<endl;
					p=0;
					sum=0; 
			}
		}
	}
	return 0;
}