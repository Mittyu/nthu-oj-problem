#include "function.h"

#ifndef ONLINE_JUDGE
#define ONLINE_JUDGE
#include <stdio.h> 
#include <stdlib.h>
#define ll long long int

int main(){
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF ){
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}

#endif

Node *createList(int n){
    // create a circle list
    Node* head = NULL;
    head = (Node*) malloc(sizeof(Node));
    head->number = n;
    head->next = head;

    return head;
}
void freeList(Node* head){
    
}
int solveJosephus(Node **head, int step){
    Node* curr = *head;
    int s = 0;
    for (int i = 2; i <= curr->number; i++)
        s = (s+step) % i;
    return s + 1;
}


