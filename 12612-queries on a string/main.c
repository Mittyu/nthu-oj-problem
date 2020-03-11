#define MAX 10000   
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, l, r, k, i;
    char* s = (char*) malloc (sizeof(char) * MAX);
    char* s_tmp = (char*) malloc (sizeof(char) * MAX);

    scanf("%s %d", s, &n);

    while (n--) {
        scanf("%d %d %d", &l, &r, &k);
        l--, r--;
        k=k%(r-l+1);
        for(i=l; i<=r; i++) {
            if (i+k<=r)
                s_tmp[i+k] = s[i];
            else
                s_tmp[i+k-(r-l+1)] = s[i];
        }
        for(i=l; i<=r; i++) s[i] = s_tmp[i];
    }
    printf("%s\n", s);

    return 0;
}