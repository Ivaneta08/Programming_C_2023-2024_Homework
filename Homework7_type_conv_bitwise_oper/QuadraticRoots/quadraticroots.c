#include "quadraticroots.h"
#include <stdio.h>
#include <math.h>

struct QuadraticRootsResult findroots(double a, double b, double c)
{
    printf("\na=%lf b=%lf c=%lf\n", a, b, c);
    struct QuadraticRootsResult result;
    if(a != 0)
    {
        double discriminant = (b * b) - (4 * a * c);    // D = b^2 - 4ac
        //printf("\na=%ld b=%ld c=%ld D = %ld\n", a, b, c, discriminant);
        if(discriminant < 0) result.norealroots = 1;    // D < 0 => no real roots
        else                                            // D >= 0
        {
            result.norealroots = 0;
            result.x1 = (b + sqrtl(discriminant)) / (2 * a);
            result.x2 = (b - sqrtl(discriminant)) / (2 * a);
        }
    }
    else // a == 0
    {
        result.norealroots = -1; // We have only 1 answer in x1
        result.x1 = (-c)/b;
    }
    return result;
}