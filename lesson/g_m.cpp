#include<iostream> 
#include<fstream>
#include<string.h>
#include<conio.h>


int code();//登录密码
using namespace std;
// Student类
class Student
{
	public:
		char name[20];
		char Id[20];
		int Date;//学生出生日期 
		int Age;//学生年龄 
		int Cnum;//C++分数 
		int Mnum;//数学分数 
		int Enum;//英语分数 
		int sum;//总分 
		Student*Next;
		void Input()
		{
		cout<<"\t\t 请输入学生的姓名:";
		cin>>name;
		cout<<"\t\t 请输入学生的学号:";
		cin >>Id;
		cout<<"\t\t 请输入学生的出生时间："; 
		cin>>Date;
        cout<<"\t\t 请输入 C++课程的成绩："; 
		cin>>Cnum;cout<<"\t\t 请输入数学课程的成绩："; 
		cin>>Mnum;cout<<"\t\t 请输入英语课程的成绩："; 
		cin>>Enum;sum=Cnum+Mnum+Enum;Age=2011-Date;
	    }
        void ReadFile (istream& in)
		{
		
        cin>>name>>Id>>Date>>Age>>Cnum>>Mnum>>Enum>>sum;
		}
        
       	void Show()
		   {
		   
				cout<<"姓名:"<<name<<endl
				<<"学号:"<<Id<<endl
				<<"出生日期:"<<Date<<endl
				<<"年龄:"<<Age<<endl
				<<"C++:"<<Cnum<<endl
				<<"数学:"<<Mnum<<endl
				<<"外语:"<<Enum<<endl
				<<"总成绩:"<<sum<<endl<<endl<<endl;
			}
};
		
//Studentmessage类
class Studentmessage:public Student
{

public: 
		Studentmessage();
		~Studentmessage();
		void ShowMenu();
		void Find();
		void Save();
		void Modifyltem();
		void Removeltem();
		void Sort();
		int ListCount();
			void Display()
			{
			
				for(Student * p=Head->Next;p!=End;p=p->Next)
					p->Show();
				cout<<"输入任意字符！继续……";
				getch();
			} 
			void Addltem()
			{
			
				End->Input();
				End->Next=new Student;
				End=End->Next;
			cout<<"添加成功!"<<endl;
			cout<<"输入任意字符！继续……";
			getch();
			}
			private:
				Student * Head,* End;
				ifstream in;
				ofstream out;
				int FindItem(char*name,Student*a[])//保存查找到的指针保存到数组，返回当前数组保存指针数 
				{
					int i=0;
					for(Student * p=Head;p->Next!=End;p=p->Next)
					if(!strcmp(p->Next->name,name))
					{
				
						a[i]=p;i++;
					}
					
					if(i==0)
					return 0;
					else
					{
			
						a[i]=End;
						return i;
					}
				}
				Student *FindID(char * Id)
				{
					for(Student*p=Head;p->Next!=End;p=p->Next)
						if(!strcmp(p->Next->Id,Id))
						return p;
						return NULL;
				}
				
};
//登录密码
int code()
{

	int i=0,j=0;
	int c;
	char name[15],cod[15];
	cout<<"\n\n";
	while(j<3)
	{
	
		cout<<"\t\t 管理员:";
		cin.getline(name,sizeof(name));//用cin不包括空格符;
		cout<<endl<<"\t\t 输入密码:";j++;
		c=getch();
		while(c !='\r')//回车
		{
		
			if(i>= 0)
			{
				if(c=='\b')
				{
				
				cout<<"\b\b";
				i=i-1;
				}
			else
			{
				cout<<"*";
				cod[i]=c;
			}
		}
		c=getch();
		if(c!='\b')	
			i=i+1;
			
	}
		cod[i]='\0';
		cout<<endl<<endl<<"\t\t";
		if((strcmp(name,"1")==0)&&(strcmp(cod,"111")==0)||(strcmp(name,"2")==0)&&(strcmp(cod,"222")==0))
		{
			cout<<"登陆成功！\n\n";j=4;break;
		}
		else
			{
			if((strcmp(name,"***")==0)||(strcmp(name,"***")==0))
			cout<<"登陆失败！密码错误！！！\n\n";
			else cout<<"登陆失败！管理员不存在！！！\n\n";
			}
		}
}
//构造函数
Studentmessage::Studentmessage()
{
    Head=new Student;
	Head->Next=new Student;
	End=Head->Next;
in.open("sort.txt");
if(!in)
		cout<<"\t\t 这是一个新系统，无学生信息。请先输入。"<<endl;
	else
	{

		while(!in.eof())
		{
		
			End->ReadFile(in);
			if(End->name[0]=='\0')break;
			End->Next=new Student;
			End=End->Next;
		}
		in.close();
		cout<<"\t\t 读取学生信息成功!"<<endl;
	}
}
//析构函数
Studentmessage::~Studentmessage()
{

	Save();
	for(Student *temp;Head->Next!=End;)
	{	
		temp=Head->Next;	
	Head->Next=Head->Next->Next;
	delete temp;
	}
	delete Head,End;
}
//菜单
void Studentmessage::ShowMenu()
{

	cout<<"※※※※※※※※※※※学生成绩管理系统※※※※※※※※※※※"<<endl;
cout<<"◆ ◆                                                   ^^^^^^^^^^^^^^^^^◆ ◆"<<endl;
cout<<"◆◆                              1.增加学生成绩◆◆"<<endl;
cout<<"◆◆                              2.显示学生成绩◆◆"<<endl;
cout<<"◆◆                              3.排序统计成绩◆◆"<<endl;
cout<<"◆◆                              4.查找学生成绩◆◆"<<endl;
cout<<"◆◆                              5.删除学生成绩◆◆"<<endl;
cout<<"◆◆                              6.修改学生信息◆◆"<<endl; 
cout<<"※※※※※※※※※※※                  0.安全退出系统※※※※※※※※※※※  "<<endl;
cout<<"\n\t\t\n\t\t 请选择：";
}

//查找函数
void Studentmessage::Find()
{

	char name[20],Id[10];
	int x,k;
	Student* p=NULL,*a[6];
	cout<<"\n\t\t*********************************\n";
	cout<<"\t\t※ 1.按学生的姓名··※\n\t\t※2.按学生学号查找※";
	cout<<"\n\t\t*********************************\n 请选择：";
	cin>>x;
	switch(x)
	{
		case 1:
			{	

				cout<<"\t\t 请输入要查找的学生的姓名：";cin>>name;
				if(k==FindItem(name,a))
				{

					for(int i=0;a[i]!=End;i++)
					{

						a[i]->Next->Show();
					}
					cout<<"输入任意字符！继续……";
					getch();
				}
				else
				{
					cout<<"\t\t 没有找到该姓名的学生！"<<'\n'<<endl;
					cout<<"输入任意字符！继续……";
					getch();
					}	
					break;
					}
					case 2:
					{
						cout<<"\t\t 请输入要查找的学生的学号：";cin>>Id;
						if(p=FindID(Id)) 
						{
						p->Next->Show();
						cout<<"输入任意字符！继续……";
						getch();
						}
						else
						{
							cout<<"\t\t 没有找到该学号的学生！"<<'\n'<<endl;
							cout<<"输入任意字符！继续……";
							getch();
						}		
						break;
						}
	}
}
//修改信息
void Studentmessage::Modifyltem()
{

char name[20];int k=0,te,t,x;
Student *p=NULL,*a[6];
cout<<"\n\t\t*********************************\n";
cout<<"\t\t※ 1.按学生的姓名※※※\n\t\t※ 2.按学生学号查找※";
cout<<"\n\t\t*********************************\n请选择：";
cin>>x;
switch(x)
{
	
	case 1:{
	
	cout<<"\t\t 请输入要修改的人的姓名：";cin>>name;//找到单个学生直接删除
	if(te=FindItem(name,a))
	{

		if(te==1)
		{

		a[0]->Next->Input();
		cout<<"修改成功！"<<endl;
		cout<<"输入任意字符！继续……";
		getch();
		}
		else
		{

			cout<<"\t\t 找到多个学生的信息!"<<endl;//找到多个学生选择删除
			for(int i=0;a[i]!=End;i++)
			{
				cout<<"第"<<i+1<<"学生:\n";
				a[i]->Next->Show();
			}	
			cout<<"\t\t 需要修改哪个学生的信息，请选择:";
			cin>>t;
			a[t-1]->Next->Input();
			cout<<"修改成功！"<<endl;
			cout<<"输入任意字符！继续……";
			getch();
		}
	}
	else
	{
	
		cout<<"\t\t 没有找到!"<<endl;
		cout<<"输入任意字符！继续……";
		getch();
	}

}break;
	case 2:
	{
		cout<<"\t\t 请输入要修改的学生的学号；";cin>>Id;
			if(p=FindID(Id))
			{
				p->Next->Input();
				cout<<"修改成功！"<<endl;
				cout<<"输入任意字符！继续……";
			getch();
			}	
	else
	{

		cout<<"\t\t 没有找到！"<<endl;
		cout<<"输入任意字符！继续……";
	getch()	;
	}	
	}break;
}	
}
//删除信息
void Studentmessage::Removeltem()
{
	char name[20];int k=0,te,x,t;
	Student * p=NULL, *temp=NULL, * a[6];
	cout<<"\n\t\t***";
	cout<<"\t\t※1. 按学生的姓名●●※\n\t\t※ 2.按学生学号删除※";
	cout<<"\n\t\t*************************\n请选择: ";
	cin>>x;
	switch(x)
	{
	case 1:
		{
			cout<<"\t\t请输入要删除的学生的姓名:";
			cin>>name;
			if(te=FindItem(name,a))
			{
				if(te==1)	//找到单个学生直接删除
				{
					temp=a[0]->Next;
					a[0]->Next=a[0]->Next->Next; 
					delete temp;
					cout<<"\t\t删除成功!"<<endl;
					cout<<"输入任意字符!继续......";
					getch();
				}
			
				else
				{
					cout<<"\t\t找到多个学生的信息!"<<endl;//找到多个学生选择删除
					for(int i=0;a[i]!=End;i++)
					{
						cout<<"第"<<i+1<<"个:"<<endl;
						a[i]->Next->Show();
					}
					cout<<"\t\t 需要删除哪个学生的信息,请选择:";
					cin>>t;
					temp-a[t-1]->Next;
					a[t-1]->Next=a[t-1]->Next->Next;
					delete temp;
					cout<<"\t\t 删除成功!"<<endl;
					cout<<"输入任意字符！继续……";
					getch();
				}
		}
		else
		{
			cout<<"\t\t 没有找到该学生！"<<'\n'<<endl;
			cout<<"输入任意字符！继续……";
			getch();
		}
	}break;
	case 2:
		{
			cout<<"\t\t 请输入要删除的学生的学号：";cin>>Id;
			if(p=FindID(Id))
			{
				temp=p->Next;
				p->Next=p->Next->Next;
				delete temp;
				cout<<"\t\t 删除成功!"<<endl;
				cout<<"输入任意字符！继续……";
				getch();
			}
			else
			{
				cout<<"\t\t 没有找到该学生！"<<'\n'<<endl;
				cout<<"输入任意字符！继续……";
				getch();	
			}
		}break;
}
}
//统计当前链表
int Studentmessage::ListCount()
{

	if(! Head)
		return 0;
	int n=0;
	for(Student * p=Head->Next;p!=End;p=p->Next)
	{

		n++;
	}
	return n;
}
//对当前链表进行排序
void Studentmessage::Sort()
{
cout<<"Sorting..."<<endl;
Student*p1=NULL,*p2=NULL,*temp=new Student;
int n=Studentmessage::ListCount();
if(n<2)
    return;
for(p1=Head->Next;p1!=End;p1=p1->Next)
for(p2=p1->Next;p2!=End;p2=p2->Next)
    {
if(p1->sum>p2->sum)
{
        strcpy(temp->name,p1->name);
        strcpy(temp->Id,p1->Id);
        temp->Date=p1->Date;
        temp->Age=p1->Age;
        temp->Cnum=p1->Cnum;
        temp->Mnum=p1->Mnum;
        temp->Enum=p1->Enum;
        temp->sum=p1->sum;

        strcpy(p1->name,p2->name);
        strcpy(p1->Id,p2->Id);
        p1->Date=p2->Date;
        p1->Age=p2->Age;
        p1->Cnum=p2->Cnum;
        p1->Mnum=p2->Mnum;
        p1->Enum=p2->Enum;
        p1->sum=p2->sum;
}
}
cout<<"排序完成！"<<endl;
getch();
return;
}


//保存函数
void Studentmessage::Save()
{

	out.open("sort.txt");
	for(Student *p=Head->Next;p!=End;p=p->Next)
		out<<p->name<<"\t"<<p->Id<<"\t"<<p->Date<<"\t"<<p->Age<<"\t"<<p->Cnum<<"\t"<<p->Mnum<<"\t"<<p->Enum<<"\t"<<p->sum<<'\n';
	out.close();
}

//主函数
int main()
{

	int x,i=0,quit=0;
	cout<<"\t\t※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
	for(i=0;i<3;i++)
	{	
		cout<<"\t\tx\t\t\t\tlt\t ☆"<<endl;
		cout<<"\t\t☆☆☆☆☆【欢迎进入学生成绩管理系统】☆☆☆☆☆"<<endl;
	}
		for(i=0;i<3;i++)
		{
			cout<<"\t\t☆\t\t\t\t\t\t  ☆"<<endl;
			cout<<"\t\t※※※※※※※※※※※※※"<<endl;
		}
		if(code()!=4)
		{
			cout<<"\t\t 输入次数已到！\n";return 0;
		}
		Studentmessage Grade;
		cout<<"\t\t 按任意键开始……\n";
		getch();
	while(!quit)
	{	
		system("cls");
		Grade.ShowMenu();
		cin>>x;
		switch(x)
		{	
		case 0:quit=1;break;
		case 1:Grade.Addltem();break;
		case 2:Grade.Display(); break;
		case 3:Grade.Sort();break;
		case 4:Grade.Find();break;
		case 5:Grade.Removeltem();break;
		case 6:Grade. Modifyltem();break;
		}
	}
	return 0;
}
























