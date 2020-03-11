#include<iostream>
#include<string>
using namespace std;

class editor{
public:
    char x;
    editor *next, *prev;
    editor(char a){
        x=a;
        next=NULL;
        prev=NULL;
    }
};

int main(){
    int n;
    cin>>n;
    while(n--){
        int s;
        cin>>s;
        string tmp;
        cin>>tmp;
        editor *head=new editor('#');
        editor *tail=new editor('#');
        head->next=tail;
        tail->prev=head;
        editor *temp=head->next;
        for(int i=0;i<s;++i){
            if(tmp[i]=='B'){
                editor *del=temp->prev;
                temp->prev->prev->next=temp;
                temp->prev=temp->prev->prev;
                delete del;
            }else if(tmp[i]=='L'){
                temp=temp->prev;
            }else if(tmp[i]=='R'){
                temp=temp->next;
            }else{
                editor *new_node=new editor(tmp[i]);
                new_node->next=temp;
                temp->prev->next=new_node;
                new_node->prev=temp->prev;
                temp->prev=new_node;
            }
        }

        editor *t=head;
        t=t->next;
        while(t->next!=NULL){
            cout<<t->x;
            t=t->next;
        }
        cout<<endl;
    }
   return 0; 
}