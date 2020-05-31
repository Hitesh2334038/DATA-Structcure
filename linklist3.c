#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*first=NULL,*last;
void createnode(int a[],int n)
{
	struct Node *t,*add;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=a[0];
	first->next=NULL;
	
	last=first;

	for(int i=1;i<n;i++)
	{
		 add=(struct Node *)malloc(sizeof(struct Node));
	        add->data=a[i];
        	add->next=NULL;
		last->next=add;
		last=add;

	}
}
void Insert(int pos,int num)
{
	struct Node *t,*p;
	if(pos==0)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
        	t->data=num;
        	t->next=NULL;

        	first=t;
	}
	else if(pos>0)
	{
		p=(struct Node *)malloc(sizeof(struct Node));
		p=first;
		for(int i=0;i<pos-1;i++)
		{
			p=p->next;
		}
		if(p)
		{
			 t=(struct Node *)malloc(sizeof(struct Node));
                	t->data=num;
                	t->next=p->next;
			p->next=t;
		}

	}
}	
void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("\n %d ",p->data);
		p=p->next;
	}
}

void deleteFirst()
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	t=first;
	int x=first->data;
	first=first->next;
	t=NULL;
	printf("first Node Deleted where value is : %d ",x);
}

void deleteAtpos(int pos)
{
	struct Node *p,*q;
	p=first;
	for(int i=0;i<pos-1;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	int x=p->data;
	p=NULL;
	printf("\n Deleted pos And value is : %d ,: %d ",pos,x);
}

void search(struct Node *p,int key)
{
	printf("\n serching using key");
	struct Node *q=NULL;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=first;
			first=p;
		}
		q=p;
		p=p->next;
	}

}

void sortandadd(struct Node *p,int x)
{
	printf("\n using sort and then add value");
	struct Node *t,*q=NULL;
	while(p!=NULL && p->data<x)
	{
		q=p;
		p=p->next;
	}
	
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	t->next=q->next;
	q->next=t;
}

void removeduplicate()
{
	printf("\n remove duplicate value  ");
	struct Node *p=first,*q=first->next;
	while(q->next!=NULL)
	{
		if(q->data!=p->data)
		{
			p=q;
			q=q->next;
		}
		p->next=q->next;
		free(q);
		p=p->next;
		q=q->next;
		
	}
}

void reverselinklist()
{
	
}
void main()
{
	int a[]={22,25,22,65,88,89,25,65};
	createnode( a,8);
	display(first);
	//Insert(3,1);
	//Insert(4,55);
	//display(first);
	//deleteFirst();
	//deleteAtpos(3);
	//search(first,36);
	//display(first);
	//sortandadd(first,37);
	//display(first);
	//sortandadd(first,38);
	//display(first);
	//removeduplicate();
	
	display(first);

	
}
