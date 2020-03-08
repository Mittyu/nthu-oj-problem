#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

class point{
public:
    int x,y;
    point(int a,int b){
        x=a;
        y=b;
    }

};


int main(){
    int n;
    cin>>n;
    for(int m=1;m<=n;++m){
        int a,b;
        cin>>a>>b;
        cout<<"Case #"<<m<<": ";
        bool used[a][b];
        memset(used,false,sizeof(used));
        vector<point> vec;
        bool impossible=false;
        int x=0,y=0;
        for(int k=0;k<a*b;++k){
            used[x][y]=true;
            point p(x+1,y+1);
            vec.push_back(p);

            int Max=0,max_x=0,max_y=0;
            for(int i=0;i<a;++i){
                for(int j=0;j<b;++j){
                    if(x!=i&&y!=j&&x+y!=i+j&&x-y!=i-j&&!used[i][j]){
                        int c=0;
                        for(int r=0;r<a;++r){
                            for(int s=0;s<b;++s){
                                if((r==i||s==j||r+s==i+j||r-s==i-j)&&!used[r][s]){
                                    c++;
                                }
                            }
                        }

                        if(c>Max){
                            Max=c;
                            max_x=i;
                            max_y=j;
                        }

                    }
                }
            }
            if(k!=a*b-1&&Max==0){
                impossible=true;
            }
            x=max_x;
            y=max_y;

        }
        if(impossible){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<"POSSIBLE"<<endl;
            for(int i=0;i<a*b;++i){
                cout<<vec[i].x<<" "<<vec[i].y<<endl;
            }
        }


    }


return 0;
}



