#include <iostream>
#include <string>
#include<vector>
#include<set>
using namespace std;
struct Word{
    string s;
    int time;
    int c;

    bool operator<(const Word& a)const{
        if (this->time>a.time) return false;
        else if (this->time<a.time) return true;
        else if (this->c >a.c) return false;
        else return true;
    }
};
set <Word> myset;
set <Word>::iterator it=myset.begin();
int head=0,tail=0;
void count_ans(int a,int e,int i,int o,int u){
    head+=(a%2+e%2+i%2+o%2+u%2)/2;
    tail+=a/2+e/2+i/2+o/2+u/2;
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        Word w;

        cin>>w.s;
        w.time=0;
        for (auto j:w.s){
            if (j=='a' ||j=='e' ||j=='i' ||j=='o' ||j=='u'){
                w.c=j;
                w.time++;
            }
        }

        myset.insert(w);
    }


    int time=1;

    int ans=0,a=0,e=0,i=0,o=0,u=0;
    //for (it=myset.begin();it!=myset.end();it++) cout<<(*it).s<<"  ";
    //cout<<endl;
    for (it=myset.begin();it!=myset.end();it++){
        if (time!=(*it).time){
            time=(*it).time;
            //cout<<"a:"<<a<<" e:"<<e<<" i:"<<i<<" o:"<<o<<" u:"<<u<<endl;
            count_ans(a,e,i,o,u);
            //cout<<ans<<endl;
            a=e=i=o=u=0;
        }

        if ((*it).c=='a'){
            a++;
        }
        else if ((*it).c=='e'){
            e++;
        }
        else if ((*it).c=='i'){
            i++;
        }
        else if ((*it).c=='o'){
            o++;
        }
        else if ((*it).c=='u'){
            u++;
        }
    }
    //cout<<"a:"<<a<<" e:"<<e<<" i:"<<i<<" o:"<<o<<" u:"<<u<<endl;
    count_ans(a,e,i,o,u);

    if (tail<head) ans=tail;
    else if (head<tail){
        ans=head+(tail-head)/2;
    }
    else {
        ans=tail;
    }
    cout<<ans<<endl;

    return 0;
}
