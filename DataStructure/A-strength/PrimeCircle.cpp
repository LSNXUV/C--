#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int A[45]={0},B[21]={0},vis[21]={0};


void isp()         //筛选出素数
{
    int i,j;
    for(int i=2;i<45;i++)
    {
        A[i]=i;
    }
    for(i=2; i*i<45; i++)
    {
        if (A[i] != 0)
		for (j=i*2; j<45; j+=i)
		{
			A[j] = 0;
		}
    }
}
//回溯法——按照深度优先的顺序遍历解答树
void dfs(int cur)
{
    int i,j;
    if (cur > 0 && B[0]!=1)  //不是1开头返回
	{
		return ;
	}
	for (j=2; j<=cur; j++)
	{
		if (!A[B[j-2]+B[j-1]]) //两素数之和不是素数返回
		{
			return ;
		}
	}
	if (cur == n)
	{
		if (A[B[0] + B[cur-1]]) //首尾之和也必须是素数
		{
			for (j=0; j<n; j++)
			{
				cout<<B[j]<<" ";
			}
			cout<<endl;
			return ;
		}
	}
	for (i=1; i<=n; i++)
	{
		if (!vis[i])
		{
			B[cur] = i;
			vis[i] = 1;
			dfs(cur+1); //列举第二个数
			vis[i] = 0;
		}
	}
}
int main()
{
    isp();
	int T=0;
	while (cin>>n)
	{
		if (n==0)
			break;
		T++;
		memset(vis,0,sizeof(vis));
		if (n==1)
		{
			cout<<1<<endl;
		}
		else if (n%2==0)
		{
			dfs(0);
		}
		else
		{
			cout<<"No Answer"<<endl;
		}
	}
	return 0;
 }