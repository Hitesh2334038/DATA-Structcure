#include<stdio.h>
#include<stdlib.h>

struct Node{
	int height;
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;


int height(struct Node *p)
{
	int hl,hr;
	hl=p&&p->lchild?p->lchild->height:0;
	hr=p&&p->rchild?p->rchild->height:0;
	return hl>hr?hl+1:hr+1; 
}

int balancefactor(struct Node *p)
{
	int hl,hr;
	hl=p&&p->lchild?p->lchild->height:0;
	hr=p&&p->rchild?p->rchild->height:0;
	return hl-hr; 
}


struct Node *LLrotation(struct Node * p)
{
	struct Node *pl=p->lchild;
	struct Node *plr=pl->rchild;

	pl->rchild=p;
	p->lchild=plr;
	
	p->height=height(p);
	pl->height=height(pl);

	if(root==p)
	root=pl;
	
	return pl;
}

struct Node *LRrotation(struct Node * p)
{
	struct Node *pl=p->lchild;
	struct Node *plr=pl->rchild;
	
	pl->rchild=plr->lchild;
	p->lchild=plr->rchild;

	plr->rchild=p;
	plr->lchild=pl;

	p->height=height(p);
	pl->height=height(pl);
	plr->height=height(plr);

	if(root==p)
	root=plr;

	return plr;

}

struct Node *RRrotation(struct Node * p)
{
	struct Node *pr=p->rchild;
	struct Node *prl=pr->lchild;

	pr->lchild=p;
	pr->rchild=prl;
	
	p->height=height(p);
	pr->height=height(pr);

	if(root==p)
	root=pr;
	
	return pr;
}



struct Node *RLrotation(struct Node * p)
{
	struct Node *pr=p->rchild;
	struct Node *prl=pr->lchild;
	
	pr->lchild=prl->rchild;
	p->rchild=prl->lchild;

	prl->lchild=p;
	prl->rchild=pr;

	p->height=height(p);
	pr->height=height(pr);
	prl->height=height(prl);

	if(root==p)
	root=prl;

	return prl;

}

 struct Node *RInsert(struct Node *p,int key)
{
	struct Node *t=NULL;
	if(p==NULL)
	{	
		t=(struct Node *)malloc(sizeof(struct Node ));
		t->data=key;
		t->height=1;		
		t->lchild=NULL;
		t->rchild=NULL;
	return t;
	}
	if(key<p->data)
	p->lchild=RInsert(p->lchild,key);
	if(key>p->data)
	p->rchild=RInsert(p->rchild,key);
	p->height=height(p);

	if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
	return LLrotation(p);


	if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
	return LRrotation(p);



	if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
	return RRrotation(p);


	if(balancefactor(p)==-2 && balancefactor(p->rchild)==1)
	return RLrotation(p);

	return p;
}


struct Node * inorder(struct Node *p)
{
	//printf("\ntraversal in INORDER : ");
	if(p!=NULL)
	{
		inorder(p->lchild);
		printf("%d -->",p->data);		
		inorder(p->rchild);
		
	}
	
}


void main()
{
	root=RInsert(root,50);
 	RInsert(root,10);
	 RInsert(root,20);
	RInsert(root,40);
	RInsert(root,2);
	RInsert(root,11);
	RInsert(root,91);
	inorder(root);
}



/*include <stdio.h>
#include<stdlib.h>
 
 typedef struct AVLTreeNode
{
    int data;
    struct AVLTreeNode*  left;
    struct AVLTreeNode*  right;
    int      height;
} node;
 
 
node* insert(  node *t,int data );
node* delete(  node *root,int data );
void PreOrder(node* root);
 
 

    get the height of a node

static int Height( node* root )
{
    if( root== NULL )
        return -1;
    else
        return root->height;
}
 

    get maximum value of two integers

static int max( int l, int r)
{
    return l > r ? l: r;
}
 

    perform a rotation between a X node and its left child
 
    note: call single_rotate_with_left only if X node has a left child

 
static node* SingleRotateLeft( node* X )
{
    node* W = NULL;
 
    W = X->left;
    X->left = W->right;
    W->right = X;
 
    X->height = max( Height( X->left ), Height( X->right ) ) + 1;
    W->height = max( Height( W->left ), X->height ) + 1;
    return W;  new root 
}
 

    perform a rotation between a node (W) and its right child
 
    note: call single_rotate_with_right only if
    the W node has a right child

 
static node* SingleRotateRight( node* W )
{
    node* X;
 
    X = W->right;
    W->right = X->left;
    X->left = W;
 
    W->height = max( Height( W->left ), Height( W->right ) ) + 1;
    X->height = max( Height( X->right ), W->height ) + 1;
 
    return X;   New root
}
 

 
    perform the left-right double rotation,
 
    note: call double_rotate_with_left only if z node has
    a left child and z 's left child has a right child

 
static node* DoubleRotateLeft( node* Z )
{
     Rotate between W and X 
    Z->left = SingleRotateRight( Z->left );
 
     Rotate between Z and X 
    return SingleRotateLeft( Z );
}
 

    perform the right-left double rotation
 
   notes: call double_rotate_with_right only if W has a
   right child and W's right child has a left child

 
 
 
static node* DoubleRotateRight( node* Y )
{
     rotate between Z and X 
    Y->right = SingleRotateLeft( Y->right );
 
     rotate between W and X 
    return SingleRotateRight( Y);
}
 

    insert a new node into the tree

node* insert( node* root,int data )
{
    if( root == NULL )
    {
        Create and return a one-node tree 
        root = (node*)malloc(sizeof(node));
        if( root == NULL )
        {
            fprintf (stderr, "Out of memory!!! (insert)\n");
            exit(1);
        }
        else
        {
            root->data = data;
            root->height = 0;
            root->left = root->right = NULL;
        }
    }
    else if( data < root->data )
    {
        root->left = insert(  root->left,data );
        if( Height( root->left ) - Height( root->right ) == 2 )
            if( data < root->left->data )
                root = SingleRotateLeft( root );
            else
                root = DoubleRotateLeft( root );
    }
    else if( data > root->data )
    {
        root->right = insert(  root->right,data );
        if( Height( root->right ) - Height( root->left ) == 2 )
            if( data> root->right->data )
                root = SingleRotateRight( root );
            else
                root = DoubleRotateRight( root );
    }
     Else X is in the tree already; we'll do nothing 
 
    root->height = max( Height( root->left ), Height( root->right ) ) + 1;
    return root;
}
 
 

    Recursively display AVL tree or subtree

void PreOrder(node* root)
{
    if (root == NULL)
        return;
    printf("%d",root->data);
 
    if(root->left != NULL)
        printf("(L:%d)",root->left->data);
    if(root->right != NULL)
        printf("(R:%d)",root->right->data);
    printf("\n");
 
    PreOrder(root->left);
    PreOrder(root->right);
}



 
int main()
{
    node *root=NULL ; 

 root=insert(root,4);
 root=insert(root,8);
 root=insert(root,15);
 root=insert(root,23);
 root=insert(root,16);
 root=insert(root,42);


    printf(" into the tree\n\n");
 
PreOrder(root); 
 
    return 0;
}*/








