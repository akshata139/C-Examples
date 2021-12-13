
//Accept decimal number and convert it into binary. 

#include<stdio.h>

void DisplayBinary(int);

int main()
{
	int iValue = 0;
	 
	printf("Enter number.\n");
	scanf("%d",&iValue);
	 
	DisplayBinary(iValue);
	 
	return 0;
}
 
void DisplayBinary(int iNo)
{
	int iDigit = 0;
	
	while(iNo != 0)
	{
		iDigit = iNo % 2;
		printf("%d",iDigit);
		
		iNo = iNo / 2;
	}
}