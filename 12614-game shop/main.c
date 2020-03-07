#define MAX 1000
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, m, i, j;
    int* cost = (int*) malloc (sizeof(int) * MAX);
    int* bill = (int*) malloc (sizeof(int) * MAX);    
    
    scanf("%d %d", &n ,&m);
    for (i=0; i<n; i++) scanf("%d", &cost[i]);
    for (i=0; i<m; i++) scanf("%d", &bill[i]);

    for (i=0, j=0; i<n; i++)
        if (cost[i] <= bill[j]) j++;
    
    printf("%d\n", j);

    return 0;
}