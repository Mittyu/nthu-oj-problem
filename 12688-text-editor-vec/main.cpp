#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int s;
        cin>>s;
        string str;
        cin>>str;
        vector<char> vec;
        int cur = 0;
        for(int i=0;i<s;++i){
            if(str[i]=='B'){
                cur--;
                vec.erase(vec.begin() + cur);
            }else if(str[i]=='L'){
                cur--;
            }else if(str[i]=='R'){
                cur++;
            }else{
                vec.insert(vec.begin() + cur, str[i]);
                cur++;
            }
        }
        for(auto iter = vec.begin(); iter < vec.end(); iter++){
            cout << *iter;
        }
        cout << endl;

    }






return 0; 
}