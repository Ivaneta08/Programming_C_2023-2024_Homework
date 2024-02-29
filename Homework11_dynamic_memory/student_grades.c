#include <stdio.h>
#include <stdlib.h>

#define ERROR_CHECK(VARIABLE) if(VARIABLE == NULL){printf("Error allocating memory!\n"); exit(1);}

int main()
{
    int num_grades;
    do
    {
        printf("Please enter the number of grades: (n > 0)\n");
        scanf("%d", &num_grades);
    } while (num_grades <= 0);

    float *grades = (float *)malloc(num_grades * sizeof(float));

    ERROR_CHECK(grades)

    for(int i=0; i < num_grades; i++)
    {
        do
        {
            printf("Please enter grade number %d: (2 <= grade <= 6)\n", i+1);
            scanf("%f", &grades[i]);
        } while (grades[i] < 2 || grades[i] > 6);
    }

    int end = 0;

    while(!end)
    {
        int choice;

        do
        {
            printf("\nPlease enter a number to choose:\n");
            printf("1. Print averade grade\n");
            printf("2. Add new grade\n");
            printf("3. Remove last grade\n");
            printf("4. Exit\n");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1:
            float average_grade;
            for(int i=0;i < num_grades; i++)
            {
                average_grade += grades[i];
            }
            average_grade /= num_grades;

            printf("The average grade of the student is: \n%f\n", average_grade);

            break;
        
        case 2:
            num_grades++;
            grades = (float *)realloc(grades, num_grades * sizeof(float));
            ERROR_CHECK(grades)

            do
            {
                printf("Enter new grade number %d: (2 <= grade <= 6)\n", num_grades);
                scanf("%f", &grades[num_grades-1]);
            } while (grades[num_grades-1] < 2 || grades[num_grades-1] > 6);

            break;

        case 3:
            if(num_grades > 1)
            {
                num_grades--;
                grades = (float *)realloc(grades, num_grades * sizeof(float));
                ERROR_CHECK(grades)

                printf("Last grade removed.\n");
            }
            else printf("The student can't have less then 1 grade.\n");
            break;

        case 4:
            end = 1;
            break;

        default:
            printf("Error choosing!\n"); 
            break;
        }
    }

    free(grades);
    
    return 0;
}
