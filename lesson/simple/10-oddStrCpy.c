#include <stdio.h>
#include <string.h>



int main(){
    //复制奇数位置的字符串
    char a[100],b[100];
    int i;
    scanf("%[^\n]",a);
    for(i=0;i<strlen(a);i++)
    {
        if(i%2==0)
        {
            b[i]=a[i];
        }
    }
    for(i=0;i<strlen(a);i++)
    {
        printf("%c",b[i]);
    }
    // printf("%s",b);
    scanf("%d",&i);

return 0;
}