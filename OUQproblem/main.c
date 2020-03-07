#define MAX 1000
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char* ouq(int times){
    char* r;
    char* o = "O", *u = "U", *q = "Q";
    char* s = (char*)malloc(sizeof(char)*MAX);
    if(times==1){
        strcpy(s, o);
        strcat(s, u);
        strcat(s, q);
    }else{
        r = ouq(times-1);
        strcpy(s, o);
        strcat(s, r);
        strcat(s, u);
        strcat(s, r);
        strcat(s, q);
    }
    return s;
}

int main(){
    char* string;
    int n, times, l, r;
    scanf(" %d", &n);
    while(n--){
        scanf(" %d %d %d", &times, &l, &r);
        string = ouq(times);
        printf("%s", string);
    }

    return 0;
}
