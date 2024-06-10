/*
При добавяне на нов запис, 
данните трябва да се запазват автоматични в отворения за работа файл. При триене, данните също трябва да се запазват автоматично.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "citizen.h"
#include "dynarr.h"

void menu()
{
    printf("1. Print all data\n");
    printf("2. Delete a citizen by EGN\n");
    printf("3. Add a new citizen\n");
    printf("4. Exit\n");
    printf("Enter number to choose: ");
}

void printCitizens(DynamicArray * arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%ld %s %d %d %d %d\n", 
        arr->buffer[i].egn, arr->buffer[i].names, arr->buffer[i].age,
        arr->buffer[i].education, arr->buffer[i].work_status, arr->buffer[i].marital_status);
    }
    printf("\n");
}

int main(void)
{
    FILE * file = fopen("citizens_of_Bulgaria.bin", "a+");

    if(file == NULL)
    {
        printf("Error! Cannot open file!\n");
        exit(1);
    }

    DynamicArray citizens = init(3);

    Citizen citizen;
    while(fread(&citizen.egn, sizeof(long), 1, file) != EOF);
    {
        fread(&citizen.namelen, sizeof(citizen.namelen), 1, file);
        fread(&citizen.names, sizeof(citizen.names), namelen, file);
        fread(&citizen.age, sizeof(citizen.age), 1, file);
        fread(&citizen.education, sizeof(citizen.education), 1, file);
        fread(&citizen.work_status, sizeof(citizen.work_status), 1, file);
        fread(&citizen.marital_status, sizeof(citizen.marital_status), 1, file);
        pushBack(&citizens, citizen);
    }

    fclose(file);

    int end = 1;

    while (end)
    {
        menu();
        int choice;
        scanf("%d", &choice);
        printf("\n")

        switch (choice)
        {
        case 1:
            printf("Printing all information about every citizen...\n");
            printCitizens(&citizens);
            break;

        case 2:
            printf("Enter the EGN number of the citizen you wish to be deleted: ");
            long num;
            scanf("%ld", &num);

            int deleted = 0;

            for (int i = 0; i < citizens.size; i++) {
                if(citizens.buffer[i].EGN == num)
                {
                    deleted = removeElement(&citizens, (uint)i);
                }
            }

            if(deleted == 0)
            {
                printf("Citizen not found.\n");
            }
            else
            {
                printf("Citizen removed.\n");
            }

            printf("\n");
            break;

        case 3:
            printf("Enter citizen information\n");
            
            Citizen new_citizen;

            printf("EGN: ");
            scanf("%ld", &new_citizen.egn);
            
            printf("Names: ");
            fgets(new_citizen.names, 255, stdin);

            printf("Age: ");
            scanf("%d", &new_citizen.age);

            printf("Education (NONE = 0, PRIMARY = 1, SECONDARY = 2, HIGHER = 3): ");
            scanf("%d", &new_citizen.education);

            printf("Work status: UNEMPLOYED = 0, EMPLOYED = 1");
            scanf("%d", &new_citizen.work_status);

            printf("Marital status: SINGLE = 0, MARRIED = 1");
            scanf("%d", &new_citizen.marital_status);

            new_citizen.namelen = strlen(new_citizen.names)

            printf("\n");

            pushBack(&citizen, new_citizen);
            
            break;

        case 4:
            end = 0;
            printf("Exiting program...");
            break;
        
        default:
            printf("Invalid imput!\n");
            break;
        }
    }

    return 0;
}