#include<stdio.h>

#define DEBUG(A) printf("Name: "#A"\nValue: %d\nFile: %s\nLine: %d", A, __FILE__, __LINE__); \

int main()
{
    int a=13;
    DEBUG(a)
    return 0;
}