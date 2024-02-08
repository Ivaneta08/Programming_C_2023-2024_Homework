#include "quadraticroots.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    int a1=6, b1=4, c1=2;
    struct QuadraticRootsResult result1 = findroots(a1, b1, c1);
    if(result1.norealroots == 0) printf("Using int:\nx1: %lf x2: %lf norealroots: %d\n", 
        result1.x1, result1.x2, result1.norealroots);
    else if(result1.norealroots == 1) printf("Using int:\nnorealroots: %d\n", result1.norealroots);
    else printf("Using int:\nx: %lf norealroots: %d\n", result1.x1, result1.norealroots);

    float a2=3.636, b2=8.5, c2=2.75;
    struct QuadraticRootsResult result2 = findroots(a2, b2, c2);
    if(result2.norealroots == 0) printf("Using float:\nx1: %lf x2: %lf norealroots: %d\n", 
        result2.x1, result2.x2, result2.norealroots);
    else if(result2.norealroots == 1) printf("Using float:\nnorealroots: %d\n", result2.norealroots);
    else printf("Using float:\nx: %lf norealroots: %d\n", result2.x1, result2.norealroots);
    
    double a3=8.37592759, b3=4.473805726, c3=5.2740195726;
    struct QuadraticRootsResult result3 = findroots(a3, b3, c3);
    if(result3.norealroots == 0) printf("Using double:\nx1: %lf x2: %lf norealroots: %d\n", 
        result3.x1, result3.x2, result3.norealroots);
    else if(result3.norealroots == 1) printf("Using double:\nnorealroots: %d\n", result3.norealroots);
    else printf("Using double:\nx: %lf norealroots: %d\n", result3.x1, result3.norealroots);
    
    return 0;
}