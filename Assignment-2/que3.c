//program that replaces old program with new program data and is expected to display the currently running processes in a hierarchical tree format.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	
	printf("pid of the current process = %d\n", getpid());

	printf("Replacing old program with new data using execl() system call\n");
	execl("/usr/bin/pstree", "pstree", 0);

	printf("Exiting main program\n");

	return 0;
}
