#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos;
char dataBus[256];

typedef struct _Node {
  char data;
  struct _Node *left, *right;
} Node;

Node* NewNode() {
  Node* root = (Node*) malloc(sizeof(Node));
  root->data = dataBus[pos--];
  root->left = root->right = NULL;
  return root;
}
Node* FACTOR();
Node* EXPR() {
  Node* right = FACTOR();

  if(pos == -1 || dataBus[pos] == '(') return right;

  Node* root = NewNode();
  root->right = right;
  root->left = EXPR();
  return root;
}

Node* FACTOR() {
  if(dataBus[pos] == ')') {
    pos--;
    Node* Factorized = EXPR();
    pos--;
    return Factorized;
  } else return NewNode();
}
void Preorder(Node* root) {
  if(root != NULL) {
    printf("%c", root->data);
    Preorder(root->left);
    Preorder(root->right);
  }
}
void Parentheses(Node* root) {
  if (root != NULL) {
    Parentheses(root->left);
    printf("%c", root->data);
    if (root->right == NULL) return;
    if (root->right->data == '&' || root->right->data == '|') {
      printf("(");
      Parentheses(root->right);
      printf(")");
    } else Parentheses(root->right);
  }
}
int main() {
  scanf(" %s", dataBus);
  pos = strlen(dataBus) - 1;
  
  Node* root = EXPR();
  Parentheses(root);
  return 0;
}
