/*

accept existing file from user and accept one strig write that string at the end of file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<io.h>

int main()
{
	int fd = 0;
	char Fname[40];
	char Arr[] = "Hello!!";
	
	printf("Enter file name : ");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDWR | O_APPEND);
	
	if(fd == -1)
	{
		printf("Unable to open file !!\n");
	}
	
	write(fd,Arr,7);
	
	close(fd);
	
	return 0;
}