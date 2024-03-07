#include <stdio.h>
#include <stdlib.h>

#define NAMELEN 15
#define POINTER_CHECK(VARIABLE) if(VARIABLE == NULL){ printf("Error allocating memory!\n"); exit(1);}

char * readline_NAMELEN()
{
    char c = '\0';
    char * line = NULL;
    int size = 0;
    do
    {
        c = getchar();
        if(size == NAMELEN + 1)continue; // 1 is added for \0
        size++;
        line = realloc(line, size * sizeof(char));
        POINTER_CHECK(line)
        line[size-1] = c;
    }while(c != '\n');
    line[size-1] = '\0';
    return line;
}

int main()
{
    // Creating subjects array

    int num_subjects = 0;
    do
    {
        printf("What is the number of subjects (n >= 1): \n");
        scanf("%d", &num_subjects);
    }while(num_subjects < 1);
    getchar();

    char **subjects = (char **)malloc(num_subjects * sizeof(char *));
    POINTER_CHECK(subjects)

    for(int i = 0; i < num_subjects; i++)
    {
        printf("Enter name of subject %d:\n", i+1);
        subjects[i] = readline_NAMELEN();
        //printf("%s\n", subjects[i]);
    }

    // Menu

    int num_students = 0;
    char **students = NULL;

    int **grades = NULL;
    
    while(1)
    {
        int choice = 0;

        printf("\nEnter a number to choose:\n");
        printf("1. Add a student. (current number of students is %d)\n", num_students);
        printf("2. Print students and their year grades for every subject. (number of students > 0)\n");
        printf("3. Exit program\n");

        scanf("%d", &choice);
        getchar();

        if(choice == 1)
        {
            // Add a student

            num_students++;
            
            // Save student name
            
            students = (char **)realloc(students, num_students * sizeof(char *));
            POINTER_CHECK(students)

            printf("Enter name of student %d:\n", num_students);
            students[num_students-1] = readline_NAMELEN();
            //printf("%s\n", students[num_students-1]);

            // Save student grades

            grades = (int **)realloc(grades, num_students * sizeof(int *));
            POINTER_CHECK(grades);

            grades[num_students-1] = (int *)malloc(num_subjects * sizeof(int));
            for(int i = 0; i < num_subjects; i++)
            {
                printf("Enter %s's year grade in %s: (2 <= grade <= 6)\n", students[num_students-1], subjects[i]);
                do
                {
                    scanf("%d", &grades[num_students-1][i]);
                }while(grades[num_students-1][i] < 2 || grades[num_students-1][i] > 6);
            }
        }
        else if(choice == 2)
        {
            // Print all info

            if(num_students == 0)
            {
                printf("There are no students to print in this list. Please add more students.");
            }
            else
            {
                printf("%30s ", subjects[0]);
                for(int i = 1; i < num_subjects; i++)
                {
                    printf("%15s ", subjects[i]);
                }
                printf("\n");
                for(int i = 0; i < num_students; i++)
                {
                    printf("%15s ", students[i]);
                    for(int j = 0; j < num_subjects; j++)
                    {
                        printf("%15d ", grades[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        else if(choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid imput! Please enter again.");
        }
    }

    // Freeing dynamic memory

    for(int i=0; i < num_subjects; i++)
    {
        free(subjects[i]);
    }
    
    free(subjects);

    for(int i=0; i < num_students; i++)
    {
        free(students[i]);
        free(grades[i]);
    }

    free(students);
    free(grades);

    return 0;
}