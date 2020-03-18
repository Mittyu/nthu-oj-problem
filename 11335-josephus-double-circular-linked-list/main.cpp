#define DEATH -1
#include<iostream>
#include<iomanip>
using namespace std;

typedef struct _node{
    int idx, next, prev;
} node;

int main(){
    // freopen("input.txt", "r", stdin);
    int n, m, i, count, dead_count;
    cin >> n >> m;
    // init node array
    node *p = new node[n];
    for(i=0; i<n; i++){
        p[i].prev = i-1;
        p[i].idx = i+1;
        p[i].next = i+1;
    }
    p[0].prev = n-1;
    p[n-1].next = 0;
    // cout << setw(4) << "prev" << setw(4) << "idx" << setw(4) << "next" << endl;
    // for(i=0; i<n; i++){
    //     cout << setw(4) << p[i].prev << setw(4) << p[i].idx << setw(4) << p[i].next << endl;
    // }
    // run josephus
    i=0, count=1, dead_count=0;
    while(dead_count<n-1){
        while(1){
            if(p[i].idx != DEATH){
                if(count%m == 0){
                    // cout << "kill:(next) " << p[i].idx << endl;
                    p[i].idx = DEATH;
                    p[p[i].prev].next = p[i].next;
                    p[p[i].next].prev = p[i].prev;
                    dead_count++;
                    count=1;
                    i=p[i].prev;
                    break;
                }
                count++;
            }
            i=p[i].next;
        }
        if(dead_count == n-1) break;
        while(1){
            if(p[i].idx != DEATH){
                if(count%m == 0){
                    // cout << "kill:(prev) " << p[i].idx << endl;
                    p[i].idx = DEATH;
                    p[p[i].prev].next = p[i].next;
                    p[p[i].next].prev = p[i].prev;                    
                    dead_count++;
                    count=1;
                    i=p[i].next;
                    break;
                }
                count++;
            }
            i=p[i].prev;
        }
    }
    while(p[i].idx == DEATH){
        i++;
        i%=n;
    }

    cout << p[i].idx << endl;


    return 0;
}