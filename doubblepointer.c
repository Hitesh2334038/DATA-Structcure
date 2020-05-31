#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}ptr;
typedef ptr *strptr;

void push(strptr *top,int val){
	strptr t;
	t=(ptr*)malloc(sizeof(ptr));
	t->data=val;
	t->next=*top;
	*top=t;
}

void pop(strptr *top){
	strptr t;
	t=*top;
	*top=(*top)->next;
	int x=(*top)->data;
	
	free(t);
}


void isempty(strptr top){
	if(top!=NULL)
	{
		printf("stack is not empty");
	}else{
		printf("stack is empty");
		}
	
}


void length(strptr top){
	int count=0;
	
		while(top!=NULL)
		{	
			count++;
			top=top->next;			
		}
		printf("stack length is : %d ",count);
	}



void display(strptr top){
	
	if(top!=NULL){
		while(top!=NULL)
		{	
			printf(" %d -->",top->data);
			top=top->next;			
		}
		
	}else
	{
		printf("stack is empty");
	}
}


void main(){
	strptr first=NULL;
	push(&first,11);
	push(&first,12);
	push(&first,13);
	push(&first,14);
	push(&first,15);
	display(first);
	pop(&first);
	display(first);
	isempty(first);
	length(first);
	}
