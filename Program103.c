#include<stdio.h>

int CapitalCount(char *str)
{
	int iCnt = 0;
	
	while(*str != '\0')
	{
		
		if((*str >= 'A') && (*str <= 'Z'))
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
	
	iRet = CapitalCount(Arr);
	
	printf("Number of Capital character in the given string is : %d\n",iRet);
	
	return 0;
	
}