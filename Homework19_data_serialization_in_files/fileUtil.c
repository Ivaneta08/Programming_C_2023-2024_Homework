#include <stdlib.h>
#include <stdio.h>
#include "fileUtil.h"

void assertFileOpen(FILE *file)
{
    if(file == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
}

void assertMemoryAlocated(void *ptr)
{
    if (ptr == NULL) 
    {
        printf("Error! Memory allocation failed");
        exit(1);
    }
}
