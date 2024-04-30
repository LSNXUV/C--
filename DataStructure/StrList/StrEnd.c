#include <stdio.h>
#include <string.h>
typedef struct 
{
    char string[100];
    int length;
} SqString ;


void strend(SqString s,SqString t){
    int tlen = strlen(t.string);
    int slen = strlen(s.string)-tlen;
    int tl = 0;
    while(s.string[slen++] == t.string[tl++])
    {
        if(tl == strlen(t.string)){
            printf("Yes");
            return;
        }
    }
    printf("No");
    return;
    
}

int main(){
    SqString s,t;
    scanf("%s",s.string);
    scanf("%s",t.string);
    strend(s,t);
    return 0;
}