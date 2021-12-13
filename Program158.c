/*
open file write and close the file.
main function can return 3 values 0= successfully done. -1 = something error occured
open wants 2 parameters (kay,kashasathi)
write wants 3 parameters(kashat,kay,kiti)
printf internally calls write.
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
	char Data[7];
   	
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
	
	iRet = read(fd,Data,7);
	
	write(1,Data,iRet);  //1 is stdout(monitor)
	
	close(fd);
	
	return 0;
}