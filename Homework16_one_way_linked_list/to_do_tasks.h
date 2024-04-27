#ifndef TO_DO_TASKS_H
#define TO_DO_TASKS_H

typedef unsigned int uint;

#define TASK_LEN 60

typedef enum{
    NEW,
    STARTED,
    DONE
} Task_status;

typedef struct
{
    char task[TASK_LEN];
    Task_status status;
}To_do_task;

#endif