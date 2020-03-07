#define MAX 200000
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, newMin, min;
    long long int*  dst = (long long int*)  malloc (sizeof(int) * MAX);
    char* dir = (char*) malloc (sizeof(char) * MAX);
    scanf("%d", &n);
    scanf("%s", dir);
    min = -1;
    for (int i=0; i<n; i++)
        scanf("%lld", &dst[i]);
    for (int i=0; i<n-1; i++){
        if (dir[i] == 'R' && dir[i+1] == 'L') {
            if (min == -1){
                min = (dst[i+1] - dst[i])/2;
            }else{
                newMin = (dst[i+1] - dst[i])/2;
                if (newMin < min) min = newMin;
            }
        }
    }
    printf("%d\n", min);
    return 0;
}
