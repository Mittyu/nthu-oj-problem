#include "function.h"

#include <stdexcept>
using namespace std;

void List::InsertHead(int data) {
  ListNode *add_node = new ListNode(data);
  if (head == nullptr) {
    head = middle = tail = add_node;
    cnt = pos = 1;
    return;
  }
  add_node->next = head;
  head->prev = add_node;
  head = add_node;
  // change middle pointer
  cnt++;
  pos++;
  if (cnt / 2 + 1 < pos) {
    pos--;
    middle = middle->prev;
  }
}
void List::InsertTail(int data) {
  ListNode *add_node = new ListNode(data);
  if (tail == nullptr) {
    head = middle = tail = add_node;
    cnt = pos = 1;
  } else {
    add_node->prev = tail;
    tail->next = add_node;
    tail = add_node;
    // change middle pointer
    cnt++;
    if (cnt / 2 + 1 < pos) {
      pos++;
      middle = middle->next;
    }
  }
}
int List::RemoveHead() {
  if (head == nullptr) throw out_of_range("List is empty");
  int rvl = head->data;
  if (getSize() == 1) {
    delete head;
    reset();
    return rvl;
  }
  ListNode *nxt;
  nxt = head->next;
  nxt->prev = nullptr;
  delete head;
  head = nxt;

  cnt--;
  pos--;
  // example
  // 0 1 2 3 4
  // 1 2 3 4 5
  // 2 3 4 5
  if (cnt / 2 + 1 > pos) {
    pos++;
    middle = middle->next;
  }
  return rvl;
}
int List::RemoveTail() {
  if (tail == nullptr) throw out_of_range("List is empty");

  int rvl = tail->data;
  if (getSize() == 1) {
    delete tail;
    reset();
    return rvl;
  }

  ListNode *prv;
  prv = tail->prev;
  prv->next = nullptr;
  delete tail;
  tail = prv;

  cnt--;
  if (cnt / 2 + 1 < pos) {
    pos--;
    middle = middle->prev;
  }
  return rvl;
}

void List::Swap() {
  if (getSize() < 2) return;
  ListNode *old_mid = middle;
  ListNode *old_tail = tail;
  tail->next = head;
  head->prev = tail;

  if (cnt % 2 == 1) {
    // example
    // 0 1 2 3 4
    // 1 2 3 4 5
    // 3 4 5 1 2 
    // -> head = mid_old, 
    //    mid = tail_old, 
    //    tail = mid_old->prev
    head = old_mid;
    middle = old_tail;
    tail = old_mid->prev;
  } else {
    // example
    // 0 1 2 3 4 5
    // 1 2 3 4 5 6
    // 4 5 6 1 2 3
    // -> head = mid_old,
    //    mid = tail_old->next,
    //    tail = mid_old->prev
    head = old_mid;
    middle = old_tail->next;
    tail = old_mid->prev;
  }

  head->prev = tail->next = nullptr;
}
int List::getSize() { return cnt; }
int List::getMiddle() { return pos; }
