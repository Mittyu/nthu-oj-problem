#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
    unsigned freq[6], i;
    for(i=0; i<6; ++i)
    {
        freq[i]=0;
    }
    for(i=1; i<600000; ++i)
    {
        freq[rand()%6]++;
    }
    for(i=1; i<7; ++i)
    {
        cout<<"freq "<<i<<" : "<<freq[i-1]<<endl;
    }

    return 0;
}