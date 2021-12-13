/*

1.Write a program which accept string from user and Check whether string is pallindrom or not.

*/

//time complexity of this progarm is (N +(N/2))

#include<stdio.h>
#include<stdbool.h>

bool CheckPallindrom(char *);

int main()
{
	char Arr[50];
	bool bRet = false;
	
	printf("Enter string.\n");
	scanf("%[^'\n']s",Arr);
	
	bRet = CheckPallindrom(Arr);
	
	if(bRet == true)
	{
		printf("String is Pallindrome!!\n");
	}
	else
	{
		printf("String is not Pallindrome!!\n");
	}
	
	
	return 0;
}

//*Str - Data & Str - Address

bool CheckPallindrom(char *Str)
{
	bool bAns = false;
	char *Start = NULL;
	char *End = NULL;
	
	Start = Str;
	End = Str;
	
	while(*End != '\0')
	{
		End++;
	}
	End--;
	
	while(Start < End)
	{
		if(*Start != *End)
		{
			bAns = false;
			break;
		}
		else
		{
			bAns = true;
		}
		Start++;
		End--;
	}
	
	return bAns;

}

