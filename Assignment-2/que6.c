//program to call functions in reverse order using atexit()


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int a, b;

void multiply()
{
	int res = 0;

	res = a * b;
	printf("multiplication of 2 no's is: %d\n",res);
}

void add()
{ 
	int res = 0;

	res = a + b;
	printf("addition of 2 no's is: %d\n",res);
}

void sub()
{ 
	int res = 0;

	res = a - b;
	printf("difference of 2 no's is: %d\n",res);
}

int main()
{
	printf("Enter two numbers:\n");
	scanf("%d%d",&a, &b);
	
	atexit(multiply);
	
	atexit(sub);
	
	atexit(add);
	
	return 0;
	
}
