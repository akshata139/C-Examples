/*

1.Write a program which accept string from user and accept one character. Check whether that character is present in string 
or not.

*/

#include<stdio.h>
#include<stdbool.h>

bool Check(char *,char);

int main()
{
	char cInput, Arr[50];
	bool bRet = false;
	
	printf("Enter character :\n");
	scanf("%c",&cInput);
	
	printf("Enter string.\n ");
	scanf("%[^'\n']s",Arr);
	
	bRet = Check(Arr, cInput);
	
	if(bRet == true)
	{
		printf("Character is present.\n");
	}
	else
	{
		printf("Character is not present.\n");
	}
	
	return 0;
}

bool Check(char *Str, char cVal)
{
	bool bAns = false;
	
	if(Str == NULL)
	{
		return -1;
	}
	
	while(*Str != '\0')
	{
		if(*Str = cVal)
		{
			bAns = true;
		}
		
		else
		{
			bAns = false;
		}
		
		Str++;
	}
	
	return bAns;
}