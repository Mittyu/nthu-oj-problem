#include <stdio.h>
#include <stdlib.h>
#define ONLINE_JUDGE
int n;
int *inorder;
int *preorder;
// Node *tree;
void PostTree(int, int);
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  scanf(" %d", &n);
  inorder = (int *)malloc(sizeof(int) * n);
  preorder = (int *)malloc(sizeof(int) * n);
  int i;
  for (i = 0; i < n; i++) scanf(" %d", &inorder[i]);
  for (i = 0; i < n; i++) scanf(" %d", &preorder[i]);
#ifndef ONLINE_JUDGE
  printf("%d\n", n);
  for (i = 0; i < n; i++) printf("%d ", inorder[i]);
  printf("\n");
  for (i = 0; i < n; i++) printf("%d ", preorder[i]);
  printf("\n");
#endif
  PostTree(0, n - 1);
  printf("\n");

  return 0;
}
int pre_idx;
void PostTree(int inorder_start, int inorder_end) {
    if (inorder_start > inorder_end) return;
  int i;
  for (i = inorder_start; i <= inorder_end; i++)
    if (inorder[i] == preorder[pre_idx]) break;
  pre_idx++;
  PostTree(inorder_start, i - 1);
  PostTree(i + 1, inorder_end);
  printf("%d ", inorder[i]);
}