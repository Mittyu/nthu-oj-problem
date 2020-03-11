#define MAX 9
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct _chess{
    int col;
    char prop;
} chess;

int q, r, count;
chess board[MAX];
void solution(int, int, int);
int main(){
    int n, m;   // n for queen, m for rook.
    while(~scanf("%d %d", &n, &m)){
        // initialize
        q = r = count = 0;
        for(int i=0; i<MAX; i++){
            board[i].col = 0;
            board[i].prop = 'n';
        }
        // compute
        solution(n, m, 0);

        printf("%d\n", count);
    }
    return 0;
}
int attackR(int i, int row){
    for (int j=0; j<row; j++){
        if (board[j].col == i ||
            board[j].prop == 'q' && 
            row-j == abs(board[j].col-i)) 
            return 1;
    }
    return 0;
}
int attackQ(int i, int row){
    for (int j=0; j<row; j++){
        if (row-j == abs(board[j].col-i) || 
            board[j].col == i) 
            return 1;
    }
    return 0;
}
void solution(int n, int m, int row){
    // only for n, i.e for queen.
    if (r>m || q>n) return;
    if (r==m && q==n){
        count++;
        return;
    }
    for(int i=0; i<n+m; i++){
        if (!attackR(i, row)){
            board[row].col = i;
            board[row].prop = 'r';
            r++;
            solution(n, m, row+1);
            board[row].col = 0;
            board[row].prop = 'n';
            r--;
        }
        if (!attackQ(i, row)){
            board[row].col = i;
            board[row].prop = 'q';
            q++;
            solution(n, m, row+1);
            board[row].col = 0;
            board[row].prop = 'n';
            q--;
        }
    }
}
