/*

1.Write a program which accept string and one character from user and count the number of that chracter .

*/

#include<stdio.h>

int CountFreq(char *, char);

int main()
{
	char Arr[50];
	char cValue;
	int iRet = 0;
	
	printf("Enter string.\n");
	scanf("%[^'\n']s",Arr);
	
	printf("Enter character :\n");
	scanf(" %c",&cValue);		//****IMPPPP
	
	iRet = CountFreq(Arr, cValue);
	
	printf("Number of Frequency is :%d\n",iRet);
	
	
	return 0;
}

int CountFreq(char *Str, char ch)
{
	int iCnt = 0;
	
	if(Str == NULL)
	{
		return -1;
	}
	
	while(*Str != '\0')
	{
		if(*Str == ch)
		{
			iCnt++;
		}
		
		Str++;
	}
	
	return iCnt;
}

