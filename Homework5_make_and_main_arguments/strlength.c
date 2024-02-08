#include<stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    printf("The lenghts of the strings are:\n");
    for(int i = 1; i <= argc; i++)
    {
        printf("%s - %d\n", argv[i], strlength(argv[i]));
    }
    return 0;
}