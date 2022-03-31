// Q5. Write a program that implements threads synchronization using pthread spinlock techniques


#include<stdio.h>
#include<pthread.h>

static pthread_spinlock_t the_spin_lock;		//declare spin lock

void *thd_task_1(void *args)				//defining thread 1 task
{
	printf("Inside thread 1 task....\n");

	printf("Entering thread 1 spin lock....\n");
	
	pthread_spin_lock(&the_spin_lock);		//apply lock

	/** Critical section starts **/

	printf("Hey, this is thread 1 sending signals from critical section.\n");
	
	printf("Starting countdown sequence from 20....\n");
	
	for(int i=20; i>0; i++)
		printf("%d\n",i);

	/** Critical section ends **/

	pthread_spin_unlock(&the_spin_lock);		//release lock
	
	printf("Lock released...\nExiting from thread 1..\n");

	return NULL;
}

void *thd_task_2(void *args)				//defining thread 2 task
{
	printf("Inside thread 2 task....\n");

	printf("Entering thread 2 spin lock....\n");
	
	pthread_spin_lock(&the_spin_lock);		//apply lock

	/** Critical section starts **/

	printf("Hey, this is thread 2 sending signals from critical section.\n");
	
	printf("Starting countdown sequence from 10....\n");
	
	for(int i=10; i>0; i++)
		printf("%d\n",i);

	/** Critical section ends **/

	pthread_spin_unlock(&the_spin_lock);		//release lock
	
	printf("Lock released...\nExiting from thread 2..\n");

	return NULL;
}

int main()
{
	pthread_t my_thd1, my_thd2;

	printf("Inside Main thread: %ld\n",pthread_self());

	if(pthread_spin_init(&the_spin_lock, PTHREAD_PROCESS_PRIVATE) != 0)
		perror("spin init");

	//create 2 threads
	pthread_create(&my_thd1, NULL, thd_task_1, NULL);
	pthread_create(&my_thd2, NULL, thd_task_2, NULL);

	//joining threads with the main thread
	pthread_join(my_thd1, NULL);
	pthread_join(my_thd2, NULL);

	printf("Exiting from Main thread\n");

	return 0;
}
