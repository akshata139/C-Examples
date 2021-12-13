//Reverse string

#include<stdio.h>
#include<stdbool.h>

bool CheckPall(char *);

int main()
{
	char Arr[50];
	bool bRet = false;
	
	printf("Enter string.\n");
	scanf("%[^'\n']s",Arr);
	
	bRet = CheckPall(Arr);
	
	if(bRet == true)
	{
		printf("String is Pallindrom!!\n");
	}
	else
	{
		printf("String is not pallindrom!!\n");
	}
	
	return 0;
}

bool CheckPall(char *Str)
{
	bool bAns = true;
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
		
		*Start++;
		*End--;
	}
	
	return bAns;
}