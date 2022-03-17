//creation of 2 child process to run two seperate tasks

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int pid1, pid2;
	
	pid1 = fork();		//making 1st child process
		
	if(pid1 == 0)
	{
		//child 1 executing
		
		printf("\nchild 1 in execution\n");
		printf("child 1 PID - %d\n", getpid());
		printf("Parent PID of child 1 - %d\n", getppid());
		
		printf("child 1 executing 'ls -l' command\n");
		execl("/bin/ls", "ls", "-l", NULL);//parent process
	}
	
	
	else
	{
			//sleep(1);
		
		pid2 = fork();		//making 2nd child process
	
		if(pid2 == 0)
		{
			//child 2 executing
			
			sleep(1);
			printf("\nchild 2 in execution\n");
			printf("child 2 PID - %d\n", getpid());
			printf("Parent PID of child 2 - %d\n", getppid());
			printf("child 2 creating data.txt\n");
			execl("/bin/touch", "touch", "data.txt",NULL);	
		}
		
		
		else
		{
			//parent process executing
			
			sleep(3);
			printf("\nparent process executing\n");
			printf("parent PID - %d\n", getpid());
		}
		
	}
	
	return 0;
}
