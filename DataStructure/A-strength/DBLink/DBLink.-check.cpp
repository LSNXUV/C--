#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct DNode
{
    int data;
    int freq;
    struct DNode *next;
    struct DNode *prior;
} DBLink;

DBLink *h;

void sort(DBLink *&h) //根据freq降序排列，写成一个函数，下面没有调用只是当做测试用，因为作业要求只写一个函数
{
    DBLink *p, *q, *pre;
    p = h->next->next;
    h->next->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        pre = h;
        while (pre->next != NULL && pre->next->freq >= p->freq) //根据freq降序
            pre = pre->next;
        p->next = pre->next;
        if (pre->next != NULL)
            pre->next->prior = p;
        pre->next = p;
        p->prior = pre;
        p = q;
    }
}

bool LocateNode(DBLink *&h, int x)
{
    DBLink *p;
    p = h->next;
    int i = 0;
    //查找x所在的位置
    while (p != NULL && p->data != x)
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
    {
        return false;
    }
    p->freq++;
    sort(h);
    return true;
}
int main()
{
    DBLink *head, *h, *s;
    int i = 0, n = 0, k, arr[20];
    head = (DBLink *)malloc(sizeof(DBLink));
    head->prior = head->next = NULL;
    h = head;
    while (cin >> k)
    {

        s = (DBLink *)malloc(sizeof(DBLink));
        s->data = k;
        s->freq = 0;
        h->next = s;
        s->prior = h;
        s->next = NULL;
        h = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }
    while (cin >> k)
    {
        arr[n++] = k;
        if (cin.get() == '\n')
            break;
    }

    cout<<"L: ";
    h = head->next;
    while(h)
    {
        cout << h->data << "[" << h->freq << "] ";
        h = h->next;
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
        if (LocateNode(head, arr[i]))
        {
            cout << "查找" << arr[i] << "结点 查找后L: ";
            h = head->next;
            while (h)
            {
                cout << h->data << "[" << h->freq << "] ";
                h = h->next;
            }
        }
        else{
            cout << "查找" << arr[i] << "结点 "<<arr[i]<<"没有找到!";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}