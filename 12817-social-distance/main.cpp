#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Seg {
  int left, right;
  explicit Seg(int l, int r) : left(l), right(r) {}
};

struct Cmp {
  bool operator()(const Seg &lhs, const Seg &rhs) const {
    int l_len = (lhs.right - lhs.left) / 2;
    int r_len = (rhs.right - rhs.left) / 2;
    if (l_len != r_len)
      return l_len > r_len;  // bigger seg is better
    else
      return lhs.left < rhs.left;  // smaller index is better
  }
};

int main() {
  char cmd;
  int n, m, s, x, D;
  set<int> pos;        // set to record taken seats
  set<Seg, Cmp> seg;   // set to record segs
  vector<int> id2pos;  // vec to record student seat

  cin >> n >> m >> s;         // n seats, m students, s safe distance
  D = n + 1;                  // default min distance
  id2pos.resize(m + 1, 1);    // m students => range from 1 ~ m
  pos.insert(0);              // left wall
  pos.insert(n + 1);          // right wall
  seg.insert(Seg(0, n + 1));  // initial seg.

  // process events
  for (int i = 0; i < 2 * m; i++) {
    cin >> cmd >> x;
    if (cmd == 'i') {
      auto it = seg.begin();
      int left = it->left, right = it->right;
      int mid = (left + right) / 2;
      if (left != 0)  // ensure left of taken seat is not left wall
        D = min(mid - left, D);
      if (right != n + 1)  // ensure right of taken seat is not right wall
        D = min(right - mid, D);
      seg.erase(it);
      seg.insert(Seg(left, mid));
      seg.insert(Seg(mid, right));
      id2pos[x] = mid;  // record seat of x
      pos.insert(mid);  // record taken seats
    } else if (cmd == 'o') {
      int mid = id2pos[x];      // find seat of x
      auto it = pos.find(mid);  // try to find left and right of mid
      auto left_it = it, right_it = it;
      int left = *(--left_it), right = *(++right_it);

      seg.erase(Seg(left, mid));
      seg.erase(Seg(mid, right));
      seg.insert(Seg(left, right));
      id2pos[x] = -1;
      pos.erase(mid);
    }
  }
  if (D >= s)
    cout << "YES\n";
  else
    cout << "NO\n";

  if (D == n + 1)
    cout << "INF\n";
  else
    cout << D << "\n";

  return 0;
}