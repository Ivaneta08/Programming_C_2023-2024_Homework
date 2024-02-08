#include <stdio.h>
#include <string.h>
#include "transformation.h"

int main()
{
    char str1[100] = "-123";
    struct transformation a = string_to_num(str1);
    if(a.error[0] == '\0') printf("%ld\n", a.result);
    else printf("%s\n", a.error);

    char str2[100] = "12dv3";
    struct transformation b = string_to_num(str2);
    if(b.error[0] == '\0') printf("%ld\n", b.result);
    else printf("%s\n", b.error);
}