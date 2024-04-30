#include <iostream>
#define MAX 100
using namespace std;


typedef struct
{
    int a[MAX];
    int length;
} SqList;


/* //定位元素
void Locate(SqList *sq)
//插入元素
void Insert(SqList *sq)
//删除元素
void Delete(SqList *sq)
//查找元素
void Find(SqList *sq)
//输出原始数据
void OutData(SqList *sq)
//输出操作之后的数据
void OutList(SqList *sq)
//打印主界面
void welcome(SqList *sq) */

//
void OutData(SqList *sq)
{
    int i;
    for (i = 0; i < sq->length; i++)
    {
        cout << sq->a[i] << "  ";
    }
    cout << endl;
}
void OutList(SqList *sq)
{
    int i;
    for (i = 0; i < sq->length; i++)
    {
        cout << sq->a[i] << " ";
    }
    cout << endl;
}

//定位
void Locate(SqList *sq)
{
    int index;
    cout << "请输入index:" << endl;
    cin >> index;
    if (index < 1 || index > sq->length)
    {
        cout << "不存在第" << index << "个元素" << endl;
    }
    else
    {
        cout << "第" << index << "个元素:" << sq->a[index - 1] << endl;
    }
}
//查找元素
void Find(SqList *sq)
{
    int i = 0, item;
    cout << "请输入要查找的元素:" << endl;
    cin >> item;
    while (i < sq->length && sq->a[i] != item)
        i++;
    if (i >= sq->length)
        cout << "待查找元素" << item << "不存在！" << endl;
    else
        cout << "查找：元素" << item << "是第" << i + 1 << "个元素" << endl;
}

//插入元素
void Insert(SqList *sq)
{
    int j, l, k;
    cout << "请输入要插入的位置和元素:" << endl;
    cin >> l >> k;
    if (l < 1 || l > sq->length)
    {
        cout << "插入位置非法！" << endl;
    }
    else
    {
        l--;
        for (j = sq->length; j > l; j--)
            sq->a[j] = sq->a[j - 1];
        sq->a[l] = k;
        sq->length++;
        cout << "插入后的顺序表为L: ";
        OutList(sq);
    }
}

//删除元素
void Delete(SqList *sq)
{
    int j, dl;
    cout << "请输入要删除的元素位置:" << endl;
    cin >> dl;
    if (dl < 1 || dl > sq->length)
    {
        cout << "删除第" << dl << "个元素不存在！" << endl;
    }
    else
    {
        dl--;
        for (j = dl; j < sq->length - 1; j++)
            sq->a[j] = sq->a[j + 1];
        sq->length--;
        cout << "删除后的顺序表为L: ";
        OutList(sq);
    }
}
//打印主界面
void welcome(SqList *sq)
{
    system("cls");

    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓  ☆   顺 序 表 测 试 系 统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          1.定位元素        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          2.插入元素        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          3.删除元素        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          4.查找元素        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          5.输出元素        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          0.退出系统        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆                              ☆  ★〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

    cout << "初始化链表成功！" << endl;

    int n = 0;
    int op;

    cout << "请输入元素个数:" << endl;
    cin >> sq->length;

    cout << "请输入" << sq->length << "个元素:" << endl;

    while (cin >> sq->a[n++])
    {
        if (cin.get() == '\n')
            break;
    }
    sq->length = n;
    cout << "创建成功！" << endl;
}

int main()
{
    SqList *sq;
    sq = (SqList *)malloc(sizeof(SqList));
    int op;
    //打印主界面
    welcome(sq);
    while (true)
    {
        //指引用户操作
        printf("\n请输入对应的功能键(数字): ");
        cin >> op;
        switch (op)
        {
        case 1:
            Locate(sq);
            break;
        case 2:
            Insert(sq);
            break;
        case 3:
            Delete(sq);
            break;
        case 4:
            Find(sq);
            break;
        case 5:
            cout<<"当前数据为:"<<endl;
            OutList(sq);
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}