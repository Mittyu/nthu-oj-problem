#include<stdio.h>
#include<stdlib.h>
#define MAX 1001

int main(){
    int n, m, input;
    scanf("%d%d", &n, &m);
    int min = 1000000000;
    for (int i = 0; i < n * m; i++){
        scanf("%d", &input);
        if (min > input) min = input;
    }
    printf("%d\n", min);
    return 0;
}

