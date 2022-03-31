// Q3.Write a pthread program that implements simple initialization code.


#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_once_t the_init_code = PTHREAD_ONCE_INIT;

void *thd_init()		//defining init function
{
	printf("--->>> initializing command sequence <<<---\n");
}

void *thd_task(void *args)		//defining thread task
{
	printf("Inside thread -> %d\n",(int *)args);
	
	pthread_once(&the_init_code , (void *)thd_init);		//calling init function

	printf("Exiting from thread %d\n", (int *)args);

	return NULL;
}

int main()
{
	pthread_t thd_1, thd_2, thd_3;

	//creating threads
	pthread_create(&thd_1, NULL, thd_task, (void *)1);
	pthread_create(&thd_2, NULL, thd_task, (void *)2);
	pthread_create(&thd_3, NULL, thd_task, (void *)3);

	//joining with parent process
	pthread_join(thd_1, NULL);
	pthread_join(thd_2, NULL);
	pthread_join(thd_3, NULL);

	return 0;
}
