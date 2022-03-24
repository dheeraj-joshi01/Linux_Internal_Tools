//Write a program that changes the default properties of newly created posix threads.

//changing stack size


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>


void* func1(void *param)
{
	printf("This is pthread creation using user attributes\n");
	sleep(2);
	
	return NULL;
}




int main(void)
{
	pthread_attr_t myAttr;
	pthread_t tid1;
	
	void *stck;
	size_t siz;
	int err;
	
	size_t my_stksize = 300000;
	void * my_stack;
	
	pthread_attr_init(&myAttr);			//init attribute
	pthread_attr_getstacksize(&myAttr, &siz);	//get size of stack
	pthread_attr_getstackaddr(&myAttr, &stck);	//get stack address
	
	printf("default address of stack : %08x  -->> default size of stack : %d\n", stck, siz);
	
	my_stack = (void*)malloc(my_stksize);		//define a new stack with attributes of our choice
	
	pthread_attr_setstack(&myAttr, my_stack, my_stksize);			//set stack
	
	pthread_create(&tid1, &myAttr, func1, NULL);
	
	
	pthread_attr_getstack(&myAttr, &stck, &siz);			//get info of new stack
	
	printf("\ndefault address of stack : %08x  -->> default size of stack : %d\n", stck, siz);
	
	return 0;
}


//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	
