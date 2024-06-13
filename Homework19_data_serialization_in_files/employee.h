#ifndef EMPLOEE_H
#define EMPLOEE_H

#define NAME_MAX_LEN 100

typedef struct employee
{
    char name[NAME_MAX_LEN];
    int num_subordinates;
    struct employee **subordinates;
}Employee;

Employee* createEmployee(char name[], int num_subordinates);
void serializeEmployees(FILE *file, Employee *employee);
void deserializeEmployees(FILE *file, Employee **employees);
void freeEmployees(Employee *employee);


#endif