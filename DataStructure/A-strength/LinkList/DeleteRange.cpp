#include <iostream>
using namespace std;

typedef struct Link
{

    int data;
    struct Link *next;

} LinkList;

//无头结点尾插法
LinkList *Create()
{
    LinkList *head, *s, *end;
    int i = 0;
    head = NULL;
    int k;
    while (cin >> k)
    {
        s = new LinkList;
        s->data = k;
        if (i == 0)
        {
            end = s;
            end->next = NULL;
            head = end;
        }
        else
        {
            end->next = s;
            s->next = NULL;
            end = s;
        }
        i++;
        if (cin.get() == '\n')
            break;
    }
    return head;
}

//删除给定范围的元素
LinkList *DeleteRange(LinkList *L, int m, int n)
{
    if (L == NULL) 
        return L;

    LinkList *p;
    if (m <= L->data && L->data <= n)
    {
        p = L;
        L = L->next;
        free(p);
        L = DeleteRange(L,m,n);
    }
    else
    {
        L->next = DeleteRange(L->next, m, n);
    }
    return L;
}

int main()
{

    LinkList *p;
    LinkList *s;
    int  m, n;

    p = Create();
    cin >> m >> n;
    s = p;
    cout<<"L: ";
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }

    p = DeleteRange(p, m, n);

    cout<<endl<<"删除"<<m<<"～"<<n<<"的结点"<<endl;
    s = p;
    cout<<"L: ";
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }

    system("pause");
    return 0;
}