#define MAX_LEN 32
#define A_VAL (idx>>3)%2
#define B_VAL (idx>>2)%2
#define C_VAL (idx>>1)%2
#define D_VAL idx%2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* s;
int pos, len, idx;
typedef struct _Node {
  char c;
  struct _Node *left, *right;
}Node;
Node* NewNode() {
  if(pos > len) return NULL;
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->c = s[pos++];
  newNode->left = newNode->right = NULL;
  return newNode;
}
Node* ConstructSyntaxTree() {
  Node* root = NewNode();
  if (root->c == '|' || root->c == '&') {
    root->left = ConstructSyntaxTree();
    root->right = ConstructSyntaxTree();
  }
  return root;
}
Node* head;
int cal(Node *root) {
  if(root == NULL) return -1;
  switch(root->c) {
    case 'A': return A_VAL;
    case 'B': return B_VAL;
    case 'C': return C_VAL;
    case 'D': return D_VAL;
    case '|': return cal(root->left) | cal(root->right);
    case '&': return cal(root->left) & cal(root->right);
    default : return -1;
  }
  return -1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  s = (char*)malloc(sizeof(char) * MAX_LEN);
  memset(s, 0, sizeof(char) * MAX_LEN);

  scanf(" %s", s);
  pos = 0;
  len = strlen(s) - 1;
  
  head = ConstructSyntaxTree();
  int ans;
  for (idx = 0; idx < 16; idx++) {
    ans = cal(head);
    printf("%d %d %d %d %d\n", A_VAL, B_VAL, C_VAL, D_VAL, ans);
  }

  return 0;
}