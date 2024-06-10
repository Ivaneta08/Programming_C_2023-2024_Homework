#ifndef CITIZEN_H
#define CITIZEN_H

#define NAME_MAX_LEN 255

enum Education{
    NONE,
    PRIMARY,
    SECONDARY,
    HIGHER
};

enum Working_status{
    UNEMPLOYED,
    EMPLOYED
};

enum Marital_status{
    SINGLE,
    MARRIED
};

typedef struct
{
    long egn;
    int namelen;
    char names[NAME_MAX_LEN];
    int age;
    enum Education education;
    enum Working_status work_status;
    enum Marital_status marital_status;
}Citizen;

#endif