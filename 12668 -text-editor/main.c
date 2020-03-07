#define MAX 110
#include<stdio.h>
#include<stdlib.h>

enum role{HEAD, REAR};

typedef struct _node{
    char c;
    struct _node *next, *prev;
} node;
void traversal(node *head, node *rear, int role){
    node *cur;
    if(role == HEAD){
        cur = head->next;
        while(cur != rear){
            printf("%c", cur->c);
            cur = cur->next;
        }
    }else{
        cur = rear->prev;
        while(cur != head){
            printf("%c", cur->c);
            cur = cur->prev;
        }
    }
    printf("\n");
}
void insert_before(node **cur, char ch){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->c = ch;

    newNode->next = *cur;
    newNode->prev = (*cur)->prev;

    (*cur)->prev->next = newNode;
    (*cur)->prev = newNode;
}
void delete_before(node **cur){
    node *dNode = (*cur)->prev;

    dNode->prev->next = *cur;
    (*cur)->prev = dNode->prev;

    free(dNode);
}
void init_list(node **head, node **rear){
    // __init__ : head & rear dummy objects
    *head =  (node*)malloc(sizeof(node));
    *rear =  (node*)malloc(sizeof(node));
    (*head)->c = HEAD;
    (*rear)->c = REAR;
    (*head)->next = (*head)->prev = (*rear);
    (*rear)->next = (*rear)->prev = (*head);
}
void free_list(node **head, node **rear){
    node *cur = *rear;
    while(cur->prev != *head){
        delete_before(&cur);
    }
    free(*head);
    free(*rear);
}
int main(){
    int t, n, i;
    // using implement 2, dummy head and rear.
    node *head, *rear, *cur;
    char *text = (char*)malloc(sizeof(char));
    scanf(" %d", &t);

    while(t--){
        scanf(" %d %s", &n, text);
        init_list(&head, &rear);
        cur = rear;
        for(i=0; i<n; i++){
            if(text[i] == 'L'){
                cur = cur->prev;
            }else if(text[i] == 'R'){
                cur = cur->next;
            }else if(text[i] == 'B'){
                delete_before(&cur);
                traversal(head, rear, REAR);
                traversal(head, rear, HEAD);
            }else{
                insert_before(&cur, text[i]);
            }
        }
        traversal(head, rear, HEAD);
        free_list(&head, &rear);
    }


    return 0;
}

/*
2
15
aaaaaaLLLbbbBRc
16
aLRLRLRLRLRLRLRz


*/