#include <stdio.h>

void swap(void * p1, void * p2)
{
    int c = * (int *) p1;
    * (int *) p1 = * (int *) p2;
    * (int *) p2 = c;
}

int main(void)
{
    int x=8, y=45;

    swap(&x, &y);

    printf("X = %d\n", x);
    printf("Y = %d\n", y);

    return 0;
}