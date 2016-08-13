/*********insertion at end ,traverse and deletion afrom front**/



/******QUEUE****/

#include <stdio.h>
#include <stdlib.h>


struct node
{

        int data;
        struct node *link;
};
struct node *insert_ll(struct node *, int );
void traverse(struct node *start);
struct node * deletion(struct node *start);

int main()
{

        struct node *start=NULL;
        int a;int ele;
        do{
                printf("enter the opeartion code\n");
                printf("1 :- insertion\n");
                printf("2 :- deletion\n");
                printf("3 :- traverse\n");
                printf("0 :- quit");
        //int a;int ele;
        scanf("%d",&a);

        switch(a){
        
        
         case 1: printf("enter the element\n");
                scanf("%d",&ele);
                start = insert_ll(start,ele);
                break;
        case 2:printf("deletion performed\n");
                start=deletion(start);
                break;
        case 3:printf("*****TRAVERSE***\n");
                traverse(start);
                break;

        
        
        }
                


}while(a!=0);
}



struct node *insert_ll(struct node *start, int ele)
{
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *ptr = NULL;

        if(start==NULL)
        {
                 printf("start node is made\n");

                temp->data=ele;
                temp->link=NULL;
                start=temp;

        }
        else
        {


                temp->data=ele;
                temp->link=NULL;
                ptr=start;
                while(ptr->link!=NULL)
                {
                       ptr=ptr->link;

                }
                ptr->link =temp;



        }

        return(start);

}
void traverse(struct node *start)
{
        printf("*****traverse***");
        struct node *ptr = start;
         while(ptr!=NULL)
                {
                        printf(" the data is %d and pointer is %p\n",ptr->data,ptr->link);
                        ptr=ptr->link;
                }

}

struct node * deletion(struct node *start)
{

        struct node *ptr=start;
        start=ptr->link;
        free(ptr);
        return(start);


}



