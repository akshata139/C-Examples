
//Accept number and accept two position from user and cheak whether that position bit is on or off.

#include<stdio.h>
#include<stdbool.h>

typedef unsigned int UINT;

UINT CheckBit(UINT iNo, UINT iPos1, UINT iPos2)
{
	UINT iResult = 0;
	UINT iMask1 = 0x00000001;
	UINT iMask2 = 0x00000001;
	UINT iMask3;
	
	iMask1 = iMask1 << (iPos1 - 1);
	iMask2 = iMask2 << (iPos2 - 1);
	
	iMask3 =  iMask1 | iMask2;
	iResult = iNo & iMask3;
	
	if(iMask3 == iResult)
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
	UINT iValue = 0,iBit1 = 0,iBit2 = 0;
	bool bRet = false;
	
	printf("Enter number .\n");
	scanf("%d",&iValue);
	
	printf("Enter 1st position :\n");
	scanf("%d",&iBit1);
	
	printf("Enter 2nd position :\n");
	scanf("%d",&iBit2);
	
	bRet = CheckBit(iValue,iBit1,iBit2);
	
	if(bRet == true)
	{
		printf("Bits are on.\n");
	}
	else
	{
		printf("Bits are off.\n");
	}
	
	return 0;
}