/*

1.Write a program which accept string from user and count the number of vowels.
*/

#include<stdio.h>

int Count(char *);

int main()
{
	char Arr[50];
	int iRet = 0;
	
	printf("Enter string.\n");
	scanf("%[^'\n']s",Arr);
	
	iRet = Count(Arr);
	
	printf("Number of vowels are :%d\n",iRet);
	
	
	return 0;
}

int Count(char *Str)
{
	int iCnt = 0;
	
	if(Str == NULL)
	{
		return -1;
	}
	
	while(*Str != '\0')
	{
		if((*Str == 'a') || (*Str == 'e') || (*Str == 'i') || (*Str == 'o') || (*Str == 'u') || (*Str == 'A') || (*Str == 'E') || (*Str == 'O') || (*Str == 'I') || (*Str == 'U'))
		{
			iCnt++;
		}
		
		Str++;
	}
	
	return iCnt;
}

