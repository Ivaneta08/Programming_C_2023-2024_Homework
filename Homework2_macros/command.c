#include<stdio.h>

#define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ## _command

#define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME, TYPE)(void)

int quit=6, external=9;
DEFINE_COMMAND(quit, external) {
    printf("First function created successfully.\n");
    printf("The value of quit is %d\n", quit);
}

int q2=6, e2=9;
DEFINE_COMMAND(q2, e2) { 
    printf("Second function created successfully.\n");
    printf("The value of e2 is %d\n", e2);
}

int main()
{
    COMMAND(quit, external)();
    COMMAND(q2, e2)();
    
    return 0;
}