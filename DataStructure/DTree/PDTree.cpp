#include <iostream>
using namespace std;

typedef struct tree
{
    int data;
    struct tree *lchild,*rchild;
} DBTree;


//节点个数
int NodeCount(DBTree *bt)
{
    int num1,num2;
    if(bt==NULL)
    {
        return 0;
    }
    else
    {
        num1 = NodeCount(bt->lchild);
        num2 = NodeCount(bt->rchild);
        return num1 + num2 + 1 ;
    }
}
//叶子结点


void PreOrder(DBTree *bt)
{
    if(bt)
    {
        cout<<bt->data;
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
void InOrder(DBTree *bt)
{
    if(bt)
    {
        InOrder(bt->lchild);
        cout<<bt->data;
        InOrder(bt->rchild);
    }
}

void PostOrder(DBTree * bt)
{
    if(bt)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data;
    }
}


int main(){


    system("pause");
    return 0;
}