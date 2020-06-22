#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class State {
 public:
  int lv, hp, mhp;
  int dist;
  explicit State(int l, int h, int m, int d = 0)
      : lv(l), hp(h), mhp(m), dist(d) {}
};

bool vis[20][310][410];

int main() {
  int lv, hp, mhp, mdmg;
  int dmg[20], hl[20];

  cin >> lv >> hp >> mhp >> mdmg;
  for (int i = 1; i <= lv; i++) cin >> dmg[i] >> hl[i];

  queue<State> q;  // for BFS
  q.push(State(1, hp, mhp));

  while (!q.empty()) {
    State s = q.front();

    // mhp <= 0, wins the game.
    if (s.mhp <= 0) break;
    q.pop();
    
    // update vis table
    if (vis[s.lv][s.hp][s.mhp]) continue;
    vis[s.lv][s.hp][s.mhp] = true;
    
    // next state
    // 1. attack
    if (s.hp > mdmg || s.mhp <= dmg[s.lv])  // attack first !!
      q.push(State(s.lv, s.hp - mdmg, s.mhp - dmg[s.lv], s.dist + 1));
    // 2. level up
    if (s.lv < lv && s.hp > mdmg)
      q.push(State(s.lv + 1, s.hp - mdmg, s.mhp, s.dist + 1));
    // 3. heal
    if (s.hp < hp && s.hp + hl[s.lv] > mdmg)
      q.push(State(s.lv, min(s.hp + hl[s.lv], hp) - mdmg, s.mhp, s.dist + 1));
  }

  if (q.empty())
    cout << -1 << endl;
  else
    cout << q.front().dist << endl;

  return 0;
}