#include<stdio.h>

#define ARRAY_SIZE 7

#define ARR_PRINT(ARR, SIZE, TYPE) for(int i=0;i < (SIZE);i++)printf("%"TYPE" ", ARR[i])

void fill_arr(int arr[], int size)
{
    int val=1;
    for(int i=0;i < size;i++)
    {
        arr[i] = val;
        val *= 2;
    }
}

int main()
{
    #if defined ARRAY_SIZE && ARRAY_SIZE <= 10 && ARRAY_SIZE >= 1
        int arr[ARRAY_SIZE];
        fill_arr(arr, ARRAY_SIZE);
        ARR_PRINT(arr, ARRAY_SIZE, "d");
    #else
        printf("Array size that is not supported by the application was entered.");
    #endif

    return 0;
}