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
    cout<<"???????????"<<endl;
    cout<<"???????????????:"<<endl;
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
        
        cout<<"??"<<g++<<"??????"<<endl;
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
    cout<<"??????????:"<<endl;
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
        cout<<"??????????:"<<endl;
        for(int i = 0;i < rens;i++){
            cout<<stp[i].num<<"  "<<stp[i].name<<"  "<<stp[i].age<<endl;
        };
    }
}
void outtwo(){
    cout<<"??????????????????????????????????????"<<endl<<"(1)"<<endl;
    char city[20][20];
    char (*cp)[20] = city;
    int n,rens;
    cout<<"?????????????????:"<<endl;
    cin>>n;
    for(int i = 0;i < n;i++){
        cout<<"???????"<<i+1<<"??????????"<<endl;
        cin>>city[i];
    }
    SelectSort(cp,n);
    cout<<"(2)";
    cout<<"?????????????:"<<endl;
    cin>>rens;
    stu *stp = (stu *)malloc(sizeof(stu)*5);
    for(int i = 0;i < rens;i++){
        cout<<"?????????"<<i+1<<"???????????????????"<<endl;
        cin>>stp[i].num>>stp[i].name>>stp[i].age;
    }
    SortStuByName(stp,rens);
    SortStuByAge(stp,rens);
}


void InvertSequence(int num){
    int n = num;
    int result = 0;
	// ??????????
	for (int i = num; i ; )
	{
		// ?????¦Ë?????
		i = i/10*10;
		// ??result???¦Ë????????????¦Ë???????num-i??
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
    cout<<"???????????"<<endl<<"(1)"<<endl;
    int a,b;
    cout<<"????????????:"<<endl;
    cin>>a>>b;
    for(int i = a;i<=b;i++){
        // cout<<i;
        InvertSequence(i);
    }
    cout<<"(2)"<<endl;
    int q,w;
    cout<<"????????????¦Ë??????:"<<endl;
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
    // Stu *pre,*cur,*next,*end;//pre???? cur????? next????? end???????????(??????)
	// end = NULL;

	// while(head->next!=end)
	// {
	// 	//???????????? ; ?§Ø????????¦Ë?? ; ????????????
	// 	for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
	// 	{
	// 		if(/* !(next->age) && */ cur->age > next->age) //??§³????
	// 		{
	// 			pre->next=next;
	// 			cur->next=next->next;
	// 			next->next=cur;

	// 			//???next??????cur??????  ????next cur
	// 			Stu *temp=cur; cur=next; next=temp;
	// 		}
	// 	}
	// 	//?????????? ???????????? end?????? (??????)
	// 	end = cur;
	// }
}
void outStu(Stu *L,int n){
    
    Stu *pre,*p;
    pre = L->next;
    cout<<"??????:"<<endl;
    /* if(pre!=NULL){
        while(pre!=NULL){
            cout<<"????:"<<pre->age<<"\t????:"<<pre->name<<endl;
            pre = pre->next;
        }
    } */
    for (int i = 0; i < n; i++)
    {
        cout<<"????:"<<pre->age<<"\t????:"<<pre->name<<endl;
        pre = pre->next;
    }
    
}


void deleteStu(int age,Stu *head,int n){
    Stu *pre = head,*pr = head;
    
    if(head==NULL){
        cout<<"???????!"<<endl;
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
    cout<<"?????????????????:"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        p = (Stu *)malloc(sizeof(Stu));
        cout<<"???????"<<i+1<<"????????????????:"<<endl;
        cin>>age>>name;
        p->age = age;
        strcpy(p->name,name);
        r->next = p;
        r = r->next;
    }
    Sort(S,n);
    outStu(S,n);
    int a;
    cout<<"????????????????:"<<endl;
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
        cout<<"???????"<<endl;
        
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
    cout<<"???????"<<endl<<"(1)"<<endl;
    cout<<"?????????????????????:"<<endl;
    cin>>n;
    cout<<"???????????:"<<endl;
    L = CreatList(n);
    cout<<"?????????????:"<<endl;
    cin>>ch;
    cout<<"¦Ë???:"<<funchr(L,ch)<<endl;

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