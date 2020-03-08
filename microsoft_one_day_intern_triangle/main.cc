#include<iostream>
#include<cmath>

using namespace std;

class point{
    public:
        long long int x, y;
};
long long int square_sum(long long int x, long long int y){
    return x * x + y * y;
}
int main(){
    point p[3];
    
    for(int i=0; i<3; i++){
        cin >> p[i].x >> p[i].y;
    }
    long long int a, b, c;
    a = abs(square_sum(p[0].x - p[1].x, p[0].y - p[1].y));
    b = abs(square_sum(p[1].x - p[2].x, p[1].y - p[2].y));
    c = abs(square_sum(p[2].x - p[0].x, p[2].y - p[0].y));
    if(a > c) swap(a, b);
    if(b > c) swap(b, c);
    if(a == 0 || b == 0 || c == 0) cout << "Not triangle";
    else if(p[0].x == p[1].x && p[1].x == p[2].x) cout << "Not triangle";
    else if((p[0].y - p[1].y)/(p[0].x - p[1].x) == (p[1].y - p[2].y)/(p[1].x - p[2].x)) cout << "Not triangle";
    else if(a + b == c) cout << "Right triangle";
    else if(a + b > c)  cout << "Acute triangle";
    else if(a + b < c)  cout << "Obtuse triangle";
    
    return 0;
}