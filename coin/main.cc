#define MAX 1010
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minCoin(vector<int>& money, int cur, int level, int count);
int main(){
    int cases, n, m, input;
    vector<int> v;
    cin>>cases;
    while(cases--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            scanf(" %d", &input);
            v.push_back(input);
        }
        sort(v.begin(), v.end());
        cout<<minCoin(v, m, n-1, 0)<<endl;
        v.clear();
    }
    return 0;
}

int minCoin(vector<int>& money, int cur, int level, int count){
    if(cur==0) return count;
    if(level<0 || cur<0) return MAX;
    return min(minCoin(money, cur-money[level], level, count+1), minCoin(money, cur, level-1, count));
}