#include<stdio.h>

#define RESULT(A, B) ((A) + (B)) * ((A) + (B))

int main()
{
    int x=9,y=7;
    int z = RESULT(x,y);
    printf("%d",z);
    return 0;
}