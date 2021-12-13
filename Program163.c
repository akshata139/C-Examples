/*

create a new file write , read and display the contents on the screen.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<io.h>

int main()
{
	int fd = 0,iRet1 = 0,iRet2 = 0;
	char Fname[40];
	char Buffer[1024];
	char Str[100];
	
	printf("Enter file name :");
	scanf("%s",Fname);
	
	fd = creat(Fname,0777);
	
	if(fd == -1)
	{
		printf("Unable to creat File.\n");
	}
	else
	{
		printf("File created successfully!!\n");
	}
	
	printf("Enter string : ");
	scanf("%[^'\n']s",&Str);
	
	fd = open(Fname,O_RDWR);
	printf("File opened successfully with fd %d \n",fd);
	
	iRet1 = write(fd,Str,sizeof(Str));
	
	printf(" written Data is :\n");
	while((iRet2 = read(iRet1,Buffer,sizeof(Buffer))) != 0)
	{
		write(1,Buffer,iRet2);
	}
	
	close(fd);
	
	return 0;
}