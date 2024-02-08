#include<stdio.h>
#include "mystrings.h"

#define MAX_STR_LEN 100

int main()
{
    while(1)
    {
        printf("Choose a function from the list below (or exit):\n");
        printf("1. strlength - finds the lenght of a string\n");
        printf("2. strconcat - concat two strings\n");
        printf("3. strcompare - compares two strings\n");
        printf("4. Exit\n");
        
        int choice;
        do
        {
            printf("The number you enter MUST be between 1 and 4: ");
            scanf("%d", &choice);
        }while(!(choice < 5 && choice > 0));

        if(choice == 4)break;
        else if(choice == 1)
        {
            char str[MAX_STR_LEN];
            printf("Enter string: ");
            scanf("%s", &str);

            printf("%d\n\n", strlength(str));
        }
        else if(choice == 2)
        {
            char first[MAX_STR_LEN], second[MAX_STR_LEN];
            printf("Enter first string: ");
            scanf("%s", &first);
            printf("Enter first string: ");
            scanf("%s", &second);

            printf("%s\n\n", strconcat(first, second));
        }
        else if(choice == 3)
        {
            char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
            printf("Enter a string: ");
            scanf("%s", &str1);
            printf("Enter another string: ");
            scanf("%s", &str2);

            printf("%d\n\n", strcompare(str1, str2));
        }
    }

    return 0;
}