#define MAX 200000
#include<stdio.h>
#include<stdlib.h>
char mark[26];
void init(){
    for (int i=0; i<26; i++)
        mark[i] = i+'a';
}
int main(){
    int i, j, n, m;
    char* letters = (char*) malloc (sizeof(char) * MAX);
    scanf("%d %d %s", &n, &m, letters);
    char first, second;
    init();
    for (i=0; i<m; i++){
        scanf(" %c %c", &first, &second);
        if (first == second) continue;
        for (j=0; j<26; j++){
            if (mark[j] == first) {
                mark[j] = second;
            } else if (mark[j] == second) {
                mark[j] = first;
            }
        }
    }
    for (i=0; i<n; i++) letters[i] = mark[letters[i]-'a'];
    printf("%s\n", letters);
    return 0;
}