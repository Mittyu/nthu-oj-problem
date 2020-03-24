#include <stdio.h>
#include <stdlib.h>
// #define ONLINE_JUDGE
typedef struct _node {
  int val;
  struct _node *left, *right;
} Node;
int n;
int *inorder;
int *preorder;
Node *tree;
Node *BuildTree(int, int);
void PostOrder(Node *);
int main() {
  Node *root;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  scanf(" %d", &n);
  tree = (Node *)malloc(sizeof(Node) * n);
  inorder = (int *)malloc(sizeof(int) * n);
  preorder = (int *)malloc(sizeof(int) * n);
  int i;
  for (i = 0; i < n; i++) {
    scanf(" %d", &inorder[i]);
  }
  for (i = 0; i < n; i++) {
    scanf(" %d", &preorder[i]);
  }
#ifndef ONLINE_JUDGE
  printf("%d\n", n);
  for (i = 0; i < n; i++) printf("%d ", inorder[i]);
  printf("\n");
  for (i = 0; i < n; i++) printf("%d ", preorder[i]);
  printf("\n");
#endif
  root = BuildTree(0, n - 1);
  PostOrder(root);
  printf("\n");

  return 0;
}
void PostOrder(Node *root) {
  if (root != NULL) {
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
  }
}
int pre_idx,  tree_idx;
Node *BuildTree(int inorder_start, int inorder_end) {
  if (inorder_start > inorder_end) return NULL;
  Node *root = &tree[tree_idx++];
  root->left = root->right = NULL;
  root->val = preorder[pre_idx++];
  if (inorder_start == inorder_end) return root;
  // find root->val in preorder array.
  int i;
  for (i = inorder_start; i <= inorder_end; i++) {
    if (inorder[i] == root->val) break;
  }
  root->left = BuildTree(inorder_start, i - 1);
  root->right = BuildTree(i + 1, inorder_end);
  return root;
}
