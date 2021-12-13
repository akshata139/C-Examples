/*
open file write and close the file.
main function can return 3 values 0= successfully done. -1 = something error occured
open wants 2 parameters (kay,kashasathi)
write wants 3 parameters(kashat,kay,kiti)
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	//fd file descriptor.
	int fd = 0,iRet = 0;
	char Fname[30];
	char Data[] = "Marvellous Infosystems";
   	
	printf("Enter file name \n");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open the file \n");
		return -1;   //return to os.
	}
	else
	{
		printf("File successfully opened with FD :%d\n",fd);
	}
	
	iRet = write(fd,Data,22);
	printf("%d bytes gets Successfully written in the file\n",iRet);
	
	return 0;
}