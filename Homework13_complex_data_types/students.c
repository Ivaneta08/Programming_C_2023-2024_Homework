#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 15

void printMenu()
{
    printf("1. Add a student\n");
    printf("2. Print students list\n");
    printf("3. Exit\n");
}

typedef struct Student
{
    char name[NAME_LEN];
    int class_number;
    double average_grade;
} student;


int main(void)
{
    student *data_list = NULL;
    int size = 0;

    while(1)
    {
        printMenu();
        printf("Enter a number to choose: ");
        int input;
        scanf("%d", &input);
        
        if(input == 1)
        {
            size++;
            data_list = (student *)realloc(data_list, size*sizeof(student));
            
            printf("Enter student data:\n");
            
            printf("Name: ");
            scanf("%s", data_list[size-1].name);
            
            printf("Number in class: ");
            scanf("%d", &data_list[size-1].class_number);
            
            do{
                printf("Average grade: ");
                scanf("%lf", &data_list[size-1].average_grade);
            }while(data_list[size-1].average_grade > 6 || data_list[size-1].average_grade < 2);
            
        }
        else if(input == 2)
        {
            printf("Student data:\n");
            for(int i=0; i < size; i++)
            {
                printf("%15s ", data_list[i].name);
                printf("%3d ", data_list[i].class_number);
                printf("%5f\n", data_list[i].average_grade);
            }
        }
        else if(input == 3)
        {
            printf("Exiting...");
            break;
        }
        else
        {
            printf("Invalid imput!\n");
        }
    }
    
    return 0;
}