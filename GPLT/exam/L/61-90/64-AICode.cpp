#include<iostream>
#include<string>
using namespace std;
string a,b; //a��ԭ�ַ�����b���޸ĺ���ַ��� 

int ch(string s,int x) // �ж��ַ�����һ�� 
{
    if(s[x]>='a' && s[x]<='z') return 1;
    else if(s[x]>='A' && s[x]<='Z') return 2;
    else if(s[x]>='0' && s[x]<='9') return 3;
    else if(s[x]==' ') return 4;
    else return 5; // ���ո�����ı�����
}

int check(int x,int y) // �ж��Ƿ�����"�������ַ���" 
{
   if((x<0 || b[x]==' ' || ch(b,x)==5 ) && (y>=b.size() || b[y]==' ' || ch(b,y)==5))     
     return 1;
   return 0;
}

int main()
{
    int N;
    cin>>N;
    getchar();
    while(N--)
    {
        getline(cin,a);
        cout << a << endl << "AI: ";
        int l = 0,r = a.size() - 1;
        while(a[l]==' ') l++; // ȥ��ȫ���׿ո� 
        while(a[r]==' ') r--; // ȥ��ȫ��β�ո� 
        for(int i=l; i<=r; i++) // ��l~rѭ�����������൱��ȥ��ȫ����β�ո��� 
        {
            if(ch(a,i) == 2 && a[i] != 'I') // ��д��Сд 
               b+=a[i]+32; 
            else if(a[i] == '?')  // ?�䣡 
               b+='!';
            else if(a[i] == ' ' && (a[i+1] == ' '||ch(a,i+1) == 5)) // ȥ������ո񣨵��ʼ�Ŀո񡢱�����ǰ�Ŀո� 
               continue;
            else
               b+=a[i];   // �����ַ�
        }
        for(int i=0; i<b.size(); i++)
        {
            if(b[i]=='I' && check(i-1,i+1))
              cout<<"you";
            else if(b.substr(i,2) == "me" && check(i-1,i+2)) // b.substr(i,2)�����ȡb�ַ�����i�±꿪ʼ�������ַ� 
              cout<<"you", i++;
            else if(b.substr(i,7) == "can you" && check(i-1,i+7))    
              cout<<"I can", i+=6;
            else if(b.substr(i,9) == "could you" && check(i-1,i+9))
              cout<<"I could", i+=8;
            else
              cout<<b[i];    
        }
        cout<<endl;
        b=""; //��b����Ϊ���ַ��� 
    }    
} 
