
#include "Student.h"


class Analyst:public StuSys
{

    private:
        
    public:

        void welcome(int delay);
        void menu();

        template <class T>
        void Swap(T &x, T &y)
        {
            T tmp = x;
            x = y;
            y = tmp;
        }

        void SortById();
        void SortBySum();
        void SortByMa();
        void SortByEn();
        void SortByEt();
        void SortByPc();
        void SortByName();

        void PtWelcome(int delay);
        void PrintStu();
        void PrintStuInfo(bool IsRank,bool IsSingle);

        void AtWelcome(int delay);
        void PrintAnalyst();
        void IntervalAnalyst(int delay);
        void IntervalAnalysis(int delay);
        void TotalAnalyst();
        void TotalAnalysis();

        void CreatXls();

        void CtWelcome(int delay);
        void PrintCreatHtml();
        void CreatTd(FILE *f,int data);
        void CreatAnalystHtml();
        void CreatHtml(bool IsRank,bool IsSingle,string FileName);

        Analyst(/* args */);
        ~Analyst();
};

Analyst::Analyst(/* args */)
{

}

void Analyst::welcome(int delay)
{
    readFile();
    system("cls");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 成 绩 分 析 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          P.输出学生信息        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          A.学生成绩分析        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          H.生成信息网页        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆         E.生成EXCEL文件        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.退出分析系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓            文件初始化成功            〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    
    // cout<<Head->next->name<<" "<<End->name;
}

void Analyst::menu()
{
    
    int choice;
    
    while (true)
    {

        welcome(20);
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 65 || choice == 97 ||
                choice == 72 || choice == 104 ||
                choice == 80 || choice == 112 ||
                choice == 69 || choice == 101
                )
            {
                break;
            }
        }

        if(choice == 96 || choice == 48)
        {
            break;
        }
     
        switch (choice)
        {
        case 80:
        case 112:
            PrintStu();
            break;
        case 65:
        case 97:
            PrintAnalyst();
            break;
        case 72:
        case 104:
            PrintCreatHtml();
            break;
        case 69:
        case 101:
            CreatXls();
            break;
        default:
            break;
        }
    }
}


void Analyst::SortById()
{
    Student *pre, *cur, *next, *end; // pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;
	while (Head->next != end)
	{
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for (pre = Head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (cur->id > next->id) //从小到大
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;

				//此时next变前一项，cur变后一项  交换next cur
				Swap(cur,next);
			}
		}
		//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
		end = cur;
	}
}

void Analyst::SortBySum()
{
    Student *p, *pre, *q;
	p = Head->next->next;	  //先保存下L的第二个元素，因为下一步要将L变成只有一个元素的有序表。
	Head->next->next = NULL; // 将L变成只有一个元素的有序表
	// 从L的第二个元素开始遍历整个L直至表尾
	while (p != NULL)
	{
		q = p->next;
		pre = Head;										   // 先用pre来保存L。
		while (pre->next != NULL && pre->next->sum > p->sum) // 遍历pre所指向的有序表L，直至找到比p大的节点
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

void Analyst::SortByMa()
{
    Student *pos, *p, *pre, *max, *premax; // pos始终指向未排序链表第一个节点
	pos = Head->next;
	Head->next = NULL; //将头节点后续置空

	while (pos != NULL) //外层循环
	{
		premax = pre = NULL;
		p = max = pos; // p指针从未排序链表中扫描

		while (p != NULL)
		{
			if (p->ma < max->ma) //找到较大值
			{
				max = p;
				premax = pre;
			}
			pre = p; // p指针向后移动
			p = p->next;
		}
		if (premax == NULL)
		{ 
            //表示最大值就是未排序中的第一个节点
			pos = max->next;
		}
		else
		{ 
            //从未排序链中移除最大节点
			premax->next = max->next;
		}
		//将未排序中最大节点头插法插入L指向的已排序链表
		max->next = Head->next;
		Head->next = max;
	}
}

void Analyst::SortByEn()
{
    Student *pre, *cur, *next, *end; 
	end = NULL;
	while (Head->next != end)
	{
		for (pre = Head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (cur->en < next->en)
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;

				Swap(cur,next);
			}
		}
		end = cur;
	}
}

void Analyst::SortByEt()
{
    Student *pos, *p, *pre, *max, *premax; 
	pos = Head->next;
	Head->next = NULL; 

	while (pos != NULL) 
	{
		premax = pre = NULL;
		p = max = pos; 

		while (p != NULL)
		{
			if (p->et < max->et) 
			{
				max = p;
				premax = pre;
			}
			pre = p; 
			p = p->next;
		}
		if (premax == NULL)
		{ 
			pos = max->next;
		}
		else
		{ 
			premax->next = max->next;
		}
		
		max->next = Head->next;
		Head->next = max;
	}
}

void Analyst::SortByPc()
{
    Student *p, *pre, *q;
	p = Head->next->next;	 
	Head->next->next = NULL; 
	while (p != NULL)
	{
		q = p->next;
		pre = Head;										   
		while (pre->next != NULL && pre->next->pc > p->pc) 
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

void Analyst::SortByName()
{
    Student *p, *pre, *q;
	p = Head->next->next;	 
	Head->next->next = NULL; 
	while (p != NULL)
	{
		q = p->next;
		pre = Head;										   
		while (pre->next != NULL && strcmp(pre->next->name,p->name) == -1 ) 
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}


void Analyst::PtWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 输 出 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            1.学号排序          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            2.总分排序          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            3.数学排序          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            4.英语排序          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            5.体育排序          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            6.计算机排序        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            7.姓名排序          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆           0.回到分析系统       ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

}

void Analyst::PrintStuInfo(bool IsRank,bool IsSingle)
{
    system("cls");
    Student S,*s;
    s = Head->next;
    int rank = 1;
    if(IsRank)
    {
        cout<<"\n    ";
        printf(" ──────────────────────────────────────────────────────────────────────────────────");
        cout<<"\n    ";
        if(IsSingle)
        {
            printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|单科排名\t|");
        }else{
            printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|排名\t|");
        }
        
        cout<<"\n    ";
        printf(" ──────────────────────────────────────────────────────────────────────────────────");
        while(s)
        {
            Sleep(20);
            S = *s;
            cout<<"\n    ";
            printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|", S.id, S.name, S.sex, S.ma, S.en, S.et, S.pc, S.avr, S.sum,rank++);
            cout<<"\n    ";
            printf(" ──────────────────────────────────────────────────────────────────────────────────");
            s = s->next;
        }
    }else{

        cout<<"\n           ";
        printf(" ───────────────────────────────────────────────────────────────────────────");
        cout<<"\n           ";
        printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|");
        cout<<"\n           ";
        printf(" ───────────────────────────────────────────────────────────────────────────");

        while(s)
        {
            Sleep(20);
            S = *s;
            cout<<"\n           ";
            printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|", S.id, S.name, S.sex, S.ma, S.en, S.et, S.pc, S.avr, S.sum);
            cout<<"\n           ";
            printf(" ───────────────────────────────────────────────────────────────────────────");
            s = s->next;
        }
    }
    printf("\n");

    SetTextGreen();
    Cprintf("按任意键退出");
    SetTextWhite();

    getch();
}

void Analyst::PrintStu()
{
    int choice;
    string str;

    while(true)
    {

        PtWelcome(20);
        
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 ||
                choice == 99 || choice == 51 ||
                choice == 100 || choice == 52 ||
                choice == 101 || choice == 53 ||
                choice == 102 || choice == 54 ||
                choice == 103 || choice == 55
            )
            {
                break;
            }
        }

        if(choice == 96 || choice == 48)
        {
            break;
        }

        switch (choice)
        {
        case 97:
        case 49:
            SortById();
            PrintStuInfo(false,false);
            break;
        case 98:
        case 50:
            SortBySum();
            PrintStuInfo(true,false);
            break;
        case 99:
        case 51:
            SortByMa();
            PrintStuInfo(true,true);
            break;
        case 100:
        case 52:
            SortByEn();
            PrintStuInfo(true,true);
            break;
        case 101:
        case 53:
            SortByEt();
            PrintStuInfo(true,true);
            break;
        case 102:
        case 54:
            SortByPc();
            PrintStuInfo(true,true);
            break;
        case 103:
        case 55:
            SortByName();
            PrintStuInfo(false,false);
            break;
        default:
            break;
        }

    }
}

void Analyst::AtWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 分 析 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆        1.查看各科具体分析      ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆         2.查看各分段人数       ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.回到分析系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void Analyst::TotalAnalyst()
{
    Student *head;
    int max,min,avr,sum = 0,passRens = 0;
    int passRate;

    SortByMa();
    head = Head->next;
    max = head->ma;
    while(head)
    {
        min = head->ma;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                   ";
    printf("|数学 \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                   ";
    printf(" ───────────────────────────────────────────────────────────");Sleep(20);


    SortByEn();
    head = Head->next;
    max = head->en;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->en;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                   ";
    printf("|英语 \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                   ";
    printf(" ───────────────────────────────────────────────────────────");Sleep(20);

    SortByEt();
    head = Head->next;
    max = head->et;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->et;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                   ";
    printf("|体育 \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                   ";
    printf(" ───────────────────────────────────────────────────────────");Sleep(20);

    SortByPc();
    head = Head->next;
    max = head->pc;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->pc;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                   ";
    printf("|计算机\t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                   ";
    printf(" ───────────────────────────────────────────────────────────");Sleep(20);
    
    SortBySum();
    head = Head->next;
    max = head->sum;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->sum;
        sum += min;
        if(min>=240) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                   ";
    printf("|总分 \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                   ";
    printf(" ───────────────────────────────────────────────────────────");Sleep(20);
}

void Analyst::TotalAnalysis()
{
    
    cout<<"\n                   ";
    printf(" ───────────────────────────────────────────────────────────");Sleep(20);
    cout<<"\n                   ";
    printf("|分析项\t|最高分\t|最低分\t|平均分\t|及格数/总人数\t|及格率\t|");Sleep(20);
    cout<<"\n                   ";
    printf(" ───────────────────────────────────────────────────────────");Sleep(20);


    TotalAnalyst();

    SetTextGreen();
    printf("\n\n");
    Cprintf("按任意键退出");
    SetTextWhite();
    getch();
}

void Analyst::IntervalAnalyst(int delay)
{
    Student *S;
    int Rens1,Rens2,Rens3,Rens4,Rens5;

    
    Rens1=0,Rens2=0,Rens3=0,Rens4=0,Rens5=0;
    for(S = Head->next;S;S = S->next)
    {
        if(S->ma >= 90 ) {Rens1++;continue;}
        if(S->ma >= 80 ) {Rens2++;continue;}
        if(S->ma >= 70 ) {Rens3++;continue;}
        if(S->ma >= 60 ) {Rens4++;continue;}
        Rens5++;continue;
    }
    cout<<"\n                     ";
    printf("|数学\t|%d\t|%d\t|%d\t|%d\t|%d\t|",Rens1,Rens2,Rens3,Rens4,Rens5);Sleep(delay);
    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);


    Rens1=0,Rens2=0,Rens3=0,Rens4=0,Rens5=0;
    for(S = Head->next;S;S = S->next)
    {
        if(S->en >= 90 ) {Rens1++;continue;}
        if(S->en >= 80 ) {Rens2++;continue;}
        if(S->en >= 70 ) {Rens3++;continue;}
        if(S->en >= 60 ) {Rens4++;continue;}
        Rens5++;continue;
    }
    cout<<"\n                     ";
    printf("|英语\t|%d\t|%d\t|%d\t|%d\t|%d\t|",Rens1,Rens2,Rens3,Rens4,Rens5);Sleep(delay);
    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);


    Rens1=0,Rens2=0,Rens3=0,Rens4=0,Rens5=0;
    for(S = Head->next;S;S = S->next)
    {
        if(S->et >= 90 ) {Rens1++;continue;}
        if(S->et >= 80 ) {Rens2++;continue;}
        if(S->et >= 70 ) {Rens3++;continue;}
        if(S->et >= 60 ) {Rens4++;continue;}
        Rens5++;continue;
    }
    cout<<"\n                     ";
    printf("|体育\t|%d\t|%d\t|%d\t|%d\t|%d\t|",Rens1,Rens2,Rens3,Rens4,Rens5);Sleep(delay);
    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);

    Rens1=0,Rens2=0,Rens3=0,Rens4=0,Rens5=0;
    for(S = Head->next;S;S = S->next)
    {
        if(S->pc >= 90 ) {Rens1++;continue;}
        if(S->pc >= 80 ) {Rens2++;continue;}
        if(S->pc >= 70 ) {Rens3++;continue;}
        if(S->pc >= 60 ) {Rens4++;continue;}
        Rens5++;continue;
    }
    cout<<"\n                     ";
    printf("|计算机\t|%d\t|%d\t|%d\t|%d\t|%d\t|",Rens1,Rens2,Rens3,Rens4,Rens5);Sleep(delay);
    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);


    cout<<"\n\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);
    cout<<"\n                     ";
    printf("|总分\t| >=360\t| >=320\t| >=280\t| >=240\t| <240\t|");Sleep(delay);
    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);

    Rens1=0,Rens2=0,Rens3=0,Rens4=0,Rens5=0;
    for(S = Head->next;S;S = S->next)
    {
        if(S->sum >= 360 ) {Rens1++;}
        if(S->sum >= 320 ) {Rens2++;}
        if(S->sum >= 280 ) {Rens3++;}
        if(S->sum >= 240 ) {Rens4++;}
        if(S->sum < 240 ) {Rens5++;}
        
    }
    cout<<"\n                     ";
    printf("|计算机\t|%d\t|%d\t|%d\t|%d\t|%d\t|",Rens1,Rens2,Rens3,Rens4,Rens5);Sleep(delay);
    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);
}

void Analyst::IntervalAnalysis(int delay)
{

    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);
    cout<<"\n                     ";
    printf("|分析项\t|90-100\t|80-90\t|70-80\t|60-70\t|60以下\t|");Sleep(delay);
    cout<<"\n                     ";
    printf(" ─────────────────────────────────────────────────");Sleep(delay);

    IntervalAnalyst(delay);
    SetTextGreen();
    printf("\n\n");
    Cprintf("按任意键退出");
    SetTextWhite();
    getch();
}

void Analyst::PrintAnalyst()
{
    int choice;

    while(true)
    {
        AtWelcome(20);
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 
            )
            {
                break;
            }
        }
        if(choice ==96 ||choice ==48) break;
        
        switch (choice)
        {
        case 97:
        case 49:
            TotalAnalysis();

            break;
        case 98:
        case 50:
            IntervalAnalysis(20);
            
            break;
        default:
            break;
        }

    }

}

void Analyst::CreatXls()
{
    ofstream oFile;
    system("md Excel 2>nul");

	oFile.open("Excel/Students.csv",ios::out|ios::trunc);

	oFile<<"学号"<<","<<"姓名"<<","<<"性别"<<","<<"数学"<<","<<"英语"<<","<<"体育"<<","<<"计算机"<<","<<"平均分"<<","<<"总分"<<endl;
    SortBySum();

    Student *S = Head->next;
    while(S)
    {
        oFile<<S->id<<","<<S->name<<","<<S->sex<<","<<S->ma<<","<<S->en<<","<<S->et<<","<<S->pc<<","<<S->avr<<","<<S->sum<<endl;
        S = S->next;
    }

	oFile.close();

    system("start Excel/Students.csv 2>nul");
}

void Analyst::CtWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     信 息 网 页 生 成 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            1.根据学号          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            2.根据姓名          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            3.根据总分          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            4.根据数学          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            5.根据英语          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            6.根据体育          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆           7.根据计算机         ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          8.根据总体分析        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.返回分析系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void Analyst::CreatTd(FILE *f,int data)
{
    char str[50];
    fprintf(f,"<td class=\"text-center\">");
    itoa(data,str,10);fprintf(f,str);
    fprintf(f,"</td>\n");
}

void Analyst::CreatHtml(bool IsRank,bool IsSingle,string FileName)
{
    FILE *f;
    int i = 1;

    f=fopen(("HTML/"+FileName).c_str(),"w+");

    fprintf(f,"<html lang=\"en\">\n");
    fprintf(f,"<head>\n");
    fprintf(f," <meta charset=\"gb2312\" />\n");
    fprintf(f," <title>学生信息汇总</title>\n");
    fprintf(f,"	<meta name=\"viewport\" content=\"initial-scale=1.0; maximum-scale=1.0; width=device-width;\">\n");
    fprintf(f," <link rel=\"stylesheet\" href=\"table.css\">\n");
    fprintf(f,"</head>\n");
    fprintf(f,"<body>\n");

    fprintf(f,"<div class=\"table-title\">\n");


    fprintf(f," <h3>学生成绩信息</h3>\n");


    fprintf(f,"</div>\n");

    fprintf(f,"<table class=\"table-fill\">\n");
    fprintf(f,"<thead>\n");
    fprintf(f," <tr>\n");
    fprintf(f,"   <th class=\"text-center\">学号</th>\n");
    fprintf(f,"   <th class=\"text-center\">姓名</th>\n");
    fprintf(f,"   <th class=\"text-center\">性别</th>\n");
    fprintf(f,"   <th class=\"text-center\">数学</th>\n");
    fprintf(f,"   <th class=\"text-center\">英语</th>\n");
    fprintf(f,"   <th class=\"text-center\">体育</th>\n");
    fprintf(f,"   <th class=\"text-center\">计算机</th>\n");
    fprintf(f,"   <th class=\"text-center\">平均分</th>\n");
    fprintf(f,"   <th class=\"text-center\">总分</th>\n");

    if(IsRank){
        if(IsSingle)
            fprintf(f,"   <th class=\"text-center\">单科排名</th>\n");
        else
            fprintf(f,"   <th class=\"text-center\">排名</th>\n");
    }
        
    fprintf(f,"  </tr>\n");
    fprintf(f,"</thead>\n");
    fprintf(f,"<tbody class=\"table-hover\">\n");
    
    for(Student *S = Head->next;S;S = S->next)
    {
        char str[50];
        fprintf(f," <tr>\n");

        CreatTd(f,S->id);

        fprintf(f,"<td class=\"text-center\">");
        fprintf(f,S->name);
        fprintf(f,"</td>\n");

        fprintf(f,"<td class=\"text-center\">");
        fprintf(f,S->sex);
        fprintf(f,"</td>\n");

        CreatTd(f,S->ma);

        CreatTd(f,S->en);

        CreatTd(f,S->et);

        CreatTd(f,S->pc);

        CreatTd(f,S->avr);

        CreatTd(f,S->sum);

        if(IsRank)
        {
            CreatTd(f,i++);
        }
        
        fprintf(f,"  </tr>\n");
    }
    
    fprintf(f,"</tbody>\n");
    fprintf(f,"</table>\n");
    fprintf(f,"</body>\n");
    fclose(f);
    
    system(("start HTML/"+FileName+" 2>nul").c_str());
}

void Analyst::CreatAnalystHtml()
{
    FILE *f;

    f = fopen("HTML/Analysis.html","w+");

    fprintf(f,"<html lang=\"en\">\n");
    fprintf(f,"<head>\n");
    fprintf(f," <meta charset=\"gb2312\" />\n");
    fprintf(f," <title>学生信息汇总</title>\n");
    fprintf(f,"	<meta name=\"viewport\" content=\"initial-scale=1.0; maximum-scale=1.0; width=device-width;\">\n");
    fprintf(f," <link rel=\"stylesheet\" href=\"table.css\">\n");
    fprintf(f,"</head>\n");
    fprintf(f,"<body>\n");

    fprintf(f,"<div class=\"table-title\">\n");

    fprintf(f," <h3>学生成绩分析</h3>\n");

    fprintf(f,"</div>\n");

    fprintf(f,"<table class=\"table-fill\">\n");
    fprintf(f,"<thead>\n");
    fprintf(f," <tr>\n");
    fprintf(f,"   <th class=\"text-center\">分析项</th>\n");
    fprintf(f,"   <th class=\"text-center\">最高分</th>\n");
    fprintf(f,"   <th class=\"text-center\">最低分</th>\n");
    fprintf(f,"   <th class=\"text-center\">平均分</th>\n");
    fprintf(f,"   <th class=\"text-center\">及格人数</th>\n");
    fprintf(f,"   <th class=\"text-center\">总人数</th>\n");
    fprintf(f,"   <th class=\"text-center\">及格率</th>\n");
    
    fprintf(f,"  </tr>\n");
    fprintf(f,"</thead>\n");

    fprintf(f,"<tbody class=\"table-hover\">\n");

    char str[50];
    Student *head;
    int max,min,avr,sum = 0,passRens = 0,passRate;

    SortByMa();
    head = Head->next;
    max = head->ma;
    while(head)
    {
        min = head->ma;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">数学</td>\n");
        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortByEn();
    head = Head->next;
    max = head->en;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->en;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">英语</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortByEt();
    head = Head->next;
    max = head->et;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->et;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">体育</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortByPc();
    head = Head->next;
    max = head->pc;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->pc;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">计算机</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortBySum();
    head = Head->next;
    max = head->sum;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->sum;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">总分</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    fprintf(f,"</tbody>\n");
    fprintf(f,"</table>\n");
    fprintf(f,"</body>\n");
    fclose(f);
    
    system("start HTML/Analysis.html 2>nul");

}

void Analyst::PrintCreatHtml()
{

    int choice;
    system("md HTML 2>nul");

    while(true)
    {
        CtWelcome(20);
        while(true)
        {
            choice = getch();
            if(
                choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 ||
                choice == 99 || choice == 51 ||
                choice == 100 || choice == 52 ||
                choice == 101 || choice == 53 ||
                choice == 102 || choice == 54 ||
                choice == 103 || choice == 55 ||
                choice == 104 || choice == 56
            ) break;
        }
        if(choice == 96 || choice == 48) break;

        switch (choice)
        {
        case 97:
        case 49:
            SortById();
            CreatHtml(false,false,"Students-Id.html");
            break;
        case 98:
        case 50:
            SortByName();
            CreatHtml(false,false,"Students-Name.html");
            break;
        case 99:
        case 51:
            SortBySum();
            CreatHtml(true,false,"Students-Total.html");
            break;
        case 100:
        case 52:
            SortByMa();
            CreatHtml(true,true,"Students-Math.html");
            break;
        case 101:
        case 53:
            SortByEn();
            CreatHtml(true,true,"Students-English.html");
            break;

        case 102:
        case 54:
            SortByEt();
            CreatHtml(true,true,"Students-ET.html");
            break;

        case 103:
        case 55:
            SortByPc();
            CreatHtml(true,true,"Students-Computer.html");
            break;
        case 104:
        case 56:
            CreatAnalystHtml();
            break;
        default:
            break;
        }
    }
}

Analyst::~Analyst()
{
}
