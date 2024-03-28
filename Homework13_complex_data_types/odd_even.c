#include <stdio.h>

union odd_even
{
    long odd;
    short even;
};


int main(void)
{
    union odd_even arr[10];

    for(int i=0; i < 10; i++)
    {
        if(i % 2 == 1) // Odd
        {
            arr[i].odd = (long)i;
        }
        else // Even
        {
            arr[i].even = (short)i;
        }
    }
    
    for(int i=1; i < 10; i+=2) printf("%ld ", arr[i].odd);
    for(int i=0; i < 10; i+=2) printf("%hd ", arr[i].even);
    
    return 0;
}