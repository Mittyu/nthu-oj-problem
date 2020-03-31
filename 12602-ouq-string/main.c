#define ll long long int
#include <stdio.h>
int k;
ll len[53], l, r, idx;

void solve (int k) {
    if(idx + len[k] <= l) {
        idx += len[k];
    } else if (idx <= r) {
        if (idx >= l && idx <= r) printf("O");
        idx++;
        if (k > 1 && idx <= r) solve(k-1);
        if (idx >= l && idx <= r) printf("u");
        idx++;
        if (k > 1 && idx <= r) solve(k-1);
        if (idx >= l && idx <= r) printf("Q");
        idx++;
    }
    return ;
}

void lenk(int k) {
  int i;
  len[0] = 0;
  for (i = 1; i <= k; i++) len[i] = len[i - 1] * 2 + 3;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    lenk(50);
    while( scanf(" %d %lld %lld\n", &k, &l, &r) != EOF ) {
        idx = 0;
        solve(k);
        printf("\n");
    }


    return 0; 
}
