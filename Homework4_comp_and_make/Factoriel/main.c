#include <stdio.h>
#include "maths.h"

int main()
{
    int n[5] = {4, 5, 6, 7, 8};
    for(int i=0; i < 5; i++)
    {
        printf("%d", factoriel(n[i]));
    }
    return 0;
}