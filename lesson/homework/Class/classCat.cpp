#include <iostream>
using namespace std;
class Cat
{
private:
	int age;
	static int HowManyCats;
public:
	Cat(int a){age = a;HowManyCats++;}
	~Cat(){HowManyCats--;cout << "destructing of the cat!" << endl;}
	static int GetHowMany(){return HowManyCats;}
};
 
int Cat::HowManyCats = 0;
void creating(Cat* arr[],int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		arr[i] = new Cat(i+1);
	}
}
//减去m个猫
void outcat(Cat* arr[],int n,int m)
{
	int i ;
	for (i = 0; i < m;i++)
	{
		delete arr[n -1-i];
		arr[n -1-i] = 0;
	}
}
int main()
{
	Cat* arr[5];
	cout << "before the function,the number of the cat is:" << Cat::GetHowMany() << endl;
	cout << "before the Cat array is created,the number of the cat is:" << Cat::GetHowMany() << endl;
	creating(arr,5);
	cout << "after the Cat array is created,the number of the cat is:"<< Cat::GetHowMany() << endl;
	outcat(arr,5,5);
	cout << "after the function,the number of the cat is:" << Cat::GetHowMany() << endl;
	return 0;
}