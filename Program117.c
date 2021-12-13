/*

1.Write a program which accept string from user and revese that string in a place.

*/

#include<stdio.h>

void StrRevX(char *);

int main()
{
	char Arr[50];
	
	printf("Enter string.\n");
	scanf("%[^'\n']s",Arr);
	
	StrRevX(Arr);
	
	printf("Reverse Strign is: %s\n",Arr);
	
	return 0;
}

//*Str - Data & Str - Address

void StrRevX(char *Start)
{
	char *End = Start;
	char temp;
	
	while(*End != '\0')
	{
		End++;
	}
	End--;
	
	while(Start < End)
	{
		temp = *Start;
		*Start = *End;
		*End = temp;
		
		Start++;
		End--;
	}
}

 