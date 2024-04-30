#include <iostream>
using namespace std;

int InvertSequence(int num){
    int result = 0;
	for (int i = num; i ; )
	{
		i = i/10*10;
		result = result * 10 + num - i;
		i = i /10;
		num = num/10;
	}
    return result;
}

int main(){
    int a,b;
    cin>>a>>b;
    for(int i = a;i<=b;i++){
        if(i==InvertSequence(i))
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}