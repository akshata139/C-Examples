#include<stdio.h>

int CountA(char *);

int main()
{
	char Arr[50];
	int iRet = 0;
	
	printf("Enter string.\n");
	scanf("%[^'\n']s",Arr);
	
	iRet = CountA(Arr);
	printf("Number of A's in the given string is :%d",iRet);
	
	return 0;
}

int CountA(char *Str)
{
	int iCnt = 0;
	
	if(Str == NULL)
	{
		return -1;
	}
	
	while(*Str != '\0')
	{
		if((*Str >= 0) && (*Str <= 255))
		{
			if(*Str == 'A' || *Str == 'a')
			{
				iCnt = iCnt + 1;
			}
		}
		
		*Str++;	
	}
	return iCnt;
}

