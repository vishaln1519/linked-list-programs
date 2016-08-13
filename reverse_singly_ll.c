/****REVERSE A SINGLY LINKED LIST *****///

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next; 

}NODE;

enum options {inst=1,rev,trav,rev_trav};

NODE *insert_node(NODE *head,int element );
NODE *reverse(NODE *head);
void traverse(NODE *head);

int main()
{
	NODE *head=NULL;
	NODE *new_head=NULL;
	int option;

	int node_data;
	do{
	printf("ENTER THE OPTION \n 1:to inter element\n 2:reverse the ll\n 3: traverse \n 4: traverse reverse llists \n 0:to quit\n");
	scanf("%d",&option);
	
	switch(option){
		case inst: printf("enter the data to node \n");
					scanf("%d",&node_data);
					head=insert_node(head,node_data);
					break;
		case rev: new_head=reverse(head);
					break;
		case trav: traverse(head);
					break;
		case rev_trav:printf("the reversed linked list is :\n");
						traverse(new_head);
						exit(0);
						break;
	}
	}while(option!=0);
}

NODE *insert_node(NODE *head,int element )
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

NODE *reverse(NODE *head)
{

	NODE *current=head;
	NODE *prev=NULL;
	NODE *next=NULL;

	while(current!=NULL)
	{
		next=current->next;
		current->next= prev;
		prev=current;
		current=next;

	}
	head=prev;
	printf("THE LINKED LIST IS REVERSED SUCCESSFULLY!!!\n");
	return head;

}