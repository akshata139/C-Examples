/*

accept file name from user and count no. of vowels.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<io.h>

int main()
{
	int fd = 0,iRet = 0,iCnt = 0,i = 0;
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
		for(i = 0;i < iRet;i++)
		{
			if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
			{
				iCnt++;
			}
		}
	}
	
	printf("Total number of Capital letters are : %d \n",iCnt);
	
	close(fd);
	
	return 0;
}

/*
iRet if size of file is 57 then at the last 7 bytes rahanare tysathi iret use kela kuthlahi inbuild function use kryach
 nahi
 */