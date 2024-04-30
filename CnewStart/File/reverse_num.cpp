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
    int a;
    cin>>a;
    if(a<0){
        cout<<"error";
    }else
    cout<<InvertSequence(a);

    system("pause");
    return 0;
}