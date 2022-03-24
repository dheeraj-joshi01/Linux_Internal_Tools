//Write a program that implements threads synchronization using mutex techniques.
//op on global var using mutex lock
//this program executes 1 thread at a time

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


int globalVar = 10;		//global variable declared

pthread_mutex_t my_mutex;			//creating mutex lock

//increase globalVar by 15
void* global_increase(void *arg)
{
	pthread_mutex_lock(&my_mutex);		//apply lock
	
	globalVar += 15;		//critical section
	
	pthread_mutex_unlock(&my_mutex);	//release lock
	
	printf("increased value = %d\n",globalVar);
}


//decrease globalVar by 5
void* global_decrease(void *arg)
{
	pthread_mutex_lock(&my_mutex);		//apply lock
	
	globalVar -= 5;				//critical section

	pthread_mutex_unlock(&my_mutex);	//release lock
	
	printf("decreased value = %d\n",globalVar);
}


void main()
{
	pthread_t tid1, tid2;
	
	pthread_mutex_init(&my_mutex, NULL);		//initialize mutex lock
	
	pthread_create(&tid1, NULL, global_increase, NULL);
	pthread_create(&tid2, NULL, global_decrease, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("global variable is : %d\n", globalVar);
	
}
