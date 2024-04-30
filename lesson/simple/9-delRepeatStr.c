#include <stdio.h>
#include <string.h>



int main(){
    //删除char数组中重复的字符,并排序
    char str[100];
    scanf("%s",str);
    int i,j,k;
    for(i=0;i<strlen(str);i++){
        for(j=i+1;j<strlen(str);j++){
            if(str[i]==str[j]){
                for(k=j;k<strlen(str);k++){
                    str[k]=str[k+1];
                }
                j--;
            }
        }
    }
    
    //排序
    for(i=0;i<strlen(str)-1;i++){
        for(j=i+1;j<strlen(str);j++){
            if(str[i]>str[j]){
                char temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
    for(i=0;i<strlen(str);i++){
            printf("%c",str[i]);
        }

    return 0;
}
