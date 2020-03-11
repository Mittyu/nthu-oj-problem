#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class diamand{
    public:
        int vol;
        int cost;
};
bool cmp(diamand d1, diamand d2){
    return d2.cost - d1.cost;
}
int main(){
    int N, C, K;
    diamand input;
    vector<diamand> vec;
    cin >> N >> C >> K;
    for(int i=0; i<N; i++){
        cin >> input.vol;
        vec.push_back(input);
    }
    for(int i=0; i<N; i++){
        cin >> input.cost;
        vec[i].cost = input.cost;
    }
    sort(vec.begin(), vec.end(), cmp);
    for(auto iter = vec.begin(); iter < vec.end(); iter++){
        cout << iter->cost << endl;
    }
    return 0;
}
/*
3 10 0
10 4 6
5 1 6

*/