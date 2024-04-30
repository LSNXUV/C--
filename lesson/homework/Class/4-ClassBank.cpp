#include <iostream>
using namespace std;

class Bank {
	private:
		long ID;
		double Balance;
		static double Rational;//静态数据成员，类内声明
	public:
		Bank() {
			ID = 10000;//缺省的默认构造函数
			Balance = 0;
		}
		Bank(long ID, double Balance) {
			this->ID = ID;
			this->Balance = Balance;
		}
		void setID(long id) {
			ID = id;
		}
		void setBalance(double d) {
			Balance = d;
		}
		double getBalance() {
			return Balance;
		}
		void setRational(double r) {
			Rational = r;
		}
		double getRational() {
			return Rational;
		}
		void display() {
			cout << "账号:" << ID << ";   " << "存款:" << Balance << ";   " << "本息:" << Balance *Rational * 0.01 << endl;
		}
};
double Bank::Rational = 2.5;//类外定义

int main() {
	double r;
	cout << "请输入利率:";
	cin >> r;
	//cout << endl;
	cout << "请输入3个账号及对应的存款:" << endl;
	long x1, x2, x3;
	double y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	Bank c;
	c.display();
	Bank c1(x1, y1);
	c1.setRational(r);
	c1.display();
	Bank c2(x2, y2);
	c2.setRational(r);
	c2.display();
	Bank c3(x3, y3);
	c3.setRational(r);
	c3.display();
	cout << "3个账户的本息:" << (y1 + y2 + y3 + (y1 + y2 + y3)*r * 0.01) << endl;
	return 0;
}

