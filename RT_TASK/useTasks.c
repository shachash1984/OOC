#include<stdio.h>

#include "task.h"


int main()
{
	// TODO: 
	// create 2 tasks
	//		1. with priority 10 and running
	//		2. with priority 5 and suspended
	// print tasks status
	// destroy tasks
	task_handler_t t1 = task_construct();
	task_set_priority(t1, 10);
	task_resume(t1);

	task_handler_t t2 = task_construct();
	task_set_priority(t2, 5);
	task_suspend(t2);

	task_print_status(t1);
	task_print_status(t2);

	task_destroy(t1);
	task_destroy(t2);


	return 0;
}