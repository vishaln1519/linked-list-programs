/***Doubly linkedlist insertion and travesering***/

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next; 
	struct node *prev;

}NODE;

enum options {inst=1,del,trav};

static void insert(NODE **start,NODE **end,int ele)
{
	NODE *temp =(NODE *)malloc(sizeof(NODE));

	if(*start==NULL || *end ==NULL)
	{
		temp->data = ele;
		temp->next=temp->prev=NULL;
		*start=*end=temp;
	}
	else
	{

		NODE *ptr=*start;
		temp->data=ele;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next = temp;
		*end = temp;
		temp->next = NULL;
		temp->prev= ptr;

	}
}

static 	void printList(struct node *start)
{
    struct node *end=NULL;
    printf("\nTraversal in forward direction \n");
    while (start!= NULL)
    {
        printf(" %d ", start->data);
        end = start;
        start = start->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (end != NULL)
    {
        printf(" %d ", end->data);
        end = end->prev;
    }
}



int main()
{
	NODE *start=NULL;
	NODE *end =NULL;
	int option;

	int node_data;
	do{
	printf("ENTER THE OPTION \n 1: to inter element\n 2: delete \n 3: traverse \n 0 :quit\n");
	scanf("%d",&option);
	
	switch(option){
		case inst: printf("enter the data to node \n");
					scanf("%d",&node_data);
					insert(&start,&end,node_data);
					break;

		case trav: printList(start);
					break;
	}
	}while(option!=0);
	exit(0);
}

