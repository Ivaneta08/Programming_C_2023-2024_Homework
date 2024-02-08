#include<stdio.h>

#define SWAP(TYPE, A, B)    TYPE temp##TYPE = A;    \
                            A = B;                  \
                            B = temp##TYPE;

int main()
{
    int a=6, b=3;
    SWAP(int, a, b);
    printf("%d %d\n",a,b);

    char c='j',d='l';
    SWAP(char, c, d);
    printf("%c %c\n",c,d);

    double arr[] = {7.456, 8.683};
    SWAP(double, arr[0], arr[1]);
    printf("%lf %lf\n", arr[0], arr[1]);

    return 0;
}