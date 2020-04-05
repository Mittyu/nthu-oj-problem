#include <stdio.h>

#include "function.h"

void printInfix(Node* root) {
  // inorder traversal
  if (root != NULL) {
    printInfix(root->left);
    printf("%c", root->data);
    if (root->right == NULL) return;
    if (root->right->data == '&' || root->right->data == '|') {
      printf("(");
      printInfix(root->right);
      printf(")");
    } else
      printInfix(root->right);
  }
}