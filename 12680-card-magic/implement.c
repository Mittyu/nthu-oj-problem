#include <stdio.h>
#include <stdlib.h>
#ifndef ONLINE_JUDGE
#include "12680.h"
#endif
#ifdef ONLINE_JUDGE
#include "function.h"
#endif

Node* ReadOneList() {
  int n, i;
  scanf(" %d", &n);
  Node* new_head = (Node*)malloc(sizeof(Node));
  int* data = (int*)malloc(sizeof(int) * n);
  /*-----get out ":"----*/
  getchar();
  for (i = 0; i < n; i++) scanf(" %d", &data[i]);
  new_head->size = n;
  new_head->data = data;
  new_head->next = NULL;
  return new_head;
}
void PrintList(Node* dummy_head) {
  Node* cur = dummy_head->next;
  int i;
  while (cur != NULL) {
    for (i = 0; i < cur->size - 1; i++) printf("%d ", cur->data[i]);
    printf("%d\n", cur->data[i]);
    cur = cur->next;
  }
}
void Merge(Node* dummy_head, int x, int y) {
  // merge x-th stack and y-th stack
  // y is base
  if (x == y) return;
  int i, j;
  Node* stack_x = NULL;
  Node* stack_y = NULL;
  Node* cur = dummy_head->next;
  Node* pre_x = dummy_head;
  for (i = 1; (i <= x || i <= y) && cur != NULL; i++) {
    if (i == x - 1) pre_x = cur;
    if (i == x) stack_x = cur;
    if (i == y) stack_y = cur;
    cur = cur->next;
  }
  if (stack_x == NULL || stack_y == NULL) return;

  int total_size = stack_x->size + stack_y->size;
  int* data = (int*)malloc(sizeof(int) * (total_size));
  for (i = 0; i < stack_y->size; i++) data[i] = stack_y->data[i];
  for (j = 0; j < stack_x->size; j++, i++) data[i] = stack_x->data[j];
  stack_y->data = data;
  stack_y->size = total_size;
  pre_x->next = stack_x->next;
  free(stack_x->data);
  free(stack_x);
}
void Cut(Node* dummy_head, int x, int y) {
  // x is base, y is data divider
  int i, j;
  Node* stack_x = dummy_head->next;

  i = 1;
  while (i < x) {
    stack_x = stack_x->next;
    i++;
  }

  if (stack_x == NULL || stack_x->data == NULL || stack_x->size < y) return;

  Node* new_node = (Node*)malloc(sizeof(Node));
  int* data_x = (int*)malloc(sizeof(int) * y);
  int* data_new = (int*)malloc(sizeof(int) * (stack_x->size - y));
  for (i = 0; i < y; i++) data_x[i] = stack_x->data[i];
  for (j = 0; i < stack_x->size; j++, i++) data_new[j] = stack_x->data[i];
  new_node->data = data_new;
  new_node->size = stack_x->size - y;

  stack_x->data = data_x;
  stack_x->size = y;
  if (stack_x->next == NULL) {
    new_node->next = NULL;
    stack_x->next = new_node;
  } else {
    new_node->next = stack_x->next;
    stack_x->next = new_node;
  }
}
