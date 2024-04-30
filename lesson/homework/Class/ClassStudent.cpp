#include<iostream>
#include<string>
using namespace std;
class  Student
{
	   private:
	   	       string name;//姓名 
	   	       int  classes;//学号
			   static int number; //班级人数
			   static int student;//班级 
       public:
       	       Student(string name);//name的构造函数 
			  Student(Student &s)
			  {
			  	 name=s.name;
			  }
       	      int Print();
                friend  void  Output(Student s);//友元函数 
};
int Student::number=47;
int Student::student=1001; //静态数据成员只能类外初始化 
Student::Student(string soname)
{
	name=soname;//名字的构造函数的初始化（类外实现）	
}
void Output(Student s)
{    cout<<"名字:"<<s.name<<endl;
     cout<<"学号:"<<2<<endl<<"班级:"<<s.student <<endl<<"班级人数:"<<s.number<<endl<<endl; 
 } 
int Student::Print()
{
	cout<<"名字:"<<name<<endl;
	cout<<"学号:"<<1<<endl<<"班级:"<<student<<endl<<"班级人数:"<<number<<endl; 
}
int  main()
{
     string someone1,someone2;
     cin>>someone1;
     cin>>someone2;//输入两个新生的名字 
     Student stu(someone1);
     stu.Print();//通过类的成员函数输出学生someone1的信息 
     Student b(someone2);
     Output(b);//通过友元函数输出学生someone2的信息
     
     system("pause");
     return  0;
}