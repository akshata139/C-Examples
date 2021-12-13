/*
owner - jyane creat keli to  can read write and can do anything
group - jo use karto to only read
other - nothing
read write and execute.
read 4
write 2
execute 1
 0 is for octal in 0777, 7 - owner ,7- group, 7- other
 owner all ,group read write, other write ,0764
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>

int main()
{
	int fd = 0;
	char Fname[30];
	
	printf("Enter file name \n");
	scanf("%s",Fname);
	
	fd = creat(Fname,0777);
	
	if(fd == -1)
	{
		printf("Unable to create the file \n");
	}
	else
	{
		printf("File successfully created \n");
	}
	
	return 0;
}