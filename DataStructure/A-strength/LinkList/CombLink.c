
#include<stdlib.h>
#include<stdio.h>
//链表结构体
typedef struct Node
{
    int data;              //数据域
    struct Node *next;     //指针域
}Node,*LinkList;

LinkList LinkedListInit()  //初始化链表
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}

LinkList CreateList(int x) //尾插法建立单链表
{

    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    Node *r;
    r = L;
    int y,i;
    for(i=0;i<x;i++)
    {
        scanf("%d",&y);
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = y;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}

 void DeleteLink(LinkList L) //删除相同的元素
{
    Node *p,*q,*s;
    for(p=L->next;p!=NULL;)
   {
       q=p->next;
       if(q!=NULL)
       {
           //如果找到相同元素
           if(q->data==p->data)
          {
              s=q->next;
              p->next=s;
              free(q);    //释放节点
              q=s;
          }
          else p=p->next;
       }
       else break;
   }

}

LinkList CoalitionLinkList(LinkList l1,LinkList l2) //合并单链表
{
    Node *p1,*p2,*r;
    LinkList l3;
    p1 = l1->next;
    p2 = l2->next;
    l3 = l1;
    l3->next = NULL;
    r = l3;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data<=p2->data)
        {
            r->next = p1;
            r = p1;
            p1 = p1->next;
        }
        else
        {
            r->next = p2;
            r = p2;
            p2 = p2->next;
        }
    }
    if(p1) r->next = p1;
    else r->next = p2;
    free(l2);
    return l3;
}

int main()
{
    LinkList l1,l2,l3,p3;
    int x,y;
    scanf("%d %d",&x,&y);
    l1 = CreateList(x);
    l2 = CreateList(y);
    l3 = LinkedListInit();
    l3 = CoalitionLinkList(l1,l2);
    DeleteLink(l3);
    for(p3 = l3->next;p3!=NULL;p3 = p3->next) //遍历整个链表
        printf("%d ",p3->data);
    return 0;
}