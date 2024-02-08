#ifndef TRANSFORMATION_H 
#define TRANSFORMATION_H

struct transformation
{
    long result;
    char error[100];
};

struct transformation string_to_num(char arr[]);

#endif