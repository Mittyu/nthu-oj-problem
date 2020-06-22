#include<iostream>
#include<algorithm>
#include<queue>
#include<list>
#include<string>

using namespace std;

int main() {

  int N, id, num;
  string command;
  list<int> line;
  queue<int> country[3];

  cin >> N;
  while (N--) {
    cin >> command;
    if (command == "ENQUEUE") {
      cin >> id;  
      // find country
      num = id % 3;
      country[num].push(id);
      if (find(line.begin(), line.end(), num) == line.end())
        line.push_back(num);
    } else if (command == "DEQUEUE") {
      num = line.front();
      cout << country[num].front() << endl;
      country[num].pop();
      if (country[num].empty()) line.pop_front();
    }
  }
  return 0;
}