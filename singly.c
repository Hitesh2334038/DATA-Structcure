#include<stdio.h>
#include<malloc.h>

/* Self Referential Structure to implement Dynamic Data Structure */
struct ListNode {
        int data;
        struct ListNode *next;

};

/* Single Linked List Operations */

/* Init Function */
struct ListNode * Init(int a)        /* Init Function */
{
        struct ListNode *new;
        new = (struct ListNode *) malloc (sizeof(struct ListNode));
        if(new)
        {
                new->data=a;
                new->next = NULL;
	}
        return new;
}

/* Function to insert the new node as first node in the list */
void insert_first(struct ListNode **head,struct ListNode *new)
{
        if(*head == NULL)        /* Check whether list is empty */
                *head = new;        /* Make new node as first node if list in empty */
        else
        {
                new->next = *head; /* Make new node as first node if list is not empty */
                *head = new;
        }
}

/* Function to insert the new node in the middle or end of the list */
void insert_middle(struct ListNode **head,struct ListNode *new,int pos)
{
        int i=1;
       struct ListNode *temp=*head;
        if(temp==NULL || pos==1)
        {
                new->next = *head;
                *head = new;        /* Make new node as first node if list in empty or positions in one*/
                return;
        }
        else
        {
                while((i<pos-1) && temp )        /* Navigate upto position-1 node */
                {
                        temp=temp->next;
                        i++;
                }
        }
        if(temp!=NULL)                /* Make new node as part of list */
        {
                new->next = temp->next;
                temp->next = new;
                        }
        else
                printf("\n Not A Valied Position \n");

}

/* Print all nodes data in the list */
void print_list(struct ListNode *new)        /* Print all nodes data in the list */
{

        printf("\n");
        while(new)
        {
                printf("%d->",new->data);

                new = new->next;
        }
        printf(" NULL \n");

}


/* Function to delete a node for the list */
void delete_node(struct ListNode ** head,int data)                /* Function to delete a node for the list */
{
        struct ListNode * temp,*start = *head,* prev = *head;
        printf("\n Before Deletion\n");
        print_list(*head);
        if(start==NULL)                /* Check if list is empty */
        {
                printf("\n List is Empty \n");
                return;
        }
        if(start->data == data)        /* Delete first element */
        {
                temp = start;
                *head = start->next;

                free(temp);
                printf("\n After Deletion\n");
                print_list(*head);
                return;
        }
        else
        {
                while( (start->data!=data) && start)        /* Search for the node to delete */
                {
                        prev = start;
                        start = start->next;
                }
                if(start != NULL)                /* Delete node */
                {
                     prev->next = start->next;
                               free(start);
                       printf("\n After Deletion \n");
                       print_list (*head);
                }
                else
                        printf("\n Node not Found \n");
        }

}

/* Function to count total number of elements in the list */
int count_node(struct ListNode *start)
{
        int count=1;
        while(start->next)
        {
        	           start=start->next;
                           count++;
        }
        return count;
}



int main()
{

int a , pos;

struct ListNode *start =NULL; /*Pointer pointing to first node of the list */

struct ListNode *ptr;

ptr = Init(10);
if (ptr==NULL)
printf("Fail to create a node \n");
else
insert_first(&start,ptr);
print_list(start);

ptr = Init(20);
if (ptr==NULL)
printf("Fail to create a node \n");
else
insert_first(&start,ptr);
print_list(start);

ptr = Init(30);
if (ptr==NULL)
printf("Fail to create a node \n");
else
insert_middle(&start,ptr,2);
print_list(start);
delete_node(&start,30);

printf("\n Total Number of Elements : %d \n",count_node(start));

}
