#include<stdio.h>

#define SWAP(TYPE, A, B)    TYPE temp##TYPE = A;    \
                            A = B;                  \
                            B = temp##TYPE;     

#define SORT(COMP, TYPE, ARR, SIZE) for(int i = 0; i < (SIZE)-1; i++)       \
                                    {                                       \
                                        int index = i;                      \
                                        for(int j = i+1; j < (SIZE); j++)   \
                                        {                                   \
                                            if(ARR[j] COMP ARR[index])      \
                                            {                               \
                                                index = j;                  \
                                            }                               \
                                        }                                   \
                                        SWAP(TYPE, ARR[index] , ARR[i]);    \
                                    }

#define ARR_PRINT(ARR, SIZE, TYPE) for(int i=0;i < (SIZE);i++)printf("%"TYPE" ", ARR[i])

int main()
{
    int arr1[] = {3, 7, 6, 2, 8, 9, 1, 4, 5};
    SORT( <, int, arr1, 9);
    ARR_PRINT(arr1, 9, "d");

    printf("\n");

    char arr2[] = {'f', 'a', 'e', 'b', 'c', 'g', 'p', 'k', 'd', 'h'};
    SORT( >, char, arr2, 10);
    ARR_PRINT(arr2, 10, "c");
    return 0;
}