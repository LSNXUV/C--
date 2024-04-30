#include <iostream>
using namespace std;
#define MaxSize 200

typedef struct
{
    char str[MaxSize];
    int length;
} SqString;


//求长度并记录
void StrLength(SqString *S)
{
    S->length = 0;
    while (S->str[S->length++] != '\0')
        ;
    S->length--;
}

//BF算法1
int index2(SqString str, SqString substr)
{
    int i, j, k;
    for (i = 0; i < str.length; i++)
    {
        for (j = i, k = 0; str.str[j] == substr.str[k]; 
            j++, k++);

        // cout<<i<<" "<<k<<endl;
        if (k == substr.length+1)
            //注意j每次从i开始,有回溯
            
            return  i+1;
    }
    return -1;
}

//BF算法2
int index(SqString S, SqString T) 
{
    int i = 0, j = 0;
    while (i < S.length && j < T.length)
    {
        if (S.str[i] == T.str[j]) //继续匹配下一个字符
        {
            i++;
            j++;
        }
        else //主串、子串指针回溯重新开始下一次匹配
        {
            i = i - j + 1; //主串从下一个位置开始匹配
            j = 0;         //子串从头开始匹配
        }
    }
    if (j >= T.length)
    {
        return (i - T.length+1); //返回匹配的第一个字符的下标
    }
    else //模式匹配不成功
    {
        return (-1);
    }
}


void GetNextval(SqString t, int nextval[])
{
    int j = 0, k = -1;
    nextval[0] = -1;
    while (j < t.length)
    {
        if (k == -1 || t.str[j] == t.str[k])
        {
            j++;
            k++;
            if (t.str[j] != t.str[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}

//KMP算法
int KMPIndex(SqString s, SqString t)
{
    int nextval[MaxSize], i = 0, j = 0;
    GetNextval(t, nextval);
    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.str[i] == t.str[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    if (j >= t.length)
        return (i - t.length+1);
    else
        return (-1);
}


//主界面
void welcome()
{

    system("cls");

    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓  ☆      顺序串的模式匹配      ☆  〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          1.BF算法          ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          2.BF算法2         ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          3.KMF算法         ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          0.退出系统        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆                              ☆  ★〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

    cout << "初始化成功！" << endl;
}

//BF测试1
void BF()
{
    cout << "请输入要测试的原字符串和模板字符串:" << endl;
    SqString S, T;
    cin >> S.str >> T.str;
    StrLength(&S);
    StrLength(&T);

    if (index(S, T) != -1)
    {
        cout << "匹配成功！" << endl;
        cout << "对应下标为:" << index(S, T)<<endl;
        return;
    }
    cout << "匹配失败！" << endl;
    return;
}
//BF测试2
void BF2()
{
    cout << "请输入要测试的原字符串和模板字符串:" << endl;
    SqString S, T;
    cin >> S.str >> T.str;
    StrLength(&S);
    StrLength(&T);

    if (index2(S, T) != -1)
    {
        cout << "匹配成功！" << endl;
        cout << "对应下标为:" << index2(S, T)<<endl;
        return;
    }
    cout << "匹配失败！" << endl;
    return;
}
//KMP测试1
void KMP(){
    cout << "请输入要测试的原字符串和模板字符串:" << endl;
    SqString S, T;
    cin >> S.str >> T.str;
    StrLength(&S);
    StrLength(&T);

    if (KMPIndex(S, T) != -1)
    {
        cout << "匹配成功！" << endl;
        cout << "对应下标为:" << KMPIndex(S, T)<<endl;
        return;
    }
    cout << "匹配失败！" << endl;
    return;
}

int main()
{
    welcome();
    while (1)
    {
        int choice;
        cout << "请输入需要实现的功能序号:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            BF();
            continue;
        case 2:
            BF2();
            continue;
        case 3:
            KMP();
            continue;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}