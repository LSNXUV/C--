#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct DBTree
{
    int data;
    struct DBTree *lchild;
    struct DBTree *rchild;
}DBTree;


//根据中序遍历和后序遍历构建二叉树
DBTree* CreateBiTree(char *instr, char *afterstr, int length)
{
    if (length == 0)//都构建完毕
    {
        return NULL;
    }
    char c = afterstr[length - 1];//树的根为后序遍历最后一个字符
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
    T->lchild = CreateBiTree(&instr[0], &afterstr[0], leftlength);//创建左子树
    T->rchild = CreateBiTree(&instr[i + 1], &afterstr[i], rightlength);//创建右子树
    
    return T;

}

//前序遍历输出
void PreOrderTraverse(DBTree *T)
{
    if (T)
    {
        printf("%c", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
int main()
{
    char instr[MAXSIZE];
    char afterstr[MAXSIZE];
    scanf("%s", instr);
    scanf("%s", afterstr);
    int length = strlen(instr);//结点的数目无论前，中，后序遍历都是相同的
    DBTree *T;
    T = (DBTree*)malloc(sizeof(DBTree));
    T = CreateBiTree(instr, afterstr, length);
    PreOrderTraverse(T);
        // scanf("%d",length);
    return 0;
}