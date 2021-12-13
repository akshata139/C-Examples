#include<stdio.h>

int SmallCount(char *str)
{
	int iCnt = 0;
	
	while(*str != '\0')
	{
		
		if((*str >= 'a') && (*str <= 'z'))
		{
			iCnt++;
		}
		str++;
	}
	return iCnt;
}

int main()
{
	char Arr[50];
	int iRet = 0;
	
	
	printf("Enter  character.\n");
	scanf("%[^'\n']s",Arr);
	
	iRet = SmallCount(Arr);
	
	printf("Number of small character in the given string is : %d\n",iRet);
	
	return 0;
	
}