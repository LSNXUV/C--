#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef char ElemType;
typedef struct DBTree
{
    ElemType data;
    struct DBTree *lchild;
    struct DBTree *rchild;
}DBTree;


//根据前序遍历和中序遍历构建二叉树
DBTree* CreateDBTreeByPre(char *instr, char *prestr, int length)
{
    if (length == 0)//都构建完毕
    {
        return NULL;
    }
    char c = prestr[0];//树的根为前序遍历第一一个字符
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
void AftOrderTraverse(DBTree *T)
{
    if (T)
    {
        AftOrderTraverse(T->lchild);
        AftOrderTraverse(T->rchild);
        printf("%c", T->data);
    }
}
int main()
{
    char instr[MAXSIZE];
    char prestr[MAXSIZE];
    scanf("%s", prestr);
    scanf("%s", instr);
    int length = strlen(instr);//结点的数目无论前，中，后序遍历都是相同的
    DBTree *T;
    T = (DBTree*)malloc(sizeof(DBTree));
    T = CreateDBTreeByPre(instr, prestr, length);
    AftOrderTraverse(T);
    // scanf("%d",length);
    return 0;
}