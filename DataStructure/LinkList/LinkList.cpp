#include <iostream>

using namespace std;

typedef struct LList
{
    int data;
    struct LList *next;
} LinkList;

/* 
//头插法输入数据
LinkList *HeadCreate(int n)
//尾插法输入数据
LinkList *EndCreate(int n)
//定位元素
void Locate(LinkList *p)
//插入元素
void Insert(LinkList *p)
//删除元素
void Delete(LinkList *p)
//查找元素
void Find(LinkList *p)
//输出数据
void OutData(LinkList *p)
//打印主界面
void welcome(int *n) */


LinkList *HeadCreate(int n){
    LinkList *head, *p;
    int i;
    head = NULL;

    cout<<"请输入"<<n<<"个数据："<<endl;
    for (i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        cin >> p->data;
        p->next = head;
        head = p;
        // p->next = NULL;
    }
    cout << "创建成功！" << endl;
    return head;
}

LinkList *EndCreate(int n){
    LinkList *end, *p,*head = NULL;
    int i; 
    cout<<"请输入"<<n<<"个数据："<<endl;

    for (i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        cin >> p->data;
        if (i == 0)
        {
            end = p;
            end->next = NULL;
            head = end;
        }
        else
        {
            end->next = p;
            p->next = NULL;
            end = p;
        }
    }
    cout << "创建成功！" << endl;
    return head;
}

void OutData(LinkList *p)
{
    if (!p)
    {
        cout << "list is empty!";
    }
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }

}
//定位
void Locate(LinkList *p)
{
    int n,i;
    LinkList *h;
    h = p;
    cout<<"请输入要定位的元素索引:"<<endl;
    cin>>n;
    if(!p)
    {
        cout << "list is empty!";
        return ;
    }
    
    for(i = 0;i<n-1;i++) h = h->next;
    cout<<"第"<<n<<"个元素为:"<<endl<<h->data<<endl;
    OutData(p);
}
//查找元素
void Find(LinkList *p)
{
    int n,i = 1;
    LinkList *h;
    h = p;
    cout<<"请输入要查找的元素:"<<endl;
    cin>>n;
    if(!p){
        cout << "list is empty!";
        return;
    }
    while(h->data != n)
    {
        h = h->next;
        i++;
    }
    cout<<"元素在第"<<i<<"个位置"<<endl;
    OutData(p);
}

//插入元素
void Insert(LinkList *p)
{
    int m,n,i = 1;
    LinkList *h,*L;

    h = p;

    L = (LinkList *)malloc(sizeof(LinkList));

    cout<<"请输入要插入的元素和插入位置:"<<endl;
    cin>>L->data>>n;

    if(!p){
        cout << "list is empty!";
        return;
    }

    while(i != n-1)
    {
        h = h->next;
    }

    L->next = h->next;
    h->next = L;

    cout<<"插入后的数据为:"<<endl;

    OutData(p);
}

//删除元素
void Delete(LinkList *p)
{
    int n;
    LinkList *p1,*p2;

    cout<<"请输入要删除的元素:"<<endl;
    cin>>n;

    if(!p){
        cout << "list is empty!";
        return;
    }
    if(p->data == n)
    {
        p2=p;
        p=p->next;
        free(p2);
    }
    p1=p;
    p2=p->next;
    while(p2!=NULL)
    {
        if(p2->data == n)
        {
            p1->next=p2->next;
            free(p2);
            p2=p1->next;
        }
        else
        {
            p1=p2;
            p2=p2->next;
        }
    }
    OutData(p);

}

//打印主界面
void welcome(int *n)
{
    system("cls");

    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓  ☆     链 表 测 试 系 统      ☆  〓〓〓〓〓〓〓〓〓〓\n");
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

    cout<<"请输入要输入元素的个数:"<<endl;

    cin>>*n;

}

    int main()
    {
        LinkList *L1;
        LinkList *L2;
        int n;

        welcome(&n);

        // L1 = HeadCreate(n);

        L2 = HeadCreate(n);

        int op;

        while (true)
        {
            //指引用户操作
            printf("\n请输入对应的功能键(数字): ");
            cin >> op;
            switch (op)
            {
            case 1:
                Locate(L2);
                break;
            case 2:
                Insert(L2);
                break;
            case 3:
                Delete(L2);
                break;
            case 4:
                Find(L2);
                break;
            case 5:
                cout<<"当前数据为:"<<endl;
                OutData(L2);
                break;
            default:
                break;
            }
        }
        system("pause");
        return 0;
    }