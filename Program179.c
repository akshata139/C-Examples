/*

accept file name from user and calculate size of file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<io.h>

int main()
{
	int fd = 0,iRet = 0,iSum = 0,i = 0;
	char Fname[40];
	char Buffer[10];

	printf("Enter file name : ");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open file !!\n");
		return -1;
	}
	
	while((iRet = read(fd,Buffer,10)) != 0)
	{
		iSum = iRet + iSum;
	}
	
	printf("Size of file is : %d \n",iSum);
	
	close(fd);
	
	return 0;
}

/*
ya program mdhe hardware io kel
u have to reduce no of hardeware operation
*/