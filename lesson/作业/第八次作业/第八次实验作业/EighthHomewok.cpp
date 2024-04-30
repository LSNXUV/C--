#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#include<vector>



void Outrepeat(){
    char repeat[30];
    char ch;
    cout<<"请输入字符串和要查找的字符:"<<endl;
    cin>>repeat>>ch;
    int j = 0;
    for(int i =1;i<strlen(repeat);i++){
        if(repeat[i]==ch){
            cout<<i<<"\t";
            j++;
        }
    }
    if(j==0){
        cout<<"NULL"<<endl;
    }cout<<endl<<j<<endl;
}

void InvertSequence(int num){
    int n = num;
    int result = 0;
	// 将整数倒序
	for (int i = num; i ; )
	{
		// 去掉个位上的数
		i = i/10*10;
		// 将result进一位，并加上当前个位上的数（num-i）
		result = result * 10 + num - i;
 
		i = i /10;
		num = num/10;
	}
    // cout<<result<<endl;
    // cout<<result<<" "<<num;
    if(result==n)
    cout<<result<<endl;
    
}
void outInvertSequence(){
    int a,b;
    cout<<"请输入两个数:"<<endl;
    cin>>a>>b;
    
    // cout<<InvertSequence(a);
    for(int i = a;i<=b;i++){
        // cout<<i;
        InvertSequence(i);
    }
}

void BinaryRecursion(int n,vector<int>&ans)
{
    int a;
    a = n%2;
    n = n>>1;
    if (n != 0)
        BinaryRecursion(n,ans);
    cout<<a;
    ans.push_back(a);
}

void quick_Sort(vector<int>& v, int left, int right){
	if(left >= right) return;
	int i = left, j = right, base = v[left];  //取最左边的数为基数
	while(i < j){
		while(v[j] >= base && i < j){
			j--;
		}
		while(v[i] <= base && i < j){
			i++;
		}
		if(i < j){
			swap(v[i], v[j]);
		}
	} 
	v[left] = v[i];
	v[i] = base;
	quick_Sort(v, left, i - 1);
	quick_Sort(v, i + 1, right);
}
void quickSort(vector<int>& v){
	int n = v.size();
	quick_Sort(v, 0, n - 1);
}

void SelectSort(int n,int a[]){
    int exchange;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[i]>a[j])
            {exchange=a[i];
            a[i]=a[j];
            a[j]=exchange;    
        }     
    }
    }
}
void outMergeArr(){
    // int a=7,b=5;
    int a,b;
    
    vector<int> herr;
    /* if(arr != NULL && brr != NULL)
    {
        cout << "c++创建动态数组成功" << endl;
    } */
    // int* hrr = (int *)malloc(a+b);
    cout<<"请分别输入两个数组的长度和内容(空格分隔):"<<endl;
    cin>>a;
    int *arr = new int[a];
    for(int i = 0;i<a;i++){
        cin>>arr[i];
    }
    cin>>b;
    int *brr = new int[b];
    for(int i = 0;i<b;i++){
        cin>>brr[i];
    }
    int *hrr = new int[a+b];
    /* for(int i = 0;i<a;i++){
        herr.push_back(arr[i]);
        
    }
    for(int j = a;j<a+b;j++){
        herr.push_back(brr[j-a]);
    } */
    for(int i = 0;i<a;i++){
        hrr[i] = arr[i];
        
    }
    for(int j = a;j<a+b;j++){
        hrr[j] = brr[j-a];
    }
   
    SelectSort(a+b,hrr);
    // cout<<herr[0];
    for(int i = 0;i<a+b;i++){
        cout<<herr[i]<<"#";
    }


}
int main(){
    int a;
    vector<int> ans;
    cout<<"一、查找算法（顺序查找和二分查找）"<<endl;
    cout<<"1-1"<<endl;
    // Outrepeat();
    cout<<"二、排序算法（直接插入排序、简单选择排序和冒泡排序）"<<endl<<"2-1"<<endl;
    outMergeArr();
    cout<<endl<<"三、指针与函数"<<endl;
    cout<<"3.1"<<endl;
    cout<<"请输入想要转换成二进制的十进制数:"<<endl;
    cin>>a;
    BinaryRecursion(a,ans);
    
    cout<<endl<<"3.2"<<endl;
    outInvertSequence();

    system("pause");
    return 0;
}