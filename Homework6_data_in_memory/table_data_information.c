#include <limits.h>
#include <stdio.h>

#define PRINT_LIMITS(name, NAME, FORMAT, UFORMAT) printf("%-15s : %-6s : %-4zu : %-21"#FORMAT" : %-21"#FORMAT" : %-15s : %-20"#UFORMAT"\n", #name, #FORMAT, sizeof(#name), NAME##_MAX, NAME##_MIN, #UFORMAT, U##NAME##_MAX)

int main()
{
    printf("%-15s : %-6s : %-4s : %-21s : %-21s : %-15s : %-20s\n", "Data type", "Format", "Size", "Max signed value", "Min signed value", "Unsigned format","Max unsigned value");
    PRINT_LIMITS(char, CHAR, d, u);
    PRINT_LIMITS(short, SHRT, hd, hu);
    PRINT_LIMITS(int, INT, d, u);
    PRINT_LIMITS(long, LONG, ld, lu);
    PRINT_LIMITS(long long, LLONG, lld, llu);
}