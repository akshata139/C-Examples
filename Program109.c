#include<stdio.h>
#include<string.h>

void StrRevX(char *);

int main()
{
	char Arr[50];
	
	printf("Enter a string.\n");
	scanf("%[^'\n']s",Arr);
	
	StrRevX(Arr);
	
	return 0;
}

void StrRevX(char *Str)
{
	char Brr[50];
	
	int iCnt = 0, i = 0, j = 0;
	while(*Str != '\0')
	{
		iCnt++;
	}
	
	j = iCnt - 1;
	
	for(i = 0; i < iCnt; i++)
	{
		Brr[i] = Str[j];
		j--;
	}
	
	printf("%s",Brr);
}
