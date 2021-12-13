
//Accept number from user and cheak whether the fourth bit is on or off.

#include<stdio.h>
#include<stdbool.h>
//if we use signed int then right first bit is reserverd , we cant use it thats why we used unsigned here.
typedef unsigned int UINT;

bool CheckBit(UINT iNo)
{
	UINT iMask = 0X00000008;
	UINT iResult = 0;
	
	iResult = iNo & iMask;
	
	if(iResult == iMask)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	UINT iValue = 0;
	bool bRet = false;
	 
	printf("Enter number.\n");
	scanf("%d",&iValue);
	
	bRet = CheckBit(iValue);
	
	if(bRet == true)
	{
		printf("4th bit is ON\n");
	}
	else
	{
		printf("4th bit is off\n");
	}
	
	return 0;
}
 