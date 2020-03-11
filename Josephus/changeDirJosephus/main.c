// doublely linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int data;
    struct _node *prev;
    struct _node *next;    
} node; 

void init(node** head, node** tail){
    *head = (node*)malloc(sizeof(node));
    (*head)->data = 1;
    *tail = *head;
    (*head)->next = (*head)->prev = *tail;
    (*tail)->prev = (*tail)->next = *head;
}
void insert_before(node **curNode, int idx, node **head, node **tail){
    node *newNode = (node*)malloc(sizeof(node));
    node *preNode = (*curNode)->prev;

    newNode->data = idx;

    newNode->next = *curNode;
    newNode->prev = preNode;

    preNode->next = newNode;
    (*curNode)->prev = newNode;

    if(*curNode==*head) *head = newNode;

}
void insert_after(node **curNode, int idx, node **head, node **tail){
    node *newNode = (node*)malloc(sizeof(node));
    node *nxtNode = (*curNode)->next;

    newNode->data = idx;

    newNode->next = nxtNode;
    newNode->prev = *curNode;

    (*curNode)->next = newNode;
    nxtNode->prev = newNode;

    if(*curNode==*tail) *tail = newNode;

}
void delete_before(node **curNode, node **head, node **tail){
    node *dNode = (*curNode)->prev;

    (*curNode)->prev = dNode->prev;
    dNode->prev->next = *curNode;

    if(dNode == *tail) *tail = (*head)->prev;
    else if(dNode == *head) *head = (*tail)->next;
    free(dNode);
}
void delete_after(node **curNode, node **head, node **tail){
    node *dNode = (*curNode)->next;

    (*curNode)->next = dNode->next;
    dNode->next->prev = (*curNode);

    if(dNode == *tail) *tail = (*head)->prev;
    else if(dNode == *head) *head = (*tail)->next;
    free(dNode);
}
void travel(node *head){
    node *cur = head;
    while(cur->next!=head){
        printf("%d ", cur->data);
        cur=cur->next;
    }
    printf("%d\n", cur->data);
}
void add_n(node **head, node **tail, int n){
    if(n<2) return;
    int i;
    for(i=2; i<=n; i++){
        insert_after(tail, i, head, tail); 
    }
}
void free_list(node **head, node **tail){
    node *cur = *head;
    while(cur->next != *head){
        delete_before(&cur, head, tail);
    }
    free(*head);
}
int Josephus(node **head, node **tail , int n, int m){
    node *cur = *head;
    int i, dead=0;
    while(dead != n-1){
        for(i=1; i<m-1; i++){
            cur = cur->next;
        }
        delete_after(&cur, head, tail);
        dead++;
        if(dead == n-1) break;
        for(i=1; i<m-1; i++){
            cur = cur->prev;
        }
        delete_before(&cur, head, tail);
        dead++;
    }
    *head = *tail = cur;
    return cur->data;
}
int main(int argc, char* argv[]){
    node *head, *tail; // addictive tail, for change the dir.
    init(&head, &tail);
    int n, m;
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    add_n(&head, &tail, n);
    travel(head);
    printf("Josephus: %d\n", Josephus(&head, &tail, n, m));
    free_list(&head, &tail);

    return 0;
}