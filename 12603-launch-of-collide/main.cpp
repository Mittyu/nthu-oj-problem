#include<iostream>
#define MAX 1000
using namespace std;


int main(){
    string dir;
    int* dst = new int[MAX];
    char* s = new char[MAX];

    int n, newMin, min;
    while(cin.getline(s, MAX)) {
        if (cin.eof())
            break;
            
        min = -1;
        cin >> n >> dir;
        for (int i = 0; i < n; i++)
            cin >> dst[i];
        for (int i = 0; i < n - 1; i++){
            if (dir[i] == 'R' && dir[i+1] == 'L'){
                if (min == -1) {
                    min = (dst[i+1] - dst[i]) / 2;
                } else {
                    newMin = (dst[i+1] - dst[i]) / 2;
                    if (newMin < min) min = newMin;
                }
            }
        }

        cout << s << endl;
        cout << min;
    }
    return 0;
}
/*
# Sample Input 1
# Sample Input 2
# Sample Input 3
# Sample Input 4

*/