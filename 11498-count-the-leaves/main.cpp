#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {

  int N, i, x, y, rootnum;
  set<int> par_nodes;
  set<int> all_nodes;

  while (cin >> N) {
    if (N == 0) break;
    par_nodes.clear();
    all_nodes.clear();
    for (i = 0; i < N; i++) {
      cin >> x >> y;
      par_nodes.insert(x);
      all_nodes.insert(x);
      all_nodes.insert(y);      
    }
    cin >> rootnum;

    cout << all_nodes.size() - par_nodes.size() << endl;
  }


  return 0;
}