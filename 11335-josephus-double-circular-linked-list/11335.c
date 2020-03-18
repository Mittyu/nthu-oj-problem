#include <stdio.h>
#include <stdlib.h>
#include "function.h"

// void traversal(){
//     Node *cur = head;
//     while(cur->next != head){
//         printf("%d ", cur->number);
//         cur=cur->next;
//     }
//     printf("%d\n", cur->number);
// }
// int main(){

//     int n, m;

//     while(scanf("%d%d", &n, &m)!=EOF){
//         head = createList(n);
//         // traversal();
//         printf("%d\n", solveJosephus(m));
//         freeList();
//     }

//     return 0;
// }
Node* createList(int n){
    int idx=1;
    Node *cur;
    head = (Node*)malloc(sizeof(Node));
    head->number = idx;
    head->prev = head->next = NULL;
    cur = head;
    while(n-- != 1){
        cur->next = (Node*)malloc(sizeof(Node));
        cur->next->prev = cur;
        cur = cur->next;
        cur->number = ++idx;
        // printf("creat: %d\n", cur->number);
    }
    cur->next = head;
    head->prev = cur;
    return head;
}

void freeList(){
    Node *cur = head;
    while(cur->next != head){
        cur->next = cur->next->next;
        free(cur);
    }
    free(head);
    // printf("delete all elements\n");
}
int solveJosephus(int step){
    int count;
    Node *cur = head, *delete_node;
    count=1;
    while(cur->next != cur){
        while(1){
            if(count%step == 0){
                delete_node = cur;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                cur = cur->prev;
                if(delete_node == head) head = delete_node->prev;
                free(delete_node);
                count=1;
                break;
            }
            cur = cur->next;
            count++;
        }
        if(cur->next == cur) break;
        while(1){
            if(count%step == 0){
                delete_node = cur;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                cur = cur->next;
                if(delete_node == head) head = delete_node->next;
                free(delete_node);
                count=1;
                break;
            }
            cur = cur->prev;
            count++;
        }
    }
    return cur->number;
}

