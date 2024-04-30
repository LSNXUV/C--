#include <iostream>
using namespace std;

typedef struct Link
{
    int data;
    struct Link *next;
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


int main(){
    int n,i = 1;
    cin>>n;
    LinkList *L,*p;
    L = End_Creat(n);
    p = L;
    
    if(n%2 == 0)
    {
        while(i++!=n/2 )
        {
            p = p->next;
        }
    }
    else{
        while (i++!=(n+1)/2)
        {
            p = p->next;
        }
    }
    cout<<p->data;
    system("pause");
    return 0;
}
