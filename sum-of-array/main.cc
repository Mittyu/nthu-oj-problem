#include<iostream>
#include<vector>
int main(){
    int n, input;
    std::vector<int> v;
    std::cin>>n;
    while(n--){
        std::cin>>input;
        v.push_back(input);
    }
    int sum=0;
    for(auto iter=v.begin(); iter<v.end(); iter++)
        sum+=*iter;
    std::cout<<sum;
    return 0;
}