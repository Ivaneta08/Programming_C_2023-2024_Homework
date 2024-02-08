#include<stdio.h>

int nok(int a, int b)
{
    int del = 2;
    int result = 1;
    while(a != 1 || b != 1)
    {
        if(a%del == 0)
        {
            a /= del;
            result *= del;
            if(b%del == 0)b /= del;
        }
        else if(b%del == 0)
        {
            b /= del;
            result *= del;
        }
        else del++;
    }
    return result;
}

int main()
{
    printf("%d",nok(12,18));
    return 0;
}