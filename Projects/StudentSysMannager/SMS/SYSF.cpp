#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "SMSF.h"

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
void printAddStuInfo(node *L){
	// 
	system("cls");
	node st;
	printf("请输入新增学生相关信息\n");
	
	while (1)
	{
		printf("学号:");
		scanf("%d",&st.id);
		if(st.id<20220100||st.id>20220170){
			printf("学号有误,请重新输入\n");

		}else{
			break;
		}
	}
	
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

	printf("________________________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st.id,st.name,st.sex,st.ma,st.en,st.et,st.pc,st.avr,st.sum);
	printf("________________________________________________________________________\n");
	insertStuInfo(L,st);
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
	
	printf("请输入要查找的学生学号:");
	scanf("%d",&id);
	node *st=searchStuInfoById(id,L);
	
	if(st==NULL){
		printf("查无此人！");
		return;
	}	
	st=st->next;

	while(1){
		// system("cls"); 
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
	node *pre,*cur,*next,*end;
	end = NULL;
	while(head->next!=end)
	{
		
		for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
		{
			if(cur->id > next->id) 
			{
				pre->next=next;
				cur->next=next->next;
				next->next=cur;
				
				node *temp=cur; cur=next; next=temp;
			}
		}
		
		end = cur;
	}
}
void SortStuInfoByEn(node *head){
	node *pre,*cur,*next,*end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;
	while(head->next!=end)
	{
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
		{
			if(cur->en < next->en) //从大到小
			{
				pre->next=next;
				cur->next=next->next;
				next->next=cur;
				node *temp=cur; cur=next; next=temp;
			}
		}
		end = cur;
	}
}
void SortStuInfoByEt(node *head){
	node *pre,*cur,*next,*end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;
	while(head->next!=end)
	{
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
		{
			if(cur->et < next->et) //从大到小
			{
				pre->next=next;
				cur->next=next->next;
				next->next=cur;
				node *temp=cur; cur=next; next=temp;
			}
		}
		end = cur;
	}
}

//直接插入排序
void SortStuInfoByMa(node *L){
	node *p,*pre,*q;
	p = L->next->next;		// 先保存下L的第二个元素，因为下一步要将L变成只有一个元素的有序表。  
	L->next->next = NULL;	// 将L变成只有一个元素的有序表
	// 从L的第二个元素开始遍历整个L直至表尾 
	while(p != NULL){
		q = p->next;
		pre = L;	// 先用pre来保存L。
		while(pre->next !=NULL && pre->next->ma > p->ma) // 遍历pre所指向的有序表L，直至找到比p大的节点 
			pre = pre->next; 
			p->next = pre->next;
			pre->next = p;
		p = q;	
	} 

}

//直接选择排序
void SortStuInfoByPc(node *L){
	node *pos,*p,*pre,*max,*premax;	//pos始终指向未排序链表第一个节点 
	pos=L->next;
	L->next=NULL;	//将头节点后续置空
	
	while(pos!=NULL)	//外层循环 
	{
		premax=pre=NULL;
		p=max=pos;	//p指针从未排序链表中扫描	
		
		while(p!=NULL)
		{
			if(p->pc < max->pc)	//找到较大值 
			{
				max=p;premax=pre; 
			}
			pre=p;		//p指针向后移动 
			p=p->next;	
		}
		if(premax==NULL){	//表示最大值就是未排序中的第一个节点 
			pos=max->next; 
		}else{		//从未排序链中移除最大节点 
			premax->next=max->next; 
		}		
		//将未排序中最大节点头插法插入L指向的已排序链表
		max->next=L->next;
		L->next=max; 
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
	 printf("信息读取方式选择:\n1:默认按总成绩排序\n2:按学生学号排序\n3.按数学成绩排序\n4.按英语成绩排序\n5.按体育成绩排序\n6.按计算机成绩排序\n请输入查看的方式:\n");
	 scanf("%d",&i);
	 /* if(i==2){
		 SortStuInfoByNum(L);
	 };
	 if(i==1){
		 SortStuInfoBySum(L);
	 }; */
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
		 break;
	 }
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