#include<stdio.h>

#define ARR_PRINT(ARR, SIZE, TYPE) for(int i=0;i < (SIZE);i++)printf("%"TYPE" ", ARR[i])

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}         

void Bubble_sort(int arr[], int size)
{
    for(int i=0;i < size-1; i++)
    {
        int swapped = 0;
        for(int j=0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapped = 1;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void Straight_selection(int arr[], int size)
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

void Insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void Invert_arr(int arr[], int size)
{
    for(int i=0;i < size/2; i++)
    {
        swap(&arr[i], &arr[size-i-1]);
    }
}

void sort_by_OS(int arr[], int size)
{
    #ifdef _WIN32
        Bubble_sort(arr, size);
    #elif _linux_
        Straight_selection( arr, size);
    #elif _APPLE_
        Insertion_sort(arr, size);
    #else
    	Invert_arr(arr, size);
    #endif
}

int main()
{
    int arr[] = {3, 7, 6, 2, 8, 9, 1, 4, 5};

    sort_by_OS(arr, 9);

    ARR_PRINT(arr, 9, "d");

    return 0;
}