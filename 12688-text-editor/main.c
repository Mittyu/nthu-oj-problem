#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum role{HEAD, REAR};

typedef struct _node{
    char c;
    struct _node *next, *prev;
} node;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int t, n, i;
    char c;
    // using implement 2, dummy head and rear.
    node *head, *rear, *cur, *delete_node, *new_node;
    scanf("%d", &t);

    while(t--){
        // cin >> n >> text;
        scanf("%d", &n);
        // init_list(head, rear)
        head = (node*)malloc(sizeof(node));
        rear = (node*)malloc(sizeof(node));
        head->c = HEAD, rear->c = REAR;
        head->prev = rear->next = NULL;
        head->next = rear, rear->prev = head;
        // printf("%d\n", n);
        cur = rear;
        getchar();
        for(i=0; i<n; i++){
            c = getchar();
            // printf("%c ", c);
            if(c == 'L'){
                if(cur->prev != NULL)
                    cur = cur->prev;
            }else if(c == 'R'){
                if(cur->next != NULL)
                    cur = cur->next;
            }else if(c == 'B'){
                // delete_before
                if(cur->prev == head || cur->prev == NULL) break;
                delete_node = cur->prev;
                delete_node->prev->next = cur;
                cur->prev = delete_node->prev;

                free(delete_node);
            }else{
                // insert_before
                if(cur->prev == NULL) break;
                new_node = (node*)malloc(sizeof(node));
                new_node->c = c;
                new_node->next = cur;
                new_node->prev = cur->prev;

                cur->prev->next = new_node;
                cur->prev = new_node;
            }
        }
        // traversal
        cur = head->next;
        while(cur != rear){
            printf("%c", cur->c);
            cur = cur->next;
        }
        printf("\n");
        // // back traversal
        // cur = rear->prev;
        // while(cur != head){
        //     printf("%c", cur->c);
        //     cur = cur->prev;
        // }
        // printf("\n");
        // free list
        cur = rear;
        while(cur->prev != head){
            delete_node = cur->prev;
            
            delete_node->prev->next = cur;
            cur->prev = delete_node->prev;

            free(delete_node);
        }
        free(head);
        free(rear);
    }


    return 0;
}

/*
2
15
aaaaaaLLLbbbBRc
16
aLRLRLRLRLRLRLRz

3
15
aaaLLLbbbRRRccc
15
abcdefghijklmno
16
aLRLRLRLRLRLRLRz

*/