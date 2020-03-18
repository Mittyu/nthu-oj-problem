#define base_lenth 189
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int k, l, r, times, i;
    long long size, down, up, middle, prev_down, prev_up, next_down, next_up;
    string t, base = "OuQ";
    for(i=1; i<6; i++){
        base = "O"+base+"u"+base+"Q";
    }
    while(cin >> k >> l >> r){
        if(k<6){
            for(i=l+(6-k); i<=r+(6-k); i++){
                cout << base[i];
            }
            cout << endl;
            continue;
        }
        t = base;
        times = k;
        size = 3*(pow(2, k)-1);
        up = size-1; down = 0, middle = (up+down)/2;
        while(times-- != 6){
            // cout << setw(6) << down << setw(6) << middle << setw(6) << up << endl;
            if(middle<=l){
                down = middle+1;
                up -= 1;
            }else if(r<=middle){
                up = middle-1;
                down += 1;
            }
            middle = (up+down)/2;
        }
        // cout << up-down << endl;
        prev_up = down-1-(k-6)-1-(k-6);
        prev_down = prev_up-base_lenth+1;
        next_down = up+1+(k-6)+1+(k-6);
        next_up = next_down+base_lenth-1;

        prev_up -= prev_down;
        down -= prev_down;
        up -= prev_down;
        next_down -= prev_down;
        next_up -= prev_down;
        l -= prev_down;
        r -= prev_down;
        prev_down = 0;
        // cout << setw(4) << prev_down << setw(4) << prev_up << setw(4) << down << setw(4) << up << setw(4) << next_down << setw(4) << next_up;

        for(i=0; i<k-6; i++){
            t += "Q";
        }
        t += "u";
        for(i=0; i<k-6; i++){
            t+= "O";
        }
        t += base;
        for(i=0; i<k-6; i++){
            t += "Q";
        }
        t += "u";
        for(i=0; i<k-6; i++){
            t += "O";
        }
        t += base;
        // cout << setw(4) << l << setw(4) << r << endl;
        for(i=l; i<=r; i++){
            cout << t[i];
        }
        cout << endl;
    }
    return 0;
}

/*
[base]qqq..qquooo..oo[base]qqq..qquooo..oo[base]
  189+ (k-6)+1+(k-6)+ 189 +(k-6) +1+(k-6) +189 = 189*3+2+4k-24 = 573 (k=7)
1. find [x] u [x], where is l and r.
2. classify is front of x or back of x, and at begin or the end.
3. using the upper method to figure out s[l:r+1]
*/