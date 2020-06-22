#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define MAX_MOVE 80
int goalRow[] = {-1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
int goalCol[] = {-1, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};

class State {
 public:
  int puzzle[4][4];
  int heuristic;
  int curMove;
  int preMove;
  int ex, ey;

  State(int puzzle[4][4]) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) this->puzzle[i][j] = puzzle[i][j];
    curMove = 0;
    preMove = -1;
    ex = ey = -1;
    setHeuristic();
  }
  State(const State& s) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) 
        this->puzzle[i][j] = s.puzzle[i][j];
    curMove = s.curMove;
    preMove = s.preMove;
    ex = s.ex;
    ey = s.ey;
    heuristic = s.heuristic;
  }

  void setHeuristic() {
    int h = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (puzzle[i][j]) {
          int goalX = goalRow[puzzle[i][j]];
          int goalY = goalCol[puzzle[i][j]];

          // calculate Manhatten distance
          h += abs(goalX - i) + abs(goalY - j);
          // Linear conflict * 2
          if (i == goalX) {  // same row
            for (int k = j; k < 4; k++) {
              if (puzzle[i][k] > 0 && goalRow[puzzle[i][k]] == i &&
                  puzzle[i][j] > puzzle[i][k])
                h += 2;
            }
          }
          if (j == goalY) {  // same col
            for (int k = i; k < 4; k++) {
              if (puzzle[k][j] > 0 && goalCol[puzzle[k][j]] == j &&
                  puzzle[i][j] > puzzle[k][j])
                h += 2;
            }
          }

        }  // end if puzzle[i][j]
      }    // end for j loop
    }      // end for i loop
    this->heuristic = h;
  }  // end setHeuristic

  void update(int dir, int newx, int newy) {
    preMove = dir;  // record moving dir
    swap(puzzle[ex][ey], puzzle[newx][newy]);

    ex = newx;
    ey = newy;

    curMove++;

    setHeuristic();
  }

  bool operator<(const State& rhs) const {
    // cmp F value (F = cur_cost + point_cost)
    return (curMove + heuristic) > (rhs.curMove + rhs.heuristic);
  }
};

int main() { 
  int puzzle[4][4];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      cin >> puzzle[i][j];
  
  State s = State(puzzle);
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      if (!puzzle[i][j]){
        s.ex = i;
        s.ey = j;
      }
    }
  }

  priority_queue<State> pq;
  pq.push(s);
  // down, up, right, left
  const int dx[] = {1, -1, 0, 0};
  const int dy[] = {0, 0, 1, -1};

  while (!pq.empty()) {
    State curState = pq.top();

    if (curState.heuristic == 0) {  // goal
      cout << curState.curMove << endl;
      break;
    }

    pq.pop();

    if (curState.heuristic + curState.curMove > MAX_MOVE) // must be a wrong path
      continue;
    
    // expand by moving empty tile
    for (int i = 0; i < 4; i++) {
      int newX = curState.ex + dx[i];
      int newY = curState.ey + dy[i];

      // check boundary
      if (newX < 0 || newX > 3 || newY < 0 || newY > 3)
        continue;
      
      // check swap repeatedly
      if (i == (curState.preMove ^ 1))
        continue;
      
      State nextState = curState;
      nextState.update(i, newX, newY);
      pq.push(nextState);
    }
  }

  if (pq.empty()) // no solution
    cout << -1 << endl;

  return 0; 
}