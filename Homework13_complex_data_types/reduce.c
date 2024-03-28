#include <stdio.h>

typedef unsigned long long ull;
typedef ull (*ptrfuncull)(ull, ull);

ull add(ull a, ull b)
{
    return a+b;
}

ull reduce(ull arr[], ull arrlen, ptrfuncull ptrfunc, ull initial_value)
{
    ull result = initial_value;
    for(int i=0; i < arrlen; i++)
    {
        result = ptrfunc(result, arr[i]);
    }
    return result;
}

int main(void)
{
    ull arr[] = {1, 2, 3, 5};
    printf("%d", reduce(arr, 4, add, 4));
    return 0;
}