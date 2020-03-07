#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string> 
using namespace std; 
#define MAX_N 1000
#define MAX_Bit 5
#define MAX 100000
class BigInt{
	public:
		int sign; // 正負號
		long long m[MAX_N];
		int l; //長度
		long long operator [](int i) const { return m[i]; }
		long long &operator [](int i) { return m[i]; }
		BigInt(){ l=1, m[0]=0; sign=1; }
		BigInt(int x){ (*this)=x; }
		BigInt(const char *s){ (*this)=s; }
        friend istream& operator>>(istream&, BigInt&);   
        friend ostream& operator<<(ostream&, BigInt);   
        BigInt operator +( const BigInt &y );  
        BigInt operator -( const BigInt &y );      
};
BigInt BigInt::operator+ (const BigInt &y){
	BigInt &x = *this, ans;
	memset(ans.m, 0, sizeof(int) * MAX_N);
	int i;
	if (x.sign == y.sign){
		ans.sign = x.sign;
		for (i = 0; i < x.l || i < y.l; i++) {
			ans.m[i] += (x.m[i] + y.m[i]) % MAX;
			ans.m[i + 1] += (x.m[i] + y.m[i]) / MAX;
		}
	} else {
		if ( x.sign == -1) {
			// x is neg, y is pos.
			for (i = 0; i < x.l || i < y.l; i++) {
				ans.m[i] += y.m[i] - x.m[i];
				if (ans.m[i] < 0){
					ans.m[i] += MAX;
					ans.m[i + 1] -= 1;
				}
			}
		} else {
			// x is pos, y is neg.
			for (i = 0; i < x.l || i < y.l; i++) {
				ans.m[i] += x.m[i] - y.m[i];
				if (ans.m[i] < 0) {
					ans.m[i] += MAX;
					ans.m[i + 1] -= 1;
				}
			}
		}
		if (ans.m[i] == -1)
			ans.sign = -1;
		else
			ans.sign = 1;
	}
	for (int j = i; j >=0; j--) {
		if (ans.m[j] == 0)
			i--;
		else 
			break;
	}
	ans.l = i;
	return ans;
}
BigInt BigInt::operator- (const BigInt &y) {
	BigInt &x = *this, ans;
	memset(ans.m, 0, sizeof(int) * MAX_N);
	int i;
	if (x.sign != y.sign) {
		ans.sign = x.sign;
		for (i = 0; i < x.l || i < y.l; i++){
			ans.m[i] += (x.m[i] + y.m[i]) % MAX;
			ans.m[i + 1] += (x.m[i] + y.m[i]) / MAX;
		}
	} else {
		// with 'minus'.
		if (x.sign == -1) {
			// x is neg, y is pos.
			for (i = 0; i < x.l || i < y.l; i++){
				ans.m[i] += y.m[i] - x.m[i];
				if (ans.m[i] < 0){
					ans.m[i] += MAX;
					ans.m[i + 1] += -1;
				}
			}
		} else {
			// x is pos, y is neg.
			for (i = 0; i < x.l || i < y.l; i++){
				ans.m[i] += x.m[i] - y.m[i];
				if (ans.m[i] < 0) {
					ans.m[i] += MAX;
					ans.m[i + 1] += -1;
				}
			}
		}
		for (int j = i; j >=0; j--) {
			if (ans.m[j] == 0)
				i--;
			else 
				break;
		}
		ans.l = i;
		if (ans.m[i] == -1)
			ans.sign = -1;
		else 
			ans.sign = 1;
	}
	return ans;
}
istream& operator>>(istream& in, BigInt& x){
	string s;
	in >> s;
	x.l = s.length();
	memset(x.m, 0, sizeof(int) * MAX_N);

	int bigIntIdx, stringIdx, tmpNum, i;
	bigIntIdx = 0;
	stringIdx = x.l - 1;
	if (s[0] == '-') {
		x.sign = -1;
		while (stringIdx > 0) { 							// s[0] is the sign
			tmpNum = 0;
			for (i = stringIdx - MAX_Bit + 1; i < stringIdx; i++) {		// eat MAX_Bit for the num.
				tmpNum *= 10;
				tmpNum += (int) s[i] - 48;
			}
			x.m[bigIntIdx] = tmpNum;
			bigIntIdx++;
			stringIdx -= MAX_Bit;
		}
	} else {
		x.sign = 1;
		while (stringIdx >= 0) {
			tmpNum = 0;
			for (i = stringIdx - MAX_Bit; i < stringIdx && i > 0; i++) {
				tmpNum *= 10;
				tmpNum += (int) s[i] - 48;
				cout << "x.m[" << bigIntIdx << "]: " << tmpNum << "\n"; 
			}
			x.m[bigIntIdx] = tmpNum;
			bigIntIdx++;
			stringIdx -= MAX_Bit;
		}
		for ( i = bigIntIdx -1; i >= 0; i--)
			cout << x.m[i];
		cout << '\n';
	}
	x.l = bigIntIdx;
	return in;
}
ostream& operator<< (ostream& out, BigInt x) {
	if (x.sign == -1)
		out << '-';
	
	if (x.l == 1 && x.m[0] == 0) {
		out << 0;
		return out;
	} else {
		out << x.m[x.l - 1];
		for (int i = x.l - 1 - 1; i >= 0; i--) {
			if (x.m[i] == 0) out << "00000";
			else if (x.m[i] < 10) out << "0000" << x.m[i];
			else if (x.m[i] < 100) out << "000" << x.m[i];
			else if (x.m[i] < 1000) out << "00" << x.m[i];
			else if (x.m[i] < 10000) out << "0" << x.m[i];
			else out << x.m[i];
		}
	}
	return out;
}


