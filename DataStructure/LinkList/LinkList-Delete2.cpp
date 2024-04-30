#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *creat()//��������
{
    Node *head = NULL,*p;
    while(1)
    {
        p=(Node *) malloc(sizeof(Node));
        cin>>p->data;
        if(p->data==-1)break;
        p->next = head;
        head=p;
    }
    return head;
}

void Display(Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}


Node *Delete(Node * head,int n)
{
    
    struct Node *p1,*p2;
    if(head->data==n)
    {
        p2=head;
        head=head->next;
        free(p2);
    }
    p1=head;
    p2=head->next;
    while(p2!=NULL)
    {
        if(p2->data==n)
        {
            p1->next=p2->next;
            free(p2);
            p2=p1->next;
        }
        else
        {
            p1=p2;
            p2=p2->next;
        }
    }
    return head;
};

int main()
{
    Node *head;
    head = creat();
    int n;
    cin>>n;
    head=Delete(head,n);
    Display(head);
    
    return 0;
}


