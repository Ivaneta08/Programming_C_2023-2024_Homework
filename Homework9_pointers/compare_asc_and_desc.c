#include <stdio.h>

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

int main(void)
{
    const int a=6, b=9, c=6;

    printf("\ncompareasc:\n");
    printf("A and B: %d\n", compareasc(&a, &b));
    printf("B and C: %d\n", compareasc(&b, &c));
    printf("A and C: %d\n", compareasc(&a, &c));

    printf("\ncomparedesc:\n");
    printf("A and B: %d\n", comparedesc(&a, &b));
    printf("B and C: %d\n", comparedesc(&b, &c));
    printf("A and C: %d\n", comparedesc(&a, &c));

    return 0;
}