/*

accept existing file from user and accept one strig write that string at the end of file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<io.h>

int main()
{
	/*
	potential hole(potential kshamata ahe data store karnyachi)
	how to create hole
	lseek(fd,10,2)
	write(fd," ",1)
	*/
	
	int fd = 0;
	char Arr[10];
	
	fd = open("LB17.txt",O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open file !!\n");
	}
	
	//0 - from starting position
	//1 - from current position
	//2 - from end of the file
	
	lseek(fd,-5,2);  //(kashat,kuthparyant,kuthun)
	read(fd,Arr,5);
	
	printf("Data from file is :\n");
	
	write(1,Arr,5);
	
	close(fd);
	
	return 0;
}