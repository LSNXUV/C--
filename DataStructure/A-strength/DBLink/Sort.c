#include<stdio.h>
#include<stdlib.h>

typedef struct DBlist
{
    int data;
    struct DBlist* next;
    struct DBlist *pre;
} DBLink;
 
 
int main()
{
    DBLink* head = (DBLink*)malloc(sizeof(DBLink));
    head->next = head;
    head->pre = head;
    DBLink* p =head, *p1 = head,*p2 = head;
    int n;
    scanf("%d", &n);
    int i = 0, j;
    for (i = 0; i < n; i++)
    {
        p1 = (DBLink*)malloc(sizeof(DBLink));
        scanf("%d", &j);
        p1->data = j;
        p2->next = p1;
        p1->pre = p2;
        head->pre = p1;
        p2 = p1;
        p1->next = head;
    }
    p1 = p2 = head->next;
    for (p = head->next->next, i = 0; p != head; p = p->next, i++)
    {
        if (p->data > head->next->data)
            break;
    }
    p = p->pre;
    if (i != 0)
    {
        head->next = head->next->next;
        head->next->next->pre = head;
        p->next->pre = p1;
        p1->next = p->next;
        p->next = p1;
        p1->pre = p;
    }
    for (p = head->next; p != head; p = p->next)
    {
        printf("%d ", p->data);
    }
    scanf("%d",n);
    return 0;
}