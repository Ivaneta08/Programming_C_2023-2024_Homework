#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

struct SchoolClass
{
    struct Person names[26];
    char paralelka;
    int class_num;
    struct Person class_teacher;
};


#endif