
#include "System.h"

//主菜单界面
void System::welcome()
{
    system("cls");
    printf("\n\n");

    Cprintf("欢迎~");
    printf("\n\n");

    Cprintf("文件加解密系统");
    printf("\n\n");

    Cprintf("1.写入文件");
    printf("\n\n");

    Cprintf("2.查看文本");
    printf("\n\n");

    Cprintf("3.设置密钥");
    printf("\n\n");

    Cprintf("4.加密文件");
    printf("\n\n");

    Cprintf("5.解密文件");
    printf("\n\n");

    Cprintf("0.退出系统");
    printf("\n\n\n");

}

//主菜单
void System::menu()
{
    welcome();
    int choice;
    while(1)
    {
        Cprintf("请输入功能序号:");
        cin>>choice;
        if(choice == 0) break;
        
        printf("\n\n");

        switch(choice)
        {
            case 1:

                write();
                welcome();
                break;
            case 2:

                view();
                welcome();

                break;
            case 3:

                setkey();
                welcome();

                break;
            case 4:

                encrypt();
                welcome();

                break;
            case 5:

                decrypt();
                welcome();

                break;
        }
    }
    
}

void System::Cprintf(string str)
{
	cout<<setw(56+str.length()/2)<<str;
}

//写入文件
void System::write()
{
    
    printf("\n\n");
    cout<<"请输入要加密的文本字符串:";

    cin>>content;

    printf("\n\n");
    Cprintf("写入成功!");

    printf("\n\n");
    Cprintf("是否需要保存到\"content.txt\"文件?  (y(是)/n(否)):");
    

    string str;
    cin>>str;
    if(str == "y" ||str == "Y")
    {
        SaveFile();
        printf("\n\n");
        Cprintf("保存成功！");
    }
    else
    {

        Cprintf("保存失败！");

    }

    printf("\n\n");
    Cprintf("按Enter键继续");
    while(getch() != 13);
}

//查看文本
void System::view()
{
    printf("\n\n");

    Cprintf("当前文本字符串内容为:( 起始《  》结束)");

    printf("\n");

    cout<<"《\n\n";

    cout<<content;

    cout<<"\n\n 》\n";

    Cprintf("按Enter键继续");

    while(getch() != 13);
}

//设置密钥
void System::setkey()
{

    printf("\n\n");
    cout<<"请输入加密的密钥:";
    cin>>key;
    while(true)
    {
        if(!cin.good())
        {
            cout<<"密钥只能是小于等于26的正整数:";
            cin>>key;
        } else
        {
            break;
        }
    }
    

    Cprintf("按Enter键继续");
    while(getch() != 13);
}

//读取文件 
void System::ReadFile()
{
    ifstream in;

    system("md Content 2>nul");

    in.open("Content/content.txt");

    if (!in.is_open()){
        Cprintf("文件不存在！");
        return;
    }
    
    in>>content;

    in.close();

}

void System::SaveFile()
{
    ofstream out;
    system("md Content 2>nul");

	out.open("Content/content.txt");

    out<<content;

    out.close();

}

//加密
void System::encrypt()
{
    Cprintf("当前未加密文本字符串内容为:( 起始《  》结束)");
    printf("\n");

    cout<<"《\n\n";
    cout<<content<<"\n\n 》\n";

    Cprintf("是否要加密到\"content.txt\"?  y(是)/n(否):");
    
    string str;
    cin>>str;

    printf("\n");
    if(str == "y" || str == "Y"){

        encrypted(content);
        SaveFile();

        Cprintf("已加密完成并保存到\"content.txt\"");
        printf("\n\n");

        Cprintf("按Enter键继续");
        while(getch() != 13);

        return;
    }

}

char * System::encrypted(char cont[1000])
{
    int i;
    //移位
    int num;

    //移位后的ascii码值
    int ascii;

    //临时保存加密后的字符串
    static char temp[1000];

    for(i=0; cont[i]!='\0'; i++)
    {

        if (cont[i] >= 'A' && cont[i] <= 'Z')
		{
            num = cont[i] - 'A' + key;
            ascii = num % 26;

			temp[i] = ascii + 'A';
		}
		else if (cont[i] >= 'a' && cont[i] <= 'z')
		{
			num = cont[i] - 'a' + key;
            ascii = num % 26;

			temp[i] = ascii + 'a';

		}

    }

    cont[i] = '\0';

    
    //赋值给content
    for(int j=0; j<i; j++)
    {
        content[j] = temp[j];
    }


    return temp;
}

//解密
void System::decrypt()
{
    Cprintf("当前未解密文本字符串内容为:( 起始《  》结束)");
    printf("\n");

    cout<<"《\n\n";
    cout<<content<<"\n\n 》\n";

    Cprintf("是否要解密到\"content.txt\"?  y(是)/n(否):");
    

    string str;
    cin>>str;

    printf("\n");
    if(str == "y" || str == "Y"){

        decrypted(content);
        SaveFile();

        printf("\n");

        Cprintf("已解密完成并保存到\"content.txt\"");
        printf("\n\n");

        Cprintf("按Enter键继续");
        while(getch() != 13);
        return;

    }
}

char *  System::decrypted(char cont[1000])
{
    int i;
    //移位
    int NUM,num;

    //移位后的ascii码值
    int ASCII,ascii;

    //解密key
    int Decrykey = 26-key;

    //临时保存解密后的字符串
    static char temp[1000];

    for(i=0; cont[i]!='\0'; i++)
    {
        
        if (cont[i] >= 'A' && cont[i] <= 'Z')
		{
            num = cont[i] - 'A' + Decrykey;
            ascii = num % 26;

			temp[i] = ascii + 'A';
		}
		else if (cont[i] >= 'a' && cont[i] <= 'z')
		{
			num = cont[i] - 'a' + Decrykey;
            ascii = num % 26;

			temp[i] = ascii + 'a';

		}

    }

    cont[i] = '\0';


    //赋值给content
    for(int j=0; j<i; j++)
    {
        content[j] = temp[j];
    }

    return temp;

}