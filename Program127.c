
//Accept number from user and cheak whether the last four bits are on or off.

#include<stdio.h>
#include<stdbool.h>
//if we use signed int then right first bit is reserverd , we cant use it thats why we used unsigned here.
typedef unsigned int UINT;

bool CheckBit(UINT iNo)
{
	UINT iMask = 0X0000000F;			//0000 0000 0000 0000 0000 0000 0000 1111
	UINT iResult = 0;				    // 0   0     0   0     0    0    0    F
									    // 0x0000000F
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
		printf("4 bits are ON\n");
	}
	else
	{
		printf("4 bits are off\n");
	}
	
	return 0;
}
 