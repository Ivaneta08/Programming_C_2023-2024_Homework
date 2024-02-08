#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H

#include "person.h"

struct SchoolRoom
{
    int room_num;
    struct Person in_the_room[50];
};


#endif