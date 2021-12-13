#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE , *PNODE, **PPNODE;

int Count(PNODE Head)
{
	int iCnt = 0;
	
	while(Head != NULL)
	{
		iCnt++;
		Head = Head -> next;
	}
	
	return iCnt;
}

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = iNo;
	newn -> next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = iNo;
	newn -> next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while((temp-> next) != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn;
	}
}

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
	int iSize = 0,i = 0;
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	iSize = Count(*Head);
	
	if((iPos < 1) || (iPos > (iSize + 1)))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(Head,iNo);
	}
	else if(iPos == (iSize + 1))
	{
		InsertLast(Head,iNo);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn -> data = iNo;
		newn -> next = NULL;
		
		for(i = 1;i < (iPos - 1);i++)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn -> next;
		temp -> next = newn;
	}
	
}

void DeleteFirst(PPNODE Head)
{
	if(*Head != NULL)
	{
		*Head = (*Head) -> next;
		free(*Head);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head) == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while((temp -> next -> next) != NULL)
		{
			temp = temp -> next;
		}
		
		free(temp -> next);
		temp -> next = NULL;
	}
}

void DeleteAtPos(PPNODE Head,int iPos)
{
	int iSize = 0,i = 0;
	PNODE temp = *Head;
	PNODE targated = NULL;
	
	iSize = Count(*Head);
	
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if(iPos == iSize)
	{
		DeleteLast(Head);
	}
	else
	{
		for(i = 1;i < (iPos - 1);i++)
		{
			temp = temp -> next;
		}
		
		targated = temp -> next;
		temp -> next = targated -> next;
		free(targated);
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d| -> ",Head -> data);
		Head = Head -> next;
	}
	
	printf("NULL\n");
}

int main()
{
	PNODE First = NULL;
	int iChoice = 1,iValue = 0,Position = 0,iRet = 0;
	
	while(iChoice != 0)
	{
		printf("Entered the desired operation that you want to perform on linked list : \n");
		printf("_________________________________________________________________________________\n");
		printf("1. Insert node at the first position  \n");
		printf("2. Insert node at the last position  \n");
		printf("3. Insert node at the desired position \n");
		printf("4. Delete first node \n");
		printf("5. Delete last node \n");
		printf("6. Delete node at the desired position \n");
		printf("7. Display the elements of linked list \n");
		printf("8. Count the total number of elements from linked list \n");
		printf("0. Terminate the application \n");
		
		scanf("%d",&iChoice);
		printf("_________________________________________________________________________________\n");
		
		switch(iChoice)
		{
			case 1:
				printf("Entered element you want to insert : \n");
				scanf("%d",&iValue);
				InsertFirst(&First,iValue);
				break;
				
			case 2 :
				printf("Entered element you want to insert : \n");
				scanf("%d",&iValue);
				InsertLast(&First,iValue);
				break;
				
			case 3:
				printf("Entered element you want to insert : \n");
				scanf("%d",&iValue);
				printf("Entered position : \n");
				scanf("%d",&Position);
				InsertAtPos(&First,iValue,Position);
				break;
				
			case 4:
				DeleteFirst(&First);
				break;
				
			case 5:
				DeleteLast(&First);
				break;
				
			case 6:
				DeleteAtPos(&First,Position);
				break;
				
			case 7:
				printf("Elements are : \n");
				Display(First);
				break;
				
			case 8:
				iRet = Count(First);
				printf("Total number of elements are : %d\t",iRet);
				printf("\n");
				break;
				
			case 0:
				printf("Thanks for using linked list!!\n");
				break;
				
			default:
				printf("Entere proper choice! \n");
				break;
		}
	}
	
	return 0;
}