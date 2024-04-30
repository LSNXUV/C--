

#include "Manager.h"
#include "Analyst.h"


StuSys::StuSys(/* args */)
{
	Head =  new Student;
    Head->next = NULL;
    End = Head;
    count = 0;
}

bool StuSys::readFile()
{
	
	system("md Students 2>nul");
    FILE *fpr = fopen("Students/Students.txt", "r");
    Student st;
    Student *t = Head;
	count = 0;
	
    if (!fpr)
    {
        FILE *fpw = fopen("Students/Students.txt", "w");
        fclose(fpw); //关闭文件指针
        return true;
    }
    else
    {

        while (fscanf(fpr, "%d %s %s %d %d %d %d %d %d", 
        &st.id, st.name, st.sex, &st.ma, &st.en, &st.et, &st.pc, &st.avr, &st.sum) != EOF)
        {
            Student *s = new Student;
			*s = st;
            t->next = s;
            t = s;
            t->next = NULL;
            End = t;
            count++;
        }
    }
    fclose(fpr); //关闭文件指针
    return true;
    
}

bool StuSys::saveFile()
{

	system("md Students 2>nul");
    FILE *fpw = fopen("Students/Students.txt", "w");

	if (!fpw)
		return false;

	Student *p = Head->next;
    if(!p)
        return true;
	while (p)
	{
		fprintf(fpw, "%d %s %s %d %d %d %d %d %d\n",
        p->id, p->name, p->sex, p->ma, p->en, p->et, p->pc, p->avr, p->sum);
		p = p->next;
	}

	fclose(fpw); //关闭文件指针
	return true;
}

void StuSys::welcome(int delay)
{

	system("cls");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆      学生成绩管理与分析系统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★                                ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          ★★★★★★★        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          S.成绩管理系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          F.成绩分析系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          H.查看使用手册        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.退 出  系 统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");


}

void StuSys::InitWindow()
{	
	//关闭右上角最大化和关闭
	SizeGoAway();
    DeleteGoAway();
	//设置管理权限图标
	HWND hwnd = GetConsoleWindow();
    SendMessage(hwnd, WM_SETICON, 0, (LPARAM)
    LoadIcon((HINSTANCE) GetWindowLongPtr(hwnd, GWLP_HINSTANCE),MAKEINTRESOURCE(32518)));
	
	system("mode con cols=96");
	
}

void StuSys::menu()
{
	InitWindow();
	char Title[96];
	sprintf(Title,"% 115s","学生信息管理和分析系统");
	SetConsoleTitleA(Title);
	
    welcome(20);

	string username;
	char ch;
	
	printf("\n\n");
	SetTextGreen();
	Cprintf("请输入管理员账号密码\n");
	SetTextWhite();
	
	while(true)
	{
		
		printf("\n");
		Mprintf("username:");
		cin>>username;
		
		int i = 0;
		char password[50];
		string pw;
		printf("\n");
		Mprintf("password:");
		while((ch=getch())!='\r')
		{
			if(ch!=8)//不是回撤就录入
			{
				password[i++]=ch;
				putchar('*');//并且输出*号
			}
			else
			{
				if(i == 0) continue;
				putchar('\b');//这里是删除一个，我们通过输出回撤符 /b，回撤一格，
				putchar(' ');//再显示空格符把刚才的*给盖住，
				putchar('\b');//然后再 回撤一格等待录入。
				i--;
			}
		}

		password[i]='\0';
		pw = password;
		if(username == "root" && pw == "admin777")
		{
			SetTextGreen();
			printf("\n\n");
			Cprintf("登录成功!\n");
			SetTextWhite();
			ShowCursor(false);
			Sleep(1000);
			break;
		}

		welcome(0);
		printf("\n\n");
		SetTextGreen();
		Cprintf("账号或密码错误!\n\n");
		SetTextWhite();
		
	}


	int choice;
	Manager StuM;
	Analyst StuA;
	while(true)
	{
		//隐藏光标
		ShowCursor(false);
		welcome(0);

		choice = getch();
		switch (choice)
		{
		case 83:
		case 115:
			StuM.menu();
			welcome(20);
			break;
		case 70:
		case 102:
			StuA.menu();
			welcome(20);
			break;
		case 72:
		case 104:
			system("start 用户手册.docx");
			break;
		default:
			break;
		}
		if(choice==96||choice==48)
		{
			break;
		}
	}
	goodbye();

}

void StuSys::EmptyRemind()
{
    cout<<"\n";
    SetTextGreen();
    for(int i = 3;i>=1;i--)
    {
        printf("                      当前无学生信息，请先添加学生信息  %d 秒后自动退出",i);
        Sleep(1000);
        cout<<"\r";
    }
    SetTextWhite();
}

bool StuSys::IsRegexInput(string str) 
{
	bool flag;
	flag = true;
	regex r("\\d{1,8}");
	while (!(flag = regex_match(str, r)))
	{
		return flag;
	}
	return flag;

}

//显示或隐藏光标
void StuSys::ShowCursor(bool visible) { 

    CONSOLE_CURSOR_INFO cursor_info = {20, visible};
    //CONSOLE_CURSOR_INFO结构体包含控制台光标信息，成员分别表示光标百分比厚度和是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 	//SetConsoleCursorInfo设定控制台窗口的光标大小和是否可见
}


void StuSys::SetTextRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void StuSys::SetTextGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void StuSys::SetTextWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


void StuSys::gotoxy(int x,int y){  
    COORD pos;  
    pos.X=x;  
    pos.Y=y;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); 
}

void StuSys::Mprintf(string str)
{
	cout<<setw(48)<<str;
}
void StuSys::Cprintf(string str)
{
	cout<<setw(48+str.length()/2)<<str;
}

//取消最大化，最小化
void StuSys::SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
}

//取消关闭  谨慎使用，坑人专用
void StuSys::DeleteGoAway(){
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
}

void StuSys::goodbye()
{
	SetTextGreen();
	printf("\n					   欢迎下次使用~\n");
	SetTextWhite();

    Sleep(3000);
}

void StuSys::Free(Student *Head)
{
	if(Head)
	{
		Free(Head->next);
		free(Head);
	}
}

StuSys::~StuSys()
{

}
