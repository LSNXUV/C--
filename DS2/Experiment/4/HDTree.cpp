#include <iostream>
#include <string>
using namespace std;

typedef struct 
{
    int weight;
    string num;
    string data;
    int parent,lchild,rchild;
} HDTree;


typedef struct
{
    int s1;
    int s2;
} MIN;

MIN Select(HDTree* HT,int n)
{
    int min = 10000,selectmin = 10000,s1 = 1,s2 = 1;
    MIN word;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && (HT[i].weight<min))
        {
            min = HT[i].weight;
            s1 = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && (HT[i].weight<selectmin) && (i != s1))
        {
            selectmin = HT[i].weight;
            s2 = i;
        }
    }
    word.s1 = s1;
    word.s2 = s2;
    return word;

};

//将哈夫曼码存储在结构体num中
void putlorinnum(HDTree* &HT, int num)
{
    for(int i = num; i >= 1; i--)
    {
        if(HT[HT[i].parent].parent)
        {
            HT[i].num = HT[HT[i].parent].num + HT[i].num;
        }
    }
}
//创造哈夫曼树
void CreateHuffmanTree(HDTree* &HT, int num)
{

    int m = 2 * num - 1;
    HT = new HDTree[m + 1];   //分配空间
    for (int i = 1; i <= m; i++)   //初始化
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    for (int i = 1; i <= num; i++)
    {
        cin>>HT[i].data;
    }

    for(int i = 1;i<=num;i++)
    {
        cin >> HT[i].weight;
    }

    for (int i = num + 1; i <= m; i++)  //构建哈夫曼树
    {
        MIN min;
        min=Select(HT,i-1);      //选择二叉树
        HT[min.s1].parent = i;
        HT[min.s2].parent = i;
        HT[i].lchild = min.s1;
        HT[min.s1].num = "0";
        HT[i].rchild = min.s2;
        HT[min.s2].num = "1";
        HT[i].weight = HT[min.s1].weight + HT[min.s2].weight;
        HT[i].data = "";
    }
    putlorinnum(HT, m);   

}
int numlen(int n)
{
    if(n<0)
    {
        return 2;
    }
    if(n==0) return 1;
    int l=0;
    while(n)
    {
        n/=10;
        l++;
    }
    return l;
}
int main(){
    int m;
    HDTree * HT;
    cin>>m;
    CreateHuffmanTree(HT,m);
    cout<<"    data    weight    parent    lchild    rchild\n";
    for(int i = 1;i<=2*m-1;i++)
    {
    
        for(int j = 0;j<(8-(int)HT[i].data.length());j++) cout<<" ";
        cout<<HT[i].data;
        for(int j = 0;j<(8-numlen(HT[i].weight));j++) cout<<" ";
        cout<<HT[i].weight;
        for(int j = 0;j<(10-numlen(HT[i].parent-1));j++) cout<<" ";
        cout<<HT[i].parent-1;
        for(int j = 0;j<(10-numlen(HT[i].lchild-1));j++) cout<<" ";
        cout<<HT[i].lchild-1;
        for(int j = 0;j<(10-numlen(HT[i].rchild-1));j++) cout<<" ";
        cout<<HT[i].rchild-1<<endl;

    }

    //进行每个字符哈夫曼码的输出
    cout<<"\n输出哈夫曼编码:\n";
    for (int i = 1; i <= m; i++) 
    {
        if(HT[i].data != "-1")
        {
            for(int j = 0;j<(5-(int)HT[i].data.length());j++) cout<<" ";
            cout<<HT[i].data<<":"<<HT[i].num<<endl;
        }
    }
    system("pause");
    return 0;
}