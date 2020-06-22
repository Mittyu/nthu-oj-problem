#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "function.h"

int idx, N;
int* PreOrder;
Node *RealBuild(int min, int max) {
  if (idx >= N) return NULL;
  Node *root = NULL;
  if (min < PreOrder[idx] && PreOrder[idx] < max) {
    root = (Node*) malloc(sizeof(Node));
    root->key = PreOrder[idx++];
    root->ltree = RealBuild(min, root->key);
    root->rtree = RealBuild(root->key, max);
  }
  return root;
}
Node *buildBST(int n, int *perOrder) {
  idx = 0, N = n, PreOrder = perOrder;
  return RealBuild(INT_MIN, INT_MAX);
}
void printInOrder(Node *ptr) {
  if (ptr != NULL) {
    printInOrder(ptr->ltree);
    printf("%d ", ptr->key);
    printInOrder(ptr->rtree);
  }
}

void printPostOrder(Node *ptr) {
  if (ptr != NULL) {
    printPostOrder(ptr->ltree);
    printPostOrder(ptr->rtree);
    printf("%d ", ptr->key);
  }
}

void freeTree(Node *ptr) {
  if (ptr != NULL) {
    freeTree(ptr->ltree);
    freeTree(ptr->rtree);
    free(ptr);
  }
}