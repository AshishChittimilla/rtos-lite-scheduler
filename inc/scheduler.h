
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

#define MAX_TASKS 5

typedef struct {
    void (*taskFunc)(void);
    uint32_t period_ms;
    uint32_t last_run;
} Task;

void Scheduler_Init(uint32_t tick_interval_ms);
void Scheduler_AddTask(void (*taskFunc)(void), uint32_t period_ms);
void Scheduler_Run(uint32_t current_time);

#endif
