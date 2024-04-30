#include <stdio.h>
#include <string.h>

void stringNx(char *a)
{
    int i, j, temp;
    for (i = 0, j = strlen(a) - 1; i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
}

int main(){
    char a[100];
    scanf("%s", a);
    stringNx(a);
    printf("%s", a);
    scanf("%s", a);

return 0;
}
