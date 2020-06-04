#define history_size 201
#include "function.h"
#include <climits>
#include <string>


enum op {greater, less, guess};


Engineer::Engineer() {
  count = 0;
  for (int i = 0; i < history_size; i++) {
    value_history[i] = action_history[i] =  0;
    answer_history[i] = false;
  }  
}

Engineer::~Engineer() {}
int min, mid, max;
void Engineer::init() {
  count = 0;
  min = INT32_MIN;
  mid = 0;
  max = INT32_MAX;
  action_history[0] = greater;
}

void Engineer::MakeQuery(char* query_str) {
  if (count == 0) {
    sprintf(query_str, "%s %d", "greater", mid);
  } else {
    if (action_history[0] == greater) {
      if (answer_history[0] == true)
        min = mid;
      else
        max = mid;
      if (min == INT32_MIN)
        mid = (min + max) / 2;
      else
        mid = min + (max - min) / 2;
      if (min == mid) 
        min = mid = max;
      if (mid == min) {
        sprintf(query_str, "%s %d", "guess", mid);
        action_history[0] = guess;
      } else {
        sprintf(query_str, "%s %d", "greater", mid);      
        action_history[0] = greater;
      }
    } else if (action_history[0] == guess) {
      mid = mid - 1;
      sprintf(query_str, "%s %d", "guess", mid);
    }
  }
}

void Engineer::GetAnswer(bool ans) {
  if (action_history[0] == guess && ans == true)
    init();
  else 
    answer_history[0] = ans;
  count++;
}