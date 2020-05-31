#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node *root = NULL;

int isEmpty() {
	return (root == NULL);
}

void insertData(int item) {
	struct Node *curr = root, *parent = NULL, *n;

	// search for a place to insert new node
	while(curr != NULL) {
		parent = curr;
		if(curr->data == item) {
			printf("\n\n Duplicate not allowed");
			return;
		}
		else if(item < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	// Create a new node
	n = (struct Node *) malloc(sizeof(struct Node));
	n->data = item;
	n->left = NULL;
	n->right = NULL;

	if(parent == NULL)  // if tree is empty
		root = n;
	else if(item < parent->data)
		parent->left = n;
	else
		parent->right = n;
}

void preOrder(struct Node *n) {
	if(n != NULL) {
		printf("%d ", n->data);
		preOrder(n->left);
		preOrder(n->right);
	}
}

void inOrder(struct Node *n) {
	if(n != NULL) {
		inOrder(n->left);
		printf("%d ", n->data);
		inOrder(n->right);
	}
}

void postOrder(struct Node *n) {
	if(n != NULL) {
		postOrder(n->left);
		postOrder(n->right);
		printf("%d ", n->data);
	}
}


void main() {
	insertData(50);
	insertData(25);
	insertData(20);
	insertData(30);
	insertData(70);
	insertData(75);
	insertData(45);
	insertData(65);
	insertData(90);
	insertData(55);
	printf("\n\nPre Order Traversal\n");
	preOrder(root);
	printf("\n\nIn Order Traversal\n");
	inOrder(root);
	printf("\n\nPost Order Traversal\n");
	postOrder(root);
}
