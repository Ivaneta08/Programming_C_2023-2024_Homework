#ifndef PROCESSES_H
#define PROCESSES_H

struct Process
{
    int ID;
    char name[31];
};

extern struct Process processes[5];
extern int processescount;

int createnewprocess(char processname[]);
void stopprocess(int stopid);

#endif