/*

creat hole in the file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<io.h>

int main()
{
	int fd = 0;

	fd = open("LB17.txt",O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open file !!\n");
		return -1;
	}

	lseek(fd,10,2);  //(kashat,kuthparyant,kuthun)
	
	write(fd," ",1);
	
	close(fd);
	
	return 0;
}

//actual size 1 kb
//size of disk 1kb = 1024