// #include <stdio.h>
#include <windows.h>
// #include <stdlib.h>
// #include <string.h>

#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

#include "SMSF.h"

node List; //����

//�ж�ȫ������
bool IsRegexInput(string str1) // ʹ��������ʽ����ƥ�䣬
{
	bool flag;
	flag = true;
	regex r("\\d{1,8}");
	while (!(flag = regex_match(str1, r)))
	{
		return flag;
	}
	return flag;

}

int main()
{
	int choice = 0;
	readFile(&List);
	while (true)
	{

		welcome();
		string str;
		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "�������ݸ�ʽ�������������֣�";
			cin >> str;
		}
		choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

		switch (choice)
		{
		case 1: //����ѧ����Ϣ
			printAddStuInfo(&List);
			break;
		case 2: //ɾ��ѧ����Ϣ
			printDeleteStuInfo(&List);
			break;
		case 3: //�޸�ѧ����Ϣ
			printFixStuInfo(&List);
			break;
		case 4: //��ѯѧ����Ϣ
			printSearchStuInfo(&List);
			break;
		case 5: //���ѧ����Ϣ
			printStuInfo(&List);
			break;
		case 0: //�˳�����
			goodBye();
			break;
		default:
			continue;
		}
		printf("�Ƿ���Ҫ����������(yes:1 / no:0 ):");

		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "�������ݸ�ʽ�������������֣�";
			cin >> str;
		}
		choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
		if (choice == 0)
		{
			break;
		}
	}

	return 0;
}

//���˵�����
void welcome()
{
	
	system("color 20");
	system("cls");

	printf("��������������������������������������������������������������������������������\n");
	printf("��������������������������������������������������������������������������������\n");
	printf("��������������������  ��   ѧ �� �� �� �� ��  ϵ ͳ     ��  ��������������������\n");
	printf("��������������������         ��������         �������������������\n");
	printf("��������������������         ��������         �������������������\n");
	printf("��������������������  ��          1.����ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          2.ɾ��ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          3.�޸�ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          4.��ѯѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          5.���ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          0.�˳�����ϵͳ        ��  �������������������\n");
	printf("��������������������  ��                                ��  �������������������\n");
	printf("��������������������������������������������������������������������������������\n");

	printf("�������Ӧ�Ĺ��ܼ�(����): ");
}

//����ѧ����Ϣ
void printAddStuInfo(node *L)
{
	//
	system("cls");
	node st;
	string str;
	printf("����������ѧ�������Ϣ\n");

	while (1)
	{
		printf("ѧ��:");

		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "ѧ������,����������:\n";
			cin >> str;
		}
		st.id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
		if (st.id < 20220100 || st.id > 20220170)
		{
			printf("ѧ������,����������\n");
		}
		else
		{
			break;
		}
	}

	printf("����:");
	scanf("%s", st.name);
	printf("�Ա�:");
	while (1)
	{

		scanf("%s", st.sex);
		if (strcmp(st.sex, "��") == 0 || strcmp(st.sex, "Ů") == 0)
		{
			break;
		}
		else
		{
			printf("�Ա��������,����������:");
		}
	};

	printf("��ѧ:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "����������,����������ѧ:\n";
			cin >> str;
		}
		st.ma = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

		if ((st.ma < 0) || (st.ma > 100))
		{
			printf("��ѧ����100,����������:");
		}
		else
		{
			break;
		}
	}

	printf("Ӣ��:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "����������,��������Ӣ��:\n";
			cin >> str;
		}
		st.en = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

		if (st.en < 0 || st.en > 100)
		{
			printf("Ӣ������100,����������:");
		}
		else
		{
			break;
		}
	}

	printf("����:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "����������,������������:\n";
			cin >> str;
		}
		st.et = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

		if (st.et < 0 || st.et > 100)
		{
			printf("��������100,����������:");
		}
		else
		{
			break;
		}
	}

	printf("�����:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "����������,������������:\n";
			cin >> str;
		}
		st.pc = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

		if (st.pc < 0 || st.pc > 100)
		{
			printf("���������100,����������:");
		}
		else
		{
			break;
		}
	}

	st.sum = st.ma + st.en + st.et + st.pc;
	st.avr = (st.sum) / 4;

	printf("________________________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st.id, st.name, st.sex, st.ma, st.en, st.et, st.pc, st.avr, st.sum);
	printf("________________________________________________________________________\n");
	insertStuInfo(L, st);
}

//����ѧ����Ϣ
void insertStuInfo(node *L, node e)
{

	//ͷ�巨
	node *h = L;
	node *s = (node *)malloc(sizeof(node));
	*s = e;

	s->next = h->next;
	h->next = s;

	//�����ļ�
	saveFile(L);
}

//ɾ��ѧ����Ϣ
void printDeleteStuInfo(node *L)
{
	system("cls");
	int id;
	node *p;
	char name[50];
	int choice = 1;
	node *st;

	printf("��ѧ�Ų���----- 1\n");
	printf("����������----- 2\n");
	printf("��������ҷ�ʽ(Ĭ�ϰ�ѧ�Ų���):\n");
	string str;
	cin >> str;
	while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
	{
		cout << "�������ݸ�ʽ�������������֣�";
		cin >> str;
	}
	choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
	
	if(choice != 2)
	{
		while (1)
		{
			printf("������Ҫɾ����ѧ��ѧ��:");

			cin >> str;
			while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
			{
				cout << "ѧ������,����������:\n";
				cin >> str;
			}
			id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
			if (id < 20220100 || id > 20220170)
			{
				printf("ѧ������,����������\n");
			}
			else
			{
				break;
			}
		}
		st = searchStuInfoById(id, L);
	}else if (choice == 2)
	{
		printf("������Ҫɾ��ѧ����������");
		scanf("%s", name);
		st = searchStuInfoByName(name, L);
	}
	p = st;

	if (st == NULL)
	{
		printf("���޴��ˣ�");
		return;
	}

	st = st->next;
	printf("________________________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
	printf("________________________________________________________________________\n");
	printf("ȷ��Ҫɾ����(1:Ĭ����/2:��)\n");
	cin >> str;
	while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
	{
		cout << "����������:\n";
		cin >> str;
	}
	choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
	if (choice!=2)
	{
		deleteStuInfo(p);
	}else
	{
		
	}
	
	
	saveFile(L);
}

void deleteStuInfo(node *pr)
{
	node *s = pr->next;

	pr->next = s->next;
	s->next = NULL;

	free(s); //�ͷŽ��ռ�
}

//�޸�ѧ����Ϣ
void printFixStuInfo(node *L)
{
	system("cls");
	int id;
	char name[50];
	int choice = 1;
	node *st;

	printf("��ѧ�Ų�ѯ----- 1\n");
	printf("��������ѯ----- 2\n");
	printf("�������ѯ��ʽ(Ĭ�ϰ�ѧ�Ų�ѯ):\n");
	string str;
	cin >> str;
	while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
	{
		cout << "�������ݸ�ʽ�������������֣�";
		cin >> str;
	}
	choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
	
	if(choice != 2)
	{
		while (1)
		{
			printf("������Ҫ�޸ĵ�ѧ��ѧ��:");

			cin >> str;
			while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
			{
				cout << "ѧ������,����������:\n";
				cin >> str;
			}
			id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
			if (id < 20220100 || id > 20220170)
			{
				printf("ѧ������,����������\n");
			}
			else
			{
				break;
			}
		}
		st = searchStuInfoById(id, L);
	}else if (choice == 2)
	{
		printf("������Ҫ��ѯ��������");
		scanf("%s", name);
		st = searchStuInfoByName(name, L);
	}

	if (st == NULL)
	{
		printf("���޴��ˣ�");
		return;
	}
	st = st->next;

	while (1)
	{
		// system("cls");
		printf("________________________________________________________________________\n");
		printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
		printf("________________________________________________________________________\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
		printf("________________________________________________________________________\n");
		printf("�޸�����------ 1\n");
		printf("�޸��Ա�------ 2\n");
		printf("�޸���ѧ------ 3\n");
		printf("�޸�Ӣ��------ 4\n");
		printf("�޸�����------ 5\n");
		printf("�޸ļ����------ 6\n");

		printf("������Ҫ�޸ĵ���Ϣ��Ӧ��ѡ��: \n");

		string str;
		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "�������ݸ�ʽ�������������֣�";
			cin >> str;
		}
		choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
		
		switch (choice)
		{
		case 1:
			printf("������������");
			scanf("%s", st->name);
			break;
		case 2:
			printf("�������Ա�");
			while (1)
			{

				scanf("%s", st->sex);
				if (strcmp(st->sex, "��") == 0 || strcmp(st->sex, "Ů") == 0)
				{
					break;
				}
				else
				{
					printf("�Ա��������,����������:");
				}
			};
			break;
		case 3:
			printf("��������ѧ��");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
				{
					cout << "����������,����������ѧ:\n";
					cin >> str;
				}
				st->ma = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

				if ((st->ma < 0) || (st->ma > 100))
				{
					printf("��ѧ����100,����������:");
				}
				else
				{
					break;
				}
			}
			break;
		case 4:
			printf("������Ӣ�");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
				{
					cout << "����������,��������Ӣ��:\n";
					cin >> str;
				}
				st->en = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

				if (st->en < 0 || st->en > 100)
				{
					printf("Ӣ������100,����������:");
				}
				else
				{
					break;
				}
			}
			break;
		case 5:
			printf("������������");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
				{
					cout << "����������,������������:\n";
					cin >> str;
				}
				st->et = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

				if (st->et < 0 || st->et > 100)
				{
					printf("��������100,����������:");
				}
				else
				{
					break;
				}
			}
			break;
		case 6:
			printf("������������");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
				{
					cout << "����������,������������:\n";
					cin >> str;
				}
				st->pc = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

				if (st->pc < 0 || st->pc > 100)
				{
					printf("���������100,����������:");
				}
				else
				{
					break;
				}
			}
			break;
		}
		st->sum = st->ma + st->en + st->et + st->pc;
		st->avr = st->sum / 4;
		printf("�Ƿ�����޸�ѧ����Ϣ?(y-1 / n-0)\n");

		cin >> str;
		while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
		{
			cout << "�������ݸ�ʽ�������������֣�";
			cin >> str;
		}
		choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

		if (choice == 0)
		{
			break;
		}else{
			system("cls");
		}
	}

	printf("________________________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
	printf("________________________________________________________________________\n");

	saveFile(L);
}
//ͳ��ѧ������
int countRens(node *L)
{
	if (!L)
		return 0;
	int n = 0;
	for (node *p = L->next; p->next != NULL; p = p->next)
	{
		n++;
	}
	return n;
}

//����ѧ����Ϣ

//ð������
void SortStuInfoBySum(node *head)
{
	node *pre, *cur, *next, *end; // preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	end = NULL;
	while (head->next != end)
	{
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for (pre = head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (/* !(next->age) && */ cur->sum < next->sum) //�Ӵ�С
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;

				//��ʱnext��ǰһ�cur���һ��  ����next cur
				node *temp = cur;
				cur = next;
				next = temp;
			}
		}
		//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
		end = cur;
	}
}

//ֱ�Ӳ�������
void SortStuInfoByNum(node *L)
{
	node *p, *pre, *q;
	p = L->next->next;	  // �ȱ�����L�ĵڶ���Ԫ�أ���Ϊ��һ��Ҫ��L���ֻ��һ��Ԫ�ص������
	L->next->next = NULL; // ��L���ֻ��һ��Ԫ�ص������
	// ��L�ĵڶ���Ԫ�ؿ�ʼ��������Lֱ����β
	while (p != NULL)
	{
		q = p->next;
		pre = L;										   // ����pre������L��
		while (pre->next != NULL && pre->next->id < p->id) // ����pre��ָ��������L��ֱ���ҵ���p��Ľڵ�
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

//ֱ��ѡ������
void SortStuInfoByEn(node *L)
{
	node *pos, *p, *pre, *max, *premax; // posʼ��ָ��δ���������һ���ڵ�
	pos = L->next;
	L->next = NULL; //��ͷ�ڵ�����ÿ�

	while (pos != NULL) //���ѭ��
	{
		premax = pre = NULL;
		p = max = pos; // pָ���δ����������ɨ��

		while (p != NULL)
		{
			if (p->en < max->en) //�ҵ��ϴ�ֵ
			{
				max = p;
				premax = pre;
			}
			pre = p; // pָ������ƶ�
			p = p->next;
		}
		if (premax == NULL)
		{ //��ʾ���ֵ����δ�����еĵ�һ���ڵ�
			pos = max->next;
		}
		else
		{ //��δ���������Ƴ����ڵ�
			premax->next = max->next;
		}
		//��δ���������ڵ�ͷ�巨����Lָ�������������
		max->next = L->next;
		L->next = max;
	}
}

//ð������
void SortStuInfoByEt(node *head)
{
	node *pre, *cur, *next, *end; // preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	end = NULL;
	while (head->next != end)
	{
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for (pre = head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (cur->et < next->et) //�Ӵ�С
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;
				node *temp = cur;
				cur = next;
				next = temp;
			}
		}
		end = cur;
	}
}

//ֱ�Ӳ�������
void SortStuInfoByMa(node *L)
{
	node *p, *pre, *q;
	p = L->next->next;	  // �ȱ�����L�ĵڶ���Ԫ�أ���Ϊ��һ��Ҫ��L���ֻ��һ��Ԫ�ص������
	L->next->next = NULL; // ��L���ֻ��һ��Ԫ�ص������
	// ��L�ĵڶ���Ԫ�ؿ�ʼ��������Lֱ����β
	while (p != NULL)
	{
		q = p->next;
		pre = L;										   // ����pre������L��
		while (pre->next != NULL && pre->next->ma > p->ma) // ����pre��ָ��������L��ֱ���ҵ���p��Ľڵ�
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

//ѡ������
void SortStuInfoByPc(node *L)
{
	node *pos, *p, *pre, *max, *premax; // posʼ��ָ��δ���������һ���ڵ�
	pos = L->next;
	L->next = NULL; //��ͷ�ڵ�����ÿ�

	while (pos != NULL) //���ѭ��
	{
		premax = pre = NULL;
		p = max = pos; // pָ���δ����������ɨ��

		while (p != NULL)
		{
			if (p->pc < max->pc) //�ҵ��ϴ�ֵ
			{
				max = p;
				premax = pre;
			}
			pre = p; // pָ������ƶ�
			p = p->next;
		}
		if (premax == NULL)
		{ //��ʾ���ֵ����δ�����еĵ�һ���ڵ�
			pos = max->next;
		}
		else
		{ //��δ���������Ƴ����ڵ�
			premax->next = max->next;
		}
		//��δ���������ڵ�ͷ�巨����Lָ�������������
		max->next = L->next;
		L->next = max;
	}
}

//��ѯѧ����Ϣ
void printSearchStuInfo(node *L)
{

	system("cls"); //������

	int choice = 0;
	int id;
	char name[50];
	node *st;

	printf("��ѧ�Ų�ѯ----- 1\n"); 
	printf("��������ѯ----- 2\n");
	printf("�������ѯ��ʽ(Ĭ�ϰ�ѧ�Ų�ѯ):");
	string str;
	cin >> str;
	while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
	{
		cout << "�������ݸ�ʽ�������������֣�";
		cin >> str;
	}
	choice = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

	//ѡ���Ӧ��ѯ��ʽ
	if (choice != 2)
	{
		
		while (1)
		{
			printf("������Ҫ��ѯ��ѧ�ţ�");

			cin >> str;
			while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
			{
				cout << "ѧ������,����������:\n";
				cin >> str;
			}
			id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
			if (id < 20220100 || id > 20220170)
			{
				printf("ѧ������,����������\n");
			}
			else
			{
				break;
			}
		}
		st = searchStuInfoById(id, L);

		if (st == NULL)
		{
			printf("���޴��ˣ�\n");
		}
		else
		{
			st = st->next;
			printf("________________________________________________________________________\n");
			printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
			printf("________________________________________________________________________\n");
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
			printf("________________________________________________________________________\n");
		}
	}
	else if (choice == 2)
	{
		printf("������Ҫ��ѯ��������");
		scanf("%s", name);
		st = searchStuInfoByName(name, L);

		if (st == NULL)
		{
			printf("���޴��ˣ�\n");
		}
		else
		{
			st = st->next;
			printf("________________________________________________________________________\n");
			printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
			printf("________________________________________________________________________\n");
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
			printf("________________________________________________________________________\n");
		}
	}
}


//��ѧ�Ž��в���
node *searchStuInfoById(int id, node *L)
{

	node *p = L;

	while (p->next != NULL)
	{

		if (p->next->id == id)
		{
			return p;
		}

		p = p->next;
	}

	return NULL;
}
//���������в���
node *searchStuInfoByName(char name[], node *L)
{
	node *p = L;

	while (p->next != NULL)
	{

		if (strcmp(name, p->next->name) == 0)
		{
			return p;
		}

		p = p->next;
	}

	return NULL;
}

//���ѧ����Ϣ
void printStuInfo(node *L)
{
	system("cls");
	int i;
	printf("��Ϣ��ȡ��ʽѡ��:\n\nĬ�ϰ��ܳɼ�����----1\n��ѧ��ѧ������------2\n����ѧ�ɼ�����------3\n��Ӣ��ɼ�����------4\n�������ɼ�����------5\n��������ɼ�����----6\n\n������鿴�ķ�ʽ:\n");

	string str;
	cin >> str;
	while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
	{
		cout << "�������ݸ�ʽ�������������֣�";
		cin >> str;
	}
	i = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

	switch (i)
	{
	case 1:
		SortStuInfoBySum(L);
		break;
	case 2:
		SortStuInfoByNum(L);
		break;
	case 3:
		SortStuInfoByMa(L);
		break;
	case 4:
		SortStuInfoByEn(L);
		break;
	case 5:
		SortStuInfoByEt(L);
		break;
	case 6:
		SortStuInfoByPc(L);
		break;
	default:
		SortStuInfoBySum(L);
		break;
	}
	node *p = L->next;
	switch (i)
	{

	case 1:
		printf("________________________________________________________________________________\n");
		printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|������\t|\n");
		printf("________________________________________________________________________________\n");
		if (p != NULL)
		{
			int k = 0;
			int Mavr = 0;
			int Enavr = 0;
			int Etavr = 0;
			int Pcavr = 0;
			int Savr = 0;
			while (p != NULL)
			{
				Mavr += p->ma;
				Enavr += p->en;
				Etavr += p->et;
				Pcavr += p->pc;
				Savr += p->sum;
				printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ma, p->en, p->et, p->pc, p->avr, p->sum, ++k);
				printf("________________________________________________________________________________\n");
				p = p->next;
			}
			printf("ƽ���ɼ�|   \t|  \t|%d\t|%d\t|%d\t|%d\t|     %d\t|  \t|\n", Mavr/k, Enavr/k, Etavr/k, Pcavr/k, Savr/k);
			printf("________________________________________________________________________________\n");
		}
		break;

	case 2:
		printf("________________________________________________________________________\n");
		printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
		printf("________________________________________________________________________\n");
		if (p != NULL)
		{
			while (p != NULL)
			{
				printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ma, p->en, p->et, p->pc, p->avr, p->sum);
				printf("_________________________________________________________________________\n");
				p = p->next;
			}
		}
		break;
	
	default:
		
		printf("_________________________________________________________________________________\n");
		printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|��������|\n");
		printf("_________________________________________________________________________________\n");
		if (p != NULL)
		{
			int k = 0;
			int Mavr = 0;
			int Enavr = 0;
			int Etavr = 0;
			int Pcavr = 0;
			int Savr = 0;
			while (p != NULL)
			{
				Mavr += p->ma;
				Enavr += p->en;
				Etavr += p->et;
				Pcavr += p->pc;
				Savr += p->sum;
				printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t |\n", p->id, p->name, p->sex, p->ma, p->en, p->et, p->pc, p->avr, p->sum, ++k);
				printf("_________________________________________________________________________________\n");
				p = p->next;
			}
			printf("ƽ���ɼ�|   \t|  \t|%d\t|%d\t|%d\t|%d\t|     %d\t|  \t|\n", Mavr/k, Enavr/k, Etavr/k, Pcavr/k, Savr/k);
			printf("________________________________________________________________________________\n");
		}
		break;
	}
	
}

//�˳�����
void goodBye()
{
	system("cls");
	printf("��ӭ�´�ʹ��~\n");
	return;
}

// �ļ�����
int readFile(node *L)
{
	FILE *fpr = fopen("studentInfo.txt", "r");
	node st;
	node *s;
	node *t = L;

	if (fpr == NULL)
	{
		return 0;
	}
	else
	{

		while (fscanf(fpr, "%d %s %s %d %d %d %d %d %d", &st.id, st.name, st.sex, &st.ma, &st.en, &st.et, &st.pc, &st.avr, &st.sum) != EOF)
		{

			s = (node *)malloc(sizeof(node));

			*s = st;

			t->next = s;
			t = s;
			t->next = NULL;
		}
	}
	fclose(fpr); //�ر��ļ�ָ��
	return 1;
}

//�����ļ�
int saveFile(node *L)
{
	SortStuInfoBySum(L);
	FILE *fpw = fopen("studentInfo.txt", "w");
	if (fpw == NULL)
		return 0;

	node *p = L->next;

	while (p != NULL)
	{

		fprintf(fpw, "%d %s %s %d %d %d %d %d %d\n", p->id, p->name, p->sex, p->ma, p->en, p->et, p->pc, p->avr, p->sum);
		p = p->next;
	}

	fclose(fpw); //�ر��ļ�ָ��
	return 1;
}
