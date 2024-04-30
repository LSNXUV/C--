#include <iostream>
using namespace std;

typedef struct Link
{

    int data;
    struct Link *next;

} LinkList;

LinkList *Create()
{
    LinkList *head, *s,*end;
    int i = 0;
    head = NULL;
    int k;
    while (cin >> k)
    {
        s = new LinkList;
        s->data = k;
        if(i == 0){
            end = s;
            end->next = NULL;
            head = end;
        }
        else{
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


LinkList *CombList(LinkList *head1, LinkList *head2,int n)
{
    //两个链表中一个为空则返回另一个，两个都为空则返回空（递归的结束条件）
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    LinkList *head = nullptr; //新链表的头
    //将两个链表第一个结点的较小结点尾插到新链表后
    if (n%2 == 0)
    {
        head = head2;
        head2 = head2->next;
    }
    else
    {
        head = head1;
        head1 = head1->next;
    }
    //递归合并链表，并将合并的链表尾插到新链表后
    head->next = CombList(head1, head2,n+1);
    
    return head; //返回新链表
}

int main()
{

    LinkList *p1;
    LinkList *p2;
    LinkList *s;
    int i = 1;
    p1 = Create();
    p2 = Create();

    cout<<endl<<"L1: ";
    s = p1;
    while(s){
        cout<<s->data<<" ";
        s = s->next;
    }
    cout<<endl<<"L2: ";
    s = p2;
    while(s){
        cout<<s->data<<" ";
        s = s->next;
    }
    cout<<endl<<"L1和L2合并后：";
    cout<<endl<<"L1: ";
    s = p1;
    while(s){
        cout<<s->data<<" ";
        s = s->next;
    }
    cout<<endl<<"L2: ";
    s = p2;
    while(s){
        cout<<s->data<<" ";
        s = s->next;
    }

    s = CombList(p1,p2,i);
    cout<<endl<<"L3: ";
    while (s)
    {
        cout<<s->data<<" ";
        s = s->next;
    }
    

    system("pause");
    return 0;
}