/*****************************************************************************************************************
Q1.Write a pthread application where main task terminated but pending pthreads task still execute.
*****************************************************************************************************************/

#include<stdio.h>
#include<pthread.h>

void *f_th_fun(void *arg)
{

	for(int i=1; i<=10; i++)
	{
		printf("Thread function exicution : %d\n",i);
	}

	printf("Exiting thread\n");
}

int main()
{
	pthread_t f_t_id;//generating Thread Id
	
	pthread_create(&f_t_id, NULL, f_th_fun, NULL); //pthread_create arguments 

	pthread_join(f_t_id, NULL);//for joining pthread

	pthread_exit(NULL); //for exiting the pthread 
	printf("Main thread terminated\n");

	return 0;
}
