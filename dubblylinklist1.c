#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node *back;
	int data;
	struct Node *next;

};

struct Node* init(int val)
{
	struct Node *temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp)
	{
		
		temp->data=val;
		temp->back=NULL;
		temp->next=NULL;
	}
	return temp;
}

void insert(struct Node **top,struct Node *ptr)
{
	
	if(*top==NULL)
	{	
		
		*top=ptr;	
	}
	else{
		ptr->next=*top;		
		(*top)->back=ptr;
		*top=ptr;
		}
}

void deleteatsamedata(struct Node **top,int val)
{
	struct Node *temp,*start=*top,*pre=*top;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else if(start->data==val)
	{	
		temp=start;
		start->next->back=NULL;
		start=start->next;
		free(temp);
	}else{
		while(start->data!=val && start)
		{
			pre=start;
			start=start->next;
		}
		
		pre->next=start->next;
		start->next->back=pre;
		free(start);
		}
}

void insertatpos(struct Node **top,struct Node *ptr,int pos)
{
	struct Node *temp;
	if(pos==0)
	{
		ptr->next=*top;
		ptr->back=NULL;
		*top=ptr;
	}else if(pos>0)
	{
		temp=*top;
		for(int i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
		if(temp)
		{
			ptr->next=temp->next;
			ptr->back=temp;

			if(temp->next)
			{
				temp->next->back=ptr;
				temp->next=ptr;
			}
		}
	}
}

void display(struct Node *new)
{
	
	printf("\n");
        while(new!=NULL)
        {
                printf("%d->",new->data);

                new = new->next;
        }
        printf(" NULL \n");
}


void length(struct Node *new)
{
	int count=0;
	printf("\n");
        while(new!=NULL)
        {
                count++;

                new = new->next;
        }
	printf("\n length is :%d",count);
       
}

void main()
{
	struct Node *first=NULL;
	
	struct Node *ptr;
	
	ptr=init(10);
	if(ptr==NULL)
	{
		printf("node is not created");
	}else{
		insert(&first,ptr);
		display(first);
	}
	ptr=init(12);
	if(ptr==NULL)
	{
		printf("node is not created");
	}else{
		insert(&first,ptr);
		display(first);
	}
	length(first);
	ptr=init(13);
	if(ptr==NULL)
	{
		printf("node is not created");
	}else{
		insert(&first,ptr);
		display(first);
	}
	ptr=init(14);
	if(ptr==NULL)
	{
		printf("node is not created");
	}else{
		insert(&first,ptr);
		display(first);
	}
	ptr=init(22);
	if(ptr==NULL)
	{
		printf("node is not created");
	}else{
		insertatpos(&first,ptr,2);
		display(first);
	}
	length(first);
	deleteatsamedata(&first,12);
	display(first);
}
