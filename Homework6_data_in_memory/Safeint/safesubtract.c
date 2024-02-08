#include <stdio.h>
#include <string.h>
#include "safeint.h"

int main(int argc, char **argv)
{
    int size1 = strlen(argv[1]);
    int size2 = strlen(argv[2]);
    util('-', argv[1], size1, argv[2], size2);

    return 0;
}