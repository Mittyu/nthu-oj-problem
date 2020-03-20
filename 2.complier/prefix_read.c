#include<stdio.h>

int evalBoolExpression(){
    char c = getchar();
    if(c == '|' || c == '&'){
        if(c == '|'){
            return evalBoolExpression() | evalBoolExpression();
        }else{
            return evalBoolExpression() & evalBoolExpression();
        }
    }else{
        return (int)(c-'0');
    }
}

int main(){
    printf("ans: %d\n", evalBoolExpression());
    return 0;
}