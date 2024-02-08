#include<stdio.h>

#define ARR_PRINT int arr[]={1, 2, 3, 4, 5}; \
                    for(int i=0;i < 5;i++)printf("%d ", arr[i]);

int main()
{
    ARR_PRINT
    return 0;
}