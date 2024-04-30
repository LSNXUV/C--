#include<iostream>
using namespace std;
#define Max 30
void SpiralMatrix(int n)
{
	int a[Max][Max];
	int x = 0,y = -1;              //x,y表示当前数组要赋值的位置 
	int x_add = 0, y_add = 1;      //每次赋值时,x和y的增量 
	int num = n,num_add = n;       //num:移动方向发生变化的转变点,num_add:每次转变时num的增量 
	for(int i=1;i<=n*n;i++)
	{
		x += x_add;
		y += y_add;
		a[x][y] = i;
		
		if(i == num)        //移动方向发生转变 
		{
			if(y_add == 1 || y_add == -1)         //横向变纵向 
			{
				x_add = y_add;
				y_add = 0;
				num += --num_add;
			}
			else                                  //纵向变横向 
			{
				y_add = -x_add;
				x_add = 0;
				num += num_add;
			}

		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
            if(a[i][j]<10)
            {
                cout<<"    "<<a[i][j];
            }else if(a[i][j]<100){
                cout<<"   "<<a[i][j];
            }else{
                cout<<"  "<<a[i][j];
            }
			
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	SpiralMatrix(n);
    system("pause");
}