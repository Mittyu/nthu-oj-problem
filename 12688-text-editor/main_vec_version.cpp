#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int t, n, i, cur;
    string text;
    vector<char> vec;
    cin >> t;
    while(t--){
        cur = 0;
        cin >> n >> text;
        for(i=0; i<n; i++){
            if(text[i] == 'L'){
                cur--;
            }else if(text[i] == 'R'){
                cur++;
            }else if(text[i] == 'B'){
                cur--;
                vec.erase(vec.begin()+cur);
            }else{
                vec.insert(vec.begin()+cur, text[i]);
                cur++;
            }
        }
        for(auto &iter:vec){
            cout << iter;
        }
        cout << endl;
        vec.clear();
    }

    return 0;
}