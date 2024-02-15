#include <stdio.h>

int main(void)
{
    double a, b;

    printf("A: ");
    scanf("%lf", &a);

    printf("B: ");
    scanf("%lf", &b);

    double * pa = &a;
    double * pb = &b;

    printf("PA adress: %p\n", pa);
    printf("PA value: %lf\n", *pa);
    
    printf("PB adress: %p\n", pb);
    printf("PB value: %lf\n", *pb);

    return 0;
}