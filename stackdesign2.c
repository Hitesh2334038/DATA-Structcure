#include <stdio.h>
#include <malloc.h>

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

void main()
{
      
       push(20);
       push(10);
       push(0);
       disp();
       
       pop();
       disp();
       printf("\n");
       main();

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
		printf(" %d",temp->val);
                 temp=temp->next;
}
	

printf("\n");

}
