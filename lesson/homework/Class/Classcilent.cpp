#include <iostream>
using namespace std;

class client {
	private:
		static char ServerName;//静态数据成员，类内定义
		static int ClientName;

	public:
		client();//构造函数
		static void changeServerName(char c);
		void showServerName();
		void showClientName();
};

char client:: ServerName = 'a';
int client::ClientName = 0;
//都在类外定义，加上类名::
client::client() {
	ClientName++;
}

void client::changeServerName(char c) {
	ServerName = c;
}

void client::showServerName() {
	cout << ServerName << endl;
}

void client::showClientName() {
	cout << ClientName << endl;
}

int main(){
int n;//记录客户数量
	cin >> n;
//输入一个客户，处理一个
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		client c1;
		c1.changeServerName(c);
		c1.showServerName();
		c1.showClientName();

	}
    system("pause");
    return 0;
}