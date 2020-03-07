
// #define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#include "function.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#ifndef ONLINE_JUDGE

#include "12390.h"

#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number

int n;

int main(void){
	int id = 1;
    while( ~scanf( "%d", &n ) ){
		int inorder[100],preorder[100];
		
		for( int i = 0; i < n; i++ )
			scanf( "%d", &inorder[i] );

		for( int i = 0; i < n; i++ )
			scanf( "%d", &preorder[i] );

		Node *root = buildTree( inorder, preorder, 0, n-1 );

		printf("testcase%d: ", id++);
		showPostorder(root);
		printf("\n");
		freeTree(root);
	}
    return 0;
}

#endif
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