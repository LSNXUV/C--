#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef struct Node{
	int id;//学号 
	char name[50];//姓名 
	char sex[10];//性别 
	int ma,en,et,pc;//数英体机 
	int sum;//总分 
	int avr;
	
	struct Node *next;//指针域 
}node;


node List;//链表 


//以下为函数声明

//读取文件 
int readFile(node *L);

//保存文件
int saveFile(node *L);

// 主菜单界面
void welcome();
//增加学生信息

void printAddStuInfo();//界面 
void insertStuInfo(node *L,node e);//功能 

//删除学生信息
//界面 
void printDeleteStuInfo(node *L);
//逻辑功能 
void deleteStuInfo(node *pr);

//修改学生信息
void printFixStuInfo(node 
*L);



//查询学生信息
void printSearchStuInfo(node *L);
//按学号进行查找 
node * searchStuInfoById(int id,node *L);
//按姓名进行查找 
node * searchStuInfoByName(char name[],node *L);

//输出学生信息
void printStuInfo(node *L);

//退出程序
void goodBye();


int main(){
	int choice=0;
	readFile(&List);
	while(true){
		welcome();
		scanf("%d",&choice);
		switch(choice){
			case 1://增加学生信息 
				printAddStuInfo(); 
				break;
			case 2://删除学生信息
				printDeleteStuInfo(&List);
				break;
			case 3://修改学生信息 
				printFixStuInfo(&List);
				break;
			case 4://查询学生信息
				printSearchStuInfo(&List);
				break;
			case 5://输出学生信息
				printStuInfo(&List);
				break;
			case 0://退出程序 
				goodBye();
				break;
		}
		printf("是否需要继续操作？(yes:1 / no:0 ):");
		scanf("%d",&choice);
		if(choice==0){
			break;
		}
	}
	
	return 0;
}

//主菜单界面 
void welcome(){
	system("cls");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓〓  ☆   学 生 成 绩 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          2.删除学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          3.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          4.查询学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          5.输出学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          0.退出管理系统        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	
	printf("请输入对应的功能键(数字): ");
	
}

//增加学生信息
void printAddStuInfo(){
	// 
	system("cls");
	node st;
	printf("请输入新增学生相关信息\n");
	printf("学号:");
	scanf("%d",&st.id);
	printf("姓名:");
	scanf("%s",st.name);
	printf("性别:");
	scanf("%s",st.sex);
	printf("数学:");
	scanf("%d",&st.ma);
	printf("英语:");
	scanf("%d",&st.en);
	printf("体育:");
	scanf("%d",&st.et);
	printf("计算机:");
	scanf("%d",&st.pc);
	st.sum=st.ma+st.en+st.et+st.pc;
	st.avr=(st.sum)/4;
	
	insertStuInfo(&List,st);
	 
}
//插入学生信息 
void insertStuInfo(node *L,node e){
	
	//头插法
	node *h=L;
	node *s=(node *)malloc(sizeof(node));
	*s=e;
	
	s->next=h->next;
	h->next=s;
	
	//保存文件 
	saveFile(L);
}


//删除学生信息
void printDeleteStuInfo(node *L){
	system("cls");
	int id;
	
	node *p;
	
	printf("请输入要删除的学生学号");
	scanf("%d",&id);
	node *st=searchStuInfoById(id,L);
	p=st;
	
	if(st==NULL){
		printf("查无此人！");
		return;
	}
	
	st=st->next; 
	printf("________________________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
	printf("________________________________________________________________________\n");
	
	deleteStuInfo(p);
	saveFile(L);	
 	
}
void deleteStuInfo(node *pr){
	node *s=pr->next;
	
	pr->next=s->next;
	s->next=NULL;
	
	free(s);//释放结点空间 
	
}


//修改学生信息
void printFixStuInfo(node *L){
	system("cls");
	int id;
	int choice=-1;
	
	printf("请输入要查找的学生学号");
	scanf("%d",&id);
	node *st=searchStuInfoById(id,L);
	
	if(st==NULL){
		printf("查无此人！");
		return;
	}	
	st=st->next;

	while(1){
		system("cls"); 
		printf("________________________________________________________________________\n");
	 	printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
		printf("________________________________________________________________________\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
		printf("________________________________________________________________________\n");
		printf("修改姓名---- 1\n");
		printf("修改性别---- 2\n");
		printf("修改数学---- 3\n");
		printf("修改英语---- 4\n");
		printf("修改体育---- 5\n");
		printf("修改计算机---- 6\n");

		
		printf("请输入要修改的信息: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("请输入姓名：");
				scanf("%s",st->name);
				break;
			case 2:
				printf("请输入性别：");
				scanf("%s",st->sex);
				break;
			case 3:
				printf("请输入数学：");
				scanf("%d",&st->ma);				
				break;
			case 4:
				printf("请输入英语：");
				scanf("%d",&st->en);				
				break;
			case 5:
				printf("请输入体育：");
				scanf("%d",&st->et);				
				break;
			case 6:
				printf("请输入计算机：");
				scanf("%d",&st->pc);				
				break;
		}
		st->sum=st->ma+st->en+st->et+st->pc; 
		st->avr=st->sum/4;
		printf("是否继续修改学生信息?（y-1 / n-0）\n");
		scanf("%d",&choice);
		if(choice == 0){
			break;
		}
	}
	
	printf("________________________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
	printf("________________________________________________________________________\n");
	
	
	saveFile(L);
}
//统计学生人数
int countRens(node *L){
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
void SortStuInfoBySum(node *head){
	node *pre,*cur,*next,*end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;
	while(head->next!=end)
	{
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
		{
			if(/* !(next->age) && */ cur->sum < next->sum) //从大到小
			{
				pre->next=next;
				cur->next=next->next;
				next->next=cur;

				//此时next变前一项，cur变后一项  交换next cur
				node *temp=cur; cur=next; next=temp;
			}
		}
		//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
		end = cur;
	}
}
void SortStuInfoByNum(node *head){
	node *pre,*cur,*next,*end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;
	while(head->next!=end)
	{
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
		{
			if(/* !(next->age) && */ cur->id > next->id) //从大到小
			{
				pre->next=next;
				cur->next=next->next;
				next->next=cur;

				//此时next变前一项，cur变后一项  交换next cur
				node *temp=cur; cur=next; next=temp;
			}
		}
		//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
		end = cur;
	}
}

//查询学生信息
void printSearchStuInfo(node *L){
	
	system("cls");//清除面板

	int choice=0;
	int id;
	char name[50];
	node *st;
	printf("按学号查询----- 1\n");
	printf("按姓名查询----- 2\n");
	printf("请输入查询方式：");
	scanf("%d",&choice);
	
	//选择对应查询方式
	if(choice == 1){
		printf("请输入要查询的学号：");
		scanf("%d",&id);
		st=searchStuInfoById(id,L);
		
		if(st==NULL){
			printf("查无此人！\n");
		}else{
			st=st->next;
			printf("________________________________________________________________________\n");
	 		printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
			printf("________________________________________________________________________\n");
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
			printf("________________________________________________________________________\n");
		}
	}else if(choice ==2){
		printf("请输入要查询的姓名：");
			scanf("%s",name);
			st=searchStuInfoByName(name,L);
			
			if(st==NULL){
				printf("查无此人！\n");
			}else{
				st=st->next;
				printf("________________________________________________________________________\n");
	 			printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
				printf("________________________________________________________________________\n");
				printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
				printf("________________________________________________________________________\n");
			}
	}
	
}
//按学号进行查找 
node * searchStuInfoById(int id,node *L){
	
	node *p=L;
	
	while(p->next!=NULL){
		
		if(p->next->id==id){
			return p;
		}
		
		p=p->next;
	}
	
	return NULL;
}
//按姓名进行查找 
node * searchStuInfoByName(char name[],node *L){
	node *p=L;
	
	while(p->next!=NULL){
		
		if(strcmp(name,p->next->name)==0){
			return p;
		}
		
		p=p->next;
	}
	
	return NULL;
}


//输出学生信息
void printStuInfo(node *L){
	 system("cls");
	 int i;
	 printf("信息读取方式选择:\n1:默认按成绩排序\n2:按学号排序\n请输入查看的方式(1/2):\n");
	 scanf("%d",&i);
	 if(i==2){
		 SortStuInfoByNum(L);
	 };
	 if(i==1){
		 SortStuInfoBySum(L);
	 };
	 node *p=L->next;
	 printf("________________________________________________________________________\n");
	 printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
	 printf("________________________________________________________________________\n");
	 if(p!=NULL){
	 	
	 	while(p!=NULL){
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",p->id,p->name,p->sex,p->ma,p->en,p->et,p->pc,p->avr,p->sum);
	 		printf("________________________________________________________________________\n");
			p=p->next;
		}
	 }
}

//退出程序
void goodBye(){
	system("cls");
	printf("欢迎下次使用~\n");
	return ;
}

// 文件输入
int readFile(node *L){
	FILE *fpr=fopen("studentInfo.txt","r");
	node st;
	node *s;
	node *t=L;
	 
	if(fpr==NULL){
		return 0;
	}else{
		//fcanf()
		
		while(fscanf(fpr,"%d %s %s %d %d %d %d %d %d",&st.id,st.name,st.sex,&st.ma,&st.en,&st.et,&st.pc,&st.avr,&st.sum)!=EOF){
			
			s=(node *)malloc(sizeof(node));
			
			*s=st;
			
			t->next=s;
			t=s;
			t->next=NULL;
	
		}
	}
	fclose(fpr);//关闭文件指针 
	return 1;
}

//保存文件
int saveFile(node *L){
	SortStuInfoBySum(L);
	FILE *fpw=fopen("studentInfo.txt","w");
	if(fpw==NULL) return 0; 
	
	
	node *p=L->next;
	
	while(p!=NULL){
		
		fprintf(fpw,"%d %s %s %d %d %d %d %d %d\n",p->id,p->name,p->sex,p->ma,p->en,p->et,p->pc,p->avr,p->sum);
		p=p->next;
	}
	fclose(fpw);//关闭文件指针
	return 1; 
}

