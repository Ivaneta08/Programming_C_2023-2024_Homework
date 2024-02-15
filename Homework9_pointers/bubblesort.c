#include <stdio.h>

#define SIZE 10

int compareasc(const void * const first, const void * const second);
int comparedesc(const void * const first, const void * const second);
void swap(void * p1, void * p2);

void bubblesort(int arr[], int arrlen, int (*compare)(const void * const, const void * const), void (*swapelements)(void *, void *))
{
    for (int i=0; i < arrlen-1; i++)
    {
        int dont_stop = 0;
        for (int j=0; j < arrlen-i-1; j++)
        {
            if((*compare)(&arr[j], &arr[j+1]) == 1)
            {
                (*swapelements)(&arr[j], &arr[j+1]);
                dont_stop = 1;
            }
        }
        if(dont_stop == 0)break;
    }
}

int main(void)
{
    int arr1[SIZE] = {9, 6, 7, 1, 3, 5, 4, 0, 2, 8};
    int arr2[SIZE] = {9, 6, 7, 1, 3, 5, 4, 0, 2, 8};

    printf("\nBubblesort with compareasc: ");
    bubblesort(arr1, SIZE, compareasc, swap);
    for(int i=0; i < SIZE; i++)printf("%d ", arr1[i]);

    printf("\nBubblesort with comparedesc: ");
    bubblesort(arr2, SIZE, comparedesc, swap);
    for(int i=0; i < SIZE; i++)printf("%d ", arr2[i]);

    return 0;
}

int compareasc(const void * const first, const void * const second)
{
    if(* (int *) first > * (int *) second)
    {
        return 1;
    }
    else if(* (int *) first < * (int *) second)
    {
        return -1;
    }
    else return 0;
}

int comparedesc(const void * const first, const void * const second)
{
    if(* (int *) first < * (int *) second)
    {
        return 1;
    }
    else if(* (int *) first > * (int *) second)
    {
        return -1;
    }
    else return 0;
}

void swap(void * p1, void * p2)
{
    int c = * (int *) p1;
    * (int *) p1 = * (int *) p2;
    * (int *) p2 = c;
}