#include<stdio.h>

int stringlen(char arr[])
{
    int i=0;
    while(*(arr+i) != '\0')i++;
    return i+1;
}

int main(void)
{
    printf("%d ", stringlen("Ivan"));
    return 0;
}