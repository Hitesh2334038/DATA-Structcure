#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node *back;
	int data;
	struct Node *next;
};

int insert(struct Node **top,struct Node *ptr)
{
	
	if(*top==NULL)
	{
	
	*top=ptr;
	}else{
		ptr->next=*top;
		(*top)->back=ptr;
		*top=ptr;
	}
}

void insertlast(struct Node **top,struct Node *ptr)
{	
	struct Node *temp;
	temp=*top;
	
	if(temp!=NULL)
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		ptr->back=temp;
		temp->next=ptr;
		ptr->next=NULL;
	}
	else{
		printf("\n list is Null");
	}
}

void deletesamedataNode(struct Node **top,int val)
{
	struct Node *start=*top,*pre=*top,*temp;
	if(start==NULL)
	{
		printf("\n List is Null");
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
		start->next->back=pre;
		pre->next=start->next;
		free(start);
	}
}

void insertatpos(struct Node **top,int pos,int data)
{
	struct Node *temp;
	struct Node *t;
	//temp=(struct Node *)malloc(sizeof(struct Node) );
	if(pos==0)
	{
		temp=(struct Node *)malloc(sizeof(struct Node)  );
		temp->data=data;
		temp->back=NULL;
		temp->next=*top;
		*top=temp;
	}else if(pos>0){
		t=*top;
		for(int i=0;i<pos-1;i++){
			t=t->next;
		}
		if(t)
		{
			temp=(struct Node *)malloc(sizeof(struct Node)  );
			temp->data=data;
			temp->next=t->next;
			temp->back=t;
			if(t->next)
			{
				t->next->back=temp;
				t->next=temp;

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

struct Node *init(int data)
{
	struct Node *ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node)  );
	if(ptr)
	{	
	ptr->data=data;
	ptr->next=NULL;
	ptr->back=NULL;
	}
	return ptr;
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
	ptr=init(15);
	if(ptr==NULL)
	{
		printf("node is not created");
	}else{
		insertlast(&first,ptr);
		display(first);
	}
	insertatpos(&first,2,11);
	display(first);
	deletesamedataNode(&first,11);
	display(first);
	
}


