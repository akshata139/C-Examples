#include<stdio.h>

void Count(char *str)
{
	int cCnt = 0,sCnt = 0;
	
	while(*str != '\0')
	{
		
		if((*str >= 'A') && (*str <= 'Z'))
		{
			cCnt++;
		}
		else if((*str >= 'a') && (*str <= 'z'))
		{
			sCnt++;
		}
		
		str++;
	}
	printf("Capital letters are :%d\t",cCnt);
	printf("Small letters are :%d\t",sCnt);
}

int main()
{
	char Arr[50];
	
	printf("Enter  character.\n");
	scanf("%[^'\n']s",Arr);
	
	Count(Arr);
	
	return 0;
	
}