
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
 
void downll(char *str,int n)
{
	int len = strlen(str);					
	for(int i = 0;i < n;i++)				
	{
		char a = str[len-1];				
		for(int j = 0;j < len;j++)			
		{			
			str[len-1-j] = str[len-1-j-1];
		}
		str[0] = a;							
	}
	
}
 
 
int main()
{
	char str[1024] = {0};
	int n;
	
	cin >> str;
	
	cin >> n;
	downll(str,n);
	cout << str << endl;
 
    return 0;
}
