#include "function.h"

#include <sstream>
#include <vector>
// TODO: Encode the code_str
void Base64Codec::encode() {
  encoded = true;
  vector<int> v;
  const int len = code_str.length();
  for (size_t i = 0; i < len; i++)
    v.push_back((int)code_str[i]);
  // for not enough 
  v.push_back(0);

  int input_num, cnt = 0;
  string ans;
  
  for (size_t i = 0; i < len; cnt++) {
    switch(cnt & 3) {
      case 0 : 
        // v[i] front 6-bits.
        input_num = v[i] >> 2;
        break;
      case 1 :
        // v[i] post 2-bits, v[i+1] front 4-bits.
        input_num = ((v[i] & 3) << 4) + (v[i + 1] >> 4);
        i++;       
        break;
      case 2 :
        // v[i] post 4-bits, v[i+1] front 2-bits. 
        input_num = ((v[i] & 15) << 2) + (v[i + 1] >> 6);
        i++;
        break;
      case 3 :
        // v[i] post 6-bits.
        input_num = (v[i] & 63);
        i++;
        break;
    }
    ans = ans + encodeCharacter(input_num);
  }
  if ((cnt & 3) == 2)
    ans = ans + "==";
  else if ((cnt & 3) == 3)
    ans = ans + "=";

  code_str = ans;
}
