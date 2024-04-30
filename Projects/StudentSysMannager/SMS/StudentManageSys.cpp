#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef struct Node{
	int id;//ѧ�� 
	char name[50];//���� 
	char sex[10];//�Ա� 
	int ma,en,et,pc;//��Ӣ��� 
	int sum;//�ܷ� 
	int avr;
	
	struct Node *next;//ָ���� 
}node;


node List;//���� 


//����Ϊ��������

//��ȡ�ļ� 
int readFile(node *L);

//�����ļ�
int saveFile(node *L);

// ���˵�����
void welcome();
//����ѧ����Ϣ

void printAddStuInfo();//���� 
void insertStuInfo(node *L,node e);//���� 

//ɾ��ѧ����Ϣ
//���� 
void printDeleteStuInfo(node *L);
//�߼����� 
void deleteStuInfo(node *pr);

//�޸�ѧ����Ϣ
void printFixStuInfo(node 
*L);



//��ѯѧ����Ϣ
void printSearchStuInfo(node *L);
//��ѧ�Ž��в��� 
node * searchStuInfoById(int id,node *L);
//���������в��� 
node * searchStuInfoByName(char name[],node *L);

//���ѧ����Ϣ
void printStuInfo(node *L);

//�˳�����
void goodBye();


int main(){
	int choice=0;
	readFile(&List);
	while(true){
		welcome();
		scanf("%d",&choice);
		switch(choice){
			case 1://����ѧ����Ϣ 
				printAddStuInfo(); 
				break;
			case 2://ɾ��ѧ����Ϣ
				printDeleteStuInfo(&List);
				break;
			case 3://�޸�ѧ����Ϣ 
				printFixStuInfo(&List);
				break;
			case 4://��ѯѧ����Ϣ
				printSearchStuInfo(&List);
				break;
			case 5://���ѧ����Ϣ
				printStuInfo(&List);
				break;
			case 0://�˳����� 
				goodBye();
				break;
		}
		printf("�Ƿ���Ҫ����������(yes:1 / no:0 ):");
		scanf("%d",&choice);
		if(choice==0){
			break;
		}
	}
	
	return 0;
}

//���˵����� 
void welcome(){
	system("cls");
	printf("��������������������������������������������������������������������������������\n");
	printf("��������������������  ��   ѧ �� �� �� �� �� ϵ  ͳ     ��  ��������������������\n");
	printf("��������������������         ��������         �������������������\n");
	printf("��������������������         ��������         �������������������\n");
	printf("��������������������  ��          1.����ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          2.ɾ��ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          3.�޸�ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          4.��ѯѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          5.���ѧ����Ϣ        ��  �������������������\n");
	printf("��������������������  ��          0.�˳�����ϵͳ        ��  �������������������\n");
	
	printf("�������Ӧ�Ĺ��ܼ�(����): ");
	
}

//����ѧ����Ϣ
void printAddStuInfo(){
	// 
	system("cls");
	node st;
	printf("����������ѧ�������Ϣ\n");
	printf("ѧ��:");
	scanf("%d",&st.id);
	printf("����:");
	scanf("%s",st.name);
	printf("�Ա�:");
	scanf("%s",st.sex);
	printf("��ѧ:");
	scanf("%d",&st.ma);
	printf("Ӣ��:");
	scanf("%d",&st.en);
	printf("����:");
	scanf("%d",&st.et);
	printf("�����:");
	scanf("%d",&st.pc);
	st.sum=st.ma+st.en+st.et+st.pc;
	st.avr=(st.sum)/4;
	
	insertStuInfo(&List,st);
	 
}
//����ѧ����Ϣ 
void insertStuInfo(node *L,node e){
	
	//ͷ�巨
	node *h=L;
	node *s=(node *)malloc(sizeof(node));
	*s=e;
	
	s->next=h->next;
	h->next=s;
	
	//�����ļ� 
	saveFile(L);
}


//ɾ��ѧ����Ϣ
void printDeleteStuInfo(node *L){
	system("cls");
	int id;
	
	node *p;
	
	printf("������Ҫɾ����ѧ��ѧ��");
	scanf("%d",&id);
	node *st=searchStuInfoById(id,L);
	p=st;
	
	if(st==NULL){
		printf("���޴��ˣ�");
		return;
	}
	
	st=st->next; 
	printf("________________________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
	printf("________________________________________________________________________\n");
	
	deleteStuInfo(p);
	saveFile(L);	
 	
}
void deleteStuInfo(node *pr){
	node *s=pr->next;
	
	pr->next=s->next;
	s->next=NULL;
	
	free(s);//�ͷŽ��ռ� 
	
}


//�޸�ѧ����Ϣ
void printFixStuInfo(node *L){
	system("cls");
	int id;
	int choice=-1;
	
	printf("������Ҫ���ҵ�ѧ��ѧ��");
	scanf("%d",&id);
	node *st=searchStuInfoById(id,L);
	
	if(st==NULL){
		printf("���޴��ˣ�");
		return;
	}	
	st=st->next;

	while(1){
		system("cls"); 
		printf("________________________________________________________________________\n");
	 	printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
		printf("________________________________________________________________________\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
		printf("________________________________________________________________________\n");
		printf("�޸�����---- 1\n");
		printf("�޸��Ա�---- 2\n");
		printf("�޸���ѧ---- 3\n");
		printf("�޸�Ӣ��---- 4\n");
		printf("�޸�����---- 5\n");
		printf("�޸ļ����---- 6\n");

		
		printf("������Ҫ�޸ĵ���Ϣ: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("������������");
				scanf("%s",st->name);
				break;
			case 2:
				printf("�������Ա�");
				scanf("%s",st->sex);
				break;
			case 3:
				printf("��������ѧ��");
				scanf("%d",&st->ma);				
				break;
			case 4:
				printf("������Ӣ�");
				scanf("%d",&st->en);				
				break;
			case 5:
				printf("������������");
				scanf("%d",&st->et);				
				break;
			case 6:
				printf("������������");
				scanf("%d",&st->pc);				
				break;
		}
		st->sum=st->ma+st->en+st->et+st->pc; 
		st->avr=st->sum/4;
		printf("�Ƿ�����޸�ѧ����Ϣ?��y-1 / n-0��\n");
		scanf("%d",&choice);
		if(choice == 0){
			break;
		}
	}
	
	printf("________________________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
	printf("________________________________________________________________________\n");
	printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
	printf("________________________________________________________________________\n");
	
	
	saveFile(L);
}
//ͳ��ѧ������
int countRens(node *L){
	if (!L)
    return 0;
  int n = 0;
  for (node *p = L->next; p->next != NULL; p = p->next)
  {
    n++;
  }
  return n;
}
//����ѧ����Ϣ
void SortStuInfoBySum(node *head){
	node *pre,*cur,*next,*end;//preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	end = NULL;
	while(head->next!=end)
	{
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
		{
			if(/* !(next->age) && */ cur->sum < next->sum) //�Ӵ�С
			{
				pre->next=next;
				cur->next=next->next;
				next->next=cur;

				//��ʱnext��ǰһ�cur���һ��  ����next cur
				node *temp=cur; cur=next; next=temp;
			}
		}
		//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
		end = cur;
	}
}
void SortStuInfoByNum(node *head){
	node *pre,*cur,*next,*end;//preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	end = NULL;
	while(head->next!=end)
	{
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for(pre=head,cur=pre->next,next=cur->next;  next!=end;  pre=pre->next,cur=cur->next,next=next->next)
		{
			if(/* !(next->age) && */ cur->id > next->id) //�Ӵ�С
			{
				pre->next=next;
				cur->next=next->next;
				next->next=cur;

				//��ʱnext��ǰһ�cur���һ��  ����next cur
				node *temp=cur; cur=next; next=temp;
			}
		}
		//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
		end = cur;
	}
}

//��ѯѧ����Ϣ
void printSearchStuInfo(node *L){
	
	system("cls");//������

	int choice=0;
	int id;
	char name[50];
	node *st;
	printf("��ѧ�Ų�ѯ----- 1\n");
	printf("��������ѯ----- 2\n");
	printf("�������ѯ��ʽ��");
	scanf("%d",&choice);
	
	//ѡ���Ӧ��ѯ��ʽ
	if(choice == 1){
		printf("������Ҫ��ѯ��ѧ�ţ�");
		scanf("%d",&id);
		st=searchStuInfoById(id,L);
		
		if(st==NULL){
			printf("���޴��ˣ�\n");
		}else{
			st=st->next;
			printf("________________________________________________________________________\n");
	 		printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
			printf("________________________________________________________________________\n");
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
			printf("________________________________________________________________________\n");
		}
	}else if(choice ==2){
		printf("������Ҫ��ѯ��������");
			scanf("%s",name);
			st=searchStuInfoByName(name,L);
			
			if(st==NULL){
				printf("���޴��ˣ�\n");
			}else{
				st=st->next;
				printf("________________________________________________________________________\n");
	 			printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
				printf("________________________________________________________________________\n");
				printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->en,st->et,st->pc,st->avr,st->sum);
				printf("________________________________________________________________________\n");
			}
	}
	
}
//��ѧ�Ž��в��� 
node * searchStuInfoById(int id,node *L){
	
	node *p=L;
	
	while(p->next!=NULL){
		
		if(p->next->id==id){
			return p;
		}
		
		p=p->next;
	}
	
	return NULL;
}
//���������в��� 
node * searchStuInfoByName(char name[],node *L){
	node *p=L;
	
	while(p->next!=NULL){
		
		if(strcmp(name,p->next->name)==0){
			return p;
		}
		
		p=p->next;
	}
	
	return NULL;
}


//���ѧ����Ϣ
void printStuInfo(node *L){
	 system("cls");
	 int i;
	 printf("��Ϣ��ȡ��ʽѡ��:\n1:Ĭ�ϰ��ɼ�����\n2:��ѧ������\n������鿴�ķ�ʽ(1/2):\n");
	 scanf("%d",&i);
	 if(i==2){
		 SortStuInfoByNum(L);
	 };
	 if(i==1){
		 SortStuInfoBySum(L);
	 };
	 node *p=L->next;
	 printf("________________________________________________________________________\n");
	 printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|\n");
	 printf("________________________________________________________________________\n");
	 if(p!=NULL){
	 	
	 	while(p!=NULL){
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",p->id,p->name,p->sex,p->ma,p->en,p->et,p->pc,p->avr,p->sum);
	 		printf("________________________________________________________________________\n");
			p=p->next;
		}
	 }
}

//�˳�����
void goodBye(){
	system("cls");
	printf("��ӭ�´�ʹ��~\n");
	return ;
}

// �ļ�����
int readFile(node *L){
	FILE *fpr=fopen("studentInfo.txt","r");
	node st;
	node *s;
	node *t=L;
	 
	if(fpr==NULL){
		return 0;
	}else{
		//fcanf()
		
		while(fscanf(fpr,"%d %s %s %d %d %d %d %d %d",&st.id,st.name,st.sex,&st.ma,&st.en,&st.et,&st.pc,&st.avr,&st.sum)!=EOF){
			
			s=(node *)malloc(sizeof(node));
			
			*s=st;
			
			t->next=s;
			t=s;
			t->next=NULL;
	
		}
	}
	fclose(fpr);//�ر��ļ�ָ�� 
	return 1;
}

//�����ļ�
int saveFile(node *L){
	SortStuInfoBySum(L);
	FILE *fpw=fopen("studentInfo.txt","w");
	if(fpw==NULL) return 0; 
	
	
	node *p=L->next;
	
	while(p!=NULL){
		
		fprintf(fpw,"%d %s %s %d %d %d %d %d %d\n",p->id,p->name,p->sex,p->ma,p->en,p->et,p->pc,p->avr,p->sum);
		p=p->next;
	}
	fclose(fpw);//�ر��ļ�ָ��
	return 1; 
}

