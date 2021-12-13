//Reverse string

#include<stdio.h>

void StrRevX(char *Str)
{
	char temp;
	char *End = NULL;
	
	End = Str;
	
	while(*End != '\0')
	{
		End++;
	}
	End--;
	
	while(Str < End)
	{
		temp = *Str;
		*Str = *End;
		*End = temp;
		
		*Str++;
		*End--;
	}
}
int main()
{
	char Arr[50];
	
	printf("Enter string.\n");
	scanf("%[^'\n']s",Arr);
	
	StrRevX(Arr);
	
	printf("Reverse String is: %s\n",Arr);
	
	return 0;
}