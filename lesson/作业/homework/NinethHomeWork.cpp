#include <iostream>
#include <cstring>
using namespace std;


int strcompare(const char *cs, const char *ct)
{
	unsigned char c1, c2;
 
	while (1) {
		c1 = *cs++;
		c2 = *ct++;
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
		if (!c1)
			break;
	}
	return 0;
}




void outone(){
    char str1[20],str2[20];
    char *cs = str1;
    char *ct = str2;
    cout<<"一、指针与字符"<<endl;
    cout<<"请输入两个字符串:"<<endl;
    cin>>str1>>str2;
    cout<<(strcompare(cs,ct)==1 ? "1" : strcompare(cs,ct)==-1 ? "-1" : "0")<<endl;
}
void SelectSort(char c[][20],int n){
    char t[20];
    int g = 1;
	for(int i=0; i<n-1; i++)
	{
		int k=i;
		for(int j=i+1; j<n; j++){
			if(strcmp(c[k],c[j]) > 0)
				k=j;
		if(k!=i)
		{
			strcpy(t,c[i]);
			strcpy(c[i],c[k]);
			strcpy(c[k],t);
		}
        
        cout<<"第"<<g++<<"次排序"<<endl;
        for(int k = 0;k < n;k++){
            cout<<c[k]<<" ";
        }
        cout<<endl;}
	}
}
typedef struct{
    int num;
    char name[20];
    int age;
} stu;
void SortStuByName(stu *stp,int rens){
    stu t;
    
	for(int i=0; i<rens-1; i++)
	{
		int k=i;
		for(int j=i+1; j<rens; j++){
			if(strcmp(stp[k].name,stp[j].name) > 0)
				k=j;
		if(k!=i)
            {
                t = stp[i];
                stp[i] = stp[k];
                stp[k] = t;
            }
        }
    }
    cout<<"按名字排序:"<<endl;
    for(int f = 0;f < rens;f++){
        cout<<stp[f].num<<"  "<<stp[f].name<<"  "<<stp[f].age<<endl;
    }
}
void SortStuByAge(stu *stp,int rens){
    stu t;
	for(int i=0; i<rens-1; i++)
	{
		int k=i;
		for(int j=i+1; j<rens; j++){
			if(stp[k].age > stp[j].age)
				k=j;
		if(k!=i)
            {
                t = stp[i];
                stp[i] = stp[k];
                stp[k] = t;
            }
        }
        cout<<"按年龄排序:"<<endl;
        for(int i = 0;i < rens;i++){
            cout<<stp[i].num<<"  "<<stp[i].name<<"  "<<stp[i].age<<endl;
        };
    }
}
void outtwo(){
    cout<<"二、排序算法（直接插入排序、简单选择排序和冒泡排序）"<<endl<<"(1)"<<endl;
    char city[20][20];
    char (*cp)[20] = city;
    int n,rens;
    cout<<"请输入要输入的城市数:"<<endl;
    cin>>n;
    for(int i = 0;i < n;i++){
        cout<<"请输入第"<<i+1<<"个城市名称"<<endl;
        cin>>city[i];
    }
    SelectSort(cp,n);
    cout<<"(2)";
    cout<<"请输入学生人数:"<<endl;
    cin>>rens;
    stu *stp = (stu *)malloc(sizeof(stu)*5);
    for(int i = 0;i < rens;i++){
        cout<<"请分别输入第"<<i+1<<"个人的学号、姓名、年龄"<<endl;
        cin>>stp[i].num>>stp[i].name>>stp[i].age;
    }
    SortStuByName(stp,rens);
    SortStuByAge(stp,rens);
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

void outthree(){
    cout<<"三、指针与函数"<<endl<<"(1)"<<endl;
    int a,b;
    cout<<"请输入两个数:"<<endl;
    cin>>a>>b;
    for(int i = a;i<=b;i++){
        // cout<<i;
        InvertSequence(i);
    }
    cout<<"(2)"<<endl;
    int q,w;
    cout<<"请输入两个两位正整数:"<<endl;
    cin>>q>>w;
    cout<<1000*(q%10)+100*(w%10)+10*(q/10)+w/10<<endl;
}
typedef struct Chr 
{
    char ch;
    struct Chr *next;
}Chr;
typedef struct Stu
{
    int age;
    char name[10];
    struct Stu *next;
}Stu,*List;
Stu S;
void Sort(Stu *L,int n){
    if(!L || !L->next) return;

    Stu *p,*p1,*pre,*head;
    // pre = L;
        for(int i = 0; i < n; ++i){
            head = L->next;
            
            for(int j = 0; j < n-i-1; ++j){
                p = head;
                p1 = head->next;
                if(p->age > p1->age){
                    swap(p->age,p1->age);
                    swap(p->name,p->name);
                    /* pre->next = p1;
                    p->next = p1->next;
                    p1->next = p; */
                   
                }
                head = head->next;
                // pre = pre->next;
                
            } 
    }
    // Stu *pre,*cur,*next,*end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	// end = NULL;

	// while(head->next!=end)
	// {
	// 	//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
	// 	for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
	// 	{
	// 		if(/* !(next->age) && */ cur->age > next->age) //从小到大
	// 		{
	// 			pre->next=next;
	// 			cur->next=next->next;
	// 			next->next=cur;

	// 			//此时next变前一项，cur变后一项  交换next cur
	// 			Stu *temp=cur; cur=next; next=temp;
	// 		}
	// 	}
	// 	//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
	// 	end = cur;
	// }
}
void outStu(Stu *L,int n){
    
    Stu *pre,*p;
    pre = L->next;
    cout<<"当前信息:"<<endl;
    /* if(pre!=NULL){
        while(pre!=NULL){
            cout<<"年龄:"<<pre->age<<"\t姓名:"<<pre->name<<endl;
            pre = pre->next;
        }
    } */
    for (int i = 0; i < n; i++)
    {
        cout<<"年龄:"<<pre->age<<"\t姓名:"<<pre->name<<endl;
        pre = pre->next;
    }
    
}


void deleteStu(int age,Stu *head,int n){
    Stu *pre = head,*pr = head;
    
    if(head==NULL){
        cout<<"链表为空!"<<endl;
    }
    while(pre->next!=NULL && pre->age!=age){
        pr = pre;
        pre = pre->next;
    }
    if(pre->age==age){
        if(pre==head){
            head=pre->next;
        }
        pr->next = pre ->next;

        free(pre);
    }

    outStu(head,n-1);
}

void creatlist(Stu *S){
    int age,n;
    char name[10];
    Stu *p,*r;
    S = (Stu *)malloc(sizeof(Stu));
    S->next = NULL;
    r = S;
    cout<<"请输入要输入的学生数:"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        p = (Stu *)malloc(sizeof(Stu));
        cout<<"请输入第"<<i+1<<"个学生的年龄和姓名:"<<endl;
        cin>>age>>name;
        p->age = age;
        strcpy(p->name,name);
        r->next = p;
        r = r->next;
    }
    Sort(S,n);
    outStu(S,n);
    int a;
    cout<<"请输入要删除的年龄:"<<endl;
    cin>>a;
    // cout<<a;
    deleteStu(a,S,n);
    

}

Chr *CreatList(int n){
    char x;
    Chr *L,*r,*p;
    L = (Chr *)malloc(sizeof(Chr));
    L->next = NULL;
    r = L;
    for(int i = 0;i<n;i++){
        cin>>x;
        p = (Chr *)malloc(sizeof(Chr));
        p->ch = x;
        p->next = NULL;
        r->next = p;
        r = r->next;
    }
    return L;

}
int funchr(Chr *L,char ch){
    int i = 1;
    Chr *p,*q,*r;
    if(L->next == NULL){
        cout<<"链表为空"<<endl;
        
    }
    else{
        p = L->next;
        while (p != NULL)
        {
            if(p->ch!=ch){
                i++;
                p = p->next;
            }
            else
                break;
        }

    }
    return i;
}
void outfour(){
    int n;
    Chr *L;
    char chr[20],ch;
    cout<<"四、链表"<<endl<<"(1)"<<endl;
    cout<<"请输入要输入的字符串长度:"<<endl;
    cin>>n;
    cout<<"请输入字符串:"<<endl;
    L = CreatList(n);
    cout<<"请输入查找的字符:"<<endl;
    cin>>ch;
    cout<<"位置为:"<<funchr(L,ch)<<endl;

    cout<<"(2)"<<endl;
    Stu *S;
    creatlist(S);


}



int main(){
    outone();
    outtwo();
    outthree();
    outfour();
    system("pause");
    return 0;
}