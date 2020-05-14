#include "function.h"

#include <iostream>
#include <limits>

using namespace std;

List_stack::List_stack() {
  head = new ListNode(__INT_MAX__);  // dummy head
  tail = new ListNode(__INT_MAX__);  // dummy tail
  head->nextPtr = tail;
  tail->prevPtr = head;
  head->prevPtr = tail->nextPtr = nullptr;
}

void List_stack::push(const int& info) {
  ListNode* ptr = new ListNode(info);
  ptr->prevPtr = tail->prevPtr;
  ptr->nextPtr = tail;

  tail->prevPtr->nextPtr = ptr;
  tail->prevPtr = ptr;
}

void List_stack::pop() {
  if (tail->prevPtr == head) return;

  ListNode* deleteNode = tail->prevPtr;
  deleteNode->prevPtr->nextPtr = tail;
  tail->prevPtr = deleteNode->prevPtr;

  delete (deleteNode);
}

void List_stack::print() {
  if (head->nextPtr == tail) return;

  ListNode* curNode = tail->prevPtr;

  while (curNode->prevPtr != head) {
    cout << curNode->data << " ";
    curNode = curNode->prevPtr;
  }
  cout << curNode->data;
}

List_stack::~List_stack() {
  delete (this->head);
  delete (this->tail);
}