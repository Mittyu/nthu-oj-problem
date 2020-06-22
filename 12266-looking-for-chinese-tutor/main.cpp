#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
  map<string, string> mapping = {
    {"Wa",	"Waninoko"},
    {"Mi",   "Milotic"},
    {"Ma",	"Magikarp"},
    {"Va",	"Vaporeon"},
    {"Sh",	"Sharpedo"},
    {"Tapu","Tapu Fini"},
    {"Em",	"Empoleon"},
    {"La",	"Lapras"},
    {"Pi",	"Pikachu"},
    {"Pe",	"Pikachu"},
    {"Me",	"Mega Gyarados"}
  };  
  int N;
  cin >> N;

  string name, school;
  bool canTeach;
  while (N--) {
    cin >> name >> school;

    canTeach = false;
    for (auto &p : mapping) {
      if (name.substr(0, p.first.size()) == p.first) {
        canTeach = true;
        cout << name << " the " << school << " " << p.second << "\n";
        break;
      }
    }
    if (!canTeach)
      cout << name << " is looking for a Chinese tutor, too!\n";  
  }



  return 0;
}