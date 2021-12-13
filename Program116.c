//Accept two characters and swap them.

#include<stdio.h>

void Swap(char *,char *);

int main()
{
	char ch1, ch2;
	
	printf("Enter 1st character \n");
	scanf("%c",&ch1);
	
	printf("Enter 2nd character \n");
	scanf(" %c",&ch2);
	
	printf("Before swapping characters are %c %c\n",ch1,ch2);
	
	Swap(&ch1,&ch2);
	
	printf("After swapping characters are %c %c \n",ch1,ch2);
	
	return 0;
}

void Swap(char *p,char *q)
{
	char temp;
	temp = *p;
	*p = *q;
	*q = temp;
}