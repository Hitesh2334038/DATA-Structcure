#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first=NULL,*last;

void createlinks(int a[],int n){
	struct Node *t;
	first=(struct Node*)malloc(sizeof(struct Node));
	first->data=a[0];
	first->next=NULL;
	last=first;

	for(int i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void lastAdd(int n){
	struct Node *p,*t;
	
	 t=(struct Node*)malloc(sizeof(struct Node));
                t->data=n;
                t->next=NULL;

		if(first==NULL)
		{
			first=last=t;
		}
		else{
			last->next=t;
			last=t;
		}
	
}

void addbetween(int pos,int n){
	struct Node *t,*p;
	
	if(pos==0)
	{
		 t=(struct Node*)malloc(sizeof(struct Node));
                t->data=n;
                t->next=NULL;
		first=t;
	}else if(pos>0)
	{
		p=first;
		for(int i=0;i<pos-1;i++)
		{
			p=p->next;
		}
		if(p)
		{
			 t=(struct Node*)malloc(sizeof(struct Node));
	                t->data=n;
        	        t->next=NULL;
			t->next=p->next;
			p->next=t;
		}
	}

}

void deletefirst(){
	
	struct Node *p;
	p=first;
	first=p->next;
	int x=p->data;
	free(p);
	printf("\n delete first node with data is :%d ",x);
}

void deletepos(int pos){
	
	struct Node *p=first,*q;
	for(int i=0;i<pos-1;i++)
	{
		q=p;;
		p=p->next;
	}
	int x=p->data;
	q->next=p->next;
	free(p);
	printf("\n delete pos is :%d and delete value at that Pos :%d",pos,x);


}

void deletelast(){
	 struct Node *p,*q;
	
	if(first==NULL)
	{
		printf("List is alredy empty");
	}
	else
	{
		 p=first;
		q=first;
	 while(p->next!=NULL)
	 {
		 q=p;
		p=p->next; 
	 }	
	
       		q->next=NULL;
		 int x=p->data;
		 free(p);
	 
	 
	  printf("\n delete value at that lastPos  :%d ",x);
	}

}

void display(struct Node *p)
{
	 while(p)
         {
                 printf("\n %d ",p->data);
                 p=p->next;
         }

}

void main(){
	int a[]={1,2,3,4,5,6};
	createlinks( a,6);

	deletelast();
	display(first);

}
