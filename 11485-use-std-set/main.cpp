#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int getValue(vector<int> v) {
  int sum = 0;
  for (size_t i = 0; i < v.size(); i++) sum += v.at(i) * (v.size() - i);
  return sum;
}
vector<int> readVector() {
  int i = 0;
  vector<int> v;
  while (cin >> i) {
    if (i == 0) break;
    v.push_back(i);
  }
  return v;
}
void printVector(vector<int> v) {
  for (auto& i : v) cout << i << " ";
  cout << endl;
}

struct mycompare {
  bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
    return getValue(lhs) < getValue(rhs);
  }
};

int main() {
  set<vector<int>, mycompare> s;
  string command;
  while (cin >> command) {
    if (command == "insert") {
      vector<int> r = readVector();
      int sum_new = getValue(r);

      for (auto v : s) {
        if (getValue(v) == sum_new) {
          cout << "exit\n";
          s.erase(v);
          r.reserve(r.size());
        }
      }

      s.insert(r);
    } else if (command == "range_out") {
      int begin = getValue(readVector());
      int end = getValue(readVector());

      for (auto v : s) {
        int curVal = getValue(v);
        if (curVal > end)
          break;
        else if (curVal >= begin)
          printVector(v);
      }

    } else if (command == "output") {
      for (auto v : s) printVector(v);
    }
  }
  return 0;
}