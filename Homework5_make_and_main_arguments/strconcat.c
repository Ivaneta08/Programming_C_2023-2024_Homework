#include<stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    printf("The concated strings are:\n");
    for(int i = 1; i <= argc; i+=2)
    {
        printf("%s + %s -> %s\n", argv[i], argv[i+1], strconcat(argv[i], argv[i+1]));
    }
    return 0;
}