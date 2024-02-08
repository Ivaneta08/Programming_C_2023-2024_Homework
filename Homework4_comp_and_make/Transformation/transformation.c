#include <stdio.h>
#include <string.h>
#include "transformation.h"

struct transformation string_to_num(char arr[])
{
    struct transformation num;
    num.result = 0;
    strcpy(num.error, "\0");

    int negative = 1;
    int i=0;
    int first_enter = 0;
 
    if(arr[0] == '+')i++;
    else if(arr[0] == '-')
    {
        negative = -1;
        i++;
    }
 
    for(;i < strlen(arr);i++)
    {
        if(arr[i] >= '0' && arr[i] <= '9')
        {
            if(!first_enter && (arr[i] - '0') == 0)
            {
                num.result = 0;
                strcpy(num.error, "Invalid input string");
                break;
            }
            else
            {
                first_enter = 1;
                num.result = num.result*10 + (arr[i] - '0');
            }
        }
        else
        {
            num.result = 0;
            strcpy(num.error, "Invalid input string");
            break;
        }
    }

    if(num.result != 0)num.result *= negative;

    return num;
}