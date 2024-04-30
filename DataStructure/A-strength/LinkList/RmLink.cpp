#include <iostream>
using namespace std;

typedef struct Linklist
{
    int data;
    struct Linklist *next;
} LinkList;

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

void Remove(LinkList *&L)
{

    LinkList *h1,*h2,*h3;
    int x = L->data;
    h1 = L;
    h2 = L->next;
    while(h2)
    {
        h3 = h2;
        h2 = h2->next;
        if(h3->data < x)
        {
            h1->next = h3->next;
            h3->next = L;
            L = h3;

        }else{
            h1 = h1->next;
        }
    }
}

int main(){
    LinkList *L,*head;
    int n;
    cin>>n;
    L = End_Creat(n);
    head = L;
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    Remove(L);
    head = L;
    cout<<endl;
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    system("pause");
    return 0;
}