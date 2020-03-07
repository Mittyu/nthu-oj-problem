#include <iostream>
#include <set>
using namespace std;
class Word {
    public:
        string s;
        int n = 0;
        char c;
        bool operator< (const Word& a) const{
            if (this->n > a.n) return false;
            else if (this->n < a.n) return true;
            else if (this->c > a.c) return false;
            else return true;
        }
};
int first, second;
void updateNums(int a, int e, int i, int o, int u){
    // first be a pair but do not need the same
    // first += (a + e + i + o + u)/2;
    // for the sake of duplicated
    first += (a%2 + e%2 + i%2 + o%2 + u%2)/2;
    // second be a pair and need the same
    second += (a/2 + e/2 + i/2 + o/2 + u/2);
}
int main(){
    set <Word> mySet;
    int n;
    cin >> n;
    while (n--) {
        Word newWord;
        cin >> newWord.s;
        for (auto i : newWord.s) {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                newWord.n++;
                newWord.c = i;
            }
        }
        mySet.insert(newWord);
    }
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    int vowelNum = 1;
    for (auto item : mySet) {
        // count a, e, i, o, u for each vowelNum.
        if (vowelNum != item.n){
            updateNums(a, e, i, o, u);
            vowelNum = item.n;
            a = e = i = o = u = 0;
        }
        // cout << "item.n: " << item.n << ", item.c: " << item.c << endl;
        if (item.c == 'a') a++;
        else if (item.c == 'e') e++;
        else if (item.c == 'i') i++;
        else if (item.c == 'o') o++;
        else if (item.c == 'u') u++;
    }
    updateNums(a, e, i, o, u);
    if (first < second)
        cout << (first + second)/2 << endl;
    else
        cout << second << endl;
    return 0;
}