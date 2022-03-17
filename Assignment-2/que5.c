//program to read file from child process and save it 

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int child;
	int fd;
	
	char buff[100];			//empty buffer
	
	child = fork();		//creating child process
	
	if(child == 0)
	{
		//child process code
		
		fd = open("file.txt",O_RDONLY,0777);
		read(fd, buff, 75);
		
		//printing the read data
		printf("\nData read from file is : \n");
		printf("%s\n",buff);
		
		close(fd);
	}
	
	else
	{
		//parent process code
		
		printf("Parent process to be put on hold till child executes\n");
		int w = wait(0);
		printf("Parent process called\n");
	}
	
	return 0;
}
