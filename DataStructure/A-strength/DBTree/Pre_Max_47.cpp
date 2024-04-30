#include <iostream>
#include <cstring>

#define MAXSIZE 100
typedef int ElemType;

using namespace std;

typedef struct DBTree
{
    ElemType data;
    struct DBTree *lchild;
    struct DBTree *rchild;
}DBTree;


//根据前序遍历和中序遍历构建二叉树
DBTree* CreateDBTreeByPre(int instr[], int prestr[], int length)
{
    if (length == 0)//都构建完毕
    {
        return NULL;
    }
    int c = prestr[0];//树的根为前序遍历第一一个字符
    // cout<<c<<" "<<endl;
    int i = 0;
    while ((instr[i] != c) && i < length)//找到中序遍历中该根的位置
    {
        i = i + 1;
    }
    int leftlength = i;//确定左子树中结点的数目
    int rightlength = length - i - 1;//确定右子树中结点的数目
    DBTree *T;
    T = (DBTree*)malloc(sizeof(DBTree));
    T->data = c;//建立新结点，每次都使其等于每棵小子树的根结点
    // printf("%c",c);//调试
    T->lchild = NULL;
    T->rchild = NULL;
    T->lchild = CreateDBTreeByPre(&instr[0], &prestr[1], leftlength);//创建左子树
    T->rchild = CreateDBTreeByPre(&instr[i + 1], &prestr[i+1], rightlength);//创建右子树

    return T;
}

//后序遍历输出
void PreOrder(DBTree *bt)
{
    if(bt)
    {
        cout<<bt->data<<"  ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
void InOrder(DBTree *bt)
{
    if(bt)
    {
        InOrder(bt->lchild);
        cout<<bt->data<<"  ";
        InOrder(bt->rchild);
    }
}

void PostOrder(DBTree * bt)
{
    if(bt)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data<<"  ";
    }
}

int MaxTree(DBTree *T,DBTree *&MaxT,int &result)
{
    if(!T)
    {
        return 0;
    }
    int sum = T->data;
    if(T->lchild || T->rchild)
    {
        int left = MaxTree(T->lchild,MaxT,result);
        int right = MaxTree(T->rchild,MaxT,result);
        sum += left + right;

        if(sum >= result)
        {
            result = sum;
            MaxT = T;
        }
    }
    return sum;
}

int main()
{
    int length = 0,i=0,max=0;
    int inarr[MAXSIZE];
    int prearr[MAXSIZE];
    cin>>prearr[length++];
    while(cin.get() != '\n')
    {
        cin>>prearr[length++];
    }
    cin>>inarr[i++];
    while(cin.get() != '\n')
    {
        cin>>inarr[i++];
    }
    
    DBTree *T,*MaxT;
    T = (DBTree*)malloc(sizeof(DBTree));
    MaxT = (DBTree*)malloc(sizeof(DBTree));
    T = CreateDBTreeByPre(inarr, prearr, length);
    cout<<"先序递归遍历：";
    PreOrder(T);
    cout<<endl<<"中序递归遍历：";
    InOrder(T);
    cout<<endl<<"后序递归遍历：";
    PostOrder(T);
    MaxTree(T,MaxT,max);
    cout<<endl<<"以"<<MaxT->data<<"为根的子树的所有结点和最大，最大和为："<<max<<".";
    system("pause");
    return 0;
}
