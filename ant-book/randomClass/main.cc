#include<iostream>
#include<iomanip>
#include<random>
#include<ctime>
using namespace std;

int main(){

    // use the default random engine to produce uniformly 
    // distributed pseudoransom int values from 1 to 6
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomInt(1, 6);

    for(unsigned i=1; i<11; ++i){
        cout<<setw(10)<<randomInt(engine);
        if(i%5==0) cout<<"\n";
    }

    return 0;
}