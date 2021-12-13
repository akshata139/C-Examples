#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void fun(PNODE p)
{
	
}

void gun(PPNODE q)
{
	
}

int main()
{
	PNODE first = NULL;
	
	//call by value
	fun(first);		//fun(100),disply(),count()
	
	//call by reference
	gun(&first);		//fun(50),insertfirst(),insertlast(),insertpos(),deletefirst(),dellast(),delatPos()
	
	return 0;
}

/*
malloc function returns void*
*/