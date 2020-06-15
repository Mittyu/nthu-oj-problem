#include "function.h"

bool Color::operator<(const Color& other) const {
  if (this->r > other.r )
    return false;
  if (this->r < other.r)
    return true;
  if (this->g > other.g ) 
    return false;
  if (this->g < other.g)
    return true;
  if (this->b >= other.b)
    return false;

  return true;
}
bool Color::operator>(const Color& other) const {
  if (this->r < other.r )
    return false;
  if (this->r > other.r )
    return true;
  if (this->g < other.g ) 
    return false;
  if (this->g > other.g ) 
    return true;
  if (this->b <= other.b)
    return false;

  return true;
}
bool Color::operator==(const Color& other) const {
  if (this->r == other.r && this->g == other.g && this->b == other.b)
    return true;

  return false;
}
Color& Color::operator=(const Color& other) {
  this->r = other.r;
  this->g = other.g;
  this->b = other.b;
  return *this;
}

Node::Node() {
  value = 1;
  left = right = nullptr;
}
Node::~Node() {}

MultiSet_Tree::MultiSet_Tree() { root = nullptr; }

void delete_tree(Node* root) {
  if (root != nullptr) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }
}

MultiSet_Tree::~MultiSet_Tree() { delete_tree(root); }

Node* Find_Pos(Node* root, const Color& target) {
  Node* cur = root;
  while (cur != nullptr) {
    if (target == cur->key)
      return cur;
    else if (target < cur->key)
      cur = cur->left;
    else
      cur = cur->right;
  }
  return nullptr;
}

Node* Find_Par(Node* root, const Color& target) {
  Node* par, *cur;
  par = cur = root;

  while (cur != nullptr) {
    if (target == cur->key)
      return par;
    else if (target < cur->key) {
      par = cur;
      cur = cur->left;
    } else {
      par = cur;
      cur = cur->right;
    }
  }
  return nullptr;
}

void MultiSet_Tree::Insert(const Color& targetColor) {
  if (root == nullptr) {
    root = new Node();
    root->key = targetColor;
    return;
  }
  Node* target = Find_Pos(root, targetColor);
  if (target == nullptr) {
    target = new Node();
    target->key = targetColor;
    Node* cur = root;
    while (1) {
      if (targetColor < cur->key) {
        if (cur->left) {
          cur = cur->left;
        } else {
          cur->left = target;
          break;
        }
      } else {
        if (cur->right) {
          cur = cur->right;
        } else {
          cur->right = target;
          break;
        }
      }
    }
  } else {
    target->value++;
  }
}
void MultiSet_Tree::Delete(const Color& targetColor) {
  Node* target = Find_Pos(root, targetColor);
  // Case 1, not existing
  if (target == nullptr) 
    return;
  // Case 2, target exist with value > 1
  if (target->value > 1) {
    target->value--;
    return;
  }
  // Case 3, target with value == 1
  // Case 3-1, with no child
  if (target->left == nullptr && target->right == nullptr) {
    delete target;
    target = nullptr;
    return;
  }
  // Case 3-2, with two children
  else if (target->left && target->right) {
    Node* par = Find_Par(root, targetColor);
    
    Node* left_biggest_par = target;
    Node* left_biggest = target->left;
    while (left_biggest->right != nullptr) { 
      left_biggest_par = left_biggest;
      left_biggest = left_biggest->right;
    }
    // left_biggest may has left child
    if (target == left_biggest_par)
      target->left = left_biggest->left;
    else 
      left_biggest_par->right = left_biggest->left;

    target->key = left_biggest->key;
    target->value = left_biggest->value;
    delete left_biggest;
  }
  // Case 3-3, with one child
  else {
    if (target == root) {
      if (target->left)
        root = target->left;
      else
        root = target->right;
      delete target;
      target = nullptr;
      return;
    }
    Node* par = Find_Par(root, targetColor);
    
    if (target->left) par->left = target->left;
    else par->right = target->right;
    
    delete target;
    target = nullptr;
  }
  
  
}

const int MultiSet_Tree::Search(const Color& target) const {
  Node* cur = Find_Pos(root, target);
  if (cur)
    return cur->value;
  else
    return 0;
}