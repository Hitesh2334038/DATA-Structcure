#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node*next;
};

void inqueue(struct Node**top ,struct Node**rear , char val)
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	if(t!=NULL)
	{
		t->data=val;
		t->next=NULL;
		if(*top==NULL)
		{
			*top=*rear=t;
		}
		else
		{
			(*rear)->next=t;
			*rear=t;
		}
	}
	else
		{
			printf("\n queue is empty");
		}
	//return 1; 

}



void dequeue(struct Node **top,struct Node **rear){
	struct Node *temp;
	if(*top!=NULL)
	{
		temp=*top;
		int x=(*top)->data;
		*top=(*top)->next;
		printf("\n deleted top position value is :%d ",x);
		free(temp);
	}else{
		printf("\n queue is empty");
	}
	
}

void isempty(struct Node *top)
{
	if(top)
	{
		printf("\n queue is Not empty");
		}
	else{
		printf("\n queue is empty");
	}
}


void display(struct Node *top){
	
	if(top!=NULL)
	{
		while(top!=NULL)
		{
			printf(" %d -->",top->data);
			top=top->next;
		}	
	}else{
		printf("\n queue is empty");
	}
}

void main(){
	struct Node *first=NULL;
	struct Node *last=NULL;
	int x;
	while(x!=8)
	{
		printf("\n <----------------------------------welcome to queue ------------------------------->");
		printf("\n 1] Add value in queue");
		printf("\n 2] remove value from queue");
		printf("\n 3] queue empty or not check");
		printf("\n 4] display linkstack");
		printf("\n 5] exit from stack");
		printf("\n Enter number for operation" );
		
		scanf("%d",&x);
		switch(x){
			case 1 :
				printf("\n Enter the value in queue");
				int num;
				scanf("%d",&num);
				inqueue(&first,&last,num);
				printf("\n values added succesfully\n");
				display(first);
				break;
			case 2	:
				printf("\n remove value from queue ");
				dequeue(&first,&last);
				break;
			case 3	:
				
				isempty(first);
				break;
			case 4	:
				printf("\n stack value is ::::::>");
				display(first);
				break;
			case 5	:
				exit(1);
				break;
			default	:
				printf("wrong input bro");				
			}
		}
}
