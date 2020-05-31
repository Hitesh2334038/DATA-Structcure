#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}ptr;
typedef ptr *strptr;

void inqueue(strptr *top,strptr *rear,int val)
{			
	strptr t;
	t=(ptr*)malloc(sizeof(ptr));
	if(t!=NULL)
	{
		t->data=val;
		t->next=NULL;
		if(*top==NULL)
		{
			*top=*rear=t;
		}else{
			(*rear)->next=t;
			*rear=t;
		}
	}else{
		printf("\n queue is empty");
	}
	
	
}



int dequeue(strptr *top,strptr *rear)
{		
	strptr temp;
	if(*top!=NULL)
	{
		temp=*top;
		int x=(*top)->data;
		*top=(*top)->next;
		printf("\n deleted top position value is :%d ",x);
		free(temp);
	}else{
		*rear=NULL;
		printf("queue is totaly empty");
	}	
		
		
}

void isempty(strptr top)
{
	printf("\n queue is empty or not ----->>" );
		 if(top==NULL)
		{
			printf("\n queue is null");
		}else{
			printf("\n queue not empty");
			}
}

void display(strptr top){
	
		if(top!=NULL)
		{
			while(top!=NULL)
			{
				printf("%d -->",top->data);
				top=top->next;
			}
				
		}else{
		printf("\n queue is empty");
		}
}

void main()
{
	strptr first=NULL;
	strptr last=NULL;
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
