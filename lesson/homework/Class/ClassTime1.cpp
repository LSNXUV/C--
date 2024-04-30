#include<iostream>
using namespace std;
class Time
{
public:
	//一般放在private里
	int h, m, s;
 
	//区分两种自加自减，int为占位参数，可用于区分前后置 
	 Time &operator--();//--t 先自减，后取值
	 Time &operator++();//++t
	 Time operator--(int n);//t-- 先取值，后自减
	 Time operator++(int n);//t++
	 
 
	 Time &operator+=(const Time& t);//累加
	 Time &operator-=(const Time& t);//累减
 
	 //输入和输出的重载最好使用友元friend
	 //友元函数：让一个函数或类能够访问另一个类中私有成员
	 friend ostream& operator<<(ostream& os, const Time& t);//输出
	 friend istream& operator>>(istream& is, const Time& t);//输入
};
 
/*t++*/
//类外定义类里面的函数要用到Time::
Time Time:: operator++(int n)
{
	//this指针:	指向被调用的成员函数所属的对象无需定义，直接使用
	//先保存当前值，最后返回这个没有改变的值，符合先取值，再++的特点
	Time temp = *this;
	int ss, mm, hh;
	ss = s + 1;
	s = ss % 60;
	mm = ss / 60 + m ;
	m = mm % 60;
	hh = m / 60 + h ;
	h = hh % 24;
	return temp;
}
/*t--*/
Time Time:: operator--(int n)
{
	Time temp = *this;
	if (s >= 1)
		s -= 1;
	else
	{
		s = 59;
		if (m >= 1)
			m--;
		else
		{
			m = 59;
			if (h >= 1)
				h--;
			else
				h = 23;
		}
	}
	return temp;
}
 
/*++t*/
Time& Time:: operator++()
{
	int ss, mm, hh;
	ss = s + 1;
	s = ss % 60;
	mm = ss / 60 + m;
	m = mm % 60;
	hh = mm / 60 + h;
	h = hh % 24;
	return *this;
}
/*--t*/
Time& Time:: operator--()
{
	if (s >= 1)
		s -= 1;
	else
	{
		s = 59;
		if (m >= 1)
			m--;
		else
		{
			m = 59;
			if (h >= 1)
				h--;
			else
				h = 23;
		}
	}
	return *this;
}
/*累加*/
Time&Time:: operator+=(const Time &t)
{
	int ss, mm, hh;
	ss =s+ t.s;
	s = ss % 60;
	mm = ss / 60 + m + t.m;
	m = mm % 60;
	hh = mm / 60 + h + t.h;
	h = hh % 24;
	return *this;
}
/*累减*/
Time& Time:: operator-=(const Time& t)
{
	if (s >= t.s)
		s -= t.s;
	else
	{
		s += 60 - t.s;
		m--;
	}
	if (m >= t.m)
		m -= t.m;
	else
	{
		m += 60 - t.m;
		h--;
	}
	if (h >= t.h)
		h -= t.h;
	else
	{
		h += 24 - t.h;
	}
	return *this;
}
/*输出*/
ostream& operator<<(ostream& os, const Time& t)
{
	if (t.h < 10)
		os << "0" << t.h << ":";
	else if (t.h >= 10)
		os << t.h << ":";
	if (t.m < 10)
		os << "0" << t.m << ":";
	else if (t.m >= 10)
		os << t.m << ":";
	if (t.s < 10)
		os << "0" << t.s;
	else if (t.s >= 10)
		os << t.s;
	return os;
}
/*输入*/
istream& operator>>(istream& is, Time& t)
{
	is >> t.h >> t.m >> t.s;
	//判断输入是否成功
	if (!is)
		t = Time();
	return is;
}
int main()
{
	Time t1, t2;
	cin >> t1 >> t2;
 
	t1 += (t2++);
	cout << t1 << endl;
		
	t1 -= t2;
	cout << t1 << endl;
 
	++t2;
	cout << t2 << endl;
 
	t2 += (t1--);
	cout << t2 << endl;
 
	--t1;
	cout << t1 << endl;
 
	t2 -= t1;
	cout << t2;
	return 0;
}
