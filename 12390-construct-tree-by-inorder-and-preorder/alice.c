#include<stdio.h>
#include<stdlib.h>
#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number
int pre_idx=0;
typedef struct _NODE
{
	int number;
	struct _NODE *ptr_to_right_node;
	struct _NODE *ptr_to_left_node;
} Node;

Node *newNode(int val){
	Node* root=(Node* )malloc(sizeof(Node));
	root->number=val;
	root->left=NULL;
	root->right=NULL;
	
	return root;
}

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
	
	if (inorder_start > inorder_end) return NULL;
	
	int cur_val=preorder[pre_idx];
	Node *root=newNode(cur_val);
	pre_idx++;
	
	if (inorder_start == inorder_end) return root;
	
	int i;
	for(i=inorder_start;i<=inorder_end;i++){
		if (inorder[i]==cur_val) break;
	}
		
	
	root->left=buildTree(inorder,preorder,inorder_start,i-1);
	root->right=buildTree(inorder,preorder,i+1,inorder_end);
		
	return root;
}

void showPostorder(Node* root){
	
	if (root){
		showPostorder(root->left);
		showPostorder(root->right);
		printf("%d ",root->number);
	}

}

void freeTree(Node *root){
	
	if(root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
    pre_idx=0;
}
