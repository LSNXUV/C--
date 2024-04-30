#include <stdio.h>
#include <string.h>



int main(){
    //合并字符串
    char str1[100];
    char str2[100];
    scanf("%s",str1);
    scanf("%s",str2);
    int i,j;
    
    strcat(str1,str2);
    //排序
    for(i=0;i<strlen(str1)-1;i++){
        for(j=i+1;j<strlen(str1);j++){
            if(str1[i]>str1[j]){
                char temp=str1[i];
                str1[i]=str1[j];
                str1[j]=temp;
            }
        }
    }
    for(i=0;i<strlen(str1);i++){
            printf("%c",str1[i]);
        }


return 0;
}
