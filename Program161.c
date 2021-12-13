/*
Accept file name from user read whole file and display it on screen.
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
	char Buffer[1024];   //mug  (1024 = default size of system buffer)
   	
	printf("Enter file name \n");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open the file \n");
		return -1;   //return to os.
	}
	else
	{
		printf("File successfully opened with FD :%d\n",fd);
	}
	
	printf("Data from file is : \n");
	
	while((iRet = read(fd,Buffer,sizeof(Buffer)) ) != 0)
	{
		write(1,Buffer,iRet);
	}
	close(fd);
	
	return 0;
}

/*
0 keybord
1 written to monitor system,out 1
system.in 0
2 error device
read function writen no. of bytes successfully from file
write 
kamit kami vela hardware vr jaychy.
*/