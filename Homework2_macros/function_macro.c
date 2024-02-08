#include<stdio.h>

#define BIGGER(A, B) if((A) > (B))printf(#A" is bigger than "#B); \
                        else if((A) < (B)) printf(#B" is bigger than "#A); \
                        else printf(#A" and "#B" are equal");

int main()
{
    int x=9,y=7;
    BIGGER(x,y)
    return 0;
}