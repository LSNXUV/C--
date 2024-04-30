#include <stdio.h>
#include <string.h>
#define maxsize 100
char a[maxsize];
char b[maxsize];
char delta[maxsize];
int a_num,b_num,d_num;

int i,j,k,len;
char c;
int flag=1;

void reverse(char s[]){
    int len = strlen(s);
    for(i=0,j=len-1;i<j;i++,j--){
       c=s[i];
       s[i]=s[j];
       s[j]=c;
    }
}

void deletechar(char s[],char c){       
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++){
        if(s[i]!=c)
            s[j++]=s[i];
    }
    s[j]='\0';
}

void substract(char a[],char b[]){
    for(i=0;i<len;i++){
        a_num=a[i]-'0';
        b_num=b[i]-'0';
        if(a_num>=b_num)
            delta[i]='0'+a_num-b_num;
        else{
            delta[i]='0'+10+a_num-b_num;
            if(i!=len-1)
                a[i+1]=a[i+1]-1;
        }
    }
}


int main()
{
    gets(a);
    gets(b);
    deletechar(a,' ');
    deletechar(b,' ');
    reverse(a);
    reverse(b);
    int len_a=strlen(a);
    int len_b=strlen(b);
    if(len_a>len_b){
        for(i=len_b;i<len_a;i++)
            b[i]='0';
    }
    else{
        for(i=len_a;i<len_b;i++)
            a[i]='0';
        if(len_b>len_a)
            flag=-1;
        else{
            for(i=0;i<len_a;i++){
                if(a[i]<b[i]){
                    flag=-1;
                    break;
                }
            }
        }
    }
    len=len_a>len_b?len_a:len_b;
    if(flag==-1)
        substract(b,a);
    else
        substract(a,b);
    reverse(delta);
    if(flag==-1)
        printf("-");
    for(i=0;i<len&&delta[i]=='0';i++);
    if(i==len)
        printf("0\n");
    else{
        for(;i<len;i++)
            printf("%c",delta[i]);
    }
}