#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "fileUtil.h"

Employee* createEmployee(char name[], int num_subordinates) 
{
    Employee *employee = (Employee *)malloc(sizeof(Employee));
    assertMemoryAlocated((void *)employee);
    
    strcpy(employee->name, name);
    employee->name[NAME_MAX_LEN - 1] = '\0';

    employee->num_subordinates = num_subordinates;
    
    if (num_subordinates > 0) 
    {
        employee->subordinates = (Employee **)malloc(num_subordinates * sizeof(Employee *));
        assertMemoryAlocated((void *)employee->subordinates);
    } 
    
    else 
    {
        employee->subordinates = NULL;
    }
    
    return employee;
}

void serializeEmployees(FILE *file, Employee *employee) 
{
    fwrite(employee->name, sizeof(char), NAME_MAX_LEN, file);
    fwrite(&employee->num_subordinates, sizeof(int), 1, file);
    for (int i = 0; i < employee->num_subordinates; i++) 
    {
        serializeEmployees(file, employee->subordinates[i]);
    }
}

void deserializeEmployees(FILE *file, Employee **employee) {
    employee = (Employee **)malloc(sizeof(Employee *));
    assertMemoryAlocated((void *)(*employee));

    fread((*employee)->name, sizeof(char), NAME_MAX_LEN, file);
    fread(&(*employee)->num_subordinates, sizeof(int), 1, file);
    
    if ((*employee)->num_subordinates > 0) 
    {
        (*employee)->subordinates = (Employee **)malloc((*employee)->num_subordinates * sizeof(Employee *));
        assertMemoryAlocated((void *)(*employee)->subordinates);
        
        for (int i = 0; i < (*employee)->num_subordinates; i++) 
        {
            deserializeEmployees(file, &(*employee)->subordinates[i]);
        }
    } 
    
    else 
    {
        (*employee)->subordinates = NULL;
    }
}

void freeEmployees(Employee *employee)
{
    for (int i = 0; i < employee->num_subordinates; i++)
    {
        freeEmployees(employee->subordinates[i]);
    }
    free(employee->subordinates);
    free(employee);
}