#include <stdio.h>
#include <stdlib.h>

/*Self Referential Structure*/

struct list{
	int val;
	struct list *next;
};

struct list *head =NULL;

//int insert_last(int);
int push(int);
//int delete_last();
int pop();
void disp();
void exit();
void main()
{
	while(1)
	{
		printf("\n Enter your number ");
		printf("\n Enter 1 : for the push value");
		printf("\n Enter 2 : for the pop value");
		printf("\n Enter 3 : exit");
		printf("\n Enter here num which operation u want :");
		int n;
		int num;
		scanf("%d",&n);
			switch(n) {

      			case 1:
				printf("\n Enter the value :");
				int num;
				scanf("%d",&num);
       				push(num);
				printf("\n pushing value in stack is done");
				disp();
 			break;
			case 2:
				if(head==NULL)
				{
					printf("\n Stack is empty");
					}
				else{
       				pop();
				printf("\n pop value from stack is done");
       				disp();}
			break;
			case 3:
				printf("\n exit from stack");
				exit(1);
			default :
				printf("\n U enter wrong input");
	
       printf("\n");
     }  
}
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

int push(int val)
{
	struct list *temp;
	temp=malloc(sizeof(struct list));
        if (!temp)
        return 0;

	temp->val=val;
	temp->next=head;
	head=temp;
        return 1;

}
int pop(int val)
{
	struct list *temp;
         temp=head;
        if (!temp)
        return 0;
       head=temp->next;
	free(temp);

}
void disp(void)
{
	struct list *temp;
                 temp=head;
		while(temp){
		printf(" --> %d",temp->val);
                 temp=temp->next;
}



printf("\n");

}
