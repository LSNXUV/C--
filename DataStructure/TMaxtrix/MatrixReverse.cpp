#include <iostream>
using namespace std;

#define Max 200

typedef struct
{
	int i,j;
	int data;
} Triple;

typedef struct
{
	Triple data[Max];
	int mu,nu,tu;
} TMatrix;

void Create(TMatrix &M)
{
	M.tu = 0;
	M.mu = 4;
	M.nu = 4;
	int i,j,data;
	cout<<"input matrix a:"<<endl;
	for(i = 0;i<M.mu;i++){
		for(j = 0;j<M.nu;j++)
		{
			cin>>data;
			if(data == 0)
			{
				continue;
			}
			M.data[M.tu].i = i;
			M.data[M.tu].j = j;
			M.data[M.tu++].data = data;
		}
	}
}


TMatrix TransposeMatrix(TMatrix M)
{
	TMatrix TSM;
	Triple T;
	TSM.mu = 4;
	TSM.nu = 4;
	TSM.tu = M.tu;
	int i,j;
	for(i = 0;i<TSM.tu;i++)
	{
		TSM.data[i].i = M.data[i].j;
		TSM.data[i].j = M.data[i].i;
		TSM.data[i].data = M.data[i].data;
	}
	for(i = 0;i<TSM.tu;i++)
	{
		for(j = i+1;j<TSM.tu;j++)
		{
			if(TSM.data[i].i > TSM.data[j].i)
			{
				T = TSM.data[i];
				TSM.data[i] = TSM.data[j];
				TSM.data[j] = T;	
			} 
		}
	}
	return TSM; 
}


void DisPlay(TMatrix M)
{
	cout<<"   "<<M.mu<<"   "<<M.nu<<"   "<<M.tu<<endl;
	cout<<"------------"<<endl;
	for(int i = 0;i<M.tu;i++)
	{
		cout<<"   "<<M.data[i].i<<"   "<<M.data[i].j<<"   "<<M.data[i].data<<endl; 
	}
}


int main(){
	
	TMatrix M,TSM;
	Create(M);
	cout<<"The triple a:"<<endl;
	DisPlay(M);
	cout<<"a to b:"<<endl;
	cout<<"The triple b:"<<endl;
	TSM = TransposeMatrix(M);
	DisPlay(TSM);
	
	
	return 0;
}

