#define start 1
#define MAX 3000000
#include<stdio.h>

int binarySearch(int x, int* arr);

int main(){
    int n, q;
    int askNum, index;
    int numArray[MAX];

    while (scanf("%d%d", &n, &q)!=EOF){
        numArray[0] = n;    // bring the size of the sequence
        for (int i = start; i <= n; ++i)
            scanf("%d", &numArray[i]);
        
        askNum = 0;
        for (int i = 0; i < q; ++i){
            scanf("%d", &askNum);

            index = binarySearch(askNum, numArray);
            if (index == -1)
                printf("Break your bridge!\n");
            else
                printf("%d\n", index);
        }
    }

    return 0;
}

int binarySearch(int x, int* arr)
{   
    int l = 1;
    int r = arr[0];
    int m = 0;
    while (l <= r){
        m = (l + r) / 2;

        if (arr[m] == x)
            return m;
        else if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}