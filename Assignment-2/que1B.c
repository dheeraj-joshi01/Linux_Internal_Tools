//Test whether the process(exec() system call) that replaces old program data , will inherit the fd's or not.

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd;
	
	char wbuff[100] = "This is to check if fd inherits or not.";

	fd = open("inherit_fd.txt", O_CREAT|O_RDWR, 0666);
	
	printf("File descriptor = %d\n",fd);

	write(fd, wbuff, strlen(wbuff));
	
	close(fd);
	
	return 0;
}
