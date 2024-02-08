#ifndef SAFEINT_H
#define SAFEINT_H

struct SafeResult
{
    int value;      // По-надолу в задачата също го наричате и result
    char errorflag;
};

struct SafeResult safeadd(int addend1, int addend2);                // addend - събираемо
struct SafeResult safesubtract(int minuend, int subtrahend);        // minuend - умаляемо, subtrahend - умалител
struct SafeResult safemultiply(int multiplier, int multiplicand);   // multiplier - първи множител, multiplicand - втори множител
struct SafeResult safedivide(int dividend, int divisor);            // dividend - делимо, divisor - делител
struct SafeResult safestrtoint(char str[], int size_str);
void util(char operation, char *arg1, int size1, char *arg2, int size2);

#endif