
#include "Student.h"


class StuSys
{
    private:

    protected:

        Student *Head,*End;
        int count;
        
    public:

        void InitWindow();
        bool readFile();
        bool saveFile();

        virtual void welcome(int delay);
        virtual void menu();

        void Cprintf(string str);
        void Mprintf(string str);
        void SetTextWhite();
        void SetTextGreen();
        void SetTextRed();
        void ShowCursor(bool visible);
        bool IsRegexInput(string str);
        void gotoxy(int x,int y);
        void SizeGoAway();
        void DeleteGoAway();
        void EmptyRemind();

        void goodbye();
        void Free(Student *Head);
        StuSys(/* args */);
        ~StuSys();

};

class Manager:public StuSys
{
    private:

    public:

        void welcome(int delay);
        void menu();

        void AddWelcome(int delay);
        void PrintAddStu();
        void AddStu(Student *S);

        void DeleteStu(Student *S);
        void DelWelcome(int delay);
        void PrintDeleteStu();

        void UpdateWelcome(int delay);
        // 打印修改信息提示页面
        void UpWelcome(int delay);
        void PrintUpdateStu();
        void UpdateStu(Student *stu);

        //查找
        void SearchWelcome(int delay);
        void PrintSingleStu(Student S);
        void PrintSearchStu();
        void PrintSearchFail();
        void SearchFailWelcome(int delay);

        Student * SearchByName(char name[]);
        Student * SearchById(int id);


        Manager(/* args */);
        ~Manager();
};


Manager::Manager(/* args */)
{
    
}


void Manager::welcome(int delay)
{
    readFile();
    system("cls");
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 成 绩 管 理 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          A.增加学生信息        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          D.删除学生信息        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          U.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          S.查询学生信息        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.退出管理系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓            文件初始化成功            〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    

}

void Manager::menu()
{
    
    int choice;

    while (true)
    {
        
        welcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 65 || choice == 97 || choice == 68 || choice == 100 || 
                choice == 85 || choice == 117 || choice == 83 || choice == 115 ||
                choice == 96||choice == 48 )
            {
                break;
            }
        }
        if(choice == 96||choice == 48)
        {
            break;
        }
        switch (choice)
        {
        case 65:
        case 97:
            PrintAddStu();
            break;
        case 68:
        case 100:
            PrintDeleteStu();
            break;
        case 85:
        case 117:
            PrintUpdateStu();
            break;
        case 83:
        case 115:
            PrintSearchStu();
            break;
        default:
            break;
        }
    }
}

void Manager::AddStu(Student *S)
{

    End->next = S;
    End = S;
    End->next = NULL;

    // PrintSingleStu(*End);
    saveFile();
}

void Manager::AddWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 添 加 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          A.输入学生信息        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.回到管理系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void Manager::PrintAddStu()
{

    Student *s;
    int choice;
    string str;

    while(true)
    {
        Student *Stu = new Student;

        AddWelcome(20);

        while(true)
        {
            choice = getch();
            if(choice == 97 || choice == 65 || choice == 96 || choice == 48)
            {
                break;
            }
        }
        
        if(choice == 96 || choice == 48)
        {
            return;
        }
        
        //添加学生信息

        ShowCursor(true);
        printf("\n");
        Mprintf("请输入学号:");
        
        while (1)
        {
            SetTextGreen();
            cin >> str;
            SetTextWhite();
            printf("\n");
            while (!IsRegexInput(str)) // 判断输入的内容是否为整形
            {
                SetTextGreen();Cprintf("学号只能是数字\n");SetTextWhite();
                Mprintf("请重新输入:");
                SetTextGreen();cin >> str;SetTextWhite();
                printf("\n");
            }
            
            Stu->id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
            if (Stu->id < 20220000 || Stu->id > 20229999)
            {
                SetTextGreen();
                Cprintf("学号格式错误\n");
                SetTextWhite();
                Mprintf("请重新输入:");
            }
            else
            {
                s = Head->next;
                while(s && s->id != Stu->id)
                {
                    // cout<<s->id<<" -- "<<S.id<<endl;
                    s = s->next;
                }
                if(s)
                {
                    // cout<<s->id<<" -- "<<S.id<<endl;
                    SetTextGreen();Cprintf("学号已存在\n");SetTextWhite();
                    Mprintf("请重新输入:");
                }else{
                    break;
                }
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("请输入姓名:");
        SetTextGreen();
        scanf("%s", Stu->name);
        printf("\n");
        while(strlen(Stu->name) > 6)
        {
            SetTextGreen();
            printf("\n");Cprintf("姓名长度不能超过3");printf("\n");SetTextWhite();
            Mprintf("请重新输入:");
            SetTextGreen();
            scanf("%s", Stu->name);
        }
        SetTextWhite();

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("请输入性别:");
        while (1)
        {
            SetTextGreen();scanf("%s", Stu->sex);SetTextWhite();printf("\n\n");
            if (strcmp(Stu->sex, "男") == 0 || strcmp(Stu->sex, "女") == 0)
            {
                break;
            }
            else
            {
                SetTextGreen();Cprintf("非地球人不能添加信息哦\n");SetTextWhite();
                Mprintf("请重新输入:");
            }
        };

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("请输入数学成绩:");
        while (1)
        {

            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // 判断输入的内容是否为整形
            {
                SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                Mprintf("请重新输入:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->ma = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

            if ((Stu->ma < 0) || (Stu->ma > 100))
            {
                SetTextGreen();Cprintf("数学满分100\n");SetTextWhite();
                Mprintf("请重新输入:");
            }
            else
            {
                break;
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("请输入英语成绩:");
        while (1)
        {
            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // 判断输入的内容是否为整形
            {
                SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                Mprintf("请重新输入:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->en = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

            if (Stu->en < 0 || Stu->en > 100)
            {
                SetTextGreen();Cprintf("英语满分100\n");SetTextWhite();
                Mprintf("请重新输入:");
            }
            else
            {
                break;
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("请输入体育成绩:");
        while (1)
        {
            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // 判断输入的内容是否为整形
            {
                SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                Mprintf("请重新输入:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->et = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

            if (Stu->et < 0 || Stu->et > 100)
            {
                SetTextGreen();Cprintf("体育满分100\n");SetTextWhite();
                Mprintf("请重新输入:");
            }
            else
            {
                break;
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("请输入计算机成绩:");
        while (1)
        {

            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // 判断输入的内容是否为整形
            {
                SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                Mprintf("请重新输入:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->pc = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

            if (Stu->pc < 0 || Stu->pc > 100)
            {
                SetTextGreen();Cprintf("计算机满分100\n");SetTextWhite();
                Mprintf("请重新输入:");
            }
            else
            {
                break;
            }
        }

        Stu->sum = Stu->en+Stu->et+Stu->ma+Stu->pc;
        Stu->avr = Stu->sum/4;
        Stu->next = NULL;

        AddWelcome(10);
        PrintSingleStu(*Stu);
        printf("\n\n");
        SetTextGreen();
        Cprintf("确认信息?  Y/N");
        while(true)
        { 
            choice = getch();
            if(choice == 89 || choice == 121) 
            {
                AddStu(Stu);
                printf("\n\n");
                Cprintf("添加成功!");
                
                Sleep(2000);
               break;
            }
            if(choice == 78 || choice == 110)
            {
                break;
            }
        }
        SetTextWhite();
        
    }
    
}

Student * Manager::SearchById(int id)
{
    Student *S = Head;
    while(S->next && S->next->id !=  id)
    {
        S = S->next;
    }
    return S;
}

Student * Manager::SearchByName(char name[])
{
    Student *S = Head;
    while(S->next && strcmp(S->next->name,name) != 0)
    {
        S = S->next;
    }
    return S;
}

void Manager::DeleteStu(Student *S)
{
    Student *s = S->next;
    S->next = s->next;
    free(s);

    saveFile();
}

void Manager::DelWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 删 除 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          I.通过学号查找        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          N.通过名字查找        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.回到管理系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

}

void Manager::PrintDeleteStu()
{
    
    int choice;
    int id;
    char name[50];
    Student S,*s;
    string str;
    while(true)
    {
        DelWelcome(20);
        //判断学生信息是否为空
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 73 || choice == 105 ||
                choice == 78 || choice == 110 || 
                choice == 96 || choice == 48 
            )
            {
                break;
            }
        }
        
        switch (choice)
        {
        case 73:
        case 105:

            ShowCursor(true);
            printf("\n\n");Mprintf("请输入学号:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();
                printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("学号只能是数字\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();
                    printf("\n");
                }
                
                id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
                if (id < 20220000 || id > 20229999)
                {
                    SetTextGreen();
                    Cprintf("学号格式错误\n");
                    SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    break;
                }
            }
            DelWelcome(0);
            s = SearchById(id);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                SetTextRed();
                Cprintf("确认删除?  Y(是)/N(否)");
                SetTextWhite();
            }else{
                printf("\n\n");
                SetTextGreen();
                Cprintf("学生不存在!");
                SetTextWhite();
                printf("\n\n");
                Cprintf("按任意键退出");
                Sleep(2000);
                getch();
                break;
            }
            while(true)
            {
                choice = getch();
                if(choice == 89 || choice == 121) 
                {
                    DeleteStu(s);
                    printf("\n\n");
                    SetTextGreen();
                    Cprintf("删除成功!");
                    SetTextWhite();
                    break;
                }
                if(choice == 78 || choice == 110)
                {
                    break;
                }
            }
            break;
        case 78:
        case 110:

            ShowCursor(true);
            printf("\n\n");Mprintf("请输入姓名:");
            SetTextGreen();cin>>name;SetTextWhite();printf("\n");

            DelWelcome(0);
            s = SearchByName(name);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                SetTextRed();
                Cprintf("确认删除?  Y(是)/N(否)");
                SetTextWhite();
            }else{
                printf("\n\n");
                SetTextGreen();
                Cprintf("学生不存在!");
                SetTextWhite();
                printf("\n\n");
                Cprintf("按任意键退出");
                getch();
                break;
            }
            while(true)
            {
                choice = getch();
                if(choice == 89 || choice == 121) 
                {
                    DeleteStu(s);
                    printf("\n\n");
                    SetTextGreen();
                    Cprintf("删除成功!");
                    SetTextWhite();
                    Sleep(2000);
                    break;
                }
                if(choice == 78 || choice == 110)
                {
                    break;
                }
            }
            break;
        default:
            break;
        }

        if(choice==96||choice==48)
		{
			break;
		}
    }
}

void Manager::SearchWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 查 询 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          I.通过学号查找        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          N.通过名字查找        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          F.查找挂科学生        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.回到管理系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void Manager::SearchFailWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 挂 科 查 询 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            1.数学挂科          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            2.英语挂科          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            3.体育挂科          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆           4.计算机挂科         ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.回到查询系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

}

void Manager::PrintSearchFail()
{
    int choice;
    Student *s,S;
    while(true)
    {
        int countRens = 0;
        SearchFailWelcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 ||
                choice == 99 || choice == 51 ||
                choice == 100 || choice == 52 
            ) break; 
        }

        if(choice == 96 || choice == 48) break;

        switch (choice)
        {
        case 97:
        case 49:
            s = Head->next;
            while(s)
            {
                if(s->ma < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("无数学挂科学生");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("按任意键继续");
            getch();
            break;
        case 98:
        case 50:
            s = Head->next;
            while(s)
            {
                if(s->en < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("无英语挂科学生");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("按任意键继续");
            getch();
            break;
            break;
        case 99:
        case 51:
            s = Head->next;
            while(s)
            {
                if(s->et < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                    
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("无体育挂科学生");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("按任意键继续");
            getch();
            break;
        case 100:
        case 52:
            s = Head->next;
            while(s)
            {
                if(s->pc < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("无计算机挂科学生");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("按任意键继续");
            getch();
            break;
        default:
            break;
        }
    }
}

void Manager::PrintSingleStu(Student S)
{
    cout<<"\n           ";
    printf(" ───────────────────────────────────────────────────────────────────────────");
    cout<<"\n           ";
    printf("|学号\t|姓名\t|性别\t|数学\t|英语\t|体育\t|计算机\t|平均分\t|总分\t|");
    cout<<"\n           ";
    printf(" ───────────────────────────────────────────────────────────────────────────");
    cout<<"\n           ";
    printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|", S.id, S.name, S.sex, S.ma, S.en, S.et, S.pc, S.avr, S.sum);
    cout<<"\n           ";
    printf(" ───────────────────────────────────────────────────────────────────────────");
}

void Manager::PrintSearchStu()
{
    int choice;
    int id;
    char name[50];
    Student S,*s;
    string str;
    while(true)
    {
        SearchWelcome(20);
        //判断学生信息是否为空
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 78 || choice == 73 || 
                choice == 110 || choice == 105 || 
                choice == 96 || choice == 48 ||
                choice == 70 || choice == 102
            )
            {
                break;
            }
        }
        
        switch (choice)
        {
        case 73:
        case 105:

            ShowCursor(true);
            printf("\n\n");Mprintf("请输入学号:");
            
            while (1)
            {
                SetTextGreen();
                cin >> str;
                SetTextWhite();
                printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("学号只能是数字\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();
                    printf("\n");
                }
                
                id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
                if (id < 20220000 || id > 20229999)
                {
                    SetTextGreen();
                    Cprintf("学号格式错误\n");
                    SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    break;
                }
            }
            SearchWelcome(0);
            
            s = SearchById(id);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                Cprintf("按任意键继续");
            }else{
                printf("\n\n");
                Cprintf("学生不存在！");
                break;
            }
            getch();
            break;
        case 78:
        case 110:

            ShowCursor(true);
            printf("\n\n");Mprintf("请输入姓名:");
            SetTextGreen();cin>>name;SetTextWhite();
            SearchWelcome(0);
            s = SearchByName(name);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                Cprintf("按任意键继续");
            }else{
                printf("\n\n");
                Cprintf("学生不存在！");
                break;
            }
            getch();
            break;
        case 70:
        case 102:
            PrintSearchFail();
            break;
        default:
            break;
        }
        if(choice==96||choice==48)
		{
			break;
		}
    }
}

void Manager::UpdateWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 更 新 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          I.通过学号查找        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          N.通过名字查找        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.回到管理系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

}

void Manager::UpWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 更 新 系 统    ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            1.修改学号          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            2.修改名字          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            3.修改性别          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          4.修改数学成绩        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          5.修改英语成绩        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          6.修改体育成绩        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆         7.修改计算机成绩       ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆          0.回到查询系统        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void Manager::UpdateStu(Student *stu)
{
    string str;
    int UpdateChoice;
    Student S,*s,*st = Head->next;
    int id;
    if(stu->next)
    {
        UpWelcome(20);
        S = *stu->next;
        PrintSingleStu(S);
        
    }else{
        printf("\n\n");
        Cprintf("学生不存在！");
        Sleep(2000);
        return;
    }

    //修改信息
    s = stu->next;
    while(true)
    {

        UpdateChoice = getch();
        if(UpdateChoice == 96 || UpdateChoice == 48) 
        {
            ShowCursor(false);
            break;
        }
        ShowCursor(true);
        switch (UpdateChoice)
        {
        case 49:
        case 97:
    
            printf("\n\n");Mprintf("请输入学号:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("学号只能是数字\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
            
                id = atoi(str.c_str());//输入没有问题，进行字符串转换为整形
                if (id < 20220000 || id > 20229999)
                {
                    SetTextGreen();Cprintf("学号格式错误\n");SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    if(id == s->id) break;
                    while(st && st->id != id)
                    {
                        st = st->next;
                    }
                    if(st)
                    {
                        SetTextGreen();Cprintf("学号已存在\n");SetTextWhite();
                        Mprintf("请重新输入:");
                        st = Head->next;
                    }else{
                        break;
                    }
                }
            }
            printf("\n");
            ShowCursor(false);Cprintf("修改成功！");
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 50:
        case 98:
            printf("\n\n");Mprintf("请输入姓名:");
            SetTextGreen();scanf("%s", s->name);
            while(strlen(s->name)>=6)
            {
                SetTextGreen();
                printf("\n");Cprintf("姓名长度不能超过3");printf("\n");SetTextWhite();
                Mprintf("请重新输入:");
                SetTextGreen();
                scanf("%s", s->name);
            }
            SetTextWhite();
            printf("\n");
            Cprintf("修改成功！");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 51:
        case 99:
            cout<<endl;
            printf("\n\n");Mprintf("请输入性别:");
            while (1)
            {
                scanf("%s", s->sex);
                if (strcmp(s->sex, "男") == 0 || strcmp(s->sex, "女") == 0)
                {
                    break;
                }
                else
                {
                    SetTextGreen(); Cprintf("非地球人不能添加信息哦\n");SetTextWhite();
                    Mprintf("请重新输入:");
                }
            };
            printf("\n");
            Cprintf("修改成功！");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 52:
        case 100:

            printf("\n\n");Mprintf("请输入数学成绩:");
            while (1)
            {

                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->ma = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

                if ((s->ma < 0) || (s->ma > 100))
                {
                    SetTextGreen();Cprintf("数学满分100\n");SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("修改成功！");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 53:
        case 101:
            cout<<endl;
            printf("\n\n");Mprintf("请输入英语成绩:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->en = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

                if (s->en < 0 || s->en > 100)
                {
                    SetTextGreen();Cprintf("英语满分100\n");SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("修改成功！");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 54:
        case 102:
            cout<<endl;
            printf("\n\n");Mprintf("请输入体育成绩:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->et = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

                if (s->et < 0 || s->et > 100)
                {
                    SetTextGreen();Cprintf("体育满分100\n");SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("修改成功！");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 55:
        case 103:
            cout<<endl;
            printf("\n\n");Mprintf("请输入计算机成绩:");
            while (1)
            {

                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("请输入正整数\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->pc = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形

                if (s->pc < 0 || s->pc > 100)
                {
                    SetTextGreen();Cprintf("计算机满分100\n");SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("修改成功！");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);
            PrintSingleStu(*s);
            break;
        default:
            break;
        }
    }

    saveFile();
}

void Manager::PrintUpdateStu()
{
    int choice,id;
    char name[50];
    string str;
    Student S,*s,*stu;
    s = new Student();

    while(true)
    {
        UpdateWelcome(20);

        //判断学生信息是否为空
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 78 || choice == 73 || 
                choice == 110 || choice == 105 || 
                choice == 96 || choice == 48
            )
            {
                break;
            }
        }

        switch (choice)
        {
        case 73:
        case 105:

            ShowCursor(true);
            printf("\n\n");Mprintf("请输入学号:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();
                printf("\n");
                while (!IsRegexInput(str)) // 判断输入的内容是否为整形
                {
                    SetTextGreen();Cprintf("学号只能是数字\n");SetTextWhite();
                    Mprintf("请重新输入:");
                    SetTextGreen();cin >> str;SetTextWhite();
                    printf("\n");
                }
                
                id = atoi(str.c_str()); //输入没有问题，进行字符串转换为整形
                if (id < 20220000 || id > 20229999)
                {
                    SetTextGreen();
                    Cprintf("学号格式错误\n");
                    SetTextWhite();
                    Mprintf("请重新输入:");
                }
                else
                {
                    break;
                }
            }
    
            stu = SearchById(id);
            
            UpdateStu(stu);
            
            break;
        case 78:
        case 110:
            ShowCursor(true);
            printf("\n\n");Mprintf("请输入姓名:");
            SetTextGreen();scanf("%s", name);SetTextWhite();

            stu = SearchByName(name);

            UpdateStu(stu);
            break;
        default:
            break;
        }
        
        if(choice == 96 || choice == 48)
        {
            break;
        }
    }
}


Manager::~Manager()
{

}

