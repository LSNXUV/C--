#include<iostream> 
#include<fstream>
#include<string.h>
#include<conio.h>


int code();//��¼����
using namespace std;
// Student��
class Student
{
	public:
		char name[20];
		char Id[20];
		int Date;//ѧ���������� 
		int Age;//ѧ������ 
		int Cnum;//C++���� 
		int Mnum;//��ѧ���� 
		int Enum;//Ӣ����� 
		int sum;//�ܷ� 
		Student*Next;
		void Input()
		{
		cout<<"\t\t ������ѧ��������:";
		cin>>name;
		cout<<"\t\t ������ѧ����ѧ��:";
		cin >>Id;
		cout<<"\t\t ������ѧ���ĳ���ʱ�䣺"; 
		cin>>Date;
        cout<<"\t\t ������ C++�γ̵ĳɼ���"; 
		cin>>Cnum;cout<<"\t\t ��������ѧ�γ̵ĳɼ���"; 
		cin>>Mnum;cout<<"\t\t ������Ӣ��γ̵ĳɼ���"; 
		cin>>Enum;sum=Cnum+Mnum+Enum;Age=2011-Date;
	    }
        void ReadFile (istream& in)
		{
		
        cin>>name>>Id>>Date>>Age>>Cnum>>Mnum>>Enum>>sum;
		}
        
       	void Show()
		   {
		   
				cout<<"����:"<<name<<endl
				<<"ѧ��:"<<Id<<endl
				<<"��������:"<<Date<<endl
				<<"����:"<<Age<<endl
				<<"C++:"<<Cnum<<endl
				<<"��ѧ:"<<Mnum<<endl
				<<"����:"<<Enum<<endl
				<<"�ܳɼ�:"<<sum<<endl<<endl<<endl;
			}
};
		
//Studentmessage��
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
				cout<<"���������ַ�����������";
				getch();
			} 
			void Addltem()
			{
			
				End->Input();
				End->Next=new Student;
				End=End->Next;
			cout<<"��ӳɹ�!"<<endl;
			cout<<"���������ַ�����������";
			getch();
			}
			private:
				Student * Head,* End;
				ifstream in;
				ofstream out;
				int FindItem(char*name,Student*a[])//������ҵ���ָ�뱣�浽���飬���ص�ǰ���鱣��ָ���� 
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
//��¼����
int code()
{

	int i=0,j=0;
	int c;
	char name[15],cod[15];
	cout<<"\n\n";
	while(j<3)
	{
	
		cout<<"\t\t ����Ա:";
		cin.getline(name,sizeof(name));//��cin�������ո��;
		cout<<endl<<"\t\t ��������:";j++;
		c=getch();
		while(c !='\r')//�س�
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
			cout<<"��½�ɹ���\n\n";j=4;break;
		}
		else
			{
			if((strcmp(name,"***")==0)||(strcmp(name,"***")==0))
			cout<<"��½ʧ�ܣ�������󣡣���\n\n";
			else cout<<"��½ʧ�ܣ�����Ա�����ڣ�����\n\n";
			}
		}
}
//���캯��
Studentmessage::Studentmessage()
{
    Head=new Student;
	Head->Next=new Student;
	End=Head->Next;
in.open("sort.txt");
if(!in)
		cout<<"\t\t ����һ����ϵͳ����ѧ����Ϣ���������롣"<<endl;
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
		cout<<"\t\t ��ȡѧ����Ϣ�ɹ�!"<<endl;
	}
}
//��������
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
//�˵�
void Studentmessage::ShowMenu()
{

	cout<<"����������������������ѧ���ɼ�����ϵͳ����������������������"<<endl;
cout<<"�� ��                                                   ^^^^^^^^^^^^^^^^^�� ��"<<endl;
cout<<"����                              1.����ѧ���ɼ�����"<<endl;
cout<<"����                              2.��ʾѧ���ɼ�����"<<endl;
cout<<"����                              3.����ͳ�Ƴɼ�����"<<endl;
cout<<"����                              4.����ѧ���ɼ�����"<<endl;
cout<<"����                              5.ɾ��ѧ���ɼ�����"<<endl;
cout<<"����                              6.�޸�ѧ����Ϣ����"<<endl; 
cout<<"����������������������                  0.��ȫ�˳�ϵͳ����������������������  "<<endl;
cout<<"\n\t\t\n\t\t ��ѡ��";
}

//���Һ���
void Studentmessage::Find()
{

	char name[20],Id[10];
	int x,k;
	Student* p=NULL,*a[6];
	cout<<"\n\t\t*********************************\n";
	cout<<"\t\t�� 1.��ѧ��������������\n\t\t��2.��ѧ��ѧ�Ų��ҡ�";
	cout<<"\n\t\t*********************************\n ��ѡ��";
	cin>>x;
	switch(x)
	{
		case 1:
			{	

				cout<<"\t\t ������Ҫ���ҵ�ѧ����������";cin>>name;
				if(k==FindItem(name,a))
				{

					for(int i=0;a[i]!=End;i++)
					{

						a[i]->Next->Show();
					}
					cout<<"���������ַ�����������";
					getch();
				}
				else
				{
					cout<<"\t\t û���ҵ���������ѧ����"<<'\n'<<endl;
					cout<<"���������ַ�����������";
					getch();
					}	
					break;
					}
					case 2:
					{
						cout<<"\t\t ������Ҫ���ҵ�ѧ����ѧ�ţ�";cin>>Id;
						if(p=FindID(Id)) 
						{
						p->Next->Show();
						cout<<"���������ַ�����������";
						getch();
						}
						else
						{
							cout<<"\t\t û���ҵ���ѧ�ŵ�ѧ����"<<'\n'<<endl;
							cout<<"���������ַ�����������";
							getch();
						}		
						break;
						}
	}
}
//�޸���Ϣ
void Studentmessage::Modifyltem()
{

char name[20];int k=0,te,t,x;
Student *p=NULL,*a[6];
cout<<"\n\t\t*********************************\n";
cout<<"\t\t�� 1.��ѧ��������������\n\t\t�� 2.��ѧ��ѧ�Ų��ҡ�";
cout<<"\n\t\t*********************************\n��ѡ��";
cin>>x;
switch(x)
{
	
	case 1:{
	
	cout<<"\t\t ������Ҫ�޸ĵ��˵�������";cin>>name;//�ҵ�����ѧ��ֱ��ɾ��
	if(te=FindItem(name,a))
	{

		if(te==1)
		{

		a[0]->Next->Input();
		cout<<"�޸ĳɹ���"<<endl;
		cout<<"���������ַ�����������";
		getch();
		}
		else
		{

			cout<<"\t\t �ҵ����ѧ������Ϣ!"<<endl;//�ҵ����ѧ��ѡ��ɾ��
			for(int i=0;a[i]!=End;i++)
			{
				cout<<"��"<<i+1<<"ѧ��:\n";
				a[i]->Next->Show();
			}	
			cout<<"\t\t ��Ҫ�޸��ĸ�ѧ������Ϣ����ѡ��:";
			cin>>t;
			a[t-1]->Next->Input();
			cout<<"�޸ĳɹ���"<<endl;
			cout<<"���������ַ�����������";
			getch();
		}
	}
	else
	{
	
		cout<<"\t\t û���ҵ�!"<<endl;
		cout<<"���������ַ�����������";
		getch();
	}

}break;
	case 2:
	{
		cout<<"\t\t ������Ҫ�޸ĵ�ѧ����ѧ�ţ�";cin>>Id;
			if(p=FindID(Id))
			{
				p->Next->Input();
				cout<<"�޸ĳɹ���"<<endl;
				cout<<"���������ַ�����������";
			getch();
			}	
	else
	{

		cout<<"\t\t û���ҵ���"<<endl;
		cout<<"���������ַ�����������";
	getch()	;
	}	
	}break;
}	
}
//ɾ����Ϣ
void Studentmessage::Removeltem()
{
	char name[20];int k=0,te,x,t;
	Student * p=NULL, *temp=NULL, * a[6];
	cout<<"\n\t\t***";
	cout<<"\t\t��1. ��ѧ������������\n\t\t�� 2.��ѧ��ѧ��ɾ����";
	cout<<"\n\t\t*************************\n��ѡ��: ";
	cin>>x;
	switch(x)
	{
	case 1:
		{
			cout<<"\t\t������Ҫɾ����ѧ��������:";
			cin>>name;
			if(te=FindItem(name,a))
			{
				if(te==1)	//�ҵ�����ѧ��ֱ��ɾ��
				{
					temp=a[0]->Next;
					a[0]->Next=a[0]->Next->Next; 
					delete temp;
					cout<<"\t\tɾ���ɹ�!"<<endl;
					cout<<"���������ַ�!����......";
					getch();
				}
			
				else
				{
					cout<<"\t\t�ҵ����ѧ������Ϣ!"<<endl;//�ҵ����ѧ��ѡ��ɾ��
					for(int i=0;a[i]!=End;i++)
					{
						cout<<"��"<<i+1<<"��:"<<endl;
						a[i]->Next->Show();
					}
					cout<<"\t\t ��Ҫɾ���ĸ�ѧ������Ϣ,��ѡ��:";
					cin>>t;
					temp-a[t-1]->Next;
					a[t-1]->Next=a[t-1]->Next->Next;
					delete temp;
					cout<<"\t\t ɾ���ɹ�!"<<endl;
					cout<<"���������ַ�����������";
					getch();
				}
		}
		else
		{
			cout<<"\t\t û���ҵ���ѧ����"<<'\n'<<endl;
			cout<<"���������ַ�����������";
			getch();
		}
	}break;
	case 2:
		{
			cout<<"\t\t ������Ҫɾ����ѧ����ѧ�ţ�";cin>>Id;
			if(p=FindID(Id))
			{
				temp=p->Next;
				p->Next=p->Next->Next;
				delete temp;
				cout<<"\t\t ɾ���ɹ�!"<<endl;
				cout<<"���������ַ�����������";
				getch();
			}
			else
			{
				cout<<"\t\t û���ҵ���ѧ����"<<'\n'<<endl;
				cout<<"���������ַ�����������";
				getch();	
			}
		}break;
}
}
//ͳ�Ƶ�ǰ����
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
//�Ե�ǰ�����������
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
cout<<"������ɣ�"<<endl;
getch();
return;
}


//���溯��
void Studentmessage::Save()
{

	out.open("sort.txt");
	for(Student *p=Head->Next;p!=End;p=p->Next)
		out<<p->name<<"\t"<<p->Id<<"\t"<<p->Date<<"\t"<<p->Age<<"\t"<<p->Cnum<<"\t"<<p->Mnum<<"\t"<<p->Enum<<"\t"<<p->sum<<'\n';
	out.close();
}

//������
int main()
{

	int x,i=0,quit=0;
	cout<<"\t\t��������������������������������������������������"<<endl;
	for(i=0;i<3;i++)
	{	
		cout<<"\t\tx\t\t\t\tlt\t ��"<<endl;
		cout<<"\t\t�������ӭ����ѧ���ɼ�����ϵͳ��������"<<endl;
	}
		for(i=0;i<3;i++)
		{
			cout<<"\t\t��\t\t\t\t\t\t  ��"<<endl;
			cout<<"\t\t��������������������������"<<endl;
		}
		if(code()!=4)
		{
			cout<<"\t\t ��������ѵ���\n";return 0;
		}
		Studentmessage Grade;
		cout<<"\t\t ���������ʼ����\n";
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
























