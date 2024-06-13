/*
Да се направи програма, която да сериализира и десериализира йерархия от работници във фирма, в бинарен файл. За целта:

Да се създаде структура служител (Employee), който има име (до 100 символа), брой подчинени служители и списък с подчинени служители. 
Списъкът от подчинени служители трябва да се пази в масив от указатели (тоест в двоен указател) от тип служител, за да може да добавяме 
други служители като подчинени на текущия. Ако служителят няма подчинени работници, този двоен указател трябва да сочи към NULL. (Насока: 
създайте първо работниците, после мениджърите и после директора, за да можете да ги добавите. Използвайте динамично заделяне на памет, за 
да създадете списъците от подчинени).

Да се създаде програма, която създава йерархия от служители (примерно един директор, който има двама мениджъри, всеки мениджър има по 
трима подчинени) и която сериализира тази йерархия в бинарен файл.

Да се направи втора програма, която да чете данните от бинарния файл и да ги десериализира обратно в йерархия и след това да принтира на 
екрана данните от йерархията подравнени. Например:
  
  Име на директор
       Име на мениджър 1
           Име на работник 1 
           Име на работник 2
           Име на работник 3
       Име на мениджър 2
           Име на работник 4
           Име на работник 5
           Име на работник 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "fileUtil.h"

void printEmployees(Employee *employee, int tabs) {
    if (employee != NULL) 
    {
        for (int i = 0; i < tabs; i++) printf("  ");
        printf("%s\n", employee->name);
        
        for (int i = 0; i < employee->num_subordinates; i++) {
            printEmployees(employee->subordinates[i], tabs + 1);
        }
    }
}

int main(void) {
    Employee *A = createEmployee("A", 3);
    
    Employee *A1 = createEmployee("A1", 0);
    Employee *A2 = createEmployee("A2", 0);
    Employee *A3 = createEmployee("A3", 0);

    A->subordinates[0] = A1;
    A->subordinates[1] = A2;
    A->subordinates[2] = A3;

    Employee *B = createEmployee("B", 3);

    Employee *B1 = createEmployee("B1", 0);
    Employee *B2 = createEmployee("B2", 0);
    Employee *B3 = createEmployee("B3", 0);

    B->subordinates[0] = B1;
    B->subordinates[1] = B2;
    B->subordinates[2] = B3;

    Employee *Boss = createEmployee("Boss", 2);

    Boss->subordinates[0] = A;
    Boss->subordinates[1] = B;

    FILE *file = fopen("employees.bin", "wb");
    assertFileOpen(file);

    serializeEmployees(file, Boss);
    fclose(file);

    Employee *deserialized = NULL;
    file = fopen("employees.bin", "rb");
    assertFileOpen(file);

    deserializeEmployees(file, &deserialized);
    fclose(file);

    printf("Deserialized hierarchy:\n");
    printEmployees(deserialized, 0);

    freeEmployees(Boss);

    freeEmployees(deserialized);

    return 0;
}