#include <climits>
#include <iostream>
using namespace std;

class Node {
 public:
  explicit Node(int val = 0) : val(val), left(nullptr), right(nullptr) {}
  ~Node() {
    if (this->left) free(this->left);
    if (this->right) free(this->right);
  }
  int val;
  Node* left;
  Node* right;
};
void PreOrder(Node* root) {
  if (root != nullptr) {
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
  }
}
int CheckDownReturnRound(Node* root, bool needPruned, int rangeMax,
                         int rangeMin) {
  if (root == nullptr) return 1;
  int lRound = 0, rRound = 0;
  if (root->val < rangeMin || root->val > rangeMax) needPruned = true;
  // check left subtree rounds
  if (root->left != nullptr)
    lRound = CheckDownReturnRound(root->left, needPruned,
                                  min(root->val, rangeMax), rangeMin);
  // check right subtree rounds
  if (root->right != nullptr)
    rRound = CheckDownReturnRound(root->right, needPruned, rangeMax,
                                  max(root->val, rangeMin));
  // determine root rounds
  int r = max(lRound, rRound);
  if (root->left == nullptr && root->right == nullptr)
    r = 1;
  else
    r++;
  // assigned root->val if need
  if (needPruned) root->val = -r;
  return r;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d\n", &n);
  Node* root = nullptr;
  Node* nodeArr = new Node[n];

  int i;
  for (i = 0; i < n; i++) cin >> nodeArr[i].val;

  int idx;
  char dir;
  for (i = 0; i < n; i++) {
    cin >> idx;
    if (idx == 0)
      root = &nodeArr[i];
    else {
      idx--;
      cin >> dir;
      if (dir == 'L')
        nodeArr[idx].left = &nodeArr[i];
      else
        nodeArr[idx].right = &nodeArr[i];
    }
  }
  CheckDownReturnRound(root, false, INT_MAX, INT_MIN);

  for (i = 0; i < n - 1; i++) cout << nodeArr[i].val << " ";
  cout << nodeArr[i].val << endl;

  return 0;
}