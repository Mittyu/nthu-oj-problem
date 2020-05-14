#include "function.h"

#include <cstring>
Str::Str(char* s) {
  int n = strlen(s);
  this->head = this->tail = new Char(s[0]);
  for (int i = 1; i < n; i++) {
    this->tail->next = new Char(s[i]);
    this->tail = this->tail->next;
  }
}

Str::Str(const Str& master) {  // copy constructor
  Char* l = master.head;
  this->head = this->tail = new Char(l->text);
  l = l->next;
  while (l != nullptr) {
    this->tail->next = new Char(l->text);
    this->tail = this->tail->next;
    l = l->next;
  }
}

Str& Str::strInsert(const Str& s2) {
  // newStr = s1s2
  Str* copyS2 = new Str(s2);
  this->tail->next = copyS2->head;
  this->tail = copyS2->tail;
  return *this;
}
