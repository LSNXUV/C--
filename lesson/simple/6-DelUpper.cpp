#include <iostream>
#include <cstring>

using namespace std;



int main(){
//输出除去大写英文字母的剩余字符串，回车结束输入
    char ch;
    while(cin>>ch){
        //保留空格字符串
        if(!ch){
            cout<<" ";
        }
        //除去大写字母
        else if(ch>='A'&&ch<='Z'){
            continue;
        }
        else{
            cout<<ch;
        }
        
        
    }
    
   

    system("pause");
    return 0;
}
