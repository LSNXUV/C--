#include <iostream>
#include <string.h>
using namespace std;


int  Index(char  S[],char  T[],int  pos)//在主串S的起始位置pos处开始查找模式串T，存在返回相应位置，不存在返回0  
{
    unsigned int i = pos-1;
    unsigned int j = 0;
    while (i < strlen(S) && j < strlen(T)) {
		if (S[i] == T[j]) {//当对应字符相等时，比较后续字符
			i++;
			j++;
		}
		else {//当对应字符不相等时
			i = i - j + 1;//主串回溯到i-j+2的位置重新比较
			j = 0;//模式串从头开始重新比较
		}
	}
	if (j >= strlen(T)) {
        //匹配成功时，返回匹配起始位置
		return i - strlen(T)+1;
	}
	else {
        //匹配失败，返回0
		return -1;
	}

}

int main(){

    char s[200],t[200];
    int pos;
    cout<<"Please input the Main SString S:";
    cin>>s;
    cout<<"Please input the other SString T:";
    cin>>t;
    cout<<"the start position:";
    cin>>pos;
    cout<<endl;

    cout<<"the index result is:"<<endl;

    if(Index(s,t,pos) != -1){
        cout<<"The postion of T in the Main SString S from "
            <<pos<<"  chars on is: "<<Index(s,t,pos);
    }
    else{
        cout<<"Failure to Index the SString!";
    }
    system("pause");
    return 0;

    
}