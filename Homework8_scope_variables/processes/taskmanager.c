#include <stdio.h>
#include "processes.h"

extern struct Process processes[5];
extern int processescount;

int main(void)
{
    int end = 1;
    while(end)
    {
        printf("Choose an option by entering 1, 2, 3 or 4: \n");
        printf("1. Create a process \n");
        printf("2. List all processes \n");
        printf("3. Stop a process \n");
        printf("4. Exit \n");
        int answer;
        scanf("%d", &answer);

        if(answer == 4)
        {
            end = 0;
            break;
        }
        else if(answer == 1)
        {
            printf("Enter processes name (up to 30 characters): \n");
            char name[31];
            scanf("%s", &name);
            //name[30] = '\0';

            int newid = createnewprocess(name);
            //printf("newid: %d\n", newid);
            if(newid == 0) printf("The max number of processes has been reached. A running processes must be stopped in order to create a new one!\n");
            else if(newid == -1) printf("No available ID number!");
            else printf("Process successfully created. ID is %d\n", newid);
        }
        else if(answer == 2)
        {
            //printf("processescount: %d", processescount);
            for(int i=0;i < processescount;i++)
            {
                printf("The ID of process %s is %d. \n", processes[i].name, processes[i].ID);
            }
        }
        else if(answer == 3)
        {
            printf("Enter prosses ID: \n");
            int id;
            scanf("%d", &id);

            stopprocess(id);
        }
    }
}