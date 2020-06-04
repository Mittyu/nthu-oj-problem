#include "function.h"
#include <sstream>

using namespace std;

void RleCodec::encode() {
  encoded = true;

  int cnt = 0; 
  char prev = '\0';
  stringstream ss;
  
  for (auto c : code_str) {
    if (c != prev) {
      if (cnt > 0) {
        if (cnt == 1)
          ss << prev;
        else if (cnt == 2)
          ss << prev << prev;
        else
          ss << cnt << prev;
      }
      prev = c;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  if (cnt > 0) {
    if (cnt == 1)
      ss << prev;
    else if (cnt == 2)
      ss << prev << prev;
    else
      ss << cnt << prev;
  }
  code_str = ss.str();
}

void RleCodec::decode() {
  encoded = false;
  stringstream ss, is;
  string int_str;

  for (auto c : code_str) {
    if (isdigit(c)) {
      int_str.push_back(c);
    } else {
      int cnt = 0;
      // type changing
      is << int_str;
      is >> cnt;
      //
      if (cnt == 0) { 
        ss << c;
      } else {
        for (int i = 0; i < cnt; i++)
          ss << c; 
      }
      // clear is stream buffer
      is.str("");
      is.clear();
      // clear int_str buffer
      int_str.clear();
    }
  }

  code_str = ss.str();
}