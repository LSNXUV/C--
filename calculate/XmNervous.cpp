
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
	vector<int> num1,num2,num3,num4,num5,num6,num7,num8;
	int size[8]={0};
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string a;
		int zhi;
		cin>>a>>zhi;
		if(a=="QBH")
			num1.push_back(zhi);
		else if(a=="PPY")
			num2.push_back(zhi);
		else if(a=="NZXM")
			num3.push_back(zhi);
		else if(a=="PPG")
			num4.push_back(zhi);
		else if(a=="WJJ")
			num5.push_back(zhi);
		else if(a=="ZZZ")
			num6.push_back(zhi);
		else if(a=="RYAN")
			num7.push_back(zhi);
		else if(a=="HCC")
			num8.push_back(zhi);
	}
	int s=0;
	for(int p1=0;p1<num1.size();p1++)
	{
		for(int p2=0;p2<num2.size();p2++)
		{
			for(int p3=0;p3<num3.size();p3++)
			{
				for(int p4=0;p4<num4.size();p4++)
				{
					for(int p5=0;p5<num5.size();p5++)
					{
						for(int p6=0;p6<num6.size();p6++)
						{
							for(int p7=0;p7<num7.size();p7++)
							{
								for(int p8=0;p8<num8.size();p8++)
								{
										long long money;
										money = (num1[p1]+num6[p6])*
											(num5[p5]+num3[p3]+num2[p2])*
											(num6[p6]+num8[p8])*
											(num7[p7]+num4[p4]);
											if(money%2 == 0)
											{
												//cout << money << endl;
												s++;
											}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << s << endl;
	return 0;
}