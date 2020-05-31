#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
	struct TreeNode *lchild;
	int data;
	struct TreeNode *rchild;
}*root=NULL;
void insertdata(int val)
{
	struct TreeNode *r,*t,*p=root;
	if(root==NULL)
	{
		t=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
		t->data=val;
		t->lchild=NULL;
		t->rchild=NULL;
		root=t;
		return ;
		
	}
	while(p)
	{
		r=p;
		if(val>p->data)
		p=p->rchild;
		else if(val<p->data)
		p=p->lchild;
		else
		return;
	}
	t=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
		t->data=val;
		t->lchild=NULL;
		t->rchild=NULL;
		if(val>r->data)
		r->rchild=t;
		if(val<r->data)
		r->lchild=t;
}

struct TreeNode * inorder(struct TreeNode *p)
{
	//printf("\ntraversal in INORDER : ");
	if(p!=NULL)
	{
		inorder(p->lchild);
		printf("%d -->",p->data);		
		inorder(p->rchild);
		
	}
	
}

struct TreeNode * preorder(struct TreeNode *p)
{
	//printf("\ntraversal in PREORDER : ");
	if(p!=NULL)
	{
		printf(" %d -->",p->data);	
		preorder(p->lchild);
		preorder(p->rchild);
		
	}
	//printf("\n");
}

struct TreeNode * postorder(struct TreeNode *p)
{
	//printf("\ntraversal in POSTORDER : ");
	if(p!=NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf(" %d -->",p->data);
	}
//	printf("\n");
}

int height(struct TreeNode *p)
{
	int x,y;
	if(p==NULL)
	return 0;
	x=height(p->lchild);
	y=height(p->rchild);
	return x>y?x+1:y+1;
}

struct TreeNode *Inpre(struct TreeNode *p)
{
	while(p && p->rchild!=NULL)
	p=p->rchild;
	
	return p;
}

struct TreeNode *Insuc(struct TreeNode *p)
{
	while(p && p->lchild!=NULL)
	p=p->lchild;
	
	return p;
}

struct TreeNode *delete(struct TreeNode *p,int key)
{
	struct TreeNode *q;
	if(p==NULL)
	return NULL;
	if(p->lchild==NULL &&  p->rchild==NULL)
	{	
		if(p==root)
		root=NULL;
		free(p);
		return NULL;
	}
		if(key>p->data)
		p->rchild=delete(p->rchild,key);
		else if(key<p->data)
		p->lchild=delete(p->lchild,key);
		else {
			if(height(p->lchild)>height(p->rchild))
			{
				q=Inpre(p->lchild);
				p->data=q->data;
				p->lchild=delete(p->lchild,q->data);
			}
			else
			{
				q=Insuc(p->rchild);
				p->data=q->data;
				p->rchild=delete(p->rchild,q->data);
			}
		}
	 return p;
}
void main()
{
	
	insertdata(50);
	insertdata(25);
	insertdata(20);
	insertdata(30);
	insertdata(70);
	insertdata(75);
	insertdata(45);
	insertdata(65);
	insertdata(90);
	insertdata(55);
	//printf("\n\ntraversal in INORDER : ");
	//inorder(root);
	printf("\n\ntraversal in PREORDER : ");
	preorder(root);
	//printf("\n\ntraversal in POSTORDER : ");
	//postorder(root);
	printf("\n \n after delete : ");	
	//delete(root,50);
	delete(root,75);
	//delete(root,90);
	inorder(root);
}


/*
struct Node* getInorderPredecessor(struct Node *n) {
 struct Node *temp = n->left;
 while(temp->right != NULL) {
  temp = temp->right;
 }
 return temp;
}




void delete(struct Node *n, int item) {
 struct Node *curr = n, *parent = NULL, *pred;
 int predecessorData;
 // search the node to be delete
 while(curr != NULL) {
  if(curr->data == item)
   break;
  parent = curr;
  if(item < curr->data)
   curr = curr->left;
  else
   curr = curr->right;
 }
 if(curr == NULL) {
  printf("\n Item not found");
  return;
 }
 // Leaf node
 if(curr->left == NULL && curr->right == NULL) {
  if(parent == NULL)
   root = NULL;
  else if(curr->data < parent->data)
   parent->left = NULL;
  else
   parent->right = NULL;
  free(curr);
  return;
 }
 // Single node
 // left is null, right is not null
 if(curr->left == NULL && curr->right != NULL) {
  if(parent == NULL)
   root = curr->right;
  else if(curr->data < parent->data)
   parent->left = curr->right;
  else
   parent->right = curr->right;
  free(curr);
  return;
 }
 // left is not null, right is null
 if(curr->left != NULL && curr->right == NULL) {
  if(parent == NULL)
   root = curr->left;
  else if(curr->data < parent->data)
   parent->left = curr->left;
  else
   parent->right = curr->left;
  free(curr);
  return;
 }
 // having both children
 pred = getInorderPredecessor(curr);
 predecessorData = pred->data;
 delete(curr, pred->data);
 curr->data = predecessorData;
}*/
