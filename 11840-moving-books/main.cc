#define MAX 30
#define HEAD -1
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, i, a, b;
  int* table_idx = new int[MAX];

  string config;
  cin >> n;
  // init()
  vector<int> tables[MAX];
  vector<int> temp;
  for (i = 0; i < n; i++) {
    tables[i].push_back(i);
    table_idx[i] = i;
  }
  // eat configurations
  while (1) {
    cin >> config;
    if (config == "move") {
      cin >> a >> config >> b;
      if (a == b || table_idx[a] == table_idx[b]) continue;
      // move all on the top of A
      auto cur = tables[table_idx[a]].back();
      while (cur != a) {
        tables[table_idx[a]].pop_back();
        tables[cur].push_back(cur);
        table_idx[cur] = cur;
        cur = tables[table_idx[a]].back();
      }
      if (config == "onto") {
        // move all on the top of B
        cur = tables[table_idx[b]].back();
        while (cur != b) {
          tables[table_idx[b]].pop_back();
          tables[cur].push_back(cur);
          table_idx[cur] = cur;
          cur = tables[table_idx[b]].back();
        }
      }
      // puts A onto B
      tables[table_idx[b]].push_back(a);
      tables[table_idx[a]].pop_back();
      table_idx[a] = table_idx[b];
    } else if (config == "pile") {
      cin >> a >> config >> b;
      if (a == b || table_idx[a] == table_idx[b]) continue;
      auto cur = tables[table_idx[b]].back();
      if (config == "onto") {
        // return all on the top of B, and puts all on the A onto B
        while (cur != b) {
          tables[table_idx[b]].pop_back();
          tables[cur].push_back(cur);
          table_idx[cur] = cur;
          cur = tables[table_idx[b]].back();
        }
      }
      // puts all on the A onto B
      // move all on the top of A
      cur = tables[table_idx[a]].back();
      while (cur != a) {
        tables[table_idx[a]].pop_back();
        temp.push_back(cur);
        table_idx[cur] = table_idx[b];
        cur = tables[table_idx[a]].back();
      }
      // puts A onto B
      temp.push_back(a);
      tables[table_idx[a]].pop_back();
      table_idx[a] = table_idx[b];
      while (!temp.empty()) {
        cur = temp.back();
        temp.pop_back();
        tables[table_idx[b]].push_back(cur);
      }
    } else if (config == "exit") {
      break;
    }
  }
  for (i = 0; i < n; i++) {
    cout << i << ":";
    for (auto iter : tables[i]) {
      cout << " " << iter;
    }
    cout << "\n";
  }
  return 0;
}