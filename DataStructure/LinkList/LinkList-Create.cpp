#include <iostream>

// #include <windows>
// #include <stdio.h>
// #include <stdlib.h>
using namespace std;

typedef struct Linklist
{
    int data;
    struct Linklist *next;
} LinkList;

LinkList *Head_Creat(int n) //逆向
{
    LinkList *head, *p;
    int i;
    head = NULL;
    for (i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        cin >> p->data;
        p->next = head;
        head = p;
        // p->next = NULL;
    }
    return head;
}
/* LinkList *Head_Creat() //逆向
{
    LinkList *head, *p;
    int k;
    head = NULL;
    while(cin>>k)
    {
        if(k == '\n') break;
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = k;
        p->next = head;
        head = p;
    }
    return head;
} */
LinkList *End_Creat(int n) //顺向
{
    LinkList *end, *p,*head = NULL;
    int i; 
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

int main()
{
    LinkList *head;
    int s, n;
    cin >> s >> n;
    if (s == 1)
    {
        head = Head_Creat(n);
        Display(head);
    }
    else
    {
        head = End_Creat(n);
        Display(head);
    }
    system("pause");

    return 0;
}
