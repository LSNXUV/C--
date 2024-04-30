
#include<iostream>
#include <string>
using namespace std;
void swap(string *a,string *b)
{
	string c;
	c=*a;*a=*b;*b=c;
}
int main()
{
	string a,b,c;
	getline(cin,a);
    getline(cin,b);
    getline(cin,c);
	string *A,*B,*C;
	A=&a;
	B=&b;
	C=&c;
	if(a>b)
	swap(A,B);
	if(a>c)
	swap(A,C);
	if(b>c)
	swap(B,C);
	cout<<a<<'\n'<<b<<'\n'<<c;
	return 0;
}
