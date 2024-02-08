#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "processes.h"

struct Process processes[5];
int processescount = 0;

static unsigned int currentid = 0;
static int nextprocessid()
{
    if(currentid == UINT_MAX)return 0;
    else
    {
        currentid++;
        return currentid;
    }
}

int createnewprocess(char processname[])
{
    //printf("processescount: %d\n", processescount);

    if(processescount < 5)
    {
        processes[processescount].ID = nextprocessid();

        //printf("processes[processescount].ID : %d\n", processes[processescount].ID);

        if(processes[processescount].ID == 0)return -1;
        /*
        int i;
        for(i=0; name[i] != '\0'; i++)
        {
            processes[processescount].name[i] = name[i];
        }
        processes[processescount].name[i] = '\0';
        */
       strcpy(processes[processescount].name, processname);

        processescount++;
        return processes[processescount-1].ID;
    }
    return 0;
}

void stopprocess(int stopid)
{
    int i, found=0;
    for(i=0;i < processescount;i++)
    {
        if(processes[i].ID == stopid)
        {
            found=1;
            break;
        }
    }
    if(found)
    {
        for(i+=1;i < processescount;i++)
        {
            processes[i-1].ID = processes[i].ID;
            strcpy(processes[i-1].name, processes[i].name);
        }
        processescount--;
    }
}