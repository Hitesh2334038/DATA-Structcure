#include <stdio.h>
#include <malloc.h>

/*Self Referential Structure*/

struct list{
	int val;
	struct list *next;
};

struct list *head =NULL;


int insert_first(int);
int delete_last();
//int delete_first();
void disp();

void main()
{
      
       insert_first(20);
       insert_first(10);
       insert_first(0);
       disp();
       
       delete_last();
       disp();
       printf("\n");
       

}
int delete_last()
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
}

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

int insert_first(int val)
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
/*int delete_first(int val)
{
	struct list *temp;
         temp=head;
        if (!temp)
        return 0;
       head=temp->next;
	free(temp);

}*/
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
