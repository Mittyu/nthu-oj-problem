#define MAX 100
#include <stdio.h>
#include <stdlib.h>

int posIdx;
typedef struct _Node
{
    int data;
    struct _Node* left;
    struct _Node* right;
}Node;

Node* newNode(int data){
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->data = data;
    return root;
}
Node* buildTree(int* inorder, int* postorder, int inorderStart, int inorderEnd){
    if (inorderStart > inorderEnd) return NULL;

    Node* root = newNode(postorder[posIdx--]);

    if (inorderStart == inorderEnd) return root;

    int rootIdx;
    for (rootIdx = inorderStart; rootIdx <= inorderEnd; rootIdx++)
        if (root->data == inorder[rootIdx]) break;

    // because Postorder: left right root, so back to the front should be right first.
    root->right = buildTree(inorder, postorder, rootIdx+1, inorderEnd);
    root->left = buildTree(inorder, postorder, inorderStart, rootIdx-1);
    return root;
}

void showPreorder(Node *root){
	if (root){
		printf("%d ",root->data);
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

int main(){
    int i, n;
    int* inorder = (int*) malloc (sizeof(int) * MAX);
    int* postorder = (int*) malloc (sizeof(int) * MAX);
    int cases = 1;
    while(~scanf("%d", &n)){
        posIdx = n-1;
        for (i = 0; i < n; i++) scanf("%d", &inorder[i]);
        for (i = 0; i < n; i++) scanf("%d", &postorder[i]);

        Node* root = buildTree(inorder, postorder, 0, n-1);
        
        printf("testcase%d: ", cases++);
        showPreorder(root);
        printf("\n");

        freeTree(root);
    }
    free(inorder);
    free(postorder);
    return 0;
}
