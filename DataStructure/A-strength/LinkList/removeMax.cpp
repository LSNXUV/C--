#include <iostream>
using namespace std;

typedef struct Link
{
    int data;
    struct Link *next;

} LinkList;

LinkList *RemoveMax(LinkList *L)
{
    LinkList *s, *sf, *head, *end;
    int max = L->data;
    s = L;
    end = NULL;
    head = L;
    while (head->next)
    {
        if (!head->next->next)
        {
            end = head->next;
        }
        if (head->next->data > max)
        {
            max = head->next->data;
            s = head;
        }
        head = head->next;
    }

    if (s == L)
    {
        if (s->data == max)
        {

            L = L->next;
            end->next = s;
            s->next = NULL;
            return L;
        }
        else
        {
            sf = s->next;
            s->next = sf->next;
            end->next = sf;
            sf->next = NULL;
            return L;
        }
    }
    else if (s != end)
    {
        sf = s->next;
        s->next = sf->next;
        end->next = sf;
        sf->next = NULL;
        return L;
    }
    return L;
}

int main()
{
    int k, i = 0;
    LinkList *head = NULL, *p, *end;

    while (cin >> k)
    {
        if (k == -1)
            break;
        p = new LinkList;
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
        i++;
    }
    head = RemoveMax(head);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    system("pause");
    return 0;
}