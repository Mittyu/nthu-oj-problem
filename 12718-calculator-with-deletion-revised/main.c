#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  long long val;
  int size;
  char type;
  struct node *left, *right, *parent;
} Node;

Node* head;
Node* buildTree() {
  char c = getchar();
  Node* root = (Node*)malloc(sizeof(Node));
  root->val = 0;
  root->type = c;
  root->size = 1;
  root->left = root->right = root->parent = NULL;

  if (c == '+' || c == '-' || c == '*') {
    root->left = buildTree();
    root->left->parent = root;
    root->right = buildTree();
    root->right->parent = root;
    root->size = root->size + root->left->size + root->right->size;
  } else
    root->val = (int)(c - '0');

  return root;
}
Node* find(int a) {
  Node* pt = head;
  int idx = 1, tmp;
  while (1) {
    /*---find a---*/
    if (idx == a) break;

    /*---go left---*/
    tmp = pt->left->size;
    if (a > idx && a <= idx + tmp) {
      pt = pt->left;
      idx++;
      continue;
    }

    /*---go right---*/
    idx = idx + tmp;
    tmp = pt->right->size;
    if (a > idx && a <= idx + tmp) {
      pt = pt->right;
      idx++;
      continue;
    }
  }
  return pt;
}
void Q(int a) {
  Node* cur = find(a);
  printf("%lld\n", (cur->val % 10007 + 10007) % 10007);
}
void update_size_and_value(Node* pt) {
  if (pt == NULL) return;

  pt->size = 1 + pt->left->size + pt->right->size;
  switch (pt->type) {
    case '+' :
      pt->val = (pt->left->val + pt->right->val) % 10007;
      break;
    case '-' :
      pt->val = (pt->left->val - pt->right->val) % 10007;
      break;
    case '*':
      pt->val = (pt->left->val * pt->right->val) % 10007;
      break;
    default:
      break;
  }
  update_size_and_value(pt->parent);
}
void D(int a, int b) {
  Node *nodeA, *orphan;
  nodeA = find(a);
  orphan = find(b + 1);

  /*---link up nodeA->orphan---*/
  if (nodeA->parent != NULL) {
    if (nodeA->parent->left == nodeA)
      nodeA->parent->left = orphan;
    else
      nodeA->parent->right = orphan;
  } else head = orphan;
  /*--link up orphan->nodeA---*/
  orphan->parent = nodeA->parent;
  /*---resize and revalue from orphan---*/
  update_size_and_value(orphan->parent);
}
long long update_all_value (Node* pt) {
  switch (pt->type)
  {
  case '+':
    pt->val = (update_all_value(pt->left) + update_all_value(pt->right)) % 10007;
    break;
  case '-':
    pt->val = (update_all_value(pt->left) - update_all_value(pt->right)) % 10007;
    break;
  case '*':
    pt->val = (update_all_value(pt->left) * update_all_value(pt->right)) % 10007;
    break;
  default:
    break;
  }
  return pt->val;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int n, i;
  scanf("%d\n", &n);
  head = buildTree();
  update_all_value(head);
  char op;
  int para_a, para_b;
  for (i = 0; i < n; i++) {
    scanf(" %c", &op);
    if (op == 'D') {
      scanf(" %d %d", &para_a, &para_b);
      D(para_a, para_b);
    } else if (op == 'Q') {
      scanf(" %d", &para_a);
      Q(para_a);
    }
  }

  return 0;
}