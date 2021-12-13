#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool Display(int *,int,int);

int main()
{
	int *Arr = NULL;
	int iSize = 0, iCnt = 0, iNo = 0;
	bool bRet = false;
	
	printf("Enter number of elements you want to display.\t");
	scanf("%d",&iSize);
	
	printf("Enter number.\n ");
	scanf("%d",&iNo);
	
	Arr = (int*)malloc( sizeof(int) * iSize);
	
	if(Arr == NULL);
	{
		return -1;
		printf("Unable to allocate memory.\n");
	}
	
	printf("Enter elements :\n");
	
	for(iCnt = 0;iCnt < iSize;iCnt++)
	{
		scanf("%d",&Arr[iCnt]);
	}
	
	printf("Enter elements are :\n");
	
	for(iCnt = 0;iCnt < iSize;iCnt++)
	{
		printf("%d\t",Arr[iCnt]);
	}
	
	bRet = Display(Arr,iSize,iNo);
	
	if(bRet == true)
	{
		printf("Divisble of the given number are present in array!!\n");
	}
	else
	{
		printf("Divisble of the given number are not present in array!!\n");
	}
	return 0;
}

bool Display(int *Brr,int iLen,int iVal)
{
	int iCnt = 0;
	bool bAns = false;
	
	for(iCnt = 0; iCnt < iLen; iCnt++)
	{
		if((*Brr % iVal)== 0)
		{
			bAns = true;
		}
		else
		{
			bAns = false;
		}
	}
	
	return bAns;
}