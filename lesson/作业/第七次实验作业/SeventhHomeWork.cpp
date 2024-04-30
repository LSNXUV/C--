#include <iostream>
#include <stdio.h>

#include <malloc.h>
#include <cstring>

using namespace std;

bool prime(int n){
    return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
}
struct{ 
    int year;
    int month;
    int day;
}date;

void outdays(){
    int days = 0;
    cout<<"请输入年月日:";
    cin>>date.year>>date.month>>date.day;
    days+=date.day;
    int year1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<date.month-1;i++){
			days+=year1[i];
	}
    if(prime(date.year&&date.month>=3)){
        days++;
    }
    cout<<date.month<<"/"<<date.day<<" is the "<<days<<"th day in "<<date.year<<"."<<endl;
}

typedef struct inf{
    char name[10];
    char sex[10];
    int born;
}info;

struct inf *pr = (struct inf *)malloc(sizeof(struct inf)*5);

void outinf(){
    int w = 0;
    int r = 0;
    for(int i = 0;i<5;i++){
        cout<<"请输入第"<<i+1<<"个人的名字:";
        cin>>pr[i].name;
        cout<<"请输入第"<<i+1<<"个人的性别:";
        cin>>pr[i].sex;
        if(!strcmp(pr[i].sex,"女")){
            w+=1;
        }
        // cout<<strcmp(pr[i].sex,"女");
        cout<<"请输入第"<<i+1<<"个人的出生年:";
        cin>>pr[i].born;
        if(pr[i].born>=1990){
            r+=1;
        }
        
    }
    cout<<"女:"<<w<<endl;
    cout<<"90后:"<<r<<endl;
}
void infile(){
    int n;
    FILE *fp=fopen("666.txt","w");
	if(fp==NULL){
        cout<<"文件创建失败";
        return;
    };
    cout<<"请输入要输入数字的个数:"<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
        char num[5];
        cout<<"请输入第"<<i+1<<"个数字"<<endl;
        cin>>num;
        fprintf(fp,num);
        fprintf(fp," ");
    }
    fclose(fp);
    

}
void outfile(){
    char buff[255];
    FILE *fpr=fopen("666.txt","r");
    if(fpr==NULL){
        cout<<"文件读取失败";
        return;
    };
    fgets(buff,255,(FILE*)fpr);
    cout<<"文件内容为:"<<buff<<endl;
    // printf("%s\n",buff);
    fclose(fpr);
}

void outperfect(){
    int n;
    int arr[10];
    cout<<"请输入一个数:"<<endl;
	cin>>n;
    int j = 0;
	for(int i=1;i<=n;i++){
		int sum=0; //计数器：计算因子相加的和 
		for(int j=1;j<i;j++){ //计算真因子 
			if(i%j==0) sum+=j;
		}
		if(i==sum) arr[j++] = i; //判断、输出 
	}
    cout<<"最大完全数:"<<arr[j-1];
}

int main(){
    cout<<"一、结构体与指针"<<endl;
    outdays();
    outinf();
    cout<<"二、文件操作与C语言输入输出"<<endl;
    infile();
    outfile();
    cout<<"三、函数"<<endl;
    outperfect();
    system("pause");
    return 0;
}