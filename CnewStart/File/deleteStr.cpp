#include <iostream>
#include <cstring>
using namespace std;


char* del(char word[20],int m,int n){
    strcpy(word+m-1,word+m+n-1);
    return word;
}
int main(){
    int a,b;
    char word[20];
    cin>>word;
    cin>>a>>b;
    cout<<del(word,a,b)<<endl;
    system("pause");
    return 0;
}