/*
Направете програма, която да пази списък с задачи. Задачите трябва да се подредени по приоритет - 
първата задача е с най-голям приоритет, втората е с по-нисък, трета с най-нисък и т.н. Броенето започва 
от 1. Програмата трябва да дава възможност да се добави нова задача с определен приоритет (примерно “Да 
измия чиниите” с приоритет 1” - тази задача трябва да се появи на първо място в списъка със задачи и тази 
задача, която е била в началото на списъка става втора по приоритет). Ako се зададе приоритет по-голям от 
големината на списъка, то задачата приема като приоритет големината на списъка + 1. Всяка задача има три 
състояния - Нова, Започната, Приключена. Когато нова задача се добави тя има състояние - “Нова”. Програмата 
трябва да предлага възможност да се смени състоянието на задачата по подаден номер (приоритет) на задачата. 
Програмата трябва да дава възможност да се извежда списък със всички задачи, подредени по приоритет (от най-висок, 
към най-нисък). За всяка изведена задача трябва да се принтира нейния приоритет, име и състояние. Програмата трябва 
да предлага възможност да се изтрие задача от списъка със задачи. Информацията за задачите трябва да се пазят в 
едносвързан списък (За целта можете да модифицирате едносвързания списък, който направихме в клас). Хубаво е 
данните за приоритетната задачата да се намират в отделна структура, а състоянието на задачата да бъде представена 
чрез изброим тип
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "to_do_tasks.h"

#define POINTER_CHECK(VARIABLE) if(VARIABLE == NULL){ printf("Error allocating memory!\n"); exit(1);}

char * readline_TASK_LEN()
{
    char c = '\0';
    char * line = NULL;
    int size = 0;
    do
    {
        c = getchar();
        if(size == TASK_LEN + 1)continue; // 1 is added for \0
        size++;
        line = realloc(line, size * sizeof(char));
        POINTER_CHECK(line)
        line[size-1] = c;
    }while(c != '\n');
    line[size-1] = '\0';
    return line;
}

void menu()
{
    printf("1. Add a task to your to-do list\n");
    printf("2. Change task status\n");
    printf("3. Print all tasks\n");
    printf("4. Delete task\n");
    printf("5. Exit\n");
    printf("Enter number to choose: ");
}

void printElement(uint index, ListType value) {
    if(value.status == NEW)
    {
        printf("%u. %s -> NEW\n", index+1, value.task);
    }
    else if (value.status == DONE)
    {
        printf("%u. %s -> DONE\n", index+1, value.task);
    }
    else
    {
        printf("%u. %s -> STARTED\n", index+1, value.task);
    }
}

void printLinkedList(LinkedList * list) {
    forEach(list, printElement);
    printf("\n");
}

int main(void) {

    printf("Welcome to your to-do list! What can I do for you today?\n");
    int end = 1;

    LinkedList to_do_list = init();
    
    while(end)
    {
        menu();
        int choice;
        scanf("%d", &choice);
        getchar();

        uint priority;

        switch (choice)
        {
        case 1:
            To_do_task task = {
                .status = NEW
            };

            printf("Enter the task you wish to add to your list:\n");
            
            char * text2 = readline_TASK_LEN();
            strcpy(task.task, text2);

            //scanf("%s", task.task);

            printf("Enter the priority of the task:\n");
            scanf("%u", &priority);

            if(priority-1 > to_do_list.size)priority = to_do_list.size+1;

            push(&to_do_list, priority-1, task);

            break;

        case 2:
            char text[10];

            printf("Enter the priority of the task whoose status you wish to change:\n");
            scanf("%u", &priority);

            printf("Enter the new status of the task (NEW, STARTED or DONE in all capital letters):\n");
            scanf("%s", &text);

            if(!strcmp(text, "NEW"))
            {
                struct ListNode * a = getElement(&to_do_list, priority-1);
                a->value.status = NEW;
            }
            else if(!strcmp(text, "STARTED"))
            {
                struct ListNode * a = getElement(&to_do_list, priority-1);
                a->value.status = STARTED;
            }
            else if(!strcmp(text, "DONE"))
            {
                struct ListNode * a = getElement(&to_do_list, priority-1);
                a->value.status = DONE;
            }
            else printf("ERROR! Wrong imput.\n");

            break;

        case 3:
            printLinkedList(&to_do_list);
            break;

        case 4:
            printf("Enter the priority of the task you wish to delete:\n");
            scanf("%u", &priority);

            pop(&to_do_list, priority-1);

            break;

        case 5:
            end = 0;
            break;
        
        default:
            printf("ERROR! Invalid imput. Try again.\n");
            break;
 
        }
    }

    release(&to_do_list);

    return 0;
}