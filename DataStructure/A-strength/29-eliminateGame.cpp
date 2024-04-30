#include <iostream>
using namespace std;

#define MaxSize 100

int main(){
    int chess[MaxSize][MaxSize];
    int Chess[MaxSize][MaxSize];
    int m,n;
    
    cin>>n>>m;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>chess[i][j];
            Chess[i][j] = chess[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
	{
		for(int j=1;j<m-1;j++)
		{
			if(chess[i][j]==chess[i][j-1]&&chess[i][j+1]==chess[i][j])
			{
				Chess[i][j-1]=0;
				Chess[i][j]=0;
				Chess[i][j+1]=0;
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		for(int i=1;i<n-1;i++)
		{
			if(chess[i-1][j]==chess[i][j]&&chess[i+1][j]==chess[i][j])
			{
				Chess[i-1][j]=0;
				Chess[i][j]=0;
				Chess[i+1][j]=0;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		    cout<<Chess[i][j]<<" ";
        cout<<endl;
	}


    system("pause");
    return 0;
}