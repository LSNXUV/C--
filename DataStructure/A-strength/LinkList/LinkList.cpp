#include <iostream>

using namespace std;

typedef struct LList
{
    int data;
    struct LList *next;
} LinkList;

void OutData(LinkList *p)
{
    if (!p)
    {
        cout << "list is empty!";
    }
    while (p)
    {
        cout<<" " << p->data;
        p = p->next;
    }
    cout << endl;
}

//定位
void Locate(LinkList *p, int index, int n)
{
    int i;
    LinkList *h;
    h = p;

    if (index > n || index < 0)
    {
        cout << "不存在第" << index << "个元素"<<endl;
        return;
    }
    for (i = 0; i < index - 1; i++)
        h = h->next;

    cout << "  第" << index << "个元素:"<< h->data << endl;

}

//查找元素
void Find(LinkList *p,int elem,int n)
{
    int  i = 1;
    LinkList *h;
    h = p;
    
    while (h && h->data != elem)

    {

        h = h->next;
        i++;

    }

    if(i < 0 || i>n){
        cout<<"待查找元素"<<elem<<"不存在！"<<endl;
        return;
    }
    cout << "查找：元素" << elem << "是第" << i << "个元素"<< endl;
}

//插入元素
void Insert(LinkList *p, int k, int m, int *len)
{

    int i = 1;
    LinkList *h, *L;

    if (k > *len)
    {
        cout << "插入位置非法！" << endl;
        cout<<"  长度:"<<*len<<endl;
        return;
    }
    h = p;
    L = (LinkList *)malloc(sizeof(LinkList));
    L->data = m;

    while (i != k - 1)
    {
        h = h->next;
        i++;
    }

    L->next = h->next;
    h->next = L;
    *len = *len + 1;
    cout << "插入后的单链表为L:";
    OutData(p);
    cout<<"  长度:"<<*len<<endl;
}

//删除元素
void Delete(LinkList *p,int k,int *len)
{
    int n = 1;
    LinkList *p1, *p2;
    p1 = p;
    p2 = p1->next;
    if(k < 0 || k > *len){
        cout<<"  删除第"<<k<<"个元素不存在！"<<endl;
        cout<<"  长度:"<<*len<<endl;
        return;
    }
    while (n != k-1)
    {
        p1 = p1->next;
        p2 = p1->next;
        n++;
    }
    p1->next = p2->next;
    p2->next = NULL;
    free(p2);
    cout<<"删除后的单链表为L:";
    OutData(p);
    *len = *len - 1;
    cout<<"  长度:"<<*len<<endl;
}

int main()
{

    LinkList *L, *p;

    L = NULL;

    int arr[1000], i, n = 0;

    while (cin >> arr[n++])
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = arr[n - 1];
        p->next = L;
        L = p;
        if (cin.get() == '\n')
            break;
    }
    cout << "测试结果：" << endl;
    cout << "原始数据：";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl
         << "原始单链表L:";

    OutData(L);
    cout<<"  长度:"<<n<<endl;
    int k, m, index, elem, dl;

    cin >> k >> m;
    Insert(L, k, m, &n);

    cin >> index;
    Locate(L, index, n);

    cin>>elem;
    Find(L,elem,n);


    cin>>dl;
    Delete(L,dl,&n);

    cout<<"销毁L";

    system("pause");
    return 0;
}