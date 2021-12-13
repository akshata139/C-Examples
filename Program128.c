
//Accept number and accept position from user and cheak whether that position bit is on or off.

#include<stdio.h>
#include<stdbool.h>

//if we use signed int then right first bit is reserverd , we cant use it thats why we used unsigned here.

typedef unsigned int UINT;

bool CheckBit(UINT iNo,UINT iPos)
{
	UINT iMask = 0x00000001;			//0000 0000 0000 0000 0000 1000 0100 1111
	UINT iResult = 0;				    // 0   0     0   0     0    0    0    F
									    // 0x0000000F
	
	if(iPos < 1 || iPos >32)
	{
		return false;
	}
	
	iMask = iMask << (iPos - 1);
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
	UINT iValue = 0,iBit = 0;
	bool bRet = false;
	 
	printf("Enter number.\n");
	scanf("%d",&iValue);
	
	printf("Enter position.\n");
	scanf("%d",&iBit);
	
	bRet = CheckBit(iValue,iBit);
	
	if(bRet == true)
	{
		printf("bit is ON\n");
	}
	else
	{
		printf("bit is off\n");
	}
	
	return 0;
}
 