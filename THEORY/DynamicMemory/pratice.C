#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	
} node1;

node1 *start;
node1 *end;

void main()
{
	    int choice;
		
		printf("\n Press<1> Create node at the end of list:");
		printf("\n Press<2> Display node from list:");
		printf("\n Press<3> for search record from list:");
		printf("\n Press<4> Exit from list:");
		
	while(1)
	{
		printf("\n Enter menu choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:creat
int display()
{
	node1 *ptr;
	if(start==NULL)
	{
		printf("List is empty");
	}
	else
	{
		for(ptr=start;ptr!=NULL;ptr=ptr->next)
		{
			printf("%d->",ptr->data);
		}
	}
} // close of display function.
int create()   // Enter element at the end of list.
{
	node1 *temp;
	temp=(node1*)malloc(sizeof(node1));
	printf("\n Enter data in list:");
	scanf("%d",&temp->data);
	if(start==NULL)
	{
		temp->next = NULL;
		start=temp;
		end=temp;
	}
	else
	{
		end->next=temp;
		end=temp;
		end->next=NULL;
	}
}// close of function.