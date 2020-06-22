#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <string>

using namespace std;

map<char, char> parens = {
  {'{', '}'},
  {'[', ']'},
  {'(', ')'},
  {'<', '>'}
};

int main() {
  
  int T;
  cin >> T;
  
  string str;
  getline(cin, str);

  for (int i = 1; i < T + 1; i++) {
    stack<char> stk;
    getline(cin, str);
    bool valid = true;
    for (auto c : str) {
      if (c == '{' or c == '[' or c == '(' or c == '<')
        stk.push(c);
      else if (c == '}' or c == ']' or c == ')' or c == '>') {
        if (stk.empty() or parens[stk.top()] != c) {
          valid = false;
          break;
        } else 
          stk.pop();
      } 
    } // end for str

    if (!stk.empty()) valid = false;

    cout << "Case " << i << ": ";
    if (valid)
      cout << "Yes\n";
    else
      cout << "No\n";
  } // end for T

  return 0;
} // end main