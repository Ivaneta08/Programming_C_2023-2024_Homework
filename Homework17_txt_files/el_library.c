#include <stdio.h>
#include <stdlib.h>
#include "dynarr.h"

// Moved to dynarr.h
/*
#define BOOK_NAME_LEN 50
#define AUTHOR_NAME_LEN 30
#define GENRE_LEN 20

typedef struct
{
    char name[BOOK_NAME_LEN];
    char author[AUTHOR_NAME_LEN];
    char genre[GENRE_LEN];
    int published_year;
    int ISBN;
}Book;
*/

void menu()
{
    printf("1. Add a new book\n");
    printf("2. Print all books and their attributes\n");
    printf("3. Delete a book by ISBN number\n");
    printf("4. Save changes to the file\n");
    printf("5. Exit\n");
    printf("Enter number to choose: ");
}

void printElLib(DynamicArray * arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%s %s %s %d %d\n", 
        arr->buffer[i].name, arr->buffer[i].author, arr->buffer[i].genre, arr->buffer[i].published_year, arr->buffer[i].ISBN);
    }
    printf("\n");
}

int main(void)
{
    FILE * file = fopen("books.txt", "r");

    if(file == NULL)
    {
        printf("Error! Cannot open file!\n");
        exit(1);
    }

    DynamicArray el_lib = init(5);

    Book book;
    while(fscanf(file, "%s %s %s %d %d", &book.name, &book.author, &book.genre, &book.published_year, &book.ISBN) != EOF);
    {
        pushBack(&el_lib, book);
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
            printf("Enter book information\n");
            
            Book new_book;

            printf("Name (no spaces): ");
            scanf("%s", &new_book.name);
            
            printf("Author: ");
            scanf("%s", &new_book.author);

            printf("Genre: ");
            scanf("%s", &new_book.genre);

            printf("Published year: ");
            scanf("%d", &new_book.published_year);

            printf("ISBN: ");
            scanf("%d", &new_book.ISBN);

            printf("\n");

            pushBack(&el_lib, new_book);

            break;

        case 2:
            printf("Printing all information about every book...\n");
            printElLib(&el_lib);
            break;

        case 3:
            printf("Enter the ISBN number of the book you wish to be deleted: ");
            int num;
            scanf("%d", &num);

            int deleted = 0;

            for (int i = 0; i < el_lib.size; i++) {
                if(el_lib.buffer[i].ISBN == num)
                {
                    deleted = removeElement(&el_lib, (uint)i);
                }
            }

            if(deleted == 0)
            {
                printf("Book not found.\n");
            }
            else
            {
                printf("Book removed.\n");
            }

            printf("\n");
            break;

        case 4:
            FILE * file = fopen("books.txt", "w");

            if(file == NULL)
            {
                printf("Error! Cannot open file!\n");
                exit(1);
            }

            for (int i = 0; i < el_lib.size; i++) {
                fprintf(file, "%s %s %s %d %d\n", el_lib.buffer[i].name, el_lib.buffer[i].author, 
                el_lib.buffer[i].genre, el_lib.buffer[i].published_year, el_lib.buffer[i].ISBN);
            }

            fclose(file);
            break;

        case 5:
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
