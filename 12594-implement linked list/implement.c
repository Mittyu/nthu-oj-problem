#include"function.h"
#include<stdio.h>
#include<stdlib.h>
Node* createList(int *a, int size){
    Node *head, *lastNode, *newNode;
    head = (Node*)malloc(sizeof(Node));
    head->data = a[0];
    lastNode = head;
    for(int i=1; i<size; i++){
        newNode = (Node*) malloc (sizeof(Node));
        lastNode->next = newNode;
        newNode->data = a[i];
        lastNode = newNode;
    }
    newNode->next = NULL;
    return head;
}
void push_front(Node** head, int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}
void deleteElementByIdx(Node** head, int idx){
    Node *lastNode, *deleteNode;
    lastNode = *head;
    if(idx==0){
        deleteNode = *head;
        *head = (*head)->next;
    } else {
        for(int i=0; i<idx-1 && lastNode!=NULL; i++)
            lastNode = lastNode->next;
        if(lastNode == NULL ||lastNode->next == NULL) return;
        else deleteNode = lastNode->next;

        lastNode->next = deleteNode->next;
    }
    free(deleteNode);
}
Node* copyList(Node* head){
    Node *newListHead, *motherNode, *lastNode, *curNode;
    newListHead = (Node*)malloc(sizeof(Node));
    motherNode = head;
    newListHead->data = motherNode->data;
    lastNode = newListHead;
    motherNode = motherNode->next;
    for( ; motherNode!=NULL; motherNode=motherNode->next){
        curNode = (Node*)malloc(sizeof(Node));
        curNode->data = motherNode->data;
        lastNode->next = curNode;
        lastNode = curNode;
    }
    curNode->next = NULL;
    return newListHead;
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    if(idx1==idx2) return;
    Node *tmpNode, *nodeOne, *nodeTwo;
    tmpNode = *head;
    if(idx1>idx2){
        idx1 -= idx2;
        while(idx2--) tmpNode = tmpNode->next;
        nodeTwo = tmpNode;
        while(idx1--) tmpNode = tmpNode->next;
        nodeOne = tmpNode;
    } else {
        idx2 -= idx1;
        while(idx1--) tmpNode = tmpNode->next;
        nodeOne = tmpNode;
        while(idx2--) tmpNode = tmpNode->next;
        nodeTwo = tmpNode;
    }
    int tmp_data = nodeOne->data;
    nodeOne->data = nodeTwo->data;
    nodeTwo->data = tmp_data;
}