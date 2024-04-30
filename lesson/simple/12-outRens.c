#include<stdio.h>
#define N 100

int main()
{
	int group[N];
	int totalNum = 0, restNum = 0, count = 0, roundcount = 0,i,round; 

	scanf("%d %d", &totalNum, &round);

	//排号操作
	for (i = 0; i < totalNum; i++)
	{
		group[i] = i + 1;
	}
	
	restNum = totalNum;

	//只要不只剩下一个人,那么就重复报数
	while (restNum>1)
	{
		roundcount = 0;
		//遍历整个数组,重复报数,直到一轮结束
		while (roundcount < totalNum)
		{
			if (group[roundcount]!=0)
			{
				count++;
				//报到3重头报数
				if (count == round)
				{
					group[roundcount] = 0;//退出的人以0为标识
					restNum--;
					count = 0;
				}				
			}
			roundcount++;
		}
	}

	for (i = 0; i < totalNum; i++)
	{
		if (group[i]!=0)
		{
			printf("%d", group[i]);
			break;
		}
	}
    printf("\n");
    return 0;
}
