#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAX_N 1000
#define MAX_Bit 5
#define MAX 100000
class BigInt{
	public:
		int sign;
		long long m[MAX_N];
		int l;
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


BigInt BigInt:: operator +( const BigInt &y ){
	int i,pos=0;
	long long h=0,tmp=0;
	BigInt a=(*this),b=y,ans;

	for (i=0;i<a.l||i<b.l;i++){
		h+=(a.sign*a.m[i])+(b.sign*b.m[i]);
		ans.m[i]=h%MAX;
		h/=MAX;
	}
	ans.l=i;

	for (i=ans.l-1;i>=0;i--){
		if (ans.m[i]>0){
			pos=1;
			break;
		}
		else if (ans.m[i]<0){
			pos=-1;
			break;
		}
	}

	if (pos==0){
		ans.sign=1;
	}
	else if (pos==1){
		ans.sign=1;

		for (i=0;i<ans.l;i++){
			ans.m[i]+=tmp;
			if (ans.m[i]<0){
				ans.m[i]+=MAX;
				tmp=-1;
			}
			else tmp=0;
		}
	}
	else if (pos==-1){
		ans.sign=-1;
		for (i=0;i<ans.l;i++){
			ans.m[i]+=tmp;
			if (ans.m[i]>0){
				ans.m[i]-=MAX;
				tmp=1;
			}
			else tmp=0;
		}


		for (i=0;i<ans.l;i++){
			ans.m[i]*=-1;
		}
	}

	return ans;

}
BigInt BigInt:: operator -( const BigInt &y ){
	int i,pos=0;
	long long h=0,tmp=0;
	BigInt a=(*this),b=y,ans;

	for (i=0;i<a.l||i<b.l;i++){
		h+=(a.sign*a.m[i])-(b.sign*b.m[i]);
		ans.m[i]=h%MAX;
		h/=MAX;
	}
	ans.l=i;

	for (i=ans.l-1;i>=0;i--){
		if (ans.m[i]>0){
			pos=1;
			break;
		}
		else if (ans.m[i]<0){
			pos=-1;
			break;
		}
	}

	if (pos==0){
		ans.sign=1;
	}
	else if (pos==1){
		ans.sign=1;

		for (i=0;i<ans.l;i++){
			ans.m[i]+=tmp;
			if (ans.m[i]<0){
				ans.m[i]+=MAX;
				tmp=-1;
			}
			else tmp=0;
		}
	}
	else if (pos==-1){
		ans.sign=-1;
		for (i=0;i<ans.l;i++){
			ans.m[i]+=tmp;
			if (ans.m[i]>0){
				ans.m[i]-=MAX;
				tmp=1;
			}
			else tmp=0;
		}


		for (i=0;i<ans.l;i++){
			ans.m[i]*=-1;
		}
	}

	return ans;
}


istream& operator>>(istream& in, BigInt& a){
	int num=0,i=0,idx=0,j=0;
	for (i=0;i<MAX_N;i++) a.m[i]=0;

	string s;
	in>>s;

	if (s[0]=='-'){
		a.sign=-1;
		a.l=s.length();
		for (i=a.l-1;i>0;){
			num=0;
			for (j=i-4;j<=i;j++){
				if (j>0){
					num*=10;
					num+=(int)s[j]-48;
				}
			}

			a.m[idx]=num;
			idx++;
			i-=5;
		}
	}
	else{
		a.sign=1;
		a.l=s.length();
		for (i=a.l-1;i>=0;){
			num=0;
			for (j=i-4;j<=i;j++){
				if (j>=0){
					num*=10;
					num+=(int)s[j]-48;
				}
			}

			a.m[idx]=num;
			idx++;
			i-=5;
		}
	}

	a.l=idx;
	return in;

}

ostream& operator<<(ostream& out, BigInt a){
	int zero=1,i;

	if (a.sign==-1) out<<'-';

	for (i=a.l-1;i>=0;i--){
		if (zero &&a.m[i]!=0){
			out<<a.m[i];
			zero=0;
		}
		else if (!zero){
			if (a.m[i]<10) out<<"0000"<<a.m[i];
			else if (a.m[i]<100) out<<"000"<<a.m[i];
			else if (a.m[i]<1000) out<<"00"<<a.m[i];
			else if (a.m[i]<10000) out<<"0"<<a.m[i];
			else if (a.m[i]<100000) out<<a.m[i];
		}
	}

	if (zero) out<<"0";

	return out;
}
