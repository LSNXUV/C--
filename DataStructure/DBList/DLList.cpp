#include <iostream>
using namespace std;

typedef struct DLList{
    int a;
    struct DLList *prior;
    struct DLList *next;
} DLList;

void CreateList(DLList *DL){
    DLList *s,*r;
    int i;
    DL = (DLList *)malloc(sizeof(DLList));
    r = DL;
    for(i = 0;i<100;i++){
        s = (DLList *)malloc(sizeof(DLList));
        s->a = i;
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}

int main(){
    DLList *DL;
    CreateList(DL);

    system("pause");
    return 0;
}