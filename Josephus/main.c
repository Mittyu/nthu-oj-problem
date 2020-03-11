#define MAX 100
#define DEAD 0
#define ALIVE 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 1-st algorithm -- array with move,
// which is slow and unnessary.
// 2-nd algorithm -- array with mark
// 3-rd algorithm -- linked list
// 4-th algorithm -- recurrence relation
// 5-th algorithm -- iterative solution
int Josephus2(int n, int m);
int Josephus3(int n, int m);
int Josephus4(int n, int m);
int Josephus5(int n, int m);
int main(){
    int n, m;
    clock_t begin, end;
    scanf(" %d %d", &n, &m);

    begin = clock();
    printf("Josephus2, array with mark: %d\n", Josephus2(n, m));
    end = clock();
    printf("\n--Execute time: %ld ms\n\n\n", end-begin);

    begin = clock();
    printf("Josephus3, Linked List: %d\n", Josephus3(n, m));
    end = clock();
    printf("\n--Execute time: %ld ms\n\n\n", end-begin);

    begin = clock();
    printf("Josephus4, Recurrence Relation: %d\n", Josephus4(n, m)+1);
    end = clock();
    printf("\n--Execute time: %ld ms\n\n\n", end-begin);

    begin = clock();
    printf("Josephus5, Iterative solution: %d\n", Josephus5(n, m)+1);
    end = clock();
    printf("\n--Execute time: %ld ms\n\n\n", end-begin);

    return 0;
}

// 2-nd algorithm -- array with mark
int Josephus2(int n, int m){
    int count=0, dead=0, cur=1, *people=(int*)malloc(MAX*sizeof(int));
    for(int i=0; i<n; i++) people[i]=ALIVE; // Init_People

    while(dead<n-1){
        if(people[cur] == ALIVE){
            count++;
            if(count%m==0){
                people[cur] = DEAD;
                dead++;
            }
        }
        cur++;
        cur%=n;
    }
    cur=0;
    while(people[cur]==DEAD&&cur<n) cur++;

    return cur;
}
// 3-rd algorithm -- linked list
typedef struct _Person{
    int status;
    struct _Person* next;
}Person;
void initPerson(Person* p){
    int i=1;
    for(; p!=NULL; p=p->next, i++)
        p->status=i;
}
int Josephus3(int n, int m){
    // build a linked list
    Person *head, *cur, *pre;
    cur = (Person*)malloc(sizeof(Person));
    head = cur;
    for(int i=1; i<n; i++){
        cur->next = (Person*)malloc(sizeof(Person));
        cur = cur->next;
    }
    initPerson(head);
    cur->next = head;
    pre=cur;
    cur=head;
    // start calculate
    int count=0, dead=0;
    while(dead<n-1){
        if(cur->status!=DEAD){
            count++;
            if(count%m==0){
                pre->next=cur->next;
                cur->status=DEAD;
                dead++;
            }
        }
        pre=cur;
        cur=cur->next;
    }
    while(cur->status==DEAD) cur=cur->next;

    return cur->status;

}
// 4-th algorithm -- recurrence relation
int Josephus4(int n, int m){
    if(n==0) return 0;

    // find the first person dead in
    // J(n, m), s.t, J(n, m)=(J(n-1, m)+k)%n
    int k=m%n;
    return (Josephus4(n-1, m)+k)%n;
}

// 5-th algorithm -- iterative solution
int Josephus5(int n, int m){
    int ans=0;
    for(int i=2; i<=n; ++i){
        ans=(ans+m)%i;
    }
    return ans;
}