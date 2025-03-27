
#include "scheduler.h"

static Task taskList[MAX_TASKS];
static uint8_t taskCount = 0;

void Scheduler_Init(uint32_t tick_interval_ms) {
    for (int i = 0; i < MAX_TASKS; i++) {
        taskList[i].taskFunc = 0;
        taskList[i].period_ms = 0;
        taskList[i].last_run = 0;
    }
}

void Scheduler_AddTask(void (*taskFunc)(void), uint32_t period_ms) {
    if (taskCount < MAX_TASKS) {
        taskList[taskCount].taskFunc = taskFunc;
        taskList[taskCount].period_ms = period_ms;
        taskList[taskCount].last_run = 0;
        taskCount++;
    }
}

void Scheduler_Run(uint32_t current_time) {
    for (int i = 0; i < taskCount; i++) {
        if ((current_time - taskList[i].last_run) >= taskList[i].period_ms) {
            taskList[i].last_run = current_time;
            if (taskList[i].taskFunc) {
                taskList[i].taskFunc();
            }
        }
    }
}
