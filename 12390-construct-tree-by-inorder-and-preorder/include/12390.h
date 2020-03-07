#include <stdlib.h>
#include <stdio.h>
#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number
typedef struct _NODE
{
	int number;
	struct _NODE *ptr_to_right_node;
	struct _NODE *ptr_to_left_node;
} Node;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end);

void showPostorder(Node* root);

void freeTree(Node *root);
int pre_idx;
Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
	if (inorder_start > inorder_end)
		return NULL;
	
	Node* root = (Node*) malloc ( sizeof(Node) );
	root->num = preorder[pre_idx++];
	root->left = NULL;
	root->right = NULL;
	
	if (inorder_start == inorder_end)
		return root;

    int	rootInorderIndex = inorder_start;

	while (inorder[rootInorderIndex] != root->num && rootInorderIndex <= inorder_end)
		rootInorderIndex++;
	
	root->left = buildTree(inorder, preorder, inorder_start, rootInorderIndex-1);
	root->right = buildTree(inorder, preorder, rootInorderIndex+1, inorder_end);
	return root;
}


void showPostorder(Node* root){
	if (root){
		showPostorder(root->left);
		showPostorder(root->right);
		printf("%d ", root->num);
	}
}

void freeTree(Node *root){
	if (root){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
	pre_idx = 0;
}
/*
9
1 2 3 4 5 6 7 8 9
1 2 4 3 6 9 8 7 5
9
3 7 8 6 11 2 5 4 9
3 8 11 6 7 4 9 5 2
*/
