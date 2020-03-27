#include <stdio.h>
#include <stdlib.h>

#include "function.h"

Node *buildDoublyCircularLinkedList(int n) {
  Node *head, *cur;
  int i = 1;
  head = createNode(i++);
  cur = head;
  for (i = 2; i <= n; i++) {
    cur->nextPtr = createNode(i);
    cur->nextPtr->prevPtr = cur;
    cur = cur->nextPtr;
  }
  cur->nextPtr = head;
  head->prevPtr = cur;

  return head;
}
Node *getNextPersonOut(int peopleLeft, int m, Node *startNode) {
  Node *cur = startNode;
  int cnt, step;
  step = (m - 1) % peopleLeft;
  if (peopleLeft == 2) {
    if (step % 2 == 1) cur = cur->nextPtr;
  } else if (step < peopleLeft / 2) {
    /*-----think of the spaces they have.-----*/
    for (cnt = 0; cnt < step; cnt++) cur = cur->nextPtr;
  } else {
    step = (peopleLeft - 1) - step;
    cur = cur->prevPtr;
    for (cnt = 0; cnt < step; cnt++) cur = cur->prevPtr;
  }
  return cur;
}
void connectNodes(Node *personInFront, Node *personInBack) {
  personInFront->nextPtr = personInBack;
  personInBack->prevPtr = personInFront;
}
void swapNodes(Node *personInFront, Node *personInBack) {
  personInFront->prevPtr->nextPtr = personInBack;
  personInBack->nextPtr->prevPtr = personInFront;

  personInFront->nextPtr = personInBack->nextPtr;
  personInBack->prevPtr = personInFront->prevPtr;

  personInFront->prevPtr = personInBack;
  personInBack->nextPtr = personInFront;
}