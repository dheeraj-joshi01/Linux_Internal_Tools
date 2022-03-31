// Q2.Write a program where a structure of information passed to pthread task function, and display structure of information.

#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct emp_info		//struct to store employee data
{
	int eID;
	int salary;
	char name[30];
};

void *thd_task(void *args)		//function to define thread task
{
	struct emp_info *e = (struct emp_info *)args;

	printf("Employee_ID: %d\nName: %s\nSalary: %d\n",e->eID, e->name, e->salary);

	return NULL;
}

int main()
{
	struct emp_info emp1;

	pthread_t new_tid;

	emp1.eID = 150;
	strcpy(emp1.name, "Kartik Kumar");
	emp1.salary = 75000;

	pthread_create(&new_tid, NULL, thd_task, &emp1);

	pthread_join(new_tid, NULL);

	pthread_exit(NULL);

	return 0;
}
