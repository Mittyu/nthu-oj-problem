#include "function.h"

#include <iostream>
#include <set>
namespace oj {
void insert(std::map<int, String> &m, int key, const std::string &str) {
  auto test = m.find(key);
  std::string tmp;
  // without String default constrctor, we cannot using m[key] to access
  // m[key].str.
  if (test == m.end()) {
    tmp = str;
  } else {
    tmp = str + test->second.str;
    m.erase(test);
  }
  m.insert(std::pair<int, String>(key, String(tmp)));
}
void output(const std::map<int, String> &m, int begin, int end) {
  for (auto &i : m) {
    if (i.first > end)
      break;
    else if (i.first >= begin)
      std::cout << i.second << ' ';
  }
}
void erase(std::map<int, String> &m, int begin, int end) {
  std::set<int> eraseKeys;
  for (auto &i : m) {
    if (i.first > end)
      break;
    else if (i.first >= begin)
      eraseKeys.insert(i.first);
  }

  for (auto key : eraseKeys) m.erase(key);
}

std::ostream &operator<<(std::ostream &out, const std::map<int, String> &m) {
  for (auto &i : m) out << i.second << ' ';
  return out;
}

}  // namespace oj
