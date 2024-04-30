#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <memory.h>
#include <time.h>
#include<stdarg.h>

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
typedef struct
{
int StuNum;
char StuName[20];
}Stu;

typedef struct
{
Stu *elem;
int length;
int listsize;
}StuList;
typedef int status;
StuList student;
void ClearList(StuList &L)
{
L.length = 0;
}
status ListDelete(StuList &L, int i, Stu &e)
{
Stu *p,*q;
if (i<1 || i>L.length)
	return 0;
p = L.elem + i - 1;
e = *p;
q = L.elem + L.length - 1;
for (p++; p <= q; p++)
	*(p - 1) = *p;
L.length--;
return 1;
}
status DestroyList(StuList &L)
{
if (L.elem)
free(L.elem);
L.elem = NULL;
L.length = 0;
L.listsize = 0;
return 1;
}
void Show()
{
	printf("******************************************************************\n");
printf("*              欢迎进入点名系统                                            *\n");
printf("*        按N键：添加学生信息                                             *\n");
printf("*         按M键：修改学生信息                                           *\n");
printf("*         按D键：删除学生信息                                           *\n");
printf("*        按S键：保存学生信息                                            *\n");
printf("*         按P键：展示学生信息                                           *\n");
printf("*         按F键：进行随机点名                                           *\n");
printf("*         按H键：打开                                                        *\n");
printf("*         按E键：退出                                                        *\n");
printf("*         其他：返回首页                                                   *\n");
printf("****************************************************************\n");
}

int ListLength(StuList L)
{
return L.length;
}
status ListInsert(StuList &L, int i,Stu e)
{

Stu *newbase, *q, *p;
if (i<1 || i>L.length + 1)
	return NULL;
if (L.length == L.listsize)
{
	newbase = (Stu*)realloc(L.elem, (L.listsize + LIST_INCREMENT) *sizeof(Stu));	
	if (!newbase)
		exit(-1);
	L.elem = newbase;
	L.listsize += LIST_INCREMENT;
}
q = L.elem + i - 1;
for (p = L.elem + L.length - 1; p >= q; --p)
	*(p + 1) = *p;
*q = e;
L.length++;
}
static status InitList(StuList &L)
{
L.elem = (Stu*)malloc(LIST_INIT_SIZE * sizeof(Stu));
if (!L.elem)
return 0;
L.length = 0;
L.listsize = LIST_INIT_SIZE;
return 1;
}
void printElement(Stu& e)
{
printf("------------------------------------------------ \n");
printf("%d %s \n",e.StuNum,e.StuName);
}
void ListTraverse(StuList L, void(*visit)(Stu& e))
{
Stu *p = L.elem;
for (int i = 1; i <= L.length; i++)
visit(*p++);
printf("\n");
}
void Add()
{
Stu information;
printf("请输入学号和姓名\n");
scanf("%d%s",&information.StuNum,&information.StuName);
int len=ListLength(student);
ListInsert(student,len+1, information);
ListTraverse(student, printElement);
system("pause");
}
void Modify()
{
char xm[10];
printf("请输入要修改的名字\n");
scanf("%s", &xm);
int i = 1;
Stu *p = student.elem;
while (i <= student.length)
{
if (strcmp(p->StuName, xm) == 0)
{
printf("当前姓名为%s\n", xm);
printElement(*p);
printf("请输入要修改后的姓名:\n");
scanf("%s", &(p->StuName));
printf("修改后为:\n");
printElement(*p);
}
i++;
p++;
}
if(i >= student.length)
{
printf("没有找到姓名为%s的同学\n", xm);
}
system("pause");
}
void Delete()
{
char del[10];
printf("请输入要删除学生的姓名\n");
scanf("%s", &del);
int i = 1;
Stu *p = student.elem;
while (i <=student.length)
{
if (strcmp(p->StuName, del) == 0)
break;
i++;
p++;
}
if (i <= student.length)
{
Stu delxm;
ListDelete(student, i, delxm);
printf("所删除的信息为:\n");
printElement(delxm);
}
else
{
printf("没有找到%s的同学\n", del);
}
system("pause");
}
void Shows()
{

ListTraverse(student, printElement);
system("pause");

}
void Open()
{

FILE* fp = fopen("data.txt", "r");
if (!fp)
{
	printf("打开文件失败");
	return;
}
ClearList(student);
int nNum;
fscanf(fp, "%d\n", &nNum);
Stu  e;
int i = 1;
while ( i <= nNum)
{
	fscanf(fp, "%d    %s\n",&e.StuNum,&e.StuName);	
    ListInsert(student,i, e);
	i++;
}
ListTraverse(student, printElement);
fclose(fp);
system("pause");
}
void Save()
{
FILE* fp = fopen("data.txt", "w+");
if (!fp)
{
printf("打开文件失败");
return;
}
fprintf(fp, "%d\n", student.length);
int i = 1;
int len=ListLength(student);
while (i <=len)
{
Stu e;
e = student.elem[i-1];
fprintf(fp,"%d%s\n",e.StuNum,e.StuName);
i++;
}
printf("保存成功\n");
fclose(fp);
system("pause");
}
void dianname()
{

FILE* fp = fopen("data.txt", "r");
if (!fp)
{
	printf("打开文件失败");
	return;
}
ClearList(student);
int nNum;
fscanf(fp, "%d\n", &nNum);
Stu  e;
int i = 1;
while ( i <= nNum)
{
	fscanf(fp, "%d    %s\n",&e.StuNum,&e.StuName);	
    ListInsert(student,i, e);
	i++;
}
fclose(fp);
int j=0;
int t=0;
int n;
printf("输入你想点名的人数");
scanf("%d",&n);
srand((unsigned)time(NULL));
while(j++<n)
{	
		t=rand()%3+1;
		Stu a;
		a = student.elem[t-1];
		printElement(a);
}
	system("pause");
}
void DianName()
{
InitList(student);
while (1)
{
Show();
char c;
fflush(stdin);
c = getchar();
switch(c)
{
case 'N':
case 'n':
Add(); break;
case 'D':
case 'd':
Delete(); break;
case 'M':
case 'm':
Modify(); break;
case 'S':
case 's':
Save(); break;
case 'p':
case 'P':
Shows(); break;
case 'F':
case 'f':
dianname();break;
case 'H':
case 'h':
Open();break;
case 'E':
case 'e':
return; break; 
default:
break;
}

}
DestroyList(student);
system("pause");
}
int main()
{
DianName();
return 0;
}