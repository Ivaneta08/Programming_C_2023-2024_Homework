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
        printf("EGN: %ld\nNames: %s\nAge: %d\nEducation: ", 
        arr->buffer[i].egn, arr->buffer[i].names, arr->buffer[i].age);

        if(arr->buffer[i].education == 0)printf("None\n");
        else if(arr->buffer[i].education == 1)printf("Primary\n");
        else if(arr->buffer[i].education == 2)printf("Secondary\n");
        else printf("Higher");
        
        printf("Work status: ");
        if(arr->buffer[i].work_status == 0)printf("Unemployed\n");
        else printf("Employed\n");

        printf("Marital status: ");
        if(arr->buffer[i].marital_status == 0)printf("Single\n");
        else printf("Married\n");

        printf("\n");
    }
}

void saveCitizens(FILE *file, DynamicArray *arr) {
    rewind(file);
    for (int i = 0; i < arr->size; i++) {
        fwrite(&arr->buffer[i].egn, sizeof(long), 1, file);
        fwrite(&arr->buffer[i].namelen, sizeof(int), 1, file);
        fwrite(&arr->buffer[i].names, sizeof(char), arr->buffer[i].namelen, file);
        fwrite(&arr->buffer[i].age, sizeof(int), 1, file);
        fwrite(&arr->buffer[i].education, sizeof(int), 1, file);
        fwrite(&arr->buffer[i].work_status, sizeof(int), 1, file);
        fwrite(&arr->buffer[i].marital_status, sizeof(int), 1, file);
    }
    fflush(file);
}

int main(void)
{
    FILE * file = fopen("citizens_of_Bulgaria.bin", "ab+");

    if(file == NULL)
    {
        printf("Error! Cannot open file!\n");
        exit(1);
    }

    DynamicArray citizens = init(3);

    Citizen citizen;
    while(fread(&citizen.egn, sizeof(long), 1, file) == 1)
    {
        fread(&citizen.namelen, sizeof(citizen.namelen), 1, file);
        
        fread(&citizen.names, sizeof(char), citizen.namelen, file);
        citizen.names[citizen.namelen] = '\0';
        
        fread(&citizen.age, sizeof(citizen.age), 1, file);
        fread(&citizen.education, sizeof(citizen.education), 1, file);
        fread(&citizen.work_status, sizeof(citizen.work_status), 1, file);
        fread(&citizen.marital_status, sizeof(citizen.marital_status), 1, file);
        
        pushBack(&citizens, citizen);
    }

    int end = 1;

    while (end)
    {
        menu();
        int choice;
        scanf("%d", &choice);
        //getchar();
        printf("\n");

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
            //getchar();

            int deleted = 0;

            for (int i = 0; i < citizens.size; i++) {
                if(citizens.buffer[i].egn == num)
                {
                    deleted = 1;
                    removeElement(&citizens, (uint)i);
                    break;
                }
            }
            
            if(deleted == 0)
            {
                printf("Citizen not found.\n");
            }
            else
            {
                printf("Citizen removed.\n");
                saveCitizens(file, &citizens);
            }

            printf("\n");
            break;

        case 3:
            printf("Enter citizen information\n");
            
            Citizen new_citizen;

            printf("EGN: ");
            scanf("%ld", &new_citizen.egn);
            getchar();
            
            printf("Names: ");
            fgets(new_citizen.names, 255, stdin);

            int index = strcspn(new_citizen.names, "\n");
            new_citizen.names[index] = '\0';

            new_citizen.namelen = strlen(new_citizen.names);

            printf("Age: ");
            scanf("%d", &new_citizen.age);
            getchar();

            do{
                printf("Education (NONE = 0, PRIMARY = 1, SECONDARY = 2, HIGHER = 3): ");
                scanf("%d", &new_citizen.education);
                getchar();
            }while(new_citizen.education > 3 || new_citizen.education < 0);

            do{
                printf("Work status: UNEMPLOYED = 0, EMPLOYED = 1): ");
                scanf("%d", &new_citizen.work_status);
                getchar();
            }while(new_citizen.work_status > 1 || new_citizen.work_status < 0);

            do{
                printf("Marital status: SINGLE = 0, MARRIED = 1): ");
                scanf("%d", &new_citizen.marital_status);
                getchar();
            }while(new_citizen.marital_status > 1 || new_citizen.marital_status < 0);

            printf("\n");

            pushBack(&citizens, new_citizen);

            saveCitizens(file, &citizens);
            
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

    fclose(file);

    return 0;
}