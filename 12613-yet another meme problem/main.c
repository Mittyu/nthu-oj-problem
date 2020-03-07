#include<stdio.h>
int main(){
    int n, i, minus;
    long long int A, B;

    scanf("%d", &n);
    while(n--){
        scanf("%lld %lld", &A, &B);

        i=minus=0;
        while (B>0) {
            // B = 9, 99, 999...
            if (B%9!=0) minus=1;
            B /= 10;
            i++;
        }

        if (minus)
            printf("%lld\n", A * (i-1));
        else
            printf("%lld\n", A * i);
    }
}
/*
3
1 11
4 2
191 31415926

*/