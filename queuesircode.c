#include <stdio.h>
#include <stdlib.h>
 
struct queueNode   			/* self-referential structure */
{
	char data;
	struct queueNode *nextPtr;
};


/* function prototypes*/ 
void printQueue(struct queueNode* );
int isEmpty(struct queueNode* );
char dequeue(struct queueNode** ,struct queueNode** );
void enqueue(struct queueNode** ,struct queueNode** , char );
void instructions( void );

int main()
{ 
	struct queueNode *headPtr = NULL,  *tailPtr = NULL;
   	int choice;
   	char value;
	
   	instructions();
      	printf( "Enter Your Choice : " );
   	scanf( "%d", &choice );

   	while ( choice != 3 ) 
	{ 
      		switch( choice ) 
		{ 
 			case 1:
            			printf( "Enter a character: " );
            			scanf( "\n%c", &value);
            			enqueue( &headPtr, &tailPtr, value );
            			printQueue( headPtr );
            			break;

         		case 2:
            			if ( !isEmpty( headPtr ) ) 
     				{ 
               			value= dequeue( &headPtr, &tailPtr );
               			printf( "%c has been dequeued.\n", value );
            			}

            			printQueue( headPtr );
            			break;

         		default:
            			printf( "Invalid choice.\n\n" );
            			instructions();
            			break;
   		}

      		printf( "Enter Your Choice : " );
    		scanf( "%d", &choice );
   	}
   	printf( "End of run.\n" );
   	return 0;
}


void instructions( void )
{ 
	printf ( "Enter your choice:\n"
         		"   1 to add an item to the queue\n"
           		"   2 to remove an item from the queue\n"
           		"   3 to end\n" );
}

void enqueue(struct queueNode**first ,struct queueNode**rear , char var)
{
	struct queueNode *t;
	t=(struct queueNode*)malloc(sizeof(struct queueNode));
		if(t==NULL)
		{
			printf("queue is full");
		}
		else{
		
		t->data=var;		
		t->next=NULL;
		if(*first==NULL)
		{
		*first=*rear=t;
		}else
		{
			(*rear)->next=t;
			*rear=t;
		}
}

int dequeue(struct queueNode**first ,struct queueNode**rear )
{
	struct queueNode *t,*q;
	t=**first;
	if(!t)
 	return 0;
 
	while(t->next!=NULL){
    	q=t;
    	t=t->next;
}
	q->next=NULL;
	free(t);

}

void printQueue(struct queueNode* )
{
	
}

