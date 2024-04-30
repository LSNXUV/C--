#include <stdio.h>
int main()
{
	int a[10][10], n, m, i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int row, col, s,flag=1,col1,s1,t=0;
	for (i = 0; i < n; i++)
	{
		s = a[i][0];
		row = i, col = 0;
		for (j = 1; j < m; j++)
		{
			if (a[i][j] > s)
			{
				s = a[i][j];
				col = j;
			}
		}
		for(j=0;j<m;j++)
		{
			if (a[i][j] == s&&j!=col)
			{
				s1 = a[i][j];
				col1 = j;
				t=1;
			}
		}
		for (k = 0; k < n; k++)
		{
			if (a[k][col] > s)
				flag=0;
			if(flag==0)
				break;
		}
		row++,col++;
		if(flag)
		printf("%d %d %d\n", s, row, col);
		flag=1;
		if(t)
		{
			for (k = 0; k < n; k++)
			{
				if (a[k][col1] > s1)
					flag=0;
			if(flag==0)
				break;
			}
			col1++;
			if(flag==1)
			printf("%d %d %d\n", s1, row, col1);
			t=0; 
		}
	}
	return 0;
}
