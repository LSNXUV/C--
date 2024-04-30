#include <stdio.h>

int strcompare(const char * str1, const char * str2){
	const char *p = str1,*q=str2;
	for(;*p==*q&&*p!='\0'&&*q!='\0';p++,q++){};
	return *p-*q;
}

int main()
{
    char str1[256], str2[256];
    scanf("%s%s", str1, str2);
    printf("%d", strcompare(str1, str2));
    return 0;
}