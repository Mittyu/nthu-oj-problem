#include "function.h"

#include <iomanip>
#include <cstring>
using namespace std;

BigInt::BigInt() {
  sign = false;
  for (int i = 0; i < N; i++) bigInt[i] = 0;
}

BigInt::BigInt(char *s)
{ 
  // cout << s << endl << "//" << endl;
  if (isdigit(s[0]))
    sign = 0;
  else{
    sign = 1;
    s[0] = '0';
  }
  for (int i = 0; i < N; i++) bigInt[i] = 0;
  int i = N - 1, j;
  int sLen = strlen(s);
  char ca[WIDTH];
  for (j = sLen - WIDTH; j >= 0; j -= WIDTH)
  {
    for (int k = 0; k < WIDTH; k++)
    {
      ca[k] = s[j + k];
    }
    bigInt[i--] = atoi(ca);
  }

  if (j < 0)
  {
    j += WIDTH;
    for (int k = 0; k < WIDTH; k++)
      ca[k] = 0;
    for (int k = 0; k < j; k++)
      ca[k] = s[k];
    bigInt[i] = atoi(ca);
  }
}

BigInt::BigInt(const BigInt &source)
{
  sign = source.sign;
  for (int i = 0; i < N; i++)
  {
    this->bigInt[i] = source.bigInt[i];
  }
}

// copy assignment operator
BigInt &BigInt::operator=(const BigInt &source)
{
  sign = source.sign;
  for (int i = 0; i < N; i++)
  {
    this->bigInt[i] = source.bigInt[i];
  }
  return *this;
}

bool BigInt::operator < (BigInt){ return true; }
bool BigInt::operator > (BigInt){ return true; }
bool BigInt::operator == (BigInt){return true; }
bool BigInt::operator >= (BigInt src){
  if (this->sign && !src.sign) return false;
  if (!this->sign && src.sign) return true;

  int* a = this->bigInt;
  int* b = src.bigInt;
  for (int i = 0; i < N; i++) {
    if (!this->sign) { // positive
      if (a[i] == b[i]) continue;
      else if (a[i] > b[i]) return true;
      else return false;
    } else {
      if (a[i] == b[i]) continue;
      else if (a[i] < b[i]) return true;
      else return false;
    }
  }
  return true;
}
bool BigInt::operator <= (BigInt){return true; }

BigInt BigInt::operator + (BigInt source) {
  BigInt ans;
  int* a = this->bigInt;
  int* b = source.bigInt;
  int* c = ans.bigInt;
  
  for (int i = N - 1; i >= 0; i--) c[i] = 0;
  
  if (this->sign == source.sign) {
    // (-) + (-) or (+) + (+)
    for (int i = N - 1; i >= 0; i--) {
      c[i] += (a[i] + b[i]);
      if (c[i] >= BASE) {
        c[i] -= BASE;
        c[i-1] = 1;
      }
    }
    ans.sign = this->sign;

  } else {
    // (-) + (+) or (+) + (-)
    ans.sign = this->sign;
    for (int i = N - 1; i >= 0; i--) {
      c[i] += (a[i] - b[i]);
      if (c[i] < 0) {
        c[i] += BASE;
        c[i-1] = -1;
      }
    }

    if (c[0] == BASE - 1) {
      for (int i = 0; i < N; i++) {
        c[i] += 1 - BASE;
        if (c[i] < 0)
          c[i] = -c[i];
      }
      ans.sign = !this->sign;
    }
  }

  return ans;
}

BigInt BigInt::operator - (BigInt source) {
  BigInt ans;
  int* a = this->bigInt;
  int* b = source.bigInt;
  int* c = ans.bigInt;
  
  for (int i = N - 1; i >= 0; i--) c[i] = 0;
  
  if (this->sign != source.sign) {
    // (-) - (+) or (+) - (-)
    for (int i = N - 1; i >= 0; i--) {
      c[i] += (a[i] + b[i]);
      if (c[i] >= BASE) {
        c[i] -= BASE;
        c[i-1] = 1;
      }
    }
    ans.sign = this->sign;

  } else {
    // (-) - (-) or (+) - (+)
    ans.sign = this->sign;
    for (int i = N - 1; i >= 0; i--) {
      c[i] += (a[i] - b[i]);
      if (c[i] < 0) {
        c[i] += BASE;
        c[i-1] = -1;
      }
    }


    if (c[0] == BASE - 1) {
      for (int i = 0; i < N; i++) {
        c[i] += 1 - BASE;
        if (c[i] < 0)
          c[i] = -c[i];
      }
      ans.sign = !this->sign;
    }

  }

  return ans;

}

istream& operator >> (istream& in, BigInt& n) {
  char s[n.N]; in >> s;
  n = BigInt(s);

  return in;
}

ostream& operator << (ostream& out, BigInt& n) {
  int i;
  for (i = 0; i < n.N; i++) {
    if (n.bigInt[i] != 0)
      break;
  }
  if (i == n.N) {
    out << '0';
    return out;
  }
  if (n.sign)
    out << '-';
  out << n.bigInt[i++];

  for (  ; i < n.N; i++) {
    out << setw(8) << setfill('0') << n.bigInt[i];
  }

  return out;
}

void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n) {
  for (int i = 0; i < n; i++) {
		BigInt mission;
		cin >> mission;
		if (inosuke >= tanjiro && inosuke >= zenitsu)
			inosuke = inosuke - mission;
		else if (tanjiro >= inosuke && tanjiro >= zenitsu)
			tanjiro = tanjiro - mission;
		else if (zenitsu >= inosuke && zenitsu >= tanjiro)
			zenitsu = zenitsu - mission;
    else
     cout << "ERROR" << endl;
	}
}