#include <iostream>

using namespace std;

int gcd (int s, int t){
    if (t == 0) return s;
    else return gcd(t, s%t);
}


int main(){
    int s, t;
    cin >> s >> t;
    if (s > t)
        cout << gcd(s, t);
    else 
        cout << gcd(t, s);

    return 0;
}