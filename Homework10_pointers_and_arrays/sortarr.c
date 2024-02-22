#include <stdio.h>

#define SIZE 10

void swap(void * p1, void * p2)
{
    int c = * (int *) p1;
    * (int *) p1 = * (int *) p2;
    * (int *) p2 = c;
}

void bubblesort(int arr[], int arrlen, void (*swapvariables)(void *, void *))
{
    for (int i=0; i < arrlen-1; i++)
    {
        int stop = 1;
        for (int j=0; j < arrlen-i-1; j++)
        {
            if(*(arr+j) > *(arr+j+1))
            {
                (*swapvariables)(arr+j, arr+j+1);
                stop = 0;
            }
        }
        if(stop == 1)break;
    }
}

int main(void)
{
    int arr1[SIZE] = {9, 6, 7, 1, 3, 5, 4, 0, 2, 8};
    int arr2[SIZE] = {5, 6 ,1, 7, 3, 9, 0, 2, 8, 4};

    bubblesort(arr1, SIZE, swap);
    for(int i=0; i < SIZE; i++)printf("%d ", arr1[i]);

    printf("\n");

    bubblesort(arr2, SIZE, swap);
    for(int i=0; i < SIZE; i++)printf("%d ", arr2[i]);

    return 0;
}