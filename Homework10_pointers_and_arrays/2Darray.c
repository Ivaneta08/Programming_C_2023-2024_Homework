#include<stdio.h>

#define COLUMNS 4
#define ROWS 3

void array2Dprint(int (*parr)[COLUMNS], int num_rows)
{
    for(int i=0; i < num_rows; i++)
    {
        for(int j=0; j < COLUMNS; j++)
        {
            printf("%5d ", *(*(parr+i)+j));
        }
        printf("\n");
    }
}

int main(void)
{
    int arr[ROWS][COLUMNS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    array2Dprint(arr, ROWS);

    return 0;
}