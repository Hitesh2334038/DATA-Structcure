void dublicate(struct node *p)
{
	struct node *a;
	a=p;
	struct node *b;
	b=p->next;
	while(b!=NULL)
	{
		if(a->data!=b->data)
		{
			a=b;
			b=b->next;
		}
		else
		{
			int x=b->data;
			printf("\n dublicate data is : %d",x);
			//a->next=b->next;
			//free(b);
			a=a->next;
			b=b->next;
		}
		
	}
}int insert (struct node **start, int data)
{
	struct node *curr,*prev,*new;
	curr = *start;

	//new = (struct node *) malloc(sizeof(struct node *));
	new = (struct node *) malloc(sizeof(struct node ));
	if(new==NULL)	
		return 0;
	
	new->data = data;

	if(*start==NULL || curr->data > data) {
		new->next=*start;
		*start = new;
		return 1;
	}

	while(curr && curr->data < data) {
		prev = curr;
		curr = curr->next;
	}
	new->next = prev->next;
	prev->next = new;
	return 1;
}
******************************
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};



int insert (struct node **start, int data)
{
	struct node *curr,*prev,*new;
	curr = *start;

	//new = (struct node *) malloc(sizeof(struct node *));
	new = (struct node *) malloc(sizeof(struct node ));
	if(new==NULL)	
		return 0;
	
	new->data = data;

	if(*start==NULL || curr->data > data) {
		new->next=*start;
		*start = new;
		return 1;
	}

	while(curr && curr->data < data) {
		prev = curr;
		curr = curr->next;
	}
	new->next = prev->next;
	prev->next = new;
	return 1;
}

void print_list(struct node  * ptr)     /* Print all nodes struct node  in the list */
{
        printf("\n");
        while(ptr)
        {
                printf("%d -> ",ptr->data);
                ptr = ptr->next;
        }
        printf(" NULL \n");
}


int main()
{
	struct node *first=NULL;
	insert(&first,10);
	insert(&first,2);
	insert(&first,50);
	insert(&first,15);
	insert(&first,30);
	insert(&first,1);
	insert(&first,60);
	insert(&first,55);

	print_list(first);
}
