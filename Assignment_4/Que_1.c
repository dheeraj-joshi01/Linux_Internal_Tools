// Q1.Write a pthread application where main task terminated but pending pthreads task still execute.


#include<stdio.h>
#include<pthread.h>

void *thd_task()			//defination of thread task function
{

	for(int i=0; i<10; i++)
	{
		printf("Executing Thread function : %d\n",i+1);
	}

	printf("Exiting from thread\n");
}

int main()
{
	pthread_t my_thd_id;
	
	pthread_create(&my_thd_id, NULL, thd_task, NULL); 	//create pthread and assign task 

	pthread_join(my_thd_id, NULL);				//for executing thread before parent process

	pthread_exit(NULL); 					//for exiting the pthread 
	
	printf("Executing Main Now\n");

	return 0;
}
