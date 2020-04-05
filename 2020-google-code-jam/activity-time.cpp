#include<bits/stdc++.h>

using namespace std;
bool m[2][1441];
int f(int s,int e){
    bool m0=true;
    //m=0;
    for(int i=s;i<e;++i){
        if(m[0][i]==1){
            m0=false;
            break;
        }
    }
    //m=1
    bool m1=true;
    for(int i=s;i<e;++i){
        if(m[1][i]==1){
            m1=false;
            break;
        }
    }
    if(m0&&m1){
        for(int i=s;i<e;++i){
            m[0][i]=1;
        }
        return 0;
    }else if(!m0&&m1){
        for(int i=s;i<e;++i){
            m[1][i]=1;
        }
        return 1;
    }else if(m0&&!m1){
        for(int i=s;i<e;++i){
            m[0][i]=1;
        }
        return 0;
    }else{
        return -1;
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        memset(m,0,sizeof(m));
        int k;
        cin>>k;
        bool possible=true;
        vector<pair<int,int>> vec;
        for(int i=0;i<k;++i){
            int s,e;
            cin>>s>>e;
            pair<int,int> p(s,e);
            vec.push_back(p);
        }
        string ans="";
        for(unsigned int i=0;i<vec.size();++i){
            int t=f(vec[i].first,vec[i].second);
            if(t==-1){
                possible=false;
                break;
            }
            if(t==0){
                ans+='C';
            }else{
                ans+='J';
            }
        }
        if(!possible){
            cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<"Case #"<<i<<": "<<ans<<endl;
        }


    }





return 0;
}

/*
6
6
0 720
360 480
480 960
720 900
900 1000
0 400
*/
