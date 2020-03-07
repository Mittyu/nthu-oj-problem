#define END 10
#define MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n;
char *word, *chessland;
bool search(int i, int state);
int main(){
    word = (char*) malloc (sizeof(char) * MAX);
    chessland = (char*) malloc (sizeof(char) * MAX * MAX);
    word = "ICPCASIASG";
    scanf("%d %s", &n, chessland);
    if(search(0, 0))
        printf("YES\n");
    else
        printf("NO\n");
}

bool search(int i, int state){
    // ICPCASIASG
    // 0123456789
    // printf("# %3d %3d %3c\n", i, state,word[state]);
    if (state == END) return true;
    if (i<0 || i>n*n) return false;
    if (state == 0) {
        for (int j=0; j<n*n; j++)
            if (chessland[j] == word[state]){
                if (j%n != 0) {
                    if (search(j-2*n-1, state+1)||
                        search(j+2*n-1, state+1)) return true;
                }
                if (j%n != n-1) {
                    if (search(j-2*n+1, state+1)||
                        search(j+2*n+1, state+1)) return true;
                }
                if (j%n > 1) {
                    if (search(j-n-2, state+1)||
                        search(j+n-2, state+1)) return true;
                }
                if (j%n < n-1) {
                    if (search(j-n+2, state+1)||
                        search(j+n+2, state+1)) return true;
                }
            }
    } else if (chessland[i] == word[state]) {
        if (i%n != 0) {
            if (search(i-2*n-1, state+1)||
                search(i+2*n-1, state+1)) return true;
        }
        if (i%n != n-1) {
            if (search(i-2*n+1, state+1)||
                search(i+2*n+1, state+1)) return true;
        }
        if (i%n > 1) {
            if (search(i-n-2, state+1)||
                search(i+n-2, state+1)) return true;
        }
        if (i%n < n-1) {
            if (search(i-n+2, state+1)||
                search(i+n+2, state+1)) return true;
        }        
    }
    return false;
}