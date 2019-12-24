#include "task.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {	SUSPENDED, 
				RUNNING
} task_state;

typedef struct task
{
	task_state state;
	unsigned int num;
	unsigned int priority;
	void (*func)(void);
} task_t;

static unsigned int task_numbers=0;

task_handler_t task_construct (void)
{
	task_handler_t this = malloc(sizeof(struct task));
	this->num = task_numbers++;
	this->priority = 0;
	return this;
}


unsigned int task_get_priority(task_handler_t tsk)
{
	task_handler_t this = (task_handler_t)tsk;
	return this->priority;
}

void task_set_priority(task_handler_t tsk,int p_priority)
{
	task_handler_t this = (task_handler_t)tsk;
	this->priority = p_priority;
}

void task_suspend (task_handler_t tsk)
{
	task_handler_t this = (task_handler_t)tsk;
	this->state = SUSPENDED;
}
void task_resume (task_handler_t tsk)
{
	task_handler_t this = (task_handler_t)tsk;
	this->state = RUNNING;
}
void task_destroy (task_handler_t tsk)
{
	free(tsk);
}

void task_print_status(task_handler_t tsk)
{
	printf("task number:%d\n",tsk->num);
	printf("task priority:%d\n",tsk->priority);
	if(tsk->state == SUSPENDED)
		printf("task is suspended\n");
	else
		printf("task is running\n");
}

