/* RECURSION FFT */
/* From e-maxx */
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

void fft(vector<cd> &a, bool invert){
	int n = a.size();
	if(n == 1)
		return;
	vector<cd> odd, even;
	for(int i=0;i<n/2;++i){
		even.pb(a[i<<1]);
		odd.pb(a[i<<1|1]);
	}
	fft(even, invert);
	fft(odd, invert); 
	double ang = 2.0*pi/n;
	if(invert)
		ang *= -1;
	cd w(1.0,0.0), wn(cos(ang), sin(ang));
	for(int i=0;i<n/2;++i){
		a[i] = even[i] +  w*odd[i];
		a[i+n/2] = even[i] - w*odd[i];
		w *= wn;
	}
	if(invert){
		for(cd & tmp: a){
			tmp/=2;
		}
	}
}

vector<int> multiply(const vector<int> &a, const vector<int> &b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int sz = 1;
	while(sz < a.size()+b.size())
		sz <<= 1;
	fa.resize(sz);
	fb.resize(sz);
	fft(fa, false);
	fft(fb, false);
	
	for(int i=0;i<sz;++i)
		fa[i] *= fb[i];
	fft(fa, true);
	
	vector<int> res;
	for(int i=0;i<sz;++i){
		res.pb(round(fa[i].real()));	//easy
	}
	return res;
}

int main(){
	return 0;
}
