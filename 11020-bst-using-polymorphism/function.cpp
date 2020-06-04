#include "function.h"
#define array_size 1025
Array_BST::Array_BST() : BST() {
  // insert A > 0
  for (int i = 0; i < array_size; i++)
    array[i] = 0;
}

void Array_BST::insert(const int &src) {
  //root node is stored at index 1.
  // insert src > 0
  int i, cnt;
  for ( i = 1, cnt = 0; i < array_size; ) {
    cnt++;
    if (array[i] == 0) {
      array[i] = src;
      break;
    } else if (src < array[i]) {
      i = i * 2;
    } else if (src > array[i]) {
      i = i * 2 + 1;
    } else if (src == array[i]) {
      return;
    }
  }
  if (cnt > Height) Height = cnt;

  if (i == array_size) cerr << "OUT OF RANGE" << endl;

}

bool Array_BST::search(const int &src) const {
  int i;
  for ( i = 1; i < array_size; ) {
    if (array[i] == 0)
      return false;
    else if (src == array[i])
      return true;
    else if (src < array[i])
      i = i * 2;
    else
      i = i * 2 + 1;
  }
  return false;
}

List_BST::List_BST() : BST() {
  root = nullptr;
}

void List_BST::insert(const int & src) {
  if (root == nullptr) {
    root = createLeaf(src);
    Height = 1;
    return;
  }
  int cnt = 1;
  ListNode* cur = root;
  while (true) {
    cnt++;
    if (src < cur->key) {
      if (cur->left == nullptr) {
        cur->left = createLeaf(src);
        break;
      } else {
        cur = cur->left;
      }
    } else if (src > cur->key) {
      if (cur->right == nullptr) {
        cur->right = createLeaf(src);
        break;
      } else {
        cur = cur->right;
      }
    } else {
      return;
    }
  }
  if (cnt > Height) Height = cnt;
}
bool List_BST::search(const int &src) const {
  ListNode* cur = root;
  while (true) {
    if (cur == nullptr)
      return false;
    else if (cur->key == src)
      return true;
    else if (src < cur->key)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

ListNode* List_BST::createLeaf(int key) const {
  //new a ListNode and return its address
  ListNode* root = new ListNode(key);
  
  if (root == nullptr) cerr << "MEMORY LEAK" << endl;

  return root;
}  
/* clean a tree.*/
void List_BST::deleteTree(ListNode *root) {
  if (root != nullptr) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
}