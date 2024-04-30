#include <iostream>
using namespace std;

void exchange(int n,int b[]){
	int k = 0;
	int x;
	do
	{
		b[k++] = n%2;
		n/=2;
	} while (n);
	for(int i = k-1;i>=0;i--){
		cout<<b[i];
	}
}
int main(){
	int n,b[20];
	cin>>n;
	exchange(n,b);
	system("pause");
	return 0;
}