#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
	
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d| ->",Head -> data);
		Head = Head -> next;
	}
	printf("NULL\n");
}

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
	newn -> prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		(*Head) -> prev = newn;
		
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
	newn -> prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		newn -> prev = temp;
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
		newn -> prev = NULL;
		
		for(i = 1;i < (iPos - 1);i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		temp -> next = newn;
		newn -> prev = temp;
	}
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head) -> next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
	 PNODE temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
       
        temp->prev->next = NULL;
        free(temp);
    }
}

void DeleteAtPos(PPNODE Head,int iPos)
{
	int iSize = 0,i = 0;
	PNODE temp = *Head;
	
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
		for(i = 1;i < (iPos-1);i++)
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		free(temp -> next -> prev);
		temp -> next -> prev = temp;
	}
}

int main()
{
	int iChoice = 1,iValue = 0,position = 0,iRet = 0;
	PNODE first = NULL;
	
	while(iChoice != 0)
	{
		printf("Entered the desired choice you want to perform on linked list : \n");
		printf("__________________________________________________________________________\n");
		printf("1. Insert node at first position \n");
		printf("2. Insert node at last position \n");
		printf("3. Insert node at the desired position \n");
		printf("4. Delete first node \n");
		printf("5. Delete last node \n");
		printf("6. Delete node from the desired position \n");
		printf("7. Display the contents of the linked list \n");
		printf("8. Count the number of elements \n");
		printf("9. Terminate the application \n");
		printf("__________________________________________________________________________\n");
		
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
				printf("Entered the element you want to insert : \n");
				scanf("%d",&iValue);
				InsertFirst(&first,iValue);
				break;
				
			case 2:
				printf("Entered the element you want to insert : \n");
				scanf("%d",&iValue);
				InsertLast(&first,iValue);
				break;
				
			case 3:
				printf("Entered the element you want to insert : \n");
				scanf("%d",&iValue);
				printf("Enter position : \n");
				scanf("%d",&position);
				InsertAtPos(&first,iValue,position);
				break;
		
			case 4:
				DeleteFirst(&first);
				break;
				
			case 5:
				DeleteLast(&first);
				break;
				
			case 6:
				printf("Enter position \n");
				scanf("%d",&position);
				DeleteAtPos(&first,position);
				break;
				
			case 7:
				printf("Elements are : \n");
				Display(first);
				break;
				
			case 8:
				iRet = Count(first);
				printf("Total number of elements are : %d\n",iRet);
				break;
				
			case 0:
				printf("Thanks for using linked list !!\n");
				break;
				
			default:
				printf("Please entered valid choice \n");
				break;
		}
	}
	
	return 0;
}