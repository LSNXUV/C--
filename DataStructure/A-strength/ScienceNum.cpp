
#include <stdio.h>
#include <string.h>
#include <math.h>
 
//当底数为正数(无'+')时
double dpos(char d[])
{
	int i=0,j,k,x;
	double s=0;
	while(d[i]!='.')
	{
		i++;
	}
	k=i-1;
	for(j=0;j<i;j++)
	{
		s+=(d[j]-'0')*pow(10,k);
		k--;
	}
	x=-1;
	for(j=i+1;d[j]!='\0';j++)
	{
		s+=(d[j]-'0')*pow(10,x);
		x--;
	}
	return s;
 
}

//当底数为正数(有'+')时
double dpos2(char d[])
{
	char x[100];
	int i=0,j=0;
	double s;
	for(i=1;d[i]!='\0';i++)
	{
		x[j]=d[i];
		j++;
	}
	x[j]='\0';
	s=dpos(x);
	return s;
}
 
//当底数为负数时
double dneg(char d[])
{
	char x[100];
	int i=0,j=0;
	double s;
	for(i=1;d[i]!='\0';i++)
	{
		x[j]=d[i];
		j++;
	}
	x[j]='\0';
	s=dpos(x);
	return -s;
}
 
//当指数为正数(无'+')时
int wpos(char w[],int l)
{
	int k,i,s=0;
	k=l-1;
	for(i=0;w[i]!='\0';i++)
	{
		s+=(w[i]-'0')*pow(10,k);
		k--;
	}
	return s;
}
 
//当指数为正数(有'+')时
int wpos2(char w[],int l)
{
	char x[100];
	int i=0,j=0,s=0;
	for(i=1;w[i]!='\0';i++)
	{
		x[j]=w[i];
		j++;
	}
	x[j]='\0';
	s=wpos(x,l-1);
	return s;
}
 
//当指数为负数时
int wneg(char w[],int l)
{
	char x[100];
	int i=0,j=0,s=0;
	for(i=1;w[i]!='\0';i++)
	{
		x[j]=w[i];
		j++;
	}
	x[j]='\0';
	s=wpos(x,l-1);
	return -s;
}
 
int main()
{
	char m[100],d[100],w[100];
	int i,j,k,y,z,flag=0;
	double s,x;

	scanf("%s",m);
	
	for(i=0;m[i]!='e';i++)
	{
		d[i]=m[i];
	}
	d[i]='\0';
	
	k=0;
	for(j=i+1;m[j]!='\0';j++)
	{
		w[k]=m[j];
		k++;
	}
	w[k]='\0';
	
	//检查底数是否是整数
	for(z=0;d[z]!='\0';z++)
	{
		if(d[z]=='.')
		{
			flag=1;
			break;
		}
	}
	if(flag){
		if(d[0]=='-')
		{
			s=dneg(d);
			if(w[0]=='-')
			{
				y=wneg(w,k);
			}
			else if(w[0]=='+')
			{
				y=wpos2(w,k);
			}
			else
			{
				y=wpos(w,k);
			}
		}
		else if(d[0]=='+')
		{
			s=dpos2(d);
			if(w[0]=='-')
			{
				y=wneg(w,k);
			}
			else if(w[0]=='+')
			{
				y=wpos2(w,k);
			}
			else
			{
				y=wpos(w,k);
			}
		}
		else
		{
			s=dpos(d);
			if(w[0]=='-')
			{
				y=wneg(w,k);
			}
			else if(w[0]=='+')
			{
				y=wpos2(w,k);
			}
			else
			{
				y=wpos(w,k);
			}
		}
	}
	else
	{
		if(d[0]=='-')
		{
			s=wneg(d,i);
			if(w[0]=='-')
			{
				y=wneg(w,k);
			}
			else if(w[0]=='+')
			{
				y=wpos2(w,k);
			}
			else
			{
				y=wpos(w,k);
			}
		}
		else if(d[0]=='+')
		{
			s=wpos2(d,i);
			if(w[0]=='-')
			{
				y=wneg(w,k);
			}
			else if(w[0]=='+')
			{
				y=wpos2(w,k);
			}
			else
			{
				y=wpos(w,k);
			}
		}
		else
		{
			s=wpos(d,i);
			if(w[0]=='-')
			{
				y=wneg(w,k);
			}
			else if(w[0]=='+')
			{
				y=wpos2(w,k);
			}
			else
			{
				y=wpos(w,k);
			}
		}
	}
	x=s*pow(10,y);
	printf("%f",x);
	scanf("%d",&s);
    return 0;
}