// #include <stdio.h>
#include <windows.h>
// #include <stdlib.h>
// #include <string.h>

#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

#include "SMSF.h"

node List; //链表

//判断全局输入
bool IsRegexInput(string str1) // 使用正则表达式进行匹配，
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
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "输入内容格式有误，请输入数字：";
			cin >> str;
		}
		choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

		switch (choice)
		{
		case 1: //增加学生信息
			printAddStuInfo(&List);
			break;
		case 2: //删除学生信息
			printDeleteStuInfo(&List);
			break;
		case 3: //修改学生信息
			printFixStuInfo(&List);
			break;
		case 4: //查询学生信息
			printSearchStuInfo(&List);
			break;
		case 5: //输出学生信息
			printStuInfo(&List);
			break;
		case 0: //退出程序
			goodBye();
			break;
		default:
			continue;
		}
		printf("是否需要继续操作？(yes:1 / no:0 ):");

		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "输入内容格式有误，请输入数字：";
			cin >> str;
		}
		choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
		if (choice == 0)
		{
			break;
		}
	}

	return 0;
}

//主菜单界面
void welcome()
{
	
	system("color 20");
	system("cls");

	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓〓  ☆   学 生 成 绩 管 理  系 统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          2.删除学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          3.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          4.查询学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          5.输出学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          0.退出管理系统        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

	printf("请输入对应的功能键(数字): ");
}

//增加学生信息
void printAddStuInfo(node *L)
{
	//
	system("cls");
	node st;
	string str;
	printf("请输入新增学生相关信息\n");

	while (1)
	{
		printf("学号:");

		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "学号有误,请重新输入:\n";
			cin >> str;
		}
		st.id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
		if (st.id < 20220100 || st.id > 20220170)
		{
			printf("学号有误,请重新输入\n");
		}
		else
		{
			break;
		}
	}

	printf("姓名:");
	scanf("%s", st.name);
	printf("性别:");
	while (1)
	{

		scanf("%s", st.sex);
		if (strcmp(st.sex, "男") == 0 || strcmp(st.sex, "女") == 0)
		{
			break;
		}
		else
		{
			printf("性别输入错误,请重新输入:");
		}
	};

	printf("数学:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "请输入数字,重新输入数学:\n";
			cin >> str;
		}
		st.ma = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

		if ((st.ma < 0) || (st.ma > 100))
		{
			printf("数学满分100,请重新输入:");
		}
		else
		{
			break;
		}
	}

	printf("英语:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "请输入数字,重新输入英语:\n";
			cin >> str;
		}
		st.en = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

		if (st.en < 0 || st.en > 100)
		{
			printf("英语满分100,请重新输入:");
		}
		else
		{
			break;
		}
	}

	printf("体育:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "请输入数字,重新输入体育:\n";
			cin >> str;
		}
		st.et = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

		if (st.et < 0 || st.et > 100)
		{
			printf("体育满分100,请重新输入:");
		}
		else
		{
			break;
		}
	}

	printf("计算机:");
	while (1)
	{

		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "请输入数字,重新输入计算机:\n";
			cin >> str;
		}
		st.pc = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

		if (st.pc < 0 || st.pc > 100)
		{
			printf("计算机满分100,请重新输入:");
		}
		else
		{
			break;
		}
	}

	st.sum = st.ma + st.en + st.et + st.pc;
	st.avr = (st.sum) / 4;

	printf("________________________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st.id, st.name, st.sex, st.ma, st.en, st.et, st.pc, st.avr, st.sum);
	printf("________________________________________________________________________\n");
	insertStuInfo(L, st);
}

//插入学生信息
void insertStuInfo(node *L, node e)
{

	//头插法
	node *h = L;
	node *s = (node *)malloc(sizeof(node));
	*s = e;

	s->next = h->next;
	h->next = s;

	//保存文件
	saveFile(L);
}

//删除学生信息
void printDeleteStuInfo(node *L)
{
	system("cls");
	int id;
	node *p;
	char name[50];
	int choice = 1;
	node *st;

	printf("按学号查找----- 1\n");
	printf("按姓名查找----- 2\n");
	printf("请输入查找方式(默认按学号查找):\n");
	string str;
	cin >> str;
	while (!IsRegexInput(str)) // 判断输入的内容是否为整形
	{
		cout << "输入内容格式有误，请输入数字：";
		cin >> str;
	}
	choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
	
	if(choice != 2)
	{
		while (1)
		{
			printf("请输入要删除的学生学号:");

			cin >> str;
			while (!IsRegexInput(str)) // 判断输入的内容是否为整形
			{
				cout << "学号有误,请重新输入:\n";
				cin >> str;
			}
			id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
			if (id < 20220100 || id > 20220170)
			{
				printf("学号有误,请重新输入\n");
			}
			else
			{
				break;
			}
		}
		st = searchStuInfoById(id, L);
	}else if (choice == 2)
	{
		printf("请输入要删除学生的姓名：");
		scanf("%s", name);
		st = searchStuInfoByName(name, L);
	}
	p = st;

	if (st == NULL)
	{
		printf("查无此人！");
		return;
	}

	st = st->next;
	printf("________________________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
	printf("________________________________________________________________________\n");
	printf("确定要删除吗？(1:默认是/2:否)\n");
	cin >> str;
	while (!IsRegexInput(str)) // 判断输入的内容是否为整形
	{
		cout << "请输入数字:\n";
		cin >> str;
	}
	choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
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

	free(s); //释放结点空间
}

//修改学生信息
void printFixStuInfo(node *L)
{
	system("cls");
	int id;
	char name[50];
	int choice = 1;
	node *st;

	printf("按学号查询----- 1\n");
	printf("按姓名查询----- 2\n");
	printf("请输入查询方式(默认按学号查询):\n");
	string str;
	cin >> str;
	while (!IsRegexInput(str)) // 判断输入的内容是否为整形
	{
		cout << "输入内容格式有误，请输入数字：";
		cin >> str;
	}
	choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
	
	if(choice != 2)
	{
		while (1)
		{
			printf("请输入要修改的学生学号:");

			cin >> str;
			while (!IsRegexInput(str)) // 判断输入的内容是否为整形
			{
				cout << "学号有误,请重新输入:\n";
				cin >> str;
			}
			id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
			if (id < 20220100 || id > 20220170)
			{
				printf("学号有误,请重新输入\n");
			}
			else
			{
				break;
			}
		}
		st = searchStuInfoById(id, L);
	}else if (choice == 2)
	{
		printf("请输入要查询的姓名：");
		scanf("%s", name);
		st = searchStuInfoByName(name, L);
	}

	if (st == NULL)
	{
		printf("查无此人！");
		return;
	}
	st = st->next;

	while (1)
	{
		// system("cls");
		printf("________________________________________________________________________\n");
		printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
		printf("________________________________________________________________________\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
		printf("________________________________________________________________________\n");
		printf("修改姓名------ 1\n");
		printf("修改性别------ 2\n");
		printf("修改数学------ 3\n");
		printf("修改英语------ 4\n");
		printf("修改体育------ 5\n");
		printf("修改计算机------ 6\n");

		printf("请输入要修改的信息对应的选项: \n");

		string str;
		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "输入内容格式有误，请输入数字：";
			cin >> str;
		}
		choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
		
		switch (choice)
		{
		case 1:
			printf("请输入姓名：");
			scanf("%s", st->name);
			break;
		case 2:
			printf("请输入性别：");
			while (1)
			{

				scanf("%s", st->sex);
				if (strcmp(st->sex, "男") == 0 || strcmp(st->sex, "女") == 0)
				{
					break;
				}
				else
				{
					printf("性别输入错误,请重新输入:");
				}
			};
			break;
		case 3:
			printf("请输入数学：");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // 判断输入的内容是否为整形
				{
					cout << "请输入数字,重新输入数学:\n";
					cin >> str;
				}
				st->ma = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

				if ((st->ma < 0) || (st->ma > 100))
				{
					printf("数学满分100,请重新输入:");
				}
				else
				{
					break;
				}
			}
			break;
		case 4:
			printf("请输入英语：");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // 判断输入的内容是否为整形
				{
					cout << "请输入数字,重新输入英语:\n";
					cin >> str;
				}
				st->en = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

				if (st->en < 0 || st->en > 100)
				{
					printf("英语满分100,请重新输入:");
				}
				else
				{
					break;
				}
			}
			break;
		case 5:
			printf("请输入体育：");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // 判断输入的内容是否为整形
				{
					cout << "请输入数字,重新输入体育:\n";
					cin >> str;
				}
				st->et = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

				if (st->et < 0 || st->et > 100)
				{
					printf("体育满分100,请重新输入:");
				}
				else
				{
					break;
				}
			}
			break;
		case 6:
			printf("请输入计算机：");
			while (1)
			{

				cin >> str;
				while (!IsRegexInput(str)) // 判断输入的内容是否为整形
				{
					cout << "请输入数字,重新输入计算机:\n";
					cin >> str;
				}
				st->pc = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

				if (st->pc < 0 || st->pc > 100)
				{
					printf("计算机满分100,请重新输入:");
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
		printf("是否继续修改学生信息?(y-1 / n-0)\n");

		cin >> str;
		while (!IsRegexInput(str)) // 判断输入的内容是否为整形
		{
			cout << "输入内容格式有误，请输入数字：";
			cin >> str;
		}
		choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

		if (choice == 0)
		{
			break;
		}else{
			system("cls");
		}
	}

	printf("________________________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
	printf("________________________________________________________________________\n");

	saveFile(L);
}
//统计学生人数
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

//排序学生信息

//冒泡排序
void SortStuInfoBySum(node *head)
{
	node *pre, *cur, *next, *end; // pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;
	while (head->next != end)
	{
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for (pre = head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (/* !(next->age) && */ cur->sum < next->sum) //从大到小
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;

				//此时next变前一项，cur变后一项  交换next cur
				node *temp = cur;
				cur = next;
				next = temp;
			}
		}
		//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
		end = cur;
	}
}

//直接插入排序
void SortStuInfoByNum(node *L)
{
	node *p, *pre, *q;
	p = L->next->next;	  // 先保存下L的第二个元素，因为下一步要将L变成只有一个元素的有序表。
	L->next->next = NULL; // 将L变成只有一个元素的有序表
	// 从L的第二个元素开始遍历整个L直至表尾
	while (p != NULL)
	{
		q = p->next;
		pre = L;										   // 先用pre来保存L。
		while (pre->next != NULL && pre->next->id < p->id) // 遍历pre所指向的有序表L，直至找到比p大的节点
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

//直接选择排序
void SortStuInfoByEn(node *L)
{
	node *pos, *p, *pre, *max, *premax; // pos始终指向未排序链表第一个节点
	pos = L->next;
	L->next = NULL; //将头节点后续置空

	while (pos != NULL) //外层循环
	{
		premax = pre = NULL;
		p = max = pos; // p指针从未排序链表中扫描

		while (p != NULL)
		{
			if (p->en < max->en) //找到较大值
			{
				max = p;
				premax = pre;
			}
			pre = p; // p指针向后移动
			p = p->next;
		}
		if (premax == NULL)
		{ //表示最大值就是未排序中的第一个节点
			pos = max->next;
		}
		else
		{ //从未排序链中移除最大节点
			premax->next = max->next;
		}
		//将未排序中最大节点头插法插入L指向的已排序链表
		max->next = L->next;
		L->next = max;
	}
}

//冒泡排序
void SortStuInfoByEt(node *head)
{
	node *pre, *cur, *next, *end; // pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;
	while (head->next != end)
	{
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for (pre = head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (cur->et < next->et) //从大到小
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

//直接插入排序
void SortStuInfoByMa(node *L)
{
	node *p, *pre, *q;
	p = L->next->next;	  // 先保存下L的第二个元素，因为下一步要将L变成只有一个元素的有序表。
	L->next->next = NULL; // 将L变成只有一个元素的有序表
	// 从L的第二个元素开始遍历整个L直至表尾
	while (p != NULL)
	{
		q = p->next;
		pre = L;										   // 先用pre来保存L。
		while (pre->next != NULL && pre->next->ma > p->ma) // 遍历pre所指向的有序表L，直至找到比p大的节点
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

//选择排序
void SortStuInfoByPc(node *L)
{
	node *pos, *p, *pre, *max, *premax; // pos始终指向未排序链表第一个节点
	pos = L->next;
	L->next = NULL; //将头节点后续置空

	while (pos != NULL) //外层循环
	{
		premax = pre = NULL;
		p = max = pos; // p指针从未排序链表中扫描

		while (p != NULL)
		{
			if (p->pc < max->pc) //找到较大值
			{
				max = p;
				premax = pre;
			}
			pre = p; // p指针向后移动
			p = p->next;
		}
		if (premax == NULL)
		{ //表示最大值就是未排序中的第一个节点
			pos = max->next;
		}
		else
		{ //从未排序链中移除最大节点
			premax->next = max->next;
		}
		//将未排序中最大节点头插法插入L指向的已排序链表
		max->next = L->next;
		L->next = max;
	}
}

//查询学生信息
void printSearchStuInfo(node *L)
{

	system("cls"); //清除面板

	int choice = 0;
	int id;
	char name[50];
	node *st;

	printf("按学号查询----- 1\n"); 
	printf("按姓名查询----- 2\n");
	printf("请输入查询方式(默认按学号查询):");
	string str;
	cin >> str;
	while (!IsRegexInput(str)) // 判断输入的内容是否为整形
	{
		cout << "输入内容格式有误，请输入数字：";
		cin >> str;
	}
	choice = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

	//选择对应查询方式
	if (choice != 2)
	{
		
		while (1)
		{
			printf("请输入要查询的学号：");

			cin >> str;
			while (!IsRegexInput(str)) // 判断输入的内容是否为整形
			{
				cout << "学号有误,请输入数字:\n";
				cin >> str;
			}
			id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
			if (id < 20220100 || id > 20220170)
			{
				printf("学号有误,请重新输入\n");
			}
			else
			{
				break;
			}
		}
		st = searchStuInfoById(id, L);

		if (st == NULL)
		{
			printf("查无此人！\n");
		}
		else
		{
			st = st->next;
			printf("________________________________________________________________________\n");
			printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
			printf("________________________________________________________________________\n");
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
			printf("________________________________________________________________________\n");
		}
	}
	else if (choice == 2)
	{
		printf("请输入要查询的姓名：");
		scanf("%s", name);
		st = searchStuInfoByName(name, L);

		if (st == NULL)
		{
			printf("查无此人！\n");
		}
		else
		{
			st = st->next;
			printf("________________________________________________________________________\n");
			printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
			printf("________________________________________________________________________\n");
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->ma, st->en, st->et, st->pc, st->avr, st->sum);
			printf("________________________________________________________________________\n");
		}
	}
}


//按学号进行查找
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
//按姓名进行查找
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

//输出学生信息
void printStuInfo(node *L)
{
	system("cls");
	int i;
	printf("信息读取方式选择:\n\n默认按总成绩排序----1\n按学生学号排序------2\n按数学成绩排序------3\n按英语成绩排序------4\n按体育成绩排序------5\n按计算机成绩排序----6\n\n请输入查看的方式:\n");

	string str;
	cin >> str;
	while (!IsRegexInput(str)) // 判断输入的内容是否为整形
	{
		cout << "输入内容格式有误，请输入数字：";
		cin >> str;
	}
	i = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

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
		printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|总排名\t|\n");
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
			printf("平均成绩|   \t|  \t|%d\t|%d\t|%d\t|%d\t|     %d\t|  \t|\n", Mavr/k, Enavr/k, Etavr/k, Pcavr/k, Savr/k);
			printf("________________________________________________________________________________\n");
		}
		break;

	case 2:
		printf("________________________________________________________________________\n");
		printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
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
		printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|单科排名|\n");
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
			printf("平均成绩|   \t|  \t|%d\t|%d\t|%d\t|%d\t|     %d\t|  \t|\n", Mavr/k, Enavr/k, Etavr/k, Pcavr/k, Savr/k);
			printf("________________________________________________________________________________\n");
		}
		break;
	}
	
}

//退出程序
void goodBye()
{
	system("cls");
	printf("欢迎下次使用~\n");
	return;
}

// 文件输入
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
	fclose(fpr); //关闭文件指针
	return 1;
}

//保存文件
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

	fclose(fpw); //关闭文件指针
	return 1;
}
