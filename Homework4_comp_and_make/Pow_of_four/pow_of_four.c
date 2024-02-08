#include <stdio.h>
#include <math.h>

int main()
{
    long arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i=0;i < 10;i++)
    {
        arr[i] = pow(arr[i], 4);
        printf("%ld ", arr[i]);
    }
}