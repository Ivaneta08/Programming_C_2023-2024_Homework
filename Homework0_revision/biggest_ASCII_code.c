#include<stdio.h>

#define maxlen 100

int main()
{
	char a[maxlen],b;
	scanf("%s",&a);
	b = a[0];
	for(int i=1; a[i] != '\0'; i++)
    {
        if(b < a[i])b=a[i];
    }
    printf("%c",b);
	return 0;
}
