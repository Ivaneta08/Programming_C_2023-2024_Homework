#include<stdio.h>

#define DEBUG(A) printf("%d ", A)

#define ARR_PRINT(ARR, SIZE, TYPE) for(int i=0;i < (SIZE);i++)printf("%"TYPE" ", ARR[i])

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}         

void arr_sort(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int index = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[index])
            {
                index = j;
            }
        }
        swap(&arr[index] , &arr[i]);
    }
}

void sum_dev_3(int arr[], int size)
{
    arr_sort(arr, size);

    #ifdef DEBUG
        ARR_PRINT(arr, size, "d");
        printf("\n");
    #endif

    int sum=0;
    for(int i=3; i < size; i+=3)
    {
        sum += arr[i];

        #ifdef DEBUG
            DEBUG(arr[i]);
            printf("\n");
        #endif
    }
    printf("Sum of the values whose index is devisible by 3: %d", sum);
}

int main()
{
    int arr[] = {3, 7, 6, 2, 8, 9, 1, 4, 5};
    sum_dev_3(arr, 9);

    return 0;
}