#include <stdio.h>
#include <malloc.h>

/*Self Referential Structure*/

struct list{
	int val;
	struct list *next;
};

struct list *head =NULL;

int insert_last(int);
int insert_first(int);

void disp();

void main()
{
       insert_last(30);
       insert_last(40);
       insert_last(50);
       disp();
       insert_first(20);
       insert_first(10);
       insert_first(0);
       disp();
   
       

}



int insert_last(int val)
{
	struct list  *new,*temp;
	new=malloc(sizeof(struct list));
	new->val=val;
        new->next =NULL;
	if(!head){
		head =new;
       
	}else{
             temp=head;
		/*traverse end of list*/
	
		while(temp->next)
			temp=temp->next;
		temp->next=new;
	}
	
}

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
