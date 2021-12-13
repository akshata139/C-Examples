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
	int fd = 0,iRet = 0;
	char Fname[40];

	printf("Enter file name : ");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open file !!\n");
		return -1;
	}
	iRet = lseek(fd,0,2);
	
	printf("Size of file is : %d bytes\n",iRet);
	
	close(fd);
	
	return 0;
}
//defination of file - unformatted stream of uniform bytes.