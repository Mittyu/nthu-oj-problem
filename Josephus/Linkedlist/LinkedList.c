#include<stdio.h>
#include<stdlib.h>

typedef struct _man{
    int id;
    struct _man *next;
} man;
void init(man** head){
    *head = (man*)malloc(sizeof(man));
    (*head)->id=1;
    (*head)->next=head;
}
void add(man** head, int n){
    man *cp=*head;
    for(int i=2; i<=n; i++){
        cp->next=(man*)malloc(sizeof(man));
        cp=cp->next;
        cp->id=i;
        cp->next=*head;
    }
}
void insert(man** curNode, int idx){
    
}
void delete(man** preNode){
    man *cp = *preNode, *p = (*preNode)->next;
    cp->next = p->next;
    free(p);
}
int Josephus(man** head, int n, int m){

}
void free(man** head){

}
int main(int argc, char argv[]){
    man *head;
    init(&head);
    int n, m;
    n=atoi(argv[1]);
    m=atoi(argv[2]);

    add(&head, n);
    printf("%d\n",Josephus(&head, n, m));

    free(&head);
    return 0;
}