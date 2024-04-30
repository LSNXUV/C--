#include <stdio.h>
#include <stdlib.h>

typedef struct Linklist
{
    int data;
    struct Linklist *next;
} LinkList;

LinkList *Head_Creat() //逆向
{
    LinkList *head, *p;
    int k;
    head = NULL;
    while(scanf("%d",&k))
    {
        if(k==-1) break;
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = k;
        p->next = head;
        head = p;
    }
    return head;
}

int main(){
    int k;
    LinkList *L;
    scanf("%d",&k);
    L = Head_Creat();
    int i = 1;
    while (i!=k && L)
    {
        L = L->next;
        i++;
    }
    if(L)
    {
        printf("%d",L->data);
    }else{
        printf("Not Found");
    }
    return 0;
}
