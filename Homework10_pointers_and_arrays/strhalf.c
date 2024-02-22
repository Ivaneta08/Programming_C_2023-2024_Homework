#include<stdio.h>

int stringlen(char arr[]);

void strhalf(char str[], char **pp)
{
    int len = stringlen(str) - 1; // -1 for \0
    len /= 2;
    *pp = str+len;
}

int main(void)
{
    char name[] = "Bloom";
    char *p = name;
    char **pp = &p;

    strhalf(name, pp);

    printf("%s ", p);

    return 0;
}

int stringlen(char arr[])
{
    int i=0;
    while(*(arr+i) != '\0')i++;
    return i+1;
}