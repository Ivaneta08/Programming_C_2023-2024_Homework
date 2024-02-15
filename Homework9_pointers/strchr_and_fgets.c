#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[255];

    fgets(name, 255, stdin);
    // stdin - standard imput from the console
    // fgets also gets the \n in the end when entering from the console

    char * p = strchr(name, '\n');
    // strchr - returns a pointer to the adress of the found char in the string

    if(p != NULL)
    {
        *p = '\0';
        // Replase '\n' with '\0'
    }

    printf("%s", name);

    return 0;
}