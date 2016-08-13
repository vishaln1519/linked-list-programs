/****IMPLEMENTATAION OF STACK USING LINKED LISTS *****///

/***STACK***/
#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next; 

}NODE;

enum options {inst=1,del,trav};

NODE *push_node(NODE *head,int element );
void pop_node(NODE *head);
void traverse(NODE *head);

int main()
{
	NODE *head=NULL;
	int option;

	int node_data;
	do{
	printf("ENTER THE OPTION \n 1:to push element\n 2:pop the element\n 3: traverse \n 0:uit\n");
	scanf("%d",&option);
	
	switch(option){
		case inst: printf("enter the data to node \n");
					scanf("%d",&node_data);
					head=push_node(head,node_data);
					break;
		case del: 	if(head==NULL)
					{
						printf("no elements to pop\n");
						return 0;
					}
					printf("Deletion performed\n");
					pop_node(head);
					break;
		case trav: traverse(head);
					break;
		default:printf("enter a valid option from above shown oprtions \n");
	}
	}while(option!=0);
}

NODE *push_node(NODE *head,int element )
{
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	if(head==NULL)
	{
		temp->data=element;
		temp->next = NULL;
		head= temp;
	}
	else{
		temp->data= element;
		temp->next=NULL;
		NODE *ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;

	}
	return(head);

}

void traverse(NODE *head)
{
        printf("*****traverse***\n");
        struct node *ptr = head;
         while(ptr!=NULL)
                {
                        printf(" the data is %d and pointer is %p\n",ptr->data,ptr->next);
                        ptr=ptr->next;
                }

}

void pop_node(NODE *head)
{
	
	NODE *save=NULL;
	NODE *ptr=head;
	while(ptr->next!=NULL)
	{
		save=ptr;
		ptr=ptr->next;
	}
	save->next=NULL;
	free(ptr);



}