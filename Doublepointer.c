#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}stptr;
typedef stptr *structptr;

void push(structptr *top,int val)
{
	structptr t;
	t=(stptr *)malloc(sizeof(stptr));
	t->data=val;
	t->next=*top;
	*top=t;
}

void pop(structptr *top)
{
	structptr t;
	t=*top;
	int x=(*top)->data;
	*top=(*top)->next;
	free(t);
	
}

void display(structptr p)
{
	if(p!=NULL)
	{
		
	

		while(p!=NULL)
		{
			printf("%d -->",p->data);
			p=p->next;
		}
	}else{
		printf("\n stack is empty");
		}
}

void deleteAll(structptr *top){
	structptr p=*top;
	structptr q=NULL;
	
	while(p->next!=NULL)
	{
		q=p;
		
		p=p->next;
		//p->next=NULL;
		free(q);
		
	}
	/*p->next=NULL;	
	if(p==NULL)
	{
		free(p);
		
	}*/
	
	printf("\n stack is empty now");
	
}

void isempty(structptr top)
	{
		printf("\n stack is empty or not ----->>" );
		 if(top==NULL)
		{
			printf("\n stack is null");
		}else{
			printf("\n stack not empty");
			}
		
	}
void deleteatpos(structptr top,int pos)
	{
		structptr p=NULL;
		for(int i=0;i<pos-1;i++)
		{
			p=top;
			top=top->next;
		}
		p->next=top->next;
		free(top);

	}
int length(structptr top)
	{	
		int count=0;
		while(top!=NULL)
		{
			count++;
			top=top->next;
		}
		
		printf("count is :%d",count);
		return count;
	}
void main(){
	structptr first=NULL;
	int x;
	while(x!=8)
	{
		printf("\n <----------------------------------welcome to link stack ------------------------------->");
		printf("\n 1] Add value in stack");
		printf("\n 2] pop value from stack");
		printf("\n 3] stack empty or not check");
		printf("\n 4] display linkstack");
		printf("\n 5] delete value depend on position");
		printf("\n 6] delete all stack");
		printf("\n 7] exit from stack");
		printf("\n Enter number for operation" );
		
		scanf("%d",&x);
		switch(x){
			case 1 :
				printf("\n Enter the value ");
				int num;
				scanf("%d",&num);
				push(&first,num);
				printf("\n values added succesfully\n");
				display(first);
				break;
			case 2	:
				printf("\n remove value from stack ");
				pop(&first);
				break;
			case 3	:
				
				isempty(first);
				break;
			case 4	:
				printf("\n stack value is ::::::>");
				display(first);
				break;
			case 5	:
				printf("\n Enter the pos ");
				int pos;
				scanf("%d",&pos);
				if(pos>length(first))
				{
					printf("\n position is greater than stack length");					
				}else{
					deleteatpos(first,pos);
					printf("\n deleted succesfully at pos :%d \n",pos);
				}
				break;
			case 6	:
				deleteAll(&first);
				break;
			case 7	:
				exit(1);
				break;
			default	:
				printf("wrong input bro");				
			}
	}
	
	
}

