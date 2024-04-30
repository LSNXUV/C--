#include <iostream>

#include <stdio.h>

#include <malloc.h>

typedef int ElemType;	   /*假定线性表元素的类型为整型*/
#define MaxSize 100 	/*假定线性表的最大长度为1024*/

typedef struct LNode   //定义单链表节点类型
{   
    ElemType data;
    struct LNode *next; //指向后继节点
} LinkList; //链表类型


//头插法创建单链表 
LinkList *Head_Creat(int n) 
{
    LinkList *head, *p;
    int i;
    head = NULL;
    for (i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d",&p->data);
        p->next = head;
        head = p;
        // p->next = NULL;
    }
    return head;
}

//尾插法创建单链表 
LinkList *End_Creat(int n) 
{
    LinkList  *end, *p,*head = NULL;
    int i; 
    for (i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList ));
        scanf("%d",&p->data);
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

//输出单链表 
void Display(LinkList *p)
{
    if (!p)
    {
        printf("list is empty!");
    }
    while (p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


int main()
{	
    LinkList *head;
    int s, n;
    scanf("%d %d",&s,&n);
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


