#include <stdio.h>
#include<stdlib.h>
typedef struct t_node{
	int val;
	struct t_node *left,*right;
}Node;

int posIdx;

Node *newNode(int val){
	Node *new_n=(Node*)malloc(sizeof(Node));
	new_n->left=new_n->right=NULL;
	new_n->val=val;
	
	return new_n;
}

Node *buildTree(int *inorder,int *postorder,int in_start,int in_end){
	if (in_start > in_end) return NULL;
	
	Node *root=newNode(postorder[posIdx--]);
	
	if (in_start==in_end) return root;
	
	int i;
	for (i=in_start;i<=in_end;i++){
		if (root->val==inorder[i]) break;
	}
	
	root->left=buildTree(inorder,postorder,in_start,i-1);
	root->right=buildTree(inorder,postorder,i+1,in_end);
	
	return root;
}

void showPreorder(Node *root){
	if (root){
		printf("%d ",root->val);
		showPreorder(root->left);
		showPreorder(root->right);
	}
}

void freeTree(Node *root){
	if (root){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main(void){
	int cases=1;
	int n,i;
	while(~scanf("%d",&n)){
		posIdx=n-1;
		int inorder[100],postorder[100];
		for (i=0;i<n;i++) scanf("%d",&inorder[i]);
		for (i=0;i<n;i++) scanf("%d",&postorder[i]);
		
		Node *root=buildTree(inorder,postorder,0,n-1);
		
		printf("testcase%d: ",cases++);
		showPreorder(root);
		printf("\n");
		freeTree(root);
	}
	return 0;
}