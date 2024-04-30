
#include <iostream>
#include <cstring>
using namespace std;
#define Max 100

typedef struct tree
{
    char data;
    struct tree *lchild,*rchild;
} DBTree;


//根据中序遍历和后序遍历构建二叉树
DBTree* CreateDBTreeByAft(char *instr, char *afterstr, int length)
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
    T->lchild = CreateDBTreeByAft(&instr[0], &afterstr[0], leftlength);//创建左子树
    T->rchild = CreateDBTreeByAft(&instr[i + 1], &afterstr[i], rightlength);//创建右子树
    
    return T;

}
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

//先序遍历
void PreOrder(DBTree *bt)
{
    if(bt)
    {
        cout<<bt->data;
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//中序遍历
void InOrder(DBTree *bt)
{
    if(bt)
    {
        InOrder(bt->lchild);
        cout<<bt->data;
        InOrder(bt->rchild);
    }
}

//后序遍历
void PostOrder(DBTree * bt)
{
    if(bt)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data;
    }
}

//层次遍历
void LevelOrder(DBTree *DT)
{
    DBTree *p;
    DBTree * qu[Max];
    int front,rear;
    front = rear = 0;
    rear++;qu[rear]=DT;
    while(front!=rear)
    {
        front = (front+1)%Max;
        p = qu[front];
        cout<<p->data;
        if(p->lchild)
        {
            rear = (rear+1)%Max;
            qu[rear]=p->lchild;
        }
        if(p->rchild)
        {
            rear = (rear+1)%Max;
            qu[rear]=p->rchild;
        }

    }

}

//打印主界面
void welcome()
{
    system("cls");
    cout<<endl;
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓  ☆      二 叉 树 遍 历 测 试      ☆  〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          1.先序遍历        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          2.中序遍历        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          3.后序遍历        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          4.层次遍历        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆          0.退出系统        ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓★  ☆                            ☆  ★〓〓〓〓〓〓〓〓〓\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");


}

int main(){
    int choice,len;
    DBTree * DT;
    char prestr[Max],instr[Max],aftstr[Max];
    welcome();
    cout<<"1.根据先序遍历和中序遍历构建二叉树。"<<endl;
    cout<<"2.根据后序遍历和中序遍历构建二叉树。"<<endl;
    cout<<"请输入想要构建二叉树的方式："<<endl;
    cin>>choice;
    if(choice==1){
        cout<<"请分别输入先序遍历和中序遍历(空格分隔):"<<endl;
        cin>>prestr>>instr;
        len = strlen(instr);
        DT = CreateDBTreeByPre(instr,prestr,len);
    }else{
        cout<<"请分别输入后序遍历和中序遍历(空格分隔):"<<endl;
        cin>>aftstr>>instr;
        len = strlen(instr);
        DT = CreateDBTreeByAft(instr,aftstr,len);
    }
    cout<<"构建成功！"<<endl;
    while(1){
        cout<<"请输入功能序号："<<endl;
        cin>>choice;
        switch (choice)
        {
        
        case 1:
            cout<<"先序遍历为:";
            PreOrder(DT);
            cout<<endl;
            continue;
        case 2:
            cout<<"中序遍历为:";
            InOrder(DT);
            cout<<endl;
            continue;
        case 3:
            cout<<"后序遍历为:";
            PostOrder(DT);
            cout<<endl;
            continue;
        case 4:
            cout<<"层次遍历为:";
            LevelOrder(DT);
            cout<<endl;
            continue;
        case 0:
            break;
        default:
            cout<<"先序遍历为:";
            PreOrder(DT);
            cout<<endl;
            continue;
        }
    }
    
    system("pause");
    return 0;
}