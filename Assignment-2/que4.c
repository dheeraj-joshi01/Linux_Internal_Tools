//A process using execl() system call should replace a new command line program.

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("program to replace command line program\n\nDisplaying present working directory\n");

	execl("/bin/pwd", "pwd", 0);

	return 0;
}
