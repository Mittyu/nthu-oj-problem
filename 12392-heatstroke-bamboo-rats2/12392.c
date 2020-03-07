#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#include "function.h"
#endif
#define MAX_N 10000
#ifndef ONLINE_JUDGE
int n, q;
int a[MAX_N];
#include "12392.h"


int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	Node *root = NULL;
	build_tree(&root,a,0,n-1);
	scanf("%d",&q);
	char op[20];
	while(q--) {
		int x;
		scanf("%s",op);
		scanf("%d",&x);
		if(strcmp(op,"heatstroke")==0) {
			if(query_heatstroke(root,x)!=0) {
				puts("We might as well eat it.");
				eat_rat(&root,x);
			}
			else puts("No dinner tonight.");
		}
		else if(strcmp(op,"buy")==0) {
			buy_rat(&root,x);
		}
	}
	return 0;
}
#endif

void build_tree(Node **now, int *arr, int l, int r){
	if (l > r) return;
	
	int mid = ( l + r ) / 2;
	*now = (Node*) malloc (sizeof(Node));
	(*now)->level = arr[mid];
	(*now)->left_child = NULL;
	(*now)->right_child = NULL;
	build_tree(&(*now)->left_child, arr, l, mid-1);
	build_tree(&(*now)->right_child, arr, mid + 1, r);
}
int query_heatstroke(Node *now, int x){
	// tell if there exists a node with level equals to x.
	while (now) {
		if ( now->level == x)
			return 1;
		else if ( now->level > x)
			now = now->left_child;
		else 
			now = now->right_child;
	}
	return 0;
}
void eat_rat(Node **root, int x){
	Node* cur = *root;
	Node* par = NULL;

	// find node with level x.
	while ( cur->level != x ) {
		par = cur;
		if ( cur->level > x )
			cur = cur->left_child;
		else 
			cur = cur->right_child;
	}

	if ( cur == NULL ) return;

	// three situation.
	// with no child.
	if ( cur->left_child == NULL && cur->right_child == NULL) {
		if ( cur == (*root) ) {
			*root = NULL;
		} else {
			if ( par->left_child == cur )
				par->left_child = NULL;
			else 
				par->right_child = NULL;
		}
		free(cur);
	} 
	// with two children.
	else if ( cur->left_child != NULL && cur->right_child != NULL) {
		Node* cloest = cur->left_child;
		int val;

		while ( cloest->right_child != NULL )
			cloest = cloest->right_child;
		
		val = cloest->level;
		eat_rat(&cur->left_child, val);
		cur->level = val;
	} 
	// with one children.
	else {
		Node* child;
		if ( cur->left_child )
			child = cur->left_child;
		else 
			child = cur->right_child;
		
		if ( cur == *root ) {
			*root = child;
		} else {
			if ( par->left_child == cur )
				par->left_child = child;
			else
				par->right_child = child;
		}
		free(cur);
	}
}

void buy_rat(Node **root, int x){
	// insert a node with level equals to x.
	Node** now = root;
	while (*now != NULL) {
		if ( (*now)->level > x ) 
			now = &(*now)->left_child;
		else
			now = &(*now)->right_child;
	}

	*now = (Node*) malloc (sizeof(Node));
	(*now)->level = x;
	(*now)->left_child = NULL;
	(*now)->right_child = NULL;
}

/*
3
1 8 309
6
heatstroke 309
heatstroke 8
heatstroke 8
heatstroke 1
buy 5
heatstroke 5 
*/