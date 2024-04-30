#include <iostream>
#include <cstring>

#define MAXSIZE 2000
typedef int ElemType;

using namespace std;

typedef struct DBTree
{
    ElemType data;
    struct DBTree *lchild;
    struct DBTree *rchild;
}DBTree;


//根据后序遍历和中序遍历构建二叉树
DBTree* CreateDBTreeByAft(int inarr[], int aftarr[], int length)
{
    if (length == 0)//都构建完毕
    {
        return NULL;
    }
    int c = aftarr[length - 1];//树的根为后序遍历最后一个字符
    // cout<<c<<" "<<length<<endl;
    // cout<<c<<" "<<endl;
    int i = 0;
    while ((inarr[i] != c) && i < length)//找到中序遍历中该根的位置
    {
        i = i + 1;
    }
    int leftlength = i;//确定左子树中结点的数目
    int rightlength = length - i - 1;//确定右子树中结点的数目
    DBTree *T;
    T = (DBTree*)malloc(sizeof(DBTree));
    T->data = c;//建立新结点，每次都使其等于每棵小子树的根结点
    T->lchild = NULL;
    T->rchild = NULL;
    T->lchild = CreateDBTreeByAft(&inarr[0], &aftarr[0], leftlength);//创建左子树
    T->rchild = CreateDBTreeByAft(&inarr[i + 1], &aftarr[i], rightlength);//创建右子树

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
void MaxAndMin(DBTree *bt,int &max,int &min)
{
    if(bt)
    {
        if(bt->data > max){
            max = bt->data;
        }
        else if(bt->data < min)
        {
            min = bt->data;
        };
        MaxAndMin(bt->lchild,max,min);
        MaxAndMin(bt->rchild,max,min);
    }
}


int main()
{
    int length = 0;
    int inarr[MAXSIZE];
    int aftarr[MAXSIZE];

    cin>>inarr[length++];
    while(cin.get() != '\n')
    {
        cin>>inarr[length++];
    }
    
    for(int i = 0;i<length;i++)
    {
        cin>>aftarr[i];
    }

    
    DBTree *T;
    T = (DBTree*)malloc(sizeof(DBTree));
    T = CreateDBTreeByAft(inarr, aftarr, length);
    cout<<"先序递归遍历：";
    PreOrder(T);
    cout<<endl<<"中序递归遍历：";
    InOrder(T);
    cout<<endl<<"后序递归遍历：";
    PostOrder(T);
    int max=T->data,min=T->data;
    MaxAndMin(T,max,min);
    cout<<endl<<"该二叉树中最大值:"<<max<<",最小值为："<<min<<"."<<endl;
    cout<<endl<<"该二叉树中最大和最小值的差的绝对值为："<<abs(max-min)<<".";
    
    system("pause");
    return 0;
}
