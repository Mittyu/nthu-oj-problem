#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

BTNode* makeNode(char c) {
  pos--;
  BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
  newNode->left = newNode->right = NULL;
  switch (c)
  {
  case 'A':
    newNode->data = ID_A;
    break;
  case 'B':
    newNode->data = ID_B;
    break;
  case 'C':
    newNode->data = ID_C;
    break;
  case 'D':
    newNode->data = ID_D;
    break;
  case '&':
    newNode->data = OP_AND;
    break;
  case '|':
    newNode->data = OP_OR;
    break;
  default:
    break;
  }
  return newNode;
}

BTNode* EXPR() {
  BTNode* right_expr = FACTOR();
  /*---Catch the end of an expression, i.e. '('.---*/
  if(pos == -1 || expr[pos] == '(') return right_expr;
  
  BTNode* root = makeNode(expr[pos]);
  root->right = right_expr;
  root->left = EXPR();
  return root;
}
BTNode* FACTOR() {
  char input = expr[pos];
  /*---Catch a beginning of the expression---*/
  if(input == ')') { 
    pos--;  // for catching ')'.
    BTNode* factorize = EXPR();
    pos--;  // for catching '('.
    return factorize;
  }
  /*------Catch an ID, return Dirctly-------*/
  else return makeNode(input);
}