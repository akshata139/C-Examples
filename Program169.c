/*

accept existing file from user and accept one strig write that string at the end of file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<io.h>
//abcdefghijklmnopqrstuvwxyz

int main()
{
	int fd = 0;
	char Arr[10];
	
	fd = open("LB17.txt",O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open file !!\n");
		return -1;
	}
	
	//0 - from starting position
	//1 - from current position
	//2 - from end of the file
	
	lseek(fd,5,0);  //(kashat,kuthparyant,kuthun)
	
	read(fd,Arr,5);
	write(1,Arr,5);
	printf("\n");
	
	lseek(fd,5,1);
	
	read(fd,Arr,5);
	write(1,Arr,5);
	
	close(fd);
	
	return 0;
}