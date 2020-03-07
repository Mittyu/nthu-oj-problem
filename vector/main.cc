#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    std::vector<int> myvector;
    for(int i=0; i<100; i++)
        myvector.push_back(-i);
    
    for(auto i=myvector.begin(); i<myvector.end(); i++)
        std::cout<<*i<<" ";
    std::cout<<std::endl;

    // [] and .at do the same thing, except that .at has out of range checking.
    std::cout<<myvector[1]<<std::endl;
    std::cout<<myvector.at(1)<<std::endl;
    //i.e .at would report error but [] would not
    // std::cout<<myvector[1000]<<std::endl;
    // std::cout<<myvector.at(1000)<<std::endl;
    
    sort(myvector.begin(), myvector.end());
    for(auto i=myvector.begin(); i<myvector.end(); i++)
        std::cout<<*i<<" ";


    return 0;
}