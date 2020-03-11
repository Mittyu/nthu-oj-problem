#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
    int num;
    struct _node *next, *prev;    
} node;
void init(node **head, node **middle, node **tail){
    *head = (node*)malloc(sizeof(node));
    *tail = (node*)malloc(sizeof(node));
    *middle = *head;
    (*head)->num = (*tail)->num = 0;
    (*head)->prev = (*head)->next = *tail;
    (*tail)->prev = (*tail)->next = *head;
}
void update_middle(node **head, node **middle, node **tail, int position_delta){
    int total = (*head)->num, cur_position = (*tail)->num + position_delta;
    if(total == 1){
        *middle = (*head)->next;
        cur_position = 0;
    }else if(total/2 - cur_position > 0){ 
        *middle = (*middle)->next;
        cur_position++;
    }else if(total/2 - cur_position < 0){
        *middle = (*middle)->prev;
        cur_position--;
    }
    
    (*tail)->num = cur_position;
}
void insert_head(node **head, node **middle, node **tail, int num){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->next = (*head)->next;
    new_node->prev = *head;
    new_node->num = num;

    (*head)->next->prev = new_node;
    (*head)->next = new_node;
    
    (*head)->num++;
    update_middle(head, middle, tail, 1);
}
void insert_tail(node **head, node **middle, node **tail, int num){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->next = *tail;
    new_node->prev = (*tail)->prev;
    new_node->num = num;

    (*tail)->prev->next = new_node;
    (*tail)->prev = new_node;

    (*head)->num++;
    update_middle(head, middle, tail, 0);
}
void remove_head(node **head, node **middle, node **tail){
    node *delete_node = (*head)->next;
    delete_node->next->prev = *head;
    (*head)->next = delete_node->next;
    printf("%d\n", delete_node->num);
    free(delete_node);
    
    (*head)->num--;
    update_middle(head, middle, tail, -1);
}
void remove_tail(node **head, node **middle, node **tail){
    node *delete_node = (*tail)->prev;
    delete_node->prev->next = *tail;
    (*tail)->prev = delete_node->prev;
    printf("%d\n", delete_node->num);
    free(delete_node);

    (*head)->num--;
    update_middle(head, middle, tail, 0);
}
void swap_element(node **head, node **middle, node **tail){
    node *middle_tmp = *middle, *tail_prev = (*tail)->prev, 
         *head_next = (*head)->next, *middle_prev = (*middle)->prev;

    (*head)->next = middle_tmp;
    middle_tmp->prev = *head;

    (*tail)->prev = middle_prev;
    middle_prev->next = *tail;

    tail_prev->next = head_next;
    head_next->prev = tail_prev;

    *middle = tail_prev;
}
void traversal(node *head, node *tail, int mode){
    node *cur;
    if(mode == 0){
        cur = head->next;
        while(cur != tail){
            printf("%d ", cur->num);
            cur = cur->next;
        }
    }else{
        cur = tail->prev;
        while(cur != head){
            printf("%d ", cur->num);
            cur = cur->prev;
        }
    }
    printf("\n");
}
int main(){
    int num;
    char instruction[3];
    node *head, *middle, *tail;
    init(&head, &middle, &tail);
    while(scanf(" %s", instruction) != EOF){
        if(strcmp(instruction, "IH") == 0){
            scanf(" %d", &num);
            insert_head(&head, &middle, &tail, num);
        }else if(strcmp(instruction, "IT") == 0){
            scanf(" %d", &num);
            insert_tail(&head, &middle, &tail, num);
        }else if(strcmp(instruction, "RH") == 0){
            remove_head(&head, &middle, &tail);
        }else if(strcmp(instruction, "RT") == 0){
            remove_tail(&head, &middle, &tail);
        }else if(strcmp(instruction, "S") == 0){
            swap_element(&head, &middle, &tail);
        }else{
            break;
        }
    }
    traversal(head, tail, 0);
    // traversal(head, tail, 1);
    // printf("middel: %d\n", middle->num);
}

/*
IT 10
IH 27
IT 2011
IT 114
IH 207
S
RT
RH

ED

IT 1
IT 2
IT 3
IT 4
IT 5
S

ED

IH 5
IH 4
IH 3
IH 2
IH 1

ED


*/