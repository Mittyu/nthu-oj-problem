#include<bits/stdc++.h>

using namespace std;

map<pair<int,int>,bool> m;
int p,w;
void fall(int i,int h){
    vector<pair<int,int>> v;
    for(int j=i+1;j<h;++j){
        for(int k=0;k<w;++k){
            if(m[{k,j}]!=0){
                v.push_back({k,j});
                m[{k,j}]=0;
            }
        }
    }
    for(int r=0;r<v.size();++r){
        v[r].second--;
        m[v[r]]=1;
    }
}

int main(){
    cin>>p>>w;
    for(int i=0;i<w;++i){
        for(int j=0;j<4*p;++j){
            m[{i,j}]=0;
        }
    }
    pair<int,int> pa;
    vector<pair<int,int>> vec;
    int height=0;
    for(int i=1;i<=p;++i){
        vec.clear();
        char c;
        cin>>c;
        string s;
        cin>>s;
        if(c=='L'){
            pa=make_pair(0,0);
            vec.push_back(pa);
            pa=make_pair(1,0);
            vec.push_back(pa);
            pa=make_pair(1,1);
            vec.push_back(pa);
            pa=make_pair(1,2);
            vec.push_back(pa);
        }else if(c=='J'){
            pa=make_pair(0,0);
            vec.push_back(pa);
            pa=make_pair(0,1);
            vec.push_back(pa);
            pa=make_pair(0,2);
            vec.push_back(pa);
            pa=make_pair(1,0);
            vec.push_back(pa);
        }else if(c=='O'){
            pa=make_pair(0,0);
            vec.push_back(pa);
            pa=make_pair(0,1);
            vec.push_back(pa);
            pa=make_pair(1,1);
            vec.push_back(pa);
            pa=make_pair(1,0);
            vec.push_back(pa);
        }else if(c=='I'){
            pa=make_pair(0,0);
            vec.push_back(pa);
            pa=make_pair(0,1);
            vec.push_back(pa);
            pa=make_pair(0,2);
            vec.push_back(pa);
            pa=make_pair(0,3);
            vec.push_back(pa);
        }else if(c=='Z'){
            pa=make_pair(0,0);
            vec.push_back(pa);
            pa=make_pair(1,0);
            vec.push_back(pa);
            pa=make_pair(1,1);
            vec.push_back(pa);
            pa=make_pair(2,1);
            vec.push_back(pa);
        }else if(c=='S'){
            pa=make_pair(0,1);
            vec.push_back(pa);
            pa=make_pair(1,1);
            vec.push_back(pa);
            pa=make_pair(1,0);
            vec.push_back(pa);
            pa=make_pair(2,0);
            vec.push_back(pa);
        }else if(c=='T'){
            pa=make_pair(0,1);
            vec.push_back(pa);
            pa=make_pair(1,1);
            vec.push_back(pa);
            pa=make_pair(1,0);
            vec.push_back(pa);
            pa=make_pair(2,1);
            vec.push_back(pa);
        }
        for(int j=0;j<s.size();++j){
            if(s[j]=='<'){
                if(vec[3].first+1==w){
                    continue;
                }
                for(int k=0;k<4;++k){
                    vec[k].first++;
                }
            }else{
                if(vec[0].first-1<0){
                    continue;
                }
                for(int k=0;k<4;++k){
                    vec[k].first--;
                }
            }
        }

        for(int j=0;j<4;++j){
            vec[j].second+=height;
        }

        while(1){
            if(vec[0].second==0||vec[1].second==0||vec[2].second==0||vec[3].second==0){
                break;
            }
            if(m[vec[0]]!=0||m[vec[1]]!=0||m[vec[2]]!=0||m[vec[3]]!=0){
                vec[0].second++;
                vec[1].second++;
                vec[2].second++;
                vec[3].second++;
                break;
            }else{
                vec[0].second--;
                vec[1].second--;
                vec[2].second--;
                vec[3].second--;
            }
        }
        m[vec[0]]=1;m[vec[1]]=1;m[vec[2]]=1;m[vec[3]]=1;
        height=0;
        while(1){
            bool con=false;
            for(int z=0;z<w;++z){
                if(m[{z,height}]!=0){
                    height++;
                    con=true;
                }
            }
            if(!con){
                break;
            }
        }
        for(int i1=0;i1<height;++i1){
            bool b=false;
            for(int j=0;j<w;++j){
                if(m[{j,i1}]==0){
                    b=true;
                    break;
                }
            }
            if(!b){
               for(int j=0;j<w;++j){
                    m[{j,i1}]=0;
                }
                fall(i1,height);
                height--;
                i1=-1;
            }
        }
    }



    /*for(map<pair<int,int>,int>::iterator iter=m.begin();iter!=m.end();++iter){
        if((*iter).second!=0){
            cout<<((*iter).first).first<<" "<<((*iter).first).second<<" "<<(*iter).second<<endl;
        }
    }*/


    int h=-1;
    int h_max=-1;
    for(int i=0;i<w;++i){
        for(int j=0;j<height;++j){
            if(m[{i,j}]!=0){
                h=j;
            }
        }
        if(h>h_max){
            h_max=h;
        }
    }
    cout<<h_max+1;





return 0;
}