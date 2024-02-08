#include "mystrings.h"
#include<stdio.h>

int strlength(char str[])
{
    int i=0;
    for(; str[i] != '\0'; i++);
    return i;
}

char* strconcat(char first[], char second[])
{
    int len_1 = strlength(first);
    int len_2 = strlength(second);

    for(int i = 0; second[i] != '\0'; i++)
    {
        first[len_1 + i] = second[i];
    }

    first[len_1 + len_2] = '\0';

    return first;
}

int strcompare(char str1[], char str2[])
{
    int len_1 = strlength(str1);
    int len_2 = strlength(str2);

    int min_len;
    if(len_1 < len_2)min_len = len_1;
    else min_len = len_2;

    int result = 0; // We assume they are equal
    for(int i=0; i < min_len; i++)
    {
        if(str1[i] < str2[i])
        {
            result = -1;
            break;
        }
        else if(str1[i] > str2[i])
        {
            result = 1;
            break;
        }
    }

    if(result == 0)
    {
        if(len_1 != len_2)
        {
            if(len_1 == min_len)result = -1;
            else result = 1;
        }
    }

    return result;
}