/*
O_RDWR it is macro.
O_RDONLY for read only
O_WRONLY for write only
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fd = 0;
	char Fname[30];
	
	printf("Enter file name \n");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open the file \n");
	}
	else
	{
		printf("File successfully opened with FD %d",fd);
	}
	
	return 0;
}