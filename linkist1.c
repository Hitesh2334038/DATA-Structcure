#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node * next;
}*first=NULL,*last;

void insertvalue(int A[],int n)
{	
	
	struct node *t;
	first=(struct node *)malloc(sizeof(struct node));
	first->data=A[0];
	first->next=NULL;
	last=first;

	for(int i=1;i<n;i++)
	{
	t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
	last->next=t;
	last=t;
	}
}

void lastinsert(int n)
{
	struct node *l;
	l=(struct node *)malloc(sizeof(struct node));
	l->data=n;
	l->next=NULL;
	if(first==NULL)
		{
			first=last=l;
		}
	else
	{
		last->next=l;
		last=l;
	}
	


}
void display(struct node *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}

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
			a->next=b->next;
			free(b);
			a=a->next;
			b=b->next;
		}
		
	}
}
void main(){
 	
	
	int A[]={11,12,13,14,11};
	insertvalue( A,5);
	
	lastinsert(100);
	lastinsert(101);
	lastinsert(100);
	lastinsert(103);
	
	dublicate(first);
	display(first);

}
;

