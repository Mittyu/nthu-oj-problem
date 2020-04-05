#include <stdio.h>
#include <string.h>
int main() {
  freopen("input.txt", "r", stdin);

  int T, N, M[110][110];
  int checkBox[110];
  int x, k, r, c;
  scanf(" %d", &T);

  int i, j;
  for (x = 1; x <= T; x++) {
    scanf(" %d", &N);
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        scanf(" %d", &M[i][j]);
      }
    }
    k = 0;
    for (i = 0; i < N; i++) {
      k += M[i][i];
    }
    r = 0;
    for (i = 0; i < N; i++) {
      memset(checkBox, 0, sizeof(int) * 110);
      for (j = 0; j < N; j++) {
        if (checkBox[M[i][j]] == 0)
          checkBox[M[i][j]]++;
        else {
          r++;
          break;
        }
      }
    }
    c = 0;
    for (j = 0; j < N; j++) {
      memset(checkBox, 0, sizeof(int) * 110);
      for (i = 0; i < N; i++) {
        if (checkBox[M[i][j]] == 0)
          checkBox[M[i][j]]++;
        else {
          c++;
          break;
        }
      }
    }
    printf("Case #%d: %d %d %d\n", x, k, r, c);
  }

  return 0;
}