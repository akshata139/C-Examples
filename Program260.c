//Menue driven code of BST.

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
	
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = iNo;
	newn -> lchild = NULL;
	newn -> rchild = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(1)
		{
			if((temp -> data) == iNo)
			{
				free(newn);
				break;
			}
			else if(iNo > (temp -> data))
			{
				if((temp -> rchild) == NULL)
				{
					temp -> rchild = newn;
					break;
				}
				temp = temp -> rchild;
			}
			else if(iNo < (temp -> data))
			{
				if(temp -> lchild == NULL)
				{
					temp -> lchild = newn;
					break;
				}
				temp = temp -> lchild;
			}
		}
	}
}

bool Search(PNODE Head,int iNo)
{
	bool bAns = false;
	
	if(Head == NULL)
	{
		return false;
	}
	else
	{
		while(Head != NULL)
		{
			if(iNo == (Head-> data))
			{
				bAns = true;
				break;
			}
			else if(iNo > (Head -> data))
			{
				Head = Head -> rchild;
			}
			else if(iNo < (Head -> data))
			{
				Head = Head -> lchild;
			}
		}
		
		return bAns;
	}
}

void Inorder(PNODE Head)
{
	if(Head != NULL)
	{
		Inorder(Head -> lchild);
		printf("%d",Head -> data);
		printf("\n");
		Inorder(Head -> rchild);
	}
}

void Preorder(PNODE Head)
{
	if(Head != NULL)
	{
		printf("%d",Head -> data);
		printf("\n");
		Preorder(Head -> lchild);
		Preorder(Head -> rchild);
	}
}

void Postorder(PNODE Head)
{
	if(Head != NULL)
	{
		Postorder(Head -> lchild);
		Postorder(Head -> rchild);
		printf("%d",Head -> data);
		printf("\n");
	}
}

int Count(PNODE Head)
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		iCnt++;
		Count(Head -> lchild);
		Count(Head -> rchild);
	}
	return iCnt;
}

int CountLeaf(PNODE Head)
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		if((Head -> lchild == NULL) && (Head -> rchild == NULL))
		{
			iCnt++;
		}
		CountLeaf(Head -> lchild);
		CountLeaf(Head -> rchild);
	}
	return iCnt;
}

int CountParent(PNODE Head)
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		if((Head -> lchild != NULL) || (Head -> rchild != NULL))
		{
			iCnt++;
		}
		CountParent(Head -> lchild);
		CountParent(Head -> rchild);
	}
	
	return iCnt;
}

int main()
{
	PNODE first = NULL;
	int iRet = 0,iChoice = 1,iValue = 0,iNo = 0;
	bool bRet = false;
	
	while(iChoice != 0)
	{
		printf("Enter desired choice you want to perform on BST : \n");
		printf("_________________________________________________________________\n");
		printf("1. Insert node in the BST.\n");
		printf("2. Search node in BST.\n");
		printf("3. Display the nodes of linked list(Inordr)\n");
		printf("4. Display the nodes of linked list(Preordr)\n");
		printf("5. Display the nodes of linked list(Postordr)\n");
		printf("6. Count the total number of nodes .\n");
		printf("7. Count the number of leaf nodes. \n");
		printf("8. Count the number of parent nodes.\n");
		printf("0.Terminate the application.\n");
		printf("_________________________________________________________________\n");
		
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
				printf("Enter element you want to insert : \n");
				scanf("%d",&iValue);
				Insert(&first,iValue);
				break;
				
			case 2:
				printf("Enter element you want to search : \n");
				scanf("%d",&iNo);
				bRet = Search(first,iNo);
				 
				if(bRet == true)
				{
					printf("Data is there\n");
				}
				else
				{
					printf("Data is not there\n");;
				}
				
				break;
				
			case 3:
				printf("Inorder : \n");
				Inorder(first);
				break;
				
			case 4:
				printf("Preorder : \n");
				Preorder(first);
				break;
				
			case 5:
				printf("Postorder : \n");
				Postorder(first);
				break;
				
			case 6:
				iRet = Count(first);
				printf("Total number of nodes are : %d\t",iRet);
				printf("\n");
				break;
				
			case 7:
				iRet = CountLeaf(first);
				printf("Number of leaf nodes are :\t%d",iRet);
				printf("\n");
				break;
				
			case 8:
				iRet = CountParent(first);
				printf("Number of parent nodes are :\t%d",iRet);
				printf("\n");
				break;
				
			case 0:
				printf("Thanks for using BST!!\n");
				break;
			
			default:
				printf("Please enter desired choice !\n");
				break;		
		}
	}
	
	return 0;
}
