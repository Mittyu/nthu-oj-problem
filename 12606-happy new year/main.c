#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int min, max, tmp;
    scanf("%d", &min);
    max = min;
    while (n--) {
        scanf("%d", &tmp);
        if (tmp < min)
            min = tmp;
        else if (tmp > max)
            max = tmp;
    }
    printf("%d\n", (max - min) * 2);
    return 0;
}