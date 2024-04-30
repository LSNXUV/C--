#include <iostream>
using namespace std;

typedef struct Linklist
{
    int data;
    struct Linklist *next;
} LinkList;

LinkList *Head_Creat(int arr[], int n) //逆向
{
    LinkList *head, *p;
    int i = 0;
    head = NULL;
    while (i < n)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = arr[i++];
        p->next = head;
        head = p;
    }
    return head;
}

void Display(LinkList *p)
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

/* LinkList *End_Creat() //顺向
{
    LinkList *end, *p,*head = NULL;
    int i,k;
    while(cin>>k)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = k;
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
    return head;
} */

int main()
{

    LinkList *L1;
    int arr[500], n = 0,k;
    while (cin >> k)
    {
        if(k!=-1){
            arr[n++] = k;
        }
        else
        {
            break;
        }
    }
    cout << "原链表为：" << endl;
    if (n == 0)
    {
        cout << "空链表！";
        cout << endl << "逆置后的链表为：" << endl;
        cout << "空链表！";
    }
    else
    {
        for (int i = 0; i < n; i++)

        {
            cout << arr[i] << " ";
        }
        cout << endl
             << "逆置后的链表为：" << endl;
        L1 = Head_Creat(arr, n);
        Display(L1);
    }

    system("pause");
    return 0;
}