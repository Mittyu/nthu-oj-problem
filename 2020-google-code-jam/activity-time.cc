#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int T, N, S, E, TimeLine[1441][2];
  cin >> T;
  int x, i, j;
  bool C_valid, J_valid, possible;
  for (x = 1; x <= T; x++) {
    cin >> N;
    string ans = "";
    memset(TimeLine, 0, sizeof(TimeLine));
    possible = true;
    for (i = 0; i < N; i++) {
      cin >> S >> E;
      C_valid = true, J_valid = true;
      for (j = S; j < E; j++) if (TimeLine[j][0] != 0) C_valid = false;
      for (j = S; j < E; j++) if (TimeLine[j][1] != 0) J_valid = false;
  
      if (C_valid) { 
        ans += "C";
        for (j = S; j < E; j++) TimeLine[j][0] = 1;
      } else if (J_valid) {
        ans += "J";
        for (j = S; j < E; j++) TimeLine[j][1] = 1;
      } else {
        possible = false;
        break;
      }
    }
    cout << "Case #" << x << ": ";
    if (possible == false) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << ans << endl;
  }

  return 0;
}
