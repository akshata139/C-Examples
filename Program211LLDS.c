#include<stdio.h>
#include<stdlib.h>

struct node
{
	int Data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	
	//step1 : allocate the memory;
	newn = (PNODE)malloc(sizeof(NODE));

	//step2 : initialise the data;
	newn->Data = iNo;
	newn->next = NULL;
	
	//step3 : insert the node;
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	//step1 : allocate the memory;
	newn = (PNODE)malloc(sizeof(NODE));
	
	//step2 : initialise the data;
	newn -> Data = iNo;
	newn -> next = NULL;
	
	//step3 : insert the node;
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while((temp -> next) != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn;
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d\t",Head -> Data);
		Head = Head -> next;
	}
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

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head != NULL)
	{
		*Head = (*Head) -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head == NULL)		//LL is empty
	{
		return;
	}
	else if((*Head) -> next == NULL)		//LL contains only one node;
	{
		free(*Head);
		*Head = NULL;
	}
	else			//LL contains more than one node.
	{
		while((temp -> next -> next) != NULL)
		{
			temp = temp -> next;
		}
		free(temp -> next);
		temp -> next = NULL;
	}
}

int main()
{
	PNODE First = NULL;
	int iRet = 0;
	
	printf("Elements are : \n");
	
	InsertFirst(&First,1);
	InsertFirst(&First,7);
	InsertFirst(&First,13);
	InsertFirst(&First,16);
	
	InsertLast(&First,45);
	InsertLast(&First,4);

	Display(First);
	
	iRet = Count(First);
	printf("\n Total number of elements are : %d\t",iRet);
	
	DeleteFirst(&First);
	printf("\n After delete first node: \t");
	Display(First);
	
	DeleteLast(&First);
	printf("\n After delete last node: \t");
	Display(First);
	
	return 0;
}