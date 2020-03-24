#define MAXEXPR 256
#define NUMSYM 6
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char sym[NUMSYM] = "ABCD&|";
char expression[MAXEXPR];

typedef enum{
    ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR
}TokenSet;

typedef struct _node{
    TokenSet token;
    struct _node *prev, *next;
}node;
int pos;
node* make_node(char c);
node* expression_read();
int main(){
    node *head;
    scanf(" %s", expression);
    pos = strlen(expression)-1; // from the back of expression
    head = expression_read();

    return 0;
}

node* make_node(char c){
    node* new_node = (node*)malloc(sizeof(node));
    for(int i=0; i<NUMSYM; i++){
        if(c == sym[i]){
            new_node->token = i;
            break;
        }
    }
    new_node->prev = new_node->next = NULL;
    return new_node;
}
node* expression_read(){
    // EXPR := ID | EXPR OP ID
    char c;
    node *new_node = NULL, *right = NULL;
    if(pos>=0){
        c = expression[pos--];  // if the expr has length >= 1
        if(c>='A' && c<='D'){   // get ID
            right = make_node(c);
        }
        if(pos>0){              // 1. the EXPR OP ID case
            c = expression[pos--];
            if(c=='&' || c=='|'){
                // make OP node (as a root)
                new_node = make_node(c);   
                new_node->next = right;
                new_node->prev = expression_read();
            }else{
                // run into this should be an error (invaild syntax input)
                new_node = right;   // 2. EXPR = ID
            }
        }else{
            new_node = right;       // 2. EXPR = ID
        }
    }
    return new_node;
}