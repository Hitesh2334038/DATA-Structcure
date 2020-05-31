#include <stdio.h>
#include <stdlib.h>

/*Self Referential Structure*/


struct stackNode 		/* self-referential structure */
{	
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr ;

void push( StackNodePtr *, int );
int pop( StackNodePtr );
int isEmpty( StackNodePtr );
//void printStack( StackNodePtr );
void instructions( void );
int main()
{ 
	StackNodePtr stackPtr = NULL;  	/* points to stack top */
	int choice, value;
 
	instructions();
	printf( "Enter Your Choice : " );
	scanf( "%d", &choice );
  	while ( choice != 3 ) 
   	{ 
   		switch ( choice ) 
      		{ 
      			case 1:      /* push value onto stack */
        			printf( "Enter an integer: " );
                		scanf( "%d", &value );
      	      			push( &stackPtr, value );
            			//printStack( stackPtr );
 	      			break;

      			case 2:      /* pop value off stack */
				if ( !isEmpty( stackPtr ) )
                			printf( "Popped value is %d.\n", pop( &stackPtr ));
	        		//printStack( stackPtr );
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
	main();
   	return 0;
}

/* Print the instructions */
void instructions( void )
{ 
	printf( "Enter choice:\n"
	"1. to push a value on the stack\n"
	"2. to pop a value off the stack\n"
     	"3. to end program\n" );	
}
/*int delete_last()
{

 struct list * temp;
 struct list * prev;
	temp=head;
 if(!temp)
 return 0;
 
while(temp->next){
    prev=temp;
    temp=temp->next;
}
prev->next=NULL;
free(temp);
}*/

/*int insert_last(int val)
{
	struct list  *new,*temp;
	new=malloc(sizeof(struct list));
	new->val=val;
        new->next =NULL;
	if(!head){
		head =new;
       
	}else{
             temp=head;
		/*traverse end of list
	
		while(temp->next)
			temp=temp->next;
		temp->next=new;
	}
	
}*/

void push(StackNodePtr   *top,int val)
{
	StackNodePtr temp;
	temp=malloc(sizeof(StackNode));
        if (!temp)
        return 0;

	temp->val=val;
	temp->next=*top;
	top=temp;
        return 1;

}
int pop(StackNodePtr *top )
{
	StackNodePtr  *temp;
         temp=stackPtr;
        if (!temp)
        return 0;
       top=temp->next;
	free(temp);

}
void disp(void)
{
	StackNodePtr  *temp;;
                 temp=head;
		while(temp){
		printf(" --> %d",temp->val);
                 temp=temp->next;
}

void isEmpty( StackNodePtr   )
{

			if(StackNodePtr==NULL)
				{
					printf("\n Stack is empty");
					}
				
}

printf("\n");

}
