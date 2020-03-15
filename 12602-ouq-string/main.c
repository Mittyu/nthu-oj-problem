#define MAX 200
#include<stdlib.h>
#include<stdio.h>
typedef struct _node{
    char *node[5];
}node;
int main(){
    char* string;
    int n, times, l, r;
    scanf(" %d", &n);
    while(n--){
        scanf(" %d %d %d", &times, &l, &r);
        string = ouq(times);
        printf("%s", string);
    }

    return 0;
}