#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct _NODE
{
    int level;
    struct _NODE *left_child, *right_child;
} Node;

void build_tree(Node **now, int *arr, int l, int r){
	if (l>r) return;
	
	(*now)=(Node*)malloc(sizeof(Node));
	(*now)->left_child=(*now)->right_child=NULL;
	
	if (l==r){
		(*now)->level=arr[l];
		(*now)->left_child=(*now)->right_child=NULL;
	}
	else{
		int mid=(l+r)/2;
		
		(*now)->level=arr[mid];
		
		build_tree(&(*now)->left_child,arr,l,mid-1);
		build_tree(&(*now)->right_child,arr,mid+1,r);
	}
}

int query_heatstroke(Node *now, int x){
	if (now==NULL) return 0;
	else if(now->level==x) return 1;
	else if(now->level > x) return query_heatstroke(now->left_child,x);
	else return query_heatstroke(now->right_child,x);
}

void eat_rat(Node **root, int x){
	Node *cur=(*root);
	Node *parent;
	
	while(cur->level!=x){
		if (cur->level > x){
			parent=cur;
			cur=cur->left_child;
		}else if (cur->level < x){
			parent=cur;
			cur=cur->right_child;
		}
	}
	
	if (cur==NULL) return ;
	
	if (cur->left_child==NULL && cur->right_child==NULL){
		if (cur!=(*root)){
			if(parent->left_child==cur) parent->left_child=NULL;
			else parent->right_child=NULL;
		}else{
			(*root)=NULL;
		}
		free(cur);
	}
	else if(cur->left_child!=NULL && cur->right_child!=NULL){
		Node *small=cur->left_child;
		int val;
		
		while(small->right_child!=NULL){
			small=small->right_child;
		}
		
		val=small->level;
		eat_rat(&(cur->left_child),val);
		cur->level=val;
	}
	else {
		Node*child;
		if (cur->left_child) child=cur->left_child;
		else child=cur->right_child;
		
		if (cur==(*root)) (*root)=child;
		else{
			if (parent->left_child==cur) parent->left_child=child;
			else parent->right_child=child;
		}

		free(cur);
	}
}

void buy_rat(Node **root, int x){
	Node **now=root;
	while((*now) != NULL){
		if ((*now)->level > x) now=&((*now)->left_child);
		else now=&((*now)->right_child);
	}
	
	(*now)=(Node *)malloc(sizeof(Node));
	(*now)->level=x;
	(*now)->left_child=(*now)->right_child=NULL;
}
