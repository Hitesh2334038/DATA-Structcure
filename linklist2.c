#include<stdio.h>
#include<stdlib.h>
int finsert(int);
int linsert(int);
void display();

struct node{
	int data;
	struct node *next;
}*head=NULL,*last;
void main()
{
	struct node *a;
	finsert(12);
	finsert(15);
	finsert(16);
	finsert(18);
	display();
	linsert(22);
	linsert(1);
	display();
}
int  finsert(int n)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	if(!t)
		return 0;
	
	t->data=n;
	t->next=head;
	head=t;
	return 1;
	
}

int linsert(int n)
{
        struct node *t,*temp;
        t=(struct node*)malloc(sizeof(struct node));
        t->data=n;
        t->next=NULL;
	if(!head)
        {
                head=t;
        }else
	{
		temp=head;
	}
	while(temp->next)
		temp=temp->next;
	temp->next=t;
        
}
void display(){
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d  ",  p->data);
		p=p->next;
	}
}
