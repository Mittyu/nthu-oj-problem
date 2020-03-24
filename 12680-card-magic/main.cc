#include<bits/stdc++.h>

using namespace std;

class node{
public:
    int num;
    node* next;
    node(){
        this->num = -1;
        this->next = NULL;
    }
};
class stacks{
public:
    node* head;
    stacks* next;
    stacks(){
        this->head = NULL;
        this->next = NULL;
    }
};
stacks head_stack;
int main(){
    int n, m;
    cin >> n >> m;



    return 0;
}