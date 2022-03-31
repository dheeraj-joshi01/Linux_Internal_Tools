// Q4.write a program, which get and set pthread scheduling policy and priority.

#include<stdio.h>
#include<pthread.h>

int main()
{
	pthread_t thd_id;

	struct sched_param thd_prm;

	int policy;

	pthread_getschedparam(pthread_self(), &policy, &thd_prm);			//getting policy/priority of parent process
	
	printf("Default sched policy : \n\npolicy: %d \npriority: %d\n",policy, thd_prm.sched_priority);

	//setting user defined policy/priority

	policy = SCHED_FIFO;
	thd_prm.sched_priority = 4;

	pthread_setschedparam(pthread_self(), policy, &thd_prm);

	pthread_getschedparam(pthread_self(), &policy, &thd_prm);

	printf("\nAfter Setting user defined sched policy : \n\npolicy: %d \npriority: %d\n",policy, thd_prm.sched_priority);

	return 0;
}
