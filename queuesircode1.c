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


void enqueue( struct queueNode **headPtr, struct queueNode **tailPtr, char value)
{ 
            struct queueNode *newPtr;

   	newPtr = malloc( sizeof( struct queueNode ) );

   	if ( newPtr != NULL ) 
        { 
      		newPtr->data = value;
      		newPtr->nextPtr = NULL;

      		if ( isEmpty( *headPtr ) )
         		*headPtr =*tailPtr=newPtr;
      		else
         	 	( *tailPtr )->nextPtr = newPtr;

  		*tailPtr = newPtr;
   	}
   	else
        	printf( "%c not inserted. No memory available.\n", value );
}

char dequeue( struct queueNode **headPtr,struct queueNode **tailPtr )
{ 
	char value;
        struct queueNode *tempPtr;

        value = ( *headPtr )->data;
        tempPtr = *headPtr;
        *headPtr = ( *headPtr )->nextPtr;
	
       if ( *headPtr == NULL )
      	     *tailPtr = NULL;

   	free( tempPtr );
   	
	return value;
}

int isEmpty( struct queueNode *headPtr )
{ 
	return headPtr == NULL;
}

void printQueue( struct queueNode  *currentPtr )
{ 
	if ( currentPtr == NULL )
               printf( "Queue is empty.\n\n" );
        else 
   	{ 
      		printf( "The queue is:\n" );

 		while ( currentPtr != NULL ) 
       		{ 
        		printf( "%c --> ", currentPtr->data );
         		currentPtr = currentPtr->nextPtr;
      		}
		printf( "NULL\n\n" );
   	}
}
