#include "safeint.h"
#include <stdio.h>

struct SafeResult safeadd(int addend1, int addend2)                // addend - събираемо
{
    struct SafeResult sum;
    sum.errorflag = 0;
    sum.value = addend1 + addend2;
    long long temp = (long long)addend1 + addend2;
    if (sum.value != temp)
    {
        sum.errorflag = 1;
    }
    return sum;
}

struct SafeResult safesubtract(int minuend, int subtrahend)        // minuend - умаляемо, subtrahend - умалител
{
    struct SafeResult difference;
    difference.errorflag = 0;
    difference.value = minuend - subtrahend;
    long long temp = (long long)minuend - subtrahend;
    if (difference.value != temp)
    {
        difference.errorflag = 1;
    }
    return difference;
}

struct SafeResult safemultiply(int multiplier, int multiplicand)   // multiplier - първи множител, multiplicand - втори множител
{
    struct SafeResult product;
    product.errorflag = 0;
    product.value = multiplier * multiplicand;
    long long temp = (long long)multiplier * multiplicand;
    if (product.value != temp)
    {
        product.errorflag = 1;
    }
    return product;
}

struct SafeResult safedivide(int dividend, int divisor)            // dividend - делимо, divisor - делител, quotient - частно
{
    struct SafeResult quotient;
    quotient.errorflag = 0;
    quotient.value = dividend / divisor;
    long long temp = (long long)dividend / divisor;
    if (quotient.value != temp)
    {
        quotient.errorflag = 1;
    }
    return quotient;
}

struct SafeResult safestrtoint(char str[], int size_str)
{
    struct SafeResult num;
    num.errorflag = 0;
    num.value = 0;
    int error = 0;

    int negative = 1;
    int i=0;
    if(str[i] == '-')
    {
        negative = -1;
        i++;
    }

    for(; i < size_str; i++)
    {
        int temp = str[i] - '0';
        num = safemultiply(num.value, 10);
        if(num.errorflag == 1) error = 1;
        num = safeadd(num.value, temp);
        if(num.errorflag == 1) error = 1;
    }
    num.value *= negative;
    if(error == 1)num.errorflag = 1;
    return num;
}

void util(char operation, char arg1[], int size1, char arg2[], int size2)
{
    int error_arg = 0;
    int error = 0;
    int error_operation = 0;

    struct SafeResult a =  safestrtoint(arg1, size1);
    struct SafeResult b =  safestrtoint(arg2, size2);
    struct SafeResult result;

    switch (operation)
    {
    case '+':
        result =  safeadd(a.value, b.value);
        break;
    
    case '-':
        result =  safesubtract(a.value, b.value);
        break;
    
    case '*':
        result =  safemultiply(a.value, b.value);
        break;

    case '/':
        result =  safedivide(a.value, b.value);
        break;

    default:
        error_operation = 1;
        break;
    }
    
    if(a.errorflag == 1 || b.errorflag == 1)error_arg = 1;
    else if(result.errorflag == 1)error = 1;

    if(error_arg) printf("Error! Invalid arguments!");
    else if(error) printf("Error! Overflow or underflow during operation!");
    else if(error_operation) printf("Error! Invalid operation!");
    else
    {
        printf("%d\n", result.value);
    }
}