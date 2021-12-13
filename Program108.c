#include<stdio.h>

char StrRevX(char *);

int main()
{
	char Arr[50];
	char cRet[50];
	
	printf("Enter a string.\n");
	scanf("%[^'\n']s",Arr);
	
	cRet[50] = StrRevX(Arr);
	printf("Reverse string is :%s",cRet);
	
	return 0;
}

char StrRevX(char *Str)
{
	char *iRev;
	
	for(*Str = '\0'; *Str >= 0; *Str--)
	{
		*iRev = *Str;
	}
	
	return *iRev;
}
